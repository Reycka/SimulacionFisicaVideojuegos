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

	ParticleSystem(Vector3 pos,physx::PxShape* shape, Vector4 color = {0.0,0.0,0.0,0.0});
	~ParticleSystem();
	void addGenerator(ParticleGen* gen);
	virtual void integrate(double t) override;

};

