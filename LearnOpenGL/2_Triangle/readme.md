#  核心内容

### 重要概念



- 顶点数组对象：Vertex Array Object，VAO
- 顶点缓冲对象：Vertex Buffer Object，VBO
- 索引缓冲对象：Element Buffer Object，EBO或Index Buffer Object，IBO

在OpenGL中，任何事物都在3D空间中，而屏幕和窗口却是2D像素数组，这导致OpenGL的大部分工作都是关于把3D坐标转变为适应你屏幕的2D像素

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/2_Triangle/pipeline.png)

**图形渲染管线可以被划分为两个主要部分：**

- 第一部分把你的3D坐标转换为2D坐标
- 第二部分是把2D坐标转变为实际的有颜色的像素





**glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);**
**glEnableVertexAttribArray(0);**
这两句话到底干了什么？
VBO是从CPU传递过来的，只是一个一维数组，需要绑定为VAO

下图就代表了一个VBO -> VAO的过程

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/2_Triangle/vertex_attribute_pointer.png)

- 位置数据被储存为32位（4字节）浮点值。

- 每个位置包含3个这样的值。

- 在这3个值之间没有空隙（或其他值）。这几个值在数组中紧密排列(Tightly Packed)。

- 数据中第一个值在缓冲开始的位置。

  

//参数含义
//第一个参数，POSITION 表示开始的索引 0
//第二参数，表示从VBO里，每3个栏位组成一个pack
//第三参数，栏位类型   float

//第四参数，是否需要归一化

//第五参数，STRIDE 每偏移多少个字节，去组成下一个pack

//第六参数，OFFSET 每一个pack的读取偏移，一般为0

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

glEnableVertexAttribArray(0); //开启





那么这个0 是怎么来的

这里有一个对应关系

Vertex Shader里 有这一段：

`layout (location = 0) in vec3 aPos;`

代码里有这一段：

`glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);`

`glEnableVertexAttribArray(0);`



这三个0是对应的，表示放在0号寄存器

也可以像下面这样写，表示使用15号寄存器，但不能超过15，因为一共16个寄存器可供使用

`layout (location = 15) in vec3 aPos;`

`glVertexAttribPointer(15, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);`

`glEnableVertexAttribArray(15);`
