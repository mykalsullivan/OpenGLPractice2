cmake_minimum_required(VERSION 3.28)
project(OpenGLPractice2)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
        ${OPENGL_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
)

add_executable(OpenGLPractice2
        src/main.cpp
)

target_link_libraries(OpenGLPractice2
        glfw
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        libGLEW.so
)