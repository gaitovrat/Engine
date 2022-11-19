#version 330

#define MAX_LIGHTS 8

#define POINT_LIGHT 0

struct Light 
{
    vec3 position;
	
	float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    int lightType;
};

out vec4 frag_colour;

in vec3 ex_worldNormal;
in vec4 ex_worldPosition;

uniform vec3 eye;

uniform Light lights[MAX_LIGHTS];
uniform int lightsSize;

float attenuation (float c, float l, float q, float dist){
    float att = 1.0/(c + l * dist + q * dist * dist );
    return max(att, 0.0);
}

vec3 calculatePointLight(vec3 viewVector, vec3 color, Light light)
{
    // ambient
    vec3 ambient = light.ambient;

    // diffuse
    vec3 normal = normalize(ex_worldNormal);
    vec3 lightPosition = light.position;
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    float diff = max(dot(normal, lightVector), 0.0);
    vec3 diffuse = light.diffuse * diff * color;

    // specular
    vec3 reflectDirecton = reflect(-lightVector, normal);
    float spec = pow(max(dot(viewVector, reflectDirecton), 0.0), 32);
    vec3 specular = light.specular * spec * color;  
    
    // attenuation
    float dist = length(light.position - vec3(ex_worldPosition));
    float attenuation = attenuation(light.constant, light.linear, light.quadratic, dist);    

    ambient *= attenuation;  
    diffuse *= attenuation;
    specular *= attenuation;   
        
    return ambient + diffuse + specular;
}

void main () 
{
    vec3 viewVector = normalize(eye - vec3(ex_worldPosition));
    vec3 color = vec3(0.385, 0.647, 0.812);

    vec3 result = vec3(0.0);
    for (int i = 0; i < lightsSize; i++)
        result += calculatePointLight(viewVector, color, lights[i]);

    /*frag_colour = vec4(0.5, 0.5, 0.5, 1.0);*/
    frag_colour = vec4(result, 1.0);
}