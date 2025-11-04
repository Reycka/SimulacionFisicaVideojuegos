#pragma once
#include "Proyectil.h"
#include <list>
#include "Characther.h"
class Enemy : public Characther
{
enum state {
	SPAWN,
	FULL_VIDA,
	GOLPEADO,
	RETIRANDOSE,
	MUERTO
};
protected:
	Proyectil* modelo;
	state actState = SPAWN;
	int points = 0;
	double lifeTime = 0.0;
public:
	Enemy(int _health,int _points,double _shootTime, double _lifeTime);
	virtual ~Enemy();
	void RegEntities();
	void DeRegEntitities();
	virtual void GotHit(int damage) override;
	virtual void removeProyectiles() override;
	virtual void shoot() override;
	virtual void proyectilUpdate(double t) override;
};

