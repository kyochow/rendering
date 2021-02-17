#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 uv;

uniform sampler2D texture1;

//环境光
uniform vec3 ambientColor;

//物体颜色
uniform vec3 objectColor;

void main()
{
    FragColor = texture(texture1, uv) * vec4(ambientColor * objectColor,1.0f);
}
