#pragma once
#include <list>
#include "Vector3D.h"
class ForceGenerator
{
private:
	bool isActive;
public:
	virtual Vector3 addForce() {};
	inline void setIsActive(bool a) { isActive = a; }
};

