#pragma once
#include "WindGenerator.h"
class WhirlwindGenerator : public WindGenerator
{
private:
public:
	WhirlwindGenerator(Vector3 _pos, float rad, Vector3 windVelocity, float k1, float k2 = 0);
	~WhirlwindGenerator();
	virtual Vector3 addForce(Vector3 entPos,Vector3 entVel) override;
};

