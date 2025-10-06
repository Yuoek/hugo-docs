---
title: "3622_CheckDivisibilitybyDigitSumandProduct"
date: 2025-10-06T00:42:37+08:00
weight: 3622
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3622. 判断整除性](https://leetcode.cn/problems/check-divisibility-by-digit-sum-and-product)

[English Version](../en/3622-22/3622_CheckDivisibilitybyDigitSumandProduct)

## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code>。请判断 <code>n</code> 是否可以被以下两值之和&nbsp;<strong>整除</strong>：</p>

<ul>
	<li>
	<p><code>n</code> 的&nbsp;<strong>数字和</strong>（即其各个位数之和）。</p>
	</li>
	<li>
	<p><code>n</code> 的&nbsp;<strong>数字积</strong>（即其各个位数之积）。</p>
	</li>
</ul>

<p>如果 <code>n</code> 能被该和整除，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 99</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>因为 99 可以被其数字和 (9 + 9 = 18) 与数字积 (9 * 9 = 81) 之和 (18 + 81 = 99) 整除，因此输出为 true。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 23</span></p>

<p><strong>输出：</strong> <span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>因为 23 无法被其数字和 (2 + 3 = 5) 与数字积 (2 * 3 = 6) 之和 (5 + 6 = 11) 整除，因此输出为 false。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以遍历整数 $n$ 的每一位数字，计算出数字和 $s$ 和数字积 $p$。最后判断 $n$ 是否能被 $s + p$ 整除。

时间复杂度 $O(\log n)$，其中 $n$ 为整数 $n$ 的值。空间复杂度 $O(1)$。

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
    def checkDivisibility(self, n: int) -> bool:
        s, p = 0, 1
        x = n
        while x:
            x, v = divmod(x, 10)
            s += v
            p *= v
        return n % (s + p) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkDivisibility(int n) {
        int s = 0, p = 1;
        int x = n;
        while (x != 0) {
            int v = x % 10;
            x /= 10;
            s += v;
            p *= v;
        }
        return n % (s + p) == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1;
        int x = n;
        while (x != 0) {
            int v = x % 10;
            x /= 10;
            s += v;
            p *= v;
        }
        return n % (s + p) == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkDivisibility(n int) bool {
	s, p := 0, 1
	x := n
	for x != 0 {
		v := x % 10
		x /= 10
		s += v
		p *= v
	}
	return n%(s+p) == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkDivisibility(n: number): boolean {
    let [s, p] = [0, 1];
    let x = n;
    while (x !== 0) {
        const v = x % 10;
        x = Math.floor(x / 10);
        s += v;
        p *= v;
    }
    return n % (s + p) === 0;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s, p = 0, 1
        x = n
        while x:
            x, v = divmod(x, 10)
            s += v
            p *= v
        return n % (s + p) == 0
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean checkDivisibility(int n) {
        int s = 0, p = 1;
        int x = n;
        while (x != 0) {
            int v = x % 10;
            x /= 10;
            s += v;
            p *= v;
        }
        return n % (s + p) == 0;
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
    bool checkDivisibility(int n) {
        int s = 0, p = 1;
        int x = n;
        while (x != 0) {
            int v = x % 10;
            x /= 10;
            s += v;
            p *= v;
        }
        return n % (s + p) == 0;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}