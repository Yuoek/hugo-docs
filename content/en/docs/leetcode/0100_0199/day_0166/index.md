---
title: "day_0166 "
date: 2025-09-21T08:57:11+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0166 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        ans = []
        neg = (numerator > 0) ^ (denominator > 0)
        if neg:
            ans.append("-")
        a, b = abs(numerator), abs(denominator)
        ans.append(str(a // b))
        a %= b
        if a == 0:
            return "".join(ans)
        ans.append(".")
        d = {}
        while a:
            d[a] = len(ans)
            a *= 10
            ans.append(str(a // b))
            a %= b
            if a in d:
                ans.insert(d[a], "(")
                ans.append(")")
                break
        return "".join(ans) 
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

## LeetCode_0166  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:  # 如果分子为0，直接返回"0"
            return "0"
        ans = []  # 初始化结果列表
        neg = (numerator > 0) ^ (denominator > 0)  # 判断结果是否为负数（异或运算）
        if neg:  # 如果是负数，在结果中添加负号
            ans.append("-")
        a, b = abs(numerator), abs(denominator)  # 取分子和分母的绝对值
        ans.append(str(a // b))  # 添加整数部分
        a %= b  # 计算余数
        if a == 0:  # 如果余数为0，说明能整除，直接返回结果
            return "".join(ans)
        ans.append(".")  # 添加小数点
        d = {}  # 创建字典用于记录余数出现的位置
        while a:  # 当余数不为0时循环
            d[a] = len(ans)  # 记录当前余数对应的位置
            a *= 10  # 余数乘以10
            ans.append(str(a // b))  # 添加商到结果中
            a %= b  # 更新余数
            if a in d:  # 如果余数已经出现过，说明出现循环小数
                ans.insert(d[a], "(")  # 在循环开始位置插入左括号
                ans.append(")")  # 在末尾添加右括号
                break  # 跳出循环
        return "".join(ans)  # 将列表转换为字符串返回
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

## LeetCode_0166  数学解释

```python 
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        ans = []
        neg = (numerator > 0) ^ (denominator > 0)
        if neg:
            ans.append("-")
        a, b = abs(numerator), abs(denominator)
        ans.append(str(a // b))
        a %= b
        if a == 0:
            return "".join(ans)
        ans.append(".")
        d = {}
        while a:
            d[a] = len(ans)
            a *= 10
            ans.append(str(a // b))
            a %= b
            if a in d:
                ans.insert(d[a], "(")
                ans.append(")")
                break
        return "".join(ans) 
```


这段代码实现了将分数转换为小数表示的功能，主要运用了以下数学思想：

## 1. 长除法模拟
代码通过循环模拟了手工长除法的过程：
- 整数部分：`a // b`
- 小数部分：通过不断将余数乘以10再除以分母来获取下一位小数

## 2. 循环小数检测
利用哈希表记录余数的位置，当遇到重复的余数时，说明开始循环：
- `d[a] = len(ans)` 记录当前余数对应的位置
- 当再次遇到相同余数时，在该位置插入"("，在末尾添加")"

## 3. 符号处理
使用异或运算判断结果的正负号：
- `(numerator > 0) ^ (denominator > 0)` 判断两数符号是否相异

## 4. 余数定理的应用
基于数学原理：如果除法过程中出现重复的余数，则小数部分必然循环

## 数学原理示例
以 1/6 为例：
- 整数部分：0
- 小数部分：1÷6=0余1 → 10÷6=1余4 → 40÷6=6余4
- 当余数4再次出现时，说明开始循环：0.1(6)

这种算法的时间复杂度为O(n)，其中n是小数部分的位数，空间复杂度为O(n)用于存储余数位置。


