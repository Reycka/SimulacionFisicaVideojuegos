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

Vector3 FloatingForceGenerator::addForce(physx::PxShape* shape, Vector3 entPos, Vector3 entVelocity, float t, float masa)
{
	if (isActive && isOnArea(entPos)) {

	}
}

bool FloatingForceGenerator::isOnArea(Vector3 entPos)
{
	return entPos.y <= pos.y;
}
