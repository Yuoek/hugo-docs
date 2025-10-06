---
title: "2605_FormSmallestNumberFromTwoDigitArrays"
date: 2025-10-06T00:42:37+08:00
weight: 2605
tags: [数组, 哈希表, 枚举]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2605. 从两个数字数组里生成最小数字](https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays)

[English Version](../en/2605-05/2605_FormSmallestNumberFromTwoDigitArrays)

## 题目描述

<!-- description:start -->

给你两个只包含 1 到 9 之间数字的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，每个数组中的元素 <strong>互不相同</strong>&nbsp;，请你返回 <strong>最小</strong> 的数字，两个数组都 <strong>至少</strong> 包含这个数字的某个数位。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [4,1,3], nums2 = [5,7]
<b>输出：</b>15
<b>解释：</b>数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [3,5,2,6], nums2 = [3,1,7]
<b>输出：</b>3
<b>解释：</b>数字 3 的数位 3 在两个数组中都出现了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 9</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 9</code></li>
	<li>每个数组中，元素 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举

我们观察发现，如果数组 $nums1$ 和 $nums2$ 中有相同的数字，那么相同数字中的最小值一定是最小的数字。否则我们取 $nums1$ 中的数字 $a$ 和 $nums2$ 中的数字 $b$，将 $a$ 和 $b$ 拼接成两个数字，取其中较小的数字即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表或数组 + 枚举

我们可以用哈希表或数组记录数组 $nums1$ 和 $nums2$ 中的数字，然后枚举 $1 \sim 9$，如果 $i$ 在两个数组中都出现了，那么 $i$ 就是最小的数字。否则我们取 $nums1$ 中的数字 $a$ 和 $nums2$ 中的数字 $b$，将 $a$ 和 $b$ 拼接成两个数字，取其中较小的数字即可。

时间复杂度 $(m + n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度；而 $C$ 是数组 $nums1$ 和 $nums2$ 中数字的范围，本题中 $C = 10$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：位运算

由于数字的范围是 $1 \sim 9$，我们可以用一个长度为 $10$ 的二进制数来表示数组 $nums1$ 和 $nums2$ 中的数字。我们用 $mask1$ 表示数组 $nums1$ 中的数字，用 $mask2$ 表示数组 $nums2$ 中的数字。

如果 $mask1$ 和 $mask2$ 进行按位与得到的数字 $mask$ 不等于 $0$，那么我们提取 $mask$ 中最后一位 $1$ 所在的位置，即为最小的数字。

否则，我们分别提取 $mask1$ 和 $mask2$ 中最后一位 $1$ 所在的位置，分别记为 $a$ 和 $b$，那么最小的数字就是 $min(a \times 10 + b, b \times 10 + a)$。

时间复杂度 $O(m + n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

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
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        mask1 = mask2 = 0
        for x in nums1:
            mask1 |= 1 << x
        for x in nums2:
            mask2 |= 1 << x
        mask = mask1 & mask2
        if mask:
            return (mask & -mask).bit_length() - 1
        a = (mask1 & -mask1).bit_length() - 1
        b = (mask2 & -mask2).bit_length() - 1
        return min(a * 10 + b, b * 10 + a)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask != 0) {
            return Integer.numberOfTrailingZeros(mask);
        }
        int a = Integer.numberOfTrailingZeros(mask1);
        int b = Integer.numberOfTrailingZeros(mask2);
        return Math.min(a * 10 + b, b * 10 + a);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask) {
            return __builtin_ctz(mask);
        }
        int a = __builtin_ctz(mask1);
        int b = __builtin_ctz(mask2);
        return min(a * 10 + b, b * 10 + a);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumber(nums1 []int, nums2 []int) int {
	var mask1, mask2 uint
	for _, x := range nums1 {
		mask1 |= 1 << x
	}
	for _, x := range nums2 {
		mask2 |= 1 << x
	}
	if mask := mask1 & mask2; mask != 0 {
		return bits.TrailingZeros(mask)
	}
	a, b := bits.TrailingZeros(mask1), bits.TrailingZeros(mask2)
	return min(a*10+b, b*10+a)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNumber(nums1: number[], nums2: number[]): number {
    let mask1: number = 0;
    let mask2: number = 0;
    for (const x of nums1) {
        mask1 |= 1 << x;
    }
    for (const x of nums2) {
        mask2 |= 1 << x;
    }
    const mask = mask1 & mask2;
    if (mask !== 0) {
        return numberOfTrailingZeros(mask);
    }
    const a = numberOfTrailingZeros(mask1);
    const b = numberOfTrailingZeros(mask2);
    return Math.min(a * 10 + b, b * 10 + a);
}

function numberOfTrailingZeros(i: number): number {
    let y = 0;
    if (i === 0) {
        return 32;
    }
    let n = 31;
    y = i << 16;
    if (y != 0) {
        n = n - 16;
        i = y;
    }
    y = i << 8;
    if (y != 0) {
        n = n - 8;
        i = y;
    }
    y = i << 4;
    if (y != 0) {
        n = n - 4;
        i = y;
    }
    y = i << 2;
    if (y != 0) {
        n = n - 2;
        i = y;
    }
    return n - ((i << 1) >>> 31);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_number(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut h1: HashMap<i32, bool> = HashMap::new();

        for &n in &nums1 {
            h1.insert(n, true);
        }

        let mut h2: HashMap<i32, bool> = HashMap::new();
        for &n in &nums2 {
            h2.insert(n, true);
        }

        let mut a = 0;
        let mut b = 0;
        for i in 1..10 {
            if h1.contains_key(&i) && h2.contains_key(&i) {
                return i;
            }

            if a == 0 && h1.contains_key(&i) {
                a = i;
            }

            if b == 0 && h2.contains_key(&i) {
                b = i;
            }
        }

        std::cmp::min(a * 10 + b, b * 10 + a)
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        mask1 = mask2 = 0
        for x in nums1:
            mask1 |= 1 << x
        for x in nums2:
            mask2 |= 1 << x
        mask = mask1 & mask2
        if mask:
            return (mask & -mask).bit_length() - 1
        a = (mask1 & -mask1).bit_length() - 1
        b = (mask2 & -mask2).bit_length() - 1
        return min(a * 10 + b, b * 10 + a)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask != 0) {
            return Integer.numberOfTrailingZeros(mask);
        }
        int a = Integer.numberOfTrailingZeros(mask1);
        int b = Integer.numberOfTrailingZeros(mask2);
        return Math.min(a * 10 + b, b * 10 + a);
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
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mask1 = 0, mask2 = 0;
        for (int x : nums1) {
            mask1 |= 1 << x;
        }
        for (int x : nums2) {
            mask2 |= 1 << x;
        }
        int mask = mask1 & mask2;
        if (mask) {
            return __builtin_ctz(mask);
        }
        int a = __builtin_ctz(mask1);
        int b = __builtin_ctz(mask2);
        return min(a * 10 + b, b * 10 + a);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}