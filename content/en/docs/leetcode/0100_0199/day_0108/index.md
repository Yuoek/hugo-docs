---
title: "day_0108 "
date: 2025-09-21T10:39:37+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0108 

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
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def dfs(l: int, r: int) -> Optional[TreeNode]:
            if l > r:
                return None
            mid = (l + r) >> 1
            return TreeNode(nums[mid], dfs(l, mid - 1), dfs(mid + 1, r))

        return dfs(0, len(nums) - 1) 
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

## LeetCode_0108  行解释

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
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def dfs(l: int, r: int) -> Optional[TreeNode]:
            if l > r:  # 如果左边界大于右边界，说明当前子树为空
                return None
            mid = (l + r) >> 1  # 计算中间位置，使用位运算右移1位相当于除以2
            return TreeNode(nums[mid], dfs(l, mid - 1), dfs(mid + 1, r))  # 创建根节点，递归构建左右子树

        return dfs(0, len(nums) - 1)  # 从整个数组范围开始递归构建平衡二叉搜索树
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

## LeetCode_0108  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def dfs(l: int, r: int) -> Optional[TreeNode]:
            if l > r:
                return None
            mid = (l + r) >> 1
            return TreeNode(nums[mid], dfs(l, mid - 1), dfs(mid + 1, r))

        return dfs(0, len(nums) - 1) 
```


这段代码使用了**分治思想**和**二分查找思想**来构建平衡二叉搜索树。

## 数学思想解释：

1. **分治思想 (Divide and Conquer)**
   - 将原问题（构建整个BST）分解为子问题（构建左右子树）
   - 递归地解决子问题
   - 合并子问题的解（将左右子树连接到根节点）

2. **二分查找思想 (Binary Search)**
   - 每次选择当前区间的中间元素作为根节点
   - 这样确保左右子树的节点数量尽可能平衡
   - 时间复杂度：O(n)，每个节点只被访问一次

3. **数学归纳法思想**
   - 基本情况：当区间为空时返回None
   - 归纳步骤：假设能正确构建左右子树，则能正确构建当前树

## 关键数学特性：
- 选择中间元素作为根节点，使得左右子树的高度差不超过1
- 由于输入数组已排序，构建的树自然满足BST性质（左子树 < 根 < 右子树）
- 递归深度为O(log n)，因为每次都将问题规模减半

这种方法的优雅之处在于它充分利用了排序数组的特性，通过简单的二分策略就实现了最优的平衡BST构建。


