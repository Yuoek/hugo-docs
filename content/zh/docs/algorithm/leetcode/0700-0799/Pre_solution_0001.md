---
title: "0700_二叉搜索树中的搜索"
date: 2025-10-08T18:36:29+08:00
weight: 1
tags: [二分查找, 二叉搜索树, 二叉树, 交互, 哈希函数, 哈希表, 堆（优先队列）, 字符串, 数据流, 数组, 树, 设计, 链表]
---

{{< markmap >}}
### [0700_二叉搜索树中的搜索](#700)
#### [树](#700)
#### [二叉搜索树](#700)
#### [二叉树](#700)
### [0701_二叉搜索树中的插入操作](#701)
#### [树](#701)
#### [二叉搜索树](#701)
#### [二叉树](#701)
### [0702_搜索长度未知的有序数组 🔒](#702)
#### [数组](#702)
#### [二分查找](#702)
#### [交互](#702)
### [0703_数据流中的第 K 大元素](#703)
#### [树](#703)
#### [设计](#703)
#### [二叉搜索树](#703)
#### [二叉树](#703)
#### [数据流](#703)
#### [堆（优先队列）](#703)
### [0704_二分查找](#704)
#### [数组](#704)
#### [二分查找](#704)
### [0705_设计哈希集合](#705)
#### [设计](#705)
#### [数组](#705)
#### [哈希表](#705)
#### [链表](#705)
#### [哈希函数](#705)
### [0706_设计哈希映射](#706)
#### [设计](#706)
#### [数组](#706)
#### [哈希表](#706)
#### [链表](#706)
#### [哈希函数](#706)
### [0707_设计链表](#707)
#### [设计](#707)
#### [链表](#707)
### [0708_循环有序列表的插入 🔒](#708)
#### [链表](#708)
### [0709_转换成小写字母](#709)
#### [字符串](#709)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0700_二叉搜索树中的搜索
___
#### 树
___
#### 二叉搜索树
___
#### 二叉树
---
### 0701_二叉搜索树中的插入操作
___
#### 树
___
#### 二叉搜索树
___
#### 二叉树
---
### 0702_搜索长度未知的有序数组 🔒
___
#### 数组
___
#### 二分查找
___
#### 交互
---
### 0703_数据流中的第 K 大元素
___
#### 树
___
#### 设计
___
#### 二叉搜索树
___
#### 二叉树
___
#### 数据流
___
#### 堆（优先队列）
---
### 0704_二分查找
___
#### 数组
___
#### 二分查找
---
### 0705_设计哈希集合
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 链表
___
#### 哈希函数
---
### 0706_设计哈希映射
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 链表
___
#### 哈希函数
---
### 0707_设计链表
___
#### 设计
___
#### 链表
---
### 0708_循环有序列表的插入 🔒
___
#### 链表
---
### 0709_转换成小写字母
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 交互 | 哈希函数 | 哈希表 |
| 堆（优先队列） | 字符串 | 数据流 |
| 数组 | 树 | 设计 |
| 链表 |  |  |

# [700. 二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree){#700}

{{< tabs "700" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None or root.val == val:
            return root
        return (
            self.searchBST(root.left, val)
            if root.val > val
            else self.searchBST(root.right, val)
        )
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
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        }
        return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
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
 func searchBST(root *TreeNode, val int) *TreeNode {
    if root == nil || root.Val == val {
        return root
    }
    if root.Val > val {
        return searchBST(root.Left, val)
    }
    return searchBST(root.Right, val)
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

function searchBST(root: TreeNode | null, val: number): TreeNode | null {
    if (root === null || root.val === val) {
        return root;
    }
    return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定二叉搜索树（BST）的根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;和一个整数值<meta charset="UTF-8" />&nbsp;<code>val</code>。</p>

<p>你需要在 BST 中找到节点值等于&nbsp;<code>val</code>&nbsp;的节点。 返回以该节点为根的子树。 如果节点不存在，则返回<meta charset="UTF-8" />&nbsp;<code>null</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0700.Search%20in%20a%20Binary%20Search%20Tree/images/tree1.jpg" style="height: 179px; width: 250px;" /><meta charset="UTF-8" /></p>

<pre>
<b>输入：</b>root = [4,2,7,1,3], val = 2
<b>输出：</b>[2,1,3]
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0700.Search%20in%20a%20Binary%20Search%20Tree/images/tree2.jpg" style="height: 179px; width: 250px;" />
<pre>
<b>输入：</b>root = [4,2,7,1,3], val = 5
<b>输出：</b>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数在&nbsp;<code>[1, 5000]</code>&nbsp;范围内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>7</sup></code></li>
	<li><code>root</code>&nbsp;是二叉搜索树</li>
	<li><code>1 &lt;= val &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们判断当前节点是否为空或者当前节点的值是否等于目标值，如果是则返回当前节点。

否则，如果当前节点的值大于目标值，则递归搜索左子树，否则递归搜索右子树。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None or root.val == val:
            return root
        return (
            self.searchBST(root.left, val)
            if root.val > val
            else self.searchBST(root.right, val)
        )
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
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        }
        return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
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
 func searchBST(root *TreeNode, val int) *TreeNode {
    if root == nil || root.Val == val {
        return root
    }
    if root.Val > val {
        return searchBST(root.Left, val)
    }
    return searchBST(root.Right, val)
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

function searchBST(root: TreeNode | null, val: number): TreeNode | null {
    if (root === null || root.val === val) {
        return root;
    }
    return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [701. 二叉搜索树中的插入操作](https://leetcode.cn/problems/insert-into-a-binary-search-tree){#701}

{{< tabs "701" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)
        if root.val > val:
            root.left = self.insertIntoBST(root.left, val)
        else:
            root.right = self.insertIntoBST(root.right, val)
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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (root.val > val) {
            root.left = insertIntoBST(root.left, val);
        } else {
            root.right = insertIntoBST(root.right, val);
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
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
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return &TreeNode{Val: val}
	}
	if root.Val > val {
		root.Left = insertIntoBST(root.Left, val)
	} else {
		root.Right = insertIntoBST(root.Right, val)
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

function insertIntoBST(root: TreeNode | null, val: number): TreeNode | null {
    if (!root) {
        return new TreeNode(val);
    }
    if (root.val > val) {
        root.left = insertIntoBST(root.left, val);
    } else {
        root.right = insertIntoBST(root.right, val);
    }
    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定二叉搜索树（BST）的根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;和要插入树中的值<meta charset="UTF-8" />&nbsp;<code>value</code>&nbsp;，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 <strong>保证</strong> ，新值和原始二叉搜索树中的任意节点值都不同。</p>

<p><strong>注意</strong>，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 <strong>任意有效的结果</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0701.Insert%20into%20a%20Binary%20Search%20Tree/images/insertbst.jpg" />
<pre>
<strong>输入：</strong>root = [4,2,7,1,3], val = 5
<strong>输出：</strong>[4,2,7,1,3,5]
<strong>解释：</strong>另一个满足题目要求可以通过的树是：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0701.Insert%20into%20a%20Binary%20Search%20Tree/images/bst.jpg" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [40,20,60,10,30,50,70], val = 25
<strong>输出：</strong>[40,20,60,10,30,50,70,null,null,25]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
<strong>输出：</strong>[4,2,7,1,3,5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数将在<meta charset="UTF-8" />&nbsp;<code>[0,&nbsp;10<sup>4</sup>]</code>的范围内。<meta charset="UTF-8" /></li>
	<li><code>-10<sup>8</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>8</sup></code></li>
	<li>所有值&nbsp;<meta charset="UTF-8" /><code>Node.val</code>&nbsp;是&nbsp;<strong>独一无二</strong>&nbsp;的。</li>
	<li><code>-10<sup>8</sup>&nbsp;&lt;= val &lt;= 10<sup>8</sup></code></li>
	<li><strong>保证</strong>&nbsp;<code>val</code>&nbsp;在原始BST中不存在。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

如果根节点为空，我们直接创建一个新节点，值为 $\textit{val}$，并返回。

如果根节点的值大于 $\textit{val}$，我们递归地将 $\textit{val}$ 插入到左子树中，并将左子树的根节点更新为返回后的根节点。

如果根节点的值小于 $\textit{val}$，我们递归地将 $\textit{val}$ 插入到右子树中，并将右子树的根节点更新为返回后的根节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)
        if root.val > val:
            root.left = self.insertIntoBST(root.left, val)
        else:
            root.right = self.insertIntoBST(root.right, val)
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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (root.val > val) {
            root.left = insertIntoBST(root.left, val);
        } else {
            root.right = insertIntoBST(root.right, val);
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
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
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return &TreeNode{Val: val}
	}
	if root.Val > val {
		root.Left = insertIntoBST(root.Left, val)
	} else {
		root.Right = insertIntoBST(root.Right, val)
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

function insertIntoBST(root: TreeNode | null, val: number): TreeNode | null {
    if (!root) {
        return new TreeNode(val);
    }
    if (root.val > val) {
        root.left = insertIntoBST(root.left, val);
    } else {
        root.right = insertIntoBST(root.right, val);
    }
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [702. 搜索长度未知的有序数组 🔒](https://leetcode.cn/problems/search-in-a-sorted-array-of-unknown-size){#702}

{{< tabs "702" >}}

{{% tab "python" %}}
```python
# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader:
#    def get(self, index: int) -> int:


class Solution:
    def search(self, reader: "ArrayReader", target: int) -> int:
        r = 1
        while reader.get(r) < target:
            r <<= 1
        l = r >> 1
        while l < r:
            mid = (l + r) >> 1
            if reader.get(mid) >= target:
                r = mid
            else:
                l = mid + 1
        return l if reader.get(l) == target else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
        int r = 1;
        while (reader.get(r) < target) {
            r <<= 1;
        }
        int l = r >> 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (reader.get(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return reader.get(l) == target ? l : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int r = 1;
        while (reader.get(r) < target) {
            r <<= 1;
        }
        int l = r >> 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (reader.get(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return reader.get(l) == target ? l : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * type ArrayReader struct {
 * }
 *
 * func (this *ArrayReader) get(index int) int {}
 */

func search(reader ArrayReader, target int) int {
	r := 1
	for reader.get(r) < target {
		r <<= 1
	}
	l := r >> 1
	for l < r {
		mid := (l + r) >> 1
		if reader.get(mid) >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if reader.get(l) == target {
		return l
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * class ArrayReader {
 *		// This is the ArrayReader's API interface.
 *		// You should not implement it, or speculate about its implementation
 *		get(index: number): number {};
 *  };
 */

function search(reader: ArrayReader, target: number): number {
    let r = 1;
    while (reader.get(r) < target) {
        r <<= 1;
    }
    let l = r >> 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (reader.get(mid) >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return reader.get(l) === target ? l : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这是一个<strong>交互问题</strong>。</p>

<p>您有一个<strong>升序</strong>整数数组，其<strong>长度未知</strong>。您没有访问数组的权限，但是可以使用&nbsp;<code>ArrayReader</code>&nbsp;接口访问它。你可以调用&nbsp;<code>ArrayReader.get(i)</code>:</p>

<ul>
	<li>
	<p>返回数组第<code>i<sup>th</sup></code>个索引(<strong>0-indexed</strong>)处的值(即&nbsp;<code>secret[i]</code>)，或者</p>
	</li>
	<li>
	<p>如果&nbsp;<code>i</code>&nbsp; 超出了数组的边界，则返回&nbsp;<code>2<sup>31</sup>&nbsp;- 1</code></p>
	</li>
</ul>

<p>你也会得到一个整数 <code>target</code>。</p>

<p>如果存在<code>secret[k] == target</code>，请返回索引&nbsp;<code>k</code>&nbsp;的值；否则返回&nbsp;<code>-1</code></p>

<p>你必须写一个时间复杂度为&nbsp;<code>O(log n)</code>&nbsp;的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> <code>secret</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>输出:</strong> 4
<strong>解释:</strong> 9 存在在 nums 中，下标为 4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> <code>secret</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 2 不在数组中所以返回 -1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= secret.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= secret[i], target &lt;= 10<sup>4</sup></code></li>
	<li><code>secret</code>&nbsp;严格递增</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们先定义一个指针 $r = 1$，每一次判断 $r$ 处的值是否小于目标值，如果小于目标值，我们将 $r$ 乘以 $2$，即左移一位，直到 $r$ 处的值大于等于目标值。此时，我们可以确定目标值在 $[r / 2, r]$ 的区间内。

接下来，我们定义一个指针 $l = r / 2$，然后我们可以使用二分查找的方法在 $[l, r]$ 的区间内查找目标值的位置。

时间复杂度 $O(\log M)$，其中 $M$ 为目标值的位置。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader:
#    def get(self, index: int) -> int:


class Solution:
    def search(self, reader: "ArrayReader", target: int) -> int:
        r = 1
        while reader.get(r) < target:
            r <<= 1
        l = r >> 1
        while l < r:
            mid = (l + r) >> 1
            if reader.get(mid) >= target:
                r = mid
            else:
                l = mid + 1
        return l if reader.get(l) == target else -1
```

#### Java

```java
/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
        int r = 1;
        while (reader.get(r) < target) {
            r <<= 1;
        }
        int l = r >> 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (reader.get(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return reader.get(l) == target ? l : -1;
    }
}
```

#### C++

```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int r = 1;
        while (reader.get(r) < target) {
            r <<= 1;
        }
        int l = r >> 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (reader.get(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return reader.get(l) == target ? l : -1;
    }
};
```

#### Go

```go
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * type ArrayReader struct {
 * }
 *
 * func (this *ArrayReader) get(index int) int {}
 */

func search(reader ArrayReader, target int) int {
	r := 1
	for reader.get(r) < target {
		r <<= 1
	}
	l := r >> 1
	for l < r {
		mid := (l + r) >> 1
		if reader.get(mid) >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if reader.get(l) == target {
		return l
	}
	return -1
}
```

#### TypeScript

```ts
/**
 * class ArrayReader {
 *		// This is the ArrayReader's API interface.
 *		// You should not implement it, or speculate about its implementation
 *		get(index: number): number {};
 *  };
 */

function search(reader: ArrayReader, target: number): number {
    let r = 1;
    while (reader.get(r) < target) {
        r <<= 1;
    }
    let l = r >> 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (reader.get(mid) >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return reader.get(l) === target ? l : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream){#703}

{{< tabs "703" >}}

{{% tab "python" %}}
```python
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.min_q = []
        for x in nums:
            self.add(x)

    def add(self, val: int) -> int:
        heappush(self.min_q, val)
        if len(self.min_q) > self.k:
            heappop(self.min_q)
        return self.min_q[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class KthLargest {
    private PriorityQueue<Integer> minQ;
    private int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        minQ = new PriorityQueue<>(k);
        for (int x : nums) {
            add(x);
        }
    }

    public int add(int val) {
        minQ.offer(val);
        if (minQ.size() > k) {
            minQ.poll();
        }
        return minQ.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        minQ.push(val);
        if (minQ.size() > k) {
            minQ.pop();
        }
        return minQ.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minQ;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type KthLargest struct {
	k    int
	minQ hp
}

func Constructor(k int, nums []int) KthLargest {
	minQ := hp{}
	this := KthLargest{k, minQ}
	for _, x := range nums {
		this.Add(x)
	}
	return this
}

func (this *KthLargest) Add(val int) int {
	heap.Push(&this.minQ, val)
	if this.minQ.Len() > this.k {
		heap.Pop(&this.minQ)
	}
	return this.minQ.IntSlice[0]
}

type hp struct{ sort.IntSlice }

func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Pop() interface{} {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[0 : n-1]
	return x
}
func (h *hp) Push(x interface{}) {
	h.IntSlice = append(h.IntSlice, x.(int))
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class KthLargest {
    #k: number = 0;
    #minQ = new MinPriorityQueue();

    constructor(k: number, nums: number[]) {
        this.#k = k;
        for (const x of nums) {
            this.add(x);
        }
    }

    add(val: number): number {
        this.#minQ.enqueue(val);
        if (this.#minQ.size() > this.#k) {
            this.#minQ.dequeue();
        }
        return this.#minQ.front().element;
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function (k, nums) {
    this.k = k;
    this.minQ = new MinPriorityQueue();
    for (const x of nums) {
        this.add(x);
    }
};

/**
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function (val) {
    this.minQ.enqueue(val);
    if (this.minQ.size() > this.k) {
        this.minQ.dequeue();
    }
    return this.minQ.front().element;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个找到数据流中第 <code>k</code> 大元素的类（class）。注意是排序后的第 <code>k</code> 大元素，不是第 <code>k</code> 个不同的元素。</p>

<p>请实现 <code>KthLargest</code>&nbsp;类：</p>

<ul>
	<li><code>KthLargest(int k, int[] nums)</code> 使用整数 <code>k</code> 和整数流 <code>nums</code> 初始化对象。</li>
	<li><code>int add(int val)</code> 将 <code>val</code> 插入数据流 <code>nums</code> 后，返回当前数据流中第 <code>k</code> 大的元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><br />
<span class="example-io">["KthLargest", "add", "add", "add", "add", "add"]<br />
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]</span></p>

<p><strong>输出：</strong><span class="example-io">[null, 4, 5, 5, 8, 8]</span></p>

<p><strong>解释：</strong></p>

<p>KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);<br />
kthLargest.add(3); // 返回 4<br />
kthLargest.add(5); // 返回 5<br />
kthLargest.add(10); // 返回 5<br />
kthLargest.add(9); // 返回 8<br />
kthLargest.add(4); // 返回 8</p>

<p>&nbsp;</p>
</div>

<p><strong class="example">示例&nbsp;2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><br />
<span class="example-io">["KthLargest", "add", "add", "add", "add"]<br />
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]</span></p>

<p><span class="example-io"><b>输出：</b>[null, 7, 7, 7, 8]</span></p>

<p><strong>解释：</strong></p>
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);<br />
kthLargest.add(2); // 返回 7<br />
kthLargest.add(10); // 返回 7<br />
kthLargest.add(9); // 返回 7<br />
kthLargest.add(9); // 返回 8</div>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length + 1</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= val &lt;= 10<sup>4</sup></code></li>
	<li>最多调用 <code>add</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们维护一个优先队列（小根堆）$\textit{minQ}$。

初始化时，我们将数组 $\textit{nums}$ 中的元素依次加入 $\textit{minQ}$，并保持 $\textit{minQ}$ 的大小不超过 $k$。时间复杂度 $O(n \times \log k)$。

每次加入一个新元素时，如果 $\textit{minQ}$ 的大小超过了 $k$，我们就将堆顶元素弹出，保证 $\textit{minQ}$ 的大小为 $k$。时间复杂度 $O(\log k)$。

这样，$\textit{minQ}$ 中的元素就是数组 $\textit{nums}$ 中最大的 $k$ 个元素，堆顶元素就是第 $k$ 大的元素。

空间复杂度 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.min_q = []
        for x in nums:
            self.add(x)

    def add(self, val: int) -> int:
        heappush(self.min_q, val)
        if len(self.min_q) > self.k:
            heappop(self.min_q)
        return self.min_q[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```

#### Java

```java
class KthLargest {
    private PriorityQueue<Integer> minQ;
    private int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        minQ = new PriorityQueue<>(k);
        for (int x : nums) {
            add(x);
        }
    }

    public int add(int val) {
        minQ.offer(val);
        if (minQ.size() > k) {
            minQ.poll();
        }
        return minQ.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```

#### C++

```cpp
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        minQ.push(val);
        if (minQ.size() > k) {
            minQ.pop();
        }
        return minQ.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minQ;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

#### Go

```go
type KthLargest struct {
	k    int
	minQ hp
}

func Constructor(k int, nums []int) KthLargest {
	minQ := hp{}
	this := KthLargest{k, minQ}
	for _, x := range nums {
		this.Add(x)
	}
	return this
}

func (this *KthLargest) Add(val int) int {
	heap.Push(&this.minQ, val)
	if this.minQ.Len() > this.k {
		heap.Pop(&this.minQ)
	}
	return this.minQ.IntSlice[0]
}

type hp struct{ sort.IntSlice }

func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Pop() interface{} {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[0 : n-1]
	return x
}
func (h *hp) Push(x interface{}) {
	h.IntSlice = append(h.IntSlice, x.(int))
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
```

#### TypeScript

```ts
class KthLargest {
    #k: number = 0;
    #minQ = new MinPriorityQueue();

    constructor(k: number, nums: number[]) {
        this.#k = k;
        for (const x of nums) {
            this.add(x);
        }
    }

    add(val: number): number {
        this.#minQ.enqueue(val);
        if (this.#minQ.size() > this.#k) {
            this.#minQ.dequeue();
        }
        return this.#minQ.front().element;
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
```

#### JavaScript

```js
/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function (k, nums) {
    this.k = k;
    this.minQ = new MinPriorityQueue();
    for (const x of nums) {
        this.add(x);
    }
};

/**
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function (val) {
    this.minQ.enqueue(val);
    if (this.minQ.size() > this.k) {
        this.minQ.dequeue();
    }
    return this.minQ.front().element;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [704. 二分查找](https://leetcode.cn/problems/binary-search){#704}

{{< tabs "704" >}}

{{% tab "python" %}}
```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l if nums[l] == target else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func search(nums []int, target int) int {
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if nums[l] == target {
		return l
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function search(nums: number[], target: number): number {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l] === target ? l : -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: usize = 0;
        let mut r: usize = nums.len() - 1;
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] >= target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if nums[l] == target {
            l as i32
        } else {
            -1
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l] === target ? l : -1;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Search(int[] nums, int target) {
        int l = 0, r = nums.Length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个&nbsp;<code>n</code>&nbsp;个元素有序的（升序）整型数组&nbsp;<code>nums</code> 和一个目标值&nbsp;<code>target</code> &nbsp;，写一个函数搜索&nbsp;<code>nums</code>&nbsp;中的 <code>target</code>，如果&nbsp;<code>target</code> 存在返回下标，否则返回 <code>-1</code>。</p>

<p>你必须编写一个具有 <code>O(log n)</code> 时间复杂度的算法。</p>

<p><br />
<strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>输出:</strong> 4
<strong>解释:</strong> 9 出现在 <code>nums</code> 中并且下标为 4
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 2 不存在 <code>nums</code> 中因此返回 -1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>你可以假设 <code>nums</code>&nbsp;中的所有元素是不重复的。</li>
	<li><code>n</code>&nbsp;将在&nbsp;<code>[1, 10000]</code>之间。</li>
	<li><code>nums</code>&nbsp;的每个元素都将在&nbsp;<code>[-9999, 9999]</code>之间。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们定义二分查找的左边界 $l=0$，右边界 $r=n-1$。

每一次循环，我们计算中间位置 $\textit{mid}=(l+r)/2$，然后比较 $\textit{nums}[\textit{mid}]$ 和 $\textit{target}$ 的大小。

-   如果 $\textit{nums}[\textit{mid}] \geq \textit{target}$，说明 $\textit{target}$ 在左半部分，我们将右边界 $r$ 移动到 $\textit{mid}$；
-   否则，说明 $\textit{target}$ 在右半部分，我们将左边界 $l$ 移动到 $\textit{mid}+1$。

循环结束的条件是 $l<r$，此时 $\textit{nums}[l]$ 就是我们要找的目标值，如果 $\textit{nums}[l]=\textit{target}$，返回 $l$，否则返回 $-1$。

时间复杂度 $O(\log n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l if nums[l] == target else -1
```

#### Java

```java
class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
```

#### Go

```go
func search(nums []int, target int) int {
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if nums[l] == target {
		return l
	}
	return -1
}
```

#### TypeScript

```ts
function search(nums: number[], target: number): number {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l] === target ? l : -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: usize = 0;
        let mut r: usize = nums.len() - 1;
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] >= target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if nums[l] == target {
            l as i32
        } else {
            -1
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l] === target ? l : -1;
};
```

#### C#

```cs
public class Solution {
    public int Search(int[] nums, int target) {
        int l = 0, r = nums.Length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [705. 设计哈希集合](https://leetcode.cn/problems/design-hashset){#705}

{{< tabs "705" >}}

{{% tab "python" %}}
```python
class MyHashSet:
    def __init__(self):
        self.size = 1000
        self.data = [[] for _ in range(self.size)]

    def add(self, key: int) -> None:
        if self.contains(key):
            return
        idx = self.hash(key)
        self.data[idx].append(key)

    def remove(self, key: int) -> None:
        if not self.contains(key):
            return
        idx = self.hash(key)
        self.data[idx].remove(key)

    def contains(self, key: int) -> bool:
        idx = self.hash(key)
        return any(v == key for v in self.data[idx])

    def hash(self, key) -> int:
        return key % self.size


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyHashSet {
    private static final int SIZE = 1000;
    private LinkedList[] data;

    public MyHashSet() {
        data = new LinkedList[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            data[i] = new LinkedList<Integer>();
        }
    }

    public void add(int key) {
        if (contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].addFirst(key);
    }

    public void remove(int key) {
        if (!contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].remove(Integer.valueOf(key));
    }

    public boolean contains(int key) {
        int idx = hash(key);
        Iterator<Integer> it = data[idx].iterator();
        while (it.hasNext()) {
            Integer e = it.next();
            if (e == key) {
                return true;
            }
        }
        return false;
    }

    private int hash(int key) {
        return key % SIZE;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyHashSet {
private:
    int size = 1000;
    vector<list<int>> data;

public:
    MyHashSet()
        : data(size) {
    }

    void add(int key) {
        if (contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].push_back(key);
    }

    void remove(int key) {
        if (!contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].remove(key);
    }

    bool contains(int key) {
        int idx = hash(key);
        for (auto it = data[idx].begin(); it != data[idx].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }

    int hash(int key) {
        return key % size;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyHashSet struct {
	data []list.List
}

func Constructor() MyHashSet {
	return MyHashSet{make([]list.List, 1000)}
}

func (this *MyHashSet) Add(key int) {
	if this.Contains(key) {
		return
	}
	idx := this.hash(key)
	this.data[idx].PushBack(key)
}

func (this *MyHashSet) Remove(key int) {
	idx := this.hash(key)
	for e := this.data[idx].Front(); e != nil; e = e.Next() {
		if e.Value.(int) == key {
			this.data[idx].Remove(e)
		}
	}
}

func (this *MyHashSet) Contains(key int) bool {
	idx := this.hash(key)
	for e := this.data[idx].Front(); e != nil; e = e.Next() {
		if e.Value.(int) == key {
			return true
		}
	}
	return false
}

func (this *MyHashSet) hash(key int) int {
	return key % len(this.data)
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyHashSet {
    data: Array<boolean>;
    constructor() {
        this.data = new Array(10 ** 6 + 1).fill(false);
    }

    add(key: number): void {
        this.data[key] = true;
    }

    remove(key: number): void {
        this.data[key] = false;
    }

    contains(key: number): boolean {
        return this.data[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>不使用任何内建的哈希表库设计一个哈希集合（HashSet）。</p>

<p>实现 <code>MyHashSet</code> 类：</p>

<ul>
	<li><code>void add(key)</code> 向哈希集合中插入值 <code>key</code> 。</li>
	<li><code>bool contains(key)</code> 返回哈希集合中是否存在这个值 <code>key</code> 。</li>
	<li><code>void remove(key)</code> 将给定值 <code>key</code> 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。</li>
</ul>
&nbsp;

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
<strong>输出：</strong>
[null, null, null, true, false, null, true, null, false]

<strong>解释：</strong>
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key &lt;= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>add</code>、<code>remove</code> 和 <code>contains</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：静态数组实现

直接创建一个大小为 $1000001$ 的数组，初始时数组中的每个元素都为 `false`，表示哈希集合中不存在该元素。

往哈希集合添加元素时，将数组中对应位置的值置为 `true`；删除元素时，将数组中对应位置的值置为 `false`；当查询元素是否存在时，直接返回数组中对应位置的值即可。

以上操作的时间复杂度均为 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class MyHashSet:
    def __init__(self):
        self.data = [False] * 1000001

    def add(self, key: int) -> None:
        self.data[key] = True

    def remove(self, key: int) -> None:
        self.data[key] = False

    def contains(self, key: int) -> bool:
        return self.data[key]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```

#### Java

```java
class MyHashSet {
    private boolean[] data = new boolean[1000001];

    public MyHashSet() {
    }

    public void add(int key) {
        data[key] = true;
    }

    public void remove(int key) {
        data[key] = false;
    }

    public boolean contains(int key) {
        return data[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```

#### C++

```cpp
class MyHashSet {
public:
    bool data[1000001];

    MyHashSet() {
        memset(data, false, sizeof data);
    }

    void add(int key) {
        data[key] = true;
    }

    void remove(int key) {
        data[key] = false;
    }

    bool contains(int key) {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

#### Go

```go
type MyHashSet struct {
	data []bool
}

func Constructor() MyHashSet {
	data := make([]bool, 1000010)
	return MyHashSet{data}
}

func (this *MyHashSet) Add(key int) {
	this.data[key] = true
}

func (this *MyHashSet) Remove(key int) {
	this.data[key] = false
}

func (this *MyHashSet) Contains(key int) bool {
	return this.data[key]
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
```

#### TypeScript

```ts
class MyHashSet {
    data: Array<boolean>;
    constructor() {
        this.data = new Array(10 ** 6 + 1).fill(false);
    }

    add(key: number): void {
        this.data[key] = true;
    }

    remove(key: number): void {
        this.data[key] = false;
    }

    contains(key: number): boolean {
        return this.data[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数组嵌套链表

我们也可以开辟一个大小为 `SIZE=1000` 的数组，数组的每个位置是一个链表。

<!-- tabs:start -->

#### Python3

```python
class MyHashSet:
    def __init__(self):
        self.size = 1000
        self.data = [[] for _ in range(self.size)]

    def add(self, key: int) -> None:
        if self.contains(key):
            return
        idx = self.hash(key)
        self.data[idx].append(key)

    def remove(self, key: int) -> None:
        if not self.contains(key):
            return
        idx = self.hash(key)
        self.data[idx].remove(key)

    def contains(self, key: int) -> bool:
        idx = self.hash(key)
        return any(v == key for v in self.data[idx])

    def hash(self, key) -> int:
        return key % self.size


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```

#### Java

```java
class MyHashSet {
    private static final int SIZE = 1000;
    private LinkedList[] data;

    public MyHashSet() {
        data = new LinkedList[SIZE];
        for (int i = 0; i < SIZE; ++i) {
            data[i] = new LinkedList<Integer>();
        }
    }

    public void add(int key) {
        if (contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].addFirst(key);
    }

    public void remove(int key) {
        if (!contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].remove(Integer.valueOf(key));
    }

    public boolean contains(int key) {
        int idx = hash(key);
        Iterator<Integer> it = data[idx].iterator();
        while (it.hasNext()) {
            Integer e = it.next();
            if (e == key) {
                return true;
            }
        }
        return false;
    }

    private int hash(int key) {
        return key % SIZE;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```

#### C++

```cpp
class MyHashSet {
private:
    int size = 1000;
    vector<list<int>> data;

public:
    MyHashSet()
        : data(size) {
    }

    void add(int key) {
        if (contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].push_back(key);
    }

    void remove(int key) {
        if (!contains(key)) {
            return;
        }
        int idx = hash(key);
        data[idx].remove(key);
    }

    bool contains(int key) {
        int idx = hash(key);
        for (auto it = data[idx].begin(); it != data[idx].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }

    int hash(int key) {
        return key % size;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

#### Go

```go
type MyHashSet struct {
	data []list.List
}

func Constructor() MyHashSet {
	return MyHashSet{make([]list.List, 1000)}
}

func (this *MyHashSet) Add(key int) {
	if this.Contains(key) {
		return
	}
	idx := this.hash(key)
	this.data[idx].PushBack(key)
}

func (this *MyHashSet) Remove(key int) {
	idx := this.hash(key)
	for e := this.data[idx].Front(); e != nil; e = e.Next() {
		if e.Value.(int) == key {
			this.data[idx].Remove(e)
		}
	}
}

func (this *MyHashSet) Contains(key int) bool {
	idx := this.hash(key)
	for e := this.data[idx].Front(); e != nil; e = e.Next() {
		if e.Value.(int) == key {
			return true
		}
	}
	return false
}

func (this *MyHashSet) hash(key int) int {
	return key % len(this.data)
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [706. 设计哈希映射](https://leetcode.cn/problems/design-hashmap){#706}

{{< tabs "706" >}}

{{% tab "python" %}}
```python
class MyHashMap:
    def __init__(self):
        self.data = [-1] * 1000001

    def put(self, key: int, value: int) -> None:
        self.data[key] = value

    def get(self, key: int) -> int:
        return self.data[key]

    def remove(self, key: int) -> None:
        self.data[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyHashMap {
    private int[] data = new int[1000001];

    public MyHashMap() {
        Arrays.fill(data, -1);
    }

    public void put(int key, int value) {
        data[key] = value;
    }

    public int get(int key) {
        return data[key];
    }

    public void remove(int key) {
        data[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyHashMap {
public:
    int data[1000001];

    MyHashMap() {
        memset(data, -1, sizeof data);
    }

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyHashMap struct {
	data []int
}

func Constructor() MyHashMap {
	data := make([]int, 1000010)
	for i := range data {
		data[i] = -1
	}
	return MyHashMap{data}
}

func (this *MyHashMap) Put(key int, value int) {
	this.data[key] = value
}

func (this *MyHashMap) Get(key int) int {
	return this.data[key]
}

func (this *MyHashMap) Remove(key int) {
	this.data[key] = -1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyHashMap {
    data: Array<number>;
    constructor() {
        this.data = new Array(10 ** 6 + 1).fill(-1);
    }

    put(key: number, value: number): void {
        this.data[key] = value;
    }

    get(key: number): number {
        return this.data[key];
    }

    remove(key: number): void {
        this.data[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>不使用任何内建的哈希表库设计一个哈希映射（HashMap）。</p>

<p>实现 <code>MyHashMap</code> 类：</p>

<ul>
	<li><code>MyHashMap()</code> 用空映射初始化对象</li>
	<li><code>void put(int key, int value)</code> 向 HashMap 插入一个键值对 <code>(key, value)</code> 。如果 <code>key</code> 已经存在于映射中，则更新其对应的值 <code>value</code> 。</li>
	<li><code>int get(int key)</code> 返回特定的 <code>key</code> 所映射的 <code>value</code> ；如果映射中不包含 <code>key</code> 的映射，返回 <code>-1</code> 。</li>
	<li><code>void remove(key)</code> 如果映射中存在 <code>key</code> 的映射，则移除 <code>key</code> 和它所对应的 <code>value</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>：
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
<strong>输出</strong>：
[null, null, null, 1, -1, null, 1, null, -1]

<strong>解释</strong>：
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>put</code>、<code>get</code> 和 <code>remove</code> 方法</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：静态数组实现

直接创建一个大小为 $1000001$ 的数组，初始时数组中的每个元素都为 $-1$，表示哈希表中不存在该键值对。

调用 `put` 方法时，将数组中对应的位置赋值为 `value`；调用 `get` 方法时，返回数组中对应的位置的值；调用 `remove` 方法时，将数组中对应的位置赋值为 $-1$。

以上操作，时间复杂度均为 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class MyHashMap:
    def __init__(self):
        self.data = [-1] * 1000001

    def put(self, key: int, value: int) -> None:
        self.data[key] = value

    def get(self, key: int) -> int:
        return self.data[key]

    def remove(self, key: int) -> None:
        self.data[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
```

#### Java

```java
class MyHashMap {
    private int[] data = new int[1000001];

    public MyHashMap() {
        Arrays.fill(data, -1);
    }

    public void put(int key, int value) {
        data[key] = value;
    }

    public int get(int key) {
        return data[key];
    }

    public void remove(int key) {
        data[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
```

#### C++

```cpp
class MyHashMap {
public:
    int data[1000001];

    MyHashMap() {
        memset(data, -1, sizeof data);
    }

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```

#### Go

```go
type MyHashMap struct {
	data []int
}

func Constructor() MyHashMap {
	data := make([]int, 1000010)
	for i := range data {
		data[i] = -1
	}
	return MyHashMap{data}
}

func (this *MyHashMap) Put(key int, value int) {
	this.data[key] = value
}

func (this *MyHashMap) Get(key int) int {
	return this.data[key]
}

func (this *MyHashMap) Remove(key int) {
	this.data[key] = -1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
```

#### TypeScript

```ts
class MyHashMap {
    data: Array<number>;
    constructor() {
        this.data = new Array(10 ** 6 + 1).fill(-1);
    }

    put(key: number, value: number): void {
        this.data[key] = value;
    }

    get(key: number): number {
        return this.data[key];
    }

    remove(key: number): void {
        this.data[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [707. 设计链表](https://leetcode.cn/problems/design-linked-list){#707}

{{< tabs "707" >}}

{{% tab "python" %}}
```python
class MyLinkedList:
    def __init__(self):
        self.e = [0] * 1010
        self.ne = [0] * 1010
        self.idx = 0
        self.head = -1
        self.cnt = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.cnt:
            return -1
        i = self.head
        for _ in range(index):
            i = self.ne[i]
        return self.e[i]

    def addAtHead(self, val: int) -> None:
        self.e[self.idx] = val
        self.ne[self.idx] = self.head
        self.head = self.idx
        self.idx += 1
        self.cnt += 1

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.cnt, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.cnt:
            return
        if index <= 0:
            self.addAtHead(val)
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.e[self.idx] = val
        self.ne[self.idx] = self.ne[i]
        self.ne[i] = self.idx
        self.idx += 1
        self.cnt += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.cnt:
            return -1
        self.cnt -= 1
        if index == 0:
            self.head = self.ne[self.head]
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.ne[i] = self.ne[self.ne[i]]


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyLinkedList {
    private int[] e = new int[1010];
    private int[] ne = new int[1010];
    private int head = -1;
    private int idx;
    private int cnt;

    public MyLinkedList() {
    }

    public int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index-- > 0) {
            i = ne[i];
        }
        return e[i];
    }

    public void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    public void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyLinkedList {
private:
    int e[1010], ne[1010];
    int head = -1, idx = 0, cnt = 0;

public:
    MyLinkedList() {
    }

    int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index--) {
            i = ne[i];
        }
        return e[i];
    }

    void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyLinkedList struct {
	e    []int
	ne   []int
	idx  int
	head int
	cnt  int
}

func Constructor() MyLinkedList {
	e := make([]int, 1010)
	ne := make([]int, 1010)
	return MyLinkedList{e, ne, 0, -1, 0}
}

func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.cnt {
		return -1
	}
	i := this.head
	for ; index > 0; index-- {
		i = this.ne[i]
	}
	return this.e[i]
}

func (this *MyLinkedList) AddAtHead(val int) {
	this.e[this.idx] = val
	this.ne[this.idx] = this.head
	this.head = this.idx
	this.idx++
	this.cnt++
}

func (this *MyLinkedList) AddAtTail(val int) {
	this.AddAtIndex(this.cnt, val)
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.cnt {
		return
	}
	if index <= 0 {
		this.AddAtHead(val)
		return
	}
	i := this.head
	for ; index > 1; index-- {
		i = this.ne[i]
	}
	this.e[this.idx] = val
	this.ne[this.idx] = this.ne[i]
	this.ne[i] = this.idx
	this.idx++
	this.cnt++
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= this.cnt {
		return
	}
	this.cnt--
	if index == 0 {
		this.head = this.ne[this.head]
		return
	}
	i := this.head
	for ; index > 1; index-- {
		i = this.ne[i]
	}
	this.ne[i] = this.ne[this.ne[i]]
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyLinkedList {
    e: Array<number>;
    ne: Array<number>;
    idx: number;
    head: number;
    cnt: number;

    constructor() {
        this.e = new Array(1010).fill(0);
        this.ne = new Array(1010).fill(0);
        this.head = -1;
        this.idx = 0;
        this.cnt = 0;
    }

    get(index: number): number {
        if (index < 0 || index >= this.cnt) {
            return -1;
        }
        let i = this.head;
        while (index--) {
            i = this.ne[i];
        }
        return this.e[i];
    }

    addAtHead(val: number): void {
        this.e[this.idx] = val;
        this.ne[this.idx] = this.head;
        this.head = this.idx++;
        this.cnt++;
    }

    addAtTail(val: number): void {
        this.addAtIndex(this.cnt, val);
    }

    addAtIndex(index: number, val: number): void {
        if (index > this.cnt) {
            return;
        }
        if (index <= 0) {
            this.addAtHead(val);
            return;
        }
        let i = this.head;
        while (--index) {
            i = this.ne[i];
        }
        this.e[this.idx] = val;
        this.ne[this.idx] = this.ne[i];
        this.ne[i] = this.idx++;
        this.cnt++;
    }

    deleteAtIndex(index: number): void {
        if (index < 0 || index >= this.cnt) {
            return;
        }
        this.cnt--;
        if (index == 0) {
            this.head = this.ne[this.head];
            return;
        }
        let i = this.head;
        while (--index) {
            i = this.ne[i];
        }
        this.ne[i] = this.ne[this.ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
#[derive(Default)]
struct MyLinkedList {
    head: Option<Box<ListNode>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {
    fn new() -> Self {
        Default::default()
    }

    fn get(&self, mut index: i32) -> i32 {
        if self.head.is_none() {
            return -1;
        }
        let mut cur = self.head.as_ref().unwrap();
        while index > 0 {
            match cur.next {
                None => {
                    return -1;
                }
                Some(ref next) => {
                    cur = next;
                    index -= 1;
                }
            }
        }
        cur.val
    }

    fn add_at_head(&mut self, val: i32) {
        self.head = Some(Box::new(ListNode {
            val,
            next: self.head.take(),
        }));
    }

    fn add_at_tail(&mut self, val: i32) {
        let new_node = Some(Box::new(ListNode { val, next: None }));
        if self.head.is_none() {
            self.head = new_node;
            return;
        }
        let mut cur = self.head.as_mut().unwrap();
        while let Some(ref mut next) = cur.next {
            cur = next;
        }
        cur.next = new_node;
    }

    fn add_at_index(&mut self, mut index: i32, val: i32) {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: self.head.take(),
        });
        let mut cur = &mut dummy;
        while index > 0 {
            if cur.next.is_none() {
                return;
            }
            cur = cur.next.as_mut().unwrap();
            index -= 1;
        }
        cur.next = Some(Box::new(ListNode {
            val,
            next: cur.next.take(),
        }));
        self.head = dummy.next;
    }

    fn delete_at_index(&mut self, mut index: i32) {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: self.head.take(),
        });
        let mut cur = &mut dummy;
        while index > 0 {
            if let Some(ref mut next) = cur.next {
                cur = next;
            }
            index -= 1;
        }
        cur.next = cur.next.take().and_then(|n| n.next);
        self.head = dummy.next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你可以选择使用单链表或者双链表，设计并实现自己的链表。</p>

<p>单链表中的节点应该具备两个属性：<code>val</code> 和 <code>next</code> 。<code>val</code> 是当前节点的值，<code>next</code> 是指向下一个节点的指针/引用。</p>

<p>如果是双向链表，则还需要属性&nbsp;<code>prev</code>&nbsp;以指示链表中的上一个节点。假设链表中的所有节点下标从 <strong>0</strong> 开始。</p>

<p>实现 <code>MyLinkedList</code> 类：</p>

<ul>
	<li><code>MyLinkedList()</code> 初始化 <code>MyLinkedList</code> 对象。</li>
	<li><code>int get(int index)</code> 获取链表中下标为 <code>index</code> 的节点的值。如果下标无效，则返回 <code>-1</code> 。</li>
	<li><code>void addAtHead(int val)</code> 将一个值为 <code>val</code> 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。</li>
	<li><code>void addAtTail(int val)</code> 将一个值为 <code>val</code> 的节点追加到链表中作为链表的最后一个元素。</li>
	<li><code>void addAtIndex(int index, int val)</code> 将一个值为 <code>val</code> 的节点插入到链表中下标为 <code>index</code> 的节点之前。如果 <code>index</code> 等于链表的长度，那么该节点会被追加到链表的末尾。如果 <code>index</code> 比长度更大，该节点将 <strong>不会插入</strong> 到链表中。</li>
	<li><code>void deleteAtIndex(int index)</code> 如果下标有效，则删除链表中下标为 <code>index</code> 的节点。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入</strong>
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
<strong>输出</strong>
[null, null, null, null, 2, null, 3]

<strong>解释</strong>
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1-&gt;2-&gt;3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1-&gt;3
myLinkedList.get(1);              // 返回 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= index, val &lt;= 1000</code></li>
	<li>请不要使用内置的 LinkedList 库。</li>
	<li>调用 <code>get</code>、<code>addAtHead</code>、<code>addAtTail</code>、<code>addAtIndex</code> 和 <code>deleteAtIndex</code> 的次数不超过 <code>2000</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：指针引用实现单链表

我们创建链表虚拟头节点 `dummy`，用变量 `cnt` 记录当前链表节点个数。

具体的方法如下：

-   `get(index)`：遍历链表，找到第 `index` 个节点，返回其值，如果不存在，返回 $-1$。时间复杂度 $O(n)$。
-   `addAtHead(val)`：创建新节点，将其插入到虚拟头节点后面。时间复杂度 $O(1)$。
-   `addAtTail(val)`：创建新节点，将其插入到链表尾部。时间复杂度 $O(n)$。
-   `addAtIndex(index, val)`：如果 `index` 等于链表长度，则该节点将附加到链表的末尾。如果 `index` 大于链表长度，则不会插入节点。如果 `index` 小于 $0$，则在头部插入节点。否则，遍历链表，找到第 `index` 个节点的前一个节点，将新节点插入到该节点后面。时间复杂度 $O(n)$。
-   `deleteAtIndex(index)`：如果索引 `index` 有效，则删除链表中的第 `index` 个节点。否则，不做任何操作。时间复杂度 $O(n)$。

时间复杂度见具体的方法说明。其中 $n$ 为链表长度。

注意：LeetCode 平台已经内置 ListNode 单链表节点类，可以直接使用。

<!-- tabs:start -->

#### Python3

```python
class MyLinkedList:
    def __init__(self):
        self.dummy = ListNode()
        self.cnt = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.cnt:
            return -1
        cur = self.dummy.next
        for _ in range(index):
            cur = cur.next
        return cur.val

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.cnt, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.cnt:
            return
        pre = self.dummy
        for _ in range(index):
            pre = pre.next
        pre.next = ListNode(val, pre.next)
        self.cnt += 1

    def deleteAtIndex(self, index: int) -> None:
        if index >= self.cnt:
            return
        pre = self.dummy
        for _ in range(index):
            pre = pre.next
        t = pre.next
        pre.next = t.next
        t.next = None
        self.cnt -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```

#### Java

```java
class MyLinkedList {
    private ListNode dummy = new ListNode();
    private int cnt;

    public MyLinkedList() {
    }

    public int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        var cur = dummy.next;
        while (index-- > 0) {
            cur = cur.next;
        }
        return cur.val;
    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        var pre = dummy;
        while (index-- > 0) {
            pre = pre.next;
        }
        pre.next = new ListNode(val, pre.next);
        ++cnt;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        var pre = dummy;
        while (index-- > 0) {
            pre = pre.next;
        }
        var t = pre.next;
        pre.next = t.next;
        t.next = null;
        --cnt;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```

#### C++

```cpp
class MyLinkedList {
private:
    ListNode* dummy = new ListNode();
    int cnt = 0;

public:
    MyLinkedList() {
    }

    int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        auto cur = dummy->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        auto pre = dummy;
        while (index-- > 0) {
            pre = pre->next;
        }
        pre->next = new ListNode(val, pre->next);
        ++cnt;
    }

    void deleteAtIndex(int index) {
        if (index >= cnt) {
            return;
        }
        auto pre = dummy;
        while (index-- > 0) {
            pre = pre->next;
        }
        auto t = pre->next;
        pre->next = t->next;
        t->next = nullptr;
        --cnt;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

#### Go

```go
type MyLinkedList struct {
	dummy *ListNode
	cnt   int
}

func Constructor() MyLinkedList {
	return MyLinkedList{&ListNode{}, 0}
}

func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.cnt {
		return -1
	}
	cur := this.dummy.Next
	for ; index > 0; index-- {
		cur = cur.Next
	}
	return cur.Val
}

func (this *MyLinkedList) AddAtHead(val int) {
	this.AddAtIndex(0, val)
}

func (this *MyLinkedList) AddAtTail(val int) {
	this.AddAtIndex(this.cnt, val)
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.cnt {
		return
	}
	pre := this.dummy
	for ; index > 0; index-- {
		pre = pre.Next
	}
	pre.Next = &ListNode{val, pre.Next}
	this.cnt++
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= this.cnt {
		return
	}
	pre := this.dummy
	for ; index > 0; index-- {
		pre = pre.Next
	}
	t := pre.Next
	pre.Next = t.Next
	t.Next = nil
	this.cnt--
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
```

#### TypeScript

```ts
class LinkNode {
    public val: number;
    public next: LinkNode;

    constructor(val: number, next: LinkNode = null) {
        this.val = val;
        this.next = next;
    }
}

class MyLinkedList {
    public head: LinkNode;

    constructor() {
        this.head = null;
    }

    get(index: number): number {
        if (this.head == null) {
            return -1;
        }
        let cur = this.head;
        let idxCur = 0;
        while (idxCur < index) {
            if (cur.next == null) {
                return -1;
            }
            cur = cur.next;
            idxCur++;
        }
        return cur.val;
    }

    addAtHead(val: number): void {
        this.head = new LinkNode(val, this.head);
    }

    addAtTail(val: number): void {
        const newNode = new LinkNode(val);
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        let cur = this.head;
        while (cur.next != null) {
            cur = cur.next;
        }
        cur.next = newNode;
    }

    addAtIndex(index: number, val: number): void {
        if (index <= 0) {
            return this.addAtHead(val);
        }
        const dummy = new LinkNode(0, this.head);
        let cur = dummy;
        let idxCur = 0;
        while (idxCur < index) {
            if (cur.next == null) {
                return;
            }
            cur = cur.next;
            idxCur++;
        }
        cur.next = new LinkNode(val, cur.next || null);
    }

    deleteAtIndex(index: number): void {
        if (index == 0) {
            this.head = (this.head || {}).next;
            return;
        }
        const dummy = new LinkNode(0, this.head);
        let cur = dummy;
        let idxCur = 0;
        while (idxCur < index) {
            if (cur.next == null) {
                return;
            }
            cur = cur.next;
            idxCur++;
        }
        cur.next = (cur.next || {}).next;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
```

#### Rust

```rust
#[derive(Default)]
struct MyLinkedList {
    head: Option<Box<ListNode>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {
    fn new() -> Self {
        Default::default()
    }

    fn get(&self, mut index: i32) -> i32 {
        if self.head.is_none() {
            return -1;
        }
        let mut cur = self.head.as_ref().unwrap();
        while index > 0 {
            match cur.next {
                None => {
                    return -1;
                }
                Some(ref next) => {
                    cur = next;
                    index -= 1;
                }
            }
        }
        cur.val
    }

    fn add_at_head(&mut self, val: i32) {
        self.head = Some(Box::new(ListNode {
            val,
            next: self.head.take(),
        }));
    }

    fn add_at_tail(&mut self, val: i32) {
        let new_node = Some(Box::new(ListNode { val, next: None }));
        if self.head.is_none() {
            self.head = new_node;
            return;
        }
        let mut cur = self.head.as_mut().unwrap();
        while let Some(ref mut next) = cur.next {
            cur = next;
        }
        cur.next = new_node;
    }

    fn add_at_index(&mut self, mut index: i32, val: i32) {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: self.head.take(),
        });
        let mut cur = &mut dummy;
        while index > 0 {
            if cur.next.is_none() {
                return;
            }
            cur = cur.next.as_mut().unwrap();
            index -= 1;
        }
        cur.next = Some(Box::new(ListNode {
            val,
            next: cur.next.take(),
        }));
        self.head = dummy.next;
    }

    fn delete_at_index(&mut self, mut index: i32) {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: self.head.take(),
        });
        let mut cur = &mut dummy;
        while index > 0 {
            if let Some(ref mut next) = cur.next {
                cur = next;
            }
            index -= 1;
        }
        cur.next = cur.next.take().and_then(|n| n.next);
        self.head = dummy.next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：静态数组实现单链表

在方法一中，我们使用了指针引用的方式，每次动态创建一个链表节点。在链表节点数量达到 $10^5$ 甚至更大时，频繁执行 new 操作，会大大增加程序的执行耗时。

因此，我们可以使用静态数组来实现单链表，预先申请一块大小略大于数据范围的内存空间，每次插入节点时，从数组中取出一个空闲的位置，将新节点插入到该位置，同时更新该位置的前驱和后继节点的指针引用。

我们定义以下几个变量，其中：

-   `head` 存放链表头节点的索引，初始时指向 $-1$。
-   `e` 存放链表所有节点的值（预先申请）。
-   `ne` 存放链表所有节点的 `next` 指针（预先申请）。
-   `idx` 指向当前可分配的节点索引，初始时指向索引 $0$。
-   `cnt` 记录当前链表节点个数，初始时为 $0$。

具体操作可参考以下代码。时间复杂度与方法一相同。

<!-- tabs:start -->

#### Python3

```python
class MyLinkedList:
    def __init__(self):
        self.e = [0] * 1010
        self.ne = [0] * 1010
        self.idx = 0
        self.head = -1
        self.cnt = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.cnt:
            return -1
        i = self.head
        for _ in range(index):
            i = self.ne[i]
        return self.e[i]

    def addAtHead(self, val: int) -> None:
        self.e[self.idx] = val
        self.ne[self.idx] = self.head
        self.head = self.idx
        self.idx += 1
        self.cnt += 1

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.cnt, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.cnt:
            return
        if index <= 0:
            self.addAtHead(val)
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.e[self.idx] = val
        self.ne[self.idx] = self.ne[i]
        self.ne[i] = self.idx
        self.idx += 1
        self.cnt += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.cnt:
            return -1
        self.cnt -= 1
        if index == 0:
            self.head = self.ne[self.head]
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.ne[i] = self.ne[self.ne[i]]


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```

#### Java

```java
class MyLinkedList {
    private int[] e = new int[1010];
    private int[] ne = new int[1010];
    private int head = -1;
    private int idx;
    private int cnt;

    public MyLinkedList() {
    }

    public int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index-- > 0) {
            i = ne[i];
        }
        return e[i];
    }

    public void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    public void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```

#### C++

```cpp
class MyLinkedList {
private:
    int e[1010], ne[1010];
    int head = -1, idx = 0, cnt = 0;

public:
    MyLinkedList() {
    }

    int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index--) {
            i = ne[i];
        }
        return e[i];
    }

    void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

#### Go

```go
type MyLinkedList struct {
	e    []int
	ne   []int
	idx  int
	head int
	cnt  int
}

func Constructor() MyLinkedList {
	e := make([]int, 1010)
	ne := make([]int, 1010)
	return MyLinkedList{e, ne, 0, -1, 0}
}

func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.cnt {
		return -1
	}
	i := this.head
	for ; index > 0; index-- {
		i = this.ne[i]
	}
	return this.e[i]
}

func (this *MyLinkedList) AddAtHead(val int) {
	this.e[this.idx] = val
	this.ne[this.idx] = this.head
	this.head = this.idx
	this.idx++
	this.cnt++
}

func (this *MyLinkedList) AddAtTail(val int) {
	this.AddAtIndex(this.cnt, val)
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.cnt {
		return
	}
	if index <= 0 {
		this.AddAtHead(val)
		return
	}
	i := this.head
	for ; index > 1; index-- {
		i = this.ne[i]
	}
	this.e[this.idx] = val
	this.ne[this.idx] = this.ne[i]
	this.ne[i] = this.idx
	this.idx++
	this.cnt++
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= this.cnt {
		return
	}
	this.cnt--
	if index == 0 {
		this.head = this.ne[this.head]
		return
	}
	i := this.head
	for ; index > 1; index-- {
		i = this.ne[i]
	}
	this.ne[i] = this.ne[this.ne[i]]
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
```

#### TypeScript

```ts
class MyLinkedList {
    e: Array<number>;
    ne: Array<number>;
    idx: number;
    head: number;
    cnt: number;

    constructor() {
        this.e = new Array(1010).fill(0);
        this.ne = new Array(1010).fill(0);
        this.head = -1;
        this.idx = 0;
        this.cnt = 0;
    }

    get(index: number): number {
        if (index < 0 || index >= this.cnt) {
            return -1;
        }
        let i = this.head;
        while (index--) {
            i = this.ne[i];
        }
        return this.e[i];
    }

    addAtHead(val: number): void {
        this.e[this.idx] = val;
        this.ne[this.idx] = this.head;
        this.head = this.idx++;
        this.cnt++;
    }

    addAtTail(val: number): void {
        this.addAtIndex(this.cnt, val);
    }

    addAtIndex(index: number, val: number): void {
        if (index > this.cnt) {
            return;
        }
        if (index <= 0) {
            this.addAtHead(val);
            return;
        }
        let i = this.head;
        while (--index) {
            i = this.ne[i];
        }
        this.e[this.idx] = val;
        this.ne[this.idx] = this.ne[i];
        this.ne[i] = this.idx++;
        this.cnt++;
    }

    deleteAtIndex(index: number): void {
        if (index < 0 || index >= this.cnt) {
            return;
        }
        this.cnt--;
        if (index == 0) {
            this.head = this.ne[this.head];
            return;
        }
        let i = this.head;
        while (--index) {
            i = this.ne[i];
        }
        this.ne[i] = this.ne[this.ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [708. 循环有序列表的插入 🔒](https://leetcode.cn/problems/insert-into-a-sorted-circular-linked-list){#708}

{{< tabs "708" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""


class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        node = Node(insertVal)
        if head is None:
            node.next = node
            return node
        prev, curr = head, head.next
        while curr != head:
            if prev.val <= insertVal <= curr.val or (
                prev.val > curr.val and (insertVal >= prev.val or insertVal <= curr.val)
            ):
                break
            prev, curr = curr, curr.next
        prev.next = node
        node.next = curr
        return head
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    public Node insert(Node head, int insertVal) {
        Node node = new Node(insertVal);
        if (head == null) {
            node.next = node;
            return node;
        }
        Node prev = head, curr = head.next;
        while (curr != head) {
            if ((prev.val <= insertVal && insertVal <= curr.val)
                || (prev.val > curr.val && (insertVal >= prev.val || insertVal <= curr.val))) {
                break;
            }
            prev = curr;
            curr = curr.next;
        }
        prev.next = node;
        node.next = curr;
        return head;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }
        Node *prev = head, *curr = head->next;
        while (curr != head) {
            if ((prev->val <= insertVal && insertVal <= curr->val) || (prev->val > curr->val && (insertVal >= prev->val || insertVal <= curr->val))) break;
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
        return head;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 * }
 */

func insert(head *Node, x int) *Node {
	node := &Node{Val: x}
	if head == nil {
		node.Next = node
		return node
	}
	prev, curr := head, head.Next
	for curr != head {
		if (prev.Val <= x && x <= curr.Val) || (prev.Val > curr.Val && (x >= prev.Val || x <= curr.Val)) {
			break
		}
		prev, curr = curr, curr.Next
	}
	prev.Next = node
	node.Next = curr
	return head
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定<strong>循环单调非递减列表</strong>中的一个点，写一个函数向这个列表中插入一个新元素&nbsp;<code>insertVal</code> ，使这个列表仍然是循环非降序的。</p>

<p>给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。</p>

<p>如果有多个满足条件的插入位置，你可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。</p>

<p>如果列表为空（给定的节点是 <code>null</code>），你需要创建一个循环有序列表并返回这个节点。否则，请返回原先给定的节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0708.Insert%20into%20a%20Sorted%20Circular%20Linked%20List/images/example_1_before_65p.jpg" style="height: 149px; width: 250px;" /><br />
&nbsp;
<pre>
<strong>输入：</strong>head = [3,4,1], insertVal = 2
<strong>输出：</strong>[3,4,1,2]
<strong>解释：</strong>在上图中，有一个包含三个元素的循环有序列表，你获得值为 3 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3 之间，插入之后，整个列表如上图所示，最后返回节点 3 。

<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0708.Insert%20into%20a%20Sorted%20Circular%20Linked%20List/images/example_1_after_65p.jpg" style="height: 149px; width: 250px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [], insertVal = 1
<strong>输出：</strong>[1]
<strong>解释：</strong>列表为空（给定的节点是 <code>null</code>），创建一个循环有序列表并返回这个节点。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1], insertVal = 0
<strong>输出：</strong>[1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= Number of Nodes &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= Node.val, insertVal &lt;= 10<sup>6</sup></code></li>
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
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""


class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        node = Node(insertVal)
        if head is None:
            node.next = node
            return node
        prev, curr = head, head.next
        while curr != head:
            if prev.val <= insertVal <= curr.val or (
                prev.val > curr.val and (insertVal >= prev.val or insertVal <= curr.val)
            ):
                break
            prev, curr = curr, curr.next
        prev.next = node
        node.next = curr
        return head
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    public Node insert(Node head, int insertVal) {
        Node node = new Node(insertVal);
        if (head == null) {
            node.next = node;
            return node;
        }
        Node prev = head, curr = head.next;
        while (curr != head) {
            if ((prev.val <= insertVal && insertVal <= curr.val)
                || (prev.val > curr.val && (insertVal >= prev.val || insertVal <= curr.val))) {
                break;
            }
            prev = curr;
            curr = curr.next;
        }
        prev.next = node;
        node.next = curr;
        return head;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }
        Node *prev = head, *curr = head->next;
        while (curr != head) {
            if ((prev->val <= insertVal && insertVal <= curr->val) || (prev->val > curr->val && (insertVal >= prev->val || insertVal <= curr->val))) break;
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
        return head;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 * }
 */

func insert(head *Node, x int) *Node {
	node := &Node{Val: x}
	if head == nil {
		node.Next = node
		return node
	}
	prev, curr := head, head.Next
	for curr != head {
		if (prev.Val <= x && x <= curr.Val) || (prev.Val > curr.Val && (x >= prev.Val || x <= curr.Val)) {
			break
		}
		prev, curr = curr, curr.Next
	}
	prev.Next = node
	node.Next = curr
	return head
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [709. 转换成小写字母](https://leetcode.cn/problems/to-lower-case){#709}

{{< tabs "709" >}}

{{% tab "python" %}}
```python
class Solution:
    def toLowerCase(self, s: str) -> str:
        return "".join([chr(ord(c) | 32) if c.isupper() else c for c in s])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String toLowerCase(String s) {
        char[] cs = s.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
            if (cs[i] >= 'A' && cs[i] <= 'Z') {
                cs[i] |= 32;
            }
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c |= 32;
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func toLowerCase(s string) string {
	cs := []byte(s)
	for i, c := range cs {
		if c >= 'A' && c <= 'Z' {
			cs[i] |= 32
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function toLowerCase(s: string): string {
    return [...s].map(c => String.fromCharCode(c.charCodeAt(0) | 32)).join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn to_lower_case(s: String) -> String {
        s.as_bytes()
            .iter()
            .map(|&c| char::from(if c >= b'A' && c <= b'Z' { c | 32 } else { c }))
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* toLowerCase(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] |= 32;
        }
    }
    return s;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "Hello"
<strong>输出：</strong>"hello"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "here"
<strong>输出：</strong>"here"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "LOVELY"
<strong>输出：</strong>"lovely"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 100</code></li>
	<li><code>s</code> 由 ASCII 字符集中的可打印字符组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以遍历字符串，对于每个大写字母，将其转换为小写字母。最后返回转换后的字符串即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def toLowerCase(self, s: str) -> str:
        return "".join([chr(ord(c) | 32) if c.isupper() else c for c in s])
```

#### Java

```java
class Solution {
    public String toLowerCase(String s) {
        char[] cs = s.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
            if (cs[i] >= 'A' && cs[i] <= 'Z') {
                cs[i] |= 32;
            }
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c |= 32;
            }
        }
        return s;
    }
};
```

#### Go

```go
func toLowerCase(s string) string {
	cs := []byte(s)
	for i, c := range cs {
		if c >= 'A' && c <= 'Z' {
			cs[i] |= 32
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function toLowerCase(s: string): string {
    return s.toLowerCase();
}
```

#### Rust

```rust
impl Solution {
    pub fn to_lower_case(s: String) -> String {
        s.to_ascii_lowercase()
    }
}
```

#### C

```c
char* toLowerCase(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] |= 32;
        }
    }
    return s;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function toLowerCase(s: string): string {
    return [...s].map(c => String.fromCharCode(c.charCodeAt(0) | 32)).join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn to_lower_case(s: String) -> String {
        s.as_bytes()
            .iter()
            .map(|&c| char::from(if c >= b'A' && c <= b'Z' { c | 32 } else { c }))
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
