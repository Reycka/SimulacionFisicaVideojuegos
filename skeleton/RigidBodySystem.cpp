#include "RigidBodySystem.h"
RigidBodySystem::RigidBodySystem(physx::PxScene* _context) : Entity()
{
	context = _context;
	Entity::DeRegItem();
}

RigidBodySystem::~RigidBodySystem()
{
	Entity::RegItem(); //Activo la representacion para posteirormente eliminarla bien
	for (auto gen : generators) {
		delete gen;
	}
	generators.clear();
}

void RigidBodySystem::addGenerator(SolidRigidGenerator* gen)
{
	generators.push_back(gen);
}

void RigidBodySystem::setActiveParticleGenerator(SolidRigidGenerator* gen, bool active)
{
	for (auto g : generators) {
		if (g == gen) {
			g->setIsActive(active);
			break;
		}
	}
}

void RigidBodySystem::addForceGenerator(ForceGenerator* gen)
{
	for (auto g : generators) {
		g->addForceGen(gen);
	}
}

void RigidBodySystem::integrate(double t)
{
	for (auto& gen : generators) {
		if (gen->getIsActive()) {
			gen->removeSolidRigid(context); //Elimina las particulas viejas
			gen->integrate(t);
			gen->addSolidRigid(context); //Añade las partículas nuevas
		}
	}
}

void RigidBodySystem::RegItem()
{
	for (auto& gen : generators) {
		gen->RegSolidRigid();
	}
}

void RigidBodySystem::DeRegItem()
{
	for (auto& gen : generators) {
		gen->DeRegSolidRigid();
	}
}

