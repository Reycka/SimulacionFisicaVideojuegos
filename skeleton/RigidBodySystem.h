#pragma once
#include "DynamicSolidRigid.h"
#include "StaticSolidRigid.h"
#include <list>
class RigidBodySystem : public Entity
{
private:
	std::list<DynamicSolidRigid*> dynamicList;
	std::list<StaticSolidRigid*> staticList;
public:
	RigidBodySystem();
	~RigidBodySystem();
	void AddSolidRigid(DynamicSolidRigid* solidRigid);
	void AddSolidRigid(StaticSolidRigid* solidRigid);
	void regSolidRigids();
	void DeRegSolidRigids();
};

