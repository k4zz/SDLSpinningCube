cmake_minimum_required(VERSION 3.20)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

project(SDLSpinningCube)

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)
add_compile_options(-Wpedantic)

set(src src/main.cpp src/CApp.cpp src/CApp.h src/ErrorCodes.h src/Logic.cpp)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} SDL2::Main)