---
title: "0130_被围绕的区域"
date: 2025-10-08T18:45:43+08:00
weight: 4
tags: [位运算, 动态规划, 哈希表, 回溯, 图, 字典树, 字符串, 并查集, 广度优先搜索, 数组, 深度优先搜索, 矩阵, 记忆化搜索, 贪心, 链表]
---

{{< markmap >}}
### [0130_被围绕的区域](#130)
#### [深度优先搜索](#130)
#### [广度优先搜索](#130)
#### [并查集](#130)
#### [数组](#130)
#### [矩阵](#130)
### [0131_分割回文串](#131)
#### [字符串](#131)
#### [动态规划](#131)
#### [回溯](#131)
### [0132_分割回文串 II](#132)
#### [字符串](#132)
#### [动态规划](#132)
### [0133_克隆图](#133)
#### [深度优先搜索](#133)
#### [广度优先搜索](#133)
#### [图](#133)
#### [哈希表](#133)
### [0134_加油站](#134)
#### [贪心](#134)
#### [数组](#134)
### [0135_分发糖果](#135)
#### [贪心](#135)
#### [数组](#135)
### [0136_只出现一次的数字](#136)
#### [位运算](#136)
#### [数组](#136)
### [0137_只出现一次的数字 II](#137)
#### [位运算](#137)
#### [数组](#137)
### [0138_随机链表的复制](#138)
#### [哈希表](#138)
#### [链表](#138)
### [0139_单词拆分](#139)
#### [字典树](#139)
#### [记忆化搜索](#139)
#### [数组](#139)
#### [哈希表](#139)
#### [字符串](#139)
#### [动态规划](#139)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0130_被围绕的区域
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 0131_分割回文串
___
#### 字符串
___
#### 动态规划
___
#### 回溯
---
### 0132_分割回文串 II
___
#### 字符串
___
#### 动态规划
---
### 0133_克隆图
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 哈希表
---
### 0134_加油站
___
#### 贪心
___
#### 数组
---
### 0135_分发糖果
___
#### 贪心
___
#### 数组
---
### 0136_只出现一次的数字
___
#### 位运算
___
#### 数组
---
### 0137_只出现一次的数字 II
___
#### 位运算
___
#### 数组
---
### 0138_随机链表的复制
___
#### 哈希表
___
#### 链表
---
### 0139_单词拆分
___
#### 字典树
___
#### 记忆化搜索
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 哈希表 |
| 回溯 | 图 | 字典树 |
| 字符串 | 并查集 | 广度优先搜索 |
| 数组 | 深度优先搜索 | 矩阵 |
| 记忆化搜索 | 贪心 | 链表 |

# [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions){#130}

{{< tabs "130" >}}

{{% tab "python" %}}
```python
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        m, n = len(board), len(board[0])
        p = list(range(m * n + 1))
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    if i in (0, m - 1) or j in (0, n - 1):
                        p[find(i * n + j)] = find(m * n)
                    else:
                        for a, b in pairwise((-1, 0, 1, 0, -1)):
                            x, y = i + a, j + b
                            if board[x][y] == "O":
                                p[find(x * n + y)] = find(i * n + j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O" and find(i * n + j) != find(m * n):
                    board[i][j] = "X"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        p = new int[m * n + 1];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        p[find(i * n + j)] = find(m * n);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k];
                            int y = j + dirs[k + 1];
                            if (board[x][y] == 'O') {
                                p[find(x * n + y)] = find(i * n + j);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && find(i * n + j) != find(m * n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> p(m * n + 1);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        p[find(i * n + j)] = find(m * n);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k];
                            int y = j + dirs[k + 1];
                            if (board[x][y] == 'O') {
                                p[find(x * n + y)] = find(i * n + j);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && find(i * n + j) != find(m * n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func solve(board [][]byte) {
	m, n := len(board), len(board[0])
	p := make([]int, m*n+1)
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
	dirs := [5]int{-1, 0, 1, 0, -1}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' {
				if i == 0 || i == m-1 || j == 0 || j == n-1 {
					p[find(i*n+j)] = find(m * n)
				} else {
					for k := 0; k < 4; k++ {
						x, y := i+dirs[k], j+dirs[k+1]
						if board[x][y] == 'O' {
							p[find(x*n+y)] = find(i*n + j)
						}
					}
				}
			}
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' && find(i*n+j) != find(m*n) {
				board[i][j] = 'X'
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function solve(board: string[][]): void {
    const m = board.length;
    const n = board[0].length;
    const p: number[] = Array(m * n + 1)
        .fill(0)
        .map((_, i) => i);
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === 'O') {
                if (i === 0 || i === m - 1 || j === 0 || j === n - 1) {
                    p[find(i * n + j)] = find(m * n);
                } else {
                    for (let k = 0; k < 4; ++k) {
                        const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                        if (board[x][y] === 'O') {
                            p[find(x * n + y)] = find(i * n + j);
                        }
                    }
                }
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === 'O' && find(i * n + j) !== find(m * n)) {
                board[i][j] = 'X';
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        let m = board.len();
        let n = board[0].len();
        let dirs = vec![-1, 0, 1, 0, -1];

        fn dfs(
            board: &mut Vec<Vec<char>>,
            i: usize,
            j: usize,
            dirs: &Vec<i32>,
            m: usize,
            n: usize,
        ) {
            if i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O' {
                board[i][j] = '.';
                for k in 0..4 {
                    dfs(
                        board,
                        ((i as i32) + dirs[k]) as usize,
                        ((j as i32) + dirs[k + 1]) as usize,
                        dirs,
                        m,
                        n,
                    );
                }
            }
        }

        for i in 0..m {
            dfs(board, i, 0, &dirs, m, n);
            dfs(board, i, n - 1, &dirs, m, n);
        }
        for j in 0..n {
            dfs(board, 0, j, &dirs, m, n);
            dfs(board, m - 1, j, &dirs, m, n);
        }

        for i in 0..m {
            for j in 0..n {
                if board[i][j] == '.' {
                    board[i][j] = 'O';
                } else if board[i][j] == 'O' {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private readonly int[] dirs = {-1, 0, 1, 0, -1};
    private char[][] board;
    private int m;
    private int n;

    public void Solve(char[][] board) {
        m = board.Length;
        n = board[0].Length;
        this.board = board;

        for (int i = 0; i < m; ++i) {
            Dfs(i, 0);
            Dfs(i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            Dfs(0, j);
            Dfs(m - 1, j);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private void Dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            Dfs(i + dirs[k], j + dirs[k + 1]);
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

<p>给你一个 <code>m x n</code> 的矩阵 <code>board</code> ，由若干字符 <code>'X'</code> 和 <code>'O'</code>&nbsp;组成，<strong>捕获</strong> 所有 <strong>被围绕的区域</strong>：</p>

<ul>
	<li><strong>连接：</strong>一个单元格与水平或垂直方向上相邻的单元格连接。</li>
	<li><strong>区域：连接所有&nbsp;</strong><code>'O'</code>&nbsp;的单元格来形成一个区域。</li>
	<li><strong>围绕：</strong>如果您可以用&nbsp;<code>'X'</code>&nbsp;单元格 <strong>连接这个区域</strong>，并且区域中没有任何单元格位于&nbsp;<code>board</code> 边缘，则该区域被 <code>'X'</code>&nbsp;单元格围绕。</li>
</ul>

<p>通过 <strong>原地</strong>&nbsp;将输入矩阵中的所有 <code>'O'</code>&nbsp;替换为 <code>'X'</code> 来 <strong>捕获被围绕的区域</strong>。你不需要返回任何值。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">board = [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]</span></p>

<p><b>输出：</b><span class="example-io">[['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']]</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0130.Surrounded%20Regions/images/1718167191-XNjUTG-image.png" style="width: 367px; height: 158px;" />
<p>在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">board = [['X']]</span></p>

<p><strong>输出：</strong><span class="example-io">[['X']]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> 为 <code>'X'</code> 或 <code>'O'</code></li>
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

### 方法一：DFS

我们可以从矩阵的边界开始，将矩阵边界上的每个 `O` 作为起始点，开始进行深度优先搜索。将搜索到的 `O` 全部替换成 `.`。

然后我们再遍历这个矩阵，对于每个位置：

-   如果是 `.`，则替换成 `O`；
-   否则如果是 `O`，则替换成 `X`。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def dfs(i: int, j: int):
            if not (0 <= i < m and 0 <= j < n and board[i][j] == "O"):
                return
            board[i][j] = "."
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                dfs(i + a, j + b)

        m, n = len(board), len(board[0])
        for i in range(m):
            dfs(i, 0)
            dfs(i, n - 1)
        for j in range(n):
            dfs(0, j)
            dfs(m - 1, j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == ".":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"
```

#### Java

```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private char[][] board;
    private int m;
    private int n;

    public void solve(char[][] board) {
        m = board.length;
        n = board[0].length;
        this.board = board;
        for (int i = 0; i < m; ++i) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j);
            dfs(m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private void dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            dfs(i + dirs[k], j + dirs[k + 1]);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
                return;
            }
            board[i][j] = '.';
            for (int k = 0; k < 4; ++k) {
                dfs(i + dirs[k], j + dirs[k + 1]);
            }
        };
        for (int i = 0; i < m; ++i) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            dfs(0, j);
            dfs(m - 1, j);
        }
        for (auto& row : board) {
            for (auto& c : row) {
                if (c == '.') {
                    c = 'O';
                } else if (c == 'O') {
                    c = 'X';
                }
            }
        }
    }
};
```

#### Go

```go
func solve(board [][]byte) {
	m, n := len(board), len(board[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' {
			return
		}
		board[i][j] = '.'
		for k := 0; k < 4; k++ {
			dfs(i+dirs[k], j+dirs[k+1])
		}
	}
	for i := 0; i < m; i++ {
		dfs(i, 0)
		dfs(i, n-1)
	}
	for j := 0; j < n; j++ {
		dfs(0, j)
		dfs(m-1, j)
	}
	for i, row := range board {
		for j, c := range row {
			if c == '.' {
				board[i][j] = 'O'
			} else if c == 'O' {
				board[i][j] = 'X'
			}
		}
	}
}
```

#### TypeScript

```ts
function solve(board: string[][]): void {
    const m = board.length;
    const n = board[0].length;
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): void => {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] !== 'O') {
            return;
        }
        board[i][j] = '.';
        for (let k = 0; k < 4; ++k) {
            dfs(i + dirs[k], j + dirs[k + 1]);
        }
    };
    for (let i = 0; i < m; ++i) {
        dfs(i, 0);
        dfs(i, n - 1);
    }
    for (let j = 0; j < n; ++j) {
        dfs(0, j);
        dfs(m - 1, j);
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === '.') {
                board[i][j] = 'O';
            } else if (board[i][j] === 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        let m = board.len();
        let n = board[0].len();
        let dirs = vec![-1, 0, 1, 0, -1];

        fn dfs(
            board: &mut Vec<Vec<char>>,
            i: usize,
            j: usize,
            dirs: &Vec<i32>,
            m: usize,
            n: usize,
        ) {
            if i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O' {
                board[i][j] = '.';
                for k in 0..4 {
                    dfs(
                        board,
                        ((i as i32) + dirs[k]) as usize,
                        ((j as i32) + dirs[k + 1]) as usize,
                        dirs,
                        m,
                        n,
                    );
                }
            }
        }

        for i in 0..m {
            dfs(board, i, 0, &dirs, m, n);
            dfs(board, i, n - 1, &dirs, m, n);
        }
        for j in 0..n {
            dfs(board, 0, j, &dirs, m, n);
            dfs(board, m - 1, j, &dirs, m, n);
        }

        for i in 0..m {
            for j in 0..n {
                if board[i][j] == '.' {
                    board[i][j] = 'O';
                } else if board[i][j] == 'O' {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
```

#### C#

```cs
public class Solution {
    private readonly int[] dirs = {-1, 0, 1, 0, -1};
    private char[][] board;
    private int m;
    private int n;

    public void Solve(char[][] board) {
        m = board.Length;
        n = board[0].Length;
        this.board = board;

        for (int i = 0; i < m; ++i) {
            Dfs(i, 0);
            Dfs(i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            Dfs(0, j);
            Dfs(m - 1, j);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private void Dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            Dfs(i + dirs[k], j + dirs[k + 1]);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

我们也可以使用并查集，将矩阵边界上的每个 `O` 与一个超级节点 $m \times n$ 相连，将矩阵中的每个 `O` 与其上下左右的 `O` 相连。

然后我们遍历这个矩阵，对于每个位置，如果是 `O`，并且其与超级节点不相连，则将其替换成 `X`。

时间复杂度 $O(m \times n \times \alpha(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数，$\alpha$ 是阿克曼函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        m, n = len(board), len(board[0])
        p = list(range(m * n + 1))
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    if i in (0, m - 1) or j in (0, n - 1):
                        p[find(i * n + j)] = find(m * n)
                    else:
                        for a, b in pairwise((-1, 0, 1, 0, -1)):
                            x, y = i + a, j + b
                            if board[x][y] == "O":
                                p[find(x * n + y)] = find(i * n + j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O" and find(i * n + j) != find(m * n):
                    board[i][j] = "X"
```

#### Java

```java
class Solution {
    private int[] p;

    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        p = new int[m * n + 1];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        p[find(i * n + j)] = find(m * n);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k];
                            int y = j + dirs[k + 1];
                            if (board[x][y] == 'O') {
                                p[find(x * n + y)] = find(i * n + j);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && find(i * n + j) != find(m * n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> p(m * n + 1);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        p[find(i * n + j)] = find(m * n);
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k];
                            int y = j + dirs[k + 1];
                            if (board[x][y] == 'O') {
                                p[find(x * n + y)] = find(i * n + j);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && find(i * n + j) != find(m * n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```

#### Go

```go
func solve(board [][]byte) {
	m, n := len(board), len(board[0])
	p := make([]int, m*n+1)
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
	dirs := [5]int{-1, 0, 1, 0, -1}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' {
				if i == 0 || i == m-1 || j == 0 || j == n-1 {
					p[find(i*n+j)] = find(m * n)
				} else {
					for k := 0; k < 4; k++ {
						x, y := i+dirs[k], j+dirs[k+1]
						if board[x][y] == 'O' {
							p[find(x*n+y)] = find(i*n + j)
						}
					}
				}
			}
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' && find(i*n+j) != find(m*n) {
				board[i][j] = 'X'
			}
		}
	}
}
```

#### TypeScript

```ts
function solve(board: string[][]): void {
    const m = board.length;
    const n = board[0].length;
    const p: number[] = Array(m * n + 1)
        .fill(0)
        .map((_, i) => i);
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === 'O') {
                if (i === 0 || i === m - 1 || j === 0 || j === n - 1) {
                    p[find(i * n + j)] = find(m * n);
                } else {
                    for (let k = 0; k < 4; ++k) {
                        const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                        if (board[x][y] === 'O') {
                            p[find(x * n + y)] = find(i * n + j);
                        }
                    }
                }
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === 'O' && find(i * n + j) !== find(m * n)) {
                board[i][j] = 'X';
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning){#131}

{{< tabs "131" >}}

{{% tab "python" %}}
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(i, n):
                if f[i][j]:
                    t.append(s[i : j + 1])
                    dfs(j + 1)
                    t.pop()

        n = len(s)
        f = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = s[i] == s[j] and f[i + 1][j - 1]
        ans = []
        t = []
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private String s;
    private boolean[][] f;
    private List<String> t = new ArrayList<>();
    private List<List<String>> ans = new ArrayList<>();

    public List<List<String>> partition(String s) {
        n = s.length();
        f = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(f[i], true);
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s.charAt(i) == s.charAt(j) && f[i + 1][j - 1];
            }
        }
        this.s = s;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == s.length()) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                t.add(s.substring(i, j + 1));
                dfs(j + 1);
                t.remove(t.size() - 1);
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
    vector<vector<string>> partition(string s) {
        int n = s.size();
        bool f[n][n];
        memset(f, true, sizeof(f));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
            }
        }
        vector<vector<string>> ans;
        vector<string> t;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = i; j < n; ++j) {
                if (f[i][j]) {
                    t.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    t.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func partition(s string) (ans [][]string) {
	n := len(s)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
		for j := range f[i] {
			f[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = s[i] == s[j] && f[i+1][j-1]
		}
	}
	t := []string{}
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, append([]string(nil), t...))
			return
		}
		for j := i; j < n; j++ {
			if f[i][j] {
				t = append(t, s[i:j+1])
				dfs(j + 1)
				t = t[:len(t)-1]
			}
		}
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function partition(s: string): string[][] {
    const n = s.length;
    const f: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = s[i] === s[j] && f[i + 1][j - 1];
        }
    }
    const ans: string[][] = [];
    const t: string[] = [];
    const dfs = (i: number) => {
        if (i === n) {
            ans.push(t.slice());
            return;
        }
        for (let j = i; j < n; ++j) {
            if (f[i][j]) {
                t.push(s.slice(i, j + 1));
                dfs(j + 1);
                t.pop();
            }
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int n;
    private string s;
    private bool[,] f;
    private IList<IList<string>> ans = new List<IList<string>>();
    private IList<string> t = new List<string>();

    public IList<IList<string>> Partition(string s) {
        n = s.Length;
        this.s = s;
        f = new bool[n, n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                f[i, j] = true;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i, j] = s[i] == s[j] && f[i + 1, j - 1];
            }
        }
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            ans.Add(new List<string>(t));
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i, j]) {
                t.Add(s.Substring(i, j + 1 - i));
                dfs(j + 1);
                t.RemoveAt(t.Count - 1);
            }
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

<p>给你一个字符串 <code>s</code>，请你将<em> </em><code>s</code><em> </em>分割成一些 <span data-keyword="substring-nonempty">子串</span>，使每个子串都是 <strong><span data-keyword="palindrome-string">回文串</span></strong> 。返回 <code>s</code> 所有可能的分割方案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aab"
<strong>输出：</strong>[["a","a","b"],["aa","b"]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a"
<strong>输出：</strong>[["a"]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 16</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + DFS(回溯)

我们可以使用动态规划，预处理出字符串中的任意子串是否为回文串，即 $f[i][j]$ 表示子串 $s[i..j]$ 是否为回文串。

接下来，我们设计一个函数 $dfs(i)$，表示从字符串的第 $i$ 个字符开始，分割成若干回文串，当前分割方案为 $t$。

如果 $i=|s|$，说明已经分割完成，我们将 $t$ 放入答案数组中，然后返回。

否则，我们可以从 $i$ 开始，从小到大依次枚举结束位置 $j$，如果 $s[i..j]$ 是回文串，那么就把 $s[i..j]$ 加入到 $t$ 中，然后继续递归 $dfs(j+1)$，回溯的时候要弹出 $s[i..j]$。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(i: int):
            if i == n:
                ans.append(t[:])
                return
            for j in range(i, n):
                if f[i][j]:
                    t.append(s[i : j + 1])
                    dfs(j + 1)
                    t.pop()

        n = len(s)
        f = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = s[i] == s[j] and f[i + 1][j - 1]
        ans = []
        t = []
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private String s;
    private boolean[][] f;
    private List<String> t = new ArrayList<>();
    private List<List<String>> ans = new ArrayList<>();

    public List<List<String>> partition(String s) {
        n = s.length();
        f = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(f[i], true);
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s.charAt(i) == s.charAt(j) && f[i + 1][j - 1];
            }
        }
        this.s = s;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == s.length()) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                t.add(s.substring(i, j + 1));
                dfs(j + 1);
                t.remove(t.size() - 1);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        bool f[n][n];
        memset(f, true, sizeof(f));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
            }
        }
        vector<vector<string>> ans;
        vector<string> t;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }
            for (int j = i; j < n; ++j) {
                if (f[i][j]) {
                    t.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    t.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func partition(s string) (ans [][]string) {
	n := len(s)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
		for j := range f[i] {
			f[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = s[i] == s[j] && f[i+1][j-1]
		}
	}
	t := []string{}
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, append([]string(nil), t...))
			return
		}
		for j := i; j < n; j++ {
			if f[i][j] {
				t = append(t, s[i:j+1])
				dfs(j + 1)
				t = t[:len(t)-1]
			}
		}
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function partition(s: string): string[][] {
    const n = s.length;
    const f: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = s[i] === s[j] && f[i + 1][j - 1];
        }
    }
    const ans: string[][] = [];
    const t: string[] = [];
    const dfs = (i: number) => {
        if (i === n) {
            ans.push(t.slice());
            return;
        }
        for (let j = i; j < n; ++j) {
            if (f[i][j]) {
                t.push(s.slice(i, j + 1));
                dfs(j + 1);
                t.pop();
            }
        }
    };
    dfs(0);
    return ans;
}
```

#### C#

```cs
public class Solution {
    private int n;
    private string s;
    private bool[,] f;
    private IList<IList<string>> ans = new List<IList<string>>();
    private IList<string> t = new List<string>();

    public IList<IList<string>> Partition(string s) {
        n = s.Length;
        this.s = s;
        f = new bool[n, n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                f[i, j] = true;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i, j] = s[i] == s[j] && f[i + 1, j - 1];
            }
        }
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            ans.Add(new List<string>(t));
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i, j]) {
                t.Add(s.Substring(i, j + 1 - i));
                dfs(j + 1);
                t.RemoveAt(t.Count - 1);
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [132. 分割回文串 II](https://leetcode.cn/problems/palindrome-partitioning-ii){#132}

{{< tabs "132" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        g = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = s[i] == s[j] and g[i + 1][j - 1]
        f = list(range(n))
        for i in range(1, n):
            for j in range(i + 1):
                if g[j][i]:
                    f[i] = min(f[i], 1 + f[j - 1] if j else 0)
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] g = new boolean[n][n];
        for (var row : g) {
            Arrays.fill(row, true);
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = s.charAt(i) == s.charAt(j) && g[i + 1][j - 1];
            }
        }
        int[] f = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (g[j][i]) {
                    f[i] = Math.min(f[i], j > 0 ? 1 + f[j - 1] : 0);
                }
            }
        }
        return f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool g[n][n];
        memset(g, true, sizeof(g));
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = s[i] == s[j] && g[i + 1][j - 1];
            }
        }
        int f[n];
        iota(f, f + n, 0);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (g[j][i]) {
                    f[i] = min(f[i], j ? 1 + f[j - 1] : 0);
                }
            }
        }
        return f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCut(s string) int {
	n := len(s)
	g := make([][]bool, n)
	f := make([]int, n)
	for i := range g {
		g[i] = make([]bool, n)
		f[i] = i
		for j := range g[i] {
			g[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			g[i][j] = s[i] == s[j] && g[i+1][j-1]
		}
	}
	for i := 1; i < n; i++ {
		for j := 0; j <= i; j++ {
			if g[j][i] {
				if j == 0 {
					f[i] = 0
				} else {
					f[i] = min(f[i], f[j-1]+1)
				}
			}
		}
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCut(s: string): number {
    const n = s.length;
    const g: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            g[i][j] = s[i] === s[j] && g[i + 1][j - 1];
        }
    }
    const f: number[] = Array.from({ length: n }, (_, i) => i);
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j <= i; ++j) {
            if (g[j][i]) {
                f[i] = Math.min(f[i], j ? 1 + f[j - 1] : 0);
            }
        }
    }
    return f[n - 1];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinCut(string s) {
        int n = s.Length;
        bool[,] g = new bool[n,n];
        int[] f = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            for (int j = 0; j < n; ++j) {
                g[i,j] = true;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i,j] = s[i] == s[j] && g[i + 1,j - 1];
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (g[j,i]) {
                    f[i] = Math.Min(f[i], j > 0 ? 1 + f[j - 1] : 0);
                }
            }
        }
        return f[n - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>，请你将 <code>s</code> 分割成一些子串，使每个子串都是<span data-keyword="palindrome-string">回文串</span>。</p>

<p>返回符合要求的 <strong>最少分割次数</strong> 。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aab"
<strong>输出：</strong>1
<strong>解释：</strong>只需一次分割就可将&nbsp;<em>s </em>分割成 ["aa","b"] 这样两个回文子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a"
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "ab"
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
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

### 方法一：动态规划

我们先预处理得到字符串 $s$ 的每一个子串 $s[i..j]$ 是否为回文串，记录在二维数组 $g[i][j]$ 中，其中 $g[i][j]$ 表示子串 $s[i..j]$ 是否为回文串。

接下来，我们定义 $f[i]$ 表示字符串 $s[0..i-1]$ 的最少分割次数，初始时 $f[i]=i$。

接下来，我们考虑 $f[i]$ 如何进行状态转移。我们可以枚举上一个分割点 $j$，如果子串 $s[j..i]$ 是一个回文串，那么 $f[i]$ 就可以从 $f[j]$ 转移而来。如果 $j=0$，那么说明 $s[0..i]$ 本身就是一个回文串，此时不需要进行分割，即 $f[i]=0$。因此，状态转移方程如下：

$$
f[i]=\min_{0\leq j \leq i}\begin{cases} f[j-1]+1, & \textit{if}\ g[j][i]=\textit{True} \\ 0, & \textit{if}\ g[0][i]=\textit{True} \end{cases}
$$

答案即为 $f[n]$，其中 $n$ 是字符串 $s$ 的长度。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        g = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = s[i] == s[j] and g[i + 1][j - 1]
        f = list(range(n))
        for i in range(1, n):
            for j in range(i + 1):
                if g[j][i]:
                    f[i] = min(f[i], 1 + f[j - 1] if j else 0)
        return f[-1]
```

#### Java

```java
class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] g = new boolean[n][n];
        for (var row : g) {
            Arrays.fill(row, true);
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = s.charAt(i) == s.charAt(j) && g[i + 1][j - 1];
            }
        }
        int[] f = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (g[j][i]) {
                    f[i] = Math.min(f[i], j > 0 ? 1 + f[j - 1] : 0);
                }
            }
        }
        return f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool g[n][n];
        memset(g, true, sizeof(g));
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = s[i] == s[j] && g[i + 1][j - 1];
            }
        }
        int f[n];
        iota(f, f + n, 0);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (g[j][i]) {
                    f[i] = min(f[i], j ? 1 + f[j - 1] : 0);
                }
            }
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func minCut(s string) int {
	n := len(s)
	g := make([][]bool, n)
	f := make([]int, n)
	for i := range g {
		g[i] = make([]bool, n)
		f[i] = i
		for j := range g[i] {
			g[i][j] = true
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			g[i][j] = s[i] == s[j] && g[i+1][j-1]
		}
	}
	for i := 1; i < n; i++ {
		for j := 0; j <= i; j++ {
			if g[j][i] {
				if j == 0 {
					f[i] = 0
				} else {
					f[i] = min(f[i], f[j-1]+1)
				}
			}
		}
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function minCut(s: string): number {
    const n = s.length;
    const g: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            g[i][j] = s[i] === s[j] && g[i + 1][j - 1];
        }
    }
    const f: number[] = Array.from({ length: n }, (_, i) => i);
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j <= i; ++j) {
            if (g[j][i]) {
                f[i] = Math.min(f[i], j ? 1 + f[j - 1] : 0);
            }
        }
    }
    return f[n - 1];
}
```

#### C#

```cs
public class Solution {
    public int MinCut(string s) {
        int n = s.Length;
        bool[,] g = new bool[n,n];
        int[] f = new int[n];
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            for (int j = 0; j < n; ++j) {
                g[i,j] = true;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i,j] = s[i] == s[j] && g[i + 1,j - 1];
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (g[j,i]) {
                    f[i] = Math.Min(f[i], j > 0 ? 1 + f[j - 1] : 0);
                }
            }
        }
        return f[n - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [133. 克隆图](https://leetcode.cn/problems/clone-graph){#133}

{{< tabs "133" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        def dfs(node):
            if node is None:
                return None
            if node in g:
                return g[node]
            cloned = Node(node.val)
            g[node] = cloned
            for nxt in node.neighbors:
                cloned.neighbors.append(dfs(nxt))
            return cloned

        g = defaultdict()
        return dfs(node)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private Map<Node, Node> g = new HashMap<>();

    public Node cloneGraph(Node node) {
        return dfs(node);
    }

    private Node dfs(Node node) {
        if (node == null) {
            return null;
        }
        Node cloned = g.get(node);
        if (cloned == null) {
            cloned = new Node(node.val);
            g.put(node, cloned);
            for (Node nxt : node.neighbors) {
                cloned.neighbors.add(dfs(nxt));
            }
        }
        return cloned;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> g;
        auto dfs = [&](this auto&& dfs, Node* node) -> Node* {
            if (!node) {
                return nullptr;
            }
            if (g.contains(node)) {
                return g[node];
            }
            Node* cloned = new Node(node->val);
            g[node] = cloned;
            for (auto& nxt : node->neighbors) {
                cloned->neighbors.push_back(dfs(nxt));
            }
            return cloned;
        };
        return dfs(node);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
	g := map[*Node]*Node{}
	var dfs func(node *Node) *Node
	dfs = func(node *Node) *Node {
		if node == nil {
			return nil
		}
		if n, ok := g[node]; ok {
			return n
		}
		cloned := &Node{node.Val, []*Node{}}
		g[node] = cloned
		for _, nxt := range node.Neighbors {
			cloned.Neighbors = append(cloned.Neighbors, dfs(nxt))
		}
		return cloned
	}
	return dfs(node)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     neighbors: _Node[]
 *
 *     constructor(val?: number, neighbors?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 *
 */

function cloneGraph(node: _Node | null): _Node | null {
    const g: Map<_Node, _Node> = new Map();
    const dfs = (node: _Node | null): _Node | null => {
        if (!node) {
            return null;
        }
        if (g.has(node)) {
            return g.get(node);
        }
        const cloned = new _Node(node.val);
        g.set(node, cloned);
        for (const nxt of node.neighbors) {
            cloned.neighbors.push(dfs(nxt));
        }
        return cloned;
    };
    return dfs(node);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function (node) {
    const g = new Map();
    const dfs = node => {
        if (!node) {
            return null;
        }
        if (g.has(node)) {
            return g.get(node);
        }
        const cloned = new _Node(node.val);
        g.set(node, cloned);
        for (const nxt of node.neighbors) {
            cloned.neighbors.push(dfs(nxt));
        }
        return cloned;
    };
    return dfs(node);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    public Node CloneGraph(Node node) {
        var g = new Dictionary<Node, Node>();
        Node Dfs(Node n) {
            if (n == null) {
                return null;
            }
            if (g.ContainsKey(n)) {
                return g[n];
            }
            var cloned = new Node(n.val);
            g[n] = cloned;
            foreach (var neighbor in n.neighbors) {
                cloned.neighbors.Add(Dfs(neighbor));
            }
            return cloned;
        }
        return Dfs(node);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你无向&nbsp;<strong><a href="https://baike.baidu.com/item/连通图/6460995?fr=aladdin" target="_blank">连通</a>&nbsp;</strong>图中一个节点的引用，请你返回该图的&nbsp;<a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin" target="_blank"><strong>深拷贝</strong></a>（克隆）。</p>

<p>图中的每个节点都包含它的值 <code>val</code>（<code>int</code>） 和其邻居的列表（<code>list[Node]</code>）。</p>

<pre>
class Node {
    public int val;
    public List&lt;Node&gt; neighbors;
}</pre>

<p>&nbsp;</p>

<p><strong>测试用例格式：</strong></p>

<p>简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（<code>val = 1</code>），第二个节点值为 2（<code>val = 2</code>），以此类推。该图在测试用例中使用邻接列表表示。</p>

<p><strong>邻接列表</strong> 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。</p>

<p>给定节点将始终是图中的第一个节点（值为 1）。你必须将&nbsp;<strong>给定节点的拷贝&nbsp;</strong>作为对克隆图的引用返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0133.Clone%20Graph/images/133_clone_graph_question.png" style="height: 500px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>adjList = [[2,4],[1,3],[2,4],[1,3]]
<strong>输出：</strong>[[2,4],[1,3],[2,4],[1,3]]
<strong>解释：
</strong>图中有 4 个节点。
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0133.Clone%20Graph/images/graph.png" style="height: 148px; width: 163px;" /></p>

<pre>
<strong>输入：</strong>adjList = [[]]
<strong>输出：</strong>[[]]
<strong>解释：</strong>输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>adjList = []
<strong>输出：</strong>[]
<strong>解释：</strong>这个图是空的，它不含任何节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>这张图中的节点数在 <code>[0, 100]</code>&nbsp;之间。</li>
	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
	<li>每个节点值&nbsp;<code>Node.val</code> 都是唯一的，</li>
	<li>图中没有重复的边，也没有自环。</li>
	<li>图是连通图，你可以从给定节点访问到所有节点。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + DFS

我们用一个哈希表 $\textit{g}$ 记录原图中的每个节点和它的拷贝节点之间的对应关系，然后进行深度优先搜索。

我们定义函数 $\text{dfs}(node)$，它的功能是返回 $\textit{node}$ 节点的拷贝节点。$\text{dfs}(node)$ 的过程如下：

-   如果 $\textit{node}$ 是 $\text{null}$，那么 $\text{dfs}(node)$ 的返回值是 $\text{null}$。
-   如果 $\textit{node}$ 在 $\textit{g}$ 中，那么 $\text{dfs}(node)$ 的返回值是 $\textit{g}[node]$。
-   否则我们创建一个新的节点 $\textit{cloned}$，并将 $\textit{g}[node]$ 的值设为 $\textit{cloned}$，然后遍历 $\textit{node}$ 的所有邻居节点 $\textit{nxt}$，并将 $\textit{cloned}$ 的邻居节点列表中加入 $\text{dfs}(nxt)$。
-   最后返回 $\textit{cloned}$。

在主函数中，我们返回 $\text{dfs}(node)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点的数量。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        def dfs(node):
            if node is None:
                return None
            if node in g:
                return g[node]
            cloned = Node(node.val)
            g[node] = cloned
            for nxt in node.neighbors:
                cloned.neighbors.append(dfs(nxt))
            return cloned

        g = defaultdict()
        return dfs(node)
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private Map<Node, Node> g = new HashMap<>();

    public Node cloneGraph(Node node) {
        return dfs(node);
    }

    private Node dfs(Node node) {
        if (node == null) {
            return null;
        }
        Node cloned = g.get(node);
        if (cloned == null) {
            cloned = new Node(node.val);
            g.put(node, cloned);
            for (Node nxt : node.neighbors) {
                cloned.neighbors.add(dfs(nxt));
            }
        }
        return cloned;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> g;
        auto dfs = [&](this auto&& dfs, Node* node) -> Node* {
            if (!node) {
                return nullptr;
            }
            if (g.contains(node)) {
                return g[node];
            }
            Node* cloned = new Node(node->val);
            g[node] = cloned;
            for (auto& nxt : node->neighbors) {
                cloned->neighbors.push_back(dfs(nxt));
            }
            return cloned;
        };
        return dfs(node);
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
	g := map[*Node]*Node{}
	var dfs func(node *Node) *Node
	dfs = func(node *Node) *Node {
		if node == nil {
			return nil
		}
		if n, ok := g[node]; ok {
			return n
		}
		cloned := &Node{node.Val, []*Node{}}
		g[node] = cloned
		for _, nxt := range node.Neighbors {
			cloned.Neighbors = append(cloned.Neighbors, dfs(nxt))
		}
		return cloned
	}
	return dfs(node)
}
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     neighbors: _Node[]
 *
 *     constructor(val?: number, neighbors?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 *
 */

function cloneGraph(node: _Node | null): _Node | null {
    const g: Map<_Node, _Node> = new Map();
    const dfs = (node: _Node | null): _Node | null => {
        if (!node) {
            return null;
        }
        if (g.has(node)) {
            return g.get(node);
        }
        const cloned = new _Node(node.val);
        g.set(node, cloned);
        for (const nxt of node.neighbors) {
            cloned.neighbors.push(dfs(nxt));
        }
        return cloned;
    };
    return dfs(node);
}
```

#### JavaScript

```js
/**
 * // Definition for a _Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function (node) {
    const g = new Map();
    const dfs = node => {
        if (!node) {
            return null;
        }
        if (g.has(node)) {
            return g.get(node);
        }
        const cloned = new _Node(node.val);
        g.set(node, cloned);
        for (const nxt of node.neighbors) {
            cloned.neighbors.push(dfs(nxt));
        }
        return cloned;
    };
    return dfs(node);
};
```

#### C#

```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    public Node CloneGraph(Node node) {
        var g = new Dictionary<Node, Node>();
        Node Dfs(Node n) {
            if (n == null) {
                return null;
            }
            if (g.ContainsKey(n)) {
                return g[n];
            }
            var cloned = new Node(n.val);
            g[n] = cloned;
            foreach (var neighbor in n.neighbors) {
                cloned.neighbors.Add(Dfs(neighbor));
            }
            return cloned;
        }
        return Dfs(node);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [134. 加油站](https://leetcode.cn/problems/gas-station){#134}

{{< tabs "134" >}}

{{% tab "python" %}}
```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        i = j = n - 1
        cnt = s = 0
        while cnt < n:
            s += gas[j] - cost[j]
            cnt += 1
            j = (j + 1) % n
            while s < 0 and cnt < n:
                i -= 1
                s += gas[i] - cost[i]
                cnt += 1
        return -1 if s < 0 else i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int i = n - 1, j = n - 1;
        int cnt = 0, s = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = n - 1, j = n - 1;
        int cnt = 0, s = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canCompleteCircuit(gas []int, cost []int) int {
	n := len(gas)
	i, j := n-1, n-1
	cnt, s := 0, 0
	for cnt < n {
		s += gas[j] - cost[j]
		cnt++
		j = (j + 1) % n
		for s < 0 && cnt < n {
			i--
			s += gas[i] - cost[i]
			cnt++
		}
	}
	if s < 0 {
		return -1
	}
	return i
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canCompleteCircuit(gas: number[], cost: number[]): number {
    const n = gas.length;
    let i = n - 1;
    let j = n - 1;
    let s = 0;
    let cnt = 0;
    while (cnt < n) {
        s += gas[j] - cost[j];
        ++cnt;
        j = (j + 1) % n;
        while (s < 0 && cnt < n) {
            --i;
            s += gas[i] - cost[i];
            ++cnt;
        }
    }
    return s < 0 ? -1 : i;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.Length;
        int i = n - 1, j = n - 1;
        int s = 0, cnt = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一条环路上有 <code>n</code>&nbsp;个加油站，其中第 <code>i</code>&nbsp;个加油站有汽油&nbsp;<code>gas[i]</code><em>&nbsp;</em>升。</p>

<p>你有一辆油箱容量无限的的汽车，从第<em> </em><code>i</code><em> </em>个加油站开往第<em> </em><code>i+1</code><em>&nbsp;</em>个加油站需要消耗汽油&nbsp;<code>cost[i]</code><em>&nbsp;</em>升。你从其中的一个加油站出发，开始时油箱为空。</p>

<p>给定两个整数数组 <code>gas</code> 和 <code>cost</code> ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 <code>-1</code> 。如果存在解，则 <strong>保证</strong> 它是 <strong>唯一</strong> 的。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> gas = [1,2,3,4,5], cost = [3,4,5,1,2]
<strong>输出:</strong> 3
<strong>解释:
</strong>从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> gas = [2,3,4], cost = [3,4,3]
<strong>输出:</strong> -1
<strong>解释:
</strong>你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == gas.length == cost.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= gas[i], cost[i] &lt;= 10<sup>4</sup></code></li>
	<li>输入保证答案唯一。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：从任意起点开始遍历

我们用 $i$, $j$ 分别标记起点和终点，用 $s$ 表示当前剩余汽油，而 $cnt$ 表示当前行驶过的加油站数量。初始时，我们将起点设在最后一个位置，即 $i=n-1$。

开始行驶，移动 $j$。若发现当前剩余汽油小于 $0$，说明当前 $i$ 作为起点不符合要求，我们将起点 $i$ 循环左移，并且更新剩余汽油，直至剩余汽油是非负数。

当行驶过的加油站数量达到 $n$ 时，结束行驶过程。若此时剩余汽油 $s$ 仍然小于 $0$，说明不存在这样的起点，返回 $-1$。否则，返回起点 $i$。

时间复杂度 $O(n)$，其中 $n$ 表示加油站的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        i = j = n - 1
        cnt = s = 0
        while cnt < n:
            s += gas[j] - cost[j]
            cnt += 1
            j = (j + 1) % n
            while s < 0 and cnt < n:
                i -= 1
                s += gas[i] - cost[i]
                cnt += 1
        return -1 if s < 0 else i
```

#### Java

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int i = n - 1, j = n - 1;
        int cnt = 0, s = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = n - 1, j = n - 1;
        int cnt = 0, s = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
};
```

#### Go

```go
func canCompleteCircuit(gas []int, cost []int) int {
	n := len(gas)
	i, j := n-1, n-1
	cnt, s := 0, 0
	for cnt < n {
		s += gas[j] - cost[j]
		cnt++
		j = (j + 1) % n
		for s < 0 && cnt < n {
			i--
			s += gas[i] - cost[i]
			cnt++
		}
	}
	if s < 0 {
		return -1
	}
	return i
}
```

#### TypeScript

```ts
function canCompleteCircuit(gas: number[], cost: number[]): number {
    const n = gas.length;
    let i = n - 1;
    let j = n - 1;
    let s = 0;
    let cnt = 0;
    while (cnt < n) {
        s += gas[j] - cost[j];
        ++cnt;
        j = (j + 1) % n;
        while (s < 0 && cnt < n) {
            --i;
            s += gas[i] - cost[i];
            ++cnt;
        }
    }
    return s < 0 ? -1 : i;
}
```

#### C#

```cs
public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.Length;
        int i = n - 1, j = n - 1;
        int s = 0, cnt = 0;
        while (cnt < n) {
            s += gas[j] - cost[j];
            ++cnt;
            j = (j + 1) % n;
            while (s < 0 && cnt < n) {
                --i;
                s += gas[i] - cost[i];
                ++cnt;
            }
        }
        return s < 0 ? -1 : i;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [135. 分发糖果](https://leetcode.cn/problems/candy){#135}

{{< tabs "135" >}}

{{% tab "python" %}}
```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
        return sum(max(a, b) for a, b in zip(left, right))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.max(left[i], right[i]);
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
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; ~i; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func candy(ratings []int) int {
	n := len(ratings)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = 1
		right[i] = 1
	}
	for i := 1; i < n; i++ {
		if ratings[i] > ratings[i-1] {
			left[i] = left[i-1] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] {
			right[i] = right[i+1] + 1
		}
	}
	ans := 0
	for i, a := range left {
		b := right[i]
		ans += max(a, b)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function candy(ratings: number[]): number {
    const n = ratings.length;
    const left = new Array(n).fill(1);
    const right = new Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    for (let i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += Math.max(left[i], right[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let n = ratings.len();
        let mut left = vec![1; n];
        let mut right = vec![1; n];

        for i in 1..n {
            if ratings[i] > ratings[i - 1] {
                left[i] = left[i - 1] + 1;
            }
        }

        for i in (0..n - 1).rev() {
            if ratings[i] > ratings[i + 1] {
                right[i] = right[i + 1] + 1;
            }
        }

        ratings.iter()
            .enumerate()
            .map(|(i, _)| left[i].max(right[i]) as i32)
            .sum()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Candy(int[] ratings) {
        int n = ratings.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        Array.Fill(left, 1);
        Array.Fill(right, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.Max(left[i], right[i]);
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

<p><code>n</code> 个孩子站成一排。给你一个整数数组 <code>ratings</code> 表示每个孩子的评分。</p>

<p>你需要按照以下要求，给这些孩子分发糖果：</p>

<ul>
	<li>每个孩子至少分配到 <code>1</code> 个糖果。</li>
	<li>相邻两个孩子中，评分更高的那个会获得更多的糖果。</li>
</ul>

<p>请你给每个孩子分发糖果，计算并返回需要准备的 <strong>最少糖果数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>ratings = [1,0,2]
<strong>输出：</strong>5
<strong>解释：</strong>你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>ratings = [1,2,2]
<strong>输出：</strong>4
<strong>解释：</strong>你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == ratings.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ratings[i] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

我们初始化两个数组 $left$ 和 $right$，其中 $left[i]$ 表示当前孩子比左边孩子评分高时，当前孩子至少应该获得的糖果数，而 $right[i]$ 表示当前孩子比右边孩子评分高时，当前孩子至少应该获得的糖果数。初始时 $left[i]=1$, $right[i]=1$。

我们从左到右遍历一遍，如果当前孩子比左边孩子评分高，则 $left[i]=left[i-1]+1$；同理，我们从右到左遍历一遍，如果当前孩子比右边孩子评分高，则 $right[i]=right[i+1]+1$。

最后，我们遍历一遍评分数组，每个孩子至少应该获得的糖果数为 $left[i]$ 和 $right[i]$ 中的最大值，将它们累加起来即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是评分数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
        return sum(max(a, b) for a, b in zip(left, right))
```

#### Java

```java
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.max(left[i], right[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; ~i; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func candy(ratings []int) int {
	n := len(ratings)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = 1
		right[i] = 1
	}
	for i := 1; i < n; i++ {
		if ratings[i] > ratings[i-1] {
			left[i] = left[i-1] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if ratings[i] > ratings[i+1] {
			right[i] = right[i+1] + 1
		}
	}
	ans := 0
	for i, a := range left {
		b := right[i]
		ans += max(a, b)
	}
	return ans
}
```

#### TypeScript

```ts
function candy(ratings: number[]): number {
    const n = ratings.length;
    const left = new Array(n).fill(1);
    const right = new Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    for (let i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += Math.max(left[i], right[i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let n = ratings.len();
        let mut left = vec![1; n];
        let mut right = vec![1; n];

        for i in 1..n {
            if ratings[i] > ratings[i - 1] {
                left[i] = left[i - 1] + 1;
            }
        }

        for i in (0..n - 1).rev() {
            if ratings[i] > ratings[i + 1] {
                right[i] = right[i + 1] + 1;
            }
        }

        ratings.iter()
            .enumerate()
            .map(|(i, _)| left[i].max(right[i]) as i32)
            .sum()
    }
}
```

#### C#

```cs
public class Solution {
    public int Candy(int[] ratings) {
        int n = ratings.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        Array.Fill(left, 1);
        Array.Fill(right, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.Max(left[i], right[i]);
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

# [136. 只出现一次的数字](https://leetcode.cn/problems/single-number){#136}

{{< tabs "136" >}}

{{% tab "python" %}}
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int singleNumber(int[] nums) {
        return Arrays.stream(nums).reduce(0, (a, b) -> a ^ b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int v : nums) {
            ans ^= v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func singleNumber(nums []int) (ans int) {
	for _, v := range nums {
		ans ^= v
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function singleNumber(nums: number[]): number {
    return nums.reduce((r, v) => r ^ v);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.into_iter().reduce(|r, v| r ^ v).unwrap()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    return nums.reduce((a, b) => a ^ b);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int SingleNumber(int[] nums) {
        return nums.Aggregate(0, (a, b) => a ^ b);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        return nums.reduce(0, ^)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非空</strong> 整数数组 <code>nums</code> ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。</p>

<p>你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>nums = [2,2,1]</p>

<p><strong>输出：</strong>1</p>
</div>

<p><strong class="example">示例 2 ：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>nums = [4,1,2,1,2]</p>

<p><strong>输出：</strong>4</p>
</div>

<p><strong class="example">示例 3 ：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>nums = [1]</p>

<p><strong>输出：</strong>1</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup> &lt;= nums[i] &lt;= 3 * 10<sup>4</sup></code></li>
	<li>除了某个元素只出现一次以外，其余每个元素均出现两次。</li>
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

### 方法一：位运算

异或运算的性质：

-   任何数和 $0$ 做异或运算，结果仍然是原来的数，即 $x \oplus 0 = x$；
-   任何数和其自身做异或运算，结果是 $0$，即 $x \oplus x = 0$；

我们对该数组所有元素进行异或运算，结果就是那个只出现一次的数字。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums)
```

#### Java

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int v : nums) {
            ans ^= v;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int v : nums) {
            ans ^= v;
        }
        return ans;
    }
};
```

#### Go

```go
func singleNumber(nums []int) (ans int) {
	for _, v := range nums {
		ans ^= v
	}
	return
}
```

#### TypeScript

```ts
function singleNumber(nums: number[]): number {
    return nums.reduce((r, v) => r ^ v);
}
```

#### Rust

```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.into_iter().reduce(|r, v| r ^ v).unwrap()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    return nums.reduce((a, b) => a ^ b);
};
```

#### C#

```cs
public class Solution {
    public int SingleNumber(int[] nums) {
        return nums.Aggregate(0, (a, b) => a ^ b);
    }
}
```

#### C

```c
int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}
```

#### Swift

```swift
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        return nums.reduce(0, ^)
    }
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
    public int singleNumber(int[] nums) {
        return Arrays.stream(nums).reduce(0, (a, b) -> a ^ b);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [137. 只出现一次的数字 II](https://leetcode.cn/problems/single-number-ii){#137}

{{< tabs "137" >}}

{{% tab "python" %}}
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = b = 0
        for c in nums:
            aa = (~a & b & c) | (a & ~b & ~c)
            bb = ~a & (b ^ c)
            a, b = aa, bb
        return b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int singleNumber(int[] nums) {
        int a = 0, b = 0;
        for (int c : nums) {
            int aa = (~a & b & c) | (a & ~b & ~c);
            int bb = ~a & (b ^ c);
            a = aa;
            b = bb;
        }
        return b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int c : nums) {
            int aa = (~a & b & c) | (a & ~b & ~c);
            int bb = ~a & (b ^ c);
            a = aa;
            b = bb;
        }
        return b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func singleNumber(nums []int) int {
	a, b := 0, 0
	for _, c := range nums {
		aa := (^a & b & c) | (a & ^b & ^c)
		bb := ^a & (b ^ c)
		a, b = aa, bb
	}
	return b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function singleNumber(nums) {
    let [ans, acc] = [0, 0];

    for (const x of nums) {
        ans ^= x & ~acc;
        acc ^= x & ~ans;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function singleNumber(nums) {
    const sumOfUnique = [...new Set(nums)].reduce((a, b) => a + b, 0);
    const sum = nums.reduce((a, b) => a + b, 0);
    return (sumOfUnique * 3 - sum) / 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut a = 0;
        let mut b = 0;

        for c in nums {
            let aa = (!a & b & c) | (a & !b & !c);
            let bb = !a & (b ^ c);
            a = aa;
            b = bb;
        }

        return b;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] >> i & 1) {
                count++;
            }
        }
        ans |= (uint) (count % 3) << i;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var a = nums.sorted()
        var n = a.count
        for i in stride(from: 0, through: n - 2, by: 3) {
            if a[i] != a[i + 1] {
                return a[i]
            }
        }
        return a[n - 1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code> ，除某个元素仅出现 <strong>一次</strong> 外，其余每个元素都恰出现 <strong>三次 。</strong>请你找出并返回那个只出现了一次的元素。</p>

<p>你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,3,2]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,0,1,0,1,99]
<strong>输出：</strong>99
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums</code> 中，除某个元素仅出现 <strong>一次</strong> 外，其余每个元素都恰出现 <strong>三次</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以枚举每个二进制位 $i$，对于每个二进制位，我们统计所有数字在该二进制位上的和，如果该二进制位上的和能被 $3$ 整除，那么只出现一次的数字在该二进制位上为 $0$，否则为 $1$。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(1)$。其中 $n$ 和 $M$ 分别是数组的长度和数组中元素的范围。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            cnt = sum(num >> i & 1 for num in nums)
            if cnt % 3:
                if i == 31:
                    ans -= 1 << i
                else:
                    ans |= 1 << i
        return ans
```

#### Java

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int num : nums) {
                cnt += num >> i & 1;
            }
            cnt %= 3;
            ans |= cnt << i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num : nums) {
                cnt += ((num >> i) & 1);
            }
            cnt %= 3;
            ans |= cnt << i;
        }
        return ans;
    }
};
```

#### Go

```go
func singleNumber(nums []int) int {
	ans := int32(0)
	for i := 0; i < 32; i++ {
		cnt := int32(0)
		for _, num := range nums {
			cnt += int32(num) >> i & 1
		}
		cnt %= 3
		ans |= cnt << i
	}
	return int(ans)
}
```

#### TypeScript

```ts
function singleNumber(nums: number[]): number {
    let ans = 0;
    for (let i = 0; i < 32; i++) {
        const count = nums.reduce((r, v) => r + ((v >> i) & 1), 0);
        ans |= count % 3 << i;
    }
    return ans;
}
```

#### JavaScript

```js
function singleNumber(nums) {
    let ans = 0;
    for (let i = 0; i < 32; i++) {
        const count = nums.reduce((r, v) => r + ((v >> i) & 1), 0);
        ans |= count % 3 << i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 0..32 {
            let count = nums.iter().map(|v| (v >> i) & 1).sum::<i32>();
            ans |= count % 3 << i;
        }
        ans
    }
}
```

#### C

```c
int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] >> i & 1) {
                count++;
            }
        }
        ans |= (uint) (count % 3) << i;
    }
    return ans;
}
```

#### Swift

```swift
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var a = nums.sorted()
        var n = a.count
        for i in stride(from: 0, through: n - 2, by: 3) {
            if a[i] != a[i + 1] {
                return a[i]
            }
        }
        return a[n - 1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数字电路

我们考虑一种更高效的方法，该方法使用数字电路来模拟上述的位运算。

一个整数的每个二进制位是 $0$ 或 $1$，只能表示 $2$ 种状态。但我们需要表示当前遍历过的所有整数的第 $i$ 位之和模 $3$ 的结果，因此，我们可以使用 $a$ 和 $b$ 两个整数来表示。那么会有以下三种情况：

1. 整数 $a$ 的第 $i$ 位为 $0$ 且整数 $b$ 的第 $i$ 位为 $0$，表示模 $3$ 结果是 $0$；
1. 整数 $a$ 的第 $i$ 位为 $0$ 且整数 $b$ 的第 $i$ 位为 $1$，表示模 $3$ 结果是 $1$；
1. 整数 $a$ 的第 $i$ 位为 $1$ 且整数 $b$ 的第 $i$ 位为 $0$，表示模 $3$ 结果是 $2$。

我们用整数 $c$ 表示当前要读入的数，那么有以下真值表：

| $a_i$ | $b_i$ | $c_i$ | 新的 $a_i$ | 新的 $b_i$ |
| ----- | ----- | ----- | ---------- | ---------- |
| 0     | 0     | 0     | 0          | 0          |
| 0     | 0     | 1     | 0          | 1          |
| 0     | 1     | 0     | 0          | 1          |
| 0     | 1     | 1     | 1          | 0          |
| 1     | 0     | 0     | 1          | 0          |
| 1     | 0     | 1     | 0          | 0          |

基于以上真值表，我们可以写出逻辑表达式：

$$
a_i = a_i' b_i c_i + a_i b_i' c_i'
$$

以及：

$$
b_i = a_i' b_i' c_i + a_i' b_i c_i' = a_i' (b_i \oplus c_i)
$$

最后结果是 $b$，因为 $b$ 的二进制位上为 $1$ 时表示这个数字出现了 $1$ 次。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = b = 0
        for c in nums:
            aa = (~a & b & c) | (a & ~b & ~c)
            bb = ~a & (b ^ c)
            a, b = aa, bb
        return b
```

#### Java

```java
class Solution {
    public int singleNumber(int[] nums) {
        int a = 0, b = 0;
        for (int c : nums) {
            int aa = (~a & b & c) | (a & ~b & ~c);
            int bb = ~a & (b ^ c);
            a = aa;
            b = bb;
        }
        return b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int c : nums) {
            int aa = (~a & b & c) | (a & ~b & ~c);
            int bb = ~a & (b ^ c);
            a = aa;
            b = bb;
        }
        return b;
    }
};
```

#### Go

```go
func singleNumber(nums []int) int {
	a, b := 0, 0
	for _, c := range nums {
		aa := (^a & b & c) | (a & ^b & ^c)
		bb := ^a & (b ^ c)
		a, b = aa, bb
	}
	return b
}
```

#### TypeScript

```ts
function singleNumber(nums: number[]): number {
    let a = 0;
    let b = 0;
    for (const c of nums) {
        const aa = (~a & b & c) | (a & ~b & ~c);
        const bb = ~a & (b ^ c);
        a = aa;
        b = bb;
    }
    return b;
}
```

#### JavaScript

```js
function singleNumber(nums) {
    let a = 0;
    let b = 0;
    for (const c of nums) {
        const aa = (~a & b & c) | (a & ~b & ~c);
        const bb = ~a & (b ^ c);
        a = aa;
        b = bb;
    }
    return b;
}
```

#### Rust

```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut a = 0;
        let mut b = 0;

        for c in nums {
            let aa = (!a & b & c) | (a & !b & !c);
            let bb = !a & (b ^ c);
            a = aa;
            b = bb;
        }

        return b;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：哈希表 + 数学

<!-- tabs:start -->

#### TypeScript

```ts
function singleNumber(nums: number[]): number {
    const sumOfUnique = [...new Set(nums)].reduce((a, b) => a + b, 0);
    const sum = nums.reduce((a, b) => a + b, 0);
    return (sumOfUnique * 3 - sum) / 2;
}
```

#### JavaScript

```js
function singleNumber(nums) {
    const sumOfUnique = [...new Set(nums)].reduce((a, b) => a + b, 0);
    const sum = nums.reduce((a, b) => a + b, 0);
    return (sumOfUnique * 3 - sum) / 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法四：位运算

<!-- tabs:start -->

#### TypeScript

```ts
function singleNumber(nums: number[]): number {
    let [ans, acc] = [0, 0];

    for (const x of nums) {
        ans ^= x & ~acc;
        acc ^= x & ~ans;
    }

    return ans;
}
```

#### JavaScript

```ts
function singleNumber(nums) {
    let [ans, acc] = [0, 0];

    for (const x of nums) {
        ans ^= x & ~acc;
        acc ^= x & ~ans;
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [138. 随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer){#138}

{{< tabs "138" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if head is None:
            return None
        cur = head
        while cur:
            node = Node(cur.val, cur.next)
            cur.next = node
            cur = node.next
        cur = head
        while cur:
            cur.next.random = cur.random.next if cur.random else None
            cur = cur.next.next
        cur = head
        ans = head.next
        while cur.next:
            node = cur.next
            cur.next = node.next
            cur = node
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

public class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Node cur = head;
        while (cur != null) {
            Node node = new Node(cur.val);
            node.next = cur.next;
            cur.next = node;
            cur = node.next;
        }
        cur = head;
        while (cur != null) {
            cur.next.random = cur.random == null ? null : cur.random.next;
            cur = cur.next.next;
        }
        cur = head;
        Node ans = head.next;
        while (cur.next != null) {
            Node node = cur.next;
            cur.next = node.next;
            cur = node;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* cur = head;
        while (cur != nullptr) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur != nullptr) {
            cur->next->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        Node* ans = head->next;
        while (cur->next != nullptr) {
            Node* node = cur->next;
            cur->next = node->next;
            cur = node;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	for cur := head; cur != nil; {
		node := &Node{cur.Val, cur.Next, nil}
		cur.Next = node
		cur = node.Next
	}
	for cur := head; cur != nil; cur = cur.Next.Next {
		if cur.Random != nil {
			cur.Next.Random = cur.Random.Next
		}
	}
	ans := head.Next
	for cur := head; cur.Next != nil; {
		node := cur.Next
		cur.Next = node.Next
		cur = node
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     next: _Node | null
 *     random: _Node | null
 *
 *     constructor(val?: number, next?: _Node, random?: _Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: _Node | null): _Node | null {
    if (head === null) {
        return null;
    }
    let cur = head;
    while (cur !== null) {
        const node = new _Node(cur.val);
        node.next = cur.next;
        cur.next = node;
        cur = node.next;
    }
    cur = head;
    while (cur !== null) {
        cur.next.random = cur.random === null ? null : cur.random.next;
        cur = cur.next.next;
    }
    cur = head;
    const ans = head.next;
    while (cur.next !== null) {
        const node = cur.next;
        cur.next = node.next;
        cur = node;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function (head) {
    if (head === null) {
        return null;
    }
    let cur = head;
    while (cur !== null) {
        const node = new _Node(cur.val);
        node.next = cur.next;
        cur.next = node;
        cur = node.next;
    }
    cur = head;
    while (cur !== null) {
        cur.next.random = cur.random === null ? null : cur.random.next;
        cur = cur.next.next;
    }
    cur = head;
    const ans = head.next;
    while (cur.next !== null) {
        const node = cur.next;
        cur.next = node.next;
        cur = node;
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;

    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Node cur = head;
        while (cur != null) {
            Node node = new Node(cur.val);
            node.next = cur.next;
            cur.next = node;
            cur = node.next;
        }
        cur = head;
        while (cur != null) {
            cur.next.random = cur.random == null ? null : cur.random.next;
            cur = cur.next.next;
        }
        cur = head;
        Node ans = head.next;
        while (cur.next != null) {
            Node node = cur.next;
            cur.next = node.next;
            cur = node;
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

<p>给你一个长度为 <code>n</code> 的链表，每个节点包含一个额外增加的随机指针 <code>random</code> ，该指针可以指向链表中的任何节点或空节点。</p>

<p>构造这个链表的&nbsp;<strong><a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin" target="_blank">深拷贝</a></strong>。&nbsp;深拷贝应该正好由 <code>n</code> 个 <strong>全新</strong> 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 <code>next</code> 指针和 <code>random</code> 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。<strong>复制链表中的指针都不应指向原链表中的节点 </strong>。</p>

<p>例如，如果原链表中有 <code>X</code> 和 <code>Y</code> 两个节点，其中 <code>X.random --&gt; Y</code> 。那么在复制链表中对应的两个节点 <code>x</code> 和 <code>y</code> ，同样有 <code>x.random --&gt; y</code> 。</p>

<p>返回复制链表的头节点。</p>

<p>用一个由&nbsp;<code>n</code>&nbsp;个节点组成的链表来表示输入/输出中的链表。每个节点用一个&nbsp;<code>[val, random_index]</code>&nbsp;表示：</p>

<ul>
	<li><code>val</code>：一个表示&nbsp;<code>Node.val</code>&nbsp;的整数。</li>
	<li><code>random_index</code>：随机指针指向的节点索引（范围从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n-1</code>）；如果不指向任何节点，则为&nbsp;&nbsp;<code>null</code>&nbsp;。</li>
</ul>

<p>你的代码 <strong>只</strong> 接受原链表的头节点 <code>head</code> 作为传入参数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0138.Copy%20List%20with%20Random%20Pointer/images/e1.png" style="height: 142px; width: 700px;" /></p>

<pre>
<strong>输入：</strong>head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
<strong>输出：</strong>[[7,null],[13,0],[11,4],[10,2],[1,0]]
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0138.Copy%20List%20with%20Random%20Pointer/images/e2.png" style="height: 114px; width: 700px;" /></p>

<pre>
<strong>输入：</strong>head = [[1,1],[2,1]]
<strong>输出：</strong>[[1,1],[2,1]]
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0138.Copy%20List%20with%20Random%20Pointer/images/e3.png" style="height: 122px; width: 700px;" /></strong></p>

<pre>
<strong>输入：</strong>head = [[3,null],[3,0],[3,null]]
<strong>输出：</strong>[[3,null],[3,0],[3,null]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 1000</code><meta charset="UTF-8" /></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li><code>Node.random</code>&nbsp;为&nbsp;<code>null</code> 或指向链表中的节点。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

我们可以定义一个虚拟头节点 $\textit{dummy}$，用一个指针 $\textit{tail}$ 指向虚拟头节点，然后遍历链表，将链表中的每个节点都复制一份，并将每个节点及其复制节点的对应关系存储在哈希表 $\textit{d}$ 中，同时连接好复制节点的 $\textit{next}$ 指针。

接下来再遍历链表，根据哈希表中存储的对应关系，将复制节点的 $\textit{random}$ 指针连接好。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为链表的长度。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        d = {}
        dummy = tail = Node(0)
        cur = head
        while cur:
            node = Node(cur.val)
            tail.next = node
            tail = tail.next
            d[cur] = node
            cur = cur.next
        cur = head
        while cur:
            d[cur].random = d[cur.random] if cur.random else None
            cur = cur.next
        return dummy.next
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> d = new HashMap<>();
        Node dummy = new Node(0);
        Node tail = dummy;
        for (Node cur = head; cur != null; cur = cur.next) {
            Node node = new Node(cur.val);
            tail.next = node;
            tail = node;
            d.put(cur, node);
        }
        for (Node cur = head; cur != null; cur = cur.next) {
            d.get(cur).random = cur.random == null ? null : d.get(cur.random);
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        unordered_map<Node*, Node*> d;
        for (Node* cur = head; cur; cur = cur->next) {
            Node* node = new Node(cur->val);
            tail->next = node;
            tail = node;
            d[cur] = node;
        }
        for (Node* cur = head; cur; cur = cur->next) {
            d[cur]->random = cur->random ? d[cur->random] : nullptr;
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
	dummy := &Node{}
	tail := dummy
	d := map[*Node]*Node{}
	for cur := head; cur != nil; cur = cur.Next {
		node := &Node{Val: cur.Val}
		d[cur] = node
		tail.Next = node
		tail = node
	}
	for cur := head; cur != nil; cur = cur.Next {
		if cur.Random != nil {
			d[cur].Random = d[cur.Random]
		}
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     next: _Node | null
 *     random: _Node | null
 *
 *     constructor(val?: number, next?: _Node, random?: _Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: _Node | null): _Node | null {
    const d: Map<_Node, _Node> = new Map();
    const dummy = new _Node();
    let tail = dummy;
    for (let cur = head; cur; cur = cur.next) {
        const node = new _Node(cur.val);
        tail.next = node;
        tail = node;
        d.set(cur, node);
    }
    for (let cur = head; cur; cur = cur.next) {
        d.get(cur)!.random = cur.random ? d.get(cur.random)! : null;
    }
    return dummy.next;
}
```

#### JavaScript

```js
/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function (head) {
    const d = new Map();
    const dummy = new _Node();
    let tail = dummy;
    for (let cur = head; cur; cur = cur.next) {
        const node = new _Node(cur.val);
        tail.next = node;
        tail = node;
        d.set(cur, node);
    }
    for (let cur = head; cur; cur = cur.next) {
        d.get(cur).random = cur.random ? d.get(cur.random) : null;
    }
    return dummy.next;
};
```

#### C#

```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;

    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        Dictionary<Node, Node> d = new Dictionary<Node, Node>();
        Node dummy = new Node(0);
        Node tail = dummy;

        for (Node cur = head; cur != null; cur = cur.next) {
            Node node = new Node(cur.val);
            tail.next = node;
            tail = node;
            d[cur] = node;
        }

        for (Node cur = head; cur != null; cur = cur.next) {
            if (cur.random != null) {
                d[cur].random = d[cur.random];
            }
        }

        return dummy.next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：模拟（空间优化）

在方法一中，我们使用了额外的哈希表来存储原节点和复制节点的对应关系，我们也可以不使用额外的空间，具体做法如下：

1. 遍历原链表，对于每个节点，复制一个新节点并将其插入到原节点和原节点的下一个节点之间。
2. 再次遍历链表，根据原节点的 $\textit{random}$ 指针，设置新节点的 $\textit{random}$ 指针。
3. 最后将链表拆分为原链表和复制链表。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。忽略答案链表的空间占用，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if head is None:
            return None
        cur = head
        while cur:
            node = Node(cur.val, cur.next)
            cur.next = node
            cur = node.next
        cur = head
        while cur:
            cur.next.random = cur.random.next if cur.random else None
            cur = cur.next.next
        cur = head
        ans = head.next
        while cur.next:
            node = cur.next
            cur.next = node.next
            cur = node
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

public class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Node cur = head;
        while (cur != null) {
            Node node = new Node(cur.val);
            node.next = cur.next;
            cur.next = node;
            cur = node.next;
        }
        cur = head;
        while (cur != null) {
            cur.next.random = cur.random == null ? null : cur.random.next;
            cur = cur.next.next;
        }
        cur = head;
        Node ans = head.next;
        while (cur.next != null) {
            Node node = cur.next;
            cur.next = node.next;
            cur = node;
        }
        return ans;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* cur = head;
        while (cur != nullptr) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur != nullptr) {
            cur->next->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        Node* ans = head->next;
        while (cur->next != nullptr) {
            Node* node = cur->next;
            cur->next = node->next;
            cur = node;
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	for cur := head; cur != nil; {
		node := &Node{cur.Val, cur.Next, nil}
		cur.Next = node
		cur = node.Next
	}
	for cur := head; cur != nil; cur = cur.Next.Next {
		if cur.Random != nil {
			cur.Next.Random = cur.Random.Next
		}
	}
	ans := head.Next
	for cur := head; cur.Next != nil; {
		node := cur.Next
		cur.Next = node.Next
		cur = node
	}
	return ans
}
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     next: _Node | null
 *     random: _Node | null
 *
 *     constructor(val?: number, next?: _Node, random?: _Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: _Node | null): _Node | null {
    if (head === null) {
        return null;
    }
    let cur = head;
    while (cur !== null) {
        const node = new _Node(cur.val);
        node.next = cur.next;
        cur.next = node;
        cur = node.next;
    }
    cur = head;
    while (cur !== null) {
        cur.next.random = cur.random === null ? null : cur.random.next;
        cur = cur.next.next;
    }
    cur = head;
    const ans = head.next;
    while (cur.next !== null) {
        const node = cur.next;
        cur.next = node.next;
        cur = node;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function (head) {
    if (head === null) {
        return null;
    }
    let cur = head;
    while (cur !== null) {
        const node = new _Node(cur.val);
        node.next = cur.next;
        cur.next = node;
        cur = node.next;
    }
    cur = head;
    while (cur !== null) {
        cur.next.random = cur.random === null ? null : cur.random.next;
        cur = cur.next.next;
    }
    cur = head;
    const ans = head.next;
    while (cur.next !== null) {
        const node = cur.next;
        cur.next = node.next;
        cur = node;
    }
    return ans;
};
```

#### C#

```cs
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;

    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Node cur = head;
        while (cur != null) {
            Node node = new Node(cur.val);
            node.next = cur.next;
            cur.next = node;
            cur = node.next;
        }
        cur = head;
        while (cur != null) {
            cur.next.random = cur.random == null ? null : cur.random.next;
            cur = cur.next.next;
        }
        cur = head;
        Node ans = head.next;
        while (cur.next != null) {
            Node node = cur.next;
            cur.next = node.next;
            cur = node;
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

# [139. 单词拆分](https://leetcode.cn/problems/word-break){#139}

{{< tabs "139" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.isEnd = False

    def insert(self, w: str):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.isEnd = True


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        n = len(s)
        f = [False] * (n + 1)
        f[n] = True
        for i in range(n - 1, -1, -1):
            node = trie
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                if not node.children[idx]:
                    break
                node = node.children[idx]
                if node.isEnd and f[j + 1]:
                    f[i] = True
                    break
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Trie trie = new Trie();
        for (String w : wordDict) {
            trie.insert(w);
        }
        int n = s.length();
        boolean[] f = new boolean[n + 1];
        f[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int k = s.charAt(j) - 'a';
                if (node.children[k] == null) {
                    break;
                }
                node = node.children[k];
                if (node.isEnd && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
}

class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd = false;

    public void insert(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
        }
        node.isEnd = true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie()
        : children(26)
        , isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& w : wordDict) {
            trie.insert(w);
        }
        int n = s.size();
        vector<bool> f(n + 1);
        f[n] = true;
        for (int i = n - 1; ~i; --i) {
            Trie* node = &trie;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                if (!node->children[k]) {
                    break;
                }
                node = node->children[k];
                if (node->isEnd && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type trie struct {
	children [26]*trie
	isEnd    bool
}

func newTrie() *trie {
	return &trie{}
}

func (t *trie) insert(w string) {
	node := t
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func wordBreak(s string, wordDict []string) bool {
	trie := newTrie()
	for _, w := range wordDict {
		trie.insert(w)
	}
	n := len(s)
	f := make([]bool, n+1)
	f[n] = true
	for i := n - 1; i >= 0; i-- {
		node := trie
		for j := i; j < n; j++ {
			k := s[j] - 'a'
			if node.children[k] == nil {
				break
			}
			node = node.children[k]
			if node.isEnd && f[j+1] {
				f[i] = true
				break
			}
		}
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wordBreak(s: string, wordDict: string[]): boolean {
    const trie = new Trie();
    for (const w of wordDict) {
        trie.insert(w);
    }
    const n = s.length;
    const f: boolean[] = new Array(n + 1).fill(false);
    f[n] = true;
    for (let i = n - 1; i >= 0; --i) {
        let node: Trie = trie;
        for (let j = i; j < n; ++j) {
            const k = s.charCodeAt(j) - 97;
            if (!node.children[k]) {
                break;
            }
            node = node.children[k];
            if (node.isEnd && f[j + 1]) {
                f[i] = true;
                break;
            }
        }
    }
    return f[0];
}

class Trie {
    children: Trie[];
    isEnd: boolean;

    constructor() {
        this.children = new Array(26);
        this.isEnd = false;
    }

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let words: std::collections::HashSet<String> = word_dict.into_iter().collect();
        let mut f = vec![false; s.len() + 1];
        f[0] = true;
        for i in 1..=s.len() {
            for j in 0..i {
                f[i] |= f[j] && words.contains(&s[j..i]);
            }
        }
        f[s.len()]
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        Trie trie = new Trie();
        foreach (string w in wordDict) {
            trie.Insert(w);
        }
        int n = s.Length;
        bool[] f = new bool[n + 1];
        f[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                if (node.Children[k] == null) {
                    break;
                }
                node = node.Children[k];
                if (node.IsEnd && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
}

class Trie {
    public Trie[] Children { get; set; }
    public bool IsEnd { get; set; }

    public Trie() {
        Children = new Trie[26];
        IsEnd = false;
    }

    public void Insert(string word) {
        Trie node = this;
        foreach (char c in word) {
            int i = c - 'a';
            if (node.Children[i] == null) {
                node.Children[i] = new Trie();
            }
            node = node.Children[i];
        }
        node.IsEnd = true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个字符串列表 <code>wordDict</code> 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 <code>s</code>&nbsp;则返回 <code>true</code>。</p>

<p><strong>注意：</strong>不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
&nbsp;    注意，你可以重复使用字典中的单词。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
	<li><code>s</code> 和 <code>wordDict[i]</code> 仅由小写英文字母组成</li>
	<li><code>wordDict</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 动态规划

我们定义 $f[i]$ 表示字符串 $s$ 的前 $i$ 个字符能否拆分成 $wordDict$ 中的单词，初始时 $f[0]=true$，其余为 $false$。答案为 $f[n]$。

考虑 $f[i]$，如果存在 $j \in [0, i)$ 使得 $f[j] \land s[j:i] \in wordDict$，则 $f[i]=true$。为了优化效率，我们可以使用哈希表存储 $wordDict$ 中的单词，这样可以快速判断 $s[j:i]$ 是否在 $wordDict$ 中。

时间复杂度 $O(n^3)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        n = len(s)
        f = [True] + [False] * n
        for i in range(1, n + 1):
            f[i] = any(f[j] and s[j:i] in words for j in range(i))
        return f[n]
```

#### Java

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        int n = s.length();
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (f[j] && words.contains(s.substring(j, i))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        bool f[n + 1];
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (f[j] && words.count(s.substr(j, i - j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func wordBreak(s string, wordDict []string) bool {
	words := map[string]bool{}
	for _, w := range wordDict {
		words[w] = true
	}
	n := len(s)
	f := make([]bool, n+1)
	f[0] = true
	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			if f[j] && words[s[j:i]] {
				f[i] = true
				break
			}
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function wordBreak(s: string, wordDict: string[]): boolean {
    const words = new Set(wordDict);
    const n = s.length;
    const f: boolean[] = new Array(n + 1).fill(false);
    f[0] = true;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (f[j] && words.has(s.substring(j, i))) {
                f[i] = true;
                break;
            }
        }
    }
    return f[n];
}
```

#### Rust

```rust
impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let words: std::collections::HashSet<String> = word_dict.into_iter().collect();
        let mut f = vec![false; s.len() + 1];
        f[0] = true;
        for i in 1..=s.len() {
            for j in 0..i {
                f[i] |= f[j] && words.contains(&s[j..i]);
            }
        }
        f[s.len()]
    }
}
```

#### C#

```cs
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        var words = new HashSet<string>(wordDict);
        int n = s.Length;
        var f = new bool[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (f[j] && words.Contains(s.Substring(j, i - j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀树 + 动态规划

我们先将 $wordDict$ 中的单词存入前缀树中，然后使用动态规划求解。

我们定义 $f[i]$ 表示从字符串 $s$ 的第 $i$ 个字符开始往后拆分，能否拆分成 $wordDict$ 中的单词，初始时 $f[n]=true$，其余为 $false$。答案为 $f[0]$。

接下来，我们从大到小枚举 $i$，对于每个 $i$，我们从 $i$ 开始往后拆分，如果 $s[i:j]$ 在前缀树中，且 $f[j+1]=true$，则 $f[i]=true$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.isEnd = False

    def insert(self, w: str):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.isEnd = True


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        n = len(s)
        f = [False] * (n + 1)
        f[n] = True
        for i in range(n - 1, -1, -1):
            node = trie
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                if not node.children[idx]:
                    break
                node = node.children[idx]
                if node.isEnd and f[j + 1]:
                    f[i] = True
                    break
        return f[0]
```

#### Java

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Trie trie = new Trie();
        for (String w : wordDict) {
            trie.insert(w);
        }
        int n = s.length();
        boolean[] f = new boolean[n + 1];
        f[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int k = s.charAt(j) - 'a';
                if (node.children[k] == null) {
                    break;
                }
                node = node.children[k];
                if (node.isEnd && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
}

class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd = false;

    public void insert(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
        }
        node.isEnd = true;
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie()
        : children(26)
        , isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& w : wordDict) {
            trie.insert(w);
        }
        int n = s.size();
        vector<bool> f(n + 1);
        f[n] = true;
        for (int i = n - 1; ~i; --i) {
            Trie* node = &trie;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                if (!node->children[k]) {
                    break;
                }
                node = node->children[k];
                if (node->isEnd && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};
```

#### Go

```go
type trie struct {
	children [26]*trie
	isEnd    bool
}

func newTrie() *trie {
	return &trie{}
}

func (t *trie) insert(w string) {
	node := t
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func wordBreak(s string, wordDict []string) bool {
	trie := newTrie()
	for _, w := range wordDict {
		trie.insert(w)
	}
	n := len(s)
	f := make([]bool, n+1)
	f[n] = true
	for i := n - 1; i >= 0; i-- {
		node := trie
		for j := i; j < n; j++ {
			k := s[j] - 'a'
			if node.children[k] == nil {
				break
			}
			node = node.children[k]
			if node.isEnd && f[j+1] {
				f[i] = true
				break
			}
		}
	}
	return f[0]
}
```

#### TypeScript

```ts
function wordBreak(s: string, wordDict: string[]): boolean {
    const trie = new Trie();
    for (const w of wordDict) {
        trie.insert(w);
    }
    const n = s.length;
    const f: boolean[] = new Array(n + 1).fill(false);
    f[n] = true;
    for (let i = n - 1; i >= 0; --i) {
        let node: Trie = trie;
        for (let j = i; j < n; ++j) {
            const k = s.charCodeAt(j) - 97;
            if (!node.children[k]) {
                break;
            }
            node = node.children[k];
            if (node.isEnd && f[j + 1]) {
                f[i] = true;
                break;
            }
        }
    }
    return f[0];
}

class Trie {
    children: Trie[];
    isEnd: boolean;

    constructor() {
        this.children = new Array(26);
        this.isEnd = false;
    }

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const i = c.charCodeAt(0) - 97;
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
        node.isEnd = true;
    }
}
```

#### C#

```cs
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        Trie trie = new Trie();
        foreach (string w in wordDict) {
            trie.Insert(w);
        }
        int n = s.Length;
        bool[] f = new bool[n + 1];
        f[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                if (node.Children[k] == null) {
                    break;
                }
                node = node.Children[k];
                if (node.IsEnd && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
}

class Trie {
    public Trie[] Children { get; set; }
    public bool IsEnd { get; set; }

    public Trie() {
        Children = new Trie[26];
        IsEnd = false;
    }

    public void Insert(string word) {
        Trie node = this;
        foreach (char c in word) {
            int i = c - 'a';
            if (node.Children[i] == null) {
                node.Children[i] = new Trie();
            }
            node = node.Children[i];
        }
        node.IsEnd = true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
