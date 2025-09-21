---
title: "day_0102 "
date: 2025-09-21T10:50:03+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0102 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(t)
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

## LeetCode_0102  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []  # 初始化结果列表，用于存储每层的节点值
        if root is None:  # 如果根节点为空，直接返回空列表
            return ans
        q = deque([root])  # 使用双端队列初始化，将根节点加入队列
        while q:  # 当队列不为空时循环
            t = []  # 临时列表，用于存储当前层的节点值
            for _ in range(len(q)):  # 遍历当前层的所有节点
                node = q.popleft()  # 从队列左侧取出节点
                t.append(node.val)  # 将当前节点的值加入临时列表
                if node.left:  # 如果当前节点有左子节点
                    q.append(node.left)  # 将左子节点加入队列
                if node.right:  # 如果当前节点有右子节点
                    q.append(node.right)  # 将右子节点加入队列
            ans.append(t)  # 将当前层的节点值列表加入结果列表
        return ans  # 返回层次遍历的结果
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

## LeetCode_0102  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        while q:
            t = []
            for _ in range(len(q)):
                node = q.popleft()
                t.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(t)
        return ans 
```


这段代码实现了二叉树的**层次遍历（广度优先搜索）**，体现了以下数学思想：

## 1. 队列数据结构（FIFO原则）
- 使用双端队列 `deque` 作为队列，遵循**先进先出（FIFO）** 的数学原理
- 这是离散数学中队列抽象数据类型的实现

## 2. 集合论思想
- 每一层的节点构成一个**集合**（用列表 `t` 表示）
- 最终结果是这些集合的**有序序列** `ans = [集合₁, 集合₂, ..., 集合ₙ]`

## 3. 图论中的广度优先搜索（BFS）
- 将二叉树视为**有向无环图**
- 从根节点开始，按**距离根节点的层级**依次访问节点
- 体现了图论中的**层级遍历**算法

## 4. 数学归纳法思想
算法的工作方式：
1. **基础情况**：处理空树（`if root is None`）
2. **归纳步骤**：假设已处理第k层，通过当前层节点可以推导出第k+1层节点

## 5. 组合数学
- 每层节点的值构成一个组合（列表）
- 这些组合按层级顺序排列，形成最终的结果序列

## 算法复杂度分析
- **时间复杂度**：O(n) - 每个节点恰好访问一次
- **空间复杂度**：O(n) - 队列最多存储约n/2个节点（最宽层）

这种实现方式优雅地结合了队列数据结构和广度优先搜索的数学原理，是图遍历算法的经典应用。


