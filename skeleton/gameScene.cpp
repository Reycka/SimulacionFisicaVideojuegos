#include "gameScene.h"
#include "nave.h"
using namespace physx;
gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(3), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };
	model = new nave({ 15.0,15.0,15.0 }, { 15.0,15.0,15.0 }, sphereShape,getMaterial(), sphereColor, {-1.0,0.0,0.0}, 20.0, 30.0, 0.999, 2, 100, 2.0);
	AddEntity(model);
}

gameScene::~gameScene()
{
}

void gameScene::keyPress(unsigned char key)
{
}
