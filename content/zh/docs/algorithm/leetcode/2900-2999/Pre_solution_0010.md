---
title: "2990_贷款类型 🔒"
date: 2025-10-08T18:39:48+08:00
weight: 10
tags: [位运算, 动态规划, 哈希表, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 状态压缩, 记忆化搜索]
---

{{< markmap >}}
### [2990_贷款类型 🔒](#2990)
#### [数据库](#2990)
### [2991_最好的三家酒庄 🔒](#2991)
#### [数据库](#2991)
### [2992_自整除排列的数量 🔒](#2992)
#### [位运算](#2992)
#### [数组](#2992)
#### [数学](#2992)
#### [动态规划](#2992)
#### [回溯](#2992)
#### [状态压缩](#2992)
#### [数论](#2992)
### [2993_发生在周五的交易 I 🔒](#2993)
#### [数据库](#2993)
### [2994_发生在周五的交易 II 🔒](#2994)
#### [数据库](#2994)
### [2995_观众变主播 🔒](#2995)
#### [数据库](#2995)
### [2996_大于等于顺序前缀和的最小缺失整数](#2996)
#### [数组](#2996)
#### [哈希表](#2996)
#### [排序](#2996)
### [2997_使数组异或和等于 K 的最少操作次数](#2997)
#### [位运算](#2997)
#### [数组](#2997)
### [2998_使 X 和 Y 相等的最少操作次数](#2998)
#### [广度优先搜索](#2998)
#### [记忆化搜索](#2998)
#### [动态规划](#2998)
### [2999_统计强大整数的数目](#2999)
#### [数学](#2999)
#### [字符串](#2999)
#### [动态规划](#2999)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2990_贷款类型 🔒
___
#### 数据库
---
### 2991_最好的三家酒庄 🔒
___
#### 数据库
---
### 2992_自整除排列的数量 🔒
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
___
#### 数论
---
### 2993_发生在周五的交易 I 🔒
___
#### 数据库
---
### 2994_发生在周五的交易 II 🔒
___
#### 数据库
---
### 2995_观众变主播 🔒
___
#### 数据库
---
### 2996_大于等于顺序前缀和的最小缺失整数
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 2997_使数组异或和等于 K 的最少操作次数
___
#### 位运算
___
#### 数组
---
### 2998_使 X 和 Y 相等的最少操作次数
___
#### 广度优先搜索
___
#### 记忆化搜索
___
#### 动态规划
---
### 2999_统计强大整数的数目
___
#### 数学
___
#### 字符串
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 哈希表 |
| 回溯 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 数论 | 状态压缩 |
| 记忆化搜索 |  |  |

# [2990. 贷款类型 🔒](https://leetcode.cn/problems/loan-types){#2990}

{{< tabs "2990" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT user_id
FROM Loans
GROUP BY 1
HAVING SUM(loan_type = 'Refinance') > 0 AND SUM(loan_type = 'Mortgage') > 0
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Loans</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| loan_id     | int     |
| user_id     | int     |
| loan_type   | varchar |
+-------------+---------+
loan_id 是这张表具有唯一值的列。
该表包含 loan_id, user_id,和 loan_type。
</pre>

<p>编写一个解决方案，找出所有具有同时具有&nbsp;<strong>Refinance</strong> 贷款类型和&nbsp;<strong>Mortgage</strong>&nbsp;贷款类型的&nbsp;<code>user_id</code>（需去重）。</p>

<p>按 <em><strong>升序</strong> 返回结果表中的 </em><code>user_id</code>。</p>

<p>返回结果表格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Loans table:
+---------+---------+-----------+
| loan_id | user_id | loan_type |
+---------+---------+-----------+
| 683     | 101     | Mortgage  |
| 218     | 101     | AutoLoan  |
| 802     | 101     | Inschool  |
| 593     | 102     | Mortgage  |
| 138     | 102     | Refinance |
| 294     | 102     | Inschool  |
| 308     | 103     | Refinance |
| 389     | 104     | Mortgage  |
+---------+---------+-----------+
<b>输出</b>
+---------+
| user_id | 
+---------+
| 102     | 
+---------+
<b>解释</b>
- User_id 101 有三种贷款类型，其中之一是 Mortgage。但是，此用户没有任何类别为 Refinance 的贷款类型，因此用户 101 不会被考虑。
- User_id 102 拥有三种贷款类型：一种是 Mortgage，一种是 Refinance。因此，用户 102 将包括在结果中。
- User_id 103 有一种 Refinance 贷款类型，但没有 Mortgage 贷款类型，因此用户 103 不会被考虑。
- User_id 104 有一种 Mortgage 贷款类型，但没有 Refinance 贷款类型，因此用户 104 不会被考虑。
输出表以升序按 user_id 排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求和

我们可以对 `Loans` 表按照 `user_id` 进行分组，找出既包含 `Refinance` 又包含 `Mortgage` 的用户，然后按照 `user_id` 进行排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT user_id
FROM Loans
GROUP BY 1
HAVING SUM(loan_type = 'Refinance') > 0 AND SUM(loan_type = 'Mortgage') > 0
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2991. 最好的三家酒庄 🔒](https://leetcode.cn/problems/top-three-wineries){#2991}

{{< tabs "2991" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            country,
            CONCAT(winery, ' (', points, ')') AS winery,
            RANK() OVER (
                PARTITION BY country
                ORDER BY points DESC, winery
            ) AS rk
        FROM (SELECT country, SUM(points) AS points, winery FROM Wineries GROUP BY 1, 3) AS t
    )
SELECT
    t1.country,
    t1.winery AS top_winery,
    IFNULL(t2.winery, 'No second winery') AS second_winery,
    IFNULL(t3.winery, 'No third winery') AS third_winery
FROM
    T AS t1
    LEFT JOIN T AS t2 ON t1.country = t2.country AND t1.rk = t2.rk - 1
    LEFT JOIN T AS t3 ON t2.country = t3.country AND t2.rk = t3.rk - 1
WHERE t1.rk = 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Wineries</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| country     | varchar  |
| points      | int      |
| winery      | varchar  |
+-------------+----------+
id 是这张表具有唯一值的列。
这张表包含 id, country, points,和 winery。
</pre>

<p>编写一个解决方案，根据每家酒庄的 <strong>总分</strong> 找出 <strong>每个国家</strong> 的 <strong>前三名酒庄</strong>。如果有 <strong>多个酒庄</strong> 的总分 <strong>相同</strong>，则按 <code>winery</code> 名称升序排列。如果没有 <strong>分数排在第二的酒庄</strong>，则输出 'No Second Winery'，如果没有 <strong>分数排在第三的酒庄</strong>，则输出 'No Third Winery'。</p>

<p>返回结果表按<meta charset="UTF-8" /><em>&nbsp;</em><code>country</code><em>&nbsp;</em><strong>升序</strong> 排列。</p>

<p>结果表格格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Wineries table:
+-----+-----------+--------+-----------------+
| id  | country   | points | winery          | 
+-----+-----------+--------+-----------------+
| 103 | Australia | 84     | WhisperingPines | 
| 737 | Australia | 85     | GrapesGalore    |    
| 848 | Australia | 100    | HarmonyHill     | 
| 222 | Hungary   | 60     | MoonlitCellars  | 
| 116 | USA       | 47     | RoyalVines      | 
| 124 | USA       | 45     | Eagle'sNest     | 
| 648 | India     | 69     | SunsetVines     | 
| 894 | USA       | 39     | RoyalVines      |  
| 677 | USA       | 9      | PacificCrest    |  
+-----+-----------+--------+-----------------+
<b>输出：</b>
+-----------+---------------------+-------------------+----------------------+
| country   | top_winery          | second_winery     | third_winery         |
+-----------+---------------------+-------------------+----------------------+
| Australia | HarmonyHill (100)   | GrapesGalore (85) | WhisperingPines (84) |
| Hungary   | MoonlitCellars (60) | No second winery  | No third winery      | 
| India     | SunsetVines (69)    | No second winery  | No third winery      |  
| USA       | RoyalVines (86)     | Eagle'sNest (45)  | PacificCrest (9)     | 
+-----------+---------------------+-------------------+----------------------+
<b>解释：</b>
对于 Australia
&nbsp;- HarmonyHill 酒庄获得了 Australia 的最高分数，为 100 分。
&nbsp;- GrapesGalore 酒庄总共获得 85 分，位列 Australia 的第二位。
&nbsp;- WhisperingPines 酒庄总共获得 80 分，位列 Australia 的第三位。
对于 Hungary
&nbsp;- MoonlitCellars 是唯一的酒庄，获得 60 分，自动成为最高分数的酒庄。没有第二或第三家酒庄。
对于 India
&nbsp;- SunsetVines 是唯一的酒庄，获得 69 分，成为最高的酒庄。没有第二或第三家酒庄。
对于 USA
&nbsp;- RoyalVines Wines 累计了总分 47 + 39 = 86 分，占据了 USA 的最高位置。
&nbsp;- Eagle'sNest 总共获得 45 分，位列 USA 的第二高位置。
&nbsp;- PacificCrest 累计了 9 分，位列 USA 的第三高酒庄。
输出表按国家首字母升序排列。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 窗口函数 + 左连接

我们可以先对 `Wineries` 表按照 `country` 和 `winery` 进行分组，计算每个分组的总得分 `points`，然后再利用窗口函数 `RANK()` 将数据再按照 `country` 进行分组，按照 `points` 降序、`winery` 升序进行排序，并且用 `CONCAT()` 函数将 `winery` 和 `points` 进行拼接，得到如下形式的数据，记为 `T` 表：

| country   | winery               | rk  |
| --------- | -------------------- | --- |
| Australia | HarmonyHill (100)    | 1   |
| Australia | GrapesGalore (85)    | 2   |
| Australia | WhisperingPines (84) | 3   |
| Hungary   | MoonlitCellars (60)  | 1   |
| India     | SunsetVines (69)     | 1   |
| USA       | RoyalVines (86)      | 1   |
| USA       | Eagle'sNest (45)     | 2   |
| USA       | PacificCrest (9)     | 3   |

接下来，我们只需要筛选出 `rk = 1` 的数据，然后再将 `T` 表自连接两次，分别连接 `rk = 2` 和 `rk = 3` 的数据，即可得到最终结果。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            country,
            CONCAT(winery, ' (', points, ')') AS winery,
            RANK() OVER (
                PARTITION BY country
                ORDER BY points DESC, winery
            ) AS rk
        FROM (SELECT country, SUM(points) AS points, winery FROM Wineries GROUP BY 1, 3) AS t
    )
SELECT
    t1.country,
    t1.winery AS top_winery,
    IFNULL(t2.winery, 'No second winery') AS second_winery,
    IFNULL(t3.winery, 'No third winery') AS third_winery
FROM
    T AS t1
    LEFT JOIN T AS t2 ON t1.country = t2.country AND t1.rk = t2.rk - 1
    LEFT JOIN T AS t3 ON t2.country = t3.country AND t2.rk = t3.rk - 1
WHERE t1.rk = 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2992. 自整除排列的数量 🔒](https://leetcode.cn/problems/number-of-self-divisible-permutations){#2992}

{{< tabs "2992" >}}

{{% tab "python" %}}
```python
class Solution:
    def selfDivisiblePermutationCount(self, n: int) -> int:
        f = [0] * (1 << n)
        f[0] = 1
        for mask in range(1 << n):
            i = mask.bit_count()
            for j in range(1, n + 1):
                if (mask >> (j - 1) & 1) == 1 and gcd(i, j) == 1:
                    f[mask] += f[mask ^ (1 << (j - 1))]
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int selfDivisiblePermutationCount(int n) {
        int[] f = new int[1 << n];
        f[0] = 1;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int i = Integer.bitCount(mask);
            for (int j = 1; j <= n; ++j) {
                if (((mask >> (j - 1)) & 1) == 1 && (i % j == 0 || j % i == 0)) {
                    f[mask] += f[mask ^ (1 << (j - 1))];
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        int f[1 << n];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int i = __builtin_popcount(mask);
            for (int j = 1; j <= n; ++j) {
                if (((mask >> (j - 1)) & 1) == 1 && (i % j == 0 || j % i == 0)) {
                    f[mask] += f[mask ^ (1 << (j - 1))];
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func selfDivisiblePermutationCount(n int) int {
	f := make([]int, 1<<n)
	f[0] = 1
	for mask := 0; mask < 1<<n; mask++ {
		i := bits.OnesCount(uint(mask))
		for j := 1; j <= n; j++ {
			if mask>>(j-1)&1 == 1 && (i%j == 0 || j%i == 0) {
				f[mask] += f[mask^(1<<(j-1))]
			}
		}
	}
	return f[(1<<n)-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function selfDivisiblePermutationCount(n: number): number {
    const f: number[] = Array(1 << n).fill(0);
    f[0] = 1;
    for (let mask = 0; mask < 1 << n; ++mask) {
        const i = bitCount(mask);
        for (let j = 1; j <= n; ++j) {
            if ((mask >> (j - 1)) & 1 && (i % j === 0 || j % i === 0)) {
                f[mask] += f[mask ^ (1 << (j - 1))];
            }
        }
    }
    return f.at(-1)!;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数 <code>n</code>，返回 <strong>下标从 1 开始</strong> 的数组 <code>nums = [1, 2, ..., n]</code>的 <strong>可能的排列数量</strong>，使其满足 <strong>自整除</strong> 条件。</p>

<p>如果对于每个 <code>1 &lt;= i &lt;= n</code>，满足 <code><span data-keyword="gcd-function">gcd</span>(a[i], i) == 1</code>，数组 <code>nums</code> 就是 <strong>自整除</strong> 的。</p>

<p>数组的 <strong>排列</strong>&nbsp;是对数组元素的重新排序，例如，下面是数组 <code>[1, 2, 3]</code>&nbsp;的所有排列：</p>

<ul>
	<li><code>[1, 2, 3]</code></li>
	<li><code>[1, 3, 2]</code></li>
	<li><code>[2, 1, 3]</code></li>
	<li><code>[2, 3, 1]</code></li>
	<li><code>[3, 1, 2]</code></li>
	<li><code>[3, 2, 1]</code></li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>n = 1
<b>输出：</b>1
<b>解释：</b>数组 [1] 只有一个排列，它是自整除的。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>n = 2
<b>输出：1</b>
<b>解释：</b>数组 [1,2] 有 2 个排列，但只有其中一个是自整除的：
nums = [1,2]：这不是自整除的，因为 gcd(nums[2], 2) != 1。
nums = [2,1]：这是自整除的，因为 gcd(nums[1], 1) == 1 并且 gcd(nums[2], 2) == 1。
</pre>

<p><b>示例 3：</b></p>

<pre>
<b>输入：</b>n = 3
<b>输出：</b>3
<b>解释：</b>数组 [1,2,3] 有 3 个自整除的排列：[1,2,3]、[2,1,3]、[3,2,1]。
其他 3 个排列不能满足自整除条件。因此答案是 3。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= n &lt;= 12</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

我们可以用一个二进制数 $mask$ 来表示当前排列的状态，其中第 $i$ 位为 $1$ 表示数字 $i$ 已经被使用，为 $0$ 表示数字 $i$ 还未被使用。

那么，我们设计一个函数 $dfs(mask)$，表示从当前排列的状态 $mask$ 开始，能够构造出的满足题目要求的排列的数量。答案即为 $dfs(0)$。

我们可以用记忆化搜索的方法来计算 $dfs(mask)$ 的值。

在计算 $dfs(mask)$ 的过程中，我们用 $i$ 表示当前要加入排列的是第几个数字，如果 $i \gt n$，说明排列已经构造完毕，我们可以返回 $1$。

否则，我们枚举当前排列中还未被使用的数字 $j$，如果 $i$ 和 $j$ 满足题目要求，那么我们就可以将 $j$ 加入排列中，此时状态变为 $mask \mid 2^j$，其中 $|$ 表示按位或运算。由于 $j$ 已经被使用，因此我们需要递归计算 $dfs(mask \mid 2^j)$ 的值，并将其累加到 $dfs(mask)$ 上。

最终，我们可以得到 $dfs(0)$ 的值，即为答案。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 为排列的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def selfDivisiblePermutationCount(self, n: int) -> int:
        @cache
        def dfs(mask: int) -> int:
            i = mask.bit_count() + 1
            if i > n:
                return 1
            ans = 0
            for j in range(1, n + 1):
                if (mask >> j & 1) == 0 and gcd(i, j) == 1:
                    ans += dfs(mask | 1 << j)
            return ans

        return dfs(0)
```

#### Java

```java
class Solution {
    private int n;
    private Integer[] f;

    public int selfDivisiblePermutationCount(int n) {
        this.n = n;
        f = new Integer[1 << (n + 1)];
        return dfs(0);
    }

    private int dfs(int mask) {
        if (f[mask] != null) {
            return f[mask];
        }
        int i = Integer.bitCount(mask) + 1;
        if (i > n) {
            return 1;
        }
        f[mask] = 0;
        for (int j = 1; j <= n; ++j) {
            if ((mask >> j & 1) == 0 && (i % j == 0 || j % i == 0)) {
                f[mask] += dfs(mask | 1 << j);
            }
        }
        return f[mask];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        int f[1 << (n + 1)];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int mask) {
            if (f[mask] != -1) {
                return f[mask];
            }
            int i = __builtin_popcount(mask) + 1;
            if (i > n) {
                return 1;
            }
            f[mask] = 0;
            for (int j = 1; j <= n; ++j) {
                if ((mask >> j & 1) == 0 && (i % j == 0 || j % i == 0)) {
                    f[mask] += dfs(mask | 1 << j);
                }
            }
            return f[mask];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func selfDivisiblePermutationCount(n int) int {
	f := make([]int, 1<<(n+1))
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(mask int) int {
		if f[mask] != -1 {
			return f[mask]
		}
		i := bits.OnesCount(uint(mask)) + 1
		if i > n {
			return 1
		}
		f[mask] = 0
		for j := 1; j <= n; j++ {
			if mask>>j&1 == 0 && (i%j == 0 || j%i == 0) {
				f[mask] += dfs(mask | 1<<j)
			}
		}
		return f[mask]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function selfDivisiblePermutationCount(n: number): number {
    const f: number[] = Array(1 << (n + 1)).fill(-1);
    const dfs = (mask: number): number => {
        if (f[mask] !== -1) {
            return f[mask];
        }
        const i = bitCount(mask) + 1;
        if (i > n) {
            return 1;
        }
        f[mask] = 0;
        for (let j = 1; j <= n; ++j) {
            if (((mask >> j) & 1) === 0 && (i % j === 0 || j % i === 0)) {
                f[mask] += dfs(mask | (1 << j));
            }
        }
        return f[mask];
    };
    return dfs(0);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩 + 动态规划

我们可以将方法一中的记忆化搜索改写为动态规划的形式，定义 $f[mask]$ 表示当前排列的状态为 $mask$，且满足题目要求的排列的数量。初始时 $f[0]=1$，其余值均为 $0$。

我们在 $[0, 2^n)$ 的范围内枚举 $mask$，对于每个 $mask$，我们用 $i$ 表示当前最后一个加入排列的是第几个数字，然后我们枚举当前排列中最后一个加入的数字 $j$，如果 $i$ 和 $j$ 满足题目要求，那么状态 $f[mask]$ 就可以从状态 $f[mask \oplus 2^(j-1)]$ 转移而来，其中 $\oplus$ 表示按位异或运算。我们将所有转移得到的状态 $f[mask \oplus 2^(j-1)]$ 的值累加到 $f[mask]$ 上，即为 $f[mask]$ 的值。

最终，我们可以得到 $f[2^n - 1]$ 的值，即为答案。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 为排列的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def selfDivisiblePermutationCount(self, n: int) -> int:
        f = [0] * (1 << n)
        f[0] = 1
        for mask in range(1 << n):
            i = mask.bit_count()
            for j in range(1, n + 1):
                if (mask >> (j - 1) & 1) == 1 and gcd(i, j) == 1:
                    f[mask] += f[mask ^ (1 << (j - 1))]
        return f[-1]
```

#### Java

```java
class Solution {
    public int selfDivisiblePermutationCount(int n) {
        int[] f = new int[1 << n];
        f[0] = 1;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int i = Integer.bitCount(mask);
            for (int j = 1; j <= n; ++j) {
                if (((mask >> (j - 1)) & 1) == 1 && (i % j == 0 || j % i == 0)) {
                    f[mask] += f[mask ^ (1 << (j - 1))];
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        int f[1 << n];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int i = __builtin_popcount(mask);
            for (int j = 1; j <= n; ++j) {
                if (((mask >> (j - 1)) & 1) == 1 && (i % j == 0 || j % i == 0)) {
                    f[mask] += f[mask ^ (1 << (j - 1))];
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func selfDivisiblePermutationCount(n int) int {
	f := make([]int, 1<<n)
	f[0] = 1
	for mask := 0; mask < 1<<n; mask++ {
		i := bits.OnesCount(uint(mask))
		for j := 1; j <= n; j++ {
			if mask>>(j-1)&1 == 1 && (i%j == 0 || j%i == 0) {
				f[mask] += f[mask^(1<<(j-1))]
			}
		}
	}
	return f[(1<<n)-1]
}
```

#### TypeScript

```ts
function selfDivisiblePermutationCount(n: number): number {
    const f: number[] = Array(1 << n).fill(0);
    f[0] = 1;
    for (let mask = 0; mask < 1 << n; ++mask) {
        const i = bitCount(mask);
        for (let j = 1; j <= n; ++j) {
            if ((mask >> (j - 1)) & 1 && (i % j === 0 || j % i === 0)) {
                f[mask] += f[mask ^ (1 << (j - 1))];
            }
        }
    }
    return f.at(-1)!;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2993. 发生在周五的交易 I 🔒](https://leetcode.cn/problems/friday-purchases-i){#2993}

{{< tabs "2993" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    CEIL(DAYOFMONTH(purchase_date) / 7) AS week_of_month,
    purchase_date,
    SUM(amount_spend) AS total_amount
FROM Purchases
WHERE DATE_FORMAT(purchase_date, '%Y%m') = '202311' AND DAYOFWEEK(purchase_date) = 6
GROUP BY 2
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Purchases</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| user_id       | int  |
| purchase_date | date |
| amount_spend  | int  |
+---------------+------+
(user_id, purchase_date, amount_spend) 是该表的主键(具有唯一值的列)。
purchase_date 的范围从 2023 年 11 月 1 日到 2023 年 11 月 30 日，并包括这两个日期。
每一行包含 user id, purchase date，和 amount spend。
</pre>

<p>编写一个解决方案，计算用户在 <strong>2023 年 11 月&nbsp;</strong>的 <strong>每个星期五</strong> 的 <strong>总花费</strong>。输出所有在&nbsp;<strong>周五&nbsp;</strong>有购买记录的周。</p>

<p>按照每月的周次序 <strong>升序</strong> 排列结果表。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
Purchases table:
+---------+---------------+--------------+
| user_id | purchase_date | amount_spend |
+---------+---------------+--------------+
| 11      | 2023-11-07    | 1126         |
| 15      | 2023-11-30    | 7473         |
| 17      | 2023-11-14    | 2414         |
| 12      | 2023-11-24    | 9692         |
| 8       | 2023-11-03    | 5117         |
| 1       | 2023-11-16    | 5241         |
| 10      | 2023-11-12    | 8266         |
| 13      | 2023-11-24    | 12000        |
+---------+---------------+--------------+
<b>输出：</b>
+---------------+---------------+--------------+
| week_of_month | purchase_date | total_amount |
+---------------+---------------+--------------+
| 1             | 2023-11-03    | 5117         |
| 4             | 2023-11-24    | 21692        |
+---------------+---------------+--------------+ 
<b>解释：</b>
- 在 2023 年 11 月的第一周，于 2023-11-03 星期五发生了总额为 $5,117 的交易。
- 对于 2023 年 11 月的第二周，于 2023-11-10 星期五没有交易。
- 同样，在 2023 年 11 月的第三周，于 2023-11-17 星期五没有交易。
- 在 2023 年 11 月的第四周，于 2023-11-24 星期五发生了两笔交易，分别为 $12,000 和 $9,692，总计为 $21,692。
输出表按照 week_of_month 升序排列。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：日期函数

我们用到的日期函数有：

-   `DATE_FORMAT(date, format)`：将日期格式化为字符串
-   `DAYOFWEEK(date)`：返回日期对应的星期几，1 代表星期日，2 代表星期一，以此类推
-   `DAYOFMONTH(date)`：返回日期对应的月份中的第几天

我们先用 `DATE_FORMAT` 函数将日期格式化为 `YYYYMM` 的形式，然后筛选出 2023 年 11 月且是星期五的记录，然后将记录按照 `purchase_date` 分组，计算出每个星期五的总消费金额。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    CEIL(DAYOFMONTH(purchase_date) / 7) AS week_of_month,
    purchase_date,
    SUM(amount_spend) AS total_amount
FROM Purchases
WHERE DATE_FORMAT(purchase_date, '%Y%m') = '202311' AND DAYOFWEEK(purchase_date) = 6
GROUP BY 2
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2994. 发生在周五的交易 II 🔒](https://leetcode.cn/problems/friday-purchases-ii){#2994}

{{< tabs "2994" >}}

{{% tab "sql" %}}
```sql
WITH RECURSIVE
    T AS (
        SELECT '2023-11-01' AS purchase_date
        UNION
        SELECT purchase_date + INTERVAL 1 DAY
        FROM T
        WHERE purchase_date < '2023-11-30'
    )
SELECT
    CEIL(DAYOFMONTH(purchase_date) / 7) AS week_of_month,
    purchase_date,
    IFNULL(SUM(amount_spend), 0) AS total_amount
FROM
    T
    LEFT JOIN Purchases USING (purchase_date)
WHERE DAYOFWEEK(purchase_date) = 6
GROUP BY 2
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Purchases</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| user_id       | int  |
| purchase_date | date |
| amount_spend  | int  |
+---------------+------+
<meta charset="UTF-8" />(user_id, purchase_date, amount_spend) 是该表的主键(具有唯一值的列)。
purchase_date 的范围从 2023 年 11 月 1 日到 2023 年 11 月 30 日，并包括这两个日期。
每一行包含 user id, purchase date，和 amount spend。</pre>

<p>编写一个解决方案，计算用户在 <strong>2023 年 11</strong> 月的 <strong>每个星期五</strong> 的 <strong>总花费</strong>。如果在&nbsp;<strong>某个星期的星期五</strong> <strong>没有</strong> 购买记录，则将其视为花费金额为 <code>0</code>。</p>

<p><meta charset="UTF-8" /></p>

<p>按照每月的周次序&nbsp;<strong>升序</strong>&nbsp;排列结果表。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
Purchases table:
+---------+---------------+--------------+
| user_id | purchase_date | amount_spend |
+---------+---------------+--------------+
| 11      | 2023-11-07    | 1126         |
| 15      | 2023-11-30    | 7473         |
| 17      | 2023-11-14    | 2414         |
| 12      | 2023-11-24    | 9692         |
| 8       | 2023-11-03    | 5117         |
| 1       | 2023-11-16    | 5241         |
| 10      | 2023-11-12    | 8266         |
| 13      | 2023-11-24    | 12000        |
+---------+---------------+--------------+
<b>输出：</b> 
+---------------+---------------+--------------+
| week_of_month | purchase_date | total_amount |
+---------------+---------------+--------------+
| 1             | 2023-11-03    | 5117         |
| 2             | 2023-11-10    | 0            |
| 3             | 2023-11-17    | 0            |
| 4             | 2023-11-24    | 21692        |
+---------------+---------------+--------------+ 
<b>解释：</b>
- 在 2023 年 11 月的第一周的周五（即 2023-11-03），共发生了总计 $5,117 的交易。
- 在 2023 年 11 月的第二周的周五（即 2023-11-10），当天没有交易，因此在输出表中该天的值为 0。
- 类似地，在 2023 年 11 月的第三周的周五（即 2023-11-17），当天没有交易，因此在输出表中该天的值为 0。
- 在 2023 年 11 月的第四周的周五（即 2023-11-24），当天发生了两笔交易，分别为 $12,000 和 $9,692，总计 $21,692。
输出表按照 week_of_month 按升序排序。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 + 左连接 + 日期函数

我们可以使用递归生成一个包含 2023 年 11 月所有日期的表 `T`，然后使用左连接将 `T` 与 `Purchases` 表按照日期进行连接，最后按照题目要求进行分组求和即可。

<!-- tabs:start -->

#### MySQL

```sql
WITH RECURSIVE
    T AS (
        SELECT '2023-11-01' AS purchase_date
        UNION
        SELECT purchase_date + INTERVAL 1 DAY
        FROM T
        WHERE purchase_date < '2023-11-30'
    )
SELECT
    CEIL(DAYOFMONTH(purchase_date) / 7) AS week_of_month,
    purchase_date,
    IFNULL(SUM(amount_spend), 0) AS total_amount
FROM
    T
    LEFT JOIN Purchases USING (purchase_date)
WHERE DAYOFWEEK(purchase_date) = 6
GROUP BY 2
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2995. 观众变主播 🔒](https://leetcode.cn/problems/viewers-turned-streamers){#2995}

{{< tabs "2995" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            session_type,
            RANK() OVER (
                PARTITION BY user_id
                ORDER BY session_start
            ) AS rk
        FROM Sessions
    )
SELECT user_id, COUNT(1) AS sessions_count
FROM
    T AS t
    JOIN Sessions AS s USING (user_id)
WHERE rk = 1 AND t.session_type = 'Viewer' AND s.session_type = 'Streamer'
GROUP BY 1
ORDER BY 2 DESC, 1 DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Sessions</code></p>

<pre>
+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| user_id       | int      |
| session_start | datetime |
| session_end   | datetime |
| session_id    | int      |
| session_type  | enum     |
+---------------+----------+
session_id 是这张表具有唯一值的列。
session_type 是一个 ENUM (枚举) 类型，包含(Viewer, Streamer)两个类别。
这张表包含 user id, session start, session end, session id 和 session type。
</pre>

<p>编写一个解决方案，找到 <strong>首次会话</strong> 为 <strong>观众身份</strong> 的用户，其 <strong>主播会话</strong> 数量。</p>

<p>按照会话数量和 <code>user_id</code> <strong>降序</strong> 排序返回结果表。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
Sessions table:
+---------+---------------------+---------------------+------------+--------------+
| user_id | session_start       | session_end         | session_id | session_type | 
+---------+---------------------+---------------------+------------+--------------+
| 101     | 2023-11-06 13:53:42 | 2023-11-06 14:05:42 | 375        | Viewer       |  
| 101     | 2023-11-22 16:45:21 | 2023-11-22 20:39:21 | 594        | Streamer     |   
| 102     | 2023-11-16 13:23:09 | 2023-11-16 16:10:09 | 777        | Streamer     | 
| 102     | 2023-11-17 13:23:09 | 2023-11-17 16:10:09 | 778        | Streamer     | 
| 101     | 2023-11-20 07:16:06 | 2023-11-20 08:33:06 | 315        | Streamer     | 
| 104     | 2023-11-27 03:10:49 | 2023-11-27 03:30:49 | 797        | Viewer       | 
| 103     | 2023-11-27 03:10:49 | 2023-11-27 03:30:49 | 798        | Streamer     |  
+---------+---------------------+---------------------+------------+--------------+
<b>输出：</b>
+---------+----------------+
| user_id | sessions_count | 
+---------+----------------+
| 101     | 2              | 
+---------+----------------+
<b>解释</b>
- user_id 101，在 2023-11-06 13:53:42 以观众身份开始了他们的初始会话，随后进行了两次主播会话，所以计数为 2。
- user_id 102，尽管有两个会话，但初始会话是作为主播，因此将排除此用户。
- user_id 103 只参与了一次会话，即作为主播，因此不会考虑在内。
- User_id 104 以观众身份开始了他们的第一次会话，但没有后续会话，因此不会包括在最终计数中。
输出表按照会话数量和 user_id 降序排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + 等值连接

我们可以用窗口函数 `RANK()` 按照 `user_id` 维度，对每个会话进行排名，记录在表 `T` 中，然后再将 `T` 与 `Sessions` 表按照 `user_id` 进行等值连接，并且筛选出 `T` 中排名为 1 的记录，并且 `session_type` 为 `Viewer`，`Sessions` 表中 `session_type` 为 `Streamer` 的记录，最后按照 `user_id` 进行分组求和即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            session_type,
            RANK() OVER (
                PARTITION BY user_id
                ORDER BY session_start
            ) AS rk
        FROM Sessions
    )
SELECT user_id, COUNT(1) AS sessions_count
FROM
    T AS t
    JOIN Sessions AS s USING (user_id)
WHERE rk = 1 AND t.session_type = 'Viewer' AND s.session_type = 'Streamer'
GROUP BY 1
ORDER BY 2 DESC, 1 DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2996. 大于等于顺序前缀和的最小缺失整数](https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum){#2996}

{{< tabs "2996" >}}

{{% tab "python" %}}
```python
class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        s, j = nums[0], 1
        while j < len(nums) and nums[j] == nums[j - 1] + 1:
            s += nums[j]
            j += 1
        vis = set(nums)
        for x in count(s):
            if x not in vis:
                return x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int missingInteger(int[] nums) {
        int s = nums[0];
        for (int j = 1; j < nums.length && nums[j] == nums[j - 1] + 1; ++j) {
            s += nums[j];
        }
        boolean[] vis = new boolean[51];
        for (int x : nums) {
            vis[x] = true;
        }
        for (int x = s;; ++x) {
            if (x >= vis.length || !vis[x]) {
                return x;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        for (int j = 1; j < nums.size() && nums[j] == nums[j - 1] + 1; ++j) {
            s += nums[j];
        }
        bitset<51> vis;
        for (int x : nums) {
            vis[x] = 1;
        }
        for (int x = s;; ++x) {
            if (x >= 51 || !vis[x]) {
                return x;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func missingInteger(nums []int) int {
	s := nums[0]
	for j := 1; j < len(nums) && nums[j] == nums[j-1]+1; j++ {
		s += nums[j]
	}
	vis := [51]bool{}
	for _, x := range nums {
		vis[x] = true
	}
	for x := s; ; x++ {
		if x >= len(vis) || !vis[x] {
			return x
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function missingInteger(nums: number[]): number {
    let s = nums[0];
    for (let j = 1; j < nums.length && nums[j] === nums[j - 1] + 1; ++j) {
        s += nums[j];
    }
    const vis: Set<number> = new Set(nums);
    for (let x = s; ; ++x) {
        if (!vis.has(x)) {
            return x;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果一个前缀&nbsp;<code>nums[0..i]</code>&nbsp;满足对于&nbsp;<code>1 &lt;= j &lt;= i</code>&nbsp;的所有元素都有&nbsp;<code>nums[j] = nums[j - 1] + 1</code>&nbsp;，那么我们称这个前缀是一个 <strong>顺序前缀</strong> 。特殊情况是，只包含&nbsp;<code>nums[0]</code>&nbsp;的前缀也是一个 <strong>顺序前缀</strong> 。</p>

<p>请你返回 <code>nums</code>&nbsp;中没有出现过的 <strong>最小</strong>&nbsp;整数&nbsp;<code>x</code>&nbsp;，满足&nbsp;<code>x</code>&nbsp;大于等于&nbsp;<strong>最长</strong> 顺序前缀的和。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,2,5]
<b>输出：</b>6
<b>解释：</b>nums 的最长顺序前缀是 [1,2,3] ，和为 6 ，6 不在数组中，所以 6 是大于等于最长顺序前缀和的最小整数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,5,1,12,14,13]
<b>输出：</b>15
<b>解释：</b>nums 的最长顺序前缀是 [3,4,5] ，和为 12 ，12、13 和 14 都在数组中，但 15 不在，所以 15 是大于等于最长顺序前缀和的最小整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟 + 哈希表

我们先求出数组 $nums$ 的最长顺序前缀和 $s$，然后从 $s$ 开始枚举整数 $x$，如果 $x$ 不在数组 $nums$ 中，那么 $x$ 就是答案。这里我们可以用哈希表来快速判断一个整数是否在数组 $nums$ 中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        s, j = nums[0], 1
        while j < len(nums) and nums[j] == nums[j - 1] + 1:
            s += nums[j]
            j += 1
        vis = set(nums)
        for x in count(s):
            if x not in vis:
                return x
```

#### Java

```java
class Solution {
    public int missingInteger(int[] nums) {
        int s = nums[0];
        for (int j = 1; j < nums.length && nums[j] == nums[j - 1] + 1; ++j) {
            s += nums[j];
        }
        boolean[] vis = new boolean[51];
        for (int x : nums) {
            vis[x] = true;
        }
        for (int x = s;; ++x) {
            if (x >= vis.length || !vis[x]) {
                return x;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        for (int j = 1; j < nums.size() && nums[j] == nums[j - 1] + 1; ++j) {
            s += nums[j];
        }
        bitset<51> vis;
        for (int x : nums) {
            vis[x] = 1;
        }
        for (int x = s;; ++x) {
            if (x >= 51 || !vis[x]) {
                return x;
            }
        }
    }
};
```

#### Go

```go
func missingInteger(nums []int) int {
	s := nums[0]
	for j := 1; j < len(nums) && nums[j] == nums[j-1]+1; j++ {
		s += nums[j]
	}
	vis := [51]bool{}
	for _, x := range nums {
		vis[x] = true
	}
	for x := s; ; x++ {
		if x >= len(vis) || !vis[x] {
			return x
		}
	}
}
```

#### TypeScript

```ts
function missingInteger(nums: number[]): number {
    let s = nums[0];
    for (let j = 1; j < nums.length && nums[j] === nums[j - 1] + 1; ++j) {
        s += nums[j];
    }
    const vis: Set<number> = new Set(nums);
    for (let x = s; ; ++x) {
        if (!vis.has(x)) {
            return x;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2997. 使数组异或和等于 K 的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k){#2997}

{{< tabs "2997" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return reduce(xor, nums, k).bit_count()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums, int k) {
        for (int x : nums) {
            k ^= x;
        }
        return Integer.bitCount(k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int x : nums) {
            k ^= x;
        }
        return __builtin_popcount(k);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, k int) (ans int) {
	for _, x := range nums {
		k ^= x
	}
	return bits.OnesCount(uint(k))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], k: number): number {
    for (const x of nums) {
        k ^= x;
    }
    return bitCount(k);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以对数组执行以下操作 <strong>任意次</strong>&nbsp;：</p>

<ul>
	<li>选择数组里的 <strong>任意</strong>&nbsp;一个元素，并将它的&nbsp;<strong>二进制</strong>&nbsp;表示&nbsp;<strong>翻转</strong>&nbsp;一个数位，翻转数位表示将&nbsp;<code>0</code> 变成&nbsp;<code>1</code>&nbsp;或者将 <code>1</code>&nbsp;变成 <code>0</code>&nbsp;。</li>
</ul>

<p>你的目标是让数组里 <strong>所有</strong>&nbsp;元素的按位异或和得到 <code>k</code>&nbsp;，请你返回达成这一目标的 <strong>最少&nbsp;</strong>操作次数。</p>

<p><strong>注意</strong>，你也可以将一个数的前导 0 翻转。比方说，数字&nbsp;<code>(101)<sub>2</sub></code>&nbsp;翻转第四个数位，得到&nbsp;<code>(1101)<sub>2</sub></code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,3,4], k = 1
<b>输出：</b>2
<b>解释：</b>我们可以执行以下操作：
- 选择下标为 2 的元素，也就是 3 == (011)<sub>2</sub>&nbsp;，我们翻转第一个数位得到 (010)<sub>2</sub> == 2 。数组变为 [2,1,2,4] 。
- 选择下标为 0 的元素，也就是 2 == (010)<sub>2</sub> ，我们翻转第三个数位得到 (110)<sub>2</sub> == 6 。数组变为 [6,1,2,4] 。
最终数组的所有元素异或和为 (6 XOR 1 XOR 2 XOR 4) == 1 == k 。
无法用少于 2 次操作得到异或和等于 k 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,0,2,0], k = 0
<b>输出：</b>0
<strong>解释：</strong>数组所有元素的异或和为 (2 XOR 0 XOR 2 XOR 0) == 0 == k 。所以不需要进行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以将数组 $nums$ 中的所有元素进行异或运算，判断得到的结果与 $k$ 的二进制表示中有多少位不同，这个数就是最少操作次数。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return reduce(xor, nums, k).bit_count()
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int k) {
        for (int x : nums) {
            k ^= x;
        }
        return Integer.bitCount(k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int x : nums) {
            k ^= x;
        }
        return __builtin_popcount(k);
    }
};
```

#### Go

```go
func minOperations(nums []int, k int) (ans int) {
	for _, x := range nums {
		k ^= x
	}
	return bits.OnesCount(uint(k))
}
```

#### TypeScript

```ts
function minOperations(nums: number[], k: number): number {
    for (const x of nums) {
        k ^= x;
    }
    return bitCount(k);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2998. 使 X 和 Y 相等的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-x-and-y-equal){#2998}

{{< tabs "2998" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperationsToMakeEqual(self, x: int, y: int) -> int:
        @cache
        def dfs(x: int) -> int:
            if y >= x:
                return y - x
            ans = x - y
            ans = min(ans, x % 5 + 1 + dfs(x // 5))
            ans = min(ans, 5 - x % 5 + 1 + dfs(x // 5 + 1))
            ans = min(ans, x % 11 + 1 + dfs(x // 11))
            ans = min(ans, 11 - x % 11 + 1 + dfs(x // 11 + 1))
            return ans

        return dfs(x)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, Integer> f = new HashMap<>();
    private int y;

    public int minimumOperationsToMakeEqual(int x, int y) {
        this.y = y;
        return dfs(x);
    }

    private int dfs(int x) {
        if (y >= x) {
            return y - x;
        }
        if (f.containsKey(x)) {
            return f.get(x);
        }
        int ans = x - y;
        int a = x % 5 + 1 + dfs(x / 5);
        int b = 5 - x % 5 + 1 + dfs(x / 5 + 1);
        int c = x % 11 + 1 + dfs(x / 11);
        int d = 11 - x % 11 + 1 + dfs(x / 11 + 1);
        ans = Math.min(ans, Math.min(a, Math.min(b, Math.min(c, d))));
        f.put(x, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_map<int, int> f;
        function<int(int)> dfs = [&](int x) {
            if (y >= x) {
                return y - x;
            }
            if (f.count(x)) {
                return f[x];
            }
            int a = x % 5 + 1 + dfs(x / 5);
            int b = 5 - x % 5 + 1 + dfs(x / 5 + 1);
            int c = x % 11 + 1 + dfs(x / 11);
            int d = 11 - x % 11 + 1 + dfs(x / 11 + 1);
            return f[x] = min({x - y, a, b, c, d});
        };
        return dfs(x);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperationsToMakeEqual(x int, y int) int {
	f := map[int]int{}
	var dfs func(int) int
	dfs = func(x int) int {
		if y >= x {
			return y - x
		}
		if v, ok := f[x]; ok {
			return v
		}
		a := x%5 + 1 + dfs(x/5)
		b := 5 - x%5 + 1 + dfs(x/5+1)
		c := x%11 + 1 + dfs(x/11)
		d := 11 - x%11 + 1 + dfs(x/11+1)
		f[x] = min(x-y, a, b, c, d)
		return f[x]
	}
	return dfs(x)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperationsToMakeEqual(x: number, y: number): number {
    const f: Map<number, number> = new Map();
    const dfs = (x: number): number => {
        if (y >= x) {
            return y - x;
        }
        if (f.has(x)) {
            return f.get(x)!;
        }
        const a = (x % 5) + 1 + dfs((x / 5) | 0);
        const b = 5 - (x % 5) + 1 + dfs(((x / 5) | 0) + 1);
        const c = (x % 11) + 1 + dfs((x / 11) | 0);
        const d = 11 - (x % 11) + 1 + dfs(((x / 11) | 0) + 1);
        const ans = Math.min(x - y, a, b, c, d);
        f.set(x, ans);
        return ans;
    };
    return dfs(x);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;。</p>

<p>一次操作中，你可以执行以下四种操作之一：</p>

<ol>
	<li>如果 <code>x</code>&nbsp;是 <code>11</code>&nbsp;的倍数，将&nbsp;<code>x</code>&nbsp;除以&nbsp;<code>11</code>&nbsp;。</li>
	<li>如果 <code>x</code>&nbsp;是 <code>5</code>&nbsp;的倍数，将 <code>x</code>&nbsp;除以 <code>5</code>&nbsp;。</li>
	<li>将&nbsp;<code>x</code> 减&nbsp;<code>1</code>&nbsp;。</li>
	<li>将&nbsp;<code>x</code>&nbsp;加&nbsp;<code>1</code>&nbsp;。</li>
</ol>

<p>请你返回让 <code>x</code>&nbsp;和 <code>y</code>&nbsp;相等的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>x = 26, y = 1
<b>输出：</b>3
<b>解释</b><strong>：</strong>我们可以通过以下操作将 26 变为 1 ：
1. 将 x 减 1
2. 将 x 除以 5
3. 将 x 除以 5
将 26 变为 1 最少需要 3 次操作。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>x = 54, y = 2
<b>输出：</b>4
<b>解释：</b>我们可以通过以下操作将 54 变为 2 ：
1. 将 x 加 1
2. 将 x 除以 11
3. 将 x 除以 5
4. 将 x 加 1
将 54 变为 2 最少需要 4 次操作。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>x = 25, y = 30
<b>输出：</b>5
<b>解释：</b>我们可以通过以下操作将 25 变为 30 ：
1. 将 x 加 1
2. 将 x 加 1
3. 将 x 加 1
4. 将 x 加 1
5. 将 x 加 1
将 25 变为 30 最少需要 5 次操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 10<sup>4</sup></code></li>
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
class Solution:
    def minimumOperationsToMakeEqual(self, x: int, y: int) -> int:
        @cache
        def dfs(x: int) -> int:
            if y >= x:
                return y - x
            ans = x - y
            ans = min(ans, x % 5 + 1 + dfs(x // 5))
            ans = min(ans, 5 - x % 5 + 1 + dfs(x // 5 + 1))
            ans = min(ans, x % 11 + 1 + dfs(x // 11))
            ans = min(ans, 11 - x % 11 + 1 + dfs(x // 11 + 1))
            return ans

        return dfs(x)
```

#### Java

```java
class Solution {
    private Map<Integer, Integer> f = new HashMap<>();
    private int y;

    public int minimumOperationsToMakeEqual(int x, int y) {
        this.y = y;
        return dfs(x);
    }

    private int dfs(int x) {
        if (y >= x) {
            return y - x;
        }
        if (f.containsKey(x)) {
            return f.get(x);
        }
        int ans = x - y;
        int a = x % 5 + 1 + dfs(x / 5);
        int b = 5 - x % 5 + 1 + dfs(x / 5 + 1);
        int c = x % 11 + 1 + dfs(x / 11);
        int d = 11 - x % 11 + 1 + dfs(x / 11 + 1);
        ans = Math.min(ans, Math.min(a, Math.min(b, Math.min(c, d))));
        f.put(x, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_map<int, int> f;
        function<int(int)> dfs = [&](int x) {
            if (y >= x) {
                return y - x;
            }
            if (f.count(x)) {
                return f[x];
            }
            int a = x % 5 + 1 + dfs(x / 5);
            int b = 5 - x % 5 + 1 + dfs(x / 5 + 1);
            int c = x % 11 + 1 + dfs(x / 11);
            int d = 11 - x % 11 + 1 + dfs(x / 11 + 1);
            return f[x] = min({x - y, a, b, c, d});
        };
        return dfs(x);
    }
};
```

#### Go

```go
func minimumOperationsToMakeEqual(x int, y int) int {
	f := map[int]int{}
	var dfs func(int) int
	dfs = func(x int) int {
		if y >= x {
			return y - x
		}
		if v, ok := f[x]; ok {
			return v
		}
		a := x%5 + 1 + dfs(x/5)
		b := 5 - x%5 + 1 + dfs(x/5+1)
		c := x%11 + 1 + dfs(x/11)
		d := 11 - x%11 + 1 + dfs(x/11+1)
		f[x] = min(x-y, a, b, c, d)
		return f[x]
	}
	return dfs(x)
}
```

#### TypeScript

```ts
function minimumOperationsToMakeEqual(x: number, y: number): number {
    const f: Map<number, number> = new Map();
    const dfs = (x: number): number => {
        if (y >= x) {
            return y - x;
        }
        if (f.has(x)) {
            return f.get(x)!;
        }
        const a = (x % 5) + 1 + dfs((x / 5) | 0);
        const b = 5 - (x % 5) + 1 + dfs(((x / 5) | 0) + 1);
        const c = (x % 11) + 1 + dfs((x / 11) | 0);
        const d = 11 - (x % 11) + 1 + dfs(((x / 11) | 0) + 1);
        const ans = Math.min(x - y, a, b, c, d);
        f.set(x, ans);
        return ans;
    };
    return dfs(x);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2999. 统计强大整数的数目](https://leetcode.cn/problems/count-the-number-of-powerful-integers){#2999}

{{< tabs "2999" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        @cache
        def dfs(pos: int, lim: int) -> int:
            if len(t) < n:
                return 0
            if len(t) - pos == n:
                return int(s <= t[pos:]) if lim else 1
            up = min(int(t[pos]) if lim else 9, limit)
            ans = 0
            for i in range(up + 1):
                ans += dfs(pos + 1, lim and i == int(t[pos]))
            return ans

        n = len(s)
        t = str(start - 1)
        a = dfs(0, True)
        dfs.cache_clear()
        t = str(finish)
        b = dfs(0, True)
        return b - a
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private String t;
    private Long[] f;
    private int limit;

    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        this.s = s;
        this.limit = limit;
        t = String.valueOf(start - 1);
        f = new Long[20];
        long a = dfs(0, true);
        t = String.valueOf(finish);
        f = new Long[20];
        long b = dfs(0, true);
        return b - a;
    }

    private long dfs(int pos, boolean lim) {
        if (t.length() < s.length()) {
            return 0;
        }
        if (!lim && f[pos] != null) {
            return f[pos];
        }
        if (t.length() - pos == s.length()) {
            return lim ? (s.compareTo(t.substring(pos)) <= 0 ? 1 : 0) : 1;
        }
        int up = lim ? t.charAt(pos) - '0' : 9;
        up = Math.min(up, limit);
        long ans = 0;
        for (int i = 0; i <= up; ++i) {
            ans += dfs(pos + 1, lim && i == (t.charAt(pos) - '0'));
        }
        if (!lim) {
            f[pos] = ans;
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
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string t = to_string(start - 1);
        long long f[20];
        memset(f, -1, sizeof(f));

        auto dfs = [&](this auto&& dfs, int pos, int lim) -> long long {
            if (t.size() < s.size()) {
                return 0;
            }
            if (!lim && f[pos] != -1) {
                return f[pos];
            }
            if (t.size() - pos == s.size()) {
                return lim ? s <= t.substr(pos) : 1;
            }
            long long ans = 0;
            int up = min(lim ? t[pos] - '0' : 9, limit);
            for (int i = 0; i <= up; ++i) {
                ans += dfs(pos + 1, lim && i == (t[pos] - '0'));
            }
            if (!lim) {
                f[pos] = ans;
            }
            return ans;
        };

        long long a = dfs(0, true);
        t = to_string(finish);
        memset(f, -1, sizeof(f));
        long long b = dfs(0, true);
        return b - a;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPowerfulInt(start, finish int64, limit int, s string) int64 {
	t := strconv.FormatInt(start-1, 10)
	f := make([]int64, 20)
	for i := range f {
		f[i] = -1
	}

	var dfs func(int, bool) int64
	dfs = func(pos int, lim bool) int64 {
		if len(t) < len(s) {
			return 0
		}
		if !lim && f[pos] != -1 {
			return f[pos]
		}
		if len(t)-pos == len(s) {
			if lim {
				if s <= t[pos:] {
					return 1
				}
				return 0
			}
			return 1
		}

		ans := int64(0)
		up := 9
		if lim {
			up = int(t[pos] - '0')
		}
		up = min(up, limit)
		for i := 0; i <= up; i++ {
			ans += dfs(pos+1, lim && i == int(t[pos]-'0'))
		}
		if !lim {
			f[pos] = ans
		}
		return ans
	}

	a := dfs(0, true)
	t = strconv.FormatInt(finish, 10)
	for i := range f {
		f[i] = -1
	}
	b := dfs(0, true)
	return b - a
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPowerfulInt(start: number, finish: number, limit: number, s: string): number {
    let t: string = (start - 1).toString();
    let f: number[] = Array(20).fill(-1);

    const dfs = (pos: number, lim: boolean): number => {
        if (t.length < s.length) {
            return 0;
        }
        if (!lim && f[pos] !== -1) {
            return f[pos];
        }
        if (t.length - pos === s.length) {
            if (lim) {
                return s <= t.substring(pos) ? 1 : 0;
            }
            return 1;
        }

        let ans: number = 0;
        const up: number = Math.min(lim ? +t[pos] : 9, limit);
        for (let i = 0; i <= up; i++) {
            ans += dfs(pos + 1, lim && i === +t[pos]);
        }

        if (!lim) {
            f[pos] = ans;
        }
        return ans;
    };

    const a: number = dfs(0, true);
    t = finish.toString();
    f = Array(20).fill(-1);
    const b: number = dfs(0, true);

    return b - a;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_powerful_int(start: i64, finish: i64, limit: i32, s: String) -> i64 {
        fn count(x: i64, limit: i32, s: &str) -> i64 {
            let t = x.to_string();
            if t.len() < s.len() {
                return 0;
            }

            let t_bytes: Vec<u8> = t.bytes().collect();
            let mut f = [-1_i64; 20];

            fn dfs(
                pos: usize,
                lim: bool,
                t: &[u8],
                s: &str,
                limit: i32,
                f: &mut [i64; 20],
            ) -> i64 {
                if t.len() < s.len() {
                    return 0;
                }

                if !lim && f[pos] != -1 {
                    return f[pos];
                }

                if t.len() - pos == s.len() {
                    if lim {
                        let suffix = &t[pos..];
                        let suffix_str = String::from_utf8_lossy(suffix);
                        return if suffix_str.as_ref() >= s { 1 } else { 0 };
                    } else {
                        return 1;
                    }
                }

                let mut ans = 0;
                let up = if lim {
                    (t[pos] - b'0').min(limit as u8)
                } else {
                    limit as u8
                };

                for i in 0..=up {
                    let next_lim = lim && i == t[pos] - b'0';
                    ans += dfs(pos + 1, next_lim, t, s, limit, f);
                }

                if !lim {
                    f[pos] = ans;
                }

                ans
            }

            dfs(0, true, &t_bytes, s, limit, &mut f)
        }

        let a = count(start - 1, limit, &s);
        let b = count(finish, limit, &s);
        b - a
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private string s;
    private string t;
    private long?[] f;
    private int limit;

    public long NumberOfPowerfulInt(long start, long finish, int limit, string s) {
        this.s = s;
        this.limit = limit;
        t = (start - 1).ToString();
        f = new long?[20];
        long a = Dfs(0, true);
        t = finish.ToString();
        f = new long?[20];
        long b = Dfs(0, true);
        return b - a;
    }

    private long Dfs(int pos, bool lim) {
        if (t.Length < s.Length) {
            return 0;
        }
        if (!lim && f[pos].HasValue) {
            return f[pos].Value;
        }
        if (t.Length - pos == s.Length) {
            return lim ? (string.Compare(s, t.Substring(pos)) <= 0 ? 1 : 0) : 1;
        }
        int up = lim ? t[pos] - '0' : 9;
        up = Math.Min(up, limit);
        long ans = 0;
        for (int i = 0; i <= up; ++i) {
            ans += Dfs(pos + 1, lim && i == (t[pos] - '0'));
        }
        if (!lim) {
            f[pos] = ans;
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

<p>给你三个整数&nbsp;<code>start</code>&nbsp;，<code>finish</code>&nbsp;和&nbsp;<code>limit</code>&nbsp;。同时给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，表示一个 <strong>正</strong>&nbsp;整数。</p>

<p>如果一个 <strong>正</strong>&nbsp;整数&nbsp;<code>x</code> 末尾部分是&nbsp;<code>s</code>&nbsp;（换句话说，<code>s</code>&nbsp;是 <code>x</code>&nbsp;的 <strong>后缀</strong>），且 <code>x</code>&nbsp;中的每个数位至多是 <code>limit</code>&nbsp;，那么我们称 <code>x</code>&nbsp;是 <strong>强大的</strong>&nbsp;。</p>

<p>请你返回区间&nbsp;<code>[start..finish]</code>&nbsp;内强大整数的&nbsp;<strong>总数目</strong>&nbsp;。</p>

<p>如果一个字符串 <code>x</code>&nbsp;是 <code>y</code>&nbsp;中某个下标开始（<strong>包括</strong>&nbsp;<code>0</code>&nbsp;），到下标为&nbsp;<code>y.length - 1</code>&nbsp;结束的子字符串，那么我们称&nbsp;<code>x</code>&nbsp;是&nbsp;<code>y</code>&nbsp;的一个后缀。比方说，<code>25</code>&nbsp;是&nbsp;<code>5125</code>&nbsp;的一个后缀，但不是&nbsp;<code>512</code>&nbsp;的后缀。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>start = 1, finish = 6000, limit = 4, s = "124"
<b>输出：</b>5
<b>解释：</b>区间 [1..6000] 内的强大数字为 124 ，1124 ，2124 ，3124 和 4124 。这些整数的各个数位都 &lt;= 4 且 "124" 是它们的后缀。注意 5124 不是强大整数，因为第一个数位 5 大于 4 。
这个区间内总共只有这 5 个强大整数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>start = 15, finish = 215, limit = 6, s = "10"
<b>输出：</b>2
<b>解释：</b>区间 [15..215] 内的强大整数为 110 和 210 。这些整数的各个数位都 &lt;= 6 且 "10" 是它们的后缀。
这个区间总共只有这 2 个强大整数。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>start = 1000, finish = 2000, limit = 4, s = "3000"
<b>输出：</b>0
<b>解释：</b>区间 [1000..2000] 内的整数都小于 3000 ，所以 "3000" 不可能是这个区间内任何整数的后缀。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= start &lt;= finish &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 9</code></li>
	<li><code>1 &lt;= s.length &lt;= floor(log<sub>10</sub>(finish)) + 1</code></li>
	<li><code>s</code>&nbsp;数位中每个数字都小于等于&nbsp;<code>limit</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;不包含任何前导 0 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，满足条件的数的个数。个数与数的位数以及每一位上的数字有关。我们可以用数位 DP 的思路来解决这道题。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

对于本题而言，我们求出 $[1, \textit{finish}]$ 中满足条件的数的个数，然后减去 $[1, \textit{start} - 1]$ 中满足条件的数的个数，即可得到答案。

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

1. 先将 $\textit{start}$ 和 $\textit{finish}$ 转化为字符串，方便后续的数位 DP。
2. 设计一个函数 $\textit{dfs}(\textit{pos}, \textit{lim})$，表示从第 $\textit{pos}$ 位开始搜索，当前的限制条件为 $\textit{lim}$。
3. 如果最大的数字位数小于 $\textit{s}$ 的长度，返回 0。
4. 如果当前剩余的数字位数等于 $\textit{s}$ 的长度，判断当前的数字是否满足条件，返回 1 或 0。
5. 否则，我们计算当前位的上限 $\textit{up} = \min(\textit{lim} ? \textit{t}[\textit{pos}] : 9, \textit{limit})$。然后遍历当前位的数字 $i$，从 0 到 $\textit{up}$，递归调用 $\textit{dfs}(\textit{pos} + 1, \textit{lim} \&\& i == \textit{t}[\textit{pos}])$，将结果累加到答案中。
6. 如果当前的 $\textit{lim}$ 为 false，则将当前的答案存入缓存中，避免重复计算。
7. 最后返回答案。

答案为区间 $[1, \textit{finish}]$ 中满足条件的数的个数减去区间 $[1, \textit{start} - 1]$ 中满足条件的数的个数。

时间复杂度 $O(\log M \times D)$，空间复杂度 $O(\log M)$，其中 $M$ 为数字的上限，而 $D = 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        @cache
        def dfs(pos: int, lim: int) -> int:
            if len(t) < n:
                return 0
            if len(t) - pos == n:
                return int(s <= t[pos:]) if lim else 1
            up = min(int(t[pos]) if lim else 9, limit)
            ans = 0
            for i in range(up + 1):
                ans += dfs(pos + 1, lim and i == int(t[pos]))
            return ans

        n = len(s)
        t = str(start - 1)
        a = dfs(0, True)
        dfs.cache_clear()
        t = str(finish)
        b = dfs(0, True)
        return b - a
```

#### Java

```java
class Solution {
    private String s;
    private String t;
    private Long[] f;
    private int limit;

    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        this.s = s;
        this.limit = limit;
        t = String.valueOf(start - 1);
        f = new Long[20];
        long a = dfs(0, true);
        t = String.valueOf(finish);
        f = new Long[20];
        long b = dfs(0, true);
        return b - a;
    }

    private long dfs(int pos, boolean lim) {
        if (t.length() < s.length()) {
            return 0;
        }
        if (!lim && f[pos] != null) {
            return f[pos];
        }
        if (t.length() - pos == s.length()) {
            return lim ? (s.compareTo(t.substring(pos)) <= 0 ? 1 : 0) : 1;
        }
        int up = lim ? t.charAt(pos) - '0' : 9;
        up = Math.min(up, limit);
        long ans = 0;
        for (int i = 0; i <= up; ++i) {
            ans += dfs(pos + 1, lim && i == (t.charAt(pos) - '0'));
        }
        if (!lim) {
            f[pos] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string t = to_string(start - 1);
        long long f[20];
        memset(f, -1, sizeof(f));

        auto dfs = [&](this auto&& dfs, int pos, int lim) -> long long {
            if (t.size() < s.size()) {
                return 0;
            }
            if (!lim && f[pos] != -1) {
                return f[pos];
            }
            if (t.size() - pos == s.size()) {
                return lim ? s <= t.substr(pos) : 1;
            }
            long long ans = 0;
            int up = min(lim ? t[pos] - '0' : 9, limit);
            for (int i = 0; i <= up; ++i) {
                ans += dfs(pos + 1, lim && i == (t[pos] - '0'));
            }
            if (!lim) {
                f[pos] = ans;
            }
            return ans;
        };

        long long a = dfs(0, true);
        t = to_string(finish);
        memset(f, -1, sizeof(f));
        long long b = dfs(0, true);
        return b - a;
    }
};
```

#### Go

```go
func numberOfPowerfulInt(start, finish int64, limit int, s string) int64 {
	t := strconv.FormatInt(start-1, 10)
	f := make([]int64, 20)
	for i := range f {
		f[i] = -1
	}

	var dfs func(int, bool) int64
	dfs = func(pos int, lim bool) int64 {
		if len(t) < len(s) {
			return 0
		}
		if !lim && f[pos] != -1 {
			return f[pos]
		}
		if len(t)-pos == len(s) {
			if lim {
				if s <= t[pos:] {
					return 1
				}
				return 0
			}
			return 1
		}

		ans := int64(0)
		up := 9
		if lim {
			up = int(t[pos] - '0')
		}
		up = min(up, limit)
		for i := 0; i <= up; i++ {
			ans += dfs(pos+1, lim && i == int(t[pos]-'0'))
		}
		if !lim {
			f[pos] = ans
		}
		return ans
	}

	a := dfs(0, true)
	t = strconv.FormatInt(finish, 10)
	for i := range f {
		f[i] = -1
	}
	b := dfs(0, true)
	return b - a
}
```

#### TypeScript

```ts
function numberOfPowerfulInt(start: number, finish: number, limit: number, s: string): number {
    let t: string = (start - 1).toString();
    let f: number[] = Array(20).fill(-1);

    const dfs = (pos: number, lim: boolean): number => {
        if (t.length < s.length) {
            return 0;
        }
        if (!lim && f[pos] !== -1) {
            return f[pos];
        }
        if (t.length - pos === s.length) {
            if (lim) {
                return s <= t.substring(pos) ? 1 : 0;
            }
            return 1;
        }

        let ans: number = 0;
        const up: number = Math.min(lim ? +t[pos] : 9, limit);
        for (let i = 0; i <= up; i++) {
            ans += dfs(pos + 1, lim && i === +t[pos]);
        }

        if (!lim) {
            f[pos] = ans;
        }
        return ans;
    };

    const a: number = dfs(0, true);
    t = finish.toString();
    f = Array(20).fill(-1);
    const b: number = dfs(0, true);

    return b - a;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_powerful_int(start: i64, finish: i64, limit: i32, s: String) -> i64 {
        fn count(x: i64, limit: i32, s: &str) -> i64 {
            let t = x.to_string();
            if t.len() < s.len() {
                return 0;
            }

            let t_bytes: Vec<u8> = t.bytes().collect();
            let mut f = [-1_i64; 20];

            fn dfs(
                pos: usize,
                lim: bool,
                t: &[u8],
                s: &str,
                limit: i32,
                f: &mut [i64; 20],
            ) -> i64 {
                if t.len() < s.len() {
                    return 0;
                }

                if !lim && f[pos] != -1 {
                    return f[pos];
                }

                if t.len() - pos == s.len() {
                    if lim {
                        let suffix = &t[pos..];
                        let suffix_str = String::from_utf8_lossy(suffix);
                        return if suffix_str.as_ref() >= s { 1 } else { 0 };
                    } else {
                        return 1;
                    }
                }

                let mut ans = 0;
                let up = if lim {
                    (t[pos] - b'0').min(limit as u8)
                } else {
                    limit as u8
                };

                for i in 0..=up {
                    let next_lim = lim && i == t[pos] - b'0';
                    ans += dfs(pos + 1, next_lim, t, s, limit, f);
                }

                if !lim {
                    f[pos] = ans;
                }

                ans
            }

            dfs(0, true, &t_bytes, s, limit, &mut f)
        }

        let a = count(start - 1, limit, &s);
        let b = count(finish, limit, &s);
        b - a
    }
}
```

#### C#

```cs
public class Solution {
    private string s;
    private string t;
    private long?[] f;
    private int limit;

    public long NumberOfPowerfulInt(long start, long finish, int limit, string s) {
        this.s = s;
        this.limit = limit;
        t = (start - 1).ToString();
        f = new long?[20];
        long a = Dfs(0, true);
        t = finish.ToString();
        f = new long?[20];
        long b = Dfs(0, true);
        return b - a;
    }

    private long Dfs(int pos, bool lim) {
        if (t.Length < s.Length) {
            return 0;
        }
        if (!lim && f[pos].HasValue) {
            return f[pos].Value;
        }
        if (t.Length - pos == s.Length) {
            return lim ? (string.Compare(s, t.Substring(pos)) <= 0 ? 1 : 0) : 1;
        }
        int up = lim ? t[pos] - '0' : 9;
        up = Math.Min(up, limit);
        long ans = 0;
        for (int i = 0; i <= up; ++i) {
            ans += Dfs(pos + 1, lim && i == (t[pos] - '0'));
        }
        if (!lim) {
            f[pos] = ans;
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
