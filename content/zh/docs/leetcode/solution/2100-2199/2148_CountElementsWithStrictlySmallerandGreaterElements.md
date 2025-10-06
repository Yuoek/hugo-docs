---
title: "2148_CountElementsWithStrictlySmallerandGreaterElements"
date: 2025-10-06T00:42:37+08:00
weight: 2148
tags: [数组, 计数, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2148. 元素计数](https://leetcode.cn/problems/count-elements-with-strictly-smaller-and-greater-elements)

[English Version](../en/2148-48/2148_CountElementsWithStrictlySmallerandGreaterElements)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，统计并返回在 <code>nums</code> 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [11,7,2,15]
<strong>输出：</strong>2
<strong>解释：</strong>元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,3,3,90]
<strong>输出：</strong>2
<strong>解释：</strong>元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：求最小值和最大值

根据题目描述，我们可以先求出数组 $\textit{nums}$ 的最小值 $\textit{mi}$ 和最大值 $\textit{mx}$，然后遍历数组 $\textit{nums}$，统计满足 $\textit{mi} < x < \textit{mx}$ 的元素个数即可。

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
    def countElements(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        return sum(mi < x < mx for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countElements(int[] nums) {
        int mi = Arrays.stream(nums).min().getAsInt();
        int mx = Arrays.stream(nums).max().getAsInt();
        int ans = 0;
        for (int x : nums) {
            if (mi < x && x < mx) {
                ans++;
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
    int countElements(vector<int>& nums) {
        auto [mi, mx] = ranges::minmax_element(nums);
        return ranges::count_if(nums, [mi, mx](int x) { return *mi < x && x < *mx; });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countElements(nums []int) (ans int) {
	mi := slices.Min(nums)
	mx := slices.Max(nums)
	for _, x := range nums {
		if mi < x && x < mx {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countElements(nums: number[]): number {
    const mi = Math.min(...nums);
    const mx = Math.max(...nums);
    return nums.filter(x => mi < x && x < mx).length;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countElements(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        return sum(mi < x < mx for x in nums)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countElements(int[] nums) {
        int mi = Arrays.stream(nums).min().getAsInt();
        int mx = Arrays.stream(nums).max().getAsInt();
        int ans = 0;
        for (int x : nums) {
            if (mi < x && x < mx) {
                ans++;
            }
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
    int countElements(vector<int>& nums) {
        auto [mi, mx] = ranges::minmax_element(nums);
        return ranges::count_if(nums, [mi, mx](int x) { return *mi < x && x < *mx; });
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}