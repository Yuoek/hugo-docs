---
title: "day_0148 "
date: 2025-09-21T09:30:00+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0148 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        l1, l2 = head, slow.next
        slow.next = None
        l1, l2 = self.sortList(l1), self.sortList(l2)
        dummy = ListNode()
        tail = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        tail.next = l1 or l2
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

## LeetCode_0148  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 基本情况：如果链表为空或只有一个节点，直接返回
        if head is None or head.next is None:
            return head
        
        # 使用快慢指针找到链表中点
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # 将链表分成两半
        l1, l2 = head, slow.next
        slow.next = None  # 切断链表连接
        
        # 递归排序两个子链表
        l1, l2 = self.sortList(l1), self.sortList(l2)
        
        # 合并两个已排序的链表
        dummy = ListNode()  # 创建虚拟头节点
        tail = dummy  # 尾指针用于构建新链表
        
        # 比较两个链表的节点值，按顺序合并
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        
        # 将剩余节点连接到新链表末尾
        tail.next = l1 or l2
        
        return dummy.next  # 返回排序后的链表头节点
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

## LeetCode_0148  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        l1, l2 = head, slow.next
        slow.next = None
        l1, l2 = self.sortList(l1), self.sortList(l2)
        dummy = ListNode()
        tail = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        tail.next = l1 or l2
        return dummy.next 
```


这段代码实现了**归并排序**算法，用于对链表进行排序。让我用数学思想来解释：

## 核心数学思想：分治法 (Divide and Conquer)

### 1. 分治策略 (Divide and Conquer)
- **分 (Divide)**: 将链表从中间分成两个子链表
  - 使用快慢指针法找到中点：`slow`每次走1步，`fast`每次走2步
  - 当fast到达末尾时，slow正好在中间位置
  - 数学原理：等差数列，时间复杂度 O(n)

### 2. 递归分解 (Recursive Decomposition)
- 对每个子链表递归调用 `sortList()`
- 数学递推关系：T(n) = 2T(n/2) + O(n)
- 根据主定理，时间复杂度为 O(n log n)

### 3. 合并操作 (Merge Operation)
- 合并两个已排序的子链表
- 使用双指针比较和连接节点
- 数学操作：比较和连接操作的时间复杂度为 O(n)

### 4. 数学归纳法思想
- 基础情况：当链表长度为0或1时，已经有序（递归终止条件）
- 归纳步骤：假设两个子链表已排序，通过合并操作得到完整的有序链表

### 5. 空间复杂度分析
- 递归调用栈深度：O(log n)
- 总空间复杂度：O(log n)

**总结**：这段代码运用了分治法的数学思想，通过递归地将问题分解为更小的子问题，然后合并结果，实现了高效(O(n log n))的链表排序算法。
