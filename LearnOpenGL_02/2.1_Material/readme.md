#  Material 材质

OpenGL支持材质，包含材质的必备属性，类似这样

```
//shader中定义结构体
struct Material{
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  **float** shininess;
};
//这样定义属性
uniform Material material;
//类似这样使用
vec3 ambient = material.ambient  * ambientColor;
```

在外面这样向shader里传入

```
shader.setVec3("material.ambient",1.0f,1.0f,1.0f);
shader.setVec3("material.diffuse",1.0f,1.0f,1.0f);
shader.setVec3("material.specular",1.0f,1.0f,1.0f);
shader.setFloat("material.shininess",32.0f);
```

