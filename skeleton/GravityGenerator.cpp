#include "GravityGenerator.h"

GravityGenerator::GravityGenerator(Vector3 g)
{
    grav = g;
}

GravityGenerator::~GravityGenerator()
{
}

Vector3 GravityGenerator::addForce(Vector3 entPos, Vector3 entVelocity,float t,float m)
{
    if (isActive) return m * grav;
    else return Vector3{ 0.0,0.0,0.0 };
}

bool GravityGenerator::isOnArea(Vector3 entPos)
{
    return true;
}
