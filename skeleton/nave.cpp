#include "nave.h"

nave::nave(Vector3 _finalPos, Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, double _damp,int health,int points,double timeToSpawn) : Entity(pos,_shape,color,_v,_masa,_tVida,_damp) ,Enemy(health,points,timeToSpawn)
{
	finalPos = _finalPos;
	partShipSystem = new ParticleSystem();
	Vector4 smokeColor = { 0.5,0.5,0.5,0.7 };
	Vector4 fireColor = { 1.0f,1.0f,0.0f,1.0f };
	smokeGenerator = new GaussianGenerator(5,getT()->p - Vector3({-2.0,0.0,-2.0}), _shape, smokeColor, {0.0,1.0,0.0}, 0.25, 3, 0.5, 0.999, 2.0);
	fireGenerator = new GaussianGenerator(5,getT()->p - Vector3({ -2.0,0.0,-2.0 }), _shape, fireColor, {0.0,1.0,0.0}, 0.25, 3,0.5,0.999,5.0);
	fireGenerator->setVariation(0, false);
	partShipSystem->addGenerator(smokeGenerator);
	partShipSystem->addGenerator(fireGenerator);
	partShipSystem->setActiveParticleGenerator(smokeGenerator,false);
	
}

nave::~nave()
{
}

void nave::integrate(double t)
{
	if (!smokeGenerator->getIsActive() && actState == GOLPEADO) {
		partShipSystem->setActiveParticleGenerator(smokeGenerator, true);
	}
	partShipSystem->integrate(t);
	tVida -= t;
	proyectilUpdate(t);
	force = Vector3({ 0.0,0.0,0.0 });
	//AddNewForces
	addForces(t);
	//Movimiento
	if (getT()->p.x > finalPos.x) {
		vSim = (vSim + ((force * pow(masaSim, -1)) * t));
		vSim = vSim * pow(damp, t);
		getT()->p = getT()->p + (vSim * t);
	}
}

void nave::RegItem()
{
	Entity::RegItem();
	partShipSystem->RegItem();
}

void nave::DeRegItem()
{
	Entity::DeRegItem();
	partShipSystem->DeRegItem();
}
