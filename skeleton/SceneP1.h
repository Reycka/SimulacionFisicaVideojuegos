#pragma once
#include "Scene.h"
class SceneP1 : public Scene
{
	public:
		SceneP1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene);
		~SceneP1();
};

