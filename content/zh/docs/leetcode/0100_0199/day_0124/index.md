---
title: "day_0124 "
date: 2025-09-21T10:13:22+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0124 

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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            left = max(0, dfs(root.left))
            right = max(0, dfs(root.right))
            nonlocal ans
            ans = max(ans, root.val + left + right)
            return root.val + max(left, right)

        ans = -inf
        dfs(root)
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

## LeetCode_0124  行解释

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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0  # 空节点返回0
            left = max(0, dfs(root.left))  # 计算左子树最大贡献值，负数则取0
            right = max(0, dfs(root.right))  # 计算右子树最大贡献值，负数则取0
            nonlocal ans  # 引用外部变量ans
            ans = max(ans, root.val + left + right)  # 更新全局最大路径和（可能包含当前节点的完整路径）
            return root.val + max(left, right)  # 返回当前节点的最大贡献值（只能选择一条子树路径）

        ans = -inf  # 初始化全局最大路径和为负无穷
        dfs(root)  # 从根节点开始深度优先搜索
        return ans  # 返回全局最大路径和
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

## LeetCode_0124  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            left = max(0, dfs(root.left))
            right = max(0, dfs(root.right))
            nonlocal ans
            ans = max(ans, root.val + left + right)
            return root.val + max(left, right)

        ans = -inf
        dfs(root)
        return ans 
```


这段代码使用了**分治思想**和**动态规划思想**来解决二叉树中的最大路径和问题：

## 数学思想分析：

### 1. 分治思想 (Divide and Conquer)
- **分解**：将问题分解为左子树和右子树的子问题
- **解决**：递归求解左右子树的最大贡献值
- **合并**：将左右子树的结果与当前节点值合并，计算全局最大值

### 2. 动态规划思想
- **状态定义**：`dfs(root)` 返回以当前节点为起点的最大路径和
- **状态转移**：当前节点的最大路径和 = 节点值 + max(左子树贡献, 右子树贡献)
- **最优子结构**：全局最优解由局部最优解组合得到

### 3. 关键数学操作：
- `max(0, dfs(root.left))`：确保只选择正贡献的子树
- `ans = max(ans, root.val + left + right)`：计算经过当前节点的最大路径和
- `return root.val + max(left, right)`：返回当前节点的最大贡献值

### 4. 时间复杂度：O(n)
每个节点只被访问一次，符合线性时间复杂度

这种解法巧妙地结合了递归遍历和状态维护，通过后序遍历的方式自底向上地计算最优解。


