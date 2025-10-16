#include "GaussianGenerator.h"

GaussianGenerator::GaussianGenerator(Vector3 pos, physx::PxShape* shape, Vector4 color, Vector3 v, Vector3 a, double _tVida, double damp,int l)
{
	limit = l;
	model = new Particle(pos,shape,color,v,a,_tVida,damp);
	model->DeRegItem();
}

GaussianGenerator::~GaussianGenerator()
{
	for (auto particle : part) {
		particle->DeRegItem();
	}
}

Particle* GaussianGenerator::GeneraAleatoria()
{
	int aleX = std::rand() % 20 + 1;
	int aleY = std::rand() % 10 + 1;
	int aleZ = std::rand() % 5 + 1;
	Vector3 pos = Vector3(model->getT()->p.x + aleX, model->getT()->p.y + aleY, model->getT()->p.z + aleZ);


	physx::PxShape* sh = model->getShape();
	RenderItem* rend = model->getRenderItem();

	Vector4 color = rend->color;
	Vector3 v = model->getV();
	Vector3 a = model->getA();
	double vida = 0.5;
	double damping = 0.999;

	Particle* p = new Particle(pos,sh,color,v,a,vida,damping);

	return p;
}

void GaussianGenerator::RegParticles()
{
	for (auto& pa : part) {
		pa->RegItem();
	}
}

void GaussianGenerator::DeRegParticles()
{
	for (auto& pa : part) {
		pa->DeRegItem();
	}
}

void GaussianGenerator::addParticles()
{
	//pos, shape, color, v, a, _tVida, damp
	while (partGen < limit) {
		if (part.size() < limit) {
			part.push_back(GeneraAleatoria());
		}
		else {
			part[partGen] = GeneraAleatoria();
		}
		partGen++;
	}
}

void GaussianGenerator::removeParticles()
{
	for (auto& pa : part) {
		if (pa->getTvida() <= 0) {;
			pa->DeRegItem();
			partGen--;
		}
		else if (pa->getT()->p.x < limitPos.x || pa->getT()->p.y < limitPos.y || pa->getT()->p.z < limitPos.z) {
			pa->DeRegItem();
			partGen--;
		}
	}
}

void GaussianGenerator::integrate(double t)
{
	for (auto& particle : part) {
		particle->integrate(t);		
	}
}
