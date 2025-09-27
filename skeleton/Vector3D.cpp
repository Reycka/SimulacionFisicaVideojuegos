#include "Vector3D.h"

Vector3D::Vector3D(float _x, float _y, float _z) : x(_x),y(_y),z(_z)
{

}

Vector3D::~Vector3D()
{
}

float Vector3D::Modulo(Vector3D vec)
{
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

Vector3D Vector3D::Normalize(Vector3D vec)
{
    float mag = Modulo(vec);
    return Vector3D({ vec.x / mag, vec.y / mag, vec.z / mag });
}

Vector3D Vector3D::Escalar(const Vector3D& vec1, const Vector3D& vec2)
{
    return Vector3D({ vec1.x * vec2.x,vec1.y * vec2.y,vec1.z * vec2.z });
}

Vector3D Vector3D::Vectorial(const Vector3D& vec1, const Vector3D& vec2)
{
    return Vector3D(
        vec1.y * vec2.z - vec1.z * vec2.y,
        vec1.z * vec2.x - vec1.x * vec2.z,
        vec1.x * vec2.y - vec1.y * vec2.x
    );
}

Vector3D Vector3D::MultEscalar(float mult)
{
    return Vector3D(x * mult, y * mult, z * mult);
}

physx::PxVec3 Vector3D::changeClass()
{
    return physx::PxVec3({x,y,z});
}

Vector3D Vector3D::operator+(Vector3D other)
{
    return Vector3D({x + other.x, y + other.y, z + other.z});
}

Vector3D Vector3D::operator-(Vector3D other)
{
    return Vector3D({ x - other.x, y - other.y, z - other.z });
}

Vector3D Vector3D::operator*(Vector3D other)
{
    return Vector3D({ x * other.x, y * other.y, z * other.z });
}

Vector3D Vector3D::operator=(Vector3D other)
{
    return Vector3D({ x = other.x, y = other.y, z = other.z });
}


