#pragma once
#include "ParticleGen.h"

class GaussianGenerator : public ParticleGen
{


private:
	std::normal_distribution<double> nd;
public:
	GaussianGenerator(float rad,Vector3 pos, physx::PxShape* shape,Vector4 color, Vector3 v, double _tVida,int l = 10, double timeToSpwan = 5, double damp = 0.999, double masa = 5.0);
	GaussianGenerator(float rad, Vector3 pos, physx::PxMaterial* mat,int tam ,Vector4 color, Vector3 v, double _tVida, int l = 10, double timeToSpwan = 5, double damp = 0.999, double masa = 5.0);
	virtual ~GaussianGenerator();
	void setLimitPos(Vector3 pos);
	virtual bool getIsActive() override;
	virtual void setIsActive(bool active) override;
	virtual void addForceGen(ForceGenerator* g) override;
	virtual Particle* GeneraAleatoria() override;
	virtual void RegParticles() override;
	virtual void DeRegParticles() override;
	virtual void addParticles() override;
	virtual void removeParticles() override;
	virtual void integrate(double t) override;
	virtual void setVariation(int RGBAttribute, bool show) override;
};

