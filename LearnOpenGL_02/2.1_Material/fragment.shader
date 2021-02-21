#version 330 core
struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform Material material;

//环境光（天光）
uniform vec3 ambientColor;
//物体颜色
uniform vec3 objectColor;

uniform vec3 lightColor;
uniform vec3 lightPos;

uniform vec3 viewPos;
void main()
{
    //计算环境光
    float ambientStrength = 0.1;
    vec3 ambient = material.ambient * ambientStrength * ambientColor;
    
    //计算光的方向
    vec3 lightDir = normalize(lightPos - FragPos);
    //计算漫反射
    vec3 diffuseColor = material.diffuse * max(dot(lightDir,Normal),0.0) * lightColor;
    
    //计算高光反射
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, Normal);
    
    float specularStrength = 0.5;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = material.specular * specularStrength * spec * lightColor;
    //最终颜色混合
    vec3 finalColor = (ambient + diffuseColor + specular) * objectColor;
    FragColor = vec4(finalColor,1.0f);
}
