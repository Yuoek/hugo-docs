---
title: "day_0130 "
date: 2025-09-21T10:01:15+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0130 

{{< tabs id="1" >}}
{{% tab "python " %}}

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

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0130  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def dfs(i: int, j: int):
            if not (0 <= i < m and 0 <= j < n and board[i][j] == "O"):  # 检查边界条件和当前单元格是否为'O'
                return
            board[i][j] = "."  # 将边界上的'O'标记为临时标记'.'
            for a, b in pairwise((-1, 0, 1, 0, -1)):  # 遍历四个方向：上、右、下、左
                dfs(i + a, j + b)  # 递归搜索相邻单元格

        m, n = len(board), len(board[0])  # 获取矩阵的行数和列数
        for i in range(m):  # 遍历第一列和最后一列
            dfs(i, 0)  # 从第一列的每个单元格开始DFS
            dfs(i, n - 1)  # 从最后一列的每个单元格开始DFS
        for j in range(n):  # 遍历第一行和最后一行
            dfs(0, j)  # 从第一行的每个单元格开始DFS
            dfs(m - 1, j)  # 从最后一行的每个单元格开始DFS
        for i in range(m):  # 遍历整个矩阵
            for j in range(n):
                if board[i][j] == ".":  # 如果是临时标记的单元格（边界相连的'O'）
                    board[i][j] = "O"  # 恢复为'O'
                elif board[i][j] == "O":  # 如果是未被标记的'O'（被'X'包围的）
                    board[i][j] = "X"  # 将其翻转为'X'
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0130  数学解释

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


这段代码使用了**深度优先搜索（DFS）**和**边界标记法**来解决矩阵中的连通区域问题。具体数学思想如下：

## 1. 问题建模
将矩阵视为一个图，每个"O"单元格是一个节点，相邻的"O"（上下左右）之间存在边

## 2. 核心数学思想
**逆向思维**：不是寻找被"X"包围的区域，而是寻找**不被包围的区域**

- 所有不被"X"包围的"O"必然与边界相连
- 从边界开始DFS标记所有可达的"O"
- 剩下的未被标记的"O"就是被包围的区域

## 3. 算法步骤的数学解释

### 步骤1：边界DFS（标记不被包围的区域）
```python
for i in range(m):  # 遍历左右边界
    dfs(i, 0)
    dfs(i, n - 1)
for j in range(n):  # 遍历上下边界
    dfs(0, j)
    dfs(m - 1, j)
```
- 从矩阵的四条边界开始DFS
- 将所有与边界相连的"O"标记为临时标记"."

### 步骤2：DFS遍历函数
```python
def dfs(i: int, j: int):
    if not (0 <= i < m and 0 <= j < n and board[i][j] == "O"):
        return  # 边界条件：越界或不是"O"
    board[i][j] = "."  # 标记为不被包围
    for a, b in pairwise((-1, 0, 1, 0, -1)):  # 四个方向
        dfs(i + a, j + b)
```
- 递归探索四个方向（上、右、下、左）
- 使用深度优先确保标记所有连通区域

### 步骤3：最终处理
```python
for i in range(m):
    for j in range(n):
        if board[i][j] == ".":
            board[i][j] = "O"  # 恢复不被包围的区域
        elif board[i][j] == "O":
            board[i][j] = "X"  # 将被包围的区域变为"X"
```
- 数学上的集合操作：
  - 所有标记为"."的 → 不被包围的"O"
  - 剩余的"O" → 被包围的区域，变为"X"

## 4. 数学复杂度分析
- 时间复杂度：O(m×n) - 每个单元格最多被访问一次
- 空间复杂度：O(m×n) - DFS递归栈的最坏情况

这种解法巧妙地运用了图遍历和集合标记的思想，避免了复杂的几何判断。
