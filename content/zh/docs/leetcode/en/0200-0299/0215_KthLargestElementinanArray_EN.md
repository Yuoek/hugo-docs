---
title: "0215_KthLargestElementinanArray"
date: 2025-10-06T00:42:37+08:00
weight: 0215
tags: [Array, Divide and Conquer, Quickselect, Sorting, Heap (Priority Queue)]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array)

[中文文档](/solution/0200-0299/0215.Kth%20Largest%20Element%20in%20an%20Array/README.md)

## Description

<!-- description:start -->

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>largest element in the array</em>.</p>

<p>Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>

<p>Can you solve it without sorting?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1,5,6,4], k = 2
<strong>Output:</strong> 5
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3,1,2,4,5,5,6], k = 4
<strong>Output:</strong> 4
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Quick Select

Quick Select is an algorithm for finding the $k^{th}$ largest or smallest element in an unsorted array. Its basic idea is to select a pivot element each time, dividing the array into two parts: one part contains elements smaller than the pivot, and the other part contains elements larger than the pivot. Then, based on the position of the pivot, it decides whether to continue the search on the left or right side until the $k^{th}$ largest element is found.

The time complexity is $O(n)$, and the space complexity is $O(\log n)$. Here, $n$ is the length of the array $\textit{nums}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Priority Queue (Min Heap)

We can maintain a min heap $\textit{minQ}$ of size $k$, and then iterate through the array $\textit{nums}$, adding each element to the min heap. When the size of the min heap exceeds $k$, we pop the top element of the heap. This way, the final $k$ elements in the min heap are the $k$ largest elements in the array, and the top element of the heap is the $k^{th}$ largest element.

The time complexity is $O(n\log k)$, and the space complexity is $O(k)$. Here, $n$ is the length of the array $\textit{nums}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3: Counting Sort

We can use the idea of counting sort, counting the occurrence of each element in the array $\textit{nums}$ and recording it in a hash table $\textit{cnt}$. Then, we iterate over the elements $i$ from largest to smallest, subtracting the occurrence count $\textit{cnt}[i]$ each time, until $k$ is less than or equal to $0$. At this point, the element $i$ is the $k^{th}$ largest element in the array.

The time complexity is $O(n + m)$, and the space complexity is $O(n)$. Here, $n$ is the length of the array $\textit{nums}$, and $m$ is the maximum value among the elements in $\textit{nums}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        for i in count(max(cnt), -1):
            k -= cnt[i]
            if k <= 0:
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>(nums.length);
        int m = Integer.MIN_VALUE;
        for (int x : nums) {
            m = Math.max(m, x);
            cnt.merge(x, 1, Integer::sum);
        }
        for (int i = m;; --i) {
            k -= cnt.getOrDefault(i, 0);
            if (k <= 0) {
                return i;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int m = INT_MIN;
        for (int x : nums) {
            ++cnt[x];
            m = max(m, x);
        }
        for (int i = m;; --i) {
            k -= cnt[i];
            if (k <= 0) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthLargest(nums []int, k int) int {
	cnt := map[int]int{}
	m := -(1 << 30)
	for _, x := range nums {
		cnt[x]++
		m = max(m, x)
	}
	for i := m; ; i-- {
		k -= cnt[i]
		if k <= 0 {
			return i
		}
	}

}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findKthLargest(nums: number[], k: number): number {
    const cnt: Record<number, number> = {};
    for (const x of nums) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const m = Math.max(...nums);
    for (let i = m; ; --i) {
        k -= cnt[i] || 0;
        if (k <= 0) {
            return i;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        let mut m = i32::MIN;

        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
            if x > m {
                m = x;
            }
        }

        let mut k = k;
        for i in (i32::MIN..=m).rev() {
            if let Some(&count) = cnt.get(&i) {
                k -= count;
                if k <= 0 {
                    return i;
                }
            }
        }

        unreachable!();
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        for i in count(max(cnt), -1):
            k -= cnt[i]
            if k <= 0:
                return i
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>(nums.length);
        int m = Integer.MIN_VALUE;
        for (int x : nums) {
            m = Math.max(m, x);
            cnt.merge(x, 1, Integer::sum);
        }
        for (int i = m;; --i) {
            k -= cnt.getOrDefault(i, 0);
            if (k <= 0) {
                return i;
            }
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
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int m = INT_MIN;
        for (int x : nums) {
            ++cnt[x];
            m = max(m, x);
        }
        for (int i = m;; --i) {
            k -= cnt[i];
            if (k <= 0) {
                return i;
            }
        }
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}