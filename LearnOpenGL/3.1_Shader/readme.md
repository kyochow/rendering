#  Shader

什么是shader？就是运行在gpu上做渲染相关的工作的程序，就叫shader



### GLSL

类c语言，一个典型的shader是这个样子的



\`#version version_number `

`in type in_variable_name;`

 `in type in_variable_name; //传入的字段`

 `out type out_variable_name;`  //返回的字段

`uniform type uniform_name;`  // cpu传入的字段

 `int main()`

 `{`  

​	`// 处理输入并进行一些图形操作  ...`  

​	`// 输出处理过的结果到输出变量` 

 	`out_variable_name = 	weird_stuff_we_processed;` 

`}`
