---
title: "1430_判断给定的序列是否是二叉树从根到叶的路径 🔒"
date: 2025-10-08T18:37:18+08:00
weight: 4
tags: [二分查找, 二叉树, 位运算, 动态规划, 单调队列, 哈希表, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 有序集合, 树, 深度优先搜索, 滑动窗口, 状态压缩, 矩阵, 贪心, 队列]
---

{{< markmap >}}
### [1430_判断给定的序列是否是二叉树从根到叶的路径 🔒](#1430)
#### [树](#1430)
#### [深度优先搜索](#1430)
#### [广度优先搜索](#1430)
#### [二叉树](#1430)
### [1431_拥有最多糖果的孩子](#1431)
#### [数组](#1431)
### [1432_改变一个整数能得到的最大差值](#1432)
#### [贪心](#1432)
#### [数学](#1432)
### [1433_检查一个字符串是否可以打破另一个字符串](#1433)
#### [贪心](#1433)
#### [字符串](#1433)
#### [排序](#1433)
### [1434_每个人戴不同帽子的方案数](#1434)
#### [位运算](#1434)
#### [数组](#1434)
#### [动态规划](#1434)
#### [状态压缩](#1434)
### [1435_制作会话柱状图 🔒](#1435)
#### [数据库](#1435)
### [1436_旅行终点站](#1436)
#### [数组](#1436)
#### [哈希表](#1436)
#### [字符串](#1436)
### [1437_是否所有 1 都至少相隔 k 个元素](#1437)
#### [数组](#1437)
### [1438_绝对差不超过限制的最长连续子数组](#1438)
#### [队列](#1438)
#### [数组](#1438)
#### [有序集合](#1438)
#### [滑动窗口](#1438)
#### [单调队列](#1438)
#### [堆（优先队列）](#1438)
### [1439_有序矩阵中的第 k 个最小数组和](#1439)
#### [数组](#1439)
#### [二分查找](#1439)
#### [矩阵](#1439)
#### [堆（优先队列）](#1439)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1430_判断给定的序列是否是二叉树从根到叶的路径 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 1431_拥有最多糖果的孩子
___
#### 数组
---
### 1432_改变一个整数能得到的最大差值
___
#### 贪心
___
#### 数学
---
### 1433_检查一个字符串是否可以打破另一个字符串
___
#### 贪心
___
#### 字符串
___
#### 排序
---
### 1434_每个人戴不同帽子的方案数
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 1435_制作会话柱状图 🔒
___
#### 数据库
---
### 1436_旅行终点站
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1437_是否所有 1 都至少相隔 k 个元素
___
#### 数组
---
### 1438_绝对差不超过限制的最长连续子数组
___
#### 队列
___
#### 数组
___
#### 有序集合
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
---
### 1439_有序矩阵中的第 k 个最小数组和
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 动态规划 | 单调队列 | 哈希表 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 有序集合 | 树 |
| 深度优先搜索 | 滑动窗口 | 状态压缩 |
| 矩阵 | 贪心 | 队列 |

# [1430. 判断给定的序列是否是二叉树从根到叶的路径 🔒](https://leetcode.cn/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree){#1430}

{{< tabs "1430" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        def dfs(root, u):
            if root is None or root.val != arr[u]:
                return False
            if u == len(arr) - 1:
                return root.left is None and root.right is None
            return dfs(root.left, u + 1) or dfs(root.right, u + 1)

        return dfs(root, 0)
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
    private int[] arr;

    public boolean isValidSequence(TreeNode root, int[] arr) {
        this.arr = arr;
        return dfs(root, 0);
    }

    private boolean dfs(TreeNode root, int u) {
        if (root == null || root.val != arr[u]) {
            return false;
        }
        if (u == arr.length - 1) {
            return root.left == null && root.right == null;
        }
        return dfs(root.left, u + 1) || dfs(root.right, u + 1);
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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* root, int u) -> bool {
            if (!root || root->val != arr[u]) return false;
            if (u == arr.size() - 1) return !root->left && !root->right;
            return dfs(root->left, u + 1) || dfs(root->right, u + 1);
        };
        return dfs(root, 0);
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
func isValidSequence(root *TreeNode, arr []int) bool {
	var dfs func(root *TreeNode, u int) bool
	dfs = func(root *TreeNode, u int) bool {
		if root == nil || root.Val != arr[u] {
			return false
		}
		if u == len(arr)-1 {
			return root.Left == nil && root.Right == nil
		}
		return dfs(root.Left, u+1) || dfs(root.Right, u+1)
	}
	return dfs(root, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树，我们称从根节点到任意叶节点的任意路径中的节点值所构成的序列为该二叉树的一个 &ldquo;<strong>有效序列</strong>&rdquo; 。检查一个给定的序列是否是给定二叉树的一个 &ldquo;<strong>有效序列</strong>&rdquo; 。</p>

<p>我们以整数数组 <code>arr</code> 的形式给出这个序列。从根节点到任意叶节点的任意路径中的节点值所构成的序列都是这个二叉树的 &ldquo;<strong>有效序列</strong>&rdquo; 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1430.Check%20If%20a%20String%20Is%20a%20Valid%20Sequence%20from%20Root%20to%20Leaves%20Path%20in%20a%20Binary%20Tree/images/leetcode_testcase_1.png" style="height:250px; width:333px" /></strong></p>

<pre>
<strong>输入：</strong>root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
<strong>输出：</strong>true
<strong>解释：
</strong>路径 0 -&gt; 1 -&gt; 0 -&gt; 1 是一个&ldquo;有效序列&rdquo;（图中的绿色节点）。
其他的&ldquo;有效序列&rdquo;是：
0 -&gt; 1 -&gt; 1 -&gt; 0 
0 -&gt; 0 -&gt; 0
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1430.Check%20If%20a%20String%20Is%20a%20Valid%20Sequence%20from%20Root%20to%20Leaves%20Path%20in%20a%20Binary%20Tree/images/leetcode_testcase_2.png" style="height:250px; width:333px" /></strong></p>

<pre>
<strong>输入：</strong>root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
<strong>输出：</strong>false 
<strong>解释：</strong>路径 0 -&gt; 0 -&gt; 1 不存在，所以这不是一个&ldquo;序列&rdquo;。
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1430.Check%20If%20a%20String%20Is%20a%20Valid%20Sequence%20from%20Root%20to%20Leaves%20Path%20in%20a%20Binary%20Tree/images/leetcode_testcase_3.png" style="height:250px; width:333px" /></strong></p>

<pre>
<strong>输入：</strong>root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
<strong>输出：</strong>false
<strong>解释：</strong>路径 0 -&gt; 1 -&gt; 1 是一个序列，但不是一个&ldquo;有效序列&rdquo;（译者注：因为序列的终点不是叶节点）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 9</code></li>
	<li>每个节点的值的取值范围是 <code>[0 - 9]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

根据题目，我们设计一个递归函数 $dfs(root, u)$，表示从当前节点 $root$ 开始，且当前已经遍历到数组的第 $u$ 个元素，是否存在一条从根节点到叶子节点的路径，且路径上的元素与数组中的元素一一对应。那么答案就是 $dfs(root, 0)$。

在递归函数中，如果当前节点为空，或者当前节点的值与数组中的值不相等，那么直接返回 $false$。如果当前节点是叶子节点，且当前节点的值与数组中的值相等，那么返回 $u$ 是否等于数组的长度减 $1$。否则，返回 $dfs(root.left, u + 1)$ 或者 $dfs(root.right, u + 1)$。

时间复杂度 $O(n)$，空间复杂度 $O(\log n)$。其中 $n$ 是二叉树的节点个数。

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
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        def dfs(root, u):
            if root is None or root.val != arr[u]:
                return False
            if u == len(arr) - 1:
                return root.left is None and root.right is None
            return dfs(root.left, u + 1) or dfs(root.right, u + 1)

        return dfs(root, 0)
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
    private int[] arr;

    public boolean isValidSequence(TreeNode root, int[] arr) {
        this.arr = arr;
        return dfs(root, 0);
    }

    private boolean dfs(TreeNode root, int u) {
        if (root == null || root.val != arr[u]) {
            return false;
        }
        if (u == arr.length - 1) {
            return root.left == null && root.right == null;
        }
        return dfs(root.left, u + 1) || dfs(root.right, u + 1);
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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* root, int u) -> bool {
            if (!root || root->val != arr[u]) return false;
            if (u == arr.size() - 1) return !root->left && !root->right;
            return dfs(root->left, u + 1) || dfs(root->right, u + 1);
        };
        return dfs(root, 0);
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
func isValidSequence(root *TreeNode, arr []int) bool {
	var dfs func(root *TreeNode, u int) bool
	dfs = func(root *TreeNode, u int) bool {
		if root == nil || root.Val != arr[u] {
			return false
		}
		if u == len(arr)-1 {
			return root.Left == nil && root.Right == nil
		}
		return dfs(root.Left, u+1) || dfs(root.Right, u+1)
	}
	return dfs(root, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1431. 拥有最多糖果的孩子](https://leetcode.cn/problems/kids-with-the-greatest-number-of-candies){#1431}

{{< tabs "1431" >}}

{{% tab "python" %}}
```python
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies)
        return [candy + extraCandies >= mx for candy in candies]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int mx = 0;
        for (int candy : candies) {
            mx = Math.max(mx, candy);
        }
        List<Boolean> res = new ArrayList<>();
        for (int candy : candies) {
            res.add(candy + extraCandies >= mx);
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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int candy : candies) {
            res.push_back(candy + extraCandies >= mx);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kidsWithCandies(candies []int, extraCandies int) (ans []bool) {
	mx := slices.Max(candies)
	for _, candy := range candies {
		ans = append(ans, candy+extraCandies >= mx)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    const max = candies.reduce((r, v) => Math.max(r, v));
    return candies.map(v => v + extraCandies >= max);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let max = *candies.iter().max().unwrap();
        candies.iter().map(|v| v + extra_candies >= max).collect()
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $candies
     * @param Integer $extraCandies
     * @return Boolean[]
     */
    function kidsWithCandies($candies, $extraCandies) {
        $max = max($candies);
        $rs = [];
        for ($i = 0; $i < count($candies); $i++) {
            array_push($rs, $candies[$i] + $extraCandies >= $max);
        }
        return $rs;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int mx = 0;
    for (int i = 0; i < candiesSize; i++) {
        mx = max(mx, candies[i]);
    }
    bool* ans = malloc(candiesSize * sizeof(bool));
    for (int i = 0; i < candiesSize; i++) {
        ans[i] = candies[i] + extraCandies >= mx;
    }
    *returnSize = candiesSize;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有&nbsp;<code>n</code>&nbsp;个有糖果的孩子。给你一个数组&nbsp;<code>candies</code>，其中&nbsp;<code>candies[i]</code>&nbsp;代表第 <code>i</code> 个孩子拥有的糖果数目，和一个整数&nbsp;<code>extraCandies</code>&nbsp;表示你所有的额外糖果的数量。</p>

<p>返回一个长度为&nbsp;<code>n</code>&nbsp;的布尔数组 <code>result</code>，如果把所有的&nbsp;<code>extraCandies</code>&nbsp;给第&nbsp;<code>i</code>&nbsp;个孩子之后，他会拥有所有孩子中&nbsp;<strong>最多&nbsp;</strong>的糖果，那么&nbsp;<code>result[i]</code>&nbsp;为&nbsp;<code>true</code>，否则为 <code>false</code>。</p>

<p>注意，允许有多个孩子同时拥有 <strong>最多</strong>&nbsp;的糖果数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candies = [2,3,5,1,3], extraCandies = 3
<strong>输出：</strong>[true,true,true,false,true] 
<strong>解释：</strong>如果你把额外的糖果全部给：
孩子 1，将有 2 + 3 = 5 个糖果，是孩子中最多的。
孩子 2，将有 3 + 3 = 6 个糖果，是孩子中最多的。
孩子 3，将有 5 + 3 = 8 个糖果，是孩子中最多的。
孩子 4，将有 1 + 3 = 4 个糖果，不是孩子中最多的。
孩子 5，将有 3 + 3 = 6 个糖果，是孩子中最多的。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candies = [4,2,1,1,2], extraCandies = 1
<strong>输出：</strong>[true,false,false,false,false] 
<strong>解释：</strong>只有 1 个额外糖果，所以不管额外糖果给谁，只有孩子 1 可以成为拥有糖果最多的孩子。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>candies = [12,1,12], extraCandies = 10
<strong>输出：</strong>[true,false,true]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == candies.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= candies[i] &lt;= 100</code></li>
	<li><code>1 &lt;= extraCandies &lt;= 50</code></li>
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
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies)
        return [candy + extraCandies >= mx for candy in candies]
```

#### Java

```java
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int mx = 0;
        for (int candy : candies) {
            mx = Math.max(mx, candy);
        }
        List<Boolean> res = new ArrayList<>();
        for (int candy : candies) {
            res.add(candy + extraCandies >= mx);
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int candy : candies) {
            res.push_back(candy + extraCandies >= mx);
        }
        return res;
    }
};
```

#### Go

```go
func kidsWithCandies(candies []int, extraCandies int) (ans []bool) {
	mx := slices.Max(candies)
	for _, candy := range candies {
		ans = append(ans, candy+extraCandies >= mx)
	}
	return
}
```

#### TypeScript

```ts
function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    const max = candies.reduce((r, v) => Math.max(r, v));
    return candies.map(v => v + extraCandies >= max);
}
```

#### Rust

```rust
impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let max = *candies.iter().max().unwrap();
        candies.iter().map(|v| v + extra_candies >= max).collect()
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $candies
     * @param Integer $extraCandies
     * @return Boolean[]
     */
    function kidsWithCandies($candies, $extraCandies) {
        $max = max($candies);
        $rs = [];
        for ($i = 0; $i < count($candies); $i++) {
            array_push($rs, $candies[$i] + $extraCandies >= $max);
        }
        return $rs;
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int mx = 0;
    for (int i = 0; i < candiesSize; i++) {
        mx = max(mx, candies[i]);
    }
    bool* ans = malloc(candiesSize * sizeof(bool));
    for (int i = 0; i < candiesSize; i++) {
        ans[i] = candies[i] + extraCandies >= mx;
    }
    *returnSize = candiesSize;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1432. 改变一个整数能得到的最大差值](https://leetcode.cn/problems/max-difference-you-can-get-from-changing-an-integer){#1432}

{{< tabs "1432" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDiff(self, num: int) -> int:
        a, b = str(num), str(num)
        for c in a:
            if c != "9":
                a = a.replace(c, "9")
                break
        if b[0] != "1":
            b = b.replace(b[0], "1")
        else:
            for c in b[1:]:
                if c not in "01":
                    b = b.replace(c, "0")
                    break
        return int(a) - int(b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDiff(int num) {
        String a = String.valueOf(num);
        String b = a;
        for (int i = 0; i < a.length(); ++i) {
            if (a.charAt(i) != '9') {
                a = a.replace(a.charAt(i), '9');
                break;
            }
        }
        if (b.charAt(0) != '1') {
            b = b.replace(b.charAt(0), '1');
        } else {
            for (int i = 1; i < b.length(); ++i) {
                if (b.charAt(i) != '0' && b.charAt(i) != '1') {
                    b = b.replace(b.charAt(i), '0');
                    break;
                }
            }
        }
        return Integer.parseInt(a) - Integer.parseInt(b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char a, char b) {
            for (auto& c : s) {
                if (c == a) {
                    c = b;
                }
            }
        };
        string a = to_string(num);
        string b = a;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != '9') {
                replace(a, a[i], '9');
                break;
            }
        }
        if (b[0] != '1') {
            replace(b, b[0], '1');
        } else {
            for (int i = 1; i < b.size(); ++i) {
                if (b[i] != '0' && b[i] != '1') {
                    replace(b, b[i], '0');
                    break;
                }
            }
        }
        return stoi(a) - stoi(b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDiff(num int) int {
	a, b := num, num
	s := strconv.Itoa(num)
	for i := range s {
		if s[i] != '9' {
			a, _ = strconv.Atoi(strings.ReplaceAll(s, string(s[i]), "9"))
			break
		}
	}
	if s[0] > '1' {
		b, _ = strconv.Atoi(strings.ReplaceAll(s, string(s[0]), "1"))
	} else {
		for i := 1; i < len(s); i++ {
			if s[i] != '0' && s[i] != '1' {
				b, _ = strconv.Atoi(strings.ReplaceAll(s, string(s[i]), "0"))
				break
			}
		}
	}
	return a - b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDiff(num: number): number {
    let a = num.toString();
    let b = a;
    for (let i = 0; i < a.length; ++i) {
        if (a[i] !== '9') {
            a = a.split(a[i]).join('9');
            break;
        }
    }
    if (b[0] !== '1') {
        b = b.split(b[0]).join('1');
    } else {
        for (let i = 1; i < b.length; ++i) {
            if (b[i] !== '0' && b[i] !== '1') {
                b = b.split(b[i]).join('0');
                break;
            }
        }
    }
    return +a - +b;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let a = num.to_string();
        let mut a = a.clone();
        let mut b = a.clone();

        for c in a.chars() {
            if c != '9' {
                a = a.replace(c, "9");
                break;
            }
        }

        let chars: Vec<char> = b.chars().collect();
        if chars[0] != '1' {
            b = b.replace(chars[0], "1");
        } else {
            for &c in &chars[1..] {
                if c != '0' && c != '1' {
                    b = b.replace(c, "0");
                    break;
                }
            }
        }

        a.parse::<i32>().unwrap() - b.parse::<i32>().unwrap()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>num</code>&nbsp;。你可以对它进行以下步骤共计&nbsp;<strong>两次</strong>：</p>

<ul>
	<li>选择一个数字&nbsp;<code>x (0&nbsp;&lt;= x &lt;= 9)</code>.</li>
	<li>选择另一个数字&nbsp;<code>y (0&nbsp;&lt;= y &lt;= 9)</code>&nbsp;。数字&nbsp;<code>y</code>&nbsp;可以等于&nbsp;<code>x</code>&nbsp;。</li>
	<li>将 <code>num</code>&nbsp;中所有出现 <code>x</code>&nbsp;的数位都用 <code>y</code>&nbsp;替换。</li>
</ul>

<p>令两次对 <code>num</code>&nbsp;的操作得到的结果分别为&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;。</p>

<p>请你返回&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;的 <strong>最大差值</strong> 。</p>

<p>注意，<code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;<strong>必须不能</strong> 含有前导 0，并且 <strong>不为</strong> 0。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 555
<strong>输出：</strong>888
<strong>解释：</strong>第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 999 和 b = 111 ，最大差值为 888
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 9
<strong>输出：</strong>8
<strong>解释：</strong>第一次选择 x = 9 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 9 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 9 和 b = 1 ，最大差值为 8
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = 123456
<strong>输出：</strong>820000
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>num = 10000
<strong>输出：</strong>80000
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>num = 9288
<strong>输出：</strong>8700
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

要想得到最大差值，那么我们应该拿到最大值与最小值，这样差值最大。

因此，我们先从高到低枚举 $\textit{nums}$ 每个位置上的数，如果数字不为 `9`，就将所有该数字替换为 `9`，得到最大整数 $a$。

接下来，我们再从高到低枚举 $\textit{nums}$ 每个位置上的数，首位不能为 `0`，因此如果首位不为 `1`，我们将其替换为 `1`；如果非首位，且数字不与首位相同，我们将其替换为 `0`，得到最大整数 $b$。

答案为差值 $a - b$。

时间复杂度 $O(\log \textit{num})$，空间复杂度 $O(\log \textit{num})$。其中 $\textit{nums}$ 为给定整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDiff(self, num: int) -> int:
        a, b = str(num), str(num)
        for c in a:
            if c != "9":
                a = a.replace(c, "9")
                break
        if b[0] != "1":
            b = b.replace(b[0], "1")
        else:
            for c in b[1:]:
                if c not in "01":
                    b = b.replace(c, "0")
                    break
        return int(a) - int(b)
```

#### Java

```java
class Solution {
    public int maxDiff(int num) {
        String a = String.valueOf(num);
        String b = a;
        for (int i = 0; i < a.length(); ++i) {
            if (a.charAt(i) != '9') {
                a = a.replace(a.charAt(i), '9');
                break;
            }
        }
        if (b.charAt(0) != '1') {
            b = b.replace(b.charAt(0), '1');
        } else {
            for (int i = 1; i < b.length(); ++i) {
                if (b.charAt(i) != '0' && b.charAt(i) != '1') {
                    b = b.replace(b.charAt(i), '0');
                    break;
                }
            }
        }
        return Integer.parseInt(a) - Integer.parseInt(b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char a, char b) {
            for (auto& c : s) {
                if (c == a) {
                    c = b;
                }
            }
        };
        string a = to_string(num);
        string b = a;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != '9') {
                replace(a, a[i], '9');
                break;
            }
        }
        if (b[0] != '1') {
            replace(b, b[0], '1');
        } else {
            for (int i = 1; i < b.size(); ++i) {
                if (b[i] != '0' && b[i] != '1') {
                    replace(b, b[i], '0');
                    break;
                }
            }
        }
        return stoi(a) - stoi(b);
    }
};
```

#### Go

```go
func maxDiff(num int) int {
	a, b := num, num
	s := strconv.Itoa(num)
	for i := range s {
		if s[i] != '9' {
			a, _ = strconv.Atoi(strings.ReplaceAll(s, string(s[i]), "9"))
			break
		}
	}
	if s[0] > '1' {
		b, _ = strconv.Atoi(strings.ReplaceAll(s, string(s[0]), "1"))
	} else {
		for i := 1; i < len(s); i++ {
			if s[i] != '0' && s[i] != '1' {
				b, _ = strconv.Atoi(strings.ReplaceAll(s, string(s[i]), "0"))
				break
			}
		}
	}
	return a - b
}
```

#### TypeScript

```ts
function maxDiff(num: number): number {
    let a = num.toString();
    let b = a;
    for (let i = 0; i < a.length; ++i) {
        if (a[i] !== '9') {
            a = a.split(a[i]).join('9');
            break;
        }
    }
    if (b[0] !== '1') {
        b = b.split(b[0]).join('1');
    } else {
        for (let i = 1; i < b.length; ++i) {
            if (b[i] !== '0' && b[i] !== '1') {
                b = b.split(b[i]).join('0');
                break;
            }
        }
    }
    return +a - +b;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let a = num.to_string();
        let mut a = a.clone();
        let mut b = a.clone();

        for c in a.chars() {
            if c != '9' {
                a = a.replace(c, "9");
                break;
            }
        }

        let chars: Vec<char> = b.chars().collect();
        if chars[0] != '1' {
            b = b.replace(chars[0], "1");
        } else {
            for &c in &chars[1..] {
                if c != '0' && c != '1' {
                    b = b.replace(c, "0");
                    break;
                }
            }
        }

        a.parse::<i32>().unwrap() - b.parse::<i32>().unwrap()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1433. 检查一个字符串是否可以打破另一个字符串](https://leetcode.cn/problems/check-if-a-string-can-break-another-string){#1433}

{{< tabs "1433" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        cs1 = sorted(s1)
        cs2 = sorted(s2)
        return all(a >= b for a, b in zip(cs1, cs2)) or all(
            a <= b for a, b in zip(cs1, cs2)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        char[] cs1 = s1.toCharArray();
        char[] cs2 = s2.toCharArray();
        Arrays.sort(cs1);
        Arrays.sort(cs2);
        return check(cs1, cs2) || check(cs2, cs1);
    }

    private boolean check(char[] cs1, char[] cs2) {
        for (int i = 0; i < cs1.length; ++i) {
            if (cs1[i] < cs2[i]) {
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
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return check(s1, s2) || check(s2, s1);
    }

    bool check(string& s1, string& s2) {
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] < s2[i]) {
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
func checkIfCanBreak(s1 string, s2 string) bool {
	cs1 := []byte(s1)
	cs2 := []byte(s2)
	sort.Slice(cs1, func(i, j int) bool { return cs1[i] < cs1[j] })
	sort.Slice(cs2, func(i, j int) bool { return cs2[i] < cs2[j] })
	check := func(cs1, cs2 []byte) bool {
		for i := range cs1 {
			if cs1[i] < cs2[i] {
				return false
			}
		}
		return true
	}
	return check(cs1, cs2) || check(cs2, cs1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkIfCanBreak(s1: string, s2: string): boolean {
    const cs1: string[] = Array.from(s1);
    const cs2: string[] = Array.from(s2);
    cs1.sort();
    cs2.sort();
    const check = (cs1: string[], cs2: string[]) => {
        for (let i = 0; i < cs1.length; i++) {
            if (cs1[i] < cs2[i]) {
                return false;
            }
        }
        return true;
    };
    return check(cs1, cs2) || check(cs2, cs1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;，它们长度相等，请你检查是否存在一个&nbsp;<code>s1</code>&nbsp; 的排列可以打破 <code>s2</code>&nbsp;的一个排列，或者是否存在一个&nbsp;<code>s2</code>&nbsp;的排列可以打破 <code>s1</code> 的一个排列。</p>

<p>字符串&nbsp;<code>x</code>&nbsp;可以打破字符串&nbsp;<code>y</code>&nbsp;（两者长度都为&nbsp;<code>n</code>&nbsp;）需满足对于所有&nbsp;<code>i</code>（在&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;之间）都有&nbsp;<code>x[i] &gt;= y[i]</code>（字典序意义下的顺序）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s1 = &quot;abc&quot;, s2 = &quot;xya&quot;
<strong>输出：</strong>true
<strong>解释：</strong>&quot;ayx&quot; 是 s2=&quot;xya&quot; 的一个排列，&quot;abc&quot; 是字符串 s1=&quot;abc&quot; 的一个排列，且 &quot;ayx&quot; 可以打破 &quot;abc&quot; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s1 = &quot;abe&quot;, s2 = &quot;acd&quot;
<strong>输出：</strong>false 
<strong>解释：</strong>s1=&quot;abe&quot; 的所有排列包括：&quot;abe&quot;，&quot;aeb&quot;，&quot;bae&quot;，&quot;bea&quot;，&quot;eab&quot; 和 &quot;eba&quot; ，s2=&quot;acd&quot; 的所有排列包括：&quot;acd&quot;，&quot;adc&quot;，&quot;cad&quot;，&quot;cda&quot;，&quot;dac&quot; 和 &quot;dca&quot;。然而没有任何 s1 的排列可以打破 s2 的排列。也没有 s2 的排列能打破 s1 的排列。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s1 = &quot;leetcodee&quot;, s2 = &quot;interview&quot;
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s1.length == n</code></li>
	<li><code>s2.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li>所有字符串都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

将字符串 $s1$, $s2$ 分别进行升序排序。然后同时遍历两个字符串，对应字符进行大小比较。若对于任意 $i∈[0, n)，都有 $s1[i] \le s2[i]$，或者都有 $s1[i] \ge s2[i]$，则存在一个排列可以打破另一个排列。

时间复杂度 $O(nlogn)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        cs1 = sorted(s1)
        cs2 = sorted(s2)
        return all(a >= b for a, b in zip(cs1, cs2)) or all(
            a <= b for a, b in zip(cs1, cs2)
        )
```

#### Java

```java
class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        char[] cs1 = s1.toCharArray();
        char[] cs2 = s2.toCharArray();
        Arrays.sort(cs1);
        Arrays.sort(cs2);
        return check(cs1, cs2) || check(cs2, cs1);
    }

    private boolean check(char[] cs1, char[] cs2) {
        for (int i = 0; i < cs1.length; ++i) {
            if (cs1[i] < cs2[i]) {
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
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return check(s1, s2) || check(s2, s1);
    }

    bool check(string& s1, string& s2) {
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] < s2[i]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkIfCanBreak(s1 string, s2 string) bool {
	cs1 := []byte(s1)
	cs2 := []byte(s2)
	sort.Slice(cs1, func(i, j int) bool { return cs1[i] < cs1[j] })
	sort.Slice(cs2, func(i, j int) bool { return cs2[i] < cs2[j] })
	check := func(cs1, cs2 []byte) bool {
		for i := range cs1 {
			if cs1[i] < cs2[i] {
				return false
			}
		}
		return true
	}
	return check(cs1, cs2) || check(cs2, cs1)
}
```

#### TypeScript

```ts
function checkIfCanBreak(s1: string, s2: string): boolean {
    const cs1: string[] = Array.from(s1);
    const cs2: string[] = Array.from(s2);
    cs1.sort();
    cs2.sort();
    const check = (cs1: string[], cs2: string[]) => {
        for (let i = 0; i < cs1.length; i++) {
            if (cs1[i] < cs2[i]) {
                return false;
            }
        }
        return true;
    };
    return check(cs1, cs2) || check(cs2, cs1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1434. 每个人戴不同帽子的方案数](https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other){#1434}

{{< tabs "1434" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        g = defaultdict(list)
        for i, h in enumerate(hats):
            for v in h:
                g[v].append(i)
        mod = 10**9 + 7
        n = len(hats)
        m = max(max(h) for h in hats)
        f = [[0] * (1 << n) for _ in range(m + 1)]
        f[0][0] = 1
        for i in range(1, m + 1):
            for j in range(1 << n):
                f[i][j] = f[i - 1][j]
                for k in g[i]:
                    if j >> k & 1:
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod
        return f[m][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        int m = 0;
        for (var h : hats) {
            for (int v : h) {
                m = Math.max(m, v);
            }
        }
        List<Integer>[] g = new List[m + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            for (int v : hats.get(i)) {
                g[v].add(i);
            }
        }
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[m + 1][1 << n];
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k : g[i]) {
                    if ((j >> k & 1) == 1) {
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int m = 0;
        for (auto& h : hats) {
            m = max(m, *max_element(h.begin(), h.end()));
        }
        vector<vector<int>> g(m + 1);
        for (int i = 0; i < n; ++i) {
            for (int& v : hats[i]) {
                g[v].push_back(i);
            }
        }
        const int mod = 1e9 + 7;
        int f[m + 1][1 << n];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k : g[i]) {
                    if (j >> k & 1) {
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberWays(hats [][]int) int {
	n := len(hats)
	m := 0
	for _, h := range hats {
		m = max(m, slices.Max(h))
	}
	g := make([][]int, m+1)
	for i, h := range hats {
		for _, v := range h {
			g[v] = append(g[v], i)
		}
	}
	const mod = 1e9 + 7
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, 1<<n)
	}
	f[0][0] = 1
	for i := 1; i <= m; i++ {
		for j := 0; j < 1<<n; j++ {
			f[i][j] = f[i-1][j]
			for _, k := range g[i] {
				if j>>k&1 == 1 {
					f[i][j] = (f[i][j] + f[i-1][j^(1<<k)]) % mod
				}
			}
		}
	}
	return f[m][(1<<n)-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberWays(hats: number[][]): number {
    const n = hats.length;
    const m = Math.max(...hats.flat());
    const g: number[][] = Array.from({ length: m + 1 }, () => []);
    for (let i = 0; i < n; ++i) {
        for (const v of hats[i]) {
            g[v].push(i);
        }
    }
    const f: number[][] = Array.from({ length: m + 1 }, () =>
        Array.from({ length: 1 << n }, () => 0),
    );
    f[0][0] = 1;
    const mod = 1e9 + 7;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j < 1 << n; ++j) {
            f[i][j] = f[i - 1][j];
            for (const k of g[i]) {
                if (((j >> k) & 1) === 1) {
                    f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                }
            }
        }
    }
    return f[m][(1 << n) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>总共有 <code>n</code>&nbsp;个人和 <code>40</code> 种不同的帽子，帽子编号从 <code>1</code> 到 <code>40</code> 。</p>

<p>给你一个整数列表的列表&nbsp;<code>hats</code>&nbsp;，其中&nbsp;<code>hats[i]</code>&nbsp;是第 <code>i</code>&nbsp;个人所有喜欢帽子的列表。</p>

<p>请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数。</p>

<p>由于答案可能很大，请返回它对&nbsp;<code>10^9 + 7</code>&nbsp;取余后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>hats = [[3,4],[4,5],[5]]
<strong>输出：</strong>1
<strong>解释：</strong>给定条件下只有一种方法选择帽子。
第一个人选择帽子 3，第二个人选择帽子 4，最后一个人选择帽子 5。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>hats = [[3,5,1],[3,5]]
<strong>输出：</strong>4
<strong>解释：</strong>总共有 4 种安排帽子的方法：
(3,5)，(5,3)，(1,3) 和 (1,5)
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
<strong>输出：</strong>24
<strong>解释：</strong>每个人都可以从编号为 1 到 4 的帽子中选。
(1,2,3,4) 4 个帽子的排列方案数为 24 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == hats.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= hats[i].length &lt;= 40</code></li>
	<li><code>1 &lt;= hats[i][j] &lt;= 40</code></li>
	<li><code>hats[i]</code>&nbsp;包含一个数字互不相同的整数列表。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们注意到 $n$ 不超过 $10$，因此我们考虑使用状态压缩动态规划的方法求解。

我们定义 $f[i][j]$ 表示在前 $i$ 个帽子中，当前被分配的人的状态为 $j$ 时的方案数。其中 $j$ 是一个二进制数，表示当前被分配的人的集合。初始时 $f[0][0]=1$，答案为 $f[m][2^n - 1]$，其中 $m$ 是帽子的最大编号，而 $n$ 是人的数量。

考虑 $f[i][j]$，如果第 $i$ 个帽子不分配给任何人，那么 $f[i][j]=f[i-1][j]$；如果第 $i$ 个帽子分配给了喜欢它的人 $k$，那么 $f[i][j]=f[i-1][j \oplus 2^k]$。这里 $\oplus$ 表示异或运算。因此我们可以得到状态转移方程：

$$
f[i][j]=f[i-1][j]+ \sum_{k \in like[i]} f[i-1][j \oplus 2^k]
$$

其中 $like[i]$ 表示喜欢第 $i$ 个帽子的人的集合。

最终的答案即为 $f[m][2^n - 1]$，注意答案可能很大，需要对 $10^9 + 7$ 取模。

时间复杂度 $O(m \times 2^n \times n)$，空间复杂度 $O(m \times 2^n)$。其中 $m$ 是帽子的最大编号，本题中 $m \leq 40$；而 $n$ 是人的数量，本题中 $n \leq 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        g = defaultdict(list)
        for i, h in enumerate(hats):
            for v in h:
                g[v].append(i)
        mod = 10**9 + 7
        n = len(hats)
        m = max(max(h) for h in hats)
        f = [[0] * (1 << n) for _ in range(m + 1)]
        f[0][0] = 1
        for i in range(1, m + 1):
            for j in range(1 << n):
                f[i][j] = f[i - 1][j]
                for k in g[i]:
                    if j >> k & 1:
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod
        return f[m][-1]
```

#### Java

```java
class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        int m = 0;
        for (var h : hats) {
            for (int v : h) {
                m = Math.max(m, v);
            }
        }
        List<Integer>[] g = new List[m + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            for (int v : hats.get(i)) {
                g[v].add(i);
            }
        }
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[m + 1][1 << n];
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k : g[i]) {
                    if ((j >> k & 1) == 1) {
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int m = 0;
        for (auto& h : hats) {
            m = max(m, *max_element(h.begin(), h.end()));
        }
        vector<vector<int>> g(m + 1);
        for (int i = 0; i < n; ++i) {
            for (int& v : hats[i]) {
                g[v].push_back(i);
            }
        }
        const int mod = 1e9 + 7;
        int f[m + 1][1 << n];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                f[i][j] = f[i - 1][j];
                for (int k : g[i]) {
                    if (j >> k & 1) {
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
};
```

#### Go

```go
func numberWays(hats [][]int) int {
	n := len(hats)
	m := 0
	for _, h := range hats {
		m = max(m, slices.Max(h))
	}
	g := make([][]int, m+1)
	for i, h := range hats {
		for _, v := range h {
			g[v] = append(g[v], i)
		}
	}
	const mod = 1e9 + 7
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, 1<<n)
	}
	f[0][0] = 1
	for i := 1; i <= m; i++ {
		for j := 0; j < 1<<n; j++ {
			f[i][j] = f[i-1][j]
			for _, k := range g[i] {
				if j>>k&1 == 1 {
					f[i][j] = (f[i][j] + f[i-1][j^(1<<k)]) % mod
				}
			}
		}
	}
	return f[m][(1<<n)-1]
}
```

#### TypeScript

```ts
function numberWays(hats: number[][]): number {
    const n = hats.length;
    const m = Math.max(...hats.flat());
    const g: number[][] = Array.from({ length: m + 1 }, () => []);
    for (let i = 0; i < n; ++i) {
        for (const v of hats[i]) {
            g[v].push(i);
        }
    }
    const f: number[][] = Array.from({ length: m + 1 }, () =>
        Array.from({ length: 1 << n }, () => 0),
    );
    f[0][0] = 1;
    const mod = 1e9 + 7;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j < 1 << n; ++j) {
            f[i][j] = f[i - 1][j];
            for (const k of g[i]) {
                if (((j >> k) & 1) === 1) {
                    f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << k)]) % mod;
                }
            }
        }
    }
    return f[m][(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1435. 制作会话柱状图 🔒](https://leetcode.cn/problems/create-a-session-bar-chart){#1435}

{{< tabs "1435" >}}

{{% tab "sql" %}}
```sql
SELECT '[0-5>' AS bin, COUNT(1) AS total FROM Sessions WHERE duration < 300
UNION
SELECT '[5-10>' AS bin, COUNT(1) AS total FROM Sessions WHERE 300 <= duration AND duration < 600
UNION
SELECT '[10-15>' AS bin, COUNT(1) AS total FROM Sessions WHERE 600 <= duration AND duration < 900
UNION
SELECT '15 or more' AS bin, COUNT(1) AS total FROM Sessions WHERE 900 <= duration;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Sessions</code></p>

<pre>
+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| session_id          | int     |
| duration            | int     |
+---------------------+---------+
session_id 是该表主键
duration 是用户访问应用的时间, 以秒为单位
</pre>

<p>&nbsp;</p>

<p>你想知道用户在你的 app 上的访问时长情况。因此你决定统计访问时长区间分别为 <code>"[0-5&gt;"</code>，<code>"[5-10&gt;"</code>，<code>"[10-15&gt;"</code>&nbsp;和&nbsp;<code>"15&nbsp;minutes&nbsp;or more"</code>&nbsp;的会话数量，并以此绘制柱状图。</p>

<p>写一个解决方案来报告 <code>(bin, total)</code> 。</p>

<p>返回结果 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Sessions 表：
+-------------+---------------+
| session_id  | duration      |
+-------------+---------------+
| 1           | 30            |
| 2           | 199           |
| 3           | 299           |
| 4           | 580           |
| 5           | 1000          |
+-------------+---------------+
<strong>输出：</strong>
+--------------+--------------+
| bin          | total        |
+--------------+--------------+
| [0-5&gt;        | 3            |
| [5-10&gt;       | 1            |
| [10-15&gt;      | 0            |
| 15 or more   | 1            |
+--------------+--------------+
<strong>解释：</strong>
对于 session_id 1，2 和 3 ，它们的访问时间大于等于 0 分钟且小于 5 分钟。
对于 session_id 4，它的访问时间大于等于 5 分钟且小于 10 分钟。
没有会话的访问时间大于等于 10 分钟且小于 15 分钟。
对于 session_id 5, 它的访问时间大于等于 15 分钟。
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
SELECT '[0-5>' AS bin, COUNT(1) AS total FROM Sessions WHERE duration < 300
UNION
SELECT '[5-10>' AS bin, COUNT(1) AS total FROM Sessions WHERE 300 <= duration AND duration < 600
UNION
SELECT '[10-15>' AS bin, COUNT(1) AS total FROM Sessions WHERE 600 <= duration AND duration < 900
UNION
SELECT '15 or more' AS bin, COUNT(1) AS total FROM Sessions WHERE 900 <= duration;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1436. 旅行终点站](https://leetcode.cn/problems/destination-city){#1436}

{{< tabs "1436" >}}

{{% tab "python" %}}
```python
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        s = {a for a, _ in paths}
        return next(b for _, b in paths if b not in s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> s = new HashSet<>();
        for (var p : paths) {
            s.add(p.get(0));
        }
        for (int i = 0;; ++i) {
            var b = paths.get(i).get(1);
            if (!s.contains(b)) {
                return b;
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
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto& p : paths) {
            s.insert(p[0]);
        }
        for (int i = 0;; ++i) {
            auto b = paths[i][1];
            if (!s.contains(b)) {
                return b;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func destCity(paths [][]string) string {
	s := map[string]bool{}
	for _, p := range paths {
		s[p[0]] = true
	}
	for _, p := range paths {
		if !s[p[1]] {
			return p[1]
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function destCity(paths: string[][]): string {
    const s = new Set<string>(paths.map(([a, _]) => a));
    return paths.find(([_, b]) => !s.has(b))![1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let s = paths
            .iter()
            .map(|p| p[0].clone())
            .collect::<HashSet<String>>();
        paths.into_iter().find(|p| !s.contains(&p[1])).unwrap()[1].clone()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function (paths) {
    const s = new Set(paths.map(([a, _]) => a));
    return paths.find(([_, b]) => !s.has(b))[1];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一份旅游线路图，该线路图中的旅行线路用数组 <code>paths</code> 表示，其中 <code>paths[i] = [cityA<sub>i</sub>, cityB<sub>i</sub>]</code> 表示该线路将会从 <code>cityA<sub>i</sub></code> 直接前往 <code>cityB<sub>i</sub></code> 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市<em>。</em></p>

<p>题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
<strong>输出：</strong>"Sao Paulo" 
<strong>解释：</strong>从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -&gt; "New York" -&gt; "Lima" -&gt; "Sao Paulo" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>paths = [["B","C"],["D","B"],["C","A"]]
<strong>输出：</strong>"A"
<strong>解释：</strong>所有可能的线路是：
"D" -&gt; "B" -&gt; "C" -&gt; "A".&nbsp;
"B" -&gt; "C" -&gt; "A".&nbsp;
"C" -&gt; "A".&nbsp;
"A".&nbsp;
显然，旅行终点站是 "A" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>paths = [["A","Z"]]
<strong>输出：</strong>"Z"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= paths.length &lt;= 100</code></li>
	<li><code>paths[i].length == 2</code></li>
	<li><code>1 &lt;=&nbsp;cityA<sub>i</sub>.length,&nbsp;cityB<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>cityA<sub>i&nbsp;</sub>!=&nbsp;cityB<sub>i</sub></code></li>
	<li>所有字符串均由大小写英文字母和空格字符组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

根据题目描述，终点一定不会出现在所有 $\textit{cityA}$ 中，因此，我们可以先遍历一遍 $\textit{paths}$，将所有 $\textit{cityA}$ 放入一个集合 $\textit{s}$ 中，然后再遍历一遍 $\textit{paths}$，找到不在 $\textit{s}$ 中的 $\textit{cityB}$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 $\textit{paths}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        s = {a for a, _ in paths}
        return next(b for _, b in paths if b not in s)
```

#### Java

```java
class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> s = new HashSet<>();
        for (var p : paths) {
            s.add(p.get(0));
        }
        for (int i = 0;; ++i) {
            var b = paths.get(i).get(1);
            if (!s.contains(b)) {
                return b;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto& p : paths) {
            s.insert(p[0]);
        }
        for (int i = 0;; ++i) {
            auto b = paths[i][1];
            if (!s.contains(b)) {
                return b;
            }
        }
    }
};
```

#### Go

```go
func destCity(paths [][]string) string {
	s := map[string]bool{}
	for _, p := range paths {
		s[p[0]] = true
	}
	for _, p := range paths {
		if !s[p[1]] {
			return p[1]
		}
	}
	return ""
}
```

#### TypeScript

```ts
function destCity(paths: string[][]): string {
    const s = new Set<string>(paths.map(([a, _]) => a));
    return paths.find(([_, b]) => !s.has(b))![1];
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let s = paths
            .iter()
            .map(|p| p[0].clone())
            .collect::<HashSet<String>>();
        paths.into_iter().find(|p| !s.contains(&p[1])).unwrap()[1].clone()
    }
}
```

#### JavaScript

```js
/**
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function (paths) {
    const s = new Set(paths.map(([a, _]) => a));
    return paths.find(([_, b]) => !s.has(b))[1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1437. 是否所有 1 都至少相隔 k 个元素](https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away){#1437}

{{< tabs "1437" >}}

{{% tab "python" %}}
```python
class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        j = -inf
        for i, x in enumerate(nums):
            if x:
                if i - j - 1 < k:
                    return False
                j = i
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int j = -(k + 1);
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 1) {
                if (i - j - 1 < k) {
                    return false;
                }
                j = i;
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
    bool kLengthApart(vector<int>& nums, int k) {
        int j = -(k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - j - 1 < k) {
                    return false;
                }
                j = i;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kLengthApart(nums []int, k int) bool {
	j := -(k + 1)
	for i, x := range nums {
		if x == 1 {
			if i-j-1 < k {
				return false
			}
			j = i
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kLengthApart(nums: number[], k: number): boolean {
    let j = -(k + 1);
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === 1) {
            if (i - j - 1 < k) {
                return false;
            }
            j = i;
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由若干 <code>0</code> 和 <code>1</code> 组成的数组 <code>nums</code> 以及整数 <code>k</code>。如果所有 <code>1</code> 都至少相隔 <code>k</code> 个元素，则返回 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">true</span></font>&nbsp;；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1437.Check%20If%20All%201%27s%20Are%20at%20Least%20Length%20K%20Places%20Away/images/sample_1_1791.png" style="width: 214px;" /></strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,0,0,1,0,0,1], k = 2
<strong>输出：</strong>true
<strong>解释：</strong>每个 1 都至少相隔 2 个元素。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1437.Check%20If%20All%201%27s%20Are%20at%20Least%20Length%20K%20Places%20Away/images/sample_2_1791.png" style="height: 86px; width: 160px;" /></strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,0,1,0,1], k = 2
<strong>输出：</strong>false
<strong>解释：</strong>第二个 1 和第三个 1 之间只隔了 1 个元素。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
	<li><code>nums[i]</code> 的值为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以遍历数组 $nums$，用变量 $j$ 记录上一个 $1$ 的下标，那么当前位置 $i$ 的元素为 $1$ 时，只需要判断 $i - j - 1$ 是否小于 $k$ 即可。如果小于 $k$，则说明存在两个 $1$ 之间的 $0$ 的个数小于 $k$，返回 `false`；否则，将 $j$ 更新为 $i$，继续遍历数组。

遍历结束后，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        j = -inf
        for i, x in enumerate(nums):
            if x:
                if i - j - 1 < k:
                    return False
                j = i
        return True
```

#### Java

```java
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int j = -(k + 1);
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 1) {
                if (i - j - 1 < k) {
                    return false;
                }
                j = i;
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
    bool kLengthApart(vector<int>& nums, int k) {
        int j = -(k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - j - 1 < k) {
                    return false;
                }
                j = i;
            }
        }
        return true;
    }
};
```

#### Go

```go
func kLengthApart(nums []int, k int) bool {
	j := -(k + 1)
	for i, x := range nums {
		if x == 1 {
			if i-j-1 < k {
				return false
			}
			j = i
		}
	}
	return true
}
```

#### TypeScript

```ts
function kLengthApart(nums: number[], k: number): boolean {
    let j = -(k + 1);
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === 1) {
            if (i - j - 1 < k) {
                return false;
            }
            j = i;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1438. 绝对差不超过限制的最长连续子数组](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit){#1438}

{{< tabs "1438" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxq = deque()
        minq = deque()
        l, n = 0, len(nums)
        for r, x in enumerate(nums):
            while maxq and nums[maxq[-1]] < x:
                maxq.pop()
            while minq and nums[minq[-1]] > x:
                minq.pop()
            maxq.append(r)
            minq.append(r)
            if nums[maxq[0]] - nums[minq[0]] > limit:
                l += 1
                if maxq[0] < l:
                    maxq.popleft()
                if minq[0] < l:
                    minq.popleft()
        return n - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int n = nums.length;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[r]) {
                maxQ.pollLast();
            }
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[r]) {
                minQ.pollLast();
            }
            maxQ.offerLast(r);
            minQ.offerLast(r);
            if (nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > limit) {
                ++l;
                if (maxQ.peekFirst() < l) {
                    maxQ.pollFirst();
                }
                if (minQ.peekFirst() < l) {
                    minQ.pollFirst();
                }
            }
        }
        return n - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_q;
        deque<int> min_q;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (!max_q.empty() && nums[max_q.back()] < nums[r]) {
                max_q.pop_back();
            }
            while (!min_q.empty() && nums[min_q.back()] > nums[r]) {
                min_q.pop_back();
            }
            max_q.push_back(r);
            min_q.push_back(r);

            if (nums[max_q.front()] - nums[min_q.front()] > limit) {
                ++l;
                if (max_q.front() < l) {
                    max_q.pop_front();
                }
                if (min_q.front() < l) {
                    min_q.pop_front();
                }
            }
        }
        return n - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubarray(nums []int, limit int) int {
	var maxq, minq Deque
	n := len(nums)
	l := 0
	for r, x := range nums {
		for !maxq.Empty() && nums[maxq.Back()] < x {
			maxq.PopBack()
		}
		for !minq.Empty() && nums[minq.Back()] > x {
			minq.PopBack()
		}
		maxq.PushBack(r)
		minq.PushBack(r)

		if nums[maxq.Front()]-nums[minq.Front()] > limit {
			l++
			if maxq.Front() < l {
				maxq.PopFront()
			}
			if minq.Front() < l {
				minq.PopFront()
			}
		}
	}
	return n - l
}

type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubarray(nums: number[], limit: number): number {
    const n = nums.length;
    let [h1, t1] = [0, -1];
    let [h2, t2] = [0, -1];
    let l = 0;
    const maxq = Array(n);
    const minq = Array(n);
    for (let r = 0; r < n; ++r) {
        while (h1 <= t1 && nums[maxq[t1]] < nums[r]) {
            --t1;
        }
        while (h2 <= t2 && nums[minq[t2]] > nums[r]) {
            --t2;
        }
        maxq[++t1] = r;
        minq[++t2] = r;
        if (nums[maxq[h1]] - nums[minq[h2]] > limit) {
            ++l;
            if (maxq[h1] < l) {
                ++h1;
            }
            if (minq[h2] < l) {
                ++h2;
            }
        }
    }
    return n - l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，和一个表示限制的整数 <code>limit</code>，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 <code>limit</code><em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [8,2,4,7], limit = 4
<strong>输出：</strong>2 
<strong>解释：</strong>所有子数组如下：
[8] 最大绝对差 |8-8| = 0 &lt;= 4.
[8,2] 最大绝对差 |8-2| = 6 &gt; 4. 
[8,2,4] 最大绝对差 |8-2| = 6 &gt; 4.
[8,2,4,7] 最大绝对差 |8-2| = 6 &gt; 4.
[2] 最大绝对差 |2-2| = 0 &lt;= 4.
[2,4] 最大绝对差 |2-4| = 2 &lt;= 4.
[2,4,7] 最大绝对差 |2-7| = 5 &gt; 4.
[4] 最大绝对差 |4-4| = 0 &lt;= 4.
[4,7] 最大绝对差 |4-7| = 3 &lt;= 4.
[7] 最大绝对差 |7-7| = 0 &lt;= 4. 
因此，满足题意的最长子数组的长度为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,1,2,4,7,2], limit = 5
<strong>输出：</strong>4 
<strong>解释：</strong>满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 &lt;= 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,2,2,4,4,2,2], limit = 0
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= limit &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合 + 滑动窗口

我们可以枚举每个位置作为子数组的右端点，找到其对应的最靠左的左端点，满足区间内中最大值与最小值的差值不超过 $limit$。过程中，我们用有序集合维护窗口内的最大值和最小值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        sl = SortedList()
        ans = j = 0
        for i, x in enumerate(nums):
            sl.add(x)
            while sl[-1] - sl[0] > limit:
                sl.remove(nums[j])
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```

#### Java

```java
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        int ans = 0;
        for (int i = 0, j = 0; i < nums.length; ++i) {
            tm.merge(nums[i], 1, Integer::sum);
            for (; tm.lastKey() - tm.firstKey() > limit; ++j) {
                if (tm.merge(nums[j], -1, Integer::sum) == 0) {
                    tm.remove(nums[j]);
                }
            }
            ans = Math.max(ans, i - j + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[j++]));
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubarray(nums []int, limit int) (ans int) {
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}
	st := redblacktree.New[int, int]()
	j := 0
	for i, x := range nums {
		merge(st, x, 1)
		for ; st.Right().Key-st.Left().Key > limit; j++ {
			merge(st, nums[j], -1)
		}
		ans = max(ans, i-j+1)
	}
	return
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[], limit: number): number {
    const ts = new TreapMultiSet<number>();
    let ans = 0;
    let j = 0;
    for (let i = 0; i < nums.length; ++i) {
        ts.add(nums[i]);
        while (ts.last()! - ts.first()! > limit) {
            ts.delete(nums[j++]);
        }
        ans = Math.max(ans, i - j + 1);
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找 + 滑动窗口

我们注意到，如果一个长度为 $k$ 的子数组满足条件，那么长度 $k' < k$ 的子数组也满足条件，这存在着单调性，因此，我们可以使用二分查找，找到最长的满足条件的子数组。

我们定义二分查找的左边界 $l = 0$，右边界 $r = n$。对于每个 $mid = \frac{l + r + 1}{2}$，我们检查是否存在一个长度为 $mid$ 的子数组满足条件。如果存在，我们更新 $l = mid$，否则更新 $r = mid - 1$。那么问题转换为数组中是否存在一个长度为 $mid$ 的子数组满足条件，这其实是求滑动窗口中的最大值和最小值的差值不超过 $limit$。我们可以用两个单调队列分别维护窗口内的最大值和最小值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        def check(k: int) -> bool:
            min_q = deque()
            max_q = deque()
            for i, x in enumerate(nums):
                if min_q and i - min_q[0] + 1 > k:
                    min_q.popleft()
                if max_q and i - max_q[0] + 1 > k:
                    max_q.popleft()
                while min_q and nums[min_q[-1]] >= x:
                    min_q.pop()
                while max_q and nums[max_q[-1]] <= x:
                    max_q.pop()
                min_q.append(i)
                max_q.append(i)
                if i >= k - 1 and nums[max_q[0]] - nums[min_q[0]] <= limit:
                    return True
            return False

        l, r = 1, len(nums)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int[] nums;
    private int limit;

    public int longestSubarray(int[] nums, int limit) {
        this.nums = nums;
        this.limit = limit;
        int l = 1, r = nums.length;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int k) {
        Deque<Integer> minQ = new ArrayDeque<>();
        Deque<Integer> maxQ = new ArrayDeque<>();
        for (int i = 0; i < nums.length; ++i) {
            if (!minQ.isEmpty() && i - minQ.peekFirst() + 1 > k) {
                minQ.pollFirst();
            }
            if (!maxQ.isEmpty() && i - maxQ.peekFirst() + 1 > k) {
                maxQ.pollFirst();
            }
            while (!minQ.isEmpty() && nums[minQ.peekLast()] >= nums[i]) {
                minQ.pollLast();
            }
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] <= nums[i]) {
                maxQ.pollLast();
            }
            minQ.offer(i);
            maxQ.offer(i);
            if (i >= k - 1 && nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] <= limit) {
                return true;
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
    int longestSubarray(vector<int>& nums, int limit) {
        auto check = [&](int k) {
            deque<int> min_q;
            deque<int> max_q;
            for (int i = 0; i < nums.size(); ++i) {
                if (!min_q.empty() && i - min_q.front() + 1 > k) {
                    min_q.pop_front();
                }
                if (!max_q.empty() && i - max_q.front() + 1 > k) {
                    max_q.pop_front();
                }
                while (!min_q.empty() && nums[min_q.back()] >= nums[i]) {
                    min_q.pop_back();
                }
                while (!max_q.empty() && nums[max_q.back()] <= nums[i]) {
                    max_q.pop_back();
                }
                min_q.push_back(i);
                max_q.push_back(i);
                if (i >= k - 1 && nums[max_q.front()] - nums[min_q.front()] <= limit) {
                    return true;
                }
            }
            return false;
        };
        int l = 1, r = nums.size();
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func longestSubarray(nums []int, limit int) int {
	l, r := 0, len(nums)
	check := func(k int) bool {
		minq := Deque{}
		maxq := Deque{}
		for i, x := range nums {
			for !minq.Empty() && i-minq.Front()+1 > k {
				minq.PopFront()
			}
			for !maxq.Empty() && i-maxq.Front()+1 > k {
				maxq.PopFront()
			}
			for !minq.Empty() && nums[minq.Back()] >= x {
				minq.PopBack()
			}
			for !maxq.Empty() && nums[maxq.Back()] <= x {
				maxq.PopBack()
			}
			minq.PushBack(i)
			maxq.PushBack(i)
			if i >= k-1 && nums[maxq.Front()]-nums[minq.Front()] <= limit {
				return true
			}
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[], limit: number): number {
    const n = nums.length;
    let [l, r] = [0, n];
    const check = (k: number): boolean => {
        const minq = new Deque<number>();
        const maxq = new Deque<number>();
        for (let i = 0; i < n; ++i) {
            while (!minq.isEmpty() && i - minq.frontValue()! + 1 > k) {
                minq.popFront();
            }
            while (!maxq.isEmpty() && i - maxq.frontValue()! + 1 > k) {
                maxq.popFront();
            }
            while (!minq.isEmpty() && nums[minq.backValue()!] >= nums[i]) {
                minq.popBack();
            }
            while (!maxq.isEmpty() && nums[maxq.backValue()!] <= nums[i]) {
                maxq.popBack();
            }
            minq.pushBack(i);
            maxq.pushBack(i);
            if (i >= k - 1 && nums[maxq.frontValue()!] - nums[minq.frontValue()!] <= limit) {
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：滑动窗口 + 双向队列

我们可以使用双向队列维护窗口内的最大值和最小值。我们维护两个双向队列，分别存储窗口内的最大值和最小值的下标。定义两个指针 $l$ 和 $r$ 分别指向窗口的左边界和右边界。

每次向右移动右边界 $r$，判断最大值队列的队尾下标对应的元素是否小于当前元素，如果小于，则将队尾元素出队，直到最大值队列的队尾元素对应的元素不小于当前元素。同理，判断最小值队列的队尾下标对应的元素是否大于当前元素，如果大于，则将队尾元素出队，直到最小值队列的队尾元素对应的元素不大于当前元素。然后，将当前元素的下标入队。

如果最大值队列的队首元素和最小值队列的队首元素的差值大于 $limit$，则向右移动左边界 $l$，然后如果最大值队列的队首元素小于 $l$，则将最大值队列的队首元素出队，如果最小值队列的队首元素小于 $l$，则将最小值队列的队首元素出队。

答案为 $n - l$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxq = deque()
        minq = deque()
        l, n = 0, len(nums)
        for r, x in enumerate(nums):
            while maxq and nums[maxq[-1]] < x:
                maxq.pop()
            while minq and nums[minq[-1]] > x:
                minq.pop()
            maxq.append(r)
            minq.append(r)
            if nums[maxq[0]] - nums[minq[0]] > limit:
                l += 1
                if maxq[0] < l:
                    maxq.popleft()
                if minq[0] < l:
                    minq.popleft()
        return n - l
```

#### Java

```java
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int n = nums.length;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[r]) {
                maxQ.pollLast();
            }
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[r]) {
                minQ.pollLast();
            }
            maxQ.offerLast(r);
            minQ.offerLast(r);
            if (nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > limit) {
                ++l;
                if (maxQ.peekFirst() < l) {
                    maxQ.pollFirst();
                }
                if (minQ.peekFirst() < l) {
                    minQ.pollFirst();
                }
            }
        }
        return n - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_q;
        deque<int> min_q;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (!max_q.empty() && nums[max_q.back()] < nums[r]) {
                max_q.pop_back();
            }
            while (!min_q.empty() && nums[min_q.back()] > nums[r]) {
                min_q.pop_back();
            }
            max_q.push_back(r);
            min_q.push_back(r);

            if (nums[max_q.front()] - nums[min_q.front()] > limit) {
                ++l;
                if (max_q.front() < l) {
                    max_q.pop_front();
                }
                if (min_q.front() < l) {
                    min_q.pop_front();
                }
            }
        }
        return n - l;
    }
};
```

#### Go

```go
func longestSubarray(nums []int, limit int) int {
	var maxq, minq Deque
	n := len(nums)
	l := 0
	for r, x := range nums {
		for !maxq.Empty() && nums[maxq.Back()] < x {
			maxq.PopBack()
		}
		for !minq.Empty() && nums[minq.Back()] > x {
			minq.PopBack()
		}
		maxq.PushBack(r)
		minq.PushBack(r)

		if nums[maxq.Front()]-nums[minq.Front()] > limit {
			l++
			if maxq.Front() < l {
				maxq.PopFront()
			}
			if minq.Front() < l {
				minq.PopFront()
			}
		}
	}
	return n - l
}

type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[], limit: number): number {
    const n = nums.length;
    let [h1, t1] = [0, -1];
    let [h2, t2] = [0, -1];
    let l = 0;
    const maxq = Array(n);
    const minq = Array(n);
    for (let r = 0; r < n; ++r) {
        while (h1 <= t1 && nums[maxq[t1]] < nums[r]) {
            --t1;
        }
        while (h2 <= t2 && nums[minq[t2]] > nums[r]) {
            --t2;
        }
        maxq[++t1] = r;
        minq[++t2] = r;
        if (nums[maxq[h1]] - nums[minq[h2]] > limit) {
            ++l;
            if (maxq[h1] < l) {
                ++h1;
            }
            if (minq[h2] < l) {
                ++h2;
            }
        }
    }
    return n - l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1439. 有序矩阵中的第 k 个最小数组和](https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows){#1439}

{{< tabs "1439" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        pre = [0]
        for cur in mat:
            pre = sorted(a + b for a in pre for b in cur[:k])[:k]
        return pre[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;
        List<Integer> pre = new ArrayList<>(k);
        List<Integer> cur = new ArrayList<>(n * k);
        pre.add(0);
        for (int[] row : mat) {
            cur.clear();
            for (int a : pre) {
                for (int b : row) {
                    cur.add(a + b);
                }
            }
            Collections.sort(cur);
            pre.clear();
            for (int i = 0; i < Math.min(k, cur.size()); ++i) {
                pre.add(cur.get(i));
            }
        }
        return pre.get(k - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int pre[k];
        int cur[mat[0].size() * k];
        memset(pre, 0, sizeof pre);
        int size = 1;
        for (auto& row : mat) {
            int i = 0;
            for (int j = 0; j < size; ++j) {
                for (int& v : row) {
                    cur[i++] = pre[j] + v;
                }
            }
            sort(cur, cur + i);
            size = min(i, k);
            for (int j = 0; j < size; ++j) {
                pre[j] = cur[j];
            }
        }
        return pre[k - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthSmallest(mat [][]int, k int) int {
	pre := []int{0}
	for _, row := range mat {
		cur := []int{}
		for _, a := range pre {
			for _, b := range row {
				cur = append(cur, a+b)
			}
		}
		sort.Ints(cur)
		pre = cur[:min(k, len(cur))]
	}
	return pre[k-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthSmallest(mat: number[][], k: number): number {
    let pre: number[] = [0];
    for (const cur of mat) {
        const next: number[] = [];
        for (const a of pre) {
            for (const b of cur) {
                next.push(a + b);
            }
        }
        pre = next.sort((a, b) => a - b).slice(0, k);
    }
    return pre[k - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m&nbsp;* n</code> 的矩阵 <code>mat</code>，以及一个整数 <code>k</code> ，矩阵中的每一行都以非递减的顺序排列。</p>

<p>你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 <strong>最小</strong> 数组和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mat = [[1,3,11],[2,4,6]], k = 5
<strong>输出：</strong>7
<strong>解释：</strong>从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。  </pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[1,3,11],[2,4,6]], k = 9
<strong>输出：</strong>17
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
<strong>输出：</strong>9
<strong>解释：</strong>从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7 个的和是 9 。 
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>mat = [[1,1,10],[2,2,9]], k = 7
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat.length[i]</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= min(200, n ^&nbsp;m)</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 5000</code></li>
	<li><code>mat[i]</code> 是一个非递减数组</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逐行遍历 + 排序

根据题目描述，我们需要找出前 $m$ 行的所有可能数组中的第 $k$ 个最小数组和。

如果我们能够找出前 $m - 1$ 行的所有可能数组中的前 $k$ 个最小数组和，那么我们可以将第 $m$ 行的每个元素与前 $m - 1$ 行的前 $k$ 个最小数组和相加，将得到的所有结果排序后，取前 $k$ 个最小值，即为前 $m$ 行的所有可能数组中的前 $k$ 个最小值。

因此，我们可以定义一个数组 $pre$，用于存储此前遍历到的行的前 $k$ 个最小数组和，初始时 $pre$ 只有一个元素 $0$。

然后，我们遍历 $mat$ 的每一行 $cur$，将 $cur$ 中的每个元素与 $pre$ 中的每个元素相加，将得到的所有结果排序后，取前 $k$ 个最小值作为新的 $pre$。继续遍历下一行，直到遍历完所有行。

最后返回 $pre$ 中的第 $k$ 个数（下标 $k-1$）即可。

时间复杂度 $O(m \times n \times k \times \log (n \times k))$，空间复杂度 $O(n \times k)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        pre = [0]
        for cur in mat:
            pre = sorted(a + b for a in pre for b in cur[:k])[:k]
        return pre[-1]
```

#### Java

```java
class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;
        List<Integer> pre = new ArrayList<>(k);
        List<Integer> cur = new ArrayList<>(n * k);
        pre.add(0);
        for (int[] row : mat) {
            cur.clear();
            for (int a : pre) {
                for (int b : row) {
                    cur.add(a + b);
                }
            }
            Collections.sort(cur);
            pre.clear();
            for (int i = 0; i < Math.min(k, cur.size()); ++i) {
                pre.add(cur.get(i));
            }
        }
        return pre.get(k - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int pre[k];
        int cur[mat[0].size() * k];
        memset(pre, 0, sizeof pre);
        int size = 1;
        for (auto& row : mat) {
            int i = 0;
            for (int j = 0; j < size; ++j) {
                for (int& v : row) {
                    cur[i++] = pre[j] + v;
                }
            }
            sort(cur, cur + i);
            size = min(i, k);
            for (int j = 0; j < size; ++j) {
                pre[j] = cur[j];
            }
        }
        return pre[k - 1];
    }
};
```

#### Go

```go
func kthSmallest(mat [][]int, k int) int {
	pre := []int{0}
	for _, row := range mat {
		cur := []int{}
		for _, a := range pre {
			for _, b := range row {
				cur = append(cur, a+b)
			}
		}
		sort.Ints(cur)
		pre = cur[:min(k, len(cur))]
	}
	return pre[k-1]
}
```

#### TypeScript

```ts
function kthSmallest(mat: number[][], k: number): number {
    let pre: number[] = [0];
    for (const cur of mat) {
        const next: number[] = [];
        for (const a of pre) {
            for (const b of cur) {
                next.push(a + b);
            }
        }
        pre = next.sort((a, b) => a - b).slice(0, k);
    }
    return pre[k - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
