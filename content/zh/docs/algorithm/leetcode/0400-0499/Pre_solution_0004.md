---
title: "0430_扁平化多级双向链表"
date: 2025-10-08T18:36:10+08:00
weight: 4
tags: [二分查找, 二叉树, 动态规划, 双向链表, 哈希表, 字符串, 广度优先搜索, 排序, 数组, 栈, 树, 深度优先搜索, 滑动窗口, 设计, 贪心, 递归, 链表]
---

{{< markmap >}}
### [0430_扁平化多级双向链表](#430)
#### [深度优先搜索](#430)
#### [链表](#430)
#### [双向链表](#430)
### [0431_将 N 叉树编码为二叉树 🔒](#431)
#### [树](#431)
#### [深度优先搜索](#431)
#### [广度优先搜索](#431)
#### [设计](#431)
#### [二叉树](#431)
### [0432_全 O(1) 的数据结构](#432)
#### [设计](#432)
#### [哈希表](#432)
#### [链表](#432)
#### [双向链表](#432)
### [0433_最小基因变化](#433)
#### [广度优先搜索](#433)
#### [哈希表](#433)
#### [字符串](#433)
### [0434_字符串中的单词数](#434)
#### [字符串](#434)
### [0435_无重叠区间](#435)
#### [贪心](#435)
#### [数组](#435)
#### [动态规划](#435)
#### [排序](#435)
### [0436_寻找右区间](#436)
#### [数组](#436)
#### [二分查找](#436)
#### [排序](#436)
### [0437_路径总和 III](#437)
#### [树](#437)
#### [深度优先搜索](#437)
#### [二叉树](#437)
### [0438_找到字符串中所有字母异位词](#438)
#### [哈希表](#438)
#### [字符串](#438)
#### [滑动窗口](#438)
### [0439_三元表达式解析器 🔒](#439)
#### [栈](#439)
#### [递归](#439)
#### [字符串](#439)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0430_扁平化多级双向链表
___
#### 深度优先搜索
___
#### 链表
___
#### 双向链表
---
### 0431_将 N 叉树编码为二叉树 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 设计
___
#### 二叉树
---
### 0432_全 O(1) 的数据结构
___
#### 设计
___
#### 哈希表
___
#### 链表
___
#### 双向链表
---
### 0433_最小基因变化
___
#### 广度优先搜索
___
#### 哈希表
___
#### 字符串
---
### 0434_字符串中的单词数
___
#### 字符串
---
### 0435_无重叠区间
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 0436_寻找右区间
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 0437_路径总和 III
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0438_找到字符串中所有字母异位词
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 0439_三元表达式解析器 🔒
___
#### 栈
___
#### 递归
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 双向链表 | 哈希表 | 字符串 |
| 广度优先搜索 | 排序 | 数组 |
| 栈 | 树 | 深度优先搜索 |
| 滑动窗口 | 设计 | 贪心 |
| 递归 | 链表 |  |

# [430. 扁平化多级双向链表](https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list){#430}

{{< tabs "430" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""


class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def preorder(pre, cur):
            if cur is None:
                return pre
            cur.prev = pre
            pre.next = cur

            t = cur.next
            tail = preorder(cur, cur.child)
            cur.child = None
            return preorder(tail, t)

        if head is None:
            return None
        dummy = Node(0, None, head, None)
        preorder(dummy, head)
        dummy.next.prev = None
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }
        Node dummy = new Node();
        dummy.next = head;
        preorder(dummy, head);
        dummy.next.prev = null;
        return dummy.next;
    }

    private Node preorder(Node pre, Node cur) {
        if (cur == null) {
            return pre;
        }
        cur.prev = pre;
        pre.next = cur;

        Node t = cur.next;
        Node tail = preorder(cur, cur.child);
        cur.child = null;
        return preorder(tail, t);
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
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        flattenGetTail(head);
        return head;
    }

    Node* flattenGetTail(Node* head) {
        Node* cur = head;
        Node* tail = nullptr;

        while (cur) {
            Node* next = cur->next;
            if (cur->child) {
                Node* child = cur->child;
                Node* childTail = flattenGetTail(cur->child);

                cur->child = nullptr;
                cur->next = child;
                child->prev = cur;
                childTail->next = next;

                if (next)
                    next->prev = childTail;

                tail = childTail;
            } else {
                tail = cur;
            }

            cur = next;
        }

        return tail;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 <strong>子指针</strong> 。这个子指针可能指向一个单独的双向链表，也包含这些特殊的节点。这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 <strong>多层数据结构</strong> 。</p>

<p>给定链表的头节点&nbsp;<font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">head</span></span></font></font>&nbsp;，将链表 <strong>扁平化</strong> ，以便所有节点都出现在单层双链表中。让 <code>curr</code> 是一个带有子列表的节点。子列表中的节点应该出现在<strong>扁平化列表</strong>中的&nbsp;<code>curr</code> <strong>之后</strong> 和&nbsp;<code>curr.next</code>&nbsp;<strong>之前</strong> 。</p>

<p>返回 <em>扁平列表的 <code>head</code>&nbsp;。列表中的节点必须将其 <strong>所有</strong> 子指针设置为&nbsp;<code>null</code>&nbsp;。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0430.Flatten%20a%20Multilevel%20Doubly%20Linked%20List/images/flatten11.jpg" style="height:339px; width:700px" /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
<strong>输出：</strong>[1,2,3,7,8,11,12,9,10,4,5,6]
<strong>解释：</strong>输入的多级列表如上图所示。
扁平化后的链表如下图：
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0430.Flatten%20a%20Multilevel%20Doubly%20Linked%20List/images/flatten12.jpg" style="height:69px; width:1000px" />
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0430.Flatten%20a%20Multilevel%20Doubly%20Linked%20List/images/flatten2.1jpg" style="height:200px; width:200px" /></p>

<pre>
<strong>输入：</strong>head = [1,2,null,3]
<strong>输出：</strong>[1,3,2]
<strong>解释：</strong>输入的多级列表如上图所示。
扁平化后的链表如下图：
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0430.Flatten%20a%20Multilevel%20Doubly%20Linked%20List/images/list.jpg" style="height:87px; width:300px" />
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = []
<strong>输出：</strong>[]
<strong>说明：</strong>输入中可能存在空列表。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点数目不超过 <code>1000</code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>如何表示测试用例中的多级链表？</strong></p>

<p>以 <strong>示例 1</strong> 为例：</p>

<pre>
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL</pre>

<p>序列化其中的每一级之后：</p>

<pre>
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
</pre>

<p>为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。</p>

<pre>
[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
</pre>

<p>合并所有序列化结果，并去除末尾的 null 。</p>

<pre>
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
</pre>

<ul>
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
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""


class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def preorder(pre, cur):
            if cur is None:
                return pre
            cur.prev = pre
            pre.next = cur

            t = cur.next
            tail = preorder(cur, cur.child)
            cur.child = None
            return preorder(tail, t)

        if head is None:
            return None
        dummy = Node(0, None, head, None)
        preorder(dummy, head)
        dummy.next.prev = None
        return dummy.next
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }
        Node dummy = new Node();
        dummy.next = head;
        preorder(dummy, head);
        dummy.next.prev = null;
        return dummy.next;
    }

    private Node preorder(Node pre, Node cur) {
        if (cur == null) {
            return pre;
        }
        cur.prev = pre;
        pre.next = cur;

        Node t = cur.next;
        Node tail = preorder(cur, cur.child);
        cur.child = null;
        return preorder(tail, t);
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
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        flattenGetTail(head);
        return head;
    }

    Node* flattenGetTail(Node* head) {
        Node* cur = head;
        Node* tail = nullptr;

        while (cur) {
            Node* next = cur->next;
            if (cur->child) {
                Node* child = cur->child;
                Node* childTail = flattenGetTail(cur->child);

                cur->child = nullptr;
                cur->next = child;
                child->prev = cur;
                childTail->next = next;

                if (next)
                    next->prev = childTail;

                tail = childTail;
            } else {
                tail = cur;
            }

            cur = next;
        }

        return tail;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [431. 将 N 叉树编码为二叉树 🔒](https://leetcode.cn/problems/encode-n-ary-tree-to-binary-tree){#431}

{{< tabs "431" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""


class Codec:
    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: "Optional[Node]") -> Optional[TreeNode]:
        if root is None:
            return None
        node = TreeNode(root.val)
        if not root.children:
            return node
        left = self.encode(root.children[0])
        node.left = left
        for child in root.children[1:]:
            left.right = self.encode(child)
            left = left.right
        return node

    # Decodes your binary tree to an n-ary tree.
    def decode(self, data: Optional[TreeNode]) -> "Optional[Node]":
        if data is None:
            return None
        node = Node(data.val, [])
        if data.left is None:
            return node
        left = data.left
        while left:
            node.children.append(self.decode(left))
            left = left.right
        return node


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Codec {
    // Encodes an n-ary tree to a binary tree.
    public TreeNode encode(Node root) {
        if (root == null) {
            return null;
        }
        TreeNode node = new TreeNode(root.val);
        if (root.children == null || root.children.isEmpty()) {
            return node;
        }
        TreeNode left = encode(root.children.get(0));
        node.left = left;
        for (int i = 1; i < root.children.size(); i++) {
            left.right = encode(root.children.get(i));
            left = left.right;
        }
        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    public Node decode(TreeNode data) {
        if (data == null) {
            return null;
        }
        Node node = new Node(data.val, new ArrayList<>());
        if (data.left == null) {
            return node;
        }
        TreeNode left = data.left;
        while (left != null) {
            node.children.add(decode(left));
            left = left.right;
        }
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(root->val);
        if (root->children.empty()) {
            return node;
        }
        TreeNode* left = encode(root->children[0]);
        node->left = left;
        for (int i = 1; i < root->children.size(); i++) {
            left->right = encode(root->children[i]);
            left = left->right;
        }
        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* data) {
        if (data == nullptr) {
            return nullptr;
        }
        Node* node = new Node(data->val, vector<Node*>());
        if (data->left == nullptr) {
            return node;
        }
        TreeNode* left = data->left;
        while (left != nullptr) {
            node->children.push_back(decode(left));
            left = left->right;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Codec struct {
}

func Constructor() *Codec {
	return &Codec{}
}

// Encodes an n-ary tree to a binary tree.
func (this *Codec) encode(root *Node) *TreeNode {
	if root == nil {
		return nil
	}
	node := &TreeNode{Val: root.Val}
	if len(root.Children) == 0 {
		return node
	}
	left := this.encode(root.Children[0])
	node.Left = left
	for i := 1; i < len(root.Children); i++ {
		left.Right = this.encode(root.Children[i])
		left = left.Right
	}
	return node
}

// Decodes your binary tree to an n-ary tree.
func (this *Codec) decode(data *TreeNode) *Node {
	if data == nil {
		return nil
	}
	node := &Node{Val: data.Val, Children: []*Node{}}
	if data.Left == nil {
		return node
	}
	left := data.Left
	for left != nil {
		node.Children = append(node.Children, this.decode(left))
		left = left.Right
	}
	return node
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * bst := obj.encode(root);
 * ans := obj.decode(bst);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     children: _Node[]
 *
 *     constructor(v: number) {
 *         this.val = v;
 *         this.children = [];
 *     }
 * }
 */

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

class Codec {
    constructor() {}

    // Encodes an n-ary tree to a binary tree.
    serialize(root: _Node | null): TreeNode | null {
        if (root === null) {
            return null;
        }
        const node = new TreeNode(root.val);
        if (root.children.length === 0) {
            return node;
        }
        let left: TreeNode | null = this.serialize(root.children[0]);
        node.left = left;
        for (let i = 1; i < root.children.length; i++) {
            if (left) {
                left.right = this.serialize(root.children[i]);
                left = left.right;
            }
        }
        return node;
    }

    // Decodes your binary tree back to an n-ary tree.
    deserialize(root: TreeNode | null): _Node | null {
        if (root === null) {
            return null;
        }
        const node = new _Node(root.val);
        if (root.left === null) {
            return node;
        }
        let left: TreeNode | null = root.left;
        while (left !== null) {
            node.children.push(this.deserialize(left));
            left = left.right;
        }
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个算法，可以将 N 叉树编码为二叉树，并能将该二叉树解码为原 N 叉树。一个 N 叉树是指每个节点都有不超过 N 个孩子节点的有根树。类似地，一个二叉树是指每个节点都有不超过 2 个孩子节点的有根树。你的编码 / 解码的算法的实现没有限制，你只需要保证一个 N 叉树可以编码为二叉树且该二叉树可以解码回原始 N 叉树即可。</p>

<p>例如，你可以将下面的 <code>3-叉</code> 树以该种方式编码：</p>

<p>&nbsp;</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0431.Encode%20N-ary%20Tree%20to%20Binary%20Tree/images/narytreebinarytreeexample.png" style="width: 500px;" /></p>

<p>&nbsp;</p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
</pre>

<p>注意，上面的方法仅仅是一个例子，可能可行也可能不可行。你没有必要遵循这种形式转化，你可以自己创造和实现不同的方法。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[1,null,3,2,4,null,5,6]
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>N</code>&nbsp;的范围在 <code>[1, 10<sup>4</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>N 叉树的高度小于等于&nbsp;<code>1000</code>。</li>
	<li>不要使用类成员 / 全局变量 / 静态变量来存储状态。你的编码和解码算法应是无状态的。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以将二叉树的左指针指向 N 叉树的第一个孩子，将二叉树的右指针指向 N 叉树的下一个兄弟节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 N 叉树的节点数量。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""


class Codec:
    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: "Optional[Node]") -> Optional[TreeNode]:
        if root is None:
            return None
        node = TreeNode(root.val)
        if not root.children:
            return node
        left = self.encode(root.children[0])
        node.left = left
        for child in root.children[1:]:
            left.right = self.encode(child)
            left = left.right
        return node

    # Decodes your binary tree to an n-ary tree.
    def decode(self, data: Optional[TreeNode]) -> "Optional[Node]":
        if data is None:
            return None
        node = Node(data.val, [])
        if data.left is None:
            return node
        left = data.left
        while left:
            node.children.append(self.decode(left))
            left = left.right
        return node


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Codec {
    // Encodes an n-ary tree to a binary tree.
    public TreeNode encode(Node root) {
        if (root == null) {
            return null;
        }
        TreeNode node = new TreeNode(root.val);
        if (root.children == null || root.children.isEmpty()) {
            return node;
        }
        TreeNode left = encode(root.children.get(0));
        node.left = left;
        for (int i = 1; i < root.children.size(); i++) {
            left.right = encode(root.children.get(i));
            left = left.right;
        }
        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    public Node decode(TreeNode data) {
        if (data == null) {
            return null;
        }
        Node node = new Node(data.val, new ArrayList<>());
        if (data.left == null) {
            return node;
        }
        TreeNode left = data.left;
        while (left != null) {
            node.children.add(decode(left));
            left = left.right;
        }
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(root->val);
        if (root->children.empty()) {
            return node;
        }
        TreeNode* left = encode(root->children[0]);
        node->left = left;
        for (int i = 1; i < root->children.size(); i++) {
            left->right = encode(root->children[i]);
            left = left->right;
        }
        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* data) {
        if (data == nullptr) {
            return nullptr;
        }
        Node* node = new Node(data->val, vector<Node*>());
        if (data->left == nullptr) {
            return node;
        }
        TreeNode* left = data->left;
        while (left != nullptr) {
            node->children.push_back(decode(left));
            left = left->right;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Codec struct {
}

func Constructor() *Codec {
	return &Codec{}
}

// Encodes an n-ary tree to a binary tree.
func (this *Codec) encode(root *Node) *TreeNode {
	if root == nil {
		return nil
	}
	node := &TreeNode{Val: root.Val}
	if len(root.Children) == 0 {
		return node
	}
	left := this.encode(root.Children[0])
	node.Left = left
	for i := 1; i < len(root.Children); i++ {
		left.Right = this.encode(root.Children[i])
		left = left.Right
	}
	return node
}

// Decodes your binary tree to an n-ary tree.
func (this *Codec) decode(data *TreeNode) *Node {
	if data == nil {
		return nil
	}
	node := &Node{Val: data.Val, Children: []*Node{}}
	if data.Left == nil {
		return node
	}
	left := data.Left
	for left != nil {
		node.Children = append(node.Children, this.decode(left))
		left = left.Right
	}
	return node
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * bst := obj.encode(root);
 * ans := obj.decode(bst);
 */
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     children: _Node[]
 *
 *     constructor(v: number) {
 *         this.val = v;
 *         this.children = [];
 *     }
 * }
 */

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

class Codec {
    constructor() {}

    // Encodes an n-ary tree to a binary tree.
    serialize(root: _Node | null): TreeNode | null {
        if (root === null) {
            return null;
        }
        const node = new TreeNode(root.val);
        if (root.children.length === 0) {
            return node;
        }
        let left: TreeNode | null = this.serialize(root.children[0]);
        node.left = left;
        for (let i = 1; i < root.children.length; i++) {
            if (left) {
                left.right = this.serialize(root.children[i]);
                left = left.right;
            }
        }
        return node;
    }

    // Decodes your binary tree back to an n-ary tree.
    deserialize(root: TreeNode | null): _Node | null {
        if (root === null) {
            return null;
        }
        const node = new _Node(root.val);
        if (root.left === null) {
            return node;
        }
        let left: TreeNode | null = root.left;
        while (left !== null) {
            node.children.push(this.deserialize(left));
            left = left.right;
        }
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [432. 全 O(1) 的数据结构](https://leetcode.cn/problems/all-oone-data-structure){#432}

{{< tabs "432" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self, key='', cnt=0):
        self.prev = None
        self.next = None
        self.cnt = cnt
        self.keys = {key}

    def insert(self, node):
        node.prev = self
        node.next = self.next
        node.prev.next = node
        node.next.prev = node
        return node

    def remove(self):
        self.prev.next = self.next
        self.next.prev = self.prev


class AllOne:
    def __init__(self):
        self.root = Node()
        self.root.next = self.root
        self.root.prev = self.root
        self.nodes = {}

    def inc(self, key: str) -> None:
        root, nodes = self.root, self.nodes
        if key not in nodes:
            if root.next == root or root.next.cnt > 1:
                nodes[key] = root.insert(Node(key, 1))
            else:
                root.next.keys.add(key)
                nodes[key] = root.next
        else:
            curr = nodes[key]
            next = curr.next
            if next == root or next.cnt > curr.cnt + 1:
                nodes[key] = curr.insert(Node(key, curr.cnt + 1))
            else:
                next.keys.add(key)
                nodes[key] = next
            curr.keys.discard(key)
            if not curr.keys:
                curr.remove()

    def dec(self, key: str) -> None:
        root, nodes = self.root, self.nodes
        curr = nodes[key]
        if curr.cnt == 1:
            nodes.pop(key)
        else:
            prev = curr.prev
            if prev == root or prev.cnt < curr.cnt - 1:
                nodes[key] = prev.insert(Node(key, curr.cnt - 1))
            else:
                prev.keys.add(key)
                nodes[key] = prev
        curr.keys.discard(key)
        if not curr.keys:
            curr.remove()

    def getMaxKey(self) -> str:
        return next(iter(self.root.prev.keys))

    def getMinKey(self) -> str:
        return next(iter(self.root.next.keys))


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class AllOne {
    Node root = new Node();
    Map<String, Node> nodes = new HashMap<>();

    public AllOne() {
        root.next = root;
        root.prev = root;
    }

    public void inc(String key) {
        if (!nodes.containsKey(key)) {
            if (root.next == root || root.next.cnt > 1) {
                nodes.put(key, root.insert(new Node(key, 1)));
            } else {
                root.next.keys.add(key);
                nodes.put(key, root.next);
            }
        } else {
            Node curr = nodes.get(key);
            Node next = curr.next;
            if (next == root || next.cnt > curr.cnt + 1) {
                nodes.put(key, curr.insert(new Node(key, curr.cnt + 1)));
            } else {
                next.keys.add(key);
                nodes.put(key, next);
            }
            curr.keys.remove(key);
            if (curr.keys.isEmpty()) {
                curr.remove();
            }
        }
    }

    public void dec(String key) {
        Node curr = nodes.get(key);
        if (curr.cnt == 1) {
            nodes.remove(key);
        } else {
            Node prev = curr.prev;
            if (prev == root || prev.cnt < curr.cnt - 1) {
                nodes.put(key, prev.insert(new Node(key, curr.cnt - 1)));
            } else {
                prev.keys.add(key);
                nodes.put(key, prev);
            }
        }

        curr.keys.remove(key);
        if (curr.keys.isEmpty()) {
            curr.remove();
        }
    }

    public String getMaxKey() {
        return root.prev.keys.iterator().next();
    }

    public String getMinKey() {
        return root.next.keys.iterator().next();
    }
}

class Node {
    Node prev;
    Node next;
    int cnt;
    Set<String> keys = new HashSet<>();

    public Node() {
        this("", 0);
    }

    public Node(String key, int cnt) {
        this.cnt = cnt;
        keys.add(key);
    }

    public Node insert(Node node) {
        node.prev = this;
        node.next = this.next;
        node.prev.next = node;
        node.next.prev = node;
        return node;
    }

    public void remove() {
        this.prev.next = this.next;
        this.next.prev = this.prev;
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。</p>

<p>实现 <code>AllOne</code> 类：</p>

<ul>
	<li><code>AllOne()</code> 初始化数据结构的对象。</li>
	<li><code>inc(String key)</code> 字符串 <code>key</code> 的计数增加 <code>1</code> 。如果数据结构中尚不存在 <code>key</code> ，那么插入计数为 <code>1</code> 的 <code>key</code> 。</li>
	<li><code>dec(String key)</code> 字符串 <code>key</code> 的计数减少 <code>1</code> 。如果 <code>key</code> 的计数在减少后为 <code>0</code> ，那么需要将这个 <code>key</code> 从数据结构中删除。测试用例保证：在减少计数前，<code>key</code> 存在于数据结构中。</li>
	<li><code>getMaxKey()</code> 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 <code>""</code> 。</li>
	<li><code>getMinKey()</code> 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 <code>""</code> 。</li>
</ul>

<p><strong>注意：</strong>每个函数都应当满足 <code>O(1)</code> 平均时间复杂度。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
<strong>输出</strong>
[null, null, null, "hello", "hello", null, "hello", "leet"]

<strong>解释</strong>
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // 返回 "hello"
allOne.getMinKey(); // 返回 "hello"
allOne.inc("leet");
allOne.getMaxKey(); // 返回 "hello"
allOne.getMinKey(); // 返回 "leet"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= key.length &lt;= 10</code></li>
	<li><code>key</code> 由小写英文字母组成</li>
	<li>测试用例保证：在每次调用 <code>dec</code> 时，数据结构中总存在 <code>key</code></li>
	<li>最多调用 <code>inc</code>、<code>dec</code>、<code>getMaxKey</code> 和 <code>getMinKey</code> 方法 <code>5 * 10<sup>4</sup></code> 次</li>
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
class Node:
    def __init__(self, key='', cnt=0):
        self.prev = None
        self.next = None
        self.cnt = cnt
        self.keys = {key}

    def insert(self, node):
        node.prev = self
        node.next = self.next
        node.prev.next = node
        node.next.prev = node
        return node

    def remove(self):
        self.prev.next = self.next
        self.next.prev = self.prev


class AllOne:
    def __init__(self):
        self.root = Node()
        self.root.next = self.root
        self.root.prev = self.root
        self.nodes = {}

    def inc(self, key: str) -> None:
        root, nodes = self.root, self.nodes
        if key not in nodes:
            if root.next == root or root.next.cnt > 1:
                nodes[key] = root.insert(Node(key, 1))
            else:
                root.next.keys.add(key)
                nodes[key] = root.next
        else:
            curr = nodes[key]
            next = curr.next
            if next == root or next.cnt > curr.cnt + 1:
                nodes[key] = curr.insert(Node(key, curr.cnt + 1))
            else:
                next.keys.add(key)
                nodes[key] = next
            curr.keys.discard(key)
            if not curr.keys:
                curr.remove()

    def dec(self, key: str) -> None:
        root, nodes = self.root, self.nodes
        curr = nodes[key]
        if curr.cnt == 1:
            nodes.pop(key)
        else:
            prev = curr.prev
            if prev == root or prev.cnt < curr.cnt - 1:
                nodes[key] = prev.insert(Node(key, curr.cnt - 1))
            else:
                prev.keys.add(key)
                nodes[key] = prev
        curr.keys.discard(key)
        if not curr.keys:
            curr.remove()

    def getMaxKey(self) -> str:
        return next(iter(self.root.prev.keys))

    def getMinKey(self) -> str:
        return next(iter(self.root.next.keys))


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
```

#### Java

```java
class AllOne {
    Node root = new Node();
    Map<String, Node> nodes = new HashMap<>();

    public AllOne() {
        root.next = root;
        root.prev = root;
    }

    public void inc(String key) {
        if (!nodes.containsKey(key)) {
            if (root.next == root || root.next.cnt > 1) {
                nodes.put(key, root.insert(new Node(key, 1)));
            } else {
                root.next.keys.add(key);
                nodes.put(key, root.next);
            }
        } else {
            Node curr = nodes.get(key);
            Node next = curr.next;
            if (next == root || next.cnt > curr.cnt + 1) {
                nodes.put(key, curr.insert(new Node(key, curr.cnt + 1)));
            } else {
                next.keys.add(key);
                nodes.put(key, next);
            }
            curr.keys.remove(key);
            if (curr.keys.isEmpty()) {
                curr.remove();
            }
        }
    }

    public void dec(String key) {
        Node curr = nodes.get(key);
        if (curr.cnt == 1) {
            nodes.remove(key);
        } else {
            Node prev = curr.prev;
            if (prev == root || prev.cnt < curr.cnt - 1) {
                nodes.put(key, prev.insert(new Node(key, curr.cnt - 1)));
            } else {
                prev.keys.add(key);
                nodes.put(key, prev);
            }
        }

        curr.keys.remove(key);
        if (curr.keys.isEmpty()) {
            curr.remove();
        }
    }

    public String getMaxKey() {
        return root.prev.keys.iterator().next();
    }

    public String getMinKey() {
        return root.next.keys.iterator().next();
    }
}

class Node {
    Node prev;
    Node next;
    int cnt;
    Set<String> keys = new HashSet<>();

    public Node() {
        this("", 0);
    }

    public Node(String key, int cnt) {
        this.cnt = cnt;
        keys.add(key);
    }

    public Node insert(Node node) {
        node.prev = this;
        node.next = this.next;
        node.prev.next = node;
        node.next.prev = node;
        return node;
    }

    public void remove() {
        this.prev.next = this.next;
        this.next.prev = this.prev;
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [433. 最小基因变化](https://leetcode.cn/problems/minimum-genetic-mutation){#433}

{{< tabs "433" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        q = deque([(startGene, 0)])
        vis = {startGene}
        while q:
            gene, depth = q.popleft()
            if gene == endGene:
                return depth
            for nxt in bank:
                diff = sum(a != b for a, b in zip(gene, nxt))
                if diff == 1 and nxt not in vis:
                    q.append((nxt, depth + 1))
                    vis.add(nxt)
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Deque<String> q = new ArrayDeque<>();
        q.offer(startGene);
        Set<String> vis = new HashSet<>();
        vis.add(startGene);
        int depth = 0;
        while (!q.isEmpty()) {
            for (int m = q.size(); m > 0; --m) {
                String gene = q.poll();
                if (gene.equals(endGene)) {
                    return depth;
                }
                for (String next : bank) {
                    int c = 2;
                    for (int k = 0; k < 8 && c > 0; ++k) {
                        if (gene.charAt(k) != next.charAt(k)) {
                            --c;
                        }
                    }
                    if (c > 0 && !vis.contains(next)) {
                        q.offer(next);
                        vis.add(next);
                    }
                }
            }
            ++depth;
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q{{{startGene, 0}}};
        unordered_set<string> vis = {startGene};
        while (!q.empty()) {
            auto [gene, depth] = q.front();
            q.pop();
            if (gene == endGene) {
                return depth;
            }
            for (const string& next : bank) {
                int c = 2;
                for (int k = 0; k < 8 && c; ++k) {
                    c -= gene[k] != next[k];
                }
                if (c && !vis.contains(next)) {
                    vis.insert(next);
                    q.push({next, depth + 1});
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMutation(startGene string, endGene string, bank []string) int {
	type pair struct {
		s     string
		depth int
	}
	q := []pair{pair{startGene, 0}}
	vis := map[string]bool{startGene: true}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		if p.s == endGene {
			return p.depth
		}
		for _, next := range bank {
			diff := 0
			for i := 0; i < len(startGene); i++ {
				if p.s[i] != next[i] {
					diff++
				}
			}
			if diff == 1 && !vis[next] {
				vis[next] = true
				q = append(q, pair{next, p.depth + 1})
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMutation(startGene: string, endGene: string, bank: string[]): number {
    const q: [string, number][] = [[startGene, 0]];
    const vis = new Set<string>([startGene]);
    for (const [gene, depth] of q) {
        if (gene === endGene) {
            return depth;
        }
        for (const next of bank) {
            let c = 2;
            for (let k = 0; k < 8 && c > 0; ++k) {
                if (gene[k] !== next[k]) {
                    --c;
                }
            }
            if (c && !vis.has(next)) {
                q.push([next, depth + 1]);
                vis.add(next);
            }
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, bank: Vec<String>) -> i32 {
        let mut q = VecDeque::new();
        q.push_back((start_gene.clone(), 0));
        let mut vis = HashSet::new();
        vis.insert(start_gene);

        while let Some((gene, depth)) = q.pop_front() {
            if gene == end_gene {
                return depth;
            }
            for next in &bank {
                let mut c = 2;
                for k in 0..8 {
                    if gene.as_bytes()[k] != next.as_bytes()[k] {
                        c -= 1;
                    }
                    if c == 0 {
                        break;
                    }
                }
                if c > 0 && !vis.contains(next) {
                    vis.insert(next.clone());
                    q.push_back((next.clone(), depth + 1));
                }
            }
        }
        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 <code>'A'</code>、<code>'C'</code>、<code>'G'</code> 和 <code>'T'</code> 之一。</p>

<p>假设我们需要调查从基因序列&nbsp;<code>start</code> 变为 <code>end</code> 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。</p>

<ul>
	<li>例如，<code>"AACCGGTT" --&gt; "AACCGGTA"</code> 就是一次基因变化。</li>
</ul>

<p>另有一个基因库 <code>bank</code> 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 <code>bank</code> 中）</p>

<p>给你两个基因序列 <code>start</code> 和 <code>end</code> ，以及一个基因库 <code>bank</code> ，请你找出并返回能够使&nbsp;<code>start</code> 变化为 <code>end</code> 所需的最少变化次数。如果无法完成此基因变化，返回 <code>-1</code> 。</p>

<p>注意：起始基因序列&nbsp;<code>start</code> 默认是有效的，但是它并不一定会出现在基因库中。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>start.length == 8</code></li>
	<li><code>end.length == 8</code></li>
	<li><code>0 &lt;= bank.length &lt;= 10</code></li>
	<li><code>bank[i].length == 8</code></li>
	<li><code>start</code>、<code>end</code> 和 <code>bank[i]</code> 仅由字符 <code>['A', 'C', 'G', 'T']</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个队列 `q`，用于存储当前基因序列以及变化的次数，定义一个集合 `vis`，用于存储已经访问过的基因序列。初始时，将起始基因序列 `start` 加入队列 `q`，并将其加入集合 `vis`。

然后，我们不断从队列 `q` 中取出一个基因序列，如果该基因序列等于目标基因序列，则返回当前的变化次数。否则，我们遍历基因库 `bank`，计算当前基因序列与基因库中的基因序列的差异值，如果差异值为 $1$，且基因库中的基因序列没有被访问过，则将其加入队列 `q`，并将其加入集合 `vis`。

如果队列 `q` 为空，说明无法完成基因变化，返回 $-1$。

时间复杂度 $O(C \times n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别表示基因序列的长度和基因库的长度，而 $C$ 表示基因序列的字符集大小，本题中 $C = 4$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        q = deque([(startGene, 0)])
        vis = {startGene}
        while q:
            gene, depth = q.popleft()
            if gene == endGene:
                return depth
            for nxt in bank:
                diff = sum(a != b for a, b in zip(gene, nxt))
                if diff == 1 and nxt not in vis:
                    q.append((nxt, depth + 1))
                    vis.add(nxt)
        return -1
```

#### Java

```java
class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Deque<String> q = new ArrayDeque<>();
        q.offer(startGene);
        Set<String> vis = new HashSet<>();
        vis.add(startGene);
        int depth = 0;
        while (!q.isEmpty()) {
            for (int m = q.size(); m > 0; --m) {
                String gene = q.poll();
                if (gene.equals(endGene)) {
                    return depth;
                }
                for (String next : bank) {
                    int c = 2;
                    for (int k = 0; k < 8 && c > 0; ++k) {
                        if (gene.charAt(k) != next.charAt(k)) {
                            --c;
                        }
                    }
                    if (c > 0 && !vis.contains(next)) {
                        q.offer(next);
                        vis.add(next);
                    }
                }
            }
            ++depth;
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q{{{startGene, 0}}};
        unordered_set<string> vis = {startGene};
        while (!q.empty()) {
            auto [gene, depth] = q.front();
            q.pop();
            if (gene == endGene) {
                return depth;
            }
            for (const string& next : bank) {
                int c = 2;
                for (int k = 0; k < 8 && c; ++k) {
                    c -= gene[k] != next[k];
                }
                if (c && !vis.contains(next)) {
                    vis.insert(next);
                    q.push({next, depth + 1});
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minMutation(startGene string, endGene string, bank []string) int {
	type pair struct {
		s     string
		depth int
	}
	q := []pair{pair{startGene, 0}}
	vis := map[string]bool{startGene: true}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		if p.s == endGene {
			return p.depth
		}
		for _, next := range bank {
			diff := 0
			for i := 0; i < len(startGene); i++ {
				if p.s[i] != next[i] {
					diff++
				}
			}
			if diff == 1 && !vis[next] {
				vis[next] = true
				q = append(q, pair{next, p.depth + 1})
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minMutation(startGene: string, endGene: string, bank: string[]): number {
    const q: [string, number][] = [[startGene, 0]];
    const vis = new Set<string>([startGene]);
    for (const [gene, depth] of q) {
        if (gene === endGene) {
            return depth;
        }
        for (const next of bank) {
            let c = 2;
            for (let k = 0; k < 8 && c > 0; ++k) {
                if (gene[k] !== next[k]) {
                    --c;
                }
            }
            if (c && !vis.has(next)) {
                q.push([next, depth + 1]);
                vis.add(next);
            }
        }
    }
    return -1;
}
```

#### Rust

```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, bank: Vec<String>) -> i32 {
        let mut q = VecDeque::new();
        q.push_back((start_gene.clone(), 0));
        let mut vis = HashSet::new();
        vis.insert(start_gene);

        while let Some((gene, depth)) = q.pop_front() {
            if gene == end_gene {
                return depth;
            }
            for next in &bank {
                let mut c = 2;
                for k in 0..8 {
                    if gene.as_bytes()[k] != next.as_bytes()[k] {
                        c -= 1;
                    }
                    if c == 0 {
                        break;
                    }
                }
                if c > 0 && !vis.contains(next) {
                    vis.insert(next.clone());
                    q.push_back((next.clone(), depth + 1));
                }
            }
        }
        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [434. 字符串中的单词数](https://leetcode.cn/problems/number-of-segments-in-a-string){#434}

{{< tabs "434" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSegments(self, s: str) -> int:
        ans = 0
        for i, c in enumerate(s):
            if c != ' ' and (i == 0 or s[i - 1] == ' '):
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSegments(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')) {
                ++ans;
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
    int countSegments(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSegments(s string) int {
	ans := 0
	for i, c := range s {
		if c != ' ' && (i == 0 || s[i-1] == ' ') {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSegments(s: string): number {
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        let c = s[i];
        if (c !== ' ' && (i === 0 || s[i - 1] === ' ')) {
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function countSegments($s) {
        $ans = 0;
        $n = strlen($s);
        for ($i = 0; $i < $n; $i++) {
            $c = $s[$i];
            if ($c !== ' ' && ($i === 0 || $s[$i - 1] === ' ')) {
                $ans++;
            }
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

<p>统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。</p>

<p>请注意，你可以假定字符串里不包括任何不可打印的字符。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> &quot;Hello, my name is John&quot;
<strong>输出:</strong> 5
<strong>解释: </strong>这里的单词是指连续的不是空格的字符，所以 &quot;Hello,&quot; 算作 1 个单词。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串分割

我们将字符串 $\textit{s}$ 按照空格进行分割，然后统计不为空的单词个数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{s}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSegments(self, s: str) -> int:
        return len(s.split())
```

#### Java

```java
class Solution {
    public int countSegments(String s) {
        int ans = 0;
        for (String t : s.split(" ")) {
            if (!"".equals(t)) {
                ++ans;
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
    int countSegments(string s) {
        int ans = 0;
        istringstream ss(s);
        while (ss >> s) ++ans;
        return ans;
    }
};
```

#### Go

```go
func countSegments(s string) int {
	ans := 0
	for _, t := range strings.Split(s, " ") {
		if len(t) > 0 {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countSegments(s: string): number {
    return s.split(/\s+/).filter(Boolean).length;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function countSegments($s) {
        $arr = explode(' ', $s);
        $cnt = 0;
        for ($i = 0; $i < count($arr); $i++) {
            if (strlen($arr[$i]) != 0) {
                $cnt++;
            }
        }
        return $cnt;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：模拟

我们也可以直接遍历字符串的每个字符 $\text{s[i]}$，如果 $\text{s[i]}$ 不是空格且 $\text{s[i-1]}$ 是空格或者 $i = 0$，那么就说明 $\text{s[i]}$ 是一个新的单词的开始，我们就将答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSegments(self, s: str) -> int:
        ans = 0
        for i, c in enumerate(s):
            if c != ' ' and (i == 0 or s[i - 1] == ' '):
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countSegments(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')) {
                ++ans;
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
    int countSegments(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSegments(s string) int {
	ans := 0
	for i, c := range s {
		if c != ' ' && (i == 0 || s[i-1] == ' ') {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countSegments(s: string): number {
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        let c = s[i];
        if (c !== ' ' && (i === 0 || s[i - 1] === ' ')) {
            ans++;
        }
    }
    return ans;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function countSegments($s) {
        $ans = 0;
        $n = strlen($s);
        for ($i = 0; $i < $n; $i++) {
            $c = $s[$i];
            if ($c !== ' ' && ($i === 0 || $s[$i - 1] === ' ')) {
                $ans++;
            }
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

# [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals){#435}

{{< tabs "435" >}}

{{% tab "python" %}}
```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        ans = len(intervals)
        pre = -inf
        for l, r in intervals:
            if pre <= l:
                ans -= 1
                pre = r
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int ans = intervals.length;
        int pre = Integer.MIN_VALUE;
        for (var e : intervals) {
            int l = e[0], r = e[1];
            if (pre <= l) {
                --ans;
                pre = r;
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = intervals.size();
        int pre = INT_MIN;
        for (const auto& e : intervals) {
            int l = e[0], r = e[1];
            if (pre <= l) {
                --ans;
                pre = r;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})
	ans := len(intervals)
	pre := math.MinInt32
	for _, e := range intervals {
		l, r := e[0], e[1]
		if pre <= l {
			ans--
			pre = r
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function eraseOverlapIntervals(intervals: number[][]): number {
    intervals.sort((a, b) => a[1] - b[1]);
    let [ans, pre] = [intervals.length, -Infinity];
    for (const [l, r] of intervals) {
        if (pre <= l) {
            --ans;
            pre = r;
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

<p>给定一个区间的集合&nbsp;<code>intervals</code>&nbsp;，其中 <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;。返回 <em>需要移除区间的最小数量，使剩余区间互不重叠&nbsp;</em>。</p>

<p><strong>注意</strong>&nbsp;只在一点上接触的区间是&nbsp;<strong>不重叠的</strong>。例如&nbsp;<code>[1, 2]</code>&nbsp;和&nbsp;<code>[2, 3]</code>&nbsp;是不重叠的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> intervals = [[1,2],[2,3],[3,4],[1,3]]
<strong>输出:</strong> 1
<strong>解释:</strong> 移除 [1,3] 后，剩下的区间没有重叠。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> intervals = [ [1,2], [1,2], [1,2] ]
<strong>输出:</strong> 2
<strong>解释:</strong> 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> intervals = [ [1,2], [2,3] ]
<strong>输出:</strong> 0
<strong>解释:</strong> 你不需要移除任何区间，因为它们已经是无重叠的了。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>-5 * 10<sup>4</sup>&nbsp;&lt;= start<sub>i</sub>&nbsp;&lt; end<sub>i</sub>&nbsp;&lt;= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们首先将区间按照右边界升序排序，用一个变量 $\textit{pre}$ 记录上一个区间的右边界，用一个变量 $\textit{ans}$ 记录需要移除的区间数量，初始时 $\textit{ans} = \textit{intervals.length}$。

然后遍历区间，对于每一个区间：

-   若当前区间的左边界大于等于 $\textit{pre}$，说明该区间无需移除，直接更新 $\textit{pre}$ 为当前区间的右边界，然后将 $\textit{ans}$ 减一；
-   否则，说明该区间需要移除，不需要更新 $\textit{pre}$ 和 $\textit{ans}$。

最后返回 $\textit{ans}$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为区间的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        ans = len(intervals)
        pre = -inf
        for l, r in intervals:
            if pre <= l:
                ans -= 1
                pre = r
        return ans
```

#### Java

```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int ans = intervals.length;
        int pre = Integer.MIN_VALUE;
        for (var e : intervals) {
            int l = e[0], r = e[1];
            if (pre <= l) {
                --ans;
                pre = r;
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = intervals.size();
        int pre = INT_MIN;
        for (const auto& e : intervals) {
            int l = e[0], r = e[1];
            if (pre <= l) {
                --ans;
                pre = r;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})
	ans := len(intervals)
	pre := math.MinInt32
	for _, e := range intervals {
		l, r := e[0], e[1]
		if pre <= l {
			ans--
			pre = r
		}
	}
	return ans
}
```

#### TypeScript

```ts
function eraseOverlapIntervals(intervals: number[][]): number {
    intervals.sort((a, b) => a[1] - b[1]);
    let [ans, pre] = [intervals.length, -Infinity];
    for (const [l, r] of intervals) {
        if (pre <= l) {
            --ans;
            pre = r;
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

# [436. 寻找右区间](https://leetcode.cn/problems/find-right-interval){#436}

{{< tabs "436" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        ans = [-1] * n
        arr = sorted((st, i) for i, (st, _) in enumerate(intervals))
        for i, (_, ed) in enumerate(intervals):
            j = bisect_left(arr, (ed, -inf))
            if j < n:
                ans[i] = arr[j][1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {intervals[i][0], i};
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int j = search(arr, intervals[i][1]);
            ans[i] = j < n ? arr[j][1] : -1;
        }
        return ans;
    }

    private int search(int[][] arr, int x) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid][0] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(intervals[i][0], i);
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto& e : intervals) {
            int j = lower_bound(arr.begin(), arr.end(), make_pair(e[1], -1)) - arr.begin();
            ans.push_back(j == n ? -1 : arr[j].second);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findRightInterval(intervals [][]int) (ans []int) {
	arr := make([][2]int, len(intervals))
	for i, v := range intervals {
		arr[i] = [2]int{v[0], i}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] < arr[j][0] })
	for _, e := range intervals {
		j := sort.Search(len(arr), func(i int) bool { return arr[i][0] >= e[1] })
		if j < len(arr) {
			ans = append(ans, arr[j][1])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findRightInterval(intervals: number[][]): number[] {
    const n = intervals.length;
    const arr: number[][] = Array.from({ length: n }, (_, i) => [intervals[i][0], i]);
    arr.sort((a, b) => a[0] - b[0]);
    return intervals.map(([_, ed]) => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid][0] >= ed) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l < n ? arr[l][1] : -1;
    });
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个区间数组 <code>intervals</code> ，其中&nbsp;<code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> ，且每个&nbsp;<code>start<sub>i</sub></code> 都 <strong>不同</strong> 。</p>

<p>区间 <code>i</code> 的 <strong>右侧区间</strong>&nbsp;是满足 <code>start<sub>j</sub>&nbsp;&gt;= end<sub>i</sub></code>，且 <code>start<sub>j</sub></code> <strong>最小&nbsp;</strong>的区间 <code>j</code>。注意 <code>i</code> 可能等于 <code>j</code> 。</p>

<p>返回一个由每个区间 <code>i</code>&nbsp;对应的 <strong>右侧区间</strong> 下标组成的数组。如果某个区间 <code>i</code> 不存在对应的 <strong>右侧区间</strong> ，则下标 <code>i</code> 处的值设为 <code>-1</code> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,2]]
<strong>输出：</strong>[-1]
<strong>解释：</strong>集合中只有一个区间，所以输出-1。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[3,4],[2,3],[1,2]]
<strong>输出：</strong>[-1,0,1]
<strong>解释：</strong>对于 [3,4] ，没有满足条件的“右侧”区间。
对于 [2,3] ，区间[3,4]具有最小的“右”起点;
对于 [1,2] ，区间[2,3]具有最小的“右”起点。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[2,3],[3,4]]
<strong>输出：</strong>[-1,2,-1]
<strong>解释：</strong>对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;intervals.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>-10<sup>6</sup> &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>每个间隔的起点都 <strong>不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们可以将区间的起点和下标存入数组 `arr` 中，并按照起点进行排序。然后遍历区间数组，对于每个区间 `[_, ed]`，我们可以使用二分查找找到第一个起点大于等于 `ed` 的区间，即为其右侧区间，如果找到了，我们就将其下标存入答案数组中，否则存入 `-1`。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为区间的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        ans = [-1] * n
        arr = sorted((st, i) for i, (st, _) in enumerate(intervals))
        for i, (_, ed) in enumerate(intervals):
            j = bisect_left(arr, (ed, -inf))
            if j < n:
                ans[i] = arr[j][1]
        return ans
```

#### Java

```java
class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {intervals[i][0], i};
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int j = search(arr, intervals[i][1]);
            ans[i] = j < n ? arr[j][1] : -1;
        }
        return ans;
    }

    private int search(int[][] arr, int x) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid][0] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(intervals[i][0], i);
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto& e : intervals) {
            int j = lower_bound(arr.begin(), arr.end(), make_pair(e[1], -1)) - arr.begin();
            ans.push_back(j == n ? -1 : arr[j].second);
        }
        return ans;
    }
};
```

#### Go

```go
func findRightInterval(intervals [][]int) (ans []int) {
	arr := make([][2]int, len(intervals))
	for i, v := range intervals {
		arr[i] = [2]int{v[0], i}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] < arr[j][0] })
	for _, e := range intervals {
		j := sort.Search(len(arr), func(i int) bool { return arr[i][0] >= e[1] })
		if j < len(arr) {
			ans = append(ans, arr[j][1])
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```

#### TypeScript

```ts
function findRightInterval(intervals: number[][]): number[] {
    const n = intervals.length;
    const arr: number[][] = Array.from({ length: n }, (_, i) => [intervals[i][0], i]);
    arr.sort((a, b) => a[0] - b[0]);
    return intervals.map(([_, ed]) => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid][0] >= ed) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l < n ? arr[l][1] : -1;
    });
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii){#437}

{{< tabs "437" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def dfs(node, s):
            if node is None:
                return 0
            s += node.val
            ans = cnt[s - targetSum]
            cnt[s] += 1
            ans += dfs(node.left, s)
            ans += dfs(node.right, s)
            cnt[s] -= 1
            return ans

        cnt = Counter({0: 1})
        return dfs(root, 0)
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
    private Map<Long, Integer> cnt = new HashMap<>();
    private int targetSum;

    public int pathSum(TreeNode root, int targetSum) {
        cnt.put(0L, 1);
        this.targetSum = targetSum;
        return dfs(root, 0);
    }

    private int dfs(TreeNode node, long s) {
        if (node == null) {
            return 0;
        }
        s += node.val;
        int ans = cnt.getOrDefault(s - targetSum, 0);
        cnt.merge(s, 1, Integer::sum);
        ans += dfs(node.left, s);
        ans += dfs(node.right, s);
        cnt.merge(s, -1, Integer::sum);
        return ans;
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> cnt;
        cnt[0] = 1;
        auto dfs = [&](this auto&& dfs, TreeNode* node, long long s) -> int {
            if (!node) {
                return 0;
            }
            s += node->val;
            int ans = cnt[s - targetSum];
            ++cnt[s];
            ans += dfs(node->left, s) + dfs(node->right, s);
            --cnt[s];
            return ans;
        };
        return dfs(root, 0);
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
func pathSum(root *TreeNode, targetSum int) int {
	cnt := map[int]int{0: 1}
	var dfs func(*TreeNode, int) int
	dfs = func(node *TreeNode, s int) int {
		if node == nil {
			return 0
		}
		s += node.Val
		ans := cnt[s-targetSum]
		cnt[s]++
		ans += dfs(node.Left, s) + dfs(node.Right, s)
		cnt[s]--
		return ans
	}
	return dfs(root, 0)
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

function pathSum(root: TreeNode | null, targetSum: number): number {
    const cnt: Map<number, number> = new Map();
    const dfs = (node: TreeNode | null, s: number): number => {
        if (!node) {
            return 0;
        }
        s += node.val;
        let ans = cnt.get(s - targetSum) ?? 0;
        cnt.set(s, (cnt.get(s) ?? 0) + 1);
        ans += dfs(node.left, s);
        ans += dfs(node.right, s);
        cnt.set(s, (cnt.get(s) ?? 0) - 1);
        return ans;
    };
    cnt.set(0, 1);
    return dfs(root, 0);
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
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;

impl Solution {
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> i32 {
        let mut cnt = HashMap::new();
        cnt.insert(0, 1);

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, s: i64, target: i64, cnt: &mut HashMap<i64, i32>) -> i32 {
            if let Some(n) = node {
                let n = n.borrow();
                let s = s + n.val as i64;
                let ans = cnt.get(&(s - target)).copied().unwrap_or(0);
                *cnt.entry(s).or_insert(0) += 1;
                let ans = ans + dfs(n.left.clone(), s, target, cnt) + dfs(n.right.clone(), s, target, cnt);
                *cnt.get_mut(&s).unwrap() -= 1;
                ans
            } else {
                0
            }
        }

        dfs(root, 0, target_sum as i64, &mut cnt)
    }
}
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
 * @param {number} targetSum
 * @return {number}
 */
var pathSum = function (root, targetSum) {
    const cnt = new Map();
    const dfs = (node, s) => {
        if (!node) {
            return 0;
        }
        s += node.val;
        let ans = cnt.get(s - targetSum) || 0;
        cnt.set(s, (cnt.get(s) || 0) + 1);
        ans += dfs(node.left, s);
        ans += dfs(node.right, s);
        cnt.set(s, cnt.get(s) - 1);
        return ans;
    };
    cnt.set(0, 1);
    return dfs(root, 0);
};
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
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int PathSum(TreeNode root, int targetSum) {
        Dictionary<long, int> cnt = new Dictionary<long, int>();

        int Dfs(TreeNode node, long s) {
            if (node == null) {
                return 0;
            }
            s += node.val;
            int ans = cnt.GetValueOrDefault(s - targetSum, 0);
            cnt[s] = cnt.GetValueOrDefault(s, 0) + 1;
            ans += Dfs(node.left, s);
            ans += Dfs(node.right, s);
            cnt[s]--;
            return ans;
        }

        cnt[0] = 1;
        return Dfs(root, 0);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树的根节点 <code>root</code> ，和一个整数 <code>targetSum</code> ，求该二叉树里节点值之和等于 <code>targetSum</code> 的 <strong>路径</strong> 的数目。</p>

<p><strong>路径</strong> 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0437.Path%20Sum%20III/images/pathsum3-1-tree.jpg" style="width: 452px; " /></p>

<pre>
<strong>输入：</strong>root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
<strong>输出：</strong>3
<strong>解释：</strong>和等于 8 的路径有 3 条，如图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li>二叉树的节点个数的范围是 <code>[0,1000]</code></li>
	<li><meta charset="UTF-8" /><code>-10<sup>9</sup> <= Node.val <= 10<sup>9</sup></code> </li>
	<li><code>-1000 <= targetSum <= 1000</code> </li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和 + 递归

我们可以运用前缀和的思想，对二叉树进行递归遍历，同时用哈希表 $\textit{cnt}$ 统计从根节点到当前节点的路径上各个前缀和出现的次数。

我们设计一个递归函数 $\textit{dfs(node, s)}$，表示当前遍历到的节点为 $\textit{node}$，从根节点到当前节点的路径上的前缀和为 $s$。函数的返回值是统计以 $\textit{node}$ 节点及其子树节点作为路径终点且路径和为 $\textit{targetSum}$ 的路径数目。那么答案就是 $\textit{dfs(root, 0)}$。

函数 $\textit{dfs(node, s)}$ 的递归过程如下：

-   如果当前节点 $\textit{node}$ 为空，则返回 $0$。
-   计算从根节点到当前节点的路径上的前缀和 $s$。
-   用 $\textit{cnt}[s - \textit{targetSum}]$ 表示以当前节点为路径终点且路径和为 $\textit{targetSum}$ 的路径数目，其中 $\textit{cnt}[s - \textit{targetSum}]$ 即为 $\textit{cnt}$ 中前缀和为 $s - \textit{targetSum}$ 的个数。
-   将前缀和 $s$ 的计数值加 $1$，即 $\textit{cnt}[s] = \textit{cnt}[s] + 1$。
-   递归地遍历当前节点的左右子节点，即调用函数 $\textit{dfs(node.left, s)}$ 和 $\textit{dfs(node.right, s)}$，并将它们的返回值相加。
-   在返回值计算完成以后，需要将当前节点的前缀和 $s$ 的计数值减 $1$，即执行 $\textit{cnt}[s] = \textit{cnt}[s] - 1$。
-   最后返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点个数。

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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def dfs(node, s):
            if node is None:
                return 0
            s += node.val
            ans = cnt[s - targetSum]
            cnt[s] += 1
            ans += dfs(node.left, s)
            ans += dfs(node.right, s)
            cnt[s] -= 1
            return ans

        cnt = Counter({0: 1})
        return dfs(root, 0)
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
    private Map<Long, Integer> cnt = new HashMap<>();
    private int targetSum;

    public int pathSum(TreeNode root, int targetSum) {
        cnt.put(0L, 1);
        this.targetSum = targetSum;
        return dfs(root, 0);
    }

    private int dfs(TreeNode node, long s) {
        if (node == null) {
            return 0;
        }
        s += node.val;
        int ans = cnt.getOrDefault(s - targetSum, 0);
        cnt.merge(s, 1, Integer::sum);
        ans += dfs(node.left, s);
        ans += dfs(node.right, s);
        cnt.merge(s, -1, Integer::sum);
        return ans;
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> cnt;
        cnt[0] = 1;
        auto dfs = [&](this auto&& dfs, TreeNode* node, long long s) -> int {
            if (!node) {
                return 0;
            }
            s += node->val;
            int ans = cnt[s - targetSum];
            ++cnt[s];
            ans += dfs(node->left, s) + dfs(node->right, s);
            --cnt[s];
            return ans;
        };
        return dfs(root, 0);
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
func pathSum(root *TreeNode, targetSum int) int {
	cnt := map[int]int{0: 1}
	var dfs func(*TreeNode, int) int
	dfs = func(node *TreeNode, s int) int {
		if node == nil {
			return 0
		}
		s += node.Val
		ans := cnt[s-targetSum]
		cnt[s]++
		ans += dfs(node.Left, s) + dfs(node.Right, s)
		cnt[s]--
		return ans
	}
	return dfs(root, 0)
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

function pathSum(root: TreeNode | null, targetSum: number): number {
    const cnt: Map<number, number> = new Map();
    const dfs = (node: TreeNode | null, s: number): number => {
        if (!node) {
            return 0;
        }
        s += node.val;
        let ans = cnt.get(s - targetSum) ?? 0;
        cnt.set(s, (cnt.get(s) ?? 0) + 1);
        ans += dfs(node.left, s);
        ans += dfs(node.right, s);
        cnt.set(s, (cnt.get(s) ?? 0) - 1);
        return ans;
    };
    cnt.set(0, 1);
    return dfs(root, 0);
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
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;

impl Solution {
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> i32 {
        let mut cnt = HashMap::new();
        cnt.insert(0, 1);

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, s: i64, target: i64, cnt: &mut HashMap<i64, i32>) -> i32 {
            if let Some(n) = node {
                let n = n.borrow();
                let s = s + n.val as i64;
                let ans = cnt.get(&(s - target)).copied().unwrap_or(0);
                *cnt.entry(s).or_insert(0) += 1;
                let ans = ans + dfs(n.left.clone(), s, target, cnt) + dfs(n.right.clone(), s, target, cnt);
                *cnt.get_mut(&s).unwrap() -= 1;
                ans
            } else {
                0
            }
        }

        dfs(root, 0, target_sum as i64, &mut cnt)
    }
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
 * @param {number} targetSum
 * @return {number}
 */
var pathSum = function (root, targetSum) {
    const cnt = new Map();
    const dfs = (node, s) => {
        if (!node) {
            return 0;
        }
        s += node.val;
        let ans = cnt.get(s - targetSum) || 0;
        cnt.set(s, (cnt.get(s) || 0) + 1);
        ans += dfs(node.left, s);
        ans += dfs(node.right, s);
        cnt.set(s, cnt.get(s) - 1);
        return ans;
    };
    cnt.set(0, 1);
    return dfs(root, 0);
};
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int PathSum(TreeNode root, int targetSum) {
        Dictionary<long, int> cnt = new Dictionary<long, int>();

        int Dfs(TreeNode node, long s) {
            if (node == null) {
                return 0;
            }
            s += node.val;
            int ans = cnt.GetValueOrDefault(s - targetSum, 0);
            cnt[s] = cnt.GetValueOrDefault(s, 0) + 1;
            ans += Dfs(node.left, s);
            ans += Dfs(node.right, s);
            cnt[s]--;
            return ans;
        }

        cnt[0] = 1;
        return Dfs(root, 0);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string){#438}

{{< tabs "438" >}}

{{% tab "python" %}}
```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        m, n = len(s), len(p)
        ans = []
        if m < n:
            return ans
        cnt1 = Counter(p)
        cnt2 = Counter()
        j = 0
        for i, c in enumerate(s):
            cnt2[c] += 1
            while cnt2[c] > cnt1[c]:
                cnt2[s[j]] -= 1
                j += 1
            if i - j + 1 == n:
                ans.append(j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int m = s.length(), n = p.length();
        List<Integer> ans = new ArrayList<>();
        if (m < n) {
            return ans;
        }
        int[] cnt1 = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt1[p.charAt(i) - 'a'];
        }
        int[] cnt2 = new int[26];
        for (int i = 0, j = 0; i < m; ++i) {
            int k = s.charAt(i) - 'a';
            ++cnt2[k];
            while (cnt2[k] > cnt1[k]) {
                --cnt2[s.charAt(j++) - 'a'];
            }
            if (i - j + 1 == n) {
                ans.add(j);
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
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;
        if (m < n) {
            return ans;
        }
        vector<int> cnt1(26);
        for (char& c : p) {
            ++cnt1[c - 'a'];
        }
        vector<int> cnt2(26);
        for (int i = 0, j = 0; i < m; ++i) {
            int k = s[i] - 'a';
            ++cnt2[k];
            while (cnt2[k] > cnt1[k]) {
                --cnt2[s[j++] - 'a'];
            }
            if (i - j + 1 == n) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findAnagrams(s string, p string) (ans []int) {
	m, n := len(s), len(p)
	if m < n {
		return
	}
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	for _, c := range p {
		cnt1[c-'a']++
	}
	j := 0
	for i, c := range s {
		cnt2[c-'a']++
		for cnt2[c-'a'] > cnt1[c-'a'] {
			cnt2[s[j]-'a']--
			j++
		}
		if i-j+1 == n {
			ans = append(ans, j)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findAnagrams(s: string, p: string): number[] {
    const m = s.length;
    const n = p.length;
    const ans: number[] = [];
    if (m < n) {
        return ans;
    }
    const cnt1: number[] = Array(26).fill(0);
    const cnt2: number[] = Array(26).fill(0);
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    for (const c of p) {
        ++cnt1[idx(c)];
    }
    for (let i = 0, j = 0; i < m; ++i) {
        const k = idx(s[i]);
        ++cnt2[k];
        while (cnt2[k] > cnt1[k]) {
            --cnt2[idx(s[j++])];
        }
        if (i - j + 1 === n) {
            ans.push(j);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let (s, p) = (s.as_bytes(), p.as_bytes());
        let (m, n) = (s.len(), p.len());
        let mut ans = vec![];
        if m < n {
            return ans;
        }

        let mut cnt = [0; 26];
        for i in 0..n {
            cnt[(p[i] - b'a') as usize] += 1;
            cnt[(s[i] - b'a') as usize] -= 1;
        }
        for i in n..m {
            if cnt.iter().all(|&v| v == 0) {
                ans.push((i - n) as i32);
            }
            cnt[(s[i] - b'a') as usize] -= 1;
            cnt[(s[i - n] - b'a') as usize] += 1;
        }
        if cnt.iter().all(|&v| v == 0) {
            ans.push((m - n) as i32);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        int m = s.Length, n = p.Length;
        IList<int> ans = new List<int>();
        if (m < n) {
            return ans;
        }
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt1[p[i] - 'a'];
        }
        for (int i = 0, j = 0; i < m; ++i) {
            int k = s[i] - 'a';
            ++cnt2[k];
            while (cnt2[k] > cnt1[k]) {
                --cnt2[s[j++] - 'a'];
            }
            if (i - j + 1 == n) {
                ans.Add(j);
            }
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

<p>给定两个字符串&nbsp;<code>s</code>&nbsp;和 <code>p</code>，找到&nbsp;<code>s</code><strong>&nbsp;</strong>中所有&nbsp;<code>p</code><strong>&nbsp;</strong>的&nbsp;<strong><span data-keyword="anagram">异位词</span>&nbsp;</strong>的子串，返回这些子串的起始索引。不考虑答案输出的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入: </strong>s = "cbaebabacd", p = "abc"
<strong>输出: </strong>[0,6]
<strong>解释:</strong>
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
</pre>

<p><strong>&nbsp;示例 2:</strong></p>

<pre>
<strong>输入: </strong>s = "abab", p = "ab"
<strong>输出: </strong>[0,1,2]
<strong>解释:</strong>
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, p.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>p</code>&nbsp;仅包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们不妨设字符串 $s$ 的长度为 $m$，字符串 $p$ 的长度为 $n$。

如果 $m \lt n$，那么 $s$ 中不可能存在任何一个子串同 $p$ 为异位词，返回空列表即可。

当 $m \ge n$ 时，我们可以使用一个固定长度为 $n$ 的滑动窗口来维护 $s$ 的子串。为了判断子串是否为 $p$ 的异位词，我们可以用一个固定长度为 $26$ 的数组 $cnt1$ 记录 $p$ 中每个字母的出现次数，再用另一个数组 $cnt2$ 记录当前滑动窗口中每个字母的出现次数，如果这两个数组相同，那么当前滑动窗口的子串就是 $p$ 的异位词，我们记录下起始位置。

时间复杂度 $O(m \times C)$，空间复杂度 $O(C)$。其中 $m$ 是字符串 $s$ 的长度；而 $C$ 是字符集大小，在本题中字符集为所有小写字母，所以 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        m, n = len(s), len(p)
        ans = []
        if m < n:
            return ans
        cnt1 = Counter(p)
        cnt2 = Counter(s[: n - 1])
        for i in range(n - 1, m):
            cnt2[s[i]] += 1
            if cnt1 == cnt2:
                ans.append(i - n + 1)
            cnt2[s[i - n + 1]] -= 1
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int m = s.length(), n = p.length();
        List<Integer> ans = new ArrayList<>();
        if (m < n) {
            return ans;
        }
        int[] cnt1 = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt1[p.charAt(i) - 'a'];
        }
        int[] cnt2 = new int[26];
        for (int i = 0; i < n - 1; ++i) {
            ++cnt2[s.charAt(i) - 'a'];
        }
        for (int i = n - 1; i < m; ++i) {
            ++cnt2[s.charAt(i) - 'a'];
            if (Arrays.equals(cnt1, cnt2)) {
                ans.add(i - n + 1);
            }
            --cnt2[s.charAt(i - n + 1) - 'a'];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;
        if (m < n) {
            return ans;
        }
        vector<int> cnt1(26);
        for (char& c : p) {
            ++cnt1[c - 'a'];
        }
        vector<int> cnt2(26);
        for (int i = 0; i < n - 1; ++i) {
            ++cnt2[s[i] - 'a'];
        }
        for (int i = n - 1; i < m; ++i) {
            ++cnt2[s[i] - 'a'];
            if (cnt1 == cnt2) {
                ans.push_back(i - n + 1);
            }
            --cnt2[s[i - n + 1] - 'a'];
        }
        return ans;
    }
};
```

#### Go

```go
func findAnagrams(s string, p string) (ans []int) {
	m, n := len(s), len(p)
	if m < n {
		return
	}
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	for _, c := range p {
		cnt1[c-'a']++
	}
	for _, c := range s[:n-1] {
		cnt2[c-'a']++
	}
	for i := n - 1; i < m; i++ {
		cnt2[s[i]-'a']++
		if cnt1 == cnt2 {
			ans = append(ans, i-n+1)
		}
		cnt2[s[i-n+1]-'a']--
	}
	return
}
```

#### TypeScript

```ts
function findAnagrams(s: string, p: string): number[] {
    const m = s.length;
    const n = p.length;
    const ans: number[] = [];
    if (m < n) {
        return ans;
    }
    const cnt1: number[] = new Array(26).fill(0);
    const cnt2: number[] = new Array(26).fill(0);
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    for (const c of p) {
        ++cnt1[idx(c)];
    }
    for (const c of s.slice(0, n - 1)) {
        ++cnt2[idx(c)];
    }
    for (let i = n - 1; i < m; ++i) {
        ++cnt2[idx(s[i])];
        if (cnt1.toString() === cnt2.toString()) {
            ans.push(i - n + 1);
        }
        --cnt2[idx(s[i - n + 1])];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let (s, p) = (s.as_bytes(), p.as_bytes());
        let (m, n) = (s.len(), p.len());
        let mut ans = vec![];
        if m < n {
            return ans;
        }

        let mut cnt = [0; 26];
        for i in 0..n {
            cnt[(p[i] - b'a') as usize] += 1;
            cnt[(s[i] - b'a') as usize] -= 1;
        }
        for i in n..m {
            if cnt.iter().all(|&v| v == 0) {
                ans.push((i - n) as i32);
            }
            cnt[(s[i] - b'a') as usize] -= 1;
            cnt[(s[i - n] - b'a') as usize] += 1;
        }
        if cnt.iter().all(|&v| v == 0) {
            ans.push((m - n) as i32);
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        int m = s.Length, n = p.Length;
        IList<int> ans = new List<int>();
        if (m < n) {
            return ans;
        }
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt1[p[i] - 'a'];
        }
        for (int i = 0, j = 0; i < m; ++i) {
            int k = s[i] - 'a';
            ++cnt2[k];
            while (cnt2[k] > cnt1[k]) {
                --cnt2[s[j++] - 'a'];
            }
            if (i - j + 1 == n) {
                ans.Add(j);
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针（滑动窗口优化）

我们可以对方法一进行优化，与方法一类似，我们用一个固定长度为 $26$ 的数组 $cnt1$ 记录 $p$ 中每个字母的出现次数，用另一个数组 $cnt2$ 记录当前滑动窗口中每个字母的出现次数，用指针 $i$ 和 $j$ 分别指向滑动窗口的左右边界。每一次移动指针 $j$，将 $cnt2[s[j]]$ 的值加 $1$，如果当前 $cnt2[s[j]]$ 的值大于 $cnt1[s[j]]$，则将指针 $i$ 不断右移，直到 $cnt2[s[j]]$ 的值不大于 $cnt1[s[j]]$。此时，如果滑动窗口的长度等于 $p$ 的长度，我们就找到了一个异位词，将起始位置加入答案。继续移动指针 $j$，重复上述操作，直到指针 $j$ 移动到 $s$ 的末尾。

时间复杂度 $(m + n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $p$ 的长度；而 $C$ 是字符集大小，在本题中字符集为所有小写字母，所以 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        m, n = len(s), len(p)
        ans = []
        if m < n:
            return ans
        cnt1 = Counter(p)
        cnt2 = Counter()
        j = 0
        for i, c in enumerate(s):
            cnt2[c] += 1
            while cnt2[c] > cnt1[c]:
                cnt2[s[j]] -= 1
                j += 1
            if i - j + 1 == n:
                ans.append(j)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int m = s.length(), n = p.length();
        List<Integer> ans = new ArrayList<>();
        if (m < n) {
            return ans;
        }
        int[] cnt1 = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt1[p.charAt(i) - 'a'];
        }
        int[] cnt2 = new int[26];
        for (int i = 0, j = 0; i < m; ++i) {
            int k = s.charAt(i) - 'a';
            ++cnt2[k];
            while (cnt2[k] > cnt1[k]) {
                --cnt2[s.charAt(j++) - 'a'];
            }
            if (i - j + 1 == n) {
                ans.add(j);
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
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> ans;
        if (m < n) {
            return ans;
        }
        vector<int> cnt1(26);
        for (char& c : p) {
            ++cnt1[c - 'a'];
        }
        vector<int> cnt2(26);
        for (int i = 0, j = 0; i < m; ++i) {
            int k = s[i] - 'a';
            ++cnt2[k];
            while (cnt2[k] > cnt1[k]) {
                --cnt2[s[j++] - 'a'];
            }
            if (i - j + 1 == n) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findAnagrams(s string, p string) (ans []int) {
	m, n := len(s), len(p)
	if m < n {
		return
	}
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	for _, c := range p {
		cnt1[c-'a']++
	}
	j := 0
	for i, c := range s {
		cnt2[c-'a']++
		for cnt2[c-'a'] > cnt1[c-'a'] {
			cnt2[s[j]-'a']--
			j++
		}
		if i-j+1 == n {
			ans = append(ans, j)
		}
	}
	return
}
```

#### TypeScript

```ts
function findAnagrams(s: string, p: string): number[] {
    const m = s.length;
    const n = p.length;
    const ans: number[] = [];
    if (m < n) {
        return ans;
    }
    const cnt1: number[] = Array(26).fill(0);
    const cnt2: number[] = Array(26).fill(0);
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    for (const c of p) {
        ++cnt1[idx(c)];
    }
    for (let i = 0, j = 0; i < m; ++i) {
        const k = idx(s[i]);
        ++cnt2[k];
        while (cnt2[k] > cnt1[k]) {
            --cnt2[idx(s[j++])];
        }
        if (i - j + 1 === n) {
            ans.push(j);
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

# [439. 三元表达式解析器 🔒](https://leetcode.cn/problems/ternary-expression-parser){#439}

{{< tabs "439" >}}

{{% tab "python" %}}
```python
class Solution:
    def parseTernary(self, expression: str) -> str:
        stk = []
        cond = False
        for c in expression[::-1]:
            if c == ':':
                continue
            if c == '?':
                cond = True
            else:
                if cond:
                    if c == 'T':
                        x = stk.pop()
                        stk.pop()
                        stk.append(x)
                    else:
                        stk.pop()
                    cond = False
                else:
                    stk.append(c)
        return stk[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String parseTernary(String expression) {
        Deque<Character> stk = new ArrayDeque<>();
        boolean cond = false;
        for (int i = expression.length() - 1; i >= 0; --i) {
            char c = expression.charAt(i);
            if (c == ':') {
                continue;
            }
            if (c == '?') {
                cond = true;
            } else {
                if (cond) {
                    if (c == 'T') {
                        char x = stk.pop();
                        stk.pop();
                        stk.push(x);
                    } else {
                        stk.pop();
                    }
                    cond = false;
                } else {
                    stk.push(c);
                }
            }
        }
        return String.valueOf(stk.peek());
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string parseTernary(string expression) {
        string stk;
        bool cond = false;
        reverse(expression.begin(), expression.end());
        for (char& c : expression) {
            if (c == ':') {
                continue;
            }
            if (c == '?') {
                cond = true;
            } else {
                if (cond) {
                    if (c == 'T') {
                        char x = stk.back();
                        stk.pop_back();
                        stk.pop_back();
                        stk.push_back(x);
                    } else {
                        stk.pop_back();
                    }
                    cond = false;
                } else {
                    stk.push_back(c);
                }
            }
        }
        return {stk[0]};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func parseTernary(expression string) string {
	stk := []byte{}
	cond := false
	for i := len(expression) - 1; i >= 0; i-- {
		c := expression[i]
		if c == ':' {
			continue
		}
		if c == '?' {
			cond = true
		} else {
			if cond {
				if c == 'T' {
					x := stk[len(stk)-1]
					stk = stk[:len(stk)-2]
					stk = append(stk, x)
				} else {
					stk = stk[:len(stk)-1]
				}
				cond = false
			} else {
				stk = append(stk, c)
			}
		}
	}
	return string(stk[0])
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表示任意嵌套三元表达式的字符串&nbsp;<code>expression</code>&nbsp;，求值并返回其结果。</p>

<p>你可以总是假设给定的表达式是有效的，并且只包含数字，&nbsp;<code>'?'</code>&nbsp;，&nbsp;&nbsp;<code>':'</code>&nbsp;，&nbsp;&nbsp;<code>'T'</code>&nbsp;和 <code>'F'</code> ，其中 <code>'T'</code> 为真， <code>'F'</code> 为假。表达式中的所有数字都是 <strong>一位</strong> 数(即在 <strong>[0,9] </strong>范围内)。</p>

<p>条件表达式从右到左分组(大多数语言中都是这样)，表达式的结果总是为数字，<code>'T'</code> 或 <code>'F'</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> expression = "T?2:3"
<strong>输出：</strong> "2"
<strong>解释：</strong> 如果条件为真，结果为 2；否则，结果为 3。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong> expression = "F?1:T?4:5"
<strong>输出：</strong> "4"
<strong>解释：</strong> 条件表达式自右向左结合。使用括号的话，相当于：
 "(F ? 1 : (T ? 4 : 5))" --&gt; "(F ? 1 : 4)" --&gt; "4"
or "(F ? 1 : (T ? 4 : 5))" --&gt; "(T ? 4 : 5)" --&gt; "4"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong> expression = "T?T?F:5:3"
<strong>输出：</strong> "F"
<strong>解释：</strong> 条件表达式自右向左结合。使用括号的话，相当于：
"(T ? (T ? F : 5) : 3)" --&gt; "(T ? F : 3)" --&gt; "F"
"(T ? (T ? F : 5) : 3)" --&gt; "(T ? F : 5)" --&gt; "F"</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>5 &lt;= expression.length &lt;= 10<sup>4</sup></code></li>
	<li><code>expression</code>&nbsp;由数字,&nbsp;<code>'T'</code>,&nbsp;<code>'F'</code>,&nbsp;<code>'?'</code>&nbsp;和&nbsp;<code>':'</code>&nbsp;组成</li>
	<li><strong>保证&nbsp;</strong>了表达式是一个有效的三元表达式，并且每个数字都是 <strong>一位数</strong>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们从右到左遍历字符串 `expression`，对于当前遍历到的字符 $c$：

-   如果 $c$ 是字符 `':'`，则跳过；
-   如果 $c$ 是字符 `'?'`，那么意味着下一个即将遍历到的字符是条件表达式的条件，我们用一个布尔变量 `cond` 标记；
-   如果 $c$ 的上一个遍历到的字符是 `'?'`，也即布尔变量 `cond` 为 `true`，那么我们判断当前字符 $c$ 是否为字符 `'T'`，如果是，那么我们要保留栈顶第一个元素，弹出栈顶第二个元素；否则，我们要保留栈顶第二个元素，弹出栈顶第一个元素。最后，将 `cond` 置为 `false`；
-   否则，我们将当前字符 $c$ 入栈。

最后，栈中只剩下一个元素，即为表达式的结果。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `expression` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def parseTernary(self, expression: str) -> str:
        stk = []
        cond = False
        for c in expression[::-1]:
            if c == ':':
                continue
            if c == '?':
                cond = True
            else:
                if cond:
                    if c == 'T':
                        x = stk.pop()
                        stk.pop()
                        stk.append(x)
                    else:
                        stk.pop()
                    cond = False
                else:
                    stk.append(c)
        return stk[0]
```

#### Java

```java
class Solution {
    public String parseTernary(String expression) {
        Deque<Character> stk = new ArrayDeque<>();
        boolean cond = false;
        for (int i = expression.length() - 1; i >= 0; --i) {
            char c = expression.charAt(i);
            if (c == ':') {
                continue;
            }
            if (c == '?') {
                cond = true;
            } else {
                if (cond) {
                    if (c == 'T') {
                        char x = stk.pop();
                        stk.pop();
                        stk.push(x);
                    } else {
                        stk.pop();
                    }
                    cond = false;
                } else {
                    stk.push(c);
                }
            }
        }
        return String.valueOf(stk.peek());
    }
}
```

#### C++

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        string stk;
        bool cond = false;
        reverse(expression.begin(), expression.end());
        for (char& c : expression) {
            if (c == ':') {
                continue;
            }
            if (c == '?') {
                cond = true;
            } else {
                if (cond) {
                    if (c == 'T') {
                        char x = stk.back();
                        stk.pop_back();
                        stk.pop_back();
                        stk.push_back(x);
                    } else {
                        stk.pop_back();
                    }
                    cond = false;
                } else {
                    stk.push_back(c);
                }
            }
        }
        return {stk[0]};
    }
};
```

#### Go

```go
func parseTernary(expression string) string {
	stk := []byte{}
	cond := false
	for i := len(expression) - 1; i >= 0; i-- {
		c := expression[i]
		if c == ':' {
			continue
		}
		if c == '?' {
			cond = true
		} else {
			if cond {
				if c == 'T' {
					x := stk[len(stk)-1]
					stk = stk[:len(stk)-2]
					stk = append(stk, x)
				} else {
					stk = stk[:len(stk)-1]
				}
				cond = false
			} else {
				stk = append(stk, c)
			}
		}
	}
	return string(stk[0])
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
