#include "dockForceGenerator.h"

dockForceGenerator::dockForceGenerator(Entity* _origen, Entity* _destino, float _K, float _l_o, Vector3 _limitDockPosition)
{
    K = _K;
    l_o = _l_o;
    origen = _origen;
    destino = _destino;
    limitDockPosition = _limitDockPosition;
}

dockForceGenerator::~dockForceGenerator()
{
}

Vector3 dockForceGenerator::addForce(physx::PxShape* shape,Vector3 entPos, Vector3 entVelocity, float t,float m)
{
    //EntPos
    if (isActive && isOnArea(entPos)) {
        d.x = (origen->getT()->p.x - destino->getT()->p.x);
        d.y = (origen->getT()->p.y - destino->getT()->p.y);
        d.z = (origen->getT()->p.z - destino->getT()->p.z);
        float lenght = d.normalize();
        float deltaX = lenght - l_o;
        forceToReturn = d * deltaX * K;
        return forceToReturn;
    }
    else {
        //Se rompe el muelle
        setIsActive(false);
        return Vector3({ 0.0,0.0,0.0 });
    }
}

bool dockForceGenerator::isOnArea(Vector3 entPos)
{
    //Compruebo si la posicion de la partícula está por encima del valor permitido por el muelle el cual defino yo
    if (abs(entPos.x) > abs(limitDockPosition.x) || abs(entPos.y) > abs(limitDockPosition.y) || abs(entPos.z) > abs(limitDockPosition.z)) {
        return false;
    }
    return true;
}

void dockForceGenerator::setNewK(float newK)
{
   // float alpha = 0.1f; // factor de suavizado
   // K = K + alpha * (newK - K);
    K = newK;
}
