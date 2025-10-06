---
title: "3125_MaximumNumberThatMakesResultofBitwiseANDZero"
date: 2025-10-06T00:42:37+08:00
weight: 3125
tags: [贪心, 字符串, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3125. 使得按位与结果为 0 的最大数字 🔒](https://leetcode.cn/problems/maximum-number-that-makes-result-of-bitwise-and-zero)

[English Version](../en/3125-25/3125_MaximumNumberThatMakesResultofBitwiseANDZero)

## 题目描述

<!-- description:start -->

给定一个整数&nbsp;<code>n</code>，返回&nbsp;<strong>最大的</strong>&nbsp;整数&nbsp;<code>x</code> 使得&nbsp;<code>x &lt;= n</code>，并且所有在范围 <code>[x, n]</code>&nbsp;内的数字的按位&nbsp;<code>AND</code>&nbsp;为 0。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 7</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>[6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为&nbsp;6。</p>

<p><code>[5, 6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 4。</p>

<p><code>[4, 5, 6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 4。</p>

<p><code>[3, 4, 5, 6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 0。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 9</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<p><code>[7, 8, 9]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 0。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 17</span></p>

<p><strong>输出：</strong><span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p><code>[15, 16, 17]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 0。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以找到 $n$ 的二进制表示中最高位的 $1$，那么最大的 $x$ 一定小于 $n$ 且该位为 $0$，其他低位均为 $1$，即 $x = 2^{\textit{最高位的位数} - 1} - 1$。这是因为 $x \textit{ and } (x + 1) = 0$ 一定成立。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

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
    def maxNumber(self, n: int) -> int:
        return (1 << (n.bit_length() - 1)) - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxNumber(long n) {
        return (1L << (63 - Long.numberOfLeadingZeros(n))) - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxNumber(long long n) {
        return (1LL << (63 - __builtin_clzll(n))) - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumber(n int64) int64 {
	return int64(1<<(bits.Len64(uint64(n))-1)) - 1
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxNumber(self, n: int) -> int:
        return (1 << (n.bit_length() - 1)) - 1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public long maxNumber(long n) {
        return (1L << (63 - Long.numberOfLeadingZeros(n))) - 1;
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
    long long maxNumber(long long n) {
        return (1LL << (63 - __builtin_clzll(n))) - 1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}