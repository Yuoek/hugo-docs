---
title: "day_0016 "
date: 2025-09-14T11:19:20+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0016 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = inf
        for i, v in enumerate(nums):
            j, k = i + 1, n - 1
            while j < k:
                t = v + nums[j] + nums[k]
                if t == target:
                    return t
                if abs(t - target) < abs(ans - target):
                    ans = t
                if t > target:
                    k -= 1
                else:
                    j += 1
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) return t;
                if (abs(t - target) < abs(ans - target)) ans = t;
                if (t > target)
                    --k;
                else
                    ++j;
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
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = 1 << 30;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) {
                    return t;
                }
                if (Math.abs(t - target) < Math.abs(ans - target)) {
                    ans = t;
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0016  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()  # 首先对数组进行排序，便于使用双指针
        n = len(nums)  # 获取数组长度
        ans = inf  # 初始化答案为无穷大，用于记录最接近的和
        
        for i, v in enumerate(nums):  # 遍历数组，固定第一个数
            j, k = i + 1, n - 1  # 设置左右指针，j从i+1开始，k从末尾开始
            
            while j < k:  # 当左右指针未相遇时循环
                t = v + nums[j] + nums[k]  # 计算当前三个数的和
                
                if t == target:  # 如果和正好等于目标值
                    return t  # 直接返回，因为这是最接近的
                
                if abs(t - target) < abs(ans - target):  # 如果当前和更接近目标值
                    ans = t  # 更新答案为当前和
                
                if t > target:  # 如果当前和大于目标值
                    k -= 1  # 右指针左移，减小总和
                else:  # 如果当前和小于目标值
                    j += 1  # 左指针右移，增大总和
        
        return ans  # 返回最接近目标值的和
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) return t;
                if (abs(t - target) < abs(ans - target)) ans = t;
                if (t > target)
                    --k;
                else
                    ++j;
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
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = 1 << 30;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t == target) {
                    return t;
                }
                if (Math.abs(t - target) < Math.abs(ans - target)) {
                    ans = t;
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0016  数学解释

```python 
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = inf
        for i, v in enumerate(nums):
            j, k = i + 1, n - 1
            while j < k:
                t = v + nums[j] + nums[k]
                if t == target:
                    return t
                if abs(t - target) < abs(ans - target):
                    ans = t
                if t > target:
                    k -= 1
                else:
                    j += 1
        return ans 
```


这段代码使用了**排序**和**双指针**的数学思想来解决最接近的三数之和问题。

## 核心数学思想：

1. **排序优化搜索空间**
   - 通过排序将无序数组变为有序，使得我们可以利用有序性进行高效搜索
   - 排序后，对于固定的第一个数，剩余两个数的搜索可以转化为有序数组的两数之和问题

2. **双指针技术**
   - 对于每个固定的第一个数 `v = nums[i]`，使用两个指针 `j` 和 `k`：
     - `j` 从 `i+1` 开始（左指针）
     - `k` 从数组末尾开始（右指针）
   - 根据当前三数之和 `t` 与目标值 `target` 的关系调整指针：
     - 如果 `t > target`：减小总和，`k--`（右指针左移）
     - 如果 `t < target`：增大总和，`j++`（左指针右移）

3. **贪心逼近**
   - 维护一个当前最接近的和 `ans`
   - 每次计算新的三数之和后，比较其与目标的距离，更新最优解
   - 遇到完全匹配的情况立即返回，实现提前终止

## 数学复杂度分析：
- 时间复杂度：O(n²) = O(n log n)（排序）+ O(n²)（双指针遍历）
- 空间复杂度：O(1)（除了排序使用的栈空间）

这种解法巧妙地利用了排序后的有序性和双指针的单调性，避免了暴力解法的 O(n³) 复杂度，是典型的**空间换时间**优化策略。

