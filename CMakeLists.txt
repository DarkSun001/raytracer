cmake_minimum_required(VERSION 3.16)
project(raytracer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(catch2)

FetchContent_Declare(
  lodepng
  GIT_REPOSITORY https://github.com/lvandeve/lodepng.git
  GIT_TAG master
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(lodepng)

add_library(lodepng STATIC ${lodepng_SOURCE_DIR}/lodepng.cpp)
target_include_directories(lodepng PUBLIC ${lodepng_SOURCE_DIR})

add_library(raytracer_lib
  src/vector.cpp
  src/colour.cpp
  src/sphere.cpp
  src/plane.cpp
  src/camera.cpp
  src/scene.cpp
  src/shading.cpp
  src/render.cpp
  src/image.cpp
  src/png_image_writer.cpp
)
target_include_directories(raytracer_lib PUBLIC include)
target_link_libraries(raytracer_lib PUBLIC lodepng)

add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_lib)

enable_testing()
include(CTest)

add_executable(unit_tests
  tests/vector_tests.cpp
  tests/sphere_tests.cpp
  tests/plane_tests.cpp
  tests/shading_tests.cpp
  tests/image_tests.cpp
)
target_link_libraries(unit_tests PRIVATE raytracer_lib Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(unit_tests)
