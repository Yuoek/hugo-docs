---
title: "1442_CountTripletsThatCanFormTwoArraysofEqualXOR"
date: 2025-10-06T00:42:37+08:00
weight: 1442
tags: [Bit Manipulation, Array, Hash Table, Math, Prefix Sum]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1442. Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor)

[中文文档](/solution/1400-1499/1442.Count%20Triplets%20That%20Can%20Form%20Two%20Arrays%20of%20Equal%20XOR/README.md)

## Description

<!-- description:start -->

<p>Given an array of integers <code>arr</code>.</p>

<p>We want to select three indices <code>i</code>, <code>j</code> and <code>k</code> where <code>(0 &lt;= i &lt; j &lt;= k &lt; arr.length)</code>.</p>

<p>Let&#39;s define <code>a</code> and <code>b</code> as follows:</p>

<ul>
	<li><code>a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]</code></li>
	<li><code>b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]</code></li>
</ul>

<p>Note that <strong>^</strong> denotes the <strong>bitwise-xor</strong> operation.</p>

<p>Return <em>the number of triplets</em> (<code>i</code>, <code>j</code> and <code>k</code>) Where <code>a == b</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,3,1,6,7]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,1,1,1,1]
<strong>Output:</strong> 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 300</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Enumeration

According to the problem description, to find triplets $(i, j, k)$ that satisfy $a = b$, which means $s = a \oplus b = 0$, we only need to enumerate the left endpoint $i$, and then calculate the prefix XOR sum $s$ of the interval $[i, k]$ with $k$ as the right endpoint. If $s = 0$, then for any $j \in [i + 1, k]$, the condition $a = b$ is satisfied, meaning $(i, j, k)$ is a valid triplet. There are $k - i$ such triplets, which we can add to our answer.

After the enumeration is complete, we return the answer.

The time complexity is $O(n^2)$, where $n$ is the length of the array $\textit{arr}$. The space complexity is $O(1)$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans, n = 0, len(arr)
        for i, x in enumerate(arr):
            s = x
            for k in range(i + 1, n):
                s ^= arr[k]
                if s == 0:
                    ans += k - i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countTriplets(int[] arr) {
        int ans = 0, n = arr.length;
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
                }
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
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countTriplets(arr []int) (ans int) {
	for i, x := range arr {
		s := x
		for k := i + 1; k < len(arr); k++ {
			s ^= arr[k]
			if s == 0 {
				ans += k - i
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTriplets(arr: number[]): number {
    const n = arr.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let s = arr[i];
        for (let k = i + 1; k < n; ++k) {
            s ^= arr[k];
            if (s === 0) {
                ans += k - i;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = arr.len();

        for i in 0..n {
            let mut s = arr[i];
            for k in (i + 1)..n {
                s ^= arr[k];
                if s == 0 {
                    ans += (k - i) as i32;
                }
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans, n = 0, len(arr)
        for i, x in enumerate(arr):
            s = x
            for k in range(i + 1, n):
                s ^= arr[k]
                if s == 0:
                    ans += k - i
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countTriplets(int[] arr) {
        int ans = 0, n = arr.length;
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
                }
            }
        }
        return ans;
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
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}