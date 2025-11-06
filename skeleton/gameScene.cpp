#include "gameScene.h"
#include "nave.h"
using namespace physx;
gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(3), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };
	Proyectil* p = new Proyectil({ 15.0,15.0,15.0 }, CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,1.0f,0.0f,1.0f }, getCamera()->getEye() , 10, 60, 60, Vector3(30.0, 15.0, 0.0));
	model = new nave({ 15.0,15.0,15.0 }, { 15.0,15.0,15.0 }, sphereShape,getMaterial(), sphereColor, {-1.0,0.0,0.0}, 20.0, 30.0, 0.999, 2, 100, 2.0,p);
	AddEntity(model);
}

gameScene::~gameScene()
{
}

void gameScene::keyPress(unsigned char key)
{
	switch (key) {
	case 'c':
		AddEntity(new Proyectil(getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,1.0f,0.0f,1.0f }, getCamera()->getDir() * 100, 10, 10, 60, Vector3(30.0, 15.0, 0.0)));
		break;
	case 'v':
		AddEntity(new Proyectil(getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,0.0f,1.0f,1.0f }, getCamera()->getDir() * 100, 50, 10, 30, Vector3(30.0, 15.0, 0.0)));
		break;
	case 'b':
		break;
	}
}
