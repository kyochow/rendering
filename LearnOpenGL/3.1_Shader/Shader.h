#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>

#endif /* Shader_hpp */

class Shader
{
public:
    Shader();
    Shader(const char* vertexPath,const char* fragmentPath);
    
    const char* vShaderCode;
    const char* fShaderCode;
};
