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
	void addGenerator(ParticleGen* gen);
	virtual void integrate(double t) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
};

