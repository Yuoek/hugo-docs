---
title: "1740_找到二叉树中的距离 🔒"
date: 2025-10-08T18:38:17+08:00
weight: 5
tags: [二叉树, 前缀和, 动态规划, 哈希表, 字符串, 广度优先搜索, 数学, 数据库, 数组, 树, 深度优先搜索, 计数]
---

{{< markmap >}}
### [1740_找到二叉树中的距离 🔒](#1740)
#### [树](#1740)
#### [深度优先搜索](#1740)
#### [广度优先搜索](#1740)
#### [哈希表](#1740)
#### [二叉树](#1740)
### [1741_查找每个员工花费的总时间](#1741)
#### [数据库](#1741)
### [1742_盒子中小球的最大数量](#1742)
#### [哈希表](#1742)
#### [数学](#1742)
#### [计数](#1742)
### [1743_从相邻元素对还原数组](#1743)
#### [深度优先搜索](#1743)
#### [数组](#1743)
#### [哈希表](#1743)
### [1744_你能在你最喜欢的那天吃到你最喜欢的糖果吗？](#1744)
#### [数组](#1744)
#### [前缀和](#1744)
### [1745_分割回文串 IV](#1745)
#### [字符串](#1745)
#### [动态规划](#1745)
### [1746_经过一次操作后的最大子数组和 🔒](#1746)
#### [数组](#1746)
#### [动态规划](#1746)
### [1747_应该被禁止的 Leetflex 账户 🔒](#1747)
#### [数据库](#1747)
### [1748_唯一元素的和](#1748)
#### [数组](#1748)
#### [哈希表](#1748)
#### [计数](#1748)
### [1749_任意子数组和的绝对值的最大值](#1749)
#### [数组](#1749)
#### [动态规划](#1749)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1740_找到二叉树中的距离 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 1741_查找每个员工花费的总时间
___
#### 数据库
---
### 1742_盒子中小球的最大数量
___
#### 哈希表
___
#### 数学
___
#### 计数
---
### 1743_从相邻元素对还原数组
___
#### 深度优先搜索
___
#### 数组
___
#### 哈希表
---
### 1744_你能在你最喜欢的那天吃到你最喜欢的糖果吗？
___
#### 数组
___
#### 前缀和
---
### 1745_分割回文串 IV
___
#### 字符串
___
#### 动态规划
---
### 1746_经过一次操作后的最大子数组和 🔒
___
#### 数组
___
#### 动态规划
---
### 1747_应该被禁止的 Leetflex 账户 🔒
___
#### 数据库
---
### 1748_唯一元素的和
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1749_任意子数组和的绝对值的最大值
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 前缀和 | 动态规划 |
| 哈希表 | 字符串 | 广度优先搜索 |
| 数学 | 数据库 | 数组 |
| 树 | 深度优先搜索 | 计数 |

# [1740. 找到二叉树中的距离 🔒](https://leetcode.cn/problems/find-distance-in-a-binary-tree){#1740}

{{< tabs "1740" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        def lca(root, p, q):
            if root is None or root.val in [p, q]:
                return root
            left = lca(root.left, p, q)
            right = lca(root.right, p, q)
            if left is None:
                return right
            if right is None:
                return left
            return root

        def dfs(root, v):
            if root is None:
                return -1
            if root.val == v:
                return 0
            left, right = dfs(root.left, v), dfs(root.right, v)
            if left == right == -1:
                return -1
            return 1 + max(left, right)

        g = lca(root, p, q)
        return dfs(g, p) + dfs(g, q)
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
    public int findDistance(TreeNode root, int p, int q) {
        TreeNode g = lca(root, p, q);
        return dfs(g, p) + dfs(g, q);
    }

    private int dfs(TreeNode root, int v) {
        if (root == null) {
            return -1;
        }
        if (root.val == v) {
            return 0;
        }
        int left = dfs(root.left, v);
        int right = dfs(root.right, v);
        if (left == -1 && right == -1) {
            return -1;
        }
        return 1 + Math.max(left, right);
    }

    private TreeNode lca(TreeNode root, int p, int q) {
        if (root == null || root.val == p || root.val == q) {
            return root;
        }
        TreeNode left = lca(root.left, p, q);
        TreeNode right = lca(root.right, p, q);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* g = lca(root, p, q);
        return dfs(g, p) + dfs(g, q);
    }

    TreeNode* lca(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }

    int dfs(TreeNode* root, int v) {
        if (!root) return -1;
        if (root->val == v) return 0;
        int left = dfs(root->left, v);
        int right = dfs(root->right, v);
        if (left == -1 && right == -1) return -1;
        return 1 + max(left, right);
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
func findDistance(root *TreeNode, p int, q int) int {
	var lca func(root *TreeNode, p int, q int) *TreeNode
	lca = func(root *TreeNode, p int, q int) *TreeNode {
		if root == nil || root.Val == p || root.Val == q {
			return root
		}
		left, right := lca(root.Left, p, q), lca(root.Right, p, q)
		if left == nil {
			return right
		}
		if right == nil {
			return left
		}
		return root
	}
	var dfs func(root *TreeNode, v int) int
	dfs = func(root *TreeNode, v int) int {
		if root == nil {
			return -1
		}
		if root.Val == v {
			return 0
		}
		left, right := dfs(root.Left, v), dfs(root.Right, v)
		if left == -1 && right == -1 {
			return -1
		}
		return 1 + max(left, right)
	}
	g := lca(root, p, q)
	return dfs(g, p) + dfs(g, q)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点 <code>root</code> 以及两个整数 <code>p</code> 和 <code>q</code> ，返回该二叉树中值为 <code>p</code> 的结点与值为 <code>q</code> 的结点间的 <strong>距离 </strong>。</p>

<p>两个结点间的<strong> 距离 </strong>就是从一个结点到另一个结点的路径上边的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1740.Find%20Distance%20in%20a%20Binary%20Tree/images/binarytree.png" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
<strong>输出：</strong>3
<strong>解释：</strong>在 5 和 0 之间有 3 条边：5-3-1-0</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1740.Find%20Distance%20in%20a%20Binary%20Tree/images/binarytree.png" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
<strong>输出：</strong>2
<strong>解释：</strong>在 5 和 7 之间有 2 条边：5-2-7</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1740.Find%20Distance%20in%20a%20Binary%20Tree/images/binarytree.png" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
<strong>输出：</strong>0
<strong>解释：</strong>一个结点与它本身之间的距离为 0</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点个数的范围在 <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>0 <= Node.val <= 10<sup>9</sup></code></li>
	<li>树中所有结点的值都是唯一的.</li>
	<li><code>p</code> 和<code>q</code> 是树中结点的值.</li>
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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        def lca(root, p, q):
            if root is None or root.val in [p, q]:
                return root
            left = lca(root.left, p, q)
            right = lca(root.right, p, q)
            if left is None:
                return right
            if right is None:
                return left
            return root

        def dfs(root, v):
            if root is None:
                return -1
            if root.val == v:
                return 0
            left, right = dfs(root.left, v), dfs(root.right, v)
            if left == right == -1:
                return -1
            return 1 + max(left, right)

        g = lca(root, p, q)
        return dfs(g, p) + dfs(g, q)
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
    public int findDistance(TreeNode root, int p, int q) {
        TreeNode g = lca(root, p, q);
        return dfs(g, p) + dfs(g, q);
    }

    private int dfs(TreeNode root, int v) {
        if (root == null) {
            return -1;
        }
        if (root.val == v) {
            return 0;
        }
        int left = dfs(root.left, v);
        int right = dfs(root.right, v);
        if (left == -1 && right == -1) {
            return -1;
        }
        return 1 + Math.max(left, right);
    }

    private TreeNode lca(TreeNode root, int p, int q) {
        if (root == null || root.val == p || root.val == q) {
            return root;
        }
        TreeNode left = lca(root.left, p, q);
        TreeNode right = lca(root.right, p, q);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* g = lca(root, p, q);
        return dfs(g, p) + dfs(g, q);
    }

    TreeNode* lca(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }

    int dfs(TreeNode* root, int v) {
        if (!root) return -1;
        if (root->val == v) return 0;
        int left = dfs(root->left, v);
        int right = dfs(root->right, v);
        if (left == -1 && right == -1) return -1;
        return 1 + max(left, right);
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
func findDistance(root *TreeNode, p int, q int) int {
	var lca func(root *TreeNode, p int, q int) *TreeNode
	lca = func(root *TreeNode, p int, q int) *TreeNode {
		if root == nil || root.Val == p || root.Val == q {
			return root
		}
		left, right := lca(root.Left, p, q), lca(root.Right, p, q)
		if left == nil {
			return right
		}
		if right == nil {
			return left
		}
		return root
	}
	var dfs func(root *TreeNode, v int) int
	dfs = func(root *TreeNode, v int) int {
		if root == nil {
			return -1
		}
		if root.Val == v {
			return 0
		}
		left, right := dfs(root.Left, v), dfs(root.Right, v)
		if left == -1 && right == -1 {
			return -1
		}
		return 1 + max(left, right)
	}
	g := lca(root, p, q)
	return dfs(g, p) + dfs(g, q)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1741. 查找每个员工花费的总时间](https://leetcode.cn/problems/find-total-time-spent-by-each-employee){#1741}

{{< tabs "1741" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT event_day AS day, emp_id, SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Employees</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| emp_id      | int  |
| event_day   | date |
| in_time     | int  |
| out_time    | int  |
+-------------+------+
在 SQL 中，(emp_id, event_day, in_time) 是这个表的主键。
该表显示了员工在办公室的出入情况。
event_day 是此事件发生的日期，in_time 是员工进入办公室的时间，而 out_time 是他们离开办公室的时间。
in_time 和 out_time 的取值在1到1440之间。
题目保证同一天没有两个事件在时间上是相交的，并且保证 in_time 小于 out_time。
</pre>

<p>&nbsp;</p>

<p>计算每位员工每天在办公室花费的总时间（以分钟为单位）。 请注意，在一天之内，同一员工是可以多次进入和离开办公室的。 在办公室里一次进出所花费的时间为out_time 减去 in_time。</p>

<p>返回结果表单的顺序无要求。<br />
查询结果的格式如下：</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employees table:
+--------+------------+---------+----------+
| emp_id | event_day  | in_time | out_time |
+--------+------------+---------+----------+
| 1      | 2020-11-28 | 4       | 32       |
| 1      | 2020-11-28 | 55      | 200      |
| 1      | 2020-12-03 | 1       | 42       |
| 2      | 2020-11-28 | 3       | 33       |
| 2      | 2020-12-09 | 47      | 74       |
+--------+------------+---------+----------+
<strong>输出：</strong>
+------------+--------+------------+
| day        | emp_id | total_time |
+------------+--------+------------+
| 2020-11-28 | 1      | 173        |
| 2020-11-28 | 2      | 30         |
| 2020-12-03 | 1      | 41         |
| 2020-12-09 | 2      | 27         |
+------------+--------+------------+
<strong>解释：</strong>
雇员 1 有三次进出: 有两次发生在 2020-11-28 花费的时间为 (32 - 4) + (200 - 55) = 173, 有一次发生在 2020-12-03 花费的时间为 (42 - 1) = 41。
雇员 2 有两次进出: 有一次发生在 2020-11-28 花费的时间为 (33 - 3) = 30,  有一次发生在 2020-12-09 花费的时间为 (74 - 47) = 27。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求和

我们可以先按照 `emp_id` 和 `event_day` 进行分组，然后计算每个分组的总时间。总时间等于每个分组的 `out_time` 减去 `in_time` 的和。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT event_day AS day, emp_id, SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1742. 盒子中小球的最大数量](https://leetcode.cn/problems/maximum-number-of-balls-in-a-box){#1742}

{{< tabs "1742" >}}

{{% tab "python" %}}
```python
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        cnt = [0] * 50
        for x in range(lowLimit, highLimit + 1):
            y = 0
            while x:
                y += x % 10
                x //= 10
            cnt[y] += 1
        return max(cnt)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        int[] cnt = new int[50];
        for (int i = lowLimit; i <= highLimit; ++i) {
            int y = 0;
            for (int x = i; x > 0; x /= 10) {
                y += x % 10;
            }
            ++cnt[y];
        }
        return Arrays.stream(cnt).max().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[50] = {0};
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int y = 0;
            for (int x = i; x; x /= 10) {
                y += x % 10;
            }
            ans = max(ans, ++cnt[y]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countBalls(lowLimit int, highLimit int) (ans int) {
	cnt := [50]int{}
	for i := lowLimit; i <= highLimit; i++ {
		y := 0
		for x := i; x > 0; x /= 10 {
			y += x % 10
		}
		cnt[y]++
		if ans < cnt[y] {
			ans = cnt[y]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countBalls(lowLimit: number, highLimit: number): number {
    const cnt: number[] = Array(50).fill(0);
    for (let i = lowLimit; i <= highLimit; ++i) {
        let y = 0;
        for (let x = i; x; x = Math.floor(x / 10)) {
            y += x % 10;
        }
        ++cnt[y];
    }
    return Math.max(...cnt);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let mut cnt = vec![0; 50];
        for x in low_limit..=high_limit {
            let mut y = 0;
            let mut n = x;
            while n > 0 {
                y += n % 10;
                n /= 10;
            }
            cnt[y as usize] += 1;
        }
        *cnt.iter().max().unwrap()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} lowLimit
 * @param {number} highLimit
 * @return {number}
 */
var countBalls = function (lowLimit, highLimit) {
    const cnt = Array(50).fill(0);
    for (let i = lowLimit; i <= highLimit; ++i) {
        let y = 0;
        for (let x = i; x; x = Math.floor(x / 10)) {
            y += x % 10;
        }
        ++cnt[y];
    }
    return Math.max(...cnt);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountBalls(int lowLimit, int highLimit) {
        int[] cnt = new int[50];
        for (int x = lowLimit; x <= highLimit; x++) {
            int y = 0;
            int n = x;
            while (n > 0) {
                y += n % 10;
                n /= 10;
            }
            cnt[y]++;
        }
        return cnt.Max();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你在一家生产小球的玩具厂工作，有 <code>n</code> 个小球，编号从 <code>lowLimit</code> 开始，到 <code>highLimit</code> 结束（包括 <code>lowLimit</code> 和 <code>highLimit</code> ，即 <code>n == highLimit - lowLimit + 1</code>）。另有无限数量的盒子，编号从 <code>1</code> 到 <code>infinity</code> 。</p>

<p>你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 <code>321</code> 的小球应当放入编号 <code>3 + 2 + 1 = 6</code> 的盒子，而编号 <code>10</code> 的小球应当放入编号 <code>1 + 0 = 1</code> 的盒子。</p>

<p>给你两个整数 <code>lowLimit</code> 和 <code>highLimit</code> ，返回放有最多小球的盒子中的小球数量<em>。</em>如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>lowLimit = 1, highLimit = 10
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
编号 1 的盒子放有最多小球，小球数量为 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>lowLimit = 5, highLimit = 15
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>lowLimit = 19, highLimit = 28
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
编号 10 的盒子放有最多小球，小球数量为 2 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= lowLimit <= highLimit <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组 + 模拟

观察题目的数据范围，小球的编号最大不超过 $10^5$，那么每个编号的各个位数之和的最大值小于 $50$。因此，我们可以直接开一个长度为 $50$ 的数组 $\textit{cnt}$ 来统计每个编号的各个位数之和的数量。

答案就是数组 $\textit{cnt}$ 中的最大值。

时间复杂度 $O(n \times \log_{10}m)$。其中 $n = \textit{highLimit} - \textit{lowLimit} + 1$，而 $m = \textit{highLimit}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        cnt = [0] * 50
        for x in range(lowLimit, highLimit + 1):
            y = 0
            while x:
                y += x % 10
                x //= 10
            cnt[y] += 1
        return max(cnt)
```

#### Java

```java
class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        int[] cnt = new int[50];
        for (int i = lowLimit; i <= highLimit; ++i) {
            int y = 0;
            for (int x = i; x > 0; x /= 10) {
                y += x % 10;
            }
            ++cnt[y];
        }
        return Arrays.stream(cnt).max().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[50] = {0};
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int y = 0;
            for (int x = i; x; x /= 10) {
                y += x % 10;
            }
            ans = max(ans, ++cnt[y]);
        }
        return ans;
    }
};
```

#### Go

```go
func countBalls(lowLimit int, highLimit int) (ans int) {
	cnt := [50]int{}
	for i := lowLimit; i <= highLimit; i++ {
		y := 0
		for x := i; x > 0; x /= 10 {
			y += x % 10
		}
		cnt[y]++
		if ans < cnt[y] {
			ans = cnt[y]
		}
	}
	return
}
```

#### TypeScript

```ts
function countBalls(lowLimit: number, highLimit: number): number {
    const cnt: number[] = Array(50).fill(0);
    for (let i = lowLimit; i <= highLimit; ++i) {
        let y = 0;
        for (let x = i; x; x = Math.floor(x / 10)) {
            y += x % 10;
        }
        ++cnt[y];
    }
    return Math.max(...cnt);
}
```

#### Rust

```rust
impl Solution {
    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let mut cnt = vec![0; 50];
        for x in low_limit..=high_limit {
            let mut y = 0;
            let mut n = x;
            while n > 0 {
                y += n % 10;
                n /= 10;
            }
            cnt[y as usize] += 1;
        }
        *cnt.iter().max().unwrap()
    }
}
```

#### JavaScript

```js
/**
 * @param {number} lowLimit
 * @param {number} highLimit
 * @return {number}
 */
var countBalls = function (lowLimit, highLimit) {
    const cnt = Array(50).fill(0);
    for (let i = lowLimit; i <= highLimit; ++i) {
        let y = 0;
        for (let x = i; x; x = Math.floor(x / 10)) {
            y += x % 10;
        }
        ++cnt[y];
    }
    return Math.max(...cnt);
};
```

#### C#

```cs
public class Solution {
    public int CountBalls(int lowLimit, int highLimit) {
        int[] cnt = new int[50];
        for (int x = lowLimit; x <= highLimit; x++) {
            int y = 0;
            int n = x;
            while (n > 0) {
                y += n % 10;
                n /= 10;
            }
            cnt[y]++;
        }
        return cnt.Max();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1743. 从相邻元素对还原数组](https://leetcode.cn/problems/restore-the-array-from-adjacent-pairs){#1743}

{{< tabs "1743" >}}

{{% tab "python" %}}
```python
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        def dfs(i, fa):
            ans.append(i)
            for j in g[i]:
                if j != fa:
                    dfs(j, i)

        g = defaultdict(list)
        for a, b in adjacentPairs:
            g[a].append(b)
            g[b].append(a)
        i = next(i for i, v in g.items() if len(v) == 1)
        ans = []
        dfs(i, 1e6)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private int[] ans;

    public int[] restoreArray(int[][] adjacentPairs) {
        for (var e : adjacentPairs) {
            int a = e[0], b = e[1];
            g.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
            g.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
        }
        int n = adjacentPairs.length + 1;
        ans = new int[n];
        for (var e : g.entrySet()) {
            if (e.getValue().size() == 1) {
                dfs(e.getKey(), 1000000, 0);
                break;
            }
        }
        return ans;
    }

    private void dfs(int i, int fa, int k) {
        ans[k++] = i;
        for (int j : g.get(i)) {
            if (j != fa) {
                dfs(j, i, k);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> g;
        for (auto& e : adjacentPairs) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        int n = adjacentPairs.size() + 1;
        vector<int> ans;
        function<void(int, int)> dfs = [&](int i, int fa) {
            ans.emplace_back(i);
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs(j, i);
                }
            }
        };
        for (auto& [i, v] : g) {
            if (v.size() == 1) {
                dfs(i, 1e6);
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func restoreArray(adjacentPairs [][]int) []int {
	g := map[int][]int{}
	for _, e := range adjacentPairs {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := []int{}
	var dfs func(i, fa int)
	dfs = func(i, fa int) {
		ans = append(ans, i)
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i)
			}
		}
	}
	for i, v := range g {
		if len(v) == 1 {
			dfs(i, 1000000)
			break
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] RestoreArray(int[][] adjacentPairs) {
        int n = adjacentPairs.Length + 1;
        Dictionary<int, List<int>> g = new Dictionary<int, List<int>>();

        foreach (int[] e in adjacentPairs) {
            int a = e[0], b = e[1];
            if (!g.ContainsKey(a)) {
                g[a] = new List<int>();
            }
            if (!g.ContainsKey(b)) {
                g[b] = new List<int>();
            }
            g[a].Add(b);
            g[b].Add(a);
        }

        int[] ans = new int[n];

        foreach (var entry in g) {
            if (entry.Value.Count == 1) {
                ans[0] = entry.Key;
                ans[1] = entry.Value[0];
                break;
            }
        }

        for (int i = 2; i < n; ++i) {
            List<int> v = g[ans[i - 1]];
            ans[i] = v[1] == ans[i - 2] ? v[0] : v[1];
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

<p>存在一个由 <code>n</code> 个不同元素组成的整数数组 <code>nums</code> ，但你已经记不清具体内容。好在你还记得 <code>nums</code> 中的每一对相邻元素。</p>

<p>给你一个二维整数数组 <code>adjacentPairs</code> ，大小为 <code>n - 1</code> ，其中每个 <code>adjacentPairs[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示元素 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 在 <code>nums</code> 中相邻。</p>

<p>题目数据保证所有由元素 <code>nums[i]</code> 和 <code>nums[i+1]</code> 组成的相邻元素对都存在于 <code>adjacentPairs</code> 中，存在形式可能是 <code>[nums[i], nums[i+1]]</code> ，也可能是 <code>[nums[i+1], nums[i]]</code> 。这些相邻元素对可以 <strong>按任意顺序</strong> 出现。</p>

<p>返回 <strong>原始数组</strong><em> </em><code>nums</code><em> </em>。如果存在多种解答，返回 <strong>其中任意一个</strong> 即可。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>adjacentPairs = [[2,1],[3,4],[3,2]]
<strong>输出：</strong>[1,2,3,4]
<strong>解释：</strong>数组的所有相邻元素对都在 adjacentPairs 中。
特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>adjacentPairs = [[4,-2],[1,4],[-3,1]]
<strong>输出：</strong>[-2,4,1,-3]
<strong>解释：</strong>数组中可能存在负数。
另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>adjacentPairs = [[100000,-100000]]
<strong>输出：</strong>[100000,-100000]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>adjacentPairs.length == n - 1</code></li>
	<li><code>adjacentPairs[i].length == 2</code></li>
	<li><code>2 <= n <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> <= nums[i], u<sub>i</sub>, v<sub>i</sub> <= 10<sup>5</sup></code></li>
	<li>题目数据保证存在一些以 <code>adjacentPairs</code> 作为元素对的数组 <code>nums</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

从度为一的点开始遍历图，可以用 DFS，也可以直接遍历。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        for a, b in adjacentPairs:
            g[a].append(b)
            g[b].append(a)
        n = len(adjacentPairs) + 1
        ans = [0] * n
        for i, v in g.items():
            if len(v) == 1:
                ans[0] = i
                ans[1] = v[0]
                break
        for i in range(2, n):
            v = g[ans[i - 1]]
            ans[i] = v[0] if v[1] == ans[i - 2] else v[1]
        return ans
```

#### Java

```java
class Solution {
    public int[] restoreArray(int[][] adjacentPairs) {
        int n = adjacentPairs.length + 1;
        Map<Integer, List<Integer>> g = new HashMap<>();
        for (int[] e : adjacentPairs) {
            int a = e[0], b = e[1];
            g.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
            g.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
        }
        int[] ans = new int[n];
        for (Map.Entry<Integer, List<Integer>> entry : g.entrySet()) {
            if (entry.getValue().size() == 1) {
                ans[0] = entry.getKey();
                ans[1] = entry.getValue().get(0);
                break;
            }
        }
        for (int i = 2; i < n; ++i) {
            List<Integer> v = g.get(ans[i - 1]);
            ans[i] = v.get(1) == ans[i - 2] ? v.get(0) : v.get(1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int, vector<int>> g;
        for (auto& e : adjacentPairs) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans(n);
        for (auto& [k, v] : g) {
            if (v.size() == 1) {
                ans[0] = k;
                ans[1] = v[0];
                break;
            }
        }
        for (int i = 2; i < n; ++i) {
            auto v = g[ans[i - 1]];
            ans[i] = v[0] == ans[i - 2] ? v[1] : v[0];
        }
        return ans;
    }
};
```

#### Go

```go
func restoreArray(adjacentPairs [][]int) []int {
	n := len(adjacentPairs) + 1
	g := map[int][]int{}
	for _, e := range adjacentPairs {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int, n)
	for k, v := range g {
		if len(v) == 1 {
			ans[0] = k
			ans[1] = v[0]
			break
		}
	}
	for i := 2; i < n; i++ {
		v := g[ans[i-1]]
		ans[i] = v[0]
		if v[0] == ans[i-2] {
			ans[i] = v[1]
		}
	}
	return ans
}
```

#### C#

```cs
public class Solution {
    public int[] RestoreArray(int[][] adjacentPairs) {
        int n = adjacentPairs.Length + 1;
        Dictionary<int, List<int>> g = new Dictionary<int, List<int>>();

        foreach (int[] e in adjacentPairs) {
            int a = e[0], b = e[1];
            if (!g.ContainsKey(a)) {
                g[a] = new List<int>();
            }
            if (!g.ContainsKey(b)) {
                g[b] = new List<int>();
            }
            g[a].Add(b);
            g[b].Add(a);
        }

        int[] ans = new int[n];

        foreach (var entry in g) {
            if (entry.Value.Count == 1) {
                ans[0] = entry.Key;
                ans[1] = entry.Value[0];
                break;
            }
        }

        for (int i = 2; i < n; ++i) {
            List<int> v = g[ans[i - 1]];
            ans[i] = v[1] == ans[i - 2] ? v[0] : v[1];
        }

        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        def dfs(i, fa):
            ans.append(i)
            for j in g[i]:
                if j != fa:
                    dfs(j, i)

        g = defaultdict(list)
        for a, b in adjacentPairs:
            g[a].append(b)
            g[b].append(a)
        i = next(i for i, v in g.items() if len(v) == 1)
        ans = []
        dfs(i, 1e6)
        return ans
```

#### Java

```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private int[] ans;

    public int[] restoreArray(int[][] adjacentPairs) {
        for (var e : adjacentPairs) {
            int a = e[0], b = e[1];
            g.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
            g.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
        }
        int n = adjacentPairs.length + 1;
        ans = new int[n];
        for (var e : g.entrySet()) {
            if (e.getValue().size() == 1) {
                dfs(e.getKey(), 1000000, 0);
                break;
            }
        }
        return ans;
    }

    private void dfs(int i, int fa, int k) {
        ans[k++] = i;
        for (int j : g.get(i)) {
            if (j != fa) {
                dfs(j, i, k);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> g;
        for (auto& e : adjacentPairs) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        int n = adjacentPairs.size() + 1;
        vector<int> ans;
        function<void(int, int)> dfs = [&](int i, int fa) {
            ans.emplace_back(i);
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs(j, i);
                }
            }
        };
        for (auto& [i, v] : g) {
            if (v.size() == 1) {
                dfs(i, 1e6);
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func restoreArray(adjacentPairs [][]int) []int {
	g := map[int][]int{}
	for _, e := range adjacentPairs {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := []int{}
	var dfs func(i, fa int)
	dfs = func(i, fa int) {
		ans = append(ans, i)
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i)
			}
		}
	}
	for i, v := range g {
		if len(v) == 1 {
			dfs(i, 1000000)
			break
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？](https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day){#1744}

{{< tabs "1744" >}}

{{% tab "python" %}}
```python
class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        s = list(accumulate(candiesCount, initial=0))
        ans = []
        for t, day, mx in queries:
            least, most = day, (day + 1) * mx
            ans.append(least < s[t + 1] and most > s[t])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        int n = candiesCount.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + candiesCount[i];
        }
        int m = queries.length;
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            int t = queries[i][0], day = queries[i][1], mx = queries[i][2];
            long least = day, most = (long) (day + 1) * mx;
            ans[i] = least < s[t + 1] && most > s[t];
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<ll> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + candiesCount[i];
        vector<bool> ans;
        for (auto& q : queries) {
            int t = q[0], day = q[1], mx = q[2];
            ll least = day, most = 1ll * (day + 1) * mx;
            ans.emplace_back(least < s[t + 1] && most > s[t]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canEat(candiesCount []int, queries [][]int) (ans []bool) {
	n := len(candiesCount)
	s := make([]int, n+1)
	for i, v := range candiesCount {
		s[i+1] = s[i] + v
	}
	for _, q := range queries {
		t, day, mx := q[0], q[1], q[2]
		least, most := day, (day+1)*mx
		ans = append(ans, least < s[t+1] && most > s[t])
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的正整数数组 <code>candiesCount</code> ，其中 <code>candiesCount[i]</code> 表示你拥有的第 <code>i</code> 类糖果的数目。同时给你一个二维数组 <code>queries</code> ，其中 <code>queries[i] = [favoriteType<sub>i</sub>, favoriteDay<sub>i</sub>, dailyCap<sub>i</sub>]</code> 。</p>

<p>你按照如下规则进行一场游戏：</p>

<ul>
	<li>你从第 <code><strong>0</strong></code><strong> </strong>天开始吃糖果。</li>
	<li>你在吃完 <strong>所有</strong> 第 <code>i - 1</code> 类糖果之前，<strong>不能</strong> 吃任何一颗第 <code>i</code> 类糖果。</li>
	<li>在吃完所有糖果之前，你必须每天 <strong>至少</strong> 吃 <strong>一颗</strong> 糖果。</li>
</ul>

<p>请你构建一个布尔型数组 <code>answer</code> ，用以给出 <code>queries</code> 中每一项的对应答案。此数组满足：</p>

<ul>
	<li><code>answer.length == queries.length</code> 。<code>answer[i]</code> 是 <code>queries[i]</code> 的答案。</li>
	<li><code>answer[i]</code> 为 <code>true</code> 的条件是：在每天吃 <strong>不超过</strong> <code>dailyCap<sub>i</sub></code><sub> </sub>颗糖果的前提下，你可以在第 <code>favoriteDay<sub>i</sub></code> 天吃到第 <code>favoriteType<sub>i</sub></code> 类糖果；否则 <code>answer[i]</code> 为 <code>false</code> 。</li>
</ul>

<p>注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。</p>

<p>请你返回得到的数组<em> </em><code>answer</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
<b>输出：</b>[true,false,true]
<strong>提示：</strong>
1- 在第 0 天吃 2 颗糖果(类型 0），第 1 天吃 2 颗糖果（类型 0），第 2 天你可以吃到类型 0 的糖果。
2- 每天你最多吃 4 颗糖果。即使第 0 天吃 4 颗糖果（类型 0），第 1 天吃 4 颗糖果（类型 0 和类型 1），你也没办法在第 2 天吃到类型 4 的糖果。换言之，你没法在每天吃 4 颗糖果的限制下在第 2 天吃到第 4 类糖果。
3- 如果你每天吃 1 颗糖果，你可以在第 13 天吃到类型 2 的糖果。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
<b>输出：</b>[false,true,true,false,false]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= candiesCount.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= candiesCount[i] <= 10<sup>5</sup></code></li>
	<li><code>1 <= queries.length <= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 3</code></li>
	<li><code>0 <= favoriteType<sub>i</sub> < candiesCount.length</code></li>
	<li><code>0 <= favoriteDay<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>1 <= dailyCap<sub>i</sub> <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `candiesCount` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        s = list(accumulate(candiesCount, initial=0))
        ans = []
        for t, day, mx in queries:
            least, most = day, (day + 1) * mx
            ans.append(least < s[t + 1] and most > s[t])
        return ans
```

#### Java

```java
class Solution {
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        int n = candiesCount.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + candiesCount[i];
        }
        int m = queries.length;
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            int t = queries[i][0], day = queries[i][1], mx = queries[i][2];
            long least = day, most = (long) (day + 1) * mx;
            ans[i] = least < s[t + 1] && most > s[t];
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<ll> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + candiesCount[i];
        vector<bool> ans;
        for (auto& q : queries) {
            int t = q[0], day = q[1], mx = q[2];
            ll least = day, most = 1ll * (day + 1) * mx;
            ans.emplace_back(least < s[t + 1] && most > s[t]);
        }
        return ans;
    }
};
```

#### Go

```go
func canEat(candiesCount []int, queries [][]int) (ans []bool) {
	n := len(candiesCount)
	s := make([]int, n+1)
	for i, v := range candiesCount {
		s[i+1] = s[i] + v
	}
	for _, q := range queries {
		t, day, mx := q[0], q[1], q[2]
		least, most := day, (day+1)*mx
		ans = append(ans, least < s[t+1] && most > s[t])
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1745. 分割回文串 IV](https://leetcode.cn/problems/palindrome-partitioning-iv){#1745}

{{< tabs "1745" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        f = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = s[i] == s[j] and (i + 1 == j or f[i + 1][j - 1])
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                if f[0][i] and f[i + 1][j] and f[j + 1][-1]:
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        boolean[][] f = new boolean[n][n];
        for (var g : f) {
            Arrays.fill(g, true);
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s.charAt(i) == s.charAt(j) && (i + 1 == j || f[i + 1][j - 1]);
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s[i] == s[j] && (i + 1 == j || f[i + 1][j - 1]);
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkPartitioning(s string) bool {
	n := len(s)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
		for j := range f[i] {
			f[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = s[i] == s[j] && (i+1 == j || f[i+1][j-1])
		}
	}
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			if f[0][i] && f[i+1][j] && f[j+1][n-1] {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkPartitioning(s: string): boolean {
    const n = s.length;
    const f: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = s[i] === s[j] && f[i + 1][j - 1];
        }
    }
    for (let i = 0; i < n - 2; ++i) {
        for (let j = i + 1; j < n - 1; ++j) {
            if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                return true;
            }
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，如果可以将它分割成三个 <strong>非空</strong> 回文子字符串，那么返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>当一个字符串正着读和反着读是一模一样的，就称其为 <strong>回文字符串</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abcbdd"
<b>输出：</b>true
<strong>解释：</strong>"abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "bcbddxy"
<b>输出：</b>false
<strong>解释：</strong>s 没办法被分割成 3 个回文子字符串。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= s.length <= 2000</code></li>
	<li><code>s</code>​​​​​​ 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示字符串 $s$ 的第 $i$ 个字符到第 $j$ 个字符是否为回文串，初始时 $f[i][j] = \textit{true}$。

然后我们可以通过以下的状态转移方程来计算 $f[i][j]$：

$$
f[i][j] = \begin{cases}
\textit{true}, & \text{if } s[i] = s[j] \text{ and } (i + 1 = j \text{ or } f[i + 1][j - 1]) \\
\textit{false}, & \text{otherwise}
\end{cases}
$$

由于 $f[i][j]$ 依赖于 $f[i + 1][j - 1]$，因此，我们需要从大到小的顺序枚举 $i$，从小到大的顺序枚举 $j$，这样才能保证当计算 $f[i][j]$ 时 $f[i + 1][j - 1]$ 已经被计算过。

接下来，我们枚举第一个子串的右端点 $i$，第二个子串的右端点 $j$，那么第三个子串的左端点可以枚举的范围为 $[j + 1, n - 1]$，其中 $n$ 是字符串 $s$ 的长度。如果第一个子串 $s[0..i]$、第二个子串 $s[i+1..j]$ 和第三个子串 $s[j+1..n-1]$ 都是回文串，那么我们就找到了一种可行的分割方案，返回 $\textit{true}$。

枚举完所有的分割方案后，如果没有找到符合要求的分割方案，那么返回 $\textit{false}$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        f = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = s[i] == s[j] and (i + 1 == j or f[i + 1][j - 1])
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                if f[0][i] and f[i + 1][j] and f[j + 1][-1]:
                    return True
        return False
```

#### Java

```java
class Solution {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        boolean[][] f = new boolean[n][n];
        for (var g : f) {
            Arrays.fill(g, true);
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s.charAt(i) == s.charAt(j) && (i + 1 == j || f[i + 1][j - 1]);
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s[i] == s[j] && (i + 1 == j || f[i + 1][j - 1]);
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func checkPartitioning(s string) bool {
	n := len(s)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
		for j := range f[i] {
			f[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = s[i] == s[j] && (i+1 == j || f[i+1][j-1])
		}
	}
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			if f[0][i] && f[i+1][j] && f[j+1][n-1] {
				return true
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function checkPartitioning(s: string): boolean {
    const n = s.length;
    const f: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = s[i] === s[j] && f[i + 1][j - 1];
        }
    }
    for (let i = 0; i < n - 2; ++i) {
        for (let j = i + 1; j < n - 1; ++j) {
            if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                return true;
            }
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1746. 经过一次操作后的最大子数组和 🔒](https://leetcode.cn/problems/maximum-subarray-sum-after-one-operation){#1746}

{{< tabs "1746" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumAfterOperation(self, nums: List[int]) -> int:
        f = g = 0
        ans = -inf
        for x in nums:
            ff = max(f, 0) + x
            gg = max(max(f, 0) + x * x, g + x)
            f, g = ff, gg
            ans = max(ans, f, g)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumAfterOperation(int[] nums) {
        int f = 0, g = 0;
        int ans = Integer.MIN_VALUE;
        for (int x : nums) {
            int ff = Math.max(f, 0) + x;
            int gg = Math.max(Math.max(f, 0) + x * x, g + x);
            f = ff;
            g = gg;
            ans = Math.max(ans, Math.max(f, g));
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
    int maxSumAfterOperation(vector<int>& nums) {
        int f = 0, g = 0;
        int ans = INT_MIN;
        for (int x : nums) {
            int ff = max(f, 0) + x;
            int gg = max(max(f, 0) + x * x, g + x);
            f = ff;
            g = gg;
            ans = max({ans, f, g});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumAfterOperation(nums []int) int {
	var f, g int
	ans := -(1 << 30)
	for _, x := range nums {
		ff := max(f, 0) + x
		gg := max(max(f, 0)+x*x, g+x)
		f, g = ff, gg
		ans = max(ans, max(f, g))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn max_sum_after_operation(nums: Vec<i32>) -> i32 {
        // Here f[i] represents the value of max sub-array that ends with nums[i] with no substitution
        let mut f = 0;
        // g[i] represents the case with exact one substitution
        let mut g = 0;
        let mut ret = 1 << 31;

        // Begin the actual dp process
        for e in &nums {
            // f[i] = MAX(f[i - 1], 0) + nums[i]
            let new_f = std::cmp::max(f, 0) + *e;
            // g[i] = MAX(MAX(f[i - 1], 0) + nums[i] * nums[i], g[i - 1] + nums[i])
            let new_g = std::cmp::max(std::cmp::max(f, 0) + *e * *e, g + *e);
            // Update f[i] & g[i]
            f = new_f;
            g = new_g;
            // Since we start at 0, update answer after updating f[i] & g[i]
            ret = std::cmp::max(ret, g);
        }

        ret
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个整数数组 <code>nums</code>。你只能将一个元素 <code>nums[i]</code> 替换为 <code>nums[i] * nums[i]</code>。</p>

<p>返回替换后的最大子数组和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,-1,-4,-3]
<strong>输出：</strong>17
<strong>解释：</strong>你可以把-4替换为16(-4*(-4))，使nums = [2,-1,<strong>16</strong>,-3]. 现在，最大子数组和为 2 + -1 + 16 = 17.</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-1,1,1,-1,-1,1]
<strong>输出：</strong>4
<strong>解释：</strong>你可以把第一个-1替换为1，使 nums = [1,<strong>1</strong>,1,1,-1,-1,1]. 现在，最大子数组和为 1 + 1 + 1 + 1 = 4.</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以 $nums[i]$ 结尾，且没有进行替换的最大子数组和，另外定义 $g[i]$ 表示以 $nums[i]$ 结尾，且进行了替换的最大子数组和。那么有如下状态转移方程：

$$
\begin{aligned}
f[i] &= \max(f[i - 1], 0) + nums[i] \\
g[i] &= \max(\max(f[i - 1], 0) + nums[i] \times nums[i], g[i - 1] + nums[i])
\end{aligned}
$$

最终答案即为所有 $max(f[i], g[i])$ 的最大值。

由于 $f[i]$ 只与 $f[i - 1]$ 有关，因此我们可以只用两个变量来维护 $f[i]$ 和 $g[i]$ 的值，从而将空间复杂度降低到 $O(1)$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumAfterOperation(self, nums: List[int]) -> int:
        f = g = 0
        ans = -inf
        for x in nums:
            ff = max(f, 0) + x
            gg = max(max(f, 0) + x * x, g + x)
            f, g = ff, gg
            ans = max(ans, f, g)
        return ans
```

#### Java

```java
class Solution {
    public int maxSumAfterOperation(int[] nums) {
        int f = 0, g = 0;
        int ans = Integer.MIN_VALUE;
        for (int x : nums) {
            int ff = Math.max(f, 0) + x;
            int gg = Math.max(Math.max(f, 0) + x * x, g + x);
            f = ff;
            g = gg;
            ans = Math.max(ans, Math.max(f, g));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int f = 0, g = 0;
        int ans = INT_MIN;
        for (int x : nums) {
            int ff = max(f, 0) + x;
            int gg = max(max(f, 0) + x * x, g + x);
            f = ff;
            g = gg;
            ans = max({ans, f, g});
        }
        return ans;
    }
};
```

#### Go

```go
func maxSumAfterOperation(nums []int) int {
	var f, g int
	ans := -(1 << 30)
	for _, x := range nums {
		ff := max(f, 0) + x
		gg := max(max(f, 0)+x*x, g+x)
		f, g = ff, gg
		ans = max(ans, max(f, g))
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn max_sum_after_operation(nums: Vec<i32>) -> i32 {
        // Here f[i] represents the value of max sub-array that ends with nums[i] with no substitution
        let mut f = 0;
        // g[i] represents the case with exact one substitution
        let mut g = 0;
        let mut ret = 1 << 31;

        // Begin the actual dp process
        for e in &nums {
            // f[i] = MAX(f[i - 1], 0) + nums[i]
            let new_f = std::cmp::max(f, 0) + *e;
            // g[i] = MAX(MAX(f[i - 1], 0) + nums[i] * nums[i], g[i - 1] + nums[i])
            let new_g = std::cmp::max(std::cmp::max(f, 0) + *e * *e, g + *e);
            // Update f[i] & g[i]
            f = new_f;
            g = new_g;
            // Since we start at 0, update answer after updating f[i] & g[i]
            ret = std::cmp::max(ret, g);
        }

        ret
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1747. 应该被禁止的 Leetflex 账户 🔒](https://leetcode.cn/problems/leetflex-banned-accounts){#1747}

{{< tabs "1747" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT
    a.account_id
FROM
    LogInfo AS a
    JOIN LogInfo AS b
        ON a.account_id = b.account_id
        AND a.ip_address != b.ip_address
        AND a.login BETWEEN b.login AND b.logout;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>LogInfo</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| account_id  | int      |
| ip_address  | int      |
| login       | datetime |
| logout      | datetime |
+-------------+----------+
该表可能包含重复项。
该表包含有关Leetflex帐户的登录和注销日期的信息。 它还包含了该账户用于登录和注销的网络地址的信息。
题目确保每一个注销时间都在登录时间之后。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，查找那些应该被禁止的Leetflex帐户编号 <code>account_id</code> 。 如果某个帐户在某一时刻从两个不同的网络地址登录了，则这个帐户应该被禁止。</p>

<p>可以以 <strong>任何顺序 </strong>返回结果。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
LogInfo table:
+------------+------------+---------------------+---------------------+
| account_id | ip_address | login               | logout              |
+------------+------------+---------------------+---------------------+
| 1          | 1          | 2021-02-01 09:00:00 | 2021-02-01 09:30:00 |
| 1          | 2          | 2021-02-01 08:00:00 | 2021-02-01 11:30:00 |
| 2          | 6          | 2021-02-01 20:30:00 | 2021-02-01 22:00:00 |
| 2          | 7          | 2021-02-02 20:30:00 | 2021-02-02 22:00:00 |
| 3          | 9          | 2021-02-01 16:00:00 | 2021-02-01 16:59:59 |
| 3          | 13         | 2021-02-01 17:00:00 | 2021-02-01 17:59:59 |
| 4          | 10         | 2021-02-01 16:00:00 | 2021-02-01 17:00:00 |
| 4          | 11         | 2021-02-01 17:00:00 | 2021-02-01 17:59:59 |
+------------+------------+---------------------+---------------------+
<strong>输出：
</strong>+------------+
| account_id |
+------------+
| 1          |
| 4          |
+------------+
<strong>解释：</strong>
Account ID 1 --&gt; 该账户从 "2021-02-01 09:00:00" 到 "2021-02-01 09:30:00" 在两个不同的网络地址(1 and 2)上激活了。它应该被禁止.
Account ID 2 --&gt; 该账户在两个不同的网络地址 (6, 7) 激活了，但在不同的时间上.
Account ID 3 --&gt; 该账户在两个不同的网络地址 (9, 13) 激活了，虽然是同一天，但时间上没有交集.
Account ID 4 --&gt; 该账户从 "2021-02-01 17:00:00" 到 "2021-02-01 17:00:00" 在两个不同的网络地址 (10 and 11)上激活了。它应该被禁止.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接

我们可以通过自连接的方式，找出每个账户在同一天内，从不同的网络地址登录的情况。连接的条件是：

-   账户编号相同
-   网络地址不同
-   一次登录的时间在另一次“登录-退出”的时间范围内

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT
    a.account_id
FROM
    LogInfo AS a
    JOIN LogInfo AS b
        ON a.account_id = b.account_id
        AND a.ip_address != b.ip_address
        AND a.login BETWEEN b.login AND b.logout;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1748. 唯一元素的和](https://leetcode.cn/problems/sum-of-unique-elements){#1748}

{{< tabs "1748" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return sum(x for x, v in cnt.items() if v == 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfUnique(int[] nums) {
        int ans = 0;
        int[] cnt = new int[101];
        for (int x : nums) {
            if (++cnt[x] == 1) {
                ans += x;
            } else if (cnt[x] == 2) {
                ans -= x;
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
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        int cnt[101]{};
        for (int& x : nums) {
            if (++cnt[x] == 1) {
                ans += x;
            } else if (cnt[x] == 2) {
                ans -= x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfUnique(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] == 1 {
			ans += x
		} else if cnt[x] == 2 {
			ans -= x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfUnique(nums: number[]): number {
    let ans = 0;
    const cnt = new Array(101).fill(0);
    for (const x of nums) {
        if (++cnt[x] === 1) {
            ans += x;
        } else if (cnt[x] === 2) {
            ans -= x;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut map = HashMap::new();
        for num in nums {
            if map.contains_key(&num) {
                if *map.get(&num).unwrap() {
                    map.insert(num, false);
                    res -= num;
                }
            } else {
                map.insert(num, true);
                res += num;
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function sumOfUnique($nums) {
        $sum = 0;
        for ($i = 0; $i < count($nums); $i++) {
            $hashtable[$nums[$i]] += 1;
            if ($hashtable[$nums[$i]] == 1) {
                $sum += $nums[$i];
            }
            if ($hashtable[$nums[$i]] == 2) {
                $sum -= $nums[$i];
            }
        }
        return $sum;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 。数组中唯一元素是那些只出现 <strong>恰好一次</strong> 的元素。</p>

<p>请你返回 <code>nums</code> 中唯一元素的 <strong>和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,2]
<b>输出：</b>4
<b>解释：</b>唯一元素为 [1,3] ，和为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,1,1,1,1]
<b>输出：</b>0
<b>解释：</b>没有唯一元素，和为 0 。
</pre>

<p><strong>示例 3 ：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>15
<b>解释：</b>唯一元素为 [1,2,3,4,5] ，和为 15 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用数组或哈希表 `cnt` 统计数组 `nums` 中每个数字出现的次数，然后遍历 `cnt`，对于出现次数为 1 的数字，将其加入答案。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(M)$。其中 $n$ 和 $m$ 分别是数组 `nums` 的长度和 `nums` 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return sum(x for x, v in cnt.items() if v == 1)
```

#### Java

```java
class Solution {
    public int sumOfUnique(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 0; x < 101; ++x) {
            if (cnt[x] == 1) {
                ans += x;
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
    int sumOfUnique(vector<int>& nums) {
        int cnt[101]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (int x = 0; x < 101; ++x) {
            if (cnt[x] == 1) {
                ans += x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfUnique(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x := 0; x < 101; x++ {
		if cnt[x] == 1 {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function sumOfUnique(nums: number[]): number {
    const cnt = new Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    let ans = 0;
    for (let x = 0; x < 101; ++x) {
        if (cnt[x] == 1) {
            ans += x;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        let mut cnt = [0; 101];
        for x in nums {
            cnt[x as usize] += 1;
        }
        let mut ans = 0;
        for x in 1..101 {
            if cnt[x] == 1 {
                ans += x;
            }
        }
        ans as i32
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function sumOfUnique($nums) {
        $sum = 0;
        for ($i = 0; $i < count($nums); $i++) {
            $hashtable[$nums[$i]] += 1;
            if ($hashtable[$nums[$i]] == 1) {
                $sum += $nums[$i];
            }
            if ($hashtable[$nums[$i]] == 2) {
                $sum -= $nums[$i];
            }
        }
        return $sum;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int sumOfUnique(int[] nums) {
        int ans = 0;
        int[] cnt = new int[101];
        for (int x : nums) {
            if (++cnt[x] == 1) {
                ans += x;
            } else if (cnt[x] == 2) {
                ans -= x;
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
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        int cnt[101]{};
        for (int& x : nums) {
            if (++cnt[x] == 1) {
                ans += x;
            } else if (cnt[x] == 2) {
                ans -= x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfUnique(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] == 1 {
			ans += x
		} else if cnt[x] == 2 {
			ans -= x
		}
	}
	return
}
```

#### TypeScript

```ts
function sumOfUnique(nums: number[]): number {
    let ans = 0;
    const cnt = new Array(101).fill(0);
    for (const x of nums) {
        if (++cnt[x] === 1) {
            ans += x;
        } else if (cnt[x] === 2) {
            ans -= x;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut map = HashMap::new();
        for num in nums {
            if map.contains_key(&num) {
                if *map.get(&num).unwrap() {
                    map.insert(num, false);
                    res -= num;
                }
            } else {
                map.insert(num, true);
                res += num;
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1749. 任意子数组和的绝对值的最大值](https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray){#1749}

{{< tabs "1749" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        f = g = 0
        ans = 0
        for x in nums:
            f = max(f, 0) + x
            g = min(g, 0) + x
            ans = max(ans, f, abs(g))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int f = 0, g = 0;
        int ans = 0;
        for (int x : nums) {
            f = Math.max(f, 0) + x;
            g = Math.min(g, 0) + x;
            ans = Math.max(ans, Math.max(f, Math.abs(g)));
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
    int maxAbsoluteSum(vector<int>& nums) {
        int f = 0, g = 0;
        int ans = 0;
        for (int& x : nums) {
            f = max(f, 0) + x;
            g = min(g, 0) + x;
            ans = max({ans, f, abs(g)});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAbsoluteSum(nums []int) (ans int) {
	var f, g int
	for _, x := range nums {
		f = max(f, 0) + x
		g = min(g, 0) + x
		ans = max(ans, max(f, abs(g)))
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
function maxAbsoluteSum(nums: number[]): number {
    let f = 0;
    let g = 0;
    let ans = 0;
    for (const x of nums) {
        f = Math.max(f, 0) + x;
        g = Math.min(g, 0) + x;
        ans = Math.max(ans, f, -g);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_absolute_sum(nums: Vec<i32>) -> i32 {
        let mut f = 0;
        let mut g = 0;
        let mut ans = 0;
        for x in nums {
            f = i32::max(f, 0) + x;
            g = i32::min(g, 0) + x;
            ans = i32::max(ans, f.max(-g));
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

<p>给你一个整数数组 <code>nums</code> 。一个子数组 <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> 的 <strong>和的绝对值</strong> 为 <code>abs(nums<sub>l</sub> + nums<sub>l+1</sub> + ... + nums<sub>r-1</sub> + nums<sub>r</sub>)</code> 。</p>

<p>请你找出 <code>nums</code> 中 <strong>和的绝对值</strong> 最大的任意子数组（<b>可能为空</b>），并返回该 <strong>最大值</strong> 。</p>

<p><code>abs(x)</code> 定义如下：</p>

<ul>
	<li>如果 <code>x</code> 是负整数，那么 <code>abs(x) = -x</code> 。</li>
	<li>如果 <code>x</code> 是非负整数，那么 <code>abs(x) = x</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,-3,2,3,-4]
<b>输出：</b>5
<b>解释：</b>子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,-5,1,-4,3,-2]
<b>输出：</b>8
<b>解释：</b>子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以 $nums[i]$ 结尾的子数组的和的最大值，定义 $g[i]$ 表示以 $nums[i]$ 结尾的子数组的和的最小值。那么 $f[i]$ 和 $g[i]$ 的状态转移方程如下：

$$
\begin{aligned}
f[i] &= \max(f[i - 1], 0) + nums[i] \\
g[i] &= \min(g[i - 1], 0) + nums[i]
\end{aligned}
$$

最后答案为 $max(f[i], |g[i]|)$ 的最大值。

由于 $f[i]$ 和 $g[i]$ 只与 $f[i - 1]$ 和 $g[i - 1]$ 有关，因此我们可以使用两个变量代替数组，将空间复杂度降低到 $O(1)$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        f = g = 0
        ans = 0
        for x in nums:
            f = max(f, 0) + x
            g = min(g, 0) + x
            ans = max(ans, f, abs(g))
        return ans
```

#### Java

```java
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int f = 0, g = 0;
        int ans = 0;
        for (int x : nums) {
            f = Math.max(f, 0) + x;
            g = Math.min(g, 0) + x;
            ans = Math.max(ans, Math.max(f, Math.abs(g)));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int f = 0, g = 0;
        int ans = 0;
        for (int& x : nums) {
            f = max(f, 0) + x;
            g = min(g, 0) + x;
            ans = max({ans, f, abs(g)});
        }
        return ans;
    }
};
```

#### Go

```go
func maxAbsoluteSum(nums []int) (ans int) {
	var f, g int
	for _, x := range nums {
		f = max(f, 0) + x
		g = min(g, 0) + x
		ans = max(ans, max(f, abs(g)))
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
function maxAbsoluteSum(nums: number[]): number {
    let f = 0;
    let g = 0;
    let ans = 0;
    for (const x of nums) {
        f = Math.max(f, 0) + x;
        g = Math.min(g, 0) + x;
        ans = Math.max(ans, f, -g);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_absolute_sum(nums: Vec<i32>) -> i32 {
        let mut f = 0;
        let mut g = 0;
        let mut ans = 0;
        for x in nums {
            f = i32::max(f, 0) + x;
            g = i32::min(g, 0) + x;
            ans = i32::max(ans, f.max(-g));
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
