#include "SceneP2_GEN1.h"

#include "ParticleSystem.h"
#include "GaussianGenerator.h"
using namespace physx;
SceneP2_GEN1::SceneP2_GEN1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 sphereColor = { 1.0f,1.0f,0.0f,1.0f };

	ParticleSystem* partSys = new ParticleSystem();
	GaussianGenerator* gaus = new GaussianGenerator({20.0,7.0,15.0}, { 0.0,0.0,0.0 }, sphereShape, sphereColor, { 0.0,10.0,0.0 }, { 0.0,2.0,0.0 }, 6, 35, 0.5);
	partSys->addGenerator(gaus);
	AddEntity(partSys);
}

SceneP2_GEN1::~SceneP2_GEN1()
{
}
