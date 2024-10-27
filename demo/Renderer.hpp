#pragma once

#include "vulkan-engine/Image/Image.hpp"

#include "Camera.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

#include <memory>
#include <glm/glm.hpp>

class Renderer{
public:
	Renderer() = default;

	void onResize(uint32_t width, uint32_t height);
	void Render(const Scene& scene, const Camera& camera);

	std::shared_ptr<MiniGameEngine::Image> getFinalImage() const { return outputImage; }
private:
	glm::vec4 traceRay(const Scene& scene, const Ray& ray);

	float intersect(glm::vec3 position, glm::vec3 direction);
private:
	std::shared_ptr<MiniGameEngine::Image> outputImage;
	uint32_t* imageData = nullptr;
};
