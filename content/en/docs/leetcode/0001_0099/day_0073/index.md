---
title: "day_0073 "
date: 2025-09-14T08:52:11+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0073 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        row = [False] * m
        col = [False] * n
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i] = col[j] = True
        for i in range(m):
            for j in range(n):
                if row[i] or col[j]:
                    matrix[i][j] = 0 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m);
        vector<bool> col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean[] row = new boolean[m];
        boolean[] col = new boolean[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0073  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])  # 获取矩阵的行数和列数
        row = [False] * m  # 创建行标记数组，记录哪些行需要置零
        col = [False] * n  # 创建列标记数组，记录哪些列需要置零
        for i in range(m):  # 遍历矩阵的每一行
            for j in range(n):  # 遍历矩阵的每一列
                if matrix[i][j] == 0:  # 如果当前元素为零
                    row[i] = col[j] = True  # 标记对应的行和列为需要置零
        for i in range(m):  # 再次遍历矩阵的每一行
            for j in range(n):  # 再次遍历矩阵的每一列
                if row[i] or col[j]:  # 如果当前行或列被标记为需要置零
                    matrix[i][j] = 0  # 将当前元素置为零
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m);
        vector<bool> col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean[] row = new boolean[m];
        boolean[] col = new boolean[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0073  数学解释

```python 
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        row = [False] * m
        col = [False] * n
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i] = col[j] = True
        for i in range(m):
            for j in range(n):
                if row[i] or col[j]:
                    matrix[i][j] = 0 
```


这段代码使用了**标记法**的数学思想来解决矩阵置零问题：

## 核心数学思想：空间换时间

### 1. **标记思想**
- 使用两个布尔数组 `row` 和 `col` 来记录哪些行和列需要被置零
- `row[i] = True` 表示第 i 行需要置零
- `col[j] = True` 表示第 j 列需要置零

### 2. **两阶段处理**
**第一阶段：信息收集**
```python
for i in range(m):
    for j in range(n):
        if matrix[i][j] == 0:
            row[i] = col[j] = True
```
- 遍历整个矩阵，发现 0 时标记对应的行和列

**第二阶段：批量处理**
```python
for i in range(m):
    for j in range(n):
        if row[i] or col[j]:
            matrix[i][j] = 0
```
- 再次遍历矩阵，根据标记信息批量置零

### 3. **数学复杂度分析**
- **时间复杂度**：O(m × n)，需要遍历矩阵两次
- **空间复杂度**：O(m + n)，需要额外的行和列标记数组

### 4. **数学优化原理**
这种方法避免了直接在原矩阵上修改可能导致的连锁反应问题，通过分离"检测"和"执行"两个步骤，确保了算法的正确性和效率。

这种思想在算法设计中很常见：**先收集必要信息，再基于这些信息进行批量操作**，是一种典型的空间换时间的优化策略。


