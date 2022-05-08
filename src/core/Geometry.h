//
// Created by Johan Solbakken on 07/05/2022.
//

#ifndef PBRT_GEOMETRY_H
#define PBRT_GEOMETRY_H

#include "pbrt.h"

#include "Vector.h"

class BBox {
    friend BBox Union(const BBox &a, const BBox &b);
};

BBox Union(const BBox &a, const BBox &b)
{
    return BBox();
}


#endif //PBRT_GEOMETRY_H
