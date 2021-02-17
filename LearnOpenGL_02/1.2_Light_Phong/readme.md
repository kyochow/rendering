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

## 漫反射光照
漫反射光照使物体上与光线方向越接近的片段能从光源处获得更多的亮度



![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL_02/1.2_Light_Phong/diffuse_light.png)

为了测量光线和片段的角度，我们使用一个叫做法向量(Normal Vector)的东西，它是垂直于片段表面的一个向量
这两个向量之间的角度很容易就能够通过点乘计算出来
两个单位向量的夹角越小，它们点乘的结果越倾向于1。当两个向量的夹角为90度的时候，点乘会变为0。这同样适用于θ，θ越大，光对片段颜色的影响就应该越小

所以，计算漫反射光照需要什么？

- 法向量：一个垂直于顶点表面的向量
- 定向的光线：作为光源的位置与片段的位置之间向量差的方向向量。为了计算这个光线，我们需要光的位置向量和片段的位置向量。

