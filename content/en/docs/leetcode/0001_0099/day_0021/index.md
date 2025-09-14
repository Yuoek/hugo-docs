---
title: "day_0021 "
date: 2025-09-14T11:07:46+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0021 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if list1 is None or list2 is None:
            return list1 or list2
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        if (list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0021  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if list1 is None or list2 is None:  # 如果任一链表为空，直接返回另一个链表
            return list1 or list2
        if list1.val <= list2.val:  # 如果list1的值小于等于list2的值
            list1.next = self.mergeTwoLists(list1.next, list2)  # 递归合并list1的下一个节点和list2
            return list1  # 返回list1作为当前合并后的链表头
        else:  # 如果list2的值小于list1的值
            list2.next = self.mergeTwoLists(list1, list2.next)  # 递归合并list1和list2的下一个节点
            return list2  # 返回list2作为当前合并后的链表头
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        if (list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0021  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if list1 is None or list2 is None:
            return list1 or list2
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2 
```


这段代码使用了**递归思想**和**分治策略**来实现两个有序链表的合并。

## 数学思想解释：

### 1. 递归思想 (Recursive Thinking)
- **基本情况**：当任一链表为空时，直接返回另一个链表（递归终止条件）
- **递归关系**：比较两个链表头节点的值，将较小节点的 `next` 指向剩余部分的合并结果
- **数学归纳法**：假设函数能正确合并任意两个较短链表，那么通过递归调用就能合并当前链表

### 2. 分治策略 (Divide and Conquer)
- **分解**：将问题分解为更小的子问题（合并剩余链表）
- **解决**：递归解决子问题
- **合并**：将子问题的解（合并后的剩余链表）连接到当前较小节点后

### 3. 数学表达式
可以表示为递归关系：
```
merge(l1, l2) = 
    l1,                  if l2 = null
    l2,                  if l1 = null  
    l1 → merge(l1.next, l2), if l1.val ≤ l2.val
    l2 → merge(l1, l2.next), otherwise
```

### 4. 时间复杂度分析
- 每次递归调用处理一个节点
- 总递归深度为两个链表长度之和 (m+n)
- 时间复杂度：O(m+n)
- 空间复杂度：O(m+n)（递归调用栈）

这种递归方法优雅地利用了链表的结构特性，通过数学归纳法保证了算法的正确性。


