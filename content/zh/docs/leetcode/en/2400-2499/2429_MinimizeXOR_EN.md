---
title: "2429_MinimizeXOR"
date: 2025-10-06T00:42:37+08:00
weight: 2429
tags: [Greedy, Bit Manipulation]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [2429. Minimize XOR](https://leetcode.com/problems/minimize-xor)

[中文文档](/solution/2400-2499/2429.Minimize%20XOR/README.md)

## Description

<!-- description:start -->

<p>Given two positive integers <code>num1</code> and <code>num2</code>, find the positive integer <code>x</code> such that:</p>

<ul>
	<li><code>x</code> has the same number of set bits as <code>num2</code>, and</li>
	<li>The value <code>x XOR num1</code> is <strong>minimal</strong>.</li>
</ul>

<p>Note that <code>XOR</code> is the bitwise XOR operation.</p>

<p>Return <em>the integer </em><code>x</code>. The test cases are generated such that <code>x</code> is <strong>uniquely determined</strong>.</p>

<p>The number of <strong>set bits</strong> of an integer is the number of <code>1</code>&#39;s in its binary representation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num1 = 3, num2 = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer <strong>3</strong> has the same number of set bits as num2, and the value <code>3 XOR 3 = 0</code> is minimal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num1 = 1, num2 = 12
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer <strong>3</strong> has the same number of set bits as num2, and the value <code>3 XOR 1 = 2</code> is minimal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1, num2 &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Greedy + Bit Manipulation

According to the problem description, we first calculate the number of set bits $cnt$ in $num2$, then enumerate each bit of $num1$ from high to low. If the bit is $1$, we set the corresponding bit in $x$ to $1$ and decrement $cnt$ by $1$, until $cnt$ is $0$. If $cnt$ is still not $0$ at this point, we start from the low bit and set each bit of $num1$ that is $0$ to $1$, and decrement $cnt$ by $1$, until $cnt$ is $0$.

The time complexity is $O(\log n)$, and the space complexity is $O(1)$. Here, $n$ is the maximum value of $num1$ and $num2$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



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

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt1 = num1.bit_count()
        cnt2 = num2.bit_count()
        while cnt1 > cnt2:
            num1 &= num1 - 1
            cnt1 -= 1
        while cnt1 < cnt2:
            num1 |= num1 + 1
            cnt1 += 1
        return num1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt1 = Integer.bitCount(num1);
        int cnt2 = Integer.bitCount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeXor(num1 int, num2 int) int {
	cnt1 := bits.OnesCount(uint(num1))
	cnt2 := bits.OnesCount(uint(num2))
	for ; cnt1 > cnt2; cnt1-- {
		num1 &= (num1 - 1)
	}
	for ; cnt1 < cnt2; cnt1++ {
		num1 |= (num1 + 1)
	}
	return num1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizeXor(num1: number, num2: number): number {
    let cnt1 = bitCount(num1);
    let cnt2 = bitCount(num2);
    for (; cnt1 > cnt2; --cnt1) {
        num1 &= num1 - 1;
    }
    for (; cnt1 < cnt2; ++cnt1) {
        num1 |= num1 + 1;
    }
    return num1;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt1 = num1.bit_count()
        cnt2 = num2.bit_count()
        while cnt1 > cnt2:
            num1 &= num1 - 1
            cnt1 -= 1
        while cnt1 < cnt2:
            num1 |= num1 + 1
            cnt1 += 1
        return num1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt1 = Integer.bitCount(num1);
        int cnt2 = Integer.bitCount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
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
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}