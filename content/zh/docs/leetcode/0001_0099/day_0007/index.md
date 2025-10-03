---
title: "day_0007 "
date: 2025-09-14T11:36:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0007 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        mi, mx = -(2**31), 2**31 - 1
        while x:
            if ans < mi // 10 + 1 or ans > mx // 10:
                return 0
            y = x % 10
            if x < 0 and y > 0:
                y -= 10
            ans = ans * 10 + y
            x = (x - y) // 10
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        for (; x; x /= 10) {
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) {
                return 0;
            }
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int reverse(int x) {
        int ans = 0;
        for (; x != 0; x /= 10) {
            if (ans < Integer.MIN_VALUE / 10 || ans > Integer.MAX_VALUE / 10) {
                return 0;
            }
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0007  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def reverse(self, x: int) -> int:
        ans = 0  # 初始化反转后的结果
        mi, mx = -(2**31), 2**31 - 1  # 定义32位有符号整数的最小值和最大值范围
        while x:  # 当x不为0时循环
            if ans < mi // 10 + 1 or ans > mx // 10:  # 检查反转过程中是否可能溢出
                return 0  # 如果可能溢出，直接返回0
            y = x % 10  # 获取x的最后一位数字
            if x < 0 and y > 0:  # 处理负数的情况
                y -= 10  # 调整负数的最后一位
            ans = ans * 10 + y  # 将数字添加到反转结果中
            x = (x - y) // 10  # 移除已经处理过的最后一位数字
        return ans  # 返回最终的反转结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        for (; x; x /= 10) {
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) {
                return 0;
            }
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int reverse(int x) {
        int ans = 0;
        for (; x != 0; x /= 10) {
            if (ans < Integer.MIN_VALUE / 10 || ans > Integer.MAX_VALUE / 10) {
                return 0;
            }
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0007  数学解释

```python 
class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        mi, mx = -(2**31), 2**31 - 1
        while x:
            if ans < mi // 10 + 1 or ans > mx // 10:
                return 0
            y = x % 10
            if x < 0 and y > 0:
                y -= 10
            ans = ans * 10 + y
            x = (x - y) // 10
        return ans 
```


这段代码实现整数反转的数学思想可以解释如下：

## 核心数学思想：数位分解与重组

### 1. 数位分解原理
代码通过模运算和除法运算逐位分解原始数字：
- `x % 10` 获取当前最低位数字
- `(x - y) // 10` 移除已处理的最低位

### 2. 负数处理技巧
对于负数，代码采用特殊的数学处理：
```python
if x < 0 and y > 0:
    y -= 10
```
这是因为在Python中，负数取模的结果是正数（如：-123 % 10 = 7），需要通过减去10来得到正确的负数值。

### 3. 溢出检测的数学原理
```python
if ans < mi // 10 + 1 or ans > mx // 10:
    return 0
```
这里使用了**预判溢出**的数学思想：
- 在将新数字加入结果前，先检查当前结果乘以10后是否会溢出
- `mi // 10 + 1` 和 `mx // 10` 确定了安全范围边界

### 4. 数学变换过程
整个算法可以看作是一个数学变换：
```
ans = dₙ × 10ⁿ⁻¹ + dₙ₋₁ × 10ⁿ⁻² + ... + d₁ × 10⁰
```
其中dᵢ是原始数字从低位到高位的各个数字。

### 5. 边界条件的数学处理
- 32位整数范围：[-2³¹, 2³¹-1]
- 通过整数除法和模运算避免了浮点数运算的精度问题

这种解法体现了**数论**和**计算机算术**的结合，既考虑了数学上的正确性，又考虑了计算机整数的表示限制。

