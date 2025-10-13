---
title: "2540_最小公共值"
date: 2025-10-08T18:39:23+08:00
weight: 5
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数组, 数论, 模拟, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [2540_最小公共值](#2540)
#### [数组](#2540)
#### [哈希表](#2540)
#### [双指针](#2540)
#### [二分查找](#2540)
### [2541_使数组中所有元素相等的最小操作数 II](#2541)
#### [贪心](#2541)
#### [数组](#2541)
#### [数学](#2541)
### [2542_最大子序列的分数](#2542)
#### [贪心](#2542)
#### [数组](#2542)
#### [排序](#2542)
#### [堆（优先队列）](#2542)
### [2543_判断一个点是否可以到达](#2543)
#### [数学](#2543)
#### [数论](#2543)
### [2544_交替数字和](#2544)
#### [数学](#2544)
### [2545_根据第 K 场考试的分数排序](#2545)
#### [数组](#2545)
#### [矩阵](#2545)
#### [排序](#2545)
### [2546_执行逐位运算使字符串相等](#2546)
#### [位运算](#2546)
#### [字符串](#2546)
### [2547_拆分数组的最小代价](#2547)
#### [数组](#2547)
#### [哈希表](#2547)
#### [动态规划](#2547)
#### [计数](#2547)
### [2548_填满背包的最大价格 🔒](#2548)
#### [贪心](#2548)
#### [数组](#2548)
#### [排序](#2548)
### [2549_统计桌面上的不同数字](#2549)
#### [数组](#2549)
#### [哈希表](#2549)
#### [数学](#2549)
#### [模拟](#2549)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2540_最小公共值
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
---
### 2541_使数组中所有元素相等的最小操作数 II
___
#### 贪心
___
#### 数组
___
#### 数学
---
### 2542_最大子序列的分数
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2543_判断一个点是否可以到达
___
#### 数学
___
#### 数论
---
### 2544_交替数字和
___
#### 数学
---
### 2545_根据第 K 场考试的分数排序
___
#### 数组
___
#### 矩阵
___
#### 排序
---
### 2546_执行逐位运算使字符串相等
___
#### 位运算
___
#### 字符串
---
### 2547_拆分数组的最小代价
___
#### 数组
___
#### 哈希表
___
#### 动态规划
___
#### 计数
---
### 2548_填满背包的最大价格 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2549_统计桌面上的不同数字
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数组 | 数论 | 模拟 |
| 矩阵 | 计数 | 贪心 |

# [2540. 最小公共值](https://leetcode.cn/problems/minimum-common-value){#2540}

{{< tabs "2540" >}}

{{% tab "python" %}}
```python
class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        i = j = 0
        m, n = len(nums1), len(nums2)
        while i < m and j < n:
            if nums1[i] == nums2[j]:
                return nums1[i]
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        for (int i = 0, j = 0; i < m && j < n;) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getCommon(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	for i, j := 0, 0; i < m && j < n; {
		if nums1[i] == nums2[j] {
			return nums1[i]
		}
		if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getCommon(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    let i = 0;
    let j = 0;
    while (i < m && j < n) {
        if (nums1[i] === nums2[j]) {
            return nums1[i];
        }
        if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut iter1 = nums1.iter();
        let mut iter2 = nums2.iter();
        let mut num1 = iter1.next();
        let mut num2 = iter2.next();

        while let (Some(n1), Some(n2)) = (num1, num2) {
            if n1 == n2 {
                return *n1;
            } else if n1 < n2 {
                num1 = iter1.next();
            } else {
                num2 = iter2.next();
            }
        }

        -1
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0;
    int j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            return nums1[i];
        }
        if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，它们已经按非降序排序，请你返回两个数组的 <strong>最小公共整数</strong>&nbsp;。如果两个数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;没有公共整数，请你返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>如果一个整数在两个数组中都 <strong>至少出现一次</strong>&nbsp;，那么这个整数是数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;<strong>公共</strong>&nbsp;的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3], nums2 = [2,4]
<b>输出：</b>2
<b>解释：</b>两个数组的最小公共元素是 2 ，所以我们返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3,6], nums2 = [2,3,4,5]
<b>输出：</b>2
<b>解释：</b>两个数组中的公共元素是 2 和 3 ，2 是较小值，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;都是 <strong>非降序</strong>&nbsp;的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

遍历两个数组，如果两个指针指向的元素相等，则返回该元素；如果两个指针指向的元素不相等，则将指向较小元素的指针右移一位，直到找到相等的元素或者遍历完数组。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是两个数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        i = j = 0
        m, n = len(nums1), len(nums2)
        while i < m and j < n:
            if nums1[i] == nums2[j]:
                return nums1[i]
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return -1
```

#### Java

```java
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        for (int i = 0, j = 0; i < m && j < n;) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func getCommon(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	for i, j := 0, 0; i < m && j < n; {
		if nums1[i] == nums2[j] {
			return nums1[i]
		}
		if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}
	return -1
}
```

#### TypeScript

```ts
function getCommon(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    let i = 0;
    let j = 0;
    while (i < m && j < n) {
        if (nums1[i] === nums2[j]) {
            return nums1[i];
        }
        if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut i = 0;
        let mut j = 0;
        while i < m && j < n {
            if nums1[i] == nums2[j] {
                return nums1[i];
            }
            if nums1[i] < nums2[j] {
                i += 1;
            } else {
                j += 1;
            }
        }
        -1
    }
}
```

#### C

```c
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0;
    int j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            return nums1[i];
        }
        if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut iter1 = nums1.iter();
        let mut iter2 = nums2.iter();
        let mut num1 = iter1.next();
        let mut num2 = iter2.next();

        while let (Some(n1), Some(n2)) = (num1, num2) {
            if n1 == n2 {
                return *n1;
            } else if n1 < n2 {
                num1 = iter1.next();
            } else {
                num2 = iter2.next();
            }
        }

        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2541. 使数组中所有元素相等的最小操作数 II](https://leetcode.cn/problems/minimum-operations-to-make-array-equal-ii){#2541}

{{< tabs "2541" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        ans = x = 0
        for a, b in zip(nums1, nums2):
            if k == 0:
                if a != b:
                    return -1
                continue
            if (a - b) % k:
                return -1
            y = (a - b) // k
            ans += abs(y)
            x += y
        return -1 if x else ans // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        long ans = 0, x = 0;
        for (int i = 0; i < nums1.length; ++i) {
            int a = nums1[i], b = nums2[i];
            if (k == 0) {
                if (a != b) {
                    return -1;
                }
                continue;
            }
            if ((a - b) % k != 0) {
                return -1;
            }
            int y = (a - b) / k;
            ans += Math.abs(y);
            x += y;
        }
        return x == 0 ? ans / 2 : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0, x = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int a = nums1[i], b = nums2[i];
            if (k == 0) {
                if (a != b) {
                    return -1;
                }
                continue;
            }
            if ((a - b) % k != 0) {
                return -1;
            }
            int y = (a - b) / k;
            ans += abs(y);
            x += y;
        }
        return x == 0 ? ans / 2 : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums1 []int, nums2 []int, k int) int64 {
	ans, x := 0, 0
	for i, a := range nums1 {
		b := nums2[i]
		if k == 0 {
			if a != b {
				return -1
			}
			continue
		}
		if (a-b)%k != 0 {
			return -1
		}
		y := (a - b) / k
		ans += abs(y)
		x += y
	}
	if x != 0 {
		return -1
	}
	return int64(ans / 2)
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
function minOperations(nums1: number[], nums2: number[], k: number): number {
    const n = nums1.length;
    if (k === 0) {
        return nums1.every((v, i) => v === nums2[i]) ? 0 : -1;
    }
    let sum1 = 0;
    let sum2 = 0;
    for (let i = 0; i < n; i++) {
        const diff = nums1[i] - nums2[i];
        sum1 += diff;
        if (diff % k !== 0) {
            return -1;
        }
        sum2 += Math.abs(diff);
    }
    if (sum1 !== 0) {
        return -1;
    }
    return sum2 / (k * 2);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i64 {
        let k = k as i64;
        let n = nums1.len();
        if k == 0 {
            return if nums1.iter().enumerate().all(|(i, &v)| v == nums2[i]) {
                0
            } else {
                -1
            };
        }
        let mut sum1 = 0;
        let mut sum2 = 0;
        for i in 0..n {
            let diff = (nums1[i] - nums2[i]) as i64;
            sum1 += diff;
            if diff % k != 0 {
                return -1;
            }
            sum2 += diff.abs();
        }
        if sum1 != 0 {
            return -1;
        }
        sum2 / (k * 2)
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
long long minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (k == 0) {
        for (int i = 0; i < nums1Size; i++) {
            if (nums1[i] != nums2[i]) {
                return -1;
            }
        }
        return 0;
    }
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i < nums1Size; i++) {
        long long diff = nums1[i] - nums2[i];
        sum1 += diff;
        if (diff % k != 0) {
            return -1;
        }
        sum2 += llabs(diff);
    }
    if (sum1 != 0) {
        return -1;
    }
    return sum2 / (k * 2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，两个数组长度都是&nbsp;<code>n</code>&nbsp;，再给你一个整数&nbsp;<code>k</code>&nbsp;。你可以对数组&nbsp;<code>nums1</code>&nbsp;进行以下操作：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，将&nbsp;<code>nums1[i]</code>&nbsp;增加&nbsp;<code>k</code>&nbsp;，将&nbsp;<code>nums1[j]</code>&nbsp;减少&nbsp;<code>k</code>&nbsp;。换言之，<code>nums1[i] = nums1[i] + k</code> 且&nbsp;<code>nums1[j] = nums1[j] - k</code>&nbsp;。</li>
</ul>

<p>如果对于所有满足&nbsp;<code>0 &lt;= i &lt; n</code>&nbsp;都有&nbsp;<code>num1[i] == nums2[i]</code>&nbsp;，那么我们称&nbsp;<code>nums1</code> <strong>等于</strong>&nbsp;<code>nums2</code>&nbsp;。</p>

<p>请你返回使<em>&nbsp;</em><code>nums1</code><em> </em>等于<em>&nbsp;</em><code>nums2</code>&nbsp;的&nbsp;<strong>最少</strong>&nbsp;操作数。如果没办法让它们相等，请你返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [4,3,1,4], nums2 = [1,3,7,1], k = 3
<b>输出：</b>2
<b>解释：</b>我们可以通过 2 个操作将 nums1 变成 nums2 。
第 1 个操作：i = 2 ，j = 0 。操作后得到 nums1 = [1,3,4,4] 。
第 2 个操作：i = 2 ，j = 3 。操作后得到 nums1 = [1,3,7,1] 。
无法用更少操作使两个数组相等。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [3,8,5,2], nums2 = [2,4,1,6], k = 1
<b>输出：</b>-1
<b>解释：</b>无法使两个数组相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们用变量 $x$ 记录加减次数的差值，用变量 $ans$ 记录操作次数。

遍历数组，对于每个位置 $i$，如果存在 $k=0$ 并且 $a_i \neq b_i$，则无法使两个数组相等，返回 $-1$。否则，如果 $k \neq 0$，则 $a_i - b_i$ 必须是 $k$ 的倍数，否则无法使两个数组相等，返回 $-1$。接下来，我们更新 $x$ 和 $ans$。

最后，如果 $x \neq 0$，则无法使两个数组相等，返回 $-1$。否则，返回 $\frac{ans}{2}$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        ans = x = 0
        for a, b in zip(nums1, nums2):
            if k == 0:
                if a != b:
                    return -1
                continue
            if (a - b) % k:
                return -1
            y = (a - b) // k
            ans += abs(y)
            x += y
        return -1 if x else ans // 2
```

#### Java

```java
class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        long ans = 0, x = 0;
        for (int i = 0; i < nums1.length; ++i) {
            int a = nums1[i], b = nums2[i];
            if (k == 0) {
                if (a != b) {
                    return -1;
                }
                continue;
            }
            if ((a - b) % k != 0) {
                return -1;
            }
            int y = (a - b) / k;
            ans += Math.abs(y);
            x += y;
        }
        return x == 0 ? ans / 2 : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0, x = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int a = nums1[i], b = nums2[i];
            if (k == 0) {
                if (a != b) {
                    return -1;
                }
                continue;
            }
            if ((a - b) % k != 0) {
                return -1;
            }
            int y = (a - b) / k;
            ans += abs(y);
            x += y;
        }
        return x == 0 ? ans / 2 : -1;
    }
};
```

#### Go

```go
func minOperations(nums1 []int, nums2 []int, k int) int64 {
	ans, x := 0, 0
	for i, a := range nums1 {
		b := nums2[i]
		if k == 0 {
			if a != b {
				return -1
			}
			continue
		}
		if (a-b)%k != 0 {
			return -1
		}
		y := (a - b) / k
		ans += abs(y)
		x += y
	}
	if x != 0 {
		return -1
	}
	return int64(ans / 2)
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
function minOperations(nums1: number[], nums2: number[], k: number): number {
    const n = nums1.length;
    if (k === 0) {
        return nums1.every((v, i) => v === nums2[i]) ? 0 : -1;
    }
    let sum1 = 0;
    let sum2 = 0;
    for (let i = 0; i < n; i++) {
        const diff = nums1[i] - nums2[i];
        sum1 += diff;
        if (diff % k !== 0) {
            return -1;
        }
        sum2 += Math.abs(diff);
    }
    if (sum1 !== 0) {
        return -1;
    }
    return sum2 / (k * 2);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i64 {
        let k = k as i64;
        let n = nums1.len();
        if k == 0 {
            return if nums1.iter().enumerate().all(|(i, &v)| v == nums2[i]) {
                0
            } else {
                -1
            };
        }
        let mut sum1 = 0;
        let mut sum2 = 0;
        for i in 0..n {
            let diff = (nums1[i] - nums2[i]) as i64;
            sum1 += diff;
            if diff % k != 0 {
                return -1;
            }
            sum2 += diff.abs();
        }
        if sum1 != 0 {
            return -1;
        }
        sum2 / (k * 2)
    }
}
```

#### C

```c
long long minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (k == 0) {
        for (int i = 0; i < nums1Size; i++) {
            if (nums1[i] != nums2[i]) {
                return -1;
            }
        }
        return 0;
    }
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i < nums1Size; i++) {
        long long diff = nums1[i] - nums2[i];
        sum1 += diff;
        if (diff % k != 0) {
            return -1;
        }
        sum2 += llabs(diff);
    }
    if (sum1 != 0) {
        return -1;
    }
    return sum2 / (k * 2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2542. 最大子序列的分数](https://leetcode.cn/problems/maximum-subsequence-score){#2542}

{{< tabs "2542" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = sorted(zip(nums2, nums1), reverse=True)
        q = []
        ans = s = 0
        for a, b in nums:
            s += b
            heappush(q, b)
            if len(q) == k:
                ans = max(ans, s * a)
                s -= heappop(q)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] nums = new int[n][2];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1[i], nums2[i]};
        }
        Arrays.sort(nums, (a, b) -> b[1] - a[1]);
        long ans = 0, s = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            s += nums[i][0];
            q.offer(nums[i][0]);
            if (q.size() == k) {
                ans = Math.max(ans, s * nums[i][1]);
                s -= q.poll();
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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = {-nums2[i], nums1[i]};
        }
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int>> q;
        long long ans = 0, s = 0;
        for (auto& [a, b] : nums) {
            s += b;
            q.push(b);
            if (q.size() == k) {
                ans = max(ans, s * -a);
                s -= q.top();
                q.pop();
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(nums1 []int, nums2 []int, k int) int64 {
	type pair struct{ a, b int }
	nums := []pair{}
	for i, a := range nums1 {
		b := nums2[i]
		nums = append(nums, pair{a, b})
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i].b > nums[j].b })
	q := hp{}
	var ans, s int
	for _, e := range nums {
		a, b := e.a, e.b
		s += a
		heap.Push(&q, a)
		if q.Len() == k {
			ans = max(ans, s*b)
			s -= heap.Pop(&q).(int)
		}
	}
	return int64(ans)
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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;，两者长度都是&nbsp;<code>n</code>&nbsp;，再给你一个正整数&nbsp;<code>k</code>&nbsp;。你必须从&nbsp;<code>nums1</code>&nbsp;中选一个长度为 <code>k</code>&nbsp;的 <strong>子序列</strong>&nbsp;对应的下标。</p>

<p>对于选择的下标&nbsp;<code>i<sub>0</sub></code>&nbsp;，<code>i<sub>1</sub></code>&nbsp;，...，&nbsp;<code>i<sub>k - 1</sub></code>&nbsp;，你的&nbsp;<strong>分数</strong>&nbsp;定义如下：</p>

<ul>
	<li><code>nums1</code>&nbsp;中下标对应元素求和，乘以&nbsp;<code>nums2</code>&nbsp;中下标对应元素的&nbsp;<strong>最小值</strong>&nbsp;。</li>
	<li>用公式表示：&nbsp;<code>(nums1[i<sub>0</sub>] + nums1[i<sub>1</sub>] +...+ nums1[i<sub>k - 1</sub>]) * min(nums2[i<sub>0</sub>] , nums2[i<sub>1</sub>], ... ,nums2[i<sub>k - 1</sub>])</code>&nbsp;。</li>
</ul>

<p>请你返回 <strong>最大</strong>&nbsp;可能的分数。</p>

<p>一个数组的 <strong>子序列</strong>&nbsp;下标是集合&nbsp;<code>{0, 1, ..., n-1}</code>&nbsp;中删除若干元素得到的剩余集合，也可以不删除任何元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
<b>输出：</b>12
<b>解释：</b>
四个可能的子序列分数为：
- 选择下标 0 ，1 和 2 ，得到分数 (1+3+3) * min(2,1,3) = 7 。
- 选择下标 0 ，1 和 3 ，得到分数 (1+3+2) * min(2,1,4) = 6 。
- 选择下标 0 ，2 和 3 ，得到分数 (1+3+2) * min(2,3,4) = 12 。
- 选择下标 1 ，2 和 3 ，得到分数 (3+3+2) * min(1,3,4) = 8 。
所以最大分数为 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
<b>输出：</b>30
<b>解释：</b>
选择下标 2 最优：nums1[2] * nums2[2] = 3 * 10 = 30 是最大可能分数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 优先队列（小根堆）

将 `nums2` 与 `nums1` 按照 `nums2` 降序排序，然后从前往后遍历，维护一个小根堆，堆中存储 `nums1` 中的元素，堆中元素个数不超过 $k$ 个，同时维护一个变量 $s$，表示堆中元素的和，遍历过程中不断更新答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums1` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = sorted(zip(nums2, nums1), reverse=True)
        q = []
        ans = s = 0
        for a, b in nums:
            s += b
            heappush(q, b)
            if len(q) == k:
                ans = max(ans, s * a)
                s -= heappop(q)
        return ans
```

#### Java

```java
class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] nums = new int[n][2];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1[i], nums2[i]};
        }
        Arrays.sort(nums, (a, b) -> b[1] - a[1]);
        long ans = 0, s = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            s += nums[i][0];
            q.offer(nums[i][0]);
            if (q.size() == k) {
                ans = Math.max(ans, s * nums[i][1]);
                s -= q.poll();
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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = {-nums2[i], nums1[i]};
        }
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int>> q;
        long long ans = 0, s = 0;
        for (auto& [a, b] : nums) {
            s += b;
            q.push(b);
            if (q.size() == k) {
                ans = max(ans, s * -a);
                s -= q.top();
                q.pop();
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(nums1 []int, nums2 []int, k int) int64 {
	type pair struct{ a, b int }
	nums := []pair{}
	for i, a := range nums1 {
		b := nums2[i]
		nums = append(nums, pair{a, b})
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i].b > nums[j].b })
	q := hp{}
	var ans, s int
	for _, e := range nums {
		a, b := e.a, e.b
		s += a
		heap.Push(&q, a)
		if q.Len() == k {
			ans = max(ans, s*b)
			s -= heap.Pop(&q).(int)
		}
	}
	return int64(ans)
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

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2543. 判断一个点是否可以到达](https://leetcode.cn/problems/check-if-point-is-reachable){#2543}

{{< tabs "2543" >}}

{{% tab "python" %}}
```python
class Solution:
    def isReachable(self, targetX: int, targetY: int) -> bool:
        x = gcd(targetX, targetY)
        return x & (x - 1) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isReachable(int targetX, int targetY) {
        int x = gcd(targetX, targetY);
        return (x & (x - 1)) == 0;
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
    bool isReachable(int targetX, int targetY) {
        int x = gcd(targetX, targetY);
        return (x & (x - 1)) == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isReachable(targetX int, targetY int) bool {
	x := gcd(targetX, targetY)
	return x&(x-1) == 0
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isReachable(targetX: number, targetY: number): boolean {
    const x = gcd(targetX, targetY);
    return (x & (x - 1)) === 0;
}

function gcd(a: number, b: number): number {
    return b == 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个无穷大的网格图。一开始你在&nbsp;<code>(1, 1)</code>&nbsp;，你需要通过有限步移动到达点&nbsp;<code>(targetX, targetY)</code>&nbsp;。</p>

<p><b>每一步</b>&nbsp;，你可以从点&nbsp;<code>(x, y)</code>&nbsp;移动到以下点之一：</p>

<ul>
	<li><code>(x, y - x)</code></li>
	<li><code>(x - y, y)</code></li>
	<li><code>(2 * x, y)</code></li>
	<li><code>(x, 2 * y)</code></li>
</ul>

<p>给你两个整数&nbsp;<code>targetX</code> 和&nbsp;<code>targetY</code>&nbsp;，分别表示你最后需要到达点的 X 和 Y 坐标。如果你可以从&nbsp;<code>(1, 1)</code>&nbsp;出发到达这个点，请你返回<code>true</code> ，否则返回<em>&nbsp;</em><code>false</code><em>&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>targetX = 6, targetY = 9
<b>输出：</b>false
<b>解释：</b>没法从 (1,1) 出发到达 (6,9) ，所以返回 false 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>targetX = 4, targetY = 7
<b>输出：</b>true
<b>解释：</b>你可以按照以下路径到达：(1,1) -&gt; (1,2) -&gt; (1,4) -&gt; (1,8) -&gt; (1,7) -&gt; (2,7) -&gt; (4,7) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= targetX, targetY&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们注意到，前两种移动方式不会改变横、纵坐标的最大公约数，而后两种移动方式可以使得横、纵坐标的最大公约数乘上 $2$ 的幂次。也就是说，最后的横、纵坐标的最大公约数必须是 $2$ 的幂次。最大公约数不是 $2$ 的幂次，那么就无法到达。

接下来，我们证明，任意满足 $gcd(x, y)=2^k$ 的 $(x, y)$ 均可达。

我们将移动方式反转一下，即从终点往回走，那么 $(x, y)$ 可以移动到 $(x, x+y)$, $(x+y, y)$, $(\frac{x}{2}, y)$ 和 $(x, \frac{y}{2})$。

只要 $x$ 或 $y$ 是偶数，我们就将其除以 $2$，直到 $x$ 和 $y$ 均为奇数。此时，若 $x \neq y$，不妨设 $x \gt y$，那么 $\frac{x+y}{2} \lt x$。由于 $x+y$ 是偶数，我们可以通过操作从 $(x, y)$ 移动到 $(x+y, y)$，再移动到 $(\frac{x+y}{2}, y)$。也就是说，我们总能让 $x$ 和 $y$ 不断变小。循环结束时，如果 $x=y=1$，说明可以到达。

时间复杂度 $O(\log(\min(targetX, targetY)))$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isReachable(self, targetX: int, targetY: int) -> bool:
        x = gcd(targetX, targetY)
        return x & (x - 1) == 0
```

#### Java

```java
class Solution {
    public boolean isReachable(int targetX, int targetY) {
        int x = gcd(targetX, targetY);
        return (x & (x - 1)) == 0;
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
    bool isReachable(int targetX, int targetY) {
        int x = gcd(targetX, targetY);
        return (x & (x - 1)) == 0;
    }
};
```

#### Go

```go
func isReachable(targetX int, targetY int) bool {
	x := gcd(targetX, targetY)
	return x&(x-1) == 0
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function isReachable(targetX: number, targetY: number): boolean {
    const x = gcd(targetX, targetY);
    return (x & (x - 1)) === 0;
}

function gcd(a: number, b: number): number {
    return b == 0 ? a : gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2544. 交替数字和](https://leetcode.cn/problems/alternating-digit-sum){#2544}

{{< tabs "2544" >}}

{{% tab "python" %}}
```python
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        ans, sign = 0, 1
        for c in str(n):
            x = int(c)
            ans += sign * x
            sign *= -1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : String.valueOf(n).toCharArray()) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
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
    int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : to_string(n)) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func alternateDigitSum(n int) (ans int) {
	sign := 1
	for _, c := range strconv.Itoa(n) {
		x := int(c - '0')
		ans += sign * x
		sign *= -1
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function alternateDigitSum(n: number): number {
    let ans = 0;
    let sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n = Math.floor(n / 10);
    }
    return ans * -sign;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn alternate_digit_sum(n: i32) -> i32 {
        let mut ans = 0;
        let mut sign = 1;

        for c in format!("{}", n).chars() {
            let x = c.to_digit(10).unwrap() as i32;
            ans += x * sign;
            sign *= -1;
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int alternateDigitSum(int n) {
    int ans = 0;
    int sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n /= 10;
    }
    return ans * -sign;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> 。<code>n</code> 中的每一位数字都会按下述规则分配一个符号：</p>

<ul>
	<li><strong>最高有效位</strong> 上的数字分配到 <strong>正</strong> 号。</li>
	<li>剩余每位上数字的符号都与其相邻数字相反。</li>
</ul>

<p>返回所有数字及其对应符号的和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 521
<strong>输出：</strong>4
<strong>解释：</strong>(+5) + (-2) + (+1) = 4</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 111
<strong>输出：</strong>1
<strong>解释：</strong>(+1) + (-1) + (+1) = 1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 886996
<strong>输出：</strong>0
<strong>解释：</strong>(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接根据题目描述模拟即可。

我们定义一个初始符号 $sign=1$，然后从最高有效位开始，每次取出一位数字 $x$，与 $sign$ 相乘，将结果加到答案中，然后将 $sign$ 取反，继续处理下一位数字，直到处理完所有数字。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为给定数字。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        return sum((-1) ** i * int(x) for i, x in enumerate(str(n)))
```

#### Java

```java
class Solution {
    public int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : String.valueOf(n).toCharArray()) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : to_string(n)) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
};
```

#### Go

```go
func alternateDigitSum(n int) (ans int) {
	sign := 1
	for _, c := range strconv.Itoa(n) {
		x := int(c - '0')
		ans += sign * x
		sign *= -1
	}
	return
}
```

#### TypeScript

```ts
function alternateDigitSum(n: number): number {
    let ans = 0;
    let sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n = Math.floor(n / 10);
    }
    return ans * -sign;
}
```

#### Rust

```rust
impl Solution {
    pub fn alternate_digit_sum(mut n: i32) -> i32 {
        let mut ans = 0;
        let mut sign = 1;
        while n != 0 {
            ans += (n % 10) * sign;
            sign = -sign;
            n /= 10;
        }
        ans * -sign
    }
}
```

#### C

```c
int alternateDigitSum(int n) {
    int ans = 0;
    int sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n /= 10;
    }
    return ans * -sign;
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
    def alternateDigitSum(self, n: int) -> int:
        ans, sign = 0, 1
        for c in str(n):
            x = int(c)
            ans += sign * x
            sign *= -1
        return ans
```

#### Rust

```rust
impl Solution {
    pub fn alternate_digit_sum(n: i32) -> i32 {
        let mut ans = 0;
        let mut sign = 1;

        for c in format!("{}", n).chars() {
            let x = c.to_digit(10).unwrap() as i32;
            ans += x * sign;
            sign *= -1;
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

# [2545. 根据第 K 场考试的分数排序](https://leetcode.cn/problems/sort-the-students-by-their-kth-score){#2545}

{{< tabs "2545" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        return sorted(score, key=lambda x: -x[k])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> b[k] - a[k]);
        return score;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ranges::sort(score, [k](const auto& a, const auto& b) { return a[k] > b[k]; });
        return score;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortTheStudents(score [][]int, k int) [][]int {
	sort.Slice(score, func(i, j int) bool { return score[i][k] > score[j][k] })
	return score
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortTheStudents(score: number[][], k: number): number[][] {
    return score.sort((a, b) => b[k] - a[k]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_the_students(mut score: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k = k as usize;
        score.sort_by(|a, b| b[k].cmp(&a[k]));
        score
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>班里有 <code>m</code> 位学生，共计划组织 <code>n</code> 场考试。给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的整数矩阵 <code>score</code> ，其中每一行对应一位学生，而 <code>score[i][j]</code> 表示第 <code>i</code> 位学生在第 <code>j</code> 场考试取得的分数。矩阵 <code>score</code> 包含的整数&nbsp;<strong>互不相同</strong>&nbsp;。</p>

<p>另给你一个整数 <code>k</code> 。请你按第 <code>k</code> 场考试分数从高到低完成对这些学生（矩阵中的行）的排序。</p>

<p>返回排序后的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2545.Sort%20the%20Students%20by%20Their%20Kth%20Score/images/example1.png" style="width: 600px; height: 136px;" /></p>

<pre>
<strong>输入：</strong>score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
<strong>输出：</strong>[[7,5,11,2],[10,6,9,1],[4,8,3,15]]
<strong>解释：</strong>在上图中，S 表示学生，E 表示考试。
- 下标为 1 的学生在第 2 场考试取得的分数为 11 ，这是考试的最高分，所以 TA 需要排在第一。
- 下标为 0 的学生在第 2 场考试取得的分数为 9 ，这是考试的第二高分，所以 TA 需要排在第二。
- 下标为 2 的学生在第 2 场考试取得的分数为 3 ，这是考试的最低分，所以 TA 需要排在第三。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2545.Sort%20the%20Students%20by%20Their%20Kth%20Score/images/example2.png" style="width: 486px; height: 121px;" /></p>

<pre>
<strong>输入：</strong>score = [[3,4],[5,6]], k = 0
<strong>输出：</strong>[[5,6],[3,4]]
<strong>解释：</strong>在上图中，S 表示学生，E 表示考试。
- 下标为 1 的学生在第 0 场考试取得的分数为 5 ，这是考试的最高分，所以 TA 需要排在第一。
- 下标为 0 的学生在第 0 场考试取得的分数为 3 ，这是考试的最低分，所以 TA 需要排在第二。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == score.length</code></li>
	<li><code>n == score[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 250</code></li>
	<li><code>1 &lt;= score[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>score</code> 由 <strong>不同</strong> 的整数组成</li>
	<li><code>0 &lt;= k &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们直接将 $\textit{score}$ 按照第 $k$ 列的分数从大到小排序，然后返回即可。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(\log m)$。其中 $m$ 为 $\textit{score}$ 的行数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        return sorted(score, key=lambda x: -x[k])
```

#### Java

```java
class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> b[k] - a[k]);
        return score;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ranges::sort(score, [k](const auto& a, const auto& b) { return a[k] > b[k]; });
        return score;
    }
};
```

#### Go

```go
func sortTheStudents(score [][]int, k int) [][]int {
	sort.Slice(score, func(i, j int) bool { return score[i][k] > score[j][k] })
	return score
}
```

#### TypeScript

```ts
function sortTheStudents(score: number[][], k: number): number[][] {
    return score.sort((a, b) => b[k] - a[k]);
}
```

#### Rust

```rust
impl Solution {
    pub fn sort_the_students(mut score: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k = k as usize;
        score.sort_by(|a, b| b[k].cmp(&a[k]));
        score
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2546. 执行逐位运算使字符串相等](https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal){#2546}

{{< tabs "2546" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeStringsEqual(self, s: str, target: str) -> bool:
        return ("1" in s) == ("1" in target)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean makeStringsEqual(String s, String target) {
        return s.contains("1") == target.contains("1");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        auto a = count(s.begin(), s.end(), '1') > 0;
        auto b = count(target.begin(), target.end(), '1') > 0;
        return a == b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeStringsEqual(s string, target string) bool {
	return strings.Contains(s, "1") == strings.Contains(target, "1")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeStringsEqual(s: string, target: string): boolean {
    return s.includes('1') === target.includes('1');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn make_strings_equal(s: String, target: String) -> bool {
        s.contains('1') == target.contains('1')
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool makeStringsEqual(char* s, char* target) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') {
            count++;
            break;
        }
    }
    for (int i = 0; target[i]; i++) {
        if (target[i] == '1') {
            count++;
            break;
        }
    }
    return !(count & 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong> 开始的 <strong>二元</strong> 字符串 <code>s</code> 和 <code>target</code> ，两个字符串的长度均为 <code>n</code> 。你可以对 <code>s</code> 执行下述操作 <strong>任意</strong> 次：</p>

<ul>
	<li>选择两个 <strong>不同</strong> 的下标 <code>i</code> 和 <code>j</code> ，其中 <code>0 &lt;= i, j &lt; n</code> 。</li>
	<li>同时，将 <code>s[i]</code> 替换为 (<code>s[i]</code> <strong>OR</strong> <code>s[j]</code>) ，<code>s[j]</code> 替换为 (<code>s[i]</code> <strong>XOR</strong> <code>s[j]</code>) 。</li>
</ul>

<p>例如，如果 <code>s = "0110"</code> ，你可以选择 <code>i = 0</code> 和 <code>j = 2</code>，然后同时将 <code>s[0]</code> 替换为 (<code>s[0]</code> <strong>OR</strong> <code>s[2]</code> = <code>0</code> <strong>OR</strong> <code>1</code> = <code>1</code>)，并将 <code>s[2]</code> 替换为 (<code>s[0]</code> <strong>XOR</strong> <code>s[2]</code> = <code>0</code> <strong>XOR</strong> <code>1</code> = <code>1</code>)，最终得到 <code>s = "1110"</code> 。</p>

<p>如果可以使 <code>s</code> 等于 <code>target</code> ，返回 <code>true</code> ，否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "1010", target = "0110"
<strong>输出：</strong>true
<strong>解释：</strong>可以执行下述操作：
- 选择 i = 2 和 j = 0 ，得到 s = "<em><strong>0</strong></em>0<em><strong>1</strong></em>0".
- 选择 i = 2 和 j = 1 ，得到 s = "0<em><strong>11</strong></em>0".
可以使 s 等于 target ，返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "11", target = "00"
<strong>输出：</strong>false
<strong>解释：</strong>执行任意次操作都无法使 s 等于 target 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s.length == target.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 和 <code>target</code> 仅由数字 <code>0</code> 和 <code>1</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们注意到 $1$ 其实是数字转换的“工具”，因此只要两个字符串中都有 $1$ 或者都没有 $1$，那么就可以通过操作使得两个字符串相等。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeStringsEqual(self, s: str, target: str) -> bool:
        return ("1" in s) == ("1" in target)
```

#### Java

```java
class Solution {
    public boolean makeStringsEqual(String s, String target) {
        return s.contains("1") == target.contains("1");
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        auto a = count(s.begin(), s.end(), '1') > 0;
        auto b = count(target.begin(), target.end(), '1') > 0;
        return a == b;
    }
};
```

#### Go

```go
func makeStringsEqual(s string, target string) bool {
	return strings.Contains(s, "1") == strings.Contains(target, "1")
}
```

#### TypeScript

```ts
function makeStringsEqual(s: string, target: string): boolean {
    return s.includes('1') === target.includes('1');
}
```

#### Rust

```rust
impl Solution {
    pub fn make_strings_equal(s: String, target: String) -> bool {
        s.contains('1') == target.contains('1')
    }
}
```

#### C

```c
bool makeStringsEqual(char* s, char* target) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') {
            count++;
            break;
        }
    }
    for (int i = 0; target[i]; i++) {
        if (target[i] == '1') {
            count++;
            break;
        }
    }
    return !(count & 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2547. 拆分数组的最小代价](https://leetcode.cn/problems/minimum-cost-to-split-an-array){#2547}

{{< tabs "2547" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, nums: List[int], k: int) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            cnt = Counter()
            one = 0
            ans = inf
            for j in range(i, n):
                cnt[nums[j]] += 1
                if cnt[nums[j]] == 1:
                    one += 1
                elif cnt[nums[j]] == 2:
                    one -= 1
                ans = min(ans, k + j - i + 1 - one + dfs(j + 1))
            return ans

        n = len(nums)
        return dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[] f;
    private int[] nums;
    private int n, k;

    public int minCost(int[] nums, int k) {
        n = nums.length;
        this.k = k;
        this.nums = nums;
        f = new Integer[n];
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int[] cnt = new int[n];
        int one = 0;
        int ans = 1 << 30;
        for (int j = i; j < n; ++j) {
            int x = ++cnt[nums[j]];
            if (x == 1) {
                ++one;
            } else if (x == 2) {
                --one;
            }
            ans = Math.min(ans, k + j - i + 1 - one + dfs(j + 1));
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
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        memset(f, 0, sizeof f);
        function<int(int)> dfs = [&](int i) {
            if (i >= n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            int cnt[n];
            memset(cnt, 0, sizeof cnt);
            int one = 0;
            int ans = 1 << 30;
            for (int j = i; j < n; ++j) {
                int x = ++cnt[nums[j]];
                if (x == 1) {
                    ++one;
                } else if (x == 2) {
                    --one;
                }
                ans = min(ans, k + j - i + 1 - one + dfs(j + 1));
            }
            return f[i] = ans;
        };
        return dfs(0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(nums []int, k int) int {
	n := len(nums)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		ans, one := 1<<30, 0
		cnt := make([]int, n)
		for j := i; j < n; j++ {
			cnt[nums[j]]++
			x := cnt[nums[j]]
			if x == 1 {
				one++
			} else if x == 2 {
				one--
			}
			ans = min(ans, k+j-i+1-one+dfs(j+1))
		}
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(nums: number[], k: number): number {
    const n = nums.length;
    const f = new Array(n).fill(0);
    const dfs = (i: number) => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        const cnt = new Array(n).fill(0);
        let one = 0;
        let ans = 1 << 30;
        for (let j = i; j < n; ++j) {
            const x = ++cnt[nums[j]];
            if (x == 1) {
                ++one;
            } else if (x == 2) {
                --one;
            }
            ans = Math.min(ans, k + j - i + 1 - one + dfs(j + 1));
        }
        f[i] = ans;
        return f[i];
    };
    return dfs(0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>将数组拆分成一些非空子数组。拆分的 <strong>代价</strong> 是每个子数组中的 <strong>重要性</strong> 之和。</p>

<p>令 <code>trimmed(subarray)</code> 作为子数组的一个特征，其中所有仅出现一次的数字将会被移除。</p>

<ul>
	<li>例如，<code>trimmed([3,1,2,4,3,4]) = [3,4,3,4]</code> 。</li>
</ul>

<p>子数组的 <strong>重要性</strong> 定义为 <code>k + trimmed(subarray).length</code> 。</p>

<ul>
	<li>例如，如果一个子数组是 <code>[1,2,3,3,3,4,4]</code> ，<code>trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4]</code> 。这个子数组的重要性就是 <code>k + 5</code> 。</li>
</ul>

<p>找出并返回拆分 <code>nums</code> 的所有可行方案中的最小代价。</p>

<p><strong>子数组</strong> 是数组的一个连续 <strong>非空</strong> 元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,1,3,3], k = 2
<strong>输出：</strong>8
<strong>解释：</strong>将 nums 拆分成两个子数组：[1,2], [1,2,1,3,3]
[1,2] 的重要性是 2 + (0) = 2 。
[1,2,1,3,3] 的重要性是 2 + (2 + 2) = 6 。
拆分的代价是 2 + 6 = 8 ，可以证明这是所有可行的拆分方案中的最小代价。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,1], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>将 nums 拆分成两个子数组：[1,2], [1,2,1] 。
[1,2] 的重要性是 2 + (0) = 2 。
[1,2,1] 的重要性是 2 + (2) = 4 。
拆分的代价是 2 + 4 = 6 ，可以证明这是所有可行的拆分方案中的最小代价。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,1], k = 5
<strong>输出：</strong>10
<strong>解释：</strong>将 nums 拆分成一个子数组：[1,2,1,2,1].
[1,2,1,2,1] 的重要性是 5 + (3 + 2) = 10 。
拆分的代价是 10 ，可以证明这是所有可行的拆分方案中的最小代价。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示从下标 $i$ 开始拆分的最小代价。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i \ge n$，说明已经拆分到了数组末尾，此时返回 $0$。
-   否则，我们枚举子数组的末尾 $j$，过程中用一个数组或哈希表 `cnt` 统计子数组中每个数字出现的次数，用一个变量 `one` 统计子数组中出现次数为 $1$ 的数字的个数。那么子数组的重要性就是 $k + j - i + 1 - one$，拆分的代价就是 $k + j - i + 1 - one + dfs(j + 1)$。我们枚举所有的 $j$，取其中的最小值作为 $dfs(i)$ 的返回值。

过程中，我们可以使用记忆化搜索，即使用一个数组 $f$ 记忆化函数 $dfs(i)$ 的返回值，避免重复计算。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, nums: List[int], k: int) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            cnt = Counter()
            one = 0
            ans = inf
            for j in range(i, n):
                cnt[nums[j]] += 1
                if cnt[nums[j]] == 1:
                    one += 1
                elif cnt[nums[j]] == 2:
                    one -= 1
                ans = min(ans, k + j - i + 1 - one + dfs(j + 1))
            return ans

        n = len(nums)
        return dfs(0)
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] nums;
    private int n, k;

    public int minCost(int[] nums, int k) {
        n = nums.length;
        this.k = k;
        this.nums = nums;
        f = new Integer[n];
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int[] cnt = new int[n];
        int one = 0;
        int ans = 1 << 30;
        for (int j = i; j < n; ++j) {
            int x = ++cnt[nums[j]];
            if (x == 1) {
                ++one;
            } else if (x == 2) {
                --one;
            }
            ans = Math.min(ans, k + j - i + 1 - one + dfs(j + 1));
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        memset(f, 0, sizeof f);
        function<int(int)> dfs = [&](int i) {
            if (i >= n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            int cnt[n];
            memset(cnt, 0, sizeof cnt);
            int one = 0;
            int ans = 1 << 30;
            for (int j = i; j < n; ++j) {
                int x = ++cnt[nums[j]];
                if (x == 1) {
                    ++one;
                } else if (x == 2) {
                    --one;
                }
                ans = min(ans, k + j - i + 1 - one + dfs(j + 1));
            }
            return f[i] = ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func minCost(nums []int, k int) int {
	n := len(nums)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		ans, one := 1<<30, 0
		cnt := make([]int, n)
		for j := i; j < n; j++ {
			cnt[nums[j]]++
			x := cnt[nums[j]]
			if x == 1 {
				one++
			} else if x == 2 {
				one--
			}
			ans = min(ans, k+j-i+1-one+dfs(j+1))
		}
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function minCost(nums: number[], k: number): number {
    const n = nums.length;
    const f = new Array(n).fill(0);
    const dfs = (i: number) => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        const cnt = new Array(n).fill(0);
        let one = 0;
        let ans = 1 << 30;
        for (let j = i; j < n; ++j) {
            const x = ++cnt[nums[j]];
            if (x == 1) {
                ++one;
            } else if (x == 2) {
                --one;
            }
            ans = Math.min(ans, k + j - i + 1 - one + dfs(j + 1));
        }
        f[i] = ans;
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2548. 填满背包的最大价格 🔒](https://leetcode.cn/problems/maximum-price-to-fill-a-bag){#2548}

{{< tabs "2548" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPrice(self, items: List[List[int]], capacity: int) -> float:
        ans = 0
        for p, w in sorted(items, key=lambda x: x[1] / x[0]):
            v = min(w, capacity)
            ans += v / w * p
            capacity -= v
        return -1 if capacity else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double maxPrice(int[][] items, int capacity) {
        Arrays.sort(items, (a, b) -> a[1] * b[0] - a[0] * b[1]);
        double ans = 0;
        for (var e : items) {
            int p = e[0], w = e[1];
            int v = Math.min(w, capacity);
            ans += v * 1.0 / w * p;
            capacity -= v;
        }
        return capacity > 0 ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        sort(items.begin(), items.end(), [&](const auto& a, const auto& b) { return a[1] * b[0] < a[0] * b[1]; });
        double ans = 0;
        for (auto& e : items) {
            int p = e[0], w = e[1];
            int v = min(w, capacity);
            ans += v * 1.0 / w * p;
            capacity -= v;
        }
        return capacity > 0 ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPrice(items [][]int, capacity int) (ans float64) {
	sort.Slice(items, func(i, j int) bool { return items[i][1]*items[j][0] < items[i][0]*items[j][1] })
	for _, e := range items {
		p, w := e[0], e[1]
		v := min(w, capacity)
		ans += float64(v) / float64(w) * float64(p)
		capacity -= v
	}
	if capacity > 0 {
		return -1
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPrice(items: number[][], capacity: number): number {
    items.sort((a, b) => a[1] * b[0] - a[0] * b[1]);
    let ans = 0;
    for (const [p, w] of items) {
        const v = Math.min(w, capacity);
        ans += (v / w) * p;
        capacity -= v;
    }
    return capacity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二维整数数组 <code>items</code> ，其中 <code>items[i] = [price<sub>i</sub>, weight<sub>i</sub>]</code> 表示第 <code>i</code> 个物品的价格和重量。</p>

<p>还给定一个 <strong>正</strong> 整数容量 <code>capacity</code> 。</p>

<p>每个物品可以分成两个部分，比率为 <code>part1</code> 和 <code>part2</code> ，其中 <code>part1 + part2 == 1</code> 。</p>

<ul>
	<li>第一个物品的重量是 <code>weighti * part1</code> ，价格是 <code>pricei * part1</code> 。</li>
	<li>同样，第二个物品的重量是 <code>weighti * part2</code>&nbsp;，价格是 <code>pricei * part2</code>&nbsp;。</li>
</ul>

<p>使用给定的物品，返回填满容量为 <code>capacity</code> 的背包所需的 <strong>最大总价格</strong> 。如果无法填满背包，则返回 <code>-1</code> 。与实际答案的差距在&nbsp;<code>10<sup>-5</sup></code>&nbsp;以内的 <strong>实际答案</strong> 将被视为接受。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>items = [[50,1],[10,8]], capacity = 5
<b>输出：</b>55.00000
<b>解释：</b>
我们将第二个物品分成两个部分，part1 = 0.5，part2 = 0.5。 
第一个物品的价格和重量分别为 5 和 4 。同样地，第二个物品的价格和重量也是 5 和 4 。 
经过操作后，数组 items 变为 [[50,1],[5,4],[5,4]] 。 
为了填满容量为 5 的背包，我们取价格为 50 的第一个元素和价格为 5 的第二个元素。 
可以证明，55.0 是我们可以达到的最大总价值。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>items = [[100,30]], capacity = 50
<b>输出：</b>-1.00000
<b>解释：</b>无法用给定的物品装满背包。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= items.length &lt;= 10<sup>5</sup></code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>1 &lt;= price<sub>i</sub>, weight<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= capacity &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们将物品按照单位价格从大到小排序，然后依次取出物品，直到背包装满。

若最后背包未装满，则返回 $-1$，否则返回总价格。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为物品数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPrice(self, items: List[List[int]], capacity: int) -> float:
        ans = 0
        for p, w in sorted(items, key=lambda x: x[1] / x[0]):
            v = min(w, capacity)
            ans += v / w * p
            capacity -= v
        return -1 if capacity else ans
```

#### Java

```java
class Solution {
    public double maxPrice(int[][] items, int capacity) {
        Arrays.sort(items, (a, b) -> a[1] * b[0] - a[0] * b[1]);
        double ans = 0;
        for (var e : items) {
            int p = e[0], w = e[1];
            int v = Math.min(w, capacity);
            ans += v * 1.0 / w * p;
            capacity -= v;
        }
        return capacity > 0 ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        sort(items.begin(), items.end(), [&](const auto& a, const auto& b) { return a[1] * b[0] < a[0] * b[1]; });
        double ans = 0;
        for (auto& e : items) {
            int p = e[0], w = e[1];
            int v = min(w, capacity);
            ans += v * 1.0 / w * p;
            capacity -= v;
        }
        return capacity > 0 ? -1 : ans;
    }
};
```

#### Go

```go
func maxPrice(items [][]int, capacity int) (ans float64) {
	sort.Slice(items, func(i, j int) bool { return items[i][1]*items[j][0] < items[i][0]*items[j][1] })
	for _, e := range items {
		p, w := e[0], e[1]
		v := min(w, capacity)
		ans += float64(v) / float64(w) * float64(p)
		capacity -= v
	}
	if capacity > 0 {
		return -1
	}
	return
}
```

#### TypeScript

```ts
function maxPrice(items: number[][], capacity: number): number {
    items.sort((a, b) => a[1] * b[0] - a[0] * b[1]);
    let ans = 0;
    for (const [p, w] of items) {
        const v = Math.min(w, capacity);
        ans += (v / w) * p;
        capacity -= v;
    }
    return capacity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2549. 统计桌面上的不同数字](https://leetcode.cn/problems/count-distinct-numbers-on-board){#2549}

{{< tabs "2549" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctIntegers(self, n: int) -> int:
        return max(1, n - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distinctIntegers(int n) {
        return Math.max(1, n - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distinctIntegers(int n) {
        return max(1, n - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctIntegers(n int) int {
	return max(1, n-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distinctIntegers(n: number): number {
    return Math.max(1, n - 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn distinct_integers(n: i32) -> i32 {
        (1).max(n - 1)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> ，开始时，它放在桌面上。在 <code>10<sup>9</sup></code> 天内，每天都要执行下述步骤：</p>

<ul>
	<li>对于出现在桌面上的每个数字 <code>x</code> ，找出符合 <code>1 &lt;= i &lt;= n</code> 且满足 <code>x % i == 1</code> 的所有数字 <code>i</code> 。</li>
	<li>然后，将这些数字放在桌面上。</li>
</ul>

<p>返回在 <code>10<sup>9</sup></code> 天之后，出现在桌面上的 <strong>不同</strong> 整数的数目。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>一旦数字放在桌面上，则会一直保留直到结束。</li>
	<li><code>%</code> 表示取余运算。例如，<code>14 % 3</code> 等于 <code>2</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>4
<strong>解释：</strong>最开始，5 在桌面上。 
第二天，2 和 4 也出现在桌面上，因为 5 % 2 == 1 且 5 % 4 == 1 。 
再过一天 3 也出现在桌面上，因为 4 % 3 == 1 。 
在十亿天结束时，桌面上的不同数字有 2 、3 、4 、5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3 
<strong>输出：</strong>2
<strong>解释：</strong> 
因为 3 % 2 == 1 ，2 也出现在桌面上。 
在十亿天结束时，桌面上的不同数字只有两个：2 和 3 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

由于每一次对桌面上的数字 $n$ 进行操作，会使得数字 $n-1$ 也出现在桌面上，因此最终桌面上的数字为 $[2,...n]$，共 $n-1$ 个数字。

注意到 $n$ 可能为 $1$，因此需要特判。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctIntegers(self, n: int) -> int:
        return max(1, n - 1)
```

#### Java

```java
class Solution {
    public int distinctIntegers(int n) {
        return Math.max(1, n - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distinctIntegers(int n) {
        return max(1, n - 1);
    }
};
```

#### Go

```go
func distinctIntegers(n int) int {
	return max(1, n-1)
}
```

#### TypeScript

```ts
function distinctIntegers(n: number): number {
    return Math.max(1, n - 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn distinct_integers(n: i32) -> i32 {
        (1).max(n - 1)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
