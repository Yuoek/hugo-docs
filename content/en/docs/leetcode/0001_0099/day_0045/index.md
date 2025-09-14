---
title: "day_0045 "
date: 2025-09-14T10:16:25+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0045 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = mx = last = 0
        for i, x in enumerate(nums[:-1]):
            mx = max(mx, i + x)
            if last == i:
                ans += 1
                last = mx
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            mx = max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
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
    public int jump(int[] nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            mx = Math.max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0045  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = mx = last = 0  # 初始化：跳跃次数、当前能到达的最远位置、上一跳的边界
        for i, x in enumerate(nums[:-1]):  # 遍历数组（最后一个元素不需要遍历）
            mx = max(mx, i + x)  # 更新当前能到达的最远位置
            if last == i:  # 如果到达了上一跳的边界
                ans += 1  # 需要再进行一次跳跃
                last = mx  # 更新下一跳的边界为当前能到达的最远位置
        return ans  # 返回最小跳跃次数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            mx = max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
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
    public int jump(int[] nums) {
        int ans = 0, mx = 0, last = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            mx = Math.max(mx, i + nums[i]);
            if (last == i) {
                ++ans;
                last = mx;
            }
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0045  数学解释

```python 
class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = mx = last = 0
        for i, x in enumerate(nums[:-1]):
            mx = max(mx, i + x)
            if last == i:
                ans += 1
                last = mx
        return ans 
```


这段代码使用了**贪心算法**思想来解决跳跃游戏问题（Jump Game II）。具体来说：

**数学思想解释：**

1. **贪心选择性质**：在每一步都选择当前最优的跳跃距离，即维护一个"当前能到达的最远位置"（mx）

2. **最优子结构**：将问题分解为多个子问题，每个阶段的目标是找到从当前位置能到达的最远边界

3. **边界追踪**：
   - `last` 记录当前跳跃能到达的最远边界
   - `mx` 记录遍历过程中能到达的最远位置
   - 当遍历到当前边界 `last` 时，说明需要进行下一次跳跃

4. **数学递推关系**：
   - 对于每个位置 i，更新 mx = max(mx, i + nums[i])
   - 当 i == last 时，必须进行一次跳跃，更新 last = mx

**时间复杂度**：O(n)，只需遍历数组一次
**空间复杂度**：O(1)，只使用了常数个变量

这种方法的数学本质是：通过维护当前能到达的最远边界，确保每次跳跃都是当前情况下的最优选择，从而用最少的跳跃次数到达终点。


