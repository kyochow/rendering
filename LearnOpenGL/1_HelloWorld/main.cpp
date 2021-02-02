#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, const char * argv[]) {
    GLFWwindow* win;
    //初始化GLFW
    if(!glfwInit()){
        return -1;
    }
    //创建Window
    win = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if(!win)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    //初始化GLEW
    if(!glewInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(win);
    
    //保持窗口打开状态
    while(!glfwWindowShouldClose(win)){
        glfwPollEvents();
    }
    
    //退出
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
