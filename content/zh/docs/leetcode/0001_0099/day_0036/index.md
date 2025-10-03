---
title: "day_0036 "
date: 2025-09-14T10:36:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0036 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        sub = [[False] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                num = int(c) - 1
                k = i // 3 * 3 + j // 3
                if row[i][num] or col[j][num] or sub[k][num]:
                    return False
                row[i][num] = True
                col[j][num] = True
                sub[k][num] = True
        return True 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row = new boolean[9][9];
        boolean[][] col = new boolean[9][9];
        boolean[][] sub = new boolean[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0036  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False] * 9 for _ in range(9)]  # 创建9x9的二维数组，记录每行数字出现情况
        col = [[False] * 9 for _ in range(9)]  # 创建9x9的二维数组，记录每列数字出现情况
        sub = [[False] * 9 for _ in range(9)]  # 创建9x9的二维数组，记录每个3x3子数独数字出现情况
        for i in range(9):  # 遍历数独的每一行
            for j in range(9):  # 遍历数独的每一列
                c = board[i][j]  # 获取当前位置的字符
                if c == '.':  # 如果是空位，跳过检查
                    continue
                num = int(c) - 1  # 将字符转换为数字并减1（因为数组索引从0开始）
                k = i // 3 * 3 + j // 3  # 计算当前单元格所属的3x3子数独的索引
                if row[i][num] or col[j][num] or sub[k][num]:  # 检查该数字是否在当前行、列或子数独中已存在
                    return False  # 如果存在重复，返回False表示无效数独
                row[i][num] = True  # 标记该数字在当前行已出现
                col[j][num] = True  # 标记该数字在当前列已出现
                sub[k][num] = True  # 标记该数字在当前子数独中已出现
        return True  # 所有检查通过，返回True表示有效数独
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row = new boolean[9][9];
        boolean[][] col = new boolean[9][9];
        boolean[][] sub = new boolean[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0036  数学解释

```python 
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        sub = [[False] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                num = int(c) - 1
                k = i // 3 * 3 + j // 3
                if row[i][num] or col[j][num] or sub[k][num]:
                    return False
                row[i][num] = True
                col[j][num] = True
                sub[k][num] = True
        return True 
```


这段代码使用了**哈希表思想**和**空间换时间**的优化策略来解决数独有效性验证问题。

## 核心数学思想：

1. **分类计数原理**：将验证分为三个独立维度
   - 行约束：每行数字1-9不能重复
   - 列约束：每列数字1-9不能重复  
   - 3×3子方格约束：每个3×3区域数字1-9不能重复

2. **坐标映射**：通过数学公式 `k = i // 3 * 3 + j // 3` 将二维坐标(i,j)映射到对应的3×3子方格编号
   - `i // 3` 和 `j // 3` 确定所在的大区域
   - 乘以3并相加得到唯一的子方格索引(0-8)

3. **布尔标记法**：使用三个二维布尔数组记录数字出现情况
   - `row[i][num]`：数字num是否在第i行出现过
   - `col[j][num]`：数字num是否在第j列出现过
   - `sub[k][num]`：数字num是否在第k个子方格出现过

## 算法流程：
遍历每个单元格 → 跳过空位 → 检查当前数字是否在对应行/列/子方格中已存在 → 若存在则无效，否则标记为已存在 → 全部通过则有效

这种方法的**时间复杂度为O(1)**（固定9×9网格），**空间复杂度为O(1)**（使用固定大小的辅助数组），是验证数独有效性的最优解。

