---
title: "day_0044 "
date: 2025-09-14T10:18:01+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0044 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i >= len(s):
                return j >= len(p) or (p[j] == "*" and dfs(i, j + 1))
            if j >= len(p):
                return False
            if p[j] == "*":
                return dfs(i + 1, j) or dfs(i + 1, j + 1) or dfs(i, j + 1)
            return (p[j] == "?" or s[i] == p[j]) and dfs(i + 1, j + 1)

        return dfs(0, 0) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int f[m + 1][n + 1];
        memset(f, -1, sizeof(f));
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i >= m) {
                return j >= n || (p[j] == '*' && dfs(i, j + 1));
            }
            if (j >= n) {
                return false;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            if (p[j] == '*') {
                f[i][j] = dfs(i + 1, j) || dfs(i, j + 1) ? 1 : 0;
            } else {
                f[i][j] = (p[j] == '?' || s[i] == p[j]) && dfs(i + 1, j + 1) ? 1 : 0;
            }
            return f[i][j] == 1;
        };
        return dfs(0, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Boolean[][] f;
    private char[] s;
    private char[] p;
    private int m;
    private int n;

    public boolean isMatch(String s, String p) {
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        m = s.length();
        n = p.length();
        f = new Boolean[m][n];
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i >= m) {
            return j >= n || (p[j] == '*' && dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        if (p[j] == '*') {
            f[i][j] = dfs(i + 1, j) || dfs(i + 1, j + 1) || dfs(i, j + 1);
        } else {
            f[i][j] = (p[j] == '?' || s[i] == p[j]) && dfs(i + 1, j + 1);
        }
        return f[i][j];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0044  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache  # 使用缓存装饰器来存储已计算的结果，避免重复计算
        def dfs(i: int, j: int) -> bool:
            # 如果已经匹配完字符串s
            if i >= len(s):
                # 如果模式p也匹配完，或者当前是*号且可以跳过
                return j >= len(p) or (p[j] == "*" and dfs(i, j + 1))
            # 如果模式p已经用完但字符串s还有剩余字符
            if j >= len(p):
                return False
            # 如果当前模式字符是*号
            if p[j] == "*":
                # 三种可能：匹配多个字符、匹配一个字符、跳过*号
                return dfs(i + 1, j) or dfs(i + 1, j + 1) or dfs(i, j + 1)
            # 普通字符匹配：要么是?通配符，要么字符相同
            return (p[j] == "?" or s[i] == p[j]) and dfs(i + 1, j + 1)

        return dfs(0, 0)  # 从两个字符串的起始位置开始匹配
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int f[m + 1][n + 1];
        memset(f, -1, sizeof(f));
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i >= m) {
                return j >= n || (p[j] == '*' && dfs(i, j + 1));
            }
            if (j >= n) {
                return false;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            if (p[j] == '*') {
                f[i][j] = dfs(i + 1, j) || dfs(i, j + 1) ? 1 : 0;
            } else {
                f[i][j] = (p[j] == '?' || s[i] == p[j]) && dfs(i + 1, j + 1) ? 1 : 0;
            }
            return f[i][j] == 1;
        };
        return dfs(0, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Boolean[][] f;
    private char[] s;
    private char[] p;
    private int m;
    private int n;

    public boolean isMatch(String s, String p) {
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        m = s.length();
        n = p.length();
        f = new Boolean[m][n];
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i >= m) {
            return j >= n || (p[j] == '*' && dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        if (p[j] == '*') {
            f[i][j] = dfs(i + 1, j) || dfs(i + 1, j + 1) || dfs(i, j + 1);
        } else {
            f[i][j] = (p[j] == '?' || s[i] == p[j]) && dfs(i + 1, j + 1);
        }
        return f[i][j];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0044  数学解释

```python 
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i >= len(s):
                return j >= len(p) or (p[j] == "*" and dfs(i, j + 1))
            if j >= len(p):
                return False
            if p[j] == "*":
                return dfs(i + 1, j) or dfs(i + 1, j + 1) or dfs(i, j + 1)
            return (p[j] == "?" or s[i] == p[j]) and dfs(i + 1, j + 1)

        return dfs(0, 0) 
```


这段代码使用了**回溯+记忆化（Memoization）**的数学思想来解决通配符匹配问题。具体来说：

## 核心数学思想：递归与动态规划

### 1. 状态定义
定义状态 `dfs(i, j)` 表示：字符串 `s` 从第 `i` 个字符开始，模式串 `p` 从第 `j` 个字符开始是否能够匹配。

### 2. 递归关系（状态转移方程）
- **基本情况1**：如果已经匹配完 `s` (`i >= len(s)`)，那么只有当 `p` 也匹配完，或者 `p` 剩余部分都是 `*` 时才匹配成功
- **基本情况2**：如果 `p` 已经用完但 `s` 还有剩余字符，匹配失败
- **遇到 `*` 的情况**：`*` 可以匹配零个、一个或多个字符，因此有三种选择：
  - 匹配一个字符并继续使用 `*`：`dfs(i + 1, j)`
  - 匹配一个字符并消耗 `*`：`dfs(i + 1, j + 1)`  
  - 匹配零个字符：`dfs(i, j + 1)`
- **普通字符匹配**：当前字符必须匹配，然后继续匹配下一个字符

### 3. 记忆化优化
使用 `@cache` 装饰器存储已计算的状态 `(i, j)`，避免重复计算，将指数级的时间复杂度优化为多项式级别（O(mn)）。

### 4. 数学本质
这实际上是一个**有重叠子问题的递归问题**，通过记忆化技术实现了**自顶向下的动态规划**解决方案，将问题分解为更小的子问题并重用计算结果。

这种思想体现了**分治法**和**动态规划**的核心理念：将复杂问题分解为简单子问题，并通过存储中间结果来优化计算效率。


