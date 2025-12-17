#include "DynamicSolidRigid.h"
#include <iostream>
#include "RenderUtils.hpp"
using namespace physx;
DynamicSolidRigid::DynamicSolidRigid(physx::PxScene* context,PxReal coefStatic,PxReal dynamStatic, PxReal restitution,PxPhysics* gPhysx,const PxGeometry& geom,Vector3 pos, const Vector4& color, Vector3 _v,
	double _masa, double vol, double _tVida, double _damp) : Entity(pos,_v,_masa,vol,_tVida,_damp)
{
	mContext = context;
	phy = gPhysx;
	geometry = geom;
	material = gPhysx->createMaterial(coefStatic,dynamStatic,restitution);
	PxShape* sh = CreateShape(geom,material);
	setShape(sh,color);
	volumeSetter(geometry);
	obj = gPhysx->createRigidDynamic(*getT());
	obj->attachShape(*getShape());
	PxRigidBodyExt::updateMassAndInertia(*obj, getMasa());
	setRenderItem(obj);
	mContext->addActor(*obj);
	obj->userData = this; //PARA LOS CALLBACKS, SE TRATA COMO EL IDENTIFICADOR DEL DYNAMIC OBJECT EN CUESTIÓN
}

DynamicSolidRigid::~DynamicSolidRigid()
{
	
}

void DynamicSolidRigid::integrate(double t)
{
	tVida -= t;
	//ClearOldForces
	force = Vector3({ 0.0,0.0,0.0 });
	//AddNewForces
	addForces(t);
	obj->addForce(force);
}

void DynamicSolidRigid::RegItem()
{
	if (obj->getScene() == NULL) {
		Entity::RegItem();
		mContext->addActor(*obj);
	}
}

void DynamicSolidRigid::DeRegItem()
{
	Entity::DeRegItem();
	mContext->removeActor(*obj);
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

physx::PxScene* DynamicSolidRigid::getContext()
{
	return mContext;
}

physx::PxRigidDynamic* DynamicSolidRigid::getObj()
{
	return obj;
}
