---
title: "1464_MaximumProductofTwoElementsinanArray"
date: 2025-10-06T00:42:37+08:00
weight: 1464
tags: [Array, Sorting, Heap (Priority Queue)]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [1464. Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array)

[中文文档](/solution/1400-1499/1464.Maximum%20Product%20of%20Two%20Elements%20in%20an%20Array/README.md)

## Description

<!-- description:start -->

Given the array of integers <code>nums</code>, you will choose two different indices <code>i</code> and <code>j</code> of that array. <em>Return the maximum value of</em> <code>(nums[i]-1)\*(nums[j]-1)</code>.

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,5,2]
<strong>Output:</strong> 12 
<strong>Explanation:</strong> If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,4,5]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,7]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

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

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3

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