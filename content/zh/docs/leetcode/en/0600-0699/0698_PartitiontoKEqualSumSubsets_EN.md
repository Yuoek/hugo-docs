---
title: "0698_PartitiontoKEqualSumSubsets"
date: 2025-10-06T00:42:37+08:00
weight: 0698
tags: [Bit Manipulation, Memoization, Array, Dynamic Programming, Backtracking, Bitmask]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [698. Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets)

[中文文档](/solution/0600-0699/0698.Partition%20to%20K%20Equal%20Sum%20Subsets/README.md)

## Description

<!-- description:start -->

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <code>true</code> if it is possible to divide this array into <code>k</code> non-empty subsets whose sums are all equal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,3,2,3,5,2,1], k = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], k = 3
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 16</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>The frequency of each element is in the range <code>[1, 4]</code>.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: DFS + Pruning

According to the problem description, we need to partition the array $\textit{nums}$ into $k$ subsets such that the sum of each subset is equal. Therefore, we first sum all the elements in $\textit{nums}$. If the total sum cannot be divided by $k$, it means we cannot partition the array into $k$ subsets, and we return $\textit{false}$ early.

If the total sum can be divided by $k$, let's denote the expected sum of each subset as $s$. Then, we create an array $\textit{cur}$ of length $k$ to represent the current sum of each subset.

We sort the array $\textit{nums}$ in descending order (to reduce the number of searches), and then start from the first element, trying to add it to each subset in $\textit{cur}$ one by one. If adding $\textit{nums}[i]$ to a subset $\textit{cur}[j]$ makes the subset's sum exceed $s$, it means it cannot be placed in that subset, and we can skip it. Additionally, if $\textit{cur}[j]$ is equal to $\textit{cur}[j - 1]$, it means we have already completed the search for $\textit{cur}[j - 1]$, and we can skip the current search.

If we can add all elements to $\textit{cur}$, it means we can partition the array into $k$ subsets, and we return $\textit{true}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: State Compression + Memoization

Similar to Solution 1, we first check whether the array $\textit{nums}$ can be partitioned into $k$ subsets. If it cannot be divided by $k$, we directly return $\textit{false}$.

Let $s$ be the expected sum of each subset, and let $\textit{state}$ represent the current partitioning state of the elements. For the $i$-th number, if the $i$-th bit of $\textit{state}$ is $0$, it means the $i$-th element has not been partitioned.

Our goal is to form $k$ subsets with a sum of $s$ from all elements. Let $t$ be the current sum of the subset. When the $i$-th element is not partitioned:

-   If $t + \textit{nums}[i] \gt s$, it means the $i$-th element cannot be added to the current subset. Since we sort the array $\textit{nums}$ in ascending order, all elements from position $i$ onwards cannot be added to the current subset, and we directly return $\textit{false}$.
-   Otherwise, add the $i$-th element to the current subset, change the state to $\textit{state} | 2^i$, and continue searching for unpartitioned elements. Note that if $t + \textit{nums}[i] = s$, it means we can form a subset with a sum of $s$. The next step is to reset $t$ to zero (which can be achieved by $(t + \textit{nums}[i]) \bmod s$) and continue partitioning the next subset.

To avoid repeated searches, we use an array $\textit{f}$ of length $2^n$ to record the search results for each state. The array $\textit{f}$ has three possible values:

-   `0` indicates that the current state has not been searched yet;
-   `-1`: indicates that the current state cannot be partitioned into $k$ subsets;
-   `1`: indicates that the current state can be partitioned into $k$ subsets.

The time complexity is $O(n \times 2^n)$, and the space complexity is $O(2^n)$. Here, $n$ represents the length of the array $\textit{nums}$. For each state, we need to traverse the array $\textit{nums}$, which has a time complexity of $O(n)$. The total number of states is $2^n$, so the overall time complexity is $O(n \times 2^n)$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3: Dynamic Programming

We can use dynamic programming to solve this problem.

We define $f[i]$ to represent whether there exists $k$ subsets that meet the requirements when the current selected numbers' state is $i$. Initially, $f[0] = \text{true}$, and the answer is $f[2^n - 1]$, where $n$ is the length of the array $\textit{nums}$. Additionally, we define $cur[i]$ to represent the sum of the last subset when the current selected numbers' state is $i$.

We enumerate the states $i$ in the range $[0, 2^n]$. For each state $i$, if $f[i]$ is $\text{false}$, we skip it. Otherwise, we enumerate any number $\textit{nums}[j]$ in the array $\textit{nums}$. If $cur[i] + \textit{nums}[j] > s$, we break the enumeration loop because the subsequent numbers are larger and cannot be placed in the current subset. Otherwise, if the $j$-th bit of the binary representation of $i$ is $0$, it means the current $\textit{nums}[j]$ has not been selected. We can place it in the current subset, change the state to $i | 2^j$, update $cur[i | 2^j] = (cur[i] + \textit{nums}[j]) \bmod s$, and set $f[i | 2^j] = \text{true}$.

Finally, we return $f[2^n - 1]$.

The time complexity is $O(n \times 2^n)$, and the space complexity is $O(2^n)$. Here, $n$ represents the length of the array $\textit{nums}$.

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
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k:
            return False
        s //= k
        nums.sort()
        n = len(nums)
        f = [False] * (1 << n)
        cur = [0] * (1 << n)
        f[0] = True
        for i in range(1 << n):
            if not f[i]:
                continue
            for j in range(n):
                if cur[i] + nums[j] > s:
                    break
                if (i >> j & 1) == 0:
                    if not f[i | 1 << j]:
                        cur[i | 1 << j] = (cur[i] + nums[j]) % s
                        f[i | 1 << j] = True
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % k != 0) {
            return false;
        }
        s /= k;
        Arrays.sort(nums);
        int n = nums.length;
        boolean[] f = new boolean[1 << n];
        f[0] = true;
        int[] cur = new int[1 << n];
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                    f[i | 1 << j] = true;
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool f[1 << n];
        int cur[1 << n];
        memset(f, false, sizeof(f));
        memset(cur, 0, sizeof(cur));
        f[0] = 1;
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    f[i | 1 << j] = true;
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canPartitionKSubsets(nums []int, k int) bool {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s%k != 0 {
		return false
	}
	s /= k
	sort.Ints(nums)
	n := len(nums)
	f := make([]bool, 1<<n)
	cur := make([]int, 1<<n)
	f[0] = true
	for i := 0; i < 1<<n; i++ {
		if !f[i] {
			continue
		}
		for j := 0; j < n; j++ {
			if cur[i]+nums[j] > s {
				break
			}
			if i>>j&1 == 0 {
				f[i|1<<j] = true
				cur[i|1<<j] = (cur[i] + nums[j]) % s
			}
		}
	}
	return f[(1<<n)-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canPartitionKSubsets(nums: number[], k: number): boolean {
    let s = nums.reduce((a, b) => a + b);
    if (s % k !== 0) {
        return false;
    }
    s /= k;
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: boolean[] = Array(1 << n).fill(false);
    f[0] = true;
    const cur: number[] = Array(n).fill(0);
    for (let i = 0; i < 1 << n; ++i) {
        if (!f[i]) {
            continue;
        }
        for (let j = 0; j < n; ++j) {
            if (cur[i] + nums[j] > s) {
                break;
            }
            if (((i >> j) & 1) === 0) {
                f[i | (1 << j)] = true;
                cur[i | (1 << j)] = (cur[i] + nums[j]) % s;
            }
        }
    }
    return f[(1 << n) - 1];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k:
            return False
        s //= k
        nums.sort()
        n = len(nums)
        f = [False] * (1 << n)
        cur = [0] * (1 << n)
        f[0] = True
        for i in range(1 << n):
            if not f[i]:
                continue
            for j in range(n):
                if cur[i] + nums[j] > s:
                    break
                if (i >> j & 1) == 0:
                    if not f[i | 1 << j]:
                        cur[i | 1 << j] = (cur[i] + nums[j]) % s
                        f[i | 1 << j] = True
        return f[-1]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % k != 0) {
            return false;
        }
        s /= k;
        Arrays.sort(nums);
        int n = nums.length;
        boolean[] f = new boolean[1 << n];
        f[0] = true;
        int[] cur = new int[1 << n];
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                    f[i | 1 << j] = true;
                }
            }
        }
        return f[(1 << n) - 1];
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool f[1 << n];
        int cur[1 << n];
        memset(f, false, sizeof(f));
        memset(cur, 0, sizeof(cur));
        f[0] = 1;
        for (int i = 0; i < 1 << n; ++i) {
            if (!f[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur[i] + nums[j] > s) {
                    break;
                }
                if ((i >> j & 1) == 0) {
                    f[i | 1 << j] = true;
                    cur[i | 1 << j] = (cur[i] + nums[j]) % s;
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}