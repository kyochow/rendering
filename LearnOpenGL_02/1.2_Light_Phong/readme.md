#  光照模型


## Phong

属于经验光照模型 主要有三个分量
- 环境(Ambient)
- 漫反射(Diffuse)
- 镜面反射(Specular)

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL_02/1.2_Light_Phong/basic_lighting_phong.png)


### 环境光照

光通常都不是来自于同一个光源，而是来自于我们周围分散的很多光源

考虑所有反射情况的算法叫做全局照明(Global Illumination)算法，但是这种算法既开销高昂又极其复杂

所以我们先使用一个简化的全局照明模型，即环境光照

