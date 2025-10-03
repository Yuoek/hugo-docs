---
title: "day_0025 "
date: 2025-09-14T11:00:20+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0025 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            cur = head
            while cur:
                nxt = cur.next
                cur.next = dummy.next
                dummy.next = cur
                cur = nxt
            return dummy.next

        dummy = pre = ListNode(next=head)
        while pre:
            cur = pre
            for _ in range(k):
                cur = cur.next
                if cur is None:
                    return dummy.next
            node = pre.next
            nxt = cur.next
            cur.next = None
            pre.next = reverse(node)
            node.next = nxt
            pre = node
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while (pre != nullptr) {
            ListNode* cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur->next;
                if (cur == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* node = pre->next;
            ListNode* nxt = cur->next;
            cur->next = nullptr;
            pre->next = reverse(node);
            node->next = nxt;
            pre = node;
        }
        return dummy->next;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = nxt;
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        dummy.next = head;
        ListNode pre = dummy;
        while (pre != null) {
            ListNode cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur.next;
                if (cur == null) {
                    return dummy.next;
                }
            }
            ListNode node = pre.next;
            ListNode nxt = cur.next;
            cur.next = null;
            pre.next = reverse(node);
            node.next = nxt;
            pre = node;
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode cur = head;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = nxt;
        }
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0025  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 定义反转链表的辅助函数
        def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()  # 创建虚拟头节点
            cur = head  # 当前节点指针
            while cur:  # 遍历链表进行反转
                nxt = cur.next  # 保存下一个节点
                cur.next = dummy.next  # 当前节点指向dummy的下一个节点
                dummy.next = cur  # dummy指向当前节点
                cur = nxt  # 移动到下一个节点
            return dummy.next  # 返回反转后的链表头

        dummy = pre = ListNode(next=head)  # 创建虚拟头节点，pre指向当前组的起始前一个节点
        while pre:  # 遍历链表
            cur = pre  # 当前指针
            for _ in range(k):  # 检查是否还有k个节点
                cur = cur.next  # 移动到下一个节点
                if cur is None:  # 如果节点不足k个
                    return dummy.next  # 直接返回结果
            node = pre.next  # 保存当前组的起始节点
            nxt = cur.next  # 保存下一组的起始节点
            cur.next = None  # 断开当前组与下一组的连接
            pre.next = reverse(node)  # 反转当前组，并连接到前一组
            node.next = nxt  # 当前组反转后的尾节点连接到下一组
            pre = node  # pre移动到下一组的前一个节点（当前组的尾节点）
        return dummy.next  # 返回结果链表的头节点
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while (pre != nullptr) {
            ListNode* cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur->next;
                if (cur == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* node = pre->next;
            ListNode* nxt = cur->next;
            cur->next = nullptr;
            pre->next = reverse(node);
            node->next = nxt;
            pre = node;
        }
        return dummy->next;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = nxt;
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        dummy.next = head;
        ListNode pre = dummy;
        while (pre != null) {
            ListNode cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur.next;
                if (cur == null) {
                    return dummy.next;
                }
            }
            ListNode node = pre.next;
            ListNode nxt = cur.next;
            cur.next = null;
            pre.next = reverse(node);
            node.next = nxt;
            pre = node;
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode cur = head;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = nxt;
        }
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0025  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            cur = head
            while cur:
                nxt = cur.next
                cur.next = dummy.next
                dummy.next = cur
                cur = nxt
            return dummy.next

        dummy = pre = ListNode(next=head)
        while pre:
            cur = pre
            for _ in range(k):
                cur = cur.next
                if cur is None:
                    return dummy.next
            node = pre.next
            nxt = cur.next
            cur.next = None
            pre.next = reverse(node)
            node.next = nxt
            pre = node
        return dummy.next 
```


这段代码实现了链表的K组反转，主要运用了以下数学思想：

## 1. 分组思想（Grouping）
- 将链表按k个节点为一组进行划分
- 体现了**离散化**的数学思想：将连续问题分解为离散的子问题
- 类似于数学中的**分段函数**概念，对每个区间分别处理

## 2. 递归/迭代思想
- 虽然不是显式递归，但采用了**迭代分组处理**的方式
- 体现了**分治法**思想：将大问题分解为相同的小问题（每组反转）
- 每个子问题（k个节点的反转）都是原问题的简化版本

## 3. 指针操作与数学映射
- 链表反转操作本质上是**指针关系的重新映射**
- `cur.next = dummy.next` 和 `dummy.next = cur` 构成了一个**函数变换**
- 这种变换类似于数学中的**置换操作**，重新排列元素的顺序

## 4. 边界条件处理
- 使用`for _ in range(k)`检查剩余节点是否足够k个
- 体现了**充分必要条件**的数学逻辑：只有当节点数≥k时才进行反转
- 否则保持原顺序（数学中的恒等变换）

## 5. 不变量的维护
- `dummy`节点始终保持指向链表头部
- `pre`指针作为分组间的连接点
- 这类似于数学证明中的**不变量**概念，确保算法正确性

## 数学建模视角
可以将链表视为一个序列：`[a₁, a₂, ..., aₙ]`
算法执行的是分段逆序变换：
```
f(S, k) = reverse(S[0:k]) + f(S[k:], k)  当 len(S) ≥ k
         = S                             当 len(S) < k
```

这种算法设计体现了计算机科学中常见的**分而治之**策略，通过将复杂问题分解为可管理的子问题来解决。

