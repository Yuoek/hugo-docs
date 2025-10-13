---
title: "0510_二叉搜索树中的中序后继 II 🔒"
date: 2025-10-08T18:36:17+08:00
weight: 2
tags: [二叉搜索树, 二叉树, 动态规划, 哈希表, 字符串, 广度优先搜索, 数学, 数据库, 数组, 树, 水塘抽样, 深度优先搜索, 贪心, 随机化]
---

{{< markmap >}}
### [0510_二叉搜索树中的中序后继 II 🔒](#510)
#### [树](#510)
#### [二叉搜索树](#510)
#### [二叉树](#510)
### [0511_游戏玩法分析 I](#511)
#### [数据库](#511)
### [0512_游戏玩法分析 II 🔒](#512)
#### [数据库](#512)
### [0513_找树左下角的值](#513)
#### [树](#513)
#### [深度优先搜索](#513)
#### [广度优先搜索](#513)
#### [二叉树](#513)
### [0514_自由之路](#514)
#### [深度优先搜索](#514)
#### [广度优先搜索](#514)
#### [字符串](#514)
#### [动态规划](#514)
### [0515_在每个树行中找最大值](#515)
#### [树](#515)
#### [深度优先搜索](#515)
#### [广度优先搜索](#515)
#### [二叉树](#515)
### [0516_最长回文子序列](#516)
#### [字符串](#516)
#### [动态规划](#516)
### [0517_超级洗衣机](#517)
#### [贪心](#517)
#### [数组](#517)
### [0518_零钱兑换 II](#518)
#### [数组](#518)
#### [动态规划](#518)
### [0519_随机翻转矩阵](#519)
#### [水塘抽样](#519)
#### [哈希表](#519)
#### [数学](#519)
#### [随机化](#519)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0510_二叉搜索树中的中序后继 II 🔒
___
#### 树
___
#### 二叉搜索树
___
#### 二叉树
---
### 0511_游戏玩法分析 I
___
#### 数据库
---
### 0512_游戏玩法分析 II 🔒
___
#### 数据库
---
### 0513_找树左下角的值
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0514_自由之路
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 字符串
___
#### 动态规划
---
### 0515_在每个树行中找最大值
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0516_最长回文子序列
___
#### 字符串
___
#### 动态规划
---
### 0517_超级洗衣机
___
#### 贪心
___
#### 数组
---
### 0518_零钱兑换 II
___
#### 数组
___
#### 动态规划
---
### 0519_随机翻转矩阵
___
#### 水塘抽样
___
#### 哈希表
___
#### 数学
___
#### 随机化
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 动态规划 |
| 哈希表 | 字符串 | 广度优先搜索 |
| 数学 | 数据库 | 数组 |
| 树 | 水塘抽样 | 深度优先搜索 |
| 贪心 | 随机化 |  |

# [510. 二叉搜索树中的中序后继 II 🔒](https://leetcode.cn/problems/inorder-successor-in-bst-ii){#510}

{{< tabs "510" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        while node.parent and node.parent.right is node:
            node = node.parent
        return node.parent
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/

class Solution {
    public Node inorderSuccessor(Node node) {
        if (node.right != null) {
            node = node.right;
            while (node.left != null) {
                node = node.left;
            }
            return node;
        }
        while (node.parent != null && node.parent.right == node) {
            node = node.parent;
        }
        return node.parent;
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
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }
        while (node->parent && node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Parent *Node
 * }
 */

func inorderSuccessor(node *Node) *Node {
	if node.Right != nil {
		node = node.Right
		for node.Left != nil {
			node = node.Left
		}
		return node
	}
	for node.Parent != nil && node == node.Parent.Right {
		node = node.Parent
	}
	return node.Parent
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class Node {
 *     val: number
 *     left: Node | null
 *     right: Node | null
 *     parent: Node | null
 *     constructor(val?: number, left?: Node | null, right?: Node | null, parent?: Node | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *         this.parent = (parent===undefined ? null : parent)
 *     }
 * }
 */

function inorderSuccessor(node: Node | null): Node | null {
    if (node.right) {
        node = node.right;
        while (node.left) {
            node = node.left;
        }
        return node;
    }
    while (node.parent && node === node.parent.right) {
        node = node.parent;
    }
    return node.parent;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * // Definition for a Node.
 * function Node(val) {
 *    this.val = val;
 *    this.left = null;
 *    this.right = null;
 *    this.parent = null;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var inorderSuccessor = function (node) {
    if (node.right) {
        node = node.right;
        while (node.left) {
            node = node.left;
        }
        return node;
    }
    while (node.parent && node === node.parent.right) {
        node = node.parent;
    }
    return node.parent;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉搜索树和其中的一个节点 <code>node</code> ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 <code>null</code> 。</p>

<p>一个节点 <code>node</code> 的中序后继是键值比 <code>node.val</code> 大所有的节点中键值最小的那个。</p>

<p>你可以直接访问结点，但无法直接访问树。每个节点都会有其父节点的引用。节点&nbsp;<code>Node</code> 定义如下：</p>

<pre>
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}</pre>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0510.Inorder%20Successor%20in%20BST%20II/images/285_example_1.png" style="height: 117px; width: 122px;" /></p>

<pre>
<strong>输入：</strong>tree = [2,1,3], node = 1
<strong>输出：</strong>2
<strong>解析：</strong>1 的中序后继结点是 2 。注意节点和返回值都是 Node 类型的。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0510.Inorder%20Successor%20in%20BST%20II/images/285_example_2.png" style="height: 229px; width: 246px;" /></p>

<pre>
<strong>输入：</strong>tree = [5,3,6,2,4,null,null,1], node = 6
<strong>输出：</strong>null
<strong>解析：</strong>该结点没有中序后继，因此返回<code> null 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>4</sup>]</code> 内。</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>树中各结点的值均保证唯一。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否在不访问任何结点的值的情况下解决问题?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

如果 $\textit{node}$ 有右子树，那么 $\textit{node}$ 的中序后继节点是右子树中最左边的节点。

如果 $\textit{node}$ 没有右子树，那么如果 $\textit{node}$ 是其父节点的右子树，我们就一直向上搜索，直到节点的父节点为空，或者节点是其父节点的左子树，此时父节点就是中序后继节点。

时间复杂度 $O(h)$，其中 $h$ 是二叉树的高度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        while node.parent and node.parent.right is node:
            node = node.parent
        return node.parent
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/

class Solution {
    public Node inorderSuccessor(Node node) {
        if (node.right != null) {
            node = node.right;
            while (node.left != null) {
                node = node.left;
            }
            return node;
        }
        while (node.parent != null && node.parent.right == node) {
            node = node.parent;
        }
        return node.parent;
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
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }
        while (node->parent && node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
};
```

#### Go

```go
/**
 * Definition for Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Parent *Node
 * }
 */

func inorderSuccessor(node *Node) *Node {
	if node.Right != nil {
		node = node.Right
		for node.Left != nil {
			node = node.Left
		}
		return node
	}
	for node.Parent != nil && node == node.Parent.Right {
		node = node.Parent
	}
	return node.Parent
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class Node {
 *     val: number
 *     left: Node | null
 *     right: Node | null
 *     parent: Node | null
 *     constructor(val?: number, left?: Node | null, right?: Node | null, parent?: Node | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *         this.parent = (parent===undefined ? null : parent)
 *     }
 * }
 */

function inorderSuccessor(node: Node | null): Node | null {
    if (node.right) {
        node = node.right;
        while (node.left) {
            node = node.left;
        }
        return node;
    }
    while (node.parent && node === node.parent.right) {
        node = node.parent;
    }
    return node.parent;
}
```

#### JavaScript

```js
/**
 * // Definition for a Node.
 * function Node(val) {
 *    this.val = val;
 *    this.left = null;
 *    this.right = null;
 *    this.parent = null;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var inorderSuccessor = function (node) {
    if (node.right) {
        node = node.right;
        while (node.left) {
            node = node.left;
        }
        return node;
    }
    while (node.parent && node === node.parent.right) {
        node = node.parent;
    }
    return node.parent;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [511. 游戏玩法分析 I](https://leetcode.cn/problems/game-play-analysis-i){#511}

{{< tabs "511" >}}

{{% tab "python" %}}
```python
import pandas as pd


def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return (
        activity.groupby("player_id")
        .agg(first_login=("event_date", "min"))
        .reset_index()
    )
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>活动表&nbsp;<code>Activity</code>：</p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
在 SQL 中，表的主键是 (player_id, event_date)。
这张表展示了一些游戏玩家在游戏平台上的行为活动。
每行数据记录了一名玩家在退出平台之前，当天使用同一台设备登录平台后打开的游戏的数目（可能是 0 个）。
</pre>

<p>&nbsp;</p>

<p>查询每位玩家 <strong>第一次登录平台的日期</strong>。</p>

<p>查询结果的格式如下所示：</p>

<pre>
Activity 表：
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-05-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+

Result 表：
+-----------+-------------+
| player_id | first_login |
+-----------+-------------+
| 1         | 2016-03-01  |
| 2         | 2017-06-25  |
| 3         | 2016-03-02  |
+-----------+-------------+
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求最小值

我们可以用 `GROUP BY` 对 `player_id` 进行分组，然后取每一组中最小的 `event_date` 作为玩家第一次登录平台的日期。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return (
        activity.groupby("player_id")
        .agg(first_login=("event_date", "min"))
        .reset_index()
    )
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [512. 游戏玩法分析 II 🔒](https://leetcode.cn/problems/game-play-analysis-ii){#512}

{{< tabs "512" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY player_id
                ORDER BY event_date
            ) AS rk
        FROM Activity
    )
SELECT player_id, device_id
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Table:&nbsp;<code>Activity</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) 是这个表的两个主键(具有唯一值的列的组合)
这个表显示的是某些游戏玩家的游戏活动情况
每一行是在某天使用某个设备登出之前登录并玩多个游戏（可能为0）的玩家的记录
</pre>

<p>请编写解决方案，描述每一个玩家首次登陆的设备名称</p>

<p>返回结果格式如以下示例：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-05-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
<strong>输出：</strong>
+-----------+-----------+
| player_id | device_id |
+-----------+-----------+
| 1         | 2         |
| 2         | 3         |
| 3         | 1         |
+-----------+-----------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询

我们可以使用 `GROUP BY` 和 `MIN` 函数来找到每个玩家的第一次登录日期，然后使用联合键子查询来找到每个玩家的第一次登录设备。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    player_id,
    device_id
FROM Activity
WHERE
    (player_id, event_date) IN (
        SELECT
            player_id,
            MIN(event_date) AS event_date
        FROM Activity
        GROUP BY 1
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们可以使用窗口函数 `rank()`，它可以为每个玩家的每个登录日期分配一个排名，然后我们可以选择排名为 $1$ 的行。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY player_id
                ORDER BY event_date
            ) AS rk
        FROM Activity
    )
SELECT player_id, device_id
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [513. 找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value){#513}

{{< tabs "513" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        def dfs(root, curr):
            if root is None:
                return
            dfs(root.left, curr + 1)
            dfs(root.right, curr + 1)
            nonlocal ans, mx
            if mx < curr:
                mx = curr
                ans = root.val

        ans = mx = 0
        dfs(root, 1)
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
    private int ans = 0;
    private int mx = 0;

    public int findBottomLeftValue(TreeNode root) {
        dfs(root, 1);
        return ans;
    }

    private void dfs(TreeNode root, int curr) {
        if (root == null) {
            return;
        }
        dfs(root.left, curr + 1);
        dfs(root.right, curr + 1);
        if (mx < curr) {
            mx = curr;
            ans = root.val;
        }
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
    int ans = 0;
    int mx = 0;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }

    void dfs(TreeNode* root, int curr) {
        if (!root) return;
        dfs(root->left, curr + 1);
        dfs(root->right, curr + 1);
        if (mx < curr) {
            mx = curr;
            ans = root->val;
        }
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
func findBottomLeftValue(root *TreeNode) int {
	ans, mx := 0, 0
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, curr int) {
		if root == nil {
			return
		}
		dfs(root.Left, curr+1)
		dfs(root.Right, curr+1)
		if mx < curr {
			mx = curr
			ans = root.Val
		}
	}
	dfs(root, 1)
	return ans
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

function findBottomLeftValue(root: TreeNode | null): number {
    let mx = 0;
    let ans = 0;

    function dfs(root, curr) {
        if (!root) {
            return;
        }
        dfs(root.left, curr + 1);
        dfs(root.right, curr + 1);
        if (mx < curr) {
            mx = curr;
            ans = root.val;
        }
    }
    dfs(root, 1);
    return ans;
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
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, cur: i32, max: &mut i32, res: &mut i32) {
        if root.is_none() {
            return;
        }
        let root = root.as_ref().unwrap().borrow();
        Self::dfs(&root.left, cur + 1, max, res);
        Self::dfs(&root.right, cur + 1, max, res);
        if *max < cur {
            *max = cur;
            *res = root.val;
        }
    }

    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max = 0;
        let mut res = 0;
        Self::dfs(&root, 1, &mut max, &mut res);
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树的 <strong>根节点</strong> <code>root</code>，请找出该二叉树的 <strong>最底层 最左边 </strong>节点的值。</p>

<p>假设二叉树中至少有一个节点。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0513.Find%20Bottom%20Left%20Tree%20Value/images/tree1.jpg" style="width: 182px; " /></p>

<pre>
<strong>输入: </strong>root = [2,1,3]
<strong>输出: </strong>1
</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0513.Find%20Bottom%20Left%20Tree%20Value/images/tree2.jpg" style="width: 242px; " /><strong> </strong></p>

<pre>
<strong>输入: </strong>[1,2,3,4,null,5,6,null,null,7]
<strong>输出: </strong>7
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li>二叉树的节点个数的范围是 <code>[1,10<sup>4</sup>]</code></li>
	<li><meta charset="UTF-8" /><code>-2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1</code> </li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

BFS 找最后一层第一个节点。

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
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        ans = 0
        while q:
            ans = q[0].val
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int ans = 0;
        while (!q.isEmpty()) {
            ans = q.peek().val;
            for (int i = q.size(); i > 0; --i) {
                TreeNode node = q.poll();
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
        }
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        while (!q.empty()) {
            ans = q.front()->val;
            for (int i = q.size(); i; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
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
func findBottomLeftValue(root *TreeNode) int {
	q := []*TreeNode{root}
	ans := 0
	for len(q) > 0 {
		ans = q[0].Val
		for i := len(q); i > 0; i-- {
			node := q[0]
			q = q[1:]
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
	}
	return ans
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

function findBottomLeftValue(root: TreeNode | null): number {
    let ans = 0;
    const q = [root];
    while (q.length) {
        ans = q[0].val;
        for (let i = q.length; i; --i) {
            const node = q.shift();
            if (node.left) {
                q.push(node.left);
            }
            if (node.right) {
                q.push(node.right);
            }
        }
    }
    return ans;
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
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back(root);
        let mut res = 0;
        while !queue.is_empty() {
            res = queue.front().unwrap().as_ref().unwrap().borrow_mut().val;
            for _ in 0..queue.len() {
                let node = queue.pop_front().unwrap();
                let mut node = node.as_ref().unwrap().borrow_mut();
                if node.left.is_some() {
                    queue.push_back(node.left.take());
                }
                if node.right.is_some() {
                    queue.push_back(node.right.take());
                }
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

DFS 先序遍历，找深度最大的，且第一次被遍历到的节点。

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
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        def dfs(root, curr):
            if root is None:
                return
            dfs(root.left, curr + 1)
            dfs(root.right, curr + 1)
            nonlocal ans, mx
            if mx < curr:
                mx = curr
                ans = root.val

        ans = mx = 0
        dfs(root, 1)
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
    private int ans = 0;
    private int mx = 0;

    public int findBottomLeftValue(TreeNode root) {
        dfs(root, 1);
        return ans;
    }

    private void dfs(TreeNode root, int curr) {
        if (root == null) {
            return;
        }
        dfs(root.left, curr + 1);
        dfs(root.right, curr + 1);
        if (mx < curr) {
            mx = curr;
            ans = root.val;
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int mx = 0;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }

    void dfs(TreeNode* root, int curr) {
        if (!root) return;
        dfs(root->left, curr + 1);
        dfs(root->right, curr + 1);
        if (mx < curr) {
            mx = curr;
            ans = root->val;
        }
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
func findBottomLeftValue(root *TreeNode) int {
	ans, mx := 0, 0
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, curr int) {
		if root == nil {
			return
		}
		dfs(root.Left, curr+1)
		dfs(root.Right, curr+1)
		if mx < curr {
			mx = curr
			ans = root.Val
		}
	}
	dfs(root, 1)
	return ans
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

function findBottomLeftValue(root: TreeNode | null): number {
    let mx = 0;
    let ans = 0;

    function dfs(root, curr) {
        if (!root) {
            return;
        }
        dfs(root.left, curr + 1);
        dfs(root.right, curr + 1);
        if (mx < curr) {
            mx = curr;
            ans = root.val;
        }
    }
    dfs(root, 1);
    return ans;
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
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, cur: i32, max: &mut i32, res: &mut i32) {
        if root.is_none() {
            return;
        }
        let root = root.as_ref().unwrap().borrow();
        Self::dfs(&root.left, cur + 1, max, res);
        Self::dfs(&root.right, cur + 1, max, res);
        if *max < cur {
            *max = cur;
            *res = root.val;
        }
    }

    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max = 0;
        let mut res = 0;
        Self::dfs(&root, 1, &mut max, &mut res);
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [514. 自由之路](https://leetcode.cn/problems/freedom-trail){#514}

{{< tabs "514" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        m, n = len(key), len(ring)
        pos = defaultdict(list)
        for i, c in enumerate(ring):
            pos[c].append(i)
        f = [[inf] * n for _ in range(m)]
        for j in pos[key[0]]:
            f[0][j] = min(j, n - j) + 1
        for i in range(1, m):
            for j in pos[key[i]]:
                for k in pos[key[i - 1]]:
                    f[i][j] = min(
                        f[i][j], f[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1
                    )
        return min(f[-1][j] for j in pos[key[-1]])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findRotateSteps(String ring, String key) {
        int m = key.length(), n = ring.length();
        List<Integer>[] pos = new List[26];
        Arrays.setAll(pos, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            int j = ring.charAt(i) - 'a';
            pos[j].add(i);
        }
        int[][] f = new int[m][n];
        for (var g : f) {
            Arrays.fill(g, 1 << 30);
        }
        for (int j : pos[key.charAt(0) - 'a']) {
            f[0][j] = Math.min(j, n - j) + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j : pos[key.charAt(i) - 'a']) {
                for (int k : pos[key.charAt(i - 1) - 'a']) {
                    f[i][j] = Math.min(
                        f[i][j], f[i - 1][k] + Math.min(Math.abs(j - k), n - Math.abs(j - k)) + 1);
                }
            }
        }
        int ans = 1 << 30;
        for (int j : pos[key.charAt(m - 1) - 'a']) {
            ans = Math.min(ans, f[m - 1][j]);
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
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<int> pos[26];
        for (int j = 0; j < n; ++j) {
            pos[ring[j] - 'a'].push_back(j);
        }
        int f[m][n];
        memset(f, 0x3f, sizeof(f));
        for (int j : pos[key[0] - 'a']) {
            f[0][j] = min(j, n - j) + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j : pos[key[i] - 'a']) {
                for (int k : pos[key[i - 1] - 'a']) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        int ans = 1 << 30;
        for (int j : pos[key[m - 1] - 'a']) {
            ans = min(ans, f[m - 1][j]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findRotateSteps(ring string, key string) int {
	m, n := len(key), len(ring)
	pos := [26][]int{}
	for j, c := range ring {
		pos[c-'a'] = append(pos[c-'a'], j)
	}
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = 1 << 30
		}
	}
	for _, j := range pos[key[0]-'a'] {
		f[0][j] = min(j, n-j) + 1
	}
	for i := 1; i < m; i++ {
		for _, j := range pos[key[i]-'a'] {
			for _, k := range pos[key[i-1]-'a'] {
				f[i][j] = min(f[i][j], f[i-1][k]+min(abs(j-k), n-abs(j-k))+1)
			}
		}
	}
	ans := 1 << 30
	for _, j := range pos[key[m-1]-'a'] {
		ans = min(ans, f[m-1][j])
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findRotateSteps(ring: string, key: string): number {
    const m: number = key.length;
    const n: number = ring.length;
    const pos: number[][] = Array.from({ length: 26 }, () => []);
    for (let i = 0; i < n; ++i) {
        const j: number = ring.charCodeAt(i) - 'a'.charCodeAt(0);
        pos[j].push(i);
    }

    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(1 << 30));
    for (const j of pos[key.charCodeAt(0) - 'a'.charCodeAt(0)]) {
        f[0][j] = Math.min(j, n - j) + 1;
    }

    for (let i = 1; i < m; ++i) {
        for (const j of pos[key.charCodeAt(i) - 'a'.charCodeAt(0)]) {
            for (const k of pos[key.charCodeAt(i - 1) - 'a'.charCodeAt(0)]) {
                f[i][j] = Math.min(
                    f[i][j],
                    f[i - 1][k] + Math.min(Math.abs(j - k), n - Math.abs(j - k)) + 1,
                );
            }
        }
    }

    let ans: number = 1 << 30;
    for (const j of pos[key.charCodeAt(m - 1) - 'a'.charCodeAt(0)]) {
        ans = Math.min(ans, f[m - 1][j]);
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

<p>电子游戏“辐射4”中，任务 <strong>“通向自由”</strong> 要求玩家到达名为 “<strong>Freedom Trail Ring”</strong> 的金属表盘，并使用表盘拼写特定关键词才能开门。</p>

<p>给定一个字符串&nbsp;<code>ring</code>&nbsp;，表示刻在外环上的编码；给定另一个字符串&nbsp;<code>key</code>&nbsp;，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的<strong>最少</strong>步数。</p>

<p>最初，<strong>ring&nbsp;</strong>的第一个字符与 <code>12:00</code> 方向对齐。您需要顺时针或逆时针旋转 <code>ring</code> 以使&nbsp;<strong>key&nbsp;</strong>的一个字符在 <code>12:00</code> 方向对齐，然后按下中心按钮，以此逐个拼写完&nbsp;<strong><code>key</code>&nbsp;</strong>中的所有字符。</p>

<p>旋转&nbsp;<code>ring</code><strong>&nbsp;</strong>拼出 key 字符&nbsp;<code>key[i]</code><strong>&nbsp;</strong>的阶段中：</p>

<ol>
	<li>您可以将&nbsp;<strong>ring&nbsp;</strong>顺时针或逆时针旋转&nbsp;<strong>一个位置&nbsp;</strong>，计为1步。旋转的最终目的是将字符串&nbsp;<strong><code>ring</code>&nbsp;</strong>的一个字符与 <code>12:00</code> 方向对齐，并且这个字符必须等于字符&nbsp;<strong><code>key[i]</code> 。</strong></li>
	<li>如果字符&nbsp;<strong><code>key[i]</code>&nbsp;</strong>已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作&nbsp;<strong>1 步</strong>。按完之后，您可以开始拼写&nbsp;<strong>key&nbsp;</strong>的下一个字符（下一阶段）, 直至完成所有拼写。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0514.Freedom%20Trail/images/ring.jpg" style="height: 450px; width: 450px;" /></p>

<center>&nbsp;</center>

<pre>
<strong>输入:</strong> ring = "godding", key = "gd"
<strong>输出:</strong> 4
<strong>解释:</strong>
 对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。 
 对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
 当然, 我们还需要1步进行拼写。
 因此最终的输出是 4。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> ring = "godding", key = "godding"
<strong>输出:</strong> 13
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ring.length, key.length &lt;= 100</code></li>
	<li><code>ring</code>&nbsp;和&nbsp;<code>key</code>&nbsp;只包含小写英文字母</li>
	<li><strong>保证</strong> 字符串&nbsp;<code>key</code>&nbsp;一定可以由字符串 &nbsp;<code>ring</code>&nbsp;旋转拼出</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们首先预处理出字符串 $ring$ 中每个字符 $c$ 出现的位置列表，记录在数组 $pos[c]$ 中。不妨假设字符串 $key$ 和 $ring$ 的长度分别为 $m$ 和 $n$。

然后我们定义 $f[i][j]$ 表示拼写完字符串 $key$ 的前 $i+1$ 个字符，且 $ring$ 的第 $j$ 个字符与 $12:00$ 方向对齐的最少步数。初始时 $f[i][j]=+\infty$。答案为 $\min_{0 \leq j < n} f[m - 1][j]$。

我们可以先初始化 $f[0][j]$，其中 $j$ 是字符 $key[0]$ 在 $ring$ 中出现的位置。由于 $ring$ 的第 $j$ 个字符与 $12:00$ 方向对齐，因此我们只需要 $1$ 步即可拼写出 $key[0]$。此外，我们还需要 $min(j, n - j)$ 步将 $ring$ 旋转到 $12:00$ 方向。因此 $f[0][j]=min(j, n - j) + 1$。

接下来，我们考虑当 $i \geq 1$ 时，状态如何转移。我们可以枚举 $key[i]$ 在 $ring$ 中的位置列表 $pos[key[i]]$，并枚举 $key[i-1]$ 在 $ring$ 中的位置列表 $pos[key[i-1]]$，然后更新 $f[i][j]$，即 $f[i][j]=\min_{k \in pos[key[i-1]]} f[i-1][k] + \min(\textit{abs}(j - k), n - \textit{abs}(j - k)) + 1$。

最后，我们返回 $\min_{0 \leq j \lt n} f[m - 1][j]$ 即可。

时间复杂度 $O(m \times n^2)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是字符串 $key$ 和 $ring$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        m, n = len(key), len(ring)
        pos = defaultdict(list)
        for i, c in enumerate(ring):
            pos[c].append(i)
        f = [[inf] * n for _ in range(m)]
        for j in pos[key[0]]:
            f[0][j] = min(j, n - j) + 1
        for i in range(1, m):
            for j in pos[key[i]]:
                for k in pos[key[i - 1]]:
                    f[i][j] = min(
                        f[i][j], f[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1
                    )
        return min(f[-1][j] for j in pos[key[-1]])
```

#### Java

```java
class Solution {
    public int findRotateSteps(String ring, String key) {
        int m = key.length(), n = ring.length();
        List<Integer>[] pos = new List[26];
        Arrays.setAll(pos, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            int j = ring.charAt(i) - 'a';
            pos[j].add(i);
        }
        int[][] f = new int[m][n];
        for (var g : f) {
            Arrays.fill(g, 1 << 30);
        }
        for (int j : pos[key.charAt(0) - 'a']) {
            f[0][j] = Math.min(j, n - j) + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j : pos[key.charAt(i) - 'a']) {
                for (int k : pos[key.charAt(i - 1) - 'a']) {
                    f[i][j] = Math.min(
                        f[i][j], f[i - 1][k] + Math.min(Math.abs(j - k), n - Math.abs(j - k)) + 1);
                }
            }
        }
        int ans = 1 << 30;
        for (int j : pos[key.charAt(m - 1) - 'a']) {
            ans = Math.min(ans, f[m - 1][j]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<int> pos[26];
        for (int j = 0; j < n; ++j) {
            pos[ring[j] - 'a'].push_back(j);
        }
        int f[m][n];
        memset(f, 0x3f, sizeof(f));
        for (int j : pos[key[0] - 'a']) {
            f[0][j] = min(j, n - j) + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j : pos[key[i] - 'a']) {
                for (int k : pos[key[i - 1] - 'a']) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        int ans = 1 << 30;
        for (int j : pos[key[m - 1] - 'a']) {
            ans = min(ans, f[m - 1][j]);
        }
        return ans;
    }
};
```

#### Go

```go
func findRotateSteps(ring string, key string) int {
	m, n := len(key), len(ring)
	pos := [26][]int{}
	for j, c := range ring {
		pos[c-'a'] = append(pos[c-'a'], j)
	}
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = 1 << 30
		}
	}
	for _, j := range pos[key[0]-'a'] {
		f[0][j] = min(j, n-j) + 1
	}
	for i := 1; i < m; i++ {
		for _, j := range pos[key[i]-'a'] {
			for _, k := range pos[key[i-1]-'a'] {
				f[i][j] = min(f[i][j], f[i-1][k]+min(abs(j-k), n-abs(j-k))+1)
			}
		}
	}
	ans := 1 << 30
	for _, j := range pos[key[m-1]-'a'] {
		ans = min(ans, f[m-1][j])
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function findRotateSteps(ring: string, key: string): number {
    const m: number = key.length;
    const n: number = ring.length;
    const pos: number[][] = Array.from({ length: 26 }, () => []);
    for (let i = 0; i < n; ++i) {
        const j: number = ring.charCodeAt(i) - 'a'.charCodeAt(0);
        pos[j].push(i);
    }

    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(1 << 30));
    for (const j of pos[key.charCodeAt(0) - 'a'.charCodeAt(0)]) {
        f[0][j] = Math.min(j, n - j) + 1;
    }

    for (let i = 1; i < m; ++i) {
        for (const j of pos[key.charCodeAt(i) - 'a'.charCodeAt(0)]) {
            for (const k of pos[key.charCodeAt(i - 1) - 'a'.charCodeAt(0)]) {
                f[i][j] = Math.min(
                    f[i][j],
                    f[i - 1][k] + Math.min(Math.abs(j - k), n - Math.abs(j - k)) + 1,
                );
            }
        }
    }

    let ans: number = 1 << 30;
    for (const j of pos[key.charCodeAt(m - 1) - 'a'.charCodeAt(0)]) {
        ans = Math.min(ans, f[m - 1][j]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [515. 在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row){#515}

{{< tabs "515" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root, curr):
            if root is None:
                return
            if curr == len(ans):
                ans.append(root.val)
            else:
                ans[curr] = max(ans[curr], root.val)
            dfs(root.left, curr + 1)
            dfs(root.right, curr + 1)

        ans = []
        dfs(root, 0)
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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> largestValues(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int curr) {
        if (root == null) {
            return;
        }
        if (curr == ans.size()) {
            ans.add(root.val);
        } else {
            ans.set(curr, Math.max(ans.get(curr), root.val));
        }
        dfs(root.left, curr + 1);
        dfs(root.right, curr + 1);
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
    vector<int> ans;

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int curr) {
        if (!root) return;
        if (curr == ans.size())
            ans.push_back(root->val);
        else
            ans[curr] = max(ans[curr], root->val);
        dfs(root->left, curr + 1);
        dfs(root->right, curr + 1);
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
func largestValues(root *TreeNode) []int {
	var ans []int
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, curr int) {
		if root == nil {
			return
		}
		if curr == len(ans) {
			ans = append(ans, root.Val)
		} else {
			ans[curr] = max(ans[curr], root.Val)
		}
		dfs(root.Left, curr+1)
		dfs(root.Right, curr+1)
	}
	dfs(root, 0)
	return ans
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

function largestValues(root: TreeNode | null): number[] {
    const res = [];
    const dfs = (root: TreeNode | null, depth: number) => {
        if (root == null) {
            return;
        }
        const { val, left, right } = root;
        if (res.length == depth) {
            res.push(val);
        } else {
            res[depth] = Math.max(res[depth], val);
        }
        dfs(left, depth + 1);
        dfs(right, depth + 1);
    };
    dfs(root, 0);
    return res;
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, depth: usize, res: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }
        let node = root.as_ref().unwrap().borrow();
        if res.len() == depth {
            res.push(node.val);
        } else {
            res[depth] = res[depth].max(node.val);
        }
        Self::dfs(&node.left, depth + 1, res);
        Self::dfs(&node.right, depth + 1, res);
    }

    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res = Vec::new();
        Self::dfs(&root, 0, &mut res);
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点&nbsp;<code>root</code> ，请找出该二叉树中每一层的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0515.Find%20Largest%20Value%20in%20Each%20Tree%20Row/images/largest_e1.jpg" style="height: 172px; width: 300px;" /></p>

<pre>
<strong>输入: </strong>root = [1,3,2,5,3,null,9]
<strong>输出: </strong>[1,3,9]
</pre>

<p><strong>示例2：</strong></p>

<pre>
<strong>输入: </strong>root = [1,2,3]
<strong>输出: </strong>[1,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树的节点个数的范围是 <code>[0,10<sup>4</sup>]</code></li>
	<li><meta charset="UTF-8" /><code>-2<sup>31</sup>&nbsp;&lt;= Node.val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个队列 $q$，将根节点放入队列中。每次从队列中取出当前层的所有节点，找出最大值，然后将下一层的所有节点放入队列中，直到队列为空。

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
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None:
            return ans
        q = deque([root])
        while q:
            x = -inf
            for _ in range(len(q)):
                node = q.popleft()
                x = max(x, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(x)
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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int t = q.peek().val;
            for (int i = q.size(); i > 0; --i) {
                TreeNode node = q.poll();
                t = Math.max(t, node.val);
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            ans.add(t);
        }
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            int x = INT_MIN;
            for (int i = q.size(); i; --i) {
                TreeNode* node = q.front();
                q.pop();
                x = max(x, node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(x);
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
func largestValues(root *TreeNode) (ans []int) {
	if root == nil {
		return
	}
	q := []*TreeNode{root}
	for len(q) > 0 {
		x := q[0].Val
		for i := len(q); i > 0; i-- {
			node := q[0]
			q = q[1:]
			x = max(x, node.Val)
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		ans = append(ans, x)
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

function largestValues(root: TreeNode | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const q: TreeNode[] = [root];
    while (q.length) {
        const nq: TreeNode[] = [];
        let x = -Infinity;
        for (const { val, left, right } of q) {
            x = Math.max(x, val);
            if (left) {
                nq.push(left);
            }
            if (right) {
                nq.push(right);
            }
        }
        ans.push(x);
        q.length = 0;
        q.push(...nq);
    }
    return ans;
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
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut q = VecDeque::new();
        if root.is_some() {
            q.push_back(root.clone());
        }
        while !q.is_empty() {
            let mut x = i32::MIN;
            for _ in 0..q.len() {
                let node = q.pop_front().unwrap();
                let node = node.as_ref().unwrap().borrow();
                x = x.max(node.val);
                if node.left.is_some() {
                    q.push_back(node.left.clone());
                }
                if node.right.is_some() {
                    q.push_back(node.right.clone());
                }
            }
            ans.push(x);
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

DFS 先序遍历，找每个深度最大的节点值。

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
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root, curr):
            if root is None:
                return
            if curr == len(ans):
                ans.append(root.val)
            else:
                ans[curr] = max(ans[curr], root.val)
            dfs(root.left, curr + 1)
            dfs(root.right, curr + 1)

        ans = []
        dfs(root, 0)
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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> largestValues(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int curr) {
        if (root == null) {
            return;
        }
        if (curr == ans.size()) {
            ans.add(root.val);
        } else {
            ans.set(curr, Math.max(ans.get(curr), root.val));
        }
        dfs(root.left, curr + 1);
        dfs(root.right, curr + 1);
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
    vector<int> ans;

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int curr) {
        if (!root) return;
        if (curr == ans.size())
            ans.push_back(root->val);
        else
            ans[curr] = max(ans[curr], root->val);
        dfs(root->left, curr + 1);
        dfs(root->right, curr + 1);
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
func largestValues(root *TreeNode) []int {
	var ans []int
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, curr int) {
		if root == nil {
			return
		}
		if curr == len(ans) {
			ans = append(ans, root.Val)
		} else {
			ans[curr] = max(ans[curr], root.Val)
		}
		dfs(root.Left, curr+1)
		dfs(root.Right, curr+1)
	}
	dfs(root, 0)
	return ans
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

function largestValues(root: TreeNode | null): number[] {
    const res = [];
    const dfs = (root: TreeNode | null, depth: number) => {
        if (root == null) {
            return;
        }
        const { val, left, right } = root;
        if (res.length == depth) {
            res.push(val);
        } else {
            res[depth] = Math.max(res[depth], val);
        }
        dfs(left, depth + 1);
        dfs(right, depth + 1);
    };
    dfs(root, 0);
    return res;
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, depth: usize, res: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }
        let node = root.as_ref().unwrap().borrow();
        if res.len() == depth {
            res.push(node.val);
        } else {
            res[depth] = res[depth].max(node.val);
        }
        Self::dfs(&node.left, depth + 1, res);
        Self::dfs(&node.right, depth + 1, res);
    }

    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res = Vec::new();
        Self::dfs(&root, 0, &mut res);
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence){#516}

{{< tabs "516" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPalindromeSubseq(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1] + 2
			} else {
				f[i][j] = max(f[i+1][j], f[i][j-1])
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPalindromeSubseq(s: string): number {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
            } else {
                f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
            }
        }
    }
    return f[0][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，找出其中最长的回文子序列，并返回该序列的长度。</p>

<p>子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "bbbab"
<strong>输出：</strong>4
<strong>解释：</strong>一个可能的最长回文子序列为 "bbbb" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "cbbd"
<strong>输出：</strong>2
<strong>解释：</strong>一个可能的最长回文子序列为 "bb" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 1000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示字符串 $s$ 的第 $i$ 个字符到第 $j$ 个字符之间的最长回文子序列的长度。初始时 $f[i][i] = 1$，其余位置的值均为 $0$。

如果 $s[i] = s[j]$，那么 $f[i][j] = f[i + 1][j - 1] + 2$；否则 $f[i][j] = \max(f[i + 1][j], f[i][j - 1])$。

由于 $f[i][j]$ 的值与 $f[i + 1][j - 1]$, $f[i + 1][j]$, $f[i][j - 1]$ 有关，所以我们应该从大到小枚举 $i$，从小到大枚举 $j$。

答案即为 $f[0][n - 1]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func longestPalindromeSubseq(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1] + 2
			} else {
				f[i][j] = max(f[i+1][j], f[i][j-1])
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function longestPalindromeSubseq(s: string): number {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
            } else {
                f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
            }
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [517. 超级洗衣机](https://leetcode.cn/problems/super-washing-machines){#517}

{{< tabs "517" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        k, mod = divmod(sum(machines), n)
        if mod:
            return -1
        ans = s = 0
        for x in machines:
            x -= k
            s += x
            ans = max(ans, abs(s), x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinMoves(int[] machines) {
        int n = machines.length;
        int s = 0;
        for (int x : machines) {
            s += x;
        }
        if (s % n != 0) {
            return -1;
        }
        int k = s / n;
        s = 0;
        int ans = 0;
        for (int x : machines) {
            x -= k;
            s += x;
            ans = Math.max(ans, Math.max(Math.abs(s), x));
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
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int s = accumulate(machines.begin(), machines.end(), 0);
        if (s % n) {
            return -1;
        }
        int k = s / n;
        s = 0;
        int ans = 0;
        for (int x : machines) {
            x -= k;
            s += x;
            ans = max({ans, abs(s), x});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMinMoves(machines []int) (ans int) {
	n := len(machines)
	s := 0
	for _, x := range machines {
		s += x
	}
	if s%n != 0 {
		return -1
	}
	k := s / n
	s = 0
	for _, x := range machines {
		x -= k
		s += x
		ans = max(ans, max(abs(s), x))
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinMoves(machines: number[]): number {
    const n = machines.length;
    let s = machines.reduce((a, b) => a + b);
    if (s % n !== 0) {
        return -1;
    }
    const k = Math.floor(s / n);
    s = 0;
    let ans = 0;
    for (let x of machines) {
        x -= k;
        s += x;
        ans = Math.max(ans, Math.abs(s), x);
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

<p>假设有 <code>n</code><strong>&nbsp;</strong>台超级洗衣机放在同一排上。开始的时候，每台洗衣机内可能有一定量的衣服，也可能是空的。</p>

<p>在每一步操作中，你可以选择任意 <code>m</code> (<code>1 &lt;= m &lt;= n</code>) 台洗衣机，与此同时将每台洗衣机的一件衣服送到相邻的一台洗衣机。</p>

<p>给定一个整数数组&nbsp;<code>machines</code> 代表从左至右每台洗衣机中的衣物数量，请给出能让所有洗衣机中剩下的衣物的数量相等的 <strong>最少的操作步数 </strong>。如果不能使每台洗衣机中衣物的数量相等，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>machines = [1,0,5]
<strong>输出：</strong>3
<strong>解释：</strong>
第一步:    1     0 &lt;-- 5    =&gt;    1     1     4
第二步:    1 &lt;-- 1 &lt;-- 4    =&gt;    2     1     3    
第三步:    2     1 &lt;-- 3    =&gt;    2     2     2   
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>machines = [0,3,0]
<strong>输出：</strong>2
<strong>解释：</strong>
第一步:    0 &lt;-- 3     0    =&gt;    1     2     0    
第二步:    1     2 --&gt; 0    =&gt;    1     1     1     
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>machines = [0,2,0]
<strong>输出：</strong>-1
<strong>解释：</strong>
不可能让所有三个洗衣机同时剩下相同数量的衣物。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == machines.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= machines[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

如果洗衣机内的衣服总数不能被洗衣机的数量整除，那么不可能使得每台洗衣机内的衣服数量相等，直接返回 $-1$。

否则，假设洗衣机内的衣服总数为 $s$，那么最终每台洗衣机内的衣服数量都会变为 $k = s / n$。

我们定义 $a_i$ 为第 $i$ 台洗衣机内的衣服数量与 $k$ 的差值，即 $a_i = \textit{machines}[i] - k$。若 $a_i > 0$，则表示第 $i$ 台洗衣机内有多余的衣服，需要向相邻的洗衣机传递；若 $a_i < 0$，则表示第 $i$ 台洗衣机内缺少衣服，需要从相邻的洗衣机获得。

我们将前 $i$ 台洗衣机的衣服数量差值之和定义为 $s_i = \sum_{j=0}^{i-1} a_j$，如果把前 $i$ 台洗衣机视为一组，其余的洗衣机视为另一组。那么若 $s_i$ 为正数，表示第一组洗衣机内有多余的衣服，需要向第二组洗衣机传递；若 $s_i$ 为负数，表示第一组洗衣机内缺少衣服，需要从第二组洗衣机获得。

那么有以下两种情况：

1. 两组之间的衣服，最多需要移动的次数为 $\max_{i=0}^{n-1} \lvert s_i \rvert$；
1. 组内某一台洗衣机的衣服数量过多，需要向左右两侧移出衣服，最多需要移动的次数为 $\max_{i=0}^{n-1} a_i$。

我们取两者的最大值即可。

时间复杂度 $O(n)$，其中 $n$ 为洗衣机的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        k, mod = divmod(sum(machines), n)
        if mod:
            return -1
        ans = s = 0
        for x in machines:
            x -= k
            s += x
            ans = max(ans, abs(s), x)
        return ans
```

#### Java

```java
class Solution {
    public int findMinMoves(int[] machines) {
        int n = machines.length;
        int s = 0;
        for (int x : machines) {
            s += x;
        }
        if (s % n != 0) {
            return -1;
        }
        int k = s / n;
        s = 0;
        int ans = 0;
        for (int x : machines) {
            x -= k;
            s += x;
            ans = Math.max(ans, Math.max(Math.abs(s), x));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int s = accumulate(machines.begin(), machines.end(), 0);
        if (s % n) {
            return -1;
        }
        int k = s / n;
        s = 0;
        int ans = 0;
        for (int x : machines) {
            x -= k;
            s += x;
            ans = max({ans, abs(s), x});
        }
        return ans;
    }
};
```

#### Go

```go
func findMinMoves(machines []int) (ans int) {
	n := len(machines)
	s := 0
	for _, x := range machines {
		s += x
	}
	if s%n != 0 {
		return -1
	}
	k := s / n
	s = 0
	for _, x := range machines {
		x -= k
		s += x
		ans = max(ans, max(abs(s), x))
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function findMinMoves(machines: number[]): number {
    const n = machines.length;
    let s = machines.reduce((a, b) => a + b);
    if (s % n !== 0) {
        return -1;
    }
    const k = Math.floor(s / n);
    s = 0;
    let ans = 0;
    for (let x of machines) {
        x -= k;
        s += x;
        ans = Math.max(ans, Math.abs(s), x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii){#518}

{{< tabs "518" >}}

{{% tab "python" %}}
```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = amount
        f = [1] + [0] * n
        for x in coins:
            for j in range(x, n + 1):
                f[j] += f[j - x]
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int change(int amount, int[] coins) {
        int n = amount;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = amount;
        unsigned f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func change(amount int, coins []int) int {
	n := amount
	f := make([]int, n+1)
	f[0] = 1
	for _, x := range coins {
		for j := x; j <= n; j++ {
			f[j] += f[j-x]
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function change(amount: number, coins: number[]): number {
    const n = amount;
    const f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] += f[j - x];
        }
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>coins</code> 表示不同面额的硬币，另给一个整数 <code>amount</code> 表示总金额。</p>

<p>请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 <code>0</code> 。</p>

<p>假设每一种面额的硬币有无限个。 </p>

<p>题目数据保证结果符合 32 位带符号整数。</p>

<p> </p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>amount = 5, coins = [1, 2, 5]
<strong>输出：</strong>4
<strong>解释：</strong>有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>amount = 3, coins = [2]
<strong>输出：</strong>0
<strong>解释：</strong>只用面额 2 的硬币不能凑成总金额 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>amount = 10, coins = [10] 
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= coins.length <= 300</code></li>
	<li><code>1 <= coins[i] <= 5000</code></li>
	<li><code>coins</code> 中的所有值 <strong>互不相同</strong></li>
	<li><code>0 <= amount <= 5000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划(完全背包)

我们定义 $f[i][j]$ 表示使用前 $i$ 种硬币，凑出金额 $j$ 的硬币组合数。初始时 $f[0][0] = 1$，其余位置的值均为 $0$。

我们可以枚举使用的最后一枚硬币的数量 $k$，那么有式子一：

$$
f[i][j] = f[i - 1][j] + f[i - 1][j - x] + f[i - 1][j - 2 \times x] + \cdots + f[i - 1][j - k \times x]
$$

其中 $x$ 表示第 $i$ 种硬币的面值。

不妨令 $j = j - x$，那么有式子二：

$$
f[i][j - x] = f[i - 1][j - x] + f[i - 1][j - 2 \times x] + \cdots + f[i - 1][j - k \times x]
$$

将式子二代入式子一，得到：

$$
f[i][j] = f[i - 1][j] + f[i][j - x]
$$

最终的答案为 $f[m][n]$，其中 $m$ 和 $n$ 分别表示硬币的种类数和总金额。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为硬币的种类数和总金额。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        m, n = len(coins), amount
        f = [[0] * (n + 1) for _ in range(m + 1)]
        f[0][0] = 1
        for i, x in enumerate(coins, 1):
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if j >= x:
                    f[i][j] += f[i][j - x]
        return f[m][n]
```

#### Java

```java
class Solution {
    public int change(int amount, int[] coins) {
        int m = coins.length, n = amount;
        int[][] f = new int[m + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= coins[i - 1]) {
                    f[i][j] += f[i][j - coins[i - 1]];
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size(), n = amount;
        unsigned f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= coins[i - 1]) {
                    f[i][j] += f[i][j - coins[i - 1]];
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func change(amount int, coins []int) int {
	m, n := len(coins), amount
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if j >= coins[i-1] {
				f[i][j] += f[i][j-coins[i-1]]
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function change(amount: number, coins: number[]): number {
    const [m, n] = [coins.length, amount];
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= coins[i - 1]) {
                f[i][j] += f[i][j - coins[i - 1]];
            }
        }
    }
    return f[m][n];
}
```

<!-- tabs:end -->

我们注意到 $f[i][j]$ 只与 $f[i - 1][j]$ 和 $f[i][j - x]$ 有关，因此我们可以将二维数组优化为一维数组，空间复杂度降为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = amount
        f = [1] + [0] * n
        for x in coins:
            for j in range(x, n + 1):
                f[j] += f[j - x]
        return f[n]
```

#### Java

```java
class Solution {
    public int change(int amount, int[] coins) {
        int n = amount;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = amount;
        unsigned f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func change(amount int, coins []int) int {
	n := amount
	f := make([]int, n+1)
	f[0] = 1
	for _, x := range coins {
		for j := x; j <= n; j++ {
			f[j] += f[j-x]
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function change(amount: number, coins: number[]): number {
    const n = amount;
    const f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] += f[j - x];
        }
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [519. 随机翻转矩阵](https://leetcode.cn/problems/random-flip-matrix){#519}

{{< tabs "519" >}}

{{% tab "python" %}}
```python
class Solution:
    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.total = m * n
        self.mp = {}

    def flip(self) -> List[int]:
        self.total -= 1
        x = random.randint(0, self.total)
        idx = self.mp.get(x, x)
        self.mp[x] = self.mp.get(self.total, self.total)
        return [idx // self.n, idx % self.n]

    def reset(self) -> None:
        self.total = self.m * self.n
        self.mp.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int total;
    private Random rand = new Random();
    private Map<Integer, Integer> mp = new HashMap<>();

    public Solution(int m, int n) {
        this.m = m;
        this.n = n;
        this.total = m * n;
    }

    public int[] flip() {
        int x = rand.nextInt(total--);
        int idx = mp.getOrDefault(x, x);
        mp.put(x, mp.getOrDefault(total, total));
        return new int[] {idx / n, idx % n};
    }

    public void reset() {
        total = m * n;
        mp.clear();
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(m, n);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x n</code> 的二元矩阵 <code>matrix</code> ，且所有值被初始化为 <code>0</code> 。请你设计一个算法，随机选取一个满足&nbsp;<code>matrix[i][j] == 0</code> 的下标&nbsp;<code>(i, j)</code> ，并将它的值变为 <code>1</code> 。所有满足 <code>matrix[i][j] == 0</code> 的下标 <code>(i, j)</code> 被选取的概率应当均等。</p>

<p>尽量最少调用内置的随机函数，并且优化时间和空间复杂度。</p>

<p>实现 <code>Solution</code> 类：</p>

<ul>
	<li><code>Solution(int m, int n)</code> 使用二元矩阵的大小 <code>m</code> 和 <code>n</code> 初始化该对象</li>
	<li><code>int[] flip()</code> 返回一个满足&nbsp;<code>matrix[i][j] == 0</code> 的随机下标 <code>[i, j]</code> ，并将其对应格子中的值变为 <code>1</code></li>
	<li><code>void reset()</code> 将矩阵中所有的值重置为 <code>0</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Solution", "flip", "flip", "flip", "reset", "flip"]
[[3, 1], [], [], [], [], []]
<strong>输出</strong>
[null, [1, 0], [2, 0], [0, 0], null, [2, 0]]

<strong>解释</strong>
Solution solution = new Solution(3, 1);
solution.flip();  // 返回 [1, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
solution.flip();  // 返回 [2, 0]，因为 [1,0] 已经返回过了，此时返回 [2,0] 和 [0,0] 的概率应当相同
solution.flip();  // 返回 [0, 0]，根据前面已经返回过的下标，此时只能返回 [0,0]
solution.reset(); // 所有值都重置为 0 ，并可以再次选择下标返回
solution.flip();  // 返回 [2, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li>每次调用<code>flip</code> 时，矩阵中至少存在一个值为 0 的格子。</li>
	<li>最多调用 <code>1000</code> 次 <code>flip</code> 和 <code>reset</code> 方法。</li>
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
class Solution:
    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.total = m * n
        self.mp = {}

    def flip(self) -> List[int]:
        self.total -= 1
        x = random.randint(0, self.total)
        idx = self.mp.get(x, x)
        self.mp[x] = self.mp.get(self.total, self.total)
        return [idx // self.n, idx % self.n]

    def reset(self) -> None:
        self.total = self.m * self.n
        self.mp.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int total;
    private Random rand = new Random();
    private Map<Integer, Integer> mp = new HashMap<>();

    public Solution(int m, int n) {
        this.m = m;
        this.n = n;
        this.total = m * n;
    }

    public int[] flip() {
        int x = rand.nextInt(total--);
        int idx = mp.getOrDefault(x, x);
        mp.put(x, mp.getOrDefault(total, total));
        return new int[] {idx / n, idx % n};
    }

    public void reset() {
        total = m * n;
        mp.clear();
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(m, n);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
