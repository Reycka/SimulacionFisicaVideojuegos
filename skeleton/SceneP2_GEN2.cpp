#include "SceneP2_GEN2.h"

#include "ParticleSystem.h"
#include "GravityGenerator.h"
#include "WindGenerator.h"
#include "WhirlwindGenerator.h"
#include "UniformGenerator.h"
using namespace physx;
//Esta escena contiene el generador de lluvia
SceneP2_GEN2::SceneP2_GEN2(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 rainColor = { 0.0f,0.0f,1.0f,0.8f };

	ParticleSystem* partSys = new ParticleSystem();
	UniformGenerator* unif = new UniformGenerator(80, { -20.0,60.0,-20.0 }, sphereShape, rainColor, { 0.0,-60.0,0.0 }, 25, 40, 0.2);
	GravityGenerator* grav = new GravityGenerator({ 0.0,-10.0,0.0 });
	//WindGenerator* wind = new WindGenerator({ 0.0,0.0,0.0 }, 30.0f, {20.0,0.0,15.0}, 10);
	WhirlwindGenerator* whirlWind = new WhirlwindGenerator({ 0.0,0.0,0.0 }, 30.0f, 10);
	partSys->addGenerator(unif);
	partSys->addForceGenerator(grav);
	partSys->addForceGenerator(whirlWind);
	AddEntity(partSys);
	AddForceGenerator(grav);
	AddForceGenerator(whirlWind);
}

SceneP2_GEN2::~SceneP2_GEN2()
{
}
