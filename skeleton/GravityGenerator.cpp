#include "GravityGenerator.h"

GravityGenerator::GravityGenerator(Vector3 g)
{
    grav = g;
}

GravityGenerator::~GravityGenerator()
{
}

Vector3 GravityGenerator::addForce()
{
    if(isActive) return grav;
}
