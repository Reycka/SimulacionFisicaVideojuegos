#pragma once
#include "Scene.h"
class ExplosionGenerator;
class SceneP3_Explosion : public Scene
{
private:
	ExplosionGenerator* exp;
public:
	SceneP3_Explosion(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam);
	~SceneP3_Explosion();
	virtual void keyPress(unsigned char key) override;
};

