#include "SceneP2_GEN1.h"
#include "GravityGenerator.h"
#include "ParticleSystem.h"
#include "GaussianGenerator.h"

using namespace physx;
//Esta escena contiene el generador de niebla
SceneP2_GEN1::SceneP2_GEN1(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 color = { 0.5f,0.5f,0.5f,1.0f };
	Vector4 sphereColor = { 1.0f,0.0f,1.0f,1.0f };

	ParticleSystem* partSys = new ParticleSystem();
	GaussianGenerator* gaus = new GaussianGenerator(90, { 0.0,0.0,0.0 }, sphereShape, color, { 3.0,10.0,3.0 },20, {0.0,-1.0,0.0}, 85, 0.5);
	GravityGenerator* gravityGen = new GravityGenerator({ 0.0,-10.0,0.0 });
	partSys->addGenerator(gaus);
	partSys->addForceGenerator(gravityGen);
	AddEntity(partSys);
	AddForceGenerator(gravityGen);

}

SceneP2_GEN1::~SceneP2_GEN1()
{
}
