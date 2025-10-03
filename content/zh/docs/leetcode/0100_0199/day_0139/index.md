---
title: "day_0139 "
date: 2025-09-21T09:46:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0139 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        n = len(s)
        f = [True] + [False] * n
        for i in range(1, n + 1):
            f[i] = any(f[j] and s[j:i] in words for j in range(i))
        return f[n] 
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

## LeetCode_0139  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)  # 将单词字典转换为集合，提高查找效率
        n = len(s)  # 获取字符串长度
        f = [True] + [False] * n  # 初始化动态规划数组，f[0]为True，其余为False
        for i in range(1, n + 1):  # 遍历字符串的每个位置
            f[i] = any(f[j] and s[j:i] in words for j in range(i))  # 检查从j到i的子串是否在字典中且f[j]为True
        return f[n]  # 返回最后一个位置的结果，表示整个字符串是否能被分割
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

## LeetCode_0139  数学解释

```python 
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        n = len(s)
        f = [True] + [False] * n
        for i in range(1, n + 1):
            f[i] = any(f[j] and s[j:i] in words for j in range(i))
        return f[n] 
```


这段代码使用了**动态规划**的数学思想来解决单词拆分问题。具体来说：

**核心思想**：
- 将问题分解为子问题：判断字符串s[0:i]是否能被拆分成字典中的单词
- 使用记忆化存储（f数组）来避免重复计算

**数学解释**：
1. **状态定义**：f[i]表示字符串s的前i个字符（s[0:i]）是否能被拆分成字典中的单词
2. **状态转移方程**：
   f[i] = ∃ j ∈ [0, i) 使得 f[j] = True 且 s[j:i] ∈ words
   
   用数学符号表示为：
   f[i] = ⋁(f[j] ∧ (s[j:i] ∈ words))，其中j从0到i-1

3. **边界条件**：f[0] = True（空字符串总是可以被拆分）

**算法流程**：
- 初始化f[0] = True
- 对于每个位置i（从1到n），检查所有可能的拆分点j
- 如果前j个字符可以拆分（f[j]为True）且子串s[j:i]在字典中，则f[i]为True
- 最终f[n]表示整个字符串是否能被拆分

**时间复杂度**：O(n²)，其中n为字符串长度
**空间复杂度**：O(n)用于存储f数组

这种方法体现了动态规划的**最优子结构**特性，即大问题的最优解可以由小问题的最优解组合得到。

