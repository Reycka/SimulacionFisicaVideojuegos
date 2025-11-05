#include "Enemy.h"

Enemy::Enemy(int _health, int _points, double _shootTime)
{
	health = _health;
	points = _points;
	MAXSHOOTTIME = _shootTime;
	shootTime = _shootTime;
}

Enemy::~Enemy()
{
	for (auto p : disparos) {
		if (p.second) {
			 p.first->DeRegItem();
		}
	}
}

void Enemy::RegEntities()
{
	for (auto& p : disparos) {
		if (p.second) {
			p.first->RegItem();
		}
	}
}

void Enemy::DeRegEntitities()
{
	for (auto& p : disparos) {
		if (p.second) {
			p.first->DeRegItem();
		}
	}
}

void Enemy::GotHit(int damage)
{
	health -= damage;
	if (health <= 0) {
		actState == MUERTO;
	}
	else {
		actState == GOLPEADO;
	}
}

void Enemy::removeProyectiles()
{
	for (auto p : disparos) {
		if (p.second) {
			p.first->DeRegItem();
			p.second = false;
		}
	}
}

void Enemy::shoot()
{
	if (shootTime >= MAXSHOOTTIME) {
		shootTime = 0.0;
		//Instanciar la bala
	}
}

void Enemy::proyectilUpdate(double t)
{
	for (auto proyectiles : disparos) {
		if (proyectiles.second) {
			proyectiles.first->integrate(t);
		}
	}
	if (shootTime > MAXSHOOTTIME) {
		shootTime = MAXSHOOTTIME;
	}
	else {
		shootTime += t;
	}
}
