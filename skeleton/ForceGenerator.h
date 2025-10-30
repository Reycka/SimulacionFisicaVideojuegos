#pragma once
#include <list>
#include "RenderUtils.hpp"
class ForceGenerator
{
protected:
	bool isActive = true;
public:
	virtual Vector3 addForce() = 0;
	inline void setIsActive(bool a) { isActive = a; }
	inline bool operator==(ForceGenerator* other) { return this == other; };
};

