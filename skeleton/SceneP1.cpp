#include "SceneP1.h"
#include "Particle.h"
using namespace physx;
SceneP1::SceneP1(physx::PxMaterial* gMaterial) : Scene(gMaterial)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };
	AddEntity(new Particle(Vector3D(0, 0, 0), sphereShape, sphereColor,Vector3D(0.0,10.0,0.0),Vector3D(0.0,0.0,0.0),10,10));

}

SceneP1::~SceneP1()
{
}
