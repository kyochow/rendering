#  一个忽明忽暗的三角形

#### Shader

什么是shader？就是运行在gpu上做渲染相关的工作的程序，就叫shader



#### GLSL

类c语言，一个典型的shader是这个样子的



`#version version_number `

`in type in_variable_name;`

 `in type in_variable_name; //传入的字段`

 `out type out_variable_name;`  //返回的字段

`uniform type uniform_name;`  // cpu传入的字段

 `int main()`

 `{`  

​	`// 处理输入并进行一些图形操作  ...`  

​	`// 输出处理过的结果到输出变量` 

 	out_variable_name = 	weird_stuff_we_processed; 

`}`

#### vertex shader

input变量可以有 vecn bvecn ivecn uvecn dvecn

输出 position 

location 可以指定位置 layout (location = 0 - 15) 一共16个寄存器

#### fragment shader
输入为vertex shader的输出，既position

输出一个vec4，颜色值，输出到屏幕上



