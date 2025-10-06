---
title: "0188_BestTimetoBuyandSellStockIV"
date: 2025-10-06T00:42:37+08:00
weight: 0188
tags: [数组, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv)

[English Version](../en/0188-88/0188_BestTimetoBuyandSellStockIV)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>prices</code> 和一个整数 <code>k</code> ，其中 <code>prices[i]</code> 是某支给定的股票在第 <code>i</code><em> </em>天的价格。</p>

<p>设计一个算法来计算你所能获取的最大利润。你最多可以完成 <code>k</code> 笔交易。也就是说，你最多可以买 <code>k</code> 次，卖 <code>k</code> 次。</p>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 2, prices = [2,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 2, prices = [3,2,6,5,0,3]
<strong>输出：</strong>7
<strong>解释：</strong>在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>1 &lt;= prices.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, k)$，表示从第 $i$ 天开始，最多完成 $j$ 笔交易，以及当前持有股票的状态为 $k$（不持有股票用 $0$ 表示，持有股票用 $1$ 表示）时，所能获得的最大利润。答案即为 $dfs(0, k, 0)$。

函数 $dfs(i, j, k)$ 的执行逻辑如下：

-   如果 $i$ 大于等于 $n$，直接返回 $0$；
-   第 $i$ 天可以不进行任何操作，那么 $dfs(i, j, k) = dfs(i + 1, j, k)$；
-   如果 $k \gt 0$，那么第 $i$ 天可以选择卖出股票，那么 $dfs(i, j, k) = \max(dfs(i + 1, j - 1, 0) + prices[i], dfs(i + 1, j, k))$；
-   否则，如果 $j \gt 0$，那么第 $i$ 天可以选择买入股票，那么 $dfs(i, j, k) = \max(dfs(i + 1, j - 1, 1) - prices[i], dfs(i + 1, j, k))$。

取上述三种情况的最大值即为 $dfs(i, j, k)$ 的值。

过程中，我们可以使用记忆化搜索的方法，将每次计算的结果保存下来，避免重复计算。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别为数组 $prices$ 的长度和 $k$ 的值。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以使用动态规划的方法，定义 $f[i][j][k]$ 表示到第 $i$ 天时，最多交易 $j$ 次（这里我们规定交易次数等于买入次数），且当前持有股票的状态为 $k$ 时，所能获得的最大利润。初始时 $f[i][j][k]=0$。答案即为 $f[n - 1][k][0]$。

当 $i = 0$ 时，股票价格为 $prices[0]$，那么对任意 $j \in [1, k]$，我们有 $f[0][j][1] = -prices[0]$，表示第 $0$ 天买入股票，此时利润为 $-prices[0]$。

当 $i \gt 0$ 时：

-   如果第 $i$ 天不持有股票，可能是第 $i-1$ 天持有股票并且在第 $i$ 天卖出；或者第 $i-1$ 天没持有股票并且第 $i$ 天不进行任何操作。因此 $f[i][j][0] = \max(f[i - 1][j][1] + prices[i], f[i - 1][j][0])$；
-   如果第 $i$ 天持有股票，可能是第 $i-1$ 天没持有股票并且在第 $i$ 天买入；或者第 $i-1$ 天持有股票并且第 $i$ 天不进行任何操作。因此 $f[i][j][1] = \max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1])$。

综上，当 $i \gt 0$ 时，我们可以得到状态转移方程：

$$
\begin{aligned}
f[i][j][0] &= \max(f[i - 1][j][1] + prices[i], f[i - 1][j][0]) \\
f[i][j][1] &= \max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1])
\end{aligned}
$$

最后答案即为 $f[n - 1][k][0]$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别为数组 $prices$ 的长度和 $k$ 的值。

我们注意到，状态 $f[i][]$ 只与状态 $f[i - 1][]$ 有关，因此我们可以优化掉第一维的空间，将空间复杂度降至 $O(k)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        f = [[0] * 2 for _ in range(k + 1)]
        for j in range(1, k + 1):
            f[j][1] = -prices[0]
        for x in prices[1:]:
            for j in range(k, 0, -1):
                f[j][0] = max(f[j][1] + x, f[j][0])
                f[j][1] = max(f[j - 1][0] - x, f[j][1])
        return f[k][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][] f = new int[k + 1][2];
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j][0] = Math.max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = Math.max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[k + 1][2];
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j; --j) {
                f[j][0] = max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(k int, prices []int) int {
	f := make([][2]int, k+1)
	for j := 1; j <= k; j++ {
		f[j][1] = -prices[0]
	}
	for _, x := range prices[1:] {
		for j := k; j > 0; j-- {
			f[j][0] = max(f[j][1]+x, f[j][0])
			f[j][1] = max(f[j-1][0]-x, f[j][1])
		}
	}
	return f[k][0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(k: number, prices: number[]): number {
    const f = Array.from({ length: k + 1 }, () => Array.from({ length: 2 }, () => 0));
    for (let j = 1; j <= k; ++j) {
        f[j][1] = -prices[0];
    }
    for (const x of prices.slice(1)) {
        for (let j = k; j; --j) {
            f[j][0] = Math.max(f[j][1] + x, f[j][0]);
            f[j][1] = Math.max(f[j - 1][0] - x, f[j][1]);
        }
    }
    return f[k][0];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxProfit(int k, int[] prices) {
        int n = prices.Length;
        int[,] f = new int[k + 1, 2];
        for (int j = 1; j <= k; ++j) {
            f[j, 1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j, 0] = Math.Max(f[j, 1] + prices[i], f[j, 0]);
                f[j, 1] = Math.Max(f[j - 1, 0] - prices[i], f[j, 1]);
            }
        }
        return f[k, 0];
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        f = [[0] * 2 for _ in range(k + 1)]
        for j in range(1, k + 1):
            f[j][1] = -prices[0]
        for x in prices[1:]:
            for j in range(k, 0, -1):
                f[j][0] = max(f[j][1] + x, f[j][0])
                f[j][1] = max(f[j - 1][0] - x, f[j][1])
        return f[k][0]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][] f = new int[k + 1][2];
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j][0] = Math.max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = Math.max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[k + 1][2];
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j; --j) {
                f[j][0] = max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}