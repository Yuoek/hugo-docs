---
title: "2970_统计移除递增子数组的数目 I"
date: 2025-10-08T18:39:48+08:00
weight: 8
tags: [二分查找, 前缀和, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 排序, 数学, 数据库, 数组, 数论, 最短路, 枚举, 树, 模拟, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [2970_统计移除递增子数组的数目 I](#2970)
#### [数组](#2970)
#### [双指针](#2970)
#### [二分查找](#2970)
#### [枚举](#2970)
### [2971_找到最大周长的多边形](#2971)
#### [贪心](#2971)
#### [数组](#2971)
#### [前缀和](#2971)
#### [排序](#2971)
### [2972_统计移除递增子数组的数目 II](#2972)
#### [数组](#2972)
#### [双指针](#2972)
#### [二分查找](#2972)
### [2973_树中每个节点放置的金币数目](#2973)
#### [树](#2973)
#### [深度优先搜索](#2973)
#### [动态规划](#2973)
#### [排序](#2973)
#### [堆（优先队列）](#2973)
### [2974_最小数字游戏](#2974)
#### [数组](#2974)
#### [排序](#2974)
#### [模拟](#2974)
#### [堆（优先队列）](#2974)
### [2975_移除栅栏得到的正方形田地的最大面积](#2975)
#### [数组](#2975)
#### [哈希表](#2975)
#### [枚举](#2975)
### [2976_转换字符串的最小成本 I](#2976)
#### [图](#2976)
#### [数组](#2976)
#### [字符串](#2976)
#### [最短路](#2976)
### [2977_转换字符串的最小成本 II](#2977)
#### [图](#2977)
#### [字典树](#2977)
#### [数组](#2977)
#### [字符串](#2977)
#### [动态规划](#2977)
#### [最短路](#2977)
### [2978_对称坐标 🔒](#2978)
#### [数据库](#2978)
### [2979_最贵的无法购买的商品 🔒](#2979)
#### [数学](#2979)
#### [动态规划](#2979)
#### [数论](#2979)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2970_统计移除递增子数组的数目 I
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 枚举
---
### 2971_找到最大周长的多边形
___
#### 贪心
___
#### 数组
___
#### 前缀和
___
#### 排序
---
### 2972_统计移除递增子数组的数目 II
___
#### 数组
___
#### 双指针
___
#### 二分查找
---
### 2973_树中每个节点放置的金币数目
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
___
#### 排序
___
#### 堆（优先队列）
---
### 2974_最小数字游戏
___
#### 数组
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 2975_移除栅栏得到的正方形田地的最大面积
___
#### 数组
___
#### 哈希表
___
#### 枚举
---
### 2976_转换字符串的最小成本 I
___
#### 图
___
#### 数组
___
#### 字符串
___
#### 最短路
---
### 2977_转换字符串的最小成本 II
___
#### 图
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 动态规划
___
#### 最短路
---
### 2978_对称坐标 🔒
___
#### 数据库
---
### 2979_最贵的无法购买的商品 🔒
___
#### 数学
___
#### 动态规划
___
#### 数论
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 堆（优先队列） | 字典树 | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 数论 | 最短路 |
| 枚举 | 树 | 模拟 |
| 深度优先搜索 | 贪心 |  |

# [2970. 统计移除递增子数组的数目 I](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i){#2970}

{{< tabs "2970" >}}

{{% tab "python" %}}
```python
class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        if i == n - 1:
            return n * (n + 1) // 2
        ans = i + 2
        j = n - 1
        while j:
            while i >= 0 and nums[i] >= nums[j]:
                i -= 1
            ans += i + 2
            if nums[j - 1] >= nums[j]:
                break
            j -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int i = 0, n = nums.length;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1) / 2;
        }
        int ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
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
    int incremovableSubarrayCount(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1) / 2;
        }
        int ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
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
func incremovableSubarrayCount(nums []int) int {
	i, n := 0, len(nums)
	for i+1 < n && nums[i] < nums[i+1] {
		i++
	}
	if i == n-1 {
		return n * (n + 1) / 2
	}
	ans := i + 2
	for j := n - 1; j > 0; j-- {
		for i >= 0 && nums[i] >= nums[j] {
			i--
		}
		ans += i + 2
		if nums[j-1] >= nums[j] {
			break
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function incremovableSubarrayCount(nums: number[]): number {
    const n = nums.length;
    let i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1]) {
        i++;
    }
    if (i === n - 1) {
        return (n * (n + 1)) / 2;
    }
    let ans = i + 2;
    for (let j = n - 1; j; --j) {
        while (i >= 0 && nums[i] >= nums[j]) {
            --i;
        }
        ans += i + 2;
        if (nums[j - 1] >= nums[j]) {
            break;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的 <b>正</b>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果 <code>nums</code>&nbsp;的一个子数组满足：移除这个子数组后剩余元素 <strong>严格递增</strong>&nbsp;，那么我们称这个子数组为 <strong>移除递增</strong>&nbsp;子数组。比方说，<code>[5, 3, 4, 6, 7]</code>&nbsp;中的 <code>[3, 4]</code>&nbsp;是一个移除递增子数组，因为移除该子数组后，<code>[5, 3, 4, 6, 7]</code>&nbsp;变为&nbsp;<code>[5, 6, 7]</code>&nbsp;，是严格递增的。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <b>移除递增</b>&nbsp;子数组的总数目。</p>

<p><b>注意</b>&nbsp;，剩余元素为空的数组也视为是递增的。</p>

<p><strong>子数组</strong> 指的是一个数组中一段非空且连续的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>10
<b>解释：</b>10 个移除递增子数组分别为：[1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4] 和 [1,2,3,4]。移除任意一个子数组后，剩余元素都是递增的。注意，空数组不是移除递增子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [6,5,7,8]
<b>输出：</b>7
<b>解释：</b>7<strong>&nbsp;</strong>个移除递增子数组分别为：[5], [6], [5,7], [6,5], [5,7,8], [6,5,7] 和 [6,5,7,8] 。
nums 中只有这 7 个移除递增子数组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [8,7,6,6]
<b>输出：</b>3
<b>解释：</b>3 个移除递增子数组分别为：[8,7,6], [7,6,6] 和 [8,7,6,6] 。注意 [8,7] 不是移除递增子数组因为移除 [8,7] 后 nums 变为 [6,6] ，它不是严格递增的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

根据题目描述，移除一个子数组后，剩余元素严格递增，那么存在以下几种情况：

1. 剩余元素仅包含数组 $nums$ 的前缀（可以为空）；
1. 剩余元素仅包含数组 $nums$ 的后缀；
1. 剩余元素包含数组 $nums$ 的前缀和后缀。

其中第 $2$ 和第 $3$ 种情况可以合并为一种情况，即剩余元素包含数组 $nums$ 的后缀。即一共有以下两种情况：

1. 剩余元素仅包含数组 $nums$ 的前缀（可以为空）；
1. 剩余元素包含数组 $nums$ 的后缀。

我们先考虑第一种情况，即剩余元素仅包含数组 $nums$ 的前缀。我们可以用一个指针 $i$ 指向数组 $nums$ 的最长递增前缀的最后一个元素，即 $nums[0] \lt nums[1] \lt \cdots \lt nums[i]$，那么剩余元素的个数为 $n - i - 1$，其中 $n$ 为数组 $nums$ 的长度。因此，对于这种情况，要使得剩余元素严格递增，我们可以选择移除以下子数组：

1. $nums[i+1,...,n-1]$；
1. $nums[i,...,n-1]$；
1. $nums[i-1,...,n-1]$；
1. $nums[i-2,...,n-1]$；
1. $\cdots$；
1. $nums[0,...,n-1]$。

这一共有 $i + 2$ 种情况，因此对于这种情况，移除递增子数组的数目为 $i + 2$。

再考虑第二种情况，即剩余元素包含数组 $nums$ 的后缀。我们可以用一个指针 $j$ 指向数组 $nums$ 的递增后缀的第一个元素，我们在 $[n - 1,...,1]$ 的范围内枚举 $j$ 作为递增后缀的第一个元素，每一次，我们需要移动指针 $i$ 使得 $nums[i] \lt nums[j]$，那么移除递增子数组的数组增加 $i + 2$。当 $nums[j - 1] \ge nums[j]$ 时，我们停止枚举，因为此时后缀不是严格递增。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        if i == n - 1:
            return n * (n + 1) // 2
        ans = i + 2
        j = n - 1
        while j:
            while i >= 0 and nums[i] >= nums[j]:
                i -= 1
            ans += i + 2
            if nums[j - 1] >= nums[j]:
                break
            j -= 1
        return ans
```

#### Java

```java
class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int i = 0, n = nums.length;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1) / 2;
        }
        int ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
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
    int incremovableSubarrayCount(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1) / 2;
        }
        int ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func incremovableSubarrayCount(nums []int) int {
	i, n := 0, len(nums)
	for i+1 < n && nums[i] < nums[i+1] {
		i++
	}
	if i == n-1 {
		return n * (n + 1) / 2
	}
	ans := i + 2
	for j := n - 1; j > 0; j-- {
		for i >= 0 && nums[i] >= nums[j] {
			i--
		}
		ans += i + 2
		if nums[j-1] >= nums[j] {
			break
		}
	}
	return ans
}
```

#### TypeScript

```ts
function incremovableSubarrayCount(nums: number[]): number {
    const n = nums.length;
    let i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1]) {
        i++;
    }
    if (i === n - 1) {
        return (n * (n + 1)) / 2;
    }
    let ans = i + 2;
    for (let j = n - 1; j; --j) {
        while (i >= 0 && nums[i] >= nums[j]) {
            --i;
        }
        ans += i + 2;
        if (nums[j - 1] >= nums[j]) {
            break;
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

# [2971. 找到最大周长的多边形](https://leetcode.cn/problems/find-polygon-with-the-largest-perimeter){#2971}

{{< tabs "2971" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        s = list(accumulate(nums, initial=0))
        ans = -1
        for k in range(3, len(nums) + 1):
            if s[k - 1] > nums[k - 1]:
                ans = max(ans, s[k])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        long ans = -1;
        for (int k = 3; k <= n; ++k) {
            if (s[k - 1] > nums[k - 1]) {
                ans = Math.max(ans, s[k]);
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
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        long long ans = -1;
        for (int k = 3; k <= n; ++k) {
            if (s[k - 1] > nums[k - 1]) {
                ans = max(ans, s[k]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestPerimeter(nums []int) int64 {
	sort.Ints(nums)
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	ans := -1
	for k := 3; k <= n; k++ {
		if s[k-1] > nums[k-1] {
			ans = max(ans, s[k])
		}
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestPerimeter(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let ans = -1;
    for (let k = 3; k <= n; ++k) {
        if (s[k - 1] > nums[k - 1]) {
            ans = Math.max(ans, s[k]);
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

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>正</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p><strong>多边形</strong>&nbsp;指的是一个至少有 <code>3</code>&nbsp;条边的封闭二维图形。多边形的 <strong>最长边</strong>&nbsp;一定 <strong>小于</strong>&nbsp;所有其他边长度之和。</p>

<p>如果你有&nbsp;<code>k</code>&nbsp;（<code>k &gt;= 3</code>）个&nbsp;<strong>正</strong>&nbsp;数&nbsp;<code>a<sub>1</sub></code>，<code>a<sub>2</sub></code>，<code>a<sub>3</sub></code>, ...，<code>a<sub>k</sub></code> 满足&nbsp;<code>a<sub>1</sub> &lt;= a<sub>2</sub> &lt;= a<sub>3</sub> &lt;= ... &lt;= a<sub>k</sub></code> <strong>且</strong> <code>a<sub>1</sub> + a<sub>2</sub> + a<sub>3</sub> + ... + a<sub>k-1</sub> &gt; a<sub>k</sub></code><sub>&nbsp;</sub>，那么 <strong>一定</strong>&nbsp;存在一个&nbsp;<code>k</code>&nbsp;条边的多边形，每条边的长度分别为&nbsp;<code>a<sub>1</sub></code>&nbsp;，<code>a<sub>2</sub></code>&nbsp;，<code>a<sub>3</sub></code>&nbsp;，&nbsp;...，<code>a<sub>k</sub></code>&nbsp;。</p>

<p>一个多边形的 <strong>周长</strong>&nbsp;指的是它所有边之和。</p>

<p>请你返回从 <code>nums</code>&nbsp;中可以构造的 <strong>多边形&nbsp;</strong>的 <strong>最大周长</strong>&nbsp;。如果不能构造出任何多边形，请你返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [5,5,5]
<b>输出：</b>15
<b>解释：</b>nums 中唯一可以构造的多边形为三角形，每条边的长度分别为 5 ，5 和 5 ，周长为 5 + 5 + 5 = 15 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,12,1,2,5,50,3]
<b>输出：</b>12
<b>解释：</b>最大周长多边形为五边形，每条边的长度分别为 1 ，1 ，2 ，3 和 5 ，周长为 1 + 1 + 2 + 3 + 5 = 12 。
我们无法构造一个包含变长为 12 或者 50 的多边形，因为其他边之和没法大于两者中的任何一个。
所以最大周长为 12 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [5,5,50]
<b>输出：</b>-1
<b>解释：</b>无法构造任何多边形，因为多边形至少要有 3 条边且 50 &gt; 5 + 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和

我们可以将数组 $nums$ 排序，然后定义一个答案变量 $ans$，初始值为 $-1$。

接下来，我们在 $[3, n]$ 的范围内枚举最长边 $a_k$，如果 $a_1 + a_2 + \cdots + a_{k-1} > a_k$，那么就可以构成一个周长为 $a_1 + a_2 + \cdots + a_k$ 的多边形。这里，我们可以使用前缀和数组 $s$，其中 $s_i = a_1 + a_2 + \cdots + a_i$，那么 $a_1 + a_2 + \cdots + a_{k-1} = s_{k-1}$，判断是否 $s_{k-1} > a_k$，如果是，那么更新答案 $ans = \max(ans, s_k)$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        s = list(accumulate(nums, initial=0))
        ans = -1
        for k in range(3, len(nums) + 1):
            if s[k - 1] > nums[k - 1]:
                ans = max(ans, s[k])
        return ans
```

#### Java

```java
class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        long ans = -1;
        for (int k = 3; k <= n; ++k) {
            if (s[k - 1] > nums[k - 1]) {
                ans = Math.max(ans, s[k]);
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
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        long long ans = -1;
        for (int k = 3; k <= n; ++k) {
            if (s[k - 1] > nums[k - 1]) {
                ans = max(ans, s[k]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestPerimeter(nums []int) int64 {
	sort.Ints(nums)
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	ans := -1
	for k := 3; k <= n; k++ {
		if s[k-1] > nums[k-1] {
			ans = max(ans, s[k])
		}
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function largestPerimeter(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let ans = -1;
    for (let k = 3; k <= n; ++k) {
        if (s[k - 1] > nums[k - 1]) {
            ans = Math.max(ans, s[k]);
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

# [2972. 统计移除递增子数组的数目 II](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-ii){#2972}

{{< tabs "2972" >}}

{{% tab "python" %}}
```python
class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        if i == n - 1:
            return n * (n + 1) // 2
        ans = i + 2
        j = n - 1
        while j:
            while i >= 0 and nums[i] >= nums[j]:
                i -= 1
            ans += i + 2
            if nums[j - 1] >= nums[j]:
                break
            j -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long incremovableSubarrayCount(int[] nums) {
        int i = 0, n = nums.length;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1L) / 2;
        }
        long ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
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
    long long incremovableSubarrayCount(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1LL) / 2;
        }
        long long ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
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
func incremovableSubarrayCount(nums []int) int64 {
	i, n := 0, len(nums)
	for i+1 < n && nums[i] < nums[i+1] {
		i++
	}
	if i == n-1 {
		return int64(n * (n + 1) / 2)
	}
	ans := int64(i + 2)
	for j := n - 1; j > 0; j-- {
		for i >= 0 && nums[i] >= nums[j] {
			i--
		}
		ans += int64(i + 2)
		if nums[j-1] >= nums[j] {
			break
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function incremovableSubarrayCount(nums: number[]): number {
    const n = nums.length;
    let i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1]) {
        i++;
    }
    if (i === n - 1) {
        return (n * (n + 1)) / 2;
    }
    let ans = i + 2;
    for (let j = n - 1; j; --j) {
        while (i >= 0 && nums[i] >= nums[j]) {
            --i;
        }
        ans += i + 2;
        if (nums[j - 1] >= nums[j]) {
            break;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的 <b>正</b>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果 <code>nums</code>&nbsp;的一个子数组满足：移除这个子数组后剩余元素 <strong>严格递增</strong>&nbsp;，那么我们称这个子数组为 <strong>移除递增</strong>&nbsp;子数组。比方说，<code>[5, 3, 4, 6, 7]</code>&nbsp;中的 <code>[3, 4]</code>&nbsp;是一个移除递增子数组，因为移除该子数组后，<code>[5, 3, 4, 6, 7]</code>&nbsp;变为&nbsp;<code>[5, 6, 7]</code>&nbsp;，是严格递增的。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <b>移除递增</b>&nbsp;子数组的总数目。</p>

<p><b>注意</b>&nbsp;，剩余元素为空的数组也视为是递增的。</p>

<p><strong>子数组</strong> 指的是一个数组中一段连续的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>10
<b>解释：</b>10 个移除递增子数组分别为：[1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4] 和 [1,2,3,4]。移除任意一个子数组后，剩余元素都是递增的。注意，空数组不是移除递增子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [6,5,7,8]
<b>输出：</b>7
<b>解释：</b>7<strong>&nbsp;</strong>个移除递增子数组分别为：[5], [6], [5,7], [6,5], [5,7,8], [6,5,7] 和 [6,5,7,8] 。
nums 中只有这 7 个移除递增子数组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [8,7,6,6]
<b>输出：</b>3
<b>解释：</b>3 个移除递增子数组分别为：[8,7,6], [7,6,6] 和 [8,7,6,6] 。注意 [8,7] 不是移除递增子数组因为移除 [8,7] 后 nums 变为 [6,6] ，它不是严格递增的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

根据题目描述，移除一个子数组后，剩余元素严格递增，那么存在以下几种情况：

1. 剩余元素仅包含数组 $nums$ 的前缀（可以为空）；
1. 剩余元素仅包含数组 $nums$ 的后缀；
1. 剩余元素包含数组 $nums$ 的前缀和后缀。

其中第 $2$ 和第 $3$ 种情况可以合并为一种情况，即剩余元素包含数组 $nums$ 的后缀。即一共有以下两种情况：

1. 剩余元素仅包含数组 $nums$ 的前缀（可以为空）；
1. 剩余元素包含数组 $nums$ 的后缀。

我们先考虑第一种情况，即剩余元素仅包含数组 $nums$ 的前缀。我们可以用一个指针 $i$ 指向数组 $nums$ 的最长递增前缀的最后一个元素，即 $nums[0] \lt nums[1] \lt \cdots \lt nums[i]$，那么剩余元素的个数为 $n - i - 1$，其中 $n$ 为数组 $nums$ 的长度。因此，对于这种情况，要使得剩余元素严格递增，我们可以选择移除以下子数组：

1. $nums[i+1,...,n-1]$；
1. $nums[i,...,n-1]$；
1. $nums[i-1,...,n-1]$；
1. $nums[i-2,...,n-1]$；
1. $\cdots$；
1. $nums[0,...,n-1]$。

这一共有 $i + 2$ 种情况，因此对于这种情况，移除递增子数组的数目为 $i + 2$。

再考虑第二种情况，即剩余元素包含数组 $nums$ 的后缀。我们可以用一个指针 $j$ 指向数组 $nums$ 的递增后缀的第一个元素，我们在 $[n - 1,...,1]$ 的范围内枚举 $j$ 作为递增后缀的第一个元素，每一次，我们需要移动指针 $i$ 使得 $nums[i] \lt nums[j]$，那么移除递增子数组的数组增加 $i + 2$。当 $nums[j - 1] \ge nums[j]$ 时，我们停止枚举，因为此时后缀不是严格递增。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        if i == n - 1:
            return n * (n + 1) // 2
        ans = i + 2
        j = n - 1
        while j:
            while i >= 0 and nums[i] >= nums[j]:
                i -= 1
            ans += i + 2
            if nums[j - 1] >= nums[j]:
                break
            j -= 1
        return ans
```

#### Java

```java
class Solution {
    public long incremovableSubarrayCount(int[] nums) {
        int i = 0, n = nums.length;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1L) / 2;
        }
        long ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
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
    long long incremovableSubarrayCount(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1LL) / 2;
        }
        long long ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func incremovableSubarrayCount(nums []int) int64 {
	i, n := 0, len(nums)
	for i+1 < n && nums[i] < nums[i+1] {
		i++
	}
	if i == n-1 {
		return int64(n * (n + 1) / 2)
	}
	ans := int64(i + 2)
	for j := n - 1; j > 0; j-- {
		for i >= 0 && nums[i] >= nums[j] {
			i--
		}
		ans += int64(i + 2)
		if nums[j-1] >= nums[j] {
			break
		}
	}
	return ans
}
```

#### TypeScript

```ts
function incremovableSubarrayCount(nums: number[]): number {
    const n = nums.length;
    let i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1]) {
        i++;
    }
    if (i === n - 1) {
        return (n * (n + 1)) / 2;
    }
    let ans = i + 2;
    for (let j = n - 1; j; --j) {
        while (i >= 0 && nums[i] >= nums[j]) {
            --i;
        }
        ans += i + 2;
        if (nums[j - 1] >= nums[j]) {
            break;
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

# [2973. 树中每个节点放置的金币数目](https://leetcode.cn/problems/find-number-of-coins-to-place-in-tree-nodes){#2973}

{{< tabs "2973" >}}

{{% tab "python" %}}
```python
class Solution:
    def placedCoins(self, edges: List[List[int]], cost: List[int]) -> List[int]:
        def dfs(a: int, fa: int) -> List[int]:
            res = [cost[a]]
            for b in g[a]:
                if b != fa:
                    res.extend(dfs(b, a))
            res.sort()
            if len(res) >= 3:
                ans[a] = max(res[-3] * res[-2] * res[-1], res[0] * res[1] * res[-1], 0)
            if len(res) > 5:
                res = res[:2] + res[-3:]
            return res

        n = len(cost)
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = [1] * n
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] cost;
    private List<Integer>[] g;
    private long[] ans;

    public long[] placedCoins(int[][] edges, int[] cost) {
        int n = cost.length;
        this.cost = cost;
        ans = new long[n];
        g = new List[n];
        Arrays.fill(ans, 1);
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private List<Integer> dfs(int a, int fa) {
        List<Integer> res = new ArrayList<>();
        res.add(cost[a]);
        for (int b : g[a]) {
            if (b != fa) {
                res.addAll(dfs(b, a));
            }
        }
        Collections.sort(res);
        int m = res.size();
        if (m >= 3) {
            long x = (long) res.get(m - 1) * res.get(m - 2) * res.get(m - 3);
            long y = (long) res.get(0) * res.get(1) * res.get(m - 1);
            ans[a] = Math.max(0, Math.max(x, y));
        }
        if (m >= 5) {
            res = List.of(res.get(0), res.get(1), res.get(m - 3), res.get(m - 2), res.get(m - 1));
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<long long> ans(n, 1);
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<vector<int>(int, int)> dfs = [&](int a, int fa) -> vector<int> {
            vector<int> res = {cost[a]};
            for (int b : g[a]) {
                if (b != fa) {
                    auto t = dfs(b, a);
                    res.insert(res.end(), t.begin(), t.end());
                }
            }
            sort(res.begin(), res.end());
            int m = res.size();
            if (m >= 3) {
                long long x = 1LL * res[m - 1] * res[m - 2] * res[m - 3];
                long long y = 1LL * res[0] * res[1] * res[m - 1];
                ans[a] = max({0LL, x, y});
            }
            if (m >= 5) {
                res = {res[0], res[1], res[m - 1], res[m - 2], res[m - 3]};
            }
            return res;
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func placedCoins(edges [][]int, cost []int) []int64 {
	n := len(cost)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int64, n)
	for i := range ans {
		ans[i] = int64(1)
	}
	var dfs func(a, fa int) []int
	dfs = func(a, fa int) []int {
		res := []int{cost[a]}
		for _, b := range g[a] {
			if b != fa {
				res = append(res, dfs(b, a)...)
			}
		}
		sort.Ints(res)
		m := len(res)
		if m >= 3 {
			x := res[m-1] * res[m-2] * res[m-3]
			y := res[0] * res[1] * res[m-1]
			ans[a] = max(0, int64(x), int64(y))
		}
		if m >= 5 {
			res = append(res[:2], res[m-3:]...)
		}
		return res
	}
	dfs(0, -1)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function placedCoins(edges: number[][], cost: number[]): number[] {
    const n = cost.length;
    const ans: number[] = Array(n).fill(1);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = (a: number, fa: number): number[] => {
        const res: number[] = [cost[a]];
        for (const b of g[a]) {
            if (b !== fa) {
                res.push(...dfs(b, a));
            }
        }
        res.sort((a, b) => a - b);
        const m = res.length;
        if (m >= 3) {
            const x = res[m - 1] * res[m - 2] * res[m - 3];
            const y = res[0] * res[1] * res[m - 1];
            ans[a] = Math.max(0, x, y);
        }
        if (m > 5) {
            res.splice(2, m - 5);
        }
        return res;
    };
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵&nbsp;<code>n</code>&nbsp;个节点的&nbsp;<strong>无向</strong>&nbsp;树，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，树的根节点在节点&nbsp;<code>0</code>&nbsp;处。同时给你一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。</p>

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>cost</code>&nbsp;，其中&nbsp;<code>cost[i]</code>&nbsp;是第 <code>i</code>&nbsp;个节点的 <b>开销</b>&nbsp;。</p>

<p>你需要在树中每个节点都放置金币，在节点 <code>i</code>&nbsp;处的金币数目计算方法如下：</p>

<ul>
	<li>如果节点 <code>i</code>&nbsp;对应的子树中的节点数目小于&nbsp;<code>3</code>&nbsp;，那么放&nbsp;<code>1</code>&nbsp;个金币。</li>
	<li>否则，计算节点 <code>i</code> 对应的子树内 <code>3</code> 个不同节点的开销乘积的 <strong>最大值</strong> ，并在节点 <code>i</code> 处放置对应数目的金币。如果最大乘积是 <b>负数</b>&nbsp;，那么放置 <code>0</code>&nbsp;个金币。</li>
</ul>

<p>请你返回一个长度为 <code>n</code>&nbsp;的数组<em>&nbsp;</em><code>coin</code>&nbsp;，<code>coin[i]</code>是节点&nbsp;<code>i</code>&nbsp;处的金币数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2973.Find%20Number%20of%20Coins%20to%20Place%20in%20Tree%20Nodes/images/screenshot-2023-11-10-012641.png" style="width: 600px; height: 233px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[0,3],[0,4],[0,5]], cost = [1,2,3,4,5,6]
<b>输出：</b>[120,1,1,1,1,1]
<b>解释：</b>在节点 0 处放置 6 * 5 * 4 = 120 个金币。所有其他节点都是叶子节点，子树中只有 1 个节点，所以其他每个节点都放 1 个金币。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2973.Find%20Number%20of%20Coins%20to%20Place%20in%20Tree%20Nodes/images/screenshot-2023-11-10-012614.png" style="width: 800px; height: 374px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]], cost = [1,4,2,3,5,7,8,-4,2]
<b>输出：</b>[280,140,32,1,1,1,1,1,1]
<b>解释：</b>每个节点放置的金币数分别为：
- 节点 0 处放置 8 * 7 * 5 = 280 个金币。
- 节点 1 处放置 7 * 5 * 4 = 140 个金币。
- 节点 2 处放置 8 * 2 * 2 = 32 个金币。
- 其他节点都是叶子节点，子树内节点数目为 1 ，所以其他每个节点都放 1 个金币。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2973.Find%20Number%20of%20Coins%20to%20Place%20in%20Tree%20Nodes/images/screenshot-2023-11-10-012513.png" style="width: 300px; height: 277px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2]], cost = [1,2,-2]
<b>输出：</b>[0,1,1]
<b>解释：</b>节点 1 和 2 都是叶子节点，子树内节点数目为 1 ，各放置 1 个金币。节点 0 处唯一的开销乘积是 2 * 1 * -2 = -4 。所以在节点 0 处放置 0 个金币。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>cost.length == n</code></li>
	<li><code>1 &lt;= |cost[i]| &lt;= 10<sup>4</sup></code></li>
	<li><code>edges</code>&nbsp;一定是一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 排序

根据题目描述，每个节点 $a$ 的放置的金币数有两种情况：

-   如果节点 $a$ 对应的子树中的节点数目小于 $3$，那么放 $1$ 个金币；
-   如果节点 $a$ 对应的子树中的节点数目大于等于 $3$，那么我们需要取出子树中的 $3$ 个不同节点，计算它们的开销乘积的最大值，然后在节点 $a$ 处放置对应数目的金币，如果最大乘积是负数，那么放置 $0$ 个金币。

第一种情况比较简单，我们只需要在遍历的过程中，统计每个节点的子树中的节点数目即可。

而对于第二种情况，如果开销都是正数，那么应该取开销最大的 $3$ 个节点；如果开销中有负数，那么应该取开销最小的 $2$ 个节点和开销最大的 $1$ 个节点。因此，我们需要维护每个子树最小的 $2$ 个开销和最大的 $3$ 个开销。

我们先根据题目给定的二维数组 $edges$ 构建邻接表 $g$，其中 $g[a]$ 表示节点 $a$ 的所有邻居节点。

接下来，我们设计一个函数 $dfs(a, fa)$，该函数返回一个数组 $res$，其中存储了节点 $a$ 的子树中最小的 $2$ 个开销和最大的 $3$ 个开销（可能不足 $5$ 个）。

在函数 $dfs(a, fa)$ 中，我们将节点 $a$ 的开销 $cost[a]$ 加入数组 $res$ 中，然后遍历节点 $a$ 的所有邻居节点 $b$，如果 $b$ 不是节点 $a$ 的父节点 $fa$，那么我们将 $dfs(b, a)$ 的结果加入数组 $res$ 中。

然后，我们对数组 $res$ 进行排序，然后根据数组 $res$ 的长度 $m$ 计算节点 $a$ 的放置金币数目，更新 $ans[a]$：

-   如果 $m \ge 3$，那么节点 $a$ 的放置金币数目为 $\max(0, res[m - 1] \times res[m - 2] \times res[m - 3], res[0] \times res[1] \times res[m - 1])$，否则节点 $a$ 的放置金币数目为 $1$；
-   如果 $m > 5$，那么我们只需要保留数组 $res$ 的前 $2$ 个元素和后 $3$ 个元素。

最后，我们调用函数 $dfs(0, -1)$，并且返回答案数组 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是节点的数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def placedCoins(self, edges: List[List[int]], cost: List[int]) -> List[int]:
        def dfs(a: int, fa: int) -> List[int]:
            res = [cost[a]]
            for b in g[a]:
                if b != fa:
                    res.extend(dfs(b, a))
            res.sort()
            if len(res) >= 3:
                ans[a] = max(res[-3] * res[-2] * res[-1], res[0] * res[1] * res[-1], 0)
            if len(res) > 5:
                res = res[:2] + res[-3:]
            return res

        n = len(cost)
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = [1] * n
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private int[] cost;
    private List<Integer>[] g;
    private long[] ans;

    public long[] placedCoins(int[][] edges, int[] cost) {
        int n = cost.length;
        this.cost = cost;
        ans = new long[n];
        g = new List[n];
        Arrays.fill(ans, 1);
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private List<Integer> dfs(int a, int fa) {
        List<Integer> res = new ArrayList<>();
        res.add(cost[a]);
        for (int b : g[a]) {
            if (b != fa) {
                res.addAll(dfs(b, a));
            }
        }
        Collections.sort(res);
        int m = res.size();
        if (m >= 3) {
            long x = (long) res.get(m - 1) * res.get(m - 2) * res.get(m - 3);
            long y = (long) res.get(0) * res.get(1) * res.get(m - 1);
            ans[a] = Math.max(0, Math.max(x, y));
        }
        if (m >= 5) {
            res = List.of(res.get(0), res.get(1), res.get(m - 3), res.get(m - 2), res.get(m - 1));
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<long long> ans(n, 1);
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<vector<int>(int, int)> dfs = [&](int a, int fa) -> vector<int> {
            vector<int> res = {cost[a]};
            for (int b : g[a]) {
                if (b != fa) {
                    auto t = dfs(b, a);
                    res.insert(res.end(), t.begin(), t.end());
                }
            }
            sort(res.begin(), res.end());
            int m = res.size();
            if (m >= 3) {
                long long x = 1LL * res[m - 1] * res[m - 2] * res[m - 3];
                long long y = 1LL * res[0] * res[1] * res[m - 1];
                ans[a] = max({0LL, x, y});
            }
            if (m >= 5) {
                res = {res[0], res[1], res[m - 1], res[m - 2], res[m - 3]};
            }
            return res;
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func placedCoins(edges [][]int, cost []int) []int64 {
	n := len(cost)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int64, n)
	for i := range ans {
		ans[i] = int64(1)
	}
	var dfs func(a, fa int) []int
	dfs = func(a, fa int) []int {
		res := []int{cost[a]}
		for _, b := range g[a] {
			if b != fa {
				res = append(res, dfs(b, a)...)
			}
		}
		sort.Ints(res)
		m := len(res)
		if m >= 3 {
			x := res[m-1] * res[m-2] * res[m-3]
			y := res[0] * res[1] * res[m-1]
			ans[a] = max(0, int64(x), int64(y))
		}
		if m >= 5 {
			res = append(res[:2], res[m-3:]...)
		}
		return res
	}
	dfs(0, -1)
	return ans
}
```

#### TypeScript

```ts
function placedCoins(edges: number[][], cost: number[]): number[] {
    const n = cost.length;
    const ans: number[] = Array(n).fill(1);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = (a: number, fa: number): number[] => {
        const res: number[] = [cost[a]];
        for (const b of g[a]) {
            if (b !== fa) {
                res.push(...dfs(b, a));
            }
        }
        res.sort((a, b) => a - b);
        const m = res.length;
        if (m >= 3) {
            const x = res[m - 1] * res[m - 2] * res[m - 3];
            const y = res[0] * res[1] * res[m - 1];
            ans[a] = Math.max(0, x, y);
        }
        if (m > 5) {
            res.splice(2, m - 5);
        }
        return res;
    };
    dfs(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2974. 最小数字游戏](https://leetcode.cn/problems/minimum-number-game){#2974}

{{< tabs "2974" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        for i in range(0, len(nums), 2):
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i += 2) {
            int t = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = t;
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberGame(nums []int) []int {
	sort.Ints(nums)
	for i := 0; i < len(nums); i += 2 {
		nums[i], nums[i+1] = nums[i+1], nums[i]
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberGame(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length; i += 2) {
        [nums[i], nums[i + 1]] = [nums[i + 1], nums[i]];
    }
    return nums;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_game(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort_unstable();
        for i in (0..nums.len()).step_by(2) {
            nums.swap(i, i + 1);
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

<p>你有一个下标从 <strong>0</strong> 开始、长度为 <strong>偶数</strong> 的整数数组 <code>nums</code> ，同时还有一个空数组 <code>arr</code> 。Alice 和 Bob 决定玩一个游戏，游戏中每一轮 Alice 和 Bob 都会各自执行一次操作。游戏规则如下：</p>

<ul>
	<li>每一轮，Alice 先从 <code>nums</code> 中移除一个<strong> 最小</strong> 元素，然后 Bob 执行同样的操作。</li>
	<li>接着，Bob 会将移除的元素添加到数组 <code>arr</code> 中，然后 Alice 也执行同样的操作。</li>
	<li>游戏持续进行，直到 <code>nums</code> 变为空。</li>
</ul>

<p>返回结果数组 <code>arr</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,2,3]
<strong>输出：</strong>[3,2,5,4]
<strong>解释：</strong>第一轮，Alice 先移除 2 ，然后 Bob 移除 3 。然后 Bob 先将 3 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [3,2] 。
第二轮开始时，nums = [5,4] 。Alice 先移除 4 ，然后 Bob 移除 5 。接着他们都将元素添加到 arr 中，arr 变为 [3,2,5,4] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,5]
<strong>输出：</strong>[5,2]
<strong>解释：</strong>第一轮，Alice 先移除 2 ，然后 Bob 移除 5 。然后 Bob 先将 5 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [5,2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟 + 优先队列（小根堆）

我们可以将数组 $\textit{nums}$ 中的元素依次放入一个小根堆中，每次从小根堆中取出两个元素 $a$ 和 $b$，然后依次将 $b$ 和 $a$ 放入答案数组中，直到小根堆为空。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        heapify(nums)
        ans = []
        while nums:
            a, b = heappop(nums), heappop(nums)
            ans.append(b)
            ans.append(a)
        return ans
```

#### Java

```java
class Solution {
    public int[] numberGame(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : nums) {
            pq.offer(x);
        }
        int[] ans = new int[nums.length];
        int i = 0;
        while (!pq.isEmpty()) {
            int a = pq.poll();
            ans[i++] = pq.poll();
            ans[i++] = a;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        vector<int> ans;
        while (pq.size()) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans.push_back(b);
            ans.push_back(a);
        }
        return ans;
    }
};
```

#### Go

```go
func numberGame(nums []int) (ans []int) {
	pq := &hp{nums}
	heap.Init(pq)
	for pq.Len() > 0 {
		a := heap.Pop(pq).(int)
		b := heap.Pop(pq).(int)
		ans = append(ans, b)
		ans = append(ans, a)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Pop() interface{} {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[0 : n-1]
	return x
}
func (h *hp) Push(x interface{}) {
	h.IntSlice = append(h.IntSlice, x.(int))
}
```

#### TypeScript

```ts
function numberGame(nums: number[]): number[] {
    const pq = new MinPriorityQueue();
    for (const x of nums) {
        pq.enqueue(x);
    }
    const ans: number[] = [];
    while (pq.size()) {
        const a = pq.dequeue().element;
        const b = pq.dequeue().element;
        ans.push(b, a);
    }
    return ans;
}
```

#### Rust

```rust
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn number_game(nums: Vec<i32>) -> Vec<i32> {
        let mut pq = BinaryHeap::new();

        for &x in &nums {
            pq.push(Reverse(x));
        }

        let mut ans = Vec::new();

        while let Some(Reverse(a)) = pq.pop() {
            if let Some(Reverse(b)) = pq.pop() {
                ans.push(b);
                ans.push(a);
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 交换

我们可以将数组 $\textit{nums}$ 排序，然后遍历数组，每次交换相邻的两个元素，直到遍历结束，返回交换后的数组。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        for i in range(0, len(nums), 2):
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
        return nums
```

#### Java

```java
class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i += 2) {
            int t = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = t;
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};
```

#### Go

```go
func numberGame(nums []int) []int {
	sort.Ints(nums)
	for i := 0; i < len(nums); i += 2 {
		nums[i], nums[i+1] = nums[i+1], nums[i]
	}
	return nums
}
```

#### TypeScript

```ts
function numberGame(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length; i += 2) {
        [nums[i], nums[i + 1]] = [nums[i + 1], nums[i]];
    }
    return nums;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_game(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort_unstable();
        for i in (0..nums.len()).step_by(2) {
            nums.swap(i, i + 1);
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

# [2975. 移除栅栏得到的正方形田地的最大面积](https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field){#2975}

{{< tabs "2975" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeSquareArea(
        self, m: int, n: int, hFences: List[int], vFences: List[int]
    ) -> int:
        def f(nums: List[int], k: int) -> Set[int]:
            nums.extend([1, k])
            nums.sort()
            return {b - a for a, b in combinations(nums, 2)}

        mod = 10**9 + 7
        hs = f(hFences, m)
        vs = f(vFences, n)
        ans = max(hs & vs, default=0)
        return ans**2 % mod if ans else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Set<Integer> hs = f(hFences, m);
        Set<Integer> vs = f(vFences, n);
        hs.retainAll(vs);
        int ans = -1;
        final int mod = (int) 1e9 + 7;
        for (int x : hs) {
            ans = Math.max(ans, x);
        }
        return ans > 0 ? (int) (1L * ans * ans % mod) : -1;
    }

    private Set<Integer> f(int[] nums, int k) {
        int n = nums.length;
        nums = Arrays.copyOf(nums, n + 2);
        nums[n] = 1;
        nums[n + 1] = k;
        Arrays.sort(nums);
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                s.add(nums[i] - nums[j]);
            }
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto f = [](vector<int>& nums, int k) {
            nums.push_back(k);
            nums.push_back(1);
            sort(nums.begin(), nums.end());
            unordered_set<int> s;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    s.insert(nums[i] - nums[j]);
                }
            }
            return s;
        };
        auto hs = f(hFences, m);
        auto vs = f(vFences, n);
        int ans = 0;
        for (int h : hs) {
            if (vs.count(h)) {
                ans = max(ans, h);
            }
        }
        const int mod = 1e9 + 7;
        return ans > 0 ? 1LL * ans * ans % mod : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximizeSquareArea(m int, n int, hFences []int, vFences []int) int {
	f := func(nums []int, k int) map[int]bool {
		nums = append(nums, 1, k)
		sort.Ints(nums)
		s := map[int]bool{}
		for i := 0; i < len(nums); i++ {
			for j := 0; j < i; j++ {
				s[nums[i]-nums[j]] = true
			}
		}
		return s
	}
	hs := f(hFences, m)
	vs := f(vFences, n)
	ans := 0
	for h := range hs {
		if vs[h] {
			ans = max(ans, h)
		}
	}
	if ans > 0 {
		return ans * ans % (1e9 + 7)
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeSquareArea(m: number, n: number, hFences: number[], vFences: number[]): number {
    const f = (nums: number[], k: number): Set<number> => {
        nums.push(1, k);
        nums.sort((a, b) => a - b);
        const s: Set<number> = new Set();
        for (let i = 0; i < nums.length; ++i) {
            for (let j = 0; j < i; ++j) {
                s.add(nums[i] - nums[j]);
            }
        }
        return s;
    };
    const hs = f(hFences, m);
    const vs = f(vFences, n);
    let ans = 0;
    for (const h of hs) {
        if (vs.has(h)) {
            ans = Math.max(ans, h);
        }
    }
    return ans ? Number(BigInt(ans) ** 2n % 1000000007n) : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个大型的 <code>(m - 1) x (n - 1)</code> 矩形田地，其两个对角分别是 <code>(1, 1)</code> 和 <code>(m, n)</code> ，田地内部有一些水平栅栏和垂直栅栏，分别由数组 <code>hFences</code> 和 <code>vFences</code> 给出。</p>

<p>水平栅栏为坐标 <code>(hFences[i], 1)</code> 到 <code>(hFences[i], n)</code>，垂直栅栏为坐标 <code>(1, vFences[i])</code> 到 <code>(m, vFences[i])</code> 。</p>

<p>返回通过<strong> 移除 </strong>一些栅栏（<strong>可能不移除</strong>）所能形成的最大面积的<strong> 正方形 </strong>田地的面积，或者如果无法形成正方形田地则返回 <code>-1</code>。</p>

<p>由于答案可能很大，所以请返回结果对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的值。</p>

<p><strong>注意：</strong>田地外围两个水平栅栏（坐标 <code>(1, 1)</code> 到 <code>(1, n)</code> 和坐标 <code>(m, 1)</code> 到 <code>(m, n)</code> ）以及两个垂直栅栏（坐标 <code>(1, 1)</code> 到 <code>(m, 1)</code> 和坐标 <code>(1, n)</code> 到 <code>(m, n)</code> ）所包围。这些栅栏<strong> 不能</strong> 被移除。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2975.Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/images/screenshot-from-2023-11-05-22-40-25.png" /></p>

<pre>
<strong>输入：</strong>m = 4, n = 3, hFences = [2,3], vFences = [2]
<strong>输出：</strong>4
<strong>解释：</strong>移除位于 2 的水平栅栏和位于 2 的垂直栅栏将得到一个面积为 4 的正方形田地。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2975.Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/images/maxsquareareaexample1.png" style="width: 285px; height: 242px;" /></p>

<pre>
<strong>输入：</strong>m = 6, n = 7, hFences = [2], vFences = [4]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明无法通过移除栅栏形成正方形田地。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= m, n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= hFences.length, vFences.length &lt;= 600</code></li>
	<li><code>1 &lt; hFences[i] &lt; m</code></li>
	<li><code>1 &lt; vFences[i] &lt; n</code></li>
	<li><code>hFences</code> 和 <code>vFences</code> 中的元素是唯一的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举 $\textit{hFences}$ 中的任意两条水平栅栏 $a$ 和 $b$，计算 $a$ 和 $b$ 之间的距离 $d$，记录在哈希表 $hs$ 中，然后枚举 $\textit{vFences}$ 中的任意两条垂直栅栏 $c$ 和 $d$，计算 $c$ 和 $d$ 之间的距离 $d$，记录在哈希表 $vs$ 中，最后遍历哈希表 $hs$，如果 $hs$ 中的某个距离 $d$ 在哈希表 $vs$ 中也存在，那么说明存在一个正方形田地，其边长为 $d$，面积为 $d^2$，我们只需要取最大的 $d$，求 $d^2 \bmod 10^9 + 7$ 即可。

时间复杂度 $O(h^2 + v^2)$，空间复杂度 $O(h^2 + v^2)$。其中 $h$ 和 $v$ 分别是 $\textit{hFences}$ 和 $\textit{vFences}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeSquareArea(
        self, m: int, n: int, hFences: List[int], vFences: List[int]
    ) -> int:
        def f(nums: List[int], k: int) -> Set[int]:
            nums.extend([1, k])
            nums.sort()
            return {b - a for a, b in combinations(nums, 2)}

        mod = 10**9 + 7
        hs = f(hFences, m)
        vs = f(vFences, n)
        ans = max(hs & vs, default=0)
        return ans**2 % mod if ans else -1
```

#### Java

```java
class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Set<Integer> hs = f(hFences, m);
        Set<Integer> vs = f(vFences, n);
        hs.retainAll(vs);
        int ans = -1;
        final int mod = (int) 1e9 + 7;
        for (int x : hs) {
            ans = Math.max(ans, x);
        }
        return ans > 0 ? (int) (1L * ans * ans % mod) : -1;
    }

    private Set<Integer> f(int[] nums, int k) {
        int n = nums.length;
        nums = Arrays.copyOf(nums, n + 2);
        nums[n] = 1;
        nums[n + 1] = k;
        Arrays.sort(nums);
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                s.add(nums[i] - nums[j]);
            }
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto f = [](vector<int>& nums, int k) {
            nums.push_back(k);
            nums.push_back(1);
            sort(nums.begin(), nums.end());
            unordered_set<int> s;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    s.insert(nums[i] - nums[j]);
                }
            }
            return s;
        };
        auto hs = f(hFences, m);
        auto vs = f(vFences, n);
        int ans = 0;
        for (int h : hs) {
            if (vs.count(h)) {
                ans = max(ans, h);
            }
        }
        const int mod = 1e9 + 7;
        return ans > 0 ? 1LL * ans * ans % mod : -1;
    }
};
```

#### Go

```go
func maximizeSquareArea(m int, n int, hFences []int, vFences []int) int {
	f := func(nums []int, k int) map[int]bool {
		nums = append(nums, 1, k)
		sort.Ints(nums)
		s := map[int]bool{}
		for i := 0; i < len(nums); i++ {
			for j := 0; j < i; j++ {
				s[nums[i]-nums[j]] = true
			}
		}
		return s
	}
	hs := f(hFences, m)
	vs := f(vFences, n)
	ans := 0
	for h := range hs {
		if vs[h] {
			ans = max(ans, h)
		}
	}
	if ans > 0 {
		return ans * ans % (1e9 + 7)
	}
	return -1
}
```

#### TypeScript

```ts
function maximizeSquareArea(m: number, n: number, hFences: number[], vFences: number[]): number {
    const f = (nums: number[], k: number): Set<number> => {
        nums.push(1, k);
        nums.sort((a, b) => a - b);
        const s: Set<number> = new Set();
        for (let i = 0; i < nums.length; ++i) {
            for (let j = 0; j < i; ++j) {
                s.add(nums[i] - nums[j]);
            }
        }
        return s;
    };
    const hs = f(hFences, m);
    const vs = f(vFences, n);
    let ans = 0;
    for (const h of hs) {
        if (vs.has(h)) {
            ans = Math.max(ans, h);
        }
    }
    return ans ? Number(BigInt(ans) ** 2n % 1000000007n) : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2976. 转换字符串的最小成本 I](https://leetcode.cn/problems/minimum-cost-to-convert-string-i){#2976}

{{< tabs "2976" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        g = [[inf] * 26 for _ in range(26)]
        for i in range(26):
            g[i][i] = 0
        for x, y, z in zip(original, changed, cost):
            x = ord(x) - ord('a')
            y = ord(y) - ord('a')
            g[x][y] = min(g[x][y], z)
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j])
        ans = 0
        for a, b in zip(source, target):
            if a != b:
                x, y = ord(a) - ord('a'), ord(b) - ord('a')
                if g[x][y] >= inf:
                    return -1
                ans += g[x][y]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumCost(
        String source, String target, char[] original, char[] changed, int[] cost) {
        final int inf = 1 << 29;
        int[][] g = new int[26][26];
        for (int i = 0; i < 26; ++i) {
            Arrays.fill(g[i], inf);
            g[i][i] = 0;
        }
        for (int i = 0; i < original.length; ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = Math.min(g[x][y], z);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source.charAt(i) - 'a';
            int y = target.charAt(i) - 'a';
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1;
                }
                ans += g[x][y];
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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = 1 << 29;
        int g[26][26];
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = min(g[x][y], z);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1;
                }
                ans += g[x][y];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(source string, target string, original []byte, changed []byte, cost []int) (ans int64) {
	const inf = 1 << 29
	g := make([][]int, 26)
	for i := range g {
		g[i] = make([]int, 26)
		for j := range g[i] {
			if i == j {
				g[i][j] = 0
			} else {
				g[i][j] = inf
			}
		}
	}

	for i := 0; i < len(original); i++ {
		x := int(original[i] - 'a')
		y := int(changed[i] - 'a')
		z := cost[i]
		g[x][y] = min(g[x][y], z)
	}

	for k := 0; k < 26; k++ {
		for i := 0; i < 26; i++ {
			for j := 0; j < 26; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}
	n := len(source)
	for i := 0; i < n; i++ {
		x := int(source[i] - 'a')
		y := int(target[i] - 'a')
		if x != y {
			if g[x][y] >= inf {
				return -1
			}
			ans += int64(g[x][y])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(
    source: string,
    target: string,
    original: string[],
    changed: string[],
    cost: number[],
): number {
    const [n, m, MAX] = [source.length, original.length, Number.POSITIVE_INFINITY];
    const g: number[][] = Array.from({ length: 26 }, () => Array(26).fill(MAX));
    const getIndex = (ch: string) => ch.charCodeAt(0) - 'a'.charCodeAt(0);

    for (let i = 0; i < 26; ++i) g[i][i] = 0;
    for (let i = 0; i < m; ++i) {
        const x = getIndex(original[i]);
        const y = getIndex(changed[i]);
        const z = cost[i];
        g[x][y] = Math.min(g[x][y], z);
    }

    for (let k = 0; k < 26; ++k) {
        for (let i = 0; i < 26; ++i) {
            for (let j = 0; g[i][k] < MAX && j < 26; j++) {
                if (g[k][j] < MAX) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const x = getIndex(source[i]);
        const y = getIndex(target[i]);
        if (x === y) continue;
        if (g[x][y] === MAX) return -1;
        ans += g[x][y];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function (source, target, original, changed, cost) {
    const [n, m, MAX] = [source.length, original.length, Number.POSITIVE_INFINITY];
    const g = Array.from({ length: 26 }, () => Array(26).fill(MAX));
    const getIndex = ch => ch.charCodeAt(0) - 'a'.charCodeAt(0);

    for (let i = 0; i < 26; ++i) g[i][i] = 0;
    for (let i = 0; i < m; ++i) {
        const x = getIndex(original[i]);
        const y = getIndex(changed[i]);
        const z = cost[i];
        g[x][y] = Math.min(g[x][y], z);
    }

    for (let k = 0; k < 26; ++k) {
        for (let i = 0; i < 26; ++i) {
            for (let j = 0; g[i][k] < MAX && j < 26; j++) {
                if (g[k][j] < MAX) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const x = getIndex(source[i]);
        const y = getIndex(target[i]);
        if (x === y) continue;
        if (g[x][y] === MAX) return -1;
        ans += g[x][y];
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong> 开始的字符串 <code>source</code> 和 <code>target</code> ，它们的长度均为 <code>n</code> 并且由 <strong>小写 </strong>英文字母组成。</p>

<p>另给你两个下标从 <strong>0</strong> 开始的字符数组 <code>original</code> 和 <code>changed</code> ，以及一个整数数组 <code>cost</code> ，其中 <code>cost[i]</code> 代表将字符 <code>original[i]</code> 更改为字符 <code>changed[i]</code> 的成本。</p>

<p>你从字符串 <code>source</code> 开始。在一次操作中，<strong>如果 </strong>存在 <strong>任意</strong> 下标 <code>j</code> 满足 <code>cost[j] == z</code>&nbsp; 、<code>original[j] == x</code> 以及 <code>changed[j] == y</code> 。你就可以选择字符串中的一个字符 <code>x</code> 并以 <code>z</code> 的成本将其更改为字符 <code>y</code> 。</p>

<p>返回将字符串 <code>source</code> 转换为字符串 <code>target</code> 所需的<strong> 最小 </strong>成本。如果不可能完成转换，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong>，可能存在下标 <code>i</code> 、<code>j</code> 使得 <code>original[j] == original[i]</code> 且 <code>changed[j] == changed[i]</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
<strong>输出：</strong>28
<strong>解释：</strong>将字符串 "abcd" 转换为字符串 "acbe" ：
- 更改下标 1 处的值 'b' 为 'c' ，成本为 5 。
- 更改下标 2 处的值 'c' 为 'e' ，成本为 1 。
- 更改下标 2 处的值 'e' 为 'b' ，成本为 2 。
- 更改下标 3 处的值 'd' 为 'e' ，成本为 20 。
产生的总成本是 5 + 1 + 2 + 20 = 28 。
可以证明这是可能的最小成本。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
<strong>输出：</strong>12
<strong>解释：</strong>要将字符 'a' 更改为 'b'：
- 将字符 'a' 更改为 'c'，成本为 1 
- 将字符 'c' 更改为 'b'，成本为 2 
产生的总成本是 1 + 2 = 3。
将所有 'a' 更改为 'b'，产生的总成本是 3 * 4 = 12 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
<strong>输出：</strong>-1
<strong>解释：</strong>无法将 source 字符串转换为 target 字符串，因为下标 3 处的值无法从 'd' 更改为 'e' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= source.length == target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>source</code>、<code>target</code> 均由小写英文字母组成</li>
	<li><code>1 &lt;= cost.length== original.length == changed.length &lt;= 2000</code></li>
	<li><code>original[i]</code>、<code>changed[i]</code> 是小写英文字母</li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>original[i] != changed[i]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Floyd 算法

根据题目描述，我们可以将每个字母看作一个节点，每对字母的转换成本看作一条有向边。那么我们先初始化一个 $26 \times 26$ 的二维数组 $g$，其中 $g[i][j]$ 表示字母 $i$ 转换成字母 $j$ 的最小成本。初始时 $g[i][j] = \infty$，如果 $i = j$，那么 $g[i][j] = 0$。

然后我们遍历数组 $original$, $changed$ 和 $cost$，对于每个下标 $i$，我们将 $original[i]$ 转换成 $changed[i]$ 的成本 $cost[i]$ 更新到 $g[original[i]][changed[i]]$ 中，取最小值。

接下来，我们使用 Floyd 算法计算出 $g$ 中任意两个节点之间的最小成本。最后，我们遍历字符串 $source$ 和 $target$，如果 $source[i] \neq target[i]$，并且 $g[source[i]][target[i]] \geq \infty$，那么说明无法完成转换，返回 $-1$。否则，我们将 $g[source[i]][target[i]]$ 累加到答案中。

遍历结束后，返回答案即可。

时间复杂度 $O(m + n + |\Sigma|^3)$，空间复杂度 $O(|\Sigma|^2)$。其中 $m$ 和 $n$ 分别是数组 $original$ 和 $source$ 的长度；而 $|\Sigma|$ 是字母表的大小，即 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        g = [[inf] * 26 for _ in range(26)]
        for i in range(26):
            g[i][i] = 0
        for x, y, z in zip(original, changed, cost):
            x = ord(x) - ord('a')
            y = ord(y) - ord('a')
            g[x][y] = min(g[x][y], z)
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j])
        ans = 0
        for a, b in zip(source, target):
            if a != b:
                x, y = ord(a) - ord('a'), ord(b) - ord('a')
                if g[x][y] >= inf:
                    return -1
                ans += g[x][y]
        return ans
```

#### Java

```java
class Solution {
    public long minimumCost(
        String source, String target, char[] original, char[] changed, int[] cost) {
        final int inf = 1 << 29;
        int[][] g = new int[26][26];
        for (int i = 0; i < 26; ++i) {
            Arrays.fill(g[i], inf);
            g[i][i] = 0;
        }
        for (int i = 0; i < original.length; ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = Math.min(g[x][y], z);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source.charAt(i) - 'a';
            int y = target.charAt(i) - 'a';
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1;
                }
                ans += g[x][y];
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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = 1 << 29;
        int g[26][26];
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = min(g[x][y], z);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1;
                }
                ans += g[x][y];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumCost(source string, target string, original []byte, changed []byte, cost []int) (ans int64) {
	const inf = 1 << 29
	g := make([][]int, 26)
	for i := range g {
		g[i] = make([]int, 26)
		for j := range g[i] {
			if i == j {
				g[i][j] = 0
			} else {
				g[i][j] = inf
			}
		}
	}

	for i := 0; i < len(original); i++ {
		x := int(original[i] - 'a')
		y := int(changed[i] - 'a')
		z := cost[i]
		g[x][y] = min(g[x][y], z)
	}

	for k := 0; k < 26; k++ {
		for i := 0; i < 26; i++ {
			for j := 0; j < 26; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}
	n := len(source)
	for i := 0; i < n; i++ {
		x := int(source[i] - 'a')
		y := int(target[i] - 'a')
		if x != y {
			if g[x][y] >= inf {
				return -1
			}
			ans += int64(g[x][y])
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumCost(
    source: string,
    target: string,
    original: string[],
    changed: string[],
    cost: number[],
): number {
    const [n, m, MAX] = [source.length, original.length, Number.POSITIVE_INFINITY];
    const g: number[][] = Array.from({ length: 26 }, () => Array(26).fill(MAX));
    const getIndex = (ch: string) => ch.charCodeAt(0) - 'a'.charCodeAt(0);

    for (let i = 0; i < 26; ++i) g[i][i] = 0;
    for (let i = 0; i < m; ++i) {
        const x = getIndex(original[i]);
        const y = getIndex(changed[i]);
        const z = cost[i];
        g[x][y] = Math.min(g[x][y], z);
    }

    for (let k = 0; k < 26; ++k) {
        for (let i = 0; i < 26; ++i) {
            for (let j = 0; g[i][k] < MAX && j < 26; j++) {
                if (g[k][j] < MAX) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const x = getIndex(source[i]);
        const y = getIndex(target[i]);
        if (x === y) continue;
        if (g[x][y] === MAX) return -1;
        ans += g[x][y];
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function (source, target, original, changed, cost) {
    const [n, m, MAX] = [source.length, original.length, Number.POSITIVE_INFINITY];
    const g = Array.from({ length: 26 }, () => Array(26).fill(MAX));
    const getIndex = ch => ch.charCodeAt(0) - 'a'.charCodeAt(0);

    for (let i = 0; i < 26; ++i) g[i][i] = 0;
    for (let i = 0; i < m; ++i) {
        const x = getIndex(original[i]);
        const y = getIndex(changed[i]);
        const z = cost[i];
        g[x][y] = Math.min(g[x][y], z);
    }

    for (let k = 0; k < 26; ++k) {
        for (let i = 0; i < 26; ++i) {
            for (let j = 0; g[i][k] < MAX && j < 26; j++) {
                if (g[k][j] < MAX) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const x = getIndex(source[i]);
        const y = getIndex(target[i]);
        if (x === y) continue;
        if (g[x][y] === MAX) return -1;
        ans += g[x][y];
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2977. 转换字符串的最小成本 II](https://leetcode.cn/problems/minimum-cost-to-convert-string-ii){#2977}

{{< tabs "2977" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ["children", "v"]

    def __init__(self):
        self.children: List[Node | None] = [None] * 26
        self.v = -1


class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        m = len(cost)
        g = [[inf] * (m << 1) for _ in range(m << 1)]
        for i in range(m << 1):
            g[i][i] = 0
        root = Node()
        idx = 0

        def insert(w: str) -> int:
            node = root
            for c in w:
                i = ord(c) - ord("a")
                if node.children[i] is None:
                    node.children[i] = Node()
                node = node.children[i]
            if node.v < 0:
                nonlocal idx
                node.v = idx
                idx += 1
            return node.v

        @cache
        def dfs(i: int) -> int:
            if i >= len(source):
                return 0
            res = dfs(i + 1) if source[i] == target[i] else inf
            p = q = root
            for j in range(i, len(source)):
                p = p.children[ord(source[j]) - ord("a")]
                q = q.children[ord(target[j]) - ord("a")]
                if p is None or q is None:
                    break
                if p.v < 0 or q.v < 0:
                    continue
                res = min(res, dfs(j + 1) + g[p.v][q.v])
            return res

        for x, y, z in zip(original, changed, cost):
            x = insert(x)
            y = insert(y)
            g[x][y] = min(g[x][y], z)
        for k in range(idx):
            for i in range(idx):
                if g[i][k] >= inf:
                    continue
                for j in range(idx):
                    # g[i][j] = min(g[i][j], g[i][k] + g[k][j])
                    if g[i][k] + g[k][j] < g[i][j]:
                        g[i][j] = g[i][k] + g[k][j]

        ans = dfs(0)
        return -1 if ans >= inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Node[] children = new Node[26];
    int v = -1;
}

class Solution {
    private final long inf = 1L << 60;
    private Node root = new Node();
    private int idx;

    private long[][] g;
    private char[] s;
    private char[] t;
    private Long[] f;

    public long minimumCost(
        String source, String target, String[] original, String[] changed, int[] cost) {
        int m = cost.length;
        g = new long[m << 1][m << 1];
        s = source.toCharArray();
        t = target.toCharArray();
        for (int i = 0; i < g.length; ++i) {
            Arrays.fill(g[i], inf);
            g[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int x = insert(original[i]);
            int y = insert(changed[i]);
            g[x][y] = Math.min(g[x][y], cost[i]);
        }
        for (int k = 0; k < idx; ++k) {
            for (int i = 0; i < idx; ++i) {
                if (g[i][k] >= inf) {
                    continue;
                }
                for (int j = 0; j < idx; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        f = new Long[s.length];
        long ans = dfs(0);
        return ans >= inf ? -1 : ans;
    }

    private int insert(String w) {
        Node node = root;
        for (char c : w.toCharArray()) {
            int i = c - 'a';
            if (node.children[i] == null) {
                node.children[i] = new Node();
            }
            node = node.children[i];
        }
        if (node.v < 0) {
            node.v = idx++;
        }
        return node.v;
    }

    private long dfs(int i) {
        if (i >= s.length) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        long res = s[i] == t[i] ? dfs(i + 1) : inf;
        Node p = root, q = root;
        for (int j = i; j < s.length; ++j) {
            p = p.children[s[j] - 'a'];
            q = q.children[t[j] - 'a'];
            if (p == null || q == null) {
                break;
            }
            if (p.v < 0 || q.v < 0) {
                continue;
            }
            long t = g[p.v][q.v];
            if (t < inf) {
                res = Math.min(res, t + dfs(j + 1));
            }
        }
        return f[i] = res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    Node* children[26];
    int v = -1;
    Node() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
private:
    const long long inf = 1LL << 60;
    Node* root = new Node();
    int idx;

    vector<vector<long long>> g;
    string s;
    string t;
    vector<long long> f;

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int m = cost.size();
        g = vector<vector<long long>>(m << 1, vector<long long>(m << 1, inf));
        s = source;
        t = target;

        for (int i = 0; i < g.size(); ++i) {
            g[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            int x = insert(original[i]);
            int y = insert(changed[i]);
            g[x][y] = min(g[x][y], static_cast<long long>(cost[i]));
        }

        for (int k = 0; k < idx; ++k) {
            for (int i = 0; i < idx; ++i) {
                if (g[i][k] >= inf) {
                    continue;
                }
                for (int j = 0; j < idx; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        f = vector<long long>(s.length(), -1);
        long long ans = dfs(0);
        return ans >= inf ? -1 : ans;
    }

private:
    int insert(const string& w) {
        Node* node = root;
        for (char c : w) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }
            node = node->children[i];
        }
        if (node->v < 0) {
            node->v = idx++;
        }
        return node->v;
    }

    long long dfs(int i) {
        if (i >= s.length()) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        long long res = (s[i] == t[i]) ? dfs(i + 1) : inf;
        Node* p = root;
        Node* q = root;
        for (int j = i; j < s.length(); ++j) {
            p = p->children[s[j] - 'a'];
            q = q->children[t[j] - 'a'];
            if (p == nullptr || q == nullptr) {
                break;
            }
            if (p->v < 0 || q->v < 0) {
                continue;
            }
            long long temp = g[p->v][q->v];
            if (temp < inf) {
                res = min(res, temp + dfs(j + 1));
            }
        }
        return f[i] = res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	children [26]*Node
	v        int
}

func newNode() *Node {
	return &Node{v: -1}
}

func minimumCost(source string, target string, original []string, changed []string, cost []int) int64 {
	inf := 1 << 60
	root := newNode()
	idx := 0
	m := len(cost)
	g := make([][]int, m<<1)
	for i := range g {
		g[i] = make([]int, m<<1)
		for j := range g[i] {
			g[i][j] = inf
		}
		g[i][i] = 0
	}
	insert := func(w string) int {
		node := root
		for _, c := range w {
			i := c - 'a'
			if node.children[i] == nil {
				node.children[i] = newNode()
			}
			node = node.children[i]
		}
		if node.v < 0 {
			node.v = idx
			idx++
		}
		return node.v
	}
	for i := range original {
		x := insert(original[i])
		y := insert(changed[i])
		g[x][y] = min(g[x][y], cost[i])
	}
	for k := 0; k < idx; k++ {
		for i := 0; i < idx; i++ {
			if g[i][k] >= inf {
				continue
			}
			for j := 0; j < idx; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}
	n := len(source)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] >= 0 {
			return f[i]
		}
		f[i] = inf
		if source[i] == target[i] {
			f[i] = dfs(i + 1)
		}
		p, q := root, root
		for j := i; j < n; j++ {
			p = p.children[source[j]-'a']
			q = q.children[target[j]-'a']
			if p == nil || q == nil {
				break
			}
			if p.v < 0 || q.v < 0 {
				continue
			}
			f[i] = min(f[i], dfs(j+1)+g[p.v][q.v])
		}
		return f[i]
	}
	ans := dfs(0)
	if ans >= inf {
		ans = -1
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    children: (Node | null)[] = Array(26).fill(null);
    v: number = -1;
}

function minimumCost(
    source: string,
    target: string,
    original: string[],
    changed: string[],
    cost: number[],
): number {
    const m = cost.length;
    const n = source.length;
    const g: number[][] = Array.from({ length: m << 1 }, () => Array(m << 1).fill(Infinity));
    const root: Node = new Node();
    let idx: number = 0;
    const f: number[] = Array(n).fill(-1);
    const insert = (w: string): number => {
        let node: Node = root;
        for (const c of w) {
            const i: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (node.children[i] === null) {
                node.children[i] = new Node();
            }
            node = node.children[i] as Node;
        }
        if (node.v < 0) {
            node.v = idx++;
        }
        return node.v;
    };

    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        let res: number = source[i] === target[i] ? dfs(i + 1) : Infinity;
        let p: Node = root;
        let q: Node = root;
        for (let j = i; j < source.length; ++j) {
            p = p.children[source[j].charCodeAt(0) - 'a'.charCodeAt(0)] as Node;
            q = q.children[target[j].charCodeAt(0) - 'a'.charCodeAt(0)] as Node;
            if (p === null || q === null) {
                break;
            }
            if (p.v < 0 || q.v < 0) {
                continue;
            }
            const t: number = g[p.v][q.v];
            res = Math.min(res, t + dfs(j + 1));
        }
        return (f[i] = res);
    };

    for (let i = 0; i < m; ++i) {
        const x: number = insert(original[i]);
        const y: number = insert(changed[i]);
        g[x][y] = Math.min(g[x][y], cost[i]);
    }

    for (let k = 0; k < idx; ++k) {
        for (let i = 0; i < idx; ++i) {
            if (g[i][k] >= Infinity) {
                continue;
            }
            for (let j = 0; j < idx; ++j) {
                g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    const ans: number = dfs(0);
    return ans >= Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong> 开始的字符串 <code>source</code> 和 <code>target</code> ，它们的长度均为 <code>n</code> 并且由 <strong>小写 </strong>英文字母组成。</p>

<p>另给你两个下标从 <strong>0</strong> 开始的字符串数组 <code>original</code> 和 <code>changed</code> ，以及一个整数数组 <code>cost</code> ，其中 <code>cost[i]</code> 代表将字符串 <code>original[i]</code> 更改为字符串 <code>changed[i]</code> 的成本。</p>

<p>你从字符串 <code>source</code> 开始。在一次操作中，<strong>如果 </strong>存在 <strong>任意</strong> 下标 <code>j</code> 满足 <code>cost[j] == z</code>&nbsp; 、<code>original[j] == x</code> 以及 <code>changed[j] == y</code> ，你就可以选择字符串中的 <strong>子串</strong> <code>x</code> 并以 <code>z</code> 的成本将其更改为 <code>y</code> 。 你可以执行 <strong>任意数量 </strong>的操作，但是任两次操作必须满足<strong> 以下两个 </strong>条件 <strong>之一</strong> ：</p>

<ul>
	<li>在两次操作中选择的子串分别是 <code>source[a..b]</code> 和 <code>source[c..d]</code> ，满足 <code>b &lt; c</code>&nbsp; <strong>或</strong> <code>d &lt; a</code> 。换句话说，两次操作中选择的下标<strong> 不相交 </strong>。</li>
	<li>在两次操作中选择的子串分别是 <code>source[a..b]</code> 和 <code>source[c..d]</code> ，满足 <code>a == c</code> <strong>且</strong> <code>b == d</code> 。换句话说，两次操作中选择的下标<strong> 相同 </strong>。</li>
</ul>

<p>返回将字符串 <code>source</code> 转换为字符串 <code>target</code> 所需的<strong> 最小 </strong>成本。如果不可能完成转换，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong>，可能存在下标 <code>i</code> 、<code>j</code> 使得 <code>original[j] == original[i]</code> 且 <code>changed[j] == changed[i]</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
<strong>输出：</strong>28
<strong>解释：</strong>将 "abcd" 转换为 "acbe"，执行以下操作：
- 将子串 source[1..1] 从 "b" 改为 "c" ，成本为 5 。
- 将子串 source[2..2] 从 "c" 改为 "e" ，成本为 1 。
- 将子串 source[2..2] 从 "e" 改为 "b" ，成本为 2 。
- 将子串 source[3..3] 从 "d" 改为 "e" ，成本为 20 。
产生的总成本是 5 + 1 + 2 + 20 = 28 。 
可以证明这是可能的最小成本。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
<strong>输出：</strong>9
<strong>解释：</strong>将 "abcdefgh" 转换为 "acdeeghh"，执行以下操作：
- 将子串 source[1..3] 从 "bcd" 改为 "cde" ，成本为 1 。
- 将子串 source[5..7] 从 "fgh" 改为 "thh" ，成本为 3 。可以执行此操作，因为下标 [5,7] 与第一次操作选中的下标不相交。
- 将子串 source[5..7] 从 "thh" 改为 "ghh" ，成本为 5 。可以执行此操作，因为下标 [5,7] 与第一次操作选中的下标不相交，且与第二次操作选中的下标相同。
产生的总成本是 1 + 3 + 5 = 9 。
可以证明这是可能的最小成本。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
<strong>输出：</strong>-1
<strong>解释：</strong>无法将 "abcdefgh" 转换为 "addddddd" 。
如果选择子串 source[1..3] 执行第一次操作，以将 "abcdefgh" 改为 "adddefgh" ，你无法选择子串 source[3..7] 执行第二次操作，因为两次操作有一个共用下标 3 。
如果选择子串 source[3..7] 执行第一次操作，以将 "abcdefgh" 改为 "abcddddd" ，你无法选择子串 source[1..3] 执行第二次操作，因为两次操作有一个共用下标 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= source.length == target.length &lt;= 1000</code></li>
	<li><code>source</code>、<code>target</code> 均由小写英文字母组成</li>
	<li><code>1 &lt;= cost.length == original.length == changed.length &lt;= 100</code></li>
	<li><code>1 &lt;= original[i].length == changed[i].length &lt;= source.length</code></li>
	<li><code>original[i]</code>、<code>changed[i]</code> 均由小写英文字母组成</li>
	<li><code>original[i] != changed[i]</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树 + Floyd 算法 + 记忆化搜索

根据题目描述，我们可以将每个字符串看作一个节点，每对字符串的转换成本看作一条有向边。那么我们先初始化一个 $26 \times 26$ 的二维数组 $g$，其中 $g[i][j]$ 表示字符串 $i$ 转换成字符串 $j$ 的最小成本。初始时 $g[i][j] = \infty$，如果 $i = j$，那么 $g[i][j] = 0$。在这里，我们可以借助字典树存储 `original` 和 `changed` 中的字符串以及对应的整数编号。

然后，我们使用 Floyd 算法计算出任意两个字符串之间的最小成本。

接下来，我们定义函数 $dfs(i)$ 表示将字符串 $source[i..]$ 转换为字符串 $target[i..]$ 所需的最小成本。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i \geq |source|$，说明不需要转换，返回 $0$。
-   否则，如果 $source[i] = target[i]$，那么可以直接跳过，我们直接递归计算 $dfs(i + 1)$。我们也可以在 $[i, |source|)$ 的范围内枚举下标 $j$，如果 $source[i..j]$ 和 $target[i..j]$ 都在字典树中，且其对应的整数编号 $x$ 和 $y$ 都大于等于 $0$，那么我们可以将 $dfs(j + 1)$ 和 $g[x][y]$ 相加，得到一种转换方案的成本，我们取所有方案中的最小值。

综上，我们可以得到：

$$
dfs(i) = \begin{cases}
0, & i \geq |source| \\
dfs(i + 1), & source[i] = target[i] \\
\min_{i \leq j < |source|} \{ dfs(j + 1) + g[x][y] \}, & \textit{otherwise}
\end{cases}
$$

其中 $x$ 和 $y$ 分别是 $source[i..j]$ 和 $target[i..j]$ 在字典树中对应的整数编号。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(m^3 + n^2 + m \times n)$，空间复杂度 $O(m^2 + m \times n + n)$。其中 $m$ 和 $n$ 分别是数组 $original$ 和 $source$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ["children", "v"]

    def __init__(self):
        self.children: List[Node | None] = [None] * 26
        self.v = -1


class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        m = len(cost)
        g = [[inf] * (m << 1) for _ in range(m << 1)]
        for i in range(m << 1):
            g[i][i] = 0
        root = Node()
        idx = 0

        def insert(w: str) -> int:
            node = root
            for c in w:
                i = ord(c) - ord("a")
                if node.children[i] is None:
                    node.children[i] = Node()
                node = node.children[i]
            if node.v < 0:
                nonlocal idx
                node.v = idx
                idx += 1
            return node.v

        @cache
        def dfs(i: int) -> int:
            if i >= len(source):
                return 0
            res = dfs(i + 1) if source[i] == target[i] else inf
            p = q = root
            for j in range(i, len(source)):
                p = p.children[ord(source[j]) - ord("a")]
                q = q.children[ord(target[j]) - ord("a")]
                if p is None or q is None:
                    break
                if p.v < 0 or q.v < 0:
                    continue
                res = min(res, dfs(j + 1) + g[p.v][q.v])
            return res

        for x, y, z in zip(original, changed, cost):
            x = insert(x)
            y = insert(y)
            g[x][y] = min(g[x][y], z)
        for k in range(idx):
            for i in range(idx):
                if g[i][k] >= inf:
                    continue
                for j in range(idx):
                    # g[i][j] = min(g[i][j], g[i][k] + g[k][j])
                    if g[i][k] + g[k][j] < g[i][j]:
                        g[i][j] = g[i][k] + g[k][j]

        ans = dfs(0)
        return -1 if ans >= inf else ans
```

#### Java

```java
class Node {
    Node[] children = new Node[26];
    int v = -1;
}

class Solution {
    private final long inf = 1L << 60;
    private Node root = new Node();
    private int idx;

    private long[][] g;
    private char[] s;
    private char[] t;
    private Long[] f;

    public long minimumCost(
        String source, String target, String[] original, String[] changed, int[] cost) {
        int m = cost.length;
        g = new long[m << 1][m << 1];
        s = source.toCharArray();
        t = target.toCharArray();
        for (int i = 0; i < g.length; ++i) {
            Arrays.fill(g[i], inf);
            g[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int x = insert(original[i]);
            int y = insert(changed[i]);
            g[x][y] = Math.min(g[x][y], cost[i]);
        }
        for (int k = 0; k < idx; ++k) {
            for (int i = 0; i < idx; ++i) {
                if (g[i][k] >= inf) {
                    continue;
                }
                for (int j = 0; j < idx; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        f = new Long[s.length];
        long ans = dfs(0);
        return ans >= inf ? -1 : ans;
    }

    private int insert(String w) {
        Node node = root;
        for (char c : w.toCharArray()) {
            int i = c - 'a';
            if (node.children[i] == null) {
                node.children[i] = new Node();
            }
            node = node.children[i];
        }
        if (node.v < 0) {
            node.v = idx++;
        }
        return node.v;
    }

    private long dfs(int i) {
        if (i >= s.length) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        long res = s[i] == t[i] ? dfs(i + 1) : inf;
        Node p = root, q = root;
        for (int j = i; j < s.length; ++j) {
            p = p.children[s[j] - 'a'];
            q = q.children[t[j] - 'a'];
            if (p == null || q == null) {
                break;
            }
            if (p.v < 0 || q.v < 0) {
                continue;
            }
            long t = g[p.v][q.v];
            if (t < inf) {
                res = Math.min(res, t + dfs(j + 1));
            }
        }
        return f[i] = res;
    }
}
```

#### C++

```cpp
class Node {
public:
    Node* children[26];
    int v = -1;
    Node() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
private:
    const long long inf = 1LL << 60;
    Node* root = new Node();
    int idx;

    vector<vector<long long>> g;
    string s;
    string t;
    vector<long long> f;

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int m = cost.size();
        g = vector<vector<long long>>(m << 1, vector<long long>(m << 1, inf));
        s = source;
        t = target;

        for (int i = 0; i < g.size(); ++i) {
            g[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            int x = insert(original[i]);
            int y = insert(changed[i]);
            g[x][y] = min(g[x][y], static_cast<long long>(cost[i]));
        }

        for (int k = 0; k < idx; ++k) {
            for (int i = 0; i < idx; ++i) {
                if (g[i][k] >= inf) {
                    continue;
                }
                for (int j = 0; j < idx; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        f = vector<long long>(s.length(), -1);
        long long ans = dfs(0);
        return ans >= inf ? -1 : ans;
    }

private:
    int insert(const string& w) {
        Node* node = root;
        for (char c : w) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }
            node = node->children[i];
        }
        if (node->v < 0) {
            node->v = idx++;
        }
        return node->v;
    }

    long long dfs(int i) {
        if (i >= s.length()) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        long long res = (s[i] == t[i]) ? dfs(i + 1) : inf;
        Node* p = root;
        Node* q = root;
        for (int j = i; j < s.length(); ++j) {
            p = p->children[s[j] - 'a'];
            q = q->children[t[j] - 'a'];
            if (p == nullptr || q == nullptr) {
                break;
            }
            if (p->v < 0 || q->v < 0) {
                continue;
            }
            long long temp = g[p->v][q->v];
            if (temp < inf) {
                res = min(res, temp + dfs(j + 1));
            }
        }
        return f[i] = res;
    }
};
```

#### Go

```go
type Node struct {
	children [26]*Node
	v        int
}

func newNode() *Node {
	return &Node{v: -1}
}

func minimumCost(source string, target string, original []string, changed []string, cost []int) int64 {
	inf := 1 << 60
	root := newNode()
	idx := 0
	m := len(cost)
	g := make([][]int, m<<1)
	for i := range g {
		g[i] = make([]int, m<<1)
		for j := range g[i] {
			g[i][j] = inf
		}
		g[i][i] = 0
	}
	insert := func(w string) int {
		node := root
		for _, c := range w {
			i := c - 'a'
			if node.children[i] == nil {
				node.children[i] = newNode()
			}
			node = node.children[i]
		}
		if node.v < 0 {
			node.v = idx
			idx++
		}
		return node.v
	}
	for i := range original {
		x := insert(original[i])
		y := insert(changed[i])
		g[x][y] = min(g[x][y], cost[i])
	}
	for k := 0; k < idx; k++ {
		for i := 0; i < idx; i++ {
			if g[i][k] >= inf {
				continue
			}
			for j := 0; j < idx; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}
	n := len(source)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] >= 0 {
			return f[i]
		}
		f[i] = inf
		if source[i] == target[i] {
			f[i] = dfs(i + 1)
		}
		p, q := root, root
		for j := i; j < n; j++ {
			p = p.children[source[j]-'a']
			q = q.children[target[j]-'a']
			if p == nil || q == nil {
				break
			}
			if p.v < 0 || q.v < 0 {
				continue
			}
			f[i] = min(f[i], dfs(j+1)+g[p.v][q.v])
		}
		return f[i]
	}
	ans := dfs(0)
	if ans >= inf {
		ans = -1
	}
	return int64(ans)
}
```

#### TypeScript

```ts
class Node {
    children: (Node | null)[] = Array(26).fill(null);
    v: number = -1;
}

function minimumCost(
    source: string,
    target: string,
    original: string[],
    changed: string[],
    cost: number[],
): number {
    const m = cost.length;
    const n = source.length;
    const g: number[][] = Array.from({ length: m << 1 }, () => Array(m << 1).fill(Infinity));
    const root: Node = new Node();
    let idx: number = 0;
    const f: number[] = Array(n).fill(-1);
    const insert = (w: string): number => {
        let node: Node = root;
        for (const c of w) {
            const i: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (node.children[i] === null) {
                node.children[i] = new Node();
            }
            node = node.children[i] as Node;
        }
        if (node.v < 0) {
            node.v = idx++;
        }
        return node.v;
    };

    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        let res: number = source[i] === target[i] ? dfs(i + 1) : Infinity;
        let p: Node = root;
        let q: Node = root;
        for (let j = i; j < source.length; ++j) {
            p = p.children[source[j].charCodeAt(0) - 'a'.charCodeAt(0)] as Node;
            q = q.children[target[j].charCodeAt(0) - 'a'.charCodeAt(0)] as Node;
            if (p === null || q === null) {
                break;
            }
            if (p.v < 0 || q.v < 0) {
                continue;
            }
            const t: number = g[p.v][q.v];
            res = Math.min(res, t + dfs(j + 1));
        }
        return (f[i] = res);
    };

    for (let i = 0; i < m; ++i) {
        const x: number = insert(original[i]);
        const y: number = insert(changed[i]);
        g[x][y] = Math.min(g[x][y], cost[i]);
    }

    for (let k = 0; k < idx; ++k) {
        for (let i = 0; i < idx; ++i) {
            if (g[i][k] >= Infinity) {
                continue;
            }
            for (let j = 0; j < idx; ++j) {
                g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    const ans: number = dfs(0);
    return ans >= Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2978. 对称坐标 🔒](https://leetcode.cn/problems/symmetric-coordinates){#2978}

{{< tabs "2978" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT
            ROW_NUMBER() OVER () AS id,
            x,
            y
        FROM Coordinates
    )
SELECT DISTINCT
    p1.x,
    p1.y
FROM
    P AS p1
    JOIN P AS p2 ON p1.x = p2.y AND p1.y = p2.x AND p1.x <= p1.y AND p1.id != p2.id
ORDER BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<font face="monospace"><code>Coordinates</code></font></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| X           | int  |
| Y           | int  |
+-------------+------+
每一行包括 X 和 Y，都是整数。表格可能包含重复值。
</pre>

<p>如果两个坐标 <code>(X1, Y1)</code>&nbsp;和&nbsp;<code>(X2, Y2)</code> 满足条件 <code>X1 == Y2</code>&nbsp;和&nbsp;<code>X2 == Y1</code>，则它们被称为 <strong>对称</strong> 坐标。</p>

<p>编写一个解决方案，找出在所有这些对称坐标中，满足条件 <code>X1 &lt;= Y1</code>&nbsp;的唯一坐标。</p>

<p>按照<em> </em><code>X</code>&nbsp;和<em>&nbsp;</em><code>Y</code> 分别&nbsp;<strong>升序</strong> 排列结果表。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Coordinates table:
+----+----+
| X  | Y  |
+----+----+
| 20 | 20 |
| 20 | 20 |
| 20 | 21 |
| 23 | 22 |
| 22 | 23 |
| 21 | 20 |
+----+----+
<b>输出：</b>
+----+----+
| x  | y  |
+----+----+
| 20 | 20 |
| 20 | 21 |
| 22 | 23 |
+----+----+
<b>解释：</b>
- (20, 20) 和 (20, 20) 是对称坐标，因为 X1 == Y2 和 X2 == Y1。所以 (20, 20) 被显示为独特的坐标。
- (20, 21) 和 (21, 20) 是对称坐标，因为 X1 == Y2 和 X2 == Y1。然而，只有 (20, 21) 会被显示，因为 X1 &lt;= Y1。
- (23, 22) 和 (22, 23) 是对称坐标，因为 X1 == Y2 和 X2 == Y1。然而，只有 (22, 23) 会被显示，因为 X1 &lt;= Y1。
输出表按照 X 和 Y 升序排列。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + 自连接

我们可以使用窗口函数 `ROW_NUMBER()` 来为每一行添加一个自增的序号，然后再自连接两张表，连接条件为 `p1.x = p2.y AND p1.y = p2.x AND p1.x <= p1.y AND p1.id != p2.id`，最后再排序去重即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT
            ROW_NUMBER() OVER () AS id,
            x,
            y
        FROM Coordinates
    )
SELECT DISTINCT
    p1.x,
    p1.y
FROM
    P AS p1
    JOIN P AS p2 ON p1.x = p2.y AND p1.y = p2.x AND p1.x <= p1.y AND p1.id != p2.id
ORDER BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2979. 最贵的无法购买的商品 🔒](https://leetcode.cn/problems/most-expensive-item-that-can-not-be-bought){#2979}

{{< tabs "2979" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostExpensiveItem(self, primeOne: int, primeTwo: int) -> int:
        return primeOne * primeTwo - primeOne - primeTwo
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mostExpensiveItem(int primeOne, int primeTwo) {
        return primeOne * primeTwo - primeOne - primeTwo;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        return primeOne * primeTwo - primeOne - primeTwo;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostExpensiveItem(primeOne int, primeTwo int) int {
	return primeOne*primeTwo - primeOne - primeTwo
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostExpensiveItem(primeOne: number, primeTwo: number): number {
    return primeOne * primeTwo - primeOne - primeTwo;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn most_expensive_item(prime_one: i32, prime_two: i32) -> i32 {
        prime_one * prime_two - prime_one - prime_two
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个 <strong>不同的质数</strong>&nbsp;<code>primeOne</code>&nbsp;和&nbsp;<code>primeTwo</code>。</p>

<p>Alice 和 Bob 正在逛市场。该市场有 <strong>无数种&nbsp;</strong>商品，对于 <strong>任何</strong> 正整数 <code>x</code>，都存在一个价格为 <code>x</code> 的物品。Alice 想从市场里买一些东西送给 Bob。她有 <b>无数个</b>&nbsp;面值为 <code>primeOne</code> 和 <code>primeTwo</code> 的硬币。她想知道她 <strong>无法</strong>&nbsp;用她拥有的硬币购买的 <strong>最贵</strong> 商品的价格。</p>

<p>返回 <em>Alice 无法买给&nbsp;Bob 的 <strong>最贵</strong> 商品的价格。</em></p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>primeOne = 2, primeTwo = 5
<b>输出：</b>3
<b>解释：</b>无法购买的商品的价格有 [1,3]。所有价格大于 3 的商品都可以通过组合使用面额为 2 和 5 的硬币购买。
</pre>

<p><b>示例 2:</b></p>

<pre>
<b>输入：</b>primeOne = 5, primeTwo = 7
<b>输出：</b>23
<b>解释：</b>无法购买的商品的价格有 [1,2,3,4,6,8,9,11,13,16,18,23]。所有价格大于 23 的商品都可以购买。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt; primeOne, primeTwo &lt; 10<sup>4</sup></code></li>
	<li><code>primeOne</code>, <code>primeTwo</code>&nbsp;都是质数。</li>
	<li><code>primeOne * primeTwo &lt; 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Chicken McNugget 定理

根据 Chicken McNugget 定理，两个互质的正整数 $a$ 和 $b$，最大不能表示的数为 $ab - a - b$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostExpensiveItem(self, primeOne: int, primeTwo: int) -> int:
        return primeOne * primeTwo - primeOne - primeTwo
```

#### Java

```java
class Solution {
    public int mostExpensiveItem(int primeOne, int primeTwo) {
        return primeOne * primeTwo - primeOne - primeTwo;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        return primeOne * primeTwo - primeOne - primeTwo;
    }
};
```

#### Go

```go
func mostExpensiveItem(primeOne int, primeTwo int) int {
	return primeOne*primeTwo - primeOne - primeTwo
}
```

#### TypeScript

```ts
function mostExpensiveItem(primeOne: number, primeTwo: number): number {
    return primeOne * primeTwo - primeOne - primeTwo;
}
```

#### Rust

```rust
impl Solution {
    pub fn most_expensive_item(prime_one: i32, prime_two: i32) -> i32 {
        prime_one * prime_two - prime_one - prime_two
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
