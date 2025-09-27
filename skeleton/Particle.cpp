#include "Particle.h"
using namespace physx;
Particle::Particle() : Entity()
{

	 v = Vector3D{ 0,10,0 };
	 a = Vector3D{ 0,-9.8,0 };
	 damp = 0.999;
	 tVida = 3;
	 masa = 5;

}

Particle::Particle(Vector3D pos, PxShape* shape, const Vector4& color, Vector3D _v, Vector3D _a, double _masa, double _tVida, double _damp) : Entity(pos,shape,color)
{
	v = _v;
	a = _a;
	masa = _masa;
	tVida = _tVida;
	damp = _damp;

}

Particle::~Particle()
{

}

void Particle::integrate(double t)
{
	v = (v + (a.MultEscalar(t)));
	getT()->p = getT()->p + (v.changeClass() * t);
}
