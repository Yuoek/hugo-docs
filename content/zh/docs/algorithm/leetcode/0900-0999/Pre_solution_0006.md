---
title: "0950_按递增顺序显示卡牌"
date: 2025-10-08T18:36:43+08:00
weight: 6
tags: [二叉树, 位运算, 动态规划, 哈希表, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 数论, 树, 模拟, 深度优先搜索, 矩阵, 贪心, 队列]
---

{{< markmap >}}
### [0950_按递增顺序显示卡牌](#950)
#### [队列](#950)
#### [数组](#950)
#### [排序](#950)
#### [模拟](#950)
### [0951_翻转等价二叉树](#951)
#### [树](#951)
#### [深度优先搜索](#951)
#### [二叉树](#951)
### [0952_按公因数计算最大组件大小](#952)
#### [并查集](#952)
#### [数组](#952)
#### [哈希表](#952)
#### [数学](#952)
#### [数论](#952)
### [0953_验证外星语词典](#953)
#### [数组](#953)
#### [哈希表](#953)
#### [字符串](#953)
### [0954_二倍数对数组](#954)
#### [贪心](#954)
#### [数组](#954)
#### [哈希表](#954)
#### [排序](#954)
### [0955_删列造序 II](#955)
#### [贪心](#955)
#### [数组](#955)
#### [字符串](#955)
### [0956_最高的广告牌](#956)
#### [数组](#956)
#### [动态规划](#956)
### [0957_N 天后的牢房](#957)
#### [位运算](#957)
#### [数组](#957)
#### [哈希表](#957)
#### [数学](#957)
### [0958_二叉树的完全性检验](#958)
#### [树](#958)
#### [广度优先搜索](#958)
#### [二叉树](#958)
### [0959_由斜杠划分区域](#959)
#### [深度优先搜索](#959)
#### [广度优先搜索](#959)
#### [并查集](#959)
#### [数组](#959)
#### [哈希表](#959)
#### [矩阵](#959)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0950_按递增顺序显示卡牌
___
#### 队列
___
#### 数组
___
#### 排序
___
#### 模拟
---
### 0951_翻转等价二叉树
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0952_按公因数计算最大组件大小
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 数论
---
### 0953_验证外星语词典
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0954_二倍数对数组
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 0955_删列造序 II
___
#### 贪心
___
#### 数组
___
#### 字符串
---
### 0956_最高的广告牌
___
#### 数组
___
#### 动态规划
---
### 0957_N 天后的牢房
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 数学
---
### 0958_二叉树的完全性检验
___
#### 树
___
#### 广度优先搜索
___
#### 二叉树
---
### 0959_由斜杠划分区域
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 动态规划 |
| 哈希表 | 字符串 | 并查集 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 数论 | 树 |
| 模拟 | 深度优先搜索 | 矩阵 |
| 贪心 | 队列 |  |

# [950. 按递增顺序显示卡牌](https://leetcode.cn/problems/reveal-cards-in-increasing-order){#950}

{{< tabs "950" >}}

{{% tab "python" %}}
```python
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        q = deque()
        for v in sorted(deck, reverse=True):
            if q:
                q.appendleft(q.pop())
            q.appendleft(v)
        return list(q)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Deque<Integer> q = new ArrayDeque<>();
        Arrays.sort(deck);
        int n = deck.length;
        for (int i = n - 1; i >= 0; --i) {
            if (!q.isEmpty()) {
                q.offerFirst(q.pollLast());
            }
            q.offerFirst(deck[i]);
        }
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = q.pollLast();
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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> q;
        for (int v : deck) {
            if (!q.empty()) {
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(v);
        }
        return vector<int>(q.begin(), q.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func deckRevealedIncreasing(deck []int) []int {
	sort.Sort(sort.Reverse(sort.IntSlice(deck)))
	q := []int{}
	for _, v := range deck {
		if len(q) > 0 {
			q = append([]int{q[len(q)-1]}, q[:len(q)-1]...)
		}
		q = append([]int{v}, q...)
	}
	return q
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>牌组中的每张卡牌都对应有一个唯一的整数。你可以按你想要的顺序对这套卡片进行排序。</p>

<p>最初，这些卡牌在牌组里是正面朝下的（即，未显示状态）。</p>

<p>现在，重复执行以下步骤，直到显示所有卡牌为止：</p>

<ol>
	<li>从牌组顶部抽一张牌，显示它，然后将其从牌组中移出。</li>
	<li>如果牌组中仍有牌，则将下一张处于牌组顶部的牌放在牌组的底部。</li>
	<li>如果仍有未显示的牌，那么返回步骤 1。否则，停止行动。</li>
</ol>

<p>返回能以<strong>递增顺序</strong>显示卡牌的牌组顺序。</p>

<p>答案中的第一张牌被认为处于牌堆顶部。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[17,13,11,2,3,5,7]
<strong>输出：</strong>[2,13,3,11,5,17,7]
<strong>解释：
</strong>我们得到的牌组顺序为 [17,13,11,2,3,5,7]（这个顺序不重要），然后将其重新排序。
重新排序后，牌组以 [2,13,3,11,5,17,7] 开始，其中 2 位于牌组的顶部。
我们显示 2，然后将 13 移到底部。牌组现在是 [3,11,5,17,7,13]。
我们显示 3，并将 11 移到底部。牌组现在是 [5,17,7,13,11]。
我们显示 5，然后将 17 移到底部。牌组现在是 [7,13,11,17]。
我们显示 7，并将 13 移到底部。牌组现在是 [11,17,13]。
我们显示 11，然后将 17 移到底部。牌组现在是 [13,17]。
我们展示 13，然后将 17 移到底部。牌组现在是 [17]。
我们显示 17。
由于所有卡片都是按递增顺序排列显示的，所以答案是正确的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 1000</code></li>
	<li><code>1 &lt;= A[i] &lt;= 10^6</code></li>
	<li>对于所有的&nbsp;<code>i != j</code>，<code>A[i] != A[j]</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：队列模拟

根据题目描述，我们知道，数组 `deck` 逆序排列后的序列就是最终的结果。我们可以从最终结果入手，逆向推导出卡片顺序。

遍历逆序排列后的数组 `deck`，先判断队列是否为空，若不为空，则将队尾元素移动到队首，然后将当前元素入队（题目中的逆过程）。若为空，则直接将当前元素入队。

最后，将队列中的元素依次出队，即可得到最终的结果。

时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `deck` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        q = deque()
        for v in sorted(deck, reverse=True):
            if q:
                q.appendleft(q.pop())
            q.appendleft(v)
        return list(q)
```

#### Java

```java
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Deque<Integer> q = new ArrayDeque<>();
        Arrays.sort(deck);
        int n = deck.length;
        for (int i = n - 1; i >= 0; --i) {
            if (!q.isEmpty()) {
                q.offerFirst(q.pollLast());
            }
            q.offerFirst(deck[i]);
        }
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = q.pollLast();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> q;
        for (int v : deck) {
            if (!q.empty()) {
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(v);
        }
        return vector<int>(q.begin(), q.end());
    }
};
```

#### Go

```go
func deckRevealedIncreasing(deck []int) []int {
	sort.Sort(sort.Reverse(sort.IntSlice(deck)))
	q := []int{}
	for _, v := range deck {
		if len(q) > 0 {
			q = append([]int{q[len(q)-1]}, q[:len(q)-1]...)
		}
		q = append([]int{v}, q...)
	}
	return q
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [951. 翻转等价二叉树](https://leetcode.cn/problems/flip-equivalent-binary-trees){#951}

{{< tabs "951" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root1, root2):
            if root1 == root2 or (root1 is None and root2 is None):
                return True
            if root1 is None or root2 is None or root1.val != root2.val:
                return False
            return (dfs(root1.left, root2.left) and dfs(root1.right, root2.right)) or (
                dfs(root1.left, root2.right) and dfs(root1.right, root2.left)
            )

        return dfs(root1, root2)
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
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        return dfs(root1, root2);
    }

    private boolean dfs(TreeNode root1, TreeNode root2) {
        if (root1 == root2 || (root1 == null && root2 == null)) {
            return true;
        }
        if (root1 == null || root2 == null || root1.val != root2.val) {
            return false;
        }
        return (dfs(root1.left, root2.left) && dfs(root1.right, root2.right))
            || (dfs(root1.left, root2.right) && dfs(root1.right, root2.left));
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }

    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2 || (!root1 && !root2)) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;
        return (dfs(root1->left, root2->left) && dfs(root1->right, root2->right)) || (dfs(root1->left, root2->right) && dfs(root1->right, root2->left));
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
func flipEquiv(root1 *TreeNode, root2 *TreeNode) bool {
	var dfs func(root1, root2 *TreeNode) bool
	dfs = func(root1, root2 *TreeNode) bool {
		if root1 == root2 || (root1 == nil && root2 == nil) {
			return true
		}
		if root1 == nil || root2 == nil || root1.Val != root2.Val {
			return false
		}
		return (dfs(root1.Left, root2.Left) && dfs(root1.Right, root2.Right)) || (dfs(root1.Left, root2.Right) && dfs(root1.Right, root2.Left))
	}
	return dfs(root1, root2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function flipEquiv(root1: TreeNode | null, root2: TreeNode | null): boolean {
    if (root1 === root2) return true;
    if (!root1 || !root2 || root1?.val !== root2?.val) return false;

    const { left: l1, right: r1 } = root1!;
    const { left: l2, right: r2 } = root2!;

    return (flipEquiv(l1, l2) && flipEquiv(r1, r2)) || (flipEquiv(l1, r2) && flipEquiv(r1, l2));
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function flipEquiv(root1, root2) {
    if (root1 === root2) return true;
    if (!root1 || !root2 || root1?.val !== root2?.val) return false;

    const { left: l1, right: r1 } = root1;
    const { left: l2, right: r2 } = root2;

    return (flipEquiv(l1, l2) && flipEquiv(r1, r2)) || (flipEquiv(l1, r2) && flipEquiv(r1, l2));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们可以为二叉树 <strong>T</strong> 定义一个&nbsp;<strong>翻转操作&nbsp;</strong>，如下所示：选择任意节点，然后交换它的左子树和右子树。</p>

<p>只要经过一定次数的翻转操作后，能使 <strong>X</strong> 等于 <strong>Y</strong>，我们就称二叉树 <strong>X</strong> <em>翻转 等价&nbsp;</em>于二叉树 <strong>Y</strong>。</p>

<p>这些树由根节点&nbsp;<code>root1</code> 和 <code>root2</code>&nbsp;给出。如果两个二叉树是否是<em>翻转 等价&nbsp;</em>的树，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="Flipped Trees Diagram" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0951.Flip%20Equivalent%20Binary%20Trees/images/tree_ex.png" /></p>

<pre>
<strong>输入：</strong>root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
<strong>输出：</strong>true
<strong>解释：</strong>我们翻转值为 1，3 以及 5 的三个节点。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> root1 = [], root2 = []
<strong>输出:</strong> true
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> root1 = [], root2 = [1]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树节点数在&nbsp;<code>[0, 100]</code> 范围内</li>
	<li>每棵树中的每个值都是唯一的、在 <code>[0, 99]</code>&nbsp;范围内的整数</li>
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
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root1, root2):
            if root1 == root2 or (root1 is None and root2 is None):
                return True
            if root1 is None or root2 is None or root1.val != root2.val:
                return False
            return (dfs(root1.left, root2.left) and dfs(root1.right, root2.right)) or (
                dfs(root1.left, root2.right) and dfs(root1.right, root2.left)
            )

        return dfs(root1, root2)
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
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        return dfs(root1, root2);
    }

    private boolean dfs(TreeNode root1, TreeNode root2) {
        if (root1 == root2 || (root1 == null && root2 == null)) {
            return true;
        }
        if (root1 == null || root2 == null || root1.val != root2.val) {
            return false;
        }
        return (dfs(root1.left, root2.left) && dfs(root1.right, root2.right))
            || (dfs(root1.left, root2.right) && dfs(root1.right, root2.left));
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }

    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2 || (!root1 && !root2)) return true;
        if (!root1 || !root2 || root1->val != root2->val) return false;
        return (dfs(root1->left, root2->left) && dfs(root1->right, root2->right)) || (dfs(root1->left, root2->right) && dfs(root1->right, root2->left));
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
func flipEquiv(root1 *TreeNode, root2 *TreeNode) bool {
	var dfs func(root1, root2 *TreeNode) bool
	dfs = func(root1, root2 *TreeNode) bool {
		if root1 == root2 || (root1 == nil && root2 == nil) {
			return true
		}
		if root1 == nil || root2 == nil || root1.Val != root2.Val {
			return false
		}
		return (dfs(root1.Left, root2.Left) && dfs(root1.Right, root2.Right)) || (dfs(root1.Left, root2.Right) && dfs(root1.Right, root2.Left))
	}
	return dfs(root1, root2)
}
```

#### TypeScript

```ts
function flipEquiv(root1: TreeNode | null, root2: TreeNode | null): boolean {
    if (root1 === root2) return true;
    if (!root1 || !root2 || root1?.val !== root2?.val) return false;

    const { left: l1, right: r1 } = root1!;
    const { left: l2, right: r2 } = root2!;

    return (flipEquiv(l1, l2) && flipEquiv(r1, r2)) || (flipEquiv(l1, r2) && flipEquiv(r1, l2));
}
```

#### JavaScript

```js
function flipEquiv(root1, root2) {
    if (root1 === root2) return true;
    if (!root1 || !root2 || root1?.val !== root2?.val) return false;

    const { left: l1, right: r1 } = root1;
    const { left: l2, right: r2 } = root2;

    return (flipEquiv(l1, l2) && flipEquiv(r1, r2)) || (flipEquiv(l1, r2) && flipEquiv(r1, l2));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [952. 按公因数计算最大组件大小](https://leetcode.cn/problems/largest-component-size-by-common-factor){#952}

{{< tabs "952" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            self.p[pa] = pb

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]


class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        uf = UnionFind(max(nums) + 1)
        for v in nums:
            i = 2
            while i <= v // i:
                if v % i == 0:
                    uf.union(v, i)
                    uf.union(v, v // i)
                i += 1
        return max(Counter(uf.find(v) for v in nums).values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    int[] p;

    UnionFind(int n) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}

class Solution {
    public int largestComponentSize(int[] nums) {
        int m = 0;
        for (int v : nums) {
            m = Math.max(m, v);
        }
        UnionFind uf = new UnionFind(m + 1);
        for (int v : nums) {
            int i = 2;
            while (i <= v / i) {
                if (v % i == 0) {
                    uf.union(v, i);
                    uf.union(v, v / i);
                }
                ++i;
            }
        }
        int[] cnt = new int[m + 1];
        int ans = 0;
        for (int v : nums) {
            int t = uf.find(v);
            ++cnt[t];
            ans = Math.max(ans, cnt[t]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    vector<int> p;
    int n;

    UnionFind(int _n)
        : n(_n)
        , p(_n) {
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) p[pa] = pb;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind* uf = new UnionFind(m + 1);
        for (int v : nums) {
            int i = 2;
            while (i <= v / i) {
                if (v % i == 0) {
                    uf->unite(v, i);
                    uf->unite(v, v / i);
                }
                ++i;
            }
        }
        vector<int> cnt(m + 1);
        int ans = 0;
        for (int v : nums) {
            int t = uf->find(v);
            ++cnt[t];
            ans = max(ans, cnt[t]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestComponentSize(nums []int) int {
	m := slices.Max(nums)
	p := make([]int, m+1)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa != pb {
			p[pa] = pb
		}
	}
	for _, v := range nums {
		i := 2
		for i <= v/i {
			if v%i == 0 {
				union(v, i)
				union(v, v/i)
			}
			i++
		}
	}
	cnt := make([]int, m+1)
	for _, v := range nums {
		t := find(v)
		cnt[t]++
	}
	return slices.Max(cnt)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由不同正整数的组成的非空数组&nbsp;<code>nums</code> ，考虑下面的图：</p>

<ul>
	<li>有&nbsp;<code>nums.length</code>&nbsp;个节点，按从&nbsp;<code>nums[0]</code>&nbsp;到&nbsp;<code>nums[nums.length - 1]</code>&nbsp;标记；</li>
	<li>只有当&nbsp;<code>nums[i]</code>&nbsp;和&nbsp;<code>nums[j]</code>&nbsp;共用一个大于 1 的公因数时，<code>nums[i]</code>&nbsp;和&nbsp;<code>nums[j]</code>之间才有一条边。</li>
</ul>

<p>返回 <em>图中最大连通组件的大小</em> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0952.Largest%20Component%20Size%20by%20Common%20Factor/images/ex1.png" style="height: 97px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>nums = [4,6,15,35]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0952.Largest%20Component%20Size%20by%20Common%20Factor/images/ex2.png" style="height: 85px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>nums = [20,50,9,63]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0952.Largest%20Component%20Size%20by%20Common%20Factor/images/ex3.png" style="height: 260px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>nums = [2,3,6,7,4,12,21,39]
<strong>输出：</strong>8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code>&nbsp;中所有值都 <strong>不同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 并查集

利用“试除法”，对 $nums$ 中的每个数 $v$ 分解因数，然后将每个因数 $i$ 与 $v$ 合并，$v / i$ 与 $v$ 合并。此过程用并查集来维护连通分量。

最后，遍历 $nums$ 中每个数 $v$，找出所在的连通分量，出现次数最多的连通分量就是所求的答案。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            self.p[pa] = pb

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]


class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        uf = UnionFind(max(nums) + 1)
        for v in nums:
            i = 2
            while i <= v // i:
                if v % i == 0:
                    uf.union(v, i)
                    uf.union(v, v // i)
                i += 1
        return max(Counter(uf.find(v) for v in nums).values())
```

#### Java

```java
class UnionFind {
    int[] p;

    UnionFind(int n) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}

class Solution {
    public int largestComponentSize(int[] nums) {
        int m = 0;
        for (int v : nums) {
            m = Math.max(m, v);
        }
        UnionFind uf = new UnionFind(m + 1);
        for (int v : nums) {
            int i = 2;
            while (i <= v / i) {
                if (v % i == 0) {
                    uf.union(v, i);
                    uf.union(v, v / i);
                }
                ++i;
            }
        }
        int[] cnt = new int[m + 1];
        int ans = 0;
        for (int v : nums) {
            int t = uf.find(v);
            ++cnt[t];
            ans = Math.max(ans, cnt[t]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    vector<int> p;
    int n;

    UnionFind(int _n)
        : n(_n)
        , p(_n) {
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) p[pa] = pb;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind* uf = new UnionFind(m + 1);
        for (int v : nums) {
            int i = 2;
            while (i <= v / i) {
                if (v % i == 0) {
                    uf->unite(v, i);
                    uf->unite(v, v / i);
                }
                ++i;
            }
        }
        vector<int> cnt(m + 1);
        int ans = 0;
        for (int v : nums) {
            int t = uf->find(v);
            ++cnt[t];
            ans = max(ans, cnt[t]);
        }
        return ans;
    }
};
```

#### Go

```go
func largestComponentSize(nums []int) int {
	m := slices.Max(nums)
	p := make([]int, m+1)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa != pb {
			p[pa] = pb
		}
	}
	for _, v := range nums {
		i := 2
		for i <= v/i {
			if v%i == 0 {
				union(v, i)
				union(v, v/i)
			}
			i++
		}
	}
	cnt := make([]int, m+1)
	for _, v := range nums {
		t := find(v)
		cnt[t]++
	}
	return slices.Max(cnt)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [953. 验证外星语词典](https://leetcode.cn/problems/verifying-an-alien-dictionary){#953}

{{< tabs "953" >}}

{{% tab "python" %}}
```python
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        m = {c: i for i, c in enumerate(order)}
        for i in range(20):
            prev = -1
            valid = True
            for x in words:
                curr = -1 if i >= len(x) else m[x[i]]
                if prev > curr:
                    return False
                if prev == curr:
                    valid = False
                prev = curr
            if valid:
                return True
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] m = new int[26];
        for (int i = 0; i < 26; ++i) {
            m[order.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < 20; ++i) {
            int prev = -1;
            boolean valid = true;
            for (String x : words) {
                int curr = i >= x.length() ? -1 : m[x.charAt(i) - 'a'];
                if (prev > curr) {
                    return false;
                }
                if (prev == curr) {
                    valid = false;
                }
                prev = curr;
            }
            if (valid) {
                break;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26);
        for (int i = 0; i < 26; ++i) m[order[i] - 'a'] = i;
        for (int i = 0; i < 20; ++i) {
            int prev = -1;
            bool valid = true;
            for (auto& x : words) {
                int curr = i >= x.size() ? -1 : m[x[i] - 'a'];
                if (prev > curr) return false;
                if (prev == curr) valid = false;
                prev = curr;
            }
            if (valid) break;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isAlienSorted(words []string, order string) bool {
	m := make([]int, 26)
	for i, c := range order {
		m[c-'a'] = i
	}
	for i := 0; i < 20; i++ {
		prev := -1
		valid := true
		for _, x := range words {
			curr := -1
			if i < len(x) {
				curr = m[x[i]-'a']
			}
			if prev > curr {
				return false
			}
			if prev == curr {
				valid = false
			}
			prev = curr
		}
		if valid {
			break
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isAlienSorted(words: string[], order: string): boolean {
    const map = new Map();
    for (const c of order) {
        map.set(c, map.size);
    }
    const n = words.length;
    for (let i = 1; i < n; i++) {
        const s1 = words[i - 1];
        const s2 = words[i];
        const m = Math.min(s1.length, s2.length);
        let isEqual = false;
        for (let j = 0; j < m; j++) {
            if (map.get(s1[j]) > map.get(s2[j])) {
                return false;
            }
            if (map.get(s1[j]) < map.get(s2[j])) {
                isEqual = true;
                break;
            }
        }
        if (!isEqual && s1.length > s2.length) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let n = words.len();
        let mut map = HashMap::new();
        order.as_bytes().iter().enumerate().for_each(|(i, &v)| {
            map.insert(v, i);
        });
        for i in 1..n {
            let s1 = words[i - 1].as_bytes();
            let s2 = words[i].as_bytes();
            let mut is_equal = true;
            for i in 0..s1.len().min(s2.len()) {
                if map.get(&s1[i]) > map.get(&s2[i]) {
                    return false;
                }
                if map.get(&s1[i]) < map.get(&s2[i]) {
                    is_equal = false;
                    break;
                }
            }
            if is_equal && s1.len() > s2.len() {
                return false;
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool isAlienSorted(char** words, int wordsSize, char* order) {
    int map[26] = {0};
    for (int i = 0; i < 26; i++) {
        map[order[i] - 'a'] = i;
    }
    for (int i = 1; i < wordsSize; i++) {
        char* s1 = words[i - 1];
        char* s2 = words[i];
        int n = strlen(s1);
        int m = strlen(s2);
        int len = min(n, m);
        int isEqual = 1;
        for (int j = 0; j < len; j++) {
            if (map[s1[j] - 'a'] > map[s2[j] - 'a']) {
                return 0;
            }
            if (map[s1[j] - 'a'] < map[s2[j] - 'a']) {
                isEqual = 0;
                break;
            }
        }
        if (isEqual && n > m) {
            return 0;
        }
    }
    return 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>某种外星语也使用英文小写字母，但可能顺序 <code>order</code> 不同。字母表的顺序（<code>order</code>）是一些小写字母的排列。</p>

<p>给定一组用外星语书写的单词 <code>words</code>，以及其字母表的顺序 <code>order</code>，只有当给定的单词在这种外星语中按字典序排列时，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
<strong>输出：</strong>true
<strong>解释：</strong>在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
<strong>输出：</strong>false
<strong>解释：</strong>在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
<strong>输出：</strong>false
<strong>解释：</strong>当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（<a href="https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F" target="_blank">更多信息</a>）。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 100</code></li>
	<li><code>1 <= words[i].length <= 20</code></li>
	<li><code>order.length == 26</code></li>
	<li>在 <code>words[i]</code> 和 <code>order</code> 中的所有字符都是英文小写字母。</li>
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
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        m = {c: i for i, c in enumerate(order)}
        for i in range(20):
            prev = -1
            valid = True
            for x in words:
                curr = -1 if i >= len(x) else m[x[i]]
                if prev > curr:
                    return False
                if prev == curr:
                    valid = False
                prev = curr
            if valid:
                return True
        return True
```

#### Java

```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] m = new int[26];
        for (int i = 0; i < 26; ++i) {
            m[order.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < 20; ++i) {
            int prev = -1;
            boolean valid = true;
            for (String x : words) {
                int curr = i >= x.length() ? -1 : m[x.charAt(i) - 'a'];
                if (prev > curr) {
                    return false;
                }
                if (prev == curr) {
                    valid = false;
                }
                prev = curr;
            }
            if (valid) {
                break;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26);
        for (int i = 0; i < 26; ++i) m[order[i] - 'a'] = i;
        for (int i = 0; i < 20; ++i) {
            int prev = -1;
            bool valid = true;
            for (auto& x : words) {
                int curr = i >= x.size() ? -1 : m[x[i] - 'a'];
                if (prev > curr) return false;
                if (prev == curr) valid = false;
                prev = curr;
            }
            if (valid) break;
        }
        return true;
    }
};
```

#### Go

```go
func isAlienSorted(words []string, order string) bool {
	m := make([]int, 26)
	for i, c := range order {
		m[c-'a'] = i
	}
	for i := 0; i < 20; i++ {
		prev := -1
		valid := true
		for _, x := range words {
			curr := -1
			if i < len(x) {
				curr = m[x[i]-'a']
			}
			if prev > curr {
				return false
			}
			if prev == curr {
				valid = false
			}
			prev = curr
		}
		if valid {
			break
		}
	}
	return true
}
```

#### TypeScript

```ts
function isAlienSorted(words: string[], order: string): boolean {
    const map = new Map();
    for (const c of order) {
        map.set(c, map.size);
    }
    const n = words.length;
    for (let i = 1; i < n; i++) {
        const s1 = words[i - 1];
        const s2 = words[i];
        const m = Math.min(s1.length, s2.length);
        let isEqual = false;
        for (let j = 0; j < m; j++) {
            if (map.get(s1[j]) > map.get(s2[j])) {
                return false;
            }
            if (map.get(s1[j]) < map.get(s2[j])) {
                isEqual = true;
                break;
            }
        }
        if (!isEqual && s1.length > s2.length) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let n = words.len();
        let mut map = HashMap::new();
        order.as_bytes().iter().enumerate().for_each(|(i, &v)| {
            map.insert(v, i);
        });
        for i in 1..n {
            let s1 = words[i - 1].as_bytes();
            let s2 = words[i].as_bytes();
            let mut is_equal = true;
            for i in 0..s1.len().min(s2.len()) {
                if map.get(&s1[i]) > map.get(&s2[i]) {
                    return false;
                }
                if map.get(&s1[i]) < map.get(&s2[i]) {
                    is_equal = false;
                    break;
                }
            }
            if is_equal && s1.len() > s2.len() {
                return false;
            }
        }
        true
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool isAlienSorted(char** words, int wordsSize, char* order) {
    int map[26] = {0};
    for (int i = 0; i < 26; i++) {
        map[order[i] - 'a'] = i;
    }
    for (int i = 1; i < wordsSize; i++) {
        char* s1 = words[i - 1];
        char* s2 = words[i];
        int n = strlen(s1);
        int m = strlen(s2);
        int len = min(n, m);
        int isEqual = 1;
        for (int j = 0; j < len; j++) {
            if (map[s1[j] - 'a'] > map[s2[j] - 'a']) {
                return 0;
            }
            if (map[s1[j] - 'a'] < map[s2[j] - 'a']) {
                isEqual = 0;
                break;
            }
        }
        if (isEqual && n > m) {
            return 0;
        }
    }
    return 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [954. 二倍数对数组](https://leetcode.cn/problems/array-of-doubled-pairs){#954}

{{< tabs "954" >}}

{{% tab "python" %}}
```python
class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        freq = Counter(arr)
        if freq[0] & 1:
            return False
        for x in sorted(freq, key=abs):
            if freq[x << 1] < freq[x]:
                return False
            freq[x << 1] -= freq[x]
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int v : arr) {
            freq.put(v, freq.getOrDefault(v, 0) + 1);
        }
        if ((freq.getOrDefault(0, 0) & 1) != 0) {
            return false;
        }
        List<Integer> keys = new ArrayList<>(freq.keySet());
        keys.sort(Comparator.comparingInt(Math::abs));
        for (int k : keys) {
            if (freq.getOrDefault(k << 1, 0) < freq.get(k)) {
                return false;
            }
            freq.put(k << 1, freq.getOrDefault(k << 1, 0) - freq.get(k));
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int& v : arr) ++freq[v];
        if (freq[0] & 1) return false;
        vector<int> keys;
        for (auto& [k, _] : freq) keys.push_back(k);
        sort(keys.begin(), keys.end(), [](int a, int b) { return abs(a) < abs(b); });
        for (int& k : keys) {
            if (freq[k * 2] < freq[k]) return false;
            freq[k * 2] -= freq[k];
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canReorderDoubled(arr []int) bool {
	freq := make(map[int]int)
	for _, v := range arr {
		freq[v]++
	}
	if freq[0]%2 != 0 {
		return false
	}
	var keys []int
	for k := range freq {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool {
		return abs(keys[i]) < abs(keys[j])
	})
	for _, k := range keys {
		if freq[k*2] < freq[k] {
			return false
		}
		freq[k*2] -= freq[k]
	}
	return true
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

<p>给定一个长度为偶数的整数数组 <code>arr</code>，只有对 <code>arr</code> 进行重组后可以满足 “对于每个 <code>0 &lt;=&nbsp;i &lt; len(arr) / 2</code>，都有 <code>arr[2 * i + 1] = 2 * arr[2 * i]</code>”&nbsp;时，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,1,3,6]
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,1,2,6]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [4,-2,2,-4]
<strong>输出：</strong>true
<strong>解释：</strong>可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr.length</code> 是偶数</li>
	<li><code>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        freq = Counter(arr)
        if freq[0] & 1:
            return False
        for x in sorted(freq, key=abs):
            if freq[x << 1] < freq[x]:
                return False
            freq[x << 1] -= freq[x]
        return True
```

#### Java

```java
class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int v : arr) {
            freq.put(v, freq.getOrDefault(v, 0) + 1);
        }
        if ((freq.getOrDefault(0, 0) & 1) != 0) {
            return false;
        }
        List<Integer> keys = new ArrayList<>(freq.keySet());
        keys.sort(Comparator.comparingInt(Math::abs));
        for (int k : keys) {
            if (freq.getOrDefault(k << 1, 0) < freq.get(k)) {
                return false;
            }
            freq.put(k << 1, freq.getOrDefault(k << 1, 0) - freq.get(k));
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int& v : arr) ++freq[v];
        if (freq[0] & 1) return false;
        vector<int> keys;
        for (auto& [k, _] : freq) keys.push_back(k);
        sort(keys.begin(), keys.end(), [](int a, int b) { return abs(a) < abs(b); });
        for (int& k : keys) {
            if (freq[k * 2] < freq[k]) return false;
            freq[k * 2] -= freq[k];
        }
        return true;
    }
};
```

#### Go

```go
func canReorderDoubled(arr []int) bool {
	freq := make(map[int]int)
	for _, v := range arr {
		freq[v]++
	}
	if freq[0]%2 != 0 {
		return false
	}
	var keys []int
	for k := range freq {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool {
		return abs(keys[i]) < abs(keys[j])
	})
	for _, k := range keys {
		if freq[k*2] < freq[k] {
			return false
		}
		freq[k*2] -= freq[k]
	}
	return true
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

# [955. 删列造序 II](https://leetcode.cn/problems/delete-columns-to-make-sorted-ii){#955}

{{< tabs "955" >}}

{{% tab "java" %}}
```java
class Solution {
    public int minDeletionSize(String[] A) {
        if (A == null || A.length <= 1) {
            return 0;
        }
        int len = A.length, wordLen = A[0].length(), res = 0;
        boolean[] cut = new boolean[len];
    search:
        for (int j = 0; j < wordLen; j++) {
            // 判断第 j 列是否应当保留
            for (int i = 0; i < len - 1; i++) {
                if (!cut[i] && A[i].charAt(j) > A[i + 1].charAt(j)) {
                    res += 1;
                    continue search;
                }
            }
            // 更新 cut 的信息
            for (int i = 0; i < len - 1; i++) {
                if (A[i].charAt(j) < A[i + 1].charAt(j)) {
                    cut[i] = true;
                }
            }
        }
        return res;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定由 <code>n</code> 个字符串组成的数组 <code>strs</code>，其中每个字符串长度相等。</p>

<p>选取一个删除索引序列，对于 <code>strs</code> 中的每个字符串，删除对应每个索引处的字符。</p>

<p>比如，有 <code>strs = ["abcdef", "uvwxyz"]</code>，删除索引序列 <code>{0, 2, 3}</code>，删除后 <code>strs</code> 为<code>["bef", "vyz"]</code>。</p>

<p>假设，我们选择了一组删除索引 <code>answer</code>，那么在执行删除操作之后，最终得到的数组的元素是按 <strong>字典序</strong>（<code>strs[0] <= strs[1] <= strs[2] ... <= strs[n - 1]</code>）排列的，然后请你返回 <code>answer.length</code> 的最小可能值。</p>

<p> </p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["ca","bb","ac"]
<strong>输出：</strong>1
<strong>解释： </strong>
删除第一列后，strs = ["a", "b", "c"]。
现在 strs 中元素是按字典排列的 (即，strs[0] <= strs[1] <= strs[2])。
我们至少需要进行 1 次删除，因为最初 strs 不是按字典序排列的，所以答案是 1。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["xc","yb","za"]
<strong>输出：</strong>0
<strong>解释：</strong>
strs 的列已经是按字典序排列了，所以我们不需要删除任何东西。
注意 strs 的行不需要按字典序排列。
也就是说，strs[0][0] <= strs[0][1] <= ... 不一定成立。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>strs = ["zyx","wvu","tsr"]
<strong>输出：</strong>3
<strong>解释：</strong>
我们必须删掉每一列。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>1 <= strs[i].length <= 100</code></li>
	<li><code>strs[i]</code> 由小写英文字母组成</li>
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

#### Java

```java
class Solution {
    public int minDeletionSize(String[] A) {
        if (A == null || A.length <= 1) {
            return 0;
        }
        int len = A.length, wordLen = A[0].length(), res = 0;
        boolean[] cut = new boolean[len];
    search:
        for (int j = 0; j < wordLen; j++) {
            // 判断第 j 列是否应当保留
            for (int i = 0; i < len - 1; i++) {
                if (!cut[i] && A[i].charAt(j) > A[i + 1].charAt(j)) {
                    res += 1;
                    continue search;
                }
            }
            // 更新 cut 的信息
            for (int i = 0; i < len - 1; i++) {
                if (A[i].charAt(j) < A[i + 1].charAt(j)) {
                    cut[i] = true;
                }
            }
        }
        return res;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [956. 最高的广告牌](https://leetcode.cn/problems/tallest-billboard){#956}

{{< tabs "956" >}}

{{% tab "python" %}}
```python
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        n = len(rods)
        s = sum(rods)
        f = [[-inf] * (s + 1) for _ in range(n + 1)]
        f[0][0] = 0
        t = 0
        for i, x in enumerate(rods, 1):
            t += x
            for j in range(t + 1):
                f[i][j] = f[i - 1][j]
                if j >= x:
                    f[i][j] = max(f[i][j], f[i - 1][j - x])
                if j + x <= t:
                    f[i][j] = max(f[i][j], f[i - 1][j + x] + x)
                if j < x:
                    f[i][j] = max(f[i][j], f[i - 1][x - j] + x - j)
        return f[n][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int tallestBillboard(int[] rods) {
        int n = rods.length;
        int s = 0;
        for (int x : rods) {
            s += x;
        }
        int[][] f = new int[n + 1][s + 1];
        for (var e : f) {
            Arrays.fill(e, -(1 << 30));
        }
        f[0][0] = 0;
        for (int i = 1, t = 0; i <= n; ++i) {
            int x = rods[i - 1];
            t += x;
            for (int j = 0; j <= t; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= x) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - x]);
                }
                if (j + x <= t) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j + x] + x);
                }
                if (j < x) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][x - j] + x - j);
                }
            }
        }
        return f[n][0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int s = accumulate(rods.begin(), rods.end(), 0);
        int f[n + 1][s + 1];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1, t = 0; i <= n; ++i) {
            int x = rods[i - 1];
            t += x;
            for (int j = 0; j <= t; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= x) {
                    f[i][j] = max(f[i][j], f[i - 1][j - x]);
                }
                if (j + x <= t) {
                    f[i][j] = max(f[i][j], f[i - 1][j + x] + x);
                }
                if (j < x) {
                    f[i][j] = max(f[i][j], f[i - 1][x - j] + x - j);
                }
            }
        }
        return f[n][0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func tallestBillboard(rods []int) int {
	n := len(rods)
	s := 0
	for _, x := range rods {
		s += x
	}
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, s+1)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	f[0][0] = 0
	for i, t := 1, 0; i <= n; i++ {
		x := rods[i-1]
		t += x
		for j := 0; j <= t; j++ {
			f[i][j] = f[i-1][j]
			if j >= x {
				f[i][j] = max(f[i][j], f[i-1][j-x])
			}
			if j+x <= t {
				f[i][j] = max(f[i][j], f[i-1][j+x]+x)
			}
			if j < x {
				f[i][j] = max(f[i][j], f[i-1][x-j]+x-j)
			}
		}
	}
	return f[n][0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function tallestBillboard(rods: number[]): number {
    const s = rods.reduce((a, b) => a + b, 0);
    const n = rods.length;
    const f = new Array(n).fill(0).map(() => new Array(s + 1).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i >= n) {
            return j === 0 ? 0 : -(1 << 30);
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let ans = Math.max(dfs(i + 1, j), dfs(i + 1, j + rods[i]));
        ans = Math.max(ans, dfs(i + 1, Math.abs(j - rods[i])) + Math.min(j, rods[i]));
        return (f[i][j] = ans);
    };
    return dfs(0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。</p>

<p>你有一堆可以焊接在一起的钢筋 <code>rods</code>。举个例子，如果钢筋的长度为 <code>1</code>、<code>2</code> 和 <code>3</code>，则可以将它们焊接在一起形成长度为 <code>6</code>&nbsp;的支架。</p>

<p>返回 <em>广告牌的最大可能安装高度</em> 。如果没法安装广告牌，请返回 <code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[1,2,3,6]
<strong>输出：</strong>6
<strong>解释：</strong>我们有两个不相交的子集 {1,2,3} 和 {6}，它们具有相同的和 sum = 6。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[1,2,3,4,5,6]
<strong>输出：</strong>10
<strong>解释：</strong>我们有两个不相交的子集 {2,3,5} 和 {4,6}，它们具有相同的和 sum = 10。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>[1,2]
<strong>输出：</strong>0
<strong>解释：</strong>没法安装广告牌，所以返回 0。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 &lt;= rods.length &lt;= 20</code></li>
	<li><code>1 &lt;= rods[i] &lt;= 1000</code></li>
	<li><code>sum(rods[i]) &lt;= 5000</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从第 $i$ 根钢筋开始，且当前高度差为 $j$ 时，两边的最大共同高度。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算过程如下：

如果 $i=n$，此时判断 $j$ 是否为 $0$，如果是则返回 $0$，否则返回 $-\infty$。

如果 $i \lt n$，此时有三种情况：

1. 不选择第 $i$ 根钢筋，此时 $dfs(i, j) = dfs(i+1, j)$；
1. 选择第 $i$ 根钢筋，并且放置在原本高度较高的一边，那么 $dfs(i, j) = dfs(i+1, j+rods[i])$；
1. 选择第 $i$ 根钢筋，并且放置在高度较低的一边，此时共同高度增加了 $\min(j, rods[i])$，那么 $dfs(i, j) = dfs(i+1, |rods[i]-j|) + \min(j, rods[i])$。

我们取这三种情况下的最大值，即可得到 $dfs(i, j)$ 的值。

为了避免重复计算，我们使用一个二维数组 $f$ 来记录已经计算过的 $dfs(i, j)$ 的值，调用 $dfs(i, j)$ 时，如果 $f[i][j]$ 已经被计算过，则直接返回 $f[i][j]$。否则，我们计算 $dfs(i, j)$ 的值，并将其存入 $f[i][j]$。

时间复杂度 $O(n \times S)$，空间复杂度 $O(n \times S)$。其中 $n$ 和 $S$ 分别为 $rods$ 的长度和 $rods$ 中所有元素的和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= len(rods):
                return 0 if j == 0 else -inf
            ans = max(dfs(i + 1, j), dfs(i + 1, j + rods[i]))
            ans = max(ans, dfs(i + 1, abs(rods[i] - j)) + min(j, rods[i]))
            return ans

        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[] rods;
    private int n;

    public int tallestBillboard(int[] rods) {
        int s = 0;
        for (int x : rods) {
            s += x;
        }
        n = rods.length;
        this.rods = rods;
        f = new Integer[n][s + 1];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= n) {
            return j == 0 ? 0 : -(1 << 30);
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = Math.max(dfs(i + 1, j), dfs(i + 1, j + rods[i]));
        ans = Math.max(ans, dfs(i + 1, Math.abs(rods[i] - j)) + Math.min(j, rods[i]));
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int s = accumulate(rods.begin(), rods.end(), 0);
        int n = rods.size();
        int f[n][s + 1];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= n) {
                return j == 0 ? 0 : -(1 << 30);
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = max(dfs(i + 1, j), dfs(i + 1, j + rods[i]));
            ans = max(ans, dfs(i + 1, abs(j - rods[i])) + min(j, rods[i]));
            return f[i][j] = ans;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func tallestBillboard(rods []int) int {
	s := 0
	for _, x := range rods {
		s += x
	}
	n := len(rods)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, s+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= n {
			if j == 0 {
				return 0
			}
			return -(1 << 30)
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		ans := max(dfs(i+1, j), dfs(i+1, j+rods[i]))
		ans = max(ans, dfs(i+1, abs(j-rods[i]))+min(j, rods[i]))
		f[i][j] = ans
		return ans
	}
	return dfs(0, 0)
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
function tallestBillboard(rods: number[]): number {
    const s = rods.reduce((a, b) => a + b, 0);
    const n = rods.length;
    const f = new Array(n).fill(0).map(() => new Array(s + 1).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i >= n) {
            return j === 0 ? 0 : -(1 << 30);
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let ans = Math.max(dfs(i + 1, j), dfs(i + 1, j + rods[i]));
        ans = Math.max(ans, dfs(i + 1, Math.abs(j - rods[i])) + Math.min(j, rods[i]));
        return (f[i][j] = ans);
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 根钢筋，两边高度差为 $j$ 时的最大共同高度。初始时 $f[0][0]=0$，其余 $f[i][j]=-\infty$。我们求出所有 $rods[i]$ 的和，记为 $s$，那么 $j$ 的取值范围为 $[0,..s]$。

对于第 $i$ 根钢筋，我们可以不选择它，此时 $f[i][j]=f[i-1][j]$；也可以选择它，此时有三种情况：

1. 放置在原本高度较高的一边，即满足 $j \geq rods[i-1]$，此时 $f[i][j] = max(f[i][j], f[i-1][j-rods[i-1]])$；
1. 放置在原本高度较低的一遍，如果满足 $j + rods[i-1] \leq s$，此时 $f[i][j] = max(f[i][j], f[i-1][j+rods[i-1]] + rods[i-1])$；如果满足 $j \lt rods[i-1]$，此时 $f[i][j] = max(f[i][j], f[i-1][rods[i-1]-j] + rods[i-1]-j)$。

综上，我们可以得到状态转移方程：

$$
\begin{aligned}
f[i][j] &= f[i-1][j] \\
f[i][j] &= max(f[i][j], f[i-1][j-rods[i-1]]) & \textit{if } j \geq rods[i-1] \\
f[i][j] &= max(f[i][j], f[i-1][j+rods[i-1]] + rods[i-1]) & \textit{if } j + rods[i-1] \leq s \\
f[i][j] &= max(f[i][j], f[i-1][rods[i-1]-j] + rods[i-1]-j) & \textit{if } j \lt rods[i-1]
\end{aligned}
$$

最终答案即为 $f[n][0]$。

时间复杂度 $O(n \times S)$，空间复杂度 $O(n \times S)$。其中 $n$ 和 $S$ 分别为 $rods$ 的长度和 $rods$ 中所有元素的和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        n = len(rods)
        s = sum(rods)
        f = [[-inf] * (s + 1) for _ in range(n + 1)]
        f[0][0] = 0
        t = 0
        for i, x in enumerate(rods, 1):
            t += x
            for j in range(t + 1):
                f[i][j] = f[i - 1][j]
                if j >= x:
                    f[i][j] = max(f[i][j], f[i - 1][j - x])
                if j + x <= t:
                    f[i][j] = max(f[i][j], f[i - 1][j + x] + x)
                if j < x:
                    f[i][j] = max(f[i][j], f[i - 1][x - j] + x - j)
        return f[n][0]
```

#### Java

```java
class Solution {
    public int tallestBillboard(int[] rods) {
        int n = rods.length;
        int s = 0;
        for (int x : rods) {
            s += x;
        }
        int[][] f = new int[n + 1][s + 1];
        for (var e : f) {
            Arrays.fill(e, -(1 << 30));
        }
        f[0][0] = 0;
        for (int i = 1, t = 0; i <= n; ++i) {
            int x = rods[i - 1];
            t += x;
            for (int j = 0; j <= t; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= x) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - x]);
                }
                if (j + x <= t) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j + x] + x);
                }
                if (j < x) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][x - j] + x - j);
                }
            }
        }
        return f[n][0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int s = accumulate(rods.begin(), rods.end(), 0);
        int f[n + 1][s + 1];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1, t = 0; i <= n; ++i) {
            int x = rods[i - 1];
            t += x;
            for (int j = 0; j <= t; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= x) {
                    f[i][j] = max(f[i][j], f[i - 1][j - x]);
                }
                if (j + x <= t) {
                    f[i][j] = max(f[i][j], f[i - 1][j + x] + x);
                }
                if (j < x) {
                    f[i][j] = max(f[i][j], f[i - 1][x - j] + x - j);
                }
            }
        }
        return f[n][0];
    }
};
```

#### Go

```go
func tallestBillboard(rods []int) int {
	n := len(rods)
	s := 0
	for _, x := range rods {
		s += x
	}
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, s+1)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	f[0][0] = 0
	for i, t := 1, 0; i <= n; i++ {
		x := rods[i-1]
		t += x
		for j := 0; j <= t; j++ {
			f[i][j] = f[i-1][j]
			if j >= x {
				f[i][j] = max(f[i][j], f[i-1][j-x])
			}
			if j+x <= t {
				f[i][j] = max(f[i][j], f[i-1][j+x]+x)
			}
			if j < x {
				f[i][j] = max(f[i][j], f[i-1][x-j]+x-j)
			}
		}
	}
	return f[n][0]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [957. N 天后的牢房](https://leetcode.cn/problems/prison-cells-after-n-days){#957}

{{< tabs "957" >}}

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

<p>监狱中 <code>8</code> 间牢房排成一排，每间牢房可能被占用或空置。</p>

<p>每天，无论牢房是被占用或空置，都会根据以下规则进行变更：</p>

<ul>
	<li>如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。</li>
	<li>否则，它就会被空置。</li>
</ul>

<p><strong>注意</strong>：由于监狱中的牢房排成一行，所以行中的第一个和最后一个牢房不存在两个相邻的房间。</p>

<p>给你一个整数数组 <code>cells</code> ，用于表示牢房的初始状态：如果第 <code>i</code> 间牢房被占用，则 <code>cell[i]==1</code>，否则 <code>cell[i]==0</code> 。另给你一个整数 <code>n</code> 。</p>

<p>请你返回 <code>n</code> 天后监狱的状况（即，按上文描述进行 <code>n</code> 次变更）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>cells = [0,1,0,1,1,0,0,1], n = 7
<strong>输出：</strong>[0,0,1,1,0,0,0,0]
<strong>解释：</strong>下表总结了监狱每天的状况：
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>cells = [1,0,0,1,0,0,1,0], n = 1000000000
<strong>输出：</strong>[0,0,1,1,1,1,1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>cells.length == 8</code></li>
	<li><code>cells[i]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
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

# [958. 二叉树的完全性检验](https://leetcode.cn/problems/check-completeness-of-a-binary-tree){#958}

{{< tabs "958" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        q = deque([root])
        while q:
            node = q.popleft()
            if node is None:
                break
            q.append(node.left)
            q.append(node.right)
        return all(node is None for node in q)
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
    public boolean isCompleteTree(TreeNode root) {
        Deque<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (q.peek() != null) {
            TreeNode node = q.poll();
            q.offer(node.left);
            q.offer(node.right);
        }
        while (!q.isEmpty() && q.peek() == null) {
            q.poll();
        }
        return q.isEmpty();
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        while (q.front()) {
            root = q.front();
            q.pop();
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty() && !q.front()) q.pop();
        return q.empty();
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
func isCompleteTree(root *TreeNode) bool {
	q := []*TreeNode{root}
	for q[0] != nil {
		root = q[0]
		q = q[1:]
		q = append(q, root.Left)
		q = append(q, root.Right)
	}
	for len(q) > 0 && q[0] == nil {
		q = q[1:]
	}
	return len(q) == 0
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点<meta charset="UTF-8" />&nbsp;<code>root</code> ，请你判断这棵树是否是一棵 <strong>完全二叉树</strong>&nbsp;。</p>

<p>在一棵 <strong><a href="https://baike.baidu.com/item/完全二叉树/7773232?fr=aladdin" target="_blank">完全二叉树</a></strong> 中，除了最后一层外，所有层都被完全填满，并且最后一层中的所有节点都尽可能靠左。最后一层（第 <code>h</code> 层）中可以包含<meta charset="UTF-8" />&nbsp;<code>1</code>&nbsp;到<meta charset="UTF-8" />&nbsp;<code>2<sup>h</sup></code> 个节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0958.Check%20Completeness%20of%20a%20Binary%20Tree/images/complete-binary-tree-1.png" /></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6]
<strong>输出：</strong>true
<strong>解释：</strong>最后一层前的每一层都是满的（即，节点值为 {1} 和 {2,3} 的两层），且最后一层中的所有节点（{4,5,6}）尽可能靠左。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0958.Check%20Completeness%20of%20a%20Binary%20Tree/images/complete-binary-tree-2.png" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,5,null,7]
<strong>输出：</strong>false
<strong>解释：</strong>值为 7 的节点不满足条件「节点尽可能靠左」。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 100]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
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
    def isCompleteTree(self, root: TreeNode) -> bool:
        q = deque([root])
        while q:
            node = q.popleft()
            if node is None:
                break
            q.append(node.left)
            q.append(node.right)
        return all(node is None for node in q)
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
    public boolean isCompleteTree(TreeNode root) {
        Deque<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (q.peek() != null) {
            TreeNode node = q.poll();
            q.offer(node.left);
            q.offer(node.right);
        }
        while (!q.isEmpty() && q.peek() == null) {
            q.poll();
        }
        return q.isEmpty();
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        while (q.front()) {
            root = q.front();
            q.pop();
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty() && !q.front()) q.pop();
        return q.empty();
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
func isCompleteTree(root *TreeNode) bool {
	q := []*TreeNode{root}
	for q[0] != nil {
		root = q[0]
		q = q[1:]
		q = append(q, root.Left)
		q = append(q, root.Right)
	}
	for len(q) > 0 && q[0] == nil {
		q = q[1:]
	}
	return len(q) == 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [959. 由斜杠划分区域](https://leetcode.cn/problems/regions-cut-by-slashes){#959}

{{< tabs "959" >}}

{{% tab "python" %}}
```python
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                p[pa] = pb
                nonlocal size
                size -= 1

        n = len(grid)
        size = n * n * 4
        p = list(range(size))
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                k = i * n + j
                if i < n - 1:
                    union(4 * k + 2, (k + n) * 4)
                if j < n - 1:
                    union(4 * k + 1, (k + 1) * 4 + 3)
                if v == '/':
                    union(4 * k, 4 * k + 3)
                    union(4 * k + 1, 4 * k + 2)
                elif v == '\\':
                    union(4 * k, 4 * k + 1)
                    union(4 * k + 2, 4 * k + 3)
                else:
                    union(4 * k, 4 * k + 1)
                    union(4 * k + 1, 4 * k + 2)
                    union(4 * k + 2, 4 * k + 3)
        return size
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;
    private int size;

    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        size = n * n * 4;
        p = new int[size];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = i * n + j;
                if (i < n - 1) {
                    union(4 * k + 2, (k + n) * 4);
                }
                if (j < n - 1) {
                    union(4 * k + 1, (k + 1) * 4 + 3);
                }
                char v = grid[i].charAt(j);
                if (v == '/') {
                    union(4 * k, 4 * k + 3);
                    union(4 * k + 1, 4 * k + 2);
                } else if (v == '\\') {
                    union(4 * k, 4 * k + 1);
                    union(4 * k + 2, 4 * k + 3);
                } else {
                    union(4 * k, 4 * k + 1);
                    union(4 * k + 1, 4 * k + 2);
                    union(4 * k + 2, 4 * k + 3);
                }
            }
        }
        return size;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return;
        }
        p[pa] = pb;
        --size;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> p;
    int size;

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        size = n * n * 4;
        p.resize(size);
        for (int i = 0; i < size; ++i) p[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = i * n + j;
                if (i < n - 1) merge(4 * k + 2, (k + n) * 4);
                if (j < n - 1) merge(4 * k + 1, (k + 1) * 4 + 3);
                char v = grid[i][j];
                if (v == '/') {
                    merge(4 * k, 4 * k + 3);
                    merge(4 * k + 1, 4 * k + 2);
                } else if (v == '\\') {
                    merge(4 * k, 4 * k + 1);
                    merge(4 * k + 2, 4 * k + 3);
                } else {
                    merge(4 * k, 4 * k + 1);
                    merge(4 * k + 1, 4 * k + 2);
                    merge(4 * k + 2, 4 * k + 3);
                }
            }
        }
        return size;
    }

    void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;
        p[pa] = pb;
        --size;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func regionsBySlashes(grid []string) int {
	n := len(grid)
	size := n * n * 4
	p := make([]int, size)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa == pb {
			return
		}
		p[pa] = pb
		size--
	}
	for i, row := range grid {
		for j, v := range row {
			k := i*n + j
			if i < n-1 {
				union(4*k+2, (k+n)*4)
			}
			if j < n-1 {
				union(4*k+1, (k+1)*4+3)
			}
			if v == '/' {
				union(4*k, 4*k+3)
				union(4*k+1, 4*k+2)
			} else if v == '\\' {
				union(4*k, 4*k+1)
				union(4*k+2, 4*k+3)
			} else {
				union(4*k, 4*k+1)
				union(4*k+1, 4*k+2)
				union(4*k+2, 4*k+3)
			}
		}
	}
	return size
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function regionsBySlashes(grid: string[]): number {
    const createGraph = () => {
        const n = grid.length;
        const g = Array.from({ length: n * 2 }, () => Array(n * 2).fill(0));

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                const [y, x] = [i * 2, j * 2];

                switch (grid[i][j]) {
                    case '/':
                        g[y][x] = g[y + 1][x + 1] = 0;
                        g[y][x + 1] = g[y + 1][x] = 1;
                        break;

                    case '\\':
                        g[y][x] = g[y + 1][x + 1] = 2;
                        g[y][x + 1] = g[y + 1][x] = 0;
                        break;

                    default:
                        g[y][x] = g[y][x + 1] = g[y + 1][x] = g[y + 1][x + 1] = 0;
                        break;
                }
            }
        }

        return g;
    };

    const isValid = (x: number) => 0 <= x && x < n;
    const dfs = (i: number, j: number) => {
        if (!isValid(i) || !isValid(j) || g[i][j]) return;

        g[i][j] = -1;
        const dirs = [-1, 0, 1, 0, -1];
        const neighbours: number[] = [];

        for (let d = 0; d < 4; d++) {
            const [y, x] = [i + dirs[d], j + dirs[d + 1]];

            if (isValid(y) && isValid(x)) {
                dfs(y, x);
                neighbours.push(g[y][x]);
            } else {
                neighbours.push(-1);
            }
        }

        const [top, right, bottom, left] = neighbours;
        if (top === 1 && right === 1) dfs(i - 1, j + 1);
        if (bottom === 1 && left === 1) dfs(i + 1, j - 1);
        if (top === 2 && left === 2) dfs(i - 1, j - 1);
        if (bottom === 2 && right === 2) dfs(i + 1, j + 1);
    };

    const g = createGraph();
    const n = g.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (g[i][j] === 0) {
                dfs(i, j);
                res++;
            }
        }
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function regionsBySlashes(grid) {
    const createGraph = () => {
        const n = grid.length;
        const g = Array.from({ length: n * 2 }, () => Array(n * 2).fill(0));

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                const [y, x] = [i * 2, j * 2];

                switch (grid[i][j]) {
                    case '/':
                        g[y][x] = g[y + 1][x + 1] = 0;
                        g[y][x + 1] = g[y + 1][x] = 1;
                        break;

                    case '\\':
                        g[y][x] = g[y + 1][x + 1] = 2;
                        g[y][x + 1] = g[y + 1][x] = 0;
                        break;

                    default:
                        g[y][x] = g[y][x + 1] = g[y + 1][x] = g[y + 1][x + 1] = 0;
                        break;
                }
            }
        }

        return g;
    };

    const isValid = x => 0 <= x && x < n;
    const dfs = (i, j) => {
        if (!isValid(i) || !isValid(j) || g[i][j]) return;

        g[i][j] = -1;
        const dirs = [-1, 0, 1, 0, -1];
        const neighbours = [];

        for (let d = 0; d < 4; d++) {
            const [y, x] = [i + dirs[d], j + dirs[d + 1]];

            if (isValid(y) && isValid(x)) {
                dfs(y, x);
                neighbours.push(g[y][x]);
            } else {
                neighbours.push(-1);
            }
        }

        const [top, right, bottom, left] = neighbours;
        if (top === 1 && right === 1) dfs(i - 1, j + 1);
        if (bottom === 1 && left === 1) dfs(i + 1, j - 1);
        if (top === 2 && left === 2) dfs(i - 1, j - 1);
        if (bottom === 2 && right === 2) dfs(i + 1, j + 1);
    };

    const g = createGraph();
    const n = g.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (g[i][j] === 0) {
                dfs(i, j);
                res++;
            }
        }
    }

    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在由 <code>1 x 1</code> 方格组成的 <code>n&nbsp;x n</code>&nbsp;网格&nbsp;<code>grid</code> 中，每个 <code>1 x 1</code>&nbsp;方块由 <code>'/'</code>、<code>'\'</code> 或空格构成。这些字符会将方块划分为一些共边的区域。</p>

<p>给定网格&nbsp;<code>grid</code>&nbsp;表示为一个字符串数组，返回 <em>区域的数量</em> 。</p>

<p>请注意，反斜杠字符是转义的，因此&nbsp;<code>'\'</code> 用 <code>'\\'</code>&nbsp;表示。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0959.Regions%20Cut%20By%20Slashes/images/1.png" style="height: 200px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>grid = [" /","/ "]
<strong>输出：</strong>2</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0959.Regions%20Cut%20By%20Slashes/images/2.png" style="height: 198px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>grid = [" /","  "]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0959.Regions%20Cut%20By%20Slashes/images/4.png" style="height: 200px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>grid = ["/\\","\\/"]
<strong>输出：</strong>5
<strong>解释：</strong>回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>grid[i][j]</code> 是&nbsp;<code>'/'</code>、<code>'\'</code>、或&nbsp;<code>' '</code></li>
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
    def regionsBySlashes(self, grid: List[str]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                p[pa] = pb
                nonlocal size
                size -= 1

        n = len(grid)
        size = n * n * 4
        p = list(range(size))
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                k = i * n + j
                if i < n - 1:
                    union(4 * k + 2, (k + n) * 4)
                if j < n - 1:
                    union(4 * k + 1, (k + 1) * 4 + 3)
                if v == '/':
                    union(4 * k, 4 * k + 3)
                    union(4 * k + 1, 4 * k + 2)
                elif v == '\\':
                    union(4 * k, 4 * k + 1)
                    union(4 * k + 2, 4 * k + 3)
                else:
                    union(4 * k, 4 * k + 1)
                    union(4 * k + 1, 4 * k + 2)
                    union(4 * k + 2, 4 * k + 3)
        return size
```

#### Java

```java
class Solution {
    private int[] p;
    private int size;

    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        size = n * n * 4;
        p = new int[size];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = i * n + j;
                if (i < n - 1) {
                    union(4 * k + 2, (k + n) * 4);
                }
                if (j < n - 1) {
                    union(4 * k + 1, (k + 1) * 4 + 3);
                }
                char v = grid[i].charAt(j);
                if (v == '/') {
                    union(4 * k, 4 * k + 3);
                    union(4 * k + 1, 4 * k + 2);
                } else if (v == '\\') {
                    union(4 * k, 4 * k + 1);
                    union(4 * k + 2, 4 * k + 3);
                } else {
                    union(4 * k, 4 * k + 1);
                    union(4 * k + 1, 4 * k + 2);
                    union(4 * k + 2, 4 * k + 3);
                }
            }
        }
        return size;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return;
        }
        p[pa] = pb;
        --size;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> p;
    int size;

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        size = n * n * 4;
        p.resize(size);
        for (int i = 0; i < size; ++i) p[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = i * n + j;
                if (i < n - 1) merge(4 * k + 2, (k + n) * 4);
                if (j < n - 1) merge(4 * k + 1, (k + 1) * 4 + 3);
                char v = grid[i][j];
                if (v == '/') {
                    merge(4 * k, 4 * k + 3);
                    merge(4 * k + 1, 4 * k + 2);
                } else if (v == '\\') {
                    merge(4 * k, 4 * k + 1);
                    merge(4 * k + 2, 4 * k + 3);
                } else {
                    merge(4 * k, 4 * k + 1);
                    merge(4 * k + 1, 4 * k + 2);
                    merge(4 * k + 2, 4 * k + 3);
                }
            }
        }
        return size;
    }

    void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;
        p[pa] = pb;
        --size;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```

#### Go

```go
func regionsBySlashes(grid []string) int {
	n := len(grid)
	size := n * n * 4
	p := make([]int, size)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa == pb {
			return
		}
		p[pa] = pb
		size--
	}
	for i, row := range grid {
		for j, v := range row {
			k := i*n + j
			if i < n-1 {
				union(4*k+2, (k+n)*4)
			}
			if j < n-1 {
				union(4*k+1, (k+1)*4+3)
			}
			if v == '/' {
				union(4*k, 4*k+3)
				union(4*k+1, 4*k+2)
			} else if v == '\\' {
				union(4*k, 4*k+1)
				union(4*k+2, 4*k+3)
			} else {
				union(4*k, 4*k+1)
				union(4*k+1, 4*k+2)
				union(4*k+2, 4*k+3)
			}
		}
	}
	return size
}
```

#### TypeScript

```ts
function regionsBySlashes(grid: string[]): number {
    const find = (x: number) => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };

    const union = (a: number, b: number) => {
        const pa = find(a);
        const pb = find(b);
        if (pa !== pb) {
            p[pa] = pb;
            size--;
        }
    };

    const n = grid.length;
    let size = n * n * 4;
    const p = Array.from({ length: size }, (_, i) => i);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const k = i * n + j;
            if (i < n - 1) {
                union(4 * k + 2, (k + n) * 4);
            }
            if (j < n - 1) {
                union(4 * k + 1, (k + 1) * 4 + 3);
            }
            if (grid[i][j] === '/') {
                union(4 * k, 4 * k + 3);
                union(4 * k + 1, 4 * k + 2);
            } else if (grid[i][j] === '\\') {
                union(4 * k, 4 * k + 1);
                union(4 * k + 2, 4 * k + 3);
            } else {
                union(4 * k, 4 * k + 1);
                union(4 * k + 1, 4 * k + 2);
                union(4 * k + 2, 4 * k + 3);
            }
        }
    }

    return size;
}
```

#### JavaScript

```js
/**
 * @param {string[]} grid
 * @return {number}
 */

function regionsBySlashes(grid) {
    const find = x => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };

    const union = (a, b) => {
        const pa = find(a);
        const pb = find(b);
        if (pa !== pb) {
            p[pa] = pb;
            size--;
        }
    };

    const n = grid.length;
    let size = n * n * 4;
    const p = Array.from({ length: size }, (_, i) => i);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const k = i * n + j;
            if (i < n - 1) {
                union(4 * k + 2, (k + n) * 4);
            }
            if (j < n - 1) {
                union(4 * k + 1, (k + 1) * 4 + 3);
            }
            if (grid[i][j] === '/') {
                union(4 * k, 4 * k + 3);
                union(4 * k + 1, 4 * k + 2);
            } else if (grid[i][j] === '\\') {
                union(4 * k, 4 * k + 1);
                union(4 * k + 2, 4 * k + 3);
            } else {
                union(4 * k, 4 * k + 1);
                union(4 * k + 1, 4 * k + 2);
                union(4 * k + 2, 4 * k + 3);
            }
        }
    }

    return size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

<!-- tabs:start -->

#### TypeScript

```ts
function regionsBySlashes(grid: string[]): number {
    const createGraph = () => {
        const n = grid.length;
        const g = Array.from({ length: n * 2 }, () => Array(n * 2).fill(0));

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                const [y, x] = [i * 2, j * 2];

                switch (grid[i][j]) {
                    case '/':
                        g[y][x] = g[y + 1][x + 1] = 0;
                        g[y][x + 1] = g[y + 1][x] = 1;
                        break;

                    case '\\':
                        g[y][x] = g[y + 1][x + 1] = 2;
                        g[y][x + 1] = g[y + 1][x] = 0;
                        break;

                    default:
                        g[y][x] = g[y][x + 1] = g[y + 1][x] = g[y + 1][x + 1] = 0;
                        break;
                }
            }
        }

        return g;
    };

    const isValid = (x: number) => 0 <= x && x < n;
    const dfs = (i: number, j: number) => {
        if (!isValid(i) || !isValid(j) || g[i][j]) return;

        g[i][j] = -1;
        const dirs = [-1, 0, 1, 0, -1];
        const neighbours: number[] = [];

        for (let d = 0; d < 4; d++) {
            const [y, x] = [i + dirs[d], j + dirs[d + 1]];

            if (isValid(y) && isValid(x)) {
                dfs(y, x);
                neighbours.push(g[y][x]);
            } else {
                neighbours.push(-1);
            }
        }

        const [top, right, bottom, left] = neighbours;
        if (top === 1 && right === 1) dfs(i - 1, j + 1);
        if (bottom === 1 && left === 1) dfs(i + 1, j - 1);
        if (top === 2 && left === 2) dfs(i - 1, j - 1);
        if (bottom === 2 && right === 2) dfs(i + 1, j + 1);
    };

    const g = createGraph();
    const n = g.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (g[i][j] === 0) {
                dfs(i, j);
                res++;
            }
        }
    }

    return res;
}
```

#### JavaScript

```js
function regionsBySlashes(grid) {
    const createGraph = () => {
        const n = grid.length;
        const g = Array.from({ length: n * 2 }, () => Array(n * 2).fill(0));

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                const [y, x] = [i * 2, j * 2];

                switch (grid[i][j]) {
                    case '/':
                        g[y][x] = g[y + 1][x + 1] = 0;
                        g[y][x + 1] = g[y + 1][x] = 1;
                        break;

                    case '\\':
                        g[y][x] = g[y + 1][x + 1] = 2;
                        g[y][x + 1] = g[y + 1][x] = 0;
                        break;

                    default:
                        g[y][x] = g[y][x + 1] = g[y + 1][x] = g[y + 1][x + 1] = 0;
                        break;
                }
            }
        }

        return g;
    };

    const isValid = x => 0 <= x && x < n;
    const dfs = (i, j) => {
        if (!isValid(i) || !isValid(j) || g[i][j]) return;

        g[i][j] = -1;
        const dirs = [-1, 0, 1, 0, -1];
        const neighbours = [];

        for (let d = 0; d < 4; d++) {
            const [y, x] = [i + dirs[d], j + dirs[d + 1]];

            if (isValid(y) && isValid(x)) {
                dfs(y, x);
                neighbours.push(g[y][x]);
            } else {
                neighbours.push(-1);
            }
        }

        const [top, right, bottom, left] = neighbours;
        if (top === 1 && right === 1) dfs(i - 1, j + 1);
        if (bottom === 1 && left === 1) dfs(i + 1, j - 1);
        if (top === 2 && left === 2) dfs(i - 1, j - 1);
        if (bottom === 2 && right === 2) dfs(i + 1, j + 1);
    };

    const g = createGraph();
    const n = g.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (g[i][j] === 0) {
                dfs(i, j);
                res++;
            }
        }
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
