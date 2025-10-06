---
title: "3370_SmallestNumberWithAllSetBits"
date: 2025-10-06T00:42:37+08:00
weight: 3370
tags: [位运算, 数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3370. 仅含置位位的最小整数](https://leetcode.cn/problems/smallest-number-with-all-set-bits)

[English Version](../en/3370-70/3370_SmallestNumberWithAllSetBits)

## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code>。</p>

<p>返回&nbsp;<strong>大于等于</strong> <code>n</code>&nbsp;且二进制表示仅包含&nbsp;<strong>置位&nbsp;</strong>位的&nbsp;<strong>最小&nbsp;</strong>整数 <code>x</code>&nbsp;。</p>

<p><strong>置位&nbsp;</strong>位指的是二进制表示中值为 <code>1</code> 的位。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 5</span></p>

<p><strong>输出：</strong> <span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<p>7 的二进制表示是 <code>"111"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 10</span></p>

<p><strong>输出：</strong> <span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p>15 的二进制表示是 <code>"1111"</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>3 的二进制表示是 <code>"11"</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：位运算

我们从 $x = 1$ 开始，不断将 $x$ 左移，直到 $x - 1 \geq n$，此时 $x - 1$ 就是我们要找的答案。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

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
    def smallestNumber(self, n: int) -> int:
        x = 1
        while x - 1 < n:
            x <<= 1
        return x - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestNumber(int n) {
        int x = 1;
        while (x - 1 < n) {
            x <<= 1;
        }
        return x - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x - 1 < n) {
            x <<= 1;
        }
        return x - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestNumber(n int) int {
	x := 1
	for x-1 < n {
		x <<= 1
	}
	return x - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestNumber(n: number): number {
    let x = 1;
    while (x - 1 < n) {
        x <<= 1;
    }
    return x - 1;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def smallestNumber(self, n: int) -> int:
        x = 1
        while x - 1 < n:
            x <<= 1
        return x - 1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int smallestNumber(int n) {
        int x = 1;
        while (x - 1 < n) {
            x <<= 1;
        }
        return x - 1;
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
    int smallestNumber(int n) {
        int x = 1;
        while (x - 1 < n) {
            x <<= 1;
        }
        return x - 1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}