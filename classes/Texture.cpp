#include "../headers/Texture.h"


unsigned char* Texture::ReadFile(const char* fileName) {
    unsigned char* data = stbi_load(fileName, &textureWidth, &textureHeight, &textureColorChannel, 0);
    if (!data) {
        std::cerr << stbi_failure_reason() << std::endl;
    }

    return data;
}

Texture::Texture(const char *fileName, GLenum activeTexture) {
    glGenTextures(1, &ID);
    glActiveTexture(activeTexture);
    Texture::Bind();
    imageData = ReadFile(fileName);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(imageData);
}

void Texture::Bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete() {
    glDeleteTextures(1, &ID);
}
