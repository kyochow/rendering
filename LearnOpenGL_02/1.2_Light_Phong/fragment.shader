#version 330 core
out vec4 FragColor;

in vec3 Normal;

//环境光
uniform vec3 ambientColor;

//物体颜色
uniform vec3 objectColor;

void main()
{
    FragColor = vec4(ambientColor * objectColor,1.0f);
}
