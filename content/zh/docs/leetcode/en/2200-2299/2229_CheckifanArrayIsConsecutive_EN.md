---
title: "2229_CheckifanArrayIsConsecutive"
date: 2025-10-06T00:42:37+08:00
weight: 2229
tags: [Array, Hash Table, Sorting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2229. Check if an Array Is Consecutive 🔒](https://leetcode.com/problems/check-if-an-array-is-consecutive)

[中文文档](/solution/2200-2299/2229.Check%20if%20an%20Array%20Is%20Consecutive/README.md)

## Description

<!-- description:start -->

<p>Given an integer array <code>nums</code>, return <code>true</code> <em>if </em><code>nums</code><em> is <strong>consecutive</strong>, otherwise return </em><code>false</code><em>.</em></p>

<p>An array is <strong>consecutive </strong>if it contains every number in the range <code>[x, x + n - 1]</code> (<strong>inclusive</strong>), where <code>x</code> is the minimum number in the array and <code>n</code> is the length of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,4,2]
<strong>Output:</strong> true
<strong>Explanation:</strong>
The minimum value is 1 and the length of nums is 4.
All of the values in the range [x, x + n - 1] = [1, 1 + 4 - 1] = [1, 4] = (1, 2, 3, 4) occur in nums.
Therefore, nums is consecutive.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3]
<strong>Output:</strong> false
<strong>Explanation:</strong>
The minimum value is 1 and the length of nums is 2.
The value 2 in the range [x, x + n - 1] = [1, 1 + 2 - 1], = [1, 2] = (1, 2) does not occur in nums.
Therefore, nums is not consecutive.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,5,4]
<strong>Output:</strong> true
<strong>Explanation:</strong>
The minimum value is 3 and the length of nums is 3.
All of the values in the range [x, x + n - 1] = [3, 3 + 3 - 1] = [3, 5] = (3, 4, 5) occur in nums.
Therefore, nums is consecutive.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Hash Table

We can use a hash table $\textit{s}$ to store all the elements in the array $\textit{nums}$, and use two variables $\textit{mi}$ and $\textit{mx}$ to represent the minimum and maximum values in the array, respectively.

If all elements in the array are distinct and the length of the array equals the difference between the maximum and minimum values plus $1$, then the array is consecutive, and we return $\textit{true}$; otherwise, we return $\textit{false}$.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Here, $n$ is the length of the array $\textit{nums}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def isConsecutive(self, nums: List[int]) -> bool:
        mi, mx = min(nums), max(nums)
        return len(set(nums)) == mx - mi + 1 == len(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isConsecutive(int[] nums) {
        int mi = nums[0], mx = 0;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            if (!s.add(x)) {
                return false;
            }
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return mx - mi + 1 == nums.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int mi = nums[0], mx = 0;
        for (int x : nums) {
            if (s.contains(x)) {
                return false;
            }
            s.insert(x);
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return mx - mi + 1 == nums.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isConsecutive(nums []int) bool {
	s := map[int]bool{}
	mi, mx := nums[0], 0
	for _, x := range nums {
		if s[x] {
			return false
		}
		s[x] = true
		mi = min(mi, x)
		mx = max(mx, x)
	}
	return mx-mi+1 == len(nums)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isConsecutive(nums: number[]): boolean {
    let [mi, mx] = [nums[0], 0];
    const s = new Set<number>();
    for (const x of nums) {
        if (s.has(x)) {
            return false;
        }
        s.add(x);
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return mx - mi + 1 === nums.length;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isConsecutive = function (nums) {
    let [mi, mx] = [nums[0], 0];
    const s = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return false;
        }
        s.add(x);
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return mx - mi + 1 === nums.length;
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def isConsecutive(self, nums: List[int]) -> bool:
        mi, mx = min(nums), max(nums)
        return len(set(nums)) == mx - mi + 1 == len(nums)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean isConsecutive(int[] nums) {
        int mi = nums[0], mx = 0;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            if (!s.add(x)) {
                return false;
            }
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return mx - mi + 1 == nums.length;
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
    bool isConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int mi = nums[0], mx = 0;
        for (int x : nums) {
            if (s.contains(x)) {
                return false;
            }
            s.insert(x);
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return mx - mi + 1 == nums.size();
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}