---
title: "day_0018 "
date: 2025-09-14T11:14:33+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0018 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        ans = []
        if n < 4:
            return ans
        nums.sort()
        for i in range(n - 3):
            if i and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                k, l = j + 1, n - 1
                while k < l:
                    x = nums[i] + nums[j] + nums[k] + nums[l]
                    if x < target:
                        k += 1
                    elif x > target:
                        l -= 1
                    else:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k, l = k + 1, l - 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long x = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        if (n < 4) {
            return ans;
        }
        Arrays.sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long x = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.add(List.of(nums[i], nums[j], nums[k++], nums[l--]));
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0018  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)  # 获取数组长度
        ans = []  # 初始化结果列表
        if n < 4:  # 如果数组长度小于4，直接返回空列表
            return ans
        nums.sort()  # 对数组进行排序，便于后续处理重复元素
        for i in range(n - 3):  # 第一个指针，遍历到倒数第4个元素
            if i and nums[i] == nums[i - 1]:  # 跳过重复的第一个元素
                continue
            for j in range(i + 1, n - 2):  # 第二个指针，从i+1开始遍历到倒数第3个元素
                if j > i + 1 and nums[j] == nums[j - 1]:  # 跳过重复的第二个元素
                    continue
                k, l = j + 1, n - 1  # 初始化第三和第四个指针，使用双指针法
                while k < l:  # 双指针遍历
                    x = nums[i] + nums[j] + nums[k] + nums[l]  # 计算四数之和
                    if x < target:  # 如果和小于目标值，移动左指针增大和
                        k += 1
                    elif x > target:  # 如果和大于目标值，移动右指针减小和
                        l -= 1
                    else:  # 找到符合条件的四元组
                        ans.append([nums[i], nums[j], nums[k], nums[l]])  # 添加到结果列表
                        k, l = k + 1, l - 1  # 同时移动左右指针
                        while k < l and nums[k] == nums[k - 1]:  # 跳过重复的第三个元素
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:  # 跳过重复的第四个元素
                            l -= 1
        return ans  # 返回所有符合条件的四元组
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long x = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        if (n < 4) {
            return ans;
        }
        Arrays.sort(nums);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long x = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (x < target) {
                        ++k;
                    } else if (x > target) {
                        --l;
                    } else {
                        ans.add(List.of(nums[i], nums[j], nums[k++], nums[l--]));
                        while (k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    }
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0018  数学解释

```python 
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        ans = []
        if n < 4:
            return ans
        nums.sort()
        for i in range(n - 3):
            if i and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                k, l = j + 1, n - 1
                while k < l:
                    x = nums[i] + nums[j] + nums[k] + nums[l]
                    if x < target:
                        k += 1
                    elif x > target:
                        l -= 1
                    else:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k, l = k + 1, l - 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
        return ans 
```


这段代码实现了寻找四数之和等于目标值的算法，其数学思想可以解释如下：

## 核心数学思想：双指针法 + 排序预处理

### 1. 排序预处理（数学排序思想）
- 首先对数组进行排序，这是为了：
  - 便于去重（避免重复解）
  - 为双指针法创造条件
- 数学原理：排序后相同的数字会相邻，便于跳过重复元素

### 2. 双重循环 + 双指针（组合数学 + 双指针优化）
- **外层循环**：固定第一个数 `nums[i]`
- **内层循环**：固定第二个数 `nums[j]`
- **双指针**：用 `k` 和 `l` 分别从剩余数组的两端向中间移动

### 3. 数学优化策略
- **去重机制**：跳过重复的数字，避免重复解
  ```python
  if i and nums[i] == nums[i - 1]: continue
  if j > i + 1 and nums[j] == nums[j - 1]: continue
  ```
  
- **双指针移动规则**（基于有序性）：
  - 如果四数之和 < target：`k++`（增大总和）
  - 如果四数之和 > target：`l--`（减小总和）
  - 如果等于 target：记录解并同时移动两个指针

### 4. 时间复杂度分析
- 排序：O(n log n)
- 双重循环 + 双指针：O(n³)
- 总体：O(n³)，比暴力法的 O(n⁴) 更高效

### 5. 数学本质
这实际上是将四数之和问题转化为：在有序数组中寻找两个数，使得它们的和等于 `target - nums[i] - nums[j]`，从而将 O(n⁴) 的问题降为 O(n³)。

这种算法体现了**分治思想**（将四数分解为两数+两数）和**贪心思想**（利用有序性进行指针移动）。

