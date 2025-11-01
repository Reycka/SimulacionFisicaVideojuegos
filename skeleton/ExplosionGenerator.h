#pragma once
#include "ForceGenerator.h"
class ExplosionGenerator : public ForceGenerator
{
private:
	const float MAXEXPLOSIONTIME = 2.0;
	Vector3 explosionForce;
	Vector3 pos;
	Vector3 velExp;
	float r;
	float cteR;
	float R;
	float K;
	float lastTimeRegister;
	float timeSinceExplode;
public:
	ExplosionGenerator(Vector3 _pos, float _R,float _cteR, float _K,Vector3 _velExp);
	~ExplosionGenerator();
	Vector3 addForce(Vector3 entPos,Vector3 entVel,float t = 0) override;
	bool isOnArea(Vector3 entPos) override;
};

