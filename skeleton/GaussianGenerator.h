#pragma once
#include "ParticleGen.h"

class GaussianGenerator : public ParticleGen
{


private:
	std::normal_distribution<double> nd;
public:
	GaussianGenerator(float rad,Vector3 pos, physx::PxShape* shape,Vector4 color, Vector3 v, Vector3 a, double _tVida, Vector3 g = { 0.0,-9.8,0.0 },int l = 10, double timeToSpwan = 5, double damp = 0.999);
	virtual ~GaussianGenerator();
	virtual Particle* GeneraAleatoria() override;
	virtual void RegParticles() override;
	virtual void DeRegParticles() override;
	virtual void addParticles() override;
	virtual void removeParticles() override;
	virtual void integrate(double t) override;
	virtual void setVariation(int RGBAttribute, bool show) override;
};

