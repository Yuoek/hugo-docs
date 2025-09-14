---
title: "day_0099 "
date: 2025-09-13T20:13:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---


## LeetCode_0099

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
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        def dfs(root):
            if root is None:
                return
            nonlocal prev, first, second
            dfs(root.left)
            if prev and prev.val > root.val:
                if first is None:
                    first = prev
                second = root
            prev = root
            dfs(root.right)

        prev = first = second = None
        dfs(root)
        first.val, second.val = second.val, first.val 
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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        function<void(TreeNode * root)> dfs = [&](TreeNode* root) {
            if (!root) return;
            dfs(root->left);
            if (prev && prev->val > root->val) {
                if (!first) first = prev;
                second = root;
            }
            prev = root;
            dfs(root->right);
        };
        dfs(root);
        swap(first->val, second->val);
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
    private TreeNode prev;
    private TreeNode first;
    private TreeNode second;

    public void recoverTree(TreeNode root) {
        dfs(root);
        int t = first.val;
        first.val = second.val;
        second.val = t;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (prev != null && prev.val > root.val) {
            if (first == null) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        dfs(root.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0099 行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
# 定义二叉树节点的类。
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        不返回任何值，直接原地修改二叉树的节点值。
        """

        # 定义一个递归函数 `dfs`，用于中序遍历二叉树。
        def dfs(root):
            # 如果当前节点为空，直接返回。
            if root is None:
                return
            # 使用 nonlocal 关键字声明外部变量，允许在嵌套函数中修改它们。
            nonlocal prev, first, second
            
            # 递归遍历左子树。
            dfs(root.left)
            
            # 检查当前节点值是否比前一个节点值小（违反二叉搜索树的性质）。
            if prev and prev.val > root.val:
                # 如果是第一次发现异常，记录第一个错误节点。
                if first is None:
                    first = prev
                # 无论是否是第一次发现异常，都记录第二个错误节点。
                second = root
            
            # 更新 `prev` 为当前节点，用于后续比较。
            prev = root
            
            # 递归遍历右子树。
            dfs(root.right)

        # 初始化变量，用于记录中序遍历中的前一个节点和两个错误节点。
        prev = first = second = None
        
        # 调用递归函数 `dfs`，执行中序遍历并找到错误的节点。
        dfs(root)
        
        # 交换两个错误节点的值，恢复二叉搜索树的正确性。
        first.val, second.val = second.val, first.val
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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        function<void(TreeNode * root)> dfs = [&](TreeNode* root) {
            if (!root) return;
            dfs(root->left);
            if (prev && prev->val > root->val) {
                if (!first) first = prev;
                second = root;
            }
            prev = root;
            dfs(root->right);
        };
        dfs(root);
        swap(first->val, second->val);
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
    private TreeNode prev;
    private TreeNode first;
    private TreeNode second;

    public void recoverTree(TreeNode root) {
        dfs(root);
        int t = first.val;
        first.val = second.val;
        second.val = t;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (prev != null && prev.val > root.val) {
            if (first == null) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        dfs(root.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0099 数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        def dfs(root):
            if root is None:
                return
            nonlocal prev, first, second
            dfs(root.left)
            if prev and prev.val > root.val:
                if first is None:
                    first = prev
                second = root
            prev = root
            dfs(root.right)

        prev = first = second = None
        dfs(root)
        first.val, second.val = second.val, first.val 
```


这段代码实现了恢复一个二叉搜索树（Binary Search Tree, BST）的功能。二叉搜索树有一个性质：对于任意节点，其左子树的所有节点值小于该节点值，其右子树的所有节点值大于该节点值。如果这个性质被破坏了（比如两个节点的值被错误交换），这段代码会找到这两个节点并交换它们的值以恢复树的性质。

我们可以用数学思想来解释这段代码的工作原理。

---

### 数学思想背景
1. **有序性**：
   二叉搜索树的中序遍历结果是一个递增序列。换句话说，如果我们按照中序遍历访问所有节点的值，我们应该得到一个严格递增的数列。

2. **局部违反递增性**：
   如果有两个节点的值被错误交换，中序遍历的结果中会出现 **局部递减现象**，即在遍历中我们会发现某些位置 `prev.val > current.val`。我们可以通过寻找这些违反递增性的位置来定位被交换的两个节点。

3. **交换恢复**：
   如果我们能找到这两个错误节点，我们只需要交换它们的值即可恢复树的有序性。

---

### 数学分析代码逻辑
代码的核心思想是通过中序遍历找到两个被交换的节点，然后交换它们的值以恢复树。

#### 1. 中序遍历的性质
通过递归函数 `dfs(root)` 实现中序遍历：
- 首先递归访问左子树。
- 然后处理当前节点。
- 最后递归访问右子树。

中序遍历保证了我们按照递增顺序访问节点值（如果树是正确的二叉搜索树）。

#### 2. 寻找违反递增性的两个节点
在中序遍历过程中，代码比较当前节点值 `root.val` 和前一个节点值 `prev.val`：
- 如果 `prev.val > root.val`，说明这里发生了违反递增性。
- 第一次发现违反递增性时，记录第一个错误节点 `first = prev`。
- 第二次发现违反递增性时，记录第二个错误节点 `second = root`。

数学上，我们可以认为被交换的两个节点分别出现在中序遍历结果中的两个异常位置。

#### 3. 恢复树
在完成中序遍历后，代码交换 `first` 和 `second` 的值：
```python
first.val, second.val = second.val, first.val
```
通过交换值，我们修复了树，使其恢复为一个正确的二叉搜索树。

---

### 数学思想总结
这段代码的数学思想可以总结为：
1. **性质分析**：
   利用二叉搜索树的中序遍历结果应该是递增序列的性质，发现异常点。
2. **错误定位**：
   寻找违反递增性的两个节点，分别记录为 `first` 和 `second`。
3. **局部修正**：
   通过交换两个节点的值修正树，恢复其有序性。

---

### 示例分析
假设有一个二叉搜索树：
```
      3
     / \
    1   4
       /
      2
```
中序遍历结果应该是 `[1, 3, 2, 4]`，但由于节点 `3` 和 `2` 被交换，结果变为 `[1, 2, 3, 4]`，违反了递增性。

代码会找到：
- 第一个错误节点 `first = 3`。
- 第二个错误节点 `second = 2`。

然后交换它们的值，恢复树为：
```
      2
     / \
    1   4
       /
      3
```
中序遍历结果恢复为 `[1, 2, 3, 4]`。

---

### 时间复杂度与空间复杂度
- **时间复杂度**：O(n)，因为我们只需要一次中序遍历。
- **空间复杂度**：O(h)，其中 h 是树的高度，用于递归栈的空间。

通过数学思想和算法的结合，这段代码高效地解决了恢复二叉搜索树的问题。


