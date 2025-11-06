#pragma once
#include "Scene.h"
class nave;
class WhirlwindGenerator;
class WindGenerator;
class GravityGenerator;
class Player;
class gameScene : public Scene
{
private:
	Player* pla;
	GravityGenerator* g;
	WindGenerator* wind;
	WhirlwindGenerator* whirlWind;
	nave* model;
public:
	gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~gameScene();
	virtual void keyPress(unsigned char key) override;
};

