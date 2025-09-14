---
title: "day_0083 "
date: 2025-09-14T08:27:46+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0083 

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
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head 
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
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
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
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if (cur.val == cur.next.val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return head;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0083  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 链表节点定义
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head  # 初始化当前指针指向链表头部
        while cur and cur.next:  # 遍历链表直到当前节点或下一个节点为空
            if cur.val == cur.next.val:  # 如果当前节点值与下一个节点值相同
                cur.next = cur.next.next  # 跳过重复节点，直接连接下下个节点
            else:
                cur = cur.next  # 没有重复，移动到下一个节点继续检查
        return head  # 返回处理后的链表头节点
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
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
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
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if (cur.val == cur.next.val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return head;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0083  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head 
```


这段代码使用了**双指针思想**和**链表遍历思想**来删除排序链表中的重复元素。

## 数学思想解释：

### 1. **双指针思想**
代码中使用了隐式的双指针：
- `cur`：当前指针，指向当前处理的节点
- `cur.next`：下一个指针，指向当前节点的下一个节点

这两个指针协同工作，通过比较它们的值来决定是否删除重复节点。

### 2. **链表遍历思想**
算法采用**线性遍历**的方式处理链表，时间复杂度为 O(n)，其中 n 是链表长度。这是一种典型的**顺序处理**思想。

### 3. **重复检测与删除机制**
当 `cur.val == cur.next.val` 时，执行删除操作：
```
cur.next = cur.next.next
```
这相当于数学中的**跳过重复项**操作，通过修改指针引用直接跳过重复节点。

### 4. **边界条件处理**
- `while cur and cur.next:` 确保不会访问空指针
- 当遇到重复时，`cur` 保持不动，继续检查新的 `cur.next`
- 当没有重复时，`cur` 向前移动

### 5. **数学归纳法视角**
可以看作是一个**递推过程**：
- 基础情况：空链表或单节点链表直接返回
- 递推步骤：对于每个节点，如果下一个节点重复则删除，否则移动到下一个节点

这种算法体现了**贪心思想**，每次只处理当前看到的重复项，通过局部最优操作达到全局最优解。
