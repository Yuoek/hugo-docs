---
title: "day_0147 "
date: 2025-09-21T09:31:59+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0147 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        dummy = ListNode(head.val, head)
        pre, cur = dummy, head
        while cur:
            if pre.val <= cur.val:
                pre, cur = cur, cur.next
                continue
            p = dummy
            while p.next.val <= cur.val:
                p = p.next
            t = cur.next
            cur.next = p.next
            p.next = cur
            pre.next = t
            cur = t
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

## LeetCode_0147  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义单链表节点类
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        # 处理空链表或单节点链表的特殊情况
        if head is None or head.next is None:
            return head
        
        # 创建虚拟头节点，指向原链表头
        dummy = ListNode(head.val, head)
        # pre指向当前节点的前一个节点，cur指向当前处理的节点
        pre, cur = dummy, head
        
        while cur:
            # 如果当前节点值大于等于前一个节点值，说明顺序正确，继续向后移动
            if pre.val <= cur.val:
                pre, cur = cur, cur.next
                continue
            
            # 从头开始寻找插入位置
            p = dummy
            # 找到第一个大于当前节点值的节点的前一个位置
            while p.next.val <= cur.val:
                p = p.next
            
            # 记录当前节点的下一个节点
            t = cur.next
            # 将当前节点插入到正确位置
            cur.next = p.next
            p.next = cur
            # 连接原链表，跳过已排序的当前节点
            pre.next = t
            # 移动cur到下一个待处理节点
            cur = t
        
        # 返回排序后的链表头节点
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

## LeetCode_0147  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        dummy = ListNode(head.val, head)
        pre, cur = dummy, head
        while cur:
            if pre.val <= cur.val:
                pre, cur = cur, cur.next
                continue
            p = dummy
            while p.next.val <= cur.val:
                p = p.next
            t = cur.next
            cur.next = p.next
            p.next = cur
            pre.next = t
            cur = t
        return dummy.next 
```


这段代码实现了链表的插入排序，主要运用了以下数学思想：

## 1. 分治思想
- 将链表分为已排序部分（dummy开始的链表）和未排序部分（cur开始的链表）
- 每次从未排序部分取出一个节点，插入到已排序部分的正确位置

## 2. 指针操作与位置追踪
- 使用多个指针（pre, cur, p）来跟踪不同位置
- `pre`指向当前节点的前一个节点（在已排序部分）
- `cur`指向当前正在处理的节点
- `p`用于在已排序部分寻找插入位置

## 3. 比较与插入的数学逻辑
- 当`pre.val <= cur.val`时，说明当前节点已经在正确位置，直接前进
- 否则，从链表头开始寻找第一个大于当前节点值的位置`p.next.val > cur.val`
- 将当前节点插入到`p`和`p.next`之间

## 4. 边界处理
- 空链表或单节点链表直接返回（基础情况）
- 使用虚拟头节点`dummy`简化插入操作，避免处理头节点变化的特殊情况

## 数学时间复杂度分析
- 最坏情况：O(n²) - 每个节点都需要遍历整个已排序部分
- 最好情况：O(n) - 链表已经有序时
- 平均情况：O(n²)

这种算法体现了典型的插入排序思想：逐步构建有序序列，对于每个新元素，在已排序序列中找到合适位置插入。


