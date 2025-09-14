---
title: "day_0087 "
date: 2025-09-13T22:27:58+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0087 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @cache
        def dfs(i: int, j: int, k: int) -> bool:
            if k == 1:
                return s1[i] == s2[j]
            for h in range(1, k):
                if dfs(i, j, h) and dfs(i + h, j + h, k - h):
                    return True
                if dfs(i + h, j, k - h) and dfs(i, j + k - h, h):
                    return True
            return False

        return dfs(0, 0, len(s1)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int f[n][n][n + 1];
        memset(f, -1, sizeof(f));
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (f[i][j][k] != -1) {
                return f[i][j][k] == 1;
            }
            if (k == 1) {
                return s1[i] == s2[j];
            }
            for (int h = 1; h < k; ++h) {
                if (dfs(i, j, h) && dfs(i + h, j + h, k - h)) {
                    return f[i][j][k] = true;
                }
                if (dfs(i + h, j, k - h) && dfs(i, j + k - h, h)) {
                    return f[i][j][k] = true;
                }
            }
            return f[i][j][k] = false;
        };
        return dfs(0, 0, n);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Boolean[][][] f;
    private String s1;
    private String s2;

    public boolean isScramble(String s1, String s2) {
        int n = s1.length();
        this.s1 = s1;
        this.s2 = s2;
        f = new Boolean[n][n][n + 1];
        return dfs(0, 0, n);
    }

    private boolean dfs(int i, int j, int k) {
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        if (k == 1) {
            return s1.charAt(i) == s2.charAt(j);
        }
        for (int h = 1; h < k; ++h) {
            if (dfs(i, j, h) && dfs(i + h, j + h, k - h)) {
                return f[i][j][k] = true;
            }
            if (dfs(i + h, j, k - h) && dfs(i, j + k - h, h)) {
                return f[i][j][k] = true;
            }
        }
        return f[i][j][k] = false;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0087  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @cache  # 使用缓存装饰器，避免重复计算
        def dfs(i: int, j: int, k: int) -> bool:
            # 递归函数：判断s1从i开始，s2从j开始的长度为k的子串是否互为扰乱字符串
            if k == 1:  # 基本情况：当子串长度为1时
                return s1[i] == s2[j]  # 直接比较两个字符是否相等
            
            # 尝试所有可能的分割点
            for h in range(1, k):  # h从1到k-1，表示分割位置
                # 情况1：不交换左右子树
                if dfs(i, j, h) and dfs(i + h, j + h, k - h):
                    return True
                # 情况2：交换左右子树
                if dfs(i + h, j, k - h) and dfs(i, j + k - h, h):
                    return True
            return False  # 所有分割方式都不满足条件

        return dfs(0, 0, len(s1))  # 从整个字符串开始递归判断
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int f[n][n][n + 1];
        memset(f, -1, sizeof(f));
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (f[i][j][k] != -1) {
                return f[i][j][k] == 1;
            }
            if (k == 1) {
                return s1[i] == s2[j];
            }
            for (int h = 1; h < k; ++h) {
                if (dfs(i, j, h) && dfs(i + h, j + h, k - h)) {
                    return f[i][j][k] = true;
                }
                if (dfs(i + h, j, k - h) && dfs(i, j + k - h, h)) {
                    return f[i][j][k] = true;
                }
            }
            return f[i][j][k] = false;
        };
        return dfs(0, 0, n);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Boolean[][][] f;
    private String s1;
    private String s2;

    public boolean isScramble(String s1, String s2) {
        int n = s1.length();
        this.s1 = s1;
        this.s2 = s2;
        f = new Boolean[n][n][n + 1];
        return dfs(0, 0, n);
    }

    private boolean dfs(int i, int j, int k) {
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        if (k == 1) {
            return s1.charAt(i) == s2.charAt(j);
        }
        for (int h = 1; h < k; ++h) {
            if (dfs(i, j, h) && dfs(i + h, j + h, k - h)) {
                return f[i][j][k] = true;
            }
            if (dfs(i + h, j, k - h) && dfs(i, j + k - h, h)) {
                return f[i][j][k] = true;
            }
        }
        return f[i][j][k] = false;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0087  数学解释

```python 
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @cache
        def dfs(i: int, j: int, k: int) -> bool:
            if k == 1:
                return s1[i] == s2[j]
            for h in range(1, k):
                if dfs(i, j, h) and dfs(i + h, j + h, k - h):
                    return True
                if dfs(i + h, j, k - h) and dfs(i, j + k - h, h):
                    return True
            return False

        return dfs(0, 0, len(s1)) 
```


这段代码使用了**分治思想**和**记忆化搜索**来解决字符串扰乱问题。

## 数学思想解释：

### 1. 问题分解（分治思想）
将大问题分解为小问题：判断长度为k的子串是否互为扰乱字符串，可以分解为：
- 检查所有可能的分割点h（1 ≤ h < k）
- 对于每个分割点，考虑两种扰乱情况：
  a) 不交换：前h个字符扰乱匹配，后k-h个字符扰乱匹配
  b) 交换：前h个字符与后h个字符交换位置后匹配

### 2. 递归关系
定义状态dfs(i, j, k)：判断s1从i开始、s2从j开始的长度为k的子串是否互为扰乱字符串

递归基：当k=1时，直接比较单个字符是否相等

递归步骤：对于每个可能的分割位置h：
- 情况1：`dfs(i, j, h) and dfs(i+h, j+h, k-h)`（不交换）
- 情况2：`dfs(i+h, j, k-h) and dfs(i, j+k-h, h)`（交换）

### 3. 记忆化优化
使用@cache装饰器缓存已计算的结果，避免重复计算，将时间复杂度从指数级降低到多项式级

### 4. 数学表示
设f(i,j,k)表示s1[i:i+k]和s2[j:j+k]是否互为扰乱字符串，则：
$$
f(i,j,k) = 
    s1[i] == s2[j]                      if k = 1
    ∨_{h=1}^{k-1} [f(i,j,h) ∧ f(i+h,j+h,k-h)] ∨ [f(i+h,j,k-h) ∧ f(i,j+k-h,h)]  if k > 1
$$

这种解法体现了**动态规划**的核心思想：将原问题分解为子问题，并利用子问题的解来构建原问题的解。


