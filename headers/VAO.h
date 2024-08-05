#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>

class VAO {
    public:
        GLuint ID;
        VAO();
        void Bind();
        void Unbind();
        void LinkAttributePointer(GLuint layout, GLuint size, GLenum type, GLboolean normalized, GLsizeiptr stride, void* offset);
        void Delete();
};

#endif //VAO_H
