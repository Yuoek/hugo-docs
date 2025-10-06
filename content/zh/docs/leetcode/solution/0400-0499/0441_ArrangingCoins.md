---
title: "0441_ArrangingCoins"
date: 2025-10-06T00:42:37+08:00
weight: 0441
tags: [数学, 二分查找]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [441. 排列硬币](https://leetcode.cn/problems/arranging-coins)

[English Version](../en/0441-41/0441_ArrangingCoins)

## 题目描述

<!-- description:start -->

<p>你总共有&nbsp;<code>n</code><em>&nbsp;</em>枚硬币，并计划将它们按阶梯状排列。对于一个由 <code>k</code> 行组成的阶梯，其第 <code>i</code><em> </em>行必须正好有 <code>i</code><em> </em>枚硬币。阶梯的最后一行 <strong>可能</strong> 是不完整的。</p>

<p>给你一个数字&nbsp;<code>n</code><em> </em>，计算并返回可形成 <strong>完整阶梯行</strong> 的总行数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0441.Arranging%20Coins/images/arrangecoins1-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>2
<strong>解释：</strong>因为第三行不完整，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0441.Arranging%20Coins/images/arrangecoins2-grid.jpg" style="width: 333px; height: 333px;" />
<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>3
<strong>解释：</strong>因为第四行不完整，所以返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数学推导

`(1 + x) * x / 2 <= n`，求解 x。

`(x + 1/2)² <= 2n + 1/4`，即 `x <= sqrt(2n + 1/4) - 1/2`。

由于 2n 可能溢出，故转换为 `x <= sqrt(2) * sqrt(n + 1/8) - 1/2`。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

<!-- tabs:start -->

#### Python3



#### Java



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        while left < right:
            mid = (left + right + 1) >> 1
            if (1 + mid) * mid // 2 <= n:
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int arrangeCoins(int n) {
        long left = 1, right = n;
        while (left < right) {
            long mid = (left + right + 1) >>> 1;
            if ((1 + mid) * mid / 2 <= n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return (int) left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using LL = long;

class Solution {
public:
    int arrangeCoins(int n) {
        LL left = 1, right = n;
        while (left < right) {
            LL mid = left + right + 1 >> 1;
            LL s = (1 + mid) * mid >> 1;
            if (n < s)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrangeCoins(n int) int {
	left, right := 1, n
	for left < right {
		mid := (left + right + 1) >> 1
		if (1+mid)*mid/2 <= n {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        while left < right:
            mid = (left + right + 1) >> 1
            if (1 + mid) * mid // 2 <= n:
                left = mid
            else:
                right = mid - 1
        return left
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int arrangeCoins(int n) {
        long left = 1, right = n;
        while (left < right) {
            long mid = (left + right + 1) >>> 1;
            if ((1 + mid) * mid / 2 <= n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return (int) left;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
using LL = long;

class Solution {
public:
    int arrangeCoins(int n) {
        LL left = 1, right = n;
        while (left < right) {
            LL mid = left + right + 1 >> 1;
            LL s = (1 + mid) * mid >> 1;
            if (n < s)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}