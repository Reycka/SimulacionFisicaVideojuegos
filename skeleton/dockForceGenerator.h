#pragma once
#include "ForceGenerator.h"
#include "Entity.h"
class dockForceGenerator : public ForceGenerator
{
private:
	Vector3 forceToReturn;
	Entity* origen;
	Entity* destino;
	float K; //Constante del muelle
	float l_o; //Longitud en reposo del muelle
	Vector3 d; //Distancia que separa ambas partes del muelle (origen con destino)
public:
	dockForceGenerator(Entity* origen, Entity* destino,float _K, float _l_o);
	~dockForceGenerator();
	virtual Vector3 addForce(Vector3 entPos, Vector3 entVelocity, float t = 0, float m = 0) override;
	virtual bool isOnArea(Vector3 entPos) override;
};

