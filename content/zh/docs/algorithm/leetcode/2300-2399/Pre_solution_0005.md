---
title: "2340_生成有效数组的最少交换次数 🔒"
date: 2025-10-08T18:39:12+08:00
weight: 5
tags: [分治, 单调栈, 哈希表, 基数排序, 堆（优先队列）, 字符串, 快速选择, 排序, 数学, 数据库, 数组, 数论, 有序集合, 栈, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2340_生成有效数组的最少交换次数 🔒](#2340)
#### [贪心](#2340)
#### [数组](#2340)
### [2341_数组能形成多少数对](#2341)
#### [数组](#2341)
#### [哈希表](#2341)
#### [计数](#2341)
### [2342_数位和相等数对的最大和](#2342)
#### [数组](#2342)
#### [哈希表](#2342)
#### [排序](#2342)
#### [堆（优先队列）](#2342)
### [2343_裁剪数字后查询第 K 小的数字](#2343)
#### [数组](#2343)
#### [字符串](#2343)
#### [分治](#2343)
#### [快速选择](#2343)
#### [基数排序](#2343)
#### [排序](#2343)
#### [堆（优先队列）](#2343)
### [2344_使数组可以被整除的最少删除次数](#2344)
#### [数组](#2344)
#### [数学](#2344)
#### [数论](#2344)
#### [排序](#2344)
#### [堆（优先队列）](#2344)
### [2345_寻找可见山的数量 🔒](#2345)
#### [栈](#2345)
#### [数组](#2345)
#### [排序](#2345)
#### [单调栈](#2345)
### [2346_以百分比计算排名 🔒](#2346)
#### [数据库](#2346)
### [2347_最好的扑克手牌](#2347)
#### [数组](#2347)
#### [哈希表](#2347)
#### [计数](#2347)
### [2348_全 0 子数组的数目](#2348)
#### [数组](#2348)
#### [数学](#2348)
### [2349_设计数字容器系统](#2349)
#### [设计](#2349)
#### [哈希表](#2349)
#### [有序集合](#2349)
#### [堆（优先队列）](#2349)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2340_生成有效数组的最少交换次数 🔒
___
#### 贪心
___
#### 数组
---
### 2341_数组能形成多少数对
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2342_数位和相等数对的最大和
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 堆（优先队列）
---
### 2343_裁剪数字后查询第 K 小的数字
___
#### 数组
___
#### 字符串
___
#### 分治
___
#### 快速选择
___
#### 基数排序
___
#### 排序
___
#### 堆（优先队列）
---
### 2344_使数组可以被整除的最少删除次数
___
#### 数组
___
#### 数学
___
#### 数论
___
#### 排序
___
#### 堆（优先队列）
---
### 2345_寻找可见山的数量 🔒
___
#### 栈
___
#### 数组
___
#### 排序
___
#### 单调栈
---
### 2346_以百分比计算排名 🔒
___
#### 数据库
---
### 2347_最好的扑克手牌
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2348_全 0 子数组的数目
___
#### 数组
___
#### 数学
---
### 2349_设计数字容器系统
___
#### 设计
___
#### 哈希表
___
#### 有序集合
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 分治 | 单调栈 | 哈希表 |
| 基数排序 | 堆（优先队列） | 字符串 |
| 快速选择 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 有序集合 | 栈 | 计数 |
| 设计 | 贪心 |  |

# [2340. 生成有效数组的最少交换次数 🔒](https://leetcode.cn/problems/minimum-adjacent-swaps-to-make-a-valid-array){#2340}

{{< tabs "2340" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        i = j = 0
        for k, v in enumerate(nums):
            if v < nums[i] or (v == nums[i] and k < i):
                i = k
            if v >= nums[j] or (v == nums[j] and k > j):
                j = k
        return 0 if i == j else i + len(nums) - 1 - j - (i > j)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSwaps(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[i] || (nums[k] == nums[i] && k < i)) {
                i = k;
            }
            if (nums[k] > nums[j] || (nums[k] == nums[j] && k > j)) {
                j = k;
            }
        }
        if (i == j) {
            return 0;
        }
        return i + n - 1 - j - (i > j ? 1 : 0);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[i] || (nums[k] == nums[i] && k < i)) {
                i = k;
            }
            if (nums[k] > nums[j] || (nums[k] == nums[j] && k > j)) {
                j = k;
            }
        }
        if (i == j) {
            return 0;
        }
        return i + n - 1 - j - (i > j);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSwaps(nums []int) int {
	var i, j int
	for k, v := range nums {
		if v < nums[i] || (v == nums[i] && k < i) {
			i = k
		}
		if v > nums[j] || (v == nums[j] && k > j) {
			j = k
		}
	}
	if i == j {
		return 0
	}
	if i < j {
		return i + len(nums) - 1 - j
	}
	return i + len(nums) - 2 - j
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSwaps(nums: number[]): number {
    let i = 0;
    let j = 0;
    const n = nums.length;
    for (let k = 0; k < n; ++k) {
        if (nums[k] < nums[i] || (nums[k] == nums[i] && k < i)) {
            i = k;
        }
        if (nums[k] > nums[j] || (nums[k] == nums[j] && k > j)) {
            j = k;
        }
    }
    return i == j ? 0 : i + n - 1 - j - (i > j ? 1 : 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个<strong>&nbsp;下标从 0 开始</strong>&nbsp;的整数数组 <code>nums</code>。</p>

<p><code>nums</code>&nbsp;上的&nbsp;<strong>相邻&nbsp;</strong>元素可以进行&nbsp;<strong>交换</strong>。</p>

<p data-group="1-1">一个&nbsp;<strong>有效&nbsp;</strong>的数组必须满足以下条件:</p>

<ul>
	<li>最大的元素 (如果有多个，则为最大元素中的任何一个) 位于数组中最右边的位置。</li>
	<li>最小的元素 (如果有多个，则为最小的任何一个元素) 位于数组的最左侧。</li>
</ul>

<p>返回<em>使 </em><code>nums</code><em> </em><em>成为有效数组所需的最少交换次数。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [3,4,5,5,3,1]
<strong>输出:</strong> 6
<strong>解释:</strong> 进行以下交换:
- 交换 1:交换第 3 和第 4 个元素，然后 nums 是 [3,4,5,<u><strong>3</strong></u>,<u><strong>5</strong></u>,1].
- 交换 2:交换第 4 和第 5 个元素，然后 nums 是 [3,4,5,3,<u><strong>1</strong></u>,<u><strong>5</strong></u>].
- 交换 3:交换第 3 和第 4 个元素，然后 nums 是  [3,4,5,<u><strong>1</strong></u>,<u><strong>3</strong></u>,5].
- 交换 4:交换第 2 和第 3 个元素，然后 nums 是  [3,4,<u><strong>1</strong></u>,<u><strong>5</strong></u>,3,5].
- 交换 5:交换第 1 和第 2 个元素，然后 nums 是  [3,<u><strong>1</strong></u>,<u><strong>4</strong></u>,5,3,5].
- 交换 6:交换第 0 和第 1 个元素，然后 nums 是  [<u><strong>1</strong></u>,<u><strong>3</strong></u>,4,5,3,5].
可以证明，6 次交换是组成一个有效数组所需的最少交换次数。
</pre>

<strong class="example">示例 2:</strong>

<pre>
<strong>输入:</strong> nums = [9]
<strong>输出:</strong> 0
<strong>解释:</strong> 该数组已经有效，因此返回 0。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护最值下标 + 分类讨论

我们可以用下标 $i$ 和 $j$ 分别记录数组 $\textit{nums}$ 第一个最小值和最后一个最大值的下标，遍历数组 $\textit{nums}$，更新 $i$ 和 $j$ 的值。

接下来，我们需要考虑交换的次数。

-   如果 $i = j$，说明数组 $\textit{nums}$ 已经是有效数组，不需要交换，返回 $0$；
-   如果 $i < j$，说明数组 $\textit{nums}$ 中最小值在最大值的左边，需要交换 $i + n - 1 - j$ 次，其中 $n$ 为数组 $\textit{nums}$ 的长度；
-   如果 $i > j$，说明数组 $\textit{nums}$ 中最小值在最大值的右边，需要交换 $i + n - 1 - j - 1$ 次。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        i = j = 0
        for k, v in enumerate(nums):
            if v < nums[i] or (v == nums[i] and k < i):
                i = k
            if v >= nums[j] or (v == nums[j] and k > j):
                j = k
        return 0 if i == j else i + len(nums) - 1 - j - (i > j)
```

#### Java

```java
class Solution {
    public int minimumSwaps(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[i] || (nums[k] == nums[i] && k < i)) {
                i = k;
            }
            if (nums[k] > nums[j] || (nums[k] == nums[j] && k > j)) {
                j = k;
            }
        }
        if (i == j) {
            return 0;
        }
        return i + n - 1 - j - (i > j ? 1 : 0);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[i] || (nums[k] == nums[i] && k < i)) {
                i = k;
            }
            if (nums[k] > nums[j] || (nums[k] == nums[j] && k > j)) {
                j = k;
            }
        }
        if (i == j) {
            return 0;
        }
        return i + n - 1 - j - (i > j);
    }
};
```

#### Go

```go
func minimumSwaps(nums []int) int {
	var i, j int
	for k, v := range nums {
		if v < nums[i] || (v == nums[i] && k < i) {
			i = k
		}
		if v > nums[j] || (v == nums[j] && k > j) {
			j = k
		}
	}
	if i == j {
		return 0
	}
	if i < j {
		return i + len(nums) - 1 - j
	}
	return i + len(nums) - 2 - j
}
```

#### TypeScript

```ts
function minimumSwaps(nums: number[]): number {
    let i = 0;
    let j = 0;
    const n = nums.length;
    for (let k = 0; k < n; ++k) {
        if (nums[k] < nums[i] || (nums[k] == nums[i] && k < i)) {
            i = k;
        }
        if (nums[k] > nums[j] || (nums[k] == nums[j] && k > j)) {
            j = k;
        }
    }
    return i == j ? 0 : i + n - 1 - j - (i > j ? 1 : 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2341. 数组能形成多少数对](https://leetcode.cn/problems/maximum-number-of-pairs-in-array){#2341}

{{< tabs "2341" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        s = sum(v // 2 for v in cnt.values())
        return [s, len(nums) - s * 2]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] numberOfPairs(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        int s = 0;
        for (int v : cnt) {
            s += v / 2;
        }
        return new int[] {s, nums.length - s * 2};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> cnt(101);
        for (int& x : nums) {
            ++cnt[x];
        }
        int s = 0;
        for (int& v : cnt) {
            s += v >> 1;
        }
        return {s, (int) nums.size() - s * 2};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPairs(nums []int) []int {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	s := 0
	for _, v := range cnt {
		s += v / 2
	}
	return []int{s, len(nums) - s*2}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPairs(nums: number[]): number[] {
    const n = nums.length;
    const count = new Array(101).fill(0);
    for (const num of nums) {
        count[num]++;
    }
    const sum = count.reduce((r, v) => r + (v >> 1), 0);
    return [sum, n - sum * 2];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_pairs(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut count = [0; 101];
        for &v in nums.iter() {
            count[v as usize] += 1;
        }
        let mut sum = 0;
        for v in count.iter() {
            sum += v >> 1;
        }
        vec![sum as i32, (n - sum * 2) as i32]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var numberOfPairs = function (nums) {
    const cnt = new Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    const s = cnt.reduce((a, b) => a + (b >> 1), 0);
    return [s, nums.length - s * 2];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] NumberOfPairs(int[] nums) {
        int[] cnt = new int[101];
        foreach(int x in nums) {
            ++cnt[x];
        }
        int s = 0;
        foreach(int v in cnt) {
            s += v / 2;
        }
        return new int[] {s, nums.Length - s * 2};
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
    int count[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < 101; i++) {
        sum += count[i] >> 1;
    }
    int* ans = malloc(sizeof(int) * 2);
    ans[0] = sum;
    ans[1] = numsSize - sum * 2;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。在一步操作中，你可以执行以下步骤：</p>

<ul>
	<li>从 <code>nums</code> 选出 <strong>两个</strong> <strong>相等的</strong> 整数</li>
	<li>从 <code>nums</code> 中移除这两个整数，形成一个 <strong>数对</strong></li>
</ul>

<p>请你在 <code>nums</code> 上多次执行此操作直到无法继续执行。</p>

<p>返回一个下标从 <strong>0</strong> 开始、长度为 <code>2</code> 的整数数组 <code>answer</code> 作为答案，其中<em> </em><code>answer[0]</code><em> </em>是形成的数对数目，<code>answer[1]</code> 是对 <code>nums</code> 尽可能执行上述操作后剩下的整数数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,2,1,3,2,2]
<strong>输出：</strong>[3,1]
<strong>解释：</strong>
nums[0] 和 nums[3] 形成一个数对，并从 nums 中移除，nums = [3,2,3,2,2] 。
nums[0] 和 nums[2] 形成一个数对，并从 nums 中移除，nums = [2,2,2] 。
nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [2] 。
无法形成更多数对。总共形成 3 个数对，nums 中剩下 1 个数字。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [] 。
无法形成更多数对。总共形成 1 个数对，nums 中剩下 0 个数字。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [0]
<strong>输出：</strong>[0,1]
<strong>解释：</strong>无法形成数对，nums 中剩下 1 个数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以统计数组 $\textit{nums}$ 中每个数字 $x$ 出现的次数，记录在哈希表或数组 $\textit{cnt}$ 中。

然后遍历 $\textit{cnt}$，对于每个数字 $x$，如果 $x$ 出现的次数 $v$ 大于 $1$，则可以从数组中选出两个 $x$ 形成一个数对，我们将 $v$ 除以 $2$ 向下取整，即可得到当前数字 $x$ 可以形成的数对数目，然后我们累加这个数目到变量 $s$ 中。

最后剩余的个数为数组 $\textit{nums}$ 的长度减去可以形成的数对数目乘以 $2$，即 $n - s \times 2$。

答案为 $[s, n - s \times 2]$。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为数组 $\textit{nums}$ 的长度；而 $C$ 为数组 $\textit{nums}$ 中数字的范围，本题中 $C = 101$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        s = sum(v // 2 for v in cnt.values())
        return [s, len(nums) - s * 2]
```

#### Java

```java
class Solution {
    public int[] numberOfPairs(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        int s = 0;
        for (int v : cnt) {
            s += v / 2;
        }
        return new int[] {s, nums.length - s * 2};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> cnt(101);
        for (int& x : nums) {
            ++cnt[x];
        }
        int s = 0;
        for (int& v : cnt) {
            s += v >> 1;
        }
        return {s, (int) nums.size() - s * 2};
    }
};
```

#### Go

```go
func numberOfPairs(nums []int) []int {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	s := 0
	for _, v := range cnt {
		s += v / 2
	}
	return []int{s, len(nums) - s*2}
}
```

#### TypeScript

```ts
function numberOfPairs(nums: number[]): number[] {
    const n = nums.length;
    const count = new Array(101).fill(0);
    for (const num of nums) {
        count[num]++;
    }
    const sum = count.reduce((r, v) => r + (v >> 1), 0);
    return [sum, n - sum * 2];
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_pairs(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut count = [0; 101];
        for &v in nums.iter() {
            count[v as usize] += 1;
        }
        let mut sum = 0;
        for v in count.iter() {
            sum += v >> 1;
        }
        vec![sum as i32, (n - sum * 2) as i32]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var numberOfPairs = function (nums) {
    const cnt = new Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    const s = cnt.reduce((a, b) => a + (b >> 1), 0);
    return [s, nums.length - s * 2];
};
```

#### C#

```cs
public class Solution {
    public int[] NumberOfPairs(int[] nums) {
        int[] cnt = new int[101];
        foreach(int x in nums) {
            ++cnt[x];
        }
        int s = 0;
        foreach(int v in cnt) {
            s += v / 2;
        }
        return new int[] {s, nums.Length - s * 2};
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
    int count[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < 101; i++) {
        sum += count[i] >> 1;
    }
    int* ans = malloc(sizeof(int) * 2);
    ans[0] = sum;
    ans[1] = numsSize - sum * 2;
    *returnSize = 2;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2342. 数位和相等数对的最大和](https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits){#2342}

{{< tabs "2342" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        d = defaultdict(int)
        ans = -1
        for v in nums:
            x, y = 0, v
            while y:
                x += y % 10
                y //= 10
            if x in d:
                ans = max(ans, d[x] + v)
            d[x] = max(d[x], v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumSum(int[] nums) {
        int[] d = new int[100];
        int ans = -1;
        for (int v : nums) {
            int x = 0;
            for (int y = v; y > 0; y /= 10) {
                x += y % 10;
            }
            if (d[x] > 0) {
                ans = Math.max(ans, d[x] + v);
            }
            d[x] = Math.max(d[x], v);
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
    int maximumSum(vector<int>& nums) {
        int d[100]{};
        int ans = -1;
        for (int v : nums) {
            int x = 0;
            for (int y = v; y; y /= 10) {
                x += y % 10;
            }
            if (d[x]) {
                ans = max(ans, d[x] + v);
            }
            d[x] = max(d[x], v);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSum(nums []int) int {
	d := [100]int{}
	ans := -1
	for _, v := range nums {
		x := 0
		for y := v; y > 0; y /= 10 {
			x += y % 10
		}
		if d[x] > 0 {
			ans = max(ans, d[x]+v)
		}
		d[x] = max(d[x], v)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSum(nums: number[]): number {
    const d: number[] = Array(100).fill(0);
    let ans = -1;
    for (const v of nums) {
        let x = 0;
        for (let y = v; y; y = (y / 10) | 0) {
            x += y % 10;
        }
        if (d[x]) {
            ans = Math.max(ans, d[x] + v);
        }
        d[x] = Math.max(d[x], v);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_sum(nums: Vec<i32>) -> i32 {
        let mut d = vec![0; 100];
        let mut ans = -1;

        for &v in nums.iter() {
            let mut x: usize = 0;
            let mut y = v;
            while y > 0 {
                x += (y % 10) as usize;
                y /= 10;
            }
            if d[x] > 0 {
                ans = ans.max(d[x] + v);
            }
            d[x] = d[x].max(v);
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

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组中的元素都是 <strong>正</strong> 整数。请你选出两个下标 <code>i</code> 和 <code>j</code>（<code>i != j</code>），且 <code>nums[i]</code> 的数位和 与&nbsp; <code>nums[j]</code> 的数位和相等。</p>

<p>请你找出所有满足条件的下标 <code>i</code> 和 <code>j</code> ，找出并返回<em> </em><code>nums[i] + nums[j]</code><em> </em>可以得到的 <strong>最大值</strong><em>。</em>如果不存在这样的下标对，返回 -1。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [18,43,36,13,7]
<strong>输出：</strong>54
<strong>解释：</strong>满足条件的数对 (i, j) 为：
- (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
- (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
所以可以获得的最大和是 54 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,12,19,14]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在满足条件的数对，返回 -1 。
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

### 方法一：哈希表

我们可以用一个哈希表 $d$ 记录每个数位和对应的最大值，初始化一个答案变量 $ans = -1$。

接下来，我们遍历数组 $nums$，对于每个数 $v$，我们计算它的数位和 $x$，如果 $x$ 在哈希表 $d$ 中存在，那么我们就更新答案 $ans = \max(ans, d[x] + v)$。然后更新哈希表 $d[x] = \max(d[x], v)$。

最后返回答案 $ans$ 即可。

由于 $nums$ 中的元素最大为 $10^9$，因此数位和最大为 $9 \times 9 = 81$，我们可以直接定义一个长度为 $100$ 的数组 $d$ 来代替哈希表。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(D)$，其中 $n$ 是数组 $nums$ 的长度，而 $M$ 和 $D$ 分别是数组 $nums$ 中的元素的最大值和数位和的最大值。本题中 $M \leq 10^9$，$D \leq 81$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        d = defaultdict(int)
        ans = -1
        for v in nums:
            x, y = 0, v
            while y:
                x += y % 10
                y //= 10
            if x in d:
                ans = max(ans, d[x] + v)
            d[x] = max(d[x], v)
        return ans
```

#### Java

```java
class Solution {
    public int maximumSum(int[] nums) {
        int[] d = new int[100];
        int ans = -1;
        for (int v : nums) {
            int x = 0;
            for (int y = v; y > 0; y /= 10) {
                x += y % 10;
            }
            if (d[x] > 0) {
                ans = Math.max(ans, d[x] + v);
            }
            d[x] = Math.max(d[x], v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int d[100]{};
        int ans = -1;
        for (int v : nums) {
            int x = 0;
            for (int y = v; y; y /= 10) {
                x += y % 10;
            }
            if (d[x]) {
                ans = max(ans, d[x] + v);
            }
            d[x] = max(d[x], v);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSum(nums []int) int {
	d := [100]int{}
	ans := -1
	for _, v := range nums {
		x := 0
		for y := v; y > 0; y /= 10 {
			x += y % 10
		}
		if d[x] > 0 {
			ans = max(ans, d[x]+v)
		}
		d[x] = max(d[x], v)
	}
	return ans
}
```

#### TypeScript

```ts
function maximumSum(nums: number[]): number {
    const d: number[] = Array(100).fill(0);
    let ans = -1;
    for (const v of nums) {
        let x = 0;
        for (let y = v; y; y = (y / 10) | 0) {
            x += y % 10;
        }
        if (d[x]) {
            ans = Math.max(ans, d[x] + v);
        }
        d[x] = Math.max(d[x], v);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_sum(nums: Vec<i32>) -> i32 {
        let mut d = vec![0; 100];
        let mut ans = -1;

        for &v in nums.iter() {
            let mut x: usize = 0;
            let mut y = v;
            while y > 0 {
                x += (y % 10) as usize;
                y /= 10;
            }
            if d[x] > 0 {
                ans = ans.max(d[x] + v);
            }
            d[x] = d[x].max(v);
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

# [2343. 裁剪数字后查询第 K 小的数字](https://leetcode.cn/problems/query-kth-smallest-trimmed-number){#2343}

{{< tabs "2343" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestTrimmedNumbers(
        self, nums: List[str], queries: List[List[int]]
    ) -> List[int]:
        ans = []
        for k, trim in queries:
            t = sorted((v[-trim:], i) for i, v in enumerate(nums))
            ans.append(t[k - 1][1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;
        int[] ans = new int[m];
        String[][] t = new String[n][2];
        for (int i = 0; i < m; ++i) {
            int k = queries[i][0], trim = queries[i][1];
            for (int j = 0; j < n; ++j) {
                t[j] = new String[] {nums[j].substring(nums[j].length() - trim), String.valueOf(j)};
            }
            Arrays.sort(t, (a, b) -> {
                int x = a[0].compareTo(b[0]);
                return x == 0 ? Long.compare(Integer.valueOf(a[1]), Integer.valueOf(b[1])) : x;
            });
            ans[i] = Integer.valueOf(t[k - 1][1]);
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
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<string, int>> t(n);
        vector<int> ans;
        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            for (int j = 0; j < n; ++j) {
                t[j] = {nums[j].substr(nums[j].size() - trim), j};
            }
            sort(t.begin(), t.end());
            ans.push_back(t[k - 1].second);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestTrimmedNumbers(nums []string, queries [][]int) []int {
	type pair struct {
		s string
		i int
	}
	ans := make([]int, len(queries))
	t := make([]pair, len(nums))
	for i, q := range queries {
		for j, s := range nums {
			t[j] = pair{s[len(s)-q[1]:], j}
		}
		sort.Slice(t, func(i, j int) bool { a, b := t[i], t[j]; return a.s < b.s || a.s == b.s && a.i < b.i })
		ans[i] = t[q[0]-1].i
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>nums</code>&nbsp;，其中每个字符串 <strong>长度相等</strong>&nbsp;且只包含数字。</p>

<p>再给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [k<sub>i</sub>, trim<sub>i</sub>]</code>&nbsp;。对于每个&nbsp;<code>queries[i]</code>&nbsp;，你需要：</p>

<ul>
	<li>将&nbsp;<code>nums</code>&nbsp;中每个数字 <strong>裁剪</strong>&nbsp;到剩下 <strong>最右边</strong>&nbsp;<code>trim<sub>i</sub></code>&nbsp;个数位。</li>
	<li>在裁剪过后的数字中，找到 <code>nums</code>&nbsp;中第&nbsp;<code>k<sub>i</sub></code>&nbsp;小数字对应的 <strong>下标</strong>&nbsp;。如果两个裁剪后数字一样大，那么下标 <strong>更小</strong>&nbsp;的数字视为更小的数字。</li>
	<li>将 <code>nums</code>&nbsp;中每个数字恢复到原本字符串。</li>
</ul>

<p>请你返回一个长度与 <code><span style="">queries</span></code>&nbsp;相等的数组<em>&nbsp;</em><code>answer</code>，其中<em>&nbsp;</em><code>answer[i]</code>是第<em>&nbsp;</em><code>i</code><em>&nbsp;</em>次查询的结果。</p>

<p><strong>提示：</strong></p>

<ul>
	<li>裁剪到剩下最右边 <code>x</code>&nbsp;个数位的意思是不断删除最左边的数位，直到剩下 <code>x</code>&nbsp;个数位。</li>
	<li><code>nums</code>&nbsp;中的字符串可能会有前导 0 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
<b>输出：</b>[2,2,1,0]
<strong>解释：</strong>
1. 裁剪到只剩 1 个数位后，nums = ["2","3","1","4"] 。最小的数字是 1 ，下标为 2 。
2. 裁剪到剩 3 个数位后，nums 没有变化。第 2 小的数字是 251 ，下标为 2 。
3. 裁剪到剩 2 个数位后，nums = ["02","73","51","14"] 。第 4 小的数字是 73 ，下标为 1 。
4. 裁剪到剩 2 个数位后，最小数字是 2 ，下标为 0 。
   注意，裁剪后数字 "02" 值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
<b>输出：</b>[3,0]
<strong>解释：</strong>
1. 裁剪到剩 1 个数位，nums = ["4","7","6","4"] 。第 2 小的数字是 4 ，下标为 3 。
   有两个 4 ，下标为 0 的 4 视为小于下标为 3 的 4 。
2. 裁剪到剩 2 个数位，nums 不变。第二小的数字是 24 ，下标为 0 。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
	<li><code>nums[i]</code> 只包含数字。</li>
	<li>所有&nbsp;<code>nums[i].length</code>&nbsp;的长度 <b>相同</b>&nbsp;。</li>
	<li><code>1 &lt;= queries.length &lt;= 100</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= k<sub>i</sub> &lt;= nums.length</code></li>
	<li><code>1 &lt;= trim<sub>i</sub> &lt;= nums[0].length</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能使用 <strong>基数排序算法</strong> 解决此问题吗？这种解法的复杂度又是多少？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意，我们可以模拟裁剪过程，然后对裁剪后的字符串进行排序，最后根据下标找到对应的数字即可。

时间复杂度 $O(m \times \ n \times \log n \times s)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别为 $\textit{nums}$ 和 $\textit{queries}$ 的长度，而 $s$ 为 $\textit{nums}[i]$ 字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestTrimmedNumbers(
        self, nums: List[str], queries: List[List[int]]
    ) -> List[int]:
        ans = []
        for k, trim in queries:
            t = sorted((v[-trim:], i) for i, v in enumerate(nums))
            ans.append(t[k - 1][1])
        return ans
```

#### Java

```java
class Solution {
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;
        int[] ans = new int[m];
        String[][] t = new String[n][2];
        for (int i = 0; i < m; ++i) {
            int k = queries[i][0], trim = queries[i][1];
            for (int j = 0; j < n; ++j) {
                t[j] = new String[] {nums[j].substring(nums[j].length() - trim), String.valueOf(j)};
            }
            Arrays.sort(t, (a, b) -> {
                int x = a[0].compareTo(b[0]);
                return x == 0 ? Long.compare(Integer.valueOf(a[1]), Integer.valueOf(b[1])) : x;
            });
            ans[i] = Integer.valueOf(t[k - 1][1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<string, int>> t(n);
        vector<int> ans;
        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            for (int j = 0; j < n; ++j) {
                t[j] = {nums[j].substr(nums[j].size() - trim), j};
            }
            sort(t.begin(), t.end());
            ans.push_back(t[k - 1].second);
        }
        return ans;
    }
};
```

#### Go

```go
func smallestTrimmedNumbers(nums []string, queries [][]int) []int {
	type pair struct {
		s string
		i int
	}
	ans := make([]int, len(queries))
	t := make([]pair, len(nums))
	for i, q := range queries {
		for j, s := range nums {
			t[j] = pair{s[len(s)-q[1]:], j}
		}
		sort.Slice(t, func(i, j int) bool { a, b := t[i], t[j]; return a.s < b.s || a.s == b.s && a.i < b.i })
		ans[i] = t[q[0]-1].i
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2344. 使数组可以被整除的最少删除次数](https://leetcode.cn/problems/minimum-deletions-to-make-array-divisible){#2344}

{{< tabs "2344" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        x = gcd(*numsDivide)
        y = min((v for v in nums if x % v == 0), default=0)
        return sum(v < y for v in nums) if y else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        int x = 0;
        for (int v : numsDivide) {
            x = gcd(x, v);
        }
        int y = 1 << 30;
        for (int v : nums) {
            if (x % v == 0) {
                y = Math.min(y, v);
            }
        }
        if (y == 1 << 30) {
            return -1;
        }
        int ans = 0;
        for (int v : nums) {
            if (v < y) {
                ++ans;
            }
        }
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
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int x = 0;
        for (int& v : numsDivide) {
            x = gcd(x, v);
        }
        int y = 1 << 30;
        for (int& v : nums) {
            if (x % v == 0) {
                y = min(y, v);
            }
        }
        if (y == 1 << 30) {
            return -1;
        }
        int ans = 0;
        for (int& v : nums) {
            ans += v < y;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, numsDivide []int) int {
	x := 0
	for _, v := range numsDivide {
		x = gcd(x, v)
	}
	y := 1 << 30
	for _, v := range nums {
		if x%v == 0 {
			y = min(y, v)
		}
	}
	if y == 1<<30 {
		return -1
	}
	ans := 0
	for _, v := range nums {
		if v < y {
			ans++
		}
	}
	return ans
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

<p>给你两个正整数数组&nbsp;<code>nums</code> 和&nbsp;<code>numsDivide</code>&nbsp;。你可以从&nbsp;<code>nums</code>&nbsp;中删除任意数目的元素。</p>

<p>请你返回使 <code>nums</code>&nbsp;中 <strong>最小</strong>&nbsp;元素可以整除 <code>numsDivide</code>&nbsp;中所有元素的 <strong>最少</strong>&nbsp;删除次数。如果无法得到这样的元素，返回 <code>-1</code>&nbsp;。</p>

<p>如果&nbsp;<code>y % x == 0</code>&nbsp;，那么我们说整数&nbsp;<code>x</code>&nbsp;整除&nbsp;<code>y</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
<b>输出：</b>2
<b>解释：</b>
[2,3,2,4,3] 中最小元素是 2 ，它无法整除 numsDivide 中所有元素。
我们从 nums 中删除 2 个大小为 2 的元素，得到 nums = [3,4,3] 。
[3,4,3] 中最小元素为 3 ，它可以整除 numsDivide 中所有元素。
可以证明 2 是最少删除次数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [4,3,6], numsDivide = [8,2,6,10]
<b>输出：</b>-1
<b>解释：</b>
我们想 nums 中的最小元素可以整除 numsDivide 中的所有元素。
没有任何办法可以达到这一目的。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, numsDivide.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], numsDivide[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 排序

如果一个元素能整除数组 `numsDivide` 所有元素，那么这个元素是所有 $numsDivide[i]$ 的最大公约数 $x$ 的因子。因此，我们可以先求出 `numsDivide` 的最大公约数 $x$。

接下来，将数组 `nums` 排序，然后从头到尾遍历数组 `nums`，找到第一个是最大公约数 $x$ 的因子的元素，返回当前元素下标即可。

时间复杂度 $O(m + \log M + n \times \log n)$，其中 $n$ 和 $m$ 分别是数组 `nums` 和 `numsDivide` 的长度，而 $M$ 是数组 `numsDivide` 中的最大值。

实际上，我们也可以不用排序数组 `nums`，而是直接遍历数组 `nums`，找到最小的能整除 $x$ 的元素，然后我们再遍历一次数组 `nums`，统计小于等于这个元素的元素个数即可。

时间复杂度 $O(m + \log M + n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        x = numsDivide[0]
        for v in numsDivide[1:]:
            x = gcd(x, v)
        nums.sort()
        for i, v in enumerate(nums):
            if x % v == 0:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        int x = 0;
        for (int v : numsDivide) {
            x = gcd(x, v);
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {
            if (x % nums[i] == 0) {
                return i;
            }
        }
        return -1;
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
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int x = 0;
        for (int& v : numsDivide) {
            x = gcd(x, v);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (x % nums[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minOperations(nums []int, numsDivide []int) int {
	x := 0
	for _, v := range numsDivide {
		x = gcd(x, v)
	}
	sort.Ints(nums)
	for i, v := range nums {
		if x%v == 0 {
			return i
		}
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

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        x = gcd(*numsDivide)
        nums.sort()
        return next((i for i, v in enumerate(nums) if x % v == 0), -1)
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        int x = 0;
        for (int v : numsDivide) {
            x = gcd(x, v);
        }
        int y = 1 << 30;
        for (int v : nums) {
            if (x % v == 0) {
                y = Math.min(y, v);
            }
        }
        if (y == 1 << 30) {
            return -1;
        }
        int ans = 0;
        for (int v : nums) {
            if (v < y) {
                ++ans;
            }
        }
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
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int x = 0;
        for (int& v : numsDivide) {
            x = gcd(x, v);
        }
        int y = 1 << 30;
        for (int& v : nums) {
            if (x % v == 0) {
                y = min(y, v);
            }
        }
        if (y == 1 << 30) {
            return -1;
        }
        int ans = 0;
        for (int& v : nums) {
            ans += v < y;
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int, numsDivide []int) int {
	x := 0
	for _, v := range numsDivide {
		x = gcd(x, v)
	}
	y := 1 << 30
	for _, v := range nums {
		if x%v == 0 {
			y = min(y, v)
		}
	}
	if y == 1<<30 {
		return -1
	}
	ans := 0
	for _, v := range nums {
		if v < y {
			ans++
		}
	}
	return ans
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

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        x = gcd(*numsDivide)
        y = min((v for v in nums if x % v == 0), default=0)
        return sum(v < y for v in nums) if y else -1
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2345. 寻找可见山的数量 🔒](https://leetcode.cn/problems/finding-the-number-of-visible-mountains){#2345}

{{< tabs "2345" >}}

{{% tab "python" %}}
```python
class Solution:
    def visibleMountains(self, peaks: List[List[int]]) -> int:
        arr = [(x - y, x + y) for x, y in peaks]
        cnt = Counter(arr)
        arr.sort(key=lambda x: (x[0], -x[1]))
        ans, cur = 0, -inf
        for l, r in arr:
            if r <= cur:
                continue
            cur = r
            if cnt[(l, r)] == 1:
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int visibleMountains(int[][] peaks) {
        int n = peaks.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            int x = peaks[i][0], y = peaks[i][1];
            arr[i] = new int[] {x - y, x + y};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int cur = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int l = arr[i][0], r = arr[i][1];
            if (r <= cur) {
                continue;
            }
            cur = r;
            if (!(i < n - 1 && arr[i][0] == arr[i + 1][0] && arr[i][1] == arr[i + 1][1])) {
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
    int visibleMountains(vector<vector<int>>& peaks) {
        vector<pair<int, int>> arr;
        for (auto& e : peaks) {
            int x = e[0], y = e[1];
            arr.emplace_back(x - y, -(x + y));
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0, cur = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int l = arr[i].first, r = -arr[i].second;
            if (r <= cur) {
                continue;
            }
            cur = r;
            ans += i == n - 1 || (i < n - 1 && arr[i] != arr[i + 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func visibleMountains(peaks [][]int) (ans int) {
	n := len(peaks)
	type pair struct{ l, r int }
	arr := make([]pair, n)
	for _, p := range peaks {
		x, y := p[0], p[1]
		arr = append(arr, pair{x - y, x + y})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].l < arr[j].l || (arr[i].l == arr[j].l && arr[i].r > arr[j].r) })
	cur := math.MinInt32
	for i, e := range arr {
		l, r := e.l, e.r
		if r <= cur {
			continue
		}
		cur = r
		if !(i < n-1 && l == arr[i+1].l && r == arr[i+1].r) {
			ans++
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

<p>给定一个 <strong>下标从 0 开始&nbsp;</strong>的二维整数数组 <code>peaks</code>，其中 <code>peaks[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示山 <code>i</code> 在坐标 <code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;处有一个峰值。山可以被描述为一个直角等腰三角形，它的底部沿着 <code>x</code>&nbsp;轴，山峰处有一个直角。更正式地说，上山和下山的&nbsp;<strong>梯度&nbsp;</strong>分别为 <code>1</code>&nbsp;和 <code>-1</code>。</p>

<p>一座山如果它的顶峰不在另一座山 (包括其他山的边界) 之内，那么它被认为是&nbsp;<strong>可见&nbsp;</strong>的。</p>

<p data-group="1-1">返回<em>可见山的数量。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2345.Finding%20the%20Number%20of%20Visible%20Mountains/images/ex1.png" style="width: 402px; height: 210px;" />
<pre>
<strong>输入:</strong> peaks = [[2,2],[6,3],[5,4]]
<strong>输出:</strong> 2
<strong>解释:</strong> 上面的图表显示了山脉。
- 山 0 是可见的，因为它的峰值不在另一座山的里面或另一座山的边界。
- 山 1 是不可见的，因为它的顶峰在山 2 的边界。
- 山 2 是可见的，因为它的峰值不在另一座山的里面或另一座山的边界。
有 2 座山是可见的。</pre>

<p><strong class="example">示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2345.Finding%20the%20Number%20of%20Visible%20Mountains/images/ex2new1.png" style="width: 300px; height: 180px;" />
<pre>
<strong>输入:</strong> peaks = [[1,3],[1,3]]
<strong>输出:</strong> 0
<strong>解释:</strong> 上面的图表显示了这些山 (它们完全重叠)。
两座山都看不见，因为它们的山峰在彼此里面。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= peaks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>peaks[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：区间排序 + 遍历

我们先将每座山 $(x, y)$ 转换成横坐标的区间 $(x - y, x + y)$，然后对区间按照左端点升序排序，右端点降序排序。

接下来，初始化当前区间的右端点为 $-\infty$，遍历每座山，如果当前山的右端点小于等于当前区间的右端点，则跳过该山，否则更新当前区间的右端点为当前山的右端点，如果当前山的区间只出现一次，则答案加一。

遍历结束后返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为山的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def visibleMountains(self, peaks: List[List[int]]) -> int:
        arr = [(x - y, x + y) for x, y in peaks]
        cnt = Counter(arr)
        arr.sort(key=lambda x: (x[0], -x[1]))
        ans, cur = 0, -inf
        for l, r in arr:
            if r <= cur:
                continue
            cur = r
            if cnt[(l, r)] == 1:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int visibleMountains(int[][] peaks) {
        int n = peaks.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            int x = peaks[i][0], y = peaks[i][1];
            arr[i] = new int[] {x - y, x + y};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int cur = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int l = arr[i][0], r = arr[i][1];
            if (r <= cur) {
                continue;
            }
            cur = r;
            if (!(i < n - 1 && arr[i][0] == arr[i + 1][0] && arr[i][1] == arr[i + 1][1])) {
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
    int visibleMountains(vector<vector<int>>& peaks) {
        vector<pair<int, int>> arr;
        for (auto& e : peaks) {
            int x = e[0], y = e[1];
            arr.emplace_back(x - y, -(x + y));
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0, cur = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int l = arr[i].first, r = -arr[i].second;
            if (r <= cur) {
                continue;
            }
            cur = r;
            ans += i == n - 1 || (i < n - 1 && arr[i] != arr[i + 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func visibleMountains(peaks [][]int) (ans int) {
	n := len(peaks)
	type pair struct{ l, r int }
	arr := make([]pair, n)
	for _, p := range peaks {
		x, y := p[0], p[1]
		arr = append(arr, pair{x - y, x + y})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].l < arr[j].l || (arr[i].l == arr[j].l && arr[i].r > arr[j].r) })
	cur := math.MinInt32
	for i, e := range arr {
		l, r := e.l, e.r
		if r <= cur {
			continue
		}
		cur = r
		if !(i < n-1 && l == arr[i+1].l && r == arr[i+1].r) {
			ans++
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

# [2346. 以百分比计算排名 🔒](https://leetcode.cn/problems/compute-the-rank-as-a-percentage){#2346}

{{< tabs "2346" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    student_id,
    department_id,
    IFNULL(
        ROUND(
            (
                RANK() OVER (
                    PARTITION BY department_id
                    ORDER BY mark DESC
                ) - 1
            ) * 100 / (COUNT(1) OVER (PARTITION BY department_id) - 1),
            2
        ),
        0
    ) AS percentage
FROM Students;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Students</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| student_id    | int  |
| department_id | int  |
| mark          | int  |
+---------------+------+
student_id 包含唯一值。
该表的每一行都表示一个学生的 ID，该学生就读的院系 ID，以及他们的考试分数。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，以百分比的形式报告每个学生在其部门的排名，其中排名的百分比使用以下公式计算:</p>

<p><code>(student_rank_in_the_department - 1) * 100 / (the_number_of_students_in_the_department - 1)</code>。&nbsp;<code>percentage</code> 应该&nbsp;<strong>四舍五入到小数点后两位</strong>。&nbsp;</p>

<p><code>student_rank_in_the_department</code>&nbsp;由<b>&nbsp;</b><code>mark</code>&nbsp;的降序决定，<code>mark</code> 最高的学生是&nbsp; <code>rank 1</code>。如果两个学生得到相同的分数，他们也会得到相同的排名。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Students 表:
+------------+---------------+------+
| student_id | department_id | mark |
+------------+---------------+------+
| 2          | 2             | 650  |
| 8          | 2             | 650  |
| 7          | 1             | 920  |
| 1          | 1             | 610  |
| 3          | 1             | 530  |
+------------+---------------+------+
<strong>输出:</strong> 
+------------+---------------+------------+
| student_id | department_id | percentage |
+------------+---------------+------------+
| 7          | 1             | 0.0        |
| 1          | 1             | 50.0       |
| 3          | 1             | 100.0      |
| 2          | 2             | 0.0        |
| 8          | 2             | 0.0        |
+------------+---------------+------------+
<strong>解释:</strong> 
对于院系 1:
 - 学生 7:percentage = (1 - 1)* 100 / (3 - 1) = 0.0
 - 学生 1:percentage = (2 - 1)* 100 / (3 - 1) = 50.0
 - 学生 3:percentage = (3 - 1)* 100 / (3 - 1) = 100.0
对于院系 2:
 - 学生 2: percentage = (1 - 1) * 100 / (2 - 1) = 0.0
 - 学生 8: percentage = (1 - 1) * 100 / (2 - 1) = 0.0
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

注意空值判断。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    student_id,
    department_id,
    IFNULL(
        ROUND(
            (
                RANK() OVER (
                    PARTITION BY department_id
                    ORDER BY mark DESC
                ) - 1
            ) * 100 / (COUNT(1) OVER (PARTITION BY department_id) - 1),
            2
        ),
        0
    ) AS percentage
FROM Students;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2347. 最好的扑克手牌](https://leetcode.cn/problems/best-poker-hand){#2347}

{{< tabs "2347" >}}

{{% tab "python" %}}
```python
class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        # if len(set(suits)) == 1:
        if all(a == b for a, b in pairwise(suits)):
            return 'Flush'
        cnt = Counter(ranks)
        if any(v >= 3 for v in cnt.values()):
            return 'Three of a Kind'
        if any(v == 2 for v in cnt.values()):
            return 'Pair'
        return 'High Card'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        boolean flush = true;
        for (int i = 1; i < 5 && flush; ++i) {
            flush = suits[i] == suits[i - 1];
        }
        if (flush) {
            return "Flush";
        }
        int[] cnt = new int[14];
        boolean pair = false;
        for (int x : ranks) {
            if (++cnt[x] == 3) {
                return "Three of a Kind";
            }
            pair = pair || cnt[x] == 2;
        }
        return pair ? "Pair" : "High Card";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;
        for (int i = 1; i < 5 && flush; ++i) {
            flush = suits[i] == suits[i - 1];
        }
        if (flush) {
            return "Flush";
        }
        int cnt[14]{};
        bool pair = false;
        for (int& x : ranks) {
            if (++cnt[x] == 3) {
                return "Three of a Kind";
            }
            pair |= cnt[x] == 2;
        }
        return pair ? "Pair" : "High Card";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func bestHand(ranks []int, suits []byte) string {
	flush := true
	for i := 1; i < 5 && flush; i++ {
		flush = suits[i] == suits[i-1]
	}
	if flush {
		return "Flush"
	}
	cnt := [14]int{}
	pair := false
	for _, x := range ranks {
		cnt[x]++
		if cnt[x] == 3 {
			return "Three of a Kind"
		}
		pair = pair || cnt[x] == 2
	}
	if pair {
		return "Pair"
	}
	return "High Card"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function bestHand(ranks: number[], suits: string[]): string {
    if (suits.every(v => v === suits[0])) {
        return 'Flush';
    }
    const count = new Array(14).fill(0);
    let isPair = false;
    for (const v of ranks) {
        if (++count[v] === 3) {
            return 'Three of a Kind';
        }
        isPair = isPair || count[v] === 2;
    }
    if (isPair) {
        return 'Pair';
    }
    return 'High Card';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn best_hand(ranks: Vec<i32>, suits: Vec<char>) -> String {
        if suits.iter().all(|v| *v == suits[0]) {
            return "Flush".to_string();
        }
        let mut count = [0; 14];
        let mut is_pair = false;
        for &v in ranks.iter() {
            let i = v as usize;
            count[i] += 1;
            if count[i] == 3 {
                return "Three of a Kind".to_string();
            }
            is_pair = is_pair || count[i] == 2;
        }
        (if is_pair { "Pair" } else { "High Card" }).to_string()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize) {
    bool isFlush = true;
    for (int i = 1; i < suitsSize; i++) {
        if (suits[0] != suits[i]) {
            isFlush = false;
            break;
        }
    }
    if (isFlush) {
        return "Flush";
    }
    int count[14] = {0};
    bool isPair = false;
    for (int i = 0; i < ranksSize; i++) {
        if (++count[ranks[i]] == 3) {
            return "Three of a Kind";
        }
        isPair = isPair || count[ranks[i]] == 2;
    }
    if (isPair) {
        return "Pair";
    }
    return "High Card";
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>ranks</code>&nbsp;和一个字符数组&nbsp;<code>suit</code>&nbsp;。你有&nbsp;<code>5</code>&nbsp;张扑克牌，第&nbsp;<code>i</code>&nbsp;张牌大小为&nbsp;<code>ranks[i]</code>&nbsp;，花色为&nbsp;<code>suits[i]</code>&nbsp;。</p>

<p>下述是从好到坏你可能持有的 <strong>手牌类型&nbsp;</strong>：</p>

<ol>
	<li><code>"Flush"</code>：同花，五张相同花色的扑克牌。</li>
	<li><code>"Three of a Kind"</code>：三条，有 3 张大小相同的扑克牌。</li>
	<li><code>"Pair"</code>：对子，两张大小一样的扑克牌。</li>
	<li><code>"High Card"</code>：高牌，五张大小互不相同的扑克牌。</li>
</ol>

<p>请你返回一个字符串，表示给定的 5 张牌中，你能组成的 <strong>最好手牌类型</strong>&nbsp;。</p>

<p><strong>注意：</strong>返回的字符串&nbsp;<strong>大小写</strong>&nbsp;需与题目描述相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
<b>输出：</b>"Flush"
<b>解释：</b>5 张扑克牌的花色相同，所以返回 "Flush" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
<b>输出：</b>"Three of a Kind"
<b>解释：</b>第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
<b>输出：</b>"Pair"
<b>解释：</b>第一和第二张牌大小相同，所以得到 "Pair" 。
我们无法得到 "Flush" 或者 "Three of a Kind" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>ranks.length == suits.length == 5</code></li>
	<li><code>1 &lt;= ranks[i] &lt;= 13</code></li>
	<li><code>'a' &lt;= suits[i] &lt;= 'd'</code></li>
	<li>任意两张扑克牌不会同时有相同的大小和花色。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以先遍历数组 $\textit{suits}$，判断相邻两个元素是否均相等，如果是，则返回 `"Flush"`。

接下来，我们用哈希表或数组 $\textit{cnt}$ 统计每张牌的数量：

-   如果有任意一张牌的数量等于 $3$，返回 `"Three of a Kind"`；
-   否则，如果有任意一张牌的数量等于 $2$，返回 `"Pair"`；
-   否则，返回 `"High Card"`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{ranks}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        # if len(set(suits)) == 1:
        if all(a == b for a, b in pairwise(suits)):
            return 'Flush'
        cnt = Counter(ranks)
        if any(v >= 3 for v in cnt.values()):
            return 'Three of a Kind'
        if any(v == 2 for v in cnt.values()):
            return 'Pair'
        return 'High Card'
```

#### Java

```java
class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        boolean flush = true;
        for (int i = 1; i < 5 && flush; ++i) {
            flush = suits[i] == suits[i - 1];
        }
        if (flush) {
            return "Flush";
        }
        int[] cnt = new int[14];
        boolean pair = false;
        for (int x : ranks) {
            if (++cnt[x] == 3) {
                return "Three of a Kind";
            }
            pair = pair || cnt[x] == 2;
        }
        return pair ? "Pair" : "High Card";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;
        for (int i = 1; i < 5 && flush; ++i) {
            flush = suits[i] == suits[i - 1];
        }
        if (flush) {
            return "Flush";
        }
        int cnt[14]{};
        bool pair = false;
        for (int& x : ranks) {
            if (++cnt[x] == 3) {
                return "Three of a Kind";
            }
            pair |= cnt[x] == 2;
        }
        return pair ? "Pair" : "High Card";
    }
};
```

#### Go

```go
func bestHand(ranks []int, suits []byte) string {
	flush := true
	for i := 1; i < 5 && flush; i++ {
		flush = suits[i] == suits[i-1]
	}
	if flush {
		return "Flush"
	}
	cnt := [14]int{}
	pair := false
	for _, x := range ranks {
		cnt[x]++
		if cnt[x] == 3 {
			return "Three of a Kind"
		}
		pair = pair || cnt[x] == 2
	}
	if pair {
		return "Pair"
	}
	return "High Card"
}
```

#### TypeScript

```ts
function bestHand(ranks: number[], suits: string[]): string {
    if (suits.every(v => v === suits[0])) {
        return 'Flush';
    }
    const count = new Array(14).fill(0);
    let isPair = false;
    for (const v of ranks) {
        if (++count[v] === 3) {
            return 'Three of a Kind';
        }
        isPair = isPair || count[v] === 2;
    }
    if (isPair) {
        return 'Pair';
    }
    return 'High Card';
}
```

#### Rust

```rust
impl Solution {
    pub fn best_hand(ranks: Vec<i32>, suits: Vec<char>) -> String {
        if suits.iter().all(|v| *v == suits[0]) {
            return "Flush".to_string();
        }
        let mut count = [0; 14];
        let mut is_pair = false;
        for &v in ranks.iter() {
            let i = v as usize;
            count[i] += 1;
            if count[i] == 3 {
                return "Three of a Kind".to_string();
            }
            is_pair = is_pair || count[i] == 2;
        }
        (if is_pair { "Pair" } else { "High Card" }).to_string()
    }
}
```

#### C

```c
char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize) {
    bool isFlush = true;
    for (int i = 1; i < suitsSize; i++) {
        if (suits[0] != suits[i]) {
            isFlush = false;
            break;
        }
    }
    if (isFlush) {
        return "Flush";
    }
    int count[14] = {0};
    bool isPair = false;
    for (int i = 0; i < ranksSize; i++) {
        if (++count[ranks[i]] == 3) {
            return "Three of a Kind";
        }
        isPair = isPair || count[ranks[i]] == 2;
    }
    if (isPair) {
        return "Pair";
    }
    return "High Card";
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2348. 全 0 子数组的数目](https://leetcode.cn/problems/number-of-zero-filled-subarrays){#2348}

{{< tabs "2348" >}}

{{% tab "python" %}}
```python
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = cnt = 0
        for x in nums:
            if x == 0:
                cnt += 1
                ans += cnt
            else:
                cnt = 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans = 0;
        int cnt = 0;
        for (int x : nums) {
            if (x == 0) {
                ans += ++cnt;
            } else {
                cnt = 0;
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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;
        for (int x : nums) {
            if (x == 0) {
                ans += ++cnt;
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func zeroFilledSubarray(nums []int) (ans int64) {
	cnt := 0
	for _, x := range nums {
		if x == 0 {
			cnt++
			ans += int64(cnt)
		} else {
			cnt = 0
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function zeroFilledSubarray(nums: number[]): number {
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (!x) {
            ans += ++cnt;
        } else {
            cnt = 0;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut cnt: i64 = 0;
        for x in nums {
            if x == 0 {
                cnt += 1;
                ans += cnt;
            } else {
                cnt = 0;
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，返回全部为&nbsp;<code>0</code>&nbsp;的&nbsp;<strong>子数组</strong>&nbsp;数目。</p>

<p><strong>子数组</strong>&nbsp;是一个数组中一段连续非空元素组成的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,3,0,0,2,0,0,4]
<b>输出：</b>6
<b>解释：</b>
子数组 [0] 出现了 4 次。
子数组 [0,0] 出现了 2 次。
不存在长度大于 2 的全 0 子数组，所以我们返回 6 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [0,0,0,2,0,0]
<b>输出：</b>9
<strong>解释：
</strong>子数组 [0] 出现了 5 次。
子数组 [0,0] 出现了 3 次。
子数组 [0,0,0] 出现了 1 次。
不存在长度大于 3 的全 0 子数组，所以我们返回 9 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [2,10,2019]
<b>输出：</b>0
<b>解释：</b>没有全 0 子数组，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们遍历数组 $\textit{nums}$，用变量 $\textit{cnt}$ 记录当前连续的 $0$ 的个数。那么对于当前遍历到的元素 $x$，如果 $x$ 为 $0$，则 $\textit{cnt}$ 自增 $1$，以当前 $x$ 为结尾的全 $0$ 子数组的个数为 $\textit{cnt}$，将其累加到答案中。否则，我们将 $\textit{cnt}$ 置为 $0$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

相似题目：

-   [413. 等差数列划分](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0413.Arithmetic%20Slices/README.md)
-   [1513. 仅含 1 的子串数](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1513.Number%20of%20Substrings%20With%20Only%201s/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = cnt = 0
        for x in nums:
            if x == 0:
                cnt += 1
                ans += cnt
            else:
                cnt = 0
        return ans
```

#### Java

```java
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans = 0;
        int cnt = 0;
        for (int x : nums) {
            if (x == 0) {
                ans += ++cnt;
            } else {
                cnt = 0;
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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;
        for (int x : nums) {
            if (x == 0) {
                ans += ++cnt;
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func zeroFilledSubarray(nums []int) (ans int64) {
	cnt := 0
	for _, x := range nums {
		if x == 0 {
			cnt++
			ans += int64(cnt)
		} else {
			cnt = 0
		}
	}
	return
}
```

#### TypeScript

```ts
function zeroFilledSubarray(nums: number[]): number {
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (!x) {
            ans += ++cnt;
        } else {
            cnt = 0;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut cnt: i64 = 0;
        for x in nums {
            if x == 0 {
                cnt += 1;
                ans += cnt;
            } else {
                cnt = 0;
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

# [2349. 设计数字容器系统](https://leetcode.cn/problems/design-a-number-container-system){#2349}

{{< tabs "2349" >}}

{{% tab "python" %}}
```python
class NumberContainers:

    def __init__(self):
        self.d = {}
        self.g = defaultdict(SortedSet)

    def change(self, index: int, number: int) -> None:
        if index in self.d:
            old_number = self.d[index]
            self.g[old_number].remove(index)
        self.d[index] = number
        self.g[number].add(index)

    def find(self, number: int) -> int:
        ids = self.g[number]
        return ids[0] if ids else -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class NumberContainers {
    private Map<Integer, Integer> d = new HashMap<>();
    private Map<Integer, TreeSet<Integer>> g = new HashMap<>();

    public NumberContainers() {
    }

    public void change(int index, int number) {
        if (d.containsKey(index)) {
            int oldNumber = d.get(index);
            g.get(oldNumber).remove(index);
        }
        d.put(index, number);
        g.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }

    public int find(int number) {
        var ids = g.get(number);
        return ids == null || ids.isEmpty() ? -1 : ids.first();
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class NumberContainers {
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (d.contains(index)) {
            int oldNumber = d[index];
            g[oldNumber].erase(index);
            if (g[oldNumber].empty()) {
                g.erase(oldNumber);
            }
        }
        d[index] = number;
        g[number].insert(index);
    }

    int find(int number) {
        return g.contains(number) ? *g[number].begin() : -1;
    }

private:
    unordered_map<int, int> d;
    unordered_map<int, set<int>> g;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type NumberContainers struct {
	d map[int]int
	g map[int]*redblacktree.Tree
}

func Constructor() NumberContainers {
	return NumberContainers{map[int]int{}, map[int]*redblacktree.Tree{}}
}

func (this *NumberContainers) Change(index int, number int) {
	if oldNumber, ok := this.d[index]; ok {
		this.g[oldNumber].Remove(index)
	}
	this.d[index] = number
	if _, ok := this.g[number]; !ok {
		this.g[number] = redblacktree.NewWithIntComparator()
	}
	this.g[number].Put(index, nil)
}

func (this *NumberContainers) Find(number int) int {
	if ids, ok := this.g[number]; ok && ids.Size() > 0 {
		return ids.Left().Key.(int)
	}
	return -1
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Change(index,number);
 * param_2 := obj.Find(number);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class NumberContainers {
    private d = new Map<number, number>();
    private g = new Map<number, TreeSet<number>>();
    constructor() {}

    change(index: number, number: number): void {
        if (this.d.has(index)) {
            const oldNumber = this.d.get(index)!;
            this.g.get(oldNumber)!.delete(index);
            if (!this.g.get(oldNumber)!.size()) {
                this.g.delete(oldNumber);
            }
        }
        this.d.set(index, number);
        if (!this.g.has(number)) {
            this.g.set(number, new TreeSet());
        }
        this.g.get(number)!.add(index);
    }

    find(number: number): number {
        return this.g.has(number) ? this.g.get(number)!.first()! : -1;
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashMap, BTreeSet};

struct NumberContainers {
    d: HashMap<i32, i32>,
    g: HashMap<i32, BTreeSet<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumberContainers {
    fn new() -> Self {
        Self {
            d: HashMap::new(),
            g: HashMap::new(),
        }
    }

    fn change(&mut self, index: i32, number: i32) {
        if let Some(&old_number) = self.d.get(&index) {
            if let Some(set) = self.g.get_mut(&old_number) {
                set.remove(&index);
            }
        }
        self.d.insert(index, number);
        self.g.entry(number).or_insert_with(BTreeSet::new).insert(index);
    }

    fn find(&self, number: i32) -> i32 {
        match self.g.get(&number) {
            Some(set) if !set.is_empty() => *set.iter().next().unwrap(),
            _ => -1,
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class NumberContainers {
    private Dictionary<int, int> d = new Dictionary<int, int>();
    private Dictionary<int, SortedSet<int>> g = new Dictionary<int, SortedSet<int>>();

    public NumberContainers() {
    }

    public void Change(int index, int number) {
        if (d.TryGetValue(index, out int oldNumber)) {
            g[oldNumber].Remove(index);
        }
        d[index] = number;
        if (!g.ContainsKey(number)) {
            g[number] = new SortedSet<int>();
        }
        g[number].Add(index);
    }

    public int Find(int number) {
        if (!g.ContainsKey(number) || g[number].Count == 0) {
            return -1;
        }
        return g[number].Min;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.Change(index, number);
 * int param_2 = obj.Find(number);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个数字容器系统，可以实现以下功能：</p>

<ul>
	<li>在系统中给定下标处&nbsp;<strong>插入</strong>&nbsp;或者 <strong>替换</strong>&nbsp;一个数字。</li>
	<li><strong>返回</strong>&nbsp;系统中给定数字的最小下标。</li>
</ul>

<p>请你实现一个&nbsp;<code>NumberContainers</code>&nbsp;类：</p>

<ul>
	<li><code>NumberContainers()</code>&nbsp;初始化数字容器系统。</li>
	<li><code>void change(int index, int number)</code> 在下标&nbsp;<code>index</code>&nbsp;处填入&nbsp;<code>number</code>&nbsp;。如果该下标&nbsp;<code>index</code>&nbsp;处已经有数字了，那么用 <code>number</code>&nbsp;替换该数字。</li>
	<li><code>int find(int number)</code>&nbsp;返回给定数字&nbsp;<code>number</code>&nbsp;在系统中的最小下标。如果系统中没有&nbsp;<code>number</code>&nbsp;，那么返回&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
<strong>输出：</strong>
[null, -1, null, null, null, null, 1, null, 2]

<strong>解释：</strong>
NumberContainers nc = new NumberContainers();
nc.find(10); // 没有数字 10 ，所以返回 -1 。
nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= index, number &lt;= 10<sup>9</sup></code></li>
	<li>调用&nbsp;<code>change</code> 和&nbsp;<code>find</code>&nbsp;的&nbsp;<strong>总次数</strong>&nbsp;不超过&nbsp;<code>10<sup>5</sup></code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序集合

我们用一个哈希表 $d$ 记录下标和数字的映射关系，用一个哈希表 $g$ 记录每个数字对应的下标集合，这里我们可以使用有序集合来存储下标，这样我们就可以方便地找到最小下标。

调用 `change` 方法时，我们先判断下标是否已经存在，如果存在，我们就将原来的数字从对应的下标集合中删除，然后将新的数字添加到对应的下标集合中。时间复杂度 $O(\log n)$。

调用 `find` 方法时，我们直接返回对应数字的下标集合的第一个元素即可。时间复杂度 $O(1)$。

空间复杂度 $O(n)$。其中 $n$ 为数字的个数。

<!-- tabs:start -->

#### Python3

```python
class NumberContainers:

    def __init__(self):
        self.d = {}
        self.g = defaultdict(SortedSet)

    def change(self, index: int, number: int) -> None:
        if index in self.d:
            old_number = self.d[index]
            self.g[old_number].remove(index)
        self.d[index] = number
        self.g[number].add(index)

    def find(self, number: int) -> int:
        ids = self.g[number]
        return ids[0] if ids else -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
```

#### Java

```java
class NumberContainers {
    private Map<Integer, Integer> d = new HashMap<>();
    private Map<Integer, TreeSet<Integer>> g = new HashMap<>();

    public NumberContainers() {
    }

    public void change(int index, int number) {
        if (d.containsKey(index)) {
            int oldNumber = d.get(index);
            g.get(oldNumber).remove(index);
        }
        d.put(index, number);
        g.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }

    public int find(int number) {
        var ids = g.get(number);
        return ids == null || ids.isEmpty() ? -1 : ids.first();
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
```

#### C++

```cpp
class NumberContainers {
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (d.contains(index)) {
            int oldNumber = d[index];
            g[oldNumber].erase(index);
            if (g[oldNumber].empty()) {
                g.erase(oldNumber);
            }
        }
        d[index] = number;
        g[number].insert(index);
    }

    int find(int number) {
        return g.contains(number) ? *g[number].begin() : -1;
    }

private:
    unordered_map<int, int> d;
    unordered_map<int, set<int>> g;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
```

#### Go

```go
type NumberContainers struct {
	d map[int]int
	g map[int]*redblacktree.Tree
}

func Constructor() NumberContainers {
	return NumberContainers{map[int]int{}, map[int]*redblacktree.Tree{}}
}

func (this *NumberContainers) Change(index int, number int) {
	if oldNumber, ok := this.d[index]; ok {
		this.g[oldNumber].Remove(index)
	}
	this.d[index] = number
	if _, ok := this.g[number]; !ok {
		this.g[number] = redblacktree.NewWithIntComparator()
	}
	this.g[number].Put(index, nil)
}

func (this *NumberContainers) Find(number int) int {
	if ids, ok := this.g[number]; ok && ids.Size() > 0 {
		return ids.Left().Key.(int)
	}
	return -1
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Change(index,number);
 * param_2 := obj.Find(number);
 */
```

#### TypeScript

```ts
class NumberContainers {
    private d = new Map<number, number>();
    private g = new Map<number, TreeSet<number>>();
    constructor() {}

    change(index: number, number: number): void {
        if (this.d.has(index)) {
            const oldNumber = this.d.get(index)!;
            this.g.get(oldNumber)!.delete(index);
            if (!this.g.get(oldNumber)!.size()) {
                this.g.delete(oldNumber);
            }
        }
        this.d.set(index, number);
        if (!this.g.has(number)) {
            this.g.set(number, new TreeSet());
        }
        this.g.get(number)!.add(index);
    }

    find(number: number): number {
        return this.g.has(number) ? this.g.get(number)!.first()! : -1;
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
```

#### Rust

```rust
use std::collections::{HashMap, BTreeSet};

struct NumberContainers {
    d: HashMap<i32, i32>,
    g: HashMap<i32, BTreeSet<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumberContainers {
    fn new() -> Self {
        Self {
            d: HashMap::new(),
            g: HashMap::new(),
        }
    }

    fn change(&mut self, index: i32, number: i32) {
        if let Some(&old_number) = self.d.get(&index) {
            if let Some(set) = self.g.get_mut(&old_number) {
                set.remove(&index);
            }
        }
        self.d.insert(index, number);
        self.g.entry(number).or_insert_with(BTreeSet::new).insert(index);
    }

    fn find(&self, number: i32) -> i32 {
        match self.g.get(&number) {
            Some(set) if !set.is_empty() => *set.iter().next().unwrap(),
            _ => -1,
        }
    }
}
```

#### C#

```cs
public class NumberContainers {
    private Dictionary<int, int> d = new Dictionary<int, int>();
    private Dictionary<int, SortedSet<int>> g = new Dictionary<int, SortedSet<int>>();

    public NumberContainers() {
    }

    public void Change(int index, int number) {
        if (d.TryGetValue(index, out int oldNumber)) {
            g[oldNumber].Remove(index);
        }
        d[index] = number;
        if (!g.ContainsKey(number)) {
            g[number] = new SortedSet<int>();
        }
        g[number].Add(index);
    }

    public int Find(int number) {
        if (!g.ContainsKey(number) || g[number].Count == 0) {
            return -1;
        }
        return g[number].Min;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.Change(index, number);
 * int param_2 = obj.Find(number);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
