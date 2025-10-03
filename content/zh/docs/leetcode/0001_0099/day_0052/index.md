---
title: "day_0052 "
date: 2025-09-14T09:58:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0052 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def totalNQueens(self, n: int) -> int:
        def dfs(i: int):
            if i == n:
                nonlocal ans
                ans += 1
                return
            for j in range(n):
                a, b = i + j, i - j + n
                if cols[j] or dg[a] or udg[b]:
                    continue
                cols[j] = dg[a] = udg[b] = True
                dfs(i + 1)
                cols[j] = dg[a] = udg[b] = False

        cols = [False] * 10
        dg = [False] * 20
        udg = [False] * 20
        ans = 0
        dfs(0)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int totalNQueens(int n) {
        bitset<10> cols;
        bitset<20> dg;
        bitset<20> udg;
        int ans = 0;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ++ans;
                return;
            }
            for (int j = 0; j < n; ++j) {
                int a = i + j, b = i - j + n;
                if (cols[j] || dg[a] || udg[b]) continue;
                cols[j] = dg[a] = udg[b] = 1;
                dfs(i + 1);
                cols[j] = dg[a] = udg[b] = 0;
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
    private int n;
    private int ans;
    private boolean[] cols = new boolean[10];
    private boolean[] dg = new boolean[20];
    private boolean[] udg = new boolean[20];

    public int totalNQueens(int n) {
        this.n = n;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            ++ans;
            return;
        }
        for (int j = 0; j < n; ++j) {
            int a = i + j, b = i - j + n;
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = true;
            dg[a] = true;
            udg[b] = true;
            dfs(i + 1);
            cols[j] = false;
            dg[a] = false;
            udg[b] = false;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0052  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def totalNQueens(self, n: int) -> int:
        def dfs(i: int):  # 深度优先搜索函数，i表示当前处理的行数
            if i == n:  # 如果已经处理完所有行，说明找到一个有效解
                nonlocal ans  # 声明使用外部变量ans
                ans += 1  # 解的数量加1
                return  # 返回上一层
            for j in range(n):  # 遍历当前行的每一列
                a, b = i + j, i - j + n  # 计算主对角线和副对角线的索引
                if cols[j] or dg[a] or udg[b]:  # 如果当前列或对角线已被占用
                    continue  # 跳过该位置，继续尝试下一列
                cols[j] = dg[a] = udg[b] = True  # 标记当前列和对角线为已占用
                dfs(i + 1)  # 递归处理下一行
                cols[j] = dg[a] = udg[b] = False  # 回溯，取消当前标记

        cols = [False] * 10  # 标记列是否被占用，最大支持10列
        dg = [False] * 20  # 标记主对角线是否被占用，最大支持20条对角线
        udg = [False] * 20  # 标记副对角线是否被占用，最大支持20条对角线
        ans = 0  # 记录有效解的数量
        dfs(0)  # 从第0行开始搜索
        return ans  # 返回N皇后问题的解的数量
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int totalNQueens(int n) {
        bitset<10> cols;
        bitset<20> dg;
        bitset<20> udg;
        int ans = 0;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ++ans;
                return;
            }
            for (int j = 0; j < n; ++j) {
                int a = i + j, b = i - j + n;
                if (cols[j] || dg[a] || udg[b]) continue;
                cols[j] = dg[a] = udg[b] = 1;
                dfs(i + 1);
                cols[j] = dg[a] = udg[b] = 0;
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
    private int n;
    private int ans;
    private boolean[] cols = new boolean[10];
    private boolean[] dg = new boolean[20];
    private boolean[] udg = new boolean[20];

    public int totalNQueens(int n) {
        this.n = n;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            ++ans;
            return;
        }
        for (int j = 0; j < n; ++j) {
            int a = i + j, b = i - j + n;
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = true;
            dg[a] = true;
            udg[b] = true;
            dfs(i + 1);
            cols[j] = false;
            dg[a] = false;
            udg[b] = false;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0052  数学解释

```python 
class Solution:
    def totalNQueens(self, n: int) -> int:
        def dfs(i: int):
            if i == n:
                nonlocal ans
                ans += 1
                return
            for j in range(n):
                a, b = i + j, i - j + n
                if cols[j] or dg[a] or udg[b]:
                    continue
                cols[j] = dg[a] = udg[b] = True
                dfs(i + 1)
                cols[j] = dg[a] = udg[b] = False

        cols = [False] * 10
        dg = [False] * 20
        udg = [False] * 20
        ans = 0
        dfs(0)
        return ans 
```


这段代码使用**回溯法**和**位运算优化**来解决N皇后问题，具体体现了以下数学思想：

1. **组合数学思想**：寻找所有可能的皇后放置方式，计算有效解的数量

2. **对角线数学关系**：
   - 主对角线：`i + j` 为常数（左上到右下）
   - 副对角线：`i - j` 为常数（右上到左下）
   通过 `i + j` 和 `i - j + n`（加n避免负数索引）来唯一标识每条对角线

3. **集合论思想**：使用三个布尔数组表示约束条件
   - `cols[j]`：第j列是否被占用
   - `dg[a]`：主对角线a是否被占用  
   - `udg[b]`：副对角线b是否被占用

4. **递归与回溯**：深度优先搜索尝试所有可能位置，遇到冲突时回溯

5. **剪枝优化**：通过提前检测冲突（列冲突、对角线冲突）来避免无效搜索，大幅减少计算量

时间复杂度：O(n!)，但由于剪枝优化，实际运行效率远高于朴素的穷举法。


