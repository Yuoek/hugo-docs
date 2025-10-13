---
title: "1420_生成数组"
date: 2025-10-08T18:37:18+08:00
weight: 3
tags: [二分查找, 交互, 前缀和, 动态规划, 单调队列, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数据流, 数组, 滑动窗口, 矩阵, 设计, 队列]
---

{{< markmap >}}
### [1420_生成数组](#1420)
#### [动态规划](#1420)
#### [前缀和](#1420)
### [1421_净现值查询 🔒](#1421)
#### [数据库](#1421)
### [1422_分割字符串的最大得分](#1422)
#### [字符串](#1422)
#### [前缀和](#1422)
### [1423_可获得的最大点数](#1423)
#### [数组](#1423)
#### [前缀和](#1423)
#### [滑动窗口](#1423)
### [1424_对角线遍历 II](#1424)
#### [数组](#1424)
#### [排序](#1424)
#### [堆（优先队列）](#1424)
### [1425_带限制的子序列和](#1425)
#### [队列](#1425)
#### [数组](#1425)
#### [动态规划](#1425)
#### [滑动窗口](#1425)
#### [单调队列](#1425)
#### [堆（优先队列）](#1425)
### [1426_数元素 🔒](#1426)
#### [数组](#1426)
#### [哈希表](#1426)
### [1427_字符串的左右移 🔒](#1427)
#### [数组](#1427)
#### [数学](#1427)
#### [字符串](#1427)
### [1428_至少有一个 1 的最左端列 🔒](#1428)
#### [数组](#1428)
#### [二分查找](#1428)
#### [交互](#1428)
#### [矩阵](#1428)
### [1429_第一个唯一数字 🔒](#1429)
#### [设计](#1429)
#### [队列](#1429)
#### [数组](#1429)
#### [哈希表](#1429)
#### [数据流](#1429)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1420_生成数组
___
#### 动态规划
___
#### 前缀和
---
### 1421_净现值查询 🔒
___
#### 数据库
---
### 1422_分割字符串的最大得分
___
#### 字符串
___
#### 前缀和
---
### 1423_可获得的最大点数
___
#### 数组
___
#### 前缀和
___
#### 滑动窗口
---
### 1424_对角线遍历 II
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 1425_带限制的子序列和
___
#### 队列
___
#### 数组
___
#### 动态规划
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
---
### 1426_数元素 🔒
___
#### 数组
___
#### 哈希表
---
### 1427_字符串的左右移 🔒
___
#### 数组
___
#### 数学
___
#### 字符串
---
### 1428_至少有一个 1 的最左端列 🔒
___
#### 数组
___
#### 二分查找
___
#### 交互
___
#### 矩阵
---
### 1429_第一个唯一数字 🔒
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 哈希表
___
#### 数据流
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 前缀和 |
| 动态规划 | 单调队列 | 哈希表 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数据流 |
| 数组 | 滑动窗口 | 矩阵 |
| 设计 | 队列 |  |

# [1420. 生成数组](https://leetcode.cn/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons){#1420}

{{< tabs "1420" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        if k == 0:
            return 0
        dp = [[[0] * (m + 1) for _ in range(k + 1)] for _ in range(n + 1)]
        mod = 10**9 + 7
        for i in range(1, m + 1):
            dp[1][1][i] = 1
        for i in range(2, n + 1):
            for c in range(1, min(k + 1, i + 1)):
                for j in range(1, m + 1):
                    dp[i][c][j] = dp[i - 1][c][j] * j
                    for j0 in range(1, j):
                        dp[i][c][j] += dp[i - 1][c - 1][j0]
                        dp[i][c][j] %= mod
        ans = 0
        for i in range(1, m + 1):
            ans += dp[n][k][i]
            ans %= mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numOfArrays(int n, int m, int k) {
        if (k == 0) {
            return 0;
        }
        long[][][] dp = new long[n + 1][k + 1][m + 1];
        for (int i = 1; i <= m; ++i) {
            dp[1][1][i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int c = 1; c <= Math.min(i, k); ++c) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][c][j] = (dp[i - 1][c][j] * j) % MOD;
                    for (int j0 = 1; j0 < j; ++j0) {
                        dp[i][c][j] = (dp[i][c][j] + dp[i - 1][c - 1][j0]) % MOD;
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + dp[n][k][i]) % MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0) return 0;
        int mod = 1e9 + 7;
        using ll = long long;
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(m + 1)));
        for (int i = 1; i <= m; ++i) dp[1][1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int c = 1; c <= min(i, k); ++c) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][c][j] = (dp[i - 1][c][j] * j) % mod;
                    for (int j0 = 1; j0 < j; ++j0) {
                        dp[i][c][j] = (dp[i][c][j] + dp[i - 1][c - 1][j0]) % mod;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= m; ++i) ans = (ans + dp[n][k][i]) % mod;
        return (int) ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfArrays(n int, m int, k int) int {
	if k == 0 {
		return 0
	}
	mod := int(1e9) + 7
	dp := make([][][]int, n+1)
	for i := range dp {
		dp[i] = make([][]int, k+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, m+1)
		}
	}
	for i := 1; i <= m; i++ {
		dp[1][1][i] = 1
	}
	for i := 2; i <= n; i++ {
		for c := 1; c <= k && c <= i; c++ {
			for j := 1; j <= m; j++ {
				dp[i][c][j] = (dp[i-1][c][j] * j) % mod
				for j0 := 1; j0 < j; j0++ {
					dp[i][c][j] = (dp[i][c][j] + dp[i-1][c-1][j0]) % mod
				}
			}
		}
	}
	ans := 0
	for i := 1; i <= m; i++ {
		ans = (ans + dp[n][k][i]) % mod
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定三个整数 <code>n</code>、<code>m</code> 和 <code>k</code> 。考虑使用下图描述的算法找出正整数数组中最大的元素。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1420.Build%20Array%20Where%20You%20Can%20Find%20The%20Maximum%20Exactly%20K%20Comparisons/images/e.png" style="height: 372px; width: 424px;" /></p>

<p>请你构建一个具有以下属性的数组 <code>arr</code> ：</p>

<ul>
	<li><code>arr</code> 中包含确切的&nbsp;<code>n</code> 个整数。</li>
	<li><code>1 &lt;= arr[i] &lt;= m</code> 其中 <code>(0 &lt;= i &lt; n)</code> 。</li>
	<li>将上面提到的算法应用于 <code>arr</code>&nbsp;之后，<code>search_cost</code> 的值等于 <code>k</code> 。</li>
</ul>

<p>返回在满足上述条件的情况下构建数组 <code>arr</code> 的 <em>方法数量</em>&nbsp;，由于答案可能会很大，所以 <strong>必须</strong> 对 <code>10^9 + 7</code> 取余。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2, m = 3, k = 1
<strong>输出：</strong>6
<strong>解释：</strong>可能的数组分别为 [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5, m = 2, k = 3
<strong>输出：</strong>0
<strong>解释：</strong>没有数组可以满足上述条件
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 9, m = 1, k = 1
<strong>输出：</strong>1
<strong>解释：</strong>唯一可能的数组是 [1, 1, 1, 1, 1, 1, 1, 1, 1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

假设 $dp[i][c][j]$ 表示长度为 $i$，搜索代价为 $c$，且最大值为 $j$ 的方案数。考虑第 $i$ 个数：

若第 $i$ 个数没有改变搜索代价，说明它不严格大于前 $i-1$ 个数，也就是说，$dp[i][c][j]$ 是从 $dp[i-1][c][j]$ 转移而来，即数组的前 $i-1$ 个数的最大值已经是 $j$，并且第 $i$ 个数没有改变最大值，因此第 $i$ 个数的可选范围是 $[1,..j]$，共有 $j$ 种可选方案。即

$$
dp[i][c][j]=dp[i-1][c][j] \times j
$$

若第 $i$ 个数改变了搜索代价，说明数组前 $i-1$ 个数的最大值小于 $j$，并且第 $i$ 个数恰好为 $j$。此时 $dp[i][c][j]$ 是从所有 $dp[i-1][c-1][j']$ 转移而来，其中 $j'<j$。即

$$
dp[i][c][j] = \sum_{j'=1}^{j-1} dp[i-1][c-1][j']
$$

综上，可得

$$
dp[i][c][j] = dp[i-1][c][j] \times j + \sum_{j'=1}^{j-1} dp[i-1][c-1][j']
$$

答案为

$$
\sum_{j=1}^{m}dp[n][k][j]
$$

时间复杂度 $O(nkm^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        if k == 0:
            return 0
        dp = [[[0] * (m + 1) for _ in range(k + 1)] for _ in range(n + 1)]
        mod = 10**9 + 7
        for i in range(1, m + 1):
            dp[1][1][i] = 1
        for i in range(2, n + 1):
            for c in range(1, min(k + 1, i + 1)):
                for j in range(1, m + 1):
                    dp[i][c][j] = dp[i - 1][c][j] * j
                    for j0 in range(1, j):
                        dp[i][c][j] += dp[i - 1][c - 1][j0]
                        dp[i][c][j] %= mod
        ans = 0
        for i in range(1, m + 1):
            ans += dp[n][k][i]
            ans %= mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numOfArrays(int n, int m, int k) {
        if (k == 0) {
            return 0;
        }
        long[][][] dp = new long[n + 1][k + 1][m + 1];
        for (int i = 1; i <= m; ++i) {
            dp[1][1][i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int c = 1; c <= Math.min(i, k); ++c) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][c][j] = (dp[i - 1][c][j] * j) % MOD;
                    for (int j0 = 1; j0 < j; ++j0) {
                        dp[i][c][j] = (dp[i][c][j] + dp[i - 1][c - 1][j0]) % MOD;
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + dp[n][k][i]) % MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0) return 0;
        int mod = 1e9 + 7;
        using ll = long long;
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(m + 1)));
        for (int i = 1; i <= m; ++i) dp[1][1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int c = 1; c <= min(i, k); ++c) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][c][j] = (dp[i - 1][c][j] * j) % mod;
                    for (int j0 = 1; j0 < j; ++j0) {
                        dp[i][c][j] = (dp[i][c][j] + dp[i - 1][c - 1][j0]) % mod;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= m; ++i) ans = (ans + dp[n][k][i]) % mod;
        return (int) ans;
    }
};
```

#### Go

```go
func numOfArrays(n int, m int, k int) int {
	if k == 0 {
		return 0
	}
	mod := int(1e9) + 7
	dp := make([][][]int, n+1)
	for i := range dp {
		dp[i] = make([][]int, k+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, m+1)
		}
	}
	for i := 1; i <= m; i++ {
		dp[1][1][i] = 1
	}
	for i := 2; i <= n; i++ {
		for c := 1; c <= k && c <= i; c++ {
			for j := 1; j <= m; j++ {
				dp[i][c][j] = (dp[i-1][c][j] * j) % mod
				for j0 := 1; j0 < j; j0++ {
					dp[i][c][j] = (dp[i][c][j] + dp[i-1][c-1][j0]) % mod
				}
			}
		}
	}
	ans := 0
	for i := 1; i <= m; i++ {
		ans = (ans + dp[n][k][i]) % mod
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1421. 净现值查询 🔒](https://leetcode.cn/problems/npv-queries){#1421}

{{< tabs "1421" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT q.*, IFNULL(npv, 0) AS npv
FROM
    Queries AS q
    LEFT JOIN NPV AS n USING (id, year);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>NPV</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| year          | int     |
| npv           | int     |
+---------------+---------+
(id, year) 是该表主键(具有唯一值的列的组合).
该表有每一笔存货的年份, id 和对应净现值的信息.
</pre>

<p>&nbsp;</p>

<p>表: <code>Queries</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| year          | int     |
+---------------+---------+
(id, year) 是该表主键(具有唯一值的列的组合).
该表有每一次查询所对应存货的 id 和年份的信息.
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找到 Queries&nbsp;表中每一次查询的净现值。</p>

<p>结果表 <strong>没有顺序要求 </strong>。</p>

<p>查询结果的格式如下所示:</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
NPV 表:
+------+--------+--------+
| id   | year   | npv    |
+------+--------+--------+
| 1    | 2018   | 100    |
| 7    | 2020   | 30     |
| 13   | 2019   | 40     |
| 1    | 2019   | 113    |
| 2    | 2008   | 121    |
| 3    | 2009   | 12     |
| 11   | 2020   | 99     |
| 7    | 2019   | 0      |
+------+--------+--------+

Queries 表:
+------+--------+
| id   | year   |
+------+--------+
| 1    | 2019   |
| 2    | 2008   |
| 3    | 2009   |
| 7    | 2018   |
| 7    | 2019   |
| 7    | 2020   |
| 13   | 2019   |
+------+--------+
<strong>输出：</strong>
+------+--------+--------+
| id   | year   | npv    |
+------+--------+--------+
| 1    | 2019   | 113    |
| 2    | 2008   | 121    |
| 3    | 2009   | 12     |
| 7    | 2018   | 0      |
| 7    | 2019   | 0      |
| 7    | 2020   | 30     |
| 13   | 2019   | 40     |
+------+--------+--------+
<strong>解释：</strong>
(7, 2018)的净现值不在 NPV 表中, 我们把它看作是 0.
所有其它查询的净现值都能在 NPV 表中找到.
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT q.*, IFNULL(npv, 0) AS npv
FROM
    Queries AS q
    LEFT JOIN NPV AS n USING (id, year);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1422. 分割字符串的最大得分](https://leetcode.cn/problems/maximum-score-after-splitting-a-string){#1422}

{{< tabs "1422" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, s: str) -> int:
        l, r = 0, s.count("1")
        ans = 0
        for x in s[:-1]:
            l += int(x) ^ 1
            r -= int(x)
            ans = max(ans, l + r)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(String s) {
        int l = 0, r = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++r;
            }
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            l += (s.charAt(i) - '0') ^ 1;
            r -= s.charAt(i) - '0';
            ans = Math.max(ans, l + r);
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
    int maxScore(string s) {
        int l = 0, r = count(s.begin(), s.end(), '1');
        int ans = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            l += (s[i] - '0') ^ 1;
            r -= s[i] - '0';
            ans = max(ans, l + r);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(s string) (ans int) {
	l, r := 0, strings.Count(s, "1")
	for _, c := range s[:len(s)-1] {
		if c == '0' {
			l++
		} else {
			r--
		}
		ans = max(ans, l+r)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(s: string): number {
    let [l, r] = [0, 0];
    for (const c of s) {
        r += c === '1' ? 1 : 0;
    }
    let ans = 0;
    for (let i = 0; i < s.length - 1; ++i) {
        if (s[i] === '0') {
            ++l;
        } else {
            --r;
        }
        ans = Math.max(ans, l + r);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_score(s: String) -> i32 {
        let mut l = 0;
        let mut r = s.bytes().filter(|&b| b == b'1').count() as i32;
        let mut ans = 0;
        let cs = s.as_bytes();
        for i in 0..s.len() - 1 {
            l += ((cs[i] - b'0') ^ 1) as i32;
            r -= (cs[i] - b'0') as i32;
            ans = ans.max(l + r);
        }
        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由若干 0 和 1 组成的字符串 <code>s</code> ，请你计算并返回将该字符串分割成两个 <strong>非空</strong> 子字符串（即&nbsp;<strong>左</strong> 子字符串和 <strong>右</strong> 子字符串）所能获得的最大得分。</p>

<p>「分割字符串的得分」为 <strong>左</strong> 子字符串中 <strong>0</strong> 的数量加上 <strong>右</strong> 子字符串中 <strong>1</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;011101&quot;
<strong>输出：</strong>5 
<strong>解释：</strong>
将字符串 s 划分为两个非空子字符串的可行方案有：
左子字符串 = &quot;0&quot; 且 右子字符串 = &quot;11101&quot;，得分 = 1 + 4 = 5 
左子字符串 = &quot;01&quot; 且 右子字符串 = &quot;1101&quot;，得分 = 1 + 3 = 4 
左子字符串 = &quot;011&quot; 且 右子字符串 = &quot;101&quot;，得分 = 1 + 2 = 3 
左子字符串 = &quot;0111&quot; 且 右子字符串 = &quot;01&quot;，得分 = 1 + 1 = 2 
左子字符串 = &quot;01110&quot; 且 右子字符串 = &quot;1&quot;，得分 = 2 + 1 = 3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;00111&quot;
<strong>输出：</strong>5
<strong>解释：</strong>当 左子字符串 = &quot;00&quot; 且 右子字符串 = &quot;111&quot; 时，我们得到最大得分 = 2 + 3 = 5
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;1111&quot;
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 500</code></li>
	<li>字符串 <code>s</code> 仅由字符 <code>&#39;0&#39;</code> 和 <code>&#39;1&#39;</code> 组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用两个变量 $l$ 和 $r$ 分别记录左子字符串中 $0$ 的数量和右子字符串中 $1$ 的数量。初始时 $l = 0$，而 $r$ 则等于字符串 $s$ 中 $1$ 的数量。

遍历字符串 $s$ 的前 $n - 1$ 个字符，对于每一个位置 $i$，如果 $s[i] = 0$，则 $l$ 自增 $1$，否则 $r$ 自减 $1$。然后我们更新答案为 $l + r$ 的最大值。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, s: str) -> int:
        l, r = 0, s.count("1")
        ans = 0
        for x in s[:-1]:
            l += int(x) ^ 1
            r -= int(x)
            ans = max(ans, l + r)
        return ans
```

#### Java

```java
class Solution {
    public int maxScore(String s) {
        int l = 0, r = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++r;
            }
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            l += (s.charAt(i) - '0') ^ 1;
            r -= s.charAt(i) - '0';
            ans = Math.max(ans, l + r);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(string s) {
        int l = 0, r = count(s.begin(), s.end(), '1');
        int ans = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            l += (s[i] - '0') ^ 1;
            r -= s[i] - '0';
            ans = max(ans, l + r);
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(s string) (ans int) {
	l, r := 0, strings.Count(s, "1")
	for _, c := range s[:len(s)-1] {
		if c == '0' {
			l++
		} else {
			r--
		}
		ans = max(ans, l+r)
	}
	return
}
```

#### TypeScript

```ts
function maxScore(s: string): number {
    let [l, r] = [0, 0];
    for (const c of s) {
        r += c === '1' ? 1 : 0;
    }
    let ans = 0;
    for (let i = 0; i < s.length - 1; ++i) {
        if (s[i] === '0') {
            ++l;
        } else {
            --r;
        }
        ans = Math.max(ans, l + r);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_score(s: String) -> i32 {
        let mut l = 0;
        let mut r = s.bytes().filter(|&b| b == b'1').count() as i32;
        let mut ans = 0;
        let cs = s.as_bytes();
        for i in 0..s.len() - 1 {
            l += ((cs[i] - b'0') ^ 1) as i32;
            r -= (cs[i] - b'0') as i32;
            ans = ans.max(l + r);
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1423. 可获得的最大点数](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards){#1423}

{{< tabs "1423" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        ans = s = sum(cardPoints[-k:])
        for i, x in enumerate(cardPoints[:k]):
            s += x - cardPoints[-k + i]
            ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int s = 0, n = cardPoints.length;
        for (int i = n - k; i < n; ++i) {
            s += cardPoints[i];
        }
        int ans = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[i] - cardPoints[n - k + i];
            ans = Math.max(ans, s);
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
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int s = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int ans = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[i] - cardPoints[n - k + i];
            ans = max(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(cardPoints []int, k int) int {
	n := len(cardPoints)
	s := 0
	for _, x := range cardPoints[n-k:] {
		s += x
	}
	ans := s
	for i := 0; i < k; i++ {
		s += cardPoints[i] - cardPoints[n-k+i]
		ans = max(ans, s)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(cardPoints: number[], k: number): number {
    const n = cardPoints.length;
    let s = cardPoints.slice(-k).reduce((a, b) => a + b);
    let ans = s;
    for (let i = 0; i < k; ++i) {
        s += cardPoints[i] - cardPoints[n - k + i];
        ans = Math.max(ans, s);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        let n = card_points.len();
        let k = k as usize;
        let mut s: i32 = card_points[n - k..].iter().sum();
        let mut ans: i32 = s;
        for i in 0..k {
            s += card_points[i] - card_points[n - k + i];
            ans = ans.max(s);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function (cardPoints, k) {
    const n = cardPoints.length;
    let s = cardPoints.slice(-k).reduce((a, b) => a + b);
    let ans = s;
    for (let i = 0; i < k; ++i) {
        s += cardPoints[i] - cardPoints[n - k + i];
        ans = Math.max(ans, s);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxScore(int[] cardPoints, int k) {
        int n = cardPoints.Length;
        int s = cardPoints[^k..].Sum();
        int ans = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[i] - cardPoints[n - k + i];
            ans = Math.Max(ans, s);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $cardPoints
     * @param Integer $k
     * @return Integer
     */
    function maxScore($cardPoints, $k) {
        $n = count($cardPoints);
        $s = array_sum(array_slice($cardPoints, -$k));
        $ans = $s;
        for ($i = 0; $i < $k; ++$i) {
            $s += $cardPoints[$i] - $cardPoints[$n - $k + $i];
            $ans = max($ans, $s);
        }
        return $ans;
    }
}
```
{{% /tab %}}
{{% tab "scala" %}}
```scala
object Solution {
    def maxScore(cardPoints: Array[Int], k: Int): Int = {
        val n = cardPoints.length
        var s = cardPoints.takeRight(k).sum
        var ans = s
        for (i <- 0 until k) {
            s += cardPoints(i) - cardPoints(n - k + i)
            ans = ans.max(s)
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func maxScore(_ cardPoints: [Int], _ k: Int) -> Int {
        let n = cardPoints.count
        var s = cardPoints.suffix(k).reduce(0, +)
        var ans = s
        for i in 0..<k {
            s += cardPoints[i] - cardPoints[n - k + i]
            ans = max(ans, s)
        }
        return ans
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# @param {Integer[]} card_points
# @param {Integer} k
# @return {Integer}
def max_score(card_points, k)
  n = card_points.length
  s = card_points[-k..].sum
  ans = s
  k.times do |i|
    s += card_points[i] - card_points[n - k + i]
    ans = [ans, s].max
  end
  ans
end
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun maxScore(cardPoints: IntArray, k: Int): Int {
        val n = cardPoints.size
        var s = cardPoints.sliceArray(n - k until n).sum()
        var ans = s
        for (i in 0 until k) {
            s += cardPoints[i] - cardPoints[n - k + i]
            ans = maxOf(ans, s)
        }
        return ans
    }
}
```
{{% /tab %}}
{{% tab "dart" %}}
```dart
class Solution {
  int maxScore(List<int> cardPoints, int k) {
    int n = cardPoints.length;
    int s = cardPoints.sublist(n - k).reduce((a, b) => a + b);
    int ans = s;
    for (int i = 0; i < k; ++i) {
      s += cardPoints[i] - cardPoints[n - k + i];
      ans = s > ans ? s : ans;
    }
    return ans;
  }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>几张卡牌<strong> 排成一行</strong>，每张卡牌都有一个对应的点数。点数由整数数组 <code>cardPoints</code> 给出。</p>

<p>每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 <code>k</code> 张卡牌。</p>

<p>你的点数就是你拿到手中的所有卡牌的点数之和。</p>

<p>给你一个整数数组 <code>cardPoints</code> 和整数 <code>k</code>，请你返回可以获得的最大点数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cardPoints = [1,2,3,4,5,6,1], k = 3
<strong>输出：</strong>12
<strong>解释：</strong>第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可获得点数。最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cardPoints = [2,2,2], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>无论你拿起哪两张卡牌，可获得的点数总是 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>cardPoints = [9,7,7,9,7,7,9], k = 7
<strong>输出：</strong>55
<strong>解释：</strong>你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>cardPoints = [1,1000,1], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>你无法拿到中间那张卡牌，所以可以获得的最大点数为 1 。 
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>cardPoints = [1,79,80,1,1,1,200,1], k = 3
<strong>输出：</strong>202
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cardPoints.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= cardPoints[i] &lt;= 10^4</code></li>
	<li><code>1 &lt;= k &lt;= cardPoints.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们可以用一个长度为 $k$ 的滑动窗口来模拟这个过程。

初始时我们将窗口放在数组的末尾，即索引为 $n-k$ 到索引 $n-1$ 的这 $k$ 个位置，窗口内卡牌的点数之和记为 $s$，初始答案 $ans$ 的值也为 $s$。这其实是从数组的开头拿走 $0$ 张卡牌的情况。

接下来，我们考虑从数组的开头依次拿 $1, 2, ..., k$ 张卡牌的情况，假设取到的卡牌为 $cardPoints[i]$，那么我们将其加入 $s$，由于窗口的长度限制为 $k$，我们需要将 $cardPoints[n-k+i]$ 从 $s$ 中减去，这样我们就可以计算出拿到的 $k$ 张卡牌的点数之和，更新答案 $ans$。

时间复杂度 $O(k)$，其中 $k$ 给题目中给出的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        ans = s = sum(cardPoints[-k:])
        for i, x in enumerate(cardPoints[:k]):
            s += x - cardPoints[-k + i]
            ans = max(ans, s)
        return ans
```

#### Java

```java
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int s = 0, n = cardPoints.length;
        for (int i = n - k; i < n; ++i) {
            s += cardPoints[i];
        }
        int ans = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[i] - cardPoints[n - k + i];
            ans = Math.max(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int s = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int ans = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[i] - cardPoints[n - k + i];
            ans = max(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(cardPoints []int, k int) int {
	n := len(cardPoints)
	s := 0
	for _, x := range cardPoints[n-k:] {
		s += x
	}
	ans := s
	for i := 0; i < k; i++ {
		s += cardPoints[i] - cardPoints[n-k+i]
		ans = max(ans, s)
	}
	return ans
}
```

#### TypeScript

```ts
function maxScore(cardPoints: number[], k: number): number {
    const n = cardPoints.length;
    let s = cardPoints.slice(-k).reduce((a, b) => a + b);
    let ans = s;
    for (let i = 0; i < k; ++i) {
        s += cardPoints[i] - cardPoints[n - k + i];
        ans = Math.max(ans, s);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        let n = card_points.len();
        let k = k as usize;
        let mut s: i32 = card_points[n - k..].iter().sum();
        let mut ans: i32 = s;
        for i in 0..k {
            s += card_points[i] - card_points[n - k + i];
            ans = ans.max(s);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function (cardPoints, k) {
    const n = cardPoints.length;
    let s = cardPoints.slice(-k).reduce((a, b) => a + b);
    let ans = s;
    for (let i = 0; i < k; ++i) {
        s += cardPoints[i] - cardPoints[n - k + i];
        ans = Math.max(ans, s);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxScore(int[] cardPoints, int k) {
        int n = cardPoints.Length;
        int s = cardPoints[^k..].Sum();
        int ans = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[i] - cardPoints[n - k + i];
            ans = Math.Max(ans, s);
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $cardPoints
     * @param Integer $k
     * @return Integer
     */
    function maxScore($cardPoints, $k) {
        $n = count($cardPoints);
        $s = array_sum(array_slice($cardPoints, -$k));
        $ans = $s;
        for ($i = 0; $i < $k; ++$i) {
            $s += $cardPoints[$i] - $cardPoints[$n - $k + $i];
            $ans = max($ans, $s);
        }
        return $ans;
    }
}
```

#### Scala

```scala
object Solution {
    def maxScore(cardPoints: Array[Int], k: Int): Int = {
        val n = cardPoints.length
        var s = cardPoints.takeRight(k).sum
        var ans = s
        for (i <- 0 until k) {
            s += cardPoints(i) - cardPoints(n - k + i)
            ans = ans.max(s)
        }
        ans
    }
}
```

#### Swift

```swift
class Solution {
    func maxScore(_ cardPoints: [Int], _ k: Int) -> Int {
        let n = cardPoints.count
        var s = cardPoints.suffix(k).reduce(0, +)
        var ans = s
        for i in 0..<k {
            s += cardPoints[i] - cardPoints[n - k + i]
            ans = max(ans, s)
        }
        return ans
    }
}
```

#### Ruby

```rb
# @param {Integer[]} card_points
# @param {Integer} k
# @return {Integer}
def max_score(card_points, k)
  n = card_points.length
  s = card_points[-k..].sum
  ans = s
  k.times do |i|
    s += card_points[i] - card_points[n - k + i]
    ans = [ans, s].max
  end
  ans
end
```

#### Kotlin

```kotlin
class Solution {
    fun maxScore(cardPoints: IntArray, k: Int): Int {
        val n = cardPoints.size
        var s = cardPoints.sliceArray(n - k until n).sum()
        var ans = s
        for (i in 0 until k) {
            s += cardPoints[i] - cardPoints[n - k + i]
            ans = maxOf(ans, s)
        }
        return ans
    }
}
```

#### Dart

```dart
class Solution {
  int maxScore(List<int> cardPoints, int k) {
    int n = cardPoints.length;
    int s = cardPoints.sublist(n - k).reduce((a, b) => a + b);
    int ans = s;
    for (int i = 0; i < k; ++i) {
      s += cardPoints[i] - cardPoints[n - k + i];
      ans = s > ans ? s : ans;
    }
    return ans;
  }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1424. 对角线遍历 II](https://leetcode.cn/problems/diagonal-traverse-ii){#1424}

{{< tabs "1424" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        arr = []
        for i, row in enumerate(nums):
            for j, v in enumerate(row):
                arr.append((i + j, j, v))
        arr.sort()
        return [v[2] for v in arr]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        List<int[]> arr = new ArrayList<>();
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.get(i).size(); ++j) {
                arr.add(new int[] {i + j, j, nums.get(i).get(j)});
            }
        }
        arr.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); ++i) {
            ans[i] = arr.get(i)[2];
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
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                arr.push_back({i + j, j, nums[i][j]});
            }
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto& e : arr) {
            ans.push_back(get<2>(e));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDiagonalOrder(nums [][]int) []int {
	arr := [][]int{}
	for i, row := range nums {
		for j, v := range row {
			arr = append(arr, []int{i + j, j, v})
		}
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i][0] == arr[j][0] {
			return arr[i][1] < arr[j][1]
		}
		return arr[i][0] < arr[j][0]
	})
	ans := []int{}
	for _, v := range arr {
		ans = append(ans, v[2])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDiagonalOrder(nums: number[][]): number[] {
    const arr: number[][] = [];
    for (let i = 0; i < nums.length; ++i) {
        for (let j = 0; j < nums[i].length; ++j) {
            arr.push([i + j, j, nums[i][j]]);
        }
    }
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    return arr.map(x => x[2]);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] FindDiagonalOrder(IList<IList<int>> nums) {
        List<int[]> arr = new List<int[]>();
        for (int i = 0; i < nums.Count; ++i) {
            for (int j = 0; j < nums[i].Count; ++j) {
                arr.Add(new int[] { i + j, j, nums[i][j] });
            }
        }
        arr.Sort((a, b) => a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] ans = new int[arr.Count];
        for (int i = 0; i < arr.Count; ++i) {
            ans[i] = arr[i][2];
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个列表&nbsp;<code>nums</code>&nbsp;，里面每一个元素都是一个整数列表。请你依照下面各图的规则，按顺序返回&nbsp;<code>nums</code>&nbsp;中对角线上的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1424.Diagonal%20Traverse%20II/images/sample_1_1784.png" style="height: 143px; width: 158px;"></strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,4,2,7,5,3,8,6,9]
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1424.Diagonal%20Traverse%20II/images/sample_2_1784.png" style="height: 177px; width: 230px;"></strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
<strong>输出：</strong>[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
<strong>输出：</strong>[1,4,2,5,3,8,6,9,7,10,11]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3,4,5,6]]
<strong>输出：</strong>[1,2,3,4,5,6]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i].length &lt;=&nbsp;10^5</code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 10^9</code></li>
	<li><code>nums</code>&nbsp;中最多有&nbsp;<code>10^5</code>&nbsp;个数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们观察到：

-   每一条对角线上的 $i + j$ 的值都是相同的；
-   下一条对角线的 $i + j$ 的值比前一条对角线的大；
-   在同一条对角线中的 $i + j$ 是相同的，而 $j$ 值是从小到大递增。

因此，我们将所有数字以 $(i, j, \textit{nums}[i][j])$ 的形式存进 $\textit{arr}$，然后按照前两项排序。最后返回 $\textit{arr}$ 所有元素下标为 $2$ 的值组成的数组即可。

时间复杂度 $O(n \times \log n)$，其中 $n$ 是数组 $\textit{nums}$ 中元素的个数。空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        arr = []
        for i, row in enumerate(nums):
            for j, v in enumerate(row):
                arr.append((i + j, j, v))
        arr.sort()
        return [v[2] for v in arr]
```

#### Java

```java
class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        List<int[]> arr = new ArrayList<>();
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.get(i).size(); ++j) {
                arr.add(new int[] {i + j, j, nums.get(i).get(j)});
            }
        }
        arr.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); ++i) {
            ans[i] = arr.get(i)[2];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                arr.push_back({i + j, j, nums[i][j]});
            }
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto& e : arr) {
            ans.push_back(get<2>(e));
        }
        return ans;
    }
};
```

#### Go

```go
func findDiagonalOrder(nums [][]int) []int {
	arr := [][]int{}
	for i, row := range nums {
		for j, v := range row {
			arr = append(arr, []int{i + j, j, v})
		}
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i][0] == arr[j][0] {
			return arr[i][1] < arr[j][1]
		}
		return arr[i][0] < arr[j][0]
	})
	ans := []int{}
	for _, v := range arr {
		ans = append(ans, v[2])
	}
	return ans
}
```

#### TypeScript

```ts
function findDiagonalOrder(nums: number[][]): number[] {
    const arr: number[][] = [];
    for (let i = 0; i < nums.length; ++i) {
        for (let j = 0; j < nums[i].length; ++j) {
            arr.push([i + j, j, nums[i][j]]);
        }
    }
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    return arr.map(x => x[2]);
}
```

#### C#

```cs
public class Solution {
    public int[] FindDiagonalOrder(IList<IList<int>> nums) {
        List<int[]> arr = new List<int[]>();
        for (int i = 0; i < nums.Count; ++i) {
            for (int j = 0; j < nums[i].Count; ++j) {
                arr.Add(new int[] { i + j, j, nums[i][j] });
            }
        }
        arr.Sort((a, b) => a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] ans = new int[arr.Count];
        for (int i = 0; i < arr.Count; ++i) {
            ans[i] = arr[i][2];
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1425. 带限制的子序列和](https://leetcode.cn/problems/constrained-subsequence-sum){#1425}

{{< tabs "1425" >}}

{{% tab "python" %}}
```python
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        q = deque([0])
        n = len(nums)
        f = [0] * n
        ans = -inf
        for i, x in enumerate(nums):
            while i - q[0] > k:
                q.popleft()
            f[i] = max(0, f[q[0]]) + x
            ans = max(ans, f[i])
            while q and f[q[-1]] <= f[i]:
                q.pop()
            q.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int n = nums.length;
        int[] f = new int[n];
        int ans = -(1 << 30);
        for (int i = 0; i < n; ++i) {
            while (i - q.peekFirst() > k) {
                q.pollFirst();
            }
            f[i] = Math.max(0, f[q.peekFirst()]) + nums[i];
            ans = Math.max(ans, f[i]);
            while (!q.isEmpty() && f[q.peekLast()] <= f[i]) {
                q.pollLast();
            }
            q.offerLast(i);
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
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q = {0};
        int n = nums.size();
        int f[n];
        f[0] = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            while (i - q.front() > k) {
                q.pop_front();
            }
            f[i] = max(0, f[q.front()]) + nums[i];
            ans = max(ans, f[i]);
            while (!q.empty() && f[q.back()] <= f[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func constrainedSubsetSum(nums []int, k int) int {
	q := Deque{}
	q.PushFront(0)
	n := len(nums)
	f := make([]int, n)
	ans := nums[0]
	for i, x := range nums {
		for i-q.Front() > k {
			q.PopFront()
		}
		f[i] = max(0, f[q.Front()]) + x
		ans = max(ans, f[i])
		for !q.Empty() && f[q.Back()] <= f[i] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return ans
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function constrainedSubsetSum(nums: number[], k: number): number {
    const q = new Deque<number>();
    const n = nums.length;
    q.pushBack(0);
    let ans = nums[0];
    const f: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        while (i - q.frontValue()! > k) {
            q.popFront();
        }
        f[i] = Math.max(0, f[q.frontValue()!]!) + nums[i];
        ans = Math.max(ans, f[i]);
        while (!q.isEmpty() && f[q.backValue()!]! <= f[i]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return ans;
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回 <strong>非空</strong>&nbsp;子序列元素和的最大值，子序列需要满足：子序列中每两个 <strong>相邻</strong>&nbsp;的整数&nbsp;<code>nums[i]</code>&nbsp;和&nbsp;<code>nums[j]</code>&nbsp;，它们在原数组中的下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;满足&nbsp;<code>i &lt; j</code>&nbsp;且 <code>j - i &lt;= k</code> 。</p>

<p>数组的子序列定义为：将数组中的若干个数字删除（可以删除 0 个数字），剩下的数字按照原本的顺序排布。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [10,2,-10,5,20], k = 2
<strong>输出：</strong>37
<strong>解释：</strong>子序列为 [10, 2, 5, 20] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-1,-2,-3], k = 1
<strong>输出：</strong>-1
<strong>解释：</strong>子序列必须是非空的，所以我们选择最大的数字。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [10,-2,-10,-5,20], k = 2
<strong>输出：</strong>23
<strong>解释：</strong>子序列为 [10, -2, -5, 20] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>-10^4&nbsp;&lt;= nums[i] &lt;= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 单调队列

我们定义 $f[i]$ 表示以 $\textit{nums}[i]$ 结尾的满足条件的子序列的最大和。初始时 $f[i] = 0$，答案为 $\max_{0 \leq i \lt n} f(i)$。

我们注意到题目需要我们维护滑动窗口的最大值，这就是一个典型的单调队列应用场景。我们可以使用单调队列来优化动态规划的转移。

我们维护一个从队首到队尾单调递减的单调队列 $q$，队列中存储的是下标 $i$，初始时，我们将一个哨兵 $0$ 加入队列中。

我们遍历 $i$ 从 $0$ 到 $n - 1$，对于每个 $i$，我们执行以下操作：

-   如果队首元素 $q[0]$ 满足 $i - q[0] > k$，说明队首元素已经不在滑动窗口内，我们需要从队首弹出队首元素；
-   然后，我们计算 $f[i] = \max(0, f[q[0]]) + \textit{nums}[i]$，表示我们将 $\textit{nums}[i]$ 加入滑动窗口后的最大子序列和；
-   接下来，我们更新答案 $\textit{ans} = \max(\textit{ans}, f[i])$；
-   最后，我们将 $i$ 加入队列尾部，并且保持队列的单调性，即如果 $f[q[\textit{back}]] \leq f[i]$，我们需要将队尾元素弹出，直到队列为空或者 $f[q[\textit{back}]] > f[i]$。

最终答案即为 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        q = deque([0])
        n = len(nums)
        f = [0] * n
        ans = -inf
        for i, x in enumerate(nums):
            while i - q[0] > k:
                q.popleft()
            f[i] = max(0, f[q[0]]) + x
            ans = max(ans, f[i])
            while q and f[q[-1]] <= f[i]:
                q.pop()
            q.append(i)
        return ans
```

#### Java

```java
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int n = nums.length;
        int[] f = new int[n];
        int ans = -(1 << 30);
        for (int i = 0; i < n; ++i) {
            while (i - q.peekFirst() > k) {
                q.pollFirst();
            }
            f[i] = Math.max(0, f[q.peekFirst()]) + nums[i];
            ans = Math.max(ans, f[i]);
            while (!q.isEmpty() && f[q.peekLast()] <= f[i]) {
                q.pollLast();
            }
            q.offerLast(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q = {0};
        int n = nums.size();
        int f[n];
        f[0] = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            while (i - q.front() > k) {
                q.pop_front();
            }
            f[i] = max(0, f[q.front()]) + nums[i];
            ans = max(ans, f[i]);
            while (!q.empty() && f[q.back()] <= f[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }
};
```

#### Go

```go
func constrainedSubsetSum(nums []int, k int) int {
	q := Deque{}
	q.PushFront(0)
	n := len(nums)
	f := make([]int, n)
	ans := nums[0]
	for i, x := range nums {
		for i-q.Front() > k {
			q.PopFront()
		}
		f[i] = max(0, f[q.Front()]) + x
		ans = max(ans, f[i])
		for !q.Empty() && f[q.Back()] <= f[i] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return ans
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function constrainedSubsetSum(nums: number[], k: number): number {
    const q = new Deque<number>();
    const n = nums.length;
    q.pushBack(0);
    let ans = nums[0];
    const f: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        while (i - q.frontValue()! > k) {
            q.popFront();
        }
        f[i] = Math.max(0, f[q.frontValue()!]!) + nums[i];
        ans = Math.max(ans, f[i]);
        while (!q.isEmpty() && f[q.backValue()!]! <= f[i]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return ans;
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1426. 数元素 🔒](https://leetcode.cn/problems/counting-elements){#1426}

{{< tabs "1426" >}}

{{% tab "python" %}}
```python
class Solution:
    def countElements(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        return sum(v for x, v in cnt.items() if cnt[x + 1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countElements(int[] arr) {
        int[] cnt = new int[1001];
        for (int x : arr) {
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 0; x < 1000; ++x) {
            if (cnt[x + 1] > 0) {
                ans += cnt[x];
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
    int countElements(vector<int>& arr) {
        int cnt[1001]{};
        for (int x : arr) {
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 0; x < 1000; ++x) {
            if (cnt[x + 1]) {
                ans += cnt[x];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countElements(arr []int) (ans int) {
	mx := slices.Max(arr)
	cnt := make([]int, mx+1)
	for _, x := range arr {
		cnt[x]++
	}
	for x := 0; x < mx; x++ {
		if cnt[x+1] > 0 {
			ans += cnt[x]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countElements(arr: number[]): number {
    const mx = Math.max(...arr);
    const cnt = Array(mx + 1).fill(0);
    for (const x of arr) {
        ++cnt[x];
    }
    let ans = 0;
    for (let i = 0; i < mx; ++i) {
        if (cnt[i + 1] > 0) {
            ans += cnt[i];
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_elements(arr: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &num in &arr {
            *cnt.entry(num).or_insert(0) += 1;
        }
        cnt.iter()
            .filter(|(&x, _)| cnt.contains_key(&(x + 1)))
            .map(|(_, &v)| v)
            .sum()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @return {number}
 */
var countElements = function (arr) {
    const mx = Math.max(...arr);
    const cnt = Array(mx + 1).fill(0);
    for (const x of arr) {
        ++cnt[x];
    }
    let ans = 0;
    for (let i = 0; i < mx; ++i) {
        if (cnt[i + 1] > 0) {
            ans += cnt[i];
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function countElements($arr) {
        $cnt = array_count_values($arr);
        $ans = 0;
        foreach ($cnt as $x => $v) {
            if (isset($cnt[$x + 1])) {
                $ans += $v;
            }
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>， 对于元素 <code>x</code> ，只有当 <code>x + 1</code> 也在数组&nbsp;<code>arr</code> 里时，才能记为 <code>1</code> 个数。</p>

<p>如果数组&nbsp;<code>arr</code> 里有重复的数，每个重复的数单独计算。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>1 和 2 被计算次数因为 2 和 3 在数组 arr 里。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,3,3,5,5,7,7]
<strong>输出：</strong>0
<strong>解释：</strong>所有的数都不算, 因为数组里没有 2、4、6、8。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个哈希表或数组 $cnt$ 记录数组 $arr$ 中的每个数出现的次数，然后遍历 $cnt$ 中的每个数 $x$，如果 $x+1$ 也在 $cnt$ 中，那么就将 $cnt[x]$ 加到答案中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countElements(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        return sum(v for x, v in cnt.items() if cnt[x + 1])
```

#### Java

```java
class Solution {
    public int countElements(int[] arr) {
        int[] cnt = new int[1001];
        for (int x : arr) {
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 0; x < 1000; ++x) {
            if (cnt[x + 1] > 0) {
                ans += cnt[x];
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
    int countElements(vector<int>& arr) {
        int cnt[1001]{};
        for (int x : arr) {
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 0; x < 1000; ++x) {
            if (cnt[x + 1]) {
                ans += cnt[x];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countElements(arr []int) (ans int) {
	mx := slices.Max(arr)
	cnt := make([]int, mx+1)
	for _, x := range arr {
		cnt[x]++
	}
	for x := 0; x < mx; x++ {
		if cnt[x+1] > 0 {
			ans += cnt[x]
		}
	}
	return
}
```

#### TypeScript

```ts
function countElements(arr: number[]): number {
    const mx = Math.max(...arr);
    const cnt = Array(mx + 1).fill(0);
    for (const x of arr) {
        ++cnt[x];
    }
    let ans = 0;
    for (let i = 0; i < mx; ++i) {
        if (cnt[i + 1] > 0) {
            ans += cnt[i];
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_elements(arr: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &num in &arr {
            *cnt.entry(num).or_insert(0) += 1;
        }
        cnt.iter()
            .filter(|(&x, _)| cnt.contains_key(&(x + 1)))
            .map(|(_, &v)| v)
            .sum()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @return {number}
 */
var countElements = function (arr) {
    const mx = Math.max(...arr);
    const cnt = Array(mx + 1).fill(0);
    for (const x of arr) {
        ++cnt[x];
    }
    let ans = 0;
    for (let i = 0; i < mx; ++i) {
        if (cnt[i + 1] > 0) {
            ans += cnt[i];
        }
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function countElements($arr) {
        $cnt = array_count_values($arr);
        $ans = 0;
        foreach ($cnt as $x => $v) {
            if (isset($cnt[$x + 1])) {
                $ans += $v;
            }
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1427. 字符串的左右移 🔒](https://leetcode.cn/problems/perform-string-shifts){#1427}

{{< tabs "1427" >}}

{{% tab "python" %}}
```python
class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        x = sum((b if a else -b) for a, b in shift)
        x %= len(s)
        return s[-x:] + s[:-x]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String stringShift(String s, int[][] shift) {
        int x = 0;
        for (var e : shift) {
            if (e[0] == 0) {
                e[1] *= -1;
            }
            x += e[1];
        }
        int n = s.length();
        x = (x % n + n) % n;
        return s.substring(n - x) + s.substring(0, n - x);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int x = 0;
        for (auto& e : shift) {
            if (e[0] == 0) {
                e[1] = -e[1];
            }
            x += e[1];
        }
        int n = s.size();
        x = (x % n + n) % n;
        return s.substr(n - x, x) + s.substr(0, n - x);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stringShift(s string, shift [][]int) string {
	x := 0
	for _, e := range shift {
		if e[0] == 0 {
			e[1] = -e[1]
		}
		x += e[1]
	}
	n := len(s)
	x = (x%n + n) % n
	return s[n-x:] + s[:n-x]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stringShift(s: string, shift: number[][]): string {
    let x = 0;
    for (const [a, b] of shift) {
        x += a === 0 ? -b : b;
    }
    x %= s.length;
    if (x < 0) {
        x += s.length;
    }
    return s.slice(-x) + s.slice(0, -x);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含小写英文字母的字符串&nbsp;<code>s</code>&nbsp;以及一个矩阵&nbsp;<code>shift</code>，其中&nbsp;<code>shift[i] = [direction, amount]</code>：</p>

<ul>
	<li><code>direction</code>&nbsp;可以为&nbsp;<code>0</code>&nbsp;（表示左移）或&nbsp;<code>1</code>&nbsp;（表示右移）。</li>
	<li><code>amount</code>&nbsp;表示&nbsp;<code>s</code>&nbsp;左右移的位数。</li>
	<li>左移 1 位表示移除&nbsp;<code>s</code>&nbsp;的第一个字符，并将该字符插入到 <code>s</code> 的结尾。</li>
	<li>类似地，右移 1 位表示移除&nbsp;<code>s</code>&nbsp;的最后一个字符，并将该字符插入到 <code>s</code> 的开头。</li>
</ul>

<p>对这个字符串进行所有操作后，返回最终结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;abc&quot;, shift = [[0,1],[1,2]]
<strong>输出：</strong>&quot;cab&quot;
<strong>解释：</strong>
[0,1] 表示左移 1 位。 &quot;abc&quot; -&gt; &quot;bca&quot;
[1,2] 表示右移 2 位。 &quot;bca&quot; -&gt; &quot;cab&quot;</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;abcdefg&quot;, shift = [[1,1],[1,1],[0,2],[1,3]]
<strong>输出：</strong>&quot;efgabcd&quot;
<strong>解释：</strong> 
[1,1] 表示右移 1 位。 &quot;abcdefg&quot; -&gt; &quot;gabcdef&quot;
[1,1] 表示右移 1 位。 &quot;gabcdef&quot; -&gt; &quot;fgabcde&quot;
[0,2] 表示左移 2 位。 &quot;fgabcde&quot; -&gt; &quot;abcdefg&quot;
[1,3] 表示右移 3 位。 &quot;abcdefg&quot; -&gt; &quot;efgabcd&quot;</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母</li>
	<li><code>1 &lt;= shift.length &lt;= 100</code></li>
	<li><code>shift[i].length == 2</code></li>
	<li><code>0 &lt;= shift[i][0] &lt;= 1</code></li>
	<li><code>0 &lt;= shift[i][1] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们不妨记字符串 $s$ 的长度为 $n$。接下来遍历数组 $shift$，累加得到最终的偏移量 $x$，然后将 $x$ 对 $n$ 取模，最终结果就是将 $s$ 的前 $n - x$ 个字符移动到末尾。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是字符串 $s$ 的长度和数组 $shift$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        x = sum((b if a else -b) for a, b in shift)
        x %= len(s)
        return s[-x:] + s[:-x]
```

#### Java

```java
class Solution {
    public String stringShift(String s, int[][] shift) {
        int x = 0;
        for (var e : shift) {
            if (e[0] == 0) {
                e[1] *= -1;
            }
            x += e[1];
        }
        int n = s.length();
        x = (x % n + n) % n;
        return s.substring(n - x) + s.substring(0, n - x);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int x = 0;
        for (auto& e : shift) {
            if (e[0] == 0) {
                e[1] = -e[1];
            }
            x += e[1];
        }
        int n = s.size();
        x = (x % n + n) % n;
        return s.substr(n - x, x) + s.substr(0, n - x);
    }
};
```

#### Go

```go
func stringShift(s string, shift [][]int) string {
	x := 0
	for _, e := range shift {
		if e[0] == 0 {
			e[1] = -e[1]
		}
		x += e[1]
	}
	n := len(s)
	x = (x%n + n) % n
	return s[n-x:] + s[:n-x]
}
```

#### TypeScript

```ts
function stringShift(s: string, shift: number[][]): string {
    let x = 0;
    for (const [a, b] of shift) {
        x += a === 0 ? -b : b;
    }
    x %= s.length;
    if (x < 0) {
        x += s.length;
    }
    return s.slice(-x) + s.slice(0, -x);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1428. 至少有一个 1 的最左端列 🔒](https://leetcode.cn/problems/leftmost-column-with-at-least-a-one){#1428}

{{< tabs "1428" >}}

{{% tab "python" %}}
```python
# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
# class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:


class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: "BinaryMatrix") -> int:
        m, n = binaryMatrix.dimensions()
        ans = n
        for i in range(m):
            j = bisect_left(range(n), 1, key=lambda k: binaryMatrix.get(i, k))
            ans = min(ans, j)
        return -1 if ans >= n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> e = binaryMatrix.dimensions();
        int m = e.get(0), n = e.get(1);
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.get(i, mid) == 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = Math.min(ans, l);
        }
        return ans >= n ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
        auto e = binaryMatrix.dimensions();
        int m = e[0], n = e[1];
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.get(i, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, l);
        }
        return ans >= n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * type BinaryMatrix struct {
 *     Get func(int, int) int
 *     Dimensions func() []int
 * }
 */

func leftMostColumnWithOne(binaryMatrix BinaryMatrix) int {
	e := binaryMatrix.Dimensions()
	m, n := e[0], e[1]
	ans := n
	for i := 0; i < m; i++ {
		l, r := 0, n
		for l < r {
			mid := (l + r) >> 1
			if binaryMatrix.Get(i, mid) == 1 {
				r = mid
			} else {
				l = mid + 1
			}
		}
		ans = min(ans, l)
	}
	if ans >= n {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *      get(row: number, col: number): number {}
 *
 *      dimensions(): number[] {}
 * }
 */

function leftMostColumnWithOne(binaryMatrix: BinaryMatrix) {
    const [m, n] = binaryMatrix.dimensions();
    let ans = n;
    for (let i = 0; i < m; ++i) {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (binaryMatrix.get(i, mid) === 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = Math.min(ans, l);
    }
    return ans >= n ? -1 : ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 *  struct BinaryMatrix;
 *  impl BinaryMatrix {
 *     fn get(row: i32, col: i32) -> i32;
 *     fn dimensions() -> Vec<i32>;
 * };
 */

impl Solution {
    pub fn left_most_column_with_one(binaryMatrix: &BinaryMatrix) -> i32 {
        let e = binaryMatrix.dimensions();
        let m = e[0] as usize;
        let n = e[1] as usize;
        let mut ans = n;

        for i in 0..m {
            let (mut l, mut r) = (0, n);
            while l < r {
                let mid = (l + r) / 2;
                if binaryMatrix.get(i as i32, mid as i32) == 1 {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = ans.min(l);
        }

        if ans >= n {
            -1
        } else {
            ans as i32
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * // This is BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *     public int Get(int row, int col) {}
 *     public IList<int> Dimensions() {}
 * }
 */

class Solution {
    public int LeftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        var e = binaryMatrix.Dimensions();
        int m = e[0], n = e[1];
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.Get(i, mid) == 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = Math.Min(ans, l);
        }
        return ans >= n ? -1 : ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>行排序二进制矩阵</strong>&nbsp;表示所有元素都是 <code>0</code> 或 <code>1</code>，并且矩阵的每一行都以非递减排序。</p>

<p>给定一个 <strong>行排序二进制矩阵&nbsp;</strong><code>binaryMatrix</code>，返回至少包含一个&nbsp;<code>1</code>&nbsp;的 <strong>最左端列&nbsp;</strong>的索引（从 0 开始）。如果这样的列不存在，返回&nbsp;<code>-1</code>。</p>

<p><strong>您不能直接访问该二进制矩阵。</strong>你只可以通过&nbsp;<code>BinaryMatrix</code>&nbsp;接口来访问。</p>

<ul>
	<li><code>BinaryMatrix.get(row, col)</code>&nbsp;返回位于索引&nbsp;<code>(row, col)</code>&nbsp;（从 0 开始）的元素。</li>
	<li><code>BinaryMatrix.dimensions()</code>&nbsp;返回含有 2 个元素的列表&nbsp;<code>[rows, cols]</code>，表示这是一个&nbsp;<code>rows *&nbsp;cols</code>的矩阵。</li>
</ul>

<p>如果提交的答案调用&nbsp;<code>BinaryMatrix.get</code>&nbsp;超过 <code>1000</code> 次，则该答案会被判定为<em>错误答案</em>。提交任何试图规避判定机制的答案将会被取消资格。</p>

<p>下列示例中，&nbsp;<code>mat</code>&nbsp;为给定的二进制矩阵。您不能直接访问该矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1428.Leftmost%20Column%20with%20at%20Least%20a%20One/images/untitled-diagram-5.jpg" style="height:81px; width:81px" /></strong></p>

<pre>
<strong>输入:</strong> mat = [[0,0],[1,1]]
<strong>输出:</strong> 0
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1428.Leftmost%20Column%20with%20at%20Least%20a%20One/images/untitled-diagram-4.jpg" style="height:81px; width:81px" /></strong></p>

<pre>
<strong>输入:</strong> mat = [[0,0],[0,1]]
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1428.Leftmost%20Column%20with%20at%20Least%20a%20One/images/untitled-diagram-3.jpg" style="height:81px; width:81px" /></strong></p>

<pre>
<strong>输入:</strong> mat = [[0,0],[0,0]]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>rows == mat.length</code></li>
	<li><code>cols == mat[i].length</code></li>
	<li><code>1 &lt;= rows, cols&nbsp;&lt;= 100</code></li>
	<li><code>mat[i][j]</code>&nbsp;只会是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li><code>mat[i]</code>&nbsp;已按非递减顺序排序。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们先调用 `BinaryMatrix.dimensions()` 得到矩阵的行数 $m$ 和列数 $n$，然后对于每一行，我们使用二分查找来找到最左边的 $1$ 所在的列数 $j$，找出所有行中最小的满足 $j$ 的值即为答案。如果不存在这样的列，则返回 $-1$。

时间复杂度 $O(m \times \log n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。需要遍历每一行，每一行内使用二分查找，时间复杂度为 $O(\log n)$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
# class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:


class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: "BinaryMatrix") -> int:
        m, n = binaryMatrix.dimensions()
        ans = n
        for i in range(m):
            j = bisect_left(range(n), 1, key=lambda k: binaryMatrix.get(i, k))
            ans = min(ans, j)
        return -1 if ans >= n else ans
```

#### Java

```java
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> e = binaryMatrix.dimensions();
        int m = e.get(0), n = e.get(1);
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.get(i, mid) == 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = Math.min(ans, l);
        }
        return ans >= n ? -1 : ans;
    }
}
```

#### C++

```cpp
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
        auto e = binaryMatrix.dimensions();
        int m = e[0], n = e[1];
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.get(i, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, l);
        }
        return ans >= n ? -1 : ans;
    }
};
```

#### Go

```go
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * type BinaryMatrix struct {
 *     Get func(int, int) int
 *     Dimensions func() []int
 * }
 */

func leftMostColumnWithOne(binaryMatrix BinaryMatrix) int {
	e := binaryMatrix.Dimensions()
	m, n := e[0], e[1]
	ans := n
	for i := 0; i < m; i++ {
		l, r := 0, n
		for l < r {
			mid := (l + r) >> 1
			if binaryMatrix.Get(i, mid) == 1 {
				r = mid
			} else {
				l = mid + 1
			}
		}
		ans = min(ans, l)
	}
	if ans >= n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *      get(row: number, col: number): number {}
 *
 *      dimensions(): number[] {}
 * }
 */

function leftMostColumnWithOne(binaryMatrix: BinaryMatrix) {
    const [m, n] = binaryMatrix.dimensions();
    let ans = n;
    for (let i = 0; i < m; ++i) {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (binaryMatrix.get(i, mid) === 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = Math.min(ans, l);
    }
    return ans >= n ? -1 : ans;
}
```

#### Rust

```rust
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 *  struct BinaryMatrix;
 *  impl BinaryMatrix {
 *     fn get(row: i32, col: i32) -> i32;
 *     fn dimensions() -> Vec<i32>;
 * };
 */

impl Solution {
    pub fn left_most_column_with_one(binaryMatrix: &BinaryMatrix) -> i32 {
        let e = binaryMatrix.dimensions();
        let m = e[0] as usize;
        let n = e[1] as usize;
        let mut ans = n;

        for i in 0..m {
            let (mut l, mut r) = (0, n);
            while l < r {
                let mid = (l + r) / 2;
                if binaryMatrix.get(i as i32, mid as i32) == 1 {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = ans.min(l);
        }

        if ans >= n {
            -1
        } else {
            ans as i32
        }
    }
}
```

#### C#

```cs
/**
 * // This is BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *     public int Get(int row, int col) {}
 *     public IList<int> Dimensions() {}
 * }
 */

class Solution {
    public int LeftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        var e = binaryMatrix.Dimensions();
        int m = e[0], n = e[1];
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.Get(i, mid) == 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = Math.Min(ans, l);
        }
        return ans >= n ? -1 : ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1429. 第一个唯一数字 🔒](https://leetcode.cn/problems/first-unique-number){#1429}

{{< tabs "1429" >}}

{{% tab "python" %}}
```python
class FirstUnique:
    def __init__(self, nums: List[int]):
        self.cnt = Counter(nums)
        self.q = deque(nums)

    def showFirstUnique(self) -> int:
        while self.q and self.cnt[self.q[0]] != 1:
            self.q.popleft()
        return -1 if not self.q else self.q[0]

    def add(self, value: int) -> None:
        self.cnt[value] += 1
        self.q.append(value)


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FirstUnique {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Deque<Integer> q = new ArrayDeque<>();

    public FirstUnique(int[] nums) {
        for (int v : nums) {
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
            q.offer(v);
        }
    }

    public int showFirstUnique() {
        while (!q.isEmpty() && cnt.get(q.peekFirst()) != 1) {
            q.poll();
        }
        return q.isEmpty() ? -1 : q.peekFirst();
    }

    public void add(int value) {
        cnt.put(value, cnt.getOrDefault(value, 0) + 1);
        q.offer(value);
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int& v : nums) {
            ++cnt[v];
            q.push_back(v);
        }
    }

    int showFirstUnique() {
        while (q.size() && cnt[q.front()] != 1) q.pop_front();
        return q.size() ? q.front() : -1;
    }

    void add(int value) {
        ++cnt[value];
        q.push_back(value);
    }

private:
    unordered_map<int, int> cnt;
    deque<int> q;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type FirstUnique struct {
	cnt map[int]int
	q   []int
}

func Constructor(nums []int) FirstUnique {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
	}
	return FirstUnique{cnt, nums}
}

func (this *FirstUnique) ShowFirstUnique() int {
	for len(this.q) > 0 && this.cnt[this.q[0]] != 1 {
		this.q = this.q[1:]
	}
	if len(this.q) > 0 {
		return this.q[0]
	}
	return -1
}

func (this *FirstUnique) Add(value int) {
	this.cnt[value]++
	this.q = append(this.q, value)
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.ShowFirstUnique();
 * obj.Add(value);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一系列整数，插入一个队列中，找出队列中第一个唯一整数。</p>

<p>实现 <code>FirstUnique</code> 类：</p>

<ul>
	<li><code>FirstUnique(int[] nums)</code> 用数组里的数字初始化队列。</li>
	<li><code>int showFirstUnique()</code> 返回队列中的<strong> 第一个唯一 </strong>整数的值。如果没有唯一整数，返回 -1。（译者注：此方法不移除队列中的任何元素）</li>
	<li><code>void add(int value)</code> 将 value 插入队列中。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
<strong>输出：</strong>
[null,2,null,2,null,3,null,-1]
<strong>解释：</strong>
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // 返回 2
firstUnique.add(5);            // 此时队列为 [2,3,5,5]
firstUnique.showFirstUnique(); // 返回 2
firstUnique.add(2);            // 此时队列为 [2,3,5,5,2]
firstUnique.showFirstUnique(); // 返回 3
firstUnique.add(3);            // 此时队列为 [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // 返回 -1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
<strong>输出：</strong>
[null,-1,null,null,null,null,null,17]
<strong>解释：</strong>
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // 返回 -1
firstUnique.add(7);            // 此时队列为 [7,7,7,7,7,7,7]
firstUnique.add(3);            // 此时队列为 [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // 此时队列为 [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // 此时队列为 [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // 此时队列为 [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // 返回 17
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
<strong>输出：</strong>
[null,809,null,-1]
<strong>解释：</strong>
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // 返回 809
firstUnique.add(809);          // 此时队列为 [809,809]
firstUnique.showFirstUnique(); // 返回 -1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>1 <= nums[i] <= 10^8</code></li>
	<li><code>1 <= value <= 10^8</code></li>
	<li>最多调用 <code>5000</code> 次 <code>showFirstUnique</code> 和 <code>add</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双端队列

我们可以使用哈希表 $cnt$ 统计每个数字出现的次数，使用双端队列 $q$ 按顺序维护出现的数字。

调用 `showFirstUnique` 方法时，判断队列 $q$ 的队头元素是否在哈希表 $cnt$ 中出现的次数是否为 $1$，如果是，则返回队头元素，否则将队头元素弹出，直到队列为空或者队头元素在哈希表 $cnt$ 中出现的次数为 $1$，如果队列为空，则返回 $-1$。

调用 `add` 方法时，将数字加入哈希表 $cnt$ 中，并将数字加入队列 $q$ 中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class FirstUnique:
    def __init__(self, nums: List[int]):
        self.cnt = Counter(nums)
        self.unique = OrderedDict({v: 1 for v in nums if self.cnt[v] == 1})

    def showFirstUnique(self) -> int:
        return -1 if not self.unique else next(v for v in self.unique.keys())

    def add(self, value: int) -> None:
        self.cnt[value] += 1
        if self.cnt[value] == 1:
            self.unique[value] = 1
        elif value in self.unique:
            self.unique.pop(value)


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
```

#### Java

```java
class FirstUnique {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Set<Integer> unique = new LinkedHashSet<>();

    public FirstUnique(int[] nums) {
        for (int v : nums) {
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
        }
        for (int v : nums) {
            if (cnt.get(v) == 1) {
                unique.add(v);
            }
        }
    }

    public int showFirstUnique() {
        return unique.isEmpty() ? -1 : unique.iterator().next();
    }

    public void add(int value) {
        cnt.put(value, cnt.getOrDefault(value, 0) + 1);
        if (cnt.get(value) == 1) {
            unique.add(value);
        } else {
            unique.remove(value);
        }
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */
```

#### C++

```cpp
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int& v : nums) {
            ++cnt[v];
            q.push_back(v);
        }
    }

    int showFirstUnique() {
        while (q.size() && cnt[q.front()] != 1) q.pop_front();
        return q.size() ? q.front() : -1;
    }

    void add(int value) {
        ++cnt[value];
        q.push_back(value);
    }

private:
    unordered_map<int, int> cnt;
    deque<int> q;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
```

#### Go

```go
type FirstUnique struct {
	cnt map[int]int
	q   []int
}

func Constructor(nums []int) FirstUnique {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
	}
	return FirstUnique{cnt, nums}
}

func (this *FirstUnique) ShowFirstUnique() int {
	for len(this.q) > 0 && this.cnt[this.q[0]] != 1 {
		this.q = this.q[1:]
	}
	if len(this.q) > 0 {
		return this.q[0]
	}
	return -1
}

func (this *FirstUnique) Add(value int) {
	this.cnt[value]++
	this.q = append(this.q, value)
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.ShowFirstUnique();
 * obj.Add(value);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class FirstUnique:
    def __init__(self, nums: List[int]):
        self.cnt = Counter(nums)
        self.q = deque(nums)

    def showFirstUnique(self) -> int:
        while self.q and self.cnt[self.q[0]] != 1:
            self.q.popleft()
        return -1 if not self.q else self.q[0]

    def add(self, value: int) -> None:
        self.cnt[value] += 1
        self.q.append(value)


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
```

#### Java

```java
class FirstUnique {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Deque<Integer> q = new ArrayDeque<>();

    public FirstUnique(int[] nums) {
        for (int v : nums) {
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
            q.offer(v);
        }
    }

    public int showFirstUnique() {
        while (!q.isEmpty() && cnt.get(q.peekFirst()) != 1) {
            q.poll();
        }
        return q.isEmpty() ? -1 : q.peekFirst();
    }

    public void add(int value) {
        cnt.put(value, cnt.getOrDefault(value, 0) + 1);
        q.offer(value);
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
