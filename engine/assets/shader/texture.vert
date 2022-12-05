#version 330

layout(location=0) in vec3 position;
layout(location=2) in vec2 textureCoordinates;

out vec2 ex_textureCoordinates;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main () 
{
    ex_textureCoordinates = textureCoordinates;

    gl_Position = projection * view * model * vec4(position, 1.0f);
}
