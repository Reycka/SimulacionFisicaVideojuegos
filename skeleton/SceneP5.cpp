#include "SceneP5.h"
#include "StaticSolidRigid.h"
using namespace physx;
SceneP5::SceneP5(physx::PxMaterial* _gMaterial, physx::PxPhysics* _phy, physx::PxScene* _gScene, Camera* _cam) : Scene(_gMaterial,_phy,_gScene,_cam)
{
	//Creacion del suelo
	PxReal coef = 1.0;
    StaticSolidRigid* floor = new StaticSolidRigid(
        coef, coef, coef,
        _phy,
        PxBoxGeometry(),
        Vector3(0.0, -10.0, 0.0),
        Vector4(1.0, 1.0, 1.0,1.0),
        Vector3(0.0, 0.0, 0.0),
        30.0, 2.0, 10.0
    );
    AddEntity(floor);
}

SceneP5::~SceneP5()
{
}

void SceneP5::keyPress(unsigned char key)
{
}
