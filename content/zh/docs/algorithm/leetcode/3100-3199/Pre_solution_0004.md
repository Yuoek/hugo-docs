---
title: "3130_找出所有稳定的二进制数组 II"
date: 2025-10-08T18:40:09+08:00
weight: 4
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希函数, 哈希表, 字符串, 排序, 数组, 枚举, 滑动窗口, 计数, 贪心]
---

{{< markmap >}}
### [3130_找出所有稳定的二进制数组 II](#3130)
#### [动态规划](#3130)
#### [前缀和](#3130)
### [3131_找出与数组相加的整数 I](#3131)
#### [数组](#3131)
### [3132_找出与数组相加的整数 II](#3132)
#### [数组](#3132)
#### [双指针](#3132)
#### [枚举](#3132)
#### [排序](#3132)
### [3133_数组最后一个元素的最小值](#3133)
#### [位运算](#3133)
### [3134_找出唯一性数组的中位数](#3134)
#### [数组](#3134)
#### [哈希表](#3134)
#### [二分查找](#3134)
#### [滑动窗口](#3134)
### [3135_通过添加或删除结尾字符来同化字符串 🔒](#3135)
#### [字符串](#3135)
#### [二分查找](#3135)
#### [动态规划](#3135)
#### [滑动窗口](#3135)
#### [哈希函数](#3135)
### [3136_有效单词](#3136)
#### [字符串](#3136)
### [3137_K 周期字符串需要的最少操作次数](#3137)
#### [哈希表](#3137)
#### [字符串](#3137)
#### [计数](#3137)
### [3138_同位字符串连接的最小长度](#3138)
#### [哈希表](#3138)
#### [字符串](#3138)
#### [计数](#3138)
### [3139_使数组中所有元素相等的最小开销](#3139)
#### [贪心](#3139)
#### [数组](#3139)
#### [枚举](#3139)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3130_找出所有稳定的二进制数组 II
___
#### 动态规划
___
#### 前缀和
---
### 3131_找出与数组相加的整数 I
___
#### 数组
---
### 3132_找出与数组相加的整数 II
___
#### 数组
___
#### 双指针
___
#### 枚举
___
#### 排序
---
### 3133_数组最后一个元素的最小值
___
#### 位运算
---
### 3134_找出唯一性数组的中位数
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 滑动窗口
---
### 3135_通过添加或删除结尾字符来同化字符串 🔒
___
#### 字符串
___
#### 二分查找
___
#### 动态规划
___
#### 滑动窗口
___
#### 哈希函数
---
### 3136_有效单词
___
#### 字符串
---
### 3137_K 周期字符串需要的最少操作次数
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 3138_同位字符串连接的最小长度
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 3139_使数组中所有元素相等的最小开销
___
#### 贪心
___
#### 数组
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希函数 |
| 哈希表 | 字符串 | 排序 |
| 数组 | 枚举 | 滑动窗口 |
| 计数 | 贪心 |  |

# [3130. 找出所有稳定的二进制数组 II](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-ii){#3130}

{{< tabs "3130" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7
        f = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        for i in range(1, min(limit, zero) + 1):
            f[i][0][0] = 1
        for j in range(1, min(limit, one) + 1):
            f[0][j][1] = 1
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                x = 0 if i - limit - 1 < 0 else f[i - limit - 1][j][1]
                y = 0 if j - limit - 1 < 0 else f[i][j - limit - 1][0]
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x) % mod
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y) % mod
        return sum(f[zero][one]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfStableArrays(int zero, int one, int limit) {
        final int mod = (int) 1e9 + 7;
        long[][][] f = new long[zero + 1][one + 1][2];
        for (int i = 1; i <= Math.min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= Math.min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                long x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                long y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (int) ((f[zero][one][0] + f[zero][one][1]) % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll f[zero + 1][one + 1][2];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                ll x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                ll y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfStableArrays(zero int, one int, limit int) int {
	const mod int = 1e9 + 7
	f := make([][][2]int, zero+1)
	for i := range f {
		f[i] = make([][2]int, one+1)
	}
	for i := 1; i <= min(zero, limit); i++ {
		f[i][0][0] = 1
	}
	for j := 1; j <= min(one, limit); j++ {
		f[0][j][1] = 1
	}
	for i := 1; i <= zero; i++ {
		for j := 1; j <= one; j++ {
			f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) % mod
			if i-limit-1 >= 0 {
				f[i][j][0] = (f[i][j][0] - f[i-limit-1][j][1] + mod) % mod
			}
			f[i][j][1] = (f[i][j-1][0] + f[i][j-1][1]) % mod
			if j-limit-1 >= 0 {
				f[i][j][1] = (f[i][j][1] - f[i][j-limit-1][0] + mod) % mod
			}
		}
	}
	return (f[zero][one][0] + f[zero][one][1]) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfStableArrays(zero: number, one: number, limit: number): number {
    const mod = 1e9 + 7;
    const f: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 1; i <= Math.min(limit, zero); i++) {
        f[i][0][0] = 1;
    }
    for (let j = 1; j <= Math.min(limit, one); j++) {
        f[0][j][1] = 1;
    }

    for (let i = 1; i <= zero; i++) {
        for (let j = 1; j <= one; j++) {
            const x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
            const y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
            f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
            f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
        }
    }

    return (f[zero][one][0] + f[zero][one][1]) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你 3 个正整数&nbsp;<code>zero</code>&nbsp;，<code>one</code>&nbsp;和&nbsp;<code>limit</code>&nbsp;。</p>

<p>一个 <span data-keyword="binary-array">二进制数组</span> <code>arr</code> 如果满足以下条件，那么我们称它是 <strong>稳定的</strong> ：</p>

<ul>
	<li>0 在&nbsp;<code>arr</code>&nbsp;中出现次数 <strong>恰好</strong>&nbsp;为<strong>&nbsp;</strong><code>zero</code>&nbsp;。</li>
	<li>1 在&nbsp;<code>arr</code>&nbsp;中出现次数 <strong>恰好</strong>&nbsp;为&nbsp;<code>one</code>&nbsp;。</li>
	<li><code>arr</code> 中每个长度超过 <code>limit</code>&nbsp;的 <span data-keyword="subarray-nonempty">子数组</span> 都 <strong>同时</strong> 包含 0 和 1 。</li>
</ul>

<p>请你返回 <strong>稳定</strong>&nbsp;二进制数组的 <em>总</em> 数目。</p>

<p>由于答案可能很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<b>取余</b>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>zero = 1, one = 1, limit = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>两个稳定的二进制数组为&nbsp;<code>[1,0]</code> 和&nbsp;<code>[0,1]</code>&nbsp;，两个数组都有一个 0 和一个 1 ，且没有子数组长度大于 2 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">zero = 1, one = 2, limit = 1</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>唯一稳定的二进制数组是&nbsp;<code>[1,0,1]</code>&nbsp;。</p>

<p>二进制数组&nbsp;<code>[1,1,0]</code> 和&nbsp;<code>[0,1,1]</code>&nbsp;都有长度为 2 且元素全都相同的子数组，所以它们不稳定。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>zero = 3, one = 3, limit = 2</span></p>

<p><span class="example-io"><b>输出：</b>14</span></p>

<p><strong>解释：</strong></p>

<p>所有稳定的二进制数组包括&nbsp;<code>[0,0,1,0,1,1]</code>&nbsp;，<code>[0,0,1,1,0,1]</code>&nbsp;，<code>[0,1,0,0,1,1]</code>&nbsp;，<code>[0,1,0,1,0,1]</code>&nbsp;，<code>[0,1,0,1,1,0]</code>&nbsp;，<code>[0,1,1,0,0,1]</code>&nbsp;，<code>[0,1,1,0,1,0]</code>&nbsp;，<code>[1,0,0,1,0,1]</code>&nbsp;，<code>[1,0,0,1,1,0]</code>&nbsp;，<code>[1,0,1,0,0,1]</code>&nbsp;，<code>[1,0,1,0,1,0]</code>&nbsp;，<code>[1,0,1,1,0,0]</code>&nbsp;，<code>[1,1,0,0,1,0]</code>&nbsp;和&nbsp;<code>[1,1,0,1,0,0]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= zero, one, limit &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, k)$ 表示还剩下 $i$ 个 $0$ 和 $j$ 个 $1$ 且接下来待填的数字是 $k$ 的情况下，满足题目条件的稳定二进制数组的个数。那么答案就是 $dfs(zero, one, 0) + dfs(zero, one, 1)$。

函数 $dfs(i, j, k)$ 的计算过程如下：

-   如果 $i \lt 0$ 或 $j \lt 0$，返回 $0$。
-   如果 $i = 0$，那么当 $k = 1$ 且 $j \leq \textit{limit}$ 时返回 $1$，否则返回 $0$。
-   如果 $j = 0$，那么当 $k = 0$ 且 $i \leq \textit{limit}$ 时返回 $1$，否则返回 $0$。
-   如果 $k = 0$，我们考虑前一个数字是 $0$ 的情况 $dfs(i - 1, j, 0)$ 和前一个数字是 $1$ 的情况 $dfs(i - 1, j, 1)$，如果前一个数是 $0$，那么有可能使得子数组中有超过 $\textit{limit}$ 个 $0$，即不允许出现倒数第 $\textit{limit} + 1$ 个数是 $1$ 的情况，所以我们要减去这种情况，即 $dfs(i - \textit{limit} - 1, j, 1)$。
-   如果 $k = 1$，我们考虑前一个数字是 $0$ 的情况 $dfs(i, j - 1, 0)$ 和前一个数字是 $1$ 的情况 $dfs(i, j - 1, 1)$，如果前一个数是 $1$，那么有可能使得子数组中有超过 $\textit{limit}$ 个 $1$，即不允许出现倒数第 $\textit{limit} + 1$ 个数是 $0$ 的情况，所以我们要减去这种情况，即 $dfs(i, j - \textit{limit} - 1, 0)$。

为了避免重复计算，我们使用记忆化搜索的方法。

时间复杂度 $O(zero \times one)$，空间复杂度 $O(zero \times one)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i == 0:
                return int(k == 1 and j <= limit)
            if j == 0:
                return int(k == 0 and i <= limit)
            if k == 0:
                return (
                    dfs(i - 1, j, 0)
                    + dfs(i - 1, j, 1)
                    - (0 if i - limit - 1 < 0 else dfs(i - limit - 1, j, 1))
                )
            return (
                dfs(i, j - 1, 0)
                + dfs(i, j - 1, 1)
                - (0 if j - limit - 1 < 0 else dfs(i, j - limit - 1, 0))
            )

        mod = 10**9 + 7
        ans = (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;
    private Long[][][] f;
    private int limit;

    public int numberOfStableArrays(int zero, int one, int limit) {
        f = new Long[zero + 1][one + 1][2];
        this.limit = limit;
        return (int) ((dfs(zero, one, 0) + dfs(zero, one, 1)) % mod);
    }

    private long dfs(int i, int j, int k) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i == 0) {
            return k == 1 && j <= limit ? 1 : 0;
        }
        if (j == 0) {
            return k == 0 && i <= limit ? 1 : 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        if (k == 0) {
            f[i][j][k]
                = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1) - dfs(i - limit - 1, j, 1) + mod) % mod;
        } else {
            f[i][j][k]
                = (dfs(i, j - 1, 0) + dfs(i, j - 1, 1) - dfs(i, j - limit - 1, 0) + mod) % mod;
        }
        return f[i][j][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        vector<vector<array<ll, 2>>> f = vector<vector<array<ll, 2>>>(zero + 1, vector<array<ll, 2>>(one + 1, {-1, -1}));
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> ll {
            if (i < 0 || j < 0) {
                return 0;
            }
            if (i == 0) {
                return k == 1 && j <= limit;
            }
            if (j == 0) {
                return k == 0 && i <= limit;
            }
            ll& res = f[i][j][k];
            if (res != -1) {
                return res;
            }
            if (k == 0) {
                res = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1) - dfs(i - limit - 1, j, 1) + mod) % mod;
            } else {
                res = (dfs(i, j - 1, 0) + dfs(i, j - 1, 1) - dfs(i, j - limit - 1, 0) + mod) % mod;
            }
            return res;
        };
        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod;
    }
};
```

#### Go

```go
func numberOfStableArrays(zero int, one int, limit int) int {
	const mod int = 1e9 + 7
	f := make([][][2]int, zero+1)
	for i := range f {
		f[i] = make([][2]int, one+1)
		for j := range f[i] {
			f[i][j] = [2]int{-1, -1}
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i < 0 || j < 0 {
			return 0
		}
		if i == 0 {
			if k == 1 && j <= limit {
				return 1
			}
			return 0
		}
		if j == 0 {
			if k == 0 && i <= limit {
				return 1
			}
			return 0
		}
		res := &f[i][j][k]
		if *res != -1 {
			return *res
		}
		if k == 0 {
			*res = (dfs(i-1, j, 0) + dfs(i-1, j, 1) - dfs(i-limit-1, j, 1) + mod) % mod
		} else {
			*res = (dfs(i, j-1, 0) + dfs(i, j-1, 1) - dfs(i, j-limit-1, 0) + mod) % mod
		}
		return *res
	}
	return (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以将方法一的记忆化搜索转换为动态规划。

我们定义 $f[i][j][k]$ 表示使用 $i$ 个 $0$ 和 $j$ 个 $1$ 且最后一个数字是 $k$ 的稳定二进制数组的个数。那么答案就是 $f[zero][one][0] + f[zero][one][1]$。

初始时，我们有 $f[i][0][0] = 1$，其中 $1 \leq i \leq \min(\textit{limit}, \textit{zero})$；有 $f[0][j][1] = 1$，其中 $1 \leq j \leq \min(\textit{limit}, \textit{one})$。

状态转移方程如下：

-   $f[i][j][0] = f[i - 1][j][0] + f[i - 1][j][1] - f[i - \textit{limit} - 1][j][1]$。
-   $f[i][j][1] = f[i][j - 1][0] + f[i][j - 1][1] - f[i][j - \textit{limit} - 1][0]$。

时间复杂度 $O(zero \times one)$，空间复杂度 $O(zero \times one)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7
        f = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        for i in range(1, min(limit, zero) + 1):
            f[i][0][0] = 1
        for j in range(1, min(limit, one) + 1):
            f[0][j][1] = 1
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                x = 0 if i - limit - 1 < 0 else f[i - limit - 1][j][1]
                y = 0 if j - limit - 1 < 0 else f[i][j - limit - 1][0]
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x) % mod
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y) % mod
        return sum(f[zero][one]) % mod
```

#### Java

```java
class Solution {
    public int numberOfStableArrays(int zero, int one, int limit) {
        final int mod = (int) 1e9 + 7;
        long[][][] f = new long[zero + 1][one + 1][2];
        for (int i = 1; i <= Math.min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= Math.min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                long x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                long y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (int) ((f[zero][one][0] + f[zero][one][1]) % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll f[zero + 1][one + 1][2];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                ll x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                ll y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % mod;
    }
};
```

#### Go

```go
func numberOfStableArrays(zero int, one int, limit int) int {
	const mod int = 1e9 + 7
	f := make([][][2]int, zero+1)
	for i := range f {
		f[i] = make([][2]int, one+1)
	}
	for i := 1; i <= min(zero, limit); i++ {
		f[i][0][0] = 1
	}
	for j := 1; j <= min(one, limit); j++ {
		f[0][j][1] = 1
	}
	for i := 1; i <= zero; i++ {
		for j := 1; j <= one; j++ {
			f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) % mod
			if i-limit-1 >= 0 {
				f[i][j][0] = (f[i][j][0] - f[i-limit-1][j][1] + mod) % mod
			}
			f[i][j][1] = (f[i][j-1][0] + f[i][j-1][1]) % mod
			if j-limit-1 >= 0 {
				f[i][j][1] = (f[i][j][1] - f[i][j-limit-1][0] + mod) % mod
			}
		}
	}
	return (f[zero][one][0] + f[zero][one][1]) % mod
}
```

#### TypeScript

```ts
function numberOfStableArrays(zero: number, one: number, limit: number): number {
    const mod = 1e9 + 7;
    const f: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 1; i <= Math.min(limit, zero); i++) {
        f[i][0][0] = 1;
    }
    for (let j = 1; j <= Math.min(limit, one); j++) {
        f[0][j][1] = 1;
    }

    for (let i = 1; i <= zero; i++) {
        for (let j = 1; j <= one; j++) {
            const x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
            const y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
            f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
            f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
        }
    }

    return (f[zero][one][0] + f[zero][one][1]) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3131. 找出与数组相加的整数 I](https://leetcode.cn/problems/find-the-integer-added-to-array-i){#3131}

{{< tabs "3131" >}}

{{% tab "python" %}}
```python
class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        return min(nums2) - min(nums1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        return Arrays.stream(nums2).min().getAsInt() - Arrays.stream(nums1).min().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addedInteger(nums1 []int, nums2 []int) int {
	return slices.Min(nums2) - slices.Min(nums1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addedInteger(nums1: number[], nums2: number[]): number {
    return Math.min(...nums2) - Math.min(...nums1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个长度相等的数组 <code>nums1</code> 和 <code>nums2</code>。</p>

<p>数组 <code>nums1</code> 中的每个元素都与变量 <code>x</code> 所表示的整数相加。如果 <code>x</code> 为负数，则表现为元素值的减少。</p>

<p>在与 <code>x</code> 相加后，<code>nums1</code> 和 <code>nums2</code> <strong>相等</strong> 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 <strong>相等</strong> 。</p>

<p>返回整数 <code>x</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [2,6,4], nums2 = [9,7,5]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">3</span></p>

<p><strong>解释：</strong></p>

<p>与 3 相加后，<code>nums1</code> 和 <code>nums2</code> 相等。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [10], nums2 = [5]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">-5</span></p>

<p><strong>解释：</strong></p>

<p>与 <code>-5</code> 相加后，<code>nums1</code> 和 <code>nums2</code> 相等。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [1,1,1,1], nums2 = [1,1,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">0</span></p>

<p><strong>解释：</strong></p>

<p>与 0 相加后，<code>nums1</code> 和 <code>nums2</code> 相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length == nums2.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
	<li>测试用例以这样的方式生成：存在一个整数 <code>x</code>，使得 <code>nums1</code> 中的每个元素都与 <code>x</code> 相加后，<code>nums1</code> 与 <code>nums2</code> 相等。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求最小值差

我们可以分别求出两个数组的最小值，然后返回两个最小值的差值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        return min(nums2) - min(nums1)
```

#### Java

```java
class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        return Arrays.stream(nums2).min().getAsInt() - Arrays.stream(nums1).min().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};
```

#### Go

```go
func addedInteger(nums1 []int, nums2 []int) int {
	return slices.Min(nums2) - slices.Min(nums1)
}
```

#### TypeScript

```ts
function addedInteger(nums1: number[], nums2: number[]): number {
    return Math.min(...nums2) - Math.min(...nums1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3132. 找出与数组相加的整数 II](https://leetcode.cn/problems/find-the-integer-added-to-array-ii){#3132}

{{< tabs "3132" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        def f(x: int) -> bool:
            i = j = cnt = 0
            while i < len(nums1) and j < len(nums2):
                if nums2[j] - nums1[i] != x:
                    cnt += 1
                else:
                    j += 1
                i += 1
            return cnt <= 2

        nums1.sort()
        nums2.sort()
        ans = inf
        for i in range(3):
            x = nums2[0] - nums1[i]
            if f(x):
                ans = min(ans, x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int ans = 1 << 30;
        for (int i = 0; i < 3; ++i) {
            int x = nums2[0] - nums1[i];
            if (f(nums1, nums2, x)) {
                ans = Math.min(ans, x);
            }
        }
        return ans;
    }

    private boolean f(int[] nums1, int[] nums2, int x) {
        int i = 0, j = 0, cnt = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums2[j] - nums1[i] != x) {
                ++cnt;
            } else {
                ++j;
            }
            ++i;
        }
        return cnt <= 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = 1 << 30;
        auto f = [&](int x) {
            int i = 0, j = 0, cnt = 0;
            while (i < nums1.size() && j < nums2.size()) {
                if (nums2[j] - nums1[i] != x) {
                    ++cnt;
                } else {
                    ++j;
                }
                ++i;
            }
            return cnt <= 2;
        };
        for (int i = 0; i < 3; ++i) {
            int x = nums2[0] - nums1[i];
            if (f(x)) {
                ans = min(ans, x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumAddedInteger(nums1 []int, nums2 []int) int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	ans := 1 << 30
	f := func(x int) bool {
		i, j, cnt := 0, 0, 0
		for i < len(nums1) && j < len(nums2) {
			if nums2[j]-nums1[i] != x {
				cnt++
			} else {
				j++
			}
			i++
		}
		return cnt <= 2
	}
	for _, a := range nums1[:3] {
		x := nums2[0] - a
		if f(x) {
			ans = min(ans, x)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumAddedInteger(nums1: number[], nums2: number[]): number {
    nums1.sort((a, b) => a - b);
    nums2.sort((a, b) => a - b);
    const f = (x: number): boolean => {
        let [i, j, cnt] = [0, 0, 0];
        while (i < nums1.length && j < nums2.length) {
            if (nums2[j] - nums1[i] !== x) {
                ++cnt;
            } else {
                ++j;
            }
            ++i;
        }
        return cnt <= 2;
    };
    let ans = Infinity;
    for (let i = 0; i < 3; ++i) {
        const x = nums2[0] - nums1[i];
        if (f(x)) {
            ans = Math.min(ans, x);
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

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>。</p>

<p>从 <code>nums1</code> 中移除两个元素，并且所有其他元素都与变量 <code>x</code> 所表示的整数相加。如果 <code>x</code> 为负数，则表现为元素值的减少。</p>

<p>执行上述操作后，<code>nums1</code> 和 <code>nums2</code> <strong>相等</strong> 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 <strong>相等</strong> 。</p>

<p>返回能够实现数组相等的 <strong>最小 </strong>整数<em> </em><code>x</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [4,20,16,12,8], nums2 = [14,18,10]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">-2</span></p>

<p><strong>解释：</strong></p>

<p>移除 <code>nums1</code> 中下标为 <code>[0,4]</code> 的两个元素，并且每个元素与 <code>-2</code> 相加后，<code>nums1</code> 变为 <code>[18,14,10]</code> ，与 <code>nums2</code> 相等。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [3,5,5,3], nums2 = [7,7]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">2</span></p>

<p><strong>解释：</strong></p>

<p>移除 <code>nums1</code> 中下标为 <code>[0,3]</code> 的两个元素，并且每个元素与 <code>2</code> 相加后，<code>nums1</code> 变为 <code>[7,7]</code> ，与 <code>nums2</code> 相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums1.length &lt;= 200</code></li>
	<li><code>nums2.length == nums1.length - 2</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
	<li>测试用例以这样的方式生成：存在一个整数 <code>x</code>，<code>nums1</code> 中的每个元素都与 <code>x</code> 相加后，再移除两个元素，<code>nums1</code> 可以与 <code>nums2</code> 相等。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举 + 双指针

我们首先对数组 $nums1$ 和 $nums2$ 进行排序，由于我们需要从 $nums1$ 中移除两个元素，因此我们只需要考虑 $nums1$ 的前三个元素，分别记为 $a_1, a_2, a_3$，我们可以枚举 $nums2$ 的第一个元素 $b_1$，那么我们可以得到 $x = b_1 - a_i$，其中 $i \in \{1, 2, 3\}$。然后我们可以通过双指针的方法来判断是否存在一个整数 $x$，使得 $nums1$ 和 $nums2$ 相等，取满足条件的最小的 $x$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        def f(x: int) -> bool:
            i = j = cnt = 0
            while i < len(nums1) and j < len(nums2):
                if nums2[j] - nums1[i] != x:
                    cnt += 1
                else:
                    j += 1
                i += 1
            return cnt <= 2

        nums1.sort()
        nums2.sort()
        ans = inf
        for i in range(3):
            x = nums2[0] - nums1[i]
            if f(x):
                ans = min(ans, x)
        return ans
```

#### Java

```java
class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int ans = 1 << 30;
        for (int i = 0; i < 3; ++i) {
            int x = nums2[0] - nums1[i];
            if (f(nums1, nums2, x)) {
                ans = Math.min(ans, x);
            }
        }
        return ans;
    }

    private boolean f(int[] nums1, int[] nums2, int x) {
        int i = 0, j = 0, cnt = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums2[j] - nums1[i] != x) {
                ++cnt;
            } else {
                ++j;
            }
            ++i;
        }
        return cnt <= 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = 1 << 30;
        auto f = [&](int x) {
            int i = 0, j = 0, cnt = 0;
            while (i < nums1.size() && j < nums2.size()) {
                if (nums2[j] - nums1[i] != x) {
                    ++cnt;
                } else {
                    ++j;
                }
                ++i;
            }
            return cnt <= 2;
        };
        for (int i = 0; i < 3; ++i) {
            int x = nums2[0] - nums1[i];
            if (f(x)) {
                ans = min(ans, x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumAddedInteger(nums1 []int, nums2 []int) int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	ans := 1 << 30
	f := func(x int) bool {
		i, j, cnt := 0, 0, 0
		for i < len(nums1) && j < len(nums2) {
			if nums2[j]-nums1[i] != x {
				cnt++
			} else {
				j++
			}
			i++
		}
		return cnt <= 2
	}
	for _, a := range nums1[:3] {
		x := nums2[0] - a
		if f(x) {
			ans = min(ans, x)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumAddedInteger(nums1: number[], nums2: number[]): number {
    nums1.sort((a, b) => a - b);
    nums2.sort((a, b) => a - b);
    const f = (x: number): boolean => {
        let [i, j, cnt] = [0, 0, 0];
        while (i < nums1.length && j < nums2.length) {
            if (nums2[j] - nums1[i] !== x) {
                ++cnt;
            } else {
                ++j;
            }
            ++i;
        }
        return cnt <= 2;
    };
    let ans = Infinity;
    for (let i = 0; i < 3; ++i) {
        const x = nums2[0] - nums1[i];
        if (f(x)) {
            ans = Math.min(ans, x);
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

# [3133. 数组最后一个元素的最小值](https://leetcode.cn/problems/minimum-array-end){#3133}

{{< tabs "3133" >}}

{{% tab "python" %}}
```python
class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        ans = x
        for i in range(31):
            if x >> i & 1 ^ 1:
                ans |= (n & 1) << i
                n >>= 1
        ans |= n << 31
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minEnd(int n, int x) {
        --n;
        long ans = x;
        for (int i = 0; i < 31; ++i) {
            if ((x >> i & 1) == 0) {
                ans |= (n & 1) << i;
                n >>= 1;
            }
        }
        ans |= (long) n << 31;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minEnd(int n, int x) {
        --n;
        long long ans = x;
        for (int i = 0; i < 31; ++i) {
            if (x >> i & 1 ^ 1) {
                ans |= (n & 1) << i;
                n >>= 1;
            }
        }
        ans |= (1LL * n) << 31;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minEnd(n int, x int) (ans int64) {
	n--
	ans = int64(x)
	for i := 0; i < 31; i++ {
		if x>>i&1 == 0 {
			ans |= int64((n & 1) << i)
			n >>= 1
		}
	}
	ans |= int64(n) << 31
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minEnd(n: number, x: number): number {
    --n;
    let ans: bigint = BigInt(x);
    for (let i = 0; i < 31; ++i) {
        if (((x >> i) & 1) ^ 1) {
            ans |= BigInt(n & 1) << BigInt(i);
            n >>= 1;
        }
    }
    ans |= BigInt(n) << BigInt(31);
    return Number(ans);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>n</code> 和 <code>x</code> 。你需要构造一个长度为 <code>n</code> 的 <strong>正整数 </strong>数组 <code>nums</code> ，对于所有 <code>0 &lt;= i &lt; n - 1</code> ，满足 <code>nums[i + 1]</code><strong> 大于 </strong><code>nums[i]</code> ，并且数组 <code>nums</code> 中所有元素的按位 <code>AND</code> 运算结果为 <code>x</code> 。</p>

<p>返回 <code>nums[n - 1]</code> 可能的<strong> 最小 </strong>值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 3, x = 4</span></p>

<p><strong>输出：</strong><span class="example-io">6</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>nums</code> 可以是 <code>[4,5,6]</code> ，最后一个元素为 <code>6</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 2, x = 7</span></p>

<p><strong>输出：</strong><span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>nums</code> 可以是 <code>[7,15]</code> ，最后一个元素为 <code>15</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, x &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 位运算

根据题目描述，要使得数组的最后一个元素尽可能小，且数组中的元素按位与的结果为 $x$，那么数组的第一个元素必须为 $x$。

假设 $x$ 的二进制表示为 $\underline{1}00\underline{1}00$，那么数组序列为 $\underline{1}00\underline{1}00$, $\underline{1}00\underline{1}01$, $\underline{1}00\underline{1}10$, $\underline{1}00\underline{1}11$...

如果我们忽略掉下划线部分，那么数组序列为 $0000$, $0001$, $0010$, $0011$...，第一项为 $0$，那么第 $n$ 项为 $n-1$。

因此，答案就是在 $x$ 的基础上，将 $n-1$ 的二进制的每一位依次填入 $x$ 的二进制中的 $0$ 位。

时间复杂度 $O(\log x)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        ans = x
        for i in range(31):
            if x >> i & 1 ^ 1:
                ans |= (n & 1) << i
                n >>= 1
        ans |= n << 31
        return ans
```

#### Java

```java
class Solution {
    public long minEnd(int n, int x) {
        --n;
        long ans = x;
        for (int i = 0; i < 31; ++i) {
            if ((x >> i & 1) == 0) {
                ans |= (n & 1) << i;
                n >>= 1;
            }
        }
        ans |= (long) n << 31;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minEnd(int n, int x) {
        --n;
        long long ans = x;
        for (int i = 0; i < 31; ++i) {
            if (x >> i & 1 ^ 1) {
                ans |= (n & 1) << i;
                n >>= 1;
            }
        }
        ans |= (1LL * n) << 31;
        return ans;
    }
};
```

#### Go

```go
func minEnd(n int, x int) (ans int64) {
	n--
	ans = int64(x)
	for i := 0; i < 31; i++ {
		if x>>i&1 == 0 {
			ans |= int64((n & 1) << i)
			n >>= 1
		}
	}
	ans |= int64(n) << 31
	return
}
```

#### TypeScript

```ts
function minEnd(n: number, x: number): number {
    --n;
    let ans: bigint = BigInt(x);
    for (let i = 0; i < 31; ++i) {
        if (((x >> i) & 1) ^ 1) {
            ans |= BigInt(n & 1) << BigInt(i);
            n >>= 1;
        }
    }
    ans |= BigInt(n) << BigInt(31);
    return Number(ans);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3134. 找出唯一性数组的中位数](https://leetcode.cn/problems/find-the-median-of-the-uniqueness-array){#3134}

{{< tabs "3134" >}}

{{% tab "python" %}}
```python
class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        def check(mx: int) -> bool:
            cnt = defaultdict(int)
            k = l = 0
            for r, x in enumerate(nums):
                cnt[x] += 1
                while len(cnt) > mx:
                    y = nums[l]
                    cnt[y] -= 1
                    if cnt[y] == 0:
                        cnt.pop(y)
                    l += 1
                k += r - l + 1
                if k >= (m + 1) // 2:
                    return True
            return False

        n = len(nums)
        m = (1 + n) * n // 2
        return bisect_left(range(n), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private long m;
    private int[] nums;

    public int medianOfUniquenessArray(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        m = (1L + n) * n / 2;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int mx) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long k = 0;
        for (int l = 0, r = 0; r < nums.length; ++r) {
            int x = nums[r];
            cnt.merge(x, 1, Integer::sum);
            while (cnt.size() > mx) {
                int y = nums[l++];
                if (cnt.merge(y, -1, Integer::sum) == 0) {
                    cnt.remove(y);
                }
            }
            k += r - l + 1;
            if (k >= (m + 1) / 2) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        using ll = long long;
        ll m = (1LL + n) * n / 2;
        int l = 0, r = n;
        auto check = [&](int mx) -> bool {
            unordered_map<int, int> cnt;
            ll k = 0;
            for (int l = 0, r = 0; r < n; ++r) {
                int x = nums[r];
                ++cnt[x];
                while (cnt.size() > mx) {
                    int y = nums[l++];
                    if (--cnt[y] == 0) {
                        cnt.erase(y);
                    }
                }
                k += r - l + 1;
                if (k >= (m + 1) / 2) {
                    return true;
                }
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func medianOfUniquenessArray(nums []int) int {
	n := len(nums)
	m := (1 + n) * n / 2
	return sort.Search(n, func(mx int) bool {
		cnt := map[int]int{}
		l, k := 0, 0
		for r, x := range nums {
			cnt[x]++
			for len(cnt) > mx {
				y := nums[l]
				cnt[y]--
				if cnt[y] == 0 {
					delete(cnt, y)
				}
				l++
			}
			k += r - l + 1
			if k >= (m+1)/2 {
				return true
			}
		}
		return false
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function medianOfUniquenessArray(nums: number[]): number {
    const n = nums.length;
    const m = Math.floor(((1 + n) * n) / 2);
    let [l, r] = [0, n];
    const check = (mx: number): boolean => {
        const cnt = new Map<number, number>();
        let [l, k] = [0, 0];
        for (let r = 0; r < n; ++r) {
            const x = nums[r];
            cnt.set(x, (cnt.get(x) || 0) + 1);
            while (cnt.size > mx) {
                const y = nums[l++];
                cnt.set(y, cnt.get(y)! - 1);
                if (cnt.get(y) === 0) {
                    cnt.delete(y);
                }
            }
            k += r - l + 1;
            if (k >= Math.floor((m + 1) / 2)) {
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 。数组 <code>nums</code> 的<strong> 唯一性数组</strong> 是一个按元素从小到大排序的数组，包含了 <code>nums</code> 的所有非空 <span data-keyword="subarray-nonempty">子数组</span> 中不同元素的个数。</p>

<p>换句话说，这是由所有 <code>0 &lt;= i &lt;= j &lt; nums.length</code> 的 <code>distinct(nums[i..j])</code> 组成的递增数组。</p>

<p>其中，<code>distinct(nums[i..j])</code> 表示从下标 <code>i</code> 到下标 <code>j</code> 的子数组中不同元素的数量。</p>

<p>返回 <code>nums</code> <strong>唯一性数组 </strong>的 <strong>中位数 </strong>。</p>

<p><strong>注意</strong>，数组的 <strong>中位数 </strong>定义为有序数组的中间元素。如果有两个中间元素，则取值较小的那个。<!-- notionvc: 7e0f5178-4273-4a82-95ce-3395297921dc --></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2,3]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 的唯一性数组为 <code>[distinct(nums[0..0]), distinct(nums[1..1]), distinct(nums[2..2]), distinct(nums[0..1]), distinct(nums[1..2]), distinct(nums[0..2])]</code>，即 <code>[1, 1, 1, 2, 2, 3]</code> 。唯一性数组的中位数为 1 ，因此答案是 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,4,3,4,5]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 的唯一性数组为 <code>[1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3]</code> 。唯一性数组的中位数为 2 ，因此答案是 2 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,3,5,4]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 的唯一性数组为 <code>[1, 1, 1, 1, 2, 2, 2, 3, 3, 3]</code> 。唯一性数组的中位数为 2 ，因此答案是 2 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 双指针

我们记数组 $\textit{nums}$ 的长度为 $n$，那么唯一性数组的长度为 $m = \frac{(1 + n) \times n}{2}$，而唯一性数组的中位数就是这 $m$ 个数中的第 $\frac{m + 1}{2}$ 小的数字。

考虑唯一性数组中，有多少个数小于等于 $x$。随着 $x$ 的增大，只会有越来越多的数小于等于 $x$。这存在着单调性，因此，我们可以二分枚举 $x$，找到第一个 $x$，满足唯一性数组中小于等于 $x$ 的数的个数大于等于 $\frac{m + 1}{2}$，这个 $x$ 就是唯一性数组的中位数。

我们定义二分查找的左边界 $l = 0$，右边界 $r = n$，然后进行二分查找，对于每个 $\textit{mid}$，我们检查唯一性数组中小于等于 $\textit{mid}$ 的数的个数是否大于等于 $\frac{m + 1}{2}$。我们通过函数 $\text{check}(mx)$ 来实现这一点。

函数 $\text{check}(mx)$ 的实现思路如下：

由于子数组越长，不同元素的个数越多，因此，我们可以利用双指针维护一个滑动窗口，使得窗口中的子数组的不同元素的个数不超过 $mx$。具体地，我们维护一个哈希表 $\textit{cnt}$，$\textit{cnt}[x]$ 表示窗口中元素 $x$ 的个数。我们使用两个指针 $l$ 和 $r$，其中 $l$ 表示窗口的左边界，而 $r$ 表示窗口的右边界。初始时 $l = r = 0$。

我们枚举 $r$，对于每个 $r$，我们将 $\textit{nums}[r]$ 加入窗口中，并更新 $\textit{cnt}[\textit{nums}[r]]$。如果窗口中的不同元素的个数超过了 $mx$，我们需要将 $l$ 右移，直到窗口中的不同元素的个数不超过 $mx$。此时，右端点为 $r$，而左端点为 $[l,..r]$ 的子数组都是满足条件的，一共有 $r - l + 1$ 个子数组。我们将这个数量累加到 $k$ 中，如果 $k$ 大于等于 $\frac{m + 1}{2}$，那么说明唯一性数组中小于等于 $\textit{mid}$ 的数的个数大于等于 $\frac{m + 1}{2}$，我们返回 $\text{true}$，否则返回 $\text{false}$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        def check(mx: int) -> bool:
            cnt = defaultdict(int)
            k = l = 0
            for r, x in enumerate(nums):
                cnt[x] += 1
                while len(cnt) > mx:
                    y = nums[l]
                    cnt[y] -= 1
                    if cnt[y] == 0:
                        cnt.pop(y)
                    l += 1
                k += r - l + 1
                if k >= (m + 1) // 2:
                    return True
            return False

        n = len(nums)
        m = (1 + n) * n // 2
        return bisect_left(range(n), True, key=check)
```

#### Java

```java
class Solution {
    private long m;
    private int[] nums;

    public int medianOfUniquenessArray(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        m = (1L + n) * n / 2;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int mx) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long k = 0;
        for (int l = 0, r = 0; r < nums.length; ++r) {
            int x = nums[r];
            cnt.merge(x, 1, Integer::sum);
            while (cnt.size() > mx) {
                int y = nums[l++];
                if (cnt.merge(y, -1, Integer::sum) == 0) {
                    cnt.remove(y);
                }
            }
            k += r - l + 1;
            if (k >= (m + 1) / 2) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        using ll = long long;
        ll m = (1LL + n) * n / 2;
        int l = 0, r = n;
        auto check = [&](int mx) -> bool {
            unordered_map<int, int> cnt;
            ll k = 0;
            for (int l = 0, r = 0; r < n; ++r) {
                int x = nums[r];
                ++cnt[x];
                while (cnt.size() > mx) {
                    int y = nums[l++];
                    if (--cnt[y] == 0) {
                        cnt.erase(y);
                    }
                }
                k += r - l + 1;
                if (k >= (m + 1) / 2) {
                    return true;
                }
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func medianOfUniquenessArray(nums []int) int {
	n := len(nums)
	m := (1 + n) * n / 2
	return sort.Search(n, func(mx int) bool {
		cnt := map[int]int{}
		l, k := 0, 0
		for r, x := range nums {
			cnt[x]++
			for len(cnt) > mx {
				y := nums[l]
				cnt[y]--
				if cnt[y] == 0 {
					delete(cnt, y)
				}
				l++
			}
			k += r - l + 1
			if k >= (m+1)/2 {
				return true
			}
		}
		return false
	})
}
```

#### TypeScript

```ts
function medianOfUniquenessArray(nums: number[]): number {
    const n = nums.length;
    const m = Math.floor(((1 + n) * n) / 2);
    let [l, r] = [0, n];
    const check = (mx: number): boolean => {
        const cnt = new Map<number, number>();
        let [l, k] = [0, 0];
        for (let r = 0; r < n; ++r) {
            const x = nums[r];
            cnt.set(x, (cnt.get(x) || 0) + 1);
            while (cnt.size > mx) {
                const y = nums[l++];
                cnt.set(y, cnt.get(y)! - 1);
                if (cnt.get(y) === 0) {
                    cnt.delete(y);
                }
            }
            k += r - l + 1;
            if (k >= Math.floor((m + 1) / 2)) {
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3135. 通过添加或删除结尾字符来同化字符串 🔒](https://leetcode.cn/problems/equalize-strings-by-adding-or-removing-characters-at-ends){#3135}

{{< tabs "3135" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, initial: str, target: str) -> int:
        m, n = len(initial), len(target)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        mx = 0
        for i, a in enumerate(initial, 1):
            for j, b in enumerate(target, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1] + 1
                    mx = max(mx, f[i][j])
        return m + n - mx * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(String initial, String target) {
        int m = initial.length(), n = target.length();
        int[][] f = new int[m + 1][n + 1];
        int mx = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (initial.charAt(i - 1) == target.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    mx = Math.max(mx, f[i][j]);
                }
            }
        }
        return m + n - 2 * mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(string initial, string target) {
        int m = initial.size(), n = target.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        int mx = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (initial[i - 1] == target[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    mx = max(mx, f[i][j]);
                }
            }
        }
        return m + n - 2 * mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(initial string, target string) int {
	m, n := len(initial), len(target)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	mx := 0
	for i, a := range initial {
		for j, b := range target {
			if a == b {
				f[i+1][j+1] = f[i][j] + 1
				mx = max(mx, f[i+1][j+1])
			}
		}
	}
	return m + n - 2*mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(initial: string, target: string): number {
    const m = initial.length;
    const n = target.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    let mx: number = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (initial[i - 1] === target[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
                mx = Math.max(mx, f[i][j]);
            }
        }
    }
    return m + n - 2 * mx;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串&nbsp;<code>initial</code> 和&nbsp;<code>target</code>，你的任务是通过一系列操作改变&nbsp;<code>initial</code>&nbsp;以使它与&nbsp;<code>target</code>&nbsp;相同。</p>

<p>在一次操作中，您只能在&nbsp;<code>initial</code> 字符串开头或结尾添加或删除一个字符。</p>

<p>返回将&nbsp;<code>initial</code>&nbsp;变为&nbsp;<code>target</code>&nbsp;所需的<strong>最小</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">initial = "abcde", target = "cdef"</span></p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong></p>

<p>从&nbsp;<code>initial</code>&nbsp;的开头删除 <code>'a'</code>&nbsp;和&nbsp;<code>'b'</code>&nbsp;并添加&nbsp;<code>'f'</code>&nbsp;到结尾。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">initial = "axxy", target = "yabx"</span></p>

<p><strong>输出：</strong>6</p>

<p><strong>解释：</strong></p>

<table border="1">
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果字符串</th>
		</tr>
		<tr>
			<td>将&nbsp;<code>'y'</code>&nbsp;添加到开头</td>
			<td><code>"yaxxy"</code></td>
		</tr>
		<tr>
			<td>从结尾删除</td>
			<td><code>"yaxx"</code></td>
		</tr>
		<tr>
			<td>从结尾删除</td>
			<td><code>"yax"</code></td>
		</tr>
		<tr>
			<td>从结尾删除</td>
			<td><code>"ya"</code></td>
		</tr>
		<tr>
			<td>将&nbsp;<code>'b'</code>&nbsp;添加到结尾</td>
			<td><code>"yab"</code></td>
		</tr>
		<tr>
			<td>将&nbsp;<code>'x'</code> 添加到结尾</td>
			<td><code>"yabx"</code></td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">initial = "xyz", target = "xyz"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>不需要任何操作，因为字符串已经相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= initial.length, target.length &lt;= 1000</code></li>
	<li><code>initial</code> 和&nbsp;<code>target</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们不妨假设字符串 `initial` 和 `target` 的长度分别为 $m$ 和 $n$。

根据题目描述，我们只需要求出 `initial` 和 `target` 的最长公共子串的长度 $mx$，那么我们可以从 `initial` 中删除 $m - mx$ 个字符，然后再添加 $n - mx$ 个字符，即可将 `initial` 转换为 `target`，因此答案为 $m + n - 2 \times mx$。

我们可以使用动态规划的方法求出 `initial` 和 `target` 的最长公共子串的长度 $mx$。我们定义一个二维数组 $f$，其中 $f[i][j]$ 表示以 `initial[i - 1]` 和 `target[j - 1]` 结尾的最长公共子串的长度。那么我们可以得到状态转移方程：

$$
f[i][j] = \begin{cases}
f[i - 1][j - 1] + 1, & \textit{if } \textit{initial}[i - 1] = \textit{target}[j - 1], \\
0, & \textit{otherwise}.
\end{cases}
$$

那么 $mx = \max f[i][j]$，最终答案为 $m + n - 2 \times mx$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为字符串 `initial` 和 `target` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, initial: str, target: str) -> int:
        m, n = len(initial), len(target)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        mx = 0
        for i, a in enumerate(initial, 1):
            for j, b in enumerate(target, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1] + 1
                    mx = max(mx, f[i][j])
        return m + n - mx * 2
```

#### Java

```java
class Solution {
    public int minOperations(String initial, String target) {
        int m = initial.length(), n = target.length();
        int[][] f = new int[m + 1][n + 1];
        int mx = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (initial.charAt(i - 1) == target.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    mx = Math.max(mx, f[i][j]);
                }
            }
        }
        return m + n - 2 * mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(string initial, string target) {
        int m = initial.size(), n = target.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        int mx = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (initial[i - 1] == target[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    mx = max(mx, f[i][j]);
                }
            }
        }
        return m + n - 2 * mx;
    }
};
```

#### Go

```go
func minOperations(initial string, target string) int {
	m, n := len(initial), len(target)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	mx := 0
	for i, a := range initial {
		for j, b := range target {
			if a == b {
				f[i+1][j+1] = f[i][j] + 1
				mx = max(mx, f[i+1][j+1])
			}
		}
	}
	return m + n - 2*mx
}
```

#### TypeScript

```ts
function minOperations(initial: string, target: string): number {
    const m = initial.length;
    const n = target.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    let mx: number = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (initial[i - 1] === target[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
                mx = Math.max(mx, f[i][j]);
            }
        }
    }
    return m + n - 2 * mx;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3136. 有效单词](https://leetcode.cn/problems/valid-word){#3136}

{{< tabs "3136" >}}

{{% tab "python" %}}
```python
class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        has_vowel = has_consonant = False
        vs = set("aeiouAEIOU")
        for c in word:
            if not c.isalnum():
                return False
            if c.isalpha():
                if c in vs:
                    has_vowel = True
                else:
                    has_consonant = True
        return has_vowel and has_consonant
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        boolean hasVowel = false, hasConsonant = false;
        boolean[] vs = new boolean[26];
        for (char c : "aeiou".toCharArray()) {
            vs[c - 'a'] = true;
        }
        for (char c : word.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                if (vs[Character.toLowerCase(c) - 'a']) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!Character.isDigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false, has_consonant = false;
        bool vs[26]{};
        string vowels = "aeiou";
        for (char c : vowels) {
            vs[c - 'a'] = true;
        }
        for (char c : word) {
            if (isalpha(c)) {
                if (vs[tolower(c) - 'a']) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isValid(word string) bool {
	if len(word) < 3 {
		return false
	}
	hasVowel := false
	hasConsonant := false
	vs := make([]bool, 26)
	for _, c := range "aeiou" {
		vs[c-'a'] = true
	}
	for _, c := range word {
		if unicode.IsLetter(c) {
			if vs[unicode.ToLower(c)-'a'] {
				hasVowel = true
			} else {
				hasConsonant = true
			}
		} else if !unicode.IsDigit(c) {
			return false
		}
	}
	return hasVowel && hasConsonant
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isValid(word: string): boolean {
    if (word.length < 3) {
        return false;
    }
    let hasVowel: boolean = false;
    let hasConsonant: boolean = false;
    const vowels: Set<string> = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    for (const c of word) {
        if (!c.match(/[a-zA-Z0-9]/)) {
            return false;
        }
        if (/[a-zA-Z]/.test(c)) {
            if (vowels.has(c)) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        }
    }
    return hasVowel && hasConsonant;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }

        let mut has_vowel = false;
        let mut has_consonant = false;
        let vowels = ['a', 'e', 'i', 'o', 'u'];

        for c in word.chars() {
            if !c.is_alphanumeric() {
                return false;
            }
            if c.is_alphabetic() {
                let lower_c = c.to_ascii_lowercase();
                if vowels.contains(&lower_c) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }

        has_vowel && has_consonant
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsValid(string word) {
        if (word.Length < 3) {
            return false;
        }

        bool hasVowel = false, hasConsonant = false;
        bool[] vs = new bool[26];
        foreach (char c in "aeiou") {
            vs[c - 'a'] = true;
        }

        foreach (char c in word) {
            if (char.IsLetter(c)) {
                char lower = char.ToLower(c);
                if (vs[lower - 'a']) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!char.IsDigit(c)) {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>有效单词</strong> 需要满足以下几个条件：</p>

<ul>
	<li><strong>至少 </strong>包含 3 个字符。</li>
	<li>由数字 0-9 和英文大小写字母组成。（不必包含所有这类字符。）</li>
	<li><strong>至少</strong> 包含一个 <strong>元音字母 </strong>。</li>
	<li><strong>至少</strong> 包含一个 <strong>辅音字母 </strong>。</li>
</ul>

<p>给你一个字符串 <code>word</code> 。如果 <code>word</code> 是一个有效单词，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code> 及其大写形式都属于<strong> 元音字母 </strong>。</li>
	<li>英文中的 <strong>辅音字母 </strong>是指那些除元音字母之外的字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "234Adas"</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>这个单词满足所有条件。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "b3"</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>这个单词的长度少于 3 且没有包含元音字母。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "a3$e"</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>这个单词包含了 <code>'$'</code> 字符且没有包含辅音字母。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code> 由英文大写和小写字母、数字、<code>'@'</code>、<code>'#'</code> 和 <code>'$'</code> 组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们首先判断字符串的长度是否小于 3，如果是则返回 `false`。

然后我们遍历字符串，判断每个字符是否是字母或数字，如果不是则返回 `false`。否则我们判断该字符是否是元音字母，如果是则将 `has_vowel` 置为 `true`，否则将 `has_consonant` 置为 `true`。

最后，如果 `has_vowel` 和 `has_consonant` 都为 `true`，则返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        has_vowel = has_consonant = False
        vs = set("aeiouAEIOU")
        for c in word:
            if not c.isalnum():
                return False
            if c.isalpha():
                if c in vs:
                    has_vowel = True
                else:
                    has_consonant = True
        return has_vowel and has_consonant
```

#### Java

```java
class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        boolean hasVowel = false, hasConsonant = false;
        boolean[] vs = new boolean[26];
        for (char c : "aeiou".toCharArray()) {
            vs[c - 'a'] = true;
        }
        for (char c : word.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                if (vs[Character.toLowerCase(c) - 'a']) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!Character.isDigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false, has_consonant = false;
        bool vs[26]{};
        string vowels = "aeiou";
        for (char c : vowels) {
            vs[c - 'a'] = true;
        }
        for (char c : word) {
            if (isalpha(c)) {
                if (vs[tolower(c) - 'a']) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
```

#### Go

```go
func isValid(word string) bool {
	if len(word) < 3 {
		return false
	}
	hasVowel := false
	hasConsonant := false
	vs := make([]bool, 26)
	for _, c := range "aeiou" {
		vs[c-'a'] = true
	}
	for _, c := range word {
		if unicode.IsLetter(c) {
			if vs[unicode.ToLower(c)-'a'] {
				hasVowel = true
			} else {
				hasConsonant = true
			}
		} else if !unicode.IsDigit(c) {
			return false
		}
	}
	return hasVowel && hasConsonant
}
```

#### TypeScript

```ts
function isValid(word: string): boolean {
    if (word.length < 3) {
        return false;
    }
    let hasVowel: boolean = false;
    let hasConsonant: boolean = false;
    const vowels: Set<string> = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    for (const c of word) {
        if (!c.match(/[a-zA-Z0-9]/)) {
            return false;
        }
        if (/[a-zA-Z]/.test(c)) {
            if (vowels.has(c)) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        }
    }
    return hasVowel && hasConsonant;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }

        let mut has_vowel = false;
        let mut has_consonant = false;
        let vowels = ['a', 'e', 'i', 'o', 'u'];

        for c in word.chars() {
            if !c.is_alphanumeric() {
                return false;
            }
            if c.is_alphabetic() {
                let lower_c = c.to_ascii_lowercase();
                if vowels.contains(&lower_c) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }

        has_vowel && has_consonant
    }
}
```

#### C#

```cs
public class Solution {
    public bool IsValid(string word) {
        if (word.Length < 3) {
            return false;
        }

        bool hasVowel = false, hasConsonant = false;
        bool[] vs = new bool[26];
        foreach (char c in "aeiou") {
            vs[c - 'a'] = true;
        }

        foreach (char c in word) {
            if (char.IsLetter(c)) {
                char lower = char.ToLower(c);
                if (vs[lower - 'a']) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!char.IsDigit(c)) {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3137. K 周期字符串需要的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-word-k-periodic){#3137}

{{< tabs "3137" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        n = len(word)
        return n // k - max(Counter(word[i : i + k] for i in range(0, n, k)).values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        int n = word.length();
        int mx = 0;
        for (int i = 0; i < n; i += k) {
            mx = Math.max(mx, cnt.merge(word.substring(i, i + k), 1, Integer::sum));
        }
        return n / k - mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> cnt;
        int n = word.size();
        int mx = 0;
        for (int i = 0; i < n; i += k) {
            mx = max(mx, ++cnt[word.substr(i, k)]);
        }
        return n / k - mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperationsToMakeKPeriodic(word string, k int) int {
	cnt := map[string]int{}
	n := len(word)
	mx := 0
	for i := 0; i < n; i += k {
		s := word[i : i+k]
		cnt[s]++
		mx = max(mx, cnt[s])
	}
	return n/k - mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperationsToMakeKPeriodic(word: string, k: number): number {
    const cnt: Map<string, number> = new Map();
    const n: number = word.length;
    let mx: number = 0;
    for (let i = 0; i < n; i += k) {
        const s = word.slice(i, i + k);
        cnt.set(s, (cnt.get(s) || 0) + 1);
        mx = Math.max(mx, cnt.get(s)!);
    }
    return Math.floor(n / k) - mx;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的字符串 <code>word</code> 和一个整数 <code>k</code> ，其中 <code>k</code> 是 <code>n</code> 的因数。</p>

<p>在一次操作中，你可以选择任意两个下标 <code>i</code> 和 <code>j</code>，其中 <code>0 &lt;= i, j &lt; n</code> ，且这两个下标都可以被 <code>k</code> 整除，然后用从 <code>j</code> 开始的长度为 <code>k</code> 的子串替换从 <code>i</code> 开始的长度为 <code>k</code> 的子串。也就是说，将子串 <code>word[i..i + k - 1]</code> 替换为子串 <code>word[j..j + k - 1]</code> 。</p>

<p>返回使 <code>word</code> 成为 <strong>K 周期字符串</strong> 所需的<strong> 最少</strong> 操作次数。</p>

<p>如果存在某个长度为 <code>k</code> 的字符串 <code>s</code>，使得 <code>word</code> 可以表示为任意次数连接 <code>s</code> ，则称字符串 <code>word</code> 是 <strong>K 周期字符串</strong> 。例如，如果 <code>word == "ababab"</code>，那么 <code>word</code> 就是 <code>s = "ab"</code> 时的 2 周期字符串 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">word = "leetcodeleet", k = 4</span></p>

<p><strong>输出：</strong><span class="example-io" style="
font-family: Menlo,sans-serif;
font-size: 0.85rem;
">1</span></p>

<p><strong>解释：</strong>可以选择 i = 4 和 j = 0 获得一个 4 周期字符串。这次操作后，word 变为 "leetleetleet" 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">word = "leetcoleet", k = 2</span></p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong>可以执行以下操作获得一个 2 周期字符串。</p>

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" height="146" style="border-collapse:collapse; text-align: center; vertical-align: middle;">
	<tbody>
		<tr>
			<th>i</th>
			<th>j</th>
			<th>word</th>
		</tr>
		<tr>
			<td style="padding: 5px 15px;">0</td>
			<td style="padding: 5px 15px;">2</td>
			<td style="padding: 5px 15px;">etetcoleet</td>
		</tr>
		<tr>
			<td style="padding: 5px 15px;">4</td>
			<td style="padding: 5px 15px;">0</td>
			<td style="padding: 5px 15px;">etetetleet</td>
		</tr>
		<tr>
			<td style="padding: 5px 15px;">6</td>
			<td style="padding: 5px 15px;">0</td>
			<td style="padding: 5px 15px;">etetetetet</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= word.length</code></li>
	<li><code>k</code> 能整除 <code>word.length</code> 。</li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以将字符串 `word` 按照长度为 $k$ 的子串进行分组，然后统计每个子串出现的次数，最后返回 $n/k$ 减去出现次数最多的子串的次数即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        n = len(word)
        return n // k - max(Counter(word[i : i + k] for i in range(0, n, k)).values())
```

#### Java

```java
class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        int n = word.length();
        int mx = 0;
        for (int i = 0; i < n; i += k) {
            mx = Math.max(mx, cnt.merge(word.substring(i, i + k), 1, Integer::sum));
        }
        return n / k - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> cnt;
        int n = word.size();
        int mx = 0;
        for (int i = 0; i < n; i += k) {
            mx = max(mx, ++cnt[word.substr(i, k)]);
        }
        return n / k - mx;
    }
};
```

#### Go

```go
func minimumOperationsToMakeKPeriodic(word string, k int) int {
	cnt := map[string]int{}
	n := len(word)
	mx := 0
	for i := 0; i < n; i += k {
		s := word[i : i+k]
		cnt[s]++
		mx = max(mx, cnt[s])
	}
	return n/k - mx
}
```

#### TypeScript

```ts
function minimumOperationsToMakeKPeriodic(word: string, k: number): number {
    const cnt: Map<string, number> = new Map();
    const n: number = word.length;
    let mx: number = 0;
    for (let i = 0; i < n; i += k) {
        const s = word.slice(i, i + k);
        cnt.set(s, (cnt.get(s) || 0) + 1);
        mx = Math.max(mx, cnt.get(s)!);
    }
    return Math.floor(n / k) - mx;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3138. 同位字符串连接的最小长度](https://leetcode.cn/problems/minimum-length-of-anagram-concatenation){#3138}

{{< tabs "3138" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAnagramLength(self, s: str) -> int:
        def check(k: int) -> bool:
            for i in range(0, n, k):
                cnt1 = Counter(s[i : i + k])
                for c, v in cnt.items():
                    if cnt1[c] * (n // k) != v:
                        return False
            return True

        cnt = Counter(s)
        n = len(s)
        for i in range(1, n + 1):
            if n % i == 0 and check(i):
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private char[] s;
    private int[] cnt = new int[26];

    public int minAnagramLength(String s) {
        n = s.length();
        this.s = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            ++cnt[this.s[i] - 'a'];
        }
        for (int i = 1;; ++i) {
            if (n % i == 0 && check(i)) {
                return i;
            }
        }
    }

    private boolean check(int k) {
        for (int i = 0; i < n; i += k) {
            int[] cnt1 = new int[26];
            for (int j = i; j < i + k; ++j) {
                ++cnt1[s[j] - 'a'];
            }
            for (int j = 0; j < 26; ++j) {
                if (cnt1[j] * (n / k) != cnt[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int cnt[26]{};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        auto check = [&](int k) {
            for (int i = 0; i < n; i += k) {
                int cnt1[26]{};
                for (int j = i; j < i + k; ++j) {
                    cnt1[s[j] - 'a']++;
                }
                for (int j = 0; j < 26; ++j) {
                    if (cnt1[j] * (n / k) != cnt[j]) {
                        return false;
                    }
                }
            }
            return true;
        };
        for (int i = 1;; ++i) {
            if (n % i == 0 && check(i)) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAnagramLength(s string) int {
	n := len(s)
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	check := func(k int) bool {
		for i := 0; i < n; i += k {
			cnt1 := [26]int{}
			for j := i; j < i+k; j++ {
				cnt1[s[j]-'a']++
			}
			for j, v := range cnt {
				if cnt1[j]*(n/k) != v {
					return false
				}
			}
		}
		return true
	}
	for i := 1; ; i++ {
		if n%i == 0 && check(i) {
			return i
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minAnagramLength(s: string): number {
    const n = s.length;
    const cnt: Record<string, number> = {};
    for (let i = 0; i < n; i++) {
        cnt[s[i]] = (cnt[s[i]] || 0) + 1;
    }
    const check = (k: number): boolean => {
        for (let i = 0; i < n; i += k) {
            const cnt1: Record<string, number> = {};
            for (let j = i; j < i + k; j++) {
                cnt1[s[j]] = (cnt1[s[j]] || 0) + 1;
            }
            for (const [c, v] of Object.entries(cnt)) {
                if (cnt1[c] * ((n / k) | 0) !== v) {
                    return false;
                }
            }
        }
        return true;
    };
    for (let i = 1; ; ++i) {
        if (n % i === 0 && check(i)) {
            return i;
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它由某个字符串&nbsp;<code>t</code>&nbsp;和若干&nbsp;<code>t</code>&nbsp; 的&nbsp;<strong>同位字符串</strong>&nbsp;连接而成。</p>

<p>请你返回字符串 <code>t</code>&nbsp;的 <strong>最小</strong>&nbsp;可能长度。</p>

<p><strong>同位字符串</strong>&nbsp;指的是重新排列一个字符串的字母得到的另外一个字符串。例如，"aab"，"aba" 和 "baa" 是 "aab" 的同位字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abba"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>一个可能的字符串&nbsp;<code>t</code>&nbsp;为&nbsp;<code>"ba"</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "cdef"</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>一个可能的字符串&nbsp;<code>t</code>&nbsp;为&nbsp;<code>"cdef"</code>&nbsp;，注意&nbsp;<code>t</code>&nbsp;可能等于&nbsp;<code>s</code>&nbsp;。</p>

<p><strong class="example">示例</strong><strong>&nbsp;3：</strong></p>

<p><strong>输入：</strong>s = "abcbcacabbaccba"</p>

<p><b>输出：</b>3</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

根据题目描述，字符串 $\textit{t}$ 的长度一定是 $\textit{s}$ 的长度的因子，我们可以从小到大枚举字符串 $\textit{t}$ 的长度 $k$，然后检查是否满足题目要求，如果满足则返回。因此，问题转化为如何检查字符串 $\textit{t}$ 的长度 $k$ 是否满足题目要求。

我们首先统计字符串 $\textit{s}$ 中每个字符出现的次数，记录在数组或哈希表 $\textit{cnt}$ 中。

然后，我们定义一个函数 $\textit{check}(k)$，用来检查字符串 $\textit{t}$ 的长度 $k$ 是否满足题目要求。我们可以遍历字符串 $\textit{s}$，每次取长度为 $k$ 的子串，然后统计每个字符出现的次数，如果每个字符出现的次数乘以 $\frac{n}{k}$ 不等于 $\textit{cnt}$ 中的值，则返回 $\textit{false}$。遍历结束，如果都满足，则返回 $\textit{true}$。

时间复杂度 $O(n \times A)$，其中 $n$ 是字符串 $\textit{s}$ 的长度，而 $A$ 是 $n$ 的因子个数。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，本题中为小写字母集合。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAnagramLength(self, s: str) -> int:
        def check(k: int) -> bool:
            for i in range(0, n, k):
                cnt1 = Counter(s[i : i + k])
                for c, v in cnt.items():
                    if cnt1[c] * (n // k) != v:
                        return False
            return True

        cnt = Counter(s)
        n = len(s)
        for i in range(1, n + 1):
            if n % i == 0 and check(i):
                return i
```

#### Java

```java
class Solution {
    private int n;
    private char[] s;
    private int[] cnt = new int[26];

    public int minAnagramLength(String s) {
        n = s.length();
        this.s = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            ++cnt[this.s[i] - 'a'];
        }
        for (int i = 1;; ++i) {
            if (n % i == 0 && check(i)) {
                return i;
            }
        }
    }

    private boolean check(int k) {
        for (int i = 0; i < n; i += k) {
            int[] cnt1 = new int[26];
            for (int j = i; j < i + k; ++j) {
                ++cnt1[s[j] - 'a'];
            }
            for (int j = 0; j < 26; ++j) {
                if (cnt1[j] * (n / k) != cnt[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int cnt[26]{};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        auto check = [&](int k) {
            for (int i = 0; i < n; i += k) {
                int cnt1[26]{};
                for (int j = i; j < i + k; ++j) {
                    cnt1[s[j] - 'a']++;
                }
                for (int j = 0; j < 26; ++j) {
                    if (cnt1[j] * (n / k) != cnt[j]) {
                        return false;
                    }
                }
            }
            return true;
        };
        for (int i = 1;; ++i) {
            if (n % i == 0 && check(i)) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func minAnagramLength(s string) int {
	n := len(s)
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	check := func(k int) bool {
		for i := 0; i < n; i += k {
			cnt1 := [26]int{}
			for j := i; j < i+k; j++ {
				cnt1[s[j]-'a']++
			}
			for j, v := range cnt {
				if cnt1[j]*(n/k) != v {
					return false
				}
			}
		}
		return true
	}
	for i := 1; ; i++ {
		if n%i == 0 && check(i) {
			return i
		}
	}
}
```

#### TypeScript

```ts
function minAnagramLength(s: string): number {
    const n = s.length;
    const cnt: Record<string, number> = {};
    for (let i = 0; i < n; i++) {
        cnt[s[i]] = (cnt[s[i]] || 0) + 1;
    }
    const check = (k: number): boolean => {
        for (let i = 0; i < n; i += k) {
            const cnt1: Record<string, number> = {};
            for (let j = i; j < i + k; j++) {
                cnt1[s[j]] = (cnt1[s[j]] || 0) + 1;
            }
            for (const [c, v] of Object.entries(cnt)) {
                if (cnt1[c] * ((n / k) | 0) !== v) {
                    return false;
                }
            }
        }
        return true;
    };
    for (let i = 1; ; ++i) {
        if (n % i === 0 && check(i)) {
            return i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3139. 使数组中所有元素相等的最小开销](https://leetcode.cn/problems/minimum-cost-to-equalize-array){#3139}

{{< tabs "3139" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和两个整数&nbsp;<code>cost1</code> 和&nbsp;<code>cost2</code>&nbsp;。你可以执行以下&nbsp;<strong>任一</strong>&nbsp;操作&nbsp;<strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>从 <code>nums</code>&nbsp;中选择下标 <code>i</code>&nbsp;并且将 <code>nums[i]</code>&nbsp;<strong>增加</strong> <code>1</code>&nbsp;，开销为 <code>cost1</code>。</li>
	<li>选择 <code>nums</code>&nbsp;中两个 <strong>不同</strong>&nbsp;下标 <code>i</code>&nbsp;和 <code>j</code>&nbsp;，并且将 <code>nums[i]</code>&nbsp;和 <code>nums[j]</code>&nbsp;都&nbsp;<strong>增加</strong> <code>1</code>&nbsp;，开销为 <code>cost2</code>&nbsp;。</li>
</ul>

<p>你的目标是使数组中所有元素都 <strong>相等</strong>&nbsp;，请你返回需要的 <strong>最小开销</strong>&nbsp;之和。</p>

<p>由于答案可能会很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [4,1], cost1 = 5, cost2 = 2</span></p>

<p><span class="example-io"><b>输出：</b>15</span></p>

<p><strong>解释：</strong></p>

<p>执行以下操作可以使数组中所有元素相等：</p>

<ul>
	<li>将&nbsp;<code>nums[1]</code>&nbsp;增加 1 ，开销为 5 ，<code>nums</code> 变为&nbsp;<code>[4,2]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[1]</code>&nbsp;增加 1 ，开销为 5 ，<code>nums</code> 变为&nbsp;<code>[4,3]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[1]</code>&nbsp;增加 1 ，开销为 5 ，<code>nums</code> 变为&nbsp;<code>[4,4]</code>&nbsp;。</li>
</ul>

<p>总开销为 15 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,3,3,3,5], cost1 = 2, cost2 = 1</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><b>解释：</b></p>

<p>执行以下操作可以使数组中所有元素相等：</p>

<ul>
	<li>将&nbsp;<code>nums[0]</code> 和&nbsp;<code>nums[1]</code>&nbsp;同时增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[3,4,3,3,5]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[0]</code> 和&nbsp;<code>nums[2]</code>&nbsp;同时增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[4,4,4,3,5]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[0]</code> 和&nbsp;<code>nums[3]</code>&nbsp;同时增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[5,4,4,4,5]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[1]</code> 和&nbsp;<code>nums[2]</code>&nbsp;同时增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[5,5,5,4,5]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[3]</code>&nbsp;增加 1 ，开销为 2 ，<code>nums</code> 变为&nbsp;<code>[5,5,5,5,5]</code>&nbsp;。</li>
</ul>

<p>总开销为 6 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,5,3], cost1 = 1, cost2 = 3</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>执行以下操作可以使数组中所有元素相等：</p>

<ul>
	<li>将&nbsp;<code>nums[0]</code>&nbsp;增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[4,5,3]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[0]</code>&nbsp;增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[5,5,3]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[2]</code>&nbsp;增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[5,5,4]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[2]</code>&nbsp;增加 1 ，开销为 1 ，<code>nums</code> 变为&nbsp;<code>[5,5,5]</code>&nbsp;。</li>
</ul>

<p>总开销为 4 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= cost1 &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= cost2 &lt;= 10<sup>6</sup></code></li>
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

#### Python3

```python

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
