#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

//环境光
uniform vec3 ambientColor;

//物体颜色
uniform vec3 objectColor;

uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{
    vec3 lightDir = normalize(lightPos - FragPos);
    
    vec3 diffuseColor = max(dot(lightDir,Normal),0.0) * lightColor;
    FragColor = vec4(diffuseColor,1.0f);
    //FragColor = vec4(ambientColor * objectColor,1.0f);
}
