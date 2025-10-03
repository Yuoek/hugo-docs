---
title: "day_0134 "
date: 2025-09-21T09:54:16+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0134 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        i = j = n - 1
        cnt = s = 0
        while cnt < n:
            s += gas[j] - cost[j]
            cnt += 1
            j = (j + 1) % n
            while s < 0 and cnt < n:
                i -= 1
                s += gas[i] - cost[i]
                cnt += 1
        return -1 if s < 0 else i 
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

## LeetCode_0134  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)  # 获取加油站数量
        i = j = n - 1  # 初始化起点和终点指针，都指向最后一个加油站
        cnt = s = 0  # cnt: 已访问的加油站计数，s: 当前油量
        while cnt < n:  # 当未访问完所有加油站时循环
            s += gas[j] - cost[j]  # 从j站加油并消耗到下一站的油量
            cnt += 1  # 已访问加油站数+1
            j = (j + 1) % n  # j指针向前移动（环形处理）
            while s < 0 and cnt < n:  # 如果油量为负且还有未访问的加油站
                i -= 1  # 起点向前移动（尝试更早的起点）
                s += gas[i] - cost[i]  # 从新起点加油并计算消耗
                cnt += 1  # 已访问加油站数+1
        return -1 if s < 0 else i  # 如果最终油量仍为负返回-1，否则返回起点索引
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

## LeetCode_0134  数学解释

```python 
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        i = j = n - 1
        cnt = s = 0
        while cnt < n:
            s += gas[j] - cost[j]
            cnt += 1
            j = (j + 1) % n
            while s < 0 and cnt < n:
                i -= 1
                s += gas[i] - cost[i]
                cnt += 1
        return -1 if s < 0 else i 
```


这段代码使用了**贪心算法**和**双指针技巧**来解决加油站问题。让我用数学思想来解释：

## 核心数学思想

1. **能量守恒思想**：将每个站点视为能量转换点，`gas[j] - cost[j]` 表示净能量增益/损失
2. **前缀和思想**：变量 `s` 维护当前路径的累计净能量
3. **环形遍历思想**：通过模运算 `j = (j + 1) % n` 实现环形遍历

## 算法策略的数学解释

**双指针策略**：
- `i` 指针（左指针）：从后向前移动，寻找可能的起点
- `j` 指针（右指针）：从前向后移动，检查当前路径的可行性

**贪心选择原理**：
当累计净能量 `s < 0` 时，说明当前起点 `i` 不可行，需要向前寻找新的起点。这是因为：
- 如果从站点 `k` 出发无法完成环形，那么 `k` 之前的任何站点作为起点都会在 `k` 处失败
- 因此应该从 `k+1` 开始尝试，这正是代码中 `i -= 1` 的数学依据

## 数学正确性证明

设 `diff[i] = gas[i] - cost[i]`，则问题转化为：
寻找起点 `start`，使得对于所有 `k`（0 ≤ k < n），都有：
```
∑_{i=start}^{(start+k) mod n} diff[i] ≥ 0
```

代码通过维护累计和 `s` 来验证这一条件，当 `s < 0` 时调整起点，确保数学条件始终满足。

## 时间复杂度分析

该算法的时间复杂度为 **O(n)**，因为每个站点最多被访问两次（一次由 `j` 指针，一次由 `i` 指针），体现了高效的数学优化。
