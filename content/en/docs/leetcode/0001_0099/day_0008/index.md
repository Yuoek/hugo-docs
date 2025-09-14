---
title: "day_0008 "
date: 2025-09-14T11:34:20+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0008 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        if n == 0:
            return 0
        i = 0
        while s[i] == ' ':
            i += 1
            # 仅包含空格
            if i == n:
                return 0
        sign = -1 if s[i] == '-' else 1
        if s[i] in ['-', '+']:
            i += 1
        res, flag = 0, (2**31 - 1) // 10
        while i < n:
            # 非数字，跳出循环体
            if not s[i].isdigit():
                break
            c = int(s[i])
            # 溢出判断
            if res > flag or (res == flag and c > 7):
                return 2**31 - 1 if sign > 0 else -(2**31)
            res = res * 10 + c
            i += 1
        return sign * res 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 

```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int myAtoi(String s) {
        if (s == null) return 0;
        int n = s.length();
        if (n == 0) return 0;
        int i = 0;
        while (s.charAt(i) == ' ') {
            // 仅包含空格
            if (++i == n) return 0;
        }
        int sign = 1;
        if (s.charAt(i) == '-') sign = -1;
        if (s.charAt(i) == '-' || s.charAt(i) == '+') ++i;
        int res = 0, flag = Integer.MAX_VALUE / 10;
        for (; i < n; ++i) {
            // 非数字，跳出循环体
            if (s.charAt(i) < '0' || s.charAt(i) > '9') break;
            // 溢出判断
            if (res > flag || (res == flag && s.charAt(i) > '7'))
                return sign > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            res = res * 10 + (s.charAt(i) - '0');
        }
        return sign * res;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0008  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        if n == 0:
            return 0
        i = 0
        while s[i] == ' ':  # 跳过前导空格
            i += 1
            # 仅包含空格
            if i == n:
                return 0
        sign = -1 if s[i] == '-' else 1  # 判断正负号
        if s[i] in ['-', '+']:  # 如果当前字符是符号位，指针后移
            i += 1
        res, flag = 0, (2**31 - 1) // 10  # res存储结果，flag用于溢出判断
        while i < n:
            # 非数字，跳出循环体
            if not s[i].isdigit():  # 遇到非数字字符，停止转换
                break
            c = int(s[i])  # 将字符转换为数字
            # 溢出判断
            if res > flag or (res == flag and c > 7):  # 检查是否超出32位有符号整数范围
                return 2**31 - 1 if sign > 0 else -(2**31)  # 返回最大或最小值
            res = res * 10 + c  # 构建数字
            i += 1  # 指针后移
        return sign * res  # 返回带符号的结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 

```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int myAtoi(String s) {
        if (s == null) return 0;
        int n = s.length();
        if (n == 0) return 0;
        int i = 0;
        while (s.charAt(i) == ' ') {
            // 仅包含空格
            if (++i == n) return 0;
        }
        int sign = 1;
        if (s.charAt(i) == '-') sign = -1;
        if (s.charAt(i) == '-' || s.charAt(i) == '+') ++i;
        int res = 0, flag = Integer.MAX_VALUE / 10;
        for (; i < n; ++i) {
            // 非数字，跳出循环体
            if (s.charAt(i) < '0' || s.charAt(i) > '9') break;
            // 溢出判断
            if (res > flag || (res == flag && s.charAt(i) > '7'))
                return sign > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            res = res * 10 + (s.charAt(i) - '0');
        }
        return sign * res;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0008  数学解释

```python 
class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        if n == 0:
            return 0
        i = 0
        while s[i] == ' ':
            i += 1
            # 仅包含空格
            if i == n:
                return 0
        sign = -1 if s[i] == '-' else 1
        if s[i] in ['-', '+']:
            i += 1
        res, flag = 0, (2**31 - 1) // 10
        while i < n:
            # 非数字，跳出循环体
            if not s[i].isdigit():
                break
            c = int(s[i])
            # 溢出判断
            if res > flag or (res == flag and c > 7):
                return 2**31 - 1 if sign > 0 else -(2**31)
            res = res * 10 + c
            i += 1
        return sign * res 
```


这段代码实现的是字符串转整数（atoi）的功能，让我用数学思想来解释其核心逻辑：

## 1. 有限状态机思想（数学建模）
代码通过索引i遍历字符串，模拟了有限状态机的状态转换：
- 初始状态：跳过前导空格
- 符号判断：确定正负号
- 数字转换：逐个字符转换为数字

## 2. 数制转换的数学原理
核心转换公式：`res = res × 10 + c`
这体现了十进制数的数学定义：
```
数字 = dₙ × 10ⁿ + dₙ₋₁ × 10ⁿ⁻¹ + ... + d₁ × 10¹ + d₀ × 10⁰
```
代码通过迭代计算实现了这个多项式求和过程。

## 3. 溢出处理的数学边界
```python
flag = (2**31 - 1) // 10  # 214748364
```
这个边界值的设计基于数学分析：
- 32位有符号整数的范围：[-2³¹, 2³¹-1] = [-2147483648, 2147483647]
- 当res > 214748364时，再乘以10就会超过最大值
- 当res == 214748364时，个位数不能超过7（2147483647的个位是7）

## 4. 符号处理的数学表示
```python
sign = -1 if s[i] == '-' else 1
return sign * res
```
这体现了数学中的符号运算：最终结果 = 绝对值 × 符号系数

## 5. 算法复杂度分析
从数学角度看，算法的时间复杂度为O(n)，空间复杂度为O(1)，其中n为字符串长度，这是最优的数学复杂度。

这种实现方式将字符串转换的数学本质（多项式求和）与计算机的数值表示限制（整数溢出）完美结合，体现了数学思想在算法设计中的重要应用。


