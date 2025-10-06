---
title: "0324_WiggleSortII"
date: 2025-10-06T00:42:37+08:00
weight: 0324
tags: [Greedy, Array, Divide and Conquer, Quickselect, Sorting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii)

[中文文档](/solution/0300-0399/0324.Wiggle%20Sort%20II/README.md)

## Description

<!-- description:start -->

<p>Given an integer array <code>nums</code>, reorder it such that <code>nums[0] &lt; nums[1] &gt; nums[2] &lt; nums[3]...</code>.</p>

<p>You may assume the input array always has a valid answer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,1,1,6,4]
<strong>Output:</strong> [1,6,1,5,1,4]
<strong>Explanation:</strong> [1,4,1,5,1,6] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2,2,3,1]
<strong>Output:</strong> [2,3,1,3,1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5000</code></li>
	<li>It is guaranteed that there will be an answer for the given input <code>nums</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow Up:</strong> Can you do it in <code>O(n)</code> time and/or <strong>in-place</strong> with <code>O(1)</code> extra space?

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

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