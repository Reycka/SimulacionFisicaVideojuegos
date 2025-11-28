#include "FloatingForceGenerator.h"

void FloatingForceGenerator::sacaVolSumergido(Vector3 entPos)
{
	float h = entPos.y;
	float h0 = pos.y;
	if (h0 - h > height * 0.5) {
		volSumergido = 1.0; //Todo el cuerpo esta sumergido
	}
	else {
		volSumergido = (h - h0) / (height + 0.5); //Se encuentra medio dentro medio fuera
	}

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
		sacaVolSumergido(entPos);
		forceToReturn = volSumergido * ent->getVol() * densidad * g;
		return forceToReturn;
	}
	else return Vector3({ 0.0,0.0,0.0 });
}

bool FloatingForceGenerator::isOnArea(Vector3 entPos)
{
	float h = entPos.y;
	float h0 = pos.y;
	if (h - h0 > height *0.5) {
		return false;
	}
	return true;
}
