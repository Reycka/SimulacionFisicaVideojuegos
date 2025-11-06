#pragma once
#include <vector>
#include "Proyectil.h"
#include "Entity.h"
class shootManager : Entity
{
private:
	std::vector<std::pair<Proyectil*,bool>> proyectiles;
public:
	shootManager();
	~shootManager();
	void addProyectil(Proyectil* p);
	void removeProyectil();
	virtual void addForceGenerator(ForceGenerator* gen) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
	virtual void integrate(double t) override;
};

