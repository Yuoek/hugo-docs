---
title: "day_0084 "
date: 2025-09-14T08:24:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0084 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = []
        left = [-1] * n
        right = [n] * n
        for i, h in enumerate(heights):
            while stk and heights[stk[-1]] >= h:
                right[stk[-1]] = i
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        return max(h * (right[i] - left[i] - 1) for i, h in enumerate(heights)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i)
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        return res;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int largestRectangleArea(int[] heights) {
        int res = 0, n = heights.length;
        Deque<Integer> stk = new ArrayDeque<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && heights[stk.peek()] >= heights[i]) {
                right[stk.pop()] = i;
            }
            left[i] = stk.isEmpty() ? -1 : stk.peek();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            res = Math.max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0084  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)  # 获取数组长度
        stk = []  # 创建单调栈，用于存储索引
        left = [-1] * n  # 初始化左边界数组，默认值为-1
        right = [n] * n  # 初始化右边界数组，默认值为n
        
        # 遍历所有柱子，计算每个柱子的左右边界
        for i, h in enumerate(heights):
            # 维护单调递增栈：弹出栈顶元素直到当前柱子高度大于栈顶柱子高度
            while stk and heights[stk[-1]] >= h:
                right[stk[-1]] = i  # 当前柱子是栈顶柱子的右边界
                stk.pop()
            # 如果栈不为空，当前栈顶元素就是当前柱子的左边界
            if stk:
                left[i] = stk[-1]
            stk.append(i)  # 将当前柱子索引入栈
        
        # 计算最大矩形面积：每个柱子的高度 × (右边界-左边界-1)
        return max(h * (right[i] - left[i] - 1) for i, h in enumerate(heights))
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i)
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        return res;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int largestRectangleArea(int[] heights) {
        int res = 0, n = heights.length;
        Deque<Integer> stk = new ArrayDeque<>();
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && heights[stk.peek()] >= heights[i]) {
                right[stk.pop()] = i;
            }
            left[i] = stk.isEmpty() ? -1 : stk.peek();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            res = Math.max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0084  数学解释

```python 
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = []
        left = [-1] * n
        right = [n] * n
        for i, h in enumerate(heights):
            while stk and heights[stk[-1]] >= h:
                right[stk[-1]] = i
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        return max(h * (right[i] - left[i] - 1) for i, h in enumerate(heights)) 
```


这段代码使用了**单调栈**的数学思想来解决最大矩形面积问题。让我解释其核心数学原理：

## 核心数学思想：单调栈

### 1. 问题建模
寻找直方图中最大矩形面积，本质是对于每个柱子，找到其左右边界：
- 左边界：第一个比当前柱子矮的柱子位置
- 右边界：第一个比当前柱子矮的柱子位置

### 2. 单调性原理
代码维护一个**单调递增栈**，利用栈的单调性来高效确定边界：

- **栈的性质**：栈中元素对应的柱子高度保持单调递增
- **边界确定**：
  - 当遇到比栈顶矮的柱子时，栈顶元素的右边界就是当前柱子
  - 当前柱子的左边界就是栈顶元素（因为栈是单调递增的）

### 3. 数学表达式
对于每个柱子 `i`，其最大矩形面积为：
```
面积 = heights[i] × (right[i] - left[i] - 1)
```
其中：
- `right[i]`：右边第一个比 `heights[i]` 小的位置
- `left[i]`：左边第一个比 `heights[i]` 小的位置

### 4. 算法复杂度
- **时间复杂度**：O(n)，每个元素最多入栈出栈一次
- **空间复杂度**：O(n)，需要存储左右边界信息

### 5. 数学证明
单调栈的正确性基于：
- 栈的单调性保证了可以快速找到边界
- 每个柱子的边界确定是完备且不重复的
- 最终的最大值计算覆盖了所有可能的矩形情况

这种解法将看似复杂的二维面积问题转化为一维的边界查找问题，体现了**空间换时间**和**利用数据结构特性**的数学优化思想。


