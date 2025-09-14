---
title: "day_0069 "
date: 2025-09-14T09:13:15+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0069 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        while l < r:
            mid = (l + r + 1) >> 1
            if mid > x // mid:
                r = mid - 1
            else:
                l = mid
        return l 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1ll) >> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0069  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x  # 初始化左右边界，l=0，r=x
        while l < r:  # 当左边界小于右边界时循环
            mid = (l + r + 1) >> 1  # 计算中间值，使用位运算右移1位相当于除以2
            if mid > x // mid:  # 如果mid的平方大于x
                r = mid - 1  # 调整右边界为mid-1
            else:
                l = mid  # 否则调整左边界为mid
        return l  # 返回最终的平方根整数部分
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1ll) >> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0069  数学解释

```python 
class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        while l < r:
            mid = (l + r + 1) >> 1
            if mid > x // mid:
                r = mid - 1
            else:
                l = mid
        return l 
```


这段代码使用了**二分查找（Binary Search）** 的数学思想来求解平方根问题。

## 核心数学思想：
1. **二分查找原理**：在有序区间 [0, x] 中寻找最大的整数 l，使得 l² ≤ x
2. **整数除法特性**：使用 `x // mid` 而不是 `mid * mid` 避免整数溢出
3. **边界处理**：通过 `(l + r + 1) >> 1` 确保中点偏向右侧，避免死循环

## 数学逻辑分析：
- **循环不变量**：始终保持 l² ≤ x < (r+1)²
- **终止条件**：当 l = r 时，l 就是最大的整数满足 l² ≤ x
- **中点计算**：`(l + r + 1) >> 1` 等价于 `⌊(l + r + 1)/2⌋`，确保中点偏向右侧

## 时间复杂度：O(log x)
每次迭代将搜索区间减半，类似于二分查找的时间复杂度。

这种解法巧妙地运用了二分查找的数学原理，在整数范围内高效地找到了平方根的整数部分。

