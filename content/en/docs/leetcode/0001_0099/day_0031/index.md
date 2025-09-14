---
title: "day_0031 "
date: 2025-09-14T10:45:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0031 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = next((i for i in range(n - 2, -1, -1) if nums[i] < nums[i + 1]), -1)
        if ~i:
            j = next((j for j in range(n - 1, i, -1) if nums[j] > nums[i]))
            nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1 :] = nums[i + 1 :][::-1] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (~i && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (~i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums, i, j);
                    break;
                }
            }
        }

        for (int j = i + 1, k = n - 1; j < k; ++j, --k) {
            swap(nums, j, k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0031  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        # 从右向左找到第一个降序的位置i（即nums[i] < nums[i+1]）
        i = next((i for i in range(n - 2, -1, -1) if nums[i] < nums[i + 1]), -1)
        
        # 如果找到了这样的位置（i不为-1）
        if ~i:
            # 在i的右侧找到第一个大于nums[i]的数，位置为j
            j = next((j for j in range(n - 1, i, -1) if nums[j] > nums[i]))
            # 交换nums[i]和nums[j]
            nums[i], nums[j] = nums[j], nums[i]
        
        # 将i+1到末尾的部分反转（使其变为升序排列）
        nums[i + 1 :] = nums[i + 1 :][::-1] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (~i && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (~i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i >= 0) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums, i, j);
                    break;
                }
            }
        }

        for (int j = i + 1, k = n - 1; j < k; ++j, --k) {
            swap(nums, j, k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0031  数学解释

```python 
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = next((i for i in range(n - 2, -1, -1) if nums[i] < nums[i + 1]), -1)
        if ~i:
            j = next((j for j in range(n - 1, i, -1) if nums[j] > nums[i]))
            nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1 :] = nums[i + 1 :][::-1] 
```


这段代码实现了"下一个排列"算法，其数学思想可以解释为：

## 核心数学思想：字典序排列的生成

### 1. 排列的字典序性质
- 所有排列按字典序从小到大排列
- 每个排列都有唯一的下一个更大的排列（最大排列的下一个是第一个排列）

### 2. 算法步骤的数学原理：

**步骤1：找到第一个下降点 (i)**
```python
i = next((i for i in range(n - 2, -1, -1) if nums[i] < nums[i + 1]), -1)
```
- 从右向左扫描，找到第一个满足 `nums[i] < nums[i+1]` 的位置
- 数学意义：这是排列中可以增大的最低位（最右边的可增大位）

**步骤2：找到交换位置 (j)**
```python
j = next((j for j in range(n - 1, i, -1) if nums[j] > nums[i]))
```
- 在i的右侧，从右向左找到第一个大于nums[i]的数
- 数学意义：找到比nums[i]大的最小数，确保交换后的增加幅度最小

**步骤3：交换并反转**
```python
nums[i], nums[j] = nums[j], nums[i]
nums[i + 1 :] = nums[i + 1 :][::-1]
```
- 交换i和j位置的数
- 将i+1到末尾的部分反转
- 数学意义：交换后，i位置增大到最小可能值，反转确保i右侧是升序排列（即最小排列）

### 3. 数学证明：
这个算法确保了：
1. 新排列严格大于原排列（因为nums[i]增大）
2. 新排列是所有大于原排列中最小的（因为只增大了最低位，且右侧保持最小排列）
3. 如果已经是最大排列（i=-1），反转整个数组得到最小排列

### 4. 时间复杂度：O(n)
空间复杂度：O(1)

这个算法优雅地利用了排列的字典序性质，通过局部调整实现了全局最优解。
