---
title: "day_0027 "
date: 2025-09-14T10:56:14+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0027 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for x in nums:
            if x != val:
                nums[k] = x
                k += 1
        return k 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
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
    public int removeElement(int[] nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0027  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0  # 初始化计数器k，记录不等于val的元素个数
        for x in nums:  # 遍历数组中的每个元素
            if x != val:  # 如果当前元素不等于目标值val
                nums[k] = x  # 将该元素放到数组前部位置k处
                k += 1  # 计数器k加1
        return k  # 返回不等于val的元素个数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
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
    public int removeElement(int[] nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0027  数学解释

```python 
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for x in nums:
            if x != val:
                nums[k] = x
                k += 1
        return k 
```


这段代码使用了**双指针思想**中的**快慢指针**技巧来解决原地移除元素的问题。

## 数学思想解释：

**核心思想**：通过两个指针（索引）来遍历数组，一个指针（快指针）用于遍历所有元素，另一个指针（慢指针）用于标记有效元素的位置。

**具体分析**：
- `k`（慢指针）：记录下一个有效元素应该放置的位置，同时统计有效元素的数量
- `x`（快指针）：遍历数组中的每个元素

**数学过程**：
1. 初始化 `k = 0`（从第一个位置开始放置有效元素）
2. 对于数组中的每个元素 `x`：
   - 如果 `x ≠ val`（是有效元素）：
     - 将 `x` 放到 `nums[k]` 的位置
     - `k` 增加 1（为下一个有效元素预留位置）
   - 如果 `x = val`（无效元素）：
     - 跳过，不进行任何操作

**数学意义**：
- 时间复杂度：O(n)，只遍历数组一次
- 空间复杂度：O(1)，只使用了常数级别的额外空间
- 算法保证了前 `k` 个元素都是不等于 `val` 的有效元素

这种思想在数组操作中非常常见，通过一次遍历完成元素的筛选和重新排列，既高效又节省空间。

