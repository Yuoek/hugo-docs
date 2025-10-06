---
title: "0309_BestTimetoBuyandSellStockwithCooldown"
date: 2025-10-06T00:42:37+08:00
weight: 0309
tags: [数组, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [309. 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown)

[English Version](../en/0309-09/0309_BestTimetoBuyandSellStockwithCooldown)

## 题目描述

<!-- description:start -->

<p>给定一个整数数组<meta charset="UTF-8" /><code>prices</code>，其中第&nbsp;<em>&nbsp;</em><code>prices[i]</code>&nbsp;表示第&nbsp;<code><em>i</em></code>&nbsp;天的股票价格 。​</p>

<p>设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:</p>

<ul>
	<li>卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。</li>
</ul>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> prices = [1,2,3,0,2]
<strong>输出: </strong>3 
<strong>解释:</strong> 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> prices = [1]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从第 $i$ 天开始，状态为 $j$ 时，能够获得的最大利润。其中 $j$ 的取值为 $0, 1$，分别表示当前不持有股票和持有股票。答案即为 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的执行逻辑如下：

如果 $i \geq n$，表示已经没有股票可以交易了，此时返回 $0$；

否则，我们可以选择不交易，此时 $dfs(i, j) = dfs(i + 1, j)$。我们也可以进行股票交易，如果此时 $j \gt 0$，说明当前持有股票，可以卖出，此时 $dfs(i, j) = prices[i] + dfs(i + 2, 0)$；如果此时 $j = 0$，说明当前不持有股票，可以买入，此时 $dfs(i, j) = -prices[i] + dfs(i + 1, 1)$。取最大值作为函数 $dfs(i, j)$ 的返回值。

答案为 $dfs(0, 0)$。

为了避免重复计算，我们使用记忆化搜索的方法，用一个数组 $f$ 记录 $dfs(i, j)$ 的返回值，如果 $f[i][j]$ 不为 $-1$，说明已经计算过，直接返回 $f[i][j]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $prices$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以用动态规划的方法求解。

我们定义 $f[i][j]$ 表示到第 $i$ 天，且状态为 $j$ 时，能够获得的最大利润。其中 $j$ 的取值为 $0, 1$，分别表示当前不持有股票和持有股票。初始时 $f[0][0] = 0$, $f[0][1] = -prices[0]$。

当 $i \geq 1$ 时，如果当前不持有股票，那么 $f[i][0]$ 可以由 $f[i - 1][0]$ 和 $f[i - 1][1] + prices[i]$ 转移得到，即 $f[i][0] = \max(f[i - 1][0], f[i - 1][1] + prices[i])$；如果当前持有股票，那么 $f[i][1]$ 可以由 $f[i - 1][1]$ 和 $f[i - 2][0] - prices[i]$ 转移得到，即 $f[i][1] = \max(f[i - 1][1], f[i - 2][0] - prices[i])$。最终答案为 $f[n - 1][0]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $prices$ 的长度。

我们注意到，状态 $f[i][]$ 的转移只与 $f[i - 1][]$ 和 $f[i - 2][0]$ 有关，因此我们可以用三个变量 $f$, $f_0$, $f_1$ 代替数组 $f$，将空间复杂度优化到 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



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