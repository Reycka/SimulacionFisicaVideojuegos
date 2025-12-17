#include "gameScene.h"
#include "GravityGenerator.h"
#include "WindGenerator.h"
#include "WhirlwindGenerator.h"
#include "ExplosionGenerator.h"
#include "FloatingForceGenerator.h"
#include "Player.h"
#include "nave.h"
#include "RigidBodySystem.h"
using namespace physx;

gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	pla = new Player(3);
	rgbs = new RigidBodySystem();
	createLimits();
	createEnemyGenerators();
	createForces();
	AddEntity(pla);
	AddEntity(rgbs);
}

gameScene::~gameScene()
{

}

void gameScene::keyPress(unsigned char key)
{
	switch (key) {
	case 'c':
		pla->shoot(new Proyectil(getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,0.0f,0.0f,1.0f }, getCamera()->getDir() * 60, 50,0.1, 10, 30, Vector3(30.0, 15.0, 0.0)));
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
void gameScene::createModels()
{
}
void gameScene::createEnemyGenerators()
{
	createModels();
}

void gameScene::createForces()
{
	float height = 32.0f;
	flFGen = new FloatingForceGenerator(height * 2, 1000.0f, Vector3(0.0, 9.8, 0.0), Vector3({ 0.0,30.0,0.0 }));
	whirlWind = new WhirlwindGenerator({ 0.0,-20.0,0.0 }, 70.0f, 10);
	wind = new WindGenerator({ 15.0,15.0,15.0 }, 30.0f, { 10.0,0.0,0.0 }, 50);
	whirlWind->setIsActive(false);
	wind->setIsActive(false);
	rgbs->addForceGenerator(flFGen);
	rgbs->addForceGenerator(whirlWind);
	rgbs->addForceGenerator(wind);
	AddForceGenerator(flFGen);
	AddForceGenerator(whirlWind);
	AddForceGenerator(wind);

}
