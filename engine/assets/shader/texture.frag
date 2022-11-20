#version 330

out vec4 frag_colour;

in vec3 ex_worldNormal;
in vec4 ex_worldPosition;
in vec2 ex_textureCoordinates;
in vec3 ex_tangent;

uniform sampler2D textureID;

void main () 
{
	frag_colour = texture(textureID, ex_textureCoordinates);
}