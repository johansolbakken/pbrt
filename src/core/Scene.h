//
//  Scene.hpp
//  pbrt
//
//  Created by Johan Solbakken on 06/05/2022.
//

#ifndef Scene_hpp
#define Scene_hpp

#include "core/Ray.h"
#include "core/Intersection.h"
#include "core/Geometry.h"
#include "core/Primitive.h"

#include "lights/Light.h"

#include "volumes/VolumeRegion.h"

#include <vector>
#include <memory>


class Scene {
public:
    Scene();
    // Scene public methods
    bool Intersect(const Ray& ray, std::shared_ptr<Intersection> isect) const;
    bool IntersectP(const Ray& ray) const;
    const BBox& WorldBound() const;

    // Scene public data
    std::shared_ptr<Primitive> aggregate;
    std::vector<std::shared_ptr<Light>> lights;
    std::shared_ptr<VolumeRegion> volumeRegion;
    BBox bound;
};

#endif /* Scene_hpp */
