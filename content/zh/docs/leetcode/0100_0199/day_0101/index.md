---
title: "day_0101 "
date: 2025-09-21T10:51:46+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0101 

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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def dfs(root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
            if root1 == root2:
                return True
            if root1 is None or root2 is None or root1.val != root2.val:
                return False
            return dfs(root1.left, root2.right) and dfs(root1.right, root2.left)

        return dfs(root.left, root.right) 
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
    bool isSymmetric(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root1, TreeNode* root2) -> bool {
            if (root1 == root2) {
                return true;
            }
            if (!root1 || !root2 || root1->val != root2->val) {
                return false;
            }
            return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
        };
        return dfs(root->left, root->right);
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
    public boolean isSymmetric(TreeNode root) {
        return dfs(root.left, root.right);
    }

    private boolean dfs(TreeNode root1, TreeNode root2) {
        if (root1 == root2) {
            return true;
        }
        if (root1 == null || root2 == null || root1.val != root2.val) {
            return false;
        }
        return dfs(root1.left, root2.right) && dfs(root1.right, root2.left);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0101  行解释

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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def dfs(root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
            if root1 == root2:  # 如果两个节点都是None（相同），返回True
                return True
            if root1 is None or root2 is None or root1.val != root2.val:  # 如果其中一个为None或值不相等，返回False
                return False
            return dfs(root1.left, root2.right) and dfs(root1.right, root2.left)  # 递归检查左子树的左节点和右子树的右节点，以及左子树的右节点和右子树的左节点

        return dfs(root.left, root.right)  # 从根节点的左右子树开始递归检查对称性
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
    bool isSymmetric(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root1, TreeNode* root2) -> bool {
            if (root1 == root2) {
                return true;
            }
            if (!root1 || !root2 || root1->val != root2->val) {
                return false;
            }
            return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
        };
        return dfs(root->left, root->right);
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
    public boolean isSymmetric(TreeNode root) {
        return dfs(root.left, root.right);
    }

    private boolean dfs(TreeNode root1, TreeNode root2) {
        if (root1 == root2) {
            return true;
        }
        if (root1 == null || root2 == null || root1.val != root2.val) {
            return false;
        }
        return dfs(root1.left, root2.right) && dfs(root1.right, root2.left);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0101  数学解释

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def dfs(root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
            if root1 == root2:
                return True
            if root1 is None or root2 is None or root1.val != root2.val:
                return False
            return dfs(root1.left, root2.right) and dfs(root1.right, root2.left)

        return dfs(root.left, root.right) 
```


这段代码使用了**递归思想**和**对称性思想**来判断二叉树是否对称：

## 数学思想解析：

### 1. 递归思想 (Recursive Thinking)
- **递归定义**：将大问题分解为相同结构的子问题
- **基本情况**：当两个节点都为空时，认为是对称的；当只有一个节点为空或值不相等时，不对称
- **递归步骤**：比较左子树的左子树与右子树的右子树，以及左子树的右子树与右子树的左子树

### 2. 对称性思想 (Symmetry Principle)
- **镜像对称**：对称二叉树要求左子树与右子树互为镜像
- **对应关系**：左子树的左节点 ↔ 右子树的右节点
- **对应关系**：左子树的右节点 ↔ 右子树的左节点

### 3. 数学归纳法
代码体现了数学归纳法的思想：
- **基础情形**：处理空节点和叶子节点的情况
- **归纳步骤**：假设子树已经满足对称性，通过递归验证整个树的对称性

### 4. 等价关系
代码通过递归建立了对称性的等价关系：
- 整棵树对称 ⇔ 左子树与右子树互为镜像
- 两棵树互为镜像 ⇔ 根节点值相等且子树满足镜像关系

这种递归对称检查的时间复杂度为 O(n)，空间复杂度为 O(h)（h 为树的高度），是一种优雅且高效的解决方案。


