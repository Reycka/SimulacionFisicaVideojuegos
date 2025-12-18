#include "nave.h"
#include <iostream>
using namespace physx;
nave::nave(physx::PxScene* context, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx,
	const physx::PxGeometry& geom, Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, 
	double _tVida, physx::PxTransform cameraTransform, double _damp,
	int health, int points, double timeToSpawn) :
	DynamicSolidRigid(context,coefStatic,dynamStatic,restitution,gPhysx,geom,pos,color,_v,_masa,vol,_tVida,_damp), Enemy(health,points,timeToSpawn)
{
	type = Nave;
	//Variables globales inicializadas
	initialPositon = pos;
	finalPos = pos + Vector3(300.0, 0.0, 0.0);
	shootPoint = pos - cameraTransform.p;

	//Sistemas de partículas internos
	partShipSystem = new ParticleSystem();
	entities.push_back(partShipSystem);
	createFire();
	createSmoke();

	//Crear fuerzas y desactivar la gravedad
	createForces();
	getObj()->setActorFlag(physx::PxActorFlag::eDISABLE_GRAVITY, true);
}

nave::~nave()
{
	delete g;
	delete wind;
	delete windProyectil;
}

void nave::addForceGenerator(ForceGenerator* gen)
{
	for (auto ent : entities) {
		ent->addForceGenerator(gen);
	}
	DynamicSolidRigid::addForceGenerator(gen);
}

void nave::integrate(double t)
{

	if (tVida > 0) {
		AIFunction();

		//Colocación de las partículas para que sigan a la nave e integrate del generador

		//Proyectil propio de la nave
		PxMaterial* proyectilMateril = getPhy()->createMaterial(0.4f, 0.3f, 0.6f);
		PxReal coef = 0.4;
		Vector3 pos = Vector3(getObj()->getGlobalPose().p.x + 10, getObj()->getGlobalPose().p.y, getObj()->getGlobalPose().p.z + 10);
		Proyectil* p = new Proyectil(getContext(), coef, coef / 2, coef * 2, getPhy(), PxSphereGeometry(1), pos, CreateShape(PxSphereGeometry(1), proyectilMateril), { 0.5f,0.5f,0.5f,1.0f }, shootPoint, 50, 0.1, 10, 30, Vector3(30.0, 15.0, 0.0));
		p->addForceGenerator(windProyectil);
		proyectilUpdate(t, p);
		DynamicSolidRigid::integrate(t);
		partShipSystem->setPosition(getObj()->getGlobalPose().p + Vector3({ -3.0,0.0,-3.0 }));
		partShipSystem->integrate(t);
	}
}

void nave::onCollision(Entity* other)
{
	switch (other->getEntType()) {
	case Nave:
		GotHit(MAXHEALTH);
		break;
	case Bala:
		GotHit(1);
		break;
	}
}

void nave::setGravity(bool value)
{
	getObj()->setActorFlag(physx::PxActorFlag::eDISABLE_GRAVITY, value);
}

void nave::setState()
{
	if (health != MAXHEALTH) {
		if (health <= 0) {
			actState = MUERTO;
		}
		else actState = GOLPEADO;
	}

	if (getT()->p.x > finalPos.x && health > 0) {
		actState = RETIRANDOSE;
	}
}

void nave::AIFunction()
{
	const state oldState = actState; //Guardamos una referencia al estado actual antes del cambio
	setState(); //Cambiamos el estado?

	if (actState != oldState) { //Si hemos cambiado el estado cambiamos el funcionamiento de los sistemas internos

		if (actState == GOLPEADO) {
			smokeGenerator->setIsActive(true);
			getObj()->setActorFlag(physx::PxActorFlag::eDISABLE_GRAVITY, false);
		}

		else if (actState == MUERTO) {
			//Activar la explosión y despawnear la nave
			//exp->setIsActive(true);
			tVida = 0;
			//TODO ganar los puntos que hagan falta
		}

		else if (actState == RETIRANDOSE){
			//Despawnear la nave
			tVida = 0;
			//TODO perder puntos por cada nave que se escape
		}

	} 
	//Si no no hacemos nada pq ya está hecho
}

void nave::RegItem()
{
	for (auto ent : entities) {
		ent->RegItem();
	}
	DynamicSolidRigid::RegItem();
	sh->RegItem();
}

void nave::DeRegItem()
{
	for (auto ent : entities) {
		ent->DeRegItem();
	}
	DynamicSolidRigid::DeRegItem();
	sh->DeRegItem();
}

void nave::createSmoke()
{
	PxMaterial* smokeMaterial = getPhy()->createMaterial(0.5f, 0.5f, 0.6f);
	Vector4 smokeColor = { 0.5,0.5,0.5,0.7 };
	smokeGenerator = new GaussianGenerator(5, getObj()->getGlobalPose().p, smokeMaterial, 1, smokeColor, { 1.0,1.0,1.0 }, 8, 6, 0.1, 0.999, 2.0);
	smokeGenerator->setIsActive(false);
	smokeGenerator->setLimitPos(Vector3(300.0, 300.0, 300.0));
	partShipSystem->addGenerator(smokeGenerator);
}

void nave::createFire()
{
	PxMaterial* fireMaterial = getPhy()->createMaterial(0.5f, 0.5f, 0.6f);
	Vector4 fireColor = { 1.0f,1.0f,0.0f,1.0f };
	fireGenerator = new UniformGenerator(5, getObj()->getGlobalPose().p + Vector3({ -20.0,5.0,-20.0 }), fireMaterial, 1, fireColor, { 0.0,10.0,0.0 }, 4, 6, 0.1, 0.999, 5.0);
	fireGenerator->setLimitPos(Vector3(300.0, 300.0, 300.0));
	fireGenerator->setVariation(0, false);
	partShipSystem->addGenerator(fireGenerator);
}

void nave::createForces()
{
	g = new GravityGenerator(Vector3(0.0, -10.0, 0.0));
	windProyectil = new WindGenerator(getObj()->getGlobalPose().p, 350.0f, Vector3(200.0, 0.0, 200.0), 120);
	wind = new WindGenerator(getObj()->getGlobalPose().p, 350.0f, Vector3(300.0, 0.0, 0.0), 60);
	//partShipSystem->addForceGenerator(exp);
	partShipSystem->addForceGenerator(g);
	DynamicSolidRigid::addForceGenerator(wind);
}


