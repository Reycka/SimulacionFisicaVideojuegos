#include "DynamicSolidRigid.h"
using namespace physx;
DynamicSolidRigid::DynamicSolidRigid(PxReal coefStatic,PxReal dynamStatic, PxReal restitution,PxPhysics* gPhysx, PxGeometry geom,Vector3 pos, const Vector4& color, Vector3 _v,
	double _masa, double vol, double _tVida, double _damp) : Entity(pos,_v,_masa,vol,_tVida,_damp)
{
	phy = gPhysx;
	geometry = geom;
	material = gPhysx->createMaterial(coefStatic,dynamStatic,restitution);
	PxShape* sh = gPhysx->createShape(geom,*material);
	setShape(sh,color);
	volumeSetter(geom);
	obj = gPhysx->createRigidDynamic(*getT());
	obj->attachShape(*getShape());
	PxRigidBodyExt::updateMassAndInertia(*obj, getMasa());
	setRenderItem(obj);
	RegItem();
}

DynamicSolidRigid::~DynamicSolidRigid()
{
}

void DynamicSolidRigid::integrate(double t)
{
	force = Vector3(0.0, 0.0, 0.0);
	addForces(t);
}

void DynamicSolidRigid::RegItem()
{
	getObj()->getScene()->addActor(*getObj());
}

void DynamicSolidRigid::DeRegItem()
{
	getObj()->getScene()->removeActor(*getObj());
}

void DynamicSolidRigid::volumeSetter(const physx::PxGeometry& geom)
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

physx::PxPhysics* DynamicSolidRigid::getPhy()
{
	return phy;
}

physx::PxGeometry DynamicSolidRigid::getGeom()
{
	return geometry;
}

physx::PxRigidDynamic* DynamicSolidRigid::getObj()
{
	return obj;
}
