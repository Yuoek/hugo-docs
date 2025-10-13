---
title: "0970_强整数"
date: 2025-10-08T18:36:43+08:00
weight: 8
tags: [二叉树, 几何, 分治, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 堆（优先队列）, 字符串, 快速选择, 排序, 数学, 数组, 有序集合, 枚举, 栈, 树, 深度优先搜索, 滑动窗口, 贪心]
---

{{< markmap >}}
### [0970_强整数](#970)
#### [哈希表](#970)
#### [数学](#970)
#### [枚举](#970)
### [0971_翻转二叉树以匹配先序遍历](#971)
#### [树](#971)
#### [深度优先搜索](#971)
#### [二叉树](#971)
### [0972_相等的有理数](#972)
#### [数学](#972)
#### [字符串](#972)
### [0973_最接近原点的 K 个点](#973)
#### [几何](#973)
#### [数组](#973)
#### [数学](#973)
#### [分治](#973)
#### [快速选择](#973)
#### [排序](#973)
#### [堆（优先队列）](#973)
### [0974_和可被 K 整除的子数组](#974)
#### [数组](#974)
#### [哈希表](#974)
#### [前缀和](#974)
### [0975_奇偶跳](#975)
#### [栈](#975)
#### [数组](#975)
#### [动态规划](#975)
#### [有序集合](#975)
#### [排序](#975)
#### [单调栈](#975)
### [0976_三角形的最大周长](#976)
#### [贪心](#976)
#### [数组](#976)
#### [数学](#976)
#### [排序](#976)
### [0977_有序数组的平方](#977)
#### [数组](#977)
#### [双指针](#977)
#### [排序](#977)
### [0978_最长湍流子数组](#978)
#### [数组](#978)
#### [动态规划](#978)
#### [滑动窗口](#978)
### [0979_在二叉树中分配硬币](#979)
#### [树](#979)
#### [深度优先搜索](#979)
#### [二叉树](#979)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0970_强整数
___
#### 哈希表
___
#### 数学
___
#### 枚举
---
### 0971_翻转二叉树以匹配先序遍历
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0972_相等的有理数
___
#### 数学
___
#### 字符串
---
### 0973_最接近原点的 K 个点
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 分治
___
#### 快速选择
___
#### 排序
___
#### 堆（优先队列）
---
### 0974_和可被 K 整除的子数组
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 0975_奇偶跳
___
#### 栈
___
#### 数组
___
#### 动态规划
___
#### 有序集合
___
#### 排序
___
#### 单调栈
---
### 0976_三角形的最大周长
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 排序
---
### 0977_有序数组的平方
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0978_最长湍流子数组
___
#### 数组
___
#### 动态规划
___
#### 滑动窗口
---
### 0979_在二叉树中分配硬币
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 几何 | 分治 |
| 前缀和 | 动态规划 | 单调栈 |
| 双指针 | 哈希表 | 堆（优先队列） |
| 字符串 | 快速选择 | 排序 |
| 数学 | 数组 | 有序集合 |
| 枚举 | 栈 | 树 |
| 深度优先搜索 | 滑动窗口 | 贪心 |

# [970. 强整数](https://leetcode.cn/problems/powerful-integers){#970}

{{< tabs "970" >}}

{{% tab "python" %}}
```python
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        ans = set()
        a = 1
        while a <= bound:
            b = 1
            while a + b <= bound:
                ans.add(a + b)
                b *= y
                if y == 1:
                    break
            if x == 1:
                break
            a *= x
        return list(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> ans = new HashSet<>();
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                ans.add(a + b);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        return new ArrayList<>(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                ans.insert(a + b);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func powerfulIntegers(x int, y int, bound int) (ans []int) {
	s := map[int]struct{}{}
	for a := 1; a <= bound; a *= x {
		for b := 1; a+b <= bound; b *= y {
			s[a+b] = struct{}{}
			if y == 1 {
				break
			}
		}
		if x == 1 {
			break
		}
	}
	for x := range s {
		ans = append(ans, x)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function powerfulIntegers(x: number, y: number, bound: number): number[] {
    const ans = new Set<number>();
    for (let a = 1; a <= bound; a *= x) {
        for (let b = 1; a + b <= bound; b *= y) {
            ans.add(a + b);
            if (y === 1) {
                break;
            }
        }
        if (x === 1) {
            break;
        }
    }
    return Array.from(ans);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} x
 * @param {number} y
 * @param {number} bound
 * @return {number[]}
 */
var powerfulIntegers = function (x, y, bound) {
    const ans = new Set();
    for (let a = 1; a <= bound; a *= x) {
        for (let b = 1; a + b <= bound; b *= y) {
            ans.add(a + b);
            if (y === 1) {
                break;
            }
        }
        if (x === 1) {
            break;
        }
    }
    return [...ans];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定三个整数 <code>x</code>&nbsp;、&nbsp;<code>y</code>&nbsp;和<em>&nbsp;</em><code>bound</code><em>&nbsp;</em>，返回 <em>值小于或等于&nbsp;<code>bound</code>&nbsp;的所有&nbsp;<strong>强整数</strong>&nbsp;组成的列表</em>&nbsp;。</p>

<p>如果某一整数可以表示为&nbsp;<code>x<sup>i</sup>&nbsp;+ y<sup>j</sup></code>&nbsp;，其中整数&nbsp;<code>i &gt;= 0</code> 且&nbsp;<code>j &gt;= 0</code>，那么我们认为该整数是一个&nbsp;<strong>强整数</strong>&nbsp;。</p>

<p>你可以按 <strong>任何顺序</strong> 返回答案。在你的回答中，每个值 <strong>最多</strong> 出现一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 2, y = 3, bound = 10
<strong>输出：</strong>[2,3,4,5,7,9,10]
<strong>解释： </strong>
2 = 2<sup>0</sup> + 3<sup>0</sup>
3 = 2<sup>1</sup> + 3<sup>0</sup>
4 = 2<sup>0</sup> + 3<sup>1</sup>
5 = 2<sup>1</sup> + 3<sup>1</sup>
7 = 2<sup>2</sup> + 3<sup>1</sup>
9 = 2<sup>3</sup> + 3<sup>0</sup>
10 = 2<sup>0</sup> + 3<sup>2</sup></pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>x = 3, y = 5, bound = 15
<strong>输出：</strong>[2,4,6,8,10,14]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 100</code></li>
	<li><code>0 &lt;= bound &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

根据题目描述，一个强整数可以表示成 $x^i + y^j$，其中 $i \geq 0$, $j \geq 0$。

题目需要我们找出所有不超过 $bound$ 的强整数，我们注意到 $bound$ 的取值范围不超过 $10^6$，而 $2^{20} = 1048576 \gt 10^6$。因此，如果 $x \geq 2$，那么 $i$ 最大不超过 $20$，才有可能使得 $x^i + y^j \leq bound$ 成立。同理，如果 $y \geq 2$，那么 $j$ 最大不超过 $20$。

因此我们可以使用双重循环，枚举所有可能的 $x^i$ 和 $y^j$，分别记为 $a$ 和 $b$，并保证 $a + b \leq bound$，此时 $a + b$ 即为一个强整数。我们使用哈希表存储所有满足条件的强整数，最后将哈希表中的所有元素转换成答案列表返回即可。

> 注意，如果 $x=1$ 或者 $y=1$，那么 $a$ 或者 $b$ 的值恒等于 $1$，对应的循环只需要执行一次即可退出。

时间复杂度 $O(\log^2 bound)$，空间复杂度 $O(\log^2 bound)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        ans = set()
        a = 1
        while a <= bound:
            b = 1
            while a + b <= bound:
                ans.add(a + b)
                b *= y
                if y == 1:
                    break
            if x == 1:
                break
            a *= x
        return list(ans)
```

#### Java

```java
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> ans = new HashSet<>();
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                ans.add(a + b);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        return new ArrayList<>(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                ans.insert(a + b);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
```

#### Go

```go
func powerfulIntegers(x int, y int, bound int) (ans []int) {
	s := map[int]struct{}{}
	for a := 1; a <= bound; a *= x {
		for b := 1; a+b <= bound; b *= y {
			s[a+b] = struct{}{}
			if y == 1 {
				break
			}
		}
		if x == 1 {
			break
		}
	}
	for x := range s {
		ans = append(ans, x)
	}
	return ans
}
```

#### TypeScript

```ts
function powerfulIntegers(x: number, y: number, bound: number): number[] {
    const ans = new Set<number>();
    for (let a = 1; a <= bound; a *= x) {
        for (let b = 1; a + b <= bound; b *= y) {
            ans.add(a + b);
            if (y === 1) {
                break;
            }
        }
        if (x === 1) {
            break;
        }
    }
    return Array.from(ans);
}
```

#### JavaScript

```js
/**
 * @param {number} x
 * @param {number} y
 * @param {number} bound
 * @return {number[]}
 */
var powerfulIntegers = function (x, y, bound) {
    const ans = new Set();
    for (let a = 1; a <= bound; a *= x) {
        for (let b = 1; a + b <= bound; b *= y) {
            ans.add(a + b);
            if (y === 1) {
                break;
            }
        }
        if (x === 1) {
            break;
        }
    }
    return [...ans];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [971. 翻转二叉树以匹配先序遍历](https://leetcode.cn/problems/flip-binary-tree-to-match-preorder-traversal){#971}

{{< tabs "971" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: List[int]) -> List[int]:
        def dfs(root):
            nonlocal i, ok
            if root is None or not ok:
                return
            if root.val != voyage[i]:
                ok = False
                return
            i += 1
            if root.left is None or root.left.val == voyage[i]:
                dfs(root.left)
                dfs(root.right)
            else:
                ans.append(root.val)
                dfs(root.right)
                dfs(root.left)

        ans = []
        i = 0
        ok = True
        dfs(root)
        return ans if ok else [-1]
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
    private int i;
    private boolean ok;
    private int[] voyage;
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        this.voyage = voyage;
        ok = true;
        dfs(root);
        return ok ? ans : List.of(-1);
    }

    private void dfs(TreeNode root) {
        if (root == null || !ok) {
            return;
        }
        if (root.val != voyage[i]) {
            ok = false;
            return;
        }
        ++i;
        if (root.left == null || root.left.val == voyage[i]) {
            dfs(root.left);
            dfs(root.right);
        } else {
            ans.add(root.val);
            dfs(root.right);
            dfs(root.left);
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        bool ok = true;
        int i = 0;
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root || !ok) {
                return;
            }
            if (root->val != voyage[i]) {
                ok = false;
                return;
            }
            ++i;
            if (!root->left || root->left->val == voyage[i]) {
                dfs(root->left);
                dfs(root->right);
            } else {
                ans.push_back(root->val);
                dfs(root->right);
                dfs(root->left);
            }
        };
        dfs(root);
        return ok ? ans : vector<int>{-1};
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
func flipMatchVoyage(root *TreeNode, voyage []int) []int {
	i := 0
	ok := true
	ans := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil || !ok {
			return
		}
		if root.Val != voyage[i] {
			ok = false
			return
		}
		i++
		if root.Left == nil || root.Left.Val == voyage[i] {
			dfs(root.Left)
			dfs(root.Right)
		} else {
			ans = append(ans, root.Val)
			dfs(root.Right)
			dfs(root.Left)
		}
	}
	dfs(root)
	if !ok {
		return []int{-1}
	}
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

function flipMatchVoyage(root: TreeNode | null, voyage: number[]): number[] {
    let ok = true;
    let i = 0;
    const ans: number[] = [];
    const dfs = (root: TreeNode | null): void => {
        if (!root || !ok) {
            return;
        }
        if (root.val !== voyage[i++]) {
            ok = false;
            return;
        }
        if (!root.left || root.left.val === voyage[i]) {
            dfs(root.left);
            dfs(root.right);
        } else {
            ans.push(root.val);
            dfs(root.right);
            dfs(root.left);
        }
    };
    dfs(root);
    return ok ? ans : [-1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code> ，树中有 <code>n</code> 个节点，每个节点都有一个不同于其他节点且处于 <code>1</code> 到 <code>n</code> 之间的值。</p>

<p>另给你一个由 <code>n</code> 个值组成的行程序列 <code>voyage</code> ，表示 <strong>预期</strong> 的二叉树 <a href="https://baike.baidu.com/item/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86/6442839?fr=aladdin" target="_blank"><strong>先序遍历</strong></a> 结果。</p>

<p>通过交换节点的左右子树，可以 <strong>翻转</strong> 该二叉树中的任意节点。例，翻转节点 1 的效果如下：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0971.Flip%20Binary%20Tree%20To%20Match%20Preorder%20Traversal/images/fliptree.jpg" style="width: 400px; height: 187px;" />
<p>请翻转 <strong>最少 </strong>的树中节点，使二叉树的 <strong>先序遍历</strong> 与预期的遍历行程 <code>voyage</code> <strong>相匹配</strong> 。 </p>

<p>如果可以，则返回 <strong>翻转的</strong> 所有节点的值的列表。你可以按任何顺序返回答案。如果不能，则返回列表 <code>[-1]</code>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0971.Flip%20Binary%20Tree%20To%20Match%20Preorder%20Traversal/images/1219-01.png" style="width: 150px; height: 205px;" />
<pre>
<strong>输入：</strong>root = [1,2], voyage = [2,1]
<strong>输出：</strong>[-1]
<strong>解释：</strong>翻转节点无法令先序遍历匹配预期行程。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0971.Flip%20Binary%20Tree%20To%20Match%20Preorder%20Traversal/images/1219-02.png" style="width: 150px; height: 142px;" />
<pre>
<strong>输入：</strong>root = [1,2,3], voyage = [1,3,2]
<strong>输出：</strong>[1]
<strong>解释：</strong>交换节点 2 和 3 来翻转节点 1 ，先序遍历可以匹配预期行程。</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0971.Flip%20Binary%20Tree%20To%20Match%20Preorder%20Traversal/images/1219-02.png" style="width: 150px; height: 142px;" />
<pre>
<strong>输入：</strong>root = [1,2,3], voyage = [1,2,3]
<strong>输出：</strong>[]
<strong>解释：</strong>先序遍历已经匹配预期行程，所以不需要翻转节点。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数目为 <code>n</code></li>
	<li><code>n == voyage.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>1 <= Node.val, voyage[i] <= n</code></li>
	<li>树中的所有值 <strong>互不相同</strong></li>
	<li><code>voyage</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以通过深度优先搜索的方式遍历整棵树，用一个下标 $i$ 记录当前遍历到的节点在数组 $\textit{voyage}$ 中的下标，如果当前遍历到的节点的值不等于 $\textit{voyage}[i]$，那么说明翻转后无法匹配，我们标记 $\textit{ok}$ 为 `false`，并直接返回。否则，我们将 $i$ 的值加 $1$，然后判断当前节点是否有左子节点，如果没有，或者左子节点的值等于 $\textit{voyage}[i]$，那么我们递归遍历当前的左右子节点；否则，我们需要翻转当前节点，然后再递归遍历当前的右子节点和左子节点。

搜索结束后，如果 $\textit{ok}$ 为 `true`，那么说明翻转后可以匹配，我们返回答案数组 $\textit{ans}$，否则返回 $[-1]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树中的节点数目。

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
    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: List[int]) -> List[int]:
        def dfs(root):
            nonlocal i, ok
            if root is None or not ok:
                return
            if root.val != voyage[i]:
                ok = False
                return
            i += 1
            if root.left is None or root.left.val == voyage[i]:
                dfs(root.left)
                dfs(root.right)
            else:
                ans.append(root.val)
                dfs(root.right)
                dfs(root.left)

        ans = []
        i = 0
        ok = True
        dfs(root)
        return ans if ok else [-1]
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
    private int i;
    private boolean ok;
    private int[] voyage;
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        this.voyage = voyage;
        ok = true;
        dfs(root);
        return ok ? ans : List.of(-1);
    }

    private void dfs(TreeNode root) {
        if (root == null || !ok) {
            return;
        }
        if (root.val != voyage[i]) {
            ok = false;
            return;
        }
        ++i;
        if (root.left == null || root.left.val == voyage[i]) {
            dfs(root.left);
            dfs(root.right);
        } else {
            ans.add(root.val);
            dfs(root.right);
            dfs(root.left);
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        bool ok = true;
        int i = 0;
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root || !ok) {
                return;
            }
            if (root->val != voyage[i]) {
                ok = false;
                return;
            }
            ++i;
            if (!root->left || root->left->val == voyage[i]) {
                dfs(root->left);
                dfs(root->right);
            } else {
                ans.push_back(root->val);
                dfs(root->right);
                dfs(root->left);
            }
        };
        dfs(root);
        return ok ? ans : vector<int>{-1};
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
func flipMatchVoyage(root *TreeNode, voyage []int) []int {
	i := 0
	ok := true
	ans := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil || !ok {
			return
		}
		if root.Val != voyage[i] {
			ok = false
			return
		}
		i++
		if root.Left == nil || root.Left.Val == voyage[i] {
			dfs(root.Left)
			dfs(root.Right)
		} else {
			ans = append(ans, root.Val)
			dfs(root.Right)
			dfs(root.Left)
		}
	}
	dfs(root)
	if !ok {
		return []int{-1}
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

function flipMatchVoyage(root: TreeNode | null, voyage: number[]): number[] {
    let ok = true;
    let i = 0;
    const ans: number[] = [];
    const dfs = (root: TreeNode | null): void => {
        if (!root || !ok) {
            return;
        }
        if (root.val !== voyage[i++]) {
            ok = false;
            return;
        }
        if (!root.left || root.left.val === voyage[i]) {
            dfs(root.left);
            dfs(root.right);
        } else {
            ans.push(root.val);
            dfs(root.right);
            dfs(root.left);
        }
    };
    dfs(root);
    return ok ? ans : [-1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [972. 相等的有理数](https://leetcode.cn/problems/equal-rational-numbers){#972}

{{< tabs "972" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串&nbsp;<code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;，每个字符串代表一个非负有理数，只有当它们表示相同的数字时才返回 <code>true</code>&nbsp;。字符串中可以使用括号来表示有理数的重复部分。</p>

<p><strong>有理数</strong>&nbsp;最多可以用三个部分来表示：<em>整数部分</em>&nbsp;<code>&lt;IntegerPart&gt;</code>、<em>小数非重复部分</em>&nbsp;<code>&lt;NonRepeatingPart&gt;</code>&nbsp;和<em>小数重复部分</em>&nbsp;<code>&lt;(&gt;&lt;RepeatingPart&gt;&lt;)&gt;</code>。数字可以用以下三种方法之一来表示：</p>

<ul>
	<li><code>&lt;IntegerPart&gt;</code>&nbsp;

    <ul>
    	<li>例：&nbsp;<code>0</code>&nbsp;,<code>12</code>&nbsp;和&nbsp;<code>123</code>&nbsp;</li>
    </ul>
    </li>
    <li><code>&lt;IntegerPart&gt;&lt;.&gt;&lt;NonRepeatingPart&gt;</code>
    <ul>
    	<li>例： <code>0.5<font color="#333333"><font face="Helvetica Neue, Helvetica, Arial, sans-serif"><span style="font-size:14px"><span style="background-color:#ffffff">&nbsp;, </span></span></font></font></code><font color="#333333"><font face="Helvetica Neue, Helvetica, Arial, sans-serif"><span style="font-size:14px"><span style="background-color:#ffffff"><code>1.</code>&nbsp;,&nbsp;</span></span></font></font><code>2.12</code>&nbsp;和&nbsp;<code>123.0001</code></li>
    </ul>
    </li>
    <li><code>&lt;IntegerPart&gt;&lt;.&gt;&lt;NonRepeatingPart&gt;&lt;(&gt;&lt;RepeatingPart&gt;&lt;)&gt;</code>&nbsp;
    <ul>
    	<li>例： <code>0.1(6)</code> ， <code>1.(9)</code>， <code>123.00(1212)</code></li>
    </ul>
    </li>

</ul>

<p>十进制展开的重复部分通常在一对圆括号内表示。例如：</p>

<ul>
	<li><code>1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "0.(52)", t = "0.5(25)"
<strong>输出：</strong>true
<strong>解释：</strong>因为 "0.(52)" 代表 0.52525252...，而 "0.5(25)" 代表 0.52525252525.....，则这两个字符串表示相同的数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0.1666(6)", t = "0.166(66)"
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0.9(9)", t = "1."
<strong>输出：</strong>true
<strong>解释：</strong>"0.9(9)" 代表 0.999999999... 永远重复，等于 1 。[<a href="https://baike.baidu.com/item/0.999…/5615429?fr=aladdin" target="_blank">有关说明，请参阅此链接</a>]
"1." 表示数字 1，其格式正确：(IntegerPart) = "1" 且 (NonRepeatingPart) = "" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每个部分仅由数字组成。</li>
	<li>整数部分&nbsp;<code>&lt;IntegerPart&gt;</code>&nbsp;不会以零开头。（零本身除外）</li>
	<li><code>1 &lt;= &lt;IntegerPart&gt;.length &lt;= 4 </code></li>
	<li><code>0 &lt;= &lt;NonRepeatingPart&gt;.length &lt;= 4 </code></li>
	<li><code>1 &lt;= &lt;RepeatingPart&gt;.length &lt;= 4 </code></li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​​​</span></span></span>

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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [973. 最接近原点的 K 个点](https://leetcode.cn/problems/k-closest-points-to-origin){#973}

{{< tabs "973" >}}

{{% tab "python" %}}
```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dist = [x * x + y * y for x, y in points]
        l, r = 0, max(dist)
        while l < r:
            mid = (l + r) >> 1
            cnt = sum(d <= mid for d in dist)
            if cnt >= k:
                r = mid
            else:
                l = mid + 1
        return [points[i] for i, d in enumerate(dist) if d <= l]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int n = points.length;
        int[] dist = new int[n];
        int r = 0;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
            r = Math.max(r, dist[i]);
        }
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int d : dist) {
                if (d <= mid) {
                    ++cnt;
                }
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int[][] ans = new int[k][0];
        for (int i = 0, j = 0; i < n; ++i) {
            if (dist[i] <= l) {
                ans[j++] = points[i];
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int dist[n];
        int r = 0;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
            r = max(r, dist[i]);
        }
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int d : dist) {
                cnt += d <= mid;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= l) {
                ans.emplace_back(points[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kClosest(points [][]int, k int) (ans [][]int) {
	n := len(points)
	dist := make([]int, n)
	l, r := 0, 0
	for i, p := range points {
		dist[i] = p[0]*p[0] + p[1]*p[1]
		r = max(r, dist[i])
	}
	for l < r {
		mid := (l + r) >> 1
		cnt := 0
		for _, d := range dist {
			if d <= mid {
				cnt++
			}
		}
		if cnt >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	for i, p := range points {
		if dist[i] <= l {
			ans = append(ans, p)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kClosest(points: number[][], k: number): number[][] {
    const dist = points.map(([x, y]) => x * x + y * y);
    let [l, r] = [0, Math.max(...dist)];
    while (l < r) {
        const mid = (l + r) >> 1;
        let cnt = 0;
        for (const d of dist) {
            if (d <= mid) {
                ++cnt;
            }
        }
        if (cnt >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return points.filter((_, i) => dist[i] <= l);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        points.sort_by(|a, b| {
            let dist_a = f64::hypot(a[0] as f64, a[1] as f64);
            let dist_b = f64::hypot(b[0] as f64, b[1] as f64);
            dist_a.partial_cmp(&dist_b).unwrap()
        });
        points.into_iter().take(k as usize).collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组 <code>points</code>&nbsp;，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示 <strong>X-Y</strong> 平面上的一个点，并且是一个整数 <code>k</code> ，返回离原点 <code>(0,0)</code> 最近的 <code>k</code> 个点。</p>

<p>这里，平面上两点之间的距离是&nbsp;<strong>欧几里德距离</strong>（&nbsp;<code>√(x<sub>1</sub>&nbsp;- x<sub>2</sub>)<sup>2</sup>&nbsp;+ (y<sub>1</sub>&nbsp;- y<sub>2</sub>)<sup>2</sup></code>&nbsp;）。</p>

<p>你可以按 <strong>任何顺序</strong> 返回答案。除了点坐标的顺序之外，答案 <strong>确保</strong> 是 <strong>唯一</strong> 的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0973.K%20Closest%20Points%20to%20Origin/images/closestplane1.jpg" style="height: 400px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>points = [[1,3],[-2,2]], k = 1
<strong>输出：</strong>[[-2,2]]
<strong>解释： </strong>
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) &lt; sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[3,3],[5,-1],[-2,4]], k = 2
<strong>输出：</strong>[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt; x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt; 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们将所有点按照与原点的距离从小到大排序，然后取前 $k$ 个点即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{points}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda p: hypot(p[0], p[1]))
        return points[:k]
```

#### Java

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        Arrays.sort(
            points, (p1, p2) -> Math.hypot(p1[0], p1[1]) - Math.hypot(p2[0], p2[1]) > 0 ? 1 : -1);
        return Arrays.copyOfRange(points, 0, k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return hypot(p1[0], p1[1]) < hypot(p2[0], p2[1]);
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
```

#### Go

```go
func kClosest(points [][]int, k int) [][]int {
	sort.Slice(points, func(i, j int) bool {
		return math.Hypot(float64(points[i][0]), float64(points[i][1])) < math.Hypot(float64(points[j][0]), float64(points[j][1]))
	})
	return points[:k]
}
```

#### TypeScript

```ts
function kClosest(points: number[][], k: number): number[][] {
    points.sort((a, b) => Math.hypot(a[0], a[1]) - Math.hypot(b[0], b[1]));
    return points.slice(0, k);
}
```

#### Rust

```rust
impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        points.sort_by(|a, b| {
            let dist_a = f64::hypot(a[0] as f64, a[1] as f64);
            let dist_b = f64::hypot(b[0] as f64, b[1] as f64);
            dist_a.partial_cmp(&dist_b).unwrap()
        });
        points.into_iter().take(k as usize).collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：优先队列（大根堆）

我们可以使用一个优先队列（大根堆）来维护距离原点最近的 $k$ 个点。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $\textit{points}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        max_q = []
        for i, (x, y) in enumerate(points):
            dist = math.hypot(x, y)
            heappush(max_q, (-dist, i))
            if len(max_q) > k:
                heappop(max_q)
        return [points[i] for _, i in max_q]
```

#### Java

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> maxQ = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < points.length; ++i) {
            int x = points[i][0], y = points[i][1];
            maxQ.offer(new int[] {x * x + y * y, i});
            if (maxQ.size() > k) {
                maxQ.poll();
            }
        }
        int[][] ans = new int[k][2];
        for (int i = 0; i < k; ++i) {
            ans[i] = points[maxQ.poll()[1]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0, n = points.size(); i < n; ++i) {
            double dist = hypot(points[i][0], points[i][1]);
            pq.push({dist, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
```

#### Go

```go
func kClosest(points [][]int, k int) [][]int {
	maxQ := hp{}
	for i, p := range points {
		dist := math.Hypot(float64(p[0]), float64(p[1]))
		heap.Push(&maxQ, pair{dist, i})
		if len(maxQ) > k {
			heap.Pop(&maxQ)
		}
	}
	ans := make([][]int, k)
	for i, p := range maxQ {
		ans[i] = points[p.i]
	}
	return ans
}

type pair struct {
	dist float64
	i    int
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.dist > b.dist
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function kClosest(points: number[][], k: number): number[][] {
    const maxQ = new MaxPriorityQueue<{ point: number[]; dist: number }>(entry => entry.dist);
    for (const [x, y] of points) {
        const dist = x * x + y * y;
        maxQ.enqueue({ point: [x, y], dist });
        if (maxQ.size() > k) {
            maxQ.dequeue();
        }
    }
    return maxQ.toArray().map(entry => entry.point);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：二分查找

我们注意到，随着距离的增大，点的数量是递增的。这存在一个临界值，使得在这个值之前的点的数量小于等于 $k$，而在这个值之后的点的数量大于 $k$。

因此，我们可以使用二分查找，枚举距离。每一次二分查找，我们统计出距离小于等于当前距离的点的数量，如果数量大于等于 $k$，则说明临界值在左侧，我们令右边界等于当前距离；否则，临界值在右侧，我们令左边界等于当前距禽加一。

二分查找结束后，我们只需要返回距离小于等于左边界的点即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{points}$ 的长度，而 $M$ 为距离的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dist = [x * x + y * y for x, y in points]
        l, r = 0, max(dist)
        while l < r:
            mid = (l + r) >> 1
            cnt = sum(d <= mid for d in dist)
            if cnt >= k:
                r = mid
            else:
                l = mid + 1
        return [points[i] for i, d in enumerate(dist) if d <= l]
```

#### Java

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int n = points.length;
        int[] dist = new int[n];
        int r = 0;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
            r = Math.max(r, dist[i]);
        }
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int d : dist) {
                if (d <= mid) {
                    ++cnt;
                }
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int[][] ans = new int[k][0];
        for (int i = 0, j = 0; i < n; ++i) {
            if (dist[i] <= l) {
                ans[j++] = points[i];
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int dist[n];
        int r = 0;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
            r = max(r, dist[i]);
        }
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int d : dist) {
                cnt += d <= mid;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= l) {
                ans.emplace_back(points[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func kClosest(points [][]int, k int) (ans [][]int) {
	n := len(points)
	dist := make([]int, n)
	l, r := 0, 0
	for i, p := range points {
		dist[i] = p[0]*p[0] + p[1]*p[1]
		r = max(r, dist[i])
	}
	for l < r {
		mid := (l + r) >> 1
		cnt := 0
		for _, d := range dist {
			if d <= mid {
				cnt++
			}
		}
		if cnt >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	for i, p := range points {
		if dist[i] <= l {
			ans = append(ans, p)
		}
	}
	return
}
```

#### TypeScript

```ts
function kClosest(points: number[][], k: number): number[][] {
    const dist = points.map(([x, y]) => x * x + y * y);
    let [l, r] = [0, Math.max(...dist)];
    while (l < r) {
        const mid = (l + r) >> 1;
        let cnt = 0;
        for (const d of dist) {
            if (d <= mid) {
                ++cnt;
            }
        }
        if (cnt >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return points.filter((_, i) => dist[i] <= l);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [974. 和可被 K 整除的子数组](https://leetcode.cn/problems/subarray-sums-divisible-by-k){#974}

{{< tabs "974" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        cnt = Counter({0: 1})
        ans = s = 0
        for x in nums:
            s = (s + x) % k
            ans += cnt[s]
            cnt[s] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        int ans = 0, s = 0;
        for (int x : nums) {
            s = ((s + x) % k + k) % k;
            ans += cnt.getOrDefault(s, 0);
            cnt.merge(s, 1, Integer::sum);
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
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnt{{0, 1}};
        int ans = 0, s = 0;
        for (int& x : nums) {
            s = ((s + x) % k + k) % k;
            ans += cnt[s]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subarraysDivByK(nums []int, k int) (ans int) {
	cnt := map[int]int{0: 1}
	s := 0
	for _, x := range nums {
		s = ((s+x)%k + k) % k
		ans += cnt[s]
		cnt[s]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subarraysDivByK(nums: number[], k: number): number {
    const cnt: { [key: number]: number } = { 0: 1 };
    let s = 0;
    let ans = 0;
    for (const x of nums) {
        s = (((s + x) % k) + k) % k;
        ans += cnt[s] || 0;
        cnt[s] = (cnt[s] || 0) + 1;
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

<p>给定一个整数数组 <code>nums</code>&nbsp;和一个整数 <code>k</code> ，返回其中元素之和可被 <code>k</code>&nbsp;整除的非空&nbsp;<strong>子数组</strong> 的数目。</p>

<p><strong>子数组</strong> 是数组中&nbsp;<strong>连续</strong>&nbsp;的部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,5,0,-2,-3,1], k = 5
<strong>输出：</strong>7
<strong>解释：
</strong>有 7 个子数组满足其元素之和可被 k = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [5], k = 9
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

假设存在 $i \leq j$，使得 $\textit{nums}[i,..j]$ 的和能被 $k$ 整除，如果我们令 $s_i$ 表示 $\textit{nums}[0,..i]$ 的和，令 $s_j$ 表示 $\textit{nums}[0,..j]$ 的和，那么 $s_j - s_i$ 能被 $k$ 整除，即 $(s_j - s_i) \bmod k = 0$，也即 $s_j \bmod k = s_i \bmod k$。因此，我们可以用哈希表统计前缀和模 $k$ 的值的个数，从而快速判断是否存在满足条件的子数组。

我们用一个哈希表 $\textit{cnt}$ 统计前缀和模 $k$ 的值的个数，即 $\textit{cnt}[i]$ 表示前缀和模 $k$ 的值为 $i$ 的个数。初始时 $\textit{cnt}[0]=1$。用变量 $s$ 表示前缀和，初始时 $s = 0$。

接下来，从左到右遍历数组 $\textit{nums}$，对于遍历到的每个元素 $x$，我们计算 $s = (s + x) \bmod k$，然后更新答案 $\textit{ans} = \textit{ans} + \textit{cnt}[s]$，其中 $\textit{cnt}[s]$ 表示前缀和模 $k$ 的值为 $s$ 的个数。最后我们将 $\textit{cnt}[s]$ 的值加 $1$，继续遍历下一个元素。

最终，我们返回答案 $\textit{ans}$。

> 注意，由于 $s$ 的值可能为负数，因此我们可以将 $s$ 模 $k$ 的结果加上 $k$，再对 $k$ 取模，以确保 $s$ 的值为非负数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        cnt = Counter({0: 1})
        ans = s = 0
        for x in nums:
            s = (s + x) % k
            ans += cnt[s]
            cnt[s] += 1
        return ans
```

#### Java

```java
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        int ans = 0, s = 0;
        for (int x : nums) {
            s = ((s + x) % k + k) % k;
            ans += cnt.getOrDefault(s, 0);
            cnt.merge(s, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnt{{0, 1}};
        int ans = 0, s = 0;
        for (int& x : nums) {
            s = ((s + x) % k + k) % k;
            ans += cnt[s]++;
        }
        return ans;
    }
};
```

#### Go

```go
func subarraysDivByK(nums []int, k int) (ans int) {
	cnt := map[int]int{0: 1}
	s := 0
	for _, x := range nums {
		s = ((s+x)%k + k) % k
		ans += cnt[s]
		cnt[s]++
	}
	return
}
```

#### TypeScript

```ts
function subarraysDivByK(nums: number[], k: number): number {
    const cnt: { [key: number]: number } = { 0: 1 };
    let s = 0;
    let ans = 0;
    for (const x of nums) {
        s = (((s + x) % k) + k) % k;
        ans += cnt[s] || 0;
        cnt[s] = (cnt[s] || 0) + 1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [975. 奇偶跳](https://leetcode.cn/problems/odd-even-jump){#975}

{{< tabs "975" >}}

{{% tab "python" %}}
```python
class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        @cache
        def dfs(i: int, k: int) -> bool:
            if i == n - 1:
                return True
            if g[i][k] == -1:
                return False
            return dfs(g[i][k], k ^ 1)

        n = len(arr)
        g = [[0] * 2 for _ in range(n)]
        sd = SortedDict()
        for i in range(n - 1, -1, -1):
            j = sd.bisect_left(arr[i])
            g[i][1] = sd.values()[j] if j < len(sd) else -1
            j = sd.bisect_right(arr[i]) - 1
            g[i][0] = sd.values()[j] if j >= 0 else -1
            sd[arr[i]] = i
        return sum(dfs(i, 1) for i in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private Integer[][] f;
    private int[][] g;

    public int oddEvenJumps(int[] arr) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        n = arr.length;
        f = new Integer[n][2];
        g = new int[n][2];
        for (int i = n - 1; i >= 0; --i) {
            var hi = tm.ceilingEntry(arr[i]);
            g[i][1] = hi == null ? -1 : hi.getValue();
            var lo = tm.floorEntry(arr[i]);
            g[i][0] = lo == null ? -1 : lo.getValue();
            tm.put(arr[i], i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i, 1);
        }
        return ans;
    }

    private int dfs(int i, int k) {
        if (i == n - 1) {
            return 1;
        }
        if (g[i][k] == -1) {
            return 0;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        return f[i][k] = dfs(g[i][k], k ^ 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, int> d;
        int f[n][2];
        int g[n][2];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            auto it = d.lower_bound(arr[i]);
            g[i][1] = it == d.end() ? -1 : it->second;
            it = d.upper_bound(arr[i]);
            g[i][0] = it == d.begin() ? -1 : prev(it)->second;
            d[arr[i]] = i;
        }
        function<int(int, int)> dfs = [&](int i, int k) -> int {
            if (i == n - 1) {
                return 1;
            }
            if (g[i][k] == -1) {
                return 0;
            }
            if (f[i][k] != 0) {
                return f[i][k];
            }
            return f[i][k] = dfs(g[i][k], k ^ 1);
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func oddEvenJumps(arr []int) (ans int) {
	n := len(arr)
	rbt := redblacktree.NewWithIntComparator()
	f := make([][2]int, n)
	g := make([][2]int, n)
	for i := n - 1; i >= 0; i-- {
		if v, ok := rbt.Ceiling(arr[i]); ok {
			g[i][1] = v.Value.(int)
		} else {
			g[i][1] = -1
		}
		if v, ok := rbt.Floor(arr[i]); ok {
			g[i][0] = v.Value.(int)
		} else {
			g[i][0] = -1
		}
		rbt.Put(arr[i], i)
	}
	var dfs func(int, int) int
	dfs = func(i, k int) int {
		if i == n-1 {
			return 1
		}
		if g[i][k] == -1 {
			return 0
		}
		if f[i][k] != 0 {
			return f[i][k]
		}
		f[i][k] = dfs(g[i][k], k^1)
		return f[i][k]
	}
	for i := 0; i < n; i++ {
		if dfs(i, 1) == 1 {
			ans++
		}
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

<p>给定一个整数数组 <code>arr</code>，你可以从某一起始索引出发，跳跃一定次数。在你跳跃的过程中，第 1、3、5... 次跳跃称为奇数跳跃，而第 2、4、6... 次跳跃称为偶数跳跃。</p>

<p>你可以按以下方式从索引 <code>i</code>&nbsp;向后跳转到索引 <code>j</code>（其中 <code>i &lt; j</code>）：</p>

<ul>
	<li>在进行奇数跳跃时（如，第&nbsp;1，3，5... 次跳跃），你将会跳到索引 <code>j</code>，使得 <code>arr[i] &lt;=&nbsp;arr[j]</code>，且 <code>arr[j]</code> 的值尽可能小。如果存在多个这样的索引 <code>j</code>，你只能跳到满足要求的<strong>最小</strong>索引 <code>j</code> 上。</li>
	<li>在进行偶数跳跃时（如，第&nbsp;2，4，6... 次跳跃），你将会跳到索引&nbsp;<code>j</code>，使得 <code>arr[i] &gt;= arr[j]</code>，且 <code>arr[j]</code> 的值尽可能大。如果存在多个这样的索引 <code>j</code>，你只能跳到满足要求的<strong>最小</strong>索引 <code>j</code>&nbsp;上。</li>
	<li>（对于某些索引 <code>i</code>，可能无法进行合乎要求的跳跃。）</li>
</ul>

<p>如果从某一索引开始跳跃一定次数（可能是 0 次或多次），就可以到达数组的末尾（索引 <code>arr.length - 1</code>），那么该索引就会被认为是好的起始索引。</p>

<p>返回好的起始索引的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[10,13,12,14,15]
<strong>输出：</strong>2
<strong>解释： </strong>
从起始索引 i = 0 出发，我们可以跳到 i = 2，（因为 arr[2] 是 arr[1]，arr[2]，arr[3]，arr[4] 中大于或等于 arr[0] 的最小值），然后我们就无法继续跳下去了。
从起始索引 i = 1 和 i = 2 出发，我们可以跳到 i = 3，然后我们就无法继续跳下去了。
从起始索引 i = 3 出发，我们可以跳到 i = 4，到达数组末尾。
从起始索引 i = 4 出发，我们已经到达数组末尾。
总之，我们可以从 2 个不同的起始索引（i = 3, i = 4）出发，通过一定数量的跳跃到达数组末尾。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>[2,3,1,1,4]
<strong>输出：</strong>3
<strong>解释：</strong>
从起始索引 i=0 出发，我们依次可以跳到 i = 1，i = 2，i = 3：

在我们的第一次跳跃（奇数）中，我们先跳到 i = 1，因为 arr[1] 是（arr[1]，arr[2]，arr[3]，arr[4]）中大于或等于 arr[0] 的最小值。

在我们的第二次跳跃（偶数）中，我们从 i = 1 跳到 i = 2，因为 arr[2] 是（arr[2]，arr[3]，arr[4]）中小于或等于 arr[1] 的最大值。arr[3] 也是最大的值，但 2 是一个较小的索引，所以我们只能跳到 i = 2，而不能跳到 i = 3。

在我们的第三次跳跃（奇数）中，我们从 i = 2 跳到 i = 3，因为 arr[3] 是（arr[3]，arr[4]）中大于或等于 arr[2] 的最小值。

我们不能从 i = 3 跳到 i = 4，所以起始索引 i = 0 不是好的起始索引。

类似地，我们可以推断：
从起始索引 i = 1 出发， 我们跳到 i = 4，这样我们就到达数组末尾。
从起始索引 i = 2 出发， 我们跳到 i = 3，然后我们就不能再跳了。
从起始索引 i = 3 出发， 我们跳到 i = 4，这样我们就到达数组末尾。
从起始索引 i = 4 出发，我们已经到达数组末尾。
总之，我们可以从 3 个不同的起始索引（i = 1, i = 3, i = 4）出发，通过一定数量的跳跃到达数组末尾。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>[5,1,3,4,2]
<strong>输出：</strong>3
<strong>解释： </strong>
我们可以从起始索引 1，2，4 出发到达数组末尾。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= arr.length &lt;= 20000</code></li>
	<li><code>0 &lt;= arr[i] &lt; 100000</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合 + 记忆化搜索

我们先利用有序集合，预处理出每个位置能跳到的位置，记录在数组 $g$ 中，其中 $g[i][1]$ 和 $g[i][0]$ 分别表示当前位置是奇数次跳还是偶数次跳时能跳到的位置。如果不能跳到任何位置，那么 $g[i][1]$ 和 $g[i][0]$ 都为 $-1$。

然后利用记忆化搜索，从每个位置出发，且当前是奇数次跳跃，判断是否能跳到数组末尾，如果能，那么结果加一。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        @cache
        def dfs(i: int, k: int) -> bool:
            if i == n - 1:
                return True
            if g[i][k] == -1:
                return False
            return dfs(g[i][k], k ^ 1)

        n = len(arr)
        g = [[0] * 2 for _ in range(n)]
        sd = SortedDict()
        for i in range(n - 1, -1, -1):
            j = sd.bisect_left(arr[i])
            g[i][1] = sd.values()[j] if j < len(sd) else -1
            j = sd.bisect_right(arr[i]) - 1
            g[i][0] = sd.values()[j] if j >= 0 else -1
            sd[arr[i]] = i
        return sum(dfs(i, 1) for i in range(n))
```

#### Java

```java
class Solution {
    private int n;
    private Integer[][] f;
    private int[][] g;

    public int oddEvenJumps(int[] arr) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        n = arr.length;
        f = new Integer[n][2];
        g = new int[n][2];
        for (int i = n - 1; i >= 0; --i) {
            var hi = tm.ceilingEntry(arr[i]);
            g[i][1] = hi == null ? -1 : hi.getValue();
            var lo = tm.floorEntry(arr[i]);
            g[i][0] = lo == null ? -1 : lo.getValue();
            tm.put(arr[i], i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i, 1);
        }
        return ans;
    }

    private int dfs(int i, int k) {
        if (i == n - 1) {
            return 1;
        }
        if (g[i][k] == -1) {
            return 0;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        return f[i][k] = dfs(g[i][k], k ^ 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, int> d;
        int f[n][2];
        int g[n][2];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            auto it = d.lower_bound(arr[i]);
            g[i][1] = it == d.end() ? -1 : it->second;
            it = d.upper_bound(arr[i]);
            g[i][0] = it == d.begin() ? -1 : prev(it)->second;
            d[arr[i]] = i;
        }
        function<int(int, int)> dfs = [&](int i, int k) -> int {
            if (i == n - 1) {
                return 1;
            }
            if (g[i][k] == -1) {
                return 0;
            }
            if (f[i][k] != 0) {
                return f[i][k];
            }
            return f[i][k] = dfs(g[i][k], k ^ 1);
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i, 1);
        }
        return ans;
    }
};
```

#### Go

```go
func oddEvenJumps(arr []int) (ans int) {
	n := len(arr)
	rbt := redblacktree.NewWithIntComparator()
	f := make([][2]int, n)
	g := make([][2]int, n)
	for i := n - 1; i >= 0; i-- {
		if v, ok := rbt.Ceiling(arr[i]); ok {
			g[i][1] = v.Value.(int)
		} else {
			g[i][1] = -1
		}
		if v, ok := rbt.Floor(arr[i]); ok {
			g[i][0] = v.Value.(int)
		} else {
			g[i][0] = -1
		}
		rbt.Put(arr[i], i)
	}
	var dfs func(int, int) int
	dfs = func(i, k int) int {
		if i == n-1 {
			return 1
		}
		if g[i][k] == -1 {
			return 0
		}
		if f[i][k] != 0 {
			return f[i][k]
		}
		f[i][k] = dfs(g[i][k], k^1)
		return f[i][k]
	}
	for i := 0; i < n; i++ {
		if dfs(i, 1) == 1 {
			ans++
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [976. 三角形的最大周长](https://leetcode.cn/problems/largest-perimeter-triangle){#976}

{{< tabs "976" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 1, 1, -1):
            if (c := nums[i - 1] + nums[i - 2]) > nums[i]:
                return c + nums[i]
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for (int i = nums.length - 1; i >= 2; --i) {
            int c = nums[i - 1] + nums[i - 2];
            if (c > nums[i]) {
                return c + nums[i];
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
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; --i) {
            int c = nums[i - 1] + nums[i - 2];
            if (c > nums[i]) return c + nums[i];
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestPerimeter(nums []int) int {
	sort.Ints(nums)
	for i := len(nums) - 1; i >= 2; i-- {
		c := nums[i-1] + nums[i-2]
		if c > nums[i] {
			return c + nums[i]
		}
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestPerimeter(nums: number[]): number {
    const n = nums.length;
    nums.sort((a, b) => b - a);
    for (let i = 2; i < n; i++) {
        const [a, b, c] = [nums[i - 2], nums[i - 1], nums[i]];
        if (a < b + c) {
            return a + b + c;
        }
    }
    return 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        nums.sort_unstable_by(|a, b| b.cmp(&a));
        for i in 2..n {
            let (a, b, c) = (nums[i - 2], nums[i - 1], nums[i]);
            if a < b + c {
                return a + b + c;
            }
        }
        0
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 2; i < numsSize; i++) {
        if (nums[i - 2] < nums[i - 1] + nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }
    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定由一些正数（代表长度）组成的数组 <code>nums</code>&nbsp;，返回 <em>由其中三个长度组成的、<strong>面积不为零</strong>的三角形的最大周长</em>&nbsp;。如果不能形成任何面积不为零的三角形，返回&nbsp;<code>0</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>你可以用三个边长组成一个三角形:1 2 2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,10]
<strong>输出：</strong>0
<strong>解释：</strong>
你不能用边长 1,1,2 来组成三角形。
不能用边长 1,1,10 来构成三角形。
不能用边长 1、2 和 10 来构成三角形。
因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

> 三角形由三条边组成，且满足 <var>C</var> >= <var>B</var> && <var>C</var> >= <var>A</var> && <var>C</var> < <var>A</var> + <var>B</var>

贪心策略，尽可能使用长边来组成三角形。

1. 对 `nums` 排序（从大到小）。
2. 遍历 `nums`，以三个元素一组，进行条件判断，如滑动窗口一般。
3. 当找到满足条件的三个元素时直接返回即可。
4. 否则，在遍历结束时返回 0。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 1, 1, -1):
            if (c := nums[i - 1] + nums[i - 2]) > nums[i]:
                return c + nums[i]
        return 0
```

#### Java

```java
class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for (int i = nums.length - 1; i >= 2; --i) {
            int c = nums[i - 1] + nums[i - 2];
            if (c > nums[i]) {
                return c + nums[i];
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
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; --i) {
            int c = nums[i - 1] + nums[i - 2];
            if (c > nums[i]) return c + nums[i];
        }
        return 0;
    }
};
```

#### Go

```go
func largestPerimeter(nums []int) int {
	sort.Ints(nums)
	for i := len(nums) - 1; i >= 2; i-- {
		c := nums[i-1] + nums[i-2]
		if c > nums[i] {
			return c + nums[i]
		}
	}
	return 0
}
```

#### TypeScript

```ts
function largestPerimeter(nums: number[]): number {
    const n = nums.length;
    nums.sort((a, b) => b - a);
    for (let i = 2; i < n; i++) {
        const [a, b, c] = [nums[i - 2], nums[i - 1], nums[i]];
        if (a < b + c) {
            return a + b + c;
        }
    }
    return 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        nums.sort_unstable_by(|a, b| b.cmp(&a));
        for i in 2..n {
            let (a, b, c) = (nums[i - 2], nums[i - 1], nums[i]);
            if a < b + c {
                return a + b + c;
            }
        }
        0
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 2; i < numsSize; i++) {
        if (nums[i - 2] < nums[i - 1] + nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }
    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [977. 有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array){#977}

{{< tabs "977" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans = []
        i, j = 0, len(nums) - 1
        while i <= j:
            a = nums[i] * nums[i]
            b = nums[j] * nums[j]
            if a > b:
                ans.append(a)
                i += 1
            else:
                ans.append(b)
                j -= 1
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0, j = n - 1, k = n - 1; i <= j; --k) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                ans[k] = a;
                ++i;
            } else {
                ans[k] = b;
                --j;
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
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, k = n - 1; i <= j; --k) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                ans[k] = a;
                ++i;
            } else {
                ans[k] = b;
                --j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortedSquares(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	for i, j, k := 0, n-1, n-1; i <= j; k-- {
		a := nums[i] * nums[i]
		b := nums[j] * nums[j]
		if a > b {
			ans[k] = a
			i++
		} else {
			ans[k] = b
			j--
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![0; n];
        let (mut i, mut j) = (0, n - 1);
        for k in (0..n).rev() {
            let a = nums[i] * nums[i];
            let b = nums[j] * nums[j];
            if a > b {
                ans[k] = a;
                i += 1;
            } else {
                ans[k] = b;
                j -= 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    const n = nums.length;
    const ans = Array(n).fill(0);
    for (let i = 0, j = n - 1, k = n - 1; i <= j; --k) {
        const [a, b] = [nums[i] * nums[i], nums[j] * nums[j]];
        if (a > b) {
            ans[k] = a;
            ++i;
        } else {
            ans[k] = b;
            --j;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortedSquares($nums) {
        $n = count($nums);
        $ans = array_fill(0, $n, 0);
        for ($i = 0, $j = $n - 1, $k = $n - 1; $i <= $j; --$k) {
            $a = $nums[$i] * $nums[$i];
            $b = $nums[$j] * $nums[$j];
            if ($a > $b) {
                $ans[$k] = $a;
                ++$i;
            } else {
                $ans[$k] = $b;
                --$j;
            }
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

<p>给你一个按 <strong>非递减顺序</strong> 排序的整数数组 <code>nums</code>，返回 <strong>每个数字的平方</strong> 组成的新数组，要求也按 <strong>非递减顺序</strong> 排序。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-4,-1,0,3,10]
<strong>输出：</strong>[0,1,9,16,100]
<strong>解释：</strong>平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-7,-3,2,3,11]
<strong>输出：</strong>[4,9,9,49,121]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code><span>1 &lt;= nums.length &lt;= </span>10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 已按 <strong>非递减顺序</strong> 排序</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>请你设计时间复杂度为 <code>O(n)</code> 的算法解决本问题</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

由于数组 $nums$ 已经按照非递减顺序排好序，所以数组中负数的平方值是递减的，正数的平方值是递增的。我们可以使用双指针，分别指向数组的两端，每次比较两个指针指向的元素的平方值，将较大的平方值放入结果数组的末尾。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans = []
        i, j = 0, len(nums) - 1
        while i <= j:
            a = nums[i] * nums[i]
            b = nums[j] * nums[j]
            if a > b:
                ans.append(a)
                i += 1
            else:
                ans.append(b)
                j -= 1
        return ans[::-1]
```

#### Java

```java
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0, j = n - 1, k = n - 1; i <= j; --k) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                ans[k] = a;
                ++i;
            } else {
                ans[k] = b;
                --j;
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
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, k = n - 1; i <= j; --k) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                ans[k] = a;
                ++i;
            } else {
                ans[k] = b;
                --j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sortedSquares(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	for i, j, k := 0, n-1, n-1; i <= j; k-- {
		a := nums[i] * nums[i]
		b := nums[j] * nums[j]
		if a > b {
			ans[k] = a
			i++
		} else {
			ans[k] = b
			j--
		}
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![0; n];
        let (mut i, mut j) = (0, n - 1);
        for k in (0..n).rev() {
            let a = nums[i] * nums[i];
            let b = nums[j] * nums[j];
            if a > b {
                ans[k] = a;
                i += 1;
            } else {
                ans[k] = b;
                j -= 1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    const n = nums.length;
    const ans = Array(n).fill(0);
    for (let i = 0, j = n - 1, k = n - 1; i <= j; --k) {
        const [a, b] = [nums[i] * nums[i], nums[j] * nums[j]];
        if (a > b) {
            ans[k] = a;
            ++i;
        } else {
            ans[k] = b;
            --j;
        }
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortedSquares($nums) {
        $n = count($nums);
        $ans = array_fill(0, $n, 0);
        for ($i = 0, $j = $n - 1, $k = $n - 1; $i <= $j; --$k) {
            $a = $nums[$i] * $nums[$i];
            $b = $nums[$j] * $nums[$j];
            if ($a > $b) {
                $ans[$k] = $a;
                ++$i;
            } else {
                $ans[$k] = $b;
                --$j;
            }
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

# [978. 最长湍流子数组](https://leetcode.cn/problems/longest-turbulent-subarray){#978}

{{< tabs "978" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        ans = f = g = 1
        for a, b in pairwise(arr):
            ff = g + 1 if a < b else 1
            gg = f + 1 if a > b else 1
            f, g = ff, gg
            ans = max(ans, f, g)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int ans = 1, f = 1, g = 1;
        for (int i = 1; i < arr.length; ++i) {
            int ff = arr[i - 1] < arr[i] ? g + 1 : 1;
            int gg = arr[i - 1] > arr[i] ? f + 1 : 1;
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
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, f = 1, g = 1;
        for (int i = 1; i < arr.size(); ++i) {
            int ff = arr[i - 1] < arr[i] ? g + 1 : 1;
            int gg = arr[i - 1] > arr[i] ? f + 1 : 1;
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
func maxTurbulenceSize(arr []int) int {
	ans, f, g := 1, 1, 1
	for i, x := range arr[1:] {
		ff, gg := 1, 1
		if arr[i] < x {
			ff = g + 1
		}
		if arr[i] > x {
			gg = f + 1
		}
		f, g = ff, gg
		ans = max(ans, max(f, g))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTurbulenceSize(arr: number[]): number {
    let f = 1;
    let g = 1;
    let ans = 1;
    for (let i = 1; i < arr.length; ++i) {
        const ff = arr[i - 1] < arr[i] ? g + 1 : 1;
        const gg = arr[i - 1] > arr[i] ? f + 1 : 1;
        f = ff;
        g = gg;
        ans = Math.max(ans, f, g);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_turbulence_size(arr: Vec<i32>) -> i32 {
        let mut ans = 1;
        let mut f = 1;
        let mut g = 1;

        for i in 1..arr.len() {
            let ff = if arr[i - 1] < arr[i] { g + 1 } else { 1 };
            let gg = if arr[i - 1] > arr[i] { f + 1 } else { 1 };
            f = ff;
            g = gg;
            ans = ans.max(f.max(g));
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

<p>给定一个整数数组 <code>arr</code>&nbsp;，返回 <code>arr</code>&nbsp;的&nbsp;<em>最大湍流子数组的<strong>长度</strong></em><strong>&nbsp;</strong>。</p>

<p>如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是&nbsp;<strong>湍流子数组</strong>&nbsp;。</p>

<p>更正式地来说，当 <code>arr</code>&nbsp;的子数组&nbsp;<code>A[i], A[i+1], ..., A[j]</code>&nbsp;满足仅满足下列条件时，我们称其为<em>湍流子数组</em>：</p>

<ul>
	<li>若&nbsp;<code>i &lt;= k &lt; j</code>&nbsp;：

    <ul>
    	<li>当 <code>k</code>&nbsp;为奇数时，&nbsp;<code>A[k] &gt; A[k+1]</code>，且</li>
    	<li>当 <code>k</code> 为偶数时，<code>A[k] &lt; A[k+1]</code>；</li>
    </ul>
    </li>
    <li><strong>或 </strong>若&nbsp;<code>i &lt;= k &lt; j</code>&nbsp;：
    <ul>
    	<li>当 <code>k</code> 为偶数时，<code>A[k] &gt; A[k+1]</code>&nbsp;，且</li>
    	<li>当 <code>k</code>&nbsp;为奇数时，&nbsp;<code>A[k] &lt; A[k+1]</code>。</li>
    </ul>
    </li>

</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [9,4,2,10,7,8,8,1,9]
<strong>输出：</strong>5
<strong>解释：</strong>arr[1] &gt; arr[2] &lt; arr[3] &gt; arr[4] &lt; arr[5]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [4,8,12,16]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [100]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以 $\textit{nums}[i]$ 结尾且结尾处于上升状态的最长湍流子数组的长度，定义 $g[i]$ 表示以 $\textit{nums}[i]$ 结尾且结尾处于下降状态的最长湍流子数组的长度。初始时 $f[0] = 1$, $g[0] = 1$。答案为 $\max(f[i], g[i])$。

对于 $i \gt 0$，若 $\textit{nums}[i] \gt \textit{nums}[i - 1]$，则 $f[i] = g[i - 1] + 1$，否则 $f[i] = 1$；若 $\textit{nums}[i] \lt \textit{nums}[i - 1]$，则 $g[i] = f[i - 1] + 1$，否则 $g[i] = 1$。

由于 $f[i]$ 和 $g[i]$ 只与 $f[i - 1]$ 和 $g[i - 1]$ 有关，因此可以使用两个变量代替数组。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        ans = f = g = 1
        for a, b in pairwise(arr):
            ff = g + 1 if a < b else 1
            gg = f + 1 if a > b else 1
            f, g = ff, gg
            ans = max(ans, f, g)
        return ans
```

#### Java

```java
class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int ans = 1, f = 1, g = 1;
        for (int i = 1; i < arr.length; ++i) {
            int ff = arr[i - 1] < arr[i] ? g + 1 : 1;
            int gg = arr[i - 1] > arr[i] ? f + 1 : 1;
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
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, f = 1, g = 1;
        for (int i = 1; i < arr.size(); ++i) {
            int ff = arr[i - 1] < arr[i] ? g + 1 : 1;
            int gg = arr[i - 1] > arr[i] ? f + 1 : 1;
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
func maxTurbulenceSize(arr []int) int {
	ans, f, g := 1, 1, 1
	for i, x := range arr[1:] {
		ff, gg := 1, 1
		if arr[i] < x {
			ff = g + 1
		}
		if arr[i] > x {
			gg = f + 1
		}
		f, g = ff, gg
		ans = max(ans, max(f, g))
	}
	return ans
}
```

#### TypeScript

```ts
function maxTurbulenceSize(arr: number[]): number {
    let f = 1;
    let g = 1;
    let ans = 1;
    for (let i = 1; i < arr.length; ++i) {
        const ff = arr[i - 1] < arr[i] ? g + 1 : 1;
        const gg = arr[i - 1] > arr[i] ? f + 1 : 1;
        f = ff;
        g = gg;
        ans = Math.max(ans, f, g);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_turbulence_size(arr: Vec<i32>) -> i32 {
        let mut ans = 1;
        let mut f = 1;
        let mut g = 1;

        for i in 1..arr.len() {
            let ff = if arr[i - 1] < arr[i] { g + 1 } else { 1 };
            let gg = if arr[i - 1] > arr[i] { f + 1 } else { 1 };
            f = ff;
            g = gg;
            ans = ans.max(f.max(g));
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

# [979. 在二叉树中分配硬币](https://leetcode.cn/problems/distribute-coins-in-binary-tree){#979}

{{< tabs "979" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return 0
            left, right = dfs(root.left), dfs(root.right)
            nonlocal ans
            ans += abs(left) + abs(right)
            return left + right + root.val - 1

        ans = 0
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
    private int ans;

    public int distributeCoins(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = dfs(root.left);
        int right = dfs(root.right);
        ans += Math.abs(left) + Math.abs(right);
        return left + right + root.val - 1;
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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int left = dfs(root->left);
            int right = dfs(root->right);
            ans += abs(left) + abs(right);
            return left + right + root->val - 1;
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
func distributeCoins(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		left, right := dfs(root.Left), dfs(root.Right)
		ans += abs(left) + abs(right)
		return left + right + root.Val - 1
	}
	dfs(root)
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

function distributeCoins(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return 0;
        }
        const left = dfs(root.left);
        const right = dfs(root.right);
        ans += Math.abs(left) + Math.abs(right);
        return left + right + root.val - 1;
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有 <code>n</code> 个结点的二叉树的根结点 <code>root</code> ，其中树中每个结点 <code>node</code> 都对应有 <code>node.val</code> 枚硬币。整棵树上一共有 <code>n</code> 枚硬币。</p>

<p>在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。移动可以是从父结点到子结点，或者从子结点移动到父结点。</p>

<p>返回使每个结点上 <strong>只有</strong> 一枚硬币所需的 <strong>最少</strong> 移动次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0979.Distribute%20Coins%20in%20Binary%20Tree/images/tree1.png" style="width: 250px; height: 236px;" />
<pre>
<strong>输入：</strong>root = [3,0,0]
<strong>输出：</strong>2
<strong>解释：</strong>一枚硬币从根结点移动到左子结点，一枚硬币从根结点移动到右子结点。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0979.Distribute%20Coins%20in%20Binary%20Tree/images/tree2.png" style="width: 250px; height: 236px;" />
<pre>
<strong>输入：</strong>root = [0,3,0]
<strong>输出：</strong>3
<strong>解释：</strong>将两枚硬币从根结点的左子结点移动到根结点（两次移动）。然后，将一枚硬币从根结点移动到右子结点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目为 <code>n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= Node.val &lt;= n</code></li>
	<li>所有 <code>Node.val</code> 的值之和是 <code>n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们定义一个函数 $\textit{dfs(\textit{node})}$，表示以 $\textit{node}$ 为根节点的子树中，金币的超载量，即金币的数量减去节点数。如果 $\textit{dfs(\textit{node})}$ 为正数，表示该子树中金币的数量多于节点数，需要将多余的金币移出该子树；如果 $\textit{dfs(\textit{node})}$ 为负数，表示该子树中金币的数量少于节点数，需要将不足的金币移入该子树。

在函数 $\textit{dfs(\textit{node})}$ 中，我们首先遍历左右子树，获得左右子树的金币超载量 $\textit{left}$ 和 $\textit{right}$。那么当前移动的次数需要加上 $|\textit{left}| + |\textit{right}|$，即将左右子树中的金币移动到当前节点。然后，我们返回整个子树的金币超载量，即 $\textit{left} + \textit{right} + \textit{node.val} - 1$。

最后返回移动的次数即可。

时间复杂度 $O(n)$，空间复杂度 $O(h)$。其中 $n$ 和 $h$ 分别是二叉树的节点数和高度。

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
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return 0
            left, right = dfs(root.left), dfs(root.right)
            nonlocal ans
            ans += abs(left) + abs(right)
            return left + right + root.val - 1

        ans = 0
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
    private int ans;

    public int distributeCoins(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = dfs(root.left);
        int right = dfs(root.right);
        ans += Math.abs(left) + Math.abs(right);
        return left + right + root.val - 1;
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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int left = dfs(root->left);
            int right = dfs(root->right);
            ans += abs(left) + abs(right);
            return left + right + root->val - 1;
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
func distributeCoins(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		left, right := dfs(root.Left), dfs(root.Right)
		ans += abs(left) + abs(right)
		return left + right + root.Val - 1
	}
	dfs(root)
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

function distributeCoins(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return 0;
        }
        const left = dfs(root.left);
        const right = dfs(root.right);
        ans += Math.abs(left) + Math.abs(right);
        return left + right + root.val - 1;
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
