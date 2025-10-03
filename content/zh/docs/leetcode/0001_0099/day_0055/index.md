---
title: "day_0055 "
date: 2025-09-14T09:52:50+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0055 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mx = 0
        for i, x in enumerate(nums):
            if mx < i:
                return False
            mx = max(mx, i + x)
        return True 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx < i) {
                return false;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean canJump(int[] nums) {
        int mx = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (mx < i) {
                return false;
            }
            mx = Math.max(mx, i + nums[i]);
        }
        return true;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0055  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mx = 0  # 记录当前能够到达的最远位置
        for i, x in enumerate(nums):  # 遍历数组中的每个元素及其索引
            if mx < i:  # 如果当前最远位置小于当前索引，说明无法到达当前位置
                return False
            mx = max(mx, i + x)  # 更新能够到达的最远位置
        return True  # 成功遍历完所有元素，说明可以到达最后一个位置
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx < i) {
                return false;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean canJump(int[] nums) {
        int mx = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (mx < i) {
                return false;
            }
            mx = Math.max(mx, i + nums[i]);
        }
        return true;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0055  数学解释

```python 
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mx = 0
        for i, x in enumerate(nums):
            if mx < i:
                return False
            mx = max(mx, i + x)
        return True 
```

这段代码使用了**贪心算法**的思想来解决跳跃游戏问题。

## 数学思想解释：

### 核心思想：**最远可达位置追踪**

1. **问题建模**：将数组视为一系列位置，每个位置的值表示从该位置能跳跃的最大步数

2. **关键观察**：如果当前位置 i 在之前能达到的最远位置范围内，那么当前位置就是可达的

3. **数学表达**：
   - 设 mx 为当前能到达的最远位置（索引）
   - 对于每个位置 i，检查：如果 i > mx，说明无法到达位置 i
   - 否则，更新 mx = max(mx, i + nums[i])

4. **数学归纳**：
   - 基础：位置 0 总是可达的（mx 初始为 0）
   - 归纳：如果位置 i 可达，那么位置 i+nums[i] 也可达
   - 结论：如果最终 mx ≥ 最后一个位置，则整个数组可达

### 算法正确性证明：
- 该算法维护了当前能到达的最远位置
- 通过遍历数组，确保每个位置都在可达范围内
- 时间复杂度：O(n)，空间复杂度：O(1)

这是一种典型的贪心算法应用，通过局部最优选择（维护最大可达位置）来达到全局最优解（判断是否能到达终点）。


