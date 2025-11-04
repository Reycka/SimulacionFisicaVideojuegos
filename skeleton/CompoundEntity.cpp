#include "CompoundEntity.h"

CompoundEntity::CompoundEntity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, Vector3 _g, double _damp) : Entity(pos,_shape,color,_v,_masa,_tVida,_g,_damp)
{
	finalPosition = { 0.0,0.0,0.0 };
}

CompoundEntity::CompoundEntity(std::list<Entity*> _list, Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, Vector3 _g, double _damp) : Entity(pos, _shape, color, _v, _masa, _tVida, _g, _damp)
{
	childs = _list;
	finalPosition = { 0.0,0.0,0.0 };
}

CompoundEntity::~CompoundEntity()
{
	for (auto kid : childs) {
		delete kid;
	}
}

void CompoundEntity::AddEntityChildren(Entity* ent)
{
	childs.push_back(ent);
}
