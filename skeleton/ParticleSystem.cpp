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

void ParticleSystem::addForceGenerator(ForceGenerator* gen)
{
	for (auto g : generators) {
		g->addForceGen(gen);
	}
}

void ParticleSystem::DesActiveForceGenerator(ForceGenerator* gen)
{
	for (auto g : generators) {
		g->DesactiveForceGen(gen);
	}
}

void ParticleSystem::reActiveForceGenerator(ForceGenerator* gen)
{
	for (auto g : generators) {
		g->activeForceGen(gen);
	}
}



void ParticleSystem::integrate(double t)
{

	for (auto& gen : generators) {
		gen->removeParticles(); //Elimina las particulas viejas
		gen->integrate(t);
		gen->addParticles(); //Añade las partículas nuevas

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


