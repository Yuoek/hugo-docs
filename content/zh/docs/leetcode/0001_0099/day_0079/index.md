---
title: "day_0079 "
date: 2025-09-14T08:36:20+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0079 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i: int, j: int, k: int) -> bool:
            if k == len(word) - 1:
                return board[i][j] == word[k]
            if board[i][j] != word[k]:
                return False
            c = board[i][j]
            board[i][j] = "0"
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                ok = 0 <= x < m and 0 <= y < n and board[x][y] != "0"
                if ok and dfs(x, y, k + 1):
                    return True
            board[i][j] = c
            return False

        m, n = len(board), len(board[0])
        return any(dfs(i, j, 0) for i in range(m) for j in range(n)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (k == word.size() - 1) {
                return board[i][j] == word[k];
            }
            if (board[i][j] != word[k]) {
                return false;
            }
            char c = board[i][j];
            board[i][j] = '0';
            for (int u = 0; u < 4; ++u) {
                int x = i + dirs[u], y = j + dirs[u + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '0' && dfs(x, y, k + 1)) {
                    return true;
                }
            }
            board[i][j] = c;
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int m;
    private int n;
    private String word;
    private char[][] board;

    public boolean exist(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        this.word = word;
        this.board = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(int i, int j, int k) {
        if (k == word.length() - 1) {
            return board[i][j] == word.charAt(k);
        }
        if (board[i][j] != word.charAt(k)) {
            return false;
        }
        char c = board[i][j];
        board[i][j] = '0';
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int u = 0; u < 4; ++u) {
            int x = i + dirs[u], y = j + dirs[u + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '0' && dfs(x, y, k + 1)) {
                return true;
            }
        }
        board[i][j] = c;
        return false;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0079  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i: int, j: int, k: int) -> bool:
            # 如果已经匹配到单词的最后一个字符
            if k == len(word) - 1:
                return board[i][j] == word[k]
            # 当前字符不匹配，返回false
            if board[i][j] != word[k]:
                return False
            # 临时保存当前字符，并将当前位置标记为已访问
            c = board[i][j]
            board[i][j] = "0"
            # 遍历四个方向：上、右、下、左
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                # 检查新位置是否在边界内且未被访问过
                ok = 0 <= x < m and 0 <= y < n and board[x][y] != "0"
                # 如果新位置有效且继续DFS搜索成功，返回true
                if ok and dfs(x, y, k + 1):
                    return True
            # 回溯：恢复当前位置的原始字符
            board[i][j] = c
            return False

        m, n = len(board), len(board[0])
        # 遍历矩阵中的每个位置作为起点
        return any(dfs(i, j, 0) for i in range(m) for j in range(n)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (k == word.size() - 1) {
                return board[i][j] == word[k];
            }
            if (board[i][j] != word[k]) {
                return false;
            }
            char c = board[i][j];
            board[i][j] = '0';
            for (int u = 0; u < 4; ++u) {
                int x = i + dirs[u], y = j + dirs[u + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '0' && dfs(x, y, k + 1)) {
                    return true;
                }
            }
            board[i][j] = c;
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int m;
    private int n;
    private String word;
    private char[][] board;

    public boolean exist(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        this.word = word;
        this.board = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(int i, int j, int k) {
        if (k == word.length() - 1) {
            return board[i][j] == word.charAt(k);
        }
        if (board[i][j] != word.charAt(k)) {
            return false;
        }
        char c = board[i][j];
        board[i][j] = '0';
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int u = 0; u < 4; ++u) {
            int x = i + dirs[u], y = j + dirs[u + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '0' && dfs(x, y, k + 1)) {
                return true;
            }
        }
        board[i][j] = c;
        return false;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0079  数学解释

```python 
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i: int, j: int, k: int) -> bool:
            if k == len(word) - 1:
                return board[i][j] == word[k]
            if board[i][j] != word[k]:
                return False
            c = board[i][j]
            board[i][j] = "0"
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                ok = 0 <= x < m and 0 <= y < n and board[x][y] != "0"
                if ok and dfs(x, y, k + 1):
                    return True
            board[i][j] = c
            return False

        m, n = len(board), len(board[0])
        return any(dfs(i, j, 0) for i in range(m) for j in range(n)) 
```


这段代码使用了**回溯法（Backtracking）** 和**深度优先搜索（DFS）** 来解决单词搜索问题。让我用数学思想来解释：

## 核心数学思想：状态空间搜索

### 1. 问题建模
- 将二维网格视为一个**状态空间**，每个单元格是一个状态节点
- 单词搜索问题转化为：在状态空间中寻找一条路径，使得路径上的字符序列等于目标单词

### 2. 递归与数学归纳法
```python
def dfs(i: int, j: int, k: int) -> bool:
```
- **基础情况（k = len(word)-1）**：当搜索到单词最后一个字符时，检查当前单元格是否匹配
- **归纳步骤**：如果当前字符匹配，则递归检查相邻单元格是否能匹配下一个字符

### 3. 组合数学的应用
```python
for a, b in pairwise((-1, 0, 1, 0, -1)):
```
- 使用**排列组合**思想：在每个位置有4种可能的移动方向（上、下、左、右）
- 这相当于在状态空间中探索所有可能的路径组合

### 4. 状态标记与集合论
```python
board[i][j] = "0"  # 标记为已访问
```
- 使用**集合操作**的思想：将已访问的单元格从可用集合中暂时移除
- 防止重复访问，确保路径是简单路径（无环）

### 5. 存在性证明
```python
return any(dfs(i, j, 0) for i in range(m) for j in range(n))
```
- 使用**存在量词**的逻辑：只要存在一个起始位置能成功匹配整个单词，就返回True
- 这体现了**存在性证明**的数学思想

### 6. 时间复杂度分析
- 最坏情况下需要检查所有可能的路径，时间复杂度为O(3ᴸ × m × n)
- 其中L是单词长度，3是因为每个位置有3个新方向可选（排除来时的方向）

这种解法体现了**递归思维**、**状态空间搜索**和**组合优化**的数学思想，是典型的回溯算法应用。


