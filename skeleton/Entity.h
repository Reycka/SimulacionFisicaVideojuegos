#pragma once
#include "Vector3D.h"
#include "RenderUtils.hpp"
#include <vector>
#include "ForceGenerator.h"
class Entity
{
private:
	RenderItem* renderItem;
	physx::PxTransform* transform;
	physx::PxShape* shape;
	std::vector<ForceGenerator*> generators;
protected:

	Vector3 lastPos;
	bool firstComprobation;
	Vector3 vSim;
	Vector3 vReal;
	Vector3 force;
	Vector3 g;
	double masaSim;
	double masaReal;
	double tVida;
	double damp;


public:
	Entity();
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color);
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, Vector3 _g = { 0.0,-9.8,0.0 }, double _damp = 0.999, double _masaReal = 1, Vector3 _vReal = { 0.0,1.0,0.0 });
	virtual void RegItem();
	virtual void DeRegItem();
	virtual ~Entity();
	void addForceGenerator(ForceGenerator* gen);
	void removeForceGenerator(ForceGenerator* gen);
	void addForces();
	RenderItem* getRenderItem() const;
	physx::PxTransform* getT() const;
	physx::PxShape* getShape() const;
	Vector3 getV()const;
	Vector3 getForce()const;
	Vector3 getG() const;
	double getMasa() const;
	double getTvida() const;
	double getDamp() const;
	virtual void integrate(double t) {};

};

