#include "shootManager.h"

shootManager::shootManager(Proyectil* _model) : Entity()
{
	modelo = _model;
	Entity::DeRegItem();
	modelo->DeRegItem();
}

shootManager::~shootManager()
{
	Entity::RegItem(); //Activo la representacion para posteirormente eliminarla bien
	for (auto p : proyectiles) {
		if (p.second) {
			delete p.first;
		}
	}
	proyectiles.clear();
}

void shootManager::addProyectil()
{
	Proyectil* p = new Proyectil(modelo->getT()->p,modelo->getShape(), modelo->getRenderItem()->color, modelo->getV(), modelo->getMasa(),modelo->getTvida(),modelo->getMasaReal(),modelo->getVReal());
	proyectiles.push_back({ p, true });
}

void shootManager::removeProyectil()
{
	for (auto& p : proyectiles) {
		if (p.second) {
			p.first->DeRegItem();
			p.second = false;
		}
	}
}

void shootManager::addForceGenerator(ForceGenerator* gen)
{
	for (auto& p : proyectiles) {
		if (p.second) {
			p.first->addForceGenerator(gen);
		}
	}
}

void shootManager::RegItem()
{
	for (auto& p : proyectiles) {
		if (p.second) {
			p.first->RegItem();
		}
	}
}

void shootManager::DeRegItem()
{
	for (auto& p : proyectiles) {
		if (p.second) {
			p.first->DeRegItem();
		}
	}
}

void shootManager::integrate(double t)
{
	for (auto& p : proyectiles) {

		if (p.second && p.first->getTvida() <= 0 || p.second && abs(p.first->getT()->p.x) > 60) {
			removeProyectil();
		}
		if (p.second) {
			p.first->integrate(t);
		}
	}
}
