#pragma once
#include <vector>
#include "Entity.h"
class Scene {
private:
	std::vector<Entity*> entities;
protected:

public:
	Scene();
	virtual ~Scene();
	void AddEntity(Entity* ent);
	void CreateAxes(physx::PxMaterial* gMaterial);
	void update(double t);
};