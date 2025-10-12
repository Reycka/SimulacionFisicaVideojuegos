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
	Vector3 vSim;
	Vector3 vReal;
	Vector3 a;
	Vector3 g;
	double masaSim;
	double masaReal;
	double tVida;
	double damp;
	double lastTime = 0;

public:
	Entity();
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color);
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _damp = 0.999, double _masaReal = 1, Vector3 _vReal = { 0.0,1.0,0.0 }, Vector3 _g = {0.0,-9.8,0.0});
	void RegItem();
	void DeRegItem();
	virtual ~Entity();
	RenderItem* getRenderItem() const;
	physx::PxTransform* getT() const;
	physx::PxShape* getShape() const;
	Vector3 getV()const;
	Vector3 getA()const;
	Vector3 getG() const;
	double getMasa() const;
	double getTvida() const;
	double getDamp() const;
	virtual void integrate(double t) {};

};

