//
// Created by Johan Solbakken on 08/05/2022.
//

#ifndef PBRT_VECTOR_H
#define PBRT_VECTOR_H


class Vector {
public:
    Vector();
    Vector(float xx, float yy, float zz);

    Vector operator+(const Vector &vector) const;
    Vector &operator+=(const Vector &vector);
    Vector operator-(const Vector &vector) const;
    Vector &operator-=(const Vector &vector);
    Vector operator*(float f) const;
    Vector &operator*=(float f);
    Vector operator/(float f) const;
    Vector &operator/=(float f);
    Vector operator-() const;
    float operator[](int i) const;
    float &operator[](int i);

    float LengthSquared() const;
    float Length() const;

private:
    [[nodiscard]] bool HasNaNs() const;

public:
    float x, y, z;
};

Vector operator*(float f, const Vector &vector);
Vector operator/(float f, const Vector &vector);

float Dot(const Vector& v1, const Vector& v2);
float AbsDot(const Vector& v1, const Vector& v2);
Vector Cross(const Vector& v1, const Vector& v2);
Vector Normalize(const Vector& vec);

#endif //PBRT_VECTOR_H
