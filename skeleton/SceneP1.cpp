#include "SceneP1.h"
#include "Particle.h"
#include "Proyectil.h"
using namespace physx;
SceneP1::SceneP1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene,_cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };

	//Part�culas
	//Sin Aceleraci�n
	AddEntity(new Particle(Vector3(0, 0, 0), sphereShape, sphereColor, Vector3(0.0, 10.0, 0.0), Vector3(0.0, 0.0, 0.0), 10, 10));
	//Con Aceleraci�n
	AddEntity(new Particle(Vector3(0, 0, 0), sphereShape, sphereColor,Vector3(0.0,1.0,0.0),Vector3(0.0,6.0,0.0),10,10));


}

SceneP1::~SceneP1()
{
}

void SceneP1::keyPress(unsigned char key)
{
	switch (key) {
	case 'c':
		AddEntity(new Proyectil(getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,1.0f,0.0f,1.0f } , getCamera()->getDir() * 100, Vector3(1.0, 10.0, 1.0), 10, 10, 30, Vector3(30.0, 15.0, 0.0), Vector3(0.0, -12.0, 0.0)));
		break;
	case 'v':
		AddEntity(new Proyectil(getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 1.0f,0.0f,1.0f,1.0f }, getCamera()->getDir() * 100, Vector3(1.0, 20.0, 1.0), 10, 10, 30, Vector3(30.0, 15.0, 0.0), Vector3(0.0, 2.0, 0.0)));
		break;
	case 'b':
		AddEntity(new Proyectil(getCamera()->getEye(), CreateShape(PxSphereGeometry(1), getMaterial()), { 0.0f,1.0f,1.0f,1.0f }, getCamera()->getDir() * 100, Vector3(1.0, 10.0, 1.0), 10, 10, 30, Vector3(30.0, 15.0, 0.0), Vector3(0.0, -22.0, 0.0)));
		break;
	}
}


