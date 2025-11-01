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

Vector3 WindGenerator::addForce(Vector3 entPos, Vector3 entVelocity,float t)
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
	// Vector desde el generador hasta la entidad
	Vector3 toEntity = entPos - pos;

	// Dirección del viento normalizada
	Vector3 windDir = windVelocity.getNormalized();

	// Proyección del vector hacia la entidad sobre el plano perpendicular al viento
	Vector3 perpendicular = toEntity - windDir * toEntity.dot(windDir);

	// Si la distancia perpendicular es menor que el radio, está dentro del área
	return perpendicular.magnitude() <= rad;
}

