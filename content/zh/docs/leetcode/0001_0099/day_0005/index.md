---
title: "day_0005 "
date: 2025-09-14T11:40:46+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0005 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        f = [[True] * n for _ in range(n)]
        k, mx = 0, 1
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = False
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                    if f[i][j] and mx < j - i + 1:
                        k, mx = i, j - i + 1
        return s[k : k + mx] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n, true));
        int k = 0, mx = 1;
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = false;
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                    if (f[i][j] && mx < j - i + 1) {
                        mx = j - i + 1;
                        k = i;
                    }
                }
            }
        }
        return s.substr(k, mx);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] f = new boolean[n][n];
        for (var g : f) {
            Arrays.fill(g, true);
        }
        int k = 0, mx = 1;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = false;
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1];
                    if (f[i][j] && mx < j - i + 1) {
                        mx = j - i + 1;
                        k = i;
                    }
                }
            }
        }
        return s.substring(k, k + mx);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0005  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)  # 获取字符串长度
        f = [[True] * n for _ in range(n)]  # 初始化动态规划表，f[i][j]表示s[i:j+1]是否为回文
        k, mx = 0, 1  # k记录最长回文子串起始位置，mx记录最长长度
        
        # 从后往前遍历，填充动态规划表
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = False  # 默认不是回文
                if s[i] == s[j]:  # 首尾字符相同
                    f[i][j] = f[i + 1][j - 1]  # 取决于内部子串是否为回文
                    if f[i][j] and mx < j - i + 1:  # 如果是回文且长度更大
                        k, mx = i, j - i + 1  # 更新最长回文子串信息
        
        return s[k : k + mx]  # 返回最长回文子串
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n, true));
        int k = 0, mx = 1;
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = false;
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                    if (f[i][j] && mx < j - i + 1) {
                        mx = j - i + 1;
                        k = i;
                    }
                }
            }
        }
        return s.substr(k, mx);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] f = new boolean[n][n];
        for (var g : f) {
            Arrays.fill(g, true);
        }
        int k = 0, mx = 1;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = false;
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1];
                    if (f[i][j] && mx < j - i + 1) {
                        mx = j - i + 1;
                        k = i;
                    }
                }
            }
        }
        return s.substring(k, k + mx);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0005  数学解释

```python 
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        f = [[True] * n for _ in range(n)]
        k, mx = 0, 1
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = False
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                    if f[i][j] and mx < j - i + 1:
                        k, mx = i, j - i + 1
        return s[k : k + mx] 
```


这段代码使用了**动态规划**的数学思想来解决最长回文子串问题。让我解释其核心数学原理：

## 1. 状态定义
定义二维数组 `f[i][j]` 表示子串 `s[i:j+1]` 是否为回文串

## 2. 状态转移方程
基于回文串的数学特性：
- **基础情况**：单个字符总是回文串（`f[i][i] = True`）
- **递推关系**：如果 `s[i] == s[j]` 且 `f[i+1][j-1]` 为真，则 `f[i][j]` 为真

数学表达式：
```
f[i][j] = True, 当 i = j
f[i][j] = (s[i] == s[j]), 当 j = i + 1  
f[i][j] = (s[i] == s[j] and f[i+1][j-1]), 当 j > i + 1
```

## 3. 填表顺序
采用**自底向上**的填表策略：
- 从右下角向左上角填充（`i` 从 `n-2` 递减到 `0`）
- 确保在计算 `f[i][j]` 时，`f[i+1][j-1]` 已经计算完成

## 4. 数学优化
- 使用变量 `k` 和 `mx` 记录当前找到的最长回文子串的起始位置和长度
- 避免重复计算，空间复杂度 O(n²)，时间复杂度 O(n²)

## 数学思想总结
1. **递推关系**：利用子问题的解构建原问题的解
2. **最优子结构**：最长回文子串问题具有最优子结构性质
3. **重叠子问题**：避免重复计算相同子问题
4. **边界处理**：正确处理长度为1和2的回文串基础情况

这种动态规划方法通过数学上的递推关系，系统地检查所有可能的子串，确保找到最优解。
