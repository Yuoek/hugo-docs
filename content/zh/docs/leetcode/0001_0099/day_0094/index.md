---
title: "day_0094 "
date: 2025-09-13T21:08:23+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0094 

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
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            ans.append(root.val)
            dfs(root.right)

        ans = []
        dfs(root)
        return ans 
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        return ans;
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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        ans.add(root.val);
        dfs(root.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0094  行解释

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
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 定义一个递归函数，用于实现中序遍历
        def dfs(root):
            # 如果当前节点为空，直接返回
            if root is None:
                return
            # 递归遍历左子树
            dfs(root.left)
            # 将当前节点的值加入结果列表
            ans.append(root.val)
            # 递归遍历右子树
            dfs(root.right)

        # 初始化结果列表，用于存储中序遍历的结果
        ans = []
        # 调用递归函数，从根节点开始进行中序遍历
        dfs(root)
        # 返回中序遍历的结果列表
        return ans
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        return ans;
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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        ans.add(root.val);
        dfs(root.right);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0094  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            ans.append(root.val)
            dfs(root.right)

        ans = []
        dfs(root)
        return ans 
```


这段代码实现了二叉树的**中序遍历**（Inorder Traversal），通过递归的方式对树的节点进行访问，并返回节点值的列表。我们可以用数学思想和递归树的结构来解释它的逻辑。

---

### 数学思想解释

#### 1. 二叉树结构
一个二叉树是一种递归定义的数据结构，它可以被看作是：
- 一个根节点 `root`，以及
- 两个子树：左子树 `root.left` 和右子树 `root.right`。

中序遍历是一种访问二叉树节点的规则，顺序是：
1. **先访问左子树**（递归地遍历左子树）。
2. **访问根节点**（记录当前节点的值）。
3. **再访问右子树**（递归地遍历右子树）。

数学上，递归是一种分治思想，它将一个复杂问题分解为多个相似的子问题。这里，中序遍历可以通过递归定义来解决整个树的遍历问题。

---

#### 2. 递归的思想
递归是一种数学归纳法的编程实现。在这个代码中，函数 `dfs(root)` 的逻辑可以表示为：
- 如果当前节点 `root` 是空节点（即 `root is None`），直接返回（递归的终止条件）。
- 否则：
  1. 递归调用 `dfs(root.left)`，先处理左子树。
  2. 记录当前节点值 `root.val` 到结果列表 `ans`。
  3. 递归调用 `dfs(root.right)`，处理右子树。

递归的核心思想是通过不断缩小问题规模，最终将问题分解为简单的基本问题。

---

#### 3. 数学上的分治思想
对于一棵二叉树 `T`：
- 假设 `T.left` 是左子树，`T.right` 是右子树。
- 中序遍历的结果可以表示为：
  \\[
  \text{Inorder}(T) = \text{Inorder}(T.left) + [T.val] + \text{Inorder}(T.right)
  \\]
这里的 "+" 表示列表的拼接。

这正是代码的逻辑：
- 通过递归计算左子树的中序遍历结果 `dfs(root.left)`。
- 将当前节点值 `root.val` 添加到结果列表。
- 通过递归计算右子树的中序遍历结果 `dfs(root.right)`。

---

### 代码流程分析
1. **初始化**：
   - 创建一个空列表 `ans`，用于存储中序遍历的结果。
   - 定义一个递归函数 `dfs(root)`，用于遍历二叉树。

2. **递归逻辑**：
   - 如果当前节点 `root` 是空节点（`None`），直接返回。
   - 否则：
     - 递归处理左子树：`dfs(root.left)`。
     - 记录当前节点值：`ans.append(root.val)`。
     - 递归处理右子树：`dfs(root.right)`。

3. **返回结果**：
   - 递归结束后，返回结果列表 `ans`。

---

### 示例推导
假设我们有如下二叉树：
```
      1
     / \
    2   3
   / \
  4   5
```

**中序遍历的顺序应该是**：
- 左子树的中序遍历结果：`[4, 2, 5]`
- 根节点：`[1]`
- 右子树的中序遍历结果：`[3]`
最终结果为：`[4, 2, 5, 1, 3]`

代码执行过程：
1. 从根节点 `1` 开始，递归进入左子树 `2`。
2. 从节点 `2` 进入其左子树 `4`，记录值 `4`。
3. 返回到节点 `2`，记录值 `2`，进入右子树 `5`，记录值 `5`。
4. 返回到根节点 `1`，记录值 `1`，进入右子树 `3`，记录值 `3`。
5. 最终结果为 `[4, 2, 5, 1, 3]`。

---

### 总结
这段代码的核心思想是通过递归实现二叉树的中序遍历。数学上，它利用递归定义和分治思想，将整个树的遍历问题分解为多个子树的遍历问题。通过递归的终止条件（空节点）和分解逻辑（先左、再根、后右），最终得到中序遍历的结果。


