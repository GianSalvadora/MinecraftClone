#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

#include "../lib/glfw-3.4/src/internal.h"

class Texture {
public:
    GLuint ID;
    Texture(const char* fileName, GLenum activeTexture);
    void Bind();
    void Unbind();
    void Delete();

private:
    int textureWidth, textureHeight, textureColorChannel;
    unsigned char* imageData;
    unsigned char* ReadFile(const char* fileName);
};
#endif //TEXTURE_H
