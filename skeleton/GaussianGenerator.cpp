#include "GaussianGenerator.h"

GaussianGenerator::GaussianGenerator()
{

}

GaussianGenerator::~GaussianGenerator()
{
	for (auto particle : part) {
		if (particle != nullptr) {
			particle->DeRegItem();
		}
	}
}

void GaussianGenerator::addParticles(std::list<Particle*>& p)
{
	//pos, shape, color, v, a, _tVida, damp
	part.push_back(new Particle({ model->getT()->p.x,model->getT()->p.y,model->getT()->p.z }, model->getShape(), model->getRenderItem()->color, model->getV(), model->getA(), model->getTvida(), model->getDamp()));
	p.push_back(part.back());
}

void GaussianGenerator::removeParticles()
{
	for (auto pa : part) {
		if (pa->getTvida() <= 0) {
			pa->DeRegItem();
			pa = nullptr;
		}
		else if (pa->getT()->p.x < limitPos.x || pa->getT()->p.y < limitPos.y || pa->getT()->p.z < limitPos.z) {
			pa->DeRegItem();
			pa = nullptr;
		}
	}
}

void GaussianGenerator::setModel(Particle* _model)
{
	model = _model;
}
