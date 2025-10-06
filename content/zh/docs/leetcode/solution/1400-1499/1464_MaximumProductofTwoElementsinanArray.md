---
title: "1464_MaximumProductofTwoElementsinanArray"
date: 2025-10-06T00:42:37+08:00
weight: 1464
tags: [数组, 排序, 堆（优先队列）]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1464. 数组中两元素的最大乘积](https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array)

[English Version](../en/1464-64/1464_MaximumProductofTwoElementsinanArray)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，请你选择数组的两个不同下标 <code>i</code> 和 <code>j</code><em>，</em>使 <code>(nums[i]-1)*(nums[j]-1)</code> 取得最大值。</p>

<p>请你计算并返回该式的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,2]
<strong>输出：</strong>12 
<strong>解释：</strong>如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,7]
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：暴力枚举

双重循环，枚举所有的下标对，求出 $(nums[i]-1) \times (nums[j]-1)$ 的最大值。其中 $i \neq j$。

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### PHP



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序

对 $nums$ 进行排序，取最后两个元素，计算乘积 $(nums[n-1]-1) \times (nums[n-2]-1)$ 即可。

时间复杂度 $O(nlogn)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：一次遍历

遍历 $nums$，维护最大值 $a$ 和次大值 $b$。遍历结束，返回 $(a-1) \times (b-1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        a = b = 0
        for v in nums:
            if v > a:
                a, b = v, a
            elif v > b:
                b = v
        return (a - 1) * (b - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProduct(int[] nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProduct(nums []int) int {
	a, b := 0, 0
	for _, v := range nums {
		if v > a {
			b, a = a, v
		} else if v > b {
			b = v
		}
	}
	return (a - 1) * (b - 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProduct(nums: number[]): number {
    let max = 0;
    let submax = 0;
    for (const num of nums) {
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut max = 0;
        let mut submax = 0;
        for &num in nums.iter() {
            if num > max {
                submax = max;
                max = num;
            } else if num > submax {
                submax = num;
            }
        }
        (max - 1) * (submax - 1)
    }
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
    function maxProduct($nums) {
        $max = 0;
        $submax = 0;
        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] > $max) {
                $submax = $max;
                $max = $nums[$i];
            } elseif ($nums[$i] > $submax) {
                $submax = $nums[$i];
            }
        }
        return ($max - 1) * ($submax - 1);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int maxProduct(int* nums, int numsSize) {
    int max = 0;
    int submax = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        a = b = 0
        for v in nums:
            if v > a:
                a, b = v, a
            elif v > b:
                b = v
        return (a - 1) * (b - 1)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxProduct(int[] nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
int maxProduct(int* nums, int numsSize) {
    int max = 0;
    int submax = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num > max) {
            submax = max;
            max = num;
        } else if (num > submax) {
            submax = num;
        }
    }
    return (max - 1) * (submax - 1);
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int v : nums) {
            if (v > a) {
                b = a;
                a = v;
            } else if (v > b) {
                b = v;
            }
        }
        return (a - 1) * (b - 1);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}