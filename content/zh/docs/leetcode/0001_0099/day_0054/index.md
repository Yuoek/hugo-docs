---
title: "day_0054 "
date: 2025-09-14T09:54:31+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0054 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        dirs = (0, 1, 0, -1, 0)
        vis = [[False] * n for _ in range(m)]
        i = j = k = 0
        ans = []
        for _ in range(m * n):
            ans.append(matrix[i][j])
            vis[i][j] = True
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= m or y < 0 or y >= n or vis[x][y]:
                k = (k + 1) % 4
            i += dirs[k]
            j += dirs[k + 1]
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (int h = m * n; h; --h) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
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
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        List<Integer> ans = new ArrayList<>();
        boolean[][] vis = new boolean[m][n];
        for (int h = m * n; h > 0; --h) {
            ans.add(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
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

## LeetCode_0054  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])  # 获取矩阵的行数和列数
        dirs = (0, 1, 0, -1, 0)  # 方向数组：右、下、左、上（x,y的增量）
        vis = [[False] * n for _ in range(m)]  # 创建访问标记矩阵，记录已访问位置
        i = j = k = 0  # 初始化当前位置(i,j)和方向索引k
        ans = []  # 存储螺旋遍历结果的列表
        for _ in range(m * n):  # 遍历矩阵所有元素
            ans.append(matrix[i][j])  # 将当前元素加入结果列表
            vis[i][j] = True  # 标记当前位置为已访问
            x, y = i + dirs[k], j + dirs[k + 1]  # 计算下一个位置
            if x < 0 or x >= m or y < 0 or y >= n or vis[x][y]:  # 如果下一个位置越界或已访问
                k = (k + 1) % 4  # 改变方向（顺时针旋转90度）
            i += dirs[k]  # 更新当前位置的行坐标
            j += dirs[k + 1]  # 更新当前位置的列坐标
        return ans  # 返回螺旋遍历的结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (int h = m * n; h; --h) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
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
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        List<Integer> ans = new ArrayList<>();
        boolean[][] vis = new boolean[m][n];
        for (int h = m * n; h > 0; --h) {
            ans.add(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
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

## LeetCode_0054  数学解释

```python 
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        dirs = (0, 1, 0, -1, 0)
        vis = [[False] * n for _ in range(m)]
        i = j = k = 0
        ans = []
        for _ in range(m * n):
            ans.append(matrix[i][j])
            vis[i][j] = True
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= m or y < 0 or y >= n or vis[x][y]:
                k = (k + 1) % 4
            i += dirs[k]
            j += dirs[k + 1]
        return ans 
```


这段代码实现了**螺旋矩阵遍历**的算法，其数学思想可以解释为：

## 核心数学思想：方向向量与边界检测

### 1. 方向控制（向量运算）
```python
dirs = (0, 1, 0, -1, 0)
```
这是一个巧妙的方向向量设计，每两个元素组成一个方向向量：
- `(0, 1)` → 向右移动 (0, +1)
- `(0, -1)` → 向左移动 (0, -1)  
- `(1, 0)` → 向下移动 (+1, 0)
- `(-1, 0)` → 向上移动 (-1, 0)

通过循环索引 `k` 来切换方向，实现螺旋遍历。

### 2. 边界检测与转向逻辑
```python
if x < 0 or x >= m or y < 0 or y >= n or vis[x][y]:
    k = (k + 1) % 4  # 转向
```
当遇到以下情况时转向：
- 超出矩阵边界（数学边界条件）
- 已经访问过的位置（避免重复访问）

### 3. 遍历终止条件
```python
for _ in range(m * n):  # 遍历所有元素
```
确保每个元素都被访问一次且仅一次，时间复杂度为 O(m×n)

## 数学建模视角
这实际上是在二维网格上模拟一个**螺旋路径**，可以看作：
- 一个在约束条件下的路径规划问题
- 使用状态机（方向状态）来控制移动策略
- 通过标记已访问位置来避免重复遍历

算法体现了**贪心思想**：始终沿着当前方向前进，直到遇到障碍才改变方向，这种策略保证了路径的螺旋特性。

