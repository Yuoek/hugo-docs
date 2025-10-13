---
title: "3010_将数组分成最小总代价的子数组 I"
date: 2025-10-08T18:39:55+08:00
weight: 2
tags: [位运算, 前缀和, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 数论, 枚举, 滑动窗口, 计数, 贪心]
---

{{< markmap >}}
### [3010_将数组分成最小总代价的子数组 I](#3010)
#### [数组](#3010)
#### [枚举](#3010)
#### [排序](#3010)
### [3011_判断一个数组是否可以变为有序](#3011)
#### [位运算](#3011)
#### [数组](#3011)
#### [排序](#3011)
### [3012_通过操作使数组长度最小](#3012)
#### [贪心](#3012)
#### [数组](#3012)
#### [数学](#3012)
#### [数论](#3012)
### [3013_将数组分成最小总代价的子数组 II](#3013)
#### [数组](#3013)
#### [哈希表](#3013)
#### [滑动窗口](#3013)
#### [堆（优先队列）](#3013)
### [3014_输入单词需要的最少按键次数 I](#3014)
#### [贪心](#3014)
#### [数学](#3014)
#### [字符串](#3014)
### [3015_按距离统计房屋对数目 I](#3015)
#### [广度优先搜索](#3015)
#### [图](#3015)
#### [前缀和](#3015)
### [3016_输入单词需要的最少按键次数 II](#3016)
#### [贪心](#3016)
#### [哈希表](#3016)
#### [字符串](#3016)
#### [计数](#3016)
#### [排序](#3016)
### [3017_按距离统计房屋对数目 II](#3017)
#### [图](#3017)
#### [前缀和](#3017)
### [3018_可处理的最大删除操作数 I 🔒](#3018)
#### [数组](#3018)
#### [动态规划](#3018)
### [3019_按键变更的次数](#3019)
#### [字符串](#3019)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3010_将数组分成最小总代价的子数组 I
___
#### 数组
___
#### 枚举
___
#### 排序
---
### 3011_判断一个数组是否可以变为有序
___
#### 位运算
___
#### 数组
___
#### 排序
---
### 3012_通过操作使数组长度最小
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 数论
---
### 3013_将数组分成最小总代价的子数组 II
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
___
#### 堆（优先队列）
---
### 3014_输入单词需要的最少按键次数 I
___
#### 贪心
___
#### 数学
___
#### 字符串
---
### 3015_按距离统计房屋对数目 I
___
#### 广度优先搜索
___
#### 图
___
#### 前缀和
---
### 3016_输入单词需要的最少按键次数 II
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
---
### 3017_按距离统计房屋对数目 II
___
#### 图
___
#### 前缀和
---
### 3018_可处理的最大删除操作数 I 🔒
___
#### 数组
___
#### 动态规划
---
### 3019_按键变更的次数
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 滑动窗口 | 计数 |
| 贪心 |  |  |

# [3010. 将数组分成最小总代价的子数组 I](https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i){#3010}

{{< tabs "3010" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        a, b, c = nums[0], inf, inf
        for x in nums[1:]:
            if x < b:
                c, b = b, x
            elif x < c:
                c = x
        return a + b + c
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCost(int[] nums) {
        int a = nums[0], b = 100, c = 100;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] < b) {
                c = b;
                b = nums[i];
            } else if (nums[i] < c) {
                c = nums[i];
            }
        }
        return a + b + c;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a = nums[0], b = 100, c = 100;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < b) {
                c = b;
                b = nums[i];
            } else if (nums[i] < c) {
                c = nums[i];
            }
        }
        return a + b + c;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(nums []int) int {
	a, b, c := nums[0], 100, 100
	for _, x := range nums[1:] {
		if x < b {
			b, c = x, b
		} else if x < c {
			c = x
		}
	}
	return a + b + c
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(nums: number[]): number {
    let [a, b, c] = [nums[0], 100, 100];
    for (const x of nums.slice(1)) {
        if (x < b) {
            [b, c] = [x, b];
        } else if (x < c) {
            c = x;
        }
    }
    return a + b + c;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一个数组的 <strong>代价</strong>&nbsp;是它的 <strong>第一个</strong>&nbsp;元素。比方说，<code>[1,2,3]</code>&nbsp;的代价是&nbsp;<code>1</code>&nbsp;，<code>[3,4,1]</code>&nbsp;的代价是&nbsp;<code>3</code>&nbsp;。</p>

<p>你需要将&nbsp;<code>nums</code>&nbsp;分成&nbsp;<code>3</code>&nbsp;个&nbsp;<strong>连续且没有交集</strong>&nbsp;的子数组。</p>

<p>请你返回这些<span data-keyword="subarray">子数组</span>的 <strong>最小</strong>&nbsp;代价&nbsp;<b>总和</b>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,12]
<b>输出：</b>6
<b>解释：</b>最佳分割成 3 个子数组的方案是：[1] ，[2] 和 [3,12] ，总代价为 1 + 2 + 3 = 6 。
其他得到 3 个子数组的方案是：
- [1] ，[2,3] 和 [12] ，总代价是 1 + 2 + 12 = 15 。
- [1,2] ，[3] 和 [12] ，总代价是 1 + 3 + 12 = 16 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,4,3]
<b>输出：</b>12
<b>解释：</b>最佳分割成 3 个子数组的方案是：[5] ，[4] 和 [3] ，总代价为 5 + 4 + 3 = 12 。
12 是所有分割方案里的最小总代价。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [10,3,1,1]
<b>输出：</b>12
<b>解释：</b>最佳分割成 3 个子数组的方案是：[10,3] ，[1] 和 [1] ，总代价为 10 + 1 + 1 = 12 。
12 是所有分割方案里的最小总代价。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历找最小值和次小值

我们记数组 $nums$ 的第一个元素为 $a$，其余元素中最小的元素为 $b$，次小的元素为 $c$，那么答案就是 $a+b+c$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        a, b, c = nums[0], inf, inf
        for x in nums[1:]:
            if x < b:
                c, b = b, x
            elif x < c:
                c = x
        return a + b + c
```

#### Java

```java
class Solution {
    public int minimumCost(int[] nums) {
        int a = nums[0], b = 100, c = 100;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] < b) {
                c = b;
                b = nums[i];
            } else if (nums[i] < c) {
                c = nums[i];
            }
        }
        return a + b + c;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a = nums[0], b = 100, c = 100;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < b) {
                c = b;
                b = nums[i];
            } else if (nums[i] < c) {
                c = nums[i];
            }
        }
        return a + b + c;
    }
};
```

#### Go

```go
func minimumCost(nums []int) int {
	a, b, c := nums[0], 100, 100
	for _, x := range nums[1:] {
		if x < b {
			b, c = x, b
		} else if x < c {
			c = x
		}
	}
	return a + b + c
}
```

#### TypeScript

```ts
function minimumCost(nums: number[]): number {
    let [a, b, c] = [nums[0], 100, 100];
    for (const x of nums.slice(1)) {
        if (x < b) {
            [b, c] = [x, b];
        } else if (x < c) {
            c = x;
        }
    }
    return a + b + c;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3011. 判断一个数组是否可以变为有序](https://leetcode.cn/problems/find-if-array-can-be-sorted){#3011}

{{< tabs "3011" >}}

{{% tab "python" %}}
```python
class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        pre_mx = 0
        i, n = 0, len(nums)
        while i < n:
            cnt = nums[i].bit_count()
            j = i + 1
            mi = mx = nums[i]
            while j < n and nums[j].bit_count() == cnt:
                mi = min(mi, nums[j])
                mx = max(mx, nums[j])
                j += 1
            if pre_mx > mi:
                return False
            pre_mx = mx
            i = j
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canSortArray(int[] nums) {
        int preMx = 0;
        int i = 0, n = nums.length;
        while (i < n) {
            int cnt = Integer.bitCount(nums[i]);
            int j = i + 1;
            int mi = nums[i], mx = nums[i];
            while (j < n && Integer.bitCount(nums[j]) == cnt) {
                mi = Math.min(mi, nums[j]);
                mx = Math.max(mx, nums[j]);
                j++;
            }
            if (preMx > mi) {
                return false;
            }
            preMx = mx;
            i = j;
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
    bool canSortArray(vector<int>& nums) {
        int preMx = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            int cnt = __builtin_popcount(nums[i]);
            int j = i + 1;
            int mi = nums[i], mx = nums[i];
            while (j < n && __builtin_popcount(nums[j]) == cnt) {
                mi = min(mi, nums[j]);
                mx = max(mx, nums[j]);
                j++;
            }
            if (preMx > mi) {
                return false;
            }
            preMx = mx;
            i = j;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canSortArray(nums []int) bool {
	preMx := 0
	i, n := 0, len(nums)
	for i < n {
		cnt := bits.OnesCount(uint(nums[i]))
		j := i + 1
		mi, mx := nums[i], nums[i]
		for j < n && bits.OnesCount(uint(nums[j])) == cnt {
			mi = min(mi, nums[j])
			mx = max(mx, nums[j])
			j++
		}
		if preMx > mi {
			return false
		}
		preMx = mx
		i = j
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canSortArray(nums: number[]): boolean {
    let preMx = 0;
    const n = nums.length;
    for (let i = 0; i < n; ) {
        const cnt = bitCount(nums[i]);
        let j = i + 1;
        let [mi, mx] = [nums[i], nums[i]];
        while (j < n && bitCount(nums[j]) === cnt) {
            mi = Math.min(mi, nums[j]);
            mx = Math.max(mx, nums[j]);
            j++;
        }
        if (preMx > mi) {
            return false;
        }
        preMx = mx;
        i = j;
    }
    return true;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始且全是 <strong>正</strong>&nbsp;整数的数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一次 <b>操作</b>&nbsp;中，如果两个 <strong>相邻</strong>&nbsp;元素在二进制下 <span data-keyword="set-bit">设置位</span> 的数目 <strong>相同</strong>&nbsp;，那么你可以将这两个元素交换。你可以执行这个操作 <strong>任意次</strong>&nbsp;（<strong>也可以 0 次</strong>）。</p>

<p>如果你可以使数组变为非降序，请你返回&nbsp;<code>true</code> ，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [8,4,2,30,15]
<b>输出：</b>true
<b>解释：</b>我们先观察每个元素的二进制表示。 2 ，4 和 8 分别都只有一个数位为 1 ，分别为 "10" ，"100" 和 "1000" 。15 和 30 分别有 4 个数位为 1 ："1111" 和 "11110" 。
我们可以通过 4 个操作使数组非降序：
- 交换 nums[0] 和 nums[1] 。8 和 4 分别只有 1 个数位为 1 。数组变为 [4,8,2,30,15] 。
- 交换 nums[1] 和 nums[2] 。8 和 2 分别只有 1 个数位为 1 。数组变为 [4,2,8,30,15] 。
- 交换 nums[0] 和 nums[1] 。4 和 2 分别只有 1 个数位为 1 。数组变为 [2,4,8,30,15] 。
- 交换 nums[3] 和 nums[4] 。30 和 15 分别有 4 个数位为 1 ，数组变为 [2,4,8,15,30] 。
数组变成有序的，所以我们返回 true 。
注意我们还可以通过其他的操作序列使数组变得有序。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>true
<b>解释：</b>数组已经是非降序的，所以我们返回 true 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,16,8,4,2]
<b>输出：</b>false
<b>解释：</b>无法通过操作使数组变为非降序。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以使用双指针，将数组 $\textit{nums}$ 分成若干个子数组，每个子数组中的元素的二进制表示中 $1$ 的个数相同。对于每个子数组，我们只需要关注它的最大值和最小值，如果最小值比上一个子数组的最大值小，那么就无法通过交换使得数组有序。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        pre_mx = 0
        i, n = 0, len(nums)
        while i < n:
            cnt = nums[i].bit_count()
            j = i + 1
            mi = mx = nums[i]
            while j < n and nums[j].bit_count() == cnt:
                mi = min(mi, nums[j])
                mx = max(mx, nums[j])
                j += 1
            if pre_mx > mi:
                return False
            pre_mx = mx
            i = j
        return True
```

#### Java

```java
class Solution {
    public boolean canSortArray(int[] nums) {
        int preMx = 0;
        int i = 0, n = nums.length;
        while (i < n) {
            int cnt = Integer.bitCount(nums[i]);
            int j = i + 1;
            int mi = nums[i], mx = nums[i];
            while (j < n && Integer.bitCount(nums[j]) == cnt) {
                mi = Math.min(mi, nums[j]);
                mx = Math.max(mx, nums[j]);
                j++;
            }
            if (preMx > mi) {
                return false;
            }
            preMx = mx;
            i = j;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int preMx = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            int cnt = __builtin_popcount(nums[i]);
            int j = i + 1;
            int mi = nums[i], mx = nums[i];
            while (j < n && __builtin_popcount(nums[j]) == cnt) {
                mi = min(mi, nums[j]);
                mx = max(mx, nums[j]);
                j++;
            }
            if (preMx > mi) {
                return false;
            }
            preMx = mx;
            i = j;
        }
        return true;
    }
};
```

#### Go

```go
func canSortArray(nums []int) bool {
	preMx := 0
	i, n := 0, len(nums)
	for i < n {
		cnt := bits.OnesCount(uint(nums[i]))
		j := i + 1
		mi, mx := nums[i], nums[i]
		for j < n && bits.OnesCount(uint(nums[j])) == cnt {
			mi = min(mi, nums[j])
			mx = max(mx, nums[j])
			j++
		}
		if preMx > mi {
			return false
		}
		preMx = mx
		i = j
	}
	return true
}
```

#### TypeScript

```ts
function canSortArray(nums: number[]): boolean {
    let preMx = 0;
    const n = nums.length;
    for (let i = 0; i < n; ) {
        const cnt = bitCount(nums[i]);
        let j = i + 1;
        let [mi, mx] = [nums[i], nums[i]];
        while (j < n && bitCount(nums[j]) === cnt) {
            mi = Math.min(mi, nums[j]);
            mx = Math.max(mx, nums[j]);
            j++;
        }
        if (preMx > mi) {
            return false;
        }
        preMx = mx;
        i = j;
    }
    return true;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3012. 通过操作使数组长度最小](https://leetcode.cn/problems/minimize-length-of-array-using-operations){#3012}

{{< tabs "3012" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        mi = min(nums)
        if any(x % mi for x in nums):
            return 1
        return (nums.count(mi) + 1) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumArrayLength(int[] nums) {
        int mi = Arrays.stream(nums).min().getAsInt();
        int cnt = 0;
        for (int x : nums) {
            if (x % mi != 0) {
                return 1;
            }
            if (x == mi) {
                ++cnt;
            }
        }
        return (cnt + 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mi = *min_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int x : nums) {
            if (x % mi) {
                return 1;
            }
            cnt += x == mi;
        }
        return (cnt + 1) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumArrayLength(nums []int) int {
	mi := slices.Min(nums)
	cnt := 0
	for _, x := range nums {
		if x%mi != 0 {
			return 1
		}
		if x == mi {
			cnt++
		}
	}
	return (cnt + 1) / 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumArrayLength(nums: number[]): number {
    const mi = Math.min(...nums);
    let cnt = 0;
    for (const x of nums) {
        if (x % mi) {
            return 1;
        }
        if (x === mi) {
            ++cnt;
        }
    }
    return (cnt + 1) >> 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它只包含 <strong>正</strong>&nbsp;整数。</p>

<p>你的任务是通过进行以下操作&nbsp;<strong>任意次</strong>&nbsp;（可以是 0 次）&nbsp;<strong>最小化</strong>&nbsp;<code>nums</code>&nbsp;的长度：</p>

<ul>
	<li>在 <code>nums</code>&nbsp;中选择 <strong>两个不同</strong>&nbsp;的下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;，满足&nbsp;<code>nums[i] &gt; 0</code>&nbsp;且&nbsp;<code>nums[j] &gt; 0</code>&nbsp;。</li>
	<li>将结果&nbsp;<code>nums[i] % nums[j]</code>&nbsp;插入&nbsp;<code>nums</code>&nbsp;的结尾。</li>
	<li>将 <code>nums</code>&nbsp;中下标为&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;的元素删除。</li>
</ul>

<p>请你返回一个整数，它表示进行任意次操作以后<em>&nbsp;</em><code>nums</code>&nbsp;的 <strong>最小长度</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,3,1]
<b>输出：</b>1
<b>解释：</b>使数组长度最小的一种方法是：
操作 1 ：选择下标 2 和 1 ，插入 nums[2] % nums[1] 到数组末尾，得到 [1,4,3,1,3] ，然后删除下标为 2 和 1 的元素。
nums 变为 [1,1,3] 。
操作 2 ：选择下标 1 和 2 ，插入 nums[1] % nums[2] 到数组末尾，得到 [1,1,3,1] ，然后删除下标为 1 和 2 的元素。
nums 变为 [1,1] 。
操作 3 ：选择下标 1 和 0 ，插入 nums[1] % nums[0] 到数组末尾，得到 [1,1,0] ，然后删除下标为 1 和 0 的元素。
nums 变为 [0] 。
nums 的长度无法进一步减小，所以答案为 1 。
1 是可以得到的最小长度。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,5,5,10,5]
<b>输出：</b>2
<b>解释：</b>使数组长度最小的一种方法是：
操作 1 ：选择下标 0 和 3 ，插入 nums[0] % nums[3] 到数组末尾，得到 [5,5,5,10,5,5] ，然后删除下标为 0 和 3 的元素。
nums 变为 [5,5,5,5] 。
操作 2 ：选择下标 2 和 3 ，插入 nums[2] % nums[3] 到数组末尾，得到 [5,5,5,5,0] ，然后删除下标为 2 和 3 的元素。
nums 变为 [5,5,0] 。
操作 3 ：选择下标 0 和 1 ，插入 nums[0] % nums[1] 到数组末尾，得到 [5,5,0,0] ，然后删除下标为 0 和 1 的元素。
nums 变为 [0,0] 。
nums 的长度无法进一步减小，所以答案为 2 。
2 是可以得到的最小长度。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,4]
<b>输出：</b>1
<b>解释：</b>使数组长度最小的一种方法是：
操作 1 ：选择下标 1 和 2 ，插入 nums[1] % nums[2] 到数组末尾，得到 [2,3,4,3] ，然后删除下标为 1 和 2 的元素。
nums 变为 [2,3] 。
操作 2 ：选择下标 1 和 0 ，插入 nums[1] % nums[0] 到数组末尾，得到 [2,3,1] ，然后删除下标为 1 和 0 的元素。
nums 变为 [1] 。
nums 的长度无法进一步减小，所以答案为 1 。
1 是可以得到的最小长度。</pre>

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

### 方法一：分情况讨论

我们不妨记数组 $nums$ 的最小的元素为 $mi$。

如果 $mi$ 只出现一次，那么我们将 $mi$ 与数组 $nums$ 的其他元素进行操作，可以将其他元素全部消去，最终剩下 $mi$ 一个元素，答案为 $1$。

如果 $mi$ 出现多次，我们判断数组 $nums$ 中的元素是否都是 $mi$ 的倍数。如果不是，即存在至少一个元素 $x$，使得 $0 \lt x \bmod mi \lt mi$，说明我们可以通过操作，构造出一个小于 $mi$ 的元素，那么这个小于 $mi$ 的元素与其他元素进行操作，可以将其他元素全部消去，最终剩下这个小于 $mi$ 的元素，答案为 $1$；如果都是 $mi$ 的倍数，我们可以先借助 $mi$，将所有大于 $mi$ 的元素消去，最终剩下的元素都是 $mi$，个数为 $cnt$，两两配对，每两个元素进行一次操作，最终剩下 $\lceil cnt / 2 \rceil$ 个元素，答案为 $\lceil cnt / 2 \rceil$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        mi = min(nums)
        if any(x % mi for x in nums):
            return 1
        return (nums.count(mi) + 1) // 2
```

#### Java

```java
class Solution {
    public int minimumArrayLength(int[] nums) {
        int mi = Arrays.stream(nums).min().getAsInt();
        int cnt = 0;
        for (int x : nums) {
            if (x % mi != 0) {
                return 1;
            }
            if (x == mi) {
                ++cnt;
            }
        }
        return (cnt + 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mi = *min_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int x : nums) {
            if (x % mi) {
                return 1;
            }
            cnt += x == mi;
        }
        return (cnt + 1) / 2;
    }
};
```

#### Go

```go
func minimumArrayLength(nums []int) int {
	mi := slices.Min(nums)
	cnt := 0
	for _, x := range nums {
		if x%mi != 0 {
			return 1
		}
		if x == mi {
			cnt++
		}
	}
	return (cnt + 1) / 2
}
```

#### TypeScript

```ts
function minimumArrayLength(nums: number[]): number {
    const mi = Math.min(...nums);
    let cnt = 0;
    for (const x of nums) {
        if (x % mi) {
            return 1;
        }
        if (x === mi) {
            ++cnt;
        }
    }
    return (cnt + 1) >> 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3013. 将数组分成最小总代价的子数组 II](https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii){#3013}

{{< tabs "3013" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        def l2r():
            nonlocal s
            x = l.pop()
            s -= x
            r.add(x)

        def r2l():
            nonlocal s
            x = r.pop(0)
            l.add(x)
            s += x

        k -= 1
        s = sum(nums[: dist + 2])
        l = SortedList(nums[1 : dist + 2])
        r = SortedList()
        while len(l) > k:
            l2r()
        ans = s
        for i in range(dist + 2, len(nums)):
            x = nums[i - dist - 1]
            if x in l:
                l.remove(x)
                s -= x
            else:
                r.remove(x)
            y = nums[i]
            if y < l[-1]:
                l.add(y)
                s += y
            else:
                r.add(y)
            while len(l) < k:
                r2l()
            while len(l) > k:
                l2r()
            ans = min(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final TreeMap<Integer, Integer> l = new TreeMap<>();
    private final TreeMap<Integer, Integer> r = new TreeMap<>();
    private long s;
    private int size;

    public long minimumCost(int[] nums, int k, int dist) {
        --k;
        s = nums[0];
        for (int i = 1; i < dist + 2; ++i) {
            s += nums[i];
            l.merge(nums[i], 1, Integer::sum);
        }
        size = dist + 1;
        while (size > k) {
            l2r();
        }
        long ans = s;
        for (int i = dist + 2; i < nums.length; ++i) {
            int x = nums[i - dist - 1];
            if (l.containsKey(x)) {
                if (l.merge(x, -1, Integer::sum) == 0) {
                    l.remove(x);
                }
                s -= x;
                --size;
            } else if (r.merge(x, -1, Integer::sum) == 0) {
                r.remove(x);
            }
            int y = nums[i];
            if (y < l.lastKey()) {
                l.merge(y, 1, Integer::sum);
                ++size;
                s += y;
            } else {
                r.merge(y, 1, Integer::sum);
            }
            while (size < k) {
                r2l();
            }
            while (size > k) {
                l2r();
            }
            ans = Math.min(ans, s);
        }
        return ans;
    }

    private void l2r() {
        int x = l.lastKey();
        s -= x;
        if (l.merge(x, -1, Integer::sum) == 0) {
            l.remove(x);
        }
        --size;
        r.merge(x, 1, Integer::sum);
    }

    private void r2l() {
        int x = r.firstKey();
        if (r.merge(x, -1, Integer::sum) == 0) {
            r.remove(x);
        }
        l.merge(x, 1, Integer::sum);
        s += x;
        ++size;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        --k;
        multiset<int> l(nums.begin() + 1, nums.begin() + dist + 2), r;
        long long s = accumulate(nums.begin(), nums.begin() + dist + 2, 0LL);
        while (l.size() > k) {
            int x = *l.rbegin();
            l.erase(l.find(x));
            s -= x;
            r.insert(x);
        }
        long long ans = s;
        for (int i = dist + 2; i < nums.size(); ++i) {
            int x = nums[i - dist - 1];
            auto it = l.find(x);
            if (it != l.end()) {
                l.erase(it);
                s -= x;
            } else {
                r.erase(r.find(x));
            }
            int y = nums[i];
            if (y < *l.rbegin()) {
                l.insert(y);
                s += y;
            } else {
                r.insert(y);
            }
            while (l.size() == k - 1) {
                int x = *r.begin();
                r.erase(r.find(x));
                l.insert(x);
                s += x;
            }
            while (l.size() == k + 1) {
                int x = *l.rbegin();
                l.erase(l.find(x));
                s -= x;
                r.insert(x);
            }
            ans = min(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(nums []int, k int, dist int) int64 {
	k--
	l := redblacktree.New[int, int]()
	r := redblacktree.New[int, int]()
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}

	s := nums[0]
	for _, x := range nums[1 : dist+2] {
		s += x
		merge(l, x, 1)
	}
	size := dist + 1

	l2r := func() {
		x := l.Right().Key
		merge(l, x, -1)
		s -= x
		size--
		merge(r, x, 1)
	}
	r2l := func() {
		x := r.Left().Key
		merge(r, x, -1)
		merge(l, x, 1)
		s += x
		size++
	}

	for size > k {
		l2r()
	}

	ans := s
	for i := dist + 2; i < len(nums); i++ {
		x := nums[i-dist-1]
		if _, ok := l.Get(x); ok {
			merge(l, x, -1)
			s -= x
			size--
		} else {
			merge(r, x, -1)
		}
		y := nums[i]
		if y < l.Right().Key {
			merge(l, y, 1)
			s += y
			size++
		} else {
			merge(r, y, 1)
		}
		for size < k {
			r2l()
		}
		for size > k {
			l2r()
		}
		ans = min(ans, s)

	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(nums: number[], k: number, dist: number): number {
    --k;
    const l = new TreapMultiSet<number>((a, b) => a - b);
    const r = new TreapMultiSet<number>((a, b) => a - b);
    let s = nums[0];
    for (let i = 1; i < dist + 2; ++i) {
        s += nums[i];
        l.add(nums[i]);
    }
    const l2r = () => {
        const x = l.pop()!;
        s -= x;
        r.add(x);
    };
    const r2l = () => {
        const x = r.shift()!;
        l.add(x);
        s += x;
    };
    while (l.size > k) {
        l2r();
    }
    let ans = s;
    for (let i = dist + 2; i < nums.length; ++i) {
        const x = nums[i - dist - 1];
        if (l.has(x)) {
            l.delete(x);
            s -= x;
        } else {
            r.delete(x);
        }
        const y = nums[i];
        if (y < l.last()!) {
            l.add(y);
            s += y;
        } else {
            r.add(y);
        }
        while (l.size < k) {
            r2l();
        }
        while (l.size > k) {
            l2r();
        }
        ans = Math.min(ans, s);
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和两个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code> 和&nbsp;<code>dist</code>&nbsp;。</p>

<p>一个数组的 <strong>代价</strong>&nbsp;是数组中的 <strong>第一个</strong>&nbsp;元素。比方说，<code>[1,2,3]</code>&nbsp;的代价为&nbsp;<code>1</code>&nbsp;，<code>[3,4,1]</code>&nbsp;的代价为&nbsp;<code>3</code>&nbsp;。</p>

<p>你需要将 <code>nums</code>&nbsp;分割成 <code>k</code>&nbsp;个 <strong>连续且互不相交</strong>&nbsp;的<span data-keyword="subarray">子数组</span>，满足 <strong>第二</strong>&nbsp;个子数组与第 <code>k</code>&nbsp;个子数组中第一个元素的下标距离 <strong>不超过</strong>&nbsp;<code>dist</code>&nbsp;。换句话说，如果你将&nbsp;<code>nums</code>&nbsp;分割成子数组&nbsp;<code>nums[0..(i<sub>1</sub> - 1)], nums[i<sub>1</sub>..(i<sub>2</sub> - 1)], ..., nums[i<sub>k-1</sub>..(n - 1)]</code>&nbsp;，那么它需要满足&nbsp;<code>i<sub>k-1</sub> - i<sub>1</sub> &lt;= dist</code>&nbsp;。</p>

<p>请你返回这些子数组的 <strong>最小</strong>&nbsp;总代价。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,2,6,4,2], k = 3, dist = 3
<b>输出：</b>5
<b>解释：</b>将数组分割成 3 个子数组的最优方案是：[1,3] ，[2,6,4] 和 [2] 。这是一个合法分割，因为 i<sub>k-1</sub> - i<sub>1</sub> 等于 5 - 2 = 3 ，等于 dist 。总代价为 nums[0] + nums[2] + nums[5] ，也就是 1 + 2 + 2 = 5 。
5 是分割成 3 个子数组的最小总代价。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,1,2,2,2,1], k = 4, dist = 3
<b>输出：</b>15
<b>解释：</b>将数组分割成 4 个子数组的最优方案是：[10] ，[1] ，[2] 和 [2,2,1] 。这是一个合法分割，因为 i<sub>k-1</sub> - i<sub>1</sub> 等于 3 - 1 = 2 ，小于 dist 。总代价为 nums[0] + nums[1] + nums[2] + nums[3] ，也就是 10 + 1 + 2 + 2 = 15 。
分割 [10] ，[1] ，[2,2,2] 和 [1] 不是一个合法分割，因为 i<sub>k-1</sub> 和 i<sub>1</sub> 的差为 5 - 1 = 4 ，大于 dist 。
15 是分割成 4 个子数组的最小总代价。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [10,8,18,9], k = 3, dist = 1
<b>输出：</b>36
<b>解释：</b>将数组分割成 4 个子数组的最优方案是：[10] ，[8] 和 [18,9] 。这是一个合法分割，因为 i<sub>k-1</sub> - i<sub>1</sub> 等于 2 - 1 = 1 ，等于 dist 。总代价为 nums[0] + nums[1] + nums[2] ，也就是 10 + 8 + 18 = 36 。
分割 [10] ，[8,18] 和 [9] 不是一个合法分割，因为 i<sub>k-1</sub> 和 i<sub>1</sub> 的差为 3 - 1 = 2 ，大于 dist 。
36 是分割成 3 个子数组的最小总代价。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>3 &lt;= k &lt;= n</code></li>
	<li><code>k - 2 &lt;= dist &lt;= n - 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合

题目需要我们将数组 $\textit{nums}$ 分割成 $k$ 个连续且不相交的子数组，并且第二个子数组的第一个元素与第 $k$ 个子数组的第一个元素的下标距离不超过 $\textit{dist}$，这等价于让我们从 $\textit{nums}$ 下标为 $1$ 的元素开始，找到一个窗口大小为 $\textit{dist}+1$ 的子数组，求其中前 $k-1$ 的最小元素之和。我们将 $k$ 减 $1$，这样我们只需要求出 $k$ 个最小元素之和，再加上 $\textit{nums}[0]$ 即可。

我们可以使用两个有序集合 $\textit{l}$ 和 $\textit{r}$ 分别维护大小为 $\textit{dist} + 1$ 的窗口元素，其中 $\textit{l}$ 维护最小的 $k$ 个元素，而 $\textit{r}$ 维护窗口的剩余元素。我们维护一个变量 $\textit{s}$ 表示 $\textit{nums}[0]$ 与 $l$ 中元素之和。初始时，我们将前 $\textit{dist}+2$ 个元素之和累加到 $\textit{s}$ 中，并将下标为 $[1, \textit{dist} + 1]$ 的所有元素加入到 $\textit{l}$ 中。如果 $\textit{l}$ 的大小大于 $k$，我们循环将 $\textit{l}$ 中的最大元素移动到 $\textit{r}$ 中，直到 $\textit{l}$ 的大小等于 $k$，过程中更新 $\textit{s}$ 的值。

那么此时初始答案 $\textit{ans} = \textit{s}$。

接下来我们从 $\textit{dist}+2$ 开始遍历 $\textit{nums}$，对于每一个元素 $\textit{nums}[i]$，我们需要将 $\textit{nums}[i-\textit{dist}-1]$ 从 $\textit{l}$ 或 $\textit{r}$ 中移除，然后将 $\textit{nums}[i]$ 加入到 $\textit{l}$ 或 $\textit{r}$ 中。如果 $\textit{nums}[i]$ 小于 $\textit{l}$ 中的最大元素，我们将 $\textit{nums}[i]$ 加入到 $\textit{l}$ 中，否则加入到 $\textit{r}$ 中。如果此时 $\textit{l}$ 的大小小于 $k$，我们将 $\textit{r}$ 中的最小元素移动到 $\textit{l}$ 中，直到 $\textit{l}$ 的大小等于 $k$。如果此时 $\textit{l}$ 的大小大于 $k$，我们将 $\textit{l}$ 中的最大元素移动到 $\textit{r}$ 中，直到 $\textit{l}$ 的大小等于 $k$。过程中更新 $\textit{s}$ 的值，并更新 $\textit{ans} = \min(\textit{ans}, \textit{s})$。

最终答案即为 $\textit{ans}$。

时间复杂度 $O(n \times \log \textit{dist})$，空间复杂度 $O(\textit{dist})$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        def l2r():
            nonlocal s
            x = l.pop()
            s -= x
            r.add(x)

        def r2l():
            nonlocal s
            x = r.pop(0)
            l.add(x)
            s += x

        k -= 1
        s = sum(nums[: dist + 2])
        l = SortedList(nums[1 : dist + 2])
        r = SortedList()
        while len(l) > k:
            l2r()
        ans = s
        for i in range(dist + 2, len(nums)):
            x = nums[i - dist - 1]
            if x in l:
                l.remove(x)
                s -= x
            else:
                r.remove(x)
            y = nums[i]
            if y < l[-1]:
                l.add(y)
                s += y
            else:
                r.add(y)
            while len(l) < k:
                r2l()
            while len(l) > k:
                l2r()
            ans = min(ans, s)
        return ans
```

#### Java

```java
class Solution {
    private final TreeMap<Integer, Integer> l = new TreeMap<>();
    private final TreeMap<Integer, Integer> r = new TreeMap<>();
    private long s;
    private int size;

    public long minimumCost(int[] nums, int k, int dist) {
        --k;
        s = nums[0];
        for (int i = 1; i < dist + 2; ++i) {
            s += nums[i];
            l.merge(nums[i], 1, Integer::sum);
        }
        size = dist + 1;
        while (size > k) {
            l2r();
        }
        long ans = s;
        for (int i = dist + 2; i < nums.length; ++i) {
            int x = nums[i - dist - 1];
            if (l.containsKey(x)) {
                if (l.merge(x, -1, Integer::sum) == 0) {
                    l.remove(x);
                }
                s -= x;
                --size;
            } else if (r.merge(x, -1, Integer::sum) == 0) {
                r.remove(x);
            }
            int y = nums[i];
            if (y < l.lastKey()) {
                l.merge(y, 1, Integer::sum);
                ++size;
                s += y;
            } else {
                r.merge(y, 1, Integer::sum);
            }
            while (size < k) {
                r2l();
            }
            while (size > k) {
                l2r();
            }
            ans = Math.min(ans, s);
        }
        return ans;
    }

    private void l2r() {
        int x = l.lastKey();
        s -= x;
        if (l.merge(x, -1, Integer::sum) == 0) {
            l.remove(x);
        }
        --size;
        r.merge(x, 1, Integer::sum);
    }

    private void r2l() {
        int x = r.firstKey();
        if (r.merge(x, -1, Integer::sum) == 0) {
            r.remove(x);
        }
        l.merge(x, 1, Integer::sum);
        s += x;
        ++size;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        --k;
        multiset<int> l(nums.begin() + 1, nums.begin() + dist + 2), r;
        long long s = accumulate(nums.begin(), nums.begin() + dist + 2, 0LL);
        while (l.size() > k) {
            int x = *l.rbegin();
            l.erase(l.find(x));
            s -= x;
            r.insert(x);
        }
        long long ans = s;
        for (int i = dist + 2; i < nums.size(); ++i) {
            int x = nums[i - dist - 1];
            auto it = l.find(x);
            if (it != l.end()) {
                l.erase(it);
                s -= x;
            } else {
                r.erase(r.find(x));
            }
            int y = nums[i];
            if (y < *l.rbegin()) {
                l.insert(y);
                s += y;
            } else {
                r.insert(y);
            }
            while (l.size() == k - 1) {
                int x = *r.begin();
                r.erase(r.find(x));
                l.insert(x);
                s += x;
            }
            while (l.size() == k + 1) {
                int x = *l.rbegin();
                l.erase(l.find(x));
                s -= x;
                r.insert(x);
            }
            ans = min(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumCost(nums []int, k int, dist int) int64 {
	k--
	l := redblacktree.New[int, int]()
	r := redblacktree.New[int, int]()
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}

	s := nums[0]
	for _, x := range nums[1 : dist+2] {
		s += x
		merge(l, x, 1)
	}
	size := dist + 1

	l2r := func() {
		x := l.Right().Key
		merge(l, x, -1)
		s -= x
		size--
		merge(r, x, 1)
	}
	r2l := func() {
		x := r.Left().Key
		merge(r, x, -1)
		merge(l, x, 1)
		s += x
		size++
	}

	for size > k {
		l2r()
	}

	ans := s
	for i := dist + 2; i < len(nums); i++ {
		x := nums[i-dist-1]
		if _, ok := l.Get(x); ok {
			merge(l, x, -1)
			s -= x
			size--
		} else {
			merge(r, x, -1)
		}
		y := nums[i]
		if y < l.Right().Key {
			merge(l, y, 1)
			s += y
			size++
		} else {
			merge(r, y, 1)
		}
		for size < k {
			r2l()
		}
		for size > k {
			l2r()
		}
		ans = min(ans, s)

	}
	return int64(ans)
}
```

#### TypeScript

```ts
function minimumCost(nums: number[], k: number, dist: number): number {
    --k;
    const l = new TreapMultiSet<number>((a, b) => a - b);
    const r = new TreapMultiSet<number>((a, b) => a - b);
    let s = nums[0];
    for (let i = 1; i < dist + 2; ++i) {
        s += nums[i];
        l.add(nums[i]);
    }
    const l2r = () => {
        const x = l.pop()!;
        s -= x;
        r.add(x);
    };
    const r2l = () => {
        const x = r.shift()!;
        l.add(x);
        s += x;
    };
    while (l.size > k) {
        l2r();
    }
    let ans = s;
    for (let i = dist + 2; i < nums.length; ++i) {
        const x = nums[i - dist - 1];
        if (l.has(x)) {
            l.delete(x);
            s -= x;
        } else {
            r.delete(x);
        }
        const y = nums[i];
        if (y < l.last()!) {
            l.add(y);
            s += y;
        } else {
            r.add(y);
        }
        while (l.size < k) {
            r2l();
        }
        while (l.size > k) {
            l2r();
        }
        ans = Math.min(ans, s);
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3014. 输入单词需要的最少按键次数 I](https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-i){#3014}

{{< tabs "3014" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        ans, k = 0, 1
        for _ in range(n // 8):
            ans += k * 8
            k += 1
        ans += k * (n % 8)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumPushes(String word) {
        int n = word.length();
        int ans = 0, k = 1;
        for (int i = 0; i < n / 8; ++i) {
            ans += k * 8;
            ++k;
        }
        ans += k * (n % 8);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0, k = 1;
        for (int i = 0; i < n / 8; ++i) {
            ans += k * 8;
            ++k;
        }
        ans += k * (n % 8);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumPushes(word string) (ans int) {
	n := len(word)
	k := 1
	for i := 0; i < n/8; i++ {
		ans += k * 8
		k++
	}
	ans += k * (n % 8)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumPushes(word: string): number {
    const n = word.length;
    let ans = 0;
    let k = 1;
    for (let i = 0; i < ((n / 8) | 0); ++i) {
        ans += k * 8;
        ++k;
    }
    ans += k * (n % 8);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>word</code>，由 <strong>不同 </strong>小写英文字母组成。</p>

<p>电话键盘上的按键与 <strong>不同 </strong>小写英文字母集合相映射，可以通过按压按键来组成单词。例如，按键 <code>2</code> 对应 <code>["a","b","c"]</code>，我们需要按一次键来输入 <code>"a"</code>，按两次键来输入 <code>"b"</code>，按三次键来输入 <code>"c"</code><em>。</em></p>

<p>现在允许你将编号为 <code>2</code> 到 <code>9</code> 的按键重新映射到 <strong>不同 </strong>字母集合。每个按键可以映射到<strong> 任意数量 </strong>的字母，但每个字母 <strong>必须</strong> <strong>恰好</strong> 映射到 <strong>一个 </strong>按键上。你需要找到输入字符串 <code>word</code> 所需的<strong> 最少 </strong>按键次数。</p>

<p>返回重新映射按键后输入 <code>word</code> 所需的 <strong>最少 </strong>按键次数。</p>

<p>下面给出了一种电话键盘上字母到按键的映射作为示例。注意 <code>1</code>，<code>*</code>，<code>#</code> 和 <code>0</code> <strong>不</strong> 对应任何字母。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3014.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20I/images/keypaddesc.png" style="width: 329px; height: 313px;" />
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3014.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20I/images/keypadv1e1.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "abcde"
<strong>输出：</strong>5
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"a" -&gt; 在按键 2 上按一次
"b" -&gt; 在按键 3 上按一次
"c" -&gt; 在按键 4 上按一次
"d" -&gt; 在按键 5 上按一次
"e" -&gt; 在按键 6 上按一次
总成本为 1 + 1 + 1 + 1 + 1 = 5 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3014.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20I/images/keypadv1e2.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "xycdefghij"
<strong>输出：</strong>12
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"x" -&gt; 在按键 2 上按一次
"y" -&gt; 在按键 2 上按两次
"c" -&gt; 在按键 3 上按一次
"d" -&gt; 在按键 3 上按两次
"e" -&gt; 在按键 4 上按一次
"f" -&gt; 在按键 5 上按一次
"g" -&gt; 在按键 6 上按一次
"h" -&gt; 在按键 7 上按一次
"i" -&gt; 在按键 8 上按一次
"j" -&gt; 在按键 9 上按一次
总成本为 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 26</code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
	<li><code>word</code> 中的所有字母互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们注意到，字符串 $word$ 中的所有字母都是不同的，因此，我们贪心地将字母均匀地分配到 $8$ 个按键上，即可使得按键次数最少。

时间复杂度 $O(n / 8)$，其中 $n$ 是字符串 $word$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        ans, k = 0, 1
        for _ in range(n // 8):
            ans += k * 8
            k += 1
        ans += k * (n % 8)
        return ans
```

#### Java

```java
class Solution {
    public int minimumPushes(String word) {
        int n = word.length();
        int ans = 0, k = 1;
        for (int i = 0; i < n / 8; ++i) {
            ans += k * 8;
            ++k;
        }
        ans += k * (n % 8);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0, k = 1;
        for (int i = 0; i < n / 8; ++i) {
            ans += k * 8;
            ++k;
        }
        ans += k * (n % 8);
        return ans;
    }
};
```

#### Go

```go
func minimumPushes(word string) (ans int) {
	n := len(word)
	k := 1
	for i := 0; i < n/8; i++ {
		ans += k * 8
		k++
	}
	ans += k * (n % 8)
	return
}
```

#### TypeScript

```ts
function minimumPushes(word: string): number {
    const n = word.length;
    let ans = 0;
    let k = 1;
    for (let i = 0; i < ((n / 8) | 0); ++i) {
        ans += k * 8;
        ++k;
    }
    ans += k * (n % 8);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3015. 按距离统计房屋对数目 I](https://leetcode.cn/problems/count-the-number-of-houses-at-a-certain-distance-i){#3015}

{{< tabs "3015" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        x, y = x - 1, y - 1
        ans = [0] * n
        for i in range(n):
            for j in range(i + 1, n):
                a = j - i
                b = abs(i - x) + 1 + abs(j - y)
                c = abs(i - y) + 1 + abs(j - x)
                ans[min(a, b, c) - 1] += 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        int[] ans = new int[n];
        x--;
        y--;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = j - i;
                int b = Math.abs(i - x) + 1 + Math.abs(j - y);
                int c = Math.abs(i - y) + 1 + Math.abs(j - x);
                ans[Math.min(a, Math.min(b, c)) - 1] += 2;
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
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n);
        x--;
        y--;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = j - i;
                int b = abs(x - i) + abs(y - j) + 1;
                int c = abs(y - i) + abs(x - j) + 1;
                ans[min({a, b, c}) - 1] += 2;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOfPairs(n int, x int, y int) []int {
	ans := make([]int, n)
	x, y = x-1, y-1
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := j - i
			b := abs(x-i) + abs(y-j) + 1
			c := abs(x-j) + abs(y-i) + 1
			ans[min(a, min(b, c))-1] += 2
		}
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
function countOfPairs(n: number, x: number, y: number): number[] {
    const ans: number[] = Array(n).fill(0);
    x--;
    y--;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            const a = j - i;
            const b = Math.abs(x - i) + Math.abs(y - j) + 1;
            const c = Math.abs(y - i) + Math.abs(x - j) + 1;
            ans[Math.min(a, b, c) - 1] += 2;
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

<p>给你三个<strong> 正整数 </strong><code>n</code> 、<code>x</code> 和 <code>y</code> 。</p>

<p>在城市中，存在编号从 <code>1</code> 到 <code>n</code> 的房屋，由 <code>n</code> 条街道相连。对所有 <code>1 &lt;= i &lt; n</code> ，都存在一条街道连接编号为 <code>i</code> 的房屋与编号为 <code>i + 1</code> 的房屋。另存在一条街道连接编号为 <code>x</code> 的房屋与编号为 <code>y</code> 的房屋。</p>

<p>对于每个 <code>k</code>（<code>1 &lt;= k &lt;= n</code>），你需要找出所有满足要求的 <strong>房屋对 </strong><code>[house<sub>1</sub>, house<sub>2</sub>]</code> ，即从 <code>house<sub>1</sub></code> 到 <code>house<sub>2</sub></code> 需要经过的<strong> 最少</strong> 街道数为 <code>k</code> 。</p>

<p>返回一个下标从 <strong>1</strong> 开始且长度为 <code>n</code> 的数组 <code>result</code> ，其中 <code>result[k]</code> 表示所有满足要求的房屋对的数量，即从一个房屋到另一个房屋需要经过的<strong> 最少 </strong>街道数为 <code>k</code> 。</p>

<p><strong>注意</strong>，<code>x</code> 与 <code>y</code> 可以 <strong>相等 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3015.Count%20the%20Number%20of%20Houses%20at%20a%20Certain%20Distance%20I/images/example2.png" style="width: 474px; height: 197px;" />
<pre>
<strong>输入：</strong>n = 3, x = 1, y = 3
<strong>输出：</strong>[6,0,0]
<strong>解释：</strong>让我们检视每个房屋对
- 对于房屋对 (1, 2)，可以直接从房屋 1 到房屋 2。
- 对于房屋对 (2, 1)，可以直接从房屋 2 到房屋 1。
- 对于房屋对 (1, 3)，可以直接从房屋 1 到房屋 3。
- 对于房屋对 (3, 1)，可以直接从房屋 3 到房屋 1。
- 对于房屋对 (2, 3)，可以直接从房屋 2 到房屋 3。
- 对于房屋对 (3, 2)，可以直接从房屋 3 到房屋 2。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3015.Count%20the%20Number%20of%20Houses%20at%20a%20Certain%20Distance%20I/images/example3.png" style="width: 668px; height: 174px;" />
<pre>
<strong>输入：</strong>n = 5, x = 2, y = 4
<strong>输出：</strong>[10,8,2,0,0]
<strong>解释：</strong>对于每个距离 k ，满足要求的房屋对如下：
- 对于 k == 1，满足要求的房屋对有 (1, 2), (2, 1), (2, 3), (3, 2), (2, 4), (4, 2), (3, 4), (4, 3), (4, 5), 以及 (5, 4)。
- 对于 k == 2，满足要求的房屋对有 (1, 3), (3, 1), (1, 4), (4, 1), (2, 5), (5, 2), (3, 5), 以及 (5, 3)。
- 对于 k == 3，满足要求的房屋对有 (1, 5)，以及 (5, 1) 。
- 对于 k == 4 和 k == 5，不存在满足要求的房屋对。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3015.Count%20the%20Number%20of%20Houses%20at%20a%20Certain%20Distance%20I/images/example5.png" style="width: 544px; height: 130px;" />
<pre>
<strong>输入：</strong>n = 4, x = 1, y = 1
<strong>输出：</strong>[6,4,2,0]
<strong>解释：</strong>对于每个距离 k ，满足要求的房屋对如下：
- 对于 k == 1，满足要求的房屋对有 (1, 2), (2, 1), (2, 3), (3, 2), (3, 4), 以及 (4, 3)。
- 对于 k == 2，满足要求的房屋对有 (1, 3), (3, 1), (2, 4), 以及 (4, 2)。
- 对于 k == 3，满足要求的房屋对有 (1, 4), 以及 (4, 1)。
- 对于 k == 4，不存在满足要求的房屋对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= x, y &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举每个点对 $(i, j)$，那么从 $i$ 到 $j$ 的最短距离为 $min(|i - j|, |i - x| + 1 + |j - y|, |i - y| + 1 + |j - x|)$，我们将该距离的出现次数加 $2$，因为 $(i, j)$ 和 $(j, i)$ 都是满足要求的点对。

时间复杂度 $O(n^2)$，其中 $n$ 是题目给定的 $n$。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        x, y = x - 1, y - 1
        ans = [0] * n
        for i in range(n):
            for j in range(i + 1, n):
                a = j - i
                b = abs(i - x) + 1 + abs(j - y)
                c = abs(i - y) + 1 + abs(j - x)
                ans[min(a, b, c) - 1] += 2
        return ans
```

#### Java

```java
class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        int[] ans = new int[n];
        x--;
        y--;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = j - i;
                int b = Math.abs(i - x) + 1 + Math.abs(j - y);
                int c = Math.abs(i - y) + 1 + Math.abs(j - x);
                ans[Math.min(a, Math.min(b, c)) - 1] += 2;
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
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n);
        x--;
        y--;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = j - i;
                int b = abs(x - i) + abs(y - j) + 1;
                int c = abs(y - i) + abs(x - j) + 1;
                ans[min({a, b, c}) - 1] += 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countOfPairs(n int, x int, y int) []int {
	ans := make([]int, n)
	x, y = x-1, y-1
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := j - i
			b := abs(x-i) + abs(y-j) + 1
			c := abs(x-j) + abs(y-i) + 1
			ans[min(a, min(b, c))-1] += 2
		}
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
function countOfPairs(n: number, x: number, y: number): number[] {
    const ans: number[] = Array(n).fill(0);
    x--;
    y--;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            const a = j - i;
            const b = Math.abs(x - i) + Math.abs(y - j) + 1;
            const c = Math.abs(y - i) + Math.abs(x - j) + 1;
            ans[Math.min(a, b, c) - 1] += 2;
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

# [3016. 输入单词需要的最少按键次数 II](https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-ii){#3016}

{{< tabs "3016" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = Counter(word)
        ans = 0
        for i, x in enumerate(sorted(cnt.values(), reverse=True)):
            ans += (i // 8 + 1) * x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumPushes(String word) {
        int[] cnt = new int[26];
        for (int i = 0; i < word.length(); ++i) {
            ++cnt[word.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i / 8 + 1) * cnt[26 - i - 1];
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
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char& c : word) {
            ++cnt[c - 'a'];
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i / 8 + 1) * cnt[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumPushes(word string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range word {
		cnt[c-'a']++
	}
	sort.Ints(cnt)
	for i := 0; i < 26; i++ {
		ans += (i/8 + 1) * cnt[26-i-1]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumPushes(word: string): number {
    const pq = new MaxPriorityQueue();
    const cnt = new Map<string, number>();
    let [i, res] = [0, 0];

    for (const x of word) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }

    for (const [x, c] of cnt) {
        pq.enqueue(x, c);
    }

    while (!pq.isEmpty()) {
        const c = pq.dequeue().priority;
        res += c * (((i++ / 8) | 0) + 1);
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function minimumPushes(word) {
    const pq = new MaxPriorityQueue();
    const cnt = new Map();
    let [i, res] = [0, 0];

    for (const x of word) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }

    for (const [x, c] of cnt) {
        pq.enqueue(x, c);
    }

    while (!pq.isEmpty()) {
        const c = pq.dequeue().priority;
        res += c * (((i++ / 8) | 0) + 1);
    }

    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>word</code>，由小写英文字母组成。</p>

<p>电话键盘上的按键与 <strong>不同 </strong>小写英文字母集合相映射，可以通过按压按键来组成单词。例如，按键 <code>2</code> 对应 <code>["a","b","c"]</code>，我们需要按一次键来输入 <code>"a"</code>，按两次键来输入 <code>"b"</code>，按三次键来输入 <code>"c"</code><em>。</em></p>

<p>现在允许你将编号为 <code>2</code> 到 <code>9</code> 的按键重新映射到 <strong>不同 </strong>字母集合。每个按键可以映射到<strong> 任意数量 </strong>的字母，但每个字母 <strong>必须</strong> <strong>恰好</strong> 映射到 <strong>一个 </strong>按键上。你需要找到输入字符串 <code>word</code> 所需的<strong> 最少 </strong>按键次数。</p>

<p>返回重新映射按键后输入 <code>word</code> 所需的 <strong>最少 </strong>按键次数。</p>

<p>下面给出了一种电话键盘上字母到按键的映射作为示例。注意 <code>1</code>，<code>*</code>，<code>#</code> 和 <code>0</code> <strong>不</strong> 对应任何字母。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3016.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20II/images/keypaddesc.png" style="width: 329px; height: 313px;" />
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3016.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20II/images/keypadv1e1.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "abcde"
<strong>输出：</strong>5
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"a" -&gt; 在按键 2 上按一次
"b" -&gt; 在按键 3 上按一次
"c" -&gt; 在按键 4 上按一次
"d" -&gt; 在按键 5 上按一次
"e" -&gt; 在按键 6 上按一次
总成本为 1 + 1 + 1 + 1 + 1 = 5 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3016.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20II/images/keypadv2e2.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "xyzxyzxyzxyz"
<strong>输出：</strong>12
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"x" -&gt; 在按键 2 上按一次
"y" -&gt; 在按键 3 上按一次
"z" -&gt; 在按键 4 上按一次
总成本为 1 * 4 + 1 * 4 + 1 * 4 = 12 。
可以证明不存在其他成本更低的映射方案。
注意按键 9 没有映射到任何字母：不必让每个按键都存在与之映射的字母，但是每个字母都必须映射到按键上。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3016.Minimum%20Number%20of%20Pushes%20to%20Type%20Word%20II/images/keypadv2.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "aabbccddeeffgghhiiiiii"
<strong>输出：</strong>24
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"a" -&gt; 在按键 2 上按一次
"b" -&gt; 在按键 3 上按一次
"c" -&gt; 在按键 4 上按一次
"d" -&gt; 在按键 5 上按一次
"e" -&gt; 在按键 6 上按一次
"f" -&gt; 在按键 7 上按一次
"g" -&gt; 在按键 8 上按一次
"h" -&gt; 在按键 9 上按两次
"i" -&gt; 在按键 9 上按一次
总成本为 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们用一个哈希表或数组 $cnt$ 统计字符串 $word$ 中每个字母出现的次数。接下来，按照字母出现的次数从大到小排序，然后每 $8$ 个字母一组，将每组中的字母分配到 $8$ 个按键上。

时间复杂度 $O(n + |\Sigma| \times \log |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $word$ 的长度，而 $\Sigma$ 是字符串 $word$ 中出现的字母集合。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = Counter(word)
        ans = 0
        for i, x in enumerate(sorted(cnt.values(), reverse=True)):
            ans += (i // 8 + 1) * x
        return ans
```

#### Java

```java
class Solution {
    public int minimumPushes(String word) {
        int[] cnt = new int[26];
        for (int i = 0; i < word.length(); ++i) {
            ++cnt[word.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i / 8 + 1) * cnt[26 - i - 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char& c : word) {
            ++cnt[c - 'a'];
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i / 8 + 1) * cnt[i];
        }
        return ans;
    }
};
```

#### Go

```go
func minimumPushes(word string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range word {
		cnt[c-'a']++
	}
	sort.Ints(cnt)
	for i := 0; i < 26; i++ {
		ans += (i/8 + 1) * cnt[26-i-1]
	}
	return
}
```

#### TypeScript

```ts
function minimumPushes(word: string): number {
    const cnt: number[] = Array(26).fill(0);
    for (const c of word) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    cnt.sort((a, b) => b - a);
    let ans = 0;
    for (let i = 0; i < 26; ++i) {
        ans += (((i / 8) | 0) + 1) * cnt[i];
    }
    return ans;
}
```

#### JavaScript

```js
function minimumPushes(word) {
    const cnt = Array(26).fill(0);
    for (const c of word) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    cnt.sort((a, b) => b - a);
    let ans = 0;
    for (let i = 0; i < 26; ++i) {
        ans += (((i / 8) | 0) + 1) * cnt[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：优先队列（大根堆）

<!-- tabs:start -->

#### TypeScript

```ts
function minimumPushes(word: string): number {
    const pq = new MaxPriorityQueue();
    const cnt = new Map<string, number>();
    let [i, res] = [0, 0];

    for (const x of word) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }

    for (const [x, c] of cnt) {
        pq.enqueue(x, c);
    }

    while (!pq.isEmpty()) {
        const c = pq.dequeue().priority;
        res += c * (((i++ / 8) | 0) + 1);
    }

    return res;
}
```

#### JavaScript

```js
function minimumPushes(word) {
    const pq = new MaxPriorityQueue();
    const cnt = new Map();
    let [i, res] = [0, 0];

    for (const x of word) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }

    for (const [x, c] of cnt) {
        pq.enqueue(x, c);
    }

    while (!pq.isEmpty()) {
        const c = pq.dequeue().priority;
        res += c * (((i++ / 8) | 0) + 1);
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3017. 按距离统计房屋对数目 II](https://leetcode.cn/problems/count-the-number-of-houses-at-a-certain-distance-ii){#3017}

{{< tabs "3017" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        if abs(x - y) <= 1:
            return [2 * x for x in reversed(range(n))]
        cycle_len = abs(x - y) + 1
        n2 = n - cycle_len + 2
        res = [2 * x for x in reversed(range(n2))]
        while len(res) < n:
            res.append(0)
        res2 = [cycle_len * 2] * (cycle_len >> 1)
        if not cycle_len & 1:
            res2[-1] = cycle_len
        res2[0] -= 2
        for i in range(len(res2)):
            res[i] += res2[i]
        if x > y:
            x, y = y, x
        tail1 = x - 1
        tail2 = n - y
        for tail in (tail1, tail2):
            if not tail:
                continue
            i_mx = tail + (cycle_len >> 1)
            val_mx = 4 * min((cycle_len - 3) >> 1, tail)
            i_mx2 = i_mx - (1 - (cycle_len & 1))
            res3 = [val_mx] * i_mx
            res3[0] = 0
            res3[1] = 0
            if not cycle_len & 1:
                res3[-1] = 0
            for i, j in enumerate(range(4, val_mx, 4)):
                res3[i + 2] = j
                res3[i_mx2 - i - 1] = j
            for i in range(1, tail + 1):
                res3[i] += 2
            if not cycle_len & 1:
                mn = cycle_len >> 1
                for i in range(mn, mn + tail):
                    res3[i] += 2
            for i in range(len(res3)):
                res[i] += res3[i]
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] countOfPairs(int n, int x, int y) {
        --x;
        --y;
        if (x > y) {
        int temp = x;
        x = y;
        y = temp;
        }
        long[] diff = new long[n];
        for (int i = 0; i < n; ++i) {
        diff[0] += 1 + 1;
        ++diff[Math.min(Math.abs(i - x), Math.abs(i - y) + 1)];
        ++diff[Math.min(Math.abs(i - y), Math.abs(i - x) + 1)];
        --diff[Math.min(Math.abs(i - 0), Math.abs(i - y) + 1 + Math.abs(x - 0))];
        --diff[Math.min(Math.abs(i - (n - 1)),
                        Math.abs(i - x) + 1 + Math.abs(y - (n - 1)))];
        --diff[Math.max(x - i, 0) + Math.max(i - y, 0) + ((y - x) + 0) / 2];
        --diff[Math.max(x - i, 0) + Math.max(i - y, 0) + ((y - x) + 1) / 2];
        }
        for (int i = 0; i + 1 < n; ++i) {
        diff[i + 1] += diff[i];
        }
        return diff;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
  vector<long long> countOfPairs(int n, int x, int y) {
    --x, --y;
    if (x > y) {
      swap(x, y);
    }
    vector<long long> diff(n);
    for (int i = 0; i < n; ++i) {
      diff[0] += 1 + 1;
      ++diff[min(abs(i - x), abs(i - y) + 1)];
      ++diff[min(abs(i - y), abs(i - x) + 1)];
      --diff[min(abs(i - 0), abs(i - y) + 1 + abs(x - 0))];
      --diff[min(abs(i - (n - 1)), abs(i - x) + 1 + abs(y - (n - 1)))];
      --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 0) / 2];
      --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 1) / 2];
    }
    for (int i = 0; i + 1 < n; ++i) {
      diff[i + 1] += diff[i];
    }
    return diff;
  }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOfPairs(n int, x int, y int) []int64 {
	if x > y {
		x, y = y, x
	}
	A := make([]int64, n)
	for i := 1; i <= n; i++ {
		A[0] += 2
		A[min(int64(i-1), int64(math.Abs(float64(i-y)))+int64(x))] -= 1
		A[min(int64(n-i), int64(math.Abs(float64(i-x)))+1+int64(n-y))] -= 1
		A[min(int64(math.Abs(float64(i-x))), int64(math.Abs(float64(y-i)))+1)] += 1
		A[min(int64(math.Abs(float64(i-x)))+1, int64(math.Abs(float64(y-i))))] += 1
		r := max(int64(x-i), 0) + max(int64(i-y), 0)
		A[r+int64((y-x+0)/2)] -= 1
		A[r+int64((y-x+1)/2)] -= 1
	}
	for i := 1; i < n; i++ {
		A[i] += A[i-1]
	}

	return A
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你三个<strong> 正整数 </strong><code>n</code> 、<code>x</code> 和 <code>y</code> 。</p>

<p>在城市中，存在编号从 <code>1</code> 到 <code>n</code> 的房屋，由 <code>n</code> 条街道相连。对所有 <code>1 &lt;= i &lt; n</code> ，都存在一条街道连接编号为 <code>i</code> 的房屋与编号为 <code>i + 1</code> 的房屋。另存在一条街道连接编号为 <code>x</code> 的房屋与编号为 <code>y</code> 的房屋。</p>

<p>对于每个 <code>k</code>（<code>1 &lt;= k &lt;= n</code>），你需要找出所有满足要求的 <strong>房屋对 </strong><code>[house<sub>1</sub>, house<sub>2</sub>]</code> ，即从 <code>house<sub>1</sub></code> 到 <code>house<sub>2</sub></code> 需要经过的<strong> 最少</strong> 街道数为 <code>k</code> 。</p>

<p>返回一个下标从 <strong>1</strong> 开始且长度为 <code>n</code> 的数组 <code>result</code> ，其中 <code>result[k]</code> 表示所有满足要求的房屋对的数量，即从一个房屋到另一个房屋需要经过的<strong> 最少 </strong>街道数为 <code>k</code> 。</p>

<p><strong>注意</strong>，<code>x</code> 与 <code>y</code> 可以 <strong>相等 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3017.Count%20the%20Number%20of%20Houses%20at%20a%20Certain%20Distance%20II/images/example2.png" style="width: 474px; height: 197px;" />
<pre>
<strong>输入：</strong>n = 3, x = 1, y = 3
<strong>输出：</strong>[6,0,0]
<strong>解释：</strong>让我们检视每个房屋对
- 对于房屋对 (1, 2)，可以直接从房屋 1 到房屋 2。
- 对于房屋对 (2, 1)，可以直接从房屋 2 到房屋 1。
- 对于房屋对 (1, 3)，可以直接从房屋 1 到房屋 3。
- 对于房屋对 (3, 1)，可以直接从房屋 3 到房屋 1。
- 对于房屋对 (2, 3)，可以直接从房屋 2 到房屋 3。
- 对于房屋对 (3, 2)，可以直接从房屋 3 到房屋 2。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3017.Count%20the%20Number%20of%20Houses%20at%20a%20Certain%20Distance%20II/images/example3.png" style="width: 668px; height: 174px;" />
<pre>
<strong>输入：</strong>n = 5, x = 2, y = 4
<strong>输出：</strong>[10,8,2,0,0]
<strong>解释：</strong>对于每个距离 k ，满足要求的房屋对如下：
- 对于 k == 1，满足要求的房屋对有 (1, 2), (2, 1), (2, 3), (3, 2), (2, 4), (4, 2), (3, 4), (4, 3), (4, 5), 以及 (5, 4)。
- 对于 k == 2，满足要求的房屋对有 (1, 3), (3, 1), (1, 4), (4, 1), (2, 5), (5, 2), (3, 5), 以及 (5, 3)。
- 对于 k == 3，满足要求的房屋对有 (1, 5)，以及 (5, 1) 。
- 对于 k == 4 和 k == 5，不存在满足要求的房屋对。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3017.Count%20the%20Number%20of%20Houses%20at%20a%20Certain%20Distance%20II/images/example5.png" style="width: 544px; height: 130px;" />
<pre>
<strong>输入：</strong>n = 4, x = 1, y = 1
<strong>输出：</strong>[6,4,2,0]
<strong>解释：</strong>对于每个距离 k ，满足要求的房屋对如下：
- 对于 k == 1，满足要求的房屋对有 (1, 2), (2, 1), (2, 3), (3, 2), (3, 4), 以及 (4, 3)。
- 对于 k == 2，满足要求的房屋对有 (1, 3), (3, 1), (2, 4), 以及 (4, 2)。
- 对于 k == 3，满足要求的房屋对有 (1, 4), 以及 (4, 1)。
- 对于 k == 4，不存在满足要求的房屋对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, y &lt;= n</code></li>
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

#### Python3

```python
class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        if abs(x - y) <= 1:
            return [2 * x for x in reversed(range(n))]
        cycle_len = abs(x - y) + 1
        n2 = n - cycle_len + 2
        res = [2 * x for x in reversed(range(n2))]
        while len(res) < n:
            res.append(0)
        res2 = [cycle_len * 2] * (cycle_len >> 1)
        if not cycle_len & 1:
            res2[-1] = cycle_len
        res2[0] -= 2
        for i in range(len(res2)):
            res[i] += res2[i]
        if x > y:
            x, y = y, x
        tail1 = x - 1
        tail2 = n - y
        for tail in (tail1, tail2):
            if not tail:
                continue
            i_mx = tail + (cycle_len >> 1)
            val_mx = 4 * min((cycle_len - 3) >> 1, tail)
            i_mx2 = i_mx - (1 - (cycle_len & 1))
            res3 = [val_mx] * i_mx
            res3[0] = 0
            res3[1] = 0
            if not cycle_len & 1:
                res3[-1] = 0
            for i, j in enumerate(range(4, val_mx, 4)):
                res3[i + 2] = j
                res3[i_mx2 - i - 1] = j
            for i in range(1, tail + 1):
                res3[i] += 2
            if not cycle_len & 1:
                mn = cycle_len >> 1
                for i in range(mn, mn + tail):
                    res3[i] += 2
            for i in range(len(res3)):
                res[i] += res3[i]
        return res
```

#### Java

```java
class Solution {
    public long[] countOfPairs(int n, int x, int y) {
        --x;
        --y;
        if (x > y) {
        int temp = x;
        x = y;
        y = temp;
        }
        long[] diff = new long[n];
        for (int i = 0; i < n; ++i) {
        diff[0] += 1 + 1;
        ++diff[Math.min(Math.abs(i - x), Math.abs(i - y) + 1)];
        ++diff[Math.min(Math.abs(i - y), Math.abs(i - x) + 1)];
        --diff[Math.min(Math.abs(i - 0), Math.abs(i - y) + 1 + Math.abs(x - 0))];
        --diff[Math.min(Math.abs(i - (n - 1)),
                        Math.abs(i - x) + 1 + Math.abs(y - (n - 1)))];
        --diff[Math.max(x - i, 0) + Math.max(i - y, 0) + ((y - x) + 0) / 2];
        --diff[Math.max(x - i, 0) + Math.max(i - y, 0) + ((y - x) + 1) / 2];
        }
        for (int i = 0; i + 1 < n; ++i) {
        diff[i + 1] += diff[i];
        }
        return diff;
    }
}
```

#### C++

```cpp
class Solution {
public:
  vector<long long> countOfPairs(int n, int x, int y) {
    --x, --y;
    if (x > y) {
      swap(x, y);
    }
    vector<long long> diff(n);
    for (int i = 0; i < n; ++i) {
      diff[0] += 1 + 1;
      ++diff[min(abs(i - x), abs(i - y) + 1)];
      ++diff[min(abs(i - y), abs(i - x) + 1)];
      --diff[min(abs(i - 0), abs(i - y) + 1 + abs(x - 0))];
      --diff[min(abs(i - (n - 1)), abs(i - x) + 1 + abs(y - (n - 1)))];
      --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 0) / 2];
      --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 1) / 2];
    }
    for (int i = 0; i + 1 < n; ++i) {
      diff[i + 1] += diff[i];
    }
    return diff;
  }
};
```

#### Go

```go
func countOfPairs(n int, x int, y int) []int64 {
	if x > y {
		x, y = y, x
	}
	A := make([]int64, n)
	for i := 1; i <= n; i++ {
		A[0] += 2
		A[min(int64(i-1), int64(math.Abs(float64(i-y)))+int64(x))] -= 1
		A[min(int64(n-i), int64(math.Abs(float64(i-x)))+1+int64(n-y))] -= 1
		A[min(int64(math.Abs(float64(i-x))), int64(math.Abs(float64(y-i)))+1)] += 1
		A[min(int64(math.Abs(float64(i-x)))+1, int64(math.Abs(float64(y-i))))] += 1
		r := max(int64(x-i), 0) + max(int64(i-y), 0)
		A[r+int64((y-x+0)/2)] -= 1
		A[r+int64((y-x+1)/2)] -= 1
	}
	for i := 1; i < n; i++ {
		A[i] += A[i-1]
	}

	return A
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3018. 可处理的最大删除操作数 I 🔒](https://leetcode.cn/problems/maximum-number-of-removal-queries-that-can-be-processed-i){#3018}

{{< tabs "3018" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumProcessableQueries(self, nums: List[int], queries: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        m = len(queries)
        for i in range(n):
            for j in range(n - 1, i - 1, -1):
                if i:
                    f[i][j] = max(
                        f[i][j], f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]])
                    )
                if j + 1 < n:
                    f[i][j] = max(
                        f[i][j], f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]])
                    )
                if f[i][j] == m:
                    return m
        return max(f[i][i] + (nums[i] >= queries[f[i][i]]) for i in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumProcessableQueries(int[] nums, int[] queries) {
        int n = nums.length;
        int[][] f = new int[n][n];
        int m = queries.length;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (i > 0) {
                    f[i][j] = Math.max(
                        f[i][j], f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]] ? 1 : 0));
                }
                if (j + 1 < n) {
                    f[i][j] = Math.max(
                        f[i][j], f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]] ? 1 : 0));
                }
                if (f[i][j] == m) {
                    return m;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, f[i][i] + (nums[i] >= queries[f[i][i]] ? 1 : 0));
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
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int m = queries.size();
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]] ? 1 : 0));
                }
                if (j + 1 < n) {
                    f[i][j] = max(f[i][j], f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]] ? 1 : 0));
                }
                if (f[i][j] == m) {
                    return m;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i][i] + (nums[i] >= queries[f[i][i]] ? 1 : 0));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumProcessableQueries(nums []int, queries []int) (ans int) {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	m := len(queries)
	for i := 0; i < n; i++ {
		for j := n - 1; j >= i; j-- {
			if i > 0 {
				t := 0
				if nums[i-1] >= queries[f[i-1][j]] {
					t = 1
				}
				f[i][j] = max(f[i][j], f[i-1][j]+t)
			}
			if j+1 < n {
				t := 0
				if nums[j+1] >= queries[f[i][j+1]] {
					t = 1
				}
				f[i][j] = max(f[i][j], f[i][j+1]+t)
			}
			if f[i][j] == m {
				return m
			}
		}
	}
	for i := 0; i < n; i++ {
		t := 0
		if nums[i] >= queries[f[i][i]] {
			t = 1
		}
		ans = max(ans, f[i][i]+t)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumProcessableQueries(nums: number[], queries: number[]): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    const m = queries.length;
    for (let i = 0; i < n; ++i) {
        for (let j = n - 1; j >= i; --j) {
            if (i > 0) {
                f[i][j] = Math.max(
                    f[i][j],
                    f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]] ? 1 : 0),
                );
            }
            if (j + 1 < n) {
                f[i][j] = Math.max(
                    f[i][j],
                    f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]] ? 1 : 0),
                );
            }
            if (f[i][j] == m) {
                return m;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, f[i][i] + (nums[i] >= queries[f[i][i]] ? 1 : 0));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_processable_queries(nums: Vec<i32>, queries: Vec<i32>) -> i32 {
        let n = nums.len();
        let m = queries.len();
        let mut f = vec![vec![0; n]; n];

        for i in 0..n {
            for j in (i..n).rev() {
                if i > 0 {
                    let idx = f[i - 1][j] as usize;
                    if idx < m {
                        f[i][j] = f[i][j].max(f[i - 1][j] + if nums[i - 1] >= queries[idx] { 1 } else { 0 });
                    }
                }
                if j + 1 < n {
                    let idx = f[i][j + 1] as usize;
                    if idx < m {
                        f[i][j] = f[i][j].max(f[i][j + 1] + if nums[j + 1] >= queries[idx] { 1 } else { 0 });
                    }
                }
                if f[i][j] as usize == m {
                    return m as i32;
                }
            }
        }

        let mut ans = 0;
        for i in 0..n {
            let idx = f[i][i] as usize;
            if idx < m {
                ans = ans.max(f[i][i] + if nums[i] >= queries[idx] { 1 } else { 0 });
            } else {
                ans = ans.max(f[i][i]);
            }
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

<p>给定一个下标&nbsp;<strong>从&nbsp;0 开始</strong>&nbsp;的数组&nbsp;<code>nums</code> 和一个下标&nbsp;<strong>从</strong>&nbsp;<strong>0 开始&nbsp;</strong>的数组&nbsp;<code>queries</code>。</p>

<p>你可以在开始时执行以下操作 <strong>最多一次</strong>：</p>

<ul>
	<li>用&nbsp;<code>nums</code>&nbsp;的 <span data-keyword="subsequence-array">子序列</span> 替换&nbsp;<code>nums</code>。</li>
</ul>

<p>我们以给定的<code>queries</code>顺序处理查询；对于<code>queries[i]</code>，我们执行以下操作：</p>

<ul>
	<li>如果&nbsp;<code>nums</code> 的第一个 <strong>和</strong> 最后一个元素 <strong>小于</strong>&nbsp;<code>queries[i]</code>，则查询处理 <strong>结束</strong>。</li>
	<li>否则，从&nbsp;<code>nums</code>&nbsp;选择第一个 <strong>或</strong> 最后一个元素，要求其<strong>大于或等于</strong> <code>queries[i]</code>，然后将其从&nbsp;<code>nums</code> 中 <strong>删除</strong>。</li>
</ul>

<p>返回通过以最佳方式执行该操作可以处理的&nbsp;<strong>最多&nbsp;</strong>次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5], queries = [1,2,3,4,6]
<strong>输出：</strong>4
<strong>解释：</strong>我们不执行任何操作，并按如下方式处理查询：
1- 我们选择并移除 nums[0]，因为 1 &lt;= 1，那么 nums 就变成 [2,3,4,5]。
2- 我们选择并移除 nums[0]，因为 2 &lt;= 2，那么 nums 就变成 [3,4,5]。
3- 我们选择并移除 nums[0]，因为 3 &lt;= 3，那么 nums 就变成 [4,5]。
4- 我们选择并移除 nums[0]，因为 4 &lt;= 4，那么 nums 就变成 [5]。
5- 我们不能从 nums 中选择任何元素，因为它们不大于或等于 5。
因此，答案为 4。
可以看出，我们不能处理超过 4 个查询。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,2], queries = [2,2,3]
<b>输出：</b>3
<strong>解释：</strong>我们不做任何操作，按如下方式处理查询：
1- 我们选择并移除 nums[0]，因为 2 &lt;= 2，那么 nums 就变成 [3,2]。
2- 我们选择并移除 nums[1]，因为 2 &lt;= 2，那么 nums 就变成 [3]。
3- 我们选择并移除 nums[0]，因为 3 &lt;= 3，那么 nums 就变成 []。
因此，答案为 3。
可以看出，我们不能处理超过 3 个查询。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,3], queries = [4,3,2]
<strong>输出：</strong>2
<strong>解释：</strong>首先，我们用 nums 的子序列 [4,3] 替换 nums。
然后，我们可以按如下方式处理查询：
1- 我们选择并移除 nums[0]，因为 4 &lt;= 4，那么 nums 就变成 [3]。
2- 我们选择并移除 nums[0]，因为 3 &lt;= 3，那么 nums 就变成 []。
3- 我们无法处理更多查询，因为 nums 为空。
因此，答案为 2。
可以看出，我们不能处理超过 2 个查询。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= queries.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], queries[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示区间 $[i, j]$ 的数还没有被删除时，我们能够处理的查询的最大数量。

考虑 $f[i][j]$：

-   如果 $i \gt 0$，此时 $f[i][j]$ 的值可以由 $f[i - 1][j]$ 转移而来。如果 $nums[i - 1] \ge queries[f[i - 1][j]]$，那么我们可以选择删除 $nums[i - 1]$，因此我们有 $f[i][j] = f[i - 1][j] + (nums[i - 1] \ge queries[f[i - 1][j]])$。
-   如果 $j + 1 \lt n$，此时 $f[i][j]$ 的值可以由 $f[i][j + 1]$ 转移而来。如果 $nums[j + 1] \ge queries[f[i][j + 1]]$，那么我们可以选择删除 $nums[j + 1]$，因此我们有 $f[i][j] = f[i][j + 1] + (nums[j + 1] \ge queries[f[i][j + 1]])$。
-   如果 $f[i][j] = m$，那么我们就可以直接返回 $m$。

最后的答案即为 $\max\limits_{0 \le i \lt n} f[i][i] + (nums[i] \ge queries[f[i][i]])$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumProcessableQueries(self, nums: List[int], queries: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        m = len(queries)
        for i in range(n):
            for j in range(n - 1, i - 1, -1):
                if i:
                    f[i][j] = max(
                        f[i][j], f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]])
                    )
                if j + 1 < n:
                    f[i][j] = max(
                        f[i][j], f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]])
                    )
                if f[i][j] == m:
                    return m
        return max(f[i][i] + (nums[i] >= queries[f[i][i]]) for i in range(n))
```

#### Java

```java
class Solution {
    public int maximumProcessableQueries(int[] nums, int[] queries) {
        int n = nums.length;
        int[][] f = new int[n][n];
        int m = queries.length;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (i > 0) {
                    f[i][j] = Math.max(
                        f[i][j], f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]] ? 1 : 0));
                }
                if (j + 1 < n) {
                    f[i][j] = Math.max(
                        f[i][j], f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]] ? 1 : 0));
                }
                if (f[i][j] == m) {
                    return m;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, f[i][i] + (nums[i] >= queries[f[i][i]] ? 1 : 0));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int m = queries.size();
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]] ? 1 : 0));
                }
                if (j + 1 < n) {
                    f[i][j] = max(f[i][j], f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]] ? 1 : 0));
                }
                if (f[i][j] == m) {
                    return m;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i][i] + (nums[i] >= queries[f[i][i]] ? 1 : 0));
        }
        return ans;
    }
};
```

#### Go

```go
func maximumProcessableQueries(nums []int, queries []int) (ans int) {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	m := len(queries)
	for i := 0; i < n; i++ {
		for j := n - 1; j >= i; j-- {
			if i > 0 {
				t := 0
				if nums[i-1] >= queries[f[i-1][j]] {
					t = 1
				}
				f[i][j] = max(f[i][j], f[i-1][j]+t)
			}
			if j+1 < n {
				t := 0
				if nums[j+1] >= queries[f[i][j+1]] {
					t = 1
				}
				f[i][j] = max(f[i][j], f[i][j+1]+t)
			}
			if f[i][j] == m {
				return m
			}
		}
	}
	for i := 0; i < n; i++ {
		t := 0
		if nums[i] >= queries[f[i][i]] {
			t = 1
		}
		ans = max(ans, f[i][i]+t)
	}
	return
}
```

#### TypeScript

```ts
function maximumProcessableQueries(nums: number[], queries: number[]): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    const m = queries.length;
    for (let i = 0; i < n; ++i) {
        for (let j = n - 1; j >= i; --j) {
            if (i > 0) {
                f[i][j] = Math.max(
                    f[i][j],
                    f[i - 1][j] + (nums[i - 1] >= queries[f[i - 1][j]] ? 1 : 0),
                );
            }
            if (j + 1 < n) {
                f[i][j] = Math.max(
                    f[i][j],
                    f[i][j + 1] + (nums[j + 1] >= queries[f[i][j + 1]] ? 1 : 0),
                );
            }
            if (f[i][j] == m) {
                return m;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, f[i][i] + (nums[i] >= queries[f[i][i]] ? 1 : 0));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_processable_queries(nums: Vec<i32>, queries: Vec<i32>) -> i32 {
        let n = nums.len();
        let m = queries.len();
        let mut f = vec![vec![0; n]; n];

        for i in 0..n {
            for j in (i..n).rev() {
                if i > 0 {
                    let idx = f[i - 1][j] as usize;
                    if idx < m {
                        f[i][j] = f[i][j].max(f[i - 1][j] + if nums[i - 1] >= queries[idx] { 1 } else { 0 });
                    }
                }
                if j + 1 < n {
                    let idx = f[i][j + 1] as usize;
                    if idx < m {
                        f[i][j] = f[i][j].max(f[i][j + 1] + if nums[j + 1] >= queries[idx] { 1 } else { 0 });
                    }
                }
                if f[i][j] as usize == m {
                    return m as i32;
                }
            }
        }

        let mut ans = 0;
        for i in 0..n {
            let idx = f[i][i] as usize;
            if idx < m {
                ans = ans.max(f[i][i] + if nums[i] >= queries[idx] { 1 } else { 0 });
            } else {
                ans = ans.max(f[i][i]);
            }
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

# [3019. 按键变更的次数](https://leetcode.cn/problems/number-of-changing-keys){#3019}

{{< tabs "3019" >}}

{{% tab "python" %}}
```python
class Solution:
    def countKeyChanges(self, s: str) -> int:
        return sum(a != b for a, b in pairwise(s.lower()))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countKeyChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(i - 1))) {
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
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countKeyChanges(s string) (ans int) {
	s = strings.ToLower(s)
	for i, c := range s[1:] {
		if byte(c) != s[i] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countKeyChanges(s: string): number {
    s = s.toLowerCase();
    let ans = 0;
    for (let i = 1; i < s.length; ++i) {
        if (s[i] !== s[i - 1]) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_key_changes(s: String) -> i32 {
        let s = s.to_lowercase();
        let bytes = s.as_bytes();
        let mut ans = 0;
        for i in 1..bytes.len() {
            if bytes[i] != bytes[i - 1] {
                ans += 1;
            }
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

<p>给你一个下标从<strong> 0</strong> 开始的字符串 <code>s</code> ，该字符串由用户输入。按键变更的定义是：使用与上次使用的按键不同的键。例如 <code>s = "ab"</code> 表示按键变更一次，而 <code>s = "bBBb"</code> 不存在按键变更。</p>

<p>返回用户输入过程中按键变更的次数。</p>

<p><strong>注意：</strong><code>shift</code> 或 <code>caps lock</code> 等修饰键不计入按键变更，也就是说，如果用户先输入字母 <code>'a'</code> 然后输入字母 <code>'A'</code> ，不算作按键变更。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aAbBcC"
<strong>输出：</strong>2
<strong>解释：</strong> 
从 s[0] = 'a' 到 s[1] = 'A'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[1] = 'A' 到 s[2] = 'b'，按键变更。
从 s[2] = 'b' 到 s[3] = 'B'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[3] = 'B' 到 s[4] = 'c'，按键变更。
从 s[4] = 'c' 到 s[5] = 'C'，不存在按键变更，因为不计入 caps lock 或 shift 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AaAaAaaA"
<strong>输出：</strong>0
<strong>解释：</strong> 不存在按键变更，因为这个过程中只按下字母 'a' 和 'A' ，不需要进行按键变更。<!-- notionvc: 8849fe75-f31e-41dc-a2e0-b7d33d8427d2 -->
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由英文大写字母和小写字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以遍历字符串，每次判断当前字符的小写形式是否与前一个字符的小写形式相同，如果不同则说明发生了按键变更，将答案加一即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countKeyChanges(self, s: str) -> int:
        return sum(a != b for a, b in pairwise(s.lower()))
```

#### Java

```java
class Solution {
    public int countKeyChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(i - 1))) {
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
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
```

#### Go

```go
func countKeyChanges(s string) (ans int) {
	s = strings.ToLower(s)
	for i, c := range s[1:] {
		if byte(c) != s[i] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countKeyChanges(s: string): number {
    s = s.toLowerCase();
    let ans = 0;
    for (let i = 1; i < s.length; ++i) {
        if (s[i] !== s[i - 1]) {
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_key_changes(s: String) -> i32 {
        let s = s.to_lowercase();
        let bytes = s.as_bytes();
        let mut ans = 0;
        for i in 1..bytes.len() {
            if bytes[i] != bytes[i - 1] {
                ans += 1;
            }
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
