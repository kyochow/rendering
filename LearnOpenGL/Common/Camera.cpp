//
//  Camera.cpp
//  7.1_Camera
//
//  Created by yons on 16.2.21.
//

#include "Camera.h"

Camera::Camera(glm::vec3 position,glm::vec3 target,glm::vec3 worldup)
{
    Position = position;
    WorldUp = worldup;
    Forward = glm::normalize(target - position);
    Right = glm::normalize(glm::cross(worldup, Forward));
    Up = glm::normalize(glm::cross(Forward, Right));
}

glm::mat4 Camera::GetViewMatrix(){
    return glm::lookAt(Position, Position + Forward, Up);
}
