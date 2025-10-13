---
title: "2160_拆分数位后四位数字的最小和"
date: 2025-10-08T18:39:03+08:00
weight: 7
tags: [动态规划, 双指针, 哈希函数, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数组, 枚举, 模拟, 滚动哈希, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2160_拆分数位后四位数字的最小和](#2160)
#### [贪心](#2160)
#### [数学](#2160)
#### [排序](#2160)
### [2161_根据给定数字划分数组](#2161)
#### [数组](#2161)
#### [双指针](#2161)
#### [模拟](#2161)
### [2162_设置时间的最少代价](#2162)
#### [数学](#2162)
#### [枚举](#2162)
### [2163_删除元素后和的最小差值](#2163)
#### [数组](#2163)
#### [动态规划](#2163)
#### [堆（优先队列）](#2163)
### [2164_对奇偶下标分别排序](#2164)
#### [数组](#2164)
#### [排序](#2164)
### [2165_重排数字的最小值](#2165)
#### [数学](#2165)
#### [排序](#2165)
### [2166_设计位集](#2166)
#### [设计](#2166)
#### [数组](#2166)
#### [哈希表](#2166)
#### [字符串](#2166)
### [2167_移除所有载有违禁货物车厢所需的最少时间](#2167)
#### [字符串](#2167)
#### [动态规划](#2167)
### [2168_每个数字的频率都相同的独特子字符串的数量 🔒](#2168)
#### [哈希表](#2168)
#### [字符串](#2168)
#### [计数](#2168)
#### [哈希函数](#2168)
#### [滚动哈希](#2168)
### [2169_得到 0 的操作数](#2169)
#### [数学](#2169)
#### [模拟](#2169)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2160_拆分数位后四位数字的最小和
___
#### 贪心
___
#### 数学
___
#### 排序
---
### 2161_根据给定数字划分数组
___
#### 数组
___
#### 双指针
___
#### 模拟
---
### 2162_设置时间的最少代价
___
#### 数学
___
#### 枚举
---
### 2163_删除元素后和的最小差值
___
#### 数组
___
#### 动态规划
___
#### 堆（优先队列）
---
### 2164_对奇偶下标分别排序
___
#### 数组
___
#### 排序
---
### 2165_重排数字的最小值
___
#### 数学
___
#### 排序
---
### 2166_设计位集
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 2167_移除所有载有违禁货物车厢所需的最少时间
___
#### 字符串
___
#### 动态规划
---
### 2168_每个数字的频率都相同的独特子字符串的数量 🔒
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 哈希函数
___
#### 滚动哈希
---
### 2169_得到 0 的操作数
___
#### 数学
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 双指针 | 哈希函数 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数组 |
| 枚举 | 模拟 | 滚动哈希 |
| 计数 | 设计 | 贪心 |

# [2160. 拆分数位后四位数字的最小和](https://leetcode.cn/problems/minimum-sum-of-four-digit-number-after-splitting-digits){#2160}

{{< tabs "2160" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSum(self, num: int) -> int:
        nums = []
        while num:
            nums.append(num % 10)
            num //= 10
        nums.sort()
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSum(int num) {
        int[] nums = new int[4];
        for (int i = 0; num != 0; ++i) {
            nums[i] = num % 10;
            num /= 10;
        }
        Arrays.sort(nums);
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        while (num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSum(num int) int {
	var nums []int
	for num > 0 {
		nums = append(nums, num%10)
		num /= 10
	}
	sort.Ints(nums)
	return 10*(nums[0]+nums[1]) + nums[2] + nums[3]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSum(num: number): number {
    const nums = new Array(4).fill(0);
    for (let i = 0; i < 4; i++) {
        nums[i] = num % 10;
        num = Math.floor(num / 10);
    }
    nums.sort((a, b) => a - b);
    return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_sum(mut num: i32) -> i32 {
        let mut nums = [0; 4];
        for i in 0..4 {
            nums[i] = num % 10;
            num /= 10;
        }
        nums.sort();
        10 * (nums[0] + nums[1]) + nums[2] + nums[3]
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int minimumSum(int num) {
    int nums[4] = {0};
    for (int i = 0; i < 4; i++) {
        nums[i] = num % 10;
        num /= 10;
    }
    qsort(nums, 4, sizeof(int), cmp);
    return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个四位&nbsp;<strong>正</strong>&nbsp;整数&nbsp;<code>num</code>&nbsp;。请你使用 <code>num</code>&nbsp;中的 <strong>数位</strong> ，将&nbsp;<code>num</code>&nbsp;拆成两个新的整数&nbsp;<code>new1</code>&nbsp;和&nbsp;<code>new2</code>&nbsp;。<code>new1</code> 和&nbsp;<code>new2</code>&nbsp;中可以有&nbsp;<strong>前导 0</strong>&nbsp;，且&nbsp;<code>num</code>&nbsp;中 <strong>所有</strong>&nbsp;数位都必须使用。</p>

<ul>
	<li>比方说，给你&nbsp;<code>num = 2932</code>&nbsp;，你拥有的数位包括：两个&nbsp;<code>2</code>&nbsp;，一个&nbsp;<code>9</code>&nbsp;和一个&nbsp;<code>3</code>&nbsp;。一些可能的&nbsp;<code>[new1, new2]</code>&nbsp;数对为&nbsp;<code>[22, 93]</code>，<code>[23, 92]</code>，<code>[223, 9]</code> 和&nbsp;<code>[2, 329]</code>&nbsp;。</li>
</ul>

<p>请你返回可以得到的&nbsp;<code>new1</code>&nbsp;和 <code>new2</code>&nbsp;的 <strong>最小</strong>&nbsp;和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>num = 2932
<b>输出：</b>52
<b>解释：</b>可行的 [new1, new2] 数对为 [29, 23] ，[223, 9] 等等。
最小和为数对 [29, 23] 的和：29 + 23 = 52 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>num = 4009
<b>输出：</b>13
<b>解释：</b>可行的 [new1, new2] 数对为 [0, 49] ，[490, 0] 等等。
最小和为数对 [4, 9] 的和：4 + 9 = 13 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1000 &lt;= num &lt;= 9999</code></li>
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
    def minimumSum(self, num: int) -> int:
        nums = []
        while num:
            nums.append(num % 10)
            num //= 10
        nums.sort()
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3]
```

#### Java

```java
class Solution {
    public int minimumSum(int num) {
        int[] nums = new int[4];
        for (int i = 0; num != 0; ++i) {
            nums[i] = num % 10;
            num /= 10;
        }
        Arrays.sort(nums);
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        while (num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
    }
};
```

#### Go

```go
func minimumSum(num int) int {
	var nums []int
	for num > 0 {
		nums = append(nums, num%10)
		num /= 10
	}
	sort.Ints(nums)
	return 10*(nums[0]+nums[1]) + nums[2] + nums[3]
}
```

#### TypeScript

```ts
function minimumSum(num: number): number {
    const nums = new Array(4).fill(0);
    for (let i = 0; i < 4; i++) {
        nums[i] = num % 10;
        num = Math.floor(num / 10);
    }
    nums.sort((a, b) => a - b);
    return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_sum(mut num: i32) -> i32 {
        let mut nums = [0; 4];
        for i in 0..4 {
            nums[i] = num % 10;
            num /= 10;
        }
        nums.sort();
        10 * (nums[0] + nums[1]) + nums[2] + nums[3]
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int minimumSum(int num) {
    int nums[4] = {0};
    for (int i = 0; i < 4; i++) {
        nums[i] = num % 10;
        num /= 10;
    }
    qsort(nums, 4, sizeof(int), cmp);
    return 10 * (nums[0] + nums[1]) + nums[2] + nums[3];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2161. 根据给定数字划分数组](https://leetcode.cn/problems/partition-array-according-to-given-pivot){#2161}

{{< tabs "2161" >}}

{{% tab "python" %}}
```python
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        a, b, c = [], [], []
        for x in nums:
            if x < pivot:
                a.append(x)
            elif x == pivot:
                b.append(x)
            else:
                c.append(x)
        return a + b + c
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] ans = new int[n];
        int k = 0;
        for (int x : nums) {
            if (x < pivot) {
                ans[k++] = x;
            }
        }
        for (int x : nums) {
            if (x == pivot) {
                ans[k++] = x;
            }
        }
        for (int x : nums) {
            if (x > pivot) {
                ans[k++] = x;
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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for (int& x : nums) {
            if (x < pivot) {
                ans.push_back(x);
            }
        }
        for (int& x : nums) {
            if (x == pivot) {
                ans.push_back(x);
            }
        }
        for (int& x : nums) {
            if (x > pivot) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pivotArray(nums []int, pivot int) []int {
	var ans []int
	for _, x := range nums {
		if x < pivot {
			ans = append(ans, x)
		}
	}
	for _, x := range nums {
		if x == pivot {
			ans = append(ans, x)
		}
	}
	for _, x := range nums {
		if x > pivot {
			ans = append(ans, x)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pivotArray(nums: number[], pivot: number): number[] {
    const n = nums.length;
    const res = Array(n).fill(pivot);

    for (let i = 0, l = 0, j = n - 1, r = n - 1; i < n; i++, j--) {
        if (nums[i] < pivot) res[l++] = nums[i];
        if (nums[j] > pivot) res[r--] = nums[j];
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function pivotArray(nums, pivot) {
    const n = nums.length;
    const res = Array(n).fill(pivot);

    for (let i = 0, l = 0, j = n - 1, r = n - 1; i < n; i++, j--) {
        if (nums[i] < pivot) res[l++] = nums[i];
        if (nums[j] > pivot) res[r--] = nums[j];
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>pivot</code>&nbsp;。请你将&nbsp;<code>nums</code>&nbsp;重新排列，使得以下条件均成立：</p>

<ul>
	<li>所有小于&nbsp;<code>pivot</code>&nbsp;的元素都出现在所有大于&nbsp;<code>pivot</code>&nbsp;的元素&nbsp;<strong>之前</strong>&nbsp;。</li>
	<li>所有等于&nbsp;<code>pivot</code>&nbsp;的元素都出现在小于和大于 <code>pivot</code>&nbsp;的元素 <strong>中间</strong>&nbsp;。</li>
	<li>小于 <code>pivot</code>&nbsp;的元素之间和大于 <code>pivot</code>&nbsp;的元素之间的 <strong>相对顺序</strong>&nbsp;不发生改变。
	<ul>
		<li>更正式的，考虑每一对&nbsp;<code>p<sub>i</sub></code>，<code>p<sub>j</sub></code>&nbsp;，<code>p<sub>i</sub></code>&nbsp;是初始时位置 <code>i</code>&nbsp;元素的新位置，<code>p<sub>j</sub></code>&nbsp;是初始时位置&nbsp;<code>j</code>&nbsp;元素的新位置。如果&nbsp;<code>i &lt; j</code> 且两个元素&nbsp;<strong>都</strong>&nbsp;小于（或大于）<code>pivot</code>，那么&nbsp;<code>p<sub>i</sub> &lt; p<sub>j</sub></code>&nbsp;。</li>
	</ul>
	</li>
</ul>

<p>请你返回重新排列 <code>nums</code>&nbsp;数组后的结果数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [9,12,5,10,14,3,10], pivot = 10
<b>输出：</b>[9,5,3,10,10,12,14]
<b>解释：</b>
元素 9 ，5 和 3 小于 pivot ，所以它们在数组的最左边。
元素 12 和 14 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [9, 5, 3] 和 [12, 14] ，它们在结果数组中的相对顺序需要保留。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [-3,4,3,2], pivot = 2
<b>输出：</b>[-3,2,4,3]
<b>解释：</b>
元素 -3 小于 pivot ，所以在数组的最左边。
元素 4 和 3 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [-3] 和 [4, 3] ，它们在结果数组中的相对顺序需要保留。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>pivot</code>&nbsp;等于&nbsp;<code>nums</code>&nbsp;中的一个元素。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以遍历数组 $\textit{nums}$，按顺序找出所有小于 $\textit{pivot}$ 的元素，所有等于 $\textit{pivot}$ 的元素，以及所有大于 $\textit{pivot}$ 的元素，然后将它们按照题目要求的顺序拼接起来。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        a, b, c = [], [], []
        for x in nums:
            if x < pivot:
                a.append(x)
            elif x == pivot:
                b.append(x)
            else:
                c.append(x)
        return a + b + c
```

#### Java

```java
class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] ans = new int[n];
        int k = 0;
        for (int x : nums) {
            if (x < pivot) {
                ans[k++] = x;
            }
        }
        for (int x : nums) {
            if (x == pivot) {
                ans[k++] = x;
            }
        }
        for (int x : nums) {
            if (x > pivot) {
                ans[k++] = x;
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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for (int& x : nums) {
            if (x < pivot) {
                ans.push_back(x);
            }
        }
        for (int& x : nums) {
            if (x == pivot) {
                ans.push_back(x);
            }
        }
        for (int& x : nums) {
            if (x > pivot) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func pivotArray(nums []int, pivot int) []int {
	var ans []int
	for _, x := range nums {
		if x < pivot {
			ans = append(ans, x)
		}
	}
	for _, x := range nums {
		if x == pivot {
			ans = append(ans, x)
		}
	}
	for _, x := range nums {
		if x > pivot {
			ans = append(ans, x)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function pivotArray(nums: number[], pivot: number): number[] {
    const ans: number[] = [];
    for (const x of nums) {
        if (x < pivot) {
            ans.push(x);
        }
    }
        if (x === pivot) {
            ans.push(x);
        }
    }
    for (const x of nums) {
        if (x > pivot) {
            ans.push(x);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

<!-- tabs:start -->

#### TypeScript

```ts
function pivotArray(nums: number[], pivot: number): number[] {
    const n = nums.length;
    const res = Array(n).fill(pivot);

    for (let i = 0, l = 0, j = n - 1, r = n - 1; i < n; i++, j--) {
        if (nums[i] < pivot) res[l++] = nums[i];
        if (nums[j] > pivot) res[r--] = nums[j];
    }

    return res;
}
```

#### JavaScript

```js
function pivotArray(nums, pivot) {
    const n = nums.length;
    const res = Array(n).fill(pivot);

    for (let i = 0, l = 0, j = n - 1, r = n - 1; i < n; i++, j--) {
        if (nums[i] < pivot) res[l++] = nums[i];
        if (nums[j] > pivot) res[r--] = nums[j];
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2162. 设置时间的最少代价](https://leetcode.cn/problems/minimum-cost-to-set-cooking-time){#2162}

{{< tabs "2162" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCostSetTime(
        self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int
    ) -> int:
        def f(m, s):
            if not 0 <= m < 100 or not 0 <= s < 100:
                return inf
            arr = [m // 10, m % 10, s // 10, s % 10]
            i = 0
            while i < 4 and arr[i] == 0:
                i += 1
            t = 0
            prev = startAt
            for v in arr[i:]:
                if v != prev:
                    t += moveCost
                t += pushCost
                prev = v
            return t

        m, s = divmod(targetSeconds, 60)
        ans = min(f(m, s), f(m - 1, s + 60))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = targetSeconds / 60;
        int s = targetSeconds % 60;
        return Math.min(
            f(m, s, startAt, moveCost, pushCost), f(m - 1, s + 60, startAt, moveCost, pushCost));
    }

    private int f(int m, int s, int prev, int moveCost, int pushCost) {
        if (m < 0 || m > 99 || s < 0 || s > 99) {
            return Integer.MAX_VALUE;
        }
        int[] arr = new int[] {m / 10, m % 10, s / 10, s % 10};
        int i = 0;
        for (; i < 4 && arr[i] == 0; ++i)
            ;
        int t = 0;
        for (; i < 4; ++i) {
            if (arr[i] != prev) {
                t += moveCost;
            }
            t += pushCost;
            prev = arr[i];
        }
        return t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = targetSeconds / 60, s = targetSeconds % 60;
        return min(f(m, s, startAt, moveCost, pushCost), f(m - 1, s + 60, startAt, moveCost, pushCost));
    }

    int f(int m, int s, int prev, int moveCost, int pushCost) {
        if (m < 0 || m > 99 || s < 0 || s > 99) return INT_MAX;
        vector<int> arr = {m / 10, m % 10, s / 10, s % 10};
        int i = 0;
        for (; i < 4 && arr[i] == 0; ++i)
            ;
        int t = 0;
        for (; i < 4; ++i) {
            if (arr[i] != prev) t += moveCost;
            t += pushCost;
            prev = arr[i];
        }
        return t;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCostSetTime(startAt int, moveCost int, pushCost int, targetSeconds int) int {
	m, s := targetSeconds/60, targetSeconds%60
	f := func(m, s int) int {
		if m < 0 || m > 99 || s < 0 || s > 99 {
			return 0x3f3f3f3f
		}
		arr := []int{m / 10, m % 10, s / 10, s % 10}
		i := 0
		for ; i < 4 && arr[i] == 0; i++ {
		}
		t := 0
		prev := startAt
		for ; i < 4; i++ {
			if arr[i] != prev {
				t += moveCost
			}
			t += pushCost
			prev = arr[i]
		}
		return t
	}
	return min(f(m, s), f(m-1, s+60))
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>常见的微波炉可以设置加热时间，且加热时间满足以下条件：</p>

<ul>
	<li>至少为 <code>1</code>&nbsp;秒钟。</li>
	<li>至多为&nbsp;<code>99</code>&nbsp;分&nbsp;<code>99</code>&nbsp;秒。</li>
</ul>

<p>你可以 <strong>最多</strong>&nbsp;输入&nbsp;<strong>4 个数字</strong>&nbsp;来设置加热时间。如果你输入的位数不足 4 位，微波炉会自动加 <strong>前缀</strong>&nbsp;<strong>0</strong>&nbsp;来补足 4 位。微波炉会将设置好的四位数中，<strong>前</strong>&nbsp;两位当作分钟数，<strong>后</strong>&nbsp;两位当作秒数。它们所表示的总时间就是加热时间。比方说：</p>

<ul>
	<li>你输入&nbsp;<code>9</code> <code>5</code> <code>4</code>&nbsp;（三个数字），被自动补足为&nbsp;<code>0954</code>&nbsp;，并表示&nbsp;<code>9</code>&nbsp;分&nbsp;<code>54</code>&nbsp;秒。</li>
	<li>你输入&nbsp;<code>0</code> <code>0</code> <code>0</code> <code>8</code>&nbsp;（四个数字），表示&nbsp;<code>0</code>&nbsp;分&nbsp;<code>8</code>&nbsp;秒。</li>
	<li>你输入&nbsp;<code>8</code> <code>0</code> <code>9</code> <code>0</code>&nbsp;，表示&nbsp;<code>80</code>&nbsp;分&nbsp;<code>90</code>&nbsp;秒。</li>
	<li>你输入&nbsp;<code>8</code> <code>1</code> <code>3</code> <code>0</code>&nbsp;，表示&nbsp;<code>81</code>&nbsp;分&nbsp;<code>30</code>&nbsp;秒。</li>
</ul>

<p>给你整数&nbsp;<code>startAt</code>&nbsp;，<code>moveCost</code>&nbsp;，<code>pushCost</code>&nbsp;和&nbsp;<code>targetSeconds</code>&nbsp;。<strong>一开始</strong>，你的手指在数字&nbsp;<code>startAt</code>&nbsp;处。将手指移到<strong>&nbsp;任何其他数字</strong>&nbsp;，需要花费&nbsp;<code>moveCost</code>&nbsp;的单位代价。<strong>每</strong>&nbsp;输入你手指所在位置的数字一次，需要花费&nbsp;<code>pushCost</code>&nbsp;的单位代价。</p>

<p>要设置&nbsp;<code>targetSeconds</code>&nbsp;秒的加热时间，可能会有多种设置方法。你想要知道这些方法中，总代价最小为多少。</p>

<p>请你能返回设置&nbsp;<code>targetSeconds</code>&nbsp;秒钟加热时间需要花费的最少代价。</p>

<p>请记住，虽然微波炉的秒数最多可以设置到 <code>99</code>&nbsp;秒，但一分钟等于&nbsp;<code>60</code>&nbsp;秒。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2162.Minimum%20Cost%20to%20Set%20Cooking%20Time/images/1.png" style="width: 506px; height: 210px;"></p>

<pre><b>输入：</b>startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
<b>输出：</b>6
<b>解释：</b>以下为设置加热时间的所有方法。
- 1 0 0 0 ，表示 10 分 0 秒。
&nbsp; 手指一开始就在数字 1 处，输入 1 （代价为 1），移到 0 处（代价为 2），输入 0（代价为 1），输入 0（代价为 1），输入 0（代价为 1）。
&nbsp; 总代价为：1 + 2 + 1 + 1 + 1 = 6 。这是所有方案中的最小代价。
- 0 9 6 0，表示 9 分 60 秒。它也表示 600 秒。
&nbsp; 手指移到 0 处（代价为 2），输入 0 （代价为 1），移到 9 处（代价为 2），输入 9（代价为 1），移到 6 处（代价为 2），输入 6（代价为 1），移到 0 处（代价为 2），输入 0（代价为 1）。
&nbsp; 总代价为：2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 = 12 。
- 9 6 0，微波炉自动补全为 0960 ，表示 9 分 60 秒。
&nbsp; 手指移到 9 处（代价为 2），输入 9 （代价为 1），移到 6 处（代价为 2），输入 6（代价为 1），移到 0 处（代价为 2），输入 0（代价为 1）。
&nbsp; 总代价为：2 + 1 + 2 + 1 + 2 + 1 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2162.Minimum%20Cost%20to%20Set%20Cooking%20Time/images/2.png" style="width: 505px; height: 73px;"></p>

<pre><b>输入：</b>startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76
<b>输出：</b>6
<b>解释：</b>最优方案为输入两个数字 7 6，表示 76 秒。
手指移到 7 处（代价为 1），输入 7 （代价为 2），移到 6 处（代价为 1），输入 6（代价为 2）。总代价为：1 + 2 + 1 + 2 = 6
其他可行方案为 0076 ，076 ，0116 和 116 ，但是它们的代价都比 6 大。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= startAt &lt;= 9</code></li>
	<li><code>1 &lt;= moveCost, pushCost &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= targetSeconds &lt;= 6039</code></li>
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
    def minCostSetTime(
        self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int
    ) -> int:
        def f(m, s):
            if not 0 <= m < 100 or not 0 <= s < 100:
                return inf
            arr = [m // 10, m % 10, s // 10, s % 10]
            i = 0
            while i < 4 and arr[i] == 0:
                i += 1
            t = 0
            prev = startAt
            for v in arr[i:]:
                if v != prev:
                    t += moveCost
                t += pushCost
                prev = v
            return t

        m, s = divmod(targetSeconds, 60)
        ans = min(f(m, s), f(m - 1, s + 60))
        return ans
```

#### Java

```java
class Solution {
    public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = targetSeconds / 60;
        int s = targetSeconds % 60;
        return Math.min(
            f(m, s, startAt, moveCost, pushCost), f(m - 1, s + 60, startAt, moveCost, pushCost));
    }

    private int f(int m, int s, int prev, int moveCost, int pushCost) {
        if (m < 0 || m > 99 || s < 0 || s > 99) {
            return Integer.MAX_VALUE;
        }
        int[] arr = new int[] {m / 10, m % 10, s / 10, s % 10};
        int i = 0;
        for (; i < 4 && arr[i] == 0; ++i)
            ;
        int t = 0;
        for (; i < 4; ++i) {
            if (arr[i] != prev) {
                t += moveCost;
            }
            t += pushCost;
            prev = arr[i];
        }
        return t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = targetSeconds / 60, s = targetSeconds % 60;
        return min(f(m, s, startAt, moveCost, pushCost), f(m - 1, s + 60, startAt, moveCost, pushCost));
    }

    int f(int m, int s, int prev, int moveCost, int pushCost) {
        if (m < 0 || m > 99 || s < 0 || s > 99) return INT_MAX;
        vector<int> arr = {m / 10, m % 10, s / 10, s % 10};
        int i = 0;
        for (; i < 4 && arr[i] == 0; ++i)
            ;
        int t = 0;
        for (; i < 4; ++i) {
            if (arr[i] != prev) t += moveCost;
            t += pushCost;
            prev = arr[i];
        }
        return t;
    }
};
```

#### Go

```go
func minCostSetTime(startAt int, moveCost int, pushCost int, targetSeconds int) int {
	m, s := targetSeconds/60, targetSeconds%60
	f := func(m, s int) int {
		if m < 0 || m > 99 || s < 0 || s > 99 {
			return 0x3f3f3f3f
		}
		arr := []int{m / 10, m % 10, s / 10, s % 10}
		i := 0
		for ; i < 4 && arr[i] == 0; i++ {
		}
		t := 0
		prev := startAt
		for ; i < 4; i++ {
			if arr[i] != prev {
				t += moveCost
			}
			t += pushCost
			prev = arr[i]
		}
		return t
	}
	return min(f(m, s), f(m-1, s+60))
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2163. 删除元素后和的最小差值](https://leetcode.cn/problems/minimum-difference-in-sums-after-removal-of-elements){#2163}

{{< tabs "2163" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        m = len(nums)
        n = m // 3

        s = 0
        pre = [0] * (m + 1)
        q1 = []
        for i, x in enumerate(nums[: n * 2], 1):
            s += x
            heappush(q1, -x)
            if len(q1) > n:
                s -= -heappop(q1)
            pre[i] = s

        s = 0
        suf = [0] * (m + 1)
        q2 = []
        for i in range(m, n, -1):
            x = nums[i - 1]
            s += x
            heappush(q2, x)
            if len(q2) > n:
                s -= heappop(q2)
            suf[i] = s

        return min(pre[i] - suf[i + 1] for i in range(n, n * 2 + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumDifference(int[] nums) {
        int m = nums.length;
        int n = m / 3;
        long s = 0;
        long[] pre = new long[m + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 1; i <= n * 2; ++i) {
            int x = nums[i - 1];
            s += x;
            pq.offer(x);
            if (pq.size() > n) {
                s -= pq.poll();
            }
            pre[i] = s;
        }
        s = 0;
        long[] suf = new long[m + 1];
        pq = new PriorityQueue<>();
        for (int i = m; i > n; --i) {
            int x = nums[i - 1];
            s += x;
            pq.offer(x);
            if (pq.size() > n) {
                s -= pq.poll();
            }
            suf[i] = s;
        }
        long ans = 1L << 60;
        for (int i = n; i <= n * 2; ++i) {
            ans = Math.min(ans, pre[i] - suf[i + 1]);
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
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;

        using ll = long long;
        ll s = 0;
        ll pre[m + 1];
        priority_queue<int> q1;
        for (int i = 1; i <= n * 2; ++i) {
            int x = nums[i - 1];
            s += x;
            q1.push(x);
            if (q1.size() > n) {
                s -= q1.top();
                q1.pop();
            }
            pre[i] = s;
        }
        s = 0;
        ll suf[m + 1];
        priority_queue<int, vector<int>, greater<int>> q2;
        for (int i = m; i > n; --i) {
            int x = nums[i - 1];
            s += x;
            q2.push(x);
            if (q2.size() > n) {
                s -= q2.top();
                q2.pop();
            }
            suf[i] = s;
        }
        ll ans = 1e18;
        for (int i = n; i <= n * 2; ++i) {
            ans = min(ans, pre[i] - suf[i + 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDifference(nums []int) int64 {
	m := len(nums)
	n := m / 3
	s := 0
	pre := make([]int, m+1)
	q1 := hp{}
	for i := 1; i <= n*2; i++ {
		x := nums[i-1]
		s += x
		heap.Push(&q1, -x)
		if q1.Len() > n {
			s -= -heap.Pop(&q1).(int)
		}
		pre[i] = s
	}
	s = 0
	suf := make([]int, m+1)
	q2 := hp{}
	for i := m; i > n; i-- {
		x := nums[i-1]
		s += x
		heap.Push(&q2, x)
		if q2.Len() > n {
			s -= heap.Pop(&q2).(int)
		}
		suf[i] = s
	}
	ans := int64(1e18)
	for i := n; i <= n*2; i++ {
		ans = min(ans, int64(pre[i]-suf[i+1]))
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDifference(nums: number[]): number {
    const m = nums.length;
    const n = Math.floor(m / 3);
    let s = 0;
    const pre: number[] = Array(m + 1);
    const q1 = new MaxPriorityQueue<number>();
    for (let i = 1; i <= n * 2; ++i) {
        const x = nums[i - 1];
        s += x;
        q1.enqueue(x);
        if (q1.size() > n) {
            s -= q1.dequeue();
        }
        pre[i] = s;
    }
    s = 0;
    const suf: number[] = Array(m + 1);
    const q2 = new MinPriorityQueue<number>();
    for (let i = m; i > n; --i) {
        const x = nums[i - 1];
        s += x;
        q2.enqueue(x);
        if (q2.size() > n) {
            s -= q2.dequeue();
        }
        suf[i] = s;
    }
    let ans = Number.MAX_SAFE_INTEGER;
    for (let i = n; i <= n * 2; ++i) {
        ans = Math.min(ans, pre[i] - suf[i + 1]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn minimum_difference(nums: Vec<i32>) -> i64 {
        let m = nums.len();
        let n = m / 3;
        let mut s = 0i64;
        let mut pre = vec![0i64; m + 1];
        let mut pq = BinaryHeap::new(); // max-heap

        for i in 1..=2 * n {
            let x = nums[i - 1] as i64;
            s += x;
            pq.push(x);
            if pq.len() > n {
                if let Some(top) = pq.pop() {
                    s -= top;
                }
            }
            pre[i] = s;
        }

        s = 0;
        let mut suf = vec![0i64; m + 1];
        let mut pq = BinaryHeap::new();

        for i in (n + 1..=m).rev() {
            let x = nums[i - 1] as i64;
            s += x;
            pq.push(Reverse(x));
            if pq.len() > n {
                if let Some(Reverse(top)) = pq.pop() {
                    s -= top;
                }
            }
            suf[i] = s;
        }

        let mut ans = i64::MAX;
        for i in n..=2 * n {
            ans = ans.min(pre[i] - suf[i + 1]);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它包含&nbsp;<code>3 * n</code>&nbsp;个元素。</p>

<p>你可以从 <code>nums</code>&nbsp;中删除 <strong>恰好</strong>&nbsp;<code>n</code>&nbsp;个元素，剩下的 <code>2 * n</code>&nbsp;个元素将会被分成两个 <strong>相同大小</strong>&nbsp;的部分。</p>

<ul>
	<li>前面&nbsp;<code>n</code>&nbsp;个元素属于第一部分，它们的和记为&nbsp;<code>sum<sub>first</sub></code>&nbsp;。</li>
	<li>后面&nbsp;<code>n</code>&nbsp;个元素属于第二部分，它们的和记为&nbsp;<code>sum<sub>second</sub></code>&nbsp;。</li>
</ul>

<p>两部分和的 <strong>差值</strong>&nbsp;记为&nbsp;<code>sum<sub>first</sub> - sum<sub>second</sub></code>&nbsp;。</p>

<ul>
	<li>比方说，<code>sum<sub>first</sub> = 3</code> 且&nbsp;<code>sum<sub>second</sub> = 2</code>&nbsp;，它们的差值为&nbsp;<code>1</code>&nbsp;。</li>
	<li>再比方，<code>sum<sub>first</sub> = 2</code> 且&nbsp;<code>sum<sub>second</sub> = 3</code>&nbsp;，它们的差值为&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>请你返回删除 <code>n</code>&nbsp;个元素之后，剩下两部分和的 <strong>差值的最小值</strong>&nbsp;是多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,1,2]
<b>输出：</b>-1
<b>解释：</b>nums 有 3 个元素，所以 n = 1 。
所以我们需要从 nums 中删除 1 个元素，并将剩下的元素分成两部分。
- 如果我们删除 nums[0] = 3 ，数组变为 [1,2] 。两部分和的差值为 1 - 2 = -1 。
- 如果我们删除 nums[1] = 1 ，数组变为 [3,2] 。两部分和的差值为 3 - 2 = 1 。
- 如果我们删除 nums[2] = 2 ，数组变为 [3,1] 。两部分和的差值为 3 - 1 = 2 。
两部分和的最小差值为 min(-1,1,2) = -1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [7,9,5,8,1,3]
<b>输出：</b>1
<b>解释：</b>n = 2 。所以我们需要删除 2 个元素，并将剩下元素分为 2 部分。
如果我们删除元素 nums[2] = 5 和 nums[3] = 8 ，剩下元素为 [7,9,1,3] 。和的差值为 (7+9) - (1+3) = 12 。
为了得到最小差值，我们应该删除 nums[1] = 9 和 nums[4] = 1 ，剩下的元素为 [7,5,8,3] 。和的差值为 (7+5) - (8+3) = 1 。
观察可知，最优答案为 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == 3 * n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大小根堆）+ 前后缀和 + 枚举分割点

题目实际上等价于在 $nums$ 中找到一个分割点，将数组分成左右两部分，在前一部分中选取最小的 $n$ 个元素，在后一部分中选取最大的 $n$ 个元素，使得两部分和的差值最小。

我们可以用一个大根堆维护前缀中最小的 $n$ 个元素，用一个小根堆维护后缀中最大的 $n$ 个元素。我们定义 $pre[i]$ 表示在数组 $nums$ 的前 $i$ 个元素中选择最小的 $n$ 个元素的和，定义 $suf[i]$ 表示从数组第 $i$ 个元素到最后一个元素中选择最大的 $n$ 个元素的和。在维护大小根堆的过程中，更新 $pre[i]$ 和 $suf[i]$ 的值。

最后，我们在 $i \in [n, 2n]$ 的范围内枚举分割点，计算 $pre[i] - suf[i + 1]$ 的值，取最小值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        m = len(nums)
        n = m // 3

        s = 0
        pre = [0] * (m + 1)
        q1 = []
        for i, x in enumerate(nums[: n * 2], 1):
            s += x
            heappush(q1, -x)
            if len(q1) > n:
                s -= -heappop(q1)
            pre[i] = s

        s = 0
        suf = [0] * (m + 1)
        q2 = []
        for i in range(m, n, -1):
            x = nums[i - 1]
            s += x
            heappush(q2, x)
            if len(q2) > n:
                s -= heappop(q2)
            suf[i] = s

        return min(pre[i] - suf[i + 1] for i in range(n, n * 2 + 1))
```

#### Java

```java
class Solution {
    public long minimumDifference(int[] nums) {
        int m = nums.length;
        int n = m / 3;
        long s = 0;
        long[] pre = new long[m + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 1; i <= n * 2; ++i) {
            int x = nums[i - 1];
            s += x;
            pq.offer(x);
            if (pq.size() > n) {
                s -= pq.poll();
            }
            pre[i] = s;
        }
        s = 0;
        long[] suf = new long[m + 1];
        pq = new PriorityQueue<>();
        for (int i = m; i > n; --i) {
            int x = nums[i - 1];
            s += x;
            pq.offer(x);
            if (pq.size() > n) {
                s -= pq.poll();
            }
            suf[i] = s;
        }
        long ans = 1L << 60;
        for (int i = n; i <= n * 2; ++i) {
            ans = Math.min(ans, pre[i] - suf[i + 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;

        using ll = long long;
        ll s = 0;
        ll pre[m + 1];
        priority_queue<int> q1;
        for (int i = 1; i <= n * 2; ++i) {
            int x = nums[i - 1];
            s += x;
            q1.push(x);
            if (q1.size() > n) {
                s -= q1.top();
                q1.pop();
            }
            pre[i] = s;
        }
        s = 0;
        ll suf[m + 1];
        priority_queue<int, vector<int>, greater<int>> q2;
        for (int i = m; i > n; --i) {
            int x = nums[i - 1];
            s += x;
            q2.push(x);
            if (q2.size() > n) {
                s -= q2.top();
                q2.pop();
            }
            suf[i] = s;
        }
        ll ans = 1e18;
        for (int i = n; i <= n * 2; ++i) {
            ans = min(ans, pre[i] - suf[i + 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDifference(nums []int) int64 {
	m := len(nums)
	n := m / 3
	s := 0
	pre := make([]int, m+1)
	q1 := hp{}
	for i := 1; i <= n*2; i++ {
		x := nums[i-1]
		s += x
		heap.Push(&q1, -x)
		if q1.Len() > n {
			s -= -heap.Pop(&q1).(int)
		}
		pre[i] = s
	}
	s = 0
	suf := make([]int, m+1)
	q2 := hp{}
	for i := m; i > n; i-- {
		x := nums[i-1]
		s += x
		heap.Push(&q2, x)
		if q2.Len() > n {
			s -= heap.Pop(&q2).(int)
		}
		suf[i] = s
	}
	ans := int64(1e18)
	for i := n; i <= n*2; i++ {
		ans = min(ans, int64(pre[i]-suf[i+1]))
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

#### TypeScript

```ts
function minimumDifference(nums: number[]): number {
    const m = nums.length;
    const n = Math.floor(m / 3);
    let s = 0;
    const pre: number[] = Array(m + 1);
    const q1 = new MaxPriorityQueue<number>();
    for (let i = 1; i <= n * 2; ++i) {
        const x = nums[i - 1];
        s += x;
        q1.enqueue(x);
        if (q1.size() > n) {
            s -= q1.dequeue();
        }
        pre[i] = s;
    }
    s = 0;
    const suf: number[] = Array(m + 1);
    const q2 = new MinPriorityQueue<number>();
    for (let i = m; i > n; --i) {
        const x = nums[i - 1];
        s += x;
        q2.enqueue(x);
        if (q2.size() > n) {
            s -= q2.dequeue();
        }
        suf[i] = s;
    }
    let ans = Number.MAX_SAFE_INTEGER;
    for (let i = n; i <= n * 2; ++i) {
        ans = Math.min(ans, pre[i] - suf[i + 1]);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn minimum_difference(nums: Vec<i32>) -> i64 {
        let m = nums.len();
        let n = m / 3;
        let mut s = 0i64;
        let mut pre = vec![0i64; m + 1];
        let mut pq = BinaryHeap::new(); // max-heap

        for i in 1..=2 * n {
            let x = nums[i - 1] as i64;
            s += x;
            pq.push(x);
            if pq.len() > n {
                if let Some(top) = pq.pop() {
                    s -= top;
                }
            }
            pre[i] = s;
        }

        s = 0;
        let mut suf = vec![0i64; m + 1];
        let mut pq = BinaryHeap::new();

        for i in (n + 1..=m).rev() {
            let x = nums[i - 1] as i64;
            s += x;
            pq.push(Reverse(x));
            if pq.len() > n {
                if let Some(Reverse(top)) = pq.pop() {
                    s -= top;
                }
            }
            suf[i] = s;
        }

        let mut ans = i64::MAX;
        for i in n..=2 * n {
            ans = ans.min(pre[i] - suf[i + 1]);
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

# [2164. 对奇偶下标分别排序](https://leetcode.cn/problems/sort-even-and-odd-indices-independently){#2164}

{{< tabs "2164" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        a = sorted(nums[::2])
        b = sorted(nums[1::2], reverse=True)
        nums[::2] = a
        nums[1::2] = b
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortEvenOdd(int[] nums) {
        int n = nums.length;
        int[] a = new int[(n + 1) >> 1];
        int[] b = new int[n >> 1];
        for (int i = 0, j = 0; j < n >> 1; i += 2, ++j) {
            a[j] = nums[i];
            b[j] = nums[i + 1];
        }
        if (n % 2 == 1) {
            a[a.length - 1] = nums[n - 1];
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int[] ans = new int[n];
        for (int i = 0, j = 0; j < a.length; i += 2, ++j) {
            ans[i] = a[j];
        }
        for (int i = 1, j = b.length - 1; j >= 0; i += 2, --j) {
            ans[i] = b[j];
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
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        vector<int> ans(n);
        for (int i = 0, j = 0; j < a.size(); i += 2, ++j) {
            ans[i] = a[j];
        }
        for (int i = 1, j = 0; j < b.size(); i += 2, ++j) {
            ans[i] = b[j];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortEvenOdd(nums []int) []int {
	n := len(nums)
	var a []int
	var b []int
	for i, v := range nums {
		if i%2 == 0 {
			a = append(a, v)
		} else {
			b = append(b, v)
		}
	}
	ans := make([]int, n)
	sort.Ints(a)
	sort.Slice(b, func(i, j int) bool {
		return b[i] > b[j]
	})
	for i, j := 0, 0; j < len(a); i, j = i+2, j+1 {
		ans[i] = a[j]
	}
	for i, j := 1, 0; j < len(b); i, j = i+2, j+1 {
		ans[i] = b[j]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortEvenOdd(nums: number[]): number[] {
    const n = nums.length;
    const a: number[] = [];
    const b: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (i % 2 === 0) {
            a.push(nums[i]);
        } else {
            b.push(nums[i]);
        }
    }
    a.sort((x, y) => x - y);
    b.sort((x, y) => y - x);
    const ans: number[] = [];
    for (let i = 0, j = 0; j < a.length; i += 2, ++j) {
        ans[i] = a[j];
    }
    for (let i = 1, j = 0; j < b.length; i += 2, ++j) {
        ans[i] = b[j];
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。根据下述规则重排 <code>nums</code> 中的值：</p>

<ol>
	<li>按 <strong>非递增</strong> 顺序排列 <code>nums</code> <strong>奇数下标</strong> 上的所有值。

    <ul>
    	<li>举个例子，如果排序前 <code>nums = [4,<em><strong>1</strong></em>,2,<em><strong>3</strong></em>]</code> ，对奇数下标的值排序后变为 <code>[4,<em><strong>3</strong></em>,2,<em><strong>1</strong></em>]</code> 。奇数下标 <code>1</code> 和 <code>3</code> 的值按照非递增顺序重排。</li>
    </ul>
    </li>
    <li>按 <strong>非递减</strong> 顺序排列 <code>nums</code> <strong>偶数下标</strong> 上的所有值。
    <ul>
    	<li>举个例子，如果排序前 <code>nums = [<em><strong>4</strong></em>,1,<em><strong>2</strong></em>,3]</code> ，对偶数下标的值排序后变为 <code>[<em><strong>2</strong></em>,1,<em><strong>4</strong></em>,3]</code> 。偶数下标 <code>0</code> 和 <code>2</code> 的值按照非递减顺序重排。</li>
    </ul>
    </li>

</ol>

<p>返回重排 <code>nums</code> 的值之后形成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,1,2,3]
<strong>输出：</strong>[2,3,4,1]
<strong>解释：</strong>
首先，按非递增顺序重排奇数下标（1 和 3）的值。
所以，nums 从 [4,<em><strong>1</strong></em>,2,<em><strong>3</strong></em>] 变为 [4,<em><strong>3</strong></em>,2,<em><strong>1</strong></em>] 。
然后，按非递减顺序重排偶数下标（0 和 2）的值。
所以，nums 从 [<em><strong>4</strong></em>,1,<em><strong>2</strong></em>,3] 变为 [<em><strong>2</strong></em>,3,<em><strong>4</strong></em>,1] 。
因此，重排之后形成的数组是 [2,3,4,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1]
<strong>输出：</strong>[2,1]
<strong>解释：</strong>
由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
形成的结果数组是 [2,1] ，和初始数组一样。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以将奇数下标和偶数下标分别取出来，然后对奇数下标的数组进行非递增排序，对偶数下标的数组进行非递减排序，最后再将两个数组合并即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        a = sorted(nums[::2])
        b = sorted(nums[1::2], reverse=True)
        nums[::2] = a
        nums[1::2] = b
        return nums
```

#### Java

```java
class Solution {
    public int[] sortEvenOdd(int[] nums) {
        int n = nums.length;
        int[] a = new int[(n + 1) >> 1];
        int[] b = new int[n >> 1];
        for (int i = 0, j = 0; j < n >> 1; i += 2, ++j) {
            a[j] = nums[i];
            b[j] = nums[i + 1];
        }
        if (n % 2 == 1) {
            a[a.length - 1] = nums[n - 1];
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int[] ans = new int[n];
        for (int i = 0, j = 0; j < a.length; i += 2, ++j) {
            ans[i] = a[j];
        }
        for (int i = 1, j = b.length - 1; j >= 0; i += 2, --j) {
            ans[i] = b[j];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        vector<int> ans(n);
        for (int i = 0, j = 0; j < a.size(); i += 2, ++j) {
            ans[i] = a[j];
        }
        for (int i = 1, j = 0; j < b.size(); i += 2, ++j) {
            ans[i] = b[j];
        }
        return ans;
    }
};
```

#### Go

```go
func sortEvenOdd(nums []int) []int {
	n := len(nums)
	var a []int
	var b []int
	for i, v := range nums {
		if i%2 == 0 {
			a = append(a, v)
		} else {
			b = append(b, v)
		}
	}
	ans := make([]int, n)
	sort.Ints(a)
	sort.Slice(b, func(i, j int) bool {
		return b[i] > b[j]
	})
	for i, j := 0, 0; j < len(a); i, j = i+2, j+1 {
		ans[i] = a[j]
	}
	for i, j := 1, 0; j < len(b); i, j = i+2, j+1 {
		ans[i] = b[j]
	}
	return ans
}
```

#### TypeScript

```ts
function sortEvenOdd(nums: number[]): number[] {
    const n = nums.length;
    const a: number[] = [];
    const b: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (i % 2 === 0) {
            a.push(nums[i]);
        } else {
            b.push(nums[i]);
        }
    }
    a.sort((x, y) => x - y);
    b.sort((x, y) => y - x);
    const ans: number[] = [];
    for (let i = 0, j = 0; j < a.length; i += 2, ++j) {
        ans[i] = a[j];
    }
    for (let i = 1, j = 0; j < b.length; i += 2, ++j) {
        ans[i] = b[j];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2165. 重排数字的最小值](https://leetcode.cn/problems/smallest-value-of-the-rearranged-number){#2165}

{{< tabs "2165" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestNumber(self, num: int) -> int:
        neg = num < 0
        num = abs(num)
        cnt = [0] * 10
        while num:
            cnt[num % 10] += 1
            num //= 10
        ans = 0
        if neg:
            for i in reversed(range(10)):
                for _ in range(cnt[i]):
                    ans *= 10
                    ans += i
            return -ans
        if cnt[0]:
            for i in range(1, 10):
                if cnt[i]:
                    ans = i
                    cnt[i] -= 1
                    break
        for i in range(10):
            for _ in range(cnt[i]):
                ans *= 10
                ans += i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long smallestNumber(long num) {
        boolean neg = num < 0;
        num = Math.abs(num);
        int[] cnt = new int[10];
        while (num > 0) {
            ++cnt[(int) (num % 10)];
            num /= 10;
        }
        long ans = 0;
        if (neg) {
            for (int i = 9; i >= 0; --i) {
                while (cnt[i] > 0) {
                    ans = ans * 10 + i;
                    --cnt[i];
                }
            }
            return -ans;
        }
        if (cnt[0] > 0) {
            for (int i = 1; i < 10; ++i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    ans = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                --cnt[i];
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
    long long smallestNumber(long long num) {
        bool neg = num < 0;
        num = abs(num);
        int cnt[10]{};
        while (num > 0) {
            ++cnt[num % 10];
            num /= 10;
        }
        long long ans = 0;
        if (neg) {
            for (int i = 9; i >= 0; --i) {
                while (cnt[i] > 0) {
                    ans = ans * 10 + i;
                    --cnt[i];
                }
            }
            return -ans;
        }
        if (cnt[0]) {
            for (int i = 1; i < 10; ++i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    ans = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                --cnt[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestNumber(num int64) (ans int64) {
	neg := num < 0
	num = max(num, -num)
	cnt := make([]int, 10)

	for num > 0 {
		cnt[num%10]++
		num /= 10
	}

	if neg {
		for i := 9; i >= 0; i-- {
			for cnt[i] > 0 {
				ans = ans*10 + int64(i)
				cnt[i]--
			}
		}
		return -ans
	}

	if cnt[0] > 0 {
		for i := 1; i < 10; i++ {
			if cnt[i] > 0 {
				cnt[i]--
				ans = int64(i)
				break
			}
		}
	}

	for i := 0; i < 10; i++ {
		for cnt[i] > 0 {
			ans = ans*10 + int64(i)
			cnt[i]--
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestNumber(num: number): number {
    const neg = num < 0;
    num = Math.abs(num);
    const cnt = Array(10).fill(0);

    while (num > 0) {
        cnt[num % 10]++;
        num = Math.floor(num / 10);
    }

    let ans = 0;
    if (neg) {
        for (let i = 9; i >= 0; i--) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                cnt[i]--;
            }
        }
        return -ans;
    }

    if (cnt[0] > 0) {
        for (let i = 1; i < 10; i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                ans = i;
                break;
            }
        }
    }

    for (let i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
            ans = ans * 10 + i;
            cnt[i]--;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_number(num: i64) -> i64 {
        let mut neg = num < 0;
        let mut num = num.abs();
        let mut cnt = vec![0; 10];

        while num > 0 {
            cnt[(num % 10) as usize] += 1;
            num /= 10;
        }

        let mut ans = 0;
        if neg {
            for i in (0..10).rev() {
                while cnt[i] > 0 {
                    ans = ans * 10 + i as i64;
                    cnt[i] -= 1;
                }
            }
            return -ans;
        }

        if cnt[0] > 0 {
            for i in 1..10 {
                if cnt[i] > 0 {
                    cnt[i] -= 1;
                    ans = i as i64;
                    break;
                }
            }
        }

        for i in 0..10 {
            while cnt[i] > 0 {
                ans = ans * 10 + i as i64;
                cnt[i] -= 1;
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function (num) {
    const neg = num < 0;
    num = Math.abs(num);
    const cnt = Array(10).fill(0);

    while (num > 0) {
        cnt[num % 10]++;
        num = Math.floor(num / 10);
    }

    let ans = 0;
    if (neg) {
        for (let i = 9; i >= 0; i--) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                cnt[i]--;
            }
        }
        return -ans;
    }

    if (cnt[0] > 0) {
        for (let i = 1; i < 10; i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                ans = i;
                break;
            }
        }
    }

    for (let i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
            ans = ans * 10 + i;
            cnt[i]--;
        }
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

<p>给你一个整数 <code>num</code> 。<strong>重排</strong> <code>num</code> 中的各位数字，使其值 <strong>最小化</strong> 且不含 <strong>任何</strong> 前导零。</p>

<p>返回不含前导零且值最小的重排数字。</p>

<p>注意，重排各位数字后，<code>num</code> 的符号不会改变。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 310
<strong>输出：</strong>103
<strong>解释：</strong>310 中各位数字的可行排列有：013、031、103、130、301、310 。
不含任何前导零且值最小的重排数字是 103 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = -7605
<strong>输出：</strong>-7650
<strong>解释：</strong>-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
不含任何前导零且值最小的重排数字是 -7650 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-10<sup>15</sup> &lt;= num &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们首先用一个数组 $\textit{cnt}$ 记录 $\textit{num}$ 中每个数字的出现次数。

如果 $\textit{num}$ 是负数，那么数字应该按照从大到小的顺序排列，因此我们从 $9$ 到 $0$ 遍历 $\textit{cnt}$，将数字按照出现次数从大到小的顺序排列。

如果是正数，我们首先找到第一个非 $0$ 的数字，将其放在第一位，然后按照从小到大的顺序排列剩余的数字。

时间复杂度 $O(\log n)$，其中 $n$ 为数字 $\textit{num}$ 的大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestNumber(self, num: int) -> int:
        neg = num < 0
        num = abs(num)
        cnt = [0] * 10
        while num:
            cnt[num % 10] += 1
            num //= 10
        ans = 0
        if neg:
            for i in reversed(range(10)):
                for _ in range(cnt[i]):
                    ans *= 10
                    ans += i
            return -ans
        if cnt[0]:
            for i in range(1, 10):
                if cnt[i]:
                    ans = i
                    cnt[i] -= 1
                    break
        for i in range(10):
            for _ in range(cnt[i]):
                ans *= 10
                ans += i
        return ans
```

#### Java

```java
class Solution {
    public long smallestNumber(long num) {
        boolean neg = num < 0;
        num = Math.abs(num);
        int[] cnt = new int[10];
        while (num > 0) {
            ++cnt[(int) (num % 10)];
            num /= 10;
        }
        long ans = 0;
        if (neg) {
            for (int i = 9; i >= 0; --i) {
                while (cnt[i] > 0) {
                    ans = ans * 10 + i;
                    --cnt[i];
                }
            }
            return -ans;
        }
        if (cnt[0] > 0) {
            for (int i = 1; i < 10; ++i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    ans = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                --cnt[i];
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
    long long smallestNumber(long long num) {
        bool neg = num < 0;
        num = abs(num);
        int cnt[10]{};
        while (num > 0) {
            ++cnt[num % 10];
            num /= 10;
        }
        long long ans = 0;
        if (neg) {
            for (int i = 9; i >= 0; --i) {
                while (cnt[i] > 0) {
                    ans = ans * 10 + i;
                    --cnt[i];
                }
            }
            return -ans;
        }
        if (cnt[0]) {
            for (int i = 1; i < 10; ++i) {
                if (cnt[i] > 0) {
                    --cnt[i];
                    ans = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                --cnt[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func smallestNumber(num int64) (ans int64) {
	neg := num < 0
	num = max(num, -num)
	cnt := make([]int, 10)

	for num > 0 {
		cnt[num%10]++
		num /= 10
	}

	if neg {
		for i := 9; i >= 0; i-- {
			for cnt[i] > 0 {
				ans = ans*10 + int64(i)
				cnt[i]--
			}
		}
		return -ans
	}

	if cnt[0] > 0 {
		for i := 1; i < 10; i++ {
			if cnt[i] > 0 {
				cnt[i]--
				ans = int64(i)
				break
			}
		}
	}

	for i := 0; i < 10; i++ {
		for cnt[i] > 0 {
			ans = ans*10 + int64(i)
			cnt[i]--
		}
	}

	return ans
}
```

#### TypeScript

```ts
function smallestNumber(num: number): number {
    const neg = num < 0;
    num = Math.abs(num);
    const cnt = Array(10).fill(0);

    while (num > 0) {
        cnt[num % 10]++;
        num = Math.floor(num / 10);
    }

    let ans = 0;
    if (neg) {
        for (let i = 9; i >= 0; i--) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                cnt[i]--;
            }
        }
        return -ans;
    }

    if (cnt[0] > 0) {
        for (let i = 1; i < 10; i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                ans = i;
                break;
            }
        }
    }

    for (let i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
            ans = ans * 10 + i;
            cnt[i]--;
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_number(num: i64) -> i64 {
        let mut neg = num < 0;
        let mut num = num.abs();
        let mut cnt = vec![0; 10];

        while num > 0 {
            cnt[(num % 10) as usize] += 1;
            num /= 10;
        }

        let mut ans = 0;
        if neg {
            for i in (0..10).rev() {
                while cnt[i] > 0 {
                    ans = ans * 10 + i as i64;
                    cnt[i] -= 1;
                }
            }
            return -ans;
        }

        if cnt[0] > 0 {
            for i in 1..10 {
                if cnt[i] > 0 {
                    cnt[i] -= 1;
                    ans = i as i64;
                    break;
                }
            }
        }

        for i in 0..10 {
            while cnt[i] > 0 {
                ans = ans * 10 + i as i64;
                cnt[i] -= 1;
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function (num) {
    const neg = num < 0;
    num = Math.abs(num);
    const cnt = Array(10).fill(0);

    while (num > 0) {
        cnt[num % 10]++;
        num = Math.floor(num / 10);
    }

    let ans = 0;
    if (neg) {
        for (let i = 9; i >= 0; i--) {
            while (cnt[i] > 0) {
                ans = ans * 10 + i;
                cnt[i]--;
            }
        }
        return -ans;
    }

    if (cnt[0] > 0) {
        for (let i = 1; i < 10; i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                ans = i;
                break;
            }
        }
    }

    for (let i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
            ans = ans * 10 + i;
            cnt[i]--;
        }
    }

    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2166. 设计位集](https://leetcode.cn/problems/design-bitset){#2166}

{{< tabs "2166" >}}

{{% tab "python" %}}
```python
class Bitset:
    def __init__(self, size: int):
        self.a = ['0'] * size
        self.b = ['1'] * size
        self.cnt = 0

    def fix(self, idx: int) -> None:
        if self.a[idx] == '0':
            self.a[idx] = '1'
            self.cnt += 1
        self.b[idx] = '0'

    def unfix(self, idx: int) -> None:
        if self.a[idx] == '1':
            self.a[idx] = '0'
            self.cnt -= 1
        self.b[idx] = '1'

    def flip(self) -> None:
        self.a, self.b = self.b, self.a
        self.cnt = len(self.a) - self.cnt

    def all(self) -> bool:
        return self.cnt == len(self.a)

    def one(self) -> bool:
        return self.cnt > 0

    def count(self) -> int:
        return self.cnt

    def toString(self) -> str:
        return ''.join(self.a)


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Bitset {
    private char[] a;
    private char[] b;
    private int cnt;

    public Bitset(int size) {
        a = new char[size];
        b = new char[size];
        Arrays.fill(a, '0');
        Arrays.fill(b, '1');
    }

    public void fix(int idx) {
        if (a[idx] == '0') {
            a[idx] = '1';
            ++cnt;
        }
        b[idx] = '0';
    }

    public void unfix(int idx) {
        if (a[idx] == '1') {
            a[idx] = '0';
            --cnt;
        }
        b[idx] = '1';
    }

    public void flip() {
        char[] t = a;
        a = b;
        b = t;
        cnt = a.length - cnt;
    }

    public boolean all() {
        return cnt == a.length;
    }

    public boolean one() {
        return cnt > 0;
    }

    public int count() {
        return cnt;
    }

    public String toString() {
        return String.valueOf(a);
    }
}

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset obj = new Bitset(size);
 * obj.fix(idx);
 * obj.unfix(idx);
 * obj.flip();
 * boolean param_4 = obj.all();
 * boolean param_5 = obj.one();
 * int param_6 = obj.count();
 * String param_7 = obj.toString();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Bitset {
public:
    string a, b;
    int cnt = 0;

    Bitset(int size) {
        a = string(size, '0');
        b = string(size, '1');
    }

    void fix(int idx) {
        if (a[idx] == '0') a[idx] = '1', ++cnt;
        b[idx] = '0';
    }

    void unfix(int idx) {
        if (a[idx] == '1') a[idx] = '0', --cnt;
        b[idx] = '1';
    }

    void flip() {
        swap(a, b);
        cnt = a.size() - cnt;
    }

    bool all() {
        return cnt == a.size();
    }

    bool one() {
        return cnt > 0;
    }

    int count() {
        return cnt;
    }

    string toString() {
        return a;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Bitset struct {
	a   []byte
	b   []byte
	cnt int
}

func Constructor(size int) Bitset {
	a := bytes.Repeat([]byte{'0'}, size)
	b := bytes.Repeat([]byte{'1'}, size)
	return Bitset{a, b, 0}
}

func (this *Bitset) Fix(idx int) {
	if this.a[idx] == '0' {
		this.a[idx] = '1'
		this.cnt++
	}
	this.b[idx] = '0'
}

func (this *Bitset) Unfix(idx int) {
	if this.a[idx] == '1' {
		this.a[idx] = '0'
		this.cnt--
	}
	this.b[idx] = '1'
}

func (this *Bitset) Flip() {
	this.a, this.b = this.b, this.a
	this.cnt = len(this.a) - this.cnt
}

func (this *Bitset) All() bool {
	return this.cnt == len(this.a)
}

func (this *Bitset) One() bool {
	return this.cnt > 0
}

func (this *Bitset) Count() int {
	return this.cnt
}

func (this *Bitset) ToString() string {
	return string(this.a)
}

/**
 * Your Bitset object will be instantiated and called as such:
 * obj := Constructor(size);
 * obj.Fix(idx);
 * obj.Unfix(idx);
 * obj.Flip();
 * param_4 := obj.All();
 * param_5 := obj.One();
 * param_6 := obj.Count();
 * param_7 := obj.ToString();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>位集 Bitset</strong> 是一种能以紧凑形式存储位的数据结构。</p>

<p>请你实现 <code>Bitset</code> 类。</p>

<ul>
	<li><code>Bitset(int size)</code> 用 <code>size</code> 个位初始化 Bitset ，所有位都是 <code>0</code> 。</li>
	<li><code>void fix(int idx)</code> 将下标为 <code>idx</code> 的位上的值更新为 <code>1</code> 。如果值已经是 <code>1</code> ，则不会发生任何改变。</li>
	<li><code>void unfix(int idx)</code> 将下标为 <code>idx</code> 的位上的值更新为 <code>0</code> 。如果值已经是 <code>0</code> ，则不会发生任何改变。</li>
	<li><code>void flip()</code> 翻转 Bitset 中每一位上的值。换句话说，所有值为 <code>0</code> 的位将会变成 <code>1</code> ，反之亦然。</li>
	<li><code>boolean all()</code> 检查&nbsp;Bitset 中 <strong>每一位</strong> 的值是否都是 <code>1</code> 。如果满足此条件，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
	<li><code>boolean one()</code> 检查&nbsp;Bitset 中 是否&nbsp;<strong>至少一位</strong> 的值是 <code>1</code> 。如果满足此条件，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
	<li><code>int count()</code> 返回 Bitset 中值为 1 的位的 <strong>总数</strong> 。</li>
	<li><code>String toString()</code> 返回 Bitset 的当前组成情况。注意，在结果字符串中，第 <code>i</code> 个下标处的字符应该与 Bitset 中的第 <code>i</code> 位一致。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]
[[5], [3], [1], [], [], [0], [], [], [0], [], []]
<strong>输出</strong>
[null, null, null, null, false, null, null, true, null, 2, "01010"]

<strong>解释</strong>
Bitset bs = new Bitset(5); // bitset = "00000".
bs.fix(3);     // 将 idx = 3 处的值更新为 1 ，此时 bitset = "00010" 。
bs.fix(1);     // 将 idx = 1 处的值更新为 1 ，此时 bitset = "01010" 。
bs.flip();     // 翻转每一位上的值，此时 bitset = "10101" 。
bs.all();      // 返回 False ，bitset 中的值不全为 1 。
bs.unfix(0);   // 将 idx = 0 处的值更新为 0 ，此时 bitset = "00101" 。
bs.flip();     // 翻转每一位上的值，此时 bitset = "11010" 。
bs.one();      // 返回 True ，至少存在一位的值为 1 。
bs.unfix(0);   // 将 idx = 0 处的值更新为 0 ，此时 bitset = "01010" 。
bs.count();    // 返回 2 ，当前有 2 位的值为 1 。
bs.toString(); // 返回 "01010" ，即 bitset 的当前组成情况。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= size &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= idx &lt;= size - 1</code></li>
	<li>至多调用&nbsp;<code>fix</code>、<code>unfix</code>、<code>flip</code>、<code>all</code>、<code>one</code>、<code>count</code> 和 <code>toString</code> 方法 <strong>总共</strong> <code>10<sup>5</sup></code> 次</li>
	<li>至少调用 <code>all</code>、<code>one</code>、<code>count</code> 或 <code>toString</code> 方法一次</li>
	<li>至多调用&nbsp;<code>toString</code> 方法 <code>5</code> 次</li>
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
class Bitset:
    def __init__(self, size: int):
        self.a = ['0'] * size
        self.b = ['1'] * size
        self.cnt = 0

    def fix(self, idx: int) -> None:
        if self.a[idx] == '0':
            self.a[idx] = '1'
            self.cnt += 1
        self.b[idx] = '0'

    def unfix(self, idx: int) -> None:
        if self.a[idx] == '1':
            self.a[idx] = '0'
            self.cnt -= 1
        self.b[idx] = '1'

    def flip(self) -> None:
        self.a, self.b = self.b, self.a
        self.cnt = len(self.a) - self.cnt

    def all(self) -> bool:
        return self.cnt == len(self.a)

    def one(self) -> bool:
        return self.cnt > 0

    def count(self) -> int:
        return self.cnt

    def toString(self) -> str:
        return ''.join(self.a)


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()
```

#### Java

```java
class Bitset {
    private char[] a;
    private char[] b;
    private int cnt;

    public Bitset(int size) {
        a = new char[size];
        b = new char[size];
        Arrays.fill(a, '0');
        Arrays.fill(b, '1');
    }

    public void fix(int idx) {
        if (a[idx] == '0') {
            a[idx] = '1';
            ++cnt;
        }
        b[idx] = '0';
    }

    public void unfix(int idx) {
        if (a[idx] == '1') {
            a[idx] = '0';
            --cnt;
        }
        b[idx] = '1';
    }

    public void flip() {
        char[] t = a;
        a = b;
        b = t;
        cnt = a.length - cnt;
    }

    public boolean all() {
        return cnt == a.length;
    }

    public boolean one() {
        return cnt > 0;
    }

    public int count() {
        return cnt;
    }

    public String toString() {
        return String.valueOf(a);
    }
}

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset obj = new Bitset(size);
 * obj.fix(idx);
 * obj.unfix(idx);
 * obj.flip();
 * boolean param_4 = obj.all();
 * boolean param_5 = obj.one();
 * int param_6 = obj.count();
 * String param_7 = obj.toString();
 */
```

#### C++

```cpp
class Bitset {
public:
    string a, b;
    int cnt = 0;

    Bitset(int size) {
        a = string(size, '0');
        b = string(size, '1');
    }

    void fix(int idx) {
        if (a[idx] == '0') a[idx] = '1', ++cnt;
        b[idx] = '0';
    }

    void unfix(int idx) {
        if (a[idx] == '1') a[idx] = '0', --cnt;
        b[idx] = '1';
    }

    void flip() {
        swap(a, b);
        cnt = a.size() - cnt;
    }

    bool all() {
        return cnt == a.size();
    }

    bool one() {
        return cnt > 0;
    }

    int count() {
        return cnt;
    }

    string toString() {
        return a;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
```

#### Go

```go
type Bitset struct {
	a   []byte
	b   []byte
	cnt int
}

func Constructor(size int) Bitset {
	a := bytes.Repeat([]byte{'0'}, size)
	b := bytes.Repeat([]byte{'1'}, size)
	return Bitset{a, b, 0}
}

func (this *Bitset) Fix(idx int) {
	if this.a[idx] == '0' {
		this.a[idx] = '1'
		this.cnt++
	}
	this.b[idx] = '0'
}

func (this *Bitset) Unfix(idx int) {
	if this.a[idx] == '1' {
		this.a[idx] = '0'
		this.cnt--
	}
	this.b[idx] = '1'
}

func (this *Bitset) Flip() {
	this.a, this.b = this.b, this.a
	this.cnt = len(this.a) - this.cnt
}

func (this *Bitset) All() bool {
	return this.cnt == len(this.a)
}

func (this *Bitset) One() bool {
	return this.cnt > 0
}

func (this *Bitset) Count() int {
	return this.cnt
}

func (this *Bitset) ToString() string {
	return string(this.a)
}

/**
 * Your Bitset object will be instantiated and called as such:
 * obj := Constructor(size);
 * obj.Fix(idx);
 * obj.Unfix(idx);
 * obj.Flip();
 * param_4 := obj.All();
 * param_5 := obj.One();
 * param_6 := obj.Count();
 * param_7 := obj.ToString();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2167. 移除所有载有违禁货物车厢所需的最少时间](https://leetcode.cn/problems/minimum-time-to-remove-all-cars-containing-illegal-goods){#2167}

{{< tabs "2167" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, s: str) -> int:
        n = len(s)
        pre = [0] * (n + 1)
        suf = [0] * (n + 1)
        for i, c in enumerate(s):
            pre[i + 1] = pre[i] if c == '0' else min(pre[i] + 2, i + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] if s[i] == '0' else min(suf[i + 1] + 2, n - i)
        return min(a + b for a, b in zip(pre[1:], suf[1:]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTime(String s) {
        int n = s.length();
        int[] pre = new int[n + 1];
        int[] suf = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = s.charAt(i) == '0' ? pre[i] : Math.min(pre[i] + 2, i + 1);
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = s.charAt(i) == '0' ? suf[i + 1] : Math.min(suf[i + 1] + 2, n - i);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            ans = Math.min(ans, pre[i] + suf[i]);
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
    int minimumTime(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        vector<int> suf(n + 1);
        for (int i = 0; i < n; ++i) pre[i + 1] = s[i] == '0' ? pre[i] : min(pre[i] + 2, i + 1);
        for (int i = n - 1; ~i; --i) suf[i] = s[i] == '0' ? suf[i + 1] : min(suf[i + 1] + 2, n - i);
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) ans = min(ans, pre[i] + suf[i]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(s string) int {
	n := len(s)
	pre := make([]int, n+1)
	suf := make([]int, n+1)
	for i, c := range s {
		pre[i+1] = pre[i]
		if c == '1' {
			pre[i+1] = min(pre[i]+2, i+1)
		}
	}
	for i := n - 1; i >= 0; i-- {
		suf[i] = suf[i+1]
		if s[i] == '1' {
			suf[i] = min(suf[i+1]+2, n-i)
		}
	}
	ans := 0x3f3f3f3f
	for i := 1; i <= n; i++ {
		ans = min(ans, pre[i]+suf[i])
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

<p>给你一个下标从 <strong>0</strong> 开始的二进制字符串 <code>s</code> ，表示一个列车车厢序列。<code>s[i] = '0'</code> 表示第 <code>i</code> 节车厢 <strong>不</strong> 含违禁货物，而 <code>s[i] = '1'</code> 表示第 <code>i</code> 节车厢含违禁货物。</p>

<p>作为列车长，你需要清理掉所有载有违禁货物的车厢。你可以不限次数执行下述三种操作中的任意一个：</p>

<ol>
	<li>从列车 <strong>左</strong> 端移除一节车厢（即移除 <code>s[0]</code>），用去 1 单位时间。</li>
	<li>从列车 <strong>右</strong> 端移除一节车厢（即移除 <code>s[s.length - 1]</code>），用去 1 单位时间。</li>
	<li>从列车车厢序列的 <strong>任意位置</strong> 移除一节车厢，用去 2 单位时间。</li>
</ol>

<p>返回移除所有载有违禁货物车厢所需要的 <strong>最少</strong> 单位时间数。</p>

<p>注意，空的列车车厢序列视为没有车厢含违禁货物。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "<em><strong>11</strong></em>00<em><strong>1</strong></em>0<em><strong>1</strong></em>"
<strong>输出：</strong>5
<strong>解释：</strong>
一种从序列中移除所有载有违禁货物的车厢的方法是：
- 从左端移除一节车厢 2 次。所用时间是 2 * 1 = 2 。
- 从右端移除一节车厢 1 次。所用时间是 1 。
- 移除序列中间位置载有违禁货物的车厢。所用时间是 2 。
总时间是 2 + 1 + 2 = 5 。

一种替代方法是：
- 从左端移除一节车厢 2 次。所用时间是 2 * 1 = 2 。
- 从右端移除一节车厢 3 次。所用时间是 3 * 1 = 3 。
总时间也是 2 + 3 = 5 。

5 是移除所有载有违禁货物的车厢所需要的最少单位时间数。
没有其他方法能够用更少的时间移除这些车厢。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "00<em><strong>1</strong></em>0"
<strong>输出：</strong>2
<strong>解释：</strong>
一种从序列中移除所有载有违禁货物的车厢的方法是：
- 从左端移除一节车厢 3 次。所用时间是 3 * 1 = 3 。
总时间是 3.

另一种从序列中移除所有载有违禁货物的车厢的方法是：
- 移除序列中间位置载有违禁货物的车厢。所用时间是 2 。
总时间是 2.

另一种从序列中移除所有载有违禁货物的车厢的方法是：
- 从右端移除一节车厢 2 次。所用时间是 2 * 1 = 2 。
总时间是 2.

2 是移除所有载有违禁货物的车厢所需要的最少单位时间数。
没有其他方法能够用更少的时间移除这些车厢。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
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
    def minimumTime(self, s: str) -> int:
        n = len(s)
        pre = [0] * (n + 1)
        suf = [0] * (n + 1)
        for i, c in enumerate(s):
            pre[i + 1] = pre[i] if c == '0' else min(pre[i] + 2, i + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] if s[i] == '0' else min(suf[i + 1] + 2, n - i)
        return min(a + b for a, b in zip(pre[1:], suf[1:]))
```

#### Java

```java
class Solution {
    public int minimumTime(String s) {
        int n = s.length();
        int[] pre = new int[n + 1];
        int[] suf = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = s.charAt(i) == '0' ? pre[i] : Math.min(pre[i] + 2, i + 1);
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = s.charAt(i) == '0' ? suf[i + 1] : Math.min(suf[i + 1] + 2, n - i);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            ans = Math.min(ans, pre[i] + suf[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        vector<int> suf(n + 1);
        for (int i = 0; i < n; ++i) pre[i + 1] = s[i] == '0' ? pre[i] : min(pre[i] + 2, i + 1);
        for (int i = n - 1; ~i; --i) suf[i] = s[i] == '0' ? suf[i + 1] : min(suf[i + 1] + 2, n - i);
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) ans = min(ans, pre[i] + suf[i]);
        return ans;
    }
};
```

#### Go

```go
func minimumTime(s string) int {
	n := len(s)
	pre := make([]int, n+1)
	suf := make([]int, n+1)
	for i, c := range s {
		pre[i+1] = pre[i]
		if c == '1' {
			pre[i+1] = min(pre[i]+2, i+1)
		}
	}
	for i := n - 1; i >= 0; i-- {
		suf[i] = suf[i+1]
		if s[i] == '1' {
			suf[i] = min(suf[i+1]+2, n-i)
		}
	}
	ans := 0x3f3f3f3f
	for i := 1; i <= n; i++ {
		ans = min(ans, pre[i]+suf[i])
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2168. 每个数字的频率都相同的独特子字符串的数量 🔒](https://leetcode.cn/problems/unique-substrings-with-equal-digit-frequency){#2168}

{{< tabs "2168" >}}

{{% tab "python" %}}
```python
class Solution:
    def equalDigitFrequency(self, s: str) -> int:
        def check(i, j):
            v = set()
            for k in range(10):
                cnt = presum[j + 1][k] - presum[i][k]
                if cnt > 0:
                    v.add(cnt)
                if len(v) > 1:
                    return False
            return True

        n = len(s)
        presum = [[0] * 10 for _ in range(n + 1)]
        for i, c in enumerate(s):
            presum[i + 1][int(c)] += 1
            for j in range(10):
                presum[i + 1][j] += presum[i][j]
        vis = set(s[i : j + 1] for i in range(n) for j in range(i, n) if check(i, j))
        return len(vis)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int equalDigitFrequency(String s) {
        int n = s.length();
        int[][] presum = new int[n + 1][10];
        for (int i = 0; i < n; ++i) {
            ++presum[i + 1][s.charAt(i) - '0'];
            for (int j = 0; j < 10; ++j) {
                presum[i + 1][j] += presum[i][j];
            }
        }
        Set<String> vis = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (check(i, j, presum)) {
                    vis.add(s.substring(i, j + 1));
                }
            }
        }
        return vis.size();
    }

    private boolean check(int i, int j, int[][] presum) {
        Set<Integer> v = new HashSet<>();
        for (int k = 0; k < 10; ++k) {
            int cnt = presum[j + 1][k] - presum[i][k];
            if (cnt > 0) {
                v.add(cnt);
            }
            if (v.size() > 1) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equalDigitFrequency(s string) int {
	n := len(s)
	presum := make([][]int, n+1)
	for i := range presum {
		presum[i] = make([]int, 10)
	}
	for i, c := range s {
		presum[i+1][c-'0']++
		for j := 0; j < 10; j++ {
			presum[i+1][j] += presum[i][j]
		}
	}
	check := func(i, j int) bool {
		v := make(map[int]bool)
		for k := 0; k < 10; k++ {
			cnt := presum[j+1][k] - presum[i][k]
			if cnt > 0 {
				v[cnt] = true
			}
			if len(v) > 1 {
				return false
			}
		}
		return true
	}
	vis := make(map[string]bool)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if check(i, j) {
				vis[s[i:j+1]] = true
			}
		}
	}
	return len(vis)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个由数字组成的字符串&nbsp;<code>s</code>，返回<em>&nbsp;</em><code>s</code><em>&nbsp;</em>中<strong>独特子字符串数量</strong>，其中的每一个数字出现的频率都相同<i>。</i>

<p>&nbsp;</p>

<p><strong>示例1:</strong></p>

<pre>
<strong>输入:</strong> s = "1212"
<strong>输出:</strong> 5
<strong>解释:</strong> 符合要求的子串有 "1", "2", "12", "21", "1212".
要注意，尽管"12"在s中出现了两次，但在计数的时候只计算一次。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> s = "12321"
<strong>输出:</strong> 9
<strong>解释:</strong> 符合要求的子串有 "1", "2", "3", "12", "23", "32", "21", "123", "321".
</pre>

<p>&nbsp;</p>

<p><strong>解释:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;只包含阿拉伯数字.</li>
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
    def equalDigitFrequency(self, s: str) -> int:
        def check(i, j):
            v = set()
            for k in range(10):
                cnt = presum[j + 1][k] - presum[i][k]
                if cnt > 0:
                    v.add(cnt)
                if len(v) > 1:
                    return False
            return True

        n = len(s)
        presum = [[0] * 10 for _ in range(n + 1)]
        for i, c in enumerate(s):
            presum[i + 1][int(c)] += 1
            for j in range(10):
                presum[i + 1][j] += presum[i][j]
        vis = set(s[i : j + 1] for i in range(n) for j in range(i, n) if check(i, j))
        return len(vis)
```

#### Java

```java
class Solution {
    public int equalDigitFrequency(String s) {
        int n = s.length();
        int[][] presum = new int[n + 1][10];
        for (int i = 0; i < n; ++i) {
            ++presum[i + 1][s.charAt(i) - '0'];
            for (int j = 0; j < 10; ++j) {
                presum[i + 1][j] += presum[i][j];
            }
        }
        Set<String> vis = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (check(i, j, presum)) {
                    vis.add(s.substring(i, j + 1));
                }
            }
        }
        return vis.size();
    }

    private boolean check(int i, int j, int[][] presum) {
        Set<Integer> v = new HashSet<>();
        for (int k = 0; k < 10; ++k) {
            int cnt = presum[j + 1][k] - presum[i][k];
            if (cnt > 0) {
                v.add(cnt);
            }
            if (v.size() > 1) {
                return false;
            }
        }
        return true;
    }
}
```

#### Go

```go
func equalDigitFrequency(s string) int {
	n := len(s)
	presum := make([][]int, n+1)
	for i := range presum {
		presum[i] = make([]int, 10)
	}
	for i, c := range s {
		presum[i+1][c-'0']++
		for j := 0; j < 10; j++ {
			presum[i+1][j] += presum[i][j]
		}
	}
	check := func(i, j int) bool {
		v := make(map[int]bool)
		for k := 0; k < 10; k++ {
			cnt := presum[j+1][k] - presum[i][k]
			if cnt > 0 {
				v[cnt] = true
			}
			if len(v) > 1 {
				return false
			}
		}
		return true
	}
	vis := make(map[string]bool)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if check(i, j) {
				vis[s[i:j+1]] = true
			}
		}
	}
	return len(vis)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2169. 得到 0 的操作数](https://leetcode.cn/problems/count-operations-to-obtain-zero){#2169}

{{< tabs "2169" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ans = 0
        while num1 and num2:
            if num1 >= num2:
                ans += num1 // num2
                num1 %= num2
            else:
                ans += num2 // num1
                num2 %= num1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
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
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 && num2) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOperations(num1 int, num2 int) (ans int) {
	for num1 != 0 && num2 != 0 {
		if num1 >= num2 {
			ans += num1 / num2
			num1 %= num2
		} else {
			ans += num2 / num1
			num2 %= num1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countOperations(num1: number, num2: number): number {
    let ans = 0;
    while (num1 && num2) {
        if (num1 >= num2) {
            ans += (num1 / num2) | 0;
            num1 %= num2;
        } else {
            ans += (num2 / num1) | 0;
            num2 %= num1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut ans = 0;
        while num1 != 0 && num2 != 0 {
            if num1 >= num2 {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var countOperations = function (num1, num2) {
    let ans = 0;
    while (num1 && num2) {
        if (num1 >= num2) {
            ans += (num1 / num2) | 0;
            num1 %= num2;
        } else {
            ans += (num2 / num1) | 0;
            num2 %= num1;
        }
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

<p>给你两个 <strong>非负</strong> 整数 <code>num1</code> 和 <code>num2</code> 。</p>

<p>每一步 <strong>操作</strong>&nbsp;中，如果 <code>num1 &gt;= num2</code> ，你必须用 <code>num1</code> 减 <code>num2</code> ；否则，你必须用 <code>num2</code> 减 <code>num1</code> 。</p>

<ul>
	<li>例如，<code>num1 = 5</code> 且 <code>num2 = 4</code> ，应该用&nbsp;<code>num1</code> 减 <code>num2</code> ，因此，得到 <code>num1 = 1</code> 和 <code>num2 = 4</code> 。然而，如果 <code>num1 = 4</code>且 <code>num2 = 5</code> ，一步操作后，得到 <code>num1 = 4</code> 和 <code>num2 = 1</code> 。</li>
</ul>

<p>返回使 <code>num1 = 0</code> 或 <code>num2 = 0</code> 的 <strong>操作数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 2, num2 = 3
<strong>输出：</strong>3
<strong>解释：</strong>
- 操作 1 ：num1 = 2 ，num2 = 3 。由于 num1 &lt; num2 ，num2 减 num1 得到 num1 = 2 ，num2 = 3 - 2 = 1 。
- 操作 2 ：num1 = 2 ，num2 = 1 。由于 num1 &gt; num2 ，num1 减 num2 。
- 操作 3 ：num1 = 1 ，num2 = 1 。由于 num1 == num2 ，num1 减 num2 。
此时 num1 = 0 ，num2 = 1 。由于 num1 == 0 ，不需要再执行任何操作。
所以总操作数是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = 10, num2 = 10
<strong>输出：</strong>1
<strong>解释：</strong>
- 操作 1 ：num1 = 10 ，num2 = 10 。由于 num1 == num2 ，num1 减 num2 得到 num1 = 10 - 10 = 0 。
此时 num1 = 0 ，num2 = 10 。由于 num1 == 0 ，不需要再执行任何操作。
所以总操作数是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num1, num2 &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟这个过程，循环执行以下操作：

-   如果 $\textit{num1} \ge \textit{num2}$，则 $\textit{num1} = \textit{num1} - \textit{num2}$；
-   否则，$\textit{num2} = \textit{num2} - \textit{num1}$。
-   每执行一次操作，操作数加一。

当 $\textit{num1}$ 或 $\textit{num2}$ 有一个为 $0$ 时，停止循环，返回操作数。

时间复杂度 $O(m)$，其中 $m$ 为 $\textit{num1}$ 和 $\textit{num2}$ 的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ans = 0
        while num1 and num2:
            if num1 >= num2:
                num1 -= num2
            else:
                num2 -= num1
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countOperations(int num1, int num2) {
        int ans = 0;
        for (; num1 != 0 && num2 != 0; ++ans) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
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
    int countOperations(int num1, int num2) {
        int ans = 0;
        for (; num1 && num2; ++ans) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countOperations(num1 int, num2 int) (ans int) {
	for ; num1 != 0 && num2 != 0; ans++ {
		if num1 >= num2 {
			num1 -= num2
		} else {
			num2 -= num1
		}
	}
	return
}
```

#### TypeScript

```ts
function countOperations(num1: number, num2: number): number {
    let ans = 0;
    for (; num1 && num2; ++ans) {
        if (num1 >= num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut ans = 0;
        while num1 != 0 && num2 != 0 {
            ans += 1;
            if num1 >= num2 {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var countOperations = function (num1, num2) {
    let ans = 0;
    for (; num1 && num2; ++ans) {
        if (num1 >= num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

如果按照方法一的模拟过程，我们会发现，如果 $\textit{num1}$ 远大于 $\textit{num2}$，那么每次操作我们都会减少 $\textit{num1}$ 的值，这样会导致操作数过多。我们可以优化这个过程，每次操作时，我们可以直接将 $\textit{num1}$ 除以 $\textit{num2}$ 的商加到答案中，然后将 $\textit{num1}$ 对 $\textit{num2}$ 取余，这样可以减少操作数。

时间复杂度 $O(\log m)$，其中 $m$ 为 $\textit{num1}$ 和 $\textit{num2}$ 的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ans = 0
        while num1 and num2:
            if num1 >= num2:
                ans += num1 // num2
                num1 %= num2
            else:
                ans += num2 // num1
                num2 %= num1
        return ans
```

#### Java

```java
class Solution {
    public int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
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
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 && num2) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countOperations(num1 int, num2 int) (ans int) {
	for num1 != 0 && num2 != 0 {
		if num1 >= num2 {
			ans += num1 / num2
			num1 %= num2
		} else {
			ans += num2 / num1
			num2 %= num1
		}
	}
	return
}
```

#### TypeScript

```ts
function countOperations(num1: number, num2: number): number {
    let ans = 0;
    while (num1 && num2) {
        if (num1 >= num2) {
            ans += (num1 / num2) | 0;
            num1 %= num2;
        } else {
            ans += (num2 / num1) | 0;
            num2 %= num1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut ans = 0;
        while num1 != 0 && num2 != 0 {
            if num1 >= num2 {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var countOperations = function (num1, num2) {
    let ans = 0;
    while (num1 && num2) {
        if (num1 >= num2) {
            ans += (num1 / num2) | 0;
            num1 %= num2;
        } else {
            ans += (num2 / num1) | 0;
            num2 %= num1;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
