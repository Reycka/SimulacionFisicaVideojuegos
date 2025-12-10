#pragma once
#include "DynamicSolidRigid.h"
#include <random>
#include "ForceGenerator.h"
class SolidRigidGenerator
{
protected:
	bool isActive = true;
	std::vector<ForceGenerator*> FGen;
	std::vector<bool> colorVariations{ true,true,true }; //Que colores queremos cambiar
	DynamicSolidRigid* model;
	double radius;
	std::vector<std::pair<DynamicSolidRigid*, bool>>solidRigid;
	int limit = 5;
	double timeToSpawn;
	double timePass;
	Vector3 limitPos;
	std::mt19937 _mt;
	std::uniform_real_distribution<double> urd;
public:
	virtual ~SolidRigidGenerator() {};
	virtual void setPosition(Vector3 pos) = 0;
	virtual bool getIsActive() = 0;
	virtual void setIsActive(bool active) = 0;
	virtual void addForceGen(ForceGenerator* g) = 0;
	virtual void addSolidRigid(physx::PxScene* context) = 0;
	virtual void RegSolidRigid() = 0;
	virtual void DeRegSolidRigid() = 0;
	virtual DynamicSolidRigid* GeneraAleatoria() = 0;
	virtual void removeSolidRigid() = 0;
	virtual void integrate(double t) = 0;
	virtual void setVariation(int RGBAttribute, bool show) = 0;
};

