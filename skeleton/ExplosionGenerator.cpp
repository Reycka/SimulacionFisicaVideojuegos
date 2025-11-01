#include "ExplosionGenerator.h"
#include <cmath>
ExplosionGenerator::ExplosionGenerator(Vector3 _pos, float _R, float _cteR, float _K, Vector3 _velExp)
{
    pos = _pos;
    R = _R;
    cteR = _cteR;
    K = _K;
    r = 0;
    velExp = _velExp;
    isActive = false;
}

ExplosionGenerator::~ExplosionGenerator()
{
}

Vector3 ExplosionGenerator::addForce(Vector3 entPos, Vector3 entVel, float t)
{
    explosionForce = Vector3({ 0.0,0.0,0.0 });
    if (isActive) {
        r = pow((entPos.x - pos.x), 2) + pow((entPos.y - pos.y), 2) + pow((entPos.z - pos.z), 2);
        float dotr = r;
        r = std::sqrt(r);
        float auxR = R;
        R = velExp.magnitude() * t;
        if (isOnArea(entPos)) {
            float aux1 = K / dotr; //Saca el valor de cte K / r
            float aux2 = pow(std::exp(1.0f), -(t / cteR)); //Saca el valor de e elevado a -t/cteR
            explosionForce.x = aux1 * (entPos.x - pos.x) * aux2;
            explosionForce.y = aux1 * (entPos.y - pos.y) * aux2;
            explosionForce.z = aux1 * (entPos.z - pos.z) * aux2;
        }
        R = auxR;
    }
    return explosionForce;
}

bool ExplosionGenerator::isOnArea(Vector3 entPos)
{
    return r < R;
}
