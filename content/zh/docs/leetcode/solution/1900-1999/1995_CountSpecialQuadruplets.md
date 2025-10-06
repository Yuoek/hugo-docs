---
title: "1995_CountSpecialQuadruplets"
date: 2025-10-06T00:42:37+08:00
weight: 1995
tags: [数组, 哈希表, 枚举]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1995. 统计特殊四元组](https://leetcode.cn/problems/count-special-quadruplets)

[English Version](../en/1995-95/1995_CountSpecialQuadruplets)

## 题目描述

<!-- description:start -->

<p>给你一个 <strong>下标从 0 开始</strong> 的整数数组 <code>nums</code> ，返回满足下述条件的 <strong>不同</strong> 四元组 <code>(a, b, c, d)</code> 的 <strong>数目</strong> ：</p>

<ul>
	<li><code>nums[a] + nums[b] + nums[c] == nums[d]</code> ，且</li>
	<li><code>a &lt; b &lt; c &lt; d</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,6]
<strong>输出：</strong>1
<strong>解释：</strong>满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [3,3,6,4,5]
<strong>输出：</strong>0
<strong>解释：</strong>[3,3,6,4,5] 中不存在满足要求的四元组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,3,5]
<strong>输出：</strong>4
<strong>解释：</strong>满足要求的 4 个四元组如下：
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>4 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

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
    def countQuadruplets(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        counter = Counter()
        for b in range(n - 3, 0, -1):
            c = b + 1
            for d in range(c + 1, n):
                counter[nums[d] - nums[c]] += 1
            for a in range(b):
                ans += counter[nums[a] + nums[b]]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0, n = nums.length;
        int[] counter = new int[310];
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
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
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> counter(310);
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countQuadruplets(nums []int) int {
	ans, n := 0, len(nums)
	counter := make([]int, 310)
	for b := n - 3; b > 0; b-- {
		c := b + 1
		for d := c + 1; d < n; d++ {
			if nums[d] >= nums[c] {
				counter[nums[d]-nums[c]]++
			}
		}
		for a := 0; a < b; a++ {
			ans += counter[nums[a]+nums[b]]
		}
	}
	return ans
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        counter = Counter()
        for b in range(n - 3, 0, -1):
            c = b + 1
            for d in range(c + 1, n):
                counter[nums[d] - nums[c]] += 1
            for a in range(b):
                ans += counter[nums[a] + nums[b]]
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0, n = nums.length;
        int[] counter = new int[310];
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
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
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> counter(310);
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}