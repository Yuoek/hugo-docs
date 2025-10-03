---
title: "day_0137 "
date: 2025-09-21T09:49:52+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0137 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            cnt = sum(num >> i & 1 for num in nums)
            if cnt % 3:
                if i == 31:
                    ans -= 1 << i
                else:
                    ans |= 1 << i
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

## LeetCode_0137  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):  # 遍历32位整数中的每一位
            cnt = sum(num >> i & 1 for num in nums)  # 统计所有数字在第i位上的1的个数
            if cnt % 3:  # 如果该位上1的个数不能被3整除，说明只出现一次的数字在这一位是1
                if i == 31:  # 处理最高位（符号位）的情况
                    ans -= 1 << i  # 如果是符号位，使用减法来处理负数
                else:
                    ans |= 1 << i  # 否则，使用位或操作设置该位为1
        return ans  # 返回只出现一次的数字
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

## LeetCode_0137  数学解释

```python 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            cnt = sum(num >> i & 1 for num in nums)
            if cnt % 3:
                if i == 31:
                    ans -= 1 << i
                else:
                    ans |= 1 << i
        return ans 
```


这段代码使用了**位运算**和**状态机**的数学思想来解决"数组中只出现一次的数字"问题（其他数字都出现三次）。

核心数学思想：

1. **二进制位统计思想**：
   - 将每个数字看作32位二进制数
   - 对于每个二进制位，统计所有数字在该位上1的个数
   - 由于其他数字都出现3次，所以每个位上1的个数应该是3的倍数

2. **模3运算的性质**：
   - 如果某位上1的个数是3的倍数，说明只出现一次的数字在该位为0
   - 如果某位上1的个数模3余1，说明只出现一次的数字在该位为1

3. **补码表示的处理**（针对负数）：
   - 第31位是符号位（最高位）
   - 当处理符号位时，需要特殊处理负数的补码表示
   - `ans -= 1 << i` 用于处理负数的补码转换

**数学表达式**：
对于第i位，结果位 = (Σ(所有数字的第i位)) mod 3

**时间复杂度**：O(32n) = O(n)，其中n是数组长度
**空间复杂度**：O(1)，只使用了常数空间

这种方法巧妙地利用了二进制位统计和模运算的性质，避免了使用额外的哈希表空间。


