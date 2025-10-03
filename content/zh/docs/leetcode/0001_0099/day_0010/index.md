---
title: "day_0010 "
date: 2025-09-14T11:30:38+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0010 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i, j):
            if j >= n:
                return i == m
            if j + 1 < n and p[j + 1] == '*':
                return dfs(i, j + 2) or (
                    i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j)
                )
            return i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1)

        m, n = len(s), len(p)
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
        memset(f, 0, sizeof f);
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (j >= n) {
                return i == m;
            }
            if (f[i][j]) {
                return f[i][j] == 1;
            }
            int res = -1;
            if (j + 1 < n && p[j + 1] == '*') {
                if (dfs(i, j + 2) or (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j))) {
                    res = 1;
                }
            } else if (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1)) {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
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
    private String s;
    private String p;
    private int m;
    private int n;

    public boolean isMatch(String s, String p) {
        m = s.length();
        n = p.length();
        f = new Boolean[m + 1][n + 1];
        this.s = s;
        this.p = p;
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (j >= n) {
            return i == m;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        boolean res = false;
        if (j + 1 < n && p.charAt(j + 1) == '*') {
            res = dfs(i, j + 2)
                || (i < m && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') && dfs(i + 1, j));
        } else {
            res = i < m && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') && dfs(i + 1, j + 1);
        }
        return f[i][j] = res;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0010  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache  # 使用缓存装饰器来存储已计算的结果，避免重复计算
        def dfs(i, j):  # 定义深度优先搜索函数，i表示s的索引，j表示p的索引
            if j >= n:  # 如果模式串p已经匹配完毕
                return i == m  # 检查字符串s是否也匹配完毕
            
            if j + 1 < n and p[j + 1] == '*':  # 如果下一个字符是'*'（通配符）
                return dfs(i, j + 2) or (  # 两种情况：1.跳过当前字符和'*'
                    i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j)  # 2.当前字符匹配且继续使用'*'
                )
            
            return i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1)  # 普通字符匹配情况

        m, n = len(s), len(p)  # 获取字符串s和模式串p的长度
        return dfs(0, 0)  # 从两个字符串的起始位置开始递归匹配
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (j >= n) {
                return i == m;
            }
            if (f[i][j]) {
                return f[i][j] == 1;
            }
            int res = -1;
            if (j + 1 < n && p[j + 1] == '*') {
                if (dfs(i, j + 2) or (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j))) {
                    res = 1;
                }
            } else if (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1)) {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
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
    private String s;
    private String p;
    private int m;
    private int n;

    public boolean isMatch(String s, String p) {
        m = s.length();
        n = p.length();
        f = new Boolean[m + 1][n + 1];
        this.s = s;
        this.p = p;
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (j >= n) {
            return i == m;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        boolean res = false;
        if (j + 1 < n && p.charAt(j + 1) == '*') {
            res = dfs(i, j + 2)
                || (i < m && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') && dfs(i + 1, j));
        } else {
            res = i < m && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') && dfs(i + 1, j + 1);
        }
        return f[i][j] = res;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0010  数学解释

```python 
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i, j):
            if j >= n:
                return i == m
            if j + 1 < n and p[j + 1] == '*':
                return dfs(i, j + 2) or (
                    i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j)
                )
            return i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1)

        m, n = len(s), len(p)
        return dfs(0, 0) 
```


这段代码实现的是正则表达式匹配功能，使用了**动态规划**和**记忆化搜索**的数学思想。

## 核心数学思想

### 1. 动态规划 (Dynamic Programming)
- **状态定义**: `dfs(i, j)` 表示字符串 `s` 的前 `i` 个字符能否与模式 `p` 的前 `j` 个字符匹配
- **最优子结构**: 当前匹配结果依赖于子问题的匹配结果
- **重叠子问题**: 相同的 `(i, j)` 状态会被多次计算，因此使用记忆化优化

### 2. 递归与分治 (Recursion & Divide and Conquer)
将复杂问题分解为更小的子问题：
- 当遇到 `*` 时：考虑两种情况（使用0次或多次）
- 当遇到普通字符或 `.` 时：检查当前字符是否匹配

### 3. 状态转移方程
基于模式字符串的当前字符：
- **情况1**: 下一个字符是 `*` (通配符)
  - 选择1：跳过 `x*` (匹配0次)：`dfs(i, j+2)`
  - 选择2：匹配当前字符并继续使用 `*`：`(s[i]==p[j] or p[j]=='.') and dfs(i+1, j)`

- **情况2**: 普通字符或 `.`
  - 必须匹配当前字符：`(s[i]==p[j] or p[j]=='.') and dfs(i+1, j+1)`

### 4. 边界条件
- **终止条件**: 当模式字符串用完时 (`j >= n`)，检查字符串是否也刚好用完
- **越界检查**: 确保索引不超出字符串范围

## 数学复杂度
- **时间复杂度**: O(m×n)，因为有 m×n 个状态
- **空间复杂度**: O(m×n)，用于存储记忆化结果

这种解法体现了**将复杂问题分解为可重复解决的子问题**的数学思维，是动态规划思想的典型应用。


