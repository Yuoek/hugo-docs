---
title: "2020_无流量的帐户数 🔒"
date: 2025-10-08T18:38:57+08:00
weight: 3
tags: [二分查找, 前缀和, 博弈, 哈希表, 字符串, 排序, 数学, 数据库, 数组, 有序集合, 枚举, 模拟, 滑动窗口, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [2020_无流量的帐户数 🔒](#2020)
#### [数据库](#2020)
### [2021_街上最亮的位置 🔒](#2021)
#### [数组](#2021)
#### [有序集合](#2021)
#### [前缀和](#2021)
#### [排序](#2021)
### [2022_将一维数组转变成二维数组](#2022)
#### [数组](#2022)
#### [矩阵](#2022)
#### [模拟](#2022)
### [2023_连接后等于目标字符串的字符串对](#2023)
#### [数组](#2023)
#### [哈希表](#2023)
#### [字符串](#2023)
#### [计数](#2023)
### [2024_考试的最大困扰度](#2024)
#### [字符串](#2024)
#### [二分查找](#2024)
#### [前缀和](#2024)
#### [滑动窗口](#2024)
### [2025_分割数组的最多方案数](#2025)
#### [数组](#2025)
#### [哈希表](#2025)
#### [计数](#2025)
#### [枚举](#2025)
#### [前缀和](#2025)
### [2026_低质量的问题 🔒](#2026)
#### [数据库](#2026)
### [2027_转换字符串的最少操作次数](#2027)
#### [贪心](#2027)
#### [字符串](#2027)
### [2028_找出缺失的观测数据](#2028)
#### [数组](#2028)
#### [数学](#2028)
#### [模拟](#2028)
### [2029_石子游戏 IX](#2029)
#### [贪心](#2029)
#### [数组](#2029)
#### [数学](#2029)
#### [计数](#2029)
#### [博弈](#2029)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2020_无流量的帐户数 🔒
___
#### 数据库
---
### 2021_街上最亮的位置 🔒
___
#### 数组
___
#### 有序集合
___
#### 前缀和
___
#### 排序
---
### 2022_将一维数组转变成二维数组
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 2023_连接后等于目标字符串的字符串对
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2024_考试的最大困扰度
___
#### 字符串
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 2025_分割数组的最多方案数
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 枚举
___
#### 前缀和
---
### 2026_低质量的问题 🔒
___
#### 数据库
---
### 2027_转换字符串的最少操作次数
___
#### 贪心
___
#### 字符串
---
### 2028_找出缺失的观测数据
___
#### 数组
___
#### 数学
___
#### 模拟
---
### 2029_石子游戏 IX
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 计数
___
#### 博弈
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 博弈 |
| 哈希表 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 枚举 | 模拟 |
| 滑动窗口 | 矩阵 | 计数 |
| 贪心 |  |  |

# [2020. 无流量的帐户数 🔒](https://leetcode.cn/problems/number-of-accounts-that-did-not-stream){#2020}

{{< tabs "2020" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT COUNT(sub.account_id) AS accounts_count
FROM
    Subscriptions AS sub
    LEFT JOIN Streams USING (account_id)
WHERE
    YEAR(start_date) <= 2021
    AND YEAR(end_date) >= 2021
    AND (YEAR(stream_date) != 2021 OR stream_date > end_date);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Subscriptions</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| start_date  | date |
| end_date    | date |
+-------------+------+
account_id 是此表的主键列。
此表的每一行都表示帐户订阅的开始和结束日期。
请注意，始终开始日期 &lt; 结束日期。</pre>

<p>&nbsp;</p>

<p>表: <code>Streams</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| session_id  | int  |
| account_id  | int  |
| stream_date | date |
+-------------+------+
session_id是该表的主键列。
account_id是订阅表中的外键。
此表的每一行都包含与会话相关联的帐户和日期的信息。</pre>

<p>&nbsp;</p>

<p>编写SQL查询以报告在 <code>2021</code> 购买订阅但没有任何会话的帐 户数。<br />
查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>

<pre>
<strong>输入:</strong> 
Subscriptions table:
+------------+------------+------------+
| account_id | start_date | end_date   |
+------------+------------+------------+
| 9          | 2020-02-18 | 2021-10-30 |
| 3          | 2021-09-21 | 2021-11-13 |
| 11         | 2020-02-28 | 2020-08-18 |
| 13         | 2021-04-20 | 2021-09-22 |
| 4          | 2020-10-26 | 2021-05-08 |
| 5          | 2020-09-11 | 2021-01-17 |
+------------+------------+------------+
Streams table:
+------------+------------+-------------+
| session_id | account_id | stream_date |
+------------+------------+-------------+
| 14         | 9          | 2020-05-16  |
| 16         | 3          | 2021-10-27  |
| 18         | 11         | 2020-04-29  |
| 17         | 13         | 2021-08-08  |
| 19         | 4          | 2020-12-31  |
| 13         | 5          | 2021-01-05  |
+------------+------------+-------------+
<strong>输出:</strong> 
+----------------+
| accounts_count |
+----------------+
| 2              |
+----------------+
<strong>解释：</strong>用户 4 和 9 在 2021 没有会话。
用户 11 在 2021 没有订阅。</pre>

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
SELECT COUNT(sub.account_id) AS accounts_count
FROM
    Subscriptions AS sub
    LEFT JOIN Streams USING (account_id)
WHERE
    YEAR(start_date) <= 2021
    AND YEAR(end_date) >= 2021
    AND (YEAR(stream_date) != 2021 OR stream_date > end_date);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2021. 街上最亮的位置 🔒](https://leetcode.cn/problems/brightest-position-on-street){#2021}

{{< tabs "2021" >}}

{{% tab "python" %}}
```python
class Solution:
    def brightestPosition(self, lights: List[List[int]]) -> int:
        d = defaultdict(int)
        for i, j in lights:
            l, r = i - j, i + j
            d[l] += 1
            d[r + 1] -= 1
        ans = s = mx = 0
        for k in sorted(d):
            s += d[k]
            if mx < s:
                mx = s
                ans = k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int brightestPosition(int[][] lights) {
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (var x : lights) {
            int l = x[0] - x[1], r = x[0] + x[1];
            d.merge(l, 1, Integer::sum);
            d.merge(r + 1, -1, Integer::sum);
        }
        int ans = 0, s = 0, mx = 0;
        for (var x : d.entrySet()) {
            int v = x.getValue();
            s += v;
            if (mx < s) {
                mx = s;
                ans = x.getKey();
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
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> d;
        for (auto& x : lights) {
            int l = x[0] - x[1], r = x[0] + x[1];
            ++d[l];
            --d[r + 1];
        }
        int ans = 0, s = 0, mx = 0;
        for (auto& [i, v] : d) {
            s += v;
            if (mx < s) {
                mx = s;
                ans = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func brightestPosition(lights [][]int) (ans int) {
	d := map[int]int{}
	for _, x := range lights {
		l, r := x[0]-x[1], x[0]+x[1]
		d[l]++
		d[r+1]--
	}
	keys := make([]int, 0, len(d))
	for i := range d {
		keys = append(keys, i)
	}
	sort.Ints(keys)
	mx, s := 0, 0
	for _, i := range keys {
		s += d[i]
		if mx < s {
			mx = s
			ans = i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} lights
 * @return {number}
 */
var brightestPosition = function (lights) {
    const d = new Map();
    for (const [i, j] of lights) {
        const l = i - j;
        const r = i + j;
        d.set(l, (d.get(l) ?? 0) + 1);
        d.set(r + 1, (d.get(r + 1) ?? 0) - 1);
    }
    const keys = [];
    for (const k of d.keys()) {
        keys.push(k);
    }
    keys.sort((a, b) => a - b);
    let ans = 0;
    let s = 0;
    let mx = 0;
    for (const i of keys) {
        s += d.get(i);
        if (mx < s) {
            mx = s;
            ans = i;
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

<p>一条街上有很多的路灯，路灯的坐标由数组&nbsp;<code>lights&nbsp;</code>的形式给出。&nbsp;每个&nbsp;<code>lights[i] = [position<sub>i</sub>, range<sub>i</sub>]</code>&nbsp;代表坐标为&nbsp;<code>position<sub>i</sub></code>&nbsp;的路灯照亮的范围为&nbsp;<code>[position<sub>i</sub> - range<sub>i</sub>, position<sub>i</sub> + range<sub>i</sub>]</code>&nbsp;<strong>（包括顶点）。</strong></p>

<p>位置&nbsp;<code>p</code>&nbsp;的亮度由能够照到&nbsp;<code>p</code>的路灯的数量来决定的。</p>

<p>给出&nbsp;<code>lights</code>, 返回<strong>最亮</strong>的位置&nbsp;。如果有很多，返回坐标最小的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2021.Brightest%20Position%20on%20Street/images/image-20210928155140-1.png" style="width: 700px; height: 165px;">
<pre><strong>输入:</strong> lights = [[-3,2],[1,2],[3,3]]
<strong>输出:</strong> -1
<strong>解释:</strong>
第一个路灯照亮的范围是[(-3) - 2, (-3) + 2] = [-5, -1].
第二个路灯照亮的范围是 [1 - 2, 1 + 2] = [-1, 3].
第三个路灯照亮的范围是 [3 - 3, 3 + 3] = [0, 6].

坐标-1被第一个和第二个路灯照亮，亮度为2
坐标0，1，2都被第二个和第三个路灯照亮，亮度为2.
对于以上坐标，-1最小，所以返回-1</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> lights = [[1,0],[0,1]]
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> lights = [[1,2]]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= lights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>lights[i].length == 2</code></li>
	<li><code>-10<sup>8</sup> &lt;= position<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= range<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组 + 哈希表 + 排序

我们可以将每个路灯照亮的范围看作是一个区间，区间左端点 $l = position_i - range_i$，区间右端点 $r = position_i + range_i$。我们可以利用差分数组的思想，对于每个区间 $[l, r]$，将位置 $l$ 的值加 $1$，将位置 $r + 1$ 的值减 $1$，用哈希表维护每个位置的变化值。

然后从小到大遍历每个位置，计算当前位置的亮度 $s$，如果此前的最大亮度 $mx \lt s$，则更新最大亮度 $mx = s$，并记录当前位置 $ans = i$。

最后返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为 $lights$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def brightestPosition(self, lights: List[List[int]]) -> int:
        d = defaultdict(int)
        for i, j in lights:
            l, r = i - j, i + j
            d[l] += 1
            d[r + 1] -= 1
        ans = s = mx = 0
        for k in sorted(d):
            s += d[k]
            if mx < s:
                mx = s
                ans = k
        return ans
```

#### Java

```java
class Solution {
    public int brightestPosition(int[][] lights) {
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (var x : lights) {
            int l = x[0] - x[1], r = x[0] + x[1];
            d.merge(l, 1, Integer::sum);
            d.merge(r + 1, -1, Integer::sum);
        }
        int ans = 0, s = 0, mx = 0;
        for (var x : d.entrySet()) {
            int v = x.getValue();
            s += v;
            if (mx < s) {
                mx = s;
                ans = x.getKey();
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
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> d;
        for (auto& x : lights) {
            int l = x[0] - x[1], r = x[0] + x[1];
            ++d[l];
            --d[r + 1];
        }
        int ans = 0, s = 0, mx = 0;
        for (auto& [i, v] : d) {
            s += v;
            if (mx < s) {
                mx = s;
                ans = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func brightestPosition(lights [][]int) (ans int) {
	d := map[int]int{}
	for _, x := range lights {
		l, r := x[0]-x[1], x[0]+x[1]
		d[l]++
		d[r+1]--
	}
	keys := make([]int, 0, len(d))
	for i := range d {
		keys = append(keys, i)
	}
	sort.Ints(keys)
	mx, s := 0, 0
	for _, i := range keys {
		s += d[i]
		if mx < s {
			mx = s
			ans = i
		}
	}
	return
}
```

#### JavaScript

```js
/**
 * @param {number[][]} lights
 * @return {number}
 */
var brightestPosition = function (lights) {
    const d = new Map();
    for (const [i, j] of lights) {
        const l = i - j;
        const r = i + j;
        d.set(l, (d.get(l) ?? 0) + 1);
        d.set(r + 1, (d.get(r + 1) ?? 0) - 1);
    }
    const keys = [];
    for (const k of d.keys()) {
        keys.push(k);
    }
    keys.sort((a, b) => a - b);
    let ans = 0;
    let s = 0;
    let mx = 0;
    for (const i of keys) {
        s += d.get(i);
        if (mx < s) {
            mx = s;
            ans = i;
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

# [2022. 将一维数组转变成二维数组](https://leetcode.cn/problems/convert-1d-array-into-2d-array){#2022}

{{< tabs "2022" >}}

{{% tab "python" %}}
```python
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original):
            return []
        return [original[i : i + n] for i in range(0, m * n, n)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (m * n != original.length) {
            return new int[0][0];
        }
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[i * n + j];
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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[i * n + j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func construct2DArray(original []int, m int, n int) (ans [][]int) {
	if m*n != len(original) {
		return [][]int{}
	}
	for i := 0; i < m*n; i += n {
		ans = append(ans, original[i:i+n])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function construct2DArray(original: number[], m: number, n: number): number[][] {
    if (m * n != original.length) {
        return [];
    }
    const ans: number[][] = [];
    for (let i = 0; i < m * n; i += n) {
        ans.push(original.slice(i, i + n));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function (original, m, n) {
    if (m * n != original.length) {
        return [];
    }
    const ans = [];
    for (let i = 0; i < m * n; i += n) {
        ans.push(original.slice(i, i + n));
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的一维整数数组&nbsp;<code>original</code>&nbsp;和两个整数&nbsp;<code>m</code>&nbsp;和&nbsp;&nbsp;<code>n</code>&nbsp;。你需要使用&nbsp;<code>original</code>&nbsp;中&nbsp;<strong>所有</strong>&nbsp;元素创建一个&nbsp;<code>m</code>&nbsp;行&nbsp;<code>n</code>&nbsp;列的二维数组。</p>

<p><code>original</code>&nbsp;中下标从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;（都 <strong>包含</strong> ）的元素构成二维数组的第一行，下标从 <code>n</code>&nbsp;到 <code>2 * n - 1</code>&nbsp;（都 <strong>包含</strong>&nbsp;）的元素构成二维数组的第二行，依此类推。</p>

<p>请你根据上述过程返回一个<em>&nbsp;</em><code>m x n</code>&nbsp;的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2022.Convert%201D%20Array%20Into%202D%20Array/images/image-20210826114243-1.png" style="width: 500px; height: 174px;">
<pre><b>输入：</b>original = [1,2,3,4], m = 2, n = 2
<b>输出：</b>[[1,2],[3,4]]
<strong>解释：
</strong>构造出的二维数组应该包含 2 行 2 列。
original 中第一个 n=2 的部分为 [1,2] ，构成二维数组的第一行。
original 中第二个 n=2 的部分为 [3,4] ，构成二维数组的第二行。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>original = [1,2,3], m = 1, n = 3
<b>输出：</b>[[1,2,3]]
<b>解释：</b>
构造出的二维数组应该包含 1 行 3 列。
将 original 中所有三个元素放入第一行中，构成要求的二维数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>original = [1,2], m = 1, n = 1
<b>输出：</b>[]
<strong>解释：
</strong>original 中有 2 个元素。
无法将 2 个元素放入到一个 1x1 的二维数组中，所以返回一个空的二维数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>original = [3], m = 1, n = 2
<b>输出：</b>[]
<strong>解释：</strong>
original 中只有 1 个元素。
无法将 1 个元素放满一个 1x2 的二维数组，所以返回一个空的二维数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= original.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= original[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m, n &lt;= 4 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题目描述，我们知道，要想构造出一个 $m$ 行 $n$ 列的二维数组，需要满足 $m \times n$ 等于原数组的长度。如果不满足，直接返回空数组即可。

如果满足，我们可以按照题目描述的过程，将原数组中的元素依次放入二维数组中即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为二维数组的行数和列数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original):
            return []
        return [original[i : i + n] for i in range(0, m * n, n)]
```

#### Java

```java
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (m * n != original.length) {
            return new int[0][0];
        }
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[i * n + j];
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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[i * n + j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func construct2DArray(original []int, m int, n int) (ans [][]int) {
	if m*n != len(original) {
		return [][]int{}
	}
	for i := 0; i < m*n; i += n {
		ans = append(ans, original[i:i+n])
	}
	return
}
```

#### TypeScript

```ts
function construct2DArray(original: number[], m: number, n: number): number[][] {
    if (m * n != original.length) {
        return [];
    }
    const ans: number[][] = [];
    for (let i = 0; i < m * n; i += n) {
        ans.push(original.slice(i, i + n));
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function (original, m, n) {
    if (m * n != original.length) {
        return [];
    }
    const ans = [];
    for (let i = 0; i < m * n; i += n) {
        ans.push(original.slice(i, i + n));
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2023. 连接后等于目标字符串的字符串对](https://leetcode.cn/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target){#2023}

{{< tabs "2023" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        cnt = Counter(nums)
        ans = 0
        for i in range(1, len(target)):
            a, b = target[:i], target[i:]
            if a != b:
                ans += cnt[a] * cnt[b]
            else:
                ans += cnt[a] * (cnt[a] - 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numOfPairs(String[] nums, String target) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        for (int i = 1; i < target.length(); ++i) {
            String a = target.substring(0, i);
            String b = target.substring(i);
            int x = cnt.getOrDefault(a, 0);
            int y = cnt.getOrDefault(b, 0);
            if (!a.equals(b)) {
                ans += x * y;
            } else {
                ans += x * (y - 1);
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
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> cnt;
        for (auto& x : nums) ++cnt[x];
        int ans = 0;
        for (int i = 1; i < target.size(); ++i) {
            string a = target.substr(0, i);
            string b = target.substr(i);
            int x = cnt[a], y = cnt[b];
            if (a != b) {
                ans += x * y;
            } else {
                ans += x * (y - 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfPairs(nums []string, target string) (ans int) {
	cnt := map[string]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for i := 1; i < len(target); i++ {
		a, b := target[:i], target[i:]
		if a != b {
			ans += cnt[a] * cnt[b]
		} else {
			ans += cnt[a] * (cnt[a] - 1)
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

<p>给你一个 <strong>数字</strong>&nbsp;字符串数组 <code>nums</code>&nbsp;和一个 <strong>数字</strong>&nbsp;字符串 <code>target</code>&nbsp;，请你返回 <code>nums[i] + nums[j]</code>&nbsp;（两个字符串连接）结果等于 <code>target</code>&nbsp;的下标 <code>(i, j)</code>&nbsp;（需满足 <code>i != j</code>）的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = ["777","7","77","77"], target = "7777"
<b>输出：</b>4
<b>解释：</b>符合要求的下标对包括：
- (0, 1)："777" + "7"
- (1, 0)："7" + "777"
- (2, 3)："77" + "77"
- (3, 2)："77" + "77"
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = ["123","4","12","34"], target = "1234"
<b>输出：</b>2
<b>解释：</b>符合要求的下标对包括
- (0, 1)："123" + "4"
- (2, 3)："12" + "34"
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = ["1","1","1"], target = "11"
<b>输出：</b>6
<b>解释：</b>符合要求的下标对包括
- (0, 1)："1" + "1"
- (1, 0)："1" + "1"
- (0, 2)："1" + "1"
- (2, 0)："1" + "1"
- (1, 2)："1" + "1"
- (2, 1)："1" + "1"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
	<li><code>2 &lt;= target.length &lt;= 100</code></li>
	<li><code>nums[i]</code>&nbsp;和&nbsp;<code>target</code>&nbsp;只包含数字。</li>
	<li><code>nums[i]</code>&nbsp;和&nbsp;<code>target</code>&nbsp;不含有任何前导 0 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

遍历数组 `nums`，对于每个 $i$，枚举所有 $j$，如果 $i \neq j$ 且 $nums[i] + nums[j] = target$，则答案加一。

时间复杂度 $O(n^2 \times m)$，其中 $n$ 和 $m$ 分别为数组 `nums` 和字符串 `target` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        n = len(nums)
        return sum(
            i != j and nums[i] + nums[j] == target for i in range(n) for j in range(n)
        )
```

#### Java

```java
class Solution {
    public int numOfPairs(String[] nums, String target) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && target.equals(nums[i] + nums[j])) {
                    ++ans;
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
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && nums[i] + nums[j] == target) ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numOfPairs(nums []string, target string) (ans int) {
	for i, a := range nums {
		for j, b := range nums {
			if i != j && a+b == target {
				ans++
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表

我们可以用哈希表统计数组 `nums` 中每个字符串出现的次数，然后遍历字符串 `target` 的所有前缀和后缀，如果前缀和后缀都在哈希表中，则答案加上它们出现的次数的乘积。

时间复杂度 $O(n + m^2)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为数组 `nums` 和字符串 `target` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        cnt = Counter(nums)
        ans = 0
        for i in range(1, len(target)):
            a, b = target[:i], target[i:]
            if a != b:
                ans += cnt[a] * cnt[b]
            else:
                ans += cnt[a] * (cnt[a] - 1)
        return ans
```

#### Java

```java
class Solution {
    public int numOfPairs(String[] nums, String target) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        for (int i = 1; i < target.length(); ++i) {
            String a = target.substring(0, i);
            String b = target.substring(i);
            int x = cnt.getOrDefault(a, 0);
            int y = cnt.getOrDefault(b, 0);
            if (!a.equals(b)) {
                ans += x * y;
            } else {
                ans += x * (y - 1);
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
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> cnt;
        for (auto& x : nums) ++cnt[x];
        int ans = 0;
        for (int i = 1; i < target.size(); ++i) {
            string a = target.substr(0, i);
            string b = target.substr(i);
            int x = cnt[a], y = cnt[b];
            if (a != b) {
                ans += x * y;
            } else {
                ans += x * (y - 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numOfPairs(nums []string, target string) (ans int) {
	cnt := map[string]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for i := 1; i < len(target); i++ {
		a, b := target[:i], target[i:]
		if a != b {
			ans += cnt[a] * cnt[b]
		} else {
			ans += cnt[a] * (cnt[a] - 1)
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

# [2024. 考试的最大困扰度](https://leetcode.cn/problems/maximize-the-confusion-of-an-exam){#2024}

{{< tabs "2024" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def f(c: str) -> int:
            cnt = l = 0
            for ch in answerKey:
                cnt += ch == c
                if cnt > k:
                    cnt -= answerKey[l] == c
                    l += 1
            return len(answerKey) - l

        return max(f("T"), f("F"))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;
    private int k;

    public int maxConsecutiveAnswers(String answerKey, int k) {
        s = answerKey.toCharArray();
        this.k = k;
        return Math.max(f('T'), f('F'));
    }

    private int f(char c) {
        int l = 0, cnt = 0;
        for (char ch : s) {
            cnt += ch == c ? 1 : 0;
            if (cnt > k) {
                cnt -= s[l++] == c ? 1 : 0;
            }
        }
        return s.length - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        auto f = [&](char c) {
            int l = 0, cnt = 0;
            for (char& ch : answerKey) {
                cnt += ch == c;
                if (cnt > k) {
                    cnt -= answerKey[l++] == c;
                }
            }
            return n - l;
        };
        return max(f('T'), f('F'));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxConsecutiveAnswers(answerKey string, k int) int {
	f := func(c byte) int {
		l, cnt := 0, 0
		for _, ch := range answerKey {
			if byte(ch) == c {
				cnt++
			}
			if cnt > k {
				if answerKey[l] == c {
					cnt--
				}
				l++
			}
		}
		return len(answerKey) - l
	}
	return max(f('T'), f('F'))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxConsecutiveAnswers(answerKey: string, k: number): number {
    const n = answerKey.length;
    const f = (c: string): number => {
        let [l, cnt] = [0, 0];
        for (const ch of answerKey) {
            cnt += ch === c ? 1 : 0;
            if (cnt > k) {
                cnt -= answerKey[l++] === c ? 1 : 0;
            }
        }
        return n - l;
    };
    return Math.max(f('T'), f('F'));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let n = answer_key.len();
        let k = k as usize;
        let s: Vec<char> = answer_key.chars().collect();

        let f = |c: char| -> usize {
            let mut l = 0;
            let mut cnt = 0;
            for &ch in &s {
                cnt += if ch == c { 1 } else { 0 };
                if cnt > k {
                    cnt -= if s[l] == c { 1 } else { 0 };
                    l += 1;
                }
            }
            n - l
        };

        std::cmp::max(f('T'), f('F')) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一位老师正在出一场由 <code>n</code>&nbsp;道判断题构成的考试，每道题的答案为 true （用 <code><span style="">'T'</span></code> 表示）或者 false （用 <code>'F'</code>&nbsp;表示）。老师想增加学生对自己做出答案的不确定性，方法是&nbsp;<strong>最大化&nbsp;</strong>有 <strong>连续相同</strong>&nbsp;结果的题数。（也就是连续出现 true 或者连续出现 false）。</p>

<p>给你一个字符串&nbsp;<code>answerKey</code>&nbsp;，其中&nbsp;<code>answerKey[i]</code>&nbsp;是第 <code>i</code>&nbsp;个问题的正确结果。除此以外，还给你一个整数 <code>k</code>&nbsp;，表示你能进行以下操作的最多次数：</p>

<ul>
	<li>每次操作中，将问题的正确答案改为&nbsp;<code>'T'</code> 或者&nbsp;<code>'F'</code>&nbsp;（也就是将 <code>answerKey[i]</code> 改为&nbsp;<code>'T'</code>&nbsp;或者&nbsp;<code>'F'</code>&nbsp;）。</li>
</ul>

<p>请你返回在不超过 <code>k</code>&nbsp;次操作的情况下，<strong>最大</strong>&nbsp;连续 <code>'T'</code>&nbsp;或者 <code>'F'</code>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>answerKey = "TTFF", k = 2
<b>输出：</b>4
<b>解释：</b>我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "<em><strong>TTTT</strong></em>" 。
总共有四个连续的 'T' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>answerKey = "TFFT", k = 1
<b>输出：</b>3
<b>解释：</b>我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "<em><strong>FFF</strong></em>T" 。
或者，我们可以将第二个 'T' 换成 'F' ，得到 answerKey = "T<em><strong>FFF</strong></em>" 。
两种情况下，都有三个连续的 'F' 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>answerKey = "TTFTTFTT", k = 1
<b>输出：</b>5
<b>解释：</b>我们可以将第一个 'F' 换成 'T' ，得到 answerKey = "<em><strong>TTTTT</strong></em>FTT" 。
或者我们可以将第二个 'F' 换成 'T' ，得到 answerKey = "TTF<em><strong>TTTTT</strong></em>" 。
两种情况下，都有五个连续的 'T' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == answerKey.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>answerKey[i]</code>&nbsp;要么是&nbsp;<code>'T'</code> ，要么是&nbsp;<code>'F'</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们设计一个函数 $\textit{f}(c)$，表示最多替换 $k$ 个字符 $c$ 的情况下，最长的连续字符的长度，其中 $c$ 可以是 'T' 或 'F'。答案就是 $\max(\textit{f}('T'), \textit{f}('F'))$。

我们遍历字符串 $\textit{answerKey}$，用一个变量 $\textit{cnt}$ 记录当前窗口内字符 $c$ 的个数，当 $\textit{cnt} > k$ 时，我们将窗口的左指针右移一位。遍历结束后，窗口的长度即为最大连续字符的长度。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

相似题目：

-   [487. 最大连续1的个数 II](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0487.Max%20Consecutive%20Ones%20II/README.md)
-   [1004. 最大连续1的个数 III](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1004.Max%20Consecutive%20Ones%20III/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def f(c: str) -> int:
            cnt = l = 0
            for ch in answerKey:
                cnt += ch == c
                if cnt > k:
                    cnt -= answerKey[l] == c
                    l += 1
            return len(answerKey) - l

        return max(f("T"), f("F"))
```

#### Java

```java
class Solution {
    private char[] s;
    private int k;

    public int maxConsecutiveAnswers(String answerKey, int k) {
        s = answerKey.toCharArray();
        this.k = k;
        return Math.max(f('T'), f('F'));
    }

    private int f(char c) {
        int l = 0, cnt = 0;
        for (char ch : s) {
            cnt += ch == c ? 1 : 0;
            if (cnt > k) {
                cnt -= s[l++] == c ? 1 : 0;
            }
        }
        return s.length - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        auto f = [&](char c) {
            int l = 0, cnt = 0;
            for (char& ch : answerKey) {
                cnt += ch == c;
                if (cnt > k) {
                    cnt -= answerKey[l++] == c;
                }
            }
            return n - l;
        };
        return max(f('T'), f('F'));
    }
};
```

#### Go

```go
func maxConsecutiveAnswers(answerKey string, k int) int {
	f := func(c byte) int {
		l, cnt := 0, 0
		for _, ch := range answerKey {
			if byte(ch) == c {
				cnt++
			}
			if cnt > k {
				if answerKey[l] == c {
					cnt--
				}
				l++
			}
		}
		return len(answerKey) - l
	}
	return max(f('T'), f('F'))
}
```

#### TypeScript

```ts
function maxConsecutiveAnswers(answerKey: string, k: number): number {
    const n = answerKey.length;
    const f = (c: string): number => {
        let [l, cnt] = [0, 0];
        for (const ch of answerKey) {
            cnt += ch === c ? 1 : 0;
            if (cnt > k) {
                cnt -= answerKey[l++] === c ? 1 : 0;
            }
        }
        return n - l;
    };
    return Math.max(f('T'), f('F'));
}
```

#### Rust

```rust
impl Solution {
    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let n = answer_key.len();
        let k = k as usize;
        let s: Vec<char> = answer_key.chars().collect();

        let f = |c: char| -> usize {
            let mut l = 0;
            let mut cnt = 0;
            for &ch in &s {
                cnt += if ch == c { 1 } else { 0 };
                if cnt > k {
                    cnt -= if s[l] == c { 1 } else { 0 };
                    l += 1;
                }
            }
            n - l
        };

        std::cmp::max(f('T'), f('F')) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2025. 分割数组的最多方案数](https://leetcode.cn/problems/maximum-number-of-ways-to-partition-an-array){#2025}

{{< tabs "2025" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToPartition(self, nums: List[int], k: int) -> int:
        n = len(nums)
        s = [nums[0]] * n
        right = defaultdict(int)
        for i in range(1, n):
            s[i] = s[i - 1] + nums[i]
            right[s[i - 1]] += 1

        ans = 0
        if s[-1] % 2 == 0:
            ans = right[s[-1] // 2]

        left = defaultdict(int)
        for v, x in zip(s, nums):
            d = k - x
            if (s[-1] + d) % 2 == 0:
                t = left[(s[-1] + d) // 2] + right[(s[-1] - d) // 2]
                if ans < t:
                    ans = t
            left[v] += 1
            right[v] -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int waysToPartition(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n];
        s[0] = nums[0];
        Map<Integer, Integer> right = new HashMap<>();
        for (int i = 0; i < n - 1; ++i) {
            right.merge(s[i], 1, Integer::sum);
            s[i + 1] = s[i] + nums[i + 1];
        }
        int ans = 0;
        if (s[n - 1] % 2 == 0) {
            ans = right.getOrDefault(s[n - 1] / 2, 0);
        }
        Map<Integer, Integer> left = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int d = k - nums[i];
            if ((s[n - 1] + d) % 2 == 0) {
                int t = left.getOrDefault((s[n - 1] + d) / 2, 0)
                    + right.getOrDefault((s[n - 1] - d) / 2, 0);
                ans = Math.max(ans, t);
            }
            left.merge(s[i], 1, Integer::sum);
            right.merge(s[i], -1, Integer::sum);
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
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        long long s[n];
        s[0] = nums[0];
        unordered_map<long long, int> right;
        for (int i = 0; i < n - 1; ++i) {
            right[s[i]]++;
            s[i + 1] = s[i] + nums[i + 1];
        }
        int ans = 0;
        if (s[n - 1] % 2 == 0) {
            ans = right[s[n - 1] / 2];
        }
        unordered_map<long long, int> left;
        for (int i = 0; i < n; ++i) {
            int d = k - nums[i];
            if ((s[n - 1] + d) % 2 == 0) {
                int t = left[(s[n - 1] + d) / 2] + right[(s[n - 1] - d) / 2];
                ans = max(ans, t);
            }
            left[s[i]]++;
            right[s[i]]--;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToPartition(nums []int, k int) (ans int) {
	n := len(nums)
	s := make([]int, n)
	s[0] = nums[0]
	right := map[int]int{}
	for i := range nums[:n-1] {
		right[s[i]]++
		s[i+1] = s[i] + nums[i+1]
	}
	if s[n-1]%2 == 0 {
		ans = right[s[n-1]/2]
	}
	left := map[int]int{}
	for i, x := range nums {
		d := k - x
		if (s[n-1]+d)%2 == 0 {
			t := left[(s[n-1]+d)/2] + right[(s[n-1]-d)/2]
			if ans < t {
				ans = t
			}
		}
		left[s[i]]++
		right[s[i]]--
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始且长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。<strong>分割</strong>&nbsp;数组 <code>nums</code>&nbsp;的方案数定义为符合以下两个条件的 <code>pivot</code>&nbsp;数目：</p>

<ul>
	<li><code>1 &lt;= pivot &lt; n</code></li>
	<li><code>nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]</code></li>
</ul>

<p>同时给你一个整数&nbsp;<code>k</code>&nbsp;。你可以将&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>一个</strong>&nbsp;元素变为&nbsp;<code>k</code>&nbsp;或&nbsp;<strong>不改变</strong>&nbsp;数组。</p>

<p>请你返回在 <strong>至多</strong>&nbsp;改变一个元素的前提下，<strong>最多</strong>&nbsp;有多少种方法 <strong>分割</strong>&nbsp;<code>nums</code>&nbsp;使得上述两个条件都满足。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,-1,2], k = 3
<b>输出：</b>1
<b>解释：</b>一个最优的方案是将 nums[0] 改为 k&nbsp;。数组变为 [<em><strong>3</strong></em>,-1,2] 。
有一种方法分割数组：
- pivot = 2 ，我们有分割 [3,-1 | 2]：3 + -1 == 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [0,0,0], k = 1
<b>输出：</b>2
<b>解释：</b>一个最优的方案是不改动数组。
有两种方法分割数组：
- pivot = 1 ，我们有分割 [0 | 0,0]：0 == 0 + 0 。
- pivot = 2 ，我们有分割 [0,0 | 0]: 0 + 0 == 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
<b>输出：</b>4
<b>解释：</b>一个最优的方案是将 nums[2] 改为 k 。数组变为 [22,4,<em><strong>-33</strong></em>,-20,-15,15,-16,7,19,-10,0,-13,-14] 。
有四种方法分割数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= k, nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

我们可以先预处理得到数组 $nums$ 对应的前缀和数组 $s$，其中 $s[i]$ 表示数组 $nums[0,...i-1]$ 的和。那么数组所有元素之和为 $s[n - 1]$。

如果不修改数组 $nums$，那么两个子数组的和相等的条件是 $s[n - 1]$ 必须为偶数，如果 $s[n - 1]$ 为偶数，那么我们求出 $ans = \frac{right[s[n - 1] / 2]}{2}$。

如果修改数组 $nums$，那么我们可以枚举每一个修改的位置 $i$，将 $nums[i]$ 修改为 $k$，那么数组总和的变化量 $d = k - nums[i]$，此时 $i$ 左侧部分的和保持不变，那么合法的分割要满足 $s[i] = s[n - 1] + d - s[i]$，即 $s[i] = \frac{s[n - 1] + d}{2}$；而右侧部分的每个前缀和都增加了 $d$，那么合法的分割要满足 $s[i] + d = s[n - 1] + d - (s[i] + d)$，即 $s[i] = \frac{s[n - 1] - d}{2}$。我们用哈希表 $left$ 和 $right$ 分别记录左侧部分和右侧部分每个前缀和出现的次数，那么我们可以求出 $ans = max(ans, left[\frac{s[n - 1] + d}{2}]) + right[\frac{s[n - 1] - d}{2}]$。

最后，我们返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToPartition(self, nums: List[int], k: int) -> int:
        n = len(nums)
        s = [nums[0]] * n
        right = defaultdict(int)
        for i in range(1, n):
            s[i] = s[i - 1] + nums[i]
            right[s[i - 1]] += 1

        ans = 0
        if s[-1] % 2 == 0:
            ans = right[s[-1] // 2]

        left = defaultdict(int)
        for v, x in zip(s, nums):
            d = k - x
            if (s[-1] + d) % 2 == 0:
                t = left[(s[-1] + d) // 2] + right[(s[-1] - d) // 2]
                if ans < t:
                    ans = t
            left[v] += 1
            right[v] -= 1
        return ans
```

#### Java

```java
class Solution {
    public int waysToPartition(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n];
        s[0] = nums[0];
        Map<Integer, Integer> right = new HashMap<>();
        for (int i = 0; i < n - 1; ++i) {
            right.merge(s[i], 1, Integer::sum);
            s[i + 1] = s[i] + nums[i + 1];
        }
        int ans = 0;
        if (s[n - 1] % 2 == 0) {
            ans = right.getOrDefault(s[n - 1] / 2, 0);
        }
        Map<Integer, Integer> left = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int d = k - nums[i];
            if ((s[n - 1] + d) % 2 == 0) {
                int t = left.getOrDefault((s[n - 1] + d) / 2, 0)
                    + right.getOrDefault((s[n - 1] - d) / 2, 0);
                ans = Math.max(ans, t);
            }
            left.merge(s[i], 1, Integer::sum);
            right.merge(s[i], -1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        long long s[n];
        s[0] = nums[0];
        unordered_map<long long, int> right;
        for (int i = 0; i < n - 1; ++i) {
            right[s[i]]++;
            s[i + 1] = s[i] + nums[i + 1];
        }
        int ans = 0;
        if (s[n - 1] % 2 == 0) {
            ans = right[s[n - 1] / 2];
        }
        unordered_map<long long, int> left;
        for (int i = 0; i < n; ++i) {
            int d = k - nums[i];
            if ((s[n - 1] + d) % 2 == 0) {
                int t = left[(s[n - 1] + d) / 2] + right[(s[n - 1] - d) / 2];
                ans = max(ans, t);
            }
            left[s[i]]++;
            right[s[i]]--;
        }
        return ans;
    }
};
```

#### Go

```go
func waysToPartition(nums []int, k int) (ans int) {
	n := len(nums)
	s := make([]int, n)
	s[0] = nums[0]
	right := map[int]int{}
	for i := range nums[:n-1] {
		right[s[i]]++
		s[i+1] = s[i] + nums[i+1]
	}
	if s[n-1]%2 == 0 {
		ans = right[s[n-1]/2]
	}
	left := map[int]int{}
	for i, x := range nums {
		d := k - x
		if (s[n-1]+d)%2 == 0 {
			t := left[(s[n-1]+d)/2] + right[(s[n-1]-d)/2]
			if ans < t {
				ans = t
			}
		}
		left[s[i]]++
		right[s[i]]--
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2026. 低质量的问题 🔒](https://leetcode.cn/problems/low-quality-problems){#2026}

{{< tabs "2026" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT problem_id
FROM Problems
WHERE likes / (likes + dislikes) < 0.6
ORDER BY problem_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Problems</code></p>

<pre>
+-------------+------+
| 列名         | 类型 |
+-------------+------+
| problem_id  | int  |
| likes       | int  |
| dislikes    | int  |
+-------------+------+
在 SQL 中，problem_id 是这张表的主键。
该表的每一行都表示一个力扣问题的喜欢和不喜欢的数量。
</pre>

<p>&nbsp;</p>

<p>找出&nbsp;<strong>低质量&nbsp;</strong>问题的 ID 集合。如果一个力扣问题的喜欢率（喜欢数除以总投票数）<strong>严格低于&nbsp;</strong><code>60%</code><strong>&nbsp;</strong>，则该问题为<strong>低质量</strong>问题。</p>

<p>按&nbsp;<code>problem_id</code> 升序排列返回结果表。</p>

<p>结果表的格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> 
Problems 表:
+------------+-------+----------+
| problem_id | likes | dislikes |
+------------+-------+----------+
| 6          | 1290  | 425      |
| 11         | 2677  | 8659     |
| 1          | 4446  | 2760     |
| 7          | 8569  | 6086     |
| 13         | 2050  | 4164     |
| 10         | 9002  | 7446     |
+------------+-------+----------+
<strong>输出:</strong> 
+------------+
| problem_id |
+------------+
| 7          |
| 10         |
| 11         |
| 13         |
+------------+
<strong>解释:</strong> 喜欢的比率如下:
- 问题 1: (4446 / (4446 + 2760)) * 100 = 61.69858%
- 问题 6: (1290 / (1290 + 425)) * 100 = 75.21866%
- 问题 7: (8569 / (8569 + 6086)) * 100 = 58.47151%
- 问题 10: (9002 / (9002 + 7446)) * 100 = 54.73006%
- 问题 11: (2677 / (2677 + 8659)) * 100 = 23.61503%
- 问题 13: (2050 / (2050 + 4164)) * 100 = 32.99002%
问题 7, 10, 11, 和 13 是低质量问题，因为它们的同类百分比低于60%。</pre>

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
SELECT problem_id
FROM Problems
WHERE likes / (likes + dislikes) < 0.6
ORDER BY problem_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2027. 转换字符串的最少操作次数](https://leetcode.cn/problems/minimum-moves-to-convert-string){#2027}

{{< tabs "2027" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMoves(self, s: str) -> int:
        ans = i = 0
        while i < len(s):
            if s[i] == "X":
                ans += 1
                i += 3
            else:
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumMoves(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'X') {
                ++ans;
                i += 2;
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
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X') {
                ++ans;
                i += 2;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumMoves(s string) (ans int) {
	for i := 0; i < len(s); i++ {
		if s[i] == 'X' {
			ans++
			i += 2
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMoves(s: string): number {
    const n = s.length;
    let ans = 0;
    let i = 0;
    while (i < n) {
        if (s[i] === 'X') {
            ans++;
            i += 3;
        } else {
            i++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_moves(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            if s[i] == b'X' {
                ans += 1;
                i += 3;
            } else {
                i += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minimumMoves(char* s) {
    int n = strlen(s);
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == 'X') {
            ans++;
            i += 3;
        } else {
            i++;
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

<p>给你一个字符串 <code>s</code> ，由 <code>n</code> 个字符组成，每个字符不是 <code>'X'</code> 就是 <code>'O'</code> 。</p>

<p>一次<strong> 操作</strong> 定义为从 <code>s</code> 中选出 <strong>三个连续字符 </strong>并将选中的每个字符都转换为 <code>'O'</code> 。注意，如果字符已经是 <code>'O'</code> ，只需要保持 <strong>不变</strong> 。</p>

<p>返回将 <code>s</code> 中所有字符均转换为 <code>'O'</code> 需要执行的&nbsp;<strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "XXX"
<strong>输出：</strong>1
<strong>解释：<em>XXX</em></strong> -&gt; OOO
一次操作，选中全部 3 个字符，并将它们转换为 <code>'O' 。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "XXOX"
<strong>输出：</strong>2
<strong>解释：<em>XXO</em></strong>X -&gt; O<em><strong>OOX</strong></em> -&gt; OOOO
第一次操作，选择前 3 个字符，并将这些字符转换为 <code>'O'</code> 。
然后，选中后 3 个字符，并执行转换。最终得到的字符串全由字符 <code>'O'</code> 组成。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "OOOO"
<strong>输出：</strong>0
<strong>解释：</strong>s 中不存在需要转换的 <code>'X' 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 为 <code>'X'</code> 或 <code>'O'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

遍历字符串 $s$，只要遇到 `'X'`，指针 $i$ 就直接往后移动三格，并且答案加 $1$；否则指针 $i$ 往后移动一格。

时间复杂度 $O(n)$。其中 $n$ 表示字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoves(self, s: str) -> int:
        ans = i = 0
        while i < len(s):
            if s[i] == "X":
                ans += 1
                i += 3
            else:
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int minimumMoves(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'X') {
                ++ans;
                i += 2;
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
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X') {
                ++ans;
                i += 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumMoves(s string) (ans int) {
	for i := 0; i < len(s); i++ {
		if s[i] == 'X' {
			ans++
			i += 2
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumMoves(s: string): number {
    const n = s.length;
    let ans = 0;
    let i = 0;
    while (i < n) {
        if (s[i] === 'X') {
            ans++;
            i += 3;
        } else {
            i++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_moves(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            if s[i] == b'X' {
                ans += 1;
                i += 3;
            } else {
                i += 1;
            }
        }
        ans
    }
}
```

#### C

```c
int minimumMoves(char* s) {
    int n = strlen(s);
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == 'X') {
            ans++;
            i += 3;
        } else {
            i++;
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

# [2028. 找出缺失的观测数据](https://leetcode.cn/problems/find-missing-observations){#2028}

{{< tabs "2028" >}}

{{% tab "python" %}}
```python
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = (n + m) * mean - sum(rolls)
        if s > n * 6 or s < n:
            return []
        ans = [s // n] * n
        for i in range(s % n):
            ans[i] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int s = (n + m) * mean;
        for (int v : rolls) {
            s -= v;
        }
        if (s > n * 6 || s < n) {
            return new int[0];
        }
        int[] ans = new int[n];
        Arrays.fill(ans, s / n);
        for (int i = 0; i < s % n; ++i) {
            ++ans[i];
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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int s = (n + m) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (s > n * 6 || s < n) {
            return {};
        }
        vector<int> ans(n, s / n);
        for (int i = 0; i < s % n; ++i) {
            ++ans[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func missingRolls(rolls []int, mean int, n int) []int {
	m := len(rolls)
	s := (n + m) * mean
	for _, v := range rolls {
		s -= v
	}
	if s > n*6 || s < n {
		return []int{}
	}
	ans := make([]int, n)
	for i, j := 0, 0; i < n; i, j = i+1, j+1 {
		ans[i] = s / n
		if j < s%n {
			ans[i]++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function missingRolls(rolls: number[], mean: number, n: number): number[] {
    const m = rolls.length;
    const s = (n + m) * mean - rolls.reduce((a, b) => a + b, 0);
    if (s > n * 6 || s < n) {
        return [];
    }
    const ans: number[] = Array(n).fill((s / n) | 0);
    for (let i = 0; i < s % n; ++i) {
        ans[i]++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn missing_rolls(rolls: Vec<i32>, mean: i32, n: i32) -> Vec<i32> {
        let m = rolls.len() as i32;
        let s = (n + m) * mean - rolls.iter().sum::<i32>();

        if s > n * 6 || s < n {
            return vec![];
        }

        let mut ans = vec![s / n; n as usize];
        for i in 0..(s % n) as usize {
            ans[i] += 1;
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

<p>现有一份 <code>n + m</code>&nbsp;次投掷单个<strong> 六面</strong> 骰子的观测数据，骰子的每个面从 <code>1</code> 到 <code>6</code> 编号。观测数据中缺失了 <code>n</code> 份，你手上只拿到剩余&nbsp;<code>m</code> 次投掷的数据。幸好你有之前计算过的这 <code>n + m</code> 次投掷数据的 <strong>平均值</strong> 。</p>

<p>给你一个长度为 <code>m</code> 的整数数组 <code>rolls</code> ，其中&nbsp;<code>rolls[i]</code> 是第 <code>i</code> 次观测的值。同时给你两个整数 <code>mean</code> 和 <code>n</code> 。</p>

<p>返回一个长度为<em> </em><code>n</code><em> </em>的数组，包含所有缺失的观测数据，且满足这<em> </em><code>n + m</code><em> </em>次投掷的 <strong>平均值</strong> 是<em> </em><code>mean</code> 。如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。</p>

<p><code>k</code>&nbsp;个数字的 <strong>平均值</strong> 为这些数字求和后再除以&nbsp;<code>k</code> 。</p>

<p>注意 <code>mean</code> 是一个整数，所以 <code>n + m</code> 次投掷的总和需要被&nbsp;<code>n + m</code>&nbsp;整除。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rolls = [3,2,4,3], mean = 4, n = 2
<strong>输出：</strong>[6,6]
<strong>解释：</strong>所有 n + m 次投掷的平均值是 (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rolls = [1,5,6], mean = 3, n = 4
<strong>输出：</strong>[2,3,2,2]
<strong>解释：</strong>所有 n + m 次投掷的平均值是 (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rolls = [1,2,3,4], mean = 6, n = 4
<strong>输出：</strong>[]
<strong>解释：</strong>无论丢失的 4 次数据是什么，平均值都不可能是 6 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>rolls = [1], mean = 3, n = 1
<strong>输出：</strong>[5]
<strong>解释：</strong>所有 n + m 次投掷的平均值是 (1 + 5) / 2 = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == rolls.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= rolls[i], mean &lt;= 6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：构造

根据题目描述，所有数字之和为 $(n + m) \times \textit{mean}$，已知的数字之和为 $\sum_{i=0}^{m-1} \textit{rolls}[i]$，那么缺失的数字之和为 $s = (n + m) \times \textit{mean} - \sum_{i=0}^{m-1} \textit{rolls}[i]$。

如果 $s \gt n \times 6$ 或者 $s \lt n$，说明不存在满足条件的答案，返回空数组。

否则，我们可以将 $s$ 平均分配到 $n$ 个数字上，即每个数字的值为 $s / n$，其中 $s \bmod n$ 个数字的值再加上 $1$。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别为缺失的数字个数和已知的数字个数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = (n + m) * mean - sum(rolls)
        if s > n * 6 or s < n:
            return []
        ans = [s // n] * n
        for i in range(s % n):
            ans[i] += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int s = (n + m) * mean;
        for (int v : rolls) {
            s -= v;
        }
        if (s > n * 6 || s < n) {
            return new int[0];
        }
        int[] ans = new int[n];
        Arrays.fill(ans, s / n);
        for (int i = 0; i < s % n; ++i) {
            ++ans[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int s = (n + m) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (s > n * 6 || s < n) {
            return {};
        }
        vector<int> ans(n, s / n);
        for (int i = 0; i < s % n; ++i) {
            ++ans[i];
        }
        return ans;
    }
};
```

#### Go

```go
func missingRolls(rolls []int, mean int, n int) []int {
	m := len(rolls)
	s := (n + m) * mean
	for _, v := range rolls {
		s -= v
	}
	if s > n*6 || s < n {
		return []int{}
	}
	ans := make([]int, n)
	for i, j := 0, 0; i < n; i, j = i+1, j+1 {
		ans[i] = s / n
		if j < s%n {
			ans[i]++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function missingRolls(rolls: number[], mean: number, n: number): number[] {
    const m = rolls.length;
    const s = (n + m) * mean - rolls.reduce((a, b) => a + b, 0);
    if (s > n * 6 || s < n) {
        return [];
    }
    const ans: number[] = Array(n).fill((s / n) | 0);
    for (let i = 0; i < s % n; ++i) {
        ans[i]++;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn missing_rolls(rolls: Vec<i32>, mean: i32, n: i32) -> Vec<i32> {
        let m = rolls.len() as i32;
        let s = (n + m) * mean - rolls.iter().sum::<i32>();

        if s > n * 6 || s < n {
            return vec![];
        }

        let mut ans = vec![s / n; n as usize];
        for i in 0..(s % n) as usize {
            ans[i] += 1;
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

# [2029. 石子游戏 IX](https://leetcode.cn/problems/stone-game-ix){#2029}

{{< tabs "2029" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        def check(cnt: List[int]) -> bool:
            if cnt[1] == 0:
                return False
            cnt[1] -= 1
            r = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0]
            if cnt[1] > cnt[2]:
                cnt[1] -= 1
                r += 1
            return r % 2 == 1 and cnt[1] != cnt[2]

        c1 = [0] * 3
        for x in stones:
            c1[x % 3] += 1
        c2 = [c1[0], c1[2], c1[1]]
        return check(c1) or check(c2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean stoneGameIX(int[] stones) {
        int[] c1 = new int[3];
        for (int x : stones) {
            c1[x % 3]++;
        }
        int[] c2 = {c1[0], c1[2], c1[1]};
        return check(c1) || check(c2);
    }

    private boolean check(int[] cnt) {
        if (--cnt[1] < 0) {
            return false;
        }
        int r = 1 + Math.min(cnt[1], cnt[2]) * 2 + cnt[0];
        if (cnt[1] > cnt[2]) {
            --cnt[1];
            ++r;
        }
        return r % 2 == 1 && cnt[1] != cnt[2];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c1(3);
        for (int x : stones) {
            ++c1[x % 3];
        }
        vector<int> c2 = {c1[0], c1[2], c1[1]};
        auto check = [](auto& cnt) -> bool {
            if (--cnt[1] < 0) {
                return false;
            }
            int r = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0];
            if (cnt[1] > cnt[2]) {
                --cnt[1];
                ++r;
            }
            return r % 2 && cnt[1] != cnt[2];
        };
        return check(c1) || check(c2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameIX(stones []int) bool {
	c1 := [3]int{}
	for _, x := range stones {
		c1[x%3]++
	}
	c2 := [3]int{c1[0], c1[2], c1[1]}
	check := func(cnt [3]int) bool {
		if cnt[1] == 0 {
			return false
		}
		cnt[1]--
		r := 1 + min(cnt[1], cnt[2])*2 + cnt[0]
		if cnt[1] > cnt[2] {
			cnt[1]--
			r++
		}
		return r%2 == 1 && cnt[1] != cnt[2]
	}
	return check(c1) || check(c2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameIX(stones: number[]): boolean {
    if (stones.length === 1) return false;

    const cnt = Array(3).fill(0);
    for (const x of stones) cnt[x % 3]++;

    const check = (x: number, cnt: number[]): boolean => {
        let c = 1;
        if (--cnt[x] < 0) return false;

        while (cnt[1] || cnt[2]) {
            if (cnt[x]) {
                cnt[x]--;
                x = x === 1 ? 2 : 1;
            } else return (c + cnt[0]) % 2 === 1;
            c++;
        }

        return false;
    };

    return check(1, [...cnt]) || check(2, [...cnt]);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function stoneGameIX(stones) {
    if (stones.length === 1) return false;

    const cnt = Array(3).fill(0);
    for (const x of stones) cnt[x % 3]++;

    const check = (x, cnt) => {
        let c = 1;
        if (--cnt[x] < 0) return false;

        while (cnt[1] || cnt[2]) {
            if (cnt[x]) {
                cnt[x]--;
                x = x === 1 ? 2 : 1;
            } else return (c + cnt[0]) % 2 === 1;
            c++;
        }

        return false;
    };

    return check(1, [...cnt]) || check(2, [...cnt]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 再次设计了一款新的石子游戏。现有一行 n 个石子，每个石子都有一个关联的数字表示它的价值。给你一个整数数组 <code>stones</code> ，其中 <code>stones[i]</code> 是第 <code>i</code> 个石子的价值。</p>

<p>Alice 和 Bob 轮流进行自己的回合，<strong>Alice</strong> 先手。每一回合，玩家需要从 <code>stones</code>&nbsp;中移除任一石子。</p>

<ul>
	<li>如果玩家移除石子后，导致 <strong>所有已移除石子</strong> 的价值&nbsp;<strong>总和</strong> 可以被 3 整除，那么该玩家就 <strong>输掉游戏</strong> 。</li>
	<li>如果不满足上一条，且移除后没有任何剩余的石子，那么 Bob 将会直接获胜（即便是在 Alice 的回合）。</li>
</ul>

<p>假设两位玩家均采用&nbsp;<strong>最佳</strong> 决策。如果 Alice 获胜，返回 <code>true</code> ；如果 Bob 获胜，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stones = [2,1]
<strong>输出：</strong>true
<strong>解释：</strong>游戏进行如下：
- 回合 1：Alice 可以移除任意一个石子。
- 回合 2：Bob 移除剩下的石子。 
已移除的石子的值总和为 1 + 2 = 3 且可以被 3 整除。因此，Bob 输，Alice 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stones = [2]
<strong>输出：</strong>false
<strong>解释：</strong>Alice 会移除唯一一个石子，已移除石子的值总和为 2 。 
由于所有石子都已移除，且值总和无法被 3 整除，Bob 获胜。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>stones = [5,1,2,4,3]
<strong>输出：</strong>false
<strong>解释：</strong>Bob 总会获胜。其中一种可能的游戏进行方式如下：
- 回合 1：Alice 可以移除值为 1 的第 2 个石子。已移除石子值总和为 1 。
- 回合 2：Bob 可以移除值为 3 的第 5 个石子。已移除石子值总和为 = 1 + 3 = 4 。
- 回合 3：Alices 可以移除值为 4 的第 4 个石子。已移除石子值总和为 = 1 + 3 + 4 = 8 。
- 回合 4：Bob 可以移除值为 2 的第 3 个石子。已移除石子值总和为 = 1 + 3 + 4 + 2 = 10.
- 回合 5：Alice 可以移除值为 5 的第 1 个石子。已移除石子值总和为 = 1 + 3 + 4 + 2 + 5 = 15.
Alice 输掉游戏，因为已移除石子值总和（15）可以被 3 整除，Bob 获胜。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= stones.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 分情况讨论

由于玩家的目标是使得已移除石子的价值总和不能被 $3$ 整除，因此我们只需要考虑每个石子的价值对 $3$ 的余数即可。

我们用一个长度为 $3$ 的数组 $\textit{cnt}$ 维护当前剩余石子的价值对 $3$ 的余数的个数，其中 $\textit{cnt}[0]$ 表示余数为 $0$ 的个数，而 $\textit{cnt}[1]$ 和 $\textit{cnt}[2]$ 分别表示余数为 $1$ 和 $2$ 的个数。

在第一回合，Alice 不能移除余数为 $0$ 的石子，因为这样会使得已移除石子的价值总和能被 $3$ 整除。因此，Alice 只能移除余数为 $1$ 或 $2$ 的石子。

我们首先考虑 Alice 移除余数为 $1$ 的石子的情况。如果 Alice 移除了一个余数为 $1$ 的石子，石子 $0$ 对石子价值总和对 $3$ 的余数不会改变，因此价值对 $3$ 的余数为 $0$ 的石子可以在任意回合被移除，我们暂时不考虑。所以 Bob 也只能移除余数为 $1$ 的石子，之后 Alice 移除余数为 $2$ 的石子，依次进行，序列为 $1, 1, 2, 1, 2, \ldots$。在这种情况下，如果最终回合数为奇数，且还有剩余石子，那么 Alice 获胜，否则 Bob 获胜。

对于第一回合 Alice 移除余数为 $2$ 的石子的情况，我们可以得到类似的结论。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{stones}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        def check(cnt: List[int]) -> bool:
            if cnt[1] == 0:
                return False
            cnt[1] -= 1
            r = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0]
            if cnt[1] > cnt[2]:
                cnt[1] -= 1
                r += 1
            return r % 2 == 1 and cnt[1] != cnt[2]

        c1 = [0] * 3
        for x in stones:
            c1[x % 3] += 1
        c2 = [c1[0], c1[2], c1[1]]
        return check(c1) or check(c2)
```

#### Java

```java
class Solution {
    public boolean stoneGameIX(int[] stones) {
        int[] c1 = new int[3];
        for (int x : stones) {
            c1[x % 3]++;
        }
        int[] c2 = {c1[0], c1[2], c1[1]};
        return check(c1) || check(c2);
    }

    private boolean check(int[] cnt) {
        if (--cnt[1] < 0) {
            return false;
        }
        int r = 1 + Math.min(cnt[1], cnt[2]) * 2 + cnt[0];
        if (cnt[1] > cnt[2]) {
            --cnt[1];
            ++r;
        }
        return r % 2 == 1 && cnt[1] != cnt[2];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c1(3);
        for (int x : stones) {
            ++c1[x % 3];
        }
        vector<int> c2 = {c1[0], c1[2], c1[1]};
        auto check = [](auto& cnt) -> bool {
            if (--cnt[1] < 0) {
                return false;
            }
            int r = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0];
            if (cnt[1] > cnt[2]) {
                --cnt[1];
                ++r;
            }
            return r % 2 && cnt[1] != cnt[2];
        };
        return check(c1) || check(c2);
    }
};
```

#### Go

```go
func stoneGameIX(stones []int) bool {
	c1 := [3]int{}
	for _, x := range stones {
		c1[x%3]++
	}
	c2 := [3]int{c1[0], c1[2], c1[1]}
	check := func(cnt [3]int) bool {
		if cnt[1] == 0 {
			return false
		}
		cnt[1]--
		r := 1 + min(cnt[1], cnt[2])*2 + cnt[0]
		if cnt[1] > cnt[2] {
			cnt[1]--
			r++
		}
		return r%2 == 1 && cnt[1] != cnt[2]
	}
	return check(c1) || check(c2)
}
```

#### TypeScript

```ts
function stoneGameIX(stones: number[]): boolean {
    const c1: number[] = Array(3).fill(0);
    for (const x of stones) {
        ++c1[x % 3];
    }
    const c2: number[] = [c1[0], c1[2], c1[1]];
    const check = (cnt: number[]): boolean => {
        if (--cnt[1] < 0) {
            return false;
        }
        let r = 1 + Math.min(cnt[1], cnt[2]) * 2 + cnt[0];
        if (cnt[1] > cnt[2]) {
            --cnt[1];
            ++r;
        }
        return r % 2 === 1 && cnt[1] !== cnt[2];
    };
    return check(c1) || check(c2);
}
```

#### JavaScript

```js
function stoneGameIX(stones) {
    const c1 = Array(3).fill(0);
    for (const x of stones) {
        ++c1[x % 3];
    }
    const c2 = [c1[0], c1[2], c1[1]];
    const check = cnt => {
        if (--cnt[1] < 0) {
            return false;
        }
        let r = 1 + Math.min(cnt[1], cnt[2]) * 2 + cnt[0];
        if (cnt[1] > cnt[2]) {
            --cnt[1];
            ++r;
        }
        return r % 2 === 1 && cnt[1] !== cnt[2];
    };
    return check(c1) || check(c2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Simulation

<!-- tabs:start -->

#### TypeScript

```ts
function stoneGameIX(stones: number[]): boolean {
    if (stones.length === 1) return false;

    const cnt = Array(3).fill(0);
    for (const x of stones) cnt[x % 3]++;

    const check = (x: number, cnt: number[]): boolean => {
        let c = 1;
        if (--cnt[x] < 0) return false;

        while (cnt[1] || cnt[2]) {
            if (cnt[x]) {
                cnt[x]--;
                x = x === 1 ? 2 : 1;
            } else return (c + cnt[0]) % 2 === 1;
            c++;
        }

        return false;
    };

    return check(1, [...cnt]) || check(2, [...cnt]);
}
```

#### JavaScript

```js
function stoneGameIX(stones) {
    if (stones.length === 1) return false;

    const cnt = Array(3).fill(0);
    for (const x of stones) cnt[x % 3]++;

    const check = (x, cnt) => {
        let c = 1;
        if (--cnt[x] < 0) return false;

        while (cnt[1] || cnt[2]) {
            if (cnt[x]) {
                cnt[x]--;
                x = x === 1 ? 2 : 1;
            } else return (c + cnt[0]) % 2 === 1;
            c++;
        }

        return false;
    };

    return check(1, [...cnt]) || check(2, [...cnt]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
