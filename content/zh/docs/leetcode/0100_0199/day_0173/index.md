---
title: "day_0173 "
date: 2025-09-21T08:41:43+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0173 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        def inorder(root):
            if root:
                inorder(root.left)
                self.vals.append(root.val)
                inorder(root.right)

        self.cur = 0
        self.vals = []
        inorder(root)

    def next(self) -> int:
        res = self.vals[self.cur]
        self.cur += 1
        return res

    def hasNext(self) -> bool:
        return self.cur < len(self.vals)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext() 
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

## LeetCode_0173  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        def inorder(root):
            if root:
                inorder(root.left)  # 递归遍历左子树
                self.vals.append(root.val)  # 将当前节点值加入列表
                inorder(root.right)  # 递归遍历右子树

        self.cur = 0  # 初始化当前指针位置
        self.vals = []  # 初始化存储节点值的列表
        inorder(root)  # 执行中序遍历填充列表

    def next(self) -> int:
        res = self.vals[self.cur]  # 获取当前指针位置的节点值
        self.cur += 1  # 指针向后移动一位
        return res  # 返回节点值

    def hasNext(self) -> bool:
        return self.cur < len(self.vals)  # 检查指针是否超出列表范围


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext() 
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

## LeetCode_0173  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        def inorder(root):
            if root:
                inorder(root.left)
                self.vals.append(root.val)
                inorder(root.right)

        self.cur = 0
        self.vals = []
        inorder(root)

    def next(self) -> int:
        res = self.vals[self.cur]
        self.cur += 1
        return res

    def hasNext(self) -> bool:
        return self.cur < len(self.vals)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext() 
```


这段代码实现了一个二叉搜索树迭代器，其数学思想主要基于：

## 1. 中序遍历的有序性
二叉搜索树的中序遍历会产生一个**严格递增序列**，这是二叉搜索树的核心性质：
- 对于任意节点，左子树所有节点值 < 当前节点值 < 右子树所有节点值
- 中序遍历（左-根-右）恰好按升序访问所有节点

## 2. 迭代器的数学抽象
将BST抽象为一个有序序列 `S = {a₁, a₂, a₃, ..., aₙ}`，其中：
- `a₁ < a₂ < a₃ < ... < aₙ`（严格递增）
- 迭代器维护一个指针 `cur` 指向当前元素

## 3. 操作的时间复杂度分析
- **初始化**：O(n) - 需要遍历所有n个节点
- **next()**：O(1) - 直接访问预计算的有序数组
- **hasNext()**：O(1) - 简单比较指针位置

## 4. 空间复杂度
需要O(n)的额外空间存储中序遍历结果，这是用空间换时间的策略。

## 5. 数学等价性
该实现等价于：
- 将BST转换为有序数组
- 在该数组上实现标准迭代器接口

这种设计确保了迭代器能够按升序逐个返回BST中的元素，完全符合二叉搜索树的数学性质。
