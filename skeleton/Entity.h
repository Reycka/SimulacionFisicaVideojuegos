#pragma once
#include "Vector3D.h"
#include "RenderUtils.hpp"
#include <list>

class Entity
{
private:
	RenderItem* renderItem;
	physx::PxTransform* transform;
	physx::PxShape* shape;

public:
	Entity();
	Entity(Vector3D pos, physx::PxShape* _shape, const Vector4& color);
	virtual ~Entity();
	void update(double t);
	physx::PxTransform* getT() const;
	virtual void integrate(double t) {};
};

