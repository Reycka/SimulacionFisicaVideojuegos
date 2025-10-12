#pragma once
#include "ParticleGen.h"

class GaussianGenerator : public ParticleGen
{


private:
	std::normal_distribution<double> nd;
public:
	GaussianGenerator();
	~GaussianGenerator();
	virtual void addParticles(std::list<Particle*> p) override;
	virtual void removeParticles() override;
};

