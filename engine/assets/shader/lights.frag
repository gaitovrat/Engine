#version 330

#define MAX_LIGHTS 8

#define POINT_LIGHT 0
#define DIRECTIONAL_LIGHT 1
#define SPOT_LIGHT 2

struct Light 
{
    vec3 position;
    vec3 direction;

    float cutOff;
    float outerCutOff;
	
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
in vec2 ex_textureCoordinates;
in vec3 ex_tangent;

uniform vec3 eye;
uniform sampler2D textureID;

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

vec3 calculateDirectionalLight(vec3 viewVector, vec3 color, Light light)
{
    vec3 lightDirection = normalize(-light.direction);
    vec3 ambient = light.ambient;
    
    // diffuse shading
    vec3 normal = normalize(ex_worldNormal);
    vec3 lightPosition = light.position;
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    float diff = max(dot(normal, lightVector), 0.0);
    vec3 diffuse = light.diffuse * diff * color;

    // specular shading
    vec3 reflectDirecton = reflect(-lightVector, normal);
    float spec = pow(max(dot(viewVector, reflectDirecton), 0.0), 32);
    vec3 specular = light.specular * spec * color;
    
    return (ambient + diffuse + specular);
}

vec3 calculateSpotLight(vec3 viewVector, vec3 color, Light light)
{
    vec3 lightPosition = light.position;
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    vec3 normal = normalize(ex_worldNormal);

    float theta = dot(lightVector, normalize(-light.direction)); 
    vec3 result;
    if(theta > light.cutOff)
    {
        vec3 ambient = light.ambient;
    
        float diff = max(dot(lightVector, normal), 0.0);
        vec3 diffuse = light.diffuse * diff * color;
    
        vec3 reflectVector = reflect(-lightVector, normal);
        float spec = pow(max(dot(viewVector, reflectVector), 0.0), 32);
        vec3 specular = light.specular * spec * color;

        float dist = length(light.position - vec3(ex_worldPosition));
        float attenuation = attenuation(light.constant, light.linear, light.quadratic, dist);
    
        diffuse *= attenuation;
        specular *= attenuation;
        
        result = vec3(ambient + diffuse + specular);

    }
    else
    {
       result = vec3(light.ambient);
    }

    return result;
}

void main () 
{
    vec3 viewVector = normalize(eye - vec3(ex_worldPosition));
    vec3 color = vec3(0.385, 0.647, 0.812);

    vec3 result = vec3(0.0);
    for (int i = 0; i < lightsSize; i++)
    {
        if (lights[i].lightType == DIRECTIONAL_LIGHT) 
        {
            result += calculateDirectionalLight(viewVector, vec3(texture(textureID, ex_textureCoordinates)), lights[i]);
        } 
        else if (lights[i].lightType == POINT_LIGHT)
        {
            result += calculatePointLight(viewVector, vec3(texture(textureID, ex_textureCoordinates)), lights[i]);
        } 
        else
        {
            result += calculateSpotLight(viewVector, vec3(texture(textureID, ex_textureCoordinates)), lights[i]);
        }
    }

    /*frag_colour = vec4(0.5, 0.5, 0.5, 1.0);*/
    frag_colour = vec4(result, 1.0);
}