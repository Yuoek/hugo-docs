---
title: "0530_二叉搜索树的最小绝对差"
date: 2025-10-08T18:36:17+08:00
weight: 4
tags: [二分查找, 二叉搜索树, 二叉树, 双指针, 哈希函数, 哈希表, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 树, 模拟, 深度优先搜索, 矩阵, 设计]
---

{{< markmap >}}
### [0530_二叉搜索树的最小绝对差](#530)
#### [树](#530)
#### [深度优先搜索](#530)
#### [广度优先搜索](#530)
#### [二叉搜索树](#530)
#### [二叉树](#530)
### [0531_孤独像素 I 🔒](#531)
#### [数组](#531)
#### [哈希表](#531)
#### [矩阵](#531)
### [0532_数组中的 k-diff 数对](#532)
#### [数组](#532)
#### [哈希表](#532)
#### [双指针](#532)
#### [二分查找](#532)
#### [排序](#532)
### [0533_孤独像素 II 🔒](#533)
#### [数组](#533)
#### [哈希表](#533)
#### [矩阵](#533)
### [0534_游戏玩法分析 III 🔒](#534)
#### [数据库](#534)
### [0535_TinyURL 的加密与解密](#535)
#### [设计](#535)
#### [哈希表](#535)
#### [字符串](#535)
#### [哈希函数](#535)
### [0536_从字符串生成二叉树 🔒](#536)
#### [栈](#536)
#### [树](#536)
#### [深度优先搜索](#536)
#### [字符串](#536)
#### [二叉树](#536)
### [0537_复数乘法](#537)
#### [数学](#537)
#### [字符串](#537)
#### [模拟](#537)
### [0538_把二叉搜索树转换为累加树](#538)
#### [树](#538)
#### [深度优先搜索](#538)
#### [二叉搜索树](#538)
#### [二叉树](#538)
### [0539_最小时间差](#539)
#### [数组](#539)
#### [数学](#539)
#### [字符串](#539)
#### [排序](#539)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0530_二叉搜索树的最小绝对差
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0531_孤独像素 I 🔒
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 0532_数组中的 k-diff 数对
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 0533_孤独像素 II 🔒
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 0534_游戏玩法分析 III 🔒
___
#### 数据库
---
### 0535_TinyURL 的加密与解密
___
#### 设计
___
#### 哈希表
___
#### 字符串
___
#### 哈希函数
---
### 0536_从字符串生成二叉树 🔒
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 字符串
___
#### 二叉树
---
### 0537_复数乘法
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0538_把二叉搜索树转换为累加树
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0539_最小时间差
___
#### 数组
___
#### 数学
___
#### 字符串
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 双指针 | 哈希函数 | 哈希表 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 设计 |

# [530. 二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst){#530}

{{< tabs "530" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nonlocal pre, ans
            ans = min(ans, root.val - pre)
            pre = root.val
            dfs(root.right)

        pre = -inf
        ans = inf
        dfs(root)
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
    private final int inf = 1 << 30;
    private int ans = inf;
    private int pre = -inf;

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
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
    int getMinimumDifference(TreeNode* root) {
        const int inf = 1 << 30;
        int ans = inf, pre = -inf;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans = min(ans, root->val - pre);
            pre = root->val;
            dfs(root->right);
        };
        dfs(root);
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
func getMinimumDifference(root *TreeNode) int {
	const inf int = 1 << 30
	ans, pre := inf, -inf
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		ans = min(ans, root.Val-pre)
		pre = root.Val
		dfs(root.Right)
	}
	dfs(root)
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

function getMinimumDifference(root: TreeNode | null): number {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
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
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        const inf: i32 = 1 << 30;
        let mut ans = inf;
        let mut pre = -inf;

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, ans: &mut i32, pre: &mut i32) {
            if let Some(n) = node {
                let n = n.borrow();
                dfs(n.left.clone(), ans, pre);
                *ans = (*ans).min(n.val - *pre);
                *pre = n.val;
                dfs(n.right.clone(), ans, pre);
            }
        }

        dfs(root, &mut ans, &mut pre);
        ans
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
 * @return {number}
 */
var getMinimumDifference = function (root) {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = root => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉搜索树的根节点 <code>root</code> ，返回 <strong>树中任意两不同节点值之间的最小差值</strong> 。</p>

<p>差值是一个正数，其数值等于两值之差的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0530.Minimum%20Absolute%20Difference%20in%20BST/images/bst1.jpg" style="width: 292px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [4,2,6,1,3]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0530.Minimum%20Absolute%20Difference%20in%20BST/images/bst2.jpg" style="width: 282px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [1,0,48,null,null,12,49]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目范围是 <code>[2, 10<sup>4</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与 783 <a href="https://leetcode.cn/problems/minimum-distance-between-bst-nodes/">https://leetcode.cn/problems/minimum-distance-between-bst-nodes/</a> 相同</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历

题目需要我们求任意两个节点值之间的最小差值，而二叉搜索树的中序遍历是一个递增序列，因此我们只需要求中序遍历中相邻两个节点值之间的最小差值即可。

我们可以使用递归的方法来实现中序遍历，过程中用一个变量 $\textit{pre}$ 来保存前一个节点的值，这样我们就可以在遍历的过程中求出相邻两个节点值之间的最小差值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉搜索树的节点个数。

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
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nonlocal pre, ans
            ans = min(ans, root.val - pre)
            pre = root.val
            dfs(root.right)

        pre = -inf
        ans = inf
        dfs(root)
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
    private final int inf = 1 << 30;
    private int ans = inf;
    private int pre = -inf;

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
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
    int getMinimumDifference(TreeNode* root) {
        const int inf = 1 << 30;
        int ans = inf, pre = -inf;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans = min(ans, root->val - pre);
            pre = root->val;
            dfs(root->right);
        };
        dfs(root);
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
func getMinimumDifference(root *TreeNode) int {
	const inf int = 1 << 30
	ans, pre := inf, -inf
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		ans = min(ans, root.Val-pre)
		pre = root.Val
		dfs(root.Right)
	}
	dfs(root)
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

function getMinimumDifference(root: TreeNode | null): number {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
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
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        const inf: i32 = 1 << 30;
        let mut ans = inf;
        let mut pre = -inf;

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, ans: &mut i32, pre: &mut i32) {
            if let Some(n) = node {
                let n = n.borrow();
                dfs(n.left.clone(), ans, pre);
                *ans = (*ans).min(n.val - *pre);
                *pre = n.val;
                dfs(n.right.clone(), ans, pre);
            }
        }

        dfs(root, &mut ans, &mut pre);
        ans
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
 * @return {number}
 */
var getMinimumDifference = function (root) {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = root => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [531. 孤独像素 I 🔒](https://leetcode.cn/problems/lonely-pixel-i){#531}

{{< tabs "531" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        rows = [0] * len(picture)
        cols = [0] * len(picture[0])
        for i, row in enumerate(picture):
            for j, x in enumerate(row):
                if x == "B":
                    rows[i] += 1
                    cols[j] += 1
        ans = 0
        for i, row in enumerate(picture):
            for j, x in enumerate(row):
                if x == "B" and rows[i] == 1 and cols[j] == 1:
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLonelyPixel(char[][] picture) {
        int m = picture.length, n = picture[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    ++ans;
                }
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
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLonelyPixel(picture [][]byte) (ans int) {
	rows := make([]int, len(picture))
	cols := make([]int, len(picture[0]))
	for i, row := range picture {
		for j, x := range row {
			if x == 'B' {
				rows[i]++
				cols[j]++
			}
		}
	}
	for i, row := range picture {
		for j, x := range row {
			if x == 'B' && rows[i] == 1 && cols[j] == 1 {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLonelyPixel(picture: string[][]): number {
    const m = picture.length;
    const n = picture[0].length;
    const rows: number[] = Array(m).fill(0);
    const cols: number[] = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (picture[i][j] === 'B') {
                ++rows[i];
                ++cols[j];
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (picture[i][j] === 'B' && rows[i] === 1 && cols[j] === 1) {
                ++ans;
            }
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

<p>给你一个大小为 <code>m x n</code> 的图像 <code>picture</code> ，图像由黑白像素组成，<code>'B'</code> 表示黑色像素，<code>'W'</code> 表示白色像素，请你统计并返回图像中 <strong>黑色</strong> 孤独像素的数量。</p>

<p><strong>黑色孤独像素</strong> 的定义为：如果黑色像素 <code>'B'</code> 所在的同一行和同一列不存在其他黑色像素，那么这个黑色像素就是黑色孤独像素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0531.Lonely%20Pixel%20I/images/pixel1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
<strong>输出：</strong>3
<strong>解释：</strong>全部三个 'B' 都是黑色的孤独像素
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0531.Lonely%20Pixel%20I/images/pixel2.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>picture = [["B","B","B"],["B","B","W"],["B","B","B"]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;picture.length</code></li>
	<li><code>n ==&nbsp;picture[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>picture[i][j]</code> 为 <code>'W'</code> 或 <code>'B'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

根据题目描述，我们需要统计每一行和每一列的黑色像素数量，分别记录在数组 $\textit{rows}$ 和 $\textit{cols}$ 中。然后我们遍历每一个黑色像素，检查其所在的行和列是否只有一个黑色像素，如果是则将答案加一。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        rows = [0] * len(picture)
        cols = [0] * len(picture[0])
        for i, row in enumerate(picture):
            for j, x in enumerate(row):
                if x == "B":
                    rows[i] += 1
                    cols[j] += 1
        ans = 0
        for i, row in enumerate(picture):
            for j, x in enumerate(row):
                if x == "B" and rows[i] == 1 and cols[j] == 1:
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int findLonelyPixel(char[][] picture) {
        int m = picture.length, n = picture[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    ++ans;
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
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLonelyPixel(picture [][]byte) (ans int) {
	rows := make([]int, len(picture))
	cols := make([]int, len(picture[0]))
	for i, row := range picture {
		for j, x := range row {
			if x == 'B' {
				rows[i]++
				cols[j]++
			}
		}
	}
	for i, row := range picture {
		for j, x := range row {
			if x == 'B' && rows[i] == 1 && cols[j] == 1 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findLonelyPixel(picture: string[][]): number {
    const m = picture.length;
    const n = picture[0].length;
    const rows: number[] = Array(m).fill(0);
    const cols: number[] = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (picture[i][j] === 'B') {
                ++rows[i];
                ++cols[j];
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (picture[i][j] === 'B' && rows[i] === 1 && cols[j] === 1) {
                ++ans;
            }
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

# [532. 数组中的 k-diff 数对](https://leetcode.cn/problems/k-diff-pairs-in-an-array){#532}

{{< tabs "532" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        ans = set()
        vis = set()
        for x in nums:
            if x - k in vis:
                ans.add(x - k)
            if x + k in vis:
                ans.add(x)
            vis.add(x)
        return len(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findPairs(int[] nums, int k) {
        Set<Integer> ans = new HashSet<>();
        Set<Integer> vis = new HashSet<>();
        for (int x : nums) {
            if (vis.contains(x - k)) {
                ans.add(x - k);
            }
            if (vis.contains(x + k)) {
                ans.add(x);
            }
            vis.add(x);
        }
        return ans.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> ans, vis;
        for (int x : nums) {
            if (vis.count(x - k)) {
                ans.insert(x - k);
            }
            if (vis.count(x + k)) {
                ans.insert(x);
            }
            vis.insert(x);
        }
        return ans.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPairs(nums []int, k int) int {
	ans := make(map[int]struct{})
	vis := make(map[int]struct{})

	for _, x := range nums {
		if _, ok := vis[x-k]; ok {
			ans[x-k] = struct{}{}
		}
		if _, ok := vis[x+k]; ok {
			ans[x] = struct{}{}
		}
		vis[x] = struct{}{}
	}
	return len(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPairs(nums: number[], k: number): number {
    const ans = new Set<number>();
    const vis = new Set<number>();
    for (const x of nums) {
        if (vis.has(x - k)) {
            ans.add(x - k);
        }
        if (vis.has(x + k)) {
            ans.add(x);
        }
        vis.add(x);
    }
    return ans.size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn find_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = HashSet::new();
        let mut vis = HashSet::new();

        for &x in &nums {
            if vis.contains(&(x - k)) {
                ans.insert(x - k);
            }
            if vis.contains(&(x + k)) {
                ans.insert(x);
            }
            vis.insert(x);
        }
        ans.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code> 和一个整数&nbsp;<code>k</code>，请你在数组中找出<strong> 不同的&nbsp;</strong>k-diff 数对，并返回不同的 <strong>k-diff 数对</strong> 的数目。</p>

<p><strong>k-diff</strong>&nbsp;数对定义为一个整数对 <code>(nums[i], nums[j])</code><strong> </strong>，并满足下述全部条件：</p>

<ul>
	<li><code>0 &lt;= i, j &lt; nums.length</code></li>
	<li><code>i != j</code></li>
	<li><code>|nums[i] - nums[j]| == k</code></li>
</ul>

<p><strong>注意</strong>，<code>|val|</code> 表示 <code>val</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3, 1, 4, 1, 5], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 2, 3, 4, 5], k = 1
<strong>输出：</strong>4
<strong>解释：</strong>数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 3, 1, 5, 4], k = 0
<strong>输出：</strong>1
<strong>解释：</strong>数组中只有一个 0-diff 数对，(1, 1) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

由于 $k$ 是一个定值，我们可以用一个哈希表 $\textit{ans}$ 记录数对的较小值，就能够确定较大的值。最后返回 $\textit{ans}$ 的大小作为答案。

遍历数组 $\textit{nums}$，当前遍历到的数 $x$，我们用哈希表 $\textit{vis}$ 记录此前遍历到的所有数字。若 $x-k$ 在 $\textit{vis}$ 中，则将 $x-k$ 添加至 $\textit{ans}$；若 $x+k$ 在 $\textit{vis}$ 中，则将 $x$ 添加至 $\textit{ans}$。然后我们将 $x$ 添加至 $\textit{vis}$。继续遍历数组 $\textit{nums}$ 直至遍历结束。

最后返回 $\textit{ans}$ 的大小作为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        ans = set()
        vis = set()
        for x in nums:
            if x - k in vis:
                ans.add(x - k)
            if x + k in vis:
                ans.add(x)
            vis.add(x)
        return len(ans)
```

#### Java

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        Set<Integer> ans = new HashSet<>();
        Set<Integer> vis = new HashSet<>();
        for (int x : nums) {
            if (vis.contains(x - k)) {
                ans.add(x - k);
            }
            if (vis.contains(x + k)) {
                ans.add(x);
            }
            vis.add(x);
        }
        return ans.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> ans, vis;
        for (int x : nums) {
            if (vis.count(x - k)) {
                ans.insert(x - k);
            }
            if (vis.count(x + k)) {
                ans.insert(x);
            }
            vis.insert(x);
        }
        return ans.size();
    }
};
```

#### Go

```go
func findPairs(nums []int, k int) int {
	ans := make(map[int]struct{})
	vis := make(map[int]struct{})

	for _, x := range nums {
		if _, ok := vis[x-k]; ok {
			ans[x-k] = struct{}{}
		}
		if _, ok := vis[x+k]; ok {
			ans[x] = struct{}{}
		}
		vis[x] = struct{}{}
	}
	return len(ans)
}
```

#### TypeScript

```ts
function findPairs(nums: number[], k: number): number {
    const ans = new Set<number>();
    const vis = new Set<number>();
    for (const x of nums) {
        if (vis.has(x - k)) {
            ans.add(x - k);
        }
        if (vis.has(x + k)) {
            ans.add(x);
        }
        vis.add(x);
    }
    return ans.size;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn find_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = HashSet::new();
        let mut vis = HashSet::new();

        for &x in &nums {
            if vis.contains(&(x - k)) {
                ans.insert(x - k);
            }
            if vis.contains(&(x + k)) {
                ans.insert(x);
            }
            vis.insert(x);
        }
        ans.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [533. 孤独像素 II 🔒](https://leetcode.cn/problems/lonely-pixel-ii){#533}

{{< tabs "533" >}}

{{% tab "python" %}}
```python
class Solution:
    def findBlackPixel(self, picture: List[List[str]], target: int) -> int:
        rows = [0] * len(picture)
        g = defaultdict(list)
        for i, row in enumerate(picture):
            for j, x in enumerate(row):
                if x == "B":
                    rows[i] += 1
                    g[j].append(i)
        ans = 0
        for j in g:
            i1 = g[j][0]
            if rows[i1] != target:
                continue
            if len(g[j]) == rows[i1] and all(picture[i2] == picture[i1] for i2 in g[j]):
                ans += target
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findBlackPixel(char[][] picture, int target) {
        int m = picture.length;
        int n = picture[0].length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] rows = new int[m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    g[j].add(i);
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (g[j].isEmpty() || (rows[g[j].get(0)] != target)) {
                continue;
            }
            int i1 = g[j].get(0);
            int ok = 0;
            if (g[j].size() == rows[i1]) {
                ok = target;
                for (int i2 : g[j]) {
                    if (!Arrays.equals(picture[i1], picture[i2])) {
                        ok = 0;
                        break;
                    }
                }
            }
            ans += ok;
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
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> g[n];
        vector<int> rows(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    g[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (g[j].empty() || (rows[g[j][0]] != target)) {
                continue;
            }
            int i1 = g[j][0];
            int ok = 0;
            if (g[j].size() == rows[i1]) {
                ok = target;
                for (int i2 : g[j]) {
                    if (picture[i1] != picture[i2]) {
                        ok = 0;
                        break;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findBlackPixel(picture [][]byte, target int) (ans int) {
	m := len(picture)
	n := len(picture[0])
	g := make([][]int, n)
	rows := make([]int, m)
	for i, row := range picture {
		for j, x := range row {
			if x == 'B' {
				rows[i]++
				g[j] = append(g[j], i)
			}
		}
	}
	for j := 0; j < n; j++ {
		if len(g[j]) == 0 || rows[g[j][0]] != target {
			continue
		}
		i1 := g[j][0]
		ok := 0
		if len(g[j]) == rows[i1] {
			ok = target
			for _, i2 := range g[j] {
				if !bytes.Equal(picture[i1], picture[i2]) {
					ok = 0
					break
				}
			}
		}
		ans += ok
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findBlackPixel(picture: string[][], target: number): number {
    const m: number = picture.length;
    const n: number = picture[0].length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const rows: number[] = Array(m).fill(0);

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (picture[i][j] === 'B') {
                ++rows[i];
                g[j].push(i);
            }
        }
    }

    let ans: number = 0;
    for (let j = 0; j < n; ++j) {
        if (g[j].length === 0 || rows[g[j][0]] !== target) {
            continue;
        }
        const i1: number = g[j][0];
        let ok: number = 0;
        if (g[j].length === rows[i1]) {
            ok = target;
            for (const i2 of g[j]) {
                if (picture[i1].join('') !== picture[i2].join('')) {
                    ok = 0;
                    break;
                }
            }
        }
        ans += ok;
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

<p>给你一个大小为 <code>m x n</code> 的二维字符数组 <code>picture</code> ，表示一张黑白图像，数组中的 <code>'B'</code> 表示黑色像素，<code>'W'</code> 表示白色像素。另给你一个整数 <code>target</code> ，请你找出并返回符合规则的 <strong>黑色</strong> 孤独像素的数量。</p>

<p>黑色孤独像素是指位于某一特定位置 <code>(r, c)</code> 的字符 <code>'B'</code> ，其中：</p>

<ul>
	<li>行 <code>r</code> 和列 <code>c</code> 中的黑色像素恰好有 <code>target</code> 个。</li>
	<li>列 <code>c</code> 中所有黑色像素所在的行必须和行 <code>r</code> 完全相同。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0533.Lonely%20Pixel%20II/images/1694957797-UWXAxl-image.png" style="width: 493px; height: 333px;" />
<pre>
<strong>输入：</strong>picture = [["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","W","B","W","B","W"]], target = 3
<strong>输出：</strong>6
<strong>解释：</strong>所有绿色的 'B' 都是我们所求的像素(第 1 列和第 3 列的所有 'B' )
以行 r = 0 和列 c = 1 的 'B' 为例：
- 规则 1 ，行 r = 0 和列 c = 1 都恰好有 target = 3 个黑色像素 
- 规则 2 ，列 c = 1 的黑色像素分别位于行 0，行 1 和行 2。和行 r = 0 完全相同。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0533.Lonely%20Pixel%20II/images/1694957806-FyCCMF-image.png" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>picture = [["W","W","B"],["W","W","B"],["W","W","B"]], target = 1
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;picture.length</code></li>
	<li><code>n ==&nbsp;picture[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>picture[i][j]</code> 为 <code>'W'</code> 或 <code>'B'</code></li>
	<li><code>1 &lt;= target &lt;= min(m, n)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

题目中条件二相当于要求对于每一列中所有包含黑色像素的行，这些行完全相同。

因此，我们可以用一个邻接表 $g$ 来存储每一列中所有包含黑色像素的行，即 $g[j]$ 表示第 $j$ 列中所有包含黑色像素的行的集合。另外，用一个数组 $rows$ 来存储每一行中黑色像素的数量。

接下来，我们遍历每一列，对于每一列，我们找到第一个包含黑色像素的行 $i_1$，如果这一行中黑色像素的数量不等于 $target$，那么这一列不可能包含孤独像素，直接跳过。否则，我们检查这一列中所有包含黑色像素的行是否和第 $i_1$ 行完全相同，如果是，则这一列中所有的黑色像素都是孤独像素，答案加上 $target$。

遍历结束后，返回答案即可。

时间复杂度 $O(m \times n^2)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findBlackPixel(self, picture: List[List[str]], target: int) -> int:
        rows = [0] * len(picture)
        g = defaultdict(list)
        for i, row in enumerate(picture):
            for j, x in enumerate(row):
                if x == "B":
                    rows[i] += 1
                    g[j].append(i)
        ans = 0
        for j in g:
            i1 = g[j][0]
            if rows[i1] != target:
                continue
            if len(g[j]) == rows[i1] and all(picture[i2] == picture[i1] for i2 in g[j]):
                ans += target
        return ans
```

#### Java

```java
class Solution {
    public int findBlackPixel(char[][] picture, int target) {
        int m = picture.length;
        int n = picture[0].length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] rows = new int[m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    g[j].add(i);
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (g[j].isEmpty() || (rows[g[j].get(0)] != target)) {
                continue;
            }
            int i1 = g[j].get(0);
            int ok = 0;
            if (g[j].size() == rows[i1]) {
                ok = target;
                for (int i2 : g[j]) {
                    if (!Arrays.equals(picture[i1], picture[i2])) {
                        ok = 0;
                        break;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> g[n];
        vector<int> rows(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    g[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (g[j].empty() || (rows[g[j][0]] != target)) {
                continue;
            }
            int i1 = g[j][0];
            int ok = 0;
            if (g[j].size() == rows[i1]) {
                ok = target;
                for (int i2 : g[j]) {
                    if (picture[i1] != picture[i2]) {
                        ok = 0;
                        break;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```

#### Go

```go
func findBlackPixel(picture [][]byte, target int) (ans int) {
	m := len(picture)
	n := len(picture[0])
	g := make([][]int, n)
	rows := make([]int, m)
	for i, row := range picture {
		for j, x := range row {
			if x == 'B' {
				rows[i]++
				g[j] = append(g[j], i)
			}
		}
	}
	for j := 0; j < n; j++ {
		if len(g[j]) == 0 || rows[g[j][0]] != target {
			continue
		}
		i1 := g[j][0]
		ok := 0
		if len(g[j]) == rows[i1] {
			ok = target
			for _, i2 := range g[j] {
				if !bytes.Equal(picture[i1], picture[i2]) {
					ok = 0
					break
				}
			}
		}
		ans += ok
	}
	return
}
```

#### TypeScript

```ts
function findBlackPixel(picture: string[][], target: number): number {
    const m: number = picture.length;
    const n: number = picture[0].length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const rows: number[] = Array(m).fill(0);

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (picture[i][j] === 'B') {
                ++rows[i];
                g[j].push(i);
            }
        }
    }

    let ans: number = 0;
    for (let j = 0; j < n; ++j) {
        if (g[j].length === 0 || rows[g[j][0]] !== target) {
            continue;
        }
        const i1: number = g[j][0];
        let ok: number = 0;
        if (g[j].length === rows[i1]) {
            ok = target;
            for (const i2 of g[j]) {
                if (picture[i1].join('') !== picture[i2].join('')) {
                    ok = 0;
                    break;
                }
            }
        }
        ans += ok;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [534. 游戏玩法分析 III 🔒](https://leetcode.cn/problems/game-play-analysis-iii){#534}

{{< tabs "534" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    t1.player_id,
    t1.event_date,
    SUM(t2.games_played) AS games_played_so_far
FROM
    Activity AS t1
    CROSS JOIN Activity AS t2 ON t1.player_id = t2.player_id AND t1.event_date >= t2.event_date
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Activity</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
（player_id，event_date）是此表的主键（具有唯一值的列）。
这张表显示了某些游戏的玩家的活动情况。
每一行是一个玩家的记录，他在某一天使用某个设备注销之前登录并玩了很多游戏（可能是 0 ）。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，同时报告每组玩家和日期，以及玩家到 <strong>目前为止</strong> 玩了多少游戏。也就是说，玩家在该日期之前所玩的游戏总数。详细情况请查看示例。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

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
| 1         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
<strong>输出：</strong>
+-----------+------------+---------------------+
| player_id | event_date | games_played_so_far |
+-----------+------------+---------------------+
| 1         | 2016-03-01 | 5                   |
| 1         | 2016-05-02 | 11                  |
| 1         | 2017-06-25 | 12                  |
| 3         | 2016-03-02 | 0                   |
| 3         | 2018-07-03 | 5                   |
+-----------+------------+---------------------+
<strong>解释：</strong>
对于 ID 为 1 的玩家，2016-05-02 共玩了 5+6=11 个游戏，2017-06-25 共玩了 5+6+1=12 个游戏。
对于 ID 为 3 的玩家，2018-07-03 共玩了 0+5=5 个游戏。
请注意，对于每个玩家，我们只关心玩家的登录日期。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用窗口函数

我们可以使用窗口函数 `SUM() OVER()`，按照 `player_id` 分组，按照 `event_date` 排序，计算每个用户截止到当前日期的游戏总数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    player_id,
    event_date,
    SUM(games_played) OVER (
        PARTITION BY player_id
        ORDER BY event_date
    ) AS games_played_so_far
FROM Activity;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：使用自连接 + 分组

我们也可以使用自连接，将 `Activity` 表自连接，连接条件为 `t1.player_id = t2.player_id AND t1.event_date >= t2.event_date`，然后按照 `t1.player_id` 和 `t1.event_date` 分组，累计 `t2.games_played`，得到每个用户截止到当前日期的游戏总数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    t1.player_id,
    t1.event_date,
    SUM(t2.games_played) AS games_played_so_far
FROM
    Activity AS t1,
    Activity AS t2
WHERE t1.player_id = t2.player_id AND t1.event_date >= t2.event_date
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    t1.player_id,
    t1.event_date,
    SUM(t2.games_played) AS games_played_so_far
FROM
    Activity AS t1
    CROSS JOIN Activity AS t2 ON t1.player_id = t2.player_id AND t1.event_date >= t2.event_date
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [535. TinyURL 的加密与解密](https://leetcode.cn/problems/encode-and-decode-tinyurl){#535}

{{< tabs "535" >}}

{{% tab "python" %}}
```python
class Codec:
    def __init__(self):
        self.m = defaultdict()
        self.idx = 0
        self.domain = 'https://tinyurl.com/'

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL."""
        self.idx += 1
        self.m[str(self.idx)] = longUrl
        return f'{self.domain}{self.idx}'

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL."""
        idx = shortUrl.split('/')[-1]
        return self.m[idx]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Codec {
    private Map<String, String> m = new HashMap<>();
    private int idx = 0;
    private String domain = "https://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        String v = String.valueOf(++idx);
        m.put(v, longUrl);
        return domain + v;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        int i = shortUrl.lastIndexOf('/') + 1;
        return m.get(shortUrl.substring(i));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string v = to_string(++idx);
        m[v] = longUrl;
        return domain + v;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = shortUrl.rfind('/') + 1;
        return m[shortUrl.substr(i, shortUrl.size() - i)];
    }

private:
    unordered_map<string, string> m;
    int idx = 0;
    string domain = "https://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Codec struct {
	m   map[int]string
	idx int
}

func Constructor() Codec {
	m := map[int]string{}
	return Codec{m, 0}
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	this.idx++
	this.m[this.idx] = longUrl
	return "https://tinyurl.com/" + strconv.Itoa(this.idx)
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	i := strings.LastIndexByte(shortUrl, '/')
	v, _ := strconv.Atoi(shortUrl[i+1:])
	return this.m[v]
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>TinyURL 是一种 URL 简化服务， 比如：当你输入一个 URL&nbsp;<code>https://leetcode.com/problems/design-tinyurl</code>&nbsp;时，它将返回一个简化的URL&nbsp;<code>http://tinyurl.com/4e9iAk</code> 。请你设计一个类来加密与解密 TinyURL 。</p>

<p>加密和解密算法如何设计和运作是没有限制的，你只需要保证一个 URL 可以被加密成一个 TinyURL ，并且这个 TinyURL 可以用解密方法恢复成原本的 URL 。</p>

<p>实现 <code>Solution</code> 类：</p>

<div class="original__bRMd">
<div>
<ul>
	<li><code>Solution()</code> 初始化 TinyURL 系统对象。</li>
	<li><code>String encode(String longUrl)</code> 返回 <code>longUrl</code> 对应的 TinyURL 。</li>
	<li><code>String decode(String shortUrl)</code> 返回 <code>shortUrl</code> 原本的 URL 。题目数据保证给定的 <code>shortUrl</code> 是由同一个系统对象加密的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>url = "https://leetcode.com/problems/design-tinyurl"
<strong>输出：</strong>"https://leetcode.com/problems/design-tinyurl"

<strong>解释：</strong>
Solution obj = new Solution();
string tiny = obj.encode(url); // 返回加密后得到的 TinyURL 。
string ans = obj.decode(tiny); // 返回解密后得到的原本的 URL 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= url.length &lt;= 10<sup>4</sup></code></li>
	<li>题目数据保证 <code>url</code> 是一个有效的 URL</li>
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

### 方法一：哈希表

<!-- tabs:start -->

#### Python3

```python
class Codec:
    def __init__(self):
        self.m = defaultdict()
        self.idx = 0
        self.domain = 'https://tinyurl.com/'

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL."""
        self.idx += 1
        self.m[str(self.idx)] = longUrl
        return f'{self.domain}{self.idx}'

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL."""
        idx = shortUrl.split('/')[-1]
        return self.m[idx]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
```

#### Java

```java
public class Codec {
    private Map<String, String> m = new HashMap<>();
    private int idx = 0;
    private String domain = "https://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        String v = String.valueOf(++idx);
        m.put(v, longUrl);
        return domain + v;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        int i = shortUrl.lastIndexOf('/') + 1;
        return m.get(shortUrl.substring(i));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
```

#### C++

```cpp
class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string v = to_string(++idx);
        m[v] = longUrl;
        return domain + v;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = shortUrl.rfind('/') + 1;
        return m[shortUrl.substr(i, shortUrl.size() - i)];
    }

private:
    unordered_map<string, string> m;
    int idx = 0;
    string domain = "https://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```

#### Go

```go
type Codec struct {
	m   map[int]string
	idx int
}

func Constructor() Codec {
	m := map[int]string{}
	return Codec{m, 0}
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	this.idx++
	this.m[this.idx] = longUrl
	return "https://tinyurl.com/" + strconv.Itoa(this.idx)
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	i := strings.LastIndexByte(shortUrl, '/')
	v, _ := strconv.Atoi(shortUrl[i+1:])
	return this.m[v]
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [536. 从字符串生成二叉树 🔒](https://leetcode.cn/problems/construct-binary-tree-from-string){#536}

{{< tabs "536" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def str2tree(self, s: str) -> TreeNode:
        def dfs(s):
            if not s:
                return None
            p = s.find('(')
            if p == -1:
                return TreeNode(int(s))
            root = TreeNode(int(s[:p]))
            start = p
            cnt = 0
            for i in range(p, len(s)):
                if s[i] == '(':
                    cnt += 1
                elif s[i] == ')':
                    cnt -= 1
                if cnt == 0:
                    if start == p:
                        root.left = dfs(s[start + 1 : i])
                        start = i + 1
                    else:
                        root.right = dfs(s[start + 1 : i])
            return root

        return dfs(s)
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
    public TreeNode str2tree(String s) {
        return dfs(s);
    }

    private TreeNode dfs(String s) {
        if ("".equals(s)) {
            return null;
        }
        int p = s.indexOf("(");
        if (p == -1) {
            return new TreeNode(Integer.parseInt(s));
        }
        TreeNode root = new TreeNode(Integer.parseInt(s.substring(0, p)));
        int start = p;
        int cnt = 0;
        for (int i = p; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++cnt;
            } else if (s.charAt(i) == ')') {
                --cnt;
            }
            if (cnt == 0) {
                if (start == p) {
                    root.left = dfs(s.substring(start + 1, i));
                    start = i + 1;
                } else {
                    root.right = dfs(s.substring(start + 1, i));
                }
            }
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
    TreeNode* str2tree(string s) {
        return dfs(s);
    }

    TreeNode* dfs(string s) {
        if (s == "") return nullptr;
        int p = s.find("(");
        if (p == s.npos) return new TreeNode(stoi(s));
        TreeNode* root = new TreeNode(stoi(s.substr(0, p)));
        int start = p;
        int cnt = 0;
        for (int i = p; i < s.size(); ++i) {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')')
                --cnt;
            if (cnt == 0) {
                if (start == p) {
                    root->left = dfs(s.substr(start + 1, i - start - 1));
                    start = i + 1;
                } else
                    root->right = dfs(s.substr(start + 1, i - start - 1));
            }
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
func str2tree(s string) *TreeNode {
	var dfs func(s string) *TreeNode
	dfs = func(s string) *TreeNode {
		if s == "" {
			return nil
		}
		p := strings.IndexAny(s, "(")
		if p == -1 {
			v, _ := strconv.Atoi(s)
			return &TreeNode{Val: v}
		}
		v, _ := strconv.Atoi(s[:p])
		root := &TreeNode{Val: v}
		start := p
		cnt := 0
		for i := p; i < len(s); i++ {
			if s[i] == '(' {
				cnt++
			} else if s[i] == ')' {
				cnt--
			}
			if cnt == 0 {
				if p == start {
					root.Left = dfs(s[start+1 : i])
					start = i + 1
				} else {
					root.Right = dfs(s[start+1 : i])
				}
			}
		}
		return root
	}
	return dfs(s)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要用一个包括括号和整数的字符串构建一棵二叉树。</p>

<p>输入的字符串代表一棵二叉树。它包括整数和随后的 0 、1 或 2 对括号。整数代表根的值，一对括号内表示同样结构的子树。</p>

<p>若存在子结点，则从<strong>左子结点</strong>开始构建。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0536.Construct%20Binary%20Tree%20from%20String/images/butree.jpg" style="height: 322px; width: 382px;" />
<pre>
<strong>输入：</strong> s = "4(2(3)(1))(6(5))"
<strong>输出：</strong> [4,2,6,3,1,5]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong> s = "4(2(3)(1))(6(5)(7))"
<strong>输出：</strong> [4,2,6,3,1,5,7]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong> s = "-4(2(3)(1))(6(5)(7))"
<strong>输出： </strong>[-4,2,6,3,1,5,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li>输入字符串中只包含&nbsp;<code>'('</code>, <code>')'</code>, <code>'-'</code>&nbsp;和&nbsp;<code>'0'</code> ~ <code>'9'</code>&nbsp;</li>
	<li>树中所有数字的值 <strong>最多</strong> 不超过&nbsp;<code>2<sup>30</sup></code>。</li>
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
    def str2tree(self, s: str) -> TreeNode:
        def dfs(s):
            if not s:
                return None
            p = s.find('(')
            if p == -1:
                return TreeNode(int(s))
            root = TreeNode(int(s[:p]))
            start = p
            cnt = 0
            for i in range(p, len(s)):
                if s[i] == '(':
                    cnt += 1
                elif s[i] == ')':
                    cnt -= 1
                if cnt == 0:
                    if start == p:
                        root.left = dfs(s[start + 1 : i])
                        start = i + 1
                    else:
                        root.right = dfs(s[start + 1 : i])
            return root

        return dfs(s)
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
    public TreeNode str2tree(String s) {
        return dfs(s);
    }

    private TreeNode dfs(String s) {
        if ("".equals(s)) {
            return null;
        }
        int p = s.indexOf("(");
        if (p == -1) {
            return new TreeNode(Integer.parseInt(s));
        }
        TreeNode root = new TreeNode(Integer.parseInt(s.substring(0, p)));
        int start = p;
        int cnt = 0;
        for (int i = p; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                ++cnt;
            } else if (s.charAt(i) == ')') {
                --cnt;
            }
            if (cnt == 0) {
                if (start == p) {
                    root.left = dfs(s.substring(start + 1, i));
                    start = i + 1;
                } else {
                    root.right = dfs(s.substring(start + 1, i));
                }
            }
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
    TreeNode* str2tree(string s) {
        return dfs(s);
    }

    TreeNode* dfs(string s) {
        if (s == "") return nullptr;
        int p = s.find("(");
        if (p == s.npos) return new TreeNode(stoi(s));
        TreeNode* root = new TreeNode(stoi(s.substr(0, p)));
        int start = p;
        int cnt = 0;
        for (int i = p; i < s.size(); ++i) {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')')
                --cnt;
            if (cnt == 0) {
                if (start == p) {
                    root->left = dfs(s.substr(start + 1, i - start - 1));
                    start = i + 1;
                } else
                    root->right = dfs(s.substr(start + 1, i - start - 1));
            }
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
func str2tree(s string) *TreeNode {
	var dfs func(s string) *TreeNode
	dfs = func(s string) *TreeNode {
		if s == "" {
			return nil
		}
		p := strings.IndexAny(s, "(")
		if p == -1 {
			v, _ := strconv.Atoi(s)
			return &TreeNode{Val: v}
		}
		v, _ := strconv.Atoi(s[:p])
		root := &TreeNode{Val: v}
		start := p
		cnt := 0
		for i := p; i < len(s); i++ {
			if s[i] == '(' {
				cnt++
			} else if s[i] == ')' {
				cnt--
			}
			if cnt == 0 {
				if p == start {
					root.Left = dfs(s[start+1 : i])
					start = i + 1
				} else {
					root.Right = dfs(s[start+1 : i])
				}
			}
		}
		return root
	}
	return dfs(s)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [537. 复数乘法](https://leetcode.cn/problems/complex-number-multiplication){#537}

{{< tabs "537" >}}

{{% tab "python" %}}
```python
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a1, b1 = map(int, num1[:-1].split("+"))
        a2, b2 = map(int, num2[:-1].split("+"))
        return f"{a1 * a2 - b1 * b2}+{a1 * b2 + a2 * b1}i"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        int[] x = parse(num1);
        int[] y = parse(num2);
        int a1 = x[0], b1 = x[1], a2 = y[0], b2 = y[1];
        return (a1 * a2 - b1 * b2) + "+" + (a1 * b2 + a2 * b1) + "i";
    }

    private int[] parse(String s) {
        var cs = s.substring(0, s.length() - 1).split("\\+");
        return new int[] {Integer.parseInt(cs[0]), Integer.parseInt(cs[1])};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func complexNumberMultiply(num1 string, num2 string) string {
	x, _ := strconv.ParseComplex(num1, 64)
	y, _ := strconv.ParseComplex(num2, 64)
	return fmt.Sprintf("%d+%di", int(real(x*y)), int(imag(x*y)))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function complexNumberMultiply(num1: string, num2: string): string {
    const [a1, b1] = num1.slice(0, -1).split('+').map(Number);
    const [a2, b2] = num2.slice(0, -1).split('+').map(Number);
    return `${a1 * a2 - b1 * b2}+${a1 * b2 + a2 * b1}i`;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><a href="https://baike.baidu.com/item/%E5%A4%8D%E6%95%B0/254365?fr=aladdin" target="_blank">复数</a> 可以用字符串表示，遵循 <code>"<strong>实部</strong>+<strong>虚部</strong>i"</code> 的形式，并满足下述条件：</p>

<ul>
	<li><code>实部</code> 是一个整数，取值范围是 <code>[-100, 100]</code></li>
	<li><code>虚部</code> 也是一个整数，取值范围是 <code>[-100, 100]</code></li>
	<li><code>i<sup>2</sup> == -1</code></li>
</ul>

<p>给你两个字符串表示的复数 <code>num1</code> 和 <code>num2</code> ，请你遵循复数表示形式，返回表示它们乘积的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = "1+1i", num2 = "1+1i"
<strong>输出：</strong>"0+2i"
<strong>解释：</strong>(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = "1+-1i", num2 = "1+-1i"
<strong>输出：</strong>"0+-2i"
<strong>解释：</strong>(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>num1</code> 和 <code>num2</code> 都是有效的复数表示。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以将复数字符串转换成对应的实部 $a$ 和虚部 $b$，然后根据复数乘法的公式 $(a_1 + b_1i) \times (a_2 + b_2i) = (a_1a_2 - b_1b_2) + (a_1b_2 + a_2b_1)i$ 计算出结果。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a1, b1 = map(int, num1[:-1].split("+"))
        a2, b2 = map(int, num2[:-1].split("+"))
        return f"{a1 * a2 - b1 * b2}+{a1 * b2 + a2 * b1}i"
```

#### Java

```java
class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        int[] x = parse(num1);
        int[] y = parse(num2);
        int a1 = x[0], b1 = x[1], a2 = y[0], b2 = y[1];
        return (a1 * a2 - b1 * b2) + "+" + (a1 * b2 + a2 * b1) + "i";
    }

    private int[] parse(String s) {
        var cs = s.substring(0, s.length() - 1).split("\\+");
        return new int[] {Integer.parseInt(cs[0]), Integer.parseInt(cs[1])};
    }
}
```

#### C++

```cpp
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};
```

#### Go

```go
func complexNumberMultiply(num1 string, num2 string) string {
	x, _ := strconv.ParseComplex(num1, 64)
	y, _ := strconv.ParseComplex(num2, 64)
	return fmt.Sprintf("%d+%di", int(real(x*y)), int(imag(x*y)))
}
```

#### TypeScript

```ts
function complexNumberMultiply(num1: string, num2: string): string {
    const [a1, b1] = num1.slice(0, -1).split('+').map(Number);
    const [a2, b2] = num2.slice(0, -1).split('+').map(Number);
    return `${a1 * a2 - b1 * b2}+${a1 * b2 + a2 * b1}i`;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [538. 把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree){#538}

{{< tabs "538" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        s = 0
        node = root
        while root:
            if root.right is None:
                s += root.val
                root.val = s
                root = root.left
            else:
                next = root.right
                while next.left and next.left != root:
                    next = next.left
                if next.left is None:
                    next.left = root
                    root = root.right
                else:
                    s += root.val
                    root.val = s
                    next.left = None
                    root = root.left
        return node
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
    public TreeNode convertBST(TreeNode root) {
        int s = 0;
        TreeNode node = root;
        while (root != null) {
            if (root.right == null) {
                s += root.val;
                root.val = s;
                root = root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null && next.left != root) {
                    next = next.left;
                }
                if (next.left == null) {
                    next.left = root;
                    root = root.right;
                } else {
                    s += root.val;
                    root.val = s;
                    next.left = null;
                    root = root.left;
                }
            }
        }
        return node;
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
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        TreeNode* node = root;
        while (root) {
            if (root->right == nullptr) {
                s += root->val;
                root->val = s;
                root = root->left;
            } else {
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
                if (next->left == nullptr) {
                    next->left = root;
                    root = root->right;
                } else {
                    s += root->val;
                    root->val = s;
                    next->left = nullptr;
                    root = root->left;
                }
            }
        }
        return node;
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
func convertBST(root *TreeNode) *TreeNode {
	s := 0
	node := root
	for root != nil {
		if root.Right == nil {
			s += root.Val
			root.Val = s
			root = root.Left
		} else {
			next := root.Right
			for next.Left != nil && next.Left != root {
				next = next.Left
			}
			if next.Left == nil {
				next.Left = root
				root = root.Right
			} else {
				s += root.Val
				root.Val = s
				next.Left = nil
				root = root.Left
			}
		}
	}
	return node
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
 * @return {TreeNode}
 */
var convertBST = function (root) {
    let s = 0;
    function dfs(root) {
        if (!root) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
    }
    dfs(root);
    return root;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出二叉<strong> 搜索 </strong>树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 <code>node</code>&nbsp;的新值等于原树中大于或等于&nbsp;<code>node.val</code>&nbsp;的值之和。</p>

<p>提醒一下，二叉搜索树满足下列约束条件：</p>

<ul>
	<li>节点的左子树仅包含键<strong> 小于 </strong>节点键的节点。</li>
	<li>节点的右子树仅包含键<strong> 大于</strong> 节点键的节点。</li>
	<li>左右子树也必须是二叉搜索树。</li>
</ul>

<p><strong>注意：</strong>本题和 1038:&nbsp;<a href="https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/">https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/</a> 相同</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0538.Convert%20BST%20to%20Greater%20Tree/images/tree.png" style="height: 364px; width: 534px;"></strong></p>

<pre><strong>输入：</strong>[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong>输出：</strong>[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>root = [0,null,1]
<strong>输出：</strong>[1,null,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1,0,2]
<strong>输出：</strong>[3,3,2]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [3,2,4,1]
<strong>输出：</strong>[7,9,4,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数介于 <code>0</code>&nbsp;和 <code>10<sup>4</sup></code><sup>&nbsp;</sup>之间。</li>
	<li>每个节点的值介于 <code>-10<sup>4</sup></code>&nbsp;和&nbsp;<code>10<sup>4</sup></code>&nbsp;之间。</li>
	<li>树中的所有值 <strong>互不相同</strong> 。</li>
	<li>给定的树为二叉搜索树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

按照“右根左”的顺序，递归遍历二叉搜索树，累加遍历到的所有节点值到 $s$ 中，然后每次赋值给对应的 `node` 节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点数。

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
    def convertBST(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            nonlocal s
            if root is None:
                return
            dfs(root.right)
            s += root.val
            root.val = s
            dfs(root.left)

        s = 0
        dfs(root)
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
    private int s;

    public TreeNode convertBST(TreeNode root) {
        dfs(root);
        return root;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
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
    int s = 0;

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        s += root->val;
        root->val = s;
        dfs(root->left);
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
func convertBST(root *TreeNode) *TreeNode {
	s := 0
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Right)
		s += root.Val
		root.Val = s
		dfs(root.Left)
	}
	dfs(root)
	return root
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
 * @return {TreeNode}
 */
var convertBST = function (root) {
    let s = 0;
    function dfs(root) {
        if (!root) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
    }
    dfs(root);
    return root;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Morris 遍历

Morris 遍历无需使用栈，时间复杂度 $O(n)$，空间复杂度为 $O(1)$。核心思想是：

定义 s 表示二叉搜索树节点值累加和。遍历二叉树节点：

1. 若当前节点 root 的右子树为空，**将当前节点值添加至 s** 中，更新当前节点值为 s，并将当前节点更新为 `root.left`。
2. 若当前节点 root 的右子树不为空，找到右子树的最左节点 next（也即是 root 节点在中序遍历下的后继节点）：
    - 若后继节点 next 的左子树为空，将后继节点的左子树指向当前节点 root，并将当前节点更新为 `root.right`。
    - 若后继节点 next 的左子树不为空，**将当前节点值添加 s** 中，更新当前节点值为 s，然后将后继节点左子树指向空（即解除 next 与 root 的指向关系），并将当前节点更新为 `root.left`。
3. 循环以上步骤，直至二叉树节点为空，遍历结束。
4. 最后返回二叉搜索树根节点即可。

> Morris 反序中序遍历跟 Morris 中序遍历思路一致，只是将中序遍历的“左根右”变为“右根左”。

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
    def convertBST(self, root: TreeNode) -> TreeNode:
        s = 0
        node = root
        while root:
            if root.right is None:
                s += root.val
                root.val = s
                root = root.left
            else:
                next = root.right
                while next.left and next.left != root:
                    next = next.left
                if next.left is None:
                    next.left = root
                    root = root.right
                else:
                    s += root.val
                    root.val = s
                    next.left = None
                    root = root.left
        return node
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
    public TreeNode convertBST(TreeNode root) {
        int s = 0;
        TreeNode node = root;
        while (root != null) {
            if (root.right == null) {
                s += root.val;
                root.val = s;
                root = root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null && next.left != root) {
                    next = next.left;
                }
                if (next.left == null) {
                    next.left = root;
                    root = root.right;
                } else {
                    s += root.val;
                    root.val = s;
                    next.left = null;
                    root = root.left;
                }
            }
        }
        return node;
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
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        TreeNode* node = root;
        while (root) {
            if (root->right == nullptr) {
                s += root->val;
                root->val = s;
                root = root->left;
            } else {
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
                if (next->left == nullptr) {
                    next->left = root;
                    root = root->right;
                } else {
                    s += root->val;
                    root->val = s;
                    next->left = nullptr;
                    root = root->left;
                }
            }
        }
        return node;
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
func convertBST(root *TreeNode) *TreeNode {
	s := 0
	node := root
	for root != nil {
		if root.Right == nil {
			s += root.Val
			root.Val = s
			root = root.Left
		} else {
			next := root.Right
			for next.Left != nil && next.Left != root {
				next = next.Left
			}
			if next.Left == nil {
				next.Left = root
				root = root.Right
			} else {
				s += root.Val
				root.Val = s
				next.Left = nil
				root = root.Left
			}
		}
	}
	return node
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [539. 最小时间差](https://leetcode.cn/problems/minimum-time-difference){#539}

{{< tabs "539" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        if len(timePoints) > 1440:
            return 0
        nums = sorted(int(x[:2]) * 60 + int(x[3:]) for x in timePoints)
        nums.append(nums[0] + 1440)
        return min(b - a for a, b in pairwise(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinDifference(List<String> timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int n = timePoints.size();
        int[] nums = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            String[] t = timePoints.get(i).split(":");
            nums[i] = Integer.parseInt(t[0]) * 60 + Integer.parseInt(t[1]);
        }
        Arrays.sort(nums, 0, n);
        nums[n] = nums[0] + 1440;
        int ans = 1 << 30;
        for (int i = 1; i <= n; ++i) {
            ans = Math.min(ans, nums[i] - nums[i - 1]);
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
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int n = timePoints.size();
        vector<int> nums(n + 1);
        for (int i = 0; i < n; ++i) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3, 2));
            nums[i] = hours * 60 + minutes;
        }
        sort(nums.begin(), nums.begin() + n);
        nums[n] = nums[0] + 1440;
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMinDifference(timePoints []string) int {
	if len(timePoints) > 1440 {
		return 0
	}

	n := len(timePoints)
	nums := make([]int, n+1)
	for i, time := range timePoints {
		parts := strings.Split(time, ":")
		hours, _ := strconv.Atoi(parts[0])
		minutes, _ := strconv.Atoi(parts[1])
		nums[i] = hours*60 + minutes
	}

	sort.Ints(nums[:n])
	nums[n] = nums[0] + 1440

	ans := 1 << 30
	for i := 1; i <= n; i++ {
		ans = min(ans, nums[i]-nums[i-1])
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinDifference(timePoints: string[]): number {
    if (timePoints.length > 1440) {
        return 0;
    }
    const n = timePoints.length;
    const nums: number[] = Array(n + 1);
    for (let i = 0; i < n; ++i) {
        const [hours, minutes] = timePoints[i].split(':').map(Number);
        nums[i] = hours * 60 + minutes;
    }
    nums.sort((a, b) => a - b);
    nums[n] = nums[0] + 1440;
    let ans = 1 << 30;
    for (let i = 1; i <= n; ++i) {
        ans = Math.min(ans, nums[i] - nums[i - 1]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_min_difference(time_points: Vec<String>) -> i32 {
        if time_points.len() > 1440 {
            return 0;
        }

        let n = time_points.len();
        let mut nums: Vec<i32> = Vec::with_capacity(n + 1);

        for time in time_points.iter() {
            let parts: Vec<i32> = time.split(':').map(|s| s.parse().unwrap()).collect();
            let minutes = parts[0] * 60 + parts[1];
            nums.push(minutes);
        }

        nums.sort();
        nums.push(nums[0] + 1440);

        let mut ans = i32::MAX;
        for i in 1..=n {
            ans = ans.min(nums[i] - nums[i - 1]);
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func findMinDifference(_ timePoints: [String]) -> Int {
        if timePoints.count > 1440 {
            return 0
        }

        var nums = [Int]()

        for t in timePoints {
            let time = t.split(separator: ":").map { Int($0)! }
            nums.append(time[0] * 60 + time[1])
        }

        nums.sort()
        nums.append(nums[0] + 1440)

        var ans = Int.max
        for i in 1..<nums.count {
            ans = min(ans, nums[i] - nums[i - 1])
        }

        return ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 24 小时制（小时:分钟 <strong>"HH:MM"</strong>）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>timePoints = ["23:59","00:00"]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>timePoints = ["00:00","23:59","00:00"]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= timePoints.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>timePoints[i]</code> 格式为 <strong>"HH:MM"</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们注意到，时间点最多只有 $24 \times 60 = 1440$ 个，因此，当 $timePoints$ 长度超过 $1440$，说明有重复的时间点，提前返回 $0$。

接下来，我们首先遍历时间列表，将其转换为“分钟制”列表 $nums$，比如，对于时间点 `13:14`，将其转换为 $13 \times 60 + 14$。

接着将“分钟制”列表按升序排列，然后将此列表的最小时间 $nums[0]$ 加上 $1440$ 追加至列表尾部，用于处理最大值、最小值的差值这种特殊情况。

最后遍历“分钟制”列表，找出相邻两个时间的最小值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为时间点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        if len(timePoints) > 1440:
            return 0
        nums = sorted(int(x[:2]) * 60 + int(x[3:]) for x in timePoints)
        nums.append(nums[0] + 1440)
        return min(b - a for a, b in pairwise(nums))
```

#### Java

```java
class Solution {
    public int findMinDifference(List<String> timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int n = timePoints.size();
        int[] nums = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            String[] t = timePoints.get(i).split(":");
            nums[i] = Integer.parseInt(t[0]) * 60 + Integer.parseInt(t[1]);
        }
        Arrays.sort(nums, 0, n);
        nums[n] = nums[0] + 1440;
        int ans = 1 << 30;
        for (int i = 1; i <= n; ++i) {
            ans = Math.min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int n = timePoints.size();
        vector<int> nums(n + 1);
        for (int i = 0; i < n; ++i) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3, 2));
            nums[i] = hours * 60 + minutes;
        }
        sort(nums.begin(), nums.begin() + n);
        nums[n] = nums[0] + 1440;
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func findMinDifference(timePoints []string) int {
	if len(timePoints) > 1440 {
		return 0
	}

	n := len(timePoints)
	nums := make([]int, n+1)
	for i, time := range timePoints {
		parts := strings.Split(time, ":")
		hours, _ := strconv.Atoi(parts[0])
		minutes, _ := strconv.Atoi(parts[1])
		nums[i] = hours*60 + minutes
	}

	sort.Ints(nums[:n])
	nums[n] = nums[0] + 1440

	ans := 1 << 30
	for i := 1; i <= n; i++ {
		ans = min(ans, nums[i]-nums[i-1])
	}

	return ans
}
```

#### TypeScript

```ts
function findMinDifference(timePoints: string[]): number {
    if (timePoints.length > 1440) {
        return 0;
    }
    const n = timePoints.length;
    const nums: number[] = Array(n + 1);
    for (let i = 0; i < n; ++i) {
        const [hours, minutes] = timePoints[i].split(':').map(Number);
        nums[i] = hours * 60 + minutes;
    }
    nums.sort((a, b) => a - b);
    nums[n] = nums[0] + 1440;
    let ans = 1 << 30;
    for (let i = 1; i <= n; ++i) {
        ans = Math.min(ans, nums[i] - nums[i - 1]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_min_difference(time_points: Vec<String>) -> i32 {
        if time_points.len() > 1440 {
            return 0;
        }

        let n = time_points.len();
        let mut nums: Vec<i32> = Vec::with_capacity(n + 1);

        for time in time_points.iter() {
            let parts: Vec<i32> = time.split(':').map(|s| s.parse().unwrap()).collect();
            let minutes = parts[0] * 60 + parts[1];
            nums.push(minutes);
        }

        nums.sort();
        nums.push(nums[0] + 1440);

        let mut ans = i32::MAX;
        for i in 1..=n {
            ans = ans.min(nums[i] - nums[i - 1]);
        }

        ans
    }
}
```

#### Swift

```swift
class Solution {
    func findMinDifference(_ timePoints: [String]) -> Int {
        if timePoints.count > 1440 {
            return 0
        }

        var nums = [Int]()

        for t in timePoints {
            let time = t.split(separator: ":").map { Int($0)! }
            nums.append(time[0] * 60 + time[1])
        }

        nums.sort()
        nums.append(nums[0] + 1440)

        var ans = Int.max
        for i in 1..<nums.count {
            ans = min(ans, nums[i] - nums[i - 1])
        }

        return ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
