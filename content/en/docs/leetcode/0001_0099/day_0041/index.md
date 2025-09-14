---
title: "day_0041 "
date: 2025-09-14T10:23:52+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0041 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0041  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        # 第一次遍历：将每个数字放到其应该在的位置上
        for i in range(n):
            # 当当前数字在1到n范围内，且不在正确位置时，进行交换
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                j = nums[i] - 1  # 计算当前数字应该在的位置索引
                nums[i], nums[j] = nums[j], nums[i]  # 交换位置
        # 第二次遍历：检查每个位置上的数字是否正确
        for i in range(n):
            if nums[i] != i + 1:  # 如果位置i上的数字不是i+1
                return i + 1  # 返回缺失的最小正整数
        return n + 1  # 如果所有1到n的数字都存在，则返回n+1
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0041  数学解释

```python 
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1 
```


这段代码使用了**鸽巢原理**和**原地哈希**的数学思想来解决"第一个缺失的正整数"问题。

## 数学思想解析：

### 1. 鸽巢原理
- 在长度为n的数组中，第一个缺失的正整数一定在[1, n+1]范围内
- 如果1到n都出现了，那么缺失的就是n+1
- 否则缺失的就是1到n中没出现的那个最小正整数

### 2. 原地哈希（索引映射）
- 核心思想：让数字i出现在索引i-1的位置上
- 通过交换操作，将每个正整数放到它应该在的位置
- 例如：数字3应该放在索引2的位置（因为3-1=2）

### 3. 算法步骤解释：
1. **位置调整阶段**：遍历数组，对于每个元素：
   - 如果它在[1, n]范围内且不在正确位置上，就交换到正确位置
   - 使用while循环确保交换过来的新元素也被正确处理

2. **查找缺失数阶段**：再次遍历数组
   - 第一个索引i上数字不是i+1的位置，说明i+1缺失
   - 如果所有位置都正确，说明缺失的是n+1

### 4. 时间复杂度：O(n)
虽然看起来有嵌套循环，但每个元素最多被交换一次到正确位置，所以总体是线性时间复杂度。

这种解法巧妙地利用了数组本身作为哈希表，实现了O(1)空间复杂度的解决方案。
