#ifndef define_h
#define define_h

const char* PROJECT_ROOT ="/Users/yons/Documents/github/rendering/LearnOpenGL_02/";

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "camera.h"

float deltaTime = 0.0f;    // 当前帧与上一帧的时间差
float lastFrame = 0.0f;

Camera camera(glm::vec3(0,0,3.0f));


//计算delta time
void caculateDeltaTime(){
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

//初始化
GLFWwindow* initGL(){
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
    glewInit();
    
    
    return win;
}

//检查ecs按键是否被按下
void checkESC(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//加载一张贴图到GPU
unsigned int loadImage(const char* imgPath,GLint internalFormat,GLenum format){
    //申请贴图 第一张
    unsigned int texBuffer;
    glGenTextures(1, &texBuffer);
    glBindTexture(GL_TEXTURE_2D, texBuffer);//绑定
    
    char imgFullPath[1024];
    sprintf(imgFullPath, "%s%s", PROJECT_ROOT,imgPath);
    int width, height, nrChannels;
    //设置image loader库上下反转图片
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(imgFullPath, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return texBuffer;
}

#endif

