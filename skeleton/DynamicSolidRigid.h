#pragma once
#include "Entity.h"
class DynamicSolidRigid : public Entity
{
private:
	physx::PxMaterial* material;
	physx::PxRigidDynamic* obj;
public:
	DynamicSolidRigid(physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution,physx::PxPhysics* gPhysx,physx::PxGeometry geom,Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, double _damp = 0.999);
	~DynamicSolidRigid();
	void integrate(double t) override;
	void RegItem() override;
	void DeRegItem() override;
	physx::PxRigidDynamic* getObj();
};

