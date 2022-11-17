#version 330

out vec4 frag_colour;

in vec3 ex_worldNormal;
in vec4 ex_worldPosition;

uniform vec3 light;

void main () 
{
    vec3 lightPosition = light;
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    float dotProduct = max(dot(lightVector, normalize(ex_worldNormal)), 0);

    vec3 diffuse = dotProduct * vec3(0.385,0.647 ,0.812);
    vec3 ambient = vec3(0.1, 0.1, 0.1);
    
    vec3 color = ambient + diffuse;
    frag_colour = vec4(color, 1);
}