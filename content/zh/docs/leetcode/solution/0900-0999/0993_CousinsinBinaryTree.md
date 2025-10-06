---
title: "0993_CousinsinBinaryTree"
date: 2025-10-06T00:42:37+08:00
weight: 0993
tags: [树, 深度优先搜索, 广度优先搜索, 二叉树]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [993. 二叉树的堂兄弟节点](https://leetcode.cn/problems/cousins-in-binary-tree)

[English Version](../en/0993-93/0993_CousinsinBinaryTree)

## 题目描述

<!-- description:start -->

<p>在二叉树中，根节点位于深度 <code>0</code> 处，每个深度为 <code>k</code> 的节点的子节点位于深度 <code>k+1</code> 处。</p>

<p>如果二叉树的两个节点深度相同，但<strong> 父节点不同</strong> ，则它们是一对<em>堂兄弟节点</em>。</p>

<p>我们给出了具有唯一值的二叉树的根节点 <code>root</code> ，以及树中两个不同节点的值 <code>x</code> 和 <code>y</code> 。</p>

<p>只有与值 <code>x</code> 和 <code>y</code> 对应的节点是堂兄弟节点时，才返回 <code>true</code> 。否则，返回 <code>false</code>。</p>

<p> </p>

<p><strong>示例 1：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0993.Cousins%20in%20Binary%20Tree/images/q1248-01.png" style="height: 160px; width: 180px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4], x = 4, y = 3
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0993.Cousins%20in%20Binary%20Tree/images/q1248-02.png" style="height: 160px; width: 201px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4,null,5], x = 5, y = 4
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0993.Cousins%20in%20Binary%20Tree/images/q1248-03.png" style="height: 160px; width: 156px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4], x = 2, y = 3
<strong>输出：</strong>false</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树的节点数介于 <code>2</code> 到 <code>100</code> 之间。</li>
	<li>每个节点的值都是唯一的、范围为 <code>1</code> 到 <code>100</code> 的整数。</li>
</ul>

<p> </p>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个队列 $q$，队列中存储的是节点和其父节点。初始时，将根节点和空节点放入队列中。

每次从队列中取出一个节点，如果该节点的值为 $x$ 或 $y$，则记录该节点的父节点和深度。如果该节点的左右子节点不为空，则将左右子节点和该节点放入队列中。

当队列中所有节点都处理完毕后，如果 $x$ 和 $y$ 的深度相同且父节点不同，则返回 $true$，否则返回 $false$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们设计一个函数 $dfs(root, parent, depth)$，表示从根节点 $root$ 出发，其父节点为 $parent$，深度为 $depth$，进行深度优先搜索。

在函数中，我们首先判断当前节点是否为空，如果为空，则直接返回。如果当前节点的值为 $x$ 或 $y$，则记录该节点的父节点和深度。然后对当前节点的左右子节点分别调用函数 $dfs$，其中父节点为当前节点，深度为当前深度加 $1$。即 $dfs(root.left, root, depth + 1)$ 和 $dfs(root.right, root, depth + 1)$。

当整棵二叉树遍历完毕后，如果 $x$ 和 $y$ 的深度相同且父节点不同，则返回 $true$，否则返回 $false$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        def dfs(root, parent, depth):
            if root is None:
                return
            if root.val == x:
                st[0] = (parent, depth)
            elif root.val == y:
                st[1] = (parent, depth)
            dfs(root.left, root, depth + 1)
            dfs(root.right, root, depth + 1)

        st = [None, None]
        dfs(root, None, 0)
        return st[0][0] != st[1][0] and st[0][1] == st[1][1]
```
{{% /tab %}}
{{% tab "java" %}}
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
    private int x, y;
    private int d1, d2;
    private TreeNode p1, p2;

    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        dfs(root, null, 0);
        return p1 != p2 && d1 == d2;
    }

    private void dfs(TreeNode root, TreeNode parent, int depth) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            d1 = depth;
            p1 = parent;
        } else if (root.val == y) {
            d2 = depth;
            p2 = parent;
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
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
    bool isCousins(TreeNode* root, int x, int y) {
        int d1, d2;
        TreeNode* p1;
        TreeNode* p2;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* root, TreeNode* parent, int depth) {
            if (!root) {
                return;
            }
            if (root->val == x) {
                d1 = depth;
                p1 = parent;
            } else if (root->val == y) {
                d2 = depth;
                p2 = parent;
            }
            dfs(root->left, root, depth + 1);
            dfs(root->right, root, depth + 1);
        };
        dfs(root, nullptr, 0);
        return p1 != p2 && d1 == d2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCousins(root *TreeNode, x int, y int) bool {
	var d1, d2 int
	var p1, p2 *TreeNode
	var dfs func(root, parent *TreeNode, depth int)
	dfs = func(root, parent *TreeNode, depth int) {
		if root == nil {
			return
		}
		if root.Val == x {
			d1, p1 = depth, parent
		} else if root.Val == y {
			d2, p2 = depth, parent
		}
		dfs(root.Left, root, depth+1)
		dfs(root.Right, root, depth+1)
	}
	dfs(root, nil, 0)
	return d1 == d2 && p1 != p2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function isCousins(root: TreeNode | null, x: number, y: number): boolean {
    let [d1, d2, p1, p2] = [0, 0, null, null];
    const dfs = (root: TreeNode | null, parent: TreeNode | null, depth: number) => {
        if (!root) {
            return;
        }
        if (root.val === x) {
            [d1, p1] = [depth, parent];
        } else if (root.val === y) {
            [d2, p2] = [depth, parent];
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
    };
    dfs(root, null, 0);
    return d1 === d2 && p1 !== p2;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        def dfs(root, parent, depth):
            if root is None:
                return
            if root.val == x:
                st[0] = (parent, depth)
            elif root.val == y:
                st[1] = (parent, depth)
            dfs(root.left, root, depth + 1)
            dfs(root.right, root, depth + 1)

        st = [None, None]
        dfs(root, None, 0)
        return st[0][0] != st[1][0] and st[0][1] == st[1][1]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
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
    private int x, y;
    private int d1, d2;
    private TreeNode p1, p2;

    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        dfs(root, null, 0);
        return p1 != p2 && d1 == d2;
    }

    private void dfs(TreeNode root, TreeNode parent, int depth) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            d1 = depth;
            p1 = parent;
        } else if (root.val == y) {
            d2 = depth;
            p2 = parent;
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
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
    bool isCousins(TreeNode* root, int x, int y) {
        int d1, d2;
        TreeNode* p1;
        TreeNode* p2;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* root, TreeNode* parent, int depth) {
            if (!root) {
                return;
            }
            if (root->val == x) {
                d1 = depth;
                p1 = parent;
            } else if (root->val == y) {
                d2 = depth;
                p2 = parent;
            }
            dfs(root->left, root, depth + 1);
            dfs(root->right, root, depth + 1);
        };
        dfs(root, nullptr, 0);
        return p1 != p2 && d1 == d2;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}