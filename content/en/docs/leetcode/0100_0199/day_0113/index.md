---
title: "day_0113 "
date: 2025-09-21T10:31:01+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0113 

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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def dfs(root, s):
            if root is None:
                return
            s += root.val
            t.append(root.val)
            if root.left is None and root.right is None and s == targetSum:
                ans.append(t[:])
            dfs(root.left, s)
            dfs(root.right, s)
            t.pop()

        ans = []
        t = []
        dfs(root, 0)
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

## LeetCode_0113  行解释

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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def dfs(root, s):  # 定义深度优先搜索函数，root是当前节点，s是当前路径和
            if root is None:  # 如果当前节点为空，直接返回
                return
            s += root.val  # 将当前节点的值加到路径和中
            t.append(root.val)  # 将当前节点值添加到临时路径列表
            if root.left is None and root.right is None and s == targetSum:  # 如果是叶子节点且路径和等于目标值
                ans.append(t[:])  # 将当前路径的副本添加到结果列表中（使用副本避免后续修改影响）
            dfs(root.left, s)  # 递归遍历左子树
            dfs(root.right, s)  # 递归遍历右子树
            t.pop()  # 回溯：移除当前节点，尝试其他路径

        ans = []  # 存储所有满足条件的路径
        t = []  # 临时存储当前遍历的路径
        dfs(root, 0)  # 从根节点开始深度优先搜索，初始路径和为0
        return ans  # 返回所有满足条件的路径列表
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

## LeetCode_0113  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def dfs(root, s):
            if root is None:
                return
            s += root.val
            t.append(root.val)
            if root.left is None and root.right is None and s == targetSum:
                ans.append(t[:])
            dfs(root.left, s)
            dfs(root.right, s)
            t.pop()

        ans = []
        t = []
        dfs(root, 0)
        return ans 
```


这段代码使用了**深度优先搜索（DFS）** 和**回溯法**的数学思想来解决二叉树路径和问题：

## 核心数学思想：

### 1. **递归与分治思想**
- 将大问题分解为子问题：从根节点到叶子节点的路径和问题，分解为左子树和右子树的子问题
- 递归基：当节点为空时返回（递归终止条件）

### 2. **回溯法思想**
- **试探性前进**：将当前节点值加入路径列表 `t` 中
- **状态记录**：累计路径和 `s`
- **回退机制**：在递归返回时使用 `t.pop()` 撤销当前选择，恢复到上一状态

### 3. **状态空间搜索**
- 遍历所有可能的路径（状态空间）
- 当遇到叶子节点且路径和等于目标值时，记录当前路径

## 具体实现：
- `dfs(root, s)`：深度优先搜索函数，`s` 记录当前路径和
- `t`：临时存储当前路径
- `ans`：存储所有满足条件的路径
- 时间复杂度：O(n)，需要遍历所有节点
- 空间复杂度：O(h)，递归栈深度为树的高度

这种解法体现了**穷举搜索**和**状态回退**的经典算法思想，通过递归和回溯系统地探索所有可能的解决方案。


