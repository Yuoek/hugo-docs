---
title: "day_0011 "
date: 2025-09-14T11:28:58+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0011 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        while l < r:
            t = min(height[l], height[r]) * (r - l)
            ans = max(ans, t)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int t = min(height[l], height[r]) * (r - l);
            ans = max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
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
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int ans = 0;
        while (l < r) {
            int t = Math.min(height[l], height[r]) * (r - l);
            ans = Math.max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0011  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1  # 初始化左右指针，分别指向数组的首尾
        ans = 0  # 初始化最大面积变量
        while l < r:  # 当左指针小于右指针时循环
            t = min(height[l], height[r]) * (r - l)  # 计算当前左右指针构成的容器面积
            ans = max(ans, t)  # 更新最大面积
            if height[l] < height[r]:  # 如果左指针的高度小于右指针
                l += 1  # 移动左指针向右
            else:  # 否则
                r -= 1  # 移动右指针向左
        return ans  # 返回最大面积
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int t = min(height[l], height[r]) * (r - l);
            ans = max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
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
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int ans = 0;
        while (l < r) {
            int t = Math.min(height[l], height[r]) * (r - l);
            ans = Math.max(ans, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0011  数学解释

```python 
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        while l < r:
            t = min(height[l], height[r]) * (r - l)
            ans = max(ans, t)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans 
```


这段代码使用了**双指针法**和**贪心算法**的数学思想来解决"盛最多水的容器"问题：

## 核心数学思想：

### 1. **双指针法 (Two Pointers)**
- 从数组两端开始（l=0, r=len-1），向中间移动
- 每次计算当前指针位置形成的容器面积

### 2. **贪心选择策略 (Greedy Choice)**
- **关键洞察**：移动较短的那一侧指针
- **数学原理**：容器的面积由两个因素决定：
  - 宽度：(r - l) - 随着指针移动而减小
  - 高度：min(height[l], height[r]) - 由较短的一侧决定

### 3. **最优性证明**
- 如果移动较长的一侧：宽度减小，但高度不会增加（仍受限于较短的一侧）
- 如果移动较短的一侧：宽度减小，但可能找到更高的边界来补偿
- 这种策略确保不会错过最大面积的解

### 4. **时间复杂度优化**
- 暴力解法：O(n²)
- 双指针法：O(n) - 每个元素最多被访问一次

这种解法巧妙地利用了问题的几何特性和贪心选择性质，在保证正确性的同时极大地提高了效率。

