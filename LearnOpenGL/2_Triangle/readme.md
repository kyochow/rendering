#  关键词

顶点数组对象：Vertex Array Object，VAO
顶点缓冲对象：Vertex Buffer Object，VBO
索引缓冲对象：Element Buffer Object，EBO或Index Buffer Object，IBO


在OpenGL中，任何事物都在3D空间中，而屏幕和窗口却是2D像素数组，这导致OpenGL的大部分工作都是关于把3D坐标转变为适应你屏幕的2D像素

图形渲染管线可以被划分为两个主要部分：
- 第一部分把你的3D坐标转换为2D坐标
- 第二部分是把2D坐标转变为实际的有颜色的像素



