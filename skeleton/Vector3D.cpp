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
    return Vector3D();
}

void Vector3D::MultEscalar(Vector3D& vec1, float mult)
{
    vec1.x *= mult;
    vec1.y *= mult;
    vec1.z *= mult;
}

Vector3D Vector3D::operator+(Vector3D other)
{
    return Vector3D();
}

Vector3D Vector3D::operator-(Vector3D other)
{
    return Vector3D();
}

Vector3D Vector3D::operator*(Vector3D other)
{
    return Vector3D();
}

Vector3D Vector3D::operator=(Vector3D other)
{
    return Vector3D();
}
