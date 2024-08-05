#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexture;


uniform mat4 camMatrix;
uniform mat4 modelMatrix;
out vec2 textureCoord;

void main()
{
    gl_Position =   camMatrix * modelMatrix * vec4(aPos, 1);
    textureCoord = aTexture;
}