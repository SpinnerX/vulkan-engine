#pragma once
#include <vulkan-engine/Layer.hpp>
#include "vulkan-engine/Timer.hpp"

#include "Renderer.hpp"
#include "Camera.hpp"

#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public MiniGameEngine::Layer{
public:
	ExampleLayer();

	virtual void onUpdate(float ts) override;

	virtual void onUIRender() override;

	void Render();

private:
	Renderer renderer;
	Camera camera;
	Scene scene;
	uint32_t viewportWidth = 0, viewportHeight = 0;

	float lastRenderTime = 0.0f;
};
