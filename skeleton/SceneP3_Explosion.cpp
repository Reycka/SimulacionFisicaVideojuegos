#include "SceneP3_Explosion.h"
#include "ParticleSystem.h"
#include "GravityGenerator.h"
#include "ExplosionGenerator.h"
#include "GaussianGenerator.h"
#include "UniformGenerator.h"
using namespace physx;
SceneP3_Explosion::SceneP3_Explosion(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 rainColor = { 0.0f,0.0f,1.0f,0.8f };
	Vector4 fogColor = { 0.5f,0.5f,0.5f,1.0f };

	ParticleSystem* partSys = new ParticleSystem();
	UniformGenerator* unif = new UniformGenerator(80, { -20.0,60.0,-20.0 }, sphereShape, rainColor, { 0.0,-60.0,0.0 }, 25, { 0.0,-1.0,0.0 }, 40, 0.2);
	//GaussianGenerator* gaus = new GaussianGenerator(90, { 0.0,0.0,0.0 }, sphereShape, fogColor, { 3.0,10.0,3.0 }, 20, { 0.0,-1.0,0.0 }, 85, 0.5);
	GravityGenerator* grav = new GravityGenerator({ 0.0,-10.0,0.0 });
	exp = new ExplosionGenerator({0.0,0.0,0.0},40000.0f,20.0f,5000.0f);
	partSys->addGenerator(unif);
	//partSys->addGenerator(gaus);
	partSys->addForceGenerator(exp);
	partSys->addForceGenerator(grav);
	AddEntity(partSys);
	AddForceGenerator(grav);
	AddForceGenerator(exp);
}

SceneP3_Explosion::~SceneP3_Explosion()
{
}

void SceneP3_Explosion::keyPress(unsigned char key)
{
	switch (key) {
	case 'c':
		exp->setIsActive(true);
		break;
	case 'v':
		exp->setIsActive(false);
		break;
	}
}
