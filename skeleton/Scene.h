#pragma once
#include <vector>
#include "Entity.h"

class Scene {
private:
	std::vector<Entity*> entities;
	physx::PxPhysics* phy;
	physx::PxScene* gScene;
	physx::PxMaterial* gMaterial;
protected:

public:
	Scene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy,physx::PxScene* _gScene);
	virtual ~Scene();
	void AddEntity(Entity* ent);
	void RegScene();
	void DeRegScene();
	void CreateAxes();
	void update(double t);
	physx::PxPhysics* getPhysx() const;
	physx::PxScene* getPhysxScene() const;
	physx::PxMaterial* getMaterial() const;
};