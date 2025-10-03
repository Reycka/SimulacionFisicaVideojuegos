#include "Particle.h"
using namespace physx;
Particle::Particle() : Entity()
{

	 v = Vector3D{ 0,10,0 };
	 a = Vector3D{ 0,-9.8,0 };
	 damp = 0.999;
	 tVida = 3;
	 masa = 5;
	 firstComprobation = true;
	 lastPos = { 0.0,0.0,0.0 };

}

Particle::Particle(Vector3D pos, PxShape* shape, const Vector4& color, Vector3D _v, Vector3D _a, double _masa, double _tVida, double _damp) : Entity(pos,shape,color)
{
	v = _v;
	a = _a;
	masa = _masa;
	tVida = _tVida;
	damp = _damp;
	firstComprobation = true;
	lastPos = { 0.0,0.0,0.0 };

}

Particle::~Particle()
{

}

void Particle::integrate(double t)
{
	if (firstComprobation || a == Vector3D({0.0,0.0,0.0})) {
		//Euler
		v = (v + (a.MultEscalar(t)));
		v = v.MultEscalar(damp);
		getT()->p = getT()->p + (v.changeClass() * t);
		lastPos = getT()->p;
		firstComprobation = false;
	}

	else {
		//Verlet
		Vector3 newPosition = getT()->p * 2.0 - lastPos + (a.MultEscalar(t * t).changeClass());
		newPosition = getT()->p + (newPosition - getT()->p) * damp;
		lastPos = getT()->p;
		getT()->p = newPosition;
		v = (getT()->p - lastPos) / (2.0 * t);
	}
}
