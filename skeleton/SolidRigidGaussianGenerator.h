#pragma once
#include "SolidRigidGenerator.h"
class SolidRigidGaussianGenerator : public SolidRigidGenerator
{
private:
	std::normal_distribution<double> nd;
public:
	SolidRigidGaussianGenerator(float rad,float _timeToSpawn,float l, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom, Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, double _damp = 0.999);
	virtual ~SolidRigidGaussianGenerator();
	virtual void setPosition(Vector3 pos) override;
	void setLimitPos(Vector3 pos);
	virtual bool getIsActive() override;
	virtual void setIsActive(bool active) override;
	virtual void addForceGen(ForceGenerator* g) override;
	virtual DynamicSolidRigid* GeneraAleatoria() override;
	virtual void RegSolidRigid() override;
	virtual void DeRegSolidRigid() override;
	virtual void addSolidRigid(physx::PxScene* context) override;
	virtual void removeSolidRigid() override;
	virtual void integrate(double t) override;
	virtual void setVariation(int RGBAttribute, bool show) override;
};

