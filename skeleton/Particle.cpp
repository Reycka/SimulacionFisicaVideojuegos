#include "Particle.h"
using namespace physx;
Particle::Particle() : Entity()
{

	 vSim = Vector3{ 0,10,0 };
	 a = Vector3{ 0,-9.8,0 };
	 damp = 0.999;
	 tVida = 3;
	 masaSim = 5;
	 firstComprobation = true;
	 lastPos = { 0.0,0.0,0.0 };

}

Particle::Particle(Vector3 pos, PxShape* shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _damp) : Entity(pos,shape,color,_v,_a,_masa,_tVida,_damp)
{

}

Particle::~Particle()
{

}

void Particle::integrate(double t)
{
	if (firstComprobation || a == Vector3({0.0,0.0,0.0})) {
		//Euler
		vSim = (vSim + (a * t));
		vSim = vSim * pow(damp,t);
		getT()->p = getT()->p + (vSim * t);
		lastPos = getT()->p;
		firstComprobation = false;
	}

	else {
		//Verlet
		Vector3 newPosition = getT()->p * 2.0 - lastPos + (a * t * t);
		newPosition = getT()->p + (newPosition - getT()->p) * pow(damp,t);
		lastPos = getT()->p;
		getT()->p = newPosition;
		vSim = (getT()->p - lastPos) / (2.0 * t);
	}
}
