#pragma once
#include "WindGenerator.h"
class WhirlwindGenerator : public WindGenerator
{
private:
	Vector3 windForce;
public:
	WhirlwindGenerator(Vector3 _pos, float rad, float k);
	~WhirlwindGenerator();
	virtual Vector3 addForce(physx::PxShape* shape,Vector3 entPos,Vector3 entVel,float t = 0,float m = 0) override;
};

