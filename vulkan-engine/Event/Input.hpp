#pragma once

#include <vulkan-engine/Event/KeyCodes.hpp>
#include <glm/glm.hpp>

namespace MiniGameEngine{
	class Input{
	public:
		static bool isKeyPressed(KeyCode keycode);
		static bool isMouseButtonPressed(MouseButton button);

		static glm::vec2 getMousePosition();

		static void setCursorMode(CursorMode mode);
	};
};
