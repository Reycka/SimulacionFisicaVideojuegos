#pragma once
#include "dockForceGenerator.h"
class RubberyForceGenerator : public dockForceGenerator
{
public:
	RubberyForceGenerator(Entity* origen, Entity* destino, float _K, float _l_o, Vector3 _limitDockPosition = Vector3({ 20.0,20.0,20.0 }));
	~RubberyForceGenerator();
	virtual Vector3 addForce(Vector3 entPos, Vector3 entVelocity, float t = 0, float m = 0) override;
	virtual bool isOnArea(Vector3 entPos) override;
};

