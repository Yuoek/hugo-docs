---
title: "day_0024 "
date: 2025-09-14T11:02:27+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0024 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        t = self.swapPairs(head.next.next)
        p = head.next
        p.next = head
        head.next = t
        return p 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* t = swapPairs(head->next->next);
        ListNode* p = head->next;
        p->next = head;
        head->next = t;
        return p;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode t = swapPairs(head.next.next);
        ListNode p = head.next;
        p.next = head;
        head.next = t;
        return p;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0024  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义单链表节点类
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 递归终止条件：当前节点为空或只有一个节点，无需交换
        if head is None or head.next is None:
            return head
        
        # 递归处理后续节点（从第三个节点开始）
        t = self.swapPairs(head.next.next)
        
        # 交换当前两个节点
        p = head.next          # 保存第二个节点
        p.next = head          # 第二个节点指向第一个节点
        head.next = t          # 第一个节点指向后续处理完的链表
        
        # 返回新的头节点（原第二个节点）
        return p 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* t = swapPairs(head->next->next);
        ListNode* p = head->next;
        p->next = head;
        head->next = t;
        return p;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode t = swapPairs(head.next.next);
        ListNode p = head.next;
        p.next = head;
        head.next = t;
        return p;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0024  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        t = self.swapPairs(head.next.next)
        p = head.next
        p.next = head
        head.next = t
        return p 
```


这段代码使用**递归思想**实现了链表节点两两交换。让我用数学归纳法的思想来解释：

**递归思想分析：**

1. **基本情况（终止条件）**：
   - 当链表为空或只有一个节点时（`head is None or head.next is None`），直接返回head
   - 这是递归的基准情形，确保递归能够终止

2. **递归步骤**：
   - 假设我们已经能够正确处理剩余部分（`head.next.next`开始的子链表）
   - 这体现了**数学归纳法**的思想：假设对规模更小的问题已经解决

3. **节点交换操作**：
   - `t = self.swapPairs(head.next.next)`：递归处理剩余链表
   - `p = head.next`：保存第二个节点
   - `p.next = head`：让第二个节点指向第一个节点
   - `head.next = t`：让第一个节点指向处理好的剩余链表

4. **递归调用栈**：
   - 每次递归处理一对节点，直到遇到终止条件
   - 然后从后往前逐层返回，完成所有节点对的交换

**数学归纳法视角**：
- 基础：空链表或单节点链表已经有序（正确）
- 归纳：如果对n-2个节点的子链表能正确交换，那么对n个节点也能正确交换
- 结论：算法对所有长度的链表都正确

这种递归方法体现了**分治思想**，将大问题分解为相同结构的小问题，然后组合结果。

