---
title: "day_0037 "
date: 2025-09-14T10:33:31+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0037 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def dfs(k):
            nonlocal ok
            if k == len(t):
                ok = True
                return
            i, j = t[k]
            for v in range(9):
                if row[i][v] == col[j][v] == block[i // 3][j // 3][v] == False:
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
                    board[i][j] = str(v + 1)
                    dfs(k + 1)
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = False
                if ok:
                    return

        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        block = [[[False] * 9 for _ in range(3)] for _ in range(3)]
        t = []
        ok = False
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    t.append((i, j))
                else:
                    v = int(board[i][j]) - 1
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
        dfs(0) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
using pii = pair<int, int>;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool block[3][3][9] = {false};
        bool ok = false;
        vector<pii> t;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.push_back({i, j});
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        function<void(int k)> dfs = [&](int k) {
            if (k == t.size()) {
                ok = true;
                return;
            }
            int i = t[k].first, j = t[k].second;
            for (int v = 0; v < 9; ++v) {
                if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                    board[i][j] = v + '1';
                    dfs(k + 1);
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
                }
                if (ok) {
                    return;
                }
            }
        };
        dfs(0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private boolean ok;
    private char[][] board;
    private List<Integer> t = new ArrayList<>();
    private boolean[][] row = new boolean[9][9];
    private boolean[][] col = new boolean[9][9];
    private boolean[][][] block = new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.add(i * 9 + j);
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        dfs(0);
    }

    private void dfs(int k) {
        if (k == t.size()) {
            ok = true;
            return;
        }
        int i = t.get(k) / 9, j = t.get(k) % 9;
        for (int v = 0; v < 9; ++v) {
            if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                board[i][j] = (char) (v + '1');
                dfs(k + 1);
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
            }
            if (ok) {
                return;
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0037  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def dfs(k):
            nonlocal ok
            if k == len(t):  # 如果已经处理完所有空格，说明找到解
                ok = True
                return
            i, j = t[k]  # 获取第k个空格的位置
            for v in range(9):  # 尝试填入数字1-9
                if row[i][v] == col[j][v] == block[i // 3][j // 3][v] == False:  # 检查数字v+1是否可用
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True  # 标记数字已使用
                    board[i][j] = str(v + 1)  # 填入数字
                    dfs(k + 1)  # 递归处理下一个空格
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = False  # 回溯，撤销选择
                if ok:  # 如果已经找到解，提前返回
                    return

        # 初始化行、列、九宫格的数字使用标记
        row = [[False] * 9 for _ in range(9)]  # 记录每行数字使用情况
        col = [[False] * 9 for _ in range(9)]  # 记录每列数字使用情况
        block = [[[False] * 9 for _ in range(3)] for _ in range(3)]  # 记录每个3x3区块数字使用情况
        t = []  # 存储所有需要填充的空格位置
        ok = False  # 标记是否找到解
        
        # 预处理：标记已有数字，收集空格位置
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':  # 如果是空格
                    t.append((i, j))  # 记录空格位置
                else:
                    v = int(board[i][j]) - 1  # 将字符数字转换为0-8的索引
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True  # 标记数字已使用
        
        dfs(0)  # 从第一个空格开始深度优先搜索
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
using pii = pair<int, int>;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool block[3][3][9] = {false};
        bool ok = false;
        vector<pii> t;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.push_back({i, j});
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        function<void(int k)> dfs = [&](int k) {
            if (k == t.size()) {
                ok = true;
                return;
            }
            int i = t[k].first, j = t[k].second;
            for (int v = 0; v < 9; ++v) {
                if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                    board[i][j] = v + '1';
                    dfs(k + 1);
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
                }
                if (ok) {
                    return;
                }
            }
        };
        dfs(0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private boolean ok;
    private char[][] board;
    private List<Integer> t = new ArrayList<>();
    private boolean[][] row = new boolean[9][9];
    private boolean[][] col = new boolean[9][9];
    private boolean[][][] block = new boolean[3][3][9];

    public void solveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    t.add(i * 9 + j);
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                }
            }
        }
        dfs(0);
    }

    private void dfs(int k) {
        if (k == t.size()) {
            ok = true;
            return;
        }
        int i = t.get(k) / 9, j = t.get(k) % 9;
        for (int v = 0; v < 9; ++v) {
            if (!row[i][v] && !col[j][v] && !block[i / 3][j / 3][v]) {
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
                board[i][j] = (char) (v + '1');
                dfs(k + 1);
                row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
            }
            if (ok) {
                return;
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0037  数学解释

```python 
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def dfs(k):
            nonlocal ok
            if k == len(t):
                ok = True
                return
            i, j = t[k]
            for v in range(9):
                if row[i][v] == col[j][v] == block[i // 3][j // 3][v] == False:
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
                    board[i][j] = str(v + 1)
                    dfs(k + 1)
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = False
                if ok:
                    return

        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        block = [[[False] * 9 for _ in range(3)] for _ in range(3)]
        t = []
        ok = False
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    t.append((i, j))
                else:
                    v = int(board[i][j]) - 1
                    row[i][v] = col[j][v] = block[i // 3][j // 3][v] = True
        dfs(0) 
```


这段代码使用**回溯法（Backtracking）** 来解决数独问题，体现了以下数学思想：

## 1. 组合数学中的排列问题
- 数独本质上是在9×9网格中填入数字1-9，满足每行、每列、每个3×3子网格的数字不重复
- 这是一个典型的**约束满足问题（CSP）**

## 2. 集合论思想
代码使用三个二维数组来记录数字使用情况：
- `row[i][v]`：记录第i行是否已使用数字v+1
- `col[j][v]`：记录第j列是否已使用数字v+1  
- `block[i//3][j//3][v]`：记录对应3×3区块是否已使用数字v+1

这体现了**集合的互斥性** - 每个数字在行、列、区块中只能出现一次。

## 3. 图论中的DFS遍历
- 将空白格看作图中的节点
- 使用深度优先搜索（DFS）遍历所有可能的数字组合
- 当遇到冲突时回溯（backtrack），尝试其他可能性

## 4. 递归数学思想
`dfs(k)`函数采用递归方式：
- 基准情况：`k == len(t)`（所有空白格已填充）
- 递归情况：对当前空白格尝试所有可能的数字(1-9)

## 5. 算法复杂度
最坏情况下需要尝试9ⁿ种组合（n为空白格数量），但通过剪枝（pruning）大幅减少搜索空间：
- 提前检测冲突，避免无效搜索
- 找到解立即返回（`if ok: return`）

这种解法体现了**穷举法与剪枝优化**的结合，是解决组合优化问题的经典数学思想。
