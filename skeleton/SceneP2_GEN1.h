#pragma once
#include "Scene.h"
class SceneP2_GEN1 : public Scene
{
public:
	SceneP2_GEN1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP2_GEN1();
};


