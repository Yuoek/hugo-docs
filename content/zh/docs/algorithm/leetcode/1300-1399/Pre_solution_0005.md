---
title: "1340_跳跃游戏 V"
date: 2025-10-08T18:37:12+08:00
weight: 5
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 有序集合, 滑动窗口, 状态压缩, 矩阵, 计数, 设计]
---

{{< markmap >}}
### [1340_跳跃游戏 V](#1340)
#### [数组](#1340)
#### [动态规划](#1340)
#### [排序](#1340)
### [1341_电影评分](#1341)
#### [数据库](#1341)
### [1342_将数字变成 0 的操作次数](#1342)
#### [位运算](#1342)
#### [数学](#1342)
### [1343_大小为 K 且平均值大于等于阈值的子数组数目](#1343)
#### [数组](#1343)
#### [滑动窗口](#1343)
### [1344_时钟指针的夹角](#1344)
#### [数学](#1344)
### [1345_跳跃游戏 IV](#1345)
#### [广度优先搜索](#1345)
#### [数组](#1345)
#### [哈希表](#1345)
### [1346_检查整数及其两倍数是否存在](#1346)
#### [数组](#1346)
#### [哈希表](#1346)
#### [双指针](#1346)
#### [二分查找](#1346)
#### [排序](#1346)
### [1347_制造字母异位词的最小步骤数](#1347)
#### [哈希表](#1347)
#### [字符串](#1347)
#### [计数](#1347)
### [1348_推文计数](#1348)
#### [设计](#1348)
#### [哈希表](#1348)
#### [二分查找](#1348)
#### [有序集合](#1348)
#### [排序](#1348)
### [1349_参加考试的最大学生数](#1349)
#### [位运算](#1349)
#### [数组](#1349)
#### [动态规划](#1349)
#### [状态压缩](#1349)
#### [矩阵](#1349)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1340_跳跃游戏 V
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 1341_电影评分
___
#### 数据库
---
### 1342_将数字变成 0 的操作次数
___
#### 位运算
___
#### 数学
---
### 1343_大小为 K 且平均值大于等于阈值的子数组数目
___
#### 数组
___
#### 滑动窗口
---
### 1344_时钟指针的夹角
___
#### 数学
---
### 1345_跳跃游戏 IV
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
---
### 1346_检查整数及其两倍数是否存在
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 1347_制造字母异位词的最小步骤数
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1348_推文计数
___
#### 设计
___
#### 哈希表
___
#### 二分查找
___
#### 有序集合
___
#### 排序
---
### 1349_参加考试的最大学生数
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 有序集合 |
| 滑动窗口 | 状态压缩 | 矩阵 |
| 计数 | 设计 |  |

# [1340. 跳跃游戏 V](https://leetcode.cn/problems/jump-game-v){#1340}

{{< tabs "1340" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        f = [1] * n
        for x, i in sorted(zip(arr, range(n))):
            for j in range(i - 1, -1, -1):
                if i - j > d or arr[j] >= x:
                    break
                f[i] = max(f[i], 1 + f[j])
            for j in range(i + 1, n):
                if j - i > d or arr[j] >= x:
                    break
                f[i] = max(f[i], 1 + f[j])
        return max(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> arr[i] - arr[j]);
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int ans = 0;
        for (int i : idx) {
            for (int j = i - 1; j >= 0; --j) {
                if (i - j > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = Math.max(f[i], 1 + f[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                if (j - i > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = Math.max(f[i], 1 + f[j]);
            }
            ans = Math.max(ans, f[i]);
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
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
        vector<int> f(n, 1);
        for (int i : idx) {
            for (int j = i - 1; j >= 0; --j) {
                if (i - j > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = max(f[i], 1 + f[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                if (j - i > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = max(f[i], 1 + f[j]);
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxJumps(arr []int, d int) int {
	n := len(arr)
	idx := make([]int, n)
	f := make([]int, n)
	for i := range f {
		idx[i] = i
		f[i] = 1
	}
	sort.Slice(idx, func(i, j int) bool { return arr[idx[i]] < arr[idx[j]] })
	for _, i := range idx {
		for j := i - 1; j >= 0; j-- {
			if i-j > d || arr[j] >= arr[i] {
				break
			}
			f[i] = max(f[i], 1+f[j])
		}
		for j := i + 1; j < n; j++ {
			if j-i > d || arr[j] >= arr[i] {
				break
			}
			f[i] = max(f[i], 1+f[j])
		}
	}
	return slices.Max(f)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code> 和一个整数&nbsp;<code>d</code> 。每一步你可以从下标&nbsp;<code>i</code>&nbsp;跳到：</p>

<ul>
	<li><code>i + x</code>&nbsp;，其中&nbsp;<code>i + x &lt; arr.length</code>&nbsp;且&nbsp;<code>0 &lt; x &lt;= d</code>&nbsp;。</li>
	<li><code>i - x</code>&nbsp;，其中&nbsp;<code>i - x &gt;= 0</code>&nbsp;且&nbsp;<code>0 &lt; x &lt;= d</code>&nbsp;。</li>
</ul>

<p>除此以外，你从下标&nbsp;<code>i</code> 跳到下标 <code>j</code>&nbsp;需要满足：<code>arr[i] &gt; arr[j]</code>&nbsp;且 <code>arr[i] &gt; arr[k]</code>&nbsp;，其中下标&nbsp;<code>k</code>&nbsp;是所有 <code>i</code>&nbsp;到 <code>j</code>&nbsp;之间的数字（更正式的，<code>min(i, j) &lt; k &lt; max(i, j)</code>）。</p>

<p>你可以选择数组的任意下标开始跳跃。请你返回你 <strong>最多</strong>&nbsp;可以访问多少个下标。</p>

<p>请注意，任何时刻你都不能跳到数组的外面。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1340.Jump%20Game%20V/images/meta-chart.jpeg" style="height: 419px; width: 633px;"></p>

<pre><strong>输入：</strong>arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
<strong>输出：</strong>4
<strong>解释：</strong>你可以从下标 10 出发，然后如上图依次经过 10 --&gt; 8 --&gt; 6 --&gt; 7 。
注意，如果你从下标 6 开始，你只能跳到下标 7 处。你不能跳到下标 5 处因为 13 &gt; 9 。你也不能跳到下标 4 处，因为下标 5 在下标 4 和 6 之间且 13 &gt; 9 。
类似的，你不能从下标 3 处跳到下标 2 或者下标 1 处。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [3,3,3,3,3], d = 3
<strong>输出：</strong>1
<strong>解释：</strong>你可以从任意下标处开始且你永远无法跳到任何其他坐标。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [7,6,5,4,3,2,1], d = 1
<strong>输出：</strong>7
<strong>解释：</strong>从下标 0 处开始，你可以按照数值从大到小，访问所有的下标。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [7,1,7,1,7,1], d = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [66], d = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= d &lt;= arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示从下标 $i$ 开始跳跃能够访问的最大下标数。我们可以枚举 $i$ 的所有合法的跳跃目标 $j$，即 $i - d \leq j \leq i + d$，并且 $arr[i] \gt arr[j]$。对于每个合法的 $j$，我们可以递归地计算 $dfs(j)$，并取其中的最大值。最终的答案即为所有 $i$ 的 $dfs(i)$ 的最大值。

我们可以使用记忆化搜索来优化这个过程，即使用一个数组 $f$ 记录每个下标的 $dfs$ 值，避免重复计算。

时间复杂度 $O(n \times d)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        @cache
        def dfs(i):
            ans = 1
            for j in range(i - 1, -1, -1):
                if i - j > d or arr[j] >= arr[i]:
                    break
                ans = max(ans, 1 + dfs(j))
            for j in range(i + 1, n):
                if j - i > d or arr[j] >= arr[i]:
                    break
                ans = max(ans, 1 + dfs(j))
            return ans

        n = len(arr)
        return max(dfs(i) for i in range(n))
```

#### Java

```java
class Solution {
    private int n;
    private int d;
    private int[] arr;
    private Integer[] f;

    public int maxJumps(int[] arr, int d) {
        n = arr.length;
        this.d = d;
        this.arr = arr;
        f = new Integer[n];
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, dfs(i));
        }
        return ans;
    }

    private int dfs(int i) {
        if (f[i] != null) {
            return f[i];
        }
        int ans = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (i - j > d || arr[j] >= arr[i]) {
                break;
            }
            ans = Math.max(ans, 1 + dfs(j));
        }
        for (int j = i + 1; j < n; ++j) {
            if (j - i > d || arr[j] >= arr[i]) {
                break;
            }
            ans = Math.max(ans, 1 + dfs(j));
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int f[n];
        memset(f, 0, sizeof(f));
        function<int(int)> dfs = [&](int i) -> int {
            if (f[i]) {
                return f[i];
            }
            int ans = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (i - j > d || arr[j] >= arr[i]) {
                    break;
                }
                ans = max(ans, 1 + dfs(j));
            }
            for (int j = i + 1; j < n; ++j) {
                if (j - i > d || arr[j] >= arr[i]) {
                    break;
                }
                ans = max(ans, 1 + dfs(j));
            }
            return f[i] = ans;
        };
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
```

#### Go

```go
func maxJumps(arr []int, d int) (ans int) {
	n := len(arr)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if f[i] != 0 {
			return f[i]
		}
		ans := 1
		for j := i - 1; j >= 0; j-- {
			if i-j > d || arr[j] >= arr[i] {
				break
			}
			ans = max(ans, 1+dfs(j))
		}
		for j := i + 1; j < n; j++ {
			if j-i > d || arr[j] >= arr[i] {
				break
			}
			ans = max(ans, 1+dfs(j))
		}
		f[i] = ans
		return ans
	}
	for i := 0; i < n; i++ {
		ans = max(ans, dfs(i))
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 动态规划

我们可以将数组 $arr$ 中的每个元素 $x$ 与其下标 $i$ 组成一个元组 $(x, i)$，并将这些元组按照 $x$ 从小到大排序。

接下来定义 $f[i]$ 表示从下标 $i$ 开始跳跃能够访问的最大下标数。初始时 $f[i] = 1$，即每个下标都可以单独作为一次跳跃。

我们可以按照元组 $(x, i)$ 的顺序枚举 $i$，并枚举 $i$ 的所有合法的跳跃目标 $j$，即 $i - d \leq j \leq i + d$，并且 $arr[i] \gt arr[j]$。对于每个合法的 $j$，我们可以更新 $f[i]$ 的值，即 $f[i] = \max(f[i], 1 + f[j])$。

最终的答案即为 $\max_{0 \leq i \lt n} f[i]$。

时间复杂度 $O(n \log n + n \times d)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        f = [1] * n
        for x, i in sorted(zip(arr, range(n))):
            for j in range(i - 1, -1, -1):
                if i - j > d or arr[j] >= x:
                    break
                f[i] = max(f[i], 1 + f[j])
            for j in range(i + 1, n):
                if j - i > d or arr[j] >= x:
                    break
                f[i] = max(f[i], 1 + f[j])
        return max(f)
```

#### Java

```java
class Solution {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> arr[i] - arr[j]);
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int ans = 0;
        for (int i : idx) {
            for (int j = i - 1; j >= 0; --j) {
                if (i - j > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = Math.max(f[i], 1 + f[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                if (j - i > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = Math.max(f[i], 1 + f[j]);
            }
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
        vector<int> f(n, 1);
        for (int i : idx) {
            for (int j = i - 1; j >= 0; --j) {
                if (i - j > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = max(f[i], 1 + f[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                if (j - i > d || arr[j] >= arr[i]) {
                    break;
                }
                f[i] = max(f[i], 1 + f[j]);
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func maxJumps(arr []int, d int) int {
	n := len(arr)
	idx := make([]int, n)
	f := make([]int, n)
	for i := range f {
		idx[i] = i
		f[i] = 1
	}
	sort.Slice(idx, func(i, j int) bool { return arr[idx[i]] < arr[idx[j]] })
	for _, i := range idx {
		for j := i - 1; j >= 0; j-- {
			if i-j > d || arr[j] >= arr[i] {
				break
			}
			f[i] = max(f[i], 1+f[j])
		}
		for j := i + 1; j < n; j++ {
			if j-i > d || arr[j] >= arr[i] {
				break
			}
			f[i] = max(f[i], 1+f[j])
		}
	}
	return slices.Max(f)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1341. 电影评分](https://leetcode.cn/problems/movie-rating){#1341}

{{< tabs "1341" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
(
    SELECT name AS results
    FROM
        Users
        JOIN MovieRating USING (user_id)
    GROUP BY user_id
    ORDER BY COUNT(1) DESC, name
    LIMIT 1
)
UNION ALL
(
    SELECT title
    FROM
        MovieRating
        JOIN Movies USING (movie_id)
    WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
    GROUP BY movie_id
    ORDER BY AVG(rating) DESC, title
    LIMIT 1
);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Movies</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| title         | varchar |
+---------------+---------+
movie_id 是这个表的主键(具有唯一值的列)。
title 是电影的名字。
</pre>

<p>表：<code>Users</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
+---------------+---------+
user_id 是表的主键(具有唯一值的列)。
'name' 列具有唯一值。</pre>

<p>表：<code>MovieRating</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| user_id       | int     |
| rating        | int     |
| created_at    | date    |
+---------------+---------+
(movie_id, user_id) 是这个表的主键(具有唯一值的列的组合)。
这个表包含用户在其评论中对电影的评分 rating 。
created_at 是用户的点评日期。 
</pre>

<p>&nbsp;</p>

<p>请你编写一个解决方案：</p>

<ul>
	<li>查找评论电影数量最多的用户名。如果出现平局，返回字典序较小的用户名。</li>
	<li>查找在 <code>February 2020</code><strong> 平均评分最高</strong> 的电影名称。如果出现平局，返回字典序较小的电影名称。</li>
</ul>

<p><strong>字典序</strong> ，即按字母在字典中出现顺序对字符串排序，字典序较小则意味着排序靠前。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Movies 表：
+-------------+--------------+
| movie_id    |  title       |
+-------------+--------------+
| 1           | Avengers     |
| 2           | Frozen 2     |
| 3           | Joker        |
+-------------+--------------+
Users 表：
+-------------+--------------+
| user_id     |  name        |
+-------------+--------------+
| 1           | Daniel       |
| 2           | Monica       |
| 3           | Maria        |
| 4           | James        |
+-------------+--------------+
MovieRating 表：
+-------------+--------------+--------------+-------------+
| movie_id    | user_id      | rating       | created_at  |
+-------------+--------------+--------------+-------------+
| 1           | 1            | 3            | 2020-01-12  |
| 1           | 2            | 4            | 2020-02-11  |
| 1           | 3            | 2            | 2020-02-12  |
| 1           | 4            | 1            | 2020-01-01  |
| 2           | 1            | 5            | 2020-02-17  | 
| 2           | 2            | 2            | 2020-02-01  | 
| 2           | 3            | 2            | 2020-03-01  |
| 3           | 1            | 3            | 2020-02-22  | 
| 3           | 2            | 4            | 2020-02-25  | 
+-------------+--------------+--------------+-------------+
<strong>输出：</strong>
Result 表：
+--------------+
| results      |
+--------------+
| Daniel       |
| Frozen 2     |
+--------------+
<strong>解释：</strong>
Daniel 和 Monica 都点评了 3 部电影（"Avengers", "Frozen 2" 和 "Joker"） 但是 Daniel 字典序比较小。
Frozen 2 和 Joker 在 2 月的评分都是 3.5，但是 Frozen 2 的字典序比较小。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Union all

分别查询两个结果，然后使用 `union all` 合并结果集。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
(
    SELECT name AS results
    FROM
        Users
        JOIN MovieRating USING (user_id)
    GROUP BY user_id
    ORDER BY COUNT(1) DESC, name
    LIMIT 1
)
UNION ALL
(
    SELECT title
    FROM
        MovieRating
        JOIN Movies USING (movie_id)
    WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
    GROUP BY movie_id
    ORDER BY AVG(rating) DESC, title
    LIMIT 1
);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1342. 将数字变成 0 的操作次数](https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero){#1342}

{{< tabs "1342" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0
        return 1 + (
            self.numberOfSteps(num // 2)
            if num % 2 == 0
            else self.numberOfSteps(num - 1)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }
        return 1 + numberOfSteps((num & 1) == 0 ? num >> 1 : num - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        return 1 + (num & 1 ? numberOfSteps(num - 1) : numberOfSteps(num >> 1));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSteps(num int) int {
	if num == 0 {
		return 0
	}
	if (num & 1) == 0 {
		return 1 + numberOfSteps(num>>1)
	}
	return 1 + numberOfSteps(num-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSteps(num: number): number {
    let ans = 0;
    while (num) {
        num = num & 1 ? num - 1 : num >>> 1;
        ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_steps(mut num: i32) -> i32 {
        if num == 0 {
            0
        } else if num % 2 == 0 {
            1 + Solution::number_of_steps(num >> 1)
        } else {
            1 + Solution::number_of_steps(num - 1)
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

<p>给你一个非负整数&nbsp;<code>num</code>&nbsp;，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 14
<strong>输出：</strong>6
<strong>解释：
</strong>步骤 1) 14 是偶数，除以 2 得到 7 。
步骤 2） 7 是奇数，减 1 得到 6 。
步骤 3） 6 是偶数，除以 2 得到 3 。
步骤 4） 3 是奇数，减 1 得到 2 。
步骤 5） 2 是偶数，除以 2 得到 1 。
步骤 6） 1 是奇数，减 1 得到 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 8
<strong>输出：</strong>4
<strong>解释：</strong>
步骤 1） 8 是偶数，除以 2 得到 4 。
步骤 2） 4 是偶数，除以 2 得到 2 。
步骤 3） 2 是偶数，除以 2 得到 1 。
步骤 4） 1 是奇数，减 1 得到 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 123
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10^6</code></li>
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
    def numberOfSteps(self, num: int) -> int:
        ans = 0
        while num:
            if num & 1:
                num -= 1
            else:
                num >>= 1
            ans += 1
        return ans
```

#### Java

```java
class Solution {

    public int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0) {
            num = (num & 1) == 1 ? num - 1 : num >> 1;
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num) {
            num = num & 1 ? num - 1 : num >> 1;
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSteps(num int) int {
	ans := 0
	for num != 0 {
		if (num & 1) == 1 {
			num--
		} else {
			num >>= 1
		}
		ans++
	}
	return ans
}
```

#### TypeScript

```ts
function numberOfSteps(num: number): number {
    let ans = 0;
    while (num) {
        num = num & 1 ? num - 1 : num >>> 1;
        ans++;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_steps(mut num: i32) -> i32 {
        let mut count = 0;
        while num != 0 {
            if num % 2 == 0 {
                num >>= 1;
            } else {
                num -= 1;
            }
            count += 1;
        }
        count
    }
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
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0
        return 1 + (
            self.numberOfSteps(num // 2)
            if num % 2 == 0
            else self.numberOfSteps(num - 1)
        )
```

#### Java

```java
class Solution {

    public int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }
        return 1 + numberOfSteps((num & 1) == 0 ? num >> 1 : num - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        return 1 + (num & 1 ? numberOfSteps(num - 1) : numberOfSteps(num >> 1));
    }
};
```

#### Go

```go
func numberOfSteps(num int) int {
	if num == 0 {
		return 0
	}
	if (num & 1) == 0 {
		return 1 + numberOfSteps(num>>1)
	}
	return 1 + numberOfSteps(num-1)
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_steps(mut num: i32) -> i32 {
        if num == 0 {
            0
        } else if num % 2 == 0 {
            1 + Solution::number_of_steps(num >> 1)
        } else {
            1 + Solution::number_of_steps(num - 1)
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1343. 大小为 K 且平均值大于等于阈值的子数组数目](https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold){#1343}

{{< tabs "1343" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        threshold *= k
        s = sum(arr[:k])
        ans = int(s >= threshold)
        for i in range(k, len(arr)):
            s += arr[i] - arr[i - k]
            ans += int(s >= threshold)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        threshold *= k;
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += arr[i];
        }
        int ans = s >= threshold ? 1 : 0;
        for (int i = k; i < arr.length; ++i) {
            s += arr[i] - arr[i - k];
            ans += s >= threshold ? 1 : 0;
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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int s = accumulate(arr.begin(), arr.begin() + k, 0);
        int ans = s >= threshold;
        for (int i = k; i < arr.size(); ++i) {
            s += arr[i] - arr[i - k];
            ans += s >= threshold;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfSubarrays(arr []int, k int, threshold int) (ans int) {
	threshold *= k
	s := 0
	for _, x := range arr[:k] {
		s += x
	}
	if s >= threshold {
		ans++
	}
	for i := k; i < len(arr); i++ {
		s += arr[i] - arr[i-k]
		if s >= threshold {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfSubarrays(arr: number[], k: number, threshold: number): number {
    threshold *= k;
    let s = arr.slice(0, k).reduce((acc, cur) => acc + cur, 0);
    let ans = s >= threshold ? 1 : 0;
    for (let i = k; i < arr.length; ++i) {
        s += arr[i] - arr[i - k];
        ans += s >= threshold ? 1 : 0;
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

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;和两个整数 <code>k</code>&nbsp;和 <code>threshold</code>&nbsp;。</p>

<p>请你返回长度为 <code>k</code>&nbsp;且平均值大于等于&nbsp;<code>threshold</code>&nbsp;的子数组数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
<strong>输出：</strong>3
<strong>解释：</strong>子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
<strong>输出：</strong>6
<strong>解释：</strong>前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
	<li><code>0 &lt;= threshold &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

不妨将 `threshold` 乘以 $k$，这样我们就可以直接比较窗口内的和与 `threshold` 的大小关系。

我们维护一个长度为 $k$ 的滑动窗口，每次计算窗口内的和 $s$，如果 $s$ 大于等于 `threshold`，则答案加一。

时间复杂度 $O(n)$，其中 $n$ 为数组 `arr` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        threshold *= k
        s = sum(arr[:k])
        ans = int(s >= threshold)
        for i in range(k, len(arr)):
            s += arr[i] - arr[i - k]
            ans += int(s >= threshold)
        return ans
```

#### Java

```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        threshold *= k;
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += arr[i];
        }
        int ans = s >= threshold ? 1 : 0;
        for (int i = k; i < arr.length; ++i) {
            s += arr[i] - arr[i - k];
            ans += s >= threshold ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int s = accumulate(arr.begin(), arr.begin() + k, 0);
        int ans = s >= threshold;
        for (int i = k; i < arr.size(); ++i) {
            s += arr[i] - arr[i - k];
            ans += s >= threshold;
        }
        return ans;
    }
};
```

#### Go

```go
func numOfSubarrays(arr []int, k int, threshold int) (ans int) {
	threshold *= k
	s := 0
	for _, x := range arr[:k] {
		s += x
	}
	if s >= threshold {
		ans++
	}
	for i := k; i < len(arr); i++ {
		s += arr[i] - arr[i-k]
		if s >= threshold {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numOfSubarrays(arr: number[], k: number, threshold: number): number {
    threshold *= k;
    let s = arr.slice(0, k).reduce((acc, cur) => acc + cur, 0);
    let ans = s >= threshold ? 1 : 0;
    for (let i = k; i < arr.length; ++i) {
        s += arr[i] - arr[i - k];
        ans += s >= threshold ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1344. 时钟指针的夹角](https://leetcode.cn/problems/angle-between-hands-of-a-clock){#1344}

{{< tabs "1344" >}}

{{% tab "python" %}}
```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = 30 * hour + 0.5 * minutes
        m = 6 * minutes
        diff = abs(h - m)
        return min(diff, 360 - diff)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double angleClock(int hour, int minutes) {
        double h = 30 * hour + 0.5 * minutes;
        double m = 6 * minutes;
        double diff = Math.abs(h - m);
        return Math.min(diff, 360 - diff);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30 * hour + 0.5 * minutes;
        double m = 6 * minutes;
        double diff = abs(h - m);
        return min(diff, 360 - diff);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func angleClock(hour int, minutes int) float64 {
	h := 30*float64(hour) + 0.5*float64(minutes)
	m := 6 * float64(minutes)
	diff := math.Abs(h - m)
	return math.Min(diff, 360-diff)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function angleClock(hour: number, minutes: number): number {
    const h = 30 * hour + 0.5 * minutes;
    const m = 6 * minutes;
    const diff = Math.abs(h - m);
    return Math.min(diff, 360 - diff);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个数&nbsp;<code>hour</code>&nbsp;和&nbsp;<code>minutes</code>&nbsp;。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1344.Angle%20Between%20Hands%20of%20a%20Clock/images/sample_1_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 12, minutes = 30
<strong>输出：</strong>165
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1344.Angle%20Between%20Hands%20of%20a%20Clock/images/sample_2_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 3, minutes = 30
<strong>输出；</strong>75
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1344.Angle%20Between%20Hands%20of%20a%20Clock/images/sample_3_1673.png" style="height: 231px; width: 230px;"></strong></p>

<pre><strong>输入：</strong>hour = 3, minutes = 15
<strong>输出：</strong>7.5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>hour = 4, minutes = 50
<strong>输出：</strong>155
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>hour = 12, minutes = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hour &lt;= 12</code></li>
	<li><code>0 &lt;= minutes &lt;= 59</code></li>
	<li>与标准答案误差在&nbsp;<code>10^-5</code>&nbsp;以内的结果都被视为正确结果。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

时针每小时移动 30 度，每分钟移动 0.5 度。分针每分钟移动 6 度。如果指针之间的夹角大于 180 度，则取其与 360 度的差值，以确保获得最小的夹角。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = 30 * hour + 0.5 * minutes
        m = 6 * minutes
        diff = abs(h - m)
        return min(diff, 360 - diff)
```

#### Java

```java
class Solution {
    public double angleClock(int hour, int minutes) {
        double h = 30 * hour + 0.5 * minutes;
        double m = 6 * minutes;
        double diff = Math.abs(h - m);
        return Math.min(diff, 360 - diff);
    }
}
```

#### C++

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30 * hour + 0.5 * minutes;
        double m = 6 * minutes;
        double diff = abs(h - m);
        return min(diff, 360 - diff);
    }
};
```

#### Go

```go
func angleClock(hour int, minutes int) float64 {
	h := 30*float64(hour) + 0.5*float64(minutes)
	m := 6 * float64(minutes)
	diff := math.Abs(h - m)
	return math.Min(diff, 360-diff)
}
```

#### TypeScript

```ts
function angleClock(hour: number, minutes: number): number {
    const h = 30 * hour + 0.5 * minutes;
    const m = 6 * minutes;
    const diff = Math.abs(h - m);
    return Math.min(diff, 360 - diff);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1345. 跳跃游戏 IV](https://leetcode.cn/problems/jump-game-iv){#1345}

{{< tabs "1345" >}}

{{% tab "python" %}}
```python
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        g = defaultdict(list)
        for i, x in enumerate(arr):
            g[x].append(i)
        q = deque([0])
        vis = {0}
        ans = 0
        while 1:
            for _ in range(len(q)):
                i = q.popleft()
                if i == len(arr) - 1:
                    return ans
                for j in (i + 1, i - 1, *g.pop(arr[i], [])):
                    if 0 <= j < len(arr) and j not in vis:
                        q.append(j)
                        vis.add(j)
            ans += 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, List<Integer>> g = new HashMap<>();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            g.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
        boolean[] vis = new boolean[n];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        vis[0] = true;
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.poll();
                if (i == n - 1) {
                    return ans;
                }
                for (int j : g.get(arr[i])) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
                g.get(arr[i]).clear();
                for (int j : new int[] {i - 1, i + 1}) {
                    if (0 <= j && j < n && !vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
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
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> g;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            g[arr[i]].push_back(i);
        }
        vector<bool> vis(n);
        queue<int> q{{0}};
        vis[0] = true;
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    return ans;
                }
                for (int j : g[arr[i]]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                g[arr[i]].clear();
                for (int j : {i - 1, i + 1}) {
                    if (0 <= j && j < n && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minJumps(arr []int) int {
	g := map[int][]int{}
	for i, x := range arr {
		g[x] = append(g[x], i)
	}
	n := len(arr)
	q := []int{0}
	vis := make([]bool, n)
	vis[0] = true
	for ans := 0; ; ans++ {
		for k := len(q); k > 0; k-- {
			i := q[0]
			q = q[1:]
			if i == n-1 {
				return ans
			}
			for _, j := range g[arr[i]] {
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
			g[arr[i]] = nil
			for _, j := range []int{i - 1, i + 1} {
				if 0 <= j && j < n && !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minJumps(arr: number[]): number {
    const g: Map<number, number[]> = new Map();
    const n = arr.length;
    for (let i = 0; i < n; ++i) {
        if (!g.has(arr[i])) {
            g.set(arr[i], []);
        }
        g.get(arr[i])!.push(i);
    }
    let q: number[] = [0];
    const vis: boolean[] = Array(n).fill(false);
    vis[0] = true;
    for (let ans = 0; ; ++ans) {
        const nq: number[] = [];
        for (const i of q) {
            if (i === n - 1) {
                return ans;
            }
            for (const j of g.get(arr[i])!) {
                if (!vis[j]) {
                    vis[j] = true;
                    nq.push(j);
                }
            }
            g.get(arr[i])!.length = 0;
            for (const j of [i - 1, i + 1]) {
                if (j >= 0 && j < n && !vis[j]) {
                    vis[j] = true;
                    nq.push(j);
                }
            }
        }
        q = nq;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;，你一开始在数组的第一个元素处（下标为 0）。</p>

<p>每一步，你可以从下标&nbsp;<code>i</code>&nbsp;跳到下标&nbsp;<code>i + 1</code> 、<code>i - 1</code> 或者 <code>j</code> ：</p>

<ul>
	<li><code>i + 1</code> 需满足：<code>i + 1 &lt; arr.length</code></li>
	<li><code>i - 1</code>&nbsp;需满足：<code>i - 1 &gt;= 0</code></li>
	<li><code>j</code>&nbsp;需满足：<code>arr[i] == arr[j]</code>&nbsp;且&nbsp;<code>i != j</code></li>
</ul>

<p>请你返回到达数组最后一个元素的下标处所需的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>

<p>注意：任何时候你都不能跳到数组外面。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>输出：</strong>3
<strong>解释：</strong>那你需要跳跃 3 次，下标依次为 0 --&gt; 4 --&gt; 3 --&gt; 9 。下标 9 为数组的最后一个元素的下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [7]
<strong>输出：</strong>0
<strong>解释：</strong>一开始就在最后一个元素处，所以你不需要跳跃。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [7,6,9,6,9,6,9,7]
<strong>输出：</strong>1
<strong>解释：</strong>你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
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
    def minJumps(self, arr: List[int]) -> int:
        g = defaultdict(list)
        for i, x in enumerate(arr):
            g[x].append(i)
        q = deque([0])
        vis = {0}
        ans = 0
        while 1:
            for _ in range(len(q)):
                i = q.popleft()
                if i == len(arr) - 1:
                    return ans
                for j in (i + 1, i - 1, *g.pop(arr[i], [])):
                    if 0 <= j < len(arr) and j not in vis:
                        q.append(j)
                        vis.add(j)
            ans += 1
```

#### Java

```java
class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, List<Integer>> g = new HashMap<>();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            g.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
        boolean[] vis = new boolean[n];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        vis[0] = true;
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.poll();
                if (i == n - 1) {
                    return ans;
                }
                for (int j : g.get(arr[i])) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
                g.get(arr[i]).clear();
                for (int j : new int[] {i - 1, i + 1}) {
                    if (0 <= j && j < n && !vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> g;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            g[arr[i]].push_back(i);
        }
        vector<bool> vis(n);
        queue<int> q{{0}};
        vis[0] = true;
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    return ans;
                }
                for (int j : g[arr[i]]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                g[arr[i]].clear();
                for (int j : {i - 1, i + 1}) {
                    if (0 <= j && j < n && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func minJumps(arr []int) int {
	g := map[int][]int{}
	for i, x := range arr {
		g[x] = append(g[x], i)
	}
	n := len(arr)
	q := []int{0}
	vis := make([]bool, n)
	vis[0] = true
	for ans := 0; ; ans++ {
		for k := len(q); k > 0; k-- {
			i := q[0]
			q = q[1:]
			if i == n-1 {
				return ans
			}
			for _, j := range g[arr[i]] {
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
			g[arr[i]] = nil
			for _, j := range []int{i - 1, i + 1} {
				if 0 <= j && j < n && !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
		}
	}
}
```

#### TypeScript

```ts
function minJumps(arr: number[]): number {
    const g: Map<number, number[]> = new Map();
    const n = arr.length;
    for (let i = 0; i < n; ++i) {
        if (!g.has(arr[i])) {
            g.set(arr[i], []);
        }
        g.get(arr[i])!.push(i);
    }
    let q: number[] = [0];
    const vis: boolean[] = Array(n).fill(false);
    vis[0] = true;
    for (let ans = 0; ; ++ans) {
        const nq: number[] = [];
        for (const i of q) {
            if (i === n - 1) {
                return ans;
            }
            for (const j of g.get(arr[i])!) {
                if (!vis[j]) {
                    vis[j] = true;
                    nq.push(j);
                }
            }
            g.get(arr[i])!.length = 0;
            for (const j of [i - 1, i + 1]) {
                if (j >= 0 && j < n && !vis[j]) {
                    vis[j] = true;
                    nq.push(j);
                }
            }
        }
        q = nq;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1346. 检查整数及其两倍数是否存在](https://leetcode.cn/problems/check-if-n-and-its-double-exist){#1346}

{{< tabs "1346" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        s = set()
        for x in arr:
            if x * 2 in s or (x % 2 == 0 and x // 2 in s):
                return True
            s.add(x)
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> s = new HashSet<>();
        for (int x : arr) {
            if (s.contains(x * 2) || ((x % 2 == 0 && s.contains(x / 2)))) {
                return true;
            }
            s.add(x);
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
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int x : arr) {
            if (s.contains(x * 2) || (x % 2 == 0 && s.contains(x / 2))) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkIfExist(arr []int) bool {
	s := map[int]bool{}
	for _, x := range arr {
		if s[x*2] || (x%2 == 0 && s[x/2]) {
			return true
		}
		s[x] = true
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkIfExist(arr: number[]): boolean {
    const s: Set<number> = new Set();
    for (const x of arr) {
        if (s.has(x * 2) || (x % 2 === 0 && s.has((x / 2) | 0))) {
            return true;
        }
        s.add(x);
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>，请你检查是否存在两个整数&nbsp;<code>N</code> 和 <code>M</code>，满足&nbsp;<code>N</code>&nbsp;是&nbsp;<code>M</code>&nbsp;的两倍（即，<code>N = 2 * M</code>）。</p>

<p>更正式地，检查是否存在两个下标&nbsp;<code>i</code> 和 <code>j</code> 满足：</p>

<ul>
	<li><code>i != j</code></li>
	<li><code>0 &lt;= i, j &lt; arr.length</code></li>
	<li><code>arr[i] == 2 * arr[j]</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [10,2,5,3]
<strong>输出：</strong>true
<strong>解释：</strong>N<code> = 10</code> 是 M<code> = 5 的两倍</code>，即 <code>10 = 2 * 5 。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7,1,14,11]
<strong>输出：</strong>true
<strong>解释：</strong>N<code> = 14</code> 是 M<code> = 7 的两倍</code>，即 <code>14 = 2 * 7 </code>。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,7,11]
<strong>输出：</strong>false
<strong>解释：</strong>在该情况下不存在 N 和 M 满足 N = 2 * M 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 500</code></li>
	<li><code>-10^3 &lt;= arr[i] &lt;= 10^3</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们定义一个哈希表 $s$，用于记录访问过的元素。

遍历数组 $arr$，对于每个元素 $x$，如果 $x$ 的两倍或者 $x$ 的一半在哈希表 $s$ 中，那么返回 `true`。否则将 $x$ 加入哈希表 $s$。

若遍历结束后没有找到满足条件的元素，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        s = set()
        for x in arr:
            if x * 2 in s or (x % 2 == 0 and x // 2 in s):
                return True
            s.add(x)
        return False
```

#### Java

```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> s = new HashSet<>();
        for (int x : arr) {
            if (s.contains(x * 2) || ((x % 2 == 0 && s.contains(x / 2)))) {
                return true;
            }
            s.add(x);
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int x : arr) {
            if (s.contains(x * 2) || (x % 2 == 0 && s.contains(x / 2))) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};
```

#### Go

```go
func checkIfExist(arr []int) bool {
	s := map[int]bool{}
	for _, x := range arr {
		if s[x*2] || (x%2 == 0 && s[x/2]) {
			return true
		}
		s[x] = true
	}
	return false
}
```

#### TypeScript

```ts
function checkIfExist(arr: number[]): boolean {
    const s: Set<number> = new Set();
    for (const x of arr) {
        if (s.has(x * 2) || (x % 2 === 0 && s.has((x / 2) | 0))) {
            return true;
        }
        s.add(x);
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1347. 制造字母异位词的最小步骤数](https://leetcode.cn/problems/minimum-number-of-steps-to-make-two-strings-anagram){#1347}

{{< tabs "1347" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = Counter(s)
        ans = 0
        for c in t:
            cnt[c] -= 1
            ans += cnt[c] < 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSteps(String s, String t) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        int ans = 0;
        for (char c : t.toCharArray()) {
            if (--cnt[c - 'a'] < 0) {
                ans++;
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
    int minSteps(string s, string t) {
        int cnt[26]{};
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (char c : t) {
            if (--cnt[c - 'a'] < 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSteps(s string, t string) (ans int) {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, c := range t {
		cnt[c-'a']--
		if cnt[c-'a'] < 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSteps(s: string, t: string): number {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    let ans = 0;
    for (const c of t) {
        if (--cnt[c.charCodeAt(0) - 97] < 0) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function (s, t) {
    const cnt = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    let ans = 0;
    for (const c of t) {
        if (--cnt[c.charCodeAt(0) - 97] < 0) {
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

<p>给你两个长度相等的字符串&nbsp;<code>s</code> 和 <code>t</code>。每一个步骤中，你可以选择将&nbsp;<code>t</code>&nbsp;中的 <strong>任一字符</strong> 替换为 <strong>另一个字符</strong>。</p>

<p>返回使&nbsp;<code>t</code>&nbsp;成为&nbsp;<code>s</code>&nbsp;的字母异位词的最小步骤数。</p>

<p><strong>字母异位词</strong> 指字母相同，但排列不同（也可能相同）的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输出：</strong>s = &quot;bab&quot;, t = &quot;aba&quot;
<strong>输出：</strong>1
<strong>提示：</strong>用 &#39;b&#39; 替换 t 中的第一个 &#39;a&#39;，t = &quot;bba&quot; 是 s 的一个字母异位词。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输出：</strong>s = &quot;leetcode&quot;, t = &quot;practice&quot;
<strong>输出：</strong>5
<strong>提示：</strong>用合适的字符替换 t 中的 &#39;p&#39;, &#39;r&#39;, &#39;a&#39;, &#39;i&#39; 和 &#39;c&#39;，使 t 变成 s 的字母异位词。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输出：</strong>s = &quot;anagram&quot;, t = &quot;mangaar&quot;
<strong>输出：</strong>0
<strong>提示：</strong>&quot;anagram&quot; 和 &quot;mangaar&quot; 本身就是一组字母异位词。 
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输出：</strong>s = &quot;xxyyzz&quot;, t = &quot;xxyyzz&quot;
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输出：</strong>s = &quot;friend&quot;, t = &quot;family&quot;
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50000</code></li>
	<li><code>s.length == t.length</code></li>
	<li><code>s</code> 和 <code>t</code>&nbsp;只包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以使用一个哈希表或者数组 $\textit{cnt}$ 来统计字符串 $\textit{s}$ 中每个字符出现的次数，然后遍历字符串 $\textit{t}$，对于每个字符，我们在 $\textit{cnt}$ 中将其出现的次数减一，如果减一后的值小于 $0$，说明这个字符在字符串 $\textit{t}$ 中出现的次数比在字符串 $\textit{s}$ 中多，我们需要将这个字符替换掉，将答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(m + n)$，空间复杂度 $O(|\Sigma|)$，其中 $m$ 和 $n$ 分别是字符串 $\textit{s}$ 和 $\textit{t}$ 的长度，而 $|\Sigma|$ 是字符集的大小，本题中字符集为小写字母，因此 $|\Sigma| = 26$。

#### Python3

```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = Counter(s)
        ans = 0
        for c in t:
            cnt[c] -= 1
            ans += cnt[c] < 0
        return ans
```

#### Java

```java
class Solution {
    public int minSteps(String s, String t) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        int ans = 0;
        for (char c : t.toCharArray()) {
            if (--cnt[c - 'a'] < 0) {
                ans++;
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
    int minSteps(string s, string t) {
        int cnt[26]{};
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (char c : t) {
            if (--cnt[c - 'a'] < 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minSteps(s string, t string) (ans int) {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, c := range t {
		cnt[c-'a']--
		if cnt[c-'a'] < 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minSteps(s: string, t: string): number {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    let ans = 0;
    for (const c of t) {
        if (--cnt[c.charCodeAt(0) - 97] < 0) {
            ++ans;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function (s, t) {
    const cnt = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    let ans = 0;
    for (const c of t) {
        if (--cnt[c.charCodeAt(0) - 97] < 0) {
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

# [1348. 推文计数](https://leetcode.cn/problems/tweet-counts-per-frequency){#1348}

{{< tabs "1348" >}}

{{% tab "python" %}}
```python
class TweetCounts:
    def __init__(self):
        self.d = {"minute": 60, "hour": 3600, "day": 86400}
        self.data = defaultdict(SortedList)

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.data[tweetName].add(time)

    def getTweetCountsPerFrequency(
        self, freq: str, tweetName: str, startTime: int, endTime: int
    ) -> List[int]:
        f = self.d[freq]
        tweets = self.data[tweetName]
        t = startTime
        ans = []
        while t <= endTime:
            l = tweets.bisect_left(t)
            r = tweets.bisect_left(min(t + f, endTime + 1))
            ans.append(r - l)
            t += f
        return ans


# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TweetCounts {
    private Map<String, TreeMap<Integer, Integer>> data = new HashMap<>();

    public TweetCounts() {
    }

    public void recordTweet(String tweetName, int time) {
        data.putIfAbsent(tweetName, new TreeMap<>());
        var tm = data.get(tweetName);
        tm.put(time, tm.getOrDefault(time, 0) + 1);
    }

    public List<Integer> getTweetCountsPerFrequency(
        String freq, String tweetName, int startTime, int endTime) {
        int f = 60;
        if ("hour".equals(freq)) {
            f = 3600;
        } else if ("day".equals(freq)) {
            f = 86400;
        }
        var tm = data.get(tweetName);
        List<Integer> ans = new ArrayList<>();
        for (int i = startTime; i <= endTime; i += f) {
            int s = 0;
            int end = Math.min(i + f, endTime + 1);
            for (int v : tm.subMap(i, end).values()) {
                s += v;
            }
            ans.add(s);
        }
        return ans;
    }
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TweetCounts {
public:
    TweetCounts() {
    }

    void recordTweet(string tweetName, int time) {
        data[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int f = 60;
        if (freq == "hour")
            f = 3600;
        else if (freq == "day")
            f = 86400;
        vector<int> ans((endTime - startTime) / f + 1);
        auto l = data[tweetName].lower_bound(startTime);
        auto r = data[tweetName].upper_bound(endTime);
        for (; l != r; ++l) {
            ++ans[(*l - startTime) / f];
        }
        return ans;
    }

private:
    unordered_map<string, multiset<int>> data;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一家社交媒体公司正试图通过分析特定时间段内出现的推文数量来监控其网站上的活动。这些时间段可以根据特定的频率（&nbsp;<strong>每分钟&nbsp;</strong>、<strong>每小时&nbsp;</strong>或 <strong>每一天</strong> ）划分为更小的 <strong>时间段</strong> 。</p>

<p>&nbsp;</p>

<p>例如，周期 <code>[10,10000]</code>&nbsp;（以 <strong>秒</strong> 为单位）将被划分为以下频率的 <strong>时间块</strong> :</p>

<ul>
	<li>每 <strong>分钟</strong> (60秒 块)：<meta charset="UTF-8" />&nbsp;<code>[10,69]</code>,&nbsp;<code>[70,129]</code>,&nbsp;<code>[130,189]</code>,&nbsp;<code>...</code>,&nbsp;<code>[9970,10000]</code></li>
	<li>每 <strong>小时</strong> (3600秒 块)：<meta charset="UTF-8" /><code>[10,3609]</code>,&nbsp;<code>[3610,7209]</code>,&nbsp;<code>[7210,10000]</code></li>
	<li>每 <strong>天</strong> (86400秒 块)：<meta charset="UTF-8" />&nbsp;<code>[10,10000]</code></li>
</ul>

<p>注意，最后一个块可能比指定频率的块大小更短，并且总是以时间段的结束时间结束(在上面的示例中为 <code>10000</code> )。</p>

<p>设计和实现一个API来帮助公司进行分析。</p>

<p>实现 <code>TweetCounts</code> 类:</p>

<ul>
	<li><code>TweetCounts()</code> 初始化 <code>TweetCounts</code> 对象。</li>
	<li>存储记录时间的 <code>tweetName</code> (以秒为单位)。</li>
	<li><code>List&lt;integer&gt; getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime)</code>&nbsp;返回一个整数列表，表示给定时间 <code>[startTime, endTime]</code>&nbsp;（单位秒）和频率频率中，每个 <strong>时间块</strong> 中带有 <code>tweetName</code> 的 <code>tweet</code> 的数量。
	<ul>
		<li><code>freq</code> 是 <code>“minute”</code> 、 <code>“hour”</code> 或 <code>“day”</code> 中的一个，分别表示 <strong>每分钟</strong> 、 <strong>每小时</strong> 或 <strong>每一天</strong> 的频率。</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

<strong>输出：</strong>
[null,null,null,null,[2],[2,1],null,[4]]

<strong>解释：</strong>
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);
tweetCounts.recordTweet("tweet3", 60);
tweetCounts.recordTweet("tweet3", 10);                             //&nbsp;"tweet3"&nbsp;发布推文的时间分别是&nbsp;0,&nbsp;10&nbsp;和&nbsp;60 。
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); //&nbsp;返回&nbsp;[2]。统计频率是每分钟（60 秒），因此只有一个有效时间间隔 [0,60&gt;&nbsp;-&nbsp;&gt;&nbsp;2&nbsp;条推文。
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); //&nbsp;返回&nbsp;[2,1]。统计频率是每分钟（60 秒），因此有两个有效时间间隔&nbsp;<strong>1)</strong>&nbsp;[0,60&gt;&nbsp;-&nbsp;&gt;&nbsp;2&nbsp;条推文，和&nbsp;<strong>2)</strong>&nbsp;[60,61&gt;&nbsp;-&nbsp;&gt;&nbsp;1&nbsp;条推文。 
tweetCounts.recordTweet("tweet3", 120);                            // "tweet3"&nbsp;发布推文的时间分别是 0, 10, 60 和 120 。
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  //&nbsp;返回&nbsp;[4]。统计频率是每小时（3600 秒），因此只有一个有效时间间隔 [0,211&gt;&nbsp;-&nbsp;&gt;&nbsp;4&nbsp;条推文。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= time, startTime, endTime &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= endTime - startTime &lt;= 10<sup>4</sup></code></li>
	<li><code>recordTweet</code>&nbsp;和&nbsp;<code>getTweetCountsPerFrequency</code>，最多有<meta charset="UTF-8" />&nbsp;<code>10<sup>4</sup></code>&nbsp;次操作。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序列表

我们用哈希表 `data` 记录每个用户的推文时间，用有序列表记录每个用户的所有推文时间。

对于 `recordTweet` 操作，我们将推文时间加入到用户的推文时间列表中。

对于 `getTweetCountsPerFrequency` 操作，我们先计算出时间间隔 `f`，然后遍历用户的推文时间列表，统计每个时间间隔内的推文数量。

时间复杂度，对于 `recordTweet` 操作，总的时间复杂度 $O(n \times \log n)$；对于 `getTweetCountsPerFrequency` 操作，总的时间复杂度 $O(q \times (t + \log n))$。其中 $n$, $q$ 和 $t$ 分别表示插入的推文数量，查询的次数和时间间隔的长度。

<!-- tabs:start -->

#### Python3

```python
class TweetCounts:
    def __init__(self):
        self.d = {"minute": 60, "hour": 3600, "day": 86400}
        self.data = defaultdict(SortedList)

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.data[tweetName].add(time)

    def getTweetCountsPerFrequency(
        self, freq: str, tweetName: str, startTime: int, endTime: int
    ) -> List[int]:
        f = self.d[freq]
        tweets = self.data[tweetName]
        t = startTime
        ans = []
        while t <= endTime:
            l = tweets.bisect_left(t)
            r = tweets.bisect_left(min(t + f, endTime + 1))
            ans.append(r - l)
            t += f
        return ans


# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
```

#### Java

```java
class TweetCounts {
    private Map<String, TreeMap<Integer, Integer>> data = new HashMap<>();

    public TweetCounts() {
    }

    public void recordTweet(String tweetName, int time) {
        data.putIfAbsent(tweetName, new TreeMap<>());
        var tm = data.get(tweetName);
        tm.put(time, tm.getOrDefault(time, 0) + 1);
    }

    public List<Integer> getTweetCountsPerFrequency(
        String freq, String tweetName, int startTime, int endTime) {
        int f = 60;
        if ("hour".equals(freq)) {
            f = 3600;
        } else if ("day".equals(freq)) {
            f = 86400;
        }
        var tm = data.get(tweetName);
        List<Integer> ans = new ArrayList<>();
        for (int i = startTime; i <= endTime; i += f) {
            int s = 0;
            int end = Math.min(i + f, endTime + 1);
            for (int v : tm.subMap(i, end).values()) {
                s += v;
            }
            ans.add(s);
        }
        return ans;
    }
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```

#### C++

```cpp
class TweetCounts {
public:
    TweetCounts() {
    }

    void recordTweet(string tweetName, int time) {
        data[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int f = 60;
        if (freq == "hour")
            f = 3600;
        else if (freq == "day")
            f = 86400;
        vector<int> ans((endTime - startTime) / f + 1);
        auto l = data[tweetName].lower_bound(startTime);
        auto r = data[tweetName].upper_bound(endTime);
        for (; l != r; ++l) {
            ++ans[(*l - startTime) / f];
        }
        return ans;
    }

private:
    unordered_map<string, multiset<int>> data;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1349. 参加考试的最大学生数](https://leetcode.cn/problems/maximum-students-taking-exam){#1349}

{{< tabs "1349" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        def f(seat: List[str]) -> int:
            mask = 0
            for i, c in enumerate(seat):
                if c == '.':
                    mask |= 1 << i
            return mask

        @cache
        def dfs(seat: int, i: int) -> int:
            ans = 0
            for mask in range(1 << n):
                if (seat | mask) != seat or (mask & (mask << 1)):
                    continue
                cnt = mask.bit_count()
                if i == len(ss) - 1:
                    ans = max(ans, cnt)
                else:
                    nxt = ss[i + 1]
                    nxt &= ~(mask << 1)
                    nxt &= ~(mask >> 1)
                    ans = max(ans, cnt + dfs(nxt, i + 1))
            return ans

        n = len(seats[0])
        ss = [f(s) for s in seats]
        return dfs(ss[0], 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private int n;
    private int[] ss;

    public int maxStudents(char[][] seats) {
        int m = seats.length;
        n = seats[0].length;
        ss = new int[m];
        f = new Integer[1 << n][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    ss[i] |= 1 << j;
                }
            }
        }
        return dfs(ss[0], 0);
    }

    private int dfs(int seat, int i) {
        if (f[seat][i] != null) {
            return f[seat][i];
        }
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            if ((seat | mask) != seat || (mask & (mask << 1)) != 0) {
                continue;
            }
            int cnt = Integer.bitCount(mask);
            if (i == ss.length - 1) {
                ans = Math.max(ans, cnt);
            } else {
                int nxt = ss[i + 1];
                nxt &= ~(mask << 1);
                nxt &= ~(mask >> 1);
                ans = Math.max(ans, cnt + dfs(nxt, i + 1));
            }
        }
        return f[seat][i] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> ss(m);
        vector<vector<int>> f(1 << n, vector<int>(m, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    ss[i] |= 1 << j;
                }
            }
        }
        function<int(int, int)> dfs = [&](int seat, int i) -> int {
            if (f[seat][i] != -1) {
                return f[seat][i];
            }
            int ans = 0;
            for (int mask = 0; mask < 1 << n; ++mask) {
                if ((seat | mask) != seat || (mask & (mask << 1)) != 0) {
                    continue;
                }
                int cnt = __builtin_popcount(mask);
                if (i == m - 1) {
                    ans = max(ans, cnt);
                } else {
                    int nxt = ss[i + 1];
                    nxt &= ~(mask >> 1);
                    nxt &= ~(mask << 1);
                    ans = max(ans, cnt + dfs(nxt, i + 1));
                }
            }
            return f[seat][i] = ans;
        };
        return dfs(ss[0], 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxStudents(seats [][]byte) int {
	m, n := len(seats), len(seats[0])
	ss := make([]int, m)
	f := make([][]int, 1<<n)
	for i, seat := range seats {
		for j, c := range seat {
			if c == '.' {
				ss[i] |= 1 << j
			}
		}
	}
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) int
	dfs = func(seat, i int) int {
		if f[seat][i] != -1 {
			return f[seat][i]
		}
		ans := 0
		for mask := 0; mask < 1<<n; mask++ {
			if (seat|mask) != seat || (mask&(mask<<1)) != 0 {
				continue
			}
			cnt := bits.OnesCount(uint(mask))
			if i == m-1 {
				ans = max(ans, cnt)
			} else {
				nxt := ss[i+1] & ^(mask >> 1) & ^(mask << 1)
				ans = max(ans, cnt+dfs(nxt, i+1))
			}
		}
		f[seat][i] = ans
		return ans
	}
	return dfs(ss[0], 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxStudents(seats: string[][]): number {
    const m: number = seats.length;
    const n: number = seats[0].length;
    const ss: number[] = Array(m).fill(0);
    const f: number[][] = Array.from({ length: 1 << n }, () => Array(m).fill(-1));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (seats[i][j] === '.') {
                ss[i] |= 1 << j;
            }
        }
    }

    const dfs = (seat: number, i: number): number => {
        if (f[seat][i] !== -1) {
            return f[seat][i];
        }
        let ans: number = 0;
        for (let mask = 0; mask < 1 << n; ++mask) {
            if ((seat | mask) !== seat || (mask & (mask << 1)) !== 0) {
                continue;
            }
            const cnt: number = mask.toString(2).split('1').length - 1;
            if (i === m - 1) {
                ans = Math.max(ans, cnt);
            } else {
                let nxt: number = ss[i + 1];
                nxt &= ~(mask >> 1);
                nxt &= ~(mask << 1);
                ans = Math.max(ans, cnt + dfs(nxt, i + 1));
            }
        }
        return (f[seat][i] = ans);
    };
    return dfs(ss[0], 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m&nbsp;* n</code>&nbsp;的矩阵 <code>seats</code>&nbsp;表示教室中的座位分布。如果座位是坏的（不可用），就用&nbsp;<code>'#'</code>&nbsp;表示；否则，用&nbsp;<code>'.'</code>&nbsp;表示。</p>

<p>学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的同时参加考试且无法作弊的&nbsp;<strong>最大&nbsp;</strong>学生人数。</p>

<p>学生必须坐在状况良好的座位上。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1349.Maximum%20Students%20Taking%20Exam/images/image.png" style="height: 197px; width: 339px;" /></p>

<pre>
<strong>输入：</strong>seats = [["#",".","#","#",".","#"],
&nbsp;             [".","#","#","#","#","."],
&nbsp;             ["#",".","#","#",".","#"]]
<strong>输出：</strong>4
<strong>解释：</strong>教师可以让 4 个学生坐在可用的座位上，这样他们就无法在考试中作弊。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>seats = [[".","#"],
&nbsp;             ["#","#"],
&nbsp;             ["#","."],
&nbsp;             ["#","#"],
&nbsp;             [".","#"]]
<strong>输出：</strong>3
<strong>解释：</strong>让所有学生坐在可用的座位上。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>seats = [["#",".","<strong>.</strong>",".","#"],
&nbsp;             ["<strong>.</strong>","#","<strong>.</strong>","#","<strong>.</strong>"],
&nbsp;             ["<strong>.</strong>",".","#",".","<strong>.</strong>"],
&nbsp;             ["<strong>.</strong>","#","<strong>.</strong>","#","<strong>.</strong>"],
&nbsp;             ["#",".","<strong>.</strong>",".","#"]]
<strong>输出：</strong>10
<strong>解释：</strong>让学生坐在第 1、3 和 5 列的可用座位上。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>seats</code>&nbsp;只包含字符&nbsp;<code>'.'&nbsp;和</code><code>'#'</code></li>
	<li><code>m ==&nbsp;seats.length</code></li>
	<li><code>n ==&nbsp;seats[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 8</code></li>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

我们注意到，每个座位有两种状态：可选和不可选。因此，我们可以使用二进制数来表示每一行的座位状态，其中 $1$ 表示可选，而 $0$ 表示不可选。例如，对于示例 $1$ 中的第一行，我们可以表示为 $010010$。因此，我们将初始座位转换为一个一维数组 $ss$，其中 $ss[i]$ 表示第 $i$ 行的座位状态。

接下来，我们设计一个函数 $dfs(seat, i)$，表示从第 $i$ 行开始，当前行的座位状态为 $seat$，可以容纳的最多学生人数。

我们可以枚举第 $i$ 行的所有选座状态 $mask$，并且判断 $mask$ 是否满足以下条件：

-   状态 $mask$ 不能选择 $seat$ 之外的座位；
-   状态 $mask$ 不能选择相邻的座位。

如果满足条件，我们求出当前行选择的座位个数 $cnt$，如果当前是最后一行，则更新函数的返回值，即 $ans = \max(ans, cnt)$。否则，我们继续递归地求解下一行的最大人数，下一行的座位状态 $nxt = ss[i + 1]$，并且需要排除当前行已选座位的左右两侧。然后我们递归地求解下一行的最大人数，即 $ans = \max(ans, cnt + dfs(nxt, i + 1))$。

最后，我们将 $ans$ 作为函数的返回值返回。

为了避免重复计算，我们可以使用记忆化搜索，将函数 $dfs(seat, i)$ 的返回值保存在一个二维数组 $f$ 中，其中 $f[seat][i]$ 表示从第 $i$ 行开始，当前行的座位状态为 $seat$，可以容纳的最多学生人数。

时间复杂度 $O(4^n \times n \times m)$，空间复杂度 $O(2^n \times m)$。其中 $m$ 和 $n$ 分别为座位的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        def f(seat: List[str]) -> int:
            mask = 0
            for i, c in enumerate(seat):
                if c == '.':
                    mask |= 1 << i
            return mask

        @cache
        def dfs(seat: int, i: int) -> int:
            ans = 0
            for mask in range(1 << n):
                if (seat | mask) != seat or (mask & (mask << 1)):
                    continue
                cnt = mask.bit_count()
                if i == len(ss) - 1:
                    ans = max(ans, cnt)
                else:
                    nxt = ss[i + 1]
                    nxt &= ~(mask << 1)
                    nxt &= ~(mask >> 1)
                    ans = max(ans, cnt + dfs(nxt, i + 1))
            return ans

        n = len(seats[0])
        ss = [f(s) for s in seats]
        return dfs(ss[0], 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int n;
    private int[] ss;

    public int maxStudents(char[][] seats) {
        int m = seats.length;
        n = seats[0].length;
        ss = new int[m];
        f = new Integer[1 << n][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    ss[i] |= 1 << j;
                }
            }
        }
        return dfs(ss[0], 0);
    }

    private int dfs(int seat, int i) {
        if (f[seat][i] != null) {
            return f[seat][i];
        }
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            if ((seat | mask) != seat || (mask & (mask << 1)) != 0) {
                continue;
            }
            int cnt = Integer.bitCount(mask);
            if (i == ss.length - 1) {
                ans = Math.max(ans, cnt);
            } else {
                int nxt = ss[i + 1];
                nxt &= ~(mask << 1);
                nxt &= ~(mask >> 1);
                ans = Math.max(ans, cnt + dfs(nxt, i + 1));
            }
        }
        return f[seat][i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> ss(m);
        vector<vector<int>> f(1 << n, vector<int>(m, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    ss[i] |= 1 << j;
                }
            }
        }
        function<int(int, int)> dfs = [&](int seat, int i) -> int {
            if (f[seat][i] != -1) {
                return f[seat][i];
            }
            int ans = 0;
            for (int mask = 0; mask < 1 << n; ++mask) {
                if ((seat | mask) != seat || (mask & (mask << 1)) != 0) {
                    continue;
                }
                int cnt = __builtin_popcount(mask);
                if (i == m - 1) {
                    ans = max(ans, cnt);
                } else {
                    int nxt = ss[i + 1];
                    nxt &= ~(mask >> 1);
                    nxt &= ~(mask << 1);
                    ans = max(ans, cnt + dfs(nxt, i + 1));
                }
            }
            return f[seat][i] = ans;
        };
        return dfs(ss[0], 0);
    }
};
```

#### Go

```go
func maxStudents(seats [][]byte) int {
	m, n := len(seats), len(seats[0])
	ss := make([]int, m)
	f := make([][]int, 1<<n)
	for i, seat := range seats {
		for j, c := range seat {
			if c == '.' {
				ss[i] |= 1 << j
			}
		}
	}
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) int
	dfs = func(seat, i int) int {
		if f[seat][i] != -1 {
			return f[seat][i]
		}
		ans := 0
		for mask := 0; mask < 1<<n; mask++ {
			if (seat|mask) != seat || (mask&(mask<<1)) != 0 {
				continue
			}
			cnt := bits.OnesCount(uint(mask))
			if i == m-1 {
				ans = max(ans, cnt)
			} else {
				nxt := ss[i+1] & ^(mask >> 1) & ^(mask << 1)
				ans = max(ans, cnt+dfs(nxt, i+1))
			}
		}
		f[seat][i] = ans
		return ans
	}
	return dfs(ss[0], 0)
}
```

#### TypeScript

```ts
function maxStudents(seats: string[][]): number {
    const m: number = seats.length;
    const n: number = seats[0].length;
    const ss: number[] = Array(m).fill(0);
    const f: number[][] = Array.from({ length: 1 << n }, () => Array(m).fill(-1));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (seats[i][j] === '.') {
                ss[i] |= 1 << j;
            }
        }
    }

    const dfs = (seat: number, i: number): number => {
        if (f[seat][i] !== -1) {
            return f[seat][i];
        }
        let ans: number = 0;
        for (let mask = 0; mask < 1 << n; ++mask) {
            if ((seat | mask) !== seat || (mask & (mask << 1)) !== 0) {
                continue;
            }
            const cnt: number = mask.toString(2).split('1').length - 1;
            if (i === m - 1) {
                ans = Math.max(ans, cnt);
            } else {
                let nxt: number = ss[i + 1];
                nxt &= ~(mask >> 1);
                nxt &= ~(mask << 1);
                ans = Math.max(ans, cnt + dfs(nxt, i + 1));
            }
        }
        return (f[seat][i] = ans);
    };
    return dfs(ss[0], 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
