//
// Created by Johan Solbakken on 07/05/2022.
//

#ifndef PBRT_PRIMITIVE_H
#define PBRT_PRIMITIVE_H


#include "Ray.h"
#include "Intersection.h"
#include "Geometry.h"

#include <memory>

class Primitive {

public:
    bool Intersect(const Ray &ray, std::shared_ptr<Intersection> pIntersection);

    bool IntersectP(const Ray &ray);

    BBox WorldBound();
};


#endif //PBRT_PRIMITIVE_H
