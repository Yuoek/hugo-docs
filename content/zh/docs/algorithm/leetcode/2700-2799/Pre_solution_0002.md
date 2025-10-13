---
title: "2710_移除字符串中的尾随零"
date: 2025-10-08T18:39:33+08:00
weight: 2
tags: [JavaScript, 二分查找, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 排序, 数学, 数组, 最短路, 有序集合, 模拟, 矩阵, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [2710_移除字符串中的尾随零](#2710)
#### [字符串](#2710)
### [2711_对角线上不同值的数量差](#2711)
#### [数组](#2711)
#### [哈希表](#2711)
#### [矩阵](#2711)
### [2712_使所有字符相等的最小成本](#2712)
#### [贪心](#2712)
#### [字符串](#2712)
#### [动态规划](#2712)
### [2713_矩阵中严格递增的单元格数](#2713)
#### [记忆化搜索](#2713)
#### [数组](#2713)
#### [哈希表](#2713)
#### [二分查找](#2713)
#### [动态规划](#2713)
#### [矩阵](#2713)
#### [有序集合](#2713)
#### [排序](#2713)
### [2714_找到 K 次跨越的最短路径 🔒](#2714)
#### [图](#2714)
#### [最短路](#2714)
#### [堆（优先队列）](#2714)
### [2715_执行可取消的延迟函数](#2715)
#### [JavaScript](#2715)
### [2716_最小化字符串长度](#2716)
#### [哈希表](#2716)
#### [字符串](#2716)
### [2717_半有序排列](#2717)
#### [数组](#2717)
#### [模拟](#2717)
### [2718_查询后矩阵的和](#2718)
#### [数组](#2718)
#### [哈希表](#2718)
### [2719_统计整数数目](#2719)
#### [数学](#2719)
#### [字符串](#2719)
#### [动态规划](#2719)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2710_移除字符串中的尾随零
___
#### 字符串
---
### 2711_对角线上不同值的数量差
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 2712_使所有字符相等的最小成本
___
#### 贪心
___
#### 字符串
___
#### 动态规划
---
### 2713_矩阵中严格递增的单元格数
___
#### 记忆化搜索
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 动态规划
___
#### 矩阵
___
#### 有序集合
___
#### 排序
---
### 2714_找到 K 次跨越的最短路径 🔒
___
#### 图
___
#### 最短路
___
#### 堆（优先队列）
---
### 2715_执行可取消的延迟函数
___
#### JavaScript
---
### 2716_最小化字符串长度
___
#### 哈希表
___
#### 字符串
---
### 2717_半有序排列
___
#### 数组
___
#### 模拟
---
### 2718_查询后矩阵的和
___
#### 数组
___
#### 哈希表
---
### 2719_统计整数数目
___
#### 数学
___
#### 字符串
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 动态规划 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数组 | 最短路 | 有序集合 |
| 模拟 | 矩阵 | 记忆化搜索 |
| 贪心 |  |  |

# [2710. 移除字符串中的尾随零](https://leetcode.cn/problems/remove-trailing-zeros-from-a-string){#2710}

{{< tabs "2710" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        return num.rstrip("0")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeTrailingZeros(String num) {
        int i = num.length() - 1;
        while (num.charAt(i) == '0') {
            --i;
        }
        return num.substring(0, i + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeTrailingZeros(string num) {
        while (num.back() == '0') {
            num.pop_back();
        }
        return num;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeTrailingZeros(num string) string {
	i := len(num) - 1
	for num[i] == '0' {
		i--
	}
	return num[:i+1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeTrailingZeros(num: string): string {
    let i = num.length - 1;
    while (num[i] === '0') {
        --i;
    }
    return num.substring(0, i + 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_trailing_zeros(num: String) -> String {
        let mut i = num.len() - 1;

        while num.chars().nth(i) == Some('0') {
            i -= 1;
        }

        num[..i + 1].to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个用字符串表示的正整数 <code>num</code> ，请你以字符串形式返回不含尾随零的整数<em> </em><code>num</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = "51230100"
<strong>输出：</strong>"512301"
<strong>解释：</strong>整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = "123"
<strong>输出：</strong>"123"
<strong>解释：</strong>整数 "123" 不含尾随零，返回整数 "123" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> 仅由数字 <code>0</code> 到 <code>9</code> 组成</li>
	<li><code>num</code> 不含前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们可以从后往前遍历字符串，遇到第一个不是 `0` 的字符时停止遍历，然后返回从头开始到这个字符的子串。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        return num.rstrip("0")
```

#### Java

```java
class Solution {
    public String removeTrailingZeros(String num) {
        int i = num.length() - 1;
        while (num.charAt(i) == '0') {
            --i;
        }
        return num.substring(0, i + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeTrailingZeros(string num) {
        while (num.back() == '0') {
            num.pop_back();
        }
        return num;
    }
};
```

#### Go

```go
func removeTrailingZeros(num string) string {
	i := len(num) - 1
	for num[i] == '0' {
		i--
	}
	return num[:i+1]
}
```

#### TypeScript

```ts
function removeTrailingZeros(num: string): string {
    let i = num.length - 1;
    while (num[i] === '0') {
        --i;
    }
    return num.substring(0, i + 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_trailing_zeros(num: String) -> String {
        let mut i = num.len() - 1;

        while num.chars().nth(i) == Some('0') {
            i -= 1;
        }

        num[..i + 1].to_string()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2711. 对角线上不同值的数量差](https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals){#2711}

{{< tabs "2711" >}}

{{% tab "python" %}}
```python
class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x, y = i, j
                s = set()
                while x and y:
                    x, y = x - 1, y - 1
                    s.add(grid[x][y])
                tl = len(s)
                x, y = i, j
                s = set()
                while x + 1 < m and y + 1 < n:
                    x, y = x + 1, y + 1
                    s.add(grid[x][y])
                br = len(s)
                ans[i][j] = abs(tl - br)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] differenceOfDistinctValues(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i, y = j;
                Set<Integer> s = new HashSet<>();
                while (x > 0 && y > 0) {
                    s.add(grid[--x][--y]);
                }
                int tl = s.size();
                x = i;
                y = j;
                s.clear();
                while (x < m - 1 && y < n - 1) {
                    s.add(grid[++x][++y]);
                }
                int br = s.size();
                ans[i][j] = Math.abs(tl - br);
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
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i, y = j;
                unordered_set<int> s;
                while (x > 0 && y > 0) {
                    s.insert(grid[--x][--y]);
                }
                int tl = s.size();
                x = i;
                y = j;
                s.clear();
                while (x < m - 1 && y < n - 1) {
                    s.insert(grid[++x][++y]);
                }
                int br = s.size();
                ans[i][j] = abs(tl - br);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func differenceOfDistinctValues(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	ans := make([][]int, m)
	for i := range grid {
		ans[i] = make([]int, n)
		for j := range grid[i] {
			x, y := i, j
			s := map[int]bool{}
			for x > 0 && y > 0 {
				x, y = x-1, y-1
				s[grid[x][y]] = true
			}
			tl := len(s)
			x, y = i, j
			s = map[int]bool{}
			for x+1 < m && y+1 < n {
				x, y = x+1, y+1
				s[grid[x][y]] = true
			}
			br := len(s)
			ans[i][j] = abs(tl - br)
		}
	}
	return ans
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
function differenceOfDistinctValues(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const ans: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let [x, y] = [i, j];
            const s = new Set<number>();
            while (x && y) {
                s.add(grid[--x][--y]);
            }
            const tl = s.size;
            [x, y] = [i, j];
            s.clear();
            while (x + 1 < m && y + 1 < n) {
                s.add(grid[++x][++y]);
            }
            const br = s.size;
            ans[i][j] = Math.abs(tl - br);
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

<p>给你一个下标从 <code>0</code> 开始、大小为 <code>m x n</code> 的二维矩阵 <code>grid</code> ，请你求解大小同样为 <code>m x n</code> 的答案矩阵 <code>answer</code> 。</p>

<p>矩阵 <code>answer</code> 中每个单元格 <code>(r, c)</code> 的值可以按下述方式进行计算：</p>

<ul>
	<li>令 <code>topLeft[r][c]</code> 为矩阵 <code>grid</code> 中单元格 <code>(r, c)</code> 左上角对角线上 <strong>不同值</strong> 的数量。</li>
	<li>令 <code>bottomRight[r][c]</code> 为矩阵 <code>grid</code> 中单元格 <code>(r, c)</code> 右下角对角线上 <strong>不同值</strong> 的数量。</li>
</ul>

<p>然后 <code>answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|</code> 。</p>

<p>返回矩阵 <code>answer</code> 。</p>

<p><strong>矩阵对角线</strong> 是从最顶行或最左列的某个单元格开始，向右下方向走到矩阵末尾的对角线。</p>

<p>如果单元格 <code>(r1, c1)</code> 和单元格 <code>(r, c) </code>属于同一条对角线且 <code>r1 &lt; r</code> ，则单元格 <code>(r1, c1)</code> 属于单元格 <code>(r, c)</code> 的左上对角线。类似地，可以定义右下对角线。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2711.Difference%20of%20Number%20of%20Distinct%20Values%20on%20Diagonals/images/ex2.png" style="width: 786px; height: 121px;" />
<pre>
<strong>输入：</strong>grid = [[1,2,3],[3,1,5],[3,2,1]]
<strong>输出：</strong>[[1,1,0],[1,0,1],[0,1,1]]
<strong>解释：</strong>第 1 个图表示最初的矩阵 grid 。&nbsp;
第 2 个图表示对单元格 (0,0) 计算，其中蓝色单元格是位于右下对角线的单元格。
第 3 个图表示对单元格 (1,2) 计算，其中红色单元格是位于左上对角线的单元格。
第 4 个图表示对单元格 (1,1) 计算，其中蓝色单元格是位于右下对角线的单元格，红色单元格是位于左上对角线的单元格。
- 单元格 (0,0) 的右下对角线包含 [1,1] ，而左上对角线包含 [] 。对应答案是 |1 - 0| = 1 。
- 单元格 (1,2) 的右下对角线包含 [] ，而左上对角线包含 [2] 。对应答案是 |0 - 1| = 1 。
- 单元格 (1,1) 的右下对角线包含 [1] ，而左上对角线包含 [1] 。对应答案是 |1 - 1| = 0 。
其他单元格的对应答案也可以按照这样的流程进行计算。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1]]
<strong>输出：</strong>[[0]]
<strong>解释：</strong>- 单元格 (0,0) 的右下对角线包含 [] ，左上对角线包含 [] 。对应答案是 |0 - 0| = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n, grid[i][j] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以按照题目描述的流程模拟，计算出每个单元格的左上角对角线上不同值的数量 $tl$ 和右下角对角线上不同值的数量 $br$，然后计算它们的差值 $|tl - br|$。

时间复杂度 $O(m \times n \times \min(m, n))$，空间复杂度 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x, y = i, j
                s = set()
                while x and y:
                    x, y = x - 1, y - 1
                    s.add(grid[x][y])
                tl = len(s)
                x, y = i, j
                s = set()
                while x + 1 < m and y + 1 < n:
                    x, y = x + 1, y + 1
                    s.add(grid[x][y])
                br = len(s)
                ans[i][j] = abs(tl - br)
        return ans
```

#### Java

```java
class Solution {
    public int[][] differenceOfDistinctValues(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i, y = j;
                Set<Integer> s = new HashSet<>();
                while (x > 0 && y > 0) {
                    s.add(grid[--x][--y]);
                }
                int tl = s.size();
                x = i;
                y = j;
                s.clear();
                while (x < m - 1 && y < n - 1) {
                    s.add(grid[++x][++y]);
                }
                int br = s.size();
                ans[i][j] = Math.abs(tl - br);
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
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i, y = j;
                unordered_set<int> s;
                while (x > 0 && y > 0) {
                    s.insert(grid[--x][--y]);
                }
                int tl = s.size();
                x = i;
                y = j;
                s.clear();
                while (x < m - 1 && y < n - 1) {
                    s.insert(grid[++x][++y]);
                }
                int br = s.size();
                ans[i][j] = abs(tl - br);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func differenceOfDistinctValues(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	ans := make([][]int, m)
	for i := range grid {
		ans[i] = make([]int, n)
		for j := range grid[i] {
			x, y := i, j
			s := map[int]bool{}
			for x > 0 && y > 0 {
				x, y = x-1, y-1
				s[grid[x][y]] = true
			}
			tl := len(s)
			x, y = i, j
			s = map[int]bool{}
			for x+1 < m && y+1 < n {
				x, y = x+1, y+1
				s[grid[x][y]] = true
			}
			br := len(s)
			ans[i][j] = abs(tl - br)
		}
	}
	return ans
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
function differenceOfDistinctValues(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const ans: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let [x, y] = [i, j];
            const s = new Set<number>();
            while (x && y) {
                s.add(grid[--x][--y]);
            }
            const tl = s.size;
            [x, y] = [i, j];
            s.clear();
            while (x + 1 < m && y + 1 < n) {
                s.add(grid[++x][++y]);
            }
            const br = s.size;
            ans[i][j] = Math.abs(tl - br);
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

# [2712. 使所有字符相等的最小成本](https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal){#2712}

{{< tabs "2712" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(1, n):
            if s[i] != s[i - 1]:
                ans += min(i, n - i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumCost(String s) {
        long ans = 0;
        int n = s.length();
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(i, n - i);
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
    long long minimumCost(string s) {
        long long ans = 0;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                ans += min(i, n - i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(s string) (ans int64) {
	n := len(s)
	for i := 1; i < n; i++ {
		if s[i] != s[i-1] {
			ans += int64(min(i, n-i))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(s: string): number {
    let ans = 0;
    const n = s.length;
    for (let i = 1; i < n; ++i) {
        if (s[i] !== s[i - 1]) {
            ans += Math.min(i, n - i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_cost(s: String) -> i64 {
        let mut ans = 0;
        let n = s.len();
        let s = s.as_bytes();
        for i in 1..n {
            if s[i] != s[i - 1] {
                ans += i.min(n - i);
            }
        }
        ans as i64
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的二进制字符串 <code>s</code> ，你可以对其执行两种操作：</p>

<ul>
	<li>选中一个下标 <code>i</code> 并且反转从下标 <code>0</code> 到下标 <code>i</code>（包括下标 <code>0</code> 和下标 <code>i</code> ）的所有字符，成本为 <code>i + 1</code> 。</li>
	<li>选中一个下标 <code>i</code> 并且反转从下标 <code>i</code> 到下标 <code>n - 1</code>（包括下标 <code>i</code> 和下标 <code>n - 1</code> ）的所有字符，成本为 <code>n - i</code> 。</li>
</ul>

<p>返回使字符串内所有字符 <strong>相等</strong> 需要的 <strong>最小成本</strong> 。</p>

<p><strong>反转</strong> 字符意味着：如果原来的值是 '0' ，则反转后值变为 '1' ，反之亦然。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "0011"
<strong>输出：</strong>2
<strong>解释：</strong>执行第二种操作，选中下标 <code>i = 2</code> ，可以得到 <code>s = "0000" ，成本为 2</code> 。可以证明 2 是使所有字符相等的最小成本。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "010101"
<strong>输出：</strong>9
<strong>解释：</strong>执行第一种操作，选中下标 i = 2 ，可以得到 s = "101101" ，成本为 3 。
执行第一种操作，选中下标 i = 1 ，可以得到 s = "011101" ，成本为 2 。
执行第一种操作，选中下标 i = 0 ，可以得到 s = "111101" ，成本为 1 。
执行第二种操作，选中下标 i = 4 ，可以得到 s = "111110" ，成本为 2 。
执行第二种操作，选中下标 i = 5 ，可以得到 s = "111111" ，成本为 1 。
使所有字符相等的总成本等于 9 。可以证明 9 是使所有字符相等的最小成本。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，如果 $s[i] \neq s[i - 1]$，那么一定要执行操作，否则无法使所有字符相等。

我们要么选择将 $s[0..i-1]$ 的字符全部反转，反转的成本为 $i$；要么选择将 $s[i..n-1]$ 的字符全部反转，反转的成本为 $n - i$。取两者中的最小值即可。

我们遍历字符串 $s$，将所有需要反转的字符的成本相加，即可得到最小成本。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(1, n):
            if s[i] != s[i - 1]:
                ans += min(i, n - i)
        return ans
```

#### Java

```java
class Solution {
    public long minimumCost(String s) {
        long ans = 0;
        int n = s.length();
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(i, n - i);
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
    long long minimumCost(string s) {
        long long ans = 0;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                ans += min(i, n - i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumCost(s string) (ans int64) {
	n := len(s)
	for i := 1; i < n; i++ {
		if s[i] != s[i-1] {
			ans += int64(min(i, n-i))
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumCost(s: string): number {
    let ans = 0;
    const n = s.length;
    for (let i = 1; i < n; ++i) {
        if (s[i] !== s[i - 1]) {
            ans += Math.min(i, n - i);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_cost(s: String) -> i64 {
        let mut ans = 0;
        let n = s.len();
        let s = s.as_bytes();
        for i in 1..n {
            if s[i] != s[i - 1] {
                ans += i.min(n - i);
            }
        }
        ans as i64
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix){#2713}

{{< tabs "2713" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxIncreasingCells(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        g = defaultdict(list)
        for i in range(m):
            for j in range(n):
                g[mat[i][j]].append((i, j))
        rowMax = [0] * m
        colMax = [0] * n
        ans = 0
        for _, pos in sorted(g.items()):
            mx = []
            for i, j in pos:
                mx.append(1 + max(rowMax[i], colMax[j]))
                ans = max(ans, mx[-1])
            for k, (i, j) in enumerate(pos):
                rowMax[i] = max(rowMax[i], mx[k])
                colMax[j] = max(colMax[j], mx[k])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxIncreasingCells(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        TreeMap<Integer, List<int[]>> g = new TreeMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g.computeIfAbsent(mat[i][j], k -> new ArrayList<>()).add(new int[] {i, j});
            }
        }
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int ans = 0;
        for (var e : g.entrySet()) {
            var pos = e.getValue();
            int[] mx = new int[pos.size()];
            int k = 0;
            for (var p : pos) {
                int i = p[0], j = p[1];
                mx[k] = Math.max(rowMax[i], colMax[j]) + 1;
                ans = Math.max(ans, mx[k++]);
            }
            for (k = 0; k < mx.length; ++k) {
                int i = pos.get(k)[0], j = pos.get(k)[1];
                rowMax[i] = Math.max(rowMax[i], mx[k]);
                colMax[j] = Math.max(colMax[j], mx[k]);
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
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[mat[i][j]].emplace_back(i, j);
            }
        }
        vector<int> rowMax(m);
        vector<int> colMax(n);
        int ans = 0;
        for (auto& [_, pos] : g) {
            vector<int> mx;
            for (auto& [i, j] : pos) {
                mx.push_back(max(rowMax[i], colMax[j]) + 1);
                ans = max(ans, mx.back());
            }
            for (int k = 0; k < mx.size(); ++k) {
                auto& [i, j] = pos[k];
                rowMax[i] = max(rowMax[i], mx[k]);
                colMax[j] = max(colMax[j], mx[k]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxIncreasingCells(mat [][]int) (ans int) {
	m, n := len(mat), len(mat[0])
	g := map[int][][2]int{}
	for i, row := range mat {
		for j, v := range row {
			g[v] = append(g[v], [2]int{i, j})
		}
	}
	nums := make([]int, 0, len(g))
	for k := range g {
		nums = append(nums, k)
	}
	sort.Ints(nums)
	rowMax := make([]int, m)
	colMax := make([]int, n)
	for _, k := range nums {
		pos := g[k]
		mx := make([]int, len(pos))
		for i, p := range pos {
			mx[i] = max(rowMax[p[0]], colMax[p[1]]) + 1
			ans = max(ans, mx[i])
		}
		for i, p := range pos {
			rowMax[p[0]] = max(rowMax[p[0]], mx[i])
			colMax[p[1]] = max(colMax[p[1]], mx[i])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxIncreasingCells(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const g: { [key: number]: [number, number][] } = {};

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!g[mat[i][j]]) {
                g[mat[i][j]] = [];
            }
            g[mat[i][j]].push([i, j]);
        }
    }

    const rowMax = Array(m).fill(0);
    const colMax = Array(n).fill(0);
    let ans = 0;

    const sortedKeys = Object.keys(g)
        .map(Number)
        .sort((a, b) => a - b);

    for (const key of sortedKeys) {
        const pos = g[key];
        const mx: number[] = [];

        for (const [i, j] of pos) {
            mx.push(1 + Math.max(rowMax[i], colMax[j]));
            ans = Math.max(ans, mx[mx.length - 1]);
        }

        for (let k = 0; k < pos.length; k++) {
            const [i, j] = pos[k];
            rowMax[i] = Math.max(rowMax[i], mx[k]);
            colMax[j] = Math.max(colMax[j], mx[k]);
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

<p>给你一个下标从 <strong>1</strong> 开始、大小为 <code>m x n</code> 的整数矩阵 <code>mat</code>，你可以选择任一单元格作为 <strong>起始单元格</strong> 。</p>

<p>从起始单元格出发，你可以移动到 <strong>同一行或同一列</strong> 中的任何其他单元格，但前提是目标单元格的值<strong> 严格大于 </strong>当前单元格的值。</p>

<p>你可以多次重复这一过程，从一个单元格移动到另一个单元格，直到无法再进行任何移动。</p>

<p>请你找出从某个单元开始访问矩阵所能访问的 <strong>单元格的最大数量</strong> 。</p>

<p>返回一个表示可访问单元格最大数量的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2713.Maximum%20Strictly%20Increasing%20Cells%20in%20a%20Matrix/images/diag1drawio.png" style="width: 200px; height: 176px;"></strong></p>

<pre><strong>输入：</strong>mat = [[3,1],[3,4]]
<strong>输出：</strong>2
<strong>解释：</strong>上图展示了从第 1 行、第 2 列的单元格开始，可以访问 2 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 2 个单元格，因此答案是 2 。 
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2713.Maximum%20Strictly%20Increasing%20Cells%20in%20a%20Matrix/images/diag3drawio.png" style="width: 200px; height: 176px;"></strong></p>

<pre><strong>输入：</strong>mat = [[1,1],[1,1]]
<strong>输出：</strong>1
<strong>解释：</strong>由于目标单元格必须严格大于当前单元格，在本示例中只能访问 1 个单元格。 
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2713.Maximum%20Strictly%20Increasing%20Cells%20in%20a%20Matrix/images/diag4drawio.png" style="width: 350px; height: 250px;"></strong></p>

<pre><strong>输入：</strong>mat = [[3,1,6],[-9,5,7]]
<strong>输出：</strong>4
<strong>解释：</strong>上图展示了从第 2 行、第 1 列的单元格开始，可以访问 4 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 4 个单元格，因此答案是 4 。  
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length&nbsp;</code></li>
	<li><code>n == mat[i].length&nbsp;</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 动态规划

根据题目描述，我们顺序移动的单元格的值必须严格递增，因此，我们不妨用一个哈希表 $g$ 来记录每个值对应的所有单元格的位置，然后按照值的大小从小到大遍历。

在这个过程中，我们可以维护两个数组 `rowMax` 和 `colMax`，分别记录每一行和每一列的最大递增长度。初始时，这两个数组的所有元素都为 $0$。

对于每个值对应的所有单元格位置，我们按照位置顺序遍历，对于每个位置 $(i, j)$，我们可以计算出以该位置为终点的最大递增长度为 $1 + \max(\textit{rowMax}[i], \textit{colMax}[j])$，更新答案，然后更新 `rowMax[i]` 和 `colMax[j]`。

最后返回答案即可。

时间复杂度 $O(m \times n \times \log(m \times n))$，空间复杂度 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxIncreasingCells(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        g = defaultdict(list)
        for i in range(m):
            for j in range(n):
                g[mat[i][j]].append((i, j))
        rowMax = [0] * m
        colMax = [0] * n
        ans = 0
        for _, pos in sorted(g.items()):
            mx = []
            for i, j in pos:
                mx.append(1 + max(rowMax[i], colMax[j]))
                ans = max(ans, mx[-1])
            for k, (i, j) in enumerate(pos):
                rowMax[i] = max(rowMax[i], mx[k])
                colMax[j] = max(colMax[j], mx[k])
        return ans
```

#### Java

```java
class Solution {
    public int maxIncreasingCells(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        TreeMap<Integer, List<int[]>> g = new TreeMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g.computeIfAbsent(mat[i][j], k -> new ArrayList<>()).add(new int[] {i, j});
            }
        }
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int ans = 0;
        for (var e : g.entrySet()) {
            var pos = e.getValue();
            int[] mx = new int[pos.size()];
            int k = 0;
            for (var p : pos) {
                int i = p[0], j = p[1];
                mx[k] = Math.max(rowMax[i], colMax[j]) + 1;
                ans = Math.max(ans, mx[k++]);
            }
            for (k = 0; k < mx.length; ++k) {
                int i = pos.get(k)[0], j = pos.get(k)[1];
                rowMax[i] = Math.max(rowMax[i], mx[k]);
                colMax[j] = Math.max(colMax[j], mx[k]);
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
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[mat[i][j]].emplace_back(i, j);
            }
        }
        vector<int> rowMax(m);
        vector<int> colMax(n);
        int ans = 0;
        for (auto& [_, pos] : g) {
            vector<int> mx;
            for (auto& [i, j] : pos) {
                mx.push_back(max(rowMax[i], colMax[j]) + 1);
                ans = max(ans, mx.back());
            }
            for (int k = 0; k < mx.size(); ++k) {
                auto& [i, j] = pos[k];
                rowMax[i] = max(rowMax[i], mx[k]);
                colMax[j] = max(colMax[j], mx[k]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxIncreasingCells(mat [][]int) (ans int) {
	m, n := len(mat), len(mat[0])
	g := map[int][][2]int{}
	for i, row := range mat {
		for j, v := range row {
			g[v] = append(g[v], [2]int{i, j})
		}
	}
	nums := make([]int, 0, len(g))
	for k := range g {
		nums = append(nums, k)
	}
	sort.Ints(nums)
	rowMax := make([]int, m)
	colMax := make([]int, n)
	for _, k := range nums {
		pos := g[k]
		mx := make([]int, len(pos))
		for i, p := range pos {
			mx[i] = max(rowMax[p[0]], colMax[p[1]]) + 1
			ans = max(ans, mx[i])
		}
		for i, p := range pos {
			rowMax[p[0]] = max(rowMax[p[0]], mx[i])
			colMax[p[1]] = max(colMax[p[1]], mx[i])
		}
	}
	return
}
```

#### TypeScript

```ts
function maxIncreasingCells(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const g: { [key: number]: [number, number][] } = {};

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!g[mat[i][j]]) {
                g[mat[i][j]] = [];
            }
            g[mat[i][j]].push([i, j]);
        }
    }

    const rowMax = Array(m).fill(0);
    const colMax = Array(n).fill(0);
    let ans = 0;

    const sortedKeys = Object.keys(g)
        .map(Number)
        .sort((a, b) => a - b);

    for (const key of sortedKeys) {
        const pos = g[key];
        const mx: number[] = [];

        for (const [i, j] of pos) {
            mx.push(1 + Math.max(rowMax[i], colMax[j]));
            ans = Math.max(ans, mx[mx.length - 1]);
        }

        for (let k = 0; k < pos.length; k++) {
            const [i, j] = pos[k];
            rowMax[i] = Math.max(rowMax[i], mx[k]);
            colMax[j] = Math.max(colMax[j], mx[k]);
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

# [2714. 找到 K 次跨越的最短路径 🔒](https://leetcode.cn/problems/find-shortest-path-with-k-hops){#2714}

{{< tabs "2714" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestPathWithHops(
        self, n: int, edges: List[List[int]], s: int, d: int, k: int
    ) -> int:
        g = [[] for _ in range(n)]
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        dist = [[inf] * (k + 1) for _ in range(n)]
        dist[s][0] = 0
        pq = [(0, s, 0)]
        while pq:
            dis, u, t = heappop(pq)
            for v, w in g[u]:
                if t + 1 <= k and dist[v][t + 1] > dis:
                    dist[v][t + 1] = dis
                    heappush(pq, (dis, v, t + 1))
                if dist[v][t] > dis + w:
                    dist[v][t] = dis + w
                    heappush(pq, (dis + w, v, t))
        return int(min(dist[d]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestPathWithHops(int n, int[][] edges, int s, int d, int k) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, s, 0});
        int[][] dist = new int[n][k + 1];
        final int inf = 1 << 30;
        for (int[] e : dist) {
            Arrays.fill(e, inf);
        }
        dist[s][0] = 0;
        while (!pq.isEmpty()) {
            int[] p = pq.poll();
            int dis = p[0], u = p[1], t = p[2];
            for (int[] e : g[u]) {
                int v = e[0], w = e[1];
                if (t + 1 <= k && dist[v][t + 1] > dis) {
                    dist[v][t + 1] = dis;
                    pq.offer(new int[] {dis, v, t + 1});
                }
                if (dist[v][t] > dis + w) {
                    dist[v][t] = dis + w;
                    pq.offer(new int[] {dis + w, v, t});
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= k; ++i) {
            ans = Math.min(ans, dist[d][i]);
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
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<pair<int, int>> g[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, s, 0);
        int dist[n][k + 1];
        memset(dist, 0x3f, sizeof(dist));
        dist[s][0] = 0;
        while (!pq.empty()) {
            auto [dis, u, t] = pq.top();
            pq.pop();
            for (auto [v, w] : g[u]) {
                if (t + 1 <= k && dist[v][t + 1] > dis) {
                    dist[v][t + 1] = dis;
                    pq.emplace(dis, v, t + 1);
                }
                if (dist[v][t] > dis + w) {
                    dist[v][t] = dis + w;
                    pq.emplace(dis + w, v, t);
                }
            }
        }
        return *min_element(dist[d], dist[d] + k + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPathWithHops(n int, edges [][]int, s int, d int, k int) int {
	g := make([][][2]int, n)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u] = append(g[u], [2]int{v, w})
		g[v] = append(g[v], [2]int{u, w})
	}
	pq := hp{{0, s, 0}}
	dist := make([][]int, n)
	for i := range dist {
		dist[i] = make([]int, k+1)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
		}
	}
	dist[s][0] = 0
	for len(pq) > 0 {
		p := heap.Pop(&pq).(tuple)
		dis, u, t := p.dis, p.u, p.t
		for _, e := range g[u] {
			v, w := e[0], e[1]
			if t+1 <= k && dist[v][t+1] > dis {
				dist[v][t+1] = dis
				heap.Push(&pq, tuple{dis, v, t + 1})
			}
			if dist[v][t] > dis+w {
				dist[v][t] = dis + w
				heap.Push(&pq, tuple{dis + w, v, t})
			}
		}
	}
	return slices.Min(dist[d])
}

type tuple struct{ dis, u, t int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个正整数 n ，它表示一个<strong>&nbsp;索引从 0 开始的无向带权连接图</strong> 的节点数，以及一个&nbsp;<strong>索引从 0 开始的二维数组&nbsp;</strong><code>edges</code> ，其中 <code>edges[i] = [ui, vi, wi]</code> 表示节点 <code>ui</code> 和 <code>vi</code> 之间存在权重为 <code>wi</code> 的边。</p>

<p>还给定两个节点 <code>s</code> 和 <code>d</code> ，以及一个正整数 <code>k</code> ，你的任务是找到从 s 到 d 的 <strong>最短 </strong>路径，但你可以 <strong>最多</strong> 跨越 <code>k</code> 条边。换句话说，将 <strong>最多</strong> <code>k</code> 条边的权重设为 <code>0</code>，然后找到从 <code>s</code> 到 <code>d</code> 的 <strong>最短</strong> 路径。</p>

<p>返回满足给定条件的从 <code>s</code> 到 <code>d</code> 的 <strong>最短</strong> 路径的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 4, edges = [[0,1,4],[0,2,2],[2,3,6]], s = 1, d = 3, k = 2
<b>输出：</b>2
<b>解释：</b>在这个例子中，只有一条从节点1（绿色节点）到节点3（红色节点）的路径，即（1-&gt;0-&gt;2-&gt;3），其长度为4 + 2 + 6 = 12。现在我们可以将两条边的权重设为 0，即将蓝色边的权重设为 0，那么路径的长度就变为 0 + 2 + 0 = 2。可以证明 2 是我们在给定条件下能够达到的最小路径长度。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2714.Find%20Shortest%20Path%20with%20K%20Hops/images/1.jpg" style="width: 170px; height: 171px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 7, edges = [[3,1,9],[3,2,4],[4,0,9],[0,5,6],[3,6,2],[6,0,4],[1,2,4]], s = 4, d = 1, k = 2
<b>输出：</b>6
<b>解释：</b>在这个例子中，有两条从节点4（绿色节点）到节点1（红色节点）的路径，分别是（4-&gt;0-&gt;6-&gt;3-&gt;2-&gt;1）和（4-&gt;0-&gt;6-&gt;3-&gt;1）。第一条路径的长度为 9 + 4 + 2 + 4 + 4 = 23，第二条路径的长度为 9 + 4 + 2 + 9 = 24。现在，如果我们将蓝色边的权重设为 0，那么最短路径的长度就变为 0 + 4 + 2 + 0 = 6。可以证明 6 是我们在给定条件下能够达到的最小路径长度。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2714.Find%20Shortest%20Path%20with%20K%20Hops/images/2.jpg" style="width: 400px; height: 171px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 5, edges = [[0,4,2],[0,1,3],[0,2,1],[2,1,4],[1,3,4],[3,4,7]], s = 2, d = 3, k = 1
<b>输出：</b>3
<b>解释：</b>在这个例子中，从节点2（绿色节点）到节点3（红色节点）有4条路径，分别是（2-&gt;1-&gt;3）、（2-&gt;0-&gt;1-&gt;3）、（2-&gt;1-&gt;0-&gt;4-&gt;3）和（2-&gt;0-&gt;4-&gt;3）。前两条路径的长度为4 + 4 = 1 + 3 + 4 = 8，第三条路径的长度为4 + 3 + 2 + 7 = 16，最后一条路径的长度为1 + 2 + 7 = 10。现在，如果我们将蓝色边的权重设为 0，那么最短路径的长度就为1 + 2 + 0 = 3。可以证明在给定条件下，3 是我们能够达到的最小路径长度。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2714.Find%20Shortest%20Path%20with%20K%20Hops/images/3.jpg" style="width: 300px; height: 296px;" /></p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>n - 1 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length = 3</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li><code>1 &lt;= edges[i][2] &lt;=&nbsp;10<sup>6</sup></code></li>
	<li><code>0 &lt;= s, d, k&nbsp;&lt;= n - 1</code></li>
	<li><code>s != d</code></li>
	<li>输入的生成确保图是 <strong>连通</strong> 的，并且没有 <strong>重复的边</strong> 或 <strong>自环</strong>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Dijkstra 算法

我们先根据给定的边构造出图 $g$，其中 $g[u]$ 表示节点 $u$ 的所有邻居节点以及对应的边权重。

然后我们使用 Dijkstra 算法求出从节点 $s$ 到节点 $d$ 的最短路径，但是在这里我们需要对 Dijkstra 算法进行一些修改：

-   我们需要记录每个节点 $u$ 到节点 $d$ 的最短路径长度，但是由于我们可以最多跨越 $k$ 条边，所以我们需要记录每个节点 $u$ 到节点 $d$ 的最短路径长度，以及跨越的边数 $t$，即 $dist[u][t]$ 表示从节点 $u$ 到节点 $d$ 的最短路径长度，且跨越的边数为 $t$。
-   我们需要使用优先队列来维护当前的最短路径，但是由于我们需要记录跨越的边数，所以我们需要使用三元组 $(dis, u, t)$ 来表示当前的最短路径，其中 $dis$ 表示当前的最短路径长度，而 $u$ 和 $t$ 分别表示当前的节点和跨越的边数。

最后我们只需要返回 $dist[d][0..k]$ 中的最小值即可。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n \times k)$。其中 $n$ 表示节点数，而 $k$ 表示最多跨越的边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPathWithHops(
        self, n: int, edges: List[List[int]], s: int, d: int, k: int
    ) -> int:
        g = [[] for _ in range(n)]
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        dist = [[inf] * (k + 1) for _ in range(n)]
        dist[s][0] = 0
        pq = [(0, s, 0)]
        while pq:
            dis, u, t = heappop(pq)
            for v, w in g[u]:
                if t + 1 <= k and dist[v][t + 1] > dis:
                    dist[v][t + 1] = dis
                    heappush(pq, (dis, v, t + 1))
                if dist[v][t] > dis + w:
                    dist[v][t] = dis + w
                    heappush(pq, (dis + w, v, t))
        return int(min(dist[d]))
```

#### Java

```java
class Solution {
    public int shortestPathWithHops(int n, int[][] edges, int s, int d, int k) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, s, 0});
        int[][] dist = new int[n][k + 1];
        final int inf = 1 << 30;
        for (int[] e : dist) {
            Arrays.fill(e, inf);
        }
        dist[s][0] = 0;
        while (!pq.isEmpty()) {
            int[] p = pq.poll();
            int dis = p[0], u = p[1], t = p[2];
            for (int[] e : g[u]) {
                int v = e[0], w = e[1];
                if (t + 1 <= k && dist[v][t + 1] > dis) {
                    dist[v][t + 1] = dis;
                    pq.offer(new int[] {dis, v, t + 1});
                }
                if (dist[v][t] > dis + w) {
                    dist[v][t] = dis + w;
                    pq.offer(new int[] {dis + w, v, t});
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= k; ++i) {
            ans = Math.min(ans, dist[d][i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<pair<int, int>> g[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, s, 0);
        int dist[n][k + 1];
        memset(dist, 0x3f, sizeof(dist));
        dist[s][0] = 0;
        while (!pq.empty()) {
            auto [dis, u, t] = pq.top();
            pq.pop();
            for (auto [v, w] : g[u]) {
                if (t + 1 <= k && dist[v][t + 1] > dis) {
                    dist[v][t + 1] = dis;
                    pq.emplace(dis, v, t + 1);
                }
                if (dist[v][t] > dis + w) {
                    dist[v][t] = dis + w;
                    pq.emplace(dis + w, v, t);
                }
            }
        }
        return *min_element(dist[d], dist[d] + k + 1);
    }
};
```

#### Go

```go
func shortestPathWithHops(n int, edges [][]int, s int, d int, k int) int {
	g := make([][][2]int, n)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u] = append(g[u], [2]int{v, w})
		g[v] = append(g[v], [2]int{u, w})
	}
	pq := hp{{0, s, 0}}
	dist := make([][]int, n)
	for i := range dist {
		dist[i] = make([]int, k+1)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
		}
	}
	dist[s][0] = 0
	for len(pq) > 0 {
		p := heap.Pop(&pq).(tuple)
		dis, u, t := p.dis, p.u, p.t
		for _, e := range g[u] {
			v, w := e[0], e[1]
			if t+1 <= k && dist[v][t+1] > dis {
				dist[v][t+1] = dis
				heap.Push(&pq, tuple{dis, v, t + 1})
			}
			if dist[v][t] > dis+w {
				dist[v][t] = dis + w
				heap.Push(&pq, tuple{dis + w, v, t})
			}
		}
	}
	return slices.Min(dist[d])
}

type tuple struct{ dis, u, t int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2715. 执行可取消的延迟函数](https://leetcode.cn/problems/timeout-cancellation){#2715}

{{< tabs "2715" >}}

{{% tab "ts" %}}
```ts
function cancellable(fn: Function, args: any[], t: number): Function {
    const timer = setTimeout(() => fn(...args), t);
    return () => {
        clearTimeout(timer);
    };
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 5
 *  const args = [2], t = 20, cancelT = 50
 *
 *  const start = performance.now()
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelT)
 *
 *  setTimeout(() => {
 *     cancel()
 *  }, cancelT)
 *
 *  setTimeout(() => {
 *     console.log(result) // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function (fn, args, t) {
    const timer = setTimeout(() => fn(...args), t);
    return () => {
        clearTimeout(timer);
    };
};

/**
 *  const result = []
 *
 *  const fn = (x) => x * 5
 *  const args = [2], t = 20, cancelT = 50
 *
 *  const start = performance.now()
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelT)
 *
 *  setTimeout(() => {
 *     cancel()
 *  }, cancelT)
 *
 *  setTimeout(() => {
 *     console.log(result) // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个函数 <code>fn</code>&nbsp;，一个参数数组 <code>args</code> 和一个以毫秒为单位的超时时间 <code>t</code> ，返回一个取消函数 <code>cancelFn</code> 。</p>

<p>在 <code>cancelTimeMs</code>&nbsp;的延迟后，返回的取消函数 <code>cancelFn</code> 将被调用。</p>

<pre>
setTimeout(cancelFn, cancelTimeMs)
</pre>

<p>最初，函数 <code>fn</code> 的执行应该延迟 <code>t</code> 毫秒。</p>

<p>如果在 <code>t</code> 毫秒的延迟之前调用了函数 <code>cancelFn</code>，它应该取消 <code>fn</code> 的延迟执行。否则，如果在指定的延迟 <code>t</code> 内没有调用 <code>cancelFn</code>，则应执行 <code>fn</code>，并使用提供的 <code>args</code> 作为参数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<b>输入：</b>fn = (x) =&gt; x * 5, args = [2], t = 20
<b>输出：</b>[{"time": 20, "returned": 10}]
<b>解释：</b>
const cancelTimeMs = 50;
const cancelFn = cancellable((x) =&gt; x * 5, [2], 20);
setTimeout(cancelFn, cancelTimeMs);

取消操作被安排在延迟了 cancelTimeMs（50毫秒）后进行，这发生在 fn(2) 在20毫秒时执行之后。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>fn = (x) =&gt; x**2, args = [2], t = 100
<b>输出：</b>[]
<b>解释：</b>
const cancelTimeMs = 50;
const cancelFn = cancellable((x) =&gt; x**2, [2], 100);
setTimeout(cancelFn, cancelTimeMs);

取消操作被安排在延迟了 cancelTimeMs（50毫秒）后进行，这发生在 fn(2) 在100毫秒时执行之前，导致 fn(2) 从未被调用。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>fn = (x1, x2) =&gt; x1 * x2, args = [2,4], t = 30
<b>输出：</b>[{"time": 30, "returned": 8}]
<b>解释：</b>
const cancelTimeMs = 100;
const cancelFn = cancellable((x1, x2) =&gt; x1 * x2, [2,4], 30);
setTimeout(cancelFn, cancelTimeMs);

取消操作被安排在延迟了 cancelTimeMs（100毫秒）后进行，这发生在 fn(2,4) 在30毫秒时执行之后。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>fn</code> 是一个函数</li>
	<li><code>args</code> 是一个有效的 JSON 数组</li>
	<li><code>1 &lt;= args.length &lt;= 10</code></li>
	<li><code><font face="monospace">20 &lt;= t &lt;= 1000</font></code></li>
	<li><code><font face="monospace">10 &lt;= cancelTimeMs&nbsp;&lt;= 1000</font></code></li>
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
function cancellable(fn: Function, args: any[], t: number): Function {
    const timer = setTimeout(() => fn(...args), t);
    return () => {
        clearTimeout(timer);
    };
}

/**
 *  const result = []
 *
 *  const fn = (x) => x * 5
 *  const args = [2], t = 20, cancelT = 50
 *
 *  const start = performance.now()
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelT)
 *
 *  setTimeout(() => {
 *     cancel()
 *  }, cancelT)
 *
 *  setTimeout(() => {
 *     console.log(result) // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */
```

#### JavaScript

```js
/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function (fn, args, t) {
    const timer = setTimeout(() => fn(...args), t);
    return () => {
        clearTimeout(timer);
    };
};

/**
 *  const result = []
 *
 *  const fn = (x) => x * 5
 *  const args = [2], t = 20, cancelT = 50
 *
 *  const start = performance.now()
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr))
 *  }
 *
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelT)
 *
 *  setTimeout(() => {
 *     cancel()
 *  }, cancelT)
 *
 *  setTimeout(() => {
 *     console.log(result) // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2716. 最小化字符串长度](https://leetcode.cn/problems/minimize-string-length){#2716}

{{< tabs "2716" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizedStringLength(self, s: str) -> int:
        return len(set(s))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizedStringLength(String s) {
        Set<Character> ss = new HashSet<>();
        for (int i = 0; i < s.length(); ++i) {
            ss.add(s.charAt(i));
        }
        return ss.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimizedStringLength(string s) {
        return unordered_set<char>(s.begin(), s.end()).size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizedStringLength(s string) int {
	ss := map[rune]struct{}{}
	for _, c := range s {
		ss[c] = struct{}{}
	}
	return len(ss)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizedStringLength(s: string): number {
    return new Set(s.split('')).size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn minimized_string_length(s: String) -> i32 {
        let ss: HashSet<char> = s.chars().collect();
        ss.len() as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimizedStringLength(string s) {
        return new HashSet<char>(s).Count;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，重复执行下述操作 <strong>任意</strong> 次：</p>

<ul>
	<li>在字符串中选出一个下标 <code>i</code> ，并使 <code>c</code> 为字符串下标 <code>i</code> 处的字符。并在 <code>i</code> <strong>左侧</strong>（如果有）和 <strong>右侧</strong>（如果有）各 <strong>删除 </strong>一个距离 <code>i</code> <strong>最近</strong> 的字符 <code>c</code> 。</li>
</ul>

<p>请你通过执行上述操作任意次，使 <code>s</code> 的长度 <strong>最小化</strong> 。</p>

<p>返回一个表示 <strong>最小化</strong> 字符串的长度的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabc"
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，s 等于 "aaabc" 。我们可以选择位于下标 1 处的字符 'a' 开始。接着删除下标 1 左侧最近的那个 'a'（位于下标 0）以及下标 1 右侧最近的那个 'a'（位于下标 2）。执行操作后，字符串变为 "abc" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "cbbd"
<strong>输出：</strong>3
<strong>解释：</strong>我们可以选择位于下标 1 处的字符 'b' 开始。下标 1 左侧不存在字符 'b' ，但右侧存在一个字符 'b'（位于下标 2），所以会删除位于下标 2 的字符 'b' 。执行操作后，字符串变为 "cbd" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 3 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "dddaaa"
<strong>输出：</strong>2
<strong>解释：</strong>我们可以选择位于下标 1 处的字符 'd' 开始。接着删除下标 1 左侧最近的那个 'd'（位于下标 0）以及下标 1 右侧最近的那个 'd'（位于下标 2）。执行操作后，字符串变为 "daaa" 。继续对新字符串执行操作，可以选择位于下标 2 的字符 'a' 。接着删除下标 2 左侧最近的那个 'a'（位于下标 1）以及下标 2 右侧最近的那个 'a'（位于下标 3）。执行操作后，字符串变为 "da" 。继续对字符串执行任何操作都不会改变其长度。因此，最小化字符串的长度是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

题目实际上可以转化为求字符串中不同字符的个数，因此，我们只需要统计字符串中不同字符的个数即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $\textit{s}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，这里是小写英文字母，因此 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizedStringLength(self, s: str) -> int:
        return len(set(s))
```

#### Java

```java
class Solution {
    public int minimizedStringLength(String s) {
        Set<Character> ss = new HashSet<>();
        for (int i = 0; i < s.length(); ++i) {
            ss.add(s.charAt(i));
        }
        return ss.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimizedStringLength(string s) {
        return unordered_set<char>(s.begin(), s.end()).size();
    }
};
```

#### Go

```go
func minimizedStringLength(s string) int {
	ss := map[rune]struct{}{}
	for _, c := range s {
		ss[c] = struct{}{}
	}
	return len(ss)
}
```

#### TypeScript

```ts
function minimizedStringLength(s: string): number {
    return new Set(s.split('')).size;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn minimized_string_length(s: String) -> i32 {
        let ss: HashSet<char> = s.chars().collect();
        ss.len() as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int MinimizedStringLength(string s) {
        return new HashSet<char>(s).Count;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2717. 半有序排列](https://leetcode.cn/problems/semi-ordered-permutation){#2717}

{{< tabs "2717" >}}

{{% tab "python" %}}
```python
class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        i = nums.index(1)
        j = nums.index(n)
        k = 1 if i < j else 2
        return i + n - j - k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] == 1) {
                i = k;
            }
            if (nums[k] == n) {
                j = k;
            }
        }
        int k = i < j ? 1 : 2;
        return i + n - j - k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = find(nums.begin(), nums.end(), 1) - nums.begin();
        int j = find(nums.begin(), nums.end(), n) - nums.begin();
        int k = i < j ? 1 : 2;
        return i + n - j - k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func semiOrderedPermutation(nums []int) int {
	n := len(nums)
	var i, j int
	for k, x := range nums {
		if x == 1 {
			i = k
		}
		if x == n {
			j = k
		}
	}
	k := 1
	if i > j {
		k = 2
	}
	return i + n - j - k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function semiOrderedPermutation(nums: number[]): number {
    const n = nums.length;
    const i = nums.indexOf(1);
    const j = nums.indexOf(n);
    const k = i < j ? 1 : 2;
    return i + n - j - k;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn semi_ordered_permutation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let (mut i, mut j) = (0, 0);

        for k in 0..n {
            if nums[k] == 1 {
                i = k;
            }
            if nums[k] == (n as i32) {
                j = k;
            }
        }

        let k = if i < j { 1 } else { 2 };
        (i + n - j - k) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数排列 <code>nums</code> 。</p>

<p>如果排列的第一个数字等于 <code>1</code> 且最后一个数字等于 <code>n</code> ，则称其为 <strong>半有序排列</strong> 。你可以执行多次下述操作，直到将 <code>nums</code> 变成一个 <strong>半有序排列</strong> ：</p>

<ul>
	<li>选择 <code>nums</code> 中相邻的两个元素，然后交换它们。</li>
</ul>

<p>返回使 <code>nums</code> 变成 <strong>半有序排列</strong> 所需的最小操作次数。</p>

<p><strong>排列</strong> 是一个长度为 <code>n</code> 的整数序列，其中包含从 <code>1</code> 到 <code>n</code> 的每个数字恰好一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,4,3]
<strong>输出：</strong>2
<strong>解释：</strong>可以依次执行下述操作得到半有序排列：
1 - 交换下标 0 和下标 1 对应元素。排列变为 [1,2,4,3] 。
2 - 交换下标 2 和下标 3 对应元素。排列变为 [1,2,3,4] 。
可以证明，要让 nums 成为半有序排列，不存在执行操作少于 2 次的方案。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,1,3]
<strong>输出：</strong>3
<strong>解释：
</strong>可以依次执行下述操作得到半有序排列：
1 - 交换下标 1 和下标 2 对应元素。排列变为 [2,1,4,3] 。
2 - 交换下标 0 和下标 1 对应元素。排列变为 [1,2,4,3] 。
3 - 交换下标 2 和下标 3 对应元素。排列变为 [1,2,3,4] 。
可以证明，要让 nums 成为半有序排列，不存在执行操作少于 3 次的方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,4,2,5]
<strong>输出：</strong>0
<strong>解释：</strong>这个排列已经是一个半有序排列，无需执行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i]&nbsp;&lt;= 50</code></li>
	<li><code>nums</code> 是一个 <strong>排列</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：寻找 1 和 n 的位置

我们可以先找到 $1$ 和 $n$ 的下标 $i$ 和 $j$，然后根据 $i$ 和 $j$ 的相对位置，判断需要交换的次数。

如果 $i \lt j$，那么需要交换的次数为 $i + n - j - 1$；如果 $i \gt j$，那么需要交换的次数为 $i + n - j - 2$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        i = nums.index(1)
        j = nums.index(n)
        k = 1 if i < j else 2
        return i + n - j - k
```

#### Java

```java
class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] == 1) {
                i = k;
            }
            if (nums[k] == n) {
                j = k;
            }
        }
        int k = i < j ? 1 : 2;
        return i + n - j - k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = find(nums.begin(), nums.end(), 1) - nums.begin();
        int j = find(nums.begin(), nums.end(), n) - nums.begin();
        int k = i < j ? 1 : 2;
        return i + n - j - k;
    }
};
```

#### Go

```go
func semiOrderedPermutation(nums []int) int {
	n := len(nums)
	var i, j int
	for k, x := range nums {
		if x == 1 {
			i = k
		}
		if x == n {
			j = k
		}
	}
	k := 1
	if i > j {
		k = 2
	}
	return i + n - j - k
}
```

#### TypeScript

```ts
function semiOrderedPermutation(nums: number[]): number {
    const n = nums.length;
    const i = nums.indexOf(1);
    const j = nums.indexOf(n);
    const k = i < j ? 1 : 2;
    return i + n - j - k;
}
```

#### Rust

```rust
impl Solution {
    pub fn semi_ordered_permutation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let (mut i, mut j) = (0, 0);

        for k in 0..n {
            if nums[k] == 1 {
                i = k;
            }
            if nums[k] == (n as i32) {
                j = k;
            }
        }

        let k = if i < j { 1 } else { 2 };
        (i + n - j - k) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2718. 查询后矩阵的和](https://leetcode.cn/problems/sum-of-matrix-after-queries){#2718}

{{< tabs "2718" >}}

{{% tab "python" %}}
```python
class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        row = set()
        col = set()
        ans = 0
        for t, i, v in queries[::-1]:
            if t == 0:
                if i not in row:
                    ans += v * (n - len(col))
                    row.add(i)
            else:
                if i not in col:
                    ans += v * (n - len(row))
                    col.add(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long matrixSumQueries(int n, int[][] queries) {
        Set<Integer> row = new HashSet<>();
        Set<Integer> col = new HashSet<>();
        int m = queries.length;
        long ans = 0;
        for (int k = m - 1; k >= 0; --k) {
            var q = queries[k];
            int t = q[0], i = q[1], v = q[2];
            if (t == 0) {
                if (row.add(i)) {
                    ans += 1L * (n - col.size()) * v;
                }
            } else {
                if (col.add(i)) {
                    ans += 1L * (n - row.size()) * v;
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
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_set<int> row, col;
        reverse(queries.begin(), queries.end());
        long long ans = 0;
        for (auto& q : queries) {
            int t = q[0], i = q[1], v = q[2];
            if (t == 0) {
                if (!row.count(i)) {
                    ans += 1LL * (n - col.size()) * v;
                    row.insert(i);
                }
            } else {
                if (!col.count(i)) {
                    ans += 1LL * (n - row.size()) * v;
                    col.insert(i);
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
func matrixSumQueries(n int, queries [][]int) (ans int64) {
	row, col := map[int]bool{}, map[int]bool{}
	m := len(queries)
	for k := m - 1; k >= 0; k-- {
		t, i, v := queries[k][0], queries[k][1], queries[k][2]
		if t == 0 {
			if !row[i] {
				ans += int64(v * (n - len(col)))
				row[i] = true
			}
		} else {
			if !col[i] {
				ans += int64(v * (n - len(row)))
				col[i] = true
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function matrixSumQueries(n: number, queries: number[][]): number {
    const row: Set<number> = new Set();
    const col: Set<number> = new Set();
    let ans = 0;
    queries.reverse();
    for (const [t, i, v] of queries) {
        if (t === 0) {
            if (!row.has(i)) {
                ans += v * (n - col.size);
                row.add(i);
            }
        } else {
            if (!col.has(i)) {
                ans += v * (n - row.size);
                col.add(i);
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

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和一个下标从 <strong>0</strong>&nbsp;开始的 <strong>二维数组</strong>&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [type<sub>i</sub>, index<sub>i</sub>, val<sub>i</sub>]</code>&nbsp;。</p>

<p>一开始，给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>n x n</code>&nbsp;矩阵，所有元素均为 <code>0</code>&nbsp;。每一个查询，你需要执行以下操作之一：</p>

<ul>
	<li>如果&nbsp;<code>type<sub>i</sub> == 0</code>&nbsp;，将第&nbsp;<code>index<sub>i</sub></code>&nbsp;行的元素全部修改为&nbsp;<code>val<sub>i</sub></code>&nbsp;，覆盖任何之前的值。</li>
	<li>如果&nbsp;<code>type<sub>i</sub> == 1</code>&nbsp;，将第&nbsp;<code>index<sub>i</sub></code>&nbsp;列的元素全部修改为 <code>val<sub>i</sub></code>&nbsp;，覆盖任何之前的值。</li>
</ul>

<p>请你执行完所有查询以后，返回矩阵中所有整数的和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2718.Sum%20of%20Matrix%20After%20Queries/images/exm1.png" style="width: 681px; height: 161px;"></p>

<pre><b>输入：</b>n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
<b>输出：</b>23
<b>解释：</b>上图展示了每个查询以后矩阵的值。所有操作执行完以后，矩阵元素之和为 23 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2718.Sum%20of%20Matrix%20After%20Queries/images/exm2.png" style="width: 681px; height: 331px;"></p>

<pre><b>输入：</b>n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
<b>输出：</b>17
<b>解释：</b>上图展示了每一个查询操作之后的矩阵。所有操作执行完以后，矩阵元素之和为 17 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i].length == 3</code></li>
	<li><code>0 &lt;= type<sub>i</sub> &lt;= 1</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt; n</code></li>
	<li><code>0 &lt;= val<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

由于每一行、每一列的值取决于最后一次的修改，因此，我们不妨倒序遍历所有的查询，使用哈希表 $row$ 和 $col$ 记录有哪些行和列被修改过。

对于每一次查询 $(t, i, v)$：

-   如果 $t = 0$，那么我们判断第 $i$ 行是否被修改过，如果没有，那么我们将 $v \times (n - |col|)$ 累加到答案中，其中 $|col|$ 表示 $col$ 的大小，然后将 $i$ 加入 $row$ 中；
-   如果 $t = 1$，那么我们判断第 $i$ 列是否被修改过，如果没有，那么我们将 $v \times (n - |row|)$ 累加到答案中，其中 $|row|$ 表示 $row$ 的大小，然后将 $i$ 加入 $col$ 中。

最后返回答案。

时间复杂度 $O(m)$，空间复杂度 $O(n)$。其中 $m$ 表示查询的次数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        row = set()
        col = set()
        ans = 0
        for t, i, v in queries[::-1]:
            if t == 0:
                if i not in row:
                    ans += v * (n - len(col))
                    row.add(i)
            else:
                if i not in col:
                    ans += v * (n - len(row))
                    col.add(i)
        return ans
```

#### Java

```java
class Solution {
    public long matrixSumQueries(int n, int[][] queries) {
        Set<Integer> row = new HashSet<>();
        Set<Integer> col = new HashSet<>();
        int m = queries.length;
        long ans = 0;
        for (int k = m - 1; k >= 0; --k) {
            var q = queries[k];
            int t = q[0], i = q[1], v = q[2];
            if (t == 0) {
                if (row.add(i)) {
                    ans += 1L * (n - col.size()) * v;
                }
            } else {
                if (col.add(i)) {
                    ans += 1L * (n - row.size()) * v;
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
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_set<int> row, col;
        reverse(queries.begin(), queries.end());
        long long ans = 0;
        for (auto& q : queries) {
            int t = q[0], i = q[1], v = q[2];
            if (t == 0) {
                if (!row.count(i)) {
                    ans += 1LL * (n - col.size()) * v;
                    row.insert(i);
                }
            } else {
                if (!col.count(i)) {
                    ans += 1LL * (n - row.size()) * v;
                    col.insert(i);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func matrixSumQueries(n int, queries [][]int) (ans int64) {
	row, col := map[int]bool{}, map[int]bool{}
	m := len(queries)
	for k := m - 1; k >= 0; k-- {
		t, i, v := queries[k][0], queries[k][1], queries[k][2]
		if t == 0 {
			if !row[i] {
				ans += int64(v * (n - len(col)))
				row[i] = true
			}
		} else {
			if !col[i] {
				ans += int64(v * (n - len(row)))
				col[i] = true
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function matrixSumQueries(n: number, queries: number[][]): number {
    const row: Set<number> = new Set();
    const col: Set<number> = new Set();
    let ans = 0;
    queries.reverse();
    for (const [t, i, v] of queries) {
        if (t === 0) {
            if (!row.has(i)) {
                ans += v * (n - col.size);
                row.add(i);
            }
        } else {
            if (!col.has(i)) {
                ans += v * (n - row.size);
                col.add(i);
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

# [2719. 统计整数数目](https://leetcode.cn/problems/count-of-integers){#2719}

{{< tabs "2719" >}}

{{% tab "python" %}}
```python
class Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        @cache
        def dfs(pos: int, s: int, limit: bool) -> int:
            if pos >= len(num):
                return int(min_sum <= s <= max_sum)
            up = int(num[pos]) if limit else 9
            return (
                sum(dfs(pos + 1, s + i, limit and i == up) for i in range(up + 1)) % mod
            )

        mod = 10**9 + 7
        num = num2
        a = dfs(0, 0, True)
        dfs.cache_clear()
        num = str(int(num1) - 1)
        b = dfs(0, 0, True)
        return (a - b) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.math.BigInteger;

class Solution {
    private final int mod = (int) 1e9 + 7;
    private Integer[][] f;
    private String num;
    private int min;
    private int max;

    public int count(String num1, String num2, int min_sum, int max_sum) {
        min = min_sum;
        max = max_sum;
        num = num2;
        f = new Integer[23][220];
        int a = dfs(0, 0, true);
        num = new BigInteger(num1).subtract(BigInteger.ONE).toString();
        f = new Integer[23][220];
        int b = dfs(0, 0, true);
        return (a - b + mod) % mod;
    }

    private int dfs(int pos, int s, boolean limit) {
        if (pos >= num.length()) {
            return s >= min && s <= max ? 1 : 0;
        }
        if (!limit && f[pos][s] != null) {
            return f[pos][s];
        }
        int ans = 0;
        int up = limit ? num.charAt(pos) - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            ans = (ans + dfs(pos + 1, s + i, limit && i == up)) % mod;
        }
        if (!limit) {
            f[pos][s] = ans;
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
    int count(string num1, string num2, int min_sum, int max_sum) {
        const int mod = 1e9 + 7;
        int f[23][220];
        memset(f, -1, sizeof(f));
        string num = num2;

        function<int(int, int, bool)> dfs = [&](int pos, int s, bool limit) -> int {
            if (pos >= num.size()) {
                return s >= min_sum && s <= max_sum ? 1 : 0;
            }
            if (!limit && f[pos][s] != -1) {
                return f[pos][s];
            }
            int up = limit ? num[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                ans += dfs(pos + 1, s + i, limit && i == up);
                ans %= mod;
            }
            if (!limit) {
                f[pos][s] = ans;
            }
            return ans;
        };

        int a = dfs(0, 0, true);
        for (int i = num1.size() - 1; ~i; --i) {
            if (num1[i] == '0') {
                num1[i] = '9';
            } else {
                num1[i] -= 1;
                break;
            }
        }
        num = num1;
        memset(f, -1, sizeof(f));
        int b = dfs(0, 0, true);
        return (a - b + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func count(num1 string, num2 string, min_sum int, max_sum int) int {
	const mod = 1e9 + 7
	f := [23][220]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	num := num2
	var dfs func(int, int, bool) int
	dfs = func(pos, s int, limit bool) int {
		if pos >= len(num) {
			if s >= min_sum && s <= max_sum {
				return 1
			}
			return 0
		}
		if !limit && f[pos][s] != -1 {
			return f[pos][s]
		}
		var ans int
		up := 9
		if limit {
			up = int(num[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			ans = (ans + dfs(pos+1, s+i, limit && i == up)) % mod
		}
		if !limit {
			f[pos][s] = ans
		}
		return ans
	}
	a := dfs(0, 0, true)
	t := []byte(num1)
	for i := len(t) - 1; i >= 0; i-- {
		if t[i] != '0' {
			t[i]--
			break
		}
		t[i] = '9'
	}
	num = string(t)
	f = [23][220]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	b := dfs(0, 0, true)
	return (a - b + mod) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function count(num1: string, num2: string, min_sum: number, max_sum: number): number {
    const mod = 1e9 + 7;
    const f: number[][] = Array.from({ length: 23 }, () => Array(220).fill(-1));
    let num = num2;
    const dfs = (pos: number, s: number, limit: boolean): number => {
        if (pos >= num.length) {
            return s >= min_sum && s <= max_sum ? 1 : 0;
        }
        if (!limit && f[pos][s] !== -1) {
            return f[pos][s];
        }
        let ans = 0;
        const up = limit ? +num[pos] : 9;
        for (let i = 0; i <= up; i++) {
            ans = (ans + dfs(pos + 1, s + i, limit && i === up)) % mod;
        }
        if (!limit) {
            f[pos][s] = ans;
        }
        return ans;
    };
    const a = dfs(0, 0, true);
    num = (BigInt(num1) - 1n).toString();
    f.forEach(v => v.fill(-1));
    const b = dfs(0, 0, true);
    return (a - b + mod) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个数字字符串&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>&nbsp;，以及两个整数&nbsp;<code>max_sum</code> 和&nbsp;<code>min_sum</code>&nbsp;。如果一个整数&nbsp;<code>x</code>&nbsp;满足以下条件，我们称它是一个好整数：</p>

<ul>
	<li><code>num1 &lt;= x &lt;= num2</code></li>
	<li><code>min_sum &lt;= digit_sum(x) &lt;= max_sum</code>.</li>
</ul>

<p>请你返回好整数的数目。答案可能很大，请返回答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后的结果。</p>

<p>注意，<code>digit_sum(x)</code>&nbsp;表示&nbsp;<code>x</code>&nbsp;各位数字之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num1 = "1", num2 = "12", min_num = 1, max_num = 8
<b>输出：</b>11
<b>解释：</b>总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11 和 12 。所以我们返回 11 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num1 = "1", num2 = "5", min_num = 1, max_num = 5
<b>输出：</b>5
<b>解释：</b>数位和在 1 到 5 之间的 5 个整数分别为 1,2,3,4 和 5 。所以我们返回 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1 &lt;= num2 &lt;= 10<sup>22</sup></code></li>
	<li><code>1 &lt;= min_sum &lt;= max_sum &lt;= 400</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

题目实际上求的是区间 $[num1,..num2]$ 中，数位和在 $[min\_sum,..max\_sum]$ 的数的个数。对于这种区间 $[l,..r]$ 的问题，我们可以考虑转化为求 $[1,..r]$ 和 $[1,..l-1]$ 的答案，然后相减即可。

对于 $[1,..r]$ 的答案，我们可以使用数位 DP 来求解。我们设计一个函数 $dfs(pos, s, limit)$ 表示当前处理到第 $pos$ 位，数位和为 $s$，当前数是否有上界限制 $limit$ 的方案数。其中 $pos$ 从高到低枚举。

对于 $dfs(pos, s, limit)$，我们可以枚举当前数位 $i$ 的值，然后递归计算 $dfs(pos+1, s+i, limit \bigcap  i==up)$，其中 $up$ 表示当前数位的上界。如果 $limit$ 为真，那么 $up$ 就是当前数位的上界，否则 $up$ 为 $9$。如果 $pos$ 大于等于 $num$ 的长度，那么我们就可以判断 $s$ 是否在 $[min\_sum,..max\_sum]$ 的范围内，如果在就返回 $1$，否则返回 $0$。

时间复杂度 $O(10 \times n \times max\_sum)$，空间复杂度 $O(n \times max\_sum)$。其中 $n$ 表示 $num$ 的长度。

相似题目：

-   [2801. 统计范围内的步进数字数目](https://github.com/doocs/leetcode/blob/main/solution/2800-2899/2801.Count%20Stepping%20Numbers%20in%20Range/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def count(self, num1: str, num2: str, min_sum: int, max_sum: int) -> int:
        @cache
        def dfs(pos: int, s: int, limit: bool) -> int:
            if pos >= len(num):
                return int(min_sum <= s <= max_sum)
            up = int(num[pos]) if limit else 9
            return (
                sum(dfs(pos + 1, s + i, limit and i == up) for i in range(up + 1)) % mod
            )

        mod = 10**9 + 7
        num = num2
        a = dfs(0, 0, True)
        dfs.cache_clear()
        num = str(int(num1) - 1)
        b = dfs(0, 0, True)
        return (a - b) % mod
```

#### Java

```java
import java.math.BigInteger;

class Solution {
    private final int mod = (int) 1e9 + 7;
    private Integer[][] f;
    private String num;
    private int min;
    private int max;

    public int count(String num1, String num2, int min_sum, int max_sum) {
        min = min_sum;
        max = max_sum;
        num = num2;
        f = new Integer[23][220];
        int a = dfs(0, 0, true);
        num = new BigInteger(num1).subtract(BigInteger.ONE).toString();
        f = new Integer[23][220];
        int b = dfs(0, 0, true);
        return (a - b + mod) % mod;
    }

    private int dfs(int pos, int s, boolean limit) {
        if (pos >= num.length()) {
            return s >= min && s <= max ? 1 : 0;
        }
        if (!limit && f[pos][s] != null) {
            return f[pos][s];
        }
        int ans = 0;
        int up = limit ? num.charAt(pos) - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            ans = (ans + dfs(pos + 1, s + i, limit && i == up)) % mod;
        }
        if (!limit) {
            f[pos][s] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        const int mod = 1e9 + 7;
        int f[23][220];
        memset(f, -1, sizeof(f));
        string num = num2;

        function<int(int, int, bool)> dfs = [&](int pos, int s, bool limit) -> int {
            if (pos >= num.size()) {
                return s >= min_sum && s <= max_sum ? 1 : 0;
            }
            if (!limit && f[pos][s] != -1) {
                return f[pos][s];
            }
            int up = limit ? num[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                ans += dfs(pos + 1, s + i, limit && i == up);
                ans %= mod;
            }
            if (!limit) {
                f[pos][s] = ans;
            }
            return ans;
        };

        int a = dfs(0, 0, true);
        for (int i = num1.size() - 1; ~i; --i) {
            if (num1[i] == '0') {
                num1[i] = '9';
            } else {
                num1[i] -= 1;
                break;
            }
        }
        num = num1;
        memset(f, -1, sizeof(f));
        int b = dfs(0, 0, true);
        return (a - b + mod) % mod;
    }
};
```

#### Go

```go
func count(num1 string, num2 string, min_sum int, max_sum int) int {
	const mod = 1e9 + 7
	f := [23][220]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	num := num2
	var dfs func(int, int, bool) int
	dfs = func(pos, s int, limit bool) int {
		if pos >= len(num) {
			if s >= min_sum && s <= max_sum {
				return 1
			}
			return 0
		}
		if !limit && f[pos][s] != -1 {
			return f[pos][s]
		}
		var ans int
		up := 9
		if limit {
			up = int(num[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			ans = (ans + dfs(pos+1, s+i, limit && i == up)) % mod
		}
		if !limit {
			f[pos][s] = ans
		}
		return ans
	}
	a := dfs(0, 0, true)
	t := []byte(num1)
	for i := len(t) - 1; i >= 0; i-- {
		if t[i] != '0' {
			t[i]--
			break
		}
		t[i] = '9'
	}
	num = string(t)
	f = [23][220]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	b := dfs(0, 0, true)
	return (a - b + mod) % mod
}
```

#### TypeScript

```ts
function count(num1: string, num2: string, min_sum: number, max_sum: number): number {
    const mod = 1e9 + 7;
    const f: number[][] = Array.from({ length: 23 }, () => Array(220).fill(-1));
    let num = num2;
    const dfs = (pos: number, s: number, limit: boolean): number => {
        if (pos >= num.length) {
            return s >= min_sum && s <= max_sum ? 1 : 0;
        }
        if (!limit && f[pos][s] !== -1) {
            return f[pos][s];
        }
        let ans = 0;
        const up = limit ? +num[pos] : 9;
        for (let i = 0; i <= up; i++) {
            ans = (ans + dfs(pos + 1, s + i, limit && i === up)) % mod;
        }
        if (!limit) {
            f[pos][s] = ans;
        }
        return ans;
    };
    const a = dfs(0, 0, true);
    num = (BigInt(num1) - 1n).toString();
    f.forEach(v => v.fill(-1));
    const b = dfs(0, 0, true);
    return (a - b + mod) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
