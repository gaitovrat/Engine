#version 330

layout(location=0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main () 
{
    vec4 l_position = vec4(position, 1.0f);

    gl_Position = projection * view * model * l_position;
}
