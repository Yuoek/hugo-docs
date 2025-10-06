---
title: "0645_SetMismatch"
date: 2025-10-06T00:42:37+08:00
weight: 0645
tags: [Bit Manipulation, Array, Hash Table, Sorting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [645. Set Mismatch](https://leetcode.com/problems/set-mismatch)

[中文文档](/solution/0600-0699/0645.Set%20Mismatch/README.md)

## Description

<!-- description:start -->

<p>You have a set of integers <code>s</code>, which originally contains all the numbers from <code>1</code> to <code>n</code>. Unfortunately, due to some error, one of the numbers in <code>s</code> got duplicated to another number in the set, which results in <strong>repetition of one</strong> number and <strong>loss of another</strong> number.</p>

<p>You are given an integer array <code>nums</code> representing the data status of this set after the error.</p>

<p>Find the number that occurs twice and the number that is missing and return <em>them in the form of an array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2,4]
<strong>Output:</strong> [2,3]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Mathematics

We denote $s_1$ as the sum of all numbers from $[1,..n]$, $s_2$ as the sum of the numbers in the array $nums$ after removing duplicates, and $s$ as the sum of the numbers in the array $nums$.

Then $s - s_2$ is the duplicate number, and $s_1 - s_2$ is the missing number.

The time complexity is $O(n)$, and the space complexity is $O(n)$, where $n$ is the length of the array $nums$. Extra space is needed to store the array after de-duplication.

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

### Solution 2: Hash Table

We can also use a more intuitive method, using a hash table $cnt$ to count the occurrence of each number in the array $nums$.

Next, iterate through $x \in [1, n]$, if $cnt[x] = 2$, then $x$ is the duplicate number, if $cnt[x] = 0$, then $x$ is the missing number.

The time complexity is $O(n)$, and the space complexity is $O(n)$, where $n$ is the length of the array $nums$.

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

### Solution 3: Bit Operation

According to the properties of the XOR operation, for integer $x$, we have $x \oplus x = 0$ and $x \oplus 0 = x$. Therefore, if we perform the XOR operation on all elements in the array $nums$ and all numbers $i \in [1, n]$, we can eliminate the numbers that appear twice, leaving only the XOR result of the missing number and the duplicate number, i.e., $xs = a \oplus b$.

Since these two numbers are not equal, there must be at least one bit in the XOR result that is $1$. We find the lowest bit of $1$ in the XOR result through the $lowbit$ operation, and then divide all numbers in the array $nums$ and all numbers $i \in [1, n]$ into two groups according to whether this bit is $1$. In this way, the two numbers are divided into different groups. The XOR result of one group of numbers is $a$, and the XOR result of the other group is $b$. These two numbers are the answers we are looking for.

Next, we only need to determine which of $a$ and $b$ is the duplicate number and which is the missing number. Therefore, iterate through the array $nums$, for the traversed number $x$, if $x=a$, then $a$ is the duplicate number, return $[a, b]$, otherwise, at the end of the iteration, return $[b, a]$.

The time complexity is $O(n)$, where $n$ is the length of the array $nums$. The space complexity is $O(1)$, only using a constant size of extra space.

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