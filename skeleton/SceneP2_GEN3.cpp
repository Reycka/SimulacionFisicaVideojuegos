#include "SceneP2_GEN3.h"

#include "ParticleSystem.h"
#include "GaussianGenerator.h"
#include "UniformGenerator.h"
using namespace physx;
//Esta escena contiene el generador de fuego
SceneP2_GEN3::SceneP2_GEN3(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 color = { 1.0f,1.0f,0.0f,1.0f };

	ParticleSystem* partSys = new ParticleSystem();
	GaussianGenerator* gaus = new GaussianGenerator(20, { 0.0,-3.0,0.0 }, sphereShape, color, { 1.0,4.0,1.0 }, 12, { 0.0,0.0,0.0 }, 22, 0.2);
	partSys->addGenerator(gaus);
	gaus->setVariation(0, false);
	AddEntity(partSys);

}

SceneP2_GEN3::~SceneP2_GEN3()
{
}
