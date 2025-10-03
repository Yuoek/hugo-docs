---
title: "day_0063 "
date: 2025-09-14T09:24:37+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0063 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= m or j >= n or obstacleGrid[i][j]:
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            return dfs(i + 1, j) + dfs(i, j + 1)

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        return dfs(0, 0) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if (i >= m || j >= n || obstacleGrid[i][j]) {
                return 0;
            }
            if (i == m - 1 && j == n - 1) {
                return 1;
            }
            if (f[i][j] == -1) {
                f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
            }
            return f[i][j];
        };
        return dfs(0, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Integer[][] f;
    private int[][] obstacleGrid;
    private int m;
    private int n;

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;
        this.obstacleGrid = obstacleGrid;
        f = new Integer[m][n];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (f[i][j] == null) {
            f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        }
        return f[i][j];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0063  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        @cache  # 使用缓存装饰器来存储已计算的结果，避免重复计算
        def dfs(i: int, j: int) -> int:  # 定义深度优先搜索函数，参数为当前坐标(i,j)
            if i >= m or j >= n or obstacleGrid[i][j]:  # 如果超出网格边界或遇到障碍物
                return 0  # 返回0，表示此路径不可行
            if i == m - 1 and j == n - 1:  # 如果到达终点(右下角)
                return 1  # 返回1，表示找到一条有效路径
            return dfs(i + 1, j) + dfs(i, j + 1)  # 递归计算向右和向下移动的路径数之和

        m, n = len(obstacleGrid), len(obstacleGrid[0])  # 获取网格的行数和列数
        return dfs(0, 0)  # 从起点(0,0)开始搜索，返回所有可能的路径数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if (i >= m || j >= n || obstacleGrid[i][j]) {
                return 0;
            }
            if (i == m - 1 && j == n - 1) {
                return 1;
            }
            if (f[i][j] == -1) {
                f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
            }
            return f[i][j];
        };
        return dfs(0, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Integer[][] f;
    private int[][] obstacleGrid;
    private int m;
    private int n;

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;
        this.obstacleGrid = obstacleGrid;
        f = new Integer[m][n];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (f[i][j] == null) {
            f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        }
        return f[i][j];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0063  数学解释

```python 
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= m or j >= n or obstacleGrid[i][j]:
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            return dfs(i + 1, j) + dfs(i, j + 1)

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        return dfs(0, 0) 
```


这段代码使用了**动态规划**和**记忆化搜索**的数学思想来解决网格路径计数问题。

## 数学思想解释：

1. **递归关系（递推公式）**：
   - 从位置(i,j)到终点的路径数 = 从(i+1,j)到终点的路径数 + 从(i,j+1)到终点的路径数
   - 数学表达式：f(i,j) = f(i+1,j) + f(i,j+1)

2. **边界条件**：
   - 越界或遇到障碍物：f(i,j) = 0
   - 到达终点：f(m-1,n-1) = 1

3. **记忆化技术**：
   - 使用`@cache`装饰器存储已计算的结果，避免重复计算
   - 这是动态规划中"自顶向下"的实现方式

4. **问题分解**：
   - 将大问题分解为子问题：从当前位置到终点的路径数
   - 符合动态规划的"最优子结构"特性

## 数学公式表示：

对于网格中的每个位置(i,j)：
```
f(i,j) = { 
    0, 如果 i≥m 或 j≥n 或 grid[i][j]=1
    1, 如果 i=m-1 且 j=n-1
    f(i+1,j) + f(i,j+1), 其他情况
}
```

这种解法的时间复杂度为O(m×n)，因为每个位置最多计算一次；空间复杂度也是O(m×n)，用于存储递归调用栈和缓存结果。


