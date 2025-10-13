---
title: "0230_二叉搜索树中第 K 小的元素"
date: 2025-10-08T18:35:28+08:00
weight: 4
tags: [二叉搜索树, 二叉树, 位运算, 前缀和, 动态规划, 单调队列, 双指针, 堆（优先队列）, 数学, 数组, 栈, 树, 深度优先搜索, 滑动窗口, 设计, 递归, 链表, 队列]
---

{{< markmap >}}
### [0230_二叉搜索树中第 K 小的元素](#230)
#### [树](#230)
#### [深度优先搜索](#230)
#### [二叉搜索树](#230)
#### [二叉树](#230)
### [0231_2 的幂](#231)
#### [位运算](#231)
#### [递归](#231)
#### [数学](#231)
### [0232_用栈实现队列](#232)
#### [栈](#232)
#### [设计](#232)
#### [队列](#232)
### [0233_数字 1 的个数](#233)
#### [递归](#233)
#### [数学](#233)
#### [动态规划](#233)
### [0234_回文链表](#234)
#### [栈](#234)
#### [递归](#234)
#### [链表](#234)
#### [双指针](#234)
### [0235_二叉搜索树的最近公共祖先](#235)
#### [树](#235)
#### [深度优先搜索](#235)
#### [二叉搜索树](#235)
#### [二叉树](#235)
### [0236_二叉树的最近公共祖先](#236)
#### [树](#236)
#### [深度优先搜索](#236)
#### [二叉树](#236)
### [0237_删除链表中的节点](#237)
#### [链表](#237)
### [0238_除自身以外数组的乘积](#238)
#### [数组](#238)
#### [前缀和](#238)
### [0239_滑动窗口最大值](#239)
#### [队列](#239)
#### [数组](#239)
#### [滑动窗口](#239)
#### [单调队列](#239)
#### [堆（优先队列）](#239)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0230_二叉搜索树中第 K 小的元素
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0231_2 的幂
___
#### 位运算
___
#### 递归
___
#### 数学
---
### 0232_用栈实现队列
___
#### 栈
___
#### 设计
___
#### 队列
---
### 0233_数字 1 的个数
___
#### 递归
___
#### 数学
___
#### 动态规划
---
### 0234_回文链表
___
#### 栈
___
#### 递归
___
#### 链表
___
#### 双指针
---
### 0235_二叉搜索树的最近公共祖先
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0236_二叉树的最近公共祖先
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0237_删除链表中的节点
___
#### 链表
---
### 0238_除自身以外数组的乘积
___
#### 数组
___
#### 前缀和
---
### 0239_滑动窗口最大值
___
#### 队列
___
#### 数组
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 单调队列 |
| 双指针 | 堆（优先队列） | 数学 |
| 数组 | 栈 | 树 |
| 深度优先搜索 | 滑动窗口 | 设计 |
| 递归 | 链表 | 队列 |

# [230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst){#230}

{{< tabs "230" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class BST:
    def __init__(self, root):
        self.cnt = Counter()
        self.root = root
        self.count(root)

    def kthSmallest(self, k):
        node = self.root
        while node:
            if self.cnt[node.left] == k - 1:
                return node.val
            if self.cnt[node.left] < k - 1:
                k -= self.cnt[node.left] + 1
                node = node.right
            else:
                node = node.left
        return 0

    def count(self, root):
        if root is None:
            return 0
        n = 1 + self.count(root.left) + self.count(root.right)
        self.cnt[root] = n
        return n


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        bst = BST(root)
        return bst.kthSmallest(k)
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
    public int kthSmallest(TreeNode root, int k) {
        BST bst = new BST(root);
        return bst.kthSmallest(k);
    }
}

class BST {
    private TreeNode root;
    private Map<TreeNode, Integer> cnt = new HashMap<>();

    public BST(TreeNode root) {
        this.root = root;
        count(root);
    }

    public int kthSmallest(int k) {
        TreeNode node = root;
        while (node != null) {
            int v = node.left == null ? 0 : cnt.get(node.left);
            if (v == k - 1) {
                return node.val;
            }
            if (v < k - 1) {
                node = node.right;
                k -= (v + 1);
            } else {
                node = node.left;
            }
        }
        return 0;
    }

    private int count(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int n = 1 + count(root.left) + count(root.right);
        cnt.put(root, n);
        return n;
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
class BST {
public:
    BST(TreeNode* root)
        : root(root) {
        count(root);
    }

    int kthSmallest(int k) {
        TreeNode* node = root;
        while (node) {
            int v = !node->left ? 0 : cnt[node->left];
            if (v == k - 1) return node->val;
            if (v < k - 1) {
                node = node->right;
                k -= (v + 1);
            } else
                node = node->left;
        }
        return 0;
    }

private:
    TreeNode* root;
    unordered_map<TreeNode*, int> cnt;

    int count(TreeNode* root) {
        if (!root) return 0;
        int n = 1 + count(root->left) + count(root->right);
        cnt[root] = n;
        return n;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        BST bst(root);
        return bst.kthSmallest(k);
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
type BST struct {
	cnt  map[*TreeNode]int
	root *TreeNode
}

func newBST(root *TreeNode) *BST {
	var count func(*TreeNode) int
	cnt := map[*TreeNode]int{}
	count = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		n := 1 + count(root.Left) + count(root.Right)
		cnt[root] = n
		return n
	}
	count(root)
	return &BST{cnt, root}
}

func (bst *BST) kthSmallest(k int) int {
	node := bst.root
	for node != nil {
		v := 0
		if node.Left != nil {
			v = bst.cnt[node.Left]
		}
		if v == k-1 {
			return node.Val
		}
		if v < k-1 {
			k -= (v + 1)
			node = node.Right
		} else {
			node = node.Left
		}
	}
	return 0
}

func kthSmallest(root *TreeNode, k int) int {
	bst := newBST(root)
	return bst.kthSmallest(k)
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

function kthSmallest(root: TreeNode | null, k: number): number {
    const dfs = (root: TreeNode | null) => {
        if (root == null) {
            return -1;
        }
        const { val, left, right } = root;
        const l = dfs(left);
        if (l !== -1) {
            return l;
        }
        k--;
        if (k === 0) {
            return val;
        }
        return dfs(right);
    };
    return dfs(root);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, res: &mut Vec<i32>, k: usize) {
        if let Some(node) = root {
            let mut node = node.borrow_mut();
            Self::dfs(node.left.take(), res, k);
            res.push(node.val);
            if res.len() >= k {
                return;
            }
            Self::dfs(node.right.take(), res, k);
        }
    }
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let k = k as usize;
        let mut res: Vec<i32> = Vec::with_capacity(k);
        Self::dfs(root, &mut res, k);
        res[k - 1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉搜索树的根节点 <code>root</code> ，和一个整数 <code>k</code> ，请你设计一个算法查找其中第&nbsp;<code>k</code><strong>&nbsp;</strong>小的元素（从 1 开始计数）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0230.Kth%20Smallest%20Element%20in%20a%20BST/images/kthtree1.jpg" style="width: 212px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [3,1,4,null,2], k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0230.Kth%20Smallest%20Element%20in%20a%20BST/images/kthtree2.jpg" style="width: 382px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [5,3,6,2,4,null,null,1], k = 3
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数为 <code>n</code> 。</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 <code>k</code> 小的值，你将如何优化算法？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历

由于二叉搜索树的性质，中序遍历一定能得到升序序列，因此可以采用中序遍历找出第 k 小的元素。

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
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stk = []
        while root or stk:
            if root:
                stk.append(root)
                root = root.left
            else:
                root = stk.pop()
                k -= 1
                if k == 0:
                    return root.val
                root = root.right
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
    public int kthSmallest(TreeNode root, int k) {
        Deque<TreeNode> stk = new ArrayDeque<>();
        while (root != null || !stk.isEmpty()) {
            if (root != null) {
                stk.push(root);
                root = root.left;
            } else {
                root = stk.pop();
                if (--k == 0) {
                    return root.val;
                }
                root = root.right;
            }
        }
        return 0;
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (--k == 0) return root->val;
                root = root->right;
            }
        }
        return 0;
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
func kthSmallest(root *TreeNode, k int) int {
	stk := []*TreeNode{}
	for root != nil || len(stk) > 0 {
		if root != nil {
			stk = append(stk, root)
			root = root.Left
		} else {
			root = stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			k--
			if k == 0 {
				return root.Val
			}
			root = root.Right
		}
	}
	return 0
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

function kthSmallest(root: TreeNode | null, k: number): number {
    const dfs = (root: TreeNode | null) => {
        if (root == null) {
            return -1;
        }
        const { val, left, right } = root;
        const l = dfs(left);
        if (l !== -1) {
            return l;
        }
        k--;
        if (k === 0) {
            return val;
        }
        return dfs(right);
    };
    return dfs(root);
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, res: &mut Vec<i32>, k: usize) {
        if let Some(node) = root {
            let mut node = node.borrow_mut();
            Self::dfs(node.left.take(), res, k);
            res.push(node.val);
            if res.len() >= k {
                return;
            }
            Self::dfs(node.right.take(), res, k);
        }
    }
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let k = k as usize;
        let mut res: Vec<i32> = Vec::with_capacity(k);
        Self::dfs(root, &mut res, k);
        res[k - 1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理结点数

预处理每个结点作为根节点的子树的节点数。

这种算法可以用来优化频繁查找第 k 个树、而二叉搜索树本身不被修改的情况。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class BST:
    def __init__(self, root):
        self.cnt = Counter()
        self.root = root
        self.count(root)

    def kthSmallest(self, k):
        node = self.root
        while node:
            if self.cnt[node.left] == k - 1:
                return node.val
            if self.cnt[node.left] < k - 1:
                k -= self.cnt[node.left] + 1
                node = node.right
            else:
                node = node.left
        return 0

    def count(self, root):
        if root is None:
            return 0
        n = 1 + self.count(root.left) + self.count(root.right)
        self.cnt[root] = n
        return n


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        bst = BST(root)
        return bst.kthSmallest(k)
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
    public int kthSmallest(TreeNode root, int k) {
        BST bst = new BST(root);
        return bst.kthSmallest(k);
    }
}

class BST {
    private TreeNode root;
    private Map<TreeNode, Integer> cnt = new HashMap<>();

    public BST(TreeNode root) {
        this.root = root;
        count(root);
    }

    public int kthSmallest(int k) {
        TreeNode node = root;
        while (node != null) {
            int v = node.left == null ? 0 : cnt.get(node.left);
            if (v == k - 1) {
                return node.val;
            }
            if (v < k - 1) {
                node = node.right;
                k -= (v + 1);
            } else {
                node = node.left;
            }
        }
        return 0;
    }

    private int count(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int n = 1 + count(root.left) + count(root.right);
        cnt.put(root, n);
        return n;
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
class BST {
public:
    BST(TreeNode* root)
        : root(root) {
        count(root);
    }

    int kthSmallest(int k) {
        TreeNode* node = root;
        while (node) {
            int v = !node->left ? 0 : cnt[node->left];
            if (v == k - 1) return node->val;
            if (v < k - 1) {
                node = node->right;
                k -= (v + 1);
            } else
                node = node->left;
        }
        return 0;
    }

private:
    TreeNode* root;
    unordered_map<TreeNode*, int> cnt;

    int count(TreeNode* root) {
        if (!root) return 0;
        int n = 1 + count(root->left) + count(root->right);
        cnt[root] = n;
        return n;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        BST bst(root);
        return bst.kthSmallest(k);
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
type BST struct {
	cnt  map[*TreeNode]int
	root *TreeNode
}

func newBST(root *TreeNode) *BST {
	var count func(*TreeNode) int
	cnt := map[*TreeNode]int{}
	count = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		n := 1 + count(root.Left) + count(root.Right)
		cnt[root] = n
		return n
	}
	count(root)
	return &BST{cnt, root}
}

func (bst *BST) kthSmallest(k int) int {
	node := bst.root
	for node != nil {
		v := 0
		if node.Left != nil {
			v = bst.cnt[node.Left]
		}
		if v == k-1 {
			return node.Val
		}
		if v < k-1 {
			k -= (v + 1)
			node = node.Right
		} else {
			node = node.Left
		}
	}
	return 0
}

func kthSmallest(root *TreeNode, k int) int {
	bst := newBST(root)
	return bst.kthSmallest(k)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [231. 2 的幂](https://leetcode.cn/problems/power-of-two){#231}

{{< tabs "231" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n == n & (-n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPowerOfTwo(n int) bool {
	return n > 0 && n == (n&(-n))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPowerOfTwo(n: number): boolean {
    return n > 0 && n === (n & -n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && n == (n & (-n))
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
    return n > 0 && n === (n & -n);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>，请你判断该整数是否是 2 的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>如果存在一个整数 <code>x</code> 使得&nbsp;<code>n == 2<sup>x</sup></code> ，则认为 <code>n</code> 是 2 的幂次方。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>2<sup>0</sup> = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 16
<strong>输出：</strong>true
<strong>解释：</strong>2<sup>4</sup> = 16
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能够不使用循环/递归解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据位运算的性质，执行 $\texttt{n\&(n-1)}$ 可以消去二进制形式的 $n$ 的最后一位 $1$。因此，如果 $n \gt 0$，并且满足 $\texttt{n\&(n-1)}$ 结果为 $0$，则说明 $n$ 是 $2$ 的幂。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0
```

#### Java

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
```

#### Go

```go
func isPowerOfTwo(n int) bool {
	return n > 0 && (n&(n-1)) == 0
}
```

#### TypeScript

```ts
function isPowerOfTwo(n: number): boolean {
    return n > 0 && (n & (n - 1)) === 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && (n & (n - 1)) == 0
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
    return n > 0 && (n & (n - 1)) == 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Lowbit

根据 $\text{lowbit}$ 的定义，我们知道 $\text{lowbit}(x) = x \& (-x)$，可以得到 $n$ 的最后一位 $1$ 表示的十进制数。因此，如果 $n > 0$，并且满足 $\text{lowbit}(n)$ 等于 $n$，则说明 $n$ 是 $2$ 的幂。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n == n & (-n)
```

#### Java

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
};
```

#### Go

```go
func isPowerOfTwo(n int) bool {
	return n > 0 && n == (n&(-n))
}
```

#### TypeScript

```ts
function isPowerOfTwo(n: number): boolean {
    return n > 0 && n === (n & -n);
}
```

#### Rust

```rust
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && n == (n & (-n))
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
    return n > 0 && n === (n & -n);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks){#232}

{{< tabs "232" >}}

{{% tab "python" %}}
```python
class MyQueue:
    def __init__(self):
        self.stk1 = []
        self.stk2 = []

    def push(self, x: int) -> None:
        self.stk1.append(x)

    def pop(self) -> int:
        self.move()
        return self.stk2.pop()

    def peek(self) -> int:
        self.move()
        return self.stk2[-1]

    def empty(self) -> bool:
        return not self.stk1 and not self.stk2

    def move(self):
        if not self.stk2:
            while self.stk1:
                self.stk2.append(self.stk1.pop())


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyQueue {
    private Deque<Integer> stk1 = new ArrayDeque<>();
    private Deque<Integer> stk2 = new ArrayDeque<>();

    public MyQueue() {
    }

    public void push(int x) {
        stk1.push(x);
    }

    public int pop() {
        move();
        return stk2.pop();
    }

    public int peek() {
        move();
        return stk2.peek();
    }

    public boolean empty() {
        return stk1.isEmpty() && stk2.isEmpty();
    }

    private void move() {
        while (stk2.isEmpty()) {
            while (!stk1.isEmpty()) {
                stk2.push(stk1.pop());
            }
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        move();
        int ans = stk2.top();
        stk2.pop();
        return ans;
    }

    int peek() {
        move();
        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }

private:
    stack<int> stk1;
    stack<int> stk2;

    void move() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyQueue struct {
	stk1 []int
	stk2 []int
}

func Constructor() MyQueue {
	return MyQueue{[]int{}, []int{}}
}

func (this *MyQueue) Push(x int) {
	this.stk1 = append(this.stk1, x)
}

func (this *MyQueue) Pop() int {
	this.move()
	ans := this.stk2[len(this.stk2)-1]
	this.stk2 = this.stk2[:len(this.stk2)-1]
	return ans
}

func (this *MyQueue) Peek() int {
	this.move()
	return this.stk2[len(this.stk2)-1]
}

func (this *MyQueue) Empty() bool {
	return len(this.stk1) == 0 && len(this.stk2) == 0
}

func (this *MyQueue) move() {
	if len(this.stk2) == 0 {
		for len(this.stk1) > 0 {
			this.stk2 = append(this.stk2, this.stk1[len(this.stk1)-1])
			this.stk1 = this.stk1[:len(this.stk1)-1]
		}
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyQueue {
    stk1: number[];
    stk2: number[];

    constructor() {
        this.stk1 = [];
        this.stk2 = [];
    }

    push(x: number): void {
        this.stk1.push(x);
    }

    pop(): number {
        this.move();
        return this.stk2.pop();
    }

    peek(): number {
        this.move();
        return this.stk2.at(-1);
    }

    empty(): boolean {
        return !this.stk1.length && !this.stk2.length;
    }

    move(): void {
        if (!this.stk2.length) {
            while (this.stk1.length) {
                this.stk2.push(this.stk1.pop()!);
            }
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

struct MyQueue {
    stk1: Vec<i32>,
    stk2: Vec<i32>,
}

impl MyQueue {
    fn new() -> Self {
        MyQueue {
            stk1: Vec::new(),
            stk2: Vec::new(),
        }
    }

    fn push(&mut self, x: i32) {
        self.stk1.push(x);
    }

    fn pop(&mut self) -> i32 {
        self.move_elements();
        self.stk2.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        self.move_elements();
        *self.stk2.last().unwrap()
    }

    fn empty(&self) -> bool {
        self.stk1.is_empty() && self.stk2.is_empty()
    }

    fn move_elements(&mut self) {
        if self.stk2.is_empty() {
            while let Some(element) = self.stk1.pop() {
                self.stk2.push(element);
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（<code>push</code>、<code>pop</code>、<code>peek</code>、<code>empty</code>）：</p>

<p>实现 <code>MyQueue</code> 类：</p>

<ul>
	<li><code>void push(int x)</code> 将元素 x 推到队列的末尾</li>
	<li><code>int pop()</code> 从队列的开头移除并返回元素</li>
	<li><code>int peek()</code> 返回队列开头的元素</li>
	<li><code>boolean empty()</code> 如果队列为空，返回 <code>true</code> ；否则，返回 <code>false</code></li>
</ul>

<p><strong>说明：</strong></p>

<ul>
	<li>你 <strong>只能</strong> 使用标准的栈操作 —— 也就是只有&nbsp;<code>push to top</code>,&nbsp;<code>peek/pop from top</code>,&nbsp;<code>size</code>, 和&nbsp;<code>is empty</code>&nbsp;操作是合法的。</li>
	<li>你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>输出：</strong>
[null, null, null, 1, 1, false]

<strong>解释：</strong>
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
</pre>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li>最多调用 <code>100</code> 次 <code>push</code>、<code>pop</code>、<code>peek</code> 和 <code>empty</code></li>
	<li>假设所有操作都是有效的 （例如，一个空的队列不会调用 <code>pop</code> 或者 <code>peek</code> 操作）</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你能否实现每个操作均摊时间复杂度为 <code>O(1)</code> 的队列？换句话说，执行 <code>n</code> 个操作的总时间复杂度为 <code>O(n)</code> ，即使其中一个操作可能花费较长时间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双栈

我们使用两个栈，其中栈 `stk1`用于入队，另一个栈 `stk2` 用于出队。

入队时，直接将元素入栈 `stk1`。时间复杂度 $O(1)$。

出队时，先判断栈 `stk2` 是否为空，如果为空，则将栈 `stk1` 中的元素全部出栈并入栈 `stk2`，然后再从栈 `stk2` 中出栈一个元素。如果栈 `stk2` 不为空，则直接从栈 `stk2` 中出栈一个元素。均摊时间复杂度 $O(1)$。

获取队首元素时，先判断栈 `stk2` 是否为空，如果为空，则将栈 `stk1` 中的元素全部出栈并入栈 `stk2`，然后再从栈 `stk2` 中获取栈顶元素。如果栈 `stk2` 不为空，则直接从栈 `stk2` 中获取栈顶元素。均摊时间复杂度 $O(1)$。

判断队列是否为空时，只要判断两个栈是否都为空即可。时间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class MyQueue:
    def __init__(self):
        self.stk1 = []
        self.stk2 = []

    def push(self, x: int) -> None:
        self.stk1.append(x)

    def pop(self) -> int:
        self.move()
        return self.stk2.pop()

    def peek(self) -> int:
        self.move()
        return self.stk2[-1]

    def empty(self) -> bool:
        return not self.stk1 and not self.stk2

    def move(self):
        if not self.stk2:
            while self.stk1:
                self.stk2.append(self.stk1.pop())


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```

#### Java

```java
class MyQueue {
    private Deque<Integer> stk1 = new ArrayDeque<>();
    private Deque<Integer> stk2 = new ArrayDeque<>();

    public MyQueue() {
    }

    public void push(int x) {
        stk1.push(x);
    }

    public int pop() {
        move();
        return stk2.pop();
    }

    public int peek() {
        move();
        return stk2.peek();
    }

    public boolean empty() {
        return stk1.isEmpty() && stk2.isEmpty();
    }

    private void move() {
        while (stk2.isEmpty()) {
            while (!stk1.isEmpty()) {
                stk2.push(stk1.pop());
            }
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```

#### C++

```cpp
class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        move();
        int ans = stk2.top();
        stk2.pop();
        return ans;
    }

    int peek() {
        move();
        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }

private:
    stack<int> stk1;
    stack<int> stk2;

    void move() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

#### Go

```go
type MyQueue struct {
	stk1 []int
	stk2 []int
}

func Constructor() MyQueue {
	return MyQueue{[]int{}, []int{}}
}

func (this *MyQueue) Push(x int) {
	this.stk1 = append(this.stk1, x)
}

func (this *MyQueue) Pop() int {
	this.move()
	ans := this.stk2[len(this.stk2)-1]
	this.stk2 = this.stk2[:len(this.stk2)-1]
	return ans
}

func (this *MyQueue) Peek() int {
	this.move()
	return this.stk2[len(this.stk2)-1]
}

func (this *MyQueue) Empty() bool {
	return len(this.stk1) == 0 && len(this.stk2) == 0
}

func (this *MyQueue) move() {
	if len(this.stk2) == 0 {
		for len(this.stk1) > 0 {
			this.stk2 = append(this.stk2, this.stk1[len(this.stk1)-1])
			this.stk1 = this.stk1[:len(this.stk1)-1]
		}
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
```

#### TypeScript

```ts
class MyQueue {
    stk1: number[];
    stk2: number[];

    constructor() {
        this.stk1 = [];
        this.stk2 = [];
    }

    push(x: number): void {
        this.stk1.push(x);
    }

    pop(): number {
        this.move();
        return this.stk2.pop();
    }

    peek(): number {
        this.move();
        return this.stk2.at(-1);
    }

    empty(): boolean {
        return !this.stk1.length && !this.stk2.length;
    }

    move(): void {
        if (!this.stk2.length) {
            while (this.stk1.length) {
                this.stk2.push(this.stk1.pop()!);
            }
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
```

#### Rust

```rust
use std::collections::VecDeque;

struct MyQueue {
    stk1: Vec<i32>,
    stk2: Vec<i32>,
}

impl MyQueue {
    fn new() -> Self {
        MyQueue {
            stk1: Vec::new(),
            stk2: Vec::new(),
        }
    }

    fn push(&mut self, x: i32) {
        self.stk1.push(x);
    }

    fn pop(&mut self) -> i32 {
        self.move_elements();
        self.stk2.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        self.move_elements();
        *self.stk2.last().unwrap()
    }

    fn empty(&self) -> bool {
        self.stk1.is_empty() && self.stk2.is_empty()
    }

    fn move_elements(&mut self) {
        if self.stk2.is_empty() {
            while let Some(element) = self.stk1.pop() {
                self.stk2.push(element);
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one){#233}

{{< tabs "233" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDigitOne(self, n: int) -> int:
        @cache
        def dfs(i: int, cnt: int, limit: bool) -> int:
            if i >= len(s):
                return cnt
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                ans += dfs(i + 1, cnt + (j == 1), limit and j == up)
            return ans

        s = str(n)
        return dfs(0, 0, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private char[] s;
    private Integer[][] f;

    public int countDigitOne(int n) {
        s = String.valueOf(n).toCharArray();
        m = s.length;
        f = new Integer[m][m];
        return dfs(0, 0, true);
    }

    private int dfs(int i, int cnt, boolean limit) {
        if (i >= m) {
            return cnt;
        }
        if (!limit && f[i][cnt] != null) {
            return f[i][cnt];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            ans += dfs(i + 1, cnt + (j == 1 ? 1 : 0), limit && j == up);
        }
        if (!limit) {
            f[i][cnt] = ans;
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
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][m];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int cnt, bool limit) -> int {
            if (i >= m) {
                return cnt;
            }
            if (!limit && f[i][cnt] != -1) {
                return f[i][cnt];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                ans += dfs(i + 1, cnt + (j == 1), limit && j == up);
            }
            if (!limit) {
                f[i][cnt] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDigitOne(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, cnt int, limit bool) int
	dfs = func(i, cnt int, limit bool) int {
		if i >= m {
			return cnt
		}
		if !limit && f[i][cnt] != -1 {
			return f[i][cnt]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			t := 0
			if j == 1 {
				t = 1
			}
			ans += dfs(i+1, cnt+t, limit && j == up)
		}
		if !limit {
			f[i][cnt] = ans
		}
		return ans
	}
	return dfs(0, 0, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countDigitOne(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[][] = Array.from({ length: m }, () => Array(m).fill(-1));
    const dfs = (i: number, cnt: number, limit: boolean): number => {
        if (i >= m) {
            return cnt;
        }
        if (!limit && f[i][cnt] !== -1) {
            return f[i][cnt];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            ans += dfs(i + 1, cnt + (j === 1 ? 1 : 0), limit && j === up);
        }
        if (!limit) {
            f[i][cnt] = ans;
        }
        return ans;
    };
    return dfs(0, 0, true);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int m;
    private char[] s;
    private int?[,] f;

    public int CountDigitOne(int n) {
        s = n.ToString().ToCharArray();
        m = s.Length;
        f = new int?[m, m];
        return Dfs(0, 0, true);
    }

    private int Dfs(int i, int cnt, bool limit) {
        if (i >= m) {
            return cnt;
        }
        if (!limit && f[i, cnt] != null) {
            return f[i, cnt].Value;
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            ans += Dfs(i + 1, cnt + (j == 1 ? 1 : 0), limit && j == up);
        }
        if (!limit) {
            f[i, cnt] = ans;
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数 <code>n</code>，计算所有小于等于 <code>n</code> 的非负整数中数字 <code>1</code> 出现的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 13
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，数字中出现 $1$ 个数。个数与数的位数以及每一位上的数字有关。我们可以用数位 DP 的思路来解决这道题。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

不过对于本题而言，我们只需要求出区间 $[1,..r]$ 的值即可。

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

我们首先将数字 $n$ 转化为字符串 $s$。然后我们设计一个函数 $\textit{dfs}(i, \textit{cnt}, \textit{limit})$，其中：

-   数字 $i$ 表示当前搜索到的位置，我们从高位开始搜索，即 $i = 0$ 表示最高位。
-   数字 $\textit{cnt}$ 表示当前数字中 $1$ 出现的次数。
-   布尔值 $\textit{limit}$ 表示当前是否受到上界的限制。

函数的执行过程如下：

如果 $i$ 超过了数字 $n$ 的长度，说明搜索结束，直接返回 $cnt$。如果 $\textit{limit}$ 为真，那么 $up$ 为当前数字的第 $i$ 位，否则 $up = 9$。接下来，我们遍历 $j$ 从 $0$ 到 $up$，对于每一个 $j$：

-   如果 $j$ 等于 $1$，我们将 $cnt$ 加一。
-   递归调用 $\textit{dfs}(i + 1, \textit{cnt}, \textit{limit} \land j = up)$。

答案为 $\textit{dfs}(0, 0, \text{True})$。

时间复杂度 $O(m^2 \times D)$，空间复杂度 $O(m^2)$。其中 $m$ 为数字 $n$ 的长度，而 $D = 10$。

相似题目：

-   [357. 统计各位数字都不同的数字个数](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0357.Count%20Numbers%20with%20Unique%20Digits/README.md)
-   [600. 不含连续 1 的非负整数](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0600.Non-negative%20Integers%20without%20Consecutive%20Ones/README.md)
-   [788. 旋转数字](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0788.Rotated%20Digits/README.md)
-   [902. 最大为 N 的数字组合](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0902.Numbers%20At%20Most%20N%20Given%20Digit%20Set/README.md)
-   [1012. 至少有 1 位重复的数字](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1012.Numbers%20With%20Repeated%20Digits/README.md)
-   [2376. 统计特殊整数](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2376.Count%20Special%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDigitOne(self, n: int) -> int:
        @cache
        def dfs(i: int, cnt: int, limit: bool) -> int:
            if i >= len(s):
                return cnt
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                ans += dfs(i + 1, cnt + (j == 1), limit and j == up)
            return ans

        s = str(n)
        return dfs(0, 0, True)
```

#### Java

```java
class Solution {
    private int m;
    private char[] s;
    private Integer[][] f;

    public int countDigitOne(int n) {
        s = String.valueOf(n).toCharArray();
        m = s.length;
        f = new Integer[m][m];
        return dfs(0, 0, true);
    }

    private int dfs(int i, int cnt, boolean limit) {
        if (i >= m) {
            return cnt;
        }
        if (!limit && f[i][cnt] != null) {
            return f[i][cnt];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            ans += dfs(i + 1, cnt + (j == 1 ? 1 : 0), limit && j == up);
        }
        if (!limit) {
            f[i][cnt] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][m];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int cnt, bool limit) -> int {
            if (i >= m) {
                return cnt;
            }
            if (!limit && f[i][cnt] != -1) {
                return f[i][cnt];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                ans += dfs(i + 1, cnt + (j == 1), limit && j == up);
            }
            if (!limit) {
                f[i][cnt] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true);
    }
};
```

#### Go

```go
func countDigitOne(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, cnt int, limit bool) int
	dfs = func(i, cnt int, limit bool) int {
		if i >= m {
			return cnt
		}
		if !limit && f[i][cnt] != -1 {
			return f[i][cnt]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			t := 0
			if j == 1 {
				t = 1
			}
			ans += dfs(i+1, cnt+t, limit && j == up)
		}
		if !limit {
			f[i][cnt] = ans
		}
		return ans
	}
	return dfs(0, 0, true)
}
```

#### TypeScript

```ts
function countDigitOne(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[][] = Array.from({ length: m }, () => Array(m).fill(-1));
    const dfs = (i: number, cnt: number, limit: boolean): number => {
        if (i >= m) {
            return cnt;
        }
        if (!limit && f[i][cnt] !== -1) {
            return f[i][cnt];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            ans += dfs(i + 1, cnt + (j === 1 ? 1 : 0), limit && j === up);
        }
        if (!limit) {
            f[i][cnt] = ans;
        }
        return ans;
    };
    return dfs(0, 0, true);
}
```

#### C#

```cs
public class Solution {
    private int m;
    private char[] s;
    private int?[,] f;

    public int CountDigitOne(int n) {
        s = n.ToString().ToCharArray();
        m = s.Length;
        f = new int?[m, m];
        return Dfs(0, 0, true);
    }

    private int Dfs(int i, int cnt, bool limit) {
        if (i >= m) {
            return cnt;
        }
        if (!limit && f[i, cnt] != null) {
            return f[i, cnt].Value;
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            ans += Dfs(i + 1, cnt + (j == 1 ? 1 : 0), limit && j == up);
        }
        if (!limit) {
            f[i, cnt] = ans;
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list){#234}

{{< tabs "234" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head.next
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        pre, cur = None, slow.next
        while cur:
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        while pre:
            if pre.val != head.val:
                return False
            pre, head = pre.next, head.next
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode cur = slow.next;
        slow.next = null;
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        while (pre != null) {
            if (pre.val != head.val) {
                return false;
            }
            pre = pre.next;
            head = head.next;
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        while (pre) {
            if (pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	var pre *ListNode
	cur := slow.Next
	for cur != nil {
		t := cur.Next
		cur.Next = pre
		pre = cur
		cur = t
	}
	for pre != nil {
		if pre.Val != head.Val {
			return false
		}
		pre, head = pre.Next, head.Next
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function isPalindrome(head: ListNode | null): boolean {
    let slow: ListNode = head,
        fast: ListNode = head.next;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let cur: ListNode = slow.next;
    slow.next = null;
    let prev: ListNode = null;
    while (cur != null) {
        let t: ListNode = cur.next;
        cur.next = prev;
        prev = cur;
        cur = t;
    }
    while (prev != null) {
        if (prev.val != head.val) return false;
        prev = prev.next;
        head = head.next;
    }
    return true;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
    let slow = head;
    let fast = head.next;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let cur = slow.next;
    slow.next = null;
    let pre = null;
    while (cur) {
        let t = cur.next;
        cur.next = pre;
        pre = cur;
        cur = t;
    }
    while (pre) {
        if (pre.val !== head.val) {
            return false;
        }
        pre = pre.next;
        head = head.next;
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public bool IsPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode cur = slow.next;
        slow.next = null;
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        while (pre != null) {
            if (pre.val != head.val) {
                return false;
            }
            pre = pre.next;
            head = head.next;
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个单链表的头节点 <code>head</code> ，请你判断该链表是否为<span data-keyword="palindrome-sequence">回文链表</span>。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0234.Palindrome%20Linked%20List/images/pal1linked-list.jpg" style="width: 422px; height: 62px;" />
<pre>
<strong>输入：</strong>head = [1,2,2,1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0234.Palindrome%20Linked%20List/images/pal2linked-list.jpg" style="width: 182px; height: 62px;" />
<pre>
<strong>输入：</strong>head = [1,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目在范围<code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否用&nbsp;<code>O(n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度解决此题？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

我们可以先用快慢指针找到链表的中点，接着反转右半部分的链表。然后同时遍历前后两段链表，若前后两段链表节点对应的值不等，说明不是回文链表，否则说明是回文链表。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head.next
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        pre, cur = None, slow.next
        while cur:
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        while pre:
            if pre.val != head.val:
                return False
            pre, head = pre.next, head.next
        return True
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode cur = slow.next;
        slow.next = null;
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        while (pre != null) {
            if (pre.val != head.val) {
                return false;
            }
            pre = pre.next;
            head = head.next;
        }
        return true;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        while (pre) {
            if (pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	var pre *ListNode
	cur := slow.Next
	for cur != nil {
		t := cur.Next
		cur.Next = pre
		pre = cur
		cur = t
	}
	for pre != nil {
		if pre.Val != head.Val {
			return false
		}
		pre, head = pre.Next, head.Next
	}
	return true
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function isPalindrome(head: ListNode | null): boolean {
    let slow: ListNode = head,
        fast: ListNode = head.next;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let cur: ListNode = slow.next;
    slow.next = null;
    let prev: ListNode = null;
    while (cur != null) {
        let t: ListNode = cur.next;
        cur.next = prev;
        prev = cur;
        cur = t;
    }
    while (prev != null) {
        if (prev.val != head.val) return false;
        prev = prev.next;
        head = head.next;
    }
    return true;
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
    let slow = head;
    let fast = head.next;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let cur = slow.next;
    slow.next = null;
    let pre = null;
    while (cur) {
        let t = cur.next;
        cur.next = pre;
        pre = cur;
        cur = t;
    }
    while (pre) {
        if (pre.val !== head.val) {
            return false;
        }
        pre = pre.next;
        head = head.next;
    }
    return true;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public bool IsPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode cur = slow.next;
        slow.next = null;
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        while (pre != null) {
            if (pre.val != head.val) {
                return false;
            }
            pre = pre.next;
            head = head.next;
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [235. 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree){#235}

{{< tabs "235" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'
    ) -> 'TreeNode':
        if root.val < min(p.val, q.val):
            return self.lowestCommonAncestor(root.right, p, q)
        if root.val > max(p.val, q.val):
            return self.lowestCommonAncestor(root.left, p, q)
        return root
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
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val < Math.min(p.val, q.val)) {
            return lowestCommonAncestor(root.right, p, q);
        }
        if (root.val > Math.max(p.val, q.val)) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return root;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > max(p->val, q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root.Val < p.Val && root.Val < q.Val {
		return lowestCommonAncestor(root.Right, p, q)
	}
	if root.Val > p.Val && root.Val > q.Val {
		return lowestCommonAncestor(root.Left, p, q)
	}
	return root
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

function lowestCommonAncestor(
    root: TreeNode | null,
    p: TreeNode | null,
    q: TreeNode | null,
): TreeNode | null {
    if (root.val > p.val && root.val > q.val) {
        return lowestCommonAncestor(root.left, p, q);
    }
    if (root.val < p.val && root.val < q.val) {
        return lowestCommonAncestor(root.right, p, q);
    }
    return root;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val < Math.Min(p.val, q.val)) {
            return LowestCommonAncestor(root.right, p, q);
        }
        if (root.val > Math.Max(p.val, q.val)) {
            return LowestCommonAncestor(root.left, p, q);
        }
        return root;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin" target="_blank">百度百科</a>中最近公共祖先的定义为：&ldquo;对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。&rdquo;</p>

<p>例如，给定如下二叉搜索树:&nbsp; root =&nbsp;[6,2,8,0,4,7,9,null,null,3,5]</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0235.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree/images/binarysearchtree_improved.png" style="height: 190px; width: 200px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>输出:</strong> 6 
<strong>解释: </strong>节点 <code>2 </code>和节点 <code>8 </code>的最近公共祖先是 <code>6。</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>输出:</strong> 2
<strong>解释: </strong>节点 <code>2</code> 和节点 <code>4</code> 的最近公共祖先是 <code>2</code>, 因为根据定义最近公共祖先节点可以为节点本身。</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul>
	<li>所有节点的值都是唯一的。</li>
	<li>p、q 为不同节点且均存在于给定的二叉搜索树中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：迭代

我们从根节点开始遍历，如果当前节点的值小于 $\textit{p}$ 和 $\textit{q}$ 的值，说明 $\textit{p}$ 和 $\textit{q}$ 应该在当前节点的右子树，因此将当前节点移动到右子节点；如果当前节点的值大于 $\textit{p}$ 和 $\textit{q}$ 的值，说明 $\textit{p}$ 和 $\textit{q}$ 应该在当前节点的左子树，因此将当前节点移动到左子节点；否则说明当前节点就是 $\textit{p}$ 和 $\textit{q}$ 的最近公共祖先，返回当前节点即可。

时间复杂度 $O(n)$，其中 $n$ 是二叉搜索树的节点个数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'
    ) -> 'TreeNode':
        while 1:
            if root.val < min(p.val, q.val):
                root = root.right
            elif root.val > max(p.val, q.val):
                root = root.left
            else:
                return root
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (true) {
            if (root.val < Math.min(p.val, q.val)) {
                root = root.right;
            } else if (root.val > Math.max(p.val, q.val)) {
                root = root.left;
            } else {
                return root;
            }
        }
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (1) {
            if (root->val < min(p->val, q->val)) {
                root = root->right;
            } else if (root->val > max(p->val, q->val)) {
                root = root->left;
            } else {
                return root;
            }
        }
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	for {
		if root.Val < min(p.Val, q.Val) {
			root = root.Right
		} else if root.Val > max(p.Val, q.Val) {
			root = root.Left
		} else {
			return root
		}
	}
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

function lowestCommonAncestor(
    root: TreeNode | null,
    p: TreeNode | null,
    q: TreeNode | null,
): TreeNode | null {
    while (root) {
        if (root.val > p.val && root.val > q.val) {
            root = root.left;
        } else if (root.val < p.val && root.val < q.val) {
            root = root.right;
        } else {
            return root;
        }
    }
}
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (true) {
            if (root.val < Math.Min(p.val, q.val)) {
                root = root.right;
            } else if (root.val > Math.Max(p.val, q.val)) {
                root = root.left;
            } else {
                return root;
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：递归

我们也可以使用递归的方法来解决这个问题。

我们首先判断当前节点的值是否小于 $\textit{p}$ 和 $\textit{q}$ 的值，如果是，则递归遍历右子树；如果当前节点的值大于 $\textit{p}$ 和 $\textit{q}$ 的值，如果是，则递归遍历左子树；否则说明当前节点就是 $\textit{p}$ 和 $\textit{q}$ 的最近公共祖先，返回当前节点即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'
    ) -> 'TreeNode':
        if root.val < min(p.val, q.val):
            return self.lowestCommonAncestor(root.right, p, q)
        if root.val > max(p.val, q.val):
            return self.lowestCommonAncestor(root.left, p, q)
        return root
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val < Math.min(p.val, q.val)) {
            return lowestCommonAncestor(root.right, p, q);
        }
        if (root.val > Math.max(p.val, q.val)) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return root;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > max(p->val, q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root.Val < p.Val && root.Val < q.Val {
		return lowestCommonAncestor(root.Right, p, q)
	}
	if root.Val > p.Val && root.Val > q.Val {
		return lowestCommonAncestor(root.Left, p, q)
	}
	return root
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

function lowestCommonAncestor(
    root: TreeNode | null,
    p: TreeNode | null,
    q: TreeNode | null,
): TreeNode | null {
    if (root.val > p.val && root.val > q.val) {
        return lowestCommonAncestor(root.left, p, q);
    }
    if (root.val < p.val && root.val < q.val) {
        return lowestCommonAncestor(root.right, p, q);
    }
    return root;
}
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val < Math.Min(p.val, q.val)) {
            return LowestCommonAncestor(root.right, p, q);
        }
        if (root.val > Math.Max(p.val, q.val)) {
            return LowestCommonAncestor(root.left, p, q);
        }
        return root;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree){#236}

{{< tabs "236" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        if root in (None, p, q):
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        return root if left and right else (left or right)
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }
        var left = lowestCommonAncestor(root.left, p, q);
        var right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        }
        return left == null ? right : left;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
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
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil || root == p || root == q {
		return root
	}
	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)
	if left != nil && right != nil {
		return root
	}
	if left != nil {
		return left
	}
	return right
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

function lowestCommonAncestor(
    root: TreeNode | null,
    p: TreeNode | null,
    q: TreeNode | null,
): TreeNode | null {
    if (!root || root === p || root === q) {
        return root;
    }
    const left = lowestCommonAncestor(root.left, p, q);
    const right = lowestCommonAncestor(root.right, p, q);
    return left && right ? root : left || right;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() || root == p || root == q {
            return root;
        }
        let left = Self::lowest_common_ancestor(
            root.as_ref().unwrap().borrow().left.clone(),
            p.clone(),
            q.clone(),
        );
        let right = Self::lowest_common_ancestor(
            root.as_ref().unwrap().borrow().right.clone(),
            p.clone(),
            q.clone(),
        );
        if left.is_some() && right.is_some() {
            return root;
        }
        if left.is_none() {
            return right;
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    if (!root || root === p || root === q) {
        return root;
    }
    const left = lowestCommonAncestor(root.left, p, q);
    const right = lowestCommonAncestor(root.right, p, q);
    return left && right ? root : left || right;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin" target="_blank">百度百科</a>中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。”</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0236.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree/images/binarytree.png" style="width: 200px; height: 190px;" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>输出：</strong>3
<strong>解释：</strong>节点 <code>5 </code>和节点 <code>1 </code>的最近公共祖先是节点 <code>3 。</code>
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0236.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree/images/binarytree.png" style="width: 200px; height: 190px;" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>输出：</strong>5
<strong>解释：</strong>节点 <code>5 </code>和节点 <code>4 </code>的最近公共祖先是节点 <code>5 。</code>因为根据定义最近公共祖先节点可以为节点本身。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2], p = 1, q = 2
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[2, 10<sup>5</sup>]</code> 内。</li>
	<li><code>-10<sup>9</sup> <= Node.val <= 10<sup>9</sup></code></li>
	<li>所有 <code>Node.val</code> <code>互不相同</code> 。</li>
	<li><code>p != q</code></li>
	<li><code>p</code> 和 <code>q</code> 均存在于给定的二叉树中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们递归遍历二叉树：

如果当前节点为空或者等于 $p$ 或者 $q$，则返回当前节点；

否则，我们递归遍历左右子树，将返回的结果分别记为 $left$ 和 $right$。如果 $left$ 和 $right$ 都不为空，则说明 $p$ 和 $q$ 分别在左右子树中，因此当前节点即为最近公共祖先；如果 $left$ 和 $right$ 中只有一个不为空，返回不为空的那个。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        if root in (None, p, q):
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        return root if left and right else (left or right)
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }
        var left = lowestCommonAncestor(root.left, p, q);
        var right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        }
        return left == null ? right : left;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
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
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil || root == p || root == q {
		return root
	}
	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)
	if left != nil && right != nil {
		return root
	}
	if left != nil {
		return left
	}
	return right
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

function lowestCommonAncestor(
    root: TreeNode | null,
    p: TreeNode | null,
    q: TreeNode | null,
): TreeNode | null {
    if (!root || root === p || root === q) {
        return root;
    }
    const left = lowestCommonAncestor(root.left, p, q);
    const right = lowestCommonAncestor(root.right, p, q);
    return left && right ? root : left || right;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() || root == p || root == q {
            return root;
        }
        let left = Self::lowest_common_ancestor(
            root.as_ref().unwrap().borrow().left.clone(),
            p.clone(),
            q.clone(),
        );
        let right = Self::lowest_common_ancestor(
            root.as_ref().unwrap().borrow().right.clone(),
            p.clone(),
            q.clone(),
        );
        if left.is_some() && right.is_some() {
            return root;
        }
        if left.is_none() {
            return right;
        }
        return left;
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    if (!root || root === p || root === q) {
        return root;
    }
    const left = lowestCommonAncestor(root.left, p, q);
    const right = lowestCommonAncestor(root.right, p, q);
    return left && right ? root : left || right;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [237. 删除链表中的节点](https://leetcode.cn/problems/delete-node-in-a-linked-list){#237}

{{< tabs "237" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

/**
 Do not return anything, modify it in-place instead.
 */
function deleteNode(node: ListNode | null): void {
    node.val = node.next.val;
    node.next = node.next.next;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function (node) {
    node.val = node.next.val;
    node.next = node.next.next;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void DeleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个单链表的&nbsp;<code>head</code>，我们想删除它其中的一个节点&nbsp;<code>node</code>。</p>

<p>给你一个需要删除的节点&nbsp;<code>node</code>&nbsp;。你将&nbsp;<strong>无法访问</strong>&nbsp;第一个节点&nbsp;&nbsp;<code>head</code>。</p>

<p>链表的所有值都是 <b>唯一的</b>，并且保证给定的节点&nbsp;<code>node</code>&nbsp;不是链表中的最后一个节点。</p>

<p>删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：</p>

<ul>
	<li>给定节点的值不应该存在于链表中。</li>
	<li>链表中的节点数应该减少 1。</li>
	<li><code>node</code>&nbsp;前面的所有值顺序相同。</li>
	<li><code>node</code>&nbsp;后面的所有值顺序相同。</li>
</ul>

<p><strong>自定义测试：</strong></p>

<ul>
	<li>对于输入，你应该提供整个链表&nbsp;<code>head</code>&nbsp;和要给出的节点&nbsp;<code>node</code>。<code>node</code>&nbsp;不应该是链表的最后一个节点，而应该是链表中的一个实际节点。</li>
	<li>我们将构建链表，并将节点传递给你的函数。</li>
	<li>输出将是调用你函数后的整个链表。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0237.Delete%20Node%20in%20a%20Linked%20List/images/node1.jpg" style="height: 286px; width: 400px;" />
<pre>
<strong>输入：</strong>head = [4,5,1,9], node = 5
<strong>输出：</strong>[4,1,9]
<strong>解释：</strong>指定链表中值为&nbsp;5&nbsp;的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 1 -&gt; 9
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0237.Delete%20Node%20in%20a%20Linked%20List/images/node2.jpg" style="height: 315px; width: 400px;" />
<pre>
<strong>输入：</strong>head = [4,5,1,9], node = 1
<strong>输出：</strong>[4,5,9]
<strong>解释：</strong>指定链表中值为&nbsp;1&nbsp;的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 5 -&gt; 9</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围是 <code>[2, 1000]</code></li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>链表中每个节点的值都是 <strong>唯一</strong> 的</li>
	<li>需要删除的节点 <code>node</code> 是 <strong>链表中的节点</strong> ，且 <strong>不是末尾节点</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：节点赋值

我们可以将当前节点的值替换为下一个节点的值，然后删除下一个节点。这样就可以达到删除当前节点的目的。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

/**
 Do not return anything, modify it in-place instead.
 */
function deleteNode(node: ListNode | null): void {
    node.val = node.next.val;
    node.next = node.next.next;
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function (node) {
    node.val = node.next.val;
    node.next = node.next.next;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void DeleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```

#### C

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self){#238}

{{< tabs "238" >}}

{{% tab "python" %}}
```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        left = right = 1
        for i, x in enumerate(nums):
            ans[i] = left
            left *= x
        for i in range(n - 1, -1, -1):
            ans[i] *= right
            right *= nums[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0, left = 1; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = n - 1, right = 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, left = 1; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = n - 1, right = 1; ~i; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func productExceptSelf(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	left, right := 1, 1
	for i, x := range nums {
		ans[i] = left
		left *= x
	}
	for i := n - 1; i >= 0; i-- {
		ans[i] *= right
		right *= nums[i]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function productExceptSelf(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = new Array(n);
    for (let i = 0, left = 1; i < n; ++i) {
        ans[i] = left;
        left *= nums[i];
    }
    for (let i = n - 1, right = 1; i >= 0; --i) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![1; n];
        for i in 1..n {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        let mut r = 1;
        for i in (0..n).rev() {
            ans[i] *= r;
            r *= nums[i];
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0, left = 1; i < n; ++i) {
        ans[i] = left;
        left *= nums[i];
    }
    for (let i = n - 1, right = 1; i >= 0; --i) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0, left = 1; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = n - 1, right = 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function productExceptSelf($nums) {
        $n = count($nums);
        $ans = [];
        for ($i = 0, $left = 1; $i < $n; ++$i) {
            $ans[$i] = $left;
            $left *= $nums[$i];
        }
        for ($i = $n - 1, $right = 1; $i >= 0; --$i) {
            $ans[$i] *= $right;
            $right *= $nums[$i];
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，返回 数组&nbsp;<code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>&nbsp;等于&nbsp;<code>nums</code>&nbsp;中除&nbsp;<code>nums[i]</code>&nbsp;之外其余各元素的乘积&nbsp;。</p>

<p>题目数据 <strong>保证</strong> 数组&nbsp;<code>nums</code>之中任意元素的全部前缀元素和后缀的乘积都在&nbsp; <strong>32 位</strong> 整数范围内。</p>

<p>请&nbsp;<strong>不要使用除法，</strong>且在&nbsp;<code>O(n)</code> 时间复杂度内完成此题。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[1,2,3,4]</code>
<strong>输出:</strong> <code>[24,12,8,6]</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [-1,1,0,-3,3]
<strong>输出:</strong> [0,0,9,0,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-30 &lt;= nums[i] &lt;= 30</code></li>
	<li>输入&nbsp;<strong>保证</strong> 数组&nbsp;<code>answer[i]</code>&nbsp;在&nbsp; <strong>32 位</strong> 整数范围内</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以在 <code>O(1)</code>&nbsp;的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组&nbsp;<strong>不被视为&nbsp;</strong>额外空间。）</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

我们定义两个变量 $\textit{left}$ 和 $\textit{right}$，分别表示当前元素左边所有元素的乘积和右边所有元素的乘积。初始时 $\textit{left}=1$, $\textit{right}=1$。定义一个长度为 $n$ 的答案数组 $\textit{ans}$。

我们先从左到右遍历数组，对于遍历到的第 $i$ 个元素，我们用 $\textit{left}$ 更新 $\textit{ans}[i]$，然后 $\textit{left}$ 乘以 $\textit{nums}[i]$。

然后，我们从右到左遍历数组，对于遍历到的第 $i$ 个元素，我们更新 $\textit{ans}[i]$ 为 $\textit{ans}[i] \times \textit{right}$，然后 $\textit{right}$ 乘以 $\textit{nums}[i]$。

遍历结束后，返回答案数组 $\textit{ans}$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        left = right = 1
        for i, x in enumerate(nums):
            ans[i] = left
            left *= x
        for i in range(n - 1, -1, -1):
            ans[i] *= right
            right *= nums[i]
        return ans
```

#### Java

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0, left = 1; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = n - 1, right = 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, left = 1; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = n - 1, right = 1; ~i; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
```

#### Go

```go
func productExceptSelf(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	left, right := 1, 1
	for i, x := range nums {
		ans[i] = left
		left *= x
	}
	for i := n - 1; i >= 0; i-- {
		ans[i] *= right
		right *= nums[i]
	}
	return ans
}
```

#### TypeScript

```ts
function productExceptSelf(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = new Array(n);
    for (let i = 0, left = 1; i < n; ++i) {
        ans[i] = left;
        left *= nums[i];
    }
    for (let i = n - 1, right = 1; i >= 0; --i) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![1; n];
        for i in 1..n {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        let mut r = 1;
        for i in (0..n).rev() {
            ans[i] *= r;
            r *= nums[i];
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0, left = 1; i < n; ++i) {
        ans[i] = left;
        left *= nums[i];
    }
    for (let i = n - 1, right = 1; i >= 0; --i) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0, left = 1; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = n - 1, right = 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function productExceptSelf($nums) {
        $n = count($nums);
        $ans = [];
        for ($i = 0, $left = 1; $i < $n; ++$i) {
            $ans[$i] = $left;
            $left *= $nums[$i];
        }
        for ($i = $n - 1, $right = 1; $i >= 0; --$i) {
            $ans[$i] *= $right;
            $right *= $nums[$i];
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum){#239}

{{< tabs "239" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        ans = []
        for i, x in enumerate(nums):
            if q and i - q[0] >= k:
                q.popleft()
            while q and nums[q[-1]] <= x:
                q.pop()
            q.append(i)
            if i >= k - 1:
                ans.append(nums[q[0]])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (!q.isEmpty() && i - q.peekFirst() >= k) {
                q.pollFirst();
            }
            while (!q.isEmpty() && nums[q.peekLast()] <= nums[i]) {
                q.pollLast();
            }
            q.offerLast(i);
            if (i >= k - 1) {
                ans[i - k + 1] = nums[q.peekFirst()];
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() && i - q.front() >= k) {
                q.pop_front();
            }
            while (q.size() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSlidingWindow(nums []int, k int) (ans []int) {
	q := []int{}
	for i, x := range nums {
		if len(q) > 0 && i-q[0] >= k {
			q = q[1:]
		}
		for len(q) > 0 && nums[q[len(q)-1]] <= x {
			q = q[:len(q)-1]
		}
		q = append(q, i)
		if i >= k-1 {
			ans = append(ans, nums[q[0]])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSlidingWindow(nums: number[], k: number): number[] {
    const ans: number[] = [];
    const q = new Deque();
    for (let i = 0; i < nums.length; ++i) {
        if (!q.isEmpty() && i - q.front()! >= k) {
            q.popFront();
        }
        while (!q.isEmpty() && nums[q.back()!] <= nums[i]) {
            q.popBack();
        }
        q.pushBack(i);
        if (i >= k - 1) {
            ans.push(nums[q.front()!]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut ans = Vec::new();
        let mut q: VecDeque<usize> = VecDeque::new();

        for i in 0..nums.len() {
            if let Some(&front) = q.front() {
                if i >= front + k {
                    q.pop_front();
                }
            }
            while let Some(&back) = q.back() {
                if nums[back] <= nums[i] {
                    q.pop_back();
                } else {
                    break;
                }
            }
            q.push_back(i);
            if i >= k - 1 {
                ans.push(nums[*q.front().unwrap()]);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {
    const ans = [];
    const q = new Deque();
    for (let i = 0; i < nums.length; ++i) {
        if (!q.isEmpty() && i - q.front() >= k) {
            q.popFront();
        }
        while (!q.isEmpty() && nums[q.back()] <= nums[i]) {
            q.popBack();
        }
        q.pushBack(i);
        if (i >= k - 1) {
            ans.push(nums[q.front()]);
        }
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，有一个大小为&nbsp;<code>k</code><em>&nbsp;</em>的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 <code>k</code>&nbsp;个数字。滑动窗口每次只向右移动一位。</p>

<p>返回 <em>滑动窗口中的最大值 </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,-1,-3,5,3,6,7], k = 3
<b>输出：</b>[3,3,5,5,6,7]
<b>解释：</b>
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1], k = 1
<b>输出：</b>[1]
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大根堆）

我们可以使用优先队列（大根堆）来维护滑动窗口中的最大值。

先将前 $k-1$ 个元素加入优先队列，接下来从第 $k$ 个元素开始，将新元素加入优先队列，同时判断堆顶元素是否滑出窗口，如果滑出窗口则将堆顶元素弹出。然后我们将堆顶元素加入结果数组。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(k)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = [(-v, i) for i, v in enumerate(nums[: k - 1])]
        heapify(q)
        ans = []
        for i in range(k - 1, len(nums)):
            heappush(q, (-nums[i], i))
            while q[0][1] <= i - k:
                heappop(q)
            ans.append(-q[0][0])
        return ans
```

#### Java

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        PriorityQueue<int[]> q
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        int n = nums.length;
        for (int i = 0; i < k - 1; ++i) {
            q.offer(new int[] {nums[i], i});
        }
        int[] ans = new int[n - k + 1];
        for (int i = k - 1, j = 0; i < n; ++i) {
            q.offer(new int[] {nums[i], i});
            while (q.peek()[1] <= i - k) {
                q.poll();
            }
            ans[j++] = q.peek()[0];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        int n = nums.size();
        for (int i = 0; i < k - 1; ++i) {
            q.push({nums[i], -i});
        }
        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            q.push({nums[i], -i});
            while (-q.top().second <= i - k) {
                q.pop();
            }
            ans.emplace_back(q.top().first);
        }
        return ans;
    }
};
```

#### Go

```go
func maxSlidingWindow(nums []int, k int) (ans []int) {
	q := hp{}
	for i, v := range nums[:k-1] {
		heap.Push(&q, pair{v, i})
	}
	for i := k - 1; i < len(nums); i++ {
		heap.Push(&q, pair{nums[i], i})
		for q[0].i <= i-k {
			heap.Pop(&q)
		}
		ans = append(ans, q[0].v)
	}
	return
}

type pair struct{ v, i int }

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.v > b.v || (a.v == b.v && i < j)
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调队列

求滑动窗口的最大值，一种常见的方法是使用单调队列。

我们可以维护一个从队头到队尾单调递减的队列 $q$，队列中存储的是元素的下标。遍历数组 $\textit{nums}$，对于当前元素 $\textit{nums}[i]$，我们首先判断队头元素是否滑出窗口，如果滑出窗口则将队头元素弹出。然后我们将当前元素 $\textit{nums}[i]$ 从队尾开始依次与队尾元素比较，如果队尾元素小于等于当前元素，则将队尾元素弹出，直到队尾元素大于当前元素或者队列为空。然后将当前元素的下标加入队列。此时队列的队头元素即为当前滑动窗口的最大值，注意，我们将队头元素加入结果数组的时机是当下标 $i$ 大于等于 $k-1$ 时。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        ans = []
        for i, x in enumerate(nums):
            if q and i - q[0] >= k:
                q.popleft()
            while q and nums[q[-1]] <= x:
                q.pop()
            q.append(i)
            if i >= k - 1:
                ans.append(nums[q[0]])
        return ans
```

#### Java

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (!q.isEmpty() && i - q.peekFirst() >= k) {
                q.pollFirst();
            }
            while (!q.isEmpty() && nums[q.peekLast()] <= nums[i]) {
                q.pollLast();
            }
            q.offerLast(i);
            if (i >= k - 1) {
                ans[i - k + 1] = nums[q.peekFirst()];
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() && i - q.front() >= k) {
                q.pop_front();
            }
            while (q.size() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSlidingWindow(nums []int, k int) (ans []int) {
	q := []int{}
	for i, x := range nums {
		if len(q) > 0 && i-q[0] >= k {
			q = q[1:]
		}
		for len(q) > 0 && nums[q[len(q)-1]] <= x {
			q = q[:len(q)-1]
		}
		q = append(q, i)
		if i >= k-1 {
			ans = append(ans, nums[q[0]])
		}
	}
	return
}
```

#### TypeScript

```ts
function maxSlidingWindow(nums: number[], k: number): number[] {
    const ans: number[] = [];
    const q = new Deque();
    for (let i = 0; i < nums.length; ++i) {
        if (!q.isEmpty() && i - q.front()! >= k) {
            q.popFront();
        }
        while (!q.isEmpty() && nums[q.back()!] <= nums[i]) {
            q.popBack();
        }
        q.pushBack(i);
        if (i >= k - 1) {
            ans.push(nums[q.front()!]);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut ans = Vec::new();
        let mut q: VecDeque<usize> = VecDeque::new();

        for i in 0..nums.len() {
            if let Some(&front) = q.front() {
                if i >= front + k {
                    q.pop_front();
                }
            }
            while let Some(&back) = q.back() {
                if nums[back] <= nums[i] {
                    q.pop_back();
                } else {
                    break;
                }
            }
            q.push_back(i);
            if i >= k - 1 {
                ans.push(nums[*q.front().unwrap()]);
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {
    const ans = [];
    const q = new Deque();
    for (let i = 0; i < nums.length; ++i) {
        if (!q.isEmpty() && i - q.front() >= k) {
            q.popFront();
        }
        while (!q.isEmpty() && nums[q.back()] <= nums[i]) {
            q.popBack();
        }
        q.pushBack(i);
        if (i >= k - 1) {
            ans.push(nums[q.front()]);
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
