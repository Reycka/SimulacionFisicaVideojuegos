#pragma once
#include "ParticleGen.h"

class GaussianGenerator : public ParticleGen
{


private:
	std::normal_distribution<double> nd;
public:
	GaussianGenerator();
	virtual ~GaussianGenerator();
	virtual void addParticles() override;
	virtual void removeParticles() override;
	virtual void integrate(double t) override;
	virtual void setModel(Particle* model) override;
};

