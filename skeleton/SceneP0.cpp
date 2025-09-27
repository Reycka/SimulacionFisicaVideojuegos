#include "SceneP0.h"

using namespace physx;
SceneP0::SceneP0(PxMaterial* gMaterial)
{
	//Act 2 P0 Draw a sphere in 0,0,0
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 sphereColor = { 1.0f,1.0f,1.0f,1.0f };
	AddEntity(new Entity(Vector3D(0, 0, 0), sphereShape, sphereColor));

	//Act 3 P0 Draw x, y and Z axes
	CreateAxes(gMaterial);
}

SceneP0::~SceneP0()
{
}
