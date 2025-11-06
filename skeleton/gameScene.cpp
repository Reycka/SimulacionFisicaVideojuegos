#include "gameScene.h"
#include "GravityGenerator.h"
#include "WindGenerator.h"
#include "WhirlwindGenerator.h"
#include "ExplosionGenerator.h"
#include "nave.h"
using namespace physx;
gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(3), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };
	Proyectil* p = new Proyectil({ 15.0,15.0,15.0 }, CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,1.0f,0.0f,1.0f }, getCamera()->getEye() , 10, 60, 60, Vector3(30.0, 15.0, 0.0));
	ExplosionGenerator* exp = new ExplosionGenerator({ 15.0f, 15.0f, 0.0f }, 0.0f, 2.0f, 25500.0f, { 3043.0f, 2405.0f, 1234.0f }, 0.5);
	model = new nave({ 15.0,15.0,15.0 }, { 15.0,15.0,15.0 }, sphereShape,getMaterial(), sphereColor, {0.0,3.0,0.0}, 20.0, 30.0, 0.999, 2, 100, 2.0, p,exp);
	whirlWind = new WhirlwindGenerator({ 0.0,-20.0,0.0 }, 70.0f, 10);
	g = new GravityGenerator({ 0.0,-10.0,0.0 });
	wind = new WindGenerator({15.0,15.0,15.0}, 30.0f, {10.0,0.0,0.0}, 50);
	
	AddForceGenerator(whirlWind);
	AddForceGenerator(g);
	AddForceGenerator(wind);
	AddForceGenerator(exp);
	model->addForceGenerator(whirlWind);
	model->addForceGenerator(g);
	model->addForceGenerator(wind);
	whirlWind->setIsActive(false);
	wind->setIsActive(false);
	exp->setIsActive(false);
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
		model->GotHit(1);
		break;
	case 'n':
		whirlWind->setIsActive(!whirlWind->getIsActive());
		break;
	case 'g':
		g->setIsActive(!g->getIsActive());
		break;
	case 'm':
		wind->setIsActive(!wind->getIsActive());
		break;
	}
}
