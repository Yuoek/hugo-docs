---
title: "1140_石子游戏 II"
date: 2025-10-08T18:36:57+08:00
weight: 5
tags: [二分查找, 二叉树, 前缀和, 动态规划, 博弈, 双指针, 哈希函数, 哈希表, 字符串, 数学, 数据库, 数组, 树, 深度优先搜索, 滚动哈希, 设计, 贪心]
---

{{< markmap >}}
### [1140_石子游戏 II](#1140)
#### [数组](#1140)
#### [数学](#1140)
#### [动态规划](#1140)
#### [博弈](#1140)
#### [前缀和](#1140)
### [1141_查询近30天活跃用户数](#1141)
#### [数据库](#1141)
### [1142_过去30天的用户活动 II 🔒](#1142)
#### [数据库](#1142)
### [1143_最长公共子序列](#1143)
#### [字符串](#1143)
#### [动态规划](#1143)
### [1144_递减元素使数组呈锯齿状](#1144)
#### [贪心](#1144)
#### [数组](#1144)
### [1145_二叉树着色游戏](#1145)
#### [树](#1145)
#### [深度优先搜索](#1145)
#### [二叉树](#1145)
### [1146_快照数组](#1146)
#### [设计](#1146)
#### [数组](#1146)
#### [哈希表](#1146)
#### [二分查找](#1146)
### [1147_段式回文](#1147)
#### [贪心](#1147)
#### [双指针](#1147)
#### [字符串](#1147)
#### [动态规划](#1147)
#### [哈希函数](#1147)
#### [滚动哈希](#1147)
### [1148_文章浏览 I](#1148)
#### [数据库](#1148)
### [1149_文章浏览 II 🔒](#1149)
#### [数据库](#1149)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1140_石子游戏 II
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
___
#### 前缀和
---
### 1141_查询近30天活跃用户数
___
#### 数据库
---
### 1142_过去30天的用户活动 II 🔒
___
#### 数据库
---
### 1143_最长公共子序列
___
#### 字符串
___
#### 动态规划
---
### 1144_递减元素使数组呈锯齿状
___
#### 贪心
___
#### 数组
---
### 1145_二叉树着色游戏
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1146_快照数组
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 二分查找
---
### 1147_段式回文
___
#### 贪心
___
#### 双指针
___
#### 字符串
___
#### 动态规划
___
#### 哈希函数
___
#### 滚动哈希
---
### 1148_文章浏览 I
___
#### 数据库
---
### 1149_文章浏览 II 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 动态规划 | 博弈 | 双指针 |
| 哈希函数 | 哈希表 | 字符串 |
| 数学 | 数据库 | 数组 |
| 树 | 深度优先搜索 | 滚动哈希 |
| 设计 | 贪心 |  |

# [1140. 石子游戏 II](https://leetcode.cn/problems/stone-game-ii){#1140}

{{< tabs "1140" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        @cache
        def dfs(i: int, m: int = 1) -> int:
            if i >= len(piles):
                return 0
            t = inf
            for x in range(1, m << 1 | 1):
                t = min(t, dfs(i + x, max(m, x)))
            return s[-1] - s[i] - t

        s = list(accumulate(piles, initial=0))
        return dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] s;
    private Integer[][] f;
    private int n;

    public int stoneGameII(int[] piles) {
        n = piles.length;
        s = new int[n + 1];
        f = new Integer[n][n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + piles[i];
        }
        return dfs(0, 1);
    }

    private int dfs(int i, int m) {
        if (m * 2 >= n - i) {
            return s[n] - s[i];
        }
        if (f[i][m] != null) {
            return f[i][m];
        }
        int res = 0;
        for (int x = 1; x <= m * 2; ++x) {
            res = Math.max(res, s[n] - s[i] - dfs(i + x, Math.max(m, x)));
        }
        return f[i][m] = res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + piles[i];
        }
        int f[n][n + 1];
        memset(f, 0, sizeof f);
        function<int(int, int)> dfs = [&](int i, int m) -> int {
            if (m * 2 >= n - i) {
                return s[n] - s[i];
            }
            if (f[i][m]) {
                return f[i][m];
            }
            int res = 0;
            for (int x = 1; x <= m << 1; ++x) {
                res = max(res, s[n] - s[i] - dfs(i + x, max(x, m)));
            }
            return f[i][m] = res;
        };
        return dfs(0, 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameII(piles []int) int {
	n := len(piles)
	s := make([]int, n+1)
	f := make([][]int, n+1)
	for i, x := range piles {
		s[i+1] = s[i] + x
		f[i] = make([]int, n+1)
	}
	var dfs func(i, m int) int
	dfs = func(i, m int) int {
		if m*2 >= n-i {
			return s[n] - s[i]
		}
		if f[i][m] > 0 {
			return f[i][m]
		}
		f[i][m] = 0
		for x := 1; x <= m<<1; x++ {
			f[i][m] = max(f[i][m], s[n]-s[i]-dfs(i+x, max(m, x)))
		}
		return f[i][m]
	}
	return dfs(0, 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameII(piles: number[]): number {
    const n = piles.length;
    const f = Array.from({ length: n }, _ => new Array(n + 1).fill(0));
    const s = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + piles[i];
    }
    const dfs = (i: number, m: number) => {
        if (m * 2 >= n - i) {
            return s[n] - s[i];
        }
        if (f[i][m]) {
            return f[i][m];
        }
        let res = 0;
        for (let x = 1; x <= m * 2; ++x) {
            res = Math.max(res, s[n] - s[i] - dfs(i + x, Math.max(m, x)));
        }
        return (f[i][m] = res);
    };
    return dfs(0, 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice&nbsp;和 Bob 继续他们的石子游戏。许多堆石子&nbsp;<strong>排成一行</strong>，每堆都有正整数颗石子&nbsp;<code>piles[i]</code>。游戏以谁手中的石子最多来决出胜负。</p>

<p>Alice&nbsp;和 Bob 轮流进行，Alice 先开始。最初，<code>M = 1</code>。</p>

<p>在每个玩家的回合中，该玩家可以拿走剩下的&nbsp;<strong>前</strong>&nbsp;<code>X</code>&nbsp;堆的所有石子，其中&nbsp;<code>1 &lt;= X &lt;= 2M</code>。然后，令&nbsp;<code>M = max(M, X)</code>。</p>

<p>游戏一直持续到所有石子都被拿走。</p>

<p>假设 Alice 和 Bob 都发挥出最佳水平，返回 Alice 可以得到的最大数量的石头。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [2,7,9,4,4]
<strong>输出：</strong>10
<strong>解释：</strong>如果一开始 Alice 取了一堆，Bob 取了两堆，然后 Alice 再取两堆。Alice 可以得到 2 + 4 + 4 = 10 堆。
如果 Alice 一开始拿走了两堆，那么 Bob 可以拿走剩下的三堆。在这种情况下，Alice 得到 2 + 7 = 9 堆。返回 10，因为它更大。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>piles = [1,2,3,4,5,100]
<strong>输出：</strong>104
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 100</code></li>
	<li><meta charset="UTF-8" /><code>1 &lt;= piles[i]&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 记忆化搜索

由于玩家每次可以拿走前 $X$ 堆的所有石子，也就是说能拿走一个区间的石子，因此，我们可以先预处理出一个长度为 $n+1$ 的前缀和数组 $s$，其中 $s[i]$ 表示数组 `piles` 的前 $i$ 个元素的和。

然后我们设计一个函数 $dfs(i, m)$，表示当前轮到的人可以从数组 `piles` 的下标 $i$ 开始拿，且当前的 $M$ 为 $m$ 时，当前轮到的人能够拿到的最大石子数。初始时爱丽丝从下标 $0$ 开始，且 $M=1$，所以我们需要求的答案为 $dfs(0, 1)$。

函数 $dfs(i, m)$ 的计算过程如下：

-   如果当前轮到的人可以拿走剩下的所有石子，能够拿到的最大石子数为 $s[n] - s[i]$；
-   否则，当前轮到的人可以拿走剩下的前 $x$ 堆的所有石子，其中 $1 \leq x \leq 2m$，能够拿到的最大石子数为 $s[n] - s[i] - dfs(i + x, max(m, x))$。也即是说，当前轮的人能够拿到的石子数为当前剩下的所有石子数减去下一轮对手能够拿到的石子数。我们需要枚举所有的 $x$，取其中的最大值作为函数 $dfs(i, m)$ 的返回值。

为了避免重复计算，我们可以使用记忆化搜索。

最后，我们返回将 $dfs(0, 1)$ 作为答案返回即可。

时间复杂度为 $O(n^3)$，空间复杂度为 $O(n^2)$。其中 $n$ 为数组 `piles` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        @cache
        def dfs(i, m):
            if m * 2 >= n - i:
                return s[n] - s[i]
            return max(
                s[n] - s[i] - dfs(i + x, max(m, x)) for x in range(1, m << 1 | 1)
            )

        n = len(piles)
        s = list(accumulate(piles, initial=0))
        return dfs(0, 1)
```

#### Java

```java
class Solution {
    private int[] s;
    private Integer[][] f;
    private int n;

    public int stoneGameII(int[] piles) {
        n = piles.length;
        s = new int[n + 1];
        f = new Integer[n][n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + piles[i];
        }
        return dfs(0, 1);
    }

    private int dfs(int i, int m) {
        if (m * 2 >= n - i) {
            return s[n] - s[i];
        }
        if (f[i][m] != null) {
            return f[i][m];
        }
        int res = 0;
        for (int x = 1; x <= m * 2; ++x) {
            res = Math.max(res, s[n] - s[i] - dfs(i + x, Math.max(m, x)));
        }
        return f[i][m] = res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + piles[i];
        }
        int f[n][n + 1];
        memset(f, 0, sizeof f);
        function<int(int, int)> dfs = [&](int i, int m) -> int {
            if (m * 2 >= n - i) {
                return s[n] - s[i];
            }
            if (f[i][m]) {
                return f[i][m];
            }
            int res = 0;
            for (int x = 1; x <= m << 1; ++x) {
                res = max(res, s[n] - s[i] - dfs(i + x, max(x, m)));
            }
            return f[i][m] = res;
        };
        return dfs(0, 1);
    }
};
```

#### Go

```go
func stoneGameII(piles []int) int {
	n := len(piles)
	s := make([]int, n+1)
	f := make([][]int, n+1)
	for i, x := range piles {
		s[i+1] = s[i] + x
		f[i] = make([]int, n+1)
	}
	var dfs func(i, m int) int
	dfs = func(i, m int) int {
		if m*2 >= n-i {
			return s[n] - s[i]
		}
		if f[i][m] > 0 {
			return f[i][m]
		}
		f[i][m] = 0
		for x := 1; x <= m<<1; x++ {
			f[i][m] = max(f[i][m], s[n]-s[i]-dfs(i+x, max(m, x)))
		}
		return f[i][m]
	}
	return dfs(0, 1)
}
```

#### TypeScript

```ts
function stoneGameII(piles: number[]): number {
    const n = piles.length;
    const f = Array.from({ length: n }, _ => new Array(n + 1).fill(0));
    const s = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + piles[i];
    }
    const dfs = (i: number, m: number) => {
        if (m * 2 >= n - i) {
            return s[n] - s[i];
        }
        if (f[i][m]) {
            return f[i][m];
        }
        let res = 0;
        for (let x = 1; x <= m * 2; ++x) {
            res = Math.max(res, s[n] - s[i] - dfs(i + x, Math.max(m, x)));
        }
        return (f[i][m] = res);
    };
    return dfs(0, 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        @cache
        def dfs(i: int, m: int = 1) -> int:
            if i >= len(piles):
                return 0
            t = inf
            for x in range(1, m << 1 | 1):
                t = min(t, dfs(i + x, max(m, x)))
            return s[-1] - s[i] - t

        s = list(accumulate(piles, initial=0))
        return dfs(0)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1141. 查询近30天活跃用户数](https://leetcode.cn/problems/user-activity-for-the-past-30-days-i){#1141}

{{< tabs "1141" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date <= '2019-07-27' AND DATEDIFF('2019-07-27', activity_date) < 30
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Activity</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
该表没有包含重复数据。
activity_type 列是 ENUM(category) 类型， 从 ('open_session'， 'end_session'， 'scroll_down'， 'send_message') 取值。
该表记录社交媒体网站的用户活动。
注意，每个会话只属于一个用户。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，统计截至&nbsp;<code>2019-07-27</code>（包含2019-07-27），近<strong>&nbsp;</strong><code>30</code> 天的每日活跃用户数（当天只要有一条活动记录，即为活跃用户）。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Activity table:
+---------+------------+---------------+---------------+
| user_id | session_id | activity_date | activity_type |
+---------+------------+---------------+---------------+
| 1       | 1          | 2019-07-20    | open_session  |
| 1       | 1          | 2019-07-20    | scroll_down   |
| 1       | 1          | 2019-07-20    | end_session   |
| 2       | 4          | 2019-07-20    | open_session  |
| 2       | 4          | 2019-07-21    | send_message  |
| 2       | 4          | 2019-07-21    | end_session   |
| 3       | 2          | 2019-07-21    | open_session  |
| 3       | 2          | 2019-07-21    | send_message  |
| 3       | 2          | 2019-07-21    | end_session   |
| 4       | 3          | 2019-06-25    | open_session  |
| 4       | 3          | 2019-06-25    | end_session   |
+---------+------------+---------------+---------------+
<strong>输出：</strong>
+------------+--------------+ 
| day        | active_users |
+------------+--------------+ 
| 2019-07-20 | 2            |
| 2019-07-21 | 2            |
+------------+--------------+ <strong>
解释：</strong>注意非活跃用户的记录不需要展示。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：GROUP BY + HAVING

我们查询出所有在 `2019-07-27` 且在 $30$ 天内的所有活动记录，然后按照日期分组，统计每天的去重活跃用户数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date <= '2019-07-27' AND DATEDIFF('2019-07-27', activity_date) < 30
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1142. 过去30天的用户活动 II 🔒](https://leetcode.cn/problems/user-activity-for-the-past-30-days-ii){#1142}

{{< tabs "1142" >}}

{{% tab "sql" %}}
```sql
SELECT
    IFNULL(
        ROUND(COUNT(DISTINCT session_id) / COUNT(DISTINCT user_id), 2),
        0
    ) AS average_sessions_per_user
FROM Activity
WHERE DATEDIFF('2019-07-27', activity_date) < 30;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Activity</code> 表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
该表没有主键，它可能有重复的行。
activity_type 列是 ENUM 类型，可以取（“ open_session”，“ end_session”，“ scroll_down”，“ send_message”）四种活动类型之一。
该表显示了社交媒体网站的用户活动。
请注意，每个会话只属于一个用户。</pre>

<p>&nbsp;</p>

<p>编写解决方案，统计截至 <code>2019-07-27</code>（含）的 <code>30</code> 天内每个用户的平均会话数，<strong>四舍五入到小数点后两位</strong>。只统计那些会话期间用户至少进行一项活动的有效会话。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
Activity 表：
+---------+------------+---------------+---------------+
| user_id | session_id | activity_date | activity_type |
+---------+------------+---------------+---------------+
| 1       | 1          | 2019-07-20    | open_session  |
| 1       | 1          | 2019-07-20    | scroll_down   |
| 1       | 1          | 2019-07-20    | end_session   |
| 2       | 4          | 2019-07-20    | open_session  |
| 2       | 4          | 2019-07-21    | send_message  |
| 2       | 4          | 2019-07-21    | end_session   |
| 3       | 2          | 2019-07-21    | open_session  |
| 3       | 2          | 2019-07-21    | send_message  |
| 3       | 2          | 2019-07-21    | end_session   |
| 3       | 5          | 2019-07-21    | open_session  |
| 3       | 5          | 2019-07-21    | scroll_down   |
| 3       | 5          | 2019-07-21    | end_session   |
| 4       | 3          | 2019-06-25    | open_session  |
| 4       | 3          | 2019-06-25    | end_session   |
+---------+------------+---------------+---------------+
<strong>输出：</strong>
+---------------------------+ 
| average_sessions_per_user |
+---------------------------+ 
| 1.33                      |
+---------------------------+
<strong>解释：</strong>用户 1 和 2 每人在过去 30 天有 1 个会话，而用户 3 有 2 个会话。所以平均是 (1 + 1 + 2) / 3 = 1.33 。
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
WITH
    T AS (
        SELECT
            COUNT(DISTINCT session_id) AS sessions
        FROM Activity
        WHERE activity_date <= '2019-07-27' AND DATEDIFF('2019-07-27', activity_date) < 30
        GROUP BY user_id
    )
SELECT IFNULL(ROUND(AVG(sessions), 2), 0) AS average_sessions_per_user
FROM T;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    IFNULL(
        ROUND(COUNT(DISTINCT session_id) / COUNT(DISTINCT user_id), 2),
        0
    ) AS average_sessions_per_user
FROM Activity
WHERE DATEDIFF('2019-07-27', activity_date) < 30;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence){#1143}

{{< tabs "1143" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    f[i][j] = f[i - 1][j - 1] + 1
                else:
                    f[i][j] = max(f[i - 1][j], f[i][j - 1])
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
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
func longestCommonSubsequence(text1 string, text2 string) int {
	m, n := len(text1), len(text2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if text1[i-1] == text2[j-1] {
				f[i][j] = f[i-1][j-1] + 1
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1])
			}
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestCommonSubsequence(text1: string, text2: string): number {
    const m = text1.length;
    const n = text2.length;
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let (m, n) = (text1.len(), text2.len());
        let (text1, text2) = (text1.as_bytes(), text2.as_bytes());
        let mut f = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                f[i][j] = if text1[i - 1] == text2[j - 1] {
                    f[i - 1][j - 1] + 1
                } else {
                    f[i - 1][j].max(f[i][j - 1])
                };
            }
        }
        f[m][n]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function (text1, text2) {
    const m = text1.length;
    const n = text2.length;
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        int m = text1.Length, n = text2.Length;
        int[,] f = new int[m + 1, n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i, j] = f[i - 1, j - 1] + 1;
                } else {
                    f[i, j] = Math.Max(f[i - 1, j], f[i, j - 1]);
                }
            }
        }
        return f[m, n];
    }
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun longestCommonSubsequence(text1: String, text2: String): Int {
        val m = text1.length
        val n = text2.length
        val f = Array(m + 1) { IntArray(n + 1) }
        for (i in 1..m) {
            for (j in 1..n) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1])
                }
            }
        }
        return f[m][n]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串 <code>text1</code> 和 <code>text2</code>，返回这两个字符串的最长 <strong>公共子序列</strong> 的长度。如果不存在 <strong>公共子序列</strong> ，返回 <code>0</code> 。</p>

<p>一个字符串的 <strong>子序列</strong><em> </em>是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。</p>

<ul>
	<li>例如，<code>"ace"</code> 是 <code>"abcde"</code> 的子序列，但 <code>"aec"</code> 不是 <code>"abcde"</code> 的子序列。</li>
</ul>

<p>两个字符串的 <strong>公共子序列</strong> 是这两个字符串所共同拥有的子序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>text1 = "abcde", text2 = "ace" 
<strong>输出：</strong>3  
<strong>解释：</strong>最长公共子序列是 "ace" ，它的长度为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>text1 = "abc", text2 = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>最长公共子序列是 "abc" ，它的长度为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>text1 = "abc", text2 = "def"
<strong>输出：</strong>0
<strong>解释：</strong>两个字符串没有公共子序列，返回 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= text1.length, text2.length <= 1000</code></li>
	<li><code>text1</code> 和 <code>text2</code> 仅由小写英文字符组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示 $text1$ 的前 $i$ 个字符和 $text2$ 的前 $j$ 个字符的最长公共子序列的长度。那么答案为 $f[m][n]$，其中 $m$ 和 $n$ 分别为 $text1$ 和 $text2$ 的长度。

如果 $text1$ 的第 $i$ 个字符和 $text2$ 的第 $j$ 个字符相同，则 $f[i][j] = f[i - 1][j - 1] + 1$；如果 $text1$ 的第 $i$ 个字符和 $text2$ 的第 $j$ 个字符不同，则 $f[i][j] = max(f[i - 1][j], f[i][j - 1])$。即状态转移方程为：

$$
f[i][j] =
\begin{cases}
f[i - 1][j - 1] + 1, & text1[i - 1] = text2[j - 1] \\
\max(f[i - 1][j], f[i][j - 1]), & text1[i - 1] \neq text2[j - 1]
\end{cases}
$$

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为 $text1$ 和 $text2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    f[i][j] = f[i - 1][j - 1] + 1
                else:
                    f[i][j] = max(f[i - 1][j], f[i][j - 1])
        return f[m][n]
```

#### Java

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func longestCommonSubsequence(text1 string, text2 string) int {
	m, n := len(text1), len(text2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if text1[i-1] == text2[j-1] {
				f[i][j] = f[i-1][j-1] + 1
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1])
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function longestCommonSubsequence(text1: string, text2: string): number {
    const m = text1.length;
    const n = text2.length;
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let (m, n) = (text1.len(), text2.len());
        let (text1, text2) = (text1.as_bytes(), text2.as_bytes());
        let mut f = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                f[i][j] = if text1[i - 1] == text2[j - 1] {
                    f[i - 1][j - 1] + 1
                } else {
                    f[i - 1][j].max(f[i][j - 1])
                };
            }
        }
        f[m][n]
    }
}
```

#### JavaScript

```js
/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function (text1, text2) {
    const m = text1.length;
    const n = text2.length;
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
};
```

#### C#

```cs
public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        int m = text1.Length, n = text2.Length;
        int[,] f = new int[m + 1, n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i, j] = f[i - 1, j - 1] + 1;
                } else {
                    f[i, j] = Math.Max(f[i - 1, j], f[i, j - 1]);
                }
            }
        }
        return f[m, n];
    }
}
```

#### Kotlin

```kotlin
class Solution {
    fun longestCommonSubsequence(text1: String, text2: String): Int {
        val m = text1.length
        val n = text2.length
        val f = Array(m + 1) { IntArray(n + 1) }
        for (i in 1..m) {
            for (j in 1..n) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1])
                }
            }
        }
        return f[m][n]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1144. 递减元素使数组呈锯齿状](https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag){#1144}

{{< tabs "1144" >}}

{{% tab "python" %}}
```python
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        ans = [0, 0]
        n = len(nums)
        for i in range(2):
            for j in range(i, n, 2):
                d = 0
                if j:
                    d = max(d, nums[j] - nums[j - 1] + 1)
                if j < n - 1:
                    d = max(d, nums[j] - nums[j + 1] + 1)
                ans[i] += d
        return min(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int[] ans = new int[2];
        int n = nums.length;
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j > 0) {
                    d = Math.max(d, nums[j] - nums[j - 1] + 1);
                }
                if (j < n - 1) {
                    d = Math.max(d, nums[j] - nums[j + 1] + 1);
                }
                ans[i] += d;
            }
        }
        return Math.min(ans[0], ans[1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j) d = max(d, nums[j] - nums[j - 1] + 1);
                if (j < n - 1) d = max(d, nums[j] - nums[j + 1] + 1);
                ans[i] += d;
            }
        }
        return min(ans[0], ans[1]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func movesToMakeZigzag(nums []int) int {
	ans := [2]int{}
	n := len(nums)
	for i := 0; i < 2; i++ {
		for j := i; j < n; j += 2 {
			d := 0
			if j > 0 {
				d = max(d, nums[j]-nums[j-1]+1)
			}
			if j < n-1 {
				d = max(d, nums[j]-nums[j+1]+1)
			}
			ans[i] += d
		}
	}
	return min(ans[0], ans[1])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function movesToMakeZigzag(nums: number[]): number {
    const ans: number[] = Array(2).fill(0);
    const n = nums.length;
    for (let i = 0; i < 2; ++i) {
        for (let j = i; j < n; j += 2) {
            let d = 0;
            if (j > 0) {
                d = Math.max(d, nums[j] - nums[j - 1] + 1);
            }
            if (j < n - 1) {
                d = Math.max(d, nums[j] - nums[j + 1] + 1);
            }
            ans[i] += d;
        }
    }
    return Math.min(...ans);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MovesToMakeZigzag(int[] nums) {
        int[] ans = new int[2];
        int n = nums.Length;
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j > 0) {
                    d = Math.Max(d, nums[j] - nums[j - 1] + 1);
                }
                if (j < n - 1) {
                    d = Math.Max(d, nums[j] - nums[j + 1] + 1);
                }
                ans[i] += d;
            }
        }
        return Math.Min(ans[0], ans[1]);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，每次 <strong>操作</strong>&nbsp;会从中选择一个元素并 <strong>将该元素的值减少&nbsp;1</strong>。</p>

<p>如果符合下列情况之一，则数组&nbsp;<code>A</code>&nbsp;就是 <strong>锯齿数组</strong>：</p>

<ul>
	<li>每个偶数索引对应的元素都大于相邻的元素，即&nbsp;<code>A[0] &gt; A[1] &lt; A[2] &gt; A[3] &lt; A[4] &gt; ...</code></li>
	<li>或者，每个奇数索引对应的元素都大于相邻的元素，即&nbsp;<code>A[0] &lt; A[1] &gt; A[2] &lt; A[3] &gt; A[4] &lt; ...</code></li>
</ul>

<p>返回将数组&nbsp;<code>nums</code>&nbsp;转换为锯齿数组所需的最小操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>我们可以把 2 递减到 0，或把 3 递减到 1。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,6,1,6,2]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 贪心

我们可以分别枚举偶数位和奇数位作为“比相邻元素小”的元素，然后计算需要的操作次数。取两者的最小值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        ans = [0, 0]
        n = len(nums)
        for i in range(2):
            for j in range(i, n, 2):
                d = 0
                if j:
                    d = max(d, nums[j] - nums[j - 1] + 1)
                if j < n - 1:
                    d = max(d, nums[j] - nums[j + 1] + 1)
                ans[i] += d
        return min(ans)
```

#### Java

```java
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int[] ans = new int[2];
        int n = nums.length;
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j > 0) {
                    d = Math.max(d, nums[j] - nums[j - 1] + 1);
                }
                if (j < n - 1) {
                    d = Math.max(d, nums[j] - nums[j + 1] + 1);
                }
                ans[i] += d;
            }
        }
        return Math.min(ans[0], ans[1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j) d = max(d, nums[j] - nums[j - 1] + 1);
                if (j < n - 1) d = max(d, nums[j] - nums[j + 1] + 1);
                ans[i] += d;
            }
        }
        return min(ans[0], ans[1]);
    }
};
```

#### Go

```go
func movesToMakeZigzag(nums []int) int {
	ans := [2]int{}
	n := len(nums)
	for i := 0; i < 2; i++ {
		for j := i; j < n; j += 2 {
			d := 0
			if j > 0 {
				d = max(d, nums[j]-nums[j-1]+1)
			}
			if j < n-1 {
				d = max(d, nums[j]-nums[j+1]+1)
			}
			ans[i] += d
		}
	}
	return min(ans[0], ans[1])
}
```

#### TypeScript

```ts
function movesToMakeZigzag(nums: number[]): number {
    const ans: number[] = Array(2).fill(0);
    const n = nums.length;
    for (let i = 0; i < 2; ++i) {
        for (let j = i; j < n; j += 2) {
            let d = 0;
            if (j > 0) {
                d = Math.max(d, nums[j] - nums[j - 1] + 1);
            }
            if (j < n - 1) {
                d = Math.max(d, nums[j] - nums[j + 1] + 1);
            }
            ans[i] += d;
        }
    }
    return Math.min(...ans);
}
```

#### C#

```cs
public class Solution {
    public int MovesToMakeZigzag(int[] nums) {
        int[] ans = new int[2];
        int n = nums.Length;
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < n; j += 2) {
                int d = 0;
                if (j > 0) {
                    d = Math.Max(d, nums[j] - nums[j - 1] + 1);
                }
                if (j < n - 1) {
                    d = Math.Max(d, nums[j] - nums[j + 1] + 1);
                }
                ans[i] += d;
            }
        }
        return Math.Min(ans[0], ans[1]);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1145. 二叉树着色游戏](https://leetcode.cn/problems/binary-tree-coloring-game){#1145}

{{< tabs "1145" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        def dfs(root):
            if root is None or root.val == x:
                return root
            return dfs(root.left) or dfs(root.right)

        def count(root):
            if root is None:
                return 0
            return 1 + count(root.left) + count(root.right)

        node = dfs(root)
        l, r = count(node.left), count(node.right)
        return max(l, r, n - l - r - 1) > n // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode node = dfs(root, x);
        int l = count(node.left);
        int r = count(node.right);
        return Math.max(Math.max(l, r), n - l - r - 1) > n / 2;
    }

    private TreeNode dfs(TreeNode root, int x) {
        if (root == null || root.val == x) {
            return root;
        }
        TreeNode node = dfs(root.left, x);
        return node == null ? dfs(root.right, x) : node;
    }

    private int count(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto node = dfs(root, x);
        int l = count(node->left), r = count(node->right);
        return max({l, r, n - l - r - 1}) > n / 2;
    }

    TreeNode* dfs(TreeNode* root, int x) {
        if (!root || root->val == x) {
            return root;
        }
        auto node = dfs(root->left, x);
        return node ? node : dfs(root->right, x);
    }

    int count(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func btreeGameWinningMove(root *TreeNode, n int, x int) bool {
	var dfs func(*TreeNode) *TreeNode
	dfs = func(root *TreeNode) *TreeNode {
		if root == nil || root.Val == x {
			return root
		}
		node := dfs(root.Left)
		if node != nil {
			return node
		}
		return dfs(root.Right)
	}

	var count func(*TreeNode) int
	count = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		return 1 + count(root.Left) + count(root.Right)
	}

	node := dfs(root)
	l, r := count(node.Left), count(node.Right)
	return max(max(l, r), n-l-r-1) > n/2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function btreeGameWinningMove(root: TreeNode | null, n: number, x: number): boolean {
    const dfs = (root: TreeNode | null): TreeNode | null => {
        if (!root || root.val === x) {
            return root;
        }
        return dfs(root.left) || dfs(root.right);
    };

    const count = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    };

    const node = dfs(root);
    const l = count(node.left);
    const r = count(node.right);
    return Math.max(l, r, n - l - r - 1) > n / 2;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} n
 * @param {number} x
 * @return {boolean}
 */
var btreeGameWinningMove = function (root, n, x) {
    const dfs = root => {
        if (!root || root.val === x) {
            return root;
        }
        return dfs(root.left) || dfs(root.right);
    };

    const count = root => {
        if (!root) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    };

    const node = dfs(root);
    const l = count(node.left);
    const r = count(node.right);
    return Math.max(l, r, n - l - r - 1) > n / 2;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点&nbsp;<code>root</code>，树上总共有 <code>n</code> 个节点，且 <code>n</code> 为奇数，其中每个节点上的值从&nbsp;<code>1</code> 到&nbsp;<code>n</code>&nbsp;各不相同。</p>

<p>最开始时：</p>

<ul>
	<li>「一号」玩家从 <code>[1, n]</code>&nbsp;中取一个值&nbsp;<code>x</code>（<code>1 &lt;= x &lt;= n</code>）；</li>
	<li>「二号」玩家也从&nbsp;<code>[1, n]</code>&nbsp;中取一个值&nbsp;<code>y</code>（<code>1 &lt;= y &lt;= n</code>）且&nbsp;<code>y != x</code>。</li>
</ul>

<p>「一号」玩家给值为&nbsp;<code>x</code>&nbsp;的节点染上红色，而「二号」玩家给值为&nbsp;<code>y</code>&nbsp;的节点染上蓝色。</p>

<p>之后两位玩家轮流进行操作，「一号」玩家先手。每一回合，玩家选择一个被他染过色的节点，将所选节点一个 <strong>未着色 </strong>的邻节点（即左右子节点、或父节点）进行染色（「一号」玩家染红色，「二号」玩家染蓝色）。</p>

<p>如果（且仅在此种情况下）当前玩家无法找到这样的节点来染色时，其回合就会被跳过。</p>

<p>若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。</p>

<p>现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个&nbsp;<code>y</code>&nbsp;值可以确保你赢得这场游戏，则返回&nbsp;<code>true</code> ；若无法获胜，就请返回 <code>false</code> 。</p>
&nbsp;

<p><strong class="example">示例 1 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1145.Binary%20Tree%20Coloring%20Game/images/1480-binary-tree-coloring-game.png" style="width: 500px; height: 310px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
<strong>输出：</strong>true
<strong>解释：</strong>第二个玩家可以选择值为 2 的节点。</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3], n = 3, x = 1
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目为 <code>n</code></li>
	<li><code>1 &lt;= x &lt;= n &lt;= 100</code></li>
	<li><code>n</code> 是奇数</li>
	<li><code>1 &lt;= Node.val &lt;= n</code></li>
	<li>树中所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先通过 $DFS$，找到「一号」玩家着色点 $x$ 所在的节点，记为 $node$。

接下来，我们统计 $node$ 的左子树、右子树的节点个数，分别记为 $l$ 和 $r$，而 $node$ 父节点方向上的个数为 $n - l - r - 1$。只要满足 $\max(l, r, n - l - r - 1) > \frac{n}{2}$，则「二号」玩家存在一个必胜策略。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点总数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        def dfs(root):
            if root is None or root.val == x:
                return root
            return dfs(root.left) or dfs(root.right)

        def count(root):
            if root is None:
                return 0
            return 1 + count(root.left) + count(root.right)

        node = dfs(root)
        l, r = count(node.left), count(node.right)
        return max(l, r, n - l - r - 1) > n // 2
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode node = dfs(root, x);
        int l = count(node.left);
        int r = count(node.right);
        return Math.max(Math.max(l, r), n - l - r - 1) > n / 2;
    }

    private TreeNode dfs(TreeNode root, int x) {
        if (root == null || root.val == x) {
            return root;
        }
        TreeNode node = dfs(root.left, x);
        return node == null ? dfs(root.right, x) : node;
    }

    private int count(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto node = dfs(root, x);
        int l = count(node->left), r = count(node->right);
        return max({l, r, n - l - r - 1}) > n / 2;
    }

    TreeNode* dfs(TreeNode* root, int x) {
        if (!root || root->val == x) {
            return root;
        }
        auto node = dfs(root->left, x);
        return node ? node : dfs(root->right, x);
    }

    int count(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func btreeGameWinningMove(root *TreeNode, n int, x int) bool {
	var dfs func(*TreeNode) *TreeNode
	dfs = func(root *TreeNode) *TreeNode {
		if root == nil || root.Val == x {
			return root
		}
		node := dfs(root.Left)
		if node != nil {
			return node
		}
		return dfs(root.Right)
	}

	var count func(*TreeNode) int
	count = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		return 1 + count(root.Left) + count(root.Right)
	}

	node := dfs(root)
	l, r := count(node.Left), count(node.Right)
	return max(max(l, r), n-l-r-1) > n/2
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function btreeGameWinningMove(root: TreeNode | null, n: number, x: number): boolean {
    const dfs = (root: TreeNode | null): TreeNode | null => {
        if (!root || root.val === x) {
            return root;
        }
        return dfs(root.left) || dfs(root.right);
    };

    const count = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    };

    const node = dfs(root);
    const l = count(node.left);
    const r = count(node.right);
    return Math.max(l, r, n - l - r - 1) > n / 2;
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} n
 * @param {number} x
 * @return {boolean}
 */
var btreeGameWinningMove = function (root, n, x) {
    const dfs = root => {
        if (!root || root.val === x) {
            return root;
        }
        return dfs(root.left) || dfs(root.right);
    };

    const count = root => {
        if (!root) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    };

    const node = dfs(root);
    const l = count(node.left);
    const r = count(node.right);
    return Math.max(l, r, n - l - r - 1) > n / 2;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1146. 快照数组](https://leetcode.cn/problems/snapshot-array){#1146}

{{< tabs "1146" >}}

{{% tab "python" %}}
```python
class SnapshotArray:

    def __init__(self, length: int):
        self.arr = [[] for _ in range(length)]
        self.i = 0

    def set(self, index: int, val: int) -> None:
        self.arr[index].append((self.i, val))

    def snap(self) -> int:
        self.i += 1
        return self.i - 1

    def get(self, index: int, snap_id: int) -> int:
        i = bisect_left(self.arr[index], (snap_id, inf)) - 1
        return 0 if i < 0 else self.arr[index][i][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SnapshotArray {
    private List<int[]>[] arr;
    private int idx;

    public SnapshotArray(int length) {
        arr = new List[length];
        Arrays.setAll(arr, k -> new ArrayList<>());
    }

    public void set(int index, int val) {
        arr[index].add(new int[] {idx, val});
    }

    public int snap() {
        return idx++;
    }

    public int get(int index, int snap_id) {
        int l = 0, r = arr[index].size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[index].get(mid)[0] > snap_id) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        --l;
        return l < 0 ? 0 : arr[index].get(l)[1];
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr.resize(length);
    }

    void set(int index, int val) {
        arr[index].emplace_back(i, val);
    }

    int snap() {
        return i++;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        return it == arr[index].begin() ? 0 : prev(it)->second;
    }

private:
    vector<vector<pair<int, int>>> arr;
    int i = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SnapshotArray struct {
	arr [][][2]int
	i   int
}

func Constructor(length int) SnapshotArray {
	return SnapshotArray{make([][][2]int, length), 0}
}

func (this *SnapshotArray) Set(index int, val int) {
	this.arr[index] = append(this.arr[index], [2]int{this.i, val})
}

func (this *SnapshotArray) Snap() int {
	this.i++
	return this.i - 1
}

func (this *SnapshotArray) Get(index int, snap_id int) int {
	i := sort.Search(len(this.arr[index]), func(i int) bool { return this.arr[index][i][0] > snap_id }) - 1
	if i < 0 {
		return 0
	}
	return this.arr[index][i][1]
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * obj := Constructor(length);
 * obj.Set(index,val);
 * param_2 := obj.Snap();
 * param_3 := obj.Get(index,snap_id);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class SnapshotArray {
    private arr: [number, number][][];
    private i: number = 0;
    constructor(length: number) {
        this.arr = Array.from({ length }, () => []);
    }

    set(index: number, val: number): void {
        this.arr[index].push([this.i, val]);
    }

    snap(): number {
        return this.i++;
    }

    get(index: number, snap_id: number): number {
        let [l, r] = [0, this.arr[index].length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (this.arr[index][mid][0] > snap_id) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        --l;
        return l < 0 ? 0 : this.arr[index][l][1];
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * var obj = new SnapshotArray(length)
 * obj.set(index,val)
 * var param_2 = obj.snap()
 * var param_3 = obj.get(index,snap_id)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实现支持下列接口的「快照数组」-&nbsp;SnapshotArray：</p>

<ul>
	<li><code>SnapshotArray(int length)</code>&nbsp;- 初始化一个与指定长度相等的 类数组 的数据结构。<strong>初始时，每个元素都等于</strong><strong>&nbsp;0</strong>。</li>
	<li><code>void set(index, val)</code>&nbsp;- 会将指定索引&nbsp;<code>index</code>&nbsp;处的元素设置为&nbsp;<code>val</code>。</li>
	<li><code>int snap()</code>&nbsp;- 获取该数组的快照，并返回快照的编号&nbsp;<code>snap_id</code>（快照号是调用&nbsp;<code>snap()</code>&nbsp;的总次数减去&nbsp;<code>1</code>）。</li>
	<li><code>int get(index, snap_id)</code>&nbsp;- 根据指定的&nbsp;<code>snap_id</code>&nbsp;选择快照，并返回该快照指定索引 <code>index</code>&nbsp;的值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[&quot;SnapshotArray&quot;,&quot;set&quot;,&quot;snap&quot;,&quot;set&quot;,&quot;get&quot;]
     [[3],[0,5],[],[0,6],[0,0]]
<strong>输出：</strong>[null,null,0,null,5]
<strong>解释：
</strong>SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
snapshotArr.set(0,5);  // 令 array[0] = 5
snapshotArr.snap();  // 获取快照，返回 snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= length&nbsp;&lt;= 50000</code></li>
	<li>题目最多进行<code>50000</code> 次<code>set</code>，<code>snap</code>，和&nbsp;<code>get</code>的调用 。</li>
	<li><code>0 &lt;= index&nbsp;&lt;&nbsp;length</code></li>
	<li><code>0 &lt;=&nbsp;snap_id &lt;&nbsp;</code>我们调用&nbsp;<code>snap()</code>&nbsp;的总次数</li>
	<li><code>0 &lt;=&nbsp;val &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组 + 二分查找

我们维护一个长度为 $\textit{length}$ 的数组，数组中的每个元素是一个列表，用来存储每次设置的值以及对应的快照 ID。

调用 `set` 方法时，将值和快照 ID 添加到对应索引的列表中。时间复杂度 $O(1)$。

调用 `snap` 方法时，我们先将快照 ID 加一，然后返回快照 ID 减一。时间复杂度 $O(1)$。

调用 `get` 方法时，我们使用二分查找找到对应位置的第一个快照 ID 大于 `snap_id` 的值，然后返回前一个的值。如果找不到，则返回 0。时间复杂度 $O(\log n)$。

空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class SnapshotArray:

    def __init__(self, length: int):
        self.arr = [[] for _ in range(length)]
        self.i = 0

    def set(self, index: int, val: int) -> None:
        self.arr[index].append((self.i, val))

    def snap(self) -> int:
        self.i += 1
        return self.i - 1

    def get(self, index: int, snap_id: int) -> int:
        i = bisect_left(self.arr[index], (snap_id, inf)) - 1
        return 0 if i < 0 else self.arr[index][i][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
```

#### Java

```java
class SnapshotArray {
    private List<int[]>[] arr;
    private int idx;

    public SnapshotArray(int length) {
        arr = new List[length];
        Arrays.setAll(arr, k -> new ArrayList<>());
    }

    public void set(int index, int val) {
        arr[index].add(new int[] {idx, val});
    }

    public int snap() {
        return idx++;
    }

    public int get(int index, int snap_id) {
        int l = 0, r = arr[index].size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[index].get(mid)[0] > snap_id) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        --l;
        return l < 0 ? 0 : arr[index].get(l)[1];
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
```

#### C++

```cpp
class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr.resize(length);
    }

    void set(int index, int val) {
        arr[index].emplace_back(i, val);
    }

    int snap() {
        return i++;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        return it == arr[index].begin() ? 0 : prev(it)->second;
    }

private:
    vector<vector<pair<int, int>>> arr;
    int i = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
```

#### Go

```go
type SnapshotArray struct {
	arr [][][2]int
	i   int
}

func Constructor(length int) SnapshotArray {
	return SnapshotArray{make([][][2]int, length), 0}
}

func (this *SnapshotArray) Set(index int, val int) {
	this.arr[index] = append(this.arr[index], [2]int{this.i, val})
}

func (this *SnapshotArray) Snap() int {
	this.i++
	return this.i - 1
}

func (this *SnapshotArray) Get(index int, snap_id int) int {
	i := sort.Search(len(this.arr[index]), func(i int) bool { return this.arr[index][i][0] > snap_id }) - 1
	if i < 0 {
		return 0
	}
	return this.arr[index][i][1]
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * obj := Constructor(length);
 * obj.Set(index,val);
 * param_2 := obj.Snap();
 * param_3 := obj.Get(index,snap_id);
 */
```

#### TypeScript

```ts
class SnapshotArray {
    private arr: [number, number][][];
    private i: number = 0;
    constructor(length: number) {
        this.arr = Array.from({ length }, () => []);
    }

    set(index: number, val: number): void {
        this.arr[index].push([this.i, val]);
    }

    snap(): number {
        return this.i++;
    }

    get(index: number, snap_id: number): number {
        let [l, r] = [0, this.arr[index].length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (this.arr[index][mid][0] > snap_id) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        --l;
        return l < 0 ? 0 : this.arr[index][l][1];
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * var obj = new SnapshotArray(length)
 * obj.set(index,val)
 * var param_2 = obj.snap()
 * var param_3 = obj.get(index,snap_id)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1147. 段式回文](https://leetcode.cn/problems/longest-chunked-palindrome-decomposition){#1147}

{{< tabs "1147" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestDecomposition(self, text: str) -> int:
        def get(l, r):
            return (h[r] - h[l - 1] * p[r - l + 1]) % mod

        n = len(text)
        base = 131
        mod = int(1e9) + 7
        h = [0] * (n + 10)
        p = [1] * (n + 10)
        for i, c in enumerate(text):
            t = ord(c) - ord('a') + 1
            h[i + 1] = (h[i] * base) % mod + t
            p[i + 1] = (p[i] * base) % mod

        ans = 0
        i, j = 0, n - 1
        while i <= j:
            k = 1
            ok = False
            while i + k - 1 < j - k + 1:
                if get(i + 1, i + k) == get(j - k + 2, j + 1):
                    ans += 2
                    i += k
                    j -= k
                    ok = True
                    break
                k += 1
            if not ok:
                ans += 1
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private long[] h;
    private long[] p;

    public int longestDecomposition(String text) {
        int n = text.length();
        int base = 131;
        h = new long[n + 10];
        p = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            int t = text.charAt(i) - 'a' + 1;
            h[i + 1] = h[i] * base + t;
            p[i + 1] = p[i] * base;
        }
        int ans = 0;
        for (int i = 0, j = n - 1; i <= j;) {
            boolean ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (get(i + 1, i + k) == get(j - k + 2, j + 1)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ++ans;
                break;
            }
        }
        return ans;
    }

    private long get(int i, int j) {
        return h[j] - h[i - 1] * p[j - i + 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestDecomposition(string text) {
        using ull = unsigned long long;
        int n = text.size();
        int base = 131;
        ull p[n + 10];
        ull h[n + 10];
        p[0] = 1;
        h[0] = 0;
        for (int i = 0; i < n; ++i) {
            int t = text[i] - 'a' + 1;
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + t;
        }

        int ans = 0;
        auto get = [&](int l, int r) {
            return h[r] - h[l - 1] * p[r - l + 1];
        };
        for (int i = 0, j = n - 1; i <= j;) {
            bool ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (get(i + 1, i + k) == get(j - k + 2, j + 1)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ++ans;
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestDecomposition(text string) (ans int) {
	n := len(text)
	base := 131
	h := make([]int, n+10)
	p := make([]int, n+10)
	p[0] = 1
	for i, c := range text {
		t := int(c-'a') + 1
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + t
	}
	get := func(l, r int) int {
		return h[r] - h[l-1]*p[r-l+1]
	}

	for i, j := 0, n-1; i <= j; {
		ok := false
		for k := 1; i+k-1 < j-k+1; k++ {
			if get(i+1, i+k) == get(j-k+2, j+1) {
				ans += 2
				i += k
				j -= k
				ok = true
				break
			}
		}
		if !ok {
			ans++
			break
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestDecomposition(text: string): number {
    let ans = 0;
    for (let i = 0, j = text.length - 1; i <= j; ) {
        let ok = false;
        for (let k = 1; i + k - 1 < j - k + 1; ++k) {
            if (text.slice(i, i + k) === text.slice(j - k + 1, j + 1)) {
                ans += 2;
                i += k;
                j -= k;
                ok = true;
                break;
            }
        }
        if (!ok) {
            ++ans;
            break;
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

<p>你会得到一个字符串&nbsp;<code>text</code>&nbsp;。你应该把它分成 <code>k</code>&nbsp;个子字符串&nbsp;<code>(subtext1, subtext2，…， subtextk)</code>&nbsp;，要求满足:</p>

<ul>
	<li><code>subtext<sub>i</sub></code><sub>&nbsp;</sub>是 <strong>非空&nbsp;</strong>字符串</li>
	<li>所有子字符串的连接等于 <code>text</code> ( 即<code>subtext<sub>1</sub>&nbsp;+ subtext<sub>2</sub>&nbsp;+ ... + subtext<sub>k</sub>&nbsp;== text</code>&nbsp;)</li>
	<li>对于所有 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">i</span></span></font></font>&nbsp;的有效值( 即&nbsp;<code>1 &lt;= i&nbsp;&lt;= k</code> ) ，<code>subtext<sub>i</sub>&nbsp;== subtext<sub>k - i + 1</sub></code> 均成立</li>
</ul>

<p>返回<code>k</code>可能最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>text = "ghiabcdefhelloadamhelloabcdefghi"
<strong>输出：</strong>7
<strong>解释：</strong>我们可以把字符串拆分成 "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>text = "merchant"
<strong>输出：</strong>1
<strong>解释：</strong>我们可以把字符串拆分成 "(merchant)"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>text = "antaprezatepzapreanta"
<strong>输出：</strong>11
<strong>解释：</strong>我们可以把字符串拆分成 "(a)(nt)(a)(pre)(za)(tep)(za)(pre)(a)(nt)(a)"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 1000</code></li>
	<li><code>text</code>&nbsp;仅由小写英文字符组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

我们可以从字符串的两端开始，寻找长度最短的、相同且不重叠的前后缀：

-   如果找不到这样的前后缀，那么整个字符串作为一个段式回文，答案加 $1$；
-   如果找到了这样的前后缀，那么这个前后缀作为一个段式回文，答案加 $2$，然后继续寻找剩下的字符串的前后缀。

以上贪心策略的证明如下：

假设有一个前后缀 $A_1$ 和 $A_2$ 满足条件，又有一个前后缀 $B_1$ 和 $B_4$ 满足条件，由于 $A_1 = A_2$，且 $B_1=B_4$，那么有 $B_3=B_1=B_4=B_2$，并且 $C_1 = C_2$，因此，如果我们贪心地将 $B_1$ 和 $B_4$ 分割出来，那么剩下的 $C_1$ 和 $C_2$，以及 $B_2$ 和 $B_3$ 也能成功分割。因此我们应该贪心地选择长度最短的相同前后缀进行分割，这样剩余的字符串中，将可能分割出更多的段式回文串。

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1147.Longest%20Chunked%20Palindrome%20Decomposition/images/demo.png" style="width: 300px;" /></p>

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$ 或 $O(1)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestDecomposition(self, text: str) -> int:
        ans = 0
        i, j = 0, len(text) - 1
        while i <= j:
            k = 1
            ok = False
            while i + k - 1 < j - k + 1:
                if text[i : i + k] == text[j - k + 1 : j + 1]:
                    ans += 2
                    i += k
                    j -= k
                    ok = True
                    break
                k += 1
            if not ok:
                ans += 1
                break
        return ans
```

#### Java

```java
class Solution {
    public int longestDecomposition(String text) {
        int ans = 0;
        for (int i = 0, j = text.length() - 1; i <= j;) {
            boolean ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (check(text, i, j - k + 1, k)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ++ans;
                break;
            }
        }
        return ans;
    }

    private boolean check(String s, int i, int j, int k) {
        while (k-- > 0) {
            if (s.charAt(i++) != s.charAt(j++)) {
                return false;
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
    int longestDecomposition(string text) {
        int ans = 0;
        auto check = [&](int i, int j, int k) -> bool {
            while (k--) {
                if (text[i++] != text[j++]) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0, j = text.size() - 1; i <= j;) {
            bool ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (check(i, j - k + 1, k)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ans += 1;
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestDecomposition(text string) (ans int) {
	for i, j := 0, len(text)-1; i <= j; {
		ok := false
		for k := 1; i+k-1 < j-k+1; k++ {
			if text[i:i+k] == text[j-k+1:j+1] {
				ans += 2
				i += k
				j -= k
				ok = true
				break
			}
		}
		if !ok {
			ans++
			break
		}
	}
	return
}
```

#### TypeScript

```ts
function longestDecomposition(text: string): number {
    let ans = 0;
    for (let i = 0, j = text.length - 1; i <= j; ) {
        let ok = false;
        for (let k = 1; i + k - 1 < j - k + 1; ++k) {
            if (text.slice(i, i + k) === text.slice(j - k + 1, j + 1)) {
                ans += 2;
                i += k;
                j -= k;
                ok = true;
                break;
            }
        }
        if (!ok) {
            ++ans;
            break;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字符串哈希

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 $0$。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

因此，在方法一的基础上，我们可以使用字符串哈希的方法，在 $O(1)$ 时间内比较两个字符串是否相等。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestDecomposition(self, text: str) -> int:
        def get(l, r):
            return (h[r] - h[l - 1] * p[r - l + 1]) % mod

        n = len(text)
        base = 131
        mod = int(1e9) + 7
        h = [0] * (n + 10)
        p = [1] * (n + 10)
        for i, c in enumerate(text):
            t = ord(c) - ord('a') + 1
            h[i + 1] = (h[i] * base) % mod + t
            p[i + 1] = (p[i] * base) % mod

        ans = 0
        i, j = 0, n - 1
        while i <= j:
            k = 1
            ok = False
            while i + k - 1 < j - k + 1:
                if get(i + 1, i + k) == get(j - k + 2, j + 1):
                    ans += 2
                    i += k
                    j -= k
                    ok = True
                    break
                k += 1
            if not ok:
                ans += 1
                break
        return ans
```

#### Java

```java
class Solution {
    private long[] h;
    private long[] p;

    public int longestDecomposition(String text) {
        int n = text.length();
        int base = 131;
        h = new long[n + 10];
        p = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            int t = text.charAt(i) - 'a' + 1;
            h[i + 1] = h[i] * base + t;
            p[i + 1] = p[i] * base;
        }
        int ans = 0;
        for (int i = 0, j = n - 1; i <= j;) {
            boolean ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (get(i + 1, i + k) == get(j - k + 2, j + 1)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ++ans;
                break;
            }
        }
        return ans;
    }

    private long get(int i, int j) {
        return h[j] - h[i - 1] * p[j - i + 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestDecomposition(string text) {
        using ull = unsigned long long;
        int n = text.size();
        int base = 131;
        ull p[n + 10];
        ull h[n + 10];
        p[0] = 1;
        h[0] = 0;
        for (int i = 0; i < n; ++i) {
            int t = text[i] - 'a' + 1;
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + t;
        }

        int ans = 0;
        auto get = [&](int l, int r) {
            return h[r] - h[l - 1] * p[r - l + 1];
        };
        for (int i = 0, j = n - 1; i <= j;) {
            bool ok = false;
            for (int k = 1; i + k - 1 < j - k + 1; ++k) {
                if (get(i + 1, i + k) == get(j - k + 2, j + 1)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ++ans;
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestDecomposition(text string) (ans int) {
	n := len(text)
	base := 131
	h := make([]int, n+10)
	p := make([]int, n+10)
	p[0] = 1
	for i, c := range text {
		t := int(c-'a') + 1
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + t
	}
	get := func(l, r int) int {
		return h[r] - h[l-1]*p[r-l+1]
	}

	for i, j := 0, n-1; i <= j; {
		ok := false
		for k := 1; i+k-1 < j-k+1; k++ {
			if get(i+1, i+k) == get(j-k+2, j+1) {
				ans += 2
				i += k
				j -= k
				ok = true
				break
			}
		}
		if !ok {
			ans++
			break
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

# [1148. 文章浏览 I](https://leetcode.cn/problems/article-views-i){#1148}

{{< tabs "1148" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Views</code>&nbsp;表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
此表可能会存在重复行。（换句话说，在 SQL 中这个表没有主键）
此表的每一行都表示某人在某天浏览了某位作者的某篇文章。
请注意，同一人的 author_id 和 viewer_id 是相同的。
</pre>

<p>&nbsp;</p>

<p>请查询出所有浏览过自己文章的作者。</p>

<p>结果按照作者的&nbsp;<code>id</code> 升序排列。</p>

<p>查询结果的格式如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Views 表：
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+

<strong>输出：</strong>
+------+
| id   |
+------+
| 4    |
| 7    |
+------+
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DISTINCT + WHERE

我们利用 `WHERE` 子句来筛选出 `author_id` 和 `viewer_id` 相等的记录，然后利用 `DISTINCT` 来去重，最后按照 `id` 排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1149. 文章浏览 II 🔒](https://leetcode.cn/problems/article-views-ii){#1149}

{{< tabs "1149" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT viewer_id AS id
FROM Views
GROUP BY viewer_id, view_date
HAVING COUNT(DISTINCT article_id) > 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Views</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
此表可能会存在重复行。
此表的每一行都表示某人在某天浏览了某位作者的某篇文章。 
请注意，同一人的 author_id 和 viewer_id 是相同的。
</pre>

<p>&nbsp;</p>

<p>编写解决方案来找出在同一天阅读至少两篇文章的人。</p>

<p>结果按照 <code>id</code> 升序排序。</p>

<p>结果的格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Views 表:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 3          | 4         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
<strong>输出：</strong>
+------+
| id   |
+------+
| 5    |
| 6    |
+------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DISTINCT + GROUP BY + HAVING

我们将数据按照 `viewer_id` 和 `view_date` 分组，然后利用 `HAVING` 子句来筛选出浏览文章数大于 $1$ 的记录，最后按照 `id` 去重排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT viewer_id AS id
FROM Views
GROUP BY viewer_id, view_date
HAVING COUNT(DISTINCT article_id) > 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
