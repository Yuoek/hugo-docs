---
title: "day_0107 "
date: 2025-09-21T10:41:05+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0107 

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
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
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
        return ans[::-1] 
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

## LeetCode_0107  行解释

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
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []  # 初始化结果列表，用于存储每层的节点值
        if root is None:  # 如果根节点为空，直接返回空列表
            return ans
        q = deque([root])  # 使用双端队列初始化，将根节点加入队列
        while q:  # 当队列不为空时循环
            t = []  # 临时列表，用于存储当前层的节点值
            for _ in range(len(q)):  # 遍历当前层的所有节点
                node = q.popleft()  # 从队列左侧取出节点
                t.append(node.val)  # 将节点值加入临时列表
                if node.left:  # 如果节点有左子节点
                    q.append(node.left)  # 将左子节点加入队列
                if node.right:  # 如果节点有右子节点
                    q.append(node.right)  # 将右子节点加入队列
            ans.append(t)  # 将当前层的节点值列表加入结果列表
        return ans[::-1]  # 反转结果列表，实现从底向上的层次遍历
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

## LeetCode_0107  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
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
        return ans[::-1] 
```


这段代码使用了**广度优先搜索（Breadth-First Search, BFS）** 的数学思想，具体体现在：

## 核心数学思想：队列与层次遍历

1. **队列数据结构（FIFO）**：
   - 使用双端队列 `deque` 实现先进先出（FIFO）的特性
   - 数学上模拟了树的层次遍历过程

2. **数学归纳法思想**：
   - 基础情况：处理根节点（n=0层）
   - 归纳步骤：处理第n层时，将第n+1层的节点加入队列
   - 确保每一层都被完整处理后再进入下一层

3. **集合划分**：
   - 将树节点按层次划分成不相交的子集（每一层一个子集）
   - 每个节点恰好属于一个层次

4. **逆序操作**：
   - 最后使用 `ans[::-1]` 进行列表反转
   - 数学上相当于对层次序列进行线性变换：f(i) = n-1-i

## 算法复杂度分析：
- **时间复杂度**：O(n)，每个节点恰好被访问一次
- **空间复杂度**：O(n)，队列最多存储约n/2个节点（最宽层的节点数）

这种解法体现了**离散数学**中图遍历的思想，通过队列实现了树的层次遍历，最后通过简单的序列反转得到自底向上的层次遍历结果。

