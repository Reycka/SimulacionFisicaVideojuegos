#include "RigidBodySystem.h"
RigidBodySystem::RigidBodySystem() : Entity()
{
	Entity::DeRegItem();
}

RigidBodySystem::~RigidBodySystem()
{
	for (auto dyn : dynamicList) {
		delete dyn;
	}
	for (auto st : staticList) {
		delete st;
	}
}

void RigidBodySystem::AddSolidRigid(DynamicSolidRigid* solidRigid)
{
	solidRigid->getObj()->getScene()->addActor(*solidRigid->getObj());
	dynamicList.push_back(solidRigid);
}

void RigidBodySystem::AddSolidRigid(StaticSolidRigid* solidRigid)
{
	solidRigid->getObj()->getScene()->addActor(*solidRigid->getObj());
	staticList.push_back(solidRigid);
}

void RigidBodySystem::regSolidRigids()
{
	for (auto dyn : dynamicList) {
		dyn->RegItem();
	}
	for (auto st : staticList) {
		st->RegItem();
	}
}

void RigidBodySystem::DeRegSolidRigids()
{
	for (auto dyn : dynamicList) {
		dyn->DeRegItem();
	}
	for (auto st : staticList) {
		st->DeRegItem();
	}
}
