

set(
    all_headers
    ../vulkan-engine/Application.hpp
    ../vulkan-engine/EntryPoint.hpp
    ../vulkan-engine/Layer.hpp
    ../vulkan-engine/Random.hpp
    ../vulkan-engine/Timer.hpp
    ../vulkan-engine/UUID.hpp

    ../vulkan-engine/Event/Input.hpp
    ../vulkan-engine/Event/KeyCodes.hpp
    ../vulkan-engine/Image/Image.hpp
    ../vulkan-engine/Image/stb_image.h
)

set(
    all_src
    vulkan-engine/Application.cpp
    vulkan-engine/Random.cpp
    vulkan-engine/UUID.cpp
    vulkan-engine/Image/Image.cpp
    vulkan-engine/Image/stb_image.cpp

    vulkan-engine/Event/Input.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src})
