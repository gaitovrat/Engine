#version 330

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;

out vec4 ex_worldPosition;
out vec3 ex_worldNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main () 
{
    vec4 l_position = vec4(position, 1.0f);

    ex_worldPosition = model * l_position;
    ex_worldNormal = normalize(transpose(inverse(mat3(model))) * normal);

    gl_Position = projection * view * model * l_position;
}
