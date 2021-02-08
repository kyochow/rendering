#  一个顶点色的三角形

![vertex_attribute_pointer_interleaved](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/3.3_Shader/vertex_attribute_pointer_interleaved.png)





关键代码



`glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);` 

`glEnableVertexAttribArray(0); // 颜色属性` 

`glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float))); glEnableVertexAttribArray(1);`





同时，vertex shader里也需要使用对应位置的寄存器

两段对比

- 分别使用寄存器0和寄存器1

- 每次依然要三个字段
- 都是float类型
- 不需要间隙
- 步长变成了6*float size
- offset分别为0和3个float size

