---
title: "day_0164 "
date: 2025-09-21T09:01:13+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0164 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        mi, mx = min(nums), max(nums)
        bucket_size = max(1, (mx - mi) // (n - 1))
        bucket_count = (mx - mi) // bucket_size + 1
        buckets = [[inf, -inf] for _ in range(bucket_count)]
        for v in nums:
            i = (v - mi) // bucket_size
            buckets[i][0] = min(buckets[i][0], v)
            buckets[i][1] = max(buckets[i][1], v)
        ans = 0
        prev = inf
        for curmin, curmax in buckets:
            if curmin > curmax:
                continue
            ans = max(ans, curmin - prev)
            prev = curmax
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

## LeetCode_0164  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:  # 如果数组长度小于2，直接返回0
            return 0
        mi, mx = min(nums), max(nums)  # 获取数组的最小值和最大值
        bucket_size = max(1, (mx - mi) // (n - 1))  # 计算桶的大小，至少为1
        bucket_count = (mx - mi) // bucket_size + 1  # 计算需要的桶数量
        buckets = [[inf, -inf] for _ in range(bucket_count)]  # 初始化桶，每个桶存储[最小值，最大值]
        
        for v in nums:  # 遍历数组中的每个元素
            i = (v - mi) // bucket_size  # 计算元素应该放入哪个桶
            buckets[i][0] = min(buckets[i][0], v)  # 更新桶的最小值
            buckets[i][1] = max(buckets[i][1], v)  # 更新桶的最大值
        
        ans = 0  # 初始化最大间隔
        prev = inf  # 前一个桶的最大值，初始设为无穷大
        for curmin, curmax in buckets:  # 遍历所有桶
            if curmin > curmax:  # 跳过空桶
                continue
            ans = max(ans, curmin - prev)  # 计算当前桶最小值与前一个桶最大值的差
            prev = curmax  # 更新前一个桶的最大值为当前桶的最大值
        
        return ans  # 返回最大间隔
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

## LeetCode_0164  数学解释

```python 
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        mi, mx = min(nums), max(nums)
        bucket_size = max(1, (mx - mi) // (n - 1))
        bucket_count = (mx - mi) // bucket_size + 1
        buckets = [[inf, -inf] for _ in range(bucket_count)]
        for v in nums:
            i = (v - mi) // bucket_size
            buckets[i][0] = min(buckets[i][0], v)
            buckets[i][1] = max(buckets[i][1], v)
        ans = 0
        prev = inf
        for curmin, curmax in buckets:
            if curmin > curmax:
                continue
            ans = max(ans, curmin - prev)
            prev = curmax
        return ans 
```


这段代码使用了**桶排序**和**鸽巢原理**的数学思想来解决最大间隔问题。

## 核心数学思想：

### 1. 鸽巢原理（Pigeonhole Principle）
- 将n个元素分配到n-1个桶中，至少有一个桶是空的
- 最大间隔一定出现在相邻非空桶之间（跨桶间隔），而不是桶内元素之间

### 2. 桶划分策略
- 桶大小：`bucket_size = max(1, (max-min)//(n-1))`
- 桶数量：`(max-min)//bucket_size + 1`
- 这样确保：
  - 每个桶内元素的最大差值 ≤ bucket_size
  - 最大间隔只可能出现在相邻桶之间

### 3. 算法流程的数学解释：
1. **预处理**：找到最小值和最大值，确定数据范围
2. **分桶**：将数据均匀分布到多个桶中，每个桶只记录最小值和最大值
3. **计算间隔**：遍历所有桶，相邻非空桶之间的最小-最大值差就是候选的最大间隔

## 为什么这样有效？
- 桶内元素的最大间隔 ≤ 桶大小
- 而跨桶间隔（前桶最大值与后桶最小值的差）可能远大于桶大小
- 由于鸽巢原理保证至少有一个空桶，最大间隔必然出现在跨桶间隔中

这种方法的**时间复杂度为O(n)**，相比排序的O(nlogn)更优，是典型的空间换时间策略。


