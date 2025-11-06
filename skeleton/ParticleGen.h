#pragma once
#include "Particle.h"
#include <random>
#include "ForceGenerator.h"
class ParticleGen
{


protected:
	bool isActive = true;
	std::vector<ForceGenerator*> FGen;
	std::vector<bool> colorVariations{true,true,true}; //Que colores queremos cambiar
	Particle* model;
	double radius;
	std::vector<std::pair<Particle*,bool>>part;
	int limit = 5;
	double timeToSpawn;
	double timePass;
	Vector3 limitPos;
	std::mt19937 _mt;
	std::uniform_real_distribution<double> urd;
public:
	virtual ~ParticleGen() {};
	virtual void setPosition(Vector3 pos) = 0;
	virtual bool getIsActive() = 0;
	virtual void setIsActive(bool active) = 0;
	virtual void addForceGen(ForceGenerator* g) = 0;
	virtual void addParticles() = 0;
	virtual void RegParticles() = 0;
	virtual void DeRegParticles() = 0;
	virtual Particle* GeneraAleatoria() = 0;
	virtual void removeParticles() = 0;
	virtual void integrate(double t) = 0;
	virtual void setVariation(int RGBAttribute, bool show) = 0;
};

