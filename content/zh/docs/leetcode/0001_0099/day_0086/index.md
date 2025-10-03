---
title: "day_0086 "
date: 2025-09-14T08:09:06+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0086 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        l = ListNode()
        r = ListNode()
        tl, tr = l, r
        while head:
            if head.val < x:
                tl.next = head
                tl = tl.next
            else:
                tr.next = head
                tr = tr.next
            head = head.next
        tr.next = None
        tl.next = r.next
        return l.next 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = new ListNode();
        ListNode* r = new ListNode();
        ListNode* tl = l;
        ListNode* tr = r;
        for (; head; head = head->next) {
            if (head->val < x) {
                tl->next = head;
                tl = tl->next;
            } else {
                tr->next = head;
                tr = tr->next;
            }
        }
        tr->next = nullptr;
        tl->next = r->next;
        return l->next;
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
    public ListNode partition(ListNode head, int x) {
        ListNode l = new ListNode();
        ListNode r = new ListNode();
        ListNode tl = l, tr = r;
        for (; head != null; head = head.next) {
            if (head.val < x) {
                tl.next = head;
                tl = tl.next;
            } else {
                tr.next = head;
                tr = tr.next;
            }
        }
        tr.next = null;
        tl.next = r.next;
        return l.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0086  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义单链表节点类
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        # 创建两个虚拟头节点，分别用于存放小于x和大于等于x的节点
        l = ListNode()  # 小于x的链表头
        r = ListNode()  # 大于等于x的链表头
        tl, tr = l, r   # 两个链表的尾指针
        
        # 遍历原始链表
        while head:
            if head.val < x:
                tl.next = head    # 将当前节点连接到左链表尾部
                tl = tl.next      # 移动左链表尾指针
            else:
                tr.next = head    # 将当前节点连接到右链表尾部
                tr = tr.next      # 移动右链表尾指针
            head = head.next      # 移动到下一个节点
        
        tr.next = None    # 将右链表的尾部置为None，防止循环链表
        tl.next = r.next  # 将左链表的尾部连接到右链表的头部
        return l.next     # 返回左链表的第一个实际节点（跳过虚拟头节点）
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = new ListNode();
        ListNode* r = new ListNode();
        ListNode* tl = l;
        ListNode* tr = r;
        for (; head; head = head->next) {
            if (head->val < x) {
                tl->next = head;
                tl = tl->next;
            } else {
                tr->next = head;
                tr = tr->next;
            }
        }
        tr->next = nullptr;
        tl->next = r->next;
        return l->next;
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
    public ListNode partition(ListNode head, int x) {
        ListNode l = new ListNode();
        ListNode r = new ListNode();
        ListNode tl = l, tr = r;
        for (; head != null; head = head.next) {
            if (head.val < x) {
                tl.next = head;
                tl = tl.next;
            } else {
                tr.next = head;
                tr = tr.next;
            }
        }
        tr.next = null;
        tl.next = r.next;
        return l.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0086  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        l = ListNode()
        r = ListNode()
        tl, tr = l, r
        while head:
            if head.val < x:
                tl.next = head
                tl = tl.next
            else:
                tr.next = head
                tr = tr.next
            head = head.next
        tr.next = None
        tl.next = r.next
        return l.next 
```


这段代码使用了**双指针/双链表**的数学思想来实现链表分区：

### 核心思想：分类与重组

### 1. **分类思想**
- 将原链表中的节点按照值是否小于x分为两类
- 使用两个虚拟头节点 `l` 和 `r` 分别管理这两类节点

### 2. **双指针遍历**
- `tl` 和 `tr` 作为尾指针，分别跟踪两个链表的末尾
- 遍历原链表时，根据节点值与x的关系决定将其连接到哪个链表

### 3. **数学归纳法思维**
- 初始状态：两个空链表
- 归纳步骤：对每个节点，根据条件将其归类到相应链表
- 终止状态：所有节点正确分类，然后合并两个链表

### 4. **边界处理**
- `tr.next = None`：确保右链表的末尾指向None，避免循环
- `tl.next = r.next`：将左链表的末尾连接到右链表的开头

### 5. **时间复杂度分析**
- 时间复杂度：O(n)，只需遍历链表一次
- 空间复杂度：O(1)，只使用了常数个额外指针

这种解法体现了**分治思想**和**指针操作的精妙运用**，通过一次遍历完成分类和重组，效率很高。
