#pragma once
#include "Entity.h"
class Proyectil : public Entity
{
private:

public:
	Proyectil();
	Proyectil(Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _damp = 0.999);
	~Proyectil();
	void integrate(double t) override;
};

