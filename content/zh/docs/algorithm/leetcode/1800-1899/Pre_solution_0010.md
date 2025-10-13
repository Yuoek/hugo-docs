---
title: "1890_2020年最后一次登录"
date: 2025-10-08T18:38:27+08:00
weight: 10
tags: [二分查找, 前缀和, 动态规划, 双指针, 哈希表, 字符串, 数学, 数据库, 数组, 栈, 模拟, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [1890_2020年最后一次登录](#1890)
#### [数据库](#1890)
### [1891_割绳子 🔒](#1891)
#### [数组](#1891)
#### [二分查找](#1891)
### [1892_页面推荐Ⅱ 🔒](#1892)
#### [数据库](#1892)
### [1893_检查是否区域内所有整数都被覆盖](#1893)
#### [数组](#1893)
#### [哈希表](#1893)
#### [前缀和](#1893)
### [1894_找到需要补充粉笔的学生编号](#1894)
#### [数组](#1894)
#### [二分查找](#1894)
#### [前缀和](#1894)
#### [模拟](#1894)
### [1895_最大的幻方](#1895)
#### [数组](#1895)
#### [矩阵](#1895)
#### [前缀和](#1895)
### [1896_反转表达式值的最少操作次数](#1896)
#### [栈](#1896)
#### [数学](#1896)
#### [字符串](#1896)
#### [动态规划](#1896)
### [1897_重新分配字符使所有字符串都相等](#1897)
#### [哈希表](#1897)
#### [字符串](#1897)
#### [计数](#1897)
### [1898_可移除字符的最大数目](#1898)
#### [数组](#1898)
#### [双指针](#1898)
#### [字符串](#1898)
#### [二分查找](#1898)
### [1899_合并若干三元组以形成目标三元组](#1899)
#### [贪心](#1899)
#### [数组](#1899)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1890_2020年最后一次登录
___
#### 数据库
---
### 1891_割绳子 🔒
___
#### 数组
___
#### 二分查找
---
### 1892_页面推荐Ⅱ 🔒
___
#### 数据库
---
### 1893_检查是否区域内所有整数都被覆盖
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 1894_找到需要补充粉笔的学生编号
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 模拟
---
### 1895_最大的幻方
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 1896_反转表达式值的最少操作次数
___
#### 栈
___
#### 数学
___
#### 字符串
___
#### 动态规划
---
### 1897_重新分配字符使所有字符串都相等
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1898_可移除字符的最大数目
___
#### 数组
___
#### 双指针
___
#### 字符串
___
#### 二分查找
---
### 1899_合并若干三元组以形成目标三元组
___
#### 贪心
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 字符串 |
| 数学 | 数据库 | 数组 |
| 栈 | 模拟 | 矩阵 |
| 计数 | 贪心 |  |

# [1890. 2020年最后一次登录](https://leetcode.cn/problems/the-latest-login-in-2020){#1890}

{{< tabs "1890" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = 2020
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Logins</code></p>

<pre>
+----------------+----------+
| 列名           | 类型      |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
(user_id, time_stamp) 是这个表的主键(具有唯一值的列的组合)。
每一行包含的信息是user_id 这个用户的登录时间。
</pre>

<p>&nbsp;</p>

<p>编写解决方案以获取在 <code>2020</code> 年登录过的所有用户的本年度 <strong>最后一次 </strong>登录时间。结果集 <strong>不</strong> 包含 <code>2020</code> 年没有登录过的用户。</p>

<p>返回的结果集可以按 <strong>任意顺序 </strong>排列。</p>

<p>返回结果格式如下例。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Logins 表:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 6       | 2020-06-30 15:06:07 |
| 6       | 2021-04-21 14:06:06 |
| 6       | 2019-03-07 00:18:15 |
| 8       | 2020-02-01 05:10:53 |
| 8       | 2020-12-30 00:46:50 |
| 2       | 2020-01-16 02:49:50 |
| 2       | 2019-08-25 07:59:08 |
| 14      | 2019-07-14 09:00:00 |
| 14      | 2021-01-06 11:59:59 |
+---------+---------------------+
<strong>输出：</strong>
+---------+---------------------+
| user_id | last_stamp          |
+---------+---------------------+
| 6       | 2020-06-30 15:06:07 |
| 8       | 2020-12-30 00:46:50 |
| 2       | 2020-01-16 02:49:50 |
+---------+---------------------+
<strong>解释：</strong>
6号用户登录了3次，但是在2020年仅有一次，所以结果集应包含此次登录。
8号用户在2020年登录了2次，一次在2月，一次在12月，所以，结果集应该包含12月的这次登录。
2号用户登录了2次，但是在2020年仅有一次，所以结果集应包含此次登录。
14号用户在2020年没有登录，所以结果集不应包含。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求最大值

我们可以先筛选出 2020 年的登录记录，并且按照 `user_id` 分组，然后利用 `max` 函数求出每个用户的最大登录时间。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = 2020
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1891. 割绳子 🔒](https://leetcode.cn/problems/cutting-ribbons){#1891}

{{< tabs "1891" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        left, right = 0, max(ribbons)
        while left < right:
            mid = (left + right + 1) >> 1
            cnt = sum(x // mid for x in ribbons)
            if cnt >= k:
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxLength(int[] ribbons, int k) {
        int left = 0, right = 0;
        for (int x : ribbons) {
            right = Math.max(right, x);
        }
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            int cnt = 0;
            for (int x : ribbons) {
                cnt += x / mid;
            }
            if (cnt >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 0, right = *max_element(ribbons.begin(), ribbons.end());
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int cnt = 0;
            for (int ribbon : ribbons) {
                cnt += ribbon / mid;
            }
            if (cnt >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxLength(ribbons []int, k int) int {
	left, right := 0, slices.Max(ribbons)
	for left < right {
		mid := (left + right + 1) >> 1
		cnt := 0
		for _, x := range ribbons {
			cnt += x / mid
		}
		if cnt >= k {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxLength(ribbons: number[], k: number): number {
    let left = 0;
    let right = Math.max(...ribbons);
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        let cnt = 0;
        for (const x of ribbons) {
            cnt += Math.floor(x / mid);
        }
        if (cnt >= k) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_length(ribbons: Vec<i32>, k: i32) -> i32 {
        let mut left = 0i32;
        let mut right = *ribbons.iter().max().unwrap();
        while left < right {
            let mid = (left + right + 1) / 2;
            let mut cnt = 0i32;
            for &entry in ribbons.iter() {
                cnt += entry / mid;
                if cnt >= k {
                    break;
                }
            }
            if cnt >= k {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} ribbons
 * @param {number} k
 * @return {number}
 */
var maxLength = function (ribbons, k) {
    let left = 0;
    let right = Math.max(...ribbons);
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        let cnt = 0;
        for (const x of ribbons) {
            cnt += Math.floor(x / mid);
        }
        if (cnt >= k) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组&nbsp;<code>ribbons</code>&nbsp;和一个整数 <code>k</code>，数组每项&nbsp;<code>ribbons[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;条绳子的长度。对于每条绳子，你可以将任意切割成一系列长度为&nbsp;<strong>正整数&nbsp;</strong>的部分，或者选择不进行切割。</p>

<p>例如，如果给你一条长度为 <code>4</code> 的绳子，你可以：</p>

<ul>
	<li>保持绳子的长度为 <code>4</code> 不变；</li>
	<li>切割成一条长度为 <code>3</code> 和一条长度为 <code>1</code> 的绳子；</li>
	<li>切割成两条长度为 <code>2</code>&nbsp;的绳子；</li>
	<li>切割成一条长度为 <code>2</code>&nbsp;和两条长度为 <code>1</code> 的绳子；</li>
	<li>切割成四条长度为 <code>1</code>&nbsp;的绳子。</li>
</ul>

<p>你的任务是找出最大 <code>x</code> 值，要求满足可以裁切出至少&nbsp;<code>k</code> 条长度均为 <code>x</code> 的绳子。你可以丢弃裁切后剩余的任意长度的绳子。如果不可能切割出&nbsp;<code>k</code> 条相同长度的绳子，返回 0。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> ribbons = [9,7,5], k = 3
<strong>输出:</strong> 5
<strong>解释:</strong>
- 把第一条绳子切成两部分，一条长度为 5，一条长度为 4；
- 把第二条绳子切成两部分，一条长度为 5，一条长度为 2；
- 第三条绳子不进行切割；
现在，你得到了 3 条长度为 5 的绳子。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> ribbons = [7,5,9], k = 4
<strong>输出:</strong> 4
<strong>解释:</strong>
- 把第一条绳子切成两部分，一条长度为 4，一条长度为 3；
- 把第二条绳子切成两部分，一条长度为 4，一条长度为 1；
- 把第二条绳子切成三部分，一条长度为 4，一条长度为 4，还有一条长度为 1；
现在，你得到了 4 条长度为 4 的绳子。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> ribbons = [5,7,9], k = 22
<strong>输出:</strong> 0
<strong>解释:</strong> 由于绳子长度需要为正整数，你无法得到 22 条长度相同的绳子。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= ribbons.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= ribbons[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们发现，如果我们能够得到长度为 $x$ 的 $k$ 根绳子，那么我们一定能够得到长度为 $x - 1$ 的 $k$ 根绳子，这存在着单调性。因此，我们可以使用二分查找的方法，找到最大的长度 $x$，使得我们能够得到长度为 $x$ 的 $k$ 根绳子。

我们定义二分查找的左边界 $left=0$, $right=\max(ribbons)$，中间值 $mid=(left+right+1)/2$，然后计算当前长度为 $mid$ 的绳子能够得到的数量 $cnt$，如果 $cnt \geq k$，说明我们能够得到长度为 $mid$ 的 $k$ 根绳子，那么我们将 $left$ 更新为 $mid$，否则我们将 $right$ 更新为 $mid-1$。

最后，我们返回 $left$ 即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别为绳子的数量和绳子的最大长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        left, right = 0, max(ribbons)
        while left < right:
            mid = (left + right + 1) >> 1
            cnt = sum(x // mid for x in ribbons)
            if cnt >= k:
                left = mid
            else:
                right = mid - 1
        return left
```

#### Java

```java
class Solution {
    public int maxLength(int[] ribbons, int k) {
        int left = 0, right = 0;
        for (int x : ribbons) {
            right = Math.max(right, x);
        }
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            int cnt = 0;
            for (int x : ribbons) {
                cnt += x / mid;
            }
            if (cnt >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 0, right = *max_element(ribbons.begin(), ribbons.end());
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            int cnt = 0;
            for (int ribbon : ribbons) {
                cnt += ribbon / mid;
            }
            if (cnt >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func maxLength(ribbons []int, k int) int {
	left, right := 0, slices.Max(ribbons)
	for left < right {
		mid := (left + right + 1) >> 1
		cnt := 0
		for _, x := range ribbons {
			cnt += x / mid
		}
		if cnt >= k {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```

#### TypeScript

```ts
function maxLength(ribbons: number[], k: number): number {
    let left = 0;
    let right = Math.max(...ribbons);
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        let cnt = 0;
        for (const x of ribbons) {
            cnt += Math.floor(x / mid);
        }
        if (cnt >= k) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_length(ribbons: Vec<i32>, k: i32) -> i32 {
        let mut left = 0i32;
        let mut right = *ribbons.iter().max().unwrap();
        while left < right {
            let mid = (left + right + 1) / 2;
            let mut cnt = 0i32;
            for &entry in ribbons.iter() {
                cnt += entry / mid;
                if cnt >= k {
                    break;
                }
            }
            if cnt >= k {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} ribbons
 * @param {number} k
 * @return {number}
 */
var maxLength = function (ribbons, k) {
    let left = 0;
    let right = Math.max(...ribbons);
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        let cnt = 0;
        for (const x of ribbons) {
            cnt += Math.floor(x / mid);
        }
        if (cnt >= k) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1892. 页面推荐Ⅱ 🔒](https://leetcode.cn/problems/page-recommendations-ii){#1892}

{{< tabs "1892" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT * FROM Friendship
        UNION
        SELECT user2_id, user1_id FROM Friendship
    )
SELECT user1_id AS user_id, page_id, COUNT(1) AS friends_likes
FROM
    S AS s
    LEFT JOIN Likes AS l ON s.user2_id = l.user_id
WHERE
    NOT EXISTS (
        SELECT 1
        FROM Likes AS l2
        WHERE user1_id = l2.user_id AND l.page_id = l2.page_id
    )
GROUP BY user1_id, page_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Friendship</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user1_id      | int     |
| user2_id      | int     |
+---------------+---------+
(user1_id,user2_id) 是 Friendship 表的主键(具有唯一值的列的组合)。
该表的每一行表示用户user1_id和user2_id是好友。
</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Likes</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| page_id     | int     |
+-------------+---------+
(user_id,page_id) 是 Likes 表的主键(具有唯一值的列)。
该表的每一行表示user_id喜欢page_id。
</pre>

<p>&nbsp;</p>

<p>您正在为一个社交媒体网站实施一个页面推荐系统。如果页面被<code>user_id</code>的&nbsp;<strong>至少一个朋友喜欢&nbsp;</strong>，而&nbsp;<strong>不被</strong><code>user_id</code><strong>喜欢&nbsp;</strong>，你的系统将&nbsp;<strong>推荐&nbsp;</strong>一个页面到<code>user_id</code>。</p>

<p>编写一个解决方案来查找针对每个用户的所有可能的&nbsp;<strong>页面建议&nbsp;</strong>。每个建议应该在结果表中显示为一行，包含以下列:</p>

<ul>
	<li><code>user_id</code>: 系统向其提出建议的用户的ID。</li>
	<li><code>page_id</code>: 推荐为&nbsp;<code>user_id</code>&nbsp;的页面ID。.</li>
	<li><code>friends_likes</code>:&nbsp;&nbsp;<code>user_id</code>&nbsp;对应&nbsp;<code>page_id</code>&nbsp;的好友数。</li>
</ul>

<p>以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>返回结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Friendship 表:
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
| 1        | 3        |
| 1        | 4        |
| 2        | 3        |
| 2        | 4        |
| 2        | 5        |
| 6        | 1        |
+----------+----------+
Likes 表:
+---------+---------+
| user_id | page_id |
+---------+---------+
| 1       | 88      |
| 2       | 23      |
| 3       | 24      |
| 4       | 56      |
| 5       | 11      |
| 6       | 33      |
| 2       | 77      |
| 3       | 77      |
| 6       | 88      |
+---------+---------+
<strong>输出：</strong>
+---------+---------+---------------+
| user_id | page_id | friends_likes |
+---------+---------+---------------+
| 1       | 77      | 2             |
| 1       | 23      | 1             |
| 1       | 24      | 1             |
| 1       | 56      | 1             |
| 1       | 33      | 1             |
| 2       | 24      | 1             |
| 2       | 56      | 1             |
| 2       | 11      | 1             |
| 2       | 88      | 1             |
| 3       | 88      | 1             |
| 3       | 23      | 1             |
| 4       | 88      | 1             |
| 4       | 77      | 1             |
| 4       | 23      | 1             |
| 5       | 77      | 1             |
| 5       | 23      | 1             |
+---------+---------+---------------+
<strong>解释：</strong>
以用户1为例:
—用户1是用户2、3、4、6的好友。
-推荐页面有23(用户2喜欢)，24(用户3喜欢)，56(用户3喜欢)，33(用户6喜欢)，77(用户2和用户3喜欢)。
-请注意，第88页不推荐，因为用户1已经喜欢它。

另一个例子是用户6:
—用户6是用户1的好友。
-用户1只喜欢了88页，但用户6已经喜欢了。因此，用户6没有推荐。

您可以使用类似的过程为用户2、3、4和5推荐页面。</pre>

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
        SELECT * FROM Friendship
        UNION
        SELECT user2_id, user1_id FROM Friendship
    )
SELECT user1_id AS user_id, page_id, COUNT(1) AS friends_likes
FROM
    S AS s
    LEFT JOIN Likes AS l ON s.user2_id = l.user_id
WHERE
    NOT EXISTS (
        SELECT 1
        FROM Likes AS l2
        WHERE user1_id = l2.user_id AND l.page_id = l2.page_id
    )
GROUP BY user1_id, page_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1893. 检查是否区域内所有整数都被覆盖](https://leetcode.cn/problems/check-if-all-the-integers-in-a-range-are-covered){#1893}

{{< tabs "1893" >}}

{{% tab "python" %}}
```python
class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        diff = [0] * 52
        for l, r in ranges:
            diff[l] += 1
            diff[r + 1] -= 1
        s = 0
        for i, x in enumerate(diff):
            s += x
            if s <= 0 and left <= i <= right:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        int[] diff = new int[52];
        for (int[] range : ranges) {
            int l = range[0], r = range[1];
            ++diff[l];
            --diff[r + 1];
        }
        int s = 0;
        for (int i = 0; i < diff.length; ++i) {
            s += diff[i];
            if (s <= 0 && left <= i && i <= right) {
                return false;
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52);
        for (auto& range : ranges) {
            int l = range[0], r = range[1];
            ++diff[l];
            --diff[r + 1];
        }
        int s = 0;
        for (int i = 0; i < diff.size(); ++i) {
            s += diff[i];
            if (s <= 0 && left <= i && i <= right) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isCovered(ranges [][]int, left int, right int) bool {
	diff := [52]int{}
	for _, e := range ranges {
		l, r := e[0], e[1]
		diff[l]++
		diff[r+1]--
	}
	s := 0
	for i, x := range diff {
		s += x
		if s <= 0 && left <= i && i <= right {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isCovered(ranges: number[][], left: number, right: number): boolean {
    const diff: number[] = Array(52).fill(0);
    for (const [l, r] of ranges) {
        ++diff[l];
        --diff[r + 1];
    }
    let s = 0;
    for (let i = 0; i < diff.length; ++i) {
        s += diff[i];
        if (s <= 0 && left <= i && i <= right) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} ranges
 * @param {number} left
 * @param {number} right
 * @return {boolean}
 */
var isCovered = function (ranges, left, right) {
    const diff = Array(52).fill(0);
    for (const [l, r] of ranges) {
        ++diff[l];
        --diff[r + 1];
    }
    let s = 0;
    for (let i = 0; i < diff.length; ++i) {
        s += diff[i];
        if (s <= 0 && left <= i && i <= right) {
            return false;
        }
    }
    return true;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>ranges</code> 和两个整数 <code>left</code> 和 <code>right</code> 。每个 <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示一个从 <code>start<sub>i</sub></code> 到 <code>end<sub>i</sub></code> 的 <strong>闭区间</strong> 。</p>

<p>如果闭区间 <code>[left, right]</code> 内每个整数都被 <code>ranges</code> 中 <strong>至少一个</strong> 区间覆盖，那么请你返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>已知区间 <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> ，如果整数 <code>x</code> 满足 <code>start<sub>i</sub> <= x <= end<sub>i</sub></code> ，那么我们称整数<code>x</code> 被覆盖了。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
<b>输出：</b>true
<b>解释：</b>2 到 5 的每个整数都被覆盖了：
- 2 被第一个区间覆盖。
- 3 和 4 被第二个区间覆盖。
- 5 被第三个区间覆盖。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>ranges = [[1,10],[10,20]], left = 21, right = 21
<b>输出：</b>false
<b>解释：</b>21 没有被任何一个区间覆盖。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= ranges.length <= 50</code></li>
	<li><code>1 <= start<sub>i</sub> <= end<sub>i</sub> <= 50</code></li>
	<li><code>1 <= left <= right <= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们可以使用差分数组的思想，创建一个长度为 $52$ 的差分数组 $\textit{diff}$。

接下来，我们遍历数组 $\textit{ranges}$，对于每个区间 $[l, r]$，我们令 $\textit{diff}[l]$ 自增 $1$，而 $\textit{diff}[r + 1]$ 自减 $1$。

接着，我们遍历差分数组 $\textit{diff}$，维护一个前缀和 $s$，对于每个位置 $i$，我们令 $s$ 自增 $\textit{diff}[i]$，如果 $s \le 0$ 且 $left \le i \le right$，则说明区间 $[left, right]$ 中有一个整数 $i$ 没有被覆盖，返回 $\textit{false}$。

如果遍历完差分数组 $\textit{diff}$ 后都没有返回 $\textit{false}$，则说明区间 $[left, right]$ 中的每个整数都被 $\textit{ranges}$ 中至少一个区间覆盖，返回 $\textit{true}$。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $\textit{ranges}$ 的长度，而 $M$ 是区间的最大值，本题中 $M \le 50$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        diff = [0] * 52
        for l, r in ranges:
            diff[l] += 1
            diff[r + 1] -= 1
        s = 0
        for i, x in enumerate(diff):
            s += x
            if s <= 0 and left <= i <= right:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        int[] diff = new int[52];
        for (int[] range : ranges) {
            int l = range[0], r = range[1];
            ++diff[l];
            --diff[r + 1];
        }
        int s = 0;
        for (int i = 0; i < diff.length; ++i) {
            s += diff[i];
            if (s <= 0 && left <= i && i <= right) {
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52);
        for (auto& range : ranges) {
            int l = range[0], r = range[1];
            ++diff[l];
            --diff[r + 1];
        }
        int s = 0;
        for (int i = 0; i < diff.size(); ++i) {
            s += diff[i];
            if (s <= 0 && left <= i && i <= right) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isCovered(ranges [][]int, left int, right int) bool {
	diff := [52]int{}
	for _, e := range ranges {
		l, r := e[0], e[1]
		diff[l]++
		diff[r+1]--
	}
	s := 0
	for i, x := range diff {
		s += x
		if s <= 0 && left <= i && i <= right {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isCovered(ranges: number[][], left: number, right: number): boolean {
    const diff: number[] = Array(52).fill(0);
    for (const [l, r] of ranges) {
        ++diff[l];
        --diff[r + 1];
    }
    let s = 0;
    for (let i = 0; i < diff.length; ++i) {
        s += diff[i];
        if (s <= 0 && left <= i && i <= right) {
            return false;
        }
    }
    return true;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} ranges
 * @param {number} left
 * @param {number} right
 * @return {boolean}
 */
var isCovered = function (ranges, left, right) {
    const diff = Array(52).fill(0);
    for (const [l, r] of ranges) {
        ++diff[l];
        --diff[r + 1];
    }
    let s = 0;
    for (let i = 0; i < diff.length; ++i) {
        s += diff[i];
        if (s <= 0 && left <= i && i <= right) {
            return false;
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1894. 找到需要补充粉笔的学生编号](https://leetcode.cn/problems/find-the-student-that-will-replace-the-chalk){#1894}

{{< tabs "1894" >}}

{{% tab "python" %}}
```python
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        s = sum(chalk)
        k %= s
        for i, x in enumerate(chalk):
            if k < x:
                return i
            k -= x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long s = 0;
        for (int x : chalk) {
            s += x;
        }
        k %= s;
        for (int i = 0;; ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= s;
        for (int i = 0;; ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func chalkReplacer(chalk []int, k int) int {
	s := 0
	for _, x := range chalk {
		s += x
	}
	k %= s
	for i := 0; ; i++ {
		if k < chalk[i] {
			return i
		}
		k -= chalk[i]
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function chalkReplacer(chalk: number[], k: number): number {
    const s = chalk.reduce((acc, cur) => acc + cur, 0);
    k %= s;
    for (let i = 0; ; ++i) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn chalk_replacer(chalk: Vec<i32>, k: i32) -> i32 {
        let mut s: i64 = chalk.iter().map(|&x| x as i64).sum();
        let mut k = (k as i64) % s;
        for (i, &x) in chalk.iter().enumerate() {
            if k < (x as i64) {
                return i as i32;
            }
            k -= x as i64;
        }
        0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个班级里有&nbsp;<code>n</code>&nbsp;个学生，编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。每个学生会依次回答问题，编号为 <code>0</code>&nbsp;的学生先回答，然后是编号为 <code>1</code>&nbsp;的学生，以此类推，直到编号为 <code>n - 1</code>&nbsp;的学生，然后老师会重复这个过程，重新从编号为 <code>0</code>&nbsp;的学生开始回答问题。</p>

<p>给你一个长度为 <code>n</code>&nbsp;且下标从 <code>0</code>&nbsp;开始的整数数组&nbsp;<code>chalk</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。一开始粉笔盒里总共有&nbsp;<code>k</code>&nbsp;支粉笔。当编号为&nbsp;<code>i</code>&nbsp;的学生回答问题时，他会消耗 <code>chalk[i]</code>&nbsp;支粉笔。如果剩余粉笔数量 <strong>严格小于</strong>&nbsp;<code>chalk[i]</code>&nbsp;，那么学生 <code>i</code>&nbsp;需要 <strong>补充</strong>&nbsp;粉笔。</p>

<p>请你返回需要 <strong>补充</strong>&nbsp;粉笔的学生 <strong>编号</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>chalk = [5,1,5], k = 22
<b>输出：</b>0
<strong>解释：</strong>学生消耗粉笔情况如下：
- 编号为 0 的学生使用 5 支粉笔，然后 k = 17 。
- 编号为 1 的学生使用 1 支粉笔，然后 k = 16 。
- 编号为 2 的学生使用 5 支粉笔，然后 k = 11 。
- 编号为 0 的学生使用 5 支粉笔，然后 k = 6 。
- 编号为 1 的学生使用 1 支粉笔，然后 k = 5 。
- 编号为 2 的学生使用 5 支粉笔，然后 k = 0 。
编号为 0 的学生没有足够的粉笔，所以他需要补充粉笔。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>chalk = [3,4,1,2], k = 25
<b>输出：</b>1
<b>解释：</b>学生消耗粉笔情况如下：
- 编号为 0 的学生使用 3 支粉笔，然后 k = 22 。
- 编号为 1 的学生使用 4 支粉笔，然后 k = 18 。
- 编号为 2 的学生使用 1 支粉笔，然后 k = 17 。
- 编号为 3 的学生使用 2 支粉笔，然后 k = 15 。
- 编号为 0 的学生使用 3 支粉笔，然后 k = 12 。
- 编号为 1 的学生使用 4 支粉笔，然后 k = 8 。
- 编号为 2 的学生使用 1 支粉笔，然后 k = 7 。
- 编号为 3 的学生使用 2 支粉笔，然后 k = 5 。
- 编号为 0 的学生使用 3 支粉笔，然后 k = 2 。
编号为 1 的学生没有足够的粉笔，所以他需要补充粉笔。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>chalk.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= chalk[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求和取余 + 模拟

由于学生的回答是一轮一轮循环进行的，因此我们可以将所有学生需要消耗的粉笔数加起来，得到一个总数 $s$。然后我们对 $k$ 取 $s$ 的余数，即可知道最后一轮结束后剩余的粉笔数。

接下来，我们只需要模拟最后一轮即可。初始时，剩余的粉笔数为 $k$，编号为 $0$ 的学生开始回答问题。当剩余的粉笔数小于当前学生需要的粉笔数时，当前学生需要补充粉笔，我们直接返回当前学生的编号 $i$ 即可。否则，我们将剩余的粉笔数减去当前学生需要的粉笔数，并将当前学生的编号 $i$ 加一，进行下一次模拟。

时间复杂度 $O(n)$，其中 $n$ 是学生的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        s = sum(chalk)
        k %= s
        for i, x in enumerate(chalk):
            if k < x:
                return i
            k -= x
```

#### Java

```java
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long s = 0;
        for (int x : chalk) {
            s += x;
        }
        k %= s;
        for (int i = 0;; ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= s;
        for (int i = 0;; ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
    }
};
```

#### Go

```go
func chalkReplacer(chalk []int, k int) int {
	s := 0
	for _, x := range chalk {
		s += x
	}
	k %= s
	for i := 0; ; i++ {
		if k < chalk[i] {
			return i
		}
		k -= chalk[i]
	}
}
```

#### TypeScript

```ts
function chalkReplacer(chalk: number[], k: number): number {
    const s = chalk.reduce((acc, cur) => acc + cur, 0);
    k %= s;
    for (let i = 0; ; ++i) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn chalk_replacer(chalk: Vec<i32>, k: i32) -> i32 {
        let mut s: i64 = chalk.iter().map(|&x| x as i64).sum();
        let mut k = (k as i64) % s;
        for (i, &x) in chalk.iter().enumerate() {
            if k < (x as i64) {
                return i as i32;
            }
            k -= x as i64;
        }
        0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1895. 最大的幻方](https://leetcode.cn/problems/largest-magic-square){#1895}

{{< tabs "1895" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        rowsum = [[0] * (n + 1) for _ in range(m + 1)]
        colsum = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                rowsum[i][j] = rowsum[i][j - 1] + grid[i - 1][j - 1]
                colsum[i][j] = colsum[i - 1][j] + grid[i - 1][j - 1]

        def check(x1, y1, x2, y2):
            val = rowsum[x1 + 1][y2 + 1] - rowsum[x1 + 1][y1]
            for i in range(x1 + 1, x2 + 1):
                if rowsum[i + 1][y2 + 1] - rowsum[i + 1][y1] != val:
                    return False
            for j in range(y1, y2 + 1):
                if colsum[x2 + 1][j + 1] - colsum[x1][j + 1] != val:
                    return False
            s, i, j = 0, x1, y1
            while i <= x2:
                s += grid[i][j]
                i += 1
                j += 1
            if s != val:
                return False
            s, i, j = 0, x1, y2
            while i <= x2:
                s += grid[i][j]
                i += 1
                j -= 1
            if s != val:
                return False
            return True

        for k in range(min(m, n), 1, -1):
            i = 0
            while i + k - 1 < m:
                j = 0
                while j + k - 1 < n:
                    i2, j2 = i + k - 1, j + k - 1
                    if check(i, j, i2, j2):
                        return k
                    j += 1
                i += 1
        return 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] rowsum;
    private int[][] colsum;

    public int largestMagicSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        rowsum = new int[m + 1][n + 1];
        colsum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i - 1][j - 1];
                colsum[i][j] = colsum[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        for (int k = Math.min(m, n); k > 1; --k) {
            for (int i = 0; i + k - 1 < m; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    int i2 = i + k - 1, j2 = j + k - 1;
                    if (check(grid, i, j, i2, j2)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }

    private boolean check(int[][] grid, int x1, int y1, int x2, int y2) {
        int val = rowsum[x1 + 1][y2 + 1] - rowsum[x1 + 1][y1];
        for (int i = x1 + 1; i <= x2; ++i) {
            if (rowsum[i + 1][y2 + 1] - rowsum[i + 1][y1] != val) {
                return false;
            }
        }
        for (int j = y1; j <= y2; ++j) {
            if (colsum[x2 + 1][j + 1] - colsum[x1][j + 1] != val) {
                return false;
            }
        }
        int s = 0;
        for (int i = x1, j = y1; i <= x2; ++i, ++j) {
            s += grid[i][j];
        }
        if (s != val) {
            return false;
        }
        s = 0;
        for (int i = x1, j = y2; i <= x2; ++i, --j) {
            s += grid[i][j];
        }
        if (s != val) {
            return false;
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
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.size();
        vector<vector<int>> rowsum(m + 1, vector<int>(n + 1));
        vector<vector<int>> colsum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i - 1][j - 1];
                colsum[i][j] = colsum[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i + k - 1 < m; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    int i2 = i + k - 1, j2 = j + k - 1;
                    if (check(grid, rowsum, colsum, i, j, i2, j2))
                        return k;
                }
            }
        }
        return 1;
    }

    bool check(vector<vector<int>>& grid, vector<vector<int>>& rowsum, vector<vector<int>>& colsum, int x1, int y1, int x2, int y2) {
        int val = rowsum[x1 + 1][y2 + 1] - rowsum[x1 + 1][y1];
        for (int i = x1 + 1; i <= x2; ++i)
            if (rowsum[i + 1][y2 + 1] - rowsum[i + 1][y1] != val)
                return false;
        for (int j = y1; j <= y2; ++j)
            if (colsum[x2 + 1][j + 1] - colsum[x1][j + 1] != val)
                return false;
        int s = 0;
        for (int i = x1, j = y1; i <= x2; ++i, ++j)
            s += grid[i][j];
        if (s != val)
            return false;
        s = 0;
        for (int i = x1, j = y2; i <= x2; ++i, --j)
            s += grid[i][j];
        if (s != val)
            return false;
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestMagicSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	rowsum := make([][]int, m+1)
	colsum := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		rowsum[i] = make([]int, n+1)
		colsum[i] = make([]int, n+1)
	}
	for i := 1; i < m+1; i++ {
		for j := 1; j < n+1; j++ {
			rowsum[i][j] = rowsum[i][j-1] + grid[i-1][j-1]
			colsum[i][j] = colsum[i-1][j] + grid[i-1][j-1]
		}
	}
	for k := min(m, n); k > 1; k-- {
		for i := 0; i+k-1 < m; i++ {
			for j := 0; j+k-1 < n; j++ {
				i2, j2 := i+k-1, j+k-1
				if check(grid, rowsum, colsum, i, j, i2, j2) {
					return k
				}
			}
		}
	}
	return 1
}

func check(grid, rowsum, colsum [][]int, x1, y1, x2, y2 int) bool {
	val := rowsum[x1+1][y2+1] - rowsum[x1+1][y1]
	for i := x1 + 1; i < x2+1; i++ {
		if rowsum[i+1][y2+1]-rowsum[i+1][y1] != val {
			return false
		}
	}
	for j := y1; j < y2+1; j++ {
		if colsum[x2+1][j+1]-colsum[x1][j+1] != val {
			return false
		}
	}
	s := 0
	for i, j := x1, y1; i <= x2; i, j = i+1, j+1 {
		s += grid[i][j]
	}
	if s != val {
		return false
	}
	s = 0
	for i, j := x1, y2; i <= x2; i, j = i+1, j-1 {
		s += grid[i][j]
	}
	if s != val {
		return false
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestMagicSquare(grid: number[][]): number {
    let m = grid.length,
        n = grid[0].length;
    // 前缀和
    let rowSum = Array.from({ length: m + 1 }, (v, i) => new Array(n + 1).fill(0)),
        colSum = Array.from({ length: m + 1 }, v => new Array(n + 1).fill(0));
    for (let i = 0; i < m; i++) {
        rowSum[i + 1][1] = grid[i][0];
        for (let j = 1; j < n; j++) {
            rowSum[i + 1][j + 1] = rowSum[i + 1][j] + grid[i][j];
        }
    }

    for (let j = 0; j < n; j++) {
        colSum[1][j + 1] = grid[0][j];
        for (let i = 1; i < m; i++) {
            colSum[i + 1][j + 1] = colSum[i][j + 1] + grid[i][j];
        }
    }
    // console.log(rowSum, colSum)
    // 寻找最大k
    for (let k = Math.min(m, n); k > 1; k--) {
        for (let i = 0; i + k - 1 < m; i++) {
            for (let j = 0; j + k - 1 < n; j++) {
                let x2 = i + k - 1,
                    y2 = j + k - 1;
                if (valid(grid, rowSum, colSum, i, j, x2, y2)) {
                    return k;
                }
            }
        }
    }
    return 1;
}

function valid(
    grid: number[][],
    rowSum: number[][],
    colSum: number[][],
    x1: number,
    y1: number,
    x2: number,
    y2: number,
): boolean {
    let diff = rowSum[x1 + 1][y2 + 1] - rowSum[x1 + 1][y1];
    // 行
    for (let i = x1 + 1; i <= x2; i++) {
        if (diff != rowSum[i + 1][y2 + 1] - rowSum[i + 1][y1]) {
            return false;
        }
    }
    // 列
    for (let j = y1; j <= y2; j++) {
        if (diff != colSum[x2 + 1][j + 1] - colSum[x1][j + 1]) {
            return false;
        }
    }
    // 主队对角线
    let mainSum = diff;
    for (let i = x1, j = y1; i <= x2; i++, j++) {
        mainSum -= grid[i][j];
    }
    if (mainSum != 0) return false;
    // 副对角线
    let subSum = diff;
    for (let i = x1, j = y2; i <= x2; i++, j--) {
        subSum -= grid[i][j];
    }
    if (subSum != 0) return false;
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个 <code>k x k</code> 的<strong> 幻方</strong> 指的是一个 <code>k x k</code> 填满整数的方格阵，且每一行、每一列以及两条对角线的和 <strong>全部</strong><strong>相等</strong> 。幻方中的整数 <strong>不需要互不相同</strong> 。显然，每个 <code>1 x 1</code> 的方格都是一个幻方。</p>

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>grid</code> ，请你返回矩阵中 <strong>最大幻方</strong> 的 <strong>尺寸</strong> （即边长 <code>k</code>）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1895.Largest%20Magic%20Square/images/magicsquare-grid.jpg" style="width: 413px; height: 335px;">
<pre><b>输入：</b>grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
<b>输出：</b>3
<b>解释：</b>最大幻方尺寸为 3 。
每一行，每一列以及两条对角线的和都等于 12 。
- 每一行的和：5+1+6 = 5+4+3 = 2+7+3 = 12
- 每一列的和：5+5+2 = 1+4+7 = 6+3+3 = 12
- 对角线的和：5+4+3 = 6+4+2 = 12
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1895.Largest%20Magic%20Square/images/magicsquare2-grid.jpg" style="width: 333px; height: 255px;">
<pre><b>输入：</b>grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
<b>输出：</b>2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
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
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        rowsum = [[0] * (n + 1) for _ in range(m + 1)]
        colsum = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                rowsum[i][j] = rowsum[i][j - 1] + grid[i - 1][j - 1]
                colsum[i][j] = colsum[i - 1][j] + grid[i - 1][j - 1]

        def check(x1, y1, x2, y2):
            val = rowsum[x1 + 1][y2 + 1] - rowsum[x1 + 1][y1]
            for i in range(x1 + 1, x2 + 1):
                if rowsum[i + 1][y2 + 1] - rowsum[i + 1][y1] != val:
                    return False
            for j in range(y1, y2 + 1):
                if colsum[x2 + 1][j + 1] - colsum[x1][j + 1] != val:
                    return False
            s, i, j = 0, x1, y1
            while i <= x2:
                s += grid[i][j]
                i += 1
                j += 1
            if s != val:
                return False
            s, i, j = 0, x1, y2
            while i <= x2:
                s += grid[i][j]
                i += 1
                j -= 1
            if s != val:
                return False
            return True

        for k in range(min(m, n), 1, -1):
            i = 0
            while i + k - 1 < m:
                j = 0
                while j + k - 1 < n:
                    i2, j2 = i + k - 1, j + k - 1
                    if check(i, j, i2, j2):
                        return k
                    j += 1
                i += 1
        return 1
```

#### Java

```java
class Solution {
    private int[][] rowsum;
    private int[][] colsum;

    public int largestMagicSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        rowsum = new int[m + 1][n + 1];
        colsum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i - 1][j - 1];
                colsum[i][j] = colsum[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        for (int k = Math.min(m, n); k > 1; --k) {
            for (int i = 0; i + k - 1 < m; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    int i2 = i + k - 1, j2 = j + k - 1;
                    if (check(grid, i, j, i2, j2)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }

    private boolean check(int[][] grid, int x1, int y1, int x2, int y2) {
        int val = rowsum[x1 + 1][y2 + 1] - rowsum[x1 + 1][y1];
        for (int i = x1 + 1; i <= x2; ++i) {
            if (rowsum[i + 1][y2 + 1] - rowsum[i + 1][y1] != val) {
                return false;
            }
        }
        for (int j = y1; j <= y2; ++j) {
            if (colsum[x2 + 1][j + 1] - colsum[x1][j + 1] != val) {
                return false;
            }
        }
        int s = 0;
        for (int i = x1, j = y1; i <= x2; ++i, ++j) {
            s += grid[i][j];
        }
        if (s != val) {
            return false;
        }
        s = 0;
        for (int i = x1, j = y2; i <= x2; ++i, --j) {
            s += grid[i][j];
        }
        if (s != val) {
            return false;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.size();
        vector<vector<int>> rowsum(m + 1, vector<int>(n + 1));
        vector<vector<int>> colsum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i - 1][j - 1];
                colsum[i][j] = colsum[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i + k - 1 < m; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    int i2 = i + k - 1, j2 = j + k - 1;
                    if (check(grid, rowsum, colsum, i, j, i2, j2))
                        return k;
                }
            }
        }
        return 1;
    }

    bool check(vector<vector<int>>& grid, vector<vector<int>>& rowsum, vector<vector<int>>& colsum, int x1, int y1, int x2, int y2) {
        int val = rowsum[x1 + 1][y2 + 1] - rowsum[x1 + 1][y1];
        for (int i = x1 + 1; i <= x2; ++i)
            if (rowsum[i + 1][y2 + 1] - rowsum[i + 1][y1] != val)
                return false;
        for (int j = y1; j <= y2; ++j)
            if (colsum[x2 + 1][j + 1] - colsum[x1][j + 1] != val)
                return false;
        int s = 0;
        for (int i = x1, j = y1; i <= x2; ++i, ++j)
            s += grid[i][j];
        if (s != val)
            return false;
        s = 0;
        for (int i = x1, j = y2; i <= x2; ++i, --j)
            s += grid[i][j];
        if (s != val)
            return false;
        return true;
    }
};
```

#### Go

```go
func largestMagicSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	rowsum := make([][]int, m+1)
	colsum := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		rowsum[i] = make([]int, n+1)
		colsum[i] = make([]int, n+1)
	}
	for i := 1; i < m+1; i++ {
		for j := 1; j < n+1; j++ {
			rowsum[i][j] = rowsum[i][j-1] + grid[i-1][j-1]
			colsum[i][j] = colsum[i-1][j] + grid[i-1][j-1]
		}
	}
	for k := min(m, n); k > 1; k-- {
		for i := 0; i+k-1 < m; i++ {
			for j := 0; j+k-1 < n; j++ {
				i2, j2 := i+k-1, j+k-1
				if check(grid, rowsum, colsum, i, j, i2, j2) {
					return k
				}
			}
		}
	}
	return 1
}

func check(grid, rowsum, colsum [][]int, x1, y1, x2, y2 int) bool {
	val := rowsum[x1+1][y2+1] - rowsum[x1+1][y1]
	for i := x1 + 1; i < x2+1; i++ {
		if rowsum[i+1][y2+1]-rowsum[i+1][y1] != val {
			return false
		}
	}
	for j := y1; j < y2+1; j++ {
		if colsum[x2+1][j+1]-colsum[x1][j+1] != val {
			return false
		}
	}
	s := 0
	for i, j := x1, y1; i <= x2; i, j = i+1, j+1 {
		s += grid[i][j]
	}
	if s != val {
		return false
	}
	s = 0
	for i, j := x1, y2; i <= x2; i, j = i+1, j-1 {
		s += grid[i][j]
	}
	if s != val {
		return false
	}
	return true
}
```

#### TypeScript

```ts
function largestMagicSquare(grid: number[][]): number {
    let m = grid.length,
        n = grid[0].length;
    // 前缀和
    let rowSum = Array.from({ length: m + 1 }, (v, i) => new Array(n + 1).fill(0)),
        colSum = Array.from({ length: m + 1 }, v => new Array(n + 1).fill(0));
    for (let i = 0; i < m; i++) {
        rowSum[i + 1][1] = grid[i][0];
        for (let j = 1; j < n; j++) {
            rowSum[i + 1][j + 1] = rowSum[i + 1][j] + grid[i][j];
        }
    }

    for (let j = 0; j < n; j++) {
        colSum[1][j + 1] = grid[0][j];
        for (let i = 1; i < m; i++) {
            colSum[i + 1][j + 1] = colSum[i][j + 1] + grid[i][j];
        }
    }
    // console.log(rowSum, colSum)
    // 寻找最大k
    for (let k = Math.min(m, n); k > 1; k--) {
        for (let i = 0; i + k - 1 < m; i++) {
            for (let j = 0; j + k - 1 < n; j++) {
                let x2 = i + k - 1,
                    y2 = j + k - 1;
                if (valid(grid, rowSum, colSum, i, j, x2, y2)) {
                    return k;
                }
            }
        }
    }
    return 1;
}

function valid(
    grid: number[][],
    rowSum: number[][],
    colSum: number[][],
    x1: number,
    y1: number,
    x2: number,
    y2: number,
): boolean {
    let diff = rowSum[x1 + 1][y2 + 1] - rowSum[x1 + 1][y1];
    // 行
    for (let i = x1 + 1; i <= x2; i++) {
        if (diff != rowSum[i + 1][y2 + 1] - rowSum[i + 1][y1]) {
            return false;
        }
    }
    // 列
    for (let j = y1; j <= y2; j++) {
        if (diff != colSum[x2 + 1][j + 1] - colSum[x1][j + 1]) {
            return false;
        }
    }
    // 主队对角线
    let mainSum = diff;
    for (let i = x1, j = y1; i <= x2; i++, j++) {
        mainSum -= grid[i][j];
    }
    if (mainSum != 0) return false;
    // 副对角线
    let subSum = diff;
    for (let i = x1, j = y2; i <= x2; i++, j--) {
        subSum -= grid[i][j];
    }
    if (subSum != 0) return false;
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1896. 反转表达式值的最少操作次数](https://leetcode.cn/problems/minimum-cost-to-change-the-final-value-of-expression){#1896}

{{< tabs "1896" >}}

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

<p>给你一个 <strong>有效的</strong> 布尔表达式，用字符串 <code>expression</code> 表示。这个字符串包含字符 <code>'1'</code>，<code>'0'</code>，<code>'&amp;'</code>（按位 <strong>与</strong> 运算），<code>'|'</code>（按位 <strong>或</strong> 运算），<code>'('</code> 和 <code>')'</code> 。</p>

<ul>
	<li>比方说，<code>"()1|1"</code> 和 <code>"(1)&amp;()"</code> <strong>不是有效</strong> 布尔表达式。而 <code>"1"</code>， <code>"(((1))|(0))"</code> 和 <code>"1|(0&amp;(1))"</code> 是 <strong>有效</strong> 布尔表达式。</li>
</ul>

<p>你的目标是将布尔表达式的 <strong>值</strong> <strong>反转 </strong>（也就是将 <code>0</code> 变为 <code>1</code> ，或者将 <code>1</code> 变为 <code>0</code>），请你返回达成目标需要的 <strong>最少操作</strong> 次数。</p>

<ul>
	<li>比方说，如果表达式 <code>expression = "1|1|(0&amp;0)&amp;1"</code> ，它的 <strong>值</strong> 为 <code>1|1|(0&amp;0)&amp;1 = 1|1|0&amp;1 = 1|0&amp;1 = 1&amp;1 = 1</code> 。我们想要执行操作将 <strong>新的</strong> 表达式的值变成 <code>0</code> 。</li>
</ul>

<p>可执行的 <strong>操作</strong> 如下：</p>

<ul>
	<li>将一个 <code>'1'</code> 变成一个 <code>'0'</code> 。</li>
	<li>将一个 <code>'0'</code> 变成一个 <code>'1'</code> 。</li>
	<li>将一个 <code>'&amp;'</code> 变成一个 <code>'|'</code> 。</li>
	<li>将一个 <code>'|'</code> 变成一个 <code>'&amp;'</code> 。</li>
</ul>

<p><strong>注意：</strong><code>'&amp;'</code> 的 <strong>运算优先级</strong> 与 <code>'|'</code> <strong>相同</strong> 。计算表达式时，括号优先级 <strong>最高</strong> ，然后按照 <strong>从左到右</strong> 的顺序运算。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>expression = "1&amp;(0|1)"
<b>输出：</b>1
<b>解释：</b>我们可以将 "1&amp;(0<strong>|</strong>1)" 变成 "1&amp;(0<strong>&amp;</strong>1)" ，执行的操作为将一个 '|' 变成一个 '&amp;' ，执行了 1 次操作。
新表达式的值为 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>expression = "(0&amp;0)&amp;(0&amp;0&amp;0)"
<b>输出：</b>3
<b>解释：</b>我们可以将 "(0<strong>&amp;0</strong>)<strong>&amp;</strong>(0&amp;0&amp;0)" 变成 "(0<strong>|1</strong>)<strong>|</strong>(0&amp;0&amp;0)" ，执行了 3 次操作。
新表达式的值为 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>expression = "(0|(1|0&amp;1))"
<b>输出：</b>1
<b>解释：</b>我们可以将 "(0|(<strong>1</strong>|0&amp;1))" 变成 "(0|(<strong>0</strong>|0&amp;1))" ，执行了 1 次操作。
新表达式的值为 0 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 10<sup>5</sup></code></li>
	<li><code>expression</code> 只包含 <code>'1'</code>，<code>'0'</code>，<code>'&amp;'</code>，<code>'|'</code>，<code>'('</code> 和 <code>')'</code></li>
	<li>所有括号都有与之匹配的对应括号。</li>
	<li>不会有空的括号（也就是说 <code>"()"</code> 不是 <code>expression</code> 的子字符串）。</li>
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

# [1897. 重新分配字符使所有字符串都相等](https://leetcode.cn/problems/redistribute-characters-to-make-all-strings-equal){#1897}

{{< tabs "1897" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = Counter()
        for w in words:
            for c in w:
                cnt[c] += 1
        n = len(words)
        return all(v % n == 0 for v in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean makeEqual(String[] words) {
        int[] cnt = new int[26];
        for (var w : words) {
            for (char c : w.toCharArray()) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.length;
        for (int v : cnt) {
            if (v % n != 0) {
                return false;
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
    bool makeEqual(vector<string>& words) {
        int cnt[26]{};
        for (const auto& w : words) {
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % n != 0) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeEqual(words []string) bool {
	cnt := [26]int{}
	for _, w := range words {
		for _, c := range w {
			cnt[c-'a']++
		}
	}
	n := len(words)
	for _, v := range cnt {
		if v%n != 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeEqual(words: string[]): boolean {
    const cnt: Record<string, number> = {};
    for (const w of words) {
        for (const c of w) {
            cnt[c] = (cnt[c] || 0) + 1;
        }
    }
    const n = words.length;
    return Object.values(cnt).every(v => v % n === 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn make_equal(words: Vec<String>) -> bool {
        let mut cnt = std::collections::HashMap::new();

        for word in words.iter() {
            for c in word.chars() {
                *cnt.entry(c).or_insert(0) += 1;
            }
        }

        let n = words.len();
        cnt.values().all(|&v| v % n == 0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code>（下标 <strong>从 0 开始</strong> 计数）。</p>

<p>在一步操作中，需先选出两个 <strong>不同</strong> 下标 <code>i</code> 和 <code>j</code>，其中 <code>words[i]</code> 是一个非空字符串，接着将 <code>words[i]</code> 中的 <strong>任一</strong> 字符移动到 <code>words[j]</code> 中的 <strong>任一</strong> 位置上。</p>

<p>如果执行任意步操作可以使 <code>words</code> 中的每个字符串都相等，返回 <code>true</code><em> </em>；否则，返回<em> </em><code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["abc","aabc","bc"]
<strong>输出：</strong>true
<strong>解释：</strong>将 <code>words[1] 中的第一个</code> 'a' 移动到<code> words[2] 的最前面。
使 </code><code>words[1]</code> = "abc" 且 words[2] = "abc" 。
所有字符串都等于 "abc" ，所以返回 <code>true</code> 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["ab","a"]
<strong>输出：</strong>false
<strong>解释：</strong>执行操作无法使所有字符串都相等。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

根据题目描述，只要每个字符的出现次数能被字符串数组的长度整除，就可以通过移动字符使所有字符串相等。

因此，我们用哈希表或者一个长度为 $26$ 的整数数组 $\textit{cnt}$ 统计每个字符出现的次数，最后判断是否每个字符的出现次数能被字符串数组的长度整除即可。

时间复杂度 $O(L)$，空间复杂度 $O(|\Sigma|)$。其中 $L$ 为数组 $\textit{words}$ 中所有字符串的长度之和，而 $\Sigma$ 为字符集，这里为小写字母集合，所以 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = Counter()
        for w in words:
            for c in w:
                cnt[c] += 1
        n = len(words)
        return all(v % n == 0 for v in cnt.values())
```

#### Java

```java
class Solution {
    public boolean makeEqual(String[] words) {
        int[] cnt = new int[26];
        for (var w : words) {
            for (char c : w.toCharArray()) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.length;
        for (int v : cnt) {
            if (v % n != 0) {
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
    bool makeEqual(vector<string>& words) {
        int cnt[26]{};
        for (const auto& w : words) {
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % n != 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func makeEqual(words []string) bool {
	cnt := [26]int{}
	for _, w := range words {
		for _, c := range w {
			cnt[c-'a']++
		}
	}
	n := len(words)
	for _, v := range cnt {
		if v%n != 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function makeEqual(words: string[]): boolean {
    const cnt: Record<string, number> = {};
    for (const w of words) {
        for (const c of w) {
            cnt[c] = (cnt[c] || 0) + 1;
        }
    }
    const n = words.length;
    return Object.values(cnt).every(v => v % n === 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn make_equal(words: Vec<String>) -> bool {
        let mut cnt = std::collections::HashMap::new();

        for word in words.iter() {
            for c in word.chars() {
                *cnt.entry(c).or_insert(0) += 1;
            }
        }

        let n = words.len();
        cnt.values().all(|&v| v % n == 0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1898. 可移除字符的最大数目](https://leetcode.cn/problems/maximum-number-of-removable-characters){#1898}

{{< tabs "1898" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        def check(k: int) -> bool:
            rem = [False] * len(s)
            for i in removable[:k]:
                rem[i] = True
            i = j = 0
            while i < len(s) and j < len(p):
                if not rem[i] and p[j] == s[i]:
                    j += 1
                i += 1
            return j == len(p)

        l, r = 0, len(removable)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;
    private char[] p;
    private int[] removable;

    public int maximumRemovals(String s, String p, int[] removable) {
        int l = 0, r = removable.length;
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        this.removable = removable;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int k) {
        boolean[] rem = new boolean[s.length];
        for (int i = 0; i < k; ++i) {
            rem[removable[i]] = true;
        }
        int i = 0, j = 0;
        while (i < s.length && j < p.length) {
            if (!rem[i] && p[j] == s[i]) {
                ++j;
            }
            ++i;
        }
        return j == p.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int m = s.size(), n = p.size();
        int l = 0, r = removable.size();
        bool rem[m];

        auto check = [&](int k) {
            memset(rem, false, sizeof(rem));
            for (int i = 0; i < k; i++) {
                rem[removable[i]] = true;
            }
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (!rem[i] && s[i] == p[j]) {
                    ++j;
                }
                ++i;
            }
            return j == n;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumRemovals(s string, p string, removable []int) int {
	m, n := len(s), len(p)
	l, r := 0, len(removable)
	check := func(k int) bool {
		rem := make([]bool, m)
		for i := 0; i < k; i++ {
			rem[removable[i]] = true
		}
		i, j := 0, 0
		for i < m && j < n {
			if !rem[i] && s[i] == p[j] {
				j++
			}
			i++
		}
		return j == n
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumRemovals(s: string, p: string, removable: number[]): number {
    const [m, n] = [s.length, p.length];
    let [l, r] = [0, removable.length];
    const rem: boolean[] = Array(m);

    const check = (k: number): boolean => {
        rem.fill(false);
        for (let i = 0; i < k; i++) {
            rem[removable[i]] = true;
        }

        let i = 0,
            j = 0;
        while (i < m && j < n) {
            if (!rem[i] && s[i] === p[j]) {
                j++;
            }
            i++;
        }
        return j === n;
    };

    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_removals(s: String, p: String, removable: Vec<i32>) -> i32 {
        let m = s.len();
        let n = p.len();
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();
        let mut l = 0;
        let mut r = removable.len();

        let check = |k: usize| -> bool {
            let mut rem = vec![false; m];
            for i in 0..k {
                rem[removable[i] as usize] = true;
            }
            let mut i = 0;
            let mut j = 0;
            while i < m && j < n {
                if !rem[i] && s[i] == p[j] {
                    j += 1;
                }
                i += 1;
            }
            j == n
        };

        while l < r {
            let mid = (l + r + 1) / 2;
            if check(mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        l as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {string} p
 * @param {number[]} removable
 * @return {number}
 */
var maximumRemovals = function (s, p, removable) {
    const [m, n] = [s.length, p.length];
    let [l, r] = [0, removable.length];
    const rem = Array(m);

    const check = k => {
        rem.fill(false);
        for (let i = 0; i < k; i++) {
            rem[removable[i]] = true;
        }

        let i = 0,
            j = 0;
        while (i < m && j < n) {
            if (!rem[i] && s[i] === p[j]) {
                j++;
            }
            i++;
        }
        return j === n;
    };

    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
};
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun maximumRemovals(s: String, p: String, removable: IntArray): Int {
        val m = s.length
        val n = p.length
        var l = 0
        var r = removable.size

        fun check(k: Int): Boolean {
            val rem = BooleanArray(m)
            for (i in 0 until k) {
                rem[removable[i]] = true
            }
            var i = 0
            var j = 0
            while (i < m && j < n) {
                if (!rem[i] && s[i] == p[j]) {
                    j++
                }
                i++
            }
            return j == n
        }

        while (l < r) {
            val mid = (l + r + 1) / 2
            if (check(mid)) {
                l = mid
            } else {
                r = mid - 1
            }
        }

        return l
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>s</code> 和 <code>p</code> ，其中 <code>p</code> 是 <code>s</code> 的一个 <strong>子序列</strong> 。同时，给你一个元素 <strong>互不相同</strong> 且下标 <strong>从 0 开始</strong> 计数的整数数组 <code>removable</code> ，该数组是 <code>s</code> 中下标的一个子集（<code>s</code> 的下标也 <strong>从 0 开始</strong> 计数）。</p>

<p>请你找出一个整数 <code>k</code>（<code>0 <= k <= removable.length</code>），选出 <code>removable</code> 中的 <strong>前</strong> <code>k</code> 个下标，然后从 <code>s</code> 中移除这些下标对应的 <code>k</code> 个字符。整数 <code>k</code> 需满足：在执行完上述步骤后， <code>p</code> 仍然是 <code>s</code> 的一个 <strong>子序列</strong> 。更正式的解释是，对于每个 <code>0 <= i < k</code> ，先标记出位于 <code>s[removable[i]]</code> 的字符，接着移除所有标记过的字符，然后检查 <code>p</code> 是否仍然是 <code>s</code> 的一个子序列。</p>

<p>返回你可以找出的 <strong>最大</strong><em> </em><code>k</code><em> </em>，满足在移除字符后<em> </em><code>p</code><em> </em>仍然是 <code>s</code> 的一个子序列。</p>

<p>字符串的一个 <strong>子序列</strong> 是一个由原字符串生成的新字符串，生成过程中可能会移除原字符串中的一些字符（也可能不移除）但不改变剩余字符之间的相对顺序。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcacb", p = "ab", removable = [3,1,0]
<strong>输出：</strong>2
<strong>解释：</strong>在移除下标 3 和 1 对应的字符后，"a<strong>b</strong>c<strong>a</strong>cb" 变成 "accb" 。
"ab" 是 "<strong>a</strong>cc<strong>b</strong>" 的一个子序列。
如果移除下标 3、1 和 0 对应的字符后，"<strong>ab</strong>c<strong>a</strong>cb" 变成 "ccb" ，那么 "ab" 就不再是 s 的一个子序列。
因此，最大的 k 是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
<strong>输出：</strong>1
<strong>解释：</strong>在移除下标 3 对应的字符后，"abc<strong>b</strong>ddddd" 变成 "abcddddd" 。
"abcd" 是 "<strong>abcd</strong>dddd" 的一个子序列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcab", p = "abc", removable = [0,1,2,3,4]
<strong>输出：</strong>0
<strong>解释：</strong>如果移除数组 removable 的第一个下标，"abc" 就不再是 s 的一个子序列。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= p.length <= s.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= removable.length < s.length</code></li>
	<li><code>0 <= removable[i] < s.length</code></li>
	<li><code>p</code> 是 <code>s</code> 的一个 <strong>子字符串</strong></li>
	<li><code>s</code> 和 <code>p</code> 都由小写英文字母组成</li>
	<li><code>removable</code> 中的元素 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果移除 $\textit{removable}$ 前 $k$ 个下标对应的字符后，满足 $p$ 仍然是 $s$ 的一个子序列，那么移除 $k \lt k' \leq \textit{removable.length}$ 个下标对应的字符后，依然满足条件，这存在着单调性。因此，我们可以使用二分查找，找到最大的 $k$。

我们定义二分查找的左边界 $l = 0$，右边界 $r = \textit{removable.length}$，然后进行二分查找。在每次查找中，我们取中间值 $mid = \left\lfloor \frac{l + r + 1}{2} \right\rfloor$，然后检查移除 $\textit{removable}$ 的前 $mid$ 个下标对应的字符后，是否满足 $p$ 仍然是 $s$ 的一个子序列。如果满足，我们更新左边界 $l = mid$，否则更新右边界 $r = mid - 1$。

二分查找结束后，返回左边界 $l$ 即可。

时间复杂度 $O(k \times \log k)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度，而 $k$ 是 $\textit{removable}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        def check(k: int) -> bool:
            rem = [False] * len(s)
            for i in removable[:k]:
                rem[i] = True
            i = j = 0
            while i < len(s) and j < len(p):
                if not rem[i] and p[j] == s[i]:
                    j += 1
                i += 1
            return j == len(p)

        l, r = 0, len(removable)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private char[] s;
    private char[] p;
    private int[] removable;

    public int maximumRemovals(String s, String p, int[] removable) {
        int l = 0, r = removable.length;
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        this.removable = removable;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int k) {
        boolean[] rem = new boolean[s.length];
        for (int i = 0; i < k; ++i) {
            rem[removable[i]] = true;
        }
        int i = 0, j = 0;
        while (i < s.length && j < p.length) {
            if (!rem[i] && p[j] == s[i]) {
                ++j;
            }
            ++i;
        }
        return j == p.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int m = s.size(), n = p.size();
        int l = 0, r = removable.size();
        bool rem[m];

        auto check = [&](int k) {
            memset(rem, false, sizeof(rem));
            for (int i = 0; i < k; i++) {
                rem[removable[i]] = true;
            }
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (!rem[i] && s[i] == p[j]) {
                    ++j;
                }
                ++i;
            }
            return j == n;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maximumRemovals(s string, p string, removable []int) int {
	m, n := len(s), len(p)
	l, r := 0, len(removable)
	check := func(k int) bool {
		rem := make([]bool, m)
		for i := 0; i < k; i++ {
			rem[removable[i]] = true
		}
		i, j := 0, 0
		for i < m && j < n {
			if !rem[i] && s[i] == p[j] {
				j++
			}
			i++
		}
		return j == n
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function maximumRemovals(s: string, p: string, removable: number[]): number {
    const [m, n] = [s.length, p.length];
    let [l, r] = [0, removable.length];
    const rem: boolean[] = Array(m);

    const check = (k: number): boolean => {
        rem.fill(false);
        for (let i = 0; i < k; i++) {
            rem[removable[i]] = true;
        }

        let i = 0,
            j = 0;
        while (i < m && j < n) {
            if (!rem[i] && s[i] === p[j]) {
                j++;
            }
            i++;
        }
        return j === n;
    };

    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_removals(s: String, p: String, removable: Vec<i32>) -> i32 {
        let m = s.len();
        let n = p.len();
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();
        let mut l = 0;
        let mut r = removable.len();

        let check = |k: usize| -> bool {
            let mut rem = vec![false; m];
            for i in 0..k {
                rem[removable[i] as usize] = true;
            }
            let mut i = 0;
            let mut j = 0;
            while i < m && j < n {
                if !rem[i] && s[i] == p[j] {
                    j += 1;
                }
                i += 1;
            }
            j == n
        };

        while l < r {
            let mid = (l + r + 1) / 2;
            if check(mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        l as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {string} p
 * @param {number[]} removable
 * @return {number}
 */
var maximumRemovals = function (s, p, removable) {
    const [m, n] = [s.length, p.length];
    let [l, r] = [0, removable.length];
    const rem = Array(m);

    const check = k => {
        rem.fill(false);
        for (let i = 0; i < k; i++) {
            rem[removable[i]] = true;
        }

        let i = 0,
            j = 0;
        while (i < m && j < n) {
            if (!rem[i] && s[i] === p[j]) {
                j++;
            }
            i++;
        }
        return j === n;
    };

    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
};
```

#### Kotlin

```kotlin
class Solution {
    fun maximumRemovals(s: String, p: String, removable: IntArray): Int {
        val m = s.length
        val n = p.length
        var l = 0
        var r = removable.size

        fun check(k: Int): Boolean {
            val rem = BooleanArray(m)
            for (i in 0 until k) {
                rem[removable[i]] = true
            }
            var i = 0
            var j = 0
            while (i < m && j < n) {
                if (!rem[i] && s[i] == p[j]) {
                    j++
                }
                i++
            }
            return j == n
        }

        while (l < r) {
            val mid = (l + r + 1) / 2
            if (check(mid)) {
                l = mid
            } else {
                r = mid - 1
            }
        }

        return l
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1899. 合并若干三元组以形成目标三元组](https://leetcode.cn/problems/merge-triplets-to-form-target-triplet){#1899}

{{< tabs "1899" >}}

{{% tab "python" %}}
```python
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        x, y, z = target
        d = e = f = 0
        for a, b, c in triplets:
            if a <= x and b <= y and c <= z:
                d = max(d, a)
                e = max(e, b)
                f = max(f, c)
        return [d, e, f] == target
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int x = target[0], y = target[1], z = target[2];
        int d = 0, e = 0, f = 0;
        for (var t : triplets) {
            int a = t[0], b = t[1], c = t[2];
            if (a <= x && b <= y && c <= z) {
                d = Math.max(d, a);
                e = Math.max(e, b);
                f = Math.max(f, c);
            }
        }
        return d == x && e == y && f == z;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int d = 0, e = 0, f = 0;
        for (auto& t : triplets) {
            int a = t[0], b = t[1], c = t[2];
            if (a <= x && b <= y && c <= z) {
                d = max(d, a);
                e = max(e, b);
                f = max(f, c);
            }
        }
        return d == x && e == y && f == z;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mergeTriplets(triplets [][]int, target []int) bool {
	x, y, z := target[0], target[1], target[2]
	d, e, f := 0, 0, 0
	for _, t := range triplets {
		a, b, c := t[0], t[1], t[2]
		if a <= x && b <= y && c <= z {
			d = max(d, a)
			e = max(e, b)
			f = max(f, c)
		}
	}
	return d == x && e == y && f == z
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mergeTriplets(triplets: number[][], target: number[]): boolean {
    const [x, y, z] = target;
    let [d, e, f] = [0, 0, 0];
    for (const [a, b, c] of triplets) {
        if (a <= x && b <= y && c <= z) {
            d = Math.max(d, a);
            e = Math.max(e, b);
            f = Math.max(f, c);
        }
    }
    return d === x && e === y && f === z;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn merge_triplets(triplets: Vec<Vec<i32>>, target: Vec<i32>) -> bool {
        let [x, y, z]: [i32; 3] = target.try_into().unwrap();
        let (mut d, mut e, mut f) = (0, 0, 0);

        for triplet in triplets {
            if let [a, b, c] = triplet[..] {
                if a <= x && b <= y && c <= z {
                    d = d.max(a);
                    e = e.max(b);
                    f = f.max(c);
                }
            }
        }

        [d, e, f] == [x, y, z]
    }
}
```
{{% /tab %}}
{{% tab "scala" %}}
```scala
object Solution {
    def mergeTriplets(triplets: Array[Array[Int]], target: Array[Int]): Boolean = {
        val Array(x, y, z) = target
        var (d, e, f) = (0, 0, 0)

        for (Array(a, b, c) <- triplets) {
            if (a <= x && b <= y && c <= z) {
                d = d.max(a)
                e = e.max(b)
                f = f.max(c)
            }
        }

        d == x && e == y && f == z
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>三元组</strong> 是一个由三个整数组成的数组。给你一个二维整数数组 <code>triplets</code> ，其中 <code>triplets[i] = [a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>]</code> 表示第 <code>i</code> 个 <strong>三元组</strong> 。同时，给你一个整数数组 <code>target = [x, y, z]</code> ，表示你想要得到的 <strong>三元组</strong> 。</p>

<p>为了得到 <code>target</code> ，你需要对 <code>triplets</code> 执行下面的操作 <strong>任意次</strong>（可能 <strong>零</strong> 次）：</p>

<ul>
	<li>选出两个下标（下标 <strong>从 0 开始</strong> 计数）<code>i</code> 和 <code>j</code>（<code>i != j</code>），并 <strong>更新</strong> <code>triplets[j]</code> 为 <code>[max(a<sub>i</sub>, a<sub>j</sub>), max(b<sub>i</sub>, b<sub>j</sub>), max(c<sub>i</sub>, c<sub>j</sub>)]</code> 。

    <ul>
    	<li>例如，<code>triplets[i] = [2, 5, 3]</code> 且 <code>triplets[j] = [1, 7, 5]</code>，<code>triplets[j]</code> 将会更新为 <code>[max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5]</code> 。</li>
    </ul>
    </li>

</ul>

<p>如果通过以上操作我们可以使得目标 <strong>三元组</strong> <code>target</code> 成为 <code>triplets</code> 的一个 <strong>元素</strong> ，则返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
<strong>输出：</strong>true
<strong>解释：</strong>执行下述操作：
- 选择第一个和最后一个三元组 [<strong>[2,5,3]</strong>,[1,8,4],<strong>[1,7,5]</strong>] 。更新最后一个三元组为 [max(2,1), max(5,7), max(3,5)] = [2,7,5] 。triplets = [[2,5,3],[1,8,4],<strong>[2,7,5]</strong>]
目标三元组 [2,7,5] 现在是 triplets 的一个元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>triplets = [[1,3,4],[2,5,8]], target = [2,5,8]
<strong>输出：</strong>true
<strong>解释：</strong>目标三元组 [2,5,8] 已经是 triplets 的一个元素。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
<strong>输出：</strong>true
<strong>解释：</strong>执行下述操作：
- 选择第一个和第三个三元组 [<strong>[2,5,3]</strong>,[2,3,4],<strong>[1,2,5]</strong>,[5,2,3]] 。更新第三个三元组为 [max(2,1), max(5,2), max(3,5)] = [2,5,5] 。triplets = [[2,5,3],[2,3,4],<strong>[2,5,5]</strong>,[5,2,3]] 。
- 选择第三个和第四个三元组 [[2,5,3],[2,3,4],<strong>[2,5,5]</strong>,<strong>[5,2,3]</strong>] 。更新第四个三元组为 [max(2,5), max(5,2), max(5,3)] = [5,5,5] 。triplets = [[2,5,3],[2,3,4],[2,5,5],<strong>[5,5,5]</strong>] 。
目标三元组 [5,5,5] 现在是 triplets 的一个元素。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
<strong>输出：</strong>false
<strong>解释：</strong>无法得到 [3,2,5] ，因为 triplets 不含 2 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= triplets.length <= 10<sup>5</sup></code></li>
	<li><code>triplets[i].length == target.length == 3</code></li>
	<li><code>1 <= a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, x, y, z <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们记 $\textit{target} = [x, y, z]$，我们需要判断是否存在三元组 $[a, b, c]$ 使得 $a \le x, b \le y, c \le z$。

我们可以将所有的三元组分为两类：

1. 满足 $a \le x, b \le y, c \le z$ 的三元组。
2. 不满足 $a \le x, b \le y, c \le z$ 的三元组。

对于第一类三元组，我们可以将它们的 $a, b, c$ 分别取最大值，得到一个新的三元组 $[d, e, f]$。

对于第二类三元组，我们可以忽略它们，因为它们无法帮助我们得到目标三元组。

最后，我们只需要判断 $[d, e, f]$ 是否等于 $\textit{target}$ 即可。如果等于，返回 $\textit{true}$，否则返回 $\textit{false}$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{triplets}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        x, y, z = target
        d = e = f = 0
        for a, b, c in triplets:
            if a <= x and b <= y and c <= z:
                d = max(d, a)
                e = max(e, b)
                f = max(f, c)
        return [d, e, f] == target
```

#### Java

```java
class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int x = target[0], y = target[1], z = target[2];
        int d = 0, e = 0, f = 0;
        for (var t : triplets) {
            int a = t[0], b = t[1], c = t[2];
            if (a <= x && b <= y && c <= z) {
                d = Math.max(d, a);
                e = Math.max(e, b);
                f = Math.max(f, c);
            }
        }
        return d == x && e == y && f == z;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int d = 0, e = 0, f = 0;
        for (auto& t : triplets) {
            int a = t[0], b = t[1], c = t[2];
            if (a <= x && b <= y && c <= z) {
                d = max(d, a);
                e = max(e, b);
                f = max(f, c);
            }
        }
        return d == x && e == y && f == z;
    }
};
```

#### Go

```go
func mergeTriplets(triplets [][]int, target []int) bool {
	x, y, z := target[0], target[1], target[2]
	d, e, f := 0, 0, 0
	for _, t := range triplets {
		a, b, c := t[0], t[1], t[2]
		if a <= x && b <= y && c <= z {
			d = max(d, a)
			e = max(e, b)
			f = max(f, c)
		}
	}
	return d == x && e == y && f == z
}
```

#### TypeScript

```ts
function mergeTriplets(triplets: number[][], target: number[]): boolean {
    const [x, y, z] = target;
    let [d, e, f] = [0, 0, 0];
    for (const [a, b, c] of triplets) {
        if (a <= x && b <= y && c <= z) {
            d = Math.max(d, a);
            e = Math.max(e, b);
            f = Math.max(f, c);
        }
    }
    return d === x && e === y && f === z;
}
```

#### Rust

```rust
impl Solution {
    pub fn merge_triplets(triplets: Vec<Vec<i32>>, target: Vec<i32>) -> bool {
        let [x, y, z]: [i32; 3] = target.try_into().unwrap();
        let (mut d, mut e, mut f) = (0, 0, 0);

        for triplet in triplets {
            if let [a, b, c] = triplet[..] {
                if a <= x && b <= y && c <= z {
                    d = d.max(a);
                    e = e.max(b);
                    f = f.max(c);
                }
            }
        }

        [d, e, f] == [x, y, z]
    }
}
```

#### Scala

```scala
object Solution {
    def mergeTriplets(triplets: Array[Array[Int]], target: Array[Int]): Boolean = {
        val Array(x, y, z) = target
        var (d, e, f) = (0, 0, 0)

        for (Array(a, b, c) <- triplets) {
            if (a <= x && b <= y && c <= z) {
                d = d.max(a)
                e = e.max(b)
                f = f.max(c)
            }
        }

        d == x && e == y && f == z
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
