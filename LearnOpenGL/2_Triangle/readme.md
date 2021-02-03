#  关键词

顶点数组对象：Vertex Array Object，VAO
顶点缓冲对象：Vertex Buffer Object，VBO
索引缓冲对象：Element Buffer Object，EBO或Index Buffer Object，IBO


在OpenGL中，任何事物都在3D空间中，而屏幕和窗口却是2D像素数组，这导致OpenGL的大部分工作都是关于把3D坐标转变为适应你屏幕的2D像素

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/2_Triangle/pipeline.png)

图形渲染管线可以被划分为两个主要部分：
- 第一部分把你的3D坐标转换为2D坐标
- 第二部分是把2D坐标转变为实际的有颜色的像素




这两句话到底干了什么？
VBO是从CPU传递过来的，只是一个一维数组

需要绑定为VAO

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/2_Triangle/vertex_attribute_pointer.png)


//参数含义
//第一个参数，表示开始的索引 0
//每二块是几个元素   3 ，表示从VBO里，每三个栏位组成一个pack
//每三个元素的类型   float
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);


