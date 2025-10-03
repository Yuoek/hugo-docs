---
title: "day_0105 "
date: 2025-09-21T10:44:43+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0105 

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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:
                return None
            v = preorder[i]
            k = d[v]
            l = dfs(i + 1, j, k - j)
            r = dfs(i + 1 + k - j, k + 1, n - k + j - 1)
            return TreeNode(v, l, r)

        d = {v: i for i, v in enumerate(inorder)}
        return dfs(0, 0, len(preorder)) 
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

## LeetCode_0105  行解释

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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:  # 如果子树节点数为0，返回空节点
                return None
            v = preorder[i]  # 获取前序遍历的当前根节点值
            k = d[v]  # 在中序遍历中找到根节点的位置索引
            l = dfs(i + 1, j, k - j)  # 递归构建左子树：前序起始位置+1，中序起始位置不变，节点数为k-j
            r = dfs(i + 1 + k - j, k + 1, n - k + j - 1)  # 递归构建右子树：前序起始位置+左子树节点数+1，中序起始位置为k+1，节点数为n-k+j-1
            return TreeNode(v, l, r)  # 返回当前根节点，连接左右子树

        d = {v: i for i, v in enumerate(inorder)}  # 创建中序遍历的值到索引的映射字典，便于快速查找
        return dfs(0, 0, len(preorder))  # 从根节点开始递归构建整棵树
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

## LeetCode_0105  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:
                return None
            v = preorder[i]
            k = d[v]
            l = dfs(i + 1, j, k - j)
            r = dfs(i + 1 + k - j, k + 1, n - k + j - 1)
            return TreeNode(v, l, r)

        d = {v: i for i, v in enumerate(inorder)}
        return dfs(0, 0, len(preorder)) 
```


这段代码实现了**通过前序遍历和中序遍历序列重建二叉树**，体现了以下数学思想：

## 1. 递归与分治思想 (Recursion & Divide and Conquer)
- **递归定义**：将大问题分解为相同结构的子问题
- **分治策略**：将树分解为根节点、左子树、右子树三个部分
- **递推关系**：`T(n) = T(k) + T(n-k-1) + O(1)`，其中k为左子树节点数

## 2. 集合映射思想 (Set Mapping)
```python
d = {v: i for i, v in enumerate(inorder)}
```
- 建立中序遍历值到索引的映射，实现O(1)时间复杂度的查找
- 体现了**哈希函数**的数学概念，将值域映射到索引域

## 3. 区间划分与索引计算
关键数学关系：
- **根节点位置**：`preorder[i]` 是当前子树的根
- **左子树大小**：`k - j`（中序遍历中左子树的节点数）
- **右子树起始索引**：
  - 前序：`i + 1 + (k - j)`
  - 中序：`k + 1`

## 4. 数学归纳法
代码的正确性基于：
- **基础情况**：`n <= 0` 时返回空树
- **归纳步骤**：假设对规模更小的子树重建正确，则当前子树重建也正确

## 5. 不变式思想 (Invariant)
在整个递归过程中保持以下不变式：
- `preorder[i:i+n]` 是当前子树的前序遍历
- `inorder[j:j+n]` 是当前子树的中序遍历

这种算法的时间复杂度为O(n)，空间复杂度为O(n)（用于存储哈希映射和递归栈），体现了**空间换时间**的优化思想。

