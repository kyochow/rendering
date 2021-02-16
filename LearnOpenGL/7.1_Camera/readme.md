#  封装Camera

## 概述

OpenGL本身没有摄像机的概念

可以通过把场景中的所有物体往相反方向移动的方式来模拟出摄像机，产生一种**我们**在移动的感觉，而不是场景在移动

一个Camera必备的要素

- 这个Camera的位置 Position

- 方向 Direction
- 向右的向量 Right
- 向上的向量 Up



![](/Users/yons/Documents/github/rendering/LearnOpenGL/7.1_Camera/camera_axes.png)



将上面对应颜色的向量值，带入下面的矩阵，则可以快速得到View Matrix



Look At 矩阵

​                 $$ LookAt = \begin{bmatrix}\begin{matrix} \color{red}{R_x} & \color{red}{R_y} & \color{red}{R_z} & 0 \\\color{green}{U_x} & \color{green}{U_y} & \color{green}{U_z} & 0 \\\color{blue}{D_x} & \color{blue}{D_y} & \color{blue}{D_z} & 0 \\0 & 0 & 0 & 1 \end{matrix}\end{bmatrix} * \begin{bmatrix}\begin{matrix} 1 & 0 & 0 & -\color{purple}{P_x} \\0 & 1 & 0 & -\color{purple}{P_y} \\0 & 0 & 1 & -\color{purple}{P_z} \\0 & 0 & 0 & 1 \end{matrix}\end{bmatrix} $$







## 欧拉角：

![](/Users/yons/Documents/github/rendering/LearnOpenGL/7.1_Camera/camera_pitch_yaw_roll.png)

pitch 俯角

yaw 水平旋转角

roll 垂直旋转角

其实我们的Camera只需要pitch + yaw，因为roll会导致视角倾斜，人类很不习惯

