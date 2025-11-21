#pragma once
#include "Scene.h"
class SceneP4 : public Scene
{
public:
	SceneP4(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP4();
};


