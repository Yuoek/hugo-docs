---
title: "0660_移除 9 🔒"
date: 2025-10-08T18:36:23+08:00
weight: 7
tags: [二分查找, 二叉搜索树, 二叉树, 动态规划, 哈希表, 字符串, 广度优先搜索, 数学, 数组, 树, 深度优先搜索, 矩阵]
---

{{< markmap >}}
### [0660_移除 9 🔒](#660)
#### [数学](#660)
### [0661_图片平滑器](#661)
#### [数组](#661)
#### [矩阵](#661)
### [0662_二叉树最大宽度](#662)
#### [树](#662)
#### [深度优先搜索](#662)
#### [广度优先搜索](#662)
#### [二叉树](#662)
### [0663_均匀树划分 🔒](#663)
#### [树](#663)
#### [深度优先搜索](#663)
#### [二叉树](#663)
### [0664_奇怪的打印机](#664)
#### [字符串](#664)
#### [动态规划](#664)
### [0665_非递减数列](#665)
#### [数组](#665)
### [0666_路径总和 IV 🔒](#666)
#### [树](#666)
#### [深度优先搜索](#666)
#### [数组](#666)
#### [哈希表](#666)
#### [二叉树](#666)
### [0667_优美的排列 II](#667)
#### [数组](#667)
#### [数学](#667)
### [0668_乘法表中第k小的数](#668)
#### [数学](#668)
#### [二分查找](#668)
### [0669_修剪二叉搜索树](#669)
#### [树](#669)
#### [深度优先搜索](#669)
#### [二叉搜索树](#669)
#### [二叉树](#669)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0660_移除 9 🔒
___
#### 数学
---
### 0661_图片平滑器
___
#### 数组
___
#### 矩阵
---
### 0662_二叉树最大宽度
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0663_均匀树划分 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0664_奇怪的打印机
___
#### 字符串
___
#### 动态规划
---
### 0665_非递减数列
___
#### 数组
---
### 0666_路径总和 IV 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 哈希表
___
#### 二叉树
---
### 0667_优美的排列 II
___
#### 数组
___
#### 数学
---
### 0668_乘法表中第k小的数
___
#### 数学
___
#### 二分查找
---
### 0669_修剪二叉搜索树
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 动态规划 | 哈希表 | 字符串 |
| 广度优先搜索 | 数学 | 数组 |
| 树 | 深度优先搜索 | 矩阵 |

# [660. 移除 9 🔒](https://leetcode.cn/problems/remove-9){#660}

{{< tabs "660" >}}

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

<p>从 <code>1</code> 开始，移除包含数字 <code>9</code> 的所有整数，例如 <code>9</code>，<code>19</code>，<code>29</code>，……</p>

<p>这样就获得了一个新的整数数列：<code>1</code>，<code>2</code>，<code>3</code>，<code>4</code>，<code>5</code>，<code>6</code>，<code>7</code>，<code>8</code>，<code>10</code>，<code>11</code>，……</p>

<p>给你一个整数 <code>n</code>，请你返回新数列中第 <code>n</code> 个数字是多少（下标从 <strong>1</strong> 开始）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>10
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>11
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8 * 10<sup>8</sup></code></li>
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

# [661. 图片平滑器](https://leetcode.cn/problems/image-smoother){#661}

{{< tabs "661" >}}

{{% tab "python" %}}
```python
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                s = cnt = 0
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < m and 0 <= y < n:
                            cnt += 1
                            s += img[x][y]
                ans[i][j] = s // cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 0;
                int cnt = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            ++cnt;
                            s += img[x][y];
                        }
                    }
                }
                ans[i][j] = s / cnt;
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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 0, cnt = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            continue;
                        }
                        ++cnt;
                        s += img[x][y];
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func imageSmoother(img [][]int) [][]int {
	m, n := len(img), len(img[0])
	ans := make([][]int, m)
	for i, row := range img {
		ans[i] = make([]int, n)
		for j := range row {
			s, cnt := 0, 0
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					if x >= 0 && x < m && y >= 0 && y < n {
						cnt++
						s += img[x][y]
					}
				}
			}
			ans[i][j] = s / cnt
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function imageSmoother(img: number[][]): number[][] {
    const m = img.length;
    const n = img[0].length;
    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let s = 0;
            let cnt = 0;
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        ++cnt;
                        s += img[x][y];
                    }
                }
            }
            ans[i][j] = Math.floor(s / cnt);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = img.len();
        let n = img[0].len();
        let mut ans = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                let mut s = 0;
                let mut cnt = 0;
                for x in i.saturating_sub(1)..=(i + 1).min(m - 1) {
                    for y in j.saturating_sub(1)..=(j + 1).min(n - 1) {
                        s += img[x][y];
                        cnt += 1;
                    }
                }
                ans[i][j] = s / cnt;
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

<p><strong>图像平滑器</strong> 是大小为&nbsp;<code>3 x 3</code> 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。</p>

<p>每个单元格的<strong>&nbsp; 平均灰度</strong> 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。</p>

<p>如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0661.Image%20Smoother/images/smoother-grid.jpg" style="height: 493px; width: 493px;" /></p>

<p>给你一个表示图像灰度的 <code>m x n</code> 整数矩阵 <code>img</code> ，返回对图像的每个单元格平滑处理后的图像&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0661.Image%20Smoother/images/smooth-grid.jpg" /></p>

<pre>
<strong>输入:</strong>img = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出:</strong>[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
<strong>解释:</strong>
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0661.Image%20Smoother/images/smooth2-grid.jpg" />
<pre>
<strong>输入:</strong> img = [[100,200,100],[200,50,200],[100,200,100]]
<strong>输出:</strong> [[137,141,137],[141,138,141],[137,141,137]]
<strong>解释:</strong>
对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == img.length</code></li>
	<li><code>n == img[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= img[i][j] &lt;= 255</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们创建一个大小为 $m \times n$ 的二维数组 $\textit{ans}$，其中 $\textit{ans}[i][j]$ 表示图像中第 $i$ 行第 $j$ 列的单元格的平滑值。

对于 $\textit{ans}[i][j]$，我们遍历 $\textit{img}$ 中第 $i$ 行第 $j$ 列的单元格及其周围的 $8$ 个单元格，计算它们的和 $s$ 以及个数 $cnt$，然后计算平均值 $s / cnt$ 并将其存入 $\textit{ans}[i][j]$ 中。

遍历结束后，我们返回 $\textit{ans}$ 即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是 $\textit{img}$ 的行数和列数。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                s = cnt = 0
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < m and 0 <= y < n:
                            cnt += 1
                            s += img[x][y]
                ans[i][j] = s // cnt
        return ans
```

#### Java

```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 0;
                int cnt = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            ++cnt;
                            s += img[x][y];
                        }
                    }
                }
                ans[i][j] = s / cnt;
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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 0, cnt = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            continue;
                        }
                        ++cnt;
                        s += img[x][y];
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func imageSmoother(img [][]int) [][]int {
	m, n := len(img), len(img[0])
	ans := make([][]int, m)
	for i, row := range img {
		ans[i] = make([]int, n)
		for j := range row {
			s, cnt := 0, 0
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					if x >= 0 && x < m && y >= 0 && y < n {
						cnt++
						s += img[x][y]
					}
				}
			}
			ans[i][j] = s / cnt
		}
	}
	return ans
}
```

#### TypeScript

```ts
function imageSmoother(img: number[][]): number[][] {
    const m = img.length;
    const n = img[0].length;
    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let s = 0;
            let cnt = 0;
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        ++cnt;
                        s += img[x][y];
                    }
                }
            }
            ans[i][j] = Math.floor(s / cnt);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = img.len();
        let n = img[0].len();
        let mut ans = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                let mut s = 0;
                let mut cnt = 0;
                for x in i.saturating_sub(1)..=(i + 1).min(m - 1) {
                    for y in j.saturating_sub(1)..=(j + 1).min(n - 1) {
                        s += img[x][y];
                        cnt += 1;
                    }
                }
                ans[i][j] = s / cnt;
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

# [662. 二叉树最大宽度](https://leetcode.cn/problems/maximum-width-of-binary-tree){#662}

{{< tabs "662" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root, depth, i):
            if root is None:
                return
            if len(t) == depth:
                t.append(i)
            else:
                nonlocal ans
                ans = max(ans, i - t[depth] + 1)
            dfs(root.left, depth + 1, i << 1)
            dfs(root.right, depth + 1, i << 1 | 1)

        ans = 1
        t = []
        dfs(root, 0, 1)
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
    private int ans = 1;
    private List<Integer> t = new ArrayList<>();

    public int widthOfBinaryTree(TreeNode root) {
        dfs(root, 0, 1);
        return ans;
    }

    private void dfs(TreeNode root, int depth, int i) {
        if (root == null) {
            return;
        }
        if (t.size() == depth) {
            t.add(i);
        } else {
            ans = Math.max(ans, i - t.get(depth) + 1);
        }
        dfs(root.left, depth + 1, i << 1);
        dfs(root.right, depth + 1, i << 1 | 1);
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
    vector<int> t;
    int ans = 1;
    using ull = unsigned long long;

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 1);
        return ans;
    }

    void dfs(TreeNode* root, int depth, ull i) {
        if (!root) return;
        if (t.size() == depth) {
            t.push_back(i);
        } else {
            ans = max(ans, (int) (i - t[depth] + 1));
        }
        dfs(root->left, depth + 1, i << 1);
        dfs(root->right, depth + 1, i << 1 | 1);
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
func widthOfBinaryTree(root *TreeNode) int {
	ans := 1
	t := []int{}
	var dfs func(root *TreeNode, depth, i int)
	dfs = func(root *TreeNode, depth, i int) {
		if root == nil {
			return
		}
		if len(t) == depth {
			t = append(t, i)
		} else {
			ans = max(ans, i-t[depth]+1)
		}
		dfs(root.Left, depth+1, i<<1)
		dfs(root.Right, depth+1, i<<1|1)
	}
	dfs(root, 0, 1)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code> ，返回树的 <strong>最大宽度</strong> 。</p>

<p>树的 <strong>最大宽度</strong> 是所有层中最大的 <strong>宽度</strong> 。</p>

<div class="original__bRMd">
<div>
<p>每一层的 <strong>宽度</strong> 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 <code>null</code> 节点，这些 <code>null</code> 节点也计入长度。</p>

<p>题目数据保证答案将会在&nbsp; <strong>32 位</strong> 带符号整数范围内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0662.Maximum%20Width%20of%20Binary%20Tree/images/width1-tree.jpg" style="width: 359px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [1,3,2,5,3,null,9]
<strong>输出：</strong>4
<strong>解释：</strong>最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0662.Maximum%20Width%20of%20Binary%20Tree/images/maximum-width-of-binary-tree-v3.jpg" style="width: 442px; height: 422px;" />
<pre>
<strong>输入：</strong>root = [1,3,2,5,null,null,9,6,null,7]
<strong>输出：</strong>7
<strong>解释：</strong>最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0662.Maximum%20Width%20of%20Binary%20Tree/images/width3-tree.jpg" style="width: 289px; height: 299px;" />
<pre>
<strong>输入：</strong>root = [1,3,2,5]
<strong>输出：</strong>2
<strong>解释：</strong>最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目范围是 <code>[1, 3000]</code></li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
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

### 方法一：BFS

对节点进行编号，初始根节点编号为 $1$。

对于一个编号为 `i` 的节点，它的左节点编号为 `i<<1`，右节点编号为 `i<<1|1`。

采用 BFS 进行层序遍历，求每层的宽度时，用该层的最大节点编号减去最小节点编号再加一即可。

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
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0
        q = deque([(root, 1)])
        while q:
            ans = max(ans, q[-1][1] - q[0][1] + 1)
            for _ in range(len(q)):
                root, i = q.popleft()
                if root.left:
                    q.append((root.left, i << 1))
                if root.right:
                    q.append((root.right, i << 1 | 1))
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
    public int widthOfBinaryTree(TreeNode root) {
        Deque<Pair<TreeNode, Integer>> q = new ArrayDeque<>();
        q.offer(new Pair<>(root, 1));
        int ans = 0;
        while (!q.isEmpty()) {
            ans = Math.max(ans, q.peekLast().getValue() - q.peekFirst().getValue() + 1);
            for (int n = q.size(); n > 0; --n) {
                var p = q.pollFirst();
                root = p.getKey();
                int i = p.getValue();
                if (root.left != null) {
                    q.offer(new Pair<>(root.left, i << 1));
                }
                if (root.right != null) {
                    q.offer(new Pair<>(root.right, i << 1 | 1));
                }
            }
        }
        return ans;
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 0;
        while (!q.empty()) {
            ans = max(ans, q.back().second - q.front().second + 1);
            int i = q.front().second;
            for (int n = q.size(); n; --n) {
                auto p = q.front();
                q.pop();
                root = p.first;
                int j = p.second;
                if (root->left) q.push({root->left, (j << 1) - (i << 1)});
                if (root->right) q.push({root->right, (j << 1 | 1) - (i << 1)});
            }
        }
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
func widthOfBinaryTree(root *TreeNode) int {
	q := []pair{{root, 1}}
	ans := 0
	for len(q) > 0 {
		ans = max(ans, q[len(q)-1].i-q[0].i+1)
		for n := len(q); n > 0; n-- {
			p := q[0]
			q = q[1:]
			root = p.node
			if root.Left != nil {
				q = append(q, pair{root.Left, p.i << 1})
			}
			if root.Right != nil {
				q = append(q, pair{root.Right, p.i<<1 | 1})
			}
		}
	}
	return ans
}

type pair struct {
	node *TreeNode
	i    int
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

定义 `dfs(root, depth, i)` 表示从深度为 `depth`，且编号为 `i` 的节点 `root` 开始往下搜索。记录每一层最先访问到的节点的编号。访问到当前层其它节点时，求当前节点编号与当前层最小编号的差再加一，更新当前层的最大宽度。

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
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(root, depth, i):
            if root is None:
                return
            if len(t) == depth:
                t.append(i)
            else:
                nonlocal ans
                ans = max(ans, i - t[depth] + 1)
            dfs(root.left, depth + 1, i << 1)
            dfs(root.right, depth + 1, i << 1 | 1)

        ans = 1
        t = []
        dfs(root, 0, 1)
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
    private int ans = 1;
    private List<Integer> t = new ArrayList<>();

    public int widthOfBinaryTree(TreeNode root) {
        dfs(root, 0, 1);
        return ans;
    }

    private void dfs(TreeNode root, int depth, int i) {
        if (root == null) {
            return;
        }
        if (t.size() == depth) {
            t.add(i);
        } else {
            ans = Math.max(ans, i - t.get(depth) + 1);
        }
        dfs(root.left, depth + 1, i << 1);
        dfs(root.right, depth + 1, i << 1 | 1);
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
    vector<int> t;
    int ans = 1;
    using ull = unsigned long long;

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 1);
        return ans;
    }

    void dfs(TreeNode* root, int depth, ull i) {
        if (!root) return;
        if (t.size() == depth) {
            t.push_back(i);
        } else {
            ans = max(ans, (int) (i - t[depth] + 1));
        }
        dfs(root->left, depth + 1, i << 1);
        dfs(root->right, depth + 1, i << 1 | 1);
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
func widthOfBinaryTree(root *TreeNode) int {
	ans := 1
	t := []int{}
	var dfs func(root *TreeNode, depth, i int)
	dfs = func(root *TreeNode, depth, i int) {
		if root == nil {
			return
		}
		if len(t) == depth {
			t = append(t, i)
		} else {
			ans = max(ans, i-t[depth]+1)
		}
		dfs(root.Left, depth+1, i<<1)
		dfs(root.Right, depth+1, i<<1|1)
	}
	dfs(root, 0, 1)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [663. 均匀树划分 🔒](https://leetcode.cn/problems/equal-tree-partition){#663}

{{< tabs "663" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEqualTree(self, root: TreeNode) -> bool:
        def sum(root):
            if root is None:
                return 0
            l, r = sum(root.left), sum(root.right)
            seen.append(l + r + root.val)
            return seen[-1]

        seen = []
        s = sum(root)
        if s % 2 == 1:
            return False
        seen.pop()
        return s // 2 in seen
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
    private List<Integer> seen;

    public boolean checkEqualTree(TreeNode root) {
        seen = new ArrayList<>();
        int s = sum(root);
        if (s % 2 != 0) {
            return false;
        }
        seen.remove(seen.size() - 1);
        return seen.contains(s / 2);
    }

    private int sum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = sum(root.left);
        int r = sum(root.right);
        int s = l + r + root.val;
        seen.add(s);
        return s;
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
    vector<int> seen;

    bool checkEqualTree(TreeNode* root) {
        int s = sum(root);
        if (s % 2 != 0) return false;
        seen.pop_back();
        return count(seen.begin(), seen.end(), s / 2);
    }

    int sum(TreeNode* root) {
        if (!root) return 0;
        int l = sum(root->left), r = sum(root->right);
        int s = l + r + root->val;
        seen.push_back(s);
        return s;
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
func checkEqualTree(root *TreeNode) bool {
	var seen []int
	var sum func(root *TreeNode) int
	sum = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := sum(root.Left), sum(root.Right)
		s := l + r + root.Val
		seen = append(seen, s)
		return s
	}

	s := sum(root)
	if s%2 != 0 {
		return false
	}
	seen = seen[:len(seen)-1]
	for _, v := range seen {
		if v == s/2 {
			return true
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code>，如果你可以通过去掉原始树上的一条边将树分成两棵节点值之和相等的子树，则返回 <code>true</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0663.Equal%20Tree%20Partition/images/split1-tree.jpg" style="width: 500px; height: 204px;" />
<pre>
<strong>输入：</strong>root = [5,10,10,null,null,2,3]
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0663.Equal%20Tree%20Partition/images/split2-tree.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [1,2,10,null,null,2,20]
<strong>输出：</strong>false
<strong>解释：</strong>在树上移除一条边无法将树分成两棵节点值之和相等的子树。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在 <code>[1, 10<sup>4</sup>]</code> 范围内。</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
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
    def checkEqualTree(self, root: TreeNode) -> bool:
        def sum(root):
            if root is None:
                return 0
            l, r = sum(root.left), sum(root.right)
            seen.append(l + r + root.val)
            return seen[-1]

        seen = []
        s = sum(root)
        if s % 2 == 1:
            return False
        seen.pop()
        return s // 2 in seen
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
    private List<Integer> seen;

    public boolean checkEqualTree(TreeNode root) {
        seen = new ArrayList<>();
        int s = sum(root);
        if (s % 2 != 0) {
            return false;
        }
        seen.remove(seen.size() - 1);
        return seen.contains(s / 2);
    }

    private int sum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = sum(root.left);
        int r = sum(root.right);
        int s = l + r + root.val;
        seen.add(s);
        return s;
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
    vector<int> seen;

    bool checkEqualTree(TreeNode* root) {
        int s = sum(root);
        if (s % 2 != 0) return false;
        seen.pop_back();
        return count(seen.begin(), seen.end(), s / 2);
    }

    int sum(TreeNode* root) {
        if (!root) return 0;
        int l = sum(root->left), r = sum(root->right);
        int s = l + r + root->val;
        seen.push_back(s);
        return s;
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
func checkEqualTree(root *TreeNode) bool {
	var seen []int
	var sum func(root *TreeNode) int
	sum = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := sum(root.Left), sum(root.Right)
		s := l + r + root.Val
		seen = append(seen, s)
		return s
	}

	s := sum(root)
	if s%2 != 0 {
		return false
	}
	seen = seen[:len(seen)-1]
	for _, v := range seen {
		if v == s/2 {
			return true
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [664. 奇怪的打印机](https://leetcode.cn/problems/strange-printer){#664}

{{< tabs "664" >}}

{{% tab "python" %}}
```python
class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        f = [[inf] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i][j - 1]
                else:
                    for k in range(i, j):
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j])
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int strangePrinter(String s) {
        final int inf = 1 << 30;
        int n = s.length();
        int[][] f = new int[n][n];
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0x3f, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func strangePrinter(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = 1 << 30
		}
	}
	for i := n - 1; i >= 0; i-- {
		f[i][i] = 1
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i][j-1]
			} else {
				for k := i; k < j; k++ {
					f[i][j] = min(f[i][j], f[i][k]+f[k+1][j])
				}
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function strangePrinter(s: string): number {
    const n = s.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(1 << 30));
    for (let i = n - 1; i >= 0; --i) {
        f[i][i] = 1;
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i][j - 1];
            } else {
                for (let k = i; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }
    }
    return f[0][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有台奇怪的打印机有以下两个特殊要求：</p>

<ul>
	<li>打印机每次只能打印由 <strong>同一个字符</strong> 组成的序列。</li>
	<li>每次可以在从起始到结束的任意位置打印新字符，并且会覆盖掉原来已有的字符。</li>
</ul>

<p>给你一个字符串 <code>s</code> ，你的任务是计算这个打印机打印它需要的最少打印次数。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabbb"
<strong>输出：</strong>2
<strong>解释：</strong>首先打印 "aaa" 然后打印 "bbb"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aba"
<strong>输出：</strong>2
<strong>解释：</strong>首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示打印完成区间 $s[i..j]$ 的最少操作数，初始时 $f[i][j]=\infty$，答案为 $f[0][n-1]$，其中 $n$ 是字符串 $s$ 的长度。

考虑 $f[i][j]$，如果 $s[i] = s[j]$，那么我们在打印 $s[i]$ 时可以顺便打印 $s[j]$，这样我们即可忽略字符 $s[j]$，在区间 $s[i+1..j-1]$ 内继续进行打印。如果 $s[i] \neq s[j]$，那么我们需要分别完成该区间的打印，即使用 $s[i..k]$ 和 $s[k+1..j]$，其中 $k \in [i,j)$。于是我们可以列出如下的转移方程：

$$
f[i][j]=
\begin{cases}
1, & \textit{if } i=j \\
f[i][j-1], & \textit{if } s[i]=s[j] \\
\min_{i \leq k < j} \{f[i][k]+f[k+1][j]\}, & \textit{otherwise}
\end{cases}
$$

在枚举时，我们可以从大到小枚举 $i$，从小到大枚举 $j$，这样可以保证在计算 $f[i][j]$ 时，状态 $f[i][j-1]$ 和 $f[i][k]$ 以及 $f[k+1][j]$ 都已经被计算过。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        f = [[inf] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            f[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i][j - 1]
                else:
                    for k in range(i, j):
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j])
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int strangePrinter(String s) {
        final int inf = 1 << 30;
        int n = s.length();
        int[][] f = new int[n][n];
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0x3f, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func strangePrinter(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = 1 << 30
		}
	}
	for i := n - 1; i >= 0; i-- {
		f[i][i] = 1
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i][j-1]
			} else {
				for k := i; k < j; k++ {
					f[i][j] = min(f[i][j], f[i][k]+f[k+1][j])
				}
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function strangePrinter(s: string): number {
    const n = s.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(1 << 30));
    for (let i = n - 1; i >= 0; --i) {
        f[i][i] = 1;
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i][j - 1];
            } else {
                for (let k = i; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [665. 非递减数列](https://leetcode.cn/problems/non-decreasing-array){#665}

{{< tabs "665" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        def is_sorted(nums: List[int]) -> bool:
            return all(a <= b for a, b in pairwise(nums))

        n = len(nums)
        for i in range(n - 1):
            a, b = nums[i], nums[i + 1]
            if a > b:
                nums[i] = b
                if is_sorted(nums):
                    return True
                nums[i] = nums[i + 1] = a
                return is_sorted(nums)
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        for (int i = 0; i < nums.length - 1; ++i) {
            int a = nums[i], b = nums[i + 1];
            if (a > b) {
                nums[i] = b;
                if (isSorted(nums)) {
                    return true;
                }
                nums[i] = a;
                nums[i + 1] = a;
                return isSorted(nums);
            }
        }
        return true;
    }

    private boolean isSorted(int[] nums) {
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
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
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i], b = nums[i + 1];
            if (a > b) {
                nums[i] = b;
                if (is_sorted(nums.begin(), nums.end())) {
                    return true;
                }
                nums[i] = a;
                nums[i + 1] = a;
                return is_sorted(nums.begin(), nums.end());
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkPossibility(nums []int) bool {
	isSorted := func(nums []int) bool {
		for i, b := range nums[1:] {
			if nums[i] > b {
				return false
			}
		}
		return true
	}
	for i := 0; i < len(nums)-1; i++ {
		a, b := nums[i], nums[i+1]
		if a > b {
			nums[i] = b
			if isSorted(nums) {
				return true
			}
			nums[i] = a
			nums[i+1] = a
			return isSorted(nums)
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkPossibility(nums: number[]): boolean {
    const isSorted = (nums: number[]) => {
        for (let i = 0; i < nums.length - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0; i < nums.length - 1; ++i) {
        const a = nums[i],
            b = nums[i + 1];
        if (a > b) {
            nums[i] = b;
            if (isSorted(nums)) {
                return true;
            }
            nums[i] = a;
            nums[i + 1] = a;
            return isSorted(nums);
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

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的整数数组<meta charset="UTF-8" />&nbsp;<code>nums</code>&nbsp;，请你判断在 <strong>最多 </strong>改变&nbsp;<code>1</code> 个元素的情况下，该数组能否变成一个非递减数列。</p>

<p>我们是这样定义一个非递减数列的：&nbsp;对于数组中任意的&nbsp;<code>i</code> <code>(0 &lt;= i &lt;= n-2)</code>，总满足 <code>nums[i] &lt;= nums[i + 1]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,2,3]
<strong>输出:</strong> true
<strong>解释:</strong> 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,2,1]
<strong>输出:</strong> false
<strong>解释:</strong> 你不能在只改变一个元素的情况下将其变为非递减数列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

在最多改变一个元素的情况下，若要将数组变成非递减数列，那么数组最多只能有一个位置，其左右两侧的元素不满足非递减数列的要求。也即数组中只会存在一个位置 $i$，使得 $nums[i] \gt nums[i+1]$。

因此，我们可以从左到右遍历数组，找到第一个不满足非递减数列要求的位置 $i$，然后将 $nums[i]$ 修改为 $nums[i+1]$ 或者将 $nums[i+1]$ 修改为 $nums[i]$，再判断修改后的数组是否满足非递减数列的要求。如果满足，则返回 `true`，否则返回 `false`。

遍历结束后，如果没有找到不满足非递减数列要求的位置，说明数组本身就是非递减数列，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        def is_sorted(nums: List[int]) -> bool:
            return all(a <= b for a, b in pairwise(nums))

        n = len(nums)
        for i in range(n - 1):
            a, b = nums[i], nums[i + 1]
            if a > b:
                nums[i] = b
                if is_sorted(nums):
                    return True
                nums[i] = nums[i + 1] = a
                return is_sorted(nums)
        return True
```

#### Java

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        for (int i = 0; i < nums.length - 1; ++i) {
            int a = nums[i], b = nums[i + 1];
            if (a > b) {
                nums[i] = b;
                if (isSorted(nums)) {
                    return true;
                }
                nums[i] = a;
                nums[i + 1] = a;
                return isSorted(nums);
            }
        }
        return true;
    }

    private boolean isSorted(int[] nums) {
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
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
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i], b = nums[i + 1];
            if (a > b) {
                nums[i] = b;
                if (is_sorted(nums.begin(), nums.end())) {
                    return true;
                }
                nums[i] = a;
                nums[i + 1] = a;
                return is_sorted(nums.begin(), nums.end());
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkPossibility(nums []int) bool {
	isSorted := func(nums []int) bool {
		for i, b := range nums[1:] {
			if nums[i] > b {
				return false
			}
		}
		return true
	}
	for i := 0; i < len(nums)-1; i++ {
		a, b := nums[i], nums[i+1]
		if a > b {
			nums[i] = b
			if isSorted(nums) {
				return true
			}
			nums[i] = a
			nums[i+1] = a
			return isSorted(nums)
		}
	}
	return true
}
```

#### TypeScript

```ts
function checkPossibility(nums: number[]): boolean {
    const isSorted = (nums: number[]) => {
        for (let i = 0; i < nums.length - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0; i < nums.length - 1; ++i) {
        const a = nums[i],
            b = nums[i + 1];
        if (a > b) {
            nums[i] = b;
            if (isSorted(nums)) {
                return true;
            }
            nums[i] = a;
            nums[i + 1] = a;
            return isSorted(nums);
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

# [666. 路径总和 IV 🔒](https://leetcode.cn/problems/path-sum-iv){#666}

{{< tabs "666" >}}

{{% tab "python" %}}
```python
class Solution:
    def pathSum(self, nums: List[int]) -> int:
        def dfs(node, t):
            if node not in mp:
                return
            t += mp[node]
            d, p = divmod(node, 10)
            l = (d + 1) * 10 + (p * 2) - 1
            r = l + 1
            nonlocal ans
            if l not in mp and r not in mp:
                ans += t
                return
            dfs(l, t)
            dfs(r, t)

        ans = 0
        mp = {num // 10: num % 10 for num in nums}
        dfs(11, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int ans;
    private Map<Integer, Integer> mp;

    public int pathSum(int[] nums) {
        ans = 0;
        mp = new HashMap<>(nums.length);
        for (int num : nums) {
            mp.put(num / 10, num % 10);
        }
        dfs(11, 0);
        return ans;
    }

    private void dfs(int node, int t) {
        if (!mp.containsKey(node)) {
            return;
        }
        t += mp.get(node);
        int d = node / 10, p = node % 10;
        int l = (d + 1) * 10 + (p * 2) - 1;
        int r = l + 1;
        if (!mp.containsKey(l) && !mp.containsKey(r)) {
            ans += t;
            return;
        }
        dfs(l, t);
        dfs(r, t);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int ans;
    unordered_map<int, int> mp;

    int pathSum(vector<int>& nums) {
        ans = 0;
        mp.clear();
        for (int num : nums) mp[num / 10] = num % 10;
        dfs(11, 0);
        return ans;
    }

    void dfs(int node, int t) {
        if (!mp.count(node)) return;
        t += mp[node];
        int d = node / 10, p = node % 10;
        int l = (d + 1) * 10 + (p * 2) - 1;
        int r = l + 1;
        if (!mp.count(l) && !mp.count(r)) {
            ans += t;
            return;
        }
        dfs(l, t);
        dfs(r, t);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pathSum(nums []int) int {
	ans := 0
	mp := make(map[int]int)
	for _, num := range nums {
		mp[num/10] = num % 10
	}
	var dfs func(node, t int)
	dfs = func(node, t int) {
		if v, ok := mp[node]; ok {
			t += v
			d, p := node/10, node%10
			l := (d+1)*10 + (p * 2) - 1
			r := l + 1
			if _, ok1 := mp[l]; !ok1 {
				if _, ok2 := mp[r]; !ok2 {
					ans += t
					return
				}
			}
			dfs(l, t)
			dfs(r, t)
		}
	}
	dfs(11, 0)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对于一棵深度小于&nbsp;<code>5</code>&nbsp;的树，可以用一组三位十进制整数来表示。给定一个由三位数组成的&nbsp;<strong>递增</strong>&nbsp;的数组&nbsp;<code>nums</code>&nbsp;表示一棵深度小于&nbsp;<code>5</code>&nbsp;的二叉树，对于每个整数：</p>

<ul>
	<li>百位上的数字表示这个节点的深度 <code>d</code>，<code>1 &lt;= d&nbsp;&lt;= 4</code>。</li>
	<li>十位上的数字表示这个节点在当前层所在的位置 <code>p</code>， <code>1 &lt;= p&nbsp;&lt;= 8</code>。位置编号与一棵 <strong>满二叉树</strong> 的位置编号相同。</li>
	<li>个位上的数字表示这个节点的权值 <code>v</code>，<code>0 &lt;= v&nbsp;&lt;= 9</code>。</li>
</ul>

<p>返回从&nbsp;<strong>根&nbsp;</strong>到所有 <strong>叶子结点</strong> 的 <strong>路径</strong> 之 <strong>和</strong>。</p>

<p><strong>保证&nbsp;</strong>给定的数组表示一个有效的连接二叉树。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0666.Path%20Sum%20IV/images/pathsum4-1-tree.jpg" /></p>

<pre>
<strong>输入:</strong> nums = [113, 215, 221]
<strong>输出:</strong> 12
<strong>解释:</strong> 列表所表示的树如上所示。
路径和 = (3 + 5) + (3 + 1) = 12。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0666.Path%20Sum%20IV/images/pathsum4-2-tree.jpg" /></p>

<pre>
<strong>输入:</strong> nums = [113, 221]
<strong>输出:</strong> 4
<strong>解释:</strong> 列表所表示的树如上所示。
路径和 = (3 + 1) = 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 15</code></li>
	<li><code>110 &lt;= nums[i] &lt;= 489</code></li>
	<li><code>nums</code>&nbsp;表示深度小于&nbsp;<code>5</code> 的有效二叉树</li>
	<li><code>nums</code>&nbsp;以升序排序。</li>
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
    def pathSum(self, nums: List[int]) -> int:
        def dfs(node, t):
            if node not in mp:
                return
            t += mp[node]
            d, p = divmod(node, 10)
            l = (d + 1) * 10 + (p * 2) - 1
            r = l + 1
            nonlocal ans
            if l not in mp and r not in mp:
                ans += t
                return
            dfs(l, t)
            dfs(r, t)

        ans = 0
        mp = {num // 10: num % 10 for num in nums}
        dfs(11, 0)
        return ans
```

#### Java

```java
class Solution {
    private int ans;
    private Map<Integer, Integer> mp;

    public int pathSum(int[] nums) {
        ans = 0;
        mp = new HashMap<>(nums.length);
        for (int num : nums) {
            mp.put(num / 10, num % 10);
        }
        dfs(11, 0);
        return ans;
    }

    private void dfs(int node, int t) {
        if (!mp.containsKey(node)) {
            return;
        }
        t += mp.get(node);
        int d = node / 10, p = node % 10;
        int l = (d + 1) * 10 + (p * 2) - 1;
        int r = l + 1;
        if (!mp.containsKey(l) && !mp.containsKey(r)) {
            ans += t;
            return;
        }
        dfs(l, t);
        dfs(r, t);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int ans;
    unordered_map<int, int> mp;

    int pathSum(vector<int>& nums) {
        ans = 0;
        mp.clear();
        for (int num : nums) mp[num / 10] = num % 10;
        dfs(11, 0);
        return ans;
    }

    void dfs(int node, int t) {
        if (!mp.count(node)) return;
        t += mp[node];
        int d = node / 10, p = node % 10;
        int l = (d + 1) * 10 + (p * 2) - 1;
        int r = l + 1;
        if (!mp.count(l) && !mp.count(r)) {
            ans += t;
            return;
        }
        dfs(l, t);
        dfs(r, t);
    }
};
```

#### Go

```go
func pathSum(nums []int) int {
	ans := 0
	mp := make(map[int]int)
	for _, num := range nums {
		mp[num/10] = num % 10
	}
	var dfs func(node, t int)
	dfs = func(node, t int) {
		if v, ok := mp[node]; ok {
			t += v
			d, p := node/10, node%10
			l := (d+1)*10 + (p * 2) - 1
			r := l + 1
			if _, ok1 := mp[l]; !ok1 {
				if _, ok2 := mp[r]; !ok2 {
					ans += t
					return
				}
			}
			dfs(l, t)
			dfs(r, t)
		}
	}
	dfs(11, 0)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [667. 优美的排列 II](https://leetcode.cn/problems/beautiful-arrangement-ii){#667}

{{< tabs "667" >}}

{{% tab "python" %}}
```python
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        l, r = 1, n
        ans = []
        for i in range(k):
            if i % 2 == 0:
                ans.append(l)
                l += 1
            else:
                ans.append(r)
                r -= 1
        for i in range(k, n):
            if k % 2 == 0:
                ans.append(r)
                r -= 1
            else:
                ans.append(l)
                l += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] constructArray(int n, int k) {
        int l = 1, r = n;
        int[] ans = new int[n];
        for (int i = 0; i < k; ++i) {
            ans[i] = i % 2 == 0 ? l++ : r--;
        }
        for (int i = k; i < n; ++i) {
            ans[i] = k % 2 == 0 ? r-- : l++;
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
    vector<int> constructArray(int n, int k) {
        int l = 1, r = n;
        vector<int> ans(n);
        for (int i = 0; i < k; ++i) {
            ans[i] = i % 2 == 0 ? l++ : r--;
        }
        for (int i = k; i < n; ++i) {
            ans[i] = k % 2 == 0 ? r-- : l++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func constructArray(n int, k int) []int {
	l, r := 1, n
	ans := make([]int, n)
	for i := 0; i < k; i++ {
		if i%2 == 0 {
			ans[i] = l
			l++
		} else {
			ans[i] = r
			r--
		}
	}
	for i := k; i < n; i++ {
		if k%2 == 0 {
			ans[i] = r
			r--
		} else {
			ans[i] = l
			l++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function constructArray(n: number, k: number): number[] {
    let l = 1;
    let r = n;
    const ans = new Array(n);
    for (let i = 0; i < k; ++i) {
        ans[i] = i % 2 == 0 ? l++ : r--;
    }
    for (let i = k; i < n; ++i) {
        ans[i] = k % 2 == 0 ? r-- : l++;
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

<p>给你两个整数 <code>n</code> 和 <code>k</code> ，请你构造一个答案列表 <code>answer</code> ，该列表应当包含从 <code>1</code> 到 <code>n</code> 的 <code>n</code> 个不同正整数，并同时满足下述条件：</p>

<ul>
	<li>假设该列表是 <code>answer = [a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ... , a<sub>n</sub>]</code> ，那么列表 <code>[|a<sub>1</sub> - a<sub>2</sub>|, |a<sub>2</sub> - a<sub>3</sub>|, |a<sub>3</sub> - a<sub>4</sub>|, ... , |a<sub>n-1</sub> - a<sub>n</sub>|]</code> 中应该有且仅有 <code>k</code> 个不同整数。</li>
</ul>

<p>返回列表 <code>answer</code> 。如果存在多种答案，只需返回其中 <strong>任意一种</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>[1, 2, 3]
<strong>解释：</strong>[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 2
<strong>输出：</strong>[1, 3, 2]
<strong>解释：</strong>[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k < n <= 10<sup>4</sup></code></li>
</ul>

<p> </p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：构造

先按照 `1, n, 2, n-1, 3,...` 构造答案数据 `ans` 的前 $k$ 个数，共产生 $k-1$ 个不同的整数。然后根据 $k$ 的奇偶性确定从哪个数开始构造下一个数。

时间复杂度 $O(n)$，忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        l, r = 1, n
        ans = []
        for i in range(k):
            if i % 2 == 0:
                ans.append(l)
                l += 1
            else:
                ans.append(r)
                r -= 1
        for i in range(k, n):
            if k % 2 == 0:
                ans.append(r)
                r -= 1
            else:
                ans.append(l)
                l += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] constructArray(int n, int k) {
        int l = 1, r = n;
        int[] ans = new int[n];
        for (int i = 0; i < k; ++i) {
            ans[i] = i % 2 == 0 ? l++ : r--;
        }
        for (int i = k; i < n; ++i) {
            ans[i] = k % 2 == 0 ? r-- : l++;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int l = 1, r = n;
        vector<int> ans(n);
        for (int i = 0; i < k; ++i) {
            ans[i] = i % 2 == 0 ? l++ : r--;
        }
        for (int i = k; i < n; ++i) {
            ans[i] = k % 2 == 0 ? r-- : l++;
        }
        return ans;
    }
};
```

#### Go

```go
func constructArray(n int, k int) []int {
	l, r := 1, n
	ans := make([]int, n)
	for i := 0; i < k; i++ {
		if i%2 == 0 {
			ans[i] = l
			l++
		} else {
			ans[i] = r
			r--
		}
	}
	for i := k; i < n; i++ {
		if k%2 == 0 {
			ans[i] = r
			r--
		} else {
			ans[i] = l
			l++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function constructArray(n: number, k: number): number[] {
    let l = 1;
    let r = n;
    const ans = new Array(n);
    for (let i = 0; i < k; ++i) {
        ans[i] = i % 2 == 0 ? l++ : r--;
    }
    for (let i = k; i < n; ++i) {
        ans[i] = k % 2 == 0 ? r-- : l++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [668. 乘法表中第k小的数](https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table){#668}

{{< tabs "668" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        left, right = 1, m * n
        while left < right:
            mid = (left + right) >> 1
            cnt = 0
            for i in range(1, m + 1):
                cnt += min(mid // i, n)
            if cnt >= k:
                right = mid
            else:
                left = mid + 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += Math.min(mid / i, n);
            }
            if (cnt >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) cnt += min(mid / i, n);
            if (cnt >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthNumber(m int, n int, k int) int {
	left, right := 1, m*n
	for left < right {
		mid := (left + right) >> 1
		cnt := 0
		for i := 1; i <= m; i++ {
			cnt += min(mid/i, n)
		}
		if cnt >= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>几乎每一个人都用&nbsp;<a href="https://baike.baidu.com/item/%E4%B9%98%E6%B3%95%E8%A1%A8">乘法表</a>。但是你能在乘法表中快速找到第 <code>k</code> 小的数字吗？</p>

<p>乘法表是大小为 <code>m x n</code> 的一个整数矩阵，其中&nbsp;<code>mat[i][j] == i * j</code>（下标从 <strong>1</strong> 开始）。</p>

<p>给你三个整数 <code>m</code>、<code>n</code> 和 <code>k</code>，请你在大小为&nbsp;<code>m x n</code> 的乘法表中，找出并返回第 <code>k</code>&nbsp;小的数字。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0668.Kth%20Smallest%20Number%20in%20Multiplication%20Table/images/multtable1-grid.jpg" style="width: 500px; height: 254px;" />
<pre>
<strong>输入：</strong>m = 3, n = 3, k = 5
<strong>输出：</strong>3
<strong>解释：</strong>第 5 小的数字是 3 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0668.Kth%20Smallest%20Number%20in%20Multiplication%20Table/images/multtable2-grid.jpg" style="width: 493px; height: 293px;" />
<pre>
<strong>输入：</strong>m = 2, n = 3, k = 6
<strong>输出：</strong>6
<strong>解释：</strong>第 6 小的数字是 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
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

### 方法一：二分查找

题目可以转换为，求有多少个数不超过 x。对于每一行 i，所有数都是 i 的倍数，不超过 x 的个数有 `x / i` 个。

二分枚举 x，累加每一行不超过 x 的个数，得到 cnt。找到 `cnt >= k` 的最小 x。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        left, right = 1, m * n
        while left < right:
            mid = (left + right) >> 1
            cnt = 0
            for i in range(1, m + 1):
                cnt += min(mid // i, n)
            if cnt >= k:
                right = mid
            else:
                left = mid + 1
        return left
```

#### Java

```java
class Solution {
    public int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += Math.min(mid / i, n);
            }
            if (cnt >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) cnt += min(mid / i, n);
            if (cnt >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```

#### Go

```go
func findKthNumber(m int, n int, k int) int {
	left, right := 1, m*n
	for left < right {
		mid := (left + right) >> 1
		cnt := 0
		for i := 1; i <= m; i++ {
			cnt += min(mid/i, n)
		}
		if cnt >= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [669. 修剪二叉搜索树](https://leetcode.cn/problems/trim-a-binary-search-tree){#669}

{{< tabs "669" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(
        self, root: Optional[TreeNode], low: int, high: int
    ) -> Optional[TreeNode]:
        while root and (root.val < low or root.val > high):
            root = root.left if root.val > high else root.right
        if root is None:
            return None
        node = root
        while node.left:
            if node.left.val < low:
                node.left = node.left.right
            else:
                node = node.left
        node = root
        while node.right:
            if node.right.val > high:
                node.right = node.right.left
            else:
                node = node.right
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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        while (root != null && (root.val < low || root.val > high)) {
            root = root.val < low ? root.right : root.left;
        }
        if (root == null) {
            return null;
        }
        TreeNode node = root;
        while (node.left != null) {
            if (node.left.val < low) {
                node.left = node.left.right;
            } else {
                node = node.left;
            }
        }
        node = root;
        while (node.right != null) {
            if (node.right.val > high) {
                node.right = node.right.left;
            } else {
                node = node.right;
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root && (root->val < low || root->val > high)) {
            root = root->val < low ? root->right : root->left;
        }
        if (!root) {
            return root;
        }
        TreeNode* node = root;
        while (node->left) {
            if (node->left->val < low) {
                node->left = node->left->right;
            } else {
                node = node->left;
            }
        }
        node = root;
        while (node->right) {
            if (node->right->val > high) {
                node->right = node->right->left;
            } else {
                node = node->right;
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
func trimBST(root *TreeNode, low int, high int) *TreeNode {
	for root != nil && (root.Val < low || root.Val > high) {
		if root.Val < low {
			root = root.Right
		} else {
			root = root.Left
		}
	}
	if root == nil {
		return nil
	}
	node := root
	for node.Left != nil {
		if node.Left.Val < low {
			node.Left = node.Left.Right
		} else {
			node = node.Left
		}
	}
	node = root
	for node.Right != nil {
		if node.Right.Val > high {
			node.Right = node.Right.Left
		} else {
			node = node.Right
		}
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

function trimBST(root: TreeNode | null, low: number, high: number): TreeNode | null {
    const dfs = (root: TreeNode | null) => {
        if (root == null) {
            return root;
        }
        const { val, left, right } = root;
        if (val < low || val > high) {
            return dfs(left) || dfs(right);
        }
        root.left = dfs(left);
        root.right = dfs(right);
        return root;
    };
    return dfs(root);
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
    pub fn trim_bst(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        low: i32,
        high: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return root;
        }
        {
            let mut node = root.as_mut().unwrap().borrow_mut();
            if node.val < low {
                return Self::trim_bst(node.right.take(), low, high);
            }
            if node.val > high {
                return Self::trim_bst(node.left.take(), low, high);
            }
            node.left = Self::trim_bst(node.left.take(), low, high);
            node.right = Self::trim_bst(node.right.take(), low, high);
        }
        root
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
 * @param {number} low
 * @param {number} high
 * @return {TreeNode}
 */
var trimBST = function (root, low, high) {
    while (root && (root.val < low || root.val > high)) {
        root = root.val < low ? root.right : root.left;
    }
    if (!root) {
        return root;
    }
    let node = root;
    while (node.left) {
        if (node.left.val < low) {
            node.left = node.left.right;
        } else {
            node = node.left;
        }
    }
    node = root;
    while (node.right) {
        if (node.right.val > high) {
            node.right = node.right.left;
        } else {
            node = node.right;
        }
    }
    return root;
};
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

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (!root) {
        return root;
    }
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你二叉搜索树的根节点 <code>root</code> ，同时给定最小边界<code>low</code> 和最大边界 <code>high</code>。通过修剪二叉搜索树，使得所有节点的值在<code>[low, high]</code>中。修剪树 <strong>不应该</strong>&nbsp;改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在&nbsp;<strong>唯一的答案</strong>&nbsp;。</p>

<p>所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0669.Trim%20a%20Binary%20Search%20Tree/images/trim1.jpg" style="height: 126px; width: 450px;" />
<pre>
<strong>输入：</strong>root = [1,0,2], low = 1, high = 2
<strong>输出：</strong>[1,null,2]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0669.Trim%20a%20Binary%20Search%20Tree/images/trim2.jpg" style="height: 277px; width: 450px;" />
<pre>
<strong>输入：</strong>root = [3,0,4,null,2,null,null,1], low = 1, high = 3
<strong>输出：</strong>[3,2,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>树中每个节点的值都是 <strong>唯一</strong> 的</li>
	<li>题目数据保证输入是一棵有效的二叉搜索树</li>
	<li><code>0 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

判断 `root.val` 与 `low` 和 `high` 的大小关系：

-   若 `root.val` 大于 `high`，说明当前 `root` 节点与其右子树所有节点的值均大于 `high`，那么递归修剪 `root.left` 即可；
-   若 `root.val` 小于 `low`，说明当前 `root` 节点与其左子树所有节点的值均小于 `low`，那么递归修剪 `root.right` 即可；
-   若 `root.val` 在 `[low, high]` 之间，说明当前 `root` 应该保留，递归修剪 `root.left`, `root.right`，并且返回 `root`。

递归的终止条件是 `root` 节点为空。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点个数。

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
    def trimBST(
        self, root: Optional[TreeNode], low: int, high: int
    ) -> Optional[TreeNode]:
        def dfs(root):
            if root is None:
                return root
            if root.val > high:
                return dfs(root.left)
            if root.val < low:
                return dfs(root.right)
            root.left = dfs(root.left)
            root.right = dfs(root.right)
            return root

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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        if (root == null) {
            return root;
        }
        if (root.val > high) {
            return trimBST(root.left, low, high);
        }
        if (root.val < low) {
            return trimBST(root.right, low, high);
        }
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return root;
        if (root->val > high) return trimBST(root->left, low, high);
        if (root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
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
func trimBST(root *TreeNode, low int, high int) *TreeNode {
	if root == nil {
		return root
	}
	if root.Val > high {
		return trimBST(root.Left, low, high)
	}
	if root.Val < low {
		return trimBST(root.Right, low, high)
	}
	root.Left = trimBST(root.Left, low, high)
	root.Right = trimBST(root.Right, low, high)
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

function trimBST(root: TreeNode | null, low: number, high: number): TreeNode | null {
    const dfs = (root: TreeNode | null) => {
        if (root == null) {
            return root;
        }
        const { val, left, right } = root;
        if (val < low || val > high) {
            return dfs(left) || dfs(right);
        }
        root.left = dfs(left);
        root.right = dfs(right);
        return root;
    };
    return dfs(root);
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
    pub fn trim_bst(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        low: i32,
        high: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return root;
        }
        {
            let mut node = root.as_mut().unwrap().borrow_mut();
            if node.val < low {
                return Self::trim_bst(node.right.take(), low, high);
            }
            if node.val > high {
                return Self::trim_bst(node.left.take(), low, high);
            }
            node.left = Self::trim_bst(node.left.take(), low, high);
            node.right = Self::trim_bst(node.right.take(), low, high);
        }
        root
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
 * @param {number} low
 * @param {number} high
 * @return {TreeNode}
 */
var trimBST = function (root, low, high) {
    function dfs(root) {
        if (!root) {
            return root;
        }
        if (root.val < low) {
            return dfs(root.right);
        }
        if (root.val > high) {
            return dfs(root.left);
        }
        root.left = dfs(root.left);
        root.right = dfs(root.right);
        return root;
    }
    return dfs(root);
};
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

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (!root) {
        return root;
    }
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代

我们先循环判断 `root`，若 `root.val` 不在 `[low, high]` 之间，那么直接将 `root` 置为对应的左孩子或右孩子，循环直至 `root` 为空或者 `root.val` 在 `[low, high]` 之间。

若此时 `root` 为空，直接返回。否则，说明 `root` 是一个需要保留的节点。接下来只需要分别迭代修剪 `root` 的左右子树。

以左子树 `node = root.left` 为例：

-   若 `node.left.val` 小于 `low`，那么 `node.left` 及其左孩子均不满足条件，我们直接将 `node.left` 置为 `node.left.right`；
-   否则，我们将 `node` 置为 `node.left`；
-   循环判断，直至 `node.left` 为空。

右子树的修剪过程与之类似。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是二叉搜索树的节点个数。

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
    def trimBST(
        self, root: Optional[TreeNode], low: int, high: int
    ) -> Optional[TreeNode]:
        while root and (root.val < low or root.val > high):
            root = root.left if root.val > high else root.right
        if root is None:
            return None
        node = root
        while node.left:
            if node.left.val < low:
                node.left = node.left.right
            else:
                node = node.left
        node = root
        while node.right:
            if node.right.val > high:
                node.right = node.right.left
            else:
                node = node.right
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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        while (root != null && (root.val < low || root.val > high)) {
            root = root.val < low ? root.right : root.left;
        }
        if (root == null) {
            return null;
        }
        TreeNode node = root;
        while (node.left != null) {
            if (node.left.val < low) {
                node.left = node.left.right;
            } else {
                node = node.left;
            }
        }
        node = root;
        while (node.right != null) {
            if (node.right.val > high) {
                node.right = node.right.left;
            } else {
                node = node.right;
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root && (root->val < low || root->val > high)) {
            root = root->val < low ? root->right : root->left;
        }
        if (!root) {
            return root;
        }
        TreeNode* node = root;
        while (node->left) {
            if (node->left->val < low) {
                node->left = node->left->right;
            } else {
                node = node->left;
            }
        }
        node = root;
        while (node->right) {
            if (node->right->val > high) {
                node->right = node->right->left;
            } else {
                node = node->right;
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
func trimBST(root *TreeNode, low int, high int) *TreeNode {
	for root != nil && (root.Val < low || root.Val > high) {
		if root.Val < low {
			root = root.Right
		} else {
			root = root.Left
		}
	}
	if root == nil {
		return nil
	}
	node := root
	for node.Left != nil {
		if node.Left.Val < low {
			node.Left = node.Left.Right
		} else {
			node = node.Left
		}
	}
	node = root
	for node.Right != nil {
		if node.Right.Val > high {
			node.Right = node.Right.Left
		} else {
			node = node.Right
		}
	}
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
 * @param {number} low
 * @param {number} high
 * @return {TreeNode}
 */
var trimBST = function (root, low, high) {
    while (root && (root.val < low || root.val > high)) {
        root = root.val < low ? root.right : root.left;
    }
    if (!root) {
        return root;
    }
    let node = root;
    while (node.left) {
        if (node.left.val < low) {
            node.left = node.left.right;
        } else {
            node = node.left;
        }
    }
    node = root;
    while (node.right) {
        if (node.right.val > high) {
            node.right = node.right.left;
        } else {
            node = node.right;
        }
    }
    return root;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
