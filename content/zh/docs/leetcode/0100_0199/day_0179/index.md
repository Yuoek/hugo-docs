---
title: "day_0179 "
date: 2025-09-21T08:31:21+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0179 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(v) for v in nums]
        nums.sort(key=cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))
        return "0" if nums[0] == "0" else "".join(nums) 
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

## LeetCode_0179  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(v) for v in nums]  # 将数字列表转换为字符串列表
        nums.sort(key=cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))  # 自定义排序：比较字符串拼接后的字典序
        return "0" if nums[0] == "0" else "".join(nums)  # 处理前导0的情况，拼接结果字符串
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

## LeetCode_0179  数学解释

```python 
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(v) for v in nums]
        nums.sort(key=cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))
        return "0" if nums[0] == "0" else "".join(nums) 
```


这段代码使用了**贪心算法**的思想来解决"最大数"问题。让我用数学思想来解释：

## 核心数学思想：字典序比较的扩展

### 1. 问题转换
将数字转换为字符串，这样就能进行**字符串拼接比较**而非数值比较

### 2. 关键比较逻辑
```python
lambda a, b: 1 if a + b < b + a else -1
```
这个比较函数体现了数学上的**拼接最优性原理**：
- 比较两种拼接方式 `a+b` 和 `b+a`
- 选择字典序更大的拼接顺序
- 这确保了局部最优选择能导致全局最优解

### 3. 数学证明思路
假设对于任意三个字符串a, b, c，如果：
- a+b ≥ b+a (a应该排在b前面)
- b+c ≥ c+b (b应该排在c前面)

那么可以证明：a+c ≥ c+a (a应该排在c前面)

这种**传递性**保证了贪心算法的正确性。

### 4. 边界情况处理
```python
return "0" if nums[0] == "0" else "".join(nums)
```
这是数学上的**前导零处理**：如果最大的"数字"是0，说明所有数字都是0，应该返回单个"0"

### 5. 时间复杂度分析
- 排序：O(n log n) 次比较
- 每次比较：O(k) 时间（k为平均数字长度）
- 总体：O(k × n log n)

这种解法巧妙地将数值排序问题转化为字符串字典序排序问题，通过自定义比较函数实现了贪心选择的最优性。

