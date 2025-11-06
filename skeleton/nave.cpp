#include "nave.h"
using namespace physx;
nave::nave(Vector3 _finalPos, Vector3 pos, physx::PxShape* _shape, physx::PxMaterial* mat, const Vector4& color, Vector3 _v, double _masa, double _tVida, double _damp, int health, int points, double timeToSpawn,Proyectil* p) : Entity(pos, _shape, color, _v, _masa, _tVida, _damp), Enemy(health, points, timeToSpawn,p)
{
	pr = p;
	finalPos = _finalPos;
	partShipSystem = new ParticleSystem();
	Vector4 smokeColor = { 0.5,0.5,0.5,0.7 };
	Vector4 fireColor = { 1.0f,1.0f,0.0f,1.0f };
	smokeGenerator = new GaussianGenerator(5, getT()->p + Vector3({ -10.0,-10.0,-10.0 }), mat, 1, smokeColor, { 1.0,1.0,1.0 }, 8, 6, 0.1, 0.999, 2.0);
	fireGenerator = new UniformGenerator(5, getT()->p + Vector3({ -10.0,-10.0,-10.0 }), mat, 1, fireColor, { 0.0,10.0,0.0 }, 4, 3, 0.1, 0.999, 5.0);
	fireGenerator->setLimitPos({30.0, 350.0, 30.0});
	smokeGenerator->setLimitPos({ 30.0, 350.0, 30.0 });
	fireGenerator->setVariation(0, false);
	partShipSystem->addGenerator(smokeGenerator);
	partShipSystem->addGenerator(fireGenerator);
	partShipSystem->setActiveParticleGenerator(smokeGenerator,false);
	
}

nave::~nave()
{
}

void nave::addForceGenerator(ForceGenerator* gen)
{
	Entity::addForceGenerator(gen);
	partShipSystem->addForceGenerator(gen);
	sh->addForceGenerator(gen);
}

void nave::integrate(double t)
{
	if (!smokeGenerator->getIsActive() && actState == GOLPEADO) {
		partShipSystem->setActiveParticleGenerator(smokeGenerator, true);
	}
	tVida -= t;
	force = Vector3({ 0.0,0.0,0.0 });
	addForces(t);

	vSim = (vSim + ((force * pow(masaSim, -1)) * t));
	vSim = vSim * pow(damp, t);
	getT()->p = getT()->p + (vSim * t);
	partShipSystem->setPosition(getT()->p);
	partShipSystem->integrate(t);
	proyectilUpdate(t);
	pr->getT()->p = pr->getT()->p + (vSim * t);	
}

void nave::RegItem()
{
	Entity::RegItem();
	partShipSystem->RegItem();
	sh->RegItem();
}

void nave::DeRegItem()
{
	Entity::DeRegItem();
	partShipSystem->DeRegItem();
	sh->DeRegItem();
}
