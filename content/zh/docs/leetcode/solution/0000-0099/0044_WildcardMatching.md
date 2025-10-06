---
title: "0044_WildcardMatching"
date: 2025-10-06T00:42:37+08:00
weight: 0044
tags: [贪心, 递归, 字符串, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [44. 通配符匹配](https://leetcode.cn/problems/wildcard-matching)

[English Version](../en/0044-44/0044_WildcardMatching)

## 题目描述

<!-- description:start -->

<div class="title__3Vvk">给你一个输入字符串 (<code>s</code>) 和一个字符模式 (<code>p</code>) ，请你实现一个支持 <code>'?'</code> 和 <code>'*'</code> 匹配规则的通配符匹配：</div>

<ul>
	<li class="title__3Vvk"><code>'?'</code> 可以匹配任何单个字符。</li>
	<li class="title__3Vvk"><code>'*'</code> 可以匹配任意字符序列（包括空字符序列）。</li>
</ul>

<div class="original__bRMd">
<div>
<p>判定匹配成功的充要条件是：字符模式必须能够 <strong>完全匹配</strong> 输入字符串（而不是部分匹配）。</p>
</div>
</div>
&nbsp;

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aa", p = "a"
<strong>输出：</strong>false
<strong>解释：</strong>"a" 无法匹配 "aa" 整个字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aa", p = "*"
<strong>输出：</strong>true
<strong>解释：</strong>'*' 可以匹配任意字符串。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "cb", p = "?a"
<strong>输出：</strong>false
<strong>解释：</strong>'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length, p.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>p</code> 仅由小写英文字母、<code>'?'</code> 或 <code>'*'</code> 组成</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从字符串 $s$ 的第 $i$ 个字符开始和字符串 $p$ 的第 $j$ 个字符开始是否匹配。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的执行过程如下：

-   如果 $i \geq \textit{len}(s)$，那么只有当 $j \geq \textit{len}(p)$ 或者 $p[j] = '*'$ 且 $dfs(i, j + 1)$ 为真时，$dfs(i, j)$ 才为真。
-   如果 $j \geq \textit{len}(p)$，那么 $dfs(i, j)$ 为假。
-   如果 $p[j] = '*'$，那么 $dfs(i, j)$ 为真当且仅当 $dfs(i + 1, j)$ 或 $dfs(i + 1, j + 1)$ 或 $dfs(i, j + 1)$ 中有一个为真。
-   否则 $dfs(i, j)$ 为真当且仅当 $p[j] = '?'$ 或 $s[i] = p[j]$ 且 $dfs(i + 1, j + 1)$ 为真。

为了避免重复计算，我们使用记忆化搜索的方法，将 $dfs(i, j)$ 的结果存储在一个哈希表中。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $p$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划。

定义 $f[i][j]$ 表示字符串 $s$ 的前 $i$ 个字符和字符串 $p$ 的前 $j$ 个字符是否匹配。初始时 $f[0][0] = \textit{true}$，表示两个空字符串是匹配的。对于 $j \in [1, n]$，如果 $p[j-1] = '*'$，那么 $f[0][j] = f[0][j-1]$。

接下来我们考虑 $i \in [1, m]$ 和 $j \in [1, n]$ 的情况：

-   如果 $p[j-1] = '*'$，那么 $f[i][j] = f[i-1][j] \lor f[i][j-1] \lor f[i-1][j-1]$。
-   否则 $f[i][j] = (p[j-1] = '?' \lor s[i-1] = p[j-1]) \land f[i-1][j-1]$。

最终答案为 $f[m][n]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $p$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### PHP



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for j in range(1, n + 1):
            if p[j - 1] == "*":
                f[0][j] = f[0][j - 1]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == "*":
                    f[i][j] = f[i - 1][j] or f[i][j - 1] or f[i - 1][j - 1]
                else:
                    f[i][j] = f[i - 1][j - 1] and (
                        p[j - 1] == "?" or s[i - 1] == p[j - 1]
                    )
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] f = new boolean[m + 1][n + 1];
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p.charAt(j - 1) == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p.charAt(j - 1) == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1]
                        && (p.charAt(j - 1) == '?' || s.charAt(i - 1) == p.charAt(j - 1));
                }
            }
        }
        return f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool f[m + 1][n + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isMatch(s string, p string) bool {
	m, n := len(s), len(p)
	f := make([][]bool, m+1)
	for i := range f {
		f[i] = make([]bool, n+1)
	}
	f[0][0] = true
	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			f[0][j] = f[0][j-1]
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				f[i][j] = f[i-1][j] || f[i][j-1] || f[i-1][j-1]
			} else {
				f[i][j] = f[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1])
			}
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isMatch(s: string, p: string): boolean {
    const m: number = s.length;
    const n: number = p.length;
    const f: boolean[][] = Array.from({ length: m + 1 }, () =>
        Array.from({ length: n + 1 }, () => false),
    );
    f[0][0] = true;
    for (let j = 1; j <= n; ++j) {
        if (p.charAt(j - 1) === '*') {
            f[0][j] = f[0][j - 1];
        }
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (p[j - 1] === '*') {
                f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
            } else {
                f[i][j] = f[i - 1][j - 1] && (p[j - 1] === '?' || s[i - 1] === p[j - 1]);
            }
        }
    }
    return f[m][n];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private bool?[,] f;
    private char[] s;
    private char[] p;
    private int m;
    private int n;

    public bool IsMatch(string s, string p) {
        this.s = s.ToCharArray();
        this.p = p.ToCharArray();
        m = s.Length;
        n = p.Length;
        f = new bool?[m, n];
        return Dfs(0, 0);
    }

    private bool Dfs(int i, int j) {
        if (i >= m) {
            return j >= n || (p[j] == '*' && Dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i, j] != null) {
            return f[i, j].Value;
        }
        if (p[j] == '*') {
            f[i, j] = Dfs(i + 1, j) || Dfs(i + 1, j + 1) || Dfs(i, j + 1);
        } else {
            f[i, j] = (p[j] == '?' || s[i] == p[j]) && Dfs(i + 1, j + 1);
        }
        return f[i, j].Value;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $s
     * @param string $p
     * @return boolean
     */

    function isMatch($s, $p) {
        $lengthS = strlen($s);
        $lengthP = strlen($p);
        $dp = [];
        for ($i = 0; $i <= $lengthS; $i++) {
            $dp[$i] = array_fill(0, $lengthP + 1, false);
        }
        $dp[0][0] = true;

        for ($i = 1; $i <= $lengthP; $i++) {
            if ($p[$i - 1] == '*') {
                $dp[0][$i] = $dp[0][$i - 1];
            }
        }
        for ($i = 1; $i <= $lengthS; $i++) {
            for ($j = 1; $j <= $lengthP; $j++) {
                if ($p[$j - 1] == '?' || $s[$i - 1] == $p[$j - 1]) {
                    $dp[$i][$j] = $dp[$i - 1][$j - 1];
                } elseif ($p[$j - 1] == '*') {
                    $dp[$i][$j] = $dp[$i][$j - 1] || $dp[$i - 1][$j];
                }
            }
        }
        return $dp[$lengthS][$lengthP];
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for j in range(1, n + 1):
            if p[j - 1] == "*":
                f[0][j] = f[0][j - 1]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == "*":
                    f[i][j] = f[i - 1][j] or f[i][j - 1] or f[i - 1][j - 1]
                else:
                    f[i][j] = f[i - 1][j - 1] and (
                        p[j - 1] == "?" or s[i - 1] == p[j - 1]
                    )
        return f[m][n]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] f = new boolean[m + 1][n + 1];
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p.charAt(j - 1) == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p.charAt(j - 1) == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1]
                        && (p.charAt(j - 1) == '?' || s.charAt(i - 1) == p.charAt(j - 1));
                }
            }
        }
        return f[m][n];
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
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool f[m + 1][n + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}