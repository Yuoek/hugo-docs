---
title: "day_0153 "
date: 2025-09-21T09:21:21+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0153 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] <= nums[-1]:
            return nums[0]
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[0] <= nums[mid]:
                left = mid + 1
            else:
                right = mid
        return nums[left] 
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

## LeetCode_0153  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] <= nums[-1]:  # 如果数组已经是有序的（没有旋转），直接返回第一个元素
            return nums[0]
        left, right = 0, len(nums) - 1  # 初始化左右指针
        while left < right:  # 二分查找循环
            mid = (left + right) >> 1  # 计算中间位置（使用位运算优化除法）
            if nums[0] <= nums[mid]:  # 如果中间值大于等于第一个元素，说明最小值在右侧
                left = mid + 1  # 移动左指针到mid+1
            else:  # 否则最小值在左侧或就是mid位置
                right = mid  # 移动右指针到mid
        return nums[left]  # 循环结束时left指向最小值
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

## LeetCode_0153  数学解释

```python 
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] <= nums[-1]:
            return nums[0]
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[0] <= nums[mid]:
                left = mid + 1
            else:
                right = mid
        return nums[left] 
```


这段代码使用了**二分查找思想**来解决在旋转排序数组中寻找最小值的问题。

## 核心数学思想：二分查找 + 旋转数组特性

### 1. 问题特性分析
旋转排序数组的特点是：数组被分成两个有序部分，且最小值位于第二个有序部分的起始位置。

### 2. 关键数学观察
- **nums[0] > nums[-1]**：说明数组确实发生了旋转
- **nums[0] <= nums[mid]**：说明中点位于第一个有序部分，最小值在右侧
- **nums[0] > nums[mid]**：说明中点位于第二个有序部分，最小值在左侧或就是中点

### 3. 算法流程的数学解释
1. **初始检查**：如果第一个元素≤最后一个元素，说明数组未旋转或完全旋转，直接返回第一个元素
2. **二分查找**：通过比较中点与第一个元素的值，确定最小值所在的区间
3. **收敛过程**：每次迭代都将搜索区间减半，最终收敛到最小值位置

### 4. 时间复杂度分析
- **O(log n)**：标准的二分查找时间复杂度
- 每次迭代都将搜索空间减半，具有对数级别的效率

### 5. 空间复杂度分析
- **O(1)**：只使用了常数级别的额外空间

这种解法巧妙地利用了旋转数组的数学特性，通过二分查找高效地定位最小值位置。

