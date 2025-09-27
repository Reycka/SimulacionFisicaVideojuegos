#pragma once
#include <vector>
#include "Entity.h"
class Scene {
private:
	std::vector<Entity*> entities;
protected:

public:
	Scene(physx::PxMaterial* gMaterial);
	virtual ~Scene();
	void AddEntity(Entity* ent);
	void RegScene();
	void DeRegScene();
	void CreateAxes(physx::PxMaterial* gMaterial);
	void update(double t);
};