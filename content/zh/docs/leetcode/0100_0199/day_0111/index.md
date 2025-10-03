---
title: "day_0111 "
date: 2025-09-21T10:34:30+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0111 

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
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is None:
            return 1 + self.minDepth(root.right)
        if root.right is None:
            return 1 + self.minDepth(root.left)
        return 1 + min(self.minDepth(root.left), self.minDepth(root.right)) 
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

## LeetCode_0111  行解释

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
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:  # 如果根节点为空，深度为0
            return 0
        if root.left is None:  # 如果左子树为空，只能计算右子树的最小深度
            return 1 + self.minDepth(root.right)
        if root.right is None:  # 如果右子树为空，只能计算左子树的最小深度
            return 1 + self.minDepth(root.left)
        return 1 + min(self.minDepth(root.left), self.minDepth(root.right))  # 左右子树都存在，取两者最小深度中的较小值
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

## LeetCode_0111  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is None:
            return 1 + self.minDepth(root.right)
        if root.right is None:
            return 1 + self.minDepth(root.left)
        return 1 + min(self.minDepth(root.left), self.minDepth(root.right)) 
```


这段代码使用了**递归思想**和**分治策略**来计算二叉树的最小深度。

从数学思想角度分析：

1. **递归思想**：将问题分解为更小的同类子问题
   - 基本情况（递归终止条件）：当节点为空时，深度为0
   - 递归情况：计算左右子树的最小深度，然后加上当前层

2. **分治策略**：将原问题分解为两个子问题（左右子树），然后合并结果
   - 如果当前节点没有左子树，则只需考虑右子树
   - 如果当前节点没有右子树，则只需考虑左子树
   - 如果左右子树都存在，则取两者中的较小值

3. **最优子结构**：整个树的最小深度 = 1 + min(左子树最小深度, 右子树最小深度)
   - 这体现了动态规划中的最优子结构特性

4. **边界处理**：代码特别处理了单边子树不存在的情况，避免了空指针异常

数学表达式可以表示为：
minDepth(root) = 
- 0, 如果 root = None
- 1 + minDepth(root.right), 如果 root.left = None
- 1 + minDepth(root.left), 如果 root.right = None  
- 1 + min(minDepth(root.left), minDepth(root.right)), 其他情况

这种递归分治的方法确保了算法的时间复杂度为O(n)，空间复杂度为O(h)，其中h为树的高度。

