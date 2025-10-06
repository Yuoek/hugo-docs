---
title: "2831_FindtheLongestEqualSubarray"
date: 2025-10-06T00:42:37+08:00
weight: 2831
tags: [数组, 哈希表, 二分查找, 滑动窗口]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2831. 找出最长等值子数组](https://leetcode.cn/problems/find-the-longest-equal-subarray)

[English Version](../en/2831-31/2831_FindtheLongestEqualSubarray)

## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>如果子数组中所有元素都相等，则认为子数组是一个 <strong>等值子数组</strong> 。注意，空数组是 <strong>等值子数组</strong> 。</p>

<p>从 <code>nums</code> 中删除最多 <code>k</code> 个元素后，返回可能的最长等值子数组的长度。</p>

<p><strong>子数组</strong> 是数组中一个连续且可能为空的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,3,1,3], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>最优的方案是删除下标 2 和下标 4 的元素。
删除后，nums 等于 [1, 3, 3, 3] 。
最长等值子数组从 i = 1 开始到 j = 3 结束，长度等于 3 。
可以证明无法创建更长的等值子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,2,1,1], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>最优的方案是删除下标 2 和下标 3 的元素。 
删除后，nums 等于 [1, 1, 1, 1] 。 
数组自身就是等值子数组，长度等于 4 。 
可以证明无法创建更长的等值子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双指针

我们用双指针维护一个单调变长的窗口，用哈希表维护窗口中每个元素出现的次数。

窗口中的所有元素个数减去窗口中出现次数最多的元素个数，就是窗口中需要删除的元素个数。

每一次，我们将右指针指向的元素加入窗口，然后更新哈希表，同时更新窗口中出现次数最多的元素个数。当窗口中需要删除的元素个数超过了 $k$ 时，我们就移动一次左指针，然后更新哈希表。

遍历结束后，返回出现次数最多的元素个数即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 双指针（写法二）

我们可以用一个哈希表 $g$ 维护每个元素的下标列表。

接下来，我们枚举每个元素作为等值元素，我们从哈希表 $g$ 中取出这个元素的下标列表 $ids$，然后我们定义两个指针 $l$ 和 $r$，用于维护一个窗口，使得窗口内的元素个数减去等值元素的个数，结果不超过 $k$。那么我们只需要求出最大的满足条件的窗口即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        g = defaultdict(list)
        for i, x in enumerate(nums):
            g[x].append(i)
        ans = 0
        for ids in g.values():
            l = 0
            for r in range(len(ids)):
                while ids[r] - ids[l] - (r - l) > k:
                    l += 1
                ans = max(ans, r - l + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestEqualSubarray(List<Integer> nums, int k) {
        int n = nums.size();
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[nums.get(i)].add(i);
        }
        int ans = 0;
        for (List<Integer> ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids.get(r) - ids.get(l) - (r - l) > k) {
                    ++l;
                }
                ans = Math.max(ans, r - l + 1);
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> g[n + 1];
        for (int i = 0; i < n; ++i) {
            g[nums[i]].push_back(i);
        }
        int ans = 0;
        for (const auto& ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids[r] - ids[l] - (r - l) > k) {
                    ++l;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestEqualSubarray(nums []int, k int) (ans int) {
	g := make([][]int, len(nums)+1)
	for i, x := range nums {
		g[x] = append(g[x], i)
	}
	for _, ids := range g {
		l := 0
		for r := range ids {
			for ids[r]-ids[l]-(r-l) > k {
				l++
			}
			ans = max(ans, r-l+1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestEqualSubarray(nums: number[], k: number): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n + 1 }, () => []);
    for (let i = 0; i < n; ++i) {
        g[nums[i]].push(i);
    }
    let ans = 0;
    for (const ids of g) {
        let l = 0;
        for (let r = 0; r < ids.length; ++r) {
            while (ids[r] - ids[l] - (r - l) > k) {
                ++l;
            }
            ans = Math.max(ans, r - l + 1);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        g = defaultdict(list)
        for i, x in enumerate(nums):
            g[x].append(i)
        ans = 0
        for ids in g.values():
            l = 0
            for r in range(len(ids)):
                while ids[r] - ids[l] - (r - l) > k:
                    l += 1
                ans = max(ans, r - l + 1)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestEqualSubarray(List<Integer> nums, int k) {
        int n = nums.size();
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[nums.get(i)].add(i);
        }
        int ans = 0;
        for (List<Integer> ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids.get(r) - ids.get(l) - (r - l) > k) {
                    ++l;
                }
                ans = Math.max(ans, r - l + 1);
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> g[n + 1];
        for (int i = 0; i < n; ++i) {
            g[nums[i]].push_back(i);
        }
        int ans = 0;
        for (const auto& ids : g) {
            int l = 0;
            for (int r = 0; r < ids.size(); ++r) {
                while (ids[r] - ids[l] - (r - l) > k) {
                    ++l;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}