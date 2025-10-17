#include "GaussianGenerator.h"
#include <iostream>
GaussianGenerator::GaussianGenerator(Vector3 _limitPos,Vector3 pos, physx::PxShape* shape, Vector4 color, Vector3 v, Vector3 a,double _tVida, Vector3 g,int l, double _timeToSpwan, double damp)
{
	//Atributos del generador
	limitPos = _limitPos;
	timeToSpawn = _timeToSpwan;
	timePass = timeToSpawn;
	limit = l;

	//Partícula modelo
	model = new Particle(pos,shape,color,v,a,_tVida,g,damp);
	model->DeRegItem();

	//Aleatorio
	std::random_device rand;
	_mt = std::mt19937(rand());

}

GaussianGenerator::~GaussianGenerator()
{
	for (auto particle : part) {
		if (particle.second) {
			particle.first->DeRegItem();
		}
	}
}

Particle* GaussianGenerator::GeneraAleatoria()
{
	//Seteo aleatorio de la posición inicial
	int aleX = std::rand() % 5 + 1;
	int aleY = std::rand() % 2 + 1;
	int aleZ = std::rand() % 5 + 1;
	Vector3 pos = Vector3(model->getT()->p.x + aleX, model->getT()->p.y + aleY, model->getT()->p.z + aleZ);

	//Seteo de la forma y el renderItem
	physx::PxShape* sh = model->getShape();
	RenderItem* rend = model->getRenderItem();

	//Creación de las variables random
	//Para el color
	std::uniform_real_distribution<float> c(0.4f, 1.0f);
	double colorVariation = c(_mt);

	//Para la velocidad
	std::normal_distribution<double> d(-5, 5);
	double velVariationX = d(_mt);
	double velVariationY = d(_mt);
	double velVariationZ = d(_mt);


	//Asgnación del color
	Vector4 color = rend->color;
	if (color.x > 0.0) {
		color.x = colorVariation;
	}
	if (color.y > 0.0) {
		color.y = colorVariation;
	}
	if (color.z > 0.0) {
		color.z = colorVariation;
	}


	//Asignación de la velocidad
	Vector3 v = model->getV();
	v.x = v.x + (v.x * velVariationX);
	v.y = v.y + (v.y * velVariationY);
	v.z = v.z + (v.z * velVariationZ);

	//Asignación de aceleración
	Vector3 a = model->getA();

	//Asignación de la vida
	double lifeVariation = d(_mt);
	double vida = model->getTvida() + lifeVariation;

	//Asignacion de damping
	double damping = model->getDamp();

	//Creación y devolución de la partícula
	Particle* p = new Particle(pos,sh,color,v,a, vida, model->getG(), damping);
	return p;
}

void GaussianGenerator::RegParticles()
{
	for (auto& pa : part) {
		if (pa.second) {
			pa.first->RegItem();
		}
	}
}

void GaussianGenerator::DeRegParticles()
{
	for (auto& pa : part) {
		if (pa.second) {
			pa.first->DeRegItem();
		}
	}
}

void GaussianGenerator::addParticles()
{
	//pos, shape, color, v, a, _tVida, damp
	if (timePass >= timeToSpawn) {
		int i = 0;
		while (i < limit) {
			part.push_back({ GeneraAleatoria(),true });
			i++;
		}
		timePass = 0;
	}

}

void GaussianGenerator::removeParticles()
{
	for (auto& pa : part) {
		if (pa.first->getTvida() <= 0 && pa.second == true) {;
			pa.first->DeRegItem();
			pa.second = false;
		}
	/*	else if (pa.second == true && pa.first->getT()->p.x < limitPos.x || pa.second == true && pa.first->getT()->p.y < limitPos.y || pa.second == true && pa.first->getT()->p.z < limitPos.z) {
			pa.first->DeRegItem();
			pa.second = false;
		}*/
	}
}

void GaussianGenerator::integrate(double t)
{
	for (auto& particle : part) {
		if (particle.second) {
			particle.first->integrate(t);
		}	
	}
	timePass += t;
}
