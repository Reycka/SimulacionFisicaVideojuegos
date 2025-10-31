#pragma once
#include "ForceGenerator.h"
class GravityGenerator : public ForceGenerator
{
private:
	Vector3 grav;
public:
	GravityGenerator(Vector3 g);
	virtual ~GravityGenerator();
	virtual Vector3 addForce(Vector3 entPos, Vector3 entVelocity) override;
	virtual bool isOnArea(Vector3 entPos) override;
};

