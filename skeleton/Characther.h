#pragma once
#include <list>
#include "shootManager.h"
class Characther
{
protected:
	shootManager* sh;
	int health = 0;
	double MAXSHOOTTIME = 0.0;
	double shootTime = 0.0;
public:
	virtual void GotHit(int damage) = 0;
	virtual void shoot(Proyectil* p) = 0;
	virtual void proyectilUpdate(double t, Proyectil* p) {};
};

