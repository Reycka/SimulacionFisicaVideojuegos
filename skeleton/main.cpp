#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Vector3D.h"

#include <iostream>

std::string display_text = "This is a test";


using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;


// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	//Act 2 P0 Draw a sphere in 0,0,0
	PxShape* sphereShape = CreateShape(PxSphereGeometry(1), gMaterial);
	PxTransform* sphereTransform = new PxTransform(PxVec3(0,0,0));
	Vector4 sphereColor = {1.0f,1.0f,1.0f,1.0f};

	RenderItem* sphere = new RenderItem(sphereShape,sphereTransform,sphereColor);
	RegisterRenderItem(sphere);
	DeregisterRenderItem(sphere);

	//Act 3 P0 Draw x, y and Z axes

	
	//X
	Vector3D vecX = Vector3D(10, 0, 0);
	PxShape* x = CreateShape(PxSphereGeometry(1), gMaterial);
	PxTransform* xTransform = new PxTransform(vecX.changeClass());
	Vector4 xColor = { 1.0f,0.0f,0.0f,1.0f };

	RenderItem* xAxix = new RenderItem(x, xTransform, xColor);
	RegisterRenderItem(xAxix);


	//Y
	Vector3D vecY = Vector3D(0, 10, 0);
	PxShape* y = CreateShape(PxSphereGeometry(1), gMaterial);
	PxTransform* yTransform = new PxTransform(vecY.changeClass());
	Vector4 yColor = { 0.0f,1.0f,0.0f,1.0f };

	RenderItem* yAxix = new RenderItem(y, yTransform, yColor);
	RegisterRenderItem(yAxix);


	//Z
	Vector3D vecZ = Vector3D(0, 0, 10);
	PxShape* z = CreateShape(PxSphereGeometry(1), gMaterial);
	PxTransform* zTransform = new PxTransform(vecZ.changeClass());
	Vector4 zColor = { 0.0f,0.0f,1.0f,1.0f };

	RenderItem* zAxix = new RenderItem(z, zTransform, zColor);
	RegisterRenderItem(zAxix);
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}