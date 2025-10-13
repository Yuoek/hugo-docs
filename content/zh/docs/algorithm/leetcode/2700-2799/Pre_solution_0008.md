---
title: "2770_达到末尾下标所需的最大跳跃次数"
date: 2025-10-08T18:39:33+08:00
weight: 8
tags: [JavaScript, 二分查找, 二叉树, 前缀和, 动态规划, 广度优先搜索, 排序, 数组, 枚举, 树, 深度优先搜索, 滑动窗口]
---

{{< markmap >}}
### [2770_达到末尾下标所需的最大跳跃次数](#2770)
#### [数组](#2770)
#### [动态规划](#2770)
### [2771_构造最长非递减子数组](#2771)
#### [数组](#2771)
#### [动态规划](#2771)
### [2772_使数组中的所有元素都等于零](#2772)
#### [数组](#2772)
#### [前缀和](#2772)
### [2773_特殊二叉树的高度 🔒](#2773)
#### [树](#2773)
#### [深度优先搜索](#2773)
#### [广度优先搜索](#2773)
#### [二叉树](#2773)
### [2774_数组的上界 🔒](#2774)
#### [JavaScript](#2774)
### [2775_将 undefined 转为 null 🔒](#2775)
#### [JavaScript](#2775)
### [2776_转换回调函数为 Promise 函数 🔒](#2776)
#### [JavaScript](#2776)
### [2777_日期范围生成器 🔒](#2777)
#### [JavaScript](#2777)
### [2778_特殊元素平方和](#2778)
#### [数组](#2778)
#### [枚举](#2778)
### [2779_数组的最大美丽值](#2779)
#### [数组](#2779)
#### [二分查找](#2779)
#### [排序](#2779)
#### [滑动窗口](#2779)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2770_达到末尾下标所需的最大跳跃次数
___
#### 数组
___
#### 动态规划
---
### 2771_构造最长非递减子数组
___
#### 数组
___
#### 动态规划
---
### 2772_使数组中的所有元素都等于零
___
#### 数组
___
#### 前缀和
---
### 2773_特殊二叉树的高度 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 2774_数组的上界 🔒
___
#### JavaScript
---
### 2775_将 undefined 转为 null 🔒
___
#### JavaScript
---
### 2776_转换回调函数为 Promise 函数 🔒
___
#### JavaScript
---
### 2777_日期范围生成器 🔒
___
#### JavaScript
---
### 2778_特殊元素平方和
___
#### 数组
___
#### 枚举
---
### 2779_数组的最大美丽值
___
#### 数组
___
#### 二分查找
___
#### 排序
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 二叉树 |
| 前缀和 | 动态规划 | 广度优先搜索 |
| 排序 | 数组 | 枚举 |
| 树 | 深度优先搜索 | 滑动窗口 |

# [2770. 达到末尾下标所需的最大跳跃次数](https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index){#2770}

{{< tabs "2770" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if i == n - 1:
                return 0
            ans = -inf
            for j in range(i + 1, n):
                if abs(nums[i] - nums[j]) <= target:
                    ans = max(ans, 1 + dfs(j))
            return ans

        n = len(nums)
        ans = dfs(0)
        return -1 if ans < 0 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[] f;
    private int[] nums;
    private int n;
    private int target;

    public int maximumJumps(int[] nums, int target) {
        n = nums.length;
        this.target = target;
        this.nums = nums;
        f = new Integer[n];
        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }

    private int dfs(int i) {
        if (i == n - 1) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int ans = -(1 << 30);
        for (int j = i + 1; j < n; ++j) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                ans = Math.max(ans, 1 + dfs(j));
            }
        }
        return f[i] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int f[n];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i == n - 1) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = -(1 << 30);
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= target) {
                    f[i] = max(f[i], 1 + dfs(j));
                }
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumJumps(nums []int, target int) int {
	n := len(nums)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i == n-1 {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		f[i] = -(1 << 30)
		for j := i + 1; j < n; j++ {
			if abs(nums[i]-nums[j]) <= target {
				f[i] = max(f[i], 1+dfs(j))
			}
		}
		return f[i]
	}
	ans := dfs(0)
	if ans < 0 {
		return -1
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumJumps(nums: number[], target: number): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (i === n - 1) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        f[i] = -(1 << 30);
        for (let j = i + 1; j < n; ++j) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                f[i] = Math.max(f[i], 1 + dfs(j));
            }
        }
        return f[i];
    };
    const ans = dfs(0);
    return ans < 0 ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、由 <code>n</code> 个整数组成的数组 <code>nums</code> 和一个整数 <code>target</code> 。</p>

<p>你的初始位置在下标 <code>0</code> 。在一步操作中，你可以从下标 <code>i</code> 跳跃到任意满足下述条件的下标 <code>j</code> ：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code></li>
	<li><code>-target &lt;= nums[j] - nums[i] &lt;= target</code></li>
</ul>

<p>返回到达下标 <code>n - 1</code> 处所需的 <strong>最大跳跃次数</strong> 。</p>

<p>如果无法到达下标 <code>n - 1</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,6,4,1,2], target = 2
<strong>输出：</strong>3
<strong>解释：</strong>要想以最大跳跃次数从下标 0 到下标 n - 1 ，可以按下述跳跃序列执行操作：
- 从下标 0 跳跃到下标 1 。 
- 从下标 1 跳跃到下标 3 。 
- 从下标 3 跳跃到下标 5 。 
可以证明，从 0 到 n - 1 的所有方案中，不存在比 3 步更长的跳跃序列。因此，答案是 3 。 </pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,6,4,1,2], target = 3
<strong>输出：</strong>5
<strong>解释：</strong>要想以最大跳跃次数从下标 0 到下标 n - 1 ，可以按下述跳跃序列执行操作：
- 从下标 0 跳跃到下标 1 。 
- 从下标 1 跳跃到下标 2 。 
- 从下标 2 跳跃到下标 3 。 
- 从下标 3 跳跃到下标 4 。 
- 从下标 4 跳跃到下标 5 。 
可以证明，从 0 到 n - 1 的所有方案中，不存在比 5 步更长的跳跃序列。因此，答案是 5 。 </pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,6,4,1,2], target = 0
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明不存在从 0 到 n - 1 的跳跃序列。因此，答案是 -1 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length == n &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= target &lt;= 2 * 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

对于每个位置 $i$，我们考虑向后搜索能跳到的位置 $j$，如果满足 $|nums[i] - nums[j]| \leq target$，那么我们就可以从 $i$ 跳到 $j$，并且从 $j$ 开始继续向后搜索。

因此，我们设计一个函数 $dfs(i)$，表示从位置 $i$ 开始跳跃到末尾下标所需的最大跳跃次数。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i = n - 1$，那么我们已经到达了末尾下标，不需要跳跃，因此返回 $0$；
-   否则，我们需要枚举从位置 $i$ 开始能跳到的位置 $j$，并计算从 $j$ 开始跳跃到末尾下标所需的最大跳跃次数，那么 $dfs(i)$ 就等于所有 $dfs(j)$ 中的最大值加 $1$。如果不存在从 $i$ 开始能跳到的位置 $j$，那么 $dfs(i) = -\infty$。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if i == n - 1:
                return 0
            ans = -inf
            for j in range(i + 1, n):
                if abs(nums[i] - nums[j]) <= target:
                    ans = max(ans, 1 + dfs(j))
            return ans

        n = len(nums)
        ans = dfs(0)
        return -1 if ans < 0 else ans
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] nums;
    private int n;
    private int target;

    public int maximumJumps(int[] nums, int target) {
        n = nums.length;
        this.target = target;
        this.nums = nums;
        f = new Integer[n];
        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }

    private int dfs(int i) {
        if (i == n - 1) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int ans = -(1 << 30);
        for (int j = i + 1; j < n; ++j) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                ans = Math.max(ans, 1 + dfs(j));
            }
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int f[n];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i == n - 1) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = -(1 << 30);
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= target) {
                    f[i] = max(f[i], 1 + dfs(j));
                }
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
};
```

#### Go

```go
func maximumJumps(nums []int, target int) int {
	n := len(nums)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i == n-1 {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		f[i] = -(1 << 30)
		for j := i + 1; j < n; j++ {
			if abs(nums[i]-nums[j]) <= target {
				f[i] = max(f[i], 1+dfs(j))
			}
		}
		return f[i]
	}
	ans := dfs(0)
	if ans < 0 {
		return -1
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function maximumJumps(nums: number[], target: number): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (i === n - 1) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        f[i] = -(1 << 30);
        for (let j = i + 1; j < n; ++j) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                f[i] = Math.max(f[i], 1 + dfs(j));
            }
        }
        return f[i];
    };
    const ans = dfs(0);
    return ans < 0 ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2771. 构造最长非递减子数组](https://leetcode.cn/problems/longest-non-decreasing-subarray-from-two-arrays){#2771}

{{< tabs "2771" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        f = g = 1
        ans = 1
        for i in range(1, n):
            ff = gg = 1
            if nums1[i] >= nums1[i - 1]:
                ff = max(ff, f + 1)
            if nums1[i] >= nums2[i - 1]:
                ff = max(ff, g + 1)
            if nums2[i] >= nums1[i - 1]:
                gg = max(gg, f + 1)
            if nums2[i] >= nums2[i - 1]:
                gg = max(gg, g + 1)
            f, g = ff, gg
            ans = max(ans, f, g)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxNonDecreasingLength(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int f = 1, g = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int ff = 1, gg = 1;
            if (nums1[i] >= nums1[i - 1]) {
                ff = Math.max(ff, f + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                ff = Math.max(ff, g + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                gg = Math.max(gg, f + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                gg = Math.max(gg, g + 1);
            }
            f = ff;
            g = gg;
            ans = Math.max(ans, Math.max(f, g));
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
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f = 1, g = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int ff = 1, gg = 1;
            if (nums1[i] >= nums1[i - 1]) {
                ff = max(ff, f + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                ff = max(ff, g + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                gg = max(gg, f + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                gg = max(gg, g + 1);
            }
            f = ff;
            g = gg;
            ans = max(ans, max(f, g));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNonDecreasingLength(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f, g, ans := 1, 1, 1
	for i := 1; i < n; i++ {
		ff, gg := 1, 1
		if nums1[i] >= nums1[i-1] {
			ff = max(ff, f+1)
		}
		if nums1[i] >= nums2[i-1] {
			ff = max(ff, g+1)
		}
		if nums2[i] >= nums1[i-1] {
			gg = max(gg, f+1)
		}
		if nums2[i] >= nums2[i-1] {
			gg = max(gg, g+1)
		}
		f, g = ff, gg
		ans = max(ans, max(f, g))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNonDecreasingLength(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    let [f, g, ans] = [1, 1, 1];
    for (let i = 1; i < n; ++i) {
        let [ff, gg] = [1, 1];
        if (nums1[i] >= nums1[i - 1]) {
            ff = Math.max(ff, f + 1);
        }
        if (nums1[i] >= nums2[i - 1]) {
            ff = Math.max(ff, g + 1);
        }
        if (nums2[i] >= nums1[i - 1]) {
            gg = Math.max(gg, f + 1);
        }
        if (nums2[i] >= nums2[i - 1]) {
            gg = Math.max(gg, g + 1);
        }
        f = ff;
        g = gg;
        ans = Math.max(ans, f, g);
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

<p>给你两个下标从 <strong>0</strong> 开始的整数数组 <code>nums1</code> 和 <code>nums2</code> ，长度均为 <code>n</code> 。</p>

<p>让我们定义另一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组，<code>nums3</code> 。对于范围&nbsp;<code>[0, n - 1]</code> 的每个下标 <code>i</code> ，你可以将 <code>nums1[i]</code> 或 <code>nums2[i]</code> 的值赋给 <code>nums3[i]</code> 。</p>

<p>你的任务是使用最优策略为 <code>nums3</code> 赋值，以最大化 <code>nums3</code> 中 <strong>最长非递减子数组</strong> 的长度。</p>

<p>以整数形式表示并返回 <code>nums3</code> 中 <strong>最长非递减</strong> 子数组的长度。</p>

<p><strong>注意：子数组</strong> 是数组中的一个连续非空元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums1 = [2,3,1], nums2 = [1,2,1]
<strong>输出：</strong>2
<strong>解释：</strong>构造 nums3 的方法之一是： 
nums3 = [nums1[0], nums2[1], nums2[2]] =&gt; [2,2,1]
从下标 0 开始到下标 1 结束，形成了一个长度为 2 的非递减子数组 [2,2] 。 
可以证明 2 是可达到的最大长度。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,3,2,1], nums2 = [2,2,3,4]
<strong>输出：</strong>4
<strong>解释：</strong>构造 nums3 的方法之一是： 
nums3 = [nums1[0], nums2[1], nums2[2], nums2[3]] =&gt; [1,2,3,4]
整个数组形成了一个长度为 4 的非递减子数组，并且是可达到的最大长度。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,1], nums2 = [2,2]
<strong>输出：</strong>2
<strong>解释：</strong>构造 nums3 的方法之一是： 
nums3 = [nums1[0], nums1[1]] =&gt; [1,1] 
整个数组形成了一个长度为 2 的非递减子数组，并且是可达到的最大长度。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length == nums2.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义两个变量 $f$ 和 $g$，分别表示当前位置的最长非递减子数组长度，其中 $f$ 表示以 $nums1$ 元素为结尾的最长非递减子数组长度，而 $g$ 表示以 $nums2$ 元素为结尾的最长非递减子数组长度。初始时 $f = g = 1$，初始答案 $ans = 1$。

接下来，我们在 $i \in [1, n)$ 的范围内遍历数组元素，对于每个 $i$，我们定义两个变量 $ff$ 和 $gg$，分别表示以 $nums1[i]$ 和 $nums2[i]$ 元素为结尾的最长非递减子数组长度，初始化时 $ff = gg = 1$。

我们可以通过 $f$ 和 $g$ 的值来计算出 $ff$ 和 $gg$ 的值：

-   如果 $nums1[i] \ge nums1[i - 1]$，那么 $ff = \max(ff, f + 1)$；
-   如果 $nums1[i] \ge nums2[i - 1]$，那么 $ff = \max(ff, g + 1)$；
-   如果 $nums2[i] \ge nums1[i - 1]$，那么 $gg = \max(gg, f + 1)$；
-   如果 $nums2[i] \ge nums2[i - 1]$，那么 $gg = \max(gg, g + 1)$。

然后，我们更新 $f = ff$ 和 $g = gg$，并将 $ans$ 更新为 $\max(ans, f, g)$。

遍历结束后，我们返回 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        f = g = 1
        ans = 1
        for i in range(1, n):
            ff = gg = 1
            if nums1[i] >= nums1[i - 1]:
                ff = max(ff, f + 1)
            if nums1[i] >= nums2[i - 1]:
                ff = max(ff, g + 1)
            if nums2[i] >= nums1[i - 1]:
                gg = max(gg, f + 1)
            if nums2[i] >= nums2[i - 1]:
                gg = max(gg, g + 1)
            f, g = ff, gg
            ans = max(ans, f, g)
        return ans
```

#### Java

```java
class Solution {
    public int maxNonDecreasingLength(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int f = 1, g = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int ff = 1, gg = 1;
            if (nums1[i] >= nums1[i - 1]) {
                ff = Math.max(ff, f + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                ff = Math.max(ff, g + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                gg = Math.max(gg, f + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                gg = Math.max(gg, g + 1);
            }
            f = ff;
            g = gg;
            ans = Math.max(ans, Math.max(f, g));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f = 1, g = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int ff = 1, gg = 1;
            if (nums1[i] >= nums1[i - 1]) {
                ff = max(ff, f + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                ff = max(ff, g + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                gg = max(gg, f + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                gg = max(gg, g + 1);
            }
            f = ff;
            g = gg;
            ans = max(ans, max(f, g));
        }
        return ans;
    }
};
```

#### Go

```go
func maxNonDecreasingLength(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f, g, ans := 1, 1, 1
	for i := 1; i < n; i++ {
		ff, gg := 1, 1
		if nums1[i] >= nums1[i-1] {
			ff = max(ff, f+1)
		}
		if nums1[i] >= nums2[i-1] {
			ff = max(ff, g+1)
		}
		if nums2[i] >= nums1[i-1] {
			gg = max(gg, f+1)
		}
		if nums2[i] >= nums2[i-1] {
			gg = max(gg, g+1)
		}
		f, g = ff, gg
		ans = max(ans, max(f, g))
	}
	return ans
}
```

#### TypeScript

```ts
function maxNonDecreasingLength(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    let [f, g, ans] = [1, 1, 1];
    for (let i = 1; i < n; ++i) {
        let [ff, gg] = [1, 1];
        if (nums1[i] >= nums1[i - 1]) {
            ff = Math.max(ff, f + 1);
        }
        if (nums1[i] >= nums2[i - 1]) {
            ff = Math.max(ff, g + 1);
        }
        if (nums2[i] >= nums1[i - 1]) {
            gg = Math.max(gg, f + 1);
        }
        if (nums2[i] >= nums2[i - 1]) {
            gg = Math.max(gg, g + 1);
        }
        f = ff;
        g = gg;
        ans = Math.max(ans, f, g);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2772. 使数组中的所有元素都等于零](https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero){#2772}

{{< tabs "2772" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        d = [0] * (n + 1)
        s = 0
        for i, x in enumerate(nums):
            s += d[i]
            x += s
            if x == 0:
                continue
            if x < 0 or i + k > n:
                return False
            s -= x
            d[i + k] += x
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkArray(int[] nums, int k) {
        int n = nums.length;
        int[] d = new int[n + 1];
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            nums[i] += s;
            if (nums[i] == 0) {
                continue;
            }
            if (nums[i] < 0 || i + k > n) {
                return false;
            }
            s -= nums[i];
            d[i + k] += nums[i];
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> d(n + 1);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            nums[i] += s;
            if (nums[i] == 0) {
                continue;
            }
            if (nums[i] < 0 || i + k > n) {
                return false;
            }
            s -= nums[i];
            d[i + k] += nums[i];
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkArray(nums []int, k int) bool {
	n := len(nums)
	d := make([]int, n+1)
	s := 0
	for i, x := range nums {
		s += d[i]
		x += s
		if x == 0 {
			continue
		}
		if x < 0 || i+k > n {
			return false
		}
		s -= x
		d[i+k] += x
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkArray(nums: number[], k: number): boolean {
    const n = nums.length;
    const d: number[] = Array(n + 1).fill(0);
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s += d[i];
        nums[i] += s;
        if (nums[i] === 0) {
            continue;
        }
        if (nums[i] < 0 || i + k > n) {
            return false;
        }
        s -= nums[i];
        d[i + k] += nums[i];
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个正整数 <code>k</code> 。</p>

<p>你可以对数组执行下述操作 <strong>任意次</strong> ：</p>

<ul>
	<li>从数组中选出长度为 <code>k</code> 的 <strong>任一</strong> 子数组，并将子数组中每个元素都 <strong>减去</strong> <code>1</code> 。</li>
</ul>

<p>如果你可以使数组中的所有元素都等于 <code>0</code> ，返回&nbsp; <code>true</code><em> </em>；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p><strong>子数组</strong> 是数组中的一个非空连续元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,2,3,1,1,0], k = 3
<strong>输出：</strong>true
<strong>解释：</strong>可以执行下述操作：
- 选出子数组 [2,2,3] ，执行操作后，数组变为 nums = [<em><strong>1</strong></em>,<em><strong>1</strong></em>,<em><strong>2</strong></em>,1,1,0] 。
- 选出子数组 [2,1,1] ，执行操作后，数组变为 nums = [1,1,<em><strong>1</strong></em>,<em><strong>0</strong></em>,<em><strong>0</strong></em>,0] 。
- 选出子数组 [1,1,1] ，执行操作后，数组变为 nums = [<em><strong>0</strong></em>,<em><strong>0</strong></em>,<em><strong>0</strong></em>,0,0,0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,1,1], k = 2
<strong>输出：</strong>false
<strong>解释：</strong>无法使数组中的所有元素等于 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组 + 前缀和

我们先考虑 $nums$ 的第一个元素 $nums[0]$：

-   如果 $nums[0] = 0$，那么我们可以不用操作；
-   如果 $nums[0] \gt 0$，那么我们需要对 $nums[0..k-1]$ 操作 $nums[0]$ 次，使得 $nums[0..k-1]$ 中的元素都减去 $nums[0]$，这样 $nums[0]$ 就变成了 $0$。

对一段连续的元素同时进行加减操作，我们可以使用差分数组来维护这些操作，我们用 $d[i]$ 表示差分数组，对差分数组求前缀和，就可以得到每个位置的数值的变化量。

因此，我们遍历 $nums$，对于每个元素 $nums[i]$，当前位置的变化量 $s = \sum_{j=0}^{i} d[j]$，我们将 $nums[i]$ 加上 $s$，就得到了当前 $nums[i]$ 的实际值。

-   如果 $nums[i] = 0$，那么无须进行操作，直接跳过。
-   如果 $nums[i]=0$，或者 $i + k \gt n$，说明经过前面的操作，$nums[i]$ 已经变成了负数，或者 $nums[i..i+k-1]$ 越界，那么无法使得 $nums$ 中的所有元素都等于 $0$，返回 `false`。否则，我们需要将 $[i..i+k-1]$ 这段区间的所有元素都减去 $nums[i]$，因此我们将 $s$ 减去 $nums[i]$，并将 $d[i+k]$ 加上 $nums[i]$。
-   继续遍历下一个元素。

遍历结束，说明可以使得 $nums$ 中的所有元素都等于 $0$，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        d = [0] * (n + 1)
        s = 0
        for i, x in enumerate(nums):
            s += d[i]
            x += s
            if x == 0:
                continue
            if x < 0 or i + k > n:
                return False
            s -= x
            d[i + k] += x
        return True
```

#### Java

```java
class Solution {
    public boolean checkArray(int[] nums, int k) {
        int n = nums.length;
        int[] d = new int[n + 1];
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            nums[i] += s;
            if (nums[i] == 0) {
                continue;
            }
            if (nums[i] < 0 || i + k > n) {
                return false;
            }
            s -= nums[i];
            d[i + k] += nums[i];
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> d(n + 1);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            nums[i] += s;
            if (nums[i] == 0) {
                continue;
            }
            if (nums[i] < 0 || i + k > n) {
                return false;
            }
            s -= nums[i];
            d[i + k] += nums[i];
        }
        return true;
    }
};
```

#### Go

```go
func checkArray(nums []int, k int) bool {
	n := len(nums)
	d := make([]int, n+1)
	s := 0
	for i, x := range nums {
		s += d[i]
		x += s
		if x == 0 {
			continue
		}
		if x < 0 || i+k > n {
			return false
		}
		s -= x
		d[i+k] += x
	}
	return true
}
```

#### TypeScript

```ts
function checkArray(nums: number[], k: number): boolean {
    const n = nums.length;
    const d: number[] = Array(n + 1).fill(0);
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s += d[i];
        nums[i] += s;
        if (nums[i] === 0) {
            continue;
        }
        if (nums[i] < 0 || i + k > n) {
            return false;
        }
        s -= nums[i];
        d[i + k] += nums[i];
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2773. 特殊二叉树的高度 🔒](https://leetcode.cn/problems/height-of-special-binary-tree){#2773}

{{< tabs "2773" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def heightOfTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], d: int):
            nonlocal ans
            ans = max(ans, d)
            if root.left and root.left.right != root:
                dfs(root.left, d + 1)
            if root.right and root.right.left != root:
                dfs(root.right, d + 1)

        ans = 0
        dfs(root, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;

    public int heightOfTree(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int d) {
        ans = Math.max(ans, d++);
        if (root.left != null && root.left.right != root) {
            dfs(root.left, d);
        }
        if (root.right != null && root.right.left != root) {
            dfs(root.right, d);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int heightOfTree(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            ans = max(ans, d++);
            if (root->left && root->left->right != root) {
                dfs(root->left, d);
            }
            if (root->right && root->right->left != root) {
                dfs(root->right, d);
            }
        };
        dfs(root, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func heightOfTree(root *TreeNode) (ans int) {
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, d int) {
		if ans < d {
			ans = d
		}
		d++
		if root.Left != nil && root.Left.Right != root {
			dfs(root.Left, d)
		}
		if root.Right != nil && root.Right.Left != root {
			dfs(root.Right, d)
		}
	}
	dfs(root, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function heightOfTree(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null, d: number) => {
        ans = Math.max(ans, d++);
        if (root.left && root.left.right !== root) {
            dfs(root.left, d);
        }
        if (root.right && root.right.left !== root) {
            dfs(root.right, d);
        }
    };
    dfs(root, 0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵具有 <code>n</code> 个节点的 <strong>特殊</strong> 二叉树的根节点 <code>root</code> 。特殊二叉树的节点编号从 <code>1</code> 到 <code>n</code> 。假设这棵树有 <code>k</code> 个叶子，顺序如下：<code>b<sub>1</sub> &lt; b<sub>2</sub> &lt; ... &lt; b<sub>k</sub></code> 。</p>

<p>这棵树的叶子节点有一个 <strong>特殊</strong> 属性 ！对于每个叶子节点 <code>b<sub>i</sub></code> ，满足以下条件：</p>

<ul>
	<li>如果 <code>i &lt; k</code> ，则 <code>b<sub>i</sub></code> 的右子节点为 <code>b<sub>i&nbsp;</sub><sub>+ 1</sub></code> ；否则为 <code>b<sub>1</sub></code> 。</li>
	<li>如果 <code>i &gt; 1</code> ，则 <code>b<sub>i</sub></code> 的左子节点为 <code>b<sub>i&nbsp;</sub><sub>- 1</sub></code> ；否则为 <code>b<sub>k</sub></code> 。</li>
</ul>

<p>返回给定树的高度。</p>

<p><strong>注意</strong>：二叉树的高度是指从根节点到任何其他节点的 <strong>最长路径</strong> 的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1;</strong></p>

<pre>
<b>输入：</b>root = [1,2,3,null,null,4,5]
<b>输出：</b>2
<strong>解释：给</strong>定树如下图所示。每个叶子节点的左子节点是它左边的叶子节点（用蓝色边表示）。每个叶子节点的右子节点是它右边的叶子节点（用红色边表示）。我们可以看出，该图的高度为2。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2773.Height%20of%20Special%20Binary%20Tree/images/1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 200px; height: 200px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>root = [1,2]
<b>输出：</b>1
<b>解释：</b>给定树如下图所示。只有一个叶子节点，所以它没有左子节点或右子节点。我们可以看出，该图的高度为 1。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2773.Height%20of%20Special%20Binary%20Tree/images/2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 95px; height: 122px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>root = [1,2,3,null,null,4,null,5,6]
<b>输出：</b>3
<strong>解释：</strong>给定树如下图所示。每个叶子节点的左子节点是它左边的叶子节点（用蓝色边表示）。每个叶子节点的右子节点是它右边的叶子节点（用红色边表示）。我们可以看出，该图的高度为3。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2773.Height%20of%20Special%20Binary%20Tree/images/3.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 200px; height: 280px;" /></p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n 为树中节点的数量</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= node.val &lt;= n</code></li>
	<li>输入保证每个 <code>node.val</code> 的值是唯一的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

题目的关键在于如何判断一个节点是叶子节点，我们设计一个函数 $dfs(root, d)$，其中 $root$ 表示当前节点，而 $d$ 表示当前节点的深度，我们每次搜索时，更新答案 $ans = \max(ans, d)$，然后判断当前节点是否为叶子节点，如果当前节点有左子节点，且左子节点的右子节点不是当前节点，那么我们递归调用 $dfs(root.left, d + 1)$，如果当前节点有右子节点，且右子节点的左子节点不是当前节点，那么我们递归调用 $dfs(root.right, d + 1)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def heightOfTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], d: int):
            nonlocal ans
            ans = max(ans, d)
            if root.left and root.left.right != root:
                dfs(root.left, d + 1)
            if root.right and root.right.left != root:
                dfs(root.right, d + 1)

        ans = 0
        dfs(root, 0)
        return ans
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;

    public int heightOfTree(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int d) {
        ans = Math.max(ans, d++);
        if (root.left != null && root.left.right != root) {
            dfs(root.left, d);
        }
        if (root.right != null && root.right.left != root) {
            dfs(root.right, d);
        }
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int heightOfTree(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            ans = max(ans, d++);
            if (root->left && root->left->right != root) {
                dfs(root->left, d);
            }
            if (root->right && root->right->left != root) {
                dfs(root->right, d);
            }
        };
        dfs(root, 0);
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func heightOfTree(root *TreeNode) (ans int) {
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, d int) {
		if ans < d {
			ans = d
		}
		d++
		if root.Left != nil && root.Left.Right != root {
			dfs(root.Left, d)
		}
		if root.Right != nil && root.Right.Left != root {
			dfs(root.Right, d)
		}
	}
	dfs(root, 0)
	return
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function heightOfTree(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null, d: number) => {
        ans = Math.max(ans, d++);
        if (root.left && root.left.right !== root) {
            dfs(root.left, d);
        }
        if (root.right && root.right.left !== root) {
            dfs(root.right, d);
        }
    };
    dfs(root, 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2774. 数组的上界 🔒](https://leetcode.cn/problems/array-upper-bound){#2774}

{{< tabs "2774" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function (target: number) {
    return this.lastIndexOf(target);
};

// [3,4,5].upperBound(5); // 2
// [1,4,5].upperBound(2); // -1
// [3,4,6,6,6,6,7].upperBound(6) // 5
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写代码实现一个数组方法，任何数组都可以调用&nbsp;<code>upperBound()</code>&nbsp;方法，并返回给定目标数字的最后一个索引。<code>nums</code>&nbsp;是一个可能包含重复数字的按升序排序的数组。如果在数组中找不到目标数字，则返回-1。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>nums = [3,4,5], target = 5
<b>输出：</b>2
<b>解释：</b>目标值的最后一个索引是 2
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,5], target = 2
<b>输出：</b>-1
<b>解释：</b>因为数组中没有数字 2，所以返回 -1。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,4,6,6,6,6,7], target = 6
<b>输出：</b>5
<b>解释：</b>目标值的最后一个索引是 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code><font face="monospace">-10<sup>4</sup>&nbsp;&lt;= nums[i], target &lt;= 10<sup>4</sup></font></code></li>
	<li><code>nums</code>&nbsp;按升序排序。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能编写一个时间复杂度为 O(log n) 的算法吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### TypeScript

```ts
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function (target: number) {
    let left = 0;
    let right = this.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (this[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left > 0 && this[left - 1] == target ? left - 1 : -1;
};

// [3,4,5].upperBound(5); // 2
// [1,4,5].upperBound(2); // -1
// [3,4,6,6,6,6,7].upperBound(6) // 5
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function (target: number) {
    return this.lastIndexOf(target);
};

// [3,4,5].upperBound(5); // 2
// [1,4,5].upperBound(2); // -1
// [3,4,6,6,6,6,7].upperBound(6) // 5
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2775. 将 undefined 转为 null 🔒](https://leetcode.cn/problems/undefined-to-null){#2775}

{{< tabs "2775" >}}

{{% tab "ts" %}}
```ts
function undefinedToNull(obj: Record<any, any>): Record<any, any> {
    for (const key in obj) {
        if (typeof obj[key] === 'object') {
            obj[key] = undefinedToNull(obj[key]);
        }
        if (obj[key] === undefined) {
            obj[key] = null;
        }
    }
    return obj;
}

/**
 * undefinedToNull({"a": undefined, "b": 3}) // {"a": null, "b": 3}
 * undefinedToNull([undefined, undefined]) // [null, null]
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个深层嵌套的对象或数组 <code>obj</code> ，并创建该对象&nbsp;<code>obj</code> 的副本，将其中的任何 <code>undefined</code> 值替换为 <code>null</code> 。</p>

<p>当使用 <code>JSON.stringify()</code> 将对象转换为 JSON 字符串时，<code>undefined</code> 值与&nbsp;<code>null</code> 值的处理方式不同。该函数有助于确保序列化数据不会出现意外错误。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>obj = {"a": undefined, "b": 3}
<b>输出：</b>{"a": null, "b": 3}
<b>解释：</b>obj.a 的值已从 undefined 更改为 null 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>obj = {"a": undefined, "b": ["a", undefined]}
<b>输出：</b>{"a": null,"b": ["a", null]}
<b>解释：</b>obj.a 和 obj.b[1] 的值已从 undefined 更改为 null 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obj</code> 是一个有效的 JSON 对象或数组</li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### TypeScript

```ts
function undefinedToNull(obj: Record<any, any>): Record<any, any> {
    for (const key in obj) {
        if (typeof obj[key] === 'object') {
            obj[key] = undefinedToNull(obj[key]);
        }
        if (obj[key] === undefined) {
            obj[key] = null;
        }
    }
    return obj;
}

/**
 * undefinedToNull({"a": undefined, "b": 3}) // {"a": null, "b": 3}
 * undefinedToNull([undefined, undefined]) // [null, null]
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2776. 转换回调函数为 Promise 函数 🔒](https://leetcode.cn/problems/convert-callback-based-function-to-promise-based-function){#2776}

{{< tabs "2776" >}}

{{% tab "ts" %}}
```ts
type CallbackFn = (next: (data: number, error: string) => void, ...args: number[]) => void;
type Promisified = (...args: number[]) => Promise<number>;

function promisify(fn: CallbackFn): Promisified {
    return async function (...args) {
        return new Promise((resolve, reject) => {
            fn(
                (data, error) => {
                    if (error) {
                        reject(error);
                    } else {
                        resolve(data);
                    }
                },
                ...args,
            );
        });
    };
}

/**
 * const asyncFunc = promisify(callback => callback(42));
 * asyncFunc().then(console.log); // 42
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个函数，接受另一个函数 <code>fn</code> ，并将基于回调函数的函数转换为基于 Promise 的函数。</p>

<p><code>promisify</code> 函数接受一个函数 <code>fn</code> ，<code>fn</code> 将回调函数作为其第一个参数，并且还可以接受其他额外的参数。</p>

<p><code>promisfy</code> 返回一个新函数，新函数会返回一个 Promise 对象。当回调函数被成功调用时，新函数返回的 Promise 对象应该使用原始函数的结果进行解析；当回调函数被调用出现错误时，返回的 Promise 对象应该被拒绝并携带错误信息。最终返回的基于 Promise 的函数应该接受额外的参数作为输入。</p>

<p>以下是一个可以传递给 <code>promisify</code> 的函数示例：</p>

<pre>
function sum(callback, a, b) {
  if (a &lt; 0 || b &lt; 0) {
&nbsp;   const err = Error('a and b must be positive');
    callback(undefined, err);
&nbsp; } else {
    callback(a + b);
&nbsp; }
}
</pre>

<p>这是基于 Promise 的等效代码：</p>

<pre>
async function sum(a, b) {
  if (a &lt; 0 || b &lt; 0) {
    throw Error('a and b must be positive');
&nbsp; } else {
    return a + b;
&nbsp; }
}
</pre>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
fn = (callback, a, b, c) =&gt; {
  return callback(a * b * c);
}
args = [1, 2, 3]
<b>输出：</b>{"resolved": 6}
<b>解释：</b>
const asyncFunc = promisify(fn);
asyncFunc(1, 2, 3).then(console.log); // 6

fn 以回调函数作为第一个参数和 args 作为其余参数进行调用。当使用 (1, 2, 3) 调用时，基于 Promise 的 fn 将解析为值 6。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
fn = (callback, a, b, c) =&gt; {
&nbsp; callback(a * b * c, "Promise Rejected");
}
args = [4, 5, 6]
<b>输出：</b>{"rejected": "Promise Rejected"}
<b>解释：</b>
const asyncFunc = promisify(fn);
asyncFunc(4, 5, 6).catch(console.log); // "Promise Rejected"

fn 以回调函数作为第一个参数和 args 作为其余参数进行调用。在回调函数的第二个参数中，接受一个错误消息，因此当调用 fn 时，Promise 被拒绝并携带回调函数中提供的错误消息。请注意，不管将什么作为回调函数的第一个参数传递都无关紧要。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= args.length &lt;= 100</code></li>
	<li><code>0 &lt;= args[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### TypeScript

```ts
type CallbackFn = (next: (data: number, error: string) => void, ...args: number[]) => void;
type Promisified = (...args: number[]) => Promise<number>;

function promisify(fn: CallbackFn): Promisified {
    return async function (...args) {
        return new Promise((resolve, reject) => {
            fn(
                (data, error) => {
                    if (error) {
                        reject(error);
                    } else {
                        resolve(data);
                    }
                },
                ...args,
            );
        });
    };
}

/**
 * const asyncFunc = promisify(callback => callback(42));
 * asyncFunc().then(console.log); // 42
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2777. 日期范围生成器 🔒](https://leetcode.cn/problems/date-range-generator){#2777}

{{< tabs "2777" >}}

{{% tab "ts" %}}
```ts
function* dateRangeGenerator(start: string, end: string, step: number): Generator<string> {
    const startDate = new Date(start);
    const endDate = new Date(end);
    let currentDate = startDate;
    while (currentDate <= endDate) {
        yield currentDate.toISOString().slice(0, 10);
        currentDate.setDate(currentDate.getDate() + step);
    }
}

/**
 * const g = dateRangeGenerator('2023-04-01', '2023-04-04', 1);
 * g.next().value; // '2023-04-01'
 * g.next().value; // '2023-04-02'
 * g.next().value; // '2023-04-03'
 * g.next().value; // '2023-04-04'
 * g.next().done; // true
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定起始日期 <code>start</code> 、结束日期 <code>end</code> 和正整数 <code>step</code> ，返回一个生成器对象，该生成器对象按照从 <code>start</code> 到 <code>end</code>（包括 start 和 end ）的范围生成日期。</p>

<p><code>step</code> 的值表示连续生成的日期之间的天数间隔。</p>

<p>所有日期都以字符串格式 <code>YYYY-MM-DD</code> 表示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>start = "2023-04-01", end = "2023-04-04", step = 1
<b>输出：</b>["2023-04-01","2023-04-02","2023-04-03","2023-04-04"]
<b>解释：</b>
const g = dateRangeGenerator(start, end, step);
g.next().value // '2023-04-01'
g.next().value // '2023-04-02'
g.next().value // '2023-04-03'
g.next().value // '2023-04-04'</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>start = "2023-04-10", end = "2023-04-20", step = 3
<b>输出：</b>["2023-04-10","2023-04-13","2023-04-16","2023-04-19"]
<b>解释：</b>
const g = dateRangeGenerator(start, end, step);
g.next().value // '2023-04-10'
g.next().value // '2023-04-13'
g.next().value // '2023-04-16'
g.next().value // '2023-04-19'</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>start = "2023-04-10", end = "2023-04-10", step = 1
<b>输出：</b>["2023-04-10"]
<b>解释：</b>
const g = dateRangeGenerator(start, end, step);
g.next().value // '2023-04-10'
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>new Date(start) &lt;= new Date(end)</code></li>
	<li><code>start</code>&nbsp;和&nbsp;<code>end</code>&nbsp;的日期格式是&nbsp;<code>YYYY-MM-DD</code></li>
	<li><code>0 &lt;= 结束日期与开始日期之间的天数差 &lt;= 1500</code></li>
	<li><code>1 &lt;= step &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### TypeScript

```ts
function* dateRangeGenerator(start: string, end: string, step: number): Generator<string> {
    const startDate = new Date(start);
    const endDate = new Date(end);
    let currentDate = startDate;
    while (currentDate <= endDate) {
        yield currentDate.toISOString().slice(0, 10);
        currentDate.setDate(currentDate.getDate() + step);
    }
}

/**
 * const g = dateRangeGenerator('2023-04-01', '2023-04-04', 1);
 * g.next().value; // '2023-04-01'
 * g.next().value; // '2023-04-02'
 * g.next().value; // '2023-04-03'
 * g.next().value; // '2023-04-04'
 * g.next().done; // true
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2778. 特殊元素平方和](https://leetcode.cn/problems/sum-of-squares-of-special-elements){#2778}

{{< tabs "2778" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        return sum(x * x for i, x in enumerate(nums, 1) if n % i == 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfSquares(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
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
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfSquares(nums []int) (ans int) {
	n := len(nums)
	for i, x := range nums {
		if n%(i+1) == 0 {
			ans += x * x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfSquares(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (n % (i + 1) === 0) {
            ans += nums[i] * nums[i];
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

<p>给你一个下标从 <strong>1</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> 。</p>

<p>对 <code>nums</code> 中的元素 <code>nums[i]</code> 而言，如果 <code>n</code> 能够被 <code>i</code> 整除，即 <code>n % i == 0</code> ，则认为 <code>num[i]</code> 是一个 <strong>特殊元素</strong> 。</p>

<p>返回 <code>nums</code> 中所有 <strong>特殊元素</strong> 的 <strong>平方和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>21
<strong>解释：</strong>nums 中共有 3 个特殊元素：nums[1]，因为 4 被 1 整除；nums[2]，因为 4 被 2 整除；以及 nums[4]，因为 4 被 4 整除。 
因此，nums 中所有特殊元素的平方和等于 nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21 。  
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,7,1,19,18,3]
<strong>输出：</strong>63
<strong>解释：</strong>nums 中共有 4 个特殊元素：nums[1]，因为 6 被 1 整除；nums[2] ，因为 6 被 2 整除；nums[3]，因为 6 被 3 整除；以及 nums[6]，因为 6 被 6 整除。 
因此，nums 中所有特殊元素的平方和等于 nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63 。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举数组中的每个元素，判断其是否为特殊元素，如果是则将其平方加入答案中。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        return sum(x * x for i, x in enumerate(nums, 1) if n % i == 0)
```

#### Java

```java
class Solution {
    public int sumOfSquares(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
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
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                ans += nums[i - 1] * nums[i - 1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfSquares(nums []int) (ans int) {
	n := len(nums)
	for i, x := range nums {
		if n%(i+1) == 0 {
			ans += x * x
		}
	}
	return
}
```

#### TypeScript

```ts
function sumOfSquares(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (n % (i + 1) === 0) {
            ans += nums[i] * nums[i];
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

# [2779. 数组的最大美丽值](https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation){#2779}

{{< tabs "2779" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        m = max(nums) + k * 2 + 2
        d = [0] * m
        for x in nums:
            d[x] += 1
            d[x + k * 2 + 1] -= 1
        return max(accumulate(d))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int m = Arrays.stream(nums).max().getAsInt() + k * 2 + 2;
        int[] d = new int[m];
        for (int x : nums) {
            d[x]++;
            d[x + k * 2 + 1]--;
        }
        int ans = 0, s = 0;
        for (int x : d) {
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
    int maximumBeauty(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end()) + k * 2 + 2;
        vector<int> d(m);
        for (int x : nums) {
            d[x]++;
            d[x + k * 2 + 1]--;
        }
        int ans = 0, s = 0;
        for (int x : d) {
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
func maximumBeauty(nums []int, k int) (ans int) {
	m := slices.Max(nums)
	m += k*2 + 2
	d := make([]int, m)
	for _, x := range nums {
		d[x]++
		d[x+k*2+1]--
	}
	s := 0
	for _, x := range d {
		s += x
		if ans < s {
			ans = s
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBeauty(nums: number[], k: number): number {
    const m = Math.max(...nums) + k * 2 + 2;
    const d: number[] = Array(m).fill(0);
    for (const x of nums) {
        d[x]++;
        d[x + k * 2 + 1]--;
    }
    let ans = 0;
    let s = 0;
    for (const x of d) {
        s += x;
        ans = Math.max(ans, s);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个 <strong>非负</strong> 整数 <code>k</code> 。</p>

<p>在一步操作中，你可以执行下述指令：</p>

<ul>
	<li>在范围&nbsp;<code>[0, nums.length - 1]</code> 中选择一个 <strong>此前没有选过</strong> 的下标 <code>i</code> 。</li>
	<li>将 <code>nums[i]</code> 替换为范围 <code>[nums[i] - k, nums[i] + k]</code> 内的任一整数。</li>
</ul>

<p>数组的 <strong>美丽值</strong> 定义为数组中由相等元素组成的最长子序列的长度。</p>

<p>对数组 <code>nums</code> 执行上述操作任意次后，返回数组可能取得的 <strong>最大</strong> 美丽值。</p>

<p><strong>注意：</strong>你 <strong>只</strong> 能对每个下标执行 <strong>一次</strong> 此操作。</p>

<p>数组的 <strong>子序列</strong> 定义是：经由原数组删除一些元素（也可能不删除）得到的一个新数组，且在此过程中剩余元素的顺序不发生改变。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,6,1,2], k = 2
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，我们执行下述操作：
- 选择下标 1 ，将其替换为 4（从范围 [4,8] 中选出），此时 nums = [4,4,1,2] 。
- 选择下标 3 ，将其替换为 4（从范围 [0,4] 中选出），此时 nums = [4,4,1,4] 。
执行上述操作后，数组的美丽值是 3（子序列由下标 0 、1 、3 对应的元素组成）。
可以证明 3 是我们可以得到的由相等元素组成的最长子序列长度。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1], k = 10
<strong>输出：</strong>4
<strong>解释：</strong>在这个示例中，我们无需执行任何操作。
数组 nums 的美丽值是 4（整个数组）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们注意到，对于每一次操作，区间 $[nums[i]-k, nums[i]+k]$ 内的所有元素都会增加 $1$，因此我们可以使用差分数组来记录这些操作对美丽值的贡献。

题目中 $nums[i]-k$ 可能为负数，我们统一将所有元素加上 $k$，保证结果为非负数。因此，我们可以创建一个长度为 $\max(nums) + k \times 2 + 2$ 的差分数组 $d$。

接下来，遍历数组 $nums$，对于当前遍历到的元素 $x$，我们将 $d[x]$ 增加 $1$，将 $d[x+k\times2+1]$ 减少 $1$。这样，我们就可以通过 $d$ 数组计算出每个位置的前缀和，即为每个位置的美丽值。找到最大的美丽值即可。

时间复杂度 $O(M + 2 \times k + n)$，空间复杂度 $O(M + 2 \times k)$。其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        m = max(nums) + k * 2 + 2
        d = [0] * m
        for x in nums:
            d[x] += 1
            d[x + k * 2 + 1] -= 1
        return max(accumulate(d))
```

#### Java

```java
class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int m = Arrays.stream(nums).max().getAsInt() + k * 2 + 2;
        int[] d = new int[m];
        for (int x : nums) {
            d[x]++;
            d[x + k * 2 + 1]--;
        }
        int ans = 0, s = 0;
        for (int x : d) {
            s += x;
            ans = Math.max(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end()) + k * 2 + 2;
        vector<int> d(m);
        for (int x : nums) {
            d[x]++;
            d[x + k * 2 + 1]--;
        }
        int ans = 0, s = 0;
        for (int x : d) {
            s += x;
            ans = max(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumBeauty(nums []int, k int) (ans int) {
	m := slices.Max(nums)
	m += k*2 + 2
	d := make([]int, m)
	for _, x := range nums {
		d[x]++
		d[x+k*2+1]--
	}
	s := 0
	for _, x := range d {
		s += x
		if ans < s {
			ans = s
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumBeauty(nums: number[], k: number): number {
    const m = Math.max(...nums) + k * 2 + 2;
    const d: number[] = Array(m).fill(0);
    for (const x of nums) {
        d[x]++;
        d[x + k * 2 + 1]--;
    }
    let ans = 0;
    let s = 0;
    for (const x of d) {
        s += x;
        ans = Math.max(ans, s);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
