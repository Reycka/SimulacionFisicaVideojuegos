#include "Particle.h"
using namespace physx;
Particle::Particle() : Entity()
{

	 v = Vector3{ 0,10,0 };
	 a = Vector3{ 0,-9.8,0 };
	 damp = 0.999;
	 tVida = 3;
	 masa = 5;
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
		v = (v + (a * t));
		v = v * pow(damp,t);
		getT()->p = getT()->p + (v * t);
		lastPos = getT()->p;
		firstComprobation = false;
	}

	else {
		//Verlet
		Vector3 newPosition = getT()->p * 2.0 - lastPos + (a * t * t);
		newPosition = getT()->p + (newPosition - getT()->p) * pow(damp,t);
		lastPos = getT()->p;
		getT()->p = newPosition;
		v = (getT()->p - lastPos) / (2.0 * t);
	}
}
