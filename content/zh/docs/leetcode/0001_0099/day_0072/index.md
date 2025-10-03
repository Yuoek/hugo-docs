---
title: "day_0072 "
date: 2025-09-14T08:54:03+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0072 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for j in range(1, n + 1):
            f[0][j] = j
        for i, a in enumerate(word1, 1):
            f[i][0] = i
            for j, b in enumerate(word2, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1]
                else:
                    f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
        return f[m][n] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int f[m + 1][n + 1];
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            f[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
                }
            }
        }
        return f[m][n];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int j = 1; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            f[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i - 1][j], Math.min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                }
            }
        }
        return f[m][n];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0072  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)  # 获取两个字符串的长度
        f = [[0] * (n + 1) for _ in range(m + 1)]  # 创建动态规划表格，大小为(m+1)×(n+1)
        for j in range(1, n + 1):
            f[0][j] = j  # 初始化第一行：将空字符串转换为word2前j个字符需要j次操作
        for i, a in enumerate(word1, 1):
            f[i][0] = i  # 初始化第一列：将word1前i个字符转换为空字符串需要i次操作
            for j, b in enumerate(word2, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1]  # 字符相同，无需操作，继承左上角的值
                else:
                    f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1  # 字符不同，取删除、插入、替换三种操作的最小值加1
        return f[m][n]  # 返回将word1转换为word2所需的最小操作次数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int f[m + 1][n + 1];
        for (int j = 0; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            f[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
                }
            }
        }
        return f[m][n];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int j = 1; j <= n; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            f[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i - 1][j], Math.min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                }
            }
        }
        return f[m][n];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0072  数学解释

```python 
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for j in range(1, n + 1):
            f[0][j] = j
        for i, a in enumerate(word1, 1):
            f[i][0] = i
            for j, b in enumerate(word2, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1]
                else:
                    f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
        return f[m][n] 
```


这段代码实现了**编辑距离（Edit Distance）**问题的动态规划解法。让我用数学思想来解释：

## 问题定义
计算将字符串 `word1` 转换为 `word2` 所需的最少操作次数，允许的操作包括：
- 插入一个字符
- 删除一个字符  
- 替换一个字符

## 数学建模 - 动态规划

### 状态定义
设 `f[i][j]` 表示将 `word1` 的前 `i` 个字符转换为 `word2` 的前 `j` 个字符所需的最少操作次数。

### 状态转移方程
对于每个位置 `(i, j)`：
1. **如果字符相同**：`f[i][j] = f[i-1][j-1]`
   - 不需要操作，直接继承前一个状态

2. **如果字符不同**：`f[i][j] = min(f[i-1][j], f[i][j-1], f[i-1][j-1]) + 1`
   - `f[i-1][j] + 1`：删除 `word1[i]`
   - `f[i][j-1] + 1`：在 `word1` 中插入 `word2[j]`
   - `f[i-1][j-1] + 1`：将 `word1[i]` 替换为 `word2[j]`

### 边界条件
- `f[0][j] = j`：空字符串变为 `word2` 的前j个字符需要j次插入
- `f[i][0] = i`：`word1` 的前i个字符变为空字符串需要i次删除

## 数学意义
这是一个典型的**最优子结构**问题，具有**重叠子问题**特性，适合用动态规划解决。时间复杂度为 O(m×n)，空间复杂度为 O(m×n)。

该算法体现了**递推思想**和**最优性原则**，通过构建二维状态表，自底向上地计算出最优解。

