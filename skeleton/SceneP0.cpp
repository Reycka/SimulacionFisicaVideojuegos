#include "SceneP0.h"

using namespace physx;
SceneP0::SceneP0(PxMaterial* gMaterial) : Scene(gMaterial)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 sphereColor = { 1.0f,1.0f,1.0f,1.0f };
	AddEntity(new Entity(Vector3D(0, 0, 0), sphereShape, sphereColor));
}

SceneP0::~SceneP0()
{
}
