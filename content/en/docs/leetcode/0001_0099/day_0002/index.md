---
title: "day_0002 "
date: 2025-09-14T11:46:27+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0002 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        carry, curr = 0, dummy
        while l1 or l2 or carry:
            s = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
            carry, val = divmod(s, 10)
            curr.next = ListNode(val)
            curr = curr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int carry = 0;
        ListNode* cur = dummy;
        while (l1 || l2 || carry) {
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        int carry = 0;
        ListNode cur = dummy;
        while (l1 != null || l2 != null || carry != 0) {
            int s = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;
            carry = s / 10;
            cur.next = new ListNode(s % 10);
            cur = cur.next;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0002  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()  # 创建虚拟头节点，简化边界处理
        carry, curr = 0, dummy  # carry表示进位，curr指向当前节点
        while l1 or l2 or carry:  # 当任一链表还有节点或还有进位时继续循环
            s = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry  # 计算当前位的和（包括进位）
            carry, val = divmod(s, 10)  # 计算进位和当前位的值
            curr.next = ListNode(val)  # 创建新节点存储当前位的值
            curr = curr.next  # 移动当前指针到新节点
            l1 = l1.next if l1 else None  # 移动l1指针（如果存在）
            l2 = l2.next if l2 else None  # 移动l2指针（如果存在）
        return dummy.next  # 返回结果链表的头节点（跳过虚拟头节点）
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int carry = 0;
        ListNode* cur = dummy;
        while (l1 || l2 || carry) {
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        int carry = 0;
        ListNode cur = dummy;
        while (l1 != null || l2 != null || carry != 0) {
            int s = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;
            carry = s / 10;
            cur.next = new ListNode(s % 10);
            cur = cur.next;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        return dummy.next;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0002  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        carry, curr = 0, dummy
        while l1 or l2 or carry:
            s = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
            carry, val = divmod(s, 10)
            curr.next = ListNode(val)
            curr = curr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummy.next 
```


这段代码实现了两个链表表示的数字相加，体现了以下数学思想：

## 1. 进位制数学（Carry System）
- 使用 `divmod(s, 10)` 实现了十进制加法中的进位机制
- `carry` 变量存储进位值，模拟了手工加法中的"进位到高位"操作
- 这是基于位置计数法的数学原理

## 2. 逐位运算（Digit-by-Digit Processing）
- 从最低位（链表头）开始逐位相加
- 符合加法运算的基本规则：从右向左逐位相加
- 体现了分解复杂问题为简单子问题的数学思想

## 3. 模运算（Modular Arithmetic）
- `val = s % 10` 获取当前位的值
- `carry = s // 10` 获取进位值
- 这是模10运算在加法中的具体应用

## 4. 零元素处理（Zero Element Handling）
- 使用 `if l1 else 0` 处理链表长度不一致的情况
- 体现了数学中"加零不改变数值"的性质：a + 0 = a

## 5. 数学归纳法思想
- 基础情况：处理完所有位数且进位为0时终止
- 归纳步骤：每次处理一位，将问题规模减小
- 确保算法对所有可能输入都能正确终止

这种实现方式将数学中的进位加法算法完美地映射到了链表数据结构上，体现了数学原理在计算机算法中的具体应用。

