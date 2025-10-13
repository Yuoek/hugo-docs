---
title: "0450_删除二叉搜索树中的节点"
date: 2025-10-08T18:36:10+08:00
weight: 6
tags: [二分查找, 二叉搜索树, 二叉树, 动态规划, 单调栈, 双指针, 哈希表, 堆（优先队列）, 字符串, 字符串匹配, 排序, 数学, 数组, 有序集合, 栈, 树, 桶排序, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [0450_删除二叉搜索树中的节点](#450)
#### [树](#450)
#### [二叉搜索树](#450)
#### [二叉树](#450)
### [0451_根据字符出现频率排序](#451)
#### [哈希表](#451)
#### [字符串](#451)
#### [桶排序](#451)
#### [计数](#451)
#### [排序](#451)
#### [堆（优先队列）](#451)
### [0452_用最少数量的箭引爆气球](#452)
#### [贪心](#452)
#### [数组](#452)
#### [排序](#452)
### [0453_最小操作次数使数组元素相等](#453)
#### [数组](#453)
#### [数学](#453)
### [0454_四数相加 II](#454)
#### [数组](#454)
#### [哈希表](#454)
### [0455_分发饼干](#455)
#### [贪心](#455)
#### [数组](#455)
#### [双指针](#455)
#### [排序](#455)
### [0456_132 模式](#456)
#### [栈](#456)
#### [数组](#456)
#### [二分查找](#456)
#### [有序集合](#456)
#### [单调栈](#456)
### [0457_环形数组是否存在循环](#457)
#### [数组](#457)
#### [哈希表](#457)
#### [双指针](#457)
### [0458_可怜的小猪](#458)
#### [数学](#458)
#### [动态规划](#458)
#### [组合数学](#458)
### [0459_重复的子字符串](#459)
#### [字符串](#459)
#### [字符串匹配](#459)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0450_删除二叉搜索树中的节点
___
#### 树
___
#### 二叉搜索树
___
#### 二叉树
---
### 0451_根据字符出现频率排序
___
#### 哈希表
___
#### 字符串
___
#### 桶排序
___
#### 计数
___
#### 排序
___
#### 堆（优先队列）
---
### 0452_用最少数量的箭引爆气球
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 0453_最小操作次数使数组元素相等
___
#### 数组
___
#### 数学
---
### 0454_四数相加 II
___
#### 数组
___
#### 哈希表
---
### 0455_分发饼干
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0456_132 模式
___
#### 栈
___
#### 数组
___
#### 二分查找
___
#### 有序集合
___
#### 单调栈
---
### 0457_环形数组是否存在循环
___
#### 数组
___
#### 哈希表
___
#### 双指针
---
### 0458_可怜的小猪
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 0459_重复的子字符串
___
#### 字符串
___
#### 字符串匹配
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 字符串匹配 | 排序 | 数学 |
| 数组 | 有序集合 | 栈 |
| 树 | 桶排序 | 组合数学 |
| 计数 | 贪心 |  |

# [450. 删除二叉搜索树中的节点](https://leetcode.cn/problems/delete-node-in-a-bst){#450}

{{< tabs "450" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
            return root
        if root.val < key:
            root.right = self.deleteNode(root.right, key)
            return root
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        node = root.right
        while node.left:
            node = node.left
        node.left = root.left
        root = root.right
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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        if (root.val < key) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        if (root.left == null) {
            return root.right;
        }
        if (root.right == null) {
            return root.left;
        }
        TreeNode node = root.right;
        while (node.left != null) {
            node = node.left;
        }
        node.left = root.left;
        root = root.right;
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* node = root->right;
        while (node->left) node = node->left;
        node->left = root->left;
        root = root->right;
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
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val > key {
		root.Left = deleteNode(root.Left, key)
		return root
	}
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
		return root
	}
	if root.Left == nil {
		return root.Right
	}
	if root.Right == nil {
		return root.Left
	}
	node := root.Right
	for node.Left != nil {
		node = node.Left
	}
	node.Left = root.Left
	root = root.Right
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

function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    if (root == null) {
        return root;
    }
    const { val, left, right } = root;
    if (val > key) {
        root.left = deleteNode(left, key);
    } else if (val < key) {
        root.right = deleteNode(right, key);
    } else {
        if (left == null && right == null) {
            root = null;
        } else if (left == null || right == null) {
            root = left || right;
        } else {
            if (right.left == null) {
                right.left = left;
                root = right;
            } else {
                let minPreNode = right;
                while (minPreNode.left.left != null) {
                    minPreNode = minPreNode.left;
                }
                const minVal = minPreNode.left.val;
                root.val = minVal;
                minPreNode.left = deleteNode(minPreNode.left, minVal);
            }
        }
    }
    return root;
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let node = root.as_ref().unwrap().borrow();
        if node.left.is_none() {
            return node.val;
        }
        Self::dfs(&node.left)
    }

    pub fn delete_node(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        key: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_some() {
            let mut node = root.as_mut().unwrap().borrow_mut();
            match node.val.cmp(&key) {
                std::cmp::Ordering::Less => {
                    node.right = Self::delete_node(node.right.take(), key);
                }
                std::cmp::Ordering::Greater => {
                    node.left = Self::delete_node(node.left.take(), key);
                }
                std::cmp::Ordering::Equal => {
                    match (node.left.is_some(), node.right.is_some()) {
                        (false, false) => {
                            return None;
                        }
                        (true, false) => {
                            return node.left.take();
                        }
                        (false, true) => {
                            return node.right.take();
                        }
                        (true, true) => {
                            if node.right.as_ref().unwrap().borrow().left.is_none() {
                                let mut r = node.right.take();
                                r.as_mut().unwrap().borrow_mut().left = node.left.take();
                                return r;
                            } else {
                                let val = Self::dfs(&node.right);
                                node.val = val;
                                node.right = Self::delete_node(node.right.take(), val);
                            }
                        }
                    };
                }
            }
        }
        root
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉搜索树的根节点 <strong>root </strong>和一个值 <strong>key</strong>，删除二叉搜索树中的&nbsp;<strong>key&nbsp;</strong>对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。</p>

<p>一般来说，删除节点可分为两个步骤：</p>

<ol>
	<li>首先找到需要删除的节点；</li>
	<li>如果找到了，删除它。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0450.Delete%20Node%20in%20a%20BST/images/del_node_1.jpg" style="width: 800px;" /></p>

<pre>
<strong>输入：</strong>root = [5,3,6,2,4,null,7], key = 3
<strong>输出：</strong>[5,4,6,2,null,null,7]
<strong>解释：</strong>给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。

<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0450.Delete%20Node%20in%20a%20BST/images/del_node_supp.jpg" style="width: 350px;" />
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [5,3,6,2,4,null,7], key = 0
<strong>输出:</strong> [5,3,6,2,4,null,7]
<strong>解释:</strong> 二叉树不包含值为 0 的节点
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> root = [], key = 0
<strong>输出:</strong> []</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点数的范围&nbsp;<code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>节点值唯一</li>
	<li><code>root</code>&nbsp;是合法的二叉搜索树</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= key &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong> 要求算法时间复杂度为&nbsp;O(h)，h 为树的高度。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

二叉搜索树有以下性质：

1. 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
1. 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
1. 任意节点的左、右子树也分别为二叉搜索树。

我们可以递归判断当前节点 $root$ 与 $key$ 的大小关系：

1. 若 $root.val>key$，则递归左子树；
1. 若 $root.val<key$，则递归右子树；
1. 若 $root.val=key$，则进一步判断：
    1. 若 $root$ 没有左子树，则 $root.right$ 顶替 $root$ 的位置；
    1. 若 $root$ 没有右子树，则 $root.left$ 顶替 $root$ 的位置；
    1. 若 $root$ 同时存在左右子树，则将左子树转移至右子树的最左节点的左子树上，然后 $root.right$ 顶替 $root$ 的位置。

时间复杂度 $O(H)$，其中 $H$ 是树的高度。

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
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
            return root
        if root.val < key:
            root.right = self.deleteNode(root.right, key)
            return root
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        node = root.right
        while node.left:
            node = node.left
        node.left = root.left
        root = root.right
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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        if (root.val < key) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        if (root.left == null) {
            return root.right;
        }
        if (root.right == null) {
            return root.left;
        }
        TreeNode node = root.right;
        while (node.left != null) {
            node = node.left;
        }
        node.left = root.left;
        root = root.right;
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* node = root->right;
        while (node->left) node = node->left;
        node->left = root->left;
        root = root->right;
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
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val > key {
		root.Left = deleteNode(root.Left, key)
		return root
	}
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
		return root
	}
	if root.Left == nil {
		return root.Right
	}
	if root.Right == nil {
		return root.Left
	}
	node := root.Right
	for node.Left != nil {
		node = node.Left
	}
	node.Left = root.Left
	root = root.Right
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

function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    if (root == null) {
        return root;
    }
    const { val, left, right } = root;
    if (val > key) {
        root.left = deleteNode(left, key);
    } else if (val < key) {
        root.right = deleteNode(right, key);
    } else {
        if (left == null && right == null) {
            root = null;
        } else if (left == null || right == null) {
            root = left || right;
        } else {
            if (right.left == null) {
                right.left = left;
                root = right;
            } else {
                let minPreNode = right;
                while (minPreNode.left.left != null) {
                    minPreNode = minPreNode.left;
                }
                const minVal = minPreNode.left.val;
                root.val = minVal;
                minPreNode.left = deleteNode(minPreNode.left, minVal);
            }
        }
    }
    return root;
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let node = root.as_ref().unwrap().borrow();
        if node.left.is_none() {
            return node.val;
        }
        Self::dfs(&node.left)
    }

    pub fn delete_node(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        key: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_some() {
            let mut node = root.as_mut().unwrap().borrow_mut();
            match node.val.cmp(&key) {
                std::cmp::Ordering::Less => {
                    node.right = Self::delete_node(node.right.take(), key);
                }
                std::cmp::Ordering::Greater => {
                    node.left = Self::delete_node(node.left.take(), key);
                }
                std::cmp::Ordering::Equal => {
                    match (node.left.is_some(), node.right.is_some()) {
                        (false, false) => {
                            return None;
                        }
                        (true, false) => {
                            return node.left.take();
                        }
                        (false, true) => {
                            return node.right.take();
                        }
                        (true, true) => {
                            if node.right.as_ref().unwrap().borrow().left.is_none() {
                                let mut r = node.right.take();
                                r.as_mut().unwrap().borrow_mut().left = node.left.take();
                                return r;
                            } else {
                                let val = Self::dfs(&node.right);
                                node.val = val;
                                node.right = Self::delete_node(node.right.take(), val);
                            }
                        }
                    };
                }
            }
        }
        root
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [451. 根据字符出现频率排序](https://leetcode.cn/problems/sort-characters-by-frequency){#451}

{{< tabs "451" >}}

{{% tab "python" %}}
```python
class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        return ''.join(c * v for c, v in sorted(cnt.items(), key=lambda x: -x[1]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> cnt = new HashMap<>(52);
        for (int i = 0; i < s.length(); ++i) {
            cnt.merge(s.charAt(i), 1, Integer::sum);
        }
        List<Character> cs = new ArrayList<>(cnt.keySet());
        cs.sort((a, b) -> cnt.get(b) - cnt.get(a));
        StringBuilder ans = new StringBuilder();
        for (char c : cs) {
            for (int v = cnt.get(c); v > 0; --v) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char& c : s) {
            ++cnt[c];
        }
        vector<char> cs;
        for (auto& [c, _] : cnt) {
            cs.push_back(c);
        }
        sort(cs.begin(), cs.end(), [&](char& a, char& b) {
            return cnt[a] > cnt[b];
        });
        string ans;
        for (char& c : cs) {
            ans += string(cnt[c], c);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func frequencySort(s string) string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	cs := make([]byte, 0, len(s))
	for c := range cnt {
		cs = append(cs, c)
	}
	sort.Slice(cs, func(i, j int) bool { return cnt[cs[i]] > cnt[cs[j]] })
	ans := make([]byte, 0, len(s))
	for _, c := range cs {
		ans = append(ans, bytes.Repeat([]byte{c}, cnt[c])...)
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function frequencySort(s: string): string {
    const cnt: Map<string, number> = new Map();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    const cs = Array.from(cnt.keys()).sort((a, b) => cnt.get(b)! - cnt.get(a)!);
    const ans: string[] = [];
    for (const c of cs) {
        ans.push(c.repeat(cnt.get(c)!));
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut cnt = HashMap::new();
        for c in s.chars() {
            cnt.insert(c, cnt.get(&c).unwrap_or(&0) + 1);
        }
        let mut cs = cnt.into_iter().collect::<Vec<(char, i32)>>();
        cs.sort_unstable_by(|(_, a), (_, b)| b.cmp(&a));
        cs.into_iter()
            .map(|(c, v)| vec![c; v as usize].into_iter().collect::<String>())
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function frequencySort($s) {
        $cnt = array_count_values(str_split($s));
        $cs = array_keys($cnt);
        usort($cs, function ($a, $b) use ($cnt) {
            return $cnt[$b] <=> $cnt[$a];
        });
        $ans = '';
        foreach ($cs as $c) {
            $ans .= str_repeat($c, $cnt[$c]);
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

<p>给定一个字符串 <code>s</code> ，根据字符出现的 <strong>频率</strong> 对其进行 <strong>降序排序</strong> 。一个字符出现的 <strong>频率</strong> 是它出现在字符串中的次数。</p>

<p>返回 <em>已排序的字符串&nbsp;</em>。如果有多个答案，返回其中任何一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入: </strong>s = "tree"
<strong>输出: </strong>"eert"
<strong>解释: </strong>'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入: </strong>s = "cccaaa"
<strong>输出: </strong>"cccaaa"
<strong>解释: </strong>'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入: </strong>s = "Aabb"
<strong>输出: </strong>"bbAa"
<strong>解释: </strong>此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;由大小写英文字母和数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们用哈希表 $\textit{cnt}$ 统计字符串 $s$ 中每个字符出现的次数，然后将 $\textit{cnt}$ 中的键值对按照出现次数降序排序，最后按照排序后的顺序拼接字符串即可。

时间复杂度 $O(n + k \times \log k)$，空间复杂度 $O(n + k)$，其中 $n$ 为字符串 $s$ 的长度，而 $k$ 为不同字符的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        return ''.join(c * v for c, v in sorted(cnt.items(), key=lambda x: -x[1]))
```

#### Java

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> cnt = new HashMap<>(52);
        for (int i = 0; i < s.length(); ++i) {
            cnt.merge(s.charAt(i), 1, Integer::sum);
        }
        List<Character> cs = new ArrayList<>(cnt.keySet());
        cs.sort((a, b) -> cnt.get(b) - cnt.get(a));
        StringBuilder ans = new StringBuilder();
        for (char c : cs) {
            for (int v = cnt.get(c); v > 0; --v) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char& c : s) {
            ++cnt[c];
        }
        vector<char> cs;
        for (auto& [c, _] : cnt) {
            cs.push_back(c);
        }
        sort(cs.begin(), cs.end(), [&](char& a, char& b) {
            return cnt[a] > cnt[b];
        });
        string ans;
        for (char& c : cs) {
            ans += string(cnt[c], c);
        }
        return ans;
    }
};
```

#### Go

```go
func frequencySort(s string) string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	cs := make([]byte, 0, len(s))
	for c := range cnt {
		cs = append(cs, c)
	}
	sort.Slice(cs, func(i, j int) bool { return cnt[cs[i]] > cnt[cs[j]] })
	ans := make([]byte, 0, len(s))
	for _, c := range cs {
		ans = append(ans, bytes.Repeat([]byte{c}, cnt[c])...)
	}
	return string(ans)
}
```

#### TypeScript

```ts
function frequencySort(s: string): string {
    const cnt: Map<string, number> = new Map();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    const cs = Array.from(cnt.keys()).sort((a, b) => cnt.get(b)! - cnt.get(a)!);
    const ans: string[] = [];
    for (const c of cs) {
        ans.push(c.repeat(cnt.get(c)!));
    }
    return ans.join('');
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut cnt = HashMap::new();
        for c in s.chars() {
            cnt.insert(c, cnt.get(&c).unwrap_or(&0) + 1);
        }
        let mut cs = cnt.into_iter().collect::<Vec<(char, i32)>>();
        cs.sort_unstable_by(|(_, a), (_, b)| b.cmp(&a));
        cs.into_iter()
            .map(|(c, v)| vec![c; v as usize].into_iter().collect::<String>())
            .collect()
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function frequencySort($s) {
        $cnt = array_count_values(str_split($s));
        $cs = array_keys($cnt);
        usort($cs, function ($a, $b) use ($cnt) {
            return $cnt[$b] <=> $cnt[$a];
        });
        $ans = '';
        foreach ($cs as $c) {
            $ans .= str_repeat($c, $cnt[$c]);
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

# [452. 用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons){#452}

{{< tabs "452" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        ans, last = 0, -inf
        for a, b in sorted(points, key=lambda x: x[1]):
            if a > last:
                ans += 1
                last = b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        // 直接 a[1] - b[1] 可能会溢出
        Arrays.sort(points, Comparator.comparingInt(a -> a[1]));
        int ans = 0;
        long last = -(1L << 60);
        for (var p : points) {
            int a = p[0], b = p[1];
            if (a > last) {
                ++ans;
                last = b;
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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        long long last = -(1LL << 60);
        for (auto& p : points) {
            int a = p[0], b = p[1];
            if (a > last) {
                ++ans;
                last = b;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMinArrowShots(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1] })
	last := -(1 << 60)
	for _, p := range points {
		a, b := p[0], p[1]
		if a > last {
			ans++
			last = b
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinArrowShots(points: number[][]): number {
    points.sort((a, b) => a[1] - b[1]);
    let ans = 0;
    let last = -Infinity;
    for (const [a, b] of points) {
        if (last < a) {
            ans++;
            last = b;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FindMinArrowShots(int[][] points) {
        Array.Sort(points, (a, b) => a[1] < b[1] ? -1 : a[1] > b[1] ? 1 : 0);
        int ans = 0;
        long last = long.MinValue;
        foreach (var point in points) {
            if (point[0] > last) {
                ++ans;
                last = point[1];
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

<p>有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组&nbsp;<code>points</code>&nbsp;，其中<code>points[i] = [x<sub>start</sub>, x<sub>end</sub>]</code>&nbsp;表示水平直径在&nbsp;<code>x<sub>start</sub></code>&nbsp;和&nbsp;<code>x<sub>end</sub></code>之间的气球。你不知道气球的确切 y 坐标。</p>

<p>一支弓箭可以沿着 x 轴从不同点 <strong>完全垂直</strong> 地射出。在坐标 <code>x</code> 处射出一支箭，若有一个气球的直径的开始和结束坐标为 <code>x</code><sub><code>start</code>，</sub><code>x</code><sub><code>end</code>，</sub> 且满足 &nbsp;<code>x<sub>start</sub>&nbsp;≤ x ≤ x</code><sub><code>end</code>，</sub>则该气球会被 <strong>引爆</strong>&nbsp;<sub>。</sub>可以射出的弓箭的数量 <strong>没有限制</strong> 。 弓箭一旦被射出之后，可以无限地前进。</p>

<p>给你一个数组 <code>points</code> ，<em>返回引爆所有气球所必须射出的 <strong>最小</strong> 弓箭数&nbsp;</em>。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[10,16],[2,8],[1,6],[7,12]]
<strong>输出：</strong>2
<strong>解释：</strong>气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,2],[3,4],[5,6],[7,8]]
<strong>输出：</strong>4
<strong>解释：</strong>每个气球需要射出一支箭，总共需要4支箭。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,2],[2,3],[3,4],[4,5]]
<strong>输出：</strong>2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= x<sub>start</sub>&nbsp;&lt; x<sub>end</sub>&nbsp;&lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们可以将所有气球按照右端点升序排序，然后从左到右遍历气球，维护当前的箭所能覆盖的最右端点 $last$，如果当前气球的左端点 $a$ 大于 $last$，说明当前箭无法覆盖当前气球，需要额外射出一支箭，那么答案加一，同时更新 $last$ 为当前气球的右端点 $b$。

遍历结束后，即可得到答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为气球的数量。

相似题目：

-   [757. 设置交集大小至少为 2](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0757.Set%20Intersection%20Size%20At%20Least%20Two/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        ans, last = 0, -inf
        for a, b in sorted(points, key=lambda x: x[1]):
            if a > last:
                ans += 1
                last = b
        return ans
```

#### Java

```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        // 直接 a[1] - b[1] 可能会溢出
        Arrays.sort(points, Comparator.comparingInt(a -> a[1]));
        int ans = 0;
        long last = -(1L << 60);
        for (var p : points) {
            int a = p[0], b = p[1];
            if (a > last) {
                ++ans;
                last = b;
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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        long long last = -(1LL << 60);
        for (auto& p : points) {
            int a = p[0], b = p[1];
            if (a > last) {
                ++ans;
                last = b;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMinArrowShots(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1] })
	last := -(1 << 60)
	for _, p := range points {
		a, b := p[0], p[1]
		if a > last {
			ans++
			last = b
		}
	}
	return
}
```

#### TypeScript

```ts
function findMinArrowShots(points: number[][]): number {
    points.sort((a, b) => a[1] - b[1]);
    let ans = 0;
    let last = -Infinity;
    for (const [a, b] of points) {
        if (last < a) {
            ans++;
            last = b;
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int FindMinArrowShots(int[][] points) {
        Array.Sort(points, (a, b) => a[1] < b[1] ? -1 : a[1] > b[1] ? 1 : 0);
        int ans = 0;
        long last = long.MinValue;
        foreach (var point in points) {
            if (point[0] > last) {
                ++ans;
                last = point[1];
            }
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

# [453. 最小操作次数使数组元素相等](https://leetcode.cn/problems/minimum-moves-to-equal-array-elements){#453}

{{< tabs "453" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - min(nums) * len(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves(int[] nums) {
        return Arrays.stream(nums).sum() - Arrays.stream(nums).min().getAsInt() * nums.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s = 0;
        int mi = 1 << 30;
        for (int x : nums) {
            s += x;
            mi = min(mi, x);
        }
        return s - mi * nums.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves(nums []int) int {
	mi := 1 << 30
	s := 0
	for _, x := range nums {
		s += x
		if x < mi {
			mi = x
		}
	}
	return s - mi*len(nums)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMoves(nums: number[]): number {
    let mi = 1 << 30;
    let s = 0;
    for (const x of nums) {
        s += x;
        mi = Math.min(mi, x);
    }
    return s - mi * nums.length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的整数数组，每次操作将会使 <code>n - 1</code> 个元素增加 <code>1</code> 。返回让数组所有元素相等的最小操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>3
<strong>解释：</strong>
只需要3次操作（注意每次操作会增加两个元素的值）：
[1,2,3]  =&gt;  [2,3,3]  =&gt;  [3,4,3]  =&gt;  [4,4,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>答案保证符合 <strong>32-bit</strong> 整数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们不妨记数组 $\textit{nums}$ 的最小值为 $\textit{mi}$，数组的和为 $\textit{s}$，数组的长度为 $\textit{n}$。

假设最小操作次数为 $\textit{k}$，最终数组的所有元素都为 $\textit{x}$，则有：

$$
\begin{aligned}
\textit{s} + (\textit{n} - 1) \times \textit{k} &= \textit{n} \times \textit{x} \\
\textit{x} &= \textit{mi} + \textit{k} \\
\end{aligned}
$$

将第二个式子代入第一个式子，得到：

$$
\begin{aligned}
\textit{s} + (\textit{n} - 1) \times \textit{k} &= \textit{n} \times (\textit{mi} + \textit{k}) \\
\textit{s} + (\textit{n} - 1) \times \textit{k} &= \textit{n} \times \textit{mi} + \textit{n} \times \textit{k} \\
\textit{k} &= \textit{s} - \textit{n} \times \textit{mi} \\
\end{aligned}
$$

因此，最小操作次数为 $\textit{s} - \textit{n} \times \textit{mi}$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - min(nums) * len(nums)
```

#### Java

```java
class Solution {
    public int minMoves(int[] nums) {
        return Arrays.stream(nums).sum() - Arrays.stream(nums).min().getAsInt() * nums.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s = 0;
        int mi = 1 << 30;
        for (int x : nums) {
            s += x;
            mi = min(mi, x);
        }
        return s - mi * nums.size();
    }
};
```

#### Go

```go
func minMoves(nums []int) int {
	mi := 1 << 30
	s := 0
	for _, x := range nums {
		s += x
		if x < mi {
			mi = x
		}
	}
	return s - mi*len(nums)
}
```

#### TypeScript

```ts
function minMoves(nums: number[]): number {
    let mi = 1 << 30;
    let s = 0;
    for (const x of nums) {
        s += x;
        mi = Math.min(mi, x);
    }
    return s - mi * nums.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii){#454}

{{< tabs "454" >}}

{{% tab "python" %}}
```python
class Solution:
    def fourSumCount(
        self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]
    ) -> int:
        cnt = Counter(a + b for a in nums1 for b in nums2)
        return sum(cnt[-(c + d)] for c in nums3 for d in nums4)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int a : nums1) {
            for (int b : nums2) {
                cnt.merge(a + b, 1, Integer::sum);
            }
        }
        int ans = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                ans += cnt.getOrDefault(-(c + d), 0);
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> cnt;
        for (int a : nums1) {
            for (int b : nums2) {
                ++cnt[a + b];
            }
        }
        int ans = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                ans += cnt[-(c + d)];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) (ans int) {
	cnt := map[int]int{}
	for _, a := range nums1 {
		for _, b := range nums2 {
			cnt[a+b]++
		}
	}
	for _, c := range nums3 {
		for _, d := range nums4 {
			ans += cnt[-(c + d)]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fourSumCount(nums1: number[], nums2: number[], nums3: number[], nums4: number[]): number {
    const cnt: Record<number, number> = {};
    for (const a of nums1) {
        for (const b of nums2) {
            const x = a + b;
            cnt[x] = (cnt[x] || 0) + 1;
        }
    }
    let ans = 0;
    for (const c of nums3) {
        for (const d of nums4) {
            const x = c + d;
            ans += cnt[-x] || 0;
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
    pub fn four_sum_count(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
        nums3: Vec<i32>,
        nums4: Vec<i32>,
    ) -> i32 {
        let mut cnt = HashMap::new();
        for &a in &nums1 {
            for &b in &nums2 {
                *cnt.entry(a + b).or_insert(0) += 1;
            }
        }
        let mut ans = 0;
        for &c in &nums3 {
            for &d in &nums4 {
                if let Some(&count) = cnt.get(&(0 - (c + d))) {
                    ans += count;
                }
            }
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

<p>给你四个整数数组 <code>nums1</code>、<code>nums2</code>、<code>nums3</code> 和 <code>nums4</code> ，数组长度都是 <code>n</code> ，请你计算有多少个元组 <code>(i, j, k, l)</code> 能满足：</p>

<ul>
	<li><code>0 &lt;= i, j, k, l &lt; n</code></li>
	<li><code>nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
<strong>输出：</strong>2
<strong>解释：</strong>
两个元组如下：
1. (0, 0, 0, 1) -&gt; nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -&gt; nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p>&nbsp; <strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>n == nums3.length</code></li>
	<li><code>n == nums4.length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>-2<sup>28</sup> &lt;= nums1[i], nums2[i], nums3[i], nums4[i] &lt;= 2<sup>28</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以将数组 $nums1$ 和 $nums2$ 中的元素 $a$ 和 $b$ 相加，将所有可能的和存储在哈希表 $cnt$ 中，其中键为两数之和，值为两数之和出现的次数。

然后我们遍历数组 $nums3$ 和 $nums4$ 中的元素 $c$ 和 $d$，令 $c+d$ 为目标值，那么答案即为 $cnt[-(c+d)]$ 的累加和。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$，其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fourSumCount(
        self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]
    ) -> int:
        cnt = Counter(a + b for a in nums1 for b in nums2)
        return sum(cnt[-(c + d)] for c in nums3 for d in nums4)
```

#### Java

```java
class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int a : nums1) {
            for (int b : nums2) {
                cnt.merge(a + b, 1, Integer::sum);
            }
        }
        int ans = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                ans += cnt.getOrDefault(-(c + d), 0);
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> cnt;
        for (int a : nums1) {
            for (int b : nums2) {
                ++cnt[a + b];
            }
        }
        int ans = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                ans += cnt[-(c + d)];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) (ans int) {
	cnt := map[int]int{}
	for _, a := range nums1 {
		for _, b := range nums2 {
			cnt[a+b]++
		}
	}
	for _, c := range nums3 {
		for _, d := range nums4 {
			ans += cnt[-(c + d)]
		}
	}
	return
}
```

#### TypeScript

```ts
function fourSumCount(nums1: number[], nums2: number[], nums3: number[], nums4: number[]): number {
    const cnt: Record<number, number> = {};
    for (const a of nums1) {
        for (const b of nums2) {
            const x = a + b;
            cnt[x] = (cnt[x] || 0) + 1;
        }
    }
    let ans = 0;
    for (const c of nums3) {
        for (const d of nums4) {
            const x = c + d;
            ans += cnt[-x] || 0;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
        nums3: Vec<i32>,
        nums4: Vec<i32>,
    ) -> i32 {
        let mut cnt = HashMap::new();
        for &a in &nums1 {
            for &b in &nums2 {
                *cnt.entry(a + b).or_insert(0) += 1;
            }
        }
        let mut ans = 0;
        for &c in &nums3 {
            for &d in &nums4 {
                if let Some(&count) = cnt.get(&(0 - (c + d))) {
                    ans += count;
                }
            }
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

# [455. 分发饼干](https://leetcode.cn/problems/assign-cookies){#455}

{{< tabs "455" >}}

{{% tab "python" %}}
```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j = 0
        for i, x in enumerate(g):
            while j < len(s) and s[j] < g[i]:
                j += 1
            if j >= len(s):
                return i
            j += 1
        return len(g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int m = g.length;
        int n = s.length;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && s[j] < g[i]) {
                ++j;
            }
            if (j++ >= n) {
                return i;
            }
        }
        return m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size(), n = s.size();
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && s[j] < g[i]) {
                ++j;
            }
            if (j++ >= n) {
                return i;
            }
        }
        return m;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	j := 0
	for i, x := range g {
		for j < len(s) && s[j] < x {
			j++
		}
		if j >= len(s) {
			return i
		}
		j++
	}
	return len(g)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findContentChildren(g: number[], s: number[]): number {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
    const m = g.length;
    const n = s.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && s[j] < g[i]) {
            ++j;
        }
        if (j++ >= n) {
            return i;
        }
    }
    return m;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function (g, s) {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
    const m = g.length;
    const n = s.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && s[j] < g[i]) {
            ++j;
        }
        if (j++ >= n) {
            return i;
        }
    }
    return m;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。</p>

<p>对每个孩子 <code>i</code>，都有一个胃口值&nbsp;<code>g[i]</code><sub>，</sub>这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 <code>j</code>，都有一个尺寸 <code>s[j]</code><sub>&nbsp;</sub>。如果 <code>s[j]&nbsp;&gt;= g[i]</code>，我们可以将这个饼干 <code>j</code> 分配给孩子 <code>i</code> ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。</p>
&nbsp;

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> g = [1,2,3], s = [1,1]
<strong>输出:</strong> 1
<strong>解释:</strong> 
你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。
所以你应该输出 1。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> g = [1,2], s = [1,2,3]
<strong>输出:</strong> 2
<strong>解释:</strong> 
你有两个孩子和三块小饼干，2 个孩子的胃口值分别是 1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出 2。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= g.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= g[i], s[j] &lt;=&nbsp;2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与&nbsp;<a href="https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/">2410. 运动员和训练师的最大匹配数</a>&nbsp;题相同。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

根据题目描述，我们应该优先将饼干分配给胃口值小的孩子，这样可以尽可能满足更多的孩子。

因此，我们首先对两个数组进行排序，然后用两个指针 $i$ 和 $j$ 分别指向数组 $g$ 和 $s$ 的头部，每次比较 $g[i]$ 和 $s[j]$ 的大小：

-   如果 $s[j] \lt g[i]$，说明当前饼干 $s[j]$ 无法满足当前孩子 $g[i]$，我们应该将尺寸更大的饼干分配给当前孩子，因此 $j$ 应该右移一位；如果 $j$ 越界，说明无法满足当前孩子，此时成功分配的孩子数量为 $i$，直接返回即可；
-   如果 $s[j] \ge g[i]$，说明当前饼干 $s[j]$ 可以满足当前孩子 $g[i]$，我们将当前饼干分配给当前孩子，因此 $i$ 和 $j$ 都应该右移一位。

如果遍历完数组 $g$，则说明所有孩子都已经分配到饼干，则返回孩子总数即可。

时间复杂度 $O(m \times \log m + n \times \log n)$，空间复杂度 $O(\log m + \log n)$。其中 $m$ 和 $n$ 分别为数组 $g$ 和 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j = 0
        for i, x in enumerate(g):
            while j < len(s) and s[j] < g[i]:
                j += 1
            if j >= len(s):
                return i
            j += 1
        return len(g)
```

#### Java

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int m = g.length;
        int n = s.length;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && s[j] < g[i]) {
                ++j;
            }
            if (j++ >= n) {
                return i;
            }
        }
        return m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size(), n = s.size();
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && s[j] < g[i]) {
                ++j;
            }
            if (j++ >= n) {
                return i;
            }
        }
        return m;
    }
};
```

#### Go

```go
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	j := 0
	for i, x := range g {
		for j < len(s) && s[j] < x {
			j++
		}
		if j >= len(s) {
			return i
		}
		j++
	}
	return len(g)
}
```

#### TypeScript

```ts
function findContentChildren(g: number[], s: number[]): number {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
    const m = g.length;
    const n = s.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && s[j] < g[i]) {
            ++j;
        }
        if (j++ >= n) {
            return i;
        }
    }
    return m;
}
```

#### JavaScript

```js
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function (g, s) {
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
    const m = g.length;
    const n = s.length;
    for (let i = 0, j = 0; i < m; ++i) {
        while (j < n && s[j] < g[i]) {
            ++j;
        }
        if (j++ >= n) {
            return i;
        }
    }
    return m;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [456. 132 模式](https://leetcode.cn/problems/132-pattern){#456}

{{< tabs "456" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        s = sorted(set(nums))
        n = len(nums)
        left = [inf] * (n + 1)
        for i, x in enumerate(nums):
            left[i + 1] = min(left[i], x)
        tree = BinaryIndexedTree(len(s))
        for i in range(n - 1, -1, -1):
            x = bisect_left(s, nums[i]) + 1
            y = bisect_left(s, left[i]) + 1
            if x > y and tree.query(x - 1) > tree.query(y):
                return True
            tree.update(x, 1)
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public boolean find132pattern(int[] nums) {
        int[] s = nums.clone();
        Arrays.sort(s);
        int n = nums.length;
        int m = 0;
        int[] left = new int[n + 1];
        left[0] = 1 << 30;
        for (int i = 0; i < n; ++i) {
            left[i + 1] = Math.min(left[i], nums[i]);
            if (i == 0 || s[i] != s[i - 1]) {
                s[m++] = s[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int i = n - 1; i >= 0; --i) {
            int x = search(s, m, nums[i]);
            int y = search(s, m, left[i]);
            if (x > y && tree.query(x - 1) > tree.query(y)) {
                return true;
            }
            tree.update(x, 1);
        }
        return false;
    }

    private int search(int[] nums, int r, int x) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) {
        this->n = n;
        this->c = vector<int>(n + 1, 0);
    }

    void update(int x, int val) {
        while (x <= n) {
            c[x] += val;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> s = nums;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        BinaryIndexedTree tree(s.size());
        int n = nums.size();
        int left[n + 1];
        memset(left, 63, sizeof(left));
        for (int i = 0; i < n; ++i) {
            left[i + 1] = min(left[i], nums[i]);
        }
        for (int i = nums.size() - 1; ~i; --i) {
            int x = lower_bound(s.begin(), s.end(), nums[i]) - s.begin() + 1;
            int y = lower_bound(s.begin(), s.end(), left[i]) - s.begin() + 1;
            if (x > y && tree.query(x - 1) > tree.query(y)) {
                return true;
            }
            tree.update(x, 1);
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, val int) {
	for x <= this.n {
		this.c[x] += val
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func find132pattern(nums []int) bool {
	n := len(nums)
	s := make([]int, n)
	left := make([]int, n+1)
	left[0] = 1 << 30
	copy(s, nums)
	sort.Ints(s)
	m := 0
	for i := 0; i < n; i++ {
		left[i+1] = min(left[i], nums[i])
		if i == 0 || s[i] != s[i-1] {
			s[m] = s[i]
			m++
		}
	}
	s = s[:m]
	tree := newBinaryIndexedTree(m)
	for i := n - 1; i >= 0; i-- {
		x := sort.SearchInts(s, nums[i]) + 1
		y := sort.SearchInts(s, left[i]) + 1
		if x > y && tree.query(x-1) > tree.query(y) {
			return true
		}
		tree.update(x, 1)
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndextedTree {
    n: number;
    c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    update(x: number, val: number): void {
        while (x <= this.n) {
            this.c[x] += val;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function find132pattern(nums: number[]): boolean {
    let s: number[] = [...nums];
    s.sort((a, b) => a - b);
    const n = nums.length;
    const left: number[] = new Array(n + 1).fill(1 << 30);
    let m = 0;
    for (let i = 0; i < n; ++i) {
        left[i + 1] = Math.min(left[i], nums[i]);
        if (i == 0 || s[i] != s[i - 1]) {
            s[m++] = s[i];
        }
    }
    s = s.slice(0, m);
    const tree = new BinaryIndextedTree(m);
    for (let i = n - 1; i >= 0; --i) {
        const x = search(s, nums[i]);
        const y = search(s, left[i]);
        if (x > y && tree.query(x - 1) > tree.query(y)) {
            return true;
        }
        tree.update(x, 1);
    }
    return false;
}

function search(nums: number[], x: number): number {
    let l = 0,
        r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut vk = i32::MIN;
        let mut stk = vec![];
        for i in (0..n).rev() {
            if nums[i] < vk {
                return true;
            }
            while !stk.is_empty() && stk.last().unwrap() < &nums[i] {
                vk = stk.pop().unwrap();
            }
            stk.push(nums[i]);
        }
        false
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，数组中共有 <code>n</code> 个整数。<strong>132 模式的子序列</strong> 由三个整数 <code>nums[i]</code>、<code>nums[j]</code> 和 <code>nums[k]</code> 组成，并同时满足：<code>i < j < k</code> 和 <code>nums[i] < nums[k] < nums[j]</code> 。</p>

<p>如果 <code>nums</code> 中存在 <strong>132 模式的子序列</strong> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>false
<strong>解释：</strong>序列中不存在 132 模式的子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,4,2]
<strong>输出：</strong>true
<strong>解释：</strong>序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,3,2,0]
<strong>输出：</strong>true
<strong>解释：</strong>序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们可以枚举从右往左枚举整数 $nums[i]$，并维护一个单调栈，栈中的元素从栈底到栈顶单调递减。维护一个变量 $vk$，表示 $nums[i]$ 右侧且小于 $nums[i]$ 的最大值。初始时，$vk$ 的值为 $-\infty$。

我们从右往左遍历数组，对于遍历到的每个元素 $nums[i]$，如果 $nums[i]$ 小于 $vk$，则说明我们找到了一个满足 $nums[i] \lt nums[k] \lt nums[j]$ 的三元组，返回 `true`。否则，如果栈顶元素小于 $nums[i]$，则我们循环将栈顶元素出栈，并且更新 $vk$ 的值为出栈元素，直到栈为空或者栈顶元素大于等于 $nums[i]$。最后，我们将 $nums[i]$ 入栈。

如果遍历结束后仍未找到满足条件的三元组，说明不存在这样的三元组，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        vk = -inf
        stk = []
        for x in nums[::-1]:
            if x < vk:
                return True
            while stk and stk[-1] < x:
                vk = stk.pop()
            stk.append(x)
        return False
```

#### Java

```java
class Solution {
    public boolean find132pattern(int[] nums) {
        int vk = -(1 << 30);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = nums.length - 1; i >= 0; --i) {
            if (nums[i] < vk) {
                return true;
            }
            while (!stk.isEmpty() && stk.peek() < nums[i]) {
                vk = stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int vk = INT_MIN;
        stack<int> stk;
        for (int i = nums.size() - 1; ~i; --i) {
            if (nums[i] < vk) {
                return true;
            }
            while (!stk.empty() && stk.top() < nums[i]) {
                vk = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
```

#### Go

```go
func find132pattern(nums []int) bool {
	vk := -(1 << 30)
	stk := []int{}
	for i := len(nums) - 1; i >= 0; i-- {
		if nums[i] < vk {
			return true
		}
		for len(stk) > 0 && stk[len(stk)-1] < nums[i] {
			vk = stk[len(stk)-1]
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, nums[i])
	}
	return false
}
```

#### TypeScript

```ts
function find132pattern(nums: number[]): boolean {
    let vk = -Infinity;
    const stk: number[] = [];
    for (let i = nums.length - 1; i >= 0; --i) {
        if (nums[i] < vk) {
            return true;
        }
        while (stk.length && stk[stk.length - 1] < nums[i]) {
            vk = stk.pop()!;
        }
        stk.push(nums[i]);
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut vk = i32::MIN;
        let mut stk = vec![];
        for i in (0..n).rev() {
            if nums[i] < vk {
                return true;
            }
            while !stk.is_empty() && stk.last().unwrap() < &nums[i] {
                vk = stk.pop().unwrap();
            }
            stk.push(nums[i]);
        }
        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：离散化 + 树状数组

我们可以用树状数组维护比某个数小的元素的个数，用一个数组 $left$ 记录 $nums[i]$ 左侧的最小值。

我们从右往左遍历数组，对于遍历到的每个元素 $nums[i]$，我们将 $nums[i]$ 离散化为一个整数 $x$，将 $left[i]$ 离散化为一个整数 $y$，如果此时 $x \gt y$，并且树状数组中存在比 $y$ 大但比 $x$ 小的元素，则说明存在满足 $nums[i] \lt nums[k] \lt nums[j]$ 的三元组，返回 `true`。否则，我们将 $nums[i]$ 的离散化结果 $x$ 更新到树状数组中。

如果遍历结束后仍未找到满足条件的三元组，说明不存在这样的三元组，返回 `false`。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        s = sorted(set(nums))
        n = len(nums)
        left = [inf] * (n + 1)
        for i, x in enumerate(nums):
            left[i + 1] = min(left[i], x)
        tree = BinaryIndexedTree(len(s))
        for i in range(n - 1, -1, -1):
            x = bisect_left(s, nums[i]) + 1
            y = bisect_left(s, left[i]) + 1
            if x > y and tree.query(x - 1) > tree.query(y):
                return True
            tree.update(x, 1)
        return False
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public boolean find132pattern(int[] nums) {
        int[] s = nums.clone();
        Arrays.sort(s);
        int n = nums.length;
        int m = 0;
        int[] left = new int[n + 1];
        left[0] = 1 << 30;
        for (int i = 0; i < n; ++i) {
            left[i + 1] = Math.min(left[i], nums[i]);
            if (i == 0 || s[i] != s[i - 1]) {
                s[m++] = s[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int i = n - 1; i >= 0; --i) {
            int x = search(s, m, nums[i]);
            int y = search(s, m, left[i]);
            if (x > y && tree.query(x - 1) > tree.query(y)) {
                return true;
            }
            tree.update(x, 1);
        }
        return false;
    }

    private int search(int[] nums, int r, int x) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) {
        this->n = n;
        this->c = vector<int>(n + 1, 0);
    }

    void update(int x, int val) {
        while (x <= n) {
            c[x] += val;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> s = nums;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        BinaryIndexedTree tree(s.size());
        int n = nums.size();
        int left[n + 1];
        memset(left, 63, sizeof(left));
        for (int i = 0; i < n; ++i) {
            left[i + 1] = min(left[i], nums[i]);
        }
        for (int i = nums.size() - 1; ~i; --i) {
            int x = lower_bound(s.begin(), s.end(), nums[i]) - s.begin() + 1;
            int y = lower_bound(s.begin(), s.end(), left[i]) - s.begin() + 1;
            if (x > y && tree.query(x - 1) > tree.query(y)) {
                return true;
            }
            tree.update(x, 1);
        }
        return false;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, val int) {
	for x <= this.n {
		this.c[x] += val
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func find132pattern(nums []int) bool {
	n := len(nums)
	s := make([]int, n)
	left := make([]int, n+1)
	left[0] = 1 << 30
	copy(s, nums)
	sort.Ints(s)
	m := 0
	for i := 0; i < n; i++ {
		left[i+1] = min(left[i], nums[i])
		if i == 0 || s[i] != s[i-1] {
			s[m] = s[i]
			m++
		}
	}
	s = s[:m]
	tree := newBinaryIndexedTree(m)
	for i := n - 1; i >= 0; i-- {
		x := sort.SearchInts(s, nums[i]) + 1
		y := sort.SearchInts(s, left[i]) + 1
		if x > y && tree.query(x-1) > tree.query(y) {
			return true
		}
		tree.update(x, 1)
	}
	return false
}
```

#### TypeScript

```ts
class BinaryIndextedTree {
    n: number;
    c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    update(x: number, val: number): void {
        while (x <= this.n) {
            this.c[x] += val;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function find132pattern(nums: number[]): boolean {
    let s: number[] = [...nums];
    s.sort((a, b) => a - b);
    const n = nums.length;
    const left: number[] = new Array(n + 1).fill(1 << 30);
    let m = 0;
    for (let i = 0; i < n; ++i) {
        left[i + 1] = Math.min(left[i], nums[i]);
        if (i == 0 || s[i] != s[i - 1]) {
            s[m++] = s[i];
        }
    }
    s = s.slice(0, m);
    const tree = new BinaryIndextedTree(m);
    for (let i = n - 1; i >= 0; --i) {
        const x = search(s, nums[i]);
        const y = search(s, left[i]);
        if (x > y && tree.query(x - 1) > tree.query(y)) {
            return true;
        }
        tree.update(x, 1);
    }
    return false;
}

function search(nums: number[], x: number): number {
    let l = 0,
        r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [457. 环形数组是否存在循环](https://leetcode.cn/problems/circular-array-loop){#457}

{{< tabs "457" >}}

{{% tab "python" %}}
```python
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)

        def next(i):
            return (i + nums[i] % n + n) % n

        for i in range(n):
            if nums[i] == 0:
                continue
            slow, fast = i, next(i)
            while nums[slow] * nums[fast] > 0 and nums[slow] * nums[next(fast)] > 0:
                if slow == fast:
                    if slow != next(slow):
                        return True
                    break
                slow, fast = next(slow), next(next(fast))
            j = i
            while nums[j] * nums[next(j)] > 0:
                nums[j] = 0
                j = next(j)
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] nums;

    public boolean circularArrayLoop(int[] nums) {
        n = nums.length;
        this.nums = nums;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int slow = i, fast = next(i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    }
                    break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            int j = i;
            while (nums[j] * nums[next(j)] > 0) {
                nums[j] = 0;
                j = next(j);
            }
        }
        return false;
    }

    private int next(int i) {
        return (i + nums[i] % n + n) % n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (!nums[i]) continue;
            int slow = i, fast = next(nums, i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(nums, slow)) return true;
                    break;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            int j = i;
            while (nums[j] * nums[next(nums, j)] > 0) {
                nums[j] = 0;
                j = next(nums, j);
            }
        }
        return false;
    }

    int next(vector<int>& nums, int i) {
        int n = nums.size();
        return (i + nums[i] % n + n) % n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func circularArrayLoop(nums []int) bool {
	for i, num := range nums {
		if num == 0 {
			continue
		}
		slow, fast := i, next(nums, i)
		for nums[slow]*nums[fast] > 0 && nums[slow]*nums[next(nums, fast)] > 0 {
			if slow == fast {
				if slow != next(nums, slow) {
					return true
				}
				break
			}
			slow, fast = next(nums, slow), next(nums, next(nums, fast))
		}
		j := i
		for nums[j]*nums[next(nums, j)] > 0 {
			nums[j] = 0
			j = next(nums, j)
		}
	}
	return false
}

func next(nums []int, i int) int {
	n := len(nums)
	return (i + nums[i]%n + n) % n
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>存在一个不含 <code>0</code> 的<strong> 环形 </strong>数组&nbsp;<code>nums</code> ，每个 <code>nums[i]</code> 都表示位于下标 <code>i</code> 的角色应该向前或向后移动的下标个数：</p>

<ul>
	<li>如果 <code>nums[i]</code> 是正数，<strong>向前</strong>（下标递增方向）移动 <code>|nums[i]|</code> 步</li>
	<li>如果&nbsp;<code>nums[i]</code> 是负数，<strong>向后</strong>（下标递减方向）移动 <code>|nums[i]|</code> 步</li>
</ul>

<p>因为数组是 <strong>环形</strong> 的，所以可以假设从最后一个元素向前移动一步会到达第一个元素，而第一个元素向后移动一步会到达最后一个元素。</p>

<p>数组中的 <strong>循环</strong> 由长度为 <code>k</code> 的下标序列 <code>seq</code> 标识：</p>

<ul>
	<li>遵循上述移动规则将导致一组重复下标序列 <code>seq[0] -&gt; seq[1] -&gt; ... -&gt; seq[k - 1] -&gt; seq[0] -&gt; ...</code></li>
	<li>所有 <code>nums[seq[j]]</code> 应当不是 <strong>全正</strong> 就是 <strong>全负</strong></li>
	<li><code>k &gt; 1</code></li>
</ul>

<p>如果 <code>nums</code> 中存在循环，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0457.Circular%20Array%20Loop/images/1723688159-qYjpWT-image.png" style="width: 402px; height: 289px;" />
<pre>
<strong>输入：</strong>nums = [2,-1,1,2,2]
<strong>输出：</strong>true
<strong>解释：</strong>图片展示了节点间如何连接。白色节点向前跳跃，而红色节点向后跳跃。
我们可以看到存在循环，按下标 0 -&gt; 2 -&gt; 3 -&gt; 0 --&gt; ...，并且其中的所有节点都是白色（以相同方向跳跃）。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0457.Circular%20Array%20Loop/images/1723688183-lRSkjp-image.png" style="width: 402px; height: 390px;" />
<pre>
<strong>输入：</strong>nums = [-1,-2,-3,-4,-5,6]
<strong>输出：</strong>false
<strong>解释：</strong>图片展示了节点间如何连接。白色节点向前跳跃，而红色节点向后跳跃。
唯一的循环长度为 1，所以返回 false。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0457.Circular%20Array%20Loop/images/1723688199-nhaMuF-image.png" style="width: 497px; height: 242px;" />
<pre>
<strong>输入：</strong>nums = [1,-1,5,1,4]
<strong>输出：</strong>true
<strong>解释：</strong>图片展示了节点间如何连接。白色节点向前跳跃，而红色节点向后跳跃。
我们可以看到存在循环，按下标 0 --&gt; 1 --&gt; 0 --&gt; ...，当它的大小大于 1 时，它有一个向前跳的节点和一个向后跳的节点，所以 <strong>它不是一个循环</strong>。
我们可以看到存在循环，按下标 3 --&gt; 4 --&gt; 3 --&gt; ...，并且其中的所有节点都是白色（以相同方向跳跃）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums[i] != 0</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能设计一个时间复杂度为 <code>O(n)</code> 且额外空间复杂度为 <code>O(1)</code> 的算法吗？</p>

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
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)

        def next(i):
            return (i + nums[i] % n + n) % n

        for i in range(n):
            if nums[i] == 0:
                continue
            slow, fast = i, next(i)
            while nums[slow] * nums[fast] > 0 and nums[slow] * nums[next(fast)] > 0:
                if slow == fast:
                    if slow != next(slow):
                        return True
                    break
                slow, fast = next(slow), next(next(fast))
            j = i
            while nums[j] * nums[next(j)] > 0:
                nums[j] = 0
                j = next(j)
        return False
```

#### Java

```java
class Solution {
    private int n;
    private int[] nums;

    public boolean circularArrayLoop(int[] nums) {
        n = nums.length;
        this.nums = nums;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int slow = i, fast = next(i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    }
                    break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            int j = i;
            while (nums[j] * nums[next(j)] > 0) {
                nums[j] = 0;
                j = next(j);
            }
        }
        return false;
    }

    private int next(int i) {
        return (i + nums[i] % n + n) % n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (!nums[i]) continue;
            int slow = i, fast = next(nums, i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(nums, slow)) return true;
                    break;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            int j = i;
            while (nums[j] * nums[next(nums, j)] > 0) {
                nums[j] = 0;
                j = next(nums, j);
            }
        }
        return false;
    }

    int next(vector<int>& nums, int i) {
        int n = nums.size();
        return (i + nums[i] % n + n) % n;
    }
};
```

#### Go

```go
func circularArrayLoop(nums []int) bool {
	for i, num := range nums {
		if num == 0 {
			continue
		}
		slow, fast := i, next(nums, i)
		for nums[slow]*nums[fast] > 0 && nums[slow]*nums[next(nums, fast)] > 0 {
			if slow == fast {
				if slow != next(nums, slow) {
					return true
				}
				break
			}
			slow, fast = next(nums, slow), next(nums, next(nums, fast))
		}
		j := i
		for nums[j]*nums[next(nums, j)] > 0 {
			nums[j] = 0
			j = next(nums, j)
		}
	}
	return false
}

func next(nums []int, i int) int {
	n := len(nums)
	return (i + nums[i]%n + n) % n
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [458. 可怜的小猪](https://leetcode.cn/problems/poor-pigs){#458}

{{< tabs "458" >}}

{{% tab "python" %}}
```python
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        base = minutesToTest // minutesToDie + 1
        res, p = 0, 1
        while p < buckets:
            p *= base
            res += 1
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        int res = 0;
        for (int p = 1; p < buckets; p *= base) {
            ++res;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        int res = 0;
        for (int p = 1; p < buckets; p *= base) ++res;
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
	base := minutesToTest/minutesToDie + 1
	res := 0
	for p := 1; p < buckets; p *= base {
		res++
	}
	return res
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有<code> buckets</code> 桶液体，其中 <strong>正好有一桶</strong>&nbsp;含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否会死进行判断。不幸的是，你只有&nbsp;<code>minutesToTest</code> 分钟时间来确定哪桶液体是有毒的。</p>

<p>喂猪的规则如下：</p>

<ol>
	<li>选择若干活猪进行喂养</li>
	<li>可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。</li>
	<li>小猪喝完水后，必须有 <code>minutesToDie</code> 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。</li>
	<li>过了 <code>minutesToDie</code> 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。</li>
	<li>重复这一过程，直到时间用完。</li>
</ol>

<p>给你桶的数目 <code>buckets</code> ，<code>minutesToDie</code> 和 <code>minutesToTest</code> ，返回&nbsp;<em>在规定时间内判断哪个桶有毒所需的 <strong>最小</strong> 猪数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>buckets = 1000, minutesToDie = 15, minutesToTest = 60
<strong>输出：</strong>5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>buckets = 4, minutesToDie = 15, minutesToTest = 15
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>buckets = 4, minutesToDie = 15, minutesToTest = 30
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= buckets &lt;= 1000</code></li>
	<li><code>1 &lt;=&nbsp;minutesToDie &lt;=&nbsp;minutesToTest &lt;= 100</code></li>
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
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        base = minutesToTest // minutesToDie + 1
        res, p = 0, 1
        while p < buckets:
            p *= base
            res += 1
        return res
```

#### Java

```java
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        int res = 0;
        for (int p = 1; p < buckets; p *= base) {
            ++res;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        int res = 0;
        for (int p = 1; p < buckets; p *= base) ++res;
        return res;
    }
};
```

#### Go

```go
func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
	base := minutesToTest/minutesToDie + 1
	res := 0
	for p := 1; p < buckets; p *= base {
		res++
	}
	return res
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [459. 重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern){#459}

{{< tabs "459" >}}

{{% tab "python" %}}
```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return (s + s).index(s, 1) < len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String str = s + s;
        return str.substring(1, str.length() - 1).contains(s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repeatedSubstringPattern(s string) bool {
	return strings.Index(s[1:]+s, s) < len(s)-1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repeatedSubstringPattern(s: string): boolean {
    return (s + s).slice(1, (s.length << 1) - 1).includes(s);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        (s.clone() + &s)[1..s.len() * 2 - 1].contains(&s)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个非空的字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，检查是否可以通过由它的一个子串重复多次构成。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abab"
<strong>输出:</strong> true
<strong>解释:</strong> 可由子串 "ab" 重复两次构成。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "aba"
<strong>输出:</strong> false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "abcabcabcabc"
<strong>输出:</strong> true
<strong>解释:</strong> 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双倍字符串

若长度为 $n$ 的字符串 $s$ 由 $m$ 个重复子串组成，将 $s$ 拼接在自身上，得到字符串 $ss$，长度为 $2n$，此时若从下标 $1$ 开始查找 $s$，那么查找到的下标一定小于 $s$ 的长度。

若长度为 $n$ 的字符串 $s$ 不由重复子串组成，将 $s$ 拼接在自身上，得到字符串 $ss$，长度为 $2n$，此时若从下标 $1$ 开始查找 $s$，那么查找到的下标一定等于 $s$ 的长度。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return (s + s).index(s, 1) < len(s)
```

#### Java

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String str = s + s;
        return str.substring(1, str.length() - 1).contains(s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();
    }
};
```

#### Go

```go
func repeatedSubstringPattern(s string) bool {
	return strings.Index(s[1:]+s, s) < len(s)-1
}
```

#### TypeScript

```ts
function repeatedSubstringPattern(s: string): boolean {
    return (s + s).slice(1, (s.length << 1) - 1).includes(s);
}
```

#### Rust

```rust
impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        (s.clone() + &s)[1..s.len() * 2 - 1].contains(&s)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
