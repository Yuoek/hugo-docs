---
title: "1820_最多邀请的个数 🔒"
date: 2025-10-08T18:38:27+08:00
weight: 3
tags: [位运算, 几何, 前缀和, 动态规划, 双指针, 图, 堆（优先队列）, 数学, 数据库, 数据流, 数组, 有序集合, 模拟, 深度优先搜索, 矩阵, 设计, 贪心, 递归, 队列]
---

{{< markmap >}}
### [1820_最多邀请的个数 🔒](#1820)
#### [深度优先搜索](#1820)
#### [图](#1820)
#### [数组](#1820)
#### [矩阵](#1820)
### [1821_寻找今年具有正收入的客户 🔒](#1821)
#### [数据库](#1821)
### [1822_数组元素积的符号](#1822)
#### [数组](#1822)
#### [数学](#1822)
### [1823_找出游戏的获胜者](#1823)
#### [递归](#1823)
#### [队列](#1823)
#### [数组](#1823)
#### [数学](#1823)
#### [模拟](#1823)
### [1824_最少侧跳次数](#1824)
#### [贪心](#1824)
#### [数组](#1824)
#### [动态规划](#1824)
### [1825_求出 MK 平均值](#1825)
#### [设计](#1825)
#### [队列](#1825)
#### [数据流](#1825)
#### [有序集合](#1825)
#### [堆（优先队列）](#1825)
### [1826_有缺陷的传感器 🔒](#1826)
#### [数组](#1826)
#### [双指针](#1826)
### [1827_最少操作使数组递增](#1827)
#### [贪心](#1827)
#### [数组](#1827)
### [1828_统计一个圆中点的数目](#1828)
#### [几何](#1828)
#### [数组](#1828)
#### [数学](#1828)
### [1829_每个查询的最大异或值](#1829)
#### [位运算](#1829)
#### [数组](#1829)
#### [前缀和](#1829)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1820_最多邀请的个数 🔒
___
#### 深度优先搜索
___
#### 图
___
#### 数组
___
#### 矩阵
---
### 1821_寻找今年具有正收入的客户 🔒
___
#### 数据库
---
### 1822_数组元素积的符号
___
#### 数组
___
#### 数学
---
### 1823_找出游戏的获胜者
___
#### 递归
___
#### 队列
___
#### 数组
___
#### 数学
___
#### 模拟
---
### 1824_最少侧跳次数
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 1825_求出 MK 平均值
___
#### 设计
___
#### 队列
___
#### 数据流
___
#### 有序集合
___
#### 堆（优先队列）
---
### 1826_有缺陷的传感器 🔒
___
#### 数组
___
#### 双指针
---
### 1827_最少操作使数组递增
___
#### 贪心
___
#### 数组
---
### 1828_统计一个圆中点的数目
___
#### 几何
___
#### 数组
___
#### 数学
---
### 1829_每个查询的最大异或值
___
#### 位运算
___
#### 数组
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 前缀和 |
| 动态规划 | 双指针 | 图 |
| 堆（优先队列） | 数学 | 数据库 |
| 数据流 | 数组 | 有序集合 |
| 模拟 | 深度优先搜索 | 矩阵 |
| 设计 | 贪心 | 递归 |
| 队列 |  |  |

# [1820. 最多邀请的个数 🔒](https://leetcode.cn/problems/maximum-number-of-accepted-invitations){#1820}

{{< tabs "1820" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumInvitations(self, grid: List[List[int]]) -> int:
        def find(i):
            for j, v in enumerate(grid[i]):
                if v and j not in vis:
                    vis.add(j)
                    if match[j] == -1 or find(match[j]):
                        match[j] = i
                        return True
            return False

        m, n = len(grid), len(grid[0])
        match = [-1] * n
        ans = 0
        for i in range(m):
            vis = set()
            ans += find(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] grid;
    private boolean[] vis;
    private int[] match;
    private int n;

    public int maximumInvitations(int[][] grid) {
        int m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        vis = new boolean[n];
        match = new int[n];
        Arrays.fill(match, -1);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            Arrays.fill(vis, false);
            if (find(i)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean find(int i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && !vis[j]) {
                vis[j] = true;
                if (match[j] == -1 || find(match[j])) {
                    match[j] = i;
                    return true;
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
    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool vis[210];
        int match[210];
        memset(match, -1, sizeof match);
        int ans = 0;
        function<bool(int)> find = [&](int i) -> bool {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !vis[j]) {
                    vis[j] = true;
                    if (match[j] == -1 || find(match[j])) {
                        match[j] = i;
                        return true;
                    }
                }
            }
            return false;
        };
        for (int i = 0; i < m; ++i) {
            memset(vis, 0, sizeof vis);
            ans += find(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumInvitations(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	var vis map[int]bool
	match := make([]int, n)
	for i := range match {
		match[i] = -1
	}
	var find func(i int) bool
	find = func(i int) bool {
		for j, v := range grid[i] {
			if v == 1 && !vis[j] {
				vis[j] = true
				if match[j] == -1 || find(match[j]) {
					match[j] = i
					return true
				}
			}
		}
		return false
	}
	ans := 0
	for i := 0; i < m; i++ {
		vis = map[int]bool{}
		if find(i) {
			ans++
		}
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

<p>某一个班级有 <code>m</code> 个男孩和 <code>n</code> 个女孩，即将举行一个派对。</p>

<p>给定一个 <code>m x n</code> 的整数矩阵 <code>grid</code> ，其中 <code>grid[i][j]</code> 等于 <code>0</code> 或 <code>1</code> 。 若 <code>grid[i][j] == 1</code> ，则表示第 <code>i</code> 个男孩可以邀请第 <code>j</code> 个女孩参加派对。 一个男孩最多可以邀请<strong>一个女孩</strong>，一个女孩最多可以接受一个男孩的<strong>一个邀请</strong>。</p>

<p>返回可能的最多邀请的个数。</p>

<p> </p>

<p><b>示例 1:</b></p>

<pre><strong>输入:</strong> grid = [[1,1,1],
               [1,0,1],
               [0,0,1]]
<strong>输出:</strong> 3<strong>
解释:</strong> 按下列方式邀请：
- 第 1 个男孩邀请第 2 个女孩。
- 第 2 个男孩邀请第 1 个女孩。
- 第 3 个男孩邀请第 3 个女孩。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> grid = [[1,0,1,0],
               [1,0,0,0],
               [0,0,1,0],
               [1,1,1,0]]
<strong>输出:</strong> 3
<strong>解释: </strong>按下列方式邀请：
- 第 1 个男孩邀请第 3 个女孩。
- 第 2 个男孩邀请第 1 个女孩。
- 第 3 个男孩未邀请任何人。
- 第 4 个男孩邀请第 2 个女孩。</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>grid.length == m</code></li>
	<li><code>grid[i].length == n</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j]</code> 是 <code>0</code> 或 <code>1</code> 之一。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：匈牙利算法

本题属于二分图最大匹配问题，适合用匈牙利算法来求解。

匈牙利算法的核心思想是，不断地从未匹配的点出发，寻找增广路径，直到没有增广路径为止，就得到了最大匹配。

时间复杂度 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumInvitations(self, grid: List[List[int]]) -> int:
        def find(i):
            for j, v in enumerate(grid[i]):
                if v and j not in vis:
                    vis.add(j)
                    if match[j] == -1 or find(match[j]):
                        match[j] = i
                        return True
            return False

        m, n = len(grid), len(grid[0])
        match = [-1] * n
        ans = 0
        for i in range(m):
            vis = set()
            ans += find(i)
        return ans
```

#### Java

```java
class Solution {
    private int[][] grid;
    private boolean[] vis;
    private int[] match;
    private int n;

    public int maximumInvitations(int[][] grid) {
        int m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        vis = new boolean[n];
        match = new int[n];
        Arrays.fill(match, -1);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            Arrays.fill(vis, false);
            if (find(i)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean find(int i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && !vis[j]) {
                vis[j] = true;
                if (match[j] == -1 || find(match[j])) {
                    match[j] = i;
                    return true;
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
    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool vis[210];
        int match[210];
        memset(match, -1, sizeof match);
        int ans = 0;
        function<bool(int)> find = [&](int i) -> bool {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !vis[j]) {
                    vis[j] = true;
                    if (match[j] == -1 || find(match[j])) {
                        match[j] = i;
                        return true;
                    }
                }
            }
            return false;
        };
        for (int i = 0; i < m; ++i) {
            memset(vis, 0, sizeof vis);
            ans += find(i);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumInvitations(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	var vis map[int]bool
	match := make([]int, n)
	for i := range match {
		match[i] = -1
	}
	var find func(i int) bool
	find = func(i int) bool {
		for j, v := range grid[i] {
			if v == 1 && !vis[j] {
				vis[j] = true
				if match[j] == -1 || find(match[j]) {
					match[j] = i
					return true
				}
			}
		}
		return false
	}
	ans := 0
	for i := 0; i < m; i++ {
		vis = map[int]bool{}
		if find(i) {
			ans++
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1821. 寻找今年具有正收入的客户 🔒](https://leetcode.cn/problems/find-customers-with-positive-revenue-this-year){#1821}

{{< tabs "1821" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    customer_id
FROM Customers
WHERE year = '2021' AND revenue > 0;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Customers</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| customer_id  | int  |
| year         | int  |
| revenue      | int  |
+--------------+------+
(customer_id, year) 是该表的主键（具有唯一值的列的组合）。
这个表包含客户 ID 和不同年份的客户收入。
注意，这个收入可能是负数。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案来报告 2021 年具有 <strong>正收入</strong> 的客户。</p>

<p>可以以&nbsp;<strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>Input:</strong>
Customers
+-------------+------+---------+
| customer_id | year | revenue |
+-------------+------+---------+
| 1           | 2018 | 50      |
| 1           | 2021 | 30      |
| 1           | 2020 | 70      |
| 2           | 2021 | -50     |
| 3           | 2018 | 10      |
| 3           | 2016 | 50      |
| 4           | 2021 | 20      |
+-------------+------+---------+

<strong>Output:</strong>
+-------------+
| customer_id |
+-------------+
| 1           |
| 4           |
+-------------+
客户 1 在 2021 年的收入等于 30 。
客户 2 在 2021 年的收入等于 -50 。
客户 3 在 2021 年没有收入。
客户 4 在 2021 年的收入等于 20 。
因此，只有客户 1 和 4 在 2021 年有正收入。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：WHERE 子句

我们可以直接使用 `WHERE` 子句来筛选出 `year` 为 `2021` 且 `revenue` 大于 $0$ 的客户。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    customer_id
FROM Customers
WHERE year = '2021' AND revenue > 0;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1822. 数组元素积的符号](https://leetcode.cn/problems/sign-of-the-product-of-an-array){#1822}

{{< tabs "1822" >}}

{{% tab "python" %}}
```python
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        ans = 1
        for v in nums:
            if v == 0:
                return 0
            if v < 0:
                ans *= -1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int arraySign(int[] nums) {
        int ans = 1;
        for (int v : nums) {
            if (v == 0) {
                return 0;
            }
            if (v < 0) {
                ans *= -1;
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
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int v : nums) {
            if (!v) return 0;
            if (v < 0) ans *= -1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arraySign(nums []int) int {
	ans := 1
	for _, v := range nums {
		if v == 0 {
			return 0
		}
		if v < 0 {
			ans *= -1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn array_sign(nums: Vec<i32>) -> i32 {
        let mut ans = 1;
        for &num in nums.iter() {
            if num == 0 {
                return 0;
            }
            if num < 0 {
                ans *= -1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var arraySign = function (nums) {
    let ans = 1;
    for (const v of nums) {
        if (!v) {
            return 0;
        }
        if (v < 0) {
            ans *= -1;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int arraySign(int* nums, int numsSize) {
    int ans = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            return 0;
        }
        if (nums[i] < 0) {
            ans *= -1;
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

<p>已知函数 <code>signFunc(x)</code> 将会根据 <code>x</code> 的正负返回特定值：</p>

<ul>
	<li>如果 <code>x</code> 是正数，返回 <code>1</code> 。</li>
	<li>如果 <code>x</code> 是负数，返回 <code>-1</code> 。</li>
	<li>如果 <code>x</code> 是等于 <code>0</code> ，返回 <code>0</code> 。</li>
</ul>

<p>给你一个整数数组 <code>nums</code> 。令 <code>product</code> 为数组 <code>nums</code> 中所有元素值的乘积。</p>

<p>返回 <code>signFunc(product)</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-2,-3,-4,3,2,1]
<strong>输出：</strong>1
<strong>解释：</strong>数组中所有值的乘积是 144 ，且 signFunc(144) = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,0,2,-3]
<strong>输出：</strong>0
<strong>解释：</strong>数组中所有值的乘积是 0 ，且 signFunc(0) = 0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,1,-1,1,-1]
<strong>输出：</strong>-1
<strong>解释：</strong>数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>-100 <= nums[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

题目要求返回数组元素乘积的符号，即正数返回 $1$，负数返回 $-1$， 等于 $0$ 则返回 $0$。

我们可以定义一个答案变量 `ans`，初始值为 $1$。

然后遍历数组每个元素 $v$，如果 $v$ 为负数，则将 `ans` 乘上 $-1$，如果 $v$ 为 $0$，则提前返回 $0$。

遍历结束后，返回 `ans` 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        ans = 1
        for v in nums:
            if v == 0:
                return 0
            if v < 0:
                ans *= -1
        return ans
```

#### Java

```java
class Solution {
    public int arraySign(int[] nums) {
        int ans = 1;
        for (int v : nums) {
            if (v == 0) {
                return 0;
            }
            if (v < 0) {
                ans *= -1;
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
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int v : nums) {
            if (!v) return 0;
            if (v < 0) ans *= -1;
        }
        return ans;
    }
};
```

#### Go

```go
func arraySign(nums []int) int {
	ans := 1
	for _, v := range nums {
		if v == 0 {
			return 0
		}
		if v < 0 {
			ans *= -1
		}
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    pub fn array_sign(nums: Vec<i32>) -> i32 {
        let mut ans = 1;
        for &num in nums.iter() {
            if num == 0 {
                return 0;
            }
            if num < 0 {
                ans *= -1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var arraySign = function (nums) {
    let ans = 1;
    for (const v of nums) {
        if (!v) {
            return 0;
        }
        if (v < 0) {
            ans *= -1;
        }
    }
    return ans;
};
```

#### C

```c
int arraySign(int* nums, int numsSize) {
    int ans = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            return 0;
        }
        if (nums[i] < 0) {
            ans *= -1;
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

# [1823. 找出游戏的获胜者](https://leetcode.cn/problems/find-the-winner-of-the-circular-game){#1823}

{{< tabs "1823" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        if n == 1:
            return 1
        ans = (k + self.findTheWinner(n - 1, k)) % n
        return n if ans == 0 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheWinner(n int, k int) int {
	if n == 1 {
		return 1
	}
	ans := (findTheWinner(n-1, k) + k) % n
	if ans == 0 {
		return n
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheWinner(n: number, k: number): number {
    const arr = Array.from({ length: n }, (_, i) => i + 1);
    let i = 0;

    while (arr.length > 1) {
        i = (i + k - 1) % arr.length;
        arr.splice(i, 1);
    }

    return arr[0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let mut ans = (k + Solution::find_the_winner(n - 1, k)) % n;
        return if ans == 0 { n } else { ans };
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function findTheWinner(n, k) {
    const arr = Array.from({ length: n }, (_, i) => i + 1);
    let i = 0;

    while (arr.length > 1) {
        i = (i + k - 1) % arr.length;
        arr.splice(i, 1);
    }

    return arr[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>共有 <code>n</code> 名小伙伴一起做游戏。小伙伴们围成一圈，按 <strong>顺时针顺序</strong> 从 <code>1</code> 到 <code>n</code> 编号。确切地说，从第 <code>i</code> 名小伙伴顺时针移动一位会到达第 <code>(i+1)</code> 名小伙伴的位置，其中 <code>1 &lt;= i &lt; n</code> ，从第 <code>n</code> 名小伙伴顺时针移动一位会回到第 <code>1</code> 名小伙伴的位置。</p>

<p>游戏遵循如下规则：</p>

<ol>
	<li>从第 <code>1</code> 名小伙伴所在位置 <strong>开始</strong> 。</li>
	<li>沿着顺时针方向数 <code>k</code> 名小伙伴，计数时需要 <strong>包含</strong> 起始时的那位小伙伴。逐个绕圈进行计数，一些小伙伴可能会被数过不止一次。</li>
	<li>你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。</li>
	<li>如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的 <strong>顺时针下一位</strong> 小伙伴 <strong>开始</strong>，回到步骤 <code>2</code> 继续执行。</li>
	<li>否则，圈子中最后一名小伙伴赢得游戏。</li>
</ol>

<p>给你参与游戏的小伙伴总数 <code>n</code> ，和一个整数 <code>k</code> ，返回游戏的获胜者。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1823.Find%20the%20Winner%20of%20the%20Circular%20Game/images/ic234-q2-ex11.png" style="width: 500px; height: 345px;" />
<pre>
<strong>输入：</strong>n = 5, k = 2
<strong>输出：</strong>3
<strong>解释：</strong>游戏运行步骤如下：
1) 从小伙伴 1 开始。
2) 顺时针数 2 名小伙伴，也就是小伙伴 1 和 2 。
3) 小伙伴 2 离开圈子。下一次从小伙伴 3 开始。
4) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 4 。
5) 小伙伴 4 离开圈子。下一次从小伙伴 5 开始。
6) 顺时针数 2 名小伙伴，也就是小伙伴 5 和 1 。
7) 小伙伴 1 离开圈子。下一次从小伙伴 3 开始。
8) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 5 。
9) 小伙伴 5 离开圈子。只剩下小伙伴 3 。所以小伙伴 3 是游戏的获胜者。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 6, k = 5
<strong>输出：</strong>1
<strong>解释：</strong>小伙伴离开圈子的顺序：5、4、6、2、3 。小伙伴 1 是游戏的获胜者。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 500</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否使用线性时间复杂度和常数空间复杂度解决此问题？</p>

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
    def findTheWinner(self, n: int, k: int) -> int:
        if n == 1:
            return 1
        ans = (k + self.findTheWinner(n - 1, k)) % n
        return n if ans == 0 else ans
```

#### Java

```java
class Solution {
    public int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
};
```

#### Go

```go
func findTheWinner(n int, k int) int {
	if n == 1 {
		return 1
	}
	ans := (findTheWinner(n-1, k) + k) % n
	if ans == 0 {
		return n
	}
	return ans
}
```

#### TypeScript

```ts
function findTheWinner(n: number, k: number): number {
    if (n === 1) {
        return 1;
    }
    const ans = (k + findTheWinner(n - 1, k)) % n;
    return ans ? ans : n;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let mut ans = (k + Solution::find_the_winner(n - 1, k)) % n;
        return if ans == 0 { n } else { ans };
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function (n, k) {
    if (n === 1) {
        return 1;
    }
    const ans = (k + findTheWinner(n - 1, k)) % n;
    return ans ? ans : n;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：模拟

<!-- tabs:start -->

#### TypeScript

```ts
function findTheWinner(n: number, k: number): number {
    const arr = Array.from({ length: n }, (_, i) => i + 1);
    let i = 0;

    while (arr.length > 1) {
        i = (i + k - 1) % arr.length;
        arr.splice(i, 1);
    }

    return arr[0];
}
```

#### JavaScript

```js
function findTheWinner(n, k) {
    const arr = Array.from({ length: n }, (_, i) => i + 1);
    let i = 0;

    while (arr.length > 1) {
        i = (i + k - 1) % arr.length;
        arr.splice(i, 1);
    }

    return arr[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1824. 最少侧跳次数](https://leetcode.cn/problems/minimum-sideway-jumps){#1824}

{{< tabs "1824" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        f = [1, 0, 1]
        for v in obstacles[1:]:
            for j in range(3):
                if v == j + 1:
                    f[j] = inf
                    break
            x = min(f) + 1
            for j in range(3):
                if v != j + 1:
                    f[j] = min(f[j], x)
        return min(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSideJumps(int[] obstacles) {
        final int inf = 1 << 30;
        int[] f = {1, 0, 1};
        for (int i = 1; i < obstacles.length; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] == j + 1) {
                    f[j] = inf;
                    break;
                }
            }
            int x = Math.min(f[0], Math.min(f[1], f[2])) + 1;
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] != j + 1) {
                    f[j] = Math.min(f[j], x);
                }
            }
        }
        return Math.min(f[0], Math.min(f[1], f[2]));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int inf = 1 << 30;
        int f[3] = {1, 0, 1};
        for (int i = 1; i < obstacles.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] == j + 1) {
                    f[j] = inf;
                    break;
                }
            }
            int x = min({f[0], f[1], f[2]}) + 1;
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] != j + 1) {
                    f[j] = min(f[j], x);
                }
            }
        }
        return min({f[0], f[1], f[2]});
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSideJumps(obstacles []int) int {
	f := [3]int{1, 0, 1}
	const inf = 1 << 30
	for _, v := range obstacles[1:] {
		for j := 0; j < 3; j++ {
			if v == j+1 {
				f[j] = inf
				break
			}
		}
		x := min(f[0], min(f[1], f[2])) + 1
		for j := 0; j < 3; j++ {
			if v != j+1 {
				f[j] = min(f[j], x)
			}
		}
	}
	return min(f[0], min(f[1], f[2]))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSideJumps(obstacles: number[]): number {
    const inf = 1 << 30;
    const f = [1, 0, 1];
    for (let i = 1; i < obstacles.length; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (obstacles[i] == j + 1) {
                f[j] = inf;
                break;
            }
        }
        const x = Math.min(...f) + 1;
        for (let j = 0; j < 3; ++j) {
            if (obstacles[i] != j + 1) {
                f[j] = Math.min(f[j], x);
            }
        }
    }
    return Math.min(...f);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的 <strong>3 跑道道路</strong> ，它总共包含 <code>n + 1</code> 个 <strong>点</strong> ，编号为 <code>0</code> 到 <code>n</code> 。一只青蛙从 <code>0</code> 号点第二条跑道 <strong>出发</strong> ，它想要跳到点 <code>n</code> 处。然而道路上可能有一些障碍。</p>

<p>给你一个长度为 <code>n + 1</code> 的数组 <code>obstacles</code> ，其中 <code>obstacles[i]</code> （<b>取值范围从 0 到 3</b>）表示在点 <code>i</code> 处的 <code>obstacles[i]</code> 跑道上有一个障碍。如果 <code>obstacles[i] == 0</code> ，那么点 <code>i</code> 处没有障碍。任何一个点的三条跑道中 <strong>最多有一个</strong> 障碍。</p>

<ul>
	<li>比方说，如果 <code>obstacles[2] == 1</code> ，那么说明在点 2 处跑道 1 有障碍。</li>
</ul>

<p>这只青蛙从点 <code>i</code> 跳到点 <code>i + 1</code> 且跑道不变的前提是点 <code>i + 1</code> 的同一跑道上没有障碍。为了躲避障碍，这只青蛙也可以在 <strong>同一个</strong> 点处 <strong>侧跳</strong> 到 <strong>另外一条</strong> 跑道（这两条跑道可以不相邻），但前提是跳过去的跑道该点处没有障碍。</p>

<ul>
	<li>比方说，这只青蛙可以从点 3 处的跑道 3 跳到点 3 处的跑道 1 。</li>
</ul>

<p>这只青蛙从点 0 处跑道 <code>2</code> 出发，并想到达点 <code>n</code> 处的 <strong>任一跑道</strong> ，请你返回 <strong>最少侧跳次数</strong> 。</p>

<p><strong>注意</strong>：点 <code>0</code> 处和点 <code>n</code> 处的任一跑道都不会有障碍。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1824.Minimum%20Sideway%20Jumps/images/ic234-q3-ex1.png" style="width: 500px; height: 244px;" />
<pre>
<b>输入：</b>obstacles = [0,1,2,3,0]
<b>输出：</b>2 
<b>解释：</b>最优方案如上图箭头所示。总共有 2 次侧跳（红色箭头）。
注意，这只青蛙只有当侧跳时才可以跳过障碍（如上图点 2 处所示）。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1824.Minimum%20Sideway%20Jumps/images/ic234-q3-ex2.png" style="width: 500px; height: 196px;" />
<pre>
<b>输入：</b>obstacles = [0,1,1,3,3,0]
<b>输出：</b>0
<b>解释：</b>跑道 2 没有任何障碍，所以不需要任何侧跳。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1824.Minimum%20Sideway%20Jumps/images/ic234-q3-ex3.png" style="width: 500px; height: 196px;" />
<pre>
<b>输入：</b>obstacles = [0,2,1,0,3,0]
<b>输出：</b>2
<b>解释：</b>最优方案如上图所示。总共有 2 次侧跳。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obstacles.length == n + 1</code></li>
	<li><code>1 <= n <= 5 * 10<sup>5</sup></code></li>
	<li><code>0 <= obstacles[i] <= 3</code></li>
	<li><code>obstacles[0] == obstacles[n] == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示青蛙到达第 $i$ 个点，且处于第 $j$ 条跑道（下标从 $0$ 开始）的最小侧跳次数。

注意到青蛙起始位置处于第 $2$ 条跑道（题目这里下标从 $1$ 开始），因此 $f[0][1]$ 的值为 $0$，而 $f[0][0]$ 和 $f[0][2]$ 的值均为 $1$。答案为 $min(f[n][0], f[n][1], f[n][2])$

对于 $i$ 从 $1$ 到 $n$ 的每个位置，我们可以枚举青蛙当前所处的跑道 $j$，如果 $obstacles[i] = j + 1$，说明第 $j$ 条跑道上有障碍，此时 $f[i][j]$ 的值为正无穷；否则，青蛙可以选择不跳跃，此时 $f[i][j]$ 的值为 $f[i - 1][j]$，或者青蛙可以从其它跑道侧跳过来，此时 $f[i][j] = min(f[i][j], min(f[i][0], f[i][1], f[i][2]) + 1)$。

在代码实现上，我们可以将第一维空间优化掉，只用一个长度为 $3$ 的数组 $f$ 来维护。

时间复杂度 $O(n)$，其中 $n$ 为数组 $obstacles$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        f = [1, 0, 1]
        for v in obstacles[1:]:
            for j in range(3):
                if v == j + 1:
                    f[j] = inf
                    break
            x = min(f) + 1
            for j in range(3):
                if v != j + 1:
                    f[j] = min(f[j], x)
        return min(f)
```

#### Java

```java
class Solution {
    public int minSideJumps(int[] obstacles) {
        final int inf = 1 << 30;
        int[] f = {1, 0, 1};
        for (int i = 1; i < obstacles.length; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] == j + 1) {
                    f[j] = inf;
                    break;
                }
            }
            int x = Math.min(f[0], Math.min(f[1], f[2])) + 1;
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] != j + 1) {
                    f[j] = Math.min(f[j], x);
                }
            }
        }
        return Math.min(f[0], Math.min(f[1], f[2]));
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int inf = 1 << 30;
        int f[3] = {1, 0, 1};
        for (int i = 1; i < obstacles.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] == j + 1) {
                    f[j] = inf;
                    break;
                }
            }
            int x = min({f[0], f[1], f[2]}) + 1;
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] != j + 1) {
                    f[j] = min(f[j], x);
                }
            }
        }
        return min({f[0], f[1], f[2]});
    }
};
```

#### Go

```go
func minSideJumps(obstacles []int) int {
	f := [3]int{1, 0, 1}
	const inf = 1 << 30
	for _, v := range obstacles[1:] {
		for j := 0; j < 3; j++ {
			if v == j+1 {
				f[j] = inf
				break
			}
		}
		x := min(f[0], min(f[1], f[2])) + 1
		for j := 0; j < 3; j++ {
			if v != j+1 {
				f[j] = min(f[j], x)
			}
		}
	}
	return min(f[0], min(f[1], f[2]))
}
```

#### TypeScript

```ts
function minSideJumps(obstacles: number[]): number {
    const inf = 1 << 30;
    const f = [1, 0, 1];
    for (let i = 1; i < obstacles.length; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (obstacles[i] == j + 1) {
                f[j] = inf;
                break;
            }
        }
        const x = Math.min(...f) + 1;
        for (let j = 0; j < 3; ++j) {
            if (obstacles[i] != j + 1) {
                f[j] = Math.min(f[j], x);
            }
        }
    }
    return Math.min(...f);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1825. 求出 MK 平均值](https://leetcode.cn/problems/finding-mk-average){#1825}

{{< tabs "1825" >}}

{{% tab "python" %}}
```python
class MKAverage:
    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.sl = SortedList()
        self.q = deque()
        self.s = 0

    def addElement(self, num: int) -> None:
        self.q.append(num)
        if len(self.q) == self.m:
            self.sl = SortedList(self.q)
            self.s = sum(self.sl[self.k : -self.k])
        elif len(self.q) > self.m:
            i = self.sl.bisect_left(num)
            if i < self.k:
                self.s += self.sl[self.k - 1]
            elif self.k <= i <= self.m - self.k:
                self.s += num
            else:
                self.s += self.sl[self.m - self.k]
            self.sl.add(num)

            x = self.q.popleft()
            i = self.sl.bisect_left(x)
            if i < self.k:
                self.s -= self.sl[self.k]
            elif self.k <= i <= self.m - self.k:
                self.s -= x
            else:
                self.s -= self.sl[self.m - self.k]
            self.sl.remove(x)

    def calculateMKAverage(self) -> int:
        return -1 if len(self.sl) < self.m else self.s // (self.m - self.k * 2)


# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MKAverage {

    private int m, k;
    private long s;
    private int size1, size3;
    private Deque<Integer> q = new ArrayDeque<>();
    private TreeMap<Integer, Integer> lo = new TreeMap<>();
    private TreeMap<Integer, Integer> mid = new TreeMap<>();
    private TreeMap<Integer, Integer> hi = new TreeMap<>();

    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
    }

    public void addElement(int num) {
        if (lo.isEmpty() || num <= lo.lastKey()) {
            lo.merge(num, 1, Integer::sum);
            ++size1;
        } else if (hi.isEmpty() || num >= hi.firstKey()) {
            hi.merge(num, 1, Integer::sum);
            ++size3;
        } else {
            mid.merge(num, 1, Integer::sum);
            s += num;
        }
        q.offer(num);
        if (q.size() > m) {
            int x = q.poll();
            if (lo.containsKey(x)) {
                if (lo.merge(x, -1, Integer::sum) == 0) {
                    lo.remove(x);
                }
                --size1;
            } else if (hi.containsKey(x)) {
                if (hi.merge(x, -1, Integer::sum) == 0) {
                    hi.remove(x);
                }
                --size3;
            } else {
                if (mid.merge(x, -1, Integer::sum) == 0) {
                    mid.remove(x);
                }
                s -= x;
            }
        }
        for (; size1 > k; --size1) {
            int x = lo.lastKey();
            if (lo.merge(x, -1, Integer::sum) == 0) {
                lo.remove(x);
            }
            mid.merge(x, 1, Integer::sum);
            s += x;
        }
        for (; size3 > k; --size3) {
            int x = hi.firstKey();
            if (hi.merge(x, -1, Integer::sum) == 0) {
                hi.remove(x);
            }
            mid.merge(x, 1, Integer::sum);
            s += x;
        }
        for (; size1 < k && !mid.isEmpty(); ++size1) {
            int x = mid.firstKey();
            if (mid.merge(x, -1, Integer::sum) == 0) {
                mid.remove(x);
            }
            s -= x;
            lo.merge(x, 1, Integer::sum);
        }
        for (; size3 < k && !mid.isEmpty(); ++size3) {
            int x = mid.lastKey();
            if (mid.merge(x, -1, Integer::sum) == 0) {
                mid.remove(x);
            }
            s -= x;
            hi.merge(x, 1, Integer::sum);
        }
    }

    public int calculateMKAverage() {
        return q.size() < m ? -1 : (int) (s / (q.size() - k * 2));
    }
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage obj = new MKAverage(m, k);
 * obj.addElement(num);
 * int param_2 = obj.calculateMKAverage();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        if (lo.empty() || num <= *lo.rbegin()) {
            lo.insert(num);
        } else if (hi.empty() || num >= *hi.begin()) {
            hi.insert(num);
        } else {
            mid.insert(num);
            s += num;
        }

        q.push(num);
        if (q.size() > m) {
            int x = q.front();
            q.pop();
            if (lo.find(x) != lo.end()) {
                lo.erase(lo.find(x));
            } else if (hi.find(x) != hi.end()) {
                hi.erase(hi.find(x));
            } else {
                mid.erase(mid.find(x));
                s -= x;
            }
        }
        while (lo.size() > k) {
            int x = *lo.rbegin();
            lo.erase(prev(lo.end()));
            mid.insert(x);
            s += x;
        }
        while (hi.size() > k) {
            int x = *hi.begin();
            hi.erase(hi.begin());
            mid.insert(x);
            s += x;
        }
        while (lo.size() < k && mid.size()) {
            int x = *mid.begin();
            mid.erase(mid.begin());
            s -= x;
            lo.insert(x);
        }
        while (hi.size() < k && mid.size()) {
            int x = *mid.rbegin();
            mid.erase(prev(mid.end()));
            s -= x;
            hi.insert(x);
        }
    }

    int calculateMKAverage() {
        return q.size() < m ? -1 : s / (q.size() - k * 2);
    }

private:
    int m, k;
    long long s = 0;
    queue<int> q;
    multiset<int> lo, mid, hi;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MKAverage struct {
	lo, mid, hi  *redblacktree.Tree
	q            []int
	m, k, s      int
	size1, size3 int
}

func Constructor(m int, k int) MKAverage {
	lo := redblacktree.NewWithIntComparator()
	mid := redblacktree.NewWithIntComparator()
	hi := redblacktree.NewWithIntComparator()
	return MKAverage{lo, mid, hi, []int{}, m, k, 0, 0, 0}
}

func (this *MKAverage) AddElement(num int) {
	merge := func(rbt *redblacktree.Tree, key, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}

	if this.lo.Empty() || num <= this.lo.Right().Key.(int) {
		merge(this.lo, num, 1)
		this.size1++
	} else if this.hi.Empty() || num >= this.hi.Left().Key.(int) {
		merge(this.hi, num, 1)
		this.size3++
	} else {
		merge(this.mid, num, 1)
		this.s += num
	}
	this.q = append(this.q, num)
	if len(this.q) > this.m {
		x := this.q[0]
		this.q = this.q[1:]
		if _, ok := this.lo.Get(x); ok {
			merge(this.lo, x, -1)
			this.size1--
		} else if _, ok := this.hi.Get(x); ok {
			merge(this.hi, x, -1)
			this.size3--
		} else {
			merge(this.mid, x, -1)
			this.s -= x
		}
	}
	for ; this.size1 > this.k; this.size1-- {
		x := this.lo.Right().Key.(int)
		merge(this.lo, x, -1)
		merge(this.mid, x, 1)
		this.s += x
	}
	for ; this.size3 > this.k; this.size3-- {
		x := this.hi.Left().Key.(int)
		merge(this.hi, x, -1)
		merge(this.mid, x, 1)
		this.s += x
	}
	for ; this.size1 < this.k && !this.mid.Empty(); this.size1++ {
		x := this.mid.Left().Key.(int)
		merge(this.mid, x, -1)
		this.s -= x
		merge(this.lo, x, 1)
	}
	for ; this.size3 < this.k && !this.mid.Empty(); this.size3++ {
		x := this.mid.Right().Key.(int)
		merge(this.mid, x, -1)
		this.s -= x
		merge(this.hi, x, 1)
	}
}

func (this *MKAverage) CalculateMKAverage() int {
	if len(this.q) < this.m {
		return -1
	}
	return this.s / (this.m - 2*this.k)
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * obj := Constructor(m, k);
 * obj.AddElement(num);
 * param_2 := obj.CalculateMKAverage();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数&nbsp;<code>m</code>&nbsp;和&nbsp;<code>k</code>&nbsp;，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 <b>MK 平均值</b>&nbsp;。</p>

<p><strong>MK 平均值</strong>&nbsp;按照如下步骤计算：</p>

<ol>
	<li>如果数据流中的整数少于 <code>m</code>&nbsp;个，<strong>MK 平均值</strong>&nbsp;为 <code>-1</code>&nbsp;，否则将数据流中最后 <code>m</code>&nbsp;个元素拷贝到一个独立的容器中。</li>
	<li>从这个容器中删除最小的 <code>k</code>&nbsp;个数和最大的 <code>k</code>&nbsp;个数。</li>
	<li>计算剩余元素的平均值，并 <strong>向下取整到最近的整数</strong>&nbsp;。</li>
</ol>

<p>请你实现&nbsp;<code>MKAverage</code>&nbsp;类：</p>

<ul>
	<li><code>MKAverage(int m, int k)</code>&nbsp;用一个空的数据流和两个整数 <code>m</code>&nbsp;和 <code>k</code>&nbsp;初始化&nbsp;<strong>MKAverage</strong>&nbsp;对象。</li>
	<li><code>void addElement(int num)</code>&nbsp;往数据流中插入一个新的元素&nbsp;<code>num</code>&nbsp;。</li>
	<li><code>int calculateMKAverage()</code>&nbsp;对当前的数据流计算并返回 <strong>MK 平均数</strong>&nbsp;，结果需 <strong>向下取整到最近的整数</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
<strong>输出：</strong>
[null, null, null, -1, null, 3, null, null, null, 5]

<strong>解释：</strong>
MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // 当前元素为 [3]
obj.addElement(1);        // 当前元素为 [3,1]
obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
obj.addElement(10);       // 当前元素为 [3,1,10]
obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
                          // 删除最小以及最大的 1 个元素后，容器为 [3]
                          // [3] 的平均值等于 3/1 = 3 ，故返回 3
obj.addElement(5);        // 当前元素为 [3,1,10,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
                          // 删除最小以及最大的 1 个元素后，容器为 [5]
                          // [5] 的平均值等于 5/1 = 5 ，故返回 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k*2 &lt; m</code></li>
	<li><code>1 &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li><code>addElement</code> 与&nbsp;<code>calculateMKAverage</code>&nbsp;总操作次数不超过 <code>10<sup>5</sup></code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合 + 队列

我们可以维护以下数据结构或变量：

-   一个长度为 $m$ 的队列 $q$，其中队首元素为最早加入的元素，队尾元素为最近加入的元素；
-   三个有序集合，分别为 $lo$, $mid$, $hi$，其中 $lo$ 和 $hi$ 分别存储最小的 $k$ 个元素和最大的 $k$ 个元素，而 $mid$ 存储剩余的元素；
-   一个变量 $s$，维护 $mid$ 中所有元素的和；
-   部分编程语言（如 Java, Go）额外维护两个变量 $size1$ 和 $size3$，分别表示 $lo$ 和 $hi$ 中元素的个数。

调用 $addElement(num)$ 函数时，顺序执行以下操作：

1. 如果 $lo$ 为空，或者 $num \leq max(lo)$，则将 $num$ 加入 $lo$ 中；否则如果 $hi$ 为空，或者 $num \geq min(hi)$，则将 $num$ 加入 $hi$ 中；否则将 $num$ 加入 $mid$ 中，同时将 $num$ 的值加到 $s$ 中。
1. 接下来将 $num$ 加入队列 $q$ 中，如果此时队列 $q$ 的长度大于 $m$，则将队首元素 $x$ 从队列 $q$ 中移除，接下来从 $lo$, $mid$ 或 $hi$ 中选择其中一个包含 $x$ 的集合，将 $x$ 从该集合中移除，如果该集合为 $mid$，则将 $s$ 减去 $x$ 的值。
1. 如果 $lo$ 的长度大于 $k$，则循环将 $lo$ 中的最大值 $max(lo)$ 从 $lo$ 中移除，将 $max(lo)$ 加入 $mid$ 中，同时将 $s$ 加上 $max(lo)$ 的值。
1. 如果 $hi$ 的长度大于 $k$，则循环将 $hi$ 中的最小值 $min(hi)$ 从 $hi$ 中移除，将 $min(hi)$ 加入 $mid$ 中，同时将 $s$ 加上 $min(hi)$ 的值。
1. 如果 $lo$ 的长度小于 $k$，并且 $mid$ 不为空，则循环将 $mid$ 中的最小值 $min(mid)$ 从 $mid$ 中移除，将 $min(mid)$ 加入 $lo$ 中，同时将 $s$ 减去 $min(mid)$ 的值。
1. 如果 $hi$ 的长度小于 $k$，并且 $mid$ 不为空，则循环将 $mid$ 中的最大值 $max(mid)$ 从 $mid$ 中移除，将 $max(mid)$ 加入 $hi$ 中，同时将 $s$ 减去 $max(mid)$ 的值。

调用 $calculateMKAverage()$ 函数时，如果 $q$ 的长度小于 $m$，则返回 $-1$，否则返回 $\frac{s}{m - 2k}$。

时间复杂度方面，每次调用 $addElement(num)$ 函数的时间复杂度为 $O(\log m)$，每次调用 $calculateMKAverage()$ 函数的时间复杂度为 $O(1)$。空间复杂度为 $O(m)$。

<!-- tabs:start -->

#### Python3

```python
class MKAverage:
    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.s = 0
        self.q = deque()
        self.lo = SortedList()
        self.mid = SortedList()
        self.hi = SortedList()

    def addElement(self, num: int) -> None:
        if not self.lo or num <= self.lo[-1]:
            self.lo.add(num)
        elif not self.hi or num >= self.hi[0]:
            self.hi.add(num)
        else:
            self.mid.add(num)
            self.s += num
        self.q.append(num)
        if len(self.q) > self.m:
            x = self.q.popleft()
            if x in self.lo:
                self.lo.remove(x)
            elif x in self.hi:
                self.hi.remove(x)
            else:
                self.mid.remove(x)
                self.s -= x
        while len(self.lo) > self.k:
            x = self.lo.pop()
            self.mid.add(x)
            self.s += x
        while len(self.hi) > self.k:
            x = self.hi.pop(0)
            self.mid.add(x)
            self.s += x
        while len(self.lo) < self.k and self.mid:
            x = self.mid.pop(0)
            self.lo.add(x)
            self.s -= x
        while len(self.hi) < self.k and self.mid:
            x = self.mid.pop()
            self.hi.add(x)
            self.s -= x

    def calculateMKAverage(self) -> int:
        return -1 if len(self.q) < self.m else self.s // (self.m - 2 * self.k)


# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()
```

#### Java

```java
class MKAverage {

    private int m, k;
    private long s;
    private int size1, size3;
    private Deque<Integer> q = new ArrayDeque<>();
    private TreeMap<Integer, Integer> lo = new TreeMap<>();
    private TreeMap<Integer, Integer> mid = new TreeMap<>();
    private TreeMap<Integer, Integer> hi = new TreeMap<>();

    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
    }

    public void addElement(int num) {
        if (lo.isEmpty() || num <= lo.lastKey()) {
            lo.merge(num, 1, Integer::sum);
            ++size1;
        } else if (hi.isEmpty() || num >= hi.firstKey()) {
            hi.merge(num, 1, Integer::sum);
            ++size3;
        } else {
            mid.merge(num, 1, Integer::sum);
            s += num;
        }
        q.offer(num);
        if (q.size() > m) {
            int x = q.poll();
            if (lo.containsKey(x)) {
                if (lo.merge(x, -1, Integer::sum) == 0) {
                    lo.remove(x);
                }
                --size1;
            } else if (hi.containsKey(x)) {
                if (hi.merge(x, -1, Integer::sum) == 0) {
                    hi.remove(x);
                }
                --size3;
            } else {
                if (mid.merge(x, -1, Integer::sum) == 0) {
                    mid.remove(x);
                }
                s -= x;
            }
        }
        for (; size1 > k; --size1) {
            int x = lo.lastKey();
            if (lo.merge(x, -1, Integer::sum) == 0) {
                lo.remove(x);
            }
            mid.merge(x, 1, Integer::sum);
            s += x;
        }
        for (; size3 > k; --size3) {
            int x = hi.firstKey();
            if (hi.merge(x, -1, Integer::sum) == 0) {
                hi.remove(x);
            }
            mid.merge(x, 1, Integer::sum);
            s += x;
        }
        for (; size1 < k && !mid.isEmpty(); ++size1) {
            int x = mid.firstKey();
            if (mid.merge(x, -1, Integer::sum) == 0) {
                mid.remove(x);
            }
            s -= x;
            lo.merge(x, 1, Integer::sum);
        }
        for (; size3 < k && !mid.isEmpty(); ++size3) {
            int x = mid.lastKey();
            if (mid.merge(x, -1, Integer::sum) == 0) {
                mid.remove(x);
            }
            s -= x;
            hi.merge(x, 1, Integer::sum);
        }
    }

    public int calculateMKAverage() {
        return q.size() < m ? -1 : (int) (s / (q.size() - k * 2));
    }
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage obj = new MKAverage(m, k);
 * obj.addElement(num);
 * int param_2 = obj.calculateMKAverage();
 */
```

#### C++

```cpp
class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        if (lo.empty() || num <= *lo.rbegin()) {
            lo.insert(num);
        } else if (hi.empty() || num >= *hi.begin()) {
            hi.insert(num);
        } else {
            mid.insert(num);
            s += num;
        }

        q.push(num);
        if (q.size() > m) {
            int x = q.front();
            q.pop();
            if (lo.find(x) != lo.end()) {
                lo.erase(lo.find(x));
            } else if (hi.find(x) != hi.end()) {
                hi.erase(hi.find(x));
            } else {
                mid.erase(mid.find(x));
                s -= x;
            }
        }
        while (lo.size() > k) {
            int x = *lo.rbegin();
            lo.erase(prev(lo.end()));
            mid.insert(x);
            s += x;
        }
        while (hi.size() > k) {
            int x = *hi.begin();
            hi.erase(hi.begin());
            mid.insert(x);
            s += x;
        }
        while (lo.size() < k && mid.size()) {
            int x = *mid.begin();
            mid.erase(mid.begin());
            s -= x;
            lo.insert(x);
        }
        while (hi.size() < k && mid.size()) {
            int x = *mid.rbegin();
            mid.erase(prev(mid.end()));
            s -= x;
            hi.insert(x);
        }
    }

    int calculateMKAverage() {
        return q.size() < m ? -1 : s / (q.size() - k * 2);
    }

private:
    int m, k;
    long long s = 0;
    queue<int> q;
    multiset<int> lo, mid, hi;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
```

#### Go

```go
type MKAverage struct {
	lo, mid, hi  *redblacktree.Tree
	q            []int
	m, k, s      int
	size1, size3 int
}

func Constructor(m int, k int) MKAverage {
	lo := redblacktree.NewWithIntComparator()
	mid := redblacktree.NewWithIntComparator()
	hi := redblacktree.NewWithIntComparator()
	return MKAverage{lo, mid, hi, []int{}, m, k, 0, 0, 0}
}

func (this *MKAverage) AddElement(num int) {
	merge := func(rbt *redblacktree.Tree, key, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}

	if this.lo.Empty() || num <= this.lo.Right().Key.(int) {
		merge(this.lo, num, 1)
		this.size1++
	} else if this.hi.Empty() || num >= this.hi.Left().Key.(int) {
		merge(this.hi, num, 1)
		this.size3++
	} else {
		merge(this.mid, num, 1)
		this.s += num
	}
	this.q = append(this.q, num)
	if len(this.q) > this.m {
		x := this.q[0]
		this.q = this.q[1:]
		if _, ok := this.lo.Get(x); ok {
			merge(this.lo, x, -1)
			this.size1--
		} else if _, ok := this.hi.Get(x); ok {
			merge(this.hi, x, -1)
			this.size3--
		} else {
			merge(this.mid, x, -1)
			this.s -= x
		}
	}
	for ; this.size1 > this.k; this.size1-- {
		x := this.lo.Right().Key.(int)
		merge(this.lo, x, -1)
		merge(this.mid, x, 1)
		this.s += x
	}
	for ; this.size3 > this.k; this.size3-- {
		x := this.hi.Left().Key.(int)
		merge(this.hi, x, -1)
		merge(this.mid, x, 1)
		this.s += x
	}
	for ; this.size1 < this.k && !this.mid.Empty(); this.size1++ {
		x := this.mid.Left().Key.(int)
		merge(this.mid, x, -1)
		this.s -= x
		merge(this.lo, x, 1)
	}
	for ; this.size3 < this.k && !this.mid.Empty(); this.size3++ {
		x := this.mid.Right().Key.(int)
		merge(this.mid, x, -1)
		this.s -= x
		merge(this.hi, x, 1)
	}
}

func (this *MKAverage) CalculateMKAverage() int {
	if len(this.q) < this.m {
		return -1
	}
	return this.s / (this.m - 2*this.k)
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * obj := Constructor(m, k);
 * obj.AddElement(num);
 * param_2 := obj.CalculateMKAverage();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class MKAverage:
    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.sl = SortedList()
        self.q = deque()
        self.s = 0

    def addElement(self, num: int) -> None:
        self.q.append(num)
        if len(self.q) == self.m:
            self.sl = SortedList(self.q)
            self.s = sum(self.sl[self.k : -self.k])
        elif len(self.q) > self.m:
            i = self.sl.bisect_left(num)
            if i < self.k:
                self.s += self.sl[self.k - 1]
            elif self.k <= i <= self.m - self.k:
                self.s += num
            else:
                self.s += self.sl[self.m - self.k]
            self.sl.add(num)

            x = self.q.popleft()
            i = self.sl.bisect_left(x)
            if i < self.k:
                self.s -= self.sl[self.k]
            elif self.k <= i <= self.m - self.k:
                self.s -= x
            else:
                self.s -= self.sl[self.m - self.k]
            self.sl.remove(x)

    def calculateMKAverage(self) -> int:
        return -1 if len(self.sl) < self.m else self.s // (self.m - self.k * 2)


# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1826. 有缺陷的传感器 🔒](https://leetcode.cn/problems/faulty-sensor){#1826}

{{< tabs "1826" >}}

{{% tab "python" %}}
```python
class Solution:
    def badSensor(self, sensor1: List[int], sensor2: List[int]) -> int:
        i, n = 0, len(sensor1)
        while i < n - 1:
            if sensor1[i] != sensor2[i]:
                break
            i += 1
        while i < n - 1:
            if sensor1[i + 1] != sensor2[i]:
                return 1
            if sensor1[i] != sensor2[i + 1]:
                return 2
            i += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int badSensor(int[] sensor1, int[] sensor2) {
        int i = 0;
        int n = sensor1.length;
        for (; i < n - 1 && sensor1[i] == sensor2[i]; ++i) {
        }
        for (; i < n - 1; ++i) {
            if (sensor1[i + 1] != sensor2[i]) {
                return 1;
            }
            if (sensor1[i] != sensor2[i + 1]) {
                return 2;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int i = 0;
        int n = sensor1.size();
        for (; i < n - 1 && sensor1[i] == sensor2[i]; ++i) {}
        for (; i < n - 1; ++i) {
            if (sensor1[i + 1] != sensor2[i]) return 1;
            if (sensor1[i] != sensor2[i + 1]) return 2;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func badSensor(sensor1 []int, sensor2 []int) int {
	i, n := 0, len(sensor1)
	for ; i < n-1 && sensor1[i] == sensor2[i]; i++ {
	}
	for ; i < n-1; i++ {
		if sensor1[i+1] != sensor2[i] {
			return 1
		}
		if sensor1[i] != sensor2[i+1] {
			return 2
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function badSensor(sensor1: number[], sensor2: number[]): number {
    let i = 0;
    const n = sensor1.length;
    while (i < n - 1) {
        if (sensor1[i] !== sensor2[i]) {
            break;
        }
        ++i;
    }
    while (i < n - 1) {
        if (sensor1[i + 1] !== sensor2[i]) {
            return 1;
        }
        if (sensor1[i] !== sensor2[i + 1]) {
            return 2;
        }
        ++i;
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实验室里正在进行一项实验。为了确保数据的准确性，同时使用 <strong>两个</strong> 传感器来采集数据。您将获得2个数组 <code>sensor1</code> and <code>sensor2</code>，其中 <code>sensor1[i]</code>&nbsp;和&nbsp;<code>sensor2[i]</code>&nbsp;分别是两个传感器对<span style="">第 <code>i</code> 个</span>数据点采集到的数据。</p>

<p>但是，这种类型的传感器有可能存在缺陷，它会导致 <strong>某一个</strong> 数据点采集的数据（掉落值）被丢弃。</p>

<p>数据被丢弃后，所有在其右侧的数据点采集的数据，都会被向左移动一个位置，最后一个数据点采集的数据会被一些随机值替换。可以保证此随机值不等于掉落值。</p>

<ul>
	<li>举个例子, 如果正确的数据是&nbsp;<code>[1,2,<em><strong>3</strong></em>,4,5]</code>&nbsp;，&nbsp;此时 <code>3</code> 被丢弃了, 传感器会返回&nbsp;<code>[1,2,4,5,<em><strong>7</strong></em>]</code> (最后的位置可以是任何值, 不仅仅是&nbsp;<code>7</code>).</li>
</ul>

<p>可以确定的是，<strong>最多有一个</strong> 传感器有缺陷。请返回这个有缺陷的传感器的编号 （<code>1</code> 或 <code>2</code>）。如果任一传感器 <strong>没有缺陷</strong> ，或者 <strong>无法</strong> 确定有缺陷的传感器，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sensor1 = [2,3,4,5], sensor2 = [2,1,3,4]
<strong>输出：</strong>1
<strong>解释：</strong>传感器 2 返回了所有正确的数据.
传感器2对第二个数据点采集的数据，被传感器1丢弃了，传感器1返回的最后一个数据被替换为 5 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sensor1 = [2,2,2,2,2], sensor2 = [2,2,2,2,5]
<strong>输出：</strong>-1
<strong>解释：</strong>无法判定哪个传感器是有缺陷的。
假设任一传感器丢弃的数据是最后一位，那么，另一个传感器就能给出与之对应的输出。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sensor1 = [2,3,2,2,3,2], sensor2 = [2,3,2,3,2,7]
<strong>输出：</strong>2
<strong>解释：</strong>传感器 1 返回了所有正确的数据.
传感器 1 对第四个数据点的采集数据，被传感器2丢失了, 传感器 2 返回的最后一个数据被替换为 7 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>sensor1.length == sensor2.length</code></li>
	<li><code>1 &lt;= sensor1.length &lt;= 100</code></li>
	<li><code>1 &lt;= sensor1[i], sensor2[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

遍历两个数组，找到第一个不相等的位置 $i$。如果 $i \lt n - 1$，循环比较 $sensor1[i + 1]$ 和 $sensor2[i]$，如果不相等，说明传感器 $1$ 有缺陷，返回 $1$；否则比较 $sensor1[i]$ 和 $sensor2[i + 1]$，如果不相等，说明传感器 $2$ 有缺陷，返回 $2$。

遍历结束，说明无法确定有缺陷的传感器 🔒，返回 $-1$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def badSensor(self, sensor1: List[int], sensor2: List[int]) -> int:
        i, n = 0, len(sensor1)
        while i < n - 1:
            if sensor1[i] != sensor2[i]:
                break
            i += 1
        while i < n - 1:
            if sensor1[i + 1] != sensor2[i]:
                return 1
            if sensor1[i] != sensor2[i + 1]:
                return 2
            i += 1
        return -1
```

#### Java

```java
class Solution {
    public int badSensor(int[] sensor1, int[] sensor2) {
        int i = 0;
        int n = sensor1.length;
        for (; i < n - 1 && sensor1[i] == sensor2[i]; ++i) {
        }
        for (; i < n - 1; ++i) {
            if (sensor1[i + 1] != sensor2[i]) {
                return 1;
            }
            if (sensor1[i] != sensor2[i + 1]) {
                return 2;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int i = 0;
        int n = sensor1.size();
        for (; i < n - 1 && sensor1[i] == sensor2[i]; ++i) {}
        for (; i < n - 1; ++i) {
            if (sensor1[i + 1] != sensor2[i]) return 1;
            if (sensor1[i] != sensor2[i + 1]) return 2;
        }
        return -1;
    }
};
```

#### Go

```go
func badSensor(sensor1 []int, sensor2 []int) int {
	i, n := 0, len(sensor1)
	for ; i < n-1 && sensor1[i] == sensor2[i]; i++ {
	}
	for ; i < n-1; i++ {
		if sensor1[i+1] != sensor2[i] {
			return 1
		}
		if sensor1[i] != sensor2[i+1] {
			return 2
		}
	}
	return -1
}
```

#### TypeScript

```ts
function badSensor(sensor1: number[], sensor2: number[]): number {
    let i = 0;
    const n = sensor1.length;
    while (i < n - 1) {
        if (sensor1[i] !== sensor2[i]) {
            break;
        }
        ++i;
    }
    while (i < n - 1) {
        if (sensor1[i + 1] !== sensor2[i]) {
            return 1;
        }
        if (sensor1[i] !== sensor2[i + 1]) {
            return 2;
        }
        ++i;
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1827. 最少操作使数组递增](https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing){#1827}

{{< tabs "1827" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = mx = 0
        for v in nums:
            ans += max(0, mx + 1 - v)
            mx = max(mx + 1, v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, mx = 0;
        for (int v : nums) {
            ans += Math.max(0, mx + 1 - v);
            mx = Math.max(mx + 1, v);
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
    int minOperations(vector<int>& nums) {
        int ans = 0, mx = 0;
        for (int& v : nums) {
            ans += max(0, mx + 1 - v);
            mx = max(mx + 1, v);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) (ans int) {
	mx := 0
	for _, v := range nums {
		ans += max(0, mx+1-v)
		mx = max(mx+1, v)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    let ans = 0;
    let max = 0;
    for (const v of nums) {
        ans += Math.max(0, max + 1 - v);
        max = Math.max(max + 1, v);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut max = 0;
        for &v in nums.iter() {
            ans += (0).max(max + 1 - v);
            max = v.max(max + 1);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinOperations(int[] nums) {
        int ans = 0, mx = 0;
        foreach (int v in nums) {
            ans += Math.Max(0, mx + 1 - v);
            mx = Math.Max(mx + 1, v);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minOperations(int* nums, int numsSize) {
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < numsSize; i++) {
        ans += max(0, mx + 1 - nums[i]);
        mx = max(mx + 1, nums[i]);
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

<p>给你一个整数数组 <code>nums</code> （<strong>下标从 0 开始</strong>）。每一次操作中，你可以选择数组中一个元素，并将它增加 <code>1</code> 。</p>

<ul>
	<li>比方说，如果 <code>nums = [1,2,3]</code> ，你可以选择增加 <code>nums[1]</code> 得到 <code>nums = [1,<b>3</b>,3]</code> 。</li>
</ul>

<p>请你返回使 <code>nums</code> <strong>严格递增</strong> 的 <strong>最少</strong> 操作次数。</p>

<p>我们称数组 <code>nums</code> 是 <strong>严格递增的</strong> ，当它满足对于所有的 <code>0 &lt;= i &lt; nums.length - 1</code> 都有 <code>nums[i] &lt; nums[i+1]</code> 。一个长度为 <code>1</code> 的数组是严格递增的一种特殊情况。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,1]
<b>输出：</b>3
<b>解释：</b>你可以进行如下操作：
1) 增加 nums[2] ，数组变为 [1,1,<strong>2</strong>] 。
2) 增加 nums[1] ，数组变为 [1,<strong>2</strong>,2] 。
3) 增加 nums[2] ，数组变为 [1,2,<strong>3</strong>] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,5,2,4,1]
<b>输出：</b>14
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [8]
<b>输出：</b>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们用变量 $mx$ 记录当前严格递增数组的最大值，初始时 $mx = 0$。

从左到右遍历数组 `nums`，对于当前遍历到的元素 $v$，如果 $v \lt mx + 1$，那么我们需要将其增加到 $mx + 1$，这样才能保证数组严格递增。因此，我们此次需要进行的操作次数为 $max(0, mx + 1 - v)$，累加到答案中，然后更新 $mx=max(mx + 1, v)$。继续遍历下一个元素，直到遍历完整个数组。

时间复杂度 $O(n)$，其中 $n$ 为数组 `nums` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = mx = 0
        for v in nums:
            ans += max(0, mx + 1 - v)
            mx = max(mx + 1, v)
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, mx = 0;
        for (int v : nums) {
            ans += Math.max(0, mx + 1 - v);
            mx = Math.max(mx + 1, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, mx = 0;
        for (int& v : nums) {
            ans += max(0, mx + 1 - v);
            mx = max(mx + 1, v);
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) (ans int) {
	mx := 0
	for _, v := range nums {
		ans += max(0, mx+1-v)
		mx = max(mx+1, v)
	}
	return
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    let ans = 0;
    let max = 0;
    for (const v of nums) {
        ans += Math.max(0, max + 1 - v);
        max = Math.max(max + 1, v);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut max = 0;
        for &v in nums.iter() {
            ans += (0).max(max + 1 - v);
            max = v.max(max + 1);
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MinOperations(int[] nums) {
        int ans = 0, mx = 0;
        foreach (int v in nums) {
            ans += Math.Max(0, mx + 1 - v);
            mx = Math.Max(mx + 1, v);
        }
        return ans;
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minOperations(int* nums, int numsSize) {
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < numsSize; i++) {
        ans += max(0, mx + 1 - nums[i]);
        mx = max(mx + 1, nums[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1828. 统计一个圆中点的数目](https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle){#1828}

{{< tabs "1828" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPoints(
        self, points: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        ans = []
        for x, y, r in queries:
            cnt = 0
            for i, j in points:
                dx, dy = i - x, j - y
                cnt += dx * dx + dy * dy <= r * r
            ans.append(cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int x = queries[k][0], y = queries[k][1], r = queries[k][2];
            for (var p : points) {
                int i = p[0], j = p[1];
                int dx = i - x, dy = j - y;
                if (dx * dx + dy * dy <= r * r) {
                    ++ans[k];
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
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1], r = q[2];
            int cnt = 0;
            for (auto& p : points) {
                int i = p[0], j = p[1];
                int dx = i - x, dy = j - y;
                cnt += dx * dx + dy * dy <= r * r;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPoints(points [][]int, queries [][]int) (ans []int) {
	for _, q := range queries {
		x, y, r := q[0], q[1], q[2]
		cnt := 0
		for _, p := range points {
			i, j := p[0], p[1]
			dx, dy := i-x, j-y
			if dx*dx+dy*dy <= r*r {
				cnt++
			}
		}
		ans = append(ans, cnt)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPoints(points: number[][], queries: number[][]): number[] {
    return queries.map(([cx, cy, r]) => {
        let res = 0;
        for (const [px, py] of points) {
            if (Math.sqrt((cx - px) ** 2 + (cy - py) ** 2) <= r) {
                res++;
            }
        }
        return res;
    });
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_points(points: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        queries
            .iter()
            .map(|v| {
                let cx = v[0];
                let cy = v[1];
                let r = v[2].pow(2);
                let mut count = 0;
                for p in points.iter() {
                    if (p[0] - cx).pow(2) + (p[1] - cy).pow(2) <= r {
                        count += 1;
                    }
                }
                count
            })
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
    int* ans = malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int cx = queries[i][0];
        int cy = queries[i][1];
        int r = queries[i][2];
        int count = 0;
        for (int j = 0; j < pointsSize; j++) {
            if (sqrt(pow(points[j][0] - cx, 2) + pow(points[j][1] - cy, 2)) <= r) {
                count++;
            }
        }
        ans[i] = count;
    }
    *returnSize = queriesSize;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> ，表示第 <code>i</code> 个点在二维平面上的坐标。多个点可能会有 <strong>相同</strong> 的坐标。</p>

<p>同时给你一个数组 <code>queries</code> ，其中 <code>queries[j] = [x<sub>j</sub>, y<sub>j</sub>, r<sub>j</sub>]</code> ，表示一个圆心在 <code>(x<sub>j</sub>, y<sub>j</sub>)</code> 且半径为 <code>r<sub>j</sub></code><sub> </sub>的圆。</p>

<p>对于每一个查询 <code>queries[j]</code> ，计算在第 <code>j</code> 个圆 <strong>内</strong> 点的数目。如果一个点在圆的 <strong>边界上</strong> ，我们同样认为它在圆 <strong>内</strong> 。</p>

<p>请你返回一个数组<em> </em><code>answer</code> ，其中<em> </em><code>answer[j]</code>是第 <code>j</code> 个查询的答案。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1828.Queries%20on%20Number%20of%20Points%20Inside%20a%20Circle/images/chrome_2021-03-25_22-34-16.png" style="width: 500px; height: 418px;">
<pre><b>输入：</b>points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
<b>输出：</b>[3,2,2]
<b>解释：</b>所有的点和圆如上图所示。
queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1828.Queries%20on%20Number%20of%20Points%20Inside%20a%20Circle/images/chrome_2021-03-25_22-42-07.png" style="width: 500px; height: 390px;">
<pre><b>输入：</b>points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
<b>输出：</b>[2,3,2,4]
<b>解释：</b>所有的点和圆如上图所示。
queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆，queries[3] 是紫色的圆。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 500</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>​​​​​​i</sub>, y<sub>​​​​​​i</sub> &lt;= 500</code></li>
	<li><code>1 &lt;= queries.length &lt;= 500</code></li>
	<li><code>queries[j].length == 3</code></li>
	<li><code>0 &lt;= x<sub>j</sub>, y<sub>j</sub> &lt;= 500</code></li>
	<li><code>1 &lt;= r<sub>j</sub> &lt;= 500</code></li>
	<li>所有的坐标都是整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

枚举所有的圆点 $(x, y, r)$，对于每个圆点，计算在圆内的点的个数，即可得到答案。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为数组 `queries` 的长度和 `points` 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPoints(
        self, points: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        ans = []
        for x, y, r in queries:
            cnt = 0
            for i, j in points:
                dx, dy = i - x, j - y
                cnt += dx * dx + dy * dy <= r * r
            ans.append(cnt)
        return ans
```

#### Java

```java
class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int x = queries[k][0], y = queries[k][1], r = queries[k][2];
            for (var p : points) {
                int i = p[0], j = p[1];
                int dx = i - x, dy = j - y;
                if (dx * dx + dy * dy <= r * r) {
                    ++ans[k];
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
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1], r = q[2];
            int cnt = 0;
            for (auto& p : points) {
                int i = p[0], j = p[1];
                int dx = i - x, dy = j - y;
                cnt += dx * dx + dy * dy <= r * r;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func countPoints(points [][]int, queries [][]int) (ans []int) {
	for _, q := range queries {
		x, y, r := q[0], q[1], q[2]
		cnt := 0
		for _, p := range points {
			i, j := p[0], p[1]
			dx, dy := i-x, j-y
			if dx*dx+dy*dy <= r*r {
				cnt++
			}
		}
		ans = append(ans, cnt)
	}
	return
}
```

#### TypeScript

```ts
function countPoints(points: number[][], queries: number[][]): number[] {
    return queries.map(([cx, cy, r]) => {
        let res = 0;
        for (const [px, py] of points) {
            if (Math.sqrt((cx - px) ** 2 + (cy - py) ** 2) <= r) {
                res++;
            }
        }
        return res;
    });
}
```

#### Rust

```rust
impl Solution {
    pub fn count_points(points: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        queries
            .iter()
            .map(|v| {
                let cx = v[0];
                let cy = v[1];
                let r = v[2].pow(2);
                let mut count = 0;
                for p in points.iter() {
                    if (p[0] - cx).pow(2) + (p[1] - cy).pow(2) <= r {
                        count += 1;
                    }
                }
                count
            })
            .collect()
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
    int* ans = malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int cx = queries[i][0];
        int cy = queries[i][1];
        int r = queries[i][2];
        int count = 0;
        for (int j = 0; j < pointsSize; j++) {
            if (sqrt(pow(points[j][0] - cx, 2) + pow(points[j][1] - cy, 2)) <= r) {
                count++;
            }
        }
        ans[i] = count;
    }
    *returnSize = queriesSize;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1829. 每个查询的最大异或值](https://leetcode.cn/problems/maximum-xor-for-each-query){#1829}

{{< tabs "1829" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        ans = []
        xs = reduce(xor, nums)
        mask = (1 << maximumBit) - 1
        for x in nums[::-1]:
            k = xs ^ mask
            ans.append(k)
            xs ^= x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int xs = 0;
        for (int x : nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
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
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xs = 0;
        for (int& x : nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaximumXor(nums []int, maximumBit int) (ans []int) {
	xs := 0
	for _, x := range nums {
		xs ^= x
	}
	mask := (1 << maximumBit) - 1
	for i := range nums {
		x := nums[len(nums)-i-1]
		k := xs ^ mask
		ans = append(ans, k)
		xs ^= x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaximumXor(nums: number[], maximumBit: number): number[] {
    let xs = 0;
    for (const x of nums) {
        xs ^= x;
    }
    const mask = (1 << maximumBit) - 1;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const x = nums[n - i - 1];
        let k = xs ^ mask;
        ans[i] = k;
        xs ^= x;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function (nums, maximumBit) {
    let xs = 0;
    for (const x of nums) {
        xs ^= x;
    }
    const mask = (1 << maximumBit) - 1;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const x = nums[n - i - 1];
        let k = xs ^ mask;
        ans[i] = k;
        xs ^= x;
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int xs = 0;
        foreach (int x in nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
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

<p>给你一个 <strong>有序</strong> 数组 <code>nums</code> ，它由 <code>n</code> 个非负整数组成，同时给你一个整数 <code>maximumBit</code> 。你需要执行以下查询 <code>n</code> 次：</p>

<ol>
	<li>找到一个非负整数 <code>k < 2<sup>maximumBit</sup></code> ，使得 <code>nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k</code> 的结果 <strong>最大化</strong> 。<code>k</code> 是第 <code>i</code> 个查询的答案。</li>
	<li>从当前数组 <code>nums</code> 删除 <strong>最后</strong> 一个元素。</li>
</ol>

<p>请你返回一个数组 <code>answer</code> ，其中<em> </em><code>answer[i]</code>是第 <code>i</code> 个查询的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [0,1,1,3], maximumBit = 2
<b>输出：</b>[0,3,2,3]
<b>解释：</b>查询的答案如下：
第一个查询：nums = [0,1,1,3]，k = 0，因为 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3 。
第二个查询：nums = [0,1,1]，k = 3，因为 0 XOR 1 XOR 1 XOR 3 = 3 。
第三个查询：nums = [0,1]，k = 2，因为 0 XOR 1 XOR 2 = 3 。
第四个查询：nums = [0]，k = 3，因为 0 XOR 3 = 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,4,7], maximumBit = 3
<b>输出：</b>[5,2,6,5]
<b>解释：</b>查询的答案如下：
第一个查询：nums = [2,3,4,7]，k = 5，因为 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7。
第二个查询：nums = [2,3,4]，k = 2，因为 2 XOR 3 XOR 4 XOR 2 = 7 。
第三个查询：nums = [2,3]，k = 6，因为 2 XOR 3 XOR 6 = 7 。
第四个查询：nums = [2]，k = 5，因为 2 XOR 5 = 7 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [0,1,2,2,5,7], maximumBit = 3
<b>输出：</b>[4,3,6,4,6,7]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= maximumBit <= 20</code></li>
	<li><code>0 <= nums[i] < 2<sup>maximumBit</sup></code></li>
	<li><code>nums</code>​​​ 中的数字已经按 <strong>升序</strong> 排好序。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算 + 枚举

我们先预处理出数组 `nums` 的异或和 $xs$，即 $xs=nums[0] \oplus nums[1] \oplus \cdots \oplus nums[n-1]$。

接下来，我们从后往前枚举数组 `nums` 中的每个元素 $x$，当前的异或和为 $xs$，我们需要找到一个数 $k$，使得 $xs \oplus k$ 的值尽可能大，并且 $k \lt 2^{maximumBit}$。

也即是说，我们从 $xs$ 的第 $maximumBit - 1$ 位开始，往低位枚举，如果 $xs$ 的某一位为 $0$，那么我们就将 $k$ 的对应位设置为 $1$，否则我们就将 $k$ 的对应位设置为 $0$。这样，最终得到的 $k$ 就是每一次查询的答案。然后，我们将 $xs$ 更新为 $xs \oplus x$，继续枚举下一个元素。

时间复杂度 $O(n \times m)$，其中 $n$ 和 $m$ 分别是数组 `nums` 和 `maximumBit` 的值。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        ans = []
        xs = reduce(xor, nums)
        for x in nums[::-1]:
            k = 0
            for i in range(maximumBit - 1, -1, -1):
                if (xs >> i & 1) == 0:
                    k |= 1 << i
            ans.append(k)
            xs ^= x
        return ans
```

#### Java

```java
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n = nums.length;
        int xs = 0;
        for (int x : nums) {
            xs ^= x;
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = 0;
            for (int j = maximumBit - 1; j >= 0; --j) {
                if (((xs >> j) & 1) == 0) {
                    k |= 1 << j;
                }
            }
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xs = 0;
        for (int& x : nums) {
            xs ^= x;
        }
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = 0;
            for (int j = maximumBit - 1; ~j; --j) {
                if ((xs >> j & 1) == 0) {
                    k |= 1 << j;
                }
            }
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
};
```

#### Go

```go
func getMaximumXor(nums []int, maximumBit int) (ans []int) {
	xs := 0
	for _, x := range nums {
		xs ^= x
	}
	for i := range nums {
		x := nums[len(nums)-i-1]
		k := 0
		for j := maximumBit - 1; j >= 0; j-- {
			if xs>>j&1 == 0 {
				k |= 1 << j
			}
		}
		ans = append(ans, k)
		xs ^= x
	}
	return
}
```

#### TypeScript

```ts
function getMaximumXor(nums: number[], maximumBit: number): number[] {
    let xs = 0;
    for (const x of nums) {
        xs ^= x;
    }
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const x = nums[n - i - 1];
        let k = 0;
        for (let j = maximumBit - 1; j >= 0; --j) {
            if (((xs >> j) & 1) == 0) {
                k |= 1 << j;
            }
        }
        ans[i] = k;
        xs ^= x;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function (nums, maximumBit) {
    let xs = 0;
    for (const x of nums) {
        xs ^= x;
    }
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const x = nums[n - i - 1];
        let k = 0;
        for (let j = maximumBit - 1; j >= 0; --j) {
            if (((xs >> j) & 1) == 0) {
                k |= 1 << j;
            }
        }
        ans[i] = k;
        xs ^= x;
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int xs = 0;
        foreach (int x in nums) {
            xs ^= x;
        }
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = 0;
            for (int j = maximumBit - 1; j >= 0; --j) {
                if ((xs >> j & 1) == 0) {
                    k |= 1 << j;
                }
            }
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

与方法一类似，我们先预处理出数组 `nums` 的异或和 $xs$，即 $xs=nums[0] \oplus nums[1] \oplus \cdots \oplus nums[n-1]$。

接下来，我们算出 $2^{maximumBit} - 1$，即 $2^{maximumBit}$ 减去 $1$，记为 $mask$。然后，我们从后往前枚举数组 `nums` 中的每个元素 $x$，当前的异或和为 $xs$，那么 $k=xs \oplus mask$ 就是每一次查询的答案。然后，我们将 $xs$ 更新为 $xs \oplus x$，继续枚举下一个元素。

时间复杂度 $O(n)$，其中 $n$ 是数组 `nums` 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        ans = []
        xs = reduce(xor, nums)
        mask = (1 << maximumBit) - 1
        for x in nums[::-1]:
            k = xs ^ mask
            ans.append(k)
            xs ^= x
        return ans
```

#### Java

```java
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int xs = 0;
        for (int x : nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xs = 0;
        for (int& x : nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
};
```

#### Go

```go
func getMaximumXor(nums []int, maximumBit int) (ans []int) {
	xs := 0
	for _, x := range nums {
		xs ^= x
	}
	mask := (1 << maximumBit) - 1
	for i := range nums {
		x := nums[len(nums)-i-1]
		k := xs ^ mask
		ans = append(ans, k)
		xs ^= x
	}
	return
}
```

#### TypeScript

```ts
function getMaximumXor(nums: number[], maximumBit: number): number[] {
    let xs = 0;
    for (const x of nums) {
        xs ^= x;
    }
    const mask = (1 << maximumBit) - 1;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const x = nums[n - i - 1];
        let k = xs ^ mask;
        ans[i] = k;
        xs ^= x;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function (nums, maximumBit) {
    let xs = 0;
    for (const x of nums) {
        xs ^= x;
    }
    const mask = (1 << maximumBit) - 1;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const x = nums[n - i - 1];
        let k = xs ^ mask;
        ans[i] = k;
        xs ^= x;
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int xs = 0;
        foreach (int x in nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
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
