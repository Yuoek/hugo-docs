---
title: "day_0149 "
date: 2025-09-21T09:27:59+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0149 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 1
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                cnt = 2
                for k in range(j + 1, n):
                    x3, y3 = points[k]
                    a = (y2 - y1) * (x3 - x1)
                    b = (y3 - y1) * (x2 - x1)
                    cnt += a == b
                ans = max(ans, cnt)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0149  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)  # 获取点的数量
        ans = 1  # 初始化最大点数为1（至少有一个点）
        for i in range(n):  # 遍历所有点作为第一个点
            x1, y1 = points[i]  # 获取第一个点的坐标
            for j in range(i + 1, n):  # 遍历所有点作为第二个点（避免重复）
                x2, y2 = points[j]  # 获取第二个点的坐标
                cnt = 2  # 当前直线至少包含两个点
                for k in range(j + 1, n):  # 遍历剩余点检查是否在同一直线上
                    x3, y3 = points[k]  # 获取第三个点的坐标
                    a = (y2 - y1) * (x3 - x1)  # 计算斜率相等的分子部分
                    b = (y3 - y1) * (x2 - x1)  # 计算斜率相等的分母部分
                    cnt += a == b  # 如果斜率相等（避免除零），计数加1
                ans = max(ans, cnt)  # 更新最大点数
        return ans  # 返回最大点数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0149  数学解释

```python 
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 1
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                cnt = 2
                for k in range(j + 1, n):
                    x3, y3 = points[k]
                    a = (y2 - y1) * (x3 - x1)
                    b = (y3 - y1) * (x2 - x1)
                    cnt += a == b
                ans = max(ans, cnt)
        return ans 
```


这段代码使用了**穷举法（Brute Force）**的数学思想来解决"直线上最多点数"问题。具体来说：

## 核心数学原理：三点共线的判定条件

代码基于以下数学原理：三个点(x₁,y₁), (x₂,y₂), (x₃,y₃)共线的充要条件是：
```
(y₂ - y₁)/(x₂ - x₁) = (y₃ - y₁)/(x₃ - x₁)
```
为了避免除数为0的情况，代码使用了交叉相乘的等价形式：
```
(y₂ - y₁) × (x₃ - x₁) = (y₃ - y₁) × (x₂ - x₁)
```

## 算法思想解析

1. **三重循环结构**：
   - 外层循环：选择第一个点作为基准点
   - 中层循环：选择第二个点，与第一个点确定一条直线
   - 内层循环：检查其他所有点是否在这条直线上

2. **计数策略**：
   - 初始计数为2（已经有两个点在直线上）
   - 每找到一个共线的点，计数加1

3. **优化考虑**：
   - 避免重复计算：`j`从`i+1`开始，`k`从`j+1`开始
   - 避免浮点数精度问题：使用整数乘法而非除法

## 时间复杂度分析

这是一个O(n³)的算法，对于n个点：
- 外层循环：n次
- 中层循环：平均n/2次  
- 内层循环：平均n/3次
总时间复杂度为O(n³)

## 数学思想的体现

这体现了**组合数学**中的思想：通过检查所有可能的三点组合来判断共线性，是典型的穷举法在几何问题中的应用。虽然时间复杂度较高，但数学原理清晰，实现简单。
