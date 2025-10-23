#include "SceneP2_GEN2.h"

#include "ParticleSystem.h"
#include "GaussianGenerator.h"
#include "UniformGenerator.h"
using namespace physx;
//Esta escena contiene el generador de lluvia
SceneP2_GEN2::SceneP2_GEN2(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 rainColor = { 0.0f,0.0f,1.0f,0.8f };

	ParticleSystem* partSys = new ParticleSystem();
	UniformGenerator* unif = new UniformGenerator(80, { -20.0,60.0,-20.0 }, sphereShape, rainColor, { 0.0,-30.0,0.0 }, { 0.0,-30.0,0.0 }, 25, { 0.0,-1.0,0.0 }, 40, 0.2);
	partSys->addGenerator(unif);
	AddEntity(partSys);

}

SceneP2_GEN2::~SceneP2_GEN2()
{
}
