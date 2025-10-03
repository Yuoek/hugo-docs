---
title: "day_0171 "
date: 2025-09-21T08:45:35+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0171 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for c in map(ord, columnTitle):
            ans = ans * 26 + c - ord("A") + 1
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

## LeetCode_0171  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0  # 初始化结果变量为0
        for c in map(ord, columnTitle):  # 遍历字符串中的每个字符，转换为ASCII码
            ans = ans * 26 + c - ord("A") + 1  # 将26进制转换为10进制：当前值×26 + 字符对应的数值
        return ans  # 返回最终的10进制数值
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

## LeetCode_0171  数学解释

```python 
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for c in map(ord, columnTitle):
            ans = ans * 26 + c - ord("A") + 1
        return ans 
```


这段代码实现的是将Excel表格的列标题转换为对应的列号，其背后的数学思想是**26进制数的转换**。

具体解释：
1. Excel列标题使用26个字母(A-Z)表示，相当于26进制数系统
2. 每个字符代表一个数字：A=1, B=2, ..., Z=26
3. 转换过程类似于将26进制数转换为10进制数

数学公式表示：
对于列标题字符串 s = c₁c₂...cₙ，对应的列号为：
result = (c₁-64)×26ⁿ⁻¹ + (c₂-64)×26ⁿ⁻² + ... + (cₙ-64)×26⁰

代码执行过程：
- `ord(c)` 获取字符的ASCII码（A=65, B=66, ..., Z=90）
- `c - ord("A") + 1` 将字符转换为对应的数字（A→1, B→2, ..., Z→26）
- `ans * 26` 相当于将之前的结果左移一位（乘以基数26）
- 循环累加完成整个26进制到10进制的转换

例如："AB"的转换：
- 处理'A'：0×26 + (65-65+1) = 1
- 处理'B'：1×26 + (66-65+1) = 26 + 2 = 28

这正是Excel中AB列对应的列号。

