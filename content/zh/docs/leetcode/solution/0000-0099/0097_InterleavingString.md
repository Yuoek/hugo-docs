---
title: "0097_InterleavingString"
date: 2025-10-06T00:42:37+08:00
weight: 0097
tags: [字符串, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [97. 交错字符串](https://leetcode.cn/problems/interleaving-string)

[English Version](../en/0097-97/0097_InterleavingString)

## 题目描述

<!-- description:start -->

<p>给定三个字符串&nbsp;<code>s1</code>、<code>s2</code>、<code>s3</code>，请你帮忙验证&nbsp;<code>s3</code>&nbsp;是否是由&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code><em> </em><strong>交错 </strong>组成的。</p>

<p>两个字符串 <code>s</code> 和 <code>t</code> <strong>交错</strong> 的定义与过程如下，其中每个字符串都会被分割成若干 <strong>非空</strong> <span data-keyword="substring-nonempty">子字符串</span>：</p>

<ul>
	<li><code>s = s<sub>1</sub> + s<sub>2</sub> + ... + s<sub>n</sub></code></li>
	<li><code>t = t<sub>1</sub> + t<sub>2</sub> + ... + t<sub>m</sub></code></li>
	<li><code>|n - m| &lt;= 1</code></li>
	<li><strong>交错</strong> 是 <code>s<sub>1</sub> + t<sub>1</sub> + s<sub>2</sub> + t<sub>2</sub> + s<sub>3</sub> + t<sub>3</sub> + ...</code> 或者 <code>t<sub>1</sub> + s<sub>1</sub> + t<sub>2</sub> + s<sub>2</sub> + t<sub>3</sub> + s<sub>3</sub> + ...</code></li>
</ul>

<p><strong>注意：</strong><code>a + b</code> 意味着字符串 <code>a</code> 和 <code>b</code> 连接。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0097.Interleaving%20String/images/interleave.jpg" />
<pre>
<strong>输入：</strong>s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s1 = "", s2 = "", s3 = ""
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li><code>0 &lt;= s3.length &lt;= 200</code></li>
	<li><code>s1</code>、<code>s2</code>、和 <code>s3</code> 都由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>您能否仅使用 <code>O(s2.length)</code> 额外的内存空间来解决它?</p>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们记字符串 $s_1$ 的长度为 $m$，字符串 $s_2$ 的长度为 $n$，如果 $m + n \neq |s_3|$，那么 $s_3$ 一定不是 $s_1$ 和 $s_2$ 的交错字符串，返回 `false`。

接下来，我们设计一个函数 $dfs(i, j)$，表示从 $s_1$ 的第 $i$ 个字符和 $s_2$ 的第 $j$ 个字符开始，能否交错组成 $s_3$ 的剩余部分。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算过程如下：

如果 $i \geq m$ 并且 $j \geq n$，那么说明 $s_1$ 和 $s_2$ 都已经遍历完毕，返回 `true`。

如果 $i < m$ 并且 $s_1[i] = s_3[i + j]$，那么说明 $s_1[i]$ 这个字符是 $s_3[i + j]$ 中的一部分，因此递归地调用 $dfs(i + 1, j)$ 判断 $s_1$ 的下一个字符能否和 $s_2$ 的当前字符匹配，如果能匹配成功，就返回 `true`。

同理，如果 $j < n$ 并且 $s_2[j] = s_3[i + j]$，那么说明 $s_2[j]$ 这个字符是 $s_3[i + j]$ 中的一部分，因此递归地调用 $dfs(i, j + 1)$ 判断 $s_2$ 的下一个字符能否和 $s_1$ 的当前字符匹配，如果能匹配成功，就返回 `true`。

否则，返回 `false`。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $s_1$ 和 $s_2$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转化为动态规划。

定义 $f[i][j]$ 表示字符串 $s_1$ 的前 $i$ 个字符和字符串 $s_2$ 的前 $j$ 个字符是否能交错组成字符串 $s_3$ 的前 $i + j$ 个字符。在进行状态转移时，我们可以考虑当前字符是由 $s_1$ 的最后一个字符还是 $s_2$ 的最后一个字符得到的，因此有状态转移方程：

$$
f[i][j] = \begin{cases}
f[i - 1][j] & \textit{if } s_1[i - 1] = s_3[i + j - 1] \\
\textit{or } f[i][j - 1] & \textit{if } s_2[j - 1] = s_3[i + j - 1] \\
\textit{false} & \textit{otherwise}
\end{cases}
$$

其中 $f[0][0] = \textit{true}$ 表示空串是两个空串的交错字符串。

答案即为 $f[m][n]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $s_1$ 和 $s_2$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



<!-- tabs:end -->

我们注意到，状态 $f[i][j]$ 只和状态 $f[i - 1][j]$、$f[i][j - 1]$、$f[i - 1][j - 1]$ 有关，因此我们可以使用滚动数组优化空间复杂度，将空间复杂度优化到 $O(n)$。

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
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        f = [True] + [False] * n
        for i in range(m + 1):
            for j in range(n + 1):
                k = i + j - 1
                if i:
                    f[j] &= s1[i - 1] == s3[k]
                if j:
                    f[j] |= f[j - 1] and s2[j - 1] == s3[k]
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[j] &= s1.charAt(i - 1) == s3.charAt(k);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] & s2.charAt(j - 1) == s3.charAt(k));
                }
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        bool f[n + 1];
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i) {
                    f[j] &= s1[i - 1] == s3[k];
                }
                if (j) {
                    f[j] |= (s2[j - 1] == s3[k] && f[j - 1]);
                }
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isInterleave(s1 string, s2 string, s3 string) bool {
	m, n := len(s1), len(s2)
	if m+n != len(s3) {
		return false
	}
	f := make([]bool, n+1)
	f[0] = true
	for i := 0; i <= m; i++ {
		for j := 0; j <= n; j++ {
			k := i + j - 1
			if i > 0 {
				f[j] = (f[j] && s1[i-1] == s3[k])
			}
			if j > 0 {
				f[j] = (f[j] || (s2[j-1] == s3[k] && f[j-1]))
			}
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isInterleave(s1: string, s2: string, s3: string): boolean {
    const m = s1.length;
    const n = s2.length;
    if (m + n !== s3.length) {
        return false;
    }
    const f: boolean[] = new Array(n + 1).fill(false);
    f[0] = true;
    for (let i = 0; i <= m; ++i) {
        for (let j = 0; j <= n; ++j) {
            const k = i + j - 1;
            if (i) {
                f[j] = f[j] && s1[i - 1] === s3[k];
            }
            if (j) {
                f[j] = f[j] || (f[j - 1] && s2[j - 1] === s3[k]);
            }
        }
    }
    return f[n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let n = s1.len();
        let m = s2.len();

        if s1.len() + s2.len() != s3.len() {
            return false;
        }

        let mut record = vec![vec![-1; m + 1]; n + 1];

        Self::dfs(
            &mut record,
            n,
            m,
            0,
            0,
            &s1.chars().collect(),
            &s2.chars().collect(),
            &s3.chars().collect(),
        )
    }

    #[allow(dead_code)]
    fn dfs(
        record: &mut Vec<Vec<i32>>,
        n: usize,
        m: usize,
        i: usize,
        j: usize,
        s1: &Vec<char>,
        s2: &Vec<char>,
        s3: &Vec<char>,
    ) -> bool {
        if i >= n && j >= m {
            return true;
        }

        if record[i][j] != -1 {
            return record[i][j] == 1;
        }

        // Set the initial value
        record[i][j] = 0;
        let k = i + j;

        // Let's try `s1` first
        if i < n && s1[i] == s3[k] && Self::dfs(record, n, m, i + 1, j, s1, s2, s3) {
            record[i][j] = 1;
        }

        // If the first approach does not succeed, let's then try `s2`
        if record[i][j] == 0
            && j < m
            && s2[j] == s3[k]
            && Self::dfs(record, n, m, i, j + 1, s1, s2, s3)
        {
            record[i][j] = 1;
        }

        record[i][j] == 1
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        int m = s1.Length, n = s2.Length;
        if (m + n != s3.Length) {
            return false;
        }
        bool[] f = new bool[n + 1];
        f[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[j] &= s1[i - 1] == s3[k];
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] & s2[j - 1] == s3[k]);
                }
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        f = [True] + [False] * n
        for i in range(m + 1):
            for j in range(n + 1):
                k = i + j - 1
                if i:
                    f[j] &= s1[i - 1] == s3[k]
                if j:
                    f[j] |= f[j - 1] and s2[j - 1] == s3[k]
        return f[n]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[j] &= s1.charAt(i - 1) == s3.charAt(k);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] & s2.charAt(j - 1) == s3.charAt(k));
                }
            }
        }
        return f[n];
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
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        bool f[n + 1];
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i) {
                    f[j] &= s1[i - 1] == s3[k];
                }
                if (j) {
                    f[j] |= (s2[j - 1] == s3[k] && f[j - 1]);
                }
            }
        }
        return f[n];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}