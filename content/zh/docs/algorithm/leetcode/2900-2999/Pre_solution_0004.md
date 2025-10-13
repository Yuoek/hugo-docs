---
title: "2930_重新排列后包含指定子字符串的字符串数目"
date: 2025-10-08T18:39:48+08:00
weight: 4
tags: [二分查找, 交互, 位运算, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字典树, 字符串, 排序, 数学, 数组, 枚举, 滑动窗口, 矩阵, 组合数学, 贪心]
---

{{< markmap >}}
### [2930_重新排列后包含指定子字符串的字符串数目](#2930)
#### [数学](#2930)
#### [动态规划](#2930)
#### [组合数学](#2930)
### [2931_购买物品的最大开销](#2931)
#### [贪心](#2931)
#### [数组](#2931)
#### [矩阵](#2931)
#### [排序](#2931)
#### [堆（优先队列）](#2931)
### [2932_找出强数对的最大异或值 I](#2932)
#### [位运算](#2932)
#### [字典树](#2932)
#### [数组](#2932)
#### [哈希表](#2932)
#### [滑动窗口](#2932)
### [2933_高访问员工](#2933)
#### [数组](#2933)
#### [哈希表](#2933)
#### [字符串](#2933)
#### [排序](#2933)
### [2934_最大化数组末位元素的最少操作次数](#2934)
#### [数组](#2934)
#### [枚举](#2934)
### [2935_找出强数对的最大异或值 II](#2935)
#### [位运算](#2935)
#### [字典树](#2935)
#### [数组](#2935)
#### [哈希表](#2935)
#### [滑动窗口](#2935)
### [2936_包含相等值数字块的数量 🔒](#2936)
#### [数组](#2936)
#### [二分查找](#2936)
#### [交互](#2936)
### [2937_使三个字符串相等](#2937)
#### [字符串](#2937)
### [2938_区分黑球与白球](#2938)
#### [贪心](#2938)
#### [双指针](#2938)
#### [字符串](#2938)
### [2939_最大异或乘积](#2939)
#### [贪心](#2939)
#### [位运算](#2939)
#### [数学](#2939)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2930_重新排列后包含指定子字符串的字符串数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 2931_购买物品的最大开销
___
#### 贪心
___
#### 数组
___
#### 矩阵
___
#### 排序
___
#### 堆（优先队列）
---
### 2932_找出强数对的最大异或值 I
___
#### 位运算
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2933_高访问员工
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 2934_最大化数组末位元素的最少操作次数
___
#### 数组
___
#### 枚举
---
### 2935_找出强数对的最大异或值 II
___
#### 位运算
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2936_包含相等值数字块的数量 🔒
___
#### 数组
___
#### 二分查找
___
#### 交互
---
### 2937_使三个字符串相等
___
#### 字符串
---
### 2938_区分黑球与白球
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 2939_最大异或乘积
___
#### 贪心
___
#### 位运算
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 位运算 |
| 动态规划 | 双指针 | 哈希表 |
| 堆（优先队列） | 字典树 | 字符串 |
| 排序 | 数学 | 数组 |
| 枚举 | 滑动窗口 | 矩阵 |
| 组合数学 | 贪心 |  |

# [2930. 重新排列后包含指定子字符串的字符串数目](https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring){#2930}

{{< tabs "2930" >}}

{{% tab "python" %}}
```python
class Solution:
    def stringCount(self, n: int) -> int:
        mod = 10**9 + 7
        a = b = pow(25, n, mod)
        c = pow(25, n, mod) + n * pow(25, n - 1, mod)
        ab = pow(24, n, mod)
        ac = bc = (pow(24, n, mod) + n * pow(24, n - 1, mod)) % mod
        abc = (pow(23, n, mod) + n * pow(23, n - 1, mod)) % mod
        tot = pow(26, n, mod)
        return (tot - (a + b + c - ab - ac - bc + abc)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int stringCount(int n) {
        long a = qpow(25, n);
        long b = a;
        long c = (qpow(25, n) + n * qpow(25, n - 1) % mod) % mod;
        long ab = qpow(24, n);
        long ac = (qpow(24, n) + n * qpow(24, n - 1) % mod) % mod;
        long bc = ac;
        long abc = (qpow(23, n) + n * qpow(23, n - 1) % mod) % mod;
        long tot = qpow(26, n);
        return (int) ((tot - (a + b + c - ab - ac - bc + abc)) % mod + mod) % mod;
    }

    private long qpow(long a, int n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
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
    int stringCount(int n) {
        const int mod = 1e9 + 7;
        using ll = long long;
        auto qpow = [&](ll a, int n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        ll a = qpow(25, n);
        ll b = a;
        ll c = (qpow(25, n) + n * qpow(25, n - 1) % mod) % mod;
        ll ab = qpow(24, n);
        ll ac = (qpow(24, n) + n * qpow(24, n - 1) % mod) % mod;
        ll bc = ac;
        ll abc = (qpow(23, n) + n * qpow(23, n - 1) % mod) % mod;
        ll tot = qpow(26, n);
        return ((tot - (a + b + c - ab - ac - bc + abc)) % mod + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stringCount(n int) int {
	const mod int = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	a := qpow(25, n)
	b := a
	c := qpow(25, n) + n*qpow(25, n-1)
	ab := qpow(24, n)
	ac := (qpow(24, n) + n*qpow(24, n-1)) % mod
	bc := ac
	abc := (qpow(23, n) + n*qpow(23, n-1)) % mod
	tot := qpow(26, n)
	return ((tot-(a+b+c-ab-ac-bc+abc))%mod + mod) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stringCount(n: number): number {
    const mod = BigInt(10 ** 9 + 7);
    const qpow = (a: bigint, n: number): bigint => {
        let ans = 1n;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
        }
        return ans;
    };
    const a = qpow(25n, n);
    const b = a;
    const c = (qpow(25n, n) + ((BigInt(n) * qpow(25n, n - 1)) % mod)) % mod;
    const ab = qpow(24n, n);
    const ac = (qpow(24n, n) + ((BigInt(n) * qpow(24n, n - 1)) % mod)) % mod;
    const bc = ac;
    const abc = (qpow(23n, n) + ((BigInt(n) * qpow(23n, n - 1)) % mod)) % mod;
    const tot = qpow(26n, n);
    return Number((((tot - (a + b + c - ab - ac - bc + abc)) % mod) + mod) % mod);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;。</p>

<p>如果一个字符串&nbsp;<code>s</code>&nbsp;只包含小写英文字母，<strong>且</strong>&nbsp;将 <code>s</code>&nbsp;的字符重新排列后，新字符串包含&nbsp;<strong>子字符串</strong>&nbsp;<code>"leet"</code> ，那么我们称字符串 <code>s</code>&nbsp;是一个 <strong>好</strong>&nbsp;字符串。</p>

<p>比方说：</p>

<ul>
	<li>字符串&nbsp;<code>"lteer"</code>&nbsp;是好字符串，因为重新排列后可以得到&nbsp;<code>"leetr"</code>&nbsp;。</li>
	<li><code>"letl"</code>&nbsp;不是好字符串，因为无法重新排列并得到子字符串&nbsp;<code>"leet"</code>&nbsp;。</li>
</ul>

<p>请你返回长度为 <code>n</code>&nbsp;的好字符串 <strong>总</strong>&nbsp;数目。</p>

<p>由于答案可能很大，将答案对<strong>&nbsp;</strong><code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p><strong>子字符串</strong>&nbsp;是一个字符串中一段连续的字符序列。</p>

<div class="notranslate" style="all: initial;">&nbsp;</div>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 4
<b>输出：</b>12
<b>解释：</b>总共有 12 个字符串重新排列后包含子字符串 "leet" ："eelt" ，"eetl" ，"elet" ，"elte" ，"etel" ，"etle" ，"leet" ，"lete" ，"ltee" ，"teel" ，"tele" 和 "tlee" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 10
<b>输出：</b>83943898
<b>解释：</b>长度为 10 的字符串重新排列后包含子字符串 "leet" 的方案数为 526083947580 。所以答案为 526083947580 % (10<sup>9</sup> + 7) = 83943898 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, l, e, t)$，表示当前剩余字符串长度为 $i$，且已至少有 $l$ 个字符 `'l'`, $e$ 个字符 `'e'` 和 $t$ 个字符 `'t'`，构成的字符串是一个好字符串的方案数。那么答案为 $dfs(n, 0, 0, 0)$。

函数 $dfs(i, l, e, t)$ 的执行逻辑如下：

如果 $i = 0$，说明当前字符串已经构造完毕，如果 $l = 1$, $e = 2$ 且 $t = 1$，说明当前字符串是一个好字符串，返回 $1$，否则返回 $0$。

否则，我们可以考虑在当前位置添加除 `'l'`, `'e'`, `'t'` 以外的任意一个小写字母，一共有 $23$ 种，那么此时得到的方案数为 $dfs(i - 1, l, e, t) \times 23$。

我们也可以考虑在当前位置添加 `'l'`，此时得到的方案数为 $dfs(i - 1, \min(1, l + 1), e, t)$。同理，添加 `'e'` 和 `'t'` 的方案数分别为 $dfs(i - 1, l, \min(2, e + 1), t)$ 和 $dfs(i - 1, l, e, \min(1, t + 1))$。累加起来，并对 $10^9 + 7$ 取模，即可得到 $dfs(i, l, e, t)$ 的值。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stringCount(self, n: int) -> int:
        @cache
        def dfs(i: int, l: int, e: int, t: int) -> int:
            if i == 0:
                return int(l == 1 and e == 2 and t == 1)
            a = dfs(i - 1, l, e, t) * 23 % mod
            b = dfs(i - 1, min(1, l + 1), e, t)
            c = dfs(i - 1, l, min(2, e + 1), t)
            d = dfs(i - 1, l, e, min(1, t + 1))
            return (a + b + c + d) % mod

        mod = 10**9 + 7
        return dfs(n, 0, 0, 0)
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;
    private Long[][][][] f;

    public int stringCount(int n) {
        f = new Long[n + 1][2][3][2];
        return (int) dfs(n, 0, 0, 0);
    }

    private long dfs(int i, int l, int e, int t) {
        if (i == 0) {
            return l == 1 && e == 2 && t == 1 ? 1 : 0;
        }
        if (f[i][l][e][t] != null) {
            return f[i][l][e][t];
        }
        long a = dfs(i - 1, l, e, t) * 23 % mod;
        long b = dfs(i - 1, Math.min(1, l + 1), e, t);
        long c = dfs(i - 1, l, Math.min(2, e + 1), t);
        long d = dfs(i - 1, l, e, Math.min(1, t + 1));
        return f[i][l][e][t] = (a + b + c + d) % mod;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stringCount(int n) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll f[n + 1][2][3][2];
        memset(f, -1, sizeof(f));
        function<ll(int, int, int, int)> dfs = [&](int i, int l, int e, int t) -> ll {
            if (i == 0) {
                return l == 1 && e == 2 && t == 1 ? 1 : 0;
            }
            if (f[i][l][e][t] != -1) {
                return f[i][l][e][t];
            }
            ll a = dfs(i - 1, l, e, t) * 23 % mod;
            ll b = dfs(i - 1, min(1, l + 1), e, t) % mod;
            ll c = dfs(i - 1, l, min(2, e + 1), t) % mod;
            ll d = dfs(i - 1, l, e, min(1, t + 1)) % mod;
            return f[i][l][e][t] = (a + b + c + d) % mod;
        };
        return dfs(n, 0, 0, 0);
    }
};
```

#### Go

```go
func stringCount(n int) int {
	const mod int = 1e9 + 7
	f := make([][2][3][2]int, n+1)
	for i := range f {
		for j := range f[i] {
			for k := range f[i][j] {
				for l := range f[i][j][k] {
					f[i][j][k][l] = -1
				}
			}
		}
	}
	var dfs func(i, l, e, t int) int
	dfs = func(i, l, e, t int) int {
		if i == 0 {
			if l == 1 && e == 2 && t == 1 {
				return 1
			}
			return 0
		}
		if f[i][l][e][t] == -1 {
			a := dfs(i-1, l, e, t) * 23 % mod
			b := dfs(i-1, min(1, l+1), e, t)
			c := dfs(i-1, l, min(2, e+1), t)
			d := dfs(i-1, l, e, min(1, t+1))
			f[i][l][e][t] = (a + b + c + d) % mod
		}
		return f[i][l][e][t]
	}
	return dfs(n, 0, 0, 0)
}
```

#### TypeScript

```ts
function stringCount(n: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[][][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: 2 }, () =>
            Array.from({ length: 3 }, () => Array.from({ length: 2 }, () => -1)),
        ),
    );
    const dfs = (i: number, l: number, e: number, t: number): number => {
        if (i === 0) {
            return l === 1 && e === 2 && t === 1 ? 1 : 0;
        }
        if (f[i][l][e][t] !== -1) {
            return f[i][l][e][t];
        }
        const a = (dfs(i - 1, l, e, t) * 23) % mod;
        const b = dfs(i - 1, Math.min(1, l + 1), e, t);
        const c = dfs(i - 1, l, Math.min(2, e + 1), t);
        const d = dfs(i - 1, l, e, Math.min(1, t + 1));
        return (f[i][l][e][t] = (a + b + c + d) % mod);
    };
    return dfs(n, 0, 0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：逆向思维 + 容斥原理

我们可以考虑逆向思维，即计算不包含子字符串 `"leet"` 的字符串数目，然后用总数减去该数目即可。

我们分成以下几种情况：

-   情况 $a$：表示字符串中不包含字符 `'l'` 的方案数，那么有 $a = 25^n$。
-   情况 $b$：与 $a$ 类似，表示字符串中不包含字符 `'t'` 的方案数，那么有 $b = 25^n$。
-   情况 $c$：表示字符串中不包含字符 `'e'` 或者只包含一个字符 `'e'` 的方案数，那么有 $c = 25^n + n \times 25^{n - 1}$。
-   情况 $ab$：表示字符串中不包含字符 `'l'` 和 `'t'` 的方案数，那么有 $ab = 24^n$。
-   情况 $ac$：表示字符串中不包含字符 `'l'` 和 `'e'` 或者只包含一个字符 `'e'` 的方案数，那么有 $ac = 24^n + n \times 24^{n - 1}$。
-   情况 $bc$：与 $ac$ 类似，表示字符串中不包含字符 `'t'` 和 `'e'` 或者只包含一个字符 `'e'` 的方案数，那么有 $bc = 24^n + n \times 24^{n - 1}$。
-   情况 $abc$：表示字符串中不包含字符 `'l'`、`'t'` 和 `'e'` 或者只包含一个字符 `'e'` 的方案数，那么有 $abc = 23^n + n \times 23^{n - 1}$。

那么根据容斥原理，可以得到 $a + b + c - ab - ac - bc + abc$，就是不包含子字符串 `"leet"` 的字符串数目。

而总数 $tot = 26^n$，所以答案为 $tot - (a + b + c - ab - ac - bc + abc)$，注意要对 $10^9 + 7$ 取模。

时间复杂度 $O(\log n)$，其中 $n$ 为字符串长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stringCount(self, n: int) -> int:
        mod = 10**9 + 7
        a = b = pow(25, n, mod)
        c = pow(25, n, mod) + n * pow(25, n - 1, mod)
        ab = pow(24, n, mod)
        ac = bc = (pow(24, n, mod) + n * pow(24, n - 1, mod)) % mod
        abc = (pow(23, n, mod) + n * pow(23, n - 1, mod)) % mod
        tot = pow(26, n, mod)
        return (tot - (a + b + c - ab - ac - bc + abc)) % mod
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int stringCount(int n) {
        long a = qpow(25, n);
        long b = a;
        long c = (qpow(25, n) + n * qpow(25, n - 1) % mod) % mod;
        long ab = qpow(24, n);
        long ac = (qpow(24, n) + n * qpow(24, n - 1) % mod) % mod;
        long bc = ac;
        long abc = (qpow(23, n) + n * qpow(23, n - 1) % mod) % mod;
        long tot = qpow(26, n);
        return (int) ((tot - (a + b + c - ab - ac - bc + abc)) % mod + mod) % mod;
    }

    private long qpow(long a, int n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stringCount(int n) {
        const int mod = 1e9 + 7;
        using ll = long long;
        auto qpow = [&](ll a, int n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        ll a = qpow(25, n);
        ll b = a;
        ll c = (qpow(25, n) + n * qpow(25, n - 1) % mod) % mod;
        ll ab = qpow(24, n);
        ll ac = (qpow(24, n) + n * qpow(24, n - 1) % mod) % mod;
        ll bc = ac;
        ll abc = (qpow(23, n) + n * qpow(23, n - 1) % mod) % mod;
        ll tot = qpow(26, n);
        return ((tot - (a + b + c - ab - ac - bc + abc)) % mod + mod) % mod;
    }
};
```

#### Go

```go
func stringCount(n int) int {
	const mod int = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	a := qpow(25, n)
	b := a
	c := qpow(25, n) + n*qpow(25, n-1)
	ab := qpow(24, n)
	ac := (qpow(24, n) + n*qpow(24, n-1)) % mod
	bc := ac
	abc := (qpow(23, n) + n*qpow(23, n-1)) % mod
	tot := qpow(26, n)
	return ((tot-(a+b+c-ab-ac-bc+abc))%mod + mod) % mod
}
```

#### TypeScript

```ts
function stringCount(n: number): number {
    const mod = BigInt(10 ** 9 + 7);
    const qpow = (a: bigint, n: number): bigint => {
        let ans = 1n;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
        }
        return ans;
    };
    const a = qpow(25n, n);
    const b = a;
    const c = (qpow(25n, n) + ((BigInt(n) * qpow(25n, n - 1)) % mod)) % mod;
    const ab = qpow(24n, n);
    const ac = (qpow(24n, n) + ((BigInt(n) * qpow(24n, n - 1)) % mod)) % mod;
    const bc = ac;
    const abc = (qpow(23n, n) + ((BigInt(n) * qpow(23n, n - 1)) % mod)) % mod;
    const tot = qpow(26n, n);
    return Number((((tot - (a + b + c - ab - ac - bc + abc)) % mod) + mod) % mod);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2931. 购买物品的最大开销](https://leetcode.cn/problems/maximum-spending-after-buying-items){#2931}

{{< tabs "2931" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        n = len(values[0])
        pq = [(row[-1], i, n - 1) for i, row in enumerate(values)]
        heapify(pq)
        ans = d = 0
        while pq:
            d += 1
            v, i, j = heappop(pq)
            ans += v * d
            if j:
                heappush(pq, (values[i][j - 1], i, j - 1))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxSpending(int[][] values) {
        int m = values.length, n = values[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < m; ++i) {
            pq.offer(new int[] {values[i][n - 1], i, n - 1});
        }
        long ans = 0;
        for (int d = 1; !pq.isEmpty(); ++d) {
            var p = pq.poll();
            int v = p[0], i = p[1], j = p[2];
            ans += (long) v * d;
            if (j > 0) {
                pq.offer(new int[] {values[i][j - 1], i, j - 1});
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
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int m = values.size(), n = values[0].size();
        for (int i = 0; i < m; ++i) {
            pq.emplace(values[i][n - 1], i, n - 1);
        }
        long long ans = 0;
        for (int d = 1; pq.size(); ++d) {
            auto [v, i, j] = pq.top();
            pq.pop();
            ans += 1LL * v * d;
            if (j) {
                pq.emplace(values[i][j - 1], i, j - 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSpending(values [][]int) (ans int64) {
	pq := hp{}
	n := len(values[0])
	for i, row := range values {
		heap.Push(&pq, tuple{row[n-1], i, n - 1})
	}
	for d := 1; len(pq) > 0; d++ {
		p := heap.Pop(&pq).(tuple)
		ans += int64(p.v * d)
		if p.j > 0 {
			heap.Push(&pq, tuple{values[p.i][p.j-1], p.i, p.j - 1})
		}
	}
	return
}

type tuple struct{ v, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSpending(values: number[][]): number {
    const m = values.length;
    const n = values[0].length;
    const pq = new PriorityQueue({ compare: (a, b) => a[0] - b[0] });
    for (let i = 0; i < m; ++i) {
        pq.enqueue([values[i][n - 1], i, n - 1]);
    }

    let ans = 0;
    for (let d = 1; !pq.isEmpty(); ++d) {
        const [v, i, j] = pq.dequeue()!;
        ans += v * d;
        if (j > 0) {
            pq.enqueue([values[i][j - 1], i, j - 1]);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始大小为&nbsp;<code>m * n</code>&nbsp;的整数矩阵&nbsp;<code>values</code>&nbsp;，表示&nbsp;<code>m</code>&nbsp;个不同商店里&nbsp;<code>m * n</code>&nbsp;件不同的物品。每个商店有 <code>n</code>&nbsp;件物品，第&nbsp;<code>i</code>&nbsp;个商店的第 <code>j</code>&nbsp;件物品的价值为&nbsp;<code>values[i][j]</code>&nbsp;。除此以外，第&nbsp;<code>i</code>&nbsp;个商店的物品已经按照价值非递增排好序了，也就是说对于所有&nbsp;<code>0 &lt;= j &lt; n - 1</code>&nbsp;都有&nbsp;<code>values[i][j] &gt;= values[i][j + 1]</code>&nbsp;。</p>

<p>每一天，你可以在一个商店里购买一件物品。具体来说，在第&nbsp;<code>d</code>&nbsp;天，你可以：</p>

<ul>
	<li>选择商店&nbsp;<code>i</code>&nbsp;。</li>
	<li>购买数组中最右边的物品&nbsp;<code>j</code>&nbsp;，开销为&nbsp;<code>values[i][j] * d</code>&nbsp;。换句话说，选择该商店中还没购买过的物品中最大的下标&nbsp;<code>j</code>&nbsp;，并且花费&nbsp;<code>values[i][j] * d</code>&nbsp;去购买。</li>
</ul>

<p><strong>注意</strong>，所有物品都视为不同的物品。比方说如果你已经从商店 <code>1</code>&nbsp;购买了物品&nbsp;<code>0</code>&nbsp;，你还可以在别的商店里购买其他商店的物品&nbsp;<code>0</code>&nbsp;。</p>

<p>请你返回购买所有 <code>m * n</code>&nbsp;件物品需要的 <strong>最大开销</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>values = [[8,5,2],[6,4,1],[9,7,3]]
<b>输出：</b>285
<b>解释：</b>第一天，从商店 1 购买物品 2 ，开销为 values[1][2] * 1 = 1 。
第二天，从商店 0 购买物品 2 ，开销为 values[0][2] * 2 = 4 。
第三天，从商店 2 购买物品 2 ，开销为 values[2][2] * 3 = 9 。
第四天，从商店 1 购买物品 1 ，开销为 values[1][1] * 4 = 16 。
第五天，从商店 0 购买物品 1 ，开销为 values[0][1] * 5 = 25 。
第六天，从商店 1 购买物品 0 ，开销为 values[1][0] * 6 = 36 。
第七天，从商店 2 购买物品 1 ，开销为 values[2][1] * 7 = 49 。
第八天，从商店 0 购买物品 0 ，开销为 values[0][0] * 8 = 64 。
第九天，从商店 2 购买物品 0 ，开销为 values[2][0] * 9 = 81 。
所以总开销为 285 。
285 是购买所有 m * n 件物品的最大总开销。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>values = [[10,8,6,4,2],[9,7,5,3,2]]
<b>输出：</b>386
<b>解释：</b>第一天，从商店 0 购买物品 4 ，开销为 values[0][4] * 1 = 2 。
第二天，从商店 1 购买物品 4 ，开销为 values[1][4] * 2 = 4 。
第三天，从商店 1 购买物品 3 ，开销为 values[1][3] * 3 = 9 。
第四天，从商店 0 购买物品 3 ，开销为 values[0][3] * 4 = 16 。
第五天，从商店 1 购买物品 2 ，开销为 values[1][2] * 5 = 25 。
第六天，从商店 0 购买物品 2 ，开销为 values[0][2] * 6 = 36 。
第七天，从商店 1 购买物品 1 ，开销为 values[1][1] * 7 = 49 。
第八天，从商店 0 购买物品 1 ，开销为 values[0][1] * 8 = 64 。
第九天，从商店 1 购买物品 0 ，开销为 values[1][0] * 9 = 81 。
第十天，从商店 0 购买物品 0 ，开销为 values[0][0] * 10 = 100 。
所以总开销为 386 。
386 是购买所有 m * n 件物品的最大总开销。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m == values.length &lt;= 10</code></li>
	<li><code>1 &lt;= n == values[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= values[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>values[i]</code>&nbsp;按照非递增顺序排序。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列

根据题目描述，我们应该优先选择价值越小的物品，把价值越大的物品留到后面购买，这样才能使得总开销最大。因此，我们使用优先队列（小根堆）存储每个商店中还未购买的最小价值的物品。初始时，我们将每个商店中最右边的物品加入优先队列。

在每一天，我们从优先队列中取出价值最小的物品，将其加入答案，并将该物品所在商店中的上一个物品加入优先队列。我们重复上述操作，直到优先队列为空。

时间复杂度 $O(m \times n \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是数组 $values$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        n = len(values[0])
        pq = [(row[-1], i, n - 1) for i, row in enumerate(values)]
        heapify(pq)
        ans = d = 0
        while pq:
            d += 1
            v, i, j = heappop(pq)
            ans += v * d
            if j:
                heappush(pq, (values[i][j - 1], i, j - 1))
        return ans
```

#### Java

```java
class Solution {
    public long maxSpending(int[][] values) {
        int m = values.length, n = values[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < m; ++i) {
            pq.offer(new int[] {values[i][n - 1], i, n - 1});
        }
        long ans = 0;
        for (int d = 1; !pq.isEmpty(); ++d) {
            var p = pq.poll();
            int v = p[0], i = p[1], j = p[2];
            ans += (long) v * d;
            if (j > 0) {
                pq.offer(new int[] {values[i][j - 1], i, j - 1});
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
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int m = values.size(), n = values[0].size();
        for (int i = 0; i < m; ++i) {
            pq.emplace(values[i][n - 1], i, n - 1);
        }
        long long ans = 0;
        for (int d = 1; pq.size(); ++d) {
            auto [v, i, j] = pq.top();
            pq.pop();
            ans += 1LL * v * d;
            if (j) {
                pq.emplace(values[i][j - 1], i, j - 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSpending(values [][]int) (ans int64) {
	pq := hp{}
	n := len(values[0])
	for i, row := range values {
		heap.Push(&pq, tuple{row[n-1], i, n - 1})
	}
	for d := 1; len(pq) > 0; d++ {
		p := heap.Pop(&pq).(tuple)
		ans += int64(p.v * d)
		if p.j > 0 {
			heap.Push(&pq, tuple{values[p.i][p.j-1], p.i, p.j - 1})
		}
	}
	return
}

type tuple struct{ v, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function maxSpending(values: number[][]): number {
    const m = values.length;
    const n = values[0].length;
    const pq = new PriorityQueue({ compare: (a, b) => a[0] - b[0] });
    for (let i = 0; i < m; ++i) {
        pq.enqueue([values[i][n - 1], i, n - 1]);
    }

    let ans = 0;
    for (let d = 1; !pq.isEmpty(); ++d) {
        const [v, i, j] = pq.dequeue()!;
        ans += v * d;
        if (j > 0) {
            pq.enqueue([values[i][j - 1], i, j - 1]);
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

# [2932. 找出强数对的最大异或值 I](https://leetcode.cn/problems/maximum-strong-pair-xor-i){#2932}

{{< tabs "2932" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ("children", "cnt")

    def __init__(self):
        self.children: List[Trie | None] = [None, None]
        self.cnt = 0

    def insert(self, x: int):
        node = self
        for i in range(7, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]
            node.cnt += 1

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(7, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1] and node.children[v ^ 1].cnt:
                ans |= 1 << i
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans

    def remove(self, x: int):
        node = self
        for i in range(7, -1, -1):
            v = x >> i & 1
            node = node.children[v]
            node.cnt -= 1


class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        nums.sort()
        tree = Trie()
        ans = i = 0
        for y in nums:
            tree.insert(y)
            while y > nums[i] * 2:
                tree.remove(nums[i])
                i += 1
            ans = max(ans, tree.search(y))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[2];
    private int cnt = 0;

    public Trie() {
    }

    public void insert(int x) {
        Trie node = this;
        for (int i = 7; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
            ++node.cnt;
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 7; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null && node.children[v ^ 1].cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }

    public void remove(int x) {
        Trie node = this;
        for (int i = 7; i >= 0; --i) {
            int v = x >> i & 1;
            node = node.children[v];
            --node.cnt;
        }
    }
}

class Solution {
    public int maximumStrongPairXor(int[] nums) {
        Arrays.sort(nums);
        Trie tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree.insert(y);
            while (y > nums[i] * 2) {
                tree.remove(nums[i++]);
            }
            ans = Math.max(ans, tree.search(y));
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie* children[2];
    int cnt;

    Trie()
        : cnt(0) {
        children[0] = nullptr;
        children[1] = nullptr;
    }

    void insert(int x) {
        Trie* node = this;
        for (int i = 7; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v] == nullptr) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
            ++node->cnt;
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 7; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v ^ 1] != nullptr && node->children[v ^ 1]->cnt > 0) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }

    void remove(int x) {
        Trie* node = this;
        for (int i = 7; ~i; --i) {
            int v = (x >> i) & 1;
            node = node->children[v];
            --node->cnt;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie* tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree->insert(y);
            while (y > nums[i] * 2) {
                tree->remove(nums[i++]);
            }
            ans = max(ans, tree->search(y));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [2]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(x int) {
	node := t
	for i := 7; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
		node.cnt++
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 7; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v^1] != nil && node.children[v^1].cnt > 0 {
			ans |= 1 << uint(i)
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return ans
}

func (t *Trie) remove(x int) {
	node := t
	for i := 7; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		node = node.children[v]
		node.cnt--
	}
}

func maximumStrongPairXor(nums []int) (ans int) {
	sort.Ints(nums)
	tree := newTrie()
	i := 0
	for _, y := range nums {
		tree.insert(y)
		for ; y > nums[i]*2; i++ {
			tree.remove(nums[i])
		}
		ans = max(ans, tree.search(y))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: (Trie | null)[];
    cnt: number;

    constructor() {
        this.children = [null, null];
        this.cnt = 0;
    }

    insert(x: number): void {
        let node: Trie | null = this;
        for (let i = 7; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v] === null) {
                node.children[v] = new Trie();
            }
            node = node.children[v] as Trie;
            node.cnt++;
        }
    }

    search(x: number): number {
        let node: Trie | null = this;
        let ans = 0;
        for (let i = 7; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v ^ 1] !== null && (node.children[v ^ 1] as Trie).cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1] as Trie;
            } else {
                node = node.children[v] as Trie;
            }
        }
        return ans;
    }

    remove(x: number): void {
        let node: Trie | null = this;
        for (let i = 7; i >= 0; i--) {
            const v = (x >> i) & 1;
            node = node.children[v] as Trie;
            node.cnt--;
        }
    }
}

function maximumStrongPairXor(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const tree = new Trie();
    let ans = 0;
    let i = 0;

    for (const y of nums) {
        tree.insert(y);

        while (y > nums[i] * 2) {
            tree.remove(nums[i++]);
        }

        ans = Math.max(ans, tree.search(y));
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。如果一对整数 <code>x</code> 和 <code>y</code> 满足以下条件，则称其为 <strong>强数对</strong> ：</p>

<ul>
	<li><code>|x - y| &lt;= min(x, y)</code></li>
</ul>

<p>你需要从 <code>nums</code> 中选出两个整数，且满足：这两个整数可以形成一个强数对，并且它们的按位异或（<code>XOR</code>）值是在该数组所有强数对中的<strong> 最大值 </strong>。</p>

<p>返回数组 <code>nums</code> 所有可能的强数对中的<strong> 最大 </strong>异或值。</p>

<p><strong>注意</strong>，你可以选择同一个整数两次来形成一个强数对。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>7
<strong>解释：</strong>数组<code> nums </code>中有 11 个强数对：(1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) 和 (5, 5) 。
这些强数对中的最大异或值是 3 XOR 4 = 7 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,100]
<strong>输出：</strong>0
<strong>解释：</strong>数组<code> nums </code>中有 2 个强数对：(10, 10) 和 (100, 100) 。
这些强数对中的最大异或值是 10 XOR 10 = 0 ，数对 (100, 100) 的异或值也是 100 XOR 100 = 0 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,6,25,30]
<strong>输出：</strong>7
<strong>解释：</strong>数组<code> nums </code>中有 6 个强数对：(5, 5), (5, 6), (6, 6), (25, 25), (25, 30) 和 (30, 30) 。
这些强数对中的最大异或值是 25 XOR 30 = 7 ；另一个异或值非零的数对是 (5, 6) ，其异或值是 5 XOR 6 = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举数组中的每一个数对 $(x, y)$，如果满足 $|x - y| \leq \min(x, y)$，那么这个数对就是一个强数对，我们可以计算这个数对的异或值，并更新答案。

时间复杂度 $O(n^2)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        return max(x ^ y for x in nums for y in nums if abs(x - y) <= min(x, y))
```

#### Java

```java
class Solution {
    public int maximumStrongPairXor(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            for (int y : nums) {
                if (Math.abs(x - y) <= Math.min(x, y)) {
                    ans = Math.max(ans, x ^ y);
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
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            for (int y : nums) {
                if (abs(x - y) <= min(x, y)) {
                    ans = max(ans, x ^ y);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumStrongPairXor(nums []int) (ans int) {
	for _, x := range nums {
		for _, y := range nums {
			if abs(x-y) <= min(x, y) {
				ans = max(ans, x^y)
			}
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function maximumStrongPairXor(nums: number[]): number {
    let ans = 0;
    for (const x of nums) {
        for (const y of nums) {
            if (Math.abs(x - y) <= Math.min(x, y)) {
                ans = Math.max(ans, x ^ y);
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 0-1 字典树

观察不等式 $|x - y| \leq \min(x, y)$，其中涉及到绝对值以及最小值，我们不妨假设 $x \leq y$，则有 $y - x \leq x$，即 $y \leq 2x$。我们可以从小到大枚举 $y$，那么 $x$ 必须满足不等式 $y \leq 2x$。

因此，我们对数组 $nums$ 进行排序，然后从小到大枚举 $y$，利用双指针维护一个窗口，使得窗口内的元素 $x$ 满足不等式 $y \leq 2x$。我们可以使用 0-1 字典树来维护窗口内的元素，这样我们就可以在 $O(1)$ 的时间内找到窗口内的最大异或值。每一次我们将 $y$ 加入到字典树中，同时将窗口左端点不满足不等式的元素移除，这样就可以保证窗口内的元素满足不等式 $y \leq 2x$。然后从字典树中查询最大异或值，更新答案。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n \times \log M)$。其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ("children", "cnt")

    def __init__(self):
        self.children: List[Trie | None] = [None, None]
        self.cnt = 0

    def insert(self, x: int):
        node = self
        for i in range(7, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]
            node.cnt += 1

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(7, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1] and node.children[v ^ 1].cnt:
                ans |= 1 << i
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans

    def remove(self, x: int):
        node = self
        for i in range(7, -1, -1):
            v = x >> i & 1
            node = node.children[v]
            node.cnt -= 1


class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        nums.sort()
        tree = Trie()
        ans = i = 0
        for y in nums:
            tree.insert(y)
            while y > nums[i] * 2:
                tree.remove(nums[i])
                i += 1
            ans = max(ans, tree.search(y))
        return ans
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[2];
    private int cnt = 0;

    public Trie() {
    }

    public void insert(int x) {
        Trie node = this;
        for (int i = 7; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
            ++node.cnt;
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 7; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null && node.children[v ^ 1].cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }

    public void remove(int x) {
        Trie node = this;
        for (int i = 7; i >= 0; --i) {
            int v = x >> i & 1;
            node = node.children[v];
            --node.cnt;
        }
    }
}

class Solution {
    public int maximumStrongPairXor(int[] nums) {
        Arrays.sort(nums);
        Trie tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree.insert(y);
            while (y > nums[i] * 2) {
                tree.remove(nums[i++]);
            }
            ans = Math.max(ans, tree.search(y));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie* children[2];
    int cnt;

    Trie()
        : cnt(0) {
        children[0] = nullptr;
        children[1] = nullptr;
    }

    void insert(int x) {
        Trie* node = this;
        for (int i = 7; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v] == nullptr) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
            ++node->cnt;
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 7; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v ^ 1] != nullptr && node->children[v ^ 1]->cnt > 0) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }

    void remove(int x) {
        Trie* node = this;
        for (int i = 7; ~i; --i) {
            int v = (x >> i) & 1;
            node = node->children[v];
            --node->cnt;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie* tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree->insert(y);
            while (y > nums[i] * 2) {
                tree->remove(nums[i++]);
            }
            ans = max(ans, tree->search(y));
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [2]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(x int) {
	node := t
	for i := 7; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
		node.cnt++
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 7; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v^1] != nil && node.children[v^1].cnt > 0 {
			ans |= 1 << uint(i)
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return ans
}

func (t *Trie) remove(x int) {
	node := t
	for i := 7; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		node = node.children[v]
		node.cnt--
	}
}

func maximumStrongPairXor(nums []int) (ans int) {
	sort.Ints(nums)
	tree := newTrie()
	i := 0
	for _, y := range nums {
		tree.insert(y)
		for ; y > nums[i]*2; i++ {
			tree.remove(nums[i])
		}
		ans = max(ans, tree.search(y))
	}
	return ans
}
```

#### TypeScript

```ts
class Trie {
    children: (Trie | null)[];
    cnt: number;

    constructor() {
        this.children = [null, null];
        this.cnt = 0;
    }

    insert(x: number): void {
        let node: Trie | null = this;
        for (let i = 7; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v] === null) {
                node.children[v] = new Trie();
            }
            node = node.children[v] as Trie;
            node.cnt++;
        }
    }

    search(x: number): number {
        let node: Trie | null = this;
        let ans = 0;
        for (let i = 7; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v ^ 1] !== null && (node.children[v ^ 1] as Trie).cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1] as Trie;
            } else {
                node = node.children[v] as Trie;
            }
        }
        return ans;
    }

    remove(x: number): void {
        let node: Trie | null = this;
        for (let i = 7; i >= 0; i--) {
            const v = (x >> i) & 1;
            node = node.children[v] as Trie;
            node.cnt--;
        }
    }
}

function maximumStrongPairXor(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const tree = new Trie();
    let ans = 0;
    let i = 0;

    for (const y of nums) {
        tree.insert(y);

        while (y > nums[i] * 2) {
            tree.remove(nums[i++]);
        }

        ans = Math.max(ans, tree.search(y));
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2933. 高访问员工](https://leetcode.cn/problems/high-access-employees){#2933}

{{< tabs "2933" >}}

{{% tab "python" %}}
```python
class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        d = defaultdict(list)
        for name, t in access_times:
            d[name].append(int(t[:2]) * 60 + int(t[2:]))
        ans = []
        for name, ts in d.items():
            ts.sort()
            if any(ts[i] - ts[i - 2] < 60 for i in range(2, len(ts))):
                ans.append(name)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> findHighAccessEmployees(List<List<String>> access_times) {
        Map<String, List<Integer>> d = new HashMap<>();
        for (var e : access_times) {
            String name = e.get(0), s = e.get(1);
            int t = Integer.valueOf(s.substring(0, 2)) * 60 + Integer.valueOf(s.substring(2));
            d.computeIfAbsent(name, k -> new ArrayList<>()).add(t);
        }
        List<String> ans = new ArrayList<>();
        for (var e : d.entrySet()) {
            String name = e.getKey();
            var ts = e.getValue();
            Collections.sort(ts);
            for (int i = 2; i < ts.size(); ++i) {
                if (ts.get(i) - ts.get(i - 2) < 60) {
                    ans.add(name);
                    break;
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
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> d;
        for (auto& e : access_times) {
            auto name = e[0];
            auto s = e[1];
            int t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2, 2));
            d[name].emplace_back(t);
        }
        vector<string> ans;
        for (auto& [name, ts] : d) {
            sort(ts.begin(), ts.end());
            for (int i = 2; i < ts.size(); ++i) {
                if (ts[i] - ts[i - 2] < 60) {
                    ans.emplace_back(name);
                    break;
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
func findHighAccessEmployees(access_times [][]string) (ans []string) {
	d := map[string][]int{}
	for _, e := range access_times {
		name, s := e[0], e[1]
		h, _ := strconv.Atoi(s[:2])
		m, _ := strconv.Atoi(s[2:])
		t := h*60 + m
		d[name] = append(d[name], t)
	}
	for name, ts := range d {
		sort.Ints(ts)
		for i := 2; i < len(ts); i++ {
			if ts[i]-ts[i-2] < 60 {
				ans = append(ans, name)
				break
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findHighAccessEmployees(access_times: string[][]): string[] {
    const d: Map<string, number[]> = new Map();
    for (const [name, s] of access_times) {
        const h = parseInt(s.slice(0, 2), 10);
        const m = parseInt(s.slice(2), 10);
        const t = h * 60 + m;
        if (!d.has(name)) {
            d.set(name, []);
        }
        d.get(name)!.push(t);
    }
    const ans: string[] = [];
    for (const [name, ts] of d) {
        ts.sort((a, b) => a - b);
        for (let i = 2; i < ts.length; ++i) {
            if (ts[i] - ts[i - 2] < 60) {
                ans.push(name);
                break;
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

<p>给你一个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的二维字符串数组 <code>access_times</code> 。对于每个 <code>i</code>（<code>0 &lt;= i &lt;= n - 1</code> ），<code>access_times[i][0]</code> 表示某位员工的姓名，<code>access_times[i][1]</code> 表示该员工的访问时间。<code>access_times</code> 中的所有条目都发生在同一天内。</p>

<p>访问时间用 <strong>四位</strong> 数字表示， 符合 <strong>24 小时制</strong> ，例如 <code>"0800"</code> 或 <code>"2250"</code> 。</p>

<p>如果员工在 <strong>同一小时内</strong> 访问系统 <strong>三次或更多</strong> ，则称其为 <strong>高访问</strong> 员工。</p>

<p>时间间隔正好相差一小时的时间 <strong>不</strong> 被视为同一小时内。例如，<code>"0815"</code> 和 <code>"0915"</code> 不属于同一小时内。</p>

<p>一天开始和结束时的访问时间不被计算为同一小时内。例如，<code>"0005"</code> 和 <code>"2350"</code> 不属于同一小时内。</p>

<p>以列表形式，按任意顺序，返回所有 <strong>高访问</strong> 员工的姓名。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
<strong>输出：</strong>["a"]
<strong>解释：</strong>"a" 在时间段 [05:32, 06:31] 内有三条访问记录，时间分别为 05:32 、05:49 和 06:21 。
但是 "b" 的访问记录只有两条。
因此，答案是 ["a"] 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>access_times = [["d","0002"],["c","0808"],["c","0829"],["e","0215"],["d","1508"],["d","1444"],["d","1410"],["c","0809"]]
<strong>输出：</strong>["c","d"]
<strong>解释：</strong>"c" 在时间段 [08:08, 09:07] 内有三条访问记录，时间分别为 08:08 、08:09 和 08:29 。
"d" 在时间段 [14:10, 15:09] 内有三条访问记录，时间分别为 14:10 、14:44 和 15:08 。
然而，"e" 只有一条访问记录，因此不能包含在答案中，最终答案是 ["c","d"] 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>access_times = [["cd","1025"],["ab","1025"],["cd","1046"],["cd","1055"],["ab","1124"],["ab","1120"]]
<strong>输出：</strong>["ab","cd"]
<strong>解释：</strong>"ab"在时间段 [10:25, 11:24] 内有三条访问记录，时间分别为 10:25 、11:20 和 11:24 。
"cd" 在时间段 [10:25, 11:24] 内有三条访问记录，时间分别为 10:25 、10:46 和 10:55 。
因此，答案是 ["ab","cd"] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= access_times.length &lt;= 100</code></li>
	<li><code>access_times[i].length == 2</code></li>
	<li><code>1 &lt;= access_times[i][0].length &lt;= 10</code></li>
	<li><code>access_times[i][0]</code> 仅由小写英文字母组成。</li>
	<li><code>access_times[i][1].length == 4</code></li>
	<li><code>access_times[i][1]</code> 采用24小时制表示时间。</li>
	<li><code>access_times[i][1]</code> 仅由数字 <code>'0'</code> 到 <code>'9'</code> 组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们用一个哈希表 $d$ 来存储每个员工的所有访问时间，其中键为员工的姓名，值为一个整数数组，表示该员工的所有访问时间，该时间为从当天 00:00 开始的分钟数。

对于每个员工，我们将其所有访问时间按照从小到大的顺序进行排序。然后我们遍历该员工的所有访问时间，如果存在连续的三个访问时间 $t_1, t_2, t_3$，满足 $t_3 - t_1 < 60$，则该员工为高访问员工，我们将其姓名加入答案数组中。

最后，返回答案数组即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为访问记录的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        d = defaultdict(list)
        for name, t in access_times:
            d[name].append(int(t[:2]) * 60 + int(t[2:]))
        ans = []
        for name, ts in d.items():
            ts.sort()
            if any(ts[i] - ts[i - 2] < 60 for i in range(2, len(ts))):
                ans.append(name)
        return ans
```

#### Java

```java
class Solution {
    public List<String> findHighAccessEmployees(List<List<String>> access_times) {
        Map<String, List<Integer>> d = new HashMap<>();
        for (var e : access_times) {
            String name = e.get(0), s = e.get(1);
            int t = Integer.valueOf(s.substring(0, 2)) * 60 + Integer.valueOf(s.substring(2));
            d.computeIfAbsent(name, k -> new ArrayList<>()).add(t);
        }
        List<String> ans = new ArrayList<>();
        for (var e : d.entrySet()) {
            String name = e.getKey();
            var ts = e.getValue();
            Collections.sort(ts);
            for (int i = 2; i < ts.size(); ++i) {
                if (ts.get(i) - ts.get(i - 2) < 60) {
                    ans.add(name);
                    break;
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
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> d;
        for (auto& e : access_times) {
            auto name = e[0];
            auto s = e[1];
            int t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2, 2));
            d[name].emplace_back(t);
        }
        vector<string> ans;
        for (auto& [name, ts] : d) {
            sort(ts.begin(), ts.end());
            for (int i = 2; i < ts.size(); ++i) {
                if (ts[i] - ts[i - 2] < 60) {
                    ans.emplace_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findHighAccessEmployees(access_times [][]string) (ans []string) {
	d := map[string][]int{}
	for _, e := range access_times {
		name, s := e[0], e[1]
		h, _ := strconv.Atoi(s[:2])
		m, _ := strconv.Atoi(s[2:])
		t := h*60 + m
		d[name] = append(d[name], t)
	}
	for name, ts := range d {
		sort.Ints(ts)
		for i := 2; i < len(ts); i++ {
			if ts[i]-ts[i-2] < 60 {
				ans = append(ans, name)
				break
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findHighAccessEmployees(access_times: string[][]): string[] {
    const d: Map<string, number[]> = new Map();
    for (const [name, s] of access_times) {
        const h = parseInt(s.slice(0, 2), 10);
        const m = parseInt(s.slice(2), 10);
        const t = h * 60 + m;
        if (!d.has(name)) {
            d.set(name, []);
        }
        d.get(name)!.push(t);
    }
    const ans: string[] = [];
    for (const [name, ts] of d) {
        ts.sort((a, b) => a - b);
        for (let i = 2; i < ts.length; ++i) {
            if (ts[i] - ts[i - 2] < 60) {
                ans.push(name);
                break;
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

# [2934. 最大化数组末位元素的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-maximize-last-elements-in-arrays){#2934}

{{< tabs "2934" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        def f(x: int, y: int) -> int:
            cnt = 0
            for a, b in zip(nums1[:-1], nums2[:-1]):
                if a <= x and b <= y:
                    continue
                if not (a <= y and b <= x):
                    return -1
                cnt += 1
            return cnt

        a, b = f(nums1[-1], nums2[-1]), f(nums2[-1], nums1[-1])
        return -1 if a + b == -2 else min(a, b + 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int minOperations(int[] nums1, int[] nums2) {
        n = nums1.length;
        int a = f(nums1, nums2, nums1[n - 1], nums2[n - 1]);
        int b = f(nums1, nums2, nums2[n - 1], nums1[n - 1]);
        return a + b == -2 ? -1 : Math.min(a, b + 1);
    }

    private int f(int[] nums1, int[] nums2, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums1[i] <= x && nums2[i] <= y) {
                continue;
            }
            if (!(nums1[i] <= y && nums2[i] <= x)) {
                return -1;
            }
            ++cnt;
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        auto f = [&](int x, int y) {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (nums1[i] <= x && nums2[i] <= y) {
                    continue;
                }
                if (!(nums1[i] <= y && nums2[i] <= x)) {
                    return -1;
                }
                ++cnt;
            }
            return cnt;
        };
        int a = f(nums1.back(), nums2.back());
        int b = f(nums2.back(), nums1.back());
        return a + b == -2 ? -1 : min(a, b + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := func(x, y int) (cnt int) {
		for i, a := range nums1[:n-1] {
			b := nums2[i]
			if a <= x && b <= y {
				continue
			}
			if !(a <= y && b <= x) {
				return -1
			}
			cnt++
		}
		return
	}
	a, b := f(nums1[n-1], nums2[n-1]), f(nums2[n-1], nums1[n-1])
	if a+b == -2 {
		return -1
	}
	return min(a, b+1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const f = (x: number, y: number): number => {
        let cnt = 0;
        for (let i = 0; i < n - 1; ++i) {
            if (nums1[i] <= x && nums2[i] <= y) {
                continue;
            }
            if (!(nums1[i] <= y && nums2[i] <= x)) {
                return -1;
            }
            ++cnt;
        }
        return cnt;
    };
    const a = f(nums1.at(-1), nums2.at(-1));
    const b = f(nums2.at(-1), nums1.at(-1));
    return a + b === -2 ? -1 : Math.min(a, b + 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong> 开始的整数数组 <code>nums1</code> 和 <code>nums2</code> ，这两个数组的长度都是 <code>n</code> 。</p>

<p>你可以执行一系列<strong> 操作（可能不执行）</strong>。</p>

<p>在每次操作中，你可以选择一个在范围 <code>[0, n - 1]</code> 内的下标 <code>i</code> ，并交换 <code>nums1[i]</code> 和 <code>nums2[i]</code> 的值。</p>

<p>你的任务是找到满足以下条件所需的 <strong>最小</strong> 操作次数：</p>

<ul>
	<li><code>nums1[n - 1]</code> 等于 <code>nums1</code> 中所有元素的 <strong>最大值</strong> ，即 <code>nums1[n - 1] = max(nums1[0], nums1[1], ..., nums1[n - 1])</code> 。</li>
	<li><code>nums2[n - 1]</code> 等于 <code>nums2</code> 中所有元素的 <strong>最大值</strong> ，即 <code>nums2[n - 1] = max(nums2[0], nums2[1], ..., nums2[n - 1])</code> 。</li>
</ul>

<p>以整数形式，表示并返回满足上述 <strong>全部</strong> 条件所需的 <strong>最小</strong> 操作次数，如果无法同时满足两个条件，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,7]，nums2 = [4,5,3]
<strong>输出：</strong>1
<strong>解释：</strong>在这个示例中，可以选择下标 i = 2 执行一次操作。
交换 nums1[2] 和 nums2[2] 的值，nums1 变为 [1,2,3] ，nums2 变为 [4,5,7] 。
同时满足两个条件。
可以证明，需要执行的最小操作次数为 1 。
因此，答案是 1 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,3,4,5,9]，nums2 = [8,8,4,4,4]
<strong>输出：</strong>2
<strong>解释：</strong>在这个示例中，可以执行以下操作：
首先，选择下标 i = 4 执行操作。
交换 nums1[4] 和 nums2[4] 的值，nums1 变为 [2,3,4,5,4] ，nums2 变为 [8,8,4,4,9] 。
然后，选择下标 i = 3 执行操作。
交换 nums1[3] 和 nums2[3] 的值，nums1 变为 [2,3,4,4,4] ，nums2 变为 [8,8,4,5,9] 。
同时满足两个条件。 
可以证明，需要执行的最小操作次数为 2 。 
因此，答案是 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,5,4]，nums2 = [2,5,3]
<strong>输出：</strong>-1
<strong>解释：</strong>在这个示例中，无法同时满足两个条件。
因此，答案是 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums1.length == nums2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums1[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论 + 贪心

我们可以分成两种情况讨论：

1. 不交换 $nums1[n - 1]$ 和 $nums2[n - 1]$ 的值
1. 交换 $nums1[n - 1]$ 和 $nums2[n - 1]$ 的值

对于每一种情况，我们记数组 $nums1$ 和 $nums2$ 的最后一个值分别为 $x$ 和 $y$。然后遍历数组 $nums1$ 和 $nums2$ 的前 $n - 1$ 个值，用一个变量 $cnt$ 记录交换次数。如果 $nums1[i] \leq x$ 且 $nums2[i] \leq y$，则不需要交换，否则如果 $nums1[i] \leq y$ 且 $nums2[i] \leq x$，则需要交换，否则无法同时满足两个条件，返回 $-1$。最后返回 $cnt$ 即可。

我们记两种情况的交换次数分别为 $a$ 和 $b$，如果 $a + b = -2$，则无法同时满足两个条件，返回 $-1$，否则返回 $\min(a, b + 1)$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        def f(x: int, y: int) -> int:
            cnt = 0
            for a, b in zip(nums1[:-1], nums2[:-1]):
                if a <= x and b <= y:
                    continue
                if not (a <= y and b <= x):
                    return -1
                cnt += 1
            return cnt

        a, b = f(nums1[-1], nums2[-1]), f(nums2[-1], nums1[-1])
        return -1 if a + b == -2 else min(a, b + 1)
```

#### Java

```java
class Solution {
    private int n;

    public int minOperations(int[] nums1, int[] nums2) {
        n = nums1.length;
        int a = f(nums1, nums2, nums1[n - 1], nums2[n - 1]);
        int b = f(nums1, nums2, nums2[n - 1], nums1[n - 1]);
        return a + b == -2 ? -1 : Math.min(a, b + 1);
    }

    private int f(int[] nums1, int[] nums2, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums1[i] <= x && nums2[i] <= y) {
                continue;
            }
            if (!(nums1[i] <= y && nums2[i] <= x)) {
                return -1;
            }
            ++cnt;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        auto f = [&](int x, int y) {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (nums1[i] <= x && nums2[i] <= y) {
                    continue;
                }
                if (!(nums1[i] <= y && nums2[i] <= x)) {
                    return -1;
                }
                ++cnt;
            }
            return cnt;
        };
        int a = f(nums1.back(), nums2.back());
        int b = f(nums2.back(), nums1.back());
        return a + b == -2 ? -1 : min(a, b + 1);
    }
};
```

#### Go

```go
func minOperations(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := func(x, y int) (cnt int) {
		for i, a := range nums1[:n-1] {
			b := nums2[i]
			if a <= x && b <= y {
				continue
			}
			if !(a <= y && b <= x) {
				return -1
			}
			cnt++
		}
		return
	}
	a, b := f(nums1[n-1], nums2[n-1]), f(nums2[n-1], nums1[n-1])
	if a+b == -2 {
		return -1
	}
	return min(a, b+1)
}
```

#### TypeScript

```ts
function minOperations(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const f = (x: number, y: number): number => {
        let cnt = 0;
        for (let i = 0; i < n - 1; ++i) {
            if (nums1[i] <= x && nums2[i] <= y) {
                continue;
            }
            if (!(nums1[i] <= y && nums2[i] <= x)) {
                return -1;
            }
            ++cnt;
        }
        return cnt;
    };
    const a = f(nums1.at(-1), nums2.at(-1));
    const b = f(nums2.at(-1), nums1.at(-1));
    return a + b === -2 ? -1 : Math.min(a, b + 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2935. 找出强数对的最大异或值 II](https://leetcode.cn/problems/maximum-strong-pair-xor-ii){#2935}

{{< tabs "2935" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ("children", "cnt")

    def __init__(self):
        self.children: List[Trie | None] = [None, None]
        self.cnt = 0

    def insert(self, x: int):
        node = self
        for i in range(20, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]
            node.cnt += 1

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(20, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1] and node.children[v ^ 1].cnt:
                ans |= 1 << i
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans

    def remove(self, x: int):
        node = self
        for i in range(20, -1, -1):
            v = x >> i & 1
            node = node.children[v]
            node.cnt -= 1


class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        nums.sort()
        tree = Trie()
        ans = i = 0
        for y in nums:
            tree.insert(y)
            while y > nums[i] * 2:
                tree.remove(nums[i])
                i += 1
            ans = max(ans, tree.search(y))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[2];
    private int cnt = 0;

    public Trie() {
    }

    public void insert(int x) {
        Trie node = this;
        for (int i = 20; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
            ++node.cnt;
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 20; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null && node.children[v ^ 1].cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }

    public void remove(int x) {
        Trie node = this;
        for (int i = 20; i >= 0; --i) {
            int v = x >> i & 1;
            node = node.children[v];
            --node.cnt;
        }
    }
}

class Solution {
    public int maximumStrongPairXor(int[] nums) {
        Arrays.sort(nums);
        Trie tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree.insert(y);
            while (y > nums[i] * 2) {
                tree.remove(nums[i++]);
            }
            ans = Math.max(ans, tree.search(y));
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie* children[2];
    int cnt;

    Trie()
        : cnt(0) {
        children[0] = nullptr;
        children[1] = nullptr;
    }

    void insert(int x) {
        Trie* node = this;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v] == nullptr) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
            ++node->cnt;
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v ^ 1] != nullptr && node->children[v ^ 1]->cnt > 0) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }

    void remove(int x) {
        Trie* node = this;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            node = node->children[v];
            --node->cnt;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie* tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree->insert(y);
            while (y > nums[i] * 2) {
                tree->remove(nums[i++]);
            }
            ans = max(ans, tree->search(y));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [2]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(x int) {
	node := t
	for i := 20; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
		node.cnt++
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 20; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v^1] != nil && node.children[v^1].cnt > 0 {
			ans |= 1 << uint(i)
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return ans
}

func (t *Trie) remove(x int) {
	node := t
	for i := 20; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		node = node.children[v]
		node.cnt--
	}
}

func maximumStrongPairXor(nums []int) (ans int) {
	sort.Ints(nums)
	tree := newTrie()
	i := 0
	for _, y := range nums {
		tree.insert(y)
		for ; y > nums[i]*2; i++ {
			tree.remove(nums[i])
		}
		ans = max(ans, tree.search(y))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: (Trie | null)[];
    cnt: number;

    constructor() {
        this.children = [null, null];
        this.cnt = 0;
    }

    insert(x: number): void {
        let node: Trie | null = this;
        for (let i = 20; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v] === null) {
                node.children[v] = new Trie();
            }
            node = node.children[v] as Trie;
            node.cnt++;
        }
    }

    search(x: number): number {
        let node: Trie | null = this;
        let ans = 0;
        for (let i = 20; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v ^ 1] !== null && (node.children[v ^ 1] as Trie).cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1] as Trie;
            } else {
                node = node.children[v] as Trie;
            }
        }
        return ans;
    }

    remove(x: number): void {
        let node: Trie | null = this;
        for (let i = 20; i >= 0; i--) {
            const v = (x >> i) & 1;
            node = node.children[v] as Trie;
            node.cnt--;
        }
    }
}

function maximumStrongPairXor(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const tree = new Trie();
    let ans = 0;
    let i = 0;

    for (const y of nums) {
        tree.insert(y);

        while (y > nums[i] * 2) {
            tree.remove(nums[i++]);
        }

        ans = Math.max(ans, tree.search(y));
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。如果一对整数 <code>x</code> 和 <code>y</code> 满足以下条件，则称其为 <strong>强数对</strong> ：</p>

<ul>
	<li><code>|x - y| &lt;= min(x, y)</code></li>
</ul>

<p>你需要从 <code>nums</code> 中选出两个整数，且满足：这两个整数可以形成一个强数对，并且它们的按位异或（<code>XOR</code>）值是在该数组所有强数对中的<strong> 最大值 </strong>。</p>

<p>返回数组 <code>nums</code> 所有可能的强数对中的<strong> 最大 </strong>异或值。</p>

<p><strong>注意</strong>，你可以选择同一个整数两次来形成一个强数对。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>7
<strong>解释：</strong>数组<code> nums </code>中有 11 个强数对：(1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) 和 (5, 5) 。
这些强数对中的最大异或值是 3 XOR 4 = 7 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,100]
<strong>输出：</strong>0
<strong>解释：</strong>数组<code> nums </code>中有 2 个强数对：(10, 10) 和 (100, 100) 。
这些强数对中的最大异或值是 10 XOR 10 = 0 ，数对 (100, 100) 的异或值也是 100 XOR 100 = 0 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [500,520,2500,3000]
<strong>输出：</strong>1020
<strong>解释：</strong>数组<code> nums </code>中有 6 个强数对：(500, 500), (500, 520), (520, 520), (2500, 2500), (2500, 3000) 和 (3000, 3000) 。
这些强数对中的最大异或值是 500 XOR 520 = 1020 ；另一个异或值非零的数对是 (5, 6) ，其异或值是 2500 XOR 3000 = 636 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2<sup>20</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 0-1 字典树

观察不等式 $|x - y| \leq \min(x, y)$，其中涉及到绝对值以及最小值，我们不妨假设 $x \leq y$，则有 $y - x \leq x$，即 $y \leq 2x$。我们可以从小到大枚举 $y$，那么 $x$ 必须满足不等式 $y \leq 2x$。

因此，我们对数组 $nums$ 进行排序，然后从小到大枚举 $y$，利用双指针维护一个窗口，使得窗口内的元素 $x$ 满足不等式 $y \leq 2x$。我们可以使用 0-1 字典树来维护窗口内的元素，这样我们就可以在 $O(1)$ 的时间内找到窗口内的最大异或值。每一次我们将 $y$ 加入到字典树中，同时将窗口左端点不满足不等式的元素移除，这样就可以保证窗口内的元素满足不等式 $y \leq 2x$。然后从字典树中查询最大异或值，更新答案。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n \times \log M)$。其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是数组 $nums$ 中的最大值，本题中 $M = 2^{20}$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ("children", "cnt")

    def __init__(self):
        self.children: List[Trie | None] = [None, None]
        self.cnt = 0

    def insert(self, x: int):
        node = self
        for i in range(20, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]
            node.cnt += 1

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(20, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1] and node.children[v ^ 1].cnt:
                ans |= 1 << i
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans

    def remove(self, x: int):
        node = self
        for i in range(20, -1, -1):
            v = x >> i & 1
            node = node.children[v]
            node.cnt -= 1


class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        nums.sort()
        tree = Trie()
        ans = i = 0
        for y in nums:
            tree.insert(y)
            while y > nums[i] * 2:
                tree.remove(nums[i])
                i += 1
            ans = max(ans, tree.search(y))
        return ans
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[2];
    private int cnt = 0;

    public Trie() {
    }

    public void insert(int x) {
        Trie node = this;
        for (int i = 20; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
            ++node.cnt;
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 20; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null && node.children[v ^ 1].cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }

    public void remove(int x) {
        Trie node = this;
        for (int i = 20; i >= 0; --i) {
            int v = x >> i & 1;
            node = node.children[v];
            --node.cnt;
        }
    }
}

class Solution {
    public int maximumStrongPairXor(int[] nums) {
        Arrays.sort(nums);
        Trie tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree.insert(y);
            while (y > nums[i] * 2) {
                tree.remove(nums[i++]);
            }
            ans = Math.max(ans, tree.search(y));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie* children[2];
    int cnt;

    Trie()
        : cnt(0) {
        children[0] = nullptr;
        children[1] = nullptr;
    }

    void insert(int x) {
        Trie* node = this;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v] == nullptr) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
            ++node->cnt;
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v ^ 1] != nullptr && node->children[v ^ 1]->cnt > 0) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }

    void remove(int x) {
        Trie* node = this;
        for (int i = 20; ~i; --i) {
            int v = (x >> i) & 1;
            node = node->children[v];
            --node->cnt;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie* tree = new Trie();
        int ans = 0, i = 0;
        for (int y : nums) {
            tree->insert(y);
            while (y > nums[i] * 2) {
                tree->remove(nums[i++]);
            }
            ans = max(ans, tree->search(y));
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [2]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(x int) {
	node := t
	for i := 20; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
		node.cnt++
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 20; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		if node.children[v^1] != nil && node.children[v^1].cnt > 0 {
			ans |= 1 << uint(i)
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return ans
}

func (t *Trie) remove(x int) {
	node := t
	for i := 20; i >= 0; i-- {
		v := (x >> uint(i)) & 1
		node = node.children[v]
		node.cnt--
	}
}

func maximumStrongPairXor(nums []int) (ans int) {
	sort.Ints(nums)
	tree := newTrie()
	i := 0
	for _, y := range nums {
		tree.insert(y)
		for ; y > nums[i]*2; i++ {
			tree.remove(nums[i])
		}
		ans = max(ans, tree.search(y))
	}
	return ans
}
```

#### TypeScript

```ts
class Trie {
    children: (Trie | null)[];
    cnt: number;

    constructor() {
        this.children = [null, null];
        this.cnt = 0;
    }

    insert(x: number): void {
        let node: Trie | null = this;
        for (let i = 20; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v] === null) {
                node.children[v] = new Trie();
            }
            node = node.children[v] as Trie;
            node.cnt++;
        }
    }

    search(x: number): number {
        let node: Trie | null = this;
        let ans = 0;
        for (let i = 20; i >= 0; i--) {
            const v = (x >> i) & 1;
            if (node.children[v ^ 1] !== null && (node.children[v ^ 1] as Trie).cnt > 0) {
                ans |= 1 << i;
                node = node.children[v ^ 1] as Trie;
            } else {
                node = node.children[v] as Trie;
            }
        }
        return ans;
    }

    remove(x: number): void {
        let node: Trie | null = this;
        for (let i = 20; i >= 0; i--) {
            const v = (x >> i) & 1;
            node = node.children[v] as Trie;
            node.cnt--;
        }
    }
}

function maximumStrongPairXor(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const tree = new Trie();
    let ans = 0;
    let i = 0;

    for (const y of nums) {
        tree.insert(y);

        while (y > nums[i] * 2) {
            tree.remove(nums[i++]);
        }

        ans = Math.max(ans, tree.search(y));
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2936. 包含相等值数字块的数量 🔒](https://leetcode.cn/problems/number-of-equal-numbers-blocks){#2936}

{{< tabs "2936" >}}

{{% tab "python" %}}
```python
# Definition for BigArray.
# class BigArray:
#     def at(self, index: long) -> int:
#         pass
#     def size(self) -> long:
#         pass
class Solution(object):
    def countBlocks(self, nums: Optional["BigArray"]) -> int:
        i, n = 0, nums.size()
        ans = 0
        while i < n:
            ans += 1
            x = nums.at(i)
            if i + 1 < n and nums.at(i + 1) != x:
                i += 1
            else:
                i += bisect_left(range(i, n), True, key=lambda j: nums.at(j) != x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for BigArray.
 * class BigArray {
 *     public BigArray(int[] elements);
 *     public int at(long index);
 *     public long size();
 * }
 */
class Solution {
    public int countBlocks(BigArray nums) {
        return f(nums, 0, nums.size() - 1);
    }

    private int f(BigArray nums, long l, long r) {
        if (nums.at(l) == nums.at(r)) {
            return 1;
        }
        long mid = (l + r) >> 1;
        int a = f(nums, l, mid);
        int b = f(nums, mid + 1, r);
        return a + b - (nums.at(mid) == nums.at(mid + 1) ? 1 : 0);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        using ll = long long;
        function<int(ll, ll)> f = [&](ll l, ll r) {
            if (nums->at(l) == nums->at(r)) {
                return 1;
            }
            ll mid = (l + r) >> 1;
            int a = f(l, mid);
            int b = f(mid + 1, r);
            return a + b - (nums->at(mid) == nums->at(mid + 1));
        };
        return f(0, nums->size() - 1);
    }
};
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for BigArray.
 * class BigArray {
 *     constructor(elements: number[]);
 *     public at(index: number): number;
 *     public size(): number;
 * }
 */
function countBlocks(nums: BigArray | null): number {
    const f = (l: number, r: number): number => {
        if (nums.at(l) === nums.at(r)) {
            return 1;
        }
        const mid = l + Math.floor((r - l) / 2);
        const a = f(l, mid);
        const b = f(mid + 1, r);
        return a + b - (nums.at(mid) === nums.at(mid + 1) ? 1 : 0);
    };
    return f(0, nums.size() - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>nums</code>，其&nbsp;<strong>下标从 0 开始</strong>。对于 <code>nums</code>，有以下性质：</p>

<ul>
	<li>所有相同值的元素都是相邻的。换句话说，如果存在两个下标 <code>i &lt; j</code>，使得 <code>nums[i] == nums[j]</code>，那么对于所有下标 <code>k</code>，满足 <code>i &lt; k &lt; j</code>，都有 <code>nums[k] == nums[i]</code>。</li>
</ul>

<p>由于 <code>nums</code> 是一个非常大的数组，这里提供了一个 <code>BigArray</code> 类的实例，该实例具有以下函数：</p>

<ul>
	<li><code>int at(long long index)</code>: 返回 <code>nums[i]</code> 的值。</li>
	<li><code>long long size()</code>: 返回 <code>nums.length</code>。</li>
</ul>

<p>让我们把数组分成 <strong>最大</strong>&nbsp;的块，使得每个块包含 <strong>相等的值</strong>。返回这些块的数量。</p>

<p><strong>请注意</strong>，如果要使用自定义测试测试解决方案，对于 <code>nums.length &gt; 10</code> 的测试行为是未定义的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,3,3,3,3]
<b>输出：</b>1
<b>解释：</b>这里只有一个块，也就是整个数组（因为所有数字都相等），即：[3,3,3,3,3]。因此答案是 1。 
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>nums = [1,1,1,3,9,9,9,2,10,10]
<b>输出：</b>5
<b>解释：</b>这里有 5 个块：
块号 1: [<u>1,1,1</u>,3,9,9,9,2,10,10]
块号 2: [1,1,1,<u>3</u>,9,9,9,2,10,10]
块号 3: [1,1,1,3,<u>9,9,9</u>,2,10,10]
块号 4: [1,1,1,3,9,9,9,<u>2</u>,10,10]
块号 5: [1,1,1,3,9,9,9,2,<u>10,10</u>]
因此答案是 5。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5,6,7]
<b>输出：</b>7
<b>解释：</b>由于所有数字都是不同的，这里有 7 个块，每个元素代表一个块。因此答案是 7。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>在生成的输入中所有相同值的元素是相邻的。</li>
	<li><code>nums</code> 的所有元素之和最多为<meta charset="UTF-8" />&nbsp;<code>10<sup>15</sup></code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们可以使用二分查找来找到每个块的右边界。具体地，我们从左到右遍历数组，对于每个下标 $i$，我们使用二分查找找到最小的下标 $j$，使得 $[i,j)$ 之间的所有元素都等于 $nums[i]$。然后我们将 $i$ 更新为 $j$，并继续遍历数组，直到 $i$ 大于等于数组的长度。

时间复杂度 $O(m \times \log n)$，其中 $m$ 是数组 $num$ 中不同元素的个数，而 $n$ 是数组 $num$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for BigArray.
# class BigArray:
#     def at(self, index: long) -> int:
#         pass
#     def size(self) -> long:
#         pass
class Solution(object):
    def countBlocks(self, nums: Optional["BigArray"]) -> int:
        i, n = 0, nums.size()
        ans = 0
        while i < n:
            ans += 1
            x = nums.at(i)
            if i + 1 < n and nums.at(i + 1) != x:
                i += 1
            else:
                i += bisect_left(range(i, n), True, key=lambda j: nums.at(j) != x)
        return ans
```

#### Java

```java
/**
 * Definition for BigArray.
 * class BigArray {
 *     public BigArray(int[] elements);
 *     public int at(long index);
 *     public long size();
 * }
 */
class Solution {
    public int countBlocks(BigArray nums) {
        int ans = 0;
        for (long i = 0, n = nums.size(); i < n; ++ans) {
            i = search(nums, i, n);
        }
        return ans;
    }

    private long search(BigArray nums, long l, long n) {
        long r = n;
        int x = nums.at(l);
        while (l < r) {
            long mid = (l + r) >> 1;
            if (nums.at(mid) != x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        int ans = 0;
        using ll = long long;
        ll n = nums->size();
        auto search = [&](ll l) {
            ll r = n;
            int x = nums->at(l);
            while (l < r) {
                ll mid = (l + r) >> 1;
                if (nums->at(mid) != x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        for (long long i = 0; i < n; ++ans) {
            i = search(i);
        }
        return ans;
    }
};
```

#### TypeScript

```ts
/**
 * Definition for BigArray.
 * class BigArray {
 *     constructor(elements: number[]);
 *     public at(index: number): number;
 *     public size(): number;
 * }
 */
function countBlocks(nums: BigArray | null): number {
    const n = nums.size();
    const search = (l: number): number => {
        let r = n;
        const x = nums.at(l);
        while (l < r) {
            const mid = l + Math.floor((r - l) / 2);
            if (nums.at(mid) !== x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    let ans = 0;
    for (let i = 0; i < n; ++ans) {
        i = search(i);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：分治

我们可以使用分治的方法来计算答案。具体地，我们将数组分成两个子数组，递归地计算每个子数组的答案，然后将答案合并起来。如果第一个子数组的最后一个元素和第二个子数组的第一个元素相等，那么我们需要将答案减一。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $num$ 的长度。

<!-- tabs:start -->

#### Java

```java
/**
 * Definition for BigArray.
 * class BigArray {
 *     public BigArray(int[] elements);
 *     public int at(long index);
 *     public long size();
 * }
 */
class Solution {
    public int countBlocks(BigArray nums) {
        return f(nums, 0, nums.size() - 1);
    }

    private int f(BigArray nums, long l, long r) {
        if (nums.at(l) == nums.at(r)) {
            return 1;
        }
        long mid = (l + r) >> 1;
        int a = f(nums, l, mid);
        int b = f(nums, mid + 1, r);
        return a + b - (nums.at(mid) == nums.at(mid + 1) ? 1 : 0);
    }
}
```

#### C++

```cpp
/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        using ll = long long;
        function<int(ll, ll)> f = [&](ll l, ll r) {
            if (nums->at(l) == nums->at(r)) {
                return 1;
            }
            ll mid = (l + r) >> 1;
            int a = f(l, mid);
            int b = f(mid + 1, r);
            return a + b - (nums->at(mid) == nums->at(mid + 1));
        };
        return f(0, nums->size() - 1);
    }
};
```

#### TypeScript

```ts
/**
 * Definition for BigArray.
 * class BigArray {
 *     constructor(elements: number[]);
 *     public at(index: number): number;
 *     public size(): number;
 * }
 */
function countBlocks(nums: BigArray | null): number {
    const f = (l: number, r: number): number => {
        if (nums.at(l) === nums.at(r)) {
            return 1;
        }
        const mid = l + Math.floor((r - l) / 2);
        const a = f(l, mid);
        const b = f(mid + 1, r);
        return a + b - (nums.at(mid) === nums.at(mid + 1) ? 1 : 0);
    };
    return f(0, nums.size() - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2937. 使三个字符串相等](https://leetcode.cn/problems/make-three-strings-equal){#2937}

{{< tabs "2937" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        s = len(s1) + len(s2) + len(s3)
        n = min(len(s1), len(s2), len(s3))
        for i in range(n):
            if not s1[i] == s2[i] == s3[i]:
                return -1 if i == 0 else s - 3 * i
        return s - 3 * n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        int s = s1.length() + s2.length() + s3.length();
        int n = Math.min(Math.min(s1.length(), s2.length()), s3.length());
        for (int i = 0; i < n; ++i) {
            if (!(s1.charAt(i) == s2.charAt(i) && s2.charAt(i) == s3.charAt(i))) {
                return i == 0 ? -1 : s - 3 * i;
            }
        }
        return s - 3 * n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int s = s1.size() + s2.size() + s3.size();
        int n = min({s1.size(), s2.size(), s3.size()});
        for (int i = 0; i < n; ++i) {
            if (!(s1[i] == s2[i] && s2[i] == s3[i])) {
                return i == 0 ? -1 : s - 3 * i;
            }
        }
        return s - 3 * n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMinimumOperations(s1 string, s2 string, s3 string) int {
	s := len(s1) + len(s2) + len(s3)
	n := min(len(s1), len(s2), len(s3))
	for i := range s1[:n] {
		if !(s1[i] == s2[i] && s2[i] == s3[i]) {
			if i == 0 {
				return -1
			}
			return s - 3*i
		}
	}
	return s - 3*n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinimumOperations(s1: string, s2: string, s3: string): number {
    const s = s1.length + s2.length + s3.length;
    const n = Math.min(s1.length, s2.length, s3.length);
    for (let i = 0; i < n; ++i) {
        if (!(s1[i] === s2[i] && s2[i] === s3[i])) {
            return i === 0 ? -1 : s - 3 * i;
        }
    }
    return s - 3 * n;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你三个字符串 <code>s1</code>、<code>s2</code> 和 <code>s3</code>。 你可以根据需要对这三个字符串执行以下操作 <strong>任意次数</strong> <!-- notionvc: b5178de7-3318-4129-b7d9-726b47e90621 -->。</p>

<p>在每次操作中，你可以选择其中一个长度至少为 <code>2</code> 的字符串 <!-- notionvc: 3342ac46-33c8-4010-aacd-e58678ce31ef --> 并删除其 <strong>最右位置上</strong> 的字符。</p>

<p>如果存在某种方法能够使这三个字符串相等，请返回使它们相等所需的 <strong>最小</strong> 操作次数；否则，返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "abc"，s2 = "abb"，s3 = "ab"
<strong>输出：</strong>2
<strong>解释：</strong>对 s1 和 s2 进行一次操作后，可以得到三个相等的字符串。
可以证明，不可能用少于两次操作使它们相等。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "dac"，s2 = "bac"，s3 = "cac"
<strong>输出：</strong>-1
<strong>解释：</strong>因为 s1 和 s2 的最左位置上的字母<!-- notionvc: 47239f7c-eec1-49f8-af79-c206ec88cb07 -->不相等，所以无论进行多少次操作，它们都不可能相等。因此答案是 -1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length, s3.length &lt;= 100</code></li>
	<li><code>s1</code>、<code>s2</code> 和 <code>s3</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

根据题目描述，我们知道，如果删除字符后的三个字符串相等，那么它们存在一个长度大于 $1$ 的公共前缀。因此，我们可以枚举公共前缀的位置 $i$，如果当前下标 $i$ 对应的三个字符不完全相等，那么公共前缀长度为 $i$，此时，我们判断 $i$ 是否为 $0$，若是，返回 $-1$，否则返回 $s - 3 \times i$，其中 $s$ 为三个字符串的长度和。

时间复杂度 $O(n)$，其中 $n$ 为三个字符串的最小长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        s = len(s1) + len(s2) + len(s3)
        n = min(len(s1), len(s2), len(s3))
        for i in range(n):
            if not s1[i] == s2[i] == s3[i]:
                return -1 if i == 0 else s - 3 * i
        return s - 3 * n
```

#### Java

```java
class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        int s = s1.length() + s2.length() + s3.length();
        int n = Math.min(Math.min(s1.length(), s2.length()), s3.length());
        for (int i = 0; i < n; ++i) {
            if (!(s1.charAt(i) == s2.charAt(i) && s2.charAt(i) == s3.charAt(i))) {
                return i == 0 ? -1 : s - 3 * i;
            }
        }
        return s - 3 * n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int s = s1.size() + s2.size() + s3.size();
        int n = min({s1.size(), s2.size(), s3.size()});
        for (int i = 0; i < n; ++i) {
            if (!(s1[i] == s2[i] && s2[i] == s3[i])) {
                return i == 0 ? -1 : s - 3 * i;
            }
        }
        return s - 3 * n;
    }
};
```

#### Go

```go
func findMinimumOperations(s1 string, s2 string, s3 string) int {
	s := len(s1) + len(s2) + len(s3)
	n := min(len(s1), len(s2), len(s3))
	for i := range s1[:n] {
		if !(s1[i] == s2[i] && s2[i] == s3[i]) {
			if i == 0 {
				return -1
			}
			return s - 3*i
		}
	}
	return s - 3*n
}
```

#### TypeScript

```ts
function findMinimumOperations(s1: string, s2: string, s3: string): number {
    const s = s1.length + s2.length + s3.length;
    const n = Math.min(s1.length, s2.length, s3.length);
    for (let i = 0; i < n; ++i) {
        if (!(s1[i] === s2[i] && s2[i] === s3[i])) {
            return i === 0 ? -1 : s - 3 * i;
        }
    }
    return s - 3 * n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2938. 区分黑球与白球](https://leetcode.cn/problems/separate-black-and-white-balls){#2938}

{{< tabs "2938" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSteps(self, s: str) -> int:
        n = len(s)
        ans = cnt = 0
        for i in range(n - 1, -1, -1):
            if s[i] == '1':
                cnt += 1
                ans += n - i - cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumSteps(String s) {
        long ans = 0;
        int cnt = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == '1') {
                ++cnt;
                ans += n - i - cnt;
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
    long long minimumSteps(string s) {
        long long ans = 0;
        int cnt = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                ++cnt;
                ans += n - i - cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSteps(s string) (ans int64) {
	n := len(s)
	cnt := 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == '1' {
			cnt++
			ans += int64(n - i - cnt)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSteps(s: string): number {
    const n = s.length;
    let [ans, cnt] = [0, 0];
    for (let i = n - 1; ~i; --i) {
        if (s[i] === '1') {
            ++cnt;
            ans += n - i - cnt;
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

<p>桌子上有 <code>n</code> 个球，每个球的颜色不是黑色，就是白色。</p>

<p>给你一个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的二进制字符串 <code>s</code>，其中 <code>1</code> 和 <code>0</code> 分别代表黑色和白色的球。</p>

<p>在每一步中，你可以选择两个相邻的球并交换它们。</p>

<p>返回「将所有黑色球都移到右侧，所有白色球都移到左侧所需的 <strong>最小步数</strong>」。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "101"
<strong>输出：</strong>1
<strong>解释：</strong>我们可以按以下方式将所有黑色球移到右侧：
- 交换 s[0] 和 s[1]，s = "011"。
最开始，1 没有都在右侧，需要至少 1 步将其移到右侧。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "100"
<strong>输出：</strong>2
<strong>解释：</strong>我们可以按以下方式将所有黑色球移到右侧：
- 交换 s[0] 和 s[1]，s = "010"。
- 交换 s[1] 和 s[2]，s = "001"。
可以证明所需的最小步数为 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0111"
<strong>输出：</strong>0
<strong>解释：</strong>所有黑色球都已经在右侧。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 不是 <code>'0'</code>，就是 <code>'1'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数模拟

我们考虑将所有的 $1$ 移到最右边，用一个变量 $cnt$ 记录当前已经移动到最右边的 $1$ 的个数，用一个变量 $ans$ 记录移动的次数。

我们从右往左遍历字符串，如果当前位置是 $1$，那么我们将 $cnt$ 加一，同时将 $n - i - cnt$ 加到 $ans$ 中，其中 $n$ 是字符串的长度。最后返回 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSteps(self, s: str) -> int:
        n = len(s)
        ans = cnt = 0
        for i in range(n - 1, -1, -1):
            if s[i] == '1':
                cnt += 1
                ans += n - i - cnt
        return ans
```

#### Java

```java
class Solution {
    public long minimumSteps(String s) {
        long ans = 0;
        int cnt = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == '1') {
                ++cnt;
                ans += n - i - cnt;
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
    long long minimumSteps(string s) {
        long long ans = 0;
        int cnt = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                ++cnt;
                ans += n - i - cnt;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumSteps(s string) (ans int64) {
	n := len(s)
	cnt := 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == '1' {
			cnt++
			ans += int64(n - i - cnt)
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumSteps(s: string): number {
    const n = s.length;
    let [ans, cnt] = [0, 0];
    for (let i = n - 1; ~i; --i) {
        if (s[i] === '1') {
            ++cnt;
            ans += n - i - cnt;
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

# [2939. 最大异或乘积](https://leetcode.cn/problems/maximum-xor-product){#2939}

{{< tabs "2939" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        mod = 10**9 + 7
        ax, bx = (a >> n) << n, (b >> n) << n
        for i in range(n - 1, -1, -1):
            x = a >> i & 1
            y = b >> i & 1
            if x == y:
                ax |= 1 << i
                bx |= 1 << i
            elif ax > bx:
                bx |= 1 << i
            else:
                ax |= 1 << i
        return ax * bx % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumXorProduct(long a, long b, int n) {
        final int mod = (int) 1e9 + 7;
        long ax = (a >> n) << n;
        long bx = (b >> n) << n;
        for (int i = n - 1; i >= 0; --i) {
            long x = a >> i & 1;
            long y = b >> i & 1;
            if (x == y) {
                ax |= 1L << i;
                bx |= 1L << i;
            } else if (ax < bx) {
                ax |= 1L << i;
            } else {
                bx |= 1L << i;
            }
        }
        ax %= mod;
        bx %= mod;
        return (int) (ax * bx % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const int mod = 1e9 + 7;
        long long ax = (a >> n) << n, bx = (b >> n) << n;
        for (int i = n - 1; ~i; --i) {
            int x = a >> i & 1, y = b >> i & 1;
            if (x == y) {
                ax |= 1LL << i;
                bx |= 1LL << i;
            } else if (ax < bx) {
                ax |= 1LL << i;
            } else {
                bx |= 1LL << i;
            }
        }
        ax %= mod;
        bx %= mod;
        return ax * bx % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumXorProduct(a int64, b int64, n int) int {
	const mod int64 = 1e9 + 7
	ax := (a >> n) << n
	bx := (b >> n) << n
	for i := n - 1; i >= 0; i-- {
		x, y := (a>>i)&1, (b>>i)&1
		if x == y {
			ax |= 1 << i
			bx |= 1 << i
		} else if ax < bx {
			ax |= 1 << i
		} else {
			bx |= 1 << i
		}
	}
	ax %= mod
	bx %= mod
	return int(ax * bx % mod)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumXorProduct(a: number, b: number, n: number): number {
    const mod = BigInt(1e9 + 7);
    let ax = (BigInt(a) >> BigInt(n)) << BigInt(n);
    let bx = (BigInt(b) >> BigInt(n)) << BigInt(n);
    for (let i = BigInt(n - 1); ~i; --i) {
        const x = (BigInt(a) >> i) & 1n;
        const y = (BigInt(b) >> i) & 1n;
        if (x === y) {
            ax |= 1n << i;
            bx |= 1n << i;
        } else if (ax < bx) {
            ax |= 1n << i;
        } else {
            bx |= 1n << i;
        }
    }
    ax %= mod;
    bx %= mod;
    return Number((ax * bx) % mod);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你三个整数&nbsp;<code>a</code>&nbsp;，<code>b</code>&nbsp;和&nbsp;<code>n</code>&nbsp;，请你返回&nbsp;<code>(a XOR x) * (b XOR x)</code>&nbsp;的&nbsp;<strong>最大值</strong>&nbsp;且 <code>x</code>&nbsp;需要满足 <code>0 &lt;= x &lt; 2<sup>n</sup></code>。</p>

<p>由于答案可能会很大，返回它对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;<strong>取余</strong>&nbsp;后的结果。</p>

<p><strong>注意</strong>，<code>XOR</code>&nbsp;是按位异或操作。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>a = 12, b = 5, n = 4
<b>输出：</b>98
<b>解释：</b>当 x = 2 时，(a XOR x) = 14 且 (b XOR x) = 7 。所以，(a XOR x) * (b XOR x) = 98 。
98 是所有满足 0 &lt;= x &lt; 2<sup>n </sup>中 (a XOR x) * (b XOR x) 的最大值。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>a = 6, b = 7 , n = 5
<b>输出：</b>930
<b>解释：</b>当 x = 25 时，(a XOR x) = 31 且 (b XOR x) = 30 。所以，(a XOR x) * (b XOR x) = 930 。
930 是所有满足 0 &lt;= x &lt; 2<sup>n </sup>中 (a XOR x) * (b XOR x) 的最大值。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>a = 1, b = 6, n = 3
<b>输出：</b>12
<b>解释： </b>当 x = 5 时，(a XOR x) = 4 且 (b XOR x) = 3 。所以，(a XOR x) * (b XOR x) = 12 。
12 是所有满足 0 &lt;= x &lt; 2<sup>n </sup>中 (a XOR x) * (b XOR x) 的最大值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= a, b &lt; 2<sup>50</sup></code></li>
	<li><code>0 &lt;= n &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 位运算

根据题目描述，我们可以给 $a$ 和 $b$ 在二进制下 $[0..n)$ 位上同时分配一个数字，最终使得 $a$ 和 $b$ 的乘积最大。

因此，我们首先提取 $a$ 和 $b$ 高于 $n$ 位的部分，分别记为 $ax$ 和 $bx$。

接下来，从大到小考虑 $[0..n)$ 位上的每一位，我们将 $a$ 和 $b$ 的当前位分别记为 $x$ 和 $y$。

如果 $x = y$，那么我们可以将 $ax$ 和 $bx$ 的当前位同时置为 $1$，因此，我们更新 $ax = ax \mid 1 << i$ 和 $bx = bx \mid 1 << i$。否则，如果 $ax \lt bx$，要使得最终的乘积最大，我们应该让 $ax$ 的当前位置为 $1$，否则我们可以将 $bx$ 的当前位置为 $1$。

最后，我们返回 $ax \times bx \bmod (10^9 + 7)$ 即为答案。

时间复杂度 $O(n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        mod = 10**9 + 7
        ax, bx = (a >> n) << n, (b >> n) << n
        for i in range(n - 1, -1, -1):
            x = a >> i & 1
            y = b >> i & 1
            if x == y:
                ax |= 1 << i
                bx |= 1 << i
            elif ax > bx:
                bx |= 1 << i
            else:
                ax |= 1 << i
        return ax * bx % mod
```

#### Java

```java
class Solution {
    public int maximumXorProduct(long a, long b, int n) {
        final int mod = (int) 1e9 + 7;
        long ax = (a >> n) << n;
        long bx = (b >> n) << n;
        for (int i = n - 1; i >= 0; --i) {
            long x = a >> i & 1;
            long y = b >> i & 1;
            if (x == y) {
                ax |= 1L << i;
                bx |= 1L << i;
            } else if (ax < bx) {
                ax |= 1L << i;
            } else {
                bx |= 1L << i;
            }
        }
        ax %= mod;
        bx %= mod;
        return (int) (ax * bx % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const int mod = 1e9 + 7;
        long long ax = (a >> n) << n, bx = (b >> n) << n;
        for (int i = n - 1; ~i; --i) {
            int x = a >> i & 1, y = b >> i & 1;
            if (x == y) {
                ax |= 1LL << i;
                bx |= 1LL << i;
            } else if (ax < bx) {
                ax |= 1LL << i;
            } else {
                bx |= 1LL << i;
            }
        }
        ax %= mod;
        bx %= mod;
        return ax * bx % mod;
    }
};
```

#### Go

```go
func maximumXorProduct(a int64, b int64, n int) int {
	const mod int64 = 1e9 + 7
	ax := (a >> n) << n
	bx := (b >> n) << n
	for i := n - 1; i >= 0; i-- {
		x, y := (a>>i)&1, (b>>i)&1
		if x == y {
			ax |= 1 << i
			bx |= 1 << i
		} else if ax < bx {
			ax |= 1 << i
		} else {
			bx |= 1 << i
		}
	}
	ax %= mod
	bx %= mod
	return int(ax * bx % mod)
}
```

#### TypeScript

```ts
function maximumXorProduct(a: number, b: number, n: number): number {
    const mod = BigInt(1e9 + 7);
    let ax = (BigInt(a) >> BigInt(n)) << BigInt(n);
    let bx = (BigInt(b) >> BigInt(n)) << BigInt(n);
    for (let i = BigInt(n - 1); ~i; --i) {
        const x = (BigInt(a) >> i) & 1n;
        const y = (BigInt(b) >> i) & 1n;
        if (x === y) {
            ax |= 1n << i;
            bx |= 1n << i;
        } else if (ax < bx) {
            ax |= 1n << i;
        } else {
            bx |= 1n << i;
        }
    }
    ax %= mod;
    bx %= mod;
    return Number((ax * bx) % mod);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
