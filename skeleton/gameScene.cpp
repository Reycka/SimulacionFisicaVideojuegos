#include "gameScene.h"
#include "GravityGenerator.h"
#include "WindGenerator.h"
#include "WhirlwindGenerator.h"
#include "ExplosionGenerator.h"
#include "Player.h"
#include "nave.h"
using namespace physx;
gameScene::gameScene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{/*
	PxShape* sphereShape = CreateShape(PxSphereGeometry(3), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };
	Vector4 rainColor = { 0.0f,0.0f,1.0f,0.8f };
	PxShape* rainShape = CreateShape(PxSphereGeometry(0.5), getMaterial());

	ParticleSystem* partSys = new ParticleSystem();
	UniformGenerator* unif = new UniformGenerator(80, { -20.0,60.0,-20.0 }, rainShape, rainColor, { 0.0,-60.0,0.0 }, 25, 40, 0.2);
	ExplosionGenerator* exp = new ExplosionGenerator({ 15.0f, 15.0f, 0.0f }, 0.0f, 2.0f, 25500.0f, { 3043.0f, 2405.0f, 1234.0f }, 0.5);
	model = new nave({ 15.0,15.0,15.0 }, { 15.0,15.0,15.0 }, sphereShape,getMaterial(), sphereColor, {0.0,3.0,0.0}, 20.0,0.1, 30.0, 0.999, 2, 100, 2.0,exp, getCamera()->getTransform());
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
	partSys->addGenerator(unif);
	partSys->addForceGenerator(whirlWind);
	partSys->addForceGenerator(g);
	partSys->addForceGenerator(wind);
	partSys->addForceGenerator(exp);
	whirlWind->setIsActive(false);
	wind->setIsActive(false);
	exp->setIsActive(false);

	pla = new Player(3);
	pla->addForceGenerator(g);
	pla->addForceGenerator(wind);
	pla->addForceGenerator(whirlWind);
	pla->addForceGenerator(exp);
	AddEntity(model);
	AddEntity(partSys);
	AddEntity(pla);*/
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
