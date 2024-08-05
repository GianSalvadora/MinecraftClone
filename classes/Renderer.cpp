#include "../headers/Renderer.h"

#include "Shader.h"
GLfloat vertices[] = {
    // Positions          // Texture Coords
    -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, 0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, 0.5f,  0.0f, 1.0f,
    0.5f,  0.5f, 0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
   0.5f,  0.5f, -0.5f,  1.0f, 1.0f,

    -0.5f, 0.5f, -0.5f,  0.0f, 0.0f,
    0.5f, 0.5f, -0.5f,  1.0f, 0.0f,
   -0.5f,  0.5f, 0.5f,  0.0f, 1.0f,
   0.5f,  0.5f, 0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
   0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
  -0.5f,  -0.5f, 0.5f,  0.0f, 1.0f,
  0.5f,  -0.5f, 0.5f,  1.0f, 1.0f,

    0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
   0.5f, 0.5f, -0.5f,  1.0f, 0.0f,
  0.5f,  -0.5f, 0.5f,  0.0f, 1.0f,
  0.5f,  0.5f, 0.5f,  1.0f, 1.0f,

 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
  -0.5f, 0.5f, -0.5f,  1.0f, 0.0f,
 -0.5f,  -0.5f, 0.5f,  0.0f, 1.0f,
 -0.5f,  0.5f, 0.5f,  1.0f, 1.0f,
};
GLuint indices[] = {
    // Front face
    0, 1, 2, 1, 2, 3,
    // Back face
    4, 5, 6, 5, 6, 7,
    // Top face
    8, 9, 10, 9, 10, 11,
    // Bottom face
    12, 13, 14, 13, 14, 15,
    // Right face
    16, 17, 18, 17, 18, 19,
    // Left face
    20, 21, 22, 21, 22, 23
};

Renderer::Renderer() : vao(), vbo(vertices, sizeof(vertices)), ibo(indices, sizeof(indices)){
    vao = VAO();
    vao.Bind();
    vbo = VBO(vertices, sizeof(vertices));
    vao.LinkAttributePointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0); // vertices
    vao.LinkAttributePointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(GLfloat))); // texture
    ibo = IBO(indices, sizeof(indices));

}
void Renderer::RenderCube(Texture cubeTexture, glm::vec3 position, Shader shader) {
    vao.Bind();
    cubeTexture.Bind();

    glm::mat4 model = glm::mat4(1.0f); // Start with an identity matrix
    model = glm::translate(model, position); // Translate to the desired position

    // Set the uniform
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

    cubeTexture.Unbind();
    vao.Unbind();
}
