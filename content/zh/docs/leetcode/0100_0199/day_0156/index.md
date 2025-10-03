---
title: "day_0156 "
date: 2025-09-21T09:16:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0156 

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
    def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None or root.left is None:
            return root
        new_root = self.upsideDownBinaryTree(root.left)
        root.left.right = root
        root.left.left = root.right
        root.left = None
        root.right = None
        return new_root 
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

## LeetCode_0156  行解释

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
    def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None or root.left is None:  # 基本情况：空树或没有左子树
            return root
        new_root = self.upsideDownBinaryTree(root.left)  # 递归处理左子树
        root.left.right = root  # 将当前节点作为原左子节点的右子节点
        root.left.left = root.right  # 将当前节点的右子节点作为原左子节点的左子节点
        root.left = None  # 断开当前节点的左指针
        root.right = None  # 断开当前节点的右指针
        return new_root  # 返回新的根节点
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

## LeetCode_0156  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None or root.left is None:
            return root
        new_root = self.upsideDownBinaryTree(root.left)
        root.left.right = root
        root.left.left = root.right
        root.left = None
        root.right = None
        return new_root 
```


这段代码实现了一个二叉树"上下翻转"操作，其背后的数学思想可以理解为：

**递归与数学归纳法思想**：
1. **基本情况**：当树为空或没有左子树时，直接返回当前节点（归纳的起点）
2. **递归假设**：假设我们已经知道如何翻转左子树，得到新的根节点
3. **递归步骤**：利用已翻转的左子树，重新构建当前节点的连接关系

**几何变换思想**：
- 将二叉树看作一个几何结构，执行180度旋转
- 原树的左子树成为新树的根
- 原树的根节点成为新树的右子节点  
- 原树的右子树成为新树的左子节点

**连接关系变换的数学表达**：
```
new_root = left_subtree (递归翻转后)
root.left.right = root      // 原左子节点指向原根节点
root.left.left = root.right // 原左子节点指向原右子树
root.left = None           // 断开原左连接
root.right = None          // 断开原右连接
```

**时间复杂度分析**：O(n)，其中n为节点数，每个节点只被访问一次
**空间复杂度分析**：O(h)，其中h为树的高度，由递归调用栈深度决定

这个算法体现了递归思想在树结构操作中的典型应用，通过分解问题和组合结果来解决复杂的结构变换问题。


