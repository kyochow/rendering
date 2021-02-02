#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

const char* vertexShaderSource =
"#version 330 core                                      \n"
"layout (location = 0) in vec3 aPos;                    \n"
"void main(){                                           \n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);   \n"
"} \n";

const char* fragmentShaderSource=
"#version 330 core                                      \n"
"out vec4 FragColor;                                \n"
"void main(){                                       \n"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);      \n"
"} \n";

int main(int argc, const char * argv[]) {
    GLFWwindow* win;
    if(!glfwInit()){
        return -1;
    }
    win = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if(!win)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glewExperimental = GL_TRUE;
    glfwMakeContextCurrent(win);
    
    if(glewInit() != GLEW_OK)
        return -1;
    
    glViewport(0, 0, 800, 600);
    
    unsigned int VAO;
    glGenVertexArrays(1,&VAO);
    
    
    unsigned int VBO;
    //返回数组的第一个地址给int
     glGenBuffers(1,&VBO);
     glBindVertexArray(VAO);
     glBindBuffer(GL_ARRAY_BUFFER,VBO);
     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
     
     //编译上面的顶点着色器
     unsigned int vertexShader;
     vertexShader = glCreateShader(GL_VERTEX_SHADER);
     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
     glCompileShader(vertexShader);
     
     //编译上面的片段着色器
     unsigned int fragmentShader;
     fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
     glCompileShader(fragmentShader);
     
     
     //创建一个shader程序
     unsigned int shaderProgram;
     shaderProgram = glCreateProgram();
     
     //连接顶点和片段着色器
     glAttachShader(shaderProgram, vertexShader);
     glAttachShader(shaderProgram, fragmentShader);
     glLinkProgram(shaderProgram);
    
    //参数含义
    //第一个参数，表示开始的索引 0
    //每一块是几个元素   3
    //每一个元素的类型   float
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    
    while(!glfwWindowShouldClose(win)){
        glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
