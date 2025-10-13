---
title: "0051_N 皇后"
date: 2025-10-08T18:34:13+08:00
weight: 6
tags: [分治, 动态规划, 回溯, 字符串, 排序, 数学, 数组, 模拟, 矩阵, 贪心, 递归]
---

{{< markmap >}}
### [0051_N 皇后](#51)
#### [数组](#51)
#### [回溯](#51)
### [0052_N 皇后 II](#52)
#### [回溯](#52)
### [0053_最大子数组和](#53)
#### [数组](#53)
#### [分治](#53)
#### [动态规划](#53)
### [0054_螺旋矩阵](#54)
#### [数组](#54)
#### [矩阵](#54)
#### [模拟](#54)
### [0055_跳跃游戏](#55)
#### [贪心](#55)
#### [数组](#55)
#### [动态规划](#55)
### [0056_合并区间](#56)
#### [数组](#56)
#### [排序](#56)
### [0057_插入区间](#57)
#### [数组](#57)
### [0058_最后一个单词的长度](#58)
#### [字符串](#58)
### [0059_螺旋矩阵 II](#59)
#### [数组](#59)
#### [矩阵](#59)
#### [模拟](#59)
### [0060_排列序列](#60)
#### [递归](#60)
#### [数学](#60)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0051_N 皇后
___
#### 数组
___
#### 回溯
---
### 0052_N 皇后 II
___
#### 回溯
---
### 0053_最大子数组和
___
#### 数组
___
#### 分治
___
#### 动态规划
---
### 0054_螺旋矩阵
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 0055_跳跃游戏
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 0056_合并区间
___
#### 数组
___
#### 排序
---
### 0057_插入区间
___
#### 数组
---
### 0058_最后一个单词的长度
___
#### 字符串
---
### 0059_螺旋矩阵 II
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 0060_排列序列
___
#### 递归
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 分治 | 动态规划 | 回溯 |
| 字符串 | 排序 | 数学 |
| 数组 | 模拟 | 矩阵 |
| 贪心 | 递归 |  |

# [51. N 皇后](https://leetcode.cn/problems/n-queens){#51}

{{< tabs "51" >}}

{{% tab "python" %}}
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
{{% tab "java" %}}
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
{{% /tab %}}
{{% tab "cpp" %}}
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
{{% tab "go" %}}
```go
func solveNQueens(n int) (ans [][]string) {
	col := make([]int, n)
	dg := make([]int, n<<1)
	udg := make([]int, n<<1)
	t := make([][]byte, n)
	for i := range t {
		t[i] = make([]byte, n)
		for j := range t[i] {
			t[i][j] = '.'
		}
	}
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			tmp := make([]string, n)
			for i := range tmp {
				tmp[i] = string(t[i])
			}
			ans = append(ans, tmp)
			return
		}
		for j := 0; j < n; j++ {
			if col[j]+dg[i+j]+udg[n-i+j] == 0 {
				col[j], dg[i+j], udg[n-i+j] = 1, 1, 1
				t[i][j] = 'Q'
				dfs(i + 1)
				t[i][j] = '.'
				col[j], dg[i+j], udg[n-i+j] = 0, 0, 0
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
function solveNQueens(n: number): string[][] {
    const col: number[] = Array(n).fill(0);
    const dg: number[] = Array(n << 1).fill(0);
    const udg: number[] = Array(n << 1).fill(0);
    const ans: string[][] = [];
    const t: string[][] = Array.from({ length: n }, () => Array(n).fill('.'));
    const dfs = (i: number) => {
        if (i === n) {
            ans.push(t.map(x => x.join('')));
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (col[j] + dg[i + j] + udg[n - i + j] === 0) {
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
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int n;
    private int[] col;
    private int[] dg;
    private int[] udg;
    private IList<IList<string>> ans = new List<IList<string>>();
    private IList<string> t = new List<string>();

    public IList<IList<string>> SolveNQueens(int n) {
        this.n = n;
        col = new int[n];
        dg = new int[n << 1];
        udg = new int[n << 1];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            ans.Add(new List<string>(t));
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                char[] row = new char[n];
                Array.Fill(row, '.');
                row[j] = 'Q';
                t.Add(new string(row));
                col[j] = dg[i + j] = udg[n - i + j] = 1;
                dfs(i + 1);
                col[j] = dg[i + j] = udg[n - i + j] = 0;
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

<p>按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。</p>

<p><strong>n&nbsp;皇后问题</strong> 研究的是如何将 <code>n</code>&nbsp;个皇后放置在 <code>n×n</code> 的棋盘上，并且使皇后彼此之间不能相互攻击。</p>

<p>给你一个整数 <code>n</code> ，返回所有不同的&nbsp;<strong>n<em>&nbsp;</em>皇后问题</strong> 的解决方案。</p>

<div class="original__bRMd">
<div>
<p>每一种解法包含一个不同的&nbsp;<strong>n 皇后问题</strong> 的棋子放置方案，该方案中 <code>'Q'</code> 和 <code>'.'</code> 分别代表了皇后和空位。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0051.N-Queens/images/queens.jpg" style="width: 600px; height: 268px;" />
<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
<strong>解释：</strong>如上图所示，4 皇后问题存在两个不同的解法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>[["Q"]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
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

### 方法一：DFS(回溯)

我们定义三个数组 $col$, $dg$ 和 $udg$，分别表示列、正对角线和反对角线上的是否有皇后，如果位置 $(i, j)$ 有皇后，那么 $col[j]$, $dg[i + j]$ 和 $udg[n - i + j]$ 都为 $1$。另外，我们用一个数组 $g$ 记录当前棋盘的状态，初始时 $g$ 中的所有元素都是 `'.'`。

接下来，我们定义一个函数 $dfs(i)$，表示从第 $i$ 行开始放置皇后。

在 $dfs(i)$ 中，如果 $i=n$，说明我们已经完成了所有皇后的放置，我们将当前 $g$ 放入答案数组中，递归结束。

否则，我们枚举当前行的每一列 $j$，如果位置 $(i, j)$ 没有皇后，即 $col[j]$, $dg[i + j]$ 和 $udg[n - i + j]$ 都为 $0$，那么我们可以放置皇后，即把 $g[i][j]$ 改为 `'Q'`，并将 $col[j]$, $dg[i + j]$ 和 $udg[n - i + j]$ 都置为 $1$，然后继续搜索下一行，即调用 $dfs(i + 1)$，递归结束后，我们需要将 $g[i][j]$ 改回 `'.'` 并将 $col[j]$, $dg[i + j]$ 和 $udg[n - i + j]$ 都置为 $0$。

在主函数中，我们调用 $dfs(0)$ 开始递归，最后返回答案数组即可。

时间复杂度 $(n^2 \times n!)$，空间复杂度 $O(n)$。其中 $n$ 是题目给定的整数。

<!-- tabs:start -->

#### Python3

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

#### Java

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

#### C++

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

#### Go

```go
func solveNQueens(n int) (ans [][]string) {
	col := make([]int, n)
	dg := make([]int, n<<1)
	udg := make([]int, n<<1)
	t := make([][]byte, n)
	for i := range t {
		t[i] = make([]byte, n)
		for j := range t[i] {
			t[i][j] = '.'
		}
	}
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			tmp := make([]string, n)
			for i := range tmp {
				tmp[i] = string(t[i])
			}
			ans = append(ans, tmp)
			return
		}
		for j := 0; j < n; j++ {
			if col[j]+dg[i+j]+udg[n-i+j] == 0 {
				col[j], dg[i+j], udg[n-i+j] = 1, 1, 1
				t[i][j] = 'Q'
				dfs(i + 1)
				t[i][j] = '.'
				col[j], dg[i+j], udg[n-i+j] = 0, 0, 0
			}
		}
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function solveNQueens(n: number): string[][] {
    const col: number[] = Array(n).fill(0);
    const dg: number[] = Array(n << 1).fill(0);
    const udg: number[] = Array(n << 1).fill(0);
    const ans: string[][] = [];
    const t: string[][] = Array.from({ length: n }, () => Array(n).fill('.'));
    const dfs = (i: number) => {
        if (i === n) {
            ans.push(t.map(x => x.join('')));
            return;
        }
        for (let j = 0; j < n; ++j) {
            if (col[j] + dg[i + j] + udg[n - i + j] === 0) {
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
```

#### C#

```cs
public class Solution {
    private int n;
    private int[] col;
    private int[] dg;
    private int[] udg;
    private IList<IList<string>> ans = new List<IList<string>>();
    private IList<string> t = new List<string>();

    public IList<IList<string>> SolveNQueens(int n) {
        this.n = n;
        col = new int[n];
        dg = new int[n << 1];
        udg = new int[n << 1];
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == n) {
            ans.Add(new List<string>(t));
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                char[] row = new char[n];
                Array.Fill(row, '.');
                row[j] = 'Q';
                t.Add(new string(row));
                col[j] = dg[i + j] = udg[n - i + j] = 1;
                dfs(i + 1);
                col[j] = dg[i + j] = udg[n - i + j] = 0;
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

# [52. N 皇后 II](https://leetcode.cn/problems/n-queens-ii){#52}

{{< tabs "52" >}}

{{% tab "python" %}}
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
{{% tab "java" %}}
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
{{% /tab %}}
{{% tab "cpp" %}}
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
{{% tab "go" %}}
```go
func totalNQueens(n int) (ans int) {
	cols := [10]bool{}
	dg := [20]bool{}
	udg := [20]bool{}
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans++
			return
		}
		for j := 0; j < n; j++ {
			a, b := i+j, i-j+n
			if cols[j] || dg[a] || udg[b] {
				continue
			}
			cols[j], dg[a], udg[b] = true, true, true
			dfs(i + 1)
			cols[j], dg[a], udg[b] = false, false, false
		}
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function totalNQueens(n: number): number {
    const cols: boolean[] = Array(10).fill(false);
    const dg: boolean[] = Array(20).fill(false);
    const udg: boolean[] = Array(20).fill(false);
    let ans = 0;
    const dfs = (i: number) => {
        if (i === n) {
            ++ans;
            return;
        }
        for (let j = 0; j < n; ++j) {
            let [a, b] = [i + j, i - j + n];
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = dg[a] = udg[b] = true;
            dfs(i + 1);
            cols[j] = dg[a] = udg[b] = false;
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function totalNQueens(n) {
    const cols = Array(10).fill(false);
    const dg = Array(20).fill(false);
    const udg = Array(20).fill(false);
    let ans = 0;
    const dfs = i => {
        if (i === n) {
            ++ans;
            return;
        }
        for (let j = 0; j < n; ++j) {
            let [a, b] = [i + j, i - j + n];
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = dg[a] = udg[b] = true;
            dfs(i + 1);
            cols[j] = dg[a] = udg[b] = false;
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
    public int TotalNQueens(int n) {
        bool[] cols = new bool[10];
        bool[] dg = new bool[20];
        bool[] udg = new bool[20];
        int ans = 0;

        void dfs(int i) {
            if (i == n) {
                ans++;
                return;
            }
            for (int j = 0; j < n; j++) {
                int a = i + j, b = i - j + n;
                if (cols[j] || dg[a] || udg[b]) {
                    continue;
                }
                cols[j] = dg[a] = udg[b] = true;
                dfs(i + 1);
                cols[j] = dg[a] = udg[b] = false;
            }
        }

        dfs(0);
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

<p><strong>n&nbsp;皇后问题</strong> 研究的是如何将 <code>n</code>&nbsp;个皇后放置在 <code>n × n</code> 的棋盘上，并且使皇后彼此之间不能相互攻击。</p>

<p>给你一个整数 <code>n</code> ，返回 <strong>n 皇后问题</strong> 不同的解决方案的数量。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0052.N-Queens%20II/images/queens.jpg" style="width: 600px; height: 268px;" />
<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>2
<strong>解释：</strong>如上图所示，4 皇后问题存在两个不同的解法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
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

### 方法一：回溯

我们设计一个函数 $dfs(i)$，表示从第 $i$ 行开始搜索，搜索到的结果累加到答案中。

在第 $i$ 行，我们枚举第 $i$ 行的每一列，如果当前列不与前面已经放置的皇后发生冲突，那么我们就可以放置一个皇后，然后继续搜索下一行，即调用 $dfs(i + 1)$。

如果发生冲突，那么我们就跳过当前列，继续枚举下一列。

判断是否发生冲突，我们需要用三个数组分别记录每一列、每一条正对角线、每一条反对角线是否已经放置了皇后。

具体地，我们用 $cols$ 数组记录每一列是否已经放置了皇后，用 $dg$ 数组记录每一条正对角线是否已经放置了皇后，用 $udg$ 数组记录每一条反对角线是否已经放置了皇后。

时间复杂度 $O(n!)$，空间复杂度 $O(n)$。其中 $n$ 是皇后的数量。

<!-- tabs:start -->

#### Python3

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

#### Java

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

#### C++

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

#### Go

```go
func totalNQueens(n int) (ans int) {
	cols := [10]bool{}
	dg := [20]bool{}
	udg := [20]bool{}
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans++
			return
		}
		for j := 0; j < n; j++ {
			a, b := i+j, i-j+n
			if cols[j] || dg[a] || udg[b] {
				continue
			}
			cols[j], dg[a], udg[b] = true, true, true
			dfs(i + 1)
			cols[j], dg[a], udg[b] = false, false, false
		}
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function totalNQueens(n: number): number {
    const cols: boolean[] = Array(10).fill(false);
    const dg: boolean[] = Array(20).fill(false);
    const udg: boolean[] = Array(20).fill(false);
    let ans = 0;
    const dfs = (i: number) => {
        if (i === n) {
            ++ans;
            return;
        }
        for (let j = 0; j < n; ++j) {
            let [a, b] = [i + j, i - j + n];
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = dg[a] = udg[b] = true;
            dfs(i + 1);
            cols[j] = dg[a] = udg[b] = false;
        }
    };
    dfs(0);
    return ans;
}
```

#### JavaScript

```js
function totalNQueens(n) {
    const cols = Array(10).fill(false);
    const dg = Array(20).fill(false);
    const udg = Array(20).fill(false);
    let ans = 0;
    const dfs = i => {
        if (i === n) {
            ++ans;
            return;
        }
        for (let j = 0; j < n; ++j) {
            let [a, b] = [i + j, i - j + n];
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = dg[a] = udg[b] = true;
            dfs(i + 1);
            cols[j] = dg[a] = udg[b] = false;
        }
    };
    dfs(0);
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int TotalNQueens(int n) {
        bool[] cols = new bool[10];
        bool[] dg = new bool[20];
        bool[] udg = new bool[20];
        int ans = 0;

        void dfs(int i) {
            if (i == n) {
                ans++;
                return;
            }
            for (int j = 0; j < n; j++) {
                int a = i + j, b = i - j + n;
                if (cols[j] || dg[a] || udg[b]) {
                    continue;
                }
                cols[j] = dg[a] = udg[b] = true;
                dfs(i + 1);
                cols[j] = dg[a] = udg[b] = false;
            }
        }

        dfs(0);
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray){#53}

{{< tabs "53" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        def crossMaxSub(nums, left, mid, right):
            lsum = rsum = 0
            lmx = rmx = -inf
            for i in range(mid, left - 1, -1):
                lsum += nums[i]
                lmx = max(lmx, lsum)
            for i in range(mid + 1, right + 1):
                rsum += nums[i]
                rmx = max(rmx, rsum)
            return lmx + rmx

        def maxSub(nums, left, right):
            if left == right:
                return nums[left]
            mid = (left + right) >> 1
            lsum = maxSub(nums, left, mid)
            rsum = maxSub(nums, mid + 1, right)
            csum = crossMaxSub(nums, left, mid, right)
            return max(lsum, rsum, csum)

        left, right = 0, len(nums) - 1
        return maxSub(nums, left, right)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubArray(int[] nums) {
        return maxSub(nums, 0, nums.length - 1);
    }

    private int maxSub(int[] nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = (left + right) >>> 1;
        int lsum = maxSub(nums, left, mid);
        int rsum = maxSub(nums, mid + 1, right);
        return Math.max(Math.max(lsum, rsum), crossMaxSub(nums, left, mid, right));
    }

    private int crossMaxSub(int[] nums, int left, int mid, int right) {
        int lsum = 0, rsum = 0;
        int lmx = Integer.MIN_VALUE, rmx = Integer.MIN_VALUE;
        for (int i = mid; i >= left; --i) {
            lsum += nums[i];
            lmx = Math.max(lmx, lsum);
        }
        for (int i = mid + 1; i <= right; ++i) {
            rsum += nums[i];
            rmx = Math.max(rmx, rsum);
        }
        return lmx + rmx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], f = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            f = max(f, 0) + nums[i];
            ans = max(ans, f);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubArray(nums []int) int {
	ans, f := nums[0], nums[0]
	for _, x := range nums[1:] {
		f = max(f, 0) + x
		ans = max(ans, f)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubArray(nums: number[]): number {
    let [ans, f] = [nums[0], nums[0]];
    for (let i = 1; i < nums.length; ++i) {
        f = Math.max(f, 0) + nums[i];
        ans = Math.max(ans, f);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = nums[0];
        let mut f = nums[0];
        for i in 1..n {
            f = f.max(0) + nums[i];
            ans = ans.max(f);
        }
        ans
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
var maxSubArray = function (nums) {
    let [ans, f] = [nums[0], nums[0]];
    for (let i = 1; i < nums.length; ++i) {
        f = Math.max(f, 0) + nums[i];
        ans = Math.max(ans, f);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxSubArray(int[] nums) {
        int ans = nums[0], f = nums[0];
        for (int i = 1; i < nums.Length; ++i) {
            f = Math.Max(f, 0) + nums[i];
            ans = Math.Max(ans, f);
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

<p>给你一个整数数组 <code>nums</code> ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。</p>

<p><strong><span data-keyword="subarray-nonempty">子数组 </span></strong>是数组中的一个连续部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>输出：</strong>6
<strong>解释：</strong>连续子数组&nbsp;[4,-1,2,1] 的和最大，为&nbsp;6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,-1,7,8]
<strong>输出：</strong>23
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果你已经实现复杂度为 <code>O(n)</code> 的解法，尝试使用更为精妙的 <strong>分治法</strong> 求解。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以元素 $\textit{nums}[i]$ 为结尾的连续子数组的最大和，初始时 $f[0] = \textit{nums}[0]$，那么最终我们要求的答案即为 $\max_{0 \leq i < n} f[i]$。

考虑 $f[i]$，其中 $i \geq 1$，它的状态转移方程为：

$$
f[i] = \max(f[i - 1] + \textit{nums}[i], \textit{nums}[i])
$$

也即：

$$
f[i] = \max(f[i - 1], 0) + \textit{nums}[i]
$$

由于 $f[i]$ 只与 $f[i - 1]$ 有关系，因此我们可以只用一个变量 $f$ 来维护对于当前 $f[i]$ 的值是多少，然后进行状态转移即可。答案为 $\max_{0 \leq i < n} f$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = f = nums[0]
        for x in nums[1:]:
            f = max(f, 0) + x
            ans = max(ans, f)
        return ans
```

#### Java

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        for (int i = 1, f = nums[0]; i < nums.length; ++i) {
            f = Math.max(f, 0) + nums[i];
            ans = Math.max(ans, f);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], f = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            f = max(f, 0) + nums[i];
            ans = max(ans, f);
        }
        return ans;
    }
};
```

#### Go

```go
func maxSubArray(nums []int) int {
	ans, f := nums[0], nums[0]
	for _, x := range nums[1:] {
		f = max(f, 0) + x
		ans = max(ans, f)
	}
	return ans
}
```

#### TypeScript

```ts
function maxSubArray(nums: number[]): number {
    let [ans, f] = [nums[0], nums[0]];
    for (let i = 1; i < nums.length; ++i) {
        f = Math.max(f, 0) + nums[i];
        ans = Math.max(ans, f);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = nums[0];
        let mut f = nums[0];
        for i in 1..n {
            f = f.max(0) + nums[i];
            ans = ans.max(f);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let [ans, f] = [nums[0], nums[0]];
    for (let i = 1; i < nums.length; ++i) {
        f = Math.max(f, 0) + nums[i];
        ans = Math.max(ans, f);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxSubArray(int[] nums) {
        int ans = nums[0], f = nums[0];
        for (int i = 1; i < nums.Length; ++i) {
            f = Math.Max(f, 0) + nums[i];
            ans = Math.Max(ans, f);
        }
        return ans;
    }
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
    def maxSubArray(self, nums: List[int]) -> int:
        def crossMaxSub(nums, left, mid, right):
            lsum = rsum = 0
            lmx = rmx = -inf
            for i in range(mid, left - 1, -1):
                lsum += nums[i]
                lmx = max(lmx, lsum)
            for i in range(mid + 1, right + 1):
                rsum += nums[i]
                rmx = max(rmx, rsum)
            return lmx + rmx

        def maxSub(nums, left, right):
            if left == right:
                return nums[left]
            mid = (left + right) >> 1
            lsum = maxSub(nums, left, mid)
            rsum = maxSub(nums, mid + 1, right)
            csum = crossMaxSub(nums, left, mid, right)
            return max(lsum, rsum, csum)

        left, right = 0, len(nums) - 1
        return maxSub(nums, left, right)
```

#### Java

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return maxSub(nums, 0, nums.length - 1);
    }

    private int maxSub(int[] nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = (left + right) >>> 1;
        int lsum = maxSub(nums, left, mid);
        int rsum = maxSub(nums, mid + 1, right);
        return Math.max(Math.max(lsum, rsum), crossMaxSub(nums, left, mid, right));
    }

    private int crossMaxSub(int[] nums, int left, int mid, int right) {
        int lsum = 0, rsum = 0;
        int lmx = Integer.MIN_VALUE, rmx = Integer.MIN_VALUE;
        for (int i = mid; i >= left; --i) {
            lsum += nums[i];
            lmx = Math.max(lmx, lsum);
        }
        for (int i = mid + 1; i <= right; ++i) {
            rsum += nums[i];
            rmx = Math.max(rmx, rsum);
        }
        return lmx + rmx;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix){#54}

{{< tabs "54" >}}

{{% tab "python" %}}
```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        ans = []
        for _ in range(m * n):
            ans.append(matrix[i][j])
            matrix[i][j] += 300
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= m or y < 0 or y >= n or matrix[x][y] > 100:
                k = (k + 1) % 4
            i += dirs[k]
            j += dirs[k + 1]
        for i in range(m):
            for j in range(n):
                matrix[i][j] -= 300
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        List<Integer> ans = new ArrayList<>();
        for (int h = m * n; h > 0; --h) {
            ans.add(matrix[i][j]);
            matrix[i][j] += 300;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                matrix[i][j] -= 300;
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        for (int h = m * n; h; --h) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] += 300;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                matrix[i][j] -= 300;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func spiralOrder(matrix [][]int) (ans []int) {
	m, n := len(matrix), len(matrix[0])
	dirs := [5]int{0, 1, 0, -1, 0}
	i, j, k := 0, 0, 0
	for h := m * n; h > 0; h-- {
		ans = append(ans, matrix[i][j])
		matrix[i][j] += 300
		x, y := i+dirs[k], j+dirs[k+1]
		if x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100 {
			k = (k + 1) % 4
		}
		i, j = i+dirs[k], j+dirs[k+1]
	}
	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			matrix[i][j] -= 300
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function spiralOrder(matrix: number[][]): number[] {
    const m = matrix.length;
    const n = matrix[0].length;
    const ans: number[] = [];
    const dirs = [0, 1, 0, -1, 0];
    for (let h = m * n, i = 0, j = 0, k = 0; h > 0; --h) {
        ans.push(matrix[i][j]);
        matrix[i][j] += 300;
        const x = i + dirs[k];
        const y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            matrix[i][j] -= 300;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn spiral_order(mut matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dirs = vec![0, 1, 0, -1, 0];
        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        let mut ans = Vec::new();

        for _ in 0..(m * n) {
            ans.push(matrix[i][j]);
            matrix[i][j] += 300;
            let x = i as i32 + dirs[k] as i32;
            let y = j as i32 + dirs[k + 1] as i32;

            if x < 0
                || x >= m as i32
                || y < 0
                || y >= n as i32
                || matrix[x as usize][y as usize] > 100
            {
                k = (k + 1) % 4;
            }

            i = (i as i32 + dirs[k] as i32) as usize;
            j = (j as i32 + dirs[k + 1] as i32) as usize;
        }

        for i in 0..m {
            for j in 0..n {
                matrix[i][j] -= 300;
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const ans = [];
    const dirs = [0, 1, 0, -1, 0];
    for (let h = m * n, i = 0, j = 0, k = 0; h > 0; --h) {
        ans.push(matrix[i][j]);
        matrix[i][j] += 300;
        const x = i + dirs[k];
        const y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            matrix[i][j] -= 300;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int m = matrix.Length, n = matrix[0].Length;
        int[] dirs = { 0, 1, 0, -1, 0 };
        int i = 0, j = 0, k = 0;
        IList<int> ans = new List<int>();
        for (int h = m * n; h > 0; --h) {
            ans.Add(matrix[i][j]);
            matrix[i][j] += 300;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        for (int a = 0; a < m; ++a) {
            for (int b = 0; b < n; ++b) {
                matrix[a][b] -= 300;
            }
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

<p>给你一个 <code>m</code> 行 <code>n</code> 列的矩阵 <code>matrix</code> ，请按照 <strong>顺时针螺旋顺序</strong> ，返回矩阵中的所有元素。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0054.Spiral%20Matrix/images/spiral1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0054.Spiral%20Matrix/images/spiral.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>输出：</strong>[1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 10</code></li>
	<li><code>-100 <= matrix[i][j] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟整个遍历的过程，用 $i$ 和 $j$ 分别表示当前访问到的元素的行和列，用 $k$ 表示当前的方向，用数组或哈希表 $\textit{vis}$ 记录每个元素是否被访问过。每次我们访问到一个元素后，将其标记为已访问，然后按照当前的方向前进一步，如果前进一步后发现越界或者已经访问过，则改变方向继续前进，直到遍历完整个矩阵。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        dirs = (0, 1, 0, -1, 0)
        vis = [[False] * n for _ in range(m)]
        i = j = k = 0
        ans = []
        for _ in range(m * n):
            ans.append(matrix[i][j])
            vis[i][j] = True
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= m or y < 0 or y >= n or vis[x][y]:
                k = (k + 1) % 4
            i += dirs[k]
            j += dirs[k + 1]
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        List<Integer> ans = new ArrayList<>();
        boolean[][] vis = new boolean[m][n];
        for (int h = m * n; h > 0; --h) {
            ans.add(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (int h = m * n; h; --h) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
};
```

#### Go

```go
func spiralOrder(matrix [][]int) (ans []int) {
	m, n := len(matrix), len(matrix[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := [5]int{0, 1, 0, -1, 0}
	i, j, k := 0, 0, 0
	for h := m * n; h > 0; h-- {
		ans = append(ans, matrix[i][j])
		vis[i][j] = true
		x, y := i+dirs[k], j+dirs[k+1]
		if x < 0 || x >= m || y < 0 || y >= n || vis[x][y] {
			k = (k + 1) % 4
		}
		i, j = i+dirs[k], j+dirs[k+1]
	}
	return
}
```

#### TypeScript

```ts
function spiralOrder(matrix: number[][]): number[] {
    const m = matrix.length;
    const n = matrix[0].length;
    const ans: number[] = [];
    const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
    const dirs = [0, 1, 0, -1, 0];
    for (let h = m * n, i = 0, j = 0, k = 0; h > 0; --h) {
        ans.push(matrix[i][j]);
        vis[i][j] = true;
        const x = i + dirs[k];
        const y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dirs = vec![0, 1, 0, -1, 0];
        let mut vis = vec![vec![false; n]; m];
        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        let mut ans = Vec::new();

        for _ in 0..(m * n) {
            ans.push(matrix[i][j]);
            vis[i][j] = true;
            let x = i as i32 + dirs[k] as i32;
            let y = j as i32 + dirs[k + 1] as i32;

            if x < 0 || x >= m as i32 || y < 0 || y >= n as i32 || vis[x as usize][y as usize] {
                k = (k + 1) % 4;
            }

            i = (i as i32 + dirs[k] as i32) as usize;
            j = (j as i32 + dirs[k + 1] as i32) as usize;
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const ans = [];
    const vis = Array.from({ length: m }, () => Array(n).fill(false));
    const dirs = [0, 1, 0, -1, 0];
    for (let h = m * n, i = 0, j = 0, k = 0; h > 0; --h) {
        ans.push(matrix[i][j]);
        vis[i][j] = true;
        const x = i + dirs[k];
        const y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int m = matrix.Length, n = matrix[0].Length;
        int[] dirs = { 0, 1, 0, -1, 0 };
        int i = 0, j = 0, k = 0;
        IList<int> ans = new List<int>();
        bool[,] vis = new bool[m, n];
        for (int h = m * n; h > 0; --h) {
            ans.Add(matrix[i][j]);
            vis[i, j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x, y]) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：模拟（空间优化）

注意到，题目中矩阵元素取值范围为 $[-100, 100]$，因此，我们可以将访问过的元素加上一个较大的值，比如 $300$，这样只需要判断访问的元素是否大于 $100$ 即可，无需额外的空间记录是否访问过。如果最终需要将访问过的元素恢复原值，可以在遍历结束后再次遍历一遍矩阵，将所有元素减去 $300$。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        ans = []
        for _ in range(m * n):
            ans.append(matrix[i][j])
            matrix[i][j] += 300
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= m or y < 0 or y >= n or matrix[x][y] > 100:
                k = (k + 1) % 4
            i += dirs[k]
            j += dirs[k + 1]
        for i in range(m):
            for j in range(n):
                matrix[i][j] -= 300
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        List<Integer> ans = new ArrayList<>();
        for (int h = m * n; h > 0; --h) {
            ans.add(matrix[i][j]);
            matrix[i][j] += 300;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                matrix[i][j] -= 300;
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        for (int h = m * n; h; --h) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] += 300;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                matrix[i][j] -= 300;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func spiralOrder(matrix [][]int) (ans []int) {
	m, n := len(matrix), len(matrix[0])
	dirs := [5]int{0, 1, 0, -1, 0}
	i, j, k := 0, 0, 0
	for h := m * n; h > 0; h-- {
		ans = append(ans, matrix[i][j])
		matrix[i][j] += 300
		x, y := i+dirs[k], j+dirs[k+1]
		if x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100 {
			k = (k + 1) % 4
		}
		i, j = i+dirs[k], j+dirs[k+1]
	}
	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			matrix[i][j] -= 300
		}
	}
	return
}
```

#### TypeScript

```ts
function spiralOrder(matrix: number[][]): number[] {
    const m = matrix.length;
    const n = matrix[0].length;
    const ans: number[] = [];
    const dirs = [0, 1, 0, -1, 0];
    for (let h = m * n, i = 0, j = 0, k = 0; h > 0; --h) {
        ans.push(matrix[i][j]);
        matrix[i][j] += 300;
        const x = i + dirs[k];
        const y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            matrix[i][j] -= 300;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn spiral_order(mut matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dirs = vec![0, 1, 0, -1, 0];
        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        let mut ans = Vec::new();

        for _ in 0..(m * n) {
            ans.push(matrix[i][j]);
            matrix[i][j] += 300;
            let x = i as i32 + dirs[k] as i32;
            let y = j as i32 + dirs[k + 1] as i32;

            if x < 0
                || x >= m as i32
                || y < 0
                || y >= n as i32
                || matrix[x as usize][y as usize] > 100
            {
                k = (k + 1) % 4;
            }

            i = (i as i32 + dirs[k] as i32) as usize;
            j = (j as i32 + dirs[k + 1] as i32) as usize;
        }

        for i in 0..m {
            for j in 0..n {
                matrix[i][j] -= 300;
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const ans = [];
    const dirs = [0, 1, 0, -1, 0];
    for (let h = m * n, i = 0, j = 0, k = 0; h > 0; --h) {
        ans.push(matrix[i][j]);
        matrix[i][j] += 300;
        const x = i + dirs[k];
        const y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            matrix[i][j] -= 300;
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int m = matrix.Length, n = matrix[0].Length;
        int[] dirs = { 0, 1, 0, -1, 0 };
        int i = 0, j = 0, k = 0;
        IList<int> ans = new List<int>();
        for (int h = m * n; h > 0; --h) {
            ans.Add(matrix[i][j]);
            matrix[i][j] += 300;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        for (int a = 0; a < m; ++a) {
            for (int b = 0; b < n; ++b) {
                matrix[a][b] -= 300;
            }
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

# [55. 跳跃游戏](https://leetcode.cn/problems/jump-game){#55}

{{< tabs "55" >}}

{{% tab "python" %}}
```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mx = 0
        for i, x in enumerate(nums):
            if mx < i:
                return False
            mx = max(mx, i + x)
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canJump(int[] nums) {
        int mx = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (mx < i) {
                return false;
            }
            mx = Math.max(mx, i + nums[i]);
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
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx < i) {
                return false;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canJump(nums []int) bool {
	mx := 0
	for i, x := range nums {
		if mx < i {
			return false
		}
		mx = max(mx, i+x)
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canJump(nums: number[]): boolean {
    let mx: number = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (mx < i) {
            return false;
        }
        mx = Math.max(mx, i + nums[i]);
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut mx = 0;

        for i in 0..n {
            if mx < i {
                return false;
            }
            mx = std::cmp::max(mx, i + (nums[i] as usize));
        }

        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {
    let mx = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (mx < i) {
            return false;
        }
        mx = Math.max(mx, i + nums[i]);
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CanJump(int[] nums) {
        int mx = 0;
        for (int i = 0; i < nums.Length; ++i) {
            if (mx < i) {
                return false;
            }
            mx = Math.Max(mx, i + nums[i]);
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非负整数数组&nbsp;<code>nums</code> ，你最初位于数组的 <strong>第一个下标</strong> 。数组中的每个元素代表你在该位置可以跳跃的最大长度。</p>

<p>判断你是否能够到达最后一个下标，如果可以，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,1,1,4]
<strong>输出：</strong>true
<strong>解释：</strong>可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,0,4]
<strong>输出：</strong>false
<strong>解释：</strong>无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用变量 $mx$ 维护当前能够到达的最远下标，初始时 $mx = 0$。

我们从左到右遍历数组，对于遍历到的每个位置 $i$，如果 $mx \lt i$，说明当前位置无法到达，直接返回 `false`。否则，我们可以通过跳跃从位置 $i$ 到达的最远位置为 $i+nums[i]$，我们用 $i+nums[i]$ 更新 $mx$ 的值，即 $mx = \max(mx, i + nums[i])$。

遍历结束，直接返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

相似题目：

-   [45. 跳跃游戏 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0045.Jump%20Game%20II/README.md)
-   [1024. 视频拼接](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1024.Video%20Stitching/README.md)
-   [1326. 灌溉花园的最少水龙头数目](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1326.Minimum%20Number%20of%20Taps%20to%20Open%20to%20Water%20a%20Garden/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mx = 0
        for i, x in enumerate(nums):
            if mx < i:
                return False
            mx = max(mx, i + x)
        return True
```

#### Java

```java
class Solution {
    public boolean canJump(int[] nums) {
        int mx = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (mx < i) {
                return false;
            }
            mx = Math.max(mx, i + nums[i]);
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx < i) {
                return false;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};
```

#### Go

```go
func canJump(nums []int) bool {
	mx := 0
	for i, x := range nums {
		if mx < i {
			return false
		}
		mx = max(mx, i+x)
	}
	return true
}
```

#### TypeScript

```ts
function canJump(nums: number[]): boolean {
    let mx: number = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (mx < i) {
            return false;
        }
        mx = Math.max(mx, i + nums[i]);
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut mx = 0;

        for i in 0..n {
            if mx < i {
                return false;
            }
            mx = std::cmp::max(mx, i + (nums[i] as usize));
        }

        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {
    let mx = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (mx < i) {
            return false;
        }
        mx = Math.max(mx, i + nums[i]);
    }
    return true;
};
```

#### C#

```cs
public class Solution {
    public bool CanJump(int[] nums) {
        int mx = 0;
        for (int i = 0; i < nums.Length; ++i) {
            if (mx < i) {
                return false;
            }
            mx = Math.Max(mx, i + nums[i]);
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [56. 合并区间](https://leetcode.cn/problems/merge-intervals){#56}

{{< tabs "56" >}}

{{% tab "python" %}}
```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = [intervals[0]]
        for s, e in intervals[1:]:
            if ans[-1][1] < s:
                ans.append([s, e])
            else:
                ans[-1][1] = max(ans[-1][1], e)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ans.get(ans.size() - 1)[1] < s) {
                ans.add(intervals[i]);
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], e);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func merge(intervals [][]int) (ans [][]int) {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	ans = append(ans, intervals[0])
	for _, e := range intervals[1:] {
		if ans[len(ans)-1][1] < e[0] {
			ans = append(ans, e)
		} else {
			ans[len(ans)-1][1] = max(ans[len(ans)-1][1], e[1])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function merge(intervals: number[][]): number[][] {
    intervals.sort((a, b) => a[0] - b[0]);
    const n = intervals.length;
    const res = [];
    let i = 0;
    while (i < n) {
        let [l, r] = intervals[i];
        i++;
        while (i < n && r >= intervals[i][0]) {
            r = Math.max(r, intervals[i][1]);
            i++;
        }
        res.push([l, r]);
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.sort_unstable_by(|a, b| a[0].cmp(&b[0]));
        let n = intervals.len();
        let mut res = vec![];
        let mut i = 0;
        while i < n {
            let l = intervals[i][0];
            let mut r = intervals[i][1];
            i += 1;
            while i < n && r >= intervals[i][0] {
                r = r.max(intervals[i][1]);
                i += 1;
            }
            res.push(vec![l, r]);
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[][] Merge(int[][] intervals) {
        intervals = intervals.OrderBy(a => a[0]).ToArray();
        var ans = new List<int[]>();
        ans.Add(intervals[0]);
        for (int i = 1; i < intervals.Length; ++i) {
            if (ans[ans.Count - 1][1] < intervals[i][0]) {
                ans.Add(intervals[i]);
            } else {
                ans[ans.Count - 1][1] = Math.Max(ans[ans.Count - 1][1], intervals[i][1]);
            }
        }
        return ans.ToArray();
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    intervals.sort((a, b) => a[0] - b[0]);
    const result = [];
    const n = intervals.length;
    let i = 0;
    while (i < n) {
        const left = intervals[i][0];
        let right = intervals[i][1];
        while (true) {
            i++;
            if (i < n && right >= intervals[i][0]) {
                right = Math.max(right, intervals[i][1]);
            } else {
                result.push([left, right]);
                break;
            }
        }
    }
    return result;
};
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun merge(intervals: Array<IntArray>): Array<IntArray> {
        intervals.sortBy { it[0] }
        val result = mutableListOf<IntArray>()
        val n = intervals.size
        var i = 0
        while (i < n) {
            val left = intervals[i][0]
            var right = intervals[i][1]
            while (true) {
                i++
                if (i < n && right >= intervals[i][0]) {
                    right = maxOf(right, intervals[i][1])
                } else {
                    result.add(intArrayOf(left, right))
                    break
                }
            }
        }
        return result.toTypedArray()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>以数组 <code>intervals</code> 表示若干个区间的集合，其中单个区间为 <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 。请你合并所有重叠的区间，并返回&nbsp;<em>一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>输出：</strong>[[1,6],[8,10],[15,18]]
<strong>解释：</strong>区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[4,5]]
<strong>输出：</strong>[[1,5]]
<strong>解释：</strong>区间 [1,4] 和 [4,5] 可被视为重叠区间。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>intervals = [[4,7],[1,4]]
<b>输出：</b>[[1,7]]
<b>解释：</b>区间 [1,4] 和 [4,7] 可被视为重叠区间。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 一次遍历

我们可以将区间按照左端点升序排列，然后遍历区间进行合并操作。

具体的合并操作如下。

我们先将第一个区间加入答案，然后依次考虑之后的每个区间：

-   如果答案数组中最后一个区间的右端点小于当前考虑区间的左端点，说明两个区间不会重合，因此我们可以直接将当前区间加入答案数组末尾；
-   否则，说明两个区间重合，我们需要用当前区间的右端点更新答案数组中最后一个区间的右端点，将其置为二者的较大值。

最后，我们返回答案数组即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为区间个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        st, ed = intervals[0]
        for s, e in intervals[1:]:
            if ed < s:
                ans.append([st, ed])
                st, ed = s, e
            else:
                ed = max(ed, e)
        ans.append([st, ed])
        return ans
```

#### Java

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int st = intervals[0][0], ed = intervals[0][1];
        List<int[]> ans = new ArrayList<>();
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ed < s) {
                ans.add(new int[] {st, ed});
                st = s;
                ed = e;
            } else {
                ed = Math.max(ed, e);
            }
        }
        ans.add(new int[] {st, ed});
        return ans.toArray(new int[ans.size()][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], ed = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i) {
            if (ed < intervals[i][0]) {
                ans.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            } else {
                ed = max(ed, intervals[i][1]);
            }
        }
        ans.push_back({st, ed});
        return ans;
    }
};
```

#### Go

```go
func merge(intervals [][]int) (ans [][]int) {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	st, ed := intervals[0][0], intervals[0][1]
	for _, e := range intervals[1:] {
		if ed < e[0] {
			ans = append(ans, []int{st, ed})
			st, ed = e[0], e[1]
		} else if ed < e[1] {
			ed = e[1]
		}
	}
	ans = append(ans, []int{st, ed})
	return ans
}
```

#### TypeScript

```ts
function merge(intervals: number[][]): number[][] {
    intervals.sort((a, b) => a[0] - b[0]);
    const ans: number[][] = [];
    let [st, ed] = intervals[0];
    for (const [s, e] of intervals.slice(1)) {
        if (ed < s) {
            ans.push([st, ed]);
            [st, ed] = [s, e];
        } else {
            ed = Math.max(ed, e);
        }
    }
    ans.push([st, ed]);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.sort_unstable_by(|a, b| a[0].cmp(&b[0]));
        let n = intervals.len();
        let mut res = vec![];
        let mut i = 0;
        while i < n {
            let l = intervals[i][0];
            let mut r = intervals[i][1];
            i += 1;
            while i < n && r >= intervals[i][0] {
                r = r.max(intervals[i][1]);
                i += 1;
            }
            res.push(vec![l, r]);
        }
        res
    }
}
```

#### C#

```cs
public class Solution {
    public int[][] Merge(int[][] intervals) {
        intervals = intervals.OrderBy(a => a[0]).ToArray();
        int st = intervals[0][0], ed = intervals[0][1];
        var ans = new List<int[]>();
        for (int i = 1; i < intervals.Length; ++i) {
            if (ed < intervals[i][0]) {
                ans.Add(new int[] { st, ed });
                st = intervals[i][0];
                ed = intervals[i][1];
            } else {
                ed = Math.Max(ed, intervals[i][1]);
            }
        }
        ans.Add(new int[] { st, ed });
        return ans.ToArray();
    }
}
```

### JavaScript

```js
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    intervals.sort((a, b) => a[0] - b[0]);
    const result = [];
    const n = intervals.length;
    let i = 0;
    while (i < n) {
        const left = intervals[i][0];
        let right = intervals[i][1];
        while (true) {
            i++;
            if (i < n && right >= intervals[i][0]) {
                right = Math.max(right, intervals[i][1]);
            } else {
                result.push([left, right]);
                break;
            }
        }
    }
    return result;
};
```

#### Kotlin

```kotlin
class Solution {
    fun merge(intervals: Array<IntArray>): Array<IntArray> {
        intervals.sortBy { it[0] }
        val result = mutableListOf<IntArray>()
        val n = intervals.size
        var i = 0
        while (i < n) {
            val left = intervals[i][0]
            var right = intervals[i][1]
            while (true) {
                i++
                if (i < n && right >= intervals[i][0]) {
                    right = maxOf(right, intervals[i][1])
                } else {
                    result.add(intArrayOf(left, right))
                    break
                }
            }
        }
        return result.toTypedArray()
    }
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
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = [intervals[0]]
        for s, e in intervals[1:]:
            if ans[-1][1] < s:
                ans.append([s, e])
            else:
                ans[-1][1] = max(ans[-1][1], e)
        return ans
```

#### Java

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ans.get(ans.size() - 1)[1] < s) {
                ans.add(intervals[i]);
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], e);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func merge(intervals [][]int) (ans [][]int) {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	ans = append(ans, intervals[0])
	for _, e := range intervals[1:] {
		if ans[len(ans)-1][1] < e[0] {
			ans = append(ans, e)
		} else {
			ans[len(ans)-1][1] = max(ans[len(ans)-1][1], e[1])
		}
	}
	return
}
```

#### TypeScript

```ts
function merge(intervals: number[][]): number[][] {
    intervals.sort((a, b) => a[0] - b[0]);
    const ans: number[][] = [intervals[0]];
    for (let i = 1; i < intervals.length; ++i) {
        if (ans.at(-1)[1] < intervals[i][0]) {
            ans.push(intervals[i]);
        } else {
            ans.at(-1)[1] = Math.max(ans.at(-1)[1], intervals[i][1]);
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int[][] Merge(int[][] intervals) {
        intervals = intervals.OrderBy(a => a[0]).ToArray();
        var ans = new List<int[]>();
        ans.Add(intervals[0]);
        for (int i = 1; i < intervals.Length; ++i) {
            if (ans[ans.Count - 1][1] < intervals[i][0]) {
                ans.Add(intervals[i]);
            } else {
                ans[ans.Count - 1][1] = Math.Max(ans[ans.Count - 1][1], intervals[i][1]);
            }
        }
        return ans.ToArray();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### TypeScript

```ts
function merge(intervals: number[][]): number[][] {
    intervals.sort((a, b) => a[0] - b[0]);
    const n = intervals.length;
    const res = [];
    let i = 0;
    while (i < n) {
        let [l, r] = intervals[i];
        i++;
        while (i < n && r >= intervals[i][0]) {
            r = Math.max(r, intervals[i][1]);
            i++;
        }
        res.push([l, r]);
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [57. 插入区间](https://leetcode.cn/problems/insert-interval){#57}

{{< tabs "57" >}}

{{% tab "python" %}}
```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        st, ed = newInterval
        ans = []
        insert = False
        for s, e in intervals:
            if ed < s:
                if not insert:
                    ans.append([st, ed])
                    insert = True
                ans.append([s, e])
            elif e < st:
                ans.append([s, e])
            else:
                st = min(st, s)
                ed = max(ed, e)
        if not insert:
            ans.append([st, ed])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int st = newInterval[0], ed = newInterval[1];
        boolean insert = false;
        for (int[] interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.add(new int[] {st, ed});
                    insert = true;
                }
                ans.add(interval);
            } else if (e < st) {
                ans.add(interval);
            } else {
                st = Math.min(st, s);
                ed = Math.max(ed, e);
            }
        }
        if (!insert) {
            ans.add(new int[] {st, ed});
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        for (auto& interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.push_back({st, ed});
                    insert = true;
                }
                ans.push_back(interval);
            } else if (e < st) {
                ans.push_back(interval);
            } else {
                st = min(st, s);
                ed = max(ed, e);
            }
        }
        if (!insert) {
            ans.push_back({st, ed});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func insert(intervals [][]int, newInterval []int) (ans [][]int) {
	st, ed := newInterval[0], newInterval[1]
	insert := false
	for _, interval := range intervals {
		s, e := interval[0], interval[1]
		if ed < s {
			if !insert {
				ans = append(ans, []int{st, ed})
				insert = true
			}
			ans = append(ans, interval)
		} else if e < st {
			ans = append(ans, interval)
		} else {
			st = min(st, s)
			ed = max(ed, e)
		}
	}
	if !insert {
		ans = append(ans, []int{st, ed})
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function insert(intervals: number[][], newInterval: number[]): number[][] {
    let [st, ed] = newInterval;
    const ans: number[][] = [];
    let insert = false;
    for (const [s, e] of intervals) {
        if (ed < s) {
            if (!insert) {
                ans.push([st, ed]);
                insert = true;
            }
            ans.push([s, e]);
        } else if (e < st) {
            ans.push([s, e]);
        } else {
            st = Math.min(st, s);
            ed = Math.max(ed, e);
        }
    }
    if (!insert) {
        ans.push([st, ed]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut inserted = false;
        let mut result = vec![];

        let (mut start, mut end) = (new_interval[0], new_interval[1]);
        for iter in intervals.iter() {
            let (cur_st, cur_ed) = (iter[0], iter[1]);
            if cur_ed < start {
                result.push(vec![cur_st, cur_ed]);
            } else if cur_st > end {
                if !inserted {
                    inserted = true;
                    result.push(vec![start, end]);
                }
                result.push(vec![cur_st, cur_ed]);
            } else {
                start = std::cmp::min(start, cur_st);
                end = std::cmp::max(end, cur_ed);
            }
        }

        if !inserted {
            result.push(vec![start, end]);
        }
        result
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        var ans = new List<int[]>();
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        foreach (var interval in intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.Add(new int[]{st, ed});
                    insert = true;
                }
                ans.Add(interval);
            } else if (st > e) {
                ans.Add(interval);
            } else {
                st = Math.Min(st, s);
                ed = Math.Max(ed, e);
            }
        }
        if (!insert) {
            ans.Add(new int[]{st, ed});
        }
        return ans.ToArray();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个<strong> 无重叠的</strong><em> ，</em>按照区间起始端点排序的区间列表 <code>intervals</code>，其中&nbsp;<code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个区间的开始和结束，并且&nbsp;<code>intervals</code>&nbsp;按照&nbsp;<code>start<sub>i</sub></code>&nbsp;升序排列。同样给定一个区间&nbsp;<code>newInterval = [start, end]</code>&nbsp;表示另一个区间的开始和结束。</p>

<p>在&nbsp;<code>intervals</code> 中插入区间&nbsp;<code>newInterval</code>，使得&nbsp;<code>intervals</code>&nbsp;依然按照&nbsp;<code>start<sub>i</sub></code>&nbsp;升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。</p>

<p>返回插入之后的&nbsp;<code>intervals</code>。</p>

<p><strong>注意</strong> 你不需要原地修改&nbsp;<code>intervals</code>。你可以创建一个新数组然后返回它。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,3],[6,9]], newInterval = [2,5]
<strong>输出：</strong>[[1,5],[6,9]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
<strong>输出：</strong>[[1,2],[3,10],[12,16]]
<strong>解释：</strong>这是因为新的区间 <code>[4,8]</code> 与 <code>[3,5],[6,7],[8,10]</code>&nbsp;重叠。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;=&nbsp;start<sub>i</sub> &lt;=&nbsp;end<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals</code> 根据 <code>start<sub>i</sub></code> 按 <strong>升序</strong> 排列</li>
	<li><code>newInterval.length == 2</code></li>
	<li><code>0 &lt;=&nbsp;start &lt;=&nbsp;end &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 区间合并

我们可以先将新区间 `newInterval` 加入到区间列表 `intervals` 中，然后按照区间合并的常规方法进行合并。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是区间的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        def merge(intervals: List[List[int]]) -> List[List[int]]:
            intervals.sort()
            ans = [intervals[0]]
            for s, e in intervals[1:]:
                if ans[-1][1] < s:
                    ans.append([s, e])
                else:
                    ans[-1][1] = max(ans[-1][1], e)
            return ans

        intervals.append(newInterval)
        return merge(intervals)
```

#### Java

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[][] newIntervals = new int[intervals.length + 1][2];
        for (int i = 0; i < intervals.length; ++i) {
            newIntervals[i] = intervals[i];
        }
        newIntervals[intervals.length] = newInterval;
        return merge(newIntervals);
    }

    private int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ans.get(ans.size() - 1)[1] < s) {
                ans.add(intervals[i]);
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], e);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func insert(intervals [][]int, newInterval []int) [][]int {
	merge := func(intervals [][]int) (ans [][]int) {
		sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
		ans = append(ans, intervals[0])
		for _, e := range intervals[1:] {
			if ans[len(ans)-1][1] < e[0] {
				ans = append(ans, e)
			} else {
				ans[len(ans)-1][1] = max(ans[len(ans)-1][1], e[1])
			}
		}
		return
	}
	intervals = append(intervals, newInterval)
	return merge(intervals)
}
```

#### TypeScript

```ts
function insert(intervals: number[][], newInterval: number[]): number[][] {
    const merge = (intervals: number[][]): number[][] => {
        intervals.sort((a, b) => a[0] - b[0]);
        const ans: number[][] = [intervals[0]];
        for (let i = 1; i < intervals.length; ++i) {
            if (ans.at(-1)[1] < intervals[i][0]) {
                ans.push(intervals[i]);
            } else {
                ans.at(-1)[1] = Math.max(ans.at(-1)[1], intervals[i][1]);
            }
        }
        return ans;
    };

    intervals.push(newInterval);
    return merge(intervals);
}
```

#### Rust

```rust
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut merged_intervals = intervals.clone();
        merged_intervals.push(vec![new_interval[0], new_interval[1]]);
        // sort by elem[0]
        merged_intervals.sort_by_key(|elem| elem[0]);
        // merge interval
        let mut result = vec![];

        for interval in merged_intervals {
            if result.is_empty() {
                result.push(interval);
                continue;
            }

            let last_elem = result.last_mut().unwrap();
            if interval[0] > last_elem[1] {
                result.push(interval);
            } else {
                last_elem[1] = last_elem[1].max(interval[1]);
            }
        }
        result
    }
}
```

#### C#

```cs
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        int[][] newIntervals = new int[intervals.Length + 1][];
        for (int i = 0; i < intervals.Length; ++i) {
            newIntervals[i] = intervals[i];
        }
        newIntervals[intervals.Length] = newInterval;
        return Merge(newIntervals);
    }

    public int[][] Merge(int[][] intervals) {
        intervals = intervals.OrderBy(a => a[0]).ToArray();
        var ans = new List<int[]>();
        ans.Add(intervals[0]);
        for (int i = 1; i < intervals.Length; ++i) {
            if (ans[ans.Count - 1][1] < intervals[i][0]) {
                ans.Add(intervals[i]);
            } else {
                ans[ans.Count - 1][1] = Math.Max(ans[ans.Count - 1][1], intervals[i][1]);
            }
        }
        return ans.ToArray();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：一次遍历

我们可以遍历区间列表 `intervals`，记当前区间为 `interval`，对于每个区间有三种情况：

-   当前区间在新区间的右侧，即 $newInterval[1] \lt interval[0]$，此时如果新区间还没有被加入，那么将新区间加入到答案中，然后将当前区间加入到答案中。
-   当前区间在新区间的左侧，即 $interval[1] \lt newInterval[0]$，此时将当前区间加入到答案中。
-   否则，说明当前区间与新区间有交集，我们取当前区间的左端点和新区间的左端点的最小值，以及当前区间的右端点和新区间的右端点的最大值，作为新区间的左右端点，然后继续遍历区间列表。

遍历结束，如果新区间还没有被加入，那么将新区间加入到答案中。

时间复杂度 $O(n)$，其中 $n$ 是区间的数量。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        st, ed = newInterval
        ans = []
        insert = False
        for s, e in intervals:
            if ed < s:
                if not insert:
                    ans.append([st, ed])
                    insert = True
                ans.append([s, e])
            elif e < st:
                ans.append([s, e])
            else:
                st = min(st, s)
                ed = max(ed, e)
        if not insert:
            ans.append([st, ed])
        return ans
```

#### Java

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int st = newInterval[0], ed = newInterval[1];
        boolean insert = false;
        for (int[] interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.add(new int[] {st, ed});
                    insert = true;
                }
                ans.add(interval);
            } else if (e < st) {
                ans.add(interval);
            } else {
                st = Math.min(st, s);
                ed = Math.max(ed, e);
            }
        }
        if (!insert) {
            ans.add(new int[] {st, ed});
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        for (auto& interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.push_back({st, ed});
                    insert = true;
                }
                ans.push_back(interval);
            } else if (e < st) {
                ans.push_back(interval);
            } else {
                st = min(st, s);
                ed = max(ed, e);
            }
        }
        if (!insert) {
            ans.push_back({st, ed});
        }
        return ans;
    }
};
```

#### Go

```go
func insert(intervals [][]int, newInterval []int) (ans [][]int) {
	st, ed := newInterval[0], newInterval[1]
	insert := false
	for _, interval := range intervals {
		s, e := interval[0], interval[1]
		if ed < s {
			if !insert {
				ans = append(ans, []int{st, ed})
				insert = true
			}
			ans = append(ans, interval)
		} else if e < st {
			ans = append(ans, interval)
		} else {
			st = min(st, s)
			ed = max(ed, e)
		}
	}
	if !insert {
		ans = append(ans, []int{st, ed})
	}
	return
}
```

#### TypeScript

```ts
function insert(intervals: number[][], newInterval: number[]): number[][] {
    let [st, ed] = newInterval;
    const ans: number[][] = [];
    let insert = false;
    for (const [s, e] of intervals) {
        if (ed < s) {
            if (!insert) {
                ans.push([st, ed]);
                insert = true;
            }
            ans.push([s, e]);
        } else if (e < st) {
            ans.push([s, e]);
        } else {
            st = Math.min(st, s);
            ed = Math.max(ed, e);
        }
    }
    if (!insert) {
        ans.push([st, ed]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut inserted = false;
        let mut result = vec![];

        let (mut start, mut end) = (new_interval[0], new_interval[1]);
        for iter in intervals.iter() {
            let (cur_st, cur_ed) = (iter[0], iter[1]);
            if cur_ed < start {
                result.push(vec![cur_st, cur_ed]);
            } else if cur_st > end {
                if !inserted {
                    inserted = true;
                    result.push(vec![start, end]);
                }
                result.push(vec![cur_st, cur_ed]);
            } else {
                start = std::cmp::min(start, cur_st);
                end = std::cmp::max(end, cur_ed);
            }
        }

        if !inserted {
            result.push(vec![start, end]);
        }
        result
    }
}
```

#### C#

```cs
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        var ans = new List<int[]>();
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        foreach (var interval in intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.Add(new int[]{st, ed});
                    insert = true;
                }
                ans.Add(interval);
            } else if (st > e) {
                ans.Add(interval);
            } else {
                st = Math.Min(st, s);
                ed = Math.Max(ed, e);
            }
        }
        if (!insert) {
            ans.Add(new int[]{st, ed});
        }
        return ans.ToArray();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [58. 最后一个单词的长度](https://leetcode.cn/problems/length-of-last-word){#58}

{{< tabs "58" >}}

{{% tab "python" %}}
```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i -= 1
        j = i
        while j >= 0 and s[j] != ' ':
            j -= 1
        return i - j
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s.charAt(j) != ' ') {
            --j;
        }
        return i - j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (~i && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (~j && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lengthOfLastWord(s string) int {
	i := len(s) - 1
	for i >= 0 && s[i] == ' ' {
		i--
	}
	j := i
	for j >= 0 && s[j] != ' ' {
		j--
	}
	return i - j
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lengthOfLastWord(s: string): number {
    let i = s.length - 1;
    while (i >= 0 && s[i] === ' ') {
        --i;
    }
    let j = i;
    while (j >= 0 && s[j] !== ' ') {
        --j;
    }
    return i - j;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let s = s.trim_end();
        let n = s.len();
        for (i, c) in s.char_indices().rev() {
            if c == ' ' {
                return (n - i - 1) as i32;
            }
        }
        n as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let i = s.length - 1;
    while (i >= 0 && s[i] === ' ') {
        --i;
    }
    let j = i;
    while (j >= 0 && s[j] !== ' ') {
        --j;
    }
    return i - j;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LengthOfLastWord(string s) {
        int i = s.Length - 1;
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
        $count = 0;
        while ($s[strlen($s) - 1] == ' ') {
            $s = substr($s, 0, -1);
        }
        while (strlen($s) != 0 && $s[strlen($s) - 1] != ' ') {
            $count++;
            $s = substr($s, 0, -1);
        }
        return $count;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 <strong>最后一个</strong> 单词的长度。</p>

<p><strong>单词</strong> 是指仅由字母组成、不包含任何空格字符的最大<span data-keyword="substring-nonempty">子字符串</span>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "Hello World"
<strong>输出：</strong>5
<strong>解释：</strong>最后一个单词是“World”，长度为 5。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "   fly me   to   the moon  "
<strong>输出：</strong>4<strong>
解释：</strong>最后一个单词是“moon”，长度为 4。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "luffy is still joyboy"
<strong>输出：</strong>6
<strong>解释：</strong>最后一个单词是长度为 6 的“joyboy”。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅有英文字母和空格 <code>' '</code> 组成</li>
	<li><code>s</code> 中至少存在一个单词</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向遍历 + 双指针

我们从字符串 $s$ 末尾开始遍历，找到第一个不为空格的字符，即为最后一个单词的最后一个字符，下标记为 $i$。然后继续向前遍历，找到第一个为空格的字符，即为最后一个单词的第一个字符的前一个字符，记为 $j$。那么最后一个单词的长度即为 $i - j$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i -= 1
        j = i
        while j >= 0 and s[j] != ' ':
            j -= 1
        return i - j
```

#### Java

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s.charAt(j) != ' ') {
            --j;
        }
        return i - j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (~i && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (~j && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
};
```

#### Go

```go
func lengthOfLastWord(s string) int {
	i := len(s) - 1
	for i >= 0 && s[i] == ' ' {
		i--
	}
	j := i
	for j >= 0 && s[j] != ' ' {
		j--
	}
	return i - j
}
```

#### TypeScript

```ts
function lengthOfLastWord(s: string): number {
    let i = s.length - 1;
    while (i >= 0 && s[i] === ' ') {
        --i;
    }
    let j = i;
    while (j >= 0 && s[j] !== ' ') {
        --j;
    }
    return i - j;
}
```

#### Rust

```rust
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let s = s.trim_end();
        let n = s.len();
        for (i, c) in s.char_indices().rev() {
            if c == ' ' {
                return (n - i - 1) as i32;
            }
        }
        n as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let i = s.length - 1;
    while (i >= 0 && s[i] === ' ') {
        --i;
    }
    let j = i;
    while (j >= 0 && s[j] !== ' ') {
        --j;
    }
    return i - j;
};
```

#### C#

```cs
public class Solution {
    public int LengthOfLastWord(string s) {
        int i = s.Length - 1;
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
        $count = 0;
        while ($s[strlen($s) - 1] == ' ') {
            $s = substr($s, 0, -1);
        }
        while (strlen($s) != 0 && $s[strlen($s) - 1] != ' ') {
            $count++;
            $s = substr($s, 0, -1);
        }
        return $count;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [59. 螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii){#59}

{{< tabs "59" >}}

{{% tab "python" %}}
```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        for v in range(1, n * n + 1):
            ans[i][j] = v
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= n or y < 0 or y >= n or ans[x][y]:
                k = (k + 1) % 4
            i, j = i + dirs[k], j + dirs[k + 1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        final int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        const int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func generateMatrix(n int) [][]int {
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	dirs := [5]int{0, 1, 0, -1, 0}
	i, j, k := 0, 0, 0
	for v := 1; v <= n*n; v++ {
		ans[i][j] = v
		x, y := i+dirs[k], j+dirs[k+1]
		if x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0 {
			k = (k + 1) % 4
		}
		i += dirs[k]
		j += dirs[k+1]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function generateMatrix(n: number): number[][] {
    const ans: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const dirs = [0, 1, 0, -1, 0];
    let [i, j, k] = [0, 0, 0];
    for (let v = 1; v <= n * n; v++) {
        ans[i][j] = v;
        const [x, y] = [i + dirs[k], j + dirs[k + 1]];
        if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] !== 0) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut ans = vec![vec![0; n as usize]; n as usize];
        let dirs = [0, 1, 0, -1, 0];
        let (mut i, mut j, mut k) = (0, 0, 0);
        for v in 1..=n * n {
            ans[i as usize][j as usize] = v;
            let (x, y) = (i + dirs[k], j + dirs[k + 1]);
            if x < 0 || x >= n || y < 0 || y >= n || ans[x as usize][y as usize] != 0 {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function (n) {
    const ans = Array.from({ length: n }, () => Array(n).fill(0));
    const dirs = [0, 1, 0, -1, 0];
    let [i, j, k] = [0, 0, 0];
    for (let v = 1; v <= n * n; v++) {
        ans[i][j] = v;
        const [x, y] = [i + dirs[k], j + dirs[k + 1]];
        if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] !== 0) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> ，生成一个包含 <code>1</code> 到 <code>n<sup>2</sup></code> 所有元素，且元素按顺时针顺序螺旋排列的 <code>n x n</code> 正方形矩阵 <code>matrix</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0059.Spiral%20Matrix%20II/images/spiraln.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>[[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>[[1]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟螺旋矩阵的生成过程。

定义一个二维数组 $\textit{ans}$，用于存储螺旋矩阵。用 $i$ 和 $j$ 分别表示当前位置的行号和列号，用 $k$ 表示当前的方向编号，$\textit{dirs}$ 表示方向编号与方向的对应关系。

从 $1$ 开始，依次填入矩阵中的每个位置。每次填入一个位置后，计算下一个位置的行号和列号，如果下一个位置不在矩阵中或者已经被填过，则改变方向，再计算下一个位置的行号和列号。

时间复杂度 $O(n^2)$，其中 $n$ 是矩阵的边长。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        dirs = (0, 1, 0, -1, 0)
        i = j = k = 0
        for v in range(1, n * n + 1):
            ans[i][j] = v
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or x >= n or y < 0 or y >= n or ans[x][y]:
                k = (k + 1) % 4
            i, j = i + dirs[k], j + dirs[k + 1]
        return ans
```

#### Java

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        final int[] dirs = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        const int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        for (int v = 1; v <= n * n; ++v) {
            ans[i][j] = v;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
};
```

#### Go

```go
func generateMatrix(n int) [][]int {
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	dirs := [5]int{0, 1, 0, -1, 0}
	i, j, k := 0, 0, 0
	for v := 1; v <= n*n; v++ {
		ans[i][j] = v
		x, y := i+dirs[k], j+dirs[k+1]
		if x < 0 || x >= n || y < 0 || y >= n || ans[x][y] != 0 {
			k = (k + 1) % 4
		}
		i += dirs[k]
		j += dirs[k+1]
	}
	return ans
}
```

#### TypeScript

```ts
function generateMatrix(n: number): number[][] {
    const ans: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const dirs = [0, 1, 0, -1, 0];
    let [i, j, k] = [0, 0, 0];
    for (let v = 1; v <= n * n; v++) {
        ans[i][j] = v;
        const [x, y] = [i + dirs[k], j + dirs[k + 1]];
        if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] !== 0) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut ans = vec![vec![0; n as usize]; n as usize];
        let dirs = [0, 1, 0, -1, 0];
        let (mut i, mut j, mut k) = (0, 0, 0);
        for v in 1..=n * n {
            ans[i as usize][j as usize] = v;
            let (x, y) = (i + dirs[k], j + dirs[k + 1]);
            if x < 0 || x >= n || y < 0 || y >= n || ans[x as usize][y as usize] != 0 {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function (n) {
    const ans = Array.from({ length: n }, () => Array(n).fill(0));
    const dirs = [0, 1, 0, -1, 0];
    let [i, j, k] = [0, 0, 0];
    for (let v = 1; v <= n * n; v++) {
        ans[i][j] = v;
        const [x, y] = [i + dirs[k], j + dirs[k + 1]];
        if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y] !== 0) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [60. 排列序列](https://leetcode.cn/problems/permutation-sequence){#60}

{{< tabs "60" >}}

{{% tab "python" %}}
```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []
        vis = [False] * (n + 1)
        for i in range(n):
            fact = 1
            for j in range(1, n - i):
                fact *= j
            for j in range(1, n + 1):
                if not vis[j]:
                    if k > fact:
                        k -= fact
                    else:
                        ans.append(str(j))
                        vis[j] = True
                        break
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder ans = new StringBuilder();
        boolean[] vis = new boolean[n + 1];
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) {
                fact *= j;
            }
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) {
                    if (k > fact) {
                        k -= fact;
                    } else {
                        ans.append(j);
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        bitset<10> vis;
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) fact *= j;
            for (int j = 1; j <= n; ++j) {
                if (vis[j]) continue;
                if (k > fact)
                    k -= fact;
                else {
                    ans += to_string(j);
                    vis[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getPermutation(n int, k int) string {
	ans := make([]byte, n)
	vis := make([]bool, n+1)
	for i := 0; i < n; i++ {
		fact := 1
		for j := 1; j < n-i; j++ {
			fact *= j
		}
		for j := 1; j <= n; j++ {
			if !vis[j] {
				if k > fact {
					k -= fact
				} else {
					ans[i] = byte('0' + j)
					vis[j] = true
					break
				}
			}
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut k = k;
        let mut ans = String::new();
        let mut fact = vec![1; n as usize];
        for i in 1..n as usize {
            fact[i] = fact[i - 1] * (i as i32);
        }
        let mut vis = vec![false; n as usize + 1];

        for i in 0..n as usize {
            let cnt = fact[(n as usize) - i - 1];
            for j in 1..=n {
                if vis[j as usize] {
                    continue;
                }
                if k > cnt {
                    k -= cnt;
                } else {
                    ans.push_str(&j.to_string());
                    vis[j as usize] = true;
                    break;
                }
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string GetPermutation(int n, int k) {
        var ans = new StringBuilder();
        int vis = 0;
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) {
                fact *= j;
            }
            for (int j = 1; j <= n; ++j) {
                if (((vis >> j) & 1) == 0) {
                    if (k > fact) {
                        k -= fact;
                    } else {
                        ans.Append(j);
                        vis |= 1 << j;
                        break;
                    }
                }
            }
        }
        return ans.ToString();
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getPermutation(n: number, k: number): string {
    let ans = '';
    const vis = Array.from({ length: n + 1 }, () => false);
    for (let i = 0; i < n; i++) {
        let fact = 1;
        for (let j = 1; j < n - i; j++) {
            fact *= j;
        }
        for (let j = 1; j <= n; j++) {
            if (!vis[j]) {
                if (k > fact) {
                    k -= fact;
                } else {
                    ans += j;
                    vis[j] = true;
                    break;
                }
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

<p>给出集合 <code>[1,2,3,...,n]</code>，其所有元素共有 <code>n!</code> 种排列。</p>

<p>按大小顺序列出所有排列情况，并一一标记，当 <code>n = 3</code> 时, 所有排列如下：</p>

<ol>
	<li><code>"123"</code></li>
	<li><code>"132"</code></li>
	<li><code>"213"</code></li>
	<li><code>"231"</code></li>
	<li><code>"312"</code></li>
	<li><code>"321"</code></li>
</ol>

<p>给定 <code>n</code> 和 <code>k</code>，返回第 <code>k</code> 个排列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 3
<strong>输出：</strong>"213"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 9
<strong>输出：</strong>"2314"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>"123"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 9</code></li>
	<li><code>1 <= k <= n!</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们知道，集合 $[1,2,..n]$ 一共有 $n!$ 种排列，如果我们确定首位，那剩余位能组成的排列数量为 $(n-1)!$。

因此，我们枚举每一位 $i$，如果此时 $k$ 大于当前位置确定后的排列数量，那么我们可以直接减去这个数量；否则，说明我们找到了当前位置的数。

对于每一位 $i$，其中 $0 \leq i \lt n$，剩余位能组成的排列数量为 $(n-i-1)!$，我们记为 $fact$。过程中已使用的数记录在 `vis` 中。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []
        vis = [False] * (n + 1)
        for i in range(n):
            fact = 1
            for j in range(1, n - i):
                fact *= j
            for j in range(1, n + 1):
                if not vis[j]:
                    if k > fact:
                        k -= fact
                    else:
                        ans.append(str(j))
                        vis[j] = True
                        break
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder ans = new StringBuilder();
        boolean[] vis = new boolean[n + 1];
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) {
                fact *= j;
            }
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) {
                    if (k > fact) {
                        k -= fact;
                    } else {
                        ans.append(j);
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        bitset<10> vis;
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) fact *= j;
            for (int j = 1; j <= n; ++j) {
                if (vis[j]) continue;
                if (k > fact)
                    k -= fact;
                else {
                    ans += to_string(j);
                    vis[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getPermutation(n int, k int) string {
	ans := make([]byte, n)
	vis := make([]bool, n+1)
	for i := 0; i < n; i++ {
		fact := 1
		for j := 1; j < n-i; j++ {
			fact *= j
		}
		for j := 1; j <= n; j++ {
			if !vis[j] {
				if k > fact {
					k -= fact
				} else {
					ans[i] = byte('0' + j)
					vis[j] = true
					break
				}
			}
		}
	}
	return string(ans)
}
```

#### Rust

```rust
impl Solution {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut k = k;
        let mut ans = String::new();
        let mut fact = vec![1; n as usize];
        for i in 1..n as usize {
            fact[i] = fact[i - 1] * (i as i32);
        }
        let mut vis = vec![false; n as usize + 1];

        for i in 0..n as usize {
            let cnt = fact[(n as usize) - i - 1];
            for j in 1..=n {
                if vis[j as usize] {
                    continue;
                }
                if k > cnt {
                    k -= cnt;
                } else {
                    ans.push_str(&j.to_string());
                    vis[j as usize] = true;
                    break;
                }
            }
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public string GetPermutation(int n, int k) {
        var ans = new StringBuilder();
        int vis = 0;
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) {
                fact *= j;
            }
            for (int j = 1; j <= n; ++j) {
                if (((vis >> j) & 1) == 0) {
                    if (k > fact) {
                        k -= fact;
                    } else {
                        ans.Append(j);
                        vis |= 1 << j;
                        break;
                    }
                }
            }
        }
        return ans.ToString();
    }
}
```

#### TypeScript

```ts
function getPermutation(n: number, k: number): string {
    let ans = '';
    const vis = Array.from({ length: n + 1 }, () => false);
    for (let i = 0; i < n; i++) {
        let fact = 1;
        for (let j = 1; j < n - i; j++) {
            fact *= j;
        }
        for (let j = 1; j <= n; j++) {
            if (!vis[j]) {
                if (k > fact) {
                    k -= fact;
                } else {
                    ans += j;
                    vis[j] = true;
                    break;
                }
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
