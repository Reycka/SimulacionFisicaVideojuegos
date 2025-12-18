#include "gameScene.h"
#include "WindGenerator.h"
#include "WhirlwindGenerator.h"
#include "ExplosionGenerator.h"
#include "FloatingForceGenerator.h"
#include "Player.h"
#include "nave.h"
#include "RigidBodySystem.h"
#include "SolidRigidGaussianGenerator.h"
#include "GeneradorNave.h"
using namespace physx;

gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	gScene = _gScene;
	phy = _phy;
	pla = new Player(3);
	rgbs = new RigidBodySystem();
	wind = new WindGenerator(_cam->getTransform().p , 50.0f, Vector3(20.0, 0.0, 0.0), 120);
	createLimits();
	createEnemyGenerators(_gMaterial,_phy, _gScene, _cam);
	createForces();
	AddEntity(pla);
	AddEntity(rgbs);
}

gameScene::~gameScene()
{

}

void gameScene::keyPress(unsigned char key)
{
	PxReal coef = 0.4;
	Proyectil* p = new Proyectil(gScene, coef, coef / 2, coef * 2, phy, PxSphereGeometry(1), getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,0.0f,0.0f,1.0f }, -getCamera()->getDir() * 240, 50, 0.1, 30, 30, Vector3(30.0, 15.0, 0.0));
	p->addForceGenerator(wind);
	switch (key) {
	case 'c':
		pla->shoot(p);
		break;
	case 'n':
		whirlWind->setIsActive(!whirlWind->getIsActive());
		break;
	case 'm':
		wind->setIsActive(!wind->getIsActive());
		break;
	}
}
void gameScene::createLimits()
{
	//Floor
	float height = 32.0f;
	PxShape* water = CreateShape(PxBoxGeometry(200.0f, height, 200.0f), getMaterial());
	Vector4 waterColor = { 0.4f,0.4f,1.0f,0.0f };
	AddEntity(new Entity(Vector3(0, -15, 0), water, waterColor, Vector3(0.0, 0.0, 0.0), 100.0, 100, 100));
	
	//Walls
	Vector4 wallColor = Vector4(0.529, 0.808, 0.922, 1.0);
	PxShape* Wall = CreateShape(PxBoxGeometry(200.0f, height, 200.0f), getMaterial());
	AddEntity(new Entity(Vector3(395, 50, 0), Wall, wallColor, Vector3(0.0, 0.0, 0.0), 100.0, 100, 100));
	AddEntity(new Entity(Vector3(-390, 50, 0), Wall, wallColor, Vector3(0.0, 0.0, 0.0), 100.0, 100, 100));
	AddEntity(new Entity(Vector3(0, 50, 395), Wall, wallColor, Vector3(0.0, 0.0, 0.0), 100.0, 100, 100));
	AddEntity(new Entity(Vector3(0, 50, -390), Wall, wallColor, Vector3(0.0, 0.0, 0.0), 100.0, 100, 100));


}
void gameScene::createEnemyGenerators(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam)
{
	PxReal coef = 0.4;
	rgbs->addGenerator(new GeneradorNave(gScene, coef, coef / 2, coef * 2, _phy, PxSphereGeometry(3), Vector3(-100.0, 40.0, 0.0),
		Vector4(1.0, 0.0, 1.0, 1.0), Vector3(1.0, 0.0, 0.0), 30.0, 2, 100.0, getCamera()->getTransform()));

}

void gameScene::createForces()
{
	float height = 32.0f;
	flFGen = new FloatingForceGenerator(height, 1000.0f, Vector3(0.0, 9.8, 0.0), Vector3({ 0.0,0.0,0.0 }));
	whirlWind = new WhirlwindGenerator({ 0.0,30.0,0.0 }, 70.0f, 320);
	explosion = new ExplosionGenerator({ 15.0f, 15.0f, 0.0f }, 0.0f, 2.0f, 25500.0f, { 3043.0f, 2405.0f, 1234.0f }, 1);
	whirlWind->setIsActive(false);
	rgbs->addForceGenerator(flFGen);
	rgbs->addForceGenerator(whirlWind);
	AddForceGenerator(flFGen);
	AddForceGenerator(whirlWind);
	AddForceGenerator(wind);

}
