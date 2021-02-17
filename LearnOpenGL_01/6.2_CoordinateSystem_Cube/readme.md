#  旋转的Cube

## Z-buffer 深度缓冲

OpenGL存储它的所有深度信息于一个Z缓冲(Z-buffer)中，也被称为深度缓冲(Depth Buffer)

OpenGL已经提供了对应的API

`glEnable(GL_DEPTH_TEST);`

因为我们使用了深度测试，我们也想要在每次渲染迭代之前清除深度缓冲（否则前一帧的深度信息仍然保存在缓冲中）。就像清除颜色缓冲一样，我们可以通过在glClear函数中指定DEPTH_BUFFER_BIT位来清除深度缓冲：
`glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);`



对应 Unity中

Camera的Clear Flag设置

SkyBox = glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清理颜色和深度信息 补天空盒颜色

Solid Color = glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清理颜色和深度信息，补纯色

Depth Only = glClear(GL_DEPTH_BUFFER_BIT ）只清理深度信息，不清理颜色

Don‘t Clear 就是完全不清理
