#version 330

/*struct Light {
    vec3 direction;
	
	float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};*/

out vec4 frag_colour;

in vec3 ex_worldNormal;
in vec4 ex_worldPosition;


uniform vec3 eye;
uniform vec3 light;

/*vec3 calculateDirectionLight(Light light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    return (ambient + diffuse + specular);
}

vec3 calculatePointLight(Light light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
  			     light.quadratic * (distance * distance));    

    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}*/

void main () {
    vec3 lightPosition = light;
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    vec4 color = vec4(.385, .647, .812, 1.);
    vec4 ambient = vec4(.1, .1, .1, 1.);
    vec3 normalVector = normalize(ex_worldNormal);  
    int h = 40;
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