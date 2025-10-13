---
title: "0600_不含连续1的非负整数"
date: 2025-10-08T18:36:23+08:00
weight: 1
tags: [二叉树, 动态规划, 哈希表, 字符串, 数据库, 数组, 树, 深度优先搜索, 设计, 贪心, 迭代器]
---

{{< markmap >}}
### [0600_不含连续1的非负整数](#600)
#### [动态规划](#600)
### [0601_体育馆的人流量](#601)
#### [数据库](#601)
### [0602_好友申请 II ：谁有最多的好友](#602)
#### [数据库](#602)
### [0603_连续空余座位 🔒](#603)
#### [数据库](#603)
### [0604_迭代压缩字符串 🔒](#604)
#### [设计](#604)
#### [数组](#604)
#### [字符串](#604)
#### [迭代器](#604)
### [0605_种花问题](#605)
#### [贪心](#605)
#### [数组](#605)
### [0606_根据二叉树创建字符串](#606)
#### [树](#606)
#### [深度优先搜索](#606)
#### [字符串](#606)
#### [二叉树](#606)
### [0607_销售员](#607)
#### [数据库](#607)
### [0608_树节点](#608)
#### [数据库](#608)
### [0609_在系统中查找重复文件](#609)
#### [数组](#609)
#### [哈希表](#609)
#### [字符串](#609)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0600_不含连续1的非负整数
___
#### 动态规划
---
### 0601_体育馆的人流量
___
#### 数据库
---
### 0602_好友申请 II ：谁有最多的好友
___
#### 数据库
---
### 0603_连续空余座位 🔒
___
#### 数据库
---
### 0604_迭代压缩字符串 🔒
___
#### 设计
___
#### 数组
___
#### 字符串
___
#### 迭代器
---
### 0605_种花问题
___
#### 贪心
___
#### 数组
---
### 0606_根据二叉树创建字符串
___
#### 树
___
#### 深度优先搜索
___
#### 字符串
___
#### 二叉树
---
### 0607_销售员
___
#### 数据库
---
### 0608_树节点
___
#### 数据库
---
### 0609_在系统中查找重复文件
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
| 二叉树 | 动态规划 | 哈希表 |
| 字符串 | 数据库 | 数组 |
| 树 | 深度优先搜索 | 设计 |
| 贪心 | 迭代器 |  |

# [600. 不含连续1的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones){#600}

{{< tabs "600" >}}

{{% tab "python" %}}
```python
class Solution:
    def findIntegers(self, n: int) -> int:
        @cache
        def dfs(i: int, pre: int, limit: bool) -> int:
            if i < 0:
                return 1
            up = (n >> i & 1) if limit else 1
            ans = 0
            for j in range(up + 1):
                if pre and j:
                    continue
                ans += dfs(i - 1, j, limit and j == up)
            return ans

        return dfs(n.bit_length() - 1, 0, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private Integer[][] f;

    public int findIntegers(int n) {
        this.n = n;
        int m = Integer.SIZE - Integer.numberOfLeadingZeros(n);
        f = new Integer[m][2];
        return dfs(m - 1, 0, true);
    }

    private int dfs(int i, int pre, boolean limit) {
        if (i < 0) {
            return 1;
        }
        if (!limit && f[i][pre] != null) {
            return f[i][pre];
        }
        int up = limit ? (n >> i & 1) : 1;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (j == 1 && pre == 1) {
                continue;
            }
            ans += dfs(i - 1, j, limit && j == up);
        }
        if (!limit) {
            f[i][pre] = ans;
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
    int findIntegers(int n) {
        int m = 32 - __builtin_clz(n);
        int f[m][2];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int pre, bool limit) -> int {
            if (i < 0) {
                return 1;
            }
            if (!limit && f[i][pre] != -1) {
                return f[i][pre];
            }
            int up = limit ? (n >> i & 1) : 1;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j && pre) {
                    continue;
                }
                ans += dfs(i - 1, j, limit && j == up);
            }
            if (!limit) {
                f[i][pre] = ans;
            }
            return ans;
        };
        return dfs(m - 1, 0, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findIntegers(n int) int {
	m := bits.Len(uint(n))
	f := make([][2]int, m)
	for i := range f {
		f[i] = [2]int{-1, -1}
	}
	var dfs func(i, pre int, limit bool) int
	dfs = func(i, pre int, limit bool) int {
		if i < 0 {
			return 1
		}
		if !limit && f[i][pre] != -1 {
			return f[i][pre]
		}
		up := 1
		if limit {
			up = n >> i & 1
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if j == 1 && pre == 1 {
				continue
			}
			ans += dfs(i-1, j, limit && j == up)
		}
		if !limit {
			f[i][pre] = ans
		}
		return ans
	}
	return dfs(m-1, 0, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findIntegers(n: number): number {
    const m = n.toString(2).length;
    const f: number[][] = Array.from({ length: m }, () => Array(2).fill(-1));
    const dfs = (i: number, pre: number, limit: boolean): number => {
        if (i < 0) {
            return 1;
        }
        if (!limit && f[i][pre] !== -1) {
            return f[i][pre];
        }
        const up = limit ? (n >> i) & 1 : 1;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if (pre === 1 && j === 1) {
                continue;
            }
            ans += dfs(i - 1, j, limit && j === up);
        }
        if (!limit) {
            f[i][pre] = ans;
        }
        return ans;
    };
    return dfs(m - 1, 0, true);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数 <code>n</code> ，请你统计在&nbsp;<code>[0, n]</code> 范围的非负整数中，有多少个整数的二进制表示中不存在 <strong>连续的 1 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 5
<strong>输出:</strong> 5
<strong>解释:</strong> 
下面列出范围在 [0, 5] 的非负整数与其对应的二进制表示：
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
其中，只有整数 3 违反规则（有两个连续的 1 ），其他 5 个满足规则。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 1
<strong>输出:</strong> 2
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> 3
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，数字的二进制表示不包含连续的 $1$ 的个数。个数与数的位数以及每个二进制位上的数字有关。我们可以用数位 DP 的思路来解决这道题。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[0,..r]$ 然后再减去 $[0,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=0}^{r} ans_i -  \sum_{i=0}^{l-1} ans_i
$$

不过对于本题而言，我们只需要求出区间 $[0,..r]$ 的值即可。

这里我们用记忆化搜索来实现数位 DP。基本步骤如下：

我们首先获取数字 $n$ 的二进制长度，记为 $m$。然后根据题目信息，我们设计函数 $\textit{dfs}(i, \textit{pre}, \textit{limit})$，其中：

-   数字 $i$ 表示当前搜索到的位置，我们从数字的最高位开始搜索，即二进制字符串的首字符；
-   数字 $\textit{pre}$ 表示上一个数字二进制位上的数字，对于本题，$\textit{pre}$ 的初始值为 $0$；
-   布尔值 $\textit{limit}$ 表示可填的数字的限制，如果无限制，那么可以选择 $[0,1]$，否则，只能选择 $[0, \textit{up}]$。

函数的执行过程如下：

如果 $i$ 超过了数字 $n$ 的长度，即 $i \lt 0$，说明搜索结束，直接返回 $1$。否则，我们从 $0$ 到 $\textit{up}$ 枚举位置 $i$ 的数字 $j$，对于每一个 $j$：

-   如果 $\textit{pre}$ 和 $j$ 都为 $1$，说明有连续的 $1$，直接跳过；
-   否则，我们递归到下一层，更新 $\textit{pre}$ 为 $j$，并将 $\textit{limit}$ 更新为 $\textit{limit}$ 与 $j$ 是否等于 $\textit{up}$ 的逻辑与。

最后，我们将所有递归到下一层的结果累加，即为答案。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为题目给定的正整数。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)
-   [357. 统计各位数字都不同的数字个数](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0357.Count%20Numbers%20with%20Unique%20Digits/README.md)
-   [788. 旋转数字](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0788.Rotated%20Digits/README.md)
-   [902. 最大为 N 的数字组合](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0902.Numbers%20At%20Most%20N%20Given%20Digit%20Set/README.md)
-   [1012. 至少有 1 位重复的数字](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1012.Numbers%20With%20Repeated%20Digits/README.md)
-   [2376. 统计特殊整数](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2376.Count%20Special%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findIntegers(self, n: int) -> int:
        @cache
        def dfs(i: int, pre: int, limit: bool) -> int:
            if i < 0:
                return 1
            up = (n >> i & 1) if limit else 1
            ans = 0
            for j in range(up + 1):
                if pre and j:
                    continue
                ans += dfs(i - 1, j, limit and j == up)
            return ans

        return dfs(n.bit_length() - 1, 0, True)
```

#### Java

```java
class Solution {
    private int n;
    private Integer[][] f;

    public int findIntegers(int n) {
        this.n = n;
        int m = Integer.SIZE - Integer.numberOfLeadingZeros(n);
        f = new Integer[m][2];
        return dfs(m - 1, 0, true);
    }

    private int dfs(int i, int pre, boolean limit) {
        if (i < 0) {
            return 1;
        }
        if (!limit && f[i][pre] != null) {
            return f[i][pre];
        }
        int up = limit ? (n >> i & 1) : 1;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (j == 1 && pre == 1) {
                continue;
            }
            ans += dfs(i - 1, j, limit && j == up);
        }
        if (!limit) {
            f[i][pre] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findIntegers(int n) {
        int m = 32 - __builtin_clz(n);
        int f[m][2];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int pre, bool limit) -> int {
            if (i < 0) {
                return 1;
            }
            if (!limit && f[i][pre] != -1) {
                return f[i][pre];
            }
            int up = limit ? (n >> i & 1) : 1;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j && pre) {
                    continue;
                }
                ans += dfs(i - 1, j, limit && j == up);
            }
            if (!limit) {
                f[i][pre] = ans;
            }
            return ans;
        };
        return dfs(m - 1, 0, true);
    }
};
```

#### Go

```go
func findIntegers(n int) int {
	m := bits.Len(uint(n))
	f := make([][2]int, m)
	for i := range f {
		f[i] = [2]int{-1, -1}
	}
	var dfs func(i, pre int, limit bool) int
	dfs = func(i, pre int, limit bool) int {
		if i < 0 {
			return 1
		}
		if !limit && f[i][pre] != -1 {
			return f[i][pre]
		}
		up := 1
		if limit {
			up = n >> i & 1
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if j == 1 && pre == 1 {
				continue
			}
			ans += dfs(i-1, j, limit && j == up)
		}
		if !limit {
			f[i][pre] = ans
		}
		return ans
	}
	return dfs(m-1, 0, true)
}
```

#### TypeScript

```ts
function findIntegers(n: number): number {
    const m = n.toString(2).length;
    const f: number[][] = Array.from({ length: m }, () => Array(2).fill(-1));
    const dfs = (i: number, pre: number, limit: boolean): number => {
        if (i < 0) {
            return 1;
        }
        if (!limit && f[i][pre] !== -1) {
            return f[i][pre];
        }
        const up = limit ? (n >> i) & 1 : 1;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if (pre === 1 && j === 1) {
                continue;
            }
            ans += dfs(i - 1, j, limit && j === up);
        }
        if (!limit) {
            f[i][pre] = ans;
        }
        return ans;
    };
    return dfs(m - 1, 0, true);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [601. 体育馆的人流量](https://leetcode.cn/problems/human-traffic-of-stadium){#601}

{{< tabs "601" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            *,
            id - (ROW_NUMBER() OVER (ORDER BY id)) AS rk
        FROM Stadium
        WHERE people >= 100
    ),
    T AS (SELECT *, COUNT(1) OVER (PARTITION BY rk) AS cnt FROM S)
SELECT id, visit_date, people
FROM T
WHERE cnt >= 3
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

表：<code>Stadium</code>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| visit_date    | date    |
| people        | int     |
+---------------+---------+
visit_date 是该表中具有唯一值的列。
每日人流量信息被记录在这三列信息中：<strong>序号</strong> (id)、<strong>日期</strong> (visit_date)、&nbsp;<strong>人流量</strong> (people)
每天只有一行记录，日期随着 id 的增加而增加
</pre>

<p>&nbsp;</p>

<p>编写解决方案找出每行的人数大于或等于 <code>100</code> 且 <code>id</code> 连续的三行或更多行记录。</p>

<p>返回按 <code>visit_date</code> <strong>升序排列</strong> 的结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Stadium</code> 表:
+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-09 | 188       |
+------+------------+-----------+
<strong>输出：</strong>
+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-09 | 188       |
+------+------------+-----------+
<strong>解释：
id</strong> 为 5、6、7、8 的四行 id 连续，并且每行都有 &gt;= 100 的人数记录。
请注意，即使第 7 行和第 8 行的 visit_date 不是连续的，输出也应当包含第 8 行，因为我们只需要考虑 id 连续的记录。
不输出 id 为 2 和 3 的行，因为至少需要三条 id 连续的记录。</pre>

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
    S AS (
        SELECT
            *,
            id - (ROW_NUMBER() OVER (ORDER BY id)) AS rk
        FROM Stadium
        WHERE people >= 100
    ),
    T AS (SELECT *, COUNT(1) OVER (PARTITION BY rk) AS cnt FROM S)
SELECT id, visit_date, people
FROM T
WHERE cnt >= 3
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [602. 好友申请 II ：谁有最多的好友](https://leetcode.cn/problems/friend-requests-ii-who-has-the-most-friends){#602}

{{< tabs "602" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT requester_id, accepter_id FROM RequestAccepted
        UNION ALL
        SELECT accepter_id, requester_id FROM RequestAccepted
    )
SELECT requester_id AS id, COUNT(1) AS num
FROM T
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>RequestAccepted</code> 表：</p>

<div class="original__bRMd">
<div>
<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| requester_id   | int     |
| accepter_id    | int     |
| accept_date    | date    |
+----------------+---------+
(requester_id, accepter_id) 是这张表的主键(具有唯一值的列的组合)。
这张表包含发送好友请求的人的 ID ，接收好友请求的人的 ID ，以及好友请求通过的日期。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出拥有最多的好友的人和他拥有的好友数目。</p>

<p>生成的测试用例保证拥有最多好友数目的只有 1 个人。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
RequestAccepted 表：
+--------------+-------------+-------------+
| requester_id | accepter_id | accept_date |
+--------------+-------------+-------------+
| 1            | 2           | 2016/06/03  |
| 1            | 3           | 2016/06/08  |
| 2            | 3           | 2016/06/08  |
| 3            | 4           | 2016/06/09  |
+--------------+-------------+-------------+
<strong>输出：</strong>
+----+-----+
| id | num |
+----+-----+
| 3  | 3   |
+----+-----+
<strong>解释：</strong>
编号为 3 的人是编号为 1 ，2 和 4 的人的好友，所以他总共有 3 个好友，比其他人都多。</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong>在真实世界里，可能会有多个人拥有好友数相同且最多，你能找到所有这些人吗？</p>
</div>
</div>

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
        SELECT requester_id, accepter_id FROM RequestAccepted
        UNION ALL
        SELECT accepter_id, requester_id FROM RequestAccepted
    )
SELECT requester_id AS id, COUNT(1) AS num
FROM T
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [603. 连续空余座位 🔒](https://leetcode.cn/problems/consecutive-available-seats){#603}

{{< tabs "603" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            SUM(free = 1) OVER (
                ORDER BY seat_id
                ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING
            ) AS cnt
        FROM Cinema
    )
SELECT seat_id
FROM T
WHERE free = 1 AND cnt > 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Cinema</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| seat_id     | int  |
| free        | bool |
+-------------+------+
Seat_id 是该表的自动递增主键列。
在 PostgreSQL 中，<code>free</code> 存储为整数。请使用 <code>::boolean</code> 将其转换为布尔格式。
该表的每一行表示第 i 个座位是否空闲。1 表示空闲，0 表示被占用。</pre>

<p>&nbsp;</p>

<p>查找电影院所有连续可用的座位。</p>

<p>返回按 <code>seat_id</code> <strong>升序排序&nbsp;</strong>的结果表。</p>

<p>测试用例的生成使得两个以上的座位连续可用。</p>

<p>结果表格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Cinema 表:
+---------+------+
| seat_id | free |
+---------+------+
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
+---------+------+
<strong>输出:</strong> 
+---------+
| seat_id |
+---------+
| 3       |
| 4       |
| 5       |
+---------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接

我们可以使用自连接的方式，将相邻的两个座位连接起来，然后筛选出连续空余的座位并去重排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT a.seat_id
FROM
    Cinema AS a
    JOIN Cinema AS b ON ABS(a.seat_id - b.seat_id) = 1 AND a.free AND b.free
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们也可以使用 `LAG` 和 `LEAD` 函数（或者 `SUM() OVER(ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING)`）来获取相邻的座位信息，然后筛选出连续空余的座位并去重排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            seat_id,
            (free + (LAG(free) OVER (ORDER BY seat_id))) AS a,
            (free + (LEAD(free) OVER (ORDER BY seat_id))) AS b
        FROM Cinema
    )
SELECT seat_id
FROM T
WHERE a = 2 OR b = 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            SUM(free = 1) OVER (
                ORDER BY seat_id
                ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING
            ) AS cnt
        FROM Cinema
    )
SELECT seat_id
FROM T
WHERE free = 1 AND cnt > 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [604. 迭代压缩字符串 🔒](https://leetcode.cn/problems/design-compressed-string-iterator){#604}

{{< tabs "604" >}}

{{% tab "python" %}}
```python
class StringIterator:
    def __init__(self, compressedString: str):
        self.d = []
        self.p = 0
        n = len(compressedString)
        i = 0
        while i < n:
            c = compressedString[i]
            x = 0
            i += 1
            while i < n and compressedString[i].isdigit():
                x = x * 10 + int(compressedString[i])
                i += 1
            self.d.append([c, x])

    def next(self) -> str:
        if not self.hasNext():
            return ' '
        ans = self.d[self.p][0]
        self.d[self.p][1] -= 1
        if self.d[self.p][1] == 0:
            self.p += 1
        return ans

    def hasNext(self) -> bool:
        return self.p < len(self.d) and self.d[self.p][1] > 0


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class StringIterator {
    private List<Node> d = new ArrayList<>();
    private int p;

    public StringIterator(String compressedString) {
        int n = compressedString.length();
        int i = 0;
        while (i < n) {
            char c = compressedString.charAt(i);
            int x = 0;
            while (++i < n && Character.isDigit(compressedString.charAt(i))) {
                x = x * 10 + (compressedString.charAt(i) - '0');
            }
            d.add(new Node(c, x));
        }
    }

    public char next() {
        if (!hasNext()) {
            return ' ';
        }
        char ans = d.get(p).c;
        if (--d.get(p).x == 0) {
            ++p;
        }
        return ans;
    }

    public boolean hasNext() {
        return p < d.size() && d.get(p).x > 0;
    }
}

class Node {
    char c;
    int x;

    Node(char c, int x) {
        this.c = c;
        this.x = x;
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class StringIterator {
public:
    StringIterator(string compressedString) {
        int n = compressedString.size();
        int i = 0;
        while (i < n) {
            char c = compressedString[i];
            int x = 0;
            while (++i < n && isdigit(compressedString[i])) {
                x = x * 10 + (compressedString[i] - '0');
            }
            d.push_back({c, x});
        }
    }

    char next() {
        if (!hasNext()) return ' ';
        char ans = d[p].first;
        if (--d[p].second == 0) {
            ++p;
        }
        return ans;
    }

    bool hasNext() {
        return p < d.size() && d[p].second > 0;
    }

private:
    vector<pair<char, int>> d;
    int p = 0;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type pair struct {
	c byte
	x int
}

type StringIterator struct {
	d []pair
	p int
}

func Constructor(compressedString string) StringIterator {
	n := len(compressedString)
	i := 0
	d := []pair{}
	for i < n {
		c := compressedString[i]
		x := 0
		i++
		for i < n && compressedString[i] >= '0' && compressedString[i] <= '9' {
			x = x*10 + int(compressedString[i]-'0')
			i++
		}
		d = append(d, pair{c, x})
	}
	return StringIterator{d, 0}
}

func (this *StringIterator) Next() byte {
	if !this.HasNext() {
		return ' '
	}
	ans := this.d[this.p].c
	this.d[this.p].x--
	if this.d[this.p].x == 0 {
		this.p++
	}
	return ans
}

func (this *StringIterator) HasNext() bool {
	return this.p < len(this.d) && this.d[this.p].x > 0
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * obj := Constructor(compressedString);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class StringIterator {
    private d: [string, number][] = [];
    private p: number = 0;

    constructor(compressedString: string) {
        const n = compressedString.length;
        let i = 0;
        while (i < n) {
            const c = compressedString[i];
            let x = 0;
            i++;
            while (i < n && !isNaN(Number(compressedString[i]))) {
                x = x * 10 + Number(compressedString[i]);
                i++;
            }
            this.d.push([c, x]);
        }
    }

    next(): string {
        if (!this.hasNext()) {
            return ' ';
        }
        const ans = this.d[this.p][0];
        this.d[this.p][1]--;
        if (this.d[this.p][1] === 0) {
            this.p++;
        }
        return ans;
    }

    hasNext(): boolean {
        return this.p < this.d.length && this.d[this.p][1] > 0;
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * var obj = new StringIterator(compressedString)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计并实现一个迭代压缩字符串的数据结构。给定的压缩字符串的形式是，每个字母后面紧跟一个正整数，表示该字母在原始未压缩字符串中出现的次数。</p>

<p>设计一个数据结构，它支持如下两种操作：&nbsp;<code>next</code>&nbsp;和&nbsp;<code>hasNext</code>。</p>

<ul>
	<li><code>next()</code> - 如果原始字符串中仍有未压缩字符，则返回<strong>下一个字符</strong>，否则返回<strong>空格</strong>。</li>
	<li><code>hasNext()</code> - 如果原始字符串中存在未压缩的的字母，则返回true，否则返回<code>false</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["StringIterator", "next", "next", "next", "next", "next", "next", "hasNext", "next", "hasNext"]
[["L1e2t1C1o1d1e1"], [], [], [], [], [], [], [], [], []]
<b>输出：</b>
[null, "L", "e", "e", "t", "C", "o", true, "d", true]

<strong>解释：</strong>
StringIterator stringIterator = new StringIterator("L1e2t1C1o1d1e1");
stringIterator.next(); // 返回 "L"
stringIterator.next(); // 返回 "e"
stringIterator.next(); // 返回 "e"
stringIterator.next(); // 返回 "t"
stringIterator.next(); // 返回 "C"
stringIterator.next(); // 返回 "o"
stringIterator.hasNext(); // 返回 True
stringIterator.next(); // 返回 "d"
stringIterator.hasNext(); // 返回 True</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;compressedString.length &lt;= 1000</code></li>
	<li><code>compressedString</code>&nbsp;由小写字母、大写字母和数字组成。</li>
	<li>在&nbsp;<code>compressedString</code>&nbsp;中，单个字符的重复次数在&nbsp;<code>[1,10 ^9]</code>&nbsp;范围内。</li>
	<li><code>next</code>&nbsp;和&nbsp;<code>hasNext</code>&nbsp;的操作数最多为&nbsp;<code>100</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：解析存储

将 `compressedString` 解析成字符 $c$ 和对应的重复次数 $x$，存储在数组或列表 $d$ 中，用 $p$ 指向当前字符。

然后在 `next` 和 `hasNext` 中进行操作。

初始化的时间复杂度为 $O(n)$，其余操作的时间复杂度为 $O(1)$。其中 $n$ 为 `compressedString` 的长度。

<!-- tabs:start -->

#### Python3

```python
class StringIterator:
    def __init__(self, compressedString: str):
        self.d = []
        self.p = 0
        n = len(compressedString)
        i = 0
        while i < n:
            c = compressedString[i]
            x = 0
            i += 1
            while i < n and compressedString[i].isdigit():
                x = x * 10 + int(compressedString[i])
                i += 1
            self.d.append([c, x])

    def next(self) -> str:
        if not self.hasNext():
            return ' '
        ans = self.d[self.p][0]
        self.d[self.p][1] -= 1
        if self.d[self.p][1] == 0:
            self.p += 1
        return ans

    def hasNext(self) -> bool:
        return self.p < len(self.d) and self.d[self.p][1] > 0


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```

#### Java

```java
class StringIterator {
    private List<Node> d = new ArrayList<>();
    private int p;

    public StringIterator(String compressedString) {
        int n = compressedString.length();
        int i = 0;
        while (i < n) {
            char c = compressedString.charAt(i);
            int x = 0;
            while (++i < n && Character.isDigit(compressedString.charAt(i))) {
                x = x * 10 + (compressedString.charAt(i) - '0');
            }
            d.add(new Node(c, x));
        }
    }

    public char next() {
        if (!hasNext()) {
            return ' ';
        }
        char ans = d.get(p).c;
        if (--d.get(p).x == 0) {
            ++p;
        }
        return ans;
    }

    public boolean hasNext() {
        return p < d.size() && d.get(p).x > 0;
    }
}

class Node {
    char c;
    int x;

    Node(char c, int x) {
        this.c = c;
        this.x = x;
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```

#### C++

```cpp
class StringIterator {
public:
    StringIterator(string compressedString) {
        int n = compressedString.size();
        int i = 0;
        while (i < n) {
            char c = compressedString[i];
            int x = 0;
            while (++i < n && isdigit(compressedString[i])) {
                x = x * 10 + (compressedString[i] - '0');
            }
            d.push_back({c, x});
        }
    }

    char next() {
        if (!hasNext()) return ' ';
        char ans = d[p].first;
        if (--d[p].second == 0) {
            ++p;
        }
        return ans;
    }

    bool hasNext() {
        return p < d.size() && d[p].second > 0;
    }

private:
    vector<pair<char, int>> d;
    int p = 0;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

#### Go

```go
type pair struct {
	c byte
	x int
}

type StringIterator struct {
	d []pair
	p int
}

func Constructor(compressedString string) StringIterator {
	n := len(compressedString)
	i := 0
	d := []pair{}
	for i < n {
		c := compressedString[i]
		x := 0
		i++
		for i < n && compressedString[i] >= '0' && compressedString[i] <= '9' {
			x = x*10 + int(compressedString[i]-'0')
			i++
		}
		d = append(d, pair{c, x})
	}
	return StringIterator{d, 0}
}

func (this *StringIterator) Next() byte {
	if !this.HasNext() {
		return ' '
	}
	ans := this.d[this.p].c
	this.d[this.p].x--
	if this.d[this.p].x == 0 {
		this.p++
	}
	return ans
}

func (this *StringIterator) HasNext() bool {
	return this.p < len(this.d) && this.d[this.p].x > 0
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * obj := Constructor(compressedString);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```

#### TypeScript

```ts
class StringIterator {
    private d: [string, number][] = [];
    private p: number = 0;

    constructor(compressedString: string) {
        const n = compressedString.length;
        let i = 0;
        while (i < n) {
            const c = compressedString[i];
            let x = 0;
            i++;
            while (i < n && !isNaN(Number(compressedString[i]))) {
                x = x * 10 + Number(compressedString[i]);
                i++;
            }
            this.d.push([c, x]);
        }
    }

    next(): string {
        if (!this.hasNext()) {
            return ' ';
        }
        const ans = this.d[this.p][0];
        this.d[this.p][1]--;
        if (this.d[this.p][1] === 0) {
            this.p++;
        }
        return ans;
    }

    hasNext(): boolean {
        return this.p < this.d.length && this.d[this.p][1] > 0;
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * var obj = new StringIterator(compressedString)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [605. 种花问题](https://leetcode.cn/problems/can-place-flowers){#605}

{{< tabs "605" >}}

{{% tab "python" %}}
```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed = [0] + flowerbed + [0]
        for i in range(1, len(flowerbed) - 1):
            if sum(flowerbed[i - 1 : i + 2]) == 0:
                flowerbed[i] = 1
                n -= 1
        return n <= 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int m = flowerbed.length;
        for (int i = 0; i < m; ++i) {
            int l = i == 0 ? 0 : flowerbed[i - 1];
            int r = i == m - 1 ? 0 : flowerbed[i + 1];
            if (l + flowerbed[i] + r == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n <= 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i < m; ++i) {
            int l = i == 0 ? 0 : flowerbed[i - 1];
            int r = i == m - 1 ? 0 : flowerbed[i + 1];
            if (l + flowerbed[i] + r == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n <= 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canPlaceFlowers(flowerbed []int, n int) bool {
	m := len(flowerbed)
	for i, v := range flowerbed {
		l, r := 0, 0
		if i > 0 {
			l = flowerbed[i-1]
		}
		if i < m-1 {
			r = flowerbed[i+1]
		}
		if l+v+r == 0 {
			flowerbed[i] = 1
			n--
		}
	}
	return n <= 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canPlaceFlowers(flowerbed: number[], n: number): boolean {
    const m = flowerbed.length;
    for (let i = 0; i < m; ++i) {
        const l = i === 0 ? 0 : flowerbed[i - 1];
        const r = i === m - 1 ? 0 : flowerbed[i + 1];
        if (l + flowerbed[i] + r === 0) {
            flowerbed[i] = 1;
            --n;
        }
    }
    return n <= 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let (mut flowers, mut cnt) = (vec![0], 0);
        flowers.append(&mut flowerbed.clone());
        flowers.push(0);

        for i in 1..flowers.len() - 1 {
            let (l, r) = (flowers[i - 1], flowers[i + 1]);
            if l + flowers[i] + r == 0 {
                flowers[i] = 1;
                cnt += 1;
            }
        }
        cnt >= n
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $flowerbed
     * @param Integer $n
     * @return Boolean
     */
    function canPlaceFlowers($flowerbed, $n) {
        array_push($flowerbed, 0);
        array_unshift($flowerbed, 0);
        for ($i = 1; $i < count($flowerbed) - 1; $i++) {
            if ($flowerbed[$i] === 0) {
                if ($flowerbed[$i - 1] === 0 && $flowerbed[$i + 1] === 0) {
                    $flowerbed[$i] = 1;
                    $n--;
                }
            }
        }
        return $n <= 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。</p>

<p>给你一个整数数组&nbsp;<code>flowerbed</code> 表示花坛，由若干 <code>0</code> 和 <code>1</code> 组成，其中 <code>0</code> 表示没种植花，<code>1</code> 表示种植了花。另有一个数&nbsp;<code>n</code><strong> </strong>，能否在不打破种植规则的情况下种入&nbsp;<code>n</code><strong>&nbsp;</strong>朵花？能则返回 <code>true</code> ，不能则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>flowerbed = [1,0,0,0,1], n = 1
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>flowerbed = [1,0,0,0,1], n = 2
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= flowerbed.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>flowerbed[i]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>flowerbed</code> 中不存在相邻的两朵花</li>
	<li><code>0 &lt;= n &lt;= flowerbed.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们直接遍历数组 $flowerbed$，对于每个位置 $i$，如果 $flowerbed[i]=0$，并且其左右相邻位置都为 $0$，则我们可以在该位置种花，否则不能。最后我们统计可以种下的花的数量，如果其不小于 $n$，则返回 $true$，否则返回 $false$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $flowerbed$ 的长度。我们只需要遍历数组一次。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed = [0] + flowerbed + [0]
        for i in range(1, len(flowerbed) - 1):
            if sum(flowerbed[i - 1 : i + 2]) == 0:
                flowerbed[i] = 1
                n -= 1
        return n <= 0
```

#### Java

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int m = flowerbed.length;
        for (int i = 0; i < m; ++i) {
            int l = i == 0 ? 0 : flowerbed[i - 1];
            int r = i == m - 1 ? 0 : flowerbed[i + 1];
            if (l + flowerbed[i] + r == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n <= 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i < m; ++i) {
            int l = i == 0 ? 0 : flowerbed[i - 1];
            int r = i == m - 1 ? 0 : flowerbed[i + 1];
            if (l + flowerbed[i] + r == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n <= 0;
    }
};
```

#### Go

```go
func canPlaceFlowers(flowerbed []int, n int) bool {
	m := len(flowerbed)
	for i, v := range flowerbed {
		l, r := 0, 0
		if i > 0 {
			l = flowerbed[i-1]
		}
		if i < m-1 {
			r = flowerbed[i+1]
		}
		if l+v+r == 0 {
			flowerbed[i] = 1
			n--
		}
	}
	return n <= 0
}
```

#### TypeScript

```ts
function canPlaceFlowers(flowerbed: number[], n: number): boolean {
    const m = flowerbed.length;
    for (let i = 0; i < m; ++i) {
        const l = i === 0 ? 0 : flowerbed[i - 1];
        const r = i === m - 1 ? 0 : flowerbed[i + 1];
        if (l + flowerbed[i] + r === 0) {
            flowerbed[i] = 1;
            --n;
        }
    }
    return n <= 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let (mut flowers, mut cnt) = (vec![0], 0);
        flowers.append(&mut flowerbed.clone());
        flowers.push(0);

        for i in 1..flowers.len() - 1 {
            let (l, r) = (flowers[i - 1], flowers[i + 1]);
            if l + flowers[i] + r == 0 {
                flowers[i] = 1;
                cnt += 1;
            }
        }
        cnt >= n
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $flowerbed
     * @param Integer $n
     * @return Boolean
     */
    function canPlaceFlowers($flowerbed, $n) {
        array_push($flowerbed, 0);
        array_unshift($flowerbed, 0);
        for ($i = 1; $i < count($flowerbed) - 1; $i++) {
            if ($flowerbed[$i] === 0) {
                if ($flowerbed[$i - 1] === 0 && $flowerbed[$i + 1] === 0) {
                    $flowerbed[$i] = 1;
                    $n--;
                }
            }
        }
        return $n <= 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [606. 根据二叉树创建字符串](https://leetcode.cn/problems/construct-string-from-binary-tree){#606}

{{< tabs "606" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        def dfs(root):
            if root is None:
                return ''
            if root.left is None and root.right is None:
                return str(root.val)
            if root.right is None:
                return f'{root.val}({dfs(root.left)})'
            return f'{root.val}({dfs(root.left)})({dfs(root.right)})'

        return dfs(root)
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
    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        }
        if (root.left == null && root.right == null) {
            return root.val + "";
        }
        if (root.right == null) {
            return root.val + "(" + tree2str(root.left) + ")";
        }
        return root.val + "(" + tree2str(root.left) + ")(" + tree2str(root.right) + ")";
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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        if (!root->left && !root->right) return to_string(root->val);
        if (!root->right) return to_string(root->val) + "(" + tree2str(root->left) + ")";
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
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
func tree2str(root *TreeNode) string {
	if root == nil {
		return ""
	}
	if root.Left == nil && root.Right == nil {
		return strconv.Itoa(root.Val)
	}
	if root.Right == nil {
		return strconv.Itoa(root.Val) + "(" + tree2str(root.Left) + ")"
	}
	return strconv.Itoa(root.Val) + "(" + tree2str(root.Left) + ")(" + tree2str(root.Right) + ")"
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

function tree2str(root: TreeNode | null): string {
    if (root == null) {
        return '';
    }
    if (root.left == null && root.right == null) {
        return `${root.val}`;
    }
    return `${root.val}(${root.left ? tree2str(root.left) : ''})${
        root.right ? `(${tree2str(root.right)})` : ''
    }`;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, res: &mut String) {
        if let Some(node) = root {
            let node = node.borrow();
            res.push_str(node.val.to_string().as_str());

            if node.left.is_none() && node.right.is_none() {
                return;
            }
            res.push('(');
            if node.left.is_some() {
                Self::dfs(&node.left, res);
            }
            res.push(')');
            if node.right.is_some() {
                res.push('(');
                Self::dfs(&node.right, res);
                res.push(')');
            }
        }
    }

    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res = String::new();
        Self::dfs(&root, &mut res);
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你二叉树的根节点 <code>root</code> ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。</p>

<p>空节点使用一对空括号对 <code>"()"</code> 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0606.Construct%20String%20from%20Binary%20Tree/images/cons1-tree.jpg" style="width: 292px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4]
<strong>输出：</strong>"1(2(4))(3)"
<strong>解释：</strong>初步转化后得到 "1(2(4)())(3()())" ，但省略所有不必要的空括号对后，字符串应该是"1(2(4))(3)" 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0606.Construct%20String%20from%20Binary%20Tree/images/cons2-tree.jpg" style="width: 207px; height: 293px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,null,4]
<strong>输出：</strong>"1(2()(4))(3)"
<strong>解释：</strong>和第一个示例类似，但是无法省略第一个空括号对，否则会破坏输入与输出一一映射的关系。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目范围是 <code>[1, 10<sup>4</sup>]</code></li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>
</div>
</div>

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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        def dfs(root):
            if root is None:
                return ''
            if root.left is None and root.right is None:
                return str(root.val)
            if root.right is None:
                return f'{root.val}({dfs(root.left)})'
            return f'{root.val}({dfs(root.left)})({dfs(root.right)})'

        return dfs(root)
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
    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        }
        if (root.left == null && root.right == null) {
            return root.val + "";
        }
        if (root.right == null) {
            return root.val + "(" + tree2str(root.left) + ")";
        }
        return root.val + "(" + tree2str(root.left) + ")(" + tree2str(root.right) + ")";
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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        if (!root->left && !root->right) return to_string(root->val);
        if (!root->right) return to_string(root->val) + "(" + tree2str(root->left) + ")";
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
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
func tree2str(root *TreeNode) string {
	if root == nil {
		return ""
	}
	if root.Left == nil && root.Right == nil {
		return strconv.Itoa(root.Val)
	}
	if root.Right == nil {
		return strconv.Itoa(root.Val) + "(" + tree2str(root.Left) + ")"
	}
	return strconv.Itoa(root.Val) + "(" + tree2str(root.Left) + ")(" + tree2str(root.Right) + ")"
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

function tree2str(root: TreeNode | null): string {
    if (root == null) {
        return '';
    }
    if (root.left == null && root.right == null) {
        return `${root.val}`;
    }
    return `${root.val}(${root.left ? tree2str(root.left) : ''})${
        root.right ? `(${tree2str(root.right)})` : ''
    }`;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, res: &mut String) {
        if let Some(node) = root {
            let node = node.borrow();
            res.push_str(node.val.to_string().as_str());

            if node.left.is_none() && node.right.is_none() {
                return;
            }
            res.push('(');
            if node.left.is_some() {
                Self::dfs(&node.left, res);
            }
            res.push(')');
            if node.right.is_some() {
                res.push('(');
                Self::dfs(&node.right, res);
                res.push(')');
            }
        }
    }

    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res = String::new();
        Self::dfs(&root, &mut res);
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [607. 销售员](https://leetcode.cn/problems/sales-person){#607}

{{< tabs "607" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT s.name
FROM
    SalesPerson AS s
    LEFT JOIN Orders USING (sales_id)
    LEFT JOIN Company AS c USING (com_id)
GROUP BY sales_id
HAVING IFNULL(SUM(c.name = 'RED'), 0) = 0;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>SalesPerson</code></p>

<pre>
+-----------------+---------+
| Column Name     | Type    |
+-----------------+---------+
| sales_id        | int     |
| name            | varchar |
| salary          | int     |
| commission_rate | int     |
| hire_date       | date    |
+-----------------+---------+
sales_id 是该表的主键列(具有唯一值的列)。
该表的每一行都显示了销售人员的姓名和 ID ，以及他们的工资、佣金率和雇佣日期。
</pre>

<p>&nbsp;</p>

<p>表:&nbsp;<code>Company</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| com_id      | int     |
| name        | varchar |
| city        | varchar |
+-------------+---------+
com_id 是该表的主键列(具有唯一值的列)。
该表的每一行都表示公司的名称和 ID ，以及公司所在的城市。
</pre>

<p>&nbsp;</p>

<p>表:&nbsp;<code>Orders</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| order_id    | int  |
| order_date  | date |
| com_id      | int  |
| sales_id    | int  |
| amount      | int  |
+-------------+------+
order_id 是该表的主键列(具有唯一值的列)。
com_id 是 Company 表中 com_id 的外键（reference 列）。
sales_id 是来自销售员表 sales_id 的外键（reference 列）。
该表的每一行包含一个订单的信息。这包括公司的 ID 、销售人员的 ID 、订单日期和支付的金额。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出没有任何与名为 <strong>“RED”</strong> 的公司相关的订单的所有销售人员的姓名。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
SalesPerson 表:
+----------+------+--------+-----------------+------------+
| sales_id | name | salary | commission_rate | hire_date  |
+----------+------+--------+-----------------+------------+
| 1        | John | 100000 | 6               | 4/1/2006   |
| 2        | Amy  | 12000  | 5               | 5/1/2010   |
| 3        | Mark | 65000  | 12              | 12/25/2008 |
| 4        | Pam  | 25000  | 25              | 1/1/2005   |
| 5        | Alex | 5000   | 10              | 2/3/2007   |
+----------+------+--------+-----------------+------------+
Company 表:
+--------+--------+----------+
| com_id | name   | city     |
+--------+--------+----------+
| 1      | RED    | Boston   |
| 2      | ORANGE | New York |
| 3      | YELLOW | Boston   |
| 4      | GREEN  | Austin   |
+--------+--------+----------+
Orders 表:
+----------+------------+--------+----------+--------+
| order_id | order_date | com_id | sales_id | amount |
+----------+------------+--------+----------+--------+
| 1        | 1/1/2014   | 3      | 4        | 10000  |
| 2        | 2/1/2014   | 4      | 5        | 5000   |
| 3        | 3/1/2014   | 1      | 1        | 50000  |
| 4        | 4/1/2014   | 1      | 4        | 25000  |
+----------+------------+--------+----------+--------+
<strong>输出：</strong>
+------+
| name |
+------+
| Amy  |
| Mark |
| Alex |
+------+
<strong>解释：</strong>
根据表&nbsp;<code>orders</code>&nbsp;中的订单 '3' 和 '4' ，容易看出只有 'John' 和 'Pam' 两个销售员曾经向公司 'RED' 销售过。
所以我们需要输出表&nbsp;<code>salesperson</code>&nbsp;中所有其他人的名字。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组统计

我们可以使用左连接将 `SalesPerson` 表与 `Orders` 表连接起来，再与 `Company` 表连接起来，然后按照 `sales_id` 分组，每组统计有多少个公司的名字为 `RED` 的订单，最后筛选出没有这样的订单的销售人员的姓名。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT s.name
FROM
    SalesPerson AS s
    LEFT JOIN Orders USING (sales_id)
    LEFT JOIN Company AS c USING (com_id)
GROUP BY sales_id
HAVING IFNULL(SUM(c.name = 'RED'), 0) = 0;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [608. 树节点](https://leetcode.cn/problems/tree-node){#608}

{{< tabs "608" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Tree</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| p_id        | int  |
+-------------+------+
id 是该表中具有唯一值的列。
该表的每行包含树中节点的 id 及其父节点的 id 信息。
给定的结构总是一个有效的树。
</pre>

<p>&nbsp;</p>

<p>树中的每个节点可以是以下三种类型之一：</p>

<ul>
	<li><strong>"Leaf"</strong>：节点是叶子节点。</li>
	<li><strong>"Root"</strong>：节点是树的根节点。</li>
	<li><strong>"lnner"</strong>：节点既不是叶子节点也不是根节点。</li>
</ul>

<p>编写一个解决方案来报告树中每个节点的类型。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0608.Tree%20Node/images/tree1.jpg" style="width: 304px; height: 224px;" />
<pre>
<b>输入：</b>
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
| 2  | 1    |
| 3  | 1    |
| 4  | 2    |
| 5  | 2    |
+----+------+
<b>输出：</b>
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |
| 5  | Leaf  |
+----+-------+
<b>解释：</b>
节点 1 是根节点，因为它的父节点为空，并且它有子节点 2 和 3。
节点 2 是一个内部节点，因为它有父节点 1 和子节点 4 和 5。
节点 3、4 和 5 是叶子节点，因为它们有父节点而没有子节点。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0608.Tree%20Node/images/tree2.jpg" style="width: 64px; height: 65px;" />
<pre>
<b>输入：</b>
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
+----+------+
<b>输出：</b>
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
+----+-------+
<b>解释：</b>如果树中只有一个节点，则只需要输出其根属性。
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与 <a href="https://leetcode.cn/problems/binary-tree-nodes/">3054. 二叉树节点</a> 一致。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：条件判断 + 子查询

我们可以使用 `CASE WHEN` 条件判断语句来判断每个节点的类型，具体地：

-   如果一个节点的 `p_id` 为 `NULL`，则该节点为根节点；
-   否则，如果一个节点是另一个节点的父节点（这里我们使用子查询来判断），则该节点为内部节点；
-   否则，该节点为叶子节点。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [609. 在系统中查找重复文件](https://leetcode.cn/problems/find-duplicate-file-in-system){#609}

{{< tabs "609" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for p in paths:
            ps = p.split()
            for f in ps[1:]:
                i = f.find('(')
                name, content = f[:i], f[i + 1 : -1]
                d[content].append(ps[0] + '/' + name)
        return [v for v in d.values() if len(v) > 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> d = new HashMap<>();
        for (String p : paths) {
            String[] ps = p.split(" ");
            for (int i = 1; i < ps.length; ++i) {
                int j = ps[i].indexOf('(');
                String content = ps[i].substring(j + 1, ps[i].length() - 1);
                String name = ps[0] + '/' + ps[i].substring(0, j);
                d.computeIfAbsent(content, k -> new ArrayList<>()).add(name);
            }
        }
        List<List<String>> ans = new ArrayList<>();
        for (var e : d.values()) {
            if (e.size() > 1) {
                ans.add(e);
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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> d;
        for (auto& p : paths) {
            auto ps = split(p, ' ');
            for (int i = 1; i < ps.size(); ++i) {
                int j = ps[i].find('(');
                auto content = ps[i].substr(j + 1, ps[i].size() - j - 2);
                auto name = ps[0] + '/' + ps[i].substr(0, j);
                d[content].push_back(name);
            }
        }
        vector<vector<string>> ans;
        for (auto& [_, e] : d) {
            if (e.size() > 1) {
                ans.push_back(e);
            }
        }
        return ans;
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, c)) {
            res.push_back(t);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDuplicate(paths []string) [][]string {
	d := map[string][]string{}
	for _, p := range paths {
		ps := strings.Split(p, " ")
		for i := 1; i < len(ps); i++ {
			j := strings.IndexByte(ps[i], '(')
			content := ps[i][j+1 : len(ps[i])-1]
			name := ps[0] + "/" + ps[i][:j]
			d[content] = append(d[content], name)
		}
	}
	ans := [][]string{}
	for _, e := range d {
		if len(e) > 1 {
			ans = append(ans, e)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDuplicate(paths: string[]): string[][] {
    const d = new Map<string, string[]>();
    for (const p of paths) {
        const [root, ...fs] = p.split(' ');
        for (const f of fs) {
            const [name, content] = f.split(/\(|\)/g).filter(Boolean);
            const t = d.get(content) ?? [];
            t.push(root + '/' + name);
            d.set(content, t);
        }
    }
    return [...d.values()].filter(e => e.length > 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个目录信息列表&nbsp;<code>paths</code> ，包括目录路径，以及该目录中的所有文件及其内容，请你按路径返回文件系统中的所有重复文件。答案可按 <strong>任意顺序</strong> 返回。</p>

<p>一组重复的文件至少包括 <strong>两个 </strong>具有完全相同内容的文件。</p>

<p><strong>输入 </strong>列表中的单个目录信息字符串的格式如下：</p>

<ul>
	<li><code>"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"</code></li>
</ul>

<p>这意味着，在目录&nbsp;<code>root/d1/d2/.../dm</code>&nbsp;下，有 <code>n</code> 个文件 ( <code>f1.txt</code>,&nbsp;<code>f2.txt</code>&nbsp;...&nbsp;<code>fn.txt</code> ) 的内容分别是 ( <code>f1_content</code>,&nbsp;<code>f2_content</code>&nbsp;...&nbsp;<code>fn_content</code> ) 。注意：<code>n &gt;= 1</code> 且 <code>m &gt;= 0</code> 。如果 <code>m = 0</code> ，则表示该目录是根目录。</p>

<p><strong>输出 </strong>是由 <strong>重复文件路径组</strong> 构成的列表。其中每个组由所有具有相同内容文件的文件路径组成。文件路径是具有下列格式的字符串：</p>

<ul>
	<li><code>"directory_path/file_name.txt"</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
<strong>输出：</strong>[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
<strong>输出：</strong>[["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= paths.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= paths[i].length &lt;= 3000</code></li>
	<li><code>1 &lt;= sum(paths[i].length) &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>paths[i]</code> 由英文字母、数字、字符 <code>'/'</code>、<code>'.'</code>、<code>'('</code>、<code>')'</code> 和 <code>' '</code> 组成</li>
	<li>你可以假设在同一目录中没有任何文件或目录共享相同的名称。</li>
	<li>你可以假设每个给定的目录信息代表一个唯一的目录。目录路径和文件信息用单个空格分隔。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>假设您有一个真正的文件系统，您将如何搜索文件？广度搜索还是宽度搜索？</li>
	<li>如果文件内容非常大（GB级别），您将如何修改您的解决方案？</li>
	<li>如果每次只能读取 1 kb 的文件，您将如何修改解决方案？</li>
	<li>修改后的解决方案的时间复杂度是多少？其中最耗时的部分和消耗内存的部分是什么？如何优化？</li>
	<li>如何确保您发现的重复文件不是误报？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们创建哈希表 `d`，其中键是文件内容，值是具有相同内容的文件路径列表。

遍历 `paths`，我们处理出每个文件的路径和内容，然后将其添加到哈希表 `d` 中。

最后，我们返回哈希表 `d` 中所有具有多个文件路径的值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `paths` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for p in paths:
            ps = p.split()
            for f in ps[1:]:
                i = f.find('(')
                name, content = f[:i], f[i + 1 : -1]
                d[content].append(ps[0] + '/' + name)
        return [v for v in d.values() if len(v) > 1]
```

#### Java

```java
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> d = new HashMap<>();
        for (String p : paths) {
            String[] ps = p.split(" ");
            for (int i = 1; i < ps.length; ++i) {
                int j = ps[i].indexOf('(');
                String content = ps[i].substring(j + 1, ps[i].length() - 1);
                String name = ps[0] + '/' + ps[i].substring(0, j);
                d.computeIfAbsent(content, k -> new ArrayList<>()).add(name);
            }
        }
        List<List<String>> ans = new ArrayList<>();
        for (var e : d.values()) {
            if (e.size() > 1) {
                ans.add(e);
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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> d;
        for (auto& p : paths) {
            auto ps = split(p, ' ');
            for (int i = 1; i < ps.size(); ++i) {
                int j = ps[i].find('(');
                auto content = ps[i].substr(j + 1, ps[i].size() - j - 2);
                auto name = ps[0] + '/' + ps[i].substr(0, j);
                d[content].push_back(name);
            }
        }
        vector<vector<string>> ans;
        for (auto& [_, e] : d) {
            if (e.size() > 1) {
                ans.push_back(e);
            }
        }
        return ans;
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, c)) {
            res.push_back(t);
        }
        return res;
    }
};
```

#### Go

```go
func findDuplicate(paths []string) [][]string {
	d := map[string][]string{}
	for _, p := range paths {
		ps := strings.Split(p, " ")
		for i := 1; i < len(ps); i++ {
			j := strings.IndexByte(ps[i], '(')
			content := ps[i][j+1 : len(ps[i])-1]
			name := ps[0] + "/" + ps[i][:j]
			d[content] = append(d[content], name)
		}
	}
	ans := [][]string{}
	for _, e := range d {
		if len(e) > 1 {
			ans = append(ans, e)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findDuplicate(paths: string[]): string[][] {
    const d = new Map<string, string[]>();
    for (const p of paths) {
        const [root, ...fs] = p.split(' ');
        for (const f of fs) {
            const [name, content] = f.split(/\(|\)/g).filter(Boolean);
            const t = d.get(content) ?? [];
            t.push(root + '/' + name);
            d.set(content, t);
        }
    }
    return [...d.values()].filter(e => e.length > 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
