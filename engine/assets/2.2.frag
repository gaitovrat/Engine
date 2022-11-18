#version 330

out vec4 frag_colour;

in vec3 ex_worldNormal;
in vec4 ex_worldPosition;

uniform vec3 eye;
uniform vec3 light;

void main () 
{
    vec3 lightPosition = light;
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    vec4 color = vec4(.385, .647, .812, 1.);
    vec4 ambient = vec4(.1, .1, .1, 1.);
    vec3 normalVector = normalize(ex_worldNormal);  
    int h = 1;
    vec4 specular = vec4(.0, .0, .0, .0);

    float dotProduct = max(dot(lightVector, normalVector), 0);
    vec4 diffuse = dotProduct * color;
    float specularStrength = 0.5;
    vec3 view = normalize(eye - vec3(ex_worldPosition));
    vec3 reflection = reflect(-lightVector, normalVector);
    float spec = pow(max(dot(view, reflection), 0), h);
    specular = specularStrength * spec * color;
    
    frag_colour = ambient + diffuse + specular;
}