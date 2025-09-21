---
title: "day_0110 "
date: 2025-09-21T10:36:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0110 

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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root):
            if root is None:
                return 0
            l, r = height(root.left), height(root.right)
            if l == -1 or r == -1 or abs(l - r) > 1:
                return -1
            return 1 + max(l, r)

        return height(root) >= 0 
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

## LeetCode_0110  行解释

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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root):
            if root is None:  # 如果节点为空，返回高度0
                return 0
            l, r = height(root.left), height(root.right)  # 递归计算左右子树的高度
            if l == -1 or r == -1 or abs(l - r) > 1:  # 如果左右子树不平衡或高度差大于1，返回-1表示不平衡
                return -1
            return 1 + max(l, r)  # 返回当前节点的高度（左右子树最大高度+1）

        return height(root) >= 0  # 如果最终高度不是-1，说明树是平衡的
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

## LeetCode_0110  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root):
            if root is None:
                return 0
            l, r = height(root.left), height(root.right)
            if l == -1 or r == -1 or abs(l - r) > 1:
                return -1
            return 1 + max(l, r)

        return height(root) >= 0 
```


这段代码使用了**递归**和**提前终止**的数学思想来解决二叉树平衡性判断问题。

## 核心数学思想：

1. **递归定义树的高度**：
   - 空树高度为0
   - 非空树高度 = 1 + max(左子树高度, 右子树高度)

2. **平衡性条件**：
   - 左右子树高度差绝对值 ≤ 1
   - 左右子树本身也是平衡的

3. **编码技巧**：
   - 使用-1作为"不平衡"的特殊标记值
   - 在计算高度的同时检查平衡性，实现提前终止

## 数学过程分析：

对于每个节点，算法执行：
1. 递归计算左子树高度
2. 递归计算右子树高度  
3. 检查：如果任一子树不平衡，或左右高度差>1，则返回-1
4. 否则返回当前节点的高度 = 1 + max(左高, 右高)

## 时间复杂度：O(n)
每个节点只被访问一次，实现了线性时间复杂度。

这种设计体现了**分治思想**和**信息复用**的数学优化策略，通过一次深度优先遍历同时完成高度计算和平衡性检查。

