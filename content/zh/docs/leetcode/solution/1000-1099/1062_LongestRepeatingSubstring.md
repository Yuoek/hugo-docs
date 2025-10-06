---
title: "1062_LongestRepeatingSubstring"
date: 2025-10-06T00:42:37+08:00
weight: 1062
tags: [字符串, 二分查找, 动态规划, 后缀数组, 哈希函数, 滚动哈希]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1062. 最长重复子串的长度 🔒](https://leetcode.cn/problems/longest-repeating-substring)

[English Version](../en/1062-62/1062_LongestRepeatingSubstring)

## 题目描述

<!-- description:start -->

<p>给定字符串&nbsp;<code>s</code>，找出最长重复子串的长度。如果不存在重复子串就返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>"abcd"
<strong>输出：</strong>0
<strong>解释：</strong>没有重复子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>"abbaba"
<strong>输出：</strong>2
<strong>解释：</strong>最长的重复子串为 "ab" 和 "ba"，每个出现 2 次。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>"aabcaabdaab"
<strong>输出：</strong>3
<strong>解释：</strong>最长的重复子串为 "aab"，出现 3 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li>字符串&nbsp;<code>s</code>&nbsp;仅包含从&nbsp;<code>'a'</code> 到&nbsp;<code>'z'</code>&nbsp;的小写英文字母。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示以 $s[i]$ 和 $s[j]$ 结尾的最长重复子串的长度，初始时 $f[i][j]=0$。

我们在 $[1, n)$ 的区间内枚举 $i$，在 $[0, i)$ 的区间内枚举 $j$，如果 $s[i]=s[j]$，那么有：

$$
f[i][j]=
\begin{cases}
f[i-1][j-1]+1, & j>0 \\
1, & j=0
\end{cases}
$$

我们求出所有 $f[i][j]$ 的最大值即为答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

相似题目：

-   [1044. 最长重复子串 🔒](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1044.Longest%20Duplicate%20Substring/README.md)

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for j in range(i):
                if s[i] == s[j]:
                    f[i][j] = 1 + (f[i - 1][j - 1] if j else 0)
                    ans = max(ans, f[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestRepeatingSubstring(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = Math.max(ans, f[i][j]);
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
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = max(ans, f[i][j]);
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
func longestRepeatingSubstring(s string) (ans int) {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if s[i] == s[j] {
				if j > 0 {
					f[i][j] = f[i-1][j-1]
				}
				f[i][j]++
				ans = max(ans, f[i][j])
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestRepeatingSubstring(s: string): number {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }).map(() => Array(n).fill(0));
    let ans = 0;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = 1 + (f[i - 1][j - 1] || 0);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_repeating_substring(s: String) -> i32 {
        let n = s.len();
        let mut f = vec![vec![0; n]; n];
        let mut ans = 0;
        let s = s.as_bytes();

        for i in 1..n {
            for j in 0..i {
                if s[i] == s[j] {
                    f[i][j] = if j > 0 { f[i - 1][j - 1] + 1 } else { 1 };
                    ans = ans.max(f[i][j]);
                }
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for j in range(i):
                if s[i] == s[j]:
                    f[i][j] = 1 + (f[i - 1][j - 1] if j else 0)
                    ans = max(ans, f[i][j])
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestRepeatingSubstring(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = Math.max(ans, f[i][j]);
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
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}