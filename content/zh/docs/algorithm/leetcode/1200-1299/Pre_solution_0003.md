---
title: "1220_统计元音字母序列的数目"
date: 2025-10-08T18:37:06+08:00
weight: 3
tags: [动态规划, 双指针, 哈希表, 多线程, 字符串, 排序, 数学, 数据库, 数组, 概率与统计, 模拟, 矩阵, 脑筋急转弯, 计数, 贪心]
---

{{< markmap >}}
### [1220_统计元音字母序列的数目](#1220)
#### [动态规划](#1220)
### [1221_分割平衡字符串](#1221)
#### [贪心](#1221)
#### [字符串](#1221)
#### [计数](#1221)
### [1222_可以攻击国王的皇后](#1222)
#### [数组](#1222)
#### [矩阵](#1222)
#### [模拟](#1222)
### [1223_掷骰子模拟](#1223)
#### [数组](#1223)
#### [动态规划](#1223)
### [1224_最大相等频率](#1224)
#### [数组](#1224)
#### [哈希表](#1224)
### [1225_报告系统状态的连续日期 🔒](#1225)
#### [数据库](#1225)
### [1226_哲学家进餐](#1226)
#### [多线程](#1226)
### [1227_飞机座位分配概率](#1227)
#### [脑筋急转弯](#1227)
#### [数学](#1227)
#### [动态规划](#1227)
#### [概率与统计](#1227)
### [1228_等差数列中缺失的数字 🔒](#1228)
#### [数组](#1228)
#### [数学](#1228)
### [1229_安排会议日程 🔒](#1229)
#### [数组](#1229)
#### [双指针](#1229)
#### [排序](#1229)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1220_统计元音字母序列的数目
___
#### 动态规划
---
### 1221_分割平衡字符串
___
#### 贪心
___
#### 字符串
___
#### 计数
---
### 1222_可以攻击国王的皇后
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 1223_掷骰子模拟
___
#### 数组
___
#### 动态规划
---
### 1224_最大相等频率
___
#### 数组
___
#### 哈希表
---
### 1225_报告系统状态的连续日期 🔒
___
#### 数据库
---
### 1226_哲学家进餐
___
#### 多线程
---
### 1227_飞机座位分配概率
___
#### 脑筋急转弯
___
#### 数学
___
#### 动态规划
___
#### 概率与统计
---
### 1228_等差数列中缺失的数字 🔒
___
#### 数组
___
#### 数学
---
### 1229_安排会议日程 🔒
___
#### 数组
___
#### 双指针
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 双指针 | 哈希表 |
| 多线程 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 概率与统计 | 模拟 | 矩阵 |
| 脑筋急转弯 | 计数 | 贪心 |

# [1220. 统计元音字母序列的数目](https://leetcode.cn/problems/count-vowels-permutation){#1220}

{{< tabs "1220" >}}

{{% tab "python" %}}
```python
import numpy as np


class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod = 10**9 + 7
        factor = np.asmatrix(
            [
                (0, 1, 0, 0, 0),
                (1, 0, 1, 0, 0),
                (1, 1, 0, 1, 1),
                (0, 0, 1, 0, 1),
                (1, 0, 0, 0, 0),
            ],
            np.dtype("O"),
        )
        res = np.asmatrix([(1, 1, 1, 1, 1)], np.dtype("O"))
        n -= 1
        while n:
            if n & 1:
                res = res * factor % mod
            factor = factor * factor % mod
            n >>= 1
        return res.sum() % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int countVowelPermutation(int n) {
        long[][] a
            = {{0, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 1}, {0, 0, 1, 0, 1}, {1, 0, 0, 0, 0}};
        long[][] res = pow(a, n - 1);
        long ans = 0;
        for (long x : res[0]) {
            ans = (ans + x) % mod;
        }
        return (int) ans;
    }

    private long[][] mul(long[][] a, long[][] b) {
        int m = a.length, n = b[0].length;
        long[][] c = new long[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    }

    private long[][] pow(long[][] a, int n) {
        long[][] res = new long[1][a.length];
        Arrays.fill(res[0], 1);
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<ll>> a = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0}};
        vector<vector<ll>> res = pow(a, n - 1);
        return accumulate(res[0].begin(), res[0].end(), 0LL) % mod;
    }

private:
    using ll = long long;
    const int mod = 1e9 + 7;

    vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<ll>> c(m, vector<ll>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    }

    vector<vector<ll>> pow(vector<vector<ll>>& a, int n) {
        vector<vector<ll>> res;
        res.push_back({1, 1, 1, 1, 1});
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mod = 1e9 + 7

func countVowelPermutation(n int) (ans int) {
	a := [][]int{
		{0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 1, 1},
		{0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0}}
	res := pow(a, n-1)
	for _, x := range res[0] {
		ans = (ans + x) % mod
	}
	return
}

func mul(a, b [][]int) [][]int {
	m, n := len(a), len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	res := [][]int{{1, 1, 1, 1, 1}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const mod = 1e9 + 7;

function countVowelPermutation(n: number): number {
    const a: number[][] = [
        [0, 1, 0, 0, 0],
        [1, 0, 1, 0, 0],
        [1, 1, 0, 1, 1],
        [0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0],
    ];
    const res = pow(a, n - 1);
    return res[0].reduce((a, b) => (a + b) % mod);
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] =
                    (c[i][j] + Number((BigInt(a[i][k]) * BigInt(b[k][j])) % BigInt(mod))) % mod;
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res: number[][] = [[1, 1, 1, 1, 1]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */

const mod = 1e9 + 7;

var countVowelPermutation = function (n) {
    const a = [
        [0, 1, 0, 0, 0],
        [1, 0, 1, 0, 0],
        [1, 1, 0, 1, 1],
        [0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0],
    ];
    const res = pow(a, n - 1);
    return res[0].reduce((a, b) => (a + b) % mod);
};

function mul(a, b) {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] =
                    (c[i][j] + Number((BigInt(a[i][k]) * BigInt(b[k][j])) % BigInt(mod))) % mod;
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [[1, 1, 1, 1, 1]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>>= 1;
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>，请你帮忙统计一下我们可以按下述规则形成多少个长度为&nbsp;<code>n</code>&nbsp;的字符串：</p>

<ul>
	<li>字符串中的每个字符都应当是小写元音字母（<code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, <code>&#39;u&#39;</code>）</li>
	<li>每个元音&nbsp;<code>&#39;a&#39;</code>&nbsp;后面都只能跟着&nbsp;<code>&#39;e&#39;</code></li>
	<li>每个元音&nbsp;<code>&#39;e&#39;</code>&nbsp;后面只能跟着&nbsp;<code>&#39;a&#39;</code>&nbsp;或者是&nbsp;<code>&#39;i&#39;</code></li>
	<li>每个元音&nbsp;<code>&#39;i&#39;</code>&nbsp;后面&nbsp;<strong>不能</strong> 再跟着另一个&nbsp;<code>&#39;i&#39;</code></li>
	<li>每个元音&nbsp;<code>&#39;o&#39;</code>&nbsp;后面只能跟着&nbsp;<code>&#39;i&#39;</code>&nbsp;或者是&nbsp;<code>&#39;u&#39;</code></li>
	<li>每个元音&nbsp;<code>&#39;u&#39;</code>&nbsp;后面只能跟着&nbsp;<code>&#39;a&#39;</code></li>
</ul>

<p>由于答案可能会很大，所以请你返回 模&nbsp;<code>10^9 + 7</code>&nbsp;之后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>5
<strong>解释：</strong>所有可能的字符串分别是：&quot;a&quot;, &quot;e&quot;, &quot;i&quot; , &quot;o&quot; 和 &quot;u&quot;。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>10
<strong>解释：</strong>所有可能的字符串分别是：&quot;ae&quot;, &quot;ea&quot;, &quot;ei&quot;, &quot;ia&quot;, &quot;ie&quot;, &quot;io&quot;, &quot;iu&quot;, &quot;oi&quot;, &quot;ou&quot; 和 &quot;ua&quot;。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>68</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

根据题目描述，我们先列出每个元音字母的后一个字母：

```
a [e]
e [a|i]
i [a|e|o|u]
o [i|u]
u [a]
```

那么我们可以推出每个元音字母的前一个字母：

```
[e|i|u]	a
[a|i]	e
[e|o]	i
[i]	o
[i|o]	u
```

我们定义 $f[i]$ 表示当前长度以第 $i$ 个元音字母结尾的字符串的个数，如果长度为 $1$，那么 $f[i]=1$。

当长度大于 $1$ 时，我们定义 $g[i]$ 表示当前长度以第 $i$ 个元音字母结尾的字符串的个数，那么 $g[i]$ 可以由 $f$ 转移而来，即：

$$
g[i]=
\begin{cases}
f[1]+f[2]+f[4] & i=0 \\
f[0]+f[2] & i=1 \\
f[1]+f[3] & i=2 \\
f[2] & i=3 \\
f[2]+f[3] & i=4
\end{cases}
$$

最终答案为 $\sum_{i=0}^{4}f[i]$。注意由于答案可能会很大，所以需要对 $10^9+7$ 取模。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是字符串的长度，而 $C$ 是元音字母的个数。本题中 $C=5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        f = [1] * 5
        mod = 10**9 + 7
        for _ in range(n - 1):
            g = [0] * 5
            g[0] = (f[1] + f[2] + f[4]) % mod
            g[1] = (f[0] + f[2]) % mod
            g[2] = (f[1] + f[3]) % mod
            g[3] = f[2]
            g[4] = (f[2] + f[3]) % mod
            f = g
        return sum(f) % mod
```

#### Java

```java
class Solution {
    public int countVowelPermutation(int n) {
        long[] f = new long[5];
        Arrays.fill(f, 1);
        final int mod = (int) 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            long[] g = new long[5];
            g[0] = (f[1] + f[2] + f[4]) % mod;
            g[1] = (f[0] + f[2]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[2];
            g[4] = (f[2] + f[3]) % mod;
            f = g;
        }
        long ans = 0;
        for (long x : f) {
            ans = (ans + x) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
        using ll = long long;
        vector<ll> f(5, 1);
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            vector<ll> g(5);
            g[0] = (f[1] + f[2] + f[4]) % mod;
            g[1] = (f[0] + f[2]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[2];
            g[4] = (f[2] + f[3]) % mod;
            f = move(g);
        }
        return accumulate(f.begin(), f.end(), 0LL) % mod;
    }
};
```

#### Go

```go
func countVowelPermutation(n int) (ans int) {
	const mod int = 1e9 + 7
	f := make([]int, 5)
	for i := range f {
		f[i] = 1
	}
	for i := 1; i < n; i++ {
		g := make([]int, 5)
		g[0] = (f[1] + f[2] + f[4]) % mod
		g[1] = (f[0] + f[2]) % mod
		g[2] = (f[1] + f[3]) % mod
		g[3] = f[2] % mod
		g[4] = (f[2] + f[3]) % mod
		f = g
	}
	for _, x := range f {
		ans = (ans + x) % mod
	}
	return
}
```

#### TypeScript

```ts
function countVowelPermutation(n: number): number {
    const f: number[] = Array(5).fill(1);
    const mod = 1e9 + 7;
    for (let i = 1; i < n; ++i) {
        const g: number[] = Array(5).fill(0);
        g[0] = (f[1] + f[2] + f[4]) % mod;
        g[1] = (f[0] + f[2]) % mod;
        g[2] = (f[1] + f[3]) % mod;
        g[3] = f[2];
        g[4] = (f[2] + f[3]) % mod;
        f.splice(0, 5, ...g);
    }
    return f.reduce((a, b) => (a + b) % mod);
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var countVowelPermutation = function (n) {
    const mod = 1e9 + 7;
    const f = Array(5).fill(1);
    for (let i = 1; i < n; ++i) {
        const g = Array(5).fill(0);
        g[0] = (f[1] + f[2] + f[4]) % mod;
        g[1] = (f[0] + f[2]) % mod;
        g[2] = (f[1] + f[3]) % mod;
        g[3] = f[2];
        g[4] = (f[2] + f[3]) % mod;
        f.splice(0, 5, ...g);
    }
    return f.reduce((a, b) => (a + b) % mod);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：矩阵快速幂加速递推

时间复杂度 $O(C^3 \times \log n)$，空间复杂度 $O(C^2)$，其中 $C$ 是元音字母的个数，本题中 $C=5$。

<!-- tabs:start -->

#### Python3

```python
import numpy as np


class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mod = 10**9 + 7
        factor = np.asmatrix(
            [
                (0, 1, 0, 0, 0),
                (1, 0, 1, 0, 0),
                (1, 1, 0, 1, 1),
                (0, 0, 1, 0, 1),
                (1, 0, 0, 0, 0),
            ],
            np.dtype("O"),
        )
        res = np.asmatrix([(1, 1, 1, 1, 1)], np.dtype("O"))
        n -= 1
        while n:
            if n & 1:
                res = res * factor % mod
            factor = factor * factor % mod
            n >>= 1
        return res.sum() % mod
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int countVowelPermutation(int n) {
        long[][] a
            = {{0, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 1}, {0, 0, 1, 0, 1}, {1, 0, 0, 0, 0}};
        long[][] res = pow(a, n - 1);
        long ans = 0;
        for (long x : res[0]) {
            ans = (ans + x) % mod;
        }
        return (int) ans;
    }

    private long[][] mul(long[][] a, long[][] b) {
        int m = a.length, n = b[0].length;
        long[][] c = new long[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    }

    private long[][] pow(long[][] a, int n) {
        long[][] res = new long[1][a.length];
        Arrays.fill(res[0], 1);
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<ll>> a = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0}};
        vector<vector<ll>> res = pow(a, n - 1);
        return accumulate(res[0].begin(), res[0].end(), 0LL) % mod;
    }

private:
    using ll = long long;
    const int mod = 1e9 + 7;

    vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<ll>> c(m, vector<ll>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    }

    vector<vector<ll>> pow(vector<vector<ll>>& a, int n) {
        vector<vector<ll>> res;
        res.push_back({1, 1, 1, 1, 1});
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```

#### Go

```go
const mod = 1e9 + 7

func countVowelPermutation(n int) (ans int) {
	a := [][]int{
		{0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 1, 1},
		{0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0}}
	res := pow(a, n-1)
	for _, x := range res[0] {
		ans = (ans + x) % mod
	}
	return
}

func mul(a, b [][]int) [][]int {
	m, n := len(a), len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	res := [][]int{{1, 1, 1, 1, 1}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```

#### TypeScript

```ts
const mod = 1e9 + 7;

function countVowelPermutation(n: number): number {
    const a: number[][] = [
        [0, 1, 0, 0, 0],
        [1, 0, 1, 0, 0],
        [1, 1, 0, 1, 1],
        [0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0],
    ];
    const res = pow(a, n - 1);
    return res[0].reduce((a, b) => (a + b) % mod);
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] =
                    (c[i][j] + Number((BigInt(a[i][k]) * BigInt(b[k][j])) % BigInt(mod))) % mod;
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res: number[][] = [[1, 1, 1, 1, 1]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>>= 1;
    }
    return res;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */

const mod = 1e9 + 7;

var countVowelPermutation = function (n) {
    const a = [
        [0, 1, 0, 0, 0],
        [1, 0, 1, 0, 0],
        [1, 1, 0, 1, 1],
        [0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0],
    ];
    const res = pow(a, n - 1);
    return res[0].reduce((a, b) => (a + b) % mod);
};

function mul(a, b) {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] =
                    (c[i][j] + Number((BigInt(a[i][k]) * BigInt(b[k][j])) % BigInt(mod))) % mod;
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [[1, 1, 1, 1, 1]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>>= 1;
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1221. 分割平衡字符串](https://leetcode.cn/problems/split-a-string-in-balanced-strings){#1221}

{{< tabs "1221" >}}

{{% tab "python" %}}
```python
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = l = 0
        for c in s:
            if c == 'L':
                l += 1
            else:
                l -= 1
            if l == 0:
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int balancedStringSplit(String s) {
        int ans = 0, l = 0;
        for (char c : s.toCharArray()) {
            if (c == 'L') {
                ++l;
            } else {
                --l;
            }
            if (l == 0) {
                ++ans;
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
    int balancedStringSplit(string s) {
        int ans = 0, l = 0;
        for (char c : s) {
            if (c == 'L')
                ++l;
            else
                --l;
            if (l == 0) ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func balancedStringSplit(s string) int {
	ans, l := 0, 0
	for _, c := range s {
		if c == 'L' {
			l++
		} else {
			l--
		}
		if l == 0 {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function (s) {
    let ans = 0;
    let l = 0;
    for (let c of s) {
        if (c == 'L') {
            ++l;
        } else {
            --l;
        }
        if (l == 0) {
            ++ans;
        }
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

<p><strong>平衡字符串</strong> 中，<code>'L'</code> 和 <code>'R'</code> 字符的数量是相同的。</p>

<p>给你一个平衡字符串&nbsp;<code>s</code>，请你将它分割成尽可能多的子字符串，并满足：</p>

<ul>
	<li>每个子字符串都是平衡字符串。</li>
</ul>

<p>返回可以通过分割得到的平衡字符串的 <strong>最大数量</strong> <strong>。</strong></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "RLRRLLRLRL"
<strong>输出：</strong>4
<strong>解释：</strong>s 可以分割为 "RL"、"RRLL"、"RL"、"RL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "RLRRRLLRLL"
<strong>输出：</strong>2
<strong>解释：</strong>s 可以分割为 "RL"、"RRRLLRLL"，每个子字符串中都包含相同数量的 'L' 和 'R' 。
注意，s 无法分割为 "RL"、"RR"、"RL"、"LR"、"LL" 因为第 2 个和第 5 个子字符串不是平衡字符串。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "LLLLRRRR"
<strong>输出：</strong>1
<strong>解释：</strong>s 只能保持原样 "LLLLRRRR" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i] = 'L' 或 'R'</code></li>
	<li><code>s</code> 是一个 <strong>平衡</strong> 字符串</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用变量 $l$ 维护当前字符串的平衡度，即 $l$ 的值为当前字符串中 $L$ 的数量减去 $R$ 的数量。当 $l$ 的值为 0 时，我们就找到了一个平衡字符串。

遍历字符串 $s$，当遍历到第 $i$ 个字符时，如果 $s[i] = L$，则 $l$ 的值加 1，否则 $l$ 的值减 1。当 $l$ 的值为 0 时，我们将答案加 1。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = l = 0
        for c in s:
            if c == 'L':
                l += 1
            else:
                l -= 1
            if l == 0:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int balancedStringSplit(String s) {
        int ans = 0, l = 0;
        for (char c : s.toCharArray()) {
            if (c == 'L') {
                ++l;
            } else {
                --l;
            }
            if (l == 0) {
                ++ans;
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
    int balancedStringSplit(string s) {
        int ans = 0, l = 0;
        for (char c : s) {
            if (c == 'L')
                ++l;
            else
                --l;
            if (l == 0) ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func balancedStringSplit(s string) int {
	ans, l := 0, 0
	for _, c := range s {
		if c == 'L' {
			l++
		} else {
			l--
		}
		if l == 0 {
			ans++
		}
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function (s) {
    let ans = 0;
    let l = 0;
    for (let c of s) {
        if (c == 'L') {
            ++l;
        } else {
            --l;
        }
        if (l == 0) {
            ++ans;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1222. 可以攻击国王的皇后](https://leetcode.cn/problems/queens-that-can-attack-the-king){#1222}

{{< tabs "1222" >}}

{{% tab "python" %}}
```python
class Solution:
    def queensAttacktheKing(
        self, queens: List[List[int]], king: List[int]
    ) -> List[List[int]]:
        n = 8
        s = {(i, j) for i, j in queens}
        ans = []
        for a in range(-1, 2):
            for b in range(-1, 2):
                if a or b:
                    x, y = king
                    while 0 <= x + a < n and 0 <= y + b < n:
                        x, y = x + a, y + b
                        if (x, y) in s:
                            ans.append([x, y])
                            break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        final int n = 8;
        var s = new boolean[n][n];
        for (var q : queens) {
            s[q[0]][q[1]] = true;
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a != 0 || b != 0) {
                    int x = king[0] + a, y = king[1] + b;
                    while (x >= 0 && x < n && y >= 0 && y < n) {
                        if (s[x][y]) {
                            ans.add(List.of(x, y));
                            break;
                        }
                        x += a;
                        y += b;
                    }
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
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = 8;
        bool s[8][8]{};
        for (auto& q : queens) {
            s[q[0]][q[1]] = true;
        }
        vector<vector<int>> ans;
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a || b) {
                    int x = king[0] + a, y = king[1] + b;
                    while (x >= 0 && x < n && y >= 0 && y < n) {
                        if (s[x][y]) {
                            ans.push_back({x, y});
                            break;
                        }
                        x += a;
                        y += b;
                    }
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
func queensAttacktheKing(queens [][]int, king []int) (ans [][]int) {
	n := 8
	s := [8][8]bool{}
	for _, q := range queens {
		s[q[0]][q[1]] = true
	}
	for a := -1; a <= 1; a++ {
		for b := -1; b <= 1; b++ {
			if a != 0 || b != 0 {
				x, y := king[0]+a, king[1]+b
				for 0 <= x && x < n && 0 <= y && y < n {
					if s[x][y] {
						ans = append(ans, []int{x, y})
						break
					}
					x += a
					y += b
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function queensAttacktheKing(queens: number[][], king: number[]): number[][] {
    const n = 8;
    const s: boolean[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => false));
    queens.forEach(([x, y]) => (s[x][y] = true));
    const ans: number[][] = [];
    for (let a = -1; a <= 1; ++a) {
        for (let b = -1; b <= 1; ++b) {
            if (a || b) {
                let [x, y] = [king[0] + a, king[1] + b];
                while (x >= 0 && x < n && y >= 0 && y < n) {
                    if (s[x][y]) {
                        ans.push([x, y]);
                        break;
                    }
                    x += a;
                    y += b;
                }
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

<p>在一个 <strong>下标从 0 开始</strong> 的 <code>8 x 8</code> 棋盘上，可能有多个黑皇后和一个白国王。</p>

<p>给你一个二维整数数组 <code>queens</code>，其中 <code>queens[i] = [xQueeni, yQueeni]</code> 表示第 <code>i</code> 个黑皇后在棋盘上的位置。还给你一个长度为 <code>2</code> 的整数数组 <code>king</code>，其中 <code>king = [xKing, yKing]</code> 表示白国王的位置。</p>

<p>返回 <em>能够直接攻击国王的黑皇后的坐标</em>。你可以以 <strong>任何顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1222.Queens%20That%20Can%20Attack%20the%20King/images/1703052515-HqjAJq-chess1.jpg" style="width: 400px; height: 400px;" /></p>

<pre>
<strong>输入：</strong>queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
<strong>输出：</strong>[[0,1],[1,0],[3,3]]
<strong>解释：</strong>上面的图示显示了三个可以直接攻击国王的皇后和三个不能攻击国王的皇后（用红色虚线标记）。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1222.Queens%20That%20Can%20Attack%20the%20King/images/1703052660-bPPflt-chess2.jpg" style="width: 400px; height: 400px;" /></strong></p>

<pre>
<strong>输入：</strong>queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
<strong>输出：</strong>[[2,2],[3,4],[4,4]]
<strong>解释：</strong>上面的图示显示了三个能够直接攻击国王的黑皇后和三个不能攻击国王的黑皇后（用红色虚线标记）。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><meta charset="UTF-8" /><code>1 &lt;= queens.length &lt; 64</code></li>
	<li><code>queens[i].length == king.length == 2</code></li>
	<li><code>0 &lt;= xQueen<sub>i</sub>, yQueen<sub>i</sub>, xKing, yKing &lt; 8</code></li>
	<li>所有给定的位置都是 <strong>唯一</strong> 的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接搜索

我们先将所有皇后的位置存入哈希表或者二维数组 $s$ 中。

接下来，我们从国王的位置开始，依次向上、下、左、右、左上、右上、左下、右下八个方向搜索，如果某个方向上存在皇后，那么就将其位置加入答案中，并且停止继续搜索该方向。

搜索结束后，返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。本题中 $n = 8$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def queensAttacktheKing(
        self, queens: List[List[int]], king: List[int]
    ) -> List[List[int]]:
        n = 8
        s = {(i, j) for i, j in queens}
        ans = []
        for a in range(-1, 2):
            for b in range(-1, 2):
                if a or b:
                    x, y = king
                    while 0 <= x + a < n and 0 <= y + b < n:
                        x, y = x + a, y + b
                        if (x, y) in s:
                            ans.append([x, y])
                            break
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        final int n = 8;
        var s = new boolean[n][n];
        for (var q : queens) {
            s[q[0]][q[1]] = true;
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a != 0 || b != 0) {
                    int x = king[0] + a, y = king[1] + b;
                    while (x >= 0 && x < n && y >= 0 && y < n) {
                        if (s[x][y]) {
                            ans.add(List.of(x, y));
                            break;
                        }
                        x += a;
                        y += b;
                    }
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
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = 8;
        bool s[8][8]{};
        for (auto& q : queens) {
            s[q[0]][q[1]] = true;
        }
        vector<vector<int>> ans;
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a || b) {
                    int x = king[0] + a, y = king[1] + b;
                    while (x >= 0 && x < n && y >= 0 && y < n) {
                        if (s[x][y]) {
                            ans.push_back({x, y});
                            break;
                        }
                        x += a;
                        y += b;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func queensAttacktheKing(queens [][]int, king []int) (ans [][]int) {
	n := 8
	s := [8][8]bool{}
	for _, q := range queens {
		s[q[0]][q[1]] = true
	}
	for a := -1; a <= 1; a++ {
		for b := -1; b <= 1; b++ {
			if a != 0 || b != 0 {
				x, y := king[0]+a, king[1]+b
				for 0 <= x && x < n && 0 <= y && y < n {
					if s[x][y] {
						ans = append(ans, []int{x, y})
						break
					}
					x += a
					y += b
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function queensAttacktheKing(queens: number[][], king: number[]): number[][] {
    const n = 8;
    const s: boolean[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => false));
    queens.forEach(([x, y]) => (s[x][y] = true));
    const ans: number[][] = [];
    for (let a = -1; a <= 1; ++a) {
        for (let b = -1; b <= 1; ++b) {
            if (a || b) {
                let [x, y] = [king[0] + a, king[1] + b];
                while (x >= 0 && x < n && y >= 0 && y < n) {
                    if (s[x][y]) {
                        ans.push([x, y]);
                        break;
                    }
                    x += a;
                    y += b;
                }
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

# [1223. 掷骰子模拟](https://leetcode.cn/problems/dice-roll-simulation){#1223}

{{< tabs "1223" >}}

{{% tab "python" %}}
```python
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        f = [[[0] * 16 for _ in range(7)] for _ in range(n + 1)]
        for j in range(1, 7):
            f[1][j][1] = 1
        for i in range(2, n + 1):
            for j in range(1, 7):
                for x in range(1, rollMax[j - 1] + 1):
                    for k in range(1, 7):
                        if k != j:
                            f[i][k][1] += f[i - 1][j][x]
                        elif x + 1 <= rollMax[j - 1]:
                            f[i][j][x + 1] += f[i - 1][j][x]
        mod = 10**9 + 7
        ans = 0
        for j in range(1, 7):
            for x in range(1, rollMax[j - 1] + 1):
                ans = (ans + f[n][j][x]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int[][][] f = new int[n + 1][7][16];
        for (int j = 1; j <= 6; ++j) {
            f[1][j][1] = 1;
        }
        final int mod = (int) 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int x = 1; x <= rollMax[j - 1]; ++x) {
                    for (int k = 1; k <= 6; ++k) {
                        if (k != j) {
                            f[i][k][1] = (f[i][k][1] + f[i - 1][j][x]) % mod;
                        } else if (x + 1 <= rollMax[j - 1]) {
                            f[i][j][x + 1] = (f[i][j][x + 1] + f[i - 1][j][x]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= 6; ++j) {
            for (int x = 1; x <= rollMax[j - 1]; ++x) {
                ans = (ans + f[n][j][x]) % mod;
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
    int dieSimulator(int n, vector<int>& rollMax) {
        int f[n + 1][7][16];
        memset(f, 0, sizeof f);
        for (int j = 1; j <= 6; ++j) {
            f[1][j][1] = 1;
        }
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int x = 1; x <= rollMax[j - 1]; ++x) {
                    for (int k = 1; k <= 6; ++k) {
                        if (k != j) {
                            f[i][k][1] = (f[i][k][1] + f[i - 1][j][x]) % mod;
                        } else if (x + 1 <= rollMax[j - 1]) {
                            f[i][j][x + 1] = (f[i][j][x + 1] + f[i - 1][j][x]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= 6; ++j) {
            for (int x = 1; x <= rollMax[j - 1]; ++x) {
                ans = (ans + f[n][j][x]) % mod;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func dieSimulator(n int, rollMax []int) (ans int) {
	f := make([][7][16]int, n+1)
	for j := 1; j <= 6; j++ {
		f[1][j][1] = 1
	}
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		for j := 1; j <= 6; j++ {
			for x := 1; x <= rollMax[j-1]; x++ {
				for k := 1; k <= 6; k++ {
					if k != j {
						f[i][k][1] = (f[i][k][1] + f[i-1][j][x]) % mod
					} else if x+1 <= rollMax[j-1] {
						f[i][j][x+1] = (f[i][j][x+1] + f[i-1][j][x]) % mod
					}
				}
			}
		}
	}
	for j := 1; j <= 6; j++ {
		for x := 1; x <= rollMax[j-1]; x++ {
			ans = (ans + f[n][j][x]) % mod
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。</p>

<p>不过我们在使用它时有个约束，就是使得投掷骰子时，<strong>连续</strong> 掷出数字&nbsp;<code>i</code>&nbsp;的次数不能超过&nbsp;<code>rollMax[i]</code>（<code>i</code>&nbsp;从 1 开始编号）。</p>

<p>现在，给你一个整数数组&nbsp;<code>rollMax</code>&nbsp;和一个整数&nbsp;<code>n</code>，请你来计算掷&nbsp;<code>n</code>&nbsp;次骰子可得到的不同点数序列的数量。</p>

<p>假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 <strong>模&nbsp;<code>10^9 + 7</code></strong>&nbsp;之后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, rollMax = [1,1,2,2,2,3]
<strong>输出：</strong>34
<strong>解释：</strong>我们掷 2 次骰子，如果没有约束的话，共有 6 * 6 = 36 种可能的组合。但是根据 rollMax 数组，数字 1 和 2 最多连续出现一次，所以不会出现序列 (1,1) 和 (2,2)。因此，最终答案是 36-2 = 34。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2, rollMax = [1,1,1,1,1,1]
<strong>输出：</strong>30
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3, rollMax = [1,1,1,2,2,3]
<strong>输出：</strong>181
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>rollMax.length == 6</code></li>
	<li><code>1 &lt;= rollMax[i] &lt;= 15</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们可以设计一个函数 $dfs(i, j, x)$ 表示从第 $i$ 次掷骰子开始，当前掷出的点数为 $j$，且连续掷出 $j$ 的次数为 $x$ 的方案数。其中 $j$ 的取值范围为 $[1, 6]$，而 $x$ 的取值范围为 $[1, rollMax[j - 1]]$。那么答案就是 $dfs(0, 0, 0)$。

函数 $dfs(i, j, x)$ 的计算过程如下：

-   如果 $i \ge n$，说明已经掷完了 $n$ 次骰子，返回 $1$。
-   否则，我们枚举下一次掷出的点数 $k$，如果 $k \ne j$，那么我们可以直接掷出 $k$，此时连续掷出 $j$ 的次数 $x$ 就会被重置为 $1$，因此方案数为 $dfs(i + 1, k, 1)$。如果 $k = j$，那么我们需要判断 $x$ 是否小于 $rollMax[j - 1]$，如果小于，那么我们可以继续掷出 $j$，此时连续掷出 $j$ 的次数 $x$ 就会加 $1$，因此方案数为 $dfs(i + 1, j, x + 1)$。最后将所有方案数相加，即为 $dfs(i, j, x)$ 的值。注意答案可能很大，因此需要对 $10^9 + 7$ 取模。

过程中，我们可以使用记忆化搜索避免重复计算。

时间复杂度 $O(n \times k^2 \times M)$，空间复杂度 $O(n \times k \times M)$。其中 $k$ 为点数的取值范围，而 $M$ 为连续掷出某个点数的最大次数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        @cache
        def dfs(i, j, x):
            if i >= n:
                return 1
            ans = 0
            for k in range(1, 7):
                if k != j:
                    ans += dfs(i + 1, k, 1)
                elif x < rollMax[j - 1]:
                    ans += dfs(i + 1, j, x + 1)
            return ans % (10**9 + 7)

        return dfs(0, 0, 0)
```

#### Java

```java
class Solution {
    private Integer[][][] f;
    private int[] rollMax;

    public int dieSimulator(int n, int[] rollMax) {
        f = new Integer[n][7][16];
        this.rollMax = rollMax;
        return dfs(0, 0, 0);
    }

    private int dfs(int i, int j, int x) {
        if (i >= f.length) {
            return 1;
        }
        if (f[i][j][x] != null) {
            return f[i][j][x];
        }
        long ans = 0;
        for (int k = 1; k <= 6; ++k) {
            if (k != j) {
                ans += dfs(i + 1, k, 1);
            } else if (x < rollMax[j - 1]) {
                ans += dfs(i + 1, j, x + 1);
            }
        }
        ans %= 1000000007;
        return f[i][j][x] = (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int f[n][7][16];
        memset(f, 0, sizeof f);
        const int mod = 1e9 + 7;
        function<int(int, int, int)> dfs = [&](int i, int j, int x) -> int {
            if (i >= n) {
                return 1;
            }
            if (f[i][j][x]) {
                return f[i][j][x];
            }
            long ans = 0;
            for (int k = 1; k <= 6; ++k) {
                if (k != j) {
                    ans += dfs(i + 1, k, 1);
                } else if (x < rollMax[j - 1]) {
                    ans += dfs(i + 1, j, x + 1);
                }
            }
            ans %= mod;
            return f[i][j][x] = ans;
        };
        return dfs(0, 0, 0);
    }
};
```

#### Go

```go
func dieSimulator(n int, rollMax []int) int {
	f := make([][7][16]int, n)
	const mod = 1e9 + 7
	var dfs func(i, j, x int) int
	dfs = func(i, j, x int) int {
		if i >= n {
			return 1
		}
		if f[i][j][x] != 0 {
			return f[i][j][x]
		}
		ans := 0
		for k := 1; k <= 6; k++ {
			if k != j {
				ans += dfs(i+1, k, 1)
			} else if x < rollMax[j-1] {
				ans += dfs(i+1, j, x+1)
			}
		}
		f[i][j][x] = ans % mod
		return f[i][j][x]
	}
	return dfs(0, 0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索改为动态规划。

定义 $f[i][j][x]$ 表示投掷前 $i$ 次骰子，且第 $i$ 次投掷的点数为 $j$，且连续投掷点数 $j$ 的次数为 $x$ 的方案数。初始时 $f[1][j][1] = 1$，其中 $1 \leq j \leq 6$。答案即是：

$$
\sum_{j=1}^6 \sum_{x=1}^{rollMax[j-1]} f[n][j][x]
$$

我们枚举上一次投掷的点数为 $j$，且连续投掷点数 $j$ 的次数为 $x$，那么当前投掷的点数可以为 $1, 2, \cdots, 6$，如果当前投掷的点数为 $k$，那么有如下两种情况：

-   如果 $k \neq j$，那么我们可以直接投掷出 $k$，此时连续投掷点数 $j$ 的次数 $x$ 就会被重置为 $1$，因此方案数 $f[i][k][1]$ 就会增加 $f[i-1][j][x]$。
-   如果 $k = j$，那么我们需要判断 $x+1$ 是否小于等于 $rollMax[j-1]$，如果小于等于，那么我们可以继续投掷出 $j$，此时连续投掷点数 $j$ 的次数 $x$ 就会加 $1$，因此方案数 $f[i][j][x+1]$ 就会增加 $f[i-1][j][x]$。

最终的答案即为所有 $f[n][j][x]$ 的和。

时间复杂度 $O(n \times k^2 \times M)$，空间复杂度 $O(n \times k \times M)$。其中 $k$ 为点数的取值范围，而 $M$ 为连续掷出某个点数的最大次数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        f = [[[0] * 16 for _ in range(7)] for _ in range(n + 1)]
        for j in range(1, 7):
            f[1][j][1] = 1
        for i in range(2, n + 1):
            for j in range(1, 7):
                for x in range(1, rollMax[j - 1] + 1):
                    for k in range(1, 7):
                        if k != j:
                            f[i][k][1] += f[i - 1][j][x]
                        elif x + 1 <= rollMax[j - 1]:
                            f[i][j][x + 1] += f[i - 1][j][x]
        mod = 10**9 + 7
        ans = 0
        for j in range(1, 7):
            for x in range(1, rollMax[j - 1] + 1):
                ans = (ans + f[n][j][x]) % mod
        return ans
```

#### Java

```java
class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int[][][] f = new int[n + 1][7][16];
        for (int j = 1; j <= 6; ++j) {
            f[1][j][1] = 1;
        }
        final int mod = (int) 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int x = 1; x <= rollMax[j - 1]; ++x) {
                    for (int k = 1; k <= 6; ++k) {
                        if (k != j) {
                            f[i][k][1] = (f[i][k][1] + f[i - 1][j][x]) % mod;
                        } else if (x + 1 <= rollMax[j - 1]) {
                            f[i][j][x + 1] = (f[i][j][x + 1] + f[i - 1][j][x]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= 6; ++j) {
            for (int x = 1; x <= rollMax[j - 1]; ++x) {
                ans = (ans + f[n][j][x]) % mod;
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
    int dieSimulator(int n, vector<int>& rollMax) {
        int f[n + 1][7][16];
        memset(f, 0, sizeof f);
        for (int j = 1; j <= 6; ++j) {
            f[1][j][1] = 1;
        }
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int x = 1; x <= rollMax[j - 1]; ++x) {
                    for (int k = 1; k <= 6; ++k) {
                        if (k != j) {
                            f[i][k][1] = (f[i][k][1] + f[i - 1][j][x]) % mod;
                        } else if (x + 1 <= rollMax[j - 1]) {
                            f[i][j][x + 1] = (f[i][j][x + 1] + f[i - 1][j][x]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= 6; ++j) {
            for (int x = 1; x <= rollMax[j - 1]; ++x) {
                ans = (ans + f[n][j][x]) % mod;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func dieSimulator(n int, rollMax []int) (ans int) {
	f := make([][7][16]int, n+1)
	for j := 1; j <= 6; j++ {
		f[1][j][1] = 1
	}
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		for j := 1; j <= 6; j++ {
			for x := 1; x <= rollMax[j-1]; x++ {
				for k := 1; k <= 6; k++ {
					if k != j {
						f[i][k][1] = (f[i][k][1] + f[i-1][j][x]) % mod
					} else if x+1 <= rollMax[j-1] {
						f[i][j][x+1] = (f[i][j][x+1] + f[i-1][j][x]) % mod
					}
				}
			}
		}
	}
	for j := 1; j <= 6; j++ {
		for x := 1; x <= rollMax[j-1]; x++ {
			ans = (ans + f[n][j][x]) % mod
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1224. 最大相等频率](https://leetcode.cn/problems/maximum-equal-frequency){#1224}

{{< tabs "1224" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        cnt = Counter()
        ccnt = Counter()
        ans = mx = 0
        for i, v in enumerate(nums, 1):
            if v in cnt:
                ccnt[cnt[v]] -= 1
            cnt[v] += 1
            mx = max(mx, cnt[v])
            ccnt[cnt[v]] += 1
            if mx == 1:
                ans = i
            elif ccnt[mx] * mx + ccnt[mx - 1] * (mx - 1) == i and ccnt[mx] == 1:
                ans = i
            elif ccnt[mx] * mx + 1 == i and ccnt[1] == 1:
                ans = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static int[] cnt = new int[100010];
    private static int[] ccnt = new int[100010];

    public int maxEqualFreq(int[] nums) {
        Arrays.fill(cnt, 0);
        Arrays.fill(ccnt, 0);
        int ans = 0;
        int mx = 0;
        for (int i = 1; i <= nums.length; ++i) {
            int v = nums[i - 1];
            if (cnt[v] > 0) {
                --ccnt[cnt[v]];
            }
            ++cnt[v];
            mx = Math.max(mx, cnt[v]);
            ++ccnt[cnt[v]];
            if (mx == 1) {
                ans = i;
            } else if (ccnt[mx] * mx + ccnt[mx - 1] * (mx - 1) == i && ccnt[mx] == 1) {
                ans = i;
            } else if (ccnt[mx] * mx + 1 == i && ccnt[1] == 1) {
                ans = i;
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
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> ccnt;
        int ans = 0, mx = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            int v = nums[i - 1];
            if (cnt[v]) --ccnt[cnt[v]];
            ++cnt[v];
            mx = max(mx, cnt[v]);
            ++ccnt[cnt[v]];
            if (mx == 1)
                ans = i;
            else if (ccnt[mx] * mx + ccnt[mx - 1] * (mx - 1) == i && ccnt[mx] == 1)
                ans = i;
            else if (ccnt[mx] * mx + 1 == i && ccnt[1] == 1)
                ans = i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxEqualFreq(nums []int) int {
	cnt := map[int]int{}
	ccnt := map[int]int{}
	ans, mx := 0, 0
	for i, v := range nums {
		i++
		if cnt[v] > 0 {
			ccnt[cnt[v]]--
		}
		cnt[v]++
		mx = max(mx, cnt[v])
		ccnt[cnt[v]]++
		if mx == 1 {
			ans = i
		} else if ccnt[mx]*mx+ccnt[mx-1]*(mx-1) == i && ccnt[mx] == 1 {
			ans = i
		} else if ccnt[mx]*mx+1 == i && ccnt[1] == 1 {
			ans = i
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxEqualFreq(nums: number[]): number {
    const n = nums.length;
    const map = new Map();
    for (const num of nums) {
        map.set(num, (map.get(num) ?? 0) + 1);
    }

    for (let i = n - 1; i > 0; i--) {
        for (const k of map.keys()) {
            map.set(k, map.get(k) - 1);
            let num = 0;
            for (const v of map.values()) {
                if (v !== 0) {
                    num = v;
                    break;
                }
            }
            let isOk = true;
            let sum = 1;
            for (const v of map.values()) {
                if (v !== 0 && v !== num) {
                    isOk = false;
                    break;
                }
                sum += v;
            }
            if (isOk) {
                return sum;
            }
            map.set(k, map.get(k) + 1);
        }
        map.set(nums[i], map.get(nums[i]) - 1);
    }
    return 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组&nbsp;<code>nums</code>，请你帮忙从该数组中找出能满足下面要求的 <strong>最长</strong> 前缀，并返回该前缀的长度：</p>

<ul>
	<li>从前缀中 <strong>恰好删除一个</strong> 元素后，剩下每个数字的出现次数都相同。</li>
</ul>

<p>如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,1,1,5,3,3,5]
<strong>输出：</strong>7
<strong>解释：</strong>对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，里面每个数字都出现了两次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
<strong>输出：</strong>13
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们用 $cnt$ 记录 $nums$ 中每个元素 $v$ 出现的次数，而 $ccnt$ 记录每个次数出现的次数，元素出现的最大次数用 $mx$ 表示。

遍历 $nums$：

-   若最大次数 $mx=1$，说明当前前缀中每个数字均出现 $1$ 次，删除任意一个后，都满足剩余数字次数相同；
-   若所有数字出现的次数均为 $mx$ 和 $mx-1$，并且只有一个数字的出现次数为 $mx$，那么我们删除出现 $mx$ 次数的一个数字，剩余数字次数均为 $mx-1$，满足条件；
-   若除了一个数字，其它所有数字出现次数均为 $mx$ 次，那么我们删除出现一次的数字，剩余数字次数均为 $mx$，满足条件。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示 $nums$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        cnt = Counter()
        ccnt = Counter()
        ans = mx = 0
        for i, v in enumerate(nums, 1):
            if v in cnt:
                ccnt[cnt[v]] -= 1
            cnt[v] += 1
            mx = max(mx, cnt[v])
            ccnt[cnt[v]] += 1
            if mx == 1:
                ans = i
            elif ccnt[mx] * mx + ccnt[mx - 1] * (mx - 1) == i and ccnt[mx] == 1:
                ans = i
            elif ccnt[mx] * mx + 1 == i and ccnt[1] == 1:
                ans = i
        return ans
```

#### Java

```java
class Solution {
    private static int[] cnt = new int[100010];
    private static int[] ccnt = new int[100010];

    public int maxEqualFreq(int[] nums) {
        Arrays.fill(cnt, 0);
        Arrays.fill(ccnt, 0);
        int ans = 0;
        int mx = 0;
        for (int i = 1; i <= nums.length; ++i) {
            int v = nums[i - 1];
            if (cnt[v] > 0) {
                --ccnt[cnt[v]];
            }
            ++cnt[v];
            mx = Math.max(mx, cnt[v]);
            ++ccnt[cnt[v]];
            if (mx == 1) {
                ans = i;
            } else if (ccnt[mx] * mx + ccnt[mx - 1] * (mx - 1) == i && ccnt[mx] == 1) {
                ans = i;
            } else if (ccnt[mx] * mx + 1 == i && ccnt[1] == 1) {
                ans = i;
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
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> ccnt;
        int ans = 0, mx = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            int v = nums[i - 1];
            if (cnt[v]) --ccnt[cnt[v]];
            ++cnt[v];
            mx = max(mx, cnt[v]);
            ++ccnt[cnt[v]];
            if (mx == 1)
                ans = i;
            else if (ccnt[mx] * mx + ccnt[mx - 1] * (mx - 1) == i && ccnt[mx] == 1)
                ans = i;
            else if (ccnt[mx] * mx + 1 == i && ccnt[1] == 1)
                ans = i;
        }
        return ans;
    }
};
```

#### Go

```go
func maxEqualFreq(nums []int) int {
	cnt := map[int]int{}
	ccnt := map[int]int{}
	ans, mx := 0, 0
	for i, v := range nums {
		i++
		if cnt[v] > 0 {
			ccnt[cnt[v]]--
		}
		cnt[v]++
		mx = max(mx, cnt[v])
		ccnt[cnt[v]]++
		if mx == 1 {
			ans = i
		} else if ccnt[mx]*mx+ccnt[mx-1]*(mx-1) == i && ccnt[mx] == 1 {
			ans = i
		} else if ccnt[mx]*mx+1 == i && ccnt[1] == 1 {
			ans = i
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxEqualFreq(nums: number[]): number {
    const n = nums.length;
    const map = new Map();
    for (const num of nums) {
        map.set(num, (map.get(num) ?? 0) + 1);
    }

    for (let i = n - 1; i > 0; i--) {
        for (const k of map.keys()) {
            map.set(k, map.get(k) - 1);
            let num = 0;
            for (const v of map.values()) {
                if (v !== 0) {
                    num = v;
                    break;
                }
            }
            let isOk = true;
            let sum = 1;
            for (const v of map.values()) {
                if (v !== 0 && v !== num) {
                    isOk = false;
                    break;
                }
                sum += v;
            }
            if (isOk) {
                return sum;
            }
            map.set(k, map.get(k) + 1);
        }
        map.set(nums[i], map.get(nums[i]) - 1);
    }
    return 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1225. 报告系统状态的连续日期 🔒](https://leetcode.cn/problems/report-contiguous-dates){#1225}

{{< tabs "1225" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT fail_date AS dt, 'failed' AS st
        FROM Failed
        WHERE YEAR(fail_date) = 2019
        UNION ALL
        SELECT success_date AS dt, 'succeeded' AS st
        FROM Succeeded
        WHERE YEAR(success_date) = 2019
    )
SELECT
    st AS period_state,
    MIN(dt) AS start_date,
    MAX(dt) AS end_date
FROM
    (
        SELECT
            *,
            SUBDATE(
                dt,
                RANK() OVER (
                    PARTITION BY st
                    ORDER BY dt
                )
            ) AS pt
        FROM T
    ) AS t
GROUP BY 1, pt
ORDER BY 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Failed</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| fail_date    | date    |
+--------------+---------+
该表主键为 fail_date (具有唯一值的列)。
该表包含失败任务的天数.
</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Succeeded</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| success_date | date    |
+--------------+---------+
该表主键为 success_date (具有唯一值的列)。
该表包含成功任务的天数.
</pre>

<p>&nbsp;</p>

<p>系统 <strong>每天</strong> 运行一个任务。每个任务都独立于先前的任务。任务的状态可以是失败或是成功。</p>

<p>编写解决方案找出&nbsp;<strong>2019-01-01</strong>&nbsp;到&nbsp;<strong>2019-12-31</strong> 期间任务连续同状态&nbsp;<code>period_state</code>&nbsp;的起止日期（<code>start_date</code> 和 <code>end_date</code>）。即如果任务失败了，就是失败状态的起止日期，如果任务成功了，就是成功状态的起止日期。</p>

<p>最后结果按照起始日期&nbsp;<code>start_date</code>&nbsp;排序</p>

<p>返回结果样例如下所示:</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Failed table:
+-------------------+
| fail_date         |
+-------------------+
| 2018-12-28        |
| 2018-12-29        |
| 2019-01-04        |
| 2019-01-05        |
+-------------------+
Succeeded table:
+-------------------+
| success_date      |
+-------------------+
| 2018-12-30        |
| 2018-12-31        |
| 2019-01-01        |
| 2019-01-02        |
| 2019-01-03        |
| 2019-01-06        |
+-------------------+
<strong>输出：</strong>
+--------------+--------------+--------------+
| period_state | start_date   | end_date     |
+--------------+--------------+--------------+
| succeeded    | 2019-01-01   | 2019-01-03   |
| failed       | 2019-01-04   | 2019-01-05   |
| succeeded    | 2019-01-06   | 2019-01-06   |
+--------------+--------------+--------------+
<strong>解释：</strong>
结果忽略了 2018 年的记录，因为我们只关心从 2019-01-01 到 2019-12-31 的记录
从 2019-01-01 到 2019-01-03 所有任务成功，系统状态为 "succeeded"。
从 2019-01-04 到 2019-01-05 所有任务失败，系统状态为 "failed"。
从 2019-01-06 到 2019-01-06 所有任务成功，系统状态为 "succeeded"。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并 + 窗口函数 + 分组求最大最小值

我们可以将两个表合并，用一个字段 $st$ 表示状态，其中 `failed` 表示失败，`succeeded` 表示成功。然后我们可以使用窗口函数，将相同状态的记录分到一组，求出每个日期与其所在组排名的差值 $pt$，作为同一个连续状态的标识。最后我们可以按照 $st$ 和 $pt$ 分组，求出每组的最小日期和最大日期，然后按照最小日期排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT fail_date AS dt, 'failed' AS st
        FROM Failed
        WHERE YEAR(fail_date) = 2019
        UNION ALL
        SELECT success_date AS dt, 'succeeded' AS st
        FROM Succeeded
        WHERE YEAR(success_date) = 2019
    )
SELECT
    st AS period_state,
    MIN(dt) AS start_date,
    MAX(dt) AS end_date
FROM
    (
        SELECT
            *,
            SUBDATE(
                dt,
                RANK() OVER (
                    PARTITION BY st
                    ORDER BY dt
                )
            ) AS pt
        FROM T
    ) AS t
GROUP BY 1, pt
ORDER BY 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1226. 哲学家进餐](https://leetcode.cn/problems/the-dining-philosophers){#1226}

{{< tabs "1226" >}}

{{% tab "cpp" %}}
```cpp
class DiningPhilosophers {
public:
    using Act = function<void()>;

    void wantsToEat(int philosopher, Act pickLeftFork, Act pickRightFork, Act eat, Act putLeftFork, Act putRightFork) {
        /* 这一题实际上是用到了C++17中的scoped_lock知识。
                   作用是传入scoped_lock(mtx1, mtx2)两个锁，然后在作用范围内，依次顺序上锁mtx1和mtx2；然后在作用范围结束时，再反续解锁mtx2和mtx1。
                   从而保证了philosopher1有动作的时候，philosopher2无法操作；但是philosopher3和philosopher4不受影响 */
        std::scoped_lock lock(mutexes_[philosopher], mutexes_[philosopher >= 4 ? 0 : philosopher + 1]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

private:
    vector<mutex> mutexes_ = vector<mutex>(5);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>5 个沉默寡言的哲学家围坐在圆桌前，每人面前一盘意面。叉子放在哲学家之间的桌面上。（5 个哲学家，5 根叉子）</p>

<p>所有的哲学家都只会在思考和进餐两种行为间交替。哲学家只有同时拿到左边和右边的叉子才能吃到面，而同一根叉子在同一时间只能被一个哲学家使用。每个哲学家吃完面后都需要把叉子放回桌面以供其他哲学家吃面。只要条件允许，哲学家可以拿起左边或者右边的叉子，但在没有同时拿到左右叉子时不能进食。</p>

<p>假设面的数量没有限制，哲学家也能随便吃，不需要考虑吃不吃得下。</p>

<p>设计一个进餐规则（并行算法）使得每个哲学家都不会挨饿；也就是说，在没有人知道别人什么时候想吃东西或思考的情况下，每个哲学家都可以在吃饭和思考之间一直交替下去。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1226.The%20Dining%20Philosophers/images/an_illustration_of_the_dining_philosophers_problem.png" style="height: 415px; width: 400px;"></p>

<p><em>问题描述和图片来自维基百科&nbsp;<a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem" target="_blank">wikipedia.org</a></em></p>

<p>&nbsp;</p>

<p>哲学家从&nbsp;<strong>0</strong> 到 <strong>4</strong> 按 <strong>顺时针</strong> 编号。请实现函数&nbsp;<code>void wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork)</code>：</p>

<ul>
	<li><code>philosopher</code>&nbsp;哲学家的编号。</li>
	<li><code>pickLeftFork</code>&nbsp;和&nbsp;<code>pickRightFork</code>&nbsp;表示拿起左边或右边的叉子。</li>
	<li><code>eat</code>&nbsp;表示吃面。</li>
	<li><code>putLeftFork</code>&nbsp;和&nbsp;<code>putRightFork</code>&nbsp;表示放下左边或右边的叉子。</li>
	<li>由于哲学家不是在吃面就是在想着啥时候吃面，所以思考这个方法没有对应的回调。</li>
</ul>

<p>给你 5 个线程，每个都代表一个哲学家，请你使用类的同一个对象来模拟这个过程。在最后一次调用结束之前，可能会为同一个哲学家多次调用该函数。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>[[4,2,1],[4,1,1],[0,1,1],[2,2,1],[2,1,1],[2,0,3],[2,1,2],[2,2,2],[4,0,3],[4,1,2],[0,2,1],[4,2,2],[3,2,1],[3,1,1],[0,0,3],[0,1,2],[0,2,2],[1,2,1],[1,1,1],[3,0,3],[3,1,2],[3,2,2],[1,0,3],[1,1,2],[1,2,2]]
<strong>解释:</strong>
n 表示每个哲学家需要进餐的次数。
输出数组描述了叉子的控制和进餐的调用，它的格式如下：
output[i] = [a, b, c] (3个整数)
- a 哲学家编号。
- b 指定叉子：{1 : 左边, 2 : 右边}.
- c 指定行为：{1 : 拿起, 2 : 放下, 3 : 吃面}。
如 [4,2,1] 表示 4 号哲学家拿起了右边的叉子。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 60</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### C++

```cpp
class DiningPhilosophers {
public:
    using Act = function<void()>;

    void wantsToEat(int philosopher, Act pickLeftFork, Act pickRightFork, Act eat, Act putLeftFork, Act putRightFork) {
        /* 这一题实际上是用到了C++17中的scoped_lock知识。
                   作用是传入scoped_lock(mtx1, mtx2)两个锁，然后在作用范围内，依次顺序上锁mtx1和mtx2；然后在作用范围结束时，再反续解锁mtx2和mtx1。
                   从而保证了philosopher1有动作的时候，philosopher2无法操作；但是philosopher3和philosopher4不受影响 */
        std::scoped_lock lock(mutexes_[philosopher], mutexes_[philosopher >= 4 ? 0 : philosopher + 1]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

private:
    vector<mutex> mutexes_ = vector<mutex>(5);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1227. 飞机座位分配概率](https://leetcode.cn/problems/airplane-seat-assignment-probability){#1227}

{{< tabs "1227" >}}

{{% tab "python" %}}
```python
class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        return 1 if n == 1 else 0.5
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : .5;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : .5;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nthPersonGetsNthSeat(n int) float64 {
	if n == 1 {
		return 1
	}
	return .5
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nthPersonGetsNthSeat(n: number): number {
    return n === 1 ? 1 : 0.5;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn nth_person_gets_nth_seat(n: i32) -> f64 {
        return if n == 1 { 1.0 } else { 0.5 };
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 位乘客即将登机，飞机正好有 <code>n</code> 个座位。第一位乘客的票丢了，他随便选了一个座位坐下。</p>

<p>剩下的乘客将会：</p>

<ul>
	<li>
	<p>如果他们自己的座位还空着，就坐到自己的座位上，</p>
	</li>
	<li>当他们自己的座位被占用时，随机选择其他座位</li>
</ul>

<p>第 <code>n</code>&nbsp;位乘客坐在自己的座位上的概率是多少？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1.00000
<strong>解释：</strong>第一个人只会坐在自己的位置上。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> 0.50000
<strong>解释：</strong>在第一个人选好座位坐下后，第二个人坐在自己的座位上的概率是 0.5。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

用 $f(n)$ 表示当有 $n$ 位乘客登机时，第 $n$ 位乘客坐在自己的座位上的概率。从最简单的情况开始考虑：

当 $n=1$ 时，只有 $1$ 位乘客和 $1$ 个座位，因此第 $1$ 位乘客只能坐在第 $1$ 个座位上，$f(1)=1$；

当 $n=2$ 时，有 $2$ 个座位，每个座位有 $0.5$ 的概率被第 $1$ 位乘客选中，当第 $1$ 位乘客选中座位之后，第 $2$ 位乘客只能选择剩下的座位，因此第 $2$ 位乘客有 $0.5$ 的概率坐在自己的座位上，$f(2)=0.5$。

当 $n>2$ 时，如何计算 $f(n)$ 的值？考虑第 $1$ 位乘客选择的座位，有以下三种情况。

-   第 $1$ 位乘客有 $\frac{1}{n}$ 的概率选择第 $1$ 个座位，则所有乘客都可以坐在自己的座位上，此时第 $n$ 位乘客坐在自己的座位上的概率是 $1.0$。

-   第 $1$ 位乘客有 $\frac{1}{n}$ 的概率选择第 $n$ 个座位，则第 $2$ 位乘客到第 $n-1$ 位乘客都可以坐在自己的座位上，第 $n$ 位乘客只能坐在第 $1$ 个座位上，此时第 $n$ 位乘客坐在自己的座位上的概率是 $0.0$。

-   第 $1$ 位乘客有 $\frac{n-2}{n}$ 的概率选择其余的座位，每个座位被选中的概率是 $\frac{1}{n}$。
    假设第 $1$ 位乘客选择第 $i$ 个座位，其中 $2 \le i \le n-1$，则第 $2$ 位乘客到第 $i-1$ 位乘客都可以坐在自己的座位上，第 $i$ 位乘客到第 $n$ 位乘客的座位不确定，第 $i$ 位乘客会在剩下的 $n-(i-1)=n-i+1$ 个座位中随机选择（包括第 $1$ 个座位和第 $i+1$ 个座位到第 $n$ 个座位）。由于此时剩下的乘客数和座位数都是 $n-i+1$，有 $1$ 位乘客会随机选择座位，因此问题规模从 $n$ 减小至 $n-i+1$。

结合上述三种情况，可以得到 $f(n)$ 的递推式：

$$
\begin{aligned}
f(n) &= \frac{1}{n} \times 1.0 + \frac{1}{n} \times 0.0 + \frac{1}{n} \times \sum_{i=2}^{n-1} f(n-i+1) \\
&= \frac{1}{n}(1.0+\sum_{i=2}^{n-1} f(n-i+1))
\end{aligned}
$$

上述递推式中，$i$ 的取值个数有 $n-2$ 个，由于 $i$ 的取值个数必须是非负整数，因此只有当 $n-2 \ge 0$ 即 $n \ge 2$ 时，上述递推式才成立。

如果直接利用上述递推式计算 $f(n)$ 的值，则时间复杂度为 $O(n^2)$，无法通过全部测试用例，因此需要优化。

将上述递推式中的 $n$ 换成 $n-1$，可以得到递推式：

$$
f(n-1) = \frac{1}{n-1}(1.0+\sum_{i=2}^{n-2} f(n-i))
$$

上述递推式中，$i$ 的取值个数有 $n-3$ 个，只有当 $n-3 \ge 0$ 即 $n \ge 3$ 时，上述递推式才成立。

当 $n \ge 3$ 时，上述两个递推式可以写成如下形式：

$$
\begin{aligned}
n \times f(n) &= 1.0+\sum_{i=2}^{n-1} f(n-i+1) \\
(n-1) \times f(n-1) &= 1.0+\sum_{i=2}^{n-2} f(n-i)
\end{aligned}
$$

将上述两式相减：

$$
\begin{aligned}
&~~~~~ n \times f(n) - (n-1) \times f(n-1) \\
&= (1.0+\sum_{i=2}^{n-1} f(n-i+1)) - (1.0+\sum_{i=2}^{n-2} f(n-i)) \\
&= \sum_{i=2}^{n-1} f(n-i+1) - \sum_{i=2}^{n-2} f(n-i) \\
&= f(2)+f(3)+...+f(n-1) - (f(2)+f(3)+...+f(n-2)) \\
&= f(n-1)
\end{aligned}
$$

整理后得到简化的递推式：

$$
\begin{aligned}
n \times f(n) &= n \times f(n-1) \\
f(n) &= f(n-1)
\end{aligned}
$$

由于已知 $f(1)=1$ 和 $f(2)=0.5$，因此当 $n \ge 3$ 时，根据 $f(n) = f(n-1)$ 可知，对任意正整数 $n$ 都有 $f(n)=0.5$。又由于 $f(2)=0.5$，因此当 $n \ge 2$ 时，对任意正整数 $n$ 都有 $f(n)=0.5$。

由此可以得到 $f(n)$ 的结果：

$$
f(n) = \begin{cases}
1.0, & n = 1 \\
0.5, & n \ge 2
\end{cases}
$$

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        return 1 if n == 1 else 0.5
```

#### Java

```java
class Solution {
    public double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : .5;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : .5;
    }
};
```

#### Go

```go
func nthPersonGetsNthSeat(n int) float64 {
	if n == 1 {
		return 1
	}
	return .5
}
```

#### TypeScript

```ts
function nthPersonGetsNthSeat(n: number): number {
    return n === 1 ? 1 : 0.5;
}
```

#### Rust

```rust
impl Solution {
    pub fn nth_person_gets_nth_seat(n: i32) -> f64 {
        return if n == 1 { 1.0 } else { 0.5 };
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1228. 等差数列中缺失的数字 🔒](https://leetcode.cn/problems/missing-number-in-arithmetic-progression){#1228}

{{< tabs "1228" >}}

{{% tab "python" %}}
```python
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        n = len(arr)
        d = (arr[-1] - arr[0]) // n
        for i in range(1, n):
            if arr[i] != arr[i - 1] + d:
                return arr[i - 1] + d
        return arr[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int d = (arr[n - 1] - arr[0]) / n;
        for (int i = 1; i < n; ++i) {
            if (arr[i] != arr[i - 1] + d) {
                return arr[i - 1] + d;
            }
        }
        return arr[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int d = (arr[n - 1] - arr[0]) / n;
        for (int i = 1; i < n; ++i) {
            if (arr[i] != arr[i - 1] + d) {
                return arr[i - 1] + d;
            }
        }
        return arr[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func missingNumber(arr []int) int {
	n := len(arr)
	d := (arr[n-1] - arr[0]) / n
	for i := 1; i < n; i++ {
		if arr[i] != arr[i-1]+d {
			return arr[i-1] + d
		}
	}
	return arr[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function missingNumber(arr: number[]): number {
    const d = ((arr.at(-1)! - arr[0]) / arr.length) | 0;
    for (let i = 1; i < arr.length; ++i) {
        if (arr[i] - arr[i - 1] !== d) {
            return arr[i - 1] + d;
        }
    }
    return arr[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在某个数组&nbsp;<code>arr</code>&nbsp;中，值符合等差数列的数值规律：在&nbsp;<code>0 &lt;= i &lt; arr.length - 1</code>&nbsp;的前提下，<code>arr[i+1] - arr[i]</code>&nbsp;的值都相等。</p>

<p>我们会从该数组中删除一个 <strong>既不是第一个 </strong>也<strong>&nbsp;不是最后一个的值</strong>，得到一个新的数组&nbsp;&nbsp;<code>arr</code>。</p>

<p>给你这个缺值的数组&nbsp;<code>arr</code>，返回 <em>被删除的那个数</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [5,7,11,13]
<strong>输出：</strong>9
<strong>解释：</strong>原来的数组是 [5,7,<strong>9</strong>,11,13]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [15,13,12]
<strong>输出：</strong>14
<strong>解释：</strong>原来的数组是 [15,<strong>14</strong>,13,12]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
	<li>给定的数组 <strong>保证</strong> 是一个有效的数组。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等差数列求和公式

等差数列求和公式为 $\frac{(a_1 + a_n)n}{2}$，其中 $n$ 为等差数列的项数，等差数列的首项为 $a_1$，末项为 $a_n$。

因为题目中给出的数组是一个等差数列，且缺失了一个数，所以数组的项数为 $n + 1$，首项为 $a_1$，末项为 $a_n$，则数组的和为 $\frac{(a_1 + a_n)(n + 1)}{2}$。

因此，缺失的数为 $\frac{(a_1 + a_n)(n + 1)}{2} - \sum_{i = 0}^n a_i$。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        return (arr[0] + arr[-1]) * (len(arr) + 1) // 2 - sum(arr)
```

#### Java

```java
class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int x = (arr[0] + arr[n - 1]) * (n + 1) / 2;
        int y = Arrays.stream(arr).sum();
        return x - y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int x = (arr[0] + arr[n - 1]) * (n + 1) / 2;
        int y = accumulate(arr.begin(), arr.end(), 0);
        return x - y;
    }
};
```

#### Go

```go
func missingNumber(arr []int) int {
	n := len(arr)
	x := (arr[0] + arr[n-1]) * (n + 1) / 2
	y := 0
	for _, v := range arr {
		y += v
	}
	return x - y
}
```

#### TypeScript

```ts
function missingNumber(arr: number[]): number {
    const x = ((arr[0] + arr.at(-1)!) * (arr.length + 1)) >> 1;
    const y = arr.reduce((acc, cur) => acc + cur, 0);
    return x - y;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：求公差 + 遍历

因为题目中给出的数组是一个等差数列，且缺失了一个数，首项为 $a_1$，末项为 $a_n$，那么公差 $d = \frac{a_n - a_1}{n}$。

遍历数组，如果 $a_i \neq a_{i - 1} + d$，则返回 $a_{i - 1} + d$。

如果遍历完数组都没有找到缺失的数，说明数组的所有数都相等，直接返回数组的第一个数即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        n = len(arr)
        d = (arr[-1] - arr[0]) // n
        for i in range(1, n):
            if arr[i] != arr[i - 1] + d:
                return arr[i - 1] + d
        return arr[0]
```

#### Java

```java
class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int d = (arr[n - 1] - arr[0]) / n;
        for (int i = 1; i < n; ++i) {
            if (arr[i] != arr[i - 1] + d) {
                return arr[i - 1] + d;
            }
        }
        return arr[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int d = (arr[n - 1] - arr[0]) / n;
        for (int i = 1; i < n; ++i) {
            if (arr[i] != arr[i - 1] + d) {
                return arr[i - 1] + d;
            }
        }
        return arr[0];
    }
};
```

#### Go

```go
func missingNumber(arr []int) int {
	n := len(arr)
	d := (arr[n-1] - arr[0]) / n
	for i := 1; i < n; i++ {
		if arr[i] != arr[i-1]+d {
			return arr[i-1] + d
		}
	}
	return arr[0]
}
```

#### TypeScript

```ts
function missingNumber(arr: number[]): number {
    const d = ((arr.at(-1)! - arr[0]) / arr.length) | 0;
    for (let i = 1; i < arr.length; ++i) {
        if (arr[i] - arr[i - 1] !== d) {
            return arr[i - 1] + d;
        }
    }
    return arr[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1229. 安排会议日程 🔒](https://leetcode.cn/problems/meeting-scheduler){#1229}

{{< tabs "1229" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAvailableDuration(
        self, slots1: List[List[int]], slots2: List[List[int]], duration: int
    ) -> List[int]:
        slots1.sort()
        slots2.sort()
        m, n = len(slots1), len(slots2)
        i = j = 0
        while i < m and j < n:
            start = max(slots1[i][0], slots2[j][0])
            end = min(slots1[i][1], slots2[j][1])
            if end - start >= duration:
                return [start, start + duration]
            if slots1[i][1] < slots2[j][1]:
                i += 1
            else:
                j += 1
        return []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        Arrays.sort(slots1, (a, b) -> a[0] - b[0]);
        Arrays.sort(slots2, (a, b) -> a[0] - b[0]);
        int m = slots1.length, n = slots2.length;
        int i = 0, j = 0;
        while (i < m && j < n) {
            int start = Math.max(slots1[i][0], slots2[j][0]);
            int end = Math.min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) {
                return Arrays.asList(start, start + duration);
            }
            if (slots1[i][1] < slots2[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return Collections.emptyList();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int m = slots1.size(), n = slots2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) {
                return {start, start + duration};
            }
            if (slots1[i][1] < slots2[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return {};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAvailableDuration(slots1 [][]int, slots2 [][]int, duration int) []int {
	sort.Slice(slots1, func(i, j int) bool { return slots1[i][0] < slots1[j][0] })
	sort.Slice(slots2, func(i, j int) bool { return slots2[i][0] < slots2[j][0] })
	i, j, m, n := 0, 0, len(slots1), len(slots2)
	for i < m && j < n {
		start := max(slots1[i][0], slots2[j][0])
		end := min(slots1[i][1], slots2[j][1])
		if end-start >= duration {
			return []int{start, start + duration}
		}
		if slots1[i][1] < slots2[j][1] {
			i++
		} else {
			j++
		}
	}
	return []int{}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minAvailableDuration(slots1: number[][], slots2: number[][], duration: number): number[] {
    slots1.sort((a, b) => a[0] - b[0]);
    slots2.sort((a, b) => a[0] - b[0]);
    const [m, n] = [slots1.length, slots2.length];
    let [i, j] = [0, 0];
    while (i < m && j < n) {
        const [start1, end1] = slots1[i];
        const [start2, end2] = slots2[j];
        const start = Math.max(start1, start2);
        const end = Math.min(end1, end2);
        if (end - start >= duration) {
            return [start, start + duration];
        }
        if (end1 < end2) {
            i++;
        } else {
            j++;
        }
    }
    return [];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_available_duration(mut slots1: Vec<Vec<i32>>, mut slots2: Vec<Vec<i32>>, duration: i32) -> Vec<i32> {
        slots1.sort_by_key(|slot| slot[0]);
        slots2.sort_by_key(|slot| slot[0]);

        let (mut i, mut j) = (0, 0);
        let (m, n) = (slots1.len(), slots2.len());

        while i < m && j < n {
            let (start1, end1) = (slots1[i][0], slots1[i][1]);
            let (start2, end2) = (slots2[j][0], slots2[j][1]);

            let start = start1.max(start2);
            let end = end1.min(end2);

            if end - start >= duration {
                return vec![start, start + duration];
            }

            if end1 < end2 {
                i += 1;
            } else {
                j += 1;
            }
        }

        vec![]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个人的空闲时间表：<code>slots1</code> 和 <code>slots2</code>，以及会议的预计持续时间&nbsp;<code>duration</code>，请你为他们安排&nbsp;<strong>时间段最早&nbsp;且</strong>合适的会议时间。</p>

<p>如果没有满足要求的会议时间，就请返回一个 <strong>空数组</strong>。</p>

<p>「空闲时间」的格式是&nbsp;<code>[start, end]</code>，由开始时间&nbsp;<code>start</code>&nbsp;和结束时间&nbsp;<code>end</code>&nbsp;组成，表示从&nbsp;<code>start</code>&nbsp;开始，到 <code>end</code>&nbsp;结束。&nbsp;</p>

<p>题目保证数据有效：同一个人的空闲时间不会出现交叠的情况，也就是说，对于同一个人的两个空闲时间&nbsp;<code>[start1, end1]</code>&nbsp;和&nbsp;<code>[start2, end2]</code>，要么&nbsp;<code>start1 &gt; end2</code>，要么&nbsp;<code>start2 &gt; end1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
<strong>输出：</strong>[60,68]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= slots1.length, slots2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>slots1[i].length, slots2[i].length == 2</code></li>
	<li><code>slots1[i][0] &lt; slots1[i][1]</code></li>
	<li><code>slots2[i][0] &lt; slots2[i][1]</code></li>
	<li><code>0 &lt;= slots1[i][j], slots2[i][j] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= duration &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们可以将两个人的空闲时间分别排序，然后使用双指针遍历两个数组，找到两个人的空闲时间段的交集，如果交集的长度大于等于 `duration`，则返回交集的起始时间和起始时间加上 `duration`。否则，如果第一个人的空闲时间段的结束时间小于第二个人的空闲时间段的结束时间，我们就移动第一个人的指针，否则移动第二个人的指针。继续遍历，直到找到满足条件的时间段或者遍历结束。

时间复杂度 $O(m \times \log m + n \times \log n)$，空间复杂度 $O(\log m + \log n)$。其中 $m$ 和 $n$ 分别为两个数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAvailableDuration(
        self, slots1: List[List[int]], slots2: List[List[int]], duration: int
    ) -> List[int]:
        slots1.sort()
        slots2.sort()
        m, n = len(slots1), len(slots2)
        i = j = 0
        while i < m and j < n:
            start = max(slots1[i][0], slots2[j][0])
            end = min(slots1[i][1], slots2[j][1])
            if end - start >= duration:
                return [start, start + duration]
            if slots1[i][1] < slots2[j][1]:
                i += 1
            else:
                j += 1
        return []
```

#### Java

```java
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        Arrays.sort(slots1, (a, b) -> a[0] - b[0]);
        Arrays.sort(slots2, (a, b) -> a[0] - b[0]);
        int m = slots1.length, n = slots2.length;
        int i = 0, j = 0;
        while (i < m && j < n) {
            int start = Math.max(slots1[i][0], slots2[j][0]);
            int end = Math.min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) {
                return Arrays.asList(start, start + duration);
            }
            if (slots1[i][1] < slots2[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return Collections.emptyList();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int m = slots1.size(), n = slots2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) {
                return {start, start + duration};
            }
            if (slots1[i][1] < slots2[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return {};
    }
};
```

#### Go

```go
func minAvailableDuration(slots1 [][]int, slots2 [][]int, duration int) []int {
	sort.Slice(slots1, func(i, j int) bool { return slots1[i][0] < slots1[j][0] })
	sort.Slice(slots2, func(i, j int) bool { return slots2[i][0] < slots2[j][0] })
	i, j, m, n := 0, 0, len(slots1), len(slots2)
	for i < m && j < n {
		start := max(slots1[i][0], slots2[j][0])
		end := min(slots1[i][1], slots2[j][1])
		if end-start >= duration {
			return []int{start, start + duration}
		}
		if slots1[i][1] < slots2[j][1] {
			i++
		} else {
			j++
		}
	}
	return []int{}
}
```

#### TypeScript

```ts
function minAvailableDuration(slots1: number[][], slots2: number[][], duration: number): number[] {
    slots1.sort((a, b) => a[0] - b[0]);
    slots2.sort((a, b) => a[0] - b[0]);
    const [m, n] = [slots1.length, slots2.length];
    let [i, j] = [0, 0];
    while (i < m && j < n) {
        const [start1, end1] = slots1[i];
        const [start2, end2] = slots2[j];
        const start = Math.max(start1, start2);
        const end = Math.min(end1, end2);
        if (end - start >= duration) {
            return [start, start + duration];
        }
        if (end1 < end2) {
            i++;
        } else {
            j++;
        }
    }
    return [];
}
```

#### Rust

```rust
impl Solution {
    pub fn min_available_duration(mut slots1: Vec<Vec<i32>>, mut slots2: Vec<Vec<i32>>, duration: i32) -> Vec<i32> {
        slots1.sort_by_key(|slot| slot[0]);
        slots2.sort_by_key(|slot| slot[0]);

        let (mut i, mut j) = (0, 0);
        let (m, n) = (slots1.len(), slots2.len());

        while i < m && j < n {
            let (start1, end1) = (slots1[i][0], slots1[i][1]);
            let (start2, end2) = (slots2[j][0], slots2[j][1]);

            let start = start1.max(start2);
            let end = end1.min(end2);

            if end - start >= duration {
                return vec![start, start + duration];
            }

            if end1 < end2 {
                i += 1;
            } else {
                j += 1;
            }
        }

        vec![]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
