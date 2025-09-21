---
title: "day_0150 "
date: 2025-09-21T09:26:12+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0150 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import operator


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        opt = {
            "+": operator.add,
            "-": operator.sub,
            "*": operator.mul,
            "/": operator.truediv,
        }
        s = []
        for token in tokens:
            if token in opt:
                s.append(int(opt[token](s.pop(-2), s.pop(-1))))
            else:
                s.append(int(token))
        return s[0] 
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

## LeetCode_0150  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
import operator  # 导入operator模块，用于获取数学运算符对应的函数


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # 定义运算符映射字典，将字符串运算符映射到对应的数学运算函数
        opt = {
            "+": operator.add,    # 加法运算
            "-": operator.sub,    # 减法运算
            "*": operator.mul,    # 乘法运算
            "/": operator.truediv,  # 除法运算（返回浮点数）
        }
        s = []  # 初始化栈，用于存储操作数
        for token in tokens:  # 遍历逆波兰表达式中的每个token
            if token in opt:  # 如果当前token是运算符
                # 从栈中弹出两个操作数，进行运算，然后将结果压入栈中
                # 注意：先弹出的是第二个操作数，后弹出的是第一个操作数
                s.append(int(opt[token](s.pop(-2), s.pop(-1))))
            else:  # 如果当前token是数字
                s.append(int(token))  # 将字符串转换为整数并压入栈中
        return s[0]  # 栈中最后剩下的元素就是计算结果
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

## LeetCode_0150  数学解释

```python 
import operator


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        opt = {
            "+": operator.add,
            "-": operator.sub,
            "*": operator.mul,
            "/": operator.truediv,
        }
        s = []
        for token in tokens:
            if token in opt:
                s.append(int(opt[token](s.pop(-2), s.pop(-1))))
            else:
                s.append(int(token))
        return s[0] 
```


这段代码使用了**栈数据结构**和**逆波兰表示法（RPN）** 的数学思想：

## 核心数学思想：

1. **逆波兰表示法（后缀表达式）**
   - 运算符位于操作数之后，无需括号即可明确运算顺序
   - 例如：`(2 + 3) × 4` 表示为 `2 3 + 4 ×`

2. **栈的LIFO（后进先出）特性**
   - 遇到操作数时压入栈中
   - 遇到运算符时，弹出栈顶的两个操作数进行运算，将结果压回栈中

## 具体执行过程：
- 遍历token列表：`["2","3","+","4","×"]`
- 遇到"2"：压入栈 → `[2]`
- 遇到"3"：压入栈 → `[2, 3]`
- 遇到"+"：弹出`3`和`2`，计算`2+3=5`，压入结果 → `[5]`
- 遇到"4"：压入栈 → `[5, 4]`
- 遇到"×"：弹出`4`和`5`，计算`5×4=20`，压入结果 → `[20]`
- 返回栈顶元素`20`

这种算法的时间复杂度为O(n)，空间复杂度为O(n)，完美体现了栈在处理表达式求值中的数学应用。

