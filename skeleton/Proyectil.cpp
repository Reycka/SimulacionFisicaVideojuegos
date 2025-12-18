#include "Proyectil.h"

void Proyectil::AjustaMasa()
{
	Vector3 aux = { vReal.x / vSim.x, vReal.y / vSim.y, vReal.z / vSim.z };
	aux.x *= aux.x;
	aux.y *= aux.y;
	aux.z *= aux.z;
	masaSim = masaReal * aux.magnitude();
	masaAjustada = true;
}

Proyectil::Proyectil(physx::PxScene* context, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom,
	Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, double _masa,double _vol, double _tVida, double _masaReal, Vector3 _vReal ,double _damp)
	: DynamicSolidRigid(context, coefStatic, dynamStatic, restitution, gPhysx, geom,pos,color,_v,_masa,_vol,_tVida,_damp)
{
	if(!masaAjustada)AjustaMasa();
	type = Bala;
	getObj()->setActorFlag(physx::PxActorFlag::eDISABLE_GRAVITY, true);
}

Proyectil::~Proyectil()
{
}

/*void Proyectil::integrate(double t) Como es solidRigid no hace falta
{
	if (isActive) {
		tVida -= t;
		//ClearOldForces
		force = Vector3({ 0.0,0.0,0.0 });
		//AddNewForces
		addForces(t);

		vSim = (vSim + ((force / masaSim) * t));
		vSim = vSim * pow(damp, t);
		getT()->p = getT()->p + (vSim * t);
		if (tVida <= 0) {
			DeRegItem();
			isActive = false;
		}
	}
}*/

void Proyectil::onCollision(Entity* other)
{
	if (other->getEntType() == Nave) {
		isActive = false;
		Entity::DeRegItem();
	}
}
