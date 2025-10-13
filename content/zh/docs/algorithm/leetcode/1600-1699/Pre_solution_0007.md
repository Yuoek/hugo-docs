---
title: "1660_纠正二叉树 🔒"
date: 2025-10-08T18:38:12+08:00
weight: 7
tags: [二叉树, 前缀和, 动态规划, 哈希表, 字符串, 字符串匹配, 广度优先搜索, 排序, 数据库, 数组, 树, 深度优先搜索, 贪心, 链表]
---

{{< markmap >}}
### [1660_纠正二叉树 🔒](#1660)
#### [树](#1660)
#### [深度优先搜索](#1660)
#### [广度优先搜索](#1660)
#### [哈希表](#1660)
#### [二叉树](#1660)
### [1661_每台机器的进程平均运行时间](#1661)
#### [数据库](#1661)
### [1662_检查两个字符串数组是否相等](#1662)
#### [数组](#1662)
#### [字符串](#1662)
### [1663_具有给定数值的最小字符串](#1663)
#### [贪心](#1663)
#### [字符串](#1663)
### [1664_生成平衡数组的方案数](#1664)
#### [数组](#1664)
#### [前缀和](#1664)
### [1665_完成所有任务的最少初始能量](#1665)
#### [贪心](#1665)
#### [数组](#1665)
#### [排序](#1665)
### [1666_改变二叉树的根节点 🔒](#1666)
#### [树](#1666)
#### [深度优先搜索](#1666)
#### [二叉树](#1666)
### [1667_修复表中的名字](#1667)
#### [数据库](#1667)
### [1668_最大重复子字符串](#1668)
#### [字符串](#1668)
#### [动态规划](#1668)
#### [字符串匹配](#1668)
### [1669_合并两个链表](#1669)
#### [链表](#1669)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1660_纠正二叉树 🔒
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
### 1661_每台机器的进程平均运行时间
___
#### 数据库
---
### 1662_检查两个字符串数组是否相等
___
#### 数组
___
#### 字符串
---
### 1663_具有给定数值的最小字符串
___
#### 贪心
___
#### 字符串
---
### 1664_生成平衡数组的方案数
___
#### 数组
___
#### 前缀和
---
### 1665_完成所有任务的最少初始能量
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1666_改变二叉树的根节点 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1667_修复表中的名字
___
#### 数据库
---
### 1668_最大重复子字符串
___
#### 字符串
___
#### 动态规划
___
#### 字符串匹配
---
### 1669_合并两个链表
___
#### 链表
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 前缀和 | 动态规划 |
| 哈希表 | 字符串 | 字符串匹配 |
| 广度优先搜索 | 排序 | 数据库 |
| 数组 | 树 | 深度优先搜索 |
| 贪心 | 链表 |  |

# [1660. 纠正二叉树 🔒](https://leetcode.cn/problems/correct-a-binary-tree){#1660}

{{< tabs "1660" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None or root.right in vis:
                return None
            vis.add(root)
            root.right = dfs(root.right)
            root.left = dfs(root.left)
            return root

        vis = set()
        return dfs(root)
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
    private Set<TreeNode> vis = new HashSet<>();

    public TreeNode correctBinaryTree(TreeNode root) {
        return dfs(root);
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null || vis.contains(root.right)) {
            return null;
        }
        vis.add(root);
        root.right = dfs(root.right);
        root.left = dfs(root.left);
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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> vis;
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) -> TreeNode* {
            if (!root || vis.count(root->right)) {
                return nullptr;
            }
            vis.insert(root);
            root->right = dfs(root->right);
            root->left = dfs(root->left);
            return root;
        };
        return dfs(root);
    }
};
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
 * @param {number} from
 * @param {number} to
 * @return {TreeNode}
 */
var correctBinaryTree = function (root) {
    const dfs = root => {
        if (!root || vis.has(root.right)) {
            return null;
        }
        vis.add(root);
        root.right = dfs(root.right);
        root.left = dfs(root.left);
        return root;
    };
    const vis = new Set();
    return dfs(root);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一棵二叉树，这棵二叉树有个小问题，其中<strong>有且只有一个</strong>无效节点，它的右子节点错误地指向了与其在<strong>同一层</strong>且在其<strong>右侧</strong>的一个其他节点。</p>

<p>给定一棵这样的问题二叉树的根节点 <code>root</code> ，将该无效节点<strong>及其所有子节点移除</strong>（除被错误指向的节点外），然后返回新二叉树的根结点。</p>

<p><b>自定义测试用例：</b></p>

<p>测试用例的输入由三行组成：</p>

<ul>
	<li><code>TreeNode root</code></li>
	<li><code>int fromNode</code> （在<strong> </strong><code>correctBinaryTree</code> 中<strong>不可见</strong>）</li>
	<li><code>int toNode</code> （在<strong> </strong><code>correctBinaryTree</code> 中<strong>不可见</strong>）</li>
</ul>

<p>当以 <code>root</code> 为根的二叉树被解析后，值为 <code>fromNode</code> 的节点 <code>TreeNode</code> 将其右子节点指向值为 <code>toNode</code> 的节点 <code>TreeNode</code> 。然后， <code>root</code> 传入 <code>correctBinaryTree</code> 的参数中。</p>

<p> </p>

<p><b>示例 1:</b></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1660.Correct%20a%20Binary%20Tree/images/ex1v2.png" style="width: 250px; height: 177px;" /></strong></p>

<pre>
<strong>输入:</strong> root = [1,2,3], fromNode = 2, toNode = 3
<strong>输出:</strong> [1,null,3]
<strong>解释:</strong> 值为 2 的节点是无效的，所以移除之。
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1660.Correct%20a%20Binary%20Tree/images/ex2v3.png" style="width: 350px; height: 255px;" /></strong></p>

<pre>
<strong>输入:</strong> root = [8,3,1,7,null,9,4,2,null,null,null,5,6], fromNode = 7, toNode = 4
<strong>输出:</strong> [8,3,1,null,null,9,4,null,null,5,6]
<strong>解释:</strong> 值为 7 的节点是无效的，所以移除这个节点及其子节点 2。
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点个数的范围是 <code>[3, 10<sup>4</sup>]</code> 。</li>
	<li><code>-10<sup>9</sup> <= Node.val <= 10<sup>9</sup></code></li>
	<li>所有的 <code>Node.val</code> 都是<strong>互不相同</strong>的。</li>
	<li><code>fromNode != toNode</code></li>
	<li><code>fromNode</code> 和 <code>toNode</code> 将出现在树中的同一层。</li>
	<li><code>toNode</code> 在 <code>fromNode</code> 的右侧。</li>
	<li><code>fromNode.right</code> 在测试用例的树中建立后为 <code>null</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root)$，用于处理以 $root$ 为根的子树。如果 $root$ 为 $null$ 或者 $root.right$ 已经被访问过，说明 $root$ 为无效节点，返回 $null$。否则，递归处理 $root.right$ 和 $root.left$，并返回 $root$。

最后，返回 $dfs(root)$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

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
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None or root.right in vis:
                return None
            vis.add(root)
            root.right = dfs(root.right)
            root.left = dfs(root.left)
            return root

        vis = set()
        return dfs(root)
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
    private Set<TreeNode> vis = new HashSet<>();

    public TreeNode correctBinaryTree(TreeNode root) {
        return dfs(root);
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null || vis.contains(root.right)) {
            return null;
        }
        vis.add(root);
        root.right = dfs(root.right);
        root.left = dfs(root.left);
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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> vis;
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) -> TreeNode* {
            if (!root || vis.count(root->right)) {
                return nullptr;
            }
            vis.insert(root);
            root->right = dfs(root->right);
            root->left = dfs(root->left);
            return root;
        };
        return dfs(root);
    }
};
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
 * @param {number} from
 * @param {number} to
 * @return {TreeNode}
 */
var correctBinaryTree = function (root) {
    const dfs = root => {
        if (!root || vis.has(root.right)) {
            return null;
        }
        vis.add(root);
        root.right = dfs(root.right);
        root.left = dfs(root.left);
        return root;
    };
    const vis = new Set();
    return dfs(root);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1661. 每台机器的进程平均运行时间](https://leetcode.cn/problems/average-time-of-process-per-machine){#1661}

{{< tabs "1661" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    machine_id,
    ROUND(AVG(IF(activity_type = 'start', -1, 1) * timestamp) * 2, 3) AS processing_time
FROM Activity
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Activity</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| machine_id     | int     |
| process_id     | int     |
| activity_type  | enum    |
| timestamp      | float   |
+----------------+---------+
该表展示了一家工厂网站的用户活动。
(machine_id, process_id, activity_type) 是当前表的主键（具有唯一值的列的组合）。
machine_id 是一台机器的ID号。
process_id 是运行在各机器上的进程ID号。
activity_type 是枚举类型 ('start', 'end')。
timestamp 是浮点类型,代表当前时间(以秒为单位)。
'start' 代表该进程在这台机器上的开始运行时间戳 , 'end' 代表该进程在这台机器上的终止运行时间戳。
同一台机器，同一个进程都有一对开始时间戳和结束时间戳，而且开始时间戳永远在结束时间戳前面。</pre>

<p>&nbsp;</p>

<p>现在有一个工厂网站由几台机器运行，每台机器上运行着 <strong>相同数量的进程</strong> 。编写解决方案，计算每台机器各自完成一个进程任务的平均耗时。</p>

<p>完成一个进程任务的时间指进程的<code>'end' 时间戳</code> 减去&nbsp;<code>'start' 时间戳</code>。平均耗时通过计算每台机器上所有进程任务的总耗费时间除以机器上的总进程数量获得。</p>

<p>结果表必须包含<code>machine_id（机器ID）</code> 和对应的&nbsp;<strong>average time（平均耗时）</strong>&nbsp;别名&nbsp;<code>processing_time</code>，且<strong>四舍五入保留3位小数。</strong></p>

<p>以 <strong>任意顺序</strong> 返回表。</p>

<p>具体参考例子如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Activity table:
+------------+------------+---------------+-----------+
| machine_id | process_id | activity_type | timestamp |
+------------+------------+---------------+-----------+
| 0          | 0          | start         | 0.712     |
| 0          | 0          | end           | 1.520     |
| 0          | 1          | start         | 3.140     |
| 0          | 1          | end           | 4.120     |
| 1          | 0          | start         | 0.550     |
| 1          | 0          | end           | 1.550     |
| 1          | 1          | start         | 0.430     |
| 1          | 1          | end           | 1.420     |
| 2          | 0          | start         | 4.100     |
| 2          | 0          | end           | 4.512     |
| 2          | 1          | start         | 2.500     |
| 2          | 1          | end           | 5.000     |
+------------+------------+---------------+-----------+
<strong>输出：</strong>
+------------+-----------------+
| machine_id | processing_time |
+------------+-----------------+
| 0          | 0.894           |
| 1          | 0.995           |
| 2          | 1.456           |
+------------+-----------------+
<strong>解释：</strong>
一共有3台机器,每台机器运行着两个进程.
机器 0 的平均耗时: ((1.520 - 0.712) + (4.120 - 3.140)) / 2 = 0.894
机器 1 的平均耗时: ((1.550 - 0.550) + (1.420 - 0.430)) / 2 = 0.995
机器 2 的平均耗时: ((4.512 - 4.100) + (5.000 - 2.500)) / 2 = 1.456</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们可以根据 `machine_id` 分组，然后利用 `AVG` 函数计算每台机器上所有进程任务的平均耗时。由于机器上的每个进程任务都有一对开始时间戳和结束时间戳，完成一个进程任务的时间指进程的 `end` 时间戳 减去 `start` 时间戳，因此我们可以利用 `CASE WHEN` 或者 `IF` 函数来计算每个进程任务的耗时，最后再利用 `AVG` 函数计算每台机器上所有进程任务的平均耗时。

注意，每台机器有 $2$ 个进程任务，因此我们需要将计算出的平均耗时乘以 $2$。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    machine_id,
    ROUND(
        AVG(
            CASE
                WHEN activity_type = 'start' THEN -timestamp
                ELSE timestamp
            END
        ) * 2,
        3
    ) AS processing_time
FROM Activity
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    machine_id,
    ROUND(AVG(IF(activity_type = 'start', -1, 1) * timestamp) * 2, 3) AS processing_time
FROM Activity
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1662. 检查两个字符串数组是否相等](https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent){#1662}

{{< tabs "1662" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        i = j = x = y = 0
        while i < len(word1) and j < len(word2):
            if word1[i][x] != word2[j][y]:
                return False
            x, y = x + 1, y + 1
            if x == len(word1[i]):
                x, i = 0, i + 1
            if y == len(word2[j]):
                y, j = 0, j + 1
        return i == len(word1) and j == len(word2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int i = 0, j = 0;
        int x = 0, y = 0;
        while (i < word1.length && j < word2.length) {
            if (word1[i].charAt(x++) != word2[j].charAt(y++)) {
                return false;
            }
            if (x == word1[i].length()) {
                x = 0;
                ++i;
            }
            if (y == word2[j].length()) {
                y = 0;
                ++j;
            }
        }
        return i == word1.length && j == word2.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, x = 0, y = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][x++] != word2[j][y++]) return false;
            if (x == word1[i].size()) x = 0, i++;
            if (y == word2[j].size()) y = 0, j++;
        }
        return i == word1.size() && j == word2.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	var i, j, x, y int
	for i < len(word1) && j < len(word2) {
		if word1[i][x] != word2[j][y] {
			return false
		}
		x, y = x+1, y+1
		if x == len(word1[i]) {
			x, i = 0, i+1
		}
		if y == len(word2[j]) {
			y, j = 0, j+1
		}
	}
	return i == len(word1) && j == len(word2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function arrayStringsAreEqual(word1: string[], word2: string[]): boolean {
    let [i, j, x, y] = [0, 0, 0, 0];
    while (i < word1.length && j < word2.length) {
        if (word1[i][x++] !== word2[j][y++]) {
            return false;
        }
        if (x === word1[i].length) {
            x = 0;
            ++i;
        }
        if (y === word2[j].length) {
            y = 0;
            ++j;
        }
    }
    return i === word1.length && j === word2.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let (n, m) = (word1.len(), word2.len());
        let (mut i, mut j, mut x, mut y) = (0, 0, 0, 0);
        while i < n && j < m {
            if word1[i].as_bytes()[x] != word2[j].as_bytes()[y] {
                return false;
            }
            x += 1;
            y += 1;
            if x == word1[i].len() {
                x = 0;
                i += 1;
            }
            if y == word2[j].len() {
                y = 0;
                j += 1;
            }
        }
        i == n && j == m
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    while (i < word1Size && j < word2Size) {
        if (word1[i][x++] != word2[j][y++]) {
            return 0;
        }

        if (word1[i][x] == '\0') {
            x = 0;
            i++;
        }
        if (word2[j][y] == '\0') {
            y = 0;
            j++;
        }
    }
    return i == word1Size && j == word2Size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串数组 <code>word1</code> 和 <code>word2</code> 。如果两个数组表示的字符串相同，返回<em> </em><code>true</code><em> </em>；否则，返回 <code>false</code><em> 。</em></p>

<p><strong>数组表示的字符串</strong> 是由数组中的所有元素 <strong>按顺序</strong> 连接形成的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = ["ab", "c"], word2 = ["a", "bc"]
<strong>输出：</strong>true
<strong>解释：</strong>
word1 表示的字符串为 "ab" + "c" -> "abc"
word2 表示的字符串为 "a" + "bc" -> "abc"
两个字符串相同，返回 true</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = ["a", "cb"], word2 = ["ab", "c"]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
<strong>输出：</strong>true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 10<sup>3</sup></code></li>
	<li><code>1 <= word1[i].length, word2[i].length <= 10<sup>3</sup></code></li>
	<li><code>1 <= sum(word1[i].length), sum(word2[i].length) <= 10<sup>3</sup></code></li>
	<li><code>word1[i]</code> 和 <code>word2[i]</code> 由小写字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串拼接

将两个数组中的字符串拼接成两个字符串，然后比较两个字符串是否相等。

时间复杂度 $O(m)$，空间复杂度 $O(m)$。其中 $m$ 为数组中字符串的总长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return ''.join(word1) == ''.join(word2)
```

#### Java

```java
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        return String.join("", word1).equals(String.join("", word2));
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return reduce(word1.cbegin(), word1.cend()) == reduce(word2.cbegin(), word2.cend());
    }
};
```

#### Go

```go
func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	return strings.Join(word1, "") == strings.Join(word2, "")
}
```

#### TypeScript

```ts
function arrayStringsAreEqual(word1: string[], word2: string[]): boolean {
    return word1.join('') === word2.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        word1.join("") == word2.join("")
    }
}
```

#### C

```c
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    while (i < word1Size && j < word2Size) {
        if (word1[i][x++] != word2[j][y++]) {
            return 0;
        }

        if (word1[i][x] == '\0') {
            x = 0;
            i++;
        }
        if (word2[j][y] == '\0') {
            y = 0;
            j++;
        }
    }
    return i == word1Size && j == word2Size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：直接遍历

方法一中，我们是将两个数组中的字符串拼接成两个新的字符串，有额外的空间开销。我们也可以直接遍历两个数组，逐个字符比较。

我们使用两个指针 $i$ 和 $j$ 分别指向两个字符串数组，用另外两个指针 $x$ 和 $y$ 分别指向字符串对应的字符。初始时 $i = j = x = y = 0$。

每次比较 $word1[i][x]$ 和 $word2[j][y]$，如果不相等，直接返回 `false`。否则，将 $x$ 和 $y$ 分别加 $1$，如果 $x$ 或 $y$ 超出了对应的字符串的长度，将对应的字符串指针 $i$ 或 $j$ 加 $1$，然后将 $x$ 和 $y$ 重置为 $0$。

如果两个字符串数组遍历完毕，返回 `true`，否则返回 `false`。

时间复杂度 $O(m)$，空间复杂度 $O(1)$。其中 $m$ 为数组中字符串的总长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        i = j = x = y = 0
        while i < len(word1) and j < len(word2):
            if word1[i][x] != word2[j][y]:
                return False
            x, y = x + 1, y + 1
            if x == len(word1[i]):
                x, i = 0, i + 1
            if y == len(word2[j]):
                y, j = 0, j + 1
        return i == len(word1) and j == len(word2)
```

#### Java

```java
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int i = 0, j = 0;
        int x = 0, y = 0;
        while (i < word1.length && j < word2.length) {
            if (word1[i].charAt(x++) != word2[j].charAt(y++)) {
                return false;
            }
            if (x == word1[i].length()) {
                x = 0;
                ++i;
            }
            if (y == word2[j].length()) {
                y = 0;
                ++j;
            }
        }
        return i == word1.length && j == word2.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, x = 0, y = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][x++] != word2[j][y++]) return false;
            if (x == word1[i].size()) x = 0, i++;
            if (y == word2[j].size()) y = 0, j++;
        }
        return i == word1.size() && j == word2.size();
    }
};
```

#### Go

```go
func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	var i, j, x, y int
	for i < len(word1) && j < len(word2) {
		if word1[i][x] != word2[j][y] {
			return false
		}
		x, y = x+1, y+1
		if x == len(word1[i]) {
			x, i = 0, i+1
		}
		if y == len(word2[j]) {
			y, j = 0, j+1
		}
	}
	return i == len(word1) && j == len(word2)
}
```

#### TypeScript

```ts
function arrayStringsAreEqual(word1: string[], word2: string[]): boolean {
    let [i, j, x, y] = [0, 0, 0, 0];
    while (i < word1.length && j < word2.length) {
        if (word1[i][x++] !== word2[j][y++]) {
            return false;
        }
        if (x === word1[i].length) {
            x = 0;
            ++i;
        }
        if (y === word2[j].length) {
            y = 0;
            ++j;
        }
    }
    return i === word1.length && j === word2.length;
}
```

#### Rust

```rust
impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let (n, m) = (word1.len(), word2.len());
        let (mut i, mut j, mut x, mut y) = (0, 0, 0, 0);
        while i < n && j < m {
            if word1[i].as_bytes()[x] != word2[j].as_bytes()[y] {
                return false;
            }
            x += 1;
            y += 1;
            if x == word1[i].len() {
                x = 0;
                i += 1;
            }
            if y == word2[j].len() {
                y = 0;
                j += 1;
            }
        }
        i == n && j == m
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1663. 具有给定数值的最小字符串](https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value){#1663}

{{< tabs "1663" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['a'] * n
        i, d = n - 1, k - n
        while d > 25:
            ans[i] = 'z'
            d -= 25
            i -= 1
        ans[i] = chr(ord(ans[i]) + d)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String getSmallestString(int n, int k) {
        char[] ans = new char[n];
        Arrays.fill(ans, 'a');
        int i = n - 1, d = k - n;
        for (; d > 25; d -= 25) {
            ans[i--] = 'z';
        }
        ans[i] = (char) ('a' + d);
        return String.valueOf(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int i = n - 1, d = k - n;
        for (; d > 25; d -= 25) {
            ans[i--] = 'z';
        }
        ans[i] += d;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSmallestString(n int, k int) string {
	ans := make([]byte, n)
	for i := range ans {
		ans[i] = 'a'
	}
	i, d := n-1, k-n
	for ; d > 25; i, d = i-1, d-25 {
		ans[i] = 'z'
	}
	ans[i] += byte(d)
	return string(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>小写字符 </strong>的 <strong>数值</strong> 是它在字母表中的位置（从 <code>1</code> 开始），因此 <code>a</code> 的数值为 <code>1</code> ，<code>b</code> 的数值为 <code>2</code> ，<code>c</code> 的数值为 <code>3</code> ，以此类推。</p>

<p>字符串由若干小写字符组成，<strong>字符串的数值</strong> 为各字符的数值之和。例如，字符串 <code>"abe"</code> 的数值等于 <code>1 + 2 + 5 = 8</code> 。</p>

<p>给你两个整数 <code>n</code> 和 <code>k</code> 。返回 <strong>长度</strong> 等于 <code>n</code> 且 <strong>数值</strong> 等于 <code>k</code> 的 <strong>字典序最小</strong> 的字符串。</p>

<p>注意，如果字符串 <code>x</code> 在字典排序中位于 <code>y</code> 之前，就认为 <code>x</code> 字典序比 <code>y</code> 小，有以下两种情况：</p>

<ul>
	<li><code>x</code> 是 <code>y</code> 的一个前缀；</li>
	<li>如果 <code>i</code> 是 <code>x[i] != y[i]</code> 的第一个位置，且 <code>x[i]</code> 在字母表中的位置比 <code>y[i]</code> 靠前。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 27
<strong>输出：</strong>"aay"
<strong>解释：</strong>字符串的数值为 1 + 1 + 25 = 27，它是数值满足要求且长度等于 3 字典序最小的字符串。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5, k = 73
<strong>输出：</strong>"aaszz"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>n <= k <= 26 * n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先将字符串的每个字符都初始化为 `'a'`，此时剩余的数值为 $d=k-n$。

接着从后往前遍历字符串，每次贪心地将当前位置的字符替换为能够使得剩余的数字最小的字符 `'z'`，直到剩余的数字不超过 $25$。最后将剩余的数字加到我们遍历到的位置上即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['a'] * n
        i, d = n - 1, k - n
        while d > 25:
            ans[i] = 'z'
            d -= 25
            i -= 1
        ans[i] = chr(ord(ans[i]) + d)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String getSmallestString(int n, int k) {
        char[] ans = new char[n];
        Arrays.fill(ans, 'a');
        int i = n - 1, d = k - n;
        for (; d > 25; d -= 25) {
            ans[i--] = 'z';
        }
        ans[i] = (char) ('a' + d);
        return String.valueOf(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int i = n - 1, d = k - n;
        for (; d > 25; d -= 25) {
            ans[i--] = 'z';
        }
        ans[i] += d;
        return ans;
    }
};
```

#### Go

```go
func getSmallestString(n int, k int) string {
	ans := make([]byte, n)
	for i := range ans {
		ans[i] = 'a'
	}
	i, d := n-1, k-n
	for ; d > 25; i, d = i-1, d-25 {
		ans[i] = 'z'
	}
	ans[i] += byte(d)
	return string(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1664. 生成平衡数组的方案数](https://leetcode.cn/problems/ways-to-make-a-fair-array){#1664}

{{< tabs "1664" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        s1, s2 = sum(nums[::2]), sum(nums[1::2])
        ans = t1 = t2 = 0
        for i, v in enumerate(nums):
            ans += i % 2 == 0 and t2 + s1 - t1 - v == t1 + s2 - t2
            ans += i % 2 == 1 and t2 + s1 - t1 == t1 + s2 - t2 - v
            t1 += v if i % 2 == 0 else 0
            t2 += v if i % 2 == 1 else 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int waysToMakeFair(int[] nums) {
        int s1 = 0, s2 = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            s1 += i % 2 == 0 ? nums[i] : 0;
            s2 += i % 2 == 1 ? nums[i] : 0;
        }
        int t1 = 0, t2 = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2 ? 1 : 0;
            ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v ? 1 : 0;
            t1 += i % 2 == 0 ? v : 0;
            t2 += i % 2 == 1 ? v : 0;
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
    int waysToMakeFair(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            s1 += i % 2 == 0 ? nums[i] : 0;
            s2 += i % 2 == 1 ? nums[i] : 0;
        }
        int t1 = 0, t2 = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2;
            ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v;
            t1 += i % 2 == 0 ? v : 0;
            t2 += i % 2 == 1 ? v : 0;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToMakeFair(nums []int) (ans int) {
	var s1, s2, t1, t2 int
	for i, v := range nums {
		if i%2 == 0 {
			s1 += v
		} else {
			s2 += v
		}
	}
	for i, v := range nums {
		if i%2 == 0 && t2+s1-t1-v == t1+s2-t2 {
			ans++
		}
		if i%2 == 1 && t2+s1-t1 == t1+s2-t2-v {
			ans++
		}
		if i%2 == 0 {
			t1 += v
		} else {
			t2 += v
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToMakeFair = function (nums) {
    let [s1, s2, t1, t2] = [0, 0, 0, 0];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s1 += nums[i];
        } else {
            s2 += nums[i];
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const v = nums[i];
        ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2;
        ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v;
        t1 += i % 2 == 0 ? v : 0;
        t2 += i % 2 == 1 ? v : 0;
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

<p>给你一个整数数组 <code>nums</code> 。你需要选择 <strong>恰好</strong> 一个下标（下标从 <strong>0</strong> 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。</p>

<p>比方说，如果 <code>nums = [6,1,7,4,1]</code> ，那么：</p>

<ul>
	<li>选择删除下标 <code>1</code> ，剩下的数组为 <code>nums = [6,7,4,1]</code> 。</li>
	<li>选择删除下标 <code>2</code> ，剩下的数组为 <code>nums = [6,1,4,1]</code> 。</li>
	<li>选择删除下标 <code>4</code> ，剩下的数组为 <code>nums = [6,1,7,4]</code> 。</li>
</ul>

<p>如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 <strong>平衡数组</strong> 。</p>

<p>请你返回删除操作后，剩下的数组<em> </em><code>nums</code><em> </em>是 <strong>平衡数组</strong> 的 <strong>方案数</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,6,4]
<b>输出：</b>1
<strong>解释：</strong>
删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
只有一种让剩余数组成为平衡数组的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1]
<b>输出：</b>3
<b>解释：</b>你可以删除任意元素，剩余数组都是平衡数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3]
<b>输出：</b>0
<b>解释：</b>不管删除哪个元素，剩下数组都不是平衡数组。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 前缀和

我们先预处理得到数组 `nums` 的偶数下标元素之和 $s_1$ 以及奇数下标元素之和 $s_2$。

然后从前往后枚举数组 `nums` 的每个元素 $v$，用变量 $t_1$ 和 $t_2$ 分别记录已遍历的偶数下标元素之和以及奇数下标元素之和。

我们观察发现，对于当前遍历到的元素 $v$，如果删除了，那么该元素之后的奇偶下标元素之和会发生交换。此时，我们先判断该位置下标 $i$ 是奇数还是偶数。

-   如果是偶数下标，删除该元素后，数组的奇数下标元素之和为 $t_2 + s_1 - t_1 - v$，而偶数下标元素之和为 $t_1 + s_2 - t_2$，如果这两个和相等，那么就是一个平衡数组，答案加一。

-   如果是奇数下标，删除该元素后，数组的偶数下标元素之和为 $t_1 + s_2 - t_2 - v$，而奇数下标元素之和为 $t_2 + s_1 - t_1$，如果这两个和相等，那么就是一个平衡数组，答案加一。

然后我们更新 $t_1$ 和 $t_2$，继续遍历下一个元素。遍历完数组后，即可得到答案。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        s1, s2 = sum(nums[::2]), sum(nums[1::2])
        ans = t1 = t2 = 0
        for i, v in enumerate(nums):
            ans += i % 2 == 0 and t2 + s1 - t1 - v == t1 + s2 - t2
            ans += i % 2 == 1 and t2 + s1 - t1 == t1 + s2 - t2 - v
            t1 += v if i % 2 == 0 else 0
            t2 += v if i % 2 == 1 else 0
        return ans
```

#### Java

```java
class Solution {
    public int waysToMakeFair(int[] nums) {
        int s1 = 0, s2 = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            s1 += i % 2 == 0 ? nums[i] : 0;
            s2 += i % 2 == 1 ? nums[i] : 0;
        }
        int t1 = 0, t2 = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2 ? 1 : 0;
            ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v ? 1 : 0;
            t1 += i % 2 == 0 ? v : 0;
            t2 += i % 2 == 1 ? v : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            s1 += i % 2 == 0 ? nums[i] : 0;
            s2 += i % 2 == 1 ? nums[i] : 0;
        }
        int t1 = 0, t2 = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2;
            ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v;
            t1 += i % 2 == 0 ? v : 0;
            t2 += i % 2 == 1 ? v : 0;
        }
        return ans;
    }
};
```

#### Go

```go
func waysToMakeFair(nums []int) (ans int) {
	var s1, s2, t1, t2 int
	for i, v := range nums {
		if i%2 == 0 {
			s1 += v
		} else {
			s2 += v
		}
	}
	for i, v := range nums {
		if i%2 == 0 && t2+s1-t1-v == t1+s2-t2 {
			ans++
		}
		if i%2 == 1 && t2+s1-t1 == t1+s2-t2-v {
			ans++
		}
		if i%2 == 0 {
			t1 += v
		} else {
			t2 += v
		}
	}
	return
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToMakeFair = function (nums) {
    let [s1, s2, t1, t2] = [0, 0, 0, 0];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s1 += nums[i];
        } else {
            s2 += nums[i];
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const v = nums[i];
        ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2;
        ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v;
        t1 += i % 2 == 0 ? v : 0;
        t2 += i % 2 == 1 ? v : 0;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1665. 完成所有任务的最少初始能量](https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks){#1665}

{{< tabs "1665" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        ans = cur = 0
        for a, m in sorted(tasks, key=lambda x: x[0] - x[1]):
            if cur < m:
                ans += m - cur
                cur = m
            cur -= a
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> a[0] - b[0] - (a[1] - b[1]));
        int ans = 0, cur = 0;
        for (var task : tasks) {
            int a = task[0], m = task[1];
            if (cur < m) {
                ans += m - cur;
                cur = m;
            }
            cur -= a;
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
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const auto& a, const auto& b) { return a[0] - a[1] < b[0] - b[1]; });
        int ans = 0, cur = 0;
        for (auto& task : tasks) {
            int a = task[0], m = task[1];
            if (cur < m) {
                ans += m - cur;
                cur = m;
            }
            cur -= a;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumEffort(tasks [][]int) (ans int) {
	sort.Slice(tasks, func(i, j int) bool { return tasks[i][0]-tasks[i][1] < tasks[j][0]-tasks[j][1] })
	cur := 0
	for _, task := range tasks {
		a, m := task[0], task[1]
		if cur < m {
			ans += m - cur
			cur = m
		}
		cur -= a
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumEffort(tasks: number[][]): number {
    tasks.sort((a, b) => a[0] - a[1] - (b[0] - b[1]));
    let ans = 0;
    let cur = 0;
    for (const [a, m] of tasks) {
        if (cur < m) {
            ans += m - cur;
            cur = m;
        }
        cur -= a;
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

<p>给你一个任务数组 <code>tasks</code> ，其中 <code>tasks[i] = [actual<sub>i</sub>, minimum<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>actual<sub>i</sub></code> 是完成第 <code>i</code> 个任务 <strong>需要耗费</strong> 的实际能量。</li>
	<li><code>minimum<sub>i</sub></code> 是开始第 <code>i</code> 个任务前需要达到的最低能量。</li>
</ul>

<p>比方说，如果任务为 <code>[10, 12]</code> 且你当前的能量为 <code>11</code> ，那么你不能开始这个任务。如果你当前的能量为 <code>13</code> ，你可以完成这个任务，且完成它后剩余能量为 <code>3</code> 。</p>

<p>你可以按照 <strong>任意顺序</strong> 完成任务。</p>

<p>请你返回完成所有任务的 <strong>最少</strong> 初始能量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tasks = [[1,2],[2,4],[4,8]]
<b>输出：</b>8
<strong>解释：</strong>
一开始有 8 能量，我们按照如下顺序完成任务：
    - 完成第 3 个任务，剩余能量为 8 - 4 = 4 。
    - 完成第 2 个任务，剩余能量为 4 - 2 = 2 。
    - 完成第 1 个任务，剩余能量为 2 - 1 = 1 。
注意到尽管我们有能量剩余，但是如果一开始只有 7 能量是不能完成所有任务的，因为我们无法开始第 3 个任务。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
<b>输出：</b>32
<strong>解释：</strong>
一开始有 32 能量，我们按照如下顺序完成任务：
    - 完成第 1 个任务，剩余能量为 32 - 1 = 31 。
    - 完成第 2 个任务，剩余能量为 31 - 2 = 29 。
    - 完成第 3 个任务，剩余能量为 29 - 10 = 19 。
    - 完成第 4 个任务，剩余能量为 19 - 10 = 9 。
    - 完成第 5 个任务，剩余能量为 9 - 8 = 1 。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
<b>输出：</b>27
<strong>解释：</strong>
一开始有 27 能量，我们按照如下顺序完成任务：
    - 完成第 5 个任务，剩余能量为 27 - 5 = 22 。
    - 完成第 2 个任务，剩余能量为 22 - 2 = 20 。
    - 完成第 3 个任务，剩余能量为 20 - 3 = 17 。
    - 完成第 1 个任务，剩余能量为 17 - 1 = 16 。
    - 完成第 4 个任务，剩余能量为 16 - 4 = 12 。
    - 完成第 6 个任务，剩余能量为 12 - 6 = 6 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= actual<sub>​i</sub> &lt;= minimum<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 自定义排序

我们假设任务数为 $n$，初始能量值为 $E$，考虑完成最后一个任务，这需要我们完成前 $n-1$ 个任务后，剩余的能量值不小于完成最后一个任务需要达到的能量值 $m_n$，即：

$$
E-\sum_{i=1}^{n-1} a_i \geq m_n
$$

我们可以将 $m_n$ 表示成 $a_n+(m_n - a_n)$，然后将上面的式子变形，得到：

$$
E-\sum_{i=1}^{n-1} a_i \geq a_n+(m_n - a_n)
$$

整理可得：

$$
E \geq \sum_{i=1}^{n} a_i + (m_n - a_n)
$$

其中 $\sum_{i=1}^{n} a_i$ 是固定不变的，要使得初始值能量值 $E$ 最小，我们需要让 $m_n - a_n$ 最小，即 $a_n-m_n$ 最大。

因此，我们可以将任务按照 $a_i-m_i$ 从小到大排序。然后从前往后遍历任务，对于每个任务，如果当前能量值 $cur$ 小于 $m_i$，则需要增加能量值 $m_i - cur$，使得当前能量值刚好等于 $m_i$，然后再完成任务，更新 $cur = cur - a_i$。继续遍历，直到完成所有任务，即可得到初始所需的最少能量值。

时间复杂度 $O(n\times \log n)$。其中 $n$ 为任务数。忽略排序的空间开销，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        ans = cur = 0
        for a, m in sorted(tasks, key=lambda x: x[0] - x[1]):
            if cur < m:
                ans += m - cur
                cur = m
            cur -= a
        return ans
```

#### Java

```java
class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> a[0] - b[0] - (a[1] - b[1]));
        int ans = 0, cur = 0;
        for (var task : tasks) {
            int a = task[0], m = task[1];
            if (cur < m) {
                ans += m - cur;
                cur = m;
            }
            cur -= a;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const auto& a, const auto& b) { return a[0] - a[1] < b[0] - b[1]; });
        int ans = 0, cur = 0;
        for (auto& task : tasks) {
            int a = task[0], m = task[1];
            if (cur < m) {
                ans += m - cur;
                cur = m;
            }
            cur -= a;
        }
        return ans;
    }
};
```

#### Go

```go
func minimumEffort(tasks [][]int) (ans int) {
	sort.Slice(tasks, func(i, j int) bool { return tasks[i][0]-tasks[i][1] < tasks[j][0]-tasks[j][1] })
	cur := 0
	for _, task := range tasks {
		a, m := task[0], task[1]
		if cur < m {
			ans += m - cur
			cur = m
		}
		cur -= a
	}
	return
}
```

#### TypeScript

```ts
function minimumEffort(tasks: number[][]): number {
    tasks.sort((a, b) => a[0] - a[1] - (b[0] - b[1]));
    let ans = 0;
    let cur = 0;
    for (const [a, m] of tasks) {
        if (cur < m) {
            ans += m - cur;
            cur = m;
        }
        cur -= a;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1666. 改变二叉树的根节点 🔒](https://leetcode.cn/problems/change-the-root-of-a-binary-tree){#1666}

{{< tabs "1666" >}}

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
    def flipBinaryTree(self, root: "Node", leaf: "Node") -> "Node":
        cur = leaf
        p = cur.parent
        while cur != root:
            gp = p.parent
            if cur.left:
                cur.right = cur.left
            cur.left = p
            p.parent = cur
            if p.left == cur:
                p.left = None
            elif p.right == cur:
                p.right = None
            cur = p
            p = gp
        leaf.parent = None
        return leaf
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
    public Node flipBinaryTree(Node root, Node leaf) {
        Node cur = leaf;
        Node p = cur.parent;
        while (cur != root) {
            Node gp = p.parent;
            if (cur.left != null) {
                cur.right = cur.left;
            }
            cur.left = p;
            p.parent = cur;
            if (p.left == cur) {
                p.left = null;
            } else if (p.right == cur) {
                p.right = null;
            }
            cur = p;
            p = gp;
        }
        leaf.parent = null;
        return leaf;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node->
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
    Node* flipBinaryTree(Node* root, Node* leaf) {
        Node* cur = leaf;
        Node* p = cur->parent;
        while (cur != root) {
            Node* gp = p->parent;
            if (cur->left) {
                cur->right = cur->left;
            }
            cur->left = p;
            p->parent = cur;
            if (p->left == cur) {
                p->left = nullptr;
            } else if (p->right == cur) {
                p->right = nullptr;
            }
            cur = p;
            p = gp;
        }
        leaf->parent = nullptr;
        return leaf;
    }
};
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
var flipBinaryTree = function (root, leaf) {
    let cur = leaf;
    let p = cur.parent;
    while (cur != root) {
        const gp = p.parent;
        if (cur.left != null) {
            cur.right = cur.left;
        }
        cur.left = p;
        p.parent = cur;
        if (p.left == cur) {
            p.left = null;
        } else if (p.right == cur) {
            p.right = null;
        }
        cur = p;
        p = gp;
    }
    leaf.parent = null;
    return leaf;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
*/

public class Solution {
    public Node FlipBinaryTree(Node root, Node leaf) {
        Node cur = leaf;
        Node p = cur.parent;
        while (cur != root) {
            Node gp = p.parent;
            if (cur.left != null) {
                cur.right = cur.left;
            }
            cur.left = p;
            p.parent = cur;
            if (p.left == cur) {
                p.left = null;
            } else if (p.right == cur) {
                p.right = null;
            }
            cur = p;
            p = gp;
        }
        leaf.parent = null;
        return leaf;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点&nbsp;<code>root</code>&nbsp;和一个叶节点&nbsp;<code>leaf</code> ，更改二叉树，使得&nbsp;<code>leaf</code>&nbsp;为新的根节点。</p>

<p>你可以按照下列步骤修改<strong>从</strong> <code>leaf</code>&nbsp;<strong>到</strong> <code>root</code>&nbsp;<strong>的路径中除</strong> <code>root</code> <strong>外的每个节点</strong> <code>cur</code>&nbsp;：</p>

<ol>
	<li>如果&nbsp;<code>cur</code>&nbsp;有左子节点，则该子节点变为&nbsp;<code>cur</code>&nbsp;的右子节点。注意我们保证&nbsp;<code>cur</code>&nbsp;至多有一个子节点。</li>
	<li><code>cur</code>&nbsp;的原父节点变为&nbsp;<code>cur</code>&nbsp;的左子节点。</li>
</ol>

<p>返回修改后新树的根节点。</p>

<p><b>注意：</b>确保你的答案在操作后正确地设定了&nbsp;<code>Node.parent</code>&nbsp;（父节点）指针，否则会被判为错误答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1666.Change%20the%20Root%20of%20a%20Binary%20Tree/images/1727138189-YtDgTf-image.png" style="width: 500px; height: 262px;" />
<pre>
<strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 7
<strong>输出:</strong> [7,2,null,5,4,3,6,null,null,null,1,null,null,0,8]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 0
<strong>输出:</strong> [0,1,null,3,8,5,null,null,null,6,2,null,null,7,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点的个数在范围&nbsp;<code>[2, 100]</code>&nbsp;内。</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>所有的&nbsp;<code>Node.val</code>&nbsp;都是<strong>唯一</strong>的。</li>
	<li><code>leaf</code>&nbsp;存在于树中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自底向上模拟

从叶节点 `leaf` 开始，向上模拟翻转操作。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为二叉树节点个数。

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
    def flipBinaryTree(self, root: "Node", leaf: "Node") -> "Node":
        cur = leaf
        p = cur.parent
        while cur != root:
            gp = p.parent
            if cur.left:
                cur.right = cur.left
            cur.left = p
            p.parent = cur
            if p.left == cur:
                p.left = None
            elif p.right == cur:
                p.right = None
            cur = p
            p = gp
        leaf.parent = None
        return leaf
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
    public Node flipBinaryTree(Node root, Node leaf) {
        Node cur = leaf;
        Node p = cur.parent;
        while (cur != root) {
            Node gp = p.parent;
            if (cur.left != null) {
                cur.right = cur.left;
            }
            cur.left = p;
            p.parent = cur;
            if (p.left == cur) {
                p.left = null;
            } else if (p.right == cur) {
                p.right = null;
            }
            cur = p;
            p = gp;
        }
        leaf.parent = null;
        return leaf;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node->
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
    Node* flipBinaryTree(Node* root, Node* leaf) {
        Node* cur = leaf;
        Node* p = cur->parent;
        while (cur != root) {
            Node* gp = p->parent;
            if (cur->left) {
                cur->right = cur->left;
            }
            cur->left = p;
            p->parent = cur;
            if (p->left == cur) {
                p->left = nullptr;
            } else if (p->right == cur) {
                p->right = nullptr;
            }
            cur = p;
            p = gp;
        }
        leaf->parent = nullptr;
        return leaf;
    }
};
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
var flipBinaryTree = function (root, leaf) {
    let cur = leaf;
    let p = cur.parent;
    while (cur != root) {
        const gp = p.parent;
        if (cur.left != null) {
            cur.right = cur.left;
        }
        cur.left = p;
        p.parent = cur;
        if (p.left == cur) {
            p.left = null;
        } else if (p.right == cur) {
            p.right = null;
        }
        cur = p;
        p = gp;
    }
    leaf.parent = null;
    return leaf;
};
```

#### C#

```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
*/

public class Solution {
    public Node FlipBinaryTree(Node root, Node leaf) {
        Node cur = leaf;
        Node p = cur.parent;
        while (cur != root) {
            Node gp = p.parent;
            if (cur.left != null) {
                cur.right = cur.left;
            }
            cur.left = p;
            p.parent = cur;
            if (p.left == cur) {
                p.left = null;
            } else if (p.right == cur) {
                p.right = null;
            }
            cur = p;
            p = gp;
        }
        leaf.parent = null;
        return leaf;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1667. 修复表中的名字](https://leetcode.cn/problems/fix-names-in-a-table){#1667}

{{< tabs "1667" >}}

{{% tab "sql" %}}
```sql
SELECT
    user_id,
    CONCAT(
        UPPER(LEFT(name, 1)),
        LOWER(SUBSTRING(name, 2, DATALENGTH(name)))
    ) AS name
FROM
    users
ORDER BY
    user_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表： <code>Users</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
user_id 是该表的主键(具有唯一值的列)。
该表包含用户的 ID 和名字。名字仅由小写和大写字符组成。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，修复名字，使得只有第一个字符是大写的，其余都是小写的。</p>

<p>返回按 <code>user_id</code> 排序的结果表。</p>

<p>返回结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Users table:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | aLice |
| 2       | bOB   |
+---------+-------+
<strong>输出：</strong>
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | Alice |
| 2       | Bob   |
+---------+-------+</pre>

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
SELECT
    user_id,
    CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM
    users
ORDER BY
    user_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    user_id,
    CONCAT(
        UPPER(LEFT(name, 1)),
        LOWER(SUBSTRING(name, 2, DATALENGTH(name)))
    ) AS name
FROM
    users
ORDER BY
    user_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1668. 最大重复子字符串](https://leetcode.cn/problems/maximum-repeating-substring){#1668}

{{< tabs "1668" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        for k in range(len(sequence) // len(word), -1, -1):
            if word * k in sequence:
                return k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxRepeating(String sequence, String word) {
        for (int k = sequence.length() / word.length(); k > 0; --k) {
            if (sequence.contains(word.repeat(k))) {
                return k;
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string t = word;
        int x = sequence.size() / word.size();
        for (int k = 1; k <= x; ++k) {
            // C++ 这里从小到大枚举重复值
            if (sequence.find(t) != string::npos) {
                ans = k;
            }
            t += word;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxRepeating(sequence string, word string) int {
	for k := len(sequence) / len(word); k > 0; k-- {
		if strings.Contains(sequence, strings.Repeat(word, k)) {
			return k
		}
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxRepeating(sequence: string, word: string): number {
    let n = sequence.length;
    let m = word.length;
    for (let k = Math.floor(n / m); k > 0; k--) {
        if (sequence.includes(word.repeat(k))) {
            return k;
        }
    }
    return 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_repeating(sequence: String, word: String) -> i32 {
        let n = sequence.len();
        let m = word.len();
        if n < m {
            return 0;
        }
        let mut dp = vec![0; n - m + 1];
        for i in 0..=n - m {
            let s = &sequence[i..i + m];
            if s == word {
                dp[i] = (if (i as i32) - (m as i32) < 0 {
                    0
                } else {
                    dp[i - m]
                }) + 1;
            }
        }
        *dp.iter().max().unwrap()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int findWord(int i, char* sequence, char* word) {
    int n = strlen(word);
    for (int j = 0; j < n; j++) {
        if (sequence[j + i] != word[j]) {
            return 0;
        }
    }
    return 1 + findWord(i + n, sequence, word);
}

int maxRepeating(char* sequence, char* word) {
    int n = strlen(sequence);
    int m = strlen(word);
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        ans = max(ans, findWord(i, sequence, word));
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

<p>给你一个字符串 <code>sequence</code> ，如果字符串 <code>word</code> 连续重复 <code>k</code> 次形成的字符串是 <code>sequence</code> 的一个子字符串，那么单词 <code>word</code> 的 <strong>重复值为 <code>k</code></strong><strong> </strong>。单词 <code>word</code> 的 <strong>最</strong><strong>大重复值</strong> 是单词 <code>word</code> 在 <code>sequence</code> 中最大的重复值。如果 <code>word</code> 不是 <code>sequence</code> 的子串，那么重复值 <code>k</code> 为 <code>0</code> 。</p>

<p>给你一个字符串 <code>sequence</code> 和 <code>word</code> ，请你返回 <strong>最大重复值 <code>k</code> </strong>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>sequence = "ababc", word = "ab"
<b>输出：</b>2
<strong>解释：</strong>"abab" 是 "<strong>abab</strong>c" 的子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>sequence = "ababc", word = "ba"
<b>输出：</b>1
<strong>解释：</strong>"ba" 是 "a<strong>ba</strong>bc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>sequence = "ababc", word = "ac"
<b>输出：</b>0
<strong>解释：</strong>"ac" 不是 "ababc" 的子字符串。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= sequence.length <= 100</code></li>
	<li><code>1 <= word.length <= 100</code></li>
	<li><code>sequence</code> 和 <code>word</code> 都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接枚举

注意到字符串长度不超过 $100$，我们直接从大到小枚举 `word` 的重复次数 $k$，判断 `word` 重复该次数后是否是 `sequence` 的子串，是则直接返回当前的重复次数 $k$。

时间复杂度为 $O(n^2)$，其中 $n$ 为 `sequence` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        for k in range(len(sequence) // len(word), -1, -1):
            if word * k in sequence:
                return k
```

#### Java

```java
class Solution {
    public int maxRepeating(String sequence, String word) {
        for (int k = sequence.length() / word.length(); k > 0; --k) {
            if (sequence.contains(word.repeat(k))) {
                return k;
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string t = word;
        int x = sequence.size() / word.size();
        for (int k = 1; k <= x; ++k) {
            // C++ 这里从小到大枚举重复值
            if (sequence.find(t) != string::npos) {
                ans = k;
            }
            t += word;
        }
        return ans;
    }
};
```

#### Go

```go
func maxRepeating(sequence string, word string) int {
	for k := len(sequence) / len(word); k > 0; k-- {
		if strings.Contains(sequence, strings.Repeat(word, k)) {
			return k
		}
	}
	return 0
}
```

#### TypeScript

```ts
function maxRepeating(sequence: string, word: string): number {
    let n = sequence.length;
    let m = word.length;
    for (let k = Math.floor(n / m); k > 0; k--) {
        if (sequence.includes(word.repeat(k))) {
            return k;
        }
    }
    return 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_repeating(sequence: String, word: String) -> i32 {
        let n = sequence.len();
        let m = word.len();
        if n < m {
            return 0;
        }
        let mut dp = vec![0; n - m + 1];
        for i in 0..=n - m {
            let s = &sequence[i..i + m];
            if s == word {
                dp[i] = (if (i as i32) - (m as i32) < 0 {
                    0
                } else {
                    dp[i - m]
                }) + 1;
            }
        }
        *dp.iter().max().unwrap()
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int findWord(int i, char* sequence, char* word) {
    int n = strlen(word);
    for (int j = 0; j < n; j++) {
        if (sequence[j + i] != word[j]) {
            return 0;
        }
    }
    return 1 + findWord(i + n, sequence, word);
}

int maxRepeating(char* sequence, char* word) {
    int n = strlen(sequence);
    int m = strlen(word);
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        ans = max(ans, findWord(i, sequence, word));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1669. 合并两个链表](https://leetcode.cn/problems/merge-in-between-linked-lists){#1669}

{{< tabs "1669" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(
        self, list1: ListNode, a: int, b: int, list2: ListNode
    ) -> ListNode:
        p = q = list1
        for _ in range(a - 1):
            p = p.next
        for _ in range(b):
            q = q.next
        p.next = list2
        while p.next:
            p = p.next
        p.next = q.next
        q.next = None
        return list1
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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode p = list1, q = list1;
        while (--a > 0) {
            p = p.next;
        }
        while (b-- > 0) {
            q = q.next;
        }
        p.next = list2;
        while (p.next != null) {
            p = p.next;
        }
        p.next = q.next;
        q.next = null;
        return list1;
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto p = list1, q = list1;
        while (--a) {
            p = p->next;
        }
        while (b--) {
            q = q->next;
        }
        p->next = list2;
        while (p->next) {
            p = p->next;
        }
        p->next = q->next;
        q->next = nullptr;
        return list1;
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
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
	p, q := list1, list1
	for ; a > 1; a-- {
		p = p.Next
	}
	for ; b > 0; b-- {
		q = q.Next
	}
	p.Next = list2
	for p.Next != nil {
		p = p.Next
	}
	p.Next = q.Next
	q.Next = nil
	return list1
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

function mergeInBetween(
    list1: ListNode | null,
    a: number,
    b: number,
    list2: ListNode | null,
): ListNode | null {
    let p = list1;
    let q = list1;
    while (--a > 0) {
        p = p.next;
    }
    while (b-- > 0) {
        q = q.next;
    }
    p.next = list2;
    while (p.next) {
        p = p.next;
    }
    p.next = q.next;
    q.next = null;
    return list1;
}
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
    public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode p = list1, q = list1;
        while (--a > 0) {
            p = p.next;
        }
        while (b-- > 0) {
            q = q.next;
        }
        p.next = list2;
        while (p.next != null) {
            p = p.next;
        }
        p.next = q.next;
        q.next = null;
        return list1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个链表&nbsp;<code>list1</code> 和&nbsp;<code>list2</code>&nbsp;，它们包含的元素分别为&nbsp;<code>n</code> 个和&nbsp;<code>m</code> 个。</p>

<p>请你将&nbsp;<code>list1</code>&nbsp;中下标从 <code>a</code> 到 <code>b</code> 的全部节点都删除，并将<code>list2</code>&nbsp;接在被删除节点的位置。</p>

<p>下图中蓝色边和节点展示了操作后的结果：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1669.Merge%20In%20Between%20Linked%20Lists/images/fig1.png" style="height: 130px; width: 504px;" />
<p>请你返回结果链表的头指针。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1669.Merge%20In%20Between%20Linked%20Lists/images/1709608717-NVGojm-image.png" style="width: 450px; height: 155px;" /></p>

<pre>
<b>输入：</b>list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
<b>输出：</b>[10,1,13,1000000,1000001,1000002,5]
<b>解释：</b>我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1669.Merge%20In%20Between%20Linked%20Lists/images/merge_linked_list_ex2.png" style="width: 463px; height: 140px;" />
<pre>
<b>输入：</b>list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
<b>输出：</b>[0,1,1000000,1000001,1000002,1000003,1000004,6]
<b>解释：</b>上图中蓝色的边和节点为答案链表。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= list1.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= a &lt;= b &lt; list1.length - 1</code></li>
	<li><code>1 &lt;= list2.length &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接模拟题目中的操作即可。

在实现上，我们使用两个指针 $p$ 和 $q$，初始时均指向链表 `list1` 的头节点。

然后我们向后移动指针 $p$ 和 $q$，直到指针 $p$ 指向链表 `list1` 中第 $a$ 个节点的前一个节点，指针 $q$ 指向链表 `list1` 中第 $b$ 个节点。此时我们将 $p$ 的 `next` 指针指向链表 `list2` 的头节点，将链表 `list2` 的尾节点的 `next` 指针指向 $q$ 的 `next` 指针指向的节点，即可完成题目要求。

时间复杂度 $O(m + n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别为链表 `list1` 和 `list2` 的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(
        self, list1: ListNode, a: int, b: int, list2: ListNode
    ) -> ListNode:
        p = q = list1
        for _ in range(a - 1):
            p = p.next
        for _ in range(b):
            q = q.next
        p.next = list2
        while p.next:
            p = p.next
        p.next = q.next
        q.next = None
        return list1
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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode p = list1, q = list1;
        while (--a > 0) {
            p = p.next;
        }
        while (b-- > 0) {
            q = q.next;
        }
        p.next = list2;
        while (p.next != null) {
            p = p.next;
        }
        p.next = q.next;
        q.next = null;
        return list1;
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto p = list1, q = list1;
        while (--a) {
            p = p->next;
        }
        while (b--) {
            q = q->next;
        }
        p->next = list2;
        while (p->next) {
            p = p->next;
        }
        p->next = q->next;
        q->next = nullptr;
        return list1;
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
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
	p, q := list1, list1
	for ; a > 1; a-- {
		p = p.Next
	}
	for ; b > 0; b-- {
		q = q.Next
	}
	p.Next = list2
	for p.Next != nil {
		p = p.Next
	}
	p.Next = q.Next
	q.Next = nil
	return list1
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

function mergeInBetween(
    list1: ListNode | null,
    a: number,
    b: number,
    list2: ListNode | null,
): ListNode | null {
    let p = list1;
    let q = list1;
    while (--a > 0) {
        p = p.next;
    }
    while (b-- > 0) {
        q = q.next;
    }
    p.next = list2;
    while (p.next) {
        p = p.next;
    }
    p.next = q.next;
    q.next = null;
    return list1;
}
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
    public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode p = list1, q = list1;
        while (--a > 0) {
            p = p.next;
        }
        while (b-- > 0) {
            q = q.next;
        }
        p.next = list2;
        while (p.next != null) {
            p = p.next;
        }
        p.next = q.next;
        q.next = null;
        return list1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
