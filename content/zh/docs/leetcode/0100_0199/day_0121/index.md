---
title: "day_0121 "
date: 2025-09-21T10:17:59+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0121 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mi = 0, inf
        for v in prices:
            ans = max(ans, v - mi)
            mi = min(mi, v)
        return ans 
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

## LeetCode_0121  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mi = 0, inf  # 初始化最大利润为0，最小价格为无穷大
        for v in prices:  # 遍历价格列表中的每个价格
            ans = max(ans, v - mi)  # 更新最大利润：当前利润与之前最大利润的较大值
            mi = min(mi, v)  # 更新最小价格：当前价格与之前最小价格的较小值
        return ans  # 返回最大利润
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

## LeetCode_0121  数学解释

```python 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mi = 0, inf
        for v in prices:
            ans = max(ans, v - mi)
            mi = min(mi, v)
        return ans 
```


这段代码使用了**贪心算法**的思想来解决股票买卖的最佳时机问题（一次交易）。

数学思想解释：
1. **局部最优与全局最优**：在遍历过程中，每一步都记录当前最低价格（局部最优），并用当前价格减去历史最低价来更新最大利润（全局最优）
2. **数学归纳法**：假设前i天的最优解已知，那么第i+1天的最优解可以通过比较当前利润和前i天的最优解来得到
3. **极值追踪**：通过维护两个变量：
   - `mi`：追踪历史最低价格（极小值）
   - `ans`：追踪最大利润（当前价格与历史最低价的差值）

算法过程：
- 初始化：`ans = 0`（最大利润），`mi = inf`（无穷大，表示尚未找到最低价）
- 遍历每个价格`v`：
  - 计算当前利润：`v - mi`，并与已知最大利润比较取最大值
  - 更新历史最低价：比较当前价格与已知最低价取最小值
- 最终返回最大利润

时间复杂度：O(n)，空间复杂度：O(1)，是这个问题的最优解法。
