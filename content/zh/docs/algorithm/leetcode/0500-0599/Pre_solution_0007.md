---
title: "0560_和为 K 的子数组"
date: 2025-10-08T18:36:17+08:00
weight: 7
tags: [二叉树, 前缀和, 动态规划, 双指针, 哈希表, 字符串, 排序, 数学, 数据库, 数组, 树, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 计数排序, 贪心]
---

{{< markmap >}}
### [0560_和为 K 的子数组](#560)
#### [数组](#560)
#### [哈希表](#560)
#### [前缀和](#560)
### [0561_数组拆分](#561)
#### [贪心](#561)
#### [数组](#561)
#### [计数排序](#561)
#### [排序](#561)
### [0562_矩阵中最长的连续1线段 🔒](#562)
#### [数组](#562)
#### [动态规划](#562)
#### [矩阵](#562)
### [0563_二叉树的坡度](#563)
#### [树](#563)
#### [深度优先搜索](#563)
#### [二叉树](#563)
### [0564_寻找最近的回文数](#564)
#### [数学](#564)
#### [字符串](#564)
### [0565_数组嵌套](#565)
#### [深度优先搜索](#565)
#### [数组](#565)
### [0566_重塑矩阵](#566)
#### [数组](#566)
#### [矩阵](#566)
#### [模拟](#566)
### [0567_字符串的排列](#567)
#### [哈希表](#567)
#### [双指针](#567)
#### [字符串](#567)
#### [滑动窗口](#567)
### [0568_最大休假天数 🔒](#568)
#### [数组](#568)
#### [动态规划](#568)
#### [矩阵](#568)
### [0569_员工薪水中位数 🔒](#569)
#### [数据库](#569)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0560_和为 K 的子数组
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 0561_数组拆分
___
#### 贪心
___
#### 数组
___
#### 计数排序
___
#### 排序
---
### 0562_矩阵中最长的连续1线段 🔒
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0563_二叉树的坡度
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0564_寻找最近的回文数
___
#### 数学
___
#### 字符串
---
### 0565_数组嵌套
___
#### 深度优先搜索
___
#### 数组
---
### 0566_重塑矩阵
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 0567_字符串的排列
___
#### 哈希表
___
#### 双指针
___
#### 字符串
___
#### 滑动窗口
---
### 0568_最大休假天数 🔒
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0569_员工薪水中位数 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 计数排序 | 贪心 |  |

# [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k){#560}

{{< tabs "560" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = Counter({0: 1})
        ans = s = 0
        for x in nums:
            s += x
            ans += cnt[s - k]
            cnt[s] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            ans += cnt.getOrDefault(s - k, 0);
            cnt.merge(s, 1, Integer::sum);
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt{{0, 1}};
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            ans += cnt[s - k];
            ++cnt[s];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subarraySum(nums []int, k int) (ans int) {
	cnt := map[int]int{0: 1}
	s := 0
	for _, x := range nums {
		s += x
		ans += cnt[s-k]
		cnt[s]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subarraySum(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    cnt.set(0, 1);
    let [ans, s] = [0, 0];
    for (const x of nums) {
        s += x;
        ans += cnt.get(s - k) || 0;
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        cnt.insert(0, 1);
        let mut ans = 0;
        let mut s = 0;
        for &x in &nums {
            s += x;
            if let Some(&v) = cnt.get(&(s - k)) {
                ans += v;
            }
            *cnt.entry(s).or_insert(0) += 1;
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

<p>给你一个整数数组 <code>nums</code> 和一个整数&nbsp;<code>k</code> ，请你统计并返回 <em>该数组中和为&nbsp;<code>k</code><strong>&nbsp;</strong>的子数组的个数&nbsp;</em>。</p>

<p>子数组是数组中元素的连续非空序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1], k = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], k = 3
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

我们定义一个哈希表 $\textit{cnt}$，用于存储数组 $\textit{nums}$ 的前缀和出现的次数。初始时，我们将 $\textit{cnt}[0]$ 的值设为 $1$，表示前缀和 $0$ 出现了一次。

我们遍历数组 $\textit{nums}$，计算前缀和 $\textit{s}$，然后将 $\textit{cnt}[s - k]$ 的值累加到答案中，并将 $\textit{cnt}[s]$ 的值增加 $1$。

遍历结束后，我们返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = Counter({0: 1})
        ans = s = 0
        for x in nums:
            s += x
            ans += cnt[s - k]
            cnt[s] += 1
        return ans
```

#### Java

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            ans += cnt.getOrDefault(s - k, 0);
            cnt.merge(s, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt{{0, 1}};
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            ans += cnt[s - k];
            ++cnt[s];
        }
        return ans;
    }
};
```

#### Go

```go
func subarraySum(nums []int, k int) (ans int) {
	cnt := map[int]int{0: 1}
	s := 0
	for _, x := range nums {
		s += x
		ans += cnt[s-k]
		cnt[s]++
	}
	return
}
```

#### TypeScript

```ts
function subarraySum(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    cnt.set(0, 1);
    let [ans, s] = [0, 0];
    for (const x of nums) {
        s += x;
        ans += cnt.get(s - k) || 0;
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        cnt.insert(0, 1);
        let mut ans = 0;
        let mut s = 0;
        for &x in &nums {
            s += x;
            if let Some(&v) = cnt.get(&(s - k)) {
                ans += v;
            }
            *cnt.entry(s).or_insert(0) += 1;
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

# [561. 数组拆分](https://leetcode.cn/problems/array-partition){#561}

{{< tabs "561" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[::2])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length; i += 2) {
            ans += nums[i];
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
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrayPairSum(nums []int) (ans int) {
	sort.Ints(nums)
	for i := 0; i < len(nums); i += 2 {
		ans += nums[i]
	}
	return
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        nums.iter().step_by(2).sum()
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
var arrayPairSum = function (nums) {
    nums.sort((a, b) => a - b);
    return nums.reduce((acc, cur, i) => (i % 2 === 0 ? acc + cur : acc), 0);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定长度为&nbsp;<code>2n</code><strong>&nbsp;</strong>的整数数组 <code>nums</code> ，你的任务是将这些数分成&nbsp;<code>n</code><strong> </strong>对, 例如 <code>(a<sub>1</sub>, b<sub>1</sub>), (a<sub>2</sub>, b<sub>2</sub>), ..., (a<sub>n</sub>, b<sub>n</sub>)</code> ，使得从 <code>1</code> 到&nbsp;<code>n</code> 的 <code>min(a<sub>i</sub>, b<sub>i</sub>)</code> 总和最大。</p>

<p>返回该 <strong>最大总和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,3,2]
<strong>输出：</strong>4
<strong>解释：</strong>所有可能的分法（忽略元素顺序）为：
1. (1, 4), (2, 3) -&gt; min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -&gt; min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -&gt; min(1, 2) + min(3, 4) = 1 + 3 = 4
所以最大总和为 4</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,2,6,5,1,2]
<strong>输出：</strong>9
<strong>解释：</strong>最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

对于一个数对 $(a, b)$，我们不妨设 $a \leq b$，那么 $\min(a, b) = a$。为了使得总和尽可能大，我们取的 $b$ 应该与 $a$ 尽可能接近，这样可以保留更大的数。

因此，我们可以对数组 $nums$ 进行排序，然后将相邻的两个数分为一组，取每组的第一个数相加即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[::2])
```

#### Java

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};
```

#### Go

```go
func arrayPairSum(nums []int) (ans int) {
	sort.Ints(nums)
	for i := 0; i < len(nums); i += 2 {
		ans += nums[i]
	}
	return
}
```

#### Rust

```rust
impl Solution {
    pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        nums.iter().step_by(2).sum()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function (nums) {
    nums.sort((a, b) => a - b);
    return nums.reduce((acc, cur, i) => (i % 2 === 0 ? acc + cur : acc), 0);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [562. 矩阵中最长的连续1线段 🔒](https://leetcode.cn/problems/longest-line-of-consecutive-one-in-matrix){#562}

{{< tabs "562" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestLine(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        a = [[0] * (n + 2) for _ in range(m + 2)]
        b = [[0] * (n + 2) for _ in range(m + 2)]
        c = [[0] * (n + 2) for _ in range(m + 2)]
        d = [[0] * (n + 2) for _ in range(m + 2)]
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if mat[i - 1][j - 1]:
                    a[i][j] = a[i - 1][j] + 1
                    b[i][j] = b[i][j - 1] + 1
                    c[i][j] = c[i - 1][j - 1] + 1
                    d[i][j] = d[i - 1][j + 1] + 1
                    ans = max(ans, a[i][j], b[i][j], c[i][j], d[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestLine(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] a = new int[m + 2][n + 2];
        int[][] b = new int[m + 2][n + 2];
        int[][] c = new int[m + 2][n + 2];
        int[][] d = new int[m + 2][n + 2];
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mat[i - 1][j - 1] == 1) {
                    a[i][j] = a[i - 1][j] + 1;
                    b[i][j] = b[i][j - 1] + 1;
                    c[i][j] = c[i - 1][j - 1] + 1;
                    d[i][j] = d[i - 1][j + 1] + 1;
                    ans = max(ans, a[i][j], b[i][j], c[i][j], d[i][j]);
                }
            }
        }
        return ans;
    }

    private int max(int... arr) {
        int ans = 0;
        for (int v : arr) {
            ans = Math.max(ans, v);
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
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> a(m + 2, vector<int>(n + 2));
        vector<vector<int>> b(m + 2, vector<int>(n + 2));
        vector<vector<int>> c(m + 2, vector<int>(n + 2));
        vector<vector<int>> d(m + 2, vector<int>(n + 2));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mat[i - 1][j - 1]) {
                    a[i][j] = a[i - 1][j] + 1;
                    b[i][j] = b[i][j - 1] + 1;
                    c[i][j] = c[i - 1][j - 1] + 1;
                    d[i][j] = d[i - 1][j + 1] + 1;
                    ans = max(ans, max(a[i][j], max(b[i][j], max(c[i][j], d[i][j]))));
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestLine(mat [][]int) (ans int) {
	m, n := len(mat), len(mat[0])
	f := make([][][4]int, m+2)
	for i := range f {
		f[i] = make([][4]int, n+2)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if mat[i-1][j-1] == 1 {
				f[i][j][0] = f[i-1][j][0] + 1
				f[i][j][1] = f[i][j-1][1] + 1
				f[i][j][2] = f[i-1][j-1][2] + 1
				f[i][j][3] = f[i-1][j+1][3] + 1
				for _, v := range f[i][j] {
					if ans < v {
						ans = v
					}
				}
			}
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

<p>给定一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵 <code>mat</code><b>&nbsp;</b>，返回矩阵中最长的连续1线段。</p>

<p>这条线段可以是水平的、垂直的、对角线的或者反对角线的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0562.Longest%20Line%20of%20Consecutive%20One%20in%20Matrix/images/long1-grid.jpg" /></p>

<pre>
<strong>输入:</strong>&nbsp;mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
<strong>输出:</strong> 3
</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0562.Longest%20Line%20of%20Consecutive%20One%20in%20Matrix/images/long2-grid.jpg" /></p>

<pre>
<strong>输入:</strong> mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i][j]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j][k]$ 表示方向为 $k$，且以 $(i, j)$ 结尾的最长连续 $1$ 的长度。其中 $k$ 的取值范围为 $0, 1, 2, 3$，分别表示水平、垂直、对角线、反对角线。

> 我们也可以用四个二维数组分别表示四个方向的最长连续 $1$ 的长度。

遍历矩阵，当遇到 $1$ 时，更新 $f[i][j][k]$ 的值。对于每个位置 $(i, j)$，我们只需要更新其四个方向的值即可。然后更新答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestLine(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        a = [[0] * (n + 2) for _ in range(m + 2)]
        b = [[0] * (n + 2) for _ in range(m + 2)]
        c = [[0] * (n + 2) for _ in range(m + 2)]
        d = [[0] * (n + 2) for _ in range(m + 2)]
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if mat[i - 1][j - 1]:
                    a[i][j] = a[i - 1][j] + 1
                    b[i][j] = b[i][j - 1] + 1
                    c[i][j] = c[i - 1][j - 1] + 1
                    d[i][j] = d[i - 1][j + 1] + 1
                    ans = max(ans, a[i][j], b[i][j], c[i][j], d[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int longestLine(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] a = new int[m + 2][n + 2];
        int[][] b = new int[m + 2][n + 2];
        int[][] c = new int[m + 2][n + 2];
        int[][] d = new int[m + 2][n + 2];
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mat[i - 1][j - 1] == 1) {
                    a[i][j] = a[i - 1][j] + 1;
                    b[i][j] = b[i][j - 1] + 1;
                    c[i][j] = c[i - 1][j - 1] + 1;
                    d[i][j] = d[i - 1][j + 1] + 1;
                    ans = max(ans, a[i][j], b[i][j], c[i][j], d[i][j]);
                }
            }
        }
        return ans;
    }

    private int max(int... arr) {
        int ans = 0;
        for (int v : arr) {
            ans = Math.max(ans, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> a(m + 2, vector<int>(n + 2));
        vector<vector<int>> b(m + 2, vector<int>(n + 2));
        vector<vector<int>> c(m + 2, vector<int>(n + 2));
        vector<vector<int>> d(m + 2, vector<int>(n + 2));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mat[i - 1][j - 1]) {
                    a[i][j] = a[i - 1][j] + 1;
                    b[i][j] = b[i][j - 1] + 1;
                    c[i][j] = c[i - 1][j - 1] + 1;
                    d[i][j] = d[i - 1][j + 1] + 1;
                    ans = max(ans, max(a[i][j], max(b[i][j], max(c[i][j], d[i][j]))));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestLine(mat [][]int) (ans int) {
	m, n := len(mat), len(mat[0])
	f := make([][][4]int, m+2)
	for i := range f {
		f[i] = make([][4]int, n+2)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if mat[i-1][j-1] == 1 {
				f[i][j][0] = f[i-1][j][0] + 1
				f[i][j][1] = f[i][j-1][1] + 1
				f[i][j][2] = f[i-1][j-1][2] + 1
				f[i][j][3] = f[i-1][j+1][3] + 1
				for _, v := range f[i][j] {
					if ans < v {
						ans = v
					}
				}
			}
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

# [563. 二叉树的坡度](https://leetcode.cn/problems/binary-tree-tilt){#563}

{{< tabs "563" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            nonlocal ans
            ans += abs(l - r)
            return l + r + root.val

        ans = 0
        dfs(root)
        return ans
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
    private int ans;

    public int findTilt(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left), r = dfs(root.right);
        ans += Math.abs(l - r);
        return l + r + root.val;
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
    int findTilt(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left), r = dfs(root->right);
            ans += abs(l - r);
            return l + r + root->val;
        };
        dfs(root);
        return ans;
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
func findTilt(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ans += abs(l - r)
		return l + r + root.Val
	}
	dfs(root)
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
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

function findTilt(root: TreeNode | null): number {
    let ans: number = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const [l, r] = [dfs(root.left), dfs(root.right)];
        ans += Math.abs(l - r);
        return l + r + root.val;
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉树的根节点 <code>root</code> ，计算并返回 <strong>整个树 </strong>的坡度 。</p>

<p>一个树的<strong> 节点的坡度 </strong>定义即为，该节点左子树的节点之和和右子树节点之和的 <strong>差的绝对值 </strong>。如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。</p>

<p><strong>整个树</strong> 的坡度就是其所有节点的坡度之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0563.Binary%20Tree%20Tilt/images/tilt1.jpg" style="width: 712px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [1,2,3]
<strong>输出：</strong>1
<strong>解释：</strong>
节点 2 的坡度：|0-0| = 0（没有子节点）
节点 3 的坡度：|0-0| = 0（没有子节点）
节点 1 的坡度：|2-3| = 1（左子树就是左子节点，所以和是 2 ；右子树就是右子节点，所以和是 3 ）
坡度总和：0 + 0 + 1 = 1
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0563.Binary%20Tree%20Tilt/images/tilt2.jpg" style="width: 800px; height: 203px;" />
<pre>
<strong>输入：</strong>root = [4,2,9,3,5,null,7]
<strong>输出：</strong>15
<strong>解释：</strong>
节点 3 的坡度：|0-0| = 0（没有子节点）
节点 5 的坡度：|0-0| = 0（没有子节点）
节点 7 的坡度：|0-0| = 0（没有子节点）
节点 2 的坡度：|3-5| = 2（左子树就是左子节点，所以和是 3 ；右子树就是右子节点，所以和是 5 ）
节点 9 的坡度：|0-7| = 7（没有左子树，所以和是 0 ；右子树正好是右子节点，所以和是 7 ）
节点 4 的坡度：|(3+5+2)-(9+7)| = |10-16| = 6（左子树值为 3、5 和 2 ，和是 10 ；右子树值为 9 和 7 ，和是 16 ）
坡度总和：0 + 0 + 0 + 2 + 7 + 6 = 15
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0563.Binary%20Tree%20Tilt/images/tilt3.jpg" style="width: 800px; height: 293px;" />
<pre>
<strong>输入：</strong>root = [21,7,14,1,1,2,2,3,3]
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目的范围在 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们设计一个函数 $\text{dfs}$，用来计算以当前节点为根节点的子树的节点之和。在 $\text{dfs}$ 函数中，我们首先判断当前节点是否为空，若为空则返回 0。然后递归调用 $\text{dfs}$ 函数计算左子树的节点之和 $l$ 和右子树的节点之和 $r$。接着计算当前节点的坡度，即 $|l - r|$，并将其加到答案中。最后返回当前节点的节点之和 $l + r + \textit{root.val}$。

在主函数中，我们初始化答案为 0，然后调用 $\text{dfs}$ 函数计算整个树的坡度，并返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点的数量。

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
    def findTilt(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            nonlocal ans
            ans += abs(l - r)
            return l + r + root.val

        ans = 0
        dfs(root)
        return ans
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
    private int ans;

    public int findTilt(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left), r = dfs(root.right);
        ans += Math.abs(l - r);
        return l + r + root.val;
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
    int findTilt(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left), r = dfs(root->right);
            ans += abs(l - r);
            return l + r + root->val;
        };
        dfs(root);
        return ans;
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
func findTilt(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ans += abs(l - r)
		return l + r + root.Val
	}
	dfs(root)
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
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

function findTilt(root: TreeNode | null): number {
    let ans: number = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const [l, r] = [dfs(root.left), dfs(root.right)];
        ans += Math.abs(l - r);
        return l + r + root.val;
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [564. 寻找最近的回文数](https://leetcode.cn/problems/find-the-closest-palindrome){#564}

{{< tabs "564" >}}

{{% tab "python" %}}
```python
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        x = int(n)
        l = len(n)
        res = {10 ** (l - 1) - 1, 10**l + 1}
        left = int(n[: (l + 1) >> 1])
        for i in range(left - 1, left + 2):
            j = i if l % 2 == 0 else i // 10
            while j:
                i = i * 10 + j % 10
                j //= 10
            res.add(i)
        res.discard(x)

        ans = -1
        for t in res:
            if (
                ans == -1
                or abs(t - x) < abs(ans - x)
                or (abs(t - x) == abs(ans - x) and t < ans)
            ):
                ans = t
        return str(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String nearestPalindromic(String n) {
        long x = Long.parseLong(n);
        long ans = -1;
        for (long t : get(n)) {
            if (ans == -1 || Math.abs(t - x) < Math.abs(ans - x)
                || (Math.abs(t - x) == Math.abs(ans - x) && t < ans)) {
                ans = t;
            }
        }
        return Long.toString(ans);
    }

    private Set<Long> get(String n) {
        int l = n.length();
        Set<Long> res = new HashSet<>();
        res.add((long) Math.pow(10, l - 1) - 1);
        res.add((long) Math.pow(10, l) + 1);
        long left = Long.parseLong(n.substring(0, (l + 1) / 2));
        for (long i = left - 1; i <= left + 1; ++i) {
            StringBuilder sb = new StringBuilder();
            sb.append(i);
            sb.append(new StringBuilder(i + "").reverse().substring(l & 1));
            res.add(Long.parseLong(sb.toString()));
        }
        res.remove(Long.parseLong(n));
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string nearestPalindromic(string n) {
        long x = stol(n);
        long ans = -1;
        for (long t : get(n))
            if (ans == -1 || abs(t - x) < abs(ans - x) || (abs(t - x) == abs(ans - x) && t < ans))
                ans = t;
        return to_string(ans);
    }

    unordered_set<long> get(string& n) {
        int l = n.size();
        unordered_set<long> res;
        res.insert((long) pow(10, l - 1) - 1);
        res.insert((long) pow(10, l) + 1);
        long left = stol(n.substr(0, (l + 1) / 2));
        for (long i = left - 1; i <= left + 1; ++i) {
            string prefix = to_string(i);
            string t = prefix + string(prefix.rbegin() + (l & 1), prefix.rend());
            res.insert(stol(t));
        }
        res.erase(stol(n));
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nearestPalindromic(n string) string {
	l := len(n)
	res := []int{int(math.Pow10(l-1)) - 1, int(math.Pow10(l)) + 1}
	left, _ := strconv.Atoi(n[:(l+1)/2])
	for _, x := range []int{left - 1, left, left + 1} {
		y := x
		if l&1 == 1 {
			y /= 10
		}
		for ; y > 0; y /= 10 {
			x = x*10 + y%10
		}
		res = append(res, x)
	}
	ans := -1
	x, _ := strconv.Atoi(n)
	for _, t := range res {
		if t != x {
			if ans == -1 || abs(t-x) < abs(ans-x) || abs(t-x) == abs(ans-x) && t < ans {
				ans = t
			}
		}
	}
	return strconv.Itoa(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} n
 * @return {string}
 */

function nearestPalindromic(n) {
    const x = BigInt(n);
    let ans = null;

    for (const t of getCandidates(n)) {
        if (
            ans === null ||
            absDiff(t, x) < absDiff(ans, x) ||
            (absDiff(t, x) === absDiff(ans, x) && t < ans)
        ) {
            ans = t;
        }
    }

    return ans.toString();
}

function getCandidates(n) {
    const length = n.length;
    const res = new Set();

    res.add(BigInt(Math.pow(10, length - 1) - 1));
    res.add(BigInt(Math.pow(10, length) + 1));

    const left = BigInt(n.substring(0, Math.ceil(length / 2)));

    for (let i = left - 1n; i <= left + 1n; i++) {
        const prefix = i.toString();
        const t =
            prefix +
            prefix
                .split('')
                .reverse()
                .slice(length % 2)
                .join('');
        res.add(BigInt(t));
    }

    res.delete(BigInt(n));
    return res;
}

function absDiff(a, b) {
    return a > b ? a - b : b - a;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表示整数的字符串&nbsp;<code>n</code> ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。</p>

<p>“最近的”定义为两个整数<strong>差的绝对值</strong>最小。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = "123"
<strong>输出:</strong> "121"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = "1"
<strong>输出:</strong> "0"
<strong>解释:</strong> 0 和 2是最近的回文，但我们返回最小的，也就是 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 18</code></li>
	<li><code>n</code>&nbsp;只由数字组成</li>
	<li><code>n</code>&nbsp;不含前导 0</li>
	<li><code>n</code>&nbsp;代表在&nbsp;<code>[1, 10<sup>18</sup>&nbsp;- 1]</code> 范围内的整数</li>
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
    def nearestPalindromic(self, n: str) -> str:
        x = int(n)
        l = len(n)
        res = {10 ** (l - 1) - 1, 10**l + 1}
        left = int(n[: (l + 1) >> 1])
        for i in range(left - 1, left + 2):
            j = i if l % 2 == 0 else i // 10
            while j:
                i = i * 10 + j % 10
                j //= 10
            res.add(i)
        res.discard(x)

        ans = -1
        for t in res:
            if (
                ans == -1
                or abs(t - x) < abs(ans - x)
                or (abs(t - x) == abs(ans - x) and t < ans)
            ):
                ans = t
        return str(ans)
```

#### Java

```java
class Solution {
    public String nearestPalindromic(String n) {
        long x = Long.parseLong(n);
        long ans = -1;
        for (long t : get(n)) {
            if (ans == -1 || Math.abs(t - x) < Math.abs(ans - x)
                || (Math.abs(t - x) == Math.abs(ans - x) && t < ans)) {
                ans = t;
            }
        }
        return Long.toString(ans);
    }

    private Set<Long> get(String n) {
        int l = n.length();
        Set<Long> res = new HashSet<>();
        res.add((long) Math.pow(10, l - 1) - 1);
        res.add((long) Math.pow(10, l) + 1);
        long left = Long.parseLong(n.substring(0, (l + 1) / 2));
        for (long i = left - 1; i <= left + 1; ++i) {
            StringBuilder sb = new StringBuilder();
            sb.append(i);
            sb.append(new StringBuilder(i + "").reverse().substring(l & 1));
            res.add(Long.parseLong(sb.toString()));
        }
        res.remove(Long.parseLong(n));
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string nearestPalindromic(string n) {
        long x = stol(n);
        long ans = -1;
        for (long t : get(n))
            if (ans == -1 || abs(t - x) < abs(ans - x) || (abs(t - x) == abs(ans - x) && t < ans))
                ans = t;
        return to_string(ans);
    }

    unordered_set<long> get(string& n) {
        int l = n.size();
        unordered_set<long> res;
        res.insert((long) pow(10, l - 1) - 1);
        res.insert((long) pow(10, l) + 1);
        long left = stol(n.substr(0, (l + 1) / 2));
        for (long i = left - 1; i <= left + 1; ++i) {
            string prefix = to_string(i);
            string t = prefix + string(prefix.rbegin() + (l & 1), prefix.rend());
            res.insert(stol(t));
        }
        res.erase(stol(n));
        return res;
    }
};
```

#### Go

```go
func nearestPalindromic(n string) string {
	l := len(n)
	res := []int{int(math.Pow10(l-1)) - 1, int(math.Pow10(l)) + 1}
	left, _ := strconv.Atoi(n[:(l+1)/2])
	for _, x := range []int{left - 1, left, left + 1} {
		y := x
		if l&1 == 1 {
			y /= 10
		}
		for ; y > 0; y /= 10 {
			x = x*10 + y%10
		}
		res = append(res, x)
	}
	ans := -1
	x, _ := strconv.Atoi(n)
	for _, t := range res {
		if t != x {
			if ans == -1 || abs(t-x) < abs(ans-x) || abs(t-x) == abs(ans-x) && t < ans {
				ans = t
			}
		}
	}
	return strconv.Itoa(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### JavaScript

```js
/**
 * @param {string} n
 * @return {string}
 */

function nearestPalindromic(n) {
    const x = BigInt(n);
    let ans = null;

    for (const t of getCandidates(n)) {
        if (
            ans === null ||
            absDiff(t, x) < absDiff(ans, x) ||
            (absDiff(t, x) === absDiff(ans, x) && t < ans)
        ) {
            ans = t;
        }
    }

    return ans.toString();
}

function getCandidates(n) {
    const length = n.length;
    const res = new Set();

    res.add(BigInt(Math.pow(10, length - 1) - 1));
    res.add(BigInt(Math.pow(10, length) + 1));

    const left = BigInt(n.substring(0, Math.ceil(length / 2)));

    for (let i = left - 1n; i <= left + 1n; i++) {
        const prefix = i.toString();
        const t =
            prefix +
            prefix
                .split('')
                .reverse()
                .slice(length % 2)
                .join('');
        res.add(BigInt(t));
    }

    res.delete(BigInt(n));
    return res;
}

function absDiff(a, b) {
    return a > b ? a - b : b - a;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [565. 数组嵌套](https://leetcode.cn/problems/array-nesting){#565}

{{< tabs "565" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            cnt = 0
            while nums[i] != n:
                j = nums[i]
                nums[i] = n
                i = j
                cnt += 1
            ans = max(ans, cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int arrayNesting(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int j = i;
            while (nums[j] < n) {
                int k = nums[j];
                nums[j] = n;
                j = k;
                ++cnt;
            }
            ans = Math.max(ans, cnt);
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
    int arrayNesting(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int j = i;
            while (nums[j] < n) {
                int k = nums[j];
                nums[j] = n;
                j = k;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrayNesting(nums []int) int {
	ans, n := 0, len(nums)
	for i := range nums {
		cnt, j := 0, i
		for nums[j] != n {
			k := nums[j]
			nums[j] = n
			j = k
			cnt++
		}
		if ans < cnt {
			ans = cnt
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

<p>索引从<code>0</code>开始长度为<code>N</code>的数组<code>A</code>，包含<code>0</code>到<code>N - 1</code>的所有整数。找到最大的集合<code>S</code>并返回其大小，其中 <code>S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }</code>且遵守以下的规则。</p>

<p>假设选择索引为<code>i</code>的元素<code>A[i]</code>为<code>S</code>的第一个元素，<code>S</code>的下一个元素应该是<code>A[A[i]]</code>，之后是<code>A[A[A[i]]]...</code> 以此类推，不断添加直到<code>S</code>出现重复的元素。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> A = [5,4,0,3,1,6,2]
<strong>输出:</strong> 4
<strong>解释:</strong> 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
	<li><code>A</code>中不含有重复的元素。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：图

嵌套数组最终一定会形成一个环，在枚举 $nums[i]$ 的过程中，可以用 $vis$ 数组剪枝，避免重复枚举同一个环。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        n = len(nums)
        vis = [False] * n
        res = 0
        for i in range(n):
            if vis[i]:
                continue
            cur, m = nums[i], 1
            vis[cur] = True
            while nums[cur] != nums[i]:
                cur = nums[cur]
                m += 1
                vis[cur] = True
            res = max(res, m)
        return res
```

#### Java

```java
class Solution {
    public int arrayNesting(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            int cur = nums[i], m = 1;
            vis[cur] = true;
            while (nums[cur] != nums[i]) {
                cur = nums[cur];
                m++;
                vis[cur] = true;
            }
            res = Math.max(res, m);
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int cur = nums[i], m = 1;
            vis[cur] = true;
            while (nums[cur] != nums[i]) {
                cur = nums[cur];
                ++m;
                vis[cur] = true;
            }
            res = max(res, m);
        }
        return res;
    }
};
```

#### Go

```go
func arrayNesting(nums []int) int {
	n := len(nums)
	vis := make([]bool, n)
	ans := 0
	for i := 0; i < n; i++ {
		if vis[i] {
			continue
		}
		cur, m := nums[i], 1
		vis[cur] = true
		for nums[cur] != nums[i] {
			cur = nums[cur]
			m++
			vis[cur] = true
		}
		if m > ans {
			ans = m
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：原地标记

由于 $nums$ 元素均在 $[0..n-1]$ 之间，因此，对于访问过的元素，我们可以令 $nums[i]=n$，从而省略 $vis$ 数组。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            cnt = 0
            while nums[i] != n:
                j = nums[i]
                nums[i] = n
                i = j
                cnt += 1
            ans = max(ans, cnt)
        return ans
```

#### Java

```java
class Solution {
    public int arrayNesting(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int j = i;
            while (nums[j] < n) {
                int k = nums[j];
                nums[j] = n;
                j = k;
                ++cnt;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int j = i;
            while (nums[j] < n) {
                int k = nums[j];
                nums[j] = n;
                j = k;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func arrayNesting(nums []int) int {
	ans, n := 0, len(nums)
	for i := range nums {
		cnt, j := 0, i
		for nums[j] != n {
			k := nums[j]
			nums[j] = n
			j = k
			cnt++
		}
		if ans < cnt {
			ans = cnt
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

# [566. 重塑矩阵](https://leetcode.cn/problems/reshape-the-matrix){#566}

{{< tabs "566" >}}

{{% tab "python" %}}
```python
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        if m * n != r * c:
            return mat
        ans = [[0] * c for _ in range(r)]
        for i in range(m * n):
            ans[i // c][i % c] = mat[i // n][i % n]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length, n = mat[0].length;
        if (m * n != r * c) {
            return mat;
        }
        int[][] ans = new int[r][c];
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matrixReshape(mat [][]int, r int, c int) [][]int {
	m, n := len(mat), len(mat[0])
	if m*n != r*c {
		return mat
	}
	ans := make([][]int, r)
	for i := range ans {
		ans[i] = make([]int, c)
	}
	for i := 0; i < m*n; i++ {
		ans[i/c][i%c] = mat[i/n][i%n]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function matrixReshape(mat: number[][], r: number, c: number): number[][] {
    const m = mat.length;
    const n = mat[0].length;
    if (m * n !== r * c) {
        return mat;
    }
    const ans = Array.from({ length: r }, () => new Array(c).fill(0));
    for (let i = 0; i < r * c; i++) {
        ans[Math.floor(i / c)][i % c] = mat[Math.floor(i / n)][i % n];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let r = r as usize;
        let c = c as usize;
        let m = mat.len();
        let n = mat[0].len();
        if m * n != r * c {
            return mat;
        }
        let mut i = 0;
        let mut j = 0;
        (0..r)
            .into_iter()
            .map(|_| {
                (0..c)
                    .into_iter()
                    .map(|_| {
                        let res = mat[i][j];
                        j += 1;
                        if j == n {
                            j = 0;
                            i += 1;
                        }
                        res
                    })
                    .collect()
            })
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (matSize * matColSize[0] != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    *returnSize = r;
    *returnColumnSizes = malloc(sizeof(int) * r);
    int** ans = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        ans[i] = malloc(sizeof(int) * c);
    }
    for (int i = 0; i < r * c; i++) {
        ans[i / c][i % c] = mat[i / matColSize[0]][i % matColSize[0]];
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

<p>在 MATLAB 中，有一个非常有用的函数 <code>reshape</code> ，它可以将一个&nbsp;<code>m x n</code> 矩阵重塑为另一个大小不同（<code>r x c</code>）的新矩阵，但保留其原始数据。</p>

<p>给你一个由二维数组 <code>mat</code> 表示的&nbsp;<code>m x n</code> 矩阵，以及两个正整数 <code>r</code> 和 <code>c</code> ，分别表示想要的重构的矩阵的行数和列数。</p>

<p>重构后的矩阵需要将原始矩阵的所有元素以相同的<strong> 行遍历顺序 </strong>填充。</p>

<p>如果具有给定参数的 <code>reshape</code> 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0566.Reshape%20the%20Matrix/images/reshape1-grid.jpg" style="width: 613px; height: 173px;" />
<pre>
<strong>输入：</strong>mat = [[1,2],[3,4]], r = 1, c = 4
<strong>输出：</strong>[[1,2,3,4]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0566.Reshape%20the%20Matrix/images/reshape2-grid.jpg" style="width: 453px; height: 173px;" />
<pre>
<strong>输入：</strong>mat = [[1,2],[3,4]], r = 2, c = 4
<strong>输出：</strong>[[1,2],[3,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-1000 &lt;= mat[i][j] &lt;= 1000</code></li>
	<li><code>1 &lt;= r, c &lt;= 300</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先获取原矩阵的行数和列数，分别记为 $m$ 和 $n$。如果 $m \times n \neq r \times c$，则无法重塑矩阵，直接返回原矩阵。

否则，我们创建一个新矩阵，新矩阵的行数为 $r$，列数为 $c$。我们从原矩阵的第一个元素开始，按照行优先的顺序遍历原矩阵的所有元素，将遍历到的元素按顺序放入新矩阵中。

遍历完原矩阵的所有元素后，我们即可得到答案。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是原矩阵的行数和列数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        if m * n != r * c:
            return mat
        ans = [[0] * c for _ in range(r)]
        for i in range(m * n):
            ans[i // c][i % c] = mat[i // n][i % n]
        return ans
```

#### Java

```java
class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length, n = mat[0].length;
        if (m * n != r * c) {
            return mat;
        }
        int[][] ans = new int[r][c];
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m * n; ++i) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};
```

#### Go

```go
func matrixReshape(mat [][]int, r int, c int) [][]int {
	m, n := len(mat), len(mat[0])
	if m*n != r*c {
		return mat
	}
	ans := make([][]int, r)
	for i := range ans {
		ans[i] = make([]int, c)
	}
	for i := 0; i < m*n; i++ {
		ans[i/c][i%c] = mat[i/n][i%n]
	}
	return ans
}
```

#### TypeScript

```ts
function matrixReshape(mat: number[][], r: number, c: number): number[][] {
    let m = mat.length,
        n = mat[0].length;
    if (m * n != r * c) return mat;
    let ans = Array.from({ length: r }, v => new Array(c).fill(0));
    let k = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans[Math.floor(k / c)][k % c] = mat[i][j];
            ++k;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let r = r as usize;
        let c = c as usize;
        let m = mat.len();
        let n = mat[0].len();
        if m * n != r * c {
            return mat;
        }
        let mut i = 0;
        let mut j = 0;
        (0..r)
            .into_iter()
            .map(|_| {
                (0..c)
                    .into_iter()
                    .map(|_| {
                        let res = mat[i][j];
                        j += 1;
                        if j == n {
                            j = 0;
                            i += 1;
                        }
                        res
                    })
                    .collect()
            })
            .collect()
    }
}
```

#### C

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (matSize * matColSize[0] != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    *returnSize = r;
    *returnColumnSizes = malloc(sizeof(int) * r);
    int** ans = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        ans[i] = malloc(sizeof(int) * c);
    }
    for (int i = 0; i < r * c; i++) {
        ans[i / c][i % c] = mat[i / matColSize[0]][i % matColSize[0]];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function matrixReshape(mat: number[][], r: number, c: number): number[][] {
    const m = mat.length;
    const n = mat[0].length;
    if (m * n !== r * c) {
        return mat;
    }
    const ans = Array.from({ length: r }, () => new Array(c).fill(0));
    for (let i = 0; i < r * c; i++) {
        ans[Math.floor(i / c)][i % c] = mat[Math.floor(i / n)][i % n];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string){#567}

{{< tabs "567" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cnt = Counter(s1)
        need = len(cnt)
        m = len(s1)
        for i, c in enumerate(s2):
            cnt[c] -= 1
            if cnt[c] == 0:
                need -= 1
            if i >= m:
                cnt[s2[i - m]] += 1
                if cnt[s2[i - m]] == 1:
                    need += 1
            if need == 0:
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int need = 0;
        int[] cnt = new int[26];
        for (char c : s1.toCharArray()) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        int m = s1.length(), n = s2.length();
        for (int i = 0; i < n; ++i) {
            int c = s2.charAt(i) - 'a';
            if (--cnt[c] == 0) {
                --need;
            }
            if (i >= m) {
                c = s2.charAt(i - m) - 'a';
                if (++cnt[c] == 1) {
                    ++need;
                }
            }
            if (need == 0) {
                return true;
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
    bool checkInclusion(string s1, string s2) {
        int need = 0;
        int cnt[26]{};
        for (char c : s1) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        int m = s1.size(), n = s2.size();
        for (int i = 0; i < n; ++i) {
            int c = s2[i] - 'a';
            if (--cnt[c] == 0) {
                --need;
            }
            if (i >= m) {
                c = s2[i - m] - 'a';
                if (++cnt[c] == 1) {
                    ++need;
                }
            }
            if (need == 0) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkInclusion(s1 string, s2 string) bool {
	need := 0
	cnt := [26]int{}

	for _, c := range s1 {
		if cnt[c-'a']++; cnt[c-'a'] == 1 {
			need++
		}
	}

	m, n := len(s1), len(s2)
	for i := 0; i < n; i++ {
		c := s2[i] - 'a'
		if cnt[c]--; cnt[c] == 0 {
			need--
		}
		if i >= m {
			c = s2[i-m] - 'a'
			if cnt[c]++; cnt[c] == 1 {
				need++
			}
		}
		if need == 0 {
			return true
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkInclusion(s1: string, s2: string): boolean {
    let need = 0;
    const cnt: number[] = Array(26).fill(0);
    const a = 'a'.charCodeAt(0);
    for (const c of s1) {
        if (++cnt[c.charCodeAt(0) - a] === 1) {
            need++;
        }
    }

    const [m, n] = [s1.length, s2.length];
    for (let i = 0; i < n; i++) {
        let c = s2.charCodeAt(i) - a;
        if (--cnt[c] === 0) {
            need--;
        }
        if (i >= m) {
            c = s2.charCodeAt(i - m) - a;
            if (++cnt[c] === 1) {
                need++;
            }
        }
        if (need === 0) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let mut need = 0;
        let mut cnt = vec![0; 26];

        for c in s1.chars() {
            let index = (c as u8 - b'a') as usize;
            if cnt[index] == 0 {
                need += 1;
            }
            cnt[index] += 1;
        }

        let m = s1.len();
        let n = s2.len();
        let s2_bytes = s2.as_bytes();

        for i in 0..n {
            let c = (s2_bytes[i] - b'a') as usize;
            cnt[c] -= 1;
            if cnt[c] == 0 {
                need -= 1;
            }

            if i >= m {
                let c = (s2_bytes[i - m] - b'a') as usize;
                cnt[c] += 1;
                if cnt[c] == 1 {
                    need += 1;
                }
            }

            if need == 0 {
                return true;
            }
        }

        false
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        int need = 0;
        int[] cnt = new int[26];

        foreach (char c in s1) {
            if (++cnt[c - 'a'] == 1) {
                need++;
            }
        }

        int m = s1.Length, n = s2.Length;
        for (int i = 0; i < n; i++) {
            int c = s2[i] - 'a';
            if (--cnt[c] == 0) {
                need--;
            }

            if (i >= m) {
                c = s2[i - m] - 'a';
                if (++cnt[c] == 1) {
                    need++;
                }
            }

            if (need == 0) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function checkInclusion($s1, $s2) {
        $need = 0;
        $cnt = array_fill(0, 26, 0);

        for ($i = 0; $i < strlen($s1); $i++) {
            $index = ord($s1[$i]) - ord('a');
            if (++$cnt[$index] == 1) {
                $need++;
            }
        }

        $m = strlen($s1);
        $n = strlen($s2);

        for ($i = 0; $i < $n; $i++) {
            $c = ord($s2[$i]) - ord('a');
            if (--$cnt[$c] == 0) {
                $need--;
            }

            if ($i >= $m) {
                $c = ord($s2[$i - $m]) - ord('a');
                if (++$cnt[$c] == 1) {
                    $need++;
                }
            }

            if ($need == 0) {
                return true;
            }
        }

        return false;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code> ，写一个函数来判断 <code>s2</code> 是否包含 <code>s1</code><strong>&nbsp;</strong>的 <span data-keyword="permutation-string">排列</span>。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>换句话说，<code>s1</code> 的排列之一是 <code>s2</code> 的 <strong>子串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "ab" s2 = "eidbaooo"
<strong>输出：</strong>true
<strong>解释：</strong>s2 包含 s1 的排列之一 ("ba").
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1= "ab" s2 = "eidboaoo"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> 和 <code>s2</code> 仅包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们用一个数组 $\textit{cnt}$ 记录当前需要匹配的字符及其个数，用一个变量 $\textit{need}$ 记录当前还需要匹配的字符种类数，初始时 $\textit{cnt}$ 为字符串 $\textit{s1}$ 中各字符出现次数，而 $\textit{need}$ 为 $\textit{s1}$ 中不同字符的个数。

然后我们遍历字符串 $\textit{s2}$，对于每个字符，我们将其在 $\textit{cnt}$ 中的对应值减一，如果减一后的值等于 $0$，说明当前字符在 $\textit{s1}$ 中出现次数已经满足要求，我们将 $\textit{need}$ 减一。如果当前下标 $i$ 大于等于 $\textit{s1}$ 的长度，我们需要将 $\textit{s2}[i-\textit{s1}]\textit{cnt}$ 中对应值加一，如果加一后的值等于 $1$，说明当前字符在 $\textit{s1}$ 中出现次数不再满足要求，我们将 $\textit{need}$ 加一。在遍历过程中，如果 $\textit{need}$ 的值等于 $0$，说明所有字符的出现次数都满足要求，我们就找到了一个满足要求的子串，返回 $\text{true}$。

否则，如果遍历结束后没有找到满足要求的子串，我们返回 $\text{false}$。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是字符串 $\textit{s1}$ 和 $\textit{s2}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，这道题中字符集为小写字母，所以空间复杂度是常数级别的。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cnt = Counter(s1)
        need = len(cnt)
        m = len(s1)
        for i, c in enumerate(s2):
            cnt[c] -= 1
            if cnt[c] == 0:
                need -= 1
            if i >= m:
                cnt[s2[i - m]] += 1
                if cnt[s2[i - m]] == 1:
                    need += 1
            if need == 0:
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int need = 0;
        int[] cnt = new int[26];
        for (char c : s1.toCharArray()) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        int m = s1.length(), n = s2.length();
        for (int i = 0; i < n; ++i) {
            int c = s2.charAt(i) - 'a';
            if (--cnt[c] == 0) {
                --need;
            }
            if (i >= m) {
                c = s2.charAt(i - m) - 'a';
                if (++cnt[c] == 1) {
                    ++need;
                }
            }
            if (need == 0) {
                return true;
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
    bool checkInclusion(string s1, string s2) {
        int need = 0;
        int cnt[26]{};
        for (char c : s1) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        int m = s1.size(), n = s2.size();
        for (int i = 0; i < n; ++i) {
            int c = s2[i] - 'a';
            if (--cnt[c] == 0) {
                --need;
            }
            if (i >= m) {
                c = s2[i - m] - 'a';
                if (++cnt[c] == 1) {
                    ++need;
                }
            }
            if (need == 0) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func checkInclusion(s1 string, s2 string) bool {
	need := 0
	cnt := [26]int{}

	for _, c := range s1 {
		if cnt[c-'a']++; cnt[c-'a'] == 1 {
			need++
		}
	}

	m, n := len(s1), len(s2)
	for i := 0; i < n; i++ {
		c := s2[i] - 'a'
		if cnt[c]--; cnt[c] == 0 {
			need--
		}
		if i >= m {
			c = s2[i-m] - 'a'
			if cnt[c]++; cnt[c] == 1 {
				need++
			}
		}
		if need == 0 {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function checkInclusion(s1: string, s2: string): boolean {
    let need = 0;
    const cnt: number[] = Array(26).fill(0);
    const a = 'a'.charCodeAt(0);
    for (const c of s1) {
        if (++cnt[c.charCodeAt(0) - a] === 1) {
            need++;
        }
    }

    const [m, n] = [s1.length, s2.length];
    for (let i = 0; i < n; i++) {
        let c = s2.charCodeAt(i) - a;
        if (--cnt[c] === 0) {
            need--;
        }
        if (i >= m) {
            c = s2.charCodeAt(i - m) - a;
            if (++cnt[c] === 1) {
                need++;
            }
        }
        if (need === 0) {
            return true;
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let mut need = 0;
        let mut cnt = vec![0; 26];

        for c in s1.chars() {
            let index = (c as u8 - b'a') as usize;
            if cnt[index] == 0 {
                need += 1;
            }
            cnt[index] += 1;
        }

        let m = s1.len();
        let n = s2.len();
        let s2_bytes = s2.as_bytes();

        for i in 0..n {
            let c = (s2_bytes[i] - b'a') as usize;
            cnt[c] -= 1;
            if cnt[c] == 0 {
                need -= 1;
            }

            if i >= m {
                let c = (s2_bytes[i - m] - b'a') as usize;
                cnt[c] += 1;
                if cnt[c] == 1 {
                    need += 1;
                }
            }

            if need == 0 {
                return true;
            }
        }

        false
    }
}
```

#### C#

```cs
public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        int need = 0;
        int[] cnt = new int[26];

        foreach (char c in s1) {
            if (++cnt[c - 'a'] == 1) {
                need++;
            }
        }

        int m = s1.Length, n = s2.Length;
        for (int i = 0; i < n; i++) {
            int c = s2[i] - 'a';
            if (--cnt[c] == 0) {
                need--;
            }

            if (i >= m) {
                c = s2[i - m] - 'a';
                if (++cnt[c] == 1) {
                    need++;
                }
            }

            if (need == 0) {
                return true;
            }
        }
        return false;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function checkInclusion($s1, $s2) {
        $need = 0;
        $cnt = array_fill(0, 26, 0);

        for ($i = 0; $i < strlen($s1); $i++) {
            $index = ord($s1[$i]) - ord('a');
            if (++$cnt[$index] == 1) {
                $need++;
            }
        }

        $m = strlen($s1);
        $n = strlen($s2);

        for ($i = 0; $i < $n; $i++) {
            $c = ord($s2[$i]) - ord('a');
            if (--$cnt[$c] == 0) {
                $need--;
            }

            if ($i >= $m) {
                $c = ord($s2[$i - $m]) - ord('a');
                if (++$cnt[$c] == 1) {
                    $need++;
                }
            }

            if ($need == 0) {
                return true;
            }
        }

        return false;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [568. 最大休假天数 🔒](https://leetcode.cn/problems/maximum-vacation-days){#568}

{{< tabs "568" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        n = len(flights)
        K = len(days[0])
        f = [[-inf] * n for _ in range(K + 1)]
        f[0][0] = 0
        for k in range(1, K + 1):
            for j in range(n):
                f[k][j] = f[k - 1][j]
                for i in range(n):
                    if flights[i][j]:
                        f[k][j] = max(f[k][j], f[k - 1][i])
                f[k][j] += days[j][k - 1]
        return max(f[-1][j] for j in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int n = flights.length;
        int K = days[0].length;
        final int inf = 1 << 30;
        int[][] f = new int[K + 1][n];
        for (var g : f) {
            Arrays.fill(g, -inf);
        }
        f[0][0] = 0;
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < n; ++j) {
                f[k][j] = f[k - 1][j];
                for (int i = 0; i < n; ++i) {
                    if (flights[i][j] == 1) {
                        f[k][j] = Math.max(f[k][j], f[k - 1][i]);
                    }
                }
                f[k][j] += days[j][k - 1];
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = Math.max(ans, f[K][j]);
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
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int K = days[0].size();
        int f[K + 1][n];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < n; ++j) {
                f[k][j] = f[k - 1][j];
                for (int i = 0; i < n; ++i) {
                    if (flights[i][j] == 1) {
                        f[k][j] = max(f[k][j], f[k - 1][i]);
                    }
                }
                f[k][j] += days[j][k - 1];
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, f[K][j]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxVacationDays(flights [][]int, days [][]int) (ans int) {
	n, K := len(flights), len(days[0])
	f := make([][]int, K+1)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	f[0][0] = 0
	for k := 1; k <= K; k++ {
		for j := 0; j < n; j++ {
			f[k][j] = f[k-1][j]
			for i := 0; i < n; i++ {
				if flights[i][j] == 1 {
					f[k][j] = max(f[k][j], f[k-1][i])
				}
			}
			f[k][j] += days[j][k-1]
		}
	}
	for j := 0; j < n; j++ {
		ans = max(ans, f[K][j])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxVacationDays(flights: number[][], days: number[][]): number {
    const n = flights.length;
    const K = days[0].length;
    const inf = Number.NEGATIVE_INFINITY;
    const f: number[][] = Array.from({ length: K + 1 }, () => Array(n).fill(inf));
    f[0][0] = 0;
    for (let k = 1; k <= K; k++) {
        for (let j = 0; j < n; j++) {
            f[k][j] = f[k - 1][j];
            for (let i = 0; i < n; i++) {
                if (flights[i][j]) {
                    f[k][j] = Math.max(f[k][j], f[k - 1][i]);
                }
            }
            f[k][j] += days[j][k - 1];
        }
    }
    return Math.max(...f[K]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_vacation_days(flights: Vec<Vec<i32>>, days: Vec<Vec<i32>>) -> i32 {
        let n = flights.len();
        let k = days[0].len();
        let inf = i32::MIN;

        let mut f = vec![vec![inf; n]; k + 1];
        f[0][0] = 0;

        for step in 1..=k {
            for j in 0..n {
                f[step][j] = f[step - 1][j];
                for i in 0..n {
                    if flights[i][j] == 1 {
                        f[step][j] = f[step][j].max(f[step - 1][i]);
                    }
                }
                f[step][j] += days[j][step - 1];
            }
        }

        *f[k].iter().max().unwrap()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>力扣想让一个最优秀的员工在 <strong>N</strong> 个城市间旅行来收集算法问题。 但只工作不玩耍，聪明的孩子也会变傻，所以您可以在某些特定的城市和星期休假。您的工作就是安排旅行使得最大化你可以休假的天数，但是您需要遵守一些规则和限制。</p>

<p><strong>规则和限制：</strong></p>

<ol>
	<li>您只能在 <strong>N</strong> 个城市之间旅行，用 <code>0</code> 到 <code>n-1</code> 的索引表示。一开始，您在索引为 <code>0</code> 的城市，并且那天是<strong>星期一</strong>。</li>
	<li>这些城市通过航班相连。这些航班用&nbsp;<code>n x n</code>&nbsp;矩阵<strong> flights</strong>（不一定是对称的）表示，<strong>flights[i][j] </strong>代表城市 <code>i</code> 到城市 <code>j</code> 的航空状态。如果没有城市 <code>i</code> 到城市 <code>j</code> 的航班，<code>flights[i][j] = 0</code>&nbsp;；否则，<code>flights[i][j] = 1</code>&nbsp;。同时，对于所有的 <code>i</code> ，<code>flights[i][i] = 0</code>&nbsp;<strong>。</strong></li>
	<li>您总共有 <code>k</code>&nbsp;周（<strong>每周7天</strong>）的时间旅行。您<strong>每天</strong>最多只能乘坐一次航班，并且只能在每周的<strong>星期一</strong>上午乘坐航班。由于飞行时间很短，我们不考虑飞行时间的影响。</li>
	<li>对于每个城市，不同的星期您休假天数是不同的，给定一个 <strong>N*K</strong> 矩阵 <strong>days</strong> 代表这种限制，<strong>days[i][j] </strong>代表您在第j个星期在城市i能休假的最长天数。</li>
	<li>如果您从 <code>A</code> 市飞往 <code>B</code> 市，并在当天休假，扣除的假期天数将计入 <code>B</code> 市当周的休假天数。</li>
	<li>我们不考虑飞行时数对休假天数计算的影响。</li>
</ol>

<p>给定 <code>flights</code> 矩阵和 <code>days</code> 矩阵，您需要输出 <code>k</code>&nbsp;周内可以休假的最长天数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong>flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
<strong>输出:</strong> 12
<strong>解释:</strong> 
最好的策略之一：
第一个星期 : 星期一从城市 0 飞到城市 1，玩 6 天，工作 1 天。 
（虽然你是从城市 0 开始，但因为是星期一，我们也可以飞到其他城市。） 
第二个星期 : 星期一从城市 1 飞到城市 2，玩 3 天，工作 4 天。
第三个星期 : 呆在城市 2，玩 3 天，工作 4 天。
Ans = 6 + 3 + 3 = 12. 
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]
<strong>输出:</strong> 3
<strong>解释:</strong> 
由于没有航班可以让您飞到其他城市，你必须在城市 0 呆整整 3 个星期。 
对于每一个星期，你只有一天时间玩，剩下六天都要工作。 
所以最大休假天数为 3.
Ans = 1 + 1 + 1 = 3. 
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong>flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
<strong>输出:</strong> 21
<strong>解释:</strong>
最好的策略之一是：
第一个星期 : 呆在城市 0，玩 7 天。 
第二个星期 : 星期一从城市 0 飞到城市 1，玩 7 天。
第三个星期 : 星期一从城市 1 飞到城市 2，玩 7 天。
Ans = 7 + 7 + 7 = 21
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == flights.length</code></li>
	<li><code>n == flights[i].length</code></li>
	<li><code>n == days.length</code></li>
	<li><code>k == days[i].length</code></li>
	<li><code>1 &lt;= n, k &lt;= 100</code></li>
	<li><code>flights[i][j]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code></li>
	<li><code>0 &lt;= days[i] &lt;= 7</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[k][j]$ 表示前 $k$ 周，且最后一周在城市 $j$ 休假的最长天数。初始时 $f[0][0]=0$，其它 $f[0][j]=-\infty$。答案为 $\max_{j=0}^{n-1} f[K][j]$。

接下来，我们考虑如何计算 $f[k][j]$。对于当前这一周，我们可以枚举上一周所在的城市 $i$，城市 $i$ 可以和城市 $j$ 相等，那么 $f[k][j] = f[k-1][i]$；也可以和城市 $j$ 不相等，如果不相等，我们需要判断是否可以从城市 $i$ 飞到城市 $j$，如果可以，那么 $f[k][j] = \max(f[k][j], f[k-1][i])$。最后，我们还需要加上这一周在城市 $j$ 休假的天数 $\textit{days}[j][k-1]$。

最终的答案即为 $\max_{j=0}^{n-1} f[K][j]$。

时间复杂度 $O(K \times n^2)$，空间复杂度 $O(K \times n)$。其中 $K$ 和 $n$ 分别为周数和城市数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        n = len(flights)
        K = len(days[0])
        f = [[-inf] * n for _ in range(K + 1)]
        f[0][0] = 0
        for k in range(1, K + 1):
            for j in range(n):
                f[k][j] = f[k - 1][j]
                for i in range(n):
                    if flights[i][j]:
                        f[k][j] = max(f[k][j], f[k - 1][i])
                f[k][j] += days[j][k - 1]
        return max(f[-1][j] for j in range(n))
```

#### Java

```java
class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int n = flights.length;
        int K = days[0].length;
        final int inf = 1 << 30;
        int[][] f = new int[K + 1][n];
        for (var g : f) {
            Arrays.fill(g, -inf);
        }
        f[0][0] = 0;
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < n; ++j) {
                f[k][j] = f[k - 1][j];
                for (int i = 0; i < n; ++i) {
                    if (flights[i][j] == 1) {
                        f[k][j] = Math.max(f[k][j], f[k - 1][i]);
                    }
                }
                f[k][j] += days[j][k - 1];
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = Math.max(ans, f[K][j]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int K = days[0].size();
        int f[K + 1][n];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < n; ++j) {
                f[k][j] = f[k - 1][j];
                for (int i = 0; i < n; ++i) {
                    if (flights[i][j] == 1) {
                        f[k][j] = max(f[k][j], f[k - 1][i]);
                    }
                }
                f[k][j] += days[j][k - 1];
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, f[K][j]);
        }
        return ans;
    }
};
```

#### Go

```go
func maxVacationDays(flights [][]int, days [][]int) (ans int) {
	n, K := len(flights), len(days[0])
	f := make([][]int, K+1)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	f[0][0] = 0
	for k := 1; k <= K; k++ {
		for j := 0; j < n; j++ {
			f[k][j] = f[k-1][j]
			for i := 0; i < n; i++ {
				if flights[i][j] == 1 {
					f[k][j] = max(f[k][j], f[k-1][i])
				}
			}
			f[k][j] += days[j][k-1]
		}
	}
	for j := 0; j < n; j++ {
		ans = max(ans, f[K][j])
	}
	return
}
```

#### TypeScript

```ts
function maxVacationDays(flights: number[][], days: number[][]): number {
    const n = flights.length;
    const K = days[0].length;
    const inf = Number.NEGATIVE_INFINITY;
    const f: number[][] = Array.from({ length: K + 1 }, () => Array(n).fill(inf));
    f[0][0] = 0;
    for (let k = 1; k <= K; k++) {
        for (let j = 0; j < n; j++) {
            f[k][j] = f[k - 1][j];
            for (let i = 0; i < n; i++) {
                if (flights[i][j]) {
                    f[k][j] = Math.max(f[k][j], f[k - 1][i]);
                }
            }
            f[k][j] += days[j][k - 1];
        }
    }
    return Math.max(...f[K]);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_vacation_days(flights: Vec<Vec<i32>>, days: Vec<Vec<i32>>) -> i32 {
        let n = flights.len();
        let k = days[0].len();
        let inf = i32::MIN;

        let mut f = vec![vec![inf; n]; k + 1];
        f[0][0] = 0;

        for step in 1..=k {
            for j in 0..n {
                f[step][j] = f[step - 1][j];
                for i in 0..n {
                    if flights[i][j] == 1 {
                        f[step][j] = f[step][j].max(f[step - 1][i]);
                    }
                }
                f[step][j] += days[j][step - 1];
            }
        }

        *f[k].iter().max().unwrap()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [569. 员工薪水中位数 🔒](https://leetcode.cn/problems/median-employee-salary){#569}

{{< tabs "569" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY company
                ORDER BY salary ASC
            ) AS rk,
            COUNT(id) OVER (PARTITION BY company) AS n
        FROM Employee
    )
SELECT
    id,
    company,
    salary
FROM t
WHERE rk >= n / 2 AND rk <= n / 2 + 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Employee</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| company      | varchar |
| salary       | int     |
+--------------+---------+
id 是该表的主键列(具有唯一值的列)。
该表的每一行表示公司和一名员工的工资。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出每个公司的工资中位数。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 1  | A       | 2341   |
| 2  | A       | 341    |
| 3  | A       | 15     |
| 4  | A       | 15314  |
| 5  | A       | 451    |
| 6  | A       | 513    |
| 7  | B       | 15     |
| 8  | B       | 13     |
| 9  | B       | 1154   |
| 10 | B       | 1345   |
| 11 | B       | 1221   |
| 12 | B       | 234    |
| 13 | C       | 2345   |
| 14 | C       | 2645   |
| 15 | C       | 2645   |
| 16 | C       | 2652   |
| 17 | C       | 65     |
+----+---------+--------+
<strong>输出:</strong> 
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 5  | A       | 451    |
| 6  | A       | 513    |
| 12 | B       | 234    |
| 9  | B       | 1154   |
| 14 | C       | 2645   |
+----+---------+--------+
</pre>

<p>&nbsp;</p>

<p><strong>进阶:&nbsp;</strong>你能在不使用任何内置函数或窗口函数的情况下解决它吗?</p>

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
            *,
            ROW_NUMBER() OVER (
                PARTITION BY company
                ORDER BY salary ASC
            ) AS rk,
            COUNT(id) OVER (PARTITION BY company) AS n
        FROM Employee
    )
SELECT
    id,
    company,
    salary
FROM t
WHERE rk >= n / 2 AND rk <= n / 2 + 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
