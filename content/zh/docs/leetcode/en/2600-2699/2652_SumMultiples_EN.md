---
title: "2652_SumMultiples"
date: 2025-10-06T00:42:37+08:00
weight: 2652
tags: [Math]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2652. Sum Multiples](https://leetcode.com/problems/sum-multiples)

[中文文档](/solution/2600-2699/2652.Sum%20Multiples/README.md)

## Description

<!-- description:start -->

<p>Given a positive integer <code>n</code>, find the sum of all integers in the range <code>[1, n]</code> <strong>inclusive</strong> that are divisible by <code>3</code>, <code>5</code>, or <code>7</code>.</p>

<p>Return <em>an integer denoting the sum of all numbers in the given range satisfying&nbsp;the constraint.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 7
<strong>Output:</strong> 21
<strong>Explanation:</strong> Numbers in the range <code>[1, 7]</code> that are divisible by <code>3</code>, <code>5,</code> or <code>7 </code>are <code>3, 5, 6, 7</code>. The sum of these numbers is <code>21</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 40
<strong>Explanation:</strong> Numbers in the range <code>[1, 10] that are</code> divisible by <code>3</code>, <code>5,</code> or <code>7</code> are <code>3, 5, 6, 7, 9, 10</code>. The sum of these numbers is 40.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 9
<strong>Output:</strong> 30
<strong>Explanation:</strong> Numbers in the range <code>[1, 9]</code> that are divisible by <code>3</code>, <code>5</code>, or <code>7</code> are <code>3, 5, 6, 7, 9</code>. The sum of these numbers is <code>30</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Enumeration

We directly enumerate every number $x$ in $[1,..n]$, and if $x$ is divisible by $3$, $5$, and $7$, we add $x$ to the answer.

After the enumeration, we return the answer.

The time complexity is $O(n)$, where $n$ is the given integer. The space complexity is $O(1)$.

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

### Solution 2: Mathematics (Inclusion-Exclusion Principle)

We define a function $f(x)$ to represent the sum of numbers in $[1,..n]$ that are divisible by $x$. There are $m = \left\lfloor \frac{n}{x} \right\rfloor$ numbers that are divisible by $x$, which are $x$, $2x$, $3x$, $\cdots$, $mx$, forming an arithmetic sequence with the first term $x$, the last term $mx$, and the number of terms $m$. Therefore, $f(x) = \frac{(x + mx) \times m}{2}$.

According to the inclusion-exclusion principle, we can obtain the answer as:

$$
f(3) + f(5) + f(7) - f(3 \times 5) - f(3 \times 7) - f(5 \times 7) + f(3 \times 5 \times 7)
$$

The time complexity is $O(1)$, and the space complexity is $O(1)$.

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

### Solution 3

<!-- tabs:start -->

#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def f(x: int) -> int:
            m = n // x
            return (x + m * x) * m // 2

        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int sumOfMultiples(int n) {
        this.n = n;
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }

    private int f(int x) {
        int m = n / x;
        return (x + m * x) * m / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfMultiples(int n) {
        auto f = [&](int x) {
            int m = n / x;
            return (x + m * x) * m / 2;
        };
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfMultiples(n int) int {
	f := func(x int) int {
		m := n / x
		return (x + m*x) * m / 2
	}
	return f(3) + f(5) + f(7) - f(3*5) - f(3*7) - f(5*7) + f(3*5*7)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfMultiples(n: number): number {
    const f = (x: number): number => {
        const m = Math.floor(n / x);
        return ((x + m * x) * m) >> 1;
    };
    return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_multiples(n: i32) -> i32 {
        fn f(x: i32, n: i32) -> i32 {
            let m = n / x;
            ((x + m * x) * m) / 2
        }

        f(3, n) + f(5, n) + f(7, n) - f(3 * 5, n) - f(3 * 7, n) - f(5 * 7, n) + f(3 * 5 * 7, n)
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def f(x: int) -> int:
            m = n // x
            return (x + m * x) * m // 2

        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private int n;

    public int sumOfMultiples(int n) {
        this.n = n;
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }

    private int f(int x) {
        int m = n / x;
        return (x + m * x) * m / 2;
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
    int sumOfMultiples(int n) {
        auto f = [&](int x) {
            int m = n / x;
            return (x + m * x) * m / 2;
        };
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}