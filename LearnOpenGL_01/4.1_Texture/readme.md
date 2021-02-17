#  贴图(Texture)



#### 贴图坐标

UV  = ST   坐标范围：（0 - 1）



#### 纹理环绕方式

GL_REPEAT    重复

GL_MIRRORED_REPEAT 也是重复，但是每次重复图片是镜像放置的

GL_CLAMP_TO_EDGE 约束在0-1之间，超出的部分重复纹理坐标的边缘，常用在无缝贴图上，消除接缝

GL_CLAMP_TO_BORDER  约束在0-1之间，超出的部分为用户指定颜色 (Unity未提供)



#### 纹理过滤(对应Unity里的Texure ImportSetting中的Filter Mode)



图片上的每一个位置显示的颜色是什么样的

GL_NEAREST,邻近过滤， (对应Unity中的Point) ，不做任何过滤，返回最近的像素颜色，一般只有2d游戏这样

GL_LINEAR，(双)线性过滤，(对应Unity中的Biliner)，找周围最邻近的几个像素，然后做均值



#### 多级渐远纹理(Mipmap)

当一个纹理，距离你很远的时候，是否可以做一些简化，没必要再采样那么多的点

这样在远处做邻近采样的时候，就会比较省了

GL_NEAREST_MIPMAP_NEAREST  使用最邻近的多级渐远纹理来匹配像素大小，并使用邻近插值进行纹理采样

GL_LINEAR_MIPMAP_NEAREST 使用最邻近的多级纹理级别，并使用先行插值采样

GL_NEAREST_MIPMAP_LINEAR  在两个最匹配像素大小的多级渐近纹理之间进行线性采样，使用邻近插值进行采样

GL_LINEAR_MIPMAP_LINEAR 在两个邻近的多级渐近纹理之间使用线性插值，并使用线性插值采样

所以 ：GL_LINEAR_MIPMAP_LINEAR  ==  Unity中的 Triliner （三次线性过滤，第三维度处理mipmap）



#### 读取image 文件

使用stb_image.h库  一个单头文件的图片加载库
