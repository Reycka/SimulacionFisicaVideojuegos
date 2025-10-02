#pragma once
#include "Scene.h"
class SceneP0 : public Scene{
public:
	SceneP0(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene);
	~SceneP0();
};