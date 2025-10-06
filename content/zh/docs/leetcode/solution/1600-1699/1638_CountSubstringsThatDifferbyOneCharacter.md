---
title: "1638_CountSubstringsThatDifferbyOneCharacter"
date: 2025-10-06T00:42:37+08:00
weight: 1638
tags: [哈希表, 字符串, 动态规划, 枚举]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1638. 统计只差一个字符的子串数目](https://leetcode.cn/problems/count-substrings-that-differ-by-one-character)

[English Version](../en/1638-38/1638_CountSubstringsThatDifferbyOneCharacter)

## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;，请你找出 <code>s</code>&nbsp;中的非空子串的数目，这些子串满足替换 <strong>一个不同字符</strong>&nbsp;以后，是 <code>t</code>&nbsp;串的子串。换言之，请你找到 <code>s</code>&nbsp;和 <code>t</code>&nbsp;串中 <strong>恰好</strong>&nbsp;只有一个字符不同的子字符串对的数目。</p>

<p>比方说，&nbsp;<code>"<u>compute</u>r"</code>&nbsp;and&nbsp;<code>"<u>computa</u>tion"&nbsp;</code>只有一个字符不同：&nbsp;<code>'e'</code>/<code>'a'</code>&nbsp;，所以这一对子字符串会给答案加 1 。</p>

<p>请你返回满足上述条件的不同子字符串对数目。</p>

<p>一个 <strong>子字符串</strong>&nbsp;是一个字符串中连续的字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aba", t = "baba"
<b>输出：</b>6
<strong>解释：</strong>以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("<strong>a</strong>ba", "<strong>b</strong>aba")
("<strong>a</strong>ba", "ba<strong>b</strong>a")
("ab<strong>a</strong>", "<strong>b</strong>aba")
("ab<strong>a</strong>", "ba<strong>b</strong>a")
("a<strong>b</strong>a", "b<strong>a</strong>ba")
("a<strong>b</strong>a", "bab<strong>a</strong>")
加粗部分分别表示 s 和 t 串选出来的子字符串。
</pre>

<strong>示例 2：</strong>

<pre>
<b>输入：</b>s = "ab", t = "bb"
<b>输出：</b>3
<strong>解释：</strong>以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("<strong>a</strong>b", "<strong>b</strong>b")
("<strong>a</strong>b", "b<strong>b</strong>")
("<strong>ab</strong>", "<strong>bb</strong>")
加粗部分分别表示 s 和 t 串选出来的子字符串。
</pre>

<strong>示例 3：</strong>

<pre>
<b>输入：</b>s = "a", t = "a"
<b>输出：</b>0
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>s = "abe", t = "bbc"
<b>输出：</b>10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 100</code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举字符串 $s$ 和 $t$ 中不同的那个字符位置，然后分别向两边扩展，直到遇到不同的字符为止，这样就可以得到以该位置为中心的满足条件的子串对数目。我们记左边扩展的相同字符个数为 $l$，右边扩展的相同字符个数为 $r$，那么以该位置为中心的满足条件的子串对数目为 $(l + 1) \times (r + 1)$，累加到答案中即可。

枚举结束后，即可得到答案。

时间复杂度 $O(m \times n \times \min(m, n))$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别为字符串 $s$ 和 $t$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理 + 枚举

方法一中，我们每次需要分别往左右两边扩展，得出 $l$ 和 $r$ 的值。实际上，我们可以预处理出以每个位置 $(i, j)$ 结尾的最长相同后缀的长度，以及以每个位置 $(i, j)$ 开头的最长相同前缀的长度，分别记录在数组 $f$ 和 $g$ 中。

接下来，与方法一类似，我们枚举字符串 $s$ 和 $t$ 中不同的那个字符位置 $(i, j)$，那么以该位置为中心的满足条件的子串对数目为 $(f[i][j] + 1) \times (g[i + 1][j + 1] + 1)$，累加到答案中即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为字符串 $s$ 和 $t$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans = 0
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i, a in enumerate(s, 1):
            for j, b in enumerate(t, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1] + 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    g[i][j] = g[i + 1][j + 1] + 1
                else:
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubstrings(String s, String t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int[][] f = new int[m + 1][n + 1];
        int[][] g = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.charAt(i) == t.charAt(j)) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s.charAt(i) == t.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int f[m + 1][n + 1];
        int g[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubstrings(s string, t string) (ans int) {
	m, n := len(s), len(t)
	f := make([][]int, m+1)
	g := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
		g[i] = make([]int, n+1)
	}
	for i, a := range s {
		for j, b := range t {
			if a == b {
				f[i+1][j+1] = f[i][j] + 1
			}
		}
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if s[i] == t[j] {
				g[i][j] = g[i+1][j+1] + 1
			} else {
				ans += (f[i][j] + 1) * (g[i+1][j+1] + 1)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans = 0
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i, a in enumerate(s, 1):
            for j, b in enumerate(t, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1] + 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    g[i][j] = g[i + 1][j + 1] + 1
                else:
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countSubstrings(String s, String t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int[][] f = new int[m + 1][n + 1];
        int[][] g = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.charAt(i) == t.charAt(j)) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s.charAt(i) == t.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
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
    int countSubstrings(string s, string t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int f[m + 1][n + 1];
        int g[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}