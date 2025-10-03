---
title: "day_0128 "
date: 2025-09-21T10:05:49+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0128 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        d = defaultdict(int)
        for x in nums:
            y = x
            while y in s:
                s.remove(y)
                y += 1
            d[x] = d[y] + y - x
            ans = max(ans, d[x])
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

## LeetCode_0128  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)  # 将数组转换为集合，便于快速查找
        ans = 0  # 记录最长连续序列的长度
        d = defaultdict(int)  # 使用字典记录以每个数字为起点的连续序列长度
        
        for x in nums:  # 遍历数组中的每个数字
            y = x  # 从当前数字开始向后查找连续序列
            while y in s:  # 如果y存在于集合中（即存在于原数组中）
                s.remove(y)  # 从集合中移除y，避免重复计算
                y += 1  # 继续检查下一个数字
            # 计算以x为起点的连续序列长度：y-x为连续数字的个数
            d[x] = d[y] + y - x
            ans = max(ans, d[x])  # 更新最长连续序列长度
        
        return ans  # 返回结果
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

## LeetCode_0128  数学解释

```python 
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        d = defaultdict(int)
        for x in nums:
            y = x
            while y in s:
                s.remove(y)
                y += 1
            d[x] = d[y] + y - x
            ans = max(ans, d[x])
        return ans 
```


这段代码使用了**贪心算法**和**哈希集合**的数学思想来解决最长连续序列问题。

## 核心数学思想：

1. **集合去重与快速查找**
   - 使用集合`s`存储所有数字，提供O(1)时间复杂度的查找
   - 自动去除重复元素，避免重复计算

2. **贪心策略**
   - 对于每个数字，尽可能向更大的方向扩展连续序列
   - 一旦找到序列的终点，记录该序列长度

3. **动态规划记忆化**
   - 使用字典`d`存储以每个数字为起点的最长序列长度
   - 避免重复计算相同起点的序列

## 算法流程的数学解释：

对于每个数字`x`：
1. 从`x`开始，不断检查`x+1, x+2, ...`是否在集合中
2. 每找到一个连续数字，就从集合中移除（避免重复处理）
3. 当遇到第一个不在集合中的数字`y`时：
   - `y - x`就是当前连续序列的长度
   - 如果`y`已经被处理过（在字典`d`中），可以直接使用其存储的结果

## 时间复杂度分析：
- 虽然看似嵌套循环，但每个数字最多被访问两次（作为起点和作为中间元素）
- 总体时间复杂度为O(n)，其中n为数组长度

这种解法巧妙地结合了集合操作和贪心扩展，通过移除已处理的元素来保证线性时间复杂度。


