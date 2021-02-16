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
    
    void SetEuler(float pitch,float yaw);
    
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
    
    float Pitch;
    float Yaw;
    float MouseSensitivity = 0.1;
    
    glm::mat4 GetViewMatrix();
    

    void ProcessMouseMovement(float xoffset, float yoffset)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   -= xoffset;
        Pitch += yoffset;
        updateCameraVectors();
    }
    
private :
    void updateCameraVectors()
    {
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Forward = glm::normalize(front);
        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Forward, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = glm::normalize(glm::cross(Right, Forward));
    }
};
