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
	void RegEntities();
	void DeRegEntitities();
	virtual void GotHit(int damage) override;
	virtual void removeProyectiles() override;
	virtual void shoot() override;
	virtual void proyectilUpdate(double t) override;
};

