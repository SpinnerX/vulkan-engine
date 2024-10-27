cmake_minimum_required(VERSION 3.15)
project(demo CXX)

set(
    all_src
    Application.cpp
    ExampleLayer.hpp
    ExampleLayer.cpp
    Renderer.cpp
    Camera.cpp
)

find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Vulkan REQUIRED)
find_package(imguidocking REQUIRED)
# find_package(engine3d REQUIRED)

add_executable(${PROJECT_NAME} ${all_src})

target_include_directories(${PROJECT_NAME} PRIVATE ../)

target_link_libraries(
    ${PROJECT_NAME}
    spdlog::spdlog
    glm::glm
    yaml-cpp::yaml-cpp
    imguidocking::imguidocking
    Vulkan::Vulkan
    engine3d
)
