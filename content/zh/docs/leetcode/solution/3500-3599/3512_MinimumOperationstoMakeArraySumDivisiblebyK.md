---
title: "3512_MinimumOperationstoMakeArraySumDivisiblebyK"
date: 2025-10-06T00:42:37+08:00
weight: 3512
tags: [数组, 数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3512. 使数组和能被 K 整除的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-array-sum-divisible-by-k)

[English Version](../en/3512-12/3512_MinimumOperationstoMakeArraySumDivisiblebyK)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code>。你可以执行以下操作任意次：</p>

<ul>
	<li>选择一个下标&nbsp;<code>i</code>，并将 <code>nums[i]</code> 替换为 <code>nums[i] - 1</code>。</li>
</ul>

<p>返回使数组元素之和能被 <code>k</code> 整除所需的<strong>最小</strong>操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,9,7], k = 5</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>对 <code>nums[1] = 9</code> 执行 4 次操作。现在 <code>nums = [3, 5, 7]</code>。</li>
	<li>数组之和为 15，可以被 5 整除。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,1,3], k = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>数组之和为 8，已经可以被 4 整除。因此不需要操作。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,2], k = 6</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>对 <code>nums[0] = 3</code> 执行 3 次操作，对 <code>nums[1] = 2</code> 执行 2 次操作。现在 <code>nums = [0, 0]</code>。</li>
	<li>数组之和为 0，可以被 6 整除。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：求和取模

题目实际上是求数组元素之和对 $k$ 取模的结果。因此，我们只需要遍历数组，计算出所有元素之和，然后对 $k$ 取模，最后返回这个结果即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

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
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) % k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums, int k) {
        return Arrays.stream(nums).sum() % k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return reduce(nums.begin(), nums.end(), 0) % k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, k int) (ans int) {
	for _, x := range nums {
		ans = (ans + x) % k
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], k: number): number {
    return nums.reduce((acc, x) => acc + x, 0) % k;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) % k
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minOperations(int[] nums, int k) {
        return Arrays.stream(nums).sum() % k;
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
    int minOperations(vector<int>& nums, int k) {
        return reduce(nums.begin(), nums.end(), 0) % k;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}