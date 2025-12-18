#include "GeneradorNave.h"
using namespace physx;

GeneradorNave::GeneradorNave(physx::PxScene* context, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom, Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, physx::PxTransform _cameraTransform, double _damp, int health, int points, double _timeToSpawn)
{
	//Atributos del generador
	radius = 5.0;
	limitPos.x = 400.0;
	limitPos.y = 400.0;
	limitPos.z = 400.0;
	timeToSpawn = 6.0;
	timePass = timeToSpawn;
	limit = 1;
	//Partícula modelo
	PxReal coef = 0.4;
	cameraTransform = _cameraTransform;
	n = new nave(context, coef, coef / 2, coef * 2, gPhysx,geom,pos,color, _v, _masa, vol, _tVida, cameraTransform);
	n->DeRegItem();

	//Aleatorio
	std::random_device rand;
	_mt = std::mt19937(rand());
}

GeneradorNave::~GeneradorNave()
{
	for (auto rigid : srg) {
		if (rigid.second) {
			rigid.first->DeRegItem();
		}
	}
}

void GeneradorNave::setPosition(Vector3 pos)
{
	n->getT()->p = pos;
}

void GeneradorNave::setLimitPos(Vector3 pos)
{
	limitPos.x = pos.x;
	limitPos.y = pos.y;
	limitPos.z = pos.z;
}

bool GeneradorNave::getIsActive()
{
	return isActive;
}

void GeneradorNave::setIsActive(bool active)
{
	isActive = active;
}

void GeneradorNave::addForceGen(ForceGenerator* g)
{
	FGen.push_back(g);
}

DynamicSolidRigid* GeneradorNave::GeneraAleatoria()
{
	return nullptr;
}

nave* GeneradorNave::GeneraNaveAleatoria()
{
	//Seteo aleatorio de la posición inicial
	int aleX = std::rand() % (int)radius / 2 + 1;
	int aleY = std::rand() % (int)radius / 2 + 1;
	int aleZ = std::rand() % (int)radius / 2 + 1;
	Vector3 pos = Vector3(n->getT()->p.x + aleX, n->getT()->p.y + aleY, n->getT()->p.z + aleZ);

	//Creación de las variables random
	//Para los coeficientes
	std::uniform_real_distribution<float> px(0.5f, 1.0f);
	double staticVariation = px(_mt);
	double dynamicVariation = px(_mt);
	double restitutionVariation = px(_mt);
	//Para el color
	std::uniform_real_distribution<float> c(0.1f, 0.5f);
	double colorVariation = c(_mt);

	//Para la vida
	std::uniform_real_distribution<float> life(-10.0f, 10.0f);
	//Para la velocidad
	std::normal_distribution<double> d(0, 50);
	double velVariationX = d(_mt);
	double velVariationY = d(_mt);
	double velVariationZ = d(_mt);

	//Asgnación del color
	Vector4 color = n->getRenderItem()->color;
	if (color.x > 0.0 && colorVariations[0]) {
		color.x = colorVariation;
	}
	if (color.y > 0.0 && colorVariations[1]) {
		color.y = colorVariation;
	}
	if (color.z > 0.0 && colorVariations[2]) {
		color.z = colorVariation;
	}


	//Asignación de la velocidad
	Vector3 v = n->getV();
	v.x = v.x + (v.x * velVariationX);
	v.y = v.y + (v.y * velVariationY);
	v.z = v.z + (v.z * velVariationZ);

	//Asignacion de damping
	double damping = n->getDamp();

	double masa = n->getMasa();
	//Creación y devolución de la partícula
	nave* p;
	physx::PxScene* context = n->getContext();
	p = new nave(context, staticVariation, dynamicVariation, restitutionVariation, n->getPhy(), PxSphereGeometry(3), pos, color, v, masa, 0.0, n->getTvida(), cameraTransform, damping);
	for (auto g : FGen) {
		p->addForceGenerator(g);
	}
	return p;
}

void GeneradorNave::RegSolidRigid()
{
	for (auto& rigid : srg) {
		if (rigid.second) {
			rigid.first->RegItem();
		}
	}
}

void GeneradorNave::DeRegSolidRigid()
{
	for (auto& rigid : srg) {
		if (rigid.second) {
			rigid.first->DeRegItem();
		}
	}
}

void GeneradorNave::addSolidRigid()
{
	//pos, shape, color, v, a, _tVida, damp
	if (timePass >= timeToSpawn) {
		int i = 0;
		while (i < limit) {
			srg.push_back({ GeneraNaveAleatoria(),true });
			i++;
		}
		timePass = 0;
	}
}

void GeneradorNave::removeSolidRigid()
{
	for (auto& rigid : srg) {
		if (rigid.first->getTvida() <= 0 && rigid.second == true) {
			rigid.first->DeRegItem();
			rigid.second = false;

		}
		else if (rigid.second == true && std::abs(rigid.first->getObj()->getGlobalPose().p.x) > limitPos.x || rigid.second == true && std::abs(rigid.first->getObj()->getGlobalPose().p.y) > limitPos.y || rigid.second == true && std::abs(rigid.first->getObj()->getGlobalPose().p.z) > limitPos.z) {
			rigid.first->DeRegItem();
			rigid.second = false;
		}
	}
}

void GeneradorNave::integrate(double t)
{
	for (auto& rigid : srg) {
		if (rigid.second) {
			rigid.first->integrate(t);
		}
	}
	timePass += t;
}

void GeneradorNave::setVariation(int RGBAttribute, bool show)
{
	for (int i = 0; i < colorVariations.size(); ++i) {
		if (i == RGBAttribute) colorVariations[i] = show;
	}
}
