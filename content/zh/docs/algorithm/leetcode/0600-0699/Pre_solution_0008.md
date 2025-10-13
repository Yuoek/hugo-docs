---
title: "0670_最大交换"
date: 2025-10-08T18:36:23+08:00
weight: 8
tags: [二叉树, 位运算, 动态规划, 哈希表, 回溯, 堆（优先队列）, 字典树, 字符串, 广度优先搜索, 数学, 数组, 栈, 树, 树状数组, 深度优先搜索, 矩阵, 线段树, 设计, 贪心]
---

{{< markmap >}}
### [0670_最大交换](#670)
#### [贪心](#670)
#### [数学](#670)
### [0671_二叉树中第二小的节点](#671)
#### [树](#671)
#### [深度优先搜索](#671)
#### [二叉树](#671)
### [0672_灯泡开关 Ⅱ](#672)
#### [位运算](#672)
#### [深度优先搜索](#672)
#### [广度优先搜索](#672)
#### [数学](#672)
### [0673_最长递增子序列的个数](#673)
#### [树状数组](#673)
#### [线段树](#673)
#### [数组](#673)
#### [动态规划](#673)
### [0674_最长连续递增序列](#674)
#### [数组](#674)
### [0675_为高尔夫比赛砍树](#675)
#### [广度优先搜索](#675)
#### [数组](#675)
#### [矩阵](#675)
#### [堆（优先队列）](#675)
### [0676_实现一个魔法字典](#676)
#### [深度优先搜索](#676)
#### [设计](#676)
#### [字典树](#676)
#### [哈希表](#676)
#### [字符串](#676)
### [0677_键值映射](#677)
#### [设计](#677)
#### [字典树](#677)
#### [哈希表](#677)
#### [字符串](#677)
### [0678_有效的括号字符串](#678)
#### [栈](#678)
#### [贪心](#678)
#### [字符串](#678)
#### [动态规划](#678)
### [0679_24 点游戏](#679)
#### [数组](#679)
#### [数学](#679)
#### [回溯](#679)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0670_最大交换
___
#### 贪心
___
#### 数学
---
### 0671_二叉树中第二小的节点
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0672_灯泡开关 Ⅱ
___
#### 位运算
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数学
---
### 0673_最长递增子序列的个数
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 动态规划
---
### 0674_最长连续递增序列
___
#### 数组
---
### 0675_为高尔夫比赛砍树
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 堆（优先队列）
---
### 0676_实现一个魔法字典
___
#### 深度优先搜索
___
#### 设计
___
#### 字典树
___
#### 哈希表
___
#### 字符串
---
### 0677_键值映射
___
#### 设计
___
#### 字典树
___
#### 哈希表
___
#### 字符串
---
### 0678_有效的括号字符串
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 动态规划
---
### 0679_24 点游戏
___
#### 数组
___
#### 数学
___
#### 回溯
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 动态规划 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字典树 | 字符串 | 广度优先搜索 |
| 数学 | 数组 | 栈 |
| 树 | 树状数组 | 深度优先搜索 |
| 矩阵 | 线段树 | 设计 |
| 贪心 |  |  |

# [670. 最大交换](https://leetcode.cn/problems/maximum-swap){#670}

{{< tabs "670" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        n = len(s)
        d = list(range(n))
        for i in range(n - 2, -1, -1):
            if s[i] <= s[d[i + 1]]:
                d[i] = d[i + 1]
        for i, j in enumerate(d):
            if s[i] < s[j]:
                s[i], s[j] = s[j], s[i]
                break
        return int(''.join(s))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumSwap(int num) {
        char[] s = String.valueOf(num).toCharArray();
        int n = s.length;
        int[] d = new int[n];
        for (int i = 0; i < n; ++i) {
            d[i] = i;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] <= s[d[i + 1]]) {
                d[i] = d[i + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = d[i];
            if (s[i] < s[j]) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
                break;
            }
        }
        return Integer.parseInt(String.valueOf(s));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> d(n);
        iota(d.begin(), d.end(), 0);
        for (int i = n - 2; ~i; --i) {
            if (s[i] <= s[d[i + 1]]) {
                d[i] = d[i + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = d[i];
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                break;
            }
        }
        return stoi(s);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSwap(num int) int {
	s := []byte(strconv.Itoa(num))
	n := len(s)
	d := make([]int, n)
	for i := range d {
		d[i] = i
	}
	for i := n - 2; i >= 0; i-- {
		if s[i] <= s[d[i+1]] {
			d[i] = d[i+1]
		}
	}
	for i, j := range d {
		if s[i] < s[j] {
			s[i], s[j] = s[j], s[i]
			break
		}
	}
	ans, _ := strconv.Atoi(string(s))
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSwap(num: number): number {
    const ans = [...String(num)];
    let [min, max, maybeMax, n] = [-1, -1, -1, ans.length];

    for (let i = n - 1; i >= 0; i--) {
        if (ans[i] > (ans[maybeMax] ?? -1)) maybeMax = i;
        if (i < maybeMax && ans[i] < ans[maybeMax]) {
            [min, max] = [i, maybeMax];
        }
    }

    if (~min && ~max && min < max) {
        [ans[min], ans[max]] = [ans[max], ans[min]];
    }

    return +ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_swap(mut num: i32) -> i32 {
        let mut list = {
            let mut res = Vec::new();
            while num != 0 {
                res.push(num % 10);
                num /= 10;
            }
            res
        };
        let n = list.len();
        let idx = {
            let mut i = 0;
            (0..n)
                .map(|j| {
                    if list[j] > list[i] {
                        i = j;
                    }
                    i
                })
                .collect::<Vec<usize>>()
        };
        for i in (0..n).rev() {
            if list[i] != list[idx[i]] {
                list.swap(i, idx[i]);
                break;
            }
        }
        let mut res = 0;
        for i in list.iter().rev() {
            res = res * 10 + i;
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function maximumSwap(num) {
    const ans = [...String(num)];
    let [min, max, maybeMax, n] = [-1, -1, -1, ans.length];

    for (let i = n - 1; i >= 0; i--) {
        if (ans[i] > (ans[maybeMax] ?? -1)) maybeMax = i;
        if (i < maybeMax && ans[i] < ans[maybeMax]) {
            [min, max] = [i, maybeMax];
        }
    }

    if (~min && ~max && min < max) {
        [ans[min], ans[max]] = [ans[max], ans[min]];
    }

    return +ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个非负整数，你<strong>至多</strong>可以交换一次数字中的任意两位。返回你能得到的最大值。</p>

<p><strong>示例 1 :</strong></p>

<pre>
<strong>输入:</strong> 2736
<strong>输出:</strong> 7236
<strong>解释:</strong> 交换数字2和数字7。
</pre>

<p><strong>示例 2 :</strong></p>

<pre>
<strong>输入:</strong> 9973
<strong>输出:</strong> 9973
<strong>解释:</strong> 不需要交换。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定数字的范围是&nbsp;[0, 10<sup>8</sup>]</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先将数字转为字符串 $s$，然后从右往左遍历字符串 $s$，用数组或哈希表 $d$ 记录每个数字右侧的最大数字的位置（可以是数字本身的位置）。

接着从左到右遍历 $d$，如果 $s[i] \lt s[d[i]]$，则进行交换，并退出遍历的过程。

最后将字符串 $s$ 转为数字，即为答案。

时间复杂度 $O(\log M)$，空间复杂度 $O(\log M)$。其中 $M$ 是数字 $num$ 的取值范围。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        n = len(s)
        d = list(range(n))
        for i in range(n - 2, -1, -1):
            if s[i] <= s[d[i + 1]]:
                d[i] = d[i + 1]
        for i, j in enumerate(d):
            if s[i] < s[j]:
                s[i], s[j] = s[j], s[i]
                break
        return int(''.join(s))
```

#### Java

```java
class Solution {
    public int maximumSwap(int num) {
        char[] s = String.valueOf(num).toCharArray();
        int n = s.length;
        int[] d = new int[n];
        for (int i = 0; i < n; ++i) {
            d[i] = i;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] <= s[d[i + 1]]) {
                d[i] = d[i + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = d[i];
            if (s[i] < s[j]) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
                break;
            }
        }
        return Integer.parseInt(String.valueOf(s));
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> d(n);
        iota(d.begin(), d.end(), 0);
        for (int i = n - 2; ~i; --i) {
            if (s[i] <= s[d[i + 1]]) {
                d[i] = d[i + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = d[i];
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                break;
            }
        }
        return stoi(s);
    }
};
```

#### Go

```go
func maximumSwap(num int) int {
	s := []byte(strconv.Itoa(num))
	n := len(s)
	d := make([]int, n)
	for i := range d {
		d[i] = i
	}
	for i := n - 2; i >= 0; i-- {
		if s[i] <= s[d[i+1]] {
			d[i] = d[i+1]
		}
	}
	for i, j := range d {
		if s[i] < s[j] {
			s[i], s[j] = s[j], s[i]
			break
		}
	}
	ans, _ := strconv.Atoi(string(s))
	return ans
}
```

#### TypeScript

```ts
function maximumSwap(num: number): number {
    const list = new Array();
    while (num !== 0) {
        list.push(num % 10);
        num = Math.floor(num / 10);
    }
    const n = list.length;
    const idx = new Array();
    for (let i = 0, j = 0; i < n; i++) {
        if (list[i] > list[j]) {
            j = i;
        }
        idx.push(j);
    }
    for (let i = n - 1; i >= 0; i--) {
        if (list[idx[i]] !== list[i]) {
            [list[idx[i]], list[i]] = [list[i], list[idx[i]]];
            break;
        }
    }
    let res = 0;
    for (let i = n - 1; i >= 0; i--) {
        res = res * 10 + list[i];
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_swap(mut num: i32) -> i32 {
        let mut list = {
            let mut res = Vec::new();
            while num != 0 {
                res.push(num % 10);
                num /= 10;
            }
            res
        };
        let n = list.len();
        let idx = {
            let mut i = 0;
            (0..n)
                .map(|j| {
                    if list[j] > list[i] {
                        i = j;
                    }
                    i
                })
                .collect::<Vec<usize>>()
        };
        for i in (0..n).rev() {
            if list[i] != list[idx[i]] {
                list.swap(i, idx[i]);
                break;
            }
        }
        let mut res = 0;
        for i in list.iter().rev() {
            res = res * 10 + i;
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 空间优化

<!-- tabs:start -->

#### TypeScript

```ts
function maximumSwap(num: number): number {
    const ans = [...String(num)];
    let [min, max, maybeMax, n] = [-1, -1, -1, ans.length];

    for (let i = n - 1; i >= 0; i--) {
        if (ans[i] > (ans[maybeMax] ?? -1)) maybeMax = i;
        if (i < maybeMax && ans[i] < ans[maybeMax]) {
            [min, max] = [i, maybeMax];
        }
    }

    if (~min && ~max && min < max) {
        [ans[min], ans[max]] = [ans[max], ans[min]];
    }

    return +ans.join('');
}
```

#### JavaScript

```js
function maximumSwap(num) {
    const ans = [...String(num)];
    let [min, max, maybeMax, n] = [-1, -1, -1, ans.length];

    for (let i = n - 1; i >= 0; i--) {
        if (ans[i] > (ans[maybeMax] ?? -1)) maybeMax = i;
        if (i < maybeMax && ans[i] < ans[maybeMax]) {
            [min, max] = [i, maybeMax];
        }
    }

    if (~min && ~max && min < max) {
        [ans[min], ans[max]] = [ans[max], ans[min]];
    }

    return +ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [671. 二叉树中第二小的节点](https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree){#671}

{{< tabs "671" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root:
                dfs(root.left)
                dfs(root.right)
                nonlocal ans, v
                if root.val > v:
                    ans = root.val if ans == -1 else min(ans, root.val)

        ans, v = -1, root.val
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
    private int ans = -1;

    public int findSecondMinimumValue(TreeNode root) {
        dfs(root, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int val) {
        if (root != null) {
            dfs(root.left, val);
            dfs(root.right, val);
            if (root.val > val) {
                ans = ans == -1 ? root.val : Math.min(ans, root.val);
            }
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
    int ans = -1;

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }

    void dfs(TreeNode* root, int val) {
        if (!root) return;
        dfs(root->left, val);
        dfs(root->right, val);
        if (root->val > val) ans = ans == -1 ? root->val : min(ans, root->val);
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
func findSecondMinimumValue(root *TreeNode) int {
	ans, v := -1, root.Val
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		dfs(root.Right)
		if root.Val > v {
			if ans == -1 || ans > root.Val {
				ans = root.Val
			}
		}
	}
	dfs(root)
	return ans
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
var findSecondMinimumValue = function (root) {
    let ans = -1;
    const v = root.val;
    function dfs(root) {
        if (!root) {
            return;
        }
        dfs(root.left);
        dfs(root.right);
        if (root.val > v) {
            if (ans == -1 || ans > root.val) {
                ans = root.val;
            }
        }
    }
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

<p>给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为&nbsp;<code>2</code>&nbsp;或&nbsp;<code>0</code>。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。</p>

<p>更正式地说，即&nbsp;<code>root.val = min(root.left.val, root.right.val)</code> 总成立。</p>

<p>给出这样的一个二叉树，你需要输出所有节点中的&nbsp;<strong>第二小的值 </strong>。</p>

<p>如果第二小的值不存在的话，输出 -1 <strong>。</strong></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0671.Second%20Minimum%20Node%20In%20a%20Binary%20Tree/images/smbt1.jpg" style="height: 210px; width: 300px;" />
<pre>
<strong>输入：</strong>root = [2,2,5,null,null,5,7]
<strong>输出：</strong>5
<strong>解释：</strong>最小的值是 2 ，第二小的值是 5 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0671.Second%20Minimum%20Node%20In%20a%20Binary%20Tree/images/smbt2.jpg" style="height: 113px; width: 200px;" />
<pre>
<strong>输入：</strong>root = [2,2,2]
<strong>输出：</strong>-1
<strong>解释：</strong>最小的值是 2, 但是不存在第二小的值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 25]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>对于树中每个节点 <code>root.val == min(root.left.val, root.right.val)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

直接 DFS 遍历二叉树，找到大于 `root.val` 的最小值。若不存在，则返回 -1。

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
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root:
                dfs(root.left)
                dfs(root.right)
                nonlocal ans, v
                if root.val > v:
                    ans = root.val if ans == -1 else min(ans, root.val)

        ans, v = -1, root.val
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
    private int ans = -1;

    public int findSecondMinimumValue(TreeNode root) {
        dfs(root, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int val) {
        if (root != null) {
            dfs(root.left, val);
            dfs(root.right, val);
            if (root.val > val) {
                ans = ans == -1 ? root.val : Math.min(ans, root.val);
            }
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
    int ans = -1;

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }

    void dfs(TreeNode* root, int val) {
        if (!root) return;
        dfs(root->left, val);
        dfs(root->right, val);
        if (root->val > val) ans = ans == -1 ? root->val : min(ans, root->val);
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
func findSecondMinimumValue(root *TreeNode) int {
	ans, v := -1, root.Val
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		dfs(root.Right)
		if root.Val > v {
			if ans == -1 || ans > root.Val {
				ans = root.Val
			}
		}
	}
	dfs(root)
	return ans
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
var findSecondMinimumValue = function (root) {
    let ans = -1;
    const v = root.val;
    function dfs(root) {
        if (!root) {
            return;
        }
        dfs(root.left);
        dfs(root.right);
        if (root.val > v) {
            if (ans == -1 || ans > root.val) {
                ans = root.val;
            }
        }
    }
    dfs(root);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [672. 灯泡开关 Ⅱ](https://leetcode.cn/problems/bulb-switcher-ii){#672}

{{< tabs "672" >}}

{{% tab "python" %}}
```python
class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        ops = (0b111111, 0b010101, 0b101010, 0b100100)
        n = min(n, 6)
        vis = set()
        for mask in range(1 << 4):
            cnt = mask.bit_count()
            if cnt <= presses and cnt % 2 == presses % 2:
                t = 0
                for i, op in enumerate(ops):
                    if (mask >> i) & 1:
                        t ^= op
                t &= (1 << 6) - 1
                t >>= 6 - n
                vis.add(t)
        return len(vis)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int flipLights(int n, int presses) {
        int[] ops = new int[] {0b111111, 0b010101, 0b101010, 0b100100};
        Set<Integer> vis = new HashSet<>();
        n = Math.min(n, 6);
        for (int mask = 0; mask < 1 << 4; ++mask) {
            int cnt = Integer.bitCount(mask);
            if (cnt <= presses && cnt % 2 == presses % 2) {
                int t = 0;
                for (int i = 0; i < 4; ++i) {
                    if (((mask >> i) & 1) == 1) {
                        t ^= ops[i];
                    }
                }
                t &= ((1 << 6) - 1);
                t >>= (6 - n);
                vis.add(t);
            }
        }
        return vis.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int flipLights(int n, int presses) {
        n = min(n, 6);
        vector<int> ops = {0b111111, 0b010101, 0b101010, 0b100100};
        unordered_set<int> vis;
        for (int mask = 0; mask < 1 << 4; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt > presses || cnt % 2 != presses % 2) continue;
            int t = 0;
            for (int i = 0; i < 4; ++i) {
                if (mask >> i & 1) {
                    t ^= ops[i];
                }
            }
            t &= (1 << 6) - 1;
            t >>= (6 - n);
            vis.insert(t);
        }
        return vis.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func flipLights(n int, presses int) int {
	if n > 6 {
		n = 6
	}
	ops := []int{0b111111, 0b010101, 0b101010, 0b100100}
	vis := map[int]bool{}
	for mask := 0; mask < 1<<4; mask++ {
		cnt := bits.OnesCount(uint(mask))
		if cnt <= presses && cnt%2 == presses%2 {
			t := 0
			for i, op := range ops {
				if mask>>i&1 == 1 {
					t ^= op
				}
			}
			t &= 1<<6 - 1
			t >>= (6 - n)
			vis[t] = true
		}
	}
	return len(vis)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>房间中有 <code>n</code>&nbsp;只已经打开的灯泡，编号从 <code>1</code> 到 <code>n</code> 。墙上挂着 <strong>4 个开关</strong> 。</p>

<p>这 4 个开关各自都具有不同的功能，其中：</p>

<ul>
	<li><strong>开关 1 ：</strong>反转当前所有灯的状态（即开变为关，关变为开）</li>
	<li><strong>开关 2 ：</strong>反转编号为偶数的灯的状态（即 <code>0, 2, 4, ...</code>）</li>
	<li><strong>开关 3 ：</strong>反转编号为奇数的灯的状态（即 <code>1, 3, ...</code>）</li>
	<li><strong>开关 4 ：</strong>反转编号为 <code>j = 3k + 1</code> 的灯的状态，其中 <code>k = 0, 1, 2, ...</code>（即 <code>1, 4, 7, 10, ...</code>）</li>
</ul>

<p>你必须 <strong>恰好</strong> 按压开关 <code>presses</code> 次。每次按压，你都需要从 4 个开关中选出一个来执行按压操作。</p>

<p>给你两个整数 <code>n</code> 和 <code>presses</code> ，执行完所有按压之后，返回 <strong>不同可能状态</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, presses = 1
<strong>输出：</strong>2
<strong>解释：</strong>状态可以是：
- 按压开关 1 ，[关]
- 按压开关 2 ，[开]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, presses = 1
<strong>输出：</strong>3
<strong>解释：</strong>状态可以是：
- 按压开关 1 ，[关, 关]
- 按压开关 2 ，[开, 关]
- 按压开关 3 ，[关, 开]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3, presses = 1
<strong>输出：</strong>4
<strong>解释：</strong>状态可以是：
- 按压开关 1 ，[关, 关, 关]
- 按压开关 2 ，[关, 开, 关]
- 按压开关 3 ，[开, 关, 开]
- 按压开关 4 ，[关, 开, 开]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= presses &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

观察灯泡开关随按钮操作的变化规律，我们可以发现，位置 $i$ 与 $i+6$ 的灯泡，开关状态始终保持一致，因此，我们只需要考虑最多前 $n=6$ 个灯泡的开关状态。

另外，对于每个按钮，若操作偶数次，相当于没执行操作；若操作奇数次，相当于操作了 $1$ 次。同时，不同按钮操作的先后顺序，也不影响结果。

题目有 $4$ 个按钮，每个按钮有“操作偶数次”和“操作奇数次”两种状态，因此总共有 $2^4$ 种按钮状态。

二进制枚举按钮的状态 `mask`，若当前状态满足题目 `presses` 的限制，我们可以通过位运算，模拟操作对应按钮，最终得到灯泡的状态 $t$，去重后的 $t$ 的数量就是答案。

时空复杂度均为常数级别。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        ops = (0b111111, 0b010101, 0b101010, 0b100100)
        n = min(n, 6)
        vis = set()
        for mask in range(1 << 4):
            cnt = mask.bit_count()
            if cnt <= presses and cnt % 2 == presses % 2:
                t = 0
                for i, op in enumerate(ops):
                    if (mask >> i) & 1:
                        t ^= op
                t &= (1 << 6) - 1
                t >>= 6 - n
                vis.add(t)
        return len(vis)
```

#### Java

```java
class Solution {
    public int flipLights(int n, int presses) {
        int[] ops = new int[] {0b111111, 0b010101, 0b101010, 0b100100};
        Set<Integer> vis = new HashSet<>();
        n = Math.min(n, 6);
        for (int mask = 0; mask < 1 << 4; ++mask) {
            int cnt = Integer.bitCount(mask);
            if (cnt <= presses && cnt % 2 == presses % 2) {
                int t = 0;
                for (int i = 0; i < 4; ++i) {
                    if (((mask >> i) & 1) == 1) {
                        t ^= ops[i];
                    }
                }
                t &= ((1 << 6) - 1);
                t >>= (6 - n);
                vis.add(t);
            }
        }
        return vis.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int flipLights(int n, int presses) {
        n = min(n, 6);
        vector<int> ops = {0b111111, 0b010101, 0b101010, 0b100100};
        unordered_set<int> vis;
        for (int mask = 0; mask < 1 << 4; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt > presses || cnt % 2 != presses % 2) continue;
            int t = 0;
            for (int i = 0; i < 4; ++i) {
                if (mask >> i & 1) {
                    t ^= ops[i];
                }
            }
            t &= (1 << 6) - 1;
            t >>= (6 - n);
            vis.insert(t);
        }
        return vis.size();
    }
};
```

#### Go

```go
func flipLights(n int, presses int) int {
	if n > 6 {
		n = 6
	}
	ops := []int{0b111111, 0b010101, 0b101010, 0b100100}
	vis := map[int]bool{}
	for mask := 0; mask < 1<<4; mask++ {
		cnt := bits.OnesCount(uint(mask))
		if cnt <= presses && cnt%2 == presses%2 {
			t := 0
			for i, op := range ops {
				if mask>>i&1 == 1 {
					t ^= op
				}
			}
			t &= 1<<6 - 1
			t >>= (6 - n)
			vis[t] = true
		}
	}
	return len(vis)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [673. 最长递增子序列的个数](https://leetcode.cn/problems/number-of-longest-increasing-subsequence){#673}

{{< tabs "673" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = ["n", "c", "d"]

    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)
        self.d = [0] * (n + 1)

    def update(self, x, v, cnt):
        while x <= self.n:
            if self.c[x] < v:
                self.c[x] = v
                self.d[x] = cnt
            elif self.c[x] == v:
                self.d[x] += cnt
            x += x & -x

    def query(self, x):
        v = cnt = 0
        while x:
            if self.c[x] > v:
                v = self.c[x]
                cnt = self.d[x]
            elif self.c[x] == v:
                cnt += self.d[x]
            x -= x & -x
        return v, cnt


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        arr = sorted(set(nums))
        m = len(arr)
        tree = BinaryIndexedTree(m)
        for x in nums:
            i = bisect_left(arr, x) + 1
            v, cnt = tree.query(i - 1)
            tree.update(i, v + 1, max(cnt, 1))
        return tree.query(m)[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;
    private int[] d;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
        d = new int[n + 1];
    }

    public void update(int x, int v, int cnt) {
        while (x <= n) {
            if (c[x] < v) {
                c[x] = v;
                d[x] = cnt;
            } else if (c[x] == v) {
                d[x] += cnt;
            }
            x += x & -x;
        }
    }

    public int[] query(int x) {
        int v = 0, cnt = 0;
        while (x > 0) {
            if (c[x] > v) {
                v = c[x];
                cnt = d[x];
            } else if (c[x] == v) {
                cnt += d[x];
            }
            x -= x & -x;
        }
        return new int[] {v, cnt};
    }
}

public class Solution {
    public int findNumberOfLIS(int[] nums) {
        // int[] arr = Arrays.stream(nums).distinct().sorted().toArray();
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int m = arr.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int x : nums) {
            int i = Arrays.binarySearch(arr, x) + 1;
            int[] t = tree.query(i - 1);
            int v = t[0];
            int cnt = t[1];
            tree.update(i, v + 1, Math.max(cnt, 1));
        }
        return tree.query(m)[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;
    vector<int> d;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1, 0)
        , d(n + 1, 0) {}

    void update(int x, int v, int cnt) {
        while (x <= n) {
            if (c[x] < v) {
                c[x] = v;
                d[x] = cnt;
            } else if (c[x] == v) {
                d[x] += cnt;
            }
            x += x & -x;
        }
    }

    pair<int, int> query(int x) {
        int v = 0, cnt = 0;
        while (x > 0) {
            if (c[x] > v) {
                v = c[x];
                cnt = d[x];
            } else if (c[x] == v) {
                cnt += d[x];
            }
            x -= x & -x;
        }
        return {v, cnt};
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        BinaryIndexedTree tree(m);
        for (int x : nums) {
            auto it = lower_bound(arr.begin(), arr.end(), x);
            int i = distance(arr.begin(), it) + 1;
            auto [v, cnt] = tree.query(i - 1);
            tree.update(i, v + 1, max(cnt, 1));
        }
        return tree.query(m).second;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
	d []int
}

func newBinaryIndexedTree(n int) BinaryIndexedTree {
	return BinaryIndexedTree{
		n: n,
		c: make([]int, n+1),
		d: make([]int, n+1),
	}
}

func (bit *BinaryIndexedTree) update(x, v, cnt int) {
	for x <= bit.n {
		if bit.c[x] < v {
			bit.c[x] = v
			bit.d[x] = cnt
		} else if bit.c[x] == v {
			bit.d[x] += cnt
		}
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) (int, int) {
	v, cnt := 0, 0
	for x > 0 {
		if bit.c[x] > v {
			v = bit.c[x]
			cnt = bit.d[x]
		} else if bit.c[x] == v {
			cnt += bit.d[x]
		}
		x -= x & -x
	}
	return v, cnt
}

func findNumberOfLIS(nums []int) int {
	arr := make([]int, len(nums))
	copy(arr, nums)
	sort.Ints(arr)
	m := len(arr)
	tree := newBinaryIndexedTree(m)
	for _, x := range nums {
		i := sort.SearchInts(arr, x) + 1
		v, cnt := tree.query(i - 1)
		tree.update(i, v+1, max(cnt, 1))
	}
	_, ans := tree.query(m)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];
    private d: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
        this.d = Array(n + 1).fill(0);
    }

    update(x: number, v: number, cnt: number): void {
        while (x <= this.n) {
            if (this.c[x] < v) {
                this.c[x] = v;
                this.d[x] = cnt;
            } else if (this.c[x] === v) {
                this.d[x] += cnt;
            }
            x += x & -x;
        }
    }

    query(x: number): [number, number] {
        let v = 0;
        let cnt = 0;
        while (x > 0) {
            if (this.c[x] > v) {
                v = this.c[x];
                cnt = this.d[x];
            } else if (this.c[x] === v) {
                cnt += this.d[x];
            }
            x -= x & -x;
        }
        return [v, cnt];
    }
}

function findNumberOfLIS(nums: number[]): number {
    const arr: number[] = [...new Set(nums)].sort((a, b) => a - b);
    const m: number = arr.length;
    const tree: BinaryIndexedTree = new BinaryIndexedTree(m);
    const search = (x: number): number => {
        let l = 0,
            r = arr.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    };
    for (const x of nums) {
        const i: number = search(x);
        const [v, cnt]: [number, number] = tree.query(i - 1);
        tree.update(i, v + 1, Math.max(cnt, 1));
    }
    return tree.query(m)[1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct BinaryIndexedTree {
    n: usize,
    c: Vec<i32>,
    d: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> BinaryIndexedTree {
        BinaryIndexedTree {
            n,
            c: vec![0; n + 1],
            d: vec![0; n + 1],
        }
    }

    fn update(&mut self, x: usize, v: i32, cnt: i32) {
        let mut x = x as usize;
        while x <= self.n {
            if self.c[x] < v {
                self.c[x] = v;
                self.d[x] = cnt;
            } else if self.c[x] == v {
                self.d[x] += cnt;
            }
            x += x & x.wrapping_neg();
        }
    }

    fn query(&self, mut x: usize) -> (i32, i32) {
        let (mut v, mut cnt) = (0, 0);
        while x > 0 {
            if self.c[x] > v {
                v = self.c[x];
                cnt = self.d[x];
            } else if self.c[x] == v {
                cnt += self.d[x];
            }
            x -= x & x.wrapping_neg();
        }
        (v, cnt)
    }
}

impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let mut arr: Vec<i32> = nums.iter().cloned().collect();
        arr.sort();
        let m = arr.len();
        let mut tree = BinaryIndexedTree::new(m);
        for x in nums.iter() {
            if let Ok(i) = arr.binary_search(x) {
                let (v, cnt) = tree.query(i);
                tree.update(i + 1, v + 1, cnt.max(1));
            }
        }
        let (_, ans) = tree.query(m);
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

<p>给定一个未排序的整数数组<meta charset="UTF-8" />&nbsp;<code>nums</code>&nbsp;，&nbsp;<em>返回最长递增子序列的个数</em>&nbsp;。</p>

<p><strong>注意</strong>&nbsp;这个数列必须是 <strong>严格</strong> 递增的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> [1,3,5,4,7]
<strong>输出:</strong> 2
<strong>解释:</strong> 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> [2,2,2,2,2]
<strong>输出:</strong> 5
<strong>解释:</strong> 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以 $nums[i]$ 结尾的最长递增子序列的长度，定义 $cnt[i]$ 表示以 $nums[i]$ 结尾的最长递增子序列的个数。初始时 $f[i]=1$, $cnt[i]=1$。另外，定义 $mx$ 表示最长递增子序列的长度，定义 $ans$ 表示最长递增子序列的个数。

对于每一个 $nums[i]$，我们枚举 $nums[0:i-1]$ 中的所有元素 $nums[j]$，如果 $nums[j] \lt nums[i]$，则 $nums[i]$ 可以接在 $nums[j]$ 后面，形成一个更长的递增子序列。如果 $f[i] \lt f[j] + 1$，说明以 $nums[i]$ 结尾的最长递增子序列的长度增加了，那么我们需要更新 $f[i]=f[j]+1$，并且 $cnt[i]=cnt[j]$。如果 $f[i]=f[j]+1$，说明我们找到了一条长度与之前相同的最长递增子序列，那么我们需要将 $cnt[i]$ 增加 $cnt[j]$。然后，如果 $mx \lt f[i]$，说明最长递增子序列的长度增加了，那么我们需要更新 $mx=f[i]$，并且 $ans=cnt[i]$。如果 $mx=f[i]$，说明我们找到了一条长度与之前相同的最长递增子序列，那么我们需要将 $ans$ 增加 $cnt[i]$。

最后，我们返回 $ans$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        f = [1] * n
        cnt = [1] * n
        mx = 0
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if f[i] < f[j] + 1:
                        f[i] = f[j] + 1
                        cnt[i] = cnt[j]
                    elif f[i] == f[j] + 1:
                        cnt[i] += cnt[j]
            if mx < f[i]:
                mx = f[i]
                ans = cnt[i]
            elif mx == f[i]:
                ans += cnt[i]
        return ans
```

#### Java

```java
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        int[] cnt = new int[n];
        int mx = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (f[i] == f[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (mx < f[i]) {
                mx = f[i];
                ans = cnt[i];
            } else if (mx == f[i]) {
                ans += cnt[i];
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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, ans = 0;
        vector<int> f(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (f[i] == f[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (mx < f[i]) {
                mx = f[i];
                ans = cnt[i];
            } else if (mx == f[i]) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findNumberOfLIS(nums []int) (ans int) {
	n, mx := len(nums), 0
	f := make([]int, n)
	cnt := make([]int, n)
	for i, x := range nums {
		for j, y := range nums[:i] {
			if y < x {
				if f[i] < f[j]+1 {
					f[i] = f[j] + 1
					cnt[i] = cnt[j]
				} else if f[i] == f[j]+1 {
					cnt[i] += cnt[j]
				}
			}
		}
		if mx < f[i] {
			mx = f[i]
			ans = cnt[i]
		} else if mx == f[i] {
			ans += cnt[i]
		}
	}
	return
}
```

#### TypeScript

```ts
function findNumberOfLIS(nums: number[]): number {
    const n = nums.length;
    let [ans, mx] = [0, 0];
    const f: number[] = Array(n).fill(1);
    const cnt: number[] = Array(n).fill(1);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    cnt[i] = cnt[j];
                } else if (f[i] === f[j] + 1) {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (mx < f[i]) {
            mx = f[i];
            ans = cnt[i];
        } else if (mx === f[i]) {
            ans += cnt[i];
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut mx = 0;
        let mut f = vec![1; n];
        let mut cnt = vec![1; n];
        for i in 0..n {
            for j in 0..i {
                if nums[j] < nums[i] {
                    if f[i] < f[j] + 1 {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j];
                    } else if f[i] == f[j] + 1 {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if mx < f[i] {
                mx = f[i];
                ans = cnt[i];
            } else if mx == f[i] {
                ans += cnt[i];
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组

我们可以用树状数组维护前缀区间的最长递增子序列的长度和个数。我们将数组 $nums$ 中的元素去重并排序，得到数组 $arr$，然后我们枚举 $nums$ 中的每一个元素 $x$，在数组 $arr$ 中二分查找 $x$ 的位置 $i$，然后查询 $[1,i-1]$ 的最长递增子序列的长度和个数，记为 $v$ 和 $cnt$，然后更新 $[i]$ 的最长递增子序列的长度和个数为 $v+1$ 和 $\max(cnt,1)$。最后，我们查询 $[1,m]$ 的最长递增子序列的长度和个数，其中 $m$ 是数组 $arr$ 的长度，即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = ["n", "c", "d"]

    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)
        self.d = [0] * (n + 1)

    def update(self, x, v, cnt):
        while x <= self.n:
            if self.c[x] < v:
                self.c[x] = v
                self.d[x] = cnt
            elif self.c[x] == v:
                self.d[x] += cnt
            x += x & -x

    def query(self, x):
        v = cnt = 0
        while x:
            if self.c[x] > v:
                v = self.c[x]
                cnt = self.d[x]
            elif self.c[x] == v:
                cnt += self.d[x]
            x -= x & -x
        return v, cnt


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        arr = sorted(set(nums))
        m = len(arr)
        tree = BinaryIndexedTree(m)
        for x in nums:
            i = bisect_left(arr, x) + 1
            v, cnt = tree.query(i - 1)
            tree.update(i, v + 1, max(cnt, 1))
        return tree.query(m)[1]
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;
    private int[] d;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
        d = new int[n + 1];
    }

    public void update(int x, int v, int cnt) {
        while (x <= n) {
            if (c[x] < v) {
                c[x] = v;
                d[x] = cnt;
            } else if (c[x] == v) {
                d[x] += cnt;
            }
            x += x & -x;
        }
    }

    public int[] query(int x) {
        int v = 0, cnt = 0;
        while (x > 0) {
            if (c[x] > v) {
                v = c[x];
                cnt = d[x];
            } else if (c[x] == v) {
                cnt += d[x];
            }
            x -= x & -x;
        }
        return new int[] {v, cnt};
    }
}

public class Solution {
    public int findNumberOfLIS(int[] nums) {
        // int[] arr = Arrays.stream(nums).distinct().sorted().toArray();
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int m = arr.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int x : nums) {
            int i = Arrays.binarySearch(arr, x) + 1;
            int[] t = tree.query(i - 1);
            int v = t[0];
            int cnt = t[1];
            tree.update(i, v + 1, Math.max(cnt, 1));
        }
        return tree.query(m)[1];
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;
    vector<int> d;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1, 0)
        , d(n + 1, 0) {}

    void update(int x, int v, int cnt) {
        while (x <= n) {
            if (c[x] < v) {
                c[x] = v;
                d[x] = cnt;
            } else if (c[x] == v) {
                d[x] += cnt;
            }
            x += x & -x;
        }
    }

    pair<int, int> query(int x) {
        int v = 0, cnt = 0;
        while (x > 0) {
            if (c[x] > v) {
                v = c[x];
                cnt = d[x];
            } else if (c[x] == v) {
                cnt += d[x];
            }
            x -= x & -x;
        }
        return {v, cnt};
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        BinaryIndexedTree tree(m);
        for (int x : nums) {
            auto it = lower_bound(arr.begin(), arr.end(), x);
            int i = distance(arr.begin(), it) + 1;
            auto [v, cnt] = tree.query(i - 1);
            tree.update(i, v + 1, max(cnt, 1));
        }
        return tree.query(m).second;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
	d []int
}

func newBinaryIndexedTree(n int) BinaryIndexedTree {
	return BinaryIndexedTree{
		n: n,
		c: make([]int, n+1),
		d: make([]int, n+1),
	}
}

func (bit *BinaryIndexedTree) update(x, v, cnt int) {
	for x <= bit.n {
		if bit.c[x] < v {
			bit.c[x] = v
			bit.d[x] = cnt
		} else if bit.c[x] == v {
			bit.d[x] += cnt
		}
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) (int, int) {
	v, cnt := 0, 0
	for x > 0 {
		if bit.c[x] > v {
			v = bit.c[x]
			cnt = bit.d[x]
		} else if bit.c[x] == v {
			cnt += bit.d[x]
		}
		x -= x & -x
	}
	return v, cnt
}

func findNumberOfLIS(nums []int) int {
	arr := make([]int, len(nums))
	copy(arr, nums)
	sort.Ints(arr)
	m := len(arr)
	tree := newBinaryIndexedTree(m)
	for _, x := range nums {
		i := sort.SearchInts(arr, x) + 1
		v, cnt := tree.query(i - 1)
		tree.update(i, v+1, max(cnt, 1))
	}
	_, ans := tree.query(m)
	return ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];
    private d: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
        this.d = Array(n + 1).fill(0);
    }

    update(x: number, v: number, cnt: number): void {
        while (x <= this.n) {
            if (this.c[x] < v) {
                this.c[x] = v;
                this.d[x] = cnt;
            } else if (this.c[x] === v) {
                this.d[x] += cnt;
            }
            x += x & -x;
        }
    }

    query(x: number): [number, number] {
        let v = 0;
        let cnt = 0;
        while (x > 0) {
            if (this.c[x] > v) {
                v = this.c[x];
                cnt = this.d[x];
            } else if (this.c[x] === v) {
                cnt += this.d[x];
            }
            x -= x & -x;
        }
        return [v, cnt];
    }
}

function findNumberOfLIS(nums: number[]): number {
    const arr: number[] = [...new Set(nums)].sort((a, b) => a - b);
    const m: number = arr.length;
    const tree: BinaryIndexedTree = new BinaryIndexedTree(m);
    const search = (x: number): number => {
        let l = 0,
            r = arr.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    };
    for (const x of nums) {
        const i: number = search(x);
        const [v, cnt]: [number, number] = tree.query(i - 1);
        tree.update(i, v + 1, Math.max(cnt, 1));
    }
    return tree.query(m)[1];
}
```

#### Rust

```rust
struct BinaryIndexedTree {
    n: usize,
    c: Vec<i32>,
    d: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> BinaryIndexedTree {
        BinaryIndexedTree {
            n,
            c: vec![0; n + 1],
            d: vec![0; n + 1],
        }
    }

    fn update(&mut self, x: usize, v: i32, cnt: i32) {
        let mut x = x as usize;
        while x <= self.n {
            if self.c[x] < v {
                self.c[x] = v;
                self.d[x] = cnt;
            } else if self.c[x] == v {
                self.d[x] += cnt;
            }
            x += x & x.wrapping_neg();
        }
    }

    fn query(&self, mut x: usize) -> (i32, i32) {
        let (mut v, mut cnt) = (0, 0);
        while x > 0 {
            if self.c[x] > v {
                v = self.c[x];
                cnt = self.d[x];
            } else if self.c[x] == v {
                cnt += self.d[x];
            }
            x -= x & x.wrapping_neg();
        }
        (v, cnt)
    }
}

impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let mut arr: Vec<i32> = nums.iter().cloned().collect();
        arr.sort();
        let m = arr.len();
        let mut tree = BinaryIndexedTree::new(m);
        for x in nums.iter() {
            if let Ok(i) = arr.binary_search(x) {
                let (v, cnt) = tree.query(i);
                tree.update(i + 1, v + 1, cnt.max(1));
            }
        }
        let (_, ans) = tree.query(m);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [674. 最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence){#674}

{{< tabs "674" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ans, n = 1, len(nums)
        i = 0
        while i < n:
            j = i + 1
            while j < n and nums[j - 1] < nums[j]:
                j += 1
            ans = max(ans, j - i)
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int ans = 1;
        int n = nums.length;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            ans = Math.max(ans, j - i);
            i = j;
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
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLengthOfLCIS(nums []int) int {
	ans := 1
	n := len(nums)
	for i := 0; i < n; {
		j := i + 1
		for j < n && nums[j-1] < nums[j] {
			j++
		}
		ans = max(ans, j-i)
		i = j
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLengthOfLCIS(nums: number[]): number {
    let ans = 1;
    const n = nums.length;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && nums[j - 1] < nums[j]) {
            ++j;
        }
        ans = Math.max(ans, j - i);
        i = j;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let mut ans = 1;
        let n = nums.len();
        let mut i = 0;
        while i < n {
            let mut j = i + 1;
            while j < n && nums[j - 1] < nums[j] {
                j += 1;
            }
            ans = ans.max(j - i);
            i = j;
        }
        ans as i32
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
    function findLengthOfLCIS($nums) {
        $ans = 1;
        $n = count($nums);
        $i = 0;
        while ($i < $n) {
            $j = $i + 1;
            while ($j < $n && $nums[$j - 1] < $nums[$j]) {
                $j++;
            }
            $ans = max($ans, $j - $i);
            $i = $j;
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

<p>给定一个未经排序的整数数组，找到最长且<strong> 连续递增的子序列</strong>，并返回该序列的长度。</p>

<p><strong>连续递增的子序列</strong> 可以由两个下标 <code>l</code> 和 <code>r</code>（<code>l < r</code>）确定，如果对于每个 <code>l <= i < r</code>，都有 <code>nums[i] < nums[i + 1]</code> ，那么子序列 <code>[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]]</code> 就是连续递增子序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,5,4,7]
<strong>输出：</strong>3
<strong>解释：</strong>最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>最长连续递增序列是 [2], 长度为1。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以遍历数组 $nums$，用变量 $cnt$ 记录当前连续递增序列的长度。初始时 $cnt = 1$。

然后，我们从下标 $i = 1$ 开始，向右遍历数组 $nums$。每次遍历时，如果 $nums[i - 1] < nums[i]$，则说明当前元素可以加入到连续递增序列中，因此令 $cnt = cnt + 1$，然后更新答案为 $ans = \max(ans, cnt)$。否则，说明当前元素无法加入到连续递增序列中，因此令 $cnt = 1$。

遍历结束后，返回答案 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ans = cnt = 1
        for i, x in enumerate(nums[1:]):
            if nums[i] < x:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 1
        return ans
```

#### Java

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int ans = 1;
        for (int i = 1, cnt = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
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
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        for (int i = 1, cnt = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLengthOfLCIS(nums []int) int {
	ans, cnt := 1, 1
	for i, x := range nums[1:] {
		if nums[i] < x {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findLengthOfLCIS(nums: number[]): number {
    let [ans, cnt] = [1, 1];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let mut ans = 1;
        let mut cnt = 1;
        for i in 1..nums.len() {
            if nums[i - 1] < nums[i] {
                ans = ans.max(cnt + 1);
                cnt += 1;
            } else {
                cnt = 1;
            }
        }
        ans
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
    function findLengthOfLCIS($nums) {
        $ans = 1;
        $cnt = 1;
        for ($i = 1; $i < count($nums); ++$i) {
            if ($nums[$i - 1] < $nums[$i]) {
                $ans = max($ans, ++$cnt);
            } else {
                $cnt = 1;
            }
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

我们也可以用双指针 $i$ 和 $j$ 找到每一段连续递增序列，找出最长的连续递增序列的长度作为答案。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ans, n = 1, len(nums)
        i = 0
        while i < n:
            j = i + 1
            while j < n and nums[j - 1] < nums[j]:
                j += 1
            ans = max(ans, j - i)
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int ans = 1;
        int n = nums.length;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            ans = Math.max(ans, j - i);
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func findLengthOfLCIS(nums []int) int {
	ans := 1
	n := len(nums)
	for i := 0; i < n; {
		j := i + 1
		for j < n && nums[j-1] < nums[j] {
			j++
		}
		ans = max(ans, j-i)
		i = j
	}
	return ans
}
```

#### TypeScript

```ts
function findLengthOfLCIS(nums: number[]): number {
    let ans = 1;
    const n = nums.length;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && nums[j - 1] < nums[j]) {
            ++j;
        }
        ans = Math.max(ans, j - i);
        i = j;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let mut ans = 1;
        let n = nums.len();
        let mut i = 0;
        while i < n {
            let mut j = i + 1;
            while j < n && nums[j - 1] < nums[j] {
                j += 1;
            }
            ans = ans.max(j - i);
            i = j;
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
    function findLengthOfLCIS($nums) {
        $ans = 1;
        $n = count($nums);
        $i = 0;
        while ($i < $n) {
            $j = $i + 1;
            while ($j < $n && $nums[$j - 1] < $nums[$j]) {
                $j++;
            }
            $ans = max($ans, $j - $i);
            $i = $j;
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

# [675. 为高尔夫比赛砍树](https://leetcode.cn/problems/cut-off-trees-for-golf-event){#675}

{{< tabs "675" >}}

{{% tab "python" %}}
```python
class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        def f(i, j, x, y):
            return abs(i - x) + abs(j - y)

        def bfs(i, j, x, y):
            q = [(f(i, j, x, y), i, j)]
            dist = {i * n + j: 0}
            while q:
                _, i, j = heappop(q)
                step = dist[i * n + j]
                if (i, j) == (x, y):
                    return step
                for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                    c, d = i + a, j + b
                    if 0 <= c < m and 0 <= d < n and forest[c][d] > 0:
                        if c * n + d not in dist or dist[c * n + d] > step + 1:
                            dist[c * n + d] = step + 1
                            heappush(q, (dist[c * n + d] + f(c, d, x, y), c, d))
            return -1

        m, n = len(forest), len(forest[0])
        trees = [
            (forest[i][j], i, j) for i in range(m) for j in range(n) if forest[i][j] > 1
        ]
        trees.sort()
        i = j = 0
        ans = 0
        for _, x, y in trees:
            t = bfs(i, j, x, y)
            if t == -1:
                return -1
            ans += t
            i, j = x, y
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] dist = new int[3600];
    private List<List<Integer>> forest;
    private int m;
    private int n;

    public int cutOffTree(List<List<Integer>> forest) {
        this.forest = forest;
        m = forest.size();
        n = forest.get(0).size();
        List<int[]> trees = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest.get(i).get(j) > 1) {
                    trees.add(new int[] {forest.get(i).get(j), i * n + j});
                }
            }
        }
        trees.sort(Comparator.comparingInt(a -> a[0]));
        int ans = 0;
        int start = 0;
        for (int[] tree : trees) {
            int end = tree[1];
            int t = bfs(start, end);
            if (t == -1) {
                return -1;
            }
            ans += t;
            start = end;
        }
        return ans;
    }

    private int bfs(int start, int end) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.offer(new int[] {f(start, end), start});
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int state = q.poll()[1];
            if (state == end) {
                return dist[state];
            }
            for (int k = 0; k < 4; ++k) {
                int x = state / n + dirs[k];
                int y = state % n + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && forest.get(x).get(y) > 0) {
                    if (dist[x * n + y] > dist[state] + 1) {
                        dist[x * n + y] = dist[state] + 1;
                        q.offer(new int[] {dist[x * n + y] + f(x * n + y, end), x * n + y});
                    }
                }
            }
        }
        return -1;
    }

    private int f(int start, int end) {
        int a = start / n;
        int b = start % n;
        int c = end / n;
        int d = end % n;
        return Math.abs(a - c) + Math.abs(b - d);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int m;
    int n;
    vector<int> dist;

    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();
        dist.resize(3600);
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i * n + j});
        sort(trees.begin(), trees.end());
        int ans = 0;
        int start = 0;
        for (auto& tree : trees) {
            int end = tree.second;
            int t = bfs(start, end, forest);
            if (t == -1) return -1;
            ans += t;
            start = end;
        }
        return ans;
    }

    int bfs(int start, int end, vector<vector<int>>& forest) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({f(start, end), start});
        fill(dist.begin(), dist.end(), INT_MAX);
        dist[start] = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int state = q.top().second;
            q.pop();
            if (state == end) return dist[state];
            for (int k = 0; k < 4; ++k) {
                int x = state / n + dirs[k], y = state % n + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] && dist[x * n + y] > dist[state] + 1) {
                    dist[x * n + y] = dist[state] + 1;
                    q.push({dist[x * n + y] + f(x * n + y, end), x * n + y});
                }
            }
        }
        return -1;
    }

    int f(int start, int end) {
        int a = start / n, b = start % n;
        int c = end / n, d = end % n;
        return abs(a - c) + abs(b - d);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
var dirs = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

type tree struct {
	height int
	pos    int
}

func cutOffTree(forest [][]int) int {
	row, col := len(forest), len(forest[0])

	bfs := func(start, end int) int {
		q := []int{start}
		vis := make(map[int]bool)
		vis[start] = true
		step := 0
		for n := len(q); n > 0; n = len(q) {
			for i := 0; i < n; i++ {
				state := q[0]
				q = q[1:]
				if state == end {
					return step
				}
				for k := 0; k < 4; k++ {
					x, y := state/col+dirs[k][0], state%col+dirs[k][1]
					nxt := x*col + y
					if x >= 0 && x < row && y >= 0 && y < col && forest[x][y] != 0 && !vis[nxt] {
						q = append(q, nxt)
						vis[nxt] = true
					}
				}
			}
			step++
		}
		return -1
	}

	var trees []tree
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if forest[i][j] > 1 {
				trees = append(trees, tree{forest[i][j], i*col + j})
			}
		}
	}
	sort.Slice(trees, func(i, j int) bool {
		return trees[i].height < trees[j].height
	})

	ans, start := 0, 0
	for _, t := range trees {
		end := t.pos
		step := bfs(start, end)
		if step == -1 {
			return -1
		}
		ans += step
		start = end
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
use std::collections::VecDeque;

const DIRS: [[i32; 2]; 4] = [[-1, 0], [1, 0], [0, -1], [0, 1]];

impl Solution {
    pub fn cut_off_tree(forest: Vec<Vec<i32>>) -> i32 {
        let (row, col) = (forest.len() as i32, forest[0].len() as i32);

        let bfs = |start: i32, end: i32| -> i32 {
            let mut queue = VecDeque::new();
            let mut vis = HashSet::new();
            queue.push_back(start);
            vis.insert(start);
            let mut step = 0;
            while !queue.is_empty() {
                let n = queue.len();
                for _ in 0..n {
                    let state = queue.pop_front().unwrap();
                    if state == end {
                        return step;
                    }
                    for k in 0..4 {
                        let x = state / col + DIRS[k][0];
                        let y = (state % col) + DIRS[k][1];
                        let nxt = x * col + y;
                        if x >= 0
                            && x < row
                            && y >= 0
                            && y < col
                            && forest[x as usize][y as usize] != 0
                            && !vis.contains(&nxt)
                        {
                            queue.push_back(nxt);
                            vis.insert(nxt);
                        }
                    }
                }
                step += 1;
            }
            -1
        };

        let mut trees = Vec::new();
        for i in 0..row {
            for j in 0..col {
                let height = forest[i as usize][j as usize];
                if height > 1 {
                    trees.push((height, i * col + j));
                }
            }
        }
        trees.sort();

        let (mut ans, mut start) = (0, 0);
        for t in &trees {
            let end = t.1;
            let step = bfs(start, end);
            if step == -1 {
                return -1;
            }
            ans += step;
            start = end;
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

<p>你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 <code>m x n</code> 的矩阵表示， 在这个矩阵中：</p>

<ul>
	<li><code>0</code> 表示障碍，无法触碰</li>
	<li><code>1</code> 表示地面，可以行走</li>
	<li><code>比 1 大的数</code> 表示有树的单元格，可以行走，数值表示树的高度</li>
</ul>

<p>每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。</p>

<p>你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 <code>1</code>（即变为地面）。</p>

<p>你将从 <code>(0, 0)</code> 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 <code>-1</code> 。</p>

<p>可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0675.Cut%20Off%20Trees%20for%20Golf%20Event/images/trees1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>forest = [[1,2,3],[0,0,4],[7,6,5]]
<strong>输出：</strong>6
<strong>解释：</strong>沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0675.Cut%20Off%20Trees%20for%20Golf%20Event/images/trees2.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>forest = [[1,2,3],[0,0,0],[7,6,5]]
<strong>输出：</strong>-1
<strong>解释：</strong>由于中间一行被障碍阻塞，无法访问最下面一行中的树。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>forest = [[2,3,4],[0,0,5],[8,7,6]]
<strong>输出：</strong>6
<strong>解释：</strong>可以按与示例 1 相同的路径来砍掉所有的树。
(0,0) 位置的树，可以直接砍去，不用算步数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == forest.length</code></li>
	<li><code>n == forest[i].length</code></li>
	<li><code>1 <= m, n <= 50</code></li>
	<li><code>0 <= forest[i][j] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 优先队列（A\* 算法）

题目的一个关键信息是“所有树的高度都不同”，要按照从小到大的顺序依次砍树，因此，我们先遍历树林，找出所有树及对应的坐标点。然后将树按照高度升序排列。

接下来就是找相邻两个点之间的最短距离。可以用 BFS，A\* 算法优化搜索。

A\* 算法主要思想如下：

1. 将 BFS 队列转换为优先队列（小根堆）；
1. 队列中的每个元素为 `(dist[state] + f(state), state)`，`dist[state]` 表示从起点到当前 state 的距离，`f(state)` 表示从当前 state 到终点的估计距离，这两个距离之和作为堆排序的依据；
1. 当终点第一次出队时，说明找到了从起点到终点的最短路径，直接返回对应的 step；
1. `f(state)` 是估价函数，并且估价函数要满足 `f(state) <= g(state)`，其中 `g(state)` 表示 state 到终点的真实距离；
1. A\* 算法只能保证终点第一次出队时，即找到了一条从起点到终点的最小路径，不能保证其他点出队时也是从起点到当前点的最短路径。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        def f(i, j, x, y):
            return abs(i - x) + abs(j - y)

        def bfs(i, j, x, y):
            q = [(f(i, j, x, y), i, j)]
            dist = {i * n + j: 0}
            while q:
                _, i, j = heappop(q)
                step = dist[i * n + j]
                if (i, j) == (x, y):
                    return step
                for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                    c, d = i + a, j + b
                    if 0 <= c < m and 0 <= d < n and forest[c][d] > 0:
                        if c * n + d not in dist or dist[c * n + d] > step + 1:
                            dist[c * n + d] = step + 1
                            heappush(q, (dist[c * n + d] + f(c, d, x, y), c, d))
            return -1

        m, n = len(forest), len(forest[0])
        trees = [
            (forest[i][j], i, j) for i in range(m) for j in range(n) if forest[i][j] > 1
        ]
        trees.sort()
        i = j = 0
        ans = 0
        for _, x, y in trees:
            t = bfs(i, j, x, y)
            if t == -1:
                return -1
            ans += t
            i, j = x, y
        return ans
```

#### Java

```java
class Solution {
    private int[] dist = new int[3600];
    private List<List<Integer>> forest;
    private int m;
    private int n;

    public int cutOffTree(List<List<Integer>> forest) {
        this.forest = forest;
        m = forest.size();
        n = forest.get(0).size();
        List<int[]> trees = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest.get(i).get(j) > 1) {
                    trees.add(new int[] {forest.get(i).get(j), i * n + j});
                }
            }
        }
        trees.sort(Comparator.comparingInt(a -> a[0]));
        int ans = 0;
        int start = 0;
        for (int[] tree : trees) {
            int end = tree[1];
            int t = bfs(start, end);
            if (t == -1) {
                return -1;
            }
            ans += t;
            start = end;
        }
        return ans;
    }

    private int bfs(int start, int end) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.offer(new int[] {f(start, end), start});
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int state = q.poll()[1];
            if (state == end) {
                return dist[state];
            }
            for (int k = 0; k < 4; ++k) {
                int x = state / n + dirs[k];
                int y = state % n + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && forest.get(x).get(y) > 0) {
                    if (dist[x * n + y] > dist[state] + 1) {
                        dist[x * n + y] = dist[state] + 1;
                        q.offer(new int[] {dist[x * n + y] + f(x * n + y, end), x * n + y});
                    }
                }
            }
        }
        return -1;
    }

    private int f(int start, int end) {
        int a = start / n;
        int b = start % n;
        int c = end / n;
        int d = end % n;
        return Math.abs(a - c) + Math.abs(b - d);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int m;
    int n;
    vector<int> dist;

    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();
        dist.resize(3600);
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i * n + j});
        sort(trees.begin(), trees.end());
        int ans = 0;
        int start = 0;
        for (auto& tree : trees) {
            int end = tree.second;
            int t = bfs(start, end, forest);
            if (t == -1) return -1;
            ans += t;
            start = end;
        }
        return ans;
    }

    int bfs(int start, int end, vector<vector<int>>& forest) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({f(start, end), start});
        fill(dist.begin(), dist.end(), INT_MAX);
        dist[start] = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int state = q.top().second;
            q.pop();
            if (state == end) return dist[state];
            for (int k = 0; k < 4; ++k) {
                int x = state / n + dirs[k], y = state % n + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] && dist[x * n + y] > dist[state] + 1) {
                    dist[x * n + y] = dist[state] + 1;
                    q.push({dist[x * n + y] + f(x * n + y, end), x * n + y});
                }
            }
        }
        return -1;
    }

    int f(int start, int end) {
        int a = start / n, b = start % n;
        int c = end / n, d = end % n;
        return abs(a - c) + abs(b - d);
    }
};
```

#### Go

```go
var dirs = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

type tree struct {
	height int
	pos    int
}

func cutOffTree(forest [][]int) int {
	row, col := len(forest), len(forest[0])

	bfs := func(start, end int) int {
		q := []int{start}
		vis := make(map[int]bool)
		vis[start] = true
		step := 0
		for n := len(q); n > 0; n = len(q) {
			for i := 0; i < n; i++ {
				state := q[0]
				q = q[1:]
				if state == end {
					return step
				}
				for k := 0; k < 4; k++ {
					x, y := state/col+dirs[k][0], state%col+dirs[k][1]
					nxt := x*col + y
					if x >= 0 && x < row && y >= 0 && y < col && forest[x][y] != 0 && !vis[nxt] {
						q = append(q, nxt)
						vis[nxt] = true
					}
				}
			}
			step++
		}
		return -1
	}

	var trees []tree
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if forest[i][j] > 1 {
				trees = append(trees, tree{forest[i][j], i*col + j})
			}
		}
	}
	sort.Slice(trees, func(i, j int) bool {
		return trees[i].height < trees[j].height
	})

	ans, start := 0, 0
	for _, t := range trees {
		end := t.pos
		step := bfs(start, end)
		if step == -1 {
			return -1
		}
		ans += step
		start = end
	}
	return ans
}
```

#### Rust

```rust
use std::collections::HashSet;
use std::collections::VecDeque;

const DIRS: [[i32; 2]; 4] = [[-1, 0], [1, 0], [0, -1], [0, 1]];

impl Solution {
    pub fn cut_off_tree(forest: Vec<Vec<i32>>) -> i32 {
        let (row, col) = (forest.len() as i32, forest[0].len() as i32);

        let bfs = |start: i32, end: i32| -> i32 {
            let mut queue = VecDeque::new();
            let mut vis = HashSet::new();
            queue.push_back(start);
            vis.insert(start);
            let mut step = 0;
            while !queue.is_empty() {
                let n = queue.len();
                for _ in 0..n {
                    let state = queue.pop_front().unwrap();
                    if state == end {
                        return step;
                    }
                    for k in 0..4 {
                        let x = state / col + DIRS[k][0];
                        let y = (state % col) + DIRS[k][1];
                        let nxt = x * col + y;
                        if x >= 0
                            && x < row
                            && y >= 0
                            && y < col
                            && forest[x as usize][y as usize] != 0
                            && !vis.contains(&nxt)
                        {
                            queue.push_back(nxt);
                            vis.insert(nxt);
                        }
                    }
                }
                step += 1;
            }
            -1
        };

        let mut trees = Vec::new();
        for i in 0..row {
            for j in 0..col {
                let height = forest[i as usize][j as usize];
                if height > 1 {
                    trees.push((height, i * col + j));
                }
            }
        }
        trees.sort();

        let (mut ans, mut start) = (0, 0);
        for t in &trees {
            let end = t.1;
            let step = bfs(start, end);
            if step == -1 {
                return -1;
            }
            ans += step;
            start = end;
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

# [676. 实现一个魔法字典](https://leetcode.cn/problems/implement-magic-dictionary){#676}

{{< tabs "676" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = "children", "is_end"

    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26
        self.is_end = False

    def insert(self, w: str) -> None:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: str) -> bool:
        def dfs(i: int, node: Optional[Trie], diff: int) -> bool:
            if i == len(w):
                return diff == 1 and node.is_end
            j = ord(w[i]) - ord("a")
            if node.children[j] and dfs(i + 1, node.children[j], diff):
                return True
            return diff == 0 and any(
                node.children[k] and dfs(i + 1, node.children[k], 1)
                for k in range(26)
                if k != j
            )

        return dfs(0, self, 0)


class MagicDictionary:
    def __init__(self):
        self.trie = Trie()

    def buildDict(self, dictionary: List[str]) -> None:
        for w in dictionary:
            self.trie.insert(w)

    def search(self, searchWord: str) -> bool:
        return self.trie.search(searchWord)


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private boolean isEnd;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int i = c - 'a';
            if (node.children[i] == null) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }

    public boolean search(String w) {
        return dfs(w, 0, this, 0);
    }

    private boolean dfs(String w, int i, Trie node, int diff) {
        if (i == w.length()) {
            return diff == 1 && node.isEnd;
        }
        int j = w.charAt(i) - 'a';
        if (node.children[j] != null) {
            if (dfs(w, i + 1, node.children[j], diff)) {
                return true;
            }
        }
        if (diff == 0) {
            for (int k = 0; k < 26; k++) {
                if (k != j && node.children[k] != null) {
                    if (dfs(w, i + 1, node.children[k], 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

class MagicDictionary {
    private Trie trie = new Trie();

    public MagicDictionary() {
    }

    public void buildDict(String[] dictionary) {
        for (String w : dictionary) {
            trie.insert(w);
        }
    }

    public boolean search(String searchWord) {
        return trie.search(searchWord);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[26];
    bool isEnd = false;

public:
    Trie() {
        fill(begin(children), end(children), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(const string& w) {
        function<bool(int, Trie*, int)> dfs = [&](int i, Trie* node, int diff) {
            if (i >= w.size()) {
                return diff == 1 && node->isEnd;
            }
            int j = w[i] - 'a';
            if (node->children[j] && dfs(i + 1, node->children[j], diff)) {
                return true;
            }
            if (diff == 0) {
                for (int k = 0; k < 26; ++k) {
                    if (k != j && node->children[k]) {
                        if (dfs(i + 1, node->children[k], 1)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(0, this, 0);
    }
};

class MagicDictionary {
public:
    MagicDictionary() {
        trie = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto& w : dictionary) {
            trie->insert(w);
        }
    }

    bool search(string searchWord) {
        return trie->search(searchWord);
    }

private:
    Trie* trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func NewTrie() *Trie {
	return &Trie{}
}

func (t *Trie) Insert(w string) {
	node := t
	for _, c := range w {
		i := c - 'a'
		if node.children[i] == nil {
			node.children[i] = NewTrie()
		}
		node = node.children[i]
	}
	node.isEnd = true
}

func (t *Trie) Search(w string) bool {
	var dfs func(int, *Trie, int) bool
	dfs = func(i int, node *Trie, diff int) bool {
		if i >= len(w) {
			return diff == 1 && node.isEnd
		}
		j := int(w[i] - 'a')
		if node.children[j] != nil && dfs(i+1, node.children[j], diff) {
			return true
		}
		if diff == 0 {
			for k := 0; k < 26; k++ {
				if k != j && node.children[k] != nil && dfs(i+1, node.children[k], 1) {
					return true
				}
			}
		}
		return false
	}
	return dfs(0, t, 0)
}

type MagicDictionary struct {
	trie *Trie
}

func Constructor() MagicDictionary {
	return MagicDictionary{trie: NewTrie()}
}

func (md *MagicDictionary) BuildDict(dictionary []string) {
	for _, w := range dictionary {
		md.trie.Insert(w)
	}
}

func (md *MagicDictionary) Search(searchWord string) bool {
	return md.trie.Search(searchWord)
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.BuildDict(dictionary);
 * param_2 := obj.Search(searchWord);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    private children: Trie[] = Array(26).fill(null);
    private isEnd: boolean = false;

    constructor() {}

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const i: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }

    search(w: string): boolean {
        const dfs = (i: number, node: Trie, diff: number): boolean => {
            if (i >= w.length) {
                return diff === 1 && node.isEnd;
            }
            const j: number = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[j] && dfs(i + 1, node.children[j], diff)) {
                return true;
            }
            if (diff === 0) {
                for (let k = 0; k < 26; k++) {
                    if (k !== j && node.children[k] && dfs(i + 1, node.children[k], 1)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(0, this, 0);
    }
}

class MagicDictionary {
    private trie: Trie;

    constructor() {
        this.trie = new Trie();
    }

    buildDict(dictionary: string[]): void {
        for (const w of dictionary) {
            this.trie.insert(w);
        }
    }

    search(searchWord: string): boolean {
        return this.trie.search(searchWord);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * var obj = new MagicDictionary()
 * obj.buildDict(dictionary)
 * var param_2 = obj.search(searchWord)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct Trie {
    children: [Option<Box<Trie>>; 26],
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: Default::default(),
            is_end: false,
        }
    }

    fn insert(&mut self, w: &str) {
        let mut node = self;
        for c in w.chars() {
            let i = (c as usize) - ('a' as usize);
            if node.children[i].is_none() {
                node.children[i] = Some(Box::new(Trie::new()));
            }
            node = node.children[i].as_mut().unwrap();
        }
        node.is_end = true;
    }

    fn search(&self, w: &str) -> bool {
        self.dfs(w, 0, 0)
    }

    fn dfs(&self, w: &str, i: usize, diff: usize) -> bool {
        if i == w.len() {
            return diff == 1 && self.is_end;
        }

        let j = (w.chars().nth(i).unwrap() as usize) - ('a' as usize);

        if let Some(child) = &self.children[j] {
            if child.dfs(w, i + 1, diff) {
                return true;
            }
        }

        if diff == 0 {
            for k in 0..26 {
                if k != j {
                    if let Some(child) = &self.children[k] {
                        if child.dfs(w, i + 1, 1) {
                            return true;
                        }
                    }
                }
            }
        }
        false
    }
}

struct MagicDictionary {
    trie: Trie,
}

impl MagicDictionary {
    fn new() -> Self {
        MagicDictionary {
            trie: Trie::new(),
        }
    }

    fn build_dict(&mut self, dictionary: Vec<String>) {
        for w in dictionary {
            self.trie.insert(&w);
        }
    }

    fn search(&self, search_word: String) -> bool {
        self.trie.search(&search_word)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 <strong>互不相同</strong> 。 如果给出一个单词，请判定能否只将这个单词中<strong>一个</strong>字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。</p>

<p>实现 <code>MagicDictionary</code> 类：</p>

<ul>
	<li><code>MagicDictionary()</code> 初始化对象</li>
	<li><code>void buildDict(String[] dictionary)</code> 使用字符串数组 <code>dictionary</code> 设定该数据结构，<code>dictionary</code> 中的字符串互不相同</li>
	<li><code>bool search(String searchWord)</code> 给定一个字符串 <code>searchWord</code> ，判定能否只将字符串中<strong> 一个 </strong>字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p> </p>

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
<strong>输出</strong>
[null, null, false, true, false, false]

<strong>解释</strong>
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // 返回 False
magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
magicDictionary.search("hell"); // 返回 False
magicDictionary.search("leetcoded"); // 返回 False
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= dictionary.length <= 100</code></li>
	<li><code>1 <= dictionary[i].length <= 100</code></li>
	<li><code>dictionary[i]</code> 仅由小写英文字母组成</li>
	<li><code>dictionary</code> 中的所有字符串 <strong>互不相同</strong></li>
	<li><code>1 <= searchWord.length <= 100</code></li>
	<li><code>searchWord</code> 仅由小写英文字母组成</li>
	<li><code>buildDict</code> 仅在 <code>search</code> 之前调用一次</li>
	<li>最多调用 <code>100</code> 次 <code>search</code></li>
</ul>
</div>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + DFS

我们可以使用前缀树来存储字典中的所有单词，然后对于每个搜索的单词，我们使用深度优先搜索的方法，具体地，我们从前缀树的根节点开始，对于当前遍历到的字母，我们首先判断是否存在与其相同的子节点，如果存在，则继续向下遍历，否则我们需要判断是否还有剩余的修改次数，如果没有，则说明无法匹配，返回 false。如果有剩余的修改次数，我们可以尝试对当前的字母进行修改，然后继续向下遍历，如果当前的字母修改后对应的子节点存在，则说明可以匹配，否则说明无法匹配，返回 false。如果我们遍历到了单词的结尾，且修改次数恰好为 1，那么说明可以匹配，返回 true。

时间复杂度 $O(n \times l + q \times l \times |\Sigma|)$，空间复杂度 $O(n \times l)$，其中 $n$ 和 $l$ 分别是字典中的单词数量和单词的平均长度，而 $q$ 是搜索的单词数量。另外 $|\Sigma|$ 表示字符集的大小，这里字符集为小写英文字母，因此 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = "children", "is_end"

    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26
        self.is_end = False

    def insert(self, w: str) -> None:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: str) -> bool:
        def dfs(i: int, node: Optional[Trie], diff: int) -> bool:
            if i == len(w):
                return diff == 1 and node.is_end
            j = ord(w[i]) - ord("a")
            if node.children[j] and dfs(i + 1, node.children[j], diff):
                return True
            return diff == 0 and any(
                node.children[k] and dfs(i + 1, node.children[k], 1)
                for k in range(26)
                if k != j
            )

        return dfs(0, self, 0)


class MagicDictionary:
    def __init__(self):
        self.trie = Trie()

    def buildDict(self, dictionary: List[str]) -> None:
        for w in dictionary:
            self.trie.insert(w)

    def search(self, searchWord: str) -> bool:
        return self.trie.search(searchWord)


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private boolean isEnd;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int i = c - 'a';
            if (node.children[i] == null) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }

    public boolean search(String w) {
        return dfs(w, 0, this, 0);
    }

    private boolean dfs(String w, int i, Trie node, int diff) {
        if (i == w.length()) {
            return diff == 1 && node.isEnd;
        }
        int j = w.charAt(i) - 'a';
        if (node.children[j] != null) {
            if (dfs(w, i + 1, node.children[j], diff)) {
                return true;
            }
        }
        if (diff == 0) {
            for (int k = 0; k < 26; k++) {
                if (k != j && node.children[k] != null) {
                    if (dfs(w, i + 1, node.children[k], 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

class MagicDictionary {
    private Trie trie = new Trie();

    public MagicDictionary() {
    }

    public void buildDict(String[] dictionary) {
        for (String w : dictionary) {
            trie.insert(w);
        }
    }

    public boolean search(String searchWord) {
        return trie.search(searchWord);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
```

#### C++

```cpp
class Trie {
private:
    Trie* children[26];
    bool isEnd = false;

public:
    Trie() {
        fill(begin(children), end(children), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(const string& w) {
        function<bool(int, Trie*, int)> dfs = [&](int i, Trie* node, int diff) {
            if (i >= w.size()) {
                return diff == 1 && node->isEnd;
            }
            int j = w[i] - 'a';
            if (node->children[j] && dfs(i + 1, node->children[j], diff)) {
                return true;
            }
            if (diff == 0) {
                for (int k = 0; k < 26; ++k) {
                    if (k != j && node->children[k]) {
                        if (dfs(i + 1, node->children[k], 1)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(0, this, 0);
    }
};

class MagicDictionary {
public:
    MagicDictionary() {
        trie = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (auto& w : dictionary) {
            trie->insert(w);
        }
    }

    bool search(string searchWord) {
        return trie->search(searchWord);
    }

private:
    Trie* trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func NewTrie() *Trie {
	return &Trie{}
}

func (t *Trie) Insert(w string) {
	node := t
	for _, c := range w {
		i := c - 'a'
		if node.children[i] == nil {
			node.children[i] = NewTrie()
		}
		node = node.children[i]
	}
	node.isEnd = true
}

func (t *Trie) Search(w string) bool {
	var dfs func(int, *Trie, int) bool
	dfs = func(i int, node *Trie, diff int) bool {
		if i >= len(w) {
			return diff == 1 && node.isEnd
		}
		j := int(w[i] - 'a')
		if node.children[j] != nil && dfs(i+1, node.children[j], diff) {
			return true
		}
		if diff == 0 {
			for k := 0; k < 26; k++ {
				if k != j && node.children[k] != nil && dfs(i+1, node.children[k], 1) {
					return true
				}
			}
		}
		return false
	}
	return dfs(0, t, 0)
}

type MagicDictionary struct {
	trie *Trie
}

func Constructor() MagicDictionary {
	return MagicDictionary{trie: NewTrie()}
}

func (md *MagicDictionary) BuildDict(dictionary []string) {
	for _, w := range dictionary {
		md.trie.Insert(w)
	}
}

func (md *MagicDictionary) Search(searchWord string) bool {
	return md.trie.Search(searchWord)
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.BuildDict(dictionary);
 * param_2 := obj.Search(searchWord);
 */
```

#### TypeScript

```ts
class Trie {
    private children: Trie[] = Array(26).fill(null);
    private isEnd: boolean = false;

    constructor() {}

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const i: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }

    search(w: string): boolean {
        const dfs = (i: number, node: Trie, diff: number): boolean => {
            if (i >= w.length) {
                return diff === 1 && node.isEnd;
            }
            const j: number = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[j] && dfs(i + 1, node.children[j], diff)) {
                return true;
            }
            if (diff === 0) {
                for (let k = 0; k < 26; k++) {
                    if (k !== j && node.children[k] && dfs(i + 1, node.children[k], 1)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(0, this, 0);
    }
}

class MagicDictionary {
    private trie: Trie;

    constructor() {
        this.trie = new Trie();
    }

    buildDict(dictionary: string[]): void {
        for (const w of dictionary) {
            this.trie.insert(w);
        }
    }

    search(searchWord: string): boolean {
        return this.trie.search(searchWord);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * var obj = new MagicDictionary()
 * obj.buildDict(dictionary)
 * var param_2 = obj.search(searchWord)
 */
```

#### Rust

```rust
struct Trie {
    children: [Option<Box<Trie>>; 26],
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: Default::default(),
            is_end: false,
        }
    }

    fn insert(&mut self, w: &str) {
        let mut node = self;
        for c in w.chars() {
            let i = (c as usize) - ('a' as usize);
            if node.children[i].is_none() {
                node.children[i] = Some(Box::new(Trie::new()));
            }
            node = node.children[i].as_mut().unwrap();
        }
        node.is_end = true;
    }

    fn search(&self, w: &str) -> bool {
        self.dfs(w, 0, 0)
    }

    fn dfs(&self, w: &str, i: usize, diff: usize) -> bool {
        if i == w.len() {
            return diff == 1 && self.is_end;
        }

        let j = (w.chars().nth(i).unwrap() as usize) - ('a' as usize);

        if let Some(child) = &self.children[j] {
            if child.dfs(w, i + 1, diff) {
                return true;
            }
        }

        if diff == 0 {
            for k in 0..26 {
                if k != j {
                    if let Some(child) = &self.children[k] {
                        if child.dfs(w, i + 1, 1) {
                            return true;
                        }
                    }
                }
            }
        }
        false
    }
}

struct MagicDictionary {
    trie: Trie,
}

impl MagicDictionary {
    fn new() -> Self {
        MagicDictionary {
            trie: Trie::new(),
        }
    }

    fn build_dict(&mut self, dictionary: Vec<String>) {
        for w in dictionary {
            self.trie.insert(&w);
        }
    }

    fn search(&self, search_word: String) -> bool {
        self.trie.search(&search_word)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [677. 键值映射](https://leetcode.cn/problems/map-sum-pairs){#677}

{{< tabs "677" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.val: int = 0

    def insert(self, w: str, x: int):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.val += x

    def search(self, w: str) -> int:
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return 0
            node = node.children[idx]
        return node.val


class MapSum:
    def __init__(self):
        self.d = defaultdict(int)
        self.tree = Trie()

    def insert(self, key: str, val: int) -> None:
        x = val - self.d[key]
        self.d[key] = val
        self.tree.insert(key, x)

    def sum(self, prefix: str) -> int:
        return self.tree.search(prefix)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private int val;

    public void insert(String w, int x) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.val += x;
        }
    }

    public int search(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                return 0;
            }
            node = node.children[idx];
        }
        return node.val;
    }
}

class MapSum {
    private Map<String, Integer> d = new HashMap<>();
    private Trie trie = new Trie();

    public MapSum() {
    }

    public void insert(String key, int val) {
        int x = val - d.getOrDefault(key, 0);
        d.put(key, val);
        trie.insert(key, x);
    }

    public int sum(String prefix) {
        return trie.search(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie()
        : children(26, nullptr) {
    }

    void insert(string& w, int x) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
            node->val += x;
        }
    }

    int search(string& w) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                return 0;
            }
            node = node->children[c];
        }
        return node->val;
    }

private:
    vector<Trie*> children;
    int val = 0;
};

class MapSum {
public:
    MapSum() {
    }

    void insert(string key, int val) {
        int x = val - d[key];
        d[key] = val;
        trie->insert(key, x);
    }

    int sum(string prefix) {
        return trie->search(prefix);
    }

private:
    unordered_map<string, int> d;
    Trie* trie = new Trie();
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type trie struct {
	children [26]*trie
	val      int
}

func (t *trie) insert(w string, x int) {
	for _, c := range w {
		c -= 'a'
		if t.children[c] == nil {
			t.children[c] = &trie{}
		}
		t = t.children[c]
		t.val += x
	}
}

func (t *trie) search(w string) int {
	for _, c := range w {
		c -= 'a'
		if t.children[c] == nil {
			return 0
		}
		t = t.children[c]
	}
	return t.val
}

type MapSum struct {
	d map[string]int
	t *trie
}

func Constructor() MapSum {
	return MapSum{make(map[string]int), &trie{}}
}

func (this *MapSum) Insert(key string, val int) {
	x := val - this.d[key]
	this.d[key] = val
	this.t.insert(key, x)
}

func (this *MapSum) Sum(prefix string) int {
	return this.t.search(prefix)
}

/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: Trie[];
    val: number;

    constructor() {
        this.children = new Array(26);
        this.val = 0;
    }

    insert(w: string, x: number) {
        let node: Trie = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
            node.val += x;
        }
    }

    search(w: string): number {
        let node: Trie = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                return 0;
            }
            node = node.children[i];
        }
        return node.val;
    }
}

class MapSum {
    d: Map<string, number>;
    t: Trie;
    constructor() {
        this.d = new Map();
        this.t = new Trie();
    }

    insert(key: string, val: number): void {
        const x = val - (this.d.get(key) ?? 0);
        this.d.set(key, val);
        this.t.insert(key, x);
    }

    sum(prefix: string): number {
        return this.t.search(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * var obj = new MapSum()
 * obj.insert(key,val)
 * var param_2 = obj.sum(prefix)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct Trie {
    children: Vec<Option<Box<Trie>>>,
    val: i32,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: (0..26).map(|_| None).collect(),
            val: 0,
        }
    }

    fn insert(&mut self, w: &str, x: i32) {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() {
                node.children[idx] = Some(Box::new(Trie::new()));
            }
            node = node.children[idx].as_mut().unwrap();
            node.val += x;
        }
    }

    fn search(&self, w: &str) -> i32 {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() {
                return 0;
            }
            node = node.children[idx].as_ref().unwrap();
        }
        node.val
    }
}

struct MapSum {
    d: std::collections::HashMap<String, i32>,
    trie: Trie,
}

impl MapSum {
    fn new() -> Self {
        MapSum {
            d: std::collections::HashMap::new(),
            trie: Trie::new(),
        }
    }

    fn insert(&mut self, key: String, val: i32) {
        let x = val - self.d.get(&key).unwrap_or(&0);
        self.d.insert(key.clone(), val);
        self.trie.insert(&key, x);
    }

    fn sum(&self, prefix: String) -> i32 {
        self.trie.search(&prefix)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
class Trie {
    constructor() {
        this.children = new Array(26);
        this.val = 0;
    }

    insert(w, x) {
        let node = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
            node.val += x;
        }
    }

    search(w) {
        let node = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                return 0;
            }
            node = node.children[i];
        }
        return node.val;
    }
}

var MapSum = function () {
    this.d = new Map();
    this.t = new Trie();
};

/**
 * @param {string} key
 * @param {number} val
 * @return {void}
 */
MapSum.prototype.insert = function (key, val) {
    const x = val - (this.d.get(key) ?? 0);
    this.d.set(key, val);
    this.t.insert(key, x);
};

/**
 * @param {string} prefix
 * @return {number}
 */
MapSum.prototype.sum = function (prefix) {
    return this.t.search(prefix);
};

/**
 * Your MapSum object will be instantiated and called as such:
 * var obj = new MapSum()
 * obj.insert(key,val)
 * var param_2 = obj.sum(prefix)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Trie {
    private Trie[] children = new Trie[26];
    private int val;

    public void Insert(string w, int x) {
        Trie node = this;
        for (int i = 0; i < w.Length; ++i) {
            int idx = w[i] - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.val += x;
        }
    }

    public int Search(string w) {
        Trie node = this;
        for (int i = 0; i < w.Length; ++i) {
            int idx = w[i] - 'a';
            if (node.children[idx] == null) {
                return 0;
            }
            node = node.children[idx];
        }
        return node.val;
    }
}

public class MapSum {
    private Dictionary<string, int> d = new Dictionary<string, int>();
    private Trie trie = new Trie();

    public MapSum() {
    }

    public void Insert(string key, int val) {
        int x = val - (d.ContainsKey(key) ? d[key] : 0);
        d[key] = val;
        trie.Insert(key, x);
    }

    public int Sum(string prefix) {
        return trie.Search(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.Insert(key,val);
 * int param_2 = obj.Sum(prefix);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个 map ，满足以下几点:</p>

<ul>
	<li>字符串表示键，整数表示值</li>
	<li>返回具有前缀等于给定字符串的键的值的总和</li>
</ul>

<p>实现一个 <code>MapSum</code> 类：</p>

<ul>
	<li><code>MapSum()</code> 初始化 <code>MapSum</code> 对象</li>
	<li><code>void insert(String key, int val)</code> 插入 <code>key-val</code> 键值对，字符串表示键 <code>key</code> ，整数表示值 <code>val</code> 。如果键 <code>key</code> 已经存在，那么原来的键值对&nbsp;<code>key-value</code>&nbsp;将被替代成新的键值对。</li>
	<li><code>int sum(string prefix)</code> 返回所有以该前缀 <code>prefix</code> 开头的键 <code>key</code> 的值的总和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
<strong>输出：</strong>
[null, null, 3, null, 5]

<strong>解释：</strong>
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // 返回 3 (<u>ap</u>ple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // 返回 5 (<u>ap</u>ple + <u>ap</u>p = 3 + 2 = 5)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= key.length, prefix.length &lt;= 50</code></li>
	<li><code>key</code> 和 <code>prefix</code> 仅由小写英文字母组成</li>
	<li><code>1 &lt;= val &lt;= 1000</code></li>
	<li>最多调用 <code>50</code> 次 <code>insert</code> 和 <code>sum</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀树

我们用哈希表 $d$ 存放键值对，用前缀树 $t$ 存放键值对的前缀和。前缀树的每个节点包含两个信息：

-   `val`：以该节点为前缀的键值对的值的总和
-   `children`：长度为 $26$ 的数组，存放该节点的子节点

插入键值对 $(key, val)$ 时，我们先判断哈希表是否存在该键，如果存在，那么前缀树每个节点的 `val` 都要减去该键原来的值，然后再加上新的值。如果不存在，那么前缀树每个节点的 `val` 都要加上新的值。

查询前缀和时，我们从前缀树的根节点开始，遍历前缀字符串，如果当前节点的子节点中不存在该字符，那么说明前缀树中不存在该前缀，返回 $0$。否则，继续遍历下一个字符，直到遍历完前缀字符串，返回当前节点的 `val`。

时间复杂度方面，插入键值对的时间复杂度为 $O(n)$，其中 $n$ 为键的长度。查询前缀和的时间复杂度为 $O(m)$，其中 $m$ 为前缀的长度。

空间复杂度 $O(n \times m \times C)$，其中 $n$ 和 $m$ 分别是键的数量以及键的最大长度；而 $C$ 是字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.val: int = 0

    def insert(self, w: str, x: int):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.val += x

    def search(self, w: str) -> int:
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return 0
            node = node.children[idx]
        return node.val


class MapSum:
    def __init__(self):
        self.d = defaultdict(int)
        self.tree = Trie()

    def insert(self, key: str, val: int) -> None:
        x = val - self.d[key]
        self.d[key] = val
        self.tree.insert(key, x)

    def sum(self, prefix: str) -> int:
        return self.tree.search(prefix)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private int val;

    public void insert(String w, int x) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.val += x;
        }
    }

    public int search(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                return 0;
            }
            node = node.children[idx];
        }
        return node.val;
    }
}

class MapSum {
    private Map<String, Integer> d = new HashMap<>();
    private Trie trie = new Trie();

    public MapSum() {
    }

    public void insert(String key, int val) {
        int x = val - d.getOrDefault(key, 0);
        d.put(key, val);
        trie.insert(key, x);
    }

    public int sum(String prefix) {
        return trie.search(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
```

#### C++

```cpp
class Trie {
public:
    Trie()
        : children(26, nullptr) {
    }

    void insert(string& w, int x) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
            node->val += x;
        }
    }

    int search(string& w) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                return 0;
            }
            node = node->children[c];
        }
        return node->val;
    }

private:
    vector<Trie*> children;
    int val = 0;
};

class MapSum {
public:
    MapSum() {
    }

    void insert(string key, int val) {
        int x = val - d[key];
        d[key] = val;
        trie->insert(key, x);
    }

    int sum(string prefix) {
        return trie->search(prefix);
    }

private:
    unordered_map<string, int> d;
    Trie* trie = new Trie();
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```

#### Go

```go
type trie struct {
	children [26]*trie
	val      int
}

func (t *trie) insert(w string, x int) {
	for _, c := range w {
		c -= 'a'
		if t.children[c] == nil {
			t.children[c] = &trie{}
		}
		t = t.children[c]
		t.val += x
	}
}

func (t *trie) search(w string) int {
	for _, c := range w {
		c -= 'a'
		if t.children[c] == nil {
			return 0
		}
		t = t.children[c]
	}
	return t.val
}

type MapSum struct {
	d map[string]int
	t *trie
}

func Constructor() MapSum {
	return MapSum{make(map[string]int), &trie{}}
}

func (this *MapSum) Insert(key string, val int) {
	x := val - this.d[key]
	this.d[key] = val
	this.t.insert(key, x)
}

func (this *MapSum) Sum(prefix string) int {
	return this.t.search(prefix)
}

/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
```

#### TypeScript

```ts
class Trie {
    children: Trie[];
    val: number;

    constructor() {
        this.children = new Array(26);
        this.val = 0;
    }

    insert(w: string, x: number) {
        let node: Trie = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
            node.val += x;
        }
    }

    search(w: string): number {
        let node: Trie = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                return 0;
            }
            node = node.children[i];
        }
        return node.val;
    }
}

class MapSum {
    d: Map<string, number>;
    t: Trie;
    constructor() {
        this.d = new Map();
        this.t = new Trie();
    }

    insert(key: string, val: number): void {
        const x = val - (this.d.get(key) ?? 0);
        this.d.set(key, val);
        this.t.insert(key, x);
    }

    sum(prefix: string): number {
        return this.t.search(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * var obj = new MapSum()
 * obj.insert(key,val)
 * var param_2 = obj.sum(prefix)
 */
```

#### Rust

```rust
struct Trie {
    children: Vec<Option<Box<Trie>>>,
    val: i32,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: (0..26).map(|_| None).collect(),
            val: 0,
        }
    }

    fn insert(&mut self, w: &str, x: i32) {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() {
                node.children[idx] = Some(Box::new(Trie::new()));
            }
            node = node.children[idx].as_mut().unwrap();
            node.val += x;
        }
    }

    fn search(&self, w: &str) -> i32 {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() {
                return 0;
            }
            node = node.children[idx].as_ref().unwrap();
        }
        node.val
    }
}

struct MapSum {
    d: std::collections::HashMap<String, i32>,
    trie: Trie,
}

impl MapSum {
    fn new() -> Self {
        MapSum {
            d: std::collections::HashMap::new(),
            trie: Trie::new(),
        }
    }

    fn insert(&mut self, key: String, val: i32) {
        let x = val - self.d.get(&key).unwrap_or(&0);
        self.d.insert(key.clone(), val);
        self.trie.insert(&key, x);
    }

    fn sum(&self, prefix: String) -> i32 {
        self.trie.search(&prefix)
    }
}
```

#### JavaScript

```js
class Trie {
    constructor() {
        this.children = new Array(26);
        this.val = 0;
    }

    insert(w, x) {
        let node = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
            node.val += x;
        }
    }

    search(w) {
        let node = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                return 0;
            }
            node = node.children[i];
        }
        return node.val;
    }
}

var MapSum = function () {
    this.d = new Map();
    this.t = new Trie();
};

/**
 * @param {string} key
 * @param {number} val
 * @return {void}
 */
MapSum.prototype.insert = function (key, val) {
    const x = val - (this.d.get(key) ?? 0);
    this.d.set(key, val);
    this.t.insert(key, x);
};

/**
 * @param {string} prefix
 * @return {number}
 */
MapSum.prototype.sum = function (prefix) {
    return this.t.search(prefix);
};

/**
 * Your MapSum object will be instantiated and called as such:
 * var obj = new MapSum()
 * obj.insert(key,val)
 * var param_2 = obj.sum(prefix)
 */
```

#### C#

```cs
public class Trie {
    private Trie[] children = new Trie[26];
    private int val;

    public void Insert(string w, int x) {
        Trie node = this;
        for (int i = 0; i < w.Length; ++i) {
            int idx = w[i] - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.val += x;
        }
    }

    public int Search(string w) {
        Trie node = this;
        for (int i = 0; i < w.Length; ++i) {
            int idx = w[i] - 'a';
            if (node.children[idx] == null) {
                return 0;
            }
            node = node.children[idx];
        }
        return node.val;
    }
}

public class MapSum {
    private Dictionary<string, int> d = new Dictionary<string, int>();
    private Trie trie = new Trie();

    public MapSum() {
    }

    public void Insert(string key, int val) {
        int x = val - (d.ContainsKey(key) ? d[key] : 0);
        d[key] = val;
        trie.Insert(key, x);
    }

    public int Sum(string prefix) {
        return trie.Search(prefix);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.Insert(key,val);
 * int param_2 = obj.Sum(prefix);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [678. 有效的括号字符串](https://leetcode.cn/problems/valid-parenthesis-string){#678}

{{< tabs "678" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        x = 0
        for c in s:
            if c in '(*':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        x = 0
        for c in s[::-1]:
            if c in '*)':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkValidString(String s) {
        int x = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != ')') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) != '(') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
                return false;
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
    bool checkValidString(string s) {
        int x = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ')') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '(') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkValidString(s string) bool {
	x := 0
	for _, c := range s {
		if c != ')' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	x = 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != '(' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个只包含三种字符的字符串，支持的字符类型分别是 <code>'('</code>、<code>')'</code> 和 <code>'*'</code>。请你检验这个字符串是否为有效字符串，如果是 <strong>有效</strong> 字符串返回 <code>true</code> 。</p>

<p><strong>有效</strong> 字符串符合如下规则：</p>

<ul>
	<li>任何左括号 <code>'('</code>&nbsp;必须有相应的右括号 <code>')'</code>。</li>
	<li>任何右括号 <code>')'</code>&nbsp;必须有相应的左括号 <code>'('</code>&nbsp;。</li>
	<li>左括号 <code>'('</code> 必须在对应的右括号之前 <code>')'</code>。</li>
	<li><code>'*'</code>&nbsp;可以被视为单个右括号 <code>')'</code>&nbsp;，或单个左括号 <code>'('</code>&nbsp;，或一个空字符串 <code>""</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "()"
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(*)"
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "(*))"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> 为 <code>'('</code>、<code>')'</code> 或 <code>'*'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

定义 $dp[i][j]$ 表示字符串 $s$ 中下标范围 $[i..j]$ 内的子串是否为有效括号字符串。答案为 $dp[0][n - 1]$。

子串长度为 $1$ 时，如果字符 $s[i]$ 为 `*`，则 $dp[i][i]$ 为 `true`，否则为 `false`。

子串长度大于 $1$ 时，如果满足下面任意一种情况，则 $dp[i][j]$ 为 `true`：

-   子串 $s[i..j]$ 的左边界为 `(` 或 `*`，且右边界为 `*` 或 `)`，且 $s[i+1..j-1]$ 为有效括号字符串；
-   子串 $s[i..j]$ 中的任意下标 $k$，如果 $s[i..k]$ 为有效括号字符串，且 $s[k+1..j]$ 为有效括号字符串，则 $s[i..j]$ 为有效括号字符串。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for i, c in enumerate(s):
            dp[i][i] = c == '*'
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                dp[i][j] = (
                    s[i] in '(*' and s[j] in '*)' and (i + 1 == j or dp[i + 1][j - 1])
                )
                dp[i][j] = dp[i][j] or any(
                    dp[i][k] and dp[k + 1][j] for k in range(i, j)
                )
        return dp[0][-1]
```

#### Java

```java
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = s.charAt(i) == '*';
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                char a = s.charAt(i), b = s.charAt(j);
                dp[i][j] = (a == '(' || a == '*') && (b == '*' || b == ')')
                    && (i + 1 == j || dp[i + 1][j - 1]);
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
        return dp[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = s[i] == '*';
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                char a = s[i], b = s[j];
                dp[i][j] = (a == '(' || a == '*') && (b == '*' || b == ')') && (i + 1 == j || dp[i + 1][j - 1]);
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

#### Go

```go
func checkValidString(s string) bool {
	n := len(s)
	dp := make([][]bool, n)
	for i := range dp {
		dp[i] = make([]bool, n)
		dp[i][i] = s[i] == '*'
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			a, b := s[i], s[j]
			dp[i][j] = (a == '(' || a == '*') && (b == '*' || b == ')') && (i+1 == j || dp[i+1][j-1])
			for k := i; k < j && !dp[i][j]; k++ {
				dp[i][j] = dp[i][k] && dp[k+1][j]
			}
		}
	}
	return dp[0][n-1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 两遍扫描

两遍扫描，第一遍从左往右，确定每一个右括号都可以成功配对，第二遍从右往左，确定每一个左括号都可以成功配对。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 `s` 的长度。

相似题目：

-   [2116. 判断一个括号字符串是否有效](https://github.com/doocs/leetcode/blob/main/solution/2100-2199/2116.Check%20if%20a%20Parentheses%20String%20Can%20Be%20Valid/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        x = 0
        for c in s:
            if c in '(*':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        x = 0
        for c in s[::-1]:
            if c in '*)':
                x += 1
            elif x:
                x -= 1
            else:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean checkValidString(String s) {
        int x = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != ')') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) != '(') {
                ++x;
            } else if (x > 0) {
                --x;
            } else {
                return false;
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
    bool checkValidString(string s) {
        int x = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ')') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        x = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '(') {
                ++x;
            } else if (x) {
                --x;
            } else {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkValidString(s string) bool {
	x := 0
	for _, c := range s {
		if c != ')' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	x = 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != '(' {
			x++
		} else if x > 0 {
			x--
		} else {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [679. 24 点游戏](https://leetcode.cn/problems/24-game){#679}

{{< tabs "679" >}}

{{% tab "python" %}}
```python
class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        def dfs(nums: List[float]):
            n = len(nums)
            if n == 1:
                if abs(nums[0] - 24) < 1e-6:
                    return True
                return False
            ok = False
            for i in range(n):
                for j in range(n):
                    if i != j:
                        nxt = [nums[k] for k in range(n) if k != i and k != j]
                        for op in ops:
                            match op:
                                case "/":
                                    if nums[j] == 0:
                                        continue
                                    ok |= dfs(nxt + [nums[i] / nums[j]])
                                case "*":
                                    ok |= dfs(nxt + [nums[i] * nums[j]])
                                case "+":
                                    ok |= dfs(nxt + [nums[i] + nums[j]])
                                case "-":
                                    ok |= dfs(nxt + [nums[i] - nums[j]])
                            if ok:
                                return True
            return ok

        ops = ("+", "-", "*", "/")
        nums = [float(x) for x in cards]
        return dfs(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final char[] ops = {'+', '-', '*', '/'};

    public boolean judgePoint24(int[] cards) {
        List<Double> nums = new ArrayList<>();
        for (int num : cards) {
            nums.add((double) num);
        }
        return dfs(nums);
    }

    private boolean dfs(List<Double> nums) {
        int n = nums.size();
        if (n == 1) {
            return Math.abs(nums.get(0) - 24) < 1e-6;
        }
        boolean ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    List<Double> nxt = new ArrayList<>();
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            nxt.add(nums.get(k));
                        }
                    }
                    for (char op : ops) {
                        switch (op) {
                            case '/' -> {
                                if (nums.get(j) == 0) {
                                    continue;
                                }
                                nxt.add(nums.get(i) / nums.get(j));
                            }
                            case '*' -> {
                                nxt.add(nums.get(i) * nums.get(j));
                            }
                            case '+' -> {
                                nxt.add(nums.get(i) + nums.get(j));
                            }
                            case '-' -> {
                                nxt.add(nums.get(i) - nums.get(j));
                            }
                        }
                        ok |= dfs(nxt);
                        if (ok) {
                            return true;
                        }
                        nxt.remove(nxt.size() - 1);
                    }
                }
            }
        }
        return ok;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int num : cards) {
            nums.push_back(static_cast<double>(num));
        }
        return dfs(nums);
    }

private:
    const char ops[4] = {'+', '-', '*', '/'};

    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return abs(nums[0] - 24) < 1e-6;
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    vector<double> nxt;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            nxt.push_back(nums[k]);
                        }
                    }
                    for (char op : ops) {
                        switch (op) {
                        case '/':
                            if (nums[j] == 0) {
                                continue;
                            }
                            nxt.push_back(nums[i] / nums[j]);
                            break;
                        case '*':
                            nxt.push_back(nums[i] * nums[j]);
                            break;
                        case '+':
                            nxt.push_back(nums[i] + nums[j]);
                            break;
                        case '-':
                            nxt.push_back(nums[i] - nums[j]);
                            break;
                        }
                        ok |= dfs(nxt);
                        if (ok) {
                            return true;
                        }
                        nxt.pop_back();
                    }
                }
            }
        }
        return ok;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func judgePoint24(cards []int) bool {
	ops := [4]rune{'+', '-', '*', '/'}
	nums := make([]float64, len(cards))
	for i, num := range cards {
		nums[i] = float64(num)
	}
	var dfs func([]float64) bool
	dfs = func(nums []float64) bool {
		n := len(nums)
		if n == 1 {
			return math.Abs(nums[0]-24) < 1e-6
		}
		ok := false
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i != j {
					var nxt []float64
					for k := 0; k < n; k++ {
						if k != i && k != j {
							nxt = append(nxt, nums[k])
						}
					}
					for _, op := range ops {
						switch op {
						case '/':
							if nums[j] == 0 {
								continue
							}
							nxt = append(nxt, nums[i]/nums[j])
						case '*':
							nxt = append(nxt, nums[i]*nums[j])
						case '+':
							nxt = append(nxt, nums[i]+nums[j])
						case '-':
							nxt = append(nxt, nums[i]-nums[j])
						}
						ok = ok || dfs(nxt)
						if ok {
							return true
						}
						nxt = nxt[:len(nxt)-1]
					}
				}
			}
		}
		return ok
	}

	return dfs(nums)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function judgePoint24(cards: number[]): boolean {
    const ops: string[] = ['+', '-', '*', '/'];
    const dfs = (nums: number[]): boolean => {
        const n: number = nums.length;
        if (n === 1) {
            return Math.abs(nums[0] - 24) < 1e-6;
        }
        let ok: boolean = false;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (i !== j) {
                    const nxt: number[] = [];
                    for (let k = 0; k < n; k++) {
                        if (k !== i && k !== j) {
                            nxt.push(nums[k]);
                        }
                    }
                    for (const op of ops) {
                        switch (op) {
                            case '/':
                                if (nums[j] === 0) {
                                    continue;
                                }
                                nxt.push(nums[i] / nums[j]);
                                break;
                            case '*':
                                nxt.push(nums[i] * nums[j]);
                                break;
                            case '+':
                                nxt.push(nums[i] + nums[j]);
                                break;
                            case '-':
                                nxt.push(nums[i] - nums[j]);
                                break;
                        }
                        ok = ok || dfs(nxt);
                        if (ok) {
                            return true;
                        }
                        nxt.pop();
                    }
                }
            }
        }
        return ok;
    };

    return dfs(cards);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        fn dfs(nums: Vec<f64>) -> bool {
            let n = nums.len();
            if n == 1 {
                return (nums[0] - 24.0).abs() < 1e-6;
            }
            for i in 0..n {
                for j in 0..n {
                    if i == j {
                        continue;
                    }
                    let mut nxt = Vec::new();
                    for k in 0..n {
                        if k != i && k != j {
                            nxt.push(nums[k]);
                        }
                    }
                    for op in 0..4 {
                        let mut nxt2 = nxt.clone();
                        match op {
                            0 => {
                                nxt2.push(nums[i] + nums[j]);
                            }
                            1 => {
                                nxt2.push(nums[i] - nums[j]);
                            }
                            2 => {
                                nxt2.push(nums[i] * nums[j]);
                            }
                            3 => {
                                if nums[j].abs() < 1e-6 {
                                    continue;
                                }
                                nxt2.push(nums[i] / nums[j]);
                            }
                            _ => {}
                        }
                        if dfs(nxt2) {
                            return true;
                        }
                    }
                }
            }
            false
        }

        let nums: Vec<f64> = cards.into_iter().map(|x| x as f64).collect();
        dfs(nums)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为4的整数数组&nbsp;<code>cards</code>&nbsp;。你有 <code>4</code> 张卡片，每张卡片上都包含一个范围在 <code>[1,9]</code> 的数字。您应该使用运算符&nbsp;<code>['+', '-', '*', '/']</code>&nbsp;和括号&nbsp;<code>'('</code>&nbsp;和&nbsp;<code>')'</code>&nbsp;将这些卡片上的数字排列成数学表达式，以获得值24。</p>

<p>你须遵守以下规则:</p>

<ul>
	<li>除法运算符 <code>'/'</code> 表示实数除法，而不是整数除法。

    <ul>
    	<li>例如，&nbsp;<code>4 /(1 - 2 / 3)= 4 /(1 / 3)= 12</code>&nbsp;。</li>
    </ul>
    </li>
    <li>每个运算都在两个数字之间。特别是，不能使用 <code>“-”</code> 作为一元运算符。
    <ul>
    	<li>例如，如果 <code>cards =[1,1,1,1]</code> ，则表达式 <code>“-1 -1 -1 -1”</code> 是 <strong>不允许</strong> 的。</li>
    </ul>
    </li>
    <li>你不能把数字串在一起
    <ul>
    	<li>例如，如果 <code>cards =[1,2,1,2]</code> ，则表达式 <code>“12 + 12”</code> 无效。</li>
    </ul>
    </li>

</ul>

<p>如果可以得到这样的表达式，其计算结果为 <code>24</code> ，则返回 <code>true </code>，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> cards = [4, 1, 8, 7]
<strong>输出:</strong> true
<strong>解释:</strong> (8-4) * (7-1) = 24
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> cards = [1, 2, 1, 2]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>cards.length == 4</code></li>
	<li><code>1 &lt;= cards[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(nums)$，其中 $nums$ 表示当前的数字序列，函数返回一个布尔值，表示是否存在一种排列方式，使得这个数字序列可以得到 $24$。

如果 $nums$ 的长度为 $1$，那么只有当这个数字等于 $24$ 时，我们才返回 $true$，否则返回 $false$。

否则，我们可以枚举 $nums$ 中的任意两个数 $a$ 和 $b$ 作为左右两个操作数，枚举 $a$ 和 $b$ 之间的运算符 $op$，那么 $a\ op\ b$ 的结果就可以作为新的数字序列的一个元素，我们将其加入到新的数字序列中，并从 $nums$ 中移除 $a$ 和 $b$，然后递归地调用 $dfs$ 函数，如果返回 $true$，那么我们就找到了一种排列方式，使得这个数字序列可以得到 $24$，我们就返回 $true$。

如果枚举完所有的情况都没有返回 $true$，那么我们就返回 $false$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        def dfs(nums: List[float]):
            n = len(nums)
            if n == 1:
                if abs(nums[0] - 24) < 1e-6:
                    return True
                return False
            ok = False
            for i in range(n):
                for j in range(n):
                    if i != j:
                        nxt = [nums[k] for k in range(n) if k != i and k != j]
                        for op in ops:
                            match op:
                                case "/":
                                    if nums[j] == 0:
                                        continue
                                    ok |= dfs(nxt + [nums[i] / nums[j]])
                                case "*":
                                    ok |= dfs(nxt + [nums[i] * nums[j]])
                                case "+":
                                    ok |= dfs(nxt + [nums[i] + nums[j]])
                                case "-":
                                    ok |= dfs(nxt + [nums[i] - nums[j]])
                            if ok:
                                return True
            return ok

        ops = ("+", "-", "*", "/")
        nums = [float(x) for x in cards]
        return dfs(nums)
```

#### Java

```java
class Solution {
    private final char[] ops = {'+', '-', '*', '/'};

    public boolean judgePoint24(int[] cards) {
        List<Double> nums = new ArrayList<>();
        for (int num : cards) {
            nums.add((double) num);
        }
        return dfs(nums);
    }

    private boolean dfs(List<Double> nums) {
        int n = nums.size();
        if (n == 1) {
            return Math.abs(nums.get(0) - 24) < 1e-6;
        }
        boolean ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    List<Double> nxt = new ArrayList<>();
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            nxt.add(nums.get(k));
                        }
                    }
                    for (char op : ops) {
                        switch (op) {
                            case '/' -> {
                                if (nums.get(j) == 0) {
                                    continue;
                                }
                                nxt.add(nums.get(i) / nums.get(j));
                            }
                            case '*' -> {
                                nxt.add(nums.get(i) * nums.get(j));
                            }
                            case '+' -> {
                                nxt.add(nums.get(i) + nums.get(j));
                            }
                            case '-' -> {
                                nxt.add(nums.get(i) - nums.get(j));
                            }
                        }
                        ok |= dfs(nxt);
                        if (ok) {
                            return true;
                        }
                        nxt.remove(nxt.size() - 1);
                    }
                }
            }
        }
        return ok;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int num : cards) {
            nums.push_back(static_cast<double>(num));
        }
        return dfs(nums);
    }

private:
    const char ops[4] = {'+', '-', '*', '/'};

    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return abs(nums[0] - 24) < 1e-6;
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    vector<double> nxt;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            nxt.push_back(nums[k]);
                        }
                    }
                    for (char op : ops) {
                        switch (op) {
                        case '/':
                            if (nums[j] == 0) {
                                continue;
                            }
                            nxt.push_back(nums[i] / nums[j]);
                            break;
                        case '*':
                            nxt.push_back(nums[i] * nums[j]);
                            break;
                        case '+':
                            nxt.push_back(nums[i] + nums[j]);
                            break;
                        case '-':
                            nxt.push_back(nums[i] - nums[j]);
                            break;
                        }
                        ok |= dfs(nxt);
                        if (ok) {
                            return true;
                        }
                        nxt.pop_back();
                    }
                }
            }
        }
        return ok;
    }
};
```

#### Go

```go
func judgePoint24(cards []int) bool {
	ops := [4]rune{'+', '-', '*', '/'}
	nums := make([]float64, len(cards))
	for i, num := range cards {
		nums[i] = float64(num)
	}
	var dfs func([]float64) bool
	dfs = func(nums []float64) bool {
		n := len(nums)
		if n == 1 {
			return math.Abs(nums[0]-24) < 1e-6
		}
		ok := false
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i != j {
					var nxt []float64
					for k := 0; k < n; k++ {
						if k != i && k != j {
							nxt = append(nxt, nums[k])
						}
					}
					for _, op := range ops {
						switch op {
						case '/':
							if nums[j] == 0 {
								continue
							}
							nxt = append(nxt, nums[i]/nums[j])
						case '*':
							nxt = append(nxt, nums[i]*nums[j])
						case '+':
							nxt = append(nxt, nums[i]+nums[j])
						case '-':
							nxt = append(nxt, nums[i]-nums[j])
						}
						ok = ok || dfs(nxt)
						if ok {
							return true
						}
						nxt = nxt[:len(nxt)-1]
					}
				}
			}
		}
		return ok
	}

	return dfs(nums)
}
```

#### TypeScript

```ts
function judgePoint24(cards: number[]): boolean {
    const ops: string[] = ['+', '-', '*', '/'];
    const dfs = (nums: number[]): boolean => {
        const n: number = nums.length;
        if (n === 1) {
            return Math.abs(nums[0] - 24) < 1e-6;
        }
        let ok: boolean = false;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (i !== j) {
                    const nxt: number[] = [];
                    for (let k = 0; k < n; k++) {
                        if (k !== i && k !== j) {
                            nxt.push(nums[k]);
                        }
                    }
                    for (const op of ops) {
                        switch (op) {
                            case '/':
                                if (nums[j] === 0) {
                                    continue;
                                }
                                nxt.push(nums[i] / nums[j]);
                                break;
                            case '*':
                                nxt.push(nums[i] * nums[j]);
                                break;
                            case '+':
                                nxt.push(nums[i] + nums[j]);
                                break;
                            case '-':
                                nxt.push(nums[i] - nums[j]);
                                break;
                        }
                        ok = ok || dfs(nxt);
                        if (ok) {
                            return true;
                        }
                        nxt.pop();
                    }
                }
            }
        }
        return ok;
    };

    return dfs(cards);
}
```

#### Rust

```rust
impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        fn dfs(nums: Vec<f64>) -> bool {
            let n = nums.len();
            if n == 1 {
                return (nums[0] - 24.0).abs() < 1e-6;
            }
            for i in 0..n {
                for j in 0..n {
                    if i == j {
                        continue;
                    }
                    let mut nxt = Vec::new();
                    for k in 0..n {
                        if k != i && k != j {
                            nxt.push(nums[k]);
                        }
                    }
                    for op in 0..4 {
                        let mut nxt2 = nxt.clone();
                        match op {
                            0 => {
                                nxt2.push(nums[i] + nums[j]);
                            }
                            1 => {
                                nxt2.push(nums[i] - nums[j]);
                            }
                            2 => {
                                nxt2.push(nums[i] * nums[j]);
                            }
                            3 => {
                                if nums[j].abs() < 1e-6 {
                                    continue;
                                }
                                nxt2.push(nums[i] / nums[j]);
                            }
                            _ => {}
                        }
                        if dfs(nxt2) {
                            return true;
                        }
                    }
                }
            }
            false
        }

        let nums: Vec<f64> = cards.into_iter().map(|x| x as f64).collect();
        dfs(nums)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
