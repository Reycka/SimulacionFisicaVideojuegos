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
private:
	Particle* model;
	std::list<Particle*>p;
	Vector4 color;
	Vector3 limitPos;
	std::mt19937 _mt;
	std::uniform_real_distribution<double> urd;

public:
	virtual void addParticles() = 0;
	virtual void removeParticles() = 0;
	inline void setModel(Particle* _model) { model = _model; };
};

