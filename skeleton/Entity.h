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

protected:

	Vector3 lastPos;
	bool firstComprobation;

	Vector3 v;
	Vector3 a;
	double masa;
	double tVida;
	double damp;

public:
	Entity();
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color);
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _damp = 0.999);
	void RegItem();
	void DeRegItem();
	virtual ~Entity();
	physx::PxTransform* getT() const;
	virtual void integrate(double t) {};
};

