---
title: "day_0132 "
date: 2025-09-21T09:57:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0132 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        g = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = s[i] == s[j] and g[i + 1][j - 1]
        f = list(range(n))
        for i in range(1, n):
            for j in range(i + 1):
                if g[j][i]:
                    f[i] = min(f[i], 1 + f[j - 1] if j else 0)
        return f[-1] 
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

## LeetCode_0132  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        # 创建回文判断矩阵g，g[i][j]表示s[i:j+1]是否为回文串
        g = [[True] * n for _ in range(n)]
        # 从后往前填充回文判断矩阵
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = s[i] == s[j] and g[i + 1][j - 1]
        
        # f[i]表示s[0:i+1]的最小分割次数
        f = list(range(n))
        # 动态规划计算最小分割次数
        for i in range(1, n):
            for j in range(i + 1):
                # 如果s[j:i+1]是回文串
                if g[j][i]:
                    # 更新最小分割次数
                    f[i] = min(f[i], 1 + f[j - 1] if j else 0)
        return f[-1]  # 返回整个字符串的最小分割次数
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

## LeetCode_0132  数学解释

```python 
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        g = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = s[i] == s[j] and g[i + 1][j - 1]
        f = list(range(n))
        for i in range(1, n):
            for j in range(i + 1):
                if g[j][i]:
                    f[i] = min(f[i], 1 + f[j - 1] if j else 0)
        return f[-1] 
```


这段代码使用**动态规划**思想解决字符串最小分割次数问题，核心包含两个关键步骤：

### 1. 预处理回文信息（g[i][j]）
- **数学思想**：利用**递推关系**和**对称性**判断所有子串是否为回文
- 状态定义：g[i][j] 表示子串 s[i:j+1] 是否为回文
- 递推关系：g[i][j] = (s[i] == s[j]) and g[i+1][j-1]
- **边界处理**：当 j-i < 2 时（长度为1或2），只需判断首尾字符是否相等

### 2. 动态规划求最小分割（f[i]）
- **数学思想**：**最优子结构** + **状态转移**
- 状态定义：f[i] 表示前 i+1 个字符的最小分割次数
- 初始状态：f[i] = i（最坏情况：每个字符都分割）
- 状态转移：对于每个位置 i，检查所有 j ≤ i：
  - 如果 s[j:i+1] 是回文（g[j][i] == True）
  - 则 f[i] = min(f[i], f[j-1] + 1)（如果 j>0）
  - 如果 j==0，说明整个子串都是回文，分割次数为0

### 时间复杂度：O(n²)
- 预处理：O(n²)
- 动态规划：O(n²)

### 空间复杂度：O(n²)
- 存储回文矩阵 g

该算法通过**空间换时间**的策略，避免了重复计算回文判断，体现了动态规划"记忆化"的核心思想。


