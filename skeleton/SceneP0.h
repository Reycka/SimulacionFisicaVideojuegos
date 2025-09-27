#pragma once
#include "Scene.h"
class SceneP0 : public Scene{
public:
	SceneP0();
	SceneP0(physx::PxMaterial* gMaterial);
	~SceneP0();
};