---
title: "2500_删除每行中的最大值"
date: 2025-10-08T18:39:23+08:00
weight: 1
tags: [二分查找, 二叉树, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 树, 模拟, 矩阵, 脑筋急转弯, 计数, 设计]
---

{{< markmap >}}
### [2500_删除每行中的最大值](#2500)
#### [数组](#2500)
#### [矩阵](#2500)
#### [排序](#2500)
#### [模拟](#2500)
#### [堆（优先队列）](#2500)
### [2501_数组中最长的方波](#2501)
#### [数组](#2501)
#### [哈希表](#2501)
#### [二分查找](#2501)
#### [动态规划](#2501)
#### [排序](#2501)
### [2502_设计内存分配器](#2502)
#### [设计](#2502)
#### [数组](#2502)
#### [哈希表](#2502)
#### [模拟](#2502)
### [2503_矩阵查询可获得的最大分数](#2503)
#### [广度优先搜索](#2503)
#### [并查集](#2503)
#### [数组](#2503)
#### [双指针](#2503)
#### [矩阵](#2503)
#### [排序](#2503)
#### [堆（优先队列）](#2503)
### [2504_把名字和职业联系起来 🔒](#2504)
#### [数据库](#2504)
### [2505_所有子序列和的按位或 🔒](#2505)
#### [位运算](#2505)
#### [脑筋急转弯](#2505)
#### [数组](#2505)
#### [数学](#2505)
#### [前缀和](#2505)
### [2506_统计相似字符串对的数目](#2506)
#### [位运算](#2506)
#### [数组](#2506)
#### [哈希表](#2506)
#### [字符串](#2506)
#### [计数](#2506)
### [2507_使用质因数之和替换后可以取到的最小值](#2507)
#### [数学](#2507)
#### [数论](#2507)
#### [模拟](#2507)
### [2508_添加边使所有节点度数都为偶数](#2508)
#### [图](#2508)
#### [哈希表](#2508)
### [2509_查询树中环的长度](#2509)
#### [树](#2509)
#### [数组](#2509)
#### [二叉树](#2509)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2500_删除每行中的最大值
___
#### 数组
___
#### 矩阵
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 2501_数组中最长的方波
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 2502_设计内存分配器
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 2503_矩阵查询可获得的最大分数
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 双指针
___
#### 矩阵
___
#### 排序
___
#### 堆（优先队列）
---
### 2504_把名字和职业联系起来 🔒
___
#### 数据库
---
### 2505_所有子序列和的按位或 🔒
___
#### 位运算
___
#### 脑筋急转弯
___
#### 数组
___
#### 数学
___
#### 前缀和
---
### 2506_统计相似字符串对的数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2507_使用质因数之和替换后可以取到的最小值
___
#### 数学
___
#### 数论
___
#### 模拟
---
### 2508_添加边使所有节点度数都为偶数
___
#### 图
___
#### 哈希表
---
### 2509_查询树中环的长度
___
#### 树
___
#### 数组
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 数论 | 树 |
| 模拟 | 矩阵 | 脑筋急转弯 |
| 计数 | 设计 |  |

# [2500. 删除每行中的最大值](https://leetcode.cn/problems/delete-greatest-value-in-each-row){#2500}

{{< tabs "2500" >}}

{{% tab "python" %}}
```python
class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        for row in grid:
            row.sort()
        return sum(max(col) for col in zip(*grid))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int deleteGreatestValue(int[][] grid) {
        for (var row : grid) {
            Arrays.sort(row);
        }
        int ans = 0;
        for (int j = 0; j < grid[0].length; ++j) {
            int t = 0;
            for (int i = 0; i < grid.length; ++i) {
                t = Math.max(t, grid[i][j]);
            }
            ans += t;
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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid) {
            ranges::sort(row);
        }
        int ans = 0;
        for (int j = 0; j < grid[0].size(); ++j) {
            int t = 0;
            for (int i = 0; i < grid.size(); ++i) {
                t = max(t, grid[i][j]);
            }
            ans += t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func deleteGreatestValue(grid [][]int) (ans int) {
	for _, row := range grid {
		sort.Ints(row)
	}
	for j := range grid[0] {
		t := 0
		for i := range grid {
			if t < grid[i][j] {
				t = grid[i][j]
			}
		}
		ans += t
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function deleteGreatestValue(grid: number[][]): number {
    for (const row of grid) {
        row.sort((a, b) => a - b);
    }

    let ans = 0;
    for (let j = 0; j < grid[0].length; ++j) {
        let t = 0;
        for (let i = 0; i < grid.length; ++i) {
            t = Math.max(t, grid[i][j]);
        }
        ans += t;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn delete_greatest_value(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        for i in 0..grid.len() {
            grid[i].sort();
        }

        let mut ans = 0;
        for j in 0..grid[0].len() {
            let mut mx = 0;

            for i in 0..grid.len() {
                if grid[i][j] > mx {
                    mx = grid[i][j];
                }
            }

            ans += mx;
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

<p>给你一个 <code>m x n</code> 大小的矩阵 <code>grid</code> ，由若干正整数组成。</p>

<p>执行下述操作，直到 <code>grid</code> 变为空矩阵：</p>

<ul>
	<li>从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。</li>
	<li>将删除元素中的最大值与答案相加。</li>
</ul>

<p><strong>注意</strong> 每执行一次操作，矩阵中列的数据就会减 1 。</p>

<p>返回执行上述操作后的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2500.Delete%20Greatest%20Value%20in%20Each%20Row/images/q1ex1.jpg" style="width: 600px; height: 135px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,2,4],[3,3,1]]
<strong>输出：</strong>8
<strong>解释：</strong>上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3 ，我们可以删除任一）。在答案上加 4 。
- 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
- 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。
最终，答案 = 4 + 3 + 1 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2500.Delete%20Greatest%20Value%20in%20Each%20Row/images/q1ex2.jpg" style="width: 83px; height: 83px;" /></p>

<pre>
<strong>输入：</strong>grid = [[10]]
<strong>输出：</strong>10
<strong>解释：</strong>上图展示在每一步中需要移除的值。
- 在第一步操作中，从第一行删除 10 。在答案上加 10 。
最终，答案 = 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

由于每一次操作都是从每一行中删除最大值，然后取最大值加到答案中，因此我们可以先对每一行进行排序。

接下来遍历每一列，取每一列的最大值，然后将其加到答案中即可。

时间复杂度 $O(m \times n \times \log n)$，空间复杂度 $O(\log n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        for row in grid:
            row.sort()
        return sum(max(col) for col in zip(*grid))
```

#### Java

```java
class Solution {
    public int deleteGreatestValue(int[][] grid) {
        for (var row : grid) {
            Arrays.sort(row);
        }
        int ans = 0;
        for (int j = 0; j < grid[0].length; ++j) {
            int t = 0;
            for (int i = 0; i < grid.length; ++i) {
                t = Math.max(t, grid[i][j]);
            }
            ans += t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid) {
            ranges::sort(row);
        }
        int ans = 0;
        for (int j = 0; j < grid[0].size(); ++j) {
            int t = 0;
            for (int i = 0; i < grid.size(); ++i) {
                t = max(t, grid[i][j]);
            }
            ans += t;
        }
        return ans;
    }
};
```

#### Go

```go
func deleteGreatestValue(grid [][]int) (ans int) {
	for _, row := range grid {
		sort.Ints(row)
	}
	for j := range grid[0] {
		t := 0
		for i := range grid {
			if t < grid[i][j] {
				t = grid[i][j]
			}
		}
		ans += t
	}
	return
}
```

#### TypeScript

```ts
function deleteGreatestValue(grid: number[][]): number {
    for (const row of grid) {
        row.sort((a, b) => a - b);
    }

    let ans = 0;
    for (let j = 0; j < grid[0].length; ++j) {
        let t = 0;
        for (let i = 0; i < grid.length; ++i) {
            t = Math.max(t, grid[i][j]);
        }
        ans += t;
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn delete_greatest_value(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        for i in 0..grid.len() {
            grid[i].sort();
        }

        let mut ans = 0;
        for j in 0..grid[0].len() {
            let mut mx = 0;

            for i in 0..grid.len() {
                if grid[i][j] > mx {
                    mx = grid[i][j];
                }
            }

            ans += mx;
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

# [2501. 数组中最长的方波](https://leetcode.cn/problems/longest-square-streak-in-an-array){#2501}

{{< tabs "2501" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        @cache
        def dfs(x: int) -> int:
            if x not in s:
                return 0
            return 1 + dfs(x * x)

        s = set(nums)
        ans = max(dfs(x) for x in s)
        return -1 if ans < 2 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private Set<Long> s = new HashSet<>();

    public int longestSquareStreak(int[] nums) {
        for (long x : nums) {
            s.add(x);
        }
        int ans = 0;
        for (long x : s) {
            ans = Math.max(ans, dfs(x));
        }
        return ans < 2 ? -1 : ans;
    }

    private int dfs(long x) {
        if (!s.contains(x)) {
            return 0;
        }
        if (f.containsKey(x)) {
            return f.get(x);
        }
        int ans = 1 + dfs(x * x);
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
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> s(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<long long, int> f;
        auto dfs = [&](this auto&& dfs, long long x) -> int {
            if (!s.contains(x)) {
                return 0;
            }
            if (f.contains(x)) {
                return f[x];
            }
            f[x] = 1 + dfs(x * x);
            return f[x];
        };
        for (long long x : s) {
            ans = max(ans, dfs(x));
        }
        return ans < 2 ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSquareStreak(nums []int) (ans int) {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	f := map[int]int{}
	var dfs func(int) int
	dfs = func(x int) int {
		if !s[x] {
			return 0
		}
		if v, ok := f[x]; ok {
			return v
		}
		f[x] = 1 + dfs(x*x)
		return f[x]
	}
	for x := range s {
		if t := dfs(x); ans < t {
			ans = t
		}
	}
	if ans < 2 {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSquareStreak(nums: number[]): number {
    const s = new Set(nums);
    const f = new Map<number, number>();
    const dfs = (x: number): number => {
        if (f.has(x)) {
            return f.get(x)!;
        }
        if (!s.has(x)) {
            return 0;
        }
        f.set(x, 1 + dfs(x ** 2));
        return f.get(x)!;
    };

    for (const x of s) {
        dfs(x);
    }
    const ans = Math.max(...f.values());
    return ans > 1 ? ans : -1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function (nums) {
    const s = new Set(nums);
    const f = new Map();
    const dfs = x => {
        if (f.has(x)) {
            return f.get(x);
        }
        if (!s.has(x)) {
            return 0;
        }
        f.set(x, 1 + dfs(x ** 2));
        return f.get(x);
    };

    for (const x of s) {
        dfs(x);
    }
    const ans = Math.max(...f.values());
    return ans > 1 ? ans : -1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 。如果 <code>nums</code> 的子序列满足下述条件，则认为该子序列是一个 <strong>方波</strong> ：</p>

<ul>
	<li>子序列的长度至少为 <code>2</code> ，并且</li>
	<li>将子序列从小到大排序 <strong>之后</strong> ，除第一个元素外，每个元素都是前一个元素的 <strong>平方</strong> 。</li>
</ul>

<p>返回<em> </em><code>nums</code><em> </em>中 <strong>最长方波</strong> 的长度，如果不存在 <strong>方波</strong><em> </em>则返回<em> </em><code>-1</code> 。</p>

<p><strong>子序列</strong> 也是一个数组，可以由另一个数组删除一些或不删除元素且不改变剩余元素的顺序得到。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre><strong>输入：</strong>nums = [4,3,6,16,8,2]
<strong>输出：</strong>3
<strong>解释：</strong>选出子序列 [4,16,2] 。排序后，得到 [2,4,16] 。
- 4 = 2 * 2.
- 16 = 4 * 4.
因此，[4,16,2] 是一个方波.
可以证明长度为 4 的子序列都不是方波。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,5,6,7]
<strong>输出：</strong>-1
<strong>解释：</strong>nums 不存在方波，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们先用哈希表记录数组中的所有元素，然后枚举数组中的每个元素作为子序列的第一个元素，将该元素不断平方，并判断平方后的结果是否在哈希表中，如果在，则将平方后的结果作为下一个元素，继续判断，直到平方后的结果不在哈希表中，此时判断子序列的长度是否大于 $1$，如果是，则更新答案。

时间复杂度 $O(n \times \log \log M)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $M$ 为数组 $\textit{nums}$ 中的元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        s = set(nums)
        ans = -1
        for x in nums:
            t = 0
            while x in s:
                x *= x
                t += 1
            if t > 1:
                ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public int longestSquareStreak(int[] nums) {
        Set<Long> s = new HashSet<>();
        for (long x : nums) {
            s.add(x);
        }
        int ans = -1;
        for (long x : s) {
            int t = 0;
            for (; s.contains(x); x *= x) {
                ++t;
            }
            if (t > 1) {
                ans = Math.max(ans, t);
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
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> s(nums.begin(), nums.end());
        int ans = -1;
        for (long long x : nums) {
            int t = 0;
            for (; s.contains(x); x *= x) {
                ++t;
            }
            if (t > 1) {
                ans = max(ans, t);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestSquareStreak(nums []int) int {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	ans := -1
	for x := range s {
		t := 0
		for s[x] {
			x *= x
			t++
		}
		if t > 1 {
			ans = max(ans, t)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestSquareStreak(nums: number[]): number {
    const s = new Set(nums);
    let ans = -1;

    for (const num of nums) {
        let x = num;
        let t = 0;

        while (s.has(x)) {
            x *= x;
            t += 1;
        }

        if (t > 1) {
            ans = Math.max(ans, t);
        }
    }

    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function (nums) {
    const s = new Set(nums);
    let ans = -1;

    for (const num of nums) {
        let x = num;
        let t = 0;

        while (s.has(x)) {
            x *= x;
            t += 1;
        }

        if (t > 1) {
            ans = Math.max(ans, t);
        }
    }

    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：记忆化搜索

与方法一类似，我们先用哈希表记录数组中的所有元素。然后设计一个函数 $\textit{dfs}(x)$，表示以 $x$ 为第一个元素的方波的长度。那么答案就是 $\max(\textit{dfs}(x))$，其中 $x$ 为数组 $\textit{nums}$ 中的元素。

函数 $\textit{dfs}(x)$ 的计算过程如下：

-   如果 $x$ 不在哈希表中，则返回 $0$。
-   否则，返回 $1 + \textit{dfs}(x^2)$。

过程中我们可以使用记忆化搜索，即使用哈希表记录函数 $\textit{dfs}(x)$ 的值，避免重复计算。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        @cache
        def dfs(x: int) -> int:
            if x not in s:
                return 0
            return 1 + dfs(x * x)

        s = set(nums)
        ans = max(dfs(x) for x in s)
        return -1 if ans < 2 else ans
```

#### Java

```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private Set<Long> s = new HashSet<>();

    public int longestSquareStreak(int[] nums) {
        for (long x : nums) {
            s.add(x);
        }
        int ans = 0;
        for (long x : s) {
            ans = Math.max(ans, dfs(x));
        }
        return ans < 2 ? -1 : ans;
    }

    private int dfs(long x) {
        if (!s.contains(x)) {
            return 0;
        }
        if (f.containsKey(x)) {
            return f.get(x);
        }
        int ans = 1 + dfs(x * x);
        f.put(x, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> s(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<long long, int> f;
        auto dfs = [&](this auto&& dfs, long long x) -> int {
            if (!s.contains(x)) {
                return 0;
            }
            if (f.contains(x)) {
                return f[x];
            }
            f[x] = 1 + dfs(x * x);
            return f[x];
        };
        for (long long x : s) {
            ans = max(ans, dfs(x));
        }
        return ans < 2 ? -1 : ans;
    }
};
```

#### Go

```go
func longestSquareStreak(nums []int) (ans int) {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	f := map[int]int{}
	var dfs func(int) int
	dfs = func(x int) int {
		if !s[x] {
			return 0
		}
		if v, ok := f[x]; ok {
			return v
		}
		f[x] = 1 + dfs(x*x)
		return f[x]
	}
	for x := range s {
		if t := dfs(x); ans < t {
			ans = t
		}
	}
	if ans < 2 {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function longestSquareStreak(nums: number[]): number {
    const s = new Set(nums);
    const f = new Map<number, number>();
    const dfs = (x: number): number => {
        if (f.has(x)) {
            return f.get(x)!;
        }
        if (!s.has(x)) {
            return 0;
        }
        f.set(x, 1 + dfs(x ** 2));
        return f.get(x)!;
    };

    for (const x of s) {
        dfs(x);
    }
    const ans = Math.max(...f.values());
    return ans > 1 ? ans : -1;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function (nums) {
    const s = new Set(nums);
    const f = new Map();
    const dfs = x => {
        if (f.has(x)) {
            return f.get(x);
        }
        if (!s.has(x)) {
            return 0;
        }
        f.set(x, 1 + dfs(x ** 2));
        return f.get(x);
    };

    for (const x of s) {
        dfs(x);
    }
    const ans = Math.max(...f.values());
    return ans > 1 ? ans : -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2502. 设计内存分配器](https://leetcode.cn/problems/design-memory-allocator){#2502}

{{< tabs "2502" >}}

{{% tab "python" %}}
```python
class Allocator:

    def __init__(self, n: int):
        self.sl = SortedList([(-1, -1), (n, n)])
        self.d = defaultdict(list)

    def allocate(self, size: int, mID: int) -> int:
        for (_, s), (e, _) in pairwise(self.sl):
            s, e = s + 1, e - 1
            if e - s + 1 >= size:
                self.sl.add((s, s + size - 1))
                self.d[mID].append((s, s + size - 1))
                return s
        return -1

    def freeMemory(self, mID: int) -> int:
        ans = 0
        for block in self.d[mID]:
            self.sl.remove(block)
            ans += block[1] - block[0] + 1
        del self.d[mID]
        return ans


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Allocator {
    private TreeMap<Integer, Integer> tm = new TreeMap<>();
    private Map<Integer, List<Integer>> d = new HashMap<>();

    public Allocator(int n) {
        tm.put(-1, -1);
        tm.put(n, n);
    }

    public int allocate(int size, int mID) {
        int s = -1;
        for (var entry : tm.entrySet()) {
            int v = entry.getKey();
            if (s != -1) {
                int e = v - 1;
                if (e - s + 1 >= size) {
                    tm.put(s, s + size - 1);
                    d.computeIfAbsent(mID, k -> new ArrayList<>()).add(s);
                    return s;
                }
            }
            s = entry.getValue() + 1;
        }
        return -1;
    }

    public int freeMemory(int mID) {
        int ans = 0;
        for (int s : d.getOrDefault(mID, List.of())) {
            int e = tm.remove(s);
            ans += e - s + 1;
        }
        d.remove(mID);
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Allocator {
public:
    Allocator(int n) {
        tm[-1] = -1;
        tm[n] = n;
    }

    int allocate(int size, int mID) {
        int s = -1;
        for (auto& [v, c] : tm) {
            if (s != -1) {
                int e = v - 1;
                if (e - s + 1 >= size) {
                    tm[s] = s + size - 1;
                    d[mID].emplace_back(s);
                    return s;
                }
            }
            s = c + 1;
        }
        return -1;
    }

    int freeMemory(int mID) {
        int ans = 0;
        for (int& s : d[mID]) {
            int e = tm[s];
            tm.erase(s);
            ans += e - s + 1;
        }
        d.erase(mID);
        return ans;
    }

private:
    map<int, int> tm;
    unordered_map<int, vector<int>> d;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Allocator struct {
	rbt *redblacktree.Tree
	d   map[int][]int
}

func Constructor(n int) Allocator {
	rbt := redblacktree.NewWithIntComparator()
	rbt.Put(-1, -1)
	rbt.Put(n, n)
	return Allocator{rbt, map[int][]int{}}
}

func (this *Allocator) Allocate(size int, mID int) int {
	s := -1
	it := this.rbt.Iterator()
	for it.Next() {
		v := it.Key().(int)
		if s != -1 {
			e := v - 1
			if e-s+1 >= size {
				this.rbt.Put(s, s+size-1)
				this.d[mID] = append(this.d[mID], s)
				return s
			}
		}
		s = it.Value().(int) + 1
	}
	return -1
}

func (this *Allocator) FreeMemory(mID int) int {
	ans := 0
	for _, s := range this.d[mID] {
		if e, ok := this.rbt.Get(s); ok {
			this.rbt.Remove(s)
			ans += e.(int) - s + 1
		}
	}
	this.d[mID] = []int{}
	return ans
}

/**
 * Your Allocator object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Allocate(size,mID);
 * param_2 := obj.FreeMemory(mID);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Allocator {
    private m: number[];

    constructor(n: number) {
        this.m = Array(n).fill(0);
    }

    allocate(size: number, mID: number): number {
        let cnt = 0;
        for (let i = 0; i < this.m.length; i++) {
            if (this.m[i] > 0) {
                cnt = 0;
            } else if (++cnt === size) {
                for (let j = i - size + 1; j <= i; j++) {
                    this.m[j] = mID;
                }
                return i - size + 1;
            }
        }
        return -1;
    }

    freeMemory(mID: number): number {
        let ans = 0;
        for (let i = 0; i < this.m.length; i++) {
            if (this.m[i] === mID) {
                this.m[i] = 0;
                ans++;
            }
        }
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * var obj = new Allocator(n)
 * var param_1 = obj.allocate(size,mID)
 * var param_2 = obj.freeMemory(mID)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，表示下标从 <strong>0</strong> 开始的内存数组的大小。所有内存单元开始都是空闲的。</p>

<p>请你设计一个具备以下功能的内存分配器：</p>

<ol>
	<li><strong>分配 </strong>一块大小为 <code>size</code> 的连续空闲内存单元并赋 id <code>mID</code> 。</li>
	<li><strong>释放</strong> 给定 id <code>mID</code> 对应的所有内存单元。</li>
</ol>

<p><strong>注意：</strong></p>

<ul>
	<li>多个块可以被分配到同一个 <code>mID</code> 。</li>
	<li>你必须释放 <code>mID</code> 对应的所有内存单元，即便这些内存单元被分配在不同的块中。</li>
</ul>

<p>实现 <code>Allocator</code> 类：</p>

<ul>
	<li><code>Allocator(int n)</code> 使用一个大小为 <code>n</code> 的内存数组初始化 <code>Allocator</code> 对象。</li>
	<li><code>int allocate(int size, int mID)</code> 找出大小为 <code>size</code> 个连续空闲内存单元且位于&nbsp; <strong>最左侧</strong> 的块，分配并赋 id <code>mID</code> 。返回块的第一个下标。如果不存在这样的块，返回 <code>-1</code> 。</li>
	<li><code>int freeMemory(int mID)</code> 释放 id <code>mID</code> 对应的所有内存单元。返回释放的内存单元数目。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate", "allocate", "allocate", "freeMemory", "allocate", "freeMemory"]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
<strong>输出</strong>
[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]

<strong>解释</strong>
Allocator loc = new Allocator(10); // 初始化一个大小为 10 的内存数组，所有内存单元都是空闲的。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 0 。内存数组变为 [<strong>1</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 0 。
loc.allocate(1, 2); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,<strong>2</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 1 。
loc.allocate(1, 3); // 最左侧的块的第一个下标是 2 。内存数组变为 [1,2,<strong>3</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 2 。
loc.freeMemory(2); // 释放 mID 为 2 的所有内存单元。内存数组变为 [1,<u> </u>,<strong>3</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>] 。返回 1 ，因为只有 1 个 mID 为 2 的内存单元。
loc.allocate(3, 4); // 最左侧的块的第一个下标是 3 。内存数组变为 [1,<u> </u>,3,<strong>4</strong>,<strong>4</strong>,<strong>4</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 3 。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,<strong>1</strong>,3,4,4,4,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 1 。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 6 。内存数组变为 [1,1,3,4,4,4,<strong>1</strong>,<u> </u>,<u> </u>,<u> </u>]。返回 6 。
loc.freeMemory(1); // 释放 mID 为 1 的所有内存单元。内存数组变为 [<u> </u>,<u> </u>,3,4,4,4,<u><strong> </strong></u>,<u> </u>,<u> </u>,<u> </u>] 。返回 3 ，因为有 3 个 mID 为 1 的内存单元。
loc.allocate(10, 2); // 无法找出长度为 10 个连续空闲内存单元的空闲块，所有返回 -1 。
loc.freeMemory(7); // 释放 mID 为 7 的所有内存单元。内存数组保持原状，因为不存在 mID 为 7 的内存单元。返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, size, mID &lt;= 1000</code></li>
	<li>最多调用 <code>allocate</code> 和 <code>free</code> 方法 <code>1000</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

题目数据范围不大，可以直接用数组模拟内存空间。

初始化时，将数组中的每个元素置为 $0$，表示空闲。

当调用 `allocate` 方法时，遍历数组，找到连续的 `size` 个空闲内存单元，将其置为 `mID`，并返回第一个下标。

当调用 `free` 方法时，遍历数组，将所有等于 `mID` 的内存单元置为 $0$，表示空闲。

时间复杂度 $O(n \times q)$，空间复杂度 $O(n)$，其中 $n$ 和 $q$ 分别为内存空间的大小和方法调用的次数。

<!-- tabs:start -->

#### Python3

```python
class Allocator:

    def __init__(self, n: int):
        self.m = [0] * n

    def allocate(self, size: int, mID: int) -> int:
        cnt = 0
        for i, v in enumerate(self.m):
            if v:
                cnt = 0
            else:
                cnt += 1
                if cnt == size:
                    self.m[i - size + 1 : i + 1] = [mID] * size
                    return i - size + 1
        return -1

    def freeMemory(self, mID: int) -> int:
        ans = 0
        for i, v in enumerate(self.m):
            if v == mID:
                self.m[i] = 0
                ans += 1
        return ans


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)
```

#### Java

```java
class Allocator {
    private int[] m;

    public Allocator(int n) {
        m = new int[n];
    }

    public int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < m.length; ++i) {
            if (m[i] > 0) {
                cnt = 0;
            } else if (++cnt == size) {
                Arrays.fill(m, i - size + 1, i + 1, mID);
                return i - size + 1;
            }
        }
        return -1;
    }

    public int freeMemory(int mID) {
        int ans = 0;
        for (int i = 0; i < m.length; ++i) {
            if (m[i] == mID) {
                m[i] = 0;
                ++ans;
            }
        }
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */
```

#### C++

```cpp
class Allocator {
public:
    vector<int> m;

    Allocator(int n) {
        m = vector<int>(n, 0);
    }

    int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] > 0) {
                cnt = 0;
            } else if (++cnt == size) {
                fill(m.begin() + i - size + 1, m.begin() + i + 1, mID);
                return i - size + 1;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int ans = 0;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] == mID) {
                m[i] = 0;
                ++ans;
            }
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
```

#### Go

```go
type Allocator struct {
	m []int
}

func Constructor(n int) Allocator {
	return Allocator{m: make([]int, n)}
}

func (this *Allocator) Allocate(size int, mID int) int {
	cnt := 0
	for i := 0; i < len(this.m); i++ {
		if this.m[i] > 0 {
			cnt = 0
		} else if cnt++; cnt == size {
			for j := i - size + 1; j <= i; j++ {
				this.m[j] = mID
			}
			return i - size + 1
		}
	}
	return -1
}

func (this *Allocator) FreeMemory(mID int) int {
	ans := 0
	for i := 0; i < len(this.m); i++ {
		if this.m[i] == mID {
			this.m[i] = 0
			ans++
		}
	}
	return ans
}

/**
 * Your Allocator object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Allocate(size,mID);
 * param_2 := obj.FreeMemory(mID);
 */
```

#### TypeScript

```ts
class Allocator {
    private m: number[];

    constructor(n: number) {
        this.m = Array(n).fill(0);
    }

    allocate(size: number, mID: number): number {
        let cnt = 0;
        for (let i = 0; i < this.m.length; i++) {
            if (this.m[i] > 0) {
                cnt = 0;
            } else if (++cnt === size) {
                for (let j = i - size + 1; j <= i; j++) {
                    this.m[j] = mID;
                }
                return i - size + 1;
            }
        }
        return -1;
    }

    freeMemory(mID: number): number {
        let ans = 0;
        for (let i = 0; i < this.m.length; i++) {
            if (this.m[i] === mID) {
                this.m[i] = 0;
                ans++;
            }
        }
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * var obj = new Allocator(n)
 * var param_1 = obj.allocate(size,mID)
 * var param_2 = obj.freeMemory(mID)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 有序集合

我们可以用有序集合维护所有已分配的内存单元的起始下标和结束下标，其中起始下标为键，结束下标为值；另外用哈希表维护 `mID` 和其对应的内存单元的起始下标。

当调用 `allocate` 方法时，遍历有序集合，找到第一个长度大于等于 `size` 的空闲区间，将其分配给 `mID`，并更新有序集合。然后将 `mID` 和其对应的内存单元的起始下标加入哈希表。

当调用 `free` 方法时，从哈希表中找到 `mID` 对应的内存单元的起始下标，然后将其从有序集合中删除，再将 `mID` 从哈希表中删除。

时间复杂度 $O(q \log n)$，空间复杂度 $O(n)$，其中 $n$ 和 $q$ 分别为内存空间的大小和方法调用的次数。

<!-- tabs:start -->

#### Python3

```python
class Allocator:

    def __init__(self, n: int):
        self.sl = SortedList([(-1, -1), (n, n)])
        self.d = defaultdict(list)

    def allocate(self, size: int, mID: int) -> int:
        for (_, s), (e, _) in pairwise(self.sl):
            s, e = s + 1, e - 1
            if e - s + 1 >= size:
                self.sl.add((s, s + size - 1))
                self.d[mID].append((s, s + size - 1))
                return s
        return -1

    def freeMemory(self, mID: int) -> int:
        ans = 0
        for block in self.d[mID]:
            self.sl.remove(block)
            ans += block[1] - block[0] + 1
        del self.d[mID]
        return ans


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)
```

#### Java

```java
class Allocator {
    private TreeMap<Integer, Integer> tm = new TreeMap<>();
    private Map<Integer, List<Integer>> d = new HashMap<>();

    public Allocator(int n) {
        tm.put(-1, -1);
        tm.put(n, n);
    }

    public int allocate(int size, int mID) {
        int s = -1;
        for (var entry : tm.entrySet()) {
            int v = entry.getKey();
            if (s != -1) {
                int e = v - 1;
                if (e - s + 1 >= size) {
                    tm.put(s, s + size - 1);
                    d.computeIfAbsent(mID, k -> new ArrayList<>()).add(s);
                    return s;
                }
            }
            s = entry.getValue() + 1;
        }
        return -1;
    }

    public int freeMemory(int mID) {
        int ans = 0;
        for (int s : d.getOrDefault(mID, List.of())) {
            int e = tm.remove(s);
            ans += e - s + 1;
        }
        d.remove(mID);
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */
```

#### C++

```cpp
class Allocator {
public:
    Allocator(int n) {
        tm[-1] = -1;
        tm[n] = n;
    }

    int allocate(int size, int mID) {
        int s = -1;
        for (auto& [v, c] : tm) {
            if (s != -1) {
                int e = v - 1;
                if (e - s + 1 >= size) {
                    tm[s] = s + size - 1;
                    d[mID].emplace_back(s);
                    return s;
                }
            }
            s = c + 1;
        }
        return -1;
    }

    int freeMemory(int mID) {
        int ans = 0;
        for (int& s : d[mID]) {
            int e = tm[s];
            tm.erase(s);
            ans += e - s + 1;
        }
        d.erase(mID);
        return ans;
    }

private:
    map<int, int> tm;
    unordered_map<int, vector<int>> d;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
```

#### Go

```go
type Allocator struct {
	rbt *redblacktree.Tree
	d   map[int][]int
}

func Constructor(n int) Allocator {
	rbt := redblacktree.NewWithIntComparator()
	rbt.Put(-1, -1)
	rbt.Put(n, n)
	return Allocator{rbt, map[int][]int{}}
}

func (this *Allocator) Allocate(size int, mID int) int {
	s := -1
	it := this.rbt.Iterator()
	for it.Next() {
		v := it.Key().(int)
		if s != -1 {
			e := v - 1
			if e-s+1 >= size {
				this.rbt.Put(s, s+size-1)
				this.d[mID] = append(this.d[mID], s)
				return s
			}
		}
		s = it.Value().(int) + 1
	}
	return -1
}

func (this *Allocator) FreeMemory(mID int) int {
	ans := 0
	for _, s := range this.d[mID] {
		if e, ok := this.rbt.Get(s); ok {
			this.rbt.Remove(s)
			ans += e.(int) - s + 1
		}
	}
	this.d[mID] = []int{}
	return ans
}

/**
 * Your Allocator object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Allocate(size,mID);
 * param_2 := obj.FreeMemory(mID);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2503. 矩阵查询可获得的最大分数](https://leetcode.cn/problems/maximum-number-of-points-from-grid-queries){#2503}

{{< tabs "2503" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m, n = len(grid), len(grid[0])
        qs = sorted((v, i) for i, v in enumerate(queries))
        ans = [0] * len(qs)
        q = [(grid[0][0], 0, 0)]
        cnt = 0
        vis = [[False] * n for _ in range(m)]
        vis[0][0] = True
        for v, k in qs:
            while q and q[0][0] < v:
                _, i, j = heappop(q)
                cnt += 1
                for a, b in pairwise((-1, 0, 1, 0, -1)):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and not vis[x][y]:
                        heappush(q, (grid[x][y], x, y))
                        vis[x][y] = True
            ans[k] = cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int k = queries.length;
        int[][] qs = new int[k][2];
        for (int i = 0; i < k; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        int[] ans = new int[k];
        int m = grid.length, n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        vis[0][0] = true;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {grid[0][0], 0, 0});
        int[] dirs = new int[] {-1, 0, 1, 0, -1};
        int cnt = 0;
        for (var e : qs) {
            int v = e[0];
            k = e[1];
            while (!q.isEmpty() && q.peek()[0] < v) {
                var p = q.poll();
                ++cnt;
                for (int h = 0; h < 4; ++h) {
                    int x = p[1] + dirs[h], y = p[2] + dirs[h + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        vis[x][y] = true;
                        q.offer(new int[] {grid[x][y], x, y});
                    }
                }
            }
            ans[k] = cnt;
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
    const int dirs[5] = {-1, 0, 1, 0, -1};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> qs(k);
        for (int i = 0; i < k; ++i) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());
        vector<int> ans(k);
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        vis[0][0] = true;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({grid[0][0], 0, 0});
        int cnt = 0;
        for (auto& e : qs) {
            int v = e.first;
            k = e.second;
            while (!q.empty() && get<0>(q.top()) < v) {
                auto [_, i, j] = q.top();
                q.pop();
                ++cnt;
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        vis[x][y] = true;
                        q.push({grid[x][y], x, y});
                    }
                }
            }
            ans[k] = cnt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPoints(grid [][]int, queries []int) []int {
	k := len(queries)
	qs := make([]pair, k)
	for i, v := range queries {
		qs[i] = pair{v, i}
	}
	sort.Slice(qs, func(i, j int) bool { return qs[i].v < qs[j].v })
	ans := make([]int, k)
	m, n := len(grid), len(grid[0])
	q := hp{}
	heap.Push(&q, tuple{grid[0][0], 0, 0})
	dirs := []int{-1, 0, 1, 0, -1}
	vis := map[int]bool{0: true}
	cnt := 0
	for _, e := range qs {
		v := e.v
		k = e.i
		for len(q) > 0 && q[0].v < v {
			p := heap.Pop(&q).(tuple)
			i, j := p.i, p.j
			cnt++
			for h := 0; h < 4; h++ {
				x, y := i+dirs[h], j+dirs[h+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x*n+y] {
					vis[x*n+y] = true
					heap.Push(&q, tuple{grid[x][y], x, y})
				}
			}
		}
		ans[k] = cnt
	}
	return ans
}

type pair struct{ v, i int }

type tuple struct{ v, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code> 和一个大小为 <code>k</code> 的数组 <code>queries</code> 。</p>

<p>找出一个大小为 <code>k</code> 的数组 <code>answer</code> ，且满足对于每个整数 <code>queries[i]</code> ，你从矩阵 <strong>左上角</strong> 单元格开始，重复以下过程：</p>

<ul>
	<li>如果 <code>queries[i]</code> <strong>严格</strong> 大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1 分，并且你可以移动到所有 <code>4</code> 个方向（上、下、左、右）上任一 <strong>相邻</strong> 单元格。</li>
	<li>否则，你不能获得任何分，并且结束这一过程。</li>
</ul>

<p>在过程结束后，<code>answer[i]</code> 是你可以获得的最大分数。注意，对于每个查询，你可以访问同一个单元格 <strong>多次</strong> 。</p>

<p>返回结果数组 <code>answer</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2503.Maximum%20Number%20of%20Points%20From%20Grid%20Queries/images/image1.png" style="width: 571px; height: 152px;" />
<pre>
<strong>输入：</strong>grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
<strong>输出：</strong>[5,8,1]
<strong>解释：</strong>上图展示了每个查询中访问并获得分数的单元格。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2503.Maximum%20Number%20of%20Points%20From%20Grid%20Queries/images/yetgriddrawio-2.png" />
<pre>
<strong>输入：</strong>grid = [[5,2,1],[1,1,2]], queries = [3]
<strong>输出：</strong>[0]
<strong>解释：</strong>无法获得分数，因为左上角单元格的值大于等于 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= grid[i][j], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离线查询 + BFS + 优先队列（小根堆）

根据题目描述我们知道，每个查询相互独立，查询的顺序不影响结果，并且题目要我们每次从左上角开始，统计所有可以访问的、且值小于当前查询值的单元格的个数。

因此，我们可以先对 `queries` 数组进行排序，然后从小到大依次处理每个查询。

我们用优先队列（小根堆）维护当前访问到的最小单元格的值，用数组或哈希表 `vis` 记录当前单元格是否已经访问过。初始时，将左上角单元格的数据 $(grid[0][0], 0, 0)$ 作为三元组加入优先队列，并将 `vis[0][0]` 置为 `True`。

对于每个查询 `queries[i]`，我们判断当前优先队列的最小值是否小于 `queries[i]`，如果是，则将当前最小值弹出，累加计数器 `cnt`，并将当前单元格的上下左右四个单元格加入优先队列，注意要判断是否已经访问过。重复上述操作，直到当前优先队列的最小值大于等于 `queries[i]`，此时 `cnt` 即为当前查询的答案。

时间复杂度 $O(k \times \log k + m \times n \log(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数，而 $k$ 为查询的个数。我们需要对 `queries` 数组进行排序，时间复杂度为 $O(k \times \log k)$。矩阵中的每个单元格最多只会被访问一次，每一次入队和出队的时间复杂度为 $O(\log(m \times n))$。因此，总时间复杂度为 $O(k \times \log k + m \times n \log(m \times n))$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m, n = len(grid), len(grid[0])
        qs = sorted((v, i) for i, v in enumerate(queries))
        ans = [0] * len(qs)
        q = [(grid[0][0], 0, 0)]
        cnt = 0
        vis = [[False] * n for _ in range(m)]
        vis[0][0] = True
        for v, k in qs:
            while q and q[0][0] < v:
                _, i, j = heappop(q)
                cnt += 1
                for a, b in pairwise((-1, 0, 1, 0, -1)):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and not vis[x][y]:
                        heappush(q, (grid[x][y], x, y))
                        vis[x][y] = True
            ans[k] = cnt
        return ans
```

#### Java

```java
class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int k = queries.length;
        int[][] qs = new int[k][2];
        for (int i = 0; i < k; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        int[] ans = new int[k];
        int m = grid.length, n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        vis[0][0] = true;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {grid[0][0], 0, 0});
        int[] dirs = new int[] {-1, 0, 1, 0, -1};
        int cnt = 0;
        for (var e : qs) {
            int v = e[0];
            k = e[1];
            while (!q.isEmpty() && q.peek()[0] < v) {
                var p = q.poll();
                ++cnt;
                for (int h = 0; h < 4; ++h) {
                    int x = p[1] + dirs[h], y = p[2] + dirs[h + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        vis[x][y] = true;
                        q.offer(new int[] {grid[x][y], x, y});
                    }
                }
            }
            ans[k] = cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int dirs[5] = {-1, 0, 1, 0, -1};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> qs(k);
        for (int i = 0; i < k; ++i) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());
        vector<int> ans(k);
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        vis[0][0] = true;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({grid[0][0], 0, 0});
        int cnt = 0;
        for (auto& e : qs) {
            int v = e.first;
            k = e.second;
            while (!q.empty() && get<0>(q.top()) < v) {
                auto [_, i, j] = q.top();
                q.pop();
                ++cnt;
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        vis[x][y] = true;
                        q.push({grid[x][y], x, y});
                    }
                }
            }
            ans[k] = cnt;
        }
        return ans;
    }
};
```

#### Go

```go
func maxPoints(grid [][]int, queries []int) []int {
	k := len(queries)
	qs := make([]pair, k)
	for i, v := range queries {
		qs[i] = pair{v, i}
	}
	sort.Slice(qs, func(i, j int) bool { return qs[i].v < qs[j].v })
	ans := make([]int, k)
	m, n := len(grid), len(grid[0])
	q := hp{}
	heap.Push(&q, tuple{grid[0][0], 0, 0})
	dirs := []int{-1, 0, 1, 0, -1}
	vis := map[int]bool{0: true}
	cnt := 0
	for _, e := range qs {
		v := e.v
		k = e.i
		for len(q) > 0 && q[0].v < v {
			p := heap.Pop(&q).(tuple)
			i, j := p.i, p.j
			cnt++
			for h := 0; h < 4; h++ {
				x, y := i+dirs[h], j+dirs[h+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x*n+y] {
					vis[x*n+y] = true
					heap.Push(&q, tuple{grid[x][y], x, y})
				}
			}
		}
		ans[k] = cnt
	}
	return ans
}

type pair struct{ v, i int }

type tuple struct{ v, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2504. 把名字和职业联系起来 🔒](https://leetcode.cn/problems/concatenate-the-name-and-the-profession){#2504}

{{< tabs "2504" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT person_id, CONCAT(name, "(", SUBSTRING(profession, 1, 1), ")") AS name
FROM Person
ORDER BY person_id DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Person</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| person_id   | int     |
| name        | varchar |
| profession  | ENUM    |
+-------------+---------+
<code>person_id</code> 是该表的主键（具有唯一值的列）。
该表中的每一行都包含一个人的 ID、姓名和职业。
profession 是 ENUM 类型，其值为 ('Doctor', 'Singer', 'Actor', 'Player', 'Engineer', 'Lawyer') 之一。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案报告每个人的名字，后面是他们职业的第一个字母，用括号括起来。</p>

<p>返回按 <code>person_id</code> <strong>降序排列&nbsp;</strong>的结果表。</p>

<p>返回结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Person 表:
+-----------+-------+------------+
| person_id | name  | profession |
+-----------+-------+------------+
| 1         | Alex  | Singer     |
| 3         | Alice | Actor      |
| 2         | Bob   | Player     |
| 4         | Messi | Doctor     |
| 6         | Tyson | Engineer   |
| 5         | Meir  | Lawyer     |
+-----------+-------+------------+
<strong>输出:</strong> 
+-----------+----------+
| person_id | name     |
+-----------+----------+
| 6         | Tyson(E) |
| 5         | Meir(L)  |
| 4         | Messi(D) |
| 3         | Alice(A) |
| 2         | Bob(P)   |
| 1         | Alex(S)  |
+-----------+----------+
<strong>解释:</strong> 请注意，在名称和职业的第一个字母之间不应该有任何空白。</pre>

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
SELECT person_id, CONCAT(name, "(", SUBSTRING(profession, 1, 1), ")") AS name
FROM Person
ORDER BY person_id DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2505. 所有子序列和的按位或 🔒](https://leetcode.cn/problems/bitwise-or-of-all-subsequence-sums){#2505}

{{< tabs "2505" >}}

{{% tab "python" %}}
```python
class Solution:
    def subsequenceSumOr(self, nums: List[int]) -> int:
        cnt = [0] * 64
        ans = 0
        for v in nums:
            for i in range(31):
                if (v >> i) & 1:
                    cnt[i] += 1
        for i in range(63):
            if cnt[i]:
                ans |= 1 << i
            cnt[i + 1] += cnt[i] // 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long subsequenceSumOr(int[] nums) {
        long[] cnt = new long[64];
        long ans = 0;
        for (int v : nums) {
            for (int i = 0; i < 31; ++i) {
                if (((v >> i) & 1) == 1) {
                    ++cnt[i];
                }
            }
        }
        for (int i = 0; i < 63; ++i) {
            if (cnt[i] > 0) {
                ans |= 1l << i;
            }
            cnt[i + 1] += cnt[i] / 2;
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
    long long subsequenceSumOr(vector<int>& nums) {
        vector<long long> cnt(64);
        long long ans = 0;
        for (int v : nums) {
            for (int i = 0; i < 31; ++i) {
                if (v >> i & 1) {
                    ++cnt[i];
                }
            }
        }
        for (int i = 0; i < 63; ++i) {
            if (cnt[i]) {
                ans |= 1ll << i;
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subsequenceSumOr(nums []int) int64 {
	cnt := make([]int, 64)
	ans := 0
	for _, v := range nums {
		for i := 0; i < 31; i++ {
			if v>>i&1 == 1 {
				cnt[i]++
			}
		}
	}
	for i := 0; i < 63; i++ {
		if cnt[i] > 0 {
			ans |= 1 << i
		}
		cnt[i+1] += cnt[i] / 2
	}
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，返回对数组中所有可能的 <strong>子序列</strong> 之和进行按位 <strong>或</strong> 运算后得到的值。</p>

<p>数组的<strong> 子序列 </strong>是从数组中删除零个或多个元素且不改变剩余元素的顺序得到的序列。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,0,3]
<b>输出：</b>7
<strong>解释：</strong>所有可能的子序列的和包括：0、1、2、3、4、5、6 。
由于 0 OR 1 OR 2 OR 3 OR 4 OR 5 OR 6 = 7，所以返回 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [0,0,0]
<b>输出：</b>0
<strong>解释：</strong>0 是唯一可能的子序列的和，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们先用数组 $cnt$ 统计每一位上 $1$ 的个数，然后从低位到高位，如果该位上 $1$ 的个数大于 $0$，则将该位所表示的数加入到答案中。然后判断是否可以进位，是则累加到下一位。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别为数组长度和数组中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subsequenceSumOr(self, nums: List[int]) -> int:
        cnt = [0] * 64
        ans = 0
        for v in nums:
            for i in range(31):
                if (v >> i) & 1:
                    cnt[i] += 1
        for i in range(63):
            if cnt[i]:
                ans |= 1 << i
            cnt[i + 1] += cnt[i] // 2
        return ans
```

#### Java

```java
class Solution {
    public long subsequenceSumOr(int[] nums) {
        long[] cnt = new long[64];
        long ans = 0;
        for (int v : nums) {
            for (int i = 0; i < 31; ++i) {
                if (((v >> i) & 1) == 1) {
                    ++cnt[i];
                }
            }
        }
        for (int i = 0; i < 63; ++i) {
            if (cnt[i] > 0) {
                ans |= 1l << i;
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        vector<long long> cnt(64);
        long long ans = 0;
        for (int v : nums) {
            for (int i = 0; i < 31; ++i) {
                if (v >> i & 1) {
                    ++cnt[i];
                }
            }
        }
        for (int i = 0; i < 63; ++i) {
            if (cnt[i]) {
                ans |= 1ll << i;
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        return ans;
    }
};
```

#### Go

```go
func subsequenceSumOr(nums []int) int64 {
	cnt := make([]int, 64)
	ans := 0
	for _, v := range nums {
		for i := 0; i < 31; i++ {
			if v>>i&1 == 1 {
				cnt[i]++
			}
		}
	}
	for i := 0; i < 63; i++ {
		if cnt[i] > 0 {
			ans |= 1 << i
		}
		cnt[i+1] += cnt[i] / 2
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2506. 统计相似字符串对的数目](https://leetcode.cn/problems/count-pairs-of-similar-strings){#2506}

{{< tabs "2506" >}}

{{% tab "python" %}}
```python
class Solution:
    def similarPairs(self, words: List[str]) -> int:
        ans = 0
        cnt = Counter()
        for s in words:
            x = 0
            for c in map(ord, s):
                x |= 1 << (c - ord("a"))
            ans += cnt[x]
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int similarPairs(String[] words) {
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (var s : words) {
            int x = 0;
            for (char c : s.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            ans += cnt.merge(x, 1, Integer::sum) - 1;
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
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (const auto& s : words) {
            int x = 0;
            for (auto& c : s) {
                x |= 1 << (c - 'a');
            }
            ans += cnt[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func similarPairs(words []string) (ans int) {
	cnt := map[int]int{}
	for _, s := range words {
		x := 0
		for _, c := range s {
			x |= 1 << (c - 'a')
		}
		ans += cnt[x]
		cnt[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function similarPairs(words: string[]): number {
    let ans = 0;
    const cnt = new Map<number, number>();
    for (const s of words) {
        let x = 0;
        for (const c of s) {
            x |= 1 << (c.charCodeAt(0) - 97);
        }
        ans += cnt.get(x) || 0;
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for s in words {
            let mut x = 0;
            for c in s.chars() {
                x |= 1 << ((c as u8) - b'a');
            }
            ans += cnt.get(&x).unwrap_or(&0);
            *cnt.entry(x).or_insert(0) += 1;
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 。</p>

<p>如果两个字符串由相同的字符组成，则认为这两个字符串 <strong>相似</strong> 。</p>

<ul>
	<li>例如，<code>"abca"</code> 和 <code>"cba"</code> 相似，因为它们都由字符 <code>'a'</code>、<code>'b'</code>、<code>'c'</code> 组成。</li>
	<li>然而，<code>"abacba"</code> 和 <code>"bcfd"</code> 不相似，因为它们不是相同字符组成的。</li>
</ul>

<p>请你找出满足字符串&nbsp;<code>words[i]</code><em> </em>和<em> </em><code>words[j]</code> 相似的下标对<em> </em><code>(i, j)</code><em> </em>，并返回下标对的数目，其中 <code>0 &lt;= i &lt; j &lt;= words.length - 1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["aba","aabb","abcd","bac","aabc"]
<strong>输出：</strong>2
<strong>解释：</strong>共有 2 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
- i = 3 且 j = 4 ：words[3] 和 words[4] 只由字符 'a'、'b' 和 'c' 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["aabb","ab","ba"]
<strong>输出：</strong>3
<strong>解释：</strong>共有 3 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
- i = 0 且 j = 2 ：words[0] 和 words[2] 只由字符 'a' 和 'b' 组成。 
- i = 1 且 j = 2 ：words[1] 和 words[2] 只由字符 'a' 和 'b' 组成。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["nba","cba","dba"]
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足条件的下标对，返回 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 位运算

对于每个字符串，我们可以将其转换为一个长度为 $26$ 的二进制数，其中第 $i$ 位为 $1$ 表示该字符串中包含第 $i$ 个字母。

如果两个字符串包含相同的字母，则它们的二进制数是相同的，因此，对于每个字符串，我们用哈希表统计其二进制数出现的次数，每一次累加到答案中，再将其二进制数出现的次数加 $1$。

时间复杂度 $O(L)$，空间复杂度 $O(n)$。其中 $L$ 是所有字符串的长度之和，而 $n$ 是字符串的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def similarPairs(self, words: List[str]) -> int:
        ans = 0
        cnt = Counter()
        for s in words:
            x = 0
            for c in map(ord, s):
                x |= 1 << (c - ord("a"))
            ans += cnt[x]
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int similarPairs(String[] words) {
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (var s : words) {
            int x = 0;
            for (char c : s.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            ans += cnt.merge(x, 1, Integer::sum) - 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (const auto& s : words) {
            int x = 0;
            for (auto& c : s) {
                x |= 1 << (c - 'a');
            }
            ans += cnt[x]++;
        }
        return ans;
    }
};
```

#### Go

```go
func similarPairs(words []string) (ans int) {
	cnt := map[int]int{}
	for _, s := range words {
		x := 0
		for _, c := range s {
			x |= 1 << (c - 'a')
		}
		ans += cnt[x]
		cnt[x]++
	}
	return
}
```

#### TypeScript

```ts
function similarPairs(words: string[]): number {
    let ans = 0;
    const cnt = new Map<number, number>();
    for (const s of words) {
        let x = 0;
        for (const c of s) {
            x |= 1 << (c.charCodeAt(0) - 97);
        }
        ans += cnt.get(x) || 0;
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for s in words {
            let mut x = 0;
            for c in s.chars() {
                x |= 1 << ((c as u8) - b'a');
            }
            ans += cnt.get(&x).unwrap_or(&0);
            *cnt.entry(x).or_insert(0) += 1;
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

# [2507. 使用质因数之和替换后可以取到的最小值](https://leetcode.cn/problems/smallest-value-after-replacing-with-sum-of-prime-factors){#2507}

{{< tabs "2507" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestValue(self, n: int) -> int:
        while 1:
            t, s, i = n, 0, 2
            while i <= n // i:
                while n % i == 0:
                    n //= i
                    s += i
                i += 1
            if n > 1:
                s += n
            if s == t:
                return t
            n = s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestValue(int n) {
        while (true) {
            int t = n, s = 0;
            for (int i = 2; i <= n / i; ++i) {
                while (n % i == 0) {
                    s += i;
                    n /= i;
                }
            }
            if (n > 1) {
                s += n;
            }
            if (s == t) {
                return s;
            }
            n = s;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestValue(int n) {
        while (1) {
            int t = n, s = 0;
            for (int i = 2; i <= n / i; ++i) {
                while (n % i == 0) {
                    s += i;
                    n /= i;
                }
            }
            if (n > 1) s += n;
            if (s == t) return s;
            n = s;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestValue(n int) int {
	for {
		t, s := n, 0
		for i := 2; i <= n/i; i++ {
			for n%i == 0 {
				s += i
				n /= i
			}
		}
		if n > 1 {
			s += n
		}
		if s == t {
			return s
		}
		n = s
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> 。</p>

<p>请你将 <code>n</code> 的值替换为 <code>n</code> 的 <strong>质因数</strong> 之和，重复这一过程。</p>

<ul>
	<li>注意，如果 <code>n</code> 能够被某个质因数多次整除，则在求和时，应当包含这个质因数同样次数。</li>
</ul>

<p>返回<em> </em><code>n</code><em> </em>可以取到的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 15
<strong>输出：</strong>5
<strong>解释：</strong>最开始，n = 15 。
15 = 3 * 5 ，所以 n 替换为 3 + 5 = 8 。
8 = 2 * 2 * 2 ，所以 n 替换为 2 + 2 + 2 = 6 。
6 = 2 * 3 ，所以 n 替换为 2 + 3 = 5 。
5 是 n 可以取到的最小值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>最开始，n = 3 。
3 是 n 可以取到的最小值。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力模拟

根据题意，我们可以得到一个质因数分解的过程，即将一个数不断地分解为质因数，分解不能分解。过程中将每次分解的质因数相加，递归或者迭代地进行即可。

时间复杂度 $O(\sqrt{n})$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestValue(self, n: int) -> int:
        while 1:
            t, s, i = n, 0, 2
            while i <= n // i:
                while n % i == 0:
                    n //= i
                    s += i
                i += 1
            if n > 1:
                s += n
            if s == t:
                return t
            n = s
```

#### Java

```java
class Solution {
    public int smallestValue(int n) {
        while (true) {
            int t = n, s = 0;
            for (int i = 2; i <= n / i; ++i) {
                while (n % i == 0) {
                    s += i;
                    n /= i;
                }
            }
            if (n > 1) {
                s += n;
            }
            if (s == t) {
                return s;
            }
            n = s;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestValue(int n) {
        while (1) {
            int t = n, s = 0;
            for (int i = 2; i <= n / i; ++i) {
                while (n % i == 0) {
                    s += i;
                    n /= i;
                }
            }
            if (n > 1) s += n;
            if (s == t) return s;
            n = s;
        }
    }
};
```

#### Go

```go
func smallestValue(n int) int {
	for {
		t, s := n, 0
		for i := 2; i <= n/i; i++ {
			for n%i == 0 {
				s += i
				n /= i
			}
		}
		if n > 1 {
			s += n
		}
		if s == t {
			return s
		}
		n = s
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2508. 添加边使所有节点度数都为偶数](https://leetcode.cn/problems/add-edges-to-make-degrees-of-all-nodes-even){#2508}

{{< tabs "2508" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
        g = defaultdict(set)
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        vs = [i for i, v in g.items() if len(v) & 1]
        if len(vs) == 0:
            return True
        if len(vs) == 2:
            a, b = vs
            if a not in g[b]:
                return True
            return any(a not in g[c] and c not in g[b] for c in range(1, n + 1))
        if len(vs) == 4:
            a, b, c, d = vs
            if a not in g[b] and c not in g[d]:
                return True
            if a not in g[c] and b not in g[d]:
                return True
            if a not in g[d] and b not in g[c]:
                return True
            return False
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPossible(int n, List<List<Integer>> edges) {
        Set<Integer>[] g = new Set[n + 1];
        Arrays.setAll(g, k -> new HashSet<>());
        for (var e : edges) {
            int a = e.get(0), b = e.get(1);
            g[a].add(b);
            g[b].add(a);
        }
        List<Integer> vs = new ArrayList<>();
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() % 2 == 1) {
                vs.add(i);
            }
        }
        if (vs.size() == 0) {
            return true;
        }
        if (vs.size() == 2) {
            int a = vs.get(0), b = vs.get(1);
            if (!g[a].contains(b)) {
                return true;
            }
            for (int c = 1; c <= n; ++c) {
                if (a != c && b != c && !g[a].contains(c) && !g[c].contains(b)) {
                    return true;
                }
            }
            return false;
        }
        if (vs.size() == 4) {
            int a = vs.get(0), b = vs.get(1), c = vs.get(2), d = vs.get(3);
            if (!g[a].contains(b) && !g[c].contains(d)) {
                return true;
            }
            if (!g[a].contains(c) && !g[b].contains(d)) {
                return true;
            }
            if (!g[a].contains(d) && !g[b].contains(c)) {
                return true;
            }
            return false;
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
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n + 1);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        vector<int> vs;
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() % 2) {
                vs.emplace_back(i);
            }
        }
        if (vs.size() == 0) {
            return true;
        }
        if (vs.size() == 2) {
            int a = vs[0], b = vs[1];
            if (!g[a].count(b)) return true;
            for (int c = 1; c <= n; ++c) {
                if (a != b && b != c && !g[a].count(c) && !g[c].count(b)) {
                    return true;
                }
            }
            return false;
        }
        if (vs.size() == 4) {
            int a = vs[0], b = vs[1], c = vs[2], d = vs[3];
            if (!g[a].count(b) && !g[c].count(d)) return true;
            if (!g[a].count(c) && !g[b].count(d)) return true;
            if (!g[a].count(d) && !g[b].count(c)) return true;
            return false;
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPossible(n int, edges [][]int) bool {
	g := make([]map[int]bool, n+1)
	for _, e := range edges {
		a, b := e[0], e[1]
		if g[a] == nil {
			g[a] = map[int]bool{}
		}
		if g[b] == nil {
			g[b] = map[int]bool{}
		}
		g[a][b], g[b][a] = true, true
	}
	vs := []int{}
	for i := 1; i <= n; i++ {
		if len(g[i])%2 == 1 {
			vs = append(vs, i)
		}
	}
	if len(vs) == 0 {
		return true
	}
	if len(vs) == 2 {
		a, b := vs[0], vs[1]
		if !g[a][b] {
			return true
		}
		for c := 1; c <= n; c++ {
			if a != c && b != c && !g[a][c] && !g[c][b] {
				return true
			}
		}
		return false
	}
	if len(vs) == 4 {
		a, b, c, d := vs[0], vs[1], vs[2], vs[3]
		if !g[a][b] && !g[c][d] {
			return true
		}
		if !g[a][c] && !g[b][d] {
			return true
		}
		if !g[a][d] && !g[b][c] {
			return true
		}
		return false
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有 <code>n</code>&nbsp;个节点的 <strong>无向</strong>&nbsp;图，节点编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;。再给你整数&nbsp;<code>n</code>&nbsp;和一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。图不一定连通。</p>

<p>你可以给图中添加 <strong>至多</strong>&nbsp;两条额外的边（也可以一条边都不添加），使得图中没有重边也没有自环。</p>

<p>如果添加额外的边后，可以使得图中所有点的度数都是偶数，返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>点的度数是连接一个点的边的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2508.Add%20Edges%20to%20Make%20Degrees%20of%20All%20Nodes%20Even/images/agraphdrawio.png" style="width: 500px; height: 190px;" /></p>

<pre>
<b>输入：</b>n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
<b>输出：</b>true
<b>解释：</b>上图展示了添加一条边的合法方案。
最终图中每个节点都连接偶数条边。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2508.Add%20Edges%20to%20Make%20Degrees%20of%20All%20Nodes%20Even/images/aagraphdrawio.png" style="width: 400px; height: 120px;" /></p>

<pre>
<b>输入：</b>n = 4, edges = [[1,2],[3,4]]
<b>输出：</b>true
<b>解释：</b>上图展示了添加两条边的合法方案。</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2508.Add%20Edges%20to%20Make%20Degrees%20of%20All%20Nodes%20Even/images/aaagraphdrawio.png" style="width: 150px; height: 158px;" /></p>

<pre>
<b>输入：</b>n = 4, edges = [[1,2],[1,3],[1,4]]
<b>输出：</b>false
<b>解释：</b>无法添加至多 2 条边得到一个符合要求的图。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>图中不会有重边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

我们先通过 `edges` 构建图 $g$，然后找出所有度数为奇数的点，记为 $vs$。

如果 $vs$ 的长度为 $0$，说明图 $g$ 中所有点的度数都是偶数，直接返回 `true` 即可。

如果 $vs$ 的长度为 $2$，说明图 $g$ 中有两个点的度数是奇数。如果我们可以直接用一条边连接这两个点，使得图 $g$ 中所有点的度数都是偶数，返回 `true`；否则，如果我们能找到第三个点 $c$，使得我们能够连接 $a$ 和 $c$，以及连接 $b$ 和 $c$，使得图 $g$ 中所有点的度数都是偶数，返回 `true`；否则，返回 `false`。

如果 $vs$ 的长度为 $4$，我们枚举两两组合的所有情况，判断是否存在满足条件的情况，是则返回 `true`；否则，返回 `false`。

其它情况，返回 `false`。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为节点的数量和边的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
        g = defaultdict(set)
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        vs = [i for i, v in g.items() if len(v) & 1]
        if len(vs) == 0:
            return True
        if len(vs) == 2:
            a, b = vs
            if a not in g[b]:
                return True
            return any(a not in g[c] and c not in g[b] for c in range(1, n + 1))
        if len(vs) == 4:
            a, b, c, d = vs
            if a not in g[b] and c not in g[d]:
                return True
            if a not in g[c] and b not in g[d]:
                return True
            if a not in g[d] and b not in g[c]:
                return True
            return False
        return False
```

#### Java

```java
class Solution {
    public boolean isPossible(int n, List<List<Integer>> edges) {
        Set<Integer>[] g = new Set[n + 1];
        Arrays.setAll(g, k -> new HashSet<>());
        for (var e : edges) {
            int a = e.get(0), b = e.get(1);
            g[a].add(b);
            g[b].add(a);
        }
        List<Integer> vs = new ArrayList<>();
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() % 2 == 1) {
                vs.add(i);
            }
        }
        if (vs.size() == 0) {
            return true;
        }
        if (vs.size() == 2) {
            int a = vs.get(0), b = vs.get(1);
            if (!g[a].contains(b)) {
                return true;
            }
            for (int c = 1; c <= n; ++c) {
                if (a != c && b != c && !g[a].contains(c) && !g[c].contains(b)) {
                    return true;
                }
            }
            return false;
        }
        if (vs.size() == 4) {
            int a = vs.get(0), b = vs.get(1), c = vs.get(2), d = vs.get(3);
            if (!g[a].contains(b) && !g[c].contains(d)) {
                return true;
            }
            if (!g[a].contains(c) && !g[b].contains(d)) {
                return true;
            }
            if (!g[a].contains(d) && !g[b].contains(c)) {
                return true;
            }
            return false;
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n + 1);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        vector<int> vs;
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() % 2) {
                vs.emplace_back(i);
            }
        }
        if (vs.size() == 0) {
            return true;
        }
        if (vs.size() == 2) {
            int a = vs[0], b = vs[1];
            if (!g[a].count(b)) return true;
            for (int c = 1; c <= n; ++c) {
                if (a != b && b != c && !g[a].count(c) && !g[c].count(b)) {
                    return true;
                }
            }
            return false;
        }
        if (vs.size() == 4) {
            int a = vs[0], b = vs[1], c = vs[2], d = vs[3];
            if (!g[a].count(b) && !g[c].count(d)) return true;
            if (!g[a].count(c) && !g[b].count(d)) return true;
            if (!g[a].count(d) && !g[b].count(c)) return true;
            return false;
        }
        return false;
    }
};
```

#### Go

```go
func isPossible(n int, edges [][]int) bool {
	g := make([]map[int]bool, n+1)
	for _, e := range edges {
		a, b := e[0], e[1]
		if g[a] == nil {
			g[a] = map[int]bool{}
		}
		if g[b] == nil {
			g[b] = map[int]bool{}
		}
		g[a][b], g[b][a] = true, true
	}
	vs := []int{}
	for i := 1; i <= n; i++ {
		if len(g[i])%2 == 1 {
			vs = append(vs, i)
		}
	}
	if len(vs) == 0 {
		return true
	}
	if len(vs) == 2 {
		a, b := vs[0], vs[1]
		if !g[a][b] {
			return true
		}
		for c := 1; c <= n; c++ {
			if a != c && b != c && !g[a][c] && !g[c][b] {
				return true
			}
		}
		return false
	}
	if len(vs) == 4 {
		a, b, c, d := vs[0], vs[1], vs[2], vs[3]
		if !g[a][b] && !g[c][d] {
			return true
		}
		if !g[a][c] && !g[b][d] {
			return true
		}
		if !g[a][d] && !g[b][c] {
			return true
		}
		return false
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2509. 查询树中环的长度](https://leetcode.cn/problems/cycle-length-queries-in-a-tree){#2509}

{{< tabs "2509" >}}

{{% tab "python" %}}
```python
class Solution:
    def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        ans = []
        for a, b in queries:
            t = 1
            while a != b:
                if a > b:
                    a >>= 1
                else:
                    b >>= 1
                t += 1
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] cycleLengthQueries(int n, int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            int t = 1;
            while (a != b) {
                if (a > b) {
                    a >>= 1;
                } else {
                    b >>= 1;
                }
                ++t;
            }
            ans[i] = t;
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
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int t = 1;
            while (a != b) {
                if (a > b) {
                    a >>= 1;
                } else {
                    b >>= 1;
                }
                ++t;
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func cycleLengthQueries(n int, queries [][]int) []int {
	ans := []int{}
	for _, q := range queries {
		a, b := q[0], q[1]
		t := 1
		for a != b {
			if a > b {
				a >>= 1
			} else {
				b >>= 1
			}
			t++
		}
		ans = append(ans, t)
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

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示你有一棵含有&nbsp;<code>2<sup>n</sup> - 1</code>&nbsp;个节点的 <strong>完全二叉树</strong>&nbsp;。根节点的编号是&nbsp;<code>1</code>&nbsp;，树中编号在<code>[1, 2<sup>n - 1</sup> - 1]</code>&nbsp;之间，编号为&nbsp;<code>val</code>&nbsp;的节点都有两个子节点，满足：</p>

<ul>
	<li>左子节点的编号为&nbsp;<code>2 * val</code></li>
	<li>右子节点的编号为&nbsp;<code>2 * val + 1</code></li>
</ul>

<p>给你一个长度为 <code>m</code>&nbsp;的查询数组 <code>queries</code>&nbsp;，它是一个二维整数数组，其中&nbsp;<code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;。对于每个查询，求出以下问题的解：</p>

<ol>
	<li>在节点编号为&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间添加一条边。</li>
	<li>求出图中环的长度。</li>
	<li>删除节点编号为&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间新添加的边。</li>
</ol>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>环</strong> 是开始和结束于同一节点的一条路径，路径中每条边都只会被访问一次。</li>
	<li>环的长度是环中边的数目。</li>
	<li>在树中添加额外的边后，两个点之间可能会有多条边。</li>
</ul>

<p>请你返回一个长度为 <code>m</code>&nbsp;的数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个查询的结果<i>。</i></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2509.Cycle%20Length%20Queries%20in%20a%20Tree/images/bexample1.png" style="width: 647px; height: 128px;" /></p>

<pre>
<b>输入：</b>n = 3, queries = [[5,3],[4,7],[2,3]]
<b>输出：</b>[4,5,3]
<b>解释：</b>上图是一棵有 2<sup>3</sup> - 1 个节点的树。红色节点表示添加额外边后形成环的节点。
- 在节点 3 和节点 5 之间添加边后，环为 [5,2,1,3] ，所以第一个查询的结果是 4 。删掉添加的边后处理下一个查询。
- 在节点 4 和节点 7 之间添加边后，环为 [4,2,1,3,7] ，所以第二个查询的结果是 5 。删掉添加的边后处理下一个查询。
- 在节点 2 和节点 3 之间添加边后，环为 [2,1,3] ，所以第三个查询的结果是 3 。删掉添加的边。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2509.Cycle%20Length%20Queries%20in%20a%20Tree/images/aexample2.png" style="width: 146px; height: 71px;" /></p>

<pre>
<b>输入：</b>n = 2, queries = [[1,2]]
<b>输出：</b>[2]
<b>解释：</b>上图是一棵有 2<sup>2</sup> - 1 个节点的树。红色节点表示添加额外边后形成环的节点。
- 在节点 1 和节点 2 之间添加边后，环为 [2,1] ，所以第一个查询的结果是 2 。删掉添加的边。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 30</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= 2<sup>n</sup> - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求最近公共祖先

对于每次查询，我们找出 $a$, $b$ 两个节点的最近公共祖先，并且记录向上走的步数，那么此次查询的答案就是步数加一。

求最近公共祖先时，如果 $a \gt b$，那么我们将 $a$ 往父节点移动；如果 $a \lt b$，我们将 $b$ 往其父节点移动。过程中累计步数，直至 $a = b$。

时间复杂度 $O(n \times m)$。其中 $m$ 为数组 `queries` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        ans = []
        for a, b in queries:
            t = 1
            while a != b:
                if a > b:
                    a >>= 1
                else:
                    b >>= 1
                t += 1
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public int[] cycleLengthQueries(int n, int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            int t = 1;
            while (a != b) {
                if (a > b) {
                    a >>= 1;
                } else {
                    b >>= 1;
                }
                ++t;
            }
            ans[i] = t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int t = 1;
            while (a != b) {
                if (a > b) {
                    a >>= 1;
                } else {
                    b >>= 1;
                }
                ++t;
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```

#### Go

```go
func cycleLengthQueries(n int, queries [][]int) []int {
	ans := []int{}
	for _, q := range queries {
		a, b := q[0], q[1]
		t := 1
		for a != b {
			if a > b {
				a >>= 1
			} else {
				b >>= 1
			}
			t++
		}
		ans = append(ans, t)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
