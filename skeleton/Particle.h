#include "Vector3D.h"
#include "Entity.h"

#pragma once
class Particle : public Entity
{

public:
	Particle();
	Particle(Vector3 pos,physx::PxShape* shape, const Vector4& color,Vector3 _v, double _tVida, Vector3 g = {0.0,-9.8,0.0}, double _damp = 0.999);
	virtual ~Particle();
	void integrate(double t) override;
};

