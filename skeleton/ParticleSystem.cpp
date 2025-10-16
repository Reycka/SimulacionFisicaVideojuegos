#include "ParticleSystem.h"
#include "Particle.h"

ParticleSystem::ParticleSystem() : Entity()
{
	Entity::DeRegItem(); //Elimino la representacion de la entidad de la escena
}

ParticleSystem::~ParticleSystem()
{
	Entity::RegItem(); //Activo la representacion para posteirormente eliminarla bien
	for (auto gen : generators) {
		delete gen;
	}
	generators.clear();
}

void ParticleSystem::addGenerator(ParticleGen* gen)
{
	generators.push_back(gen);
}

void ParticleSystem::integrate(double t)
{

	for (auto& gen : generators) {
		gen->removeParticles(); //Elimina las particulas viejas
		gen->integrate(t);
		gen->addParticles(); //A�ade las part�culas nuevas

	}
}

void ParticleSystem::RegItem()
{
	for (auto& gen : generators) {
		gen->RegParticles();
	}
}

void ParticleSystem::DeRegItem()
{
	for (auto& gen : generators) {
		gen->DeRegParticles();
	}
}


