---
title: "0324_WiggleSortII"
date: 2025-10-06T00:42:37+08:00
weight: 0324
tags: [贪心, 数组, 分治, 快速选择, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [324. 摆动排序 II](https://leetcode.cn/problems/wiggle-sort-ii)

[English Version](../en/0324-24/0324_WiggleSortII)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，将它重新排列成 <code>nums[0] < nums[1] > nums[2] < nums[3]...</code> 的顺序。</p>

<p>你可以假设所有输入数组都可以得到满足题目要求的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,1,1,6,4]
<strong>输出：</strong>[1,6,1,5,1,4]
<strong>解释：</strong>[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,2,3,1]
<strong>输出：</strong>[2,3,1,3,1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>0 <= nums[i] <= 5000</code></li>
	<li>题目数据保证，对于给定的输入 <code>nums</code> ，总能产生满足题目要求的结果</li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？</p>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：排序

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：桶排序

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        bucket = [0] * 5001
        for v in nums:
            bucket[v] += 1
        n = len(nums)
        j = 5000
        for i in range(1, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
        for i in range(0, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void wiggleSort(int[] nums) {
        int[] bucket = new int[5001];
        for (int v : nums) {
            ++bucket[v];
        }
        int n = nums.length;
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> bucket(5001);
        for (int& v : nums) ++bucket[v];
        int n = nums.size();
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wiggleSort(nums []int) {
	bucket := make([]int, 5001)
	for _, v := range nums {
		bucket[v]++
	}
	n, j := len(nums), 5000
	for i := 1; i < n; i += 2 {
		for bucket[j] == 0 {
			j--
		}
		nums[i] = j
		bucket[j]--
	}
	for i := 0; i < n; i += 2 {
		for bucket[j] == 0 {
			j--
		}
		nums[i] = j
		bucket[j]--
	}
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function (nums) {
    let bucket = new Array(5001).fill(0);
    for (const v of nums) {
        bucket[v]++;
    }
    const n = nums.length;
    let j = 5000;
    for (let i = 1; i < n; i += 2) {
        while (bucket[j] == 0) {
            --j;
        }
        nums[i] = j;
        --bucket[j];
    }
    for (let i = 0; i < n; i += 2) {
        while (bucket[j] == 0) {
            --j;
        }
        nums[i] = j;
        --bucket[j];
    }
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        bucket = [0] * 5001
        for v in nums:
            bucket[v] += 1
        n = len(nums)
        j = 5000
        for i in range(1, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
        for i in range(0, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public void wiggleSort(int[] nums) {
        int[] bucket = new int[5001];
        for (int v : nums) {
            ++bucket[v];
        }
        int n = nums.length;
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
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
    void wiggleSort(vector<int>& nums) {
        vector<int> bucket(5001);
        for (int& v : nums) ++bucket[v];
        int n = nums.size();
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}