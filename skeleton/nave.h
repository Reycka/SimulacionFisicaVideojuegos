#pragma once
#include "CompoundEntity.h"
#include "Enemy.h"
class nave : public CompoundEntity ,public Enemy
{
private:
public:
	nave(Vector3 _finalPos,Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, Vector3 _g = { 0.0,-9.8,0.0 }, double _damp = 0.999, int health, int points, double timeToSpawn, double lifeTime);
	~nave();
	virtual void integrate(double t) override;
};

