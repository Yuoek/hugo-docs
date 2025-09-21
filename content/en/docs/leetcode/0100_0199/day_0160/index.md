---
title: "day_0160 "
date: 2025-09-21T09:08:19+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---
{{< katex />}}


## LeetCode_0160 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        a, b = headA, headB
        while a != b:
            a = a.next if a else headB
            b = b.next if b else headA
        return a 
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

## LeetCode_0160  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        a, b = headA, headB  # 初始化两个指针，分别指向两个链表的头节点
        while a != b:  # 当两个指针不相同时继续循环
            a = a.next if a else headB  # 如果a不为空，移动到下一个节点；如果为空，跳转到链表B的头节点
            b = b.next if b else headA  # 如果b不为空，移动到下一个节点；如果为空，跳转到链表A的头节点
        return a  # 返回相交节点（如果相交）或None（如果不相交）
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

## LeetCode_0160  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        a, b = headA, headB
        while a != b:
            a = a.next if a else headB
            b = b.next if b else headA
        return a 
```


这段代码使用了**双指针法**和**数学归纳思想**来寻找两个链表的交点。

## 核心数学思想：路径长度相等化

**关键洞察**：让两个指针分别遍历两个链表，当到达链表末尾时切换到另一个链表的头部，这样两个指针最终会在交点处相遇（或者同时到达None表示无交点）。

## 数学证明：

设：
- 链表A的非公共部分长度为 `a`
- 链表B的非公共部分长度为 `b`  
- 公共部分长度为 `c`

**指针A的路径**：`a + c + b`（A链表 → 公共部分 → B链表）
**指针B的路径**：`b + c + a`（B链表 → 公共部分 → A链表）

由于 `a + c + b = b + c + a`，两个指针的路径长度完全相同，因此：
- 如果有交点：它们会在交点处相遇（走了 `a + c + b` 步后）
- 如果无交点：它们会同时到达None（走了 `a + b` 步后）

## 时间复杂度：O(m+n)
## 空间复杂度：O(1)

这种解法巧妙地利用了路径长度的数学对称性，避免了使用额外空间，是数学思想在算法中的优雅应用。

