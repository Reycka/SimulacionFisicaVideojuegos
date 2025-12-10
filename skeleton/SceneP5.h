#pragma once
#include "Scene.h"
#include "StaticSolidRigid.h"
#include "SolidRigidGaussianGenerator.h"
class SceneP5 : public Scene
{
private:
	SolidRigidGaussianGenerator* solidGen;
	StaticSolidRigid* actor;
public:
	SceneP5(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP5();
	virtual void keyPress(unsigned char key) override;
};