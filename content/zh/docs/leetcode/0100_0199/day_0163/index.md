---
title: "day_0163 "
date: 2025-09-21T09:03:19+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0163 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findMissingRanges(
        self, nums: List[int], lower: int, upper: int
    ) -> List[List[int]]:
        n = len(nums)
        if n == 0:
            return [[lower, upper]]
        ans = []
        if nums[0] > lower:
            ans.append([lower, nums[0] - 1])
        for a, b in pairwise(nums):
            if b - a > 1:
                ans.append([a + 1, b - 1])
        if nums[-1] < upper:
            ans.append([nums[-1] + 1, upper])
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

## LeetCode_0163  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findMissingRanges(
        self, nums: List[int], lower: int, upper: int
    ) -> List[List[int]]:
        n = len(nums)
        if n == 0:  # 如果数组为空，整个区间[lower, upper]都是缺失的
            return [[lower, upper]]
        ans = []  # 存储所有缺失区间
        if nums[0] > lower:  # 检查lower到第一个数字之间是否有缺失区间
            ans.append([lower, nums[0] - 1])
        for a, b in pairwise(nums):  # 遍历相邻数字对
            if b - a > 1:  # 如果两个数字之间有间隔，说明有缺失区间
                ans.append([a + 1, b - 1])
        if nums[-1] < upper:  # 检查最后一个数字到upper之间是否有缺失区间
            ans.append([nums[-1] + 1, upper])
        return ans  # 返回所有缺失区间列表
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

## LeetCode_0163  数学解释

```python 
class Solution:
    def findMissingRanges(
        self, nums: List[int], lower: int, upper: int
    ) -> List[List[int]]:
        n = len(nums)
        if n == 0:
            return [[lower, upper]]
        ans = []
        if nums[0] > lower:
            ans.append([lower, nums[0] - 1])
        for a, b in pairwise(nums):
            if b - a > 1:
                ans.append([a + 1, b - 1])
        if nums[-1] < upper:
            ans.append([nums[-1] + 1, upper])
        return ans 
```


这段代码使用了**区间合并**的数学思想来解决缺失区间问题。具体来说：

## 核心数学思想：
1. **补集思想**：在[lower, upper]范围内找出不在nums中的所有连续区间
2. **区间边界处理**：通过比较相邻数字的差值来识别缺失区间

## 数学原理分析：

设完整区间为 [L, U] = [lower, upper]
给定有序数组 nums = [a₁, a₂, ..., aₙ]

### 三种情况：
1. **起始缺失区间**：如果 a₁ > L，则缺失区间为 [L, a₁-1]
   - 数学表达式：L ≤ x ≤ a₁-1

2. **中间缺失区间**：对于每对相邻数字 (aᵢ, aᵢ₊₁)，如果 aᵢ₊₁ - aᵢ > 1
   - 则缺失区间为 [aᵢ+1, aᵢ₊₁-1]
   - 数学表达式：aᵢ+1 ≤ x ≤ aᵢ₊₁-1

3. **末尾缺失区间**：如果 aₙ < U，则缺失区间为 [aₙ+1, U]
   - 数学表达式：aₙ+1 ≤ x ≤ U

## 数学性质：
- **单调性**：nums是有序数组，保证了区间的连续性
- **完备性**：这三个情况覆盖了所有可能的缺失区间
- **互斥性**：这些区间彼此不相交

## 时间复杂度：O(n)
空间复杂度：O(1)（不考虑输出空间）

这种解法通过简单的区间边界比较，高效地找出了所有缺失的连续整数区间。

