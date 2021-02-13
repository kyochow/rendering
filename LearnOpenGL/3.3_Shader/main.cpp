#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include "Shader.h"
#include "define.h"
//VBO Data
float vertices[] = {
    -0.5f, -0.5f, 0.0f    , 1.0f, 0.0f, 0.0f,   // 右下
     0.5f, -0.5f, 0.0f    , 0.0f, 1.0f, 0.0f,   // 左下
     0.0f,  0.5f, 0.0f    , 0.0f, 0.0f, 1.0f    // 顶部
};
//EBO Data
unsigned int indices[] = {
    0,1,2
};

int main(int argc, const char * argv[]) {
    std::cout << "start \n" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow* win = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if(!win)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(win);
    
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
        return -1;
    
    glViewport(0, 0, 800, 600);
    
    const char* folderPath = "3.3_Shader/";
    
    const char* vertexName = "vertex.shader";
    char vertexFullPath[1024];
    sprintf(vertexFullPath, "%s%s%s", PROJECT_ROOT,folderPath,vertexName);

    const char* fragmentName = "fragment.shader";
    char fragmentFullPath[1024];
    sprintf(fragmentFullPath, "%s%s%s", PROJECT_ROOT,folderPath,fragmentName);
    
    Shader shader = Shader(vertexFullPath,fragmentFullPath);
    
    
    unsigned int VAO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    
    unsigned int VBO;
    glGenBuffers(1,&VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //这部分就是绑定EBO
    unsigned int EBO;
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    shader.use();
    
    while(!glfwWindowShouldClose(win)){
        glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
        glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
