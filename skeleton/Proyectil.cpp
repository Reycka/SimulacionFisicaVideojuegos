#include "Proyectil.h"

Proyectil::Proyectil()
{
}

Proyectil::Proyectil(Vector3D pos, physx::PxShape* shape, const Vector4& color, Vector3D _v, Vector3D _a, double _masa, double _tVida, double _damp) : Entity(pos,shape,color,_v,_a,_masa,_tVida,_damp)
{

}

Proyectil::~Proyectil()
{
}

void Proyectil::integrate(double t)
{
}
