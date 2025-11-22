#pragma once
#include "Scene.h"
#include "WindGenerator.h"
#include "dockForceGenerator.h"
class SceneP4 : public Scene
{
private:
	WindGenerator* windGen;
	dockForceGenerator* dockGen;
	bool slinky = true;
public:
	SceneP4(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP4();
	void createSlinky();
	virtual void keyPress(unsigned char key) override;
};


