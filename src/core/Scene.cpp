//
//  Scene.cpp
//  pbrt
//
//  Created by Johan Solbakken on 06/05/2022.
//

#include "Scene.h"

Scene::Scene() {
    bound = aggregate->WorldBound();
    //if (volumeRegion) bound = Union(bound, volumeRegion->WorldBound());
}

bool Scene::Intersect(const Ray &ray, Intersection *isect) const {
    bool hit = aggregate->Intersect(ray, isect);
    return hit;
}

bool Scene::IntersectP(const Ray &ray) const {
    bool hit = aggregate->IntersectP(ray);
    return hit;
}

const BBox &Scene::WorldBound() const {
    return bound;
}


