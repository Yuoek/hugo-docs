---
title: "day_0035 "
date: 2025-09-14T10:38:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0035 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0035  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)  # 初始化左右指针，左指针指向数组起始位置，右指针指向数组末尾
        while l < r:  # 当左指针小于右指针时循环继续
            mid = (l + r) >> 1  # 计算中间位置，使用位运算右移1位相当于除以2
            if nums[mid] >= target:  # 如果中间值大于等于目标值
                r = mid  # 将右指针移动到中间位置
            else:  # 如果中间值小于目标值
                l = mid + 1  # 将左指针移动到中间位置+1
        return l  # 返回左指针位置，即目标值应该插入的位置
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0035  数学解释

```python 
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l 
```


这段代码使用了**二分查找**的数学思想，具体体现了以下几个重要概念：

1. **分治思想 (Divide and Conquer)**
   - 每次将搜索区间对半分割，将问题规模减半
   - 通过比较中间元素与目标值，确定目标值可能存在的区间

2. **循环不变量 (Loop Invariant)**
   - 初始化：`l=0, r=len(nums)`，确保目标值在区间 [l, r) 内
   - 保持：每次迭代后，目标值的插入位置仍在 [l, r) 区间内
   - 终止：当 `l == r` 时，l 就是正确的插入位置

3. **边界处理**
   - 使用左闭右开区间 [l, r)，这样处理边界更加简洁
   - `r = mid` 和 `l = mid + 1` 的更新方式确保了区间的正确收缩

4. **数学归纳法思想**
   - 通过数学归纳可以证明算法的正确性
   - 对于任意长度的有序数组，算法都能正确找到插入位置

5. **时间复杂度分析**
   - 每次迭代将问题规模减半：O(log n)
   - 空间复杂度：O(1)，只使用了常数个变量

这个算法优雅地运用了二分查找的核心思想，通过数学上的严谨设计确保了在各种边界情况下的正确性。


