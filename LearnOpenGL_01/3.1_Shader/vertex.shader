#version 330 core
layout (location = 0) in vec3 aPos;

//额外传递给fragment shader的变量
out vec4 vertexColor;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); // 这个gl_Position是必须的
    vertexColor = vec4(1, 0, 0, 1.0);
}
