#pragma once
#include <PxPhysicsAPI.h>;

class Vector3D
{
private:
	float x;
	float y;
	float z;
public:
	Vector3D(float _x = 0, float _y = 0, float _z = 0);
	~Vector3D();
	float Modulo(Vector3D vec);
	Vector3D Normalize(Vector3D vec);
	Vector3D Escalar(const Vector3D& vec1, const Vector3D& vec2);
	Vector3D Vectorial(const Vector3D& vec1, const Vector3D& vec2);
	Vector3D MultEscalar(float mult);
	physx::PxVec3 changeClass();

	Vector3D operator+(Vector3D other);
	Vector3D operator-(Vector3D other);
	Vector3D operator*(Vector3D other);
	Vector3D operator=(Vector3D other);
	bool operator==(Vector3D other);
	inline Vector3D operator=(physx::PxVec3 other) { return Vector3D({ x = other.x, y = other.y, z = other.z }); }

};

