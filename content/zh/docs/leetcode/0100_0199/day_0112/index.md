---
title: "day_0112 "
date: 2025-09-21T10:32:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0112 

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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(root, s):
            if root is None:
                return False
            s += root.val
            if root.left is None and root.right is None and s == targetSum:
                return True
            return dfs(root.left, s) or dfs(root.right, s)

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

## LeetCode_0112  行解释

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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(root, s):  # 定义深度优先搜索函数，root是当前节点，s是当前路径和
            if root is None:  # 如果当前节点为空
                return False  # 返回False，表示此路径无效
            s += root.val  # 将当前节点的值加到路径和中
            if root.left is None and root.right is None and s == targetSum:  # 如果是叶子节点且路径和等于目标值
                return True  # 返回True，找到有效路径
            return dfs(root.left, s) or dfs(root.right, s)  # 递归检查左子树或右子树是否存在有效路径

        return dfs(root, 0)  # 从根节点开始搜索，初始路径和为0
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

## LeetCode_0112  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(root, s):
            if root is None:
                return False
            s += root.val
            if root.left is None and root.right is None and s == targetSum:
                return True
            return dfs(root.left, s) or dfs(root.right, s)

        return dfs(root, 0) 
```


这段代码使用了**深度优先搜索（DFS）** 和**递归回溯**的数学思想来解决二叉树路径和问题。

## 数学思想解析：

### 1. **递归思想**
- 将大问题分解为相同结构的子问题
- 对于每个节点，问题转化为：是否存在从该节点到叶子节点的路径，使得路径和等于 `targetSum - 当前累计和`

### 2. **状态转移**
- 定义状态：`(当前节点, 当前累计和)`
- 状态转移方程：
  - 如果当前节点是叶子节点且 `当前累计和 + 节点值 == targetSum`，返回 True
  - 否则，递归检查左子树和右子树

### 3. **回溯思想**
- 在递归调用中传递累计和 `s`，而不是修改全局状态
- 每次递归调用结束后自动"回溯"到之前的状态，因为 `s` 是值传递

### 4. **逻辑运算的数学性质**
- 使用 `or` 运算符合并子问题的结果
- `dfs(root.left, s) or dfs(root.right, s)` 体现了**存在性判断**：只要左子树或右子树中存在满足条件的路径，就返回 True

### 5. **基础情况的数学定义**
- 空节点返回 False（数学上的空集不包含解）
- 叶子节点且路径和等于目标值时返回 True（找到解）

## 时间复杂度分析：
- 最坏情况下需要遍历所有节点：O(n)
- 空间复杂度：O(h)，其中 h 是树的高度（递归栈的深度）

这个算法体现了**分治思想**和**递归数学归纳法**的完美结合，通过将问题分解为更小的相同子问题来求解。


