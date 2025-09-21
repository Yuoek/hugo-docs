---
title: "day_0114 "
date: 2025-09-21T10:29:18+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0114 

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
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        while root:
            if root.left:
                pre = root.left
                while pre.right:
                    pre = pre.right
                pre.right = root.right
                root.right = root.left
                root.left = None
            root = root.right 
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

## LeetCode_0114  行解释

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
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        while root:
            if root.left:  # 如果当前节点有左子树
                pre = root.left  # 找到左子树的最右节点
                while pre.right:
                    pre = pre.right
                pre.right = root.right  # 将原右子树接到左子树最右节点的右边
                root.right = root.left  # 将左子树移到右边
                root.left = None  # 清空左子树指针
            root = root.right  # 移动到下一个节点继续处理
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

## LeetCode_0114  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        while root:
            if root.left:
                pre = root.left
                while pre.right:
                    pre = pre.right
                pre.right = root.right
                root.right = root.left
                root.left = None
            root = root.right 
```


这段代码实现了二叉树的**前序遍历展开**，使用了**Morris遍历**的思想，这是一种空间复杂度为O(1)的原地算法。

## 数学思想解释：

### 1. **前序遍历的数学结构**
前序遍历的顺序是：根 → 左子树 → 右子树。展开后的链表需要保持这个顺序。

### 2. **关键数学操作**
代码的核心思想是：**对于每个节点，将其左子树插入到右子树之前**

具体数学操作：
- 找到当前节点左子树的最右节点（前序遍历中左子树的最后一个节点）
- 将当前节点的右子树连接到这个最右节点的右侧
- 将左子树移动到右子树的位置
- 清空左指针

### 3. **数学不变式**
算法维护的不变式：**在处理每个节点时，其左侧的所有节点已经被正确展开**

### 4. **时间复杂度分析**
- 每个节点最多被访问2次（一次作为当前节点，一次作为左子树的最右节点）
- 时间复杂度：O(n)，其中n是节点数
- 空间复杂度：O(1)，只使用常数额外空间

### 5. **数学证明思路**
可以用**数学归纳法**证明：
- 基本情况：空树或单节点树显然成立
- 归纳步骤：假设对高度为h的树成立，证明对高度为h+1的树也成立

这种算法巧妙地利用了二叉树的结构特性，通过重新连接指针来实现原地展开，体现了**空间优化**和**指针操作**的数学美感。

