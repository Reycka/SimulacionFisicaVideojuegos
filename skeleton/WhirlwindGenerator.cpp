#include "WhirlwindGenerator.h"

WhirlwindGenerator::WhirlwindGenerator(Vector3 _pos, float rad, float k) : WindGenerator(_pos,rad,{0.0,0.0,0.0}, k)
{
}

WhirlwindGenerator::~WhirlwindGenerator()
{
}

Vector3 WhirlwindGenerator::addForce(Entity* ent, float t)
{
	windForce = Vector3({ 0.0,0.0,0.0 });
	Vector3 entPos = ent->getT()->p;
	if (isActive && isOnArea(entPos)) {
		windForce.x = k1 * -(entPos.z - pos.z);
		windForce.y = k1 * (50 - (entPos.y - pos.y));
		windForce.z = k1 * (entPos.x - pos.x);
	}
	return windForce;
}
