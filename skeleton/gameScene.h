#pragma once
#include "Scene.h"
class nave;
class WhirlwindGenerator;
class WindGenerator;
class ExplosionGenerator;
class GravityGenerator;
class gameScene : public Scene
{
private:
	GravityGenerator* g;
	WindGenerator* wind;
	WhirlwindGenerator* whirlWind;
	ExplosionGenerator* explosion;
	nave* model;
public:
	gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~gameScene();
	virtual void keyPress(unsigned char key) override;
};

