---
title: "day_0026 "
date: 2025-09-14T10:57:55+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0026 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if k == 0 or x != nums[k - 1]:
                nums[k] = x
                k += 1
        return k 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0026  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0  # 初始化指针k，表示当前不重复元素的位置
        for x in nums:  # 遍历数组中的每个元素
            if k == 0 or x != nums[k - 1]:  # 如果是第一个元素或者当前元素不等于前一个不重复元素
                nums[k] = x  # 将当前元素放到k位置
                k += 1  # k指针后移
        return k  # 返回不重复元素的个数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0026  数学解释

```python 
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if k == 0 or x != nums[k - 1]:
                nums[k] = x
                k += 1
        return k 
```


这段代码使用了**双指针/快慢指针**的数学思想来解决有序数组去重问题：

## 数学思想解析：

### 1. **双指针思想**
- **快指针 (x)**：遍历整个数组，寻找新的不重复元素
- **慢指针 (k)**：记录当前不重复序列的末尾位置

### 2. **数学归纳法**
- **基础情况**：当 k=0 时，第一个元素总是唯一的
- **归纳步骤**：对于每个新元素 x，只有当 x ≠ nums[k-1] 时才将其加入结果序列

### 3. **集合论思想**
- 维护一个不断增长的无重复元素集合
- 每次迭代都在验证：当前元素是否属于已构建集合的最后一个元素

### 4. **不变式 (Invariant)**
- 循环不变式：nums[0:k] 始终是一个有序且无重复的子序列
- 这个不变式在每次循环迭代后都保持成立

### 5. **时间复杂度分析**
- 算法的时间复杂度为 O(n)，空间复杂度为 O(1)
- 每个元素最多被比较和移动一次

这个算法巧妙地利用了有序数组的特性，通过一次遍历就完成了去重操作，体现了**高效利用已知信息**和**维护不变式**的重要数学编程思想。


