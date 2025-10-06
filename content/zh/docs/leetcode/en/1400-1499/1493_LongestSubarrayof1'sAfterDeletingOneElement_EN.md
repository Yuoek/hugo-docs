---
title: "1493_LongestSubarrayof1'sAfterDeletingOneElement"
date: 2025-10-06T00:42:37+08:00
weight: 1493
tags: [Array, Dynamic Programming, Sliding Window]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1493. Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element)

[中文文档](/solution/1400-1499/1493.Longest%20Subarray%20of%201%27s%20After%20Deleting%20One%20Element/README.md)

## Description

<!-- description:start -->

<p>Given a binary array <code>nums</code>, you should delete one element from it.</p>

<p>Return <em>the size of the longest non-empty subarray containing only </em><code>1</code><em>&#39;s in the resulting array</em>. Return <code>0</code> if there is no such subarray.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1&#39;s.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,1,1,0,1,1,0,1]
<strong>Output:</strong> 5
<strong>Explanation:</strong> After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1&#39;s is [1,1,1,1,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You must delete one element.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Enumeration

We can enumerate each position $i$ to be deleted, then calculate the number of consecutive 1s on the left and right, and finally take the maximum value.

Specifically, we use two arrays $left$ and $right$ of length $n+1$, where $left[i]$ represents the number of consecutive 1s ending with $nums[i-1]$, and $right[i]$ represents the number of consecutive 1s starting with $nums[i]$.

The final answer is $\max_{0 \leq i < n} \{left[i] + right[i+1]\}$.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Where $n$ is the length of the array $nums$.

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

### Solution 2: Two Pointers

The problem is actually asking us to find the longest subarray that contains at most one $0$. The remaining length after deleting one element from this subarray is the answer.

Therefore, we can use two pointers $j$ and $i$ to point to the left and right boundaries of the subarray, initially $j = 0$, $i = 0$. In addition, we use a variable $cnt$ to record the number of $0$s in the subarray.

Next, we move the right pointer $i$. If $nums[i] = 0$, then $cnt$ is incremented by $1$. When $cnt > 1$, we need to move the left pointer $j$ until $cnt \leq 1$. Then, we update the answer, i.e., $ans = \max(ans, i - j)$. Continue to move the right pointer $i$ until $i$ reaches the end of the array.

The time complexity is $O(n)$, where $n$ is the length of the array $nums$. The space complexity is $O(1)$.

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

### Solution 3: Two Pointers (Optimization)

In Solution 2, we move the left pointer in a loop until $cnt \leq 1$. Since the problem asks for the longest subarray, it means we don't need to reduce the length of the subarray. Therefore, if $\textit{cnt} \gt 1$, we only move the left pointer once, and the right pointer continues to move to the right. This ensures that the length of the subarray does not decrease.

Finally, the answer we return is $n - l - 1$, where $l$ is the position of the left pointer.

The time complexity is $O(n)$, where $n$ is the length of the array $nums$. The space complexity is $O(1)$.

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
    def longestSubarray(self, nums: List[int]) -> int:
        cnt = l = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > 1:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubarray(int[] nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubarray(nums []int) int {
	cnt, l := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > 1 {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubarray(nums: number[]): number {
    let [cnt, l] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l - 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let mut l = 0;

        for &x in &nums {
            cnt += x ^ 1;
            if cnt > 1 {
                cnt -= nums[l] ^ 1;
                l += 1;
            }
        }

        (nums.len() - l - 1) as i32
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        cnt = l = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > 1:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l - 1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestSubarray(int[] nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l - 1;
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
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l - 1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}