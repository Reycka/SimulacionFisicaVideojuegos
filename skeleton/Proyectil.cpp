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

Proyectil::Proyectil(Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, double _masaReal, Vector3 _vReal,Vector3 _g ,double _damp) : Entity(pos,shape,color,_v,_masa,_tVida,_g,_damp,_masaReal,_vReal)
{

}

Proyectil::~Proyectil()
{
}

void Proyectil::integrate(double t)
{
	tVida -= t;
	//ClearOldForces
	force = Vector3({ 0.0,0.0,0.0 });
	//AddNewForces
	addForces(t);

	vSim = (vSim + ((force/masaSim) * t));
	vSim = vSim * pow(damp, t);
	getT()->p = getT()->p + (vSim * t);

}
