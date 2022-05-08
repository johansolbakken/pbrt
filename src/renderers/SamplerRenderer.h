//
// Created by Johan Solbakken on 07/05/2022.
//

#ifndef PBRT_SAMPLERRENDERER_H
#define PBRT_SAMPLERRENDERER_H

#include "core/Renderer.h"

#include <memory>

class Sampler;

class Camera;

class SurfaceIntegrator;

class VolumeIntegrator;

class SamplerRenderer : public Renderer {
public:
    SamplerRenderer(const std::shared_ptr<Sampler> &sampler, const std::shared_ptr<Camera> &camera,
                    const std::shared_ptr<SurfaceIntegrator> &surfaceIntegrator,
                    const std::shared_ptr<VolumeIntegrator> &volumeIntegrator);

    ~SamplerRenderer() override;

    void Render(const std::shared_ptr<Scene> &scene) override;

    Spectrum Li(const std::shared_ptr<Scene> &scene, MemoryArena &arena, std::shared_ptr<Intersection> isect = nullptr,
                std::shared_ptr<Spectrum> T = nullptr) override;

    Spectrum Transmittance(const std::shared_ptr<Scene> &scene, const RayDifferential &ray,
                           const std::shared_ptr<Sample> &sample, RNG &rng, MemoryArena &arena) const override;

private:
    std::shared_ptr<Sampler> sampler;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<SurfaceIntegrator> surfaceIntegrator;
    std::shared_ptr<VolumeIntegrator> volumeIntegrator;
};


#endif //PBRT_SAMPLERRENDERER_H
