#pragma once
#include "Scene.h"
class nave;
class WhirlwindGenerator;
class WindGenerator;
class GravityGenerator;
class Player;
class RigidBodySystem;
class FloatingForceGenerator;

class gameScene : public Scene
{
private:
	Player* pla;
	WindGenerator* wind;
	WhirlwindGenerator* whirlWind;
	FloatingForceGenerator* flFGen;
	nave* modelShip;
	nave* modelBoat;
	RigidBodySystem* rgbs;

	void createLimits();
	void createModels();
	void createEnemyGenerators();
	void createForces();

public:
	gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~gameScene();
	virtual void keyPress(unsigned char key) override;
};

