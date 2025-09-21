---
title: "day_0129 "
date: 2025-09-21T10:04:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0129 

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
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(root, s):
            if root is None:
                return 0
            s = s * 10 + root.val
            if root.left is None and root.right is None:
                return s
            return dfs(root.left, s) + dfs(root.right, s)

        return dfs(root, 0) 
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

## LeetCode_0129  行解释

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
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(root, s):  # 定义深度优先搜索辅助函数，root为当前节点，s为当前路径数字
            if root is None:  # 如果当前节点为空
                return 0  # 返回0，表示该路径无效
            s = s * 10 + root.val  # 更新当前路径数字：原数字左移一位加上当前节点值
            if root.left is None and root.right is None:  # 如果是叶子节点（没有左右子节点）
                return s  # 返回当前路径形成的完整数字
            return dfs(root.left, s) + dfs(root.right, s)  # 递归计算左右子树的路径和并相加

        return dfs(root, 0)  # 从根节点开始DFS，初始路径数字为0
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

## LeetCode_0129  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(root, s):
            if root is None:
                return 0
            s = s * 10 + root.val
            if root.left is None and root.right is None:
                return s
            return dfs(root.left, s) + dfs(root.right, s)

        return dfs(root, 0) 
```


这段代码使用了**深度优先搜索（DFS）** 和**递归**的数学思想来解决二叉树路径数字求和问题。

## 核心数学思想：

### 1. **位置计数法（Positional Notation）**
- 从根节点到叶子节点的路径表示一个数字，如路径 `1→2→3` 表示数字 `123`
- 使用 `s = s * 10 + root.val` 实现十进制数字的构建
- 这体现了**多项式展开**的思想：`123 = 1×10² + 2×10¹ + 3×10⁰`

### 2. **递归与分治（Recursion & Divide and Conquer）**
- 将大问题分解为子问题：整棵树的和 = 左子树的和 + 右子树的和
- 递归基（终止条件）：到达叶子节点时返回当前构建的数字
- 体现了**数学归纳法**的思想：假设子问题已解决，组合得到原问题的解

### 3. **树遍历的数学结构**
- 使用前序遍历（根→左→右）来构建路径数字
- 每个叶子节点对应一个唯一的路径数字
- 最终结果是所有叶子节点路径数字的**求和**

## 数学表达式表示：
对于从根到叶子节点的路径 `v₁→v₂→...→vₙ`，对应的数字为：
```
数字 = v₁ × 10ⁿ⁻¹ + v₂ × 10ⁿ⁻² + ... + vₙ × 10⁰
```
总和的数学表达式为：
```
总和 = ∑(所有从根到叶子的路径数字)
```

这种解法巧妙地结合了树的遍历和数字的数学表示，体现了计算机科学中算法与数学的紧密联系。

