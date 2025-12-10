#pragma once
#include <vector>
#include <list>
#include "RenderUtils.hpp"
class ForceGenerator;
class Entity
{
private:
	int maxIndex;  
	RenderItem* renderItem;
	physx::PxTransform* transform;
	physx::PxShape* shape;

protected:

	Vector3 lastPos;
	bool firstComprobation;
	Vector3 vSim;
	Vector3 vReal;
	Vector3 force;
	double volSim;
	double volReal;
	double masaSim;
	double masaReal;
	double tVida;
	double damp;
	std::list<ForceGenerator*> ForceGen;


public:
	Entity();
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color);
	Entity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa,double vol,double _tVida, double _damp = 0.999, double _masaReal = 1, Vector3 _vReal = { 0.0,1.0,0.0 }, double _volReal = 1);
	Entity(Vector3 pos, Vector3 _v, double _masa, double vol, double _tVida, double _damp = 0.999, double _masaReal = 1, Vector3 _vReal = { 0.0,1.0,0.0 }, double _volReal = 1);

	virtual void RegItem();
	virtual void DeRegItem();
	virtual ~Entity();
	virtual void addForceGenerator(ForceGenerator* gen);
	virtual void DesActiveForceGenerator(ForceGenerator* gen);
	virtual void reActiveForceGenerator(ForceGenerator* gen);
	void addForces(double t);
	RenderItem* getRenderItem() const;
	physx::PxTransform* getT() ;
	physx::PxShape* getShape() const;
	Vector3 getV()const;
	Vector3 getVReal()const;
	Vector3 getForce()const;
	double getMasa() const;
	double getVol() const;
	double getMasaReal() const;
	double getTvida() const;
	double getDamp() const;
	void setShape(physx::PxShape* sh,const Vector4& color);
	void setRenderItem(physx::PxRigidActor* act);
	void setMasa(double newMasa);
	void setVolume(double newVol);
	virtual void integrate(double t) {};

};

