#version 330

out vec4 frag_colour;

in vec2 ex_textureCoordinates;

uniform sampler2D textureID;

void main () 
{
	frag_colour = texture(textureID, ex_textureCoordinates);
}
