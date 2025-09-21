---
title: "day_0109 "
date: 2025-09-21T10:37:59+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0109 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def dfs(i: int, j: int) -> Optional[TreeNode]:
            if i > j:
                return None
            mid = (i + j) >> 1
            l, r = dfs(i, mid - 1), dfs(mid + 1, j)
            return TreeNode(nums[mid], l, r)

        nums = []
        while head:
            nums.append(head.val)
            head = head.next
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

## LeetCode_0109  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def dfs(i: int, j: int) -> Optional[TreeNode]:
            if i > j:  # 递归终止条件：当起始索引大于结束索引时，返回空节点
                return None
            mid = (i + j) >> 1  # 计算中间索引，使用位运算右移1位相当于除以2
            l, r = dfs(i, mid - 1), dfs(mid + 1, j)  # 递归构建左右子树
            return TreeNode(nums[mid], l, r)  # 创建当前根节点，值为中间索引对应的值，左右子树分别为递归结果

        nums = []  # 初始化空列表用于存储链表值
        while head:  # 遍历链表，将节点值存入列表
            nums.append(head.val)
            head = head.next
        return dfs(0, len(nums) - 1)  # 从整个列表范围开始递归构建平衡二叉搜索树
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

## LeetCode_0109  数学解释

```python 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def dfs(i: int, j: int) -> Optional[TreeNode]:
            if i > j:
                return None
            mid = (i + j) >> 1
            l, r = dfs(i, mid - 1), dfs(mid + 1, j)
            return TreeNode(nums[mid], l, r)

        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        return dfs(0, len(nums) - 1) 
```


这段代码使用了**分治思想**和**递归思想**来解决将有序链表转换为平衡二叉搜索树的问题。

## 核心数学思想：

### 1. 分治思想 (Divide and Conquer)
- **分解**：将有序链表转换为有序数组，然后递归地将数组分成左右两部分
- **解决**：每次取中间元素作为根节点，确保左右子树高度平衡
- **合并**：将左右子树连接到根节点，构建完整的BST

### 2. 中位数原理
- 每次选择数组中间位置的元素作为根节点
- 数学表达式：`mid = (i + j) // 2`
- 这保证了左右子树的节点数量最多相差1，从而构建出高度平衡的BST

### 3. 递归思想
- 递归构建左右子树：`dfs(i, mid-1)` 和 `dfs(mid+1, j)`
- 基线条件：当 `i > j` 时返回空节点

### 4. 空间换时间策略
- 先将链表转换为数组 `nums`，牺牲O(n)空间复杂度
- 获得O(1)时间复杂度的随机访问能力，便于快速找到中间元素

## 数学优势：
- 时间复杂度：O(n) - 每个节点处理一次
- 空间复杂度：O(n) - 存储数组和递归调用栈
- 保证了BST的高度平衡性，树高为O(log n)

这种解法巧妙地结合了分治策略和递归技术，利用有序数组的特性高效构建平衡二叉搜索树。


