#pragma once
#include <list>
#include "RenderUtils.hpp"
#include "Entity.h"
class ForceGenerator
{
protected:
	bool isActive = true;
public:
	virtual Vector3 addForce(Entity* ent, float t) = 0;
	virtual bool isOnArea(Vector3 entPos) = 0;
	inline bool getIsActive()const { return isActive; };
	inline void setIsActive(bool a) { isActive = a; }
	inline bool operator==(ForceGenerator* other) { return this == other; };
};

