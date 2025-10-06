---
title: "2177_FindThreeConsecutiveIntegersThatSumtoaGivenNumber"
date: 2025-10-06T00:42:37+08:00
weight: 2177
tags: [数学, 模拟]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2177. 找到和为给定整数的三个连续整数](https://leetcode.cn/problems/find-three-consecutive-integers-that-sum-to-a-given-number)

[English Version](../en/2177-77/2177_FindThreeConsecutiveIntegersThatSumtoaGivenNumber)

## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>num</code>&nbsp;，请你返回三个连续的整数，它们的&nbsp;<strong>和</strong>&nbsp;为<em>&nbsp;</em><code>num</code>&nbsp;。如果&nbsp;<code>num</code>&nbsp;无法被表示成三个连续整数的和，请你返回一个 <strong>空</strong>&nbsp;数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>num = 33
<b>输出：</b>[10,11,12]
<b>解释：</b>33 可以表示为 10 + 11 + 12 = 33 。
10, 11, 12 是 3 个连续整数，所以返回 [10, 11, 12] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>num = 4
<b>输出：</b>[]
<b>解释：</b>没有办法将 4 表示成 3 个连续整数的和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数学

我们假设三个连续的整数分别为 $x-1$, $x$, $x+1$，则它们的和为 $3x$，因此 $\textit{num}$ 必须是 $3$ 的倍数。如果 $\textit{num}$ 不是 $3$ 的倍数，则无法表示成三个连续整数的和，返回空数组。否则，令 $x = \frac{\textit{num}}{3}$，则 $x-1$, $x$, $x+1$ 就是三个连续整数，它们的和为 $\textit{num}$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        x, mod = divmod(num, 3)
        return [] if mod else [x - 1, x, x + 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] sumOfThree(long num) {
        if (num % 3 != 0) {
            return new long[] {};
        }
        long x = num / 3;
        return new long[] {x - 1, x, x + 1};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3) {
            return {};
        }
        long long x = num / 3;
        return {x - 1, x, x + 1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfThree(num int64) []int64 {
	if num%3 != 0 {
		return []int64{}
	}
	x := num / 3
	return []int64{x - 1, x, x + 1}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfThree(num: number): number[] {
    if (num % 3) {
        return [];
    }
    const x = Math.floor(num / 3);
    return [x - 1, x, x + 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_three(num: i64) -> Vec<i64> {
        if num % 3 != 0 {
            return Vec::new();
        }
        let x = num / 3;
        vec![x - 1, x, x + 1]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num
 * @return {number[]}
 */
var sumOfThree = function (num) {
    if (num % 3) {
        return [];
    }
    const x = Math.floor(num / 3);
    return [x - 1, x, x + 1];
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        x, mod = divmod(num, 3)
        return [] if mod else [x - 1, x, x + 1]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public long[] sumOfThree(long num) {
        if (num % 3 != 0) {
            return new long[] {};
        }
        long x = num / 3;
        return new long[] {x - 1, x, x + 1};
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
    vector<long long> sumOfThree(long long num) {
        if (num % 3) {
            return {};
        }
        long long x = num / 3;
        return {x - 1, x, x + 1};
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}