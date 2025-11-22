#include "Slinky.h"
#include "Scene.h"
using namespace physx;
Slinky::Slinky(Scene& Scenereference, float _K, float _l_o,int tam, Vector3 limitPos)
{
	SLINKY_TAM = tam;
	K = _K;
	l_o = _l_o;
	lPos = limitPos;
	slinkyColors.resize(SLINKY_TAM);
	slinkyParticles.resize(SLINKY_TAM);
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), Scenereference.getMaterial());
	setColors();
	createParticles(Scenereference, sphereShape);
}

Slinky::~Slinky()
{
}

void Slinky::addForceGen(ForceGenerator* f)
{
	for (int i = 1; i < SLINKY_TAM; ++i) {
		slinkyParticles[i]->addForceGenerator(f);
	}
}

void Slinky::setColors()
{
	Vector4 color = Vector4({ 1.0,0.0,0.0,1.0 });
	for (int i = 0; i < SLINKY_TAM; ++i) {
		slinkyColors[i] = color;
		if (color.y < 1.0 && color.z == 0.0) {
			color.y += 0.5;
		}
		else if (color.x != 0.0 && color.y == 1.0 && color.z == 0.0) {
			color.x -= 0.5;
		}
		else if (color.x == 0.0 && color.z != 1.0) {
			color.z += 0.5;
		}
		else if (color.z == 1.0 && color.y > 0.0) {
			color.y -= 0.5;
		}
		else if (color.x != 1.0 && color.y == 0.0 && color.z != 0.0) {
			color.z -= 0.5;
			color.x += 0.5;
		}
	}
}

void Slinky::createParticles(Scene& sceneReference,PxShape* shape)
{
	slinkyParticles[0] = new Particle(Vector3(0.0, 0.0, 0.0), shape, slinkyColors[0], Vector3(0.0, 0.0, 0.0), 10);
	sceneReference.AddEntity(slinkyParticles[0]);
	for (int i = 1; i < SLINKY_TAM; ++i) {
		slinkyParticles[i] = new Particle(slinkyParticles[i-1]->getT()->p + Vector3(0.0,-1.0,0.0),shape,slinkyColors[i],Vector3(0.0,0.0,0.0),10);
		dockForceGenerator* slinkyDockGenerator = new dockForceGenerator(slinkyParticles[i-1],slinkyParticles[i],K,l_o,lPos);
		slinkyParticles[i]->addForceGenerator(slinkyDockGenerator);
		sceneReference.AddForceGenerator(slinkyDockGenerator);
		sceneReference.AddEntity(slinkyParticles[i]);
	}
}
