---
title: "day_0042 "
date: 2025-09-14T10:22:06+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0042 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [height[0]] * n
        right = [height[-1]] * n
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i])
            right[n - i - 1] = max(right[n - i], height[n - i - 1])
        return sum(min(l, r) - h for l, r, h in zip(left, right, height)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
            right[n - i - 1] = max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.max(left[i - 1], height[i]);
            right[n - i - 1] = Math.max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.min(left[i], right[i]) - height[i];
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0042  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)  # 获取数组长度
        left = [height[0]] * n  # 初始化左边界数组，每个位置存储从左到当前位置的最大高度
        right = [height[-1]] * n  # 初始化右边界数组，每个位置存储从右到当前位置的最大高度
        
        # 从左向右遍历，计算每个位置的左边界最大值
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i])
            
        # 从右向左遍历，计算每个位置的右边界最大值
        for i in range(1, n):
            right[n - i - 1] = max(right[n - i], height[n - i - 1])
            
        # 计算总积水量：每个位置的积水量 = min(左边界, 右边界) - 当前高度
        return sum(min(l, r) - h for l, r, h in zip(left, right, height)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
            right[n - i - 1] = max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.max(left[i - 1], height[i]);
            right[n - i - 1] = Math.max(right[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.min(left[i], right[i]) - height[i];
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0042  数学解释

```python 
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [height[0]] * n
        right = [height[-1]] * n
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i])
            right[n - i - 1] = max(right[n - i], height[n - i - 1])
        return sum(min(l, r) - h for l, r, h in zip(left, right, height)) 
```


这段代码使用了**动态规划**和**空间换时间**的数学思想来解决"接雨水"问题。

## 核心数学思想：

### 1. **分治思想**
将问题分解为：对于每个位置，计算其左侧最高柱子和右侧最高柱子

### 2. **动态规划预处理**
- `left[i]`：表示位置i左侧（包括i）的最高柱子高度
- `right[i]`：表示位置i右侧（包括i）的最高柱子高度

递推关系：
- `left[i] = max(left[i-1], height[i])` （从左向右遍历）
- `right[i] = max(right[i+1], height[i])` （从右向左遍历）

### 3. **木桶原理（短板效应）**
每个位置能接的雨水量由左右两侧最高柱子中的较小值决定：
`min(left[i], right[i]) - height[i]`

### 4. **数学建模**
总雨水量 = Σ [min(左侧最高, 右侧最高) - 当前高度] （对所有位置求和）

## 算法复杂度：
- **时间复杂度**：O(n) - 三次线性遍历
- **空间复杂度**：O(n) - 需要两个辅助数组

这种解法通过预处理左右边界信息，避免了暴力解法中O(n²)的时间复杂度，体现了典型的"空间换时间"优化策略。


