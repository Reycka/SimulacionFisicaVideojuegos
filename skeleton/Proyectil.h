#pragma once
#include "Entity.h"
class Proyectil : public Entity
{
private:
	void AjustaMasa();
	bool masaAjustada = false;
public:
	Proyectil();
	Proyectil(Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, double _masa, double _tVida,double _masaReal = 20, Vector3 _vReal = {3.0,2.0,3.0}, double _damp = 0.999);
	~Proyectil();
	void integrate(double t) override;
};

