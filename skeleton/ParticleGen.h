#pragma once
#include "Particle.h"
#include <list>
#include <random>
class ParticleGen
{
//DISTRIBUCION UNIFORME: double a = std::uniform_real_ditribution<double> -u{0,1}
// Posteriormente se hace POS * RADIO * a

//DISTRIBUCIÓN NORMAL: double a = std::normal_real_distribution<double> -d{0,1}
// Posteriormente se hace POS * RADIO * a

/*
CASO DE GENERADOR GAUSSIANO
desviacion de Posicion
desviacion de velocidad
desviacion de tiempo
x = xmediaDeLaDistribucion + d(-mt) * desviacion de P
*/

protected:
	Particle* model;
	std::vector<std::pair<Particle*,bool>>part;
	int limit = 5;
	double timeToSpawn;
	double timePass;
	Vector3 limitPos;
	std::mt19937 _mt;
	std::uniform_real_distribution<double> urd;
public:
	virtual ~ParticleGen() {};
	virtual void addParticles() = 0;
	virtual void RegParticles() = 0;
	virtual void DeRegParticles() = 0;
	virtual Particle* GeneraAleatoria() = 0;
	virtual void removeParticles() = 0;
	virtual void integrate(double t) = 0;
};

