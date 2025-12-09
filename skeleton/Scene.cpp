#include "Scene.h"
using namespace physx;
Scene::Scene(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene,Camera* _cam)
{
	gMaterial = _gMaterial;
	phy = _phy;
	gScene = _gScene;
	cam = _cam;
	CreateAxes();
}

Scene::~Scene()
{
	for (auto ent : entities) {
		delete ent;
	}
	for (auto fGen : generators) {
		delete fGen;
	}
}

void Scene::AddEntity(Entity* ent)
{
	entities.push_back(ent);
}

void Scene::AddForceGenerator(ForceGenerator* forceGen)
{
	generators.push_back(forceGen);
}

void Scene::RegScene()
{
	for (auto& ent : entities) {
		ent->RegItem();
	}
}

void Scene::DeRegScene()
{
	for (auto& ent : entities) {
		ent->DeRegItem();
	}
}

void Scene::CreateAxes()
{

	//X
	Vector3 vecX = Vector3(10, 0, 0);
	PxShape* x = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 xColor = { 1.0f,0.0f,0.0f,1.0f };
	AddEntity(new Entity(vecX, x, xColor));

	//Y
	Vector3 vecY = Vector3(0, 10, 0);
	PxShape* y = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 yColor = { 0.0f,1.0f,0.0f,1.0f };
	AddEntity(new Entity(vecY, y, yColor));

	//Z
	Vector3 vecZ = Vector3(0, 0, 10);
	PxShape* z = CreateShape(PxSphereGeometry(1), gMaterial);
	Vector4 zColor = { 0.0f,0.0f,1.0f,1.0f };
	AddEntity(new Entity(vecZ, z, zColor));

}

void Scene::update(double t)
{
	for (auto& ent : entities) {
		ent->integrate(t);
	}
}

void Scene::keyPress(unsigned char key)
{
}

physx::PxPhysics* Scene::getPhysx() const
{
	return phy;
}

physx::PxScene* Scene::getPhysxScene() const
{
	return gScene;
}

physx::PxMaterial* Scene::getMaterial() const
{
	return gMaterial;
}

Camera* Scene::getCamera() const
{
	return cam;
}
