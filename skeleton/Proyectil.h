#pragma once
#include "DynamicSolidRigid.h"
class Proyectil : public DynamicSolidRigid
{
private:
	void AjustaMasa();
	bool masaAjustada = false;
public:
	Proyectil();
	Proyectil(physx::PxScene* context, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom, Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, double _masa, double _vol, double _tVida,double _masaReal = 20, Vector3 _vReal = {3.0,2.0,3.0}, double _damp = 0.999);
	~Proyectil();
	virtual void integrate(double t) override;
	virtual void onCollision(Entity* other) override;
};

