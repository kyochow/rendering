#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 uv;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = texture(texture2, uv);
}
