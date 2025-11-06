#include "Player.h"

Player::Player(int _health) : Entity()
{
	Entity::DeRegItem();
	health = _health;
	sh = new shootManager();
}

Player::~Player()
{
	Entity::RegItem();
	delete sh;
}

void Player::RegItem()
{
	sh->RegItem();
}


void Player::DeRegItem()
{
	sh->DeRegItem();
}

void Player::GotHit(int damage)
{
	health -= damage;
}

void Player::addForceGenerator(ForceGenerator* gen)
{
	sh->addForceGenerator(gen);
}

void Player::shoot(Proyectil* p)
{
	sh->addProyectil(p);
}


void Player::integrate(double t)
{
	sh->integrate(t);
}
