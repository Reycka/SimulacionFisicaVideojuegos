#include "SceneP5.h"
#include "StaticSolidRigid.h"
#include "RigidBodySystem.h"
#include "SolidRigidGaussianGenerator.h"
#include "GravityGenerator.h"
using namespace physx;
SceneP5::SceneP5(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial,_phy,_gScene,_cam)
{
	//Creacion del suelo
	PxReal coef = 1.0;
    StaticSolidRigid* floor = new StaticSolidRigid(
        coef, coef, coef,
        _phy,
        PxBoxGeometry(100.0,0.01,100.0),
        Vector3(0.0, -10.0, 0.0),
        Vector4(0.5, 0.5, 0.5,1.0),
        Vector3(0.0, 0.0, 0.0),
        30.0, 2.0, 10.0
    );
    AddEntity(floor);
    _gScene->addActor(*floor->getObj());
    RigidBodySystem* rgSys = new RigidBodySystem(_gScene);
    SolidRigidGaussianGenerator* solidGen = new SolidRigidGaussianGenerator(10.0,1.0,10.0,1.0,1.0,1.0,_phy, PxBoxGeometry(1.0, 1.0, 1.0),Vector3(0.0,10.0,0.0),Vector4(1.0,0.0,1.0,1.0),Vector3(1.0,0.0,0.0),5,2,5.0);
    rgSys->addGenerator(solidGen);
 //   GravityGenerator* gravityGen = new GravityGenerator({ 0.0,-10.0,0.0 });
//    rgSys->addForceGenerator(gravityGen);
    AddEntity(rgSys);
 //   AddForceGenerator(gravityGen);
}

SceneP5::~SceneP5()
{
}

void SceneP5::keyPress(unsigned char key)
{
}
