#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <Shader.h>
#include <Camera.h>
#include <Renderer.h>

int main() {
    int windowHeight = 800;
    int windowWidth = 800;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Minecraft", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create a window" << std::endl;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, windowWidth, windowHeight);
    Shader shader("../shaders/default.vert", "../shaders/default.frag");
    Camera cam(windowWidth, windowHeight, glm::vec3(0.0f, 5.0f, 10.0f));
    Renderer renderer;

    double oldTime = glfwGetTime();
    Texture dirtTexture("../resources/dirt.png", GL_TEXTURE0);
    while (!glfwWindowShouldClose(window)) {
        double currentTime = glfwGetTime();
        if (currentTime - oldTime >= 1.0f / 60.0f) {
            oldTime = glfwGetTime();
            cam.Inputs(window);
        }

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        shader.Activate();
        cam.Matrix(80.0f, 0.1f, 100.0f, shader, "camMatrix");

        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < 10; y++) {
                for(int z = 0; z < 10; z++) {
                    renderer.RenderCube(dirtTexture, glm::vec3(x, y, z), shader);
                }
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shader.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
}

//do I really need to make a new VBO VAO IBO for everytime I render a cube?
//clean the system CLEAN CLEAN CLEAN
