#include "SceneP4Floating.h"
#include "FloatingForceGenerator.h"
#include "GravityGenerator.h"
#include "Particle.h"
using namespace physx;
SceneP4Floating::SceneP4Floating(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* SmallBoxShape = CreateShape(PxBoxGeometry(2.5f, 2.5f, 2.5f), getMaterial());
	Vector4 SmallBoxColor = { 0.5f,0.0f,1.0f,1.0f };

	float height = 12.0f;
	PxShape* water = CreateShape(PxBoxGeometry(20.0f, height, 20.0f), getMaterial());
	Vector4 waterColor = { 0.4f,0.4f,1.0f,0.0f };

	FloatingForceGenerator* fl = new FloatingForceGenerator(height,1000.0f,Vector3(0.0,9.8,0.0), Vector3({0.0,0.0,0.0}));
	GravityGenerator* gr = new GravityGenerator(Vector3(0.0, -9.8, 0.0));
	box = new Particle(Vector3(0, 30.0, 0), SmallBoxShape, SmallBoxColor, Vector3(0.0, -15.0, 0.0),10, 0.500, 10, 0.01);
	AddEntity(box);
	AddEntity(new Entity(Vector3(0, 0, 0), water, waterColor, Vector3(0.0, 0.0, 0.0), 100.0, 100, 100));
	AddForceGenerator(fl);
	AddForceGenerator(gr);
	box->addForceGenerator(fl);
	box->addForceGenerator(gr);
}

SceneP4Floating::~SceneP4Floating()
{
}

void SceneP4Floating::keyPress(unsigned char key)
{
	switch (key) {
	case 'm':
		box->setMasa(box->getMasa() * 2);
		break;
	case 'v':
		box->setVolume(box->getVol() * 2);
	}
}
