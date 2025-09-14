---
title: "day_0082 "
date: 2025-09-14T08:29:38+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0082 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = pre = ListNode(next=head)
        cur = head
        while cur:
            while cur.next and cur.next.val == cur.val:
                cur = cur.next
            if pre.next == cur:
                pre = cur
            else:
                pre.next = cur.next
            cur = cur.next
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if (pre->next == cur) {
                pre = cur;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur != null) {
            while (cur.next != null && cur.next.val == cur.val) {
                cur = cur.next;
            }
            if (pre.next == cur) {
                pre = cur;
            } else {
                pre.next = cur.next;
            }
            cur = cur.next;
        }
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0082  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义单链表节点类
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 创建虚拟头节点，pre指针用于跟踪前一个非重复节点
        dummy = pre = ListNode(next=head)
        # cur指针用于遍历链表
        cur = head
        
        while cur:
            # 跳过所有重复节点，直到找到下一个不同值的节点
            while cur.next and cur.next.val == cur.val:
                cur = cur.next
            
            # 如果pre的下一个节点就是cur，说明cur是唯一的，移动pre指针
            if pre.next == cur:
                pre = cur
            else:
                # 否则说明有重复，跳过所有重复节点
                pre.next = cur.next
            
            # 移动到下一个节点继续处理
            cur = cur.next
        
        # 返回处理后的链表头节点
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if (pre->next == cur) {
                pre = cur;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur != null) {
            while (cur.next != null && cur.next.val == cur.val) {
                cur = cur.next;
            }
            if (pre.next == cur) {
                pre = cur;
            } else {
                pre.next = cur.next;
            }
            cur = cur.next;
        }
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0082  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = pre = ListNode(next=head)
        cur = head
        while cur:
            while cur.next and cur.next.val == cur.val:
                cur = cur.next
            if pre.next == cur:
                pre = cur
            else:
                pre.next = cur.next
            cur = cur.next
        return dummy.next 
```


这段代码使用了**双指针**和**虚拟头节点**的数学思想来解决链表去重问题：

## 核心数学思想：

1. **双指针追踪**（Two Pointers Tracking）
   - `pre`指针：指向当前已处理好的非重复链表的最后一个节点
   - `cur`指针：遍历原始链表，寻找重复序列的结束位置

2. **滑动窗口识别重复序列**（Sliding Window for Duplicate Detection）
   - 内层while循环：识别连续的重复值序列，`cur`指针滑动到该重复序列的最后一个节点

3. **集合操作思维**（Set Operation Mindset）
   - 将链表视为一个有序集合，目标是去除所有重复元素，只保留每个值的第一次出现

## 数学过程描述：

```
初始状态：dummy → head → ... → null
        pre
        cur

处理过程：
1. 当发现重复序列时（cur.next.val == cur.val）：
   - cur指针滑动到重复序列末尾
   
2. 如果pre.next == cur（说明没有重复）：
   - pre指针前进到cur位置
   
3. 否则（有重复）：
   - pre.next指向cur.next（跳过所有重复节点）
   
4. cur指针继续前进
```

## 数学性质保证：
- **不变性**：pre指针始终指向已处理好的非重复链表的末尾
- **完备性**：通过遍历所有节点确保所有重复都被处理
- **有序性保持**：由于链表本身有序，重复元素必然连续出现

这种解法的时间复杂度为O(n)，空间复杂度为O(1)，是典型的线性扫描算法在链表数据结构上的应用。

