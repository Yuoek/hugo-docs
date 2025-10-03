---
title: "day_0059 "
date: 2025-09-14T09:45:44+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0059 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        for v in range(1, n * n + 1):
            ans[i][j] = v
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= n or y < 0 or y >= n or ans[x][y]:
                k = (k + 1) % 4
            i, j = i + dirs[k], j + dirs[k + 1]
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        const int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        final int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0059  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]  # 初始化n×n的零矩阵
        dirs = (0, 1, 0, -1, 0)  # 方向向量：右、下、左、上
        i = j = k = 0  # 初始化当前位置(i,j)和方向索引k
        for v in range(1, n * n + 1):  # 遍历1到n²的所有数字
            ans[i][j] = v  # 将当前数字填入矩阵
            x, y = i + dirs[k], j + dirs[k + 1]  # 计算下一个位置
            if x < 0 or x >= n or y < 0 or y >= n or ans[x][y]:  # 如果越界或已填充
                k = (k + 1) % 4  # 改变方向（顺时针旋转90度）
            i, j = i + dirs[k], j + dirs[k + 1]  # 移动到下一个位置
        return ans  # 返回填充完成的螺旋矩阵
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        const int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        final int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0059  数学解释

```python 
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        for v in range(1, n * n + 1):
            ans[i][j] = v
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= n or y < 0 or y >= n or ans[x][y]:
                k = (k + 1) % 4
            i, j = i + dirs[k], j + dirs[k + 1]
        return ans 
```


这段代码使用**螺旋填充法**生成一个 n×n 的螺旋矩阵，其数学思想可以解释为：

## 1. **方向控制与边界检测**
- 使用方向向量 `dirs = (0, 1, 0, -1, 0)` 表示四个方向（右、下、左、上）
- 数学上这相当于四个方向向量：(0,1), (1,0), (0,-1), (-1,0)
- 通过模运算 `k = (k + 1) % 4` 实现方向的循环切换

## 2. **螺旋遍历的数学规律**
- 从左上角(0,0)开始，按顺时针方向螺旋填充
- 每次遇到边界或已填充位置时改变方向
- 填充顺序遵循：右→下→左→上的循环模式

## 3. **矩阵填充的数学映射**
- 将数字1到n²按螺旋顺序映射到矩阵坐标(i,j)
- 每个位置(i,j)对应一个唯一的数值v
- 这种填充方式在数学上形成了一个螺旋递增的序列

## 4. **算法复杂度分析**
- 时间复杂度：O(n²)，需要填充n²个元素
- 空间复杂度：O(n²)，用于存储结果矩阵

这种方法的数学本质是**在二维网格上实现一种特定的遍历顺序**，通过方向向量和边界检测来模拟螺旋路径，体现了**坐标变换**和**方向控制**的数学思想。

