---
title: "day_0053 "
date: 2025-09-14T09:56:28+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0053 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = f = nums[0]
        for x in nums[1:]:
            f = max(f, 0) + x
            ans = max(ans, f)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], f = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            f = max(f, 0) + nums[i];
            ans = max(ans, f);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        for (int i = 1, f = nums[0]; i < nums.length; ++i) {
            f = Math.max(f, 0) + nums[i];
            ans = Math.max(ans, f);
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0053  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = f = nums[0]  # 初始化：ans存储最大和，f存储当前连续子数组和
        for x in nums[1:]:  # 遍历数组从第二个元素开始
            f = max(f, 0) + x  # 如果当前和小于0就重置为0，再加上当前元素
            ans = max(ans, f)  # 更新最大和
        return ans  # 返回最大子数组和
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], f = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            f = max(f, 0) + nums[i];
            ans = max(ans, f);
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        for (int i = 1, f = nums[0]; i < nums.length; ++i) {
            f = Math.max(f, 0) + nums[i];
            ans = Math.max(ans, f);
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0053  数学解释

```python 
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = f = nums[0]
        for x in nums[1:]:
            f = max(f, 0) + x
            ans = max(ans, f)
        return ans 
```


这段代码使用了**动态规划**的数学思想来解决最大子数组和问题（Kadane算法）。具体分析如下：

## 核心思想
**最优子结构**：整个数组的最大子数组和可以分解为以每个位置结尾的最大子数组和中的最大值。

## 数学表达
定义状态：
- `f(i)`：表示以第`i`个元素结尾的最大子数组和

状态转移方程：
```
f(i) = max(f(i-1), 0) + nums[i]
```

## 代码解释
1. **初始化**：`ans = f = nums[0]`
   - `f` 表示以当前元素结尾的最大子数组和
   - `ans` 记录全局最大值

2. **遍历过程**：
   - `f = max(f, 0) + x`：如果前一个位置的最大和为负数，就重新开始（因为负数会减小总和）
   - `ans = max(ans, f)`：更新全局最大值

3. **数学原理**：
   - 当`f(i-1) < 0`时，`f(i) = nums[i]`（重新开始）
   - 当`f(i-1) ≥ 0`时，`f(i) = f(i-1) + nums[i]`（继续累加）

## 时间复杂度
- **O(n)**：只需遍历数组一次
- **空间复杂度 O(1)**：只使用了常数个变量

这种解法巧妙地利用了"负数和会减小总和"的数学直觉，通过动态规划实现了最优解。


