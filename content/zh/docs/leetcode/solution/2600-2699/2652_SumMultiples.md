---
title: "2652_SumMultiples"
date: 2025-10-06T00:42:37+08:00
weight: 2652
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2652. 倍数求和](https://leetcode.cn/problems/sum-multiples)

[English Version](../en/2652-52/2652_SumMultiples)

## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> ，请你计算在 <code>[1，n]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数之和。</p>

<p>返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>21
<strong>解释：</strong>在 <code>[1, 7]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数分别是 <code>3</code>、<code>5</code>、<code>6</code>、<code>7</code> 。数字之和为 <code>21</code>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>40
<strong>解释：</strong>在 <code>[1, 10]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数分别是 <code>3</code>、<code>5</code>、<code>6</code>、<code>7</code>、<code>9</code>、<code>10</code> 。数字之和为 <code>40</code>。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>30
<strong>解释：</strong>在 <code>[1, 9]</code> 范围内能被 <code>3</code>、<code>5</code>、<code>7</code> 整除的所有整数分别是 <code>3</code>、<code>5</code>、<code>6</code>、<code>7</code>、<code>9</code> 。数字之和为 <code>30</code>。
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li>1 &lt;= n &lt;= 10<sup>3</sup></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举

我们直接枚举 $[1,..n]$ 中的每一个数 $x$，如果 $x$ 能被 $3$, $5$, $7$ 整除，那么就将 $x$ 累加到答案中。

枚举结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(1)$。

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

### 方法二：数学（容斥原理）

我们定义函数 $f(x)$ 表示 $[1,..n]$ 中能被 $x$ 整除的数之和，那么一共有 $m = \left\lfloor \frac{n}{x} \right\rfloor$ 个数能被 $x$ 整除，这些数字分别为 $x$, $2x$, $3x$, $\cdots$, $mx$，构成一个等差数列，首项为 $x$，末项为 $mx$，项数为 $m$，因此 $f(x) = \frac{(x + mx) \times m}{2}$。

根据容斥原理，我们可以得到答案为：

$$
f(3) + f(5) + f(7) - f(3 \times 5) - f(3 \times 7) - f(5 \times 7) + f(3 \times 5 \times 7)
$$

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

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

### 方法三

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