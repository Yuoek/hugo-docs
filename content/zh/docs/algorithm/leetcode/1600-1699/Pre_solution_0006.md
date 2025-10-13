---
title: "1650_二叉树的最近公共祖先 III 🔒"
date: 2025-10-08T18:38:12+08:00
weight: 6
tags: [二分查找, 二叉树, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 字符串, 广度优先搜索, 排序, 数据库, 数据流, 数组, 栈, 树, 滑动窗口, 状态压缩, 计数, 记忆化搜索, 设计]
---

{{< markmap >}}
### [1650_二叉树的最近公共祖先 III 🔒](#1650)
#### [树](#1650)
#### [哈希表](#1650)
#### [双指针](#1650)
#### [二叉树](#1650)
### [1651_Hopper 公司查询 III 🔒](#1651)
#### [数据库](#1651)
### [1652_拆炸弹](#1652)
#### [数组](#1652)
#### [滑动窗口](#1652)
### [1653_使字符串平衡的最少删除次数](#1653)
#### [栈](#1653)
#### [字符串](#1653)
#### [动态规划](#1653)
### [1654_到家的最少跳跃次数](#1654)
#### [广度优先搜索](#1654)
#### [数组](#1654)
#### [动态规划](#1654)
### [1655_分配重复整数](#1655)
#### [位运算](#1655)
#### [数组](#1655)
#### [动态规划](#1655)
#### [回溯](#1655)
#### [状态压缩](#1655)
### [1656_设计有序流](#1656)
#### [设计](#1656)
#### [数组](#1656)
#### [哈希表](#1656)
#### [数据流](#1656)
### [1657_确定两个字符串是否接近](#1657)
#### [哈希表](#1657)
#### [字符串](#1657)
#### [计数](#1657)
#### [排序](#1657)
### [1658_将 x 减到 0 的最小操作数](#1658)
#### [数组](#1658)
#### [哈希表](#1658)
#### [二分查找](#1658)
#### [前缀和](#1658)
#### [滑动窗口](#1658)
### [1659_最大化网格幸福感](#1659)
#### [位运算](#1659)
#### [记忆化搜索](#1659)
#### [动态规划](#1659)
#### [状态压缩](#1659)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1650_二叉树的最近公共祖先 III 🔒
___
#### 树
___
#### 哈希表
___
#### 双指针
___
#### 二叉树
---
### 1651_Hopper 公司查询 III 🔒
___
#### 数据库
---
### 1652_拆炸弹
___
#### 数组
___
#### 滑动窗口
---
### 1653_使字符串平衡的最少删除次数
___
#### 栈
___
#### 字符串
___
#### 动态规划
---
### 1654_到家的最少跳跃次数
___
#### 广度优先搜索
___
#### 数组
___
#### 动态规划
---
### 1655_分配重复整数
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 1656_设计有序流
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 数据流
---
### 1657_确定两个字符串是否接近
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
---
### 1658_将 x 减到 0 的最小操作数
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 1659_最大化网格幸福感
___
#### 位运算
___
#### 记忆化搜索
___
#### 动态规划
___
#### 状态压缩
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 双指针 |
| 哈希表 | 回溯 | 字符串 |
| 广度优先搜索 | 排序 | 数据库 |
| 数据流 | 数组 | 栈 |
| 树 | 滑动窗口 | 状态压缩 |
| 计数 | 记忆化搜索 | 设计 |

# [1650. 二叉树的最近公共祖先 III 🔒](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-iii){#1650}

{{< tabs "1650" >}}

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
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        a, b = p, q
        while a != b:
            a = a.parent if a.parent else q
            b = b.parent if b.parent else p
        return a
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
    public Node lowestCommonAncestor(Node p, Node q) {
        Node a = p, b = q;
        while (a != b) {
            a = a.parent == null ? q : a.parent;
            b = b.parent == null ? p : b.parent;
        }
        return a;
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
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* a = p;
        Node* b = q;
        while (a != b) {
            a = a->parent ? a->parent : q;
            b = b->parent ? b->parent : p;
        }
        return a;
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

func lowestCommonAncestor(p *Node, q *Node) *Node {
	a, b := p, q
	for a != b {
		if a.Parent != nil {
			a = a.Parent
		} else {
			a = q
		}
		if b.Parent != nil {
			b = b.Parent
		} else {
			b = p
		}
	}
	return a
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

function lowestCommonAncestor(p: Node | null, q: Node | null): Node | null {
    let [a, b] = [p, q];
    while (a != b) {
        a = a.parent ?? q;
        b = b.parent ?? p;
    }
    return a;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树中的两个节点 <code>p</code> 和 <code>q</code>，返回它们的最近公共祖先节点（LCA）。</p>

<p>每个节点都包含其父节点的引用（指针）。<code>Node</code>&nbsp;的定义如下：</p>

<pre>
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
</pre>

<p>根据<a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor">维基百科中对最近公共祖先节点的定义</a>：“两个节点 p 和 q 在二叉树 T 中的最近公共祖先节点是后代节点中既包括 p&nbsp;又包括&nbsp;q&nbsp;的最深节点（我们允许<strong>一个节点为自身的一个后代节点</strong>）”。一个节点 x&nbsp;的后代节点是节点&nbsp;x 到某一叶节点间的路径中的节点 y。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1650.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20III/images/binarytree.png" style="width: 200px; height: 190px;" />
<pre>
<strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>输出:</strong> 3
<strong>解释:</strong> 节点 5 和 1 的最近公共祖先是 3。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1650.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20III/images/binarytree.png" style="width: 200px; height: 190px;" />
<pre>
<strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>输出:</strong> 5
<strong>解释:</strong> 节点 5 和 4 的最近公共祖先是 5，根据定义，一个节点可以是自身的最近公共祖先。
</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入:</strong> root = [1,2], p = 1, q = 2
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点个数的范围是&nbsp;<code>[2, 10<sup>5</sup>]</code>。</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>所有的&nbsp;<code>Node.val</code>&nbsp;都是<strong>互不相同</strong>的。</li>
	<li><code>p != q</code></li>
	<li><code>p</code>&nbsp;和&nbsp;<code>q</code>&nbsp;存在于树中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $vis$ 记录从节点 $p$ 开始到根节点的路径上的所有节点，接下来从节点 $q$ 开始往根节点方向遍历，如果遇到一个节点存在于哈希表 $vis$ 中，那么该节点就是 $p$ 和 $q$ 的最近公共祖先节点，直接返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def lowestCommonAncestor(self, p: "Node", q: "Node") -> "Node":
        vis = set()
        node = p
        while node:
            vis.add(node)
            node = node.parent
        node = q
        while node not in vis:
            node = node.parent
        return node
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
    public Node lowestCommonAncestor(Node p, Node q) {
        Set<Node> vis = new HashSet<>();
        for (Node node = p; node != null; node = node.parent) {
            vis.add(node);
        }
        for (Node node = q;; node = node.parent) {
            if (!vis.add(node)) {
                return node;
            }
        }
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
    Node* lowestCommonAncestor(Node* p, Node* q) {
        unordered_set<Node*> vis;
        for (Node* node = p; node; node = node->parent) {
            vis.insert(node);
        }
        for (Node* node = q;; node = node->parent) {
            if (vis.count(node)) {
                return node;
            }
        }
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

func lowestCommonAncestor(p *Node, q *Node) *Node {
	vis := map[*Node]bool{}
	for node := p; node != nil; node = node.Parent {
		vis[node] = true
	}
	for node := q; ; node = node.Parent {
		if vis[node] {
			return node
		}
	}
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

function lowestCommonAncestor(p: Node | null, q: Node | null): Node | null {
    const vis: Set<Node> = new Set();
    for (let node = p; node; node = node.parent) {
        vis.add(node);
    }
    for (let node = q; ; node = node.parent) {
        if (vis.has(node)) {
            return node;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

我们可以用两个指针 $a$ 和 $b$ 分别指向节点 $p$ 和 $q$，然后分别往根节点方向遍历，当 $a$ 和 $b$ 相遇时，就是 $p$ 和 $q$ 的最近公共祖先节点。否则，如果指针 $a$ 遍历到了根节点，那么我们就让它指向节点 $q$，指针 $b$ 同理。这样，当两个指针相遇时，就是 $p$ 和 $q$ 的最近公共祖先节点。

时间复杂度 $O(n)$，其中 $n$ 是二叉树的节点数。空间复杂度 $O(1)$。

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
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        a, b = p, q
        while a != b:
            a = a.parent if a.parent else q
            b = b.parent if b.parent else p
        return a
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
    public Node lowestCommonAncestor(Node p, Node q) {
        Node a = p, b = q;
        while (a != b) {
            a = a.parent == null ? q : a.parent;
            b = b.parent == null ? p : b.parent;
        }
        return a;
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
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* a = p;
        Node* b = q;
        while (a != b) {
            a = a->parent ? a->parent : q;
            b = b->parent ? b->parent : p;
        }
        return a;
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

func lowestCommonAncestor(p *Node, q *Node) *Node {
	a, b := p, q
	for a != b {
		if a.Parent != nil {
			a = a.Parent
		} else {
			a = q
		}
		if b.Parent != nil {
			b = b.Parent
		} else {
			b = p
		}
	}
	return a
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

function lowestCommonAncestor(p: Node | null, q: Node | null): Node | null {
    let [a, b] = [p, q];
    while (a != b) {
        a = a.parent ?? q;
        b = b.parent ?? p;
    }
    return a;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1651. Hopper 公司查询 III 🔒](https://leetcode.cn/problems/hopper-company-queries-iii){#1651}

{{< tabs "1651" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    Months AS (
        SELECT 1 AS month
        UNION ALL
        SELECT month + 1
        FROM Months
        WHERE month < 12
    ),
    Ride AS (
        SELECT
            month,
            SUM(IFNULL(ride_distance, 0)) AS ride_distance,
            SUM(IFNULL(ride_duration, 0)) AS ride_duration
        FROM
            Months AS m
            LEFT JOIN Rides AS r ON month = MONTH(requested_at) AND YEAR(requested_at) = 2020
            LEFT JOIN AcceptedRides AS a ON r.ride_id = a.ride_id
        GROUP BY month
    )
SELECT
    month,
    ROUND(
        AVG(ride_distance) OVER (ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING),
        2
    ) AS average_ride_distance,
    ROUND(
        AVG(ride_duration) OVER (ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING),
        2
    ) AS average_ride_duration
FROM Ride
ORDER BY month
LIMIT 10;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Drivers</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| driver_id   | int     |
| join_date   | date    |
+-------------+---------+
driver_id 是该表具有唯一值的列。
该表的每一行均包含驾驶员的 ID 以及他们加入 Hopper 公司的日期。</pre>

<p>&nbsp;</p>

<p>表：<code>Rides</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| ride_id      | int     |
| user_id      | int     |
| requested_at | date    |
+--------------+---------+
ride_id 是该表具有唯一值的列。 
该表的每一行均包含行程 ID(ride_id)，用户 ID(user_id) 以及该行程的日期(requested_at)。 
该表中可能有一些不被接受的乘车请求。
</pre>

<p>&nbsp;</p>

<p><font color="#333333" face="Helvetica Neue, Helvetica, Arial, sans-serif"><span style="font-size: 14px; background-color: rgb(255, 255, 255);">表：</span></font><code>AcceptedRides</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| ride_id       | int     |
| driver_id     | int     |
| ride_distance | int     |
| ride_duration | int     |
+---------------+---------+
ride_id 是该表具有唯一值的列。 
该表的每一行都包含已接受的行程信息。 
表中的行程信息都在 "<code>Rides</code>" 表中存在。</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，计算出从&nbsp;<strong>2020 年 1 月至 3 月 至 2020 年 10 月至 12 月&nbsp;</strong>的每三个月窗口的&nbsp;<code>average_ride_distance</code>&nbsp;和&nbsp;<code>average_ride_duration</code>&nbsp;。并将&nbsp;<code>average_ride_distance</code>&nbsp;和&nbsp;<code>average_ride_duration</code>&nbsp;四舍五入至 <strong>小数点后两位</strong> 。<br />
通过将三个月的总&nbsp;<code>ride_distance</code>&nbsp;相加并除以 <code>3</code> 来计算&nbsp;<code>average_ride_distance</code>&nbsp;。<code>average_ride_duration</code>&nbsp;的计算方法与此类似。<br />
返回按&nbsp;<code>month</code>&nbsp;升序排列的结果表，其中&nbsp;<code>month</code>&nbsp;是起始月份的编号（一月为 1，二月为 2 ...）。</p>

<p>查询结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> 
Drivers table:
+-----------+------------+
| driver_id | join_date  |
+-----------+------------+
| 10        | 2019-12-10 |
| 8         | 2020-1-13  |
| 5         | 2020-2-16  |
| 7         | 2020-3-8   |
| 4         | 2020-5-17  |
| 1         | 2020-10-24 |
| 6         | 2021-1-5   |
+-----------+------------+
Rides table:
+---------+---------+--------------+
| ride_id | user_id | requested_at |
+---------+---------+--------------+
| 6       | 75      | 2019-12-9    |
| 1       | 54      | 2020-2-9     |
| 10      | 63      | 2020-3-4     |
| 19      | 39      | 2020-4-6     |
| 3       | 41      | 2020-6-3     |
| 13      | 52      | 2020-6-22    |
| 7       | 69      | 2020-7-16    |
| 17      | 70      | 2020-8-25    |
| 20      | 81      | 2020-11-2    |
| 5       | 57      | 2020-11-9    |
| 2       | 42      | 2020-12-9    |
| 11      | 68      | 2021-1-11    |
| 15      | 32      | 2021-1-17    |
| 12      | 11      | 2021-1-19    |
| 14      | 18      | 2021-1-27    |
+---------+---------+--------------+
AcceptedRides table:
+---------+-----------+---------------+---------------+
| ride_id | driver_id | ride_distance | ride_duration |
+---------+-----------+---------------+---------------+
| 10      | 10        | 63            | 38            |
| 13      | 10        | 73            | 96            |
| 7       | 8         | 100           | 28            |
| 17      | 7         | 119           | 68            |
| 20      | 1         | 121           | 92            |
| 5       | 7         | 42            | 101           |
| 2       | 4         | 6             | 38            |
| 11      | 8         | 37            | 43            |
| 15      | 8         | 108           | 82            |
| 12      | 8         | 38            | 34            |
| 14      | 1         | 90            | 74            |
+---------+-----------+---------------+---------------+
<strong>输出:</strong> 
+-------+-----------------------+-----------------------+
| month | average_ride_distance | average_ride_duration |
+-------+-----------------------+-----------------------+
| 1     | 21.00                 | 12.67                 |
| 2     | 21.00                 | 12.67                 |
| 3     | 21.00                 | 12.67                 |
| 4     | 24.33                 | 32.00                 |
| 5     | 57.67                 | 41.33                 |
| 6     | 97.33                 | 64.00                 |
| 7     | 73.00                 | 32.00                 |
| 8     | 39.67                 | 22.67                 |
| 9     | 54.33                 | 64.33                 |
| 10    | 56.33                 | 77.00                 |
+-------+-----------------------+-----------------------+
<strong>解释:</strong> 
到1月底--&gt;平均骑行距离=（0+0+63）/3=21，平均骑行持续时间=（0+0+38）/3=12.67
到2月底--&gt;平均骑行距离=（0+63+0）/3=21，平均骑行持续时间=（0+38+0）/3=12.67
到3月底--&gt;平均骑行距离=（63+0+0）/3=21，平均骑行持续时间=（38+0+0）/3=12.67
到4月底--&gt;平均骑行距离=（0+0+73）/3=24.33，平均骑行持续时间=（0+0+96）/3=32.00
到5月底--&gt;平均骑行距离=（0+73+100）/3=57.67，平均骑行持续时间=（0+96+28）/3=41.33
到6月底--&gt;平均骑行距离=（73+100+119）/3=97.33，平均骑行持续时间=（96+28+68）/3=64.00
到7月底--&gt;平均骑行距离=（100+119+0）/3=73.00，平均骑行持续时间=（28+68+0）/3=32.00
到8月底--&gt;平均骑行距离=（119+0+0）/3=39.67，平均骑行持续时间=（68+0+0）/3=22.67
9月底--&gt;平均骑行距离=（0+0+163）/3=54.33，平均骑行持续时间=（0+0+193）/3=64.33
到10月底--&gt;平均骑行距离=（0+163+6）/3=56.33，平均骑行持续时间=（0+193+38）/3=77.00</pre>

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
WITH RECURSIVE
    Months AS (
        SELECT 1 AS month
        UNION ALL
        SELECT month + 1
        FROM Months
        WHERE month < 12
    ),
    Ride AS (
        SELECT
            month,
            SUM(IFNULL(ride_distance, 0)) AS ride_distance,
            SUM(IFNULL(ride_duration, 0)) AS ride_duration
        FROM
            Months AS m
            LEFT JOIN Rides AS r ON month = MONTH(requested_at) AND YEAR(requested_at) = 2020
            LEFT JOIN AcceptedRides AS a ON r.ride_id = a.ride_id
        GROUP BY month
    )
SELECT
    month,
    ROUND(
        AVG(ride_distance) OVER (ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING),
        2
    ) AS average_ride_distance,
    ROUND(
        AVG(ride_duration) OVER (ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING),
        2
    ) AS average_ride_duration
FROM Ride
ORDER BY month
LIMIT 10;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1652. 拆炸弹](https://leetcode.cn/problems/defuse-the-bomb){#1652}

{{< tabs "1652" >}}

{{% tab "python" %}}
```python
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0:
            return ans
        s = list(accumulate(code + code, initial=0))
        for i in range(n):
            if k > 0:
                ans[i] = s[i + k + 1] - s[i + 1]
            else:
                ans[i] = s[i + n] - s[i + k + n]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] ans = new int[n];
        if (k == 0) {
            return ans;
        }
        int[] s = new int[n << 1 | 1];
        for (int i = 0; i < n << 1; ++i) {
            s[i + 1] = s[i] + code[i % n];
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                ans[i] = s[i + k + 1] - s[i + 1];
            } else {
                ans[i] = s[i + n] - s[i + k + n];
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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) {
            return ans;
        }
        vector<int> s(n << 1 | 1);
        for (int i = 0; i < n << 1; ++i) {
            s[i + 1] = s[i] + code[i % n];
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                ans[i] = s[i + k + 1] - s[i + 1];
            } else {
                ans[i] = s[i + n] - s[i + k + n];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decrypt(code []int, k int) []int {
	n := len(code)
	ans := make([]int, n)
	if k == 0 {
		return ans
	}
	s := make([]int, n<<1|1)
	for i := 0; i < n<<1; i++ {
		s[i+1] = s[i] + code[i%n]
	}
	for i := range code {
		if k > 0 {
			ans[i] = s[i+k+1] - s[i+1]
		} else {
			ans[i] = s[i+n] - s[i+k+n]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decrypt(code: number[], k: number): number[] {
    const n: number = code.length;
    const ans: number[] = Array(n).fill(0);

    if (k === 0) {
        return ans;
    }

    const s: number[] = Array((n << 1) | 1).fill(0);
    for (let i = 0; i < n << 1; ++i) {
        s[i + 1] = s[i] + code[i % n];
    }

    for (let i = 0; i < n; ++i) {
        if (k > 0) {
            ans[i] = s[i + k + 1] - s[i + 1];
        } else {
            ans[i] = s[i + n] - s[i + k + n];
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

<p>你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 <code>n</code> 的 <strong>循环</strong> 数组 <code>code</code> 以及一个密钥 <code>k</code> 。</p>

<p>为了获得正确的密码，你需要替换掉每一个数字。所有数字会 <strong>同时</strong> 被替换。</p>

<ul>
	<li>如果 <code>k > 0</code> ，将第 <code>i</code> 个数字用 <strong>接下来</strong> <code>k</code> 个数字之和替换。</li>
	<li>如果 <code>k < 0</code> ，将第 <code>i</code> 个数字用 <strong>之前</strong> <code>k</code> 个数字之和替换。</li>
	<li>如果 <code>k == 0</code> ，将第 <code>i</code> 个数字用 <code>0</code> 替换。</li>
</ul>

<p>由于 <code>code</code> 是循环的， <code>code[n-1]</code> 下一个元素是 <code>code[0]</code> ，且 <code>code[0]</code> 前一个元素是 <code>code[n-1]</code> 。</p>

<p>给你 <strong>循环</strong> 数组 <code>code</code> 和整数密钥 <code>k</code> ，请你返回解密后的结果来拆除炸弹！</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>code = [5,7,1,4], k = 3
<b>输出：</b>[12,10,16,13]
<b>解释：</b>每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>code = [1,2,3,4], k = 0
<b>输出：</b>[0,0,0,0]
<b>解释：</b>当 k 为 0 时，所有数字都被 0 替换。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>code = [2,4,9,3], k = -2
<b>输出：</b>[12,5,6,13]
<b>解释：</b>解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 <strong>之前</strong> 的数字。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == code.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>1 <= code[i] <= 100</code></li>
	<li><code>-(n - 1) <= k <= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个长度为 $n$ 的答案数组 $ans$，初始时所有元素都为 $0$。根据题意，若 $k$ 为 $0$，直接返回 $ans$。

否则，遍历每个位置 $i$：

若 $k$ 为正数，那么 $i$ 位置的值为 $i$ 位置后 $k$ 个位置的值之和，即：

$$
ans[i] = \sum_{j=i+1}^{i+k} code[j \bmod n]
$$

若 $k$ 为负数，那么 $i$ 位置的值为 $i$ 位置前 $|k|$ 个位置的值之和，即：

$$
ans[i] = \sum_{j=i+k}^{i-1} code[(j+n) \bmod n]
$$

时间复杂度 $O(n \times |k|)$，忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0:
            return ans
        for i in range(n):
            if k > 0:
                for j in range(i + 1, i + k + 1):
                    ans[i] += code[j % n]
            else:
                for j in range(i + k, i):
                    ans[i] += code[(j + n) % n]
        return ans
```

#### Java

```java
class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] ans = new int[n];
        if (k == 0) {
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                for (int j = i + 1; j < i + k + 1; ++j) {
                    ans[i] += code[j % n];
                }
            } else {
                for (int j = i + k; j < i; ++j) {
                    ans[i] += code[(j + n) % n];
                }
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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) {
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                for (int j = i + 1; j < i + k + 1; ++j) {
                    ans[i] += code[j % n];
                }
            } else {
                for (int j = i + k; j < i; ++j) {
                    ans[i] += code[(j + n) % n];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func decrypt(code []int, k int) []int {
	n := len(code)
	ans := make([]int, n)
	if k == 0 {
		return ans
	}
	for i := 0; i < n; i++ {
		if k > 0 {
			for j := i + 1; j < i+k+1; j++ {
				ans[i] += code[j%n]
			}
		} else {
			for j := i + k; j < i; j++ {
				ans[i] += code[(j+n)%n]
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function decrypt(code: number[], k: number): number[] {
    const n: number = code.length;
    const ans: number[] = Array(n).fill(0);

    if (k === 0) {
        return ans;
    }

    for (let i = 0; i < n; ++i) {
        if (k > 0) {
            for (let j = i + 1; j < i + k + 1; ++j) {
                ans[i] += code[j % n];
            }
        } else {
            for (let j = i + k; j < i; ++j) {
                ans[i] += code[(j + n) % n];
            }
        }
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀和

在方法一中，对于每个位置 $i$，都需要遍历 $k$ 个位置，有很多重复计算的操作。我们可以利用前缀和来优化。

我们将 `code` 数组复制一份（可以不用执行复制操作，直接通过循环遍历取模实现），得到两倍长度的数组，对其求前缀和，得到长度为 $2 \times n + 1$ 的前缀和数组 $s$。

若 $k$ 为正数，那么 $i$ 位置的值为 $i$ 位置后 $k$ 个位置的值之和，即 $ans[i] = s[i + k + 1] - s[i + 1]$。

若 $k$ 为负数，那么 $i$ 位置的值为 $i$ 位置前 $|k|$ 个位置的值之和，即 $ans[i] = s[i + n] - s[i + k + n]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `code` 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0:
            return ans
        s = list(accumulate(code + code, initial=0))
        for i in range(n):
            if k > 0:
                ans[i] = s[i + k + 1] - s[i + 1]
            else:
                ans[i] = s[i + n] - s[i + k + n]
        return ans
```

#### Java

```java
class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] ans = new int[n];
        if (k == 0) {
            return ans;
        }
        int[] s = new int[n << 1 | 1];
        for (int i = 0; i < n << 1; ++i) {
            s[i + 1] = s[i] + code[i % n];
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                ans[i] = s[i + k + 1] - s[i + 1];
            } else {
                ans[i] = s[i + n] - s[i + k + n];
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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) {
            return ans;
        }
        vector<int> s(n << 1 | 1);
        for (int i = 0; i < n << 1; ++i) {
            s[i + 1] = s[i] + code[i % n];
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                ans[i] = s[i + k + 1] - s[i + 1];
            } else {
                ans[i] = s[i + n] - s[i + k + n];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func decrypt(code []int, k int) []int {
	n := len(code)
	ans := make([]int, n)
	if k == 0 {
		return ans
	}
	s := make([]int, n<<1|1)
	for i := 0; i < n<<1; i++ {
		s[i+1] = s[i] + code[i%n]
	}
	for i := range code {
		if k > 0 {
			ans[i] = s[i+k+1] - s[i+1]
		} else {
			ans[i] = s[i+n] - s[i+k+n]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function decrypt(code: number[], k: number): number[] {
    const n: number = code.length;
    const ans: number[] = Array(n).fill(0);

    if (k === 0) {
        return ans;
    }

    const s: number[] = Array((n << 1) | 1).fill(0);
    for (let i = 0; i < n << 1; ++i) {
        s[i + 1] = s[i] + code[i % n];
    }

    for (let i = 0; i < n; ++i) {
        if (k > 0) {
            ans[i] = s[i + k + 1] - s[i + 1];
        } else {
            ans[i] = s[i + n] - s[i + k + n];
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

# [1653. 使字符串平衡的最少删除次数](https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced){#1653}

{{< tabs "1653" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        lb, ra = 0, s.count('a')
        ans = len(s)
        for c in s:
            ra -= c == 'a'
            ans = min(ans, lb + ra)
            lb += c == 'b'
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDeletions(String s) {
        int lb = 0, ra = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == 'a') {
                ++ra;
            }
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ra -= (s.charAt(i) == 'a' ? 1 : 0);
            ans = Math.min(ans, lb + ra);
            lb += (s.charAt(i) == 'b' ? 1 : 0);
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
    int minimumDeletions(string s) {
        int lb = 0, ra = count(s.begin(), s.end(), 'a');
        int ans = ra;
        for (char& c : s) {
            ra -= c == 'a';
            ans = min(ans, lb + ra);
            lb += c == 'b';
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDeletions(s string) int {
	lb, ra := 0, strings.Count(s, "a")
	ans := ra
	for _, c := range s {
		if c == 'a' {
			ra--
		}
		if t := lb + ra; ans > t {
			ans = t
		}
		if c == 'b' {
			lb++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDeletions(s: string): number {
    const stk: string[] = [];
    let res = 0;

    for (const ch of s) {
        if (stk.at(-1) === 'b' && ch === 'a') {
            stk.pop();
            res++;
        } else stk.push(ch);
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function (s) {
    const stk = [];
    let res = 0;

    for (const ch of s) {
        if (stk.at(-1) === 'b' && ch === 'a') {
            stk.pop();
            res++;
        } else stk.push(ch);
    }

    return res;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它仅包含字符&nbsp;<code>'a'</code> 和&nbsp;<code>'b'</code>​​​​ 。</p>

<p>你可以删除&nbsp;<code>s</code>&nbsp;中任意数目的字符，使得&nbsp;<code>s</code> <strong>平衡</strong>&nbsp;。当不存在下标对&nbsp;<code>(i,j)</code>&nbsp;满足&nbsp;<code>i &lt; j</code> ，且&nbsp;<code>s[i] = 'b'</code> 的同时&nbsp;<code>s[j]= 'a'</code> ，此时认为 <code>s</code> 是 <strong>平衡 </strong>的。</p>

<p>请你返回使 <code>s</code>&nbsp;<strong>平衡</strong>&nbsp;的 <strong>最少</strong>&nbsp;删除次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aababbab"
<b>输出：</b>2
<b>解释：</b>你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aa<strong>b</strong>abb<strong>a</strong>b" -&gt; "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aab<strong>a</strong>bb<strong>a</strong>b" -&gt; "aabbbb"）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "bbaaaaabb"
<b>输出：</b>2
<b>解释：</b>唯一的最优解是删除最前面两个字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'a'</code> 要么是&nbsp;<code>'b'</code>​<strong>&nbsp;</strong>。​</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示前 $i$ 个字符中，删除最少的字符数，使得字符串平衡。初始时 $f[0]=0$。答案为 $f[n]$。

我们遍历字符串 $s$，维护变量 $b$，表示当前遍历到的位置之前的字符中，字符 $b$ 的个数。

-   如果当前字符为 `'b'`，此时不影响前 $i$ 个字符的平衡性，因此 $f[i]=f[i-1]$，然后我们更新 $b \leftarrow b+1$。
-   如果当前字符为 `'a'`，此时我们可以选择删除当前字符，那么有 $f[i]=f[i-1]+1$；也可以选择删除之前的字符 $b$，那么有 $f[i]=b$。因此我们取两者的最小值，即 $f[i]=\min(f[i-1]+1,b)$。

综上，我们可以得到状态转移方程：

$$
f[i]=\begin{cases}
f[i-1], & s[i-1]='b'\\
\min(f[i-1]+1,b), & s[i-1]='a'
\end{cases}
$$

最终答案为 $f[n]$。

我们注意到，状态转移方程中只与前一个状态以及变量 $b$ 有关，因此我们可以仅用一个答案变量 $ans$ 维护当前的 $f[i]$，并不需要开辟数组 $f$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        f = [0] * (n + 1)
        b = 0
        for i, c in enumerate(s, 1):
            if c == 'b':
                f[i] = f[i - 1]
                b += 1
            else:
                f[i] = min(f[i - 1] + 1, b)
        return f[n]
```

#### Java

```java
class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) == 'b') {
                f[i] = f[i - 1];
                ++b;
            } else {
                f[i] = Math.min(f[i - 1] + 1, b);
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
    int minimumDeletions(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b') {
                f[i] = f[i - 1];
                ++b;
            } else {
                f[i] = min(f[i - 1] + 1, b);
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func minimumDeletions(s string) int {
	n := len(s)
	f := make([]int, n+1)
	b := 0
	for i, c := range s {
		i++
		if c == 'b' {
			f[i] = f[i-1]
			b++
		} else {
			f[i] = min(f[i-1]+1, b)
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function minimumDeletions(s: string): number {
    const n = s.length;
    const f = new Array(n + 1).fill(0);
    let b = 0;
    for (let i = 1; i <= n; ++i) {
        if (s[i - 1] === 'b') {
            f[i] = f[i - 1];
            ++b;
        } else {
            f[i] = Math.min(f[i - 1] + 1, b);
        }
    }
    return f[n];
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function (s) {
    const n = s.length;
    const f = new Array(n + 1).fill(0);
    let b = 0;
    for (let i = 1; i <= n; ++i) {
        if (s[i - 1] === 'b') {
            f[i] = f[i - 1];
            ++b;
        } else {
            f[i] = Math.min(f[i - 1] + 1, b);
        }
    }
    return f[n];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举 + 前缀和

我们可以枚举字符串 $s$ 中的每一个位置 $i$，将字符串 $s$ 分成两部分，分别为 $s[0,..,i-1]$ 和 $s[i+1,..n-1]$，要使得字符串平衡，我们在当前位置 $i$ 需要删除的字符数为 $s[0,..,i-1]$ 中字符 $b$ 的个数加上 $s[i+1,..n-1]$ 中字符 $a$ 的个数。

因此，我们维护两个变量 $lb$ 和 $ra$ 分别表示 $s[0,..,i-1]$ 中字符 $b$ 的个数以及 $s[i+1,..n-1]$ 中字符 $a$ 的个数，那么我们需要删除的字符数为 $lb+ra$。枚举过程中，更新变量 $lb$ 和 $ra$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        ans = b = 0
        for c in s:
            if c == 'b':
                b += 1
            else:
                ans = min(ans + 1, b)
        return ans
```

#### Java

```java
class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int ans = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == 'b') {
                ++b;
            } else {
                ans = Math.min(ans + 1, b);
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
    int minimumDeletions(string s) {
        int ans = 0, b = 0;
        for (char& c : s) {
            if (c == 'b') {
                ++b;
            } else {
                ans = min(ans + 1, b);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDeletions(s string) int {
	ans, b := 0, 0
	for _, c := range s {
		if c == 'b' {
			b++
		} else {
			ans = min(ans+1, b)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDeletions(s: string): number {
    let [ans, b] = [0, 0];

    for (const ch of s) {
        if (ch === 'b') {
            ++b;
        } else {
            ans = Math.min(ans + 1, b);
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function (s) {
    let [ans, b] = [0, 0];

    for (const ch of s) {
        if (ch === 'b') {
            ++b;
        } else {
            ans = Math.min(ans + 1, b);
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        lb, ra = 0, s.count('a')
        ans = len(s)
        for c in s:
            ra -= c == 'a'
            ans = min(ans, lb + ra)
            lb += c == 'b'
        return ans
```

#### Java

```java
class Solution {
    public int minimumDeletions(String s) {
        int lb = 0, ra = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == 'a') {
                ++ra;
            }
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ra -= (s.charAt(i) == 'a' ? 1 : 0);
            ans = Math.min(ans, lb + ra);
            lb += (s.charAt(i) == 'b' ? 1 : 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int lb = 0, ra = count(s.begin(), s.end(), 'a');
        int ans = ra;
        for (char& c : s) {
            ra -= c == 'a';
            ans = min(ans, lb + ra);
            lb += c == 'b';
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDeletions(s string) int {
	lb, ra := 0, strings.Count(s, "a")
	ans := ra
	for _, c := range s {
		if c == 'a' {
			ra--
		}
		if t := lb + ra; ans > t {
			ans = t
		}
		if c == 'b' {
			lb++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDeletions(s: string): number {
    let ra = [...s].reduce((acc, x) => (x === 'a' ? acc + 1 : acc), 0);
    let lb = 0;

    let ans = s.length;
    for (const ch of s) {
        if (ch === 'a') ra--;
        ans = Math.min(ans, lb + ra);
        if (ch === 'b') lb++;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function (s) {
    let ra = [...s].reduce((acc, x) => (x === 'a' ? acc + 1 : acc), 0);
    let lb = 0;

    let ans = s.length;
    for (const ch of s) {
        if (ch === 'a') ra--;
        ans = Math.min(ans, lb + ra);
        if (ch === 'b') lb++;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 4: Stack

<!-- tabs:start -->

#### TypeScript

```ts
function minimumDeletions(s: string): number {
    const stk: string[] = [];
    let res = 0;

    for (const ch of s) {
        if (stk.at(-1) === 'b' && ch === 'a') {
            stk.pop();
            res++;
        } else stk.push(ch);
    }

    return res;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function (s) {
    const stk = [];
    let res = 0;

    for (const ch of s) {
        if (stk.at(-1) === 'b' && ch === 'a') {
            stk.pop();
            res++;
        } else stk.push(ch);
    }

    return res;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1654. 到家的最少跳跃次数](https://leetcode.cn/problems/minimum-jumps-to-reach-home){#1654}

{{< tabs "1654" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        s = set(forbidden)
        q = deque([(0, 1)])
        vis = {(0, 1)}
        ans = 0
        while q:
            for _ in range(len(q)):
                i, k = q.popleft()
                if i == x:
                    return ans
                nxt = [(i + a, 1)]
                if k & 1:
                    nxt.append((i - b, 0))
                for j, k in nxt:
                    if 0 <= j < 6000 and j not in s and (j, k) not in vis:
                        q.append((j, k))
                        vis.add((j, k))
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumJumps(int[] forbidden, int a, int b, int x) {
        Set<Integer> s = new HashSet<>();
        for (int v : forbidden) {
            s.add(v);
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 1});
        final int n = 6000;
        boolean[][] vis = new boolean[n][2];
        vis[0][1] = true;
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                int i = p[0], k = p[1];
                if (i == x) {
                    return ans;
                }
                List<int[]> nxt = new ArrayList<>();
                nxt.add(new int[] {i + a, 1});
                if ((k & 1) == 1) {
                    nxt.add(new int[] {i - b, 0});
                }
                for (var e : nxt) {
                    int j = e[0];
                    k = e[1];
                    if (j >= 0 && j < n && !s.contains(j) && !vis[j][k]) {
                        q.offer(new int[] {j, k});
                        vis[j][k] = true;
                    }
                }
            }
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
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s(forbidden.begin(), forbidden.end());
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        const int n = 6000;
        bool vis[n][2];
        memset(vis, false, sizeof(vis));
        vis[0][1] = true;
        for (int ans = 0; q.size(); ++ans) {
            for (int t = q.size(); t; --t) {
                auto [i, k] = q.front();
                q.pop();
                if (i == x) {
                    return ans;
                }
                vector<pair<int, int>> nxts = {{i + a, 1}};
                if (k & 1) {
                    nxts.emplace_back(i - b, 0);
                }
                for (auto [j, l] : nxts) {
                    if (j >= 0 && j < n && !s.count(j) && !vis[j][l]) {
                        vis[j][l] = true;
                        q.emplace(j, l);
                    }
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
func minimumJumps(forbidden []int, a int, b int, x int) (ans int) {
	s := map[int]bool{}
	for _, v := range forbidden {
		s[v] = true
	}
	q := [][2]int{[2]int{0, 1}}
	const n = 6000
	vis := make([][2]bool, n)
	vis[0][1] = true
	for ; len(q) > 0; ans++ {
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			i, k := p[0], p[1]
			if i == x {
				return
			}
			nxt := [][2]int{[2]int{i + a, 1}}
			if k&1 == 1 {
				nxt = append(nxt, [2]int{i - b, 0})
			}
			for _, e := range nxt {
				j, l := e[0], e[1]
				if j >= 0 && j < n && !s[j] && !vis[j][l] {
					q = append(q, [2]int{j, l})
					vis[j][l] = true
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumJumps(forbidden: number[], a: number, b: number, x: number): number {
    const s: Set<number> = new Set(forbidden);
    const q: [number, number][] = [[0, 1]];
    const n = 6000;
    const vis: boolean[][] = Array.from({ length: n }, () => [false, false]);
    vis[0][1] = true;
    for (let ans = 0; q.length; ++ans) {
        for (let t = q.length; t; --t) {
            const [i, k] = q.shift()!;
            if (i === x) {
                return ans;
            }
            const nxt: [number, number][] = [[i + a, 1]];
            if (k & 1) {
                nxt.push([i - b, 0]);
            }
            for (const [j, k] of nxt) {
                if (j >= 0 && j < n && !s.has(j) && !vis[j][k]) {
                    vis[j][k] = true;
                    q.push([j, k]);
                }
            }
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一只跳蚤的家在数轴上的位置 <code>x</code> 处。请你帮助它从位置 <code>0</code> 出发，到达它的家。</p>

<p>跳蚤跳跃的规则如下：</p>

<ul>
	<li>它可以 <strong>往前</strong> 跳恰好 <code>a</code> 个位置（即往右跳）。</li>
	<li>它可以 <strong>往后</strong> 跳恰好 <code>b</code> 个位置（即往左跳）。</li>
	<li>它不能 <strong>连续</strong> 往后跳 <code>2</code> 次。</li>
	<li>它不能跳到任何 <code>forbidden</code> 数组中的位置。</li>
</ul>

<p>跳蚤可以往前跳 <strong>超过</strong> 它的家的位置，但是它 <strong>不能跳到负整数</strong> 的位置。</p>

<p>给你一个整数数组 <code>forbidden</code> ，其中 <code>forbidden[i]</code> 是跳蚤不能跳到的位置，同时给你整数 <code>a</code>， <code>b</code> 和 <code>x</code> ，请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 <code>x</code> 的可行方案，请你返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
<b>输出：</b>3
<b>解释：</b>往前跳 3 次（0 -> 3 -> 6 -> 9），跳蚤就到家了。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
<b>输出：</b>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
<b>输出：</b>2
<b>解释：</b>往前跳一次（0 -> 16），然后往回跳一次（16 -> 7），跳蚤就到家了。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= forbidden.length <= 1000</code></li>
	<li><code>1 <= a, b, forbidden[i] <= 2000</code></li>
	<li><code>0 <= x <= 2000</code></li>
	<li><code>forbidden</code> 中所有位置互不相同。</li>
	<li>位置 <code>x</code> 不在 <code>forbidden</code> 中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以将跳蚤的位置和跳跃方向作为状态，使用 BFS 搜索最短路径。本题比较关键的地方在于确定右边界，即跳蚤最远能跳到哪里。

如果 $a \geq b$，即往前跳的距离大于往后跳的距离，那么如果跳蚤在位置大于 $x+b$ 的地方，它就不能再往前跳了，因为跳蚤不能连续往后跳两次，如果继续往前跳，那么永远无法跳到 $x$ 的位置。因此，如果 $a \geq b$，那么右边界可以是 $x+b$。

如果 $a \lt b$，即往前跳的距离小于往后跳的距离，那么如果跳蚤所在的位置减去 $b$ 超过 $2000$，此时选择往后跳，否则往前跳。因此，如果 $a \lt b$，那么右边界不超过 $6000$。

综上，我们可以将右边界设置为 $6000$。

接下来，我们使用 BFS 搜索最短路径。我们使用一个队列，初始时将跳蚤的位置和跳跃方向作为状态加入队列。每次从队列中取出一个状态，如果该状态的位置等于 $x$，那么我们就找到了一条从初始状态到达目标状态的路径，返回当前的步数即可。否则，我们将当前状态的下一个状态加入队列，下一个状态有两种情况：

-   往前跳，跳跃方向为 $1$；
-   当前跳跃方向为 $1$ 时，往后跳，跳跃方向为 $0$。

注意，我们需要判断下一个状态是否合法，即下一个状态的位置不超过右边界，且不在禁止的位置中，且未被访问过。

如果队列为空，说明无法到达目标位置，返回 $-1$。

时间复杂度 $O(M)$，空间复杂度 $O(M)$。其中 $M$ 是右边界，本题中 $M \leq 6000$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        s = set(forbidden)
        q = deque([(0, 1)])
        vis = {(0, 1)}
        ans = 0
        while q:
            for _ in range(len(q)):
                i, k = q.popleft()
                if i == x:
                    return ans
                nxt = [(i + a, 1)]
                if k & 1:
                    nxt.append((i - b, 0))
                for j, k in nxt:
                    if 0 <= j < 6000 and j not in s and (j, k) not in vis:
                        q.append((j, k))
                        vis.add((j, k))
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int minimumJumps(int[] forbidden, int a, int b, int x) {
        Set<Integer> s = new HashSet<>();
        for (int v : forbidden) {
            s.add(v);
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 1});
        final int n = 6000;
        boolean[][] vis = new boolean[n][2];
        vis[0][1] = true;
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                int i = p[0], k = p[1];
                if (i == x) {
                    return ans;
                }
                List<int[]> nxt = new ArrayList<>();
                nxt.add(new int[] {i + a, 1});
                if ((k & 1) == 1) {
                    nxt.add(new int[] {i - b, 0});
                }
                for (var e : nxt) {
                    int j = e[0];
                    k = e[1];
                    if (j >= 0 && j < n && !s.contains(j) && !vis[j][k]) {
                        q.offer(new int[] {j, k});
                        vis[j][k] = true;
                    }
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s(forbidden.begin(), forbidden.end());
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        const int n = 6000;
        bool vis[n][2];
        memset(vis, false, sizeof(vis));
        vis[0][1] = true;
        for (int ans = 0; q.size(); ++ans) {
            for (int t = q.size(); t; --t) {
                auto [i, k] = q.front();
                q.pop();
                if (i == x) {
                    return ans;
                }
                vector<pair<int, int>> nxts = {{i + a, 1}};
                if (k & 1) {
                    nxts.emplace_back(i - b, 0);
                }
                for (auto [j, l] : nxts) {
                    if (j >= 0 && j < n && !s.count(j) && !vis[j][l]) {
                        vis[j][l] = true;
                        q.emplace(j, l);
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumJumps(forbidden []int, a int, b int, x int) (ans int) {
	s := map[int]bool{}
	for _, v := range forbidden {
		s[v] = true
	}
	q := [][2]int{[2]int{0, 1}}
	const n = 6000
	vis := make([][2]bool, n)
	vis[0][1] = true
	for ; len(q) > 0; ans++ {
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			i, k := p[0], p[1]
			if i == x {
				return
			}
			nxt := [][2]int{[2]int{i + a, 1}}
			if k&1 == 1 {
				nxt = append(nxt, [2]int{i - b, 0})
			}
			for _, e := range nxt {
				j, l := e[0], e[1]
				if j >= 0 && j < n && !s[j] && !vis[j][l] {
					q = append(q, [2]int{j, l})
					vis[j][l] = true
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumJumps(forbidden: number[], a: number, b: number, x: number): number {
    const s: Set<number> = new Set(forbidden);
    const q: [number, number][] = [[0, 1]];
    const n = 6000;
    const vis: boolean[][] = Array.from({ length: n }, () => [false, false]);
    vis[0][1] = true;
    for (let ans = 0; q.length; ++ans) {
        for (let t = q.length; t; --t) {
            const [i, k] = q.shift()!;
            if (i === x) {
                return ans;
            }
            const nxt: [number, number][] = [[i + a, 1]];
            if (k & 1) {
                nxt.push([i - b, 0]);
            }
            for (const [j, k] of nxt) {
                if (j >= 0 && j < n && !s.has(j) && !vis[j][k]) {
                    vis[j][k] = true;
                    q.push([j, k]);
                }
            }
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1655. 分配重复整数](https://leetcode.cn/problems/distribute-repeating-integers){#1655}

{{< tabs "1655" >}}

{{% tab "python" %}}
```python
class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        m = len(quantity)
        s = [0] * (1 << m)
        for i in range(1, 1 << m):
            for j in range(m):
                if i >> j & 1:
                    s[i] = s[i ^ (1 << j)] + quantity[j]
                    break
        cnt = Counter(nums)
        arr = list(cnt.values())
        n = len(arr)
        f = [[False] * (1 << m) for _ in range(n)]
        for i in range(n):
            f[i][0] = True
        for i, x in enumerate(arr):
            for j in range(1, 1 << m):
                if i and f[i - 1][j]:
                    f[i][j] = True
                    continue
                k = j
                while k:
                    ok1 = j == k if i == 0 else f[i - 1][j ^ k]
                    ok2 = s[k] <= x
                    if ok1 and ok2:
                        f[i][j] = True
                        break
                    k = (k - 1) & j
        return f[-1][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canDistribute(int[] nums, int[] quantity) {
        int m = quantity.length;
        int[] s = new int[1 << m];
        for (int i = 1; i < 1 << m; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i >> j & 1) != 0) {
                    s[i] = s[i ^ (1 << j)] + quantity[j];
                    break;
                }
            }
        }
        Map<Integer, Integer> cnt = new HashMap<>(50);
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int n = cnt.size();
        int[] arr = new int[n];
        int i = 0;
        for (int x : cnt.values()) {
            arr[i++] = x;
        }
        boolean[][] f = new boolean[n][1 << m];
        for (i = 0; i < n; ++i) {
            f[i][0] = true;
        }
        for (i = 0; i < n; ++i) {
            for (int j = 1; j < 1 << m; ++j) {
                if (i > 0 && f[i - 1][j]) {
                    f[i][j] = true;
                    continue;
                }
                for (int k = j; k > 0; k = (k - 1) & j) {
                    boolean ok1 = i == 0 ? j == k : f[i - 1][j ^ k];
                    boolean ok2 = s[k] <= arr[i];
                    if (ok1 && ok2) {
                        f[i][j] = true;
                        break;
                    }
                }
            }
        }
        return f[n - 1][(1 << m) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = quantity.size();
        int s[1 << m];
        memset(s, 0, sizeof(s));
        for (int i = 1; i < 1 << m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    s[i] = s[i ^ (1 << j)] + quantity[j];
                    break;
                }
            }
        }
        unordered_map<int, int> cnt;
        for (int& x : nums) {
            ++cnt[x];
        }
        int n = cnt.size();
        vector<int> arr;
        for (auto& [_, x] : cnt) {
            arr.push_back(x);
        }
        bool f[n][1 << m];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][0] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 1 << m; ++j) {
                if (i && f[i - 1][j]) {
                    f[i][j] = true;
                    continue;
                }
                for (int k = j; k; k = (k - 1) & j) {
                    bool ok1 = i == 0 ? j == k : f[i - 1][j ^ k];
                    bool ok2 = s[k] <= arr[i];
                    if (ok1 && ok2) {
                        f[i][j] = true;
                        break;
                    }
                }
            }
        }
        return f[n - 1][(1 << m) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canDistribute(nums []int, quantity []int) bool {
	m := len(quantity)
	s := make([]int, 1<<m)
	for i := 1; i < 1<<m; i++ {
		for j := 0; j < m; j++ {
			if i>>j&1 == 1 {
				s[i] = s[i^(1<<j)] + quantity[j]
				break
			}
		}
	}
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	n := len(cnt)
	arr := make([]int, 0, n)
	for _, x := range cnt {
		arr = append(arr, x)
	}
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, 1<<m)
		f[i][0] = true
	}
	for i := 0; i < n; i++ {
		for j := 0; j < 1<<m; j++ {
			if i > 0 && f[i-1][j] {
				f[i][j] = true
				continue
			}
			for k := j; k > 0; k = (k - 1) & j {
				ok1 := (i == 0 && j == k) || (i > 0 && f[i-1][j-k])
				ok2 := s[k] <= arr[i]
				if ok1 && ok2 {
					f[i][j] = true
					break
				}
			}
		}
	}
	return f[n-1][(1<<m)-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canDistribute(nums: number[], quantity: number[]): boolean {
    const m = quantity.length;
    const s: number[] = new Array(1 << m).fill(0);
    for (let i = 1; i < 1 << m; ++i) {
        for (let j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                s[i] = s[i ^ (1 << j)] + quantity[j];
                break;
            }
        }
    }
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    const n = cnt.size;
    const arr: number[] = [];
    for (const [_, v] of cnt) {
        arr.push(v);
    }
    const f: boolean[][] = new Array(n).fill(false).map(() => new Array(1 << m).fill(false));
    for (let i = 0; i < n; ++i) {
        f[i][0] = true;
    }
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < 1 << m; ++j) {
            if (i > 0 && f[i - 1][j]) {
                f[i][j] = true;
                continue;
            }
            for (let k = j; k > 0; k = (k - 1) & j) {
                const ok1: boolean = (i == 0 && j == k) || (i > 0 && f[i - 1][j ^ k]);
                const ok2: boolean = s[k] <= arr[i];
                if (ok1 && ok2) {
                    f[i][j] = true;
                    break;
                }
            }
        }
    }
    return f[n - 1][(1 << m) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，这个数组中至多有&nbsp;<code>50</code>&nbsp;个不同的值。同时你有 <code>m</code>&nbsp;个顾客的订单 <code>quantity</code>&nbsp;，其中，整数&nbsp;<code>quantity[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;位顾客订单的数目。请你判断是否能将 <code>nums</code>&nbsp;中的整数分配给这些顾客，且满足：</p>

<ul>
	<li>第&nbsp;<code>i</code>&nbsp;位顾客 <strong>恰好&nbsp;</strong>有&nbsp;<code>quantity[i]</code>&nbsp;个整数。</li>
	<li>第&nbsp;<code>i</code>&nbsp;位顾客拿到的整数都是 <strong>相同的</strong>&nbsp;。</li>
	<li>每位顾客都满足上述两个要求。</li>
</ul>

<p>如果你可以分配 <code>nums</code>&nbsp;中的整数满足上面的要求，那么请返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4], quantity = [2]
<b>输出：</b>false
<strong>解释：</strong>第 0 位顾客没办法得到两个相同的整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,3], quantity = [2]
<b>输出：</b>true
<b>解释：</b>第 0 位顾客得到 [3,3] 。整数 [1,2] 都没有被使用。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,2,2], quantity = [2,2]
<b>输出：</b>true
<b>解释：</b>第 0 位顾客得到 [1,1] ，第 1 位顾客得到 [2,2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>m == quantity.length</code></li>
	<li><code>1 &lt;= m &lt;= 10</code></li>
	<li><code>1 &lt;= quantity[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code>&nbsp;中至多有&nbsp;<code>50</code>&nbsp;个不同的数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划 + 子集枚举

我们先统计数组 $nums$ 中每个数字出现的次数，记录在哈希表 $cnt$ 中，然后将哈希表中的值存入数组 $arr$ 中，我们记数组 $arr$ 的长度为 $n$。

注意到数组 $quantity$ 的长度不超过 $10$，因此，我们可以用一个二进制数表示 $quantity$ 中的一个子集，即数字 $j$ 表示 $quantity$ 中的一个子集，其中 $j$ 的二进制表示中的第 $i$ 位为 $1$ 表示 $quantity$ 中的第 $i$ 个数字被选中，为 $0$ 表示第 $i$ 个数字未被选中。

我们可以预处理出数组 $s$，其中 $s[j]$ 表示 $quantity$ 中子集 $j$ 中所有数字的和。

接下来，我们定义 $f[i][j]$ 表示数组 $arr[0,..i-1]$ 中的数字能否成功分配给 $quantity$ 中的子集 $j$，其中 $i$ 的取值范围为 $[0,..n-1]$，而 $j$ 的取值范围为 $[0,2^m-1]$，其中 $m$ 为 $quantity$ 的长度。

考虑 $f[i][j]$，如果子集 $j$ 中存在一个子集 $k$，使得 $s[k] \leq arr[i]$，并且 $f[i-1][j \oplus k]$ 为真，那么 $f[i][j]$ 为真，否则 $f[i][j]$ 为假。

答案为 $f[n-1][2^m-1]$。

时间复杂度 $O(n \times 3^m)$，空间复杂度 $O(n \times 2^m)$。其中 $n$ 是数组 $nums$ 中不同整数的个数；而 $m$ 是数组 $quantity$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        m = len(quantity)
        s = [0] * (1 << m)
        for i in range(1, 1 << m):
            for j in range(m):
                if i >> j & 1:
                    s[i] = s[i ^ (1 << j)] + quantity[j]
                    break
        cnt = Counter(nums)
        arr = list(cnt.values())
        n = len(arr)
        f = [[False] * (1 << m) for _ in range(n)]
        for i in range(n):
            f[i][0] = True
        for i, x in enumerate(arr):
            for j in range(1, 1 << m):
                if i and f[i - 1][j]:
                    f[i][j] = True
                    continue
                k = j
                while k:
                    ok1 = j == k if i == 0 else f[i - 1][j ^ k]
                    ok2 = s[k] <= x
                    if ok1 and ok2:
                        f[i][j] = True
                        break
                    k = (k - 1) & j
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public boolean canDistribute(int[] nums, int[] quantity) {
        int m = quantity.length;
        int[] s = new int[1 << m];
        for (int i = 1; i < 1 << m; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i >> j & 1) != 0) {
                    s[i] = s[i ^ (1 << j)] + quantity[j];
                    break;
                }
            }
        }
        Map<Integer, Integer> cnt = new HashMap<>(50);
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int n = cnt.size();
        int[] arr = new int[n];
        int i = 0;
        for (int x : cnt.values()) {
            arr[i++] = x;
        }
        boolean[][] f = new boolean[n][1 << m];
        for (i = 0; i < n; ++i) {
            f[i][0] = true;
        }
        for (i = 0; i < n; ++i) {
            for (int j = 1; j < 1 << m; ++j) {
                if (i > 0 && f[i - 1][j]) {
                    f[i][j] = true;
                    continue;
                }
                for (int k = j; k > 0; k = (k - 1) & j) {
                    boolean ok1 = i == 0 ? j == k : f[i - 1][j ^ k];
                    boolean ok2 = s[k] <= arr[i];
                    if (ok1 && ok2) {
                        f[i][j] = true;
                        break;
                    }
                }
            }
        }
        return f[n - 1][(1 << m) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = quantity.size();
        int s[1 << m];
        memset(s, 0, sizeof(s));
        for (int i = 1; i < 1 << m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    s[i] = s[i ^ (1 << j)] + quantity[j];
                    break;
                }
            }
        }
        unordered_map<int, int> cnt;
        for (int& x : nums) {
            ++cnt[x];
        }
        int n = cnt.size();
        vector<int> arr;
        for (auto& [_, x] : cnt) {
            arr.push_back(x);
        }
        bool f[n][1 << m];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][0] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 1 << m; ++j) {
                if (i && f[i - 1][j]) {
                    f[i][j] = true;
                    continue;
                }
                for (int k = j; k; k = (k - 1) & j) {
                    bool ok1 = i == 0 ? j == k : f[i - 1][j ^ k];
                    bool ok2 = s[k] <= arr[i];
                    if (ok1 && ok2) {
                        f[i][j] = true;
                        break;
                    }
                }
            }
        }
        return f[n - 1][(1 << m) - 1];
    }
};
```

#### Go

```go
func canDistribute(nums []int, quantity []int) bool {
	m := len(quantity)
	s := make([]int, 1<<m)
	for i := 1; i < 1<<m; i++ {
		for j := 0; j < m; j++ {
			if i>>j&1 == 1 {
				s[i] = s[i^(1<<j)] + quantity[j]
				break
			}
		}
	}
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	n := len(cnt)
	arr := make([]int, 0, n)
	for _, x := range cnt {
		arr = append(arr, x)
	}
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, 1<<m)
		f[i][0] = true
	}
	for i := 0; i < n; i++ {
		for j := 0; j < 1<<m; j++ {
			if i > 0 && f[i-1][j] {
				f[i][j] = true
				continue
			}
			for k := j; k > 0; k = (k - 1) & j {
				ok1 := (i == 0 && j == k) || (i > 0 && f[i-1][j-k])
				ok2 := s[k] <= arr[i]
				if ok1 && ok2 {
					f[i][j] = true
					break
				}
			}
		}
	}
	return f[n-1][(1<<m)-1]
}
```

#### TypeScript

```ts
function canDistribute(nums: number[], quantity: number[]): boolean {
    const m = quantity.length;
    const s: number[] = new Array(1 << m).fill(0);
    for (let i = 1; i < 1 << m; ++i) {
        for (let j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                s[i] = s[i ^ (1 << j)] + quantity[j];
                break;
            }
        }
    }
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    const n = cnt.size;
    const arr: number[] = [];
    for (const [_, v] of cnt) {
        arr.push(v);
    }
    const f: boolean[][] = new Array(n).fill(false).map(() => new Array(1 << m).fill(false));
    for (let i = 0; i < n; ++i) {
        f[i][0] = true;
    }
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < 1 << m; ++j) {
            if (i > 0 && f[i - 1][j]) {
                f[i][j] = true;
                continue;
            }
            for (let k = j; k > 0; k = (k - 1) & j) {
                const ok1: boolean = (i == 0 && j == k) || (i > 0 && f[i - 1][j ^ k]);
                const ok2: boolean = s[k] <= arr[i];
                if (ok1 && ok2) {
                    f[i][j] = true;
                    break;
                }
            }
        }
    }
    return f[n - 1][(1 << m) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1656. 设计有序流](https://leetcode.cn/problems/design-an-ordered-stream){#1656}

{{< tabs "1656" >}}

{{% tab "python" %}}
```python
class OrderedStream:

    def __init__(self, n: int):
        self.ptr = 1
        self.data = [None] * (n + 1)

    def insert(self, idKey: int, value: str) -> List[str]:
        self.data[idKey] = value
        ans = []
        while self.ptr < len(self.data) and self.data[self.ptr]:
            ans.append(self.data[self.ptr])
            self.ptr += 1
        return ans


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class OrderedStream {
    private int ptr = 1;
    private String[] data;

    public OrderedStream(int n) {
        data = new String[n + 1];
    }

    public List<String> insert(int idKey, String value) {
        data[idKey] = value;
        List<String> ans = new ArrayList<>();
        while (ptr < data.length && data[ptr] != null) {
            ans.add(data[ptr++]);
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
        data = vector<string>(n + 1);
    }

    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> ans;
        while (ptr < data.size() && !data[ptr].empty()) {
            ans.push_back(data[ptr++]);
        }
        return ans;
    }

private:
    int ptr;
    vector<string> data;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type OrderedStream struct {
	ptr  int
	data []string
}

func Constructor(n int) OrderedStream {
	return OrderedStream{
		ptr:  1,
		data: make([]string, n+1),
	}
}

func (this *OrderedStream) Insert(idKey int, value string) []string {
	this.data[idKey] = value
	var ans []string
	for this.ptr < len(this.data) && this.data[this.ptr] != "" {
		ans = append(ans, this.data[this.ptr])
		this.ptr++
	}
	return ans
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class OrderedStream {
    private ptr: number;
    private data: string[];

    constructor(n: number) {
        this.ptr = 1;
        this.data = Array(n + 1);
    }

    insert(idKey: number, value: string): string[] {
        this.data[idKey] = value;
        const ans: string[] = [];
        while (this.data[this.ptr]) {
            ans.push(this.data[this.ptr++]);
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * var obj = new OrderedStream(n)
 * var param_1 = obj.insert(idKey,value)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct OrderedStream {
    ptr: usize,
    data: Vec<Option<String>>,
}

impl OrderedStream {
    fn new(n: i32) -> Self {
        OrderedStream {
            ptr: 1,
            data: vec![None; (n + 1) as usize],
        }
    }

    fn insert(&mut self, id_key: i32, value: String) -> Vec<String> {
        self.data[id_key as usize] = Some(value);
        let mut ans = Vec::new();
        while self.ptr < self.data.len() && self.data[self.ptr].is_some() {
            ans.push(self.data[self.ptr].take().unwrap());
            self.ptr += 1;
        }
        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 个 <code>(id, value)</code> 对，其中 <code>id</code> 是 <code>1</code> 到 <code>n</code> 之间的一个整数，<code>value</code> 是一个字符串。不存在 <code>id</code> 相同的两个 <code>(id, value)</code> 对。</p>

<p>设计一个流，以 <strong>任意</strong> 顺序获取 <code>n</code> 个 <code>(id, value)</code> 对，并在多次调用时 <strong>按 <code>id</code> 递增的顺序</strong> 返回一些值。</p>

<p>实现 <code>OrderedStream</code> 类：</p>

<ul>
	<li><code>OrderedStream(int n)</code> 构造一个能接收 <code>n</code> 个值的流，并将当前指针 <code>ptr</code> 设为 <code>1</code> 。</li>
	<li><code>String[] insert(int id, String value)</code> 向流中存储新的 <code>(id, value)</code> 对。存储后：
	<ul>
		<li>如果流存储有 <code>id = ptr</code> 的 <code>(id, value)</code> 对，则找出从 <code>id = ptr</code> 开始的 <strong>最长 id 连续递增序列</strong> ，并 <strong>按顺序</strong> 返回与这些 id 关联的值的列表。然后，将 <code>ptr</code> 更新为最后那个  <code>id + 1</code> 。</li>
		<li>
		<p>否则，返回一个空列表。</p>
		</li>
	</ul>
	</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1656.Design%20an%20Ordered%20Stream/images/q1.gif" style="width: 682px; height: 240px;" /></strong></p>

<pre>
<strong>输入</strong>
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
<strong>输出</strong>
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

<strong>解释</strong>
OrderedStream os= new OrderedStream(5);
os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 1000</code></li>
	<li><code>1 <= id <= n</code></li>
	<li><code>value.length == 5</code></li>
	<li><code>value</code> 仅由小写字母组成</li>
	<li>每次调用 <code>insert</code> 都会使用一个唯一的 <code>id</code></li>
	<li>恰好调用 <code>n</code> 次 <code>insert</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组模拟

我们可以使用一个长度为 $n + 1$ 的数组 $\textit{data}$ 来模拟这个流，其中 $\textit{data}[i]$ 表示 $\textit{id} = i$ 的值。同时，我们使用一个指针 $\textit{ptr}$ 来表示当前的位置。初始时 $\textit{ptr} = 1$。

在插入一个新的 $(\textit{idKey}, \textit{value})$ 对时，我们将 $\textit{data}[\textit{idKey}]$ 更新为 $\textit{value}$。然后，我们从 $\textit{ptr}$ 开始，依次将 $\textit{data}[\textit{ptr}]$ 加入答案中，直到 $\textit{data}[\textit{ptr}]$ 为空。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数据流的长度。

<!-- tabs:start -->

#### Python3

```python
class OrderedStream:

    def __init__(self, n: int):
        self.ptr = 1
        self.data = [None] * (n + 1)

    def insert(self, idKey: int, value: str) -> List[str]:
        self.data[idKey] = value
        ans = []
        while self.ptr < len(self.data) and self.data[self.ptr]:
            ans.append(self.data[self.ptr])
            self.ptr += 1
        return ans


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
```

#### Java

```java
class OrderedStream {
    private int ptr = 1;
    private String[] data;

    public OrderedStream(int n) {
        data = new String[n + 1];
    }

    public List<String> insert(int idKey, String value) {
        data[idKey] = value;
        List<String> ans = new ArrayList<>();
        while (ptr < data.length && data[ptr] != null) {
            ans.add(data[ptr++]);
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */
```

#### C++

```cpp
class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
        data = vector<string>(n + 1);
    }

    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> ans;
        while (ptr < data.size() && !data[ptr].empty()) {
            ans.push_back(data[ptr++]);
        }
        return ans;
    }

private:
    int ptr;
    vector<string> data;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
```

#### Go

```go
type OrderedStream struct {
	ptr  int
	data []string
}

func Constructor(n int) OrderedStream {
	return OrderedStream{
		ptr:  1,
		data: make([]string, n+1),
	}
}

func (this *OrderedStream) Insert(idKey int, value string) []string {
	this.data[idKey] = value
	var ans []string
	for this.ptr < len(this.data) && this.data[this.ptr] != "" {
		ans = append(ans, this.data[this.ptr])
		this.ptr++
	}
	return ans
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */
```

#### TypeScript

```ts
class OrderedStream {
    private ptr: number;
    private data: string[];

    constructor(n: number) {
        this.ptr = 1;
        this.data = Array(n + 1);
    }

    insert(idKey: number, value: string): string[] {
        this.data[idKey] = value;
        const ans: string[] = [];
        while (this.data[this.ptr]) {
            ans.push(this.data[this.ptr++]);
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * var obj = new OrderedStream(n)
 * var param_1 = obj.insert(idKey,value)
 */
```

#### Rust

```rust
struct OrderedStream {
    ptr: usize,
    data: Vec<Option<String>>,
}

impl OrderedStream {
    fn new(n: i32) -> Self {
        OrderedStream {
            ptr: 1,
            data: vec![None; (n + 1) as usize],
        }
    }

    fn insert(&mut self, id_key: i32, value: String) -> Vec<String> {
        self.data[id_key as usize] = Some(value);
        let mut ans = Vec::new();
        while self.ptr < self.data.len() && self.data[self.ptr].is_some() {
            ans.push(self.data[self.ptr].take().unwrap());
            self.ptr += 1;
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1657. 确定两个字符串是否接近](https://leetcode.cn/problems/determine-if-two-strings-are-close){#1657}

{{< tabs "1657" >}}

{{% tab "python" %}}
```python
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        cnt1, cnt2 = Counter(word1), Counter(word2)
        return sorted(cnt1.values()) == sorted(cnt2.values()) and set(
            cnt1.keys()
        ) == set(cnt2.keys())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < word1.length(); ++i) {
            ++cnt1[word1.charAt(i) - 'a'];
        }
        for (int i = 0; i < word2.length(); ++i) {
            ++cnt2[word2.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] == 0) != (cnt2[i] == 0)) {
                return false;
            }
        }
        Arrays.sort(cnt1);
        Arrays.sort(cnt2);
        return Arrays.equals(cnt1, cnt2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int cnt1[26]{};
        int cnt2[26]{};
        for (char& c : word1) {
            ++cnt1[c - 'a'];
        }
        for (char& c : word2) {
            ++cnt2[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] == 0) != (cnt2[i] == 0)) {
                return false;
            }
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        return equal(cnt1, cnt1 + 26, cnt2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closeStrings(word1 string, word2 string) bool {
	cnt1 := make([]int, 26)
	cnt2 := make([]int, 26)
	for _, c := range word1 {
		cnt1[c-'a']++
	}
	for _, c := range word2 {
		cnt2[c-'a']++
	}
	if !slices.EqualFunc(cnt1, cnt2, func(v1, v2 int) bool { return (v1 == 0) == (v2 == 0) }) {
		return false
	}
	sort.Ints(cnt1)
	sort.Ints(cnt2)
	return slices.Equal(cnt1, cnt2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function closeStrings(word1: string, word2: string): boolean {
    const cnt1 = Array(26).fill(0);
    const cnt2 = Array(26).fill(0);
    for (const c of word1) {
        ++cnt1[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    for (const c of word2) {
        ++cnt2[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    for (let i = 0; i < 26; ++i) {
        if ((cnt1[i] === 0) !== (cnt2[i] === 0)) {
            return false;
        }
    }
    cnt1.sort((a, b) => a - b);
    cnt2.sort((a, b) => a - b);
    return cnt1.join('.') === cnt2.join('.');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        let mut cnt1 = vec![0; 26];
        let mut cnt2 = vec![0; 26];
        for c in word1.chars() {
            cnt1[((c as u8) - b'a') as usize] += 1;
        }
        for c in word2.chars() {
            cnt2[((c as u8) - b'a') as usize] += 1;
        }
        for i in 0..26 {
            if (cnt1[i] == 0) != (cnt2[i] == 0) {
                return false;
            }
        }
        cnt1.sort();
        cnt2.sort();
        cnt1 == cnt2
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 <strong>接近</strong> ：</p>

<ul>
	<li>操作 1：交换任意两个 <strong>现有</strong> 字符。

    <ul>
    	<li>例如，<code>a<u>b</u>cd<u>e</u> -&gt; a<u>e</u>cd<u>b</u></code></li>
    </ul>
    </li>
    <li>操作 2：将一个 <strong>现有</strong> 字符的每次出现转换为另一个 <strong>现有</strong> 字符，并对另一个字符执行相同的操作。
    <ul>
    	<li>例如，<code><u>aa</u>c<u>abb</u> -&gt; <u>bb</u>c<u>baa</u></code>（所有 <code>a</code> 转化为 <code>b</code> ，而所有的 <code>b</code> 转换为 <code>a</code> ）</li>
    </ul>
    </li>

</ul>

<p>你可以根据需要对任意一个字符串多次使用这两种操作。</p>

<p>给你两个字符串，<code>word1</code> 和 <code>word2</code> 。如果<em> </em><code>word1</code><em> </em>和<em> </em><code>word2</code><em> </em><strong>接近 </strong>，就返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abc", word2 = "bca"
<strong>输出：</strong>true
<strong>解释：</strong>2 次操作从 word1 获得 word2 。
执行操作 1："a<u>bc</u>" -&gt; "a<u>cb</u>"
执行操作 1："<u>a</u>c<u>b</u>" -&gt; "<u>b</u>c<u>a</u>"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "a", word2 = "aa"
<strong>输出：</strong>false
<strong>解释：</strong>不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word1 = "cabbba", word2 = "abbccc"
<strong>输出：</strong>true
<strong>解释：</strong>3 次操作从 word1 获得 word2 。
执行操作 1："ca<u>b</u>bb<u>a</u>" -&gt; "ca<u>a</u>bb<u>b</u>"
执行操作 2：<code>"</code><u>c</u>aa<u>bbb</u>" -&gt; "<u>b</u>aa<u>ccc</u>"
执行操作 2："<u>baa</u>ccc" -&gt; "<u>abb</u>ccc"
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word1</code> 和 <code>word2</code> 仅包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 排序

根据题目描述，两个字符串接近，需要同时满足以下两个条件：

1. 字符串 `word1` 和 `word2` 包含的字母种类必须相同；
1. 将字符串 `word1` 和 `word2` 的所有字符出现次数排序，得到的两个数组必须相同。

因此，我们可以先用数组或哈希表分别统计 `word1` 和 `word2` 中每种字母出现的次数，然后比较两者是否相同，不相同则提前返回 `false`。

否则，我们将对应的次数排序，然后依次比较对应位置的两个次数是否相同，不同则返回 `false`。

遍历结束，返回 `true`。

时间复杂度 $O(m + n + C \times \log C)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别为字符串 `word1` 和 `word2` 的长度，而 $C$ 是字母种类。本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        cnt1, cnt2 = Counter(word1), Counter(word2)
        return sorted(cnt1.values()) == sorted(cnt2.values()) and set(
            cnt1.keys()
        ) == set(cnt2.keys())
```

#### Java

```java
class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < word1.length(); ++i) {
            ++cnt1[word1.charAt(i) - 'a'];
        }
        for (int i = 0; i < word2.length(); ++i) {
            ++cnt2[word2.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] == 0) != (cnt2[i] == 0)) {
                return false;
            }
        }
        Arrays.sort(cnt1);
        Arrays.sort(cnt2);
        return Arrays.equals(cnt1, cnt2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int cnt1[26]{};
        int cnt2[26]{};
        for (char& c : word1) {
            ++cnt1[c - 'a'];
        }
        for (char& c : word2) {
            ++cnt2[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] == 0) != (cnt2[i] == 0)) {
                return false;
            }
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        return equal(cnt1, cnt1 + 26, cnt2);
    }
};
```

#### Go

```go
func closeStrings(word1 string, word2 string) bool {
	cnt1 := make([]int, 26)
	cnt2 := make([]int, 26)
	for _, c := range word1 {
		cnt1[c-'a']++
	}
	for _, c := range word2 {
		cnt2[c-'a']++
	}
	if !slices.EqualFunc(cnt1, cnt2, func(v1, v2 int) bool { return (v1 == 0) == (v2 == 0) }) {
		return false
	}
	sort.Ints(cnt1)
	sort.Ints(cnt2)
	return slices.Equal(cnt1, cnt2)
}
```

#### TypeScript

```ts
function closeStrings(word1: string, word2: string): boolean {
    const cnt1 = Array(26).fill(0);
    const cnt2 = Array(26).fill(0);
    for (const c of word1) {
        ++cnt1[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    for (const c of word2) {
        ++cnt2[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    for (let i = 0; i < 26; ++i) {
        if ((cnt1[i] === 0) !== (cnt2[i] === 0)) {
            return false;
        }
    }
    cnt1.sort((a, b) => a - b);
    cnt2.sort((a, b) => a - b);
    return cnt1.join('.') === cnt2.join('.');
}
```

#### Rust

```rust
impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        let mut cnt1 = vec![0; 26];
        let mut cnt2 = vec![0; 26];
        for c in word1.chars() {
            cnt1[((c as u8) - b'a') as usize] += 1;
        }
        for c in word2.chars() {
            cnt2[((c as u8) - b'a') as usize] += 1;
        }
        for i in 0..26 {
            if (cnt1[i] == 0) != (cnt2[i] == 0) {
                return false;
            }
        }
        cnt1.sort();
        cnt2.sort();
        cnt1 == cnt2
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1658. 将 x 减到 0 的最小操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero){#1658}

{{< tabs "1658" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        s = sum(nums) - x
        j = t = 0
        mx = -1
        for i, x in enumerate(nums):
            t += x
            while j <= i and t > s:
                t -= nums[j]
                j += 1
            if t == s:
                mx = max(mx, i - j + 1)
        return -1 if mx == -1 else len(nums) - mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums, int x) {
        int s = -x;
        for (int v : nums) {
            s += v;
        }
        int mx = -1, t = 0;
        int n = nums.length;
        for (int i = 0, j = 0; i < n; ++i) {
            t += nums[i];
            while (j <= i && t > s) {
                t -= nums[j++];
            }
            if (t == s) {
                mx = Math.max(mx, i - j + 1);
            }
        }
        return mx == -1 ? -1 : n - mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s = accumulate(nums.begin(), nums.end(), 0) - x;
        int mx = -1, t = 0;
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            t += nums[i];
            while (j <= i && t > s) {
                t -= nums[j++];
            }
            if (t == s) {
                mx = max(mx, i - j + 1);
            }
        }
        return mx == -1 ? -1 : n - mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, x int) int {
	s := -x
	for _, v := range nums {
		s += v
	}
	mx, t, j := -1, 0, 0
	for i, v := range nums {
		t += v
		for ; j <= i && t > s; j++ {
			t -= nums[j]
		}
		if t == s {
			mx = max(mx, i-j+1)
		}
	}
	if mx == -1 {
		return -1
	}
	return len(nums) - mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], x: number): number {
    const s = nums.reduce((acc, cur) => acc + cur, -x);
    let [mx, t] = [-1, 0];
    const n = nums.length;
    for (let i = 0, j = 0; i < n; ++i) {
        t += nums[i];
        while (t > s) {
            t -= nums[j++];
        }
        if (t === s) {
            mx = Math.max(mx, i - j + 1);
        }
    }
    return ~mx ? n - mx : -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let s: i32 = nums.iter().sum::<i32>() - x;
        let mut j: usize = 0;
        let mut t: i32 = 0;
        let mut mx: i32 = -1;
        for (i, &v) in nums.iter().enumerate() {
            t += v;
            while j <= i && t > s {
                t -= nums[j];
                j += 1;
            }
            if t == s {
                mx = mx.max((i - j + 1) as i32);
            }
        }
        if mx == -1 {
            -1
        } else {
            (nums.len() as i32) - mx
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>x</code> 。每一次操作时，你应当移除数组 <code>nums</code> 最左边或最右边的元素，然后从 <code>x</code> 中减去该元素的值。请注意，需要 <strong>修改</strong> 数组以供接下来的操作使用。</p>

<p>如果可以将 <code>x</code> <strong>恰好</strong> 减到 <code>0</code> ，返回<strong> 最小操作数 </strong>；否则，返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,4,2,3], x = 5
<strong>输出：</strong>2
<strong>解释：</strong>最佳解决方案是移除后两个元素，将 x 减到 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,6,7,8,9], x = 4
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,20,1,1,3], x = 10
<strong>输出：</strong>5
<strong>解释：</strong>最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
	<li><code>1 <= x <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

根据题目描述，我们需要移除数组 $nums$ 左右两端的元素，使得移除的元素和等于 $x$，且移除的元素个数最少。我们可以将问题转化为：找到数组 $nums$ 中最长的连续子数组，使得子数组的和 $s = \sum_{i=0}^{n} nums[i] - x$。这样，我们就可以将问题转化为求解数组 $nums$ 中和为 $s$ 的最长连续子数组的长度 $mx$，答案即为 $n - mx$。

我们初始化 $mx = -1$，然后使用哈希表 $vis$ 来存储前缀和，键为前缀和，值为前缀和对应的下标。

遍历数组 $nums$，对于当前元素 $nums[i]$，计算前缀和 $t$，如果 $t$ 不在哈希表中，则将 $t$ 加入哈希表；如果 $t - s$ 在哈希表中，则更新 $mx = \max(mx, i - vis[t - s])$。

最后，如果 $mx = -1$，则返回 $-1$，否则返回 $n - mx$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        s = sum(nums) - x
        vis = {0: -1}
        mx, t = -1, 0
        for i, v in enumerate(nums):
            t += v
            if t not in vis:
                vis[t] = i
            if t - s in vis:
                mx = max(mx, i - vis[t - s])
        return -1 if mx == -1 else len(nums) - mx
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int x) {
        int s = -x;
        for (int v : nums) {
            s += v;
        }
        Map<Integer, Integer> vis = new HashMap<>();
        vis.put(0, -1);
        int mx = -1, t = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            t += nums[i];
            vis.putIfAbsent(t, i);
            if (vis.containsKey(t - s)) {
                mx = Math.max(mx, i - vis.get(t - s));
            }
        }
        return mx == -1 ? -1 : n - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s = accumulate(nums.begin(), nums.end(), 0) - x;
        unordered_map<int, int> vis = {{0, -1}};
        int mx = -1, t = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            t += nums[i];
            if (!vis.contains(t)) {
                vis[t] = i;
            }
            if (vis.contains(t - s)) {
                mx = max(mx, i - vis[t - s]);
            }
        }
        return mx == -1 ? -1 : n - mx;
    }
};
```

#### Go

```go
func minOperations(nums []int, x int) int {
	s := -x
	for _, v := range nums {
		s += v
	}
	vis := map[int]int{0: -1}
	mx, t := -1, 0
	for i, v := range nums {
		t += v
		if _, ok := vis[t]; !ok {
			vis[t] = i
		}
		if j, ok := vis[t-s]; ok {
			mx = max(mx, i-j)
		}
	}
	if mx == -1 {
		return -1
	}
	return len(nums) - mx
}
```

#### TypeScript

```ts
function minOperations(nums: number[], x: number): number {
    const s = nums.reduce((acc, cur) => acc + cur, -x);
    const vis: Map<number, number> = new Map([[0, -1]]);
    let [mx, t] = [-1, 0];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        t += nums[i];
        if (!vis.has(t)) {
            vis.set(t, i);
        }
        if (vis.has(t - s)) {
            mx = Math.max(mx, i - vis.get(t - s)!);
        }
    }
    return ~mx ? n - mx : -1;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let s = nums.iter().sum::<i32>() - x;
        let mut vis: HashMap<i32, i32> = HashMap::new();
        vis.insert(0, -1);
        let mut mx = -1;
        let mut t = 0;
        for (i, v) in nums.iter().enumerate() {
            t += v;
            if !vis.contains_key(&t) {
                vis.insert(t, i as i32);
            }
            if let Some(&j) = vis.get(&(t - s)) {
                mx = mx.max((i as i32) - j);
            }
        }
        if mx == -1 {
            -1
        } else {
            (nums.len() as i32) - mx
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

基于方法一的分析，我们需要求解数组 $nums$ 中和为 $s$ 的最长连续子数组的长度 $mx$。由于数组 $nums$ 中的元素都是正整数，数组的前缀和只会单调递增，因此我们可以使用双指针来求解。

我们初始化指针 $j = 0$，前缀和 $t = 0$，最长连续子数组的长度 $mx = -1$。

遍历数组 $nums$，对于当前元素 $nums[i]$，计算前缀和 $t += nums[i]$，如果 $t > s$，则移动指针 $j$，直到 $t \leq s$。如果 $t = s$，则更新 $mx = \max(mx, i - j + 1)$。

最后，如果 $mx = -1$，则返回 $-1$，否则返回 $n - mx$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        s = sum(nums) - x
        j = t = 0
        mx = -1
        for i, x in enumerate(nums):
            t += x
            while j <= i and t > s:
                t -= nums[j]
                j += 1
            if t == s:
                mx = max(mx, i - j + 1)
        return -1 if mx == -1 else len(nums) - mx
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int x) {
        int s = -x;
        for (int v : nums) {
            s += v;
        }
        int mx = -1, t = 0;
        int n = nums.length;
        for (int i = 0, j = 0; i < n; ++i) {
            t += nums[i];
            while (j <= i && t > s) {
                t -= nums[j++];
            }
            if (t == s) {
                mx = Math.max(mx, i - j + 1);
            }
        }
        return mx == -1 ? -1 : n - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s = accumulate(nums.begin(), nums.end(), 0) - x;
        int mx = -1, t = 0;
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            t += nums[i];
            while (j <= i && t > s) {
                t -= nums[j++];
            }
            if (t == s) {
                mx = max(mx, i - j + 1);
            }
        }
        return mx == -1 ? -1 : n - mx;
    }
};
```

#### Go

```go
func minOperations(nums []int, x int) int {
	s := -x
	for _, v := range nums {
		s += v
	}
	mx, t, j := -1, 0, 0
	for i, v := range nums {
		t += v
		for ; j <= i && t > s; j++ {
			t -= nums[j]
		}
		if t == s {
			mx = max(mx, i-j+1)
		}
	}
	if mx == -1 {
		return -1
	}
	return len(nums) - mx
}
```

#### TypeScript

```ts
function minOperations(nums: number[], x: number): number {
    const s = nums.reduce((acc, cur) => acc + cur, -x);
    let [mx, t] = [-1, 0];
    const n = nums.length;
    for (let i = 0, j = 0; i < n; ++i) {
        t += nums[i];
        while (t > s) {
            t -= nums[j++];
        }
        if (t === s) {
            mx = Math.max(mx, i - j + 1);
        }
    }
    return ~mx ? n - mx : -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let s: i32 = nums.iter().sum::<i32>() - x;
        let mut j: usize = 0;
        let mut t: i32 = 0;
        let mut mx: i32 = -1;
        for (i, &v) in nums.iter().enumerate() {
            t += v;
            while j <= i && t > s {
                t -= nums[j];
                j += 1;
            }
            if t == s {
                mx = mx.max((i - j + 1) as i32);
            }
        }
        if mx == -1 {
            -1
        } else {
            (nums.len() as i32) - mx
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1659. 最大化网格幸福感](https://leetcode.cn/problems/maximize-grid-happiness){#1659}

{{< tabs "1659" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaxGridHappiness(
        self, m: int, n: int, introvertsCount: int, extrovertsCount: int
    ) -> int:
        @cache
        def dfs(pos: int, pre: int, ic: int, ec: int) -> int:
            if pos == m * n or (ic == 0 and ec == 0):
                return 0
            ans = 0
            up = pre // p
            left = 0 if pos % n == 0 else pre % 3
            for i in range(3):
                if (i == 1 and ic == 0) or (i == 2 and ec == 0):
                    continue
                cur = pre % p * 3 + i
                a = h[up][i] + h[left][i]
                b = dfs(pos + 1, cur, ic - (i == 1), ec - (i == 2))
                c = 0
                if i == 1:
                    c = 120
                elif i == 2:
                    c = 40
                ans = max(ans, a + b + c)
            return ans

        p = pow(3, n - 1)
        h = [[0, 0, 0], [0, -60, -10], [0, -10, 40]]
        return dfs(0, 0, introvertsCount, extrovertsCount)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int p;
    private final int[][] h = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
    private Integer[][][][] memo;

    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this.m = m;
        this.n = n;
        p = (int) Math.pow(3, n - 1);
        memo = new Integer[m * n][p * 3][introvertsCount + 1][extrovertsCount + 1];
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    private int dfs(int pos, int pre, int ic, int ec) {
        if (pos == m * n || (ic == 0 && ec == 0)) {
            return 0;
        }
        if (memo[pos][pre][ic][ec] != null) {
            return memo[pos][pre][ic][ec];
        }
        int ans = 0;
        int up = pre / p;
        int left = pos % n == 0 ? 0 : pre % 3;
        for (int i = 0; i < 3; ++i) {
            if (i == 1 && (ic == 0) || (i == 2 && ec == 0)) {
                continue;
            }
            int cur = pre % p * 3 + i;
            int a = h[up][i] + h[left][i];
            int b = dfs(pos + 1, cur, ic - (i == 1 ? 1 : 0), ec - (i == 2 ? 1 : 0));
            int c = i == 1 ? 120 : (i == 2 ? 40 : 0);
            ans = Math.max(ans, a + b + c);
        }
        return memo[pos][pre][ic][ec] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int h[3][3] = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
        int p = pow(3, n - 1);
        int memo[m * n][p * 3][introvertsCount + 1][extrovertsCount + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int, int)> dfs = [&](int pos, int pre, int ic, int ec) {
            if (pos == m * n || (ic == 0 && ec == 0)) {
                return 0;
            }
            if (memo[pos][pre][ic][ec] != -1) {
                return memo[pos][pre][ic][ec];
            }
            int ans = 0;
            int up = pre / p;
            int left = pos % n == 0 ? 0 : pre % 3;
            for (int i = 0; i < 3; ++i) {
                if ((i == 1 && ic == 0) || (i == 2 && ec == 0)) {
                    continue;
                }
                int cur = pre % p * 3 + i;
                int a = h[up][i] + h[left][i];
                int b = dfs(pos + 1, cur, ic - (i == 1), ec - (i == 2));
                int c = i == 1 ? 120 : (i == 2 ? 40 : 0);
                ans = max(ans, a + b + c);
            }
            return memo[pos][pre][ic][ec] = ans;
        };
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaxGridHappiness(m int, n int, introvertsCount int, extrovertsCount int) int {
	p := int(math.Pow(3, float64(n-1)))
	h := [3][3]int{{0, 0, 0}, {0, -60, -10}, {0, -10, 40}}
	memo := make([][][][]int, m*n)
	for i := range memo {
		memo[i] = make([][][]int, p*3)
		for j := range memo[i] {
			memo[i][j] = make([][]int, introvertsCount+1)
			for k := range memo[i][j] {
				memo[i][j][k] = make([]int, extrovertsCount+1)
				for l := range memo[i][j][k] {
					memo[i][j][k][l] = -1
				}
			}
		}
	}
	var dfs func(int, int, int, int) int
	dfs = func(pos, pre, ic, ec int) int {
		if pos == m*n || (ic == 0 && ec == 0) {
			return 0
		}
		if memo[pos][pre][ic][ec] != -1 {
			return memo[pos][pre][ic][ec]
		}
		ans := 0
		up := pre / p
		left := pre % 3
		if pos%n == 0 {
			left = 0
		}
		for i := 0; i < 3; i++ {
			if (i == 1 && ic == 0) || (i == 2 && ec == 0) {
				continue
			}
			cur := pre%p*3 + i
			nic, nec := ic, ec
			c := 0
			if i == 1 {
				nic--
				c = 120
			} else if i == 2 {
				nec--
				c = 40
			}
			a := h[up][i] + h[left][i]
			b := dfs(pos+1, cur, nic, nec)
			ans = max(ans, a+b+c)
		}
		memo[pos][pre][ic][ec] = ans
		return ans
	}
	return dfs(0, 0, introvertsCount, extrovertsCount)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaxGridHappiness(
    m: number,
    n: number,
    introvertsCount: number,
    extrovertsCount: number,
): number {
    const p = 3 ** (n - 1);
    const h: number[][] = [
        [0, 0, 0],
        [0, -60, -10],
        [0, -10, 40],
    ];
    const memo: number[][][][] = Array(m * n)
        .fill(0)
        .map(() =>
            Array(p * 3)
                .fill(0)
                .map(() =>
                    Array(introvertsCount + 1)
                        .fill(0)
                        .map(() => Array(extrovertsCount + 1).fill(-1)),
                ),
        );
    const dfs = (pos: number, pre: number, ic: number, ec: number): number => {
        if (pos === m * n || (ic === 0 && ec === 0)) {
            return 0;
        }
        if (memo[pos][pre][ic][ec] !== -1) {
            return memo[pos][pre][ic][ec];
        }
        let ans = 0;
        const up = Math.floor(pre / p);
        const left = pos % n == 0 ? 0 : pre % 3;
        for (let i = 0; i < 3; ++i) {
            if ((i === 1 && ic === 0) || (i === 2 && ec === 0)) {
                continue;
            }
            const cur = (pre % p) * 3 + i;
            const a = h[up][i] + h[left][i];
            const nic = i === 1 ? ic - 1 : ic;
            const nec = i === 2 ? ec - 1 : ec;
            const b = dfs(pos + 1, cur, nic, nec);
            const c = i === 1 ? 120 : i === 2 ? 40 : 0;
            ans = Math.max(ans, a + b + c);
        }
        return (memo[pos][pre][ic][ec] = ans);
    };
    return dfs(0, 0, introvertsCount, extrovertsCount);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你四个整数 <code>m</code>、<code>n</code>、<code>introvertsCount</code> 和 <code>extrovertsCount</code> 。有一个 <code>m x n</code> 网格，和两种类型的人：内向的人和外向的人。总共有 <code>introvertsCount</code> 个内向的人和 <code>extrovertsCount</code> 个外向的人。</p>

<p>请你决定网格中应当居住多少人，并为每个人分配一个网格单元。 注意，<strong>不必</strong> 让所有人都生活在网格中。</p>

<p>每个人的 <strong>幸福感</strong> 计算如下：</p>

<ul>
	<li>内向的人 <strong>开始</strong> 时有 <code>120</code> 个幸福感，但每存在一个邻居（内向的或外向的）他都会 <strong>失去</strong>  <code>30</code> 个幸福感。</li>
	<li>外向的人 <strong>开始</strong> 时有 <code>40</code> 个幸福感，每存在一个邻居（内向的或外向的）他都会 <strong>得到</strong>  <code>20</code> 个幸福感。</li>
</ul>

<p>邻居是指居住在一个人所在单元的上、下、左、右四个直接相邻的单元中的其他人。</p>

<p><strong>网格幸福感</strong> 是每个人幸福感的 <strong>总和</strong> 。 返回 <strong>最大可能的网格幸福感</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1659.Maximize%20Grid%20Happiness/images/grid_happiness.png" style="width: 261px; height: 121px;" />
<pre>
<strong>输入：</strong>m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2
<strong>输出：</strong>240
<strong>解释：</strong>假设网格坐标 (row, column) 从 1 开始编号。
将内向的人放置在单元 (1,1) ，将外向的人放置在单元 (1,3) 和 (2,3) 。
- 位于 (1,1) 的内向的人的幸福感：120（初始幸福感）- (0 * 30)（0 位邻居）= 120
- 位于 (1,3) 的外向的人的幸福感：40（初始幸福感）+ (1 * 20)（1 位邻居）= 60
- 位于 (2,3) 的外向的人的幸福感：40（初始幸福感）+ (1 * 20)（1 位邻居）= 60
网格幸福感为：120 + 60 + 60 = 240
上图展示该示例对应网格中每个人的幸福感。内向的人在浅绿色单元中，而外向的人在浅紫色单元中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1
<strong>输出：</strong>260
<strong>解释：</strong>将内向的人放置在单元 (1,1) 和 (3,1) ，将外向的人放置在单元 (2,1) 。
- 位于 (1,1) 的内向的人的幸福感：120（初始幸福感）- (1 * 30)（1 位邻居）= 90
- 位于 (2,1) 的外向的人的幸福感：40（初始幸福感）+ (2 * 20)（2 位邻居）= 80
- 位于 (3,1) 的内向的人的幸福感：120（初始幸福感）- (1 * 30)（1 位邻居）= 90
网格幸福感为 90 + 80 + 90 = 260
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0
<strong>输出：</strong>240
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m, n <= 5</code></li>
	<li><code>0 <= introvertsCount, extrovertsCount <= min(m * n, 6)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：三进制状态压缩 + 记忆化搜索

我们注意到，题目中 $1 \leq m, n \leq 5$，并且每个网格单元只有三种状态，即：不分配人员、分配内向的人、分配外向的人。因此，我们可以用 $0$, $1$, $2$ 表示这三种状态，网格中的每一行可以用一个长度为 $n$ 的三进制数表示。

我们定义一个函数 $dfs(i, pre, ic, ec)$，表示当前从第 $i$ 行开始，且上一行的状态为 $pre$，内向的人还剩 $ic$ 个，外向的人还剩 $ec$ 个时，网格的最大幸福感。那么答案就是 $dfs(0, 0, introvertsCount, extrovertsCount)$。

函数 $dfs(i, pre, ic, ec)$ 的计算过程如下：

如果 $i = m$，表示已经处理完了所有的行，那么返回 $0$；

如果 $ic = 0$ 且 $ec = 0$，表示所有的人都已经分配完了，那么返回 $0$；

否则，枚举当前行的状态 $cur$，其中 $cur \in [0, 3^n)$，然后计算当前行的幸福感 $f[cur]$，以及与上一行的状态 $pre$ 之间对幸福感的贡献 $g[pre][cur]$，并递归计算 $dfs(i + 1, cur, ic - ix[cur], ec - ex[cur])$，最后返回 $f[cur] + g[pre][cur] + dfs(i + 1, cur, ic - ix[cur], ec - ex[cur])$ 的最大值，即：

$$
dfs(i, pre, ic, ec) = \max_{cur} \{f[cur] + g[pre][cur] + dfs(i + 1, cur, ic - ix[cur], ec - ex[cur])\}
$$

其中：

-   $ix[cur]$ 表示状态 $cur$ 中内向的人的个数；
-   $ex[cur]$ 表示状态 $cur$ 中外向的人的个数；
-   $f[cur]$ 表示状态 $cur$ 中的人的初始幸福感；
-   $g[pre][cur]$ 表示两个相邻状态行对幸福感的贡献。

这些值都可以通过预处理得到。并且，我们可以使用记忆化搜索的方法，避免重复计算。

时间复杂度 $O(3^{2n} \times (m \times ic \times ec + n))$，空间复杂度 $O(3^{2n} + 3^n \times m \times ic \times ec)$。其中 $ic$ 和 $ec$ 分别表示内向的人和外向的人的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaxGridHappiness(
        self, m: int, n: int, introvertsCount: int, extrovertsCount: int
    ) -> int:
        @cache
        def dfs(i: int, pre: int, ic: int, ec: int) -> int:
            if i == m or (ic == 0 and ec == 0):
                return 0
            ans = 0
            for cur in range(mx):
                if ix[cur] <= ic and ex[cur] <= ec:
                    a = f[cur] + g[pre][cur]
                    b = dfs(i + 1, cur, ic - ix[cur], ec - ex[cur])
                    ans = max(ans, a + b)
            return ans

        mx = pow(3, n)
        f = [0] * mx
        g = [[0] * mx for _ in range(mx)]
        h = [[0, 0, 0], [0, -60, -10], [0, -10, 40]]
        bits = [[0] * n for _ in range(mx)]
        ix = [0] * mx
        ex = [0] * mx
        for i in range(mx):
            mask = i
            for j in range(n):
                mask, x = divmod(mask, 3)
                bits[i][j] = x
                if x == 1:
                    ix[i] += 1
                    f[i] += 120
                elif x == 2:
                    ex[i] += 1
                    f[i] += 40
                if j:
                    f[i] += h[x][bits[i][j - 1]]
        for i in range(mx):
            for j in range(mx):
                for k in range(n):
                    g[i][j] += h[bits[i][k]][bits[j][k]]
        return dfs(0, 0, introvertsCount, extrovertsCount)
```

#### Java

```java
class Solution {
    private int m;
    private int mx;
    private int[] f;
    private int[][] g;
    private int[][] bits;
    private int[] ix;
    private int[] ex;
    private Integer[][][][] memo;
    private final int[][] h = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};

    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this.m = m;
        mx = (int) Math.pow(3, n);
        f = new int[mx];
        g = new int[mx][mx];
        bits = new int[mx][n];
        ix = new int[mx];
        ex = new int[mx];
        memo = new Integer[m][mx][introvertsCount + 1][extrovertsCount + 1];
        for (int i = 0; i < mx; ++i) {
            int mask = i;
            for (int j = 0; j < n; ++j) {
                int x = mask % 3;
                mask /= 3;
                bits[i][j] = x;
                if (x == 1) {
                    ix[i]++;
                    f[i] += 120;
                } else if (x == 2) {
                    ex[i]++;
                    f[i] += 40;
                }
                if (j > 0) {
                    f[i] += h[x][bits[i][j - 1]];
                }
            }
        }
        for (int i = 0; i < mx; ++i) {
            for (int j = 0; j < mx; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[i][j] += h[bits[i][k]][bits[j][k]];
                }
            }
        }
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    private int dfs(int i, int pre, int ic, int ec) {
        if (i == m || (ic == 0 && ec == 0)) {
            return 0;
        }
        if (memo[i][pre][ic][ec] != null) {
            return memo[i][pre][ic][ec];
        }
        int ans = 0;
        for (int cur = 0; cur < mx; ++cur) {
            if (ix[cur] <= ic && ex[cur] <= ec) {
                ans = Math.max(
                    ans, f[cur] + g[pre][cur] + dfs(i + 1, cur, ic - ix[cur], ec - ex[cur]));
            }
        }
        return memo[i][pre][ic][ec] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int mx = pow(3, n);
        int f[mx];
        int g[mx][mx];
        int bits[mx][n];
        int ix[mx];
        int ex[mx];
        int memo[m][mx][introvertsCount + 1][extrovertsCount + 1];
        int h[3][3] = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(bits, 0, sizeof(bits));
        memset(ix, 0, sizeof(ix));
        memset(ex, 0, sizeof(ex));
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < mx; ++i) {
            int mask = i;
            for (int j = 0; j < n; ++j) {
                int x = mask % 3;
                mask /= 3;
                bits[i][j] = x;
                if (x == 1) {
                    ix[i]++;
                    f[i] += 120;
                } else if (x == 2) {
                    ex[i]++;
                    f[i] += 40;
                }
                if (j) {
                    f[i] += h[x][bits[i][j - 1]];
                }
            }
        }
        for (int i = 0; i < mx; ++i) {
            for (int j = 0; j < mx; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[i][j] += h[bits[i][k]][bits[j][k]];
                }
            }
        }
        function<int(int, int, int, int)> dfs = [&](int i, int pre, int ic, int ec) {
            if (i == m || (ic == 0 && ec == 0)) {
                return 0;
            }
            if (memo[i][pre][ic][ec] != -1) {
                return memo[i][pre][ic][ec];
            }
            int ans = 0;
            for (int cur = 0; cur < mx; ++cur) {
                if (ix[cur] <= ic && ex[cur] <= ec) {
                    ans = max(ans, f[cur] + g[pre][cur] + dfs(i + 1, cur, ic - ix[cur], ec - ex[cur]));
                }
            }
            return memo[i][pre][ic][ec] = ans;
        };
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};
```

#### Go

```go
func getMaxGridHappiness(m int, n int, introvertsCount int, extrovertsCount int) int {
	mx := int(math.Pow(3, float64(n)))
	f := make([]int, mx)
	g := make([][]int, mx)
	h := [3][3]int{{0, 0, 0}, {0, -60, -10}, {0, -10, 40}}
	bits := make([][]int, mx)
	ix := make([]int, mx)
	ex := make([]int, mx)
	memo := make([][][][]int, m)
	for i := range g {
		g[i] = make([]int, mx)
		bits[i] = make([]int, n)
	}
	for i := range memo {
		memo[i] = make([][][]int, mx)
		for j := range memo[i] {
			memo[i][j] = make([][]int, introvertsCount+1)
			for k := range memo[i][j] {
				memo[i][j][k] = make([]int, extrovertsCount+1)
				for l := range memo[i][j][k] {
					memo[i][j][k][l] = -1
				}
			}
		}
	}
	for i := 0; i < mx; i++ {
		mask := i
		for j := 0; j < n; j++ {
			x := mask % 3
			mask /= 3
			bits[i][j] = x
			if x == 1 {
				ix[i]++
				f[i] += 120
			} else if x == 2 {
				ex[i]++
				f[i] += 40
			}
			if j > 0 {
				f[i] += h[x][bits[i][j-1]]
			}
		}
	}
	for i := 0; i < mx; i++ {
		for j := 0; j < mx; j++ {
			for k := 0; k < n; k++ {
				g[i][j] += h[bits[i][k]][bits[j][k]]
			}
		}
	}
	var dfs func(int, int, int, int) int
	dfs = func(i, pre, ic, ec int) int {
		if i == m || (ic == 0 && ec == 0) {
			return 0
		}
		if memo[i][pre][ic][ec] != -1 {
			return memo[i][pre][ic][ec]
		}
		ans := 0
		for cur := 0; cur < mx; cur++ {
			if ix[cur] <= ic && ex[cur] <= ec {
				ans = max(ans, f[cur]+g[pre][cur]+dfs(i+1, cur, ic-ix[cur], ec-ex[cur]))
			}
		}
		memo[i][pre][ic][ec] = ans
		return ans
	}
	return dfs(0, 0, introvertsCount, extrovertsCount)
}
```

#### TypeScript

```ts
function getMaxGridHappiness(
    m: number,
    n: number,
    introvertsCount: number,
    extrovertsCount: number,
): number {
    const mx = 3 ** n;
    const f: number[] = Array(mx).fill(0);
    const g: number[][] = Array(mx)
        .fill(0)
        .map(() => Array(mx).fill(0));
    const h: number[][] = [
        [0, 0, 0],
        [0, -60, -10],
        [0, -10, 40],
    ];
    const bits: number[][] = Array(mx)
        .fill(0)
        .map(() => Array(n).fill(0));
    const ix: number[] = Array(mx).fill(0);
    const ex: number[] = Array(mx).fill(0);
    const memo: number[][][][] = Array(m)
        .fill(0)
        .map(() =>
            Array(mx)
                .fill(0)
                .map(() =>
                    Array(introvertsCount + 1)
                        .fill(0)
                        .map(() => Array(extrovertsCount + 1).fill(-1)),
                ),
        );
    for (let i = 0; i < mx; ++i) {
        let mask = i;
        for (let j = 0; j < n; ++j) {
            const x = mask % 3;
            mask = Math.floor(mask / 3);
            bits[i][j] = x;
            if (x === 1) {
                ix[i] += 1;
                f[i] += 120;
            } else if (x === 2) {
                ex[i] += 1;
                f[i] += 40;
            }
            if (j > 0) {
                f[i] += h[x][bits[i][j - 1]];
            }
        }
    }
    for (let i = 0; i < mx; ++i) {
        for (let j = 0; j < mx; ++j) {
            for (let k = 0; k < n; ++k) {
                g[i][j] += h[bits[i][k]][bits[j][k]];
            }
        }
    }
    const dfs = (i: number, pre: number, ic: number, ec: number): number => {
        if (i === m || (ic === 0 && ec === 0)) {
            return 0;
        }
        if (memo[i][pre][ic][ec] !== -1) {
            return memo[i][pre][ic][ec];
        }
        let ans = 0;
        for (let cur = 0; cur < mx; ++cur) {
            if (ix[cur] <= ic && ex[cur] <= ec) {
                const a = f[cur] + g[pre][cur];
                const b = dfs(i + 1, cur, ic - ix[cur], ec - ex[cur]);
                ans = Math.max(ans, a + b);
            }
        }
        return (memo[i][pre][ic][ec] = ans);
    };
    return dfs(0, 0, introvertsCount, extrovertsCount);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：轮廓线记忆化搜索

我们可以考虑搜索每个网格单元，每次搜索一个位置 $(i, j)$，我们记 $pos = i \times n + j$。那么它左边以及上边的相邻网格会影响到它们之间的幸福感贡献。

我们定义一个函数 $dfs(pos, pre, ic, ec)$，表示当前搜索到位置 $pos$，且此前的 $n$ 个网格单元的状态为 $pre$，内向的人还剩 $ic$ 个，外向的人还剩 $ec$ 个时，网格的最大幸福感。那么答案就是 $dfs(0, 0, introvertsCount, extrovertsCount)$。

函数 $dfs(pos, pre, ic, ec)$ 的计算过程如下：

如果 $pos = m \times n$，表示已经处理完了所有的网格单元，那么返回 $0$；

如果 $ic = 0$ 且 $ec = 0$，表示所有的人都已经分配完了，那么返回 $0$；

否则，我们根据 $pre$ 算出当前网格单元的上边相邻网格单元的状态 $up = \frac{pre}{3^{n-1}}$，以及左边相邻网格单元的状态 $left = pre \bmod 3$（注意，如果 $pos$ 在第 $0$ 列，那么 $left = 0$）。

接下来，我们枚举当前网格单元的状态 $i$，其中 $i \in [0, 3)$。那么当前的 $n$ 个网格单元的状态为 $cur = pre \bmod 3^{n-1} \times 3 + i$，当前网格单元以及左边和上边的相邻网格单元的幸福感贡献为 $h[up][i]+h[left][i]$；而当前网格单元本身的幸福感取决于该位置是否分配人员，以及分配的人员是内向的还是外向的，如果是内向的，那么幸福感为 $120$，如果是外向的，那么幸福感为 $40$，否则幸福感为 $0$；然后，如果当前网格单元分配了人员，那么我们递归调用时需要更新 $ic$ 或 $ec$。累计这些幸福感，取最大值作为函数的返回值。

与方法一类似，我们也可以使用记忆化搜索的方法，避免重复计算。

时间复杂度 $O(3^{n+1} \times m \times n \times ic \times ec)$，空间复杂度 $O(3^n \times m \times n \times ic \times ec)$。其中 $ic$ 和 $ec$ 分别表示内向的人和外向的人的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaxGridHappiness(
        self, m: int, n: int, introvertsCount: int, extrovertsCount: int
    ) -> int:
        @cache
        def dfs(pos: int, pre: int, ic: int, ec: int) -> int:
            if pos == m * n or (ic == 0 and ec == 0):
                return 0
            ans = 0
            up = pre // p
            left = 0 if pos % n == 0 else pre % 3
            for i in range(3):
                if (i == 1 and ic == 0) or (i == 2 and ec == 0):
                    continue
                cur = pre % p * 3 + i
                a = h[up][i] + h[left][i]
                b = dfs(pos + 1, cur, ic - (i == 1), ec - (i == 2))
                c = 0
                if i == 1:
                    c = 120
                elif i == 2:
                    c = 40
                ans = max(ans, a + b + c)
            return ans

        p = pow(3, n - 1)
        h = [[0, 0, 0], [0, -60, -10], [0, -10, 40]]
        return dfs(0, 0, introvertsCount, extrovertsCount)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int p;
    private final int[][] h = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
    private Integer[][][][] memo;

    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this.m = m;
        this.n = n;
        p = (int) Math.pow(3, n - 1);
        memo = new Integer[m * n][p * 3][introvertsCount + 1][extrovertsCount + 1];
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    private int dfs(int pos, int pre, int ic, int ec) {
        if (pos == m * n || (ic == 0 && ec == 0)) {
            return 0;
        }
        if (memo[pos][pre][ic][ec] != null) {
            return memo[pos][pre][ic][ec];
        }
        int ans = 0;
        int up = pre / p;
        int left = pos % n == 0 ? 0 : pre % 3;
        for (int i = 0; i < 3; ++i) {
            if (i == 1 && (ic == 0) || (i == 2 && ec == 0)) {
                continue;
            }
            int cur = pre % p * 3 + i;
            int a = h[up][i] + h[left][i];
            int b = dfs(pos + 1, cur, ic - (i == 1 ? 1 : 0), ec - (i == 2 ? 1 : 0));
            int c = i == 1 ? 120 : (i == 2 ? 40 : 0);
            ans = Math.max(ans, a + b + c);
        }
        return memo[pos][pre][ic][ec] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int h[3][3] = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
        int p = pow(3, n - 1);
        int memo[m * n][p * 3][introvertsCount + 1][extrovertsCount + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int, int)> dfs = [&](int pos, int pre, int ic, int ec) {
            if (pos == m * n || (ic == 0 && ec == 0)) {
                return 0;
            }
            if (memo[pos][pre][ic][ec] != -1) {
                return memo[pos][pre][ic][ec];
            }
            int ans = 0;
            int up = pre / p;
            int left = pos % n == 0 ? 0 : pre % 3;
            for (int i = 0; i < 3; ++i) {
                if ((i == 1 && ic == 0) || (i == 2 && ec == 0)) {
                    continue;
                }
                int cur = pre % p * 3 + i;
                int a = h[up][i] + h[left][i];
                int b = dfs(pos + 1, cur, ic - (i == 1), ec - (i == 2));
                int c = i == 1 ? 120 : (i == 2 ? 40 : 0);
                ans = max(ans, a + b + c);
            }
            return memo[pos][pre][ic][ec] = ans;
        };
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};
```

#### Go

```go
func getMaxGridHappiness(m int, n int, introvertsCount int, extrovertsCount int) int {
	p := int(math.Pow(3, float64(n-1)))
	h := [3][3]int{{0, 0, 0}, {0, -60, -10}, {0, -10, 40}}
	memo := make([][][][]int, m*n)
	for i := range memo {
		memo[i] = make([][][]int, p*3)
		for j := range memo[i] {
			memo[i][j] = make([][]int, introvertsCount+1)
			for k := range memo[i][j] {
				memo[i][j][k] = make([]int, extrovertsCount+1)
				for l := range memo[i][j][k] {
					memo[i][j][k][l] = -1
				}
			}
		}
	}
	var dfs func(int, int, int, int) int
	dfs = func(pos, pre, ic, ec int) int {
		if pos == m*n || (ic == 0 && ec == 0) {
			return 0
		}
		if memo[pos][pre][ic][ec] != -1 {
			return memo[pos][pre][ic][ec]
		}
		ans := 0
		up := pre / p
		left := pre % 3
		if pos%n == 0 {
			left = 0
		}
		for i := 0; i < 3; i++ {
			if (i == 1 && ic == 0) || (i == 2 && ec == 0) {
				continue
			}
			cur := pre%p*3 + i
			nic, nec := ic, ec
			c := 0
			if i == 1 {
				nic--
				c = 120
			} else if i == 2 {
				nec--
				c = 40
			}
			a := h[up][i] + h[left][i]
			b := dfs(pos+1, cur, nic, nec)
			ans = max(ans, a+b+c)
		}
		memo[pos][pre][ic][ec] = ans
		return ans
	}
	return dfs(0, 0, introvertsCount, extrovertsCount)
}
```

#### TypeScript

```ts
function getMaxGridHappiness(
    m: number,
    n: number,
    introvertsCount: number,
    extrovertsCount: number,
): number {
    const p = 3 ** (n - 1);
    const h: number[][] = [
        [0, 0, 0],
        [0, -60, -10],
        [0, -10, 40],
    ];
    const memo: number[][][][] = Array(m * n)
        .fill(0)
        .map(() =>
            Array(p * 3)
                .fill(0)
                .map(() =>
                    Array(introvertsCount + 1)
                        .fill(0)
                        .map(() => Array(extrovertsCount + 1).fill(-1)),
                ),
        );
    const dfs = (pos: number, pre: number, ic: number, ec: number): number => {
        if (pos === m * n || (ic === 0 && ec === 0)) {
            return 0;
        }
        if (memo[pos][pre][ic][ec] !== -1) {
            return memo[pos][pre][ic][ec];
        }
        let ans = 0;
        const up = Math.floor(pre / p);
        const left = pos % n == 0 ? 0 : pre % 3;
        for (let i = 0; i < 3; ++i) {
            if ((i === 1 && ic === 0) || (i === 2 && ec === 0)) {
                continue;
            }
            const cur = (pre % p) * 3 + i;
            const a = h[up][i] + h[left][i];
            const nic = i === 1 ? ic - 1 : ic;
            const nec = i === 2 ? ec - 1 : ec;
            const b = dfs(pos + 1, cur, nic, nec);
            const c = i === 1 ? 120 : i === 2 ? 40 : 0;
            ans = Math.max(ans, a + b + c);
        }
        return (memo[pos][pre][ic][ec] = ans);
    };
    return dfs(0, 0, introvertsCount, extrovertsCount);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
