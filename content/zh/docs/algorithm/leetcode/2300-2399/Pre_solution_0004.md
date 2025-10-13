---
title: "2330_验证回文串 IV 🔒"
date: 2025-10-08T18:39:12+08:00
weight: 4
tags: [二分查找, 二叉树, 动态规划, 单调栈, 双指针, 哈希表, 堆（优先队列）, 字符串, 并查集, 排序, 数学, 数据库, 数组, 数论, 有序集合, 栈, 树, 深度优先搜索, 组合数学, 设计, 贪心]
---

{{< markmap >}}
### [2330_验证回文串 IV 🔒](#2330)
#### [双指针](#2330)
#### [字符串](#2330)
### [2331_计算布尔二叉树的值](#2331)
#### [树](#2331)
#### [深度优先搜索](#2331)
#### [二叉树](#2331)
### [2332_坐上公交的最晚时间](#2332)
#### [数组](#2332)
#### [双指针](#2332)
#### [二分查找](#2332)
#### [排序](#2332)
### [2333_最小差值平方和](#2333)
#### [贪心](#2333)
#### [数组](#2333)
#### [二分查找](#2333)
#### [排序](#2333)
#### [堆（优先队列）](#2333)
### [2334_元素值大于变化阈值的子数组](#2334)
#### [栈](#2334)
#### [并查集](#2334)
#### [数组](#2334)
#### [单调栈](#2334)
### [2335_装满杯子需要的最短总时长](#2335)
#### [贪心](#2335)
#### [数组](#2335)
#### [排序](#2335)
#### [堆（优先队列）](#2335)
### [2336_无限集中的最小数字](#2336)
#### [设计](#2336)
#### [哈希表](#2336)
#### [有序集合](#2336)
#### [堆（优先队列）](#2336)
### [2337_移动片段得到字符串](#2337)
#### [双指针](#2337)
#### [字符串](#2337)
### [2338_统计理想数组的数目](#2338)
#### [数学](#2338)
#### [动态规划](#2338)
#### [组合数学](#2338)
#### [数论](#2338)
### [2339_联赛的所有比赛 🔒](#2339)
#### [数据库](#2339)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2330_验证回文串 IV 🔒
___
#### 双指针
___
#### 字符串
---
### 2331_计算布尔二叉树的值
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 2332_坐上公交的最晚时间
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 2333_最小差值平方和
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 排序
___
#### 堆（优先队列）
---
### 2334_元素值大于变化阈值的子数组
___
#### 栈
___
#### 并查集
___
#### 数组
___
#### 单调栈
---
### 2335_装满杯子需要的最短总时长
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2336_无限集中的最小数字
___
#### 设计
___
#### 哈希表
___
#### 有序集合
___
#### 堆（优先队列）
---
### 2337_移动片段得到字符串
___
#### 双指针
___
#### 字符串
---
### 2338_统计理想数组的数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
___
#### 数论
---
### 2339_联赛的所有比赛 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 单调栈 | 双指针 | 哈希表 |
| 堆（优先队列） | 字符串 | 并查集 |
| 排序 | 数学 | 数据库 |
| 数组 | 数论 | 有序集合 |
| 栈 | 树 | 深度优先搜索 |
| 组合数学 | 设计 | 贪心 |

# [2330. 验证回文串 IV 🔒](https://leetcode.cn/problems/valid-palindrome-iv){#2330}

{{< tabs "2330" >}}

{{% tab "python" %}}
```python
class Solution:
    def makePalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        cnt = 0
        while i < j:
            cnt += s[i] != s[j]
            i, j = i + 1, j - 1
        return cnt <= 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean makePalindrome(String s) {
        int cnt = 0;
        int i = 0, j = s.length() - 1;
        for (; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j)) {
                ++cnt;
            }
        }
        return cnt <= 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool makePalindrome(string s) {
        int cnt = 0;
        int i = 0, j = s.size() - 1;
        for (; i < j; ++i, --j) {
            cnt += s[i] != s[j];
        }
        return cnt <= 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makePalindrome(s string) bool {
	cnt := 0
	i, j := 0, len(s)-1
	for ; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			cnt++
		}
	}
	return cnt <= 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makePalindrome(s: string): boolean {
    let cnt = 0;
    let i = 0;
    let j = s.length - 1;
    for (; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            ++cnt;
        }
    }
    return cnt <= 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、仅由小写英文字母组成的字符串 <code>s</code> 。在一步操作中，你可以将 <code>s</code> 中的任一字符更改为其他任何字符。</p>

<p>如果你能在 <strong>恰</strong> 执行一到两步操作后使 <code>s</code> 变成一个回文，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "abcdba"
<strong>输出:</strong> true
<strong>解释:</strong> 能让 s 变成回文，且只用了一步操作的方案如下:
- 将 s[2] 变成 'd' ，得到 s = "abddba" 。
执行一步操作让 s 变成一个回文，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> s = "aa"
<strong>输出:</strong> true
<strong>解释:</strong> 能让 s 变成回文，且只用了两步操作的方案如下:
- 将 s[0] 变成 'b' ，得到 s = "ba" 。
- 将 s[1] 变成 'b' ，得到s = "bb" 。
执行两步操作让 s 变成一个回文，所以返回 true 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> s = "abcdef"
<strong>输出:</strong> false
<strong>解释:</strong> 不存在能在两步操作以内将 s 变成回文的办法，所以返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以使用双指针 $i$ 和 $j$，分别指向字符串的头尾，然后向中间移动，统计不同字符的个数，如果不同字符的个数大于 $2$，则返回 $\textit{false}$，否则返回 $\textit{true}$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makePalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        cnt = 0
        while i < j:
            cnt += s[i] != s[j]
            i, j = i + 1, j - 1
        return cnt <= 2
```

#### Java

```java
class Solution {
    public boolean makePalindrome(String s) {
        int cnt = 0;
        int i = 0, j = s.length() - 1;
        for (; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j)) {
                ++cnt;
            }
        }
        return cnt <= 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool makePalindrome(string s) {
        int cnt = 0;
        int i = 0, j = s.size() - 1;
        for (; i < j; ++i, --j) {
            cnt += s[i] != s[j];
        }
        return cnt <= 2;
    }
};
```

#### Go

```go
func makePalindrome(s string) bool {
	cnt := 0
	i, j := 0, len(s)-1
	for ; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			cnt++
		}
	}
	return cnt <= 2
}
```

#### TypeScript

```ts
function makePalindrome(s: string): boolean {
    let cnt = 0;
    let i = 0;
    let j = s.length - 1;
    for (; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            ++cnt;
        }
    }
    return cnt <= 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2331. 计算布尔二叉树的值](https://leetcode.cn/problems/evaluate-boolean-binary-tree){#2331}

{{< tabs "2331" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if root.left is None:
            return bool(root.val)
        op = or_ if root.val == 2 else and_
        return op(self.evaluateTree(root.left), self.evaluateTree(root.right))
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
    public boolean evaluateTree(TreeNode root) {
        if (root.left == null) {
            return root.val == 1;
        }
        if (root.val == 2) {
            return evaluateTree(root.left) || evaluateTree(root.right);
        }
        return evaluateTree(root.left) && evaluateTree(root.right);
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
    bool evaluateTree(TreeNode* root) {
        if (!root->left) {
            return root->val;
        }
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        return evaluateTree(root->left) && evaluateTree(root->right);
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
func evaluateTree(root *TreeNode) bool {
	if root.Left == nil {
		return root.Val == 1
	}
	if root.Val == 2 {
		return evaluateTree(root.Left) || evaluateTree(root.Right)
	} else {
		return evaluateTree(root.Left) && evaluateTree(root.Right)
	}
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

function evaluateTree(root: TreeNode | null): boolean {
    const { val, left, right } = root;
    if (left === null) {
        return val === 1;
    }
    if (val === 2) {
        return evaluateTree(left) || evaluateTree(right);
    }
    return evaluateTree(left) && evaluateTree(right);
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
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(node) => {
                let node = node.borrow();
                if node.left.is_none() {
                    return node.val == 1;
                }
                if node.val == 2 {
                    return Self::evaluate_tree(node.left.clone())
                        || Self::evaluate_tree(node.right.clone());
                }
                Self::evaluate_tree(node.left.clone()) && Self::evaluate_tree(node.right.clone())
            }
            None => false,
        }
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if (!root->left) {
        return root->val == 1;
    }
    if (root->val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
    return evaluateTree(root->left) && evaluateTree(root->right);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <strong>完整二叉树</strong>&nbsp;的根，这棵树有以下特征：</p>

<ul>
	<li><strong>叶子节点</strong>&nbsp;要么值为&nbsp;<code>0</code>&nbsp;要么值为&nbsp;<code>1</code>&nbsp;，其中&nbsp;<code>0</code> 表示&nbsp;<code>False</code>&nbsp;，<code>1</code> 表示&nbsp;<code>True</code>&nbsp;。</li>
	<li><strong>非叶子节点 </strong>要么值为 <code>2</code>&nbsp;要么值为 <code>3</code>&nbsp;，其中&nbsp;<code>2</code>&nbsp;表示逻辑或&nbsp;<code>OR</code> ，<code>3</code>&nbsp;表示逻辑与&nbsp;<code>AND</code>&nbsp;。</li>
</ul>

<p><strong>计算</strong>&nbsp;一个节点的值方式如下：</p>

<ul>
	<li>如果节点是个叶子节点，那么节点的 <strong>值</strong>&nbsp;为它本身，即&nbsp;<code>True</code>&nbsp;或者&nbsp;<code>False</code>&nbsp;。</li>
	<li>否则，<strong>计算</strong>&nbsp;两个孩子的节点值，然后将该节点的运算符对两个孩子值进行 <strong>运算</strong>&nbsp;。</li>
</ul>

<p>返回根节点<em>&nbsp;</em><code>root</code>&nbsp;的布尔运算值。</p>

<p><strong>完整二叉树</strong>&nbsp;是每个节点有 <code>0</code>&nbsp;个或者 <code>2</code>&nbsp;个孩子的二叉树。</p>

<p><strong>叶子节点</strong>&nbsp;是没有孩子的节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2331.Evaluate%20Boolean%20Binary%20Tree/images/example1drawio1.png" style="width: 700px; height: 252px;"></p>

<pre><b>输入：</b>root = [2,1,3,null,null,0,1]
<b>输出：</b>true
<b>解释：</b>上图展示了计算过程。
AND 与运算节点的值为 False AND True = False 。
OR 运算节点的值为 True OR False = True 。
根节点的值为 True ，所以我们返回 true 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>root = [0]
<b>输出：</b>false
<b>解释：</b>根节点是叶子节点，且值为 false，所以我们返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在&nbsp;<code>[1, 1000]</code>&nbsp;之间。</li>
	<li><code>0 &lt;= Node.val &lt;= 3</code></li>
	<li>每个节点的孩子数为&nbsp;<code>0</code> 或&nbsp;<code>2</code>&nbsp;。</li>
	<li>叶子节点的值为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>&nbsp;。</li>
	<li>非叶子节点的值为&nbsp;<code>2</code>&nbsp;或&nbsp;<code>3</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以使用递归的方式来求解本题。

对于当前节点 $\textit{root}$：

-   如果其左孩子为空，说明当前节点是叶子节点。如果当前节点的值为 $1$，则返回 $\textit{true}$，否则返回 $\textit{false}$；
-   如果当前节点的值为 $2$，则返回其左孩子和右孩子的递归结果的逻辑或，否则返回其左孩子和右孩子的递归结果的逻辑与。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

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
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if root.left is None:
            return bool(root.val)
        op = or_ if root.val == 2 else and_
        return op(self.evaluateTree(root.left), self.evaluateTree(root.right))
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
    public boolean evaluateTree(TreeNode root) {
        if (root.left == null) {
            return root.val == 1;
        }
        if (root.val == 2) {
            return evaluateTree(root.left) || evaluateTree(root.right);
        }
        return evaluateTree(root.left) && evaluateTree(root.right);
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
    bool evaluateTree(TreeNode* root) {
        if (!root->left) {
            return root->val;
        }
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        return evaluateTree(root->left) && evaluateTree(root->right);
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
func evaluateTree(root *TreeNode) bool {
	if root.Left == nil {
		return root.Val == 1
	}
	if root.Val == 2 {
		return evaluateTree(root.Left) || evaluateTree(root.Right)
	} else {
		return evaluateTree(root.Left) && evaluateTree(root.Right)
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

function evaluateTree(root: TreeNode | null): boolean {
    const { val, left, right } = root;
    if (left === null) {
        return val === 1;
    }
    if (val === 2) {
        return evaluateTree(left) || evaluateTree(right);
    }
    return evaluateTree(left) && evaluateTree(right);
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
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(node) => {
                let node = node.borrow();
                if node.left.is_none() {
                    return node.val == 1;
                }
                if node.val == 2 {
                    return Self::evaluate_tree(node.left.clone())
                        || Self::evaluate_tree(node.right.clone());
                }
                Self::evaluate_tree(node.left.clone()) && Self::evaluate_tree(node.right.clone())
            }
            None => false,
        }
    }
}
```

#### C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if (!root->left) {
        return root->val == 1;
    }
    if (root->val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
    return evaluateTree(root->left) && evaluateTree(root->right);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2332. 坐上公交的最晚时间](https://leetcode.cn/problems/the-latest-time-to-catch-a-bus){#2332}

{{< tabs "2332" >}}

{{% tab "python" %}}
```python
class Solution:
    def latestTimeCatchTheBus(
        self, buses: List[int], passengers: List[int], capacity: int
    ) -> int:
        buses.sort()
        passengers.sort()
        j = 0
        for t in buses:
            c = capacity
            while c and j < len(passengers) and passengers[j] <= t:
                c, j = c - 1, j + 1
        j -= 1
        ans = buses[-1] if c else passengers[j]
        while ~j and passengers[j] == ans:
            ans, j = ans - 1, j - 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        int j = 0, c = 0;
        for (int t : buses) {
            c = capacity;
            while (c > 0 && j < passengers.length && passengers[j] <= t) {
                --c;
                ++j;
            }
        }
        --j;
        int ans = c > 0 ? buses[buses.length - 1] : passengers[j];
        while (j >= 0 && ans == passengers[j]) {
            --ans;
            --j;
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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0, c = 0;
        for (int t : buses) {
            c = capacity;
            while (c && j < passengers.size() && passengers[j] <= t) --c, ++j;
        }
        --j;
        int ans = c ? buses[buses.size() - 1] : passengers[j];
        while (~j && ans == passengers[j]) --j, --ans;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func latestTimeCatchTheBus(buses []int, passengers []int, capacity int) int {
	sort.Ints(buses)
	sort.Ints(passengers)
	j, c := 0, 0
	for _, t := range buses {
		c = capacity
		for c > 0 && j < len(passengers) && passengers[j] <= t {
			j++
			c--
		}
	}
	j--
	ans := buses[len(buses)-1]
	if c == 0 {
		ans = passengers[j]
	}
	for j >= 0 && ans == passengers[j] {
		ans--
		j--
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function latestTimeCatchTheBus(buses: number[], passengers: number[], capacity: number): number {
    buses.sort((a, b) => a - b);
    passengers.sort((a, b) => a - b);
    let [j, c] = [0, 0];
    for (const t of buses) {
        c = capacity;
        while (c && j < passengers.length && passengers[j] <= t) {
            --c;
            ++j;
        }
    }
    --j;
    let ans = c > 0 ? buses.at(-1)! : passengers[j];
    while (j >= 0 && passengers[j] === ans) {
        --ans;
        --j;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} buses
 * @param {number[]} passengers
 * @param {number} capacity
 * @return {number}
 */
var latestTimeCatchTheBus = function (buses, passengers, capacity) {
    buses.sort((a, b) => a - b);
    passengers.sort((a, b) => a - b);
    let [j, c] = [0, 0];
    for (const t of buses) {
        c = capacity;
        while (c && j < passengers.length && passengers[j] <= t) {
            --c;
            ++j;
        }
    }
    --j;
    let ans = c > 0 ? buses.at(-1) : passengers[j];
    while (j >= 0 && passengers[j] === ans) {
        --ans;
        --j;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>buses</code>&nbsp;，其中&nbsp;<code>buses[i]</code>&nbsp;表示第 <code>i</code>&nbsp;辆公交车的出发时间。同时给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>m</code>&nbsp;的整数数组&nbsp;<code>passengers</code>&nbsp;，其中&nbsp;<code>passengers[j]</code>&nbsp;表示第&nbsp;<code>j</code>&nbsp;位乘客的到达时间。所有公交车出发的时间互不相同，所有乘客到达的时间也互不相同。</p>

<p>给你一个整数&nbsp;<code>capacity</code>&nbsp;，表示每辆公交车&nbsp;<strong>最多</strong>&nbsp;能容纳的乘客数目。</p>

<p>每位乘客都会排队搭乘下一辆有座位的公交车。如果你在 <code>y</code>&nbsp;时刻到达，公交在&nbsp;<code>x</code>&nbsp;时刻出发，满足&nbsp;<code>y &lt;= x</code>&nbsp;&nbsp;且公交没有满，那么你可以搭乘这一辆公交。<strong>最早</strong>&nbsp;到达的乘客优先上车。</p>

<p>返回你可以搭乘公交车的最晚到达公交站时间。你 <strong>不能</strong>&nbsp;跟别的乘客同时刻到达。</p>

<p><strong>注意：</strong>数组&nbsp;<code>buses</code> 和&nbsp;<code>passengers</code>&nbsp;不一定是有序的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>buses = [10,20], passengers = [2,17,18,19], capacity = 2
<b>输出：</b>16
<strong>解释：</strong>
第 1 辆公交车载着第 1 位乘客。
第 2 辆公交车载着你和第 2 位乘客。
注意你不能跟其他乘客同一时间到达，所以你必须在第二位乘客之前到达。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
<b>输出：</b>20
<b>解释：</b>
第 1 辆公交车载着第 4 位乘客。
第 2 辆公交车载着第 6 位和第 2 位乘客。
第 3 辆公交车载着第 1 位乘客和你。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == buses.length</code></li>
	<li><code>m == passengers.length</code></li>
	<li><code>1 &lt;= n, m, capacity &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= buses[i], passengers[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>buses</code>&nbsp;中的元素 <strong>互不相同&nbsp;</strong>。</li>
	<li><code>passengers</code>&nbsp;中的元素 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先排序，然后用双指针模拟乘客上车的过程：遍历公交车 $bus$，乘客遵循“先到先上车”的原则。

模拟结束后，判断最后一班公交车是否还有空位：

-   若有空位，我们可以在公交车发车时 $bus[|bus|-1]$ 到达公交站；若此时有人，可以顺着往前找到没人到达的时刻；
-   若无空位，我们可以找到上一个上车的乘客，顺着他往前找到没人到达的时刻。

时间复杂度 $O(n \times \log n + m \times \log m)$，空间复杂度 $O(\log n + \log m)$。其中 $n$ 和 $m$ 分别是公交车和乘客的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def latestTimeCatchTheBus(
        self, buses: List[int], passengers: List[int], capacity: int
    ) -> int:
        buses.sort()
        passengers.sort()
        j = 0
        for t in buses:
            c = capacity
            while c and j < len(passengers) and passengers[j] <= t:
                c, j = c - 1, j + 1
        j -= 1
        ans = buses[-1] if c else passengers[j]
        while ~j and passengers[j] == ans:
            ans, j = ans - 1, j - 1
        return ans
```

#### Java

```java
class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        int j = 0, c = 0;
        for (int t : buses) {
            c = capacity;
            while (c > 0 && j < passengers.length && passengers[j] <= t) {
                --c;
                ++j;
            }
        }
        --j;
        int ans = c > 0 ? buses[buses.length - 1] : passengers[j];
        while (j >= 0 && ans == passengers[j]) {
            --ans;
            --j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0, c = 0;
        for (int t : buses) {
            c = capacity;
            while (c && j < passengers.size() && passengers[j] <= t) --c, ++j;
        }
        --j;
        int ans = c ? buses[buses.size() - 1] : passengers[j];
        while (~j && ans == passengers[j]) --j, --ans;
        return ans;
    }
};
```

#### Go

```go
func latestTimeCatchTheBus(buses []int, passengers []int, capacity int) int {
	sort.Ints(buses)
	sort.Ints(passengers)
	j, c := 0, 0
	for _, t := range buses {
		c = capacity
		for c > 0 && j < len(passengers) && passengers[j] <= t {
			j++
			c--
		}
	}
	j--
	ans := buses[len(buses)-1]
	if c == 0 {
		ans = passengers[j]
	}
	for j >= 0 && ans == passengers[j] {
		ans--
		j--
	}
	return ans
}
```

#### TypeScript

```ts
function latestTimeCatchTheBus(buses: number[], passengers: number[], capacity: number): number {
    buses.sort((a, b) => a - b);
    passengers.sort((a, b) => a - b);
    let [j, c] = [0, 0];
    for (const t of buses) {
        c = capacity;
        while (c && j < passengers.length && passengers[j] <= t) {
            --c;
            ++j;
        }
    }
    --j;
    let ans = c > 0 ? buses.at(-1)! : passengers[j];
    while (j >= 0 && passengers[j] === ans) {
        --ans;
        --j;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} buses
 * @param {number[]} passengers
 * @param {number} capacity
 * @return {number}
 */
var latestTimeCatchTheBus = function (buses, passengers, capacity) {
    buses.sort((a, b) => a - b);
    passengers.sort((a, b) => a - b);
    let [j, c] = [0, 0];
    for (const t of buses) {
        c = capacity;
        while (c && j < passengers.length && passengers[j] <= t) {
            --c;
            ++j;
        }
    }
    --j;
    let ans = c > 0 ? buses.at(-1) : passengers[j];
    while (j >= 0 && passengers[j] === ans) {
        --ans;
        --j;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2333. 最小差值平方和](https://leetcode.cn/problems/minimum-sum-of-squared-difference){#2333}

{{< tabs "2333" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSumSquareDiff(
        self, nums1: List[int], nums2: List[int], k1: int, k2: int
    ) -> int:
        d = [abs(a - b) for a, b in zip(nums1, nums2)]
        k = k1 + k2
        if sum(d) <= k:
            return 0
        left, right = 0, max(d)
        while left < right:
            mid = (left + right) >> 1
            if sum(max(v - mid, 0) for v in d) <= k:
                right = mid
            else:
                left = mid + 1
        for i, v in enumerate(d):
            d[i] = min(left, v)
            k -= max(0, v - left)
        for i, v in enumerate(d):
            if k == 0:
                break
            if v == left:
                k -= 1
                d[i] -= 1
        return sum(v * v for v in d)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int[] d = new int[n];
        long s = 0;
        int mx = 0;
        int k = k1 + k2;
        for (int i = 0; i < n; ++i) {
            d[i] = Math.abs(nums1[i] - nums2[i]);
            s += d[i];
            mx = Math.max(mx, d[i]);
        }
        if (s <= k) {
            return 0;
        }
        int left = 0, right = mx;
        while (left < right) {
            int mid = (left + right) >> 1;
            long t = 0;
            for (int v : d) {
                t += Math.max(v - mid, 0);
            }
            if (t <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            k -= Math.max(0, d[i] - left);
            d[i] = Math.min(d[i], left);
        }
        for (int i = 0; i < n && k > 0; ++i) {
            if (d[i] == left) {
                --k;
                --d[i];
            }
        }
        long ans = 0;
        for (int v : d) {
            ans += (long) v * v;
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
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> d(n);
        ll s = 0;
        int mx = 0;
        int k = k1 + k2;
        for (int i = 0; i < n; ++i) {
            d[i] = abs(nums1[i] - nums2[i]);
            s += d[i];
            mx = max(mx, d[i]);
        }
        if (s <= k) return 0;
        int left = 0, right = mx;
        while (left < right) {
            int mid = (left + right) >> 1;
            ll t = 0;
            for (int v : d) t += max(v - mid, 0);
            if (t <= k)
                right = mid;
            else
                left = mid + 1;
        }
        for (int i = 0; i < n; ++i) {
            k -= max(0, d[i] - left);
            d[i] = min(d[i], left);
        }
        for (int i = 0; i < n && k; ++i) {
            if (d[i] == left) {
                --k;
                --d[i];
            }
        }
        ll ans = 0;
        for (int v : d) ans += 1ll * v * v;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSumSquareDiff(nums1 []int, nums2 []int, k1 int, k2 int) int64 {
	k := k1 + k2
	s, mx := 0, 0
	n := len(nums1)
	d := make([]int, n)
	for i, v := range nums1 {
		d[i] = abs(v - nums2[i])
		s += d[i]
		mx = max(mx, d[i])
	}
	if s <= k {
		return 0
	}
	left, right := 0, mx
	for left < right {
		mid := (left + right) >> 1
		t := 0
		for _, v := range d {
			t += max(v-mid, 0)
		}
		if t <= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	for i, v := range d {
		k -= max(v-left, 0)
		d[i] = min(v, left)
	}
	for i, v := range d {
		if k <= 0 {
			break
		}
		if v == left {
			d[i]--
			k--
		}
	}
	ans := 0
	for _, v := range d {
		ans += v * v
	}
	return int64(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，长度为&nbsp;<code>n</code>&nbsp;。</p>

<p>数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;的 <strong>差值平方和</strong>&nbsp;定义为所有满足&nbsp;<code>0 &lt;= i &lt; n</code>&nbsp;的&nbsp;<code>(nums1[i] - nums2[i])<sup>2</sup></code>&nbsp;之和。</p>

<p>同时给你两个正整数&nbsp;<code>k1</code> 和&nbsp;<code>k2</code>&nbsp;。你可以将&nbsp;<code>nums1</code>&nbsp;中的任意元素&nbsp;<code>+1</code> 或者&nbsp;<code>-1</code>&nbsp;至多&nbsp;<code>k1</code>&nbsp;次。类似的，你可以将&nbsp;<code>nums2</code>&nbsp;中的任意元素&nbsp;<code>+1</code> 或者&nbsp;<code>-1</code>&nbsp;至多&nbsp;<code>k2</code>&nbsp;次。</p>

<p>请你返回修改数组<em>&nbsp;</em><code>nums1</code><em>&nbsp;</em>至多<em>&nbsp;</em><code>k1</code>&nbsp;次且修改数组<em>&nbsp;</em><code>nums2</code>&nbsp;至多 <code>k2</code><em>&nbsp;</em>次后的最小&nbsp;<strong>差值平方和</strong>&nbsp;。</p>

<p><strong>注意：</strong>你可以将数组中的元素变成&nbsp;<strong>负</strong>&nbsp;整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
<b>输出：</b>579
<b>解释：</b>nums1 和 nums2 中的元素不能修改，因为 k1 = 0 和 k2 = 0 。
差值平方和为：(1 - 2)<sup>2 </sup>+ (2 - 10)<sup>2 </sup>+ (3 - 20)<sup>2 </sup>+ (4 - 19)<sup>2</sup>&nbsp;= 579 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
<b>输出：</b>43
<b>解释：</b>一种得到最小差值平方和的方式为：
- 将 nums1[0] 增加一次。
- 将 nums2[2] 增加一次。
最小差值平方和为：
(2 - 5)<sup>2 </sup>+ (4 - 8)<sup>2 </sup>+ (10 - 7)<sup>2 </sup>+ (12 - 9)<sup>2</sup>&nbsp;= 43 。
注意，也有其他方式可以得到最小差值平方和，但没有得到比 43 更小答案的方案。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k1, k2 &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSumSquareDiff(
        self, nums1: List[int], nums2: List[int], k1: int, k2: int
    ) -> int:
        d = [abs(a - b) for a, b in zip(nums1, nums2)]
        k = k1 + k2
        if sum(d) <= k:
            return 0
        left, right = 0, max(d)
        while left < right:
            mid = (left + right) >> 1
            if sum(max(v - mid, 0) for v in d) <= k:
                right = mid
            else:
                left = mid + 1
        for i, v in enumerate(d):
            d[i] = min(left, v)
            k -= max(0, v - left)
        for i, v in enumerate(d):
            if k == 0:
                break
            if v == left:
                k -= 1
                d[i] -= 1
        return sum(v * v for v in d)
```

#### Java

```java
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int[] d = new int[n];
        long s = 0;
        int mx = 0;
        int k = k1 + k2;
        for (int i = 0; i < n; ++i) {
            d[i] = Math.abs(nums1[i] - nums2[i]);
            s += d[i];
            mx = Math.max(mx, d[i]);
        }
        if (s <= k) {
            return 0;
        }
        int left = 0, right = mx;
        while (left < right) {
            int mid = (left + right) >> 1;
            long t = 0;
            for (int v : d) {
                t += Math.max(v - mid, 0);
            }
            if (t <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            k -= Math.max(0, d[i] - left);
            d[i] = Math.min(d[i], left);
        }
        for (int i = 0; i < n && k > 0; ++i) {
            if (d[i] == left) {
                --k;
                --d[i];
            }
        }
        long ans = 0;
        for (int v : d) {
            ans += (long) v * v;
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
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> d(n);
        ll s = 0;
        int mx = 0;
        int k = k1 + k2;
        for (int i = 0; i < n; ++i) {
            d[i] = abs(nums1[i] - nums2[i]);
            s += d[i];
            mx = max(mx, d[i]);
        }
        if (s <= k) return 0;
        int left = 0, right = mx;
        while (left < right) {
            int mid = (left + right) >> 1;
            ll t = 0;
            for (int v : d) t += max(v - mid, 0);
            if (t <= k)
                right = mid;
            else
                left = mid + 1;
        }
        for (int i = 0; i < n; ++i) {
            k -= max(0, d[i] - left);
            d[i] = min(d[i], left);
        }
        for (int i = 0; i < n && k; ++i) {
            if (d[i] == left) {
                --k;
                --d[i];
            }
        }
        ll ans = 0;
        for (int v : d) ans += 1ll * v * v;
        return ans;
    }
};
```

#### Go

```go
func minSumSquareDiff(nums1 []int, nums2 []int, k1 int, k2 int) int64 {
	k := k1 + k2
	s, mx := 0, 0
	n := len(nums1)
	d := make([]int, n)
	for i, v := range nums1 {
		d[i] = abs(v - nums2[i])
		s += d[i]
		mx = max(mx, d[i])
	}
	if s <= k {
		return 0
	}
	left, right := 0, mx
	for left < right {
		mid := (left + right) >> 1
		t := 0
		for _, v := range d {
			t += max(v-mid, 0)
		}
		if t <= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	for i, v := range d {
		k -= max(v-left, 0)
		d[i] = min(v, left)
	}
	for i, v := range d {
		if k <= 0 {
			break
		}
		if v == left {
			d[i]--
			k--
		}
	}
	ans := 0
	for _, v := range d {
		ans += v * v
	}
	return int64(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2334. 元素值大于变化阈值的子数组](https://leetcode.cn/problems/subarray-with-elements-greater-than-varying-threshold){#2334}

{{< tabs "2334" >}}

{{% tab "python" %}}
```python
class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        for i, v in enumerate(nums):
            k = right[i] - left[i] - 1
            if v > threshold // k:
                return k
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int validSubarraySize(int[] nums, int threshold) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] >= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] >= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int k = right[i] - left[i] - 1;
            if (v > threshold / k) {
                return k;
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
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] >= v) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] >= v) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int k = right[i] - left[i] - 1;
            if (v > threshold / k) return k;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validSubarraySize(nums []int, threshold int) int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	var stk []int
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		v := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, v := range nums {
		k := right[i] - left[i] - 1
		if v > threshold/k {
			return k
		}
	}
	return -1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>threshold</code>&nbsp;。</p>

<p>找到长度为 <code>k</code>&nbsp;的&nbsp;<code>nums</code>&nbsp;子数组，满足数组中&nbsp;<strong>每个</strong>&nbsp;元素都 <strong>大于</strong>&nbsp;<code>threshold / k</code>&nbsp;。</p>

<p>请你返回满足要求的 <strong>任意</strong>&nbsp;子数组的 <strong>大小</strong>&nbsp;。如果没有这样的子数组，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><strong>子数组</strong> 是数组中一段连续非空的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,3,4,3,1], threshold = 6
<b>输出：</b>3
<b>解释：</b>子数组 [3,4,3] 大小为 3 ，每个元素都大于 6 / 3 = 2 。
注意这是唯一合法的子数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [6,5,6,5,8], threshold = 7
<b>输出：</b>1
<b>解释：</b>子数组 [8] 大小为 1 ，且 8 &gt; 7 / 1 = 7 。所以返回 1 。
注意子数组 [6,5] 大小为 2 ，每个元素都大于 7 / 2 = 3.5 。
类似的，子数组 [6,5,6] ，[6,5,6,5] ，[6,5,6,5,8] 都是符合条件的子数组。
所以返回 2, 3, 4 和 5 都可以。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], threshold &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

考虑**从大到小遍历**数组 $nums$ 中的每个元素 $v$，用并查集来维护以 $v$ 作为子数组最小值的连通块。

遍历过程中：

$v$ 在数组 $nums$ 中的下标为 $i$，若下标 $i-1$ 对应的元素遍历过，可以将 $i-1$ 与 $i$ 进行合并，同理，若下标 $i+1$ 对应的元素也遍历过了，将 $i$ 与 $i+1$ 合并。合并过程中更新连通块的大小。

$v$ 作为当前连通块的最小值，当前连通块的大小为 $size[find(i)]$，若 $v>\frac{\textit{threshold}}{size[find(i)]}$，说明找到了满足条件的子数组，返回 $true$。

否则遍历结束，返回 $-1$。

时间复杂度 $O(nlogn)$。

相似题目：

-   [1562. 查找大小为 M 的最新分组](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1562.Find%20Latest%20Group%20of%20Size%20M/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def merge(a, b):
            pa, pb = find(a), find(b)
            if pa == pb:
                return
            p[pa] = pb
            size[pb] += size[pa]

        n = len(nums)
        p = list(range(n))
        size = [1] * n
        arr = sorted(zip(nums, range(n)), reverse=True)
        vis = [False] * n
        for v, i in arr:
            if i and vis[i - 1]:
                merge(i, i - 1)
            if i < n - 1 and vis[i + 1]:
                merge(i, i + 1)
            if v > threshold // size[find(i)]:
                return size[find(i)]
            vis[i] = True
        return -1
```

#### Java

```java
class Solution {
    private int[] p;
    private int[] size;

    public int validSubarraySize(int[] nums, int threshold) {
        int n = nums.length;
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        Arrays.sort(arr, (a, b) -> b[0] - a[0]);
        boolean[] vis = new boolean[n];
        for (int[] e : arr) {
            int v = e[0], i = e[1];
            if (i > 0 && vis[i - 1]) {
                merge(i, i - 1);
            }
            if (i < n - 1 && vis[i + 1]) {
                merge(i, i + 1);
            }
            if (v > threshold / size[find(i)]) {
                return size[find(i)];
            }
            vis[i] = true;
        }
        return -1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return;
        }
        p[pa] = pb;
        size[pb] += size[pa];
    }
}
```

#### C++

```cpp
using pii = pair<int, int>;

class Solution {
public:
    vector<int> p;
    vector<int> size;

    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        size.assign(n, 1);
        vector<pii> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());
        vector<bool> vis(n);
        for (int j = n - 1; ~j; --j) {
            int v = arr[j].first, i = arr[j].second;
            if (i && vis[i - 1]) merge(i, i - 1);
            if (j < n - 1 && vis[i + 1]) merge(i, i + 1);
            if (v > threshold / size[find(i)]) return size[find(i)];
            vis[i] = true;
        }
        return -1;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        p[pa] = pb;
        size[pb] += size[pa];
    }
};
```

#### Go

```go
func validSubarraySize(nums []int, threshold int) int {
	n := len(nums)
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	merge := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa == pb {
			return
		}
		p[pa] = pb
		size[pb] += size[pa]
	}

	arr := make([][]int, n)
	for i, v := range nums {
		arr[i] = []int{v, i}
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i][0] > arr[j][0]
	})
	vis := make([]bool, n)
	for _, e := range arr {
		v, i := e[0], e[1]
		if i > 0 && vis[i-1] {
			merge(i, i-1)
		}
		if i < n-1 && vis[i+1] {
			merge(i, i+1)
		}
		if v > threshold/size[find(i)] {
			return size[find(i)]
		}
		vis[i] = true
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调栈

利用单调栈，得到以当前元素 $nums[i]$ 作为最小元素的左右边界 $left[i]$（左边第一个比 $nums[i]$ 小的元素的位置）, $right[i]$（右边第一个比 $nums[i]$ 小的元素的位置）。

那么对于当前元素 $nums[i]$，有 $k=right[i]-left[i]-1$，若 $nums[i]>\frac{\textit{threshold}}{k}$，说明找到了满足条件的子数组，返回 $true$。

否则遍历结束，返回 $-1$。

时间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        for i, v in enumerate(nums):
            k = right[i] - left[i] - 1
            if v > threshold // k:
                return k
        return -1
```

#### Java

```java
class Solution {
    public int validSubarraySize(int[] nums, int threshold) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] >= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] >= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int k = right[i] - left[i] - 1;
            if (v > threshold / k) {
                return k;
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
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] >= v) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] >= v) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int k = right[i] - left[i] - 1;
            if (v > threshold / k) return k;
        }
        return -1;
    }
};
```

#### Go

```go
func validSubarraySize(nums []int, threshold int) int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	var stk []int
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		v := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, v := range nums {
		k := right[i] - left[i] - 1
		if v > threshold/k {
			return k
		}
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2335. 装满杯子需要的最短总时长](https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups){#2335}

{{< tabs "2335" >}}

{{% tab "python" %}}
```python
class Solution:
    def fillCups(self, amount: List[int]) -> int:
        amount.sort()
        if amount[0] + amount[1] <= amount[2]:
            return amount[2]
        return (sum(amount) + 1) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int fillCups(int[] amount) {
        Arrays.sort(amount);
        if (amount[0] + amount[1] <= amount[2]) {
            return amount[2];
        }
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2]) {
            return amount[2];
        }
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fillCups(amount []int) int {
	sort.Ints(amount)
	if amount[0]+amount[1] <= amount[2] {
		return amount[2]
	}
	return (amount[0] + amount[1] + amount[2] + 1) / 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fillCups(amount: number[]): number {
    amount.sort((a, b) => a - b);
    let [a, b, c] = amount;
    let diff = a + b - c;
    if (diff <= 0) return c;
    else return Math.floor((diff + 1) / 2) + c;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn fill_cups(mut amount: Vec<i32>) -> i32 {
        amount.sort();
        let dif = amount[0] + amount[1] - amount[2];
        if dif <= 0 {
            return amount[2];
        }
        (dif + 1) / 2 + amount[2]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一台饮水机，可以制备冷水、温水和热水。每秒钟，可以装满 <code>2</code> 杯 <strong>不同</strong> 类型的水或者 <code>1</code> 杯任意类型的水。</p>

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>3</code> 的整数数组 <code>amount</code> ，其中 <code>amount[0]</code>、<code>amount[1]</code> 和 <code>amount[2]</code> 分别表示需要装满冷水、温水和热水的杯子数量。返回装满所有杯子所需的 <strong>最少</strong> 秒数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>amount = [1,4,2]
<strong>输出：</strong>4
<strong>解释：</strong>下面给出一种方案：
第 1 秒：装满一杯冷水和一杯温水。
第 2 秒：装满一杯温水和一杯热水。
第 3 秒：装满一杯温水和一杯热水。
第 4 秒：装满一杯温水。
可以证明最少需要 4 秒才能装满所有杯子。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>amount = [5,4,4]
<strong>输出：</strong>7
<strong>解释：</strong>下面给出一种方案：
第 1 秒：装满一杯冷水和一杯热水。
第 2 秒：装满一杯冷水和一杯温水。
第 3 秒：装满一杯冷水和一杯温水。
第 4 秒：装满一杯温水和一杯热水。
第 5 秒：装满一杯冷水和一杯热水。
第 6 秒：装满一杯冷水和一杯温水。
第 7 秒：装满一杯热水。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>amount = [5,0,0]
<strong>输出：</strong>5
<strong>解释：</strong>每秒装满一杯冷水。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>amount.length == 3</code></li>
	<li><code>0 &lt;= amount[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们可以每次贪心地选择其中较大的两个数进行减一操作（最多减为 $0$），直至所有数变为 $0$。

时间复杂度 $O(S)$，空间复杂度 $O(1)$。其中 $S$ 为数组 `amount` 中所有数的和，本题中 $S \leq 300$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fillCups(self, amount: List[int]) -> int:
        ans = 0
        while sum(amount):
            amount.sort()
            ans += 1
            amount[2] -= 1
            amount[1] = max(0, amount[1] - 1)
        return ans
```

#### Java

```java
class Solution {
    public int fillCups(int[] amount) {
        int ans = 0;
        while (amount[0] + amount[1] + amount[2] > 0) {
            Arrays.sort(amount);
            ++ans;
            amount[2]--;
            amount[1] = Math.max(0, amount[1] - 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while (amount[0] + amount[1] + amount[2]) {
            sort(amount.begin(), amount.end());
            ++ans;
            amount[2]--;
            amount[1] = max(0, amount[1] - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func fillCups(amount []int) int {
	ans := 0
	for amount[0]+amount[1]+amount[2] > 0 {
		sort.Ints(amount)
		ans++
		amount[2]--
		if amount[1] > 0 {
			amount[1]--
		}
	}
	return ans
}
```

#### TypeScript

```ts
function fillCups(amount: number[]): number {
    amount.sort((a, b) => a - b);
    let [a, b, c] = amount;
    let diff = a + b - c;
    if (diff <= 0) return c;
    else return Math.floor((diff + 1) / 2) + c;
}
```

#### Rust

```rust
impl Solution {
    pub fn fill_cups(mut amount: Vec<i32>) -> i32 {
        amount.sort();
        let dif = amount[0] + amount[1] - amount[2];
        if dif <= 0 {
            return amount[2];
        }
        (dif + 1) / 2 + amount[2]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 分类讨论

我们可以将数组 `amount` 排序，设 $a$, $b$, $c$ 分别为数组 `amount` 中的三个数，有以下两种情况：

-   如果 $a + b \leq c$，此时我们只需要 $c$ 次操作即可将所有数变为 $0$，因此答案为 $c$。
-   如果 $a + b > c$，每一次操作我们都可以将其中两个数减一，最终匹配完，或者剩下最后一个数（取决于总和是偶数还是奇数），因此答案为 $\left \lfloor \frac{a + b + c + 1}{2}  \right \rfloor$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fillCups(self, amount: List[int]) -> int:
        amount.sort()
        if amount[0] + amount[1] <= amount[2]:
            return amount[2]
        return (sum(amount) + 1) // 2
```

#### Java

```java
class Solution {
    public int fillCups(int[] amount) {
        Arrays.sort(amount);
        if (amount[0] + amount[1] <= amount[2]) {
            return amount[2];
        }
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2]) {
            return amount[2];
        }
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
};
```

#### Go

```go
func fillCups(amount []int) int {
	sort.Ints(amount)
	if amount[0]+amount[1] <= amount[2] {
		return amount[2]
	}
	return (amount[0] + amount[1] + amount[2] + 1) / 2
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2336. 无限集中的最小数字](https://leetcode.cn/problems/smallest-number-in-infinite-set){#2336}

{{< tabs "2336" >}}

{{% tab "python" %}}
```python
class SmallestInfiniteSet:
    def __init__(self):
        self.s = SortedSet(range(1, 1001))

    def popSmallest(self) -> int:
        x = self.s[0]
        self.s.remove(x)
        return x

    def addBack(self, num: int) -> None:
        self.s.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SmallestInfiniteSet {
    private TreeSet<Integer> s = new TreeSet<>();

    public SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            s.add(i);
        }
    }

    public int popSmallest() {
        return s.pollFirst();
    }

    public void addBack(int num) {
        s.add(num);
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            s.insert(i);
        }
    }

    int popSmallest() {
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    }

    void addBack(int num) {
        s.insert(num);
    }

private:
    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SmallestInfiniteSet struct {
	s *treemap.Map
}

func Constructor() SmallestInfiniteSet {
	s := treemap.NewWithIntComparator()
	for i := 1; i <= 1000; i++ {
		s.Put(i, nil)
	}
	return SmallestInfiniteSet{s}
}

func (this *SmallestInfiniteSet) PopSmallest() int {
	x, _ := this.s.Min()
	this.s.Remove(x.(int))
	return x.(int)
}

func (this *SmallestInfiniteSet) AddBack(num int) {
	this.s.Put(num, nil)
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class SmallestInfiniteSet {
    private pq: typeof MinPriorityQueue;
    private s: Set<number>;

    constructor() {
        this.pq = new MinPriorityQueue();
        this.s = new Set();
        for (let i = 1; i <= 1000; i++) {
            this.pq.enqueue(i, i);
            this.s.add(i);
        }
    }

    popSmallest(): number {
        const x = this.pq.dequeue()?.element;
        this.s.delete(x);
        return x;
    }

    addBack(num: number): void {
        if (!this.s.has(num)) {
            this.pq.enqueue(num, num);
            this.s.add(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BTreeSet;

struct SmallestInfiniteSet {
    s: BTreeSet<i32>,
}

impl SmallestInfiniteSet {
    fn new() -> Self {
        let mut set = BTreeSet::new();
        for i in 1..=1000 {
            set.insert(i);
        }
        SmallestInfiniteSet { s: set }
    }

    fn pop_smallest(&mut self) -> i32 {
        let x = *self.s.iter().next().unwrap();
        self.s.remove(&x);
        x
    }

    fn add_back(&mut self, num: i32) {
        self.s.insert(num);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一个包含所有正整数的集合 <code>[1, 2, 3, 4, 5, ...]</code> 。</p>

<p>实现 <code>SmallestInfiniteSet</code> 类：</p>

<ul>
	<li><code>SmallestInfiniteSet()</code> 初始化 <strong>SmallestInfiniteSet</strong> 对象以包含 <strong>所有</strong> 正整数。</li>
	<li><code>int popSmallest()</code> <strong>移除</strong> 并返回该无限集中的最小整数。</li>
	<li><code>void addBack(int num)</code> 如果正整数 <code>num</code> <strong>不</strong> 存在于无限集中，则将一个 <code>num</code> <strong>添加</strong> 到该无限集中。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
<strong>输出</strong>
[null, null, 1, 2, 3, null, 1, 4, 5]

<strong>解释</strong>
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 已经在集合中，所以不做任何变更。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 2 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 3 ，并将其从集合中移除。
smallestInfiniteSet.addBack(1);    // 将 1 添加到该集合中。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 在上一步中被添加到集合中，
                                   // 且 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 4 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 5 ，并将其从集合中移除。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
	<li>最多调用 <code>popSmallest</code> 和 <code>addBack</code> 方法 <strong>共计</strong> <code>1000</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合 + 模拟

我们注意到，题目中集合的元素范围是 $[1, 1000]$，并且我们需要支持的操作有：

-   `popSmallest`：弹出集合中的最小元素
-   `addBack`：向集合中添加元素

因此，我们可以使用有序集合来模拟，不妨记有序集合为 $s$，集合中的元素为 $s_1, s_2, \cdots, s_n$，其中 $n$ 为有序集合中的元素个数。本题中 $n \le 1000$。

我们在初始化时，将 $[1, 1000]$ 中的所有元素加入有序集合中。时间复杂度 $O(n \times \log n)$。

在 `popSmallest` 操作中，我们只需要弹出有序集合中的第一个元素即可。单次操作时间复杂度 $O(\log n)$。

在 `addBack` 操作中，我们只需要将元素加入有序集合中即可。单次操作时间复杂度 $O(\log n)$。

空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class SmallestInfiniteSet:
    def __init__(self):
        self.s = SortedSet(range(1, 1001))

    def popSmallest(self) -> int:
        x = self.s[0]
        self.s.remove(x)
        return x

    def addBack(self, num: int) -> None:
        self.s.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
```

#### Java

```java
class SmallestInfiniteSet {
    private TreeSet<Integer> s = new TreeSet<>();

    public SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            s.add(i);
        }
    }

    public int popSmallest() {
        return s.pollFirst();
    }

    public void addBack(int num) {
        s.add(num);
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */
```

#### C++

```cpp
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            s.insert(i);
        }
    }

    int popSmallest() {
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    }

    void addBack(int num) {
        s.insert(num);
    }

private:
    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
```

#### Go

```go
type SmallestInfiniteSet struct {
	s *treemap.Map
}

func Constructor() SmallestInfiniteSet {
	s := treemap.NewWithIntComparator()
	for i := 1; i <= 1000; i++ {
		s.Put(i, nil)
	}
	return SmallestInfiniteSet{s}
}

func (this *SmallestInfiniteSet) PopSmallest() int {
	x, _ := this.s.Min()
	this.s.Remove(x.(int))
	return x.(int)
}

func (this *SmallestInfiniteSet) AddBack(num int) {
	this.s.Put(num, nil)
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */
```

#### TypeScript

```ts
class SmallestInfiniteSet {
    private s: TreeSet<number>;

    constructor() {
        this.s = new TreeSet();
        for (let i = 1; i <= 1000; ++i) {
            this.s.add(i);
        }
    }

    popSmallest(): number {
        return this.s.shift()!;
    }

    addBack(num: number): void {
        this.s.add(num);
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
```

#### Rust

```rust
use std::collections::BTreeSet;

struct SmallestInfiniteSet {
    s: BTreeSet<i32>,
}

impl SmallestInfiniteSet {
    fn new() -> Self {
        let mut set = BTreeSet::new();
        for i in 1..=1000 {
            set.insert(i);
        }
        SmallestInfiniteSet { s: set }
    }

    fn pop_smallest(&mut self) -> i32 {
        let x = *self.s.iter().next().unwrap();
        self.s.remove(&x);
        x
    }

    fn add_back(&mut self, num: i32) {
        self.s.insert(num);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
class SmallestInfiniteSet {
    private pq: typeof MinPriorityQueue;
    private s: Set<number>;

    constructor() {
        this.pq = new MinPriorityQueue();
        this.s = new Set();
        for (let i = 1; i <= 1000; i++) {
            this.pq.enqueue(i, i);
            this.s.add(i);
        }
    }

    popSmallest(): number {
        const x = this.pq.dequeue()?.element;
        this.s.delete(x);
        return x;
    }

    addBack(num: number): void {
        if (!this.s.has(num)) {
            this.pq.enqueue(num, num);
            this.s.add(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2337. 移动片段得到字符串](https://leetcode.cn/problems/move-pieces-to-obtain-a-string){#2337}

{{< tabs "2337" >}}

{{% tab "python" %}}
```python
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        n = len(start)
        i = j = 0
        while 1:
            while i < n and start[i] == '_':
                i += 1
            while j < n and target[j] == '_':
                j += 1
            if i >= n and j >= n:
                return True
            if i >= n or j >= n or start[i] != target[j]:
                return False
            if start[i] == 'L' and i < j:
                return False
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canChange(String start, String target) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == '_') {
                ++i;
            }
            while (j < n && target.charAt(j) == '_') {
                ++j;
            }
            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n || start.charAt(i) != target.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i < j || start.charAt(i) == 'R' && i > j) {
                return false;
            }
            ++i;
            ++j;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == '_') ++i;
            while (j < n && target[j] == '_') ++j;
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canChange(start string, target string) bool {
	n := len(start)
	i, j := 0, 0
	for {
		for i < n && start[i] == '_' {
			i++
		}
		for j < n && target[j] == '_' {
			j++
		}
		if i == n && j == n {
			return true
		}
		if i == n || j == n || start[i] != target[j] {
			return false
		}
		if start[i] == 'L' && i < j {
			return false
		}
		if start[i] == 'R' && i > j {
			return false
		}
		i, j = i+1, j+1
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canChange(start: string, target: string): boolean {
    const n = start.length;
    let [i, j] = [0, 0];
    while (1) {
        while (i < n && start[i] === '_') {
            ++i;
        }
        while (j < n && target[j] === '_') {
            ++j;
        }
        if (i === n && j === n) {
            return true;
        }
        if (i === n || j === n || start[i] !== target[j]) {
            return false;
        }
        if ((start[i] === 'L' && i < j) || (start[i] === 'R' && i > j)) {
            return false;
        }
        ++i;
        ++j;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>start</code> 和 <code>target</code> ，长度均为 <code>n</code> 。每个字符串 <strong>仅</strong> 由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成，其中：</p>

<ul>
	<li>字符 <code>'L'</code> 和 <code>'R'</code> 表示片段，其中片段 <code>'L'</code> 只有在其左侧直接存在一个 <strong>空位</strong> 时才能向 <strong>左</strong> 移动，而片段 <code>'R'</code> 只有在其右侧直接存在一个 <strong>空位</strong> 时才能向 <strong>右</strong> 移动。</li>
	<li>字符 <code>'_'</code> 表示可以被 <strong>任意</strong> <code>'L'</code> 或 <code>'R'</code> 片段占据的空位。</li>
</ul>

<p>如果在移动字符串 <code>start</code> 中的片段任意次之后可以得到字符串 <code>target</code> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>start = "_L__R__R_", target = "L______RR"
<strong>输出：</strong>true
<strong>解释：</strong>可以从字符串 start 获得 target ，需要进行下面的移动：
- 将第一个片段向左移动一步，字符串现在变为 "<strong>L</strong>___R__R_" 。
- 将最后一个片段向右移动一步，字符串现在变为 "L___R___<strong>R</strong>" 。
- 将第二个片段向右移动三步，字符串现在变为 "L______<strong>R</strong>R" 。
可以从字符串 start 得到 target ，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>start = "R_L_", target = "__LR"
<strong>输出：</strong>false
<strong>解释：</strong>字符串 start 中的 'R' 片段可以向右移动一步得到 "_<strong>R</strong>L_" 。
但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>start = "_R", target = "R_"
<strong>输出：</strong>false
<strong>解释：</strong>字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == start.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>start</code> 和 <code>target</code> 由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

替换操作实际上是将 `L` 往左移动（`L` 左边为 `_` 时才能移动），`R` 往右移动（`R` 右边是 `_` 时才能移动），但 `L` 无法穿过 `R`。所以，如果去掉 `start` 和 `target` 中的所有 `_`，剩下的字符应该是相同的，否则返回 `false`。

我们使用双指针 $i$ 和 $j$ 从头到尾遍历 `start` 和 `target`：

-   如果当前字符为 `L` 且 $i\lt j$，那么这个 `L` 无法向右移动，返回 `false`；
-   如果当前字符为 `R` 且 $i\gt j$，那么这个 `R` 无法向左移动，返回 `false`。

如果双指针均遍历到末尾，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 表示字符串 `start` 或 `target` 的长度。

相似题目：

-   [777. 在 LR 字符串中交换相邻字符](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0777.Swap%20Adjacent%20in%20LR%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        a = [(v, i) for i, v in enumerate(start) if v != '_']
        b = [(v, i) for i, v in enumerate(target) if v != '_']
        if len(a) != len(b):
            return False
        for (c, i), (d, j) in zip(a, b):
            if c != d:
                return False
            if c == 'L' and i < j:
                return False
            if c == 'R' and i > j:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean canChange(String start, String target) {
        List<int[]> a = f(start);
        List<int[]> b = f(target);
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); ++i) {
            int[] x = a.get(i);
            int[] y = b.get(i);
            if (x[0] != y[0]) {
                return false;
            }
            if (x[0] == 1 && x[1] < y[1]) {
                return false;
            }
            if (x[0] == 2 && x[1] > y[1]) {
                return false;
            }
        }
        return true;
    }

    private List<int[]> f(String s) {
        List<int[]> res = new ArrayList<>();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'L') {
                res.add(new int[] {1, i});
            } else if (s.charAt(i) == 'R') {
                res.add(new int[] {2, i});
            }
        }
        return res;
    }
}
```

#### C++

```cpp
using pii = pair<int, int>;

class Solution {
public:
    bool canChange(string start, string target) {
        auto a = f(start);
        auto b = f(target);
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); ++i) {
            auto x = a[i], y = b[i];
            if (x.first != y.first) return false;
            if (x.first == 1 && x.second < y.second) return false;
            if (x.first == 2 && x.second > y.second) return false;
        }
        return true;
    }

    vector<pair<int, int>> f(string s) {
        vector<pii> res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L')
                res.push_back({1, i});
            else if (s[i] == 'R')
                res.push_back({2, i});
        }
        return res;
    }
};
```

#### Go

```go
func canChange(start string, target string) bool {
	f := func(s string) [][]int {
		res := [][]int{}
		for i, c := range s {
			if c == 'L' {
				res = append(res, []int{1, i})
			} else if c == 'R' {
				res = append(res, []int{2, i})
			}
		}
		return res
	}

	a, b := f(start), f(target)
	if len(a) != len(b) {
		return false
	}
	for i, x := range a {
		y := b[i]
		if x[0] != y[0] {
			return false
		}
		if x[0] == 1 && x[1] < y[1] {
			return false
		}
		if x[0] == 2 && x[1] > y[1] {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canChange(start: string, target: string): boolean {
    if (
        [...start].filter(c => c !== '_').join('') !== [...target].filter(c => c !== '_').join('')
    ) {
        return false;
    }
    const n = start.length;
    let i = 0;
    let j = 0;
    while (i < n || j < n) {
        while (start[i] === '_') {
            i++;
        }
        while (target[j] === '_') {
            j++;
        }
        if (start[i] === 'R') {
            if (i > j) {
                return false;
            }
        }
        if (start[i] === 'L') {
            if (i < j) {
                return false;
            }
        }
        i++;
        j++;
    }
    return true;
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
    def canChange(self, start: str, target: str) -> bool:
        n = len(start)
        i = j = 0
        while 1:
            while i < n and start[i] == '_':
                i += 1
            while j < n and target[j] == '_':
                j += 1
            if i >= n and j >= n:
                return True
            if i >= n or j >= n or start[i] != target[j]:
                return False
            if start[i] == 'L' and i < j:
                return False
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
```

#### Java

```java
class Solution {
    public boolean canChange(String start, String target) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == '_') {
                ++i;
            }
            while (j < n && target.charAt(j) == '_') {
                ++j;
            }
            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n || start.charAt(i) != target.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i < j || start.charAt(i) == 'R' && i > j) {
                return false;
            }
            ++i;
            ++j;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == '_') ++i;
            while (j < n && target[j] == '_') ++j;
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
    }
};
```

#### Go

```go
func canChange(start string, target string) bool {
	n := len(start)
	i, j := 0, 0
	for {
		for i < n && start[i] == '_' {
			i++
		}
		for j < n && target[j] == '_' {
			j++
		}
		if i == n && j == n {
			return true
		}
		if i == n || j == n || start[i] != target[j] {
			return false
		}
		if start[i] == 'L' && i < j {
			return false
		}
		if start[i] == 'R' && i > j {
			return false
		}
		i, j = i+1, j+1
	}
}
```

#### TypeScript

```ts
function canChange(start: string, target: string): boolean {
    const n = start.length;
    let [i, j] = [0, 0];
    while (1) {
        while (i < n && start[i] === '_') {
            ++i;
        }
        while (j < n && target[j] === '_') {
            ++j;
        }
        if (i === n && j === n) {
            return true;
        }
        if (i === n || j === n || start[i] !== target[j]) {
            return false;
        }
        if ((start[i] === 'L' && i < j) || (start[i] === 'R' && i > j)) {
            return false;
        }
        ++i;
        ++j;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2338. 统计理想数组的数目](https://leetcode.cn/problems/count-the-number-of-ideal-arrays){#2338}

{{< tabs "2338" >}}

{{% tab "python" %}}
```python
class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        c = [[0] * 16 for _ in range(n)]
        mod = 10**9 + 7
        for i in range(n):
            for j in range(min(16, i + 1)):
                c[i][j] = 1 if j == 0 else (c[i - 1][j] + c[i - 1][j - 1]) % mod
        f = [[0] * 16 for _ in range(maxValue + 1)]
        for i in range(1, maxValue + 1):
            f[i][1] = 1
        for j in range(1, 15):
            for i in range(1, maxValue + 1):
                k = 2
                while k * i <= maxValue:
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod
                    k += 1
        ans = 0
        for i in range(1, maxValue + 1):
            for j in range(1, 16):
                ans = (ans + f[i][j] * c[-1][j - 1]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int idealArrays(int n, int maxValue) {
        final int mod = (int) 1e9 + 7;
        int[][] c = new int[n][16];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i && j < 16; ++j) {
                c[i][j] = j == 0 ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        long[][] f = new long[maxValue + 1][16];
        for (int i = 1; i <= maxValue; ++i) {
            f[i][1] = 1;
        }
        for (int j = 1; j < 15; ++j) {
            for (int i = 1; i <= maxValue; ++i) {
                int k = 2;
                for (; k * i <= maxValue; ++k) {
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod;
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = 1; j < 16; ++j) {
                ans = (ans + f[i][j] * c[n - 1][j - 1]) % mod;
            }
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int mod = 1e9 + 7;
        vector<vector<int>> c(n, vector<int>(16));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i && j < 16; ++j) {
                if (j == 0) {
                    c[i][j] = 1;
                } else {
                    c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
                }
            }
        }

        vector<vector<long long>> f(maxValue + 1, vector<long long>(16));
        for (int i = 1; i <= maxValue; ++i) {
            f[i][1] = 1;
        }

        for (int j = 1; j < 15; ++j) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int k = 2; k * i <= maxValue; ++k) {
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod;
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = 1; j < 16; ++j) {
                ans = (ans + f[i][j] * c[n - 1][j - 1]) % mod;
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func idealArrays(n int, maxValue int) (ans int) {
	const mod = int(1e9 + 7)
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, 16)
		for j := 0; j <= i && j < 16; j++ {
			if j == 0 {
				c[i][j] = 1
			} else {
				c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod
			}
		}
	}

	f := make([][16]int, maxValue+1)
	for i := 1; i <= maxValue; i++ {
		f[i][1] = 1
	}
	for j := 1; j < 15; j++ {
		for i := 1; i <= maxValue; i++ {
			for k := 2; k*i <= maxValue; k++ {
				f[k*i][j+1] = (f[k*i][j+1] + f[i][j]) % mod
			}
		}
	}

	for i := 1; i <= maxValue; i++ {
		for j := 1; j < 16; j++ {
			ans = (ans + f[i][j]*c[n-1][j-1]) % mod
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function idealArrays(n: number, maxValue: number): number {
    const mod = 1e9 + 7;

    const c: number[][] = Array.from({ length: n }, () => Array(16).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= i && j < 16; j++) {
            if (j === 0) {
                c[i][j] = 1;
            } else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }

    const f: number[][] = Array.from({ length: maxValue + 1 }, () => Array(16).fill(0));
    for (let i = 1; i <= maxValue; i++) {
        f[i][1] = 1;
    }

    for (let j = 1; j < 15; j++) {
        for (let i = 1; i <= maxValue; i++) {
            for (let k = 2; k * i <= maxValue; k++) {
                f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod;
            }
        }
    }

    let ans = 0;
    for (let i = 1; i <= maxValue; i++) {
        for (let j = 1; j < 16; j++) {
            ans = (ans + f[i][j] * c[n - 1][j - 1]) % mod;
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

<p>给你两个整数 <code>n</code> 和 <code>maxValue</code> ，用于描述一个 <strong>理想数组</strong> 。</p>

<p>对于下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>arr</code> ，如果满足以下条件，则认为该数组是一个 <strong>理想数组</strong> ：</p>

<ul>
	<li>每个 <code>arr[i]</code> 都是从 <code>1</code> 到 <code>maxValue</code> 范围内的一个值，其中 <code>0 &lt;= i &lt; n</code> 。</li>
	<li>每个 <code>arr[i]</code> 都可以被 <code>arr[i - 1]</code> 整除，其中 <code>0 &lt; i &lt; n</code> 。</li>
</ul>

<p>返回长度为 <code>n</code> 的 <strong>不同</strong> 理想数组的数目。由于答案可能很大，返回对 <code>10<sup>9</sup> + 7</code> 取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, maxValue = 5
<strong>输出：</strong>10
<strong>解释：</strong>存在以下理想数组：
- 以 1 开头的数组（5 个）：[1,1]、[1,2]、[1,3]、[1,4]、[1,5]
- 以 2 开头的数组（2 个）：[2,2]、[2,4]
- 以 3 开头的数组（1 个）：[3,3]
- 以 4 开头的数组（1 个）：[4,4]
- 以 5 开头的数组（1 个）：[5,5]
共计 5 + 2 + 1 + 1 + 1 = 10 个不同理想数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 5, maxValue = 3
<strong>输出：</strong>11
<strong>解释：</strong>存在以下理想数组：
- 以 1 开头的数组（9 个）：
   - 不含其他不同值（1 个）：[1,1,1,1,1] 
   - 含一个不同值 2（4 个）：[1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - 含一个不同值 3（4 个）：[1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- 以 2 开头的数组（1 个）：[2,2,2,2,2]
- 以 3 开头的数组（1 个）：[3,3,3,3,3]
共计 9 + 1 + 1 = 11 个不同理想数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxValue &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

设 $f[i][j]$ 表示以 $i$ 结尾，且由 $j$ 个不同元素构成的序列的方案数。初始值 $f[i][1]=1$。

考虑 $n$ 个小球，最终划分为 $j$ 份，那么可以用“隔板法”，即在 $n-1$ 个位置上插入 $j-1$ 个隔板，那么组合数为 $c_{n-1}^{j-1}$。

我们可以预处理组合数 $c[i][j]$，根据递推公式 $c[i][j]=c[i-1][j]+c[i-1][j-1]$ 求得，特别地，当 $j=0$ 时，$c[i][j]=1$。

最终的答案为

$$
\sum\limits_{i=1}^{k}\sum\limits_{j=1}^{\log_2 k + 1} f[i][j] \times c_{n-1}^{j-1}
$$

其中 $k$ 表示数组的最大值，即 $\textit{maxValue}$。

时间复杂度 $O(m \times \log^2 m)$，空间复杂度 $O(m \times \log m)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        c = [[0] * 16 for _ in range(n)]
        mod = 10**9 + 7
        for i in range(n):
            for j in range(min(16, i + 1)):
                c[i][j] = 1 if j == 0 else (c[i - 1][j] + c[i - 1][j - 1]) % mod
        f = [[0] * 16 for _ in range(maxValue + 1)]
        for i in range(1, maxValue + 1):
            f[i][1] = 1
        for j in range(1, 15):
            for i in range(1, maxValue + 1):
                k = 2
                while k * i <= maxValue:
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod
                    k += 1
        ans = 0
        for i in range(1, maxValue + 1):
            for j in range(1, 16):
                ans = (ans + f[i][j] * c[-1][j - 1]) % mod
        return ans
```

#### Java

```java
class Solution {
    public int idealArrays(int n, int maxValue) {
        final int mod = (int) 1e9 + 7;
        int[][] c = new int[n][16];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i && j < 16; ++j) {
                c[i][j] = j == 0 ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        long[][] f = new long[maxValue + 1][16];
        for (int i = 1; i <= maxValue; ++i) {
            f[i][1] = 1;
        }
        for (int j = 1; j < 15; ++j) {
            for (int i = 1; i <= maxValue; ++i) {
                int k = 2;
                for (; k * i <= maxValue; ++k) {
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod;
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = 1; j < 16; ++j) {
                ans = (ans + f[i][j] * c[n - 1][j - 1]) % mod;
            }
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int mod = 1e9 + 7;
        vector<vector<int>> c(n, vector<int>(16));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i && j < 16; ++j) {
                if (j == 0) {
                    c[i][j] = 1;
                } else {
                    c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
                }
            }
        }

        vector<vector<long long>> f(maxValue + 1, vector<long long>(16));
        for (int i = 1; i <= maxValue; ++i) {
            f[i][1] = 1;
        }

        for (int j = 1; j < 15; ++j) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int k = 2; k * i <= maxValue; ++k) {
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod;
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = 1; j < 16; ++j) {
                ans = (ans + f[i][j] * c[n - 1][j - 1]) % mod;
            }
        }

        return ans;
    }
};
```

#### Go

```go
func idealArrays(n int, maxValue int) (ans int) {
	const mod = int(1e9 + 7)
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, 16)
		for j := 0; j <= i && j < 16; j++ {
			if j == 0 {
				c[i][j] = 1
			} else {
				c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod
			}
		}
	}

	f := make([][16]int, maxValue+1)
	for i := 1; i <= maxValue; i++ {
		f[i][1] = 1
	}
	for j := 1; j < 15; j++ {
		for i := 1; i <= maxValue; i++ {
			for k := 2; k*i <= maxValue; k++ {
				f[k*i][j+1] = (f[k*i][j+1] + f[i][j]) % mod
			}
		}
	}

	for i := 1; i <= maxValue; i++ {
		for j := 1; j < 16; j++ {
			ans = (ans + f[i][j]*c[n-1][j-1]) % mod
		}
	}
	return
}
```

#### TypeScript

```ts
function idealArrays(n: number, maxValue: number): number {
    const mod = 1e9 + 7;

    const c: number[][] = Array.from({ length: n }, () => Array(16).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= i && j < 16; j++) {
            if (j === 0) {
                c[i][j] = 1;
            } else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }

    const f: number[][] = Array.from({ length: maxValue + 1 }, () => Array(16).fill(0));
    for (let i = 1; i <= maxValue; i++) {
        f[i][1] = 1;
    }

    for (let j = 1; j < 15; j++) {
        for (let i = 1; i <= maxValue; i++) {
            for (let k = 2; k * i <= maxValue; k++) {
                f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % mod;
            }
        }
    }

    let ans = 0;
    for (let i = 1; i <= maxValue; i++) {
        for (let j = 1; j < 16; j++) {
            ans = (ans + f[i][j] * c[n - 1][j - 1]) % mod;
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

# [2339. 联赛的所有比赛 🔒](https://leetcode.cn/problems/all-the-matches-of-the-league){#2339}

{{< tabs "2339" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT t1.team_name AS home_team, t2.team_name AS away_team
FROM
    Teams AS t1
    JOIN Teams AS t2
WHERE t1.team_name != t2.team_name;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Teams</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| team_name   | varchar |
+-------------+---------+
team_name 是该表中具有唯一值的列。
此表的每一行都显示了团队的名称。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，获取联赛中所有比赛。每两支球队进行两场比赛，其中一支球队是主队&nbsp;<code>home_team</code>&nbsp;，另一支是客场队&nbsp;<code>away_team</code>。<br />
按 <strong>任意顺序</strong> 返回结果表。<br />
返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Teams 表:
+-------------+
| team_name   |
+-------------+
| Leetcode FC |
| Ahly SC     |
| Real Madrid |
+-------------+
<strong>输出:</strong> 
+-------------+-------------+
| home_team   | away_team   |
+-------------+-------------+
| Real Madrid | Leetcode FC |
| Real Madrid | Ahly SC     |
| Leetcode FC | Real Madrid |
| Leetcode FC | Ahly SC     |
| Ahly SC     | Real Madrid |
| Ahly SC     | Leetcode FC |
+-------------+-------------+
<strong>解释:</strong> 该联赛的所有比赛都列在表格中。
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
SELECT t1.team_name AS home_team, t2.team_name AS away_team
FROM
    Teams AS t1
    JOIN Teams AS t2
WHERE t1.team_name != t2.team_name;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
