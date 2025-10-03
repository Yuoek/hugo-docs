---
title: "day_0122 "
date: 2025-09-21T10:16:35+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0122 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, b - a) for a, b in pairwise(prices)) 
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

## LeetCode_0122  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 计算股票交易的最大利润（允许多次交易）
        # 使用pairwise函数将相邻两天的价格组成(a, b)对
        # 如果后一天价格b大于前一天价格a，则利润为b-a，否则为0
        # 将所有相邻交易日的利润相加得到总最大利润
        return sum(max(0, b - a) for a, b in pairwise(prices))
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

## LeetCode_0122  数学解释

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, b - a) for a, b in pairwise(prices)) 
```


这段代码使用了**贪心算法**的数学思想来解决股票买卖问题。

## 数学思想解释：

**核心思想**：将整体最优解分解为局部最优解的累加

1. **局部最优性原理**：在每一天，如果第二天的价格高于当天（b > a），就获得这个差价作为利润；如果价格下跌（b ≤ a），就不操作（利润为0）

2. **数学表达式**：`max(0, b - a)` 表示单次交易的利润函数
   - 当 b > a 时：利润 = b - a
   - 当 b ≤ a 时：利润 = 0

3. **整体最优解**：将所有正的日间差价累加起来 `sum(...)`，这恰好等于多次交易能获得的最大总利润

## 为什么这样是最优的？

- **数学证明**：任何价格序列的总最大利润都可以分解为所有上升段的差价之和
- **时间复杂度**：O(n)，只需遍历一次价格序列
- **空间复杂度**：O(1)，只使用常数空间

这种解法巧妙地利用了**贪心选择性质**：每次只考虑相邻两天的价格关系，通过累加所有正的差价来获得全局最优解。

