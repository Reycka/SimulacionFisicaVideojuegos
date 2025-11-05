#pragma once
#include "Entity.h"
#include <list>
class CompoundEntity : public Entity	
{
protected:
	std::list<Entity*> childs;
	Vector3 finalPosition;
public:
	CompoundEntity(Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, double _damp = 0.999);
	CompoundEntity(std::list<Entity*> _list,Vector3 pos, physx::PxShape* _shape, const Vector4& color, Vector3 _v, double _masa, double _tVida, double _damp = 0.999);
	~CompoundEntity();
	void AddEntityChildren(Entity* ent);
};

