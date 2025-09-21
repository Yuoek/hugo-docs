---
title: "day_0198 "
date: 2025-09-21T07:48:12+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0198 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(nums):
                return 0
            return max(nums[i] + dfs(i + 2), dfs(i + 1))

        return dfs(0) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] < 0) {
                f[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
            }
            return f[i];
        };
        return dfs(0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Integer[] f;
    private int[] nums;

    public int rob(int[] nums) {
        this.nums = nums;
        f = new Integer[nums.length];
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= nums.length) {
            return 0;
        }
        if (f[i] == null) {
            f[i] = Math.max(nums[i] + dfs(i + 2), dfs(i + 1));
        }
        return f[i];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0198  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache  # 使用缓存装饰器来存储已计算的结果，避免重复计算
        def dfs(i: int) -> int:  # 定义深度优先搜索函数，参数为当前房屋索引
            if i >= len(nums):  # 如果索引超出房屋数量范围
                return 0  # 返回0，表示没有房屋可偷
            return max(nums[i] + dfs(i + 2), dfs(i + 1))  # 选择偷当前房屋并跳过下一个，或者不偷当前房屋继续下一个

        return dfs(0)  # 从第一个房屋开始进行深度优先搜索
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] < 0) {
                f[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
            }
            return f[i];
        };
        return dfs(0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Integer[] f;
    private int[] nums;

    public int rob(int[] nums) {
        this.nums = nums;
        f = new Integer[nums.length];
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= nums.length) {
            return 0;
        }
        if (f[i] == null) {
            f[i] = Math.max(nums[i] + dfs(i + 2), dfs(i + 1));
        }
        return f[i];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0198  数学解释

```python 
class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(nums):
                return 0
            return max(nums[i] + dfs(i + 2), dfs(i + 1))

        return dfs(0) 
```


这段代码使用了**动态规划**和**记忆化递归**的数学思想来解决"打家劫舍"问题：

## 核心数学思想

### 1. 最优子结构（动态规划）
问题可以分解为子问题：对于每个房屋i，有两种选择：
- 抢劫当前房屋：收益 = nums[i] + 从i+2开始的收益
- 不抢劫当前房屋：收益 = 从i+1开始的收益

### 2. 状态转移方程
```
dp(i) = max(nums[i] + dp(i+2), dp(i+1))
```
其中dp(i)表示从第i个房屋开始能获得的最大收益

### 3. 记忆化递归
- `@cache`装饰器自动缓存计算结果，避免重复计算
- 当i ≥ n时，返回0（边界条件）

### 4. 数学归纳法
从最后一个房屋开始向前递推，每个子问题的解都基于更小子问题的解

## 时间复杂度
- 由于记忆化，每个状态只计算一次
- 时间复杂度：O(n)
- 空间复杂度：O(n)（递归栈和缓存）

这种解法体现了**分治思想**和**重叠子问题优化**的经典组合。


