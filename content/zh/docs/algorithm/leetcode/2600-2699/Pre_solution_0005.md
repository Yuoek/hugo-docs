---
title: "2640_一个数组所有前缀的分数"
date: 2025-10-08T18:39:28+08:00
weight: 5
tags: [JavaScript, 二叉树, 前缀和, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 数学, 数组, 最短路, 栈, 树, 深度优先搜索, 矩阵, 设计, 贪心]
---

{{< markmap >}}
### [2640_一个数组所有前缀的分数](#2640)
#### [数组](#2640)
#### [前缀和](#2640)
### [2641_二叉树的堂兄弟节点 II](#2641)
#### [树](#2641)
#### [深度优先搜索](#2641)
#### [广度优先搜索](#2641)
#### [哈希表](#2641)
#### [二叉树](#2641)
### [2642_设计可以求最短路径的图类](#2642)
#### [图](#2642)
#### [设计](#2642)
#### [最短路](#2642)
#### [堆（优先队列）](#2642)
### [2643_一最多的行](#2643)
#### [数组](#2643)
#### [矩阵](#2643)
### [2644_找出可整除性得分最大的整数](#2644)
#### [数组](#2644)
### [2645_构造有效字符串的最少插入数](#2645)
#### [栈](#2645)
#### [贪心](#2645)
#### [字符串](#2645)
#### [动态规划](#2645)
### [2646_最小化旅行的价格总和](#2646)
#### [树](#2646)
#### [深度优先搜索](#2646)
#### [图](#2646)
#### [数组](#2646)
#### [动态规划](#2646)
### [2647_把三角形染成红色 🔒](#2647)
#### [数组](#2647)
#### [数学](#2647)
### [2648_生成斐波那契数列](#2648)
#### [JavaScript](#2648)
### [2649_嵌套数组生成器](#2649)
#### [JavaScript](#2649)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2640_一个数组所有前缀的分数
___
#### 数组
___
#### 前缀和
---
### 2641_二叉树的堂兄弟节点 II
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
### 2642_设计可以求最短路径的图类
___
#### 图
___
#### 设计
___
#### 最短路
___
#### 堆（优先队列）
---
### 2643_一最多的行
___
#### 数组
___
#### 矩阵
---
### 2644_找出可整除性得分最大的整数
___
#### 数组
---
### 2645_构造有效字符串的最少插入数
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 动态规划
---
### 2646_最小化旅行的价格总和
___
#### 树
___
#### 深度优先搜索
___
#### 图
___
#### 数组
___
#### 动态规划
---
### 2647_把三角形染成红色 🔒
___
#### 数组
___
#### 数学
---
### 2648_生成斐波那契数列
___
#### JavaScript
---
### 2649_嵌套数组生成器
___
#### JavaScript
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二叉树 | 前缀和 |
| 动态规划 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 数学 | 数组 | 最短路 |
| 栈 | 树 | 深度优先搜索 |
| 矩阵 | 设计 | 贪心 |

# [2640. 一个数组所有前缀的分数](https://leetcode.cn/problems/find-the-score-of-all-prefixes-of-an-array){#2640}

{{< tabs "2640" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        mx = 0
        for i, x in enumerate(nums):
            mx = max(mx, x)
            ans[i] = x + mx + (0 if i == 0 else ans[i - 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = Math.max(mx, nums[i]);
            ans[i] = nums[i] + mx + (i == 0 ? 0 : ans[i - 1]);
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
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            ans[i] = nums[i] + mx + (i == 0 ? 0 : ans[i - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPrefixScore(nums []int) []int64 {
	n := len(nums)
	ans := make([]int64, n)
	mx := 0
	for i, x := range nums {
		mx = max(mx, x)
		ans[i] = int64(x + mx)
		if i > 0 {
			ans[i] += ans[i-1]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPrefixScore(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = new Array(n);
    let mx: number = 0;
    for (let i = 0; i < n; ++i) {
        mx = Math.max(mx, nums[i]);
        ans[i] = nums[i] + mx + (i === 0 ? 0 : ans[i - 1]);
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

<p>定义一个数组 <code>arr</code>&nbsp;的 <strong>转换数组</strong>&nbsp;<code>conver</code>&nbsp;为：</p>

<ul>
	<li><code>conver[i] = arr[i] + max(arr[0..i])</code>，其中&nbsp;<code>max(arr[0..i])</code>&nbsp;是满足 <code>0 &lt;= j &lt;= i</code>&nbsp;的所有&nbsp;<code>arr[j]</code>&nbsp;中的最大值。</li>
</ul>

<p>定义一个数组 <code>arr</code>&nbsp;的 <strong>分数</strong>&nbsp;为 <code>arr</code>&nbsp;转换数组中所有元素的和。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，请你返回一个长度为 <code>n</code>&nbsp;的数组<em>&nbsp;</em><code>ans</code>&nbsp;，其中&nbsp;<code>ans[i]</code>是前缀&nbsp;<code>nums[0..i]</code>&nbsp;的分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,3,7,5,10]
<b>输出：</b>[4,10,24,36,56]
<b>解释：</b>
对于前缀 [2] ，转换数组为 [4] ，所以分数为 4 。
对于前缀 [2, 3] ，转换数组为 [4, 6] ，所以分数为 10 。
对于前缀 [2, 3, 7] ，转换数组为 [4, 6, 14] ，所以分数为 24 。
对于前缀 [2, 3, 7, 5] ，转换数组为 [4, 6, 14, 12] ，所以分数为 36 。
对于前缀 [2, 3, 7, 5, 10] ，转换数组为 [4, 6, 14, 12, 20] ，所以分数为 56 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,1,2,4,8,16]
<b>输出：</b>[2,4,8,16,32,64]
<b>解释：</b>
对于前缀 [1] ，转换数组为 [2] ，所以分数为 2 。
对于前缀 [1, 1]，转换数组为 [2, 2] ，所以分数为 4 。
对于前缀 [1, 1, 2]，转换数组为 [2, 2, 4] ，所以分数为 8 。
对于前缀 [1, 1, 2, 4]，转换数组为 [2, 2, 4, 8] ，所以分数为 16 。
对于前缀 [1, 1, 2, 4, 8]，转换数组为 [2, 2, 4, 8, 16] ，所以分数为 32 。
对于前缀 [1, 1, 2, 4, 8, 16]，转换数组为 [2, 2, 4, 8, 16, 32] ，所以分数为 64 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们用变量 $mx$ 记录数组 $nums$ 中前 $i$ 个元素的最大值，用数组 $ans[i]$ 记录数组 $nums$ 中前 $i$ 个元素的分数。

接下来，遍历数组 $nums$，对于每个元素 $nums[i]$，我们更新 $mx$，即 $mx = \max(mx, nums[i])$，然后更新 $ans[i]$，如果 $i = 0$，则 $ans[i] = nums[i] + mx$，否则 $ans[i] = nums[i] + mx + ans[i - 1]$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        mx = 0
        for i, x in enumerate(nums):
            mx = max(mx, x)
            ans[i] = x + mx + (0 if i == 0 else ans[i - 1])
        return ans
```

#### Java

```java
class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = Math.max(mx, nums[i]);
            ans[i] = nums[i] + mx + (i == 0 ? 0 : ans[i - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            ans[i] = nums[i] + mx + (i == 0 ? 0 : ans[i - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func findPrefixScore(nums []int) []int64 {
	n := len(nums)
	ans := make([]int64, n)
	mx := 0
	for i, x := range nums {
		mx = max(mx, x)
		ans[i] = int64(x + mx)
		if i > 0 {
			ans[i] += ans[i-1]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findPrefixScore(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = new Array(n);
    let mx: number = 0;
    for (let i = 0; i < n; ++i) {
        mx = Math.max(mx, nums[i]);
        ans[i] = nums[i] + mx + (i === 0 ? 0 : ans[i - 1]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2641. 二叉树的堂兄弟节点 II](https://leetcode.cn/problems/cousins-in-binary-tree-ii){#2641}

{{< tabs "2641" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root.val = 0
        q = [root]
        while q:
            t = []
            s = 0
            for node in q:
                if node.left:
                    t.append(node.left)
                    s += node.left.val
                if node.right:
                    t.append(node.right)
                    s += node.right.val
            for node in q:
                sub = (node.left.val if node.left else 0) + (
                    node.right.val if node.right else 0
                )
                if node.left:
                    node.left.val = s - sub
                if node.right:
                    node.right.val = s - sub
            q = t
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
    public TreeNode replaceValueInTree(TreeNode root) {
        root.val = 0;
        List<TreeNode> q = List.of(root);
        while (!q.isEmpty()) {
            List<TreeNode> t = new ArrayList<>();
            int s = 0;
            for (TreeNode node : q) {
                if (node.left != null) {
                    t.add(node.left);
                    s += node.left.val;
                }
                if (node.right != null) {
                    t.add(node.right);
                    s += node.right.val;
                }
            }
            for (TreeNode node : q) {
                int sub = (node.left == null ? 0 : node.left.val)
                    + (node.right == null ? 0 : node.right.val);
                if (node.left != null) {
                    node.left.val = s - sub;
                }
                if (node.right != null) {
                    node.right.val = s - sub;
                }
            }
            q = t;
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*> q = {root};
        while (!q.empty()) {
            vector<TreeNode*> t;
            int s = 0;
            for (TreeNode* node : q) {
                if (node->left) {
                    t.emplace_back(node->left);
                    s += node->left->val;
                }
                if (node->right) {
                    t.emplace_back(node->right);
                    s += node->right->val;
                }
            }
            for (TreeNode* node : q) {
                int sub = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) {
                    node->left->val = s - sub;
                }
                if (node->right) {
                    node->right->val = s - sub;
                }
            }
            q = move(t);
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
func replaceValueInTree(root *TreeNode) *TreeNode {
	root.Val = 0
	q := []*TreeNode{root}
	for len(q) > 0 {
		t := []*TreeNode{}
		s := 0
		for _, node := range q {
			if node.Left != nil {
				t = append(t, node.Left)
				s += node.Left.Val
			}
			if node.Right != nil {
				t = append(t, node.Right)
				s += node.Right.Val
			}
		}
		for _, node := range q {
			sub := 0
			if node.Left != nil {
				sub += node.Left.Val
			}
			if node.Right != nil {
				sub += node.Right.Val
			}
			if node.Left != nil {
				node.Left.Val = s - sub
			}
			if node.Right != nil {
				node.Right.Val = s - sub
			}
		}
		q = t
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

function replaceValueInTree(root: TreeNode | null): TreeNode | null {
    let q = [root];
    let [sum, nextSum] = [0, root.val];

    while (q.length) {
        const qNext: TreeNode[] = [];
        [sum, nextSum] = [nextSum, 0];

        for (const node of q) {
            const x = (node.left?.val ?? 0) + (node.right?.val ?? 0);
            node.val = sum - node.val;
            nextSum += x;

            if (node.left) {
                node.left.val = x;
                qNext.push(node.left);
            }

            if (node.right) {
                node.right.val = x;
                qNext.push(node.right);
            }
        }

        q = qNext;
    }

    return root;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function replaceValueInTree(root) {
    let q = [root];
    let [sum, nextSum] = [0, root.val];

    while (q.length) {
        const qNext = [];
        [sum, nextSum] = [nextSum, 0];

        for (const node of q) {
            const x = (node.left?.val ?? 0) + (node.right?.val ?? 0);
            node.val = sum - node.val;
            nextSum += x;

            if (node.left) {
                node.left.val = x;
                qNext.push(node.left);
            }

            if (node.right) {
                node.right.val = x;
                qNext.push(node.right);
            }
        }

        q = qNext;
    }

    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根&nbsp;<code>root</code>&nbsp;，请你将每个节点的值替换成该节点的所有 <strong>堂兄弟节点值的和&nbsp;</strong>。</p>

<p>如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 <strong>堂兄弟</strong>&nbsp;。</p>

<p>请你返回修改值之后，树的根<em>&nbsp;</em><code>root</code><em>&nbsp;</em>。</p>

<p><strong>注意</strong>，一个节点的深度指的是从树根节点到这个节点经过的边数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2641.Cousins%20in%20Binary%20Tree%20II/images/example11.png" style="width: 571px; height: 151px;" /></p>

<pre>
<b>输入：</b>root = [5,4,9,1,10,null,7]
<b>输出：</b>[0,0,0,7,7,null,11]
<b>解释：</b>上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 5 的节点没有堂兄弟，所以值修改为 0 。
- 值为 4 的节点没有堂兄弟，所以值修改为 0 。
- 值为 9 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 10 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 7 的节点有两个堂兄弟，值分别为 1 和 10 ，所以值修改为 11 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2641.Cousins%20in%20Binary%20Tree%20II/images/diagram33.png" style="width: 481px; height: 91px;" /></p>

<pre>
<b>输入：</b>root = [3,1,2]
<b>输出：</b>[0,0,0]
<b>解释：</b>上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 3 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点没有堂兄弟，所以值修改为 0 。
- 值为 2 的节点没有堂兄弟，所以值修改为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目的范围是&nbsp;<code>[1, 10<sup>5</sup>]</code> 。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们创建一个列表 $s$ 用于记录二叉树每一层的节点值之和，其中 $s[depth]$ 表示第 $depth$ 层的节点值之和（规定根节点所在的层为第 $0$ 层）。

接下来，我们先跑一遍 DFS，计算出数组 $s$ 的值。然后再跑一遍 DFS，更新每个节点的子节点的值，子节点的值等于子节点所在层的节点值之和减去子节点及其兄弟节点的值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs1(root: Optional[TreeNode], depth: int):
            if root is None:
                return
            if len(s) <= depth:
                s.append(0)
            s[depth] += root.val
            dfs1(root.left, depth + 1)
            dfs1(root.right, depth + 1)

        def dfs2(root: Optional[TreeNode], depth: int):
            sub = (root.left.val if root.left else 0) + (
                root.right.val if root.right else 0
            )
            depth += 1
            if root.left:
                root.left.val = s[depth] - sub
                dfs2(root.left, depth)
            if root.right:
                root.right.val = s[depth] - sub
                dfs2(root.right, depth)

        s = []
        dfs1(root, 0)
        root.val = 0
        dfs2(root, 0)
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
    private List<Integer> s = new ArrayList<>();

    public TreeNode replaceValueInTree(TreeNode root) {
        dfs1(root, 0);
        root.val = 0;
        dfs2(root, 0);
        return root;
    }

    private void dfs1(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        if (s.size() <= depth) {
            s.add(0);
        }
        s.set(depth, s.get(depth) + root.val);
        dfs1(root.left, depth + 1);
        dfs1(root.right, depth + 1);
    }

    private void dfs2(TreeNode root, int depth) {
        int l = root.left == null ? 0 : root.left.val;
        int r = root.right == null ? 0 : root.right.val;
        int sub = l + r;
        ++depth;
        if (root.left != null) {
            root.left.val = s.get(depth) - sub;
            dfs2(root.left, depth);
        }
        if (root.right != null) {
            root.right.val = s.get(depth) - sub;
            dfs2(root.right, depth);
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        memset(s, 0, sizeof(s));
        dfs1(root, 0);
        root->val = 0;
        dfs2(root, 0);
        return root;
    }

private:
    int s[100010];
    void dfs1(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        s[depth] += root->val;
        dfs1(root->left, depth + 1);
        dfs1(root->right, depth + 1);
    };

    void dfs2(TreeNode* root, int depth) {
        int l = root->left ? root->left->val : 0;
        int r = root->right ? root->right->val : 0;
        int sub = l + r;
        ++depth;
        if (root->left) {
            root->left->val = s[depth] - sub;
            dfs2(root->left, depth);
        }
        if (root->right) {
            root->right->val = s[depth] - sub;
            dfs2(root->right, depth);
        }
    };
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
func replaceValueInTree(root *TreeNode) *TreeNode {
	s := []int{}
	var dfs1 func(*TreeNode, int)
	dfs1 = func(root *TreeNode, depth int) {
		if root == nil {
			return
		}
		if len(s) <= depth {
			s = append(s, 0)
		}
		s[depth] += root.Val
		dfs1(root.Left, depth+1)
		dfs1(root.Right, depth+1)
	}
	var dfs2 func(*TreeNode, int)
	dfs2 = func(root *TreeNode, depth int) {
		l, r := 0, 0
		if root.Left != nil {
			l = root.Left.Val
		}
		if root.Right != nil {
			r = root.Right.Val
		}
		sub := l + r
		depth++
		if root.Left != nil {
			root.Left.Val = s[depth] - sub
			dfs2(root.Left, depth)
		}
		if root.Right != nil {
			root.Right.Val = s[depth] - sub
			dfs2(root.Right, depth)
		}
	}
	dfs1(root, 0)
	root.Val = 0
	dfs2(root, 0)
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

function replaceValueInTree(root: TreeNode | null): TreeNode | null {
    const s: number[] = [];
    const dfs1 = (root: TreeNode | null, depth: number) => {
        if (!root) {
            return;
        }
        if (s.length <= depth) {
            s.push(0);
        }
        s[depth] += root.val;
        dfs1(root.left, depth + 1);
        dfs1(root.right, depth + 1);
    };
    const dfs2 = (root: TreeNode | null, depth: number) => {
        const sub = (root.left?.val || 0) + (root.right?.val || 0);
        ++depth;
        if (root.left) {
            root.left.val = s[depth] - sub;
            dfs2(root.left, depth);
        }
        if (root.right) {
            root.right.val = s[depth] - sub;
            dfs2(root.right, depth);
        }
    };
    dfs1(root, 0);
    root.val = 0;
    dfs2(root, 0);
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

我们先将根节点的值更新为 $0$，用一个队列 $q$ 来存储每一层的所有节点，初始时将根节点入队。

然后遍历队列，计算每一层的所有子节点的值之和 $s$，然后计算每个子节点及其兄弟节点的值之和 $sub$，然后更新每个子节点的值为 $s - sub$。

遍历结束后，返回根节点即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root.val = 0
        q = [root]
        while q:
            t = []
            s = 0
            for node in q:
                if node.left:
                    t.append(node.left)
                    s += node.left.val
                if node.right:
                    t.append(node.right)
                    s += node.right.val
            for node in q:
                sub = (node.left.val if node.left else 0) + (
                    node.right.val if node.right else 0
                )
                if node.left:
                    node.left.val = s - sub
                if node.right:
                    node.right.val = s - sub
            q = t
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
    public TreeNode replaceValueInTree(TreeNode root) {
        root.val = 0;
        List<TreeNode> q = List.of(root);
        while (!q.isEmpty()) {
            List<TreeNode> t = new ArrayList<>();
            int s = 0;
            for (TreeNode node : q) {
                if (node.left != null) {
                    t.add(node.left);
                    s += node.left.val;
                }
                if (node.right != null) {
                    t.add(node.right);
                    s += node.right.val;
                }
            }
            for (TreeNode node : q) {
                int sub = (node.left == null ? 0 : node.left.val)
                    + (node.right == null ? 0 : node.right.val);
                if (node.left != null) {
                    node.left.val = s - sub;
                }
                if (node.right != null) {
                    node.right.val = s - sub;
                }
            }
            q = t;
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*> q = {root};
        while (!q.empty()) {
            vector<TreeNode*> t;
            int s = 0;
            for (TreeNode* node : q) {
                if (node->left) {
                    t.emplace_back(node->left);
                    s += node->left->val;
                }
                if (node->right) {
                    t.emplace_back(node->right);
                    s += node->right->val;
                }
            }
            for (TreeNode* node : q) {
                int sub = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) {
                    node->left->val = s - sub;
                }
                if (node->right) {
                    node->right->val = s - sub;
                }
            }
            q = move(t);
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
func replaceValueInTree(root *TreeNode) *TreeNode {
	root.Val = 0
	q := []*TreeNode{root}
	for len(q) > 0 {
		t := []*TreeNode{}
		s := 0
		for _, node := range q {
			if node.Left != nil {
				t = append(t, node.Left)
				s += node.Left.Val
			}
			if node.Right != nil {
				t = append(t, node.Right)
				s += node.Right.Val
			}
		}
		for _, node := range q {
			sub := 0
			if node.Left != nil {
				sub += node.Left.Val
			}
			if node.Right != nil {
				sub += node.Right.Val
			}
			if node.Left != nil {
				node.Left.Val = s - sub
			}
			if node.Right != nil {
				node.Right.Val = s - sub
			}
		}
		q = t
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

function replaceValueInTree(root: TreeNode | null): TreeNode | null {
    let q = [root];
    let [sum, nextSum] = [0, root.val];

    while (q.length) {
        const qNext: TreeNode[] = [];
        [sum, nextSum] = [nextSum, 0];

        for (const node of q) {
            const x = (node.left?.val ?? 0) + (node.right?.val ?? 0);
            node.val = sum - node.val;
            nextSum += x;

            if (node.left) {
                node.left.val = x;
                qNext.push(node.left);
            }

            if (node.right) {
                node.right.val = x;
                qNext.push(node.right);
            }
        }

        q = qNext;
    }

    return root;
}
```

#### JavaScript

```js
function replaceValueInTree(root) {
    let q = [root];
    let [sum, nextSum] = [0, root.val];

    while (q.length) {
        const qNext = [];
        [sum, nextSum] = [nextSum, 0];

        for (const node of q) {
            const x = (node.left?.val ?? 0) + (node.right?.val ?? 0);
            node.val = sum - node.val;
            nextSum += x;

            if (node.left) {
                node.left.val = x;
                qNext.push(node.left);
            }

            if (node.right) {
                node.right.val = x;
                qNext.push(node.right);
            }
        }

        q = qNext;
    }

    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2642. 设计可以求最短路径的图类](https://leetcode.cn/problems/design-graph-with-shortest-path-calculator){#2642}

{{< tabs "2642" >}}

{{% tab "python" %}}
```python
class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.n = n
        self.g = [[inf] * n for _ in range(n)]
        for f, t, c in edges:
            self.g[f][t] = c

    def addEdge(self, edge: List[int]) -> None:
        f, t, c = edge
        self.g[f][t] = c

    def shortestPath(self, node1: int, node2: int) -> int:
        dist = [inf] * self.n
        dist[node1] = 0
        vis = [False] * self.n
        for _ in range(self.n):
            t = -1
            for j in range(self.n):
                if not vis[j] and (t == -1 or dist[t] > dist[j]):
                    t = j
            vis[t] = True
            for j in range(self.n):
                dist[j] = min(dist[j], dist[t] + self.g[t][j])
        return -1 if dist[node2] == inf else dist[node2]


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Graph {
    private int n;
    private int[][] g;
    private final int inf = 1 << 29;

    public Graph(int n, int[][] edges) {
        this.n = n;
        g = new int[n][n];
        for (var f : g) {
            Arrays.fill(f, inf);
        }
        for (int[] e : edges) {
            int f = e[0], t = e[1], c = e[2];
            g[f][t] = c;
        }
    }

    public void addEdge(int[] edge) {
        int f = edge[0], t = edge[1], c = edge[2];
        g[f][t] = c;
    }

    public int shortestPath(int node1, int node2) {
        int[] dist = new int[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(dist, inf);
        dist[node1] = 0;
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
            }
        }
        return dist[node2] >= inf ? -1 : dist[node2];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.addEdge(edge);
 * int param_2 = obj.shortestPath(node1,node2);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g = vector<vector<int>>(n, vector<int>(n, inf));
        for (auto& e : edges) {
            int f = e[0], t = e[1], c = e[2];
            g[f][t] = c;
        }
    }

    void addEdge(vector<int> edge) {
        int f = edge[0], t = edge[1], c = edge[2];
        g[f][t] = c;
    }

    int shortestPath(int node1, int node2) {
        vector<bool> vis(n);
        vector<int> dist(n, inf);
        dist[node1] = 0;
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        return dist[node2] >= inf ? -1 : dist[node2];
    }

private:
    vector<vector<int>> g;
    int n;
    const int inf = 1 << 29;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
const inf = 1 << 29

type Graph struct {
	g [][]int
}

func Constructor(n int, edges [][]int) Graph {
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
	}
	for _, e := range edges {
		f, t, c := e[0], e[1], e[2]
		g[f][t] = c
	}
	return Graph{g}
}

func (this *Graph) AddEdge(edge []int) {
	f, t, c := edge[0], edge[1], edge[2]
	this.g[f][t] = c
}

func (this *Graph) ShortestPath(node1 int, node2 int) int {
	n := len(this.g)
	dist := make([]int, n)
	for i := range dist {
		dist[i] = inf
	}
	vis := make([]bool, n)
	dist[node1] = 0
	for i := 0; i < n; i++ {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[t] > dist[j]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			dist[j] = min(dist[j], dist[t]+this.g[t][j])
		}
	}
	if dist[node2] >= inf {
		return -1
	}
	return dist[node2]
}

/**
 * Your Graph object will be instantiated and called as such:
 * obj := Constructor(n, edges);
 * obj.AddEdge(edge);
 * param_2 := obj.ShortestPath(node1,node2);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Graph {
    private g: number[][] = [];
    private inf: number = 1 << 29;

    constructor(n: number, edges: number[][]) {
        this.g = Array.from({ length: n }, () => Array(n).fill(this.inf));
        for (const [f, t, c] of edges) {
            this.g[f][t] = c;
        }
    }

    addEdge(edge: number[]): void {
        const [f, t, c] = edge;
        this.g[f][t] = c;
    }

    shortestPath(node1: number, node2: number): number {
        const n = this.g.length;
        const dist: number[] = new Array(n).fill(this.inf);
        dist[node1] = 0;
        const vis: boolean[] = new Array(n).fill(false);
        for (let i = 0; i < n; ++i) {
            let t = -1;
            for (let j = 0; j < n; ++j) {
                if (!vis[j] && (t === -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (let j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + this.g[t][j]);
            }
        }
        return dist[node2] >= this.inf ? -1 : dist[node2];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * var obj = new Graph(n, edges)
 * obj.addEdge(edge)
 * var param_2 = obj.shortestPath(node1,node2)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Graph {
    private int n;
    private int[,] g;
    private readonly int inf = 1 << 29;

    public Graph(int n, int[][] edges) {
        this.n = n;
        g = new int[n, n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i, j] = inf;
            }
        }
        foreach (var e in edges) {
            int f = e[0], t = e[1], c = e[2];
            g[f, t] = c;
        }
    }

    public void AddEdge(int[] edge) {
        int f = edge[0], t = edge[1], c = edge[2];
        g[f, t] = c;
    }

    public int ShortestPath(int node1, int node2) {
        int[] dist = new int[n];
        bool[] vis = new bool[n];
        Array.Fill(dist, inf);
        dist[node1] = 0;
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.Min(dist[j], dist[t] + g[t, j]);
            }
        }
        return dist[node2] >= inf ? -1 : dist[node2];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.AddEdge(edge);
 * int param_2 = obj.ShortestPath(node1,node2);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有&nbsp;<code>n</code>&nbsp;个节点的&nbsp;<strong>有向带权</strong>&nbsp;图，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。图中的初始边用数组&nbsp;<code>edges</code>&nbsp;表示，其中&nbsp;<code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, edgeCost<sub>i</sub>]</code>&nbsp;表示从&nbsp;<code>from<sub>i</sub></code>&nbsp;到&nbsp;<code>to<sub>i</sub></code>&nbsp;有一条代价为&nbsp;<code>edgeCost<sub>i</sub></code>&nbsp;的边。</p>

<p>请你实现一个&nbsp;<code>Graph</code>&nbsp;类：</p>

<ul>
	<li><code>Graph(int n, int[][] edges)</code>&nbsp;初始化图有&nbsp;<code>n</code>&nbsp;个节点，并输入初始边。</li>
	<li><code>addEdge(int[] edge)</code>&nbsp;向边集中添加一条边，其中<strong>&nbsp;</strong><code>edge = [from, to, edgeCost]</code>&nbsp;。数据保证添加这条边之前对应的两个节点之间没有有向边。</li>
	<li><code>int shortestPath(int node1, int node2)</code>&nbsp;返回从节点&nbsp;<code>node1</code>&nbsp;到&nbsp;<code>node2</code>&nbsp;的路径<strong>&nbsp;最小</strong>&nbsp;代价。如果路径不存在，返回&nbsp;<code>-1</code>&nbsp;。一条路径的代价是路径中所有边代价之和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2642.Design%20Graph%20With%20Shortest%20Path%20Calculator/images/graph3drawio-2.png" style="width: 621px; height: 191px;"></p>

<pre><strong>输入：</strong>
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
<b>输出：</b>
[null, 6, -1, null, 6]

<strong>解释：</strong>
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // 返回 6 。从 3 到 2 的最短路径如第一幅图所示：3 -&gt; 0 -&gt; 1 -&gt; 2 ，总代价为 3 + 2 + 1 = 6 。
g.shortestPath(0, 3); // 返回 -1 。没有从 0 到 3 的路径。
g.addEdge([1, 3, 4]); // 添加一条节点 1 到节点 3 的边，得到第二幅图。
g.shortestPath(0, 3); // 返回 6 。从 0 到 3 的最短路径为 0 -&gt; 1 -&gt; 3 ，总代价为 2 + 4 = 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1)</code></li>
	<li><code>edges[i].length == edge.length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub>, from, to, node1, node2 &lt;= n - 1</code></li>
	<li><code>1 &lt;= edgeCost<sub>i</sub>, edgeCost &lt;= 10<sup>6</sup></code></li>
	<li>图中任何时候都不会有重边和自环。</li>
	<li>调用 <code>addEdge</code>&nbsp;至多&nbsp;<code>100</code>&nbsp;次。</li>
	<li>调用 <code>shortestPath</code>&nbsp;至多&nbsp;<code>100</code>&nbsp;次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Dijsktra 算法

在初始化函数中，我们先用邻接矩阵 $g$ 存储图的边权，其中 $g_{ij}$ 表示从节点 $i$ 到节点 $j$ 的边权，如果 $i$ 和 $j$ 之间没有边，则 $g_{ij}$ 的值为 $\infty$。

在 `addEdge` 函数中，我们更新 $g_{ij}$ 的值为 $edge[2]$。

在 `shortestPath` 函数中，我们使用 Dijsktra 算法求从节点 $node1$ 到节点 $node2$ 的最短路径，其中 $dist[i]$ 表示从节点 $node1$ 到节点 $i$ 的最短路径，$vis[i]$ 表示节点 $i$ 是否已经被访问过。我们初始化 $dist[node1]$ 为 $0$，其余的 $dist[i]$ 均为 $\infty$。然后我们遍历 $n$ 次，每次找到当前未被访问过的节点 $t$，使得 $dist[t]$ 最小。然后我们将节点 $t$ 标记为已访问，然后更新 $dist[i]$ 的值为 $min(dist[i], dist[t] + g_{ti})$。最后我们返回 $dist[node2]$，如果 $dist[node2]$ 为 $\infty$，则说明从节点 $node1$ 到节点 $node2$ 不存在路径，返回 $-1$。

时间复杂度 $O(n^2 \times q)$，空间复杂度 $O(n^2)$。其中 $n$ 为节点数，而 $q$ 为 `shortestPath` 函数的调用次数。

<!-- tabs:start -->

#### Python3

```python
class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.n = n
        self.g = [[inf] * n for _ in range(n)]
        for f, t, c in edges:
            self.g[f][t] = c

    def addEdge(self, edge: List[int]) -> None:
        f, t, c = edge
        self.g[f][t] = c

    def shortestPath(self, node1: int, node2: int) -> int:
        dist = [inf] * self.n
        dist[node1] = 0
        vis = [False] * self.n
        for _ in range(self.n):
            t = -1
            for j in range(self.n):
                if not vis[j] and (t == -1 or dist[t] > dist[j]):
                    t = j
            vis[t] = True
            for j in range(self.n):
                dist[j] = min(dist[j], dist[t] + self.g[t][j])
        return -1 if dist[node2] == inf else dist[node2]


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)
```

#### Java

```java
class Graph {
    private int n;
    private int[][] g;
    private final int inf = 1 << 29;

    public Graph(int n, int[][] edges) {
        this.n = n;
        g = new int[n][n];
        for (var f : g) {
            Arrays.fill(f, inf);
        }
        for (int[] e : edges) {
            int f = e[0], t = e[1], c = e[2];
            g[f][t] = c;
        }
    }

    public void addEdge(int[] edge) {
        int f = edge[0], t = edge[1], c = edge[2];
        g[f][t] = c;
    }

    public int shortestPath(int node1, int node2) {
        int[] dist = new int[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(dist, inf);
        dist[node1] = 0;
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
            }
        }
        return dist[node2] >= inf ? -1 : dist[node2];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.addEdge(edge);
 * int param_2 = obj.shortestPath(node1,node2);
 */
```

#### C++

```cpp
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g = vector<vector<int>>(n, vector<int>(n, inf));
        for (auto& e : edges) {
            int f = e[0], t = e[1], c = e[2];
            g[f][t] = c;
        }
    }

    void addEdge(vector<int> edge) {
        int f = edge[0], t = edge[1], c = edge[2];
        g[f][t] = c;
    }

    int shortestPath(int node1, int node2) {
        vector<bool> vis(n);
        vector<int> dist(n, inf);
        dist[node1] = 0;
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        return dist[node2] >= inf ? -1 : dist[node2];
    }

private:
    vector<vector<int>> g;
    int n;
    const int inf = 1 << 29;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
```

#### Go

```go
const inf = 1 << 29

type Graph struct {
	g [][]int
}

func Constructor(n int, edges [][]int) Graph {
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
	}
	for _, e := range edges {
		f, t, c := e[0], e[1], e[2]
		g[f][t] = c
	}
	return Graph{g}
}

func (this *Graph) AddEdge(edge []int) {
	f, t, c := edge[0], edge[1], edge[2]
	this.g[f][t] = c
}

func (this *Graph) ShortestPath(node1 int, node2 int) int {
	n := len(this.g)
	dist := make([]int, n)
	for i := range dist {
		dist[i] = inf
	}
	vis := make([]bool, n)
	dist[node1] = 0
	for i := 0; i < n; i++ {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[t] > dist[j]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			dist[j] = min(dist[j], dist[t]+this.g[t][j])
		}
	}
	if dist[node2] >= inf {
		return -1
	}
	return dist[node2]
}

/**
 * Your Graph object will be instantiated and called as such:
 * obj := Constructor(n, edges);
 * obj.AddEdge(edge);
 * param_2 := obj.ShortestPath(node1,node2);
 */
```

#### TypeScript

```ts
class Graph {
    private g: number[][] = [];
    private inf: number = 1 << 29;

    constructor(n: number, edges: number[][]) {
        this.g = Array.from({ length: n }, () => Array(n).fill(this.inf));
        for (const [f, t, c] of edges) {
            this.g[f][t] = c;
        }
    }

    addEdge(edge: number[]): void {
        const [f, t, c] = edge;
        this.g[f][t] = c;
    }

    shortestPath(node1: number, node2: number): number {
        const n = this.g.length;
        const dist: number[] = new Array(n).fill(this.inf);
        dist[node1] = 0;
        const vis: boolean[] = new Array(n).fill(false);
        for (let i = 0; i < n; ++i) {
            let t = -1;
            for (let j = 0; j < n; ++j) {
                if (!vis[j] && (t === -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (let j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + this.g[t][j]);
            }
        }
        return dist[node2] >= this.inf ? -1 : dist[node2];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * var obj = new Graph(n, edges)
 * obj.addEdge(edge)
 * var param_2 = obj.shortestPath(node1,node2)
 */
```

#### C#

```cs
public class Graph {
    private int n;
    private int[,] g;
    private readonly int inf = 1 << 29;

    public Graph(int n, int[][] edges) {
        this.n = n;
        g = new int[n, n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i, j] = inf;
            }
        }
        foreach (var e in edges) {
            int f = e[0], t = e[1], c = e[2];
            g[f, t] = c;
        }
    }

    public void AddEdge(int[] edge) {
        int f = edge[0], t = edge[1], c = edge[2];
        g[f, t] = c;
    }

    public int ShortestPath(int node1, int node2) {
        int[] dist = new int[n];
        bool[] vis = new bool[n];
        Array.Fill(dist, inf);
        dist[node1] = 0;
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.Min(dist[j], dist[t] + g[t, j]);
            }
        }
        return dist[node2] >= inf ? -1 : dist[node2];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.AddEdge(edge);
 * int param_2 = obj.ShortestPath(node1,node2);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2643. 一最多的行](https://leetcode.cn/problems/row-with-maximum-ones){#2643}

{{< tabs "2643" >}}

{{% tab "python" %}}
```python
class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        ans = [0, 0]
        for i, row in enumerate(mat):
            cnt = sum(row)
            if ans[1] < cnt:
                ans = [i, cnt]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] ans = new int[2];
        for (int i = 0; i < mat.length; ++i) {
            int cnt = 0;
            for (int x : mat[i]) {
                cnt += x;
            }
            if (ans[1] < cnt) {
                ans[0] = i;
                ans[1] = cnt;
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
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2);
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (ans[1] < cnt) {
                ans = {i, cnt};
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rowAndMaximumOnes(mat [][]int) []int {
	ans := []int{0, 0}
	for i, row := range mat {
		cnt := 0
		for _, x := range row {
			cnt += x
		}
		if ans[1] < cnt {
			ans = []int{i, cnt}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rowAndMaximumOnes(mat: number[][]): number[] {
    const ans: number[] = [0, 0];
    for (let i = 0; i < mat.length; i++) {
        const cnt = mat[i].reduce((sum, num) => sum + num, 0);
        if (ans[1] < cnt) {
            ans[0] = i;
            ans[1] = cnt;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = vec![0, 0];
        for (i, row) in mat.iter().enumerate() {
            let cnt = row.iter().sum();
            if ans[1] < cnt {
                ans = vec![i as i32, cnt];
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] RowAndMaximumOnes(int[][] mat) {
        int[] ans = new int[2];
        for (int i = 0; i < mat.Length; i++) {
            int cnt = mat[i].Sum();
            if (ans[1] < cnt) {
                ans = new int[] { i, cnt };
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

<p>给你一个大小为 <code>m x n</code> 的二进制矩阵 <code>mat</code> ，请你找出包含最多 <strong>1</strong> 的行的下标（从 <strong>0</strong> 开始）以及这一行中 <strong>1</strong> 的数目。</p>

<p>如果有多行包含最多的 1 ，只需要选择 <strong>行下标最小</strong> 的那一行。</p>

<p>返回一个由行下标和该行中 1 的数量组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0,1],[1,0]]
<strong>输出：</strong>[0,1]
<strong>解释：</strong>两行中 1 的数量相同。所以返回下标最小的行，下标为 0 。该行 1 的数量为 1 。所以，答案为 [0,1] 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0,0,0],[0,1,1]]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>下标为 1 的行中 1 的数量最多<code>。</code>该行 1 的数量<code>为 2 。所以，答案为</code> [1,2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0,0],[1,1],[0,0]]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>下标为 1 的行中 1 的数量最多。该行 1 的数量<code>为 2 。所以，答案为</code> [1,2] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code>&nbsp;</li>
	<li><code>n == mat[i].length</code>&nbsp;</li>
	<li><code>1 &lt;= m, n &lt;= 100</code>&nbsp;</li>
	<li><code>mat[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们初始化一个数组 $\textit{ans} = [0, 0]$，用于记录最多 $1$ 的行的下标和 $1$ 的数量。

然后遍历矩阵的每一行，对于每一行：

-   计算该行 $1$ 的数量 $\textit{cnt}$（由于矩阵中只包含 $0$ 和 $1$，我们可以直接对该行求和）；
-   如果 $\textit{ans}[1] < \textit{cnt}$，则更新 $\textit{ans} = [i, \textit{cnt}]$。

遍历结束后，返回 $\textit{ans}$。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        ans = [0, 0]
        for i, row in enumerate(mat):
            cnt = sum(row)
            if ans[1] < cnt:
                ans = [i, cnt]
        return ans
```

#### Java

```java
class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] ans = new int[2];
        for (int i = 0; i < mat.length; ++i) {
            int cnt = 0;
            for (int x : mat[i]) {
                cnt += x;
            }
            if (ans[1] < cnt) {
                ans[0] = i;
                ans[1] = cnt;
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
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2);
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (ans[1] < cnt) {
                ans = {i, cnt};
            }
        }
        return ans;
    }
};
```

#### Go

```go
func rowAndMaximumOnes(mat [][]int) []int {
	ans := []int{0, 0}
	for i, row := range mat {
		cnt := 0
		for _, x := range row {
			cnt += x
		}
		if ans[1] < cnt {
			ans = []int{i, cnt}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function rowAndMaximumOnes(mat: number[][]): number[] {
    const ans: number[] = [0, 0];
    for (let i = 0; i < mat.length; i++) {
        const cnt = mat[i].reduce((sum, num) => sum + num, 0);
        if (ans[1] < cnt) {
            ans[0] = i;
            ans[1] = cnt;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = vec![0, 0];
        for (i, row) in mat.iter().enumerate() {
            let cnt = row.iter().sum();
            if ans[1] < cnt {
                ans = vec![i as i32, cnt];
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int[] RowAndMaximumOnes(int[][] mat) {
        int[] ans = new int[2];
        for (int i = 0; i < mat.Length; i++) {
            int cnt = mat[i].Sum();
            if (ans[1] < cnt) {
                ans = new int[] { i, cnt };
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

# [2644. 找出可整除性得分最大的整数](https://leetcode.cn/problems/find-the-maximum-divisibility-score){#2644}

{{< tabs "2644" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        ans, mx = divisors[0], 0
        for div in divisors:
            cnt = sum(x % div == 0 for x in nums)
            if mx < cnt:
                mx, ans = cnt, div
            elif mx == cnt and ans > div:
                ans = div
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                if (x % div == 0) {
                    ++cnt;
                }
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = Math.min(ans, div);
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                cnt += x % div == 0;
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = min(ans, div);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDivScore(nums []int, divisors []int) int {
	ans, mx := divisors[0], 0
	for _, div := range divisors {
		cnt := 0
		for _, x := range nums {
			if x%div == 0 {
				cnt++
			}
		}
		if mx < cnt {
			ans, mx = div, cnt
		} else if mx == cnt && ans > div {
			ans = div
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDivScore(nums: number[], divisors: number[]): number {
    let ans: number = divisors[0];
    let mx: number = 0;
    for (const div of divisors) {
        const cnt = nums.reduce((a, b) => a + (b % div == 0 ? 1 : 0), 0);
        if (mx < cnt) {
            mx = cnt;
            ans = div;
        } else if (mx === cnt && ans > div) {
            ans = div;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_div_score(nums: Vec<i32>, divisors: Vec<i32>) -> i32 {
        let mut ans = divisors[0];
        let mut mx = 0;

        for &div in &divisors {
            let mut cnt = 0;

            for &n in &nums {
                if n % div == 0 {
                    cnt += 1;
                }
            }

            if cnt > mx || (cnt >= mx && div < ans) {
                mx = cnt;
                ans = div;
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

<p>给你两个整数数组 <code>nums</code> 和 <code>divisors</code> 。</p>

<p><code>divisors[i]</code> 的 <strong>可整除性得分</strong> 等于满足 <code>nums[j]</code> 能被 <code>divisors[i]</code> 整除的下标 <code>j</code> 的数量。</p>

<p>返回 <strong>可整除性得分</strong> 最大的整数 <code>divisors[i]</code> 。如果有多个整数具有最大得分，则返回数值最小的一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,9,15,50], divisors = [5,3,7,2]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><code>divisors[0]</code>&nbsp;的可整除性分数为 2 因为&nbsp;<code>nums[2]</code> 和&nbsp;<code>nums[3]</code>&nbsp;能被 5 整除。</p>

<p><code>divisors[1]</code> 的可整除性分数为 2 因为&nbsp;<code>nums[1]</code>&nbsp;和&nbsp;<code>nums[2]</code>&nbsp;能被 3 整除。</p>

<p><code>divisors[2]</code> 的可整除性分数为 0 因为&nbsp;<code>nums</code>&nbsp;中没有数字能被 7 整除。</p>

<p><code>divisors[3]</code> 的可整除性分数为 2 因为 <code>nums[0]</code> 和&nbsp;<code>nums[3]</code>&nbsp;能够被 2 整除。</p>

<p>因为&nbsp;<code>divisors[0]</code>&nbsp;、<code>divisor[1]</code> 和&nbsp;<code>divisors[3]</code>&nbsp;有相同的可整除性分数，我们返回更小的那个&nbsp;<code>divisors[3]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,7,9,3,9], divisors = [5,2,3]</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>divisors[0]</code> 的可整除性分数为 0&nbsp;因为&nbsp;<code>nums</code>&nbsp;中没有数字能被 5 整除。</p>

<p><code>divisors[1]</code> 的可整除性分数为 1 因为只有 <code>nums[0]</code>&nbsp;能被 2 整除。</p>

<p><code>divisors[2]</code> 的可整除性分数为 3 因为&nbsp;<code>nums[2]</code>&nbsp;，<code>nums[3]</code>&nbsp;和&nbsp;<code>nums[4]</code>&nbsp;能被 3 整除。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [20,14,21,10], divisors = [10,16,20]</span></p>

<p><strong>输出：</strong><span class="example-io">10</span></p>

<p><strong>解释：</strong></p>

<p><code>divisors[0]</code> 的可整除性分数为 2 因为&nbsp;<code>nums[0]</code>&nbsp;和&nbsp;<code>nums[3]</code> 能被 10 整除。</p>

<p><code>divisors[1]</code> 的可整除性分数为 0 因为&nbsp;<code>nums</code>&nbsp;中没有数字能被 16&nbsp;整除。</p>

<p><code>divisors[2]</code> 的可整除性分数为 1 因为&nbsp;<code>nums[0]</code>&nbsp;能被 20&nbsp;整除。</p>

<p>因为&nbsp;<code>divisors[0]</code>&nbsp;的可整除性分数最大，我们返回&nbsp;<code>divisors[0]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, divisors.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], divisors[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举 $divisors$ 中的每个元素 $div$，计算 $nums$ 中有多少个元素能被 $div$ 整除，记为 $cnt$。

-   如果 $cnt$ 大于当前最大的可整除性得分 $mx$，则更新 $mx = cnt$，并且更新 $ans = div$。
-   如果 $cnt$ 等于 $mx$ 并且 $div$ 小于 $ans$，则更新 $ans = div$。

最后返回 $ans$ 即可。

时间复杂度 $(m \times n)$，其中 $m$ 和 $n$ 分别是 $nums$ 和 $divisors$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        ans, mx = divisors[0], 0
        for div in divisors:
            cnt = sum(x % div == 0 for x in nums)
            if mx < cnt:
                mx, ans = cnt, div
            elif mx == cnt and ans > div:
                ans = div
        return ans
```

#### Java

```java
class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                if (x % div == 0) {
                    ++cnt;
                }
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = Math.min(ans, div);
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0];
        int mx = 0;
        for (int div : divisors) {
            int cnt = 0;
            for (int x : nums) {
                cnt += x % div == 0;
            }
            if (mx < cnt) {
                mx = cnt;
                ans = div;
            } else if (mx == cnt) {
                ans = min(ans, div);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxDivScore(nums []int, divisors []int) int {
	ans, mx := divisors[0], 0
	for _, div := range divisors {
		cnt := 0
		for _, x := range nums {
			if x%div == 0 {
				cnt++
			}
		}
		if mx < cnt {
			ans, mx = div, cnt
		} else if mx == cnt && ans > div {
			ans = div
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxDivScore(nums: number[], divisors: number[]): number {
    let ans: number = divisors[0];
    let mx: number = 0;
    for (const div of divisors) {
        const cnt = nums.reduce((a, b) => a + (b % div == 0 ? 1 : 0), 0);
        if (mx < cnt) {
            mx = cnt;
            ans = div;
        } else if (mx === cnt && ans > div) {
            ans = div;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_div_score(nums: Vec<i32>, divisors: Vec<i32>) -> i32 {
        let mut ans = divisors[0];
        let mut mx = 0;

        for &div in &divisors {
            let mut cnt = 0;

            for &n in &nums {
                if n % div == 0 {
                    cnt += 1;
                }
            }

            if cnt > mx || (cnt >= mx && div < ans) {
                mx = cnt;
                ans = div;
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

# [2645. 构造有效字符串的最少插入数](https://leetcode.cn/problems/minimum-additions-to-make-valid-string){#2645}

{{< tabs "2645" >}}

{{% tab "python" %}}
```python
class Solution:
    def addMinimum(self, word: str) -> int:
        s = 'abc'
        ans, n = 0, len(word)
        i = j = 0
        while j < n:
            if word[j] != s[i]:
                ans += 1
            else:
                j += 1
            i = (i + 1) % 3
        if word[-1] != 'c':
            ans += 1 if word[-1] == 'b' else 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int addMinimum(String word) {
        String s = "abc";
        int ans = 0, n = word.length();
        for (int i = 0, j = 0; j < n; i = (i + 1) % 3) {
            if (word.charAt(j) != s.charAt(i)) {
                ++ans;
            } else {
                ++j;
            }
        }
        if (word.charAt(n - 1) != 'c') {
            ans += word.charAt(n - 1) == 'b' ? 1 : 2;
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
    int addMinimum(string word) {
        string s = "abc";
        int ans = 0, n = word.size();
        for (int i = 0, j = 0; j < n; i = (i + 1) % 3) {
            if (word[j] != s[i]) {
                ++ans;
            } else {
                ++j;
            }
        }
        if (word[n - 1] != 'c') {
            ans += word[n - 1] == 'b' ? 1 : 2;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addMinimum(word string) (ans int) {
	s := "abc"
	n := len(word)
	for i, j := 0, 0; j < n; i = (i + 1) % 3 {
		if word[j] != s[i] {
			ans++
		} else {
			j++
		}
	}
	if word[n-1] == 'b' {
		ans++
	} else if word[n-1] == 'a' {
		ans += 2
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addMinimum(word: string): number {
    const s: string = 'abc';
    let ans: number = 0;
    const n: number = word.length;
    for (let i = 0, j = 0; j < n; i = (i + 1) % 3) {
        if (word[j] !== s[i]) {
            ++ans;
        } else {
            ++j;
        }
    }
    if (word[n - 1] === 'b') {
        ++ans;
    } else if (word[n - 1] === 'a') {
        ans += 2;
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

<p>给你一个字符串 <code>word</code> ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 <code>word</code> <strong>有效</strong> 需要插入的最少字母数。</p>

<p>如果字符串可以由 "abc" 串联多次得到，则认为该字符串 <strong>有效</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word = "b"
<strong>输出：</strong>2
<strong>解释：</strong>在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "<strong>a</strong>b<strong>c</strong>" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word = "aaa"
<strong>输出：</strong>6
<strong>解释：</strong>在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "a<strong>bc</strong>a<strong>bc</strong>a<strong>bc</strong>" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word = "abc"
<strong>输出：</strong>0
<strong>解释：</strong>word 已经是有效字符串，不需要进行修改。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> 仅由字母 "a"、"b" 和 "c" 组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

我们定义字符串 $s$ 为 `"abc"`，用指针 $i$ 和 $j$ 分别指向 $s$ 和 $word$。

如果 $word[j] \neq s[i]$，则需要插入 $s[i]$，我们将答案加 $1$；否则，说明 $word[j]$ 可以与 $s[i]$ 匹配，我们将 $j$ 右移一位。

然后，我们将 $i$ 右移一位，即 $i = (i + 1) \bmod 3$。继续上述操作，直到 $j$ 到达字符串 $word$ 的末尾。

最后，我们判断 $word$ 的最后一个字符是否为 `'b'` 或者 `'a'`，如果是，则需要插入 `'c'` 或者 `'bc'`，我们将答案加 $1$ 或者 $2$ 后返回即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $word$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addMinimum(self, word: str) -> int:
        s = 'abc'
        ans, n = 0, len(word)
        i = j = 0
        while j < n:
            if word[j] != s[i]:
                ans += 1
            else:
                j += 1
            i = (i + 1) % 3
        if word[-1] != 'c':
            ans += 1 if word[-1] == 'b' else 2
        return ans
```

#### Java

```java
class Solution {
    public int addMinimum(String word) {
        String s = "abc";
        int ans = 0, n = word.length();
        for (int i = 0, j = 0; j < n; i = (i + 1) % 3) {
            if (word.charAt(j) != s.charAt(i)) {
                ++ans;
            } else {
                ++j;
            }
        }
        if (word.charAt(n - 1) != 'c') {
            ans += word.charAt(n - 1) == 'b' ? 1 : 2;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int addMinimum(string word) {
        string s = "abc";
        int ans = 0, n = word.size();
        for (int i = 0, j = 0; j < n; i = (i + 1) % 3) {
            if (word[j] != s[i]) {
                ++ans;
            } else {
                ++j;
            }
        }
        if (word[n - 1] != 'c') {
            ans += word[n - 1] == 'b' ? 1 : 2;
        }
        return ans;
    }
};
```

#### Go

```go
func addMinimum(word string) (ans int) {
	s := "abc"
	n := len(word)
	for i, j := 0, 0; j < n; i = (i + 1) % 3 {
		if word[j] != s[i] {
			ans++
		} else {
			j++
		}
	}
	if word[n-1] == 'b' {
		ans++
	} else if word[n-1] == 'a' {
		ans += 2
	}
	return
}
```

#### TypeScript

```ts
function addMinimum(word: string): number {
    const s: string = 'abc';
    let ans: number = 0;
    const n: number = word.length;
    for (let i = 0, j = 0; j < n; i = (i + 1) % 3) {
        if (word[j] !== s[i]) {
            ++ans;
        } else {
            ++j;
        }
    }
    if (word[n - 1] === 'b') {
        ++ans;
    } else if (word[n - 1] === 'a') {
        ans += 2;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2646. 最小化旅行的价格总和](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips){#2646}

{{< tabs "2646" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTotalPrice(
        self, n: int, edges: List[List[int]], price: List[int], trips: List[List[int]]
    ) -> int:
        def dfs(i: int, fa: int, k: int) -> bool:
            cnt[i] += 1
            if i == k:
                return True
            ok = any(j != fa and dfs(j, i, k) for j in g[i])
            if not ok:
                cnt[i] -= 1
            return ok

        def dfs2(i: int, fa: int) -> (int, int):
            a = cnt[i] * price[i]
            b = a // 2
            for j in g[i]:
                if j != fa:
                    x, y = dfs2(j, i)
                    a += min(x, y)
                    b += x
            return a, b

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        cnt = Counter()
        for start, end in trips:
            dfs(start, -1, end)
        return min(dfs2(0, -1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] price;
    private int[] cnt;

    public int minimumTotalPrice(int n, int[][] edges, int[] price, int[][] trips) {
        this.price = price;
        cnt = new int[n];
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (var t : trips) {
            int start = t[0], end = t[1];
            dfs(start, -1, end);
        }
        int[] ans = dfs2(0, -1);
        return Math.min(ans[0], ans[1]);
    }

    private boolean dfs(int i, int fa, int k) {
        ++cnt[i];
        if (i == k) {
            return true;
        }
        boolean ok = false;
        for (int j : g[i]) {
            if (j != fa) {
                ok = dfs(j, i, k);
                if (ok) {
                    break;
                }
            }
        }
        if (!ok) {
            --cnt[i];
        }
        return ok;
    }

    private int[] dfs2(int i, int fa) {
        int a = cnt[i] * price[i];
        int b = a >> 1;
        for (int j : g[i]) {
            if (j != fa) {
                var t = dfs2(j, i);
                a += Math.min(t[0], t[1]);
                b += t[0];
            }
        }
        return new int[] {a, b};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        vector<int> cnt(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<bool(int, int, int)> dfs = [&](int i, int fa, int k) -> bool {
            ++cnt[i];
            if (i == k) {
                return true;
            }
            bool ok = false;
            for (int j : g[i]) {
                if (j != fa) {
                    ok = dfs(j, i, k);
                    if (ok) {
                        break;
                    }
                }
            }
            if (!ok) {
                --cnt[i];
            }
            return ok;
        };
        function<pair<int, int>(int, int)> dfs2 = [&](int i, int fa) -> pair<int, int> {
            int a = cnt[i] * price[i];
            int b = a >> 1;
            for (int j : g[i]) {
                if (j != fa) {
                    auto [x, y] = dfs2(j, i);
                    a += min(x, y);
                    b += x;
                }
            }
            return {a, b};
        };
        for (auto& t : trips) {
            int start = t[0], end = t[1];
            dfs(start, -1, end);
        }
        auto [a, b] = dfs2(0, -1);
        return min(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTotalPrice(n int, edges [][]int, price []int, trips [][]int) int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	cnt := make([]int, n)
	var dfs func(int, int, int) bool
	dfs = func(i, fa, k int) bool {
		cnt[i]++
		if i == k {
			return true
		}
		ok := false
		for _, j := range g[i] {
			if j != fa {
				ok = dfs(j, i, k)
				if ok {
					break
				}
			}
		}
		if !ok {
			cnt[i]--
		}
		return ok
	}
	for _, t := range trips {
		start, end := t[0], t[1]
		dfs(start, -1, end)
	}
	var dfs2 func(int, int) (int, int)
	dfs2 = func(i, fa int) (int, int) {
		a := price[i] * cnt[i]
		b := a >> 1
		for _, j := range g[i] {
			if j != fa {
				x, y := dfs2(j, i)
				a += min(x, y)
				b += x
			}
		}
		return a, b
	}
	a, b := dfs2(0, -1)
	return min(a, b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTotalPrice(
    n: number,
    edges: number[][],
    price: number[],
    trips: number[][],
): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const cnt: number[] = new Array(n).fill(0);
    const dfs = (i: number, fa: number, k: number): boolean => {
        ++cnt[i];
        if (i === k) {
            return true;
        }
        let ok = false;
        for (const j of g[i]) {
            if (j !== fa) {
                ok = dfs(j, i, k);
                if (ok) {
                    break;
                }
            }
        }
        if (!ok) {
            --cnt[i];
        }
        return ok;
    };
    for (const [start, end] of trips) {
        dfs(start, -1, end);
    }
    const dfs2 = (i: number, fa: number): number[] => {
        let a: number = price[i] * cnt[i];
        let b: number = a >> 1;
        for (const j of g[i]) {
            if (j !== fa) {
                const [x, y] = dfs2(j, i);
                a += Math.min(x, y);
                b += x;
            }
        }
        return [a, b];
    };
    const [a, b] = dfs2(0, -1);
    return Math.min(a, b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一棵无向、无根的树，树中有 <code>n</code> 个节点，按从 <code>0</code> 到 <code>n - 1</code> 编号。给你一个整数 <code>n</code> 和一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code> ，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条边。</p>

<p>每个节点都关联一个价格。给你一个整数数组 <code>price</code> ，其中 <code>price[i]</code> 是第 <code>i</code> 个节点的价格。</p>

<p>给定路径的 <strong>价格总和</strong> 是该路径上所有节点的价格之和。</p>

<p>另给你一个二维整数数组 <code>trips</code> ，其中 <code>trips[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示您从节点 <code>start<sub>i</sub></code> 开始第 <code>i</code> 次旅行，并通过任何你喜欢的路径前往节点 <code>end<sub>i</sub></code> 。</p>

<p>在执行第一次旅行之前，你可以选择一些 <strong>非相邻节点</strong> 并将价格减半。</p>

<p>返回执行所有旅行的最小价格总和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2646.Minimize%20the%20Total%20Price%20of%20the%20Trips/images/diagram2.png" style="width: 541px; height: 181px;">
<pre><strong>输入：</strong>n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
<strong>输出：</strong>23
<strong>解释：
</strong>上图表示将节点 2 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 、2 和 3 并使其价格减半后的树。
第 1 次旅行，选择路径 [0,1,3] 。路径的价格总和为 1 + 2 + 3 = 6 。
第 2 次旅行，选择路径 [2,1] 。路径的价格总和为 2 + 5 = 7 。
第 3 次旅行，选择路径 [2,1,3] 。路径的价格总和为 5 + 2 + 3 = 10 。
所有旅行的价格总和为 6 + 7 + 10 = 23 。可以证明，23 是可以实现的最小答案。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2646.Minimize%20the%20Total%20Price%20of%20the%20Trips/images/diagram3.png" style="width: 456px; height: 111px;">
<pre><strong>输入：</strong>n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
<strong>输出：</strong>1
<strong>解释：</strong>
上图表示将节点 0 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 并使其价格减半后的树。 
第 1 次旅行，选择路径 [0] 。路径的价格总和为 1 。 
所有旅行的价格总和为 1 。可以证明，1 是可以实现的最小答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>edges</code> 表示一棵有效的树</li>
	<li><code>price.length == n</code></li>
	<li><code>price[i]</code> 是一个偶数</li>
	<li><code>1 &lt;= price[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= trips.length &lt;= 100</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP

我们可以统计每一次旅行经过的节点，记录在数组 $cnt$ 中，其中 $cnt[i]$ 表示所有旅行中经过节点 $i$ 的次数。我们设计一个函数 $dfs(i, fa, k)$，表示从节点 $i$ 开始搜索，最终到达节点 $k$，过程中记录所有经过的节点。其中 $fa$ 表示节点 $i$ 的父节点。

接下来，我们再设计一个函数 $dfs2(i, fa)$，表示从节点 $i$ 开始搜索，返回将节点 $i$ 的价格不减半或者减半后的最小价格总和。其中 $fa$ 表示节点 $i$ 的父节点。

我们从节点 $0$ 开始，对于每一个节点 $i$，我们可以选择不将其价格减半，也可以选择将其价格减半，分别记为 $a = cnt[i] \times price[i]$, $b = \frac{a}{2}$。

对于节点 $i$ 的所有邻接节点 $j$，我们依然可以选择不将其价格减半，也可以选择将其价格减半，那么 $(x, y) = dfs2(j, i)$。如果节点 $i$ 价格不减半，那么节点 $j$ 价格可以不减半，也可以减半，因此 $a = a + \min(x, y)$；如果节点 $i$ 价格减半，那么节点 $j$ 价格必须不减半，因此 $b = b + x$。

最后，函数 $dfs2(i, fa)$ 的返回值为 $(a, b)$。

在主函数中，我们调用函数 $dfs2(0, -1)$，返回值为 $(a, b)$，那么最终的答案即为 $\min(a, b)$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别为旅行次数以及节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTotalPrice(
        self, n: int, edges: List[List[int]], price: List[int], trips: List[List[int]]
    ) -> int:
        def dfs(i: int, fa: int, k: int) -> bool:
            cnt[i] += 1
            if i == k:
                return True
            ok = any(j != fa and dfs(j, i, k) for j in g[i])
            if not ok:
                cnt[i] -= 1
            return ok

        def dfs2(i: int, fa: int) -> (int, int):
            a = cnt[i] * price[i]
            b = a // 2
            for j in g[i]:
                if j != fa:
                    x, y = dfs2(j, i)
                    a += min(x, y)
                    b += x
            return a, b

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        cnt = Counter()
        for start, end in trips:
            dfs(start, -1, end)
        return min(dfs2(0, -1))
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] price;
    private int[] cnt;

    public int minimumTotalPrice(int n, int[][] edges, int[] price, int[][] trips) {
        this.price = price;
        cnt = new int[n];
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (var t : trips) {
            int start = t[0], end = t[1];
            dfs(start, -1, end);
        }
        int[] ans = dfs2(0, -1);
        return Math.min(ans[0], ans[1]);
    }

    private boolean dfs(int i, int fa, int k) {
        ++cnt[i];
        if (i == k) {
            return true;
        }
        boolean ok = false;
        for (int j : g[i]) {
            if (j != fa) {
                ok = dfs(j, i, k);
                if (ok) {
                    break;
                }
            }
        }
        if (!ok) {
            --cnt[i];
        }
        return ok;
    }

    private int[] dfs2(int i, int fa) {
        int a = cnt[i] * price[i];
        int b = a >> 1;
        for (int j : g[i]) {
            if (j != fa) {
                var t = dfs2(j, i);
                a += Math.min(t[0], t[1]);
                b += t[0];
            }
        }
        return new int[] {a, b};
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        vector<int> cnt(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<bool(int, int, int)> dfs = [&](int i, int fa, int k) -> bool {
            ++cnt[i];
            if (i == k) {
                return true;
            }
            bool ok = false;
            for (int j : g[i]) {
                if (j != fa) {
                    ok = dfs(j, i, k);
                    if (ok) {
                        break;
                    }
                }
            }
            if (!ok) {
                --cnt[i];
            }
            return ok;
        };
        function<pair<int, int>(int, int)> dfs2 = [&](int i, int fa) -> pair<int, int> {
            int a = cnt[i] * price[i];
            int b = a >> 1;
            for (int j : g[i]) {
                if (j != fa) {
                    auto [x, y] = dfs2(j, i);
                    a += min(x, y);
                    b += x;
                }
            }
            return {a, b};
        };
        for (auto& t : trips) {
            int start = t[0], end = t[1];
            dfs(start, -1, end);
        }
        auto [a, b] = dfs2(0, -1);
        return min(a, b);
    }
};
```

#### Go

```go
func minimumTotalPrice(n int, edges [][]int, price []int, trips [][]int) int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	cnt := make([]int, n)
	var dfs func(int, int, int) bool
	dfs = func(i, fa, k int) bool {
		cnt[i]++
		if i == k {
			return true
		}
		ok := false
		for _, j := range g[i] {
			if j != fa {
				ok = dfs(j, i, k)
				if ok {
					break
				}
			}
		}
		if !ok {
			cnt[i]--
		}
		return ok
	}
	for _, t := range trips {
		start, end := t[0], t[1]
		dfs(start, -1, end)
	}
	var dfs2 func(int, int) (int, int)
	dfs2 = func(i, fa int) (int, int) {
		a := price[i] * cnt[i]
		b := a >> 1
		for _, j := range g[i] {
			if j != fa {
				x, y := dfs2(j, i)
				a += min(x, y)
				b += x
			}
		}
		return a, b
	}
	a, b := dfs2(0, -1)
	return min(a, b)
}
```

#### TypeScript

```ts
function minimumTotalPrice(
    n: number,
    edges: number[][],
    price: number[],
    trips: number[][],
): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const cnt: number[] = new Array(n).fill(0);
    const dfs = (i: number, fa: number, k: number): boolean => {
        ++cnt[i];
        if (i === k) {
            return true;
        }
        let ok = false;
        for (const j of g[i]) {
            if (j !== fa) {
                ok = dfs(j, i, k);
                if (ok) {
                    break;
                }
            }
        }
        if (!ok) {
            --cnt[i];
        }
        return ok;
    };
    for (const [start, end] of trips) {
        dfs(start, -1, end);
    }
    const dfs2 = (i: number, fa: number): number[] => {
        let a: number = price[i] * cnt[i];
        let b: number = a >> 1;
        for (const j of g[i]) {
            if (j !== fa) {
                const [x, y] = dfs2(j, i);
                a += Math.min(x, y);
                b += x;
            }
        }
        return [a, b];
    };
    const [a, b] = dfs2(0, -1);
    return Math.min(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2647. 把三角形染成红色 🔒](https://leetcode.cn/problems/color-the-triangle-red){#2647}

{{< tabs "2647" >}}

{{% tab "python" %}}
```python
class Solution:
    def colorRed(self, n: int) -> List[List[int]]:
        ans = [[1, 1]]
        k = 0
        for i in range(n, 1, -1):
            if k == 0:
                for j in range(1, i << 1, 2):
                    ans.append([i, j])
            elif k == 1:
                ans.append([i, 2])
            elif k == 2:
                for j in range(3, i << 1, 2):
                    ans.append([i, j])
            else:
                ans.append([i, 1])
            k = (k + 1) % 4
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] colorRed(int n) {
        List<int[]> ans = new ArrayList<>();
        ans.add(new int[] {1, 1});
        for (int i = n, k = 0; i > 1; --i, k = (k + 1) % 4) {
            if (k == 0) {
                for (int j = 1; j < i << 1; j += 2) {
                    ans.add(new int[] {i, j});
                }
            } else if (k == 1) {
                ans.add(new int[] {i, 2});
            } else if (k == 2) {
                for (int j = 3; j < i << 1; j += 2) {
                    ans.add(new int[] {i, j});
                }
            } else {
                ans.add(new int[] {i, 1});
            }
        }
        return ans.toArray(new int[0][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        vector<vector<int>> ans;
        ans.push_back({1, 1});
        for (int i = n, k = 0; i > 1; --i, k = (k + 1) % 4) {
            if (k == 0) {
                for (int j = 1; j < i << 1; j += 2) {
                    ans.push_back({i, j});
                }
            } else if (k == 1) {
                ans.push_back({i, 2});
            } else if (k == 2) {
                for (int j = 3; j < i << 1; j += 2) {
                    ans.push_back({i, j});
                }
            } else {
                ans.push_back({i, 1});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func colorRed(n int) (ans [][]int) {
	ans = append(ans, []int{1, 1})
	for i, k := n, 0; i > 1; i, k = i-1, (k+1)%4 {
		if k == 0 {
			for j := 1; j < i<<1; j += 2 {
				ans = append(ans, []int{i, j})
			}
		} else if k == 1 {
			ans = append(ans, []int{i, 2})
		} else if k == 2 {
			for j := 3; j < i<<1; j += 2 {
				ans = append(ans, []int{i, j})
			}
		} else {
			ans = append(ans, []int{i, 1})
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function colorRed(n: number): number[][] {
    const ans: number[][] = [[1, 1]];
    for (let i = n, k = 0; i > 1; --i, k = (k + 1) % 4) {
        if (k === 0) {
            for (let j = 1; j < i << 1; j += 2) {
                ans.push([i, j]);
            }
        } else if (k === 1) {
            ans.push([i, 2]);
        } else if (k === 2) {
            for (let j = 3; j < i << 1; j += 2) {
                ans.push([i, j]);
            }
        } else {
            ans.push([i, 1]);
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

<p>现给定你一个整数 <code>n</code> 。考虑一个边长为 <code>n</code> 的等边三角形，被分成 <code>n<sup>2</sup></code> 个单位等边三角形。这个三角形有 <code>n</code> 个 <strong>从 1 开始编号</strong> 的行，其中第 <code>i</code> 行有 <code>2i - 1</code> 个单位等边三角形。</p>

<p>第 <code>i</code> 行的三角形也是&nbsp;<strong>从 1 开始编号&nbsp;</strong>的，其坐标从 <code>(i, 1)</code> 到 <code>(i, 2i - 1)</code>&nbsp;。下面的图像显示了一个边长为 <code>4</code> 的三角形及其三角形的索引。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2647.Color%20the%20Triangle%20Red/images/triangle4.jpg" style="width: 402px; height: 242px;" />
<p>如果两个三角形 <strong>共享一条边</strong> ，则它们是 <strong>相邻</strong> 的。例如：</p>

<ul>
	<li>三角形 <code>(1,1)</code> 和 <code>(2,2)</code> 是相邻的。</li>
	<li>三角形 <code>(3,2)</code> 和 <code>(3,3)</code> 是相邻的。</li>
	<li>三角形 <code>(2,2)</code> 和 <code>(3,3)</code> 不相邻，因为它们没有共享任何边。</li>
</ul>

<p>初始时，所有单位三角形都是 <strong>白色</strong> 的。你想选择 <code>k</code> 个三角形并将它们涂成 <strong>红色</strong> 。然后我们将运行以下算法：</p>

<ol>
	<li>选择一个 <strong>至少有两个</strong> 红色相邻三角形的白色三角形。

    <ul>
    	<li>如果没有这样的三角形，请停止算法。</li>
    </ul>
    </li>
    <li>将该三角形涂成 <strong>红色</strong> 。</li>
    <li>回到步骤 1。</li>

</ol>

<p>选择最小的 <code>k</code> 并在运行此算法之前将 <code>k</code> 个三角形涂成红色，使得在算法停止后，所有单元三角形都被涂成红色。</p>

<p>返回一个二维列表，其中包含你要最初涂成红色的三角形的坐标。答案必须尽可能小。如果有多个有效的解决方案，请返回其中任意一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2647.Color%20the%20Triangle%20Red/images/example1.jpg" style="width: 500px; height: 263px;" />
<pre>
<b>输入：</b>n = 3
<b>输出：</b>[[1,1],[2,1],[2,3],[3,1],[3,5]]
<b>解释：</b>初始时，我们选择展示的5个三角形染成红色。然后，我们运行以下算法：
- 选择(2,2)，它有三个红色相邻的三角形，并将其染成红色。
- 选择(3,2)，它有两个红色相邻的三角形，并将其染成红色。
- 选择(3,4)，它有三个红色相邻的三角形，并将其染成红色。
- 选择(3,3)，它有三个红色相邻的三角形，并将其染成红色。 
可以证明，选择任何4个三角形并运行算法都无法将所有三角形都染成红色。</pre>

<p><strong class="example">示例 2 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2647.Color%20the%20Triangle%20Red/images/example2.jpg" style="width: 300px; height: 101px;" />
<pre>
<b>输入：</b>n = 2
<b>输出：</b>[[1,1],[2,1],[2,3]]
<b>解释：</b>初始时，我们选择图中所示的 3 个三角形为红色。然后，我们运行以下算法： 
-选择有三个红色相邻的 (2,2) 三角形并将其染成红色。 
可以证明，选择任意 2 个三角形并运行该算法都不能使所有三角形变为红色。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：找规律

我们画图观察，可以发现，第一行只有一个三角形，一定要涂色，而从最后一行开始，到第二行结束，每四行的涂色方案是一样的：

1. 最后一行涂色坐标为 $(n, 1)$, $(n, 3)$, ..., $(n, 2n - 1)$。
1. 第 $n - 1$ 行涂色坐标为 $(n - 1, 2)$。
1. 第 $n - 2$ 行涂色坐标为 $(n - 2, 3)$, $(n - 2, 5)$, ..., $(n - 2, 2n - 5)$。
1. 第 $n - 3$ 行涂色坐标为 $(n - 3, 1)$。

<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2647.Color%20the%20Triangle%20Red/images/demo3.png" style="width: 50%">

因此，我们可以按照上述规律，先给第一行涂色，然后从最后一行开始，每四行涂色一次，直到第二行结束。

<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2647.Color%20the%20Triangle%20Red/images/demo2.png" style="width: 80%">

时间复杂度 $(n^2)$，其中 $n$ 为题目给定的参数。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def colorRed(self, n: int) -> List[List[int]]:
        ans = [[1, 1]]
        k = 0
        for i in range(n, 1, -1):
            if k == 0:
                for j in range(1, i << 1, 2):
                    ans.append([i, j])
            elif k == 1:
                ans.append([i, 2])
            elif k == 2:
                for j in range(3, i << 1, 2):
                    ans.append([i, j])
            else:
                ans.append([i, 1])
            k = (k + 1) % 4
        return ans
```

#### Java

```java
class Solution {
    public int[][] colorRed(int n) {
        List<int[]> ans = new ArrayList<>();
        ans.add(new int[] {1, 1});
        for (int i = n, k = 0; i > 1; --i, k = (k + 1) % 4) {
            if (k == 0) {
                for (int j = 1; j < i << 1; j += 2) {
                    ans.add(new int[] {i, j});
                }
            } else if (k == 1) {
                ans.add(new int[] {i, 2});
            } else if (k == 2) {
                for (int j = 3; j < i << 1; j += 2) {
                    ans.add(new int[] {i, j});
                }
            } else {
                ans.add(new int[] {i, 1});
            }
        }
        return ans.toArray(new int[0][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        vector<vector<int>> ans;
        ans.push_back({1, 1});
        for (int i = n, k = 0; i > 1; --i, k = (k + 1) % 4) {
            if (k == 0) {
                for (int j = 1; j < i << 1; j += 2) {
                    ans.push_back({i, j});
                }
            } else if (k == 1) {
                ans.push_back({i, 2});
            } else if (k == 2) {
                for (int j = 3; j < i << 1; j += 2) {
                    ans.push_back({i, j});
                }
            } else {
                ans.push_back({i, 1});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func colorRed(n int) (ans [][]int) {
	ans = append(ans, []int{1, 1})
	for i, k := n, 0; i > 1; i, k = i-1, (k+1)%4 {
		if k == 0 {
			for j := 1; j < i<<1; j += 2 {
				ans = append(ans, []int{i, j})
			}
		} else if k == 1 {
			ans = append(ans, []int{i, 2})
		} else if k == 2 {
			for j := 3; j < i<<1; j += 2 {
				ans = append(ans, []int{i, j})
			}
		} else {
			ans = append(ans, []int{i, 1})
		}
	}
	return
}
```

#### TypeScript

```ts
function colorRed(n: number): number[][] {
    const ans: number[][] = [[1, 1]];
    for (let i = n, k = 0; i > 1; --i, k = (k + 1) % 4) {
        if (k === 0) {
            for (let j = 1; j < i << 1; j += 2) {
                ans.push([i, j]);
            }
        } else if (k === 1) {
            ans.push([i, 2]);
        } else if (k === 2) {
            for (let j = 3; j < i << 1; j += 2) {
                ans.push([i, j]);
            }
        } else {
            ans.push([i, 1]);
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

# [2648. 生成斐波那契数列](https://leetcode.cn/problems/generate-fibonacci-sequence){#2648}

{{< tabs "2648" >}}

{{% tab "ts" %}}
```ts
function* fibGenerator(): Generator<number, any, number> {
    let a = 0;
    let b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个生成器函数，并返回一个可以生成 <strong>斐波那契数列</strong> 的生成器对象。</p>

<p><strong>斐波那契数列</strong> 的递推公式为 <code>X<sub>n</sub>&nbsp;= X<sub>n-1</sub>&nbsp;+ X<sub>n-2</sub></code> 。</p>

<p>这个数列的前几个数字是 <code>0, 1, 1, 2, 3, 5, 8, 13</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>callCount = 5
<b>输出：</b>[0,1,1,2,3]
<strong>解释：</strong>
const gen = fibGenerator();
gen.next().value; // 0
gen.next().value; // 1
gen.next().value; // 1
gen.next().value; // 2
gen.next().value; // 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>callCount = 0
<strong>输出：</strong>[]
<b>解释：</b>gen.next() 永远不会被调用，所以什么也不会输出
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= callCount &lt;= 50</code></li>
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

#### TypeScript

```ts
function* fibGenerator(): Generator<number, any, number> {
    let a = 0;
    let b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2649. 嵌套数组生成器](https://leetcode.cn/problems/nested-array-generator){#2649}

{{< tabs "2649" >}}

{{% tab "ts" %}}
```ts
type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    for (const e of arr) {
        if (Array.isArray(e)) {
            yield* inorderTraversal(e);
        } else {
            yield e;
        }
    }
}

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个整数的 <strong>多维数组</strong> ，请你返回一个生成器对象，按照&nbsp;<strong>中序遍历</strong> 的顺序逐个生成整数。</p>

<p><strong>多维数组</strong> 是一个递归数据结构，包含整数和其他 <strong>多维数组</strong>。</p>

<p><strong>中序遍历</strong> 是从左到右遍历每个数组，在遇到任何整数时生成它，遇到任何数组时递归应用 <strong>中序遍历</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [[[6]],[1,3],[]]
<b>输出：</b>[6,1,3]
<strong>解释：</strong>
const generator = inorderTraversal(arr);
generator.next().value; // 6
generator.next().value; // 1
generator.next().value; // 3
generator.next().done; // true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arr = []
<b>输出：</b>[]
<b>解释：</b>输入的多维数组没有任何参数，所以生成器不需要生成任何值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.flat().length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr.flat()[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>maxNestingDepth &lt;= 10<sup>5</sup></code></li>
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

#### TypeScript

```ts
type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    for (const e of arr) {
        if (Array.isArray(e)) {
            yield* inorderTraversal(e);
        } else {
            yield e;
        }
    }
}

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
