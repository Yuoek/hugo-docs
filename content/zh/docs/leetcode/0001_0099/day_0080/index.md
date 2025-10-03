---
title: "day_0080 "
date: 2025-09-14T08:34:18+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0080 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if k < 2 or x != nums[k - 2]:
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
            if (k < 2 || x != nums[k - 2]) {
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
            if (k < 2 || x != nums[k - 2]) {
                nums[k++] = x;
            }
        }
        return k;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0080  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0  # 初始化指针k，表示当前有效数组的长度
        for x in nums:  # 遍历数组中的每个元素
            if k < 2 or x != nums[k - 2]:  # 如果当前元素与k-2位置的元素不同，或者k小于2（前两个元素直接保留）
                nums[k] = x  # 将当前元素放到k位置
                k += 1  # k指针后移
        return k  # 返回去重后的数组长度
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            if (k < 2 || x != nums[k - 2]) {
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
            if (k < 2 || x != nums[k - 2]) {
                nums[k++] = x;
            }
        }
        return k;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0080  数学解释

```python 
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if k < 2 or x != nums[k - 2]:
                nums[k] = x
                k += 1
        return k 
```


这段代码使用了**双指针技巧**和**贪心思想**来解决有序数组中最多保留两个重复元素的问题。

## 数学思想解释：

### 1. 双指针思想 (Two Pointers)
- **慢指针 k**：表示当前有效数组的末尾位置（下一个要插入的位置）
- **快指针 x**：遍历整个数组的迭代器

### 2. 不变式 (Invariant)
维护一个重要的数学性质：**对于任意位置 i < k，nums[0:i] 中每个元素最多出现两次**

### 3. 条件判断的数学逻辑
条件 `if k < 2 or x != nums[k - 2]` 的数学含义：
- `k < 2`：前两个元素可以直接保留（不可能有重复超过两次的情况）
- `x != nums[k - 2]`：核心判断条件，确保当前元素 x 与倒数第二个元素不同
  - 这意味着如果当前元素与 nums[k-2] 相同，那么它已经出现了至少两次
  - 如果不同，说明可以安全添加

### 4. 贪心选择
每次选择当前最优的决策：只有当当前元素不会破坏"最多两个重复"的性质时才将其加入结果数组。

### 5. 时间复杂度分析
- 时间复杂度：O(n) - 单次遍历
- 空间复杂度：O(1) - 原地修改，只使用常数额外空间

这个算法巧妙地利用了有序数组的性质和双指针技巧，通过数学上的不变式保证来高效解决问题。


