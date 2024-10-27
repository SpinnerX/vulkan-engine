#include <vulkan-engine/Random.hpp>

namespace MiniGameEngine {

	std::mt19937 Random::_randomEngine;
	std::uniform_int_distribution<std::mt19937::result_type> Random::_distrbution;

}
