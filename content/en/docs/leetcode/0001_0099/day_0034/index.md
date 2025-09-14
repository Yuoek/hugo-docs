---
title: "day_0034 "
date: 2025-09-14T10:40:22+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0034 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect_left(nums, target)
        r = bisect_left(nums, target + 1)
        return [-1, -1] if l == r else [l, r - 1] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (l == r) {
            return {-1, -1};
        }
        return {l, r - 1};
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = search(nums, target);
        int r = search(nums, target + 1);
        return l == r ? new int[] {-1, -1} : new int[] {l, r - 1};
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0034  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect_left(nums, target)  # 找到第一个大于等于target的位置
        r = bisect_left(nums, target + 1)  # 找到第一个大于等于target+1的位置
        return [-1, -1] if l == r else [l, r - 1]  # 如果l等于r说明没找到，否则返回[l, r-1]作为区间
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (l == r) {
            return {-1, -1};
        }
        return {l, r - 1};
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = search(nums, target);
        int r = search(nums, target + 1);
        return l == r ? new int[] {-1, -1} : new int[] {l, r - 1};
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0034  数学解释

```python 
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect_left(nums, target)
        r = bisect_left(nums, target + 1)
        return [-1, -1] if l == r else [l, r - 1] 
```


这段代码使用了**二分查找**的数学思想，具体体现在：

## 核心数学思想
1. **有序性利用**：利用数组已排序的特性，通过二分查找快速定位目标值
2. **边界定位**：通过两次二分查找分别确定目标值的起始和结束位置

## 数学原理分析
- `bisect_left(nums, target)`：找到第一个 ≥ target 的位置（起始位置）
- `bisect_left(nums, target + 1)`：找到第一个 ≥ target+1 的位置
  - 这个位置实际上是第一个 > target 的位置
  - 因此 `r - 1` 就是 target 的结束位置

## 数学表达式
设起始位置为 `start`，结束位置为 `end`，则有：
- `start = min{i | nums[i] ≥ target}`
- `end = min{i | nums[i] > target} - 1`

## 边界条件处理
- 如果 `l == r`，说明没有找到 target（起始位置 = 第一个 > target 的位置）
- 否则返回 `[l, r - 1]` 作为目标值的范围

这种方法的时间复杂度为 O(log n)，空间复杂度为 O(1)，是处理有序数组中元素范围查找的高效算法。


