#include "../headers/IBO.h"

IBO::IBO(GLuint *vertices, GLsizeiptr size) {
    glGenBuffers(1, &ID);
    IBO::Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void IBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IBO::Delete() {
    glDeleteBuffers(1, &ID);
}

