//
// Created by Johan Solbakken on 07/05/2022.
//

#include "SamplerRenderer.h"

SamplerRenderer::SamplerRenderer(const std::shared_ptr<Sampler> &sampler, const std::shared_ptr<Camera> &camera,
                                 const std::shared_ptr<SurfaceIntegrator> &surfaceIntegrator,
                                 const std::shared_ptr<VolumeIntegrator> &volumeIntegrator)
        : sampler(sampler), camera(camera), surfaceIntegrator(surfaceIntegrator), volumeIntegrator(volumeIntegrator) {

}

SamplerRenderer::~SamplerRenderer() {

}

void SamplerRenderer::Render(const std::shared_ptr<Scene> &scene) {
    // Allow integrators to do preprocessing for the scene
    surfaceIntegrator->Preprocess(scene, camera, this);
    volumeIntegrator->Preprocess(scene, camera, this);

    // Allocate and initialize sample
    std::shared_ptr<Sample> sample = std::make_shared<Sample>(sampler, surfaceIntegrator, volumeIntegrator, scene);

    // Create and launch SamplerRendererTasks for rendering image

    // Clean up after rendering and store final image
}

Spectrum
SamplerRenderer::Li(const std::shared_ptr<Scene> &scene, MemoryArena &arena, std::shared_ptr<Intersection> isect,
                    std::shared_ptr<Spectrum> T) {
    return Spectrum();
}

Spectrum SamplerRenderer::Transmittance(const std::shared_ptr<Scene> &scene, const RayDifferential &ray,
                                        const std::shared_ptr<Sample> &sample, RNG &rng,
                                        MemoryArena &arena) const {
    return Spectrum();
}



