#include "FloatingForceGenerator.h"

void FloatingForceGenerator::sacaVolSumergido(Vector3 entPos)
{
	
}

FloatingForceGenerator::FloatingForceGenerator(float _height,float _dens, Vector3 _g, Vector3 _pos)
{
	height = _height;
	densidad = _dens;
	g = _g;
	pos = _pos;
}

FloatingForceGenerator::~FloatingForceGenerator()
{
}

Vector3 FloatingForceGenerator::addForce(Entity* ent, float t)
{
	Vector3 entPos = ent->getT()->p;
	if (isActive && isOnArea(entPos)) {
		return forceToReturn;
	}
	else return Vector3({ 0.0,0.0,0.0 });
}

bool FloatingForceGenerator::isOnArea(Vector3 entPos)
{
	return entPos.y <= pos.y;
}
