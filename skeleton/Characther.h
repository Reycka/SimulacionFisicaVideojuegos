#pragma once
#include <list>
#include "Proyectil.h"
class Characther
{
protected:
	std::list<std::pair<Proyectil*,bool>> disparos;
	Proyectil* modelo;
	int health = 0;
	double MAXSHOOTTIME = 0.0;
	double shootTime = 0.0;
public:
	virtual void GotHit(int damage) = 0;
	virtual void shoot() = 0;
	virtual void removeProyectiles() = 0;
	virtual void proyectilUpdate(double t) = 0;
};

