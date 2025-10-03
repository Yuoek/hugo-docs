---
title: "day_0100 "
date: 2025-09-21T10:52:05+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0100 

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
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == q:
            return True
        if p is None or q is None or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == q) return true;
        if (p == null || q == null || p.val != q.val) return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0100  行解释

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
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == q:  # 如果两个节点是同一个对象（或都为None），返回True
            return True
        if p is None or q is None or p.val != q.val:  # 如果任一节点为None或节点值不相等，返回False
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)  # 递归检查左右子树是否相同
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == q) return true;
        if (p == null || q == null || p.val != q.val) return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0100  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == q:
            return True
        if p is None or q is None or p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) 
```


这段代码使用了**递归思想**和**分治思想**来判断两棵二叉树是否相同。

## 数学思想分析：

### 1. 递归思想 (Recursive Thinking)
- **基本情况 (Base Cases)**：
  - `if p == q:`：如果两个节点完全相同（包括都为None的情况），返回True
  - `if p is None or q is None or p.val != q.val:`：如果任一节点为空或节点值不同，返回False

- **递归步骤 (Recursive Step)**：
  - `return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)`
  - 将大问题分解为两个子问题：比较左子树和比较右子树

### 2. 分治思想 (Divide and Conquer)
- 将判断整棵树是否相同的问题分解为：
  - 判断当前节点是否相同
  - 判断左子树是否相同（子问题1）
  - 判断右子树是否相同（子问题2）
- 只有当所有子问题都返回True时，整个问题才返回True

### 3. 数学归纳法
代码遵循数学归纳法的思想：
- 基础情况：处理空树和单节点的情况
- 归纳假设：假设对于较小的子树，函数能正确判断是否相同
- 归纳步骤：通过组合子树的结果来判断整棵树是否相同

### 4. 树的结构性质
利用了二叉树的递归定义：一棵二叉树由根节点、左子树和右子树组成。两棵树相同当且仅当：
- 根节点值相同
- 左子树相同
- 右子树相同

这种递归解法的时间复杂度为O(n)，其中n是节点数，因为需要遍历所有节点；空间复杂度为O(h)，其中h是树的高度，由递归调用栈的深度决定。


