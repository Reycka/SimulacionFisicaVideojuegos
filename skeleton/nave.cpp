#include "nave.h"
#include <iostream>
using namespace physx;
nave::nave(physx::PxScene* context, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx,
	const physx::PxGeometry& geom, Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, double _damp, 
	int health, int points, double timeToSpawn, ExplosionGenerator* _exp, physx::PxTransform cameraTransform) :
	DynamicSolidRigid(context,coefStatic,dynamStatic,restitution,gPhysx,geom,pos,color,_v,_masa,vol,_tVida,_damp), Enemy(health,points,timeToSpawn)
{
	type = Nave;
	//Variables globales inicializadas
	initialPositon = pos;
	finalPos = pos + Vector3(300.0, 0.0, 0.0);
	shootPoint = cameraTransform.p;

	//Sistemas de partículas internos
	partShipSystem = new ParticleSystem();
	entities.push_back(partShipSystem);
	createFire();
	createSmoke();

	//Asignar el puntero de explosión de la escena a las entidades
	exp = _exp;
	createForces();
	getObj()->setActorFlag(physx::PxActorFlag::eDISABLE_GRAVITY, true);
}

nave::~nave()
{
	delete g;
}

void nave::addForceGenerator(ForceGenerator* gen)
{
	for (auto ent : entities) {
		ent->addForceGenerator(gen);
	}
}

void nave::integrate(double t)
{

	AIFunction();

	//Colocación de las partículas para que sigan a la nave e integrate del generador
	partShipSystem->setPosition(getT()->p);
	partShipSystem->integrate(t);

	//Proyectil propio de la nave
//	PxMaterial* proyectilMateril = getPhy()->createMaterial(0.4f, 0.3f, 0.6f);
//	Proyectil* p = new Proyectil(getT()->p, CreateShape(PxSphereGeometry(1), proyectilMateril), { 1.0f,1.0f,0.0f,1.0f }, shootPoint, 10, 0.02, 60, 60, Vector3(30.0, 15.0, 0.0), 0.999);
//	proyectilUpdate(t, p);
	DynamicSolidRigid::integrate(t);
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
			//TODO Probar si queda bien bajar la velocidad aqui
		}

		else if (actState == MUERTO) {
			//Activar la explosión y despawnear la nave
			//exp->setIsActive(true);
			tVida = 0;
			smokeGenerator->setIsActive(false);
			fireGenerator->setIsActive(false);
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
}

void nave::DeRegItem()
{
	for (auto ent : entities) {
		ent->DeRegItem();
	}
	DynamicSolidRigid::DeRegItem();
}

void nave::createSmoke()
{
	PxMaterial* smokeMaterial = getPhy()->createMaterial(0.5f, 0.5f, 0.6f);
	Vector4 smokeColor = { 0.5,0.5,0.5,0.7 };
	smokeGenerator = new GaussianGenerator(5, getT()->p , smokeMaterial, 1, smokeColor, { 1.0,1.0,1.0 }, 8, 6, 0.1, 0.999, 2.0);
	smokeGenerator->setIsActive(false);
	partShipSystem->addGenerator(smokeGenerator);
}

void nave::createFire()
{
	PxMaterial* fireMaterial = getPhy()->createMaterial(0.5f, 0.5f, 0.6f);
	Vector4 fireColor = { 1.0f,1.0f,0.0f,1.0f };
	fireGenerator = new UniformGenerator(5, getT()->p , fireMaterial, 1, fireColor, { 0.0,10.0,0.0 }, 4, 3, 0.1, 0.999, 5.0);
	partShipSystem->addGenerator(fireGenerator);
}

void nave::createForces()
{
	g = new GravityGenerator(Vector3(0.0, -10.0, 0.0));
	partShipSystem->addForceGenerator(exp);
	partShipSystem->addForceGenerator(g);
}


