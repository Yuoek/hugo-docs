---
title: "day_0070 "
date: 2025-09-14T08:57:45+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0070 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return b 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0070  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 0, 1  # 初始化斐波那契数列的前两个值
        for _ in range(n):  # 循环n次，计算斐波那契数列
            a, b = b, a + b  # 更新斐波那契数列的值
        return b  # 返回第n个斐波那契数，即爬n阶楼梯的方法数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0070  数学解释

```python 
class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return b 
```


这段代码使用了**动态规划**的数学思想来解决爬楼梯问题（斐波那契数列问题）。

## 数学思想解析：

### 1. 问题建模
爬n阶楼梯，每次可以爬1阶或2阶，求不同爬法总数。这实际上就是斐波那契数列：
- f(1) = 1
- f(2) = 2  
- f(n) = f(n-1) + f(n-2)

### 2. 动态规划优化
代码采用了**空间优化的动态规划**方法：
- 使用两个变量 `a` 和 `b` 来存储前两个状态
- `a` 代表 f(n-2)
- `b` 代表 f(n-1)
- 每次迭代：`a, b = b, a + b` 计算下一个斐波那契数

### 3. 数学递推关系
每次循环执行数学递推：
- 新的 `a` = 旧的 `b` (即 f(n-1))
- 新的 `b` = 旧的 `a` + 旧的 `b` (即 f(n-2) + f(n-1))

### 4. 时间复杂度：O(n)
### 5. 空间复杂度：O(1)

这种解法巧妙地运用了斐波那契数列的数学性质和动态规划的空间优化技巧，既高效又优雅。


