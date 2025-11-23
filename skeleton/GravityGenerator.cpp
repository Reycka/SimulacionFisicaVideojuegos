#include "GravityGenerator.h"

GravityGenerator::GravityGenerator(Vector3 g)
{
    grav = g;
}

GravityGenerator::~GravityGenerator()
{
}

Vector3 GravityGenerator::addForce(Entity* ent, float t)
{
    if (isActive) return ent->getMasa() * grav;
    else return Vector3{ 0.0,0.0,0.0 };
}

bool GravityGenerator::isOnArea(Vector3 entPos)
{
    return true;
}
