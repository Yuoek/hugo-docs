---
title: "1950_所有子数组最小值中的最大值 🔒"
date: 2025-10-08T18:38:49+08:00
weight: 6
tags: [二分查找, 几何, 动态规划, 单调栈, 字符串, 数学, 数据库, 数组, 数论, 枚举, 栈, 矩阵, 贪心]
---

{{< markmap >}}
### [1950_所有子数组最小值中的最大值 🔒](#1950)
#### [栈](#1950)
#### [数组](#1950)
#### [单调栈](#1950)
### [1951_查询具有最多共同关注者的所有两两结对组 🔒](#1951)
#### [数据库](#1951)
### [1952_三除数](#1952)
#### [数学](#1952)
#### [枚举](#1952)
#### [数论](#1952)
### [1953_你可以工作的最大周数](#1953)
#### [贪心](#1953)
#### [数组](#1953)
### [1954_收集足够苹果的最小花园周长](#1954)
#### [数学](#1954)
#### [二分查找](#1954)
### [1955_统计特殊子序列的数目](#1955)
#### [数组](#1955)
#### [动态规划](#1955)
### [1956_感染 K 种病毒所需的最短时间 🔒](#1956)
#### [几何](#1956)
#### [数组](#1956)
#### [数学](#1956)
#### [二分查找](#1956)
#### [枚举](#1956)
### [1957_删除字符使字符串变好](#1957)
#### [字符串](#1957)
### [1958_检查操作是否合法](#1958)
#### [数组](#1958)
#### [枚举](#1958)
#### [矩阵](#1958)
### [1959_K 次调整数组大小浪费的最小总空间](#1959)
#### [数组](#1959)
#### [动态规划](#1959)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1950_所有子数组最小值中的最大值 🔒
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 1951_查询具有最多共同关注者的所有两两结对组 🔒
___
#### 数据库
---
### 1952_三除数
___
#### 数学
___
#### 枚举
___
#### 数论
---
### 1953_你可以工作的最大周数
___
#### 贪心
___
#### 数组
---
### 1954_收集足够苹果的最小花园周长
___
#### 数学
___
#### 二分查找
---
### 1955_统计特殊子序列的数目
___
#### 数组
___
#### 动态规划
---
### 1956_感染 K 种病毒所需的最短时间 🔒
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 枚举
---
### 1957_删除字符使字符串变好
___
#### 字符串
---
### 1958_检查操作是否合法
___
#### 数组
___
#### 枚举
___
#### 矩阵
---
### 1959_K 次调整数组大小浪费的最小总空间
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 几何 | 动态规划 |
| 单调栈 | 字符串 | 数学 |
| 数据库 | 数组 | 数论 |
| 枚举 | 栈 | 矩阵 |
| 贪心 |  |  |

# [1950. 所有子数组最小值中的最大值 🔒](https://leetcode.cn/problems/maximum-of-minimum-values-in-all-subarrays){#1950}

{{< tabs "1950" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] >= x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        ans = [0] * n
        for i in range(n):
            m = right[i] - left[i] - 1
            ans[m - 1] = max(ans[m - 1], nums[i])
        for i in range(n - 2, -1, -1):
            ans[i] = max(ans[i], ans[i + 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findMaximums(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int m = right[i] - left[i] - 1;
            ans[m - 1] = Math.max(ans[m - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
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
    vector<int> findMaximums(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int m = right[i] - left[i] - 1;
            ans[m - 1] = max(ans[m - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaximums(nums []int) []int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i], right[i] = -1, n
	}
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	ans := make([]int, n)
	for i := range ans {
		m := right[i] - left[i] - 1
		ans[m-1] = max(ans[m-1], nums[i])
	}
	for i := n - 2; i >= 0; i-- {
		ans[i] = max(ans[i], ans[i+1])
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

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，你需要处理 <code>n</code> 个查询。</p>

<p>对于第 <code>i</code> （<code>0 &lt;= i &lt;&nbsp;n</code>）个查询：</p>

<ol>
	<li>你需要先找出 <code>nums</code> 的所有长度为 <code>i + 1</code> 的子数组中的<strong> 最小值</strong> 。</li>
	<li>在这些最小值中找出<strong> 最大值</strong> 作为答案。</li>
</ol>

<p>返回一个 <strong>下标从 0 开始</strong> 的长度为 <code>n</code> 的整数数组 <code>ans</code> ，<code>ans[i]</code> 代表第 <code>i</code> 个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> nums = [0,1,2,4]
<strong>输出:</strong> [4,2,1,0]
<strong>解释:</strong>
i = 0:
- 大小为 1 的子数组为 [0], [1], [2], [4]
- 有最大的最小值的子数组是 [4], 它的最小值是 4
i = 1:
- 大小为 2 的子数组为 [0,1], [1,2], [2,4]
- 有最大的最小值的子数组是 [2,4], 它的最小值是 2
i = 2:
- 大小为 3 的子数组为 [0,1,2], [1,2,4]
- 有最大的最小值的子数组是 [1,2,4], 它的最小值是 1
i = 3:
- 大小为 4 的子数组为 [0,1,2,4]
- 有最大的最小值的子数组是 [0,1,2,4], 它的最小值是 0</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>nums = [10,20,50,10]
<strong>输出: </strong>[50,20,10,10]
<strong>解释:</strong>
i = 0: 
- 大小为 1 的子数组为 [10], [20], [50], [10]
- 有最大的最小值的子数组是 [50], 它的最小值是 50
i = 1: 
- 大小为 2 的子数组为 [10,20], [20,50], [50,10]
- 有最大的最小值的子数组是 [20,50], 它的最小值是 20
i = 2: 
- 大小为 3 的子数组为 [10,20,50], [20,50,10]
- 有最大的最小值的子数组是 [10,20,50], 它的最小值是 10
i = 3: 
- 大小为 4 的子数组为 [10,20,50,10]
- 有最大的最小值的子数组是 [10,20,50,10], 它的最小值是 10</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们可以先利用单调栈，求出每个位置的左边第一个比它小的位置 $left[i]$ 和右边第一个比它小的位置 $right[i]$，那么以 $nums[i]$ 为最小值的子数组的长度为 $m = right[i] - left[i] - 1$。

然后我们遍历数组，对于每个位置 $i$，更新 $ans[m - 1] = max(ans[m - 1], nums[i])$。

接着我们倒序遍历数组，更新 $ans[i] = max(ans[i], ans[i + 1])$。

最后返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaximums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] >= x:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        ans = [0] * n
        for i in range(n):
            m = right[i] - left[i] - 1
            ans[m - 1] = max(ans[m - 1], nums[i])
        for i in range(n - 2, -1, -1):
            ans[i] = max(ans[i], ans[i + 1])
        return ans
```

#### Java

```java
class Solution {
    public int[] findMaximums(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int m = right[i] - left[i] - 1;
            ans[m - 1] = Math.max(ans[m - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int m = right[i] - left[i] - 1;
            ans[m - 1] = max(ans[m - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func findMaximums(nums []int) []int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i], right[i] = -1, n
	}
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		x := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	ans := make([]int, n)
	for i := range ans {
		m := right[i] - left[i] - 1
		ans[m-1] = max(ans[m-1], nums[i])
	}
	for i := n - 2; i >= 0; i-- {
		ans[i] = max(ans[i], ans[i+1])
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1951. 查询具有最多共同关注者的所有两两结对组 🔒](https://leetcode.cn/problems/all-the-pairs-with-the-maximum-number-of-common-followers){#1951}

{{< tabs "1951" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            r1.user_id AS user1_id,
            r2.user_id AS user2_id,
            RANK() OVER (ORDER BY COUNT(1) DESC) AS rk
        FROM
            Relations AS r1
            JOIN Relations AS r2 ON r1.follower_id = r2.follower_id AND r1.user_id < r2.user_id
        GROUP BY r1.user_id, r2.user_id
    )
SELECT
    user1_id,
    user2_id
FROM t
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Relations</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) 是这个表的主键.
这个表的每一行，表示这个user_id的用户和他的关注者，关注者的id 就是本表的 user_id.
</pre>

<p>&nbsp;</p>

<p>写出一个查询语句，找到具有最多共同关注者的所有两两结对组。换句话说，如果有两个用户的共同关注者是最大的，我们应该返回所有具有此最大值的两两结对组</p>

<p>结果返回表，每一行应该包含<code>user1_id</code>和&nbsp;<code>user2_id，</code>其中<code>user1_id &lt; user2_id</code>.</p>

<p>返回结果&nbsp;<strong>不要求顺序</strong>&nbsp;。</p>

<p>查询结果格式如下例：</p>

<p>&nbsp;</p>

<pre>
Relations 表:
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 1       | 3           |
| 2       | 3           |
| 7       | 3           |
| 1       | 4           |
| 2       | 4           |
| 7       | 4           |
| 1       | 5           |
| 2       | 6           |
| 7       | 5           |
+---------+-------------+

Result 表:
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 7        |
+----------+----------+

用户1 和用户 2 有2个共同的关注者（3和4）。
用户1 和用户 7 有3个共同的关注者（3，4和5）。
用户2 和用户7 有2个共同的关注者（3和4）。
既然两两结对的所有组队的最大共同关注者的数值是3，所以，我们应该返回所有拥有3个共同关注者的两两组队，这就是仅有的一对(1, 7).
我们返回的是(1, 7).，而不是(7, 1).
注意，我们没有关于用户3，4，5的任何关注者信息，我们认为他们有0个关注者。
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
    t AS (
        SELECT
            r1.user_id AS user1_id,
            r2.user_id AS user2_id,
            RANK() OVER (ORDER BY COUNT(1) DESC) AS rk
        FROM
            Relations AS r1
            JOIN Relations AS r2 ON r1.follower_id = r2.follower_id AND r1.user_id < r2.user_id
        GROUP BY r1.user_id, r2.user_id
    )
SELECT
    user1_id,
    user2_id
FROM t
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1952. 三除数](https://leetcode.cn/problems/three-divisors){#1952}

{{< tabs "1952" >}}

{{% tab "python" %}}
```python
class Solution:
    def isThree(self, n: int) -> bool:
        cnt = 0
        i = 1
        while i <= n // i:
            if n % i == 0:
                cnt += 1 if i == n // i else 2
            i += 1
        return cnt == 3
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isThree(int n) {
        int cnt = 0;
        for (int i = 1; i <= n / i; ++i) {
            if (n % i == 0) {
                cnt += n / i == i ? 1 : 2;
            }
        }
        return cnt == 3;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 1; i <= n / i; ++i) {
            if (n % i == 0) {
                cnt += n / i == i ? 1 : 2;
            }
        }
        return cnt == 3;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isThree(n int) bool {
	cnt := 0
	for i := 1; i <= n/i; i++ {
		if n%i == 0 {
			if n/i == i {
				cnt++
			} else {
				cnt += 2
			}
		}
	}
	return cnt == 3
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isThree = function (n) {
    let cnt = 0;
    for (let i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            cnt += ~~(n / i) == i ? 1 : 2;
        }
    }
    return cnt == 3;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> 。如果 <code>n</code> <strong>恰好有三个正除数</strong> ，返回 <code>true</code><em> </em>；否则，返回<em> </em><code>false</code> 。</p>

<p>如果存在整数 <code>k</code> ，满足 <code>n = k * m</code> ，那么整数 <code>m</code> 就是 <code>n</code> 的一个 <strong>除数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>false
<strong>解释：</strong>2 只有两个除数：1 和 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>true
<strong>解释：</strong>4 有三个除数：1、2 和 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

一个数 $n$ 一定有 $1$ 和 $n$ 两个正除数，因此只需要枚举 $2$ 到 $n-1$ 之间的数，看它们是否是 $n$ 的正除数即可，是则累加计数器，最后判断计数器是否为 $1$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isThree(self, n: int) -> bool:
        return sum(n % i == 0 for i in range(2, n)) == 1
```

#### Java

```java
class Solution {
    public boolean isThree(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                ++cnt;
            }
        }
        return cnt == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            cnt += n % i == 0;
        }
        return cnt == 1;
    }
};
```

#### Go

```go
func isThree(n int) bool {
	cnt := 0
	for i := 2; i < n; i++ {
		if n%i == 0 {
			cnt++
		}
	}
	return cnt == 1
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isThree = function (n) {
    let cnt = 0;
    for (let i = 2; i < n; ++i) {
        if (n % i == 0) {
            ++cnt;
        }
    }
    return cnt == 1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

我们可以枚举 $1$ 到 $\sqrt{n}$ 之间的数 $i$，如果 $n$ 能被 $i$ 整除，并且 $\frac{n}{i}$ 不等于 $i$，那么计数器累加 $2$，否则计数器累加 $1$。最后判断计数器是否为 $3$ 即可。

时间复杂度 $O(\sqrt{n})$，空间复杂度 $O(1)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isThree(self, n: int) -> bool:
        cnt = 0
        i = 1
        while i <= n // i:
            if n % i == 0:
                cnt += 1 if i == n // i else 2
            i += 1
        return cnt == 3
```

#### Java

```java
class Solution {
    public boolean isThree(int n) {
        int cnt = 0;
        for (int i = 1; i <= n / i; ++i) {
            if (n % i == 0) {
                cnt += n / i == i ? 1 : 2;
            }
        }
        return cnt == 3;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 1; i <= n / i; ++i) {
            if (n % i == 0) {
                cnt += n / i == i ? 1 : 2;
            }
        }
        return cnt == 3;
    }
};
```

#### Go

```go
func isThree(n int) bool {
	cnt := 0
	for i := 1; i <= n/i; i++ {
		if n%i == 0 {
			if n/i == i {
				cnt++
			} else {
				cnt += 2
			}
		}
	}
	return cnt == 3
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isThree = function (n) {
    let cnt = 0;
    for (let i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            cnt += ~~(n / i) == i ? 1 : 2;
        }
    }
    return cnt == 3;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1953. 你可以工作的最大周数](https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work){#1953}

{{< tabs "1953" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        mx, s = max(milestones), sum(milestones)
        rest = s - mx
        return rest * 2 + 1 if mx > rest + 1 else s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long numberOfWeeks(int[] milestones) {
        int mx = 0;
        long s = 0;
        for (int e : milestones) {
            s += e;
            mx = Math.max(mx, e);
        }
        long rest = s - mx;
        return mx > rest + 1 ? rest * 2 + 1 : s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long s = accumulate(milestones.begin(), milestones.end(), 0LL);
        long long rest = s - mx;
        return mx > rest + 1 ? rest * 2 + 1 : s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWeeks(milestones []int) int64 {
	mx := slices.Max(milestones)
	s := 0
	for _, x := range milestones {
		s += x
	}
	rest := s - mx
	if mx > rest+1 {
		return int64(rest*2 + 1)
	}
	return int64(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWeeks(milestones: number[]): number {
    const mx = Math.max(...milestones);
    const s = milestones.reduce((a, b) => a + b, 0);
    const rest = s - mx;
    return mx > rest + 1 ? rest * 2 + 1 : s;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你&nbsp;<code>n</code> 个项目，编号从 <code>0</code> 到 <code>n - 1</code> 。同时给你一个整数数组 <code>milestones</code> ，其中每个 <code>milestones[i]</code> 表示第 <code>i</code> 个项目中的阶段任务数量。</p>

<p>你可以按下面两个规则参与项目中的工作：</p>

<ul>
	<li>每周，你将会完成 <strong>某一个</strong> 项目中的 <strong>恰好一个</strong>&nbsp;阶段任务。你每周都 <strong>必须</strong> 工作。</li>
	<li>在 <strong>连续的</strong> 两周中，你 <strong>不能</strong> 参与并完成同一个项目中的两个阶段任务。</li>
</ul>

<p>一旦所有项目中的全部阶段任务都完成，或者执行仅剩的一个阶段任务将会导致你违反上面的规则，你将 <strong>停止工作</strong>。注意，由于这些条件的限制，你可能无法完成所有阶段任务。</p>

<p>返回在不违反上面规则的情况下你&nbsp;<strong>最多</strong>&nbsp;能工作多少周。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>milestones = [1,2,3]
<strong>输出：</strong>6
<strong>解释：</strong>一种可能的情形是：
​​​​- 第 1 周，你参与并完成项目 0 中的一个阶段任务。
- 第 2 周，你参与并完成项目 2 中的一个阶段任务。
- 第 3 周，你参与并完成项目 1 中的一个阶段任务。
- 第 4 周，你参与并完成项目 2 中的一个阶段任务。
- 第 5 周，你参与并完成项目 1 中的一个阶段任务。
- 第 6 周，你参与并完成项目 2 中的一个阶段任务。
总周数是 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>milestones = [5,2,1]
<strong>输出：</strong>7
<strong>解释：</strong>一种可能的情形是：
- 第 1 周，你参与并完成项目 0 中的一个阶段任务。
- 第 2 周，你参与并完成项目 1 中的一个阶段任务。
- 第 3 周，你参与并完成项目 0 中的一个阶段任务。
- 第 4 周，你参与并完成项目 1 中的一个阶段任务。
- 第 5 周，你参与并完成项目 0 中的一个阶段任务。
- 第 6 周，你参与并完成项目 2 中的一个阶段任务。
- 第 7 周，你参与并完成项目 0 中的一个阶段任务。
总周数是 7 。
注意，你不能在第 8 周参与完成项目 0 中的最后一个阶段任务，因为这会违反规则。
因此，项目 0 中会有一个阶段任务维持未完成状态。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == milestones.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= milestones[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们考虑什么情况下不能完成所有阶段任务。如果存在一个项目 $i$，它的阶段任务数大于其余所有项目的阶段任务数之和再加 $1$，那么就不能完成所有阶段任务。否则，我们一定可以通过不同项目之间来回穿插的方式完成所有阶段任务。

我们记所有项目的阶段任务数之和为 $s$，最大的阶段任务数为 $mx$，那么其余所有项目的阶段任务数之和为 $rest = s - mx$。

如果 $mx \gt rest + 1$，那么就不能完成所有阶段任务，最多只能完成 $rest \times 2 + 1$ 个阶段任务。否则，我们可以完成所有阶段任务，数量为 $s$。

时间复杂度 $O(n)$，其中 $n$ 为项目数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        mx, s = max(milestones), sum(milestones)
        rest = s - mx
        return rest * 2 + 1 if mx > rest + 1 else s
```

#### Java

```java
class Solution {
    public long numberOfWeeks(int[] milestones) {
        int mx = 0;
        long s = 0;
        for (int e : milestones) {
            s += e;
            mx = Math.max(mx, e);
        }
        long rest = s - mx;
        return mx > rest + 1 ? rest * 2 + 1 : s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long s = accumulate(milestones.begin(), milestones.end(), 0LL);
        long long rest = s - mx;
        return mx > rest + 1 ? rest * 2 + 1 : s;
    }
};
```

#### Go

```go
func numberOfWeeks(milestones []int) int64 {
	mx := slices.Max(milestones)
	s := 0
	for _, x := range milestones {
		s += x
	}
	rest := s - mx
	if mx > rest+1 {
		return int64(rest*2 + 1)
	}
	return int64(s)
}
```

#### TypeScript

```ts
function numberOfWeeks(milestones: number[]): number {
    const mx = Math.max(...milestones);
    const s = milestones.reduce((a, b) => a + b, 0);
    const rest = s - mx;
    return mx > rest + 1 ? rest * 2 + 1 : s;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1954. 收集足够苹果的最小花园周长](https://leetcode.cn/problems/minimum-garden-perimeter-to-collect-enough-apples){#1954}

{{< tabs "1954" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        l, r = 1, 100000
        while l < r:
            mid = (l + r) >> 1
            if 2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples:
                r = mid
            else:
                l = mid + 1
        return l * 8
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumPerimeter(long neededApples) {
        long l = 1, r = 100000;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l * 8;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, r = 100000;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l * 8;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumPerimeter(neededApples int64) int64 {
	var l, r int64 = 1, 100000
	for l < r {
		mid := (l + r) >> 1
		if 2*mid*(mid+1)*(2*mid+1) >= neededApples {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l * 8
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumPerimeter(neededApples: number): number {
    let l = 1;
    let r = 100000;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return 8 * l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个用无限二维网格表示的花园，<strong>每一个</strong>&nbsp;整数坐标处都有一棵苹果树。整数坐标&nbsp;<code>(i, j)</code>&nbsp;处的苹果树有 <code>|i| + |j|</code>&nbsp;个苹果。</p>

<p>你将会买下正中心坐标是 <code>(0, 0)</code>&nbsp;的一块 <strong>正方形土地</strong>&nbsp;，且每条边都与两条坐标轴之一平行。</p>

<p>给你一个整数&nbsp;<code>neededApples</code>&nbsp;，请你返回土地的&nbsp;<strong>最小周长</strong>&nbsp;，使得&nbsp;<strong>至少</strong>&nbsp;有<strong>&nbsp;</strong><code>neededApples</code>&nbsp;个苹果在土地&nbsp;<strong>里面或者边缘上</strong>。</p>

<p><code>|x|</code>&nbsp;的值定义为：</p>

<ul>
	<li>如果&nbsp;<code>x &gt;= 0</code>&nbsp;，那么值为&nbsp;<code>x</code></li>
	<li>如果&nbsp;<code>x &lt;&nbsp;0</code>&nbsp;，那么值为&nbsp;<code>-x</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1954.Minimum%20Garden%20Perimeter%20to%20Collect%20Enough%20Apples/images/1627790803-qcBKFw-image.png" style="width: 442px; height: 449px;" />
<pre>
<b>输入：</b>neededApples = 1
<b>输出：</b>8
<b>解释：</b>边长长度为 1 的正方形不包含任何苹果。
但是边长为 2 的正方形包含 12 个苹果（如上图所示）。
周长为 2 * 4 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>neededApples = 13
<b>输出：</b>16
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>neededApples = 1000000000
<b>输出：</b>5040
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= neededApples &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 枚举

假设正方形右上角坐标为 $(n, n)$，那么它的边长为 $2n$，周长为 $8n$，里面的苹果总数为：

$$
\begin{aligned}
&\sum_{x=-n}^{n} \sum_{y=-n}^{n} |x| + |y| \\
\end{aligned}
$$

由于 $x$ 和 $y$ 是对称的，所以可以化简为：

$$
\begin{aligned}
&\sum_{x=-n}^{n} \sum_{y=-n}^{n} |x| + |y| \\
&= 2 \sum_{x=-n}^{n} \sum_{y=-n}^{n} |x| \\
&= 2 \sum_{x=-n}^{n} (2n + 1) |x| \\
&= 2 (2n + 1) \sum_{x=-n}^{n} |x| \\
&= 2n(n+1)(2n+1)
\end{aligned}
$$

所以，我们只需要枚举 $n$，直到找到第一个满足 $2n(n+1)(2n+1) \geq neededApples$ 的 $n$ 即可。

时间复杂度 $O(m^{\frac{1}{3}})$，其中 $m$ 为 $neededApples$ 的值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        x = 1
        while 2 * x * (x + 1) * (2 * x + 1) < neededApples:
            x += 1
        return x * 8
```

#### Java

```java
class Solution {
    public long minimumPerimeter(long neededApples) {
        long x = 1;
        while (2 * x * (x + 1) * (2 * x + 1) < neededApples) {
            ++x;
        }
        return 8 * x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long x = 1;
        while (2 * x * (x + 1) * (2 * x + 1) < neededApples) {
            ++x;
        }
        return 8 * x;
    }
};
```

#### Go

```go
func minimumPerimeter(neededApples int64) int64 {
	var x int64 = 1
	for 2*x*(x+1)*(2*x+1) < neededApples {
		x++
	}
	return 8 * x
}
```

#### TypeScript

```ts
function minimumPerimeter(neededApples: number): number {
    let x = 1;
    while (2 * x * (x + 1) * (2 * x + 1) < neededApples) {
        ++x;
    }
    return 8 * x;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

我们也可以二分枚举 $n$，时间复杂度 $O(\log m)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        l, r = 1, 100000
        while l < r:
            mid = (l + r) >> 1
            if 2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples:
                r = mid
            else:
                l = mid + 1
        return l * 8
```

#### Java

```java
class Solution {
    public long minimumPerimeter(long neededApples) {
        long l = 1, r = 100000;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l * 8;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, r = 100000;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l * 8;
    }
};
```

#### Go

```go
func minimumPerimeter(neededApples int64) int64 {
	var l, r int64 = 1, 100000
	for l < r {
		mid := (l + r) >> 1
		if 2*mid*(mid+1)*(2*mid+1) >= neededApples {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l * 8
}
```

#### TypeScript

```ts
function minimumPerimeter(neededApples: number): number {
    let l = 1;
    let r = 100000;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (2 * mid * (mid + 1) * (2 * mid + 1) >= neededApples) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return 8 * l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1955. 统计特殊子序列的数目](https://leetcode.cn/problems/count-number-of-special-subsequences){#1955}

{{< tabs "1955" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        f = [0] * 3
        f[0] = nums[0] == 0
        for i in range(1, n):
            if nums[i] == 0:
                f[0] = (2 * f[0] + 1) % mod
            elif nums[i] == 1:
                f[1] = (f[0] + 2 * f[1]) % mod
            else:
                f[2] = (f[1] + 2 * f[2]) % mod
        return f[2]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSpecialSubsequences(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[] f = new int[3];
        f[0] = nums[0] == 0 ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                f[0] = (2 * f[0] % mod + 1) % mod;
            } else if (nums[i] == 1) {
                f[1] = (f[0] + 2 * f[1] % mod) % mod;
            } else {
                f[2] = (f[1] + 2 * f[2] % mod) % mod;
            }
        }
        return f[2];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int f[3]{0};
        f[0] = nums[0] == 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                f[0] = (2 * f[0] % mod + 1) % mod;
            } else if (nums[i] == 1) {
                f[1] = (f[0] + 2 * f[1] % mod) % mod;
            } else {
                f[2] = (f[1] + 2 * f[2] % mod) % mod;
            }
        }
        return f[2];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSpecialSubsequences(nums []int) int {
	const mod = 1e9 + 7
	n := len(nums)
	f := [3]int{}
	if nums[0] == 0 {
		f[0] = 1
	}
	for i := 1; i < n; i++ {
		if nums[i] == 0 {
			f[0] = (2*f[0] + 1) % mod
		} else if nums[i] == 1 {
			f[1] = (f[0] + 2*f[1]) % mod
		} else {
			f[2] = (f[1] + 2*f[2]) % mod
		}
	}
	return f[2]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSpecialSubsequences(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const f: number[] = [0, 0, 0];
    f[0] = nums[0] === 0 ? 1 : 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] === 0) {
            f[0] = (((2 * f[0]) % mod) + 1) % mod;
            f[1] = f[1];
            f[2] = f[2];
        } else if (nums[i] === 1) {
            f[0] = f[0];
            f[1] = (f[0] + ((2 * f[1]) % mod)) % mod;
            f[2] = f[2];
        } else {
            f[0] = f[0];
            f[1] = f[1];
            f[2] = (f[1] + ((2 * f[2]) % mod)) % mod;
        }
    }
    return f[2];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>特殊序列</strong> 是由&nbsp;<strong>正整数</strong>&nbsp;个 <code>0</code>&nbsp;，紧接着&nbsp;<strong>正整数</strong>&nbsp;个 <code>1</code>&nbsp;，最后 <strong>正整数</strong>&nbsp;个 <code>2</code>&nbsp;组成的序列。</p>

<ul>
	<li>比方说，<code>[0,1,2]</code> 和&nbsp;<code>[0,0,1,1,1,2]</code>&nbsp;是特殊序列。</li>
	<li>相反，<code>[2,1,0]</code>&nbsp;，<code>[1]</code>&nbsp;和&nbsp;<code>[0,1,2,0]</code>&nbsp;就不是特殊序列。</li>
</ul>

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;（<strong>仅</strong>&nbsp;包含整数&nbsp;<code>0</code>，<code>1</code>&nbsp;和&nbsp;<code>2</code>），请你返回 <b>不同特殊子序列的数目</b>&nbsp;。由于答案可能很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后返回。</p>

<p>一个数组的 <strong>子序列</strong>&nbsp;是从原数组中删除零个或者若干个元素后，剩下元素不改变顺序得到的序列。如果两个子序列的 <strong>下标集合</strong>&nbsp;不同，那么这两个子序列是 <strong>不同的</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [0,1,2,2]
<b>输出：</b>3
<b>解释：</b>特殊子序列为 [<strong>0</strong>,<strong>1</strong>,<strong>2</strong>,2]，[<strong>0</strong>,<strong>1</strong>,2,<strong>2</strong>] 和 [<strong>0</strong>,<strong>1</strong>,<strong>2</strong>,<strong>2</strong>] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,2,0,0]
<b>输出：</b>0
<b>解释：</b>数组 [2,2,0,0] 中没有特殊子序列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [0,1,2,0,1,2]
<b>输出：</b>7
<b>解释：</b>特殊子序列包括：
- [<strong>0</strong>,<strong>1</strong>,<strong>2</strong>,0,1,2]
- [<strong>0</strong>,<strong>1</strong>,2,0,1,<strong>2</strong>]
- [<strong>0</strong>,<strong>1</strong>,<strong>2</strong>,0,1,<strong>2</strong>]
- [<strong>0</strong>,<strong>1</strong>,2,0,<strong>1</strong>,<strong>2</strong>]
- [<strong>0</strong>,1,2,<strong>0</strong>,<strong>1</strong>,<strong>2</strong>]
- [<strong>0</strong>,1,2,0,<strong>1</strong>,<strong>2</strong>]
- [0,1,2,<strong>0</strong>,<strong>1</strong>,<strong>2</strong>]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i+1$ 个元素中，以 $j$ 结尾的特殊子序列的个数。初始时 $f[i][j]=0$，如果 $nums[0]=0$，则 $f[0][0]=1$。

对于 $i \gt 0$，我们考虑 $nums[i]$ 的值：

如果 $nums[i] = 0$：如果我们不选择 $nums[i]$，则 $f[i][0] = f[i-1][0]$；如果我们选择 $nums[i]$，那么 $f[i][0]=f[i-1][0]+1$，因为我们可以在任何一个以 $0$ 结尾的特殊子序列后面加上一个 $0$ 得到一个新的特殊子序列，也可以将 $nums[i]$ 单独作为一个特殊子序列。因此 $f[i][0] = 2 \times f[i - 1][0] + 1$。其余的 $f[i][j]$ 与 $f[i-1][j]$ 相等。

如果 $nums[i] = 1$：如果我们不选择 $nums[i]$，则 $f[i][1] = f[i-1][1]$；如果我们选择 $nums[i]$，那么 $f[i][1]=f[i-1][1]+f[i-1][0]$，因为我们可以在任何一个以 $0$ 或 $1$ 结尾的特殊子序列后面加上一个 $1$ 得到一个新的特殊子序列。因此 $f[i][1] = f[i-1][0] + 2 \times f[i - 1][1]$。其余的 $f[i][j]$ 与 $f[i-1][j]$ 相等。

如果 $nums[i] = 2$：如果我们不选择 $nums[i]$，则 $f[i][2] = f[i-1][2]$；如果我们选择 $nums[i]$，那么 $f[i][2]=f[i-1][2]+f[i-1][1]$，因为我们可以在任何一个以 $1$ 或 $2$ 结尾的特殊子序列后面加上一个 $2$ 得到一个新的特殊子序列。因此 $f[i][2] = f[i-1][1] + 2 \times f[i - 1][2]$。其余的 $f[i][j]$ 与 $f[i-1][j]$ 相等。

综上，我们可以得到如下的状态转移方程：

$$
\begin{aligned}
f[i][0] &= 2 \times f[i - 1][0] + 1, \quad nums[i] = 0 \\
f[i][1] &= f[i-1][0] + 2 \times f[i - 1][1], \quad nums[i] = 1 \\
f[i][2] &= f[i-1][1] + 2 \times f[i - 1][2], \quad nums[i] = 2 \\
f[i][j] &= f[i-1][j], \quad nums[i] \neq j
\end{aligned}
$$

最终的答案即为 $f[n-1][2]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        f = [[0] * 3 for _ in range(n)]
        f[0][0] = nums[0] == 0
        for i in range(1, n):
            if nums[i] == 0:
                f[i][0] = (2 * f[i - 1][0] + 1) % mod
                f[i][1] = f[i - 1][1]
                f[i][2] = f[i - 1][2]
            elif nums[i] == 1:
                f[i][0] = f[i - 1][0]
                f[i][1] = (f[i - 1][0] + 2 * f[i - 1][1]) % mod
                f[i][2] = f[i - 1][2]
            else:
                f[i][0] = f[i - 1][0]
                f[i][1] = f[i - 1][1]
                f[i][2] = (f[i - 1][1] + 2 * f[i - 1][2]) % mod
        return f[n - 1][2]
```

#### Java

```java
class Solution {
    public int countSpecialSubsequences(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[][] f = new int[n][3];
        f[0][0] = nums[0] == 0 ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                f[i][0] = (2 * f[i - 1][0] % mod + 1) % mod;
                f[i][1] = f[i - 1][1];
                f[i][2] = f[i - 1][2];
            } else if (nums[i] == 1) {
                f[i][0] = f[i - 1][0];
                f[i][1] = (f[i - 1][0] + 2 * f[i - 1][1] % mod) % mod;
                f[i][2] = f[i - 1][2];
            } else {
                f[i][0] = f[i - 1][0];
                f[i][1] = f[i - 1][1];
                f[i][2] = (f[i - 1][1] + 2 * f[i - 1][2] % mod) % mod;
            }
        }
        return f[n - 1][2];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int f[n][3];
        memset(f, 0, sizeof(f));
        f[0][0] = nums[0] == 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                f[i][0] = (2 * f[i - 1][0] % mod + 1) % mod;
                f[i][1] = f[i - 1][1];
                f[i][2] = f[i - 1][2];
            } else if (nums[i] == 1) {
                f[i][0] = f[i - 1][0];
                f[i][1] = (f[i - 1][0] + 2 * f[i - 1][1] % mod) % mod;
                f[i][2] = f[i - 1][2];
            } else {
                f[i][0] = f[i - 1][0];
                f[i][1] = f[i - 1][1];
                f[i][2] = (f[i - 1][1] + 2 * f[i - 1][2] % mod) % mod;
            }
        }
        return f[n - 1][2];
    }
};
```

#### Go

```go
func countSpecialSubsequences(nums []int) int {
	const mod = 1e9 + 7
	n := len(nums)
	f := make([][3]int, n)
	if nums[0] == 0 {
		f[0][0] = 1
	}
	for i := 1; i < n; i++ {
		if nums[i] == 0 {
			f[i][0] = (2*f[i-1][0] + 1) % mod
			f[i][1] = f[i-1][1]
			f[i][2] = f[i-1][2]
		} else if nums[i] == 1 {
			f[i][0] = f[i-1][0]
			f[i][1] = (f[i-1][0] + 2*f[i-1][1]) % mod
			f[i][2] = f[i-1][2]
		} else {
			f[i][0] = f[i-1][0]
			f[i][1] = f[i-1][1]
			f[i][2] = (f[i-1][1] + 2*f[i-1][2]) % mod
		}
	}
	return f[n-1][2]
}
```

#### TypeScript

```ts
function countSpecialSubsequences(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const f: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));
    f[0][0] = nums[0] === 0 ? 1 : 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] === 0) {
            f[i][0] = (((2 * f[i - 1][0]) % mod) + 1) % mod;
            f[i][1] = f[i - 1][1];
            f[i][2] = f[i - 1][2];
        } else if (nums[i] === 1) {
            f[i][0] = f[i - 1][0];
            f[i][1] = (f[i - 1][0] + ((2 * f[i - 1][1]) % mod)) % mod;
            f[i][2] = f[i - 1][2];
        } else {
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
            f[i][2] = (f[i - 1][1] + ((2 * f[i - 1][2]) % mod)) % mod;
        }
    }
    return f[n - 1][2];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们注意到，上述的状态转移方程中，$f[i][j]$ 的值仅与 $f[i-1][j]$ 有关，因此我们可以去掉第一维，将空间复杂度优化到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        f = [0] * 3
        f[0] = nums[0] == 0
        for i in range(1, n):
            if nums[i] == 0:
                f[0] = (2 * f[0] + 1) % mod
            elif nums[i] == 1:
                f[1] = (f[0] + 2 * f[1]) % mod
            else:
                f[2] = (f[1] + 2 * f[2]) % mod
        return f[2]
```

#### Java

```java
class Solution {
    public int countSpecialSubsequences(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[] f = new int[3];
        f[0] = nums[0] == 0 ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                f[0] = (2 * f[0] % mod + 1) % mod;
            } else if (nums[i] == 1) {
                f[1] = (f[0] + 2 * f[1] % mod) % mod;
            } else {
                f[2] = (f[1] + 2 * f[2] % mod) % mod;
            }
        }
        return f[2];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int f[3]{0};
        f[0] = nums[0] == 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                f[0] = (2 * f[0] % mod + 1) % mod;
            } else if (nums[i] == 1) {
                f[1] = (f[0] + 2 * f[1] % mod) % mod;
            } else {
                f[2] = (f[1] + 2 * f[2] % mod) % mod;
            }
        }
        return f[2];
    }
};
```

#### Go

```go
func countSpecialSubsequences(nums []int) int {
	const mod = 1e9 + 7
	n := len(nums)
	f := [3]int{}
	if nums[0] == 0 {
		f[0] = 1
	}
	for i := 1; i < n; i++ {
		if nums[i] == 0 {
			f[0] = (2*f[0] + 1) % mod
		} else if nums[i] == 1 {
			f[1] = (f[0] + 2*f[1]) % mod
		} else {
			f[2] = (f[1] + 2*f[2]) % mod
		}
	}
	return f[2]
}
```

#### TypeScript

```ts
function countSpecialSubsequences(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const f: number[] = [0, 0, 0];
    f[0] = nums[0] === 0 ? 1 : 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] === 0) {
            f[0] = (((2 * f[0]) % mod) + 1) % mod;
            f[1] = f[1];
            f[2] = f[2];
        } else if (nums[i] === 1) {
            f[0] = f[0];
            f[1] = (f[0] + ((2 * f[1]) % mod)) % mod;
            f[2] = f[2];
        } else {
            f[0] = f[0];
            f[1] = f[1];
            f[2] = (f[1] + ((2 * f[2]) % mod)) % mod;
        }
    }
    return f[2];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1956. 感染 K 种病毒所需的最短时间 🔒](https://leetcode.cn/problems/minimum-time-for-k-virus-variants-to-spread){#1956}

{{< tabs "1956" >}}

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

<p>在无限大的二维平面上有&nbsp;<code>n</code>&nbsp;种 <strong>不同</strong> 的病毒。给定二维数组&nbsp;<code>points</code>&nbsp;，<span style="">第 </span><code>i</code><span style=""> 项&nbsp;</span><code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;说明第&nbsp;<code>0</code>&nbsp;天有一种病毒在点&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;。注意初始状态下，可能有 <strong>多种</strong> 病毒在 <strong>同一点</strong> 上。</p>

<p>每天，被感染的点会把它感染的病毒传播到上、下、左、右四个邻居点。</p>

<p>现给定一个整数 <code>k</code>&nbsp;，问 <strong>最少</strong> 需要多少天，方能找到一点感染 <strong>至少</strong> <code>k</code> 种病毒？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1956.Minimum%20Time%20For%20K%20Virus%20Variants%20to%20Spread/images/case-1.png" style="width: 421px; height: 256px;" /></strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[6,1]], k = 2
<b>输出：</b>3
<strong>解释：</strong>在第 3 天，点 (3,1) 与 (4,1) 将感染所有 2 种病毒。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1956.Minimum%20Time%20For%20K%20Virus%20Variants%20to%20Spread/images/case-2.png" style="width: 416px; height: 257px;" /></strong></p>

<pre>
<strong>输入：</strong>points = [[3,3],[1,2],[9,2]], k = 2
<b>输出：</b>2
<b>解释：</b>在第 2 天, 点 (1,2), (1,3), (2,1), (2,2), (3,1) 和 (3,3) 将会感染前两种病毒。
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1956.Minimum%20Time%20For%20K%20Virus%20Variants%20to%20Spread/images/case-2.png" style="width: 416px; height: 257px;" /></strong></p>

<pre>
<b>输入：</b>points = [[3,3],[1,2],[9,2]], k = 3
<b>输出：</b>4
<strong>解释：</strong>在第 4 天，点 (5,2) 会感染所有 3 种病毒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>2 &lt;= n &lt;= 50</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>2 &lt;= k &lt;= n</code></li>
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

# [1957. 删除字符使字符串变好](https://leetcode.cn/problems/delete-characters-to-make-fancy-string){#1957}

{{< tabs "1957" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = []
        for i, c in enumerate(s):
            if i < 2 or c != s[i - 1] or c != s[i - 2]:
                ans.append(c)
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (i < 2 || c != s.charAt(i - 1) || c != s.charAt(i - 2)) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (i < 2 || c != s[i - 1] || c != s[i - 2]) {
                ans += c;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeFancyString(s string) string {
	ans := []byte{}
	for i, ch := range s {
		if c := byte(ch); i < 2 || c != s[i-1] || c != s[i-2] {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeFancyString(s: string): string {
    const ans: string[] = [];
    for (let i = 0; i < s.length; ++i) {
        if (s[i] !== s[i - 1] || s[i] !== s[i - 2]) {
            ans.push(s[i]);
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function (s) {
    const ans = [];
    for (let i = 0; i < s.length; ++i) {
        if (s[i] !== s[i - 1] || s[i] !== s[i - 2]) {
            ans.push(s[i]);
        }
    }
    return ans.join('');
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function makeFancyString($s) {
        $ans = '';
        for ($i = 0; $i < strlen($s); $i++) {
            $c = $s[$i];
            if ($i < 2 || $c !== $s[$i - 1] || $c !== $s[$i - 2]) {
                $ans .= $c;
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

<p>一个字符串如果没有 <strong>三个连续</strong>&nbsp;相同字符，那么它就是一个 <strong>好字符串</strong>&nbsp;。</p>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你从 <code>s</code>&nbsp;删除&nbsp;<strong>最少</strong>&nbsp;的字符，使它变成一个 <strong>好字符串</strong> 。</p>

<p>请你返回删除后的字符串。题目数据保证答案总是 <strong>唯一的 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "le<strong>e</strong>etcode"
<b>输出：</b>"leetcode"
<strong>解释：</strong>
从第一组 'e' 里面删除一个 'e' ，得到 "leetcode" 。
没有连续三个相同字符，所以返回 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "<strong>a</strong>aab<strong>aa</strong>aa"
<b>输出：</b>"aabaa"
<strong>解释：</strong>
从第一组 'a' 里面删除一个 'a' ，得到 "aabaaaa" 。
从第二组 'a' 里面删除两个 'a' ，得到 "aabaa" 。
没有连续三个相同字符，所以返回 "aabaa" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "aab"
<b>输出：</b>"aab"
<b>解释：</b>没有连续三个相同字符，所以返回 "aab" 。
</pre>

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

### 方法一：模拟

我们可以遍历字符串 $s$，并使用一个数组 $\textit{ans}$ 记录当前的答案。对于每一个字符 $\textit{s[i]}$，如果 $i \lt 2$ 或者 $s[i]$ 与 $s[i - 1]$ 不等，或者 $s[i]$ 与 $s[i - 2]$ 不等，我们就将 $s[i]$ 添加到 $\textit{ans}$ 中。

最后，我们将 $\textit{ans}$ 中的字符连接起来，就得到了答案。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = []
        for i, c in enumerate(s):
            if i < 2 or c != s[i - 1] or c != s[i - 2]:
                ans.append(c)
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (i < 2 || c != s.charAt(i - 1) || c != s.charAt(i - 2)) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (i < 2 || c != s[i - 1] || c != s[i - 2]) {
                ans += c;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func makeFancyString(s string) string {
	ans := []byte{}
	for i, ch := range s {
		if c := byte(ch); i < 2 || c != s[i-1] || c != s[i-2] {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function makeFancyString(s: string): string {
    const ans: string[] = [];
    for (let i = 0; i < s.length; ++i) {
        if (s[i] !== s[i - 1] || s[i] !== s[i - 2]) {
            ans.push(s[i]);
        }
    }
    return ans.join('');
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function (s) {
    const ans = [];
    for (let i = 0; i < s.length; ++i) {
        if (s[i] !== s[i - 1] || s[i] !== s[i - 2]) {
            ans.push(s[i]);
        }
    }
    return ans.join('');
};
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function makeFancyString($s) {
        $ans = '';
        for ($i = 0; $i < strlen($s); $i++) {
            $c = $s[$i];
            if ($i < 2 || $c !== $s[$i - 1] || $c !== $s[$i - 2]) {
                $ans .= $c;
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

# [1958. 检查操作是否合法](https://leetcode.cn/problems/check-if-move-is-legal){#1958}

{{< tabs "1958" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkMove(
        self, board: List[List[str]], rMove: int, cMove: int, color: str
    ) -> bool:
        for a in range(-1, 2):
            for b in range(-1, 2):
                if a == 0 and b == 0:
                    continue
                i, j = rMove, cMove
                cnt = 0
                while 0 <= i + a < 8 and 0 <= j + b < 8:
                    cnt += 1
                    i, j = i + a, j + b
                    if cnt > 1 and board[i][j] == color:
                        return True
                    if board[i][j] in (color, "."):
                        break
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a == 0 && b == 0) {
                    continue;
                }
                int i = rMove, j = cMove;
                int cnt = 0;
                while (0 <= i + a && i + a < 8 && 0 <= j + b && j + b < 8) {
                    i += a;
                    j += b;
                    if (++cnt > 1 && board[i][j] == color) {
                        return true;
                    }
                    if (board[i][j] == color || board[i][j] == '.') {
                        break;
                    }
                }
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
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a == 0 && b == 0) {
                    continue;
                }
                int i = rMove, j = cMove;
                int cnt = 0;
                while (0 <= i + a && i + a < 8 && 0 <= j + b && j + b < 8) {
                    i += a;
                    j += b;
                    if (++cnt > 1 && board[i][j] == color) {
                        return true;
                    }
                    if (board[i][j] == color || board[i][j] == '.') {
                        break;
                    }
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkMove(board [][]byte, rMove int, cMove int, color byte) bool {
	for a := -1; a <= 1; a++ {
		for b := -1; b <= 1; b++ {
			if a == 0 && b == 0 {
				continue
			}
			i, j := rMove, cMove
			cnt := 0
			for 0 <= i+a && i+a < 8 && 0 <= j+b && j+b < 8 {
				i += a
				j += b
				cnt++
				if cnt > 1 && board[i][j] == color {
					return true
				}
				if board[i][j] == color || board[i][j] == '.' {
					break
				}
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkMove(board: string[][], rMove: number, cMove: number, color: string): boolean {
    for (let a = -1; a <= 1; ++a) {
        for (let b = -1; b <= 1; ++b) {
            if (a === 0 && b === 0) {
                continue;
            }
            let [i, j] = [rMove, cMove];
            let cnt = 0;
            while (0 <= i + a && i + a < 8 && 0 <= j + b && j + b < 8) {
                i += a;
                j += b;
                if (++cnt > 1 && board[i][j] === color) {
                    return true;
                }
                if (board[i][j] === color || board[i][j] === '.') {
                    break;
                }
            }
        }
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

<p>给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的&nbsp;<code>8 x 8</code> 网格&nbsp;<code>board</code>&nbsp;，其中&nbsp;<code>board[r][c]</code>&nbsp;表示游戏棋盘上的格子&nbsp;<code>(r, c)</code>&nbsp;。棋盘上空格用&nbsp;<code>'.'</code>&nbsp;表示，白色格子用&nbsp;<code>'W'</code>&nbsp;表示，黑色格子用&nbsp;<code>'B'</code>&nbsp;表示。</p>

<p>游戏中每次操作步骤为：选择一个空格子，将它变成你正在执行的颜色（要么白色，要么黑色）。但是，<strong>合法 </strong>操作必须满足：涂色后这个格子是 <strong>好线段的一个端点</strong>&nbsp;（好线段可以是水平的，竖直的或者是对角线）。</p>

<p><strong>好线段</strong>&nbsp;指的是一个包含 <strong>三个或者更多格子（包含端点格子）</strong>的线段，线段两个端点格子为 <strong>同一种颜色</strong>&nbsp;，且中间剩余格子的颜色都为 <strong>另一种颜色</strong>&nbsp;（线段上不能有任何空格子）。你可以在下图找到好线段的例子：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1958.Check%20if%20Move%20is%20Legal/images/goodlines5.png" style="width: 500px; height: 312px;" />
<p>给你两个整数&nbsp;<code>rMove</code> 和&nbsp;<code>cMove</code>&nbsp;以及一个字符&nbsp;<code>color</code>&nbsp;，表示你正在执行操作的颜色（白或者黑），如果将格子&nbsp;<code>(rMove, cMove)</code>&nbsp;变成颜色&nbsp;<code>color</code>&nbsp;后，是一个&nbsp;<strong>合法</strong>&nbsp;操作，那么返回&nbsp;<code>true</code>&nbsp;，如果不是合法操作返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1958.Check%20if%20Move%20is%20Legal/images/grid11.png" style="width: 350px; height: 350px;" /></p>

<pre>
<b>输入：</b>board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
<b>输出：</b>true
<b>解释：</b>'.'，'W' 和 'B' 分别用颜色蓝色，白色和黑色表示。格子 (rMove, cMove) 用 'X' 标记。
以选中格子为端点的两个好线段在上图中用红色矩形标注出来了。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1958.Check%20if%20Move%20is%20Legal/images/grid2.png" style="width: 350px; height: 351px;" /></p>

<pre>
<b>输入：</b>board = [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]], rMove = 4, cMove = 4, color = "W"
<b>输出：</b>false
<b>解释：</b>虽然选中格子涂色后，棋盘上产生了好线段，但选中格子是作为中间格子，没有产生以选中格子为端点的好线段。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == board[r].length == 8</code></li>
	<li><code>0 &lt;= rMove, cMove &lt; 8</code></li>
	<li><code>board[rMove][cMove] == '.'</code></li>
	<li><code>color</code>&nbsp;要么是&nbsp;<code>'B'</code> 要么是&nbsp;<code>'W'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们枚举所有可能的方向，对于每个方向 $(a, b)$，我们从 $(\textit{rMove}, \textit{cMove})$ 出发，用一个变量 $\textit{cnt}$ 记录我们走过的格子数，如果我们在走的过程中遇到了颜色为 $\textit{color}$ 的格子，且 $\textit{cnt} > 1$，那么我们就找到了一个好线段，返回 $\textit{true}$。

枚举结束后，如果我们没有找到任何好线段，那么返回 $\textit{false}$。

时间复杂度 $O(m + n)$，其中 $m$ 为 $\textit{board}$ 的行数，而 $n$ 为 $\textit{board}$ 的列数，本题中 $m = n = 8$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkMove(
        self, board: List[List[str]], rMove: int, cMove: int, color: str
    ) -> bool:
        for a in range(-1, 2):
            for b in range(-1, 2):
                if a == 0 and b == 0:
                    continue
                i, j = rMove, cMove
                cnt = 0
                while 0 <= i + a < 8 and 0 <= j + b < 8:
                    cnt += 1
                    i, j = i + a, j + b
                    if cnt > 1 and board[i][j] == color:
                        return True
                    if board[i][j] in (color, "."):
                        break
        return False
```

#### Java

```java
class Solution {
    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a == 0 && b == 0) {
                    continue;
                }
                int i = rMove, j = cMove;
                int cnt = 0;
                while (0 <= i + a && i + a < 8 && 0 <= j + b && j + b < 8) {
                    i += a;
                    j += b;
                    if (++cnt > 1 && board[i][j] == color) {
                        return true;
                    }
                    if (board[i][j] == color || board[i][j] == '.') {
                        break;
                    }
                }
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
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                if (a == 0 && b == 0) {
                    continue;
                }
                int i = rMove, j = cMove;
                int cnt = 0;
                while (0 <= i + a && i + a < 8 && 0 <= j + b && j + b < 8) {
                    i += a;
                    j += b;
                    if (++cnt > 1 && board[i][j] == color) {
                        return true;
                    }
                    if (board[i][j] == color || board[i][j] == '.') {
                        break;
                    }
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func checkMove(board [][]byte, rMove int, cMove int, color byte) bool {
	for a := -1; a <= 1; a++ {
		for b := -1; b <= 1; b++ {
			if a == 0 && b == 0 {
				continue
			}
			i, j := rMove, cMove
			cnt := 0
			for 0 <= i+a && i+a < 8 && 0 <= j+b && j+b < 8 {
				i += a
				j += b
				cnt++
				if cnt > 1 && board[i][j] == color {
					return true
				}
				if board[i][j] == color || board[i][j] == '.' {
					break
				}
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function checkMove(board: string[][], rMove: number, cMove: number, color: string): boolean {
    for (let a = -1; a <= 1; ++a) {
        for (let b = -1; b <= 1; ++b) {
            if (a === 0 && b === 0) {
                continue;
            }
            let [i, j] = [rMove, cMove];
            let cnt = 0;
            while (0 <= i + a && i + a < 8 && 0 <= j + b && j + b < 8) {
                i += a;
                j += b;
                if (++cnt > 1 && board[i][j] === color) {
                    return true;
                }
                if (board[i][j] === color || board[i][j] === '.') {
                    break;
                }
            }
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1959. K 次调整数组大小浪费的最小总空间](https://leetcode.cn/problems/minimum-total-space-wasted-with-k-resizing-operations){#1959}

{{< tabs "1959" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSpaceWastedKResizing(self, nums: List[int], k: int) -> int:
        k += 1
        n = len(nums)
        g = [[0] * n for _ in range(n)]
        for i in range(n):
            s = mx = 0
            for j in range(i, n):
                s += nums[j]
                mx = max(mx, nums[j])
                g[i][j] = mx * (j - i + 1) - s
        f = [[inf] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                for h in range(i):
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1])
        return f[-1][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSpaceWastedKResizing(int[] nums, int k) {
        ++k;
        int n = nums.length;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            int s = 0, mx = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                mx = Math.max(mx, nums[j]);
                g[i][j] = mx * (j - i + 1) - s;
            }
        }
        int[][] f = new int[n + 1][k + 1];
        int inf = 0x3f3f3f3f;
        for (int i = 0; i < f.length; ++i) {
            Arrays.fill(f[i], inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                }
            }
        }
        return f[n][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        ++k;
        int n = nums.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int s = 0, mx = 0;
            for (int j = i; j < n; ++j) {
                mx = max(mx, nums[j]);
                s += nums[j];
                g[i][j] = mx * (j - i + 1) - s;
            }
        }
        int inf = 0x3f3f3f3f;
        vector<vector<int>> f(n + 1, vector<int>(k + 1, inf));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                }
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSpaceWastedKResizing(nums []int, k int) int {
	k++
	n := len(nums)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		s, mx := 0, 0
		for j := i; j < n; j++ {
			s += nums[j]
			mx = max(mx, nums[j])
			g[i][j] = mx*(j-i+1) - s
		}
	}
	f := make([][]int, n+1)
	inf := 0x3f3f3f3f
	for i := range f {
		f[i] = make([]int, k+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			for h := 0; h < i; h++ {
				f[i][j] = min(f[i][j], f[h][j-1]+g[h][i-1])
			}
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSpaceWastedKResizing(nums: number[], k: number): number {
    k += 1;
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        let s = 0,
            mx = 0;
        for (let j = i; j < n; j++) {
            s += nums[j];
            mx = Math.max(mx, nums[j]);
            g[i][j] = mx * (j - i + 1) - s;
        }
    }

    const inf = Number.POSITIVE_INFINITY;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(inf));
    f[0][0] = 0;

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= k; j++) {
            for (let h = 0; h < i; h++) {
                f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
            }
        }
    }

    return f[n][k];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_space_wasted_k_resizing(nums: Vec<i32>, k: i32) -> i32 {
        let mut k = k + 1;
        let n = nums.len();
        let mut g = vec![vec![0; n]; n];

        for i in 0..n {
            let (mut s, mut mx) = (0, 0);
            for j in i..n {
                s += nums[j];
                mx = mx.max(nums[j]);
                g[i][j] = mx * (j as i32 - i as i32 + 1) - s;
            }
        }

        let inf = 0x3f3f3f3f;
        let mut f = vec![vec![inf; (k + 1) as usize]; n + 1];
        f[0][0] = 0;

        for i in 1..=n {
            for j in 1..=k as usize {
                for h in 0..i {
                    f[i][j] = f[i][j].min(f[h][j - 1] + g[h][i - 1]);
                }
            }
        }

        f[n][k as usize]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在设计一个动态数组。给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;是&nbsp;<code>i</code>&nbsp;时刻数组中的元素数目。除此以外，你还有一个整数 <code>k</code>&nbsp;，表示你可以 <strong>调整</strong>&nbsp;数组大小的 <strong>最多</strong>&nbsp;次数（每次都可以调整成 <strong>任意</strong>&nbsp;大小）。</p>

<p><code>t</code>&nbsp;时刻数组的大小&nbsp;<code>size<sub>t</sub></code>&nbsp;必须大于等于&nbsp;<code>nums[t]</code>&nbsp;，因为数组需要有足够的空间容纳所有元素。<code>t</code>&nbsp;时刻 <strong>浪费的空间</strong>&nbsp;为&nbsp;<code>size<sub>t</sub> - nums[t]</code>&nbsp;，<strong>总</strong>&nbsp;浪费空间为满足&nbsp;<code>0 &lt;= t &lt; nums.length</code>&nbsp;的每一个时刻&nbsp;<code>t</code>&nbsp;浪费的空间&nbsp;<strong>之和</strong>&nbsp;。</p>

<p>在调整数组大小不超过 <code>k</code>&nbsp;次的前提下，请你返回 <strong>最小总浪费空间</strong>&nbsp;。</p>

<p><strong>注意：</strong>数组最开始时可以为&nbsp;<strong>任意大小</strong>&nbsp;，且&nbsp;<strong>不计入</strong>&nbsp;调整大小的操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [10,20], k = 0
<b>输出：</b>10
<b>解释：</b>size = [20,20].
我们可以让数组初始大小为 20 。
总浪费空间为 (20 - 10) + (20 - 20) = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [10,20,30], k = 1
<b>输出：</b>10
<b>解释：</b>size = [20,20,30].
我们可以让数组初始大小为 20 ，然后时刻 2 调整大小为 30 。
总浪费空间为 (20 - 10) + (20 - 20) + (30 - 30) = 10 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [10,20,15,30,20], k = 2
<b>输出：</b>15
<b>解释：</b>size = [10,20,20,30,30].
我们可以让数组初始大小为 10 ，时刻 1 调整大小为 20 ，时刻 3 调整大小为 30 。
总浪费空间为 (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= k &lt;= nums.length - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

题目等价于我们将数组 $\textit{nums}$ 分成 $k + 1$ 段，那么每一段的浪费空间为该段的最大值乘以该段的长度减去该段的元素之和。我们累加每一段的浪费空间，即可得到总浪费空间。我们将 $k$ 加 $1$，那么就相当于将数组分成 $k$ 段。

因此，我们定义数组 $\textit{g}[i][j]$ 表示 $\textit{nums}[i..j]$ 的最大值乘以 $\textit{nums}[i..j]$ 的长度减去 $\textit{nums}[i..j]$ 的元素之和。我们在 $[0, n)$ 的范围内枚举 $i$，在 $[i, n)$ 的范围内枚举 $j$，用一个变量 $s$ 维护 $\textit{nums}[i..j]$ 的元素之和，用一个变量 $\textit{mx}$ 维护 $\textit{nums}[i..j]$ 的最大值，那么我们可以得到：

$$
\textit{g}[i][j] = \textit{mx} \times (j - i + 1) - s
$$

接下来，我们定义 $\textit{f}[i][j]$ 表示前 $i$ 个元素分成 $j$ 段的最小浪费空间。我们初始化 $\textit{f}[0][0] = 0$，其余位置初始化为无穷大。我们在 $[1, n]$ 的范围内枚举 $i$，在 $[1, k]$ 的范围内枚举 $j$，然后我们枚举前 $j - 1$ 段的最后一个元素 $h$，那么有：

$$
\textit{f}[i][j] = \min(\textit{f}[i][j], \
\textit{f}[h][j - 1] + \textit{g}[h][i - 1])
$$

最终答案为 $\textit{f}[n][k]$。

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n \times (n + k))$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSpaceWastedKResizing(self, nums: List[int], k: int) -> int:
        k += 1
        n = len(nums)
        g = [[0] * n for _ in range(n)]
        for i in range(n):
            s = mx = 0
            for j in range(i, n):
                s += nums[j]
                mx = max(mx, nums[j])
                g[i][j] = mx * (j - i + 1) - s
        f = [[inf] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                for h in range(i):
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1])
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int minSpaceWastedKResizing(int[] nums, int k) {
        ++k;
        int n = nums.length;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            int s = 0, mx = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                mx = Math.max(mx, nums[j]);
                g[i][j] = mx * (j - i + 1) - s;
            }
        }
        int[][] f = new int[n + 1][k + 1];
        int inf = 0x3f3f3f3f;
        for (int i = 0; i < f.length; ++i) {
            Arrays.fill(f[i], inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                }
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        ++k;
        int n = nums.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int s = 0, mx = 0;
            for (int j = i; j < n; ++j) {
                mx = max(mx, nums[j]);
                s += nums[j];
                g[i][j] = mx * (j - i + 1) - s;
            }
        }
        int inf = 0x3f3f3f3f;
        vector<vector<int>> f(n + 1, vector<int>(k + 1, inf));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i; ++h) {
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                }
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func minSpaceWastedKResizing(nums []int, k int) int {
	k++
	n := len(nums)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		s, mx := 0, 0
		for j := i; j < n; j++ {
			s += nums[j]
			mx = max(mx, nums[j])
			g[i][j] = mx*(j-i+1) - s
		}
	}
	f := make([][]int, n+1)
	inf := 0x3f3f3f3f
	for i := range f {
		f[i] = make([]int, k+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			for h := 0; h < i; h++ {
				f[i][j] = min(f[i][j], f[h][j-1]+g[h][i-1])
			}
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function minSpaceWastedKResizing(nums: number[], k: number): number {
    k += 1;
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        let s = 0,
            mx = 0;
        for (let j = i; j < n; j++) {
            s += nums[j];
            mx = Math.max(mx, nums[j]);
            g[i][j] = mx * (j - i + 1) - s;
        }
    }

    const inf = Number.POSITIVE_INFINITY;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(inf));
    f[0][0] = 0;

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= k; j++) {
            for (let h = 0; h < i; h++) {
                f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
            }
        }
    }

    return f[n][k];
}
```

#### Rust

```rust
impl Solution {
    pub fn min_space_wasted_k_resizing(nums: Vec<i32>, k: i32) -> i32 {
        let mut k = k + 1;
        let n = nums.len();
        let mut g = vec![vec![0; n]; n];

        for i in 0..n {
            let (mut s, mut mx) = (0, 0);
            for j in i..n {
                s += nums[j];
                mx = mx.max(nums[j]);
                g[i][j] = mx * (j as i32 - i as i32 + 1) - s;
            }
        }

        let inf = 0x3f3f3f3f;
        let mut f = vec![vec![inf; (k + 1) as usize]; n + 1];
        f[0][0] = 0;

        for i in 1..=n {
            for j in 1..=k as usize {
                for h in 0..i {
                    f[i][j] = f[i][j].min(f[h][j - 1] + g[h][i - 1]);
                }
            }
        }

        f[n][k as usize]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
