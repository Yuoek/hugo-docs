---
title: "day_0091 "
date: 2025-09-13T21:37:55+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0091 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        f = [1] + [0] * n
        for i, c in enumerate(s, 1):
            if c != "0":
                f[i] = f[i - 1]
            if i > 1 and s[i - 2] != "0" and int(s[i - 2 : i]) <= 26:
                f[i] += f[i - 2]
        return f[n] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                f[i] = f[i - 1];
            }
            if (i > 1 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) != '0') {
                f[i] = f[i - 1];
            }
            if (i > 1 && s.charAt(i - 2) != '0' && Integer.valueOf(s.substring(i - 2, i)) <= 26) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0091  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        # 定义字符串的长度
        n = len(s)
        # 初始化动态规划数组f，f[0]表示空字符串的解码方式为1
        f = [1] + [0] * n
        # 遍历字符串s的每个字符，使用enumerate(s, 1)从索引1开始
        for i, c in enumerate(s, 1):
            # 如果当前字符c不是"0"，说明它可以单独解码，继承前一个状态的解码方式
            if c != "0":
                f[i] = f[i - 1]
            # 如果当前字符和前一个字符组合成的数字在1到26之间，且前一个字符不为"0"
            # 说明可以把这两个字符作为一个整体解码，累加f[i-2]的解码方式
            if i > 1 and s[i - 2] != "0" and int(s[i - 2 : i]) <= 26:
                f[i] += f[i - 2]
        # 返回动态规划数组f的最后一个值，即字符串s的总解码方式
        return f[n]
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                f[i] = f[i - 1];
            }
            if (i > 1 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) != '0') {
                f[i] = f[i - 1];
            }
            if (i > 1 && s.charAt(i - 2) != '0' && Integer.valueOf(s.substring(i - 2, i)) <= 26) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0091  数学解释

```python 
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        f = [1] + [0] * n
        for i, c in enumerate(s, 1):
            if c != "0":
                f[i] = f[i - 1]
            if i > 1 and s[i - 2] != "0" and int(s[i - 2 : i]) <= 26:
                f[i] += f[i - 2]
        return f[n] 
```


这段代码是用来解决 **解码方法（Decode Ways）** 问题的。我们可以用数学思想来解释它的逻辑，特别是结合动态规划（Dynamic Programming, DP）的思想。

### 问题背景
给定一个只包含数字的字符串 `s`，每个数字可以解码成一个字母（1 对应 'A', 2 对应 'B', ..., 26 对应 'Z'）。问字符串 `s` 有多少种不同的解码方法？

例如：
- 输入 `"12"`，可以解码为 `"AB"` 或 `"L"`，共有 2 种解码方法。
- 输入 `"226"`，可以解码为 `"BZ"`、`"VF"` 或 `"BBF"`，共有 3 种解码方法。

### 数学思想与动态规划
我们将问题转化为一个 **最优子结构问题**，并用动态规划解决。定义 `f[i]` 表示字符串前 `i` 个字符可以解码的总方法数。

#### 状态转移方程
我们通过以下两种方式计算 `f[i]`：
1. 如果当前字符 `s[i-1]` 不是 `'0'`，那么它可以单独解码为一个字母，此时可以继承前 `i-1` 个字符的解码方法数：  
   \\[
   f[i] += f[i-1]
   \\]
2. 如果当前字符和前一个字符组合成一个合法的两位数（10 ≤ 两位数 ≤ 26），那么它可以作为一个整体解码为一个字母，此时可以继承前 `i-2` 个字符的解码方法数：  
   \\[
   f[i] += f[i-2]
   \\]

#### 初始条件
- `f[0] = 1`：空字符串有一种解码方法（即不解码）。
- `f[1]` 的值取决于 `s[0]` 是否为 `'0'`。如果 `s[0] != '0'`，则 `f[1] = 1`；否则解码无效。

#### 遍历字符串
我们从左到右遍历字符串，根据上述两种情况逐步更新 `f[i]` 的值。

---

### 代码逐步解释
```python
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)  # 字符串长度
        f = [1] + [0] * n  # 初始化 DP 数组，f[0] = 1，其余初始化为 0
```
- `f` 是一个数组，`f[i]` 表示前 `i` 个字符的解码方法数。
- 初始值 `f[0] = 1` 表示空字符串有一种解码方法。

```python
        for i, c in enumerate(s, 1):  # 遍历字符串，从索引 1 开始（对应第 1 个字符）
            if c != "0":  # 当前字符不是 '0'，可以单独解码
                f[i] = f[i - 1]  # 继承前 i-1 个字符的解码方法数
```
- 如果当前字符 `s[i-1]` 不是 `'0'`，那么它可以单独解码。此时，`f[i]` 至少等于 `f[i-1]`。

```python
            if i > 1 and s[i - 2] != "0" and int(s[i - 2 : i]) <= 26:
                f[i] += f[i - 2]  # 如果前两位字符可以组成一个合法的两位数，累加 f[i-2]
```
- 如果当前字符和前一个字符可以组成一个合法的两位数（即 10 ≤ 两位数 ≤ 26），那么它可以作为一个整体解码，继承前 `i-2` 个字符的解码方法数。

```python
        return f[n]  # 返回前 n 个字符的解码方法数
```
- 最终结果是 `f[n]`，即整个字符串的解码方法数。

---

### 举例分析
以输入 `s = "226"` 为例：
1. 初始化：`f = [1, 0, 0, 0]`。
2. 遍历字符串：
   - `i = 1`，`c = '2'`：`f[1] = f[0] = 1`（单独解码）。
     - `f = [1, 1, 0, 0]`
   - `i = 2`，`c = '2'`：`f[2] = f[1] = 1`（单独解码）。
     - `s[0:2] = "22"` 是合法两位数，`f[2] += f[0] = 1`。
     - `f = [1, 1, 2, 0]`
   - `i = 3`，`c = '6'`：`f[3] = f[2] = 2`（单独解码）。
     - `s[1:3] = "26"` 是合法两位数，`f[3] += f[1] = 1`。
     - `f = [1, 1, 2, 3]`
3. 返回 `f[3] = 3`。

---

### 时间和空间复杂度
- **时间复杂度**：`O(n)`，遍历字符串一次。
- **空间复杂度**：`O(n)`，使用了长度为 `n+1` 的 DP 数组 `f`。如果优化为只用两个变量存储状态，可以降为 `O(1)`。

这段代码本质上利用了数学中的递推关系和动态规划思想，逐步构建出问题的解。


