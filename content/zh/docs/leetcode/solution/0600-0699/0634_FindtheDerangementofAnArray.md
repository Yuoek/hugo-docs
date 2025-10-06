---
title: "0634_FindtheDerangementofAnArray"
date: 2025-10-06T00:42:37+08:00
weight: 0634
tags: [数学, 动态规划, 组合数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [634. 寻找数组的错位排列 🔒](https://leetcode.cn/problems/find-the-derangement-of-an-array)

[English Version](../en/0634-34/0634_FindtheDerangementofAnArray)

## 题目描述

<!-- description:start -->

<p>在组合数学中，如果一个排列中所有元素都不在原先的位置上，那么这个排列就被称为 <strong>错位排列</strong> 。</p>

<p>给定一个从&nbsp;<code>1</code> 到 <code>n</code>&nbsp;升序排列的数组，返回&nbsp;<em><strong>不同的错位排列</strong> 的数量&nbsp;</em>。由于答案可能非常大，你只需要将答案对 <code>10<sup>9</sup>+7</code> <strong>取余</strong>&nbsp;输出即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 3
<strong>输出:</strong> 2
<strong>解释:</strong> 原始的数组为 [1,2,3]。两个错位排列的数组为 [2,3,1] 和 [3,1,2]。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示长度为 $i$ 的数组的错位排列的数量。初始时 $f[0] = 1$, $f[1] = 0$。答案即为 $f[n]$。

对于长度为 $i$ 的数组，我们考虑将数字 $1$ 放在哪个位置，假设放在第 $j$ 个位置，这里有 $i-1$ 种选择，那么接下来数字 $j$ 可以有两种选择：

-   放在第 $1$ 个位置，那么剩下的 $i - 2$ 个位置可以有 $f[i - 2]$ 种错位排列，因此总共有 $(i - 1) \times f[i - 2]$ 种错位排列；
-   不放在第 $1$ 个位置，那么相当于转化为了长度为 $i - 1$ 的数组的错位排列，因此总共有 $(i - 1) \times f[i - 1]$ 种错位排列。

综上，我们有如下状态转移方程：

$$
f[i] = (i - 1) \times (f[i - 1] + f[i - 2])
$$

最终答案即为 $f[n]$。注意答案的取模操作。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们发现，状态转移方程中只与 $f[i - 1]$ 和 $f[i - 2]$ 有关，因此我们可以使用两个变量 $a$ 和 $b$ 来分别表示 $f[i - 1]$ 和 $f[i - 2]$，从而将空间复杂度降低到 $O(1)$。

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
    def findDerangement(self, n: int) -> int:
        mod = 10**9 + 7
        a, b = 1, 0
        for i in range(2, n + 1):
            a, b = b, ((i - 1) * (a + b)) % mod
        return b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findDerangement(int n) {
        final int mod = (int) 1e9 + 7;
        long a = 1, b = 0;
        for (int i = 2; i <= n; ++i) {
            long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return (int) b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findDerangement(int n) {
        long long a = 1, b = 0;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            long long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDerangement(n int) int {
	a, b := 1, 0
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		a, b = b, (i-1)*(a+b)%mod
	}
	return b
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def findDerangement(self, n: int) -> int:
        mod = 10**9 + 7
        a, b = 1, 0
        for i in range(2, n + 1):
            a, b = b, ((i - 1) * (a + b)) % mod
        return b
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int findDerangement(int n) {
        final int mod = (int) 1e9 + 7;
        long a = 1, b = 0;
        for (int i = 2; i <= n; ++i) {
            long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return (int) b;
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
    int findDerangement(int n) {
        long long a = 1, b = 0;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            long long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}