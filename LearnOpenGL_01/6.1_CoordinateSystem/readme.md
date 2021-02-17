#  坐标系统(Coordinate System)

## 概述

为了将坐标从一个坐标系变换到另一个坐标系，需要用到几个变换矩阵，最重要的几个分别是模型(Model)、观察(View)、投影(Projection)三个矩阵。另外几个常见的概念

- 局部空间(Local Space，或者称为物体空间(Object Space))

- 世界空间(World Space)

- 观察空间(View Space，或者称为视觉空间(Eye Space))

- 裁剪空间(Clip Space)

- 屏幕空间(Screen Space)

  

下面的这张图展示了整个流程以及各个变换过程做了什么



![坐标系统](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/6.1_CoordinateSystem/coordinate_systems.png)





## Local Coordinate 本地坐标

表示本物体相对于上一层的位置

## World Coordinate 世界坐标

就是世界中的绝对位置

对应的Unity。就是localPosition 和position的关系

从Local转为World，需要M矩阵(Model Matrix)



## View Coordinate 观察坐标

 就是把Camera当作远点，场景中所有的物体做相应的平移

例如 Camera位置 0 0 3，那场景中的物体，转换为观察坐标，则每一个物体的位置都加上 0 0 -3

从World Coordinate 转为View Coordination，需要 V 矩阵(View Matrix)



## Clip Coordinate 裁剪坐标

在一个顶点着色器运行的最后，OpenGL期望所有的坐标都能落在一个特定的范围(-1.0 到 1.0)内，就是NDC坐标，且任何在这个范围之外的点都应该被裁剪掉(Clipped),这个空间是裁剪空间，对应的坐标系就是裁剪坐标系



从View Coordination转为 Clip Coordinate 裁剪坐标系，需要P矩阵(Projection Matrix)



#### 投影矩阵(Projection Matrix)

指定了一个范围的坐标，比如在每个维度上的-1000到1000。投影矩阵接着会将在这个指定的范围内的坐标变换为标准化设备坐标的范围(-1.0, 1.0)，如果在范围外的就被裁掉了

PS:如果只是图元(Primitive)，例如三角形，的一部分超出了裁剪体积(Clipping Volume)，则OpenGL会重新构建这个三角形为一个或多个三角形让其能够适合这个裁剪范围。

由投影矩阵创建的**观察箱**(Viewing Box)被称为平截头体(Frustum)，每个出现在平截头体范围内的坐标都会最终出现在用户的屏幕上，将特定范围内的坐标转化到NDC的过程（而且它很容易被映射到2D观察空间坐标）被称之为投影(Projection)

一旦所有顶点被变换到裁剪空间，最终的操作——透视除法(Perspective Division)将会执行，在这个过程中我们将位置向量的x，y，z分量分别除以向量的齐次w分量



#### 正射投影

![正射投影](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/6.1_CoordinateSystem/orthographic_frustum.png)

正射投影矩阵定义了一个类似立方体的平截头箱，w = 1，glm代码：

`//前两个参数指定了平截头体的左右坐标，`

`//第三和第四参数指定了平截头体的底部和顶部`

`//第五和第六个参数则定义了近平面和远平面的距离`

`glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);`

#### 透视投影

![坐标系统](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL/6.1_CoordinateSystem/perspective_frustum.png)

离你越远的东西看起来更小。这个奇怪的效果称之为透视(Perspective)，使用透视投影矩阵来完成投影，这个投影矩阵将给定的平截头体范围映射到裁剪空间，除此之外还修改了每个顶点坐标的w值，从而使得离观察者越远的顶点坐标w分量越大 out = vec3(x/w,y/w,z/w),对应的glm代码：

`//第一个参数 fov`

`//第二个参数 宽高比`

`//第三个参数 近距离`

`//第四个参数 远距离`

`glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);`

`glm::perspective`所做的其实就是创建了一个定义了可视空间的大**平截头体**，任何在这个平截头体以外的东西最后都不会出现在裁剪空间体积内，并且将会受到裁剪，



#### 组合在一起

​           $$ V_{clip} = M_{projection} \cdot M_{view} \cdot M_{model} \cdot V_{local} $$

也就是常说的MPV矩阵，注意，矩阵运算是反着的，就是从右向左



## Screen Coordinate 屏幕坐标系

从Clip Coordinate 到Screen Coordinate的过程，叫视窗变换 (Viewport Transform)

Screen Coordinate  屏幕坐标系 (0 - 1)，对应的opengl的api是 glViewport



## 后续：变换出来的坐标将会送到光栅器，将其转化为片元，进入片元着色器








