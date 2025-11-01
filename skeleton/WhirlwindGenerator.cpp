#include "WhirlwindGenerator.h"

WhirlwindGenerator::WhirlwindGenerator(Vector3 _pos, float rad, Vector3 windVelocity, float k1, float k2) : WindGenerator(_pos,rad,windVelocity,k1,k2)
{
}

WhirlwindGenerator::~WhirlwindGenerator()
{
}

Vector3 WhirlwindGenerator::addForce(Vector3 entPos, Vector3 entVel)
{
	return Vector3();
}
