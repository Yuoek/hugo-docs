---
title: "day_0064 "
date: 2025-09-14T09:22:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0064 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[0] * n for _ in range(m)]
        f[0][0] = grid[0][0]
        for i in range(1, m):
            f[i][0] = f[i - 1][0] + grid[i][0]
        for j in range(1, n):
            f[0][j] = f[0][j - 1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j]
        return f[-1][-1] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
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
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0064  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])  # 获取网格的行数m和列数n
        f = [[0] * n for _ in range(m)]  # 创建m×n的二维数组f，用于存储到达每个位置的最小路径和
        f[0][0] = grid[0][0]  # 初始化起点位置的最小路径和为网格起点值
        
        # 初始化第一列：只能从上往下走
        for i in range(1, m):
            f[i][0] = f[i - 1][0] + grid[i][0]  # 当前位置的最小路径和 = 上方位置的最小路径和 + 当前网格值
            
        # 初始化第一行：只能从左往右走
        for j in range(1, n):
            f[0][j] = f[0][j - 1] + grid[0][j]  # 当前位置的最小路径和 = 左方位置的最小路径和 + 当前网格值
            
        # 动态规划填充剩余网格
        for i in range(1, m):
            for j in range(1, n):
                # 当前位置的最小路径和 = min(上方位置的最小路径和, 左方位置的最小路径和) + 当前网格值
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j]
                
        return f[-1][-1]  # 返回右下角位置的最小路径和，即从起点到终点的最小路径和
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
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
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0064  数学解释

```python 
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[0] * n for _ in range(m)]
        f[0][0] = grid[0][0]
        for i in range(1, m):
            f[i][0] = f[i - 1][0] + grid[i][0]
        for j in range(1, n):
            f[0][j] = f[0][j - 1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j]
        return f[-1][-1] 
```


这段代码使用了**动态规划**的数学思想来解决最小路径和问题。具体解释如下：

## 问题描述
给定一个m×n的网格，每个格子包含一个非负整数，从左上角(0,0)出发到右下角(m-1,n-1)，每次只能向右或向下移动，求路径上数字之和的最小值。

## 动态规划思想

### 1. 状态定义
`f[i][j]` 表示从起点(0,0)到位置(i,j)的最小路径和

### 2. 状态转移方程
对于任意位置(i,j)，只能从上方(i-1,j)或左方(i,j-1)到达：
```
f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
```

### 3. 边界条件处理
- **起点**：`f[0][0] = grid[0][0]`
- **第一列**：只能从上方到达 `f[i][0] = f[i-1][0] + grid[i][0]`
- **第一行**：只能从左方到达 `f[0][j] = f[0][j-1] + grid[0][j]`

### 4. 算法流程
1. 初始化二维数组f存储中间结果
2. 处理边界情况（第一行和第一列）
3. 按行遍历网格，计算每个位置的最小路径和
4. 返回终点`f[m-1][n-1]`的值

## 数学原理
该算法基于**最优子结构**性质：全局最优解包含子问题的最优解。通过自底向上的方式，逐步构建从起点到每个位置的最优解，最终得到全局最优解。

**时间复杂度**：O(m×n)  
**空间复杂度**：O(m×n)（可优化为O(n)）


