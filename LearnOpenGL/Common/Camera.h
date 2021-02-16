#pragma once
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    Camera(glm::vec3 position,glm::vec3 target,glm::vec3 worldup);
    Camera(glm::vec3 position,float pitch,float yaw,glm::vec3 worldup);
    
    //摄像机位置
    glm::vec3 Position;
    //摄像机方向
    glm::vec3 Forward;
    //右轴向量
    glm::vec3 Right;
    //上轴向量
    glm::vec3 Up;
    //世界上轴方向
    glm::vec3 WorldUp;
    
    glm::mat4 GetViewMatrix();
};
