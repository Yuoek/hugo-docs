---
title: "1080_根到叶路径上的不足节点"
date: 2025-10-08T18:36:50+08:00
weight: 9
tags: [二叉树, 单调栈, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 树, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [1080_根到叶路径上的不足节点](#1080)
#### [树](#1080)
#### [深度优先搜索](#1080)
#### [二叉树](#1080)
### [1081_不同字符的最小子序列](#1081)
#### [栈](#1081)
#### [贪心](#1081)
#### [字符串](#1081)
#### [单调栈](#1081)
### [1082_销售分析 I 🔒](#1082)
#### [数据库](#1082)
### [1083_销售分析 II 🔒](#1083)
#### [数据库](#1083)
### [1084_销售分析 III](#1084)
#### [数据库](#1084)
### [1085_最小元素各数位之和 🔒](#1085)
#### [数组](#1085)
#### [数学](#1085)
### [1086_前五科的均分 🔒](#1086)
#### [数组](#1086)
#### [哈希表](#1086)
#### [排序](#1086)
#### [堆（优先队列）](#1086)
### [1087_花括号展开 🔒](#1087)
#### [广度优先搜索](#1087)
#### [字符串](#1087)
#### [回溯](#1087)
### [1088_易混淆数 II 🔒](#1088)
#### [数学](#1088)
#### [回溯](#1088)
### [1089_复写零](#1089)
#### [数组](#1089)
#### [双指针](#1089)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1080_根到叶路径上的不足节点
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1081_不同字符的最小子序列
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 单调栈
---
### 1082_销售分析 I 🔒
___
#### 数据库
---
### 1083_销售分析 II 🔒
___
#### 数据库
---
### 1084_销售分析 III
___
#### 数据库
---
### 1085_最小元素各数位之和 🔒
___
#### 数组
___
#### 数学
---
### 1086_前五科的均分 🔒
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 堆（优先队列）
---
### 1087_花括号展开 🔒
___
#### 广度优先搜索
___
#### 字符串
___
#### 回溯
---
### 1088_易混淆数 II 🔒
___
#### 数学
___
#### 回溯
---
### 1089_复写零
___
#### 数组
___
#### 双指针
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 单调栈 | 双指针 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 树 | 深度优先搜索 |
| 贪心 |  |  |

# [1080. 根到叶路径上的不足节点](https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths){#1080}

{{< tabs "1080" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sufficientSubset(
        self, root: Optional[TreeNode], limit: int
    ) -> Optional[TreeNode]:
        if root is None:
            return None
        limit -= root.val
        if root.left is None and root.right is None:
            return None if limit > 0 else root
        root.left = self.sufficientSubset(root.left, limit)
        root.right = self.sufficientSubset(root.right, limit)
        return None if root.left is None and root.right is None else root
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
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if (root == null) {
            return null;
        }
        limit -= root.val;
        if (root.left == null && root.right == null) {
            return limit > 0 ? null : root;
        }
        root.left = sufficientSubset(root.left, limit);
        root.right = sufficientSubset(root.right, limit);
        return root.left == null && root.right == null ? null : root;
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) {
            return nullptr;
        }
        limit -= root->val;
        if (!root->left && !root->right) {
            return limit > 0 ? nullptr : root;
        }
        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);
        return !root->left && !root->right ? nullptr : root;
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
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
	if root == nil {
		return nil
	}

	limit -= root.Val
	if root.Left == nil && root.Right == nil {
		if limit > 0 {
			return nil
		}
		return root
	}

	root.Left = sufficientSubset(root.Left, limit)
	root.Right = sufficientSubset(root.Right, limit)

	if root.Left == nil && root.Right == nil {
		return nil
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

function sufficientSubset(root: TreeNode | null, limit: number): TreeNode | null {
    if (root === null) {
        return null;
    }
    limit -= root.val;
    if (root.left === null && root.right === null) {
        return limit > 0 ? null : root;
    }
    root.left = sufficientSubset(root.left, limit);
    root.right = sufficientSubset(root.right, limit);
    return root.left === null && root.right === null ? null : root;
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
 * @param {number} limit
 * @return {TreeNode}
 */
var sufficientSubset = function (root, limit) {
    if (root === null) {
        return null;
    }
    limit -= root.val;
    if (root.left === null && root.right === null) {
        return limit > 0 ? null : root;
    }
    root.left = sufficientSubset(root.left, limit);
    root.right = sufficientSubset(root.right, limit);
    return root.left === null && root.right === null ? null : root;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你二叉树的根节点 <code>root</code> 和一个整数 <code>limit</code> ，请你同时删除树中所有 <strong>不足节点 </strong>，并返回最终二叉树的根节点。</p>

<p>假如通过节点 <code>node</code> 的每种可能的 “根-叶” 路径上值的总和全都小于给定的 <code>limit</code>，则该节点被称之为<strong> 不足节点 </strong>，需要被删除。</p>

<p><strong>叶子节点</strong>，就是没有子节点的节点。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1080.Insufficient%20Nodes%20in%20Root%20to%20Leaf%20Paths/images/insufficient-11.png" style="width: 500px; height: 207px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
<strong>输出：</strong>[1,2,3,4,null,null,7,8,9,null,14]
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1080.Insufficient%20Nodes%20in%20Root%20to%20Leaf%20Paths/images/insufficient-3.png" style="width: 400px; height: 274px;" />
<pre>
<strong>输入：</strong>root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
<strong>输出：</strong>[5,4,8,11,null,17,4,7,null,null,null,5]
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1080.Insufficient%20Nodes%20in%20Root%20to%20Leaf%20Paths/images/screen-shot-2019-06-11-at-83301-pm.png" style="width: 250px; height: 199px;" />
<pre>
<strong>输入：</strong>root = [1,2,-3,-5,null,4,null], limit = -1
<strong>输出：</strong>[1,null,-3,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 5000]</code> 内</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= limit &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们递归遍历整棵树，对于当前遍历到的节点 $root$：

如果 $root$ 为空，那么返回空；否则，我们将 $limit$ 减去当前节点的值，即 $limit = limit - root.val$，然后继续执行下述步骤。

如果 $root$ 为叶子节点（即 $root$ 的左右子节点都为空），说明我们已经走完了一条从根节点到叶子节点的路径。如果此时 $limit \gt 0$，说明该路径上所有节点的值的和小于 $limit$，我们返回空节点，表示删除；否则，说明该路径上所有节点的值的和大于等于 $limit$，我们返回 $root$。

如果 $root$ 不是叶子节点，那么我们递归调用函数 $sufficientSubset$，对 $root$ 的左右子节点分别进行处理，并将返回值分别赋值给 $root$ 的左右子节点。

如果 $root$ 的左右子节点在经过递归调用后变成了空节点，那么说明 $root$ 的左右子树中所有从根节点到叶子节点的路径上所有节点的值的和都小于 $limit$，因此我们返回空节点，表示删除 $root$；否则，说明 $root$ 的左右子树中存在从根节点到叶子节点上所有节点值的和大于等于 $limit$ 的路径，因此我们返回 $root$。

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
    def sufficientSubset(
        self, root: Optional[TreeNode], limit: int
    ) -> Optional[TreeNode]:
        if root is None:
            return None
        limit -= root.val
        if root.left is None and root.right is None:
            return None if limit > 0 else root
        root.left = self.sufficientSubset(root.left, limit)
        root.right = self.sufficientSubset(root.right, limit)
        return None if root.left is None and root.right is None else root
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
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if (root == null) {
            return null;
        }
        limit -= root.val;
        if (root.left == null && root.right == null) {
            return limit > 0 ? null : root;
        }
        root.left = sufficientSubset(root.left, limit);
        root.right = sufficientSubset(root.right, limit);
        return root.left == null && root.right == null ? null : root;
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) {
            return nullptr;
        }
        limit -= root->val;
        if (!root->left && !root->right) {
            return limit > 0 ? nullptr : root;
        }
        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);
        return !root->left && !root->right ? nullptr : root;
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
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
	if root == nil {
		return nil
	}

	limit -= root.Val
	if root.Left == nil && root.Right == nil {
		if limit > 0 {
			return nil
		}
		return root
	}

	root.Left = sufficientSubset(root.Left, limit)
	root.Right = sufficientSubset(root.Right, limit)

	if root.Left == nil && root.Right == nil {
		return nil
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

function sufficientSubset(root: TreeNode | null, limit: number): TreeNode | null {
    if (root === null) {
        return null;
    }
    limit -= root.val;
    if (root.left === null && root.right === null) {
        return limit > 0 ? null : root;
    }
    root.left = sufficientSubset(root.left, limit);
    root.right = sufficientSubset(root.right, limit);
    return root.left === null && root.right === null ? null : root;
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
 * @param {number} limit
 * @return {TreeNode}
 */
var sufficientSubset = function (root, limit) {
    if (root === null) {
        return null;
    }
    limit -= root.val;
    if (root.left === null && root.right === null) {
        return limit > 0 ? null : root;
    }
    root.left = sufficientSubset(root.left, limit);
    root.right = sufficientSubset(root.right, limit);
    return root.left === null && root.right === null ? null : root;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters){#1081}

{{< tabs "1081" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        stk = []
        vis = set()
        for i, c in enumerate(s):
            if c in vis:
                continue
            while stk and stk[-1] > c and last[stk[-1]] > i:
                vis.remove(stk.pop())
            stk.append(c)
            vis.add(c)
        return "".join(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String smallestSubsequence(String s) {
        int n = s.length();
        int[] last = new int[26];
        for (int i = 0; i < n; ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        Deque<Character> stk = new ArrayDeque<>();
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (((mask >> (c - 'a')) & 1) == 1) {
                continue;
            }
            while (!stk.isEmpty() && stk.peek() > c && last[stk.peek() - 'a'] > i) {
                mask ^= 1 << (stk.pop() - 'a');
            }
            stk.push(c);
            mask |= 1 << (c - 'a');
        }
        StringBuilder ans = new StringBuilder();
        for (char c : stk) {
            ans.append(c);
        }
        return ans.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        int last[26] = {0};
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        string ans;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if ((mask >> (c - 'a')) & 1) {
                continue;
            }
            while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
                mask ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(c);
            mask |= 1 << (c - 'a');
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestSubsequence(s string) string {
	last := make([]int, 26)
	for i, c := range s {
		last[c-'a'] = i
	}
	stk := []rune{}
	vis := make([]bool, 128)
	for i, c := range s {
		if vis[c] {
			continue
		}
		for len(stk) > 0 && stk[len(stk)-1] > c && last[stk[len(stk)-1]-'a'] > i {
			vis[stk[len(stk)-1]] = false
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, c)
		vis[c] = true
	}
	return string(stk)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestSubsequence(s: string): string {
    const f = (c: string): number => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const last: number[] = new Array(26).fill(0);
    for (const [i, c] of [...s].entries()) {
        last[f(c)] = i;
    }
    const stk: string[] = [];
    let mask = 0;
    for (const [i, c] of [...s].entries()) {
        const x = f(c);
        if ((mask >> x) & 1) {
            continue;
        }
        while (stk.length && stk[stk.length - 1] > c && last[f(stk[stk.length - 1])] > i) {
            mask ^= 1 << f(stk.pop()!);
        }
        stk.push(c);
        mask |= 1 << x;
    }
    return stk.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>返回 <code>s</code> 字典序最小的<span data-keyword="subsequence-array">子序列</span>，该子序列包含 <code>s</code> 的所有不同字符，且只包含一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>s = "bcabc"</code>
<strong>输出<code>：</code></strong><code>"abc"</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong><code>s = "cbacdcbc"</code>
<strong>输出：</strong><code>"acdb"</code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>该题与 316 <a href="https://leetcode.cn/problems/remove-duplicate-letters/">https://leetcode.cn/problems/remove-duplicate-letters/</a> 相同</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们用一个数组 $last$ 记录字符串 $s$ 每个字符最后一次出现的位置，用栈来保存结果字符串，用一个数组 $vis$ 或者一个整型变量 $mask$ 记录当前字符是否在栈中。

遍历字符串 $s$，对于每个字符 $c$，如果 $c$ 不在栈中，我们就需要判断栈顶元素是否大于 $c$，如果大于 $c$，且栈顶元素在后面还会出现，我们就将栈顶元素弹出，将 $c$ 压入栈中。

最后将栈中元素拼接成字符串作为结果返回。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        stk = []
        vis = set()
        for i, c in enumerate(s):
            if c in vis:
                continue
            while stk and stk[-1] > c and last[stk[-1]] > i:
                vis.remove(stk.pop())
            stk.append(c)
            vis.add(c)
        return "".join(stk)
```

#### Java

```java
class Solution {
    public String smallestSubsequence(String text) {
        int[] cnt = new int[26];
        for (char c : text.toCharArray()) {
            ++cnt[c - 'a'];
        }
        boolean[] vis = new boolean[26];
        char[] cs = new char[text.length()];
        int top = -1;
        for (char c : text.toCharArray()) {
            --cnt[c - 'a'];
            if (!vis[c - 'a']) {
                while (top >= 0 && c < cs[top] && cnt[cs[top] - 'a'] > 0) {
                    vis[cs[top--] - 'a'] = false;
                }
                cs[++top] = c;
                vis[c - 'a'] = true;
            }
        }
        return String.valueOf(cs, 0, top + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        int last[26] = {0};
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        string ans;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if ((mask >> (c - 'a')) & 1) {
                continue;
            }
            while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
                mask ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(c);
            mask |= 1 << (c - 'a');
        }
        return ans;
    }
};
```

#### Go

```go
func smallestSubsequence(s string) string {
	last := make([]int, 26)
	for i, c := range s {
		last[c-'a'] = i
	}
	stk := []rune{}
	vis := make([]bool, 128)
	for i, c := range s {
		if vis[c] {
			continue
		}
		for len(stk) > 0 && stk[len(stk)-1] > c && last[stk[len(stk)-1]-'a'] > i {
			vis[stk[len(stk)-1]] = false
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, c)
		vis[c] = true
	}
	return string(stk)
}
```

#### TypeScript

```ts
function smallestSubsequence(s: string): string {
    const f = (c: string): number => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const last: number[] = new Array(26).fill(0);
    for (const [i, c] of [...s].entries()) {
        last[f(c)] = i;
    }
    const stk: string[] = [];
    let mask = 0;
    for (const [i, c] of [...s].entries()) {
        const x = f(c);
        if ((mask >> x) & 1) {
            continue;
        }
        while (stk.length && stk[stk.length - 1] > c && last[f(stk[stk.length - 1])] > i) {
            mask ^= 1 << f(stk.pop()!);
        }
        stk.push(c);
        mask |= 1 << x;
    }
    return stk.join('');
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
    public String smallestSubsequence(String s) {
        int n = s.length();
        int[] last = new int[26];
        for (int i = 0; i < n; ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        Deque<Character> stk = new ArrayDeque<>();
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (((mask >> (c - 'a')) & 1) == 1) {
                continue;
            }
            while (!stk.isEmpty() && stk.peek() > c && last[stk.peek() - 'a'] > i) {
                mask ^= 1 << (stk.pop() - 'a');
            }
            stk.push(c);
            mask |= 1 << (c - 'a');
        }
        StringBuilder ans = new StringBuilder();
        for (char c : stk) {
            ans.append(c);
        }
        return ans.reverse().toString();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1082. 销售分析 I 🔒](https://leetcode.cn/problems/sales-analysis-i){#1082}

{{< tabs "1082" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            seller_id,
            SUM(price) AS tot,
            RANK() OVER (ORDER BY SUM(price) DESC) AS rk
        FROM Sales
        GROUP BY seller_id
    )
SELECT seller_id
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>产品表：<code>Product</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
product_id 是这个表的主键(具有唯一值的列)。
该表的每一行显示每个产品的名称和价格。
</pre>

<p>销售表：<code>Sales</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+------ ------+---------+
这个表它可以有重复的行。 
product_id 是 Product 表的外键(reference 列)。
该表的每一行包含关于一个销售的一些信息。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出总销售额最高的销售者，如果有并列的，就都展示出来。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Product 表：
+------------+--------------+------------+
| product_id | product_name | unit_price |
+------------+--------------+------------+
| 1          | S8           | 1000       |
| 2          | G4           | 800        |
| 3          | iPhone       | 1400       |
+------------+--------------+------------+
<code>Sales </code>表：
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 2          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 4        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
<strong>输出：</strong>
+-------------+
| seller_id   |
+-------------+
| 1           |
| 3           |
+-------------+
<strong>解释：</strong>Id 为 1 和 3 的销售者，销售总金额都为最高的 2800。</pre>

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
SELECT seller_id
FROM Sales
GROUP BY seller_id
HAVING
    SUM(price) >= ALL(
        SELECT SUM(price)
        FROM Sales
        GROUP BY seller_id
    );
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
            seller_id,
            SUM(price) AS tot,
            RANK() OVER (ORDER BY SUM(price) DESC) AS rk
        FROM Sales
        GROUP BY seller_id
    )
SELECT seller_id
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1083. 销售分析 II 🔒](https://leetcode.cn/problems/sales-analysis-ii){#1083}

{{< tabs "1083" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT buyer_id
FROM
    Sales
    JOIN Product USING (product_id)
GROUP BY 1
HAVING SUM(product_name = 'S8') > 0 AND SUM(product_name = 'iPhone') = 0;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Product</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
Product_id 是该表的主键(具有唯一值的列)。
该表的每一行表示每种产品的名称和价格。
</pre>

<p>表：<code>Sales</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+------ ------+---------+
这个表可能有重复的行。
product_id 是 Product 表的外键(reference 列)。
buyer_id 永远不会是 NULL。
sale_date 永远不会是 NULL。
该表的每一行都包含一次销售的一些信息。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，报告那些买了 <em>S8</em> 而没有买 <em>iPhone</em> 的 <strong>买家</strong>。注意，<em>S8</em> 和 <em>iPhone</em> 是 <code>Product</code> 表中显示的产品。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Product table:
+------------+--------------+------------+
| product_id | product_name | unit_price |
+------------+--------------+------------+
| 1          | S8           | 1000       |
| 2          | G4           | 800        |
| 3          | iPhone       | 1400       |
+------------+--------------+------------+
<code>Sales </code>table:
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 1          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 3        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
<strong>输出：</strong>
+-------------+
| buyer_id    |
+-------------+
| 1           |
+-------------+
解释：
id 为 1 的买家购买了一部 S8，但是却没有购买 iPhone，而 id 为 3 的买家却同时购买了这 2 部手机。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：JOIN + GROUP BY + HAVING

我们先将 `Sales` 表和 `Product` 表连接起来，然后根据 `buyer_id` 分组，最后用 `HAVING` 子句筛选出购买了 S8 却没有购买 iPhone 的买家。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT buyer_id
FROM
    Sales
    JOIN Product USING (product_id)
GROUP BY 1
HAVING SUM(product_name = 'S8') > 0 AND SUM(product_name = 'iPhone') = 0;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1084. 销售分析 III](https://leetcode.cn/problems/sales-analysis-iii){#1084}

{{< tabs "1084" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT product_id, product_name
FROM
    Sales
    JOIN Product USING (product_id)
GROUP BY 1
HAVING COUNT(1) = SUM(sale_date BETWEEN '2019-01-01' AND '2019-03-31');
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Product</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
product_id 是该表的主键（具有唯一值的列）。
该表的每一行显示每个产品的名称和价格。
</pre>

<p>表：<code>Sales</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+------ ------+---------+
这个表可能有重复的行。
product_id 是 Product 表的外键（reference 列）。
该表的每一行包含关于一个销售的一些信息。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告&nbsp;<code>2019年春季</code>&nbsp;才售出的产品。即&nbsp;<strong>仅&nbsp;</strong>在&nbsp;<code><strong>2019-01-01</strong></code><strong>&nbsp;</strong>（含）至&nbsp;<code><strong>2019-03-31</strong></code><strong>&nbsp;</strong>（含）之间出售的商品。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Product table:
+------------+--------------+------------+
| product_id | product_name | unit_price |
+------------+--------------+------------+
| 1          | S8           | 1000       |
| 2          | G4           | 800        |
| 3          | iPhone       | 1400       |
+------------+--------------+------------+
<code>Sales </code>table:
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 2          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 4        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
<strong>输出：</strong>
+-------------+--------------+
| product_id  | product_name |
+-------------+--------------+
| 1           | S8           |
+-------------+--------------+
<strong>解释:</strong>
id 为 1 的产品仅在 2019 年春季销售。
id 为 2 的产品在 2019 年春季销售，但也在 2019 年春季之后销售。
id 为 3 的产品在 2019 年春季之后销售。
我们只返回 id 为 1 的产品，因为它是 2019 年春季才销售的产品。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：JOIN + GROUP BY + HAVING

我们可以通过 `JOIN` 将 `Sales` 表和 `Product` 表连接起来，然后通过 `GROUP BY` 和 `HAVING` 来筛选出符合条件的产品。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT product_id, product_name
FROM
    Sales
    JOIN Product USING (product_id)
GROUP BY 1
HAVING COUNT(1) = SUM(sale_date BETWEEN '2019-01-01' AND '2019-03-31');
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1085. 最小元素各数位之和 🔒](https://leetcode.cn/problems/sum-of-digits-in-the-minimum-number){#1085}

{{< tabs "1085" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfDigits(self, nums: List[int]) -> int:
        x = min(nums)
        s = 0
        while x:
            s += x % 10
            x //= 10
        return s & 1 ^ 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfDigits(int[] nums) {
        int x = 100;
        for (int v : nums) {
            x = Math.min(x, v);
        }
        int s = 0;
        for (; x > 0; x /= 10) {
            s += x % 10;
        }
        return s & 1 ^ 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int s = 0;
        for (; x > 0; x /= 10) {
            s += x % 10;
        }
        return s & 1 ^ 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfDigits(nums []int) int {
	s := 0
	for x := slices.Min(nums); x > 0; x /= 10 {
		s += x % 10
	}
	return s&1 ^ 1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数的数组 <code>A</code>。</p>

<p>然后计算 <code>S</code>，使其等于数组 <code>A</code> 当中最小的那个元素各个数位上数字之和。</p>

<p>最后，假如 <code>S</code> 所得计算结果是 <strong>奇数 </strong>，返回 0 ；否则请返回 1。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>[34,23,1,24,75,33,54,8]
<strong>输出：</strong>0
<strong>解释：</strong>
最小元素为 1 ，该元素各个数位上的数字之和 S = 1 ，是奇数所以答案为 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[99,77,33,66,55]
<strong>输出：</strong>1
<strong>解释：</strong>
最小元素为 33 ，该元素各个数位上的数字之和 S = 3 + 3 = 6 ，是偶数所以答案为 1 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= A.length <= 100</code></li>
	<li><code>1 <= A[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先找到数组中的最小值，记为 $x$。然后计算 $x$ 的各个数位上的数字之和，记为 $s$。最后判断 $s$ 是否为奇数，若是则返回 $0$，否则返回 $1$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfDigits(self, nums: List[int]) -> int:
        x = min(nums)
        s = 0
        while x:
            s += x % 10
            x //= 10
        return s & 1 ^ 1
```

#### Java

```java
class Solution {
    public int sumOfDigits(int[] nums) {
        int x = 100;
        for (int v : nums) {
            x = Math.min(x, v);
        }
        int s = 0;
        for (; x > 0; x /= 10) {
            s += x % 10;
        }
        return s & 1 ^ 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int s = 0;
        for (; x > 0; x /= 10) {
            s += x % 10;
        }
        return s & 1 ^ 1;
    }
};
```

#### Go

```go
func sumOfDigits(nums []int) int {
	s := 0
	for x := slices.Min(nums); x > 0; x /= 10 {
		s += x % 10
	}
	return s&1 ^ 1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1086. 前五科的均分 🔒](https://leetcode.cn/problems/high-five){#1086}

{{< tabs "1086" >}}

{{% tab "python" %}}
```python
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        d = defaultdict(list)
        m = 0
        for i, x in items:
            d[i].append(x)
            m = max(m, i)
        ans = []
        for i in range(1, m + 1):
            if xs := d[i]:
                avg = sum(nlargest(5, xs)) // 5
                ans.append([i, avg])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] highFive(int[][] items) {
        int size = 0;
        PriorityQueue[] s = new PriorityQueue[101];
        int n = 5;
        for (int[] item : items) {
            int i = item[0], score = item[1];
            if (s[i] == null) {
                ++size;
                s[i] = new PriorityQueue<>(n);
            }
            s[i].offer(score);
            if (s[i].size() > n) {
                s[i].poll();
            }
        }
        int[][] res = new int[size][2];
        int j = 0;
        for (int i = 0; i < 101; ++i) {
            if (s[i] == null) {
                continue;
            }
            int avg = sum(s[i]) / n;
            res[j][0] = i;
            res[j++][1] = avg;
        }
        return res;
    }

    private int sum(PriorityQueue<Integer> q) {
        int s = 0;
        while (!q.isEmpty()) {
            s += q.poll();
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<int> d[1001];
        for (auto& item : items) {
            int i = item[0], x = item[1];
            d[i].push_back(x);
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= 1000; ++i) {
            if (!d[i].empty()) {
                sort(d[i].begin(), d[i].end(), greater<int>());
                int s = 0;
                for (int j = 0; j < 5; ++j) {
                    s += d[i][j];
                }
                ans.push_back({i, s / 5});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func highFive(items [][]int) (ans [][]int) {
	d := make([][]int, 1001)
	for _, item := range items {
		i, x := item[0], item[1]
		d[i] = append(d[i], x)
	}
	for i := 1; i <= 1000; i++ {
		if len(d[i]) > 0 {
			sort.Ints(d[i])
			s := 0
			for j := len(d[i]) - 1; j >= len(d[i])-5; j-- {
				s += d[i][j]
			}
			ans = append(ans, []int{i, s / 5})
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function highFive(items: number[][]): number[][] {
    const d: number[][] = Array(1001)
        .fill(0)
        .map(() => Array(0));
    for (const [i, x] of items) {
        d[i].push(x);
    }
    const ans: number[][] = [];
    for (let i = 1; i <= 1000; ++i) {
        if (d[i].length > 0) {
            d[i].sort((a, b) => b - a);
            const s = d[i].slice(0, 5).reduce((a, b) => a + b);
            ans.push([i, Math.floor(s / 5)]);
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

<p>给你一个不同学生的分数列表 <code>items</code>，其中 <code>items[i] = [ID<sub>i</sub>, score<sub>i</sub>]</code> 表示 <code>ID<sub>i</sub></code> 的学生的一科分数，你需要计算每个学生 <strong>最高的五科 </strong>成绩的 <strong>平均分</strong>。</p>

<p>返回答案 <code>result</code> 以数对数组形式给出<em>，</em>其中<em> </em><code>result[j] = [ID<sub>j</sub>, topFiveAverage<sub>j</sub>]</code><em> </em>表示<em> </em><code>ID<sub>j</sub></code><em> </em>的学生和他 <strong>最高的五科 </strong>成绩的 <strong>平均分</strong><em>。</em><code>result</code><em> </em>需要按<em> </em><code>ID<sub>j</sub></code><em>  </em>递增的 <strong>顺序排列</strong> 。</p>

<p>学生 <strong>最高的五科 </strong>成绩的 <strong>平均分 </strong>的计算方法是将最高的五科分数相加，然后用 <strong>整数除法</strong> 除以 5 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
<strong>输出：</strong>[[1,87],[2,88]]
<strong>解释：</strong>
ID = 1 的学生分数为 91、92、60、65、87 和 100 。前五科的平均分 (100 + 92 + 91 + 87 + 65) / 5 = 87
ID = 2 的学生分数为 93、97、77、100 和 76 。前五科的平均分 (100 + 97 + 93 + 77 + 76) / 5 = 88.6，但是由于使用整数除法，结果转换为 88
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
<strong>输出：</strong>[[1,100],[7,100]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= items.length <= 1000</code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>1 <= ID<sub>i</sub> <= 1000</code></li>
	<li><code>0 <= score<sub>i</sub> <= 100</code></li>
	<li>对于每个 <code>ID<sub>i</sub></code>，<strong>至少</strong> 存在五个分数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先用一个哈希表或数组 $d$ 记录每个学生的分数列表，然后从小到大遍历学生的编号，对于每个学生，我们将他的分数列表排序，然后取最高的五个分数求平均值即可。

时间复杂度 $O(n \log n)$，空间复杂度 $O(n)$。其中 $n$ 是学生的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        d = defaultdict(list)
        m = 0
        for i, x in items:
            d[i].append(x)
            m = max(m, i)
        ans = []
        for i in range(1, m + 1):
            if xs := d[i]:
                avg = sum(nlargest(5, xs)) // 5
                ans.append([i, avg])
        return ans
```

#### Java

```java
class Solution {
    public int[][] highFive(int[][] items) {
        int size = 0;
        PriorityQueue[] s = new PriorityQueue[101];
        int n = 5;
        for (int[] item : items) {
            int i = item[0], score = item[1];
            if (s[i] == null) {
                ++size;
                s[i] = new PriorityQueue<>(n);
            }
            s[i].offer(score);
            if (s[i].size() > n) {
                s[i].poll();
            }
        }
        int[][] res = new int[size][2];
        int j = 0;
        for (int i = 0; i < 101; ++i) {
            if (s[i] == null) {
                continue;
            }
            int avg = sum(s[i]) / n;
            res[j][0] = i;
            res[j++][1] = avg;
        }
        return res;
    }

    private int sum(PriorityQueue<Integer> q) {
        int s = 0;
        while (!q.isEmpty()) {
            s += q.poll();
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<int> d[1001];
        for (auto& item : items) {
            int i = item[0], x = item[1];
            d[i].push_back(x);
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= 1000; ++i) {
            if (!d[i].empty()) {
                sort(d[i].begin(), d[i].end(), greater<int>());
                int s = 0;
                for (int j = 0; j < 5; ++j) {
                    s += d[i][j];
                }
                ans.push_back({i, s / 5});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func highFive(items [][]int) (ans [][]int) {
	d := make([][]int, 1001)
	for _, item := range items {
		i, x := item[0], item[1]
		d[i] = append(d[i], x)
	}
	for i := 1; i <= 1000; i++ {
		if len(d[i]) > 0 {
			sort.Ints(d[i])
			s := 0
			for j := len(d[i]) - 1; j >= len(d[i])-5; j-- {
				s += d[i][j]
			}
			ans = append(ans, []int{i, s / 5})
		}
	}
	return ans
}
```

#### TypeScript

```ts
function highFive(items: number[][]): number[][] {
    const d: number[][] = Array(1001)
        .fill(0)
        .map(() => Array(0));
    for (const [i, x] of items) {
        d[i].push(x);
    }
    const ans: number[][] = [];
    for (let i = 1; i <= 1000; ++i) {
        if (d[i].length > 0) {
            d[i].sort((a, b) => b - a);
            const s = d[i].slice(0, 5).reduce((a, b) => a + b);
            ans.push([i, Math.floor(s / 5)]);
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

# [1087. 花括号展开 🔒](https://leetcode.cn/problems/brace-expansion){#1087}

{{< tabs "1087" >}}

{{% tab "python" %}}
```python
class Solution:
    def expand(self, s: str) -> List[str]:
        def convert(s):
            if not s:
                return
            if s[0] == '{':
                j = s.find('}')
                items.append(s[1:j].split(','))
                convert(s[j + 1 :])
            else:
                j = s.find('{')
                if j != -1:
                    items.append(s[:j].split(','))
                    convert(s[j:])
                else:
                    items.append(s.split(','))

        def dfs(i, t):
            if i == len(items):
                ans.append(''.join(t))
                return
            for c in items[i]:
                t.append(c)
                dfs(i + 1, t)
                t.pop()

        items = []
        convert(s)
        ans = []
        dfs(0, [])
        ans.sort()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<String> ans;
    private List<String[]> items;

    public String[] expand(String s) {
        ans = new ArrayList<>();
        items = new ArrayList<>();
        convert(s);
        dfs(0, new ArrayList<>());
        Collections.sort(ans);
        return ans.toArray(new String[0]);
    }

    private void convert(String s) {
        if ("".equals(s)) {
            return;
        }
        if (s.charAt(0) == '{') {
            int j = s.indexOf("}");
            items.add(s.substring(1, j).split(","));
            convert(s.substring(j + 1));
        } else {
            int j = s.indexOf("{");
            if (j != -1) {
                items.add(s.substring(0, j).split(","));
                convert(s.substring(j));
            } else {
                items.add(s.split(","));
            }
        }
    }

    private void dfs(int i, List<String> t) {
        if (i == items.size()) {
            ans.add(String.join("", t));
            return;
        }
        for (String c : items.get(i)) {
            t.add(c);
            dfs(i + 1, t);
            t.remove(t.size() - 1);
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

<p>给定一个表示单词列表的字符串&nbsp;<code>s</code>&nbsp;。单词中的每个字母都有一个或多个选项。</p>

<ul>
	<li>如果有一个选项，则字母按原样表示。</li>
	<li>如果有多个选项，则用大括号分隔选项。例如,<meta charset="UTF-8" />&nbsp;&nbsp;<code>"{a,b,c}"</code>&nbsp; 表示选项<meta charset="UTF-8" />&nbsp;&nbsp;<code>["a", "b", "c"]</code>&nbsp; 。</li>
</ul>

<p>例如，如果<meta charset="UTF-8" />&nbsp;&nbsp;<code>s = "a{b,c}"</code>&nbsp; ，第一个字符总是 <code>'a'</code> ，但第二个字符可以是 <code>'b'</code> 或 <code>'c'</code> 。原来的列表是<meta charset="UTF-8" />&nbsp;<code>["ab", "ac"]</code>&nbsp;。</p>

<p>请你 <strong>按字典顺序</strong> ，返回所有以这种方式形成的单词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "{a,b}c{d,e}f"
<strong>输出：</strong>["acdf","acef","bcdf","bcef"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>["abcd"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= S.length &lt;= 50</code></li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;由括号 <code>'{}'</code>&nbsp;, <code>','</code> 和小写英文字母组成。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;保证是一个有效的输入。</li>
	<li>没有嵌套的大括号。</li>
	<li>在一对连续的左括号和右括号内的所有字符都是不同的。</li>
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
    def expand(self, s: str) -> List[str]:
        def convert(s):
            if not s:
                return
            if s[0] == '{':
                j = s.find('}')
                items.append(s[1:j].split(','))
                convert(s[j + 1 :])
            else:
                j = s.find('{')
                if j != -1:
                    items.append(s[:j].split(','))
                    convert(s[j:])
                else:
                    items.append(s.split(','))

        def dfs(i, t):
            if i == len(items):
                ans.append(''.join(t))
                return
            for c in items[i]:
                t.append(c)
                dfs(i + 1, t)
                t.pop()

        items = []
        convert(s)
        ans = []
        dfs(0, [])
        ans.sort()
        return ans
```

#### Java

```java
class Solution {
    private List<String> ans;
    private List<String[]> items;

    public String[] expand(String s) {
        ans = new ArrayList<>();
        items = new ArrayList<>();
        convert(s);
        dfs(0, new ArrayList<>());
        Collections.sort(ans);
        return ans.toArray(new String[0]);
    }

    private void convert(String s) {
        if ("".equals(s)) {
            return;
        }
        if (s.charAt(0) == '{') {
            int j = s.indexOf("}");
            items.add(s.substring(1, j).split(","));
            convert(s.substring(j + 1));
        } else {
            int j = s.indexOf("{");
            if (j != -1) {
                items.add(s.substring(0, j).split(","));
                convert(s.substring(j));
            } else {
                items.add(s.split(","));
            }
        }
    }

    private void dfs(int i, List<String> t) {
        if (i == items.size()) {
            ans.add(String.join("", t));
            return;
        }
        for (String c : items.get(i)) {
            t.add(c);
            dfs(i + 1, t);
            t.remove(t.size() - 1);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1088. 易混淆数 II 🔒](https://leetcode.cn/problems/confusing-number-ii){#1088}

{{< tabs "1088" >}}

{{% tab "python" %}}
```python
class Solution:
    def confusingNumberII(self, n: int) -> int:
        def check(x: int) -> bool:
            y, t = 0, x
            while t:
                t, v = divmod(t, 10)
                y = y * 10 + d[v]
            return x != y

        def dfs(pos: int, limit: bool, x: int) -> int:
            if pos >= len(s):
                return int(check(x))
            up = int(s[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if d[i] != -1:
                    ans += dfs(pos + 1, limit and i == up, x * 10 + i)
            return ans

        d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6]
        s = str(n)
        return dfs(0, True, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int[] d = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    private String s;

    public int confusingNumberII(int n) {
        s = String.valueOf(n);
        return dfs(0, 1, 0);
    }

    private int dfs(int pos, int limit, int x) {
        if (pos >= s.length()) {
            return check(x) ? 1 : 0;
        }
        int up = limit == 1 ? s.charAt(pos) - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (d[i] != -1) {
                ans += dfs(pos + 1, limit == 1 && i == up ? 1 : 0, x * 10 + i);
            }
        }
        return ans;
    }

    private boolean check(int x) {
        int y = 0;
        for (int t = x; t > 0; t /= 10) {
            int v = t % 10;
            y = y * 10 + d[v];
        }
        return x != y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int confusingNumberII(int n) {
        string s = to_string(n);
        int d[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        auto check = [&](int x) -> bool {
            int y = 0;
            for (int t = x; t; t /= 10) {
                int v = t % 10;
                y = y * 10 + d[v];
            }
            return x != y;
        };
        function<int(int, int, int)> dfs = [&](int pos, int limit, int x) -> int {
            if (pos >= s.size()) {
                return check(x);
            }
            int up = limit ? s[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                if (d[i] != -1) {
                    ans += dfs(pos + 1, limit && i == up, x * 10 + i);
                }
            }
            return ans;
        };
        return dfs(0, 1, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func confusingNumberII(n int) int {
	d := [10]int{0, 1, -1, -1, -1, -1, 9, -1, 8, 6}
	s := strconv.Itoa(n)
	check := func(x int) bool {
		y := 0
		for t := x; t > 0; t /= 10 {
			v := t % 10
			y = y*10 + d[v]
		}
		return x != y
	}
	var dfs func(pos int, limit bool, x int) int
	dfs = func(pos int, limit bool, x int) (ans int) {
		if pos >= len(s) {
			if check(x) {
				return 1
			}
			return 0
		}
		up := 9
		if limit {
			up = int(s[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			if d[i] != -1 {
				ans += dfs(pos+1, limit && i == up, x*10+i)
			}
		}
		return
	}
	return dfs(0, true, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function confusingNumberII(n: number): number {
    const s = n.toString();
    const d: number[] = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6];
    const check = (x: number) => {
        let y = 0;
        for (let t = x; t > 0; t = Math.floor(t / 10)) {
            const v = t % 10;
            y = y * 10 + d[v];
        }
        return x !== y;
    };
    const dfs = (pos: number, limit: boolean, x: number): number => {
        if (pos >= s.length) {
            return check(x) ? 1 : 0;
        }
        const up = limit ? parseInt(s[pos]) : 9;
        let ans = 0;
        for (let i = 0; i <= up; ++i) {
            if (d[i] !== -1) {
                ans += dfs(pos + 1, limit && i === up, x * 10 + i);
            }
        }
        return ans;
    };
    return dfs(0, true, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>易混淆数</strong>（Confusing Number）指的是一个数字在整体旋转 <code>180°</code> 以后，能够得到一个和原来&nbsp;<strong>不同&nbsp;</strong>的数，且 <strong>新数字的每一位都应该是有效的</strong>。</p>

<p>本题我们会将数字旋转 <code>180°</code> 来生成一个新的数字。</p>

<ul>
	<li>当 <code>0、1、6、8、9</code> 旋转 <code>180°</code> 以后，我们得到的新数字分别为&nbsp;0、1、9、8、6。</li>
	<li>当&nbsp;<code>2、3、4、5、7</code> 旋转 <code>180°</code> 后，是 <strong>无法</strong> 得到任何数字的。</li>
</ul>

<p>请注意，在旋转一个数字之后，我们可以忽略前导零。</p>

<ul>
	<li>例如，在旋转 <code>8000</code> 之后，我们有 <code>0008</code> ，它被认为只是 <code>8</code> 。</li>
</ul>

<p>给出正整数&nbsp;<code>n</code>，请你返回&nbsp;&nbsp;<em><code>[1, n]</code>&nbsp;范围内的 <strong>易混淆数</strong> 的数量&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 20
<strong>输出：</strong>6
<strong>解释：</strong>易混淆数为 [6,9,10,16,18,19]。
6 转换为 9
9 转换为 6
10 转换为 01 也就是 1
16 转换为 91
18 转换为 81
19 转换为 61
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 100
<strong>输出：</strong>19
<strong>解释：</strong>易混淆数为 [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

我们先将数字 $n$ 转成字符串 $s$。

接下来，我们定义一个函数 $check(x)$，用来判断 $x$ 在旋转 $180^\circ$ 之后是否变成了一个不同的数。如果 $x$ 在旋转 $180^\circ$ 之后变成了一个不同的数，那么我们就称 $x$ 是一个易混淆数。

然后，我们定义另一个函数 $dfs(pos, limit, x)$，用于搜索从高位到低位的每一位。其中：

-   参数 $pos$ 表示当前搜索到的位置，初始时为 $0$；
-   参数 $limit$ 表示当前搜索的数是否受到上界的限制，初始时为 $true$；
-   参数 $x$ 表示当前搜索的数，初始时为 $0$。

在 $dfs(pos, limit, x)$ 中，如果 $pos \geq len(s)$，那么我们就判断 $x$ 是否是一个易混淆数，如果是则返回 $1$，否则返回 $0$。

否则，我们计算出当前位置上的数字的上界 $up$，然后枚举当前位置上的数字 $i$，如果 $i$ 在旋转 $180^\circ$ 之后不是一个数字，那么我们就直接跳过这个数字。否则，我们将 $x$ 更新为 $x \times 10 + i$，并根据 $limit$ 的值决定下一步搜索的时候是否受到上界的限制，最后将答案返回。

最终的答案即为 $dfs(0, true, 0)$。

时间复杂度 $O(5^{\log_{10}n})$，空间复杂度 $O(\log_{10}n)$。其中 $5^{\log_{10}n}$ 表示 $n$ 的位数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def confusingNumberII(self, n: int) -> int:
        def check(x: int) -> bool:
            y, t = 0, x
            while t:
                t, v = divmod(t, 10)
                y = y * 10 + d[v]
            return x != y

        def dfs(pos: int, limit: bool, x: int) -> int:
            if pos >= len(s):
                return int(check(x))
            up = int(s[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if d[i] != -1:
                    ans += dfs(pos + 1, limit and i == up, x * 10 + i)
            return ans

        d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6]
        s = str(n)
        return dfs(0, True, 0)
```

#### Java

```java
class Solution {
    private final int[] d = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    private String s;

    public int confusingNumberII(int n) {
        s = String.valueOf(n);
        return dfs(0, 1, 0);
    }

    private int dfs(int pos, int limit, int x) {
        if (pos >= s.length()) {
            return check(x) ? 1 : 0;
        }
        int up = limit == 1 ? s.charAt(pos) - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (d[i] != -1) {
                ans += dfs(pos + 1, limit == 1 && i == up ? 1 : 0, x * 10 + i);
            }
        }
        return ans;
    }

    private boolean check(int x) {
        int y = 0;
        for (int t = x; t > 0; t /= 10) {
            int v = t % 10;
            y = y * 10 + d[v];
        }
        return x != y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int confusingNumberII(int n) {
        string s = to_string(n);
        int d[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        auto check = [&](int x) -> bool {
            int y = 0;
            for (int t = x; t; t /= 10) {
                int v = t % 10;
                y = y * 10 + d[v];
            }
            return x != y;
        };
        function<int(int, int, int)> dfs = [&](int pos, int limit, int x) -> int {
            if (pos >= s.size()) {
                return check(x);
            }
            int up = limit ? s[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                if (d[i] != -1) {
                    ans += dfs(pos + 1, limit && i == up, x * 10 + i);
                }
            }
            return ans;
        };
        return dfs(0, 1, 0);
    }
};
```

#### Go

```go
func confusingNumberII(n int) int {
	d := [10]int{0, 1, -1, -1, -1, -1, 9, -1, 8, 6}
	s := strconv.Itoa(n)
	check := func(x int) bool {
		y := 0
		for t := x; t > 0; t /= 10 {
			v := t % 10
			y = y*10 + d[v]
		}
		return x != y
	}
	var dfs func(pos int, limit bool, x int) int
	dfs = func(pos int, limit bool, x int) (ans int) {
		if pos >= len(s) {
			if check(x) {
				return 1
			}
			return 0
		}
		up := 9
		if limit {
			up = int(s[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			if d[i] != -1 {
				ans += dfs(pos+1, limit && i == up, x*10+i)
			}
		}
		return
	}
	return dfs(0, true, 0)
}
```

#### TypeScript

```ts
function confusingNumberII(n: number): number {
    const s = n.toString();
    const d: number[] = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6];
    const check = (x: number) => {
        let y = 0;
        for (let t = x; t > 0; t = Math.floor(t / 10)) {
            const v = t % 10;
            y = y * 10 + d[v];
        }
        return x !== y;
    };
    const dfs = (pos: number, limit: boolean, x: number): number => {
        if (pos >= s.length) {
            return check(x) ? 1 : 0;
        }
        const up = limit ? parseInt(s[pos]) : 9;
        let ans = 0;
        for (let i = 0; i <= up; ++i) {
            if (d[i] !== -1) {
                ans += dfs(pos + 1, limit && i === up, x * 10 + i);
            }
        }
        return ans;
    };
    return dfs(0, true, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1089. 复写零](https://leetcode.cn/problems/duplicate-zeros){#1089}

{{< tabs "1089" >}}

{{% tab "python" %}}
```python
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        n = len(arr)
        i, k = -1, 0
        while k < n:
            i += 1
            k += 1 if arr[i] else 2
        j = n - 1
        if k == n + 1:
            arr[j] = 0
            i, j = i - 1, j - 1
        while ~j:
            if arr[i] == 0:
                arr[j] = arr[j - 1] = arr[i]
                j -= 1
            else:
                arr[j] = arr[i]
            i, j = i - 1, j - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void duplicateZeros(int[] arr) {
        int n = arr.length;
        int i = -1, k = 0;
        while (k < n) {
            ++i;
            k += arr[i] > 0 ? 1 : 2;
        }
        int j = n - 1;
        if (k == n + 1) {
            arr[j--] = 0;
            --i;
        }
        while (j >= 0) {
            arr[j] = arr[i];
            if (arr[i] == 0) {
                arr[--j] = arr[i];
            }
            --i;
            --j;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = -1, k = 0;
        while (k < n) {
            ++i;
            k += arr[i] ? 1 : 2;
        }
        int j = n - 1;
        if (k == n + 1) {
            arr[j--] = 0;
            --i;
        }
        while (~j) {
            arr[j] = arr[i];
            if (arr[i] == 0) arr[--j] = arr[i];
            --i;
            --j;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func duplicateZeros(arr []int) {
	n := len(arr)
	i, k := -1, 0
	for k < n {
		i, k = i+1, k+1
		if arr[i] == 0 {
			k++
		}
	}
	j := n - 1
	if k == n+1 {
		arr[j] = 0
		i, j = i-1, j-1
	}
	for j >= 0 {
		arr[j] = arr[i]
		if arr[i] == 0 {
			j--
			arr[j] = arr[i]
		}
		i, j = i-1, j-1
	}
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let n = arr.len();
        let mut i = 0;
        let mut j = 0;
        while j < n {
            if arr[i] == 0 {
                j += 1;
            }
            j += 1;
            i += 1;
        }
        while i > 0 {
            if arr[i - 1] == 0 {
                if j <= n {
                    arr[j - 1] = arr[i - 1];
                }
                j -= 1;
            }
            arr[j - 1] = arr[i - 1];
            i -= 1;
            j -= 1;
        }
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
void duplicateZeros(int* arr, int arrSize) {
    int i = 0;
    int j = 0;
    while (j < arrSize) {
        if (arr[i] == 0) {
            j++;
        }
        i++;
        j++;
    }
    i--;
    j--;
    while (i >= 0) {
        if (arr[i] == 0) {
            if (j < arrSize) {
                arr[j] = arr[i];
            }
            j--;
        }
        arr[j] = arr[i];
        i--;
        j--;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度固定的整数数组&nbsp;<code>arr</code> ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。</p>

<p>注意：请不要在超过该数组长度的位置写入元素。请对输入的数组&nbsp;<strong>就地&nbsp;</strong>进行上述修改，不要从函数返回任何东西。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,0,2,3,0,4,5,0]
<strong>输出：</strong>[1,0,0,2,3,0,0,4]
<strong>解释：</strong>调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3]
<strong>输出：</strong>[1,2,3]
<strong>解释：</strong>调用函数后，输入的数组将被修改为：[1,2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

开辟一个等长数组，将 `arr` 复刻一份，再进行简单模拟即可。

-   时间复杂度：$O(n)$。
-   空间复杂度：$O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        n = len(arr)
        i, k = -1, 0
        while k < n:
            i += 1
            k += 1 if arr[i] else 2
        j = n - 1
        if k == n + 1:
            arr[j] = 0
            i, j = i - 1, j - 1
        while ~j:
            if arr[i] == 0:
                arr[j] = arr[j - 1] = arr[i]
                j -= 1
            else:
                arr[j] = arr[i]
            i, j = i - 1, j - 1
```

#### Java

```java
class Solution {
    public void duplicateZeros(int[] arr) {
        int n = arr.length;
        int i = -1, k = 0;
        while (k < n) {
            ++i;
            k += arr[i] > 0 ? 1 : 2;
        }
        int j = n - 1;
        if (k == n + 1) {
            arr[j--] = 0;
            --i;
        }
        while (j >= 0) {
            arr[j] = arr[i];
            if (arr[i] == 0) {
                arr[--j] = arr[i];
            }
            --i;
            --j;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = -1, k = 0;
        while (k < n) {
            ++i;
            k += arr[i] ? 1 : 2;
        }
        int j = n - 1;
        if (k == n + 1) {
            arr[j--] = 0;
            --i;
        }
        while (~j) {
            arr[j] = arr[i];
            if (arr[i] == 0) arr[--j] = arr[i];
            --i;
            --j;
        }
    }
};
```

#### Go

```go
func duplicateZeros(arr []int) {
	n := len(arr)
	i, k := -1, 0
	for k < n {
		i, k = i+1, k+1
		if arr[i] == 0 {
			k++
		}
	}
	j := n - 1
	if k == n+1 {
		arr[j] = 0
		i, j = i-1, j-1
	}
	for j >= 0 {
		arr[j] = arr[i]
		if arr[i] == 0 {
			j--
			arr[j] = arr[i]
		}
		i, j = i-1, j-1
	}
}
```

#### Rust

```rust
impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let n = arr.len();
        let mut i = 0;
        let mut j = 0;
        while j < n {
            if arr[i] == 0 {
                j += 1;
            }
            j += 1;
            i += 1;
        }
        while i > 0 {
            if arr[i - 1] == 0 {
                if j <= n {
                    arr[j - 1] = arr[i - 1];
                }
                j -= 1;
            }
            arr[j - 1] = arr[i - 1];
            i -= 1;
            j -= 1;
        }
    }
}
```

#### C

```c
void duplicateZeros(int* arr, int arrSize) {
    int i = 0;
    int j = 0;
    while (j < arrSize) {
        if (arr[i] == 0) {
            j++;
        }
        i++;
        j++;
    }
    i--;
    j--;
    while (i >= 0) {
        if (arr[i] == 0) {
            if (j < arrSize) {
                arr[j] = arr[i];
            }
            j--;
        }
        arr[j] = arr[i];
        i--;
        j--;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

-   时间复杂度：$O(n)$。
-   空间复杂度：$O(1)$。

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
