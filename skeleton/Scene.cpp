#include "Scene.h"
using namespace physx;
Scene::Scene(physx::PxMaterial* gMaterial)
{
	CreateAxes(gMaterial);
}

Scene::~Scene()
{
	for (auto ent : entities) {
		delete ent;
	}
}

void Scene::AddEntity(Entity* ent)
{
	entities.push_back(ent);
}

void Scene::CreateAxes(physx::PxMaterial* gMaterial)
{

	//X
	Vector3D vecX = Vector3D(10, 0, 0);
	PxShape* x = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 xColor = { 1.0f,0.0f,0.0f,1.0f };
	AddEntity(new Entity(vecX, x, xColor));

	//Y
	Vector3D vecY = Vector3D(0, 10, 0);
	PxShape* y = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 yColor = { 0.0f,1.0f,0.0f,1.0f };
	AddEntity(new Entity(vecY, y, yColor));

	//Z
	Vector3D vecZ = Vector3D(0, 0, 10);
	PxShape* z = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 zColor = { 0.0f,0.0f,1.0f,1.0f };
	AddEntity(new Entity(vecZ, z, zColor));

}

void Scene::update(double t)
{
	for (auto ent : entities) {
		ent->integrate(t);
	}
}
