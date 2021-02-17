#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include "shader.h"
#include "camera.h"
#include "define.h"
#include "inputs.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int argc, const char * argv[]) {
    
    auto win = initGL();
    glEnable(GL_DEPTH_TEST); // 这里需要开启Z Test
    //隐藏掉鼠标
    glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(win, mouse_callback);
    glViewport(0, 0, 800, 600);
    
    Shader shader = Shader("1.1_Light/");
    
    unsigned int VAO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    
    unsigned int VBO;
    glGenBuffers(1,&VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    //这里用来取UV
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    unsigned int textureA = loadImage("Arts/container.jpg",GL_RGB,GL_RGB);
    unsigned int textureB = loadImage("Arts/awesomeface.png",GL_RGBA,GL_RGBA);
    
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glm::vec3 cubePositions[] = {
      glm::vec3( 0.0f,  0.0f,  0.0f),
      glm::vec3( 2.0f,  5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f),
      glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3( 2.4f, -0.4f, -3.5f),
      glm::vec3(-1.7f,  3.0f, -7.5f),
      glm::vec3( 1.3f, -2.0f, -2.5f),
      glm::vec3( 1.5f,  2.0f, -2.5f),
      glm::vec3( 1.5f,  0.2f, -1.5f),
      glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    
    //Player Loop
    while(!glfwWindowShouldClose(win)){
        
        checkESC(win);
        processInput(win);
        
        caculateDeltaTime();
        
        //清屏
        glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
        //和之前不同的是不仅清楚颜色，还得清除深度缓冲值
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader.use();
        
        //V矩阵 设置一次就行
        glm::mat4 viewMat = camera.GetViewMatrix();
        shader.setMat4("viewMat",viewMat);
        
        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 modelMat; //M矩阵
            modelMat = glm::translate(modelMat, cubePositions[i]);
            modelMat = glm::rotate(modelMat, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
            
            //P矩阵
            glm::mat4 projMat = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);
            shader.setMat4("modelMat",modelMat);
            shader.setMat4("projMat",projMat);
            
            //绑定VAO
            glBindVertexArray(VAO);
            
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, textureA);
            shader.setInt("texture1", 0);
            
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, textureB);
            shader.setInt("texture2", 1);
            
            shader.setVec3("ambientColor", glm::vec3(1.0f, 1.0f, 1.0f));
            shader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
            
            //画
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
