#pragma once
#include <vector>
#include "Proyectil.h"
#include "Entity.h"
class shootManager : Entity
{
private:
	std::vector<std::pair<Proyectil*,bool>> proyectiles;
	Proyectil* modelo;
public:
	shootManager(Proyectil* _model);
	~shootManager();
	void addProyectil();
	void removeProyectil();
	virtual void addForceGenerator(ForceGenerator* gen) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
	virtual void integrate(double t) override;
};

