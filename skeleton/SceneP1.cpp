#include "SceneP1.h"
#include "Particle.h"
using namespace physx;
SceneP1::SceneP1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene) : Scene(_gMaterial, _phy, _gScene)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };

	//Sin Aceleración
	AddEntity(new Particle(Vector3(0, 0, 0), sphereShape, sphereColor, Vector3(0.0, 10.0, 0.0), Vector3(0.0, 0.0, 0.0), 10, 10));
	//Con Aceleración
	AddEntity(new Particle(Vector3(0, 0, 0), sphereShape, sphereColor,Vector3(0.0,1.0,0.0),Vector3(0.0,6.0,0.0),10,10));

}

SceneP1::~SceneP1()
{
}
