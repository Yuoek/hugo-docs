---
title: "day_0136 "
date: 2025-09-21T09:51:18+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0136 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums) 
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

## LeetCode_0136  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums)  # 使用异或运算找出数组中只出现一次的数字
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

## LeetCode_0136  数学解释

```python 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums) 
```


这段代码使用了**异或运算的数学性质**来解决问题：

## 核心数学思想：异或运算的性质

1. **交换律**：a ⊕ b = b ⊕ a
2. **结合律**：a ⊕ (b ⊕ c) = (a ⊕ b) ⊕ c
3. **恒等律**：a ⊕ 0 = a
4. **自反律**：a ⊕ a = 0

## 算法原理：

- 数组中所有数字进行异或运算
- 成对出现的数字会相互抵消（a ⊕ a = 0）
- 最终剩下的就是只出现一次的数字（0 ⊕ b = b）

## 数学表达式：

设数组为 [a, a, b, c, c, d, d, ...]
则：a ⊕ a ⊕ b ⊕ c ⊕ c ⊕ d ⊕ d ⊕ ... = (a ⊕ a) ⊕ b ⊕ (c ⊕ c) ⊕ (d ⊕ d) ⊕ ... = 0 ⊕ b ⊕ 0 ⊕ 0 ⊕ ... = b

## 时间复杂度：O(n)
## 空间复杂度：O(1)

这种解法巧妙地利用了异或运算的数学特性，在常数空间内高效地找到了唯一不重复的元素。
