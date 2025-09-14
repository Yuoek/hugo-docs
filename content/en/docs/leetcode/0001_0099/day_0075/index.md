---
title: "day_0075 "
date: 2025-09-14T08:48:02+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0075 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        i, j, k = -1, len(nums), 0
        while k < j:
            if nums[k] == 0:
                i += 1
                nums[i], nums[k] = nums[k], nums[i]
                k += 1
            elif nums[k] == 2:
                j -= 1
                nums[j], nums[k] = nums[k], nums[j]
            else:
                k += 1 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = nums.size(), k = 0;
        while (k < j) {
            if (nums[k] == 0) {
                swap(nums[++i], nums[k++]);
            } else if (nums[k] == 2) {
                swap(nums[--j], nums[k]);
            } else {
                ++k;
            }
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void sortColors(int[] nums) {
        int i = -1, j = nums.length, k = 0;
        while (k < j) {
            if (nums[k] == 0) {
                swap(nums, ++i, k++);
            } else if (nums[k] == 2) {
                swap(nums, --j, k);
            } else {
                ++k;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0075  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        i, j, k = -1, len(nums), 0  # 初始化三个指针：i指向0的末尾，j指向2的开头，k为当前遍历指针
        while k < j:  # 当当前指针k未到达2的开头位置时循环
            if nums[k] == 0:  # 如果当前元素是0
                i += 1  # 将0的边界向右扩展一位
                nums[i], nums[k] = nums[k], nums[i]  # 交换当前0元素到0区域末尾
                k += 1  # 移动当前指针
            elif nums[k] == 2:  # 如果当前元素是2
                j -= 1  # 将2的边界向左扩展一位
                nums[j], nums[k] = nums[k], nums[j]  # 交换当前2元素到2区域开头
                # 注意：这里不移动k，因为交换过来的元素需要重新检查
            else:  # 如果当前元素是1
                k += 1  # 直接跳过，1应该在中间区域
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = nums.size(), k = 0;
        while (k < j) {
            if (nums[k] == 0) {
                swap(nums[++i], nums[k++]);
            } else if (nums[k] == 2) {
                swap(nums[--j], nums[k]);
            } else {
                ++k;
            }
        }
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void sortColors(int[] nums) {
        int i = -1, j = nums.length, k = 0;
        while (k < j) {
            if (nums[k] == 0) {
                swap(nums, ++i, k++);
            } else if (nums[k] == 2) {
                swap(nums, --j, k);
            } else {
                ++k;
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0075  数学解释

```python 
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        i, j, k = -1, len(nums), 0
        while k < j:
            if nums[k] == 0:
                i += 1
                nums[i], nums[k] = nums[k], nums[i]
                k += 1
            elif nums[k] == 2:
                j -= 1
                nums[j], nums[k] = nums[k], nums[j]
            else:
                k += 1 
```


这段代码使用了**荷兰国旗问题（Dutch National Flag Problem）**的经典三指针解法，体现了**分治思想**和**双指针技巧**的数学思想。

## 数学思想解析：

### 1. 分区思想（Partitioning）
将数组划分为三个区域：
- [0, i]：存放0（红色区域）
- [i+1, j-1]：存放1（白色区域，待处理区域）
- [j, n-1]：存放2（蓝色区域）

### 2. 三指针策略
- **i指针**：指向最后一个0的位置（红色区域的右边界）
- **j指针**：指向第一个2的位置（蓝色区域的左边界）
- **k指针**：当前遍历指针（扫描待处理区域）

### 3. 状态转移逻辑
```python
当 nums[k] == 0 时：
   将当前0交换到红色区域，i和k都右移

当 nums[k] == 2 时：
   将当前2交换到蓝色区域，j左移（k不移动，因为交换过来的元素需要重新检查）

当 nums[k] == 1 时：
   直接跳过，k右移（1属于中间区域）
```

### 4. 数学不变式（Invariant）
在整个循环过程中，始终保持：
- nums[0:i+1] 都是0
- nums[i+1:k] 都是1（或正在处理）
- nums[j:n] 都是2
- nums[k:j] 是待处理区域

### 5. 算法复杂度
- **时间复杂度**：O(n)，每个元素最多被访问两次
- **空间复杂度**：O(1)，原地排序，只使用常数空间

这种解法巧妙地利用了三个指针来维护三个不同的区域，通过一次遍历完成排序，体现了**高效的空间利用**和**最优的时间复杂度**。


