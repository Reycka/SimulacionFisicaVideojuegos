#include "GaussianGenerator.h"
#include <iostream>
GaussianGenerator::GaussianGenerator(Vector3 _limitPos,Vector3 pos, physx::PxShape* shape, Vector4 color, Vector3 v, Vector3 a, double _tVida,int l, double _timeToSpwan, double damp)
{
	limitPos = _limitPos;
	timeToSpawn = _timeToSpwan;
	timePass = timeToSpawn;
	limit = l;
	model = new Particle(pos,shape,color,v,a,_tVida,damp);
	model->DeRegItem();
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
	int aleX = std::rand() % 10 + 1;
	int aleY = std::rand() % 10 + 1;
	int aleZ = std::rand() % 5 + 1;
	Vector3 pos = Vector3(model->getT()->p.x + aleX, model->getT()->p.y + aleY, model->getT()->p.z + aleZ);


	physx::PxShape* sh = model->getShape();
	RenderItem* rend = model->getRenderItem();

	Vector4 color = rend->color;
	Vector3 v = model->getV();
	Vector3 a = model->getA();
	double vida = model->getTvida();
	double damping = 0.999;

	Particle* p = new Particle(pos,sh,color,v,a,vida,damping);

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
		else if (pa.second == true && pa.first->getT()->p.x < limitPos.x || pa.second == true && pa.first->getT()->p.y < limitPos.y || pa.second == true && pa.first->getT()->p.z < limitPos.z) {
			pa.first->DeRegItem();
			pa.second = false;
		}
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
