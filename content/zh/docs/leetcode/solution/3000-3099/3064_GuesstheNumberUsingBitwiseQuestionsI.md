---
title: "3064_GuesstheNumberUsingBitwiseQuestionsI"
date: 2025-10-06T00:42:37+08:00
weight: 3064
tags: [位运算, 交互]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3064. 使用按位查询猜测数字 I 🔒](https://leetcode.cn/problems/guess-the-number-using-bitwise-questions-i)

[English Version](../en/3064-64/3064_GuesstheNumberUsingBitwiseQuestionsI)

## 题目描述

<!-- description:start -->

<p>你需要找到一个数字&nbsp;<code>n</code>。</p>

<p>这里有一个预定义的 API&nbsp;<code>int commonSetBits(int num)</code>，它返回&nbsp;<code>n</code> 和 <code>num</code> 在二进制表示的同一位置上都是 1 的位数。换句话说，它返回&nbsp;<code>n &amp; num</code>&nbsp;的 <span data-keyword="set-bit">设置位</span> 数量，其中&nbsp;<code>&amp;</code>&nbsp;是按位&nbsp;<code>AND</code>&nbsp;运算符。</p>

<p>返回数字&nbsp;<code>n</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 31

<strong>输出：</strong>31

<strong>解释：</strong>能够证明使用给定的 API 找到 31 是可能的。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 33

<strong>输出：</strong>33

<strong>解释：</strong>能够证明使用给定的 API 找到 33 是可能的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>30</sup> - 1</code></li>
	<li><code>0 &lt;= num &lt;= 2<sup>30</sup> - 1</code></li>
	<li>如果你查询的&nbsp;<code>num</code>&nbsp;超出了给定的范围，输出就不可靠。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举 $2$ 的幂次方，然后调用 `commonSetBits` 方法，如果返回值大于 $0$，则说明 $n$ 的二进制表示中的对应位是 $1$。

时间复杂度 $O(\log n)$，本题中 $n \le 2^{30}$。空间复杂度 $O(1)$。

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
# Definition of commonSetBits API.
# def commonSetBits(num: int) -> int:


class Solution:
    def findNumber(self) -> int:
        return sum(1 << i for i in range(32) if commonSetBits(1 << i))
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i) > 0) {
                n |= 1 << i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i)) {
                n |= 1 << i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition of commonSetBits API.
 * func commonSetBits(num int) int;
 */

func findNumber() (n int) {
	for i := 0; i < 32; i++ {
		if commonSetBits(1<<i) > 0 {
			n |= 1 << i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition of commonSetBits API.
 * var commonSetBits = function(num: number): number {}
 */

function findNumber(): number {
    let n = 0;
    for (let i = 0; i < 32; ++i) {
        if (commonSetBits(1 << i)) {
            n |= 1 << i;
        }
    }
    return n;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
# Definition of commonSetBits API.
# def commonSetBits(num: int) -> int:


class Solution:
    def findNumber(self) -> int:
        return sum(1 << i for i in range(32) if commonSetBits(1 << i))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
/**
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i) > 0) {
                n |= 1 << i;
            }
        }
        return n;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i)) {
                n |= 1 << i;
            }
        }
        return n;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}