#include "ParticleSystem.h"
#include "Particle.h"

ParticleSystem::ParticleSystem(Vector3 pos, physx::PxShape* shape, Vector4 color,Vector3 v, Vector3 a, double _tVida, double damp) : Entity(pos,shape,{0.0,0.0,0.0,0.0})
{
	modelo = new Particle(pos,shape,color,v,a,_tVida,damp);
	modelo->DeRegItem();
}

ParticleSystem::~ParticleSystem()
{
	for (auto gen : generators) {
		delete gen;
	}
	generators.clear();
}

void ParticleSystem::addGenerator(ParticleGen* gen)
{
	generators.push_back(gen);
	generators.back()->setModel(modelo);
}

void ParticleSystem::integrate(double t)
{

	for (auto& gen : generators) {

		gen->addParticles(); //Añade las partículas nuevas
		gen->integrate(t);
		gen->removeParticles(); //Elimina las particulas viejas 

	}
}


