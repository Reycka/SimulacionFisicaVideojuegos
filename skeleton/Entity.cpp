#include "Entity.h"
using namespace physx;

Entity::Entity()
{
	Vector3D pos = { 0,0,0 };
	PxShape* _shape = CreateShape(PxSphereGeometry(1), NULL);
	shape = _shape;
	transform = new PxTransform(pos.changeClass());
	Vector4 color = { 1.0,1.0,1.0,1.0 };
	renderItem = new RenderItem(shape, transform, color);
	v = Vector3D({ 0.0,0.0,0.0 });
	a = Vector3D({ 0.0,0.0,0.0 });
	masa = 0;
	tVida = 0;
	damp = 0;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
}

Entity::Entity(Vector3D pos, PxShape* _shape, const Vector4& color)
{
	shape = _shape;
	transform = new PxTransform(pos.changeClass());
	renderItem = new RenderItem(shape, transform, color);
	v = Vector3D({0.0,0.0,0.0});
	a = Vector3D({ 0.0,0.0,0.0 });
	masa = 0;
	tVida = 0;
	damp = 0;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
}

Entity::Entity(Vector3D pos, physx::PxShape* _shape, const Vector4& color, Vector3D _v, Vector3D _a, double _masa, double _tVida, double _damp)
{
	shape = _shape;
	transform = new PxTransform(pos.changeClass());
	renderItem = new RenderItem(shape, transform, color);
	v = _v;
	a = _a;
	masa = _masa;
	tVida = _tVida;
	damp = _damp;
	firstComprobation = true;
	lastPos = Vector3({ 0.0,0.0,0.0 });
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
	DeregisterRenderItem(renderItem);
	shape->release();
	delete transform;
	delete renderItem;

}


PxTransform* Entity::getT() const
{
	return transform;
}
