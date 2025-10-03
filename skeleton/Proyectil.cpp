#include "Proyectil.h"

Proyectil::Proyectil()
{
}

Proyectil::Proyectil(Vector3 pos, physx::PxShape* shape, const Vector4& color, Vector3 _v, Vector3 _a, double _masa, double _tVida, double _damp) : Entity(pos,shape,color,_v,_a,_masa,_tVida,_damp)
{

}

Proyectil::~Proyectil()
{
}

void Proyectil::integrate(double t)
{
}
