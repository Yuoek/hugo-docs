---
title: "1770_执行乘法运算的最大分数"
date: 2025-10-08T18:38:17+08:00
weight: 8
tags: [交互, 动态规划, 单调栈, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 深度优先搜索, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [1770_执行乘法运算的最大分数](#1770)
#### [数组](#1770)
#### [动态规划](#1770)
### [1771_由子序列构造的最长回文串的长度](#1771)
#### [字符串](#1771)
#### [动态规划](#1771)
### [1772_按受欢迎程度排列功能 🔒](#1772)
#### [数组](#1772)
#### [哈希表](#1772)
#### [字符串](#1772)
#### [排序](#1772)
### [1773_统计匹配检索规则的物品数量](#1773)
#### [数组](#1773)
#### [字符串](#1773)
### [1774_最接近目标价格的甜点成本](#1774)
#### [数组](#1774)
#### [动态规划](#1774)
#### [回溯](#1774)
### [1775_通过最少操作次数使数组的和相等](#1775)
#### [贪心](#1775)
#### [数组](#1775)
#### [哈希表](#1775)
#### [计数](#1775)
### [1776_车队 II](#1776)
#### [栈](#1776)
#### [数组](#1776)
#### [数学](#1776)
#### [单调栈](#1776)
#### [堆（优先队列）](#1776)
### [1777_每家商店的产品价格 🔒](#1777)
#### [数据库](#1777)
### [1778_未知网格中的最短路径 🔒](#1778)
#### [深度优先搜索](#1778)
#### [广度优先搜索](#1778)
#### [数组](#1778)
#### [交互](#1778)
#### [矩阵](#1778)
### [1779_找到最近的有相同 X 或 Y 坐标的点](#1779)
#### [数组](#1779)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1770_执行乘法运算的最大分数
___
#### 数组
___
#### 动态规划
---
### 1771_由子序列构造的最长回文串的长度
___
#### 字符串
___
#### 动态规划
---
### 1772_按受欢迎程度排列功能 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 1773_统计匹配检索规则的物品数量
___
#### 数组
___
#### 字符串
---
### 1774_最接近目标价格的甜点成本
___
#### 数组
___
#### 动态规划
___
#### 回溯
---
### 1775_通过最少操作次数使数组的和相等
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1776_车队 II
___
#### 栈
___
#### 数组
___
#### 数学
___
#### 单调栈
___
#### 堆（优先队列）
---
### 1777_每家商店的产品价格 🔒
___
#### 数据库
---
### 1778_未知网格中的最短路径 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 交互
___
#### 矩阵
---
### 1779_找到最近的有相同 X 或 Y 坐标的点
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 交互 | 动态规划 | 单调栈 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 深度优先搜索 | 矩阵 |
| 计数 | 贪心 |  |

# [1770. 执行乘法运算的最大分数](https://leetcode.cn/problems/maximum-score-from-performing-multiplication-operations){#1770}

{{< tabs "1770" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n, m = len(nums), len(multipliers)
        f = [[-inf] * (m + 1) for _ in range(m + 1)]
        f[0][0] = 0
        ans = -inf
        for i in range(m + 1):
            for j in range(m - i + 1):
                k = i + j - 1
                if i > 0:
                    f[i][j] = max(f[i][j], f[i - 1][j] + multipliers[k] * nums[i - 1])
                if j > 0:
                    f[i][j] = max(f[i][j], f[i][j - 1] + multipliers[k] * nums[n - j])
                if i + j == m:
                    ans = max(ans, f[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        final int inf = 1 << 30;
        int n = nums.length, m = multipliers.length;
        int[][] f = new int[m + 1][m + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(f[i], -inf);
        }
        f[0][0] = 0;
        int ans = -inf;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m - i; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j] + multipliers[k] * nums[i - 1]);
                }
                if (j > 0) {
                    f[i][j] = Math.max(f[i][j], f[i][j - 1] + multipliers[k] * nums[n - j]);
                }
                if (i + j == m) {
                    ans = Math.max(ans, f[i][j]);
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
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int inf = 1 << 30;
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> f(m + 1, vector<int>(m + 1, -inf));
        f[0][0] = 0;
        int ans = -inf;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m - i; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j] + multipliers[k] * nums[i - 1]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], f[i][j - 1] + multipliers[k] * nums[n - j]);
                }
                if (i + j == m) {
                    ans = max(ans, f[i][j]);
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
func maximumScore(nums []int, multipliers []int) int {
	const inf int = 1 << 30
	n, m := len(nums), len(multipliers)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, m+1)
		for j := range f {
			f[i][j] = -inf
		}
	}
	f[0][0] = 0
	ans := -inf
	for i := 0; i <= m; i++ {
		for j := 0; j <= m-i; j++ {
			k := i + j - 1
			if i > 0 {
				f[i][j] = max(f[i][j], f[i-1][j]+multipliers[k]*nums[i-1])
			}
			if j > 0 {
				f[i][j] = max(f[i][j], f[i][j-1]+multipliers[k]*nums[n-j])
			}
			if i+j == m {
				ans = max(ans, f[i][j])
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumScore(nums: number[], multipliers: number[]): number {
    const inf = 1 << 30;
    const n = nums.length;
    const m = multipliers.length;
    const f = new Array(m + 1).fill(0).map(() => new Array(m + 1).fill(-inf));
    f[0][0] = 0;
    let ans = -inf;
    for (let i = 0; i <= m; ++i) {
        for (let j = 0; j <= m - i; ++j) {
            const k = i + j - 1;
            if (i > 0) {
                f[i][j] = Math.max(f[i][j], f[i - 1][j] + nums[i - 1] * multipliers[k]);
            }
            if (j > 0) {
                f[i][j] = Math.max(f[i][j], f[i][j - 1] + nums[n - j] * multipliers[k]);
            }
            if (i + j === m) {
                ans = Math.max(ans, f[i][j]);
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

<p>给你两个长度分别 <code>n</code> 和 <code>m</code> 的整数数组 <code>nums</code> 和 <code>multipliers</code><strong> </strong>，其中 <code>n &gt;= m</code> ，数组下标 <strong>从 1 开始</strong> 计数。</p>

<p>初始时，你的分数为 <code>0</code> 。你需要执行恰好 <code>m</code> 步操作。在第 <code>i</code> 步操作（<strong>从 1 开始</strong> 计数）中，需要：</p>

<ul>
	<li>选择数组 <code>nums</code> <strong>开头处或者末尾处</strong> 的整数 <code>x</code> 。</li>
	<li>你获得 <code>multipliers[i] * x</code> 分，并累加到你的分数中。</li>
	<li>将 <code>x</code> 从数组 <code>nums</code> 中移除。</li>
</ul>

<p>在执行<em> </em><code>m</code> 步操作后，返回 <strong>最大</strong> 分数<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3], multipliers = [3,2,1]
<strong>输出：</strong>14
<strong>解释：</strong>一种最优解决方案如下：
- 选择末尾处的整数 3 ，[1,2,<strong>3</strong>] ，得 3 * 3 = 9 分，累加到分数中。
- 选择末尾处的整数 2 ，[1,<strong>2</strong>] ，得 2 * 2 = 4 分，累加到分数中。
- 选择末尾处的整数 1 ，[<strong>1</strong>] ，得 1 * 1 = 1 分，累加到分数中。
总分数为 9 + 4 + 1 = 14 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
<strong>输出：</strong>102
<strong>解释：</strong>一种最优解决方案如下：
- 选择开头处的整数 -5 ，[<strong>-5</strong>,-3,-3,-2,7,1] ，得 -5 * -10 = 50 分，累加到分数中。
- 选择开头处的整数 -3 ，[<strong>-3</strong>,-3,-2,7,1] ，得 -3 * -5 = 15 分，累加到分数中。
- 选择开头处的整数 -3 ，[<strong>-3</strong>,-2,7,1] ，得 -3 * 3 = -9 分，累加到分数中。
- 选择末尾处的整数 1 ，[-2,7,<strong>1</strong>] ，得 1 * 4 = 4 分，累加到分数中。
- 选择末尾处的整数 7 ，[-2,<strong>7</strong>] ，得 7 * 6 = 42 分，累加到分数中。
总分数为 50 + 15 - 9 + 4 + 42 = 102 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == multipliers.length</code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>3</sup></code></li>
	<li><code>m &lt;= n &lt;= 10<sup>5</sup></code><code> </code></li>
	<li><code>-1000 &lt;= nums[i], multipliers[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从 `nums` 数组头部第 $i$ 个元素开始，从 `nums` 数组尾部第 $j$ 个元素开始，能够获得的最大分数。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $i \geq m$ 或者 $j \geq m$，或者 $i + j \geq m$，说明已经没有元素可以选择了，返回 $0$。
-   否则，我们可以选择 `nums` 数组头部第 $i$ 个元素，那么能够获取的最大分数为 $nums[i] \times multipliers[i + j] + dfs(i + 1, j)$；或者我们可以选择 `nums` 数组尾部第 $j$ 个元素，那么能够获取的最大分数为 $nums[n - j - 1] \times multipliers[i + j] + dfs(i, j + 1)$。我们取两者的最大值作为 $dfs(i, j)$ 的返回值。

我们可以使用记忆化搜索来实现上述递归过程，其中 `f` 数组用于存储函数 $dfs(i, j)$ 的返回值，防止重复计算。

时间复杂度 $O(m^2)$，空间复杂度 $O(m^2)$。其中 $m$ 为 `multipliers` 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        @cache
        def f(i, j, k):
            if k >= m or i >= n or j < 0:
                return 0
            a = f(i + 1, j, k + 1) + nums[i] * multipliers[k]
            b = f(i, j - 1, k + 1) + nums[j] * multipliers[k]
            return max(a, b)

        n = len(nums)
        m = len(multipliers)
        return f(0, n - 1, 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[] multipliers;
    private int[] nums;
    private int n;
    private int m;

    public int maximumScore(int[] nums, int[] multipliers) {
        n = nums.length;
        m = multipliers.length;
        f = new Integer[m][m];
        this.nums = nums;
        this.multipliers = multipliers;
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= m || j >= m || (i + j) >= m) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int k = i + j;
        int a = dfs(i + 1, j) + nums[i] * multipliers[k];
        int b = dfs(i, j + 1) + nums[n - 1 - j] * multipliers[k];
        f[i][j] = Math.max(a, b);
        return f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        int f[m][m];
        memset(f, 0x3f, sizeof f);
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= m || j >= m || (i + j) >= m) return 0;
            if (f[i][j] != 0x3f3f3f3f) return f[i][j];
            int k = i + j;
            int a = dfs(i + 1, j) + nums[i] * multipliers[k];
            int b = dfs(i, j + 1) + nums[n - j - 1] * multipliers[k];
            return f[i][j] = max(a, b);
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func maximumScore(nums []int, multipliers []int) int {
	n, m := len(nums), len(multipliers)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = 1 << 30
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= m || j >= m || i+j >= m {
			return 0
		}
		if f[i][j] != 1<<30 {
			return f[i][j]
		}
		k := i + j
		a := dfs(i+1, j) + nums[i]*multipliers[k]
		b := dfs(i, j+1) + nums[n-j-1]*multipliers[k]
		f[i][j] = max(a, b)
		return f[i][j]
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function maximumScore(nums: number[], multipliers: number[]): number {
    const inf = 1 << 30;
    const n = nums.length;
    const m = multipliers.length;
    const f = new Array(m + 1).fill(0).map(() => new Array(m + 1).fill(-inf));
    f[0][0] = 0;
    let ans = -inf;
    for (let i = 0; i <= m; ++i) {
        for (let j = 0; j <= m - i; ++j) {
            const k = i + j - 1;
            if (i > 0) {
                f[i][j] = Math.max(f[i][j], f[i - 1][j] + nums[i - 1] * multipliers[k]);
            }
            if (j > 0) {
                f[i][j] = Math.max(f[i][j], f[i][j - 1] + nums[n - j] * multipliers[k]);
            }
            if (i + j === m) {
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索改写为动态规划的形式。

我们用 $f[i][j]$ 表示取数组 $nums$ 的前 $i$ 个元素，以及取数组 $nums$ 的后 $j$ 个元素，能够获得的最大分数。初始时 $f[0][0] = 0$，其余元素均为 $-\infty$。答案为 $\max_{0 \leq i \leq m} f[i][m-i]$。

考虑 $f[i][j]$，那么当前我们可以选择 `nums` 数组头部的第 $i$ 个元素，或者选择 `nums` 数组尾部的第 $j$ 个元素。如果选择了 `nums` 数组头部的第 $i$ 个元素，那么能够获得的最大分数为 $f[i-1][j] + nums[i-1] \times multipliers[i+j-1]$；如果选择了 `nums` 数组尾部的第 $j$ 个元素，那么能够获得的最大分数为 $f[i][j-1] + nums[n-j] \times multipliers[i+j-1]$。我们取两者的最大值作为 $f[i][j]$ 的值。如果 $i + j = m$，我们我们更新答案 $ans = \max(ans, f[i][j])$。

最后返回答案 $ans$ 即可。

时间复杂度 $O(m^2)$，空间复杂度 $O(m^2)$。其中 $m$ 为 `multipliers` 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n, m = len(nums), len(multipliers)
        f = [[-inf] * (m + 1) for _ in range(m + 1)]
        f[0][0] = 0
        ans = -inf
        for i in range(m + 1):
            for j in range(m - i + 1):
                k = i + j - 1
                if i > 0:
                    f[i][j] = max(f[i][j], f[i - 1][j] + multipliers[k] * nums[i - 1])
                if j > 0:
                    f[i][j] = max(f[i][j], f[i][j - 1] + multipliers[k] * nums[n - j])
                if i + j == m:
                    ans = max(ans, f[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        final int inf = 1 << 30;
        int n = nums.length, m = multipliers.length;
        int[][] f = new int[m + 1][m + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(f[i], -inf);
        }
        f[0][0] = 0;
        int ans = -inf;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m - i; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j] + multipliers[k] * nums[i - 1]);
                }
                if (j > 0) {
                    f[i][j] = Math.max(f[i][j], f[i][j - 1] + multipliers[k] * nums[n - j]);
                }
                if (i + j == m) {
                    ans = Math.max(ans, f[i][j]);
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
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int inf = 1 << 30;
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> f(m + 1, vector<int>(m + 1, -inf));
        f[0][0] = 0;
        int ans = -inf;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m - i; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j] + multipliers[k] * nums[i - 1]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], f[i][j - 1] + multipliers[k] * nums[n - j]);
                }
                if (i + j == m) {
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumScore(nums []int, multipliers []int) int {
	const inf int = 1 << 30
	n, m := len(nums), len(multipliers)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, m+1)
		for j := range f {
			f[i][j] = -inf
		}
	}
	f[0][0] = 0
	ans := -inf
	for i := 0; i <= m; i++ {
		for j := 0; j <= m-i; j++ {
			k := i + j - 1
			if i > 0 {
				f[i][j] = max(f[i][j], f[i-1][j]+multipliers[k]*nums[i-1])
			}
			if j > 0 {
				f[i][j] = max(f[i][j], f[i][j-1]+multipliers[k]*nums[n-j])
			}
			if i+j == m {
				ans = max(ans, f[i][j])
			}
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

# [1771. 由子序列构造的最长回文串的长度](https://leetcode.cn/problems/maximize-palindrome-length-from-subsequences){#1771}

{{< tabs "1771" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        s = word1 + word2
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        ans = 0
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                    if i < len(word1) <= j:
                        ans = max(ans, f[i][j])
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestPalindrome(String word1, String word2) {
        String s = word1 + word2;
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if (i < word1.length() && j >= word1.length()) {
                        ans = Math.max(ans, f[i][j]);
                    }
                } else {
                    f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
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
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) f[i][i] = 1;
        int ans = 0;
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if (i < word1.size() && j >= word1.size()) {
                        ans = max(ans, f[i][j]);
                    }
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
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
func longestPalindrome(word1 string, word2 string) (ans int) {
	s := word1 + word2
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1] + 2
				if i < len(word1) && j >= len(word1) && ans < f[i][j] {
					ans = f[i][j]
				}
			} else {
				f[i][j] = max(f[i+1][j], f[i][j-1])
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPalindrome(word1: string, word2: string): number {
    const s = word1 + word2;
    const n = s.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }
    let ans = 0;
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
                if (i < word1.length && j >= word1.length) {
                    ans = Math.max(ans, f[i][j]);
                }
            } else {
                f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_palindrome(word1: String, word2: String) -> i32 {
        let s: Vec<char> = format!("{}{}", word1, word2).chars().collect();
        let n = s.len();
        let mut f = vec![vec![0; n]; n];
        for i in 0..n {
            f[i][i] = 1;
        }
        let mut ans = 0;
        for i in (0..n - 1).rev() {
            for j in i + 1..n {
                if s[i] == s[j] {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if i < word1.len() && j >= word1.len() {
                        ans = ans.max(f[i][j]);
                    }
                } else {
                    f[i][j] = f[i + 1][j].max(f[i][j - 1]);
                }
            }
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

<p>给你两个字符串 <code>word1</code> 和 <code>word2</code> ，请你按下述方法构造一个字符串：</p>

<ul>
	<li>从 <code>word1</code> 中选出某个 <strong>非空</strong> 子序列 <code>subsequence1</code> 。</li>
	<li>从 <code>word2</code> 中选出某个 <strong>非空</strong> 子序列 <code>subsequence2</code> 。</li>
	<li>连接两个子序列 <code>subsequence1 + subsequence2</code> ，得到字符串。</li>
</ul>

<p>返回可按上述方法构造的最长 <strong>回文串</strong> 的 <strong>长度</strong> 。如果无法构造回文串，返回 <code>0</code> 。</p>

<p>字符串 <code>s</code> 的一个 <strong>子序列</strong> 是通过从 <code>s</code> 中删除一些（也可能不删除）字符而不更改其余字符的顺序生成的字符串。</p>

<p><strong>回文串</strong> 是正着读和反着读结果一致的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word1 = "cacb", word2 = "cbba"
<strong>输出：</strong>5
<strong>解释：</strong>从 word1 中选出 "ab" ，从 word2 中选出 "cba" ，得到回文串 "abcba" 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word1 = "ab", word2 = "ab"
<strong>输出：</strong>3
<strong>解释：</strong>从 word1 中选出 "ab" ，从 word2 中选出 "a" ，得到回文串 "aba" 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word1 = "aa", word2 = "bb"
<strong>输出：</strong>0
<strong>解释：</strong>无法按题面所述方法构造回文串，所以返回 0 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 1000</code></li>
	<li><code>word1</code> 和 <code>word2</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们首先将字符串 `word1` 和 `word2` 连接起来，得到字符串 $s$，然后我们可以将问题转化为求字符串 $s$ 的最长回文子序列的长度。只不过这里在算最后的答案时，需要保证回文字符串中，至少有一个字符来自 `word1`，另一个字符来自 `word2`。

我们定义 $f[i][j]$ 表示字符串 $s$ 中下标范围在 $[i, j]$ 内的子串的最长回文子序列的长度。

如果 $s[i] = s[j]$，那么 $s[i]$ 和 $s[j]$ 一定在最长回文子序列中，此时 $f[i][j] = f[i + 1][j - 1] + 2$，这时候我们还需要判断 $s[i]$ 和 $s[j]$ 是否来自 `word1` 和 `word2`，如果是，我们将答案的最大值更新为 $ans=\max(ans, f[i][j])$。

如果 $s[i] \neq s[j]$，那么 $s[i]$ 和 $s[j]$ 一定不会同时出现在最长回文子序列中，此时 $f[i][j] = max(f[i + 1][j], f[i][j - 1])$。

最后我们返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$，其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        s = word1 + word2
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        ans = 0
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                    if i < len(word1) <= j:
                        ans = max(ans, f[i][j])
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
        return ans
```

#### Java

```java
class Solution {
    public int longestPalindrome(String word1, String word2) {
        String s = word1 + word2;
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if (i < word1.length() && j >= word1.length()) {
                        ans = Math.max(ans, f[i][j]);
                    }
                } else {
                    f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
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
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) f[i][i] = 1;
        int ans = 0;
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if (i < word1.size() && j >= word1.size()) {
                        ans = max(ans, f[i][j]);
                    }
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestPalindrome(word1 string, word2 string) (ans int) {
	s := word1 + word2
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1] + 2
				if i < len(word1) && j >= len(word1) && ans < f[i][j] {
					ans = f[i][j]
				}
			} else {
				f[i][j] = max(f[i+1][j], f[i][j-1])
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestPalindrome(word1: string, word2: string): number {
    const s = word1 + word2;
    const n = s.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }
    let ans = 0;
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
                if (i < word1.length && j >= word1.length) {
                    ans = Math.max(ans, f[i][j]);
                }
            } else {
                f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_palindrome(word1: String, word2: String) -> i32 {
        let s: Vec<char> = format!("{}{}", word1, word2).chars().collect();
        let n = s.len();
        let mut f = vec![vec![0; n]; n];
        for i in 0..n {
            f[i][i] = 1;
        }
        let mut ans = 0;
        for i in (0..n - 1).rev() {
            for j in i + 1..n {
                if s[i] == s[j] {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if i < word1.len() && j >= word1.len() {
                        ans = ans.max(f[i][j]);
                    }
                } else {
                    f[i][j] = f[i + 1][j].max(f[i][j - 1]);
                }
            }
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

# [1772. 按受欢迎程度排列功能 🔒](https://leetcode.cn/problems/sort-features-by-popularity){#1772}

{{< tabs "1772" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortFeatures(self, features: List[str], responses: List[str]) -> List[str]:
        cnt = Counter()
        for s in responses:
            for w in set(s.split()):
                cnt[w] += 1
        return sorted(features, key=lambda w: -cnt[w])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] sortFeatures(String[] features, String[] responses) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : responses) {
            Set<String> vis = new HashSet<>();
            for (String w : s.split(" ")) {
                if (vis.add(w)) {
                    cnt.merge(w, 1, Integer::sum);
                }
            }
        }
        int n = features.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> {
            int x = cnt.getOrDefault(features[i], 0);
            int y = cnt.getOrDefault(features[j], 0);
            return x == y ? i - j : y - x;
        });
        String[] ans = new String[n];
        for (int i = 0; i < n; i++) {
            ans[i] = features[idx[i]];
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
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> cnt;
        for (auto& s : responses) {
            istringstream iss(s);
            string w;
            unordered_set<string> st;
            while (iss >> w) {
                st.insert(w);
            }
            for (auto& w : st) {
                ++cnt[w];
            }
        }
        int n = features.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            int x = cnt[features[i]], y = cnt[features[j]];
            return x == y ? i < j : x > y;
        });
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = features[idx[i]];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortFeatures(features []string, responses []string) []string {
	cnt := map[string]int{}
	for _, s := range responses {
		vis := map[string]bool{}
		for _, w := range strings.Split(s, " ") {
			if !vis[w] {
				cnt[w]++
				vis[w] = true
			}
		}
	}
	sort.SliceStable(features, func(i, j int) bool { return cnt[features[i]] > cnt[features[j]] })
	return features
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortFeatures(features: string[], responses: string[]): string[] {
    const cnt: Map<string, number> = new Map();
    for (const s of responses) {
        const vis: Set<string> = new Set();
        for (const w of s.split(' ')) {
            if (vis.has(w)) {
                continue;
            }
            vis.add(w);
            cnt.set(w, (cnt.get(w) || 0) + 1);
        }
    }
    const n = features.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => {
        const x = cnt.get(features[i]) || 0;
        const y = cnt.get(features[j]) || 0;
        return x === y ? i - j : y - x;
    });
    return idx.map(i => features[i]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串数组 <code>features</code> ，其中 <code>features[i]</code> 是一个单词，描述你最近参与开发的项目中一个功能的名称。你调查了用户喜欢哪些功能。另给定一个字符串数组 <code>responses</code>，其中 <code>responses[i]</code> 是一个包含以空格分隔的一系列单词的字符串。</p>

<p>你想要按照受欢迎程度排列这些功能。 严格地说，令 <code>appearances(word)</code> 是满足 <code>responses[i]</code> 中包含单词 <code>word</code> 的 <code>i</code> 的个数，则当 <code>appearances(features[x]) > appearances(features[y])</code> 时，第 <code>x</code> 个功能比第 <code>y</code> 个功能更受欢迎。</p>

<p>返回一个数组 <code>sortedFeatures</code> ，包含按受欢迎程度排列的功能名称。当第 <code>x</code>  个功能和第 <code>y</code> 个功能的受欢迎程度相同且 <code>x < y</code> 时，你应当将第 <code>x</code> 个功能放在第 <code>y</code> 个功能之前。</p>

<p> </p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入</strong><b>：</b>features = ["cooler","lock","touch"], responses = ["i like cooler cooler","lock touch cool","locker like touch"]
<strong>输出</strong><b>：</b>["touch","cooler","lock"]
<strong>解释</strong><b>：</b>appearances("cooler") = 1，appearances("lock") = 1，appearances("touch") = 2。由于 "cooler" 和 "lock" 都出现了 1 次，且 "cooler" 在原数组的前面，所以 "cooler" 也应该在结果数组的前面。
</pre>

<p><b>示例 2：</b></p>

<pre>
<strong>输入</strong><b>：</b>features = ["a","aa","b","c"], responses = ["a","a aa","a a a a a","b a"]
<strong>输出</strong><b>：</b>["a","aa","b","c"]
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 <= features.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= features[i].length <= 10</code></li>
	<li><code>features</code> 不包含重复项。</li>
	<li><code>features[i]</code> 由小写字母构成。</li>
	<li><code>1 <= responses.length <= 10<sup>2</sup></code></li>
	<li><code>1 <= responses[i].length <= 10<sup>3</sup></code></li>
	<li><code>responses[i]</code> 由小写字母和空格组成。</li>
	<li><code>responses[i]</code> 不包含两个连续的空格。</li>
	<li><code>responses[i]</code> 没有前置或后置空格。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 自定义排序

我们遍历 `responses`，对于 `responses[i]` 中的每个单词，我们用一个哈希表 `vis` 暂存。接下来将 `vis` 中的单词记录到哈希表 `cnt` 中，记录每个单词出现的次数。

接下来，采用自定义排序，将 `features` 中的单词按照出现次数从大到小排序，如果出现次数相同，则按照出现的下标从小到大排序。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为 `features` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortFeatures(self, features: List[str], responses: List[str]) -> List[str]:
        cnt = Counter()
        for s in responses:
            for w in set(s.split()):
                cnt[w] += 1
        return sorted(features, key=lambda w: -cnt[w])
```

#### Java

```java
class Solution {
    public String[] sortFeatures(String[] features, String[] responses) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : responses) {
            Set<String> vis = new HashSet<>();
            for (String w : s.split(" ")) {
                if (vis.add(w)) {
                    cnt.merge(w, 1, Integer::sum);
                }
            }
        }
        int n = features.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> {
            int x = cnt.getOrDefault(features[i], 0);
            int y = cnt.getOrDefault(features[j], 0);
            return x == y ? i - j : y - x;
        });
        String[] ans = new String[n];
        for (int i = 0; i < n; i++) {
            ans[i] = features[idx[i]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> cnt;
        for (auto& s : responses) {
            istringstream iss(s);
            string w;
            unordered_set<string> st;
            while (iss >> w) {
                st.insert(w);
            }
            for (auto& w : st) {
                ++cnt[w];
            }
        }
        int n = features.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            int x = cnt[features[i]], y = cnt[features[j]];
            return x == y ? i < j : x > y;
        });
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = features[idx[i]];
        }
        return ans;
    }
};
```

#### Go

```go
func sortFeatures(features []string, responses []string) []string {
	cnt := map[string]int{}
	for _, s := range responses {
		vis := map[string]bool{}
		for _, w := range strings.Split(s, " ") {
			if !vis[w] {
				cnt[w]++
				vis[w] = true
			}
		}
	}
	sort.SliceStable(features, func(i, j int) bool { return cnt[features[i]] > cnt[features[j]] })
	return features
}
```

#### TypeScript

```ts
function sortFeatures(features: string[], responses: string[]): string[] {
    const cnt: Map<string, number> = new Map();
    for (const s of responses) {
        const vis: Set<string> = new Set();
        for (const w of s.split(' ')) {
            if (vis.has(w)) {
                continue;
            }
            vis.add(w);
            cnt.set(w, (cnt.get(w) || 0) + 1);
        }
    }
    const n = features.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => {
        const x = cnt.get(features[i]) || 0;
        const y = cnt.get(features[j]) || 0;
        return x === y ? i - j : y - x;
    });
    return idx.map(i => features[i]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1773. 统计匹配检索规则的物品数量](https://leetcode.cn/problems/count-items-matching-a-rule){#1773}

{{< tabs "1773" >}}

{{% tab "python" %}}
```python
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        i = 0 if ruleKey[0] == 't' else (1 if ruleKey[0] == 'c' else 2)
        return sum(v[i] == ruleValue for v in items)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int i = ruleKey.charAt(0) == 't' ? 0 : (ruleKey.charAt(0) == 'c' ? 1 : 2);
        int ans = 0;
        for (var v : items) {
            if (v.get(i).equals(ruleValue)) {
                ++ans;
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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int i = ruleKey[0] == 't' ? 0 : (ruleKey[0] == 'c' ? 1 : 2);
        return count_if(items.begin(), items.end(), [&](auto& v) { return v[i] == ruleValue; });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countMatches(items [][]string, ruleKey string, ruleValue string) (ans int) {
	i := map[byte]int{'t': 0, 'c': 1, 'n': 2}[ruleKey[0]]
	for _, v := range items {
		if v[i] == ruleValue {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countMatches(items: string[][], ruleKey: string, ruleValue: string): number {
    const key = ruleKey === 'type' ? 0 : ruleKey === 'color' ? 1 : 2;
    return items.reduce((r, v) => r + (v[key] === ruleValue ? 1 : 0), 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
        let key = if rule_key == "type" {
            0
        } else if rule_key == "color" {
            1
        } else {
            2
        };
        items.iter().filter(|v| v[key] == rule_value).count() as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue) {
    int k = strcmp(ruleKey, "type") == 0 ? 0 : strcmp(ruleKey, "color") == 0 ? 1
                                                                             : 2;
    int res = 0;
    for (int i = 0; i < itemsSize; i++) {
        if (strcmp(items[i][k], ruleValue) == 0) {
            res++;
        }
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>items</code> ，其中 <code>items[i] = [type<sub>i</sub>, color<sub>i</sub>, name<sub>i</sub>]</code> ，描述第 <code>i</code> 件物品的类型、颜色以及名称。</p>

<p>另给你一条由两个字符串 <code>ruleKey</code> 和 <code>ruleValue</code> 表示的检索规则。</p>

<p>如果第 <code>i</code> 件物品能满足下述条件之一，则认为该物品与给定的检索规则 <strong>匹配</strong> ：</p>

<ul>
	<li><code>ruleKey == "type"</code> 且 <code>ruleValue == type<sub>i</sub></code> 。</li>
	<li><code>ruleKey == "color"</code> 且 <code>ruleValue == color<sub>i</sub></code> 。</li>
	<li><code>ruleKey == "name"</code> 且 <code>ruleValue == name<sub>i</sub></code> 。</li>
</ul>

<p>统计并返回 <strong>匹配检索规则的物品数量</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
<strong>输出：</strong>1
<strong>解释：</strong>只有一件物品匹配检索规则，这件物品是 ["computer","silver","lenovo"] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
<strong>输出：</strong>2
<strong>解释：</strong>只有两件物品匹配检索规则，这两件物品分别是 ["phone","blue","pixel"] 和 ["phone","gold","iphone"] 。注意，["computer","silver","phone"] 未匹配检索规则。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= items.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= type<sub>i</sub>.length, color<sub>i</sub>.length, name<sub>i</sub>.length, ruleValue.length <= 10</code></li>
	<li><code>ruleKey</code> 等于 <code>"type"</code>、<code>"color"</code> 或 <code>"name"</code></li>
	<li>所有字符串仅由小写字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数模拟

由于 `ruleKey` 只可能是 `"type"`、`"color"` 或 `"name"`，我们可以直接取 `ruleKey` 的第一个字符来确定 `item` 的下标 $i$。然后遍历 `items` 数组，统计 `item[i] == ruleValue` 的个数即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为 `items` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        i = 0 if ruleKey[0] == 't' else (1 if ruleKey[0] == 'c' else 2)
        return sum(v[i] == ruleValue for v in items)
```

#### Java

```java
class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int i = ruleKey.charAt(0) == 't' ? 0 : (ruleKey.charAt(0) == 'c' ? 1 : 2);
        int ans = 0;
        for (var v : items) {
            if (v.get(i).equals(ruleValue)) {
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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int i = ruleKey[0] == 't' ? 0 : (ruleKey[0] == 'c' ? 1 : 2);
        return count_if(items.begin(), items.end(), [&](auto& v) { return v[i] == ruleValue; });
    }
};
```

#### Go

```go
func countMatches(items [][]string, ruleKey string, ruleValue string) (ans int) {
	i := map[byte]int{'t': 0, 'c': 1, 'n': 2}[ruleKey[0]]
	for _, v := range items {
		if v[i] == ruleValue {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countMatches(items: string[][], ruleKey: string, ruleValue: string): number {
    const key = ruleKey === 'type' ? 0 : ruleKey === 'color' ? 1 : 2;
    return items.reduce((r, v) => r + (v[key] === ruleValue ? 1 : 0), 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
        let key = if rule_key == "type" {
            0
        } else if rule_key == "color" {
            1
        } else {
            2
        };
        items.iter().filter(|v| v[key] == rule_value).count() as i32
    }
}
```

#### C

```c
int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue) {
    int k = strcmp(ruleKey, "type") == 0 ? 0 : strcmp(ruleKey, "color") == 0 ? 1
                                                                             : 2;
    int res = 0;
    for (int i = 0; i < itemsSize; i++) {
        if (strcmp(items[i][k], ruleValue) == 0) {
            res++;
        }
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1774. 最接近目标价格的甜点成本](https://leetcode.cn/problems/closest-dessert-cost){#1774}

{{< tabs "1774" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestCost(
        self, baseCosts: List[int], toppingCosts: List[int], target: int
    ) -> int:
        def dfs(i, t):
            if i >= len(toppingCosts):
                arr.append(t)
                return
            dfs(i + 1, t)
            dfs(i + 1, t + toppingCosts[i])

        arr = []
        dfs(0, 0)
        arr.sort()
        d = ans = inf

        # 选择一种冰激淋基料
        for x in baseCosts:
            # 枚举子集和
            for y in arr:
                # 二分查找
                i = bisect_left(arr, target - x - y)
                for j in (i, i - 1):
                    if 0 <= j < len(arr):
                        t = abs(x + y + arr[j] - target)
                        if d > t or (d == t and ans > x + y + arr[j]):
                            d = t
                            ans = x + y + arr[j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer> arr = new ArrayList<>();
    private int[] ts;
    private int inf = 1 << 30;

    public int closestCost(int[] baseCosts, int[] toppingCosts, int target) {
        ts = toppingCosts;
        dfs(0, 0);
        Collections.sort(arr);
        int d = inf, ans = inf;

        // 选择一种冰激淋基料
        for (int x : baseCosts) {
            // 枚举子集和
            for (int y : arr) {
                // 二分查找
                int i = search(target - x - y);
                for (int j : new int[] {i, i - 1}) {
                    if (j >= 0 && j < arr.size()) {
                        int t = Math.abs(x + y + arr.get(j) - target);
                        if (d > t || (d == t && ans > x + y + arr.get(j))) {
                            d = t;
                            ans = x + y + arr.get(j);
                        }
                    }
                }
            }
        }
        return ans;
    }

    private int search(int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr.get(mid) >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private void dfs(int i, int t) {
        if (i >= ts.length) {
            arr.add(t);
            return;
        }
        dfs(i + 1, t);
        dfs(i + 1, t + ts[i]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int inf = INT_MAX;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int> arr;
        function<void(int, int)> dfs = [&](int i, int t) {
            if (i >= toppingCosts.size()) {
                arr.push_back(t);
                return;
            }
            dfs(i + 1, t);
            dfs(i + 1, t + toppingCosts[i]);
        };
        dfs(0, 0);
        sort(arr.begin(), arr.end());
        int d = inf, ans = inf;
        // 选择一种冰激淋基料
        for (int x : baseCosts) {
            // 枚举子集和
            for (int y : arr) {
                // 二分查找
                int i = lower_bound(arr.begin(), arr.end(), target - x - y) - arr.begin();
                for (int j = i - 1; j < i + 1; ++j) {
                    if (j >= 0 && j < arr.size()) {
                        int t = abs(x + y + arr[j] - target);
                        if (d > t || (d == t && ans > x + y + arr[j])) {
                            d = t;
                            ans = x + y + arr[j];
                        }
                    }
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
func closestCost(baseCosts []int, toppingCosts []int, target int) int {
	arr := []int{}
	var dfs func(int, int)
	dfs = func(i, t int) {
		if i >= len(toppingCosts) {
			arr = append(arr, t)
			return
		}
		dfs(i+1, t)
		dfs(i+1, t+toppingCosts[i])
	}
	dfs(0, 0)
	sort.Ints(arr)
	const inf = 1 << 30
	ans, d := inf, inf
	// 选择一种冰激淋基料
	for _, x := range baseCosts {
		// 枚举子集和
		for _, y := range arr {
			// 二分查找
			i := sort.SearchInts(arr, target-x-y)
			for j := i - 1; j < i+1; j++ {
				if j >= 0 && j < len(arr) {
					t := abs(x + y + arr[j] - target)
					if d > t || (d == t && ans > x+y+arr[j]) {
						d = t
						ans = x + y + arr[j]
					}
				}
			}
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
{{% tab "js" %}}
```js
const closestCost = function (baseCosts, toppingCosts, target) {
    let closestDessertCost = -Infinity;
    function dfs(dessertCost, j) {
        const tarCurrDiff = Math.abs(target - dessertCost);
        const tarCloseDiff = Math.abs(target - closestDessertCost);
        if (tarCurrDiff < tarCloseDiff) {
            closestDessertCost = dessertCost;
        } else if (tarCurrDiff === tarCloseDiff && dessertCost < closestDessertCost) {
            closestDessertCost = dessertCost;
        }
        if (dessertCost > target) return;
        if (j === toppingCosts.length) return;
        for (let count = 0; count <= 2; count++) {
            dfs(dessertCost + count * toppingCosts[j], j + 1);
        }
    }
    for (let i = 0; i < baseCosts.length; i++) {
        dfs(baseCosts[i], 0);
    }
    return closestDessertCost;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你打算做甜点，现在需要购买配料。目前共有 <code>n</code> 种冰激凌基料和 <code>m</code> 种配料可供选购。而制作甜点需要遵循以下几条规则：</p>

<ul>
	<li>必须选择 <strong>一种</strong> 冰激凌基料。</li>
	<li>可以添加 <strong>一种或多种</strong> 配料，也可以不添加任何配料。</li>
	<li>每种类型的配料 <strong>最多两份</strong> 。</li>
</ul>

<p>给你以下三个输入：</p>

<ul>
	<li><code>baseCosts</code> ，一个长度为 <code>n</code> 的整数数组，其中每个 <code>baseCosts[i]</code> 表示第 <code>i</code> 种冰激凌基料的价格。</li>
	<li><code>toppingCosts</code>，一个长度为 <code>m</code> 的整数数组，其中每个 <code>toppingCosts[i]</code> 表示 <strong>一份</strong> 第 <code>i</code> 种冰激凌配料的价格。</li>
	<li><code>target</code> ，一个整数，表示你制作甜点的目标价格。</li>
</ul>

<p>你希望自己做的甜点总成本尽可能接近目标价格 <code>target</code> 。</p>

<p>返回最接近<em> </em><code>target</code> 的甜点成本。如果有多种方案，返回 <strong>成本相对较低</strong> 的一种。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>baseCosts = [1,7], toppingCosts = [3,4], target = 10
<strong>输出：</strong>10
<strong>解释：</strong>考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 7
- 选择 1 份 0 号配料：成本 1 x 3 = 3
- 选择 0 份 1 号配料：成本 0 x 4 = 0
总成本：7 + 3 + 0 = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
<strong>输出：</strong>17
<strong>解释：</strong>考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 3
- 选择 1 份 0 号配料：成本 1 x 4 = 4
- 选择 2 份 1 号配料：成本 2 x 5 = 10
- 选择 0 份 2 号配料：成本 0 x 100 = 0
总成本：3 + 4 + 10 + 0 = 17 。不存在总成本为 18 的甜点制作方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>baseCosts = [3,10], toppingCosts = [2,5], target = 9
<strong>输出：</strong>8
<strong>解释：</strong>可以制作总成本为 8 和 10 的甜点。返回 8 ，因为这是成本更低的方案。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>baseCosts = [10], toppingCosts = [1], target = 1
<strong>输出：</strong>10
<strong>解释：</strong>注意，你可以选择不添加任何配料，但你必须选择一种基料。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == baseCosts.length</code></li>
	<li><code>m == toppingCosts.length</code></li>
	<li><code>1 <= n, m <= 10</code></li>
	<li><code>1 <= baseCosts[i], toppingCosts[i] <= 10<sup>4</sup></code></li>
	<li><code>1 <= target <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举子集和 + 排序 + 二分查找

每种类型的配料最多可以选两份，因此，我们可以复制一份配料，然后利用 `DFS` 枚举子集之和。在实现上，我们可以只枚举一半的配料的所有子集和，然后在另一半配料子集和中，利用二分查找找到最接近的配料。

时间复杂度 $O(n \times 2^m \times \log {2^m})$。

相似题目：

-   [1755. 最接近目标值的子序列和](https://github.com/doocs/leetcode/blob/main/solution/1700-1799/1755.Closest%20Subsequence%20Sum/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestCost(
        self, baseCosts: List[int], toppingCosts: List[int], target: int
    ) -> int:
        def dfs(i, t):
            if i >= len(toppingCosts):
                arr.append(t)
                return
            dfs(i + 1, t)
            dfs(i + 1, t + toppingCosts[i])

        arr = []
        dfs(0, 0)
        arr.sort()
        d = ans = inf

        # 选择一种冰激淋基料
        for x in baseCosts:
            # 枚举子集和
            for y in arr:
                # 二分查找
                i = bisect_left(arr, target - x - y)
                for j in (i, i - 1):
                    if 0 <= j < len(arr):
                        t = abs(x + y + arr[j] - target)
                        if d > t or (d == t and ans > x + y + arr[j]):
                            d = t
                            ans = x + y + arr[j]
        return ans
```

#### Java

```java
class Solution {
    private List<Integer> arr = new ArrayList<>();
    private int[] ts;
    private int inf = 1 << 30;

    public int closestCost(int[] baseCosts, int[] toppingCosts, int target) {
        ts = toppingCosts;
        dfs(0, 0);
        Collections.sort(arr);
        int d = inf, ans = inf;

        // 选择一种冰激淋基料
        for (int x : baseCosts) {
            // 枚举子集和
            for (int y : arr) {
                // 二分查找
                int i = search(target - x - y);
                for (int j : new int[] {i, i - 1}) {
                    if (j >= 0 && j < arr.size()) {
                        int t = Math.abs(x + y + arr.get(j) - target);
                        if (d > t || (d == t && ans > x + y + arr.get(j))) {
                            d = t;
                            ans = x + y + arr.get(j);
                        }
                    }
                }
            }
        }
        return ans;
    }

    private int search(int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr.get(mid) >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private void dfs(int i, int t) {
        if (i >= ts.length) {
            arr.add(t);
            return;
        }
        dfs(i + 1, t);
        dfs(i + 1, t + ts[i]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int inf = INT_MAX;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int> arr;
        function<void(int, int)> dfs = [&](int i, int t) {
            if (i >= toppingCosts.size()) {
                arr.push_back(t);
                return;
            }
            dfs(i + 1, t);
            dfs(i + 1, t + toppingCosts[i]);
        };
        dfs(0, 0);
        sort(arr.begin(), arr.end());
        int d = inf, ans = inf;
        // 选择一种冰激淋基料
        for (int x : baseCosts) {
            // 枚举子集和
            for (int y : arr) {
                // 二分查找
                int i = lower_bound(arr.begin(), arr.end(), target - x - y) - arr.begin();
                for (int j = i - 1; j < i + 1; ++j) {
                    if (j >= 0 && j < arr.size()) {
                        int t = abs(x + y + arr[j] - target);
                        if (d > t || (d == t && ans > x + y + arr[j])) {
                            d = t;
                            ans = x + y + arr[j];
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func closestCost(baseCosts []int, toppingCosts []int, target int) int {
	arr := []int{}
	var dfs func(int, int)
	dfs = func(i, t int) {
		if i >= len(toppingCosts) {
			arr = append(arr, t)
			return
		}
		dfs(i+1, t)
		dfs(i+1, t+toppingCosts[i])
	}
	dfs(0, 0)
	sort.Ints(arr)
	const inf = 1 << 30
	ans, d := inf, inf
	// 选择一种冰激淋基料
	for _, x := range baseCosts {
		// 枚举子集和
		for _, y := range arr {
			// 二分查找
			i := sort.SearchInts(arr, target-x-y)
			for j := i - 1; j < i+1; j++ {
				if j >= 0 && j < len(arr) {
					t := abs(x + y + arr[j] - target)
					if d > t || (d == t && ans > x+y+arr[j]) {
						d = t
						ans = x + y + arr[j]
					}
				}
			}
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

#### JavaScript

```js
const closestCost = function (baseCosts, toppingCosts, target) {
    let closestDessertCost = -Infinity;
    function dfs(dessertCost, j) {
        const tarCurrDiff = Math.abs(target - dessertCost);
        const tarCloseDiff = Math.abs(target - closestDessertCost);
        if (tarCurrDiff < tarCloseDiff) {
            closestDessertCost = dessertCost;
        } else if (tarCurrDiff === tarCloseDiff && dessertCost < closestDessertCost) {
            closestDessertCost = dessertCost;
        }
        if (dessertCost > target) return;
        if (j === toppingCosts.length) return;
        for (let count = 0; count <= 2; count++) {
            dfs(dessertCost + count * toppingCosts[j], j + 1);
        }
    }
    for (let i = 0; i < baseCosts.length; i++) {
        dfs(baseCosts[i], 0);
    }
    return closestDessertCost;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1775. 通过最少操作次数使数组的和相等](https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations){#1775}

{{< tabs "1775" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2 = sum(nums1), sum(nums2)
        if s1 == s2:
            return 0
        if s1 > s2:
            return self.minOperations(nums2, nums1)
        cnt = Counter([6 - v for v in nums1] + [v - 1 for v in nums2])
        d = s2 - s1
        ans = 0
        for i in range(5, 0, -1):
            while cnt[i] and d > 0:
                d -= i
                cnt[i] -= 1
                ans += 1
        return ans if d <= 0 else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        int s1 = Arrays.stream(nums1).sum();
        int s2 = Arrays.stream(nums2).sum();
        if (s1 == s2) {
            return 0;
        }
        if (s1 > s2) {
            return minOperations(nums2, nums1);
        }
        int d = s2 - s1;
        int[] cnt = new int[6];
        for (int v : nums1) {
            ++cnt[6 - v];
        }
        for (int v : nums2) {
            ++cnt[v - 1];
        }
        int ans = 0;
        for (int i = 5; i > 0; --i) {
            while (cnt[i] > 0 && d > 0) {
                d -= i;
                --cnt[i];
                ++ans;
            }
        }
        return d <= 0 ? ans : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 == s2) return 0;
        if (s1 > s2) return minOperations(nums2, nums1);
        int d = s2 - s1;
        int cnt[6] = {0};
        for (int& v : nums1) ++cnt[6 - v];
        for (int& v : nums2) ++cnt[v - 1];
        int ans = 0;
        for (int i = 5; i; --i) {
            while (cnt[i] && d > 0) {
                d -= i;
                --cnt[i];
                ++ans;
            }
        }
        return d <= 0 ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums1 []int, nums2 []int) (ans int) {
	s1, s2 := sum(nums1), sum(nums2)
	if s1 == s2 {
		return 0
	}
	if s1 > s2 {
		return minOperations(nums2, nums1)
	}
	d := s2 - s1
	cnt := [6]int{}
	for _, v := range nums1 {
		cnt[6-v]++
	}
	for _, v := range nums2 {
		cnt[v-1]++
	}
	for i := 5; i > 0; i-- {
		for cnt[i] > 0 && d > 0 {
			d -= i
			cnt[i]--
			ans++
		}
	}
	if d <= 0 {
		return
	}
	return -1
}

func sum(nums []int) (s int) {
	for _, v := range nums {
		s += v
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

<p>给你两个长度可能不等的整数数组 <code>nums1</code> 和 <code>nums2</code> 。两个数组中的所有值都在 <code>1</code> 到 <code>6</code> 之间（包含 <code>1</code> 和 <code>6</code>）。</p>

<p>每次操作中，你可以选择 <strong>任意</strong> 数组中的任意一个整数，将它变成 <code>1</code> 到 <code>6</code> 之间 <strong>任意</strong> 的值（包含 <code>1</code> 和 <code><span style="">6</span></code>）。</p>

<p>请你返回使 <code>nums1</code> 中所有数的和与 <code>nums2</code> 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
<b>输出：</b>3
<b>解释：</b>你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [<strong>6</strong>,1,2,2,2,2] 。
- 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,<strong>1</strong>], nums2 = [6,1,2,2,2,2] 。
- 将 nums1[2] 变为 2 。 nums1 = [1,2,<strong>2</strong>,4,5,1], nums2 = [6,1,2,2,2,2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,1,1,1,1,1,1], nums2 = [6]
<b>输出：</b>-1
<b>解释：</b>没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums1 = [6,6], nums2 = [1]
<b>输出：</b>3
<b>解释：</b>你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums1[0] 变为 2 。 nums1 = [<strong>2</strong>,6], nums2 = [1] 。
- 将 nums1[1] 变为 2 。 nums1 = [2,<strong>2</strong>], nums2 = [1] 。
- 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [<strong>4</strong>] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们用 $s_1$ 和 $s_2$ 分别表示数组 `nums1` 和 `nums2` 的和。

如果 $s_1 = s_2$，则不需要任何操作，直接返回 $0$。否则，我们不妨设 $s_1 \lt s_2$，即 $nums_1$ 中的元素和小于 $nums_2$ 中的元素和，那么两个数组元素和的差值 $d=s_2-s_1$。

要使得两个数组元素和相等，我们需要对 `nums1` 中的元素进行增大操作，对 `nums2` 中的元素进行减小操作。

对于 `nums1` 中的每个元素 $v$，我们最多可以将其增大到 $6$，那么 $v$ 可以增大的量为 $6-v$。对于 `nums2` 中的每个元素 $v$，我们最多可以将其减小到 $1$，那么 $v$ 可以减小的量为 $v-1$。

我们将每个元素的变化量放入数组 `arr` 中，然后对数组 `arr` 进行降序排列。

接下来，我们从数组 `arr` 的第一个元素开始，贪心地将 $d$ 减去每个元素的变化量，直到 $d \leq 0$，返回此时的操作次数即可。

遍历结束后，如果 $d \gt 0$，说明无法使得两个数组元素和相等，返回 $-1$。

时间复杂度 $O((m+n) \times \log (m + n))$，空间复杂度 $O(m+n)$。其中 $m$ 和 $n$ 分别为数组 `nums1` 和 `nums2` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2 = sum(nums1), sum(nums2)
        if s1 == s2:
            return 0
        if s1 > s2:
            return self.minOperations(nums2, nums1)
        arr = [6 - v for v in nums1] + [v - 1 for v in nums2]
        d = s2 - s1
        for i, v in enumerate(sorted(arr, reverse=True), 1):
            d -= v
            if d <= 0:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        int s1 = Arrays.stream(nums1).sum();
        int s2 = Arrays.stream(nums2).sum();
        if (s1 == s2) {
            return 0;
        }
        if (s1 > s2) {
            return minOperations(nums2, nums1);
        }
        int d = s2 - s1;
        int[] arr = new int[nums1.length + nums2.length];
        int k = 0;
        for (int v : nums1) {
            arr[k++] = 6 - v;
        }
        for (int v : nums2) {
            arr[k++] = v - 1;
        }
        Arrays.sort(arr);
        for (int i = 1, j = arr.length - 1; j >= 0; ++i, --j) {
            d -= arr[j];
            if (d <= 0) {
                return i;
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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 == s2) return 0;
        if (s1 > s2) return minOperations(nums2, nums1);
        int d = s2 - s1;
        int arr[nums1.size() + nums2.size()];
        int k = 0;
        for (int& v : nums1) arr[k++] = 6 - v;
        for (int& v : nums2) arr[k++] = v - 1;
        sort(arr, arr + k, greater<>());
        for (int i = 0; i < k; ++i) {
            d -= arr[i];
            if (d <= 0) return i + 1;
        }
        return -1;
    }
};
```

#### Go

```go
func minOperations(nums1 []int, nums2 []int) int {
	s1, s2 := sum(nums1), sum(nums2)
	if s1 == s2 {
		return 0
	}
	if s1 > s2 {
		return minOperations(nums2, nums1)
	}
	d := s2 - s1
	arr := []int{}
	for _, v := range nums1 {
		arr = append(arr, 6-v)
	}
	for _, v := range nums2 {
		arr = append(arr, v-1)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(arr)))
	for i, v := range arr {
		d -= v
		if d <= 0 {
			return i + 1
		}
	}
	return -1
}

func sum(nums []int) (s int) {
	for _, v := range nums {
		s += v
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 计数排序

方法一中，我们需要创建数组 `arr` 并进行排序，时空复杂度较高。由于数组 `arr` 中元素的范围为 $[0,..5]$，因此我们创建一个长度为 $6$ 的数组 `cnt`，用于统计数组 `arr` 中每个元素的数量，也即每个最大变化量的元素的数量。

接下来，我们从最大变化量 $i=5$ 开始，贪心地将 $d$ 减去最大变化量，直到 $d \leq 0$，返回此时的操作次数即可。

时间复杂度 $O(m+n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别为数组 `nums1` 和 `nums2` 的长度。本题中 $C=6$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2 = sum(nums1), sum(nums2)
        if s1 == s2:
            return 0
        if s1 > s2:
            return self.minOperations(nums2, nums1)
        cnt = Counter([6 - v for v in nums1] + [v - 1 for v in nums2])
        d = s2 - s1
        ans = 0
        for i in range(5, 0, -1):
            while cnt[i] and d > 0:
                d -= i
                cnt[i] -= 1
                ans += 1
        return ans if d <= 0 else -1
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        int s1 = Arrays.stream(nums1).sum();
        int s2 = Arrays.stream(nums2).sum();
        if (s1 == s2) {
            return 0;
        }
        if (s1 > s2) {
            return minOperations(nums2, nums1);
        }
        int d = s2 - s1;
        int[] cnt = new int[6];
        for (int v : nums1) {
            ++cnt[6 - v];
        }
        for (int v : nums2) {
            ++cnt[v - 1];
        }
        int ans = 0;
        for (int i = 5; i > 0; --i) {
            while (cnt[i] > 0 && d > 0) {
                d -= i;
                --cnt[i];
                ++ans;
            }
        }
        return d <= 0 ? ans : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 == s2) return 0;
        if (s1 > s2) return minOperations(nums2, nums1);
        int d = s2 - s1;
        int cnt[6] = {0};
        for (int& v : nums1) ++cnt[6 - v];
        for (int& v : nums2) ++cnt[v - 1];
        int ans = 0;
        for (int i = 5; i; --i) {
            while (cnt[i] && d > 0) {
                d -= i;
                --cnt[i];
                ++ans;
            }
        }
        return d <= 0 ? ans : -1;
    }
};
```

#### Go

```go
func minOperations(nums1 []int, nums2 []int) (ans int) {
	s1, s2 := sum(nums1), sum(nums2)
	if s1 == s2 {
		return 0
	}
	if s1 > s2 {
		return minOperations(nums2, nums1)
	}
	d := s2 - s1
	cnt := [6]int{}
	for _, v := range nums1 {
		cnt[6-v]++
	}
	for _, v := range nums2 {
		cnt[v-1]++
	}
	for i := 5; i > 0; i-- {
		for cnt[i] > 0 && d > 0 {
			d -= i
			cnt[i]--
			ans++
		}
	}
	if d <= 0 {
		return
	}
	return -1
}

func sum(nums []int) (s int) {
	for _, v := range nums {
		s += v
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1776. 车队 II](https://leetcode.cn/problems/car-fleet-ii){#1776}

{{< tabs "1776" >}}

{{% tab "python" %}}
```python
class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        stk = []
        n = len(cars)
        ans = [-1] * n
        for i in range(n - 1, -1, -1):
            while stk:
                j = stk[-1]
                if cars[i][1] > cars[j][1]:
                    t = (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1])
                    if ans[j] == -1 or t <= ans[j]:
                        ans[i] = t
                        break
                stk.pop()
            stk.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double[] getCollisionTimes(int[][] cars) {
        int n = cars.length;
        double[] ans = new double[n];
        Arrays.fill(ans, -1.0);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty()) {
                int j = stk.peek();
                if (cars[i][1] > cars[j][1]) {
                    double t = (cars[j][0] - cars[i][0]) * 1.0 / (cars[i][1] - cars[j][1]);
                    if (ans[j] < 0 || t <= ans[j]) {
                        ans[i] = t;
                        break;
                    }
                }
                stk.pop();
            }
            stk.push(i);
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
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (stk.size()) {
                int j = stk.top();
                if (cars[i][1] > cars[j][1]) {
                    double t = (cars[j][0] - cars[i][0]) * 1.0 / (cars[i][1] - cars[j][1]);
                    if (ans[j] < 0 || t <= ans[j]) {
                        ans[i] = t;
                        break;
                    }
                }
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getCollisionTimes(cars [][]int) []float64 {
	n := len(cars)
	ans := make([]float64, n)
	for i := range ans {
		ans[i] = -1.0
	}
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 {
			j := stk[len(stk)-1]
			if cars[i][1] > cars[j][1] {
				t := float64(cars[j][0]-cars[i][0]) / float64(cars[i][1]-cars[j][1])
				if ans[j] < 0 || t <= ans[j] {
					ans[i] = t
					break
				}
			}
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
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

<p>在一条单车道上有 <code>n</code> 辆车，它们朝着同样的方向行驶。给你一个长度为 <code>n</code> 的数组 <code>cars</code> ，其中 <code>cars[i] = [position<sub>i</sub>, speed<sub>i</sub>]</code> ，它表示：</p>

<ul>
	<li><code>position<sub>i</sub></code> 是第 <code>i</code> 辆车和道路起点之间的距离（单位：米）。题目保证 <code>position<sub>i</sub> < position<sub>i+1</sub></code><sub> </sub>。</li>
	<li><code>speed<sub>i</sub></code> 是第 <code>i</code> 辆车的初始速度（单位：米/秒）。</li>
</ul>

<p>简单起见，所有车子可以视为在数轴上移动的点。当两辆车占据同一个位置时，我们称它们相遇了。一旦两辆车相遇，它们会合并成一个车队，这个车队里的车有着同样的位置和相同的速度，速度为这个车队里 <strong>最慢</strong> 一辆车的速度。</p>

<p>请你返回一个数组 <code>answer</code> ，其中 <code>answer[i]</code> 是第 <code>i</code> 辆车与下一辆车相遇的时间（单位：秒），如果这辆车不会与下一辆车相遇，则 <code>answer[i]</code> 为 <code>-1</code> 。答案精度误差需在 <code>10<sup>-5</sup></code> 以内。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>cars = [[1,2],[2,1],[4,3],[7,2]]
<b>输出：</b>[1.00000,-1.00000,3.00000,-1.00000]
<b>解释：</b>经过恰好 1 秒以后，第一辆车会与第二辆车相遇，并形成一个 1 m/s 的车队。经过恰好 3 秒以后，第三辆车会与第四辆车相遇，并形成一个 2 m/s 的车队。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>cars = [[3,4],[5,4],[6,3],[9,1]]
<b>输出：</b>[2.00000,1.00000,1.50000,-1.00000]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= cars.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= position<sub>i</sub>, speed<sub>i</sub> <= 10<sup>6</sup></code></li>
	<li><code>position<sub>i</sub> < position<sub>i+1</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

由于每一辆车最终追上其右边第一辆车的时间与其左边的车没有关系，因此，我们可以从右往左遍历，计算每辆车与其右边第一辆车相遇的时间。

具体地，我们维护一个栈，栈中存放的是车辆的编号，栈顶元素表示当前最慢的车辆编号，栈底元素表示当前最快的车辆编号。

当我们遍历到第 $i$ 辆车时，如果第 $i$ 辆车的速度大于栈顶元素对应的车辆 $j$ 的速度，此时我们计算两车相遇的时间，记为 $t$。如果车辆 $j$ 与右边车辆不会相遇，或者 $t$ 小于等于 $j$ 与右辆车相遇的时间，说明车辆 $i$ 可以在 $t$ 时间追上车辆 $j$，更新答案。否则，说明车辆 $i$ 不会与车辆 $j$ 相遇，我们将车辆 $j$ 出栈，继续判断车辆 $i$ 与栈顶元素对应的车辆相遇的时间。如果栈为空，说明车辆 $i$ 不会与任何车辆相遇，更新答案为 $-1$。最后，将车辆 $i$ 入栈。

遍历完所有车辆后，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为车辆数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        stk = []
        n = len(cars)
        ans = [-1] * n
        for i in range(n - 1, -1, -1):
            while stk:
                j = stk[-1]
                if cars[i][1] > cars[j][1]:
                    t = (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1])
                    if ans[j] == -1 or t <= ans[j]:
                        ans[i] = t
                        break
                stk.pop()
            stk.append(i)
        return ans
```

#### Java

```java
class Solution {
    public double[] getCollisionTimes(int[][] cars) {
        int n = cars.length;
        double[] ans = new double[n];
        Arrays.fill(ans, -1.0);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty()) {
                int j = stk.peek();
                if (cars[i][1] > cars[j][1]) {
                    double t = (cars[j][0] - cars[i][0]) * 1.0 / (cars[i][1] - cars[j][1]);
                    if (ans[j] < 0 || t <= ans[j]) {
                        ans[i] = t;
                        break;
                    }
                }
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (stk.size()) {
                int j = stk.top();
                if (cars[i][1] > cars[j][1]) {
                    double t = (cars[j][0] - cars[i][0]) * 1.0 / (cars[i][1] - cars[j][1]);
                    if (ans[j] < 0 || t <= ans[j]) {
                        ans[i] = t;
                        break;
                    }
                }
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
```

#### Go

```go
func getCollisionTimes(cars [][]int) []float64 {
	n := len(cars)
	ans := make([]float64, n)
	for i := range ans {
		ans[i] = -1.0
	}
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 {
			j := stk[len(stk)-1]
			if cars[i][1] > cars[j][1] {
				t := float64(cars[j][0]-cars[i][0]) / float64(cars[i][1]-cars[j][1])
				if ans[j] < 0 || t <= ans[j] {
					ans[i] = t
					break
				}
			}
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1777. 每家商店的产品价格 🔒](https://leetcode.cn/problems/products-price-for-each-store){#1777}

{{< tabs "1777" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    product_id,
    SUM(IF(store = 'store1', price, NULL)) AS store1,
    SUM(IF(store = 'store2', price, NULL)) AS store2,
    SUM(IF(store = 'store3', price, NULL)) AS store3
FROM Products
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store       | enum    |
| price       | int     |
+-------------+---------+
在 SQL 中，(product_id,store) 是这个表的主键。
store 字段是枚举类型，它的取值为以下三种 ('store1', 'store2', 'store3') 。
price 是该商品在这家商店中的价格。</pre>

<p>&nbsp;</p>

<p>找出每种产品在各个商店中的价格。</p>

<p>可以以 <strong>任何顺序</strong> 输出结果。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Products 表：
+-------------+--------+-------+
| product_id  | store  | price |
+-------------+--------+-------+
| 0           | store1 | 95    |
| 0           | store3 | 105   |
| 0           | store2 | 100   |
| 1           | store1 | 70    |
| 1           | store3 | 80    |
+-------------+--------+-------+
<strong>输出：</strong>
+-------------+--------+--------+--------+
| product_id  | store1 | store2 | store3 |
+-------------+--------+--------+--------+
| 0           | 95     | 100    | 105    |
| 1           | 70     | null   | 80     |
+-------------+--------+--------+--------+
<strong>解释：</strong>
产品 0 的价格在商店 1 为 95 ，商店 2 为 100 ，商店 3 为 105 。
产品 1 的价格在商店 1 为 70 ，商店 3 的产品 1 价格为 80 ，但在商店 2 中没有销售。
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
SELECT
    product_id,
    SUM(IF(store = 'store1', price, NULL)) AS store1,
    SUM(IF(store = 'store2', price, NULL)) AS store2,
    SUM(IF(store = 'store3', price, NULL)) AS store3
FROM Products
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1778. 未知网格中的最短路径 🔒](https://leetcode.cn/problems/shortest-path-in-a-hidden-grid){#1778}

{{< tabs "1778" >}}

{{% tab "python" %}}
```python
# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
# class GridMaster(object):
#    def canMove(self, direction: str) -> bool:
#
#
#    def move(self, direction: str) -> bool:
#
#
#    def isTarget(self) -> None:
#
#


class Solution(object):
    def findShortestPath(self, master: "GridMaster") -> int:
        def dfs(i: int, j: int):
            if master.isTarget():
                nonlocal target
                target = (i, j)
                return
            for k, c in enumerate(s):
                x, y = i + dirs[k], j + dirs[k + 1]
                if master.canMove(c) and (x, y) not in vis:
                    vis.add((x, y))
                    master.move(c)
                    dfs(x, y)
                    master.move(s[(k + 2) % 4])

        s = "URDL"
        dirs = (-1, 0, 1, 0, -1)
        target = None
        vis = set()
        dfs(0, 0)
        if target is None:
            return -1
        vis.discard((0, 0))
        q = deque([(0, 0)])
        ans = -1
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                if (i, j) == target:
                    return ans
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if (x, y) in vis:
                        vis.remove((x, y))
                        q.append((x, y))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *     boolean canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * }
 */

class Solution {
    private int[] target;
    private GridMaster master;
    private final int n = 2010;
    private final String s = "URDL";
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private final Set<Integer> vis = new HashSet<>();

    public int findShortestPath(GridMaster master) {
        this.master = master;
        dfs(0, 0);
        if (target == null) {
            return -1;
        }
        vis.remove(0);
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int m = q.size(); m > 0; --m) {
                var p = q.poll();
                if (p[0] == target[0] && p[1] == target[1]) {
                    return ans;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (vis.remove(x * n + y)) {
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
        return -1;
    }

    private void dfs(int i, int j) {
        if (master.isTarget()) {
            target = new int[] {i, j};
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (master.canMove(s.charAt(k)) && vis.add(x * n + y)) {
                master.move(s.charAt(k));
                dfs(x, y);
                master.move(s.charAt((k + 2) % 4));
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
private:
    const int n = 2010;
    int dirs[5] = {-1, 0, 1, 0, -1};
    string s = "URDL";
    int target;
    unordered_set<int> vis;

public:
    int findShortestPath(GridMaster& master) {
        target = n * n;
        vis.insert(0);
        dfs(0, 0, master);
        if (target == n * n) {
            return -1;
        }
        vis.erase(0);
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        for (int ans = 0; q.size(); ++ans) {
            for (int m = q.size(); m; --m) {
                auto [i, j] = q.front();
                q.pop();
                if (i * n + j == target) {
                    return ans;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (vis.count(x * n + y)) {
                        vis.erase(x * n + y);
                        q.emplace(x, y);
                    }
                }
            }
        }
        return -1;
    }

    void dfs(int i, int j, GridMaster& master) {
        if (master.isTarget()) {
            target = i * n + j;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (master.canMove(s[k]) && !vis.count(x * n + y)) {
                vis.insert(x * n + y);
                master.move(s[k]);
                dfs(x, y, master);
                master.move(s[(k + 2) % 4]);
            }
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这是一个<strong>交互式的问题。</strong></p>

<p>一个未知的网格里有一个机器人，你需要让机器人从起点走到终点。这个网格的大小是 <code>m x n</code>，网格中的每个位置只会是可通行和不可通行两种状态。题目<strong>保证</strong>机器人的起点和终点不同，且都是可通行的。</p>

<p>你需要找到起点到终点的最短路径，然而你<strong>不知道</strong>网格的大小、起点和终点。你只能向 <code>GridMaster</code> 对象查询。</p>

<p><code>GridMaster</code>有这些方法：</p>

<ul>
	<li><code>boolean canMove(char direction)</code> 当机器人能向对应方向移动时，返回 <code>true</code>，否则返回 <code>false</code>。</li>
	<li><code>void move(char direction)</code> 把机器人向这个方向移动。如果移动方向上是不可通行的或是网格的边界，则这次移动会被<strong>忽略</strong>，机器人会待在原地。</li>
	<li><code>boolean isTarget()</code> 如果机器人当前位于终点，返回 <code>true</code>，否则返回 <code>false</code>。</li>
</ul>

<p>注意上述方法中的direction应该是 <code>{'U','D','L','R'}</code> 中的一个，分别代表上下左右四个方向。</p>

<p>返回机器人的初始位置到终点的最短距离。如果在起点和终点间没有路径联通，返回 <code>-1</code>。</p>

<p><strong>自定义测试用例</strong></p>

<p>测试用例是一个 <code>m x n</code> 的二维矩阵 <code>grid</code>，其中：</p>

<ul>
	<li><code>grid[i][j] == -1</code> 表明机器人一开始位于位置 <code>(i, j)</code> （即起点）。</li>
	<li><code>grid[i][j] == 0</code> 表明位置 <code>(i, j)</code> 不可通行。</li>
	<li><code>grid[i][j] == 1</code> 表明位置 <code>(i, j)</code> 可以通行.</li>
	<li><code>grid[i][j] == 2</code> 表明位置 <code>(i, j)</code> 是终点.</li>
</ul>

<p><code>grid</code> 里恰有一个<code>-1</code> 和一个 <code>2</code>。记住在你的代码中，你对这些信息将<strong>一无所知</strong>。</p>

<p><strong>示例1：</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,2],[-1,0]]
<strong>输出:</strong> 2
<strong>解释:</strong> 一种可能的交互过程如下：
The robot is initially standing on cell (1, 0), denoted by the -1.
- master.canMove('U') 返回 true.
- master.canMove('D') 返回false.
- master.canMove('L') 返回 false.
- master.canMove('R') 返回 false.
- master.move('U') 把机器人移动到 (0, 0).
- master.isTarget() 返回 false.
- master.canMove('U') 返回 false.
- master.canMove('D') 返回 true.
- master.canMove('L') 返回 false.
- master.canMove('R') 返回 true.
- master.move('R') 把机器人移动到 (0, 1).
- master.isTarget() 返回 true. 
我们现在知道终点是点 (0, 1)，而且最短的路径是2.
</pre>

<p><strong>示例2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[0,0,-1],[1,1,1],[2,0,0]]
<strong>输出:</strong> 4
<strong>解释:</strong> 机器人和终点的最短路径长是4.</pre>

<p><strong>示例3:</strong></p>

<pre>
<strong>输入:</strong> grid = [[-1,0],[0,2]]
<strong>输出:</strong> -1
<strong>解释:</strong> 机器人和终点间没有可通行的路径.</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n, m <= 500</code></li>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>grid[i][j]</code> 只可能是 <code>-1</code>, <code>0</code>, <code>1</code> 或 <code>2</code></li>
	<li><code>grid</code> 中 <strong>有且只有一个</strong> <code>-1</code></li>
	<li><code>grid</code> 中<strong> 有且只有一个</strong> <code>2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS 建图 + BFS 求最短路

我们不妨假设机器人从坐标 $(0, 0)$ 出发，那么我们可以通过 DFS，找到所有可达的坐标，记录在哈希表 $vis$ 中。另外，我们还需要记录终点的坐标 $target$。

如果找不到终点，那么直接返回 $-1$。否则，我们可以通过 BFS，求出最短路。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

相似题目：

-   [1810. 隐藏网格下的最小消耗路径](https://github.com/doocs/leetcode/blob/main/solution/1800-1899/1810.Minimum%20Path%20Cost%20in%20a%20Hidden%20Grid/README.md)

<!-- tabs:start -->

#### Python3

```python
# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
# class GridMaster(object):
#    def canMove(self, direction: str) -> bool:
#
#
#    def move(self, direction: str) -> bool:
#
#
#    def isTarget(self) -> None:
#
#


class Solution(object):
    def findShortestPath(self, master: "GridMaster") -> int:
        def dfs(i: int, j: int):
            if master.isTarget():
                nonlocal target
                target = (i, j)
                return
            for k, c in enumerate(s):
                x, y = i + dirs[k], j + dirs[k + 1]
                if master.canMove(c) and (x, y) not in vis:
                    vis.add((x, y))
                    master.move(c)
                    dfs(x, y)
                    master.move(s[(k + 2) % 4])

        s = "URDL"
        dirs = (-1, 0, 1, 0, -1)
        target = None
        vis = set()
        dfs(0, 0)
        if target is None:
            return -1
        vis.discard((0, 0))
        q = deque([(0, 0)])
        ans = -1
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                if (i, j) == target:
                    return ans
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if (x, y) in vis:
                        vis.remove((x, y))
                        q.append((x, y))
        return -1
```

#### Java

```java
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *     boolean canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * }
 */

class Solution {
    private int[] target;
    private GridMaster master;
    private final int n = 2010;
    private final String s = "URDL";
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private final Set<Integer> vis = new HashSet<>();

    public int findShortestPath(GridMaster master) {
        this.master = master;
        dfs(0, 0);
        if (target == null) {
            return -1;
        }
        vis.remove(0);
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int m = q.size(); m > 0; --m) {
                var p = q.poll();
                if (p[0] == target[0] && p[1] == target[1]) {
                    return ans;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (vis.remove(x * n + y)) {
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
        return -1;
    }

    private void dfs(int i, int j) {
        if (master.isTarget()) {
            target = new int[] {i, j};
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (master.canMove(s.charAt(k)) && vis.add(x * n + y)) {
                master.move(s.charAt(k));
                dfs(x, y);
                master.move(s.charAt((k + 2) % 4));
            }
        }
    }
}
```

#### C++

```cpp
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
private:
    const int n = 2010;
    int dirs[5] = {-1, 0, 1, 0, -1};
    string s = "URDL";
    int target;
    unordered_set<int> vis;

public:
    int findShortestPath(GridMaster& master) {
        target = n * n;
        vis.insert(0);
        dfs(0, 0, master);
        if (target == n * n) {
            return -1;
        }
        vis.erase(0);
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        for (int ans = 0; q.size(); ++ans) {
            for (int m = q.size(); m; --m) {
                auto [i, j] = q.front();
                q.pop();
                if (i * n + j == target) {
                    return ans;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (vis.count(x * n + y)) {
                        vis.erase(x * n + y);
                        q.emplace(x, y);
                    }
                }
            }
        }
        return -1;
    }

    void dfs(int i, int j, GridMaster& master) {
        if (master.isTarget()) {
            target = i * n + j;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (master.canMove(s[k]) && !vis.count(x * n + y)) {
                vis.insert(x * n + y);
                master.move(s[k]);
                dfs(x, y, master);
                master.move(s[(k + 2) % 4]);
            }
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1779. 找到最近的有相同 X 或 Y 坐标的点](https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate){#1779}

{{< tabs "1779" >}}

{{% tab "python" %}}
```python
class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans, mi = -1, inf
        for i, (a, b) in enumerate(points):
            if a == x or b == y:
                d = abs(a - x) + abs(b - y)
                if mi > d:
                    ans, mi = i, d
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int ans = -1, mi = 1000000;
        for (int i = 0; i < points.length; ++i) {
            int a = points[i][0], b = points[i][1];
            if (a == x || b == y) {
                int d = Math.abs(a - x) + Math.abs(b - y);
                if (d < mi) {
                    mi = d;
                    ans = i;
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
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1, mi = 1e6;
        for (int i = 0; i < points.size(); ++i) {
            int a = points[i][0], b = points[i][1];
            if (a == x || b == y) {
                int d = abs(a - x) + abs(b - y);
                if (d < mi) {
                    mi = d;
                    ans = i;
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
func nearestValidPoint(x int, y int, points [][]int) int {
	ans, mi := -1, 1000000
	for i, p := range points {
		a, b := p[0], p[1]
		if a == x || b == y {
			d := abs(a-x) + abs(b-y)
			if d < mi {
				ans, mi = i, d
			}
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
{{% tab "ts" %}}
```ts
function nearestValidPoint(x: number, y: number, points: number[][]): number {
    let res = -1;
    let midDif = Infinity;
    points.forEach(([px, py], i) => {
        if (px != x && py != y) {
            return;
        }
        const dif = Math.abs(px - x) + Math.abs(py - y);
        if (dif < midDif) {
            midDif = dif;
            res = i;
        }
    });
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut min_dif = i32::MAX;
        let mut res = -1;
        for i in 0..n {
            let (p_x, p_y) = (points[i][0], points[i][1]);
            if p_x != x && p_y != y {
                continue;
            }
            let dif = (p_x - x).abs() + (p_y - y).abs();
            if dif < min_dif {
                min_dif = dif;
                res = i as i32;
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize) {
    int ans = -1;
    int min = INT_MAX;
    for (int i = 0; i < pointsSize; i++) {
        int* point = points[i];
        if (point[0] != x && point[1] != y) {
            continue;
        }
        int d = abs(x - point[0]) + abs(y - point[1]);
        if (d < min) {
            min = d;
            ans = i;
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

<p>给你两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;，表示你在一个笛卡尔坐标系下的&nbsp;<code>(x, y)</code>&nbsp;处。同时，在同一个坐标系下给你一个数组&nbsp;<code>points</code>&nbsp;，其中&nbsp;<code>points[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示在&nbsp;<code>(a<sub>i</sub>, b<sub>i</sub>)</code>&nbsp;处有一个点。当一个点与你所在的位置有相同的 <code>x</code> 坐标或者相同的 <code>y</code> 坐标时，我们称这个点是 <b>有效的</b>&nbsp;。</p>

<p>请返回距离你当前位置&nbsp;<strong>曼哈顿距离</strong>&nbsp;最近的&nbsp;<strong>有效</strong>&nbsp;点的下标（下标从 <strong>0</strong> 开始）。如果有多个最近的有效点，请返回下标&nbsp;<strong>最小</strong>&nbsp;的一个。如果没有有效点，请返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>两个点 <code>(x<sub>1</sub>, y<sub>1</sub>)</code>&nbsp;和 <code>(x<sub>2</sub>, y<sub>2</sub>)</code>&nbsp;之间的 <strong>曼哈顿距离</strong>&nbsp;为&nbsp;<code>abs(x<sub>1</sub> - x<sub>2</sub>) + abs(y<sub>1</sub> - y<sub>2</sub>)</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
<b>输出：</b>2
<b>解释：</b>所有点中，[3,1]，[2,4] 和 [4,4] 是有效点。有效点中，[2,4] 和 [4,4] 距离你当前位置的曼哈顿距离最小，都为 1 。[2,4] 的下标最小，所以返回 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 4, points = [[3,4]]
<b>输出：</b>0
<b>提示：</b>答案可以与你当前所在位置坐标相同。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>x = 3, y = 4, points = [[2,3]]
<b>输出：</b>-1
<b>解释：</b>没有 有效点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>1 &lt;= x, y, a<sub>i</sub>, b<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

直接遍历 `points` 数组，对于 $points[i]$，如果 $points[i][0] = x$ 或者 $points[i][1] = y$，则说明 $points[i]$ 是有效点，计算曼哈顿距离，更新最小距离和最小距离的下标。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为 `points` 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans, mi = -1, inf
        for i, (a, b) in enumerate(points):
            if a == x or b == y:
                d = abs(a - x) + abs(b - y)
                if mi > d:
                    ans, mi = i, d
        return ans
```

#### Java

```java
class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int ans = -1, mi = 1000000;
        for (int i = 0; i < points.length; ++i) {
            int a = points[i][0], b = points[i][1];
            if (a == x || b == y) {
                int d = Math.abs(a - x) + Math.abs(b - y);
                if (d < mi) {
                    mi = d;
                    ans = i;
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
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1, mi = 1e6;
        for (int i = 0; i < points.size(); ++i) {
            int a = points[i][0], b = points[i][1];
            if (a == x || b == y) {
                int d = abs(a - x) + abs(b - y);
                if (d < mi) {
                    mi = d;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func nearestValidPoint(x int, y int, points [][]int) int {
	ans, mi := -1, 1000000
	for i, p := range points {
		a, b := p[0], p[1]
		if a == x || b == y {
			d := abs(a-x) + abs(b-y)
			if d < mi {
				ans, mi = i, d
			}
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

#### TypeScript

```ts
function nearestValidPoint(x: number, y: number, points: number[][]): number {
    let res = -1;
    let midDif = Infinity;
    points.forEach(([px, py], i) => {
        if (px != x && py != y) {
            return;
        }
        const dif = Math.abs(px - x) + Math.abs(py - y);
        if (dif < midDif) {
            midDif = dif;
            res = i;
        }
    });
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut min_dif = i32::MAX;
        let mut res = -1;
        for i in 0..n {
            let (p_x, p_y) = (points[i][0], points[i][1]);
            if p_x != x && p_y != y {
                continue;
            }
            let dif = (p_x - x).abs() + (p_y - y).abs();
            if dif < min_dif {
                min_dif = dif;
                res = i as i32;
            }
        }
        res
    }
}
```

#### C

```c
int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize) {
    int ans = -1;
    int min = INT_MAX;
    for (int i = 0; i < pointsSize; i++) {
        int* point = points[i];
        if (point[0] != x && point[1] != y) {
            continue;
        }
        int d = abs(x - point[0]) + abs(y - point[1]);
        if (d < min) {
            min = d;
            ans = i;
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
