#pragma once
#include "ForceGenerator.h"
class WindGenerator : public ForceGenerator
{

protected:
	Vector3 pos;
	float rad;
	Vector3 windVelocity;
	float k1;
	float k2;

public:
	WindGenerator(Vector3 _pos,float rad,Vector3 windVelocity,float k1,float k2 = 0);
	~WindGenerator();
	virtual Vector3 addForce(Entity* ent, float t) override;
	virtual bool isOnArea(Vector3 entPos) override;
};

