---
title: "day_0131 "
date: 2025-09-21T09:59:19+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0131 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(i, n):
                if f[i][j]:
                    t.append(s[i : j + 1])
                    dfs(j + 1)
                    t.pop()

        n = len(s)
        f = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = s[i] == s[j] and f[i + 1][j - 1]
        ans = []
        t = []
        dfs(0)
        return ans 
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

## LeetCode_0131  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(i: int):
            if i == n:  # 如果已经处理完所有字符
                ans.append(t[:])  # 将当前分割方案添加到结果中
                return
            for j in range(i, n):  # 遍历所有可能的结束位置
                if f[i][j]:  # 如果从i到j的子串是回文
                    t.append(s[i : j + 1])  # 将该回文子串添加到当前分割方案
                    dfs(j + 1)  # 递归处理剩余字符串
                    t.pop()  # 回溯，移除最后添加的子串

        n = len(s)  # 字符串长度
        # 创建动态规划表f，f[i][j]表示s[i:j+1]是否为回文
        f = [[True] * n for _ in range(n)]
        # 从后向前填充动态规划表
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                # 判断s[i:j+1]是否为回文：首尾字符相同且内部子串是回文
                f[i][j] = s[i] == s[j] and f[i + 1][j - 1]
        ans = []  # 存储所有分割方案
        t = []  # 存储当前分割方案
        dfs(0)  # 从索引0开始深度优先搜索
        return ans  # 返回所有可能的分割方案
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

## LeetCode_0131  数学解释

```python 
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(i, n):
                if f[i][j]:
                    t.append(s[i : j + 1])
                    dfs(j + 1)
                    t.pop()

        n = len(s)
        f = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = s[i] == s[j] and f[i + 1][j - 1]
        ans = []
        t = []
        dfs(0)
        return ans 
```


这段代码使用了**动态规划**和**回溯法**的数学思想来解决字符串分割问题：

## 1. 动态规划思想（预处理回文判断）
- 使用二维数组 `f[i][j]` 表示子串 `s[i:j+1]` 是否为回文
- 状态转移方程：`f[i][j] = (s[i] == s[j]) and f[i+1][j-1]`
- 这是典型的**区间DP**思想，通过已知小区间的结果推导大区间的结果
- 从后向前遍历确保在计算 `f[i][j]` 时 `f[i+1][j-1]` 已经计算完成

## 2. 回溯法思想（深度优先搜索）
- 使用DFS遍历所有可能的分割方案
- 对于每个起始位置 `i`，尝试所有可能的结束位置 `j`（其中 `s[i:j+1]` 是回文）
- 递归调用 `dfs(j+1)` 处理剩余字符串
- 使用 `t.pop()` 进行回溯，撤销当前选择，尝试其他可能性

## 3. 组合数学思想
- 本质上是在寻找所有满足条件的**划分方案**
- 每个划分方案都是原字符串的一个**有序划分**，其中每个子串都是回文
- 算法通过系统性的搜索避免了重复计算和遗漏

## 时间复杂度分析
- 预处理：O(n²)
- 回溯：最坏情况下 O(n·2ⁿ)（当所有子串都是回文时）
- 总体：O(n·2ⁿ)

这种组合使用动态规划和回溯的方法，既保证了正确性，又通过预处理优化了回文判断的效率。


