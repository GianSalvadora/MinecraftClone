cmake_minimum_required(VERSION 3.28)
project(Minecraft_1)

set(CMAKE_CXX_STANDARD 17)

# External libraries
add_subdirectory(lib/glfw-3.4)
add_subdirectory(lib/glm)

# GLAD library
add_library(glad STATIC lib/glad/src/glad.c)

# STB library
add_library(stb STATIC lib/stb/stb.cpp)

# Main executable
add_executable(Minecraft_1
        main.cpp
        headers/Shader.h
        classes/Shader.cpp
        headers/VBO.h
        classes/VBO.cpp
        headers/VAO.h
        classes/VAO.cpp
        headers/IBO.h
        classes/IBO.cpp
        headers/Texture.h
        classes/Texture.cpp
        headers/Camera.h
        classes/Camera.cpp
        headers/Renderer.h
        classes/Renderer.cpp
)

# Link libraries
target_link_libraries(Minecraft_1 PRIVATE glfw glad stb glm)

# Include directories
target_include_directories(Minecraft_1 PRIVATE headers)
target_include_directories(glad PUBLIC lib/glad/include)
target_include_directories(stb PUBLIC lib/stb)
