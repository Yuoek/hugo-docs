---
title: "3040_相同分数的最大操作数目 II"
date: 2025-10-08T18:39:55+08:00
weight: 5
tags: [二分查找, 几何, 动态规划, 哈希函数, 哈希表, 堆（优先队列）, 字典树, 字符串, 字符串匹配, 排序, 数学, 数组, 数论, 枚举, 滚动哈希, 矩阵, 计数, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [3040_相同分数的最大操作数目 II](#3040)
#### [记忆化搜索](#3040)
#### [数组](#3040)
#### [动态规划](#3040)
### [3041_修改数组后最大化数组中的连续元素数目](#3041)
#### [数组](#3041)
#### [动态规划](#3041)
#### [排序](#3041)
### [3042_统计前后缀下标对 I](#3042)
#### [字典树](#3042)
#### [数组](#3042)
#### [字符串](#3042)
#### [字符串匹配](#3042)
#### [哈希函数](#3042)
#### [滚动哈希](#3042)
### [3043_最长公共前缀的长度](#3043)
#### [字典树](#3043)
#### [数组](#3043)
#### [哈希表](#3043)
#### [字符串](#3043)
### [3044_出现频率最高的质数](#3044)
#### [数组](#3044)
#### [哈希表](#3044)
#### [数学](#3044)
#### [计数](#3044)
#### [枚举](#3044)
#### [矩阵](#3044)
#### [数论](#3044)
### [3045_统计前后缀下标对 II](#3045)
#### [字典树](#3045)
#### [数组](#3045)
#### [字符串](#3045)
#### [字符串匹配](#3045)
#### [哈希函数](#3045)
#### [滚动哈希](#3045)
### [3046_分割数组](#3046)
#### [数组](#3046)
#### [哈希表](#3046)
#### [计数](#3046)
### [3047_求交集区域内的最大正方形面积](#3047)
#### [几何](#3047)
#### [数组](#3047)
#### [数学](#3047)
### [3048_标记所有下标的最早秒数 I](#3048)
#### [数组](#3048)
#### [二分查找](#3048)
### [3049_标记所有下标的最早秒数 II](#3049)
#### [贪心](#3049)
#### [数组](#3049)
#### [二分查找](#3049)
#### [堆（优先队列）](#3049)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3040_相同分数的最大操作数目 II
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
---
### 3041_修改数组后最大化数组中的连续元素数目
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 3042_统计前后缀下标对 I
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3043_最长公共前缀的长度
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 3044_出现频率最高的质数
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
___
#### 枚举
___
#### 矩阵
___
#### 数论
---
### 3045_统计前后缀下标对 II
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3046_分割数组
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 3047_求交集区域内的最大正方形面积
___
#### 几何
___
#### 数组
___
#### 数学
---
### 3048_标记所有下标的最早秒数 I
___
#### 数组
___
#### 二分查找
---
### 3049_标记所有下标的最早秒数 II
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 几何 | 动态规划 |
| 哈希函数 | 哈希表 | 堆（优先队列） |
| 字典树 | 字符串 | 字符串匹配 |
| 排序 | 数学 | 数组 |
| 数论 | 枚举 | 滚动哈希 |
| 矩阵 | 计数 | 记忆化搜索 |
| 贪心 |  |  |

# [3040. 相同分数的最大操作数目 II](https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-ii){#3040}

{{< tabs "3040" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, s: int) -> int:
            if j - i < 1:
                return 0
            ans = 0
            if nums[i] + nums[i + 1] == s:
                ans = max(ans, 1 + dfs(i + 2, j, s))
            if nums[i] + nums[j] == s:
                ans = max(ans, 1 + dfs(i + 1, j - 1, s))
            if nums[j - 1] + nums[j] == s:
                ans = max(ans, 1 + dfs(i, j - 2, s))
            return ans

        n = len(nums)
        a = dfs(2, n - 1, nums[0] + nums[1])
        b = dfs(0, n - 3, nums[-1] + nums[-2])
        c = dfs(1, n - 2, nums[0] + nums[-1])
        return 1 + max(a, b, c)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private int[] nums;
    private int s;
    private int n;

    public int maxOperations(int[] nums) {
        this.nums = nums;
        n = nums.length;
        int a = g(2, n - 1, nums[0] + nums[1]);
        int b = g(0, n - 3, nums[n - 2] + nums[n - 1]);
        int c = g(1, n - 2, nums[0] + nums[n - 1]);
        return 1 + Math.max(a, Math.max(b, c));
    }

    private int g(int i, int j, int s) {
        f = new Integer[n][n];
        this.s = s;
        return dfs(i, j);
    }

    private int dfs(int i, int j) {
        if (j - i < 1) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0;
        if (nums[i] + nums[i + 1] == s) {
            ans = Math.max(ans, 1 + dfs(i + 2, j));
        }
        if (nums[i] + nums[j] == s) {
            ans = Math.max(ans, 1 + dfs(i + 1, j - 1));
        }
        if (nums[j - 1] + nums[j] == s) {
            ans = Math.max(ans, 1 + dfs(i, j - 2));
        }
        return f[i][j] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int f[n][n];
        auto g = [&](int i, int j, int s) -> int {
            memset(f, -1, sizeof(f));
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (j - i < 1) {
                    return 0;
                }
                if (f[i][j] != -1) {
                    return f[i][j];
                }
                int ans = 0;
                if (nums[i] + nums[i + 1] == s) {
                    ans = max(ans, 1 + dfs(i + 2, j));
                }
                if (nums[i] + nums[j] == s) {
                    ans = max(ans, 1 + dfs(i + 1, j - 1));
                }
                if (nums[j - 1] + nums[j] == s) {
                    ans = max(ans, 1 + dfs(i, j - 2));
                }
                return f[i][j] = ans;
            };
            return dfs(i, j);
        };
        int a = g(2, n - 1, nums[0] + nums[1]);
        int b = g(0, n - 3, nums[n - 2] + nums[n - 1]);
        int c = g(1, n - 2, nums[0] + nums[n - 1]);
        return 1 + max({a, b, c});
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxOperations(nums []int) int {
	n := len(nums)
	var g func(i, j, s int) int
	g = func(i, j, s int) int {
		f := make([][]int, n)
		for i := range f {
			f[i] = make([]int, n)
			for j := range f {
				f[i][j] = -1
			}
		}
		var dfs func(i, j int) int
		dfs = func(i, j int) int {
			if j-i < 1 {
				return 0
			}
			if f[i][j] != -1 {
				return f[i][j]
			}
			ans := 0
			if nums[i]+nums[i+1] == s {
				ans = max(ans, 1+dfs(i+2, j))
			}

			if nums[i]+nums[j] == s {
				ans = max(ans, 1+dfs(i+1, j-1))
			}

			if nums[j-1]+nums[j] == s {
				ans = max(ans, 1+dfs(i, j-2))
			}
			f[i][j] = ans
			return ans
		}
		return dfs(i, j)
	}
	a := g(2, n-1, nums[0]+nums[1])
	b := g(0, n-3, nums[n-1]+nums[n-2])
	c := g(1, n-2, nums[0]+nums[n-1])
	return 1 + max(a, b, c)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxOperations(nums: number[]): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n));
    const g = (i: number, j: number, s: number): number => {
        f.forEach(row => row.fill(-1));
        const dfs = (i: number, j: number): number => {
            if (j - i < 1) {
                return 0;
            }
            if (f[i][j] !== -1) {
                return f[i][j];
            }
            let ans = 0;
            if (nums[i] + nums[i + 1] === s) {
                ans = Math.max(ans, 1 + dfs(i + 2, j));
            }
            if (nums[i] + nums[j] === s) {
                ans = Math.max(ans, 1 + dfs(i + 1, j - 1));
            }
            if (nums[j - 1] + nums[j] === s) {
                ans = Math.max(ans, 1 + dfs(i, j - 2));
            }
            return (f[i][j] = ans);
        };
        return dfs(i, j);
    };
    const a = g(2, n - 1, nums[0] + nums[1]);
    const b = g(0, n - 3, nums[n - 2] + nums[n - 1]);
    const c = g(1, n - 2, nums[0] + nums[n - 1]);
    return 1 + Math.max(a, b, c);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，如果&nbsp;<code>nums</code>&nbsp;<strong>至少</strong>&nbsp;包含 <code>2</code>&nbsp;个元素，你可以执行以下操作中的&nbsp;<strong>任意</strong>&nbsp;一个：</p>

<ul>
	<li>选择 <code>nums</code>&nbsp;中最前面两个元素并且删除它们。</li>
	<li>选择 <code>nums</code>&nbsp;中最后两个元素并且删除它们。</li>
	<li>选择 <code>nums</code>&nbsp;中第一个和最后一个元素并且删除它们。</li>
</ul>

<p>一次操作的&nbsp;<strong>分数</strong>&nbsp;是被删除元素的和。</p>

<p>在确保<strong>&nbsp;所有操作分数相同</strong>&nbsp;的前提下，请你求出&nbsp;<strong>最多</strong>&nbsp;能进行多少次操作。</p>

<p>请你返回按照上述要求&nbsp;<strong>最多</strong>&nbsp;可以进行的操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,1,2,3,4]
<b>输出：</b>3
<b>解释：</b>我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,2,3,4] 。
- 删除第一个元素和最后一个元素，分数为 1 + 4 = 5 ，nums = [2,3] 。
- 删除第一个元素和最后一个元素，分数为 2 + 3 = 5 ，nums = [] 。
由于 nums 为空，我们无法继续进行任何操作。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,6,1,4]
<b>输出：</b>2
<b>解释：</b>我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
- 删除最后两个元素，分数为 1 + 4 = 5 ，nums = [6] 。
至多进行 2 次操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

分数 $s$ 的取值有三种情况，分别是 $s = nums[0] + nums[1]$, $s = nums[0] + nums[n-1]$, $s = nums[n-1] + nums[n-2]$。我们可以针对这三种情况，分别进行记忆化搜索。

我们设计一个函数 $dfs(i, j)$，表示在分数为 $s$ 的情况下，从下标 $i$ 到下标 $j$ 的最大操作次数。函数 $dfs(i, j)$ 的执行过程如下：

-   如果 $j - i < 1$，表示区间 $[i, j]$ 的长度小于 $2$，无法进行任何操作，返回 $0$。
-   如果 $nums[i] + nums[i+1] = s$，表示可以删除下标 $i$ 和下标 $i+1$ 的元素，此时最大操作次数为 $1 + dfs(i+2, j)$。
-   如果 $nums[i] + nums[j] = s$，表示可以删除下标 $i$ 和下标 $j$ 的元素，此时最大操作次数为 $1 + dfs(i+1, j-1)$。
-   如果 $nums[j-1] + nums[j] = s$，表示可以删除下标 $j-1$ 和下标 $j$ 的元素，此时最大操作次数为 $1 + dfs(i, j-2)$。
-   返回以上的最大值即可。

最后，我们分别计算三种情况的最大操作次数，取最大值返回即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, s: int) -> int:
            if j - i < 1:
                return 0
            ans = 0
            if nums[i] + nums[i + 1] == s:
                ans = max(ans, 1 + dfs(i + 2, j, s))
            if nums[i] + nums[j] == s:
                ans = max(ans, 1 + dfs(i + 1, j - 1, s))
            if nums[j - 1] + nums[j] == s:
                ans = max(ans, 1 + dfs(i, j - 2, s))
            return ans

        n = len(nums)
        a = dfs(2, n - 1, nums[0] + nums[1])
        b = dfs(0, n - 3, nums[-1] + nums[-2])
        c = dfs(1, n - 2, nums[0] + nums[-1])
        return 1 + max(a, b, c)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[] nums;
    private int s;
    private int n;

    public int maxOperations(int[] nums) {
        this.nums = nums;
        n = nums.length;
        int a = g(2, n - 1, nums[0] + nums[1]);
        int b = g(0, n - 3, nums[n - 2] + nums[n - 1]);
        int c = g(1, n - 2, nums[0] + nums[n - 1]);
        return 1 + Math.max(a, Math.max(b, c));
    }

    private int g(int i, int j, int s) {
        f = new Integer[n][n];
        this.s = s;
        return dfs(i, j);
    }

    private int dfs(int i, int j) {
        if (j - i < 1) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0;
        if (nums[i] + nums[i + 1] == s) {
            ans = Math.max(ans, 1 + dfs(i + 2, j));
        }
        if (nums[i] + nums[j] == s) {
            ans = Math.max(ans, 1 + dfs(i + 1, j - 1));
        }
        if (nums[j - 1] + nums[j] == s) {
            ans = Math.max(ans, 1 + dfs(i, j - 2));
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int f[n][n];
        auto g = [&](int i, int j, int s) -> int {
            memset(f, -1, sizeof(f));
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (j - i < 1) {
                    return 0;
                }
                if (f[i][j] != -1) {
                    return f[i][j];
                }
                int ans = 0;
                if (nums[i] + nums[i + 1] == s) {
                    ans = max(ans, 1 + dfs(i + 2, j));
                }
                if (nums[i] + nums[j] == s) {
                    ans = max(ans, 1 + dfs(i + 1, j - 1));
                }
                if (nums[j - 1] + nums[j] == s) {
                    ans = max(ans, 1 + dfs(i, j - 2));
                }
                return f[i][j] = ans;
            };
            return dfs(i, j);
        };
        int a = g(2, n - 1, nums[0] + nums[1]);
        int b = g(0, n - 3, nums[n - 2] + nums[n - 1]);
        int c = g(1, n - 2, nums[0] + nums[n - 1]);
        return 1 + max({a, b, c});
    }
};
```

#### Go

```go
func maxOperations(nums []int) int {
	n := len(nums)
	var g func(i, j, s int) int
	g = func(i, j, s int) int {
		f := make([][]int, n)
		for i := range f {
			f[i] = make([]int, n)
			for j := range f {
				f[i][j] = -1
			}
		}
		var dfs func(i, j int) int
		dfs = func(i, j int) int {
			if j-i < 1 {
				return 0
			}
			if f[i][j] != -1 {
				return f[i][j]
			}
			ans := 0
			if nums[i]+nums[i+1] == s {
				ans = max(ans, 1+dfs(i+2, j))
			}

			if nums[i]+nums[j] == s {
				ans = max(ans, 1+dfs(i+1, j-1))
			}

			if nums[j-1]+nums[j] == s {
				ans = max(ans, 1+dfs(i, j-2))
			}
			f[i][j] = ans
			return ans
		}
		return dfs(i, j)
	}
	a := g(2, n-1, nums[0]+nums[1])
	b := g(0, n-3, nums[n-1]+nums[n-2])
	c := g(1, n-2, nums[0]+nums[n-1])
	return 1 + max(a, b, c)
}
```

#### TypeScript

```ts
function maxOperations(nums: number[]): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n));
    const g = (i: number, j: number, s: number): number => {
        f.forEach(row => row.fill(-1));
        const dfs = (i: number, j: number): number => {
            if (j - i < 1) {
                return 0;
            }
            if (f[i][j] !== -1) {
                return f[i][j];
            }
            let ans = 0;
            if (nums[i] + nums[i + 1] === s) {
                ans = Math.max(ans, 1 + dfs(i + 2, j));
            }
            if (nums[i] + nums[j] === s) {
                ans = Math.max(ans, 1 + dfs(i + 1, j - 1));
            }
            if (nums[j - 1] + nums[j] === s) {
                ans = Math.max(ans, 1 + dfs(i, j - 2));
            }
            return (f[i][j] = ans);
        };
        return dfs(i, j);
    };
    const a = g(2, n - 1, nums[0] + nums[1]);
    const b = g(0, n - 3, nums[n - 2] + nums[n - 1]);
    const c = g(1, n - 2, nums[0] + nums[n - 1]);
    return 1 + Math.max(a, b, c);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3041. 修改数组后最大化数组中的连续元素数目](https://leetcode.cn/problems/maximize-consecutive-elements-in-an-array-after-modification){#3041}

{{< tabs "3041" >}}

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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始只包含 <strong>正</strong>&nbsp;整数的数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一开始，你可以将数组中 <strong>任意数量</strong> 元素增加 <strong>至多</strong> <code>1</code> 。</p>

<p>修改后，你可以从最终数组中选择 <strong>一个或者更多</strong>&nbsp;元素，并确保这些元素升序排序后是 <strong>连续</strong>&nbsp;的。比方说，<code>[3, 4, 5]</code> 是连续的，但是&nbsp;<code>[3, 4, 6]</code> 和&nbsp;<code>[1, 1, 2, 3]</code>&nbsp;不是连续的。<!-- notionvc: 312f8c5d-40d0-4cd1-96cc-9e96a846735b --></p>

<p>请你返回 <strong>最多</strong>&nbsp;可以选出的元素数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,5,1,1]
<b>输出：</b>3
<b>解释：</b>我们将下标 0 和 3 处的元素增加 1 ，得到结果数组 nums = [3,1,5,2,1] 。
我们选择元素 [<em><strong>3</strong></em>,<em><strong>1</strong></em>,5,<em><strong>2</strong></em>,1] 并将它们排序得到 [1,2,3] ，是连续元素。
最多可以得到 3 个连续元素。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,7,10]
<b>输出：</b>1
<b>解释：</b>我们可以选择的最多元素数目是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
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

# [3042. 统计前后缀下标对 I](https://leetcode.cn/problems/count-prefix-and-suffix-pairs-i){#3042}

{{< tabs "3042" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ["children", "cnt"]

    def __init__(self):
        self.children = {}
        self.cnt = 0


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        trie = Node()
        for s in words:
            node = trie
            for p in zip(s, reversed(s)):
                if p not in node.children:
                    node.children[p] = Node()
                node = node.children[p]
                ans += node.cnt
            node.cnt += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Map<Integer, Node> children = new HashMap<>();
    int cnt;
}

class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int ans = 0;
        Node trie = new Node();
        for (String s : words) {
            Node node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s.charAt(i) * 32 + s.charAt(m - i - 1);
                node.children.putIfAbsent(p, new Node());
                node = node.children.get(p);
                ans += node.cnt;
            }
            ++node.cnt;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    unordered_map<int, Node*> children;
    int cnt;

    Node()
        : cnt(0) {}
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        Node* trie = new Node();
        for (const string& s : words) {
            Node* node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s[i] * 32 + s[m - i - 1];
                if (node->children.find(p) == node->children.end()) {
                    node->children[p] = new Node();
                }
                node = node->children[p];
                ans += node->cnt;
            }
            ++node->cnt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	children map[int]*Node
	cnt      int
}

func countPrefixSuffixPairs(words []string) (ans int) {
	trie := &Node{children: make(map[int]*Node)}
	for _, s := range words {
		node := trie
		m := len(s)
		for i := 0; i < m; i++ {
			p := int(s[i])*32 + int(s[m-i-1])
			if _, ok := node.children[p]; !ok {
				node.children[p] = &Node{children: make(map[int]*Node)}
			}
			node = node.children[p]
			ans += node.cnt
		}
		node.cnt++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPrefixSuffixPairs(words: string[]): number {
    let ans = 0;
    for (let i = 0; i < words.length; ++i) {
        const s = words[i];
        for (const t of words.slice(i + 1)) {
            if (t.startsWith(s) && t.endsWith(s)) {
                ++ans;
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 。</p>

<p>定义一个 <strong>布尔 </strong>函数 <code>isPrefixAndSuffix</code> ，它接受两个字符串参数 <code>str1</code> 和 <code>str2</code> ：</p>

<ul>
	<li>当 <code>str1</code> 同时是 <code>str2</code> 的前缀（<span data-keyword="string-prefix">prefix</span>）和后缀（<span data-keyword="string-suffix">suffix</span>）时，<code>isPrefixAndSuffix(str1, str2)</code> 返回 <code>true</code>，否则返回 <code>false</code>。</li>
</ul>

<p>例如，<code>isPrefixAndSuffix("aba", "ababa")</code> 返回 <code>true</code>，因为 <code>"aba"</code> 既是 <code>"ababa"</code> 的前缀，也是 <code>"ababa"</code> 的后缀，但是 <code>isPrefixAndSuffix("abc", "abcd")</code> 返回<code> false</code>。</p>

<p>以整数形式，返回满足 <code>i &lt; j</code> 且 <code>isPrefixAndSuffix(words[i], words[j])</code> 为 <code>true</code> 的下标对 <code>(i, j)</code> 的<strong> 数量 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","aba","ababa","aa"]
<strong>输出：</strong>4
<strong>解释：</strong>在本示例中，计数的下标对包括：
i = 0 且 j = 1 ，因为 isPrefixAndSuffix("a", "aba") 为 true 。
i = 0 且 j = 2 ，因为 isPrefixAndSuffix("a", "ababa") 为 true 。
i = 0 且 j = 3 ，因为 isPrefixAndSuffix("a", "aa") 为 true 。
i = 1 且 j = 2 ，因为 isPrefixAndSuffix("aba", "ababa") 为 true 。
因此，答案是 4 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["pa","papa","ma","mama"]
<strong>输出：</strong>2
<strong>解释：</strong>在本示例中，计数的下标对包括：
i = 0 且 j = 1 ，因为 isPrefixAndSuffix("pa", "papa") 为 true 。
i = 2 且 j = 3 ，因为 isPrefixAndSuffix("ma", "mama") 为 true 。
因此，答案是 2 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["abab","ab"]
<strong>输出：</strong>0
<strong>解释：</strong>在本示例中，唯一有效的下标对是 i = 0 且 j = 1 ，但是 isPrefixAndSuffix("abab", "ab") 为 false 。
因此，答案是 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举所有的下标对 $(i, j)$，其中 $i \lt j$，然后判断 `words[i]` 是否是 `words[j]` 的前缀和后缀，若是则计数加一。

时间复杂度 $O(n^2 \times m)$，其中 $n$ 和 $m$ 分别为 `words` 的长度和字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        for i, s in enumerate(words):
            for t in words[i + 1 :]:
                ans += t.endswith(s) and t.startswith(s)
        return ans
```

#### Java

```java
class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int ans = 0;
        int n = words.length;
        for (int i = 0; i < n; ++i) {
            String s = words[i];
            for (int j = i + 1; j < n; ++j) {
                String t = words[j];
                if (t.startsWith(s) && t.endsWith(s)) {
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
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string s = words[i];
            for (int j = i + 1; j < n; ++j) {
                string t = words[j];
                if (t.find(s) == 0 && t.rfind(s) == t.length() - s.length()) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPrefixSuffixPairs(words []string) (ans int) {
	for i, s := range words {
		for _, t := range words[i+1:] {
			if strings.HasPrefix(t, s) && strings.HasSuffix(t, s) {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countPrefixSuffixPairs(words: string[]): number {
    let ans = 0;
    for (let i = 0; i < words.length; ++i) {
        const s = words[i];
        for (const t of words.slice(i + 1)) {
            if (t.startsWith(s) && t.endsWith(s)) {
                ++ans;
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字典树

我们可以把字符串数组中的每个字符串 $s$ 当作一个字符对的列表，其中每个字符对 $(s[i], s[m - i - 1])$ 表示字符串 $s$ 的前缀和后缀的第 $i$ 个字符对。

我们可以使用字典树来存储所有的字符对，然后对于每个字符串 $s$，我们在字典树中查找所有的字符对 $(s[i], s[m - i - 1])$，并将其计数加到答案中。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别为 `words` 的长度和字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ["children", "cnt"]

    def __init__(self):
        self.children = {}
        self.cnt = 0


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        trie = Node()
        for s in words:
            node = trie
            for p in zip(s, reversed(s)):
                if p not in node.children:
                    node.children[p] = Node()
                node = node.children[p]
                ans += node.cnt
            node.cnt += 1
        return ans
```

#### Java

```java
class Node {
    Map<Integer, Node> children = new HashMap<>();
    int cnt;
}

class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int ans = 0;
        Node trie = new Node();
        for (String s : words) {
            Node node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s.charAt(i) * 32 + s.charAt(m - i - 1);
                node.children.putIfAbsent(p, new Node());
                node = node.children.get(p);
                ans += node.cnt;
            }
            ++node.cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    unordered_map<int, Node*> children;
    int cnt;

    Node()
        : cnt(0) {}
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        Node* trie = new Node();
        for (const string& s : words) {
            Node* node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s[i] * 32 + s[m - i - 1];
                if (node->children.find(p) == node->children.end()) {
                    node->children[p] = new Node();
                }
                node = node->children[p];
                ans += node->cnt;
            }
            ++node->cnt;
        }
        return ans;
    }
};
```

#### Go

```go
type Node struct {
	children map[int]*Node
	cnt      int
}

func countPrefixSuffixPairs(words []string) (ans int) {
	trie := &Node{children: make(map[int]*Node)}
	for _, s := range words {
		node := trie
		m := len(s)
		for i := 0; i < m; i++ {
			p := int(s[i])*32 + int(s[m-i-1])
			if _, ok := node.children[p]; !ok {
				node.children[p] = &Node{children: make(map[int]*Node)}
			}
			node = node.children[p]
			ans += node.cnt
		}
		node.cnt++
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3043. 最长公共前缀的长度](https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix){#3043}

{{< tabs "3043" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        s = set()
        for x in arr1:
            while x:
                s.add(x)
                x //= 10
        ans = 0
        for x in arr2:
            while x:
                if x in s:
                    ans = max(ans, len(str(x)))
                    break
                x //= 10
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> s = new HashSet<>();
        for (int x : arr1) {
            for (; x > 0; x /= 10) {
                s.add(x);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            for (; x > 0; x /= 10) {
                if (s.contains(x)) {
                    ans = Math.max(ans, String.valueOf(x).length());
                    break;
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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int x : arr1) {
            for (; x; x /= 10) {
                s.insert(x);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            for (; x; x /= 10) {
                if (s.count(x)) {
                    ans = max(ans, (int) log10(x) + 1);
                    break;
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
func longestCommonPrefix(arr1 []int, arr2 []int) (ans int) {
	s := map[int]bool{}
	for _, x := range arr1 {
		for ; x > 0; x /= 10 {
			s[x] = true
		}
	}
	for _, x := range arr2 {
		for ; x > 0; x /= 10 {
			if s[x] {
				ans = max(ans, int(math.Log10(float64(x)))+1)
				break
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestCommonPrefix(arr1: number[], arr2: number[]): number {
    const s: Set<number> = new Set<number>();
    for (let x of arr1) {
        for (; x; x = Math.floor(x / 10)) {
            s.add(x);
        }
    }
    let ans: number = 0;
    for (let x of arr2) {
        for (; x; x = Math.floor(x / 10)) {
            if (s.has(x)) {
                ans = Math.max(ans, Math.floor(Math.log10(x)) + 1);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function (arr1, arr2) {
    const s = new Set();
    for (let x of arr1) {
        for (; x; x = Math.floor(x / 10)) {
            s.add(x);
        }
    }
    let ans = 0;
    for (let x of arr2) {
        for (; x; x = Math.floor(x / 10)) {
            if (s.has(x)) {
                ans = Math.max(ans, Math.floor(Math.log10(x)) + 1);
            }
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

<p>给你两个 <strong>正整数 </strong>数组 <code>arr1</code> 和 <code>arr2</code> 。</p>

<p>正整数的 <strong>前缀 </strong>是其 <strong>最左边 </strong>的一位或多位数字组成的整数。例如，<code>123</code> 是整数 <code>12345</code> 的前缀，而 <code>234</code><strong> 不是 </strong>。</p>

<p>设若整数 <code>c</code> 是整数 <code>a</code> 和 <code>b</code> 的<strong> 公共前缀 </strong>，那么 <code>c</code> 需要同时是 <code>a</code> 和 <code>b</code> 的前缀。例如，<code>5655359</code> 和 <code>56554</code> 有公共前缀 <code>565</code>&nbsp;和 <code>5655</code>，而 <code>1223</code> 和 <code>43456</code><strong> 没有 </strong>公共前缀。</p>

<p>你需要找出属于 <code>arr1</code> 的整数 <code>x</code> 和属于 <code>arr2</code> 的整数 <code>y</code> 组成的所有数对 <code>(x, y)</code> 之中最长的公共前缀的长度。</p>

<p>返回所有数对之中最长公共前缀的长度。如果它们之间不存在公共前缀，则返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,10,100], arr2 = [1000]
<strong>输出：</strong>3
<strong>解释：</strong>存在 3 个数对 (arr1[i], arr2[j]) ：
- (1, 1000) 的最长公共前缀是 1 。
- (10, 1000) 的最长公共前缀是 10 。
- (100, 1000) 的最长公共前缀是 100 。
最长的公共前缀是 100 ，长度为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,2,3], arr2 = [4,4,4]
<strong>输出：</strong>0
<strong>解释：</strong>任何数对 (arr1[i], arr2[j]) 之中都不存在公共前缀，因此返回 0 。
请注意，同一个数组内元素之间的公共前缀不在考虑范围内。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr1[i], arr2[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以使用哈希表来存储 `arr1` 中的所有数字的前缀，然后遍历 `arr2` 中的所有数字 $x$，对于每个数字 $x$，我们从最高位开始逐渐减小，判断是否存在于哈希表中，如果存在，那么我们就找到了一个公共前缀，此时更新答案即可。

时间复杂度 $O(m \times \log M + n \times \log N)$，空间复杂度 $O(m \times \log M)$。其中 $m$ 和 $n$ 分别是 `arr1` 和 `arr2` 的长度，而 $M$ 和 $N$ 分别是 `arr1` 和 `arr2` 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        s = set()
        for x in arr1:
            while x:
                s.add(x)
                x //= 10
        ans = 0
        for x in arr2:
            while x:
                if x in s:
                    ans = max(ans, len(str(x)))
                    break
                x //= 10
        return ans
```

#### Java

```java
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> s = new HashSet<>();
        for (int x : arr1) {
            for (; x > 0; x /= 10) {
                s.add(x);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            for (; x > 0; x /= 10) {
                if (s.contains(x)) {
                    ans = Math.max(ans, String.valueOf(x).length());
                    break;
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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int x : arr1) {
            for (; x; x /= 10) {
                s.insert(x);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            for (; x; x /= 10) {
                if (s.count(x)) {
                    ans = max(ans, (int) log10(x) + 1);
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestCommonPrefix(arr1 []int, arr2 []int) (ans int) {
	s := map[int]bool{}
	for _, x := range arr1 {
		for ; x > 0; x /= 10 {
			s[x] = true
		}
	}
	for _, x := range arr2 {
		for ; x > 0; x /= 10 {
			if s[x] {
				ans = max(ans, int(math.Log10(float64(x)))+1)
				break
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function longestCommonPrefix(arr1: number[], arr2: number[]): number {
    const s: Set<number> = new Set<number>();
    for (let x of arr1) {
        for (; x; x = Math.floor(x / 10)) {
            s.add(x);
        }
    }
    let ans: number = 0;
    for (let x of arr2) {
        for (; x; x = Math.floor(x / 10)) {
            if (s.has(x)) {
                ans = Math.max(ans, Math.floor(Math.log10(x)) + 1);
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function (arr1, arr2) {
    const s = new Set();
    for (let x of arr1) {
        for (; x; x = Math.floor(x / 10)) {
            s.add(x);
        }
    }
    let ans = 0;
    for (let x of arr2) {
        for (; x; x = Math.floor(x / 10)) {
            if (s.has(x)) {
                ans = Math.max(ans, Math.floor(Math.log10(x)) + 1);
            }
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

# [3044. 出现频率最高的质数](https://leetcode.cn/problems/most-frequent-prime){#3044}

{{< tabs "3044" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostFrequentPrime(self, mat: List[List[int]]) -> int:
        def is_prime(x: int) -> int:
            return all(x % i != 0 for i in range(2, isqrt(x) + 1))

        m, n = len(mat), len(mat[0])
        cnt = Counter()
        for i in range(m):
            for j in range(n):
                for a in range(-1, 2):
                    for b in range(-1, 2):
                        if a == 0 and b == 0:
                            continue
                        x, y, v = i + a, j + b, mat[i][j]
                        while 0 <= x < m and 0 <= y < n:
                            v = v * 10 + mat[x][y]
                            if is_prime(v):
                                cnt[v] += 1
                            x, y = x + a, y + b
        ans, mx = -1, 0
        for v, x in cnt.items():
            if mx < x:
                mx = x
                ans = v
            elif mx == x:
                ans = max(ans, v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mostFrequentPrime(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int a = -1; a <= 1; ++a) {
                    for (int b = -1; b <= 1; ++b) {
                        if (a == 0 && b == 0) {
                            continue;
                        }
                        int x = i + a, y = j + b, v = mat[i][j];
                        while (x >= 0 && x < m && y >= 0 && y < n) {
                            v = v * 10 + mat[x][y];
                            if (isPrime(v)) {
                                cnt.merge(v, 1, Integer::sum);
                            }
                            x += a;
                            y += b;
                        }
                    }
                }
            }
        }
        int ans = -1, mx = 0;
        for (var e : cnt.entrySet()) {
            int v = e.getKey(), x = e.getValue();
            if (mx < x || (mx == x && ans < v)) {
                mx = x;
                ans = v;
            }
        }
        return ans;
    }

    private boolean isPrime(int n) {
        for (int i = 2; i <= n / i; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int a = -1; a <= 1; ++a) {
                    for (int b = -1; b <= 1; ++b) {
                        if (a == 0 && b == 0) {
                            continue;
                        }
                        int x = i + a, y = j + b, v = mat[i][j];
                        while (x >= 0 && x < m && y >= 0 && y < n) {
                            v = v * 10 + mat[x][y];
                            if (isPrime(v)) {
                                cnt[v]++;
                            }
                            x += a;
                            y += b;
                        }
                    }
                }
            }
        }
        int ans = -1, mx = 0;
        for (auto& [v, x] : cnt) {
            if (mx < x || (mx == x && ans < v)) {
                mx = x;
                ans = v;
            }
        }
        return ans;
    }

private:
    bool isPrime(int n) {
        for (int i = 2; i <= n / i; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostFrequentPrime(mat [][]int) int {
	m, n := len(mat), len(mat[0])
	cnt := make(map[int]int)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for a := -1; a <= 1; a++ {
				for b := -1; b <= 1; b++ {
					if a == 0 && b == 0 {
						continue
					}
					x, y, v := i+a, j+b, mat[i][j]
					for x >= 0 && x < m && y >= 0 && y < n {
						v = v*10 + mat[x][y]
						if isPrime(v) {
							cnt[v]++
						}
						x += a
						y += b
					}
				}
			}
		}
	}
	ans, mx := -1, 0
	for v, x := range cnt {
		if mx < x || (mx == x && ans < v) {
			mx = x
			ans = v
		}
	}
	return ans
}

func isPrime(n int) bool {
	for i := 2; i <= n/i; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostFrequentPrime(mat: number[][]): number {
    const m: number = mat.length;
    const n: number = mat[0].length;
    const cnt: Map<number, number> = new Map();
    const isPrime = (x: number): boolean => {
        for (let i = 2; i <= x / i; ++i) {
            if (x % i === 0) {
                return false;
            }
        }
        return true;
    };

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let a = -1; a <= 1; ++a) {
                for (let b = -1; b <= 1; ++b) {
                    if (a === 0 && b === 0) {
                        continue;
                    }
                    let [x, y, v] = [i + a, j + b, mat[i][j]];
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        v = v * 10 + mat[x][y];
                        if (isPrime(v)) {
                            cnt.set(v, (cnt.get(v) || 0) + 1);
                        }
                        x += a;
                        y += b;
                    }
                }
            }
        }
    }

    let [ans, mx] = [-1, 0];
    cnt.forEach((x, v) => {
        if (mx < x || (mx === x && ans < v)) {
            mx = x;
            ans = v;
        }
    });
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 、下标从 <strong>0</strong> 开始的二维矩阵 <code>mat</code> 。在每个单元格，你可以按以下方式生成数字：</p>

<ul>
	<li>最多有 <code>8</code> 条路径可以选择：东，东南，南，西南，西，西北，北，东北。</li>
	<li>选择其中一条路径，沿着这个方向移动，并且将路径上的数字添加到正在形成的数字后面。</li>
	<li>注意，每一步都会生成数字，例如，如果路径上的数字是 <code>1, 9, 1</code>，那么在这个方向上会生成三个数字：<code>1, 19, 191</code> 。</li>
</ul>

<p>返回在遍历矩阵所创建的所有数字中，出现频率最高的、<strong>大于</strong> <code>10</code>的<span data-keyword="prime-number">质数</span>；如果不存在这样的质数，则返回 <code>-1</code><em> </em>。如果存在多个出现频率最高的质数，那么返回其中最大的那个。</p>

<p><strong>注意：</strong>移动过程中不允许改变方向。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3044.Most%20Frequent%20Prime/images/south" style="width: 641px; height: 291px;" /> </strong>

<pre>
<strong>
输入：</strong>mat = [[1,1],[9,9],[1,1]]
<strong>输出：</strong>19
<strong>解释：</strong> 
从单元格 (0,0) 出发，有 3 个可能的方向，这些方向上可以生成的大于 10 的数字有：
东方向: [11], 东南方向: [19], 南方向: [19,191] 。
从单元格 (0,1) 出发，所有可能方向上生成的大于 10 的数字有：[19,191,19,11] 。
从单元格 (1,0) 出发，所有可能方向上生成的大于 10 的数字有：[99,91,91,91,91] 。
从单元格 (1,1) 出发，所有可能方向上生成的大于 10 的数字有：[91,91,99,91,91] 。
从单元格 (2,0) 出发，所有可能方向上生成的大于 10 的数字有：[11,19,191,19] 。
从单元格 (2,1) 出发，所有可能方向上生成的大于 10 的数字有：[11,19,19,191] 。
在所有生成的数字中，出现频率最高的质数是 19 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[7]]
<strong>输出：</strong>-1
<strong>解释：</strong>唯一可以生成的数字是 7 。它是一个质数，但不大于 10 ，所以返回 -1 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[9,7,8],[4,6,5],[2,8,6]]
<strong>输出：</strong>97
<strong>解释：</strong> 
从单元格 (0,0) 出发，所有可能方向上生成的大于 10 的数字有: [97,978,96,966,94,942] 。
从单元格 (0,1) 出发，所有可能方向上生成的大于 10 的数字有: [78,75,76,768,74,79] 。
从单元格 (0,2) 出发，所有可能方向上生成的大于 10 的数字有: [85,856,86,862,87,879] 。
从单元格 (1,0) 出发，所有可能方向上生成的大于 10 的数字有: [46,465,48,42,49,47] 。
从单元格 (1,1) 出发，所有可能方向上生成的大于 10 的数字有: [65,66,68,62,64,69,67,68] 。
从单元格 (1,2) 出发，所有可能方向上生成的大于 10 的数字有: [56,58,56,564,57,58] 。
从单元格 (2,0) 出发，所有可能方向上生成的大于 10 的数字有: [28,286,24,249,26,268] 。
从单元格 (2,1) 出发，所有可能方向上生成的大于 10 的数字有: [86,82,84,86,867,85] 。
从单元格 (2,2) 出发，所有可能方向上生成的大于 10 的数字有: [68,682,66,669,65,658] 。
在所有生成的数字中，出现频率最高的质数是 97 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 6</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们可以使用哈希表来统计每个大于 10 的素数出现的次数。

对于每个单元格，我们可以从它出发，沿着 8 个方向之一生成数字，然后判断生成的数字是否是大于 $10$ 的素数，如果是的话，就将它加入到哈希表中。

最后，我们遍历哈希表，找到出现频率最高的质数，如果有多个出现频率最高的质数，那么返回其中最大的那个。

时间复杂度 $O(m \times n \times \max(m, n) \times {10}^{\frac{\max(m, n)}{2}})$，空间复杂度 $O(m \times n \times \max(m, n))$。其中 $m$ 和 $n$ 分别是 `mat` 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostFrequentPrime(self, mat: List[List[int]]) -> int:
        def is_prime(x: int) -> int:
            return all(x % i != 0 for i in range(2, isqrt(x) + 1))

        m, n = len(mat), len(mat[0])
        cnt = Counter()
        for i in range(m):
            for j in range(n):
                for a in range(-1, 2):
                    for b in range(-1, 2):
                        if a == 0 and b == 0:
                            continue
                        x, y, v = i + a, j + b, mat[i][j]
                        while 0 <= x < m and 0 <= y < n:
                            v = v * 10 + mat[x][y]
                            if is_prime(v):
                                cnt[v] += 1
                            x, y = x + a, y + b
        ans, mx = -1, 0
        for v, x in cnt.items():
            if mx < x:
                mx = x
                ans = v
            elif mx == x:
                ans = max(ans, v)
        return ans
```

#### Java

```java
class Solution {
    public int mostFrequentPrime(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int a = -1; a <= 1; ++a) {
                    for (int b = -1; b <= 1; ++b) {
                        if (a == 0 && b == 0) {
                            continue;
                        }
                        int x = i + a, y = j + b, v = mat[i][j];
                        while (x >= 0 && x < m && y >= 0 && y < n) {
                            v = v * 10 + mat[x][y];
                            if (isPrime(v)) {
                                cnt.merge(v, 1, Integer::sum);
                            }
                            x += a;
                            y += b;
                        }
                    }
                }
            }
        }
        int ans = -1, mx = 0;
        for (var e : cnt.entrySet()) {
            int v = e.getKey(), x = e.getValue();
            if (mx < x || (mx == x && ans < v)) {
                mx = x;
                ans = v;
            }
        }
        return ans;
    }

    private boolean isPrime(int n) {
        for (int i = 2; i <= n / i; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int a = -1; a <= 1; ++a) {
                    for (int b = -1; b <= 1; ++b) {
                        if (a == 0 && b == 0) {
                            continue;
                        }
                        int x = i + a, y = j + b, v = mat[i][j];
                        while (x >= 0 && x < m && y >= 0 && y < n) {
                            v = v * 10 + mat[x][y];
                            if (isPrime(v)) {
                                cnt[v]++;
                            }
                            x += a;
                            y += b;
                        }
                    }
                }
            }
        }
        int ans = -1, mx = 0;
        for (auto& [v, x] : cnt) {
            if (mx < x || (mx == x && ans < v)) {
                mx = x;
                ans = v;
            }
        }
        return ans;
    }

private:
    bool isPrime(int n) {
        for (int i = 2; i <= n / i; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func mostFrequentPrime(mat [][]int) int {
	m, n := len(mat), len(mat[0])
	cnt := make(map[int]int)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for a := -1; a <= 1; a++ {
				for b := -1; b <= 1; b++ {
					if a == 0 && b == 0 {
						continue
					}
					x, y, v := i+a, j+b, mat[i][j]
					for x >= 0 && x < m && y >= 0 && y < n {
						v = v*10 + mat[x][y]
						if isPrime(v) {
							cnt[v]++
						}
						x += a
						y += b
					}
				}
			}
		}
	}
	ans, mx := -1, 0
	for v, x := range cnt {
		if mx < x || (mx == x && ans < v) {
			mx = x
			ans = v
		}
	}
	return ans
}

func isPrime(n int) bool {
	for i := 2; i <= n/i; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function mostFrequentPrime(mat: number[][]): number {
    const m: number = mat.length;
    const n: number = mat[0].length;
    const cnt: Map<number, number> = new Map();
    const isPrime = (x: number): boolean => {
        for (let i = 2; i <= x / i; ++i) {
            if (x % i === 0) {
                return false;
            }
        }
        return true;
    };

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let a = -1; a <= 1; ++a) {
                for (let b = -1; b <= 1; ++b) {
                    if (a === 0 && b === 0) {
                        continue;
                    }
                    let [x, y, v] = [i + a, j + b, mat[i][j]];
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        v = v * 10 + mat[x][y];
                        if (isPrime(v)) {
                            cnt.set(v, (cnt.get(v) || 0) + 1);
                        }
                        x += a;
                        y += b;
                    }
                }
            }
        }
    }

    let [ans, mx] = [-1, 0];
    cnt.forEach((x, v) => {
        if (mx < x || (mx === x && ans < v)) {
            mx = x;
            ans = v;
        }
    });
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3045. 统计前后缀下标对 II](https://leetcode.cn/problems/count-prefix-and-suffix-pairs-ii){#3045}

{{< tabs "3045" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ["children", "cnt"]

    def __init__(self):
        self.children = {}
        self.cnt = 0


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        trie = Node()
        for s in words:
            node = trie
            for p in zip(s, reversed(s)):
                if p not in node.children:
                    node.children[p] = Node()
                node = node.children[p]
                ans += node.cnt
            node.cnt += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Map<Integer, Node> children = new HashMap<>();
    int cnt;
}

class Solution {
    public long countPrefixSuffixPairs(String[] words) {
        long ans = 0;
        Node trie = new Node();
        for (String s : words) {
            Node node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s.charAt(i) * 32 + s.charAt(m - i - 1);
                node.children.putIfAbsent(p, new Node());
                node = node.children.get(p);
                ans += node.cnt;
            }
            ++node.cnt;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    unordered_map<int, Node*> children;
    int cnt;

    Node()
        : cnt(0) {}
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        Node* trie = new Node();
        for (const string& s : words) {
            Node* node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s[i] * 32 + s[m - i - 1];
                if (node->children.find(p) == node->children.end()) {
                    node->children[p] = new Node();
                }
                node = node->children[p];
                ans += node->cnt;
            }
            ++node->cnt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	children map[int]*Node
	cnt      int
}

func countPrefixSuffixPairs(words []string) (ans int64) {
	trie := &Node{children: make(map[int]*Node)}
	for _, s := range words {
		node := trie
		m := len(s)
		for i := 0; i < m; i++ {
			p := int(s[i])*32 + int(s[m-i-1])
			if _, ok := node.children[p]; !ok {
				node.children[p] = &Node{children: make(map[int]*Node)}
			}
			node = node.children[p]
			ans += int64(node.cnt)
		}
		node.cnt++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    children: Map<number, Node> = new Map<number, Node>();
    cnt: number = 0;
}

function countPrefixSuffixPairs(words: string[]): number {
    let ans: number = 0;
    const trie: Node = new Node();
    for (const s of words) {
        let node: Node = trie;
        const m: number = s.length;
        for (let i: number = 0; i < m; ++i) {
            const p: number = s.charCodeAt(i) * 32 + s.charCodeAt(m - i - 1);
            if (!node.children.has(p)) {
                node.children.set(p, new Node());
            }
            node = node.children.get(p)!;
            ans += node.cnt;
        }
        ++node.cnt;
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 。</p>

<p>定义一个 <strong>布尔 </strong>函数 <code>isPrefixAndSuffix</code> ，它接受两个字符串参数 <code>str1</code> 和 <code>str2</code> ：</p>

<ul>
	<li>当 <code>str1</code> 同时是 <code>str2</code> 的前缀（<span data-keyword="string-prefix">prefix</span>）和后缀（<span data-keyword="string-suffix">suffix</span>）时，<code>isPrefixAndSuffix(str1, str2)</code> 返回 <code>true</code>，否则返回 <code>false</code>。</li>
</ul>

<p>例如，<code>isPrefixAndSuffix("aba", "ababa")</code> 返回 <code>true</code>，因为 <code>"aba"</code> 既是 <code>"ababa"</code> 的前缀，也是 <code>"ababa"</code> 的后缀，但是 <code>isPrefixAndSuffix("abc", "abcd")</code> 返回<code> false</code>。</p>

<p>以整数形式，返回满足 <code>i &lt; j</code> 且 <code>isPrefixAndSuffix(words[i], words[j])</code> 为 <code>true</code> 的下标对 <code>(i, j)</code> 的<strong> 数量 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","aba","ababa","aa"]
<strong>输出：</strong>4
<strong>解释：</strong>在本示例中，计数的下标对包括：
i = 0 且 j = 1 ，因为 isPrefixAndSuffix("a", "aba") 为 true 。
i = 0 且 j = 2 ，因为 isPrefixAndSuffix("a", "ababa") 为 true 。
i = 0 且 j = 3 ，因为 isPrefixAndSuffix("a", "aa") 为 true 。
i = 1 且 j = 2 ，因为 isPrefixAndSuffix("aba", "ababa") 为 true 。
因此，答案是 4 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["pa","papa","ma","mama"]
<strong>输出：</strong>2
<strong>解释：</strong>在本示例中，计数的下标对包括：
i = 0 且 j = 1 ，因为 isPrefixAndSuffix("pa", "papa") 为 true 。
i = 2 且 j = 3 ，因为 isPrefixAndSuffix("ma", "mama") 为 true 。
因此，答案是 2 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["abab","ab"]
<strong>输出：</strong>0
<strong>解释：</strong>在本示例中，唯一有效的下标对是 i = 0 且 j = 1 ，但是 isPrefixAndSuffix("abab", "ab") 为 false 。
因此，答案是 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10<sup>5</sup></code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成。</li>
	<li>所有 <code>words[i]</code> 的长度之和不超过 <code>5 * 10<sup>5</sup></code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树

我们可以把字符串数组中的每个字符串 $s$ 当作一个字符对的列表，其中每个字符对 $(s[i], s[m - i - 1])$ 表示字符串 $s$ 的前缀和后缀的第 $i$ 个字符对。

我们可以使用字典树来存储所有的字符对，然后对于每个字符串 $s$，我们在字典树中查找所有的字符对 $(s[i], s[m - i - 1])$，并将其计数加到答案中。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别为 `words` 的长度和字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ["children", "cnt"]

    def __init__(self):
        self.children = {}
        self.cnt = 0


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        trie = Node()
        for s in words:
            node = trie
            for p in zip(s, reversed(s)):
                if p not in node.children:
                    node.children[p] = Node()
                node = node.children[p]
                ans += node.cnt
            node.cnt += 1
        return ans
```

#### Java

```java
class Node {
    Map<Integer, Node> children = new HashMap<>();
    int cnt;
}

class Solution {
    public long countPrefixSuffixPairs(String[] words) {
        long ans = 0;
        Node trie = new Node();
        for (String s : words) {
            Node node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s.charAt(i) * 32 + s.charAt(m - i - 1);
                node.children.putIfAbsent(p, new Node());
                node = node.children.get(p);
                ans += node.cnt;
            }
            ++node.cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    unordered_map<int, Node*> children;
    int cnt;

    Node()
        : cnt(0) {}
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        Node* trie = new Node();
        for (const string& s : words) {
            Node* node = trie;
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                int p = s[i] * 32 + s[m - i - 1];
                if (node->children.find(p) == node->children.end()) {
                    node->children[p] = new Node();
                }
                node = node->children[p];
                ans += node->cnt;
            }
            ++node->cnt;
        }
        return ans;
    }
};
```

#### Go

```go
type Node struct {
	children map[int]*Node
	cnt      int
}

func countPrefixSuffixPairs(words []string) (ans int64) {
	trie := &Node{children: make(map[int]*Node)}
	for _, s := range words {
		node := trie
		m := len(s)
		for i := 0; i < m; i++ {
			p := int(s[i])*32 + int(s[m-i-1])
			if _, ok := node.children[p]; !ok {
				node.children[p] = &Node{children: make(map[int]*Node)}
			}
			node = node.children[p]
			ans += int64(node.cnt)
		}
		node.cnt++
	}
	return
}
```

#### TypeScript

```ts
class Node {
    children: Map<number, Node> = new Map<number, Node>();
    cnt: number = 0;
}

function countPrefixSuffixPairs(words: string[]): number {
    let ans: number = 0;
    const trie: Node = new Node();
    for (const s of words) {
        let node: Node = trie;
        const m: number = s.length;
        for (let i: number = 0; i < m; ++i) {
            const p: number = s.charCodeAt(i) * 32 + s.charCodeAt(m - i - 1);
            if (!node.children.has(p)) {
                node.children.set(p, new Node());
            }
            node = node.children.get(p)!;
            ans += node.cnt;
        }
        ++node.cnt;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3046. 分割数组](https://leetcode.cn/problems/split-the-array){#3046}

{{< tabs "3046" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        return max(Counter(nums).values()) < 3
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            if (++cnt[x] >= 3) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int cnt[101]{};
        for (int x : nums) {
            if (++cnt[x] >= 3) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPossibleToSplit(nums []int) bool {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] >= 3 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPossibleToSplit(nums: number[]): boolean {
    const cnt: number[] = Array(101).fill(0);
    for (const x of nums) {
        if (++cnt[x] >= 3) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn is_possible_to_split(nums: Vec<i32>) -> bool {
        let mut cnt = HashMap::new();
        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        *cnt.values().max().unwrap_or(&0) < 3
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsPossibleToSplit(int[] nums) {
        int[] cnt = new int[101];
        foreach (int x in nums) {
            if (++cnt[x] >= 3) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <strong>偶数 </strong>的整数数组 <code>nums</code> 。你需要将这个数组分割成 <code>nums1</code> 和 <code>nums2</code> 两部分，要求：</p>

<ul>
	<li><code>nums1.length == nums2.length == nums.length / 2</code> 。</li>
	<li><code>nums1</code> 应包含 <strong>互不相同</strong><strong> </strong>的元素。</li>
	<li><code>nums2</code>也应包含<strong> 互不相同</strong> 的元素。</li>
</ul>

<p>如果能够分割数组就返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,2,3,4]
<strong>输出：</strong>true
<strong>解释：</strong>分割 nums 的可行方案之一是 nums1 = [1,2,3] 和 nums2 = [1,2,4] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1]
<strong>输出：</strong>false
<strong>解释：</strong>分割 nums 的唯一可行方案是 nums1 = [1,1] 和 nums2 = [1,1] 。但 nums1 和 nums2 都不是由互不相同的元素构成。因此，返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

根据题意，我们需要将数组分成两部分，每部分的元素都是互不相同的。因此，我们可以统计数组中每个元素的出现次数，如果某个元素出现的次数大于等于 $3$ 次，那么就无法满足题意。否则，我们可以将数组分成两部分。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        return max(Counter(nums).values()) < 3
```

#### Java

```java
class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            if (++cnt[x] >= 3) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int cnt[101]{};
        for (int x : nums) {
            if (++cnt[x] >= 3) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isPossibleToSplit(nums []int) bool {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] >= 3 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isPossibleToSplit(nums: number[]): boolean {
    const cnt: number[] = Array(101).fill(0);
    for (const x of nums) {
        if (++cnt[x] >= 3) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn is_possible_to_split(nums: Vec<i32>) -> bool {
        let mut cnt = HashMap::new();
        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        *cnt.values().max().unwrap_or(&0) < 3
    }
}
```

#### C#

```cs
public class Solution {
    public bool IsPossibleToSplit(int[] nums) {
        int[] cnt = new int[101];
        foreach (int x in nums) {
            if (++cnt[x] >= 3) {
                return false;
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3047. 求交集区域内的最大正方形面积](https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles){#3047}

{{< tabs "3047" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestSquareArea(
        self, bottomLeft: List[List[int]], topRight: List[List[int]]
    ) -> int:
        ans = 0
        for ((x1, y1), (x2, y2)), ((x3, y3), (x4, y4)) in combinations(
            zip(bottomLeft, topRight), 2
        ):
            w = min(x2, x4) - max(x1, x3)
            h = min(y2, y4) - max(y1, y3)
            e = min(w, h)
            if e > 0:
                ans = max(ans, e * e)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        long ans = 0;
        for (int i = 0; i < bottomLeft.length; ++i) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];
            for (int j = i + 1; j < bottomLeft.length; ++j) {
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                int w = Math.min(x2, x4) - Math.max(x1, x3);
                int h = Math.min(y2, y4) - Math.max(y1, y3);
                int e = Math.min(w, h);
                if (e > 0) {
                    ans = Math.max(ans, 1L * e * e);
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
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        for (int i = 0; i < bottomLeft.size(); ++i) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];
            for (int j = i + 1; j < bottomLeft.size(); ++j) {
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                int w = min(x2, x4) - max(x1, x3);
                int h = min(y2, y4) - max(y1, y3);
                int e = min(w, h);
                if (e > 0) {
                    ans = max(ans, 1LL * e * e);
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
func largestSquareArea(bottomLeft [][]int, topRight [][]int) (ans int64) {
	for i, b1 := range bottomLeft {
		t1 := topRight[i]
		x1, y1 := b1[0], b1[1]
		x2, y2 := t1[0], t1[1]
		for j := i + 1; j < len(bottomLeft); j++ {
			x3, y3 := bottomLeft[j][0], bottomLeft[j][1]
			x4, y4 := topRight[j][0], topRight[j][1]
			w := min(x2, x4) - max(x1, x3)
			h := min(y2, y4) - max(y1, y3)
			e := min(w, h)
			if e > 0 {
				ans = max(ans, int64(e)*int64(e))
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestSquareArea(bottomLeft: number[][], topRight: number[][]): number {
    let ans = 0;
    for (let i = 0; i < bottomLeft.length; ++i) {
        const [x1, y1] = bottomLeft[i];
        const [x2, y2] = topRight[i];
        for (let j = i + 1; j < bottomLeft.length; ++j) {
            const [x3, y3] = bottomLeft[j];
            const [x4, y4] = topRight[j];
            const w = Math.min(x2, x4) - Math.max(x1, x3);
            const h = Math.min(y2, y4) - Math.max(y1, y3);
            const e = Math.min(w, h);
            if (e > 0) {
                ans = Math.max(ans, e * e);
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

<p>在二维平面上存在 <code>n</code> 个矩形。给你两个下标从 <strong>0</strong> 开始的二维整数数组 <code>bottomLeft</code> 和 <code>topRight</code>，两个数组的大小都是 <code>n x 2</code> ，其中 <code>bottomLeft[i]</code> 和 <code>topRight[i]</code> 分别代表第 <code>i</code> 个矩形的<strong> 左下角 </strong>和 <strong>右上角 </strong>坐标。</p>

<p>我们定义 <strong>向右 </strong>的方向为 x 轴正半轴（<strong>x 坐标增加</strong>），<strong>向左 </strong>的方向为 x 轴负半轴（<strong>x 坐标减少</strong>）。同样地，定义 <strong>向上 </strong>的方向为 y 轴正半轴（<strong>y 坐标增加</strong>）<strong>，向下 </strong>的方向为 y 轴负半轴（<strong>y 坐标减少</strong>）。</p>

<p>你可以选择一个区域，该区域由两个矩形的 <strong>交集</strong>&nbsp;形成。你需要找出能够放入该区域 <strong>内 </strong>的<strong> 最大 </strong>正方形面积，并选择最优解。</p>

<p>返回能够放入交集区域的正方形的 <strong>最大 </strong>可能面积，如果矩形之间不存在任何交集区域，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3047.Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/images/example12.png" style="width: 443px; height: 364px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" />
<pre>
<strong>输入：</strong>bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
<strong>输出：</strong>1
<strong>解释：</strong>边长为 1 的正方形可以放入矩形 0 和矩形 1 的交集区域，或矩形 1 和矩形 2 的交集区域。因此最大面积是边长 * 边长，即 1 * 1 = 1。
可以证明，边长更大的正方形无法放入任何交集区域。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3047.Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/images/rectanglesexample2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 445px; height: 365px;" />
<pre>
<strong>输入：</strong>bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]
<strong>输出：</strong>1
<strong>解释：</strong>边长为 1 的正方形可以放入矩形 0 和矩形 1，矩形 1 和矩形 2，或所有三个矩形的交集区域。因此最大面积是边长 * 边长，即 1 * 1 = 1。
可以证明，边长更大的正方形无法放入任何交集区域。
请注意，区域可以由多于两个矩形的交集构成。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3047.Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/images/rectanglesexample3.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 444px; height: 364px;" />
<pre>
<strong>输入：</strong>bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]
<strong>输出：</strong>0
<strong>解释：</strong>不存在相交的矩形，因此，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == bottomLeft.length == topRight.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>3</sup></code></li>
	<li><code>bottomLeft[i].length == topRight[i].length == 2</code></li>
	<li><code>1 &lt;= bottomLeft[i][0], bottomLeft[i][1] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= topRight[i][0], topRight[i][1] &lt;= 10<sup>7</sup></code></li>
	<li><code>bottomLeft[i][0] &lt; topRight[i][0]</code></li>
	<li><code>bottomLeft[i][1] &lt; topRight[i][1]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举两个矩形，其中矩形 $1$ 的左下角和右上角坐标分别为 $(x_1, y_1)$ 和 $(x_2, y_2)$，矩形 $2$ 的左下角和右上角坐标分别为 $(x_3, y_3)$ 和 $(x_4, y_4)$。

如果矩形 $1$ 和矩形 $2$ 有交集，那么交集的坐标分别为：

-   左下角横坐标是两个矩形左下角横坐标的最大值，即 $\max(x_1, x_3)$；
-   左下角纵坐标是两个矩形左下角纵坐标的最大值，即 $\max(y_1, y_3)$；
-   右上角横坐标是两个矩形右上角横坐标的最小值，即 $\min(x_2, x_4)$；
-   右上角纵坐标是两个矩形右上角纵坐标的最小值，即 $\min(y_2, y_4)$。

那么交集的宽和高分别为 $w = \min(x_2, x_4) - \max(x_1, x_3)$ 和 $h = \min(y_2, y_4) - \max(y_1, y_3)$。我们取两者的最小值作为边长，即 $e = \min(w, h)$，如果 $e > 0$，那么我们就可以得到一个正方形，其面积为 $e^2$，我们取所有正方形的最大面积即可。

时间复杂度 $O(n^2)$，其中 $n$ 是矩形的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestSquareArea(
        self, bottomLeft: List[List[int]], topRight: List[List[int]]
    ) -> int:
        ans = 0
        for ((x1, y1), (x2, y2)), ((x3, y3), (x4, y4)) in combinations(
            zip(bottomLeft, topRight), 2
        ):
            w = min(x2, x4) - max(x1, x3)
            h = min(y2, y4) - max(y1, y3)
            e = min(w, h)
            if e > 0:
                ans = max(ans, e * e)
        return ans
```

#### Java

```java
class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        long ans = 0;
        for (int i = 0; i < bottomLeft.length; ++i) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];
            for (int j = i + 1; j < bottomLeft.length; ++j) {
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                int w = Math.min(x2, x4) - Math.max(x1, x3);
                int h = Math.min(y2, y4) - Math.max(y1, y3);
                int e = Math.min(w, h);
                if (e > 0) {
                    ans = Math.max(ans, 1L * e * e);
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
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        for (int i = 0; i < bottomLeft.size(); ++i) {
            int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
            int x2 = topRight[i][0], y2 = topRight[i][1];
            for (int j = i + 1; j < bottomLeft.size(); ++j) {
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                int w = min(x2, x4) - max(x1, x3);
                int h = min(y2, y4) - max(y1, y3);
                int e = min(w, h);
                if (e > 0) {
                    ans = max(ans, 1LL * e * e);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestSquareArea(bottomLeft [][]int, topRight [][]int) (ans int64) {
	for i, b1 := range bottomLeft {
		t1 := topRight[i]
		x1, y1 := b1[0], b1[1]
		x2, y2 := t1[0], t1[1]
		for j := i + 1; j < len(bottomLeft); j++ {
			x3, y3 := bottomLeft[j][0], bottomLeft[j][1]
			x4, y4 := topRight[j][0], topRight[j][1]
			w := min(x2, x4) - max(x1, x3)
			h := min(y2, y4) - max(y1, y3)
			e := min(w, h)
			if e > 0 {
				ans = max(ans, int64(e)*int64(e))
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function largestSquareArea(bottomLeft: number[][], topRight: number[][]): number {
    let ans = 0;
    for (let i = 0; i < bottomLeft.length; ++i) {
        const [x1, y1] = bottomLeft[i];
        const [x2, y2] = topRight[i];
        for (let j = i + 1; j < bottomLeft.length; ++j) {
            const [x3, y3] = bottomLeft[j];
            const [x4, y4] = topRight[j];
            const w = Math.min(x2, x4) - Math.max(x1, x3);
            const h = Math.min(y2, y4) - Math.max(y1, y3);
            const e = Math.min(w, h);
            if (e > 0) {
                ans = Math.max(ans, e * e);
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

# [3048. 标记所有下标的最早秒数 I](https://leetcode.cn/problems/earliest-second-to-mark-indices-i){#3048}

{{< tabs "3048" >}}

{{% tab "python" %}}
```python
class Solution:
    def earliestSecondToMarkIndices(
        self, nums: List[int], changeIndices: List[int]
    ) -> int:
        def check(t: int) -> bool:
            decrement = 0
            marked = 0
            last = {i: s for s, i in enumerate(changeIndices[:t])}
            for s, i in enumerate(changeIndices[:t]):
                if last[i] == s:
                    if decrement < nums[i - 1]:
                        return False
                    decrement -= nums[i - 1]
                    marked += 1
                else:
                    decrement += 1
            return marked == len(nums)

        m = len(changeIndices)
        l = bisect_left(range(1, m + 2), True, key=check) + 1
        return -1 if l > m else l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private int[] changeIndices;

    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        this.nums = nums;
        this.changeIndices = changeIndices;
        int m = changeIndices.length;
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }

    private boolean check(int t) {
        int[] last = new int[nums.length + 1];
        for (int s = 0; s < t; ++s) {
            last[changeIndices[s]] = s;
        }
        int decrement = 0;
        int marked = 0;
        for (int s = 0; s < t; ++s) {
            int i = changeIndices[s];
            if (last[i] == s) {
                if (decrement < nums[i - 1]) {
                    return false;
                }
                decrement -= nums[i - 1];
                ++marked;
            } else {
                ++decrement;
            }
        }
        return marked == nums.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int last[n + 1];
        auto check = [&](int t) {
            memset(last, 0, sizeof(last));
            for (int s = 0; s < t; ++s) {
                last[changeIndices[s]] = s;
            }
            int decrement = 0, marked = 0;
            for (int s = 0; s < t; ++s) {
                int i = changeIndices[s];
                if (last[i] == s) {
                    if (decrement < nums[i - 1]) {
                        return false;
                    }
                    decrement -= nums[i - 1];
                    ++marked;
                } else {
                    ++decrement;
                }
            }
            return marked == n;
        };

        int m = changeIndices.size();
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func earliestSecondToMarkIndices(nums []int, changeIndices []int) int {
	n, m := len(nums), len(changeIndices)
	l := sort.Search(m+1, func(t int) bool {
		last := make([]int, n+1)
		for s, i := range changeIndices[:t] {
			last[i] = s
		}
		decrement, marked := 0, 0
		for s, i := range changeIndices[:t] {
			if last[i] == s {
				if decrement < nums[i-1] {
					return false
				}
				decrement -= nums[i-1]
				marked++
			} else {
				decrement++
			}
		}
		return marked == n
	})
	if l > m {
		return -1
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function earliestSecondToMarkIndices(nums: number[], changeIndices: number[]): number {
    const [n, m] = [nums.length, changeIndices.length];
    let [l, r] = [1, m + 1];
    const check = (t: number): boolean => {
        const last: number[] = Array(n + 1).fill(0);
        for (let s = 0; s < t; ++s) {
            last[changeIndices[s]] = s;
        }
        let [decrement, marked] = [0, 0];
        for (let s = 0; s < t; ++s) {
            const i = changeIndices[s];
            if (last[i] === s) {
                if (decrement < nums[i - 1]) {
                    return false;
                }
                decrement -= nums[i - 1];
                ++marked;
            } else {
                ++decrement;
            }
        }
        return marked === n;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > m ? -1 : l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>1</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code> 和&nbsp;<code>changeIndices</code>&nbsp;，数组的长度分别为&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;。</p>

<p>一开始，<code>nums</code>&nbsp;中所有下标都是未标记的，你的任务是标记 <code>nums</code>&nbsp;中 <strong>所有</strong>&nbsp;下标。</p>

<p>从第 <code>1</code>&nbsp;秒到第 <code>m</code>&nbsp;秒（<b>包括&nbsp;</b>第&nbsp;<code>m</code>&nbsp;秒），对于每一秒 <code>s</code>&nbsp;，你可以执行以下操作 <strong>之一</strong>&nbsp;：</p>

<ul>
	<li>选择范围&nbsp;<code>[1, n]</code>&nbsp;中的一个下标 <code>i</code>&nbsp;，并且将&nbsp;<code>nums[i]</code> <strong>减少</strong>&nbsp;<code>1</code>&nbsp;。</li>
	<li>如果&nbsp;<code>nums[changeIndices[s]]</code>&nbsp;<strong>等于</strong>&nbsp;<code>0</code>&nbsp;，<strong>标记</strong>&nbsp;下标&nbsp;<code>changeIndices[s]</code>&nbsp;。</li>
	<li>什么也不做。</li>
</ul>

<p>请你返回范围 <code>[1, m]</code>&nbsp;中的一个整数，表示最优操作下，标记&nbsp;<code>nums</code>&nbsp;中 <strong>所有</strong>&nbsp;下标的 <strong>最早秒数</strong>&nbsp;，如果无法标记所有下标，返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,2,0], changeIndices = [2,2,2,2,3,2,2,1]
<b>输出：</b>8
<b>解释：</b>这个例子中，我们总共有 8 秒。按照以下操作标记所有下标：
第 1 秒：选择下标 1 ，将 nums[1] 减少 1 。nums 变为 [1,2,0] 。
第 2 秒：选择下标 1 ，将 nums[1] 减少 1 。nums 变为 [0,2,0] 。
第 3 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [0,1,0] 。
第 4 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [0,0,0] 。
第 5 秒，标​​​​​记 changeIndices[5] ，也就是标记下标 3 ，因为 nums[3] 等于 0 。
第 6 秒，标​​​​​记 changeIndices[6] ，也就是标记下标 2 ，因为 nums[2] 等于 0 。
第 7 秒，什么也不做。
第 8 秒，标记 changeIndices[8] ，也就是标记下标 1 ，因为 nums[1] 等于 0 。
现在所有下标已被标记。
最早可以在第 8 秒标记所有下标。
所以答案是 8 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,3], changeIndices = [1,1,1,2,1,1,1]
<b>输出：</b>6
<b>解释：</b>这个例子中，我们总共有 7 秒。按照以下操作标记所有下标：
第 1 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [1,2] 。
第 2 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [1,1] 。
第 3 秒：选择下标 2 ，将 nums[2] 减少 1 。nums 变为 [1,0] 。
第 4 秒：标​​​​​记 changeIndices[4] ，也就是标记下标 2 ，因为 nums[2] 等于 0 。
第 5 秒：选择下标 1 ，将 nums[1] 减少 1 。nums 变为 [0,0] 。
第 6 秒：标​​​​​记 changeIndices[6] ，也就是标记下标 1 ，因为 nums[1] 等于 0 。
现在所有下标已被标记。
最早可以在第 6 秒标记所有下标。
所以答案是 6 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1], changeIndices = [2,2,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> 这个例子中，无法标记所有下标，因为下标 1 不在 changeIndices 中。
所以答案是 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m == changeIndices.length &lt;= 2000</code></li>
	<li><code>1 &lt;= changeIndices[i] &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果我们能够在 $t$ 秒内标记所有下标，那么我们也能在 $t' \geq t$ 秒内标记所有下标。因此，我们可以使用二分查找的方法找到最早的秒数。

我们定义二分查找的左右边界分别为 $l = 1$ 和 $r = m + 1$，其中 $m$ 是数组 `changeIndices` 的长度。对于每一个 $t = \frac{l + r}{2}$，我们检查是否能在 $t$ 秒内标记所有下标。如果能，我们将右边界移动到 $t$，否则我们将左边界移动到 $t + 1$。最终，我们判定左边界是否大于 $m$，如果是则返回 $-1$，否则返回左边界。

题目的关键在于如何判断是否能在 $t$ 秒内标记所有下标。我们可以使用一个数组 $last$ 记录每一个下标最晚需要被标记的时间，用一个变量 $decrement$ 记录当前可以减少的次数，用一个变量 $marked$ 记录已经被标记的下标的数量。

我们遍历数组 `changeIndices` 的前 $t$ 个元素，对于每一个元素 $i$，如果 $last[i] = s$，那么我们需要检查 $decrement$ 是否大于等于 $nums[i - 1]$，如果是，我们将 $decrement$ 减去 $nums[i - 1]$，并且将 $marked$ 加一；否则，我们返回 `False`。如果 $last[i] \neq s$，那么我们可以暂时不标记下标，因此将 $decrement$ 加一。最后，我们检查 $marked$ 是否等于 $n$，如果是，我们返回 `True`，否则返回 `False`。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 `nums` 和 `changeIndices` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def earliestSecondToMarkIndices(
        self, nums: List[int], changeIndices: List[int]
    ) -> int:
        def check(t: int) -> bool:
            decrement = 0
            marked = 0
            last = {i: s for s, i in enumerate(changeIndices[:t])}
            for s, i in enumerate(changeIndices[:t]):
                if last[i] == s:
                    if decrement < nums[i - 1]:
                        return False
                    decrement -= nums[i - 1]
                    marked += 1
                else:
                    decrement += 1
            return marked == len(nums)

        m = len(changeIndices)
        l = bisect_left(range(1, m + 2), True, key=check) + 1
        return -1 if l > m else l
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[] changeIndices;

    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        this.nums = nums;
        this.changeIndices = changeIndices;
        int m = changeIndices.length;
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }

    private boolean check(int t) {
        int[] last = new int[nums.length + 1];
        for (int s = 0; s < t; ++s) {
            last[changeIndices[s]] = s;
        }
        int decrement = 0;
        int marked = 0;
        for (int s = 0; s < t; ++s) {
            int i = changeIndices[s];
            if (last[i] == s) {
                if (decrement < nums[i - 1]) {
                    return false;
                }
                decrement -= nums[i - 1];
                ++marked;
            } else {
                ++decrement;
            }
        }
        return marked == nums.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int last[n + 1];
        auto check = [&](int t) {
            memset(last, 0, sizeof(last));
            for (int s = 0; s < t; ++s) {
                last[changeIndices[s]] = s;
            }
            int decrement = 0, marked = 0;
            for (int s = 0; s < t; ++s) {
                int i = changeIndices[s];
                if (last[i] == s) {
                    if (decrement < nums[i - 1]) {
                        return false;
                    }
                    decrement -= nums[i - 1];
                    ++marked;
                } else {
                    ++decrement;
                }
            }
            return marked == n;
        };

        int m = changeIndices.size();
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }
};
```

#### Go

```go
func earliestSecondToMarkIndices(nums []int, changeIndices []int) int {
	n, m := len(nums), len(changeIndices)
	l := sort.Search(m+1, func(t int) bool {
		last := make([]int, n+1)
		for s, i := range changeIndices[:t] {
			last[i] = s
		}
		decrement, marked := 0, 0
		for s, i := range changeIndices[:t] {
			if last[i] == s {
				if decrement < nums[i-1] {
					return false
				}
				decrement -= nums[i-1]
				marked++
			} else {
				decrement++
			}
		}
		return marked == n
	})
	if l > m {
		return -1
	}
	return l
}
```

#### TypeScript

```ts
function earliestSecondToMarkIndices(nums: number[], changeIndices: number[]): number {
    const [n, m] = [nums.length, changeIndices.length];
    let [l, r] = [1, m + 1];
    const check = (t: number): boolean => {
        const last: number[] = Array(n + 1).fill(0);
        for (let s = 0; s < t; ++s) {
            last[changeIndices[s]] = s;
        }
        let [decrement, marked] = [0, 0];
        for (let s = 0; s < t; ++s) {
            const i = changeIndices[s];
            if (last[i] === s) {
                if (decrement < nums[i - 1]) {
                    return false;
                }
                decrement -= nums[i - 1];
                ++marked;
            } else {
                ++decrement;
            }
        }
        return marked === n;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > m ? -1 : l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3049. 标记所有下标的最早秒数 II](https://leetcode.cn/problems/earliest-second-to-mark-indices-ii){#3049}

{{< tabs "3049" >}}

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

<p>给你两个下标从 <strong>1</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code> 和&nbsp;<code>changeIndices</code>&nbsp;，数组的长度分别为&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;。</p>

<p>一开始，<code>nums</code>&nbsp;中所有下标都是未标记的，你的任务是标记 <code>nums</code>&nbsp;中 <strong>所有</strong>&nbsp;下标。</p>

<p>从第 <code>1</code>&nbsp;秒到第 <code>m</code>&nbsp;秒（<b>包括&nbsp;</b>第&nbsp;<code>m</code>&nbsp;秒），对于每一秒 <code>s</code>&nbsp;，你可以执行以下操作 <strong>之一</strong>&nbsp;：</p>

<ul>
	<li>选择范围&nbsp;<code>[1, n]</code>&nbsp;中的一个下标 <code>i</code>&nbsp;，并且将&nbsp;<code>nums[i]</code> <strong>减少</strong>&nbsp;<code>1</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[changeIndices[s]]</code>&nbsp;设置成任意的 <strong>非负</strong>&nbsp;整数。</li>
	<li>选择范围&nbsp;<code>[1, n]</code>&nbsp;中的一个下标&nbsp;<code>i</code>&nbsp;， 满足&nbsp;<code>nums[i]</code> <strong>等于</strong> <code>0</code>, 并 <strong>标记</strong>&nbsp;下标&nbsp;<code>i</code> 。</li>
	<li>什么也不做。</li>
</ul>

<p>请你返回范围 <code>[1, m]</code>&nbsp;中的一个整数，表示最优操作下，标记&nbsp;<code>nums</code>&nbsp;中 <strong>所有</strong>&nbsp;下标的 <strong>最早秒数</strong>&nbsp;，如果无法标记所有下标，返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,3], changeIndices = [1,3,2,2,2,2,3]
<b>输出：</b>6
<b>解释：</b>这个例子中，我们总共有 7 秒。按照以下操作标记所有下标：
第 1 秒：将 nums[changeIndices[1]] 变为 0 。nums 变为 [0,2,3] 。
第 2 秒：将 nums[changeIndices[2]] 变为 0 。nums 变为 [0,2,0] 。
第 3 秒：将 nums[changeIndices[3]] 变为 0 。nums 变为 [0,0,0] 。
第 4 秒：标记下标 1 ，因为 nums[1] 等于 0 。
第 5 秒：标记下标 2 ，因为 nums[2] 等于 0 。
第 6 秒：标记下标 3 ，因为 nums[3] 等于 0 。
现在所有下标已被标记。
最早可以在第 6 秒标记所有下标。
所以答案是 6 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [0,0,1,2], changeIndices = [1,2,1,2,1,2,1,2]
<b>输出：</b>7
<b>解释：</b>这个例子中，我们总共有 8 秒。按照以下操作标记所有下标：
第 1 秒：标记下标 1 ，因为 nums[1] 等于 0 。
第 2 秒：标记下标 2 ，因为 nums[2] 等于 0 。
第 3 秒：将 nums[4] 减少 1 。nums 变为 [0,0,1,1] 。
第 4 秒：将 nums[4] 减少 1 。nums 变为 [0,0,1,0] 。
第 5 秒：将 nums[3] 减少 1 。nums 变为 [0,0,0,0] 。
第 6 秒：标记下标 3 ，因为 nums[3] 等于 0 。
第 7 秒：标记下标 4 ，因为 nums[4] 等于 0 。
现在所有下标已被标记。
最早可以在第 7 秒标记所有下标。
所以答案是 7 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3], changeIndices = [1,2,3]
<b>输出：</b>-1
<strong>解释：</strong>这个例子中，无法标记所有下标，因为我们没有足够的秒数。
所以答案是 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 5000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m == changeIndices.length &lt;= 5000</code></li>
	<li><code>1 &lt;= changeIndices[i] &lt;= n</code></li>
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
