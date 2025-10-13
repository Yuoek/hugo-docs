---
title: "0570_至少有5名直接下属的经理"
date: 2025-10-08T18:36:17+08:00
weight: 8
tags: [二叉树, 动态规划, 哈希函数, 哈希表, 字符串匹配, 数学, 数据库, 数组, 树, 深度优先搜索]
---

{{< markmap >}}
### [0570_至少有5名直接下属的经理](#570)
#### [数据库](#570)
### [0571_给定数字的频率查询中位数 🔒](#571)
#### [数据库](#571)
### [0572_另一棵树的子树](#572)
#### [树](#572)
#### [深度优先搜索](#572)
#### [二叉树](#572)
#### [字符串匹配](#572)
#### [哈希函数](#572)
### [0573_松鼠模拟 🔒](#573)
#### [数组](#573)
#### [数学](#573)
### [0574_当选者 🔒](#574)
#### [数据库](#574)
### [0575_分糖果](#575)
#### [数组](#575)
#### [哈希表](#575)
### [0576_出界的路径数](#576)
#### [动态规划](#576)
### [0577_员工奖金](#577)
#### [数据库](#577)
### [0578_查询回答率最高的问题 🔒](#578)
#### [数据库](#578)
### [0579_查询员工的累计薪水 🔒](#579)
#### [数据库](#579)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0570_至少有5名直接下属的经理
___
#### 数据库
---
### 0571_给定数字的频率查询中位数 🔒
___
#### 数据库
---
### 0572_另一棵树的子树
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
___
#### 字符串匹配
___
#### 哈希函数
---
### 0573_松鼠模拟 🔒
___
#### 数组
___
#### 数学
---
### 0574_当选者 🔒
___
#### 数据库
---
### 0575_分糖果
___
#### 数组
___
#### 哈希表
---
### 0576_出界的路径数
___
#### 动态规划
---
### 0577_员工奖金
___
#### 数据库
---
### 0578_查询回答率最高的问题 🔒
___
#### 数据库
---
### 0579_查询员工的累计薪水 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 哈希函数 |
| 哈希表 | 字符串匹配 | 数学 |
| 数据库 | 数组 | 树 |
| 深度优先搜索 |  |  |

# [570. 至少有5名直接下属的经理](https://leetcode.cn/problems/managers-with-at-least-5-direct-reports){#570}

{{< tabs "570" >}}

{{% tab "python" %}}
```python
import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    # Group the employees by managerId and count the number of direct reports
    manager_report_count = (
        employee.groupby("managerId").size().reset_index(name="directReports")
    )

    # Filter managers with at least five direct reports
    result = manager_report_count[manager_report_count["directReports"] >= 5]

    # Merge with the Employee table to get the names of these managers
    result = result.merge(
        employee[["id", "name"]], left_on="managerId", right_on="id", how="inner"
    )

    # Select only the 'name' column and drop the 'id' and 'directReports' columns
    result = result[["name"]]

    return result
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name
FROM
    Employee
    JOIN (
        SELECT managerId AS id, COUNT(1) AS cnt
        FROM Employee
        GROUP BY 1
        HAVING cnt >= 5
    ) AS t
        USING (id);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Employee</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id 是此表的主键（具有唯一值的列）。
该表的每一行表示雇员的名字、他们的部门和他们的经理的id。
如果managerId为空，则该员工没有经理。
没有员工会成为自己的管理者。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，找出至少有<strong>五个直接下属</strong>的经理。</p>

<p>以 <strong>任意顺序 </strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | Null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
<strong>输出:</strong> 
+------+
| name |
+------+
| John |
+------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计 + 连接

我们可以先统计每个经理的直接下属人数，然后再连接 `Employee` 表，找出直接下属人数大于等于 $5$ 的经理。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    # Group the employees by managerId and count the number of direct reports
    manager_report_count = (
        employee.groupby("managerId").size().reset_index(name="directReports")
    )

    # Filter managers with at least five direct reports
    result = manager_report_count[manager_report_count["directReports"] >= 5]

    # Merge with the Employee table to get the names of these managers
    result = result.merge(
        employee[["id", "name"]], left_on="managerId", right_on="id", how="inner"
    )

    # Select only the 'name' column and drop the 'id' and 'directReports' columns
    result = result[["name"]]

    return result
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name
FROM
    Employee
    JOIN (
        SELECT managerId AS id, COUNT(1) AS cnt
        FROM Employee
        GROUP BY 1
        HAVING cnt >= 5
    ) AS t
        USING (id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [571. 给定数字的频率查询中位数 🔒](https://leetcode.cn/problems/find-median-given-frequency-of-numbers){#571}

{{< tabs "571" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            *,
            SUM(frequency) OVER (ORDER BY num ASC) AS rk1,
            SUM(frequency) OVER (ORDER BY num DESC) AS rk2,
            SUM(frequency) OVER () AS s
        FROM Numbers
    )
SELECT
    ROUND(AVG(num), 1) AS median
FROM t
WHERE rk1 >= s / 2 AND rk2 >= s / 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Numbers</code> 表：</p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
| frequency   | int  |
+-------------+------+
num 是这张表的主键(具有唯一值的列)。
这张表的每一行表示某个数字在该数据库中的出现频率。</pre>

<p>&nbsp;</p>
<a href="https://baike.baidu.com/item/%E4%B8%AD%E4%BD%8D%E6%95%B0/3087401" target="_blank"><strong>中位数</strong></a> 是将数据样本中半数较高值和半数较低值分隔开的值。

<p>编写解决方案，解压 <code>Numbers</code> 表，报告数据库中所有数字的 <strong>中位数</strong> 。结果四舍五入至 <strong>一位小数</strong> 。</p>

<p>返回结果如下例所示。</p>

<p>&nbsp;</p>

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Numbers 表：
+-----+-----------+
| num | frequency |
+-----+-----------+
| 0   | 7         |
| 1   | 1         |
| 2   | 3         |
| 3   | 1         |
+-----+-----------+
<strong>输出：</strong>
+--------+
| median |
+--------+
| 0.0    |
+--------+
<strong>解释：</strong>
如果解压这个 Numbers 表，可以得到 [0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3] ，所以中位数是 (0 + 0) / 2 = 0 。
</pre>
</div>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：开窗函数

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            *,
            SUM(frequency) OVER (ORDER BY num ASC) AS rk1,
            SUM(frequency) OVER (ORDER BY num DESC) AS rk2,
            SUM(frequency) OVER () AS s
        FROM Numbers
    )
SELECT
    ROUND(AVG(num), 1) AS median
FROM t
WHERE rk1 >= s / 2 AND rk2 >= s / 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [572. 另一棵树的子树](https://leetcode.cn/problems/subtree-of-another-tree){#572}

{{< tabs "572" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def same(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
            if p is None or q is None:
                return p is q
            return p.val == q.val and same(p.left, q.left) and same(p.right, q.right)

        if root is None:
            return False
        return (
            same(root, subRoot)
            or self.isSubtree(root.left, subRoot)
            or self.isSubtree(root.right, subRoot)
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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        return same(root, subRoot) || isSubtree(root.left, subRoot)
            || isSubtree(root.right, subRoot);
    }

    private boolean same(TreeNode p, TreeNode q) {
        if (p == null || q == null) {
            return p == q;
        }
        return p.val == q.val && same(p.left, q.left) && same(p.right, q.right);
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        return same(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool same(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return p->val == q->val && same(p->left, q->left) && same(p->right, q->right);
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
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	var same func(p, q *TreeNode) bool
	same = func(p, q *TreeNode) bool {
		if p == nil || q == nil {
			return p == q
		}
		return p.Val == q.Val && same(p.Left, q.Left) && same(p.Right, q.Right)
	}
	if root == nil {
		return false
	}
	return same(root, subRoot) || isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
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
function isSubtree(root: TreeNode | null, subRoot: TreeNode | null): boolean {
    const same = (p: TreeNode | null, q: TreeNode | null): boolean => {
        if (!p || !q) {
            return p === q;
        }
        return p.val === q.val && same(p.left, q.left) && same(p.right, q.right);
    };
    if (!root) {
        return false;
    }
    return same(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
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
    pub fn is_subtree(
        root: Option<Rc<RefCell<TreeNode>>>,
        sub_root: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if root.is_none() {
            return false;
        }
        Self::same(&root, &sub_root)
            || Self::is_subtree(
                root.as_ref().unwrap().borrow().left.clone(),
                sub_root.clone(),
            )
            || Self::is_subtree(
                root.as_ref().unwrap().borrow().right.clone(),
                sub_root.clone(),
            )
    }

    fn same(p: &Option<Rc<RefCell<TreeNode>>>, q: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p, q) {
            (None, None) => true,
            (Some(p), Some(q)) => {
                let p = p.borrow();
                let q = q.borrow();
                p.val == q.val && Self::same(&p.left, &q.left) && Self::same(&p.right, &q.right)
            }
            _ => false,
        }
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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function (root, subRoot) {
    const same = (p, q) => {
        if (!p || !q) {
            return p === q;
        }
        return p.val === q.val && same(p.left, q.left) && same(p.right, q.right);
    };
    if (!root) {
        return false;
    }
    return same(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<div class="original__bRMd">
<div>
<p>给你两棵二叉树 <code>root</code> 和 <code>subRoot</code> 。检验 <code>root</code> 中是否包含和 <code>subRoot</code> 具有相同结构和节点值的子树。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>二叉树 <code>tree</code> 的一棵子树包括 <code>tree</code> 的某个节点和这个节点的所有后代节点。<code>tree</code> 也可以看做它自身的一棵子树。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0572.Subtree%20of%20Another%20Tree/images/1724998676-cATjhe-image.png" style="width: 532px; height: 400px;" />
<pre>
<strong>输入：</strong>root = [3,4,5,1,2], subRoot = [4,1,2]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0572.Subtree%20of%20Another%20Tree/images/1724998698-sEJWnq-image.png" style="width: 502px; height: 458px;" />
<pre>
<strong>输入：</strong>root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>root</code> 树上的节点数量范围是 <code>[1, 2000]</code></li>
	<li><code>subRoot</code> 树上的节点数量范围是 <code>[1, 1000]</code></li>
	<li><code>-10<sup>4</sup> &lt;= root.val &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= subRoot.val &lt;= 10<sup>4</sup></code></li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们定义一个辅助函数 $\textit{same}(p, q)$，用于判断以 $p$ 为根节点的树和以 $q$ 为根节点的树是否相等。如果两棵树的根节点的值相等，并且它们的左子树和右子树也分别相等，那么这两棵树是相等的。

在 $\textit{isSubtree}(\textit{root}, \textit{subRoot})$ 函数中，我们首先判断 $\textit{root}$ 是否为空，如果为空，则返回 $\text{false}$。否则，我们判断 $\textit{root}$ 和 $\textit{subRoot}$ 是否相等，如果相等，则返回 $\text{true}$。否则，我们递归地判断 $\textit{root}$ 的左子树和右子树是否包含 $\textit{subRoot}$。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是树 $root$ 和树 $subRoot$ 的节点个数。

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
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def same(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
            if p is None or q is None:
                return p is q
            return p.val == q.val and same(p.left, q.left) and same(p.right, q.right)

        if root is None:
            return False
        return (
            same(root, subRoot)
            or self.isSubtree(root.left, subRoot)
            or self.isSubtree(root.right, subRoot)
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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        return same(root, subRoot) || isSubtree(root.left, subRoot)
            || isSubtree(root.right, subRoot);
    }

    private boolean same(TreeNode p, TreeNode q) {
        if (p == null || q == null) {
            return p == q;
        }
        return p.val == q.val && same(p.left, q.left) && same(p.right, q.right);
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        return same(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool same(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return p->val == q->val && same(p->left, q->left) && same(p->right, q->right);
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
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	var same func(p, q *TreeNode) bool
	same = func(p, q *TreeNode) bool {
		if p == nil || q == nil {
			return p == q
		}
		return p.Val == q.Val && same(p.Left, q.Left) && same(p.Right, q.Right)
	}
	if root == nil {
		return false
	}
	return same(root, subRoot) || isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
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
function isSubtree(root: TreeNode | null, subRoot: TreeNode | null): boolean {
    const same = (p: TreeNode | null, q: TreeNode | null): boolean => {
        if (!p || !q) {
            return p === q;
        }
        return p.val === q.val && same(p.left, q.left) && same(p.right, q.right);
    };
    if (!root) {
        return false;
    }
    return same(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
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
    pub fn is_subtree(
        root: Option<Rc<RefCell<TreeNode>>>,
        sub_root: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if root.is_none() {
            return false;
        }
        Self::same(&root, &sub_root)
            || Self::is_subtree(
                root.as_ref().unwrap().borrow().left.clone(),
                sub_root.clone(),
            )
            || Self::is_subtree(
                root.as_ref().unwrap().borrow().right.clone(),
                sub_root.clone(),
            )
    }

    fn same(p: &Option<Rc<RefCell<TreeNode>>>, q: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p, q) {
            (None, None) => true,
            (Some(p), Some(q)) => {
                let p = p.borrow();
                let q = q.borrow();
                p.val == q.val && Self::same(&p.left, &q.left) && Self::same(&p.right, &q.right)
            }
            _ => false,
        }
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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function (root, subRoot) {
    const same = (p, q) => {
        if (!p || !q) {
            return p === q;
        }
        return p.val === q.val && same(p.left, q.left) && same(p.right, q.right);
    };
    if (!root) {
        return false;
    }
    return same(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [573. 松鼠模拟 🔒](https://leetcode.cn/problems/squirrel-simulation){#573}

{{< tabs "573" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDistance(
        self,
        height: int,
        width: int,
        tree: List[int],
        squirrel: List[int],
        nuts: List[List[int]],
    ) -> int:
        tr, tc = tree
        sr, sc = squirrel
        s = sum(abs(r - tr) + abs(c - tc) for r, c in nuts) * 2
        ans = inf
        for r, c in nuts:
            a = abs(r - tr) + abs(c - tc)
            b = abs(r - sr) + abs(c - sc)
            ans = min(ans, s - a + b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
import static java.lang.Math.*;

class Solution {
    public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int tr = tree[0], tc = tree[1];
        int sr = squirrel[0], sc = squirrel[1];
        int s = 0;
        for (var e : nuts) {
            s += abs(e[0] - tr) + abs(e[1] - tc);
        }
        s <<= 1;
        int ans = Integer.MAX_VALUE;
        for (var e : nuts) {
            int a = abs(e[0] - tr) + abs(e[1] - tc);
            int b = abs(e[0] - sr) + abs(e[1] - sc);
            ans = min(ans, s - a + b);
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
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int tr = tree[0], tc = tree[1];
        int sr = squirrel[0], sc = squirrel[1];
        int s = 0;
        for (const auto& e : nuts) {
            s += abs(e[0] - tr) + abs(e[1] - tc);
        }
        s <<= 1;
        int ans = INT_MAX;
        for (const auto& e : nuts) {
            int a = abs(e[0] - tr) + abs(e[1] - tc);
            int b = abs(e[0] - sr) + abs(e[1] - sc);
            ans = min(ans, s - a + b);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDistance(height int, width int, tree []int, squirrel []int, nuts [][]int) int {
	tr, tc := tree[0], tree[1]
	sr, sc := squirrel[0], squirrel[1]
	s := 0
	for _, e := range nuts {
		s += abs(e[0]-tr) + abs(e[1]-tc)
	}
	s <<= 1
	ans := math.MaxInt32
	for _, e := range nuts {
		a := abs(e[0]-tr) + abs(e[1]-tc)
		b := abs(e[0]-sr) + abs(e[1]-sc)
		ans = min(ans, s-a+b)
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
function minDistance(
    height: number,
    width: number,
    tree: number[],
    squirrel: number[],
    nuts: number[][],
): number {
    const [tr, tc] = tree;
    const [sr, sc] = squirrel;
    const s = nuts.reduce((acc, [r, c]) => acc + (Math.abs(tr - r) + Math.abs(tc - c)) * 2, 0);
    let ans = Infinity;
    for (const [r, c] of nuts) {
        const a = Math.abs(tr - r) + Math.abs(tc - c);
        const b = Math.abs(sr - r) + Math.abs(sc - c);
        ans = Math.min(ans, s - a + b);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_distance(
        height: i32,
        width: i32,
        tree: Vec<i32>,
        squirrel: Vec<i32>,
        nuts: Vec<Vec<i32>>,
    ) -> i32 {
        let (tr, tc) = (tree[0], tree[1]);
        let (sr, sc) = (squirrel[0], squirrel[1]);
        let s: i32 = nuts
            .iter()
            .map(|nut| (nut[0] - tr).abs() + (nut[1] - tc).abs())
            .sum::<i32>()
            * 2;

        let mut ans = i32::MAX;
        for nut in &nuts {
            let a = (nut[0] - tr).abs() + (nut[1] - tc).abs();
            let b = (nut[0] - sr).abs() + (nut[1] - sc).abs();
            ans = ans.min(s - a + b);
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int tr = tree[0], tc = tree[1];
        int sr = squirrel[0], sc = squirrel[1];
        int s = 0;

        foreach (var e in nuts) {
            s += Math.Abs(e[0] - tr) + Math.Abs(e[1] - tc);
        }
        s <<= 1;

        int ans = int.MaxValue;
        foreach (var e in nuts) {
            int a = Math.Abs(e[0] - tr) + Math.Abs(e[1] - tc);
            int b = Math.Abs(e[0] - sr) + Math.Abs(e[1] - sc);
            ans = Math.Min(ans, s - a + b);
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

<p>给你两个整数 <code>height</code> 和 <code>width</code> ，代表一个大小为 <code>height x width</code> 的花园。你还得到了以下信息：</p>

<ul>
	<li>一个数组 <code>tree</code> ，其中 <code>tree = [tree<sub>r</sub>, tree<sub>c</sub>]</code> 是花园中树的位置，</li>
	<li>一个数组 <code>squirrel</code> ，其中 <code>squirrel = [squirrel<sub>r</sub>, squirrel<sub>c</sub>]</code> 是花园中松鼠的位置，</li>
	<li>一个数组 <code>nuts</code> ，其中 <code>nuts[i] = [nut<sub>i<sub>r</sub></sub>, nut<sub>i<sub>c</sub></sub>]</code> 是花园中第 <code>i<sup>th</sup></code> 个坚果的位置。</li>
</ul>

<p>松鼠一次最多只能携带一个坚果，并且能够向上、下、左、右四个方向移动到相邻的单元格。</p>

<p>返回松鼠收集所有坚果并逐一放在树下的 <strong>最小距离</strong> 。</p>

<p><strong>距离</strong> 是指移动的次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0573.Squirrel%20Simulation/images/squirrel1-grid.jpg" style="width: 573px; height: 413px;" />
<pre>
<strong>输入：</strong>height = 5, width = 7, tree = [2,2], squirrel = [4,4], nuts = [[3,0], [2,5]]
<strong>输出：</strong>12
<strong>解释：</strong>为实现最小的距离，松鼠应该先摘 [2, 5] 位置的坚果。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0573.Squirrel%20Simulation/images/squirrel2-grid.jpg" style="width: 253px; height: 93px;" />
<pre>
<strong>输入：</strong>height = 1, width = 3, tree = [0,1], squirrel = [0,0], nuts = [[0,2]]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= height, width &lt;= 100</code></li>
	<li><code>tree.length == 2</code></li>
	<li><code>squirrel.length == 2</code></li>
	<li><code>1 &lt;= nuts.length &lt;= 5000</code></li>
	<li><code>nuts[i].length == 2</code></li>
	<li><code>0 &lt;= tree<sub>r</sub>, squirrel<sub>r</sub>, nut<sub>i<sub>r</sub></sub> &lt;= height</code></li>
	<li><code>0 &lt;= tree<sub>c</sub>, squirrel<sub>c</sub>, nut<sub>i<sub>c</sub></sub> &lt;= width</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们观察松鼠的移动路径，可以发现，松鼠会首先移动到某个坚果的位置，然后移动到树的位置。接下来，松鼠的移动路径之和等于“其余坚果到树的位置之和”再乘以 $2$。

因此，我们只需要选出一个坚果，作为松鼠的第一个目标，使得其到树的位置之和最小，即可得到最小路径。

时间复杂度 $O(n)$，其中 $n$ 为坚果的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDistance(
        self,
        height: int,
        width: int,
        tree: List[int],
        squirrel: List[int],
        nuts: List[List[int]],
    ) -> int:
        tr, tc = tree
        sr, sc = squirrel
        s = sum(abs(r - tr) + abs(c - tc) for r, c in nuts) * 2
        ans = inf
        for r, c in nuts:
            a = abs(r - tr) + abs(c - tc)
            b = abs(r - sr) + abs(c - sc)
            ans = min(ans, s - a + b)
        return ans
```

#### Java

```java
import static java.lang.Math.*;

class Solution {
    public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int tr = tree[0], tc = tree[1];
        int sr = squirrel[0], sc = squirrel[1];
        int s = 0;
        for (var e : nuts) {
            s += abs(e[0] - tr) + abs(e[1] - tc);
        }
        s <<= 1;
        int ans = Integer.MAX_VALUE;
        for (var e : nuts) {
            int a = abs(e[0] - tr) + abs(e[1] - tc);
            int b = abs(e[0] - sr) + abs(e[1] - sc);
            ans = min(ans, s - a + b);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int tr = tree[0], tc = tree[1];
        int sr = squirrel[0], sc = squirrel[1];
        int s = 0;
        for (const auto& e : nuts) {
            s += abs(e[0] - tr) + abs(e[1] - tc);
        }
        s <<= 1;
        int ans = INT_MAX;
        for (const auto& e : nuts) {
            int a = abs(e[0] - tr) + abs(e[1] - tc);
            int b = abs(e[0] - sr) + abs(e[1] - sc);
            ans = min(ans, s - a + b);
        }
        return ans;
    }
};
```

#### Go

```go
func minDistance(height int, width int, tree []int, squirrel []int, nuts [][]int) int {
	tr, tc := tree[0], tree[1]
	sr, sc := squirrel[0], squirrel[1]
	s := 0
	for _, e := range nuts {
		s += abs(e[0]-tr) + abs(e[1]-tc)
	}
	s <<= 1
	ans := math.MaxInt32
	for _, e := range nuts {
		a := abs(e[0]-tr) + abs(e[1]-tc)
		b := abs(e[0]-sr) + abs(e[1]-sc)
		ans = min(ans, s-a+b)
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
function minDistance(
    height: number,
    width: number,
    tree: number[],
    squirrel: number[],
    nuts: number[][],
): number {
    const [tr, tc] = tree;
    const [sr, sc] = squirrel;
    const s = nuts.reduce((acc, [r, c]) => acc + (Math.abs(tr - r) + Math.abs(tc - c)) * 2, 0);
    let ans = Infinity;
    for (const [r, c] of nuts) {
        const a = Math.abs(tr - r) + Math.abs(tc - c);
        const b = Math.abs(sr - r) + Math.abs(sc - c);
        ans = Math.min(ans, s - a + b);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_distance(
        height: i32,
        width: i32,
        tree: Vec<i32>,
        squirrel: Vec<i32>,
        nuts: Vec<Vec<i32>>,
    ) -> i32 {
        let (tr, tc) = (tree[0], tree[1]);
        let (sr, sc) = (squirrel[0], squirrel[1]);
        let s: i32 = nuts
            .iter()
            .map(|nut| (nut[0] - tr).abs() + (nut[1] - tc).abs())
            .sum::<i32>()
            * 2;

        let mut ans = i32::MAX;
        for nut in &nuts {
            let a = (nut[0] - tr).abs() + (nut[1] - tc).abs();
            let b = (nut[0] - sr).abs() + (nut[1] - sc).abs();
            ans = ans.min(s - a + b);
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MinDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int tr = tree[0], tc = tree[1];
        int sr = squirrel[0], sc = squirrel[1];
        int s = 0;

        foreach (var e in nuts) {
            s += Math.Abs(e[0] - tr) + Math.Abs(e[1] - tc);
        }
        s <<= 1;

        int ans = int.MaxValue;
        foreach (var e in nuts) {
            int a = Math.Abs(e[0] - tr) + Math.Abs(e[1] - tc);
            int b = Math.Abs(e[0] - sr) + Math.Abs(e[1] - sc);
            ans = Math.Min(ans, s - a + b);
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

# [574. 当选者 🔒](https://leetcode.cn/problems/winning-candidate){#574}

{{< tabs "574" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name
FROM
    Candidate AS c
    LEFT JOIN Vote AS v ON c.id = v.candidateId
GROUP BY c.id
ORDER BY COUNT(1) DESC
LIMIT 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Candidate</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
+-------------+----------+
id 是该表中具有唯一值的列
该表的每一行都包含关于候选对象的id和名称的信息。</pre>

<p>&nbsp;</p>

<p>表:&nbsp;<code>Vote</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| candidateId | int  |
+-------------+------+
id 是自动递增的主键(具有唯一值的列)。
candidateId是id来自Candidate表的外键(reference 列)。
该表的每一行决定了在选举中获得第i张选票的候选人。</pre>

<p>&nbsp;</p>

<p>编写解决方案来报告获胜候选人的名字(即获得最多选票的候选人)。</p>

<p>生成的测试用例保证&nbsp;<strong>只有一个候选人赢得&nbsp;</strong>选举。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Candidate table:
+----+------+
| id | name |
+----+------+
| 1  | A    |
| 2  | B    |
| 3  | C    |
| 4  | D    |
| 5  | E    |
+----+------+
Vote table:
+----+-------------+
| id | candidateId |
+----+-------------+
| 1  | 2           |
| 2  | 4           |
| 3  | 3           |
| 4  | 2           |
| 5  | 5           |
+----+-------------+
<strong>输出:</strong> 
+------+
| name |
+------+
| B    |
+------+
<strong>解释:</strong> 
候选人B有2票。候选人C、D、E各有1票。
获胜者是候选人B。</pre>

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
SELECT
    Name
FROM
    (
        SELECT
            CandidateId AS id
        FROM Vote
        GROUP BY CandidateId
        ORDER BY COUNT(id) DESC
        LIMIT 1
    ) AS t
    INNER JOIN Candidate AS c ON t.id = c.id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name
FROM
    Candidate AS c
    LEFT JOIN Vote AS v ON c.id = v.candidateId
GROUP BY c.id
ORDER BY COUNT(1) DESC
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [575. 分糖果](https://leetcode.cn/problems/distribute-candies){#575}

{{< tabs "575" >}}

{{% tab "python" %}}
```python
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(candyType) >> 1, len(set(candyType)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> s = new HashSet<>();
        for (int c : candyType) {
            s.add(c);
        }
        return Math.min(candyType.length >> 1, s.size());
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(candyType.size() >> 1, s.size());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCandies(candyType []int) int {
	s := hashset.New()
	for _, c := range candyType {
		s.Add(c)
	}
	return min(len(candyType)>>1, s.Size())
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCandies(candyType: number[]): number {
    const s = new Set(candyType);
    return Math.min(s.size, candyType.length >> 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 有 <code>n</code> 枚糖，其中第 <code>i</code> 枚糖的类型为 <code>candyType[i]</code> 。Alice 注意到她的体重正在增长，所以前去拜访了一位医生。</p>

<p>医生建议 Alice 要少摄入糖分，只吃掉她所有糖的 <code>n / 2</code> 即可（<code>n</code> 是一个偶数）。Alice 非常喜欢这些糖，她想要在遵循医生建议的情况下，尽可能吃到最多不同种类的糖。</p>

<p>给你一个长度为 <code>n</code> 的整数数组 <code>candyType</code> ，返回： Alice <em>在仅吃掉 <code>n / 2</code> 枚糖的情况下，可以吃到糖的 <strong>最多</strong> 种类数</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candyType = [1,1,2,2,3,3]
<strong>输出：</strong>3
<strong>解释：</strong>Alice 只能吃 6 / 2 = 3 枚糖，由于只有 3 种糖，她可以每种吃一枚。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candyType = [1,1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>Alice 只能吃 4 / 2 = 2 枚糖，不管她选择吃的种类是 [1,2]、[1,3] 还是 [2,3]，她只能吃到两种不同类的糖。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>candyType = [6,6,6,6]
<strong>输出：</strong>1
<strong>解释：</strong>Alice 只能吃 4 / 2 = 2 枚糖，尽管她能吃 2 枚，但只能吃到 1 种糖。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == candyType.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>n</code> 是一个偶数</li>
	<li><code>-10<sup>5</sup> &lt;= candyType[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表来存储糖果的种类，如果糖果的种类数小于 $n / 2$，那么 Alice 最多可以吃到的糖果种类数就是糖果的种类数；否则，Alice 最多可以吃到的糖果种类数就是 $n / 2$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为糖果的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(candyType) >> 1, len(set(candyType)))
```

#### Java

```java
class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> s = new HashSet<>();
        for (int c : candyType) {
            s.add(c);
        }
        return Math.min(candyType.length >> 1, s.size());
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(candyType.size() >> 1, s.size());
    }
};
```

#### Go

```go
func distributeCandies(candyType []int) int {
	s := hashset.New()
	for _, c := range candyType {
		s.Add(c)
	}
	return min(len(candyType)>>1, s.Size())
}
```

#### TypeScript

```ts
function distributeCandies(candyType: number[]): number {
    const s = new Set(candyType);
    return Math.min(s.size, candyType.length >> 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [576. 出界的路径数](https://leetcode.cn/problems/out-of-boundary-paths){#576}

{{< tabs "576" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPaths(
        self, m: int, n: int, maxMove: int, startRow: int, startColumn: int
    ) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if not 0 <= i < m or not 0 <= j < n:
                return int(k >= 0)
            if k <= 0:
                return 0
            ans = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                ans = (ans + dfs(x, y, k - 1)) % mod
            return ans

        mod = 10**9 + 7
        dirs = (-1, 0, 1, 0, -1)
        return dfs(startRow, startColumn, maxMove)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m, n;
    private Integer[][][] f;
    private final int mod = (int) 1e9 + 7;

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this.m = m;
        this.n = n;
        f = new Integer[m][n][maxMove + 1];
        return dfs(startRow, startColumn, maxMove);
    }

    private int dfs(int i, int j, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return k >= 0 ? 1 : 0;
        }
        if (k <= 0) {
            return 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = 0;
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d], y = j + dirs[d + 1];
            ans = (ans + dfs(x, y, k - 1)) % mod;
        }
        return f[i][j][k] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int f[m][n][maxMove + 1];
        memset(f, -1, sizeof(f));
        const int mod = 1e9 + 7;
        const int dirs[5] = {-1, 0, 1, 0, -1};
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return k >= 0;
            }
            if (k <= 0) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = 0;
            for (int d = 0; d < 4; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                ans = (ans + dfs(x, y, k - 1)) % mod;
            }
            return f[i][j][k] = ans;
        };
        return dfs(startRow, startColumn, maxMove);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPaths(m int, n int, maxMove int, startRow int, startColumn int) int {
	f := make([][][]int, m)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, maxMove+1)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	const mod int = 1e9 + 7
	var dfs func(int, int, int) int
	dirs := [5]int{-1, 0, 1, 0, -1}
	dfs = func(i, j, k int) int {
		if i < 0 || i >= m || j < 0 || j >= n {
			if k >= 0 {
				return 1
			}
			return 0
		}
		if k <= 0 {
			return 0
		}
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		ans := 0
		for d := 0; d < 4; d++ {
			x, y := i+dirs[d], j+dirs[d+1]
			ans = (ans + dfs(x, y, k-1)) % mod
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(startRow, startColumn, maxMove)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPaths(
    m: number,
    n: number,
    maxMove: number,
    startRow: number,
    startColumn: number,
): number {
    const f = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(maxMove + 1).fill(-1)),
    );
    const mod = 1000000007;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, k: number): number => {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return k >= 0 ? 1 : 0;
        }
        if (k <= 0) {
            return 0;
        }
        if (f[i][j][k] !== -1) {
            return f[i][j][k];
        }
        let ans = 0;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            ans = (ans + dfs(x, y, k - 1)) % mod;
        }
        return (f[i][j][k] = ans);
    };
    return dfs(startRow, startColumn, maxMove);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的网格和一个球。球的起始坐标为 <code>[startRow, startColumn]</code> 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 <strong>最多</strong> 可以移动 <code>maxMove</code> 次球。</p>

<p>给你五个整数 <code>m</code>、<code>n</code>、<code>maxMove</code>、<code>startRow</code> 以及 <code>startColumn</code> ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0576.Out%20of%20Boundary%20Paths/images/out_of_boundary_paths_1.png" style="width: 500px; height: 296px;" />
<pre>
<strong>输入：</strong>m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0576.Out%20of%20Boundary%20Paths/images/out_of_boundary_paths_2.png" style="width: 500px; height: 293px;" />
<pre>
<strong>输入：</strong>m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= maxMove &lt;= 50</code></li>
	<li><code>0 &lt;= startRow &lt; m</code></li>
	<li><code>0 &lt;= startColumn &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们定义一个函数 $\textit{dfs}(i, j, k)$ 表示从坐标 $(i, j)$ 出发，还剩下 $k$ 步可以移动的情况下，可以移出边界的路径数量。

在函数 $\textit{dfs}(i, j, k)$ 中，我们首先处理边界情况，如果当前坐标 $(i, j)$ 不在网格范围内，如果 $k \geq 0$，则返回 $1$，否则返回 $0$。如果 $k \leq 0$，说明还在网格内，但是已经没有移动次数了，返回 $0$。接下来，我们遍历四个方向，移动到下一个坐标 $(x, y)$，然后递归调用 $\textit{dfs}(x, y, k - 1)$，并将结果累加到答案中。

在主函数中，我们调用 $\textit{dfs}(startRow, startColumn, maxMove)$，即从起始坐标 $(\textit{startRow}, \textit{startColumn})$ 出发，还剩下 $\textit{maxMove}$ 步可以移动的情况下，可以移出边界的路径数量。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(m \times n \times k)$，空间复杂度 $O(m \times n \times k)$。其中 $m$ 和 $n$ 分别是网格的行数和列数，而 $k$ 是可以移动的步数，本题中 $k = \textit{maxMove} \leq 50$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPaths(
        self, m: int, n: int, maxMove: int, startRow: int, startColumn: int
    ) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if not 0 <= i < m or not 0 <= j < n:
                return int(k >= 0)
            if k <= 0:
                return 0
            ans = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                ans = (ans + dfs(x, y, k - 1)) % mod
            return ans

        mod = 10**9 + 7
        dirs = (-1, 0, 1, 0, -1)
        return dfs(startRow, startColumn, maxMove)
```

#### Java

```java
class Solution {
    private int m, n;
    private Integer[][][] f;
    private final int mod = (int) 1e9 + 7;

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this.m = m;
        this.n = n;
        f = new Integer[m][n][maxMove + 1];
        return dfs(startRow, startColumn, maxMove);
    }

    private int dfs(int i, int j, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return k >= 0 ? 1 : 0;
        }
        if (k <= 0) {
            return 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = 0;
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d], y = j + dirs[d + 1];
            ans = (ans + dfs(x, y, k - 1)) % mod;
        }
        return f[i][j][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int f[m][n][maxMove + 1];
        memset(f, -1, sizeof(f));
        const int mod = 1e9 + 7;
        const int dirs[5] = {-1, 0, 1, 0, -1};
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return k >= 0;
            }
            if (k <= 0) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = 0;
            for (int d = 0; d < 4; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                ans = (ans + dfs(x, y, k - 1)) % mod;
            }
            return f[i][j][k] = ans;
        };
        return dfs(startRow, startColumn, maxMove);
    }
};
```

#### Go

```go
func findPaths(m int, n int, maxMove int, startRow int, startColumn int) int {
	f := make([][][]int, m)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, maxMove+1)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	const mod int = 1e9 + 7
	var dfs func(int, int, int) int
	dirs := [5]int{-1, 0, 1, 0, -1}
	dfs = func(i, j, k int) int {
		if i < 0 || i >= m || j < 0 || j >= n {
			if k >= 0 {
				return 1
			}
			return 0
		}
		if k <= 0 {
			return 0
		}
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		ans := 0
		for d := 0; d < 4; d++ {
			x, y := i+dirs[d], j+dirs[d+1]
			ans = (ans + dfs(x, y, k-1)) % mod
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(startRow, startColumn, maxMove)
}
```

#### TypeScript

```ts
function findPaths(
    m: number,
    n: number,
    maxMove: number,
    startRow: number,
    startColumn: number,
): number {
    const f = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(maxMove + 1).fill(-1)),
    );
    const mod = 1000000007;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, k: number): number => {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return k >= 0 ? 1 : 0;
        }
        if (k <= 0) {
            return 0;
        }
        if (f[i][j][k] !== -1) {
            return f[i][j][k];
        }
        let ans = 0;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            ans = (ans + dfs(x, y, k - 1)) % mod;
        }
        return (f[i][j][k] = ans);
    };
    return dfs(startRow, startColumn, maxMove);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [577. 员工奖金](https://leetcode.cn/problems/employee-bonus){#577}

{{< tabs "577" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name, bonus
FROM
    Employee
    LEFT JOIN Bonus USING (empId)
WHERE IFNULL(bonus, 0) < 1000;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Employee</code>&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId 是该表中具有唯一值的列。
该表的每一行都表示员工的 id 和姓名，以及他们经理的 id 和他们的工资。
</pre>

<p>&nbsp;</p>

<p>表：<code>Bonus</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId 是该表具有唯一值的列。
empId 是 Employee 表中 empId 的外键(reference 列)。
该表的每一行都包含一个员工的 id 和他们各自的奖金。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告每个奖金 <strong>少于</strong> <code>1000</code> 的员工的姓名和奖金数额。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+
Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
<b>输出：</b>
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接

我们可以使用左连接，将 `Employee` 表和 `Bonus` 表按照 `empId` 进行连接，然后筛选出奖金小于 $1000$ 的员工。注意，连接后的表中，`bonus` 为 `NULL` 的员工也应该被筛选出来，因此我们需要使用 `IFNULL` 函数将 `NULL` 值转换为 $0$。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name, bonus
FROM
    Employee
    LEFT JOIN Bonus USING (empId)
WHERE IFNULL(bonus, 0) < 1000;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [578. 查询回答率最高的问题 🔒](https://leetcode.cn/problems/get-highest-answer-rate-question){#578}

{{< tabs "578" >}}

{{% tab "sql" %}}
```sql
WITH
    T AS (
        SELECT
            question_id AS survey_log,
            (SUM(action = 'answer') OVER (PARTITION BY question_id)) / (
                SUM(action = 'show') OVER (PARTITION BY question_id)
            ) AS ratio
        FROM SurveyLog
    )
SELECT survey_log
FROM T
ORDER BY ratio DESC, 1
LIMIT 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>SurveyLog</code> 表：</p>

<div class="original__bRMd">
<div>
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| action      | ENUM |
| question_id | int  |
| answer_id   | int  |
| q_num       | int  |
| timestamp   | int  |
+-------------+------+
这张表可能包含重复项。
action 是一个 ENUM(category) 数据，可以是 "show"、"answer" 或者 "skip" 。
这张表的每一行表示：ID = id 的用户对 question_id 的问题在 timestamp 时间进行了 action 操作。
如果用户对应的操作是 "answer" ，answer_id 将会是对应答案的 id ，否则，值为 null 。
q_num 是该问题在当前会话中的数字顺序。
</pre>

<p>&nbsp;</p>

<p><strong>回答率</strong> 是指：同一问题编号中回答次数占显示次数的比率。</p>

<p>编写一个解决方案以报告 <strong>回答率</strong> 最高的问题。如果有多个问题具有相同的最大 <strong>回答率</strong> ，返回 <code>question_id</code> 最小的那个。</p>

<p>查询结果如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
SurveyLog table:
+----+--------+-------------+-----------+-------+-----------+
| id | action | question_id | answer_id | q_num | timestamp |
+----+--------+-------------+-----------+-------+-----------+
| 5  | show   | 285         | null      | 1     | 123       |
| 5  | answer | 285         | 124124    | 1     | 124       |
| 5  | show   | 369         | null      | 2     | 125       |
| 5  | skip   | 369         | null      | 2     | 126       |
+----+--------+-------------+-----------+-------+-----------+
<strong>输出：</strong>
+------------+
| survey_log |
+------------+
| 285        |
+------------+
<strong>解释：</strong>
问题 285 显示 1 次、回答 1 次。回答率为 1.0 。
问题 369 显示 1 次、回答 0 次。回答率为 0.0 。
问题 285 回答率最高。</pre>
</div>
</div>

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
SELECT question_id AS survey_log
FROM SurveyLog
GROUP BY 1
ORDER BY SUM(action = 'answer') / SUM(action = 'show') DESC, 1
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
WITH
    T AS (
        SELECT
            question_id AS survey_log,
            (SUM(action = 'answer') OVER (PARTITION BY question_id)) / (
                SUM(action = 'show') OVER (PARTITION BY question_id)
            ) AS ratio
        FROM SurveyLog
    )
SELECT survey_log
FROM T
ORDER BY ratio DESC, 1
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [579. 查询员工的累计薪水 🔒](https://leetcode.cn/problems/find-cumulative-salary-of-an-employee){#579}

{{< tabs "579" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            id,
            month,
            SUM(salary) OVER (
                PARTITION BY id
                ORDER BY month
                RANGE 2 PRECEDING
            ) AS salary,
            RANK() OVER (
                PARTITION BY id
                ORDER BY month DESC
            ) AS rk
        FROM Employee
    )
SELECT id, month, salary
FROM T
WHERE rk > 1
ORDER BY 1, 2 DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Employee</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| month       | int  |
| salary      | int  |
+-------------+------+
(id, month) 是该表的主键(具有唯一值的列的组合)。
表中的每一行表示 2020 年期间员工一个月的工资。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，在一个统一的表中计算出每个员工的 <strong>累计工资汇总</strong> 。</p>

<p>员工的 <strong>累计工资汇总</strong> 可以计算如下:</p>

<ul>
	<li>对于该员工工作的每个月，将 <strong>该月</strong> 和 <strong>前两个月</strong> 的工资 <strong>加</strong> 起来。这是他们当月的 <strong>3 个月总工资</strong><strong>和</strong> 。如果员工在前几个月没有为公司工作，那么他们在前几个月的有效工资为 <code>0</code> 。</li>
	<li><strong>不要</strong> 在摘要中包括员工 <strong>最近一个月</strong> 的 3 个月总工资和。</li>
	<li><strong>不要</strong> 包括雇员 <strong>没有工作</strong> 的任何一个月的 3 个月总工资和。</li>
</ul>

<p>返回按 <code>id</code> <strong>升序排序&nbsp;</strong>的结果表。如果 <code>id</code> 相等，请按 <code>month</code> <strong>降序排序</strong>。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1</strong></p>

<pre>
<b>输入：</b>
Employee table:
+----+-------+--------+
| id | month | salary |
+----+-------+--------+
| 1  | 1     | 20     |
| 2  | 1     | 20     |
| 1  | 2     | 30     |
| 2  | 2     | 30     |
| 3  | 2     | 40     |
| 1  | 3     | 40     |
| 3  | 3     | 60     |
| 1  | 4     | 60     |
| 3  | 4     | 70     |
| 1  | 7     | 90     |
| 1  | 8     | 90     |
+----+-------+--------+
<b>输出：</b>
+----+-------+--------+
| id | month | Salary |
+----+-------+--------+
| 1  | 7     | 90     |
| 1  | 4     | 130    |
| 1  | 3     | 90     |
| 1  | 2     | 50     |
| 1  | 1     | 20     |
| 2  | 1     | 20     |
| 3  | 3     | 100    |
| 3  | 2     | 40     |
+----+-------+--------+
<b>解释：</b>
员工 “1” 有 5 条工资记录，不包括最近一个月的 “8”:
- 第 '7' 个月为 90。
- 第 '4' 个月为 60。
- 第 '3' 个月是 40。
- 第 '2' 个月为 30。
- 第 '1' 个月为 20。
因此，该员工的累计工资汇总为:
+----+-------+--------+
| id | month | salary |
+----+-------+--------+
| 1  | 7     | 90     |  (90 + 0 + 0)
| 1  | 4     | 130    |  (60 + 40 + 30)
| 1  | 3     | 90     |  (40 + 30 + 20)
| 1  | 2     | 50     |  (30 + 20 + 0)
| 1  | 1     | 20     |  (20 + 0 + 0)
+----+-------+--------+
请注意，'7' 月的 3 个月的总和是 90，因为他们没有在 '6' 月或 '5' 月工作。

员工 '2' 只有一个工资记录('1' 月)，不包括最近的 '2' 月。
+----+-------+--------+
| id | month | salary |
+----+-------+--------+
| 2  | 1     | 20     |  (20 + 0 + 0)
+----+-------+--------+

员工 '3' 有两个工资记录，不包括最近一个月的 '4' 月:
- 第 '3' 个月为 60 。
- 第 '2' 个月是 40。
因此，该员工的累计工资汇总为:
+----+-------+--------+
| id | month | salary |
+----+-------+--------+
| 3  | 3     | 100    |  (60 + 40 + 0)
| 3  | 2     | 40     |  (40 + 0 + 0)
+----+-------+--------+</pre>

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
SELECT
    id,
    month,
    SUM(salary) OVER (
        PARTITION BY id
        ORDER BY month
        RANGE 2 PRECEDING
    ) AS Salary
FROM employee
WHERE
    (id, month) NOT IN (
        SELECT
            id,
            MAX(month)
        FROM Employee
        GROUP BY id
    )
ORDER BY id, month DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            id,
            month,
            SUM(salary) OVER (
                PARTITION BY id
                ORDER BY month
                RANGE 2 PRECEDING
            ) AS salary,
            RANK() OVER (
                PARTITION BY id
                ORDER BY month DESC
            ) AS rk
        FROM Employee
    )
SELECT id, month, salary
FROM T
WHERE rk > 1
ORDER BY 1, 2 DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
