---
title: "day_0001 "
date: 2025-09-14T11:48:27+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0001 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(nums):
            if (y := target - x) in d:
                return [d[y], i]
            d[x] = i 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        for (int i = 0;; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.contains(y)) {
                return {d[y], i};
            }
            d[x] = i;
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0;; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.containsKey(y)) {
                return new int[] {d.get(y), i};
            }
            d.put(x, i);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0001  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}


```python 
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}  # 创建空字典用于存储数字和索引的映射
        for i, x in enumerate(nums):  # 遍历数组，i为索引，x为当前数值
            if (y := target - x) in d:  # 检查目标值与当前值的差是否在字典中
                return [d[y], i]  # 如果存在，返回两个索引
            d[x] = i  # 将当前数值和索引存入字典
```
``

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        for (int i = 0;; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.contains(y)) {
                return {d[y], i};
            }
            d[x] = i;
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0;; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.containsKey(y)) {
                return new int[] {d.get(y), i};
            }
            d.put(x, i);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0001  数学解释

```python 
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(nums):
            if (y := target - x) in d:
                return [d[y], i]
            d[x] = i 
```


这段代码使用了**哈希表（字典）** 的数学思想来解决两数之和问题，核心思想是：

**数学原理**：对于每个元素 x，寻找是否存在另一个元素 y = target - x

**具体实现思想**：
1. **空间换时间**：用字典存储已遍历元素的值和索引，将查找时间从 O(n) 降到 O(1)
2. **一次遍历**：在遍历过程中同时构建哈希表和查找目标值
3. **避免重复计算**：通过哈希表快速判断差值是否存在

**算法步骤**：
- 初始化空字典 d
- 遍历数组，对于每个元素 x：
  - 计算 y = target - x
  - 如果 y 已在字典中，返回 [d[y], i]
  - 否则将当前元素 x 和索引 i 存入字典

**时间复杂度**：O(n) - 只需一次遍历
**空间复杂度**：O(n) - 最坏情况下需要存储所有元素

这种解法体现了**哈希查找**和**补数思想**的巧妙结合。

