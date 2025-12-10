#pragma once
#include "Entity.h"
class StaticSolidRigid : public Entity
{
private:
	physx::PxMaterial* material;
	physx::PxRigidStatic* obj;
public:
	StaticSolidRigid(physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom, Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, double _damp = 0.999);
	~StaticSolidRigid();
	void RegItem() override;
	void DeRegItem() override;
	void volumeSetter(const physx::PxGeometry& geom);
	physx::PxRigidStatic* getObj() const;
};

