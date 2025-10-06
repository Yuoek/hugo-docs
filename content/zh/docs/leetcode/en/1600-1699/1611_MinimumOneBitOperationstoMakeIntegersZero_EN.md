---
title: "1611_MinimumOneBitOperationstoMakeIntegersZero"
date: 2025-10-06T00:42:37+08:00
weight: 1611
tags: [Bit Manipulation, Memoization, Dynamic Programming]
---


{{< katex />}}

{{< badge title="Difficulty" value="Hard" >}}

<!-- problem:start -->

# [1611. Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero)

[中文文档](/solution/1600-1699/1611.Minimum%20One%20Bit%20Operations%20to%20Make%20Integers%20Zero/README.md)

## Description

<!-- description:start -->

<p>Given an integer <code>n</code>, you must transform it into <code>0</code> using the following operations any number of times:</p>

<ul>
	<li>Change the rightmost (<code>0<sup>th</sup></code>) bit in the binary representation of <code>n</code>.</li>
	<li>Change the <code>i<sup>th</sup></code> bit in the binary representation of <code>n</code> if the <code>(i-1)<sup>th</sup></code> bit is set to <code>1</code> and the <code>(i-2)<sup>th</sup></code> through <code>0<sup>th</sup></code> bits are set to <code>0</code>.</li>
</ul>

<p>Return <em>the minimum number of operations to transform </em><code>n</code><em> into </em><code>0</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The binary representation of 3 is &quot;11&quot;.
&quot;<u>1</u>1&quot; -&gt; &quot;<u>0</u>1&quot; with the 2<sup>nd</sup> operation since the 0<sup>th</sup> bit is 1.
&quot;0<u>1</u>&quot; -&gt; &quot;0<u>0</u>&quot; with the 1<sup>st</sup> operation.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> The binary representation of 6 is &quot;110&quot;.
&quot;<u>1</u>10&quot; -&gt; &quot;<u>0</u>10&quot; with the 2<sup>nd</sup> operation since the 1<sup>st</sup> bit is 1 and 0<sup>th</sup> through 0<sup>th</sup> bits are 0.
&quot;01<u>0</u>&quot; -&gt; &quot;01<u>1</u>&quot; with the 1<sup>st</sup> operation.
&quot;0<u>1</u>1&quot; -&gt; &quot;0<u>0</u>1&quot; with the 2<sup>nd</sup> operation since the 0<sup>th</sup> bit is 1.
&quot;00<u>1</u>&quot; -&gt; &quot;00<u>0</u>&quot; with the 1<sup>st</sup> operation.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
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
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        return n ^ self.minimumOneBitOperations(n >> 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOneBitOperations(n int) int {
	if n == 0 {
		return 0
	}
	return n ^ minimumOneBitOperations(n>>1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOneBitOperations(n: number): number {
    if (n === 0) {
        return 0;
    }
    return n ^ minimumOneBitOperations(n >> 1);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        return n ^ self.minimumOneBitOperations(n >> 1)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
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
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}