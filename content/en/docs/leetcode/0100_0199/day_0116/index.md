---
title: "day_0116 "
date: 2025-09-21T10:25:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0116 

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
    def connect(self, root: "Optional[Node]") -> "Optional[Node]":
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

## LeetCode_0116  行解释

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
    def connect(self, root: "Optional[Node]") -> "Optional[Node]":
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

## LeetCode_0116  数学解释

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
    def connect(self, root: "Optional[Node]") -> "Optional[Node]":
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


这段代码使用了**广度优先搜索（Breadth-First Search, BFS）** 的数学思想，具体来说是**层次遍历（Level Order Traversal）**。

## 核心数学思想：

1. **队列数据结构（Queue）**：使用队列实现BFS，保证按层次顺序处理节点
2. **层次遍历**：每次处理一层的所有节点，从左到右连接它们的next指针

## 数学原理：

- **集合论**：将每层节点视为一个集合，按层次顺序处理
- **图论**：将二叉树视为有向图，使用BFS进行遍历
- **指针操作**：使用指针p来记录前一个节点，建立next连接

## 算法步骤：

1. 初始化队列，将根节点加入
2. 对于每一层：
   - 记录该层节点数量（队列长度）
   - 使用指针p记录前一个节点
   - 遍历该层所有节点，建立next指针连接
   - 将子节点加入队列（下一层）

## 时间复杂度：O(n)
## 空间复杂度：O(n)

这种解法完美地体现了**广度优先搜索**在二叉树层次遍历中的应用，通过队列实现了按层次处理节点的数学思想。


