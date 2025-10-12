#pragma once
#include <list>
#include "Entity.h"
#include "ParticleGen.h"
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

