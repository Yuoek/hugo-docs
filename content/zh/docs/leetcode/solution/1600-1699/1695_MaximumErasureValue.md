---
title: "1695_MaximumErasureValue"
date: 2025-10-06T00:42:37+08:00
weight: 1695
tags: [数组, 哈希表, 滑动窗口]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1695. 删除子数组的最大得分](https://leetcode.cn/problems/maximum-erasure-value)

[English Version](../en/1695-95/1695_MaximumErasureValue)

## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>nums</code> ，请你从中删除一个含有 <strong>若干不同元素</strong> 的子数组<strong>。</strong>删除子数组的 <strong>得分</strong> 就是子数组各元素之 <strong>和</strong> 。</p>

<p>返回 <strong>只删除一个</strong> 子数组可获得的 <strong>最大得分</strong><em> 。</em></p>

<p>如果数组 <code>b</code> 是数组 <code>a</code> 的一个连续子序列，即如果它等于 <code>a[l],a[l+1],...,a[r]</code> ，那么它就是 <code>a</code> 的一个子数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,4,5,6]
<strong>输出：</strong>17
<strong>解释：</strong>最优子数组是 [2,4,5,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,2,1,2,5,2,1,2,5]
<strong>输出：</strong>8
<strong>解释：</strong>最优子数组是 [5,2,1] 或 [1,2,5]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数组或哈希表 + 前缀和

我们用数组或哈希表 $\text{d}$ 记录每个数字最后一次出现的位置，用前缀和数组 $\text{s}$ 记录从起点到当前位置的和。我们用变量 $j$ 记录当前不重复子数组的左端点。

遍历数组，对于每个数字 $v$，如果 $\text{d}[v]$ 存在，那么我们更新 $j$ 为 $\max(j, \text{d}[v])$，这样就保证了当前不重复子数组不包含 $v$。然后我们更新答案为 $\max(\text{ans}, \text{s}[i] - \text{s}[j])$，最后更新 $\text{d}[v]$ 为 $i$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\text{nums}$ 的长度。

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

### 方法二：双指针（滑动窗口）

题目实际上是让我们找出一个最长的子数组，该子数组中所有元素都不相同。我们可以用两个指针 $i$ 和 $j$ 分别指向子数组的左右边界，初始时 $i = 0$, $j = 0$。另外，我们用一个哈希表 $\text{vis}$ 记录子数组中的元素。

遍历数组，对于每个数字 $x$，如果 $x$ 在 $\text{vis}$ 中，那么我们不断地将 $\text{nums}[i]$ 从 $\text{vis}$ 中移除，直到 $x$ 不在 $\text{vis}$ 中为止。这样我们就找到了一个不包含重复元素的子数组。我们将 $x$ 加入 $\text{vis}$，并更新子数组的和 $s$，然后更新答案 $\text{ans} = \max(\text{ans}, s)$。

遍历结束后，我们就可以得到最大的子数组和。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\text{nums}$ 的长度。

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
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        vis = set()
        ans = s = i = 0
        for x in nums:
            while x in vis:
                y = nums[i]
                s -= y
                vis.remove(y)
                i += 1
            vis.add(x)
            s += x
            ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.remove(nums[i++]);
            }
            vis.add(x);
            s += x;
            ans = Math.max(ans, s);
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
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> vis;
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.erase(nums[i++]);
            }
            vis.insert(x);
            s += x;
            ans = max(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumUniqueSubarray(nums []int) (ans int) {
	vis := map[int]bool{}
	var s, i int
	for _, x := range nums {
		for vis[x] {
			s -= nums[i]
			vis[nums[i]] = false
			i++
		}
		vis[x] = true
		s += x
		ans = max(ans, s)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumUniqueSubarray(nums: number[]): number {
    const vis: Set<number> = new Set();
    let [ans, s, i] = [0, 0, 0];
    for (const x of nums) {
        while (vis.has(x)) {
            s -= nums[i];
            vis.delete(nums[i++]);
        }
        vis.add(x);
        s += x;
        ans = Math.max(ans, s);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut vis = HashSet::new();
        let (mut ans, mut s, mut i) = (0, 0, 0);

        for &x in &nums {
            while vis.contains(&x) {
                let y = nums[i];
                s -= y;
                vis.remove(&y);
                i += 1;
            }
            vis.insert(x);
            s += x;
            ans = ans.max(s);
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
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        vis = set()
        ans = s = i = 0
        for x in nums:
            while x in vis:
                y = nums[i]
                s -= y
                vis.remove(y)
                i += 1
            vis.add(x)
            s += x
            ans = max(ans, s)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.remove(nums[i++]);
            }
            vis.add(x);
            s += x;
            ans = Math.max(ans, s);
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
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> vis;
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.erase(nums[i++]);
            }
            vis.insert(x);
            s += x;
            ans = max(ans, s);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}