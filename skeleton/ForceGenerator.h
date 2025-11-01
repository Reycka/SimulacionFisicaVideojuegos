#pragma once
#include <list>
#include "RenderUtils.hpp"
class ForceGenerator
{
protected:
	bool isActive = true;
public:
	virtual Vector3 addForce(Vector3 entPos, Vector3 entVelocity,float t = 0) = 0;
	virtual bool isOnArea(Vector3 entPos) = 0;
 
	inline void setIsActive(bool a) { isActive = a; }
	inline bool operator==(ForceGenerator* other) { return this == other; };
};

