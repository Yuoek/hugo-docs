---
title: "day_0167 "
date: 2025-09-21T08:55:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0167 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        for i in range(n - 1):
            x = target - numbers[i]
            j = bisect_left(numbers, x, lo=i + 1)
            if j < n and numbers[j] == x:
                return [i + 1, j + 1] 
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

## LeetCode_0167  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)  # 获取数组长度
        for i in range(n - 1):  # 遍历数组，i从0到n-2
            x = target - numbers[i]  # 计算需要查找的补数
            j = bisect_left(numbers, x, lo=i + 1)  # 在i+1到末尾的范围内二分查找补数x
            if j < n and numbers[j] == x:  # 如果找到有效索引且值匹配
                return [i + 1, j + 1]  # 返回1-based索引（题目要求）
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

## LeetCode_0167  数学解释

```python 
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        for i in range(n - 1):
            x = target - numbers[i]
            j = bisect_left(numbers, x, lo=i + 1)
            if j < n and numbers[j] == x:
                return [i + 1, j + 1] 
```


这段代码使用了**二分查找思想**来解决"两数之和 II - 输入有序数组"问题。

## 数学思想解释：

1. **有序性利用**：由于数组已排序，可以利用二分查找来高效定位目标值
2. **补数思想**：对于每个元素 `numbers[i]`，计算其补数 `x = target - numbers[i]`
3. **二分搜索**：在剩余部分 `[i+1, n-1]` 中使用二分查找快速定位补数 `x` 的位置

## 算法流程：
- 遍历每个元素 `i` (0 ≤ i < n-1)
- 计算需要查找的目标值 `x = target - numbers[i]`
- 在 `i+1` 到末尾的区间内二分查找 `x`
- 如果找到且值匹配，返回索引（+1 因为题目要求从1开始计数）

## 时间复杂度：
- 外层循环：O(n)
- 内层二分查找：O(log n)
- 总复杂度：O(n log n)

这种解法充分利用了数组的有序性，比暴力解法 O(n²) 更高效，但比双指针法 O(n) 稍慢。

