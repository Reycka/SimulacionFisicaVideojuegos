#include "SceneP4.h"
#include <iostream>
#include "Particle.h"
#include "GravityGenerator.h"
#include "RubberyForceGenerator.h"
using namespace physx;
//Esta escena contiene el generador de fuego
SceneP4::SceneP4(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial, _phy, _gScene, _cam)
{
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), getMaterial());
	Vector4 color = { 1.0f,1.0f,0.0f,1.0f };
	Particle* origen = new Particle(Vector3(0, 0, 0), sphereShape, color, Vector3(0.0, 0.0, 0.0), 10,0.999,10);
	Particle* destino = new Particle(Vector3(0, -1, 0), sphereShape, color, Vector3(0.0, 0.0, 0.0), 10,0.90,1.0);
	Particle* destino2 = new Particle(Vector3(0, -5, 0), sphereShape, color, Vector3(0.0, 0.0, 0.0), 10, 0.90, 1.0);
	float K = 3;
	float l_o = 30;
	dockGen = new dockForceGenerator(origen,destino,K,l_o);

	//dockForceGenerator* dockGen2 = new dockForceGenerator(destino, destino2, K, l_o,Vector3({200.0,200.0,200.0})); //Esta particula se le rompe el muelle	
	RubberyForceGenerator* dockGen2 = new RubberyForceGenerator(destino, destino2, K, l_o, Vector3({ 50.0,50.0,50.0 })); //Goma Elástica

	GravityGenerator* grav = new GravityGenerator(Vector3({0.0,-9.8,0.0}));
	windGen = new WindGenerator({ 0.0,0.0,0.0 }, 30.0f, { 20.0,0.0,15.0 }, 10);
	windGen->setIsActive(false);
	AddForceGenerator(dockGen);
	AddForceGenerator(grav);
	AddForceGenerator(windGen);
	AddForceGenerator(dockGen2);
	AddEntity(origen);
	AddEntity(destino);
	AddEntity(destino2);
	destino->addForceGenerator(dockGen);
	destino->addForceGenerator(grav);
	destino->addForceGenerator(windGen);
	destino2->addForceGenerator(dockGen2);
	destino2->addForceGenerator(grav);
	destino2->addForceGenerator(windGen);

}

SceneP4::~SceneP4()
{
}

void SceneP4::keyPress(unsigned char key)
{
	switch (key) {
	case 'c':
		windGen->setIsActive(!windGen->getIsActive());
		break;
	case 'v':
		//ERROR EN LA SIMULACION: SI LA CONSOLA POPEA PARA PREGUNTAR LA SIMULACIÓN SE ROMPE
		float newK = 10.0;
		/*std::cout << "Seleccione una K distinta para el muelle" << "\n";
		std::cin >> newK;*/
		dockGen->setNewK(newK);
		break;
	}
}
