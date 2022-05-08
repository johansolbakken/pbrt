//
// Created by Johan Solbakken on 08/05/2022.
//

#include <gtest/gtest.h>

#include "core/Geometry.h"

TEST(GeometryTest, VectorConstructorTest) {
    Vector v{};
    EXPECT_FLOAT_EQ(0.0f, v.x) << "x should equal 0.0f";
    EXPECT_FLOAT_EQ(0.0f, v.y) << "y should equal 0.0f";
    EXPECT_FLOAT_EQ(0.0f, v.z) << "z should equal 0.0f";

    Vector v2{1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(1.0f, v2.x) << "x should equal 1.0f";
    EXPECT_FLOAT_EQ(2.0f, v2.y) << "y should equal 2.0f";
    EXPECT_FLOAT_EQ(3.0f, v2.z) << "z should equal 3.0f";
}

TEST(GeometryTest, VectorArithmeticTest) {
    Vector a{1.0f, 2.0f, 3.0f};
    Vector b{1.0f, 2.0f, 3.0f};

    Vector c = a + b;
    EXPECT_FLOAT_EQ(2.0f, c.x) << "x should be 2.0f";
    EXPECT_FLOAT_EQ(4.0f, c.y) << "y should be 4.0f";
    EXPECT_FLOAT_EQ(6.0f, c.z) << "z should be 6.0f";

    c += a;
    EXPECT_FLOAT_EQ(3.0f, c.x) << "x should be 3.0f";
    EXPECT_FLOAT_EQ(6.0f, c.y) << "y should be 6.0f";
    EXPECT_FLOAT_EQ(9.0f, c.z) << "z should be 9.0f";

    c = a - b;
    EXPECT_FLOAT_EQ(0.0f, c.x) << "x should be 0.0f";
    EXPECT_FLOAT_EQ(0.0f, c.y) << "y should be 0.0f";
    EXPECT_FLOAT_EQ(0.0f, c.z) << "z should be 0.0f";

    c -= a;
    EXPECT_FLOAT_EQ(-1.0f, c.x) << "x should be -1.0f";
    EXPECT_FLOAT_EQ(-2.0f, c.y) << "y should be -2.0f";
    EXPECT_FLOAT_EQ(-3.0f, c.z) << "z should be -3.0f";

    Vector d{2.0f, 3.0f, 4.0f};
    Vector e = 2.0f * d;
    EXPECT_FLOAT_EQ(4.0f, e.x) << "x should be 4";
    EXPECT_FLOAT_EQ(6.0f, e.y) << "y should be 6";
    EXPECT_FLOAT_EQ(8.0f, e.z) << "z should be 8";

    e = d * 2.0f;
    EXPECT_FLOAT_EQ(4.0f, e.x) << "x should be 4";
    EXPECT_FLOAT_EQ(6.0f, e.y) << "y should be 6";
    EXPECT_FLOAT_EQ(8.0f, e.z) << "z should be 8";

    d *= 2.0f;
    EXPECT_FLOAT_EQ(4.0f, d.x) << "x should be 4";
    EXPECT_FLOAT_EQ(6.0f, d.y) << "y should be 6";
    EXPECT_FLOAT_EQ(8.0f, d.z) << "z should be 8";

    Vector i{2.0f, 4.0f, 6.0f};
    Vector j = i / 2.0f;
    EXPECT_FLOAT_EQ(1.0f, j.x) << "x should be 1";
    EXPECT_FLOAT_EQ(2.0f, j.y) << "y should be 2";
    EXPECT_FLOAT_EQ(3.0f, j.z) << "z should be 3";

    i /= 2.0f;
    EXPECT_FLOAT_EQ(1.0f, i.x) << "x should be 1";
    EXPECT_FLOAT_EQ(2.0f, i.y) << "y should be 2";
    EXPECT_FLOAT_EQ(3.0f, i.z) << "z should be 3";

    Vector vec(-1.0f, -2.0f, -3.0f);
    Vector inv = -vec;
    EXPECT_FLOAT_EQ(1.0f, inv.x) << "x should be 1";
    EXPECT_FLOAT_EQ(2.0f, inv.y) << "y should be 2";
    EXPECT_FLOAT_EQ(3.0f, inv.z) << "z should be 3";

    EXPECT_FLOAT_EQ(-1.0f, vec[0]) << "x should be -1";
    EXPECT_FLOAT_EQ(-2.0f, vec[1]) << "y should be -2";
    EXPECT_FLOAT_EQ(-3.0f, vec[2]) << "z should be -3";
}

TEST(GeometryTest, DotCrossTest)
{
    Vector a{2, 2, 4};
    Vector b{5, 6, -7};

    float dot = Dot(a, b);
    EXPECT_FLOAT_EQ(-6.f, dot) << "answer should be -6";

    float absDot = AbsDot(a, b);
    EXPECT_FLOAT_EQ(6.f, absDot) << "answer should be 6";

    Vector cross = Cross(a, b);
    EXPECT_FLOAT_EQ(-38.f, cross.x) << "answer should be -38";
    EXPECT_FLOAT_EQ(34.f, cross.y) << "answer should be 34";
    EXPECT_FLOAT_EQ(2.f, cross.z) << "answer should be 2";
}