#include "StaticSolidRigid.h"
using namespace physx;
StaticSolidRigid::StaticSolidRigid(PxReal coefStatic, PxReal dynamStatic, PxReal restitution, PxPhysics* gPhysx, PxGeometry geom, Vector3 pos, const Vector4& color, Vector3 _v,
	double _masa, double vol, double _tVida, double _damp) : Entity(pos, nullptr, color, _v, _masa, vol, _tVida, _damp)
{
	material = gPhysx->createMaterial(coefStatic, dynamStatic, restitution);
	PxShape* sh = gPhysx->createShape(geom, *material);
	setShape(sh);
	obj = gPhysx->createRigidDynamic(*getT());
	obj->attachShape(*getShape());
	PxRigidBodyExt::updateMassAndInertia(*obj, (PxReal)getMasa());
	setRenderItem(obj);
}

StaticSolidRigid::~StaticSolidRigid()
{
}

void StaticSolidRigid::RegItem()
{
}

void StaticSolidRigid::DeRegItem()
{
}
