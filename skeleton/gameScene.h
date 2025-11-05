#pragma once
#include "Scene.h"
class nave;
class gameScene : public Scene
{
private:
	nave* model;
public:
	gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~gameScene();
	virtual void keyPress(unsigned char key) override;
};

