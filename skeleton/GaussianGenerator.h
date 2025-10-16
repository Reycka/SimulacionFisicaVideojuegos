#pragma once
#include "ParticleGen.h"

class GaussianGenerator : public ParticleGen
{


private:
	std::normal_distribution<double> nd;
public:
	GaussianGenerator(Vector3 pos, physx::PxShape* shape,Vector4 color, Vector3 v, Vector3 a, double _tVida, double damp = 0.999,int l = 10);
	virtual ~GaussianGenerator();
	virtual Particle* GeneraAleatoria() override;
	virtual void RegParticles() override;
	virtual void DeRegParticles() override;
	virtual void addParticles() override;
	virtual void removeParticles() override;
	virtual void integrate(double t) override;
};

