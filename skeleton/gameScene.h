#pragma once
#include "Scene.h"
class nave;
class WindGenerator;
class Player;
class RigidBodySystem;
class FloatingForceGenerator;

class gameScene : public Scene
{
private:
	Player* pla;
	WindGenerator* wind;
	FloatingForceGenerator* flFGen;
	RigidBodySystem* rgbs;
	physx::PxPhysics* phy;
	physx::PxScene* gScene;

	void createLimits();
	void createEnemyGenerators(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	void createForces();

public:
	gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~gameScene();
	virtual void keyPress(unsigned char key) override;
};

