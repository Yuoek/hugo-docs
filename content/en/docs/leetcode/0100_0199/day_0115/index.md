---
title: "day_0115 "
date: 2025-09-21T10:27:39+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0115 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            f[i][0] = 1
        for i, a in enumerate(s, 1):
            for j, b in enumerate(t, 1):
                f[i][j] = f[i - 1][j]
                if a == b:
                    f[i][j] += f[i - 1][j - 1]
        return f[m][n] 
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

## LeetCode_0115  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)  # 获取字符串s和t的长度
        f = [[0] * (n + 1) for _ in range(m + 1)]  # 创建动态规划二维数组，大小为(m+1)×(n+1)
        for i in range(m + 1):
            f[i][0] = 1  # 初始化：当t为空字符串时，任何s都有1种匹配方式
        for i, a in enumerate(s, 1):  # 遍历字符串s，索引从1开始
            for j, b in enumerate(t, 1):  # 遍历字符串t，索引从1开始
                f[i][j] = f[i - 1][j]  # 不选择当前s字符时的匹配数
                if a == b:  # 如果当前字符匹配
                    f[i][j] += f[i - 1][j - 1]  # 加上选择当前字符时的匹配数
        return f[m][n]  # 返回s中t作为子序列出现的不同方式总数
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

## LeetCode_0115  数学解释

```python 
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            f[i][0] = 1
        for i, a in enumerate(s, 1):
            for j, b in enumerate(t, 1):
                f[i][j] = f[i - 1][j]
                if a == b:
                    f[i][j] += f[i - 1][j - 1]
        return f[m][n] 
```


这段代码使用了**动态规划**的数学思想来解决"不同子序列"问题。具体来说：

## 问题定义
计算字符串 `s` 中有多少种不同的方式可以删除某些字符得到字符串 `t`

## 数学建模
定义状态 `f[i][j]` 表示：在 `s` 的前 `i` 个字符中，`t` 的前 `j` 个字符出现的不同子序列个数

## 状态转移方程
1. **基础情况**：`f[i][0] = 1`（空字符串是任何字符串的子序列）
2. **递推关系**：
   - 如果 `s[i-1] != t[j-1]`：`f[i][j] = f[i-1][j]`
     （当前字符不匹配，只能从前i-1个字符中找j个字符的子序列）
   - 如果 `s[i-1] == t[j-1]`：`f[i][j] = f[i-1][j] + f[i-1][j-1]`
     （可以选择使用当前匹配的字符，也可以选择不使用）

## 数学思想体现
- **递推关系**：将大问题分解为小问题
- **最优子结构**：当前状态的值依赖于前一个状态的值
- **重叠子问题**：避免重复计算，通过二维数组存储中间结果
- **组合计数**：使用加法原理计算不同的组合方式

## 时间复杂度
O(m×n)，其中 m 是 s 的长度，n 是 t 的长度

这种动态规划方法通过建立状态转移方程，系统地计算了所有可能的子序列匹配情况，是解决这类计数问题的经典数学思想。


