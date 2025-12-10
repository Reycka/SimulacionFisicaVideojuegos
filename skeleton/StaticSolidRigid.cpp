#include "StaticSolidRigid.h"
#include "RenderUtils.hpp"
using namespace physx;
StaticSolidRigid::StaticSolidRigid(PxReal coefStatic, PxReal dynamStatic, PxReal restitution, PxPhysics* gPhysx, const PxGeometry& geom, Vector3 pos, const Vector4& color, Vector3 _v,
	double _masa, double vol, double _tVida, double _damp) : Entity(pos,_v, _masa, vol, _tVida, _damp)
{
	material = gPhysx->createMaterial(coefStatic, dynamStatic, restitution);
	PxShape* sh = CreateShape(PxBoxGeometry(1,1,1), material);
	setShape(sh,color);
	volumeSetter(geom);
	obj = gPhysx->createRigidStatic(*getT());
	obj->attachShape(*getShape());
	setRenderItem(obj);
}

StaticSolidRigid::~StaticSolidRigid()
{
}

void StaticSolidRigid::RegItem()
{
	getObj()->getScene()->addActor(*getObj());
}

void StaticSolidRigid::DeRegItem()
{
	getObj()->getScene()->removeActor(*getObj());
}

void StaticSolidRigid::volumeSetter(const physx::PxGeometry& geom)
{
	const PxSphereGeometry& sphere = static_cast<const PxSphereGeometry&>(geom);
	const PxBoxGeometry& box = static_cast<const PxBoxGeometry&>(geom);
	switch (geom.getType()) {
	case (PxGeometryType::eSPHERE):

		volSim = (4.0f / 3.0f) * PxPi * pow(sphere.radius, 3);
		break;

	case (PxGeometryType::eBOX):
		volSim = 8.0f * box.halfExtents.x * box.halfExtents.y * box.halfExtents.z;
		break;
	default:
		volSim = 0;
		break;
	}
}
void StaticSolidRigid::setObj(PxRigidStatic* st)
{
	obj = st;
}
physx::PxRigidStatic* StaticSolidRigid::getObj() const
{
	return obj;
}
