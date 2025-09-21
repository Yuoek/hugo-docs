---
title: "day_0106 "
date: 2025-09-21T10:42:54+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0106 

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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:
                return None
            v = postorder[j + n - 1]
            k = d[v]
            l = dfs(i, j, k - i)
            r = dfs(k + 1, j + k - i, n - k + i - 1)
            return TreeNode(v, l, r)

        d = {v: i for i, v in enumerate(inorder)}
        return dfs(0, 0, len(inorder)) 
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

## LeetCode_0106  行解释

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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:  # 如果子树节点数为0，返回空节点
                return None
            v = postorder[j + n - 1]  # 从后序遍历中获取当前子树的根节点值（最后一个元素）
            k = d[v]  # 在中序遍历中找到根节点的位置索引
            l = dfs(i, j, k - i)  # 递归构建左子树：中序起始i，后序起始j，节点数k-i
            r = dfs(k + 1, j + k - i, n - k + i - 1)  # 递归构建右子树：中序起始k+1，后序起始j+k-i，节点数n-k+i-1
            return TreeNode(v, l, r)  # 返回当前构建的子树根节点

        d = {v: i for i, v in enumerate(inorder)}  # 创建中序遍历的值到索引的映射字典
        return dfs(0, 0, len(inorder))  # 从整个序列的起始位置开始递归构建
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

## LeetCode_0106  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:
                return None
            v = postorder[j + n - 1]
            k = d[v]
            l = dfs(i, j, k - i)
            r = dfs(k + 1, j + k - i, n - k + i - 1)
            return TreeNode(v, l, r)

        d = {v: i for i, v in enumerate(inorder)}
        return dfs(0, 0, len(inorder)) 
```


这段代码实现了通过中序遍历和后序遍历序列重建二叉树的算法，体现了以下数学思想：

## 1. 递归与分治思想 (Recursion & Divide and Conquer)
- **递归定义**：将大问题分解为相同结构的子问题
- **分治策略**：将树分为根节点、左子树、右子树三个部分
- **数学表达式**：T(n) = T(k) + T(n-k-1) + O(1)，其中k为左子树节点数

## 2. 集合映射思想 (Set Mapping)
```python
d = {v: i for i, v in enumerate(inorder)}
```
- 建立值到索引的映射，实现O(1)时间复杂度的查找
- 体现了数学中的函数映射关系：f(value) → index

## 3. 区间划分与索引计算
关键参数含义：
- `i`: 当前子树在中序遍历中的起始索引
- `j`: 当前子树在后序遍历中的起始索引  
- `n`: 当前子树的节点数量

数学关系：
- **根节点位置**：后序遍历的最后一个元素 `postorder[j + n - 1]`
- **左子树大小**：`k - i`（中序遍历中根节点左侧的元素个数）
- **右子树大小**：`n - (k - i) - 1`（总节点数减去左子树和根节点）

## 4. 不变式思想 (Invariant)
算法维护以下不变式：
- 中序遍历 `inorder[i:i+n]` 对应当前子树
- 后序遍历 `postorder[j:j+n]` 对应当前子树
- 根节点始终是后序遍历片段的最后一个元素

## 5. 数学归纳法
算法基于递归的数学归纳思想：
- **基础情形**：n ≤ 0 时返回空树
- **归纳步骤**：假设能正确构建左右子树，则能正确构建整棵树

这种算法的时间复杂度为O(n)，空间复杂度为O(n)，体现了递归分治与哈希映射的巧妙结合。

