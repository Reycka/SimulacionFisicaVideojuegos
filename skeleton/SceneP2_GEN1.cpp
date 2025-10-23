#include "SceneP2_GEN1.h"

#include "ParticleSystem.h"
#include "GaussianGenerator.h"
#include "UniformGenerator.h"
using namespace physx;
SceneP2_GEN1::SceneP2_GEN1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 gaussColor = { 1.0f,1.0f,0.0f,1.0f };
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };

	ParticleSystem* partSys = new ParticleSystem();
	GaussianGenerator* gaus = new GaussianGenerator({ 20.0,70.0,15.0 }, { 0.0,0.0,0.0 }, sphereShape, gaussColor, { 3.0,10.0,3.0 }, { 0.0,20.0,0.0 }, 6, {0.0,-1.0,0.0}, 35, 0.1);
	partSys->addGenerator(gaus);
	UniformGenerator* unif = new UniformGenerator({ 20.0,70.0,15.0 }, { 10.0,0.0,0.0 }, sphereShape, sphereColor, { 3.0,10.0,3.0 }, { 20.0,20.0,20.0 }, 6, { 0.0,-4.0,0.0 }, 20, 0.3);
	partSys->addGenerator(unif);
	AddEntity(partSys);

}

SceneP2_GEN1::~SceneP2_GEN1()
{
}
