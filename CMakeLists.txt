cmake_minimum_required(VERSION 3.12)

project(BlueMarble)

add_executable(BlueMarble sessao_2/aula_14.cpp)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(BlueMarble PRIVATE librays/stb librays/glm)
target_link_libraries(BlueMarble GLEW::glew
                                 glfw
                                 OpenGL::OpenGL)
