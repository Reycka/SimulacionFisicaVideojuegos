#pragma once
#include "Characther.h"
#include "Entity.h"
class Player : public Characther, public Entity
{
public:
	Player(int health);
	~Player();
	virtual void RegItem() override;
	virtual void DeRegItem() override;
	virtual void GotHit(int damage) override;
	virtual void addForceGenerator(ForceGenerator* gen) override;
	virtual void shoot(Proyectil* p) override;
	virtual void integrate(double t) override;

};

