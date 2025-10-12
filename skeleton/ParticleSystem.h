#pragma once
#include <list>
#include "ParticleGen.h"
class Particle;
class ParticleSystem : public Entity
{

private:

	Particle* modelo;
	std::list<Particle*>particles;
	std::list<ParticleGen*>generators;

public:

	ParticleSystem(Vector3 pos,physx::PxShape* shape, Vector4 color, Vector3 v, Vector3 a, double _tVida, double damp = 0.999);
	~ParticleSystem();
	void addGenerator(ParticleGen* gen);
	virtual void integrate(double t) override;

};

