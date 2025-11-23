#pragma once
#include "ForceGenerator.h"
#include "Entity.h"
#include <climits>
class dockForceGenerator : public ForceGenerator
{
protected:
	Vector3 limitDockPosition;
	Vector3 forceToReturn;
	Entity* origen;
	Entity* destino;
	float K; //Constante del muelle
	float l_o; //Longitud en reposo del muelle
	Vector3 d; //Distancia que separa ambas partes del muelle (origen con destino)
public:
	dockForceGenerator(Entity* origen, Entity* destino,float _K, float _l_o,Vector3 _limitDockPosition = Vector3({ FLT_MAX,FLT_MAX,FLT_MAX }));
	~dockForceGenerator();
	virtual Vector3 addForce(Entity* ent, float t) override;
	virtual bool isOnArea(Vector3 entPos) override;
	void setNewK(float newK);
};

