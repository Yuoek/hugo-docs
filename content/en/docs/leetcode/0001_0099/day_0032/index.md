---
title: "day_0032 "
date: 2025-09-14T10:43:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0032 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        f = [0] * (n + 1)
        for i, c in enumerate(s, 1):
            if c == ")":
                if i > 1 and s[i - 2] == "(":
                    f[i] = f[i - 2] + 2
                else:
                    j = i - f[i - 1] - 1
                    if j and s[j - 1] == "(":
                        f[i] = f[i - 1] + 2 + f[j - 1]
        return max(f) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j && s[j - 1] == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
            }
        }
        return *max_element(f, f + n + 1);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s.charAt(i - 1) == ')') {
                if (s.charAt(i - 2) == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s.charAt(j - 1) == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.max(ans, f[i]);
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0032  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)  # 获取字符串长度
        f = [0] * (n + 1)  # 初始化动态规划数组，f[i]表示以第i个字符结尾的最长有效括号长度
        for i, c in enumerate(s, 1):  # 遍历字符串，索引从1开始
            if c == ")":  # 当前字符为右括号时才处理
                if i > 1 and s[i - 2] == "(":  # 情况1：前一个字符是左括号，形成"()"对
                    f[i] = f[i - 2] + 2  # 当前有效长度 = 前前位置的长度 + 2
                else:  # 情况2：前一个字符是右括号
                    j = i - f[i - 1] - 1  # 计算与当前右括号匹配的左括号位置
                    if j and s[j - 1] == "(":  # 如果找到匹配的左括号
                        f[i] = f[i - 1] + 2 + f[j - 1]  # 当前长度 = 前一个长度 + 2 + 匹配左括号前的位置长度
        return max(f)  # 返回所有位置中的最大值
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j && s[j - 1] == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
            }
        }
        return *max_element(f, f + n + 1);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s.charAt(i - 1) == ')') {
                if (s.charAt(i - 2) == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s.charAt(j - 1) == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.max(ans, f[i]);
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0032  数学解释

```python 
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        f = [0] * (n + 1)
        for i, c in enumerate(s, 1):
            if c == ")":
                if i > 1 and s[i - 2] == "(":
                    f[i] = f[i - 2] + 2
                else:
                    j = i - f[i - 1] - 1
                    if j and s[j - 1] == "(":
                        f[i] = f[i - 1] + 2 + f[j - 1]
        return max(f) 
```


这段代码使用了**动态规划**的数学思想来解决最长有效括号子串问题。让我解释其中的数学逻辑：

## 核心思想
定义 `f[i]` 表示以第 `i` 个字符结尾的最长有效括号子串长度（索引从1开始）

## 状态转移方程的数学推导

### 情况1：当前字符是 `)` 且前一个字符是 `(`
```python
if i > 1 and s[i - 2] == "(":
    f[i] = f[i - 2] + 2
```
**数学解释**：形成 `()` 这样的有效对，长度增加2，并继承 `i-2` 位置的最优解

### 情况2：嵌套括号的情况
```python
j = i - f[i - 1] - 1
if j and s[j - 1] == "(":
    f[i] = f[i - 1] + 2 + f[j - 1]
```
**数学解释**：
- `j` 表示与当前 `)` 匹配的 `(` 的位置
- `f[i - 1]` 是前一个位置的最长有效长度
- `f[j - 1]` 是匹配位置之前的最长有效长度
- 总长度 = 内部嵌套长度 + 当前匹配的2个字符 + 前面可能存在的有效长度

## 数学优化
- **空间复杂度**：O(n)，使用一维DP数组
- **时间复杂度**：O(n)，单次遍历字符串
- **最优子结构**：每个状态只依赖于前面已计算的状态

这种解法体现了动态规划的**最优子结构**和**重叠子问题**特性，通过数学归纳的方式逐步构建最优解。


