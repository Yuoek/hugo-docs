---
title: "day_0015 "
date: 2025-09-14T11:21:20+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0015 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                x = nums[i] + nums[j] + nums[k]
                if x < 0:
                    j += 1
                elif x > 0:
                    k -= 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    j, k = j + 1, k - 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
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
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.add(List.of(nums[i], nums[j++], nums[k--]));
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0015  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # 首先对数组进行排序，便于后续处理
        n = len(nums)  # 获取数组长度
        ans = []  # 初始化结果列表
        for i in range(n - 2):  # 遍历数组，i作为第一个数的索引
            if nums[i] > 0:  # 如果当前数大于0，由于数组已排序，后面不可能有和为0的三元组
                break
            if i and nums[i] == nums[i - 1]:  # 跳过重复的数字，避免重复解
                continue
            j, k = i + 1, n - 1  # 设置双指针，j从i+1开始，k从末尾开始
            while j < k:  # 双指针遍历
                x = nums[i] + nums[j] + nums[k]  # 计算三数之和
                if x < 0:  # 如果和小于0，需要增大和，j指针右移
                    j += 1
                elif x > 0:  # 如果和大于0，需要减小和，k指针左移
                    k -= 1
                else:  # 找到和为0的三元组
                    ans.append([nums[i], nums[j], nums[k]])  # 添加到结果中
                    j, k = j + 1, k - 1  # 移动双指针继续寻找
                    while j < k and nums[j] == nums[j - 1]:  # 跳过重复的j值
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:  # 跳过重复的k值
                        k -= 1
        return ans  # 返回所有满足条件的三元组
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
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
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < 0) {
                    ++j;
                } else if (x > 0) {
                    --k;
                } else {
                    ans.add(List.of(nums[i], nums[j++], nums[k--]));
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0015  数学解释

```python 
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                x = nums[i] + nums[j] + nums[k]
                if x < 0:
                    j += 1
                elif x > 0:
                    k -= 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    j, k = j + 1, k - 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
        return ans 
```


这段代码使用了**排序+双指针**的数学思想来解决三数之和问题：

## 核心数学思想

1. **排序预处理**：通过排序将无序数组变为有序，这是双指针法的基础
2. **固定一个数，转化为两数之和**：对于每个固定的 nums[i]，问题简化为在剩余数组中找两个数使和为 -nums[i]
3. **双指针夹逼**：利用有序数组的特性，通过调整左右指针来逼近目标值

## 数学原理详解

**时间复杂度分析**：O(n²)
- 排序：O(n log n)
- 外层循环：O(n)
- 内层双指针：O(n)
- 总复杂度：O(n log n) + O(n²) = O(n²)

**空间复杂度**：O(1)（不考虑输出空间）

## 关键数学优化

1. **提前终止**：当 nums[i] > 0 时，由于数组已排序，后面所有数都为正数，不可能和为0
2. **去重处理**：跳过重复元素，避免重复解
   - `if i and nums[i] == nums[i - 1]: continue`
   - 内层循环中的去重逻辑

3. **双指针移动策略**：
   - 和 < 0：左指针右移（增大和）
   - 和 > 0：右指针左移（减小和）
   - 和 = 0：记录结果并同时移动两个指针

这种解法体现了**分治思想**（将三数之和分解为两数之和）和**贪心思想**（利用有序性进行高效搜索）。


