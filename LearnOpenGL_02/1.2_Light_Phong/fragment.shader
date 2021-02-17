#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

//环境光（天光）
uniform vec3 ambientColor;
//物体颜色
uniform vec3 objectColor;

uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{
    //计算环境光
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * ambientColor;
    
    //计算光的方向
    vec3 lightDir = normalize(lightPos - FragPos);
    //计算漫反射
    vec3 diffuseColor = max(dot(lightDir,Normal),0.0) * lightColor;
    
    //最终颜色混合
    vec3 finalColor = (ambient + diffuseColor) * objectColor;
    FragColor = vec4(finalColor,1.0f);
}
