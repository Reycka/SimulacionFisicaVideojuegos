#pragma once
#include "DynamicSolidRigid.h"
#include "StaticSolidRigid.h"
#include <list>
class RigidBodyManager
{
private:
	std::list<DynamicSolidRigid*> dynamicList;
	std::list<StaticSolidRigid*> staticList;
public:
	RigidBodyManager();
	~RigidBodyManager();
	void AddSolidRigid(DynamicSolidRigid* solidRigid);
	void AddSolidRigid(StaticSolidRigid* solidRigid);
	void regSolidRigids();
	void DeRegSolidRigids();
};

