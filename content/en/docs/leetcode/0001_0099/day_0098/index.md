---
title: "day_0098 "
date: 2025-09-13T20:23:57+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---


{{< katex />}}

## LeetCode_0098 

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
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode]) -> bool:
            if root is None:
                return True
            if not dfs(root.left):
                return False
            nonlocal prev
            if prev >= root.val:
                return False
            prev = root.val
            return dfs(root.right)

        prev = -inf
        return dfs(root) 
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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        function<bool(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return true;
            }
            if (!dfs(root->left)) {
                return false;
            }
            if (prev && prev->val >= root->val) {
                return false;
            }
            prev = root;
            return dfs(root->right);
        };
        return dfs(root);
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

    public boolean isValidBST(TreeNode root) {
        return dfs(root);
    }

    private boolean dfs(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (!dfs(root.left)) {
            return false;
        }
        if (prev != null && prev.val >= root.val) {
            return false;
        }
        prev = root;
        return dfs(root.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0098  行解释

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
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # 定义一个深度优先搜索（DFS）函数，用于验证二叉搜索树
        def dfs(root: Optional[TreeNode]) -> bool:
            # 如果当前节点为空，返回True（空树是合法的二叉搜索树）
            if root is None:
                return True
            # 递归检查左子树是否是合法的二叉搜索树
            if not dfs(root.left):
                return False
            # 使用nonlocal关键字访问外部变量prev
            nonlocal prev
            # 如果当前节点的值小于等于前一个节点的值，则不是合法的二叉搜索树
            if prev >= root.val:
                return False
            # 更新prev为当前节点的值
            prev = root.val
            # 递归检查右子树是否是合法的二叉搜索树
            return dfs(root.right)

        # 初始化prev为负无穷，用于记录中序遍历过程中前一个节点的值
        prev = -inf
        # 调用DFS函数，从根节点开始检查整棵树是否是合法的二叉搜索树
        return dfs(root)
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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        function<bool(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return true;
            }
            if (!dfs(root->left)) {
                return false;
            }
            if (prev && prev->val >= root->val) {
                return false;
            }
            prev = root;
            return dfs(root->right);
        };
        return dfs(root);
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

    public boolean isValidBST(TreeNode root) {
        return dfs(root);
    }

    private boolean dfs(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (!dfs(root.left)) {
            return false;
        }
        if (prev != null && prev.val >= root.val) {
            return false;
        }
        prev = root;
        return dfs(root.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0098  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode]) -> bool:
            if root is None:
                return True
            if not dfs(root.left):
                return False
            nonlocal prev
            if prev >= root.val:
                return False
            prev = root.val
            return dfs(root.right)

        prev = -inf
        return dfs(root) 
```


这个代码是一个实现二叉搜索树（Binary Search Tree, BST）验证的函数。我们可以用数学思想来解释它。

---

### 问题背景：
在数学中，二叉搜索树的定义是：
1. 对于每个节点，其左子树的所有节点值都小于该节点的值。
2. 对于每个节点，其右子树的所有节点值都大于该节点的值。
3. 左子树和右子树本身也必须是二叉搜索树。

验证一个二叉树是否是二叉搜索树的任务可以归结为：
- 检查是否对树中的每个节点及其子树满足以上条件。

---

### 数学思想解释代码：
这段代码采用 **中序遍历** 的方法来验证二叉搜索树的性质。中序遍历是遍历二叉树的一种方式，按照「左子树 -> 当前节点 -> 右子树」的顺序访问节点。

#### 为什么中序遍历适合验证 BST？
根据二叉搜索树的性质，如果对一棵 BST 进行中序遍历，那么得到的节点值序列应该是严格递增的（单调递增但不相等）。也就是说：
\[ \text{对于任意两个相邻的节点值，} v_1 < v_2 \]

#### 核心思想：
我们可以通过中序遍历依次检查节点值是否严格递增。如果某个节点的值小于或等于前一个节点的值，则这棵树不是 BST。

---

### 代码逐步解析：
#### 1. 函数 `dfs` 的作用：
`dfs` 是一个递归函数，用来执行中序遍历，同时验证当前节点值是否满足 BST 的性质。

- **递归基准条件：**
  ```python
  if root is None:
      return True
  ```
  如果当前节点是空节点（即递归到了叶子节点的底部），直接返回 `True`，表示当前子树是有效的 BST。

- **左子树递归：**
  ```python
  if not dfs(root.left):
      return False
  ```
  首先递归遍历左子树。如果左子树不是 BST（`dfs(root.left)` 返回 `False`），直接返回 `False`。

- **检查当前节点值：**
  ```python
  if prev >= root.val:
      return False
  ```
  这里的 `prev` 变量保存了上一个访问的节点值（中序遍历中前一个节点值）。如果当前节点值 `root.val` 小于或等于 `prev`，说明中序遍历序列不是严格递增，返回 `False`。

- **更新 `prev`：**
  ```python
  prev = root.val
  ```
  如果当前节点值合法，则更新 `prev` 为当前节点值，为后续的节点检查做准备。

- **右子树递归：**
  ```python
  return dfs(root.right)
  ```
  最后递归遍历右子树。如果右子树不是 BST，则返回 `False`。

---

#### 2. 初始化 `prev`：
在主函数中：
```python
prev = -inf
```
`prev` 是一个全局变量（通过 `nonlocal` 声明），用于存储中序遍历过程中前一个节点的值。初始值设置为负无穷大（`-inf`），因为二叉搜索树的节点值通常是有限的整数，负无穷大确保任何节点值都大于它。

---

#### 3. 返回结果：
```python
return dfs(root)
```
通过调用 `dfs` 函数，从根节点开始执行中序遍历，并验证整棵树是否满足 BST 的性质。如果满足，返回 `True`；否则返回 `False`。

---

### 数学验证：
- **中序遍历的顺序性：**
  中序遍历的顺序保证了我们按照「从小到大」的顺序检查节点值。
  
- **严格递增的验证：**
  每次访问节点时，通过比较当前节点值和前一个节点值，确保：
  \[
  \text{prev} < \text{root.val}
  \]
  这是 BST 的核心性质。

- **递归的正确性：**
  递归调用分别验证左子树和右子树，并在每次返回时保证当前子树满足 BST 的性质。递归最终覆盖了整棵树。

---

### 总结：
这段代码利用中序遍历和严格递增的数学性质来验证二叉搜索树的定义，整体的数学思想可以概括为：
1. **序列单调性：** BST 的中序遍历序列是严格递增的。
2. **递归分治：** 整棵树的 BST 性质依赖于左子树和右子树的 BST 性质，以及当前节点值与前一个节点值的比较。
3. **全局变量记录状态：** 通过全局变量 `prev` 记录中序遍历的状态，确保节点值严格递增。

这是一种高效且优雅的验证方法，时间复杂度为 \(O(n)\)，空间复杂度为 \(O(h)\)（其中 \(h\) 是树的高度）。



