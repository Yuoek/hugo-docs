---
title: "day_0019 "
date: 2025-09-14T11:12:48+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0019 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        fast = slow = dummy
        for _ in range(n):
            fast = fast.next
        while fast.next:
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while (n--) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        while (n-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0019  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义单链表节点类
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)  # 创建虚拟头节点，简化边界情况处理
        fast = slow = dummy  # 初始化快慢指针都指向虚拟头节点
        
        # 快指针先向前移动n步
        for _ in range(n):
            fast = fast.next
            
        # 同时移动快慢指针，直到快指针到达链表末尾
        while fast.next:
            slow, fast = slow.next, fast.next
            
        slow.next = slow.next.next  # 删除倒数第n个节点
        return dummy.next  # 返回删除节点后的链表头节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while (n--) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy, slow = dummy;
        while (n-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0019  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        fast = slow = dummy
        for _ in range(n):
            fast = fast.next
        while fast.next:
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy.next 
```


这段代码使用了**双指针技巧**和**虚拟头节点**的数学思想来解决链表问题：

## 数学思想分析：

### 1. **相对位置关系**（核心思想）
- 设链表长度为 L，要删除倒数第 n 个节点（即正数第 L-n+1 个）
- 让快指针先走 n 步，此时快慢指针相距 n 个节点
- 当快指针到达末尾时（走了 L 步），慢指针正好在倒数第 n+1 个节点
- 这样慢指针就指向了要删除节点的前一个节点

### 2. **等差数列思想**
- 快指针：从起点开始，总共移动 L 步到达末尾
- 慢指针：从起点开始，总共移动 L-n 步到达要删除节点的前一个
- 两者移动步数差为 n，正好是需要跳过的节点数

### 3. **边界处理技巧**
- 使用虚拟头节点 `dummy` 处理删除头节点的特殊情况
- 这样无论删除哪个节点，操作方式都统一为 `slow.next = slow.next.next`

## 时间复杂度：O(L)
- 只需要遍历链表一次，线性时间复杂度

## 空间复杂度：O(1)
- 只使用了常数级别的额外空间

这种解法巧妙地运用了相对位置关系和双指针同步移动的数学原理，既高效又优雅地解决了问题。

