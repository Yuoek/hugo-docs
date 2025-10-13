---
title: "1110_删点成林"
date: 2025-10-08T18:36:57+08:00
weight: 2
tags: [二叉树, 哈希表, 多线程, 字符串, 数学, 数据库, 数组, 栈, 树, 深度优先搜索]
---

{{< markmap >}}
### [1110_删点成林](#1110)
#### [树](#1110)
#### [深度优先搜索](#1110)
#### [数组](#1110)
#### [哈希表](#1110)
#### [二叉树](#1110)
### [1111_有效括号的嵌套深度](#1111)
#### [栈](#1111)
#### [字符串](#1111)
### [1112_每位学生的最高成绩 🔒](#1112)
#### [数据库](#1112)
### [1113_报告的记录 🔒](#1113)
#### [数据库](#1113)
### [1114_按序打印](#1114)
#### [多线程](#1114)
### [1115_交替打印 FooBar](#1115)
#### [多线程](#1115)
### [1116_打印零与奇偶数](#1116)
#### [多线程](#1116)
### [1117_H2O 生成](#1117)
#### [多线程](#1117)
### [1118_一月有多少天 🔒](#1118)
#### [数学](#1118)
### [1119_删去字符串中的元音 🔒](#1119)
#### [字符串](#1119)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1110_删点成林
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 哈希表
___
#### 二叉树
---
### 1111_有效括号的嵌套深度
___
#### 栈
___
#### 字符串
---
### 1112_每位学生的最高成绩 🔒
___
#### 数据库
---
### 1113_报告的记录 🔒
___
#### 数据库
---
### 1114_按序打印
___
#### 多线程
---
### 1115_交替打印 FooBar
___
#### 多线程
---
### 1116_打印零与奇偶数
___
#### 多线程
---
### 1117_H2O 生成
___
#### 多线程
---
### 1118_一月有多少天 🔒
___
#### 数学
---
### 1119_删去字符串中的元音 🔒
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 哈希表 | 多线程 |
| 字符串 | 数学 | 数据库 |
| 数组 | 栈 | 树 |
| 深度优先搜索 |  |  |

# [1110. 删点成林](https://leetcode.cn/problems/delete-nodes-and-return-forest){#1110}

{{< tabs "1110" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        def dfs(root: Optional[TreeNode]) -> Optional[TreeNode]:
            if root is None:
                return None
            root.left, root.right = dfs(root.left), dfs(root.right)
            if root.val not in s:
                return root
            if root.left:
                ans.append(root.left)
            if root.right:
                ans.append(root.right)
            return None

        s = set(to_delete)
        ans = []
        if dfs(root):
            ans.append(root)
        return ans
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
    private boolean[] s = new boolean[1001];
    private List<TreeNode> ans = new ArrayList<>();

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        for (int x : to_delete) {
            s[x] = true;
        }
        if (dfs(root) != null) {
            ans.add(root);
        }
        return ans;
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null) {
            return null;
        }
        root.left = dfs(root.left);
        root.right = dfs(root.right);
        if (!s[root.val]) {
            return root;
        }
        if (root.left != null) {
            ans.add(root.left);
        }
        if (root.right != null) {
            ans.add(root.right);
        }
        return null;
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        bool s[1001];
        memset(s, 0, sizeof(s));
        for (int x : to_delete) {
            s[x] = true;
        }
        vector<TreeNode*> ans;
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) -> TreeNode* {
            if (!root) {
                return nullptr;
            }
            root->left = dfs(root->left);
            root->right = dfs(root->right);
            if (!s[root->val]) {
                return root;
            }
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return nullptr;
        };
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
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
func delNodes(root *TreeNode, to_delete []int) (ans []*TreeNode) {
	s := make([]bool, 1001)
	for _, x := range to_delete {
		s[x] = true
	}
	var dfs func(*TreeNode) *TreeNode
	dfs = func(root *TreeNode) *TreeNode {
		if root == nil {
			return nil
		}
		root.Left = dfs(root.Left)
		root.Right = dfs(root.Right)
		if !s[root.Val] {
			return root
		}
		if root.Left != nil {
			ans = append(ans, root.Left)
		}
		if root.Right != nil {
			ans = append(ans, root.Right)
		}
		return nil
	}
	if dfs(root) != nil {
		ans = append(ans, root)
	}
	return
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
export function delNodes(root: T, to_delete: number[]): Array<T> {
    if (!root) return [];

    const del = new Set(to_delete);
    const res: T[] = [];
    let q: TreeNode[] = [root];

    while (q.length) {
        const qNext: TreeNode[] = [];

        for (const node of q) {
            if (node.left) {
                qNext.push(node.left);

                if (del.has(node.left.val)) {
                    node.left = null;
                }
            }

            if (node.right) {
                qNext.push(node.right);

                if (del.has(node.right.val)) {
                    node.right = null;
                }
            }

            if (del.has(node.val)) {
                if (node.left) res.push(node.left);
                if (node.right) res.push(node.right);
            }
        }

        q = qNext;
    }

    if (!del.has(root.val)) res.push(root);

    return res;
}

type T = TreeNode | null;
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function (root, to_delete) {
    if (!root) return [];

    const del = new Set(to_delete);
    const res = [];
    let q = [root];

    while (q.length) {
        const qNext = [];

        for (const node of q) {
            if (node.left) {
                qNext.push(node.left);

                if (del.has(node.left.val)) {
                    node.left = null;
                }
            }

            if (node.right) {
                qNext.push(node.right);

                if (del.has(node.right.val)) {
                    node.right = null;
                }
            }

            if (del.has(node.val)) {
                if (node.left) res.push(node.left);
                if (node.right) res.push(node.right);
            }
        }

        q = qNext;
    }

    if (!del.has(root.val)) res.push(root);

    return res;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出二叉树的根节点&nbsp;<code>root</code>，树上每个节点都有一个不同的值。</p>

<p>如果节点值在&nbsp;<code>to_delete</code>&nbsp;中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。</p>

<p>返回森林中的每棵树。你可以按任意顺序组织答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1110.Delete%20Nodes%20And%20Return%20Forest/images/screen-shot-2019-07-01-at-53836-pm.png" style="height: 150px; width: 237px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6,7], to_delete = [3,5]
<strong>输出：</strong>[[1,2,null,4],[6],[7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2,4,null,3], to_delete = [3]
<strong>输出：</strong>[[1,2,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数最大为&nbsp;<code>1000</code>。</li>
	<li>每个节点都有一个介于&nbsp;<code>1</code> 到&nbsp;<code>1000</code>&nbsp;之间的值，且各不相同。</li>
	<li><code>to_delete.length &lt;= 1000</code></li>
	<li><code>to_delete</code> 包含一些从&nbsp;<code>1</code> 到&nbsp;<code>1000</code>、各不相同的值。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先用哈希表或者一个长度为 $1001$ 的数组 $s$ 记录所有需要删除的节点。

接下来，设计一个函数 $dfs(root)$，它会返回以 $root$ 为根的子树中，删除所有需要删除的节点后的树的根节点。函数 $dfs(root)$ 的执行逻辑如下：

-   如果 $root$ 为空，那么我们返回空；
-   否则，我们递归执行 $dfs(root.left)$ 和 $dfs(root.right)$，并将返回值分别赋给 $root.left$ 和 $root.right$。如果 $root$ 不需要被删除，那么我们返回 $root$；如果 $root$ 需要被删除，那么我们分别判断 $root.left$ 和 $root.right$ 是否为空，如果它们不为空，那么我们将它们加入答案数组中；最后返回空。

在主函数中，我们调用 $dfs(root)$，如果结果不为空，说明根节点不需要被删除，我们再将根节点加入答案数组中。最后返回答案数组即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        def dfs(root: Optional[TreeNode]) -> Optional[TreeNode]:
            if root is None:
                return None
            root.left, root.right = dfs(root.left), dfs(root.right)
            if root.val not in s:
                return root
            if root.left:
                ans.append(root.left)
            if root.right:
                ans.append(root.right)
            return None

        s = set(to_delete)
        ans = []
        if dfs(root):
            ans.append(root)
        return ans
```

#### Java

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
    private boolean[] s = new boolean[1001];
    private List<TreeNode> ans = new ArrayList<>();

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        for (int x : to_delete) {
            s[x] = true;
        }
        if (dfs(root) != null) {
            ans.add(root);
        }
        return ans;
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null) {
            return null;
        }
        root.left = dfs(root.left);
        root.right = dfs(root.right);
        if (!s[root.val]) {
            return root;
        }
        if (root.left != null) {
            ans.add(root.left);
        }
        if (root.right != null) {
            ans.add(root.right);
        }
        return null;
    }
}
```

#### C++

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        bool s[1001];
        memset(s, 0, sizeof(s));
        for (int x : to_delete) {
            s[x] = true;
        }
        vector<TreeNode*> ans;
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) -> TreeNode* {
            if (!root) {
                return nullptr;
            }
            root->left = dfs(root->left);
            root->right = dfs(root->right);
            if (!s[root->val]) {
                return root;
            }
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return nullptr;
        };
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, to_delete []int) (ans []*TreeNode) {
	s := make([]bool, 1001)
	for _, x := range to_delete {
		s[x] = true
	}
	var dfs func(*TreeNode) *TreeNode
	dfs = func(root *TreeNode) *TreeNode {
		if root == nil {
			return nil
		}
		root.Left = dfs(root.Left)
		root.Right = dfs(root.Right)
		if !s[root.Val] {
			return root
		}
		if root.Left != nil {
			ans = append(ans, root.Left)
		}
		if root.Right != nil {
			ans = append(ans, root.Right)
		}
		return nil
	}
	if dfs(root) != nil {
		ans = append(ans, root)
	}
	return
}
```

#### TypeScript

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

function delNodes(root: TreeNode | null, to_delete: number[]): Array<TreeNode | null> {
    const s: boolean[] = Array(1001).fill(false);
    for (const x of to_delete) {
        s[x] = true;
    }
    const ans: Array<TreeNode | null> = [];
    const dfs = (root: TreeNode | null): TreeNode | null => {
        if (!root) {
            return null;
        }
        root.left = dfs(root.left);
        root.right = dfs(root.right);
        if (!s[root.val]) {
            return root;
        }
        if (root.left) {
            ans.push(root.left);
        }
        if (root.right) {
            ans.push(root.right);
        }
        return null;
    };
    if (dfs(root)) {
        ans.push(root);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function (root, to_delete) {
    const s = Array(1001).fill(false);
    for (const x of to_delete) {
        s[x] = true;
    }
    const ans = [];
    const dfs = root => {
        if (!root) {
            return null;
        }
        root.left = dfs(root.left);
        root.right = dfs(root.right);
        if (!s[root.val]) {
            return root;
        }
        if (root.left) {
            ans.push(root.left);
        }
        if (root.right) {
            ans.push(root.right);
        }
        return null;
    };
    if (dfs(root)) {
        ans.push(root);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

<!-- tabs:start -->

#### TypeScript

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
export function delNodes(root: T, to_delete: number[]): Array<T> {
    if (!root) return [];

    const del = new Set(to_delete);
    const res: T[] = [];
    let q: TreeNode[] = [root];

    while (q.length) {
        const qNext: TreeNode[] = [];

        for (const node of q) {
            if (node.left) {
                qNext.push(node.left);

                if (del.has(node.left.val)) {
                    node.left = null;
                }
            }

            if (node.right) {
                qNext.push(node.right);

                if (del.has(node.right.val)) {
                    node.right = null;
                }
            }

            if (del.has(node.val)) {
                if (node.left) res.push(node.left);
                if (node.right) res.push(node.right);
            }
        }

        q = qNext;
    }

    if (!del.has(root.val)) res.push(root);

    return res;
}

type T = TreeNode | null;
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function (root, to_delete) {
    if (!root) return [];

    const del = new Set(to_delete);
    const res = [];
    let q = [root];

    while (q.length) {
        const qNext = [];

        for (const node of q) {
            if (node.left) {
                qNext.push(node.left);

                if (del.has(node.left.val)) {
                    node.left = null;
                }
            }

            if (node.right) {
                qNext.push(node.right);

                if (del.has(node.right.val)) {
                    node.right = null;
                }
            }

            if (del.has(node.val)) {
                if (node.left) res.push(node.left);
                if (node.right) res.push(node.right);
            }
        }

        q = qNext;
    }

    if (!del.has(root.val)) res.push(root);

    return res;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1111. 有效括号的嵌套深度](https://leetcode.cn/problems/maximum-nesting-depth-of-two-valid-parentheses-strings){#1111}

{{< tabs "1111" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = [0] * len(seq)
        x = 0
        for i, c in enumerate(seq):
            if c == "(":
                ans[i] = x & 1
                x += 1
            else:
                x -= 1
                ans[i] = x & 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] ans = new int[n];
        for (int i = 0, x = 0; i < n; ++i) {
            if (seq.charAt(i) == '(') {
                ans[i] = x++ & 1;
            } else {
                ans[i] = --x & 1;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        for (int i = 0, x = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ans[i] = x++ & 1;
            } else {
                ans[i] = --x & 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDepthAfterSplit(seq string) []int {
	n := len(seq)
	ans := make([]int, n)
	for i, x := 0, 0; i < n; i++ {
		if seq[i] == '(' {
			ans[i] = x & 1
			x++
		} else {
			x--
			ans[i] = x & 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDepthAfterSplit(seq: string): number[] {
    const n = seq.length;
    const ans: number[] = new Array(n);
    for (let i = 0, x = 0; i < n; ++i) {
        if (seq[i] === '(') {
            ans[i] = x++ & 1;
        } else {
            ans[i] = --x & 1;
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>有效括号字符串 </strong>定义：对于每个左括号，都能找到与之对应的右括号，反之亦然。详情参见题末「<strong>有效括号字符串</strong>」部分。</p>

<p><strong>嵌套深度</strong> <code>depth</code> 定义：即有效括号字符串嵌套的层数，<code>depth(A)</code> 表示有效括号字符串 <code>A</code> 的嵌套深度。详情参见题末「<strong>嵌套深度</strong>」部分。</p>

<p>有效括号字符串类型与对应的嵌套深度计算方法如下图所示：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1111.Maximum%20Nesting%20Depth%20of%20Two%20Valid%20Parentheses%20Strings/images/1111.png" style="height: 152px; width: 600px;"></p>

<p>&nbsp;</p>

<p>给你一个「有效括号字符串」 <code>seq</code>，请你将其分成两个不相交的有效括号字符串，<code>A</code> 和&nbsp;<code>B</code>，并使这两个字符串的深度最小。</p>

<ul>
	<li>不相交：每个 <code>seq[i]</code> 只能分给 <code>A</code> 和 <code>B</code> 二者中的一个，不能既属于 <code>A</code> 也属于 <code>B</code> 。</li>
	<li><code>A</code> 或 <code>B</code> 中的元素在原字符串中可以不连续。</li>
	<li><code>A.length + B.length = seq.length</code></li>
	<li>深度最小：<code>max(depth(A), depth(B))</code>&nbsp;的可能取值最小。&nbsp;</li>
</ul>

<p>划分方案用一个长度为 <code>seq.length</code> 的答案数组 <code>answer</code> 表示，编码规则如下：</p>

<ul>
	<li><code>answer[i] = 0</code>，<code>seq[i]</code> 分给 <code>A</code> 。</li>
	<li><code>answer[i] = 1</code>，<code>seq[i]</code> 分给 <code>B</code> 。</li>
</ul>

<p>如果存在多个满足要求的答案，只需返回其中任意 <strong>一个 </strong>即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>seq = &quot;(()())&quot;
<strong>输出：</strong>[0,1,1,1,1,0]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>seq = &quot;()(())()&quot;
<strong>输出：</strong>[0,0,0,1,1,0,1,1]
<strong>解释：</strong>本示例答案不唯一。
按此输出 A = &quot;()()&quot;, B = &quot;()()&quot;, max(depth(A), depth(B)) = 1，它们的深度最小。
像 [1,1,1,0,0,1,1,1]，也是正确结果，其中 A = &quot;()()()&quot;, B = &quot;()&quot;, max(depth(A), depth(B)) = 1 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;&nbsp;seq.size &lt;= 10000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>有效括号字符串：</strong></p>

<pre>仅由&nbsp;<code>&quot;(&quot;</code> 和&nbsp;<code>&quot;)&quot;</code>&nbsp;构成的字符串，对于每个左括号，都能找到与之对应的右括号，反之亦然。
下述几种情况同样属于有效括号字符串：

  1. 空字符串
  2. 连接，可以记作&nbsp;<code>AB</code>（<code>A</code> 与 <code>B</code> 连接），其中&nbsp;<code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;都是有效括号字符串
  3. 嵌套，可以记作&nbsp;<code>(A)</code>，其中&nbsp;<code>A</code>&nbsp;是有效括号字符串
</pre>

<p><strong>嵌套深度：</strong></p>

<pre>类似地，我们可以定义任意有效括号字符串 <code>s</code> 的 <strong>嵌套深度</strong>&nbsp;<code>depth(S)</code>：

  1.<code> s</code> 为空时，<code>depth(&quot;&quot;) = 0</code>
<code>  2. s</code> 为 <code>A</code> 与 <code>B</code> 连接时，<code>depth(A + B) = max(depth(A), depth(B))</code>，其中&nbsp;<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是有效括号字符串
<code>  3. s</code> 为嵌套情况，<code>depth(&quot;(&quot; + A + &quot;)&quot;) = 1 + depth(A)</code>，其中 <code>A</code> 是有效括号字符串

例如：<code>&quot;&quot;</code>，<code>&quot;()()&quot;</code>，和&nbsp;<code>&quot;()(()())&quot;</code>&nbsp;都是有效括号字符串，嵌套深度分别为 0，1，2，而&nbsp;<code>&quot;)(&quot;</code> 和&nbsp;<code>&quot;(()&quot;</code>&nbsp;都不是有效括号字符串。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用一个变量 $x$ 维护当前括号的平衡度，也就是左括号的数量减去右括号的数量。

遍历字符串 $seq$，更新 $x$ 的值。如果 $x$ 为奇数，我们将当前的左括号分给 $A$，否则分给 $B$。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $seq$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = [0] * len(seq)
        x = 0
        for i, c in enumerate(seq):
            if c == "(":
                ans[i] = x & 1
                x += 1
            else:
                x -= 1
                ans[i] = x & 1
        return ans
```

#### Java

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] ans = new int[n];
        for (int i = 0, x = 0; i < n; ++i) {
            if (seq.charAt(i) == '(') {
                ans[i] = x++ & 1;
            } else {
                ans[i] = --x & 1;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        for (int i = 0, x = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ans[i] = x++ & 1;
            } else {
                ans[i] = --x & 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxDepthAfterSplit(seq string) []int {
	n := len(seq)
	ans := make([]int, n)
	for i, x := 0, 0; i < n; i++ {
		if seq[i] == '(' {
			ans[i] = x & 1
			x++
		} else {
			x--
			ans[i] = x & 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxDepthAfterSplit(seq: string): number[] {
    const n = seq.length;
    const ans: number[] = new Array(n);
    for (let i = 0, x = 0; i < n; ++i) {
        if (seq[i] === '(') {
            ans[i] = x++ & 1;
        } else {
            ans[i] = --x & 1;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1112. 每位学生的最高成绩 🔒](https://leetcode.cn/problems/highest-grade-for-each-student){#1112}

{{< tabs "1112" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT student_id, MIN(course_id) AS course_id, grade
FROM Enrollments
WHERE
    (student_id, grade) IN (
        SELECT student_id, MAX(grade) AS grade
        FROM Enrollments
        GROUP BY 1
    )
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Enrollments</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| course_id     | int     |
| grade         | int     |
+---------------+---------+
(student_id, course_id) 是该表的主键（具有唯一值的列的组合）。
grade 不会为 NULL。</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出每位学生获得的最高成绩和它所对应的科目，若科目成绩并列，取&nbsp;<code>course_id</code>&nbsp;最小的一门。查询结果需按&nbsp;<code>student_id</code>&nbsp;增序进行排序。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Enrollments 表：
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 2          | 2         | 95    |
| 2          | 3         | 95    |
| 1          | 1         | 90    |
| 1          | 2         | 99    |
| 3          | 1         | 80    |
| 3          | 2         | 75    |
| 3          | 3         | 82    |
+------------+-----------+-------+
<strong>输出：</strong>
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 1          | 2         | 99    |
| 2          | 2         | 95    |
| 3          | 3         | 82    |
+------------+-----------+-------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：RANK() OVER() 窗口函数

我们可以使用 `RANK() OVER()` 窗口函数，按照每个学生的成绩降序排列，如果成绩相同，按照课程号升序排列，然后取每个学生排名为 $1$ 的记录。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY student_id
                ORDER BY grade DESC, course_id
            ) AS rk
        FROM Enrollments
    )
SELECT student_id, course_id, grade
FROM T
WHERE rk = 1
ORDER BY student_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：子查询

我们可以先查询每个学生的最高成绩，然后再查询每个学生的最高成绩对应的最小课程号。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT student_id, MIN(course_id) AS course_id, grade
FROM Enrollments
WHERE
    (student_id, grade) IN (
        SELECT student_id, MAX(grade) AS grade
        FROM Enrollments
        GROUP BY 1
    )
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1113. 报告的记录 🔒](https://leetcode.cn/problems/reported-posts){#1113}

{{< tabs "1113" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT extra AS report_reason, COUNT(DISTINCT post_id) AS report_count
FROM Actions
WHERE action_date = '2019-07-04' AND action = 'report'
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>动作表：<code>Actions</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| post_id       | int     |
| action_date   | date    | 
| action        | enum    |
| extra         | varchar |
+---------------+---------+
此表可能会有重复的行。
action 字段是 ENUM 类型的，包含:('view', 'like', 'reaction', 'comment', <em><strong>'</strong></em>report<em><strong>'</strong></em>, 'share')
extra 包含关于 action 的可选信息，例如举报的原因或反馈的类型。
当 action 为 'report' 时 extra 不会为 NULL。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，针对每个举报原因统计昨天的举报帖子数量。假设今天是&nbsp;<code>2019-07-05</code>&nbsp;。</p>

<p>返回结果表 <strong>无顺序要求 </strong>。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Actions table:
+---------+---------+-------------+--------+--------+
| user_id | post_id | action_date | action | extra  |
+---------+---------+-------------+--------+--------+
| 1       | 1       | 2019-07-01  | view   | null   |
| 1       | 1       | 2019-07-01  | like   | null   |
| 1       | 1       | 2019-07-01  | share  | null   |
| 2       | 4       | 2019-07-04  | view   | null   |
| 2       | 4       | 2019-07-04  | report | spam   |
| 3       | 4       | 2019-07-04  | view   | null   |
| 3       | 4       | 2019-07-04  | report | spam   |
| 4       | 3       | 2019-07-02  | view   | null   |
| 4       | 3       | 2019-07-02  | report | spam   |
| 5       | 2       | 2019-07-04  | view   | null   |
| 5       | 2       | 2019-07-04  | report | racism |
| 5       | 5       | 2019-07-04  | view   | null   |
| 5       | 5       | 2019-07-04  | report | racism |
+---------+---------+-------------+--------+--------+
<strong>输出：</strong>
+---------------+--------------+
| report_reason | report_count |
+---------------+--------------+
| spam          | 1            |
| racism        | 2            |
+---------------+--------------+ 
<strong>解释：</strong>注意，我们只关心举报帖数量非零的举报原因。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT extra AS report_reason, COUNT(DISTINCT post_id) AS report_count
FROM Actions
WHERE action_date = '2019-07-04' AND action = 'report'
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1114. 按序打印](https://leetcode.cn/problems/print-in-order){#1114}

{{< tabs "1114" >}}

{{% tab "python" %}}
```python
from threading import Semaphore


class Foo:
    def __init__(self):
        self.a = Semaphore(1)
        self.b = Semaphore(0)
        self.c = Semaphore(0)

    def first(self, printFirst: 'Callable[[], None]') -> None:
        self.a.acquire()
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.b.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.b.acquire()
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.c.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.c.acquire()
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        self.a.release()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Foo {
    private Semaphore a = new Semaphore(1);
    private Semaphore b = new Semaphore(0);
    private Semaphore c = new Semaphore(0);

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        a.acquire(1);
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        b.release(1);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        b.acquire(1);
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        c.release(1);
    }

    public void third(Runnable printThird) throws InterruptedException {
        c.acquire(1);
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        a.release(1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <semaphore.h>

class Foo {
private:
    sem_t a, b, c;

public:
    Foo() {
        sem_init(&a, 0, 1);
        sem_init(&b, 0, 0);
        sem_init(&c, 0, 0);
    }

    void first(function<void()> printFirst) {
        sem_wait(&a);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&b);
    }

    void second(function<void()> printSecond) {
        sem_wait(&b);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&c);
    }

    void third(function<void()> printThird) {
        sem_wait(&c);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        sem_post(&a);
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个类：</p>

<pre>
public class Foo {
&nbsp; public void first() { print("first"); }
&nbsp; public void second() { print("second"); }
&nbsp; public void third() { print("third"); }
}</pre>

<p>三个不同的线程 A、B、C 将会共用一个&nbsp;<code>Foo</code>&nbsp;实例。</p>

<ul>
	<li>线程 A 将会调用 <code>first()</code> 方法</li>
	<li>线程 B 将会调用&nbsp;<code>second()</code> 方法</li>
	<li>线程 C 将会调用 <code>third()</code> 方法</li>
</ul>

<p>请设计修改程序，以确保 <code>second()</code> 方法在 <code>first()</code> 方法之后被执行，<code>third()</code> 方法在 <code>second()</code> 方法之后被执行。</p>

<p><strong>提示：</strong></p>

<ul>
	<li>尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。</li>
	<li>你看到的输入格式主要是为了确保测试的全面性。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>"firstsecondthird"
<strong>解释：</strong>
有三个线程会被异步启动。输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。正确的输出是 "firstsecondthird"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2]
<strong>输出：</strong>"firstsecondthird"
<strong>解释：</strong>
输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。正确的输出是 "firstsecondthird"。</pre>

<p>&nbsp;</p>

<ul>
</ul>
<strong>提示：</strong>

<ul>
	<li><code>nums</code> 是 <code>[1, 2, 3]</code> 的一组排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：多线程 + 锁或信号量

我们可以用三个信号量 $a$, $b$, $c$ 来控制三个线程的执行顺序，初始时 $a$ 信号量的计数为 $1$，$b$ 和 $c$ 的计数为 $0$。

线程 $A$ 在执行 `first()` 方法时，首先需要获取 $a$ 信号量，获取成功后执行 `first()` 方法，然后释放 $b$ 信号量，这样线程 $B$ 就可以获取 $b$ 信号量并执行 `second()` 方法。

线程 $B$ 在执行 `second()` 方法时，首先需要获取 $b$ 信号量，获取成功后执行 `second()` 方法，然后释放 $c$ 信号量，这样线程 $C$ 就可以获取 $c$ 信号量并执行 `third()` 方法。

线程 $C$ 在执行 `third()` 方法时，首先需要获取 $c$ 信号量，获取成功后执行 `third()` 方法，然后释放 $a$ 信号量，这样线程 $A$ 就可以获取 $a$ 信号量并执行 `first()` 方法。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Foo:
    def __init__(self):
        self.l2 = threading.Lock()
        self.l3 = threading.Lock()
        self.l2.acquire()
        self.l3.acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.l2.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.l2.acquire()
        printSecond()
        self.l3.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.l3.acquire()
        printThird()
```

#### Java

```java
class Foo {
    private Semaphore a = new Semaphore(1);
    private Semaphore b = new Semaphore(0);
    private Semaphore c = new Semaphore(0);

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        a.acquire(1);
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        b.release(1);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        b.acquire(1);
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        c.release(1);
    }

    public void third(Runnable printThird) throws InterruptedException {
        c.acquire(1);
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        a.release(1);
    }
}
```

#### C++

```cpp
class Foo {
private:
    mutex m2, m3;

public:
    Foo() {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        printThird();
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
from threading import Semaphore


class Foo:
    def __init__(self):
        self.a = Semaphore(1)
        self.b = Semaphore(0)
        self.c = Semaphore(0)

    def first(self, printFirst: 'Callable[[], None]') -> None:
        self.a.acquire()
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.b.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.b.acquire()
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.c.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.c.acquire()
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        self.a.release()
```

#### C++

```cpp
#include <semaphore.h>

class Foo {
private:
    sem_t a, b, c;

public:
    Foo() {
        sem_init(&a, 0, 1);
        sem_init(&b, 0, 0);
        sem_init(&c, 0, 0);
    }

    void first(function<void()> printFirst) {
        sem_wait(&a);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&b);
    }

    void second(function<void()> printSecond) {
        sem_wait(&b);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&c);
    }

    void third(function<void()> printThird) {
        sem_wait(&c);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        sem_post(&a);
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1115. 交替打印 FooBar](https://leetcode.cn/problems/print-foobar-alternately){#1115}

{{< tabs "1115" >}}

{{% tab "python" %}}
```python
from threading import Semaphore


class FooBar:
    def __init__(self, n):
        self.n = n
        self.f = Semaphore(1)
        self.b = Semaphore(0)

    def foo(self, printFoo: "Callable[[], None]") -> None:
        for _ in range(self.n):
            self.f.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.b.release()

    def bar(self, printBar: "Callable[[], None]") -> None:
        for _ in range(self.n):
            self.b.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.f.release()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FooBar {
    private int n;
    private Semaphore f = new Semaphore(1);
    private Semaphore b = new Semaphore(0);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            f.acquire(1);
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            b.release(1);
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            b.acquire(1);
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            f.release(1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t f, b;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&f, 0, 1);
        sem_init(&b, 0, 0);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&f);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&b);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&b);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&f);
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个类：</p>

<pre>
class FooBar {
  public void foo() {
&nbsp; &nbsp; for (int i = 0; i &lt; n; i++) {
&nbsp; &nbsp; &nbsp; print("foo");
&nbsp;   }
  }

  public void bar() {
&nbsp; &nbsp; for (int i = 0; i &lt; n; i++) {
&nbsp; &nbsp; &nbsp; print("bar");
&nbsp; &nbsp; }
  }
}
</pre>

<p>两个不同的线程将会共用一个 <code>FooBar</code>&nbsp;实例：</p>

<ul>
	<li>线程 A 将会调用&nbsp;<code>foo()</code>&nbsp;方法，而</li>
	<li>线程 B 将会调用&nbsp;<code>bar()</code>&nbsp;方法</li>
</ul>

<p>请设计修改程序，以确保 <code>"foobar"</code> 被输出 <code>n</code> 次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>"foobar"
<strong>解释：</strong>这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>"foobarfoobar"
<strong>解释：</strong>"foobar" 将被输出两次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：多线程 + 信号量

我们用两个信号量 $f$ 和 $b$ 来控制两个线程的执行顺序，其中 $f$ 初始值为 $1$，而 $b$ 初始值为 $0$，表示线程 $A$ 先执行。

当线程 $A$ 执行时，首先会执行 $f$ 的 $acquire$ 操作，此时 $f$ 的值变为 $0$，线程 $A$ 获得了 $f$ 的使用权，可以执行 $foo$ 函数，然后执行 $b$ 的 $release$ 操作，此时 $b$ 的值变为 $1$，线程 $B$ 获得了 $b$ 的使用权，可以执行 $bar$ 函数。

当线程 $B$ 执行时，首先会执行 $b$ 的 $acquire$ 操作，此时 $b$ 的值变为 $0$，线程 $B$ 获得了 $b$ 的使用权，可以执行 $bar$ 函数，然后执行 $f$ 的 $release$ 操作，此时 $f$ 的值变为 $1$，线程 $A$ 获得了 $f$ 的使用权，可以执行 $foo$ 函数。

因此，我们只需要循环 $n$ 次，每次执行 $foo$ 和 $bar$ 函数时，先执行 $acquire$ 操作，再执行 $release$ 操作即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
from threading import Semaphore


class FooBar:
    def __init__(self, n):
        self.n = n
        self.f = Semaphore(1)
        self.b = Semaphore(0)

    def foo(self, printFoo: "Callable[[], None]") -> None:
        for _ in range(self.n):
            self.f.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.b.release()

    def bar(self, printBar: "Callable[[], None]") -> None:
        for _ in range(self.n):
            self.b.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.f.release()
```

#### Java

```java
class FooBar {
    private int n;
    private Semaphore f = new Semaphore(1);
    private Semaphore b = new Semaphore(0);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            f.acquire(1);
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            b.release(1);
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            b.acquire(1);
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            f.release(1);
        }
    }
}
```

#### C++

```cpp
#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t f, b;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&f, 0, 1);
        sem_init(&b, 0, 0);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&f);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&b);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&b);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&f);
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1116. 打印零与奇偶数](https://leetcode.cn/problems/print-zero-even-odd){#1116}

{{< tabs "1116" >}}

{{% tab "python" %}}
```python
from threading import Semaphore


class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.z = Semaphore(1)
        self.e = Semaphore(0)
        self.o = Semaphore(0)

    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.z.acquire()
            printNumber(0)
            if i % 2 == 0:
                self.o.release()
            else:
                self.e.release()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n + 1, 2):
            self.e.acquire()
            printNumber(i)
            self.z.release()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1, 2):
            self.o.acquire()
            printNumber(i)
            self.z.release()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class ZeroEvenOdd {
    private int n;
    private Semaphore z = new Semaphore(1);
    private Semaphore e = new Semaphore(0);
    private Semaphore o = new Semaphore(0);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; ++i) {
            z.acquire(1);
            printNumber.accept(0);
            if (i % 2 == 0) {
                o.release(1);
            } else {
                e.release(1);
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            e.acquire(1);
            printNumber.accept(i);
            z.release(1);
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            o.acquire(1);
            printNumber.accept(i);
            z.release(1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t z, e, o;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&z, 0, 1);
        sem_init(&e, 0, 0);
        sem_init(&o, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            sem_wait(&z);
            printNumber(0);
            if (i % 2 == 0) {
                sem_post(&o);
            } else {
                sem_post(&e);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&e);
            printNumber(i);
            sem_post(&z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&o);
            printNumber(i);
            sem_post(&z);
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有函数 <code>printNumber</code> 可以用一个整数参数调用，并输出该整数到控制台。</p>

<ul>
	<li>例如，调用 <code>printNumber(7)</code> 将会输出 <code>7</code> 到控制台。</li>
</ul>

<p>给你类 <code>ZeroEvenOdd</code> 的一个实例，该类中有三个函数：<code>zero</code>、<code>even</code> 和 <code>odd</code> 。<code>ZeroEvenOdd</code> 的相同实例将会传递给三个不同线程：</p>

<ul>
	<li><strong>线程 A：</strong>调用 <code>zero()</code> ，只输出 <code>0</code></li>
	<li><strong>线程 B：</strong>调用 <code>even()</code> ，只输出偶数</li>
	<li><strong>线程 C：</strong>调用 <code>odd()</code> ，只输出奇数</li>
</ul>

<p>修改给出的类，以输出序列 <code>"010203040506..."</code> ，其中序列的长度必须为 <code>2n</code> 。</p>

<p>实现 <code>ZeroEvenOdd</code> 类：</p>

<ul>
	<li><code>ZeroEvenOdd(int n)</code> 用数字 <code>n</code> 初始化对象，表示需要输出的数。</li>
	<li><code>void zero(printNumber)</code> 调用 <code>printNumber</code> 以输出一个 0 。</li>
	<li><code>void even(printNumber)</code> 调用<code>printNumber</code> 以输出偶数。</li>
	<li><code>void odd(printNumber)</code> 调用 <code>printNumber</code> 以输出奇数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>"0102"
<strong>解释：</strong>三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>"0102030405"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：多线程 + 信号量

我们用三个信号量 $z$, $e$, $o$ 来控制三个线程的执行顺序，其中 $z$ 的初始值为 $1$，$e$ 和 $o$ 的初始值为 $0$。

-   信号量 $x$ 控制 `zero` 函数的执行，当 $z$ 信号量的值为 $1$ 时，`zero` 函数可以执行，执行完毕后将 $z$ 信号量的值设为 $0$，并将 $e$ 信号量的值设为 $1$ 或 $o$ 信号量的值设为 $1$，具体取决于下一次需要执行的是 `even` 函数还是 `odd` 函数。
-   信号量 $e$ 控制 `even` 函数的执行，当 $e$ 信号量的值为 $1$ 时，`even` 函数可以执行，执行完毕后将 $z$ 信号量的值设为 $1$，并将 $e$ 信号量的值设为 $0$。
-   信号量 $o$ 控制 `odd` 函数的执行，当 $o$ 信号量的值为 $1$ 时，`odd` 函数可以执行，执行完毕后将 $z$ 信号量的值设为 $1$，并将 $o$ 信号量的值设为 $0$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
from threading import Semaphore


class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.z = Semaphore(1)
        self.e = Semaphore(0)
        self.o = Semaphore(0)

    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.z.acquire()
            printNumber(0)
            if i % 2 == 0:
                self.o.release()
            else:
                self.e.release()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n + 1, 2):
            self.e.acquire()
            printNumber(i)
            self.z.release()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1, 2):
            self.o.acquire()
            printNumber(i)
            self.z.release()
```

#### Java

```java
class ZeroEvenOdd {
    private int n;
    private Semaphore z = new Semaphore(1);
    private Semaphore e = new Semaphore(0);
    private Semaphore o = new Semaphore(0);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; ++i) {
            z.acquire(1);
            printNumber.accept(0);
            if (i % 2 == 0) {
                o.release(1);
            } else {
                e.release(1);
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            e.acquire(1);
            printNumber.accept(i);
            z.release(1);
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            o.acquire(1);
            printNumber.accept(i);
            z.release(1);
        }
    }
}
```

#### C++

```cpp
#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t z, e, o;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&z, 0, 1);
        sem_init(&e, 0, 0);
        sem_init(&o, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            sem_wait(&z);
            printNumber(0);
            if (i % 2 == 0) {
                sem_post(&o);
            } else {
                sem_post(&e);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&e);
            printNumber(i);
            sem_post(&z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&o);
            printNumber(i);
            sem_post(&z);
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1117. H2O 生成](https://leetcode.cn/problems/building-h2o){#1117}

{{< tabs "1117" >}}

{{% tab "python" %}}
```python
from threading import Semaphore


class H2O:
    def __init__(self):
        self.h = Semaphore(2)
        self.o = Semaphore(0)

    def hydrogen(self, releaseHydrogen: "Callable[[], None]") -> None:
        self.h.acquire()
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        if self.h._value == 0:
            self.o.release()

    def oxygen(self, releaseOxygen: "Callable[[], None]") -> None:
        self.o.acquire()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        self.h.release(2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class H2O {
    private Semaphore h = new Semaphore(2);
    private Semaphore o = new Semaphore(0);

    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        h.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        o.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        releaseOxygen.run();
        h.release(2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <semaphore.h>

class H2O {
private:
    sem_t h, o;
    int st;

public:
    H2O() {
        sem_init(&h, 0, 2);
        sem_init(&o, 0, 0);
        st = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++st;
        if (st == 2) {
            sem_post(&o);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        st = 0;
        sem_post(&h);
        sem_post(&h);
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现在有两种线程，氧 <code>oxygen</code> 和氢 <code>hydrogen</code>，你的目标是组织这两种线程来产生水分子。</p>

<p>存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。</p>

<p>氢和氧线程会被分别给予 <code>releaseHydrogen</code> 和 <code>releaseOxygen</code> 方法来允许它们突破屏障。</p>

<p>这些线程应该三三成组突破屏障并能立即组合产生一个水分子。</p>

<p>你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。</p>

<p>换句话说:</p>

<ul>
	<li>如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。</li>
	<li>如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。</li>
</ul>

<p>书写满足这些限制条件的氢、氧线程同步代码。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>water = "HOH"
<strong>输出: </strong>"HHO"
<strong>解释:</strong> "HOH" 和 "OHH" 依然都是有效解。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>water = "OOHHHH"
<strong>输出: </strong>"HHOHHO"
<strong>解释:</strong> "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" 和 "OHHOHH" 依然都是有效解。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 * n == water.length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>water[i] == 'O' or 'H'</code></li>
	<li>输入字符串&nbsp;<code>water</code>&nbsp;中的 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'H'</span></span></font></font>&nbsp;总数将会是 <code>2 * n</code> 。</li>
	<li>输入字符串&nbsp;<code>water</code>&nbsp;中的 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'O'</span></span></font></font>&nbsp;总数将会是 <code>n</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
from threading import Semaphore


class H2O:
    def __init__(self):
        self.h = Semaphore(2)
        self.o = Semaphore(0)

    def hydrogen(self, releaseHydrogen: "Callable[[], None]") -> None:
        self.h.acquire()
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        if self.h._value == 0:
            self.o.release()

    def oxygen(self, releaseOxygen: "Callable[[], None]") -> None:
        self.o.acquire()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        self.h.release(2)
```

#### Java

```java
class H2O {
    private Semaphore h = new Semaphore(2);
    private Semaphore o = new Semaphore(0);

    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        h.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        o.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        releaseOxygen.run();
        h.release(2);
    }
}
```

#### C++

```cpp
#include <semaphore.h>

class H2O {
private:
    sem_t h, o;
    int st;

public:
    H2O() {
        sem_init(&h, 0, 2);
        sem_init(&o, 0, 0);
        st = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++st;
        if (st == 2) {
            sem_post(&o);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        st = 0;
        sem_post(&h);
        sem_post(&h);
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1118. 一月有多少天 🔒](https://leetcode.cn/problems/number-of-days-in-a-month){#1118}

{{< tabs "1118" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfDays(self, year: int, month: int) -> int:
        leap = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
        days = [0, 31, 29 if leap else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return days[month]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfDays(int year, int month) {
        boolean leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int[] days = new int[] {0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfDays(int year, int month) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        vector<int> days = {0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfDays(year int, month int) int {
	leap := (year%4 == 0 && year%100 != 0) || (year%400 == 0)
	x := 28
	if leap {
		x = 29
	}
	days := []int{0, 31, x, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	return days[month]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfDays(year: number, month: number): number {
    const leap = (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
    const days = [0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days[month];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>指定年份&nbsp;<code>year</code> 和月份&nbsp;<code>month</code>，返回 <em>该月天数&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>year = 1992, month = 7
<strong>输出：</strong>31
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>year = 2000, month = 2
<strong>输出：</strong>29
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>year = 1900, month = 2
<strong>输出：</strong>28
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1583 &lt;= year &lt;= 2100</code></li>
	<li><code>1 &lt;= month &lt;= 12</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：判断闰年

我们可以先判断给定的年份是否为闰年，如果年份能被 $4$ 整除但不能被 $100$ 整除，或者能被 $400$ 整除，那么这一年就是闰年。

闰年的二月有 $29$ 天，平年的二月有 $28$ 天。

我们可以用一个数组 $days$ 存储当前年份每个月的天数，其中 $days[0]=0$，$days[i]$ 表示当前年份第 $i$ 个月的天数。那么答案就是 $days[month]$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfDays(self, year: int, month: int) -> int:
        leap = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
        days = [0, 31, 29 if leap else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return days[month]
```

#### Java

```java
class Solution {
    public int numberOfDays(int year, int month) {
        boolean leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int[] days = new int[] {0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfDays(int year, int month) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        vector<int> days = {0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month];
    }
};
```

#### Go

```go
func numberOfDays(year int, month int) int {
	leap := (year%4 == 0 && year%100 != 0) || (year%400 == 0)
	x := 28
	if leap {
		x = 29
	}
	days := []int{0, 31, x, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	return days[month]
}
```

#### TypeScript

```ts
function numberOfDays(year: number, month: number): number {
    const leap = (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
    const days = [0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days[month];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1119. 删去字符串中的元音 🔒](https://leetcode.cn/problems/remove-vowels-from-a-string){#1119}

{{< tabs "1119" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeVowels(self, s: str) -> str:
        return "".join(c for c in s if c not in "aeiou")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeVowels(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for (char& c : s) {
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
                ans += c;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeVowels(s string) string {
	ans := []rune{}
	for _, c := range s {
		if !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeVowels(s: string): string {
    return s.replace(/[aeiou]/g, '');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>&nbsp;，请你删去其中的所有元音字母&nbsp;<code>'a'</code>，<code>'e'</code>，<code>'i'</code>，<code>'o'</code>，<code>'u'</code>，并返回这个新字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcodeisacommunityforcoders"
<strong>输出：</strong>"ltcdscmmntyfrcdrs"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aeiou"
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= S.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接按照题目要求，遍历字符串，将不是元音字母的字符拼接到结果字符串中即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeVowels(self, s: str) -> str:
        return "".join(c for c in s if c not in "aeiou")
```

#### Java

```java
class Solution {
    public String removeVowels(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for (char& c : s) {
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
                ans += c;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeVowels(s string) string {
	ans := []rune{}
	for _, c := range s {
		if !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function removeVowels(s: string): string {
    return s.replace(/[aeiou]/g, '');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
