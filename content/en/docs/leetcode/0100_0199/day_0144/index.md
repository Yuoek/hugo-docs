---
title: "day_0144 "
date: 2025-09-21T09:37:17+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0144 

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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            ans.append(root.val)
            dfs(root.left)
            dfs(root.right)

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

## LeetCode_0144  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义二叉树节点类
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val          # 节点值
#         self.left = left        # 左子节点
#         self.right = right      # 右子节点

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 定义深度优先搜索（DFS）递归函数
        def dfs(root):
            if root is None:      # 如果当前节点为空，直接返回
                return
            ans.append(root.val)  # 前序遍历：先访问根节点，将节点值加入结果列表
            dfs(root.left)        # 递归遍历左子树
            dfs(root.right)       # 递归遍历右子树

        ans = []                  # 初始化结果列表，用于存储遍历结果
        dfs(root)                 # 从根节点开始递归遍历
        return ans                # 返回前序遍历结果
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

## LeetCode_0144  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            ans.append(root.val)
            dfs(root.left)
            dfs(root.right)

        ans = []
        dfs(root)
        return ans 
```


这段代码使用了**递归**的数学思想来实现二叉树的前序遍历。

从数学角度解释：
1. **递归定义**：前序遍历可以递归地定义为：
   - 访问根节点
   - 前序遍历左子树
   - 前序遍历右子树

2. **递归基（终止条件）**：当节点为None时，递归终止（空树的前序遍历为空）

3. **递归过程**：
   - `ans.append(root.val)` 对应数学定义中的"访问根节点"
   - `dfs(root.left)` 对应"前序遍历左子树"
   - `dfs(root.right)` 对应"前序遍历右子树"

4. **数学归纳法思想**：假设函数`dfs`能够正确完成任意子树的前序遍历，那么通过组合根节点、左子树遍历结果和右子树遍历结果，就能完成整棵树的前序遍历。

5. **递归栈的数学建模**：递归调用形成了函数调用栈，这可以用数学中的栈数据结构来建模，每次递归调用相当于压栈，返回相当于出栈。

这种递归方法体现了**分治思想**：将大问题（遍历整棵树）分解为小问题（遍历子树），通过解决小问题来解决大问题，最终组合得到完整解。

