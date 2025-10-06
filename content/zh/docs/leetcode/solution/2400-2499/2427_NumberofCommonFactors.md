---
title: "2427_NumberofCommonFactors"
date: 2025-10-06T00:42:37+08:00
weight: 2427
tags: [数学, 枚举, 数论]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2427. 公因子的数目](https://leetcode.cn/problems/number-of-common-factors)

[English Version](../en/2427-27/2427_NumberofCommonFactors)

## 题目描述

<!-- description:start -->

<p>给你两个正整数 <code>a</code> 和 <code>b</code> ，返回 <code>a</code> 和 <code>b</code> 的 <strong>公</strong> 因子的数目。</p>

<p>如果 <code>x</code> 可以同时整除 <code>a</code> 和 <code>b</code> ，则认为 <code>x</code> 是 <code>a</code> 和 <code>b</code> 的一个 <strong>公因子</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = 12, b = 6
<strong>输出：</strong>4
<strong>解释：</strong>12 和 6 的公因子是 1、2、3、6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = 25, b = 30
<strong>输出：</strong>2
<strong>解释：</strong>25 和 30 的公因子是 1、5 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a, b &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以先算出 $a$ 和 $b$ 的最大公约数 $g$，然后枚举 $[1,..g]$ 中的每个数，判断其是否是 $g$ 的因子，如果是，则答案加一。

时间复杂度 $O(\min(a, b))$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

与方法一类似，我们可以先算出 $a$ 和 $b$ 的最大公约数 $g$，然后枚举最大公约数 $g$ 的所有因子，累加答案。

时间复杂度 $O(\sqrt{\min(a, b)})$，空间复杂度 $O(1)$。

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
    def commonFactors(self, a: int, b: int) -> int:
        g = gcd(a, b)
        ans, x = 0, 1
        while x * x <= g:
            if g % x == 0:
                ans += 1
                ans += x * x < g
            x += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ++ans;
                if (x * x < g) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ans++;
                ans += x * x < g;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func commonFactors(a int, b int) (ans int) {
	g := gcd(a, b)
	for x := 1; x*x <= g; x++ {
		if g%x == 0 {
			ans++
			if x*x < g {
				ans++
			}
		}
	}
	return
}

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function commonFactors(a: number, b: number): number {
    const g = gcd(a, b);
    let ans = 0;
    for (let x = 1; x * x <= g; ++x) {
        if (g % x === 0) {
            ++ans;
            if (x * x < g) {
                ++ans;
            }
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        g = gcd(a, b)
        ans, x = 0, 1
        while x * x <= g:
            if g % x == 0:
                ans += 1
                ans += x * x < g
            x += 1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ++ans;
                if (x * x < g) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
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
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ans++;
                ans += x * x < g;
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}