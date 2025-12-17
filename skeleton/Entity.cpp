#include "Entity.h"
#include "ForceGenerator.h"
using namespace physx;

Entity::Entity()
{
	Vector3 pos = { 0,0,0 };
	PxShape* _shape = CreateShape(PxSphereGeometry(1), NULL);
	shape = _shape;
	transform = new PxTransform(pos);
	Vector4 color = { 0.0,0.0,0.0,0.0 };
	renderItem = new RenderItem(shape, transform, color);
	vSim = Vector3({ 0.0,0.0,0.0 });
	masaSim = 0;
	tVida = 0;
	damp = 0;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });

}

Entity::Entity(Vector3 pos, PxShape* _shape, const Vector4& color)
{
	shape = _shape;
	transform = new PxTransform(pos);
	renderItem = new RenderItem(shape, transform, color);
	vSim = Vector3({0.0,0.0,0.0});
	masaSim = 3;
	tVida = 0;
	damp = 0;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
}

Entity::Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa,double _volSim ,double _tVida,double _damp, double _masaReal, Vector3 _vRea, double _volReal)
{
	shape = _shape;
	transform = new PxTransform(pos);
	renderItem = new RenderItem(shape, transform, color);
	vSim = _v;
	masaSim = _masa;
	volSim = _volSim;
	tVida = _tVida;
	damp = _damp;
	masaReal = _masaReal;
	vReal = _vRea;
	volReal = _volReal;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
}

Entity::Entity(Vector3 pos, Vector3 _v, double _masa, double vol, double _tVida, double _damp, double _masaReal, Vector3 _vReal, double _volReal)
{
	transform = new PxTransform(pos);
	vSim = _v;
	masaSim = _masa;
	volSim = vol;
	tVida = _tVida;
	damp = _damp;
	masaReal = _masaReal;
	vReal = _vReal;
	volReal = _volReal;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
}

void Entity::RegItem()
{
	if (isActive) {
		RegisterRenderItem(renderItem);
	}
}

void Entity::DeRegItem()
{
	if (isActive) {
		DeregisterRenderItem(renderItem);
	}
}

Entity::~Entity()
{
	shape->release();
	delete transform;
	delete renderItem;
	DeRegItem();

}

void Entity::addForceGenerator(ForceGenerator* gen)
{
	ForceGen.push_back(gen);
}

void Entity::DesActiveForceGenerator(ForceGenerator* gen)
{
	for (auto g : ForceGen) {
		 g->setIsActive(false);
	}
}

void Entity::reActiveForceGenerator(ForceGenerator* gen)
{
	for (auto g : ForceGen) {
		g->setIsActive(true);
	}
}

void Entity::addForces(double t)
{
	for (auto g : ForceGen) {
		 Vector3 forceReturned;
		 forceReturned = g->addForce(this,t);
		 force.x += forceReturned.x;
		 force.y += forceReturned.y;
		 force.z += forceReturned.z;
	}
}

RenderItem* Entity::getRenderItem() const
{
	return renderItem;
}



//GETTERS
PxTransform* Entity::getT() 
{
	return transform;
}

physx::PxShape* Entity::getShape() const
{
	return shape;
}

Vector3 Entity::getV() const
{
	return vSim;
}

Vector3 Entity::getVReal() const
{
	return vReal;
}

Vector3 Entity::getForce() const
{
	return force;
}

double Entity::getMasa() const
{
	return masaSim;
}

double Entity::getVol() const
{
	return volSim;
}

double Entity::getMasaReal() const
{
	return masaReal;
}

double Entity::getTvida() const
{
	return tVida;
}

double Entity::getDamp() const
{
	return damp;
}

EntityType Entity::getEntType() const
{
	return type;
}

void Entity::setShape(physx::PxShape* sh,const Vector4& color)
{
	shape = sh;
	renderItem = new RenderItem(shape, transform, color);
}

void Entity::setRenderItem(physx::PxRigidActor* act)
{
	Vector4 color = renderItem->color;
	renderItem->release();
	renderItem = new RenderItem(shape, act, color);
}

void Entity::setMasa(double newMasa)
{
	masaSim = newMasa;
}

void Entity::setVolume(double newVol)
{
	volSim = newVol;
}

