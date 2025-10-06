---
title: "0309_BestTimetoBuyandSellStockwithCooldown"
date: 2025-10-06T00:42:37+08:00
weight: 0309
tags: [Array, Dynamic Programming]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)

[中文文档](/solution/0300-0399/0309.Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown/README.md)

## Description

<!-- description:start -->

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:</p>

<ul>
	<li>After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).</li>
</ul>

<p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,3,0,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> transactions = [buy, sell, cooldown, buy, sell]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Memoization Search

We design a function $dfs(i, j)$, which represents the maximum profit that can be obtained starting from the $i$th day with state $j$. The values of $j$ are $0$ and $1$, respectively representing currently not holding a stock and holding a stock. The answer is $dfs(0, 0)$.

The execution logic of the function $dfs(i, j)$ is as follows:

If $i \geq n$, it means that there are no more stocks to trade, so return $0$;

Otherwise, we can choose not to trade, then $dfs(i, j) = dfs(i + 1, j)$. We can also trade stocks. If $j > 0$, it means that we currently hold a stock and can sell it, then $dfs(i, j) = prices[i] + dfs(i + 2, 0)$. If $j = 0$, it means that we currently do not hold a stock and can buy, then $dfs(i, j) = -prices[i] + dfs(i + 1, 1)$. Take the maximum value as the return value of the function $dfs(i, j)$.

The answer is $dfs(0, 0)$.

To avoid repeated calculations, we use the method of memoization search, and use an array $f$ to record the return value of $dfs(i, j)$. If $f[i][j]$ is not $-1$, it means that it has been calculated, and we can directly return $f[i][j]$.

The time complexity is $O(n)$, and the space complexity is $O(n)$, where $n$ is the length of the array $prices$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Dynamic Programming

We can also use dynamic programming to solve this problem.

We define $f[i][j]$ to represent the maximum profit that can be obtained on the $i$th day with state $j$. The values of $j$ are $0$ and $1$, respectively representing currently not holding a stock and holding a stock. Initially, $f[0][0] = 0$, $f[0][1] = -prices[0]$.

When $i \geq 1$, if we currently do not hold a stock, then $f[i][0]$ can be obtained by transitioning from $f[i - 1][0]$ and $f[i - 1][1] + prices[i]$, i.e., $f[i][0] = \max(f[i - 1][0], f[i - 1][1] + prices[i])$. If we currently hold a stock, then $f[i][1]$ can be obtained by transitioning from $f[i - 1][1]$ and $f[i - 2][0] - prices[i]$, i.e., $f[i][1] = \max(f[i - 1][1], f[i - 2][0] - prices[i])$. The final answer is $f[n - 1][0]$.

The time complexity is $O(n)$, and the space complexity is $O(n)$, where $n$ is the length of the array $prices$.

We notice that the transition of state $f[i][]$ is only related to $f[i - 1][]$ and $f[i - 2][0]$, so we can use three variables $f$, $f_0$, $f_1$ to replace the array $f$, optimizing the space complexity to $O(1)$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3

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
    def maxProfit(self, prices: List[int]) -> int:
        f, f0, f1 = 0, 0, -prices[0]
        for x in prices[1:]:
            f, f0, f1 = f0, max(f0, f1 + x), max(f1, f - x)
        return f0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int[] prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            int g0 = Math.max(f0, f1 + prices[i]);
            f1 = Math.max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int g0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(prices []int) int {
	f, f0, f1 := 0, 0, -prices[0]
	for _, x := range prices[1:] {
		f, f0, f1 = f0, max(f0, f1+x), max(f1, f-x)
	}
	return f0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(prices: number[]): number {
    let [f, f0, f1] = [0, 0, -prices[0]];
    for (const x of prices.slice(1)) {
        [f, f0, f1] = [f0, Math.max(f0, f1 + x), Math.max(f1, f - x)];
    }
    return f0;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        f, f0, f1 = 0, 0, -prices[0]
        for x in prices[1:]:
            f, f0, f1 = f0, max(f0, f1 + x), max(f1, f - x)
        return f0
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxProfit(int[] prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            int g0 = Math.max(f0, f1 + prices[i]);
            f1 = Math.max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
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
    int maxProfit(vector<int>& prices) {
        int f = 0, f0 = 0, f1 = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int g0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f - prices[i]);
            f = f0;
            f0 = g0;
        }
        return f0;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}