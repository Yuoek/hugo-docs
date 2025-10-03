---
title: "day_0033 "
date: 2025-09-14T10:41:54+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0033 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[n - 1]:
                    left = mid + 1
                else:
                    right = mid
        return left if nums[left] == target else -1 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0033  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)  # 获取数组长度
        left, right = 0, n - 1  # 初始化左右指针
        while left < right:  # 当左指针小于右指针时循环
            mid = (left + right) >> 1  # 计算中间位置（使用位运算右移1位相当于除以2）
            if nums[0] <= nums[mid]:  # 如果中间元素在左半部分（有序部分）
                if nums[0] <= target <= nums[mid]:  # 如果目标值在左半部分范围内
                    right = mid  # 将右指针移动到中间位置
                else:
                    left = mid + 1  # 否则将左指针移动到中间位置+1
            else:  # 如果中间元素在右半部分
                if nums[mid] < target <= nums[n - 1]:  # 如果目标值在右半部分范围内
                    left = mid + 1  # 将左指针移动到中间位置+1
                else:
                    right = mid  # 否则将右指针移动到中间位置
        return left if nums[left] == target else -1  # 检查找到的位置是否为目标值，是则返回索引，否则返回-1
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0033  数学解释

```python 
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[n - 1]:
                    left = mid + 1
                else:
                    right = mid
        return left if nums[left] == target else -1 
```


这段代码实现的是在**旋转排序数组**中搜索目标值的算法。让我用数学思想来解释其核心逻辑：

## 数学思想：二分查找 + 旋转数组的性质

### 1. 旋转数组的数学性质
- 旋转数组可以看作是两个有序子数组的拼接
- 第一个子数组的所有元素 ≥ 第二个子数组的所有元素
- 数组首元素 `nums[0]` 是第一个子数组的最小值，也是整个数组的"分界点"

### 2. 二分查找的数学思想
- **分治思想**：每次将搜索区间减半，时间复杂度 O(log n)
- **不变性原理**：通过判断条件确保目标值始终在搜索区间内

### 3. 核心判断逻辑的数学解释

```python
if nums[0] <= nums[mid]:  # mid在第一个有序子数组中
    if nums[0] <= target <= nums[mid]:  # 目标值在第一个子数组的前半部分
        right = mid      # 搜索左半区间
    else:
        left = mid + 1   # 搜索右半区间
else:                    # mid在第二个有序子数组中  
    if nums[mid] < target <= nums[n - 1]:  # 目标值在第二个子数组的后半部分
        left = mid + 1   # 搜索右半区间
    else:
        right = mid      # 搜索左半区间
```

### 4. 数学证明思路
- **正确性**：通过判断目标值与当前中点、数组首尾元素的关系，可以确定目标值位于哪个有序子数组
- **终止条件**：当 `left == right` 时，区间缩小到单个元素，检查是否为目标值

### 5. 数学复杂度分析
- 时间复杂度：O(log n) - 每次迭代将搜索空间减半
- 空间复杂度：O(1) - 只使用常数额外空间

这个算法巧妙地利用了旋转数组的数学特性，将看似复杂的问题转化为标准的二分查找问题。
