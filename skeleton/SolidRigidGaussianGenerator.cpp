#include "SolidRigidGaussianGenerator.h"
using namespace physx;
SolidRigidGaussianGenerator::SolidRigidGaussianGenerator(float rad, float _timeToSpawn, float l, physx::PxReal coefStatic, physx::PxReal dynamStatic, physx::PxReal restitution, physx::PxPhysics* gPhysx, const physx::PxGeometry& geom,
	Vector3 pos, const Vector4& color, Vector3 _v, double _masa, double vol, double _tVida, double _damp)
{
	//Atributos del generador
	radius = rad;
	limitPos.x = rad * 2;
	limitPos.y = rad * 2;
	limitPos.z = rad * 2;
	timeToSpawn = _timeToSpawn;
	timePass = timeToSpawn;
	limit = l;
	//Partícula modelo
	model = new DynamicSolidRigid(coefStatic, dynamStatic, restitution, gPhysx, geom, pos, color,_v,_masa,vol,_tVida,_damp);
	model->DeRegItem();

	//Aleatorio
	std::random_device rand;
	_mt = std::mt19937(rand());
}

SolidRigidGaussianGenerator::~SolidRigidGaussianGenerator()
{
	for (auto rigid : solidRigid) {
		if (rigid.second) {
			rigid.first->DeRegItem();
		}
	}
}

void SolidRigidGaussianGenerator::setPosition(Vector3 pos)
{
	model->getT()->p = pos;
}

void SolidRigidGaussianGenerator::setLimitPos(Vector3 pos)
{
	limitPos.x = pos.x;
	limitPos.y = pos.y;
	limitPos.z = pos.z;
}

bool SolidRigidGaussianGenerator::getIsActive()
{
	return isActive;
}

void SolidRigidGaussianGenerator::setIsActive(bool active)
{
	isActive = active;
}

void SolidRigidGaussianGenerator::addForceGen(ForceGenerator* g)
{
	FGen.push_back(g);
}

DynamicSolidRigid* SolidRigidGaussianGenerator::GeneraAleatoria()
{
	//Seteo aleatorio de la posición inicial
	int aleX = std::rand() % (int)radius / 2 + 1;
	int aleY = std::rand() % (int)radius / 2 + 1;
	int aleZ = std::rand() % (int)radius / 2 + 1;
	Vector3 pos = Vector3(model->getT()->p.x + aleX, model->getT()->p.y + aleY, model->getT()->p.z + aleZ);

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
	Vector4 color = model->getRenderItem()->color;
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
	Vector3 v = model->getV();
	v.x = v.x + (v.x * velVariationX);
	v.y = v.y + (v.y * velVariationY);
	v.z = v.z + (v.z * velVariationZ);


	//Asignación de la vida
	double lifeVariation = life(_mt);
	double vida = model->getTvida() + lifeVariation;

	//Asignacion de damping
	double damping = model->getDamp();

	double masa = model->getMasa();
	//Creación y devolución de la partícula
	DynamicSolidRigid* p;
	switch (model->getGeom().getType()) {
	case (PxGeometryType::eSPHERE):
		p = new DynamicSolidRigid(staticVariation, dynamicVariation, restitutionVariation, model->getPhy(), PxSphereGeometry(1), pos, color, v, masa, 0.0, vida, damping);
		break;

	case (PxGeometryType::eBOX):
		p = new DynamicSolidRigid(staticVariation, dynamicVariation, restitutionVariation, model->getPhy(), PxBoxGeometry(1, 1, 1), pos, color, v, masa, 0.0, vida, damping);
		break;
	default:
		p = new DynamicSolidRigid(staticVariation, dynamicVariation, restitutionVariation, model->getPhy(), PxBoxGeometry(1, 1, 1), pos, color, v, masa, 0.0, vida, damping);
		break;
	}
	for (auto g : FGen) {
		p->addForceGenerator(g);
	}
	return p;
}

void SolidRigidGaussianGenerator::RegSolidRigid()
{
	for (auto& rigid : solidRigid) {
		if (rigid.second) {
			rigid.first->RegItem();
		}
	}
}

void SolidRigidGaussianGenerator::DeRegSolidRigid()
{
	for (auto& rigid : solidRigid) {
		if (rigid.second) {
			rigid.first->DeRegItem();
		}
	}
}

void SolidRigidGaussianGenerator::addSolidRigid(physx::PxScene* context)
{
	//pos, shape, color, v, a, _tVida, damp
	if (timePass >= timeToSpawn) {
		int i = 0;
		while (i < limit) {
			solidRigid.push_back({ GeneraAleatoria(),true });
			context->addActor(*solidRigid.back().first->getObj());
			i++;
		}
		timePass = 0;
	}
}

void SolidRigidGaussianGenerator::removeSolidRigid()
{
	for (auto& rigid : solidRigid) {
		if (rigid.first->getTvida() <= 0 && rigid.second == true) {
			rigid.first->DeRegItem();
			rigid.second = false;

		}
		else if (rigid.second == true && std::abs(rigid.first->getT()->p.x) > limitPos.x || rigid.second == true && std::abs(rigid.first->getT()->p.y) > limitPos.y || rigid.second == true && std::abs(rigid.first->getT()->p.z) > limitPos.z) {
			rigid.first->DeRegItem();
			rigid.second = false;
		}
	}
}

void SolidRigidGaussianGenerator::integrate(double t)
{
	for (auto& rigid : solidRigid) {
		if (rigid.second) {
			rigid.first->integrate(t);
		}
	}
	timePass += t;
}

void SolidRigidGaussianGenerator::setVariation(int RGBAttribute, bool show)
{
	for (int i = 0; i < colorVariations.size(); ++i) {
		if (i == RGBAttribute) colorVariations[i] = show;
	}
}
