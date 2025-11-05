#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "ParticleSystem.h"
#include "GaussianGenerator.h"
class nave : public Entity ,public Enemy
{
private:
	Vector3 finalPos;
	ParticleSystem* partShipSystem;
	GaussianGenerator* smokeGenerator;
	GaussianGenerator* fireGenerator;
public:
	nave(Vector3 _finalPos,Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, double _damp = 0.999, int health = 2, int points = 100, double timeToSpawn = 2.0);
	~nave();
	virtual void integrate(double t) override;
	virtual void RegItem() override;
	virtual void DeRegItem() override;
};

