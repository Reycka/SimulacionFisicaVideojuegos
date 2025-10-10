#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(Vector3 pos, physx::PxShape* shape, Vector4 color) : Entity(pos,shape,color)
{
}

ParticleSystem::~ParticleSystem()
{
	for (auto part : particles) {
		part->DeRegItem(); //Si se llama a la destructora de Entuty incluyendo esto entonces no hace falta
	}
	for (auto gen : generators) {
		delete gen;
	}
}

void ParticleSystem::addGenerator(ParticleGen* gen)
{
	generators.push_back(gen);
}

void ParticleSystem::integrate(double t)
{
	for (auto part : particles) {
		//part->integrate(t); En caso de no moverse la partícula
	}

	for (auto gen : generators) {

		gen->removeParticles(); //Elimina las particulas viejas 
		gen->addParticles(); //Añade las partículas nuevas

	}
}

