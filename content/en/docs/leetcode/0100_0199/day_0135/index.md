---
title: "day_0135 "
date: 2025-09-21T09:52:45+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0135 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
        return sum(max(a, b) for a, b in zip(left, right)) 
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

## LeetCode_0135  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        left = [1] * n  # 从左向右遍历，每个孩子至少1颗糖
        right = [1] * n  # 从右向左遍历，每个孩子至少1颗糖
        
        # 从左向右遍历：如果当前孩子评分比左边高，糖果数比左边多1
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        
        # 从右向左遍历：如果当前孩子评分比右边高，糖果数比右边多1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
        
        # 取两个方向的最大值作为最终分配，求和得到最少糖果数
        return sum(max(a, b) for a, b in zip(left, right)) 
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

## LeetCode_0135  数学解释

```python 
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
        return sum(max(a, b) for a, b in zip(left, right)) 
```


这段代码使用了**贪心算法**和**双向遍历**的数学思想来解决糖果分配问题：

## 核心数学思想

### 1. 贪心策略 (Greedy Algorithm)
- **局部最优解**：对于每个孩子，只考虑与相邻孩子的评分关系
- **全局最优解**：通过组合所有局部最优解得到整体最优分配

### 2. 双向遍历 (Bidirectional Traversal)
- **从左到右遍历**：确保每个孩子比左边评分低的孩子得到更多糖果
- **从右到左遍历**：确保每个孩子比右边评分低的孩子得到更多糖果

### 3. 约束满足 (Constraint Satisfaction)
- **基本约束**：每个孩子至少得到1颗糖果
- **比较约束**：评分更高的相邻孩子必须得到更多糖果

## 数学解释

设评分数组为 `ratings = [r₀, r₁, ..., rₙ₋₁]`

**左遍历规则**：
```
left[i] = { 1, 如果 rᵢ ≤ rᵢ₋₁
          { left[i-1] + 1, 如果 rᵢ > rᵢ₋₁
```

**右遍历规则**：
```
right[i] = { 1, 如果 rᵢ ≤ rᵢ₊₁
           { right[i+1] + 1, 如果 rᵢ > rᵢ₊₁
```

**最终分配**：
```
candies[i] = max(left[i], right[i])
```

## 为什么这样有效？

这种方法确保了：
1. **单调性**：评分更高的孩子得到更多糖果
2. **最小性**：使用最少的糖果总数满足所有约束
3. **完备性**：同时考虑了左右两个方向的约束关系

时间复杂度：O(n)，空间复杂度：O(n)，是这个问题的最优解法之一。
