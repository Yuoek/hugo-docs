---
title: "day_0048 "
date: 2025-09-14T10:10:39+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0048 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n >> 1):
            for j in range(n):
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i - 1][j], matrix[i][j]
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0048  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        # 第一步：上下翻转矩阵（水平翻转）
        for i in range(n >> 1):  # n >> 1 等价于 n//2，遍历上半部分行
            for j in range(n):  # 遍历每一列
                # 交换第i行和第n-i-1行的对应元素
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i - 1][j], matrix[i][j]
        
        # 第二步：沿主对角线翻转（转置矩阵）
        for i in range(n):  # 遍历每一行
            for j in range(i):  # 只遍历对角线以下的列，避免重复交换
                # 交换matrix[i][j]和matrix[j][i]的位置
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0048  数学解释

```python 
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n >> 1):
            for j in range(n):
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i - 1][j], matrix[i][j]
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j] 
```


这段代码实现的是矩阵顺时针旋转90度的操作，其中蕴含着两个重要的数学变换思想：

## 核心数学思想

### 1. 对称变换思想
第一个循环 `for i in range(n >> 1)` 实现了**水平对称变换**：
- 将矩阵上下翻转（关于水平中线对称）
- 数学上表示为：`(i, j) ↔ (n-i-1, j)`
- 这相当于对矩阵进行了一次反射变换

### 2. 转置变换思想  
第二个循环 `for i in range(n): for j in range(i)` 实现了**矩阵转置**：
- 将矩阵沿主对角线翻转
- 数学上表示为：`(i, j) ↔ (j, i)`
- 这是线性代数中的标准转置操作

## 数学原理证明

矩阵顺时针旋转90度 = 水平对称变换 + 转置变换

**数学证明：**
设原矩阵位置为 (i, j)，经过：
1. 水平对称：`(i, j) → (n-i-1, j)`
2. 转置：`(n-i-1, j) → (j, n-i-1)`

最终位置 (j, n-i-1) 正是顺时针旋转90度后的正确位置。

## 算法复杂度
- **时间复杂度**：O(n²) - 两个嵌套循环
- **空间复杂度**：O(1) - 原地操作，无需额外空间

这种方法的巧妙之处在于将复杂的旋转操作分解为两个简单的对称操作，体现了数学中的**分解与组合**思想。


