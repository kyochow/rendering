#  光照模型Phong

属于经验光照模型 主要有三个分量
- 环境(Ambient)
- 漫反射(Diffuse)
- 镜面反射(Specular)

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL_02/1.2_Light_Phong/basic_lighting_phong.png)


## 环境光照

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

- 法向量：一个垂直于顶点表面的向量 (一般由模型提供)  Normal
- 定向的光线：作为光源的位置与片段的位置之间向量差的方向向量。为了计算这个光线，我们需要光的位置向量和片段的位置向量。这里我们传入一个我们自己定义的光位置 lightPos和lightColor

第一件事是计算光源和片段位置之间的方向向量

```
vec3 norm = normalize(Normal);
vec3 lightDir = normalize(lightPos - FragPos);
```

第二步，计算漫反射标量，乘以光的颜色，就得到了漫反射颜色

```
float diff = max(dot(norm, lightDir), 0.0);
vec3 diffuseColor = diff * lightColor;
```

第三步，环境光分量和漫反射分量，我们把它们相加，然后把结果乘以物体的颜色,得到最终颜色

```
vec3 result = (ambientColor + diffuseColor) * objectColor;
FragColor = vec4(result, 1.0);
```



##### One more thing

在计算法线的时候，需要借助法线矩阵(Normal Matrix)来处理模型不等比缩放造成的问题

```
Normal = mat3(transpose(inverse(model))) * aNormal;
```



# 镜面光照

镜面光照也是依据光的方向向量和物体的法向量来决定的，但是它也依赖于观察方向

![Image text](https://raw.githubusercontent.com/kyochow/rendering/main/LearnOpenGL_02/1.2_Light_Phong/basic_lighting_specular_theory.png)



为了得到观察者的世界空间坐标，可以使用摄像机对象的位置坐标代替









