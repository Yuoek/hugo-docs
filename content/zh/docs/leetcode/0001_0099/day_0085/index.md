---
title: "day_0085 "
date: 2025-09-14T08:17:26+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0085 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        heights = [0] * len(matrix[0])
        ans = 0
        for row in matrix:
            for j, v in enumerate(row):
                if v == "1":
                    heights[j] += 1
                else:
                    heights[j] = 0
            ans = max(ans, self.largestRectangleArea(heights))
        return ans

    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = []
        left = [-1] * n
        right = [n] * n
        for i, h in enumerate(heights):
            while stk and heights[stk[-1]] >= h:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            h = heights[i]
            while stk and heights[stk[-1]] >= h:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        return max(h * (right[i] - left[i] - 1) for i, h in enumerate(heights)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for (auto& row : matrix) {
            for (int j = 0; j < n; ++j) {
                if (row[j] == '1')
                    ++heights[j];
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

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
    public int maximalRectangle(char[][] matrix) {
        int n = matrix[0].length;
        int[] heights = new int[n];
        int ans = 0;
        for (var row : matrix) {
            for (int j = 0; j < n; ++j) {
                if (row[j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            ans = Math.max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    private int largestRectangleArea(int[] heights) {
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

## LeetCode_0085  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # 初始化高度数组，长度为矩阵的列数
        heights = [0] * len(matrix[0])
        ans = 0  # 存储最大矩形面积
        
        # 遍历矩阵的每一行
        for row in matrix:
            # 更新当前行的高度数组
            for j, v in enumerate(row):
                if v == "1":
                    heights[j] += 1  # 如果是'1'，高度加1
                else:
                    heights[j] = 0   # 如果是'0'，高度重置为0
            
            # 计算当前高度数组能形成的最大矩形面积，并更新答案
            ans = max(ans, self.largestRectangleArea(heights))
        
        return ans

    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = []  # 单调栈
        left = [-1] * n   # 存储每个柱子左边第一个比它矮的柱子索引
        right = [n] * n   # 存储每个柱子右边第一个比它矮的柱子索引
        
        # 从左向右遍历，计算left数组
        for i, h in enumerate(heights):
            # 维护单调递增栈
            while stk and heights[stk[-1]] >= h:
                stk.pop()
            if stk:
                left[i] = stk[-1]  # 记录左边第一个比当前矮的柱子
            stk.append(i)
        
        stk = []  # 清空栈
        # 从右向左遍历，计算right数组
        for i in range(n - 1, -1, -1):
            h = heights[i]
            # 维护单调递增栈
            while stk and heights[stk[-1]] >= h:
                stk.pop()
            if stk:
                right[i] = stk[-1]  # 记录右边第一个比当前矮的柱子
            stk.append(i)
        
        # 计算每个柱子能形成的最大矩形面积，取最大值
        return max(h * (right[i] - left[i] - 1) for i, h in enumerate(heights))
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for (auto& row : matrix) {
            for (int j = 0; j < n; ++j) {
                if (row[j] == '1')
                    ++heights[j];
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

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
    public int maximalRectangle(char[][] matrix) {
        int n = matrix[0].length;
        int[] heights = new int[n];
        int ans = 0;
        for (var row : matrix) {
            for (int j = 0; j < n; ++j) {
                if (row[j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            ans = Math.max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    private int largestRectangleArea(int[] heights) {
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

## LeetCode_0085  数学解释

```python 
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        heights = [0] * len(matrix[0])
        ans = 0
        for row in matrix:
            for j, v in enumerate(row):
                if v == "1":
                    heights[j] += 1
                else:
                    heights[j] = 0
            ans = max(ans, self.largestRectangleArea(heights))
        return ans

    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = []
        left = [-1] * n
        right = [n] * n
        for i, h in enumerate(heights):
            while stk and heights[stk[-1]] >= h:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            h = heights[i]
            while stk and heights[stk[-1]] >= h:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        return max(h * (right[i] - left[i] - 1) for i, h in enumerate(heights)) 
```


这段代码使用了**单调栈**的数学思想来解决最大矩形面积问题。让我分两部分解释：

## 第一部分：maximalRectangle方法
- **逐行累积**：将二维矩阵问题转化为一维直方图问题
- **动态高度数组**：对每一行，维护一个heights数组
  - 如果当前单元格为"1"，高度累加（表示连续垂直的'1'）
  - 如果为"0"，高度重置为0（表示柱子在此断开）
- **分治思想**：将二维问题分解为多个一维问题求解

## 第二部分：largestRectangleArea方法（核心算法）
使用**单调递增栈**的数学原理：

### 数学思想：
1. **单调性维护**：栈中保持索引对应的柱高单调递增
2. **边界确定**：对于每个柱子，找到左右第一个比它矮的柱子位置
3. **面积计算**：每个柱子能形成的最大矩形宽度 = (右边界 - 左边界 - 1)

### 具体步骤：
- **左边界扫描**：从左到右，维护递增栈，确定每个柱子左边第一个比它矮的柱子位置
- **右边界扫描**：从右到左，同样维护递增栈，确定右边第一个比它矮的柱子位置
- **最大面积**：对每个柱子，计算 `高度 × (右边界 - 左边界 - 1)`

### 时间复杂度：O(m×n)
通过单调栈，将暴力解的O(n²)优化到O(n)，整体复杂度为矩阵行数×列数

这种解法巧妙地将二维问题降维到一维，再利用单调栈的数学特性高效求解，体现了**降维思想**和**单调性优化**的数学智慧。

