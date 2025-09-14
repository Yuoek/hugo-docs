---
title: "day_0051 "
date: 2025-09-14T09:59:57+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0051 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def dfs(i: int):
            if i == n:
                ans.append(["".join(row) for row in g])
                return
            for j in range(n):
                if col[j] + dg[i + j] + udg[n - i + j] == 0:
                    g[i][j] = "Q"
                    col[j] = dg[i + j] = udg[n - i + j] = 1
                    dfs(i + 1)
                    col[j] = dg[i + j] = udg[n - i + j] = 0
                    g[i][j] = "."

        ans = []
        g = [["."] * n for _ in range(n)]
        col = [0] * n
        dg = [0] * (n << 1)
        udg = [0] * (n << 1)
        dfs(0)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        vector<int> dg(n << 1);
        vector<int> udg(n << 1);
        vector<vector<string>> ans;
        vector<string> t(n, string(n, '.'));
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                    t[i][j] = 'Q';
                    col[j] = dg[i + j] = udg[n - i + j] = 1;
                    dfs(i + 1);
                    col[j] = dg[i + j] = udg[n - i + j] = 0;
                    t[i][j] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private List<List<String>> ans = new ArrayList<>();
    private int[] col;
    private int[] dg;
    private int[] udg;
    private String[][] g;
    private int n;

    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        col = new int[n];
        dg = new int[n << 1];
        udg = new int[n << 1];
        g = new String[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(g[i], ".");
        }
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            List<String> t = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                t.add(String.join("", g[j]));
            }
            ans.add(t);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                g[i][j] = "Q";
                col[j] = dg[i + j] = udg[n - i + j] = 1;
                dfs(i + 1);
                col[j] = dg[i + j] = udg[n - i + j] = 0;
                g[i][j] = ".";
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0051  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def dfs(i: int):
            if i == n:  # 如果已经放置完所有皇后（到达第n行）
                ans.append(["".join(row) for row in g])  # 将当前棋盘状态加入答案
                return
            for j in range(n):  # 遍历当前行的每一列
                if col[j] + dg[i + j] + udg[n - i + j] == 0:  # 检查当前位置是否安全（列、对角线、反对角线都没有皇后）
                    g[i][j] = "Q"  # 放置皇后
                    col[j] = dg[i + j] = udg[n - i + j] = 1  # 标记列、对角线、反对角线为已占用
                    dfs(i + 1)  # 递归处理下一行
                    col[j] = dg[i + j] = udg[n - i + j] = 0  # 回溯：取消标记
                    g[i][j] = "."  # 回溯：移除皇后

        ans = []  # 存储所有解
        g = [["."] * n for _ in range(n)]  # 初始化棋盘，全部为'.'
        col = [0] * n  # 记录列是否被占用
        dg = [0] * (n << 1)  # 记录对角线是否被占用（长度为2n）
        udg = [0] * (n << 1)  # 记录反对角线是否被占用（长度为2n）
        dfs(0)  # 从第0行开始深度优先搜索
        return ans  # 返回所有解
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        vector<int> dg(n << 1);
        vector<int> udg(n << 1);
        vector<vector<string>> ans;
        vector<string> t(n, string(n, '.'));
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                    t[i][j] = 'Q';
                    col[j] = dg[i + j] = udg[n - i + j] = 1;
                    dfs(i + 1);
                    col[j] = dg[i + j] = udg[n - i + j] = 0;
                    t[i][j] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private List<List<String>> ans = new ArrayList<>();
    private int[] col;
    private int[] dg;
    private int[] udg;
    private String[][] g;
    private int n;

    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        col = new int[n];
        dg = new int[n << 1];
        udg = new int[n << 1];
        g = new String[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(g[i], ".");
        }
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            List<String> t = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                t.add(String.join("", g[j]));
            }
            ans.add(t);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                g[i][j] = "Q";
                col[j] = dg[i + j] = udg[n - i + j] = 1;
                dfs(i + 1);
                col[j] = dg[i + j] = udg[n - i + j] = 0;
                g[i][j] = ".";
            }
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0051  数学解释

```python 
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def dfs(i: int):
            if i == n:
                ans.append(["".join(row) for row in g])
                return
            for j in range(n):
                if col[j] + dg[i + j] + udg[n - i + j] == 0:
                    g[i][j] = "Q"
                    col[j] = dg[i + j] = udg[n - i + j] = 1
                    dfs(i + 1)
                    col[j] = dg[i + j] = udg[n - i + j] = 0
                    g[i][j] = "."

        ans = []
        g = [["."] * n for _ in range(n)]
        col = [0] * n
        dg = [0] * (n << 1)
        udg = [0] * (n << 1)
        dfs(0)
        return ans 
```


这段代码使用**回溯法**解决N皇后问题，体现了以下数学思想：

## 1. 组合数学思想
- 问题本质是在n×n棋盘上放置n个皇后，属于**排列组合问题**
- 使用DFS遍历所有可能的放置方案，但通过剪枝避免无效搜索

## 2. 约束满足问题(CSP)
- 皇后不能同行、同列、同对角线 → 三个约束条件
- 使用三个数组记录约束状态：
  - `col[j]`: 记录第j列是否有皇后
  - `dg[i+j]`: 记录主对角线(左上到右下)是否有皇后
  - `udg[n-i+j]`: 记录副对角线(右上到左下)是否有皇后

## 3. 对角线数学表示
- **主对角线**: 同一主对角线上所有点的 `行号+列号 = 常数`
- **副对角线**: 同一副对角线上所有点的 `行号-列号 = 常数` (代码中通过 `n-i+j` 处理为正值)

## 4. 递归与数学归纳法
- 基础情况：`i == n` 时找到完整解
- 归纳步骤：在第i行尝试所有可能位置，递归处理第i+1行

## 5. 状态空间搜索
- 使用DFS系统性地探索解空间
- 通过约束条件剪枝，避免无效搜索，时间复杂度从O(nⁿ)优化到O(n!)

这种解法将几何约束(对角线)转化为代数表达式，体现了**数学建模**思想，将空间几何问题转化为代数约束问题。


