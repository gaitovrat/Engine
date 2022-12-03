#version 330

out vec4 frag_colour;

in vec3 ex_position;

uniform samplerCube textureID;

void main () 
{
	frag_colour = texture(textureID, ex_position);
}
