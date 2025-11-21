#include "dockForceGenerator.h"

dockForceGenerator::dockForceGenerator(Entity* _origen, Entity* _destino, float _K, float _l_o)
{
    K = _K;
    l_o = _l_o;
    origen = _origen;
    destino = _destino;
}

dockForceGenerator::~dockForceGenerator()
{
}

Vector3 dockForceGenerator::addForce(Vector3 entPos, Vector3 entVelocity, float t,float m)
{
    //EntPos
    if (isActive && isOnArea(entPos)) {
        d.x = abs(origen->getT()->p.x - destino->getT()->p.x);
        d.y = abs(origen->getT()->p.y - destino->getT()->p.y);
        d.z = abs(origen->getT()->p.z - destino->getT()->p.z);
        forceToReturn = -K * (d.magnitude() - l_o) * (d / d.magnitude());
        return forceToReturn;
    }
    else return Vector3({ 0.0,0.0,0.0 });
}

bool dockForceGenerator::isOnArea(Vector3 entPos)
{
    //Compruebo si la posicion de la partícula está por encima del valor permitido por el muelle el cual defino yo
    return true;
}
