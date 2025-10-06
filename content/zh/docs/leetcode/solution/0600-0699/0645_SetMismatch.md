---
title: "0645_SetMismatch"
date: 2025-10-06T00:42:37+08:00
weight: 0645
tags: [位运算, 数组, 哈希表, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [645. 错误的集合](https://leetcode.cn/problems/set-mismatch)

[English Version](../en/0645-45/0645_SetMismatch)

## 题目描述

<!-- description:start -->

<p>集合 <code>s</code> 包含从 <code>1</code> 到 <code>n</code> 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 <strong>丢失了一个数字</strong> 并且 <strong>有一个数字重复</strong> 。</p>

<p>给定一个数组 <code>nums</code> 代表了集合 <code>S</code> 发生错误后的结果。</p>

<p>请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,4]
<strong>输出：</strong>[2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数学

我们用 $s_1$ 表示 $[1,..n]$ 所有数字的和，用 $s_2$ 表示数组 $nums$ 去重后的数字和，用 $s$ 表示数组 $nums$ 的数字和。

那么 $s - s_2$ 就是重复的数字，而 $s_1 - s_2$ 就是缺失的数字。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。需要额外的空间对数组去重。

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

### 方法二：哈希表

我们也可以一种更加直观的方法，直接用哈希表 $cnt$ 统计数组 $nums$ 中每个数字出现的次数。

接下来遍历 $x \in [1, n]$，如果 $cnt[x] = 2$，那么 $x$ 就是重复的数字，如果 $cnt[x] = 0$，那么 $x$ 就是缺失的数字。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。

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

根据异或运算的性质，对于整数 $x$，有 $x \oplus x = 0$ 以及 $x \oplus 0 = x$，因此我们对数组 $nums$ 中的所有元素以及 $i \in [1, n]$ 的所有数字进行异或运算，可以消除出现两次的数字，最终只留下缺失的数字和重复的数字的异或结果，即 $xs = a \oplus b$。

由于这两个数字不相等，因此异或结果中至少存在一位为 $1$。我们通过 $lowbit$ 运算找到异或结果中最低位的 $1$，然后将数组 $nums$ 中所有数字以及 $i \in [1, n]$ 的所有数字按照该位是否为 $1$ 分为两组，这样两个数字就被分到了不同的组中。其中一组数字的异或结果为 $a$，另一组数字的异或结果为 $b$。那么这两个数字就是我们要找的答案。

接下来我们只需要判断 $a$ 和 $b$ 哪个数字是重复的数字，哪个数字是缺失的数字即可。因此，遍历数组 $nums$，对于遍历到的数字 $x$，如果 $x=a$，那么 $a$ 就是重复的数字，返回 $[a, b]$，否则遍历结束，返回 $[b, a]$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$，仅使用常数大小的额外空间。

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
    def findErrorNums(self, nums: List[int]) -> List[int]:
        xs = 0
        for i, x in enumerate(nums, 1):
            xs ^= i ^ x
        a = 0
        lb = xs & -xs
        for i, x in enumerate(nums, 1):
            if i & lb:
                a ^= i
            if x & lb:
                a ^= x
        b = xs ^ a
        for x in nums:
            if x == a:
                return [a, b]
        return [b, a]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & lb) > 0) {
                a ^= i;
            }
            if ((nums[i - 1] & lb) > 0) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return new int[] {a, b};
            }
        }
        return new int[] {b, a};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & lb) {
                a ^= i;
            }
            if (nums[i - 1] & lb) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return {a, b};
            }
        }
        return {b, a};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findErrorNums(nums []int) []int {
	xs := 0
	for i, x := range nums {
		xs ^= x ^ (i + 1)
	}
	lb := xs & -xs
	a := 0
	for i, x := range nums {
		if (i+1)&lb != 0 {
			a ^= (i + 1)
		}
		if x&lb != 0 {
			a ^= x
		}
	}
	b := xs ^ a
	for _, x := range nums {
		if x == a {
			return []int{a, b}
		}
	}
	return []int{b, a}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findErrorNums(nums: number[]): number[] {
    const n = nums.length;
    let xs = 0;
    for (let i = 1; i <= n; ++i) {
        xs ^= i ^ nums[i - 1];
    }
    const lb = xs & -xs;
    let a = 0;
    for (let i = 1; i <= n; ++i) {
        if (i & lb) {
            a ^= i;
        }
        if (nums[i - 1] & lb) {
            a ^= nums[i - 1];
        }
    }
    const b = xs ^ a;
    return nums.includes(a) ? [a, b] : [b, a];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let mut xs = 0;
        for (i, x) in nums.iter().enumerate() {
            xs ^= ((i + 1) as i32) ^ x;
        }
        let mut a = 0;
        let lb = xs & -xs;
        for (i, x) in nums.iter().enumerate() {
            if (((i + 1) as i32) & lb) != 0 {
                a ^= (i + 1) as i32;
            }
            if (*x & lb) != 0 {
                a ^= *x;
            }
        }
        let b = xs ^ a;
        for x in nums.iter() {
            if *x == a {
                return vec![a, b];
            }
        }
        vec![b, a]
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        xs = 0
        for i, x in enumerate(nums, 1):
            xs ^= i ^ x
        a = 0
        lb = xs & -xs
        for i, x in enumerate(nums, 1):
            if i & lb:
                a ^= i
            if x & lb:
                a ^= x
        b = xs ^ a
        for x in nums:
            if x == a:
                return [a, b]
        return [b, a]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & lb) > 0) {
                a ^= i;
            }
            if ((nums[i - 1] & lb) > 0) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return new int[] {a, b};
            }
        }
        return new int[] {b, a};
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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & lb) {
                a ^= i;
            }
            if (nums[i - 1] & lb) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return {a, b};
            }
        }
        return {b, a};
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}