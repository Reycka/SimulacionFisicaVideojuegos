#pragma once
#include <vector>
#include "Particle.h"
#include "dockForceGenerator.h"
class Scene;
class Slinky
{
private:
	int SLINKY_TAM;
	std::vector<Particle*> slinkyParticles;
	std::vector<Vector4> slinkyColors;
	float K;
	float l_o;
	Vector3 lPos;
	void setColors();
	void createParticles(Scene& sceneReference,physx::PxShape* shape);
public:
	Slinky(Scene& Scenereference,float _K, float l_o,int tam = 10, Vector3 limitPos = Vector3(FLT_MAX, FLT_MAX, FLT_MAX));
	~Slinky();
	void addForceGen(ForceGenerator* f);
};

