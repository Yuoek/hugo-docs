---
title: "day_0143 "
date: 2025-09-21T09:38:46+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0143 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        cur = slow.next
        slow.next = None

        pre = None
        while cur:
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        cur = head

        while pre:
            t = pre.next
            pre.next = cur.next
            cur.next = pre
            cur, pre = pre.next, t 
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

## LeetCode_0143  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 链表节点定义
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # 使用快慢指针找到链表中点
        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next          # 慢指针每次走一步
            fast = fast.next.next      # 快指针每次走两步

        # 将链表从中点断开，分成前后两部分
        cur = slow.next                # 后半部分的起始节点
        slow.next = None               # 断开前后两部分

        # 反转后半部分链表
        pre = None                     # 反转后的链表头
        while cur:
            t = cur.next               # 保存下一个节点
            cur.next = pre             # 当前节点指向前一个节点
            pre, cur = cur, t          # 移动指针

        # 合并前后两部分链表（交替连接）
        cur = head                     # 前半部分的当前节点
        while pre:
            t = pre.next               # 保存反转部分的下一个节点
            pre.next = cur.next        # 将反转节点插入到前半部分节点之间
            cur.next = pre             # 连接节点
            cur, pre = pre.next, t     # 移动两个指针
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

## LeetCode_0143  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        cur = slow.next
        slow.next = None

        pre = None
        while cur:
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        cur = head

        while pre:
            t = pre.next
            pre.next = cur.next
            cur.next = pre
            cur, pre = pre.next, t 
```


这段代码实现了链表重排序的功能，使用了多种数学思想：

## 1. 快慢指针（龟兔赛跑算法）
```python
fast = slow = head
while fast.next and fast.next.next:
    slow = slow.next
    fast = fast.next.next
```
**数学思想**：等差数列思想
- 快指针每次移动2步，慢指针每次移动1步
- 当快指针到达末尾时，慢指针正好在中间位置
- 时间复杂度：O(n/2) = O(n)

## 2. 链表反转
```python
pre = None
while cur:
    t = cur.next
    cur.next = pre
    pre, cur = cur, t
```
**数学思想**：迭代和指针操作
- 通过迭代方式反转链表后半部分
- 使用三个指针(pre, cur, t)进行原地反转
- 空间复杂度：O(1)

## 3. 链表合并（交错插入）
```python
while pre:
    t = pre.next
    pre.next = cur.next
    cur.next = pre
    cur, pre = pre.next, t
```
**数学思想**：交替排列思想
- 将原链表前半部分和反转后的后半部分交替合并
- 形成 L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ... 的模式

## 整体算法复杂度
- **时间复杂度**：O(n) - 三个循环都是线性时间
- **空间复杂度**：O(1) - 只使用了常数个额外指针

这个算法巧妙地运用了分治思想：先找到中点，然后反转后半部分，最后合并两个子链表，体现了"分而治之"的数学策略。
