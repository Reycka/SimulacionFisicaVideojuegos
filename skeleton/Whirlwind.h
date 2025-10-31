#pragma once
#include "ForceGenerator.h"
class Whirlwind : public ForceGenerator
{
private:
public:
	Whirlwind();
	~Whirlwind();
	virtual Vector3 addForce(Vector3 entPos,Vector3 entVel) override;
	virtual bool isOnArea(Vector3 entPos) override;
};

