---
title: "day_0188 "
date: 2025-09-21T08:10:23+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0188 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i >= len(prices):
                return 0
            ans = dfs(i + 1, j, k)
            if k:
                ans = max(ans, prices[i] + dfs(i + 1, j, 0))
            elif j:
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1))
            return ans

        return dfs(0, k, 0) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[n][k + 1][2];
        memset(f, -1, sizeof(f));
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = dfs(i + 1, j, k);
            if (k) {
                ans = max(ans, prices[i] + dfs(i + 1, j, 0));
            } else if (j) {
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, k, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Integer[][][] f;
    private int[] prices;
    private int n;

    public int maxProfit(int k, int[] prices) {
        n = prices.length;
        this.prices = prices;
        f = new Integer[n][k + 1][2];
        return dfs(0, k, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i >= n) {
            return 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, k);
        if (k > 0) {
            ans = Math.max(ans, prices[i] + dfs(i + 1, j, 0));
        } else if (j > 0) {
            ans = Math.max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
        }
        return f[i][j][k] = ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0188  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        @cache  # 使用缓存装饰器来存储已计算的结果，避免重复计算
        def dfs(i: int, j: int, k: int) -> int:  # 定义深度优先搜索函数，i:当前天数，j:剩余交易次数，k:当前是否持有股票(0未持有，1持有)
            if i >= len(prices):  # 如果已经遍历完所有天数
                return 0  # 返回0利润
            
            ans = dfs(i + 1, j, k)  # 不进行任何操作，直接跳到下一天
            
            if k:  # 如果当前持有股票
                ans = max(ans, prices[i] + dfs(i + 1, j, 0))  # 卖出当前股票，获得利润，并将状态改为未持有
            elif j:  # 如果当前未持有股票且还有交易次数
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1))  # 买入股票，花费成本，减少一次交易次数，并将状态改为持有
            
            return ans  # 返回最大利润

        return dfs(0, k, 0)  # 从第0天开始，初始有k次交易机会，初始未持有股票
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[n][k + 1][2];
        memset(f, -1, sizeof(f));
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = dfs(i + 1, j, k);
            if (k) {
                ans = max(ans, prices[i] + dfs(i + 1, j, 0));
            } else if (j) {
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, k, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Integer[][][] f;
    private int[] prices;
    private int n;

    public int maxProfit(int k, int[] prices) {
        n = prices.length;
        this.prices = prices;
        f = new Integer[n][k + 1][2];
        return dfs(0, k, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i >= n) {
            return 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, k);
        if (k > 0) {
            ans = Math.max(ans, prices[i] + dfs(i + 1, j, 0));
        } else if (j > 0) {
            ans = Math.max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
        }
        return f[i][j][k] = ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0188  数学解释

```python 
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i >= len(prices):
                return 0
            ans = dfs(i + 1, j, k)
            if k:
                ans = max(ans, prices[i] + dfs(i + 1, j, 0))
            elif j:
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1))
            return ans

        return dfs(0, k, 0) 
```


这段代码使用了**动态规划**和**记忆化搜索**的数学思想来解决股票交易问题。

## 数学思想解析

### 1. 状态定义
定义状态 `dfs(i, j, k)` 表示：
- `i`: 当前考虑的价格索引
- `j`: 剩余可交易次数
- `k`: 当前是否持有股票 (0=未持有，1=持有)

### 2. 状态转移方程
基于**最优子结构**思想：
- **不操作**：`dfs(i+1, j, k)` - 保持当前状态
- **如果持有股票**：`prices[i] + dfs(i+1, j, 0)` - 卖出股票
- **如果未持有且有交易次数**：`-prices[i] + dfs(i+1, j-1, 1)` - 买入股票

### 3. 边界条件
当 `i >= len(prices)` 时，返回 0（无法再进行交易）

### 4. 记忆化搜索
使用 `@cache` 装饰器避免重复计算相同状态，体现了**空间换时间**的优化思想

## 数学意义
该算法通过**递归+记忆化**实现了动态规划，将复杂问题分解为重叠子问题，每个状态的最优解依赖于后续状态的最优解，体现了**贝尔曼最优性原理**。

时间复杂度：O(n×k)（n为价格天数，k为交易次数限制）
空间复杂度：O(n×k)（用于存储记忆化状态）


