#include "Enemy.h"

Enemy::Enemy(int _health, int _points, double _shootTime, Proyectil* p)
{
	health = _health;
	points = _points;
	MAXSHOOTTIME = _shootTime;
	shootTime = _shootTime;
	sh = new shootManager(p);
}

Enemy::~Enemy()
{
	delete sh;
}


void Enemy::GotHit(int damage)
{
	health -= damage;
	if (health <= 0) {
		actState = MUERTO;
	}
	else {
		actState = GOLPEADO;
	}
}


void Enemy::shoot()
{
	if (shootTime >= MAXSHOOTTIME) {
		shootTime = 0.0;
		sh->addProyectil();
	}
}

void Enemy::proyectilUpdate(double t)
{
	sh->integrate(t);
	if (shootTime > MAXSHOOTTIME) {
		shootTime = MAXSHOOTTIME;
	}
	else {
		shootTime += t;
	}
	shoot();
}
