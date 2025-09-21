---
title: "day_0154 "
date: 2025-09-21T09:19:38+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0154 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
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

## LeetCode_0154  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1  # 初始化左右指针，指向数组首尾
        while left < right:  # 当左指针小于右指针时循环
            mid = (left + right) >> 1  # 计算中间位置，使用位运算右移1位相当于除以2
            if nums[mid] > nums[right]:  # 如果中间值大于右端值，说明最小值在右半部分
                left = mid + 1  # 将左指针移动到mid+1位置
            elif nums[mid] < nums[right]:  # 如果中间值小于右端值，说明最小值在左半部分
                right = mid  # 将右指针移动到mid位置
            else:  # 如果中间值等于右端值（处理重复元素的情况）
                right -= 1  # 右指针左移一位，缩小搜索范围
        return nums[left]  # 循环结束时，左指针指向最小值
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

## LeetCode_0154  数学解释

```python 
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
        return nums[left] 
```


这段代码使用了**二分查找**和**分治思想**来解决在旋转排序数组中寻找最小值的问题。具体数学思想分析如下：

1. **二分查找思想**：
   - 通过不断将搜索区间对半分割（`mid = (left + right) >> 1`），将时间复杂度从O(n)降低到O(log n)
   - 每次迭代都能排除一半的搜索空间，体现了分治策略

2. **旋转数组的性质利用**：
   - 旋转后的数组由两个有序子数组组成，且最小值位于第二个有序子数组的开头
   - 关键观察：最小值右侧的元素都 ≤ 数组最后一个元素，最小值左侧的元素都 ≥ 数组最后一个元素

3. **比较逻辑的数学依据**：
   - `nums[mid] > nums[right]`：说明mid在第一个有序子数组中，最小值在mid右侧 → `left = mid + 1`
   - `nums[mid] < nums[right]`：说明mid在第二个有序子数组中，最小值在mid左侧或就是mid → `right = mid`
   - `nums[mid] == nums[right]`：无法确定最小值位置，但可以安全地缩小右边界 → `right -= 1`

4. **处理重复元素的策略**：
   - 当中间值与右边界值相等时，通过右移右边界来逐步缩小搜索范围
   - 这避免了重复元素导致的二分查找失效问题

5. **收敛性保证**：
   - 循环终止条件 `left < right` 确保最终left和right指向同一个位置
   - 该位置就是最小值所在位置

这种方法巧妙地将旋转数组的查找问题转化为二分查找问题，通过比较中间元素与右边界元素的关系来确定搜索方向，体现了**问题转化**和**分治优化**的数学思想。

