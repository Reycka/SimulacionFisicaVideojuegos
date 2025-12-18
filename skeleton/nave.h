#pragma once
#include "DynamicSolidRigid.h"
#include "Enemy.h"
#include "ParticleSystem.h"
#include "GravityGenerator.h"
#include "GaussianGenerator.h"
#include "UniformGenerator.h"
#include "ExplosionGenerator.h"
#include "WindGenerator.h"
class nave : public DynamicSolidRigid ,public Enemy
{
private:

	std::list<Entity*> entities;
	Vector3 shootPoint;
	Vector3 initialPositon;
	Vector3 finalPos;

	ParticleSystem* partShipSystem;
	GaussianGenerator* smokeGenerator;
	UniformGenerator* fireGenerator;
	ExplosionGenerator* exp;
	GravityGenerator* g;
	WindGenerator* wind;

	//Creacion de los sistemas propios de la nave (las 2 partículas y la explosión)
	void createSmoke();
	void createFire();
	void createForces();

	void setState() override;
	void AIFunction() override;

public:
	nave(physx::PxScene* context, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom,
		Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, 
		ExplosionGenerator* exp = nullptr, physx::PxTransform cameraTransform = physx::PxTransform(),double _damp = 0.999,
		int health = 2, int points = 100, double timeToSpawn = 2.0);
	~nave();
	virtual void addForceGenerator(ForceGenerator* gen) override;
	virtual void integrate(double t) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
	void onCollision(Entity* other) override;
};

