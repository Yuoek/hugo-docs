---
title: "day_0172 "
date: 2025-09-21T08:43:31+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0172 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0
        while n:
            n //= 5
            ans += n
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

## LeetCode_0172  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0  # 初始化零的个数计数器
        while n:  # 当n不为0时循环
            n //= 5  # 将n除以5并取整
            ans += n  # 将商加到计数器中
        return ans  # 返回尾随零的总数
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

## LeetCode_0172  数学解释

```python 
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0
        while n:
            n //= 5
            ans += n
        return ans 
```


这段代码使用了**数论中的数学思想**，具体来说是**勒让德定理（Legendre's Formula）**。

## 核心数学思想：
计算 n! 末尾零的个数，实际上就是计算 n! 中因子 10 的个数。由于 10 = 2 × 5，而阶乘中因子 2 的数量总是多于因子 5 的数量，因此问题转化为计算 n! 中因子 5 的个数。

## 数学原理：
勒让德定理指出：n! 中质因子 p 的个数为：
```
⌊n/p⌋ + ⌊n/p²⌋ + ⌊n/p³⌋ + ... 
```

## 代码解释：
```python
ans = 0
while n:
    n //= 5      # 计算当前层级的 5 的幂次对应的个数
    ans += n     # 累加到结果中
return ans
```

## 数学过程示例（n=25）：
- 第一轮：n=25 → n//5=5 → ans=5（计算能被5整除的数：5,10,15,20,25）
- 第二轮：n=5 → n//5=1 → ans=6（计算能被25整除的数：25）
- 第三轮：n=1 → n//5=0 → 循环结束

最终结果：5+1=6，即 25! 末尾有6个零

## 数学简洁性：
这个算法的时间复杂度为 O(log₅n)，空间复杂度为 O(1)，通过简单的除法和累加操作，优雅地解决了看似复杂的数学问题。

