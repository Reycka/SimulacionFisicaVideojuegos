#pragma once
#include "Characther.h"
class Enemy : public Characther
{

protected:
	enum state {
		SPAWN,
		FULL_VIDA,
		GOLPEADO,
		RETIRANDOSE,
		MUERTO
	};
	state actState = SPAWN;
	int points = 0;
public:
	Enemy(int _health,int _points,double _shootTime);
	virtual ~Enemy();
	virtual void setState() {};
	virtual void AIFunction() {};
	virtual void GotHit(int damage) override;
	virtual void shoot(Proyectil* p) override;
	virtual void proyectilUpdate(double t, Proyectil* p) override;
};

