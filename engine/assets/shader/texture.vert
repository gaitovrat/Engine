#version 330

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 textureCoordinates;
layout(location=3) in vec3 tangent;

out vec4 ex_worldPosition;
out vec3 ex_worldNormal;
out vec2 ex_textureCoordinates;
out vec3 ex_tangent;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main () 
{
    vec4 l_position = vec4(position, 1.0f);

    ex_worldPosition = model * l_position;
    ex_worldNormal = normalize(transpose(inverse(mat3(model))) * normal);
    ex_textureCoordinates = textureCoordinates;
    ex_tangent = tangent;

    gl_Position = projection * view * model * l_position;
}
