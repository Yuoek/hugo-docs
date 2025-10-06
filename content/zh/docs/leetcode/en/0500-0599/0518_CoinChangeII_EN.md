---
title: "0518_CoinChangeII"
date: 2025-10-06T00:42:37+08:00
weight: 0518
tags: [Array, Dynamic Programming]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [518. Coin Change II](https://leetcode.com/problems/coin-change-ii)

[中文文档](/solution/0500-0599/0518.Coin%20Change%20II/README.md)

## Description

<!-- description:start -->

<p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>amount</code> representing a total amount of money.</p>

<p>Return <em>the number of combinations that make up that amount</em>. If that amount of money cannot be made up by any combination of the coins, return <code>0</code>.</p>

<p>You may assume that you have an infinite number of each kind of coin.</p>

<p>The answer is <strong>guaranteed</strong> to fit into a signed <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> amount = 5, coins = [1,2,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> amount = 3, coins = [2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> the amount of 3 cannot be made up just with coins of 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> amount = 10, coins = [10]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 300</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 5000</code></li>
	<li>All the values of <code>coins</code> are <strong>unique</strong>.</li>
	<li><code>0 &lt;= amount &lt;= 5000</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Dynamic Programming (Complete Knapsack)

We define $f[i][j]$ as the number of coin combinations to make up the amount $j$ using the first $i$ types of coins. Initially, $f[0][0] = 1$, and the values of other positions are all $0$.

We can enumerate the quantity $k$ of the last coin used, then we have equation one:

$$
f[i][j] = f[i - 1][j] + f[i - 1][j - x] + f[i - 1][j - 2 \times x] + \cdots + f[i - 1][j - k \times x]
$$

where $x$ represents the face value of the $i$-th type of coin.

Let $j = j - x$, then we have equation two:

$$
f[i][j - x] = f[i - 1][j - x] + f[i - 1][j - 2 \times x] + \cdots + f[i - 1][j - k \times x]
$$

Substituting equation two into equation one, we can get the following state transition equation:

$$
f[i][j] = f[i - 1][j] + f[i][j - x]
$$

The final answer is $f[m][n]$.

The time complexity is $O(m \times n)$, and the space complexity is $O(m \times n)$. Where $m$ and $n$ are the number of types of coins and the total amount, respectively.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

We notice that $f[i][j]$ is only related to $f[i - 1][j]$ and $f[i][j - x]$. Therefore, we can optimize the two-dimensional array into a one-dimensional array, reducing the space complexity to $O(n)$.

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
    def change(self, amount: int, coins: List[int]) -> int:
        n = amount
        f = [1] + [0] * n
        for x in coins:
            for j in range(x, n + 1):
                f[j] += f[j - x]
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int change(int amount, int[] coins) {
        int n = amount;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = amount;
        unsigned f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func change(amount int, coins []int) int {
	n := amount
	f := make([]int, n+1)
	f[0] = 1
	for _, x := range coins {
		for j := x; j <= n; j++ {
			f[j] += f[j-x]
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function change(amount: number, coins: number[]): number {
    const n = amount;
    const f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] += f[j - x];
        }
    }
    return f[n];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = amount
        f = [1] + [0] * n
        for x in coins:
            for j in range(x, n + 1):
                f[j] += f[j - x]
        return f[n]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int change(int amount, int[] coins) {
        int n = amount;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
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
    int change(int amount, vector<int>& coins) {
        int n = amount;
        unsigned f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}