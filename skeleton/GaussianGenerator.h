#pragma once
#include "ParticleGen.h"

class GaussianGenerator : public ParticleGen
{
friend Entity; //Le permite acceder a los atributos protected de Entity (Vel, aceleracion...)

private:
	std::normal_distribution<double> nd;
public:
	GaussianGenerator();
	~GaussianGenerator();
	virtual void addParticles() override;
	virtual void removeParticles() override;
};

