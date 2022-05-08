cmake_minimum_required(VERSION 3.10)

project(pbrt VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#set(CMAKE_ENABLE_EXPORTS ON)

enable_testing()

add_subdirectory(vendor/googletest)

add_subdirectory(src/lights)
add_subdirectory(src/volumes)
#add_subdirectory(src/renderers)

add_library(pbrt
        #src/core/Scene.cpp src/core/Scene.h
        src/core/Primitive.cpp src/core/Primitive.h
        src/core/Ray.cpp src/core/Ray.h
        src/core/Intersection.cpp src/core/Intersection.h
        src/core/Geometry.cpp src/core/Geometry.h
        #src/core/Renderer.h
        src/core/Parallel.cpp src/core/Parallel.h
        src/core/Transform.cpp src/core/Transform.h
        src/core/Error.h src/core/Error.cpp
        src/core/Vector.cpp src/core/Vector.h)

target_link_libraries(pbrt PUBLIC
        lights
        volumes
        #renderers
        )

add_executable(pbrtapp src/main/pbrt.cpp)
target_link_libraries(pbrtapp PUBLIC pbrt)

add_subdirectory(tests)

target_include_directories(pbrt PUBLIC src)