---
title: "day_0117 "
date: 2025-09-21T10:24:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0117 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: "Node") -> "Node":
        if root is None:
            return root
        q = deque([root])
        while q:
            p = None
            for _ in range(len(q)):
                node = q.popleft()
                if p:
                    p.next = node
                p = node
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return root 
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

## LeetCode_0117  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: "Node") -> "Node":
        if root is None:  # 如果根节点为空，直接返回
            return root
        q = deque([root])  # 创建队列，初始包含根节点
        while q:  # 当队列不为空时循环
            p = None  # 初始化前一个节点指针
            for _ in range(len(q)):  # 遍历当前层的所有节点
                node = q.popleft()  # 从队列左侧取出节点
                if p:  # 如果前一个节点存在
                    p.next = node  # 将前一个节点的next指向当前节点
                p = node  # 更新前一个节点为当前节点
                if node.left:  # 如果当前节点有左子节点
                    q.append(node.left)  # 将左子节点加入队列
                if node.right:  # 如果当前节点有右子节点
                    q.append(node.right)  # 将右子节点加入队列
        return root  # 返回连接后的根节点
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

## LeetCode_0117  数学解释

```python 
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: "Node") -> "Node":
        if root is None:
            return root
        q = deque([root])
        while q:
            p = None
            for _ in range(len(q)):
                node = q.popleft()
                if p:
                    p.next = node
                p = node
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return root 
```


这段代码使用了**广度优先搜索（BFS）** 的数学思想，具体来说是**层次遍历**的思想。

## 数学思想解释：

1. **队列数据结构（先进先出）**：使用队列来维护待处理的节点，确保按层级顺序处理节点

2. **层次遍历**：每次处理一层的所有节点，通过记录当前队列长度来确定每层的节点数量

3. **指针连接**：对于每一层，使用指针 `p` 来连接当前节点与前一个节点，形成链表结构

## 数学过程描述：

- 初始化：将根节点加入队列
- 对于每一层：
  - 记录当前队列长度 n（即该层节点数）
  - 遍历该层所有 n 个节点：
    - 出队当前节点
    - 如果存在前一个节点 `p`，则将 `p.next` 指向当前节点
    - 将当前节点设为新的 `p`
    - 将当前节点的左右子节点加入队列（为下一层做准备）
- 重复直到队列为空

## 时间复杂度分析：
- 每个节点入队出队各一次：O(n)
- 每个节点的连接操作：O(1)
- 总体时间复杂度：O(n)

这种算法确保了完美二叉树的每一层节点都通过 `next` 指针正确连接，形成链表结构。
