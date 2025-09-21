---
title: "day_0104 "
date: 2025-09-21T10:46:32+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0104 

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
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        l, r = self.maxDepth(root.left), self.maxDepth(root.right)
        return 1 + max(l, r) 
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

## LeetCode_0104  行解释

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
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:  # 如果当前节点为空，返回深度0
            return 0
        l, r = self.maxDepth(root.left), self.maxDepth(root.right)  # 递归计算左右子树的深度
        return 1 + max(l, r)  # 返回当前节点深度（1）加上左右子树中较大的深度
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

## LeetCode_0104  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        l, r = self.maxDepth(root.left), self.maxDepth(root.right)
        return 1 + max(l, r) 
```


这段代码使用了**递归思想**和**分治策略**来计算二叉树的最大深度。

从数学角度分析：

1. **递归定义**：二叉树的最大深度可以递归地定义为：
   - 空树的深度为 0（基准情况）
   - 非空树的深度 = 1 + max(左子树深度, 右子树深度)

2. **数学表达式**：
   ```
   depth(T) = { 0, if T is empty
             { 1 + max(depth(T_left), depth(T_right)), otherwise
   ```

3. **分治策略**：
   - 将原问题（求整棵树的深度）分解为两个子问题（求左右子树的深度）
   - 解决子问题（递归调用）
   - 合并子问题的解（取最大值并加1）

4. **时间复杂度**：O(n)，其中n是节点数，每个节点只访问一次
5. **空间复杂度**：O(h)，其中h是树的高度，由递归调用栈的深度决定

这种递归方法体现了**自底向上**的计算方式：先计算最深层节点的深度，然后逐层向上返回结果，最终得到整棵树的最大深度。

