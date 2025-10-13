---
title: "0041_缺失的第一个正数"
date: 2025-10-08T18:34:13+08:00
weight: 5
tags: [动态规划, 单调栈, 双指针, 哈希表, 回溯, 字符串, 排序, 数学, 数组, 栈, 模拟, 矩阵, 贪心, 递归]
---

{{< markmap >}}
### [0041_缺失的第一个正数](#41)
#### [数组](#41)
#### [哈希表](#41)
### [0042_接雨水](#42)
#### [栈](#42)
#### [数组](#42)
#### [双指针](#42)
#### [动态规划](#42)
#### [单调栈](#42)
### [0043_字符串相乘](#43)
#### [数学](#43)
#### [字符串](#43)
#### [模拟](#43)
### [0044_通配符匹配](#44)
#### [贪心](#44)
#### [递归](#44)
#### [字符串](#44)
#### [动态规划](#44)
### [0045_跳跃游戏 II](#45)
#### [贪心](#45)
#### [数组](#45)
#### [动态规划](#45)
### [0046_全排列](#46)
#### [数组](#46)
#### [回溯](#46)
### [0047_全排列 II](#47)
#### [数组](#47)
#### [回溯](#47)
#### [排序](#47)
### [0048_旋转图像](#48)
#### [数组](#48)
#### [数学](#48)
#### [矩阵](#48)
### [0049_字母异位词分组](#49)
#### [数组](#49)
#### [哈希表](#49)
#### [字符串](#49)
#### [排序](#49)
### [0050_Pow(x, n)](#50)
#### [递归](#50)
#### [数学](#50)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0041_缺失的第一个正数
___
#### 数组
___
#### 哈希表
---
### 0042_接雨水
___
#### 栈
___
#### 数组
___
#### 双指针
___
#### 动态规划
___
#### 单调栈
---
### 0043_字符串相乘
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0044_通配符匹配
___
#### 贪心
___
#### 递归
___
#### 字符串
___
#### 动态规划
---
### 0045_跳跃游戏 II
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 0046_全排列
___
#### 数组
___
#### 回溯
---
### 0047_全排列 II
___
#### 数组
___
#### 回溯
___
#### 排序
---
### 0048_旋转图像
___
#### 数组
___
#### 数学
___
#### 矩阵
---
### 0049_字母异位词分组
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0050_Pow(x, n)
___
#### 递归
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 回溯 | 字符串 |
| 排序 | 数学 | 数组 |
| 栈 | 模拟 | 矩阵 |
| 贪心 | 递归 |  |

# [41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive){#41}

{{< tabs "41" >}}

{{% tab "python" %}}
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func firstMissingPositive(nums []int) int {
	n := len(nums)
	for i := range nums {
		for 0 < nums[i] && nums[i] <= n && nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}
	for i, x := range nums {
		if x != i+1 {
			return i + 1
		}
	}
	return n + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function firstMissingPositive(nums: number[]): number {
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[i] !== nums[nums[i] - 1]) {
            const j = nums[i] - 1;
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        for i in 0..n {
            while nums[i] > 0 && nums[i] <= n as i32 && nums[i] != nums[nums[i] as usize - 1] {
                let j = nums[i] as usize - 1;
                nums.swap(i, j);
            }
        }
        for i in 0..n {
            if nums[i] != (i + 1) as i32 {
                return (i + 1) as i32;
            }
        }
        return (n + 1) as i32;
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                Swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void Swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
            int j = nums[i] - 1;
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        $n = count($nums);
        for ($i = 0; $i < $n; $i++) {
            while ($nums[$i] >= 1 && $nums[$i] <= $n && $nums[$i] != $nums[$nums[$i] - 1]) {
                $j = $nums[$i] - 1;
                $t = $nums[$i];
                $nums[$i] = $nums[$j];
                $nums[$j] = $t;
            }
        }
        for ($i = 0; $i < $n; $i++) {
            if ($nums[$i] != $i + 1) {
                return $i + 1;
            }
        }
        return $n + 1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个未排序的整数数组 <code>nums</code> ，请你找出其中没有出现的最小的正整数。</p>
请你实现时间复杂度为 <code>O(n)</code> 并且只使用常数级别额外空间的解决方案。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,0]
<strong>输出：</strong>3
<strong>解释：</strong>范围 [1,2] 中的数字都在数组中。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,-1,1]
<strong>输出：</strong>2
<strong>解释：</strong>1 在数组中，但 2 没有。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,8,9,11,12]
<strong>输出：</strong>1
<strong>解释：</strong>最小的正数 1 没有出现。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：原地交换

我们假设数组 $nums$ 长度为 $n$，那么最小的正整数一定在 $[1, .., n + 1]$ 之间。我们可以遍历数组，将数组中的每个数 $x$ 交换到它应该在的位置上，即 $x$ 应该在的位置为 $x - 1$。如果 $x$ 不在 $[1, n + 1]$ 之间，那么我们就不用管它。

遍历结束后，我们再遍历数组，如果 $i+1$ 不等于 $nums[i]$，那么 $i+1$ 就是我们要找的最小的正整数。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
```

#### Java

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```

#### Go

```go
func firstMissingPositive(nums []int) int {
	n := len(nums)
	for i := range nums {
		for 0 < nums[i] && nums[i] <= n && nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}
	for i, x := range nums {
		if x != i+1 {
			return i + 1
		}
	}
	return n + 1
}
```

#### TypeScript

```ts
function firstMissingPositive(nums: number[]): number {
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[i] !== nums[nums[i] - 1]) {
            const j = nums[i] - 1;
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        for i in 0..n {
            while nums[i] > 0 && nums[i] <= n as i32 && nums[i] != nums[nums[i] as usize - 1] {
                let j = nums[i] as usize - 1;
                nums.swap(i, j);
            }
        }
        for i in 0..n {
            if nums[i] != (i + 1) as i32 {
                return (i + 1) as i32;
            }
        }
        return (n + 1) as i32;
    }
}
```

#### C#

```cs
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                Swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void Swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C

```c
int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
            int j = nums[i] - 1;
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        $n = count($nums);
        for ($i = 0; $i < $n; $i++) {
            while ($nums[$i] >= 1 && $nums[$i] <= $n && $nums[$i] != $nums[$nums[$i] - 1]) {
                $j = $nums[$i] - 1;
                $t = $nums[$i];
                $nums[$i] = $nums[$j];
                $nums[$j] = $t;
            }
        }
        for ($i = 0; $i < $n; $i++) {
            if ($nums[$i] != $i + 1) {
                return $i + 1;
            }
        }
        return $n + 1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water){#42}

{{< tabs "42" >}}

{{% tab "python" %}}
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [height[0]] * n
        right = [height[-1]] * n
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i])
            right[n - i - 1] = max(right[n - i], height[n - i - 1])
        return sum(min(l, r) - h for l, r, h in zip(left, right, height))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.max(left[i - 1], height[i]);
            right[n - i - 1] = Math.max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.min(left[i], right[i]) - height[i];
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
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
            right[n - i - 1] = max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func trap(height []int) (ans int) {
	n := len(height)
	left := make([]int, n)
	right := make([]int, n)
	left[0], right[n-1] = height[0], height[n-1]
	for i := 1; i < n; i++ {
		left[i] = max(left[i-1], height[i])
		right[n-i-1] = max(right[n-i], height[n-i-1])
	}
	for i, h := range height {
		ans += min(left[i], right[i]) - h
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function trap(height: number[]): number {
    const n = height.length;
    const left: number[] = new Array(n).fill(height[0]);
    const right: number[] = new Array(n).fill(height[n - 1]);
    for (let i = 1; i < n; ++i) {
        left[i] = Math.max(left[i - 1], height[i]);
        right[n - i - 1] = Math.max(right[n - i], height[n - i - 1]);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += Math.min(left[i], right[i]) - height[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut left: Vec<i32> = vec![0; n];
        let mut right: Vec<i32> = vec![0; n];

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        // Initialize the left & right vector
        for i in 1..n {
            left[i] = std::cmp::max(left[i - 1], height[i]);
            right[n - i - 1] = std::cmp::max(right[n - i], height[n - i - 1]);
        }

        let mut ans = 0;

        // Calculate the ans
        for i in 0..n {
            ans += std::cmp::min(left[i], right[i]) - height[i];
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Trap(int[] height) {
        int n = height.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.Max(left[i - 1], height[i]);
            right[n - i - 1] = Math.Max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.Min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer[] $height
     * @return integer
     */

    function trap($height) {
        $n = count($height);

        if ($n == 0) {
            return 0;
        }

        $left = 0;
        $right = $n - 1;
        $leftMax = 0;
        $rightMax = 0;
        $ans = 0;

        while ($left < $right) {
            if ($height[$left] < $height[$right]) {
                if ($height[$left] > $leftMax) {
                    $leftMax = $height[$left];
                } else {
                    $ans += $leftMax - $height[$left];
                }
                $left++;
            } else {
                if ($height[$right] > $rightMax) {
                    $rightMax = $height[$right];
                } else {
                    $ans += $rightMax - $height[$right];
                }
                $right--;
            }
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定&nbsp;<code>n</code> 个非负整数表示每个宽度为 <code>1</code> 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0042.Trapping%20Rain%20Water/images/rainwatertrap.png" style="height: 161px; width: 412px;" /></p>

<pre>
<strong>输入：</strong>height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>输出：</strong>6
<strong>解释：</strong>上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>height = [4,2,0,3,2,5]
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $left[i]$ 表示下标 $i$ 位置及其左边的最高柱子的高度，定义 $right[i]$ 表示下标 $i$ 位置及其右边的最高柱子的高度。那么下标 $i$ 位置能接的雨水量为 $\min(left[i], right[i]) - height[i]$。我们遍历数组，计算出 $left[i]$ 和 $right[i]$，最后答案为 $\sum_{i=0}^{n-1} \min(left[i], right[i]) - height[i]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [height[0]] * n
        right = [height[-1]] * n
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i])
            right[n - i - 1] = max(right[n - i], height[n - i - 1])
        return sum(min(l, r) - h for l, r, h in zip(left, right, height))
```

#### Java

```java
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.max(left[i - 1], height[i]);
            right[n - i - 1] = Math.max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
            right[n - i - 1] = max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};
```

#### Go

```go
func trap(height []int) (ans int) {
	n := len(height)
	left := make([]int, n)
	right := make([]int, n)
	left[0], right[n-1] = height[0], height[n-1]
	for i := 1; i < n; i++ {
		left[i] = max(left[i-1], height[i])
		right[n-i-1] = max(right[n-i], height[n-i-1])
	}
	for i, h := range height {
		ans += min(left[i], right[i]) - h
	}
	return
}
```

#### TypeScript

```ts
function trap(height: number[]): number {
    const n = height.length;
    const left: number[] = new Array(n).fill(height[0]);
    const right: number[] = new Array(n).fill(height[n - 1]);
    for (let i = 1; i < n; ++i) {
        left[i] = Math.max(left[i - 1], height[i]);
        right[n - i - 1] = Math.max(right[n - i], height[n - i - 1]);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += Math.min(left[i], right[i]) - height[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut left: Vec<i32> = vec![0; n];
        let mut right: Vec<i32> = vec![0; n];

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        // Initialize the left & right vector
        for i in 1..n {
            left[i] = std::cmp::max(left[i - 1], height[i]);
            right[n - i - 1] = std::cmp::max(right[n - i], height[n - i - 1]);
        }

        let mut ans = 0;

        // Calculate the ans
        for i in 0..n {
            ans += std::cmp::min(left[i], right[i]) - height[i];
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int Trap(int[] height) {
        int n = height.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.Max(left[i - 1], height[i]);
            right[n - i - 1] = Math.Max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.Min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer[] $height
     * @return integer
     */

    function trap($height) {
        $n = count($height);

        if ($n == 0) {
            return 0;
        }

        $left = 0;
        $right = $n - 1;
        $leftMax = 0;
        $rightMax = 0;
        $ans = 0;

        while ($left < $right) {
            if ($height[$left] < $height[$right]) {
                if ($height[$left] > $leftMax) {
                    $leftMax = $height[$left];
                } else {
                    $ans += $leftMax - $height[$left];
                }
                $left++;
            } else {
                if ($height[$right] > $rightMax) {
                    $rightMax = $height[$right];
                } else {
                    $ans += $rightMax - $height[$right];
                }
                $right--;
            }
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [43. 字符串相乘](https://leetcode.cn/problems/multiply-strings){#43}

{{< tabs "43" >}}

{{% tab "python" %}}
```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        m, n = len(num1), len(num2)
        arr = [0] * (m + n)
        for i in range(m - 1, -1, -1):
            a = int(num1[i])
            for j in range(n - 1, -1, -1):
                b = int(num2[j])
                arr[i + j + 1] += a * b
        for i in range(m + n - 1, 0, -1):
            arr[i - 1] += arr[i] // 10
            arr[i] %= 10
        i = 0 if arr[0] else 1
        return "".join(str(x) for x in arr[i:])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String multiply(String num1, String num2) {
        if ("0".equals(num1) || "0".equals(num2)) {
            return "0";
        }
        int m = num1.length(), n = num2.length();
        int[] arr = new int[m + n];
        for (int i = m - 1; i >= 0; --i) {
            int a = num1.charAt(i) - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2.charAt(j) - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.length - 1; i > 0; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] == 0 ? 1 : 0;
        StringBuilder ans = new StringBuilder();
        for (; i < arr.length; ++i) {
            ans.append(arr[i]);
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n);
        for (int i = m - 1; i >= 0; --i) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.size() - 1; i; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] ? 0 : 1;
        string ans;
        for (; i < arr.size(); ++i) {
            ans += '0' + arr[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	m, n := len(num1), len(num2)
	arr := make([]int, m+n)
	for i := m - 1; i >= 0; i-- {
		a := int(num1[i] - '0')
		for j := n - 1; j >= 0; j-- {
			b := int(num2[j] - '0')
			arr[i+j+1] += a * b
		}
	}
	for i := len(arr) - 1; i > 0; i-- {
		arr[i-1] += arr[i] / 10
		arr[i] %= 10
	}
	i := 0
	if arr[0] == 0 {
		i = 1
	}
	ans := []byte{}
	for ; i < len(arr); i++ {
		ans = append(ans, byte('0'+arr[i]))
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function multiply(num1: string, num2: string): string {
    if (num1 === '0' || num2 === '0') {
        return '0';
    }
    const m: number = num1.length;
    const n: number = num2.length;
    const arr: number[] = Array(m + n).fill(0);
    for (let i: number = m - 1; i >= 0; i--) {
        const a: number = +num1[i];
        for (let j: number = n - 1; j >= 0; j--) {
            const b: number = +num2[j];
            arr[i + j + 1] += a * b;
        }
    }
    for (let i: number = arr.length - 1; i > 0; i--) {
        arr[i - 1] += Math.floor(arr[i] / 10);
        arr[i] %= 10;
    }
    let i: number = 0;
    while (i < arr.length && arr[i] === 0) {
        i++;
    }
    return arr.slice(i).join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return String::from("0");
        }
        let (num1, num2) = (num1.as_bytes(), num2.as_bytes());
        let (n, m) = (num1.len(), num2.len());
        let mut res = vec![];
        for i in 0..n {
            let a = num1[n - i - 1] - b'0';
            let mut sum = 0;
            let mut j = 0;
            while j < m || sum != 0 {
                if i + j == res.len() {
                    res.push(0);
                }
                let b = num2.get(m - j - 1).unwrap_or(&b'0') - b'0';
                sum += a * b + res[i + j];
                res[i + j] = sum % 10;
                sum /= 10;
                j += 1;
            }
        }
        res.into_iter()
            .rev()
            .map(|v| char::from(v + b'0'))
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string Multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.Length;
        int n = num2.Length;
        int[] arr = new int[m + n];

        for (int i = m - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }

        for (int i = arr.Length - 1; i > 0; i--) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }

        int index = 0;
        while (index < arr.Length && arr[index] == 0) {
            index++;
        }

        StringBuilder ans = new StringBuilder();
        for (; index < arr.Length; index++) {
            ans.Append(arr[index]);
        }

        return ans.ToString();
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $num1
     * @param string $num2
     * @return string
     */

    function multiply($num1, $num2) {
        $length1 = strlen($num1);
        $length2 = strlen($num2);
        $product = array_fill(0, $length1 + $length2, 0);

        for ($i = $length1 - 1; $i >= 0; $i--) {
            for ($j = $length2 - 1; $j >= 0; $j--) {
                $digit1 = intval($num1[$i]);
                $digit2 = intval($num2[$j]);

                $temp = $digit1 * $digit2 + $product[$i + $j + 1];
                $product[$i + $j + 1] = $temp % 10;

                $carry = intval($temp / 10);
                $product[$i + $j] += $carry;
            }
        }
        $result = implode('', $product);
        $result = ltrim($result, '0');
        return $result === '' ? '0' : $result;
    }
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun multiply(num1: String, num2: String): String {
        if (num1 == "0" || num2 == "0") return "0"

        val chars_1 = num1.toCharArray().reversedArray()
        val chars_2 = num2.toCharArray().reversedArray()

        val result = mutableListOf<Int>()

        chars_1.forEachIndexed { i, c1 ->
            val multiplier_1 = c1 - '0'
            var over = 0
            var index = 0

            fun sum(product: Int = 0): Unit {
                while (index >= result.size) {
                    result.add(0)
                }
                val value = product + over + result[index]
                result[index] = value % 10
                over = value / 10
                return
            }

            chars_2.forEachIndexed { j, c2 ->
                index = i + j
                val multiplier_2 = c2 - '0'
                sum(multiplier_1 * multiplier_2)
            }

            while (over > 0) {
                index++
                sum()
            }
        }

        return result.reversed().joinToString("")
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function (num1, num2) {
    if (num1 === '0' || num2 === '0') return '0';

    const result = Array(num1.length + num2.length).fill(0);
    const code_0 = '0'.charCodeAt(0);

    const num1_len = num1.length;
    const num2_len = num2.length;

    for (let i = 0; i < num1_len; ++i) {
        const multiplier_1 = num1.charCodeAt(num1_len - i - 1) - code_0;
        for (let j = 0; j < num2_len; ++j) {
            const multiplier_2 = num2.charCodeAt(num2_len - j - 1) - code_0;
            result[i + j] += multiplier_1 * multiplier_2;
        }
    }

    result.reduce((carry, value, index) => {
        const sum = carry + value;
        result[index] = sum % 10;
        return (sum / 10) | 0;
    }, 0);

    return result
        .slice(0, result.findLastIndex(d => d !== 0) + 1)
        .reverse()
        .join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个以字符串形式表示的非负整数&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>，返回&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>&nbsp;的乘积，它们的乘积也表示为字符串形式。</p>

<p><strong>注意：</strong>不能使用任何内置的 BigInteger 库或直接将输入转换为整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> num1 = "2", num2 = "3"
<strong>输出:</strong> "6"</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> num1 = "123", num2 = "456"
<strong>输出:</strong> "56088"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 200</code></li>
	<li><code>num1</code>&nbsp;和 <code>num2</code>&nbsp;只能由数字组成。</li>
	<li><code>num1</code>&nbsp;和 <code>num2</code>&nbsp;都不包含任何前导零，除了数字0本身。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学乘法模拟

假设 $num1$ 和 $num2$ 的长度分别为 $m$ 和 $n$，则它们的乘积的长度最多为 $m + n$。

证明如下：

-   如果 $num1$ 和 $num2$ 都取最小值，那么它们的乘积为 ${10}^{m - 1} \times {10}^{n - 1} = {10}^{m + n - 2}$，长度为 $m + n - 1$。
-   如果 $num1$ 和 $num2$ 都取最大值，那么它们的乘积为 $({10}^m - 1) \times ({10}^n - 1) = {10}^{m + n} - {10}^m - {10}^n + 1$，长度为 $m + n$。

因此，我们可以申请一个长度为 $m + n$ 的数组，用于存储乘积的每一位。

从低位到高位，依次计算乘积的每一位，最后将数组转换为字符串即可。

注意判断最高位是否为 $0$，如果是，则去掉。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为 $num1$ 和 $num2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        m, n = len(num1), len(num2)
        arr = [0] * (m + n)
        for i in range(m - 1, -1, -1):
            a = int(num1[i])
            for j in range(n - 1, -1, -1):
                b = int(num2[j])
                arr[i + j + 1] += a * b
        for i in range(m + n - 1, 0, -1):
            arr[i - 1] += arr[i] // 10
            arr[i] %= 10
        i = 0 if arr[0] else 1
        return "".join(str(x) for x in arr[i:])
```

#### Java

```java
class Solution {
    public String multiply(String num1, String num2) {
        if ("0".equals(num1) || "0".equals(num2)) {
            return "0";
        }
        int m = num1.length(), n = num2.length();
        int[] arr = new int[m + n];
        for (int i = m - 1; i >= 0; --i) {
            int a = num1.charAt(i) - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2.charAt(j) - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.length - 1; i > 0; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] == 0 ? 1 : 0;
        StringBuilder ans = new StringBuilder();
        for (; i < arr.length; ++i) {
            ans.append(arr[i]);
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n);
        for (int i = m - 1; i >= 0; --i) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.size() - 1; i; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] ? 0 : 1;
        string ans;
        for (; i < arr.size(); ++i) {
            ans += '0' + arr[i];
        }
        return ans;
    }
};
```

#### Go

```go
func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	m, n := len(num1), len(num2)
	arr := make([]int, m+n)
	for i := m - 1; i >= 0; i-- {
		a := int(num1[i] - '0')
		for j := n - 1; j >= 0; j-- {
			b := int(num2[j] - '0')
			arr[i+j+1] += a * b
		}
	}
	for i := len(arr) - 1; i > 0; i-- {
		arr[i-1] += arr[i] / 10
		arr[i] %= 10
	}
	i := 0
	if arr[0] == 0 {
		i = 1
	}
	ans := []byte{}
	for ; i < len(arr); i++ {
		ans = append(ans, byte('0'+arr[i]))
	}
	return string(ans)
}
```

#### TypeScript

```ts
function multiply(num1: string, num2: string): string {
    if (num1 === '0' || num2 === '0') {
        return '0';
    }
    const m: number = num1.length;
    const n: number = num2.length;
    const arr: number[] = Array(m + n).fill(0);
    for (let i: number = m - 1; i >= 0; i--) {
        const a: number = +num1[i];
        for (let j: number = n - 1; j >= 0; j--) {
            const b: number = +num2[j];
            arr[i + j + 1] += a * b;
        }
    }
    for (let i: number = arr.length - 1; i > 0; i--) {
        arr[i - 1] += Math.floor(arr[i] / 10);
        arr[i] %= 10;
    }
    let i: number = 0;
    while (i < arr.length && arr[i] === 0) {
        i++;
    }
    return arr.slice(i).join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return String::from("0");
        }
        let (num1, num2) = (num1.as_bytes(), num2.as_bytes());
        let (n, m) = (num1.len(), num2.len());
        let mut res = vec![];
        for i in 0..n {
            let a = num1[n - i - 1] - b'0';
            let mut sum = 0;
            let mut j = 0;
            while j < m || sum != 0 {
                if i + j == res.len() {
                    res.push(0);
                }
                let b = num2.get(m - j - 1).unwrap_or(&b'0') - b'0';
                sum += a * b + res[i + j];
                res[i + j] = sum % 10;
                sum /= 10;
                j += 1;
            }
        }
        res.into_iter()
            .rev()
            .map(|v| char::from(v + b'0'))
            .collect()
    }
}
```

#### C#

```cs
public class Solution {
    public string Multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.Length;
        int n = num2.Length;
        int[] arr = new int[m + n];

        for (int i = m - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }

        for (int i = arr.Length - 1; i > 0; i--) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }

        int index = 0;
        while (index < arr.Length && arr[index] == 0) {
            index++;
        }

        StringBuilder ans = new StringBuilder();
        for (; index < arr.Length; index++) {
            ans.Append(arr[index]);
        }

        return ans.ToString();
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param string $num1
     * @param string $num2
     * @return string
     */

    function multiply($num1, $num2) {
        $length1 = strlen($num1);
        $length2 = strlen($num2);
        $product = array_fill(0, $length1 + $length2, 0);

        for ($i = $length1 - 1; $i >= 0; $i--) {
            for ($j = $length2 - 1; $j >= 0; $j--) {
                $digit1 = intval($num1[$i]);
                $digit2 = intval($num2[$j]);

                $temp = $digit1 * $digit2 + $product[$i + $j + 1];
                $product[$i + $j + 1] = $temp % 10;

                $carry = intval($temp / 10);
                $product[$i + $j] += $carry;
            }
        }
        $result = implode('', $product);
        $result = ltrim($result, '0');
        return $result === '' ? '0' : $result;
    }
}
```

#### Kotlin

```kotlin
class Solution {
    fun multiply(num1: String, num2: String): String {
        if (num1 == "0" || num2 == "0") return "0"

        val chars_1 = num1.toCharArray().reversedArray()
        val chars_2 = num2.toCharArray().reversedArray()

        val result = mutableListOf<Int>()

        chars_1.forEachIndexed { i, c1 ->
            val multiplier_1 = c1 - '0'
            var over = 0
            var index = 0

            fun sum(product: Int = 0): Unit {
                while (index >= result.size) {
                    result.add(0)
                }
                val value = product + over + result[index]
                result[index] = value % 10
                over = value / 10
                return
            }

            chars_2.forEachIndexed { j, c2 ->
                index = i + j
                val multiplier_2 = c2 - '0'
                sum(multiplier_1 * multiplier_2)
            }

            while (over > 0) {
                index++
                sum()
            }
        }

        return result.reversed().joinToString("")
    }
}
```

#### JavaScript

```js
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function (num1, num2) {
    if (num1 === '0' || num2 === '0') return '0';

    const result = Array(num1.length + num2.length).fill(0);
    const code_0 = '0'.charCodeAt(0);

    const num1_len = num1.length;
    const num2_len = num2.length;

    for (let i = 0; i < num1_len; ++i) {
        const multiplier_1 = num1.charCodeAt(num1_len - i - 1) - code_0;
        for (let j = 0; j < num2_len; ++j) {
            const multiplier_2 = num2.charCodeAt(num2_len - j - 1) - code_0;
            result[i + j] += multiplier_1 * multiplier_2;
        }
    }

    result.reduce((carry, value, index) => {
        const sum = carry + value;
        result[index] = sum % 10;
        return (sum / 10) | 0;
    }, 0);

    return result
        .slice(0, result.findLastIndex(d => d !== 0) + 1)
        .reverse()
        .join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [44. 通配符匹配](https://leetcode.cn/problems/wildcard-matching){#44}

{{< tabs "44" >}}

{{% tab "python" %}}
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for j in range(1, n + 1):
            if p[j - 1] == "*":
                f[0][j] = f[0][j - 1]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == "*":
                    f[i][j] = f[i - 1][j] or f[i][j - 1] or f[i - 1][j - 1]
                else:
                    f[i][j] = f[i - 1][j - 1] and (
                        p[j - 1] == "?" or s[i - 1] == p[j - 1]
                    )
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] f = new boolean[m + 1][n + 1];
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p.charAt(j - 1) == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p.charAt(j - 1) == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1]
                        && (p.charAt(j - 1) == '?' || s.charAt(i - 1) == p.charAt(j - 1));
                }
            }
        }
        return f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool f[m + 1][n + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isMatch(s string, p string) bool {
	m, n := len(s), len(p)
	f := make([][]bool, m+1)
	for i := range f {
		f[i] = make([]bool, n+1)
	}
	f[0][0] = true
	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			f[0][j] = f[0][j-1]
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				f[i][j] = f[i-1][j] || f[i][j-1] || f[i-1][j-1]
			} else {
				f[i][j] = f[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1])
			}
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isMatch(s: string, p: string): boolean {
    const m: number = s.length;
    const n: number = p.length;
    const f: boolean[][] = Array.from({ length: m + 1 }, () =>
        Array.from({ length: n + 1 }, () => false),
    );
    f[0][0] = true;
    for (let j = 1; j <= n; ++j) {
        if (p.charAt(j - 1) === '*') {
            f[0][j] = f[0][j - 1];
        }
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (p[j - 1] === '*') {
                f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
            } else {
                f[i][j] = f[i - 1][j - 1] && (p[j - 1] === '?' || s[i - 1] === p[j - 1]);
            }
        }
    }
    return f[m][n];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private bool?[,] f;
    private char[] s;
    private char[] p;
    private int m;
    private int n;

    public bool IsMatch(string s, string p) {
        this.s = s.ToCharArray();
        this.p = p.ToCharArray();
        m = s.Length;
        n = p.Length;
        f = new bool?[m, n];
        return Dfs(0, 0);
    }

    private bool Dfs(int i, int j) {
        if (i >= m) {
            return j >= n || (p[j] == '*' && Dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i, j] != null) {
            return f[i, j].Value;
        }
        if (p[j] == '*') {
            f[i, j] = Dfs(i + 1, j) || Dfs(i + 1, j + 1) || Dfs(i, j + 1);
        } else {
            f[i, j] = (p[j] == '?' || s[i] == p[j]) && Dfs(i + 1, j + 1);
        }
        return f[i, j].Value;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param string $s
     * @param string $p
     * @return boolean
     */

    function isMatch($s, $p) {
        $lengthS = strlen($s);
        $lengthP = strlen($p);
        $dp = [];
        for ($i = 0; $i <= $lengthS; $i++) {
            $dp[$i] = array_fill(0, $lengthP + 1, false);
        }
        $dp[0][0] = true;

        for ($i = 1; $i <= $lengthP; $i++) {
            if ($p[$i - 1] == '*') {
                $dp[0][$i] = $dp[0][$i - 1];
            }
        }
        for ($i = 1; $i <= $lengthS; $i++) {
            for ($j = 1; $j <= $lengthP; $j++) {
                if ($p[$j - 1] == '?' || $s[$i - 1] == $p[$j - 1]) {
                    $dp[$i][$j] = $dp[$i - 1][$j - 1];
                } elseif ($p[$j - 1] == '*') {
                    $dp[$i][$j] = $dp[$i][$j - 1] || $dp[$i - 1][$j];
                }
            }
        }
        return $dp[$lengthS][$lengthP];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<div class="title__3Vvk">给你一个输入字符串 (<code>s</code>) 和一个字符模式 (<code>p</code>) ，请你实现一个支持 <code>'?'</code> 和 <code>'*'</code> 匹配规则的通配符匹配：</div>

<ul>
	<li class="title__3Vvk"><code>'?'</code> 可以匹配任何单个字符。</li>
	<li class="title__3Vvk"><code>'*'</code> 可以匹配任意字符序列（包括空字符序列）。</li>
</ul>

<div class="original__bRMd">
<div>
<p>判定匹配成功的充要条件是：字符模式必须能够 <strong>完全匹配</strong> 输入字符串（而不是部分匹配）。</p>
</div>
</div>
&nbsp;

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aa", p = "a"
<strong>输出：</strong>false
<strong>解释：</strong>"a" 无法匹配 "aa" 整个字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aa", p = "*"
<strong>输出：</strong>true
<strong>解释：</strong>'*' 可以匹配任意字符串。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "cb", p = "?a"
<strong>输出：</strong>false
<strong>解释：</strong>'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length, p.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>p</code> 仅由小写英文字母、<code>'?'</code> 或 <code>'*'</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从字符串 $s$ 的第 $i$ 个字符开始和字符串 $p$ 的第 $j$ 个字符开始是否匹配。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的执行过程如下：

-   如果 $i \geq \textit{len}(s)$，那么只有当 $j \geq \textit{len}(p)$ 或者 $p[j] = '*'$ 且 $dfs(i, j + 1)$ 为真时，$dfs(i, j)$ 才为真。
-   如果 $j \geq \textit{len}(p)$，那么 $dfs(i, j)$ 为假。
-   如果 $p[j] = '*'$，那么 $dfs(i, j)$ 为真当且仅当 $dfs(i + 1, j)$ 或 $dfs(i + 1, j + 1)$ 或 $dfs(i, j + 1)$ 中有一个为真。
-   否则 $dfs(i, j)$ 为真当且仅当 $p[j] = '?'$ 或 $s[i] = p[j]$ 且 $dfs(i + 1, j + 1)$ 为真。

为了避免重复计算，我们使用记忆化搜索的方法，将 $dfs(i, j)$ 的结果存储在一个哈希表中。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $p$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i >= len(s):
                return j >= len(p) or (p[j] == "*" and dfs(i, j + 1))
            if j >= len(p):
                return False
            if p[j] == "*":
                return dfs(i + 1, j) or dfs(i + 1, j + 1) or dfs(i, j + 1)
            return (p[j] == "?" or s[i] == p[j]) and dfs(i + 1, j + 1)

        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Boolean[][] f;
    private char[] s;
    private char[] p;
    private int m;
    private int n;

    public boolean isMatch(String s, String p) {
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        m = s.length();
        n = p.length();
        f = new Boolean[m][n];
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i >= m) {
            return j >= n || (p[j] == '*' && dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        if (p[j] == '*') {
            f[i][j] = dfs(i + 1, j) || dfs(i + 1, j + 1) || dfs(i, j + 1);
        } else {
            f[i][j] = (p[j] == '?' || s[i] == p[j]) && dfs(i + 1, j + 1);
        }
        return f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int f[m + 1][n + 1];
        memset(f, -1, sizeof(f));
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i >= m) {
                return j >= n || (p[j] == '*' && dfs(i, j + 1));
            }
            if (j >= n) {
                return false;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            if (p[j] == '*') {
                f[i][j] = dfs(i + 1, j) || dfs(i, j + 1) ? 1 : 0;
            } else {
                f[i][j] = (p[j] == '?' || s[i] == p[j]) && dfs(i + 1, j + 1) ? 1 : 0;
            }
            return f[i][j] == 1;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func isMatch(s string, p string) bool {
	m, n := len(s), len(p)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i >= m {
			return j >= n || p[j] == '*' && dfs(i, j+1)
		}
		if j >= n {
			return false
		}
		if f[i][j] != 0 {
			return f[i][j] == 1
		}
		f[i][j] = 2
		ok := false
		if p[j] == '*' {
			ok = dfs(i+1, j) || dfs(i+1, j+1) || dfs(i, j+1)
		} else {
			ok = (p[j] == '?' || s[i] == p[j]) && dfs(i+1, j+1)
		}
		if ok {
			f[i][j] = 1
		}
		return ok
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function isMatch(s: string, p: string): boolean {
    const m = s.length;
    const n = p.length;
    const f: number[][] = Array.from({ length: m + 1 }, () =>
        Array.from({ length: n + 1 }, () => -1),
    );
    const dfs = (i: number, j: number): boolean => {
        if (i >= m) {
            return j >= n || (p[j] === '*' && dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i][j] !== -1) {
            return f[i][j] === 1;
        }
        if (p[j] === '*') {
            f[i][j] = dfs(i + 1, j) || dfs(i, j + 1) ? 1 : 0;
        } else {
            f[i][j] = (p[j] === '?' || s[i] === p[j]) && dfs(i + 1, j + 1) ? 1 : 0;
        }
        return f[i][j] === 1;
    };
    return dfs(0, 0);
}
```

#### C#

```cs
public class Solution {
    private bool?[,] f;
    private char[] s;
    private char[] p;
    private int m;
    private int n;

    public bool IsMatch(string s, string p) {
        this.s = s.ToCharArray();
        this.p = p.ToCharArray();
        m = s.Length;
        n = p.Length;
        f = new bool?[m, n];
        return Dfs(0, 0);
    }

    private bool Dfs(int i, int j) {
        if (i >= m) {
            return j >= n || (p[j] == '*' && Dfs(i, j + 1));
        }
        if (j >= n) {
            return false;
        }
        if (f[i, j] != null) {
            return f[i, j].Value;
        }
        if (p[j] == '*') {
            f[i, j] = Dfs(i + 1, j) || Dfs(i + 1, j + 1) || Dfs(i, j + 1);
        } else {
            f[i, j] = (p[j] == '?' || s[i] == p[j]) && Dfs(i + 1, j + 1);
        }
        return f[i, j].Value;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划。

定义 $f[i][j]$ 表示字符串 $s$ 的前 $i$ 个字符和字符串 $p$ 的前 $j$ 个字符是否匹配。初始时 $f[0][0] = \textit{true}$，表示两个空字符串是匹配的。对于 $j \in [1, n]$，如果 $p[j-1] = '*'$，那么 $f[0][j] = f[0][j-1]$。

接下来我们考虑 $i \in [1, m]$ 和 $j \in [1, n]$ 的情况：

-   如果 $p[j-1] = '*'$，那么 $f[i][j] = f[i-1][j] \lor f[i][j-1] \lor f[i-1][j-1]$。
-   否则 $f[i][j] = (p[j-1] = '?' \lor s[i-1] = p[j-1]) \land f[i-1][j-1]$。

最终答案为 $f[m][n]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $p$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for j in range(1, n + 1):
            if p[j - 1] == "*":
                f[0][j] = f[0][j - 1]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == "*":
                    f[i][j] = f[i - 1][j] or f[i][j - 1] or f[i - 1][j - 1]
                else:
                    f[i][j] = f[i - 1][j - 1] and (
                        p[j - 1] == "?" or s[i - 1] == p[j - 1]
                    )
        return f[m][n]
```

#### Java

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] f = new boolean[m + 1][n + 1];
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p.charAt(j - 1) == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p.charAt(j - 1) == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1]
                        && (p.charAt(j - 1) == '?' || s.charAt(i - 1) == p.charAt(j - 1));
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool f[m + 1][n + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                f[0][j] = f[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func isMatch(s string, p string) bool {
	m, n := len(s), len(p)
	f := make([][]bool, m+1)
	for i := range f {
		f[i] = make([]bool, n+1)
	}
	f[0][0] = true
	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			f[0][j] = f[0][j-1]
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				f[i][j] = f[i-1][j] || f[i][j-1] || f[i-1][j-1]
			} else {
				f[i][j] = f[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1])
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function isMatch(s: string, p: string): boolean {
    const m: number = s.length;
    const n: number = p.length;
    const f: boolean[][] = Array.from({ length: m + 1 }, () =>
        Array.from({ length: n + 1 }, () => false),
    );
    f[0][0] = true;
    for (let j = 1; j <= n; ++j) {
        if (p.charAt(j - 1) === '*') {
            f[0][j] = f[0][j - 1];
        }
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (p[j - 1] === '*') {
                f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
            } else {
                f[i][j] = f[i - 1][j - 1] && (p[j - 1] === '?' || s[i - 1] === p[j - 1]);
            }
        }
    }
    return f[m][n];
}
```

#### PHP

```php
class Solution {
    /**
     * @param string $s
     * @param string $p
     * @return boolean
     */

    function isMatch($s, $p) {
        $lengthS = strlen($s);
        $lengthP = strlen($p);
        $dp = [];
        for ($i = 0; $i <= $lengthS; $i++) {
            $dp[$i] = array_fill(0, $lengthP + 1, false);
        }
        $dp[0][0] = true;

        for ($i = 1; $i <= $lengthP; $i++) {
            if ($p[$i - 1] == '*') {
                $dp[0][$i] = $dp[0][$i - 1];
            }
        }
        for ($i = 1; $i <= $lengthS; $i++) {
            for ($j = 1; $j <= $lengthP; $j++) {
                if ($p[$j - 1] == '?' || $s[$i - 1] == $p[$j - 1]) {
                    $dp[$i][$j] = $dp[$i - 1][$j - 1];
                } elseif ($p[$j - 1] == '*') {
                    $dp[$i][$j] = $dp[$i][$j - 1] || $dp[$i - 1][$j];
                }
            }
        }
        return $dp[$lengthS][$lengthP];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii){#45}

{{< tabs "45" >}}

{{% tab "python" %}}
```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = mx = last = 0
        for i, x in enumerate(nums[:-1]):
            mx = max(mx, i + x)
            if last == i:
                ans += 1
                last = mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int jump(int[] nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            mx = Math.max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
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
    int jump(vector<int>& nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            mx = max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func jump(nums []int) (ans int) {
	mx, last := 0, 0
	for i, x := range nums[:len(nums)-1] {
		mx = max(mx, i+x)
		if last == i {
			ans++
			last = mx
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function jump(nums: number[]): number {
    let [ans, mx, last] = [0, 0, 0];
    for (let i = 0; i < nums.length - 1; ++i) {
        mx = Math.max(mx, i + nums[i]);
        if (last === i) {
            ++ans;
            last = mx;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        let mut last = 0;
        for i in 0..(nums.len() - 1) {
            mx = mx.max(i as i32 + nums[i]);
            if last == i as i32 {
                ans += 1;
                last = mx;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Jump(int[] nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.Length - 1; ++i) {
            mx = Math.Max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int jump(int* nums, int numsSize) {
    int ans = 0;
    int mx = 0;
    int last = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        mx = (mx > i + nums[i]) ? mx : (i + nums[i]);
        if (last == i) {
            ++ans;
            last = mx;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function jump($nums) {
        $ans = 0;
        $mx = 0;
        $last = 0;

        for ($i = 0; $i < count($nums) - 1; $i++) {
            $mx = max($mx, $i + $nums[$i]);
            if ($last == $i) {
                $ans++;
                $last = $mx;
            }
        }

        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 <code>n</code> 的 <strong>0 索引</strong>整数数组 <code>nums</code>。初始位置在下标 0。</p>

<p>每个元素 <code>nums[i]</code> 表示从索引 <code>i</code> 向后跳转的最大长度。换句话说，如果你在索引&nbsp;<code>i</code>&nbsp;处，你可以跳转到任意 <code>(i + j)</code> 处：</p>

<ul>
	<li><code>0 &lt;= j &lt;= nums[i]</code>&nbsp;且</li>
	<li><code>i + j &lt; n</code></li>
</ul>

<p>返回到达&nbsp;<code>n - 1</code>&nbsp;的最小跳跃次数。测试用例保证可以到达 <code>n - 1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,3,1,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 跳到最后一个位置的最小跳跃数是 <code>2</code>。
&nbsp;    从下标为 0 跳到下标为 1 的位置，跳&nbsp;<code>1</code>&nbsp;步，然后跳&nbsp;<code>3</code>&nbsp;步到达数组的最后一个位置。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,3,0,1,4]
<strong>输出:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li>题目保证可以到达&nbsp;<code>n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以用变量 $mx$ 记录当前位置能够到达的最远位置，用变量 $last$ 记录上一次跳跃到的位置，用变量 $ans$ 记录跳跃的次数。

接下来，我们遍历 $[0,..n - 2]$ 的每一个位置 $i$，对于每一个位置 $i$，我们可以通过 $i + nums[i]$ 计算出当前位置能够到达的最远位置，我们用 $mx$ 来记录这个最远位置，即 $mx = max(mx, i + nums[i])$。接下来，判断当前位置是否到达了上一次跳跃的边界，即 $i = last$，如果到达了，那么我们就需要进行一次跳跃，将 $last$ 更新为 $mx$，并且将跳跃次数 $ans$ 增加 $1$。

最后，我们返回跳跃的次数 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

相似题目：

-   [55. 跳跃游戏](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0055.Jump%20Game/README.md)
-   [1024. 视频拼接](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1024.Video%20Stitching/README.md)
-   [1326. 灌溉花园的最少水龙头数目](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1326.Minimum%20Number%20of%20Taps%20to%20Open%20to%20Water%20a%20Garden/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = mx = last = 0
        for i, x in enumerate(nums[:-1]):
            mx = max(mx, i + x)
            if last == i:
                ans += 1
                last = mx
        return ans
```

#### Java

```java
class Solution {
    public int jump(int[] nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            mx = Math.max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
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
    int jump(vector<int>& nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            mx = max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func jump(nums []int) (ans int) {
	mx, last := 0, 0
	for i, x := range nums[:len(nums)-1] {
		mx = max(mx, i+x)
		if last == i {
			ans++
			last = mx
		}
	}
	return
}
```

#### TypeScript

```ts
function jump(nums: number[]): number {
    let [ans, mx, last] = [0, 0, 0];
    for (let i = 0; i < nums.length - 1; ++i) {
        mx = Math.max(mx, i + nums[i]);
        if (last === i) {
            ++ans;
            last = mx;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        let mut last = 0;
        for i in 0..(nums.len() - 1) {
            mx = mx.max(i as i32 + nums[i]);
            if last == i as i32 {
                ans += 1;
                last = mx;
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int Jump(int[] nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.Length - 1; ++i) {
            mx = Math.Max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
            }
        }
        return ans;
    }
}
```

#### C

```c
int jump(int* nums, int numsSize) {
    int ans = 0;
    int mx = 0;
    int last = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        mx = (mx > i + nums[i]) ? mx : (i + nums[i]);
        if (last == i) {
            ++ans;
            last = mx;
        }
    }
    return ans;
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function jump($nums) {
        $ans = 0;
        $mx = 0;
        $last = 0;

        for ($i = 0; $i < count($nums) - 1; $i++) {
            $mx = max($mx, $i + $nums[$i]);
            if ($last == $i) {
                $ans++;
                $last = $mx;
            }
        }

        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [46. 全排列](https://leetcode.cn/problems/permutations){#46}

{{< tabs "46" >}}

{{% tab "python" %}}
```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i >= n:
                ans.append(t[:])
                return
            for j, x in enumerate(nums):
                if not vis[j]:
                    vis[j] = True
                    t[i] = x
                    dfs(i + 1)
                    vis[j] = False

        n = len(nums)
        vis = [False] * n
        t = [0] * n
        ans = []
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private boolean[] vis;
    private int[] nums;

    public List<List<Integer>> permute(int[] nums) {
        this.nums = nums;
        vis = new boolean[nums.length];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = 0; j < nums.length; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t.add(nums[j]);
                dfs(i + 1);
                t.remove(t.size() - 1);
                vis[j] = false;
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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    t[i] = nums[j];
                    dfs(i + 1);
                    vis[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func permute(nums []int) (ans [][]int) {
	n := len(nums)
	t := make([]int, n)
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, slices.Clone(t))
			return
		}
		for j, x := range nums {
			if !vis[j] {
				vis[j] = true
				t[i] = x
				dfs(i + 1)
				vis[j] = false
			}
		}
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function permute(nums: number[]): number[][] {
    const n = nums.length;
    const ans: number[][] = [];
    const vis: boolean[] = Array(n).fill(false);
    const t: number[] = Array(n).fill(0);
    const dfs = (i: number) => {
        if (i >= n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t[i] = nums[j];
                dfs(i + 1);
                vis[j] = false;
            }
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut ans = Vec::new();
        let mut t = vec![0; n];
        let mut vis = vec![false; n];
        fn dfs(
            nums: &Vec<i32>,
            n: usize,
            t: &mut Vec<i32>,
            vis: &mut Vec<bool>,
            ans: &mut Vec<Vec<i32>>,
            i: usize
        ) {
            if i == n {
                ans.push(t.clone());
                return;
            }
            for j in 0..n {
                if !vis[j] {
                    vis[j] = true;
                    t[i] = nums[j];
                    dfs(nums, n, t, vis, ans, i + 1);
                    vis[j] = false;
                }
            }
        }
        dfs(&nums, n, &mut t, &mut vis, &mut ans, 0);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
    const n = nums.length;
    const ans = [];
    const vis = Array(n).fill(false);
    const t = Array(n).fill(0);
    const dfs = i => {
        if (i >= n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t[i] = nums[j];
                dfs(i + 1);
                vis[j] = false;
            }
        }
    };
    dfs(0);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        var ans = new List<IList<int>>();
        var t = new List<int>();
        var vis = new bool[nums.Length];
        dfs(nums, 0, t, vis, ans);
        return ans;
    }

    private void dfs(int[] nums, int i, IList<int> t, bool[] vis, IList<IList<int>> ans) {
        if (i >= nums.Length) {
            ans.Add(new List<int>(t));
            return;
        }
        for (int j = 0; j < nums.Length; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t.Add(nums[j]);
                dfs(nums, i + 1, t, vis, ans);
                t.RemoveAt(t.Count - 1);
                vis[j] = false;
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个不含重复数字的数组 <code>nums</code> ，返回其 <em>所有可能的全排列</em> 。你可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[[0,1],[1,0]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>[[1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS（回溯）

我们设计一个函数 $dfs(i)$ 表示已经填完了前 $i$ 个位置，现在需要填第 $i+1$ 个位置。枚举所有可能的数，如果这个数没有被填过，就填入这个数，然后继续填下一个位置，直到填完所有的位置。

时间复杂度 $O(n \times n!)$，其中 $n$ 是数组的长度。一共有 $n!$ 个排列，每个排列需要 $O(n)$ 的时间来构造。

相似题目：

-   [47. 全排列 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0047.Permutations%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i >= n:
                ans.append(t[:])
                return
            for j, x in enumerate(nums):
                if not vis[j]:
                    vis[j] = True
                    t[i] = x
                    dfs(i + 1)
                    vis[j] = False

        n = len(nums)
        vis = [False] * n
        t = [0] * n
        ans = []
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private boolean[] vis;
    private int[] nums;

    public List<List<Integer>> permute(int[] nums) {
        this.nums = nums;
        vis = new boolean[nums.length];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = 0; j < nums.length; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t.add(nums[j]);
                dfs(i + 1);
                t.remove(t.size() - 1);
                vis[j] = false;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    t[i] = nums[j];
                    dfs(i + 1);
                    vis[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func permute(nums []int) (ans [][]int) {
	n := len(nums)
	t := make([]int, n)
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, slices.Clone(t))
			return
		}
		for j, x := range nums {
			if !vis[j] {
				vis[j] = true
				t[i] = x
				dfs(i + 1)
				vis[j] = false
			}
		}
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function permute(nums: number[]): number[][] {
    const n = nums.length;
    const ans: number[][] = [];
    const vis: boolean[] = Array(n).fill(false);
    const t: number[] = Array(n).fill(0);
    const dfs = (i: number) => {
        if (i >= n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t[i] = nums[j];
                dfs(i + 1);
                vis[j] = false;
            }
        }
    };
    dfs(0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut ans = Vec::new();
        let mut t = vec![0; n];
        let mut vis = vec![false; n];
        fn dfs(
            nums: &Vec<i32>,
            n: usize,
            t: &mut Vec<i32>,
            vis: &mut Vec<bool>,
            ans: &mut Vec<Vec<i32>>,
            i: usize
        ) {
            if i == n {
                ans.push(t.clone());
                return;
            }
            for j in 0..n {
                if !vis[j] {
                    vis[j] = true;
                    t[i] = nums[j];
                    dfs(nums, n, t, vis, ans, i + 1);
                    vis[j] = false;
                }
            }
        }
        dfs(&nums, n, &mut t, &mut vis, &mut ans, 0);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
    const n = nums.length;
    const ans = [];
    const vis = Array(n).fill(false);
    const t = Array(n).fill(0);
    const dfs = i => {
        if (i >= n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t[i] = nums[j];
                dfs(i + 1);
                vis[j] = false;
            }
        }
    };
    dfs(0);
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        var ans = new List<IList<int>>();
        var t = new List<int>();
        var vis = new bool[nums.Length];
        dfs(nums, 0, t, vis, ans);
        return ans;
    }

    private void dfs(int[] nums, int i, IList<int> t, bool[] vis, IList<IList<int>> ans) {
        if (i >= nums.Length) {
            ans.Add(new List<int>(t));
            return;
        }
        for (int j = 0; j < nums.Length; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                t.Add(nums[j]);
                dfs(nums, i + 1, t, vis, ans);
                t.RemoveAt(t.Count - 1);
                vis[j] = false;
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [47. 全排列 II](https://leetcode.cn/problems/permutations-ii){#47}

{{< tabs "47" >}}

{{% tab "python" %}}
```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(n):
                if vis[j] or (j and nums[j] == nums[j - 1] and not vis[j - 1]):
                    continue
                t[i] = nums[j]
                vis[j] = True
                dfs(i + 1)
                vis[j] = False

        n = len(nums)
        nums.sort()
        ans = []
        t = [0] * n
        vis = [False] * n
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] nums;
    private boolean[] vis;

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        vis = new boolean[nums.length];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = 0; j < nums.length; ++j) {
            if (vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t.add(nums[j]);
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
            t.remove(t.size() - 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j] || (j && nums[j] == nums[j - 1] && !vis[j - 1])) {
                    continue;
                }
                t[i] = nums[j];
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func permuteUnique(nums []int) (ans [][]int) {
	slices.Sort(nums)
	n := len(nums)
	t := make([]int, n)
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, slices.Clone(t))
			return
		}
		for j := 0; j < n; j++ {
			if vis[j] || (j > 0 && nums[j] == nums[j-1] && !vis[j-1]) {
				continue
			}
			vis[j] = true
			t[i] = nums[j]
			dfs(i + 1)
			vis[j] = false
		}
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function permuteUnique(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const ans: number[][] = [];
    const t: number[] = Array(n);
    const vis: boolean[] = Array(n).fill(false);
    const dfs = (i: number) => {
        if (i === n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (vis[j] || (j > 0 && nums[j] === nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t[i] = nums[j];
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn permute_unique(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let n = nums.len();
        let mut ans = Vec::new();
        let mut t = vec![0; n];
        let mut vis = vec![false; n];

        fn dfs(
            nums: &Vec<i32>,
            t: &mut Vec<i32>,
            vis: &mut Vec<bool>,
            ans: &mut Vec<Vec<i32>>,
            i: usize,
        ) {
            if i == nums.len() {
                ans.push(t.clone());
                return;
            }
            for j in 0..nums.len() {
                if vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1]) {
                    continue;
                }
                t[i] = nums[j];
                vis[j] = true;
                dfs(nums, t, vis, ans, i + 1);
                vis[j] = false;
            }
        }

        dfs(&nums, &mut t, &mut vis, &mut ans, 0);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function (nums) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const ans = [];
    const t = Array(n);
    const vis = Array(n).fill(false);
    const dfs = i => {
        if (i === n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (vis[j] || (j > 0 && nums[j] === nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t[i] = nums[j];
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
        }
    };
    dfs(0);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] nums;
    private bool[] vis;

    public IList<IList<int>> PermuteUnique(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length;
        vis = new bool[n];
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.Length) {
            ans.Add(new List<int>(t));
            return;
        }
        for (int j = 0; j < nums.Length; ++j) {
            if (vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            vis[j] = true;
            t.Add(nums[j]);
            dfs(i + 1);
            t.RemoveAt(t.Count - 1);
            vis[j] = false;
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个可包含重复数字的序列 <code>nums</code> ，<em><strong>按任意顺序</strong></em> 返回所有不重复的全排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2]
<strong>输出：</strong>
[[1,1,2],
 [1,2,1],
 [2,1,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 8</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 回溯

我们可以先对数组进行排序，这样就可以将重复的数字放在一起，方便我们进行去重。

然后，我们设计一个函数 $\textit{dfs}(i)$，表示当前需要填写第 $i$ 个位置的数。函数的具体实现如下：

-   如果 $i = n$，说明我们已经填写完毕，将当前排列加入答案数组中，然后返回。
-   否则，我们枚举第 $i$ 个位置的数 $nums[j]$，其中 $j$ 的范围是 $[0, n - 1]$。我们需要保证 $nums[j]$ 没有被使用过，并且与前面枚举的数不同，这样才能保证当前排列不重复。如果满足条件，我们就可以填写 $nums[j]$，并继续递归地填写下一个位置，即调用 $\textit{dfs}(i + 1)$。在递归调用结束后，我们需要将 $nums[j]$ 标记为未使用，以便于进行后面的枚举。

在主函数中，我们首先对数组进行排序，然后调用 $\textit{dfs}(0)$，即从第 0 个位置开始填写，最终返回答案数组即可。

时间复杂度 $O(n \times n!)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。需要进行 $n!$ 次枚举，每次枚举需要 $O(n)$ 的时间来判断是否重复。另外，我们需要一个标记数组来标记每个位置是否被使用过，因此空间复杂度为 $O(n)$。

相似题目：

-   [46. 全排列](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0046.Permutations/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(n):
                if vis[j] or (j and nums[j] == nums[j - 1] and not vis[j - 1]):
                    continue
                t[i] = nums[j]
                vis[j] = True
                dfs(i + 1)
                vis[j] = False

        n = len(nums)
        nums.sort()
        ans = []
        t = [0] * n
        vis = [False] * n
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int[] nums;
    private boolean[] vis;

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        vis = new boolean[nums.length];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = 0; j < nums.length; ++j) {
            if (vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t.add(nums[j]);
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
            t.remove(t.size() - 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n);
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j] || (j && nums[j] == nums[j - 1] && !vis[j - 1])) {
                    continue;
                }
                t[i] = nums[j];
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func permuteUnique(nums []int) (ans [][]int) {
	slices.Sort(nums)
	n := len(nums)
	t := make([]int, n)
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, slices.Clone(t))
			return
		}
		for j := 0; j < n; j++ {
			if vis[j] || (j > 0 && nums[j] == nums[j-1] && !vis[j-1]) {
				continue
			}
			vis[j] = true
			t[i] = nums[j]
			dfs(i + 1)
			vis[j] = false
		}
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function permuteUnique(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const ans: number[][] = [];
    const t: number[] = Array(n);
    const vis: boolean[] = Array(n).fill(false);
    const dfs = (i: number) => {
        if (i === n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (vis[j] || (j > 0 && nums[j] === nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t[i] = nums[j];
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
        }
    };
    dfs(0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn permute_unique(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let n = nums.len();
        let mut ans = Vec::new();
        let mut t = vec![0; n];
        let mut vis = vec![false; n];

        fn dfs(
            nums: &Vec<i32>,
            t: &mut Vec<i32>,
            vis: &mut Vec<bool>,
            ans: &mut Vec<Vec<i32>>,
            i: usize,
        ) {
            if i == nums.len() {
                ans.push(t.clone());
                return;
            }
            for j in 0..nums.len() {
                if vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1]) {
                    continue;
                }
                t[i] = nums[j];
                vis[j] = true;
                dfs(nums, t, vis, ans, i + 1);
                vis[j] = false;
            }
        }

        dfs(&nums, &mut t, &mut vis, &mut ans, 0);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function (nums) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const ans = [];
    const t = Array(n);
    const vis = Array(n).fill(false);
    const dfs = i => {
        if (i === n) {
            ans.push(t.slice());
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (vis[j] || (j > 0 && nums[j] === nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            t[i] = nums[j];
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
        }
    };
    dfs(0);
    return ans;
};
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int[] nums;
    private bool[] vis;

    public IList<IList<int>> PermuteUnique(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length;
        vis = new bool[n];
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == nums.Length) {
            ans.Add(new List<int>(t));
            return;
        }
        for (int j = 0; j < nums.Length; ++j) {
            if (vis[j] || (j > 0 && nums[j] == nums[j - 1] && !vis[j - 1])) {
                continue;
            }
            vis[j] = true;
            t.Add(nums[j]);
            dfs(i + 1);
            t.RemoveAt(t.Count - 1);
            vis[j] = false;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [48. 旋转图像](https://leetcode.cn/problems/rotate-image){#48}

{{< tabs "48" >}}

{{% tab "python" %}}
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n >> 1):
            for j in range(n):
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i - 1][j], matrix[i][j]
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rotate(matrix [][]int) {
	n := len(matrix)
	for i := 0; i < n>>1; i++ {
		for j := 0; j < n; j++ {
			matrix[i][j], matrix[n-i-1][j] = matrix[n-i-1][j], matrix[i][j]
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
    matrix.reverse();
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < i; ++j) {
            const t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        for i in 0..n / 2 {
            for j in 0..n {
                let t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for i in 0..n {
            for j in 0..i {
                let t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    matrix.reverse();
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < i; ++j) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <em>n&nbsp;</em>×&nbsp;<em>n</em> 的二维矩阵&nbsp;<code>matrix</code> 表示一个图像。请你将图像顺时针旋转 90 度。</p>

<p>你必须在<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地</a></strong> 旋转图像，这意味着你需要直接修改输入的二维矩阵。<strong>请不要 </strong>使用另一个矩阵来旋转图像。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0048.Rotate%20Image/images/mat1.jpg" style="height: 188px; width: 500px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[[7,4,1],[8,5,2],[9,6,3]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0048.Rotate%20Image/images/mat2.jpg" style="height: 201px; width: 500px;" />
<pre>
<strong>输入：</strong>matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
<strong>输出：</strong>[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：原地翻转

根据题目要求，我们实际上需要将 $\text{matrix}[i][j]$ 旋转至 $\text{matrix}[j][n - i - 1]$。

我们可以先对矩阵进行上下翻转，即 $\text{matrix}[i][j]$ 和 $\text{matrix}[n - i - 1][j]$ 进行交换，然后再对矩阵进行主对角线翻转，即 $\text{matrix}[i][j]$ 和 $\text{matrix}[j][i]$ 进行交换。这样就能将 $\text{matrix}[i][j]$ 旋转至 $\text{matrix}[j][n - i - 1]$ 了。

时间复杂度 $O(n^2)$，其中 $n$ 是矩阵的边长。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n >> 1):
            for j in range(n):
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i - 1][j], matrix[i][j]
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```

#### Java

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```

#### Go

```go
func rotate(matrix [][]int) {
	n := len(matrix)
	for i := 0; i < n>>1; i++ {
		for j := 0; j < n; j++ {
			matrix[i][j], matrix[n-i-1][j] = matrix[n-i-1][j], matrix[i][j]
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}
```

#### TypeScript

```ts
/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
    matrix.reverse();
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < i; ++j) {
            const t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        for i in 0..n / 2 {
            for j in 0..n {
                let t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for i in 0..n {
            for j in 0..i {
                let t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    matrix.reverse();
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < i; ++j) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }
};
```

#### C#

```cs
public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        for (int i = 0; i < n >> 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams){#49}

{{< tabs "49" >}}

{{% tab "python" %}}
```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in strs:
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            d[tuple(cnt)].append(s)
        return list(d.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> d = new HashMap<>();
        for (String s : strs) {
            int[] cnt = new int[26];
            for (int i = 0; i < s.length(); ++i) {
                ++cnt[s.charAt(i) - 'a'];
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    sb.append((char) ('a' + i)).append(cnt[i]);
                }
            }
            String k = sb.toString();
            d.computeIfAbsent(k, key -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(d.values());
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            int cnt[26] = {0};
            for (auto& c : s) ++cnt[c - 'a'];
            string k;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    k += 'a' + i;
                    k += to_string(cnt[i]);
                }
            }
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func groupAnagrams(strs []string) (ans [][]string) {
	d := map[[26]int][]string{}
	for _, s := range strs {
		cnt := [26]int{}
		for _, c := range s {
			cnt[c-'a']++
		}
		d[cnt] = append(d[cnt], s)
	}
	for _, v := range d {
		ans = append(ans, v)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function groupAnagrams(strs: string[]): string[][] {
    const map = new Map<string, string[]>();
    for (const str of strs) {
        const k = str.split('').sort().join('');
        map.set(k, (map.get(k) ?? []).concat([str]));
    }
    return [...map.values()];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map = HashMap::new();
        for s in strs {
            let key = {
                let mut arr = s.chars().collect::<Vec<char>>();
                arr.sort();
                arr.iter().collect::<String>()
            };
            let val = map.entry(key).or_insert(vec![]);
            val.push(s);
        }
        map.into_iter().map(|(_, v)| v).collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Collections.Generic;

public class Comparer : IEqualityComparer<string>
{
    public bool Equals(string left, string right)
    {
        if (left.Length != right.Length) return false;

        var leftCount = new int[26];
        foreach (var ch in left)
        {
            ++leftCount[ch - 'a'];
        }

        var rightCount = new int[26];
        foreach (var ch in right)
        {
            var index = ch - 'a';
            if (++rightCount[index] > leftCount[index]) return false;
        }

        return true;
    }

    public int GetHashCode(string obj)
    {
        var hashCode = 0;
        for (int i = 0; i < obj.Length; ++i)
        {
            hashCode ^= 1 << (obj[i] - 'a');
        }
        return hashCode;
    }
}

public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var dict = new Dictionary<string, List<string>>(new Comparer());
        foreach (var str in strs)
        {
            List<string> list;
            if (!dict.TryGetValue(str, out list))
            {
                list = new List<string>();
                dict.Add(str, list);
            }
            list.Add(str);
        }
        foreach (var list in dict.Values)
        {
            list.Sort();
        }
        return new List<IList<string>>(dict.Values);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组，请你将 <span data-keyword="anagram">字母异位词</span> 组合在一起。可以按任意顺序返回结果列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> strs = ["eat", "tea", "tan", "ate", "nat", "bat"]</p>

<p><strong>输出: </strong>[["bat"],["nat","tan"],["ate","eat","tea"]]</p>

<p><strong>解释：</strong></p>

<ul>
	<li>在 strs 中没有字符串可以通过重新排列来形成 <code>"bat"</code>。</li>
	<li>字符串 <code>"nat"</code> 和 <code>"tan"</code> 是字母异位词，因为它们可以重新排列以形成彼此。</li>
	<li>字符串 <code>"ate"</code>&nbsp;，<code>"eat"</code>&nbsp;和 <code>"tea"</code> 是字母异位词，因为它们可以重新排列以形成彼此。</li>
</ul>
</div>

<p><strong>示例 2:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> strs = [""]</p>

<p><strong>输出: </strong>[[""]]</p>
</div>

<p><strong>示例 3:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> strs = ["a"]</p>

<p><strong>输出: </strong>[["a"]]</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code>&nbsp;仅包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

1. 遍历字符串，对每个字符串按照**字符字典序**排序，得到一个新的字符串。
2. 以新字符串为 `key`，`[str]` 为 `value`，存入哈希表当中（`HashMap<String, List<String>>`）。
3. 后续遍历得到相同 `key` 时，将其加入到对应的 `value` 当中即可。

以 `strs = ["eat", "tea", "tan", "ate", "nat", "bat"]` 为例，遍历结束时，哈希表的状况：

| key     | value                   |
| ------- | ----------------------- |
| `"aet"` | `["eat", "tea", "ate"]` |
| `"ant"` | `["tan", "nat"] `       |
| `"abt"` | `["bat"] `              |

最后返回哈希表的 `value` 列表即可。

时间复杂度 $O(n\times k\times \log k)$。其中 $n$ 和 $k$ 分别是字符串数组的长度和字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in strs:
            k = ''.join(sorted(s))
            d[k].append(s)
        return list(d.values())
```

#### Java

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> d = new HashMap<>();
        for (String s : strs) {
            char[] t = s.toCharArray();
            Arrays.sort(t);
            String k = String.valueOf(t);
            d.computeIfAbsent(k, key -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(d.values());
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
};
```

#### Go

```go
func groupAnagrams(strs []string) (ans [][]string) {
	d := map[string][]string{}
	for _, s := range strs {
		t := []byte(s)
		sort.Slice(t, func(i, j int) bool { return t[i] < t[j] })
		k := string(t)
		d[k] = append(d[k], s)
	}
	for _, v := range d {
		ans = append(ans, v)
	}
	return
}
```

#### TypeScript

```ts
function groupAnagrams(strs: string[]): string[][] {
    const d: Map<string, string[]> = new Map();
    for (const s of strs) {
        const k = s.split('').sort().join('');
        if (!d.has(k)) {
            d.set(k, []);
        }
        d.get(k)!.push(s);
    }
    return Array.from(d.values());
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map = HashMap::new();
        for s in strs {
            let key = {
                let mut arr = s.chars().collect::<Vec<char>>();
                arr.sort();
                arr.iter().collect::<String>()
            };
            let val = map.entry(key).or_insert(vec![]);
            val.push(s);
        }
        map.into_iter().map(|(_, v)| v).collect()
    }
}
```

#### C#

```cs
using System.Collections.Generic;

public class Comparer : IEqualityComparer<string>
{
    public bool Equals(string left, string right)
    {
        if (left.Length != right.Length) return false;

        var leftCount = new int[26];
        foreach (var ch in left)
        {
            ++leftCount[ch - 'a'];
        }

        var rightCount = new int[26];
        foreach (var ch in right)
        {
            var index = ch - 'a';
            if (++rightCount[index] > leftCount[index]) return false;
        }

        return true;
    }

    public int GetHashCode(string obj)
    {
        var hashCode = 0;
        for (int i = 0; i < obj.Length; ++i)
        {
            hashCode ^= 1 << (obj[i] - 'a');
        }
        return hashCode;
    }
}

public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var dict = new Dictionary<string, List<string>>(new Comparer());
        foreach (var str in strs)
        {
            List<string> list;
            if (!dict.TryGetValue(str, out list))
            {
                list = new List<string>();
                dict.Add(str, list);
            }
            list.Add(str);
        }
        foreach (var list in dict.Values)
        {
            list.Sort();
        }
        return new List<IList<string>>(dict.Values);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数

我们也可以将方法一中的排序部分改为计数，也就是说，将每个字符串 $s$ 中的字符以及出现的次数作为 `key`，将字符串 $s$ 作为 `value` 存入哈希表当中。

时间复杂度 $O(n\times (k + C))$。其中 $n$ 和 $k$ 分别是字符串数组的长度和字符串的最大长度，而 $C$ 是字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in strs:
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            d[tuple(cnt)].append(s)
        return list(d.values())
```

#### Java

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> d = new HashMap<>();
        for (String s : strs) {
            int[] cnt = new int[26];
            for (int i = 0; i < s.length(); ++i) {
                ++cnt[s.charAt(i) - 'a'];
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    sb.append((char) ('a' + i)).append(cnt[i]);
                }
            }
            String k = sb.toString();
            d.computeIfAbsent(k, key -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(d.values());
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            int cnt[26] = {0};
            for (auto& c : s) ++cnt[c - 'a'];
            string k;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    k += 'a' + i;
                    k += to_string(cnt[i]);
                }
            }
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
};
```

#### Go

```go
func groupAnagrams(strs []string) (ans [][]string) {
	d := map[[26]int][]string{}
	for _, s := range strs {
		cnt := [26]int{}
		for _, c := range s {
			cnt[c-'a']++
		}
		d[cnt] = append(d[cnt], s)
	}
	for _, v := range d {
		ans = append(ans, v)
	}
	return
}
```

#### TypeScript

```ts
function groupAnagrams(strs: string[]): string[][] {
    const map = new Map<string, string[]>();
    for (const str of strs) {
        const k = str.split('').sort().join('');
        map.set(k, (map.get(k) ?? []).concat([str]));
    }
    return [...map.values()];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [50. Pow(x, n)](https://leetcode.cn/problems/powx-n){#50}

{{< tabs "50" >}}

{{% tab "python" %}}
```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def qpow(a: float, n: int) -> float:
            ans = 1
            while n:
                if n & 1:
                    ans *= a
                a *= a
                n >>= 1
            return ans

        return qpow(x, n) if n >= 0 else 1 / qpow(x, -n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double myPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long) n);
    }

    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a;
            }
            a = a * a;
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
    double myPow(double x, int n) {
        auto qpow = [](double a, long long n) {
            double ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans *= a;
                }
                a *= a;
            }
            return ans;
        };
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long long) n);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func myPow(x float64, n int) float64 {
	qpow := func(a float64, n int) float64 {
		ans := 1.0
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans *= a
			}
			a *= a
		}
		return ans
	}
	if n >= 0 {
		return qpow(x, n)
	}
	return 1 / qpow(x, -n)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function myPow(x: number, n: number): number {
    const qpow = (a: number, n: number): number => {
        let ans = 1;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans *= a;
            }
            a *= a;
        }
        return ans;
    };
    return n >= 0 ? qpow(x, n) : 1 / qpow(x, -n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn my_pow(x: f64, n: i32) -> f64 {
        let mut x = x;
        let n = n as i64;
        if n >= 0 {
            Self::quick_pow(&mut x, n)
        } else {
            1.0 / Self::quick_pow(&mut x, -n)
        }
    }

    #[allow(dead_code)]
    fn quick_pow(x: &mut f64, mut n: i64) -> f64 {
        // `n` should greater or equal to zero
        let mut ret = 1.0;
        while n != 0 {
            if (n & 0x1) == 1 {
                ret *= *x;
            }
            *x *= *x;
            n >>= 1;
        }
        ret
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    const qpow = (a, n) => {
        let ans = 1;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans *= a;
            }
            a *= a;
        }
        return ans;
    };
    return n >= 0 ? qpow(x, n) : 1 / qpow(x, -n);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public double MyPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1.0 / qpow(x, -(long)n);
    }

    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans *= a;
            }
            a *= a;
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

<p>实现&nbsp;<a href="https://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(<em>x</em>, <em>n</em>)</a>&nbsp;，即计算 <code>x</code> 的整数&nbsp;<code>n</code> 次幂函数（即，<code>x<sup>n</sup></code><sup><span style="font-size:10.8333px"> </span></sup>）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 2.00000, n = 10
<strong>输出：</strong>1024.00000
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 2.10000, n = 3
<strong>输出：</strong>9.26100
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>x = 2.00000, n = -2
<strong>输出：</strong>0.25000
<strong>解释：</strong>2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-100.0 &lt; x &lt; 100.0</code></li>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup>-1</code></li>
	<li><code>n</code>&nbsp;是一个整数</li>
	<li>要么 <code>x</code> 不为零，要么 <code>n &gt; 0</code> 。</li>
	<li><code>-10<sup>4</sup> &lt;= x<sup>n</sup> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学（快速幂）

快速幂算法的核心思想是将幂指数 $n$ 拆分为若干个二进制位上的 $1$ 的和，然后将 $x$ 的 $n$ 次幂转化为 $x$ 的若干个幂的乘积。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为幂指数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def qpow(a: float, n: int) -> float:
            ans = 1
            while n:
                if n & 1:
                    ans *= a
                a *= a
                n >>= 1
            return ans

        return qpow(x, n) if n >= 0 else 1 / qpow(x, -n)
```

#### Java

```java
class Solution {
    public double myPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long) n);
    }

    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a;
            }
            a = a * a;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        auto qpow = [](double a, long long n) {
            double ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans *= a;
                }
                a *= a;
            }
            return ans;
        };
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long long) n);
    }
};
```

#### Go

```go
func myPow(x float64, n int) float64 {
	qpow := func(a float64, n int) float64 {
		ans := 1.0
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans *= a
			}
			a *= a
		}
		return ans
	}
	if n >= 0 {
		return qpow(x, n)
	}
	return 1 / qpow(x, -n)
}
```

#### TypeScript

```ts
function myPow(x: number, n: number): number {
    const qpow = (a: number, n: number): number => {
        let ans = 1;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans *= a;
            }
            a *= a;
        }
        return ans;
    };
    return n >= 0 ? qpow(x, n) : 1 / qpow(x, -n);
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn my_pow(x: f64, n: i32) -> f64 {
        let mut x = x;
        let n = n as i64;
        if n >= 0 {
            Self::quick_pow(&mut x, n)
        } else {
            1.0 / Self::quick_pow(&mut x, -n)
        }
    }

    #[allow(dead_code)]
    fn quick_pow(x: &mut f64, mut n: i64) -> f64 {
        // `n` should greater or equal to zero
        let mut ret = 1.0;
        while n != 0 {
            if (n & 0x1) == 1 {
                ret *= *x;
            }
            *x *= *x;
            n >>= 1;
        }
        ret
    }
}
```

#### JavaScript

```js
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    const qpow = (a, n) => {
        let ans = 1;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans *= a;
            }
            a *= a;
        }
        return ans;
    };
    return n >= 0 ? qpow(x, n) : 1 / qpow(x, -n);
};
```

#### C#

```cs
public class Solution {
    public double MyPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1.0 / qpow(x, -(long)n);
    }

    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans *= a;
            }
            a *= a;
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
