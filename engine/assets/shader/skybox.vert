#version 330

layout(location=0) in vec3 position;

out vec3 ex_position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main () 
{
    ex_position = position;

    gl_Position = projection * mat4(mat3(view)) * vec4(position, 1.0f);
}
