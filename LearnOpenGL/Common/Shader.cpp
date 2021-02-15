//
//  Shader.cpp
//  Shader
//
//  Created by zhongliang.zhou on 2021/2/4.
//

#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const char* PROJ_ROOT ="/Users/yons/Documents/github/rendering/LearnOpenGL/";


Shader::Shader(const char* folderPath)
{
    const char* vertexName = "vertex.shader";
    const char* fragmentName = "fragment.shader";
    char vertexFullPath[1024];
    sprintf(vertexFullPath, "%s%s%s", PROJ_ROOT,folderPath,vertexName);
    char fragmentFullPath[1024];
    sprintf(fragmentFullPath, "%s%s%s", PROJ_ROOT,folderPath,fragmentName);
    genShader(vertexFullPath,fragmentFullPath);
}

Shader::Shader(const char* folderPath,const char* vertexName,const char* fragmentName)
{
    char vertexFullPath[1024];
    sprintf(vertexFullPath, "%s%s%s", PROJ_ROOT,folderPath,vertexName);
    char fragmentFullPath[1024];
    sprintf(fragmentFullPath, "%s%s%s", PROJ_ROOT,folderPath,fragmentName);
    genShader(vertexFullPath,fragmentFullPath);
}

void Shader::genShader(const char* vertexPath,const char* fragmentPath)
{
    // 1. 从文件路径中获取顶点/片段着色器
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // 保证ifstream对象可以抛出异常：
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // 打开文件
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // 读取文件的缓冲内容到数据流中
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // 关闭文件处理器
        vShaderFile.close();
        fShaderFile.close();
        // 转换数据流到string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    
    // 2. compile shaders
    unsigned int vertex, fragment;
    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec4(const std::string &name, float f1,float f2,float f3,float f4)const
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), f1,f2,f3,f4);
}

void Shader::setMat4(const std::string &name, glm::mat4 mat4)const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()),1,GL_FALSE,glm::value_ptr(mat4));
}
