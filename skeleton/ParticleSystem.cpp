#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(Vector3 pos, physx::PxShape* shape, Vector4 color,Vector3 v, Vector3 a, double _tVida, double damp = 0.999) : Entity(pos,shape,{0.0,0.0,0.0,0.0})
{
	modelo = new Particle(pos,shape,color,v,a,_tVida,damp);
}

ParticleSystem::~ParticleSystem()
{
	for (auto part : particles) {
		part->DeRegItem(); //Si se llama a la destructora de Entity incluyendo esto entonces no hace falta
	}
	for (auto gen : generators) {
		delete gen;
	}
}

void ParticleSystem::addGenerator(ParticleGen* gen)
{
	generators.push_back(gen);
	generators.back()->setModel(modelo);
}

void ParticleSystem::integrate(double t)
{
	for (auto part : particles) {
		part->integrate(t); 
	}

	for (auto gen : generators) {

		gen->removeParticles(); //Elimina las particulas viejas 
		gen->addParticles(particles); //Añade las partículas nuevas

	}
}

