#include "Entity.h"
using namespace physx;

Entity::Entity()
{
	Vector3D pos = { 0,0,0 };
	PxShape* _shape = CreateShape(PxSphereGeometry(1), NULL);
	shape = _shape;
	transform = new PxTransform(pos.changeClass());
	Vector4 color = { 0.0,0.0,0.0,0.0 };
	renderItem = new RenderItem(shape, transform, color);
	vSim = Vector3({ 0.0,0.0,0.0 });
	a = Vector3({ 0.0,0.0,0.0 });
	masaSim = 0;
	tVida = 0;
	damp = 0;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
	g = Vector3({ 0.0,0.0,0.0 });

}

Entity::Entity(Vector3 pos, PxShape* _shape, const Vector4& color)
{
	shape = _shape;
	transform = new PxTransform(pos);
	renderItem = new RenderItem(shape, transform, color);
	vSim = Vector3({0.0,0.0,0.0});
	a = Vector3({ 0.0,0.0,0.0 });
	masaSim = 0;
	tVida = 0;
	damp = 0;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
	g = Vector3({ 0.0,0.0,0.0 });
}

Entity::Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _damp, double _masaReal, Vector3 _vReal, Vector3 _g)
{
	shape = _shape;
	transform = new PxTransform(pos);
	renderItem = new RenderItem(shape, transform, color);
	vSim = _v;
	a = _a;
	masaSim = _masa;
	tVida = _tVida;
	damp = _damp;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
	g = _g;
}

void Entity::RegItem()
{
	RegisterRenderItem(renderItem);
}

void Entity::DeRegItem()
{
	DeregisterRenderItem(renderItem);
}

Entity::~Entity()
{
	DeRegItem();
	shape->release();
	delete transform;
	delete renderItem;

}

RenderItem* Entity::getRenderItem() const
{
	return renderItem;
}



//GETTERS
PxTransform* Entity::getT() const
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

Vector3 Entity::getA() const
{
	return a;
}

Vector3 Entity::getG() const
{
	return g;
}

double Entity::getMasa() const
{
	return masaSim;
}

double Entity::getTvida() const
{
	return tVida;
}

double Entity::getDamp() const
{
	return damp;
}

