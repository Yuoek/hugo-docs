---
title: "day_152 "
date: 2025-09-21T09:22:57+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0152 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = f = g = nums[0]
        for x in nums[1:]:
            ff, gg = f, g
            f = max(x, ff * x, gg * x)
            g = min(x, ff * x, gg * x)
            ans = max(ans, f)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0152  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = f = g = nums[0]  # 初始化最大乘积、当前最大乘积、当前最小乘积
        for x in nums[1:]:  # 遍历数组剩余元素
            ff, gg = f, g  # 保存上一轮的最大最小乘积值
            f = max(x, ff * x, gg * x)  # 计算新的最大乘积（考虑正负号影响）
            g = min(x, ff * x, gg * x)  # 计算新的最小乘积（处理负数相乘变正的情况）
            ans = max(ans, f)  # 更新全局最大乘积
        return ans  # 返回最大乘积结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0152  数学解释

```python 
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = f = g = nums[0]
        for x in nums[1:]:
            ff, gg = f, g
            f = max(x, ff * x, gg * x)
            g = min(x, ff * x, gg * x)
            ans = max(ans, f)
        return ans 
```


这段代码使用了**动态规划**的数学思想来解决最大乘积子数组问题。具体来说：

**核心思想**：
1. **状态定义**：维护两个状态变量
   - `f`：记录以当前元素结尾的**最大乘积**
   - `g`：记录以当前元素结尾的**最小乘积**

2. **状态转移**：
   - 由于乘积的符号会影响结果（负数相乘会变正），需要同时跟踪最大和最小值
   - 当前最大乘积 `f` = max(当前元素, 前一个最大乘积×当前元素, 前一个最小乘积×当前元素)
   - 当前最小乘积 `g` = min(当前元素, 前一个最大乘积×当前元素, 前一个最小乘积×当前元素)

3. **数学原理**：
   - 乘法的不确定性：负数×负数=正数，正数×负数=负数
   - 通过维护最小乘积，可以捕捉到"负负得正"的情况
   - 每一步都考虑三种可能性：重新开始、延续最大乘积、延续最小乘积（可能产生新的最大）

4. **时间复杂度**：O(n)，空间复杂度：O(1)

**举例说明**：
对于数组 `[2, 3, -2, 4]`：
- 初始：f=2, g=2
- x=3：f=max(3, 2×3, 2×3)=6, g=min(3, 6, 6)=3
- x=-2：f=max(-2, 6×(-2), 3×(-2))=-2, g=min(-2, -12, -6)=-12
- x=4：f=max(4, -2×4, -12×4)=4, g=min(4, -8, -48)=-48

最终最大乘积为6（来自子数组[2,3]）

这种解法巧妙地利用了动态规划和数学性质，高效地解决了问题。
