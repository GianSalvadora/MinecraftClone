#include "../headers/VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

void VAO::Bind() {
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::LinkAttributePointer(GLuint layout, GLuint size, GLenum type, GLboolean normalized, GLsizeiptr stride, void* offset) {
    glVertexAttribPointer(layout, size, type, normalized, stride, offset);
    glEnableVertexAttribArray(layout);
}

void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);
}


