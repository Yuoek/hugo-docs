---
title: "0689_MaximumSumof3Non-OverlappingSubarrays"
date: 2025-10-06T00:42:37+08:00
weight: 0689
tags: [数组, 动态规划, 前缀和, 滑动窗口]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [689. 三个无重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays)

[English Version](../en/0689-89/0689_MaximumSumof3Non-OverlappingSubarrays)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，找出三个长度为 <code>k</code> 、互不重叠、且全部数字和最大的子数组，并返回这三个子数组。</p>

<p>以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 <strong>0</strong> 开始）。如果有多个结果，返回字典序最小的一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,6,7,5,1], k = 2
<strong>输出：</strong>[0,3,5]
<strong>解释：</strong>子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,1,2,1,2,1], k = 2
<strong>输出：</strong>[0,2,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;&nbsp;2<sup>16</sup></code></li>
	<li><code>1 &lt;= k &lt;= floor(nums.length / 3)</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：滑动窗口

滑动窗口，枚举第三个子数组的位置，同时维护前两个无重叠子数组的最大和及其位置。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理前后缀 + 枚举中间子数组

我们可以预处理得到数组 $nums$ 的前缀和数组 $s$，其中 $s[i] = \sum_{j=0}^{i-1} nums[j]$，那么对于任意的 $i$，$j$，$s[j] - s[i]$ 就是子数组 $[i, j)$ 的和。

接下来，我们使用动态规划的方法，维护两个长度为 $n$ 的数组 $pre$ 和 $suf$，其中 $pre[i]$ 表示 $[0, i]$ 范围内长度为 $k$ 的子数组的最大和及其起始位置，$suf[i]$ 表示 $[i, n)$ 范围内长度为 $k$ 的子数组的最大和及其起始位置。

然后，我们枚举中间子数组的起始位置 $i$，那么三个子数组的和就是 $pre[i-1][0] + suf[i+k][0] + (s[i+k] - s[i])$，其中 $pre[i-1][0]$ 表示 $[0, i-1]$ 范围内长度为 $k$ 的子数组的最大和，$suf[i+k][0]$ 表示 $[i+k, n)$ 范围内长度为 $k$ 的子数组的最大和，$(s[i+k] - s[i])$ 表示 $[i, i+k)$ 范围内长度为 $k$ 的子数组的和。我们找出和的最大值对应的三个子数组的起始位置即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

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
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        pre = [[] for _ in range(n)]
        suf = [[] for _ in range(n)]
        t = idx = 0
        for i in range(n - k + 1):
            if (cur := s[i + k] - s[i]) > t:
                pre[i + k - 1] = [cur, i]
                t, idx = pre[i + k - 1]
            else:
                pre[i + k - 1] = [t, idx]
        t = idx = 0
        for i in range(n - k, -1, -1):
            if (cur := s[i + k] - s[i]) >= t:
                suf[i] = [cur, i]
                t, idx = suf[i]
            else:
                suf[i] = [t, idx]
        t = 0
        ans = []
        for i in range(k, n - 2 * k + 1):
            if (cur := s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0]) > t:
                ans = [pre[i - 1][1], i, suf[i + k][1]]
                t = cur
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int[][] pre = new int[n][0];
        int[][] suf = new int[n][0];
        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = new int[] {t, idx};
            }
        }
        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = new int[] {t, idx};
            }
        }
        int[] ans = new int[0];
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = new int[] {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }

        vector<vector<int>> pre(n, vector<int>(2, 0));
        vector<vector<int>> suf(n, vector<int>(2, 0));

        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = {t, idx};
            }
        }

        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = {t, idx};
            }
        }

        vector<int> ans;
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumOfThreeSubarrays(nums []int, k int) (ans []int) {
	n := len(nums)
	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + nums[i]
	}

	pre := make([][]int, n)
	suf := make([][]int, n)

	for i, t, idx := 0, 0, 0; i < n-k+1; i++ {
		cur := s[i+k] - s[i]
		if cur > t {
			pre[i+k-1] = []int{cur, i}
			t, idx = cur, i
		} else {
			pre[i+k-1] = []int{t, idx}
		}
	}

	for i, t, idx := n-k, 0, 0; i >= 0; i-- {
		cur := s[i+k] - s[i]
		if cur >= t {
			suf[i] = []int{cur, i}
			t, idx = cur, i
		} else {
			suf[i] = []int{t, idx}
		}
	}

	for i, t := k, 0; i < n-2*k+1; i++ {
		cur := s[i+k] - s[i] + pre[i-1][0] + suf[i+k][0]
		if cur > t {
			ans = []int{pre[i-1][1], i, suf[i+k][1]}
			t = cur
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumOfThreeSubarrays(nums: number[], k: number): number[] {
    const n: number = nums.length;
    const s: number[] = Array(n + 1).fill(0);

    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }

    const pre: number[][] = Array(n)
        .fill([])
        .map(() => new Array(2).fill(0));
    const suf: number[][] = Array(n)
        .fill([])
        .map(() => new Array(2).fill(0));

    for (let i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
        const cur: number = s[i + k] - s[i];
        if (cur > t) {
            pre[i + k - 1] = [cur, i];
            t = cur;
            idx = i;
        } else {
            pre[i + k - 1] = [t, idx];
        }
    }

    for (let i = n - k, t = 0, idx = 0; i >= 0; --i) {
        const cur: number = s[i + k] - s[i];
        if (cur >= t) {
            suf[i] = [cur, i];
            t = cur;
            idx = i;
        } else {
            suf[i] = [t, idx];
        }
    }

    let ans: number[] = [];
    for (let i = k, t = 0; i < n - 2 * k + 1; ++i) {
        const cur: number = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
        if (cur > t) {
            ans = [pre[i - 1][1], i, suf[i + k][1]];
            t = cur;
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
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        pre = [[] for _ in range(n)]
        suf = [[] for _ in range(n)]
        t = idx = 0
        for i in range(n - k + 1):
            if (cur := s[i + k] - s[i]) > t:
                pre[i + k - 1] = [cur, i]
                t, idx = pre[i + k - 1]
            else:
                pre[i + k - 1] = [t, idx]
        t = idx = 0
        for i in range(n - k, -1, -1):
            if (cur := s[i + k] - s[i]) >= t:
                suf[i] = [cur, i]
                t, idx = suf[i]
            else:
                suf[i] = [t, idx]
        t = 0
        ans = []
        for i in range(k, n - 2 * k + 1):
            if (cur := s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0]) > t:
                ans = [pre[i - 1][1], i, suf[i + k][1]]
                t = cur
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int[][] pre = new int[n][0];
        int[][] suf = new int[n][0];
        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = new int[] {t, idx};
            }
        }
        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = new int[] {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = new int[] {t, idx};
            }
        }
        int[] ans = new int[0];
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = new int[] {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }

        vector<vector<int>> pre(n, vector<int>(2, 0));
        vector<vector<int>> suf(n, vector<int>(2, 0));

        for (int i = 0, t = 0, idx = 0; i < n - k + 1; ++i) {
            int cur = s[i + k] - s[i];
            if (cur > t) {
                pre[i + k - 1] = {cur, i};
                t = cur;
                idx = i;
            } else {
                pre[i + k - 1] = {t, idx};
            }
        }

        for (int i = n - k, t = 0, idx = 0; i >= 0; --i) {
            int cur = s[i + k] - s[i];
            if (cur >= t) {
                suf[i] = {cur, i};
                t = cur;
                idx = i;
            } else {
                suf[i] = {t, idx};
            }
        }

        vector<int> ans;
        for (int i = k, t = 0; i < n - 2 * k + 1; ++i) {
            int cur = s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0];
            if (cur > t) {
                ans = {pre[i - 1][1], i, suf[i + k][1]};
                t = cur;
            }
        }

        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}