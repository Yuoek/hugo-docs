---
title: "2660_保龄球游戏的获胜者"
date: 2025-10-08T18:39:28+08:00
weight: 7
tags: [JavaScript, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 数据库, 数组, 最短路, 模拟, 矩阵, 贪心]
---

{{< markmap >}}
### [2660_保龄球游戏的获胜者](#2660)
#### [数组](#2660)
#### [模拟](#2660)
### [2661_找出叠涂元素](#2661)
#### [数组](#2661)
#### [哈希表](#2661)
#### [矩阵](#2661)
### [2662_前往目标的最小代价](#2662)
#### [图](#2662)
#### [数组](#2662)
#### [最短路](#2662)
#### [堆（优先队列）](#2662)
### [2663_字典序最小的美丽字符串](#2663)
#### [贪心](#2663)
#### [字符串](#2663)
### [2664_巡逻的骑士 🔒](#2664)
#### [数组](#2664)
#### [回溯](#2664)
#### [矩阵](#2664)
### [2665_计数器 II](#2665)
#### [JavaScript](#2665)
### [2666_只允许一次函数调用](#2666)
#### [JavaScript](#2666)
### [2667_创建 Hello World 函数](#2667)
#### [JavaScript](#2667)
### [2668_查询员工当前薪水 🔒](#2668)
#### [数据库](#2668)
### [2669_统计 Spotify 排行榜上艺术家出现次数 🔒](#2669)
#### [数据库](#2669)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2660_保龄球游戏的获胜者
___
#### 数组
___
#### 模拟
---
### 2661_找出叠涂元素
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 2662_前往目标的最小代价
___
#### 图
___
#### 数组
___
#### 最短路
___
#### 堆（优先队列）
---
### 2663_字典序最小的美丽字符串
___
#### 贪心
___
#### 字符串
---
### 2664_巡逻的骑士 🔒
___
#### 数组
___
#### 回溯
___
#### 矩阵
---
### 2665_计数器 II
___
#### JavaScript
---
### 2666_只允许一次函数调用
___
#### JavaScript
---
### 2667_创建 Hello World 函数
___
#### JavaScript
---
### 2668_查询员工当前薪水 🔒
___
#### 数据库
---
### 2669_统计 Spotify 排行榜上艺术家出现次数 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 哈希表 | 回溯 |
| 图 | 堆（优先队列） | 字符串 |
| 数据库 | 数组 | 最短路 |
| 模拟 | 矩阵 | 贪心 |

# [2660. 保龄球游戏的获胜者](https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game){#2660}

{{< tabs "2660" >}}

{{% tab "python" %}}
```python
class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        def f(arr: List[int]) -> int:
            s = 0
            for i, x in enumerate(arr):
                k = 2 if (i and arr[i - 1] == 10) or (i > 1 and arr[i - 2] == 10) else 1
                s += k * x
            return s

        a, b = f(player1), f(player2)
        return 1 if a > b else (2 if b > a else 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int isWinner(int[] player1, int[] player2) {
        int a = f(player1), b = f(player2);
        return a > b ? 1 : b > a ? 2 : 0;
    }

    private int f(int[] arr) {
        int s = 0;
        for (int i = 0; i < arr.length; ++i) {
            int k = (i > 0 && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10) ? 2 : 1;
            s += k * arr[i];
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        auto f = [](vector<int>& arr) {
            int s = 0;
            for (int i = 0, n = arr.size(); i < n; ++i) {
                int k = (i && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10) ? 2 : 1;
                s += k * arr[i];
            }
            return s;
        };
        int a = f(player1), b = f(player2);
        return a > b ? 1 : (b > a ? 2 : 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isWinner(player1 []int, player2 []int) int {
	f := func(arr []int) int {
		s := 0
		for i, x := range arr {
			k := 1
			if (i > 0 && arr[i-1] == 10) || (i > 1 && arr[i-2] == 10) {
				k = 2
			}
			s += k * x
		}
		return s
	}
	a, b := f(player1), f(player2)
	if a > b {
		return 1
	}
	if b > a {
		return 2
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isWinner(player1: number[], player2: number[]): number {
    const f = (arr: number[]): number => {
        let s = 0;
        for (let i = 0; i < arr.length; ++i) {
            s += arr[i];
            if ((i && arr[i - 1] === 10) || (i > 1 && arr[i - 2] === 10)) {
                s += arr[i];
            }
        }
        return s;
    };
    const a = f(player1);
    const b = f(player2);
    return a > b ? 1 : a < b ? 2 : 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_winner(player1: Vec<i32>, player2: Vec<i32>) -> i32 {
        let f = |arr: &Vec<i32>| -> i32 {
            let mut s = 0;
            for i in 0..arr.len() {
                let mut k = 1;
                if (i > 0 && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10) {
                    k = 2;
                }
                s += k * arr[i];
            }
            s
        };

        let a = f(&player1);
        let b = f(&player2);
        if a > b {
            1
        } else if a < b {
            2
        } else {
            0
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

<p>给你两个下标从 <strong>0</strong> 开始的整数数组 <code>player1</code> 和 <code>player2</code> ，分别表示玩家 1 和玩家 2 击中的瓶数。</p>

<p>保龄球比赛由 <code>n</code> 轮组成，每轮的瓶数恰好为 <code>10</code> 。</p>

<p>假设玩家在第 <code>i</code> 轮中击中&nbsp;<code>x<sub>i</sub></code> 个瓶子。玩家第 <code>i</code> 轮的价值为：</p>

<ul>
	<li>如果玩家在该轮的前两轮的任何一轮中击中了 <code>10</code> 个瓶子，则为 <code>2x<sub>i</sub></code> 。</li>
	<li>否则，为&nbsp;<code>x<sub>i</sub></code> 。</li>
</ul>

<p>玩家的得分是其 <code>n</code> 轮价值的总和。</p>

<p>返回</p>

<ul>
	<li>如果玩家 1 的得分高于玩家 2 的得分，则为 <code>1</code> ；</li>
	<li>如果玩家 2 的得分高于玩家 1 的得分，则为 <code>2</code> ；</li>
	<li>如果平局，则为 <code>0</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">player1 = [5,10,3,2], player2 = [6,5,7,3]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>玩家 1 的分数为 5 + 10 + 2*3 + 2*2 = 25。</p>

<p>玩家 2&nbsp;的分数为 6 + 5 + 7 + 3 = 21。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">player1 = [3,5,7,6], player2 = [8,10,10,2]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>玩家 1 的分数为 3 + 5 + 7 + 6 = 21。</p>

<p>玩家 2&nbsp;的分数为 8 + 10 + 2*10 + 2*2 = 42。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">player1 = [2,3], player2 = [4,1]</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>玩家 1 的分数为&nbsp;2 + 3 = 5。</p>

<p>玩家 2 的分数为&nbsp;4 + 1 = 5。</p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">player1 = [1,1,1,10,10,10,10], player2 = [10,10,10,10,1,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>玩家 1 的分数为 1 + 1 + 1 + 10 + 2*10 + 2*10 + 2*10 = 73。</p>

<p>玩家 2 的分数为 is 10 + 2*10 + 2*10 + 2*10 + 2*1 + 2*1 + 1 = 75。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == player1.length == player2.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= player1[i], player2[i] &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以用一个函数 $f(arr)$ 计算出两个玩家的得分，分别记为 $a$ 和 $b$，然后根据 $a$ 和 $b$ 的大小关系返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        def f(arr: List[int]) -> int:
            s = 0
            for i, x in enumerate(arr):
                k = 2 if (i and arr[i - 1] == 10) or (i > 1 and arr[i - 2] == 10) else 1
                s += k * x
            return s

        a, b = f(player1), f(player2)
        return 1 if a > b else (2 if b > a else 0)
```

#### Java

```java
class Solution {
    public int isWinner(int[] player1, int[] player2) {
        int a = f(player1), b = f(player2);
        return a > b ? 1 : b > a ? 2 : 0;
    }

    private int f(int[] arr) {
        int s = 0;
        for (int i = 0; i < arr.length; ++i) {
            int k = (i > 0 && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10) ? 2 : 1;
            s += k * arr[i];
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        auto f = [](vector<int>& arr) {
            int s = 0;
            for (int i = 0, n = arr.size(); i < n; ++i) {
                int k = (i && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10) ? 2 : 1;
                s += k * arr[i];
            }
            return s;
        };
        int a = f(player1), b = f(player2);
        return a > b ? 1 : (b > a ? 2 : 0);
    }
};
```

#### Go

```go
func isWinner(player1 []int, player2 []int) int {
	f := func(arr []int) int {
		s := 0
		for i, x := range arr {
			k := 1
			if (i > 0 && arr[i-1] == 10) || (i > 1 && arr[i-2] == 10) {
				k = 2
			}
			s += k * x
		}
		return s
	}
	a, b := f(player1), f(player2)
	if a > b {
		return 1
	}
	if b > a {
		return 2
	}
	return 0
}
```

#### TypeScript

```ts
function isWinner(player1: number[], player2: number[]): number {
    const f = (arr: number[]): number => {
        let s = 0;
        for (let i = 0; i < arr.length; ++i) {
            s += arr[i];
            if ((i && arr[i - 1] === 10) || (i > 1 && arr[i - 2] === 10)) {
                s += arr[i];
            }
        }
        return s;
    };
    const a = f(player1);
    const b = f(player2);
    return a > b ? 1 : a < b ? 2 : 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_winner(player1: Vec<i32>, player2: Vec<i32>) -> i32 {
        let f = |arr: &Vec<i32>| -> i32 {
            let mut s = 0;
            for i in 0..arr.len() {
                let mut k = 1;
                if (i > 0 && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10) {
                    k = 2;
                }
                s += k * arr[i];
            }
            s
        };

        let a = f(&player1);
        let b = f(&player2);
        if a > b {
            1
        } else if a < b {
            2
        } else {
            0
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2661. 找出叠涂元素](https://leetcode.cn/problems/first-completely-painted-row-or-column){#2661}

{{< tabs "2661" >}}

{{% tab "python" %}}
```python
class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        idx = {}
        for i in range(m):
            for j in range(n):
                idx[mat[i][j]] = (i, j)
        row = [0] * m
        col = [0] * n
        for k in range(len(arr)):
            i, j = idx[arr[k]]
            row[i] += 1
            col[j] += 1
            if row[i] == n or col[j] == m:
                return k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, int[]> idx = new HashMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                idx.put(mat[i][j], new int[] {i, j});
            }
        }
        int[] row = new int[m];
        int[] col = new int[n];
        for (int k = 0;; ++k) {
            var x = idx.get(arr[k]);
            int i = x[0], j = x[1];
            ++row[i];
            ++col[j];
            if (row[i] == n || col[j] == m) {
                return k;
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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> idx;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                idx[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(m), col(n);
        for (int k = 0;; ++k) {
            auto [i, j] = idx[arr[k]];
            ++row[i];
            ++col[j];
            if (row[i] == n || col[j] == m) {
                return k;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func firstCompleteIndex(arr []int, mat [][]int) int {
	m, n := len(mat), len(mat[0])
	idx := map[int][2]int{}
	for i := range mat {
		for j := range mat[i] {
			idx[mat[i][j]] = [2]int{i, j}
		}
	}
	row := make([]int, m)
	col := make([]int, n)
	for k := 0; ; k++ {
		x := idx[arr[k]]
		i, j := x[0], x[1]
		row[i]++
		col[j]++
		if row[i] == n || col[j] == m {
			return k
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function firstCompleteIndex(arr: number[], mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const idx: Map<number, number[]> = new Map();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            idx.set(mat[i][j], [i, j]);
        }
    }
    const row: number[] = Array(m).fill(0);
    const col: number[] = Array(n).fill(0);
    for (let k = 0; ; ++k) {
        const [i, j] = idx.get(arr[k])!;
        ++row[i];
        ++col[j];
        if (row[i] === n || col[j] === m) {
            return k;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut idx = HashMap::new();
        for i in 0..m {
            for j in 0..n {
                idx.insert(mat[i][j], [i, j]);
            }
        }

        let mut row = vec![0; m];
        let mut col = vec![0; n];
        for k in 0..arr.len() {
            let x = idx.get(&arr[k]).unwrap();
            let i = x[0];
            let j = x[1];
            row[i] += 1;
            col[j] += 1;
            if row[i] == n || col[j] == m {
                return k as i32;
            }
        }

        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>arr</code> 和一个 <code>m x n</code> 的整数 <strong>矩阵</strong> <code>mat</code> 。<code>arr</code> 和 <code>mat</code> 都包含范围 <code>[1，m * n]</code> 内的 <strong>所有</strong> 整数。</p>

<p>从下标 <code>0</code> 开始遍历 <code>arr</code> 中的每个下标 <code>i</code> ，并将包含整数 <code>arr[i]</code> 的 <code>mat</code> 单元格涂色。</p>

<p>请你找出 <code>arr</code> 中第一个使得&nbsp;<code>mat</code> 的某一行或某一列都被涂色的元素，并返回其下标 <code>i</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="image explanation for example 1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2661.First%20Completely%20Painted%20Row%20or%20Column/images/grid1.jpg" style="width: 321px; height: 81px;" />
<pre>
<strong>输入：</strong>arr = [1,3,4,2], mat = [[1,4],[2,3]]
<strong>输出：</strong>2
<strong>解释：</strong>遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="image explanation for example 2" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2661.First%20Completely%20Painted%20Row%20or%20Column/images/grid2.jpg" style="width: 601px; height: 121px;" />
<pre>
<strong>输入：</strong>arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
<strong>输出：</strong>3
<strong>解释：</strong>遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n = mat[i].length</code></li>
	<li><code>arr.length == m * n</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], mat[r][c] &lt;= m * n</code></li>
	<li><code>arr</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>mat</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 数组计数

我们用一个哈希表 $idx$ 记录每个元素在矩阵 $mat$ 中的位置，即 $idx[mat[i][j]] = (i, j)$，定义两个数组 $row$ 和 $col$ 分别记录每行和每列已经涂色的元素个数。

遍历数组 $arr$，对于每个元素 $arr[k]$，我们找到其在矩阵 $mat$ 中的位置 $(i, j)$，然后将 $row[i]$ 和 $col[j]$ 分别加一，如果 $row[i] = n$ 或 $col[j] = m$，说明第 $i$ 行或第 $j$ 列已经被涂色，那么 $arr[k]$ 就是我们要找的元素，返回 $k$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵 $mat$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        idx = {}
        for i in range(m):
            for j in range(n):
                idx[mat[i][j]] = (i, j)
        row = [0] * m
        col = [0] * n
        for k in range(len(arr)):
            i, j = idx[arr[k]]
            row[i] += 1
            col[j] += 1
            if row[i] == n or col[j] == m:
                return k
```

#### Java

```java
class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Map<Integer, int[]> idx = new HashMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                idx.put(mat[i][j], new int[] {i, j});
            }
        }
        int[] row = new int[m];
        int[] col = new int[n];
        for (int k = 0;; ++k) {
            var x = idx.get(arr[k]);
            int i = x[0], j = x[1];
            ++row[i];
            ++col[j];
            if (row[i] == n || col[j] == m) {
                return k;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> idx;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                idx[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(m), col(n);
        for (int k = 0;; ++k) {
            auto [i, j] = idx[arr[k]];
            ++row[i];
            ++col[j];
            if (row[i] == n || col[j] == m) {
                return k;
            }
        }
    }
};
```

#### Go

```go
func firstCompleteIndex(arr []int, mat [][]int) int {
	m, n := len(mat), len(mat[0])
	idx := map[int][2]int{}
	for i := range mat {
		for j := range mat[i] {
			idx[mat[i][j]] = [2]int{i, j}
		}
	}
	row := make([]int, m)
	col := make([]int, n)
	for k := 0; ; k++ {
		x := idx[arr[k]]
		i, j := x[0], x[1]
		row[i]++
		col[j]++
		if row[i] == n || col[j] == m {
			return k
		}
	}
}
```

#### TypeScript

```ts
function firstCompleteIndex(arr: number[], mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const idx: Map<number, number[]> = new Map();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            idx.set(mat[i][j], [i, j]);
        }
    }
    const row: number[] = Array(m).fill(0);
    const col: number[] = Array(n).fill(0);
    for (let k = 0; ; ++k) {
        const [i, j] = idx.get(arr[k])!;
        ++row[i];
        ++col[j];
        if (row[i] === n || col[j] === m) {
            return k;
        }
    }
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut idx = HashMap::new();
        for i in 0..m {
            for j in 0..n {
                idx.insert(mat[i][j], [i, j]);
            }
        }

        let mut row = vec![0; m];
        let mut col = vec![0; n];
        for k in 0..arr.len() {
            let x = idx.get(&arr[k]).unwrap();
            let i = x[0];
            let j = x[1];
            row[i] += 1;
            col[j] += 1;
            if row[i] == n || col[j] == m {
                return k as i32;
            }
        }

        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2662. 前往目标的最小代价](https://leetcode.cn/problems/minimum-cost-of-a-path-with-special-roads){#2662}

{{< tabs "2662" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(
        self, start: List[int], target: List[int], specialRoads: List[List[int]]
    ) -> int:
        def dist(x1: int, y1: int, x2: int, y2: int) -> int:
            return abs(x1 - x2) + abs(y1 - y2)

        q = [(0, start[0], start[1])]
        vis = set()
        ans = inf
        while q:
            d, x, y = heappop(q)
            if (x, y) in vis:
                continue
            vis.add((x, y))
            ans = min(ans, d + dist(x, y, *target))
            for x1, y1, x2, y2, cost in specialRoads:
                heappush(q, (d + dist(x, y, x1, y1) + cost, x2, y2))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCost(int[] start, int[] target, int[][] specialRoads) {
        int ans = 1 << 30;
        int n = 1000000;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        Set<Long> vis = new HashSet<>();
        q.offer(new int[] {0, start[0], start[1]});
        while (!q.isEmpty()) {
            var p = q.poll();
            int x = p[1], y = p[2];
            long k = 1L * x * n + y;
            if (vis.contains(k)) {
                continue;
            }
            vis.add(k);
            int d = p[0];
            ans = Math.min(ans, d + dist(x, y, target[0], target[1]));
            for (var r : specialRoads) {
                int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3], cost = r[4];
                q.offer(new int[] {d + dist(x, y, x1, y1) + cost, x2, y2});
            }
        }
        return ans;
    }

    private int dist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        auto dist = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };
        int ans = 1 << 30;
        int n = 1e6;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, start[0], start[1]});
        unordered_set<long long> vis;
        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            long long k = 1LL * x * n + y;
            if (vis.count(k)) {
                continue;
            }
            vis.insert(k);
            ans = min(ans, d + dist(x, y, target[0], target[1]));
            for (auto& r : specialRoads) {
                int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3], cost = r[4];
                pq.push({d + dist(x, y, x1, y1) + cost, x2, y2});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(start []int, target []int, specialRoads [][]int) int {
	ans := 1 << 30
	const n int = 1e6
	pq := hp{{0, start[0], start[1]}}
	vis := map[int]bool{}
	for len(pq) > 0 {
		p := pq[0]
		heap.Pop(&pq)
		d, x, y := p.d, p.x, p.y
		if vis[x*n+y] {
			continue
		}
		vis[x*n+y] = true
		ans = min(ans, d+dist(x, y, target[0], target[1]))
		for _, r := range specialRoads {
			x1, y1, x2, y2, cost := r[0], r[1], r[2], r[3], r[4]
			heap.Push(&pq, tuple{d + dist(x, y, x1, y1) + cost, x2, y2})
		}
	}
	return ans
}

func dist(x1, y1, x2, y2 int) int {
	return abs(x1-x2) + abs(y1-y2)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type tuple struct {
	d, x, y int
}
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].d < h[j].d }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(start: number[], target: number[], specialRoads: number[][]): number {
    const dist = (x1: number, y1: number, x2: number, y2: number): number => {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };
    const q = new Heap<[number, number, number]>((a, b) => a[0] - b[0]);
    q.push([0, start[0], start[1]]);
    const n = 1000000;
    const vis: Set<number> = new Set();
    let ans = 1 << 30;
    while (q.size()) {
        const [d, x, y] = q.pop();
        const k = x * n + y;
        if (vis.has(k)) {
            continue;
        }
        vis.add(k);
        ans = Math.min(ans, d + dist(x, y, target[0], target[1]));
        for (const [x1, y1, x2, y2, cost] of specialRoads) {
            q.push([d + dist(x, y, x1, y1) + cost, x2, y2]);
        }
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class Heap<T = number> {
    data: Array<T | null>;
    lt: (i: number, j: number) => boolean;
    constructor();
    constructor(data: T[]);
    constructor(compare: Compare<T>);
    constructor(data: T[], compare: Compare<T>);
    constructor(data: T[] | Compare<T>, compare?: (lhs: T, rhs: T) => number);
    constructor(
        data: T[] | Compare<T> = [],
        compare: Compare<T> = (lhs: T, rhs: T) => (lhs < rhs ? -1 : lhs > rhs ? 1 : 0),
    ) {
        if (typeof data === 'function') {
            compare = data;
            data = [];
        }
        this.data = [null, ...data];
        this.lt = (i, j) => compare(this.data[i]!, this.data[j]!) < 0;
        for (let i = this.size(); i > 0; i--) this.heapify(i);
    }

    size(): number {
        return this.data.length - 1;
    }

    push(v: T): void {
        this.data.push(v);
        let i = this.size();
        while (i >> 1 !== 0 && this.lt(i, i >> 1)) this.swap(i, (i >>= 1));
    }

    pop(): T {
        this.swap(1, this.size());
        const top = this.data.pop();
        this.heapify(1);
        return top!;
    }

    top(): T {
        return this.data[1]!;
    }
    heapify(i: number): void {
        while (true) {
            let min = i;
            const [l, r, n] = [i * 2, i * 2 + 1, this.data.length];
            if (l < n && this.lt(l, min)) min = l;
            if (r < n && this.lt(r, min)) min = r;
            if (min !== i) {
                this.swap(i, min);
                i = min;
            } else break;
        }
    }

    clear(): void {
        this.data = [null];
    }

    private swap(i: number, j: number): void {
        const d = this.data;
        [d[i], d[j]] = [d[j], d[i]];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>start</code> ，其中 <code>start = [startX, startY]</code> 表示你的初始位置位于二维空间上的 <code>(startX, startY)</code> 。另给你一个数组 <code>target</code> ，其中 <code>target = [targetX, targetY]</code> 表示你的目标位置 <code>(targetX, targetY)</code> 。</p>

<p>从位置 <code>(x1, y1)</code> 到空间中任一其他位置 <code>(x2, y2)</code> 的 <strong>代价</strong> 是 <code>|x2 - x1| + |y2 - y1|</code> 。</p>

<p>给你一个二维数组 <code>specialRoads</code> ，表示空间中存在的一些 <strong>特殊路径</strong>。其中 <code>specialRoads[i] = [x1<sub>i</sub>, y1<sub>i</sub>, x2<sub>i</sub>, y2<sub>i</sub>, cost<sub>i</sub>]</code> 表示第 <code>i</code> 条特殊路径可以从 <code>(x1<sub>i</sub>, y1<sub>i</sub>)</code> 到 <code>(x2<sub>i</sub>, y2<sub>i</sub>)</code> ，但成本等于 <code>cost<sub>i</sub></code> 。你可以使用每条特殊路径任意次数。</p>

<p>返回从 <code>(startX, startY)</code> 到 <code>(targetX, targetY)</code> 所需的 <strong>最小</strong> 代价。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><b>解释：</b></p>

<ol>
	<li>(1,1) 到 (1,2) 花费为 |1 - 1| + |2 - 1| = 1。</li>
	<li>(1,2) 到 (3,3)。使用&nbsp;<code><span class="example-io">specialRoads[0]</span></code><span class="example-io">&nbsp;花费为</span><span class="example-io">&nbsp;2。</span></li>
	<li><span class="example-io">(3,3) </span>到<span class="example-io"> (3,4) </span>花费为<span class="example-io"> |3 - 3| + |4 - 3| = 1。</span></li>
	<li><span class="example-io">(3,4) </span>到<span class="example-io"> (4,5)。</span>使用<span class="example-io"> </span><code><span class="example-io">specialRoads[1]</span></code><span class="example-io"> 花费为</span><span class="example-io"> 1。</span></li>
</ol>

<p><span class="example-io">所以总花费是 1 + 2 + 1 + 1 = 5。</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">start = [3,2], target = [5,7], specialRoads = [[5,7,3,2,1],[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">7</span></p>

<p><b>解释：</b></p>

<p>不使用任何特殊路径，直接从开始到结束位置是最优的，花费为&nbsp;|5 - 3| + |7 - 2| = 7。</p>

<p>注意&nbsp;<span class="example-io"><code>specialRoads[0]</code>&nbsp;直接从 (5,7) 到 (3,2)。</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">start = [1,1], target = [10,4], specialRoads = [[4,2,1,1,3],[1,2,7,4,4],[10,3,6,1,2],[6,1,1,2,3]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">8</span></p>

<p><b>解释：</b></p>

<ol>
	<li>(1,1) 到 (1,2) 花费为 |1 - 1| + |2 - 1| = 1。</li>
	<li>(1,2) 到 (7,4)。使用&nbsp;<code><span class="example-io">specialRoads[1]</span></code><span class="example-io">&nbsp;花费为</span><span class="example-io">&nbsp;4。</span></li>
	<li>(7,4) 到 (10,4) 花费为 |10 - 7| + |4 - 4| = 3。</li>
</ol>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>start.length == target.length == 2</code></li>
	<li><code>1 &lt;= startX &lt;= targetX &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= startY &lt;= targetY &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= specialRoads.length &lt;= 200</code></li>
	<li><code>specialRoads[i].length == 5</code></li>
	<li><code>startX &lt;= x1<sub>i</sub>, x2<sub>i</sub> &lt;= targetX</code></li>
	<li><code>startY &lt;= y1<sub>i</sub>, y2<sub>i</sub> &lt;= targetY</code></li>
	<li><code>1 &lt;= cost<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Dijkstra

我们可以发现，对于访问到的每个坐标点 $(x, y)$，假设从起点到 $(x, y)$ 的最小代价为 $d$。如果选择直接移动到 $(targetX, targetY)$，那么总代价就是 $d + |x - targetX| + |y - targetY|$。如果选择经过某条特殊路径 $(x_1, y_1) \rightarrow (x_2, y_2)$，那么我们需要可以花费 $|x - x_1| + |y - y_1| + cost$ 的代价，从 $(x, y)$ 移动到 $(x_2, y_2)$。

因此，我们可以使用 Dijkstra 算法求出从起点到所有点的最小代价，然后从中选择最小的那个。

我们定义一个优先队列 $q$，队列中的每一个元素是一个三元组 $(d, x, y)$，表示从起点到 $(x, y)$ 的最小代价为 $d$。初始时，我们将 $(0, startX, startY)$ 加入队列中。

在每一步中，我们取出队首元素 $(d, x, y)$，此时我们可以更新答案，即 $ans = \min(ans, d + dist(x, y, targetX, targetY))$。然后我们枚举所有的特殊路径 $(x_1, y_1) \rightarrow (x_2, y_2)$，将 $(d + dist(x, y, x_1, y_1) + cost, x_2, y_2)$ 加入队列中。

最后当队列为空时，我们就可以得到答案。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n^2)$。其中 $n$ 是特殊路径的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(
        self, start: List[int], target: List[int], specialRoads: List[List[int]]
    ) -> int:
        def dist(x1: int, y1: int, x2: int, y2: int) -> int:
            return abs(x1 - x2) + abs(y1 - y2)

        q = [(0, start[0], start[1])]
        vis = set()
        ans = inf
        while q:
            d, x, y = heappop(q)
            if (x, y) in vis:
                continue
            vis.add((x, y))
            ans = min(ans, d + dist(x, y, *target))
            for x1, y1, x2, y2, cost in specialRoads:
                heappush(q, (d + dist(x, y, x1, y1) + cost, x2, y2))
        return ans
```

#### Java

```java
class Solution {
    public int minimumCost(int[] start, int[] target, int[][] specialRoads) {
        int ans = 1 << 30;
        int n = 1000000;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        Set<Long> vis = new HashSet<>();
        q.offer(new int[] {0, start[0], start[1]});
        while (!q.isEmpty()) {
            var p = q.poll();
            int x = p[1], y = p[2];
            long k = 1L * x * n + y;
            if (vis.contains(k)) {
                continue;
            }
            vis.add(k);
            int d = p[0];
            ans = Math.min(ans, d + dist(x, y, target[0], target[1]));
            for (var r : specialRoads) {
                int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3], cost = r[4];
                q.offer(new int[] {d + dist(x, y, x1, y1) + cost, x2, y2});
            }
        }
        return ans;
    }

    private int dist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        auto dist = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };
        int ans = 1 << 30;
        int n = 1e6;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, start[0], start[1]});
        unordered_set<long long> vis;
        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            long long k = 1LL * x * n + y;
            if (vis.count(k)) {
                continue;
            }
            vis.insert(k);
            ans = min(ans, d + dist(x, y, target[0], target[1]));
            for (auto& r : specialRoads) {
                int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3], cost = r[4];
                pq.push({d + dist(x, y, x1, y1) + cost, x2, y2});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumCost(start []int, target []int, specialRoads [][]int) int {
	ans := 1 << 30
	const n int = 1e6
	pq := hp{{0, start[0], start[1]}}
	vis := map[int]bool{}
	for len(pq) > 0 {
		p := pq[0]
		heap.Pop(&pq)
		d, x, y := p.d, p.x, p.y
		if vis[x*n+y] {
			continue
		}
		vis[x*n+y] = true
		ans = min(ans, d+dist(x, y, target[0], target[1]))
		for _, r := range specialRoads {
			x1, y1, x2, y2, cost := r[0], r[1], r[2], r[3], r[4]
			heap.Push(&pq, tuple{d + dist(x, y, x1, y1) + cost, x2, y2})
		}
	}
	return ans
}

func dist(x1, y1, x2, y2 int) int {
	return abs(x1-x2) + abs(y1-y2)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type tuple struct {
	d, x, y int
}
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].d < h[j].d }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function minimumCost(start: number[], target: number[], specialRoads: number[][]): number {
    const dist = (x1: number, y1: number, x2: number, y2: number): number => {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };
    const q = new Heap<[number, number, number]>((a, b) => a[0] - b[0]);
    q.push([0, start[0], start[1]]);
    const n = 1000000;
    const vis: Set<number> = new Set();
    let ans = 1 << 30;
    while (q.size()) {
        const [d, x, y] = q.pop();
        const k = x * n + y;
        if (vis.has(k)) {
            continue;
        }
        vis.add(k);
        ans = Math.min(ans, d + dist(x, y, target[0], target[1]));
        for (const [x1, y1, x2, y2, cost] of specialRoads) {
            q.push([d + dist(x, y, x1, y1) + cost, x2, y2]);
        }
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class Heap<T = number> {
    data: Array<T | null>;
    lt: (i: number, j: number) => boolean;
    constructor();
    constructor(data: T[]);
    constructor(compare: Compare<T>);
    constructor(data: T[], compare: Compare<T>);
    constructor(data: T[] | Compare<T>, compare?: (lhs: T, rhs: T) => number);
    constructor(
        data: T[] | Compare<T> = [],
        compare: Compare<T> = (lhs: T, rhs: T) => (lhs < rhs ? -1 : lhs > rhs ? 1 : 0),
    ) {
        if (typeof data === 'function') {
            compare = data;
            data = [];
        }
        this.data = [null, ...data];
        this.lt = (i, j) => compare(this.data[i]!, this.data[j]!) < 0;
        for (let i = this.size(); i > 0; i--) this.heapify(i);
    }

    size(): number {
        return this.data.length - 1;
    }

    push(v: T): void {
        this.data.push(v);
        let i = this.size();
        while (i >> 1 !== 0 && this.lt(i, i >> 1)) this.swap(i, (i >>= 1));
    }

    pop(): T {
        this.swap(1, this.size());
        const top = this.data.pop();
        this.heapify(1);
        return top!;
    }

    top(): T {
        return this.data[1]!;
    }
    heapify(i: number): void {
        while (true) {
            let min = i;
            const [l, r, n] = [i * 2, i * 2 + 1, this.data.length];
            if (l < n && this.lt(l, min)) min = l;
            if (r < n && this.lt(r, min)) min = r;
            if (min !== i) {
                this.swap(i, min);
                i = min;
            } else break;
        }
    }

    clear(): void {
        this.data = [null];
    }

    private swap(i: number, j: number): void {
        const d = this.data;
        [d[i], d[j]] = [d[j], d[i]];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2663. 字典序最小的美丽字符串](https://leetcode.cn/problems/lexicographically-smallest-beautiful-string){#2663}

{{< tabs "2663" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestBeautifulString(self, s: str, k: int) -> str:
        n = len(s)
        cs = list(s)
        for i in range(n - 1, -1, -1):
            p = ord(cs[i]) - ord('a') + 1
            for j in range(p, k):
                c = chr(ord('a') + j)
                if (i > 0 and cs[i - 1] == c) or (i > 1 and cs[i - 2] == c):
                    continue
                cs[i] = c
                for l in range(i + 1, n):
                    for m in range(k):
                        c = chr(ord('a') + m)
                        if (l > 0 and cs[l - 1] == c) or (l > 1 and cs[l - 2] == c):
                            continue
                        cs[l] = c
                        break
                return ''.join(cs)
        return ''
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String smallestBeautifulString(String s, int k) {
        int n = s.length();
        char[] cs = s.toCharArray();
        for (int i = n - 1; i >= 0; --i) {
            int p = cs[i] - 'a' + 1;
            for (int j = p; j < k; ++j) {
                char c = (char) ('a' + j);
                if ((i > 0 && cs[i - 1] == c) || (i > 1 && cs[i - 2] == c)) {
                    continue;
                }
                cs[i] = c;
                for (int l = i + 1; l < n; ++l) {
                    for (int m = 0; m < k; ++m) {
                        c = (char) ('a' + m);
                        if ((l > 0 && cs[l - 1] == c) || (l > 1 && cs[l - 2] == c)) {
                            continue;
                        }
                        cs[l] = c;
                        break;
                    }
                }
                return String.valueOf(cs);
            }
        }
        return "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            int p = s[i] - 'a' + 1;
            for (int j = p; j < k; ++j) {
                char c = (char) ('a' + j);
                if ((i > 0 && s[i - 1] == c) || (i > 1 && s[i - 2] == c)) {
                    continue;
                }
                s[i] = c;
                for (int l = i + 1; l < n; ++l) {
                    for (int m = 0; m < k; ++m) {
                        c = (char) ('a' + m);
                        if ((l > 0 && s[l - 1] == c) || (l > 1 && s[l - 2] == c)) {
                            continue;
                        }
                        s[l] = c;
                        break;
                    }
                }
                return s;
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestBeautifulString(s string, k int) string {
	cs := []byte(s)
	n := len(cs)
	for i := n - 1; i >= 0; i-- {
		p := int(cs[i] - 'a' + 1)
		for j := p; j < k; j++ {
			c := byte('a' + j)
			if (i > 0 && cs[i-1] == c) || (i > 1 && cs[i-2] == c) {
				continue
			}
			cs[i] = c
			for l := i + 1; l < n; l++ {
				for m := 0; m < k; m++ {
					c = byte('a' + m)
					if (l > 0 && cs[l-1] == c) || (l > 1 && cs[l-2] == c) {
						continue
					}
					cs[l] = c
					break
				}
			}
			return string(cs)
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestBeautifulString(s: string, k: number): string {
    const cs: string[] = s.split('');
    const n = cs.length;
    for (let i = n - 1; i >= 0; --i) {
        const p = cs[i].charCodeAt(0) - 97 + 1;
        for (let j = p; j < k; ++j) {
            let c = String.fromCharCode(j + 97);
            if ((i > 0 && cs[i - 1] === c) || (i > 1 && cs[i - 2] === c)) {
                continue;
            }
            cs[i] = c;
            for (let l = i + 1; l < n; ++l) {
                for (let m = 0; m < k; ++m) {
                    c = String.fromCharCode(m + 97);
                    if ((l > 0 && cs[l - 1] === c) || (l > 1 && cs[l - 2] === c)) {
                        continue;
                    }
                    cs[l] = c;
                    break;
                }
            }
            return cs.join('');
        }
    }
    return '';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个字符串满足以下条件，则称其为 <strong>美丽字符串</strong> ：</p>

<ul>
	<li>它由英语小写字母表的前 <code>k</code> 个字母组成。</li>
	<li>它不包含任何长度为 <code>2</code> 或更长的回文子字符串。</li>
</ul>

<p>给你一个长度为 <code>n</code> 的美丽字符串 <code>s</code> 和一个正整数 <code>k</code> 。</p>

<p>请你找出并返回一个长度为 <code>n</code> 的美丽字符串，该字符串还满足：在字典序大于 <code>s</code> 的所有美丽字符串中字典序最小。如果不存在这样的字符串，则返回一个空字符串。</p>

<p>对于长度相同的两个字符串 <code>a</code> 和 <code>b</code> ，如果字符串 <code>a</code> 在与字符串 <code>b</code> 不同的第一个位置上的字符字典序更大，则字符串 <code>a</code> 的字典序大于字符串 <code>b</code> 。</p>

<ul>
	<li>例如，<code>"abcd"</code> 的字典序比 <code>"abcc"</code> 更大，因为在不同的第一个位置（第四个字符）上 <code>d</code> 的字典序大于 <code>c</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcz", k = 26
<strong>输出：</strong>"abda"
<strong>解释：</strong>字符串 "abda" 既是美丽字符串，又满足字典序大于 "abcz" 。
可以证明不存在字符串同时满足字典序大于 "abcz"、美丽字符串、字典序小于 "abda" 这三个条件。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "dc", k = 4
<strong>输出：</strong>""
<strong>解释：</strong>可以证明，不存在既是美丽字符串，又字典序大于 "dc" 的字符串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>4 &lt;= k &lt;= 26</code></li>
	<li><code>s</code> 是一个美丽字符串</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以发现，一个长度为 $2$ 的回文字符串，其相邻两个字符一定相同；而一个长度为 $3$ 的回文字符串，其首尾两个字符一定相同。因此，一个美丽字符串不包含任何长度为 $2$ 或更长的回文子字符串，意味着该字符串的每个字符与其相邻的前两个字符都不相同。

我们可以贪心地从字符串的最后一个下标开始往前查找，找到一个下标 $i$，使得下标 $i$ 处的字符可以被替换为一个比其稍大的字符，同时保证其与其相邻的前两个字符都不相同的字符 $c$。

-   若找到了这样的下标 $i$，那么我们将 $s[i]$ 替换为 $c$，并将 $s[i+1]$ 到 $s[n-1]$ 的字符依次替换为字典序尽可能小的、不与前面相邻两个字符相同的、且在字母表前 $k$ 个字符中的字符，替换完成后，我们就得到了一个字典序最小的且大于 $s$ 的美丽字符串。
-   若找不到这样的下标 $i$，那么我们就无法构造出字典序大于 $s$ 的美丽字符串，因此返回空字符串。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestBeautifulString(self, s: str, k: int) -> str:
        n = len(s)
        cs = list(s)
        for i in range(n - 1, -1, -1):
            p = ord(cs[i]) - ord('a') + 1
            for j in range(p, k):
                c = chr(ord('a') + j)
                if (i > 0 and cs[i - 1] == c) or (i > 1 and cs[i - 2] == c):
                    continue
                cs[i] = c
                for l in range(i + 1, n):
                    for m in range(k):
                        c = chr(ord('a') + m)
                        if (l > 0 and cs[l - 1] == c) or (l > 1 and cs[l - 2] == c):
                            continue
                        cs[l] = c
                        break
                return ''.join(cs)
        return ''
```

#### Java

```java
class Solution {
    public String smallestBeautifulString(String s, int k) {
        int n = s.length();
        char[] cs = s.toCharArray();
        for (int i = n - 1; i >= 0; --i) {
            int p = cs[i] - 'a' + 1;
            for (int j = p; j < k; ++j) {
                char c = (char) ('a' + j);
                if ((i > 0 && cs[i - 1] == c) || (i > 1 && cs[i - 2] == c)) {
                    continue;
                }
                cs[i] = c;
                for (int l = i + 1; l < n; ++l) {
                    for (int m = 0; m < k; ++m) {
                        c = (char) ('a' + m);
                        if ((l > 0 && cs[l - 1] == c) || (l > 1 && cs[l - 2] == c)) {
                            continue;
                        }
                        cs[l] = c;
                        break;
                    }
                }
                return String.valueOf(cs);
            }
        }
        return "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            int p = s[i] - 'a' + 1;
            for (int j = p; j < k; ++j) {
                char c = (char) ('a' + j);
                if ((i > 0 && s[i - 1] == c) || (i > 1 && s[i - 2] == c)) {
                    continue;
                }
                s[i] = c;
                for (int l = i + 1; l < n; ++l) {
                    for (int m = 0; m < k; ++m) {
                        c = (char) ('a' + m);
                        if ((l > 0 && s[l - 1] == c) || (l > 1 && s[l - 2] == c)) {
                            continue;
                        }
                        s[l] = c;
                        break;
                    }
                }
                return s;
            }
        }
        return "";
    }
};
```

#### Go

```go
func smallestBeautifulString(s string, k int) string {
	cs := []byte(s)
	n := len(cs)
	for i := n - 1; i >= 0; i-- {
		p := int(cs[i] - 'a' + 1)
		for j := p; j < k; j++ {
			c := byte('a' + j)
			if (i > 0 && cs[i-1] == c) || (i > 1 && cs[i-2] == c) {
				continue
			}
			cs[i] = c
			for l := i + 1; l < n; l++ {
				for m := 0; m < k; m++ {
					c = byte('a' + m)
					if (l > 0 && cs[l-1] == c) || (l > 1 && cs[l-2] == c) {
						continue
					}
					cs[l] = c
					break
				}
			}
			return string(cs)
		}
	}
	return ""
}
```

#### TypeScript

```ts
function smallestBeautifulString(s: string, k: number): string {
    const cs: string[] = s.split('');
    const n = cs.length;
    for (let i = n - 1; i >= 0; --i) {
        const p = cs[i].charCodeAt(0) - 97 + 1;
        for (let j = p; j < k; ++j) {
            let c = String.fromCharCode(j + 97);
            if ((i > 0 && cs[i - 1] === c) || (i > 1 && cs[i - 2] === c)) {
                continue;
            }
            cs[i] = c;
            for (let l = i + 1; l < n; ++l) {
                for (let m = 0; m < k; ++m) {
                    c = String.fromCharCode(m + 97);
                    if ((l > 0 && cs[l - 1] === c) || (l > 1 && cs[l - 2] === c)) {
                        continue;
                    }
                    cs[l] = c;
                    break;
                }
            }
            return cs.join('');
        }
    }
    return '';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2664. 巡逻的骑士 🔒](https://leetcode.cn/problems/the-knights-tour){#2664}

{{< tabs "2664" >}}

{{% tab "python" %}}
```python
class Solution:
    def tourOfKnight(self, m: int, n: int, r: int, c: int) -> List[List[int]]:
        def dfs(i: int, j: int):
            nonlocal ok
            if g[i][j] == m * n - 1:
                ok = True
                return
            for a, b in pairwise((-2, -1, 2, 1, -2, 1, 2, -1, -2)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and g[x][y] == -1:
                    g[x][y] = g[i][j] + 1
                    dfs(x, y)
                    if ok:
                        return
                    g[x][y] = -1

        g = [[-1] * n for _ in range(m)]
        g[r][c] = 0
        ok = False
        dfs(r, c)
        return g
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] g;
    private int m;
    private int n;
    private boolean ok;

    public int[][] tourOfKnight(int m, int n, int r, int c) {
        this.m = m;
        this.n = n;
        this.g = new int[m][n];
        for (var row : g) {
            Arrays.fill(row, -1);
        }
        g[r][c] = 0;
        dfs(r, c);
        return g;
    }

    private void dfs(int i, int j) {
        if (g[i][j] == m * n - 1) {
            ok = true;
            return;
        }
        int[] dirs = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int k = 0; k < 8; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == -1) {
                g[x][y] = g[i][j] + 1;
                dfs(x, y);
                if (ok) {
                    return;
                }
                g[x][y] = -1;
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
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> g(m, vector<int>(n, -1));
        g[r][c] = 0;
        int dirs[9] = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        bool ok = false;
        function<void(int, int)> dfs = [&](int i, int j) {
            if (g[i][j] == m * n - 1) {
                ok = true;
                return;
            }
            for (int k = 0; k < 8; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == -1) {
                    g[x][y] = g[i][j] + 1;
                    dfs(x, y);
                    if (ok) {
                        return;
                    }
                    g[x][y] = -1;
                }
            }
        };
        dfs(r, c);
        return g;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func tourOfKnight(m int, n int, r int, c int) [][]int {
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = -1
		}
	}
	g[r][c] = 0
	ok := false
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if g[i][j] == m*n-1 {
			ok = true
			return
		}
		dirs := []int{-2, -1, 2, 1, -2, 1, 2, -1, -2}
		for k := 0; k < 8; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && g[x][y] == -1 {
				g[x][y] = g[i][j] + 1
				dfs(x, y)
				if ok {
					return
				}
				g[x][y] = -1
			}
		}
	}
	dfs(r, c)
	return g
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function tourOfKnight(m: number, n: number, r: number, c: number): number[][] {
    const g: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dirs = [-2, -1, 2, 1, -2, 1, 2, -1, -2];
    let ok = false;
    const dfs = (i: number, j: number) => {
        if (g[i][j] === m * n - 1) {
            ok = true;
            return;
        }
        for (let k = 0; k < 8; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] === -1) {
                g[x][y] = g[i][j] + 1;
                dfs(x, y);
                if (ok) {
                    return;
                }
                g[x][y] = -1;
            }
        }
    };
    g[r][c] = 0;
    dfs(r, c);
    return g;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn tour_of_knight(m: i32, n: i32, r: i32, c: i32) -> Vec<Vec<i32>> {
        let mut g: Vec<Vec<i32>> = vec![vec![-1; n as usize]; m as usize];
        g[r as usize][c as usize] = 0;
        let dirs: [i32; 9] = [-2, -1, 2, 1, -2, 1, 2, -1, -2];
        let mut ok = false;

        fn dfs(
            i: usize,
            j: usize,
            g: &mut Vec<Vec<i32>>,
            m: i32,
            n: i32,
            dirs: &[i32; 9],
            ok: &mut bool,
        ) {
            if g[i][j] == m * n - 1 {
                *ok = true;
                return;
            }
            for k in 0..8 {
                let x = ((i as i32) + dirs[k]) as usize;
                let y = ((j as i32) + dirs[k + 1]) as usize;
                if x < (m as usize) && y < (n as usize) && g[x][y] == -1 {
                    g[x][y] = g[i][j] + 1;
                    dfs(x, y, g, m, n, dirs, ok);
                    if *ok {
                        return;
                    }
                    g[x][y] = -1;
                }
            }
        }

        dfs(r as usize, c as usize, &mut g, m, n, &dirs, &mut ok);
        g
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个正整数 <code>m</code> 和 <code>n</code>&nbsp;，它们是一个 <strong>下标从 0 开始</strong> 的二维数组 <code>board</code> 的高度和宽度。还有一对正整数 <code>(r, c)</code> ，它们是骑士在棋盘上的起始位置。</p>

<p>你的任务是找到一个骑士的移动顺序，使得&nbsp;<code>board</code>&nbsp;中每个单元格都 <strong>恰好</strong> 被访问一次（起始单元格已被访问，<strong>不应</strong> 再次访问）。</p>

<p>返回数组 <code>board</code> ，其中单元格的值显示从 0 开始访问该单元格的顺序（骑士的初始位置为 0）。</p>

<p>注意，如果 <code>0 &lt;= r2 &lt;= m-1 且 0 &lt;= c2 &lt;= n-1</code>&nbsp;，并且 <code>min(abs(r1-r2), abs(c1-c2)) = 1</code> 且 <code>max(abs(r1-r2), abs(c1-c2)) = 2</code>&nbsp;，则骑士可以从单元格 <code>(r1, c1)</code> 移动到单元格 <code>(r2, c2)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre>
<b>输入：</b>m = 1, n = 1, r = 0, c = 0
<b>输出：</b>[[0]]
<b>解释</b>只有一个单元格，骑士最初在其中，因此 1x1 网格中只有一个 0。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 4, r = 0, c = 0
<b>输出：</b>[[0,3,6,9],[11,8,1,4],[2,5,10,7]]
<b>解释：</b>按照以下移动顺序，我们可以访问整个棋盘。 
(0,0)-&gt;(1,2)-&gt;(2,0)-&gt;(0,1)-&gt;(1,3)-&gt;(2,1)-&gt;(0,2)-&gt;(2,3)-&gt;(1,1)-&gt;(0,3)-&gt;(2,2)-&gt;(1,0)</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= m,&nbsp;n &lt;= 5</code></li>
	<li><code>0 &lt;= r &lt;= m - 1</code></li>
	<li><code>0 &lt;= c &lt;= n - 1</code></li>
	<li>输入的数据保证在给定条件下至少存在一种访问所有单元格的移动顺序。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯

我们创建一个二维数组 $g$，用于记录骑士的移动顺序，初始时 $g[r][c] = -1$，其余位置均为 $-1$。另外，我们还需要一个变量 $ok$，用于记录是否找到了一种方案。

接下来，我们从 $(r, c)$ 开始进行深度优先搜索，每次搜索位置 $(i, j)$ 时，我们先判断 $g[i][j]$ 是否等于 $m \times n - 1$，若是，说明我们已经找到了一种方案，此时将 $ok$ 置为 `true` 并且返回。否则我们枚举骑士的八个移动方向对应的位置 $(x, y)$，若满足 $0 \leq x \lt m$, $0 \leq y \lt n$，并且 $g[x][y]=-1$，那么我们将 $g[x][y]$ 更新为 $g[i][j]+1$，然后递归搜索位置 $(x, y)$。如果搜索结束后，变量 $ok$ 为 `true`，则直接返回。否则，我们将 $g[x][y]$ 重置为 $-1$，继续搜索其他方向。

最后返回二维数组 $g$ 即可。

时间复杂度 $O(8^{m \times n})$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 为题目给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tourOfKnight(self, m: int, n: int, r: int, c: int) -> List[List[int]]:
        def dfs(i: int, j: int):
            nonlocal ok
            if g[i][j] == m * n - 1:
                ok = True
                return
            for a, b in pairwise((-2, -1, 2, 1, -2, 1, 2, -1, -2)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and g[x][y] == -1:
                    g[x][y] = g[i][j] + 1
                    dfs(x, y)
                    if ok:
                        return
                    g[x][y] = -1

        g = [[-1] * n for _ in range(m)]
        g[r][c] = 0
        ok = False
        dfs(r, c)
        return g
```

#### Java

```java
class Solution {
    private int[][] g;
    private int m;
    private int n;
    private boolean ok;

    public int[][] tourOfKnight(int m, int n, int r, int c) {
        this.m = m;
        this.n = n;
        this.g = new int[m][n];
        for (var row : g) {
            Arrays.fill(row, -1);
        }
        g[r][c] = 0;
        dfs(r, c);
        return g;
    }

    private void dfs(int i, int j) {
        if (g[i][j] == m * n - 1) {
            ok = true;
            return;
        }
        int[] dirs = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        for (int k = 0; k < 8; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == -1) {
                g[x][y] = g[i][j] + 1;
                dfs(x, y);
                if (ok) {
                    return;
                }
                g[x][y] = -1;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> g(m, vector<int>(n, -1));
        g[r][c] = 0;
        int dirs[9] = {-2, -1, 2, 1, -2, 1, 2, -1, -2};
        bool ok = false;
        function<void(int, int)> dfs = [&](int i, int j) {
            if (g[i][j] == m * n - 1) {
                ok = true;
                return;
            }
            for (int k = 0; k < 8; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == -1) {
                    g[x][y] = g[i][j] + 1;
                    dfs(x, y);
                    if (ok) {
                        return;
                    }
                    g[x][y] = -1;
                }
            }
        };
        dfs(r, c);
        return g;
    }
};
```

#### Go

```go
func tourOfKnight(m int, n int, r int, c int) [][]int {
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = -1
		}
	}
	g[r][c] = 0
	ok := false
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if g[i][j] == m*n-1 {
			ok = true
			return
		}
		dirs := []int{-2, -1, 2, 1, -2, 1, 2, -1, -2}
		for k := 0; k < 8; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && g[x][y] == -1 {
				g[x][y] = g[i][j] + 1
				dfs(x, y)
				if ok {
					return
				}
				g[x][y] = -1
			}
		}
	}
	dfs(r, c)
	return g
}
```

#### TypeScript

```ts
function tourOfKnight(m: number, n: number, r: number, c: number): number[][] {
    const g: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dirs = [-2, -1, 2, 1, -2, 1, 2, -1, -2];
    let ok = false;
    const dfs = (i: number, j: number) => {
        if (g[i][j] === m * n - 1) {
            ok = true;
            return;
        }
        for (let k = 0; k < 8; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] === -1) {
                g[x][y] = g[i][j] + 1;
                dfs(x, y);
                if (ok) {
                    return;
                }
                g[x][y] = -1;
            }
        }
    };
    g[r][c] = 0;
    dfs(r, c);
    return g;
}
```

#### Rust

```rust
impl Solution {
    pub fn tour_of_knight(m: i32, n: i32, r: i32, c: i32) -> Vec<Vec<i32>> {
        let mut g: Vec<Vec<i32>> = vec![vec![-1; n as usize]; m as usize];
        g[r as usize][c as usize] = 0;
        let dirs: [i32; 9] = [-2, -1, 2, 1, -2, 1, 2, -1, -2];
        let mut ok = false;

        fn dfs(
            i: usize,
            j: usize,
            g: &mut Vec<Vec<i32>>,
            m: i32,
            n: i32,
            dirs: &[i32; 9],
            ok: &mut bool,
        ) {
            if g[i][j] == m * n - 1 {
                *ok = true;
                return;
            }
            for k in 0..8 {
                let x = ((i as i32) + dirs[k]) as usize;
                let y = ((j as i32) + dirs[k + 1]) as usize;
                if x < (m as usize) && y < (n as usize) && g[x][y] == -1 {
                    g[x][y] = g[i][j] + 1;
                    dfs(x, y, g, m, n, dirs, ok);
                    if *ok {
                        return;
                    }
                    g[x][y] = -1;
                }
            }
        }

        dfs(r as usize, c as usize, &mut g, m, n, &dirs, &mut ok);
        g
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2665. 计数器 II](https://leetcode.cn/problems/counter-ii){#2665}

{{< tabs "2665" >}}

{{% tab "ts" %}}
```ts
type ReturnObj = {
    increment: () => number;
    decrement: () => number;
    reset: () => number;
};

function createCounter(init: number): ReturnObj {
    let val = init;
    return {
        increment() {
            return ++val;
        },
        decrement() {
            return --val;
        },
        reset() {
            return (val = init);
        },
    };
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你写一个函数&nbsp;<code>createCounter</code>。这个函数接收一个初始的整数值 <code>init</code>。并返回一个包含三个函数的对象。</p>

<p>这三个函数是：</p>

<ul>
	<li><code>increment()</code>&nbsp;将当前值加 1 并返回。</li>
	<li><code>decrement()</code>&nbsp;将当前值减 1 并返回。</li>
	<li><code>reset()</code>&nbsp;将当前值设置为 <code>init</code> 并返回。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>init = 5, calls = ["increment","reset","decrement"]
<strong>输出：</strong>[6,5,4]
<strong>解释：</strong>
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>init = 0, calls = ["increment","increment","decrement","reset","reset"]
<strong>输出：</strong>[1,2,1,0,0]
<strong>解释：</strong>
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-1000 &lt;= init &lt;= 1000</code></li>
	<li><code>0 &lt;= calls.length &lt;= 1000</code></li>
	<li><code>calls[i]</code> 是 “increment”、“decrement” 和 “reset” 中的一个</li>
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

#### TypeScript

```ts
type ReturnObj = {
    increment: () => number;
    decrement: () => number;
    reset: () => number;
};

function createCounter(init: number): ReturnObj {
    let val = init;
    return {
        increment() {
            return ++val;
        },
        decrement() {
            return --val;
        },
        reset() {
            return (val = init);
        },
    };
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2666. 只允许一次函数调用](https://leetcode.cn/problems/allow-one-function-call){#2666}

{{< tabs "2666" >}}

{{% tab "ts" %}}
```ts
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type OnceFn = (...args: JSONValue[]) => JSONValue | undefined;

function once(fn: Function): OnceFn {
    let called = false;
    return function (...args) {
        if (!called) {
            called = true;
            return fn(...args);
        }
    };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function (fn) {
    let called = false;
    return function (...args) {
        if (!called) {
            called = true;
            return fn(...args);
        }
    };
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个函数 <code>fn</code> ，它返回一个新的函数，返回的函数与原始函数完全相同，只不过它确保 <code>fn</code> 最多被调用一次。</p>

<ul>
	<li>第一次调用返回的函数时，它应该返回与 <code>fn</code> 相同的结果。</li>
	<li>第一次后的每次调用，它应该返回 <code>undefined</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>fn = (a,b,c) =&gt; (a + b + c), calls = [[1,2,3],[2,3,6]]
<b>输出：</b>[{"calls":1,"value":6}]
<strong>解释：</strong>
const onceFn = once(fn);
onceFn(1, 2, 3); // 6
onceFn(2, 3, 6); // undefined, fn 没有被调用
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>fn = (a,b,c) =&gt; (a * b * c), calls = [[5,7,4],[2,3,6],[4,6,8]]
<b>输出：</b>[{"calls":1,"value":140}]
<strong>解释：</strong>
const onceFn = once(fn);
onceFn(5, 7, 4); // 140
onceFn(2, 3, 6); // undefined, fn 没有被调用
onceFn(4, 6, 8); // undefined, fn 没有被调用
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>calls</code> 是一个有效的 JSON 数组</li>
	<li><code>1 &lt;= calls.length &lt;= 10</code></li>
	<li><code>1 &lt;= calls[i].length &lt;= 100</code></li>
	<li><code>2 &lt;= JSON.stringify(calls).length &lt;= 1000</code></li>
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

#### TypeScript

```ts
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type OnceFn = (...args: JSONValue[]) => JSONValue | undefined;

function once(fn: Function): OnceFn {
    let called = false;
    return function (...args) {
        if (!called) {
            called = true;
            return fn(...args);
        }
    };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
```

#### JavaScript

```js
/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function (fn) {
    let called = false;
    return function (...args) {
        if (!called) {
            called = true;
            return fn(...args);
        }
    };
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2667. 创建 Hello World 函数](https://leetcode.cn/problems/create-hello-world-function){#2667}

{{< tabs "2667" >}}

{{% tab "ts" %}}
```ts
function createHelloWorld() {
    return function (...args): string {
        return 'Hello World';
    };
}

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

请你编写一个名为 <code>createHelloWorld</code> 的函数。它应该返回一个新的函数，该函数总是返回 <code>"Hello World"</code>&nbsp;。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>args = []
<b>输出：</b>"Hello World"
<strong>解释：</strong>
const f = createHelloWorld();
f(); // "Hello World"

createHelloWorld 返回的函数应始终返回 "Hello World"。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>args = [{},null,42]
<b>输出：</b>"Hello World"
<strong>解释：</strong>
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

可以传递任何参数给函数，但它应始终返回 "Hello World"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= args.length &lt;= 10</code></li>
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

#### TypeScript

```ts
function createHelloWorld() {
    return function (...args): string {
        return 'Hello World';
    };
}

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2668. 查询员工当前薪水 🔒](https://leetcode.cn/problems/find-latest-salaries){#2668}

{{< tabs "2668" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    emp_id,
    firstname,
    lastname,
    MAX(salary) AS salary,
    department_id
FROM Salary
GROUP BY emp_id
ORDER BY emp_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code><font face="monospace">Salary</font></code></p>

<pre>
+---------------+---------+ 
| 列名          | 类型    | 
+---------------+---------+ 
| emp_id        | int     | 
| firstname     | varchar |
| lastname      | varchar |
| salary        | varchar |
| department_id | varchar |
+---------------+---------+
(emp_id, salary) 是该表的主键(具有唯一值的列的组合)。
每行包含员工的详细信息和他们每年的薪水，但有些记录是旧的，包含过时的薪资信息。
</pre>

<p>找出每个员工的当前薪水，假设薪水每年增加。输出他们的 <code>emp_id</code>&nbsp;、<code>firstname</code>&nbsp;、<code>lastname</code>&nbsp;、<code>salary</code> 和 <code>department_id</code> 。</p>

<p>按&nbsp;<code>emp_id</code> <strong>升序排序</strong> 返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：
</strong><code>Salary</code> 表:
+--------+-----------+----------+--------+---------------+
| emp_id | firstname | lastname | salary | department_id |
+--------+-----------+----------+--------+---------------+ 
| 1      | Todd      | Wilson   | 110000 | D1006         |
| 1      | Todd      | Wilson   | 106119 | D1006         | 
| 2      | Justin    | Simon    | 128922 | D1005         | 
| 2      | Justin    | Simon    | 130000 | D1005         | 
| 3      | Kelly     | Rosario  | 42689  | D1002         | 
| 4      | Patricia  | Powell   | 162825 | D1004         |
| 4      | Patricia  | Powell   | 170000 | D1004         |
| 5      | Sherry    | Golden   | 44101  | D1002         | 
| 6      | Natasha   | Swanson  | 79632  | D1005         | 
| 6      | Natasha   | Swanson  | 90000  | D1005         |
+--------+-----------+----------+--------+---------------+
<strong>输出：
</strong>+--------+-----------+----------+--------+---------------+
| emp_id | firstname | lastname | salary | department_id |
+--------+-----------+----------+--------+---------------+ 
| 1      | Todd      | Wilson   | 110000 | D1006         |
| 2      | Justin    | Simon    | 130000 | D1005         | 
| 3      | Kelly     | Rosario  | 42689  | D1002         | 
| 4      | Patricia  | Powell   | 170000 | D1004         |
| 5      | Sherry    | Golden   | 44101  | D1002         | 
| 6      | Natasha   | Swanson  | 90000  | D1005         |
+--------+-----------+----------+--------+---------------+<strong>
</strong>
<strong>解释：</strong>
- emp_id 1 有两条记录，工资分别为 110000 和 106119，其中 110000 是更新后的工资（假设工资每年都会增加）
- emp_id 2 有两条记录，工资分别为 128922 和 130000，其中 130000 是更新后的工资。
- emp_id 3 只有一条工资记录，因此这已经是更新后的工资。
- emp_id 4 有两条记录，工资分别为 162825 和 170000，其中 170000 是更新后的工资。
- emp_id 5 只有一条工资记录，因此这已经是更新后的工资。
- emp_id 6 有两条记录，工资分别为 79632 和 90000，其中 90000 是更新后的工资。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    emp_id,
    firstname,
    lastname,
    MAX(salary) AS salary,
    department_id
FROM Salary
GROUP BY emp_id
ORDER BY emp_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2669. 统计 Spotify 排行榜上艺术家出现次数 🔒](https://leetcode.cn/problems/count-artist-occurrences-on-spotify-ranking-list){#2669}

{{< tabs "2669" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    artist,
    COUNT(1) AS occurrences
FROM Spotify
GROUP BY artist
ORDER BY occurrences DESC, artist;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code><font face="monospace">Spotify</font></code></p>

<pre>
+-------------+---------+ 
| 列名        | 类型    | 
+-------------+---------+ 
| id          | int     | 
| track_name  | varchar |
| artist      | varchar |
+-------------+---------+
id 是该表的主键(具有唯一值的列)。
每行包含 id、track_name 和 artist。
</pre>

<p>编写解决方案来查找每个艺术家在Spotify排行榜上出现的次数。</p>

<p>返回结果表，其中包含艺术家的名称以及相应的出现次数，按出现次数&nbsp;<strong>降序&nbsp;</strong>排列。如果出现次数相等，则按艺术家名称&nbsp;<strong>升序&nbsp;</strong>排列。</p>

<p>返回结果格式如下所示：</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：
</strong>Spotify 表: 
+---------+--------------------+------------+ 
| id      | track_name         | artist     |  
+---------+--------------------+------------+
| 303651  | Heart Won't Forget | Sia        |
| 1046089 | Shape of you       | Ed Sheeran |
| 33445   | I'm the one        | DJ Khalid  |
| 811266  | Young Dumb &amp; Broke | DJ Khalid  | 
| 505727  | Happier            | Ed Sheeran |
+---------+--------------------+------------+ 
<strong>输出：
</strong>+------------+-------------+
| artist     | occurrences | 
+------------+-------------+
| DJ Khalid  | 2           |
| Ed Sheeran | 2           |
| Sia        | 1           | 
+------------+-------------+ 

<strong>解释：</strong>"occurrences" 列下按降序列出了出现次数的计数。如果出现次数相同，则艺术家名称按升序排序。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    artist,
    COUNT(1) AS occurrences
FROM Spotify
GROUP BY artist
ORDER BY occurrences DESC, artist;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
