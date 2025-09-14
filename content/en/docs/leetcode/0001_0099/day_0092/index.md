---
title: "day_0092 "
date: 2025-09-13T21:21:12+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0092 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        if head.next is None or left == right:
            return head
        dummy = ListNode(0, head)
        pre = dummy
        for _ in range(left - 1):
            pre = pre.next
        p, q = pre, pre.next
        cur = q
        for _ in range(right - left + 1):
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        p.next = pre
        q.next = cur
        return dummy.next 
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *p = pre, *q = pre->next;
        ListNode* cur = q;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        p->next = pre;
        q->next = cur;
        return dummy->next;
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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head.next == null || left == right) {
            return head;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre.next;
        }
        ListNode p = pre;
        ListNode q = pre.next;
        ListNode cur = q;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        p.next = pre;
        q.next = cur;
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0092  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        # 如果链表只有一个节点或者需要反转的范围是同一个位置，则直接返回原链表
        if head.next is None or left == right:
            return head

        # 创建一个哑节点(dummy node)，它的next指向链表的头节点
        dummy = ListNode(0, head)
        pre = dummy  # pre用来定位反转部分的前一个节点

        # 将pre移动到反转区间的前一个节点
        for _ in range(left - 1):
            pre = pre.next

        # p是反转区间的前一个节点，q是反转区间的第一个节点
        p, q = pre, pre.next
        cur = q  # cur用来遍历反转区间的节点

        # 反转[left, right]区间的链表
        for _ in range(right - left + 1):
            t = cur.next  # 保存当前节点的下一个节点
            cur.next = pre  # 将当前节点的next指向前一个节点
            pre, cur = cur, t  # 更新pre和cur为下一个位置

        # 反转完成后，将反转区间的前一个节点连接到反转后的第一个节点
        p.next = pre
        # 将反转区间的最后一个节点连接到反转区间后面的部分
        q.next = cur

        # 返回新的链表头节点（哑节点的next指向的是链表的实际头节点）
        return dummy.next
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *p = pre, *q = pre->next;
        ListNode* cur = q;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        p->next = pre;
        q->next = cur;
        return dummy->next;
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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head.next == null || left == right) {
            return head;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre.next;
        }
        ListNode p = pre;
        ListNode q = pre.next;
        ListNode cur = q;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        p.next = pre;
        q.next = cur;
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0092  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        if head.next is None or left == right:
            return head
        dummy = ListNode(0, head)
        pre = dummy
        for _ in range(left - 1):
            pre = pre.next
        p, q = pre, pre.next
        cur = q
        for _ in range(right - left + 1):
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        p.next = pre
        q.next = cur
        return dummy.next 
```


这段代码的目的是反转单链表中从位置 `left` 到位置 `right` 的节点。通过数学思想，我们可以将这段代码分解为以下几个关键步骤，并用数学的方式进行解释。

---

### 1. **问题描述**
我们有一个单链表，记为：
\\[ L = [a_1, a_2, \dots, a_n] \\]

目标是反转链表中的一个子区间，从第 \( \text{left} \) 个节点到第 \( \text{right} \) 个节点。反转后，链表的顺序变为：
\\[ L = [a_1, \dots, a_{\text{left}-1}, a_{\text{right}}, a_{\text{right}-1}, \dots, a_{\text{left}}, a_{\text{right}+1}, \dots, a_n] \\]

---

### 2. **数学思想：利用指针操作模拟反转**

#### 2.1 初始化一个虚拟头节点
```python
dummy = ListNode(0, head)
pre = dummy
```
这里我们创建了一个虚拟头节点 \( \text{dummy} \)，它的作用是简化边界情况的处理（比如 \( \text{left} = 1 \) 时反转子链表的操作）。从数学上看，相当于在链表头部添加一个虚拟节点 \( a_0 \)，使得链表变为：
\\[ L = [a_0, a_1, a_2, \dots, a_n] \\]

此时，指针 \( \text{pre} \) 初始化指向 \( a_0 \)。

---

#### 2.2 找到反转区间的前一个节点
```python
for _ in range(left - 1):
    pre = pre.next
```
通过 \( \text{left} - 1 \) 次迭代，指针 \( \text{pre} \) 移动到反转区间的前一个节点。数学上，相当于找到 \( a_{\text{left}-1} \)。

此时，链表结构可以表示为：
\\[ L = [a_0, \dots, a_{\text{left}-1}, a_{\text{left}}, \dots, a_{\text{right}}, \dots, a_n] \\]

---

#### 2.3 初始化反转的起点
```python
p, q = pre, pre.next
cur = q
```
此时，指针 \( \text{p} \) 指向 \( a_{\text{left}-1} \)，指针 \( \text{q} \) 和 \( \text{cur} \) 都指向 \( a_{\text{left}} \)。

我们即将从 \( a_{\text{left}} \) 开始进行链表反转。

---

#### 2.4 反转链表的核心逻辑
```python
for _ in range(right - left + 1):
    t = cur.next
    cur.next = pre
    pre, cur = cur, t
```

这段代码是链表反转的核心，通过数学思想可以解释如下：

1. **初始状态**：
   - \( \text{cur} \) 指向当前节点（初始为 \( a_{\text{left}} \)）。
   - \( \text{pre} \) 指向反转后的链表的尾部（初始为 \( a_{\text{left}-1} \)）。
   - \( t \) 是 \( \text{cur.next} \)，即保存当前节点的下一个节点（用于后续遍历）。

2. **每次迭代的操作**：
   - 将当前节点 \( \text{cur} \) 的指针反转，指向 \( \text{pre} \)：
     \\[
     a_{\text{cur}}.next = a_{\text{pre}}
     \\]
   - 更新 \( \text{pre} \) 和 \( \text{cur} \)：
     \\[
     \text{pre} = \text{cur}, \quad \text{cur} = t
     \\]

3. **迭代次数**：
   - 这个过程会执行 \( \text{right} - \text{left} + 1 \) 次，完成子链表的反转。

反转完成后，链表的结构变为：
\\[ L = [a_0, \dots, a_{\text{left}-1}, a_{\text{right}}, a_{\text{right}-1}, \dots, a_{\text{left}}, \dots, a_n] \\]

---

#### 2.5 修复反转后的链表
```python
p.next = pre
q.next = cur
```
此时，链表的结构需要重新连接：
- \( p.next = pre \)：将反转后的子链表的头部连接到反转区间的前一个节点。
- \( q.next = cur \)：将反转后的子链表的尾部连接到反转区间的后一个节点。

最终，链表的完整结构恢复为：
\\[ L = [a_0, \dots, a_{\text{left}-1}, a_{\text{right}}, a_{\text{right}-1}, \dots, a_{\text{left}}, a_{\text{right}+1}, \dots, a_n] \\]

---

#### 2.6 返回结果
```python
return dummy.next
```
返回虚拟头节点的下一个节点，即原链表的头部。

---

### 3. **总结**
从数学的角度看，这段代码的核心思想是通过指针操作，将链表的一个子区间反转，同时保持其余部分的顺序不变。利用迭代的方式，我们将子链表的每个节点的指针方向逐一反转，并在最后重新连接链表的前后部分，完成整体链表的修复。


