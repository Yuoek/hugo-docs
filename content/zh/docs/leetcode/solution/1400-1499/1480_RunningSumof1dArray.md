---
title: "1480_RunningSumof1dArray"
date: 2025-10-06T00:42:37+08:00
weight: 1480
tags: [数组, 前缀和]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1480. 一维数组的动态和](https://leetcode.cn/problems/running-sum-of-1d-array)

[English Version](../en/1480-80/1480_RunningSumof1dArray)

## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> 。数组「动态和」的计算公式为：<code>runningSum[i] = sum(nums[0]&hellip;nums[i])</code> 。</p>

<p>请返回 <code>nums</code> 的动态和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[1,3,6,10]
<strong>解释：</strong>动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1,1]
<strong>输出：</strong>[1,2,3,4,5]
<strong>解释：</strong>动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,1,2,10,1]
<strong>输出：</strong>[3,4,6,16,17]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10^6&nbsp;&lt;= nums[i] &lt;=&nbsp;10^6</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：前缀和

我们直接遍历数组，对于当前元素 $nums[i]$，我们将其与前缀和 $nums[i-1]$ 相加，即可得到当前元素的前缀和 $nums[i]$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



#### PHP



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return list(accumulate(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func runningSum(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function runningSum(nums: number[]): number[] {
    for (let i = 1; i < nums.length; ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] RunningSum(int[] nums) {
        for (int i = 1; i < nums.Length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function runningSum($nums) {
        for ($i = 1; $i < count($nums); $i++) {
            $nums[$i] += $nums[$i - 1];
        }
        return $nums;
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return list(accumulate(nums))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] runningSum(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
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
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        return nums;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}