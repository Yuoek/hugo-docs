---
title: "day_0138 "
date: 2025-09-21T09:47:48+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0138 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        d = {}
        dummy = tail = Node(0)
        cur = head
        while cur:
            node = Node(cur.val)
            tail.next = node
            tail = tail.next
            d[cur] = node
            cur = cur.next
        cur = head
        while cur:
            d[cur].random = d[cur.random] if cur.random else None
            cur = cur.next
        return dummy.next 
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

## LeetCode_0138  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        d = {}  # 创建字典用于存储原节点到复制节点的映射关系
        dummy = tail = Node(0)  # 创建虚拟头节点和尾指针
        cur = head  # 当前指针指向原链表头
        while cur:  # 第一次遍历：复制节点并建立next连接
            node = Node(cur.val)  # 创建新节点，复制原节点的值
            tail.next = node  # 将新节点连接到复制链表的尾部
            tail = tail.next  # 移动尾指针到新节点
            d[cur] = node  # 记录原节点到复制节点的映射
            cur = cur.next  # 移动到原链表的下一个节点
        cur = head  # 重置当前指针到原链表头
        while cur:  # 第二次遍历：处理random指针
            d[cur].random = d[cur.random] if cur.random else None  # 通过映射表设置复制节点的random指针
            cur = cur.next  # 移动到原链表的下一个节点
        return dummy.next  # 返回复制链表的头节点（跳过虚拟头节点）
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

## LeetCode_0138  数学解释

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        d = {}
        dummy = tail = Node(0)
        cur = head
        while cur:
            node = Node(cur.val)
            tail.next = node
            tail = tail.next
            d[cur] = node
            cur = cur.next
        cur = head
        while cur:
            d[cur].random = d[cur.random] if cur.random else None
            cur = cur.next
        return dummy.next 
```


这段代码实现了深拷贝带有随机指针的链表，主要运用了以下数学思想：

## 1. 映射思想 (Mapping)
- 使用字典 `d` 建立原节点到新节点的映射关系
- 这本质上是一个**函数映射**：f: 原节点 → 新节点
- 数学上表示为：∀ 原节点 n ∈ 链表，∃ 新节点 f(n) ∈ 新链表

## 2. 分治思想 (Divide and Conquer)
将复杂问题分解为两个独立的子问题：
1. **创建节点并建立映射**：遍历原链表，创建新节点并记录映射关系
2. **设置随机指针**：利用映射关系，为新节点的random指针赋值

## 3. 函数复合 (Function Composition)
随机指针的设置体现了函数复合的思想：
- 原链表中：random指针指向节点 r
- 新链表中：random指针应指向 f(r)
- 即：新random = f(原random)

## 4. 不变式 (Invariant)
代码维护了重要的不变式：
- 对于每个原节点，字典中都有对应的新节点
- 新链表的next指针连接顺序与原链表一致

## 5. 空值处理 (Null Handling)
- `cur.random else None` 体现了对空指针的数学处理
- 确保映射关系的定义域完整性

这种解法的时间复杂度为 O(n)，空间复杂度为 O(n)，通过空间换时间的方式高效解决了深拷贝问题，体现了计算机科学中常见的权衡思想。

