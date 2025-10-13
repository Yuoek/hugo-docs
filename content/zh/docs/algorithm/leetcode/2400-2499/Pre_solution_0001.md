---
title: "2400_恰好移动 k 步到达某一位置的方法数目"
date: 2025-10-08T18:39:18+08:00
weight: 1
tags: [位运算, 分治, 前缀和, 动态规划, 单调队列, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数组, 树状数组, 模拟, 滑动窗口, 状态压缩, 线段树, 组合数学, 计数, 设计, 贪心, 队列]
---

{{< markmap >}}
### [2400_恰好移动 k 步到达某一位置的方法数目](#2400)
#### [数学](#2400)
#### [动态规划](#2400)
#### [组合数学](#2400)
### [2401_最长优雅子数组](#2401)
#### [位运算](#2401)
#### [数组](#2401)
#### [滑动窗口](#2401)
### [2402_会议室 III](#2402)
#### [数组](#2402)
#### [哈希表](#2402)
#### [排序](#2402)
#### [模拟](#2402)
#### [堆（优先队列）](#2402)
### [2403_杀死所有怪物的最短时间 🔒](#2403)
#### [位运算](#2403)
#### [数组](#2403)
#### [动态规划](#2403)
#### [状态压缩](#2403)
### [2404_出现最频繁的偶数元素](#2404)
#### [数组](#2404)
#### [哈希表](#2404)
#### [计数](#2404)
### [2405_子字符串的最优划分](#2405)
#### [贪心](#2405)
#### [哈希表](#2405)
#### [字符串](#2405)
### [2406_将区间分为最少组数](#2406)
#### [贪心](#2406)
#### [数组](#2406)
#### [双指针](#2406)
#### [前缀和](#2406)
#### [排序](#2406)
#### [堆（优先队列）](#2406)
### [2407_最长递增子序列 II](#2407)
#### [树状数组](#2407)
#### [线段树](#2407)
#### [队列](#2407)
#### [数组](#2407)
#### [分治](#2407)
#### [动态规划](#2407)
#### [单调队列](#2407)
### [2408_设计 SQL 🔒](#2408)
#### [设计](#2408)
#### [数组](#2408)
#### [哈希表](#2408)
#### [字符串](#2408)
### [2409_统计共同度过的日子数](#2409)
#### [数学](#2409)
#### [字符串](#2409)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2400_恰好移动 k 步到达某一位置的方法数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 2401_最长优雅子数组
___
#### 位运算
___
#### 数组
___
#### 滑动窗口
---
### 2402_会议室 III
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 2403_杀死所有怪物的最短时间 🔒
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 2404_出现最频繁的偶数元素
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2405_子字符串的最优划分
___
#### 贪心
___
#### 哈希表
___
#### 字符串
---
### 2406_将区间分为最少组数
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 前缀和
___
#### 排序
___
#### 堆（优先队列）
---
### 2407_最长递增子序列 II
___
#### 树状数组
___
#### 线段树
___
#### 队列
___
#### 数组
___
#### 分治
___
#### 动态规划
___
#### 单调队列
---
### 2408_设计 SQL 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 2409_统计共同度过的日子数
___
#### 数学
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 分治 | 前缀和 |
| 动态规划 | 单调队列 | 双指针 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数组 |
| 树状数组 | 模拟 | 滑动窗口 |
| 状态压缩 | 线段树 | 组合数学 |
| 计数 | 设计 | 贪心 |
| 队列 |  |  |

# [2400. 恰好移动 k 步到达某一位置的方法数目](https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps){#2400}

{{< tabs "2400" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j or j < 0:
                return 0
            if j == 0:
                return 1 if i == 0 else 0
            return (dfs(i + 1, j - 1) + dfs(abs(i - 1), j - 1)) % mod

        mod = 10**9 + 7
        return dfs(abs(startPos - endPos), k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private final int mod = (int) 1e9 + 7;

    public int numberOfWays(int startPos, int endPos, int k) {
        f = new Integer[k + 1][k + 1];
        return dfs(Math.abs(startPos - endPos), k);
    }

    private int dfs(int i, int j) {
        if (i > j || j < 0) {
            return 0;
        }
        if (j == 0) {
            return i == 0 ? 1 : 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = dfs(i + 1, j - 1) + dfs(Math.abs(i - 1), j - 1);
        ans %= mod;
        return f[i][j] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        const int mod = 1e9 + 7;
        int f[k + 1][k + 1];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i > j || j < 0) {
                return 0;
            }
            if (j == 0) {
                return i == 0 ? 1 : 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            f[i][j] = (dfs(i + 1, j - 1) + dfs(abs(i - 1), j - 1)) % mod;
            return f[i][j];
        };
        return dfs(abs(startPos - endPos), k);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(startPos int, endPos int, k int) int {
	const mod = 1e9 + 7
	f := make([][]int, k+1)
	for i := range f {
		f[i] = make([]int, k+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i > j || j < 0 {
			return 0
		}
		if j == 0 {
			if i == 0 {
				return 1
			}
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		f[i][j] = (dfs(i+1, j-1) + dfs(abs(i-1), j-1)) % mod
		return f[i][j]
	}
	return dfs(abs(startPos-endPos), k)
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
function numberOfWays(startPos: number, endPos: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f = new Array(k + 1).fill(0).map(() => new Array(k + 1).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i > j || j < 0) {
            return 0;
        }
        if (j === 0) {
            return i === 0 ? 1 : 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        f[i][j] = dfs(i + 1, j - 1) + dfs(Math.abs(i - 1), j - 1);
        f[i][j] %= mod;
        return f[i][j];
    };
    return dfs(Math.abs(startPos - endPos), k);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个 <strong>正</strong> 整数 <code>startPos</code> 和 <code>endPos</code> 。最初，你站在 <strong>无限</strong> 数轴上位置 <code>startPos</code> 处。在一步移动中，你可以向左或者向右移动一个位置。</p>

<p>给你一个正整数 <code>k</code> ，返回从 <code>startPos</code> 出发、<strong>恰好</strong> 移动 <code>k</code> 步并到达 <code>endPos</code> 的 <strong>不同</strong> 方法数目。由于答案可能会很大，返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p>如果所执行移动的顺序不完全相同，则认为两种方法不同。</p>

<p><strong>注意：</strong>数轴包含负整数<strong>。</strong></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>startPos = 1, endPos = 2, k = 3
<strong>输出：</strong>3
<strong>解释：</strong>存在 3 种从 1 到 2 且恰好移动 3 步的方法：
- 1 -&gt; 2 -&gt; 3 -&gt; 2.
- 1 -&gt; 2 -&gt; 1 -&gt; 2.
- 1 -&gt; 0 -&gt; 1 -&gt; 2.
可以证明不存在其他方法，所以返回 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>startPos = 2, endPos = 5, k = 10
<strong>输出：</strong>0
<strong>解释：</strong>不存在从 2 到 5 且恰好移动 10 步的方法。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= startPos, endPos, k &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示当前位置距离目标位置的距离为 $i$，还剩 $j$ 步，有多少种方法到达目标位置。那么答案就是 $dfs(abs(startPos - endPos), k)$。

函数 $dfs(i, j)$ 的计算方式如下：

-   如果 $i \gt j$ 或者 $j \lt 0$，说明当前位置距离目标位置的距离大于剩余步数，或者剩余步数为负数，此时无法到达目标位置，返回 $0$；
-   如果 $j = 0$，说明剩余步数为 $0$，此时只有当前位置距离目标位置的距离为 $0$ 时才能到达目标位置，否则无法到达目标位置，返回 $1$ 或者 $0$；
-   否则，当前位置距离目标位置的距离为 $i$，还剩 $j$ 步，那么有两种方法到达目标位置：
    -   向左移动一步，此时当前位置距离目标位置的距离为 $i + 1$，还剩 $j - 1$ 步，方法数为 $dfs(i + 1, j - 1)$；
    -   向右移动一步，此时当前位置距离目标位置的距离为 $abs(i - 1)$，还剩 $j - 1$ 步，方法数为 $dfs(abs(i - 1), j - 1)$；
-   最后，返回两种方法的和对 $10^9 + 7$ 取余的结果。

为了避免重复计算，我们使用记忆化搜索，即使用一个二维数组 $f$ 记录函数 $dfs(i, j)$ 的结果，当函数 $dfs(i, j)$ 被调用时，如果 $f[i][j]$ 不为 $-1$，则直接返回 $f[i][j]$，否则计算 $f[i][j]$ 的值，并返回 $f[i][j]$。

时间复杂度 $O(k^2)$，空间复杂度 $O(k^2)$。其中 $k$ 为题目给定的步数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j or j < 0:
                return 0
            if j == 0:
                return 1 if i == 0 else 0
            return (dfs(i + 1, j - 1) + dfs(abs(i - 1), j - 1)) % mod

        mod = 10**9 + 7
        return dfs(abs(startPos - endPos), k)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private final int mod = (int) 1e9 + 7;

    public int numberOfWays(int startPos, int endPos, int k) {
        f = new Integer[k + 1][k + 1];
        return dfs(Math.abs(startPos - endPos), k);
    }

    private int dfs(int i, int j) {
        if (i > j || j < 0) {
            return 0;
        }
        if (j == 0) {
            return i == 0 ? 1 : 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = dfs(i + 1, j - 1) + dfs(Math.abs(i - 1), j - 1);
        ans %= mod;
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        const int mod = 1e9 + 7;
        int f[k + 1][k + 1];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i > j || j < 0) {
                return 0;
            }
            if (j == 0) {
                return i == 0 ? 1 : 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            f[i][j] = (dfs(i + 1, j - 1) + dfs(abs(i - 1), j - 1)) % mod;
            return f[i][j];
        };
        return dfs(abs(startPos - endPos), k);
    }
};
```

#### Go

```go
func numberOfWays(startPos int, endPos int, k int) int {
	const mod = 1e9 + 7
	f := make([][]int, k+1)
	for i := range f {
		f[i] = make([]int, k+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i > j || j < 0 {
			return 0
		}
		if j == 0 {
			if i == 0 {
				return 1
			}
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		f[i][j] = (dfs(i+1, j-1) + dfs(abs(i-1), j-1)) % mod
		return f[i][j]
	}
	return dfs(abs(startPos-endPos), k)
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
function numberOfWays(startPos: number, endPos: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f = new Array(k + 1).fill(0).map(() => new Array(k + 1).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i > j || j < 0) {
            return 0;
        }
        if (j === 0) {
            return i === 0 ? 1 : 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        f[i][j] = dfs(i + 1, j - 1) + dfs(Math.abs(i - 1), j - 1);
        f[i][j] %= mod;
        return f[i][j];
    };
    return dfs(Math.abs(startPos - endPos), k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2401. 最长优雅子数组](https://leetcode.cn/problems/longest-nice-subarray){#2401}

{{< tabs "2401" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans = mask = l = 0
        for r, x in enumerate(nums):
            while mask & x:
                mask ^= nums[l]
                l += 1
            mask |= x
            ans = max(ans, r - l + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestNiceSubarray(int[] nums) {
        int ans = 0, mask = 0;
        for (int l = 0, r = 0; r < nums.length; ++r) {
            while ((mask & nums[r]) != 0) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            ans = Math.max(ans, r - l + 1);
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
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, mask = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (mask & nums[r]) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestNiceSubarray(nums []int) (ans int) {
	mask, l := 0, 0
	for r, x := range nums {
		for mask&x != 0 {
			mask ^= nums[l]
			l++
		}
		mask |= x
		ans = max(ans, r-l+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestNiceSubarray(nums: number[]): number {
    let [ans, mask] = [0, 0];
    for (let l = 0, r = 0; r < nums.length; ++r) {
        while (mask & nums[r]) {
            mask ^= nums[l++];
        }
        mask |= nums[r];
        ans = Math.max(ans, r - l + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mask = 0;
        let mut l = 0;
        for (r, &x) in nums.iter().enumerate() {
            while mask & x != 0 {
                mask ^= nums[l];
                l += 1;
            }
            mask |= x;
            ans = ans.max((r - l + 1) as i32);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LongestNiceSubarray(int[] nums) {
        int ans = 0, mask = 0;
        for (int l = 0, r = 0; r < nums.Length; ++r) {
            while ((mask & nums[r]) != 0) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            ans = Math.Max(ans, r - l + 1);
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

<p>给你一个由 <strong>正</strong> 整数组成的数组 <code>nums</code> 。</p>

<p>如果&nbsp;<code>nums</code> 的子数组中位于 <strong>不同</strong> 位置的每对元素按位 <strong>与（AND）</strong>运算的结果等于 <code>0</code> ，则称该子数组为 <strong>优雅</strong> 子数组。</p>

<p>返回 <strong>最长</strong> 的优雅子数组的长度。</p>

<p><strong>子数组</strong> 是数组中的一个 <strong>连续</strong> 部分。</p>

<p><strong>注意：</strong>长度为 <code>1</code> 的子数组始终视作优雅子数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,8,48,10]
<strong>输出：</strong>3
<strong>解释：</strong>最长的优雅子数组是 [3,8,48] 。子数组满足题目条件：
- 3 AND 8 = 0
- 3 AND 48 = 0
- 8 AND 48 = 0
可以证明不存在更长的优雅子数组，所以返回 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [3,1,5,11,13]
<strong>输出：</strong>1
<strong>解释：</strong>最长的优雅子数组长度为 1 ，任何长度为 1 的子数组都满足题目条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

根据题目描述，子数组的每个元素的二进制位上的 $1$ 的位置不能相同，这样才能保证任意两个元素的按位与结果为 $0$。

因此，我们可以使用双指针 $l$ 和 $r$ 维护一个滑动窗口，使得窗口内的元素满足题目条件。

我们用一个变量 $\textit{mask}$ 来表示窗口内的元素的按位或的结果，接下来，遍历数组的每个元素。对于当前元素 $x$，如果 $\textit{mask}$ 和 $x$ 的按位与结果不为 $0$，说明当前元素 $x$ 与窗口内的元素有重复的二进制位，此时需要移动左指针 $l$，直到 $\textit{mask}$ 和 $x$ 的按位与结果为 $0$。然后，我们将 $\textit{mask}$ 和 $x$ 的按位或的结果赋值给 $\textit{mask}$，并更新答案 $\textit{ans} = \max(\textit{ans}, r - l + 1)$。

遍历结束后，返回答案 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans = mask = l = 0
        for r, x in enumerate(nums):
            while mask & x:
                mask ^= nums[l]
                l += 1
            mask |= x
            ans = max(ans, r - l + 1)
        return ans
```

#### Java

```java
class Solution {
    public int longestNiceSubarray(int[] nums) {
        int ans = 0, mask = 0;
        for (int l = 0, r = 0; r < nums.length; ++r) {
            while ((mask & nums[r]) != 0) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, mask = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (mask & nums[r]) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func longestNiceSubarray(nums []int) (ans int) {
	mask, l := 0, 0
	for r, x := range nums {
		for mask&x != 0 {
			mask ^= nums[l]
			l++
		}
		mask |= x
		ans = max(ans, r-l+1)
	}
	return
}
```

#### TypeScript

```ts
function longestNiceSubarray(nums: number[]): number {
    let [ans, mask] = [0, 0];
    for (let l = 0, r = 0; r < nums.length; ++r) {
        while (mask & nums[r]) {
            mask ^= nums[l++];
        }
        mask |= nums[r];
        ans = Math.max(ans, r - l + 1);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mask = 0;
        let mut l = 0;
        for (r, &x) in nums.iter().enumerate() {
            while mask & x != 0 {
                mask ^= nums[l];
                l += 1;
            }
            mask |= x;
            ans = ans.max((r - l + 1) as i32);
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int LongestNiceSubarray(int[] nums) {
        int ans = 0, mask = 0;
        for (int l = 0, r = 0; r < nums.Length; ++r) {
            while ((mask & nums[r]) != 0) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            ans = Math.Max(ans, r - l + 1);
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

# [2402. 会议室 III](https://leetcode.cn/problems/meeting-rooms-iii){#2402}

{{< tabs "2402" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        busy = []
        idle = list(range(n))
        heapify(idle)
        cnt = [0] * n
        for s, e in meetings:
            while busy and busy[0][0] <= s:
                heappush(idle, heappop(busy)[1])
            if idle:
                i = heappop(idle)
                cnt[i] += 1
                heappush(busy, (e, i))
            else:
                a, i = heappop(busy)
                cnt[i] += 1
                heappush(busy, (a + e - s, i))
        ans = 0
        for i, v in enumerate(cnt):
            if cnt[ans] < v:
                ans = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> busy
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        PriorityQueue<Integer> idle = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            idle.offer(i);
        }
        int[] cnt = new int[n];
        for (var v : meetings) {
            int s = v[0], e = v[1];
            while (!busy.isEmpty() && busy.peek()[0] <= s) {
                idle.offer(busy.poll()[1]);
            }
            int i = 0;
            if (!idle.isEmpty()) {
                i = idle.poll();
                busy.offer(new int[] {e, i});
            } else {
                var x = busy.poll();
                i = x[1];
                busy.offer(new int[] {x[0] + e - s, i});
            }
            ++cnt[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[ans] < cnt[i]) {
                ans = i;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;
using pii = pair<ll, int>;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> idle;
        priority_queue<pii, vector<pii>, greater<pii>> busy;
        for (int i = 0; i < n; ++i) idle.push(i);
        vector<int> cnt(n);
        sort(meetings.begin(), meetings.end());
        for (auto& v : meetings) {
            int s = v[0], e = v[1];
            while (!busy.empty() && busy.top().first <= s) {
                idle.push(busy.top().second);
                busy.pop();
            }
            int i = 0;
            if (!idle.empty()) {
                i = idle.top();
                idle.pop();
                busy.push({e, i});
            } else {
                auto x = busy.top();
                busy.pop();
                i = x.second;
                busy.push({x.first + e - s, i});
            }
            ++cnt[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[ans] < cnt[i]) {
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
func mostBooked(n int, meetings [][]int) int {
	sort.Slice(meetings, func(i, j int) bool { return meetings[i][0] < meetings[j][0] })
	idle := hp{make([]int, n)}
	for i := 0; i < n; i++ {
		idle.IntSlice[i] = i
	}
	busy := hp2{}
	cnt := make([]int, n)
	for _, v := range meetings {
		s, e := v[0], v[1]
		for len(busy) > 0 && busy[0].end <= s {
			heap.Push(&idle, heap.Pop(&busy).(pair).i)
		}
		var i int
		if idle.Len() > 0 {
			i = heap.Pop(&idle).(int)
			heap.Push(&busy, pair{e, i})
		} else {
			x := heap.Pop(&busy).(pair)
			i = x.i
			heap.Push(&busy, pair{x.end + e - s, i})
		}
		cnt[i]++
	}
	ans := 0
	for i, v := range cnt {
		if cnt[ans] < v {
			ans = i
		}
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

type pair struct{ end, i int }
type hp2 []pair

func (h hp2) Len() int { return len(h) }
func (h hp2) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.end < b.end || a.end == b.end && a.i < b.i
}
func (h hp2) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，共有编号从 <code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个会议室。</p>

<p>给你一个二维整数数组 <code>meetings</code> ，其中 <code>meetings[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示一场会议将会在 <strong>半闭</strong> 时间区间 <code>[start<sub>i</sub>, end<sub>i</sub>)</code> 举办。所有 <code>start<sub>i</sub></code> 的值 <strong>互不相同</strong> 。</p>

<p>会议将会按以下方式分配给会议室：</p>

<ol>
	<li>每场会议都会在未占用且编号 <strong>最小</strong> 的会议室举办。</li>
	<li>如果没有可用的会议室，会议将会延期，直到存在空闲的会议室。延期会议的持续时间和原会议持续时间 <strong>相同</strong> 。</li>
	<li>当会议室处于未占用状态时，将会优先提供给原 <strong>开始</strong> 时间更早的会议。</li>
</ol>

<p>返回举办最多次会议的房间 <strong>编号</strong> 。如果存在多个房间满足此条件，则返回编号 <strong>最小</strong> 的房间。</p>

<p><strong>半闭区间 </strong><code>[a, b)</code> 是 <code>a</code> 和 <code>b</code> 之间的区间，<strong>包括</strong> <code>a</code> 但<strong> 不包括</strong> <code>b</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
<strong>输出：</strong>0
<strong>解释：</strong>
- 在时间 0 ，两个会议室都未占用，第一场会议在会议室 0 举办。
- 在时间 1 ，只有会议室 1 未占用，第二场会议在会议室 1 举办。
- 在时间 2 ，两个会议室都被占用，第三场会议延期举办。
- 在时间 3 ，两个会议室都被占用，第四场会议延期举办。
- 在时间 5 ，会议室 1 的会议结束。第三场会议在会议室 1 举办，时间周期为 [5,10) 。
- 在时间 10 ，两个会议室的会议都结束。第四场会议在会议室 0 举办，时间周期为 [10,11) 。
会议室 0 和会议室 1 都举办了 2 场会议，所以返回 0 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
<strong>输出：</strong>1
<strong>解释：</strong>
- 在时间 1 ，所有三个会议室都未占用，第一场会议在会议室 0 举办。
- 在时间 2 ，会议室 1 和 2 未占用，第二场会议在会议室 1 举办。
- 在时间 3 ，只有会议室 2 未占用，第三场会议在会议室 2 举办。
- 在时间 4 ，所有三个会议室都被占用，第四场会议延期举办。 
- 在时间 5 ，会议室 2 的会议结束。第四场会议在会议室 2 举办，时间周期为 [5,10) 。
- 在时间 6 ，所有三个会议室都被占用，第五场会议延期举办。 
- 在时间 10 ，会议室 1 和 2 的会议结束。第五场会议在会议室 1 举办，时间周期为 [10,12) 。 
会议室 1 和会议室 2 都举办了 2 场会议，所以返回 1 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>start<sub>i</sub></code> 的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们定义两个优先队列，分别表示空闲会议室、使用中的会议室。其中：空闲会议室 `idle` 依据**下标**排序；而使用中的会议室 `busy` 依据**结束时间、下标**排序。

先对会议按照开始时间排序，然后遍历会议，对于每个会议：

-   若有使用中的会议室小于当前等于会议的开始时间，将其加入到空闲会议室队列 `idle` 中；
-   若当前有空闲会议室，那么在空闲队列 `idle` 中取出权重最小的会议室，将其加入使用中的队列 `busy` 中；
-   若当前没有空闲会议室，那么在使用队列 `busy` 中找出最早结束时间且下标最小的会议室，重新加入使用中的队列 `busy` 中。

时间复杂度 $O(m \times \log m)$，其中 $m$ 为会议数量。

相似题目：

-   [1882. 使用服务器处理任务](https://github.com/doocs/leetcode/blob/main/solution/1800-1899/1882.Process%20Tasks%20Using%20Servers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        busy = []
        idle = list(range(n))
        heapify(idle)
        cnt = [0] * n
        for s, e in meetings:
            while busy and busy[0][0] <= s:
                heappush(idle, heappop(busy)[1])
            if idle:
                i = heappop(idle)
                cnt[i] += 1
                heappush(busy, (e, i))
            else:
                a, i = heappop(busy)
                cnt[i] += 1
                heappush(busy, (a + e - s, i))
        ans = 0
        for i, v in enumerate(cnt):
            if cnt[ans] < v:
                ans = i
        return ans
```

#### Java

```java
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> busy
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        PriorityQueue<Integer> idle = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            idle.offer(i);
        }
        int[] cnt = new int[n];
        for (var v : meetings) {
            int s = v[0], e = v[1];
            while (!busy.isEmpty() && busy.peek()[0] <= s) {
                idle.offer(busy.poll()[1]);
            }
            int i = 0;
            if (!idle.isEmpty()) {
                i = idle.poll();
                busy.offer(new int[] {e, i});
            } else {
                var x = busy.poll();
                i = x[1];
                busy.offer(new int[] {x[0] + e - s, i});
            }
            ++cnt[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[ans] < cnt[i]) {
                ans = i;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;
using pii = pair<ll, int>;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> idle;
        priority_queue<pii, vector<pii>, greater<pii>> busy;
        for (int i = 0; i < n; ++i) idle.push(i);
        vector<int> cnt(n);
        sort(meetings.begin(), meetings.end());
        for (auto& v : meetings) {
            int s = v[0], e = v[1];
            while (!busy.empty() && busy.top().first <= s) {
                idle.push(busy.top().second);
                busy.pop();
            }
            int i = 0;
            if (!idle.empty()) {
                i = idle.top();
                idle.pop();
                busy.push({e, i});
            } else {
                auto x = busy.top();
                busy.pop();
                i = x.second;
                busy.push({x.first + e - s, i});
            }
            ++cnt[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[ans] < cnt[i]) {
                ans = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mostBooked(n int, meetings [][]int) int {
	sort.Slice(meetings, func(i, j int) bool { return meetings[i][0] < meetings[j][0] })
	idle := hp{make([]int, n)}
	for i := 0; i < n; i++ {
		idle.IntSlice[i] = i
	}
	busy := hp2{}
	cnt := make([]int, n)
	for _, v := range meetings {
		s, e := v[0], v[1]
		for len(busy) > 0 && busy[0].end <= s {
			heap.Push(&idle, heap.Pop(&busy).(pair).i)
		}
		var i int
		if idle.Len() > 0 {
			i = heap.Pop(&idle).(int)
			heap.Push(&busy, pair{e, i})
		} else {
			x := heap.Pop(&busy).(pair)
			i = x.i
			heap.Push(&busy, pair{x.end + e - s, i})
		}
		cnt[i]++
	}
	ans := 0
	for i, v := range cnt {
		if cnt[ans] < v {
			ans = i
		}
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

type pair struct{ end, i int }
type hp2 []pair

func (h hp2) Len() int { return len(h) }
func (h hp2) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.end < b.end || a.end == b.end && a.i < b.i
}
func (h hp2) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2403. 杀死所有怪物的最短时间 🔒](https://leetcode.cn/problems/minimum-time-to-kill-all-monsters){#2403}

{{< tabs "2403" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, power: List[int]) -> int:
        n = len(power)
        f = [inf] * (1 << n)
        f[0] = 0
        for mask in range(1, 1 << n):
            gain = mask.bit_count()
            for i, x in enumerate(power):
                if mask >> i & 1:
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (x + gain - 1) // gain)
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumTime(int[] power) {
        int n = power.length;
        long[] f = new long[1 << n];
        Arrays.fill(f, Long.MAX_VALUE);
        f[0] = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int gain = Integer.bitCount(mask);
            for (int i = 0; i < n; ++i) {
                if ((mask >> i & 1) == 1) {
                    f[mask] = Math.min(f[mask], f[mask ^ 1 << i] + (power[i] + gain - 1) / gain);
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n = power.size();
        long long f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int gain = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (power[i] + gain - 1) / gain);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(power []int) int64 {
	n := len(power)
	f := make([]int64, 1<<n)
	for i := range f {
		f[i] = 1e18
	}
	f[0] = 0
	for mask := 1; mask < 1<<n; mask++ {
		gain := bits.OnesCount(uint(mask))
		for i, x := range power {
			if mask>>i&1 == 1 {
				f[mask] = min(f[mask], f[mask^(1<<i)]+int64(x+gain-1)/int64(gain))
			}
		}
	}
	return f[1<<n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTime(power: number[]): number {
    const n = power.length;
    const f: number[] = Array(1 << n).fill(Infinity);
    f[0] = 0;
    for (let mask = 1; mask < 1 << n; ++mask) {
        const gain = bitCount(mask);
        for (let i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                f[mask] = Math.min(f[mask], f[mask ^ (1 << i)] + Math.ceil(power[i] / gain));
            }
        }
    }
    return f.at(-1)!;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个整数数组 <code>power</code>，其中&nbsp; <code>power[i]</code> 是第 <code>i</code> 个怪物的力量。</p>

<p>你从 <code>0</code> 点法力值开始，每天获取&nbsp;<code>gain</code> 点法力值，最初 <code>gain</code> 等于 <code>1</code>。</p>

<p>每天，在获得 <code>gain</code>&nbsp;点法力值后，如果你的法力值大于或等于怪物的力量，你就可以打败怪物。当你打败怪物时:</p>

<ul>
	<li>
	<p data-group="1-1">你的法力值会被重置为 <code>0</code>，并且</p>
	</li>
	<li>
	<p data-group="1-1"><code>gain</code>&nbsp;的值增加 <code>1</code>。</p>
	</li>
</ul>

<p>返回<em>打败所有怪物所需的&nbsp;<strong>最少&nbsp;</strong>天数。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> power = [3,1,4]
<strong>输出:</strong> 4
<strong>解释:</strong> 打败所有怪物的最佳方法是:
- 第 1 天: 获得 1 点法力值，现在总共拥有 1 点法力值。用尽所有法力值击杀第 2 个怪物。
- 第 2 天: 获得 2 点法力值，现在总共拥有 2 点法力值。
- 第 3 天: 获得 2 点法力值，现在总共拥有 4 点法力值。用尽所有法力值击杀第 3 个怪物。
- 第 4 天: 获得 3 点法力值，现在总共拥有 3 点法力值。 用尽所有法力值击杀第 1 个怪物。
可以证明，4 天是最少需要的天数。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> power = [1,1,4]
<strong>输出:</strong> 4
<strong>解释:</strong> 打败所有怪物的最佳方法是:
- 第 1 天: 获得 1 点法力值，现在总共拥有 1 点法力值。用尽所有法力值击杀第 1 个怪物。
- 第 2 天: 获得 2 点法力值，现在总共拥有 2 点法力值。用尽所有法力值击杀第 2 个怪物。
- 第 3 天: 获得 3 点法力值，现在总共拥有 3 点法力值。
- 第 4 天: 获得 3 点法力值，现在总共拥有 6 点法力值。用尽所有法力值击杀第 3 个怪物。
可以证明，4 天是最少需要的天数。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> power = [1,2,4,9]
<strong>输出:</strong> 6
<strong>解释:</strong> 打败所有怪物的最佳方法是:
- 第 1 天: 获得 1 点法力值，现在总共拥有 1 点法力值。用尽所有法力值击杀第 1 个怪物
- 第 2 天: 获得 2 点法力值，现在总共拥有 2 点法力值。用尽所有法力值击杀第 2 个怪物。
- 第 3 天: 获得 3 点法力值，现在总共拥有 3 点法力值。
- 第 4 天: 获得 3 点法力值，现在总共拥有 6 点法力值。
- 第 5 天: 获得 3 点法力值，现在总共拥有 9 点法力值。用尽所有法力值击杀第 4 个怪物。
- 第 6 天: 获得 4 点法力值，现在总共拥有 4 点法力值。用尽所有法力值击杀第 3 个怪物。
可以证明，6 天是最少需要的天数。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= power.length &lt;= 17</code></li>
	<li><code>1 &lt;= power[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

我们注意带，怪物的数量最多为 $17$，这意味着我们可以使用一个 $17$ 位的二进制数来表示怪物的状态，其中第 $i$ 位为 $1$ 表示第 $i$ 个怪物还活着，为 $0$ 表示第 $i$ 个怪物已经被击败。

我们设计一个函数 $\textit{dfs}(\textit{mask})$，表示当前怪物的状态为 $\textit{mask}$ 时，打败所有怪物所需的最少天数。那么答案就是 $\textit{dfs}(2^n - 1)$，其中 $n$ 为怪物的数量。

函数 $\textit{dfs}(\textit{mask})$ 的计算方式如下：

-   如果 $\textit{mask} = 0$，表示所有怪物都已经被击败，返回 $0$；
-   否则，我们枚举每个怪物 $i$，如果第 $i$ 个怪物还活着，那么我们可以选择击败第 $i$ 个怪物，然后递归计算 $\textit{dfs}(\textit{mask} \oplus 2^i)$，并更新答案为 $\textit{ans} = \min(\textit{ans}, \textit{dfs}(\textit{mask} \oplus 2^i) + \lceil \frac{x}{\textit{gain}} \rceil)$，其中 $x$ 为第 $i$ 个怪物的力量，而 $\textit{gain} = 1 + (n - \textit{mask}.\textit{bitCount}())$，表示当前每天可以获得的法力值。

最后，我们返回 $\textit{dfs}(2^n - 1)$。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(2^n)$。其中 $n$ 为怪物的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, power: List[int]) -> int:
        @cache
        def dfs(mask: int) -> int:
            if mask == 0:
                return 0
            ans = inf
            gain = 1 + (n - mask.bit_count())
            for i, x in enumerate(power):
                if mask >> i & 1:
                    ans = min(ans, dfs(mask ^ (1 << i)) + (x + gain - 1) // gain)
            return ans

        n = len(power)
        return dfs((1 << n) - 1)
```

#### Java

```java
class Solution {
    private int n;
    private int[] power;
    private Long[] f;

    public long minimumTime(int[] power) {
        n = power.length;
        this.power = power;
        f = new Long[1 << n];
        return dfs((1 << n) - 1);
    }

    private long dfs(int mask) {
        if (mask == 0) {
            return 0;
        }
        if (f[mask] != null) {
            return f[mask];
        }
        f[mask] = Long.MAX_VALUE;
        int gain = 1 + (n - Integer.bitCount(mask));
        for (int i = 0; i < n; ++i) {
            if ((mask >> i & 1) == 1) {
                f[mask] = Math.min(f[mask], dfs(mask ^ 1 << i) + (power[i] + gain - 1) / gain);
            }
        }
        return f[mask];
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n = power.size();
        long long f[1 << n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int mask) -> long long {
            if (mask == 0) {
                return 0;
            }
            if (f[mask] != -1) {
                return f[mask];
            }
            f[mask] = LLONG_MAX;
            int gain = 1 + (n - __builtin_popcount(mask));
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    f[mask] = min(f[mask], dfs(mask ^ (1 << i)) + (power[i] + gain - 1) / gain);
                }
            }
            return f[mask];
        };
        return dfs((1 << n) - 1);
    }
};
```

#### Go

```go
func minimumTime(power []int) int64 {
	n := len(power)
	f := make([]int64, 1<<n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(mask int) int64
	dfs = func(mask int) int64 {
		if mask == 0 {
			return 0
		}
		if f[mask] != -1 {
			return f[mask]
		}
		f[mask] = 1e18
		gain := 1 + (n - bits.OnesCount(uint(mask)))
		for i, x := range power {
			if mask>>i&1 == 1 {
				f[mask] = min(f[mask], dfs(mask^(1<<i))+int64(x+gain-1)/int64(gain))
			}
		}
		return f[mask]
	}
	return dfs(1<<n - 1)
}
```

#### TypeScript

```ts
function minimumTime(power: number[]): number {
    const n = power.length;
    const f: number[] = Array(1 << n).fill(-1);
    const dfs = (mask: number): number => {
        if (mask === 0) {
            return 0;
        }
        if (f[mask] !== -1) {
            return f[mask];
        }
        f[mask] = Infinity;
        const gain = 1 + (n - bitCount(mask));
        for (let i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                f[mask] = Math.min(f[mask], dfs(mask ^ (1 << i)) + Math.ceil(power[i] / gain));
            }
        }
        return f[mask];
    };
    return dfs((1 << n) - 1);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩 + 动态规划

我们可以将方法一中的记忆化搜索改为动态规划，定义 $f[\textit{mask}]$ 表示当前怪物的状态为 $\textit{mask}$ 时，打败所有怪物所需的最少天数。其中 $\textit{mask}$ 是一个 $n$ 位的二进制数，其中第 $i$ 位为 $1$ 表示第 $i$ 个怪物已被击败，为 $0$ 表示第 $i$ 个怪物还活着。初始时 $f[0] = 0$，其余 $f[\textit{mask}] = +\infty$。答案即为 $f[2^n - 1]$。

我们在 $[1, 2^n - 1]$ 的范围内枚举 $\textit{mask}$，对于每个 $\textit{mask}$，我们枚举每个怪物 $i$，如果第 $i$ 个怪物被击败，那么它可以从上一个状态 $\textit{mask} \oplus 2^i$ 转移过来，转移的代价为 $(\textit{power}[i] + \textit{gain} - 1) / \textit{gain}$，其中 $\textit{gain} = \textit{mask}.\textit{bitCount}()$。

最后，返回 $f[2^n - 1]$。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(2^n)$。其中 $n$ 为怪物的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, power: List[int]) -> int:
        n = len(power)
        f = [inf] * (1 << n)
        f[0] = 0
        for mask in range(1, 1 << n):
            gain = mask.bit_count()
            for i, x in enumerate(power):
                if mask >> i & 1:
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (x + gain - 1) // gain)
        return f[-1]
```

#### Java

```java
class Solution {
    public long minimumTime(int[] power) {
        int n = power.length;
        long[] f = new long[1 << n];
        Arrays.fill(f, Long.MAX_VALUE);
        f[0] = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int gain = Integer.bitCount(mask);
            for (int i = 0; i < n; ++i) {
                if ((mask >> i & 1) == 1) {
                    f[mask] = Math.min(f[mask], f[mask ^ 1 << i] + (power[i] + gain - 1) / gain);
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n = power.size();
        long long f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int gain = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (power[i] + gain - 1) / gain);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func minimumTime(power []int) int64 {
	n := len(power)
	f := make([]int64, 1<<n)
	for i := range f {
		f[i] = 1e18
	}
	f[0] = 0
	for mask := 1; mask < 1<<n; mask++ {
		gain := bits.OnesCount(uint(mask))
		for i, x := range power {
			if mask>>i&1 == 1 {
				f[mask] = min(f[mask], f[mask^(1<<i)]+int64(x+gain-1)/int64(gain))
			}
		}
	}
	return f[1<<n-1]
}
```

#### TypeScript

```ts
function minimumTime(power: number[]): number {
    const n = power.length;
    const f: number[] = Array(1 << n).fill(Infinity);
    f[0] = 0;
    for (let mask = 1; mask < 1 << n; ++mask) {
        const gain = bitCount(mask);
        for (let i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                f[mask] = Math.min(f[mask], f[mask ^ (1 << i)] + Math.ceil(power[i] / gain));
            }
        }
    }
    return f.at(-1)!;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2404. 出现最频繁的偶数元素](https://leetcode.cn/problems/most-frequent-even-element){#2404}

{{< tabs "2404" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        cnt = Counter(x for x in nums if x % 2 == 0)
        ans, mx = -1, 0
        for x, v in cnt.items():
            if v > mx or (v == mx and ans > x):
                ans, mx = x, v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            if (x % 2 == 0) {
                cnt.merge(x, 1, Integer::sum);
            }
        }
        int ans = -1, mx = 0;
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            if (mx < v || (mx == v && ans > x)) {
                ans = x;
                mx = v;
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
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            if (x % 2 == 0) {
                ++cnt[x];
            }
        }
        int ans = -1, mx = 0;
        for (auto& [x, v] : cnt) {
            if (mx < v || (mx == v && ans > x)) {
                ans = x;
                mx = v;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostFrequentEven(nums []int) int {
	cnt := map[int]int{}
	for _, x := range nums {
		if x%2 == 0 {
			cnt[x]++
		}
	}
	ans, mx := -1, 0
	for x, v := range cnt {
		if mx < v || (mx == v && x < ans) {
			ans, mx = x, v
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostFrequentEven(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        if (x % 2 === 0) {
            cnt.set(x, (cnt.get(x) ?? 0) + 1);
        }
    }
    let ans = -1;
    let mx = 0;
    for (const [x, v] of cnt) {
        if (mx < v || (mx === v && ans > x)) {
            ans = x;
            mx = v;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &x in nums.iter() {
            if x % 2 == 0 {
                *cnt.entry(x).or_insert(0) += 1;
            }
        }
        let mut ans = -1;
        let mut mx = 0;
        for (&x, &v) in cnt.iter() {
            if mx < v || (mx == v && ans > x) {
                ans = x;
                mx = v;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function mostFrequentEven($nums) {
        $max = $rs = -1;
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] % 2 == 0) {
                $hashtable[$nums[$i]] += 1;
                if (
                    $hashtable[$nums[$i]] > $max ||
                    ($hashtable[$nums[$i]] == $max && $rs > $nums[$i])
                ) {
                    $max = $hashtable[$nums[$i]];
                    $rs = $nums[$i];
                }
            }
        }
        return $rs;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，返回出现最频繁的偶数元素。</p>

<p>如果存在多个满足条件的元素，只需要返回 <strong>最小</strong> 的一个。如果不存在这样的元素，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,2,2,4,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>
数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
返回最小的那个，即返回 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,4,4,9,2,4]
<strong>输出：</strong>4
<strong>解释：</strong>4 是出现最频繁的偶数元素。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [29,47,21,41,13,37,25,7]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在偶数元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 $cnt$ 统计所有偶数元素出现的次数，然后找出出现次数最多且值最小的偶数元素。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        cnt = Counter(x for x in nums if x % 2 == 0)
        ans, mx = -1, 0
        for x, v in cnt.items():
            if v > mx or (v == mx and ans > x):
                ans, mx = x, v
        return ans
```

#### Java

```java
class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            if (x % 2 == 0) {
                cnt.merge(x, 1, Integer::sum);
            }
        }
        int ans = -1, mx = 0;
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            if (mx < v || (mx == v && ans > x)) {
                ans = x;
                mx = v;
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
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            if (x % 2 == 0) {
                ++cnt[x];
            }
        }
        int ans = -1, mx = 0;
        for (auto& [x, v] : cnt) {
            if (mx < v || (mx == v && ans > x)) {
                ans = x;
                mx = v;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mostFrequentEven(nums []int) int {
	cnt := map[int]int{}
	for _, x := range nums {
		if x%2 == 0 {
			cnt[x]++
		}
	}
	ans, mx := -1, 0
	for x, v := range cnt {
		if mx < v || (mx == v && x < ans) {
			ans, mx = x, v
		}
	}
	return ans
}
```

#### TypeScript

```ts
function mostFrequentEven(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        if (x % 2 === 0) {
            cnt.set(x, (cnt.get(x) ?? 0) + 1);
        }
    }
    let ans = -1;
    let mx = 0;
    for (const [x, v] of cnt) {
        if (mx < v || (mx === v && ans > x)) {
            ans = x;
            mx = v;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &x in nums.iter() {
            if x % 2 == 0 {
                *cnt.entry(x).or_insert(0) += 1;
            }
        }
        let mut ans = -1;
        let mut mx = 0;
        for (&x, &v) in cnt.iter() {
            if mx < v || (mx == v && ans > x) {
                ans = x;
                mx = v;
            }
        }
        ans
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function mostFrequentEven($nums) {
        $max = $rs = -1;
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] % 2 == 0) {
                $hashtable[$nums[$i]] += 1;
                if (
                    $hashtable[$nums[$i]] > $max ||
                    ($hashtable[$nums[$i]] == $max && $rs > $nums[$i])
                ) {
                    $max = $hashtable[$nums[$i]];
                    $rs = $nums[$i];
                }
            }
        }
        return $rs;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2405. 子字符串的最优划分](https://leetcode.cn/problems/optimal-partition-of-string){#2405}

{{< tabs "2405" >}}

{{% tab "python" %}}
```python
class Solution:
    def partitionString(self, s: str) -> int:
        ans, mask = 1, 0
        for x in map(lambda c: ord(c) - ord("a"), s):
            if mask >> x & 1:
                ans += 1
                mask = 0
            mask |= 1 << x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int partitionString(String s) {
        int ans = 1, mask = 0;
        for (int i = 0; i < s.length(); ++i) {
            int x = s.charAt(i) - 'a';
            if ((mask >> x & 1) == 1) {
                ++ans;
                mask = 0;
            }
            mask |= 1 << x;
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
    int partitionString(string s) {
        int ans = 1, mask = 0;
        for (char& c : s) {
            int x = c - 'a';
            if (mask >> x & 1) {
                ++ans;
                mask = 0;
            }
            mask |= 1 << x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func partitionString(s string) int {
	ans, mask := 1, 0
	for _, c := range s {
		x := int(c - 'a')
		if mask>>x&1 == 1 {
			ans++
			mask = 0
		}
		mask |= 1 << x
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function partitionString(s: string): number {
    let [ans, mask] = [1, 0];
    for (const c of s) {
        const x = c.charCodeAt(0) - 97;
        if ((mask >> x) & 1) {
            ++ans;
            mask = 0;
        }
        mask |= 1 << x;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut ans = 1;
        let mut mask = 0;
        for x in s.chars().map(|c| (c as u8 - b'a') as u32) {
            if mask >> x & 1 == 1 {
                ans += 1;
                mask = 0;
            }
            mask |= 1 << x;
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

<p>给你一个字符串 <code>s</code> ，请你将该字符串划分成一个或多个 <strong>子字符串</strong> ，并满足每个子字符串中的字符都是 <strong>唯一</strong> 的。也就是说，在单个子字符串中，字母的出现次数都不超过 <strong>一次</strong> 。</p>

<p>满足题目要求的情况下，返回 <strong>最少</strong> 需要划分多少个子字符串<em>。</em></p>

<p>注意，划分后，原字符串中的每个字符都应该恰好属于一个子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abacaba"
<strong>输出：</strong>4
<strong>解释：</strong>
两种可行的划分方法分别是 ("a","ba","cab","a") 和 ("ab","a","ca","ba") 。
可以证明最少需要划分 4 个子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ssssss"
<strong>输出：</strong>6
<strong>解释：
</strong>只存在一种可行的划分方法 ("s","s","s","s","s","s") 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题意，每个子字符串应该尽可能长，且包含的字符唯一，因此，我们只需要贪心地进行划分即可。

我们定义一个二进制整数 $\textit{mask}$ 来记录当前子字符串中出现的字符，其中 $\textit{mask}$ 的第 $i$ 位为 $1$ 表示第 $i$ 个字母已经出现过，为 $0$ 表示未出现过。另外，我们还需要一个变量 $\textit{ans}$ 来记录划分的子字符串个数，初始时 $\textit{ans} = 1$。

遍历字符串 $s$ 中的每个字符，对于每个字符 $c$，我们将其转换为 $0$ 到 $25$ 之间的整数 $x$，然后判断 $\textit{mask}$ 的第 $x$ 位是否为 $1$，如果为 $1$，说明当前字符 $c$ 与当前子字符串中的字符有重复，此时 $\textit{ans}$ 需要加 $1$，并将 $\textit{mask}$ 置为 $0$；否则，将 $\textit{mask}$ 的第 $x$ 位置为 $1$。然后，我们将 $\textit{mask}$ 更新为 $\textit{mask}$ 与 $2^x$ 的按位或结果。

最后，返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def partitionString(self, s: str) -> int:
        ans, mask = 1, 0
        for x in map(lambda c: ord(c) - ord("a"), s):
            if mask >> x & 1:
                ans += 1
                mask = 0
            mask |= 1 << x
        return ans
```

#### Java

```java
class Solution {
    public int partitionString(String s) {
        int ans = 1, mask = 0;
        for (int i = 0; i < s.length(); ++i) {
            int x = s.charAt(i) - 'a';
            if ((mask >> x & 1) == 1) {
                ++ans;
                mask = 0;
            }
            mask |= 1 << x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int partitionString(string s) {
        int ans = 1, mask = 0;
        for (char& c : s) {
            int x = c - 'a';
            if (mask >> x & 1) {
                ++ans;
                mask = 0;
            }
            mask |= 1 << x;
        }
        return ans;
    }
};
```

#### Go

```go
func partitionString(s string) int {
	ans, mask := 1, 0
	for _, c := range s {
		x := int(c - 'a')
		if mask>>x&1 == 1 {
			ans++
			mask = 0
		}
		mask |= 1 << x
	}
	return ans
}
```

#### TypeScript

```ts
function partitionString(s: string): number {
    let [ans, mask] = [1, 0];
    for (const c of s) {
        const x = c.charCodeAt(0) - 97;
        if ((mask >> x) & 1) {
            ++ans;
            mask = 0;
        }
        mask |= 1 << x;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut ans = 1;
        let mut mask = 0;
        for x in s.chars().map(|c| (c as u8 - b'a') as u32) {
            if mask >> x & 1 == 1 {
                ans += 1;
                mask = 0;
            }
            mask |= 1 << x;
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

# [2406. 将区间分为最少组数](https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups){#2406}

{{< tabs "2406" >}}

{{% tab "python" %}}
```python
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        q = []
        for left, right in sorted(intervals):
            if q and q[0] < left:
                heappop(q)
            heappush(q, right)
        return len(q)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (var e : intervals) {
            if (!q.isEmpty() && q.peek() < e[0]) {
                q.poll();
            }
            q.offer(e[1]);
        }
        return q.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& e : intervals) {
            if (q.size() && q.top() < e[0]) {
                q.pop();
            }
            q.push(e[1]);
        }
        return q.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minGroups(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	q := hp{}
	for _, e := range intervals {
		if q.Len() > 0 && q.IntSlice[0] < e[0] {
			heap.Pop(&q)
		}
		heap.Push(&q, e[1])
	}
	return q.Len()
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minGroups(intervals: number[][]): number {
    intervals.sort((a, b) => a[0] - b[0]);
    const q = new PriorityQueue({ compare: (a, b) => a - b });
    for (const [left, right] of intervals) {
        if (!q.isEmpty() && q.front() < left) {
            q.dequeue();
        }
        q.enqueue(right);
    }
    return q.size();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组&nbsp;<code>intervals</code>&nbsp;，其中&nbsp;<code>intervals[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;表示 <strong>闭</strong>&nbsp;区间&nbsp;<code>[left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;。</p>

<p>你需要将&nbsp;<code>intervals</code> 划分为一个或者多个区间&nbsp;<strong>组</strong>&nbsp;，每个区间 <b>只</b>&nbsp;属于一个组，且同一个组中任意两个区间 <strong>不相交</strong>&nbsp;。</p>

<p>请你返回 <strong>最少</strong>&nbsp;需要划分成多少个组。</p>

<p>如果两个区间覆盖的范围有重叠（即至少有一个公共数字），那么我们称这两个区间是 <strong>相交</strong>&nbsp;的。比方说区间&nbsp;<code>[1, 5]</code> 和&nbsp;<code>[5, 8]</code>&nbsp;相交。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
<b>输出：</b>3
<b>解释：</b>我们可以将区间划分为如下的区间组：
- 第 1 组：[1, 5] ，[6, 8] 。
- 第 2 组：[2, 3] ，[5, 10] 。
- 第 3 组：[1, 10] 。
可以证明无法将区间划分为少于 3 个组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>intervals = [[1,3],[5,6],[8,10],[11,13]]
<b>输出：</b>1
<b>解释：</b>所有区间互不相交，所以我们可以把它们全部放在一个组内。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>1 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

我们先将区间按左端点排序，用小根堆维护每组的最右端点（堆顶是所有组的最右端点的最小值）。

接下来，我们遍历每个区间：

-   若当前区间左端点大于堆顶元素，说明当前区间可以加入到堆顶元素所在的组中，我们直接弹出堆顶元素，然后将当前区间的右端点放入堆中；
-   否则，说明当前没有组能容纳当前区间，那么我们就新建一个组，将当前区间的右端点放入堆中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `intervals` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        q = []
        for left, right in sorted(intervals):
            if q and q[0] < left:
                heappop(q)
            heappush(q, right)
        return len(q)
```

#### Java

```java
class Solution {
    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (var e : intervals) {
            if (!q.isEmpty() && q.peek() < e[0]) {
                q.poll();
            }
            q.offer(e[1]);
        }
        return q.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& e : intervals) {
            if (q.size() && q.top() < e[0]) {
                q.pop();
            }
            q.push(e[1]);
        }
        return q.size();
    }
};
```

#### Go

```go
func minGroups(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	q := hp{}
	for _, e := range intervals {
		if q.Len() > 0 && q.IntSlice[0] < e[0] {
			heap.Pop(&q)
		}
		heap.Push(&q, e[1])
	}
	return q.Len()
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

#### TypeScript

```ts
function minGroups(intervals: number[][]): number {
    intervals.sort((a, b) => a[0] - b[0]);
    const q = new PriorityQueue({ compare: (a, b) => a - b });
    for (const [left, right] of intervals) {
        if (!q.isEmpty() && q.front() < left) {
            q.dequeue();
        }
        q.enqueue(right);
    }
    return q.size();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2407. 最长递增子序列 II](https://leetcode.cn/problems/longest-increasing-subsequence-ii){#2407}

{{< tabs "2407" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = max(self.tr[u << 1].v, self.tr[u << 1 | 1].v)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v = self.query(u << 1, l, r)
        if r > mid:
            v = max(v, self.query(u << 1 | 1, l, r))
        return v


class Solution:
    def lengthOfLIS(self, nums: List[int], k: int) -> int:
        tree = SegmentTree(max(nums))
        ans = 1
        for v in nums:
            t = tree.query(1, v - k, v - 1) + 1
            ans = max(ans, t)
            tree.modify(1, v, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthOfLIS(int[] nums, int k) {
        int mx = nums[0];
        for (int v : nums) {
            mx = Math.max(mx, v);
        }
        SegmentTree tree = new SegmentTree(mx);
        int ans = 0;
        for (int v : nums) {
            int t = tree.query(1, v - k, v - 1) + 1;
            ans = Math.max(ans, t);
            tree.modify(1, v, t);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = Math.max(tr[u << 1].v, tr[u << 1 | 1].v);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v = query(u << 1, l, r);
        }
        if (r > mid) {
            v = Math.max(v, query(u << 1 | 1, l, r));
        }
        return v;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = max(tr[u << 1]->v, tr[u << 1 | 1]->v);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v = max(v, query(u << 1 | 1, l, r));
        return v;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        SegmentTree* tree = new SegmentTree(*max_element(nums.begin(), nums.end()));
        int ans = 1;
        for (int v : nums) {
            int t = tree->query(1, v - k, v - 1) + 1;
            ans = max(ans, t);
            tree->modify(1, v, t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lengthOfLIS(nums []int, k int) int {
	mx := slices.Max(nums)
	tree := newSegmentTree(mx)
	ans := 1
	for _, v := range nums {
		t := tree.query(1, v-k, v-1) + 1
		ans = max(ans, t)
		tree.modify(1, v, t)
	}
	return ans
}

type node struct {
	l int
	r int
	v int
}

type segmentTree struct {
	tr []*node
}

func newSegmentTree(n int) *segmentTree {
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{tr}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) modify(u, x, v int) {
	if t.tr[u].l == x && t.tr[u].r == x {
		t.tr[u].v = v
		return
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if x <= mid {
		t.modify(u<<1, x, v)
	} else {
		t.modify(u<<1|1, x, v)
	}
	t.pushup(u)
}

func (t *segmentTree) query(u, l, r int) int {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return t.tr[u].v
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	v := 0
	if l <= mid {
		v = t.query(u<<1, l, r)
	}
	if r > mid {
		v = max(v, t.query(u<<1|1, l, r))
	}
	return v
}

func (t *segmentTree) pushup(u int) {
	t.tr[u].v = max(t.tr[u<<1].v, t.tr[u<<1|1].v)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>找到&nbsp;<code>nums</code>&nbsp;中满足以下要求的最长子序列：</p>

<ul>
	<li>子序列 <strong>严格递增</strong></li>
	<li>子序列中相邻元素的差值 <strong>不超过</strong>&nbsp;<code>k</code>&nbsp;。</li>
</ul>

<p>请你返回满足上述要求的 <strong>最长子序列</strong>&nbsp;的长度。</p>

<p><strong>子序列</strong>&nbsp;是从一个数组中删除部分元素后，剩余元素不改变顺序得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,2,1,4,3,4,5,8,15], k = 3
<b>输出：</b>5
<strong>解释：</strong>
满足要求的最长子序列是 [1,3,4,5,8] 。
子序列长度为 5 ，所以我们返回 5 。
注意子序列 [1,3,4,5,8,15] 不满足要求，因为 15 - 8 = 7 大于 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [7,4,5,1,8,12,4,7], k = 5
<b>输出：</b>4
<strong>解释：</strong>
满足要求的最长子序列是 [4,5,8,12] 。
子序列长度为 4 ，所以我们返回 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,5], k = 1
<b>输出：</b>1
<strong>解释：</strong>
满足要求的最长子序列是 [1] 。
子序列长度为 1 ，所以我们返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

我们假设 $f[v]$ 表示以数字 $v$ 结尾的最长递增子序列的长度。

我们遍历数组 $nums$ 中的每个元素 $v$，有状态转移方程：$f[v] = \max(f[v], f[x])$，其中 $x$ 的取值范围是 $[v-k, v-1]$。

因此，我们需要一个数据结构，来维护区间的最大值，不难想到使用线段树。

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 $log(width)$。更新某个元素的值，只需要更新 $log(width)$ 个区间，并且这些区间都包含在一个包含该元素的大区间内。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 $[1,N]$；
-   线段树的每个叶子节点代表一个长度为 $1$ 的元区间 $[x, x]$；
-   对于每个内部节点 $[l,r]$，它的左儿子是 $[l,mid]$，右儿子是 $[mid+1,r]$, 其中 $mid = \left \lfloor \frac{l+r}{2} \right \rfloor$。

对于本题，线段树节点维护的信息是区间范围内的最大值。

时间复杂度 $O(n \times \log n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = max(self.tr[u << 1].v, self.tr[u << 1 | 1].v)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v = self.query(u << 1, l, r)
        if r > mid:
            v = max(v, self.query(u << 1 | 1, l, r))
        return v


class Solution:
    def lengthOfLIS(self, nums: List[int], k: int) -> int:
        tree = SegmentTree(max(nums))
        ans = 1
        for v in nums:
            t = tree.query(1, v - k, v - 1) + 1
            ans = max(ans, t)
            tree.modify(1, v, t)
        return ans
```

#### Java

```java
class Solution {
    public int lengthOfLIS(int[] nums, int k) {
        int mx = nums[0];
        for (int v : nums) {
            mx = Math.max(mx, v);
        }
        SegmentTree tree = new SegmentTree(mx);
        int ans = 0;
        for (int v : nums) {
            int t = tree.query(1, v - k, v - 1) + 1;
            ans = Math.max(ans, t);
            tree.modify(1, v, t);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = Math.max(tr[u << 1].v, tr[u << 1 | 1].v);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v = query(u << 1, l, r);
        }
        if (r > mid) {
            v = Math.max(v, query(u << 1 | 1, l, r));
        }
        return v;
    }
}
```

#### C++

```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = max(tr[u << 1]->v, tr[u << 1 | 1]->v);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v = max(v, query(u << 1 | 1, l, r));
        return v;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        SegmentTree* tree = new SegmentTree(*max_element(nums.begin(), nums.end()));
        int ans = 1;
        for (int v : nums) {
            int t = tree->query(1, v - k, v - 1) + 1;
            ans = max(ans, t);
            tree->modify(1, v, t);
        }
        return ans;
    }
};
```

#### Go

```go
func lengthOfLIS(nums []int, k int) int {
	mx := slices.Max(nums)
	tree := newSegmentTree(mx)
	ans := 1
	for _, v := range nums {
		t := tree.query(1, v-k, v-1) + 1
		ans = max(ans, t)
		tree.modify(1, v, t)
	}
	return ans
}

type node struct {
	l int
	r int
	v int
}

type segmentTree struct {
	tr []*node
}

func newSegmentTree(n int) *segmentTree {
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{tr}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) modify(u, x, v int) {
	if t.tr[u].l == x && t.tr[u].r == x {
		t.tr[u].v = v
		return
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if x <= mid {
		t.modify(u<<1, x, v)
	} else {
		t.modify(u<<1|1, x, v)
	}
	t.pushup(u)
}

func (t *segmentTree) query(u, l, r int) int {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return t.tr[u].v
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	v := 0
	if l <= mid {
		v = t.query(u<<1, l, r)
	}
	if r > mid {
		v = max(v, t.query(u<<1|1, l, r))
	}
	return v
}

func (t *segmentTree) pushup(u int) {
	t.tr[u].v = max(t.tr[u<<1].v, t.tr[u<<1|1].v)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2408. 设计 SQL 🔒](https://leetcode.cn/problems/design-sql){#2408}

{{< tabs "2408" >}}

{{% tab "python" %}}
```python
class SQL:
    def __init__(self, names: List[str], columns: List[int]):
        self.tables = defaultdict(list)

    def insertRow(self, name: str, row: List[str]) -> None:
        self.tables[name].append(row)

    def deleteRow(self, name: str, rowId: int) -> None:
        pass

    def selectCell(self, name: str, rowId: int, columnId: int) -> str:
        return self.tables[name][rowId - 1][columnId - 1]


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# obj.insertRow(name,row)
# obj.deleteRow(name,rowId)
# param_3 = obj.selectCell(name,rowId,columnId)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SQL {
    private Map<String, List<List<String>>> tables;

    public SQL(List<String> names, List<Integer> columns) {
        tables = new HashMap<>(names.size());
    }

    public void insertRow(String name, List<String> row) {
        tables.computeIfAbsent(name, k -> new ArrayList<>()).add(row);
    }

    public void deleteRow(String name, int rowId) {
    }

    public String selectCell(String name, int rowId, int columnId) {
        return tables.get(name).get(rowId - 1).get(columnId - 1);
    }
}

/**
 * Your SQL object will be instantiated and called as such:
 * SQL obj = new SQL(names, columns);
 * obj.insertRow(name,row);
 * obj.deleteRow(name,rowId);
 * String param_3 = obj.selectCell(name,rowId,columnId);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SQL {
public:
    unordered_map<string, vector<vector<string>>> tables;
    SQL(vector<string>& names, vector<int>& columns) {
    }

    void insertRow(string name, vector<string> row) {
        tables[name].push_back(row);
    }

    void deleteRow(string name, int rowId) {
    }

    string selectCell(string name, int rowId, int columnId) {
        return tables[name][rowId - 1][columnId - 1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SQL struct {
	tables map[string][][]string
}

func Constructor(names []string, columns []int) SQL {
	return SQL{map[string][][]string{}}
}

func (this *SQL) InsertRow(name string, row []string) {
	this.tables[name] = append(this.tables[name], row)
}

func (this *SQL) DeleteRow(name string, rowId int) {

}

func (this *SQL) SelectCell(name string, rowId int, columnId int) string {
	return this.tables[name][rowId-1][columnId-1]
}

/**
 * Your SQL object will be instantiated and called as such:
 * obj := Constructor(names, columns);
 * obj.InsertRow(name,row);
 * obj.DeleteRow(name,rowId);
 * param_3 := obj.SelectCell(name,rowId,columnId);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串数组&nbsp;<code>names</code> 和 <code>columns</code>，大小都为&nbsp;<code>n</code>。其中 <code>names[i]</code> 是第 <code>i</code> 个表的名称，<code>columns[i]</code> 是第 <code>i</code> 个表的列数。</p>

<p>您需要实现一个支持以下&nbsp;<strong>操作&nbsp;</strong>的类：</p>

<ul>
	<li>在特定的表中&nbsp;<strong>插入&nbsp;</strong>一行。插入的每一行都有一个 id。id 是使用自动递增方法分配的，其中第一个插入行的 id 为 1，同一个表中的后续其他行的 id 为上一个插入行的 id (即使它已被删除) 加 1。</li>
	<li>从指定表中&nbsp;<strong>删除&nbsp;</strong>一行。<strong>注意</strong>，删除一行 <strong>不会</strong> 影响下一个插入行的 id。</li>
	<li>从任何表中&nbsp;<strong>查询&nbsp;</strong>一个特定的单元格并返回其值。</li>
	<li>从任何表以 csv 格式 <strong>导出</strong> 所有行。</li>
</ul>

<p>实现&nbsp;<code>SQL</code> 类:</p>

<ul>
	<li><code>SQL(String[] names, int[] columns)</code>

    <ul>
    	<li>创建&nbsp;<code>n</code> 个表。</li>
    </ul>
    </li>
    <li><code>bool ins(String name, String[] row)</code>
    <ul>
    	<li>将 <code>row</code> 插入表 <code>name</code> 中并返回 <code>true</code>。</li>
    	<li>如果&nbsp;<code>row.length</code>&nbsp;<strong>不</strong> 匹配列的预期数量，或者 <code>name</code> <strong>不是</strong> 一个合法的表，不进行任何插入并返回 <code>false</code>。</li>
    </ul>
    </li>
    <li><code>void rmv(String name, int rowId, int columnId)</code>
    <ul>
    	<li>从表 <code>name</code>&nbsp;中移除行 <code>rowId</code>。</li>
    	<li>如果 <code>name</code> <strong>不是</strong> 一个合法的表或者没有 id 为 <code>rowId</code> 的行，不进行删除。</li>
    </ul>
    </li>
    <li><code>String sel(String name, int rowId, int columnId)</code>
    <ul>
    	<li>返回表 <code>name</code> 中位于特定的 <code>rowId</code> 和 <code>columnId</code> 的单元格的值。</li>
    	<li>如果 name&nbsp;<strong>不是&nbsp;</strong>一个合法的表，或者单元格 <code>(rowId, columnId)</code> <strong>不合法</strong>，返回 <code>"&lt;null&gt;"</code>。</li>
    </ul>
    </li>
    <li><code>String[]&nbsp;exp(String name)</code>
    <ul>
    	<li>返回表 <code>name</code> 中出现的行。</li>
    	<li>如果 <code>name</code> <strong>不是</strong> 一个合法的表，返回一个空数组。每一行以字符串表示，每个单元格的值（<strong>包括</strong> 行的 id）以 <code>","</code> 分隔。</li>
    </ul>
    </li>

</ul>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<pre class="example-io">
["SQL","ins","sel","ins","exp","rmv","sel","exp"]
[[["one","two","three"],[2,3,1]],["two",["first","second","third"]],["two",1,3],["two",["fourth","fifth","sixth"]],["two"],["two",1],["two",2,2],["two"]]
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
[null,true,"third",true,["1,first,second,third","2,fourth,fifth,sixth"],null,"fifth",["2,fourth,fifth,sixth"]]</pre>

<p><strong>解释：</strong></p>

<pre class="example-io">
// 创建 3 张表。
SQL sql = new SQL(["one", "two", "three"], [2, 3, 1]);

// 将 id 为 1 的行添加到表 "two"。返回 True。
sql.ins("two", ["first", "second", "third"]);

// 从表 "two" 中 id 为 1 的行 
// 其中第 3 列返回值 "third"。
sql.sel("two", 1, 3);

// 将另外一个 id 为 2 的行添加到表 "two"。返回 True。
sql.ins("two", ["fourth", "fifth", "sixth"]);

// 导出表 "two" 的行。
// 目前表中有两行 id 为 1 和 2 。
sql.exp("two");

// 删除表 "two" 当中的第一行。注意第二行的 id
// 依然为 2。
sql.rmv("two", 1);

// 从表 "two" 中 id 为 2 的行
// 其中第 2 列返回值 "fifth"。
sql.sel("two", 2, 2);

// 导出表 "two" 的行。
// 目前表中有一行 id 为 2。
sql.exp("two");
</pre>
</div>

<p><strong class="example">示例 2：</strong></p>
<strong>输入：</strong>

<pre>
["SQL","ins","sel","ins","exp","rmv","sel","exp"]
[[["one","two","three"],[2,3,1]],["two",["first","second","third"]],["two",1,3],["two",["fourth","fifth","sixth"]],["two"],["two",1],["two",2,2],["two"]]
</pre>

<strong>输出：</strong>

<pre>
[null,true,"third",true,["1,first,second,third","2,fourth,fifth,sixth"],null,"fifth",["2,fourth,fifth,sixth"]]
</pre>

<strong>解释：</strong>

<pre>
// 创建 3 张表
SQL sQL = new SQL(["one", "two", "three"], [2, 3, 1]); 

// 将 id 为 1 的行添加到表 "two"。返回 True。
sQL.ins("two", ["first", "second", "third"]); 

// 从表 "two" 中 id 为 1 的行
// 其中第 3 列返回值 "third"。
sQL.sel("two", 1, 3); 

// 删除表 "two" 的第一行。
sQL.rmv("two", 1); 

// 返回 "&lt;null&gt;" 因为 id 为 1 的单元格
// 已经从表 "two" 中删除。
sQL.sel("two", 1, 2); 

// 返回 False 因为列的数量不正确。
sQL.ins("two", ["fourth", "fifth"]); 

// 将 id 为 2 的行添加到表 "two"。返回 True。
sQL.ins("two", ["fourth", "fifth", "sixth"]); 
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == names.length == columns.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= names[i].length, row[i].length, name.length &lt;= 10</code></li>
	<li><code>names[i]</code>, <code>row[i]</code>, <code>name</code> 由小写英文字母组成。</li>
	<li><code>1 &lt;= columns[i] &lt;= 10</code></li>
	<li><code>1 &lt;= row.length &lt;= 10</code></li>
	<li>所有的 <code>names[i]</code>&nbsp;都是&nbsp;<strong>不同&nbsp;</strong>的。</li>
	<li>最多调用 <code>ins</code> 和 <code>rmv</code> <code>2000</code> 次。</li>
	<li>最多调用 <code>sel</code> <code>10<sup>4</sup></code>&nbsp;次。</li>
	<li>最多调用 <code>exp</code> <code>500</code> 次。</li>
</ul>

<p><strong>进阶：</strong>如果表因多次删除而变得稀疏，您会选择哪种方法？为什么？考虑对内存使用和性能的影响。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

创建哈希表 `tables` 用于存储表名和表数据行的映射。直接模拟题目中的操作即可。

每个操作的时间复杂度均为 $O(1)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class SQL:
    def __init__(self, names: List[str], columns: List[int]):
        self.tables = defaultdict(list)

    def insertRow(self, name: str, row: List[str]) -> None:
        self.tables[name].append(row)

    def deleteRow(self, name: str, rowId: int) -> None:
        pass

    def selectCell(self, name: str, rowId: int, columnId: int) -> str:
        return self.tables[name][rowId - 1][columnId - 1]


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# obj.insertRow(name,row)
# obj.deleteRow(name,rowId)
# param_3 = obj.selectCell(name,rowId,columnId)
```

#### Java

```java
class SQL {
    private Map<String, List<List<String>>> tables;

    public SQL(List<String> names, List<Integer> columns) {
        tables = new HashMap<>(names.size());
    }

    public void insertRow(String name, List<String> row) {
        tables.computeIfAbsent(name, k -> new ArrayList<>()).add(row);
    }

    public void deleteRow(String name, int rowId) {
    }

    public String selectCell(String name, int rowId, int columnId) {
        return tables.get(name).get(rowId - 1).get(columnId - 1);
    }
}

/**
 * Your SQL object will be instantiated and called as such:
 * SQL obj = new SQL(names, columns);
 * obj.insertRow(name,row);
 * obj.deleteRow(name,rowId);
 * String param_3 = obj.selectCell(name,rowId,columnId);
 */
```

#### C++

```cpp
class SQL {
public:
    unordered_map<string, vector<vector<string>>> tables;
    SQL(vector<string>& names, vector<int>& columns) {
    }

    void insertRow(string name, vector<string> row) {
        tables[name].push_back(row);
    }

    void deleteRow(string name, int rowId) {
    }

    string selectCell(string name, int rowId, int columnId) {
        return tables[name][rowId - 1][columnId - 1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
```

#### Go

```go
type SQL struct {
	tables map[string][][]string
}

func Constructor(names []string, columns []int) SQL {
	return SQL{map[string][][]string{}}
}

func (this *SQL) InsertRow(name string, row []string) {
	this.tables[name] = append(this.tables[name], row)
}

func (this *SQL) DeleteRow(name string, rowId int) {

}

func (this *SQL) SelectCell(name string, rowId int, columnId int) string {
	return this.tables[name][rowId-1][columnId-1]
}

/**
 * Your SQL object will be instantiated and called as such:
 * obj := Constructor(names, columns);
 * obj.InsertRow(name,row);
 * obj.DeleteRow(name,rowId);
 * param_3 := obj.SelectCell(name,rowId,columnId);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2409. 统计共同度过的日子数](https://leetcode.cn/problems/count-days-spent-together){#2409}

{{< tabs "2409" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDaysTogether(
        self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
    ) -> int:
        a = max(arriveAlice, arriveBob)
        b = min(leaveAlice, leaveBob)
        days = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
        x = sum(days[: int(a[:2]) - 1]) + int(a[3:])
        y = sum(days[: int(b[:2]) - 1]) + int(b[3:])
        return max(y - x + 1, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] days = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int countDaysTogether(
        String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        String a = arriveAlice.compareTo(arriveBob) < 0 ? arriveBob : arriveAlice;
        String b = leaveAlice.compareTo(leaveBob) < 0 ? leaveAlice : leaveBob;
        int x = f(a), y = f(b);
        return Math.max(y - x + 1, 0);
    }

    private int f(String s) {
        int i = Integer.parseInt(s.substring(0, 2)) - 1;
        int res = 0;
        for (int j = 0; j < i; ++j) {
            res += days[j];
        }
        res += Integer.parseInt(s.substring(3));
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string a = arriveAlice < arriveBob ? arriveBob : arriveAlice;
        string b = leaveAlice < leaveBob ? leaveAlice : leaveBob;
        int x = f(a), y = f(b);
        return max(0, y - x + 1);
    }

    int f(string s) {
        int m, d;
        sscanf(s.c_str(), "%d-%d", &m, &d);
        int res = 0;
        for (int i = 0; i < m - 1; ++i) {
            res += days[i];
        }
        res += d;
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
	days := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	f := func(s string) int {
		m, _ := strconv.Atoi(s[:2])
		d, _ := strconv.Atoi(s[3:])
		res := 0
		for i := 0; i < m-1; i++ {
			res += days[i]
		}
		res += d
		return res
	}
	a, b := arriveAlice, leaveBob
	if arriveAlice < arriveBob {
		a = arriveBob
	}
	if leaveAlice < leaveBob {
		b = leaveAlice
	}
	x, y := f(a), f(b)
	ans := y - x + 1
	if ans < 0 {
		return 0
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

<p>Alice 和 Bob 计划分别去罗马开会。</p>

<p>给你四个字符串&nbsp;<code>arriveAlice</code>&nbsp;，<code>leaveAlice</code>&nbsp;，<code>arriveBob</code>&nbsp;和&nbsp;<code>leaveBob</code>&nbsp;。Alice 会在日期&nbsp;<code>arriveAlice</code>&nbsp;到&nbsp;<code>leaveAlice</code>&nbsp;之间在城市里（<strong>日期为闭区间</strong>），而 Bob 在日期&nbsp;<code>arriveBob</code>&nbsp;到&nbsp;<code>leaveBob</code>&nbsp;之间在城市里（<strong>日期为闭区间</strong>）。每个字符串都包含 5 个字符，格式为&nbsp;<code>"MM-DD"</code>&nbsp;，对应着一个日期的月和日。</p>

<p>请你返回 Alice和 Bob 同时在罗马的天数。</p>

<p>你可以假设所有日期都在 <strong>同一个</strong>&nbsp;自然年，而且 <strong>不是</strong>&nbsp;闰年。每个月份的天数分别为：<code>[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
<b>输出：</b>3
<b>解释：</b>Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月 16、17 和 18 号。所以答案为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
<b>输出：</b>0
<b>解释：</b>Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有日期的格式均为&nbsp;<code>"MM-DD"</code>&nbsp;。</li>
	<li>Alice 和 Bob 的到达日期都 <strong>早于或等于</strong> 他们的离开日期。</li>
	<li>题目测试用例所给出的日期均为 <strong>非闰年</strong> 的有效日期。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们将日期转换为天数，然后计算两个人在罗马的天数。

时间复杂度 $O(C)$，空间复杂度 $O(C)$。其中 $C$ 为常数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDaysTogether(
        self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
    ) -> int:
        a = max(arriveAlice, arriveBob)
        b = min(leaveAlice, leaveBob)
        days = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
        x = sum(days[: int(a[:2]) - 1]) + int(a[3:])
        y = sum(days[: int(b[:2]) - 1]) + int(b[3:])
        return max(y - x + 1, 0)
```

#### Java

```java
class Solution {
    private int[] days = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int countDaysTogether(
        String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        String a = arriveAlice.compareTo(arriveBob) < 0 ? arriveBob : arriveAlice;
        String b = leaveAlice.compareTo(leaveBob) < 0 ? leaveAlice : leaveBob;
        int x = f(a), y = f(b);
        return Math.max(y - x + 1, 0);
    }

    private int f(String s) {
        int i = Integer.parseInt(s.substring(0, 2)) - 1;
        int res = 0;
        for (int j = 0; j < i; ++j) {
            res += days[j];
        }
        res += Integer.parseInt(s.substring(3));
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string a = arriveAlice < arriveBob ? arriveBob : arriveAlice;
        string b = leaveAlice < leaveBob ? leaveAlice : leaveBob;
        int x = f(a), y = f(b);
        return max(0, y - x + 1);
    }

    int f(string s) {
        int m, d;
        sscanf(s.c_str(), "%d-%d", &m, &d);
        int res = 0;
        for (int i = 0; i < m - 1; ++i) {
            res += days[i];
        }
        res += d;
        return res;
    }
};
```

#### Go

```go
func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
	days := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	f := func(s string) int {
		m, _ := strconv.Atoi(s[:2])
		d, _ := strconv.Atoi(s[3:])
		res := 0
		for i := 0; i < m-1; i++ {
			res += days[i]
		}
		res += d
		return res
	}
	a, b := arriveAlice, leaveBob
	if arriveAlice < arriveBob {
		a = arriveBob
	}
	if leaveAlice < leaveBob {
		b = leaveAlice
	}
	x, y := f(a), f(b)
	ans := y - x + 1
	if ans < 0 {
		return 0
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
