---
title: "day_0062 "
date: 2025-09-14T09:26:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0062 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[0] * n for _ in range(m)]
        f[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i:
                    f[i][j] += f[i - 1][j]
                if j:
                    f[i][j] += f[i][j - 1]
        return f[-1][-1] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i) {
                    f[i][j] += f[i - 1][j];
                }
                if (j) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int uniquePaths(int m, int n) {
        var f = new int[m][n];
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    f[i][j] += f[i - 1][j];
                }
                if (j > 0) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0062  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 创建一个m行n列的二维数组，初始值都为0
        f = [[0] * n for _ in range(m)]
        
        # 起点位置(0,0)的路径数为1
        f[0][0] = 1
        
        # 遍历网格中的每个位置
        for i in range(m):
            for j in range(n):
                # 如果不是第一行，则可以从上方格子到达当前位置
                if i:
                    f[i][j] += f[i - 1][j]
                # 如果不是第一列，则可以从左侧格子到达当前位置
                if j:
                    f[i][j] += f[i][j - 1]
        
        # 返回右下角终点的路径总数
        return f[-1][-1] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i) {
                    f[i][j] += f[i - 1][j];
                }
                if (j) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int uniquePaths(int m, int n) {
        var f = new int[m][n];
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    f[i][j] += f[i - 1][j];
                }
                if (j > 0) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0062  数学解释

```python 
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[0] * n for _ in range(m)]
        f[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i:
                    f[i][j] += f[i - 1][j]
                if j:
                    f[i][j] += f[i][j - 1]
        return f[-1][-1] 
```


这段代码使用了**动态规划**的数学思想来解决网格路径计数问题。

## 数学思想解释：

1. **问题建模**：将网格看作一个m×n的矩阵，从左上角(0,0)到右下角(m-1,n-1)的路径计数问题

2. **状态定义**：f[i][j]表示从起点(0,0)到达位置(i,j)的不同路径数

3. **递推关系**（核心数学思想）：
   - **基础情况**：f[0][0] = 1（起点只有1种方式到达）
   - **递推公式**：f[i][j] = f[i-1][j] + f[i][j-1]
   - 这个公式基于**组合数学**中的加法原理：到达(i,j)的路径数等于从上方(i-1,j)下来的路径数加上从左方(i,j-1)过来的路径数

4. **边界处理**：
   - 当i=0（第一行）时，只能从左边来（没有上方）
   - 当j=0（第一列）时，只能从上方来（没有左边）

## 数学等价性：

这实际上是在计算组合数 C(m+n-2, m-1) 或 C(m+n-2, n-1)，因为：
- 总共需要走(m-1)+(n-1)步
- 其中向下走(m-1)步，向右走(n-1)步
- 路径数等于从(m+n-2)步中选择(m-1)步向下走的组合数

动态规划方法通过递推关系避免了直接计算大组合数，提供了更高效的解决方案。
