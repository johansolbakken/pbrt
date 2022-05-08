//
// Created by Johan Solbakken on 07/05/2022.
//

#ifndef PBRT_RENDERER_H
#define PBRT_RENDERER_H

#include "pbrt.h"

#include "Scene.h"

#include "Intersection.h"

class MemoryArena;
class RayDifferential;
class Sample;
class RNG;

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void Render(const std::shared_ptr<Scene>& scene) = 0;
    virtual Spectrum Li(const std::shared_ptr<Scene>& scene, MemoryArena &arena, std::shared_ptr<Intersection> isect=nullptr, std::shared_ptr<Spectrum> T = nullptr) = 0;
    virtual Spectrum Transmittance(const std::shared_ptr<Scene>& scene, const RayDifferential& ray, const std::shared_ptr<Sample>& sample, RNG& rng, MemoryArena& arena) const = 0;
};


#endif //PBRT_RENDERER_H
