---
title: "1230_TossStrangeCoins"
date: 2025-10-06T00:42:37+08:00
weight: 1230
tags: [Array, Math, Dynamic Programming, Probability and Statistics]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1230. Toss Strange Coins 🔒](https://leetcode.com/problems/toss-strange-coins)

[中文文档](/solution/1200-1299/1230.Toss%20Strange%20Coins/README.md)

## Description

<!-- description:start -->

<p>You have some coins.&nbsp; The <code>i</code>-th&nbsp;coin has a probability&nbsp;<code>prob[i]</code> of facing heads when tossed.</p>

<p>Return the probability that the number of coins facing heads equals <code>target</code> if you toss every coin exactly once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> prob = [0.4], target = 1
<strong>Output:</strong> 0.40000
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> prob = [0.5,0.5,0.5,0.5,0.5], target = 0
<strong>Output:</strong> 0.03125
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prob.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prob[i] &lt;= 1</code></li>
	<li><code>0 &lt;= target&nbsp;</code><code>&lt;= prob.length</code></li>
	<li>Answers will be accepted as correct if they are within <code>10^-5</code> of the correct answer.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Dynamic Programming

Let $f[i][j]$ represent the probability of having $j$ coins facing up in the first $i$ coins, and initially $f[0][0]=1$. The answer is $f[n][target]$.

Consider $f[i][j]$, where $i \geq 1$. If the current coin is facing down, then $f[i][j] = (1 - p) \times f[i - 1][j]$; If the current coin is facing up and $j \gt 0$, then $f[i][j] = p \times f[i - 1][j - 1]$. Therefore, the state transition equation is:

$$
f[i][j] = \begin{cases}
(1 - p) \times f[i - 1][j], & j = 0 \\
(1 - p) \times f[i - 1][j] + p \times f[i - 1][j - 1], & j \gt 0
\end{cases}
$$

where $p$ represents the probability of the $i$-th coin facing up.

We note that the state $f[i][j]$ is only related to $f[i - 1][j]$ and $f[i - 1][j - 1]$, so we can optimize the two-dimensional space into one-dimensional space.

The time complexity is $O(n \times target)$, and the space complexity is $O(target)$. Where $n$ is the number of coins.

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
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        f = [0] * (target + 1)
        f[0] = 1
        for p in prob:
            for j in range(target, -1, -1):
                f[j] *= 1 - p
                if j:
                    f[j] += p * f[j - 1]
        return f[target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        double[] f = new double[target + 1];
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func probabilityOfHeads(prob []float64, target int) float64 {
	f := make([]float64, target+1)
	f[0] = 1
	for _, p := range prob {
		for j := target; j >= 0; j-- {
			f[j] *= (1 - p)
			if j > 0 {
				f[j] += p * f[j-1]
			}
		}
	}
	return f[target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function probabilityOfHeads(prob: number[], target: number): number {
    const f = new Array(target + 1).fill(0);
    f[0] = 1;
    for (const p of prob) {
        for (let j = target; j >= 0; --j) {
            f[j] *= 1 - p;
            if (j > 0) {
                f[j] += f[j - 1] * p;
            }
        }
    }
    return f[target];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        f = [0] * (target + 1)
        f[0] = 1
        for p in prob:
            for j in range(target, -1, -1):
                f[j] *= 1 - p
                if j:
                    f[j] += p * f[j - 1]
        return f[target]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        double[] f = new double[target + 1];
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
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
    double probabilityOfHeads(vector<double>& prob, int target) {
        double f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}