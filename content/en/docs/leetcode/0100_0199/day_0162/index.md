---
title: "day_0162 "
date: 2025-09-21T09:05:04+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0162 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left 
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

## LeetCode_0162  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}


```python 
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1  # 初始化左右指针，指向数组首尾
        while left < right:  # 当左指针小于右指针时循环
            mid = (left + right) >> 1  # 计算中间位置，使用位运算右移1位相当于除以2
            if nums[mid] > nums[mid + 1]:  # 如果中间元素大于右侧相邻元素
                right = mid  # 说明峰值在左侧或当前位置，将右指针移到中间位置
            else:  # 否则中间元素小于等于右侧相邻元素
                left = mid + 1  # 说明峰值在右侧，将左指针移到中间位置+1
        return left  # 循环结束时left==right，返回峰值元素的索引
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

## LeetCode_0162  数学解释

```python 
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left 
```


这段代码使用了**二分查找思想**来解决寻找峰值元素的问题。以下是数学思想的解释：

## 核心数学思想：**二分查找 + 局部极值定理**

### 1. **问题特性分析**
- 数组可能包含多个峰值（局部最大值）
- 峰值定义为：`nums[i] > nums[i-1]` 且 `nums[i] > nums[i+1]`
- 边界情况：数组两端可以视为 `nums[-1] = nums[n] = -∞`

### 2. **二分查找的数学基础**
- **关键观察**：如果 `nums[mid] > nums[mid+1]`，那么在 `[left, mid]` 区间内一定存在峰值
- **数学原理**：根据连续函数的极值定理，如果一个区间左端上升、右端下降，中间必然存在极大值点

### 3. **算法步骤的数学解释**
```
while left < right:  # 当区间长度 > 1 时继续
    mid = (left + right) // 2  # 取中点
    
    if nums[mid] > nums[mid + 1]:
        right = mid  # 峰值在左半区间 [left, mid]
    else:
        left = mid + 1  # 峰值在右半区间 [mid+1, right]
```

### 4. **数学证明思路**
- **情况1**：`nums[mid] > nums[mid+1]`
  - 说明当前处于下降趋势
  - 峰值要么在 mid 处，要么在 mid 左侧
  - 因此将搜索范围缩小到 `[left, mid]`

- **情况2**：`nums[mid] <= nums[mid+1]`
  - 说明当前处于上升趋势
  - 峰值一定在 mid 右侧（因为右侧可能有更高的点）
  - 因此将搜索范围缩小到 `[mid+1, right]`

### 5. **时间复杂度分析**
- 每次迭代将搜索区间减半：O(log n)
- 空间复杂度：O(1)（只使用常数额外空间）

这种算法巧妙地利用了数组的局部单调性，通过二分查找快速定位峰值位置。
