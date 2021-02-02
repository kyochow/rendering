# 本部分介绍
### 本项目已经搭建好了xcode环境，但如何自己搭建一个opengl开发环境呢

- 安装HomeBrew

- brew install glfw3 安装目录在 /usr/local/Cellar/glfw/3.x.x/

- brew install glew 安装目录在 /usr/local/Cellar/glew/2.x.x

- 配置xcode

#### 如何配置XCode项目

- 新建（command line tool）项目，语言选择C++
- Bulid Settings -> Header Search Paths 添加两条  /usr/local/Cellar/glfw/3.x.x/include 和 /usr/local/Cellar/glew/2.x.x/include
- Bulid Settings -> Library Search Paths 添加两条 /usr/local/Cellar/glfw/3.x.x/lib 和 /usr/local/Cellar/glew/2.x.x/lib
- 导入framework，在 General中找到Linked Frameworks and Libraries 添加两个库中的libglfw.x.x.dylib 和 libGLEW.2.2.0.dylib
- 继续添加其他需要的库
