#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPos;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
    //从右向左
    gl_Position = projMat * viewMat * modelMat * vec4(aPos,1.0);
    FragPos = mat3(modelMat) * aPos;
    //法线矩阵
    Normal =mat3(transpose(inverse(modelMat))) * aNormal;

}
