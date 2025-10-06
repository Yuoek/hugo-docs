---
title: "3423_MaximumDifferenceBetweenAdjacentElementsinaCircularArray"
date: 2025-10-06T00:42:37+08:00
weight: 3423
tags: [数组]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3423. 循环数组中相邻元素的最大差值](https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array)

[English Version](../en/3423-23/3423_MaximumDifferenceBetweenAdjacentElementsinaCircularArray)

## 题目描述

<!-- description:start -->

<p>给你一个 <strong>循环</strong>&nbsp;数组&nbsp;<code>nums</code>&nbsp;，请你找出相邻元素之间的&nbsp;<strong>最大</strong>&nbsp;绝对差值。</p>

<p><b>注意：</b>一个循环数组中，第一个元素和最后一个元素是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,4]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>由于&nbsp;<code>nums</code>&nbsp;是循环的，<code>nums[0]</code> 和&nbsp;<code>nums[2]</code>&nbsp;是相邻的，它们之间的绝对差值是最大值&nbsp;<code>|4 - 1| = 3</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [-5,-10,-5]</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><b>解释：</b></p>

<p>相邻元素&nbsp;<code>nums[0]</code> 和&nbsp;<code>nums[1]</code>&nbsp;之间的绝对差值为最大值&nbsp;<code>|-5 - (-10)| = 5</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历数组 $\textit{nums}$，计算相邻元素之间的绝对差值，并维护最大的绝对差值，最后与首尾元素之间的绝对差值比较，取最大值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        return max(abs(a - b) for a, b in pairwise(nums + [nums[0]]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int ans = Math.abs(nums[0] - nums[n - 1]);
        for (int i = 1; i < n; ++i) {
            ans = Math.max(ans, Math.abs(nums[i] - nums[i - 1]));
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
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0] - nums.back());
        for (int i = 1; i < nums.size(); ++i) {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAdjacentDistance(nums []int) int {
	ans := abs(nums[0] - nums[len(nums)-1])
	for i := 1; i < len(nums); i++ {
		ans = max(ans, abs(nums[i]-nums[i-1]))
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
function maxAdjacentDistance(nums: number[]): number {
    const n = nums.length;
    let ans = Math.abs(nums[0] - nums[n - 1]);
    for (let i = 1; i < n; ++i) {
        ans = Math.max(ans, Math.abs(nums[i] - nums[i - 1]));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_adjacent_distance(nums: Vec<i32>) -> i32 {
        nums.iter()
            .zip(nums.iter().cycle().skip(1))
            .take(nums.len())
            .map(|(a, b)| (*a - *b).abs())
            .max()
            .unwrap_or(0)
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxAdjacentDistance(int[] nums) {
        int n = nums.Length;
        int ans = Math.Abs(nums[0] - nums[n - 1]);
        for (int i = 1; i < n; ++i) {
            ans = Math.Max(ans, Math.Abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        return max(abs(a - b) for a, b in pairwise(nums + [nums[0]]))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int ans = Math.abs(nums[0] - nums[n - 1]);
        for (int i = 1; i < n; ++i) {
            ans = Math.max(ans, Math.abs(nums[i] - nums[i - 1]));
        }
        return ans;
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
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0] - nums.back());
        for (int i = 1; i < nums.size(); ++i) {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}