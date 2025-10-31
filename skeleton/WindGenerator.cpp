#include "WindGenerator.h"


WindGenerator::WindGenerator(Vector3 _pos, float _rad, Vector3 _windVelocity, float _k1, float _k2 )
{
	pos = _pos;
	rad = _rad;
	windVelocity = _windVelocity;
	k1 = _k1;
	k2 = _k2;
}

WindGenerator::~WindGenerator()
{
}

Vector3 WindGenerator::addForce(Vector3 entPos, Vector3 entVelocity)
{
	if (isActive && isOnArea(entPos)) {
		return k1 * (windVelocity - entVelocity) + k2 * 
			(windVelocity.magnitude() - entVelocity.magnitude()) * (windVelocity - entVelocity);
	}
	else {
		return Vector3({ 0.0,0.0,0.0 });
	}
}

bool WindGenerator::isOnArea(Vector3 entPos)
{
	bool onArea = false;
	if (entPos.x <= pos.x + rad && entPos.x >= pos.x - rad) {
		onArea = true;
	}
	else if (entPos.y <= pos.y + rad && entPos.y >= pos.y - rad) {
		onArea = true;
	}
	else if (entPos.z <= pos.z + rad && entPos.z >= pos.z - rad) {
		onArea = true;
	}
	return onArea;
}
