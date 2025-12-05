#include "RigidBodyManager.h"
RigidBodyManager::RigidBodyManager()
{
}

RigidBodyManager::~RigidBodyManager()
{
	for (auto dyn : dynamicList) {
		delete dyn;
	}
	for (auto st : staticList) {
		delete st;
	}
}

void RigidBodyManager::AddSolidRigid(DynamicSolidRigid* solidRigid)
{
	solidRigid->getObj()->getScene()->addActor(*solidRigid->getObj());
	dynamicList.push_back(solidRigid);
}

void RigidBodyManager::AddSolidRigid(StaticSolidRigid* solidRigid)
{
	solidRigid->getObj()->getScene()->addActor(*solidRigid->getObj());
	staticList.push_back(solidRigid);
}

void RigidBodyManager::regSolidRigids()
{
	for (auto dyn : dynamicList) {
		dyn->getObj()->getScene()->addActor(*dyn->getObj());
	}
	for (auto st : staticList) {
		st->getObj()->getScene()->addActor(*st->getObj());
	}
}

void RigidBodyManager::DeRegSolidRigids()
{
	for (auto dyn : dynamicList) {
		dyn->getObj()->getScene()->removeActor(*dyn->getObj());
	}
	for (auto st : staticList) {
		st->getObj()->getScene()->removeActor(*st->getObj());
	}
}
