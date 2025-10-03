---
title: "day_0142 "
date: 2025-09-21T09:40:32+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0142 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                ans = head
                while ans != slow:
                    ans = ans.next
                    slow = slow.next
                return ans 
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

## LeetCode_0142  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义链表节点类
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 使用快慢指针法检测环
        fast = slow = head  # 初始化快慢指针都指向头节点
        
        # 快指针每次走两步，慢指针每次走一步
        while fast and fast.next:
            slow = slow.next  # 慢指针前进一步
            fast = fast.next.next  # 快指针前进两步
            
            # 如果快慢指针相遇，说明存在环
            if slow == fast:
                # 重新从头节点开始一个指针，与相遇点的指针同步前进
                ans = head  # 从头节点开始的新指针
                while ans != slow:
                    ans = ans.next  # 新指针前进一步
                    slow = slow.next  # 相遇点的指针前进一步
                return ans  # 当两个指针相遇时，就是环的入口节点
        
        # 如果没有环，返回None
        return None
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

## LeetCode_0142  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                ans = head
                while ans != slow:
                    ans = ans.next
                    slow = slow.next
                return ans 
```


这段代码使用了**Floyd判圈算法（龟兔赛跑算法）**，体现了以下数学思想：

## 核心数学原理：相遇点与环入口的关系

设：
- 链表头到环入口距离：`a`
- 环入口到相遇点距离：`b`
- 相遇点到环入口距离：`c`
- 环的长度：`L = b + c`

当快慢指针相遇时：
- 慢指针移动距离：`a + b`
- 快指针移动距离：`a + b + nL`（n为快指针在环中跑的圈数）

由于快指针速度是慢指针的2倍：
`2(a + b) = a + b + nL`
=> `a + b = nL`
=> `a = nL - b = (n-1)L + c`

## 算法步骤的数学解释：

1. **第一阶段（检测环）**：快慢指针以2:1速度前进，如果存在环，它们必然在环内某点相遇

2. **第二阶段（寻找入口）**：
   - 将其中一个指针重置到链表头
   - 两个指针以相同速度前进
   - 根据数学推导 `a = (n-1)L + c`，它们将在环入口相遇

## 数学思想体现：
- **同余理论**：通过模运算（环的长度L）建立距离关系
- **线性代数**：建立距离方程并求解
- **数论**：利用倍数关系和模运算性质

这种算法的时间复杂度为O(n)，空间复杂度为O(1)，是检测链表环的最优解。


