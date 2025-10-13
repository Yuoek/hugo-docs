---
title: "1050_合作过至少三次的演员和导演"
date: 2025-10-08T18:36:50+08:00
weight: 6
tags: [二分查找, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 拓扑排序, 排序, 数学, 数据库, 数组, 滑动窗口, 计数, 计数排序, 贪心]
---

{{< markmap >}}
### [1050_合作过至少三次的演员和导演](#1050)
#### [数据库](#1050)
### [1051_高度检查器](#1051)
#### [数组](#1051)
#### [计数排序](#1051)
#### [排序](#1051)
### [1052_爱生气的书店老板](#1052)
#### [数组](#1052)
#### [滑动窗口](#1052)
### [1053_交换一次的先前排列](#1053)
#### [贪心](#1053)
#### [数组](#1053)
### [1054_距离相等的条形码](#1054)
#### [贪心](#1054)
#### [数组](#1054)
#### [哈希表](#1054)
#### [计数](#1054)
#### [排序](#1054)
#### [堆（优先队列）](#1054)
### [1055_形成字符串的最短路径 🔒](#1055)
#### [贪心](#1055)
#### [双指针](#1055)
#### [字符串](#1055)
#### [二分查找](#1055)
### [1056_易混淆数 🔒](#1056)
#### [数学](#1056)
### [1057_校园自行车分配 🔒](#1057)
#### [数组](#1057)
#### [排序](#1057)
#### [堆（优先队列）](#1057)
### [1058_最小化舍入误差以满足目标 🔒](#1058)
#### [贪心](#1058)
#### [数组](#1058)
#### [数学](#1058)
#### [字符串](#1058)
#### [排序](#1058)
### [1059_从始点到终点的所有路径 🔒](#1059)
#### [图](#1059)
#### [拓扑排序](#1059)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1050_合作过至少三次的演员和导演
___
#### 数据库
---
### 1051_高度检查器
___
#### 数组
___
#### 计数排序
___
#### 排序
---
### 1052_爱生气的书店老板
___
#### 数组
___
#### 滑动窗口
---
### 1053_交换一次的先前排列
___
#### 贪心
___
#### 数组
---
### 1054_距离相等的条形码
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
___
#### 堆（优先队列）
---
### 1055_形成字符串的最短路径 🔒
___
#### 贪心
___
#### 双指针
___
#### 字符串
___
#### 二分查找
---
### 1056_易混淆数 🔒
___
#### 数学
---
### 1057_校园自行车分配 🔒
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 1058_最小化舍入误差以满足目标 🔒
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 字符串
___
#### 排序
---
### 1059_从始点到终点的所有路径 🔒
___
#### 图
___
#### 拓扑排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 拓扑排序 | 排序 | 数学 |
| 数据库 | 数组 | 滑动窗口 |
| 计数 | 计数排序 | 贪心 |

# [1050. 合作过至少三次的演员和导演](https://leetcode.cn/problems/actors-and-directors-who-cooperated-at-least-three-times){#1050}

{{< tabs "1050" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY 1, 2
HAVING COUNT(1) >= 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>ActorDirector</code>&nbsp;表：</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp 是这张表的主键(具有唯一值的列).
</pre>

<p>&nbsp;</p>

<p>编写解决方案找出合作过至少三次的演员和导演的 id 对&nbsp;<code>(actor_id, director_id)</code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
ActorDirector 表：
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
<strong>输出：</strong>
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
<strong>解释：</strong>
唯一的 id 对是 (1, 1)，他们恰好合作了 3 次。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们可以使用 `GROUP BY` 语句，按照 `actor_id` 和 `director_id` 字段进行分组，然后使用 `HAVING` 语句，筛选出现次数大于等于 $3$ 的 `actor_id` 和 `director_id`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY 1, 2
HAVING COUNT(1) >= 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1051. 高度检查器](https://leetcode.cn/problems/height-checker){#1051}

{{< tabs "1051" >}}

{{% tab "python" %}}
```python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        cnt = [0] * 101
        for h in heights:
            cnt[h] += 1
        ans = i = 0
        for j in range(1, 101):
            while cnt[j]:
                cnt[j] -= 1
                if heights[i] != j:
                    ans += 1
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] cnt = new int[101];
        for (int h : heights) {
            ++cnt[h];
        }
        int ans = 0;
        for (int i = 0, j = 0; i < 101; ++i) {
            while (cnt[i] > 0) {
                --cnt[i];
                if (heights[j++] != i) {
                    ++ans;
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
    int heightChecker(vector<int>& heights) {
        vector<int> cnt(101);
        for (int& h : heights) ++cnt[h];
        int ans = 0;
        for (int i = 0, j = 0; i < 101; ++i) {
            while (cnt[i]) {
                --cnt[i];
                if (heights[j++] != i) ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func heightChecker(heights []int) int {
	cnt := make([]int, 101)
	for _, h := range heights {
		cnt[h]++
	}
	ans := 0
	for i, j := 0, 0; i < 101; i++ {
		for cnt[i] > 0 {
			cnt[i]--
			if heights[j] != i {
				ans++
			}
			j++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function heightChecker(heights: number[]): number {
    const cnt = Array(101).fill(0);
    for (const i of heights) {
        cnt[i]++;
    }
    let ans = 0;
    for (let j = 1, i = 0; j < 101; j++) {
        while (cnt[j]--) {
            if (heights[i++] !== j) {
                ans++;
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

<p>学校打算为全体学生拍一张年度纪念照。根据要求，学生需要按照 <strong>非递减</strong> 的高度顺序排成一行。</p>

<p>排序后的高度情况用整数数组 <code>expected</code> 表示，其中 <code>expected[i]</code> 是预计排在这一行中第 <code>i</code> 位的学生的高度（<strong>下标从 0 开始</strong>）。</p>

<p>给你一个整数数组 <code>heights</code> ，表示 <strong>当前学生站位</strong> 的高度情况。<code>heights[i]</code> 是这一行中第 <code>i</code> 位学生的高度（<strong>下标从 0 开始</strong>）。</p>

<p>返回满足<em> </em><code>heights[i] != expected[i]</code> 的 <strong>下标数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>heights =&nbsp;[1,1,4,2,1,3]
<strong>输出：</strong>3 
<strong>解释：</strong>
高度：[1,1,<em><strong>4</strong></em>,2,<em><strong>1</strong></em>,<em><strong>3</strong></em>]
预期：[1,1,<em><strong>1</strong></em>,2,<em><strong>3</strong></em>,<em><strong>4</strong></em>]
下标 2 、4 、5 处的学生高度不匹配。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>heights = [5,1,2,3,4]
<strong>输出：</strong>5
<strong>解释：</strong>
高度：[<em><strong>5</strong></em>,<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>3</strong></em>,<em><strong>4</strong></em>]
预期：[<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>3</strong></em>,<em><strong>4</strong></em>,<em><strong>5</strong></em>]
所有下标的对应学生高度都不匹配。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>heights = [1,2,3,4,5]
<strong>输出：</strong>0
<strong>解释：</strong>
高度：[1,2,3,4,5]
预期：[1,2,3,4,5]
所有下标的对应学生高度都匹配。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 100</code></li>
	<li><code>1 &lt;= heights[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以先对学生的高度进行排序，然后比较排序后的高度和原始高度，统计不同的位置即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是学生的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        return sum(a != b for a, b in zip(heights, expected))
```

#### Java

```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] expected = heights.clone();
        Arrays.sort(expected);
        int ans = 0;
        for (int i = 0; i < heights.length; ++i) {
            if (heights[i] != expected[i]) {
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
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            ans += heights[i] != expected[i];
        }
        return ans;
    }
};
```

#### Go

```go
func heightChecker(heights []int) (ans int) {
	expected := slices.Clone(heights)
	sort.Ints(expected)
	for i, v := range heights {
		if v != expected[i] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function heightChecker(heights: number[]): number {
    const expected = [...heights].sort((a, b) => a - b);
    return heights.reduce((acc, cur, i) => acc + (cur !== expected[i] ? 1 : 0), 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数排序

由于题目中学生高度不超过 $100$，因此可以使用计数排序。这里我们用一个长度 $101$ 的数组 $cnt$ 统计每个高度 $h_i$ 出现的次数。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 是学生的数量，而 $M$ 是学生的最大高度，本题中 $M = 101$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        cnt = [0] * 101
        for h in heights:
            cnt[h] += 1
        ans = i = 0
        for j in range(1, 101):
            while cnt[j]:
                cnt[j] -= 1
                if heights[i] != j:
                    ans += 1
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] cnt = new int[101];
        for (int h : heights) {
            ++cnt[h];
        }
        int ans = 0;
        for (int i = 0, j = 0; i < 101; ++i) {
            while (cnt[i] > 0) {
                --cnt[i];
                if (heights[j++] != i) {
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
    int heightChecker(vector<int>& heights) {
        vector<int> cnt(101);
        for (int& h : heights) ++cnt[h];
        int ans = 0;
        for (int i = 0, j = 0; i < 101; ++i) {
            while (cnt[i]) {
                --cnt[i];
                if (heights[j++] != i) ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func heightChecker(heights []int) int {
	cnt := make([]int, 101)
	for _, h := range heights {
		cnt[h]++
	}
	ans := 0
	for i, j := 0, 0; i < 101; i++ {
		for cnt[i] > 0 {
			cnt[i]--
			if heights[j] != i {
				ans++
			}
			j++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function heightChecker(heights: number[]): number {
    const cnt = Array(101).fill(0);
    for (const i of heights) {
        cnt[i]++;
    }
    let ans = 0;
    for (let j = 1, i = 0; j < 101; j++) {
        while (cnt[j]--) {
            if (heights[i++] !== j) {
                ans++;
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

# [1052. 爱生气的书店老板](https://leetcode.cn/problems/grumpy-bookstore-owner){#1052}

{{< tabs "1052" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSatisfied(
        self, customers: List[int], grumpy: List[int], minutes: int
    ) -> int:
        mx = cnt = sum(c * g for c, g in zip(customers[:minutes], grumpy))
        for i in range(minutes, len(customers)):
            cnt += customers[i] * grumpy[i]
            cnt -= customers[i - minutes] * grumpy[i - minutes]
            mx = max(mx, cnt)
        return sum(c * (g ^ 1) for c, g in zip(customers, grumpy)) + mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int cnt = 0;
        int tot = 0;
        for (int i = 0; i < minutes; ++i) {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        int mx = cnt;
        int n = customers.length;
        for (int i = minutes; i < n; ++i) {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = Math.max(mx, cnt);
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        return tot + mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cnt = 0;
        int tot = 0;
        for (int i = 0; i < minutes; ++i) {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        int mx = cnt;
        int n = customers.size();
        for (int i = minutes; i < n; ++i) {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = max(mx, cnt);
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        return tot + mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSatisfied(customers []int, grumpy []int, minutes int) int {
	var cnt, tot int
	for i, c := range customers[:minutes] {
		cnt += c * grumpy[i]
		tot += c * (grumpy[i] ^ 1)
	}
	mx := cnt
	for i := minutes; i < len(customers); i++ {
		cnt += customers[i] * grumpy[i]
		cnt -= customers[i-minutes] * grumpy[i-minutes]
		mx = max(mx, cnt)
		tot += customers[i] * (grumpy[i] ^ 1)
	}
	return tot + mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSatisfied(customers: number[], grumpy: number[], minutes: number): number {
    let [cnt, tot] = [0, 0];
    for (let i = 0; i < minutes; ++i) {
        cnt += customers[i] * grumpy[i];
        tot += customers[i] * (grumpy[i] ^ 1);
    }
    let mx = cnt;
    for (let i = minutes; i < customers.length; ++i) {
        cnt += customers[i] * grumpy[i];
        cnt -= customers[i - minutes] * grumpy[i - minutes];
        mx = Math.max(mx, cnt);
        tot += customers[i] * (grumpy[i] ^ 1);
    }
    return tot + mx;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let mut cnt = 0;
        let mut tot = 0;
        let minutes = minutes as usize;
        for i in 0..minutes {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (1 - grumpy[i]);
        }
        let mut mx = cnt;
        let n = customers.len();
        for i in minutes..n {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = mx.max(cnt);
            tot += customers[i] * (1 - grumpy[i]);
        }
        tot + mx
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个书店老板，他的书店开了&nbsp;<code>n</code>&nbsp;分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 <code>n</code> 的整数数组 <code>customers</code> ，其中 <code>customers[i]</code> 是在第 <code>i</code> 分钟开始时进入商店的顾客数量，所有这些顾客在第 <code>i</code> 分钟结束后离开。</p>

<p>在某些分钟内，书店老板会生气。 如果书店老板在第 <code>i</code> 分钟生气，那么 <code>grumpy[i] = 1</code>，否则 <code>grumpy[i] = 0</code>。</p>

<p>当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。</p>

<p>书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续&nbsp;<code>minutes</code>&nbsp;分钟不生气，但却只能使用一次。</p>

<p>请你返回 <em>这一天营业下来，最多有多少客户能够感到满意</em> 。<br />
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
<strong>输出：</strong>16
<strong>解释：</strong>书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>customers = [1], grumpy = [0], minutes = 1
<strong>输出：</strong>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == customers.length == grumpy.length</code></li>
	<li><code>1 &lt;= minutes &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= customers[i] &lt;= 1000</code></li>
	<li><code>grumpy[i] == 0 or 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

根据题目描述，我们只需要统计老板不生气时的客户数量 $tot$，再加上一个大小为 `minutes` 的滑动窗口中，老板生气时的客户数量的最大值 $mx$ 即可。

我们定义一个变量 $cnt$ 来记录滑动窗口中老板生气时的客户数量，初始值为前 `minutes` 分钟老板生气时的客户数量。然后我们遍历数组，每次移动滑动窗口时，更新 $cnt$ 的值，同时更新 $mx$ 的值。

最后返回 $tot + mx$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 `customers` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSatisfied(
        self, customers: List[int], grumpy: List[int], minutes: int
    ) -> int:
        mx = cnt = sum(c * g for c, g in zip(customers[:minutes], grumpy))
        for i in range(minutes, len(customers)):
            cnt += customers[i] * grumpy[i]
            cnt -= customers[i - minutes] * grumpy[i - minutes]
            mx = max(mx, cnt)
        return sum(c * (g ^ 1) for c, g in zip(customers, grumpy)) + mx
```

#### Java

```java
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int cnt = 0;
        int tot = 0;
        for (int i = 0; i < minutes; ++i) {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        int mx = cnt;
        int n = customers.length;
        for (int i = minutes; i < n; ++i) {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = Math.max(mx, cnt);
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        return tot + mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cnt = 0;
        int tot = 0;
        for (int i = 0; i < minutes; ++i) {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        int mx = cnt;
        int n = customers.size();
        for (int i = minutes; i < n; ++i) {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = max(mx, cnt);
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        return tot + mx;
    }
};
```

#### Go

```go
func maxSatisfied(customers []int, grumpy []int, minutes int) int {
	var cnt, tot int
	for i, c := range customers[:minutes] {
		cnt += c * grumpy[i]
		tot += c * (grumpy[i] ^ 1)
	}
	mx := cnt
	for i := minutes; i < len(customers); i++ {
		cnt += customers[i] * grumpy[i]
		cnt -= customers[i-minutes] * grumpy[i-minutes]
		mx = max(mx, cnt)
		tot += customers[i] * (grumpy[i] ^ 1)
	}
	return tot + mx
}
```

#### TypeScript

```ts
function maxSatisfied(customers: number[], grumpy: number[], minutes: number): number {
    let [cnt, tot] = [0, 0];
    for (let i = 0; i < minutes; ++i) {
        cnt += customers[i] * grumpy[i];
        tot += customers[i] * (grumpy[i] ^ 1);
    }
    let mx = cnt;
    for (let i = minutes; i < customers.length; ++i) {
        cnt += customers[i] * grumpy[i];
        cnt -= customers[i - minutes] * grumpy[i - minutes];
        mx = Math.max(mx, cnt);
        tot += customers[i] * (grumpy[i] ^ 1);
    }
    return tot + mx;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let mut cnt = 0;
        let mut tot = 0;
        let minutes = minutes as usize;
        for i in 0..minutes {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (1 - grumpy[i]);
        }
        let mut mx = cnt;
        let n = customers.len();
        for i in minutes..n {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = mx.max(cnt);
            tot += customers[i] * (1 - grumpy[i]);
        }
        tot + mx
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1053. 交换一次的先前排列](https://leetcode.cn/problems/previous-permutation-with-one-swap){#1053}

{{< tabs "1053" >}}

{{% tab "python" %}}
```python
class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr)
        for i in range(n - 1, 0, -1):
            if arr[i - 1] > arr[i]:
                for j in range(n - 1, i - 1, -1):
                    if arr[j] < arr[i - 1] and arr[j] != arr[j - 1]:
                        arr[i - 1], arr[j] = arr[j], arr[i - 1]
                        return arr
        return arr
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int n = arr.length;
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i - 1] && arr[j] != arr[j - 1]) {
                        int t = arr[i - 1];
                        arr[i - 1] = arr[j];
                        arr[j] = t;
                        return arr;
                    }
                }
            }
        }
        return arr;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i - 1] && arr[j] != arr[j - 1]) {
                        swap(arr[i - 1], arr[j]);
                        return arr;
                    }
                }
            }
        }
        return arr;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func prevPermOpt1(arr []int) []int {
	n := len(arr)
	for i := n - 1; i > 0; i-- {
		if arr[i-1] > arr[i] {
			for j := n - 1; j > i-1; j-- {
				if arr[j] < arr[i-1] && arr[j] != arr[j-1] {
					arr[i-1], arr[j] = arr[j], arr[i-1]
					return arr
				}
			}
		}
	}
	return arr
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function prevPermOpt1(arr: number[]): number[] {
    const n = arr.length;
    for (let i = n - 1; i > 0; --i) {
        if (arr[i - 1] > arr[i]) {
            for (let j = n - 1; j > i - 1; --j) {
                if (arr[j] < arr[i - 1] && arr[j] !== arr[j - 1]) {
                    const t = arr[i - 1];
                    arr[i - 1] = arr[j];
                    arr[j] = t;
                    return arr;
                }
            }
        }
    }
    return arr;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>arr</code>（可能存在重复的元素），请你返回可在&nbsp;<strong>一次交换</strong>（交换两数字 <code>arr[i]</code> 和 <code>arr[j]</code> 的位置）后得到的、按<span data-keyword="lexicographically-smaller-string-alien">字典序</span>排列小于 <code>arr</code> 的最大排列。</p>

<p>如果无法这么操作，就请返回原数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,2,1]
<strong>输出：</strong>[3,1,2]
<strong>解释：</strong>交换 2 和 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,5]
<strong>输出：</strong>[1,1,5]
<strong>解释：</strong>已经是最小排列
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,9,4,6,7]
<strong>输出：</strong>[1,7,4,6,9]
<strong>解释：</strong>交换 9 和 7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先从右到左遍历数组，找到第一个满足 $arr[i - 1] \gt arr[i]$ 的下标 $i$，此时 $arr[i - 1]$ 就是我们要交换的数字，我们再从右到左遍历数组，找到第一个满足 $arr[j] \lt arr[i - 1]$ 且 $arr[j] \neq arr[j - 1]$ 的下标 $j$，此时我们交换 $arr[i - 1]$ 和 $arr[j]$ 后返回即可。

如果遍历完数组都没有找到满足条件的下标 $i$，说明数组已经是最小排列，直接返回原数组即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr)
        for i in range(n - 1, 0, -1):
            if arr[i - 1] > arr[i]:
                for j in range(n - 1, i - 1, -1):
                    if arr[j] < arr[i - 1] and arr[j] != arr[j - 1]:
                        arr[i - 1], arr[j] = arr[j], arr[i - 1]
                        return arr
        return arr
```

#### Java

```java
class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int n = arr.length;
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i - 1] && arr[j] != arr[j - 1]) {
                        int t = arr[i - 1];
                        arr[i - 1] = arr[j];
                        arr[j] = t;
                        return arr;
                    }
                }
            }
        }
        return arr;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i - 1] && arr[j] != arr[j - 1]) {
                        swap(arr[i - 1], arr[j]);
                        return arr;
                    }
                }
            }
        }
        return arr;
    }
};
```

#### Go

```go
func prevPermOpt1(arr []int) []int {
	n := len(arr)
	for i := n - 1; i > 0; i-- {
		if arr[i-1] > arr[i] {
			for j := n - 1; j > i-1; j-- {
				if arr[j] < arr[i-1] && arr[j] != arr[j-1] {
					arr[i-1], arr[j] = arr[j], arr[i-1]
					return arr
				}
			}
		}
	}
	return arr
}
```

#### TypeScript

```ts
function prevPermOpt1(arr: number[]): number[] {
    const n = arr.length;
    for (let i = n - 1; i > 0; --i) {
        if (arr[i - 1] > arr[i]) {
            for (let j = n - 1; j > i - 1; --j) {
                if (arr[j] < arr[i - 1] && arr[j] !== arr[j - 1]) {
                    const t = arr[i - 1];
                    arr[i - 1] = arr[j];
                    arr[j] = t;
                    return arr;
                }
            }
        }
    }
    return arr;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1054. 距离相等的条形码](https://leetcode.cn/problems/distant-barcodes){#1054}

{{< tabs "1054" >}}

{{% tab "python" %}}
```python
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        cnt = Counter(barcodes)
        barcodes.sort(key=lambda x: (-cnt[x], x))
        n = len(barcodes)
        ans = [0] * len(barcodes)
        ans[::2] = barcodes[: (n + 1) // 2]
        ans[1::2] = barcodes[(n + 1) // 2 :]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int n = barcodes.length;
        Integer[] t = new Integer[n];
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            t[i] = barcodes[i];
            mx = Math.max(mx, barcodes[i]);
        }
        int[] cnt = new int[mx + 1];
        for (int x : barcodes) {
            ++cnt[x];
        }
        Arrays.sort(t, (a, b) -> cnt[a] == cnt[b] ? a - b : cnt[b] - cnt[a]);
        int[] ans = new int[n];
        for (int k = 0, j = 0; k < 2; ++k) {
            for (int i = k; i < n; i += 2) {
                ans[i] = t[j++];
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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int mx = *max_element(barcodes.begin(), barcodes.end());
        int cnt[mx + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int x : barcodes) {
            ++cnt[x];
        }
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        int n = barcodes.size();
        vector<int> ans(n);
        for (int k = 0, j = 0; k < 2; ++k) {
            for (int i = k; i < n; i += 2) {
                ans[i] = barcodes[j++];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rearrangeBarcodes(barcodes []int) []int {
	mx := slices.Max(barcodes)
	cnt := make([]int, mx+1)
	for _, x := range barcodes {
		cnt[x]++
	}
	sort.Slice(barcodes, func(i, j int) bool {
		a, b := barcodes[i], barcodes[j]
		if cnt[a] == cnt[b] {
			return a < b
		}
		return cnt[a] > cnt[b]
	})
	n := len(barcodes)
	ans := make([]int, n)
	for k, j := 0, 0; k < 2; k++ {
		for i := k; i < n; i, j = i+2, j+1 {
			ans[i] = barcodes[j]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rearrangeBarcodes(barcodes: number[]): number[] {
    const mx = Math.max(...barcodes);
    const cnt = Array(mx + 1).fill(0);
    for (const x of barcodes) {
        ++cnt[x];
    }
    barcodes.sort((a, b) => (cnt[a] === cnt[b] ? a - b : cnt[b] - cnt[a]));
    const n = barcodes.length;
    const ans = Array(n);
    for (let k = 0, j = 0; k < 2; ++k) {
        for (let i = k; i < n; i += 2, ++j) {
            ans[i] = barcodes[j];
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

<p>在一个仓库里，有一排条形码，其中第 <code>i</code> 个条形码为&nbsp;<code>barcodes[i]</code>。</p>

<p>请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 你可以返回任何满足该要求的答案，此题保证存在答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>barcodes = [1,1,1,2,2,2]
<strong>输出：</strong>[2,1,2,1,2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>barcodes = [1,1,1,1,2,2,3,3]
<strong>输出：</strong>[1,3,1,3,2,1,2,1]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= barcodes.length &lt;= 10000</code></li>
	<li><code>1 &lt;= barcodes[i] &lt;= 10000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 排序

我们先用哈希表或数组 $cnt$ 统计数组 $barcodes$ 中各个数出现的次数，然后将 $barcodes$ 中的数按照它们在 $cnt$ 中出现的次数从大到小排序，如果出现次数相同，那么就按照数的大小从小到大排序（确保相同的数相邻）。

接下来，我们创建一个长度为 $n$ 的答案数组 $ans$，然后遍历排好序的 $barcodes$，将元素依次填入答案数组的 $0, 2, 4, \cdots$ 等偶数下标位置，然后将剩余元素依次填入答案数组的 $1, 3, 5, \cdots$ 等奇数下标位置即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(M)$。其中 $n$ 和 $M$ 分别是数组 $barcodes$ 的长度以及数组 $barcodes$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        cnt = Counter(barcodes)
        barcodes.sort(key=lambda x: (-cnt[x], x))
        n = len(barcodes)
        ans = [0] * len(barcodes)
        ans[::2] = barcodes[: (n + 1) // 2]
        ans[1::2] = barcodes[(n + 1) // 2 :]
        return ans
```

#### Java

```java
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int n = barcodes.length;
        Integer[] t = new Integer[n];
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            t[i] = barcodes[i];
            mx = Math.max(mx, barcodes[i]);
        }
        int[] cnt = new int[mx + 1];
        for (int x : barcodes) {
            ++cnt[x];
        }
        Arrays.sort(t, (a, b) -> cnt[a] == cnt[b] ? a - b : cnt[b] - cnt[a]);
        int[] ans = new int[n];
        for (int k = 0, j = 0; k < 2; ++k) {
            for (int i = k; i < n; i += 2) {
                ans[i] = t[j++];
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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int mx = *max_element(barcodes.begin(), barcodes.end());
        int cnt[mx + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int x : barcodes) {
            ++cnt[x];
        }
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        int n = barcodes.size();
        vector<int> ans(n);
        for (int k = 0, j = 0; k < 2; ++k) {
            for (int i = k; i < n; i += 2) {
                ans[i] = barcodes[j++];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func rearrangeBarcodes(barcodes []int) []int {
	mx := slices.Max(barcodes)
	cnt := make([]int, mx+1)
	for _, x := range barcodes {
		cnt[x]++
	}
	sort.Slice(barcodes, func(i, j int) bool {
		a, b := barcodes[i], barcodes[j]
		if cnt[a] == cnt[b] {
			return a < b
		}
		return cnt[a] > cnt[b]
	})
	n := len(barcodes)
	ans := make([]int, n)
	for k, j := 0, 0; k < 2; k++ {
		for i := k; i < n; i, j = i+2, j+1 {
			ans[i] = barcodes[j]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function rearrangeBarcodes(barcodes: number[]): number[] {
    const mx = Math.max(...barcodes);
    const cnt = Array(mx + 1).fill(0);
    for (const x of barcodes) {
        ++cnt[x];
    }
    barcodes.sort((a, b) => (cnt[a] === cnt[b] ? a - b : cnt[b] - cnt[a]));
    const n = barcodes.length;
    const ans = Array(n);
    for (let k = 0, j = 0; k < 2; ++k) {
        for (let i = k; i < n; i += 2, ++j) {
            ans[i] = barcodes[j];
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

# [1055. 形成字符串的最短路径 🔒](https://leetcode.cn/problems/shortest-way-to-form-string){#1055}

{{< tabs "1055" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        def f(i, j):
            while i < m and j < n:
                if source[i] == target[j]:
                    j += 1
                i += 1
            return j

        m, n = len(source), len(target)
        ans = j = 0
        while j < n:
            k = f(0, j)
            if k == j:
                return -1
            j = k
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestWay(String source, String target) {
        int m = source.length(), n = target.length();
        int ans = 0, j = 0;
        while (j < n) {
            int i = 0;
            boolean ok = false;
            while (i < m && j < n) {
                if (source.charAt(i) == target.charAt(j)) {
                    ok = true;
                    ++j;
                }
                ++i;
            }
            if (!ok) {
                return -1;
            }
            ++ans;
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
    int shortestWay(string source, string target) {
        int m = source.size(), n = target.size();
        int ans = 0, j = 0;
        while (j < n) {
            int i = 0;
            bool ok = false;
            while (i < m && j < n) {
                if (source[i] == target[j]) {
                    ok = true;
                    ++j;
                }
                ++i;
            }
            if (!ok) {
                return -1;
            }
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestWay(source string, target string) int {
	m, n := len(source), len(target)
	ans, j := 0, 0
	for j < n {
		ok := false
		for i := 0; i < m && j < n; i++ {
			if source[i] == target[j] {
				ok = true
				j++
			}
		}
		if !ok {
			return -1
		}
		ans++
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

<p>对于任何字符串，我们可以通过删除其中一些字符（也可能不删除）来构造该字符串的 <strong>子序列</strong> 。(例如，<code>“ace”</code>&nbsp;是 <code>“abcde”</code> 的子序列，而 <code>“aec”</code> 不是)。</p>

<p>给定源字符串&nbsp;<code>source</code> 和目标字符串&nbsp;<code>target</code>，返回 <em>源字符串&nbsp;<code>source</code>&nbsp;中能通过串联形成目标字符串&nbsp;</em><code>target</code>&nbsp;<em>的 <strong>子序列</strong> 的最小数量&nbsp;</em>。如果无法通过串联源字符串中的子序列来构造目标字符串，则返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>source = "abc", target = "abcbc"
<strong>输出：</strong>2
<strong>解释：</strong>目标字符串 "abcbc" 可以由 "abc" 和 "bc" 形成，它们都是源字符串 "abc" 的子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>source = "abc", target = "acdbc"
<strong>输出：</strong>-1
<strong>解释：</strong>由于目标字符串中包含字符 "d"，所以无法由源字符串的子序列构建目标字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>source = "xyz", target = "xzyxz"
<strong>输出：</strong>3
<strong>解释：</strong>目标字符串可以按如下方式构建： "xz" + "y" + "xz"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= source.length, target.length &lt;= 1000</code></li>
	<li><code>source</code> 和&nbsp;<code>target</code>&nbsp;仅包含英文小写字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以使用双指针的方法，用指针 $j$ 指向目标字符串 `target`，然后遍历源字符串 `source`，用指针 $i$ 指向源字符串 `source`，如果 $source[i] = target[j]$，则 $i$ 和 $j$ 同时向后移动一位，否则只移动 $i$ 指针。当指针 $i$ 和 $j$ 都到达字符串末尾时，如果没有找到相等的字符，则返回 $-1$，否则子序列数量加一，然后将指针 $i$ 置为 $0$，继续遍历。

遍历结束后，返回子序列数量即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为字符串 `source` 和 `target` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        def f(i, j):
            while i < m and j < n:
                if source[i] == target[j]:
                    j += 1
                i += 1
            return j

        m, n = len(source), len(target)
        ans = j = 0
        while j < n:
            k = f(0, j)
            if k == j:
                return -1
            j = k
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int shortestWay(String source, String target) {
        int m = source.length(), n = target.length();
        int ans = 0, j = 0;
        while (j < n) {
            int i = 0;
            boolean ok = false;
            while (i < m && j < n) {
                if (source.charAt(i) == target.charAt(j)) {
                    ok = true;
                    ++j;
                }
                ++i;
            }
            if (!ok) {
                return -1;
            }
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
    int shortestWay(string source, string target) {
        int m = source.size(), n = target.size();
        int ans = 0, j = 0;
        while (j < n) {
            int i = 0;
            bool ok = false;
            while (i < m && j < n) {
                if (source[i] == target[j]) {
                    ok = true;
                    ++j;
                }
                ++i;
            }
            if (!ok) {
                return -1;
            }
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func shortestWay(source string, target string) int {
	m, n := len(source), len(target)
	ans, j := 0, 0
	for j < n {
		ok := false
		for i := 0; i < m && j < n; i++ {
			if source[i] == target[j] {
				ok = true
				j++
			}
		}
		if !ok {
			return -1
		}
		ans++
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1056. 易混淆数 🔒](https://leetcode.cn/problems/confusing-number){#1056}

{{< tabs "1056" >}}

{{% tab "python" %}}
```python
class Solution:
    def confusingNumber(self, n: int) -> bool:
        x, y = n, 0
        d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6]
        while x:
            x, v = divmod(x, 10)
            if d[v] < 0:
                return False
            y = y * 10 + d[v]
        return y != n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean confusingNumber(int n) {
        int[] d = new int[] {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int x = n, y = 0;
        while (x > 0) {
            int v = x % 10;
            if (d[v] < 0) {
                return false;
            }
            y = y * 10 + d[v];
            x /= 10;
        }
        return y != n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool confusingNumber(int n) {
        vector<int> d = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int x = n, y = 0;
        while (x) {
            int v = x % 10;
            if (d[v] < 0) {
                return false;
            }
            y = y * 10 + d[v];
            x /= 10;
        }
        return y != n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func confusingNumber(n int) bool {
	d := []int{0, 1, -1, -1, -1, -1, 9, -1, 8, 6}
	x, y := n, 0
	for x > 0 {
		v := x % 10
		if d[v] < 0 {
			return false
		}
		y = y*10 + d[v]
		x /= 10
	}
	return y != n
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return Boolean
     */
    function confusingNumber($n) {
        $d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6];
        $x = $n;
        $y = 0;
        while ($x > 0) {
            $v = $x % 10;
            if ($d[$v] < 0) {
                return false;
            }
            $y = $y * 10 + $d[$v];
            $x = intval($x / 10);
        }
        return $y != $n;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数字 <code>N</code>，当它满足以下条件的时候返回 <code>true</code>：</p>

<p>原数字旋转 180° 以后可以得到新的数字。</p>

<p>如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。</p>

<p>2, 3, 4, 5, 7 旋转 180° 后，得到的<strong>不是</strong>数字。</p>

<p>易混淆数&nbsp;(confusing number) 在旋转180°以后，可以得到和原来<strong>不同</strong>的数，且新数字的每一位都是有效的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1056.Confusing%20Number/images/1268_1.png" style="height: 90px; width: 180px;" /></p>

<pre>
<strong>输入：</strong>6
<strong>输出：</strong>true
<strong>解释： 
</strong>把 6 旋转 180° 以后得到 9，9 是有效数字且 9!=6 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1056.Confusing%20Number/images/1268_2.png" style="height: 90px; width: 180px;" /></p>

<pre>
<strong>输入：</strong>89
<strong>输出：</strong>true
<strong>解释: 
</strong>把 89 旋转 180° 以后得到 68，<span style="text-wrap: wrap;">68</span> 是有效数字且 89!=68 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1056.Confusing%20Number/images/1268_3.png" style="height: 121px; width: 301px;" /></p>

<pre>
<strong>输入：</strong>11
<strong>输出：</strong>false
<strong>解释：
</strong>把 11 旋转 180° 以后得到 11，11 是有效数字但是值保持不变，所以 11 不是易混淆数字。 
</pre>

<p><strong>示例 4：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1056.Confusing%20Number/images/1268_4.png" style="height: 90px; width: 180px;" /></p>

<pre>
<strong>输入：</strong>25
<strong>输出：</strong>false
<strong>解释：</strong>
把 25 旋转 180° 以后得到的不是数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 &lt;= N &lt;= 10^9</code></li>
	<li>可以忽略掉旋转后得到的前导零，例如，如果我们旋转后得到 <code>0008</code> 那么该数字就是 <code>8</code> 。</li>
</ol>

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
    def confusingNumber(self, n: int) -> bool:
        x, y = n, 0
        d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6]
        while x:
            x, v = divmod(x, 10)
            if d[v] < 0:
                return False
            y = y * 10 + d[v]
        return y != n
```

#### Java

```java
class Solution {
    public boolean confusingNumber(int n) {
        int[] d = new int[] {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int x = n, y = 0;
        while (x > 0) {
            int v = x % 10;
            if (d[v] < 0) {
                return false;
            }
            y = y * 10 + d[v];
            x /= 10;
        }
        return y != n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool confusingNumber(int n) {
        vector<int> d = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int x = n, y = 0;
        while (x) {
            int v = x % 10;
            if (d[v] < 0) {
                return false;
            }
            y = y * 10 + d[v];
            x /= 10;
        }
        return y != n;
    }
};
```

#### Go

```go
func confusingNumber(n int) bool {
	d := []int{0, 1, -1, -1, -1, -1, 9, -1, 8, 6}
	x, y := n, 0
	for x > 0 {
		v := x % 10
		if d[v] < 0 {
			return false
		}
		y = y*10 + d[v]
		x /= 10
	}
	return y != n
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Boolean
     */
    function confusingNumber($n) {
        $d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6];
        $x = $n;
        $y = 0;
        while ($x > 0) {
            $v = $x % 10;
            if ($d[$v] < 0) {
                return false;
            }
            $y = $y * 10 + $d[$v];
            $x = intval($x / 10);
        }
        return $y != $n;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1057. 校园自行车分配 🔒](https://leetcode.cn/problems/campus-bikes){#1057}

{{< tabs "1057" >}}

{{% tab "python" %}}
```python
class Solution:
    def assignBikes(
        self, workers: List[List[int]], bikes: List[List[int]]
    ) -> List[int]:
        n, m = len(workers), len(bikes)
        arr = []
        for i, j in product(range(n), range(m)):
            dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
            arr.append((dist, i, j))
        arr.sort()
        vis1 = [False] * n
        vis2 = [False] * m
        ans = [0] * n
        for _, i, j in arr:
            if not vis1[i] and not vis2[j]:
                vis1[i] = vis2[j] = True
                ans[i] = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length, m = bikes.length;
        int[][] arr = new int[m * n][3];
        for (int i = 0, k = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dist
                    = Math.abs(workers[i][0] - bikes[j][0]) + Math.abs(workers[i][1] - bikes[j][1]);
                arr[k++] = new int[] {dist, i, j};
            }
        }
        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            if (a[1] != b[1]) {
                return a[1] - b[1];
            }
            return a[2] - b[2];
        });
        boolean[] vis1 = new boolean[n];
        boolean[] vis2 = new boolean[m];
        int[] ans = new int[n];
        for (var e : arr) {
            int i = e[1], j = e[2];
            if (!vis1[i] && !vis2[j]) {
                vis1[i] = true;
                vis2[j] = true;
                ans[i] = j;
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
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<tuple<int, int, int>> arr(n * m);
        for (int i = 0, k = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                arr[k++] = {dist, i, j};
            }
        }
        sort(arr.begin(), arr.end());
        vector<bool> vis1(n), vis2(m);
        vector<int> ans(n);
        for (auto& [_, i, j] : arr) {
            if (!vis1[i] && !vis2[j]) {
                vis1[i] = true;
                vis2[j] = true;
                ans[i] = j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func assignBikes(workers [][]int, bikes [][]int) []int {
	n, m := len(workers), len(bikes)
	type tuple struct{ d, i, j int }
	arr := make([]tuple, n*m)
	for i, k := 0, 0; i < n; i++ {
		for j := 0; j < m; j++ {
			d := abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1])
			arr[k] = tuple{d, i, j}
			k++
		}
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i].d != arr[j].d {
			return arr[i].d < arr[j].d
		}
		if arr[i].i != arr[j].i {
			return arr[i].i < arr[j].i
		}
		return arr[i].j < arr[j].j
	})
	vis1, vis2 := make([]bool, n), make([]bool, m)
	ans := make([]int, n)
	for _, e := range arr {
		i, j := e.i, e.j
		if !vis1[i] && !vis2[j] {
			vis1[i], vis2[j] = true, true
			ans[i] = j
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在 X-Y 平面上表示的校园中，有 <code>n</code> 名工人和 <code>m</code> 辆自行车，其中 <code>n &lt;= m</code>。</p>

<p>给定一个长度为 <code>n</code> 的数组&nbsp;<code>workers</code>&nbsp;，其中 <code>worker [i] = [xi, yi]</code>&nbsp;表示第 <code>i</code>&nbsp;个工人的位置。你也得到一个长度为 <code>m</code> 的自行车数组 <code>bikers</code> ，其中 <code>bikes[j] = [x<sub>j</sub>, y<sub>j</sub>]</code>&nbsp;是第 <code>j</code> 辆自行车的位置。所有给定的位置都是 <strong>唯一</strong> 的。</p>

<p>我们需要为每位工人分配一辆自行车。在所有可用的自行车和工人中，我们选取彼此之间 <strong>曼哈顿距离</strong> 最短的工人自行车对&nbsp;<code>(worker<sub>i</sub>, bike<sub>j</sub>)</code>&nbsp;，并将其中的自行车分配給工人。</p>

<p>如果有多个&nbsp;<code>(worker<sub>i</sub>, bike<sub>j</sub>)</code> 对之间的 <strong>曼哈顿距离</strong> 相同，那么我们选择 <strong>工人索引最小</strong> 的那对。类似地，如果有多种不同的分配方法，则选择 <strong>自行车索引最小</strong> 的一对。不断重复这一过程，直到所有工人都分配到自行车为止。</p>

<p>返回长度为 <code>n</code> 的向量 <code>answer</code>，其中 <code>answer[i]</code>&nbsp;是第 <code>i</code>&nbsp;位工人分配到的自行车的索引（<strong>从 0 开始</strong>）。</p>

<p>给定两点&nbsp;<code>p1</code>&nbsp;和&nbsp;<code>p2</code>&nbsp;之间的 <strong>曼哈顿距离</strong> 为&nbsp;<code>Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1057.Campus%20Bikes/images/1261_example_1_v2.png" /></p>

<pre>
<strong>输入：</strong>workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>工人 1 分配到自行车 0，因为他们最接近且不存在冲突，工人 0 分配到自行车 1 。所以输出是 [1,0]。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1057.Campus%20Bikes/images/1261_example_2_v2.png" /></p>

<pre>
<strong>输入：</strong>workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
<strong>输出：</strong>[0,2,1]
<strong>解释：</strong>工人 0 首先分配到自行车 0 。工人 1 和工人 2 与自行车 2 距离相同，因此工人 1 分配到自行车 2，工人 2 将分配到自行车 1 。因此输出为 [0,2,1]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == workers.length</code></li>
	<li><code>m == bikes.length</code></li>
	<li><code>1 &lt;= n &lt;= m &lt;= 1000</code></li>
	<li><code>workers[i].length == bikes[j].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt; 1000</code></li>
	<li><code>0 &lt;= x<sub>j</sub>, y<sub>j</sub>&nbsp;&lt; 1000</code></li>
	<li>所有工人和自行车的位置都<strong>不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

先计算每个工人和每个自行车之间的曼哈顿距离，然后按照曼哈顿距离从小到大排序，遍历排序后的数组，如果当前工人和自行车都未被分配，则分配给当前工人和自行车。

时间复杂度 $O(n\times m\times \log (n\times m))$。其中 $n$ 和 $m$ 分别为工人和自行车的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def assignBikes(
        self, workers: List[List[int]], bikes: List[List[int]]
    ) -> List[int]:
        n, m = len(workers), len(bikes)
        arr = []
        for i, j in product(range(n), range(m)):
            dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
            arr.append((dist, i, j))
        arr.sort()
        vis1 = [False] * n
        vis2 = [False] * m
        ans = [0] * n
        for _, i, j in arr:
            if not vis1[i] and not vis2[j]:
                vis1[i] = vis2[j] = True
                ans[i] = j
        return ans
```

#### Java

```java
class Solution {
    public int[] assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length, m = bikes.length;
        int[][] arr = new int[m * n][3];
        for (int i = 0, k = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dist
                    = Math.abs(workers[i][0] - bikes[j][0]) + Math.abs(workers[i][1] - bikes[j][1]);
                arr[k++] = new int[] {dist, i, j};
            }
        }
        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            if (a[1] != b[1]) {
                return a[1] - b[1];
            }
            return a[2] - b[2];
        });
        boolean[] vis1 = new boolean[n];
        boolean[] vis2 = new boolean[m];
        int[] ans = new int[n];
        for (var e : arr) {
            int i = e[1], j = e[2];
            if (!vis1[i] && !vis2[j]) {
                vis1[i] = true;
                vis2[j] = true;
                ans[i] = j;
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
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<tuple<int, int, int>> arr(n * m);
        for (int i = 0, k = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                arr[k++] = {dist, i, j};
            }
        }
        sort(arr.begin(), arr.end());
        vector<bool> vis1(n), vis2(m);
        vector<int> ans(n);
        for (auto& [_, i, j] : arr) {
            if (!vis1[i] && !vis2[j]) {
                vis1[i] = true;
                vis2[j] = true;
                ans[i] = j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func assignBikes(workers [][]int, bikes [][]int) []int {
	n, m := len(workers), len(bikes)
	type tuple struct{ d, i, j int }
	arr := make([]tuple, n*m)
	for i, k := 0, 0; i < n; i++ {
		for j := 0; j < m; j++ {
			d := abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1])
			arr[k] = tuple{d, i, j}
			k++
		}
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i].d != arr[j].d {
			return arr[i].d < arr[j].d
		}
		if arr[i].i != arr[j].i {
			return arr[i].i < arr[j].i
		}
		return arr[i].j < arr[j].j
	})
	vis1, vis2 := make([]bool, n), make([]bool, m)
	ans := make([]int, n)
	for _, e := range arr {
		i, j := e.i, e.j
		if !vis1[i] && !vis2[j] {
			vis1[i], vis2[j] = true, true
			ans[i] = j
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1058. 最小化舍入误差以满足目标 🔒](https://leetcode.cn/problems/minimize-rounding-error-to-meet-target){#1058}

{{< tabs "1058" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        mi = 0
        arr = []
        for p in prices:
            p = float(p)
            mi += int(p)
            if d := p - int(p):
                arr.append(d)
        if not mi <= target <= mi + len(arr):
            return "-1"
        d = target - mi
        arr.sort(reverse=True)
        ans = d - sum(arr[:d]) + sum(arr[d:])
        return f'{ans:.3f}'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minimizeError(String[] prices, int target) {
        int mi = 0;
        List<Double> arr = new ArrayList<>();
        for (String p : prices) {
            double price = Double.valueOf(p);
            mi += (int) price;
            double d = price - (int) price;
            if (d > 0) {
                arr.add(d);
            }
        }
        if (target < mi || target > mi + arr.size()) {
            return "-1";
        }
        int d = target - mi;
        arr.sort(Collections.reverseOrder());
        double ans = d;
        for (int i = 0; i < d; ++i) {
            ans -= arr.get(i);
        }
        for (int i = d; i < arr.size(); ++i) {
            ans += arr.get(i);
        }
        DecimalFormat df = new DecimalFormat("#0.000");
        return df.format(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int mi = 0;
        vector<double> arr;
        for (auto& p : prices) {
            double price = stod(p);
            mi += (int) price;
            double d = price - (int) price;
            if (d > 0) {
                arr.push_back(d);
            }
        }
        if (target < mi || target > mi + arr.size()) {
            return "-1";
        }
        int d = target - mi;
        sort(arr.rbegin(), arr.rend());
        double ans = d;
        for (int i = 0; i < d; ++i) {
            ans -= arr[i];
        }
        for (int i = d; i < arr.size(); ++i) {
            ans += arr[i];
        }
        string s = to_string(ans);
        return s.substr(0, s.find('.') + 4);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeError(prices []string, target int) string {
	arr := []float64{}
	mi := 0
	for _, p := range prices {
		price, _ := strconv.ParseFloat(p, 64)
		mi += int(math.Floor(price))
		d := price - float64(math.Floor(price))
		if d > 0 {
			arr = append(arr, d)
		}
	}
	if target < mi || target > mi+len(arr) {
		return "-1"
	}
	d := target - mi
	sort.Float64s(arr)
	ans := float64(d)
	for i := 0; i < d; i++ {
		ans -= arr[len(arr)-i-1]
	}
	for i := d; i < len(arr); i++ {
		ans += arr[len(arr)-i-1]
	}
	return fmt.Sprintf("%.3f", ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一系列价格&nbsp;<code>[p<sub>1</sub>,p<sub>2</sub>...,p<sub>n</sub>]</code>&nbsp;和一个目标&nbsp;<code>target</code>，将每个价格&nbsp;<code>p<sub>i</sub></code>&nbsp;舍入为&nbsp;<code>Round<sub>i</sub>(p<sub>i</sub>)</code>&nbsp;以使得舍入数组&nbsp;<code>[Round<sub>1</sub>(p<sub>1</sub>),Round<sub>2</sub>(p<sub>2</sub>)...,Round<sub>n</sub>(p<sub>n</sub>)]</code>&nbsp;之和达到给定的目标值&nbsp;<code>target</code>。每次舍入操作&nbsp;<code>Round<sub>i</sub>(p<sub>i</sub>)</code>&nbsp;可以是向下舍&nbsp;<code>Floor(p<sub>i</sub>)</code>&nbsp;也可以是向上入&nbsp;<code>Ceil(p<sub>i</sub>)</code>。</p>

<p>如果舍入数组之和无论如何都无法达到目标值&nbsp;<code>target</code>，就返回字符串&nbsp;<code>"-1"</code>。否则，以保留到<strong>小数点后三位</strong>的字符串格式返回最小的舍入误差，其定义为 <code>Σ |Round<sub>i</sub>(p<sub>i</sub>) - (p<sub>i</sub>)|</code>（&nbsp;i 从 1 到 n ）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>prices = ["0.700","2.800","4.900"], target = 8
<strong>输出：</strong>"1.000"
<strong>解释： </strong>
使用 Floor，Ceil 和 Ceil 操作得到 (0.7 - 0) + (3 - 2.8) + (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>prices = ["1.500","2.500","3.500"], target = 10
<strong>输出：</strong>"-1"
<strong>解释：</strong>
达到目标是不可能的。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>prices = ["1.500","2.500","3.500"], target = 9
<strong>输出：</strong>"1.500"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 500</code></li>
	<li>表示价格的每个字符串&nbsp;<code>prices[i]</code>&nbsp;都代表一个介于 <code>[0.0,&nbsp;1000.0]</code> 之间的实数，并且正好有 3 个小数位。</li>
	<li><code>target</code>&nbsp;介于&nbsp;0 和 1000000&nbsp;之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

遍历价格数组 `prices`，先将每个价格 $p$ 向下舍入，累加到 `mi` 中，同时将每个价格的小数点部分添加到数组 `arr` 中。

遍历结束后，判断 `target` 是否在 `mi` 和 `mi + arr.length` 之间，如果不在，直接返回 `"-1"`。

接下来，我们计算 `target - mi`，即需要向上入的价格个数，然后将 `arr` 从大到小排序，从前往后遍历，将前 `target - mi` 个价格向上入，其余价格向下舍入，累计到 `ans` 中。

时间复杂度 $O(n\log n)$。其中 $n$ 为 `prices` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        mi = 0
        arr = []
        for p in prices:
            p = float(p)
            mi += int(p)
            if d := p - int(p):
                arr.append(d)
        if not mi <= target <= mi + len(arr):
            return "-1"
        d = target - mi
        arr.sort(reverse=True)
        ans = d - sum(arr[:d]) + sum(arr[d:])
        return f'{ans:.3f}'
```

#### Java

```java
class Solution {
    public String minimizeError(String[] prices, int target) {
        int mi = 0;
        List<Double> arr = new ArrayList<>();
        for (String p : prices) {
            double price = Double.valueOf(p);
            mi += (int) price;
            double d = price - (int) price;
            if (d > 0) {
                arr.add(d);
            }
        }
        if (target < mi || target > mi + arr.size()) {
            return "-1";
        }
        int d = target - mi;
        arr.sort(Collections.reverseOrder());
        double ans = d;
        for (int i = 0; i < d; ++i) {
            ans -= arr.get(i);
        }
        for (int i = d; i < arr.size(); ++i) {
            ans += arr.get(i);
        }
        DecimalFormat df = new DecimalFormat("#0.000");
        return df.format(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int mi = 0;
        vector<double> arr;
        for (auto& p : prices) {
            double price = stod(p);
            mi += (int) price;
            double d = price - (int) price;
            if (d > 0) {
                arr.push_back(d);
            }
        }
        if (target < mi || target > mi + arr.size()) {
            return "-1";
        }
        int d = target - mi;
        sort(arr.rbegin(), arr.rend());
        double ans = d;
        for (int i = 0; i < d; ++i) {
            ans -= arr[i];
        }
        for (int i = d; i < arr.size(); ++i) {
            ans += arr[i];
        }
        string s = to_string(ans);
        return s.substr(0, s.find('.') + 4);
    }
};
```

#### Go

```go
func minimizeError(prices []string, target int) string {
	arr := []float64{}
	mi := 0
	for _, p := range prices {
		price, _ := strconv.ParseFloat(p, 64)
		mi += int(math.Floor(price))
		d := price - float64(math.Floor(price))
		if d > 0 {
			arr = append(arr, d)
		}
	}
	if target < mi || target > mi+len(arr) {
		return "-1"
	}
	d := target - mi
	sort.Float64s(arr)
	ans := float64(d)
	for i := 0; i < d; i++ {
		ans -= arr[len(arr)-i-1]
	}
	for i := d; i < len(arr); i++ {
		ans += arr[len(arr)-i-1]
	}
	return fmt.Sprintf("%.3f", ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1059. 从始点到终点的所有路径 🔒](https://leetcode.cn/problems/all-paths-from-source-lead-to-destination){#1059}

{{< tabs "1059" >}}

{{% tab "python" %}}
```python
class Solution:
    def leadsToDestination(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        @cache
        def dfs(i):
            if i == destination:
                return not g[i]
            if i in vis or not g[i]:
                return False
            vis.add(i)
            for j in g[i]:
                if not dfs(j):
                    return False
            return True

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
        vis = set()
        return dfs(source)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] f;
    private boolean[] vis;
    private int k;

    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        vis = new boolean[n];
        g = new List[n];
        k = destination;
        f = new int[n];
        Arrays.setAll(g, key -> new ArrayList<>());
        for (var e : edges) {
            g[e[0]].add(e[1]);
        }
        return dfs(source);
    }

    private boolean dfs(int i) {
        if (i == k) {
            return g[i].isEmpty();
        }
        if (f[i] != 0) {
            return f[i] == 1;
        }
        if (vis[i] || g[i].isEmpty()) {
            return false;
        }
        vis[i] = true;
        for (int j : g[i]) {
            if (!dfs(j)) {
                f[i] = -1;
                return false;
            }
        }
        f[i] = 1;
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        vector<int> f(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }
        function<bool(int)> dfs = [&](int i) {
            if (i == destination) {
                return g[i].empty();
            }
            if (f[i]) {
                return f[i] == 1;
            }
            if (vis[i] || g[i].empty()) {
                return false;
            }
            vis[i] = true;
            for (int j : g[i]) {
                if (!dfs(j)) {
                    f[i] = -1;
                    return false;
                }
            }
            f[i] = 1;
            return true;
        };
        return dfs(source);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func leadsToDestination(n int, edges [][]int, source int, destination int) bool {
	vis := make([]bool, n)
	g := make([][]int, n)
	f := make([]int, n)
	for _, e := range edges {
		g[e[0]] = append(g[e[0]], e[1])
	}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == destination {
			return len(g[i]) == 0
		}
		if f[i] != 0 {
			return f[i] == 1
		}
		if vis[i] || len(g[i]) == 0 {
			return false
		}
		vis[i] = true
		for _, j := range g[i] {
			if !dfs(j) {
				f[i] = -1
				return false
			}
		}
		f[i] = 1
		return true
	}
	return dfs(source)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定有向图的边&nbsp;<code>edges</code>，以及该图的始点&nbsp;<code>source</code>&nbsp;和目标终点&nbsp;<code>destination</code>，确定从始点&nbsp;<code>source</code>&nbsp;出发的所有路径是否最终结束于目标终点&nbsp;<code>destination</code>，即：</p>

<ul>
	<li>从始点&nbsp;<code>source</code> 到目标终点&nbsp;<code>destination</code> 存在至少一条路径</li>
	<li>如果存在从始点&nbsp;<code>source</code> 到没有出边的节点的路径，则该节点就是路径终点。</li>
	<li>从始点<code>source</code>到目标终点&nbsp;<code>destination</code> 可能路径数是有限数字</li>
</ul>

<p>当从始点&nbsp;<code>source</code> 出发的所有路径都可以到达目标终点&nbsp;<code>destination</code> 时返回&nbsp;<code>true</code>，否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1059.All%20Paths%20from%20Source%20Lead%20to%20Destination/images/485_example_1.png" style="height: 208px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
<strong>输出：</strong>false
<strong>说明：</strong>节点 1 和节点 2 都可以到达，但也会卡在那里。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1059.All%20Paths%20from%20Source%20Lead%20to%20Destination/images/485_example_2.png" style="height: 230px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
<strong>输出：</strong>false
<strong>说明：</strong>有两种可能：在节点 3 处结束，或是在节点 1 和节点 2 之间无限循环。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1059.All%20Paths%20from%20Source%20Lead%20to%20Destination/images/485_example_3.png" style="height: 183px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 10<sup>4</sup></code></li>
	<li><code>edges.length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>0 &lt;= source &lt;= n - 1</code></li>
	<li><code>0 &lt;= destination &lt;= n - 1</code></li>
	<li>给定的图中可能带有自环和平行边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

建图，然后从 `source` 出发，进行深度优先搜索：

如果遇到了 `destination`，判断此时是否还有出边，如果有出边，返回 `false`，否则返回 `true`。

如果遇到了环（此前访问过），或者遇到了没有出边的节点，直接返回 `false`。

否则，我们把当前节点标记为已访问，然后对当前节点的所有出边进行深度优先搜索，只要有一条路径无法可以到达 `destination`，就返回 `false`，否则返回 `true`。

过程中我们用一个数组 $f$ 记录每个节点的状态，每个 $f[i]$ 的值有三种，分别表示：

-   对于 $f[i] = 0$，表示节点 $i$ 未被访问；
-   对于 $f[i] = 1$，表示节点 $i$ 已被访问，且可以到达 `destination`；
-   对于 $f[i] = 2$，表示节点 $i$ 已被访问，但无法到达 `destination`。

时间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def leadsToDestination(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        @cache
        def dfs(i):
            if i == destination:
                return not g[i]
            if i in vis or not g[i]:
                return False
            vis.add(i)
            for j in g[i]:
                if not dfs(j):
                    return False
            return True

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
        vis = set()
        return dfs(source)
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] f;
    private boolean[] vis;
    private int k;

    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        vis = new boolean[n];
        g = new List[n];
        k = destination;
        f = new int[n];
        Arrays.setAll(g, key -> new ArrayList<>());
        for (var e : edges) {
            g[e[0]].add(e[1]);
        }
        return dfs(source);
    }

    private boolean dfs(int i) {
        if (i == k) {
            return g[i].isEmpty();
        }
        if (f[i] != 0) {
            return f[i] == 1;
        }
        if (vis[i] || g[i].isEmpty()) {
            return false;
        }
        vis[i] = true;
        for (int j : g[i]) {
            if (!dfs(j)) {
                f[i] = -1;
                return false;
            }
        }
        f[i] = 1;
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        vector<int> f(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }
        function<bool(int)> dfs = [&](int i) {
            if (i == destination) {
                return g[i].empty();
            }
            if (f[i]) {
                return f[i] == 1;
            }
            if (vis[i] || g[i].empty()) {
                return false;
            }
            vis[i] = true;
            for (int j : g[i]) {
                if (!dfs(j)) {
                    f[i] = -1;
                    return false;
                }
            }
            f[i] = 1;
            return true;
        };
        return dfs(source);
    }
};
```

#### Go

```go
func leadsToDestination(n int, edges [][]int, source int, destination int) bool {
	vis := make([]bool, n)
	g := make([][]int, n)
	f := make([]int, n)
	for _, e := range edges {
		g[e[0]] = append(g[e[0]], e[1])
	}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == destination {
			return len(g[i]) == 0
		}
		if f[i] != 0 {
			return f[i] == 1
		}
		if vis[i] || len(g[i]) == 0 {
			return false
		}
		vis[i] = true
		for _, j := range g[i] {
			if !dfs(j) {
				f[i] = -1
				return false
			}
		}
		f[i] = 1
		return true
	}
	return dfs(source)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
