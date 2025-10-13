---
title: "2460_对数组执行操作"
date: 2025-10-08T18:39:18+08:00
weight: 7
tags: [二分查找, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 数论, 枚举, 树, 模拟, 深度优先搜索, 滑动窗口]
---

{{< markmap >}}
### [2460_对数组执行操作](#2460)
#### [数组](#2460)
#### [双指针](#2460)
#### [模拟](#2460)
### [2461_长度为 K 子数组中的最大和](#2461)
#### [数组](#2461)
#### [哈希表](#2461)
#### [滑动窗口](#2461)
### [2462_雇佣 K 位工人的总代价](#2462)
#### [数组](#2462)
#### [双指针](#2462)
#### [模拟](#2462)
#### [堆（优先队列）](#2462)
### [2463_最小移动总距离](#2463)
#### [数组](#2463)
#### [动态规划](#2463)
#### [排序](#2463)
### [2464_有效分割中的最少子数组数目 🔒](#2464)
#### [数组](#2464)
#### [数学](#2464)
#### [动态规划](#2464)
#### [数论](#2464)
### [2465_不同的平均值数目](#2465)
#### [数组](#2465)
#### [哈希表](#2465)
#### [双指针](#2465)
#### [排序](#2465)
### [2466_统计构造好字符串的方案数](#2466)
#### [动态规划](#2466)
### [2467_树上最大得分和路径](#2467)
#### [树](#2467)
#### [深度优先搜索](#2467)
#### [广度优先搜索](#2467)
#### [图](#2467)
#### [数组](#2467)
### [2468_根据限制分割消息](#2468)
#### [字符串](#2468)
#### [二分查找](#2468)
#### [枚举](#2468)
### [2469_温度转换](#2469)
#### [数学](#2469)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2460_对数组执行操作
___
#### 数组
___
#### 双指针
___
#### 模拟
---
### 2461_长度为 K 子数组中的最大和
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2462_雇佣 K 位工人的总代价
___
#### 数组
___
#### 双指针
___
#### 模拟
___
#### 堆（优先队列）
---
### 2463_最小移动总距离
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 2464_有效分割中的最少子数组数目 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 数论
---
### 2465_不同的平均值数目
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 排序
---
### 2466_统计构造好字符串的方案数
___
#### 动态规划
---
### 2467_树上最大得分和路径
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 数组
---
### 2468_根据限制分割消息
___
#### 字符串
___
#### 二分查找
___
#### 枚举
---
### 2469_温度转换
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 树 | 模拟 |
| 深度优先搜索 | 滑动窗口 |  |

# [2460. 对数组执行操作](https://leetcode.cn/problems/apply-operations-to-an-array){#2460}

{{< tabs "2460" >}}

{{% tab "python" %}}
```python
class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n - 1):
            if nums[i] == nums[i + 1]:
                nums[i] <<= 1
                nums[i + 1] = 0
        ans = [0] * n
        i = 0
        for x in nums:
            if x:
                ans[i] = x
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        int[] ans = new int[n];
        int i = 0;
        for (int x : nums) {
            if (x > 0) {
                ans[i++] = x;
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
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        vector<int> ans(n);
        int i = 0;
        for (int& x : nums) {
            if (x) {
                ans[i++] = x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func applyOperations(nums []int) []int {
	n := len(nums)
	for i := 0; i < n-1; i++ {
		if nums[i] == nums[i+1] {
			nums[i] <<= 1
			nums[i+1] = 0
		}
	}
	ans := make([]int, n)
	i := 0
	for _, x := range nums {
		if x > 0 {
			ans[i] = x
			i++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function applyOperations(nums: number[]): number[] {
    const n = nums.length;
    for (let i = 0; i < n - 1; ++i) {
        if (nums[i] === nums[i + 1]) {
            nums[i] <<= 1;
            nums[i + 1] = 0;
        }
    }
    const ans: number[] = Array(n).fill(0);
    let i = 0;
    for (const x of nums) {
        if (x !== 0) {
            ans[i++] = x;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn apply_operations(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;

        for i in 0..nums.len() - 1 {
            if nums[i] == nums[i + 1] {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }

        let mut cur = 0;
        for i in 0..nums.len() {
            if nums[i] != 0 {
                nums.swap(i, cur);
                cur += 1;
            }
        }

        nums
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组大小为 <code>n</code> ，且由 <strong>非负</strong> 整数组成。</p>

<p>你需要对数组执行 <code>n - 1</code> 步操作，其中第 <code>i</code> 步操作（从 <strong>0</strong> 开始计数）要求对 <code>nums</code> 中第 <code>i</code> 个元素执行下述指令：</p>

<ul>
	<li>如果 <code>nums[i] == nums[i + 1]</code> ，则 <code>nums[i]</code> 的值变成原来的 <code>2</code> 倍，<code>nums[i + 1]</code> 的值变成 <code>0</code> 。否则，跳过这步操作。</li>
</ul>

<p>在执行完 <strong>全部</strong> 操作后，将所有 <code>0</code> <strong>移动</strong> 到数组的 <strong>末尾</strong> 。</p>

<ul>
	<li>例如，数组 <code>[1,0,2,0,0,1]</code> 将所有 <code>0</code> 移动到末尾后变为 <code>[1,2,1,0,0,0]</code> 。</li>
</ul>

<p>返回结果数组。</p>

<p><strong>注意</strong> 操作应当 <strong>依次有序</strong> 执行，而不是一次性全部执行。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,1,1,0]
<strong>输出：</strong>[1,4,2,0,0,0]
<strong>解释：</strong>执行以下操作：
- i = 0: nums[0] 和 nums[1] 不相等，跳过这步操作。
- i = 1: nums[1] 和 nums[2] 相等，nums[1] 的值变成原来的 2 倍，nums[2] 的值变成 0 。数组变成 [1,<em><strong>4</strong></em>,<em><strong>0</strong></em>,1,1,0] 。
- i = 2: nums[2] 和 nums[3] 不相等，所以跳过这步操作。
- i = 3: nums[3] 和 nums[4] 相等，nums[3] 的值变成原来的 2 倍，nums[4] 的值变成 0 。数组变成 [1,4,0,<em><strong>2</strong></em>,<em><strong>0</strong></em>,0] 。
- i = 4: nums[4] 和 nums[5] 相等，nums[4] 的值变成原来的 2 倍，nums[5] 的值变成 0 。数组变成 [1,4,0,2,<em><strong>0</strong></em>,<em><strong>0</strong></em>] 。
执行完所有操作后，将 0 全部移动到数组末尾，得到结果数组 [1,4,2,0,0,0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>无法执行任何操作，只需要将 0 移动到末尾。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接根据题意模拟即可。

首先，我们遍历数组 $nums$，对于任意相邻的两个元素 $nums[i]$ 和 $nums[i+1]$，如果 $nums[i]=nums[i+1]$，那么我们将 $nums[i]$ 的值变为原来的 $2$ 倍，同时将 $nums[i+1]$ 的值变为 $0$。

然后，我们创建一个长度为 $n$ 的答案数组 $ans$，并将 $nums$ 中所有非零元素按顺序放入 $ans$ 中。

最后，返回答案数组 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n - 1):
            if nums[i] == nums[i + 1]:
                nums[i] <<= 1
                nums[i + 1] = 0
        ans = [0] * n
        i = 0
        for x in nums:
            if x:
                ans[i] = x
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        int[] ans = new int[n];
        int i = 0;
        for (int x : nums) {
            if (x > 0) {
                ans[i++] = x;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        vector<int> ans(n);
        int i = 0;
        for (int& x : nums) {
            if (x) {
                ans[i++] = x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func applyOperations(nums []int) []int {
	n := len(nums)
	for i := 0; i < n-1; i++ {
		if nums[i] == nums[i+1] {
			nums[i] <<= 1
			nums[i+1] = 0
		}
	}
	ans := make([]int, n)
	i := 0
	for _, x := range nums {
		if x > 0 {
			ans[i] = x
			i++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function applyOperations(nums: number[]): number[] {
    const n = nums.length;
    for (let i = 0; i < n - 1; ++i) {
        if (nums[i] === nums[i + 1]) {
            nums[i] <<= 1;
            nums[i + 1] = 0;
        }
    }
    const ans: number[] = Array(n).fill(0);
    let i = 0;
    for (const x of nums) {
        if (x !== 0) {
            ans[i++] = x;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn apply_operations(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;

        for i in 0..nums.len() - 1 {
            if nums[i] == nums[i + 1] {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }

        let mut cur = 0;
        for i in 0..nums.len() {
            if nums[i] != 0 {
                nums.swap(i, cur);
                cur += 1;
            }
        }

        nums
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2461. 长度为 K 子数组中的最大和](https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k){#2461}

{{< tabs "2461" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums[:k])
        s = sum(nums[:k])
        ans = s if len(cnt) == k else 0
        for i in range(k, len(nums)):
            cnt[nums[i]] += 1
            cnt[nums[i - k]] -= 1
            if cnt[nums[i - k]] == 0:
                cnt.pop(nums[i - k])
            s += nums[i] - nums[i - k]
            if len(cnt) == k:
                ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> cnt = new HashMap<>(k);
        long s = 0;
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            s += nums[i];
        }
        long ans = cnt.size() == k ? s : 0;
        for (int i = k; i < n; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            if (cnt.merge(nums[i - k], -1, Integer::sum) == 0) {
                cnt.remove(nums[i - k]);
            }
            s += nums[i] - nums[i - k];
            if (cnt.size() == k) {
                ans = Math.max(ans, s);
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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        unordered_map<int, ll> cnt;
        ll s = 0;
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i]];
            s += nums[i];
        }
        ll ans = cnt.size() == k ? s : 0;
        for (int i = k; i < n; ++i) {
            ++cnt[nums[i]];
            if (--cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            s += nums[i] - nums[i - k];
            if (cnt.size() == k) {
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSubarraySum(nums []int, k int) (ans int64) {
	n := len(nums)
	cnt := map[int]int64{}
	var s int64
	for _, x := range nums[:k] {
		cnt[x]++
		s += int64(x)
	}
	if len(cnt) == k {
		ans = s
	}
	for i := k; i < n; i++ {
		cnt[nums[i]]++
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			delete(cnt, nums[i-k])
		}
		s += int64(nums[i] - nums[i-k])
		if len(cnt) == k && ans < s {
			ans = s
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSubarraySum(nums: number[], k: number): number {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    let s = 0;
    for (let i = 0; i < k; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        s += nums[i];
    }
    let ans = cnt.size === k ? s : 0;
    for (let i = k; i < n; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        cnt.set(nums[i - k], cnt.get(nums[i - k])! - 1);
        if (cnt.get(nums[i - k]) === 0) {
            cnt.delete(nums[i - k]);
        }
        s += nums[i] - nums[i - k];
        if (cnt.size === k) {
            ans = Math.max(ans, s);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        int n = nums.Length;
        Dictionary<int, int> cnt = new Dictionary<int, int>(k);
        long s = 0;

        for (int i = 0; i < k; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            s += nums[i];
        }

        long ans = cnt.Count == k ? s : 0;

        for (int i = k; i < n; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            if (--cnt[nums[i - k]] == 0) {
                cnt.Remove(nums[i - k]);
            }

            s += nums[i] - nums[i - k];

            if (cnt.Count == k) {
                ans = Math.Max(ans, s);
            }
        }

        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。请你从 <code>nums</code> 中满足下述条件的全部子数组中找出最大子数组和：</p>

<ul>
	<li>子数组的长度是 <code>k</code>，且</li>
	<li>子数组中的所有元素 <strong>各不相同 。</strong></li>
</ul>

<p>返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 <code>0</code> 。</p>

<p><strong>子数组</strong> 是数组中一段连续非空的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,4,2,9,9,9], k = 3
<strong>输出：</strong>15
<strong>解释：</strong>nums 中长度为 3 的子数组是：
- [1,5,4] 满足全部条件，和为 10 。
- [5,4,2] 满足全部条件，和为 11 。
- [4,2,9] 满足全部条件，和为 15 。
- [2,9,9] 不满足全部条件，因为元素 9 出现重复。
- [9,9,9] 不满足全部条件，因为元素 9 出现重复。
因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,4,4], k = 3
<strong>输出：</strong>0
<strong>解释：</strong>nums 中长度为 3 的子数组是：
- [4,4,4] 不满足全部条件，因为元素 4 出现重复。
因为不存在满足全部条件的子数组，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 哈希表

我们维护一个长度为 $k$ 的滑动窗口，用哈希表 $cnt$ 记录窗口中每个数字出现的次数，用变量 $s$ 记录窗口中所有数字的和。每次滑动窗口，如果窗口中的数字都不重复，那么更新答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums[:k])
        s = sum(nums[:k])
        ans = s if len(cnt) == k else 0
        for i in range(k, len(nums)):
            cnt[nums[i]] += 1
            cnt[nums[i - k]] -= 1
            if cnt[nums[i - k]] == 0:
                cnt.pop(nums[i - k])
            s += nums[i] - nums[i - k]
            if len(cnt) == k:
                ans = max(ans, s)
        return ans
```

#### Java

```java
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> cnt = new HashMap<>(k);
        long s = 0;
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            s += nums[i];
        }
        long ans = cnt.size() == k ? s : 0;
        for (int i = k; i < n; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            if (cnt.merge(nums[i - k], -1, Integer::sum) == 0) {
                cnt.remove(nums[i - k]);
            }
            s += nums[i] - nums[i - k];
            if (cnt.size() == k) {
                ans = Math.max(ans, s);
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        unordered_map<int, ll> cnt;
        ll s = 0;
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i]];
            s += nums[i];
        }
        ll ans = cnt.size() == k ? s : 0;
        for (int i = k; i < n; ++i) {
            ++cnt[nums[i]];
            if (--cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            s += nums[i] - nums[i - k];
            if (cnt.size() == k) {
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSubarraySum(nums []int, k int) (ans int64) {
	n := len(nums)
	cnt := map[int]int64{}
	var s int64
	for _, x := range nums[:k] {
		cnt[x]++
		s += int64(x)
	}
	if len(cnt) == k {
		ans = s
	}
	for i := k; i < n; i++ {
		cnt[nums[i]]++
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			delete(cnt, nums[i-k])
		}
		s += int64(nums[i] - nums[i-k])
		if len(cnt) == k && ans < s {
			ans = s
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumSubarraySum(nums: number[], k: number): number {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    let s = 0;
    for (let i = 0; i < k; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        s += nums[i];
    }
    let ans = cnt.size === k ? s : 0;
    for (let i = k; i < n; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        cnt.set(nums[i - k], cnt.get(nums[i - k])! - 1);
        if (cnt.get(nums[i - k]) === 0) {
            cnt.delete(nums[i - k]);
        }
        s += nums[i] - nums[i - k];
        if (cnt.size === k) {
            ans = Math.max(ans, s);
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        int n = nums.Length;
        Dictionary<int, int> cnt = new Dictionary<int, int>(k);
        long s = 0;

        for (int i = 0; i < k; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            s += nums[i];
        }

        long ans = cnt.Count == k ? s : 0;

        for (int i = k; i < n; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            if (--cnt[nums[i - k]] == 0) {
                cnt.Remove(nums[i - k]);
            }

            s += nums[i] - nums[i - k];

            if (cnt.Count == k) {
                ans = Math.Max(ans, s);
            }
        }

        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2462. 雇佣 K 位工人的总代价](https://leetcode.cn/problems/total-cost-to-hire-k-workers){#2462}

{{< tabs "2462" >}}

{{% tab "python" %}}
```python
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        if candidates * 2 >= n:
            return sum(sorted(costs)[:k])
        pq = []
        for i, c in enumerate(costs[:candidates]):
            heappush(pq, (c, i))
        for i in range(n - candidates, n):
            heappush(pq, (costs[i], i))
        heapify(pq)
        l, r = candidates, n - candidates - 1
        ans = 0
        for _ in range(k):
            c, i = heappop(pq)
            ans += c
            if l > r:
                continue
            if i < l:
                heappush(pq, (costs[l], l))
                l += 1
            else:
                heappush(pq, (costs[r], r))
                r -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        int n = costs.length;
        long ans = 0;
        if (candidates * 2 >= n) {
            Arrays.sort(costs);
            for (int i = 0; i < k; ++i) {
                ans += costs[i];
            }
            return ans;
        }
        PriorityQueue<int[]> pq
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < candidates; ++i) {
            pq.offer(new int[] {costs[i], i});
            pq.offer(new int[] {costs[n - i - 1], n - i - 1});
        }
        int l = candidates, r = n - candidates - 1;
        while (k-- > 0) {
            var p = pq.poll();
            ans += p[0];
            if (l > r) {
                continue;
            }
            if (p[1] < l) {
                pq.offer(new int[] {costs[l], l++});
            } else {
                pq.offer(new int[] {costs[r], r--});
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
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if (candidates * 2 > n) {
            sort(costs.begin(), costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < candidates; ++i) {
            pq.emplace(costs[i], i);
            pq.emplace(costs[n - i - 1], n - i - 1);
        }
        long long ans = 0;
        int l = candidates, r = n - candidates - 1;
        while (k--) {
            auto [cost, i] = pq.top();
            pq.pop();
            ans += cost;
            if (l > r) {
                continue;
            }
            if (i < l) {
                pq.emplace(costs[l], l++);
            } else {
                pq.emplace(costs[r], r--);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalCost(costs []int, k int, candidates int) (ans int64) {
	n := len(costs)
	if candidates*2 > n {
		sort.Ints(costs)
		for _, x := range costs[:k] {
			ans += int64(x)
		}
		return
	}
	pq := hp{}
	for i, x := range costs[:candidates] {
		heap.Push(&pq, pair{x, i})
		heap.Push(&pq, pair{costs[n-i-1], n - i - 1})
	}
	l, r := candidates, n-candidates-1
	for ; k > 0; k-- {
		p := heap.Pop(&pq).(pair)
		ans += int64(p.cost)
		if l > r {
			continue
		}
		if p.i < l {
			heap.Push(&pq, pair{costs[l], l})
			l++
		} else {
			heap.Push(&pq, pair{costs[r], r})
			r--
		}
	}
	return
}

type pair struct{ cost, i int }
type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	return h[i].cost < h[j].cost || (h[i].cost == h[j].cost && h[i].i < h[j].i)
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function totalCost(costs: number[], k: number, candidates: number): number {
    const n = costs.length;
    if (candidates * 2 >= n) {
        costs.sort((a, b) => a - b);
        return costs.slice(0, k).reduce((acc, x) => acc + x, 0);
    }
    const pq = new PriorityQueue({
        compare: (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]),
    });
    for (let i = 0; i < candidates; ++i) {
        pq.enqueue([costs[i], i]);
        pq.enqueue([costs[n - i - 1], n - i - 1]);
    }
    let [l, r] = [candidates, n - candidates - 1];
    let ans = 0;
    while (k--) {
        const [cost, i] = pq.dequeue()!;
        ans += cost;
        if (l > r) {
            continue;
        }
        if (i < l) {
            pq.enqueue([costs[l], l++]);
        } else {
            pq.enqueue([costs[r], r--]);
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>costs</code>&nbsp;，其中&nbsp;<code>costs[i]</code>&nbsp;是雇佣第 <code>i</code>&nbsp;位工人的代价。</p>

<p>同时给你两个整数&nbsp;<code>k</code> 和&nbsp;<code>candidates</code>&nbsp;。我们想根据以下规则恰好雇佣&nbsp;<code>k</code>&nbsp;位工人：</p>

<ul>
	<li>总共进行&nbsp;<code>k</code>&nbsp;轮雇佣，且每一轮恰好雇佣一位工人。</li>
	<li>在每一轮雇佣中，从最前面 <code>candidates</code>&nbsp;和最后面 <code>candidates</code>&nbsp;人中选出代价最小的一位工人，如果有多位代价相同且最小的工人，选择下标更小的一位工人。
	<ul>
		<li>比方说，<code>costs = [3,2,7,7,1,2]</code> 且&nbsp;<code>candidates = 2</code>&nbsp;，第一轮雇佣中，我们选择第&nbsp;<code>4</code>&nbsp;位工人，因为他的代价最小&nbsp;<code>[<em>3,2</em>,7,7,<em><strong>1</strong>,2</em>]</code>&nbsp;。</li>
		<li>第二轮雇佣，我们选择第&nbsp;<code>1</code>&nbsp;位工人，因为他们的代价与第&nbsp;<code>4</code>&nbsp;位工人一样都是最小代价，而且下标更小，<code>[<em>3,<strong>2</strong></em>,7,<em>7,2</em>]</code>&nbsp;。注意每一轮雇佣后，剩余工人的下标可能会发生变化。</li>
	</ul>
	</li>
	<li>如果剩余员工数目不足 <code>candidates</code>&nbsp;人，那么下一轮雇佣他们中代价最小的一人，如果有多位代价相同且最小的工人，选择下标更小的一位工人。</li>
	<li>一位工人只能被选择一次。</li>
</ul>

<p>返回雇佣恰好<em>&nbsp;</em><code>k</code>&nbsp;位工人的总代价。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
<b>输出：</b>11
<b>解释：</b>我们总共雇佣 3 位工人。总代价一开始为 0 。
- 第一轮雇佣，我们从 [<strong><em>17,12,10,2</em></strong>,7,<strong><em>2,11,20,8</em></strong>] 中选择。最小代价是 2 ，有两位工人，我们选择下标更小的一位工人，即第 3 位工人。总代价是 0 + 2 = 2 。
- 第二轮雇佣，我们从 [<strong><em>17,12,10,7</em></strong>,<strong><em>2,11,20,8</em></strong>] 中选择。最小代价是 2 ，下标为 4 ，总代价是 2 + 2 = 4 。
- 第三轮雇佣，我们从 [<strong><em>17,12,10,7,11,20,8</em></strong>] 中选择，最小代价是 7 ，下标为 3 ，总代价是 4 + 7 = 11 。注意下标为 3 的工人同时在最前面和最后面 4 位工人中。
总雇佣代价是 11 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>costs = [1,2,4,1], k = 3, candidates = 3
<b>输出：</b>4
<b>解释：</b>我们总共雇佣 3 位工人。总代价一开始为 0 。
- 第一轮雇佣，我们从 [<strong><em>1,2,4,1</em></strong>] 中选择。最小代价为 1 ，有两位工人，我们选择下标更小的一位工人，即第 0 位工人，总代价是 0 + 1 = 1 。注意，下标为 1 和 2 的工人同时在最前面和最后面 3 位工人中。
- 第二轮雇佣，我们从 [<strong><em>2,4,1</em></strong>] 中选择。最小代价为 1 ，下标为 2 ，总代价是 1 + 1 = 2 。
- 第三轮雇佣，少于 3 位工人，我们从剩余工人 [<strong><em>2,4</em></strong>] 中选择。最小代价是 2 ，下标为 0 。总代价为 2 + 2 = 4 。
总雇佣代价是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= costs.length &lt;= 10<sup>5 </sup></code></li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k, candidates &lt;= costs.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们首先判断 $candidates \times 2$ 是否大于等于 $n$，如果是，我们直接返回前 $k$ 个最小的工人的代价之和。

否则，我们使用一个小根堆 $pq$ 来维护前 $candidates$ 个工人和后 $candidates$ 个工人的代价。

我们首先将前 $candidates$ 个工人的代价以及对应的下标加入小根堆 $pq$ 中，然后将后 $candidates$ 个工人的代价以及对应的下标加入小根堆 $pq$ 中。用两个指针 $l$ 和 $r$ 分别指向前后待选工人的下标，初始时 $l = candidates$, $r = n - candidates - 1$。

然后我们进行 $k$ 次循环，每次从小根堆 $pq$ 中取出代价最小的工人，将其代价加入答案，如果 $l > r$，说明前后待选工人已经全部被选完，直接跳过。否则，如果当前工人的下标小于 $l$，说明是前面的工人，我们将第 $l$ 个工人的代价以及下标加入小根堆 $pq$ 中，然后 $l$ 加一；否则，我们将第 $r$ 个工人的代价以及下标加入小根堆 $pq$ 中，然后 $r$ 减一。

循环结束后，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $costs$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        if candidates * 2 >= n:
            return sum(sorted(costs)[:k])
        pq = []
        for i, c in enumerate(costs[:candidates]):
            heappush(pq, (c, i))
        for i in range(n - candidates, n):
            heappush(pq, (costs[i], i))
        heapify(pq)
        l, r = candidates, n - candidates - 1
        ans = 0
        for _ in range(k):
            c, i = heappop(pq)
            ans += c
            if l > r:
                continue
            if i < l:
                heappush(pq, (costs[l], l))
                l += 1
            else:
                heappush(pq, (costs[r], r))
                r -= 1
        return ans
```

#### Java

```java
class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        int n = costs.length;
        long ans = 0;
        if (candidates * 2 >= n) {
            Arrays.sort(costs);
            for (int i = 0; i < k; ++i) {
                ans += costs[i];
            }
            return ans;
        }
        PriorityQueue<int[]> pq
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < candidates; ++i) {
            pq.offer(new int[] {costs[i], i});
            pq.offer(new int[] {costs[n - i - 1], n - i - 1});
        }
        int l = candidates, r = n - candidates - 1;
        while (k-- > 0) {
            var p = pq.poll();
            ans += p[0];
            if (l > r) {
                continue;
            }
            if (p[1] < l) {
                pq.offer(new int[] {costs[l], l++});
            } else {
                pq.offer(new int[] {costs[r], r--});
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if (candidates * 2 > n) {
            sort(costs.begin(), costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < candidates; ++i) {
            pq.emplace(costs[i], i);
            pq.emplace(costs[n - i - 1], n - i - 1);
        }
        long long ans = 0;
        int l = candidates, r = n - candidates - 1;
        while (k--) {
            auto [cost, i] = pq.top();
            pq.pop();
            ans += cost;
            if (l > r) {
                continue;
            }
            if (i < l) {
                pq.emplace(costs[l], l++);
            } else {
                pq.emplace(costs[r], r--);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func totalCost(costs []int, k int, candidates int) (ans int64) {
	n := len(costs)
	if candidates*2 > n {
		sort.Ints(costs)
		for _, x := range costs[:k] {
			ans += int64(x)
		}
		return
	}
	pq := hp{}
	for i, x := range costs[:candidates] {
		heap.Push(&pq, pair{x, i})
		heap.Push(&pq, pair{costs[n-i-1], n - i - 1})
	}
	l, r := candidates, n-candidates-1
	for ; k > 0; k-- {
		p := heap.Pop(&pq).(pair)
		ans += int64(p.cost)
		if l > r {
			continue
		}
		if p.i < l {
			heap.Push(&pq, pair{costs[l], l})
			l++
		} else {
			heap.Push(&pq, pair{costs[r], r})
			r--
		}
	}
	return
}

type pair struct{ cost, i int }
type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	return h[i].cost < h[j].cost || (h[i].cost == h[j].cost && h[i].i < h[j].i)
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function totalCost(costs: number[], k: number, candidates: number): number {
    const n = costs.length;
    if (candidates * 2 >= n) {
        costs.sort((a, b) => a - b);
        return costs.slice(0, k).reduce((acc, x) => acc + x, 0);
    }
    const pq = new PriorityQueue({
        compare: (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]),
    });
    for (let i = 0; i < candidates; ++i) {
        pq.enqueue([costs[i], i]);
        pq.enqueue([costs[n - i - 1], n - i - 1]);
    }
    let [l, r] = [candidates, n - candidates - 1];
    let ans = 0;
    while (k--) {
        const [cost, i] = pq.dequeue()!;
        ans += cost;
        if (l > r) {
            continue;
        }
        if (i < l) {
            pq.enqueue([costs[l], l++]);
        } else {
            pq.enqueue([costs[r], r--]);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2463. 最小移动总距离](https://leetcode.cn/problems/minimum-total-distance-traveled){#2463}

{{< tabs "2463" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        @cache
        def dfs(i, j):
            if i == len(robot):
                return 0
            if j == len(factory):
                return inf
            ans = dfs(i, j + 1)
            t = 0
            for k in range(factory[j][1]):
                if i + k == len(robot):
                    break
                t += abs(robot[i + k] - factory[j][0])
                ans = min(ans, t + dfs(i + k + 1, j + 1))
            return ans

        robot.sort()
        factory.sort()
        ans = dfs(0, 0)
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private long[][] f;
    private List<Integer> robot;
    private int[][] factory;

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> a[0] - b[0]);
        this.robot = robot;
        this.factory = factory;
        f = new long[robot.size()][factory.length];
        return dfs(0, 0);
    }

    private long dfs(int i, int j) {
        if (i == robot.size()) {
            return 0;
        }
        if (j == factory.length) {
            return Long.MAX_VALUE / 1000;
        }
        if (f[i][j] != 0) {
            return f[i][j];
        }
        long ans = dfs(i, j + 1);
        long t = 0;
        for (int k = 0; k < factory[j][1]; ++k) {
            if (i + k == robot.size()) {
                break;
            }
            t += Math.abs(robot.get(i + k) - factory[j][0]);
            ans = Math.min(ans, t + dfs(i + k + 1, j + 1));
        }
        f[i][j] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<ll>> f(robot.size(), vector<ll>(factory.size()));
        function<ll(int i, int j)> dfs = [&](int i, int j) -> ll {
            if (i == robot.size()) return 0;
            if (j == factory.size()) return 1e15;
            if (f[i][j]) return f[i][j];
            ll ans = dfs(i, j + 1);
            ll t = 0;
            for (int k = 0; k < factory[j][1]; ++k) {
                if (i + k >= robot.size()) break;
                t += abs(robot[i + k] - factory[j][0]);
                ans = min(ans, t + dfs(i + k + 1, j + 1));
            }
            f[i][j] = ans;
            return ans;
        };
        return dfs(0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTotalDistance(robot []int, factory [][]int) int64 {
	sort.Ints(robot)
	sort.Slice(factory, func(i, j int) bool { return factory[i][0] < factory[j][0] })
	f := make([][]int, len(robot))
	for i := range f {
		f[i] = make([]int, len(factory))
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i == len(robot) {
			return 0
		}
		if j == len(factory) {
			return 1e15
		}
		if f[i][j] != 0 {
			return f[i][j]
		}
		ans := dfs(i, j+1)
		t := 0
		for k := 0; k < factory[j][1]; k++ {
			if i+k >= len(robot) {
				break
			}
			t += abs(robot[i+k] - factory[j][0])
			ans = min(ans, t+dfs(i+k+1, j+1))
		}
		f[i][j] = ans
		return ans
	}
	return int64(dfs(0, 0))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>X 轴上有一些机器人和工厂。给你一个整数数组&nbsp;<code>robot</code>&nbsp;，其中&nbsp;<code>robot[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个机器人的位置。再给你一个二维整数数组&nbsp;<code>factory</code>&nbsp;，其中&nbsp;<code>factory[j] = [position<sub>j</sub>, limit<sub>j</sub>]</code>&nbsp;，表示第 <code>j</code>&nbsp;个工厂的位置在&nbsp;<code>position<sub>j</sub></code>&nbsp;，且第 <code>j</code>&nbsp;个工厂最多可以修理&nbsp;<code>limit<sub>j</sub></code>&nbsp;个机器人。</p>

<p>每个机器人所在的位置 <strong>互不相同</strong>&nbsp;。每个工厂所在的位置也 <strong>互不相同</strong>&nbsp;。注意一个机器人可能一开始跟一个工厂在 <strong>相同的位置</strong>&nbsp;。</p>

<p>所有机器人一开始都是坏的，他们会沿着设定的方向一直移动。设定的方向要么是 X 轴的正方向，要么是 X 轴的负方向。当一个机器人经过一个没达到上限的工厂时，这个工厂会维修这个机器人，且机器人停止移动。</p>

<p><b>任何时刻</b>，你都可以设置&nbsp;<strong>部分</strong>&nbsp;机器人的移动方向。你的目标是最小化所有机器人总的移动距离。</p>

<p>请你返回所有机器人移动的最小总距离。测试数据保证所有机器人都可以被维修。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>所有机器人移动速度相同。</li>
	<li>如果两个机器人移动方向相同，它们永远不会碰撞。</li>
	<li>如果两个机器人迎面相遇，它们也不会碰撞，它们彼此之间会擦肩而过。</li>
	<li>如果一个机器人经过了一个已经达到上限的工厂，机器人会当作工厂不存在，继续移动。</li>
	<li>机器人从位置&nbsp;<code>x</code> 到位置&nbsp;<code>y</code>&nbsp;的移动距离为&nbsp;<code>|y - x|</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2463.Minimum%20Total%20Distance%20Traveled/images/1667542978-utuiPv-image.png" style="width: 500px; height: 320px;" /></p>

<pre>
<b>输入：</b>robot = [0,4,6], factory = [[2,2],[6,2]]
<b>输出：</b>4
<b>解释：</b>如上图所示：
- 第一个机器人从位置 0 沿着正方向移动，在第一个工厂处维修。
- 第二个机器人从位置 4 沿着负方向移动，在第一个工厂处维修。
- 第三个机器人在位置 6 被第二个工厂维修，它不需要移动。
第一个工厂的维修上限是 2 ，它维修了 2 个机器人。
第二个工厂的维修上限是 2 ，它维修了 1 个机器人。
总移动距离是 |2 - 0| + |2 - 4| + |6 - 6| = 4 。没有办法得到比 4 更少的总移动距离。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2463.Minimum%20Total%20Distance%20Traveled/images/1667542984-OAIRFN-image.png" style="width: 500px; height: 329px;" /></p>

<pre>
<b>输入：</b>robot = [1,-1], factory = [[-2,1],[2,1]]
<b>输出：</b>2
<b>解释：</b>如上图所示：
- 第一个机器人从位置 1 沿着正方向移动，在第二个工厂处维修。
- 第二个机器人在位置 -1 沿着负方向移动，在第一个工厂处维修。
第一个工厂的维修上限是 1 ，它维修了 1 个机器人。
第二个工厂的维修上限是 1 ，它维修了 1 个机器人。
总移动距离是 |2 - 1| + |(-2) - (-1)| = 2 。没有办法得到比 2 更少的总移动距离。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= robot.length, factory.length &lt;= 100</code></li>
	<li><code>factory[j].length == 2</code></li>
	<li><code>-10<sup>9</sup> &lt;= robot[i], position<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= limit<sub>j</sub> &lt;= robot.length</code></li>
	<li>测试数据保证所有机器人都可以被维修。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们先对机器人和工厂进行升序排列。然后定义函数 $dfs(i, j)$ 表示从第 $i$ 个机器人开始，第 $j$ 个工厂开始维修的最小总移动距离。

对于 $dfs(i, j)$，如果第 $j$ 个工厂不维修机器人，那么 $dfs(i, j)=dfs(i, j+1)$。如果第 $j$ 个工厂维修机器人，我们可以枚举第 $j$ 个工厂维修的机器人的数量，找出最小的总移动距离。即 $dfs(i, j) = min(dfs(i + k + 1, j + 1) + \sum_{t = 0}^{k} |robot[i + t] - factory[j][0|)$。

时间复杂度 $O(m^2\times n)$，空间复杂度 $O(m\times n)$。其中 $m$ 和 $n$ 分别为机器人数量和工厂数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        @cache
        def dfs(i, j):
            if i == len(robot):
                return 0
            if j == len(factory):
                return inf
            ans = dfs(i, j + 1)
            t = 0
            for k in range(factory[j][1]):
                if i + k == len(robot):
                    break
                t += abs(robot[i + k] - factory[j][0])
                ans = min(ans, t + dfs(i + k + 1, j + 1))
            return ans

        robot.sort()
        factory.sort()
        ans = dfs(0, 0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private long[][] f;
    private List<Integer> robot;
    private int[][] factory;

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> a[0] - b[0]);
        this.robot = robot;
        this.factory = factory;
        f = new long[robot.size()][factory.length];
        return dfs(0, 0);
    }

    private long dfs(int i, int j) {
        if (i == robot.size()) {
            return 0;
        }
        if (j == factory.length) {
            return Long.MAX_VALUE / 1000;
        }
        if (f[i][j] != 0) {
            return f[i][j];
        }
        long ans = dfs(i, j + 1);
        long t = 0;
        for (int k = 0; k < factory[j][1]; ++k) {
            if (i + k == robot.size()) {
                break;
            }
            t += Math.abs(robot.get(i + k) - factory[j][0]);
            ans = Math.min(ans, t + dfs(i + k + 1, j + 1));
        }
        f[i][j] = ans;
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<ll>> f(robot.size(), vector<ll>(factory.size()));
        function<ll(int i, int j)> dfs = [&](int i, int j) -> ll {
            if (i == robot.size()) return 0;
            if (j == factory.size()) return 1e15;
            if (f[i][j]) return f[i][j];
            ll ans = dfs(i, j + 1);
            ll t = 0;
            for (int k = 0; k < factory[j][1]; ++k) {
                if (i + k >= robot.size()) break;
                t += abs(robot[i + k] - factory[j][0]);
                ans = min(ans, t + dfs(i + k + 1, j + 1));
            }
            f[i][j] = ans;
            return ans;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func minimumTotalDistance(robot []int, factory [][]int) int64 {
	sort.Ints(robot)
	sort.Slice(factory, func(i, j int) bool { return factory[i][0] < factory[j][0] })
	f := make([][]int, len(robot))
	for i := range f {
		f[i] = make([]int, len(factory))
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i == len(robot) {
			return 0
		}
		if j == len(factory) {
			return 1e15
		}
		if f[i][j] != 0 {
			return f[i][j]
		}
		ans := dfs(i, j+1)
		t := 0
		for k := 0; k < factory[j][1]; k++ {
			if i+k >= len(robot) {
				break
			}
			t += abs(robot[i+k] - factory[j][0])
			ans = min(ans, t+dfs(i+k+1, j+1))
		}
		f[i][j] = ans
		return ans
	}
	return int64(dfs(0, 0))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2464. 有效分割中的最少子数组数目 🔒](https://leetcode.cn/problems/minimum-subarrays-in-a-valid-split){#2464}

{{< tabs "2464" >}}

{{% tab "python" %}}
```python
class Solution:
    def validSubarraySplit(self, nums: List[int]) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            ans = inf
            for j in range(i, n):
                if gcd(nums[i], nums[j]) > 1:
                    ans = min(ans, 1 + dfs(j + 1))
            return ans

        n = len(nums)
        ans = dfs(0)
        dfs.cache_clear()
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] f;
    private int[] nums;
    private int inf = 0x3f3f3f3f;

    public int validSubarraySplit(int[] nums) {
        n = nums.length;
        f = new int[n];
        this.nums = nums;
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] > 0) {
            return f[i];
        }
        int ans = inf;
        for (int j = i; j < n; ++j) {
            if (gcd(nums[i], nums[j]) > 1) {
                ans = Math.min(ans, 1 + dfs(j + 1));
            }
        }
        f[i] = ans;
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i]) return f[i];
            int ans = inf;
            for (int j = i; j < n; ++j) {
                if (__gcd(nums[i], nums[j]) > 1) {
                    ans = min(ans, 1 + dfs(j + 1));
                }
            }
            f[i] = ans;
            return ans;
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validSubarraySplit(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	var dfs func(int) int
	const inf int = 0x3f3f3f3f
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		ans := inf
		for j := i; j < n; j++ {
			if gcd(nums[i], nums[j]) > 1 {
				ans = min(ans, 1+dfs(j+1))
			}
		}
		f[i] = ans
		return ans
	}
	ans := dfs(0)
	if ans < inf {
		return ans
	}
	return -1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>nums</code>。</p>

<p>如果要将整数数组 <code>nums</code> 拆分为&nbsp;<strong>子数组&nbsp;</strong>后是&nbsp;<strong>有效的</strong>，则必须满足:</p>

<ul>
	<li>每个子数组的第一个和最后一个元素的最大公约数&nbsp;<strong>大于</strong> <code>1</code>，且</li>
	<li><code>nums</code> 的每个元素只属于一个子数组。</li>
</ul>

<p>返回 <code>nums</code>&nbsp;的&nbsp;<strong>有效&nbsp;</strong>子数组拆分中的&nbsp;<strong>最少&nbsp;</strong>子数组数目。如果不能进行有效的子数组拆分，则返回 <code>-1</code>。</p>

<p><b>注意</b>:</p>

<ul>
	<li>两个数的&nbsp;<strong>最大公约数&nbsp;</strong>是能整除两个数的最大正整数。</li>
	<li><strong>子数组&nbsp;</strong>是数组中连续的非空部分。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,6,3,4,3]
<strong>输出:</strong> 2
<strong>解释:</strong> 我们可以通过以下方式创建一个有效的分割: [2,6] | [3,4,3].
- 第一个子数组的起始元素是 2，结束元素是 6。它们的最大公约数是 2，大于 1。
- 第二个子数组的起始元素是 3，结束元素是 3。它们的最大公约数是 3，大于 1。
可以证明，2 是我们在有效分割中可以获得的最少子数组数。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [3,5]
<strong>输出:</strong> 2
<strong>解释:</strong> 我们可以通过以下方式创建一个有效的分割: [3] | [5].
- 第一个子数组的起始元素是 3，结束元素是 3。它们的最大公约数是 3，大于 1。
- 第二个子数组的起始元素是 5，结束元素是 5。它们的最大公约数是 5，大于 1。
可以证明，2 是我们在有效分割中可以获得的最少子数组数。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,1]
<strong>输出:</strong> -1
<strong>解释:</strong> 不可能创建有效的分割。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$ 表示从下标 $i$ 开始的最小分割数。对于下标 $i$，我们可以枚举所有的分割点 $j$，即 $i \leq j \lt n$，其中 $n$ 为数组长度。对于每个分割点 $j$，我们需要判断 $nums[i]$ 和 $nums[j]$ 的最大公约数是否大于 $1$，如果大于 $1$，则可以进行分割，此时分割数为 $1 + dfs(j + 1)$，否则分割数为 $+\infty$。最后我们取所有分割数的最小值即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSubarraySplit(self, nums: List[int]) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            ans = inf
            for j in range(i, n):
                if gcd(nums[i], nums[j]) > 1:
                    ans = min(ans, 1 + dfs(j + 1))
            return ans

        n = len(nums)
        ans = dfs(0)
        dfs.cache_clear()
        return ans if ans < inf else -1
```

#### Java

```java
class Solution {
    private int n;
    private int[] f;
    private int[] nums;
    private int inf = 0x3f3f3f3f;

    public int validSubarraySplit(int[] nums) {
        n = nums.length;
        f = new int[n];
        this.nums = nums;
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] > 0) {
            return f[i];
        }
        int ans = inf;
        for (int j = i; j < n; ++j) {
            if (gcd(nums[i], nums[j]) > 1) {
                ans = Math.min(ans, 1 + dfs(j + 1));
            }
        }
        f[i] = ans;
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i]) return f[i];
            int ans = inf;
            for (int j = i; j < n; ++j) {
                if (__gcd(nums[i], nums[j]) > 1) {
                    ans = min(ans, 1 + dfs(j + 1));
                }
            }
            f[i] = ans;
            return ans;
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```

#### Go

```go
func validSubarraySplit(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	var dfs func(int) int
	const inf int = 0x3f3f3f3f
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		ans := inf
		for j := i; j < n; j++ {
			if gcd(nums[i], nums[j]) > 1 {
				ans = min(ans, 1+dfs(j+1))
			}
		}
		f[i] = ans
		return ans
	}
	ans := dfs(0)
	if ans < inf {
		return ans
	}
	return -1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2465. 不同的平均值数目](https://leetcode.cn/problems/number-of-distinct-averages){#2465}

{{< tabs "2465" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        cnt = Counter()
        for i in range(len(nums) >> 1):
            x = nums[i] + nums[-i - 1]
            cnt[x] += 1
            if cnt[x] == 1:
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distinctAverages(int[] nums) {
        Arrays.sort(nums);
        int[] cnt = new int[201];
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            if (++cnt[nums[i] + nums[n - i - 1]] == 1) {
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
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt[201]{};
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            if (++cnt[nums[i] + nums[n - i - 1]] == 1) {
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
func distinctAverages(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	cnt := [201]int{}
	for i := 0; i < n>>1; i++ {
		x := nums[i] + nums[n-i-1]
		cnt[x]++
		if cnt[x] == 1 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distinctAverages(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const cnt: number[] = Array(201).fill(0);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        if (++cnt[nums[i] + nums[n - i - 1]] === 1) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn distinct_averages(nums: Vec<i32>) -> i32 {
        let mut set = HashSet::new();
        let mut ans = 0;
        let n = nums.len();
        let mut nums = nums;
        nums.sort();

        for i in 0..n >> 1 {
            let x = nums[i] + nums[n - i - 1];

            if set.contains(&x) {
                continue;
            }

            set.insert(x);
            ans += 1;
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <strong>偶数</strong>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>只要&nbsp;<code>nums</code> <strong>不是</strong>&nbsp;空数组，你就重复执行以下步骤：</p>

<ul>
	<li>找到&nbsp;<code>nums</code>&nbsp;中的最小值，并删除它。</li>
	<li>找到&nbsp;<code>nums</code>&nbsp;中的最大值，并删除它。</li>
	<li>计算删除两数的平均值。</li>
</ul>

<p>两数 <code>a</code>&nbsp;和 <code>b</code>&nbsp;的 <strong>平均值</strong>&nbsp;为&nbsp;<code>(a + b) / 2</code>&nbsp;。</p>

<ul>
	<li>比方说，<code>2</code>&nbsp;和&nbsp;<code>3</code>&nbsp;的平均值是&nbsp;<code>(2 + 3) / 2 = 2.5</code>&nbsp;。</li>
</ul>

<p>返回上述过程能得到的 <strong>不同</strong>&nbsp;平均值的数目。</p>

<p><strong>注意</strong>&nbsp;，如果最小值或者最大值有重复元素，可以删除任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,1,4,0,3,5]
<b>输出：</b>2
<strong>解释：</strong>
1. 删除 0 和 5 ，平均值是 (0 + 5) / 2 = 2.5 ，现在 nums = [4,1,4,3] 。
2. 删除 1 和 4 ，平均值是 (1 + 4) / 2 = 2.5 ，现在 nums = [4,3] 。
3. 删除 3 和 4 ，平均值是 (3 + 4) / 2 = 3.5 。
2.5 ，2.5 和 3.5 之中总共有 2 个不同的数，我们返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,100]
<b>输出：</b>1
<strong>解释：</strong>
删除 1 和 100 后只有一个平均值，所以我们返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums.length</code>&nbsp;是偶数。</li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

题目中要求每次找到数组 $nums$ 中的最小值和最大值，然后删除它们，再计算删除两数的平均值。因此，我们可以先对数组 $nums$ 进行排序，然后每次取数组的首尾元素，计算它们的和，用哈希表或数组 $cnt$ 记录每个和出现的次数，最后统计不同的和的个数即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        return len(set(nums[i] + nums[-i - 1] for i in range(len(nums) >> 1)))
```

#### Java

```java
class Solution {
    public int distinctAverages(int[] nums) {
        Arrays.sort(nums);
        Set<Integer> s = new HashSet<>();
        int n = nums.length;
        for (int i = 0; i < n >> 1; ++i) {
            s.add(nums[i] + nums[n - i - 1]);
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n >> 1; ++i) {
            s.insert(nums[i] + nums[n - i - 1]);
        }
        return s.size();
    }
};
```

#### Go

```go
func distinctAverages(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	s := map[int]struct{}{}
	for i := 0; i < n>>1; i++ {
		s[nums[i]+nums[n-i-1]] = struct{}{}
	}
	return len(s)
}
```

#### TypeScript

```ts
function distinctAverages(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const s: Set<number> = new Set();
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        s.add(nums[i] + nums[n - i - 1]);
    }
    return s.size;
}
```

#### Rust

```rust
impl Solution {
    pub fn distinct_averages(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let n = nums.len();
        let mut cnt = vec![0; 201];
        let mut ans = 0;

        for i in 0..n >> 1 {
            let x = (nums[i] + nums[n - i - 1]) as usize;
            cnt[x] += 1;

            if cnt[x] == 1 {
                ans += 1;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        cnt = Counter()
        for i in range(len(nums) >> 1):
            x = nums[i] + nums[-i - 1]
            cnt[x] += 1
            if cnt[x] == 1:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int distinctAverages(int[] nums) {
        Arrays.sort(nums);
        int[] cnt = new int[201];
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            if (++cnt[nums[i] + nums[n - i - 1]] == 1) {
                ++ans;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt[201]{};
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            if (++cnt[nums[i] + nums[n - i - 1]] == 1) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func distinctAverages(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	cnt := [201]int{}
	for i := 0; i < n>>1; i++ {
		x := nums[i] + nums[n-i-1]
		cnt[x]++
		if cnt[x] == 1 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function distinctAverages(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const cnt: number[] = Array(201).fill(0);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        if (++cnt[nums[i] + nums[n - i - 1]] === 1) {
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn distinct_averages(nums: Vec<i32>) -> i32 {
        let mut h = HashMap::new();
        let mut nums = nums;
        let mut ans = 0;
        let n = nums.len();
        nums.sort();

        for i in 0..n >> 1 {
            let x = nums[i] + nums[n - i - 1];
            *h.entry(x).or_insert(0) += 1;

            if *h.get(&x).unwrap() == 1 {
                ans += 1;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn distinct_averages(nums: Vec<i32>) -> i32 {
        let mut set = HashSet::new();
        let mut ans = 0;
        let n = nums.len();
        let mut nums = nums;
        nums.sort();

        for i in 0..n >> 1 {
            let x = nums[i] + nums[n - i - 1];

            if set.contains(&x) {
                continue;
            }

            set.insert(x);
            ans += 1;
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2466. 统计构造好字符串的方案数](https://leetcode.cn/problems/count-ways-to-build-good-strings){#2466}

{{< tabs "2466" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        @cache
        def dfs(i):
            if i > high:
                return 0
            ans = 0
            if low <= i <= high:
                ans += 1
            ans += dfs(i + zero) + dfs(i + one)
            return ans % mod

        mod = 10**9 + 7
        return dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;
    private int[] f;
    private int lo;
    private int hi;
    private int zero;
    private int one;

    public int countGoodStrings(int low, int high, int zero, int one) {
        f = new int[high + 1];
        Arrays.fill(f, -1);
        lo = low;
        hi = high;
        this.zero = zero;
        this.one = one;
        return dfs(0);
    }

    private int dfs(int i) {
        if (i > hi) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        long ans = 0;
        if (i >= lo && i <= hi) {
            ++ans;
        }
        ans += dfs(i + zero) + dfs(i + one);
        ans %= MOD;
        f[i] = (int) ans;
        return f[i];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high + 1, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i > high) return 0;
            if (f[i] != -1) return f[i];
            long ans = i >= low && i <= high;
            ans += dfs(i + zero) + dfs(i + one);
            ans %= mod;
            f[i] = ans;
            return ans;
        };
        return dfs(0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countGoodStrings(low int, high int, zero int, one int) int {
	f := make([]int, high+1)
	for i := range f {
		f[i] = -1
	}
	const mod int = 1e9 + 7
	var dfs func(i int) int
	dfs = func(i int) int {
		if i > high {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		ans := 0
		if i >= low && i <= high {
			ans++
		}
		ans += dfs(i+zero) + dfs(i+one)
		ans %= mod
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodStrings(low: number, high: number, zero: number, one: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = new Array(high + 1).fill(0);
    f[0] = 1;

    for (let i = 1; i <= high; i++) {
        if (i >= zero) f[i] += f[i - zero];
        if (i >= one) f[i] += f[i - one];
        f[i] %= mod;
    }

    const ans = f.slice(low, high + 1).reduce((acc, cur) => acc + cur, 0);

    return ans % mod;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */
function countGoodStrings(low, high, zero, one) {
    const mod = 10 ** 9 + 7;
    const f = Array(high + 1).fill(0);
    f[0] = 1;

    for (let i = 1; i <= high; i++) {
        if (i >= zero) f[i] += f[i - zero];
        if (i >= one) f[i] += f[i - one];
        f[i] %= mod;
    }

    const ans = f.slice(low, high + 1).reduce((acc, cur) => acc + cur, 0);

    return ans % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你整数&nbsp;<code>zero</code>&nbsp;，<code>one</code>&nbsp;，<code>low</code>&nbsp;和&nbsp;<code>high</code>&nbsp;，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：</p>

<ul>
	<li>将&nbsp;<code>'0'</code>&nbsp;在字符串末尾添加&nbsp;<code>zero</code>&nbsp; 次。</li>
	<li>将&nbsp;<code>'1'</code>&nbsp;在字符串末尾添加&nbsp;<code>one</code>&nbsp;次。</li>
</ul>

<p>以上操作可以执行任意次。</p>

<p>如果通过以上过程得到一个 <strong>长度</strong>&nbsp;在&nbsp;<code>low</code> 和&nbsp;<code>high</code>&nbsp;之间（包含上下边界）的字符串，那么这个字符串我们称为&nbsp;<strong>好</strong>&nbsp;字符串。</p>

<p>请你返回满足以上要求的 <strong>不同</strong>&nbsp;好字符串数目。由于答案可能很大，请将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>low = 3, high = 3, zero = 1, one = 1
<b>输出：</b>8
<b>解释：</b>
一个可能的好字符串是 "011" 。
可以这样构造得到："" -&gt; "0" -&gt; "01" -&gt; "011" 。
从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>low = 2, high = 3, zero = 1, one = 2
<b>输出：</b>5
<b>解释：</b>好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= low&nbsp;&lt;= high&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= zero, one &lt;= low</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$ 表示从第 $i$ 位开始构造的好字符串的个数，答案即为 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i \gt high$，返回 $0$；
-   如果 $ low \leq i \leq high$，答案累加 $1$，然后 $i$ 之后既可以添加 `zero` 个 $0$，也可以添加 `one` 个 $1$，因此答案累加上 $dfs(i + zero) + dfs(i + one)$。

过程中，我们需要对答案取模，并且可以使用记忆化搜索减少重复计算。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n = high$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        @cache
        def dfs(i):
            if i > high:
                return 0
            ans = 0
            if low <= i <= high:
                ans += 1
            ans += dfs(i + zero) + dfs(i + one)
            return ans % mod

        mod = 10**9 + 7
        return dfs(0)
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;
    private int[] f;
    private int lo;
    private int hi;
    private int zero;
    private int one;

    public int countGoodStrings(int low, int high, int zero, int one) {
        f = new int[high + 1];
        Arrays.fill(f, -1);
        lo = low;
        hi = high;
        this.zero = zero;
        this.one = one;
        return dfs(0);
    }

    private int dfs(int i) {
        if (i > hi) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        long ans = 0;
        if (i >= lo && i <= hi) {
            ++ans;
        }
        ans += dfs(i + zero) + dfs(i + one);
        ans %= MOD;
        f[i] = (int) ans;
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high + 1, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i > high) return 0;
            if (f[i] != -1) return f[i];
            long ans = i >= low && i <= high;
            ans += dfs(i + zero) + dfs(i + one);
            ans %= mod;
            f[i] = ans;
            return ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func countGoodStrings(low int, high int, zero int, one int) int {
	f := make([]int, high+1)
	for i := range f {
		f[i] = -1
	}
	const mod int = 1e9 + 7
	var dfs func(i int) int
	dfs = func(i int) int {
		if i > high {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		ans := 0
		if i >= low && i <= high {
			ans++
		}
		ans += dfs(i+zero) + dfs(i+one)
		ans %= mod
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

<!-- tabs:start -->

#### TypeScript

```ts
function countGoodStrings(low: number, high: number, zero: number, one: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = new Array(high + 1).fill(0);
    f[0] = 1;

    for (let i = 1; i <= high; i++) {
        if (i >= zero) f[i] += f[i - zero];
        if (i >= one) f[i] += f[i - one];
        f[i] %= mod;
    }

    const ans = f.slice(low, high + 1).reduce((acc, cur) => acc + cur, 0);

    return ans % mod;
}
```

#### JavaScript

```js
/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */
function countGoodStrings(low, high, zero, one) {
    const mod = 10 ** 9 + 7;
    const f = Array(high + 1).fill(0);
    f[0] = 1;

    for (let i = 1; i <= high; i++) {
        if (i >= zero) f[i] += f[i - zero];
        if (i >= one) f[i] += f[i - one];
        f[i] %= mod;
    }

    const ans = f.slice(low, high + 1).reduce((acc, cur) => acc + cur, 0);

    return ans % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2467. 树上最大得分和路径](https://leetcode.cn/problems/most-profitable-path-in-a-tree){#2467}

{{< tabs "2467" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostProfitablePath(
        self, edges: List[List[int]], bob: int, amount: List[int]
    ) -> int:
        def dfs1(i, fa, t):
            if i == 0:
                ts[i] = min(ts[i], t)
                return True
            for j in g[i]:
                if j != fa and dfs1(j, i, t + 1):
                    ts[j] = min(ts[j], t + 1)
                    return True
            return False

        def dfs2(i, fa, t, v):
            if t == ts[i]:
                v += amount[i] // 2
            elif t < ts[i]:
                v += amount[i]
            nonlocal ans
            if len(g[i]) == 1 and g[i][0] == fa:
                ans = max(ans, v)
                return
            for j in g[i]:
                if j != fa:
                    dfs2(j, i, t + 1, v)

        n = len(edges) + 1
        g = defaultdict(list)
        ts = [n] * n
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        dfs1(bob, -1, 0)
        ts[bob] = 0
        ans = -inf
        dfs2(0, -1, 0, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] amount;
    private int[] ts;
    private int ans = Integer.MIN_VALUE;

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = edges.length + 1;
        g = new List[n];
        ts = new int[n];
        this.amount = amount;
        Arrays.setAll(g, k -> new ArrayList<>());
        Arrays.fill(ts, n);
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs1(bob, -1, 0);
        ts[bob] = 0;
        dfs2(0, -1, 0, 0);
        return ans;
    }

    private boolean dfs1(int i, int fa, int t) {
        if (i == 0) {
            ts[i] = Math.min(ts[i], t);
            return true;
        }
        for (int j : g[i]) {
            if (j != fa && dfs1(j, i, t + 1)) {
                ts[j] = Math.min(ts[j], t + 1);
                return true;
            }
        }
        return false;
    }

    private void dfs2(int i, int fa, int t, int v) {
        if (t == ts[i]) {
            v += amount[i] >> 1;
        } else if (t < ts[i]) {
            v += amount[i];
        }
        if (g[i].size() == 1 && g[i].get(0) == fa) {
            ans = Math.max(ans, v);
            return;
        }
        for (int j : g[i]) {
            if (j != fa) {
                dfs2(j, i, t + 1, v);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<int> ts(n, n);
        function<bool(int i, int fa, int t)> dfs1 = [&](int i, int fa, int t) -> bool {
            if (i == 0) {
                ts[i] = t;
                return true;
            }
            for (int j : g[i]) {
                if (j != fa && dfs1(j, i, t + 1)) {
                    ts[j] = min(ts[j], t + 1);
                    return true;
                }
            }
            return false;
        };
        dfs1(bob, -1, 0);
        ts[bob] = 0;
        int ans = INT_MIN;
        function<void(int i, int fa, int t, int v)> dfs2 = [&](int i, int fa, int t, int v) {
            if (t == ts[i])
                v += amount[i] >> 1;
            else if (t < ts[i])
                v += amount[i];
            if (g[i].size() == 1 && g[i][0] == fa) {
                ans = max(ans, v);
                return;
            }
            for (int j : g[i])
                if (j != fa) dfs2(j, i, t + 1, v);
        };
        dfs2(0, -1, 0, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostProfitablePath(edges [][]int, bob int, amount []int) int {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ts := make([]int, n)
	for i := range ts {
		ts[i] = n
	}
	var dfs1 func(int, int, int) bool
	dfs1 = func(i, fa, t int) bool {
		if i == 0 {
			ts[i] = min(ts[i], t)
			return true
		}
		for _, j := range g[i] {
			if j != fa && dfs1(j, i, t+1) {
				ts[j] = min(ts[j], t+1)
				return true
			}
		}
		return false
	}
	dfs1(bob, -1, 0)
	ts[bob] = 0
	ans := -0x3f3f3f3f
	var dfs2 func(int, int, int, int)
	dfs2 = func(i, fa, t, v int) {
		if t == ts[i] {
			v += amount[i] >> 1
		} else if t < ts[i] {
			v += amount[i]
		}
		if len(g[i]) == 1 && g[i][0] == fa {
			ans = max(ans, v)
			return
		}
		for _, j := range g[i] {
			if j != fa {
				dfs2(j, i, t+1, v)
			}
		}
	}
	dfs2(0, -1, 0, 0)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个 <code>n</code>&nbsp;个节点的无向树，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，树的根结点是&nbsp;<code>0</code>&nbsp;号节点。给你一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;，表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;在树中有一条边。</p>

<p>在每一个节点&nbsp;<code>i</code>&nbsp;处有一扇门。同时给你一个都是偶数的数组&nbsp;<code>amount</code>&nbsp;，其中&nbsp;<code>amount[i]</code>&nbsp;表示：</p>

<ul>
	<li>如果 <code>amount[i]</code>&nbsp;的值是负数，那么它表示打开节点&nbsp;<code>i</code>&nbsp;处门扣除的分数。</li>
	<li>如果 <code>amount[i]</code>&nbsp;的值是正数，那么它表示打开节点 <code>i</code>&nbsp;处门加上的分数。</li>
</ul>

<p>游戏按照如下规则进行：</p>

<ul>
	<li>一开始，Alice 在节点&nbsp;<code>0</code>&nbsp;处，Bob 在节点&nbsp;<code>bob</code>&nbsp;处。</li>
	<li>每一秒钟，Alice 和 Bob <strong>分别</strong>&nbsp;移动到相邻的节点。Alice 朝着某个&nbsp;<strong>叶子结点</strong>&nbsp;移动，Bob 朝着节点&nbsp;<code>0</code>&nbsp;移动。</li>
	<li>对于他们之间路径上的 <strong>每一个</strong>&nbsp;节点，Alice 和 Bob 要么打开门并扣分，要么打开门并加分。注意：
	<ul>
		<li>如果门 <strong>已经打开</strong>&nbsp;（被另一个人打开），不会有额外加分也不会扣分。</li>
		<li>如果&nbsp;Alice 和 Bob <strong>同时</strong>&nbsp;到达一个节点，他们会共享这个节点的加分或者扣分。换言之，如果打开这扇门扣&nbsp;<code>c</code>&nbsp;分，那么&nbsp;Alice 和 Bob 分别扣&nbsp;<code>c / 2</code>&nbsp;分。如果这扇门的加分为&nbsp;<code>c</code>&nbsp;，那么他们分别加&nbsp;<code>c / 2</code>&nbsp;分。</li>
	</ul>
	</li>
	<li>如果 Alice 到达了一个叶子结点，她会停止移动。类似的，如果&nbsp;Bob 到达了节点&nbsp;<code>0</code>&nbsp;，他也会停止移动。注意这些事件互相 <strong>独立</strong>&nbsp;，不会影响另一方移动。</li>
</ul>

<p>请你返回&nbsp;Alice 朝最优叶子结点移动的 <strong>最大</strong>&nbsp;净得分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2467.Most%20Profitable%20Path%20in%20a%20Tree/images/eg1.png" style="width: 275px; height: 275px;"></p>

<pre><b>输入：</b>edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
<b>输出：</b>6
<b>解释：</b>
上图展示了输入给出的一棵树。游戏进行如下：
- Alice 一开始在节点 0 处，Bob 在节点 3 处。他们分别打开所在节点的门。
  Alice 得分为 -2 。
- Alice 和 Bob 都移动到节点 1 。
&nbsp; 因为他们同时到达这个节点，他们一起打开门并平分得分。
&nbsp; Alice 的得分变为 -2 + (4 / 2) = 0 。
- Alice 移动到节点 3 。因为 Bob 已经打开了这扇门，Alice 得分不变。
&nbsp; Bob 移动到节点 0 ，并停止移动。
- Alice 移动到节点 4 并打开这个节点的门，她得分变为 0 + 6 = 6 。
现在，Alice 和 Bob 都不能进行任何移动了，所以游戏结束。
Alice 无法得到更高分数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2467.Most%20Profitable%20Path%20in%20a%20Tree/images/eg2.png" style="width: 250px; height: 78px;"></p>

<pre><b>输入：</b>edges = [[0,1]], bob = 1, amount = [-7280,2350]
<b>输出：</b>-7280
<b>解释：</b>
Alice 按照路径 0-&gt;1 移动，同时 Bob 按照路径 1-&gt;0 移动。
所以 Alice 只打开节点 0 处的门，她的得分为 -7280 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code>&nbsp;表示一棵有效的树。</li>
	<li><code>1 &lt;= bob &lt; n</code></li>
	<li><code>amount.length == n</code></li>
	<li><code>amount[i]</code>&nbsp;是范围&nbsp;<code>[-10<sup>4</sup>, 10<sup>4</sup>]</code>&nbsp;之间的一个&nbsp;<strong>偶数</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

根据题意，我们可以知道，Bob 的移动路径是固定的，即从节点 $bob$ 出发，最终到达节点 $0$。因此，我们可以先跑一遍 DFS，求出 Bob 到达每个节点的时间，记在数组 $ts$ 中。

然后我们再跑一遍 DFS，求出 Alice 每条移动路径的最大得分，我们记 Alice 到达节点 $i$ 的时间为 $t$，当前累计得分为 $v$，那么 Alice 在经过节点 $i$ 处后，累计的分数有三种情况：

1. Alice 到达节点 $i$ 的时间 $t$ 与 Bob 到达节点 $i$ 的时间 $ts[i]$ 相同，那么 Alice 和 Bob 同时打开节点 $i$ 处的门，Alice 获得的分数为 $v + \frac{amount[i]}{2}$；
1. Alice 到达节点 $i$ 的时间 $t$ 小于 Bob 到达节点 $i$ 的时间 $ts[i]$，那么 Alice 打开节点 $i$ 处的门，Alice 获得的分数为 $v + amount[i]$。
1. Alice 到达节点 $i$ 的时间 $t$ 大于 Bob 到达节点 $i$ 的时间 $ts[i]$，那么 Alice 不打开节点 $i$ 处的门，Alice 获得的分数为 $v$，即不变。

当 Alice 到达叶子节点时，更新最大得分。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostProfitablePath(
        self, edges: List[List[int]], bob: int, amount: List[int]
    ) -> int:
        def dfs1(i, fa, t):
            if i == 0:
                ts[i] = min(ts[i], t)
                return True
            for j in g[i]:
                if j != fa and dfs1(j, i, t + 1):
                    ts[j] = min(ts[j], t + 1)
                    return True
            return False

        def dfs2(i, fa, t, v):
            if t == ts[i]:
                v += amount[i] // 2
            elif t < ts[i]:
                v += amount[i]
            nonlocal ans
            if len(g[i]) == 1 and g[i][0] == fa:
                ans = max(ans, v)
                return
            for j in g[i]:
                if j != fa:
                    dfs2(j, i, t + 1, v)

        n = len(edges) + 1
        g = defaultdict(list)
        ts = [n] * n
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        dfs1(bob, -1, 0)
        ts[bob] = 0
        ans = -inf
        dfs2(0, -1, 0, 0)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] amount;
    private int[] ts;
    private int ans = Integer.MIN_VALUE;

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = edges.length + 1;
        g = new List[n];
        ts = new int[n];
        this.amount = amount;
        Arrays.setAll(g, k -> new ArrayList<>());
        Arrays.fill(ts, n);
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs1(bob, -1, 0);
        ts[bob] = 0;
        dfs2(0, -1, 0, 0);
        return ans;
    }

    private boolean dfs1(int i, int fa, int t) {
        if (i == 0) {
            ts[i] = Math.min(ts[i], t);
            return true;
        }
        for (int j : g[i]) {
            if (j != fa && dfs1(j, i, t + 1)) {
                ts[j] = Math.min(ts[j], t + 1);
                return true;
            }
        }
        return false;
    }

    private void dfs2(int i, int fa, int t, int v) {
        if (t == ts[i]) {
            v += amount[i] >> 1;
        } else if (t < ts[i]) {
            v += amount[i];
        }
        if (g[i].size() == 1 && g[i].get(0) == fa) {
            ans = Math.max(ans, v);
            return;
        }
        for (int j : g[i]) {
            if (j != fa) {
                dfs2(j, i, t + 1, v);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<int> ts(n, n);
        function<bool(int i, int fa, int t)> dfs1 = [&](int i, int fa, int t) -> bool {
            if (i == 0) {
                ts[i] = t;
                return true;
            }
            for (int j : g[i]) {
                if (j != fa && dfs1(j, i, t + 1)) {
                    ts[j] = min(ts[j], t + 1);
                    return true;
                }
            }
            return false;
        };
        dfs1(bob, -1, 0);
        ts[bob] = 0;
        int ans = INT_MIN;
        function<void(int i, int fa, int t, int v)> dfs2 = [&](int i, int fa, int t, int v) {
            if (t == ts[i])
                v += amount[i] >> 1;
            else if (t < ts[i])
                v += amount[i];
            if (g[i].size() == 1 && g[i][0] == fa) {
                ans = max(ans, v);
                return;
            }
            for (int j : g[i])
                if (j != fa) dfs2(j, i, t + 1, v);
        };
        dfs2(0, -1, 0, 0);
        return ans;
    }
};
```

#### Go

```go
func mostProfitablePath(edges [][]int, bob int, amount []int) int {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ts := make([]int, n)
	for i := range ts {
		ts[i] = n
	}
	var dfs1 func(int, int, int) bool
	dfs1 = func(i, fa, t int) bool {
		if i == 0 {
			ts[i] = min(ts[i], t)
			return true
		}
		for _, j := range g[i] {
			if j != fa && dfs1(j, i, t+1) {
				ts[j] = min(ts[j], t+1)
				return true
			}
		}
		return false
	}
	dfs1(bob, -1, 0)
	ts[bob] = 0
	ans := -0x3f3f3f3f
	var dfs2 func(int, int, int, int)
	dfs2 = func(i, fa, t, v int) {
		if t == ts[i] {
			v += amount[i] >> 1
		} else if t < ts[i] {
			v += amount[i]
		}
		if len(g[i]) == 1 && g[i][0] == fa {
			ans = max(ans, v)
			return
		}
		for _, j := range g[i] {
			if j != fa {
				dfs2(j, i, t+1, v)
			}
		}
	}
	dfs2(0, -1, 0, 0)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2468. 根据限制分割消息](https://leetcode.cn/problems/split-message-based-on-limit){#2468}

{{< tabs "2468" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        n = len(message)
        sa = 0
        for k in range(1, n + 1):
            sa += len(str(k))
            sb = len(str(k)) * k
            sc = 3 * k
            if limit * k - (sa + sb + sc) >= n:
                ans = []
                i = 0
                for j in range(1, k + 1):
                    tail = f'<{j}/{k}>'
                    t = message[i : i + limit - len(tail)] + tail
                    ans.append(t)
                    i += limit - len(tail)
                return ans
        return []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] splitMessage(String message, int limit) {
        int n = message.length();
        int sa = 0;
        String[] ans = new String[0];
        for (int k = 1; k <= n; ++k) {
            int lk = (k + "").length();
            sa += lk;
            int sb = lk * k;
            int sc = 3 * k;
            if (limit * k - (sa + sb + sc) >= n) {
                int i = 0;
                ans = new String[k];
                for (int j = 1; j <= k; ++j) {
                    String tail = String.format("<%d/%d>", j, k);
                    String t = message.substring(i, Math.min(n, i + limit - tail.length())) + tail;
                    ans[j - 1] = t;
                    i += limit - tail.length();
                }
                break;
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
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int sa = 0;
        vector<string> ans;
        for (int k = 1; k <= n; ++k) {
            int lk = to_string(k).size();
            sa += lk;
            int sb = lk * k;
            int sc = 3 * k;
            if (k * limit - (sa + sb + sc) >= n) {
                int i = 0;
                for (int j = 1; j <= k; ++j) {
                    string tail = "<" + to_string(j) + "/" + to_string(k) + ">";
                    string t = message.substr(i, limit - tail.size()) + tail;
                    ans.emplace_back(t);
                    i += limit - tail.size();
                }
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitMessage(message string, limit int) (ans []string) {
	n := len(message)
	sa := 0
	for k := 1; k <= n; k++ {
		lk := len(strconv.Itoa(k))
		sa += lk
		sb := lk * k
		sc := 3 * k
		if limit*k-(sa+sb+sc) >= n {
			i := 0
			for j := 1; j <= k; j++ {
				tail := "<" + strconv.Itoa(j) + "/" + strconv.Itoa(k) + ">"
				t := message[i:min(i+limit-len(tail), n)] + tail
				ans = append(ans, t)
				i += limit - len(tail)
			}
			break
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>message</code>&nbsp;和一个正整数&nbsp;<code>limit</code>&nbsp;。</p>

<p>你需要根据 <code>limit</code>&nbsp;将&nbsp;<code>message</code> <strong>分割</strong>&nbsp;成一个或多个 <strong>部分</strong>&nbsp;。每个部分的结尾都是&nbsp;<code>"&lt;a/b&gt;"</code>&nbsp;，其中&nbsp;<code>"b"</code>&nbsp;用分割出来的总数 <b>替换</b>，&nbsp;<code>"a"</code>&nbsp;用当前部分所在的编号 <strong>替换</strong>&nbsp;，编号从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>b</code>&nbsp;依次编号。除此以外，除了最后一部分长度 <strong>小于等于</strong>&nbsp;<code>limit</code>&nbsp;以外，其他每一部分（包括结尾部分）的长度都应该&nbsp;<strong>等于</strong>&nbsp;<code>limit</code>&nbsp;。</p>

<p>你需要确保分割后的结果数组，删掉每部分的结尾并<strong>&nbsp;按顺序&nbsp;</strong>连起来后，能够得到&nbsp;<code>message</code>&nbsp;。同时，结果数组越短越好。</p>

<p>请你返回<em>&nbsp;</em><code>message</code>&nbsp; 分割后得到的结果数组。如果无法按要求分割&nbsp;<code>message</code>&nbsp;，返回一个空数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>message = "this is really a very awesome message", limit = 9
<b>输出：</b>["thi&lt;1/14&gt;","s i&lt;2/14&gt;","s r&lt;3/14&gt;","eal&lt;4/14&gt;","ly &lt;5/14&gt;","a v&lt;6/14&gt;","ery&lt;7/14&gt;"," aw&lt;8/14&gt;","eso&lt;9/14&gt;","me&lt;10/14&gt;"," m&lt;11/14&gt;","es&lt;12/14&gt;","sa&lt;13/14&gt;","ge&lt;14/14&gt;"]
<strong>解释：</strong>
前面 9 个部分分别从 message 中得到 3 个字符。
接下来的 5 个部分分别从 message 中得到 2 个字符。
这个例子中，包含最后一个部分在内，每个部分的长度都为 9 。
可以证明没有办法分割成少于 14 个部分。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>message = "short message", limit = 15
<b>输出：</b>["short mess&lt;1/2&gt;","age&lt;2/2&gt;"]
<strong>解释：</strong>
在给定限制下，字符串可以分成两个部分：
- 第一个部分包含 10 个字符，长度为 15 。
- 第二个部分包含 3 个字符，长度为 8 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= message.length &lt;= 10<sup>4</sup></code></li>
	<li><code>message</code>&nbsp;只包含小写英文字母和&nbsp;<code>' '</code>&nbsp;。</li>
	<li><code>1 &lt;= limit &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举分段数量 + 模拟

我们设字符串 `message` 的长度为 $n$，分段数量为 $k$。

根据题意，如果 $k \gt n$，表示我们可以将字符串划分成超过 $n$ 段，由于字符串长度仅为 $n$，若划分成超过 $n$ 段必然导致有部分段的长度为 $0$，可以删去。因此，我们只需要将 $k$ 的取值范围限制在 $[1,.. n]$ 即可。

从小到大枚举分段数量 $k$，记所有分段中 $a$ 段的长度为 $sa$，所有分段中 $b$ 段的长度为 $sb$，所有分段中符号（包括尖括号和斜杠）的长度为 $sc$。

那么 $sa$ 的值为 ${\textstyle \sum_{j=1}^{k}} len(s_j)$，可以直接通过前缀和求出；而 $sb$ 的值为 $len(str(k)) \times k$；另外 $sc$ 的值为 $3 \times k$。

因此，所有分段剩余可填充的字符数为 $limit\times k - (sa + sb + sc)$，如果该值大于等于 $n$ 则说明可以将字符串划分成 $k$ 段，直接构造答案返回即可。

时间复杂度 $O(n\times \log n)$，其中 $n$ 为字符串 `message` 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        n = len(message)
        sa = 0
        for k in range(1, n + 1):
            sa += len(str(k))
            sb = len(str(k)) * k
            sc = 3 * k
            if limit * k - (sa + sb + sc) >= n:
                ans = []
                i = 0
                for j in range(1, k + 1):
                    tail = f'<{j}/{k}>'
                    t = message[i : i + limit - len(tail)] + tail
                    ans.append(t)
                    i += limit - len(tail)
                return ans
        return []
```

#### Java

```java
class Solution {
    public String[] splitMessage(String message, int limit) {
        int n = message.length();
        int sa = 0;
        String[] ans = new String[0];
        for (int k = 1; k <= n; ++k) {
            int lk = (k + "").length();
            sa += lk;
            int sb = lk * k;
            int sc = 3 * k;
            if (limit * k - (sa + sb + sc) >= n) {
                int i = 0;
                ans = new String[k];
                for (int j = 1; j <= k; ++j) {
                    String tail = String.format("<%d/%d>", j, k);
                    String t = message.substring(i, Math.min(n, i + limit - tail.length())) + tail;
                    ans[j - 1] = t;
                    i += limit - tail.length();
                }
                break;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int sa = 0;
        vector<string> ans;
        for (int k = 1; k <= n; ++k) {
            int lk = to_string(k).size();
            sa += lk;
            int sb = lk * k;
            int sc = 3 * k;
            if (k * limit - (sa + sb + sc) >= n) {
                int i = 0;
                for (int j = 1; j <= k; ++j) {
                    string tail = "<" + to_string(j) + "/" + to_string(k) + ">";
                    string t = message.substr(i, limit - tail.size()) + tail;
                    ans.emplace_back(t);
                    i += limit - tail.size();
                }
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func splitMessage(message string, limit int) (ans []string) {
	n := len(message)
	sa := 0
	for k := 1; k <= n; k++ {
		lk := len(strconv.Itoa(k))
		sa += lk
		sb := lk * k
		sc := 3 * k
		if limit*k-(sa+sb+sc) >= n {
			i := 0
			for j := 1; j <= k; j++ {
				tail := "<" + strconv.Itoa(j) + "/" + strconv.Itoa(k) + ">"
				t := message[i:min(i+limit-len(tail), n)] + tail
				ans = append(ans, t)
				i += limit - len(tail)
			}
			break
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2469. 温度转换](https://leetcode.cn/problems/convert-the-temperature){#2469}

{{< tabs "2469" >}}

{{% tab "python" %}}
```python
class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double[] convertTemperature(double celsius) {
        return new double[] {celsius + 273.15, celsius * 1.8 + 32};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func convertTemperature(celsius float64) []float64 {
	return []float64{celsius + 273.15, celsius*1.8 + 32}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function convertTemperature(celsius: number): number[] {
    return [celsius + 273.15, celsius * 1.8 + 32];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        vec![celsius + 273.15, celsius * 1.8 + 32.0]
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double* ans = malloc(sizeof(double) * 2);
    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.8 + 32;
    *returnSize = 2;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个四舍五入到两位小数的非负浮点数 <code>celsius</code> 来表示温度，以 <strong>摄氏度</strong>（<strong>Celsius</strong>）为单位。</p>

<p>你需要将摄氏度转换为 <strong>开氏度</strong>（<strong>Kelvin</strong>）和 <strong>华氏度</strong>（<strong>Fahrenheit</strong>），并以数组 <code>ans = [kelvin, fahrenheit]</code> 的形式返回结果。</p>

<p>返回数组<em> <code>ans</code></em> 。与实际答案误差不超过 <code>10<sup>-5</sup></code> 的会视为正确答案<strong>。</strong></p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>开氏度 = 摄氏度 + 273.15</code></li>
	<li><code>华氏度 = 摄氏度 * 1.80 + 32.00</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre><strong>输入：</strong>celsius = 36.50
<strong>输出：</strong>[309.65000,97.70000]
<strong>解释：</strong>36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。</pre>

<p><strong>示例 2 ：</strong></p>

<pre><strong>输入：</strong>celsius = 122.11
<strong>输出：</strong>[395.26000,251.79800]
<strong>解释：</strong>122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= celsius &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接根据题意模拟即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]
```

#### Java

```java
class Solution {
    public double[] convertTemperature(double celsius) {
        return new double[] {celsius + 273.15, celsius * 1.8 + 32};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};
```

#### Go

```go
func convertTemperature(celsius float64) []float64 {
	return []float64{celsius + 273.15, celsius*1.8 + 32}
}
```

#### TypeScript

```ts
function convertTemperature(celsius: number): number[] {
    return [celsius + 273.15, celsius * 1.8 + 32];
}
```

#### Rust

```rust
impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        vec![celsius + 273.15, celsius * 1.8 + 32.0]
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double* ans = malloc(sizeof(double) * 2);
    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.8 + 32;
    *returnSize = 2;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
