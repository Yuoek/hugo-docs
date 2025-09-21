---
title: "day_0123 "
date: 2025-09-21T10:14:57+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0123 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 第一次买入，第一次卖出，第二次买入，第二次卖出
        f1, f2, f3, f4 = -prices[0], 0, -prices[0], 0
        for price in prices[1:]:
            f1 = max(f1, -price)
            f2 = max(f2, f1 + price)
            f3 = max(f3, f2 - price)
            f4 = max(f4, f3 + price)
        return f4 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0123  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 第一次买入，第一次卖出，第二次买入，第二次卖出
        f1, f2, f3, f4 = -prices[0], 0, -prices[0], 0  # 初始化四个状态变量：第一次买入成本、第一次卖出收益、第二次买入成本、第二次卖出收益
        for price in prices[1:]:  # 从第二天开始遍历股价
            f1 = max(f1, -price)  # 更新第一次买入的最低成本（取当前成本与前一天成本的最小值）
            f2 = max(f2, f1 + price)  # 更新第一次卖出的最大收益（当前收益与前一天收益的最大值）
            f3 = max(f3, f2 - price)  # 更新第二次买入的最低成本（用第一次卖出收益减去当前股价）
            f4 = max(f4, f3 + price)  # 更新第二次卖出的最大收益（当前收益与前一天收益的最大值）
        return f4  # 返回最终的最大收益（允许完成两次交易）
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0123  数学解释

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 第一次买入，第一次卖出，第二次买入，第二次卖出
        f1, f2, f3, f4 = -prices[0], 0, -prices[0], 0
        for price in prices[1:]:
            f1 = max(f1, -price)
            f2 = max(f2, f1 + price)
            f3 = max(f3, f2 - price)
            f4 = max(f4, f3 + price)
        return f4 
```


这段代码使用了**动态规划**和**状态机**的数学思想来解决"最多完成两次交易的最大股票收益"问题。

## 核心数学思想：

### 1. 状态机建模
将投资过程建模为4个状态：
- f1: 第一次买入后的最大收益（持有第一支股票）
- f2: 第一次卖出后的最大收益（无持仓，完成一次交易）
- f3: 第二次买入后的最大收益（持有第二支股票）
- f4: 第二次卖出后的最大收益（无持仓，完成两次交易）

### 2. 动态规划递推
每个状态都基于前一个状态和当前价格进行更新：
- **f1** = max(保持第一次买入状态, 在当前价格第一次买入)
- **f2** = max(保持第一次卖出状态, 在当前价格卖出第一次买入的股票)
- **f3** = max(保持第二次买入状态, 用第一次卖出的收益在当前价格第二次买入)
- **f4** = max(保持第二次卖出状态, 在当前价格卖出第二次买入的股票)

### 3. 最优子结构
每个状态都记录了到当前为止的最优解，确保全局最优解可以通过局部最优解递推得到。

## 数学表达式：
对于第i天的价格price：
```
f1_i = max(f1_{i-1}, -price_i)
f2_i = max(f2_{i-1}, f1_{i-1} + price_i)  
f3_i = max(f3_{i-1}, f2_{i-1} - price_i)
f4_i = max(f4_{i-1}, f3_{i-1} + price_i)
```

这种方法的数学本质是**将复杂问题分解为多个相互关联的子问题**，通过状态转移方程逐步求解，最终得到全局最优解。

