#include "GravityGenerator.h"

GravityGenerator::GravityGenerator(Vector3 g)
{
    grav = g;
}

GravityGenerator::~GravityGenerator()
{
}

Vector3 GravityGenerator::addForce(Vector3 entPos, Vector3 entVelocity,float t)
{
    if(isActive) return grav;
}

bool GravityGenerator::isOnArea(Vector3 entPos)
{
    return true;
}
