#include "GaussianGenerator.h"

GaussianGenerator::GaussianGenerator()
{
	part.resize(10);
}

GaussianGenerator::~GaussianGenerator()
{
	for (auto particle : part) {
		if (particle.second == true ) {
			particle.first->DeRegItem();
		}
	}
}

void GaussianGenerator::addParticles()
{
	//pos, shape, color, v, a, _tVida, damp
	for (auto& particle : part) {
		if (particle.second == false) {
			particle.first = new Particle({ model->getT()->p.x,model->getT()->p.y,model->getT()->p.z }, model->getShape(), model->getRenderItem()->color, model->getV(), model->getA(), model->getTvida(), model->getDamp());
			particle.second = true;
		}
	}
}

void GaussianGenerator::removeParticles()
{
	for (auto& pa : part) {
		if (pa.first->getTvida() <= 0) {
			pa.first->DeRegItem();
			pa.second = false;
		}
		else if (pa.first->getT()->p.x < limitPos.x || pa.first->getT()->p.y < limitPos.y || pa.first->getT()->p.z < limitPos.z) {
			pa.first->DeRegItem();
			pa.second = false;
		}
	}
}

void GaussianGenerator::integrate(double t)
{
	for (auto& particle : part) {
		if (particle.second == true) {
			particle.first->integrate(t);
		}
	}
}

void GaussianGenerator::setModel(Particle* _model)
{
	model = _model;
}
