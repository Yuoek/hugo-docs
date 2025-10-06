---
title: "3392_CountSubarraysofLengthThreeWithaCondition"
date: 2025-10-06T00:42:37+08:00
weight: 3392
tags: [Array]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [3392. Count Subarrays of Length Three With a Condition](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition)

[中文文档](/solution/3300-3399/3392.Count%20Subarrays%20of%20Length%20Three%20With%20a%20Condition/README.md)

## Description

<!-- description:start -->

<p>Given an integer array <code>nums</code>, return the number of <span data-keyword="subarray-nonempty">subarrays</span> of length 3 such that the sum of the first and third numbers equals <em>exactly</em> half of the second number.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,4,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>Only the subarray <code>[1,4,1]</code> contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><code>[1,1,1]</code> is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code><font face="monospace">-100 &lt;= nums[i] &lt;= 100</font></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Single Pass

We traverse each subarray of length $3$ in the array $\textit{nums}$ and check if twice the sum of the first and third numbers equals the second number. If it does, we increment the answer by $1$.

After traversing, we return the answer.

The time complexity is $O(n)$, where $n$ is the length of the array $\textit{nums}$. The space complexity is $O(1)$.

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
    def countSubarrays(self, nums: List[int]) -> int:
        return sum(
            (nums[i - 1] + nums[i + 1]) * 2 == nums[i] for i in range(1, len(nums) - 1)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubarrays(int[] nums) {
        int ans = 0;
        for (int i = 1; i + 1 < nums.length; ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++ans;
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
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i + 1 < nums.size(); ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int) (ans int) {
	for i := 1; i+1 < len(nums); i++ {
		if (nums[i-1]+nums[i+1])*2 == nums[i] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[]): number {
    let ans: number = 0;
    for (let i = 1; i + 1 < nums.length; ++i) {
        if ((nums[i - 1] + nums[i + 1]) * 2 === nums[i]) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 1..nums.len() - 1 {
            if (nums[i - 1] + nums[i + 1]) * 2 == nums[i] {
                ans += 1;
            }
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
    def countSubarrays(self, nums: List[int]) -> int:
        return sum(
            (nums[i - 1] + nums[i + 1]) * 2 == nums[i] for i in range(1, len(nums) - 1)
        )
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countSubarrays(int[] nums) {
        int ans = 0;
        for (int i = 1; i + 1 < nums.length; ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++ans;
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
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i + 1 < nums.size(); ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}