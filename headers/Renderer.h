#ifndef RENDERER_H
#define RENDERER_H
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <VBO.h>
#include <VAO.h>
#include <Shader.h>
#include <IBO.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Texture.h>

class Renderer{
public:
    VAO vao;
    VBO vbo;
    IBO ibo;
    void RenderCube(Texture cubeTexture, glm::vec3 position, Shader shader);
    Renderer();
};

#endif //RENDERER_H
