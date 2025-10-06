---
title: "0540_SingleElementinaSortedArray"
date: 2025-10-06T00:42:37+08:00
weight: 0540
tags: [数组, 二分查找]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [540. 有序数组中的单一元素](https://leetcode.cn/problems/single-element-in-a-sorted-array)

[English Version](../en/0540-40/0540_SingleElementinaSortedArray)

## 题目描述

<!-- description:start -->

<p>给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。</p>

<p>请你找出并返回只出现一次的那个数。</p>

<p>你设计的解决方案必须满足 <code>O(log n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums =  [3,3,7,7,10,11,11]
<strong>输出:</strong> 10
</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：二分查找

题目给定的数组 $\textit{nums}$ 是有序的，且要求在 $\textit{O}(\log n)$ 时间找到只出现一次的元素，因此我们考虑使用二分查找解决。

我们定义二分查找的左边界 $\textit{l} = 0$，右边界 $\textit{r} = n - 1$，其中 $n$ 是数组的长度。

在每一步中，我们取中间位置 $\textit{mid} = (l + r) / 2$，如果下标 $\textit{mid}$ 为偶数，那么我们应该将 $\textit{nums}[\textit{mid}]$ 与 $\textit{nums}[\textit{mid} + 1]$ 进行比较；如果下标 $\textit{mid}$ 为奇数，那么我们应该将 $\textit{nums}[\textit{mid}]$ 与 $\textit{nums}[\textit{mid} - 1]$ 进行比较。因此，我们可以统一将 $\textit{nums}[\textit{mid}]$ 与 $\textit{nums}[\textit{mid} \oplus 1]$ 进行比较，其中 $\oplus$ 表示异或运算。

如果 $\textit{nums}[\textit{mid}] \neq \textit{nums}[\textit{mid} \oplus 1]$，那么答案在 $[\textit{l}, \textit{mid}]$ 中，我们令 $\textit{r} = \textit{mid}$；如果 $\textit{nums}[\textit{mid}] = \textit{nums}[\textit{mid} \oplus 1]$，那么答案在 $[\textit{mid} + 1, \textit{r}]$ 中，我们令 $\textit{l} = \textit{mid} + 1$。继续二分查找，直到 $\textit{l} = \textit{r}$，此时 $\textit{nums}[\textit{l}]$ 即为只出现一次的元素。

时间复杂度 $\textit{O}(\log n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $\textit{O}(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] != nums[mid ^ 1]:
                r = mid
            else:
                l = mid + 1
        return nums[l]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func singleNonDuplicate(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] != nums[mid^1] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return nums[l]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function singleNonDuplicate(nums: number[]): number {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] !== nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] != nums[mid ^ 1] {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        nums[l]
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] != nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] != nums[mid ^ 1]:
                r = mid
            else:
                l = mid + 1
        return nums[l]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] != nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}