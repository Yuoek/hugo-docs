---
title: "day_0061 "
date: 2025-09-14T09:29:02+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0061 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        cur, n = head, 0
        while cur:
            n += 1
            cur = cur.next
        k %= n
        if k == 0:
            return head
        fast = slow = head
        for _ in range(k):
            fast = fast.next
        while fast.next:
            fast, slow = fast.next, slow.next

        ans = slow.next
        slow.next = None
        fast.next = head
        return ans 
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return ans;
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cur = head;
        int n = 0;
        for (; cur != null; cur = cur.next) {
            n++;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (k-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode ans = slow.next;
        slow.next = null;
        fast.next = head;
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0061  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None:  # 如果链表为空或只有一个节点，直接返回
            return head
        cur, n = head, 0  # 初始化当前节点和链表长度计数器
        while cur:  # 遍历链表计算总长度
            n += 1
            cur = cur.next
        k %= n  # 对k取模，避免重复旋转
        if k == 0:  # 如果k为0，不需要旋转
            return head
        fast = slow = head  # 初始化快慢指针
        for _ in range(k):  # 快指针先走k步
            fast = fast.next
        while fast.next:  # 同时移动快慢指针，直到快指针到达末尾
            fast, slow = fast.next, slow.next

        ans = slow.next  # 新的头节点是慢指针的下一个节点
        slow.next = None  # 断开链表
        fast.next = head  # 将原链表尾部连接到原头部
        return ans  # 返回新的头节点
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return ans;
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cur = head;
        int n = 0;
        for (; cur != null; cur = cur.next) {
            n++;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (k-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode ans = slow.next;
        slow.next = null;
        fast.next = head;
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0061  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        cur, n = head, 0
        while cur:
            n += 1
            cur = cur.next
        k %= n
        if k == 0:
            return head
        fast = slow = head
        for _ in range(k):
            fast = fast.next
        while fast.next:
            fast, slow = fast.next, slow.next

        ans = slow.next
        slow.next = None
        fast.next = head
        return ans 
```


这段代码实现了链表的右旋转操作，让我用数学思想来解释其原理：

## 核心数学思想：模运算与双指针

### 1. 模运算思想 (Modular Arithmetic)
```python
k %= n
```
- **数学原理**：旋转k次等价于旋转k mod n次，因为旋转n次后链表恢复原状
- **循环群概念**：链表旋转操作形成一个循环群，群的大小为n（链表长度）
- **周期性**：旋转操作具有周期性，周期为n

### 2. 双指针技术 (Two Pointers)
```python
fast = slow = head
for _ in range(k):
    fast = fast.next
while fast.next:
    fast, slow = fast.next, slow.next
```
- **相对位置关系**：fast指针比slow指针超前k个位置
- **同步移动**：当fast到达链表末尾时，slow正好指向新链表的尾节点
- **数学关系**：slow的位置 = n - k - 1（从0开始计数）

### 3. 链表重组 (Linked List Reorganization)
```python
ans = slow.next
slow.next = None
fast.next = head
```
- **断开与连接**：在slow处断开链表，将后半部分连接到原链表头部
- **数学变换**：相当于将链表的后k个节点移动到前面

### 4. 时间复杂度分析
- **遍历链表**：O(n) - 计算链表长度
- **双指针移动**：O(n) - 最多遍历整个链表
- **总体复杂度**：O(n)

### 5. 空间复杂度分析
- **常数空间**：O(1) - 只使用了几个指针变量

这种解法巧妙地运用了模运算来减少不必要的旋转次数，并通过双指针技术高效地找到旋转点，体现了数学优化思想在算法设计中的重要性。


