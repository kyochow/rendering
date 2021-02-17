#  贴图(Texture)

多贴图

OpenGL 有16个贴图预留位置（纹理单元，俗称贴图槽），最多可以同时使用16张贴图

需要想下面这样做

`glActiveTexture(GL_TEXTURE0);                   //先激活第一个槽`
`glBindTexture(GL_TEXTURE_2D, texture1); 		//绑定`
`glActiveTexture(GL_TEXTURE1);                   //再激活第二个槽`
`glBindTexture(GL_TEXTURE_2D, texture2); 		//绑定`

有两种方式为每个槽设置贴图

`glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0); // 手动设置`
`ourShader.setInt("texture2", 1); 								// 或者使用着色器类设置`



默认的纹理上下颠倒了！这是因为OpenGL要求y轴0.0坐标是在图片的底部的，但是图片的y轴0.0坐标通常在顶部。stb_image.h能够在图像加载时帮助我们翻转y轴，只需要在加载任何图像前加入以下语句即可：

stbi_set_flip_vertically_on_load(true);




