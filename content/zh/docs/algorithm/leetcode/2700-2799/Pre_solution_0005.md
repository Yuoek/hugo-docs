---
title: "2740_找出分区值"
date: 2025-10-08T18:39:33+08:00
weight: 5
tags: [位运算, 动态规划, 哈希表, 字符串, 排序, 数学, 数组, 数论, 枚举, 模拟, 滑动窗口, 状态压缩, 脑筋急转弯, 计数, 贪心]
---

{{< markmap >}}
### [2740_找出分区值](#2740)
#### [数组](#2740)
#### [排序](#2740)
### [2741_特别的排列](#2741)
#### [位运算](#2741)
#### [数组](#2741)
#### [动态规划](#2741)
#### [状态压缩](#2741)
### [2742_给墙壁刷油漆](#2742)
#### [数组](#2742)
#### [动态规划](#2742)
### [2743_计算没有重复字符的子字符串数量 🔒](#2743)
#### [哈希表](#2743)
#### [字符串](#2743)
#### [滑动窗口](#2743)
### [2744_最大字符串配对数目](#2744)
#### [数组](#2744)
#### [哈希表](#2744)
#### [字符串](#2744)
#### [模拟](#2744)
### [2745_构造最长的新字符串](#2745)
#### [贪心](#2745)
#### [脑筋急转弯](#2745)
#### [数学](#2745)
#### [动态规划](#2745)
### [2746_字符串连接删减字母](#2746)
#### [数组](#2746)
#### [字符串](#2746)
#### [动态规划](#2746)
### [2747_统计没有收到请求的服务器数目](#2747)
#### [数组](#2747)
#### [哈希表](#2747)
#### [排序](#2747)
#### [滑动窗口](#2747)
### [2748_美丽下标对的数目](#2748)
#### [数组](#2748)
#### [哈希表](#2748)
#### [数学](#2748)
#### [计数](#2748)
#### [数论](#2748)
### [2749_得到整数零需要执行的最少操作数](#2749)
#### [位运算](#2749)
#### [脑筋急转弯](#2749)
#### [枚举](#2749)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2740_找出分区值
___
#### 数组
___
#### 排序
---
### 2741_特别的排列
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 2742_给墙壁刷油漆
___
#### 数组
___
#### 动态规划
---
### 2743_计算没有重复字符的子字符串数量 🔒
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 2744_最大字符串配对数目
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 模拟
---
### 2745_构造最长的新字符串
___
#### 贪心
___
#### 脑筋急转弯
___
#### 数学
___
#### 动态规划
---
### 2746_字符串连接删减字母
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 2747_统计没有收到请求的服务器数目
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 滑动窗口
---
### 2748_美丽下标对的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
___
#### 数论
---
### 2749_得到整数零需要执行的最少操作数
___
#### 位运算
___
#### 脑筋急转弯
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 哈希表 |
| 字符串 | 排序 | 数学 |
| 数组 | 数论 | 枚举 |
| 模拟 | 滑动窗口 | 状态压缩 |
| 脑筋急转弯 | 计数 | 贪心 |

# [2740. 找出分区值](https://leetcode.cn/problems/find-the-value-of-the-partition){#2740}

{{< tabs "2740" >}}

{{% tab "python" %}}
```python
class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        return min(b - a for a, b in pairwise(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int ans = 1 << 30;
        for (int i = 1; i < nums.length; ++i) {
            ans = Math.min(ans, nums[i] - nums[i - 1]);
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
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30;
        for (int i = 1; i < nums.size(); ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findValueOfPartition(nums []int) int {
	sort.Ints(nums)
	ans := 1 << 30
	for i, x := range nums[1:] {
		ans = min(ans, x-nums[i])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findValueOfPartition(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = Infinity;
    for (let i = 1; i < nums.length; ++i) {
        ans = Math.min(ans, Math.abs(nums[i] - nums[i - 1]));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_value_of_partition(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = i32::MAX;
        for i in 1..nums.len() {
            ans = ans.min(nums[i] - nums[i - 1]);
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

<p>给你一个 <strong>正</strong> 整数数组 <code>nums</code> 。</p>

<p>将 <code>nums</code> 分成两个数组：<code>nums1</code> 和 <code>nums2</code> ，并满足下述条件：</p>

<ul>
	<li>数组 <code>nums</code> 中的每个元素都属于数组 <code>nums1</code> 或数组 <code>nums2</code> 。</li>
	<li>两个数组都 <strong>非空</strong> 。</li>
	<li>分区值 <strong>最小</strong> 。</li>
</ul>

<p>分区值的计算方法是 <code>|max(nums1) - min(nums2)|</code> 。</p>

<p>其中，<code>max(nums1)</code> 表示数组 <code>nums1</code> 中的最大元素，<code>min(nums2)</code> 表示数组 <code>nums2</code> 中的最小元素。</p>

<p>返回表示分区值的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,2,4]
<strong>输出：</strong>1
<strong>解释：</strong>可以将数组 nums 分成 nums1 = [1,2] 和 nums2 = [3,4] 。
- 数组 nums1 的最大值等于 2 。
- 数组 nums2 的最小值等于 3 。
分区值等于 |2 - 3| = 1 。
可以证明 1 是所有分区方案的最小值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [100,1,10]
<strong>输出：</strong>9
<strong>解释：</strong>可以将数组 nums 分成 nums1 = [10] 和 nums2 = [100,1] 。 
- 数组 nums1 的最大值等于 10 。 
- 数组 nums2 的最小值等于 1 。 
分区值等于 |10 - 1| = 9 。 
可以证明 9 是所有分区方案的最小值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

题目要求分区值最小，那么我们可以将数组排序，然后取相邻两个数的差值的最小值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        return min(b - a for a, b in pairwise(nums))
```

#### Java

```java
class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int ans = 1 << 30;
        for (int i = 1; i < nums.length; ++i) {
            ans = Math.min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30;
        for (int i = 1; i < nums.size(); ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func findValueOfPartition(nums []int) int {
	sort.Ints(nums)
	ans := 1 << 30
	for i, x := range nums[1:] {
		ans = min(ans, x-nums[i])
	}
	return ans
}
```

#### TypeScript

```ts
function findValueOfPartition(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = Infinity;
    for (let i = 1; i < nums.length; ++i) {
        ans = Math.min(ans, Math.abs(nums[i] - nums[i - 1]));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_value_of_partition(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = i32::MAX;
        for i in 1..nums.len() {
            ans = ans.min(nums[i] - nums[i - 1]);
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

# [2741. 特别的排列](https://leetcode.cn/problems/special-permutations){#2741}

{{< tabs "2741" >}}

{{% tab "python" %}}
```python
class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        m = 1 << n
        f = [[0] * n for _ in range(m)]
        for i in range(1, m):
            for j, x in enumerate(nums):
                if i >> j & 1:
                    ii = i ^ (1 << j)
                    if ii == 0:
                        f[i][j] = 1
                        continue
                    for k, y in enumerate(nums):
                        if x % y == 0 or y % x == 0:
                            f[i][j] = (f[i][j] + f[ii][k]) % mod
        return sum(f[-1]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int specialPerm(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int m = 1 << n;
        int[][] f = new int[m][n];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    int ii = i ^ (1 << j);
                    if (ii == 0) {
                        f[i][j] = 1;
                        continue;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                            f[i][j] = (f[i][j] + f[ii][k]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int x : f[m - 1]) {
            ans = (ans + x) % mod;
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
    int specialPerm(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = 1 << n;
        int f[m][n];
        memset(f, 0, sizeof(f));
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    int ii = i ^ (1 << j);
                    if (ii == 0) {
                        f[i][j] = 1;
                        continue;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                            f[i][j] = (f[i][j] + f[ii][k]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int x : f[m - 1]) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func specialPerm(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	m := 1 << n
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 1; i < m; i++ {
		for j, x := range nums {
			if i>>j&1 == 1 {
				ii := i ^ (1 << j)
				if ii == 0 {
					f[i][j] = 1
					continue
				}
				for k, y := range nums {
					if x%y == 0 || y%x == 0 {
						f[i][j] = (f[i][j] + f[ii][k]) % mod
					}
				}
			}
		}
	}
	for _, x := range f[m-1] {
		ans = (ans + x) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function specialPerm(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const m = 1 << n;
    const f = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 1; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 1) {
                const ii = i ^ (1 << j);
                if (ii === 0) {
                    f[i][j] = 1;
                    continue;
                }
                for (let k = 0; k < n; ++k) {
                    if (nums[j] % nums[k] === 0 || nums[k] % nums[j] === 0) {
                        f[i][j] = (f[i][j] + f[ii][k]) % mod;
                    }
                }
            }
        }
    }

    return f[m - 1].reduce((acc, x) => (acc + x) % mod);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn special_perm(nums: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let n = nums.len();
        let m = 1 << n;
        let mut f = vec![vec![0; n]; m];

        for i in 1..m {
            for j in 0..n {
                if (i >> j) & 1 == 1 {
                    let ii = i ^ (1 << j);
                    if ii == 0 {
                        f[i][j] = 1;
                        continue;
                    }
                    for k in 0..n {
                        if nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0 {
                            f[i][j] = (f[i][j] + f[ii][k]) % MOD;
                        }
                    }
                }
            }
        }

        let mut ans = 0;
        for &x in &f[m - 1] {
            ans = (ans + x) % MOD;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它包含 <code>n</code>&nbsp;个 <strong>互不相同</strong>&nbsp;的正整数。如果&nbsp;<code>nums</code>&nbsp;的一个排列满足以下条件，我们称它是一个特别的排列：</p>

<ul>
	<li>对于&nbsp;<code>0 &lt;= i &lt; n - 1</code>&nbsp;的下标 <code>i</code>&nbsp;，要么&nbsp;<code>nums[i] % nums[i+1] == 0</code>&nbsp;，要么&nbsp;<code>nums[i+1] % nums[i] == 0</code>&nbsp;。</li>
</ul>

<p>请你返回特别排列的总数目，由于答案可能很大，请将它对<strong>&nbsp;</strong><code>10<sup>9&nbsp;</sup>+ 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,6]
<b>输出：</b>2
<b>解释：</b>[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,4,3]
<b>输出：</b>2
<b>解释：</b>[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 14</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们注意到题目中数组的长度最大不超过 $14$，因此，我们可以用一个二进制整数来表示当前的状态，其中第 $i$ 位为 $1$ 表示数组中的第 $i$ 个数已经被选取，为 $0$ 表示数组中的第 $i$ 个数还未被选取。

我们定义 $f[i][j]$ 表示当前选取的整数状态为 $i$，且最后一个选取的整数下标为 $j$ 的方案数。初始时 $f[0][0]=0$，答案为 $\sum_{j=0}^{n-1}f[2^n-1][j]$。

考虑 $f[i][j]$，如果当前只有一个数被选取，那么 $f[i][j]=1$。否则，我们可以枚举上一个选择的数的下标 $k$，如果 $k$ 与 $j$ 对应的数满足题目要求，那么 $f[i][j]$ 可以从 $f[i \oplus 2^j][k]$ 转移而来。即：

$$
f[i][j]=
\begin{cases}
1, & i=2^j\\
\sum_{k=0}^{n-1}f[i \oplus 2^j][k], & i \neq 2^j \textit{且} \textit{nums}[j] \textit{与} \textit{nums}[k] \textit{满足题目要求}\\
\end{cases}
$$

最终答案即为 $\sum_{j=0}^{n-1}f[2^n-1][j]$。注意答案可能很大，需要对 $10^9+7$ 取模。

时间复杂度 $O(n^2 \times 2^n)$，空间复杂度 $O(n \times 2^n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        m = 1 << n
        f = [[0] * n for _ in range(m)]
        for i in range(1, m):
            for j, x in enumerate(nums):
                if i >> j & 1:
                    ii = i ^ (1 << j)
                    if ii == 0:
                        f[i][j] = 1
                        continue
                    for k, y in enumerate(nums):
                        if x % y == 0 or y % x == 0:
                            f[i][j] = (f[i][j] + f[ii][k]) % mod
        return sum(f[-1]) % mod
```

#### Java

```java
class Solution {
    public int specialPerm(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int m = 1 << n;
        int[][] f = new int[m][n];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    int ii = i ^ (1 << j);
                    if (ii == 0) {
                        f[i][j] = 1;
                        continue;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                            f[i][j] = (f[i][j] + f[ii][k]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int x : f[m - 1]) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = 1 << n;
        int f[m][n];
        memset(f, 0, sizeof(f));
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    int ii = i ^ (1 << j);
                    if (ii == 0) {
                        f[i][j] = 1;
                        continue;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                            f[i][j] = (f[i][j] + f[ii][k]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int x : f[m - 1]) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func specialPerm(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	m := 1 << n
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 1; i < m; i++ {
		for j, x := range nums {
			if i>>j&1 == 1 {
				ii := i ^ (1 << j)
				if ii == 0 {
					f[i][j] = 1
					continue
				}
				for k, y := range nums {
					if x%y == 0 || y%x == 0 {
						f[i][j] = (f[i][j] + f[ii][k]) % mod
					}
				}
			}
		}
	}
	for _, x := range f[m-1] {
		ans = (ans + x) % mod
	}
	return
}
```

#### TypeScript

```ts
function specialPerm(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const m = 1 << n;
    const f = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 1; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 1) {
                const ii = i ^ (1 << j);
                if (ii === 0) {
                    f[i][j] = 1;
                    continue;
                }
                for (let k = 0; k < n; ++k) {
                    if (nums[j] % nums[k] === 0 || nums[k] % nums[j] === 0) {
                        f[i][j] = (f[i][j] + f[ii][k]) % mod;
                    }
                }
            }
        }
    }

    return f[m - 1].reduce((acc, x) => (acc + x) % mod);
}
```

#### Rust

```rust
impl Solution {
    pub fn special_perm(nums: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let n = nums.len();
        let m = 1 << n;
        let mut f = vec![vec![0; n]; m];

        for i in 1..m {
            for j in 0..n {
                if (i >> j) & 1 == 1 {
                    let ii = i ^ (1 << j);
                    if ii == 0 {
                        f[i][j] = 1;
                        continue;
                    }
                    for k in 0..n {
                        if nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0 {
                            f[i][j] = (f[i][j] + f[ii][k]) % MOD;
                        }
                    }
                }
            }
        }

        let mut ans = 0;
        for &x in &f[m - 1] {
            ans = (ans + x) % MOD;
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

# [2742. 给墙壁刷油漆](https://leetcode.cn/problems/painting-the-walls){#2742}

{{< tabs "2742" >}}

{{% tab "python" %}}
```python
class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if n - i <= j:
                return 0
            if i >= n:
                return inf
            return min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1))

        n = len(cost)
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] cost;
    private int[] time;
    private Integer[][] f;

    public int paintWalls(int[] cost, int[] time) {
        n = cost.length;
        this.cost = cost;
        this.time = time;
        f = new Integer[n][n << 1 | 1];
        return dfs(0, n);
    }

    private int dfs(int i, int j) {
        if (n - i <= j - n) {
            return 0;
        }
        if (i >= n) {
            return 1 << 30;
        }
        if (f[i][j] == null) {
            f[i][j] = Math.min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1));
        }
        return f[i][j];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int f[n][n << 1 | 1];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (n - i <= j - n) {
                return 0;
            }
            if (i >= n) {
                return 1 << 30;
            }
            if (f[i][j] == -1) {
                f[i][j] = min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1));
            }
            return f[i][j];
        };
        return dfs(0, n);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func paintWalls(cost []int, time []int) int {
	n := len(cost)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n<<1|1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if n-i <= j-n {
			return 0
		}
		if i >= n {
			return 1 << 30
		}
		if f[i][j] == -1 {
			f[i][j] = min(dfs(i+1, j+time[i])+cost[i], dfs(i+1, j-1))
		}
		return f[i][j]
	}
	return dfs(0, n)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn paint_walls(cost: Vec<i32>, time: Vec<i32>) -> i32 {
        let n = cost.len();
        let mut record_vec: Vec<Vec<i32>> = vec![vec![-1; n << 1 | 1]; n];
        Self::dfs(&mut record_vec, 0, n as i32, n as i32, &time, &cost)
    }

    #[allow(dead_code)]
    fn dfs(
        record_vec: &mut Vec<Vec<i32>>,
        i: i32,
        j: i32,
        n: i32,
        time: &Vec<i32>,
        cost: &Vec<i32>,
    ) -> i32 {
        if n - i <= j - n {
            // All the remaining walls can be printed at no cost
            // Just return 0
            return 0;
        }
        if i >= n {
            // No way this case can be achieved
            // Just return +INF
            return 1 << 30;
        }
        if record_vec[i as usize][j as usize] == -1 {
            // This record hasn't been written
            record_vec[i as usize][j as usize] = std::cmp::min(
                Self::dfs(record_vec, i + 1, j + time[i as usize], n, time, cost)
                    + cost[i as usize],
                Self::dfs(record_vec, i + 1, j - 1, n, time, cost),
            );
        }
        record_vec[i as usize][j as usize]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>cost</code> 和&nbsp;<code>time</code>&nbsp;，分别表示给&nbsp;<code>n</code>&nbsp;堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：</p>

<ul>
	<li>一位需要 <strong>付费</strong>&nbsp;的油漆匠，刷第&nbsp;<code>i</code>&nbsp;堵墙需要花费&nbsp;<code>time[i]</code>&nbsp;单位的时间，开销为&nbsp;<code>cost[i]</code>&nbsp;单位的钱。</li>
	<li>一位 <strong>免费</strong>&nbsp;的油漆匠，刷 <strong>任意</strong>&nbsp;一堵墙的时间为&nbsp;<code>1</code>&nbsp;单位，开销为&nbsp;<code>0</code>&nbsp;。但是必须在付费油漆匠&nbsp;<strong>工作</strong>&nbsp;时，免费油漆匠才会工作。</li>
</ul>

<p>请你返回刷完 <code>n</code>&nbsp;堵墙最少开销为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>cost = [1,2,3,2], time = [1,2,3,2]
<b>输出：</b>3
<strong>解释：</strong>下标为 0 和 1 的墙由付费油漆匠来刷，需要 3 单位时间。同时，免费油漆匠刷下标为 2 和 3 的墙，需要 2 单位时间，开销为 0 。总开销为 1 + 2 = 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>cost = [2,3,4,2], time = [1,1,1,1]
<b>输出：</b>4
<b>解释：</b>下标为 0 和 3 的墙由付费油漆匠来刷，需要 2 单位时间。同时，免费油漆匠刷下标为 1 和 2 的墙，需要 2 单位时间，开销为 0 。总开销为 2 + 2 = 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cost.length &lt;= 500</code></li>
	<li><code>cost.length == time.length</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= time[i] &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们可以考虑每一堵墙是给付费油漆匠刷还是给免费油漆匠刷，设计一个函数 $dfs(i, j)$，表示从第 $i$ 堵墙开始，且当前剩余的免费油漆匠工作时间为 $j$ 时，刷完剩余所有墙壁的最小开销。那么答案为 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $n - i \le j$，表示剩余的墙壁不超过免费油漆匠的工作时间，那么剩余的墙壁都由免费油漆匠刷，开销为 $0$；
-   如果 $i \ge n$，返回 $+\infty$；
-   否则，如果第 $i$ 堵墙由付费油漆匠刷，开销为 $cost[i]$，那么 $dfs(i, j) = dfs(i + 1, j + time[i]) + cost[i]$；如果第 $i$ 堵墙由免费油漆匠刷，开销为 $0$，那么 $dfs(i, j) = dfs(i + 1, j - 1)$。

注意，参数 $j$ 可能小于 $0$，因此，在实际编码过程中，除了 $Python$ 语言外，我们对 $j$ 加上一个偏移量 $n$，使得 $j$ 的取值范围为 $[0, 2n]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if n - i <= j:
                return 0
            if i >= n:
                return inf
            return min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1))

        n = len(cost)
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private int n;
    private int[] cost;
    private int[] time;
    private Integer[][] f;

    public int paintWalls(int[] cost, int[] time) {
        n = cost.length;
        this.cost = cost;
        this.time = time;
        f = new Integer[n][n << 1 | 1];
        return dfs(0, n);
    }

    private int dfs(int i, int j) {
        if (n - i <= j - n) {
            return 0;
        }
        if (i >= n) {
            return 1 << 30;
        }
        if (f[i][j] == null) {
            f[i][j] = Math.min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1));
        }
        return f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int f[n][n << 1 | 1];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (n - i <= j - n) {
                return 0;
            }
            if (i >= n) {
                return 1 << 30;
            }
            if (f[i][j] == -1) {
                f[i][j] = min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1));
            }
            return f[i][j];
        };
        return dfs(0, n);
    }
};
```

#### Go

```go
func paintWalls(cost []int, time []int) int {
	n := len(cost)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n<<1|1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if n-i <= j-n {
			return 0
		}
		if i >= n {
			return 1 << 30
		}
		if f[i][j] == -1 {
			f[i][j] = min(dfs(i+1, j+time[i])+cost[i], dfs(i+1, j-1))
		}
		return f[i][j]
	}
	return dfs(0, n)
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn paint_walls(cost: Vec<i32>, time: Vec<i32>) -> i32 {
        let n = cost.len();
        let mut record_vec: Vec<Vec<i32>> = vec![vec![-1; n << 1 | 1]; n];
        Self::dfs(&mut record_vec, 0, n as i32, n as i32, &time, &cost)
    }

    #[allow(dead_code)]
    fn dfs(
        record_vec: &mut Vec<Vec<i32>>,
        i: i32,
        j: i32,
        n: i32,
        time: &Vec<i32>,
        cost: &Vec<i32>,
    ) -> i32 {
        if n - i <= j - n {
            // All the remaining walls can be printed at no cost
            // Just return 0
            return 0;
        }
        if i >= n {
            // No way this case can be achieved
            // Just return +INF
            return 1 << 30;
        }
        if record_vec[i as usize][j as usize] == -1 {
            // This record hasn't been written
            record_vec[i as usize][j as usize] = std::cmp::min(
                Self::dfs(record_vec, i + 1, j + time[i as usize], n, time, cost)
                    + cost[i as usize],
                Self::dfs(record_vec, i + 1, j - 1, n, time, cost),
            );
        }
        record_vec[i as usize][j as usize]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2743. 计算没有重复字符的子字符串数量 🔒](https://leetcode.cn/problems/count-substrings-without-repeating-character){#2743}

{{< tabs "2743" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:
        cnt = Counter()
        ans = j = 0
        for i, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[j]] -= 1
                j += 1
            ans += i - j + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfSpecialSubstrings(String s) {
        int n = s.length();
        int ans = 0;
        int[] cnt = new int[26];
        for (int i = 0, j = 0; i < n; ++i) {
            int k = s.charAt(i) - 'a';
            ++cnt[k];
            while (cnt[k] > 1) {
                --cnt[s.charAt(j++) - 'a'];
            }
            ans += i - j + 1;
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
    int numberOfSpecialSubstrings(string s) {
        int n = s.size();
        int cnt[26]{};
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            int k = s[i] - 'a';
            ++cnt[k];
            while (cnt[k] > 1) {
                --cnt[s[j++] - 'a'];
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSpecialSubstrings(s string) (ans int) {
	j := 0
	cnt := [26]int{}
	for i, c := range s {
		k := c - 'a'
		cnt[k]++
		for cnt[k] > 1 {
			cnt[s[j]-'a']--
			j++
		}
		ans += i - j + 1
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSpecialSubstrings(s: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const n = s.length;
    const cnt: number[] = Array(26).fill(0);
    let ans = 0;
    for (let i = 0, j = 0; i < n; ++i) {
        const k = idx(s[i]);
        ++cnt[k];
        while (cnt[k] > 1) {
            --cnt[idx(s[j++])];
        }
        ans += i - j + 1;
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

<p>给定你一个只包含小写英文字母的字符串 <code>s</code> 。如果一个子字符串不包含任何字符至少出现两次（换句话说，它不包含重复字符），则称其为 <strong>特殊</strong> 子字符串。你的任务是计算 <strong>特殊</strong> 子字符串的数量。例如，在字符串 <code>"pop"</code> 中，子串 <code>"po"</code> 是一个特殊子字符串，然而 <code>"pop"</code> 不是 <strong>特殊</strong> 子字符串（因为 <code>'p'</code> 出现了两次）。</p>

<p>返回 <strong>特殊</strong> 子字符串的数量。</p>

<p><strong>子字符串</strong> 是指字符串中连续的字符序列。例如，<code>"abc"</code> 是 <code>"abcd"</code> 的一个子字符串，但 <code>"acd"</code> 不是。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abcd"
<b>输出：</b>10
<b>解释：</b>由于每个字符只出现一次，每个子串都是特殊子串。长度为 1 的子串有 4 个，长度为 2 的有 3 个，长度为 3 的有 2 个，长度为 4 的有 1 个。所以一共有 4 + 3 + 2 + 1 = 10 个特殊子串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "ooo"
<b>输出：</b>3
<b>解释：</b>任何长度至少为 2 的子串都包含重复字符。所以我们要计算长度为 1 的子串的数量，即 3 个。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>s = "abab"
<b>输出：</b>7
<b>解释：</b>特殊子串如下（按起始位置排序）： 
长度为 1 的特殊子串："a", "b", "a", "b" 
长度为 2 的特殊子串："ab", "ba", "ab" 
并且可以证明没有长度至少为 3 的特殊子串。所以答案是4 + 3 = 7。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 双指针

我们用两个指针 $j$ 和 $i$ 分别表示当前子串的左右边界，用一个长度为 $26$ 的数组 $cnt$ 统计当前子串中每个字符出现的次数。我们从左到右遍历字符串，每次遍历到位置 $i$ 时，将 $s[i]$ 出现的次数加一，然后判断 $s[i]$ 是否出现了至少两次，如果是，那么我们需要将 $s[j]$ 出现的次数减一，并将 $j$ 右移一位，直到 $s[i]$ 出现的次数不超过一次为止。这样一来，我们就得到以 $s[i]$ 结尾的最长特殊子串的长度，即 $i - j + 1$，那么以 $s[i]$ 结尾的特殊子串的数量就是 $i - j + 1$。最后我们将每个位置结尾的特殊子串的数量累加起来，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是字符串 $s$ 的长度；而 $C$ 是字符集的大小，这里字符集为小写英文字母，因此 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:
        cnt = Counter()
        ans = j = 0
        for i, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[j]] -= 1
                j += 1
            ans += i - j + 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfSpecialSubstrings(String s) {
        int n = s.length();
        int ans = 0;
        int[] cnt = new int[26];
        for (int i = 0, j = 0; i < n; ++i) {
            int k = s.charAt(i) - 'a';
            ++cnt[k];
            while (cnt[k] > 1) {
                --cnt[s.charAt(j++) - 'a'];
            }
            ans += i - j + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int n = s.size();
        int cnt[26]{};
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            int k = s[i] - 'a';
            ++cnt[k];
            while (cnt[k] > 1) {
                --cnt[s[j++] - 'a'];
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSpecialSubstrings(s string) (ans int) {
	j := 0
	cnt := [26]int{}
	for i, c := range s {
		k := c - 'a'
		cnt[k]++
		for cnt[k] > 1 {
			cnt[s[j]-'a']--
			j++
		}
		ans += i - j + 1
	}
	return
}
```

#### TypeScript

```ts
function numberOfSpecialSubstrings(s: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const n = s.length;
    const cnt: number[] = Array(26).fill(0);
    let ans = 0;
    for (let i = 0, j = 0; i < n; ++i) {
        const k = idx(s[i]);
        ++cnt[k];
        while (cnt[k] > 1) {
            --cnt[idx(s[j++])];
        }
        ans += i - j + 1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2744. 最大字符串配对数目](https://leetcode.cn/problems/find-maximum-number-of-string-pairs){#2744}

{{< tabs "2744" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        cnt = Counter()
        ans = 0
        for w in words:
            ans += cnt[w[::-1]]
            cnt[w] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (var w : words) {
            int a = w.charAt(0) - 'a', b = w.charAt(1) - 'a';
            ans += cnt.getOrDefault(b << 5 | a, 0);
            cnt.merge(a << 5 | b, 1, Integer::sum);
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
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& w : words) {
            int a = w[0] - 'a', b = w[1] - 'a';
            ans += cnt[b << 5 | a];
            cnt[a << 5 | b]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumNumberOfStringPairs(words []string) (ans int) {
	cnt := map[int]int{}
	for _, w := range words {
		a, b := int(w[0]-'a'), int(w[1]-'a')
		ans += cnt[b<<5|a]
		cnt[a<<5|b]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumNumberOfStringPairs(words: string[]): number {
    const cnt: { [key: number]: number } = {};
    let ans = 0;
    for (const w of words) {
        const [a, b] = [w.charCodeAt(0) - 97, w.charCodeAt(w.length - 1) - 97];
        ans += cnt[(b << 5) | a] || 0;
        cnt[(a << 5) | b] = (cnt[(a << 5) | b] || 0) + 1;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>words</code>&nbsp;，数组中包含 <strong>互不相同</strong>&nbsp;的字符串。</p>

<p>如果字符串&nbsp;<code>words[i]</code>&nbsp;与字符串 <code>words[j]</code>&nbsp;满足以下条件，我们称它们可以匹配：</p>

<ul>
	<li>字符串&nbsp;<code>words[i]</code>&nbsp;等于&nbsp;<code>words[j]</code>&nbsp;的反转字符串。</li>
	<li><code>0 &lt;= i &lt; j &lt; words.length</code></li>
</ul>

<p>请你返回数组 <code>words</code>&nbsp;中的&nbsp;<strong>最大</strong>&nbsp;匹配数目。</p>

<p>注意，每个字符串最多匹配一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["cd","ac","dc","ca","zz"]
<b>输出：</b>2
<strong>解释：</strong>在此示例中，我们可以通过以下方式匹配 2 对字符串：
- 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
- 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
可以证明最多匹配数目是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["ab","ba","cc"]
<b>输出：</b>1
<b>解释：</b>在此示例中，我们可以通过以下方式匹配 1 对字符串：
- 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab" 与 words[0] 相等。
可以证明最多匹配数目是 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>words = ["aa","ab"]
<b>输出：</b>0
<strong>解释：</strong>这个例子中，无法匹配任何字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words</code>&nbsp;包含的字符串互不相同。</li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用哈希表 $cnt$ 来存储数组 $words$ 中每个字符串的反转字符串出现的次数。

遍历数组 $words$，对于每个字符串 $w$，我们将其反转字符串 $w$ 的出现次数加到答案中，然后将 $w$ 的出现次数加 $1$。

最后返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $words$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        cnt = Counter()
        ans = 0
        for w in words:
            ans += cnt[w[::-1]]
            cnt[w] += 1
        return ans
```

#### Java

```java
class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (var w : words) {
            int a = w.charAt(0) - 'a', b = w.charAt(1) - 'a';
            ans += cnt.getOrDefault(b << 5 | a, 0);
            cnt.merge(a << 5 | b, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& w : words) {
            int a = w[0] - 'a', b = w[1] - 'a';
            ans += cnt[b << 5 | a];
            cnt[a << 5 | b]++;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumNumberOfStringPairs(words []string) (ans int) {
	cnt := map[int]int{}
	for _, w := range words {
		a, b := int(w[0]-'a'), int(w[1]-'a')
		ans += cnt[b<<5|a]
		cnt[a<<5|b]++
	}
	return
}
```

#### TypeScript

```ts
function maximumNumberOfStringPairs(words: string[]): number {
    const cnt: { [key: number]: number } = {};
    let ans = 0;
    for (const w of words) {
        const [a, b] = [w.charCodeAt(0) - 97, w.charCodeAt(w.length - 1) - 97];
        ans += cnt[(b << 5) | a] || 0;
        cnt[(a << 5) | b] = (cnt[(a << 5) | b] || 0) + 1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2745. 构造最长的新字符串](https://leetcode.cn/problems/construct-the-longest-new-string){#2745}

{{< tabs "2745" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        if x < y:
            return (x * 2 + z + 1) * 2
        if x > y:
            return (y * 2 + z + 1) * 2
        return (x + y + z) * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestString(int x, int y, int z) {
        if (x < y) {
            return (x * 2 + z + 1) * 2;
        }
        if (x > y) {
            return (y * 2 + z + 1) * 2;
        }
        return (x + y + z) * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestString(int x, int y, int z) {
        if (x < y) {
            return (x * 2 + z + 1) * 2;
        }
        if (x > y) {
            return (y * 2 + z + 1) * 2;
        }
        return (x + y + z) * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestString(x int, y int, z int) int {
	if x < y {
		return (x*2 + z + 1) * 2
	}
	if x > y {
		return (y*2 + z + 1) * 2
	}
	return (x + y + z) * 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestString(x: number, y: number, z: number): number {
    if (x < y) {
        return (x * 2 + z + 1) * 2;
    }
    if (x > y) {
        return (y * 2 + z + 1) * 2;
    }
    return (x + y + z) * 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你三个整数&nbsp;<code>x</code>&nbsp;，<code>y</code>&nbsp;和&nbsp;<code>z</code>&nbsp;。</p>

<p>这三个整数表示你有&nbsp;<code>x</code>&nbsp;个&nbsp;<code>"AA"</code>&nbsp;字符串，<code>y</code>&nbsp;个&nbsp;<code>"BB"</code>&nbsp;字符串，和&nbsp;<code>z</code>&nbsp;个&nbsp;<code>"AB"</code>&nbsp;字符串。你需要选择这些字符串中的部分字符串（可以全部选择也可以一个都不选择），将它们按顺序连接得到一个新的字符串。新字符串不能包含子字符串&nbsp;<code>"AAA"</code>&nbsp;或者&nbsp;<code>"BBB"</code>&nbsp;。</p>

<p>请你返回 <em>新字符串的最大可能长度。</em></p>

<p><strong>子字符串</strong>&nbsp;是一个字符串中一段连续 <strong>非空</strong>&nbsp;的字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>x = 2, y = 5, z = 1
<b>输出：</b>12
<strong>解释： </strong>我们可以按顺序连接 "BB" ，"AA" ，"BB" ，"AA" ，"BB" 和 "AB" ，得到新字符串 "BBAABBAABBAB" 。
字符串长度为 12 ，无法得到一个更长的符合题目要求的字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 2, z = 2
<b>输出：</b>14
<b>解释：</b>我们可以按顺序连接 "AB" ，"AB" ，"AA" ，"BB" ，"AA" ，"BB" 和 "AA" ，得到新字符串 "ABABAABBAABBAA" 。
字符串长度为 14 ，无法得到一个更长的符合题目要求的字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y, z &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

我们观察发现，字符串 `'AA'` 之后只能跟 `'BB'`，而字符串 `'AB'` 可以放在字符串开头或结尾。因此：

-   如果 $x \lt y$，那么我们可以先交替放置 `'BBAABBAA..BB'`，一共放置 $x$ 个 `'AA'` 和 $x+1$ 个 `'BB'`，然后放置剩余的 $z$ 个 `'AB'`，总长度为 $(x \times 2 + z + 1) \times 2$；
-   如果 $x \gt y$，那么我们可以先交替放置 `'AABBAABB..AA'`，一共放置 $y$ 个 `'BB'` 和 $y+1$ 个 `'AA'`，然后放置剩余的 $z$ 个 `'AB'`，总长度为 $(y \times 2 + z + 1) \times 2$；
-   如果 $x = y$，我们只需要交替放置 `'AABB'`，一共放置 $x$ 个 `'AA'` 和 $y$ 个 `'BB'`，然后放置剩余的 $z$ 个 `'AB'`，总长度为 $(x + y + z) \times 2$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        if x < y:
            return (x * 2 + z + 1) * 2
        if x > y:
            return (y * 2 + z + 1) * 2
        return (x + y + z) * 2
```

#### Java

```java
class Solution {
    public int longestString(int x, int y, int z) {
        if (x < y) {
            return (x * 2 + z + 1) * 2;
        }
        if (x > y) {
            return (y * 2 + z + 1) * 2;
        }
        return (x + y + z) * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestString(int x, int y, int z) {
        if (x < y) {
            return (x * 2 + z + 1) * 2;
        }
        if (x > y) {
            return (y * 2 + z + 1) * 2;
        }
        return (x + y + z) * 2;
    }
};
```

#### Go

```go
func longestString(x int, y int, z int) int {
	if x < y {
		return (x*2 + z + 1) * 2
	}
	if x > y {
		return (y*2 + z + 1) * 2
	}
	return (x + y + z) * 2
}
```

#### TypeScript

```ts
function longestString(x: number, y: number, z: number): number {
    if (x < y) {
        return (x * 2 + z + 1) * 2;
    }
    if (x > y) {
        return (y * 2 + z + 1) * 2;
    }
    return (x + y + z) * 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2746. 字符串连接删减字母](https://leetcode.cn/problems/decremental-string-concatenation){#2746}

{{< tabs "2746" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        @cache
        def dfs(i: int, a: str, b: str) -> int:
            if i >= len(words):
                return 0
            s = words[i]
            x = dfs(i + 1, a, s[-1]) - int(s[0] == b)
            y = dfs(i + 1, s[0], b) - int(s[-1] == a)
            return len(s) + min(x, y)

        return len(words[0]) + dfs(1, words[0][0], words[0][-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][][] f;
    private String[] words;
    private int n;

    public int minimizeConcatenatedLength(String[] words) {
        n = words.length;
        this.words = words;
        f = new Integer[n][26][26];
        return words[0].length()
            + dfs(1, words[0].charAt(0) - 'a', words[0].charAt(words[0].length() - 1) - 'a');
    }

    private int dfs(int i, int a, int b) {
        if (i >= n) {
            return 0;
        }
        if (f[i][a][b] != null) {
            return f[i][a][b];
        }
        String s = words[i];
        int m = s.length();
        int x = dfs(i + 1, a, s.charAt(m - 1) - 'a') - (s.charAt(0) - 'a' == b ? 1 : 0);
        int y = dfs(i + 1, s.charAt(0) - 'a', b) - (s.charAt(m - 1) - 'a' == a ? 1 : 0);
        return f[i][a][b] = m + Math.min(x, y);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int f[n][26][26];
        memset(f, 0, sizeof(f));
        function<int(int, int, int)> dfs = [&](int i, int a, int b) {
            if (i >= n) {
                return 0;
            }
            if (f[i][a][b]) {
                return f[i][a][b];
            }
            auto s = words[i];
            int m = s.size();
            int x = dfs(i + 1, a, s[m - 1] - 'a') - (s[0] - 'a' == b);
            int y = dfs(i + 1, s[0] - 'a', b) - (s[m - 1] - 'a' == a);
            return f[i][a][b] = m + min(x, y);
        };
        return words[0].size() + dfs(1, words[0].front() - 'a', words[0].back() - 'a');
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeConcatenatedLength(words []string) int {
	n := len(words)
	f := make([][26][26]int, n)
	var dfs func(i, a, b int) int
	dfs = func(i, a, b int) int {
		if i >= n {
			return 0
		}
		if f[i][a][b] > 0 {
			return f[i][a][b]
		}
		s := words[i]
		m := len(s)
		x := dfs(i+1, a, int(s[m-1]-'a'))
		y := dfs(i+1, int(s[0]-'a'), b)
		if int(s[0]-'a') == b {
			x--
		}
		if int(s[m-1]-'a') == a {
			y--
		}
		f[i][a][b] = m + min(x, y)
		return f[i][a][b]
	}
	return len(words[0]) + dfs(1, int(words[0][0]-'a'), int(words[0][len(words[0])-1]-'a'))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizeConcatenatedLength(words: string[]): number {
    const n = words.length;
    const f: number[][][] = Array(n)
        .fill(0)
        .map(() =>
            Array(26)
                .fill(0)
                .map(() => Array(26).fill(0)),
        );
    const dfs = (i: number, a: number, b: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i][a][b] > 0) {
            return f[i][a][b];
        }
        const s = words[i];
        const m = s.length;
        const x =
            dfs(i + 1, a, s[m - 1].charCodeAt(0) - 97) - (s[0].charCodeAt(0) - 97 === b ? 1 : 0);
        const y =
            dfs(i + 1, s[0].charCodeAt(0) - 97, b) - (s[m - 1].charCodeAt(0) - 97 === a ? 1 : 0);
        return (f[i][a][b] = Math.min(x + m, y + m));
    };
    return (
        words[0].length +
        dfs(1, words[0][0].charCodeAt(0) - 97, words[0][words[0].length - 1].charCodeAt(0) - 97)
    );
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>words</code>&nbsp;，它包含 <code>n</code>&nbsp;个字符串。</p>

<p>定义 <strong>连接</strong>&nbsp;操作&nbsp;<code>join(x, y)</code>&nbsp;表示将字符串&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;连在一起，得到&nbsp;<code>xy</code>&nbsp;。如果&nbsp;<code>x</code>&nbsp;的最后一个字符与&nbsp;<code>y</code>&nbsp;的第一个字符相等，连接后两个字符中的一个会被&nbsp;<strong>删除</strong>&nbsp;。</p>

<p>比方说&nbsp;<code>join("ab", "ba") = "aba"</code>&nbsp;，&nbsp;<code>join("ab", "cde") = "abcde"</code>&nbsp;。</p>

<p>你需要执行&nbsp;<code>n - 1</code>&nbsp;次&nbsp;<strong>连接</strong>&nbsp;操作。令&nbsp;<code>str<sub>0</sub> = words[0]</code>&nbsp;，从&nbsp;<code>i = 1</code> 直到&nbsp;<code>i = n - 1</code>&nbsp;，对于第&nbsp;<code>i</code>&nbsp;个操作，你可以执行以下操作之一：</p>

<ul>
	<li>令&nbsp;<code>str<sub>i</sub> = join(str<sub>i - 1</sub>, words[i])</code></li>
	<li>令&nbsp;<code>str<sub>i</sub> = join(words[i], str<sub>i - 1</sub>)</code></li>
</ul>

<p>你的任务是使&nbsp;<code>str<sub>n - 1</sub></code>&nbsp;的长度<strong>&nbsp;最小&nbsp;</strong>。</p>

<p>请你返回一个整数，表示&nbsp;<code>str<sub>n - 1</sub></code>&nbsp;的最小长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["aa","ab","bc"]
<b>输出：</b>4
<strong>解释：</strong>这个例子中，我们按以下顺序执行连接操作，得到 <code>str<sub>2</sub></code> 的最小长度：
<code>str<sub>0</sub> = "aa"</code>
<code>str<sub>1</sub> = join(str<sub>0</sub>, "ab") = "aab"
</code><code>str<sub>2</sub> = join(str<sub>1</sub>, "bc") = "aabc"</code> 
<code>str<sub>2</sub></code> 的最小长度为 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["ab","b"]
<b>输出：</b>2
<b>解释：</b>这个例子中，str<sub>0</sub> = "ab"，可以得到两个不同的 str<sub>1</sub>：
join(str<sub>0</sub>, "b") = "ab" 或者 join("b", str<sub>0</sub>) = "bab" 。
第一个字符串 "ab" 的长度最短，所以答案为 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>words = ["aaa","c","aba"]
<b>输出：</b>6
<b>解释：</b>这个例子中，我们按以下顺序执行连接操作，得到 <code>str<sub>2</sub>&nbsp;的最小长度：</code>
<code>str<sub>0</sub> = "</code>aaa"
<code>str<sub>1</sub> = join(str<sub>0</sub>, "c") = "aaac"</code>
<code>str<sub>2</sub> = join("aba", str<sub>1</sub>) = "abaaac"</code>
<code>str<sub>2</sub></code> 的最小长度为 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>words[i]</code>&nbsp;中只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们注意到，字符串连接时，字符串的第一个字符和最后一个字符会影响到连接后字符串的长度。因此，我们设计一个函数 $dfs(i, a, b)$，表示从第 $i$ 个字符串开始连接，且此前已经连接的字符串的第一个字符为 $a$，最后一个字符为 $b$ 时，连接后字符串的最小长度。

函数 $dfs(i, a, b)$ 的执行过程如下：

-   如果 $i = n$，说明所有字符串已经连接完毕，返回 $0$；
-   否则，我们考虑将第 $i$ 个字符串连接到已经连接的字符串的末尾或者开头，得到连接后字符串的长度 $x$ 和 $y$，则 $dfs(i, a, b) = \min(x, y) + |words[i]|$。

为了避免重复计算，我们使用记忆化搜索的方法。具体地，我们使用一个三维数组 $f$ 存储所有的 $dfs(i, a, b)$ 的返回值。当我们需要计算 $dfs(i, a, b)$ 时，如果 $f[i][a][b]$ 已经被计算过，我们直接返回 $f[i][a][b]$；否则我们按照上述的递推关系计算 $dfs(i, a, b)$ 的值，并将其存入 $f[i][a][b]$ 中。

在主函数中，我们直接返回 $|words[0]| + dfs(1, words[0][0], words[0][|words[0]| - 1])$。

时间复杂度 $O(n \times C^2)$，空间复杂度 $O(n \times C^2)$，其中 $C$ 表示字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        @cache
        def dfs(i: int, a: str, b: str) -> int:
            if i >= len(words):
                return 0
            s = words[i]
            x = dfs(i + 1, a, s[-1]) - int(s[0] == b)
            y = dfs(i + 1, s[0], b) - int(s[-1] == a)
            return len(s) + min(x, y)

        return len(words[0]) + dfs(1, words[0][0], words[0][-1])
```

#### Java

```java
class Solution {
    private Integer[][][] f;
    private String[] words;
    private int n;

    public int minimizeConcatenatedLength(String[] words) {
        n = words.length;
        this.words = words;
        f = new Integer[n][26][26];
        return words[0].length()
            + dfs(1, words[0].charAt(0) - 'a', words[0].charAt(words[0].length() - 1) - 'a');
    }

    private int dfs(int i, int a, int b) {
        if (i >= n) {
            return 0;
        }
        if (f[i][a][b] != null) {
            return f[i][a][b];
        }
        String s = words[i];
        int m = s.length();
        int x = dfs(i + 1, a, s.charAt(m - 1) - 'a') - (s.charAt(0) - 'a' == b ? 1 : 0);
        int y = dfs(i + 1, s.charAt(0) - 'a', b) - (s.charAt(m - 1) - 'a' == a ? 1 : 0);
        return f[i][a][b] = m + Math.min(x, y);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int f[n][26][26];
        memset(f, 0, sizeof(f));
        function<int(int, int, int)> dfs = [&](int i, int a, int b) {
            if (i >= n) {
                return 0;
            }
            if (f[i][a][b]) {
                return f[i][a][b];
            }
            auto s = words[i];
            int m = s.size();
            int x = dfs(i + 1, a, s[m - 1] - 'a') - (s[0] - 'a' == b);
            int y = dfs(i + 1, s[0] - 'a', b) - (s[m - 1] - 'a' == a);
            return f[i][a][b] = m + min(x, y);
        };
        return words[0].size() + dfs(1, words[0].front() - 'a', words[0].back() - 'a');
    }
};
```

#### Go

```go
func minimizeConcatenatedLength(words []string) int {
	n := len(words)
	f := make([][26][26]int, n)
	var dfs func(i, a, b int) int
	dfs = func(i, a, b int) int {
		if i >= n {
			return 0
		}
		if f[i][a][b] > 0 {
			return f[i][a][b]
		}
		s := words[i]
		m := len(s)
		x := dfs(i+1, a, int(s[m-1]-'a'))
		y := dfs(i+1, int(s[0]-'a'), b)
		if int(s[0]-'a') == b {
			x--
		}
		if int(s[m-1]-'a') == a {
			y--
		}
		f[i][a][b] = m + min(x, y)
		return f[i][a][b]
	}
	return len(words[0]) + dfs(1, int(words[0][0]-'a'), int(words[0][len(words[0])-1]-'a'))
}
```

#### TypeScript

```ts
function minimizeConcatenatedLength(words: string[]): number {
    const n = words.length;
    const f: number[][][] = Array(n)
        .fill(0)
        .map(() =>
            Array(26)
                .fill(0)
                .map(() => Array(26).fill(0)),
        );
    const dfs = (i: number, a: number, b: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i][a][b] > 0) {
            return f[i][a][b];
        }
        const s = words[i];
        const m = s.length;
        const x =
            dfs(i + 1, a, s[m - 1].charCodeAt(0) - 97) - (s[0].charCodeAt(0) - 97 === b ? 1 : 0);
        const y =
            dfs(i + 1, s[0].charCodeAt(0) - 97, b) - (s[m - 1].charCodeAt(0) - 97 === a ? 1 : 0);
        return (f[i][a][b] = Math.min(x + m, y + m));
    };
    return (
        words[0].length +
        dfs(1, words[0][0].charCodeAt(0) - 97, words[0][words[0].length - 1].charCodeAt(0) - 97)
    );
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2747. 统计没有收到请求的服务器数目](https://leetcode.cn/problems/count-zero-request-servers){#2747}

{{< tabs "2747" >}}

{{% tab "python" %}}
```python
class Solution:
    def countServers(
        self, n: int, logs: List[List[int]], x: int, queries: List[int]
    ) -> List[int]:
        cnt = Counter()
        logs.sort(key=lambda x: x[1])
        ans = [0] * len(queries)
        j = k = 0
        for r, i in sorted(zip(queries, count())):
            l = r - x
            while k < len(logs) and logs[k][1] <= r:
                cnt[logs[k][0]] += 1
                k += 1
            while j < len(logs) and logs[j][1] < l:
                cnt[logs[j][0]] -= 1
                if cnt[logs[j][0]] == 0:
                    cnt.pop(logs[j][0])
                j += 1
            ans[i] = n - len(cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        Arrays.sort(logs, (a, b) -> a[1] - b[1]);
        int m = queries.length;
        int[][] qs = new int[m][0];
        for (int i = 0; i < m; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[m];
        int j = 0, k = 0;
        for (var q : qs) {
            int r = q[0], i = q[1];
            int l = r - x;
            while (k < logs.length && logs[k][1] <= r) {
                cnt.merge(logs[k++][0], 1, Integer::sum);
            }
            while (j < logs.length && logs[j][1] < l) {
                if (cnt.merge(logs[j][0], -1, Integer::sum) == 0) {
                    cnt.remove(logs[j][0]);
                }
                j++;
            }
            ans[i] = n - cnt.size();
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
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<pair<int, int>> qs(m);
        for (int i = 0; i < m; ++i) {
            qs[i] = {queries[i], i};
        }
        sort(qs.begin(), qs.end());
        unordered_map<int, int> cnt;
        vector<int> ans(m);
        int j = 0, k = 0;
        for (auto& [r, i] : qs) {
            int l = r - x;
            while (k < logs.size() && logs[k][1] <= r) {
                ++cnt[logs[k++][0]];
            }
            while (j < logs.size() && logs[j][1] < l) {
                if (--cnt[logs[j][0]] == 0) {
                    cnt.erase(logs[j][0]);
                }
                ++j;
            }
            ans[i] = n - cnt.size();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countServers(n int, logs [][]int, x int, queries []int) []int {
	sort.Slice(logs, func(i, j int) bool { return logs[i][1] < logs[j][1] })
	m := len(queries)
	qs := make([][2]int, m)
	for i, q := range queries {
		qs[i] = [2]int{q, i}
	}
	sort.Slice(qs, func(i, j int) bool { return qs[i][0] < qs[j][0] })
	cnt := map[int]int{}
	ans := make([]int, m)
	j, k := 0, 0
	for _, q := range qs {
		r, i := q[0], q[1]
		l := r - x
		for k < len(logs) && logs[k][1] <= r {
			cnt[logs[k][0]]++
			k++
		}
		for j < len(logs) && logs[j][1] < l {
			cnt[logs[j][0]]--
			if cnt[logs[j][0]] == 0 {
				delete(cnt, logs[j][0])
			}
			j++
		}
		ans[i] = n - len(cnt)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countServers(n: number, logs: number[][], x: number, queries: number[]): number[] {
    logs.sort((a, b) => a[1] - b[1]);
    const m = queries.length;
    const qs: number[][] = [];
    for (let i = 0; i < m; ++i) {
        qs.push([queries[i], i]);
    }
    qs.sort((a, b) => a[0] - b[0]);
    const cnt: Map<number, number> = new Map();
    const ans: number[] = new Array(m);
    let j = 0;
    let k = 0;
    for (const [r, i] of qs) {
        const l = r - x;
        while (k < logs.length && logs[k][1] <= r) {
            cnt.set(logs[k][0], (cnt.get(logs[k][0]) || 0) + 1);
            ++k;
        }
        while (j < logs.length && logs[j][1] < l) {
            cnt.set(logs[j][0], (cnt.get(logs[j][0]) || 0) - 1);
            if (cnt.get(logs[j][0]) === 0) {
                cnt.delete(logs[j][0]);
            }
            ++j;
        }
        ans[i] = n - cnt.size;
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

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示服务器的总数目，再给你一个下标从 <strong>0</strong>&nbsp;开始的 <strong>二维</strong>&nbsp;整数数组&nbsp;<code>logs</code>&nbsp;，其中&nbsp;<code>logs[i] = [server_id, time]</code>&nbsp;表示 id 为&nbsp;<code>server_id</code>&nbsp;的服务器在&nbsp;<code>time</code>&nbsp;时收到了一个请求。</p>

<p>同时给你一个整数&nbsp;<code>x</code>&nbsp;和一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>queries</code>&nbsp; 。</p>

<p>请你返回一个长度等于&nbsp;<code>queries.length</code>&nbsp;的数组&nbsp;<code>arr</code>&nbsp;，其中&nbsp;<code>arr[i]</code>&nbsp;表示在时间区间&nbsp;<code>[queries[i] - x, queries[i]]</code>&nbsp;内没有收到请求的服务器数目。</p>

<p>注意时间区间是个闭区间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
<b>输出：</b>[1,2]
<b>解释：</b>
对于 queries[0]：id 为 1 和 2 的服务器在区间 [5, 10] 内收到了请求，所以只有服务器 3 没有收到请求。
对于 queries[1]：id 为 2 的服务器在区间 [6,11] 内收到了请求，所以 id 为 1 和 3 的服务器在这个时间段内没有收到请求。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]
<b>输出：</b>[0,1]
<b>解释：</b>
对于 queries[0]：区间 [1, 3] 内所有服务器都收到了请求。
对于 queries[1]：只有 id 为 3 的服务器在区间 [2,4] 内没有收到请求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= logs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>logs[i].length == 2</code></li>
	<li><code>1 &lt;= logs[i][0] &lt;= n</code></li>
	<li><code>1 &lt;= logs[i][1] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= x &lt;= 10<sup>5</sup></code></li>
	<li><code>x &lt;&nbsp;queries[i]&nbsp;&lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离线查询 + 排序 + 双指针

我们可以将所有的查询按照时间从小到大排序，然后按照时间顺序依次处理每个查询。

对于每个查询 $q = (r, i)$，其窗口左边界为 $l = r - x$，我们需要统计在窗口 $[l, r]$ 内有多少个服务器收到了请求。我们用双指针 $j$ 和 $k$ 分别维护窗口的左右边界，初始时 $j = k = 0$。每一次，如果 $k$ 指向的日志的时间小于等于 $r$，我们就将其加入到窗口中，然后将 $k$ 向右移动一位。如果 $j$ 指向的日志的时间小于 $l$，我们就将其从窗口中移除，然后将 $j$ 向右移动一位。在移动的过程中，我们需要统计窗口中有多少个不同的服务器，这可以使用哈希表来实现。移动结束后，当前时间区间中没有收到请求的服务器数目就是 $n$ 减去哈希表中不同的服务器数目。

时间复杂度 $O(l \times \log l + m \times \log m + n)$，空间复杂度 $O(l + m)$。其中 $l$ 和 $n$ 分别是数组 $\textit{logs}$ 的长度和服务器的数量，而 $m$ 是数组 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countServers(
        self, n: int, logs: List[List[int]], x: int, queries: List[int]
    ) -> List[int]:
        cnt = Counter()
        logs.sort(key=lambda x: x[1])
        ans = [0] * len(queries)
        j = k = 0
        for r, i in sorted(zip(queries, count())):
            l = r - x
            while k < len(logs) and logs[k][1] <= r:
                cnt[logs[k][0]] += 1
                k += 1
            while j < len(logs) and logs[j][1] < l:
                cnt[logs[j][0]] -= 1
                if cnt[logs[j][0]] == 0:
                    cnt.pop(logs[j][0])
                j += 1
            ans[i] = n - len(cnt)
        return ans
```

#### Java

```java
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        Arrays.sort(logs, (a, b) -> a[1] - b[1]);
        int m = queries.length;
        int[][] qs = new int[m][0];
        for (int i = 0; i < m; ++i) {
            qs[i] = new int[] {queries[i], i};
        }
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[m];
        int j = 0, k = 0;
        for (var q : qs) {
            int r = q[0], i = q[1];
            int l = r - x;
            while (k < logs.length && logs[k][1] <= r) {
                cnt.merge(logs[k++][0], 1, Integer::sum);
            }
            while (j < logs.length && logs[j][1] < l) {
                if (cnt.merge(logs[j][0], -1, Integer::sum) == 0) {
                    cnt.remove(logs[j][0]);
                }
                j++;
            }
            ans[i] = n - cnt.size();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<pair<int, int>> qs(m);
        for (int i = 0; i < m; ++i) {
            qs[i] = {queries[i], i};
        }
        sort(qs.begin(), qs.end());
        unordered_map<int, int> cnt;
        vector<int> ans(m);
        int j = 0, k = 0;
        for (auto& [r, i] : qs) {
            int l = r - x;
            while (k < logs.size() && logs[k][1] <= r) {
                ++cnt[logs[k++][0]];
            }
            while (j < logs.size() && logs[j][1] < l) {
                if (--cnt[logs[j][0]] == 0) {
                    cnt.erase(logs[j][0]);
                }
                ++j;
            }
            ans[i] = n - cnt.size();
        }
        return ans;
    }
};
```

#### Go

```go
func countServers(n int, logs [][]int, x int, queries []int) []int {
	sort.Slice(logs, func(i, j int) bool { return logs[i][1] < logs[j][1] })
	m := len(queries)
	qs := make([][2]int, m)
	for i, q := range queries {
		qs[i] = [2]int{q, i}
	}
	sort.Slice(qs, func(i, j int) bool { return qs[i][0] < qs[j][0] })
	cnt := map[int]int{}
	ans := make([]int, m)
	j, k := 0, 0
	for _, q := range qs {
		r, i := q[0], q[1]
		l := r - x
		for k < len(logs) && logs[k][1] <= r {
			cnt[logs[k][0]]++
			k++
		}
		for j < len(logs) && logs[j][1] < l {
			cnt[logs[j][0]]--
			if cnt[logs[j][0]] == 0 {
				delete(cnt, logs[j][0])
			}
			j++
		}
		ans[i] = n - len(cnt)
	}
	return ans
}
```

#### TypeScript

```ts
function countServers(n: number, logs: number[][], x: number, queries: number[]): number[] {
    logs.sort((a, b) => a[1] - b[1]);
    const m = queries.length;
    const qs: number[][] = [];
    for (let i = 0; i < m; ++i) {
        qs.push([queries[i], i]);
    }
    qs.sort((a, b) => a[0] - b[0]);
    const cnt: Map<number, number> = new Map();
    const ans: number[] = new Array(m);
    let j = 0;
    let k = 0;
    for (const [r, i] of qs) {
        const l = r - x;
        while (k < logs.length && logs[k][1] <= r) {
            cnt.set(logs[k][0], (cnt.get(logs[k][0]) || 0) + 1);
            ++k;
        }
        while (j < logs.length && logs[j][1] < l) {
            cnt.set(logs[j][0], (cnt.get(logs[j][0]) || 0) - 1);
            if (cnt.get(logs[j][0]) === 0) {
                cnt.delete(logs[j][0]);
            }
            ++j;
        }
        ans[i] = n - cnt.size;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2748. 美丽下标对的数目](https://leetcode.cn/problems/number-of-beautiful-pairs){#2748}

{{< tabs "2748" >}}

{{% tab "python" %}}
```python
class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        cnt = [0] * 10
        ans = 0
        for x in nums:
            for y in range(10):
                if cnt[y] and gcd(x % 10, y) == 1:
                    ans += cnt[y]
            cnt[int(str(x)[0])] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countBeautifulPairs(int[] nums) {
        int[] cnt = new int[10];
        int ans = 0;
        for (int x : nums) {
            for (int y = 0; y < 10; ++y) {
                if (cnt[y] > 0 && gcd(x % 10, y) == 1) {
                    ans += cnt[y];
                }
            }
            while (x > 9) {
                x /= 10;
            }
            ++cnt[x];
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt[10]{};
        int ans = 0;
        for (int x : nums) {
            for (int y = 0; y < 10; ++y) {
                if (cnt[y] && gcd(x % 10, y) == 1) {
                    ans += cnt[y];
                }
            }
            while (x > 9) {
                x /= 10;
            }
            ++cnt[x];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countBeautifulPairs(nums []int) (ans int) {
	cnt := [10]int{}
	for _, x := range nums {
		for y := 0; y < 10; y++ {
			if cnt[y] > 0 && gcd(x%10, y) == 1 {
				ans += cnt[y]
			}
		}
		for x > 9 {
			x /= 10
		}
		cnt[x]++
	}
	return
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countBeautifulPairs(nums: number[]): number {
    const cnt: number[] = Array(10).fill(0);
    let ans = 0;
    for (let x of nums) {
        for (let y = 0; y < 10; ++y) {
            if (cnt[y] > 0 && gcd(x % 10, y) === 1) {
                ans += cnt[y];
            }
        }
        while (x > 9) {
            x = Math.floor(x / 10);
        }
        ++cnt[x];
    }
    return ans;
}

function gcd(a: number, b: number): number {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。如果下标对 <code>i</code>、<code>j</code> 满足 <code>0 ≤ i &lt; j &lt; nums.length</code> ，如果&nbsp;<code>nums[i]</code> 的 <strong>第一个数字</strong> 和 <code>nums[j]</code> 的 <strong>最后一个数字</strong> <strong>互质</strong> ，则认为 <code>nums[i]</code> 和 <code>nums[j]</code> 是一组 <strong>美丽下标对</strong> 。</p>

<p>返回 <code>nums</code> 中 <strong>美丽下标对</strong> 的总数目。</p>

<p>对于两个整数 <code>x</code> 和 <code>y</code> ，如果不存在大于 1 的整数可以整除它们，则认为 <code>x</code> 和 <code>y</code> <strong>互质</strong> 。换而言之，如果 <code>gcd(x, y) == 1</code> ，则认为 <code>x</code> 和 <code>y</code> 互质，其中 <code>gcd(x, y)</code> 是 <code>x</code> 和 <code>y</code>&nbsp;的&nbsp;<strong>最大公因数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,5,1,4]
<strong>输出：</strong>5
<strong>解释：</strong>nums 中共有 5 组美丽下标对：
i = 0 和 j = 1 ：nums[0] 的第一个数字是 2 ，nums[1] 的最后一个数字是 5 。2 和 5 互质，因此 gcd(2,5) == 1 。
i = 0 和 j = 2 ：nums[0] 的第一个数字是 2 ，nums[2] 的最后一个数字是 1 。2 和 1 互质，因此 gcd(2,1) == 1 。
i = 1 和 j = 2 ：nums[1] 的第一个数字是 5 ，nums[2] 的最后一个数字是 1 。5 和 1 互质，因此 gcd(5,1) == 1 。
i = 1 和 j = 3 ：nums[1] 的第一个数字是 5 ，nums[3] 的最后一个数字是 4 。5 和 4 互质，因此 gcd(5,4) == 1 。
i = 2 和 j = 3 ：nums[2] 的第一个数字是 1 ，nums[3] 的最后一个数字是 4 。1 和 4 互质，因此 gcd(1,4) == 1 。
因此，返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [11,21,12]
<strong>输出：</strong>2
<strong>解释：</strong>共有 2 组美丽下标对：
i = 0 和 j = 1 ：nums[0] 的第一个数字是 1 ，nums[1] 的最后一个数字是 1 。gcd(1,1) == 1 。
i = 0 和 j = 2 ：nums[0] 的第一个数字是 1 ，nums[2] 的最后一个数字是 2 。gcd(1,2) == 1 。
因此，返回 2 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 9999</code></li>
	<li><code>nums[i] % 10 != 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个长度为 $10$ 的数组 $\textit{cnt}$ 来记录每个数字的第一个数字出现的次数。

遍历数组 $\textit{nums}$，对于每个数字 $x$，我们枚举 $0$ 到 $9$ 的每个数字 $y$，如果 $\textit{cnt}[y]$ 不为 $0$ 且 $\textit{gcd}(x b\mod 10, y) = 1$，则答案加上 $\textit{cnt}[y]$。然后，我们将 $x$ 的第一个数字出现的次数加 $1$。

遍历结束后，返回答案即可。

时间复杂度 $O(n \times (k + \log M))$，空间复杂度 $O(k + \log M)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $k$ 和 $M$ 分别表示数组 $\textit{nums}$ 中的数字的种类以及最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        cnt = [0] * 10
        ans = 0
        for x in nums:
            for y in range(10):
                if cnt[y] and gcd(x % 10, y) == 1:
                    ans += cnt[y]
            cnt[int(str(x)[0])] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countBeautifulPairs(int[] nums) {
        int[] cnt = new int[10];
        int ans = 0;
        for (int x : nums) {
            for (int y = 0; y < 10; ++y) {
                if (cnt[y] > 0 && gcd(x % 10, y) == 1) {
                    ans += cnt[y];
                }
            }
            while (x > 9) {
                x /= 10;
            }
            ++cnt[x];
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt[10]{};
        int ans = 0;
        for (int x : nums) {
            for (int y = 0; y < 10; ++y) {
                if (cnt[y] && gcd(x % 10, y) == 1) {
                    ans += cnt[y];
                }
            }
            while (x > 9) {
                x /= 10;
            }
            ++cnt[x];
        }
        return ans;
    }
};
```

#### Go

```go
func countBeautifulPairs(nums []int) (ans int) {
	cnt := [10]int{}
	for _, x := range nums {
		for y := 0; y < 10; y++ {
			if cnt[y] > 0 && gcd(x%10, y) == 1 {
				ans += cnt[y]
			}
		}
		for x > 9 {
			x /= 10
		}
		cnt[x]++
	}
	return
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function countBeautifulPairs(nums: number[]): number {
    const cnt: number[] = Array(10).fill(0);
    let ans = 0;
    for (let x of nums) {
        for (let y = 0; y < 10; ++y) {
            if (cnt[y] > 0 && gcd(x % 10, y) === 1) {
                ans += cnt[y];
            }
        }
        while (x > 9) {
            x = Math.floor(x / 10);
        }
        ++cnt[x];
    }
    return ans;
}

function gcd(a: number, b: number): number {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2749. 得到整数零需要执行的最少操作数](https://leetcode.cn/problems/minimum-operations-to-make-the-integer-zero){#2749}

{{< tabs "2749" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for k in count(1):
            x = num1 - k * num2
            if x < 0:
                break
            if x.bit_count() <= k <= x:
                return k
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int makeTheIntegerZero(int num1, int num2) {
        for (long k = 1;; ++k) {
            long x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (Long.bitCount(x) <= k && k <= x) {
                return (int) k;
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
    int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
        for (ll k = 1;; ++k) {
            ll x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (__builtin_popcountll(x) <= k && k <= x) {
                return k;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeTheIntegerZero(num1 int, num2 int) int {
	for k := 1; ; k++ {
		x := num1 - k*num2
		if x < 0 {
			break
		}
		if bits.OnesCount(uint(x)) <= k && k <= x {
			return k
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeTheIntegerZero(num1: number, num2: number): number {
    for (let k = 1; ; ++k) {
        let x = num1 - k * num2;
        if (x < 0) {
            break;
        }
        if (x.toString(2).replace(/0/g, '').length <= k && k <= x) {
            return k;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {
        let num1 = num1 as i64;
        let num2 = num2 as i64;
        for k in 1.. {
            let x = num1 - k * num2;
            if x < 0 {
                break;
            }
            if (x.count_ones() as i64) <= k && k <= x {
                return k as i32;
            }
        }
        -1
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MakeTheIntegerZero(int num1, int num2) {
        long a = num1, b = num2;
        for (long k = 1; ; ++k) {
            long x = a - k * b;
            if (x < 0) {
                break;
            }
            if (BitOperations.PopCount((ulong)x) <= k && k <= x) {
                return (int)k;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数：<code>num1</code> 和 <code>num2</code> 。</p>

<p>在一步操作中，你需要从范围&nbsp;<code>[0, 60]</code> 中选出一个整数 <code>i</code> ，并从 <code>num1</code> 减去 <code>2<sup>i</sup> + num2</code> 。</p>

<p>请你计算，要想使 <code>num1</code> 等于 <code>0</code> 需要执行的最少操作数，并以整数形式返回。</p>

<p>如果无法使 <code>num1</code> 等于 <code>0</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 3, num2 = -2
<strong>输出：</strong>3
<strong>解释：</strong>可以执行下述步骤使 3 等于 0 ：
- 选择 i = 2 ，并从 3 减去 2<sup>2</sup> + (-2) ，num1 = 3 - (4 + (-2)) = 1 。
- 选择 i = 2 ，并从 1 减去 2<sup>2</sup> + (-2) ，num1 = 1 - (4 + (-2)) = -1 。
- 选择 i = 0 ，并从 -1 减去 2<sup>0</sup>&nbsp;+ (-2) ，num1 = (-1) - (1 + (-2)) = 0 。
可以证明 3 是需要执行的最少操作数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = 5, num2 = 7
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明，执行操作无法使 5 等于 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1 &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= num2 &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

如果我们操作了 $k$ 次，那么问题实际上就变成了：判断 $\textit{num1} - k \times \textit{num2}$ 能否拆分成 $k$ 个 $2^i$ 之和。

我们不妨假设 $x = \textit{num1} - k \times \textit{num2}$，接下来分类讨论：

-   如果 $x \lt 0$，那么 $x$ 无法拆分成 $k$ 个 $2^i$ 之和，因为 $2^i \gt 0$，显然无解；
-   如果 $x$ 的二进制表示中 $1$ 的个数大于 $k$，此时也是无解；
-   否则，对于当前 $k$，一定存在一个拆分方案。

因此，我们从 $1$ 开始枚举 $k$，一旦找到一个满足条件的 $k$，就可以直接返回答案。

时间复杂度 $O(\log x)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for k in count(1):
            x = num1 - k * num2
            if x < 0:
                break
            if x.bit_count() <= k <= x:
                return k
        return -1
```

#### Java

```java
class Solution {
    public int makeTheIntegerZero(int num1, int num2) {
        for (long k = 1;; ++k) {
            long x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (Long.bitCount(x) <= k && k <= x) {
                return (int) k;
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
    int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
        for (ll k = 1;; ++k) {
            ll x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (__builtin_popcountll(x) <= k && k <= x) {
                return k;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func makeTheIntegerZero(num1 int, num2 int) int {
	for k := 1; ; k++ {
		x := num1 - k*num2
		if x < 0 {
			break
		}
		if bits.OnesCount(uint(x)) <= k && k <= x {
			return k
		}
	}
	return -1
}
```

#### TypeScript

```ts
function makeTheIntegerZero(num1: number, num2: number): number {
    for (let k = 1; ; ++k) {
        let x = num1 - k * num2;
        if (x < 0) {
            break;
        }
        if (x.toString(2).replace(/0/g, '').length <= k && k <= x) {
            return k;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {
        let num1 = num1 as i64;
        let num2 = num2 as i64;
        for k in 1.. {
            let x = num1 - k * num2;
            if x < 0 {
                break;
            }
            if (x.count_ones() as i64) <= k && k <= x {
                return k as i32;
            }
        }
        -1
    }
}
```

#### C#

```cs
public class Solution {
    public int MakeTheIntegerZero(int num1, int num2) {
        long a = num1, b = num2;
        for (long k = 1; ; ++k) {
            long x = a - k * b;
            if (x < 0) {
                break;
            }
            if (BitOperations.PopCount((ulong)x) <= k && k <= x) {
                return (int)k;
            }
        }
        return -1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
