#pragma once
#include "WindGenerator.h"
class WhirlwindGenerator : public WindGenerator
{
private:
	Vector3 windForce;
public:
	WhirlwindGenerator(Vector3 _pos, float rad, float k);
	~WhirlwindGenerator();
	virtual Vector3 addForce(Entity* ent, float t) override;
};

