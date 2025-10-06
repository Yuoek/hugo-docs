---
title: "3099_HarshadNumber"
date: 2025-10-06T00:42:37+08:00
weight: 3099
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3099. 哈沙德数](https://leetcode.cn/problems/harshad-number)

[English Version](../en/3099-99/3099_HarshadNumber)

## 题目描述

<!-- description:start -->

<p>如果一个整数能够被其各个数位上的数字之和整除，则称之为<strong> 哈沙德数</strong>（Harshad number）。给你一个整数 <code>x</code> 。如果 <code>x</code> 是 <strong>哈沙德数 </strong>，则返回<em> </em><code>x</code> 各个数位上的数字之和，否则，返回<em> </em><code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 18</span></p>

<p><strong>输出：</strong> <span class="example-io">9</span></p>

<p><strong>解释：</strong></p>

<p><code>x</code> 各个数位上的数字之和为 <code>9</code> 。<code>18</code> 能被 <code>9</code> 整除。因此 <code>18</code> 是哈沙德数，答案是 <code>9</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 23</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong></p>

<p><code>x</code> 各个数位上的数字之和为 <code>5</code> 。<code>23</code> 不能被 <code>5</code> 整除。因此 <code>23</code> 不是哈沙德数，答案是 <code>-1</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 100</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以通过模拟的方法，计算出 $x$ 的各个数位上的数字之和，记为 $s$。如果 $x$ 能被 $s$ 整除，则返回 $s$，否则返回 $-1$。

时间复杂度 $O(\log x)$，其中 $x$ 是输入的整数。空间复杂度 $O(1)$。

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
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s, y = 0, x
        while y:
            s += y % 10
            y //= 10
        return s if x % s == 0 else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfTheDigitsOfHarshadNumber(x int) int {
	s := 0
	for y := x; y > 0; y /= 10 {
		s += y % 10
	}
	if x%s == 0 {
		return s
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfTheDigitsOfHarshadNumber(x: number): number {
    let s = 0;
    for (let y = x; y; y = Math.floor(y / 10)) {
        s += y % 10;
    }
    return x % s === 0 ? s : -1;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s, y = 0, x
        while y:
            s += y % 10
            y //= 10
        return s if x % s == 0 else -1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}