#include "Particle.h"
#include <math.h>
#include <iostream>

using namespace physx;
Particle::Particle() : Entity()
{

	 vSim = Vector3{ 0,10,0 };
	 damp = 0.999;
	 tVida = 3;
	 masaSim = 5;
	 firstComprobation = true;
	 lastPos = { 0.0,0.0,0.0 };

}

Particle::Particle(Vector3 pos, PxShape* shape, const Vector4& color, Vector3 _v, double _tVida, Vector3 g, double _damp,double masaSim) : Entity(pos,shape,color,_v,masaSim,_tVida,g,_damp)
{
	
}


void Particle::integrate(double t) 
{
	tVida -= t;
	//ClearOldForces
	force = Vector3({ 0.0,0.0,0.0 });
	//AddNewForces
	addForces(t);

	if (firstComprobation || (force/masaSim) == Vector3({0.0,0.0,0.0})) {
		//Euler
		vSim = (vSim + ((force * pow(masaSim,-1)) * t));
		vSim = vSim * pow(damp,t);
		getT()->p = getT()->p + (vSim * t);
		lastPos = getT()->p;
		firstComprobation = false;
	}

	else {
		//Verlet
		Vector3 newPosition = getT()->p * 2.0 - lastPos + ((force / masaSim) * t * t);
		newPosition = getT()->p + (newPosition - getT()->p) * pow(damp,t);
		lastPos = getT()->p;
		getT()->p = newPosition;
		vSim = (getT()->p - lastPos) / (2.0 * t);
		
	}
	
}
