#pragma once
#include <list>
#include "ParticleGen.h"
class Particle;
class ParticleSystem : public Entity
{

private:

	std::list<ParticleGen*>generators;

public:

	ParticleSystem();
	~ParticleSystem();
	virtual void addForceGenerator(ForceGenerator gen) override;
	virtual void DesActiveForceGenerator(ForceGenerator gen) override;
	virtual void reActiveForceGenerator(ForceGenerator gen) override;
	virtual void integrate(double t) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
};

