---
title: "2595_NumberofEvenandOddBits"
date: 2025-10-06T00:42:37+08:00
weight: 2595
tags: [Bit Manipulation]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2595. Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits)

[中文文档](/solution/2500-2599/2595.Number%20of%20Even%20and%20Odd%20Bits/README.md)

## Description

<!-- description:start -->

<p>You are given a <strong>positive</strong> integer <code>n</code>.</p>

<p>Let <code>even</code> denote the number of even indices in the binary representation of <code>n</code> with value 1.</p>

<p>Let <code>odd</code> denote the number of odd indices in the binary representation of <code>n</code> with value 1.</p>

<p>Note that bits are indexed from <strong>right to left</strong> in the binary representation of a number.</p>

<p>Return the array <code>[even, odd]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 50</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2]</span></p>

<p><strong>Explanation:</strong></p>

<p>The binary representation of 50 is <code>110010</code>.</p>

<p>It contains 1 on indices 1, 4, and 5.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,1]</span></p>

<p><strong>Explanation:</strong></p>

<p>The binary representation of 2 is <code>10</code>.</p>

<p>It contains 1 only on index 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Enumerate

According to the problem description, enumerate the binary representation of $n$ from the low bit to the high bit. If the bit is $1$, add $1$ to the corresponding counter according to whether the index of the bit is odd or even.

The time complexity is $O(\log n)$ and the space complexity is $O(1)$. Where $n$ is the given integer.

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

### Solution 2: Bit Manipulation

We can define a mask $\textit{mask} = \text{0x5555}$, which is represented in binary as $\text{0101 0101 0101 0101}_2$. Then, performing a bitwise AND operation between $n$ and $\textit{mask}$ will give us the bits at even indices in the binary representation of $n$. Performing a bitwise AND operation between $n$ and the complement of $\textit{mask}$ will give us the bits at odd indices in the binary representation of $n$. We can count the number of 1s in these two results.

The time complexity is $O(1)$, and the space complexity is $O(1)$. Here, $n$ is the given integer.

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
    def evenOddBit(self, n: int) -> List[int]:
        mask = 0x5555
        even = (n & mask).bit_count()
        odd = (n & ~mask).bit_count()
        return [even, odd]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] evenOddBit(int n) {
        int mask = 0x5555;
        int even = Integer.bitCount(n & mask);
        int odd = Integer.bitCount(n & ~mask);
        return new int[] {even, odd};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int mask = 0x5555;
        int even = __builtin_popcount(n & mask);
        int odd = __builtin_popcount(n & ~mask);
        return {even, odd};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func evenOddBit(n int) []int {
	mask := 0x5555
	even := bits.OnesCount32(uint32(n & mask))
	odd := bits.OnesCount32(uint32(n & ^mask))
	return []int{even, odd}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function evenOddBit(n: number): number[] {
    const mask = 0x5555;
    const even = bitCount(n & mask);
    const odd = bitCount(n & ~mask);
    return [even, odd];
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
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        let mask: i32 = 0x5555;
        let even = (n & mask).count_ones() as i32;
        let odd = (n & !mask).count_ones() as i32;
        vec![even, odd]
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        mask = 0x5555
        even = (n & mask).bit_count()
        odd = (n & ~mask).bit_count()
        return [even, odd]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] evenOddBit(int n) {
        int mask = 0x5555;
        int even = Integer.bitCount(n & mask);
        int odd = Integer.bitCount(n & ~mask);
        return new int[] {even, odd};
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
    vector<int> evenOddBit(int n) {
        int mask = 0x5555;
        int even = __builtin_popcount(n & mask);
        int odd = __builtin_popcount(n & ~mask);
        return {even, odd};
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}