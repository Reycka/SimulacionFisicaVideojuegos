#include "SceneP0.h"

using namespace physx;
SceneP0::SceneP0(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene) : Scene(_gMaterial,_phy,_gScene)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 sphereColor = { 1.0f,1.0f,1.0f,1.0f };
	AddEntity(new Entity(Vector3(0, 0, 0), sphereShape, sphereColor));
}

SceneP0::~SceneP0()
{
}
