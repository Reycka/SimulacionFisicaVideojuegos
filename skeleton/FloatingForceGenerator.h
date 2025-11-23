#pragma once
#include "ForceGenerator.h"
class FloatingForceGenerator : public ForceGenerator
{
private:
	float volSumergido;
	float densidad;
	float height;
	Vector3 g;
	Vector3 forceToReturn;
	Vector3 pos;
	void sacaVolSumergido(Vector3 entPos);
public:
	FloatingForceGenerator(float _height,float _dens, Vector3 _g,Vector3 _pos);
	~FloatingForceGenerator();
	virtual Vector3 addForce(Entity* ent, float t) override;
	virtual bool isOnArea(Vector3 entPos) override;
};
