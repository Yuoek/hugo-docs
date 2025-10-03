---
title: "day_0145 "
date: 2025-09-21T09:35:51+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0145 

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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            dfs(root.right)
            ans.append(root.val)

        ans = []
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

## LeetCode_0145  行解释

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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:  # 如果当前节点为空，直接返回
                return
            dfs(root.left)    # 递归遍历左子树
            dfs(root.right)   # 递归遍历右子树
            ans.append(root.val)  # 访问当前节点的值（后序遍历：左右根）

        ans = []  # 初始化结果列表
        dfs(root)  # 从根节点开始递归遍历
        return ans  # 返回后序遍历结果
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

## LeetCode_0145  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            dfs(root.right)
            ans.append(root.val)

        ans = []
        dfs(root)
        return ans 
```


这段代码实现的是二叉树的后序遍历，体现了以下数学思想：

## 1. 递归思想 (Recursive Thinking)
- **数学归纳法**：假设函数能正确处理子树，然后基于此处理当前节点
- **分治策略**：将问题分解为更小的子问题（左子树和右子树）
- **递推关系**：f(root) = f(left) + f(right) + [root.val]

## 2. 树结构理论
- **树的前序定义**：空树是基本情况（base case）
- **遍历顺序的数学性质**：后序遍历 = 左子树后序 + 右子树后序 + 根节点

## 3. 集合运算思想
- **结果的累积性**：ans列表作为全局变量累积遍历结果
- **操作的结合性**：遍历操作满足结合律（顺序不影响最终结果集合）

## 4. 函数式编程思想
- **纯函数的副作用**：虽然使用全局变量ans，但保持了递归过程的数学纯粹性
- **递归终止条件**：root is None 作为递归的边界条件

代码的数学本质是：通过递归将树结构线性化，按照"左-右-根"的顺序生成节点值的序列，这体现了树结构的递归定义和遍历的数学规律。


