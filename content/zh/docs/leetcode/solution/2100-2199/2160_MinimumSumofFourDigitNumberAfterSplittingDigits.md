---
title: "2160_MinimumSumofFourDigitNumberAfterSplittingDigits"
date: 2025-10-06T00:42:37+08:00
weight: 2160
tags: [贪心, 数学, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2160. 拆分数位后四位数字的最小和](https://leetcode.cn/problems/minimum-sum-of-four-digit-number-after-splitting-digits)

[English Version](../en/2160-60/2160_MinimumSumofFourDigitNumberAfterSplittingDigits)

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

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
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
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minimumSum(self, num: int) -> int:
        nums = []
        while num:
            nums.append(num % 10)
            num //= 10
        nums.sort()
        return 10 * (nums[0] + nums[1]) + nums[2] + nums[3]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}