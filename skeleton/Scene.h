#pragma once
#include <vector>
#include "ForceGenerator.h"
#include "RigidBodyManager.h"
class Scene {
private:
	std::vector<Entity*> entities;
	std::vector<ForceGenerator*> generators;
	physx::PxPhysics* phy;
	physx::PxScene* gScene;
	physx::PxMaterial* gMaterial;
	Camera* cam;
protected:

public:
	Scene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy,physx::PxScene* _gScene, Camera* _cam);
	virtual ~Scene();
	void AddEntity(Entity* ent);
	void AddForceGenerator(ForceGenerator* forceGen);
	void RegScene();
	void DeRegScene();
	void CreateAxes();
	void update(double t);
	virtual void keyPress(unsigned char key);
	physx::PxPhysics* getPhysx() const;
	physx::PxScene* getPhysxScene() const;
	physx::PxMaterial* getMaterial() const;
	Camera* getCamera() const;
};