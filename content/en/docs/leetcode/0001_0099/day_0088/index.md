---
title: "day_0088 "
date: 2025-09-13T22:19:02+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0088 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        k = m + n - 1
        i, j = m - 1, n - 1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; ~j; --k) {
            nums1[k] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; j >= 0; --k) {
            nums1[k] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0089  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        k = m + n - 1  # 合并后数组的最后一个位置索引
        i, j = m - 1, n - 1  # 分别指向nums1和nums2的最后一个有效元素
        while j >= 0:  # 当nums2中还有元素需要处理时
            if i >= 0 and nums1[i] > nums2[j]:  # 如果nums1当前元素更大
                nums1[k] = nums1[i]  # 将nums1的元素放到合并数组的末尾
                i -= 1  # nums1指针前移
            else:  # 如果nums2当前元素更大或相等
                nums1[k] = nums2[j]  # 将nums2的元素放到合并数组的末尾
                j -= 1  # nums2指针前移
            k -= 1  # 合并数组指针前移
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; ~j; --k) {
            nums1[k] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n - 1; j >= 0; --k) {
            nums1[k] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0089  数学解释

```python 
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        k = m + n - 1
        i, j = m - 1, n - 1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1 
```


这段代码使用了**双指针**和**贪心算法**的数学思想来解决两个有序数组合并的问题：

## 核心数学思想

### 1. 逆向双指针 (Reverse Two Pointers)
- 从数组的**末尾**开始处理，避免正向合并时的元素覆盖问题
- 使用三个指针：`i`指向nums1的有效元素末尾，`j`指向nums2末尾，`k`指向合并后的末尾位置

### 2. 贪心选择策略 (Greedy Selection)
- 在每一步选择当前最大的元素放入目标位置
- 比较 `nums1[i]` 和 `nums2[j]`，选择较大的放入 `nums1[k]`
- 这种局部最优选择保证了全局最优解

### 3. 数学归纳法思想
- 算法基于这样的数学事实：两个有序数组的合并结果也是有序的
- 通过从大到小依次放置元素，确保最终数组的有序性

## 算法复杂度
- **时间复杂度**：O(m+n)，每个元素只被处理一次
- **空间复杂度**：O(1)，原地修改，不需要额外空间

## 数学证明思路
假设在每一步，我们已经正确地将较大的k+1个元素放入了正确位置，那么当前步骤选择剩余元素中的最大值放入第k个位置，就能保证整个数组的有序性。这种逆向处理的方式巧妙地利用了nums1后部的空闲空间。


