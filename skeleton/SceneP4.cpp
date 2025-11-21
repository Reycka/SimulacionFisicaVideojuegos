#include "SceneP4.h"
#include "Particle.h"
#include "dockForceGenerator.h"
#include "GravityGenerator.h"
using namespace physx;
//Esta escena contiene el generador de fuego
SceneP4::SceneP4(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 color = { 1.0f,1.0f,0.0f,1.0f };
	Particle* origen = new Particle(Vector3(0, 0, 0), sphereShape, color, Vector3(0.0, 0.0, 0.0), 10,0.999,10);
	Particle* destino = new Particle(Vector3(0, -1, 0), sphereShape, color, Vector3(0.0, 0.0, 0.0), 10,0.90,1.0);
	float K = 3;
	float l_o = 3;
	dockForceGenerator* dockGen = new dockForceGenerator(origen,destino,K,l_o);
	GravityGenerator* grav = new GravityGenerator(Vector3({0.0,-9.8,0.0}));
	AddForceGenerator(dockGen);
	AddForceGenerator(grav);
	AddEntity(origen);
	AddEntity(destino);
	destino->addForceGenerator(dockGen);
	destino->addForceGenerator(grav);

}

SceneP4::~SceneP4()
{
}
