---
title: "0920_播放列表的数量"
date: 2025-10-08T18:36:43+08:00
weight: 3
tags: [动态规划, 双指针, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 栈, 深度优先搜索, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [0920_播放列表的数量](#920)
#### [数学](#920)
#### [动态规划](#920)
#### [组合数学](#920)
### [0921_使括号有效的最少添加](#921)
#### [栈](#921)
#### [贪心](#921)
#### [字符串](#921)
### [0922_按奇偶排序数组 II](#922)
#### [数组](#922)
#### [双指针](#922)
#### [排序](#922)
### [0923_多重三数之和](#923)
#### [数组](#923)
#### [哈希表](#923)
#### [双指针](#923)
#### [计数](#923)
#### [排序](#923)
### [0924_尽量减少恶意软件的传播](#924)
#### [深度优先搜索](#924)
#### [广度优先搜索](#924)
#### [并查集](#924)
#### [图](#924)
#### [数组](#924)
#### [哈希表](#924)
### [0925_长按键入](#925)
#### [双指针](#925)
#### [字符串](#925)
### [0926_将字符串翻转到单调递增](#926)
#### [字符串](#926)
#### [动态规划](#926)
### [0927_三等分](#927)
#### [数组](#927)
#### [数学](#927)
### [0928_尽量减少恶意软件的传播 II](#928)
#### [深度优先搜索](#928)
#### [广度优先搜索](#928)
#### [并查集](#928)
#### [图](#928)
#### [数组](#928)
#### [哈希表](#928)
### [0929_独特的电子邮件地址](#929)
#### [数组](#929)
#### [哈希表](#929)
#### [字符串](#929)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0920_播放列表的数量
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 0921_使括号有效的最少添加
___
#### 栈
___
#### 贪心
___
#### 字符串
---
### 0922_按奇偶排序数组 II
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0923_多重三数之和
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 计数
___
#### 排序
---
### 0924_尽量减少恶意软件的传播
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 哈希表
---
### 0925_长按键入
___
#### 双指针
___
#### 字符串
---
### 0926_将字符串翻转到单调递增
___
#### 字符串
___
#### 动态规划
---
### 0927_三等分
___
#### 数组
___
#### 数学
---
### 0928_尽量减少恶意软件的传播 II
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 哈希表
---
### 0929_独特的电子邮件地址
___
#### 数组
___
#### 哈希表
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 栈 | 深度优先搜索 |
| 组合数学 | 计数 | 贪心 |

# [920. 播放列表的数量](https://leetcode.cn/problems/number-of-music-playlists){#920}

{{< tabs "920" >}}

{{% tab "python" %}}
```python
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        mod = 10**9 + 7
        f = [0] * (goal + 1)
        f[0] = 1
        for i in range(1, goal + 1):
            g = [0] * (goal + 1)
            for j in range(1, n + 1):
                g[j] = f[j - 1] * (n - j + 1)
                if j > k:
                    g[j] += f[j] * (j - k)
                g[j] %= mod
            f = g
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numMusicPlaylists(int n, int goal, int k) {
        final int mod = (int) 1e9 + 7;
        long[] f = new long[n + 1];
        f[0] = 1;
        for (int i = 1; i <= goal; ++i) {
            long[] g = new long[n + 1];
            for (int j = 1; j <= n; ++j) {
                g[j] = f[j - 1] * (n - j + 1);
                if (j > k) {
                    g[j] += f[j] * (j - k);
                }
                g[j] %= mod;
            }
            f = g;
        }
        return (int) f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int mod = 1e9 + 7;
        vector<long long> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= goal; ++i) {
            vector<long long> g(n + 1);
            for (int j = 1; j <= n; ++j) {
                g[j] = f[j - 1] * (n - j + 1);
                if (j > k) {
                    g[j] += f[j] * (j - k);
                }
                g[j] %= mod;
            }
            f = move(g);
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numMusicPlaylists(n int, goal int, k int) int {
	const mod = 1e9 + 7
	f := make([]int, goal+1)
	f[0] = 1
	for i := 1; i <= goal; i++ {
		g := make([]int, goal+1)
		for j := 1; j <= n; j++ {
			g[j] = f[j-1] * (n - j + 1)
			if j > k {
				g[j] += f[j] * (j - k)
			}
			g[j] %= mod
		}
		f = g
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numMusicPlaylists(n: number, goal: number, k: number): number {
    const mod = 1e9 + 7;
    let f = new Array(goal + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= goal; ++i) {
        const g = new Array(goal + 1).fill(0);
        for (let j = 1; j <= n; ++j) {
            g[j] = f[j - 1] * (n - j + 1);
            if (j > k) {
                g[j] += f[j] * (j - k);
            }
            g[j] %= mod;
        }
        f = g;
    }
    return f[n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn num_music_playlists(n: i32, goal: i32, k: i32) -> i32 {
        let mut dp: Vec<Vec<i64>> = vec![vec![0; n as usize + 1]; goal as usize + 1];

        // Initialize the dp vector
        dp[0][0] = 1;

        // Begin the dp process
        for i in 1..=goal as usize {
            for j in 1..=n as usize {
                // Choose the song that has not been chosen before
                // We have n - (j - 1) songs to choose
                dp[i][j] += dp[i - 1][j - 1] * ((n - ((j as i32) - 1)) as i64);

                // Choose the song that has been chosen before
                // We have j - k songs to choose if j > k
                if (j as i32) > k {
                    dp[i][j] += dp[i - 1][j] * (((j as i32) - k) as i64);
                }

                // Update dp[i][j]
                dp[i][j] %= ((1e9 as i32) + 7) as i64;
            }
        }

        dp[goal as usize][n as usize] as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你的音乐播放器里有 <code>n</code> 首不同的歌，在旅途中，你计划听 <code>goal</code> 首歌（不一定不同，即，允许歌曲重复）。你将会按如下规则创建播放列表：</p>

<ul>
	<li>每首歌 <strong>至少播放一次</strong> 。</li>
	<li>一首歌只有在其他 <code>k</code> 首歌播放完之后才能再次播放。</li>
</ul>

<p>给你 <code>n</code>、<code>goal</code> 和 <code>k</code> ，返回可以满足要求的播放列表的数量。由于答案可能非常大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, goal = 3, k = 1
<strong>输出：</strong>6
<strong>解释：</strong>有 6 种可能的播放列表。[1, 2, 3]，[1, 3, 2]，[2, 1, 3]，[2, 3, 1]，[3, 1, 2]，[3, 2, 1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, goal = 3, k = 0
<strong>输出：</strong>6
<strong>解释：</strong>有 6 种可能的播放列表。[1, 1, 2]，[1, 2, 1]，[2, 1, 1]，[2, 2, 1]，[2, 1, 2]，[1, 2, 2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, goal = 3, k = 1
<strong>输出：</strong>2
<strong>解释：</strong>有 2 种可能的播放列表。[1, 2, 1]，[2, 1, 2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= k &lt; n &lt;= goal &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示听 $i$ 首歌，且这 $i$ 首歌中有 $j$ 首不同歌曲的播放列表的数量。初始时 $f[0][0]=1$。答案为 $f[goal][n]$。

对于 $f[i][j]$，我们可以选择没听过的歌，那么上一个状态为 $f[i - 1][j - 1]$，这样的选择有 $n - (j - 1) = n - j + 1$ 种，因此 $f[i][j] += f[i - 1][j - 1] \times (n - j + 1)$。我们也可以选择听过的歌，那么上一个状态为 $f[i - 1][j]$，这样的选择有 $j - k$ 种，因此 $f[i][j] += f[i - 1][j] \times (j - k)$，其中 $j \geq k$。

综上，我们可以得到状态转移方程：

$$
f[i][j] = \begin{cases}
1 & i = 0, j = 0 \\
f[i - 1][j - 1] \times (n - j + 1) + f[i - 1][j] \times (j - k) & i \geq 1, j \geq 1
\end{cases}
$$

最终的答案为 $f[goal][n]$。

时间复杂度 $O(goal \times n)$，空间复杂度 $O(goal \times n)$。其中 $goal$ 和 $n$ 为题目中给定的参数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (n + 1) for _ in range(goal + 1)]
        f[0][0] = 1
        for i in range(1, goal + 1):
            for j in range(1, n + 1):
                f[i][j] = f[i - 1][j - 1] * (n - j + 1)
                if j > k:
                    f[i][j] += f[i - 1][j] * (j - k)
                f[i][j] %= mod
        return f[goal][n]
```

#### Java

```java
class Solution {
    public int numMusicPlaylists(int n, int goal, int k) {
        final int mod = (int) 1e9 + 7;
        long[][] f = new long[goal + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i - 1][j - 1] * (n - j + 1);
                if (j > k) {
                    f[i][j] += f[i - 1][j] * (j - k);
                }
                f[i][j] %= mod;
            }
        }
        return (int) f[goal][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int mod = 1e9 + 7;
        long long f[goal + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i - 1][j - 1] * (n - j + 1);
                if (j > k) {
                    f[i][j] += f[i - 1][j] * (j - k);
                }
                f[i][j] %= mod;
            }
        }
        return f[goal][n];
    }
};
```

#### Go

```go
func numMusicPlaylists(n int, goal int, k int) int {
	const mod = 1e9 + 7
	f := make([][]int, goal+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= goal; i++ {
		for j := 1; j <= n; j++ {
			f[i][j] = f[i-1][j-1] * (n - j + 1)
			if j > k {
				f[i][j] += f[i-1][j] * (j - k)
			}
			f[i][j] %= mod
		}
	}
	return f[goal][n]
}
```

#### TypeScript

```ts
function numMusicPlaylists(n: number, goal: number, k: number): number {
    const mod = 1e9 + 7;
    const f = new Array(goal + 1).fill(0).map(() => new Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= goal; ++i) {
        for (let j = 1; j <= n; ++j) {
            f[i][j] = f[i - 1][j - 1] * (n - j + 1);
            if (j > k) {
                f[i][j] += f[i - 1][j] * (j - k);
            }
            f[i][j] %= mod;
        }
    }
    return f[goal][n];
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn num_music_playlists(n: i32, goal: i32, k: i32) -> i32 {
        let mut dp: Vec<Vec<i64>> = vec![vec![0; n as usize + 1]; goal as usize + 1];

        // Initialize the dp vector
        dp[0][0] = 1;

        // Begin the dp process
        for i in 1..=goal as usize {
            for j in 1..=n as usize {
                // Choose the song that has not been chosen before
                // We have n - (j - 1) songs to choose
                dp[i][j] += dp[i - 1][j - 1] * ((n - ((j as i32) - 1)) as i64);

                // Choose the song that has been chosen before
                // We have j - k songs to choose if j > k
                if (j as i32) > k {
                    dp[i][j] += dp[i - 1][j] * (((j as i32) - k) as i64);
                }

                // Update dp[i][j]
                dp[i][j] %= ((1e9 as i32) + 7) as i64;
            }
        }

        dp[goal as usize][n as usize] as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们注意到 $f[i][j]$ 只与 $f[i - 1][j - 1]$ 和 $f[i - 1][j]$ 有关，因此我们可以使用滚动数组优化空间复杂度，将空间复杂度优化至 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        mod = 10**9 + 7
        f = [0] * (goal + 1)
        f[0] = 1
        for i in range(1, goal + 1):
            g = [0] * (goal + 1)
            for j in range(1, n + 1):
                g[j] = f[j - 1] * (n - j + 1)
                if j > k:
                    g[j] += f[j] * (j - k)
                g[j] %= mod
            f = g
        return f[n]
```

#### Java

```java
class Solution {
    public int numMusicPlaylists(int n, int goal, int k) {
        final int mod = (int) 1e9 + 7;
        long[] f = new long[n + 1];
        f[0] = 1;
        for (int i = 1; i <= goal; ++i) {
            long[] g = new long[n + 1];
            for (int j = 1; j <= n; ++j) {
                g[j] = f[j - 1] * (n - j + 1);
                if (j > k) {
                    g[j] += f[j] * (j - k);
                }
                g[j] %= mod;
            }
            f = g;
        }
        return (int) f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int mod = 1e9 + 7;
        vector<long long> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= goal; ++i) {
            vector<long long> g(n + 1);
            for (int j = 1; j <= n; ++j) {
                g[j] = f[j - 1] * (n - j + 1);
                if (j > k) {
                    g[j] += f[j] * (j - k);
                }
                g[j] %= mod;
            }
            f = move(g);
        }
        return f[n];
    }
};
```

#### Go

```go
func numMusicPlaylists(n int, goal int, k int) int {
	const mod = 1e9 + 7
	f := make([]int, goal+1)
	f[0] = 1
	for i := 1; i <= goal; i++ {
		g := make([]int, goal+1)
		for j := 1; j <= n; j++ {
			g[j] = f[j-1] * (n - j + 1)
			if j > k {
				g[j] += f[j] * (j - k)
			}
			g[j] %= mod
		}
		f = g
	}
	return f[n]
}
```

#### TypeScript

```ts
function numMusicPlaylists(n: number, goal: number, k: number): number {
    const mod = 1e9 + 7;
    let f = new Array(goal + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= goal; ++i) {
        const g = new Array(goal + 1).fill(0);
        for (let j = 1; j <= n; ++j) {
            g[j] = f[j - 1] * (n - j + 1);
            if (j > k) {
                g[j] += f[j] * (j - k);
            }
            g[j] %= mod;
        }
        f = g;
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [921. 使括号有效的最少添加](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid){#921}

{{< tabs "921" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            elif cnt:
                cnt -= 1
            else:
                ans += 1
        ans += cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minAddToMakeValid(String s) {
        int ans = 0, cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                ++cnt;
            } else if (cnt > 0) {
                --cnt;
            } else {
                ++ans;
            }
        }
        ans += cnt;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, cnt = 0;
        for (char c : s) {
            if (c == '(')
                ++cnt;
            else if (cnt)
                --cnt;
            else
                ++ans;
        }
        ans += cnt;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAddToMakeValid(s string) int {
	ans, cnt := 0, 0
	for _, c := range s {
		if c == '(' {
			cnt++
		} else if cnt > 0 {
			cnt--
		} else {
			ans++
		}
	}
	ans += cnt
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minAddToMakeValid(s: string): number {
    const l = s.length;
    s = s.replace('()', '');

    return s.length === l ? l : minAddToMakeValid(s);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var minAddToMakeValid = function (s) {
    const l = s.length;
    s = s.replace('()', '');
    return s.length === l ? l : minAddToMakeValid(s);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>只有满足下面几点之一，括号字符串才是有效的：</p>

<ul>
	<li>它是一个空字符串，或者</li>
	<li>它可以被写成&nbsp;<code>AB</code>&nbsp;（<code>A</code>&nbsp;与&nbsp;<code>B</code>&nbsp;连接）, 其中&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是有效字符串，或者</li>
	<li>它可以被写作&nbsp;<code>(A)</code>，其中&nbsp;<code>A</code>&nbsp;是有效字符串。</li>
</ul>

<p>给定一个括号字符串 <code>s</code> ，在每一次操作中，你都可以在字符串的任何位置插入一个括号</p>

<ul>
	<li>例如，如果 <code>s = "()))"</code> ，你可以插入一个开始括号为 <code>"(()))"</code> 或结束括号为 <code>"())))"</code> 。</li>
</ul>

<p>返回 <em>为使结果字符串 <code>s</code> 有效而必须添加的最少括号数</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "())"
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "((("
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 只包含&nbsp;<code>'('</code> 和&nbsp;<code>')'</code>&nbsp;字符。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 栈

这个问题属于经典的括号匹配问题，可以使用“贪心 + 栈”来解决。

遍历字符串 $s$ 的每个字符 $c$：

-   若 $c$ 为左括号，直接将 $c$ 入栈；
-   若 $c$ 为右括号，此时如果栈不为空，且栈顶元素为左括号，则将栈顶元素出栈，表示匹配成功；否则将 $c$ 入栈。

遍历结束后，栈中剩余的元素个数即为需要添加的括号数。

时间复杂度为 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stk = []
        for c in s:
            if c == ')' and stk and stk[-1] == '(':
                stk.pop()
            else:
                stk.append(c)
        return len(stk)
```

#### Java

```java
class Solution {
    public int minAddToMakeValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == ')' && !stk.isEmpty() && stk.peek() == '(') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        string stk;
        for (char c : s) {
            if (c == ')' && stk.size() && stk.back() == '(')
                stk.pop_back();
            else
                stk.push_back(c);
        }
        return stk.size();
    }
};
```

#### Go

```go
func minAddToMakeValid(s string) int {
	stk := []rune{}
	for _, c := range s {
		if c == ')' && len(stk) > 0 && stk[len(stk)-1] == '(' {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, c)
		}
	}
	return len(stk)
}
```

#### TypeScript

```ts
function minAddToMakeValid(s: string): number {
    const stk: string[] = [];
    for (const c of s) {
        if (c === ')' && stk.length > 0 && stk.at(-1)! === '(') {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 计数

方法一借助了栈来实现括号匹配，也可以直接通过计数来实现。

定义变量 `cnt` 表示当前待匹配的左括号个数，变量 `ans` 记录答案。初始时两个变量的值均为 $0$。

同样遍历字符串 $s$ 的每个字符 $c$：

-   若 $c$ 为左括号，将 `cnt` 的值增加 $1$；
-   若 $c$ 为右括号，此时如果 $cnt \gt 0$，说明当前有左括号可以匹配，将 `cnt` 的值减 $1$；否则说明当前右括号无法匹配，将 `ans` 的值增加 $1$。

遍历结束后，将 `cnt` 的值加到 `ans` 中，即为答案。

时间复杂度为 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            elif cnt:
                cnt -= 1
            else:
                ans += 1
        ans += cnt
        return ans
```

#### Java

```java
class Solution {
    public int minAddToMakeValid(String s) {
        int ans = 0, cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                ++cnt;
            } else if (cnt > 0) {
                --cnt;
            } else {
                ++ans;
            }
        }
        ans += cnt;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, cnt = 0;
        for (char c : s) {
            if (c == '(')
                ++cnt;
            else if (cnt)
                --cnt;
            else
                ++ans;
        }
        ans += cnt;
        return ans;
    }
};
```

#### Go

```go
func minAddToMakeValid(s string) int {
	ans, cnt := 0, 0
	for _, c := range s {
		if c == '(' {
			cnt++
		} else if cnt > 0 {
			cnt--
		} else {
			ans++
		}
	}
	ans += cnt
	return ans
}
```

#### TypeScript

```ts
function minAddToMakeValid(s: string): number {
    let [ans, cnt] = [0, 0];
    for (const c of s) {
        if (c === '(') {
            ++cnt;
        } else if (cnt) {
            --cnt;
        } else {
            ++ans;
        }
    }
    ans += cnt;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：替换 + 递归

<!-- tabs:start -->

#### TypeScript

```ts
function minAddToMakeValid(s: string): number {
    const l = s.length;
    s = s.replace('()', '');

    return s.length === l ? l : minAddToMakeValid(s);
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minAddToMakeValid = function (s) {
    const l = s.length;
    s = s.replace('()', '');
    return s.length === l ? l : minAddToMakeValid(s);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [922. 按奇偶排序数组 II](https://leetcode.cn/problems/sort-array-by-parity-ii){#922}

{{< tabs "922" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        n, j = len(nums), 1
        for i in range(0, n, 2):
            if nums[i] % 2:
                while nums[j] % 2:
                    j += 2
                nums[i], nums[j] = nums[j], nums[i]
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        for (int i = 0, j = 1; i < nums.length; i += 2) {
            if (nums[i] % 2 == 1) {
                while (nums[j] % 2 == 1) {
                    j += 2;
                }
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size(); i += 2) {
            if (nums[i] % 2) {
                while (nums[j] % 2) {
                    j += 2;
                }
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortArrayByParityII(nums []int) []int {
	for i, j := 0, 1; i < len(nums); i += 2 {
		if nums[i]%2 == 1 {
			for nums[j]%2 == 1 {
				j += 2
			}
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortArrayByParityII(nums: number[]): number[] {
    for (let i = 0, j = 1; i < nums.length; i += 2) {
        if (nums[i] % 2) {
            while (nums[j] % 2) {
                j += 2;
            }
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    return nums;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_array_by_parity_ii(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut j = 1;
        for i in (0..n).step_by(2) {
            if nums[i] % 2 != 0 {
                while nums[j] % 2 != 0 {
                    j += 2;
                }
                nums.swap(i, j);
            }
        }
        nums
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParityII = function (nums) {
    for (let i = 0, j = 1; i < nums.length; i += 2) {
        if (nums[i] % 2) {
            while (nums[j] % 2) {
                j += 2;
            }
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    return nums;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个非负整数数组&nbsp;<code>nums</code>，&nbsp;&nbsp;<code>nums</code> 中一半整数是 <strong>奇数</strong> ，一半整数是 <strong>偶数</strong> 。</p>

<p>对数组进行排序，以便当&nbsp;<code>nums[i]</code> 为奇数时，<code>i</code>&nbsp;也是 <strong>奇数</strong> ；当&nbsp;<code>nums[i]</code>&nbsp;为偶数时， <code>i</code> 也是 <strong>偶数</strong> 。</p>

<p>你可以返回 <em>任何满足上述条件的数组作为答案</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,5,7]
<strong>输出：</strong>[4,5,2,7]
<strong>解释：</strong>[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,3]
<b>输出：</b>[2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>nums.length</code>&nbsp;是偶数</li>
	<li><code>nums</code>&nbsp;中一半是偶数</li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>可以不使用额外空间解决问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$ 分别指向偶数下标和奇数下标，初始时 $i = 0$, $j = 1$。

当 $i$ 指向偶数下标时，如果 $\textit{nums}[i]$ 是奇数，那么我们需要找到一个奇数下标 $j$，使得 $\textit{nums}[j]$ 是偶数，然后交换 $\textit{nums}[i]$ 和 $\textit{nums}[j]$。继续遍历，直到 $i$ 指向数组末尾。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}[i]$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        n, j = len(nums), 1
        for i in range(0, n, 2):
            if nums[i] % 2:
                while nums[j] % 2:
                    j += 2
                nums[i], nums[j] = nums[j], nums[i]
        return nums
```

#### Java

```java
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        for (int i = 0, j = 1; i < nums.length; i += 2) {
            if (nums[i] % 2 == 1) {
                while (nums[j] % 2 == 1) {
                    j += 2;
                }
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size(); i += 2) {
            if (nums[i] % 2) {
                while (nums[j] % 2) {
                    j += 2;
                }
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
```

#### Go

```go
func sortArrayByParityII(nums []int) []int {
	for i, j := 0, 1; i < len(nums); i += 2 {
		if nums[i]%2 == 1 {
			for nums[j]%2 == 1 {
				j += 2
			}
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return nums
}
```

#### TypeScript

```ts
function sortArrayByParityII(nums: number[]): number[] {
    for (let i = 0, j = 1; i < nums.length; i += 2) {
        if (nums[i] % 2) {
            while (nums[j] % 2) {
                j += 2;
            }
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    return nums;
}
```

#### Rust

```rust
impl Solution {
    pub fn sort_array_by_parity_ii(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut j = 1;
        for i in (0..n).step_by(2) {
            if nums[i] % 2 != 0 {
                while nums[j] % 2 != 0 {
                    j += 2;
                }
                nums.swap(i, j);
            }
        }
        nums
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParityII = function (nums) {
    for (let i = 0, j = 1; i < nums.length; i += 2) {
        if (nums[i] % 2) {
            while (nums[j] % 2) {
                j += 2;
            }
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    return nums;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [923. 多重三数之和](https://leetcode.cn/problems/3sum-with-multiplicity){#923}

{{< tabs "923" >}}

{{% tab "python" %}}
```python
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        mod = 10**9 + 7
        cnt = Counter(arr)
        ans = 0
        for j, b in enumerate(arr):
            cnt[b] -= 1
            for a in arr[:j]:
                c = target - a - b
                ans = (ans + cnt[c]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int threeSumMulti(int[] arr, int target) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = new int[101];
        for (int x : arr) {
            ++cnt[x];
        }
        int n = arr.length;
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            --cnt[arr[j]];
            for (int i = 0; i < j; ++i) {
                int c = target - arr[i] - arr[j];
                if (c >= 0 && c < cnt.length) {
                    ans = (ans + cnt[c]) % mod;
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
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        int cnt[101]{};
        for (int x : arr) {
            ++cnt[x];
        }
        int n = arr.size();
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            --cnt[arr[j]];
            for (int i = 0; i < j; ++i) {
                int c = target - arr[i] - arr[j];
                if (c >= 0 && c <= 100) {
                    ans = (ans + cnt[c]) % mod;
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
func threeSumMulti(arr []int, target int) (ans int) {
	const mod int = 1e9 + 7
	cnt := [101]int{}
	for _, x := range arr {
		cnt[x]++
	}
	for j, b := range arr {
		cnt[b]--
		for _, a := range arr[:j] {
			if c := target - a - b; c >= 0 && c < len(cnt) {
				ans = (ans + cnt[c]) % mod
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function threeSumMulti(arr: number[], target: number): number {
    const mod = 10 ** 9 + 7;
    const cnt: number[] = Array(101).fill(0);
    for (const x of arr) {
        ++cnt[x];
    }
    let ans = 0;
    const n = arr.length;
    for (let j = 0; j < n; ++j) {
        --cnt[arr[j]];
        for (let i = 0; i < j; ++i) {
            const c = target - arr[i] - arr[j];
            if (c >= 0 && c < cnt.length) {
                ans = (ans + cnt[c]) % mod;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组<meta charset="UTF-8" />&nbsp;<code>arr</code>&nbsp;，以及一个整数&nbsp;<code>target</code>&nbsp;作为目标值，返回满足 <code>i &lt; j &lt; k</code> 且<meta charset="UTF-8" />&nbsp;<code>arr[i] + arr[j] + arr[k] == target</code>&nbsp;的元组&nbsp;<code>i, j, k</code>&nbsp;的数量。</p>

<p>由于结果会非常大，请返回 <code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;的模。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,2,2,3,3,4,4,5,5], target = 8
<strong>输出：</strong>20
<strong>解释：</strong>
按值枚举(arr[i], arr[j], arr[k])：
(1, 2, 5) 出现 8 次；
(1, 3, 4) 出现 8 次；
(2, 2, 4) 出现 2 次；
(2, 3, 3) 出现 2 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,2,2,2,2], target = 5
<strong>输出：</strong>12
<strong>解释：</strong>
arr[i] = 1, arr[j] = arr[k] = 2 出现 12 次：
我们从 [1,1] 中选择一个 1，有 2 种情况，
从 [2,2,2,2] 中选出两个 2，有 6 种情况。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 3000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 100</code></li>
	<li><code>0 &lt;= target &lt;= 300</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们可以用一个哈希表或者一个长度为 $101$ 的数组 $cnt$ 统计数组 $arr$ 中每个元素的出现次数。

然后，我们枚举数组 $arr$ 中的每个元素 $arr[j]$，先将 $cnt[arr[j]]$ 减一，然后再枚举 $arr[j]$ 之前的元素 $arr[i]$，计算 $c = target - arr[i] - arr[j]$，如果 $c$ 在 $[0, 100]$ 的范围内，那么答案就加上 $cnt[c]$，最后返回答案。

注意，这里的答案可能会超过 ${10}^9 + 7$，所以在每次加法操作后都要取模。

时间复杂度 $O(n^2)$，其中 $n$ 为数组 $arr$ 的长度。空间复杂度 $O(C)$，其中 $C$ 为数组 $arr$ 中元素的最大值，本题中 $C = 100$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        mod = 10**9 + 7
        cnt = Counter(arr)
        ans = 0
        for j, b in enumerate(arr):
            cnt[b] -= 1
            for a in arr[:j]:
                c = target - a - b
                ans = (ans + cnt[c]) % mod
        return ans
```

#### Java

```java
class Solution {
    public int threeSumMulti(int[] arr, int target) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = new int[101];
        for (int x : arr) {
            ++cnt[x];
        }
        int n = arr.length;
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            --cnt[arr[j]];
            for (int i = 0; i < j; ++i) {
                int c = target - arr[i] - arr[j];
                if (c >= 0 && c < cnt.length) {
                    ans = (ans + cnt[c]) % mod;
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        int cnt[101]{};
        for (int x : arr) {
            ++cnt[x];
        }
        int n = arr.size();
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            --cnt[arr[j]];
            for (int i = 0; i < j; ++i) {
                int c = target - arr[i] - arr[j];
                if (c >= 0 && c <= 100) {
                    ans = (ans + cnt[c]) % mod;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func threeSumMulti(arr []int, target int) (ans int) {
	const mod int = 1e9 + 7
	cnt := [101]int{}
	for _, x := range arr {
		cnt[x]++
	}
	for j, b := range arr {
		cnt[b]--
		for _, a := range arr[:j] {
			if c := target - a - b; c >= 0 && c < len(cnt) {
				ans = (ans + cnt[c]) % mod
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function threeSumMulti(arr: number[], target: number): number {
    const mod = 10 ** 9 + 7;
    const cnt: number[] = Array(101).fill(0);
    for (const x of arr) {
        ++cnt[x];
    }
    let ans = 0;
    const n = arr.length;
    for (let j = 0; j < n; ++j) {
        --cnt[arr[j]];
        for (let i = 0; i < j; ++i) {
            const c = target - arr[i] - arr[j];
            if (c >= 0 && c < cnt.length) {
                ans = (ans + cnt[c]) % mod;
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread){#924}

{{< tabs "924" >}}

{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True

    def get_size(self, root: int) -> int:
        return self.size[root]


class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        n = len(graph)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i + 1, n):
                graph[i][j] and uf.union(i, j)
        cnt = Counter(uf.find(x) for x in initial)
        ans, mx = n, 0
        for x in initial:
            root = uf.find(x)
            if cnt[root] > 1:
                continue
            sz = uf.get_size(root)
            if sz > mx or (sz == mx and x < ans):
                ans = x
                mx = sz
        return min(initial) if ans == n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int root) {
        return size[root];
    }
}

class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j] == 1) {
                    uf.union(i, j);
                }
            }
        }
        int ans = n;
        int mi = n, mx = 0;
        int[] cnt = new int[n];
        for (int x : initial) {
            ++cnt[uf.find(x)];
            mi = Math.min(mi, x);
        }

        for (int x : initial) {
            int root = uf.find(x);
            if (cnt[root] == 1) {
                int sz = uf.size(root);
                if (sz > mx || (sz == mx && x < ans)) {
                    ans = x;
                    mx = sz;
                }
            }
        }
        return ans == n ? mi : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int root) {
        return size[root];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j]) {
                    uf.unite(i, j);
                }
            }
        }
        int ans = n, mx = 0;
        vector<int> cnt(n);
        for (int x : initial) {
            ++cnt[uf.find(x)];
        }
        for (int x : initial) {
            int root = uf.find(x);
            if (cnt[root] == 1) {
                int sz = uf.getSize(root);
                if (sz > mx || (sz == mx && ans > x)) {
                    ans = x;
                    mx = sz;
                }
            }
        }
        return ans == n ? *min_element(initial.begin(), initial.end()) : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(root int) int {
	return uf.size[root]
}

func minMalwareSpread(graph [][]int, initial []int) int {
	n := len(graph)
	uf := newUnionFind(n)
	for i := range graph {
		for j := i + 1; j < n; j++ {
			if graph[i][j] == 1 {
				uf.union(i, j)
			}
		}
	}
	cnt := make([]int, n)
	ans, mx := n, 0
	for _, x := range initial {
		cnt[uf.find(x)]++
	}
	for _, x := range initial {
		root := uf.find(x)
		if cnt[root] == 1 {
			sz := uf.getSize(root)
			if sz > mx || sz == mx && x < ans {
				ans, mx = x, sz
			}
		}
	}
	if ans == n {
		return slices.Min(initial)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(root: number): number {
        return this.size[root];
    }
}

function minMalwareSpread(graph: number[][], initial: number[]): number {
    const n = graph.length;
    const uf = new UnionFind(n);
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            graph[i][j] && uf.union(i, j);
        }
    }
    let [ans, mx] = [n, 0];
    const cnt: number[] = Array(n).fill(0);
    for (const x of initial) {
        ++cnt[uf.find(x)];
    }
    for (const x of initial) {
        const root = uf.find(x);
        if (cnt[root] === 1) {
            const sz = uf.getSize(root);
            if (sz > mx || (sz === mx && x < ans)) {
                [ans, mx] = [x, sz];
            }
        }
    }
    return ans === n ? Math.min(...initial) : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出了一个由 <code>n</code> 个节点组成的网络，用 <code>n × n</code> 个邻接矩阵图<meta charset="UTF-8" />&nbsp;<code>graph</code>&nbsp;表示。在节点网络中，当 <code>graph[i][j] = 1</code>&nbsp;时，表示节点&nbsp;<code>i</code>&nbsp;能够直接连接到另一个节点 <code>j</code>。&nbsp;</p>

<p>一些节点&nbsp;<code>initial</code>&nbsp;最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。</p>

<p>假设 <code>M(initial)</code> 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。</p>

<p>如果从&nbsp;<code>initial</code>&nbsp;中<strong>移除某一节点</strong>能够最小化 <code>M(initial)</code>， 返回该节点。如果有多个节点满足条件，就返回<strong>索引最小</strong>的节点。</p>

<p>请注意，如果某个节点已从受感染节点的列表 <code>initial</code> 中删除，它以后仍有可能因恶意软件传播而受到感染。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
<strong>输出：</strong>0
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
<strong>输出：</strong>0
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>n == graph[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 300</code></li>
	<li><code>graph[i][j]&nbsp;==&nbsp;0</code>&nbsp;或&nbsp;<code>1</code>.</li>
	<li><code>graph[i][j] == graph[j][i]</code></li>
	<li><code>graph[i][i] == 1</code></li>
	<li><code>1 &lt;= initial.length &lt;= n</code></li>
	<li><code>0 &lt;= initial[i] &lt;= n - 1</code></li>
	<li><code>initial</code>&nbsp;中所有整数均<strong>不重复</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

根据题目描述，如果初始时有若干个节点属于同一个连通分量，那么一共可以分为三种情况：

1. 这些节点中没有一个节点被感染
1. 这些节点中只有一个节点被感染
1. 这些节点中有多个节点被感染

我们要考虑的是，移除某个感染节点后，剩下的节点中被感染的节点数最少。

情况一没有被感染的节点，不需要考虑；情况二只有一个节点被感染，那么移除这个节点后，该连通分量中的其他节点都不会被感染；情况三有多个节点被感染，那么移除任意一个感染节点后，该连通分量中的其他节点还是会被感染，所以我们只需要考虑情况二。

我们利用并查集 $uf$ 维护节点的连通关系，用一个变量 $ans$ 记录答案，用一个变量 $mx$ 记录当前能减少感染的最大节点数，初始时 $ans = n$, $mx = 0$。

然后遍历数组 $initial$，用一个哈希表或者一个长度为 $n$ 的数组 $cnt$ 统计每个连通分量中被感染节点的个数。

接下来，我们再遍历数组 $initial$，对于每个节点 $x$，我们找到其所在的连通分量的根节点 $root$，如果该连通分量中只有一个被感染节点，即 $cnt[root] = 1$，我们就更新答案，更新的条件是该连通分量中的节点数 $sz$ 大于 $mx$ 或者 $sz$ 等于 $mx$ 且 $x$ 的值小于 $ans$。

最后，如果 $ans$ 没有被更新，说明所有的连通分量中都有多个被感染节点，那么我们返回 $initial$ 中的最小值，否则返回 $ans$。

时间复杂度 $O(n^2 \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 是节点的个数，而 $\alpha(n)$ 是 Ackermann 函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True

    def get_size(self, root: int) -> int:
        return self.size[root]


class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        n = len(graph)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i + 1, n):
                graph[i][j] and uf.union(i, j)
        cnt = Counter(uf.find(x) for x in initial)
        ans, mx = n, 0
        for x in initial:
            root = uf.find(x)
            if cnt[root] > 1:
                continue
            sz = uf.get_size(root)
            if sz > mx or (sz == mx and x < ans):
                ans = x
                mx = sz
        return min(initial) if ans == n else ans
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int root) {
        return size[root];
    }
}

class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j] == 1) {
                    uf.union(i, j);
                }
            }
        }
        int ans = n;
        int mi = n, mx = 0;
        int[] cnt = new int[n];
        for (int x : initial) {
            ++cnt[uf.find(x)];
            mi = Math.min(mi, x);
        }

        for (int x : initial) {
            int root = uf.find(x);
            if (cnt[root] == 1) {
                int sz = uf.size(root);
                if (sz > mx || (sz == mx && x < ans)) {
                    ans = x;
                    mx = sz;
                }
            }
        }
        return ans == n ? mi : ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int root) {
        return size[root];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j]) {
                    uf.unite(i, j);
                }
            }
        }
        int ans = n, mx = 0;
        vector<int> cnt(n);
        for (int x : initial) {
            ++cnt[uf.find(x)];
        }
        for (int x : initial) {
            int root = uf.find(x);
            if (cnt[root] == 1) {
                int sz = uf.getSize(root);
                if (sz > mx || (sz == mx && ans > x)) {
                    ans = x;
                    mx = sz;
                }
            }
        }
        return ans == n ? *min_element(initial.begin(), initial.end()) : ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(root int) int {
	return uf.size[root]
}

func minMalwareSpread(graph [][]int, initial []int) int {
	n := len(graph)
	uf := newUnionFind(n)
	for i := range graph {
		for j := i + 1; j < n; j++ {
			if graph[i][j] == 1 {
				uf.union(i, j)
			}
		}
	}
	cnt := make([]int, n)
	ans, mx := n, 0
	for _, x := range initial {
		cnt[uf.find(x)]++
	}
	for _, x := range initial {
		root := uf.find(x)
		if cnt[root] == 1 {
			sz := uf.getSize(root)
			if sz > mx || sz == mx && x < ans {
				ans, mx = x, sz
			}
		}
	}
	if ans == n {
		return slices.Min(initial)
	}
	return ans
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(root: number): number {
        return this.size[root];
    }
}

function minMalwareSpread(graph: number[][], initial: number[]): number {
    const n = graph.length;
    const uf = new UnionFind(n);
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            graph[i][j] && uf.union(i, j);
        }
    }
    let [ans, mx] = [n, 0];
    const cnt: number[] = Array(n).fill(0);
    for (const x of initial) {
        ++cnt[uf.find(x)];
    }
    for (const x of initial) {
        const root = uf.find(x);
        if (cnt[root] === 1) {
            const sz = uf.getSize(root);
            if (sz > mx || (sz === mx && x < ans)) {
                [ans, mx] = [x, sz];
            }
        }
    }
    return ans === n ? Math.min(...initial) : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [925. 长按键入](https://leetcode.cn/problems/long-pressed-name){#925}

{{< tabs "925" >}}

{{% tab "python" %}}
```python
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        m, n = len(name), len(typed)
        i = j = 0
        while i < m and j < n:
            if name[i] != typed[j]:
                return False
            x = i + 1
            while x < m and name[x] == name[i]:
                x += 1
            y = j + 1
            while y < n and typed[y] == typed[j]:
                y += 1
            if x - i > y - j:
                return False
            i, j = x, y
        return i == m and j == n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int m = name.length(), n = typed.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (name.charAt(i) != typed.charAt(j)) {
                return false;
            }
            int x = i + 1;
            while (x < m && name.charAt(x) == name.charAt(i)) {
                ++x;
            }
            int y = j + 1;
            while (y < n && typed.charAt(y) == typed.charAt(j)) {
                ++y;
            }
            if (x - i > y - j) {
                return false;
            }
            i = x;
            j = y;
        }
        return i == m && j == n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.length(), n = typed.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (name[i] != typed[j]) {
                return false;
            }
            int x = i + 1;
            while (x < m && name[x] == name[i]) {
                ++x;
            }
            int y = j + 1;
            while (y < n && typed[y] == typed[j]) {
                ++y;
            }
            if (x - i > y - j) {
                return false;
            }
            i = x;
            j = y;
        }
        return i == m && j == n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isLongPressedName(name string, typed string) bool {
	m, n := len(name), len(typed)
	i, j := 0, 0

	for i < m && j < n {
		if name[i] != typed[j] {
			return false
		}
		x, y := i+1, j+1

		for x < m && name[x] == name[i] {
			x++
		}

		for y < n && typed[y] == typed[j] {
			y++
		}

		if x-i > y-j {
			return false
		}

		i, j = x, y
	}

	return i == m && j == n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isLongPressedName(name: string, typed: string): boolean {
    const [m, n] = [name.length, typed.length];
    let i = 0;
    let j = 0;
    while (i < m && j < n) {
        if (name[i] !== typed[j]) {
            return false;
        }
        let x = i + 1;
        while (x < m && name[x] === name[i]) {
            x++;
        }
        let y = j + 1;
        while (y < n && typed[y] === typed[j]) {
            y++;
        }
        if (x - i > y - j) {
            return false;
        }
        i = x;
        j = y;
    }
    return i === m && j === n;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let (m, n) = (name.len(), typed.len());
        let (mut i, mut j) = (0, 0);
        let s: Vec<char> = name.chars().collect();
        let t: Vec<char> = typed.chars().collect();

        while i < m && j < n {
            if s[i] != t[j] {
                return false;
            }
            let mut x = i + 1;
            while x < m && s[x] == s[i] {
                x += 1;
            }
            let mut y = j + 1;
            while y < n && t[y] == t[j] {
                y += 1;
            }
            if x - i > y - j {
                return false;
            }
            i = x;
            j = y;
        }

        i == m && j == n
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你的朋友正在使用键盘输入他的名字&nbsp;<code>name</code>。偶尔，在键入字符&nbsp;<code>c</code>&nbsp;时，按键可能会被<em>长按</em>，而字符可能被输入 1 次或多次。</p>

<p>你将会检查键盘输入的字符&nbsp;<code>typed</code>。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回&nbsp;<code>True</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>name = "alex", typed = "aaleex"
<strong>输出：</strong>true
<strong>解释：</strong>'alex' 中的 'a' 和 'e' 被长按。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>name = "saeed", typed = "ssaaedd"
<strong>输出：</strong>false
<strong>解释：</strong>'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= name.length, typed.length &lt;= 1000</code></li>
	<li><code>name</code> 和&nbsp;<code>typed</code>&nbsp;的字符都是小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们利用两个指针 $i$ 和 $j$ 分别指向字符串 $\textit{typed}$ 和 $\textit{name}$ 的第一个字符，然后开始遍历，如果 $\textit{typed}[j] \neq \textit{name}[i]$，说明两个字符串不匹配，直接返回 $\textit{False}$。否则，我们找到连续相同的字符的下一个位置，分别记为 $x$ 和 $y$，如果 $x - i > y - j$，说明 $\textit{typed}$ 中的字符个数小于 $\textit{name}$ 中的字符个数，直接返回 $\textit{False}$。否则，我们将 $i$ 和 $j$ 更新为 $x$ 和 $y$，继续遍历，直到 $i$ 和 $j$ 分别遍历完 $\textit{name}$ 和 $\textit{typed}$，返回 $\textit{True}$。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是字符串 $\textit{name}$ 和 $\textit{typed}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        m, n = len(name), len(typed)
        i = j = 0
        while i < m and j < n:
            if name[i] != typed[j]:
                return False
            x = i + 1
            while x < m and name[x] == name[i]:
                x += 1
            y = j + 1
            while y < n and typed[y] == typed[j]:
                y += 1
            if x - i > y - j:
                return False
            i, j = x, y
        return i == m and j == n
```

#### Java

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int m = name.length(), n = typed.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (name.charAt(i) != typed.charAt(j)) {
                return false;
            }
            int x = i + 1;
            while (x < m && name.charAt(x) == name.charAt(i)) {
                ++x;
            }
            int y = j + 1;
            while (y < n && typed.charAt(y) == typed.charAt(j)) {
                ++y;
            }
            if (x - i > y - j) {
                return false;
            }
            i = x;
            j = y;
        }
        return i == m && j == n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.length(), n = typed.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (name[i] != typed[j]) {
                return false;
            }
            int x = i + 1;
            while (x < m && name[x] == name[i]) {
                ++x;
            }
            int y = j + 1;
            while (y < n && typed[y] == typed[j]) {
                ++y;
            }
            if (x - i > y - j) {
                return false;
            }
            i = x;
            j = y;
        }
        return i == m && j == n;
    }
};
```

#### Go

```go
func isLongPressedName(name string, typed string) bool {
	m, n := len(name), len(typed)
	i, j := 0, 0

	for i < m && j < n {
		if name[i] != typed[j] {
			return false
		}
		x, y := i+1, j+1

		for x < m && name[x] == name[i] {
			x++
		}

		for y < n && typed[y] == typed[j] {
			y++
		}

		if x-i > y-j {
			return false
		}

		i, j = x, y
	}

	return i == m && j == n
}
```

#### TypeScript

```ts
function isLongPressedName(name: string, typed: string): boolean {
    const [m, n] = [name.length, typed.length];
    let i = 0;
    let j = 0;
    while (i < m && j < n) {
        if (name[i] !== typed[j]) {
            return false;
        }
        let x = i + 1;
        while (x < m && name[x] === name[i]) {
            x++;
        }
        let y = j + 1;
        while (y < n && typed[y] === typed[j]) {
            y++;
        }
        if (x - i > y - j) {
            return false;
        }
        i = x;
        j = y;
    }
    return i === m && j === n;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let (m, n) = (name.len(), typed.len());
        let (mut i, mut j) = (0, 0);
        let s: Vec<char> = name.chars().collect();
        let t: Vec<char> = typed.chars().collect();

        while i < m && j < n {
            if s[i] != t[j] {
                return false;
            }
            let mut x = i + 1;
            while x < m && s[x] == s[i] {
                x += 1;
            }
            let mut y = j + 1;
            while y < n && t[y] == t[j] {
                y += 1;
            }
            if x - i > y - j {
                return false;
            }
            i = x;
            j = y;
        }

        i == m && j == n
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [926. 将字符串翻转到单调递增](https://leetcode.cn/problems/flip-string-to-monotone-increasing){#926}

{{< tabs "926" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        tot = s.count("0")
        ans, cur = tot, 0
        for i, c in enumerate(s, 1):
            cur += int(c == "0")
            ans = min(ans, i - cur + tot - cur)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                ++tot;
            }
        }
        int ans = tot, cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) == '0') {
                ++cur;
            }
            ans = Math.min(ans, i - cur + tot - cur);
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
    int minFlipsMonoIncr(string s) {
        int tot = count(s.begin(), s.end(), '0');
        int ans = tot, cur = 0;
        for (int i = 1; i <= s.size(); ++i) {
            cur += s[i - 1] == '0';
            ans = min(ans, i - cur + tot - cur);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlipsMonoIncr(s string) int {
	tot := strings.Count(s, "0")
	ans, cur := tot, 0
	for i, c := range s {
		if c == '0' {
			cur++
		}
		ans = min(ans, i+1-cur+tot-cur)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFlipsMonoIncr(s: string): number {
    let tot = 0;
    for (const c of s) {
        tot += c === '0' ? 1 : 0;
    }
    let [ans, cur] = [tot, 0];
    for (let i = 1; i <= s.length; ++i) {
        cur += s[i - 1] === '0' ? 1 : 0;
        ans = Math.min(ans, i - cur + tot - cur);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function (s) {
    let tot = 0;
    for (const c of s) {
        tot += c === '0' ? 1 : 0;
    }
    let [ans, cur] = [tot, 0];
    for (let i = 1; i <= s.length; ++i) {
        cur += s[i - 1] === '0' ? 1 : 0;
        ans = Math.min(ans, i - cur + tot - cur);
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个二进制字符串，是以一些 <code>0</code>（可能没有 <code>0</code>）后面跟着一些 <code>1</code>（也可能没有 <code>1</code>）的形式组成的，那么该字符串是 <strong>单调递增 </strong>的。</p>

<p>给你一个二进制字符串 <code>s</code>，你可以将任何 <code>0</code> 翻转为 <code>1</code> 或者将 <code>1</code> 翻转为 <code>0</code> 。</p>

<p>返回使 <code>s</code> 单调递增的最小翻转次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "00110"
<strong>输出：</strong>1
<strong>解释：</strong>翻转最后一位得到 00111.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "010110"
<strong>输出：</strong>2
<strong>解释：</strong>翻转得到 011111，或者是 000111。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "00011000"
<strong>输出：</strong>2
<strong>解释：</strong>翻转得到 00000000。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 枚举

我们可以先统计字符串 $s$ 中 $0$ 的个数，记为 $tot$。定义一个答案变量 $ans$，初始时 $ans = tot$，表示将所有 $0$ 变成 $1$ 的翻转次数。

然后，我们可以枚举每个位置 $i$，将位置 $i$ 及其左边的所有 $1$ 变成 $0$，将位置 $i$ 右边的所有 $0$ 变成 $1$，计算这种情况下的翻转次数，即 $i + 1 - cur + tot - cur$，其中 $cur$ 表示位置 $i$ 及其左边的 $0$ 的个数，更新答案 $ans = \min(ans, i + 1 - cur + tot - cur)$。

最后返回答案 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        tot = s.count("0")
        ans, cur = tot, 0
        for i, c in enumerate(s, 1):
            cur += int(c == "0")
            ans = min(ans, i - cur + tot - cur)
        return ans
```

#### Java

```java
class Solution {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                ++tot;
            }
        }
        int ans = tot, cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) == '0') {
                ++cur;
            }
            ans = Math.min(ans, i - cur + tot - cur);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int tot = count(s.begin(), s.end(), '0');
        int ans = tot, cur = 0;
        for (int i = 1; i <= s.size(); ++i) {
            cur += s[i - 1] == '0';
            ans = min(ans, i - cur + tot - cur);
        }
        return ans;
    }
};
```

#### Go

```go
func minFlipsMonoIncr(s string) int {
	tot := strings.Count(s, "0")
	ans, cur := tot, 0
	for i, c := range s {
		if c == '0' {
			cur++
		}
		ans = min(ans, i+1-cur+tot-cur)
	}
	return ans
}
```

#### TypeScript

```ts
function minFlipsMonoIncr(s: string): number {
    let tot = 0;
    for (const c of s) {
        tot += c === '0' ? 1 : 0;
    }
    let [ans, cur] = [tot, 0];
    for (let i = 1; i <= s.length; ++i) {
        cur += s[i - 1] === '0' ? 1 : 0;
        ans = Math.min(ans, i - cur + tot - cur);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function (s) {
    let tot = 0;
    for (const c of s) {
        tot += c === '0' ? 1 : 0;
    }
    let [ans, cur] = [tot, 0];
    for (let i = 1; i <= s.length; ++i) {
        cur += s[i - 1] === '0' ? 1 : 0;
        ans = Math.min(ans, i - cur + tot - cur);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [927. 三等分](https://leetcode.cn/problems/three-equal-parts){#927}

{{< tabs "927" >}}

{{% tab "bash" %}}
```bash
0 1 1 0 0 0 1 1 0 0 0 0 0 1 1 0 0
          ^         ^             ^
          i         j             k
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        def find(x):
            s = 0
            for i, v in enumerate(arr):
                s += v
                if s == x:
                    return i

        n = len(arr)
        cnt, mod = divmod(sum(arr), 3)
        if mod:
            return [-1, -1]
        if cnt == 0:
            return [0, n - 1]

        i, j, k = find(1), find(cnt + 1), find(cnt * 2 + 1)
        while k < n and arr[i] == arr[j] == arr[k]:
            i, j, k = i + 1, j + 1, k + 1
        return [i - 1, j] if k == n else [-1, -1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] arr;

    public int[] threeEqualParts(int[] arr) {
        this.arr = arr;
        int cnt = 0;
        int n = arr.length;
        for (int v : arr) {
            cnt += v;
        }
        if (cnt % 3 != 0) {
            return new int[] {-1, -1};
        }
        if (cnt == 0) {
            return new int[] {0, n - 1};
        }
        cnt /= 3;

        int i = find(1), j = find(cnt + 1), k = find(cnt * 2 + 1);
        for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {
        }
        return k == n ? new int[] {i - 1, j} : new int[] {-1, -1};
    }

    private int find(int x) {
        int s = 0;
        for (int i = 0; i < arr.length; ++i) {
            s += arr[i];
            if (s == x) {
                return i;
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int cnt = accumulate(arr.begin(), arr.end(), 0);
        if (cnt % 3) return {-1, -1};
        if (!cnt) return {0, n - 1};
        cnt /= 3;

        auto find = [&](int x) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                s += arr[i];
                if (s == x) return i;
            }
            return 0;
        };
        int i = find(1), j = find(cnt + 1), k = find(cnt * 2 + 1);
        for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {}
        return k == n ? vector<int>{i - 1, j} : vector<int>{-1, -1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func threeEqualParts(arr []int) []int {
	find := func(x int) int {
		s := 0
		for i, v := range arr {
			s += v
			if s == x {
				return i
			}
		}
		return 0
	}
	n := len(arr)
	cnt := 0
	for _, v := range arr {
		cnt += v
	}
	if cnt%3 != 0 {
		return []int{-1, -1}
	}
	if cnt == 0 {
		return []int{0, n - 1}
	}
	cnt /= 3
	i, j, k := find(1), find(cnt+1), find(cnt*2+1)
	for ; k < n && arr[i] == arr[j] && arr[j] == arr[k]; i, j, k = i+1, j+1, k+1 {
	}
	if k == n {
		return []int{i - 1, j}
	}
	return []int{-1, -1}
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function (arr) {
    function find(x) {
        let s = 0;
        for (let i = 0; i < n; ++i) {
            s += arr[i];
            if (s == x) {
                return i;
            }
        }
        return 0;
    }
    const n = arr.length;
    let cnt = 0;
    for (const v of arr) {
        cnt += v;
    }
    if (cnt % 3) {
        return [-1, -1];
    }
    if (cnt == 0) {
        return [0, n - 1];
    }
    cnt = Math.floor(cnt / 3);
    let [i, j, k] = [find(1), find(cnt + 1), find(cnt * 2 + 1)];
    for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {}
    return k == n ? [i - 1, j] : [-1, -1];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由 <code>0</code> 和 <code>1</code> 组成的数组<meta charset="UTF-8" />&nbsp;<code>arr</code>&nbsp;，将数组分成 &nbsp;<strong>3&nbsp;个非空的部分</strong> ，使得所有这些部分表示相同的二进制值。</p>

<p>如果可以做到，请返回<strong>任何</strong>&nbsp;<code>[i, j]</code>，其中 <code>i+1 &lt; j</code>，这样一来：</p>

<ul>
	<li><code>arr[0], arr[1], ..., arr[i]</code>&nbsp;为第一部分；</li>
	<li><code>arr[i + 1], arr[i + 2], ..., arr[j - 1]</code>&nbsp;为第二部分；</li>
	<li><code>arr[j], arr[j + 1], ..., arr[arr.length - 1]</code>&nbsp;为第三部分。</li>
	<li>这三个部分所表示的二进制值相等。</li>
</ul>

<p>如果无法做到，就返回&nbsp;<code>[-1, -1]</code>。</p>

<p>注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，<code>[1,1,0]</code>&nbsp;表示十进制中的&nbsp;<code>6</code>，而不会是&nbsp;<code>3</code>。此外，前导零也是<strong>被允许</strong>的，所以&nbsp;<code>[0,1,1]</code> 和&nbsp;<code>[1,1]</code>&nbsp;表示相同的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,0,1,0,1]
<strong>输出：</strong>[0,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,0,1,1]
<strong>输出：</strong>[-1,-1]</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,0,0,1]
<strong>输出：</strong>[0,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>3 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr[i]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 三指针

我们记数组的长度为 $n$，数组中 $1$ 的数量为 $cnt$。

显然 $cnt$ 必须是 $3$ 的倍数，否则无法将数组三等分，可以提前返回 $[-1, -1]$。如果 $cnt$ 为 $0$，那么意味着数组中所有元素都为 $0$，直接返回 $[0, n - 1]$ 即可。

我们将 $cnt$ 除以 $3$，得到每一份中 $1$ 的数量，然后找到每一份的第一个 $1$ 在数组 `arr` 中的位置（参考以下代码中的 $find(x)$ 函数），分别记为 $i$, $j$, $k$。

```bash
0 1 1 0 0 0 1 1 0 0 0 0 0 1 1 0 0
  ^         ^             ^
  i         j             k
```

接着我们从 $i$, $j$, $k$ 开始往后同时遍历每一部分，判断三部分对应的值是否相等，是则继续遍历，直至 $k$ 到达 $arr$ 末尾。

```bash
0 1 1 0 0 0 1 1 0 0 0 0 0 1 1 0 0
          ^         ^             ^
          i         j             k
```

遍历结束时，若 $k=n$，说明满足三等分，返回此时的 $[i - 1, j]$ 作为答案，否则返回 $[-1, -1]$。

时间复杂度 $O(n)$，其中 $n$ 表示 `arr` 的长度。空间复杂度 $O(1)$。

相似题目：

-   [1573. 分割字符串的方案数](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1573.Number%20of%20Ways%20to%20Split%20a%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        def find(x):
            s = 0
            for i, v in enumerate(arr):
                s += v
                if s == x:
                    return i

        n = len(arr)
        cnt, mod = divmod(sum(arr), 3)
        if mod:
            return [-1, -1]
        if cnt == 0:
            return [0, n - 1]

        i, j, k = find(1), find(cnt + 1), find(cnt * 2 + 1)
        while k < n and arr[i] == arr[j] == arr[k]:
            i, j, k = i + 1, j + 1, k + 1
        return [i - 1, j] if k == n else [-1, -1]
```

#### Java

```java
class Solution {
    private int[] arr;

    public int[] threeEqualParts(int[] arr) {
        this.arr = arr;
        int cnt = 0;
        int n = arr.length;
        for (int v : arr) {
            cnt += v;
        }
        if (cnt % 3 != 0) {
            return new int[] {-1, -1};
        }
        if (cnt == 0) {
            return new int[] {0, n - 1};
        }
        cnt /= 3;

        int i = find(1), j = find(cnt + 1), k = find(cnt * 2 + 1);
        for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {
        }
        return k == n ? new int[] {i - 1, j} : new int[] {-1, -1};
    }

    private int find(int x) {
        int s = 0;
        for (int i = 0; i < arr.length; ++i) {
            s += arr[i];
            if (s == x) {
                return i;
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int cnt = accumulate(arr.begin(), arr.end(), 0);
        if (cnt % 3) return {-1, -1};
        if (!cnt) return {0, n - 1};
        cnt /= 3;

        auto find = [&](int x) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                s += arr[i];
                if (s == x) return i;
            }
            return 0;
        };
        int i = find(1), j = find(cnt + 1), k = find(cnt * 2 + 1);
        for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {}
        return k == n ? vector<int>{i - 1, j} : vector<int>{-1, -1};
    }
};
```

#### Go

```go
func threeEqualParts(arr []int) []int {
	find := func(x int) int {
		s := 0
		for i, v := range arr {
			s += v
			if s == x {
				return i
			}
		}
		return 0
	}
	n := len(arr)
	cnt := 0
	for _, v := range arr {
		cnt += v
	}
	if cnt%3 != 0 {
		return []int{-1, -1}
	}
	if cnt == 0 {
		return []int{0, n - 1}
	}
	cnt /= 3
	i, j, k := find(1), find(cnt+1), find(cnt*2+1)
	for ; k < n && arr[i] == arr[j] && arr[j] == arr[k]; i, j, k = i+1, j+1, k+1 {
	}
	if k == n {
		return []int{i - 1, j}
	}
	return []int{-1, -1}
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function (arr) {
    function find(x) {
        let s = 0;
        for (let i = 0; i < n; ++i) {
            s += arr[i];
            if (s == x) {
                return i;
            }
        }
        return 0;
    }
    const n = arr.length;
    let cnt = 0;
    for (const v of arr) {
        cnt += v;
    }
    if (cnt % 3) {
        return [-1, -1];
    }
    if (cnt == 0) {
        return [0, n - 1];
    }
    cnt = Math.floor(cnt / 3);
    let [i, j, k] = [find(1), find(cnt + 1), find(cnt * 2 + 1)];
    for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {}
    return k == n ? [i - 1, j] : [-1, -1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [928. 尽量减少恶意软件的传播 II](https://leetcode.cn/problems/minimize-malware-spread-ii){#928}

{{< tabs "928" >}}

{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True

    def get_size(self, root: int) -> int:
        return self.size[root]


class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        n = len(graph)
        s = set(initial)
        uf = UnionFind(n)
        for i in range(n):
            if i not in s:
                for j in range(i + 1, n):
                    graph[i][j] and j not in s and uf.union(i, j)

        g = defaultdict(set)
        cnt = Counter()
        for i in initial:
            for j in range(n):
                if j not in s and graph[i][j]:
                    g[i].add(uf.find(j))
            for root in g[i]:
                cnt[root] += 1

        ans, mx = 0, -1
        for i in initial:
            t = sum(uf.get_size(root) for root in g[i] if cnt[root] == 1)
            if t > mx or (t == mx and i < ans):
                ans, mx = i, t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int root) {
        return size[root];
    }
}

class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        boolean[] s = new boolean[n];
        for (int i : initial) {
            s[i] = true;
        }
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            if (!s[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if (graph[i][j] == 1 && !s[j]) {
                        uf.union(i, j);
                    }
                }
            }
        }
        Set<Integer>[] g = new Set[n];
        Arrays.setAll(g, k -> new HashSet<>());
        int[] cnt = new int[n];
        for (int i : initial) {
            for (int j = 0; j < n; ++j) {
                if (!s[j] && graph[i][j] == 1) {
                    g[i].add(uf.find(j));
                }
            }
            for (int root : g[i]) {
                ++cnt[root];
            }
        }
        int ans = 0, mx = -1;
        for (int i : initial) {
            int t = 0;
            for (int root : g[i]) {
                if (cnt[root] == 1) {
                    t += uf.size(root);
                }
            }
            if (t > mx || (t == mx && i < ans)) {
                ans = i;
                mx = t;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int root) {
        return size[root];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        bool s[n];
        memset(s, false, sizeof(s));
        for (int i : initial) {
            s[i] = true;
        }
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            if (!s[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if (graph[i][j] && !s[j]) {
                        uf.unite(i, j);
                    }
                }
            }
        }
        unordered_set<int> g[n];
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        for (int i : initial) {
            for (int j = 0; j < n; ++j) {
                if (!s[j] && graph[i][j]) {
                    g[i].insert(uf.find(j));
                }
            }
            for (int root : g[i]) {
                ++cnt[root];
            }
        }
        int ans = 0, mx = -1;
        for (int i : initial) {
            int t = 0;
            for (int root : g[i]) {
                if (cnt[root] == 1) {
                    t += uf.getSize(root);
                }
            }
            if (t > mx || (t == mx && i < ans)) {
                ans = i;
                mx = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(root int) int {
	return uf.size[root]
}

func minMalwareSpread(graph [][]int, initial []int) int {
	n := len(graph)
	s := make([]bool, n)
	for _, i := range initial {
		s[i] = true
	}
	uf := newUnionFind(n)
	for i := range graph {
		if !s[i] {
			for j := i + 1; j < n; j++ {
				if graph[i][j] == 1 && !s[j] {
					uf.union(i, j)
				}
			}
		}
	}
	g := make([]map[int]bool, n)
	for _, i := range initial {
		g[i] = map[int]bool{}
	}
	cnt := make([]int, n)
	for _, i := range initial {
		for j := 0; j < n; j++ {
			if !s[j] && graph[i][j] == 1 {
				g[i][uf.find(j)] = true
			}
		}
		for root := range g[i] {
			cnt[root]++
		}
	}
	ans, mx := 0, -1
	for _, i := range initial {
		t := 0
		for root := range g[i] {
			if cnt[root] == 1 {
				t += uf.getSize(root)
			}
		}
		if t > mx || t == mx && i < ans {
			ans, mx = i, t
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(root: number): number {
        return this.size[root];
    }
}

function minMalwareSpread(graph: number[][], initial: number[]): number {
    const n = graph.length;
    const s = new Set(initial);
    const uf = new UnionFind(n);
    for (let i = 0; i < n; ++i) {
        if (!s.has(i)) {
            for (let j = i + 1; j < n; ++j) {
                if (graph[i][j] && !s.has(j)) {
                    uf.union(i, j);
                }
            }
        }
    }
    const g: Set<number>[] = Array.from({ length: n }, () => new Set());
    const cnt: number[] = Array(n).fill(0);
    for (const i of initial) {
        for (let j = 0; j < n; ++j) {
            if (graph[i][j] && !s.has(j)) {
                g[i].add(uf.find(j));
            }
        }
        for (const root of g[i]) {
            ++cnt[root];
        }
    }
    let ans = 0;
    let mx = -1;
    for (const i of initial) {
        let t = 0;
        for (const root of g[i]) {
            if (cnt[root] === 1) {
                t += uf.getSize(root);
            }
        }
        if (t > mx || (t === mx && i < ans)) {
            [ans, mx] = [i, t];
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由 <code>n</code> 个节点组成的网络，用 <code>n x n</code> 个邻接矩阵&nbsp;<code>graph</code>&nbsp;表示。在节点网络中，只有当&nbsp;<code>graph[i][j] = 1</code>&nbsp;时，节点&nbsp;<code>i</code>&nbsp;能够直接连接到另一个节点&nbsp;<code>j</code>。</p>

<p>一些节点&nbsp;<code>initial</code>&nbsp;最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。</p>

<p>假设&nbsp;<code>M(initial)</code>&nbsp;是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。</p>

<p>我们可以从 <code>initial</code> 中&nbsp;<strong>删除一个节点</strong>，<strong>并完全移除该节点以及从该节点到任何其他节点的任何连接。</strong></p>

<p>请返回移除后能够使&nbsp;<code>M(initial)</code>&nbsp;最小化的节点。如果有多个节点满足条件，返回索引 <strong>最小的节点</strong> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
<strong>输出：</strong>0
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
<strong>输出：</strong>1
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>n == graph[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 300</code></li>
	<li><code>graph[i][j]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>.</li>
	<li><code>graph[i][j] == graph[j][i]</code></li>
	<li><code>graph[i][i] == 1</code></li>
	<li><code>1 &lt;= initial.length &lt;&nbsp;n</code></li>
	<li><code>0 &lt;= initial[i] &lt;= n - 1</code></li>
	<li>&nbsp;<code>initial</code>&nbsp;中每个整数都<strong>不同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以使用并查集，将所有不在 $initial$ 中的节点，并且满足 $graph[i][j] = 1$ 的节点 $(i, j)$ 进行合并。

接下来，我们创建一个哈希表 $g$，其中 $g[i]$ 表示所有与节点 $i$ 相连的连通分量的根节点。我们还需要一个计数器 $cnt$，用来统计每个根节点被多少个初始节点感染。

对于每个初始时被感染的节点 $i$，我们遍历所有与节点 $i$ 相连的节点 $j$，如果节点 $j$ 不在 $initial$ 中，我们将节点 $j$ 的根节点加入到集合 $g[i]$ 中。同时，我们统计每个根节点被多少个初始节点感染，将结果保存到计数器 $cnt$ 中。

然后，我们用一个变量 $ans$ 记录答案，用 $mx$ 记录最多可以减少的被感染节点的数量。初始时 $ans = 0$, $mx = -1$。

遍历所有初始时被感染的节点，对于每个节点 $i$，我们遍历 $g[i]$ 中的所有根节点，如果根节点只被一个初始节点感染，我们累加这个根节点所在的连通分量的大小到 $t$ 中。如果 $t > mx$ 或者 $t = mx$ 且 $i < ans$，我们更新 $ans = i$, $mx = t$。

最后返回 $ans$ 即可。

时间复杂度 $O(n^2 \times \alpha(n))$，空间复杂度 $O(n^2)$。其中 $n$ 是节点的数量，而 $\alpha(n)$ 是 Ackermann 函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    __slots__ = "p", "size"

    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True

    def get_size(self, root: int) -> int:
        return self.size[root]


class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        n = len(graph)
        s = set(initial)
        uf = UnionFind(n)
        for i in range(n):
            if i not in s:
                for j in range(i + 1, n):
                    graph[i][j] and j not in s and uf.union(i, j)

        g = defaultdict(set)
        cnt = Counter()
        for i in initial:
            for j in range(n):
                if j not in s and graph[i][j]:
                    g[i].add(uf.find(j))
            for root in g[i]:
                cnt[root] += 1

        ans, mx = 0, -1
        for i in initial:
            t = sum(uf.get_size(root) for root in g[i] if cnt[root] == 1)
            if t > mx or (t == mx and i < ans):
                ans, mx = i, t
        return ans
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int root) {
        return size[root];
    }
}

class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        boolean[] s = new boolean[n];
        for (int i : initial) {
            s[i] = true;
        }
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            if (!s[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if (graph[i][j] == 1 && !s[j]) {
                        uf.union(i, j);
                    }
                }
            }
        }
        Set<Integer>[] g = new Set[n];
        Arrays.setAll(g, k -> new HashSet<>());
        int[] cnt = new int[n];
        for (int i : initial) {
            for (int j = 0; j < n; ++j) {
                if (!s[j] && graph[i][j] == 1) {
                    g[i].add(uf.find(j));
                }
            }
            for (int root : g[i]) {
                ++cnt[root];
            }
        }
        int ans = 0, mx = -1;
        for (int i : initial) {
            int t = 0;
            for (int root : g[i]) {
                if (cnt[root] == 1) {
                    t += uf.size(root);
                }
            }
            if (t > mx || (t == mx && i < ans)) {
                ans = i;
                mx = t;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int root) {
        return size[root];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        bool s[n];
        memset(s, false, sizeof(s));
        for (int i : initial) {
            s[i] = true;
        }
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            if (!s[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if (graph[i][j] && !s[j]) {
                        uf.unite(i, j);
                    }
                }
            }
        }
        unordered_set<int> g[n];
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        for (int i : initial) {
            for (int j = 0; j < n; ++j) {
                if (!s[j] && graph[i][j]) {
                    g[i].insert(uf.find(j));
                }
            }
            for (int root : g[i]) {
                ++cnt[root];
            }
        }
        int ans = 0, mx = -1;
        for (int i : initial) {
            int t = 0;
            for (int root : g[i]) {
                if (cnt[root] == 1) {
                    t += uf.getSize(root);
                }
            }
            if (t > mx || (t == mx && i < ans)) {
                ans = i;
                mx = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(root int) int {
	return uf.size[root]
}

func minMalwareSpread(graph [][]int, initial []int) int {
	n := len(graph)
	s := make([]bool, n)
	for _, i := range initial {
		s[i] = true
	}
	uf := newUnionFind(n)
	for i := range graph {
		if !s[i] {
			for j := i + 1; j < n; j++ {
				if graph[i][j] == 1 && !s[j] {
					uf.union(i, j)
				}
			}
		}
	}
	g := make([]map[int]bool, n)
	for _, i := range initial {
		g[i] = map[int]bool{}
	}
	cnt := make([]int, n)
	for _, i := range initial {
		for j := 0; j < n; j++ {
			if !s[j] && graph[i][j] == 1 {
				g[i][uf.find(j)] = true
			}
		}
		for root := range g[i] {
			cnt[root]++
		}
	}
	ans, mx := 0, -1
	for _, i := range initial {
		t := 0
		for root := range g[i] {
			if cnt[root] == 1 {
				t += uf.getSize(root)
			}
		}
		if t > mx || t == mx && i < ans {
			ans, mx = i, t
		}
	}
	return ans
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(root: number): number {
        return this.size[root];
    }
}

function minMalwareSpread(graph: number[][], initial: number[]): number {
    const n = graph.length;
    const s = new Set(initial);
    const uf = new UnionFind(n);
    for (let i = 0; i < n; ++i) {
        if (!s.has(i)) {
            for (let j = i + 1; j < n; ++j) {
                if (graph[i][j] && !s.has(j)) {
                    uf.union(i, j);
                }
            }
        }
    }
    const g: Set<number>[] = Array.from({ length: n }, () => new Set());
    const cnt: number[] = Array(n).fill(0);
    for (const i of initial) {
        for (let j = 0; j < n; ++j) {
            if (graph[i][j] && !s.has(j)) {
                g[i].add(uf.find(j));
            }
        }
        for (const root of g[i]) {
            ++cnt[root];
        }
    }
    let ans = 0;
    let mx = -1;
    for (const i of initial) {
        let t = 0;
        for (const root of g[i]) {
            if (cnt[root] === 1) {
                t += uf.getSize(root);
            }
        }
        if (t > mx || (t === mx && i < ans)) {
            [ans, mx] = [i, t];
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [929. 独特的电子邮件地址](https://leetcode.cn/problems/unique-email-addresses){#929}

{{< tabs "929" >}}

{{% tab "python" %}}
```python
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for email in emails:
            local, domain = email.split("@")
            t = []
            for c in local:
                if c == ".":
                    continue
                if c == "+":
                    break
                t.append(c)
            s.add("".join(t) + "@" + domain)
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> s = new HashSet<>();
        for (String email : emails) {
            String[] parts = email.split("@");
            String local = parts[0];
            String domain = parts[1];
            StringBuilder t = new StringBuilder();
            for (char c : local.toCharArray()) {
                if (c == '.') {
                    continue;
                }
                if (c == '+') {
                    break;
                }
                t.append(c);
            }
            s.add(t.toString() + "@" + domain);
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const string& email : emails) {
            size_t atPos = email.find('@');
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos + 1);
            string t;
            for (char c : local) {
                if (c == '.') {
                    continue;
                }
                if (c == '+') {
                    break;
                }
                t.push_back(c);
            }
            s.insert(t + "@" + domain);
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numUniqueEmails(emails []string) int {
	s := make(map[string]struct{})
	for _, email := range emails {
		parts := strings.Split(email, "@")
		local := parts[0]
		domain := parts[1]
		var t strings.Builder
		for _, c := range local {
			if c == '.' {
				continue
			}
			if c == '+' {
				break
			}
			t.WriteByte(byte(c))
		}
		s[t.String()+"@"+domain] = struct{}{}
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numUniqueEmails(emails: string[]): number {
    const s = new Set<string>();
    for (const email of emails) {
        const [local, domain] = email.split('@');
        let t = '';
        for (const c of local) {
            if (c === '.') {
                continue;
            }
            if (c === '+') {
                break;
            }
            t += c;
        }
        s.add(t + '@' + domain);
    }
    return s.size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
        let mut s = HashSet::new();

        for email in emails {
            let parts: Vec<&str> = email.split('@').collect();
            let local = parts[0];
            let domain = parts[1];
            let mut t = String::new();
            for c in local.chars() {
                if c == '.' {
                    continue;
                }
                if c == '+' {
                    break;
                }
                t.push(c);
            }
            s.insert(format!("{}@{}", t, domain));
        }

        s.len() as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function (emails) {
    const s = new Set();
    for (const email of emails) {
        const [local, domain] = email.split('@');
        let t = '';
        for (const c of local) {
            if (c === '.') {
                continue;
            }
            if (c === '+') {
                break;
            }
            t += c;
        }
        s.add(t + '@' + domain);
    }
    return s.size;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>每个 <strong>有效电子邮件地址</strong> 都由一个 <strong>本地名</strong> 和一个 <strong>域名</strong> 组成，以 <code>'@'</code> 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个&nbsp;<code>'.'</code> 或 <code>'+'</code> 。</p>

<ul>
	<li>例如，在&nbsp;<code>alice@leetcode.com</code>中，&nbsp;<code>alice</code>&nbsp;是 <strong>本地名</strong> ，而&nbsp;<code>leetcode.com</code>&nbsp;是 <strong>域名</strong> 。</li>
</ul>

<p>如果在电子邮件地址的<strong> 本地名 </strong>部分中的某些字符之间添加句点（<code>'.'</code>），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 <strong>不适用于域名</strong> 。</p>

<ul>
	<li>例如，<code>"alice.z@leetcode.com”</code> 和 <code>“alicez@leetcode.com”</code>&nbsp;会转发到同一电子邮件地址。</li>
</ul>

<p>如果在<strong> 本地名 </strong>中添加加号（<code>'+'</code>），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 <strong>不适用于域名</strong> 。</p>

<ul>
	<li>例如 <code>m.y+name@email.com</code> 将转发到 <code>my@email.com</code>。</li>
</ul>

<p>可以同时使用这两个规则。</p>

<p>给你一个字符串数组 <code>emails</code>，我们会向每个 <code>emails[i]</code> 发送一封电子邮件。返回实际收到邮件的不同地址数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
<strong>输出：</strong>2
<strong>解释：</strong>实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
<strong>输出：</strong>3
</pre>

<p><br />
<strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= emails.length &lt;= 100</code></li>
	<li><code>1 &lt;= emails[i].length&nbsp;&lt;= 100</code></li>
	<li><code>emails[i]</code> 由小写英文字母、<code>'+'</code>、<code>'.'</code> 和 <code>'@'</code> 组成</li>
	<li>每个 <code>emails[i]</code> 都包含有且仅有一个 <code>'@'</code> 字符</li>
	<li>所有本地名和域名都不为空</li>
	<li>本地名不会以 <code>'+'</code> 字符作为开头</li>
	<li>域名以&nbsp;<code>".com"</code> 后缀结尾。</li>
	<li>域名在&nbsp;<code>".com"</code> 后缀前至少包含一个字符</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $s$ 来存储所有的电子邮件地址，然后遍历数组 $\textit{emails}$，对于每个电子邮件地址，我们将其分为本地名和域名两部分，然后对本地名进行处理，去掉所有的点号和加号后面的字符，最后将处理后的本地名和域名拼接起来，加入哈希表 $s$ 中。

最后返回哈希表 $s$ 的大小即可。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 为所有电子邮件地址的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for email in emails:
            local, domain = email.split("@")
            t = []
            for c in local:
                if c == ".":
                    continue
                if c == "+":
                    break
                t.append(c)
            s.add("".join(t) + "@" + domain)
        return len(s)
```

#### Java

```java
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> s = new HashSet<>();
        for (String email : emails) {
            String[] parts = email.split("@");
            String local = parts[0];
            String domain = parts[1];
            StringBuilder t = new StringBuilder();
            for (char c : local.toCharArray()) {
                if (c == '.') {
                    continue;
                }
                if (c == '+') {
                    break;
                }
                t.append(c);
            }
            s.add(t.toString() + "@" + domain);
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const string& email : emails) {
            size_t atPos = email.find('@');
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos + 1);
            string t;
            for (char c : local) {
                if (c == '.') {
                    continue;
                }
                if (c == '+') {
                    break;
                }
                t.push_back(c);
            }
            s.insert(t + "@" + domain);
        }
        return s.size();
    }
};
```

#### Go

```go
func numUniqueEmails(emails []string) int {
	s := make(map[string]struct{})
	for _, email := range emails {
		parts := strings.Split(email, "@")
		local := parts[0]
		domain := parts[1]
		var t strings.Builder
		for _, c := range local {
			if c == '.' {
				continue
			}
			if c == '+' {
				break
			}
			t.WriteByte(byte(c))
		}
		s[t.String()+"@"+domain] = struct{}{}
	}
	return len(s)
}
```

#### TypeScript

```ts
function numUniqueEmails(emails: string[]): number {
    const s = new Set<string>();
    for (const email of emails) {
        const [local, domain] = email.split('@');
        let t = '';
        for (const c of local) {
            if (c === '.') {
                continue;
            }
            if (c === '+') {
                break;
            }
            t += c;
        }
        s.add(t + '@' + domain);
    }
    return s.size;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
        let mut s = HashSet::new();

        for email in emails {
            let parts: Vec<&str> = email.split('@').collect();
            let local = parts[0];
            let domain = parts[1];
            let mut t = String::new();
            for c in local.chars() {
                if c == '.' {
                    continue;
                }
                if c == '+' {
                    break;
                }
                t.push(c);
            }
            s.insert(format!("{}@{}", t, domain));
        }

        s.len() as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function (emails) {
    const s = new Set();
    for (const email of emails) {
        const [local, domain] = email.split('@');
        let t = '';
        for (const c of local) {
            if (c === '.') {
                continue;
            }
            if (c === '+') {
                break;
            }
            t += c;
        }
        s.add(t + '@' + domain);
    }
    return s.size;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
