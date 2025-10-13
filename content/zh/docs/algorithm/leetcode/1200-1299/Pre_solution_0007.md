---
title: "1260_二维网格迁移"
date: 2025-10-08T18:37:06+08:00
weight: 7
tags: [二分查找, 二叉树, 几何, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字典树, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 树, 模拟, 深度优先搜索, 矩阵, 计数, 设计, 贪心, 递归, 链表]
---

{{< markmap >}}
### [1260_二维网格迁移](#1260)
#### [数组](#1260)
#### [矩阵](#1260)
#### [模拟](#1260)
### [1261_在受污染的二叉树中查找元素](#1261)
#### [树](#1261)
#### [深度优先搜索](#1261)
#### [广度优先搜索](#1261)
#### [设计](#1261)
#### [哈希表](#1261)
#### [二叉树](#1261)
### [1262_可被三整除的最大和](#1262)
#### [贪心](#1262)
#### [数组](#1262)
#### [动态规划](#1262)
#### [排序](#1262)
### [1263_推箱子](#1263)
#### [广度优先搜索](#1263)
#### [数组](#1263)
#### [矩阵](#1263)
#### [堆（优先队列）](#1263)
### [1264_页面推荐 🔒](#1264)
#### [数据库](#1264)
### [1265_逆序打印不可变链表 🔒](#1265)
#### [栈](#1265)
#### [递归](#1265)
#### [链表](#1265)
#### [双指针](#1265)
### [1266_访问所有点的最小时间](#1266)
#### [几何](#1266)
#### [数组](#1266)
#### [数学](#1266)
### [1267_统计参与通信的服务器](#1267)
#### [深度优先搜索](#1267)
#### [广度优先搜索](#1267)
#### [并查集](#1267)
#### [数组](#1267)
#### [计数](#1267)
#### [矩阵](#1267)
### [1268_搜索推荐系统](#1268)
#### [字典树](#1268)
#### [数组](#1268)
#### [字符串](#1268)
#### [二分查找](#1268)
#### [排序](#1268)
#### [堆（优先队列）](#1268)
### [1269_停在原地的方案数](#1269)
#### [动态规划](#1269)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1260_二维网格迁移
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 1261_在受污染的二叉树中查找元素
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 设计
___
#### 哈希表
___
#### 二叉树
---
### 1262_可被三整除的最大和
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 1263_推箱子
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 堆（优先队列）
---
### 1264_页面推荐 🔒
___
#### 数据库
---
### 1265_逆序打印不可变链表 🔒
___
#### 栈
___
#### 递归
___
#### 链表
___
#### 双指针
---
### 1266_访问所有点的最小时间
___
#### 几何
___
#### 数组
___
#### 数学
---
### 1267_统计参与通信的服务器
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 计数
___
#### 矩阵
---
### 1268_搜索推荐系统
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 二分查找
___
#### 排序
___
#### 堆（优先队列）
---
### 1269_停在原地的方案数
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 几何 |
| 动态规划 | 双指针 | 哈希表 |
| 堆（优先队列） | 字典树 | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 计数 |
| 设计 | 贪心 | 递归 |
| 链表 |  |  |

# [1260. 二维网格迁移](https://leetcode.cn/problems/shift-2d-grid){#1260}

{{< tabs "1260" >}}

{{% tab "python" %}}
```python
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * n for _ in range(m)]
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                x, y = divmod((i * n + j + k) % (m * n), n)
                ans[x][y] = v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                row.add(0);
            }
            ans.add(row);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j + k) % (m * n);
                int x = idx / n, y = idx % n;
                ans.get(x).set(y, grid[i][j]);
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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j + k) % (m * n);
                int x = idx / n, y = idx % n;
                ans[x][y] = grid[i][j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shiftGrid(grid [][]int, k int) [][]int {
	m, n := len(grid), len(grid[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			idx := (i*n + j + k) % (m * n)
			x, y := idx/n, idx%n
			ans[x][y] = grid[i][j]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shiftGrid(grid: number[][], k: number): number[][] {
    const [m, n] = [grid.length, grid[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            const idx = (i * n + j + k) % (m * n);
            const [x, y] = [Math.floor(idx / n), idx % n];
            ans[x][y] = grid[i][j];
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

<p>给你一个 <code>m</code> 行 <code>n</code>&nbsp;列的二维网格&nbsp;<code>grid</code>&nbsp;和一个整数&nbsp;<code>k</code>。你需要将&nbsp;<code>grid</code>&nbsp;迁移&nbsp;<code>k</code>&nbsp;次。</p>

<p>每次「迁移」操作将会引发下述活动：</p>

<ul>
	<li>位于 <code>grid[i][j]</code>（<code>j &lt; n - 1</code>）的元素将会移动到&nbsp;<code>grid[i][j + 1]</code>。</li>
	<li>位于&nbsp;<code>grid[i][n&nbsp;- 1]</code> 的元素将会移动到&nbsp;<code>grid[i + 1][0]</code>。</li>
	<li>位于 <code>grid[m&nbsp;- 1][n - 1]</code>&nbsp;的元素将会移动到&nbsp;<code>grid[0][0]</code>。</li>
</ul>

<p>请你返回&nbsp;<code>k</code> 次迁移操作后最终得到的 <strong>二维网格</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1260.Shift%202D%20Grid/images/e1-1.png" style="height: 158px; width: 400px;" /></p>

<pre>
<code><strong>输入：</strong>grid</code> = [[1,2,3],[4,5,6],[7,8,9]], k = 1
<strong>输出：</strong>[[9,1,2],[3,4,5],[6,7,8]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1260.Shift%202D%20Grid/images/e2-1.png" style="height: 166px; width: 400px;" /></p>

<pre>
<code><strong>输入：</strong>grid</code> = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
<strong>输出：</strong>[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<code><strong>输入：</strong>grid</code> = [[1,2,3],[4,5,6],[7,8,9]], k = 9
<strong>输出：</strong>[[1,2,3],[4,5,6],[7,8,9]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;grid.length</code></li>
	<li><code>n ==&nbsp;grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 50</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>-1000 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维数组展开

根据题目描述，如果我们将二维数组展开成一维数组，那么每次迁移操作就是将数组中的元素向右移动一个位置，最后一个元素移动到数组的首位。

因此，我们可以将二维数组展开成一维数组，然后计算每个元素在最后的位置 $idx = (x, y)$，更新答案数组 `ans[x][y] = grid[i][j]` 即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是二维数组 `grid` 的行数和列数。需要遍历二维数组 `grid` 一次，计算每个元素在最后的位置。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * n for _ in range(m)]
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                x, y = divmod((i * n + j + k) % (m * n), n)
                ans[x][y] = v
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                row.add(0);
            }
            ans.add(row);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j + k) % (m * n);
                int x = idx / n, y = idx % n;
                ans.get(x).set(y, grid[i][j]);
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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j + k) % (m * n);
                int x = idx / n, y = idx % n;
                ans[x][y] = grid[i][j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shiftGrid(grid [][]int, k int) [][]int {
	m, n := len(grid), len(grid[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			idx := (i*n + j + k) % (m * n)
			x, y := idx/n, idx%n
			ans[x][y] = grid[i][j]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function shiftGrid(grid: number[][], k: number): number[][] {
    const [m, n] = [grid.length, grid[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            const idx = (i * n + j + k) % (m * n);
            const [x, y] = [Math.floor(idx / n), idx % n];
            ans[x][y] = grid[i][j];
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

# [1261. 在受污染的二叉树中查找元素](https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree){#1261}

{{< tabs "1261" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        def dfs(root: Optional[TreeNode]):
            self.s.add(root.val)
            if root.left:
                root.left.val = root.val * 2 + 1
                dfs(root.left)
            if root.right:
                root.right.val = root.val * 2 + 2
                dfs(root.right)

        root.val = 0
        self.s = set()
        dfs(root)

    def find(self, target: int) -> bool:
        return target in self.s


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
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
class FindElements {
    private Set<Integer> s = new HashSet<>();

    public FindElements(TreeNode root) {
        root.val = 0;
        dfs(root);
    }

    public boolean find(int target) {
        return s.contains(target);
    }

    private void dfs(TreeNode root) {
        s.add(root.val);
        if (root.left != null) {
            root.left.val = root.val * 2 + 1;
            dfs(root.left);
        }
        if (root.right != null) {
            root.right.val = root.val * 2 + 2;
            dfs(root.right);
        }
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
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
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);
    }

    bool find(int target) {
        return s.contains(target);
    }

private:
    unordered_set<int> s;

    void dfs(TreeNode* root) {
        s.insert(root->val);
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            dfs(root->left);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            dfs(root->right);
        }
    };
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
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
type FindElements struct {
	s map[int]bool
}

func Constructor(root *TreeNode) FindElements {
	root.Val = 0
	s := map[int]bool{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		s[root.Val] = true
		if root.Left != nil {
			root.Left.Val = root.Val*2 + 1
			dfs(root.Left)
		}
		if root.Right != nil {
			root.Right.Val = root.Val*2 + 2
			dfs(root.Right)
		}
	}
	dfs(root)
	return FindElements{s}
}

func (this *FindElements) Find(target int) bool {
	return this.s[target]
}

/**
 * Your FindElements object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Find(target);
 */
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

class FindElements {
    readonly #s = new Set<number>();

    constructor(root: TreeNode | null) {
        root.val = 0;

        const dfs = (node: TreeNode | null, x = 0) => {
            if (!node) return;

            this.#s.add(x);
            dfs(node.left, x * 2 + 1);
            dfs(node.right, x * 2 + 2);
        };

        dfs(root);
    }

    find(target: number): boolean {
        return this.#s.has(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
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

const s = Symbol.for('s');

/**
 * @param {TreeNode} root
 */
var FindElements = function (root) {
    root.val = 0;
    this[s] = new Set();

    const dfs = (node, x = 0) => {
        if (!node) return;

        this[s].add(x);
        dfs(node.left, x * 2 + 1);
        dfs(node.right, x * 2 + 2);
    };

    dfs(root);
};

/**
 * @param {number} target
 * @return {boolean}
 */
FindElements.prototype.find = function (target) {
    return this[s].has(target);
};

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个满足下述规则的二叉树：</p>

<ol>
	<li><code>root.val == 0</code></li>
	<li>对于任意 <code>treeNode</code>：
	<ol type="a">
		<li>如果 <code>treeNode.val</code> 为&nbsp;<code>x</code> 且&nbsp;<code>treeNode.left != null</code>，那么&nbsp;<code>treeNode.left.val == 2 * x + 1</code></li>
		<li>如果 <code>treeNode.val</code> 为&nbsp;<code>x</code> 且 <code>treeNode.right != null</code>，那么&nbsp;<code>treeNode.right.val == 2 * x + 2</code></li>
	</ol>
	</li>
</ol>

<p>现在这个二叉树受到「污染」，所有的&nbsp;<code>treeNode.val</code>&nbsp;都变成了&nbsp;<code>-1</code>。</p>

<p>请你先还原二叉树，然后实现&nbsp;<code>FindElements</code>&nbsp;类：</p>

<ul>
	<li><code>FindElements(TreeNode* root)</code>&nbsp;用受污染的二叉树初始化对象，你需要先把它还原。</li>
	<li><code>bool find(int target)</code>&nbsp;判断目标值&nbsp;<code>target</code>&nbsp;是否存在于还原后的二叉树中并返回结果。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1261.Find%20Elements%20in%20a%20Contaminated%20Binary%20Tree/images/untitled-diagram-4-1.jpg" style="height: 119px; width: 320px;" /></strong></p>

<pre>
<strong>输入：</strong>
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
<strong>输出：</strong>
[null,false,true]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True </pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1261.Find%20Elements%20in%20a%20Contaminated%20Binary%20Tree/images/untitled-diagram-4.jpg" style="height: 198px; width: 400px;" /></strong></p>

<pre>
<strong>输入：</strong>
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
<strong>输出：</strong>
[null,true,true,false]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False</pre>

<p><strong class="example">示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1261.Find%20Elements%20in%20a%20Contaminated%20Binary%20Tree/images/untitled-diagram-4-1-1.jpg" style="height: 274px; width: 306px;" /></strong></p>

<pre>
<strong>输入：</strong>
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
<strong>输出：</strong>
[null,true,false,false,true]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>TreeNode.val == -1</code></li>
	<li>二叉树的高度不超过&nbsp;<code>20</code></li>
	<li>节点的总数在&nbsp;<code>[1,&nbsp;10<sup>4</sup>]</code>&nbsp;之间</li>
	<li>调用&nbsp;<code>find()</code>&nbsp;的总次数在&nbsp;<code>[1,&nbsp;10<sup>4</sup>]</code>&nbsp;之间</li>
	<li><code>0 &lt;= target &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 哈希表

我们先通过 DFS 遍历二叉树，将节点值恢复为原来的值，并将所有节点值存入哈希表中。然后在查找时，只需要判断哈希表中是否存在目标值即可。

时间复杂度方面，初始化时需要遍历二叉树，时间复杂度为 $O(n)$，查找时只需要判断哈希表中是否存在目标值，时间复杂度为 $O(1)$。空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        def dfs(root: Optional[TreeNode]):
            self.s.add(root.val)
            if root.left:
                root.left.val = root.val * 2 + 1
                dfs(root.left)
            if root.right:
                root.right.val = root.val * 2 + 2
                dfs(root.right)

        root.val = 0
        self.s = set()
        dfs(root)

    def find(self, target: int) -> bool:
        return target in self.s


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
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
class FindElements {
    private Set<Integer> s = new HashSet<>();

    public FindElements(TreeNode root) {
        root.val = 0;
        dfs(root);
    }

    public boolean find(int target) {
        return s.contains(target);
    }

    private void dfs(TreeNode root) {
        s.add(root.val);
        if (root.left != null) {
            root.left.val = root.val * 2 + 1;
            dfs(root.left);
        }
        if (root.right != null) {
            root.right.val = root.val * 2 + 2;
            dfs(root.right);
        }
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
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
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);
    }

    bool find(int target) {
        return s.contains(target);
    }

private:
    unordered_set<int> s;

    void dfs(TreeNode* root) {
        s.insert(root->val);
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            dfs(root->left);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            dfs(root->right);
        }
    };
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
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
type FindElements struct {
	s map[int]bool
}

func Constructor(root *TreeNode) FindElements {
	root.Val = 0
	s := map[int]bool{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		s[root.Val] = true
		if root.Left != nil {
			root.Left.Val = root.Val*2 + 1
			dfs(root.Left)
		}
		if root.Right != nil {
			root.Right.Val = root.Val*2 + 2
			dfs(root.Right)
		}
	}
	dfs(root)
	return FindElements{s}
}

func (this *FindElements) Find(target int) bool {
	return this.s[target]
}

/**
 * Your FindElements object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Find(target);
 */
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

class FindElements {
    readonly #s = new Set<number>();

    constructor(root: TreeNode | null) {
        root.val = 0;

        const dfs = (node: TreeNode | null, x = 0) => {
            if (!node) return;

            this.#s.add(x);
            dfs(node.left, x * 2 + 1);
            dfs(node.right, x * 2 + 2);
        };

        dfs(root);
    }

    find(target: number): boolean {
        return this.#s.has(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
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

const s = Symbol.for('s');

/**
 * @param {TreeNode} root
 */
var FindElements = function (root) {
    root.val = 0;
    this[s] = new Set();

    const dfs = (node, x = 0) => {
        if (!node) return;

        this[s].add(x);
        dfs(node.left, x * 2 + 1);
        dfs(node.right, x * 2 + 2);
    };

    dfs(root);
};

/**
 * @param {number} target
 * @return {boolean}
 */
FindElements.prototype.find = function (target) {
    return this[s].has(target);
};

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1262. 可被三整除的最大和](https://leetcode.cn/problems/greatest-sum-divisible-by-three){#1262}

{{< tabs "1262" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        f = [0, -inf, -inf]
        for x in nums:
            g = f[:]
            for j in range(3):
                g[j] = max(f[j], f[(j - x) % 3] + x)
            f = g
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumDivThree(int[] nums) {
        final int inf = 1 << 30;
        int[] f = new int[] {0, -inf, -inf};
        for (int x : nums) {
            int[] g = f.clone();
            for (int j = 0; j < 3; ++j) {
                g[j] = Math.max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = g;
        }
        return f[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int inf = 1 << 30;
        vector<int> f = {0, -inf, -inf};
        for (int& x : nums) {
            vector<int> g = f;
            for (int j = 0; j < 3; ++j) {
                g[j] = max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = move(g);
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumDivThree(nums []int) int {
	const inf = 1 << 30
	f := [3]int{0, -inf, -inf}
	for _, x := range nums {
		g := [3]int{}
		for j := range f {
			g[j] = max(f[j], f[(j-x%3+3)%3]+x)
		}
		f = g
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumDivThree(nums: number[]): number {
    const inf = 1 << 30;
    const f: number[] = [0, -inf, -inf];
    for (const x of nums) {
        const g = [...f];
        for (let j = 0; j < 3; ++j) {
            f[j] = Math.max(g[j], g[(j - (x % 3) + 3) % 3] + x);
        }
    }
    return f[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，请你找出并返回能被三整除的元素 <strong>最大和</strong>。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,6,5,1,8]
<strong>输出：</strong>18
<strong>解释：</strong>选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4]
<strong>输出：</strong>0
<strong>解释：</strong>4 不能被 3 整除，所以无法选出数字，返回 0。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,4]
<strong>输出：</strong>12
<strong>解释：</strong>选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 个数中选取若干个数，使得这若干个数的和模 $3$ 余 $j$ 的最大值。初始时 $f[0][0]=0$，其余为 $-\infty$。

对于 $f[i][j]$，我们可以考虑第 $i$ 个数 $x$ 的状态：

-   如果我们不选 $x$，那么 $f[i][j]=f[i-1][j]$；
-   如果我们选 $x$，那么 $f[i][j]=f[i-1][(j-x \bmod 3 + 3)\bmod 3]+x$。

因此我们可以得到状态转移方程：

$$
f[i][j]=\max\{f[i-1][j],f[i-1][(j-x \bmod 3 + 3)\bmod 3]+x\}
$$

最终答案为 $f[n][0]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

注意到 $f[i][j]$ 的值只与 $f[i-1][j]$ 和 $f[i-1][(j-x \bmod 3 + 3)\bmod 3]$ 有关，因此我们可以使用滚动数组优化空间复杂度，使空间复杂度降低为 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[-inf] * 3 for _ in range(n + 1)]
        f[0][0] = 0
        for i, x in enumerate(nums, 1):
            for j in range(3):
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - x) % 3] + x)
        return f[n][0]
```

#### Java

```java
class Solution {
    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        final int inf = 1 << 30;
        int[][] f = new int[n + 1][3];
        f[0][1] = f[0][2] = -inf;
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            for (int j = 0; j < 3; ++j) {
                f[i][j] = Math.max(f[i - 1][j], f[i - 1][(j - x % 3 + 3) % 3] + x);
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
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1 << 30;
        int f[n + 1][3];
        f[0][0] = 0;
        f[0][1] = f[0][2] = -inf;
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            for (int j = 0; j < 3; ++j) {
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - x % 3 + 3) % 3] + x);
            }
        }
        return f[n][0];
    }
};
```

#### Go

```go
func maxSumDivThree(nums []int) int {
	n := len(nums)
	const inf = 1 << 30
	f := make([][3]int, n+1)
	f[0] = [3]int{0, -inf, -inf}
	for i, x := range nums {
		i++
		for j := 0; j < 3; j++ {
			f[i][j] = max(f[i-1][j], f[i-1][(j-x%3+3)%3]+x)
		}
	}
	return f[n][0]
}
```

#### TypeScript

```ts
function maxSumDivThree(nums: number[]): number {
    const n = nums.length;
    const inf = 1 << 30;
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(3).fill(-inf));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        const x = nums[i - 1];
        for (let j = 0; j < 3; ++j) {
            f[i][j] = Math.max(f[i - 1][j], f[i - 1][(j - (x % 3) + 3) % 3] + x);
        }
    }
    return f[n][0];
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
    def maxSumDivThree(self, nums: List[int]) -> int:
        f = [0, -inf, -inf]
        for x in nums:
            g = f[:]
            for j in range(3):
                g[j] = max(f[j], f[(j - x) % 3] + x)
            f = g
        return f[0]
```

#### Java

```java
class Solution {
    public int maxSumDivThree(int[] nums) {
        final int inf = 1 << 30;
        int[] f = new int[] {0, -inf, -inf};
        for (int x : nums) {
            int[] g = f.clone();
            for (int j = 0; j < 3; ++j) {
                g[j] = Math.max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = g;
        }
        return f[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int inf = 1 << 30;
        vector<int> f = {0, -inf, -inf};
        for (int& x : nums) {
            vector<int> g = f;
            for (int j = 0; j < 3; ++j) {
                g[j] = max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = move(g);
        }
        return f[0];
    }
};
```

#### Go

```go
func maxSumDivThree(nums []int) int {
	const inf = 1 << 30
	f := [3]int{0, -inf, -inf}
	for _, x := range nums {
		g := [3]int{}
		for j := range f {
			g[j] = max(f[j], f[(j-x%3+3)%3]+x)
		}
		f = g
	}
	return f[0]
}
```

#### TypeScript

```ts
function maxSumDivThree(nums: number[]): number {
    const inf = 1 << 30;
    const f: number[] = [0, -inf, -inf];
    for (const x of nums) {
        const g = [...f];
        for (let j = 0; j < 3; ++j) {
            f[j] = Math.max(g[j], g[(j - (x % 3) + 3) % 3] + x);
        }
    }
    return f[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1263. 推箱子](https://leetcode.cn/problems/minimum-moves-to-move-a-box-to-their-target-location){#1263}

{{< tabs "1263" >}}

{{% tab "python" %}}
```python
class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        def f(i: int, j: int) -> int:
            return i * n + j

        def check(i: int, j: int) -> bool:
            return 0 <= i < m and 0 <= j < n and grid[i][j] != "#"

        for i, row in enumerate(grid):
            for j, c in enumerate(row):
                if c == "S":
                    si, sj = i, j
                elif c == "B":
                    bi, bj = i, j
        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)
        q = deque([(f(si, sj), f(bi, bj), 0)])
        vis = [[False] * (m * n) for _ in range(m * n)]
        vis[f(si, sj)][f(bi, bj)] = True
        while q:
            s, b, d = q.popleft()
            bi, bj = b // n, b % n
            if grid[bi][bj] == "T":
                return d
            si, sj = s // n, s % n
            for a, b in pairwise(dirs):
                sx, sy = si + a, sj + b
                if not check(sx, sy):
                    continue
                if sx == bi and sy == bj:
                    bx, by = bi + a, bj + b
                    if not check(bx, by) or vis[f(sx, sy)][f(bx, by)]:
                        continue
                    vis[f(sx, sy)][f(bx, by)] = True
                    q.append((f(sx, sy), f(bx, by), d + 1))
                elif not vis[f(sx, sy)][f(bi, bj)]:
                    vis[f(sx, sy)][f(bi, bj)] = True
                    q.appendleft((f(sx, sy), f(bi, bj), d))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private char[][] grid;

    public int minPushBox(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int si = 0, sj = 0, bi = 0, bj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 'B') {
                    bi = i;
                    bj = j;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        Deque<int[]> q = new ArrayDeque<>();
        boolean[][] vis = new boolean[m * n][m * n];
        q.offer(new int[] {f(si, sj), f(bi, bj), 0});
        vis[f(si, sj)][f(bi, bj)] = true;
        while (!q.isEmpty()) {
            var p = q.poll();
            int d = p[2];
            bi = p[1] / n;
            bj = p[1] % n;
            if (grid[bi][bj] == 'T') {
                return d;
            }
            si = p[0] / n;
            sj = p[0] % n;
            for (int k = 0; k < 4; ++k) {
                int sx = si + dirs[k], sy = sj + dirs[k + 1];
                if (!check(sx, sy)) {
                    continue;
                }
                if (sx == bi && sy == bj) {
                    int bx = bi + dirs[k], by = bj + dirs[k + 1];
                    if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                        continue;
                    }
                    vis[f(sx, sy)][f(bx, by)] = true;
                    q.offer(new int[] {f(sx, sy), f(bx, by), d + 1});
                } else if (!vis[f(sx, sy)][f(bi, bj)]) {
                    vis[f(sx, sy)][f(bi, bj)] = true;
                    q.offerFirst(new int[] {f(sx, sy), f(bi, bj), d});
                }
            }
        }
        return -1;
    }

    private int f(int i, int j) {
        return i * n + j;
    }

    private boolean check(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#';
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int si, sj, bi, bj;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    si = i, sj = j;
                } else if (grid[i][j] == 'B') {
                    bi = i, bj = j;
                }
            }
        }
        auto f = [&](int i, int j) {
            return i * n + j;
        };
        auto check = [&](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#';
        };
        int dirs[5] = {-1, 0, 1, 0, -1};
        deque<tuple<int, int, int>> q;
        q.emplace_back(f(si, sj), f(bi, bj), 0);
        bool vis[m * n][m * n];
        memset(vis, false, sizeof(vis));
        vis[f(si, sj)][f(bi, bj)] = true;
        while (!q.empty()) {
            auto [s, b, d] = q.front();
            q.pop_front();
            si = s / n, sj = s % n;
            bi = b / n, bj = b % n;
            if (grid[bi][bj] == 'T') {
                return d;
            }
            for (int k = 0; k < 4; ++k) {
                int sx = si + dirs[k], sy = sj + dirs[k + 1];
                if (!check(sx, sy)) {
                    continue;
                }
                if (sx == bi && sy == bj) {
                    int bx = bi + dirs[k], by = bj + dirs[k + 1];
                    if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                        continue;
                    }
                    vis[f(sx, sy)][f(bx, by)] = true;
                    q.emplace_back(f(sx, sy), f(bx, by), d + 1);
                } else if (!vis[f(sx, sy)][f(bi, bj)]) {
                    vis[f(sx, sy)][f(bi, bj)] = true;
                    q.emplace_front(f(sx, sy), f(bi, bj), d);
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minPushBox(grid [][]byte) int {
	m, n := len(grid), len(grid[0])
	var si, sj, bi, bj int
	for i, row := range grid {
		for j, c := range row {
			if c == 'S' {
				si, sj = i, j
			} else if c == 'B' {
				bi, bj = i, j
			}
		}
	}
	f := func(i, j int) int {
		return i*n + j
	}
	check := func(i, j int) bool {
		return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#'
	}
	q := [][]int{[]int{f(si, sj), f(bi, bj), 0}}
	vis := make([][]bool, m*n)
	for i := range vis {
		vis[i] = make([]bool, m*n)
	}
	vis[f(si, sj)][f(bi, bj)] = true
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		si, sj, bi, bj = p[0]/n, p[0]%n, p[1]/n, p[1]%n
		d := p[2]
		if grid[bi][bj] == 'T' {
			return d
		}
		for k := 0; k < 4; k++ {
			sx, sy := si+dirs[k], sj+dirs[k+1]
			if !check(sx, sy) {
				continue
			}
			if sx == bi && sy == bj {
				bx, by := bi+dirs[k], bj+dirs[k+1]
				if !check(bx, by) || vis[f(sx, sy)][f(bx, by)] {
					continue
				}
				vis[f(sx, sy)][f(bx, by)] = true
				q = append(q, []int{f(sx, sy), f(bx, by), d + 1})
			} else if !vis[f(sx, sy)][f(bi, bj)] {
				vis[f(sx, sy)][f(bi, bj)] = true
				q = append([][]int{[]int{f(sx, sy), f(bi, bj), d}}, q...)
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minPushBox(grid: string[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    let [si, sj, bi, bj] = [0, 0, 0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 'S') {
                [si, sj] = [i, j];
            } else if (grid[i][j] === 'B') {
                [bi, bj] = [i, j];
            }
        }
    }
    const f = (i: number, j: number): number => i * n + j;
    const check = (i: number, j: number): boolean =>
        i >= 0 && i < m && j >= 0 && j < n && grid[i][j] !== '#';

    const q: Deque<[number, number, number]> = new Deque();
    const vis: boolean[][] = new Array(m * n).fill(0).map(() => new Array(m * n).fill(false));
    q.push([f(si, sj), f(bi, bj), 0]);
    vis[f(si, sj)][f(bi, bj)] = true;
    const dirs: number[] = [-1, 0, 1, 0, -1];
    while (q.size() > 0) {
        const [s, b, d] = q.shift()!;
        const [si, sj] = [Math.floor(s / n), s % n];
        const [bi, bj] = [Math.floor(b / n), b % n];
        if (grid[bi][bj] === 'T') {
            return d;
        }
        for (let k = 0; k < 4; ++k) {
            const [sx, sy] = [si + dirs[k], sj + dirs[k + 1]];
            if (!check(sx, sy)) {
                continue;
            }
            if (sx === bi && sy === bj) {
                const [bx, by] = [bi + dirs[k], bj + dirs[k + 1]];
                if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                    continue;
                }
                vis[f(sx, sy)][f(bx, by)] = true;
                q.push([f(sx, sy), f(bx, by), d + 1]);
            } else if (!vis[f(sx, sy)][f(bi, bj)]) {
                vis[f(sx, sy)][f(bi, bj)] = true;
                q.unshift([f(sx, sy), f(bi, bj), d]);
            }
        }
    }
    return -1;
}

/* 以下是双向列队模板类 */
class CircularDeque<T> {
    prev: CircularDeque<T> | null;
    next: CircularDeque<T> | null;
    begin: number;
    end: number;
    empty: boolean;
    data: T[];
    constructor(N: number) {
        this.prev = this.next = null;
        this.begin = this.end = 0;
        this.empty = true;
        this.data = Array(N);
    }

    isFull(): boolean {
        return this.end === this.begin && !this.empty;
    }

    isEmpty(): boolean {
        return this.empty;
    }

    push(val: T): boolean {
        if (this.isFull()) return false;
        this.empty = false;
        this.data[this.end] = val;
        this.end = (this.end + 1) % this.data.length;
        return true;
    }

    front(): T | undefined {
        return this.isEmpty() ? undefined : this.data[this.begin];
    }

    back(): T | undefined {
        return this.isEmpty() ? undefined : this.data[this.end - 1];
    }

    pop(): T | undefined {
        if (this.isEmpty()) return undefined;
        const value = this.data[this.end - 1];
        this.end = (this.end - 1) % this.data.length;
        if (this.end < 0) this.end += this.data.length;
        if (this.end === this.begin) this.empty = true;
        return value;
    }

    unshift(val: T): boolean {
        if (this.isFull()) return false;
        this.empty = false;
        this.begin = (this.begin - 1) % this.data.length;
        if (this.begin < 0) this.begin += this.data.length;
        this.data[this.begin] = val;
        return true;
    }

    shift(): T | undefined {
        if (this.isEmpty()) return undefined;
        const value = this.data[this.begin];
        this.begin = (this.begin + 1) % this.data.length;
        if (this.end === this.begin) this.empty = true;
        return value;
    }

    *values(): Generator<T, void, undefined> {
        if (this.isEmpty()) return undefined;
        let i = this.begin;
        do {
            yield this.data[i];
            i = (i + 1) % this.data.length;
        } while (i !== this.end);
    }
}

class Deque<T> {
    head: CircularDeque<T>;
    tail: CircularDeque<T>;
    _size: number;
    constructor(collection: T[] = []) {
        this.head = new CircularDeque<T>(128);
        this.tail = new CircularDeque<T>(128);
        this.tail.empty = this.head.empty = false;
        this.tail.prev = this.head;
        this.head.next = this.tail;
        this._size = 0;
        for (const item of collection) this.push(item);
    }

    size(): number {
        return this._size;
    }

    push(val: T): void {
        let last = this.tail.prev!;
        if (last.isFull()) {
            const inserted = new CircularDeque<T>(128);

            this.tail.prev = inserted;
            inserted.next = this.tail;

            last.next = inserted;
            inserted.prev = last;

            last = inserted;
        }
        last.push(val);
        this._size++;
    }

    back(): T | undefined {
        if (this._size === 0) return;
        return this.tail.prev!.back();
    }

    pop(): T | undefined {
        if (this.head.next === this.tail) return undefined;
        const last = this.tail.prev!;
        const value = last.pop();
        if (last.isEmpty()) {
            this.tail.prev = last.prev;
            last.prev!.next = this.tail;
        }
        this._size--;
        return value;
    }

    unshift(val: T): void {
        let first = this.head.next!;
        if (first.isFull()) {
            const inserted = new CircularDeque<T>(128);

            this.head.next = inserted;
            inserted.prev = this.head;

            inserted.next = first;
            first.prev = inserted;

            first = inserted;
        }
        first.unshift(val);
        this._size++;
    }

    shift(): T | undefined {
        if (this.head.next === this.tail) return undefined;
        const first = this.head.next!;
        const value = first.shift();
        if (first.isEmpty()) {
            this.head.next = first.next;
            first.next!.prev = this.head;
        }
        this._size--;
        return value;
    }

    front(): T | undefined {
        if (this._size === 0) return undefined;
        return this.head.next!.front();
    }

    *values(): Generator<T, void, undefined> {
        let node = this.head.next!;
        while (node !== this.tail) {
            for (const value of node.values()) yield value;
            node = node.next!;
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

<p>「推箱子」是一款风靡全球的益智小游戏，玩家需要将箱子推到仓库中的目标位置。</p>

<p>游戏地图用大小为&nbsp;<code>m x n</code>&nbsp;的网格 <code>grid</code> 表示，其中每个元素可以是墙、地板或者是箱子。</p>

<p>现在你将作为玩家参与游戏，按规则将箱子&nbsp;<code>'B'</code>&nbsp;移动到目标位置&nbsp;<code>'T'</code> ：</p>

<ul>
	<li>玩家用字符&nbsp;<code>'S'</code>&nbsp;表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。</li>
	<li>地板用字符&nbsp;<code>'.'</code>&nbsp;表示，意味着可以自由行走。</li>
	<li>墙用字符&nbsp;<code>'#'</code>&nbsp;表示，意味着障碍物，不能通行。&nbsp;</li>
	<li>箱子仅有一个，用字符&nbsp;<code>'B'</code>&nbsp;表示。相应地，网格上有一个目标位置&nbsp;<code>'T'</code>。</li>
	<li>玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。</li>
	<li>玩家无法越过箱子。</li>
</ul>

<p>返回将箱子推到目标位置的最小 <strong>推动</strong> 次数，如果无法做到，请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1263.Minimum%20Moves%20to%20Move%20a%20Box%20to%20Their%20Target%20Location/images/sample_1_1620.png" style="height: 335px; width: 500px;" /></strong></p>

<pre>
<strong>输入：</strong>grid = [["#","#","#","#","#","#"],
             ["#","T","#","#","#","#"],
&nbsp;            ["#",".",".","B",".","#"],
&nbsp;            ["#",".","#","#",".","#"],
&nbsp;            ["#",".",".",".","S","#"],
&nbsp;            ["#","#","#","#","#","#"]]
<strong>输出：</strong>3
<strong>解释：</strong>我们只需要返回推箱子的次数。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [["#","#","#","#","#","#"],
             ["#","T","#","#","#","#"],
&nbsp;            ["#",".",".","B",".","#"],
&nbsp;            ["#","#","#","#",".","#"],
&nbsp;            ["#",".",".",".","S","#"],
&nbsp;            ["#","#","#","#","#","#"]]
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [["#","#","#","#","#","#"],
&nbsp;            ["#","T",".",".","#","#"],
&nbsp;            ["#",".","#","B",".","#"],
&nbsp;            ["#",".",".",".",".","#"],
&nbsp;            ["#",".",".",".","S","#"],
&nbsp;            ["#","#","#","#","#","#"]]
<strong>输出：</strong>5
<strong>解释：</strong>向下、向左、向左、向上再向上。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>grid</code> 仅包含字符&nbsp;<code>'.'</code>, <code>'#'</code>,&nbsp; <code>'S'</code> , <code>'T'</code>, 以及&nbsp;<code>'B'</code>。</li>
	<li><code>grid</code>&nbsp;中&nbsp;<code>'S'</code>, <code>'B'</code>&nbsp;和&nbsp;<code>'T'</code>&nbsp;各只能出现一个。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双端队列 + BFS

我们把玩家的位置和箱子的位置看成一个状态，即 $(s_i, s_j, b_i, b_j)$，其中 $(s_i, s_j)$ 是玩家的位置，而 $(b_i, b_j)$ 是箱子的位置。在代码实现上，我们定义一个函数 $f(i, j)$，它将二维坐标 $(i, j)$ 映射到一个一维的状态编号，即 $f(i, j) = i \times n + j$，其中 $n$ 是网格的列数。那么玩家和箱子的状态就是 $(f(s_i, s_j), f(b_i, b_j))$。

我们首先遍历网格，找到玩家和箱子的初始位置，记为 $(s_i, s_j)$ 和 $(b_i, b_j)$。

然后，我们定义一个双端队列 $q$，其中每个元素都是一个三元组 $(f(s_i, s_j), f(b_i, b_j), d)$，表示玩家位于 $(s_i, s_j)$，箱子位于 $(b_i, b_j)$，并且已经进行了 $d$ 次推动。初始时，我们将 $(f(s_i, s_j), f(b_i, b_j), 0)$ 加入队列 $q$。

另外，我们用一个二维数组 $vis$ 记录每个状态是否已经访问过，初始时 $vis[f(s_i, s_j), f(b_i, b_j)]$ 标记为已访问。

接下来，我们开始进行广度优先搜索。

在每一步搜索中，我们取出队头元素 $(f(s_i, s_j), f(b_i, b_j), d)$，并检查是否满足 $grid[b_i][b_j] = 'T'$，如果是，说明箱子已经被推到目标位置，此时将 $d$ 作为答案返回即可。

否则，我们枚举玩家的下一步移动方向，玩家新的位置记为 $(s_x, s_y)$，如果 $(s_x, s_y)$ 是一个合法的位置，我们判断此时 $(s_x, s_y)$ 是否与箱子的位置 $(b_i, b_j)$ 相同：

-   如果相同，说明当前玩家到达了箱子的位置，并且推动箱子往前走了一步。箱子新的位置为 $(b_x, b_y)$，如果 $(b_x, b_y)$ 是一个合法的位置，且状态 $(f(s_x, s_y), f(b_x, b_y))$ 没有被访问过，那么我们就将 $(f(s_x, s_y), f(b_x, b_y), d + 1)$ 加入队列 $q$ 的末尾，并将 $vis[f(s_x, s_y), f(b_x, b_y)]$ 标记为已访问。
-   如果不同，说明当前玩家没有推动箱子，那么我们只需要判断状态 $(f(s_x, s_y), f(b_i, b_j))$ 是否被访问过，如果没有被访问过，那么我们就将 $(f(s_x, s_y), f(b_i, b_j), d)$ 加入队列 $q$ 的头部，并将 $vis[f(s_x, s_y), f(b_i, b_j)]$ 标记为已访问。

继续进行广度优先搜索，直到队列为空为止。

> 注意，如果推动箱子，那么推动次数 $d$ 需要加 $1$，并且新的状态加入到队列 $q$ 的末尾；如果没推动箱子，那么推动次数 $d$ 不变，新的状态加入到队列 $q$ 的头部。

最后，如果没有找到合法的推动方案，那么返回 $-1$。

时间复杂度 $O(m^2 \times n^2)$，空间复杂度 $O(m^2 \times n^2)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        def f(i: int, j: int) -> int:
            return i * n + j

        def check(i: int, j: int) -> bool:
            return 0 <= i < m and 0 <= j < n and grid[i][j] != "#"

        for i, row in enumerate(grid):
            for j, c in enumerate(row):
                if c == "S":
                    si, sj = i, j
                elif c == "B":
                    bi, bj = i, j
        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)
        q = deque([(f(si, sj), f(bi, bj), 0)])
        vis = [[False] * (m * n) for _ in range(m * n)]
        vis[f(si, sj)][f(bi, bj)] = True
        while q:
            s, b, d = q.popleft()
            bi, bj = b // n, b % n
            if grid[bi][bj] == "T":
                return d
            si, sj = s // n, s % n
            for a, b in pairwise(dirs):
                sx, sy = si + a, sj + b
                if not check(sx, sy):
                    continue
                if sx == bi and sy == bj:
                    bx, by = bi + a, bj + b
                    if not check(bx, by) or vis[f(sx, sy)][f(bx, by)]:
                        continue
                    vis[f(sx, sy)][f(bx, by)] = True
                    q.append((f(sx, sy), f(bx, by), d + 1))
                elif not vis[f(sx, sy)][f(bi, bj)]:
                    vis[f(sx, sy)][f(bi, bj)] = True
                    q.appendleft((f(sx, sy), f(bi, bj), d))
        return -1
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private char[][] grid;

    public int minPushBox(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int si = 0, sj = 0, bi = 0, bj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 'B') {
                    bi = i;
                    bj = j;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        Deque<int[]> q = new ArrayDeque<>();
        boolean[][] vis = new boolean[m * n][m * n];
        q.offer(new int[] {f(si, sj), f(bi, bj), 0});
        vis[f(si, sj)][f(bi, bj)] = true;
        while (!q.isEmpty()) {
            var p = q.poll();
            int d = p[2];
            bi = p[1] / n;
            bj = p[1] % n;
            if (grid[bi][bj] == 'T') {
                return d;
            }
            si = p[0] / n;
            sj = p[0] % n;
            for (int k = 0; k < 4; ++k) {
                int sx = si + dirs[k], sy = sj + dirs[k + 1];
                if (!check(sx, sy)) {
                    continue;
                }
                if (sx == bi && sy == bj) {
                    int bx = bi + dirs[k], by = bj + dirs[k + 1];
                    if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                        continue;
                    }
                    vis[f(sx, sy)][f(bx, by)] = true;
                    q.offer(new int[] {f(sx, sy), f(bx, by), d + 1});
                } else if (!vis[f(sx, sy)][f(bi, bj)]) {
                    vis[f(sx, sy)][f(bi, bj)] = true;
                    q.offerFirst(new int[] {f(sx, sy), f(bi, bj), d});
                }
            }
        }
        return -1;
    }

    private int f(int i, int j) {
        return i * n + j;
    }

    private boolean check(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#';
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int si, sj, bi, bj;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    si = i, sj = j;
                } else if (grid[i][j] == 'B') {
                    bi = i, bj = j;
                }
            }
        }
        auto f = [&](int i, int j) {
            return i * n + j;
        };
        auto check = [&](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#';
        };
        int dirs[5] = {-1, 0, 1, 0, -1};
        deque<tuple<int, int, int>> q;
        q.emplace_back(f(si, sj), f(bi, bj), 0);
        bool vis[m * n][m * n];
        memset(vis, false, sizeof(vis));
        vis[f(si, sj)][f(bi, bj)] = true;
        while (!q.empty()) {
            auto [s, b, d] = q.front();
            q.pop_front();
            si = s / n, sj = s % n;
            bi = b / n, bj = b % n;
            if (grid[bi][bj] == 'T') {
                return d;
            }
            for (int k = 0; k < 4; ++k) {
                int sx = si + dirs[k], sy = sj + dirs[k + 1];
                if (!check(sx, sy)) {
                    continue;
                }
                if (sx == bi && sy == bj) {
                    int bx = bi + dirs[k], by = bj + dirs[k + 1];
                    if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                        continue;
                    }
                    vis[f(sx, sy)][f(bx, by)] = true;
                    q.emplace_back(f(sx, sy), f(bx, by), d + 1);
                } else if (!vis[f(sx, sy)][f(bi, bj)]) {
                    vis[f(sx, sy)][f(bi, bj)] = true;
                    q.emplace_front(f(sx, sy), f(bi, bj), d);
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minPushBox(grid [][]byte) int {
	m, n := len(grid), len(grid[0])
	var si, sj, bi, bj int
	for i, row := range grid {
		for j, c := range row {
			if c == 'S' {
				si, sj = i, j
			} else if c == 'B' {
				bi, bj = i, j
			}
		}
	}
	f := func(i, j int) int {
		return i*n + j
	}
	check := func(i, j int) bool {
		return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#'
	}
	q := [][]int{[]int{f(si, sj), f(bi, bj), 0}}
	vis := make([][]bool, m*n)
	for i := range vis {
		vis[i] = make([]bool, m*n)
	}
	vis[f(si, sj)][f(bi, bj)] = true
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		si, sj, bi, bj = p[0]/n, p[0]%n, p[1]/n, p[1]%n
		d := p[2]
		if grid[bi][bj] == 'T' {
			return d
		}
		for k := 0; k < 4; k++ {
			sx, sy := si+dirs[k], sj+dirs[k+1]
			if !check(sx, sy) {
				continue
			}
			if sx == bi && sy == bj {
				bx, by := bi+dirs[k], bj+dirs[k+1]
				if !check(bx, by) || vis[f(sx, sy)][f(bx, by)] {
					continue
				}
				vis[f(sx, sy)][f(bx, by)] = true
				q = append(q, []int{f(sx, sy), f(bx, by), d + 1})
			} else if !vis[f(sx, sy)][f(bi, bj)] {
				vis[f(sx, sy)][f(bi, bj)] = true
				q = append([][]int{[]int{f(sx, sy), f(bi, bj), d}}, q...)
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minPushBox(grid: string[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    let [si, sj, bi, bj] = [0, 0, 0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 'S') {
                [si, sj] = [i, j];
            } else if (grid[i][j] === 'B') {
                [bi, bj] = [i, j];
            }
        }
    }
    const f = (i: number, j: number): number => i * n + j;
    const check = (i: number, j: number): boolean =>
        i >= 0 && i < m && j >= 0 && j < n && grid[i][j] !== '#';

    const q: Deque<[number, number, number]> = new Deque();
    const vis: boolean[][] = new Array(m * n).fill(0).map(() => new Array(m * n).fill(false));
    q.push([f(si, sj), f(bi, bj), 0]);
    vis[f(si, sj)][f(bi, bj)] = true;
    const dirs: number[] = [-1, 0, 1, 0, -1];
    while (q.size() > 0) {
        const [s, b, d] = q.shift()!;
        const [si, sj] = [Math.floor(s / n), s % n];
        const [bi, bj] = [Math.floor(b / n), b % n];
        if (grid[bi][bj] === 'T') {
            return d;
        }
        for (let k = 0; k < 4; ++k) {
            const [sx, sy] = [si + dirs[k], sj + dirs[k + 1]];
            if (!check(sx, sy)) {
                continue;
            }
            if (sx === bi && sy === bj) {
                const [bx, by] = [bi + dirs[k], bj + dirs[k + 1]];
                if (!check(bx, by) || vis[f(sx, sy)][f(bx, by)]) {
                    continue;
                }
                vis[f(sx, sy)][f(bx, by)] = true;
                q.push([f(sx, sy), f(bx, by), d + 1]);
            } else if (!vis[f(sx, sy)][f(bi, bj)]) {
                vis[f(sx, sy)][f(bi, bj)] = true;
                q.unshift([f(sx, sy), f(bi, bj), d]);
            }
        }
    }
    return -1;
}

/* 以下是双向列队模板类 */
class CircularDeque<T> {
    prev: CircularDeque<T> | null;
    next: CircularDeque<T> | null;
    begin: number;
    end: number;
    empty: boolean;
    data: T[];
    constructor(N: number) {
        this.prev = this.next = null;
        this.begin = this.end = 0;
        this.empty = true;
        this.data = Array(N);
    }

    isFull(): boolean {
        return this.end === this.begin && !this.empty;
    }

    isEmpty(): boolean {
        return this.empty;
    }

    push(val: T): boolean {
        if (this.isFull()) return false;
        this.empty = false;
        this.data[this.end] = val;
        this.end = (this.end + 1) % this.data.length;
        return true;
    }

    front(): T | undefined {
        return this.isEmpty() ? undefined : this.data[this.begin];
    }

    back(): T | undefined {
        return this.isEmpty() ? undefined : this.data[this.end - 1];
    }

    pop(): T | undefined {
        if (this.isEmpty()) return undefined;
        const value = this.data[this.end - 1];
        this.end = (this.end - 1) % this.data.length;
        if (this.end < 0) this.end += this.data.length;
        if (this.end === this.begin) this.empty = true;
        return value;
    }

    unshift(val: T): boolean {
        if (this.isFull()) return false;
        this.empty = false;
        this.begin = (this.begin - 1) % this.data.length;
        if (this.begin < 0) this.begin += this.data.length;
        this.data[this.begin] = val;
        return true;
    }

    shift(): T | undefined {
        if (this.isEmpty()) return undefined;
        const value = this.data[this.begin];
        this.begin = (this.begin + 1) % this.data.length;
        if (this.end === this.begin) this.empty = true;
        return value;
    }

    *values(): Generator<T, void, undefined> {
        if (this.isEmpty()) return undefined;
        let i = this.begin;
        do {
            yield this.data[i];
            i = (i + 1) % this.data.length;
        } while (i !== this.end);
    }
}

class Deque<T> {
    head: CircularDeque<T>;
    tail: CircularDeque<T>;
    _size: number;
    constructor(collection: T[] = []) {
        this.head = new CircularDeque<T>(128);
        this.tail = new CircularDeque<T>(128);
        this.tail.empty = this.head.empty = false;
        this.tail.prev = this.head;
        this.head.next = this.tail;
        this._size = 0;
        for (const item of collection) this.push(item);
    }

    size(): number {
        return this._size;
    }

    push(val: T): void {
        let last = this.tail.prev!;
        if (last.isFull()) {
            const inserted = new CircularDeque<T>(128);

            this.tail.prev = inserted;
            inserted.next = this.tail;

            last.next = inserted;
            inserted.prev = last;

            last = inserted;
        }
        last.push(val);
        this._size++;
    }

    back(): T | undefined {
        if (this._size === 0) return;
        return this.tail.prev!.back();
    }

    pop(): T | undefined {
        if (this.head.next === this.tail) return undefined;
        const last = this.tail.prev!;
        const value = last.pop();
        if (last.isEmpty()) {
            this.tail.prev = last.prev;
            last.prev!.next = this.tail;
        }
        this._size--;
        return value;
    }

    unshift(val: T): void {
        let first = this.head.next!;
        if (first.isFull()) {
            const inserted = new CircularDeque<T>(128);

            this.head.next = inserted;
            inserted.prev = this.head;

            inserted.next = first;
            first.prev = inserted;

            first = inserted;
        }
        first.unshift(val);
        this._size++;
    }

    shift(): T | undefined {
        if (this.head.next === this.tail) return undefined;
        const first = this.head.next!;
        const value = first.shift();
        if (first.isEmpty()) {
            this.head.next = first.next;
            first.next!.prev = this.head;
        }
        this._size--;
        return value;
    }

    front(): T | undefined {
        if (this._size === 0) return undefined;
        return this.head.next!.front();
    }

    *values(): Generator<T, void, undefined> {
        let node = this.head.next!;
        while (node !== this.tail) {
            for (const value of node.values()) yield value;
            node = node.next!;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1264. 页面推荐 🔒](https://leetcode.cn/problems/page-recommendations){#1264}

{{< tabs "1264" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT page_id AS recommended_page
FROM Likes
WHERE
    user_id IN (
        SELECT user1_id AS user_id FROM Friendship WHERE user2_id = 1
        UNION ALL
        SELECT user2_id AS user_id FROM Friendship WHERE user1_id = 1
    )
    AND page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>朋友关系列表：&nbsp;<code>Friendship</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user1_id      | int     |
| user2_id      | int     |
+---------------+---------+
(user1_id, user2_id) 是这张表具有唯一值的列的组合。
这张表的每一行代表着 user1_id 和 user2_id 之间存在着朋友关系。
</pre>

<p>&nbsp;</p>

<p>喜欢列表：&nbsp;<code>Likes</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| page_id     | int     |
+-------------+---------+
(user_id, page_id) 是这张表具有唯一值的列的组合。
这张表的每一行代表着 user_id 喜欢 page_id。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，向<code>user_id</code> = 1 的用户，推荐其朋友们喜欢的页面。不要推荐该用户已经喜欢的页面。</p>

<p>以 <strong>任意顺序</strong> 返回结果，其中不应当包含重复项。</p>

<p>返回结果的格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Friendship table:
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
| 1        | 3        |
| 1        | 4        |
| 2        | 3        |
| 2        | 4        |
| 2        | 5        |
| 6        | 1        |
+----------+----------+
 
Likes table:
+---------+---------+
| user_id | page_id |
+---------+---------+
| 1       | 88      |
| 2       | 23      |
| 3       | 24      |
| 4       | 56      |
| 5       | 11      |
| 6       | 33      |
| 2       | 77      |
| 3       | 77      |
| 6       | 88      |
+---------+---------+

<strong>输出：</strong>
+------------------+
| recommended_page |
+------------------+
| 23               |
| 24               |
| 56               |
| 33               |
| 77               |
+------------------+
<strong>解释：</strong>
用户1 同 用户2, 3, 4, 6 是朋友关系。
推荐页面为： 页面23 来自于 用户2, 页面24 来自于 用户3, 页面56 来自于 用户3 以及 页面33 来自于 用户6。
页面77 同时被 用户2 和 用户3 推荐。
页面88 没有被推荐，因为 用户1 已经喜欢了它。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并 + 等值连接 + 子查询

我们先查出所有与 `user_id = 1` 的用户是朋友的用户，记录在 `T` 表中，然后再查出所有在 `T` 表中的用户喜欢的页面，最后排除掉 `user_id = 1` 喜欢的页面即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT user1_id AS user_id FROM Friendship WHERE user2_id = 1
        UNION
        SELECT user2_id AS user_id FROM Friendship WHERE user1_id = 1
    )
SELECT DISTINCT page_id AS recommended_page
FROM
    T
    JOIN Likes USING (user_id)
WHERE page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT page_id AS recommended_page
FROM Likes
WHERE
    user_id IN (
        SELECT user1_id AS user_id FROM Friendship WHERE user2_id = 1
        UNION ALL
        SELECT user2_id AS user_id FROM Friendship WHERE user1_id = 1
    )
    AND page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1265. 逆序打印不可变链表 🔒](https://leetcode.cn/problems/print-immutable-linked-list-in-reverse){#1265}

{{< tabs "1265" >}}

{{% tab "python" %}}
```python
# """
# This is the ImmutableListNode's API interface.
# You should not implement it, or speculate about its implementation.
# """
# class ImmutableListNode:
#     def printValue(self) -> None: # print the value of this node.
#     def getNext(self) -> 'ImmutableListNode': # return the next node.


class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        if head:
            self.printLinkedListInReverse(head.getNext())
            head.printValue()
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * interface ImmutableListNode {
 *     public void printValue(); // print the value of this node.
 *     public ImmutableListNode getNext(); // return the next node.
 * };
 */

class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        if (head != null) {
            printLinkedListInReverse(head.getNext());
            head.printValue();
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head) {
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/*   Below is the interface for ImmutableListNode, which is already defined for you.
 *
 *   type ImmutableListNode struct {
 *
 *   }
 *
 *   func (this *ImmutableListNode) getNext() ImmutableListNode {
 *		// return the next node.
 *   }
 *
 *   func (this *ImmutableListNode) printValue() {
 *		// print the value of this node.
 *   }
 */

func printLinkedListInReverse(head ImmutableListNode) {
	if head != nil {
		printLinkedListInReverse(head.getNext())
		head.printValue()
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ImmutableListNode {
 *      printValue() {}
 *
 *      getNext(): ImmutableListNode {}
 * }
 */

function printLinkedListInReverse(head: ImmutableListNode) {
    if (head) {
        printLinkedListInReverse(head.next);
        head.printValue();
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 *     public void PrintValue(); // print the value of this node.
 *     public ImmutableListNode GetNext(); // return the next node.
 * }
 */

public class Solution {
    public void PrintLinkedListInReverse(ImmutableListNode head) {
        if (head != null) {
            PrintLinkedListInReverse(head.GetNext());
            head.PrintValue();
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

<p>给您一个不可变的链表，使用下列接口逆序打印每个节点的值：</p>

<ul>
	<li><code>ImmutableListNode</code>: 描述不可变链表的接口，链表的头节点已给出。</li>
</ul>

<p>您需要使用以下函数来访问此链表（您&nbsp;<strong>不能&nbsp;</strong>直接访问&nbsp;<code>ImmutableListNode</code>）：</p>

<ul>
	<li><code>ImmutableListNode.printValue()</code>：打印当前节点的值。</li>
	<li><code>ImmutableListNode.getNext()</code>：返回下一个节点。</li>
</ul>

<p>输入只用来内部初始化链表。您不可以通过修改链表解决问题。也就是说，您只能通过上述 API 来操作链表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[4,3,2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [0,-4,-1,3,-5]
<strong>输出：</strong>[-5,3,-1,-4,0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [-2,0,6,4,4,-6]
<strong>输出：</strong>[-6,4,4,6,0,-2]
</pre>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度在&nbsp;<code>[1, 1000]</code>&nbsp;之间。</li>
	<li>每个节点的值在&nbsp;<code>[-1000, 1000]</code>&nbsp;之间。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>您是否可以：</p>

<ul>
	<li>使用常数级空间复杂度解决问题？</li>
	<li>使用线性级时间复杂度和低于线性级空间复杂度解决问题？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以使用递归来实现链表的逆序打印。在函数中，我们判断当前节点是否为空，如果不为空，则获取下一个节点，然后递归调用函数本身，最后打印当前节点的值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是链表的长度。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the ImmutableListNode's API interface.
# You should not implement it, or speculate about its implementation.
# """
# class ImmutableListNode:
#     def printValue(self) -> None: # print the value of this node.
#     def getNext(self) -> 'ImmutableListNode': # return the next node.


class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        if head:
            self.printLinkedListInReverse(head.getNext())
            head.printValue()
```

#### Java

```java
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * interface ImmutableListNode {
 *     public void printValue(); // print the value of this node.
 *     public ImmutableListNode getNext(); // return the next node.
 * };
 */

class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        if (head != null) {
            printLinkedListInReverse(head.getNext());
            head.printValue();
        }
    }
}
```

#### C++

```cpp
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head) {
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};
```

#### Go

```go
/*   Below is the interface for ImmutableListNode, which is already defined for you.
 *
 *   type ImmutableListNode struct {
 *
 *   }
 *
 *   func (this *ImmutableListNode) getNext() ImmutableListNode {
 *		// return the next node.
 *   }
 *
 *   func (this *ImmutableListNode) printValue() {
 *		// print the value of this node.
 *   }
 */

func printLinkedListInReverse(head ImmutableListNode) {
	if head != nil {
		printLinkedListInReverse(head.getNext())
		head.printValue()
	}
}
```

#### TypeScript

```ts
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ImmutableListNode {
 *      printValue() {}
 *
 *      getNext(): ImmutableListNode {}
 * }
 */

function printLinkedListInReverse(head: ImmutableListNode) {
    if (head) {
        printLinkedListInReverse(head.next);
        head.printValue();
    }
}
```

#### C#

```cs
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 *     public void PrintValue(); // print the value of this node.
 *     public ImmutableListNode GetNext(); // return the next node.
 * }
 */

public class Solution {
    public void PrintLinkedListInReverse(ImmutableListNode head) {
        if (head != null) {
            PrintLinkedListInReverse(head.GetNext());
            head.PrintValue();
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1266. 访问所有点的最小时间](https://leetcode.cn/problems/minimum-time-visiting-all-points){#1266}

{{< tabs "1266" >}}

{{% tab "python" %}}
```python
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(
            max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1])) for p1, p2 in pairwise(points)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0;
        for (int i = 1; i < points.length; ++i) {
            int dx = Math.abs(points[i][0] - points[i - 1][0]);
            int dy = Math.abs(points[i][1] - points[i - 1][1]);
            ans += Math.max(dx, dy);
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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            ans += max(dx, dy);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTimeToVisitAllPoints(points [][]int) (ans int) {
	for i, p := range points[1:] {
		dx := abs(p[0] - points[i][0])
		dy := abs(p[1] - points[i][1])
		ans += max(dx, dy)
	}
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
function minTimeToVisitAllPoints(points: number[][]): number {
    let ans = 0;
    for (let i = 1; i < points.length; i++) {
        let dx = Math.abs(points[i][0] - points[i - 1][0]),
            dy = Math.abs(points[i][1] - points[i - 1][1]);
        ans += Math.max(dx, dy);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut ans = 0;
        for i in 1..n {
            let x = (points[i - 1][0] - points[i][0]).abs();
            let y = (points[i - 1][1] - points[i][1]).abs();
            ans += x.max(y);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0;
    for (int i = 1; i < pointsSize; i++) {
        int x = abs(points[i - 1][0] - points[i][0]);
        int y = abs(points[i - 1][1] - points[i][1]);
        ans += max(x, y);
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

<p>平面上有 <code>n</code> 个点，点的位置用整数坐标表示 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。请你计算访问所有这些点需要的 <strong>最小时间</strong>（以秒为单位）。</p>

<p>你需要按照下面的规则在平面上移动：</p>

<ul>
	<li>每一秒内，你可以：
	<ul>
		<li>沿水平方向移动一个单位长度，或者</li>
		<li>沿竖直方向移动一个单位长度，或者</li>
		<li>跨过对角线移动 <code>sqrt(2)</code> 个单位长度（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。</li>
	</ul>
	</li>
	<li>必须按照数组中出现的顺序来访问这些点。</li>
	<li>在访问某个点时，可以经过该点后面出现的点，但经过的那些点不算作有效访问。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1266.Minimum%20Time%20Visiting%20All%20Points/images/1626_example_1.png" style="height: 428px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>points = [[1,1],[3,4],[-1,0]]
<strong>输出：</strong>7
<strong>解释：</strong>一条最佳的访问路径是： <strong>[1,1]</strong> -> [2,2] -> [3,3] -> <strong>[3,4] </strong>-> [2,3] -> [1,2] -> [0,1] -> <strong>[-1,0]</strong>   
从 [1,1] 到 [3,4] 需要 3 秒 
从 [3,4] 到 [-1,0] 需要 4 秒
一共需要 7 秒</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[3,2],[-2,2]]
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>points.length == n</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-1000 <= points[i][0], points[i][1] <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

对于两个点 $p1=(x_1, y_1)$ 和 $p2=(x_2, y_2)$，横坐标和纵坐标分别移动的距离分别为 $dx = |x_1 - x_2|$ 和 $dy = |y_1 - y_2|$。

如果 $dx \ge dy$，则沿对角线移动 $dy$，再沿水平方向移动 $dx - dy$；如果 $dx < dy$，则沿对角线移动 $dx$，再沿竖直方向移动 $dy - dx$。因此，两个点之间的最短距离为 $max(dx, dy)$。

我们可以遍历所有的点对，计算出每个点对之间的最短距离，然后求和即可。

时间复杂度 $O(n)$，其中 $n$ 为点的个数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(
            max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1])) for p1, p2 in pairwise(points)
        )
```

#### Java

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0;
        for (int i = 1; i < points.length; ++i) {
            int dx = Math.abs(points[i][0] - points[i - 1][0]);
            int dy = Math.abs(points[i][1] - points[i - 1][1]);
            ans += Math.max(dx, dy);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            ans += max(dx, dy);
        }
        return ans;
    }
};
```

#### Go

```go
func minTimeToVisitAllPoints(points [][]int) (ans int) {
	for i, p := range points[1:] {
		dx := abs(p[0] - points[i][0])
		dy := abs(p[1] - points[i][1])
		ans += max(dx, dy)
	}
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
function minTimeToVisitAllPoints(points: number[][]): number {
    let ans = 0;
    for (let i = 1; i < points.length; i++) {
        let dx = Math.abs(points[i][0] - points[i - 1][0]),
            dy = Math.abs(points[i][1] - points[i - 1][1]);
        ans += Math.max(dx, dy);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut ans = 0;
        for i in 1..n {
            let x = (points[i - 1][0] - points[i][0]).abs();
            let y = (points[i - 1][1] - points[i][1]).abs();
            ans += x.max(y);
        }
        ans
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0;
    for (int i = 1; i < pointsSize; i++) {
        int x = abs(points[i - 1][0] - points[i][0]);
        int y = abs(points[i - 1][1] - points[i][1]);
        ans += max(x, y);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1267. 统计参与通信的服务器](https://leetcode.cn/problems/count-servers-that-communicate){#1267}

{{< tabs "1267" >}}

{{% tab "python" %}}
```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row = [0] * m
        col = [0] * n
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    row[i] += 1
                    col[j] += 1
        return sum(
            grid[i][j] and (row[i] > 1 or col[j] > 1)
            for i in range(m)
            for j in range(n)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] row = new int[m];
        int[] col = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
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
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j] && (row[i] > 1 || col[j] > 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countServers(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	row, col := make([]int, m), make([]int, n)
	for i := range grid {
		for j, x := range grid[i] {
			if x == 1 {
				row[i]++
				col[j]++
			}
		}
	}
	for i := range grid {
		for j, x := range grid[i] {
			if x == 1 && (row[i] > 1 || col[j] > 1) {
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
function countServers(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const row = new Array(m).fill(0);
    const col = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                row[i]++;
                col[j]++;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1 && (row[i] > 1 || col[j] > 1)) {
                ans++;
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

<p>这里有一幅服务器分布图，服务器的位置标识在&nbsp;<code>m * n</code>&nbsp;的整数矩阵网格&nbsp;<code>grid</code>&nbsp;中，1 表示单元格上有服务器，0 表示没有。</p>

<p>如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。</p>

<p>请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1267.Count%20Servers%20that%20Communicate/images/untitled-diagram-6.jpg" style="height: 203px; width: 202px;"></p>

<pre><strong>输入：</strong>grid = [[1,0],[0,1]]
<strong>输出：</strong>0
<strong>解释：</strong>没有一台服务器能与其他服务器进行通信。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1267.Count%20Servers%20that%20Communicate/images/untitled-diagram-4-1.jpg" style="height: 203px; width: 203px;"></strong></p>

<pre><strong>输入：</strong>grid = [[1,0],[1,1]]
<strong>输出：</strong>3
<strong>解释：</strong>所有这些服务器都至少可以与一台别的服务器进行通信。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1267.Count%20Servers%20that%20Communicate/images/untitled-diagram-1-3.jpg" style="height: 443px; width: 443px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
<strong>输出：</strong>4
<strong>解释：</strong>第一行的两台服务器互相通信，第三列的两台服务器互相通信，但右下角的服务器无法与其他服务器通信。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 250</code></li>
	<li><code>1 &lt;= n &lt;= 250</code></li>
	<li><code>grid[i][j] == 0 or 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以统计每一行、每一列的服务器数量，然后遍历每个服务器，若当前服务器所在的行或者列的服务器数量超过 $1$，说明当前服务器满足条件，结果加 $1$。

遍历结束后，返回结果即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row = [0] * m
        col = [0] * n
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    row[i] += 1
                    col[j] += 1
        return sum(
            grid[i][j] and (row[i] > 1 or col[j] > 1)
            for i in range(m)
            for j in range(n)
        )
```

#### Java

```java
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] row = new int[m];
        int[] col = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
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
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j] && (row[i] > 1 || col[j] > 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countServers(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	row, col := make([]int, m), make([]int, n)
	for i := range grid {
		for j, x := range grid[i] {
			if x == 1 {
				row[i]++
				col[j]++
			}
		}
	}
	for i := range grid {
		for j, x := range grid[i] {
			if x == 1 && (row[i] > 1 || col[j] > 1) {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countServers(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const row = new Array(m).fill(0);
    const col = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                row[i]++;
                col[j]++;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1 && (row[i] > 1 || col[j] > 1)) {
                ans++;
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

# [1268. 搜索推荐系统](https://leetcode.cn/problems/search-suggestions-system){#1268}

{{< tabs "1268" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Union[Trie, None]] = [None] * 26
        self.v: List[int] = []

    def insert(self, w, i):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            if len(node.v) < 3:
                node.v.append(i)

    def search(self, w):
        node = self
        ans = [[] for _ in range(len(w))]
        for i, c in enumerate(w):
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                break
            node = node.children[idx]
            ans[i] = node.v
        return ans


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        products.sort()
        trie = Trie()
        for i, w in enumerate(products):
            trie.insert(w, i)
        return [[products[i] for i in v] for v in trie.search(searchWord)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    List<Integer> v = new ArrayList<>();

    public void insert(String w, int i) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            if (node.v.size() < 3) {
                node.v.add(i);
            }
        }
    }

    public List<Integer>[] search(String w) {
        Trie node = this;
        int n = w.length();
        List<Integer>[] ans = new List[n];
        Arrays.setAll(ans, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                break;
            }
            node = node.children[idx];
            ans[i] = node.v;
        }
        return ans;
    }
}

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        Trie trie = new Trie();
        for (int i = 0; i < products.length; ++i) {
            trie.insert(products[i], i);
        }
        List<List<String>> ans = new ArrayList<>();
        for (var v : trie.search(searchWord)) {
            List<String> t = new ArrayList<>();
            for (int i : v) {
                t.add(products[i]);
            }
            ans.add(t);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    void insert(string& w, int i) {
        Trie* node = this;
        for (int j = 0; j < w.size(); ++j) {
            int idx = w[j] - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            if (node->v.size() < 3) {
                node->v.push_back(i);
            }
        }
    }

    vector<vector<int>> search(string& w) {
        Trie* node = this;
        int n = w.size();
        vector<vector<int>> ans(n);
        for (int i = 0; i < w.size(); ++i) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) {
                break;
            }
            node = node->children[idx];
            ans[i] = move(node->v);
        }
        return ans;
    }

private:
    vector<Trie*> children = vector<Trie*>(26);
    vector<int> v;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie* trie = new Trie();
        for (int i = 0; i < products.size(); ++i) {
            trie->insert(products[i], i);
        }
        vector<vector<string>> ans;
        for (auto& v : trie->search(searchWord)) {
            vector<string> t;
            for (int i : v) {
                t.push_back(products[i]);
            }
            ans.push_back(move(t));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	v        []int
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(w string, i int) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		if len(node.v) < 3 {
			node.v = append(node.v, i)
		}
	}
}

func (this *Trie) search(w string) [][]int {
	node := this
	n := len(w)
	ans := make([][]int, n)
	for i, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			break
		}
		node = node.children[c]
		ans[i] = node.v
	}
	return ans
}

func suggestedProducts(products []string, searchWord string) (ans [][]string) {
	sort.Strings(products)
	trie := newTrie()
	for i, w := range products {
		trie.insert(w, i)
	}
	for _, v := range trie.search(searchWord) {
		t := []string{}
		for _, i := range v {
			t = append(t, products[i])
		}
		ans = append(ans, t)
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

<p>给你一个产品数组&nbsp;<code>products</code>&nbsp;和一个字符串&nbsp;<code>searchWord</code>&nbsp;，<code>products</code>&nbsp; 数组中每个产品都是一个字符串。</p>

<p>请你设计一个推荐系统，在依次输入单词&nbsp;<code>searchWord</code> 的每一个字母后，推荐&nbsp;<code>products</code> 数组中前缀与&nbsp;<code>searchWord</code> 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。</p>

<p>请你以二维列表的形式，返回在输入&nbsp;<code>searchWord</code>&nbsp;每个字母后相应的推荐产品的列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>products = [&quot;mobile&quot;,&quot;mouse&quot;,&quot;moneypot&quot;,&quot;monitor&quot;,&quot;mousepad&quot;], searchWord = &quot;mouse&quot;
<strong>输出：</strong>[
[&quot;mobile&quot;,&quot;moneypot&quot;,&quot;monitor&quot;],
[&quot;mobile&quot;,&quot;moneypot&quot;,&quot;monitor&quot;],
[&quot;mouse&quot;,&quot;mousepad&quot;],
[&quot;mouse&quot;,&quot;mousepad&quot;],
[&quot;mouse&quot;,&quot;mousepad&quot;]
]
<strong>解释：</strong>按字典序排序后的产品列表是 [&quot;mobile&quot;,&quot;moneypot&quot;,&quot;monitor&quot;,&quot;mouse&quot;,&quot;mousepad&quot;]
输入 m 和 mo，由于所有产品的前缀都相同，所以系统返回字典序最小的三个产品 [&quot;mobile&quot;,&quot;moneypot&quot;,&quot;monitor&quot;]
输入 mou， mous 和 mouse 后系统都返回 [&quot;mouse&quot;,&quot;mousepad&quot;]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>products = [&quot;havana&quot;], searchWord = &quot;havana&quot;
<strong>输出：</strong>[[&quot;havana&quot;],[&quot;havana&quot;],[&quot;havana&quot;],[&quot;havana&quot;],[&quot;havana&quot;],[&quot;havana&quot;]]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>products = [&quot;bags&quot;,&quot;baggage&quot;,&quot;banner&quot;,&quot;box&quot;,&quot;cloths&quot;], searchWord = &quot;bags&quot;
<strong>输出：</strong>[[&quot;baggage&quot;,&quot;bags&quot;,&quot;banner&quot;],[&quot;baggage&quot;,&quot;bags&quot;,&quot;banner&quot;],[&quot;baggage&quot;,&quot;bags&quot;],[&quot;bags&quot;]]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>products = [&quot;havana&quot;], searchWord = &quot;tatiana&quot;
<strong>输出：</strong>[[],[],[],[],[],[],[]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= products.length &lt;= 1000</code></li>
	<li><code>1 &lt;= &Sigma; products[i].length &lt;= 2 * 10^4</code></li>
	<li><code>products[i]</code>&nbsp;中所有的字符都是小写英文字母。</li>
	<li><code>1 &lt;= searchWord.length &lt;= 1000</code></li>
	<li><code>searchWord</code>&nbsp;中所有字符都是小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀树

题目要求在输入 `searchWord` 的每一个字母后，推荐 `products` 数组中前缀与 `searchWord` 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，按字典序返回最小的三个。

找前缀相同的产品，可以使用前缀树；而要返回字典序最小的三个产品，我们可以先对 `products` 数组进行排序，然后将排序后的数组下标存入前缀树中。

前缀树的每个节点维护以下信息：

-   `children`：这是一个长度为 $26$ 的数组，用于存储当前节点的子节点，`children[i]` 表示当前节点的子节点中字符为 `i + 'a'` 的节点。
-   `v`：这是一个数组，用于存储当前节点的子节点中的字符在 `products` 数组中的下标，最多存储三个下标。

搜索时，我们从前缀树的根节点开始，找到每一个前缀对应的下标数组，将其存入结果数组中。最后只需要将每个下标数组中的下标对应到 `products` 数组中即可。

时间复杂度 $O(L \times \log n + m)$，空间复杂度 $O(L)$。其中 $L$ 是 `products` 数组所有字符串的长度之和，而 $n$ 和 $m$ 分别是 `products` 数组的长度和 `searchWord` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Union[Trie, None]] = [None] * 26
        self.v: List[int] = []

    def insert(self, w, i):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            if len(node.v) < 3:
                node.v.append(i)

    def search(self, w):
        node = self
        ans = [[] for _ in range(len(w))]
        for i, c in enumerate(w):
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                break
            node = node.children[idx]
            ans[i] = node.v
        return ans


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        products.sort()
        trie = Trie()
        for i, w in enumerate(products):
            trie.insert(w, i)
        return [[products[i] for i in v] for v in trie.search(searchWord)]
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    List<Integer> v = new ArrayList<>();

    public void insert(String w, int i) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            if (node.v.size() < 3) {
                node.v.add(i);
            }
        }
    }

    public List<Integer>[] search(String w) {
        Trie node = this;
        int n = w.length();
        List<Integer>[] ans = new List[n];
        Arrays.setAll(ans, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                break;
            }
            node = node.children[idx];
            ans[i] = node.v;
        }
        return ans;
    }
}

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        Trie trie = new Trie();
        for (int i = 0; i < products.length; ++i) {
            trie.insert(products[i], i);
        }
        List<List<String>> ans = new ArrayList<>();
        for (var v : trie.search(searchWord)) {
            List<String> t = new ArrayList<>();
            for (int i : v) {
                t.add(products[i]);
            }
            ans.add(t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    void insert(string& w, int i) {
        Trie* node = this;
        for (int j = 0; j < w.size(); ++j) {
            int idx = w[j] - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            if (node->v.size() < 3) {
                node->v.push_back(i);
            }
        }
    }

    vector<vector<int>> search(string& w) {
        Trie* node = this;
        int n = w.size();
        vector<vector<int>> ans(n);
        for (int i = 0; i < w.size(); ++i) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) {
                break;
            }
            node = node->children[idx];
            ans[i] = move(node->v);
        }
        return ans;
    }

private:
    vector<Trie*> children = vector<Trie*>(26);
    vector<int> v;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie* trie = new Trie();
        for (int i = 0; i < products.size(); ++i) {
            trie->insert(products[i], i);
        }
        vector<vector<string>> ans;
        for (auto& v : trie->search(searchWord)) {
            vector<string> t;
            for (int i : v) {
                t.push_back(products[i]);
            }
            ans.push_back(move(t));
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	v        []int
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(w string, i int) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		if len(node.v) < 3 {
			node.v = append(node.v, i)
		}
	}
}

func (this *Trie) search(w string) [][]int {
	node := this
	n := len(w)
	ans := make([][]int, n)
	for i, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			break
		}
		node = node.children[c]
		ans[i] = node.v
	}
	return ans
}

func suggestedProducts(products []string, searchWord string) (ans [][]string) {
	sort.Strings(products)
	trie := newTrie()
	for i, w := range products {
		trie.insert(w, i)
	}
	for _, v := range trie.search(searchWord) {
		t := []string{}
		for _, i := range v {
			t = append(t, products[i])
		}
		ans = append(ans, t)
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1269. 停在原地的方案数](https://leetcode.cn/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps){#1269}

{{< tabs "1269" >}}

{{% tab "python" %}}
```python
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        @cache
        def dfs(i, j):
            if i > j or i >= arrLen or i < 0 or j < 0:
                return 0
            if i == 0 and j == 0:
                return 1
            ans = 0
            for k in range(-1, 2):
                ans += dfs(i + k, j - 1)
                ans %= mod
            return ans

        mod = 10**9 + 7
        return dfs(0, steps)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private int n;

    public int numWays(int steps, int arrLen) {
        f = new Integer[steps][steps + 1];
        n = arrLen;
        return dfs(0, steps);
    }

    private int dfs(int i, int j) {
        if (i > j || i >= n || i < 0 || j < 0) {
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int k = -1; k <= 1; ++k) {
            ans = (ans + dfs(i + k, j - 1)) % mod;
        }
        return f[i][j] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int f[steps][steps + 1];
        memset(f, -1, sizeof f);
        const int mod = 1e9 + 7;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i > j || i >= arrLen || i < 0 || j < 0) {
                return 0;
            }
            if (i == 0 && j == 0) {
                return 1;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = 0;
            for (int k = -1; k <= 1; ++k) {
                ans = (ans + dfs(i + k, j - 1)) % mod;
            }
            return f[i][j] = ans;
        };
        return dfs(0, steps);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numWays(steps int, arrLen int) int {
	const mod int = 1e9 + 7
	f := make([][]int, steps)
	for i := range f {
		f[i] = make([]int, steps+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) (ans int) {
		if i > j || i >= arrLen || i < 0 || j < 0 {
			return 0
		}
		if i == 0 && j == 0 {
			return 1
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		for k := -1; k <= 1; k++ {
			ans += dfs(i+k, j-1)
			ans %= mod
		}
		f[i][j] = ans
		return
	}
	return dfs(0, steps)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numWays(steps: number, arrLen: number): number {
    const f = Array.from({ length: steps }, () => Array(steps + 1).fill(-1));
    const mod = 10 ** 9 + 7;
    const dfs = (i: number, j: number) => {
        if (i > j || i >= arrLen || i < 0 || j < 0) {
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (f[i][j] != -1) {
            return f[i][j];
        }
        let ans = 0;
        for (let k = -1; k <= 1; ++k) {
            ans = (ans + dfs(i + k, j - 1)) % mod;
        }
        return (f[i][j] = ans);
    };
    return dfs(0, steps);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个长度为 <code>arrLen</code> 的数组，开始有一个指针在索引 <code>0</code> 处。</p>

<p>每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。</p>

<p>给你两个整数 <code>steps</code> 和 <code>arrLen</code> ，请你计算并返回：在恰好执行 <code>steps</code> 次操作以后，指针仍然指向索引 <code>0</code> 处的方案数。</p>

<p>由于答案可能会很大，请返回方案数 <strong>模</strong> <code>10^9 + 7</code> 后的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>steps = 3, arrLen = 2
<strong>输出：</strong>4
<strong>解释：</strong>3 步后，总共有 4 种不同的方法可以停在索引 0 处。
向右，向左，不动
不动，向右，向左
向右，不动，向左
不动，不动，不动
</pre>

<p><strong>示例  2：</strong></p>

<pre>
<strong>输入：</strong>steps = 2, arrLen = 4
<strong>输出：</strong>2
<strong>解释：</strong>2 步后，总共有 2 种不同的方法可以停在索引 0 处。
向右，向左
不动，不动
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>steps = 4, arrLen = 2
<strong>输出：</strong>8
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= steps <= 500</code></li>
	<li><code>1 <= arrLen <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们观察题目的数据范围，可以发现 $steps$ 最大不超过 $500$，这意味着我们最远只能往右走 $500$ 步。

我们可以设计一个函数 $dfs(i, j)$，表示当前在位置 $i$，并且剩余步数为 $j$ 的方案数。那么答案就是 $dfs(0, steps)$。

函数 $dfs(i, j)$ 的执行过程如下：

1. 如果 $i \gt j$ 或者 $i \geq arrLen$ 或者 $i \lt 0$ 或者 $j \lt 0$，那么返回 $0$。
1. 如果 $i = 0$ 且 $j = 0$，那么此时指针已经停在原地，并且没有剩余步数，所以返回 $1$。
1. 否则，我们可以选择向左走一步，向右走一步，或者不动，所以返回 $dfs(i - 1, j - 1) + dfs(i + 1, j - 1) + dfs(i, j - 1)$。注意答案的取模操作。

过程中，我们可以使用记忆化搜索避免重复计算。

时间复杂度 $O(steps \times steps)$，空间复杂度 $O(steps \times steps)$。其中 $steps$ 是题目给定的步数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        @cache
        def dfs(i, j):
            if i > j or i >= arrLen or i < 0 or j < 0:
                return 0
            if i == 0 and j == 0:
                return 1
            ans = 0
            for k in range(-1, 2):
                ans += dfs(i + k, j - 1)
                ans %= mod
            return ans

        mod = 10**9 + 7
        return dfs(0, steps)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int n;

    public int numWays(int steps, int arrLen) {
        f = new Integer[steps][steps + 1];
        n = arrLen;
        return dfs(0, steps);
    }

    private int dfs(int i, int j) {
        if (i > j || i >= n || i < 0 || j < 0) {
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int k = -1; k <= 1; ++k) {
            ans = (ans + dfs(i + k, j - 1)) % mod;
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int f[steps][steps + 1];
        memset(f, -1, sizeof f);
        const int mod = 1e9 + 7;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i > j || i >= arrLen || i < 0 || j < 0) {
                return 0;
            }
            if (i == 0 && j == 0) {
                return 1;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = 0;
            for (int k = -1; k <= 1; ++k) {
                ans = (ans + dfs(i + k, j - 1)) % mod;
            }
            return f[i][j] = ans;
        };
        return dfs(0, steps);
    }
};
```

#### Go

```go
func numWays(steps int, arrLen int) int {
	const mod int = 1e9 + 7
	f := make([][]int, steps)
	for i := range f {
		f[i] = make([]int, steps+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) (ans int) {
		if i > j || i >= arrLen || i < 0 || j < 0 {
			return 0
		}
		if i == 0 && j == 0 {
			return 1
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		for k := -1; k <= 1; k++ {
			ans += dfs(i+k, j-1)
			ans %= mod
		}
		f[i][j] = ans
		return
	}
	return dfs(0, steps)
}
```

#### TypeScript

```ts
function numWays(steps: number, arrLen: number): number {
    const f = Array.from({ length: steps }, () => Array(steps + 1).fill(-1));
    const mod = 10 ** 9 + 7;
    const dfs = (i: number, j: number) => {
        if (i > j || i >= arrLen || i < 0 || j < 0) {
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (f[i][j] != -1) {
            return f[i][j];
        }
        let ans = 0;
        for (let k = -1; k <= 1; ++k) {
            ans = (ans + dfs(i + k, j - 1)) % mod;
        }
        return (f[i][j] = ans);
    };
    return dfs(0, steps);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
