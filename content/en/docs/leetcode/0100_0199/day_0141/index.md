---
title: "day_0141 "
date: 2025-09-21T09:42:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0141 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s = set()
        while head:
            if head in s:
                return True
            s.add(head)
            head = head.next
        return False 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0141  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s = set()  # 创建一个集合来存储已经访问过的节点
        while head:  # 遍历链表直到头节点为空
            if head in s:  # 如果当前节点已经在集合中存在
                return True  # 说明存在环，返回True
            s.add(head)  # 将当前节点添加到集合中
            head = head.next  # 移动到下一个节点
        return False  # 遍历完整个链表都没有发现环，返回False
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0141  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s = set()
        while head:
            if head in s:
                return True
            s.add(head)
            head = head.next
        return False 
```


这段代码使用了**集合（Set）**的数学思想来检测链表中的环。

## 数学思想解释：

### 1. **集合的唯一性原理**
集合中的元素具有唯一性，不能包含重复元素。利用这个特性，我们可以：
- 将遍历过的节点存储在集合中
- 每次遇到新节点时检查是否已存在于集合中
- 如果存在，说明遇到了重复节点，即存在环

### 2. **哈希思想的运用**
虽然这里使用的是Python的set，但其底层实现基于哈希表，体现了：
- **哈希函数的确定性**：每个节点对象有唯一的哈希值
- **快速查找特性**：`head in s`操作的时间复杂度接近O(1)

### 3. **反证法思维**
代码的逻辑基于这样的数学推理：
- 假设链表无环：所有节点都是唯一的，不会重复出现在集合中
- 如果发现重复节点：与假设矛盾，证明存在环

### 4. **空间换时间的权衡**
这种方法用O(n)的空间复杂度换取O(n)的时间复杂度，体现了计算机科学中常见的**时空权衡**思想。

## 数学表示：
设链表节点序列为：a₁ → a₂ → ... → aₙ

如果存在环，则存在i < j使得aᵢ = aⱼ
集合s的作用就是检测这样的相等关系：∃i,j (i≠j) ∧ (aᵢ = aⱼ)

这种方法虽然空间效率不高，但数学原理清晰易懂，是检测环的一种直观解法。


