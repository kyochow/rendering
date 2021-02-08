#  一个忽明忽暗的的三角形

#### Uniform
由CPU直接传入GPU的值


glfwGetTime();

可以获取系统时间

// 更新uniform颜色
float timeValue = glfwGetTime();
float greenValue = sin(timeValue) / 2.0f + 0.5f;
//先获取uniform字段所在的位置
int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//设置颜色
glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
