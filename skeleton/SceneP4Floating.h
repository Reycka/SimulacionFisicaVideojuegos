#pragma once
#include "Scene.h"
class Particle;
class SceneP4Floating : public Scene
{
private:
	Particle* box;
public:
	SceneP4Floating(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP4Floating();
	virtual void keyPress(unsigned char key) override;
};

