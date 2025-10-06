---
title: "0214_ShortestPalindrome"
date: 2025-10-06T00:42:37+08:00
weight: 0214
tags: [字符串, 字符串匹配, 哈希函数, 滚动哈希]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [214. 最短回文串](https://leetcode.cn/problems/shortest-palindrome)

[English Version](../en/0214-14/0214_ShortestPalindrome)

## 题目描述

<!-- description:start -->

<p>给定一个字符串 <em><strong>s</strong></em>，你可以通过在字符串前面添加字符将其转换为<span data-keyword="palindrome-string">回文串</span>。找到并返回可以用这种方式转换的最短回文串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aacecaaa"
<strong>输出：</strong>"aaacecaaa"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>"dcbabcd"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：字符串哈希

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 0。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

取一固定值 BASE，把字符串看作是 BASE 进制数，并分配一个大于 0 的数值，代表每种字符。一般来说，我们分配的数值都远小于 BASE。例如，对于小写字母构成的字符串，可以令 a=1, b=2, ..., z=26。取一固定值 MOD，求出该 BASE 进制对 M 的余数，作为该字符串的 hash 值。

一般来说，取 BASE=131 或者 BASE=13331，此时 hash 值产生的冲突概率极低。只要两个字符串 hash 值相同，我们就认为两个字符串是相等的。通常 MOD 取 2^64，C++ 里，可以直接使用 unsigned long long 类型存储这个 hash 值，在计算时不处理算术溢出问题，产生溢出时相当于自动对 2^64 取模，这样可以避免低效取模运算。

除了在极特殊构造的数据上，上述 hash 算法很难产生冲突，一般情况下上述 hash 算法完全可以出现在题目的标准答案中。我们还可以多取一些恰当的 BASE 和 MOD 的值（例如大质数），多进行几组 hash 运算，当结果都相同时才认为原字符串相等，就更加难以构造出使这个 hash 产生错误的数据。

对于本题，问题等价于**找到字符串 s 的最长回文前缀**。

记 s 的长度为 n，其最长回文前缀的长度为 m，将 s 的后 n-m 个字符反序并添加到 s 的前面即可构成最短回文串。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### Rust



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：KMP 算法

根据题目描述，我们需要将字符串 $s$ 反转，得到字符串 $\textit{rev}$，然后求出字符串 $rev$ 的后缀与字符串 $s$ 的前缀的最长公共部分。我们可以使用 KMP 算法，将字符串 $s$ 与字符串 $rev$ 连接起来，求出其最长前缀与最长后缀的最长公共部分。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        t = s + "#" + s[::-1] + "$"
        n = len(t)
        next = [0] * n
        next[0] = -1
        i, j = 2, 0
        while i < n:
            if t[i - 1] == t[j]:
                j += 1
                next[i] = j
                i += 1
            elif j:
                j = next[j]
            else:
                next[i] = 0
                i += 1
        return s[::-1][: -next[-1]] + s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        char[] t = (s + "#" + rev + "$").toCharArray();
        int n = t.length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return rev.substring(0, s.length() - next[n - 1]) + s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s + "#" + string(s.rbegin(), s.rend()) + "$";
        int n = t.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return string(s.rbegin(), s.rbegin() + s.size() - next[n - 1]) + s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPalindrome(s string) string {
	t := s + "#" + reverse(s) + "$"
	n := len(t)
	next := make([]int, n)
	next[0] = -1
	for i, j := 2, 0; i < n; {
		if t[i-1] == t[j] {
			j++
			next[i] = j
			i++
		} else if j > 0 {
			j = next[j]
		} else {
			next[i] = 0
			i++
		}
	}
	return reverse(s)[:len(s)-next[n-1]] + s
}

func reverse(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn shortest_palindrome(s: String) -> String {
        let base = 131;
        let (mut idx, mut prefix, mut suffix, mut mul) = (0, 0, 0, 1);
        for (i, c) in s.chars().enumerate() {
            let t = (c as u64) - ('0' as u64) + 1;
            prefix = prefix * base + t;
            suffix = suffix + t * mul;
            mul *= base;
            if prefix == suffix {
                idx = i + 1;
            }
        }
        if idx == s.len() {
            s
        } else {
            let x: String = (&s[idx..]).chars().rev().collect();
            String::from(x + &s)
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string ShortestPalindrome(string s) {
        char[] t = (s + "#" + new string(s.Reverse().ToArray()) + "$").ToCharArray();
        int n = t.Length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return new string(s.Substring(next[n - 1]).Reverse().ToArray()).Substring(0, s.Length - next[n - 1]) + s;
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestPalindrome(s: string): string {
    const rev = s.split('').reverse().join('');
    const t = s + '#' + rev + '$';
    const n = t.length;
    const next: number[] = Array(n).fill(0);
    next[0] = -1;
    for (let i = 2, j = 0; i < n; ) {
        if (t[i - 1] === t[j]) {
            next[i++] = ++j;
        } else if (j > 0) {
            j = next[j];
        } else {
            next[i++] = 0;
        }
    }
    return rev.slice(0, -next[n - 1]) + s;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        t = s + "#" + s[::-1] + "$"
        n = len(t)
        next = [0] * n
        next[0] = -1
        i, j = 2, 0
        while i < n:
            if t[i - 1] == t[j]:
                j += 1
                next[i] = j
                i += 1
            elif j:
                j = next[j]
            else:
                next[i] = 0
                i += 1
        return s[::-1][: -next[-1]] + s
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        char[] t = (s + "#" + rev + "$").toCharArray();
        int n = t.length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return rev.substring(0, s.length() - next[n - 1]) + s;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s + "#" + string(s.rbegin(), s.rend()) + "$";
        int n = t.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return string(s.rbegin(), s.rbegin() + s.size() - next[n - 1]) + s;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}