#pragma once
#include <list>
#include "SolidRigidGenerator.h"
class RigidBodySystem : public Entity
{
private:
	std::list<SolidRigidGenerator*>generators;
	physx::PxScene* context;
public:
	RigidBodySystem(physx::PxScene* context);
	~RigidBodySystem();
	void addGenerator(SolidRigidGenerator* gen);
	void setActiveParticleGenerator(SolidRigidGenerator* gen, bool active);
	virtual void addForceGenerator(ForceGenerator* gen) override;
	void setPosition(Vector3 pos);
	virtual void integrate(double t) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
};

