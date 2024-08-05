#ifndef IBO_H
#define IBO_H
#include <glad//glad.h>
class IBO{
public:
    GLuint ID;
    IBO(GLuint* vertices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();

};
#endif //IBO_H
