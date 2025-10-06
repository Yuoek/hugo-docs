---
title: "2730_FindtheLongestSemi-RepetitiveSubstring"
date: 2025-10-06T00:42:37+08:00
weight: 2730
tags: [字符串, 滑动窗口]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2730. 找到最长的半重复子字符串](https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring)

[English Version](../en/2730-30/2730_FindtheLongestSemi-RepetitiveSubstring)

## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，这个字符串只包含&nbsp;<code>0</code>&nbsp;到&nbsp;<code>9</code>&nbsp;的数字字符。</p>

<p>如果一个字符串&nbsp;<code>t</code>&nbsp;中至多有一对相邻字符是相等的，那么称这个字符串 <code>t</code> 是 <strong>半重复的</strong>&nbsp;。例如，<code>"0010"</code>&nbsp;、<code>"002020"</code>&nbsp;、<code>"0123"</code>&nbsp;、<code>"2002"</code>&nbsp;和 <code>"54944"</code>&nbsp;是半重复字符串，而 <code>"00101022"</code>&nbsp;（相邻的相同数字对是 00 和 22）和 <code>"1101234883"</code>&nbsp;（相邻的相同数字对是 11 和 88）不是半重复字符串。</p>

<p>请你返回 <code>s</code>&nbsp;中最长 <strong>半重复</strong>&nbsp;<span data-keyword="substring-nonempty">子字符串</span> 的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "52233"</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>最长的半重复子字符串是 "5223"。整个字符串 "52233" 有两个相邻的相同数字对 22 和 33，但最多只能选取一个。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "5494"</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;是一个半重复字符串。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "1111111"</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>最长的半重复子字符串是 "11"。子字符串 "111" 有两个相邻的相同数字对，但最多允许选取一个。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '9'</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：双指针

我们用双指针维护一个区间 $s[j..i]$，使得区间内最多只有一个相邻字符相等，初始时 $j = 0$, $i = 1$。初始化答案 $ans = 1$。

我们用 $cnt$ 记录区间内相邻字符相等的个数，如果 $cnt \gt 1$，那么我们就需要移动左指针 $j$，直到 $cnt \le 1$。每一次，我们更新答案为 $ans = \max(ans, i - j + 1)$。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针（优化）

由于题目只需要我们找到最长的半重复子字符串的长度，因此，每次当区间内相邻字符相等的个数超过 $1$ 时，我们可以只移动左指针 $l$ 一次，右指针 $r$ 继续向右移动。这样可以保证子字符串的长度不会减小。

最后答案为 $n - l$，其中 $n$ 是字符串的长度。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        cnt = l = 0
        for i in range(1, n):
            cnt += s[i] == s[i - 1]
            if cnt > 1:
                cnt -= s[l] == s[l + 1]
                l += 1
        return n - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s.charAt(i) == s.charAt(i - 1) ? 1 : 0;
            if (cnt > 1) {
                cnt -= s.charAt(l) == s.charAt(++l) ? 1 : 0;
            }
        }
        return n - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s[i] == s[i - 1] ? 1 : 0;
            if (cnt > 1) {
                cnt -= s[l] == s[++l] ? 1 : 0;
            }
        }
        return n - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSemiRepetitiveSubstring(s string) (ans int) {
	cnt, l := 0, 0
	for i, c := range s[1:] {
		if byte(c) == s[i] {
			cnt++
		}
		if cnt > 1 {
			if s[l] == s[l+1] {
				cnt--
			}
			l++
		}
	}
	return len(s) - l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSemiRepetitiveSubstring(s: string): number {
    const n = s.length;
    let [cnt, l] = [0, 0];
    for (let i = 1; i < n; ++i) {
        cnt += s[i] === s[i - 1] ? 1 : 0;
        if (cnt > 1) {
            cnt -= s[l] === s[l + 1] ? 1 : 0;
            ++l;
        }
    }
    return n - l;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        cnt = l = 0
        for i in range(1, n):
            cnt += s[i] == s[i - 1]
            if cnt > 1:
                cnt -= s[l] == s[l + 1]
                l += 1
        return n - l
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s.charAt(i) == s.charAt(i - 1) ? 1 : 0;
            if (cnt > 1) {
                cnt -= s.charAt(l) == s.charAt(++l) ? 1 : 0;
            }
        }
        return n - l;
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
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s[i] == s[i - 1] ? 1 : 0;
            if (cnt > 1) {
                cnt -= s[l] == s[++l] ? 1 : 0;
            }
        }
        return n - l;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}