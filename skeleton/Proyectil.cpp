#include "Proyectil.h"

void Proyectil::AjustaMasa()
{
	Vector3 aux = { vReal.x / vSim.x, vReal.y / vSim.y, vReal.z / vSim.z };
	aux.x *= aux.x;
	aux.y *= aux.y;
	aux.z *= aux.z;
	masaSim = masaReal * aux.magnitude();
}

Proyectil::Proyectil()
{
}

Proyectil::Proyectil(Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _masaReal, Vector3 _vReal,Vector3 _g ,double _damp) : Entity(pos,shape,color,_v,_a,_masa,_tVida,_g,_damp,_masaReal,_vReal)
{
	a += g;
}

Proyectil::~Proyectil()
{
}

void Proyectil::integrate(double t)
{
	Entity::integrate(t);

//	if (firstComprobation || a == Vector3({ 0.0,0.0,0.0 })) {
		//Euler
		vSim = (vSim + (a * t));
		vSim = vSim * pow(damp, t);
		getT()->p = getT()->p + (vSim * t);
		lastPos = getT()->p;
		firstComprobation = false;
	//}
		/*
	else {
		//Verlet
		
		Vector3 newPosition = getT()->p * 2.0 - lastPos + (a * t * t);
		newPosition = getT()->p + (newPosition - getT()->p) * pow(damp, t);
		lastPos = getT()->p;
		getT()->p = newPosition;
		vSim = (getT()->p - lastPos) / (2.0 * t);
	}*/
}
