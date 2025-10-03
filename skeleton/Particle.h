#include "Vector3D.h"
#include "Entity.h"

#pragma once
class Particle : public Entity
{

public:
	Particle();
	Particle(Vector3D pos,physx::PxShape* shape, const Vector4& color,Vector3D _v,Vector3D _a,double _masa, double _tVida, double _damp = 0.999);
	virtual ~Particle();
	void integrate(double t) override;
};

