---
title: "2644_FindtheMaximumDivisibilityScore"
date: 2025-10-06T00:42:37+08:00
weight: 2644
tags: [Array]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2644. Find the Maximum Divisibility Score](https://leetcode.com/problems/find-the-maximum-divisibility-score)

[中文文档](/solution/2600-2699/2644.Find%20the%20Maximum%20Divisibility%20Score/README.md)

## Description

<!-- description:start -->

<p>You are given two integer arrays <code>nums</code> and <code>divisors</code>.</p>

<p>The <strong>divisibility score</strong> of <code>divisors[i]</code> is the number of indices <code>j</code> such that <code>nums[j]</code> is divisible by <code>divisors[i]</code>.</p>

<p>Return the integer <code>divisors[i]</code> with the <strong>maximum</strong> divisibility score. If multiple integers have the maximum score, return the smallest one.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,9,15,50], divisors = [5,3,7,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The divisibility score of <code>divisors[0]</code> is 2 since <code>nums[2]</code> and <code>nums[3]</code> are divisible by 5.</p>

<p>The divisibility score of <code>divisors[1]</code> is 2 since <code>nums[1]</code> and <code>nums[2]</code> are divisible by 3.</p>

<p>The divisibility score of <code>divisors[2]</code> is 0 since none of the numbers in <code>nums</code> is divisible by 7.</p>

<p>The divisibility score of <code>divisors[3]</code> is 2 since <code>nums[0]</code> and <code>nums[3]</code> are divisible by 2.</p>

<p>As <code>divisors[0]</code>,&nbsp;<code>divisors[1]</code>, and <code>divisors[3]</code> have the same divisibility score, we return the smaller one which is <code>divisors[3]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,7,9,3,9], divisors = [5,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The divisibility score of <code>divisors[0]</code> is 0 since none of numbers in <code>nums</code> is divisible by 5.</p>

<p>The divisibility score of <code>divisors[1]</code> is 1 since only <code>nums[0]</code> is divisible by 2.</p>

<p>The divisibility score of <code>divisors[2]</code> is 3 since <code>nums[2]</code>, <code>nums[3]</code> and <code>nums[4]</code> are divisible by 3.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [20,14,21,10], divisors = [10,16,20]</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>The divisibility score of <code>divisors[0]</code> is 2 since <code>nums[0]</code> and <code>nums[3]</code> are divisible by 10.</p>

<p>The divisibility score of <code>divisors[1]</code> is 0 since none of the numbers in <code>nums</code> is divisible by 16.</p>

<p>The divisibility score of <code>divisors[2]</code> is 1 since <code>nums[0]</code> is divisible by 20.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, divisors.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], divisors[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Enumeration

We can enumerate each element $div$ in $divisors$, and calculate how many elements in $nums$ can be divided by $div$, denoted as $cnt$.

-   If $cnt$ is greater than the current maximum divisibility score $mx$, then update $mx = cnt$, and update $ans = div$.
-   If $cnt$ equals $mx$ and $div$ is less than $ans$, then update $ans = div$.

Finally, return $ans$.

The time complexity is $O(m \times n)$, where $m$ and $n$ are the lengths of $nums$ and $divisors$ respectively. The space complexity is $O(1)$.

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
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        ans, mx = divisors[0], 0
        for div in divisors:
            cnt = sum(x % div == 0 for x in nums)
            if mx < cnt:
                mx, ans = cnt, div
            elif mx == cnt and ans > div:
                ans = div
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                if (x % div == 0) {
                    ++cnt;
                }
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = Math.min(ans, div);
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                cnt += x % div == 0;
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = min(ans, div);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDivScore(nums []int, divisors []int) int {
	ans, mx := divisors[0], 0
	for _, div := range divisors {
		cnt := 0
		for _, x := range nums {
			if x%div == 0 {
				cnt++
			}
		}
		if mx < cnt {
			ans, mx = div, cnt
		} else if mx == cnt && ans > div {
			ans = div
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDivScore(nums: number[], divisors: number[]): number {
    let ans: number = divisors[0];
    let mx: number = 0;
    for (const div of divisors) {
        const cnt = nums.reduce((a, b) => a + (b % div == 0 ? 1 : 0), 0);
        if (mx < cnt) {
            mx = cnt;
            ans = div;
        } else if (mx === cnt && ans > div) {
            ans = div;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_div_score(nums: Vec<i32>, divisors: Vec<i32>) -> i32 {
        let mut ans = divisors[0];
        let mut mx = 0;

        for &div in &divisors {
            let mut cnt = 0;

            for &n in &nums {
                if n % div == 0 {
                    cnt += 1;
                }
            }

            if cnt > mx || (cnt >= mx && div < ans) {
                mx = cnt;
                ans = div;
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
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        ans, mx = divisors[0], 0
        for div in divisors:
            cnt = sum(x % div == 0 for x in nums)
            if mx < cnt:
                mx, ans = cnt, div
            elif mx == cnt and ans > div:
                ans = div
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                if (x % div == 0) {
                    ++cnt;
                }
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = Math.min(ans, div);
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                cnt += x % div == 0;
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = min(ans, div);
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}