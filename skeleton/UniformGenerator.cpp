#include "UniformGenerator.h"
#include <iostream>
UniformGenerator::UniformGenerator(float rad, Vector3 pos, physx::PxShape* shape, Vector4 color, Vector3 v, double _tVida, Vector3 g, int l, double _timeToSpwan, double damp)
{
	//Atributos del generador
	radius = rad;
	limitPos.x = rad;
	limitPos.y = rad;
	limitPos.z = rad;
	timeToSpawn = _timeToSpwan;
	timePass = timeToSpawn;
	limit = l;

	//Part�cula modelo
	model = new Particle(pos, shape, color, v, _tVida, g, damp);
	model->DeRegItem();

	//Aleatorio
	std::random_device rand;
	_mt = std::mt19937(rand());
}

UniformGenerator::~UniformGenerator()
{
	for (auto particle : part) {
		if (particle.second) {
			particle.first->DeRegItem();
		}
	}
}

void UniformGenerator::addForceGen(ForceGenerator g)
{
	FGen.push_back(g);
}

void UniformGenerator::activeForceGen(ForceGenerator gen)
{
	for (auto g : FGen) {
		if (g == &gen)g.setIsActive(true);
	}
}

void UniformGenerator::DesactiveForceGen(ForceGenerator gen)
{
	for (auto g : FGen) {
		if (g == &gen)g.setIsActive(false);
	}
}

Particle* UniformGenerator::GeneraAleatoria()
{
	//Seteo aleatorio de la posici�n inicial
	int aleX = std::rand() % (int)radius / 2 + 1;
	int aleY = std::rand() % (int)radius / 2 + 1;
	int aleZ = std::rand() % (int)radius / 2 + 1;
	Vector3 pos = Vector3(model->getT()->p.x + aleX, model->getT()->p.y + aleY, model->getT()->p.z + aleZ);

	//Seteo de la forma y el renderItem
	physx::PxShape* sh = model->getShape();
	RenderItem* rend = model->getRenderItem();

	//Creaci�n de las variables random
	//Para el color
	std::uniform_real_distribution<float> c(0.4f, 0.8f);
	double colorVariation = c(_mt);


	//Para la vida
	std::uniform_real_distribution<float> life(-10.0f, 10.0f);

	//Para la velocidad
	std::uniform_real_distribution<double> d(-2.0f, 2.0f);
	double velVariationX = d(_mt);
	double velVariationY = d(_mt);
	double velVariationZ = d(_mt);

	//Asgnaci�n del color
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


	//Asignaci�n de la velocidad
	Vector3 v = model->getV();
	v.x = v.x + (v.x * velVariationX);
	v.y = v.y + (v.y * velVariationY);
	v.z = v.z + (v.z * velVariationZ);



	//Asignaci�n de la vida
	double lifeVariation = life(_mt);
	double vida = model->getTvida() + lifeVariation;

	//Asignacion de damping
	double damping = model->getDamp();

	//Creaci�n y devoluci�n de la part�cula
	Particle* p = new Particle(pos, sh, color, v, vida, model->getG(), damping);
	for (auto g : FGen) {
		p->addForceGenerator(g);
	}
	return p;
}

void UniformGenerator::RegParticles()
{
	for (auto& pa : part) {
		if (pa.second) {
			pa.first->RegItem();
		}
	}
}

void UniformGenerator::DeRegParticles()
{
	for (auto& pa : part) {
		if (pa.second) {
			pa.first->DeRegItem();
		}
	}
}

void UniformGenerator::addParticles()
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

void UniformGenerator::removeParticles()
{
	for (auto& pa : part) {
		if (pa.first->getTvida() <= 0 && pa.second == true) {
			;
			pa.first->DeRegItem();
			pa.second = false;
		}
		else if (pa.second == true && std::abs(pa.first->getT()->p.x) > limitPos.x || pa.second == true && std::abs(pa.first->getT()->p.y) > limitPos.y || pa.second == true && std::abs(pa.first->getT()->p.z) > limitPos.z) {
			pa.first->DeRegItem();
			pa.second = false;
		}
	}
}

void UniformGenerator::integrate(double t)
{
	for (auto& particle : part) {
		if (particle.second) {
			particle.first->integrate(t);
		}
	}
	timePass += t;
}

void UniformGenerator::setVariation(int RGBAttribute, bool show)
{
	for (int i = 0; i < colorVariations.size(); ++i) {
		if (i == RGBAttribute) colorVariations[i] = show;
	}
}

