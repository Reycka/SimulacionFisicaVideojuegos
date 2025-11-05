#include "gameScene.h"
#include "nave.h"
using namespace physx;
gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };
	model = new nave({ 35.0,35.0,35.0 }, { 35.0,35.0,35.0 }, sphereShape, sphereColor, { -1.0,0.0,0.0 }, 20.0, 30.0, 0.999, 2, 100, 2.0);
	AddEntity(model);
}

gameScene::~gameScene()
{
}

void gameScene::keyPress(unsigned char key)
{
}
