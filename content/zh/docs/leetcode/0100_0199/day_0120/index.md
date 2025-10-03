---
title: "day_0120 "
date: 2025-09-21T10:19:18+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0120 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        f = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1):
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j]
        return f[0][0] 
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

## LeetCode_0120  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)  # 获取三角形的行数
        f = [[0] * (n + 1) for _ in range(n + 1)]  # 创建DP数组，大小为(n+1)×(n+1)
        for i in range(n - 1, -1, -1):  # 从倒数第二行开始向上遍历
            for j in range(i + 1):  # 遍历当前行的每个元素
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j]  # 计算当前位置的最小路径和
        return f[0][0]  # 返回顶部的最小路径和
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

## LeetCode_0120  数学解释

```python 
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        f = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1):
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j]
        return f[0][0] 
```


这段代码使用了**动态规划**的数学思想来解决三角形最小路径和问题。具体来说：

1. **问题分析**：从三角形顶部到底部，寻找一条路径使得路径上的数字之和最小（每次只能移动到下一行相邻的数字）

2. **动态规划思想**：
   - **状态定义**：`f[i][j]` 表示从位置 `(i, j)` 到底部的最小路径和
   - **状态转移方程**：`f[i][j] = min(f[i+1][j], f[i+1][j+1]) + triangle[i][j]`
   - **自底向上**：从最后一行开始向上递推计算

3. **数学递推关系**：
   - 每个位置的最小路径和 = 当前值 + 下一行相邻两个位置中较小的路径和
   - 这体现了**最优子结构**特性：全局最优解包含子问题的最优解

4. **边界处理**：
   - 初始化 `f[n][*] = 0`（底部边界）
   - 最终结果存储在 `f[0][0]` 中（顶部到底部的最小路径和）

5. **时间复杂度**：O(n²)，其中 n 是三角形的行数
6. **空间复杂度**：O(n²)，使用二维数组存储中间状态

这种解法通过将大问题分解为小问题，并存储子问题的解来避免重复计算，是动态规划的经典应用。

