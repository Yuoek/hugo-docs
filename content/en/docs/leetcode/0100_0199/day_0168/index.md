---
title: "day_0168 "
date: 2025-09-21T08:53:48+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0168 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = []
        while columnNumber:
            columnNumber -= 1
            res.append(chr(ord('A') + columnNumber % 26))
            columnNumber //= 26
        return ''.join(res[::-1]) 
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

## LeetCode_0168  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = []  # 初始化结果列表，用于存储转换后的字符
        while columnNumber:  # 当列号不为0时循环
            columnNumber -= 1  # 减1操作，将1-26映射到0-25（对应A-Z）
            res.append(chr(ord('A') + columnNumber % 26))  # 计算当前位的字符并加入结果列表
            columnNumber //= 26  # 整除26，处理更高位
        return ''.join(res[::-1])  # 反转列表并拼接成字符串返回（因为是从低位到高位计算的）
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

## LeetCode_0168  数学解释

```python 
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = []
        while columnNumber:
            columnNumber -= 1
            res.append(chr(ord('A') + columnNumber % 26))
            columnNumber //= 26
        return ''.join(res[::-1]) 
```


这段代码实现的是将Excel列号转换为对应的列标题（如1→"A", 28→"AB"）。让我用数学思想来解释：

## 核心数学思想：**26进制转换（基数为26的进制系统）**

### 1. **进制转换原理**
- 通常的进制转换（如10进制转2进制）使用除基取余法
- 但Excel列号系统是**特殊的26进制**：
  - 没有"0"这个数字，从1开始（A=1, B=2, ..., Z=26）
  - 这导致需要特殊处理

### 2. **关键数学操作解析**

**`columnNumber -= 1`**：
- 这是最重要的数学调整
- 因为Excel列号从1开始，而我们的字符映射需要从0开始
- 数学上：将范围[1,26]映射到[0,25]，便于使用模运算

**`columnNumber % 26`**：
- 获取当前最低位的值（0-25）
- 对应字母'A'到'Z'

**`columnNumber //= 26`**：
- 整数除法，处理更高位
- 相当于在26进制中右移一位

### 3. **数学递推关系**
设f(n)为转换函数，则：
- 当n ≤ 26时：f(n) = chr('A' + n - 1)
- 当n > 26时：f(n) = f((n-1)//26) + chr('A' + (n-1)%26)

### 4. **逆向拼接的原因**
- 因为算法从最低位开始计算
- 但我们需要最高位在前（如"AB"而不是"BA"）
- 数学上：`res[::-1]`相当于将计算出的数字序列反转

### 5. **数学示例验证**
以28为例（应为"AB"）：
```
第一次循环：28-1=27 → 27%26=1 → 'B'，27//26=1
第二次循环：1-1=0 → 0%26=0 → 'A'，0//26=0（结束）
结果：['B','A'] → 反转 → "AB"
```

这种解法巧妙地将1-based的Excel编号系统转换为0-based的计算机处理方式，体现了数学中**坐标变换**和**进制转换**的思想。

