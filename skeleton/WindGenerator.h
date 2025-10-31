#pragma once
#include "ForceGenerator.h"
class WindGenerator : public ForceGenerator
{
enum dir {
    TOP,
	DOWN,
	RIGHT,
	LEFT,
	TOPLEFT,
	TOPRIGHT,
	DOWNLEFT,
	DOWNRIGHT
};
private:
	Vector3 pos;
	float rad;
	Vector3 windVelocity;
	float k1;
	float k2;

public:
	WindGenerator(Vector3 _pos,float rad,Vector3 windVelocity,float k1,float k2 = 0);
	~WindGenerator();
	virtual Vector3 addForce(Vector3 entPos, Vector3 entVelocity) override;
	virtual bool isOnArea(Vector3 entPos) override;
};

