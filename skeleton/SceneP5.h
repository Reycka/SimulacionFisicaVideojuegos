#pragma once
#include "Scene.h"
class SceneP5 : public Scene
{
private:

public:
	SceneP5(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP5();
	virtual void keyPress(unsigned char key) override;
};