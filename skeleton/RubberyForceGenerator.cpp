#include "RubberyForceGenerator.h"

RubberyForceGenerator::RubberyForceGenerator(Entity* origen, Entity* destino, float _K, float _l_o, Vector3 _limitDockPosition)
    : dockForceGenerator(origen,destino,_K,_l_o,_limitDockPosition)
{
}

RubberyForceGenerator::~RubberyForceGenerator()
{
}

Vector3 RubberyForceGenerator::addForce(Entity* ent, float t)
{
    //EntPos
    if (isActive && isOnArea(ent->getT()->p)) {
        d.x = (origen->getT()->p.x - destino->getT()->p.x);
        d.y = (origen->getT()->p.y - destino->getT()->p.y);
        d.z = (origen->getT()->p.z - destino->getT()->p.z);
        float lenght = d.normalize();
        float deltaX = lenght - l_o;
        forceToReturn = d * deltaX * K;
        return forceToReturn;
    }
    else {
        return Vector3({ 0.0,0.0,0.0 });
    }
}

bool RubberyForceGenerator::isOnArea(Vector3 entPos)
{
    //Si la goma no ha llegado a su límite no devuelve fuerza
    if (abs(entPos.x) >= abs(limitDockPosition.x) || abs(entPos.y) >= abs(limitDockPosition.y) || abs(entPos.z) >= abs(limitDockPosition.z)) {
        return true;
    }
    return false;
}
