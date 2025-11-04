#include "nave.h"

nave::nave(Vector3 _finalPos, Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, Vector3 _g, double _damp,int health,int points,double timeToSpawn,double lifeTime) : CompoundEntity(pos,_shape,color,_v,_masa,_tVida,_g,_damp) ,Enemy(health,points,timeToSpawn,lifeTime)
{
	finalPosition = _finalPos;
}

nave::~nave()
{
}

void nave::integrate(double t)
{
	proyectilUpdate(t);
	//Movimiento
}
