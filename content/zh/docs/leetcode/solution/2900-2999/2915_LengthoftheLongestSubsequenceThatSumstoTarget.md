---
title: "2915_LengthoftheLongestSubsequenceThatSumstoTarget"
date: 2025-10-06T00:42:37+08:00
weight: 2915
tags: [数组, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2915. 和为目标值的最长子序列的长度](https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target)

[English Version](../en/2915-15/2915_LengthoftheLongestSubsequenceThatSumstoTarget)

## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;。</p>

<p>返回和为 <code>target</code>&nbsp;的 <code>nums</code>&nbsp;子序列中，子序列&nbsp;<strong>长度的最大值&nbsp;</strong>。如果不存在和为 <code>target</code>&nbsp;的子序列，返回 <code>-1</code>&nbsp;。</p>

<p><strong>子序列</strong> 指的是从原数组中删除一些或者不删除任何元素后，剩余元素保持原来的顺序构成的数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5], target = 9
<b>输出：</b>3
<b>解释：</b>总共有 3 个子序列的和为 9 ：[4,5] ，[1,3,5] 和 [2,3,4] 。最长的子序列是 [1,3,5] 和 [2,3,4] 。所以答案为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,1,3,2,1,5], target = 7
<b>输出：</b>4
<strong>解释：</strong>总共有 5 个子序列的和为 7 ：[4,3] ，[4,1,2] ，[4,2,1] ，[1,1,5] 和 [1,3,2,1] 。最长子序列为 [1,3,2,1] 。所以答案为 4 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,5,4,5], target = 3
<b>输出：</b>-1
<b>解释：</b>无法得到和为 3 的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 个数中选取若干个数，使得这若干个数的和恰好为 $j$ 的最长子序列的长度。初始时 $f[0][0]=0$，其余位置均为 $-\infty$。

对于 $f[i][j]$，我们考虑第 $i$ 个数 $x$，如果不选取 $x$，那么 $f[i][j]=f[i-1][j]$；如果选取 $x$，那么 $f[i][j]=f[i-1][j-x]+1$，其中 $j\ge x$。因此我们有状态转移方程：

$$
f[i][j]=\max\{f[i-1][j],f[i-1][j-x]+1\}
$$

最终答案为 $f[n][target]$，如果 $f[n][target]\le0$，则不存在和为 $target$ 的子序列，返回 $-1$。

时间复杂度 $O(n\times target)$，空间复杂度 $O(n\times target)$。其中 $n$ 为数组长度，而 $target$ 为目标值。

我们注意到 $f[i][j]$ 的状态只与 $f[i-1][\cdot]$ 有关，因此我们可以优化掉第一维，将空间复杂度优化到 $O(target)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        f = [0] + [-inf] * target
        for x in nums:
            for j in range(target, x - 1, -1):
                f[j] = max(f[j], f[j - x] + 1)
        return -1 if f[-1] <= 0 else f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int[] f = new int[target + 1];
        final int inf = 1 << 30;
        Arrays.fill(f, -inf);
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = Math.max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int f[target + 1];
        memset(f, -0x3f, sizeof(f));
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lengthOfLongestSubsequence(nums []int, target int) int {
	f := make([]int, target+1)
	for i := range f {
		f[i] = -(1 << 30)
	}
	f[0] = 0
	for _, x := range nums {
		for j := target; j >= x; j-- {
			f[j] = max(f[j], f[j-x]+1)
		}
	}
	if f[target] <= 0 {
		return -1
	}
	return f[target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lengthOfLongestSubsequence(nums: number[], target: number): number {
    const f: number[] = Array(target + 1).fill(-Infinity);
    f[0] = 0;
    for (const x of nums) {
        for (let j = target; j >= x; --j) {
            f[j] = Math.max(f[j], f[j - x] + 1);
        }
    }
    return f[target] <= 0 ? -1 : f[target];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        f = [0] + [-inf] * target
        for x in nums:
            for j in range(target, x - 1, -1):
                f[j] = max(f[j], f[j - x] + 1)
        return -1 if f[-1] <= 0 else f[-1]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int[] f = new int[target + 1];
        final int inf = 1 << 30;
        Arrays.fill(f, -inf);
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = Math.max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int f[target + 1];
        memset(f, -0x3f, sizeof(f));
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}