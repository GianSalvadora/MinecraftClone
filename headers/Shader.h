#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>

std::string ReadFile(const char* fileName);

class Shader {
    public:
        GLuint ID;
        Shader(const char* vertexFile, const char* fragmentFile);
        void Activate();
        void Delete();

};

#endif //SHADER_H
