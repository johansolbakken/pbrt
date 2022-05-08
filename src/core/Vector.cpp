//
// Created by Johan Solbakken on 08/05/2022.
//

#include "Vector.h"

#include <cmath>

#include "Error.h"

Vector::Vector() : x(0.0f), y(0.0f), z(0.0f) {}

Vector::Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {
    Assert(!HasNaNs());
}

Vector Vector::operator+(const Vector &vector) const {
    Vector vec{x, y, z};
    vec += vector;
    return vec;
}

Vector &Vector::operator+=(const Vector &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector Vector::operator-(const Vector &vector) const {
    Vector vec{x, y, z};
    vec -= vector;
    return vec;
}

Vector &Vector::operator-=(const Vector &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

Vector Vector::operator*(float f) const {
    return {x * f, y * f, z * f};
}

Vector &Vector::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Vector Vector::operator/(float f) const {
    Assert(f != 0);

    float inv = 1.0f / f;
    return {x * inv, y * inv, z * inv};
}

Vector &Vector::operator/=(float f) {
    Assert(f != 0);

    float inv = 1.0f / f;
    x *= inv;
    y *= inv;
    z *= inv;

    return *this;
}

Vector Vector::operator-() const {
    \
    return {-x, -y, -z};
}

float Vector::operator[](int i) const {
    Assert(i >= 0 && i <= 2);
    return (&x)[i];
}

float &Vector::operator[](int i) {
    Assert(i >= 0 && i <= 2)
    {
        return (&x)[i];
    }
}

bool Vector::HasNaNs() const {
    return std::isnan(x) || std::isnan(y) || std::isnan(z);
}

float Vector::LengthSquared() const {
    return x * x + y * y + z * z;
}

float Vector::Length() const {
    return std::sqrt(LengthSquared());
}

Vector operator*(float f, const Vector &vector) {
    return vector * f;
}

Vector operator/(float f, const Vector &vector) {
    return vector / f;
}

float Dot(const Vector &v1, const Vector &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float AbsDot(const Vector &v1, const Vector &v2) {
    return std::abs(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

Vector Cross(const Vector &v1, const Vector &v2) {
    return {
            (v1.y * v2.z) - (v1.z * v2.y),
            (v1.z * v2.x) - (v1.x * v2.z),
            (v1.x * v2.y) - (v1.y * v2.x)
    };
}

Vector Normalize(const Vector &vec) {
    return vec / vec.Length();
}
