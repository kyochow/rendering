#  



Tip:gl里剔除背面

glEnable(GL_CULL_FACE);  //开启面剔除

glCullFace(GL_BACK);         //剔除背面





#### EBO 索引缓存对象

Element Buffer Object



描述三角形，可以去掉重复的点，然后使用索引值来存储，这就是EBO，可以大量节约传输量



OpenGL,本质上是一个状态机

- 在同一时间，只有一个Context，一个Context只有一个VAO

CPU不断的往GPU里面传VBO，OpenGL依次处理

OpenGL拿到一个VBO，需要让它绑定显存中的一个VAO，形成一个绑定关系

这时候就可以Unbind了，OpenGL去处理下一个VBO，上一个VAO-VBO绑定就可以进入下一步渲染流水线了

VBO和VAO的生命周期由OpenGL维护



加入EBO，EBO可以协助 VBO和VAO的绑定，且占用单独的寄存空间



另外，还可以设置一系列开关，来影响整个渲染流程


 整体的图如下：来自傅老师
 
 ![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/2.1_Triangle_EBO/opengl_context.png)

