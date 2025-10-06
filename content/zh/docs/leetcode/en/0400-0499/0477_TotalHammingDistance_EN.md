---
title: "0477_TotalHammingDistance"
date: 2025-10-06T00:42:37+08:00
weight: 0477
tags: [Bit Manipulation, Array, Math]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [477. Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance)

[中文文档](/solution/0400-0499/0477.Total%20Hamming%20Distance/README.md)

## Description

<!-- description:start -->

<p>The <a href="https://en.wikipedia.org/wiki/Hamming_distance" target="_blank">Hamming distance</a> between two integers is the number of positions at which the corresponding bits are different.</p>

<p>Given an integer array <code>nums</code>, return <em>the sum of <strong>Hamming distances</strong> between all the pairs of the integers in</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,14,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,14,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>The answer for the given input will fit in a <strong>32-bit</strong> integer.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Bit Manipulation

We enumerate each bit in the range $[0, 31]$. For the current enumerated bit $i$, we count the number of numbers where the $i$-th bit is $1$, denoted as $a$. Therefore, the number of numbers where the $i$-th bit is $0$ is $b = n - a$, where $n$ is the length of the array. In this way, the sum of the Hamming distance on the $i$-th bit is $a \times b$. We add the Hamming distances of all bits to get the answer.

The time complexity is $O(n \times \log M)$, where $n$ and $M$ are the length of the array and the maximum value in the array, respectively. The space complexity is $O(1)$.

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
    def totalHammingDistance(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(32):
            a = sum(x >> i & 1 for x in nums)
            b = n - a
            ans += a * b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalHammingDistance(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += (x >> i & 1);
            }
            int b = n - a;
            ans += a * b;
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
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += x >> i & 1;
            }
            int b = n - a;
            ans += a * b;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalHammingDistance(nums []int) (ans int) {
	for i := 0; i < 32; i++ {
		a := 0
		for _, x := range nums {
			a += x >> i & 1
		}
		b := len(nums) - a
		ans += a * b
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function totalHammingDistance(nums: number[]): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        const a = nums.filter(x => (x >> i) & 1).length;
        const b = nums.length - a;
        ans += a * b;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 0..32 {
            let mut a = 0;
            for &x in nums.iter() {
                a += (x >> i) & 1;
            }
            let b = (nums.len() as i32) - a;
            ans += a * b;
        }
        ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(32):
            a = sum(x >> i & 1 for x in nums)
            b = n - a
            ans += a * b
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int totalHammingDistance(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += (x >> i & 1);
            }
            int b = n - a;
            ans += a * b;
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
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += x >> i & 1;
            }
            int b = n - a;
            ans += a * b;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}