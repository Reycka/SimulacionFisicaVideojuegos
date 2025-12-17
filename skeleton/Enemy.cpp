#include "Enemy.h"

Enemy::Enemy(int _health, int _points, double _shootTime)
{
	MAXHEALTH = _health;
	health = _health;
	points = _points;
	MAXSHOOTTIME = _shootTime;
	shootTime = _shootTime;
	sh = new shootManager();
}

Enemy::~Enemy()
{
	delete sh;
}


void Enemy::GotHit(int damage)
{
	health -= damage;
}


void Enemy::shoot(Proyectil* p)
{
	if (shootTime >= MAXSHOOTTIME) {
		shootTime = 0.0;
		sh->addProyectil(p);
	}
	else {
		p->DeRegItem();
	}
}

void Enemy::proyectilUpdate(double t,Proyectil* p)
{
	sh->integrate(t);
	if (shootTime > MAXSHOOTTIME) {
		shootTime = MAXSHOOTTIME;
	}
	else {
		shootTime += t;
	}
	shoot(p);
}
