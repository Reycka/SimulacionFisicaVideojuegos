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
}

Entity::Entity(Vector3D pos, PxShape* _shape, const Vector4& color)
{
	shape = _shape;
	transform = new PxTransform(pos.changeClass());
	renderItem = new RenderItem(shape, transform, color);
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
