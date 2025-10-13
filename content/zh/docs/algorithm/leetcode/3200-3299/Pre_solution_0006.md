---
title: "3250_单调数组对的数目 I"
date: 2025-10-08T18:40:15+08:00
weight: 6
tags: [前缀和, 动态规划, 字符串, 数学, 数据库, 数组, 枚举, 滑动窗口, 矩阵, 组合数学]
---

{{< markmap >}}
### [3250_单调数组对的数目 I](#3250)
#### [数组](#3250)
#### [数学](#3250)
#### [动态规划](#3250)
#### [组合数学](#3250)
#### [前缀和](#3250)
### [3251_单调数组对的数目 II](#3251)
#### [数组](#3251)
#### [数学](#3251)
#### [动态规划](#3251)
#### [组合数学](#3251)
#### [前缀和](#3251)
### [3252_英超积分榜排名 II 🔒](#3252)
#### [数据库](#3252)
### [3253_最小代价构造字符串（简单） 🔒](#3253)
### [3254_长度为 K 的子数组的能量值 I](#3254)
#### [数组](#3254)
#### [滑动窗口](#3254)
### [3255_长度为 K 的子数组的能量值 II](#3255)
#### [数组](#3255)
#### [滑动窗口](#3255)
### [3256_放三个车的价值之和最大 I](#3256)
#### [数组](#3256)
#### [动态规划](#3256)
#### [枚举](#3256)
#### [矩阵](#3256)
### [3257_放三个车的价值之和最大 II](#3257)
#### [数组](#3257)
#### [动态规划](#3257)
#### [枚举](#3257)
#### [矩阵](#3257)
### [3258_统计满足 K 约束的子字符串数量 I](#3258)
#### [字符串](#3258)
#### [滑动窗口](#3258)
### [3259_超级饮料的最大强化能量](#3259)
#### [数组](#3259)
#### [动态规划](#3259)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3250_单调数组对的数目 I
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 组合数学
___
#### 前缀和
---
### 3251_单调数组对的数目 II
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 组合数学
___
#### 前缀和
---
### 3252_英超积分榜排名 II 🔒
___
#### 数据库
---
### 3253_最小代价构造字符串（简单） 🔒
---
### 3254_长度为 K 的子数组的能量值 I
___
#### 数组
___
#### 滑动窗口
---
### 3255_长度为 K 的子数组的能量值 II
___
#### 数组
___
#### 滑动窗口
---
### 3256_放三个车的价值之和最大 I
___
#### 数组
___
#### 动态规划
___
#### 枚举
___
#### 矩阵
---
### 3257_放三个车的价值之和最大 II
___
#### 数组
___
#### 动态规划
___
#### 枚举
___
#### 矩阵
---
### 3258_统计满足 K 约束的子字符串数量 I
___
#### 字符串
___
#### 滑动窗口
---
### 3259_超级饮料的最大强化能量
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 字符串 |
| 数学 | 数据库 | 数组 |
| 枚举 | 滑动窗口 | 矩阵 |
| 组合数学 |  |  |

# [3250. 单调数组对的数目 I](https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-i){#3250}

{{< tabs "3250" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n, m = len(nums), max(nums)
        f = [[0] * (m + 1) for _ in range(n)]
        for j in range(nums[0] + 1):
            f[0][j] = 1
        for i in range(1, n):
            s = list(accumulate(f[i - 1]))
            for j in range(nums[i] + 1):
                k = min(j, j + nums[i - 1] - nums[i])
                if k >= 0:
                    f[i][j] = s[k] % mod
        return sum(f[-1][: nums[-1] + 1]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countOfPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int m = Arrays.stream(nums).max().getAsInt();
        int[][] f = new int[n][m + 1];
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        int[] g = new int[m + 1];
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = Math.min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
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
    int countOfPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<int>> f(n, vector<int>(m + 1));
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        vector<int> g(m + 1);
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOfPairs(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	m := slices.Max(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	for j := 0; j <= nums[0]; j++ {
		f[0][j] = 1
	}
	g := make([]int, m+1)
	for i := 1; i < n; i++ {
		g[0] = f[i-1][0]
		for j := 1; j <= m; j++ {
			g[j] = (g[j-1] + f[i-1][j]) % mod
		}
		for j := 0; j <= nums[i]; j++ {
			k := min(j, j+nums[i-1]-nums[i])
			if k >= 0 {
				f[i][j] = g[k]
			}
		}
	}
	for j := 0; j <= nums[n-1]; j++ {
		ans = (ans + f[n-1][j]) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countOfPairs(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const m = Math.max(...nums);
    const f: number[][] = Array.from({ length: n }, () => Array(m + 1).fill(0));
    for (let j = 0; j <= nums[0]; j++) {
        f[0][j] = 1;
    }
    const g: number[] = Array(m + 1).fill(0);
    for (let i = 1; i < n; i++) {
        g[0] = f[i - 1][0];
        for (let j = 1; j <= m; j++) {
            g[j] = (g[j - 1] + f[i - 1][j]) % mod;
        }
        for (let j = 0; j <= nums[i]; j++) {
            const k = Math.min(j, j + nums[i - 1] - nums[i]);
            if (k >= 0) {
                f[i][j] = g[k];
            }
        }
    }
    let ans = 0;
    for (let j = 0; j <= nums[n - 1]; j++) {
        ans = (ans + f[n - 1][j]) % mod;
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

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>正</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果两个&nbsp;<strong>非负</strong>&nbsp;整数数组&nbsp;<code>(arr1, arr2)</code>&nbsp;满足以下条件，我们称它们是&nbsp;<strong>单调</strong>&nbsp;数组对：</p>

<ul>
	<li>两个数组的长度都是&nbsp;<code>n</code>&nbsp;。</li>
	<li><code>arr1</code>&nbsp;是单调<strong>&nbsp;非递减</strong>&nbsp;的，换句话说&nbsp;<code>arr1[0] &lt;= arr1[1] &lt;= ... &lt;= arr1[n - 1]</code>&nbsp;。</li>
	<li><code>arr2</code>&nbsp;是单调 <strong>非递增</strong>&nbsp;的，换句话说&nbsp;<code>arr2[0] &gt;= arr2[1] &gt;= ... &gt;= arr2[n - 1]</code>&nbsp;。</li>
	<li>对于所有的&nbsp;<code>0 &lt;= i &lt;= n - 1</code>&nbsp;都有&nbsp;<code>arr1[i] + arr2[i] == nums[i]</code>&nbsp;。</li>
</ul>

<p>请你返回所有 <strong>单调</strong>&nbsp;数组对的数目。</p>

<p>由于答案可能很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,3,2]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>单调数组对包括：</p>

<ol>
	<li><code>([0, 1, 1], [2, 2, 1])</code></li>
	<li><code>([0, 1, 2], [2, 2, 0])</code></li>
	<li><code>([0, 2, 2], [2, 1, 0])</code></li>
	<li><code>([1, 2, 2], [1, 1, 0])</code></li>
</ol>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [5,5,5,5]</span></p>

<p><span class="example-io"><b>输出：</b>126</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 2000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 前缀和优化

我们定义 $f[i][j]$ 表示下标 $[0,..i]$ 的单调数组对的数目，且 $arr1[i] = j$。初始时 $[i][j] = 0$，答案为 $\sum_{j=0}^{\textit{nums}[n-1]} f[n-1][j]$。

当 $i = 0$ 时，有 $[0][j] = 1$，其中 $0 \leq j \leq \textit{nums}[0]$。

当 $i > 0$ 时，我们可以根据 $f[i-1][j']$ 计算 $f[i][j]$。由于 $\textit{arr1}$ 是单调非递减的，因此 $j' \leq j$。又由于 $\textit{arr2}$ 是单调非递增的，因此 $\textit{nums}[i] - j \leq \textit{nums}[i - 1] - j'$。即 $j' \leq \min(j, j + \textit{nums}[i - 1] - \textit{nums}[i])$。

答案为 $\sum_{j=0}^{\textit{nums}[n-1]} f[n-1][j]$。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度，而 $m$ 表示数组 $\textit{nums}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n, m = len(nums), max(nums)
        f = [[0] * (m + 1) for _ in range(n)]
        for j in range(nums[0] + 1):
            f[0][j] = 1
        for i in range(1, n):
            s = list(accumulate(f[i - 1]))
            for j in range(nums[i] + 1):
                k = min(j, j + nums[i - 1] - nums[i])
                if k >= 0:
                    f[i][j] = s[k] % mod
        return sum(f[-1][: nums[-1] + 1]) % mod
```

#### Java

```java
class Solution {
    public int countOfPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int m = Arrays.stream(nums).max().getAsInt();
        int[][] f = new int[n][m + 1];
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        int[] g = new int[m + 1];
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = Math.min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<int>> f(n, vector<int>(m + 1));
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        vector<int> g(m + 1);
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countOfPairs(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	m := slices.Max(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	for j := 0; j <= nums[0]; j++ {
		f[0][j] = 1
	}
	g := make([]int, m+1)
	for i := 1; i < n; i++ {
		g[0] = f[i-1][0]
		for j := 1; j <= m; j++ {
			g[j] = (g[j-1] + f[i-1][j]) % mod
		}
		for j := 0; j <= nums[i]; j++ {
			k := min(j, j+nums[i-1]-nums[i])
			if k >= 0 {
				f[i][j] = g[k]
			}
		}
	}
	for j := 0; j <= nums[n-1]; j++ {
		ans = (ans + f[n-1][j]) % mod
	}
	return
}
```

#### TypeScript

```ts
function countOfPairs(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const m = Math.max(...nums);
    const f: number[][] = Array.from({ length: n }, () => Array(m + 1).fill(0));
    for (let j = 0; j <= nums[0]; j++) {
        f[0][j] = 1;
    }
    const g: number[] = Array(m + 1).fill(0);
    for (let i = 1; i < n; i++) {
        g[0] = f[i - 1][0];
        for (let j = 1; j <= m; j++) {
            g[j] = (g[j - 1] + f[i - 1][j]) % mod;
        }
        for (let j = 0; j <= nums[i]; j++) {
            const k = Math.min(j, j + nums[i - 1] - nums[i]);
            if (k >= 0) {
                f[i][j] = g[k];
            }
        }
    }
    let ans = 0;
    for (let j = 0; j <= nums[n - 1]; j++) {
        ans = (ans + f[n - 1][j]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3251. 单调数组对的数目 II](https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii){#3251}

{{< tabs "3251" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n, m = len(nums), max(nums)
        f = [[0] * (m + 1) for _ in range(n)]
        for j in range(nums[0] + 1):
            f[0][j] = 1
        for i in range(1, n):
            s = list(accumulate(f[i - 1]))
            for j in range(nums[i] + 1):
                k = min(j, j + nums[i - 1] - nums[i])
                if k >= 0:
                    f[i][j] = s[k] % mod
        return sum(f[-1][: nums[-1] + 1]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countOfPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int m = Arrays.stream(nums).max().getAsInt();
        int[][] f = new int[n][m + 1];
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        int[] g = new int[m + 1];
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = Math.min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
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
    int countOfPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<int>> f(n, vector<int>(m + 1));
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        vector<int> g(m + 1);
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOfPairs(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	m := slices.Max(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	for j := 0; j <= nums[0]; j++ {
		f[0][j] = 1
	}
	g := make([]int, m+1)
	for i := 1; i < n; i++ {
		g[0] = f[i-1][0]
		for j := 1; j <= m; j++ {
			g[j] = (g[j-1] + f[i-1][j]) % mod
		}
		for j := 0; j <= nums[i]; j++ {
			k := min(j, j+nums[i-1]-nums[i])
			if k >= 0 {
				f[i][j] = g[k]
			}
		}
	}
	for j := 0; j <= nums[n-1]; j++ {
		ans = (ans + f[n-1][j]) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countOfPairs(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const m = Math.max(...nums);
    const f: number[][] = Array.from({ length: n }, () => Array(m + 1).fill(0));
    for (let j = 0; j <= nums[0]; j++) {
        f[0][j] = 1;
    }
    const g: number[] = Array(m + 1).fill(0);
    for (let i = 1; i < n; i++) {
        g[0] = f[i - 1][0];
        for (let j = 1; j <= m; j++) {
            g[j] = (g[j - 1] + f[i - 1][j]) % mod;
        }
        for (let j = 0; j <= nums[i]; j++) {
            const k = Math.min(j, j + nums[i - 1] - nums[i]);
            if (k >= 0) {
                f[i][j] = g[k];
            }
        }
    }
    let ans = 0;
    for (let j = 0; j <= nums[n - 1]; j++) {
        ans = (ans + f[n - 1][j]) % mod;
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

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>正</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果两个&nbsp;<strong>非负</strong>&nbsp;整数数组&nbsp;<code>(arr1, arr2)</code>&nbsp;满足以下条件，我们称它们是&nbsp;<strong>单调</strong>&nbsp;数组对：</p>

<ul>
	<li>两个数组的长度都是&nbsp;<code>n</code>&nbsp;。</li>
	<li><code>arr1</code>&nbsp;是单调<strong>&nbsp;非递减</strong>&nbsp;的，换句话说&nbsp;<code>arr1[0] &lt;= arr1[1] &lt;= ... &lt;= arr1[n - 1]</code>&nbsp;。</li>
	<li><code>arr2</code>&nbsp;是单调 <strong>非递增</strong>&nbsp;的，换句话说&nbsp;<code>arr2[0] &gt;= arr2[1] &gt;= ... &gt;= arr2[n - 1]</code>&nbsp;。</li>
	<li>对于所有的&nbsp;<code>0 &lt;= i &lt;= n - 1</code>&nbsp;都有&nbsp;<code>arr1[i] + arr2[i] == nums[i]</code>&nbsp;。</li>
</ul>

<p>请你返回所有 <strong>单调</strong>&nbsp;数组对的数目。</p>

<p>由于答案可能很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,3,2]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>单调数组对包括：</p>

<ol>
	<li><code>([0, 1, 1], [2, 2, 1])</code></li>
	<li><code>([0, 1, 2], [2, 2, 0])</code></li>
	<li><code>([0, 2, 2], [2, 1, 0])</code></li>
	<li><code>([1, 2, 2], [1, 1, 0])</code></li>
</ol>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [5,5,5,5]</span></p>

<p><span class="example-io"><b>输出：</b>126</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 2000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 前缀和优化

我们定义 $f[i][j]$ 表示下标 $[0,..i]$ 的单调数组对的数目，且 $arr1[i] = j$。初始时 $[i][j] = 0$，答案为 $\sum_{j=0}^{\textit{nums}[n-1]} f[n-1][j]$。

当 $i = 0$ 时，有 $[0][j] = 1$，其中 $0 \leq j \leq \textit{nums}[0]$。

当 $i > 0$ 时，我们可以根据 $f[i-1][j']$ 计算 $f[i][j]$。由于 $\textit{arr1}$ 是单调非递减的，因此 $j' \leq j$。又由于 $\textit{arr2}$ 是单调非递增的，因此 $\textit{nums}[i] - j \leq \textit{nums}[i - 1] - j'$。即 $j' \leq \min(j, j + \textit{nums}[i - 1] - \textit{nums}[i])$。

答案为 $\sum_{j=0}^{\textit{nums}[n-1]} f[n-1][j]$。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度，而 $m$ 表示数组 $\textit{nums}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        n, m = len(nums), max(nums)
        f = [[0] * (m + 1) for _ in range(n)]
        for j in range(nums[0] + 1):
            f[0][j] = 1
        for i in range(1, n):
            s = list(accumulate(f[i - 1]))
            for j in range(nums[i] + 1):
                k = min(j, j + nums[i - 1] - nums[i])
                if k >= 0:
                    f[i][j] = s[k] % mod
        return sum(f[-1][: nums[-1] + 1]) % mod
```

#### Java

```java
class Solution {
    public int countOfPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int m = Arrays.stream(nums).max().getAsInt();
        int[][] f = new int[n][m + 1];
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        int[] g = new int[m + 1];
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = Math.min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<int>> f(n, vector<int>(m + 1));
        for (int j = 0; j <= nums[0]; ++j) {
            f[0][j] = 1;
        }
        vector<int> g(m + 1);
        for (int i = 1; i < n; ++i) {
            g[0] = f[i - 1][0];
            for (int j = 1; j <= m; ++j) {
                g[j] = (g[j - 1] + f[i - 1][j]) % mod;
            }
            for (int j = 0; j <= nums[i]; ++j) {
                int k = min(j, j + nums[i - 1] - nums[i]);
                if (k >= 0) {
                    f[i][j] = g[k];
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= nums[n - 1]; ++j) {
            ans = (ans + f[n - 1][j]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countOfPairs(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	m := slices.Max(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	for j := 0; j <= nums[0]; j++ {
		f[0][j] = 1
	}
	g := make([]int, m+1)
	for i := 1; i < n; i++ {
		g[0] = f[i-1][0]
		for j := 1; j <= m; j++ {
			g[j] = (g[j-1] + f[i-1][j]) % mod
		}
		for j := 0; j <= nums[i]; j++ {
			k := min(j, j+nums[i-1]-nums[i])
			if k >= 0 {
				f[i][j] = g[k]
			}
		}
	}
	for j := 0; j <= nums[n-1]; j++ {
		ans = (ans + f[n-1][j]) % mod
	}
	return
}
```

#### TypeScript

```ts
function countOfPairs(nums: number[]): number {
    const mod = 1e9 + 7;
    const n = nums.length;
    const m = Math.max(...nums);
    const f: number[][] = Array.from({ length: n }, () => Array(m + 1).fill(0));
    for (let j = 0; j <= nums[0]; j++) {
        f[0][j] = 1;
    }
    const g: number[] = Array(m + 1).fill(0);
    for (let i = 1; i < n; i++) {
        g[0] = f[i - 1][0];
        for (let j = 1; j <= m; j++) {
            g[j] = (g[j - 1] + f[i - 1][j]) % mod;
        }
        for (let j = 0; j <= nums[i]; j++) {
            const k = Math.min(j, j + nums[i - 1] - nums[i]);
            if (k >= 0) {
                f[i][j] = g[k];
            }
        }
    }
    let ans = 0;
    for (let j = 0; j <= nums[n - 1]; j++) {
        ans = (ans + f[n - 1][j]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3252. 英超积分榜排名 II 🔒](https://leetcode.cn/problems/premier-league-table-ranking-ii){#3252}

{{< tabs "3252" >}}

{{% tab "sql" %}}
```sql
WITH
    T AS (
        SELECT
            team_name,
            wins * 3 + draws AS points,
            RANK() OVER (ORDER BY wins * 3 + draws DESC) AS position,
            COUNT(1) OVER () AS total_teams
        FROM TeamStats
    )
SELECT
    team_name,
    points,
    position,
    CASE
        WHEN position <= CEIL(total_teams / 3.0) THEN 'Tier 1'
        WHEN position <= CEIL(2 * total_teams / 3.0) THEN 'Tier 2'
        ELSE 'Tier 3'
    END tier
FROM T
ORDER BY 2 DESC, 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def calculate_team_tiers(team_stats: pd.DataFrame) -> pd.DataFrame:
    team_stats["points"] = team_stats["wins"] * 3 + team_stats["draws"]
    team_stats["position"] = (
        team_stats["points"].rank(method="min", ascending=False).astype(int)
    )
    total_teams = len(team_stats)
    team_stats["tier"] = np.where(
        team_stats["position"] <= np.ceil(total_teams / 3.0),
        "Tier 1",
        np.where(
            team_stats["position"] <= np.ceil(2 * total_teams / 3.0), "Tier 2", "Tier 3"
        ),
    )
    team_stats = team_stats.sort_values(
        by=["points", "team_name"], ascending=[False, True]
    )
    return team_stats[["team_name", "points", "position", "tier"]]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>TeamStats</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| team_id          | int     |
| team_name        | varchar |
| matches_played   | int     |
| wins             | int     |
| draws            | int     |
| losses           | int     |
+------------------+---------+
team_id 是这张表的唯一主键。
这张表包含队伍 id，队伍名，场次，赢局，平局和输局。
</pre>

<p>编写一个解决方案来计算联盟中每支球队的 <strong>得分</strong>，<strong>排名 </strong>和 <b>等级</b>。积分计算方式如下：</p>

<ul>
	<li><strong>赢局</strong> 有&nbsp;<code>3</code>&nbsp;点得分</li>
	<li><strong>平局</strong> 有&nbsp;<code>1</code>&nbsp;点得分</li>
	<li><strong>输局</strong> 有&nbsp;<code>0</code>&nbsp;点得分</li>
</ul>

<p><b>注意：</b>积分相同的球队必须分配相同的排名。</p>

<p><strong>等级评级：</strong></p>

<ul>
	<li>根据积分将联盟分为 <code>3</code> 个等级：</li>
	<li>等级 1：前&nbsp;<code>33%</code>&nbsp;的队伍</li>
	<li>等级 2：中间&nbsp;<code>33%</code> 的队伍</li>
	<li>等级 3：最后&nbsp;<code>34%</code>&nbsp;的队伍</li>
	<li>如果等级边界出现平局，平局的队伍分配到更高的等级。</li>
</ul>

<p>返回结果表以&nbsp;<code>points</code>&nbsp;<strong>降序</strong>&nbsp;排序，然后以&nbsp;<code>team_name</code> <strong>升序</strong>&nbsp;排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>TeamStats</code> 表：</p>

<pre class="example-io">
+---------+-------------------+----------------+------+-------+--------+
| team_id | team_name         | matches_played | wins | draws | losses |
+---------+-------------------+----------------+------+-------+--------+
| 1       | Chelsea           | 22             | 13   | 2     | 7      |
| 2       | Nottingham Forest | 27             | 6    | 6     | 15     |
| 3       | Liverpool         | 17             | 1    | 8     | 8      |
| 4       | Aston Villa       | 20             | 1    | 6     | 13     |
| 5       | Fulham            | 31             | 18   | 1     | 12     |
| 6       | Burnley           | 26             | 6    | 9     | 11     |
| 7       | Newcastle United  | 33             | 11   | 10    | 12     |
| 8       | Sheffield United  | 20             | 18   | 2     | 0      |
| 9       | Luton Town        | 5              | 4    | 0     | 1      |
| 10      | Everton           | 14             | 2    | 6     | 6      |
+---------+-------------------+----------------+------+-------+--------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------------+--------+----------+---------+
| team_name         | points | position | tier    |
+-------------------+--------+----------+---------+
| Sheffield United  | 56     | 1        | Tier 1  |
| Fulham            | 55     | 2        | Tier 1  |
| Newcastle United  | 43     | 3        | Tier 1  |
| Chelsea           | 41     | 4        | Tier 1  |
| Burnley           | 27     | 5        | Tier 2  |
| Nottingham Forest | 24     | 6        | Tier 2  |
| Everton           | 12     | 7        | Tier 2  |
| Luton Town        | 12     | 7        | Tier 2  |
| Liverpool         | 11     | 9        | Tier 3  |
| Aston Villa       | 9      | 10       | Tier 3  |
+-------------------+--------+----------+---------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>谢菲尔德联队拿下 56 分（18 胜 * 3 分 + 2 平 * 1 分）位列第 1。</li>
	<li>富勒姆拿下 55 分（18 胜 * 3 分 + 1 平 * 1 分）位列第 2。</li>
	<li>纽卡斯尔联队拿下 43 分（11 胜 * 3 分 + 10 平 * 1 分）位列第 3。</li>
	<li>切尔西拿下 41 分（13 胜 * 3 分 + 2 平 * 1 分）位列第 4。</li>
	<li>伯恩利拿下 27 分（6 胜 * 3 分 + 9 平 * 1 分）位列第 5。</li>
	<li>诺丁汉森林拿下 24 分（6 胜 * 3 分 + 6 平 * 1 分）位列第 6。</li>
	<li>埃弗顿和卢顿镇均拿下 12 分，埃弗顿&nbsp;2 胜 * 3 分 + 6 平 * 1 分，卢顿镇 4 胜 * 3 分。两支队伍并列位列第 7。</li>
	<li>利物浦拿下 11 分（1 胜 * 3 分 + 8 平 * 1 分）位列第 9。</li>
	<li>阿斯顿维拉拿下 9 分（1 胜 * 3 分 + 6 平 * 1 分）位列第 10。</li>
</ul>

<p><strong>等级计算：</strong></p>

<ul>
	<li><strong>等级 1：</strong>根据积分排名前 33% 的球队。谢菲尔德联队、富勒姆、纽卡斯尔联队和切尔西属于等级 1。</li>
	<li><strong>等级 2：</strong>中间&nbsp;33% 的球队。伯恩利、诺丁汉森林、埃弗顿和卢顿镇属于等级 2。</li>
	<li><strong>等级 3：</strong>垫底 34% 的球队。利物浦和阿斯顿维拉落入等级 3。</li>
</ul>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + CASE WHEN

我们可以使用窗口函数 `RANK()` 来计算每支球队的积分、排名，并计算总球队数。然后，我们可以使用 `CASE WHEN` 语句来确定每支球队的等级。

<!-- tabs:start -->

#### MySQL

```sql
WITH
    T AS (
        SELECT
            team_name,
            wins * 3 + draws AS points,
            RANK() OVER (ORDER BY wins * 3 + draws DESC) AS position,
            COUNT(1) OVER () AS total_teams
        FROM TeamStats
    )
SELECT
    team_name,
    points,
    position,
    CASE
        WHEN position <= CEIL(total_teams / 3.0) THEN 'Tier 1'
        WHEN position <= CEIL(2 * total_teams / 3.0) THEN 'Tier 2'
        ELSE 'Tier 3'
    END tier
FROM T
ORDER BY 2 DESC, 1;
```

#### Pandas

```python
import pandas as pd


def calculate_team_tiers(team_stats: pd.DataFrame) -> pd.DataFrame:
    team_stats["points"] = team_stats["wins"] * 3 + team_stats["draws"]
    team_stats["position"] = (
        team_stats["points"].rank(method="min", ascending=False).astype(int)
    )
    total_teams = len(team_stats)
    team_stats["tier"] = np.where(
        team_stats["position"] <= np.ceil(total_teams / 3.0),
        "Tier 1",
        np.where(
            team_stats["position"] <= np.ceil(2 * total_teams / 3.0), "Tier 2", "Tier 3"
        ),
    )
    team_stats = team_stats.sort_values(
        by=["points", "team_name"], ascending=[False, True]
    )
    return team_stats[["team_name", "points", "position", "tier"]]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3253. 最小代价构造字符串（简单） 🔒](https://leetcode.cn/problems/construct-string-with-minimum-cost-easy){#3253}

{{< tabs "3253" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26
        self.cost = inf

    def insert(self, word: str, cost: int):
        node = self
        for c in word:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.cost = min(node.cost, cost)


class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(target):
                return 0
            ans = inf
            node = trie
            for j in range(i, len(target)):
                idx = ord(target[j]) - ord("a")
                if node.children[idx] is None:
                    return ans
                node = node.children[idx]
                ans = min(ans, node.cost + dfs(j + 1))
            return ans

        trie = Trie()
        for word, cost in zip(words, costs):
            trie.insert(word, cost)
        ans = dfs(0)
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    public final int inf = 1 << 29;
    public Trie[] children = new Trie[26];
    public int cost = inf;

    public void insert(String word, int cost) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.cost = Math.min(node.cost, cost);
    }
}

class Solution {
    private Trie trie = new Trie();
    private char[] target;
    private Integer[] f;

    public int minimumCost(String target, String[] words, int[] costs) {
        for (int i = 0; i < words.length; ++i) {
            trie.insert(words[i], costs[i]);
        }
        this.target = target.toCharArray();
        f = new Integer[target.length()];
        int ans = dfs(0);
        return ans < trie.inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= target.length) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        f[i] = trie.inf;
        Trie node = trie;
        for (int j = i; j < target.length; ++j) {
            int idx = target[j] - 'a';
            if (node.children[idx] == null) {
                return f[i];
            }
            node = node.children[idx];
            f[i] = Math.min(f[i], node.cost + dfs(j + 1));
        }
        return f[i];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int inf = 1 << 29;

class Trie {
public:
    Trie* children[26]{};
    int cost = inf;

    void insert(string& word, int cost) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->cost = min(node->cost, cost);
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i], costs[i]);
        }
        int n = target.length();
        int f[n];
        memset(f, 0, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            f[i] = inf;
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = target[j] - 'a';
                if (!node->children[idx]) {
                    return f[i];
                }
                node = node->children[idx];
                f[i] = min(f[i], node->cost + dfs(j + 1));
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const inf = 1 << 29

type Trie struct {
	children [26]*Trie
	cost     int
}

func NewTrie() *Trie {
	return &Trie{cost: inf}
}

func (t *Trie) insert(word string, cost int) {
	node := t
	for _, c := range word {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = NewTrie()
		}
		node = node.children[idx]
	}
	node.cost = min(node.cost, cost)
}

func minimumCost(target string, words []string, costs []int) int {
	trie := NewTrie()
	for i, word := range words {
		trie.insert(word, costs[i])
	}

	n := len(target)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		f[i] = inf
		node := trie
		for j := i; j < n; j++ {
			idx := target[j] - 'a'
			if node.children[idx] == nil {
				return f[i]
			}
			node = node.children[idx]
			f[i] = min(f[i], node.cost+dfs(j+1))
		}
		return f[i]
	}
	if ans := dfs(0); ans < inf {
		return ans
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const inf = 1 << 29;

class Trie {
    children: (Trie | null)[];
    cost: number;

    constructor() {
        this.children = Array(26).fill(null);
        this.cost = inf;
    }

    insert(word: string, cost: number): void {
        let node: Trie = this;
        for (const c of word) {
            const idx = c.charCodeAt(0) - 97;
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx]!;
        }
        node.cost = Math.min(node.cost, cost);
    }
}

function minimumCost(target: string, words: string[], costs: number[]): number {
    const trie = new Trie();
    for (let i = 0; i < words.length; ++i) {
        trie.insert(words[i], costs[i]);
    }

    const n = target.length;
    const f: number[] = Array(n).fill(0);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        f[i] = inf;
        let node: Trie | null = trie;
        for (let j = i; j < n; ++j) {
            const idx = target.charCodeAt(j) - 97;
            if (!node?.children[idx]) {
                return f[i];
            }
            node = node.children[idx];
            f[i] = Math.min(f[i], node!.cost + dfs(j + 1));
        }
        return f[i];
    };

    const ans = dfs(0);
    return ans < inf ? ans : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>target</code>、一个字符串数组 <code>words</code> 以及一个整数数组 <code>costs</code>，这两个数组长度相同。</p>

<p>设想一个空字符串 <code>s</code>。</p>

<p>你可以执行以下操作任意次数（包括&nbsp;<strong>零&nbsp;</strong>次）：</p>

<ul>
	<li>选择一个在范围&nbsp; <code>[0, words.length - 1]</code> 的索引 <code>i</code>。</li>
	<li>将 <code>words[i]</code> 追加到 <code>s</code>。</li>
	<li>该操作的成本是 <code>costs[i]</code>。</li>
</ul>

<p>返回使 <code>s</code> 等于 <code>target</code> 的 <strong>最小</strong> 成本。如果不可能，返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong>输入：</strong> target = "abcdef", words = ["abdef","abc","d","def","ef"], costs = [100,1,1,10,5]</p>

<p><strong>输出：</strong> 7</p>

<p><strong>解释：</strong></p>

<ul>
	<li>选择索引 1 并以成本 1 将 <code>"abc"</code> 追加到 <code>s</code>，得到 <code>s = "abc"</code>。</li>
	<li>选择索引 2 并以成本 1 将 <code>"d"</code> 追加到 <code>s</code>，得到 <code>s = "abcd"</code>。</li>
	<li>选择索引 4 并以成本 5 将 <code>"ef"</code> 追加到 <code>s</code>，得到 <code>s = "abcdef"</code>。</li>
</ul>

<p><strong>示例 2：</strong></p>

<p><strong>输入：</strong> target = "aaaa", words = ["z","zz","zzz"], costs = [1,10,100]</p>

<p><strong>输出：</strong> -1</p>

<p><strong>解释：</strong></p>

<p>无法使 <code>s</code> 等于 <code>target</code>，因此返回 -1。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 2000</code></li>
	<li><code>1 &lt;= words.length == costs.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= target.length</code></li>
	<li><code>target</code> 和 <code>words[i]</code> 仅由小写英文字母组成。</li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树 + 记忆化搜索

我们首先创建一个字典树 $\textit{trie}$，字典树的每个节点包含一个长度为 $26$ 的数组 $\textit{children}$，数组中的每个元素都是一个指向下一个节点的指针。字典树的每个节点还包含一个 $\textit{cost}$ 变量，表示从根节点到当前节点的最小花费。

我们遍历 $\textit{words}$ 数组，将每个单词插入到字典树中，同时更新每个节点的 $\textit{cost}$ 变量。

接下来，我们定义一个记忆化搜索函数 $\textit{dfs}(i)$，表示从 $\textit{target}[i]$ 开始构造字符串的最小花费。那么答案就是 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的计算过程如下：

-   如果 $i \geq \textit{len}(\textit{target})$，表示已经构造完整个字符串，返回 $0$。
-   否则，我们从 $\textit{trie}$ 的根节点开始，遍历 $\textit{target}[i]$ 开始的所有后缀，找到最小花费，即 $\textit{trie}$ 中的 $\textit{cost}$ 变量，加上 $\textit{dfs}(j+1)$ 的结果，其中 $j$ 是 $\textit{target}[i]$ 开始的后缀的结束位置。

最后，如果 $\textit{dfs}(0) < \textit{inf}$，返回 $\textit{dfs}(0)$，否则返回 $-1$。

时间复杂度 $O(n^2 + L)$，空间复杂度 $O(n + L)$。其中 $n$ 是 $\textit{target}$ 的长度，而 $L$ 是 $\textit{words}$ 数组中所有单词的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26
        self.cost = inf

    def insert(self, word: str, cost: int):
        node = self
        for c in word:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.cost = min(node.cost, cost)


class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(target):
                return 0
            ans = inf
            node = trie
            for j in range(i, len(target)):
                idx = ord(target[j]) - ord("a")
                if node.children[idx] is None:
                    return ans
                node = node.children[idx]
                ans = min(ans, node.cost + dfs(j + 1))
            return ans

        trie = Trie()
        for word, cost in zip(words, costs):
            trie.insert(word, cost)
        ans = dfs(0)
        return ans if ans < inf else -1
```

#### Java

```java
class Trie {
    public final int inf = 1 << 29;
    public Trie[] children = new Trie[26];
    public int cost = inf;

    public void insert(String word, int cost) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.cost = Math.min(node.cost, cost);
    }
}

class Solution {
    private Trie trie = new Trie();
    private char[] target;
    private Integer[] f;

    public int minimumCost(String target, String[] words, int[] costs) {
        for (int i = 0; i < words.length; ++i) {
            trie.insert(words[i], costs[i]);
        }
        this.target = target.toCharArray();
        f = new Integer[target.length()];
        int ans = dfs(0);
        return ans < trie.inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= target.length) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        f[i] = trie.inf;
        Trie node = trie;
        for (int j = i; j < target.length; ++j) {
            int idx = target[j] - 'a';
            if (node.children[idx] == null) {
                return f[i];
            }
            node = node.children[idx];
            f[i] = Math.min(f[i], node.cost + dfs(j + 1));
        }
        return f[i];
    }
}
```

#### C++

```cpp
const int inf = 1 << 29;

class Trie {
public:
    Trie* children[26]{};
    int cost = inf;

    void insert(string& word, int cost) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->cost = min(node->cost, cost);
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i], costs[i]);
        }
        int n = target.length();
        int f[n];
        memset(f, 0, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            f[i] = inf;
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = target[j] - 'a';
                if (!node->children[idx]) {
                    return f[i];
                }
                node = node->children[idx];
                f[i] = min(f[i], node->cost + dfs(j + 1));
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```

#### Go

```go
const inf = 1 << 29

type Trie struct {
	children [26]*Trie
	cost     int
}

func NewTrie() *Trie {
	return &Trie{cost: inf}
}

func (t *Trie) insert(word string, cost int) {
	node := t
	for _, c := range word {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = NewTrie()
		}
		node = node.children[idx]
	}
	node.cost = min(node.cost, cost)
}

func minimumCost(target string, words []string, costs []int) int {
	trie := NewTrie()
	for i, word := range words {
		trie.insert(word, costs[i])
	}

	n := len(target)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		f[i] = inf
		node := trie
		for j := i; j < n; j++ {
			idx := target[j] - 'a'
			if node.children[idx] == nil {
				return f[i]
			}
			node = node.children[idx]
			f[i] = min(f[i], node.cost+dfs(j+1))
		}
		return f[i]
	}
	if ans := dfs(0); ans < inf {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
const inf = 1 << 29;

class Trie {
    children: (Trie | null)[];
    cost: number;

    constructor() {
        this.children = Array(26).fill(null);
        this.cost = inf;
    }

    insert(word: string, cost: number): void {
        let node: Trie = this;
        for (const c of word) {
            const idx = c.charCodeAt(0) - 97;
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx]!;
        }
        node.cost = Math.min(node.cost, cost);
    }
}

function minimumCost(target: string, words: string[], costs: number[]): number {
    const trie = new Trie();
    for (let i = 0; i < words.length; ++i) {
        trie.insert(words[i], costs[i]);
    }

    const n = target.length;
    const f: number[] = Array(n).fill(0);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        f[i] = inf;
        let node: Trie | null = trie;
        for (let j = i; j < n; ++j) {
            const idx = target.charCodeAt(j) - 97;
            if (!node?.children[idx]) {
                return f[i];
            }
            node = node.children[idx];
            f[i] = Math.min(f[i], node!.cost + dfs(j + 1));
        }
        return f[i];
    };

    const ans = dfs(0);
    return ans < inf ? ans : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3254. 长度为 K 的子数组的能量值 I](https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-i){#3254}

{{< tabs "3254" >}}

{{% tab "python" %}}
```python
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        f = [1] * n
        for i in range(1, n):
            if nums[i] == nums[i - 1] + 1:
                f[i] = f[i - 1] + 1
        return [nums[i] if f[i] >= k else -1 for i in range(k - 1, n)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                f[i] = f[i - 1] + 1;
            }
        }
        int[] ans = new int[n - k + 1];
        for (int i = k - 1; i < n; ++i) {
            ans[i - k + 1] = f[i] >= k ? nums[i] : -1;
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
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = nums[i] == nums[i - 1] + 1 ? f[i - 1] + 1 : 1;
        }
        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            ans.push_back(f[i] >= k ? nums[i] : -1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func resultsArray(nums []int, k int) (ans []int) {
	n := len(nums)
	f := make([]int, n)
	f[0] = 1
	for i := 1; i < n; i++ {
		if nums[i] == nums[i-1]+1 {
			f[i] = f[i-1] + 1
		} else {
			f[i] = 1
		}
	}
	for i := k - 1; i < n; i++ {
		if f[i] >= k {
			ans = append(ans, nums[i])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
export function resultsArray(nums: number[], k: number): number[] {
    const n = nums.length;
    const ans: number[] = [];

    for (let i = 0, j = 0; i < n; i++) {
        if (i && nums[i - 1] + 1 !== nums[i]) j = i;
        if (i >= k - 1) {
            ans.push(i - k + 1 < j ? -1 : nums[i]);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
export function resultsArray(nums, k) {
    const n = nums.length;
    const ans = [];

    for (let i = 0, j = 0; i < n; i++) {
        if (i && nums[i - 1] + 1 !== nums[i]) j = i;
        if (i >= k - 1) {
            ans.push(i - k + 1 < j ? -1 : nums[i]);
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一个数组的 <strong>能量值</strong> 定义为：</p>

<ul>
	<li>如果 <strong>所有</strong>&nbsp;元素都是依次&nbsp;<strong>连续</strong> 且 <strong>上升</strong> 的，那么能量值为 <strong>最大</strong>&nbsp;的元素。</li>
	<li>否则为 -1 。</li>
</ul>

<p>你需要求出 <code>nums</code>&nbsp;中所有长度为 <code>k</code>&nbsp;的&nbsp;<span data-keyword="subarray-nonempty">子数组</span>&nbsp;的能量值。</p>

<p>请你返回一个长度为 <code>n - k + 1</code>&nbsp;的整数数组&nbsp;<code>results</code>&nbsp;，其中&nbsp;<code>results[i]</code>&nbsp;是子数组&nbsp;<code>nums[i..(i + k - 1)]</code>&nbsp;的能量值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,3,2,5], k = 3</span></p>

<p><b>输出：</b>[3,4,-1,-1,-1]</p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中总共有 5 个长度为 3 的子数组：</p>

<ul>
	<li><code>[1, 2, 3]</code>&nbsp;中最大元素为 3 。</li>
	<li><code>[2, 3, 4]</code>&nbsp;中最大元素为 4 。</li>
	<li><code>[3, 4, 3]</code>&nbsp;中元素 <strong>不是</strong>&nbsp;连续的。</li>
	<li><code>[4, 3, 2]</code>&nbsp;中元素 <b>不是</b>&nbsp;上升的。</li>
	<li><code>[3, 2, 5]</code>&nbsp;中元素 <strong>不是</strong>&nbsp;连续的。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,2,2,2,2], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>[-1,-1]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,2,3,2,3,2], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>[-1,3,-1,3,-1]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

我们定义一个数组 $f$，其中 $f[i]$ 表示以第 $i$ 个元素结尾的连续上升子序列的长度。初始时 $f[i] = 1$。

接下来，我们遍历数组 $\textit{nums}$，计算数组 $f$ 的值。如果 $nums[i] = nums[i - 1] + 1$，则 $f[i] = f[i - 1] + 1$；否则 $f[i] = 1$。

然后，我们在 $[k - 1, n)$ 的范围内遍历数组 $f$，如果 $f[i] \ge k$，那么答案数组添加 $\textit{nums}$，否则添加 $-1$。

遍历结束后，返回答案数组。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        f = [1] * n
        for i in range(1, n):
            if nums[i] == nums[i - 1] + 1:
                f[i] = f[i - 1] + 1
        return [nums[i] if f[i] >= k else -1 for i in range(k - 1, n)]
```

#### Java

```java
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                f[i] = f[i - 1] + 1;
            }
        }
        int[] ans = new int[n - k + 1];
        for (int i = k - 1; i < n; ++i) {
            ans[i - k + 1] = f[i] >= k ? nums[i] : -1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = nums[i] == nums[i - 1] + 1 ? f[i - 1] + 1 : 1;
        }
        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            ans.push_back(f[i] >= k ? nums[i] : -1);
        }
        return ans;
    }
};
```

#### Go

```go
func resultsArray(nums []int, k int) (ans []int) {
	n := len(nums)
	f := make([]int, n)
	f[0] = 1
	for i := 1; i < n; i++ {
		if nums[i] == nums[i-1]+1 {
			f[i] = f[i-1] + 1
		} else {
			f[i] = 1
		}
	}
	for i := k - 1; i < n; i++ {
		if f[i] >= k {
			ans = append(ans, nums[i])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```

#### TypeScript

```ts
function resultsArray(nums: number[], k: number): number[] {
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        if (nums[i] === nums[i - 1] + 1) {
            f[i] = f[i - 1] + 1;
        }
    }
    const ans: number[] = [];
    for (let i = k - 1; i < n; ++i) {
        ans.push(f[i] >= k ? nums[i] : -1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### TypeScript

```ts
export function resultsArray(nums: number[], k: number): number[] {
    const n = nums.length;
    const ans: number[] = [];

    for (let i = 0, j = 0; i < n; i++) {
        if (i && nums[i - 1] + 1 !== nums[i]) j = i;
        if (i >= k - 1) {
            ans.push(i - k + 1 < j ? -1 : nums[i]);
        }
    }

    return ans;
}
```

#### JavaScript

```js
export function resultsArray(nums, k) {
    const n = nums.length;
    const ans = [];

    for (let i = 0, j = 0; i < n; i++) {
        if (i && nums[i - 1] + 1 !== nums[i]) j = i;
        if (i >= k - 1) {
            ans.push(i - k + 1 < j ? -1 : nums[i]);
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

# [3255. 长度为 K 的子数组的能量值 II](https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii){#3255}

{{< tabs "3255" >}}

{{% tab "python" %}}
```python
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        f = [1] * n
        for i in range(1, n):
            if nums[i] == nums[i - 1] + 1:
                f[i] = f[i - 1] + 1
        return [nums[i] if f[i] >= k else -1 for i in range(k - 1, n)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                f[i] = f[i - 1] + 1;
            }
        }
        int[] ans = new int[n - k + 1];
        for (int i = k - 1; i < n; ++i) {
            ans[i - k + 1] = f[i] >= k ? nums[i] : -1;
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
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = nums[i] == nums[i - 1] + 1 ? f[i - 1] + 1 : 1;
        }
        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            ans.push_back(f[i] >= k ? nums[i] : -1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func resultsArray(nums []int, k int) (ans []int) {
	n := len(nums)
	f := make([]int, n)
	f[0] = 1
	for i := 1; i < n; i++ {
		if nums[i] == nums[i-1]+1 {
			f[i] = f[i-1] + 1
		} else {
			f[i] = 1
		}
	}
	for i := k - 1; i < n; i++ {
		if f[i] >= k {
			ans = append(ans, nums[i])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function resultsArray(nums: number[], k: number): number[] {
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        if (nums[i] === nums[i - 1] + 1) {
            f[i] = f[i - 1] + 1;
        }
    }
    const ans: number[] = [];
    for (let i = k - 1; i < n; ++i) {
        ans.push(f[i] >= k ? nums[i] : -1);
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一个数组的 <strong>能量值</strong> 定义为：</p>

<ul>
	<li>如果 <strong>所有</strong>&nbsp;元素都是依次&nbsp;<strong>连续</strong>（即 <code>nums[i] + 1 = nums[i + 1]</code>，<code>i &lt; n</code>）且 <strong>上升</strong> 的，那么能量值为 <strong>最大</strong>&nbsp;的元素。</li>
	<li>否则为 -1 。</li>
</ul>

<p>你需要求出 <code>nums</code>&nbsp;中所有长度为 <code>k</code>&nbsp;的&nbsp;<span data-keyword="subarray-nonempty">子数组</span>&nbsp;的能量值。</p>

<p>请你返回一个长度为 <code>n - k + 1</code>&nbsp;的整数数组&nbsp;<code>results</code>&nbsp;，其中&nbsp;<code>results[i]</code>&nbsp;是子数组&nbsp;<code>nums[i..(i + k - 1)]</code>&nbsp;的能量值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,3,2,5], k = 3</span></p>

<p><b>输出：</b>[3,4,-1,-1,-1]</p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中总共有 5 个长度为 3 的子数组：</p>

<ul>
	<li><code>[1, 2, 3]</code>&nbsp;中最大元素为 3 。</li>
	<li><code>[2, 3, 4]</code>&nbsp;中最大元素为 4 。</li>
	<li><code>[3, 4, 3]</code>&nbsp;中元素 <strong>不是</strong>&nbsp;连续的。</li>
	<li><code>[4, 3, 2]</code>&nbsp;中元素 <b>不是</b>&nbsp;上升的。</li>
	<li><code>[3, 2, 5]</code>&nbsp;中元素 <strong>不是</strong>&nbsp;连续的。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,2,2,2,2], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>[-1,-1]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,2,3,2,3,2], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>[-1,3,-1,3,-1]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

我们定义一个数组 $f$，其中 $f[i]$ 表示以第 $i$ 个元素结尾的连续上升子序列的长度。初始时 $f[i] = 1$。

接下来，我们遍历数组 $\textit{nums}$，计算数组 $f$ 的值。如果 $nums[i] = nums[i - 1] + 1$，则 $f[i] = f[i - 1] + 1$；否则 $f[i] = 1$。

然后，我们在 $[k - 1, n)$ 的范围内遍历数组 $f$，如果 $f[i] \ge k$，那么答案数组添加 $\textit{nums}$，否则添加 $-1$。

遍历结束后，返回答案数组。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        f = [1] * n
        for i in range(1, n):
            if nums[i] == nums[i - 1] + 1:
                f[i] = f[i - 1] + 1
        return [nums[i] if f[i] >= k else -1 for i in range(k - 1, n)]
```

#### Java

```java
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                f[i] = f[i - 1] + 1;
            }
        }
        int[] ans = new int[n - k + 1];
        for (int i = k - 1; i < n; ++i) {
            ans[i - k + 1] = f[i] >= k ? nums[i] : -1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = nums[i] == nums[i - 1] + 1 ? f[i - 1] + 1 : 1;
        }
        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            ans.push_back(f[i] >= k ? nums[i] : -1);
        }
        return ans;
    }
};
```

#### Go

```go
func resultsArray(nums []int, k int) (ans []int) {
	n := len(nums)
	f := make([]int, n)
	f[0] = 1
	for i := 1; i < n; i++ {
		if nums[i] == nums[i-1]+1 {
			f[i] = f[i-1] + 1
		} else {
			f[i] = 1
		}
	}
	for i := k - 1; i < n; i++ {
		if f[i] >= k {
			ans = append(ans, nums[i])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```

#### TypeScript

```ts
function resultsArray(nums: number[], k: number): number[] {
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        if (nums[i] === nums[i - 1] + 1) {
            f[i] = f[i - 1] + 1;
        }
    }
    const ans: number[] = [];
    for (let i = k - 1; i < n; ++i) {
        ans.push(f[i] >= k ? nums[i] : -1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3256. 放三个车的价值之和最大 I](https://leetcode.cn/problems/maximum-value-sum-by-placing-three-rooks-i){#3256}

{{< tabs "3256" >}}

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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二维整数数组&nbsp;<code>board</code>&nbsp;，它表示一个国际象棋棋盘，其中&nbsp;<code>board[i][j]</code>&nbsp;表示格子 <code>(i, j)</code>&nbsp;的 <strong>价值</strong>&nbsp;。</p>

<p>处于 <strong>同一行</strong>&nbsp;或者 <strong>同一列</strong>&nbsp;车会互相 <strong>攻击</strong>&nbsp;。你需要在棋盘上放三个车，确保它们两两之间都&nbsp;<b>无法互相攻击</b>&nbsp;。</p>

<p>请你返回满足上述条件下，三个车所在格子 <strong>值</strong>&nbsp;之和 <strong>最大</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>board = </span>[[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]</p>

<p><b>输出：</b>4</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3256.Maximum%20Value%20Sum%20by%20Placing%20Three%20Rooks%20I/images/rooks2.png" style="width: 294px; height: 450px;" /></p>

<p>我们可以将车分别放在格子&nbsp;<code>(0, 2)</code>&nbsp;，<code>(1, 3)</code>&nbsp;和&nbsp;<code>(2, 1)</code>&nbsp;处，价值之和为&nbsp;<code>1 + 1 + 2 = 4</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>board = [[1,2,3],[4,5,6],[7,8,9]]</span></p>

<p><span class="example-io"><b>输出：</b>15</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将车分别放在格子&nbsp;<code>(0, 0)</code>&nbsp;，<code>(1, 1)</code>&nbsp;和&nbsp;<code>(2, 2)</code>&nbsp;处，价值之和为&nbsp;<code>1 + 5 + 9 = 15</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>board = [[1,1,1],[1,1,1],[1,1,1]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将车分别放在格子&nbsp;<code>(0, 2)</code>&nbsp;，<code>(1, 1)</code>&nbsp;和&nbsp;<code>(2, 0)</code>&nbsp;处，价值之和为&nbsp;<code>1 + 1 + 1 = 3</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= m == board.length &lt;= 100</code></li>
	<li><code>3 &lt;= n == board[i].length &lt;= 100</code></li>
	<li><code>-10<sup>9</sup> &lt;= board[i][j] &lt;= 10<sup>9</sup></code></li>
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

# [3257. 放三个车的价值之和最大 II](https://leetcode.cn/problems/maximum-value-sum-by-placing-three-rooks-ii){#3257}

{{< tabs "3257" >}}

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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二维整数数组&nbsp;<code>board</code>&nbsp;，它表示一个国际象棋棋盘，其中&nbsp;<code>board[i][j]</code>&nbsp;表示格子 <code>(i, j)</code>&nbsp;的 <strong>价值</strong>&nbsp;。</p>

<p>处于 <strong>同一行</strong>&nbsp;或者 <strong>同一列</strong>&nbsp;车会互相 <strong>攻击</strong>&nbsp;。你需要在棋盘上放三个车，确保它们两两之间都&nbsp;<b>无法互相攻击</b>&nbsp;。</p>

<p>请你返回满足上述条件下，三个车所在格子 <strong>值</strong>&nbsp;之和 <strong>最大</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>board = </span>[[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]</p>

<p><b>输出：</b>4</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3257.Maximum%20Value%20Sum%20by%20Placing%20Three%20Rooks%20II/images/rooks2.png" style="width: 294px; height: 450px;" /></p>

<p>我们可以将车分别放在格子&nbsp;<code>(0, 2)</code>&nbsp;，<code>(1, 3)</code>&nbsp;和&nbsp;<code>(2, 1)</code>&nbsp;处，价值之和为&nbsp;<code>1 + 1 + 2 = 4</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>board = [[1,2,3],[4,5,6],[7,8,9]]</span></p>

<p><span class="example-io"><b>输出：</b>15</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将车分别放在格子&nbsp;<code>(0, 0)</code>&nbsp;，<code>(1, 1)</code>&nbsp;和&nbsp;<code>(2, 2)</code>&nbsp;处，价值之和为&nbsp;<code>1 + 5 + 9 = 15</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>board = [[1,1,1],[1,1,1],[1,1,1]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将车分别放在格子&nbsp;<code>(0, 2)</code>&nbsp;，<code>(1, 1)</code>&nbsp;和&nbsp;<code>(2, 0)</code>&nbsp;处，价值之和为&nbsp;<code>1 + 1 + 1 = 3</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= m == board.length &lt;= 500</code></li>
	<li><code>3 &lt;= n == board[i].length &lt;= 500</code></li>
	<li><code>-10<sup>9</sup> &lt;= board[i][j] &lt;= 10<sup>9</sup></code></li>
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

# [3258. 统计满足 K 约束的子字符串数量 I](https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i){#3258}

{{< tabs "3258" >}}

{{% tab "python" %}}
```python
class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        cnt = [0, 0]
        ans = l = 0
        for r, x in enumerate(map(int, s)):
            cnt[x] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[int(s[l])] -= 1
                l += 1
            ans += r - l + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int[] cnt = new int[2];
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            ++cnt[s.charAt(r) - '0'];
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s.charAt(l++) - '0']--;
            }
            ans += r - l + 1;
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
    int countKConstraintSubstrings(string s, int k) {
        int cnt[2]{};
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l++] - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countKConstraintSubstrings(s string, k int) (ans int) {
	cnt := [2]int{}
	l := 0
	for r, c := range s {
		cnt[c-'0']++
		for ; cnt[0] > k && cnt[1] > k; l++ {
			cnt[s[l]-'0']--
		}
		ans += r - l + 1
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countKConstraintSubstrings(s: string, k: number): number {
    const cnt: [number, number] = [0, 0];
    let [ans, l] = [0, 0];
    for (let r = 0; r < s.length; ++r) {
        cnt[+s[r]]++;
        while (cnt[0] > k && cnt[1] > k) {
            cnt[+s[l++]]--;
        }
        ans += r - l + 1;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_k_constraint_substrings(s: String, k: i32) -> i32 {
        let mut cnt = [0; 2];
        let mut l = 0;
        let mut ans = 0;
        let s = s.as_bytes();

        for (r, &c) in s.iter().enumerate() {
            cnt[(c - b'0') as usize] += 1;
            while cnt[0] > k && cnt[1] > k {
                cnt[(s[l] - b'0') as usize] -= 1;
                l += 1;
            }
            ans += r - l + 1;
        }

        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>二进制</strong> 字符串 <code>s</code> 和一个整数 <code>k</code>。</p>

<p>如果一个 <strong>二进制字符串</strong> 满足以下任一条件，则认为该字符串满足 <strong>k 约束</strong>：</p>

<ul>
	<li>字符串中 <code>0</code> 的数量最多为 <code>k</code>。</li>
	<li>字符串中 <code>1</code> 的数量最多为 <code>k</code>。</li>
</ul>

<p>返回一个整数，表示 <code>s</code> 的所有满足 <strong>k 约束 </strong>的<span data-keyword="substring-nonempty">子字符串</span>的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "10101", k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">12</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串中，除了 <code>"1010"</code>、<code>"10101"</code> 和 <code>"0101"</code> 外，其余子字符串都满足 k 约束。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "1010101", k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">25</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串中，除了长度大于 5 的子字符串外，其余子字符串都满足 k 约束。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "11111", k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串都满足 k 约束。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s[i]</code> 是 <code>'0'</code> 或 <code>'1'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们用两个变量 $\textit{cnt0}$ 和 $\textit{cnt1}$ 分别记录当前窗口内的 $0$ 和 $1$ 的个数，用 $\textit{ans}$ 记录满足 $k$ 约束的子字符串的个数，用 $l$ 记录窗口的左边界。

当我们右移窗口时，如果窗口内的 $0$ 和 $1$ 的个数都大于 $k$，我们就需要左移窗口，直到窗口内的 $0$ 和 $1$ 的个数都不大于 $k$。此时，窗口内所有以 $r$ 作为右端点的子字符串都满足 $k$ 约束，个数为 $r - l + 1$，其中 $r$ 是窗口的右边界。我们将这个个数累加到 $\textit{ans}$ 中。

最后，我们返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        cnt = [0, 0]
        ans = l = 0
        for r, x in enumerate(map(int, s)):
            cnt[x] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[int(s[l])] -= 1
                l += 1
            ans += r - l + 1
        return ans
```

#### Java

```java
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int[] cnt = new int[2];
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            ++cnt[s.charAt(r) - '0'];
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s.charAt(l++) - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt[2]{};
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l++] - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func countKConstraintSubstrings(s string, k int) (ans int) {
	cnt := [2]int{}
	l := 0
	for r, c := range s {
		cnt[c-'0']++
		for ; cnt[0] > k && cnt[1] > k; l++ {
			cnt[s[l]-'0']--
		}
		ans += r - l + 1
	}
	return
}
```

#### TypeScript

```ts
function countKConstraintSubstrings(s: string, k: number): number {
    const cnt: [number, number] = [0, 0];
    let [ans, l] = [0, 0];
    for (let r = 0; r < s.length; ++r) {
        cnt[+s[r]]++;
        while (cnt[0] > k && cnt[1] > k) {
            cnt[+s[l++]]--;
        }
        ans += r - l + 1;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_k_constraint_substrings(s: String, k: i32) -> i32 {
        let mut cnt = [0; 2];
        let mut l = 0;
        let mut ans = 0;
        let s = s.as_bytes();

        for (r, &c) in s.iter().enumerate() {
            cnt[(c - b'0') as usize] += 1;
            while cnt[0] > k && cnt[1] > k {
                cnt[(s[l] - b'0') as usize] -= 1;
                l += 1;
            }
            ans += r - l + 1;
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3259. 超级饮料的最大强化能量](https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks){#3259}

{{< tabs "3259" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        f, g = energyDrinkA[0], energyDrinkB[0]
        for a, b in zip(energyDrinkA[1:], energyDrinkB[1:]):
            f, g = max(f + a, g), max(g + b, f)
        return max(f, g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        int n = energyDrinkA.length;
        long f = energyDrinkA[0], g = energyDrinkB[0];
        for (int i = 1; i < n; ++i) {
            long ff = Math.max(f + energyDrinkA[i], g);
            g = Math.max(g + energyDrinkB[i], f);
            f = ff;
        }
        return Math.max(f, g);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        long long f = energyDrinkA[0], g = energyDrinkB[0];
        for (int i = 1; i < n; ++i) {
            long long ff = max(f + energyDrinkA[i], g);
            g = max(g + energyDrinkB[i], f);
            f = ff;
        }
        return max(f, g);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
	n := len(energyDrinkA)
	f, g := energyDrinkA[0], energyDrinkB[0]
	for i := 1; i < n; i++ {
		f, g = max(f+energyDrinkA[i], g), max(g+energyDrinkB[i], f)
	}
	return int64(max(f, g))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxEnergyBoost(energyDrinkA: number[], energyDrinkB: number[]): number {
    const n = energyDrinkA.length;
    let [f, g] = [energyDrinkA[0], energyDrinkB[0]];
    for (let i = 1; i < n; ++i) {
        [f, g] = [Math.max(f + energyDrinkA[i], g), Math.max(g + energyDrinkB[i], f)];
    }
    return Math.max(f, g);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>来自未来的体育科学家给你两个整数数组 <code>energyDrinkA</code> 和 <code>energyDrinkB</code>，数组长度都等于 <code>n</code>。这两个数组分别代表 A、B 两种不同能量饮料每小时所能提供的强化能量。</p>

<p>你需要每小时饮用一种能量饮料来 <strong>最大化 </strong>你的总强化能量。然而，如果从一种能量饮料切换到另一种，你需要等待一小时来梳理身体的能量体系（在那个小时里你将不会获得任何强化能量）。</p>

<p>返回在接下来的 <code>n</code> 小时内你能获得的<strong> 最大 </strong>总强化能量。</p>

<p><strong>注意 </strong>你可以选择从饮用任意一种能量饮料开始。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>energyDrinkA<span class="example-io"> = [1,3,1], </span>energyDrinkB<span class="example-io"> = [3,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>要想获得 5 点强化能量，需要选择只饮用能量饮料 A（或者只饮用 B）。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>energyDrinkA<span class="example-io"> = [4,1,1], </span>energyDrinkB<span class="example-io"> = [1,1,3]</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第一个小时饮用能量饮料 A。</li>
	<li>切换到能量饮料 B ，在第二个小时无法获得强化能量。</li>
	<li>第三个小时饮用能量饮料 B ，并获得强化能量。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == energyDrinkA.length == energyDrinkB.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= energyDrinkA[i], energyDrinkB[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][0]$ 表示在第 $i$ 小时选择能量饮料 A 获得的最大强化能量，定义 $f[i][1]$ 表示在第 $i$ 小时选择能量饮料 B 获得的最大强化能量。初始时 $f[0][0] = \textit{energyDrinkA}[0]$, $f[0][1] = \textit{energyDrinkB}[0]$。答案为 $\max(f[n - 1][0], f[n - 1][1])$。

对于 $i > 0$，我们有以下状态转移方程：

$$
\begin{aligned}
f[i][0] & = \max(f[i - 1][0] + \textit{energyDrinkA}[i], f[i - 1][1]) \\
f[i][1] & = \max(f[i - 1][1] + \textit{energyDrinkB}[i], f[i - 1][0])
\end{aligned}
$$

最后返回 $\max(f[n - 1][0], f[n - 1][1])$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        f = [[0] * 2 for _ in range(n)]
        f[0][0] = energyDrinkA[0]
        f[0][1] = energyDrinkB[0]
        for i in range(1, n):
            f[i][0] = max(f[i - 1][0] + energyDrinkA[i], f[i - 1][1])
            f[i][1] = max(f[i - 1][1] + energyDrinkB[i], f[i - 1][0])
        return max(f[n - 1])
```

#### Java

```java
class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        int n = energyDrinkA.length;
        long[][] f = new long[n][2];
        f[0][0] = energyDrinkA[0];
        f[0][1] = energyDrinkB[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = Math.max(f[i - 1][0] + energyDrinkA[i], f[i - 1][1]);
            f[i][1] = Math.max(f[i - 1][1] + energyDrinkB[i], f[i - 1][0]);
        }
        return Math.max(f[n - 1][0], f[n - 1][1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> f(n, vector<long long>(2));
        f[0][0] = energyDrinkA[0];
        f[0][1] = energyDrinkB[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0] + energyDrinkA[i], f[i - 1][1]);
            f[i][1] = max(f[i - 1][1] + energyDrinkB[i], f[i - 1][0]);
        }
        return max(f[n - 1][0], f[n - 1][1]);
    }
};
```

#### Go

```go
func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
	n := len(energyDrinkA)
	f := make([][2]int64, n)
	f[0][0] = int64(energyDrinkA[0])
	f[0][1] = int64(energyDrinkB[0])
	for i := 1; i < n; i++ {
		f[i][0] = max(f[i-1][0]+int64(energyDrinkA[i]), f[i-1][1])
		f[i][1] = max(f[i-1][1]+int64(energyDrinkB[i]), f[i-1][0])
	}
	return max(f[n-1][0], f[n-1][1])
}
```

#### TypeScript

```ts
function maxEnergyBoost(energyDrinkA: number[], energyDrinkB: number[]): number {
    const n = energyDrinkA.length;
    const f: number[][] = Array.from({ length: n }, () => [0, 0]);
    f[0][0] = energyDrinkA[0];
    f[0][1] = energyDrinkB[0];
    for (let i = 1; i < n; i++) {
        f[i][0] = Math.max(f[i - 1][0] + energyDrinkA[i], f[i - 1][1]);
        f[i][1] = Math.max(f[i - 1][1] + energyDrinkB[i], f[i - 1][0]);
    }
    return Math.max(...f[n - 1]!);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们注意到，状态 $f[i]$ 至于 $f[i - 1]$ 有关，而与 $f[i - 2]$ 无关。因此我们可以只使用两个变量 $f$ 和 $g$ 来维护状态，从而将空间复杂度优化到 $O(1)$。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        f, g = energyDrinkA[0], energyDrinkB[0]
        for a, b in zip(energyDrinkA[1:], energyDrinkB[1:]):
            f, g = max(f + a, g), max(g + b, f)
        return max(f, g)
```

#### Java

```java
class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        int n = energyDrinkA.length;
        long f = energyDrinkA[0], g = energyDrinkB[0];
        for (int i = 1; i < n; ++i) {
            long ff = Math.max(f + energyDrinkA[i], g);
            g = Math.max(g + energyDrinkB[i], f);
            f = ff;
        }
        return Math.max(f, g);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        long long f = energyDrinkA[0], g = energyDrinkB[0];
        for (int i = 1; i < n; ++i) {
            long long ff = max(f + energyDrinkA[i], g);
            g = max(g + energyDrinkB[i], f);
            f = ff;
        }
        return max(f, g);
    }
};
```

#### Go

```go
func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
	n := len(energyDrinkA)
	f, g := energyDrinkA[0], energyDrinkB[0]
	for i := 1; i < n; i++ {
		f, g = max(f+energyDrinkA[i], g), max(g+energyDrinkB[i], f)
	}
	return int64(max(f, g))
}
```

#### TypeScript

```ts
function maxEnergyBoost(energyDrinkA: number[], energyDrinkB: number[]): number {
    const n = energyDrinkA.length;
    let [f, g] = [energyDrinkA[0], energyDrinkB[0]];
    for (let i = 1; i < n; ++i) {
        [f, g] = [Math.max(f + energyDrinkA[i], g), Math.max(g + energyDrinkB[i], f)];
    }
    return Math.max(f, g);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
