---
title: "day_0155 "
date: 2025-09-21T09:17:48+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0155 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class MinStack:
    def __init__(self):
        self.stk1 = []
        self.stk2 = [inf]

    def push(self, val: int) -> None:
        self.stk1.append(val)
        self.stk2.append(min(val, self.stk2[-1]))

    def pop(self) -> None:
        self.stk1.pop()
        self.stk2.pop()

    def top(self) -> int:
        return self.stk1[-1]

    def getMin(self) -> int:
        return self.stk2[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin() 
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

## LeetCode_0155  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class MinStack:
    def __init__(self):
        self.stk1 = []  # 主栈：存储所有压入的元素
        self.stk2 = [inf]  # 辅助栈：存储当前最小值，初始化为无穷大

    def push(self, val: int) -> None:
        self.stk1.append(val)  # 将元素压入主栈
        self.stk2.append(min(val, self.stk2[-1]))  # 将当前最小值压入辅助栈

    def pop(self) -> None:
        self.stk1.pop()  # 弹出主栈顶部元素
        self.stk2.pop()  # 弹出辅助栈顶部元素（对应的最小值）

    def top(self) -> int:
        return self.stk1[-1]  # 返回主栈顶部元素

    def getMin(self) -> int:
        return self.stk2[-1]  # 返回辅助栈顶部元素（当前最小值）


# 使用示例：
# obj = MinStack()  # 创建最小栈对象
# obj.push(val)     # 压入元素
# obj.pop()         # 弹出顶部元素
# param_3 = obj.top()  # 获取顶部元素
# param_4 = obj.getMin()  # 获取当前最小值
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

## LeetCode_0155  数学解释

```python 
class MinStack:
    def __init__(self):
        self.stk1 = []
        self.stk2 = [inf]

    def push(self, val: int) -> None:
        self.stk1.append(val)
        self.stk2.append(min(val, self.stk2[-1]))

    def pop(self) -> None:
        self.stk1.pop()
        self.stk2.pop()

    def top(self) -> int:
        return self.stk1[-1]

    def getMin(self) -> int:
        return self.stk2[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin() 
```


这个代码实现了一个最小栈（MinStack），其数学思想可以解释为：

## 核心思想：空间换时间 + 同步维护

### 1. 双栈结构设计
- **stk1**：存储所有压入栈的元素（常规栈）
- **stk2**：存储对应时刻的最小值（辅助栈）

### 2. 数学原理：递推关系
对于每个操作时刻，stk2的栈顶元素始终等于stk1中所有元素的**最小值**，即：
```
min(stk1[0], stk1[1], ..., stk1[n-1]) = stk2[-1]
```

### 3. 操作的时间复杂度分析
- **push操作**：O(1) - 通过比较当前值与历史最小值，立即确定新的最小值
- **pop操作**：O(1) - 同时弹出两个栈的栈顶元素
- **getMin操作**：O(1) - 直接返回stk2的栈顶元素

### 4. 数学归纳法证明正确性
**基础情况**：初始时，stk2 = [∞]，空栈的最小值定义为∞

**归纳步骤**：假设在push第k个元素前，stk2[-1]是当前栈的最小值
- push(val)后：min(val, stk2[-1])就是新的最小值
- pop()后：stk2弹出栈顶，新的栈顶就是剩余元素的最小值

### 5. 空间复杂度
需要额外的O(n)空间来存储最小值信息，这是典型的"空间换时间"策略。

这种设计确保了在常数时间内获取栈的最小值，适用于需要频繁查询最小值的场景。
