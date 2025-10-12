#include "GaussianGenerator.h"

GaussianGenerator::GaussianGenerator()
{
}

GaussianGenerator::~GaussianGenerator()
{
}

void GaussianGenerator::addParticles(std::list<Particle*> p)
{
	part.push_back(model);
	p.push_back(part.back());
}

void GaussianGenerator::removeParticles()
{
	for (auto pa : part) {
		if (pa->getTvida() <= 0) {
			pa->DeRegItem();
		}
		else if (pa->getT()->p.x < limitPos.x || pa->getT()->p.y < limitPos.y || pa->getT()->p.z < limitPos.z) {
			pa->DeRegItem();
		}
	}
}
