---
title: "2370_最长理想子序列"
date: 2025-10-08T18:39:12+08:00
weight: 8
tags: [动态规划, 哈希表, 回溯, 图, 字符串, 并查集, 拓扑排序, 排序, 数学, 数据库, 数组, 栈, 树, 深度优先搜索, 滑动窗口, 矩阵, 贪心]
---

{{< markmap >}}
### [2370_最长理想子序列](#2370)
#### [哈希表](#2370)
#### [字符串](#2370)
#### [动态规划](#2370)
### [2371_最小化网格中的最大值 🔒](#2371)
#### [并查集](#2371)
#### [图](#2371)
#### [拓扑排序](#2371)
#### [数组](#2371)
#### [矩阵](#2371)
#### [排序](#2371)
### [2372_计算每个销售人员的影响力 🔒](#2372)
#### [数据库](#2372)
### [2373_矩阵中的局部最大值](#2373)
#### [数组](#2373)
#### [矩阵](#2373)
### [2374_边积分最高的节点](#2374)
#### [图](#2374)
#### [哈希表](#2374)
### [2375_根据模式串构造最小数字](#2375)
#### [栈](#2375)
#### [贪心](#2375)
#### [字符串](#2375)
#### [回溯](#2375)
### [2376_统计特殊整数](#2376)
#### [数学](#2376)
#### [动态规划](#2376)
### [2377_整理奥运表 🔒](#2377)
#### [数据库](#2377)
### [2378_选择边来最大化树的得分 🔒](#2378)
#### [树](#2378)
#### [深度优先搜索](#2378)
#### [动态规划](#2378)
### [2379_得到 K 个黑块的最少涂色次数](#2379)
#### [字符串](#2379)
#### [滑动窗口](#2379)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2370_最长理想子序列
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
---
### 2371_最小化网格中的最大值 🔒
___
#### 并查集
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 矩阵
___
#### 排序
---
### 2372_计算每个销售人员的影响力 🔒
___
#### 数据库
---
### 2373_矩阵中的局部最大值
___
#### 数组
___
#### 矩阵
---
### 2374_边积分最高的节点
___
#### 图
___
#### 哈希表
---
### 2375_根据模式串构造最小数字
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 回溯
---
### 2376_统计特殊整数
___
#### 数学
___
#### 动态规划
---
### 2377_整理奥运表 🔒
___
#### 数据库
---
### 2378_选择边来最大化树的得分 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
---
### 2379_得到 K 个黑块的最少涂色次数
___
#### 字符串
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 哈希表 | 回溯 |
| 图 | 字符串 | 并查集 |
| 拓扑排序 | 排序 | 数学 |
| 数据库 | 数组 | 栈 |
| 树 | 深度优先搜索 | 滑动窗口 |
| 矩阵 | 贪心 |  |

# [2370. 最长理想子序列](https://leetcode.cn/problems/longest-ideal-subsequence){#2370}

{{< tabs "2370" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        ans = 1
        dp = [1] * n
        d = {s[0]: 0}
        for i in range(1, n):
            a = ord(s[i])
            for b in ascii_lowercase:
                if abs(a - ord(b)) > k:
                    continue
                if b in d:
                    dp[i] = max(dp[i], dp[d[b]] + 1)
            d[s[i]] = i
        return max(dp)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestIdealString(String s, int k) {
        int n = s.length();
        int ans = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        Map<Character, Integer> d = new HashMap<>(26);
        d.put(s.charAt(0), 0);
        for (int i = 1; i < n; ++i) {
            char a = s.charAt(i);
            for (char b = 'a'; b <= 'z'; ++b) {
                if (Math.abs(a - b) > k) {
                    continue;
                }
                if (d.containsKey(b)) {
                    dp[i] = Math.max(dp[i], dp[d.get(b)] + 1);
                }
            }
            d.put(a, i);
            ans = Math.max(ans, dp[i]);
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
    int longestIdealString(string s, int k) {
        int n = s.size();
        int ans = 1;
        vector<int> dp(n, 1);
        unordered_map<char, int> d;
        d[s[0]] = 0;
        for (int i = 1; i < n; ++i) {
            char a = s[i];
            for (char b = 'a'; b <= 'z'; ++b) {
                if (abs(a - b) > k) continue;
                if (d.count(b)) dp[i] = max(dp[i], dp[d[b]] + 1);
            }
            d[a] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestIdealString(s string, k int) int {
	n := len(s)
	ans := 1
	dp := make([]int, n)
	for i := range dp {
		dp[i] = 1
	}
	d := map[byte]int{s[0]: 0}
	for i := 1; i < n; i++ {
		a := s[i]
		for b := byte('a'); b <= byte('z'); b++ {
			if int(a)-int(b) > k || int(b)-int(a) > k {
				continue
			}
			if v, ok := d[b]; ok {
				dp[i] = max(dp[i], dp[v]+1)
			}
		}
		d[a] = i
		ans = max(ans, dp[i])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestIdealString(s: string, k: number): number {
    const dp = new Array(26).fill(0);
    for (const c of s) {
        const x = c.charCodeAt(0) - 'a'.charCodeAt(0);
        let t = 0;
        for (let i = 0; i < 26; i++) {
            if (Math.abs(x - i) <= k) {
                t = Math.max(t, dp[i] + 1);
            }
        }
        dp[x] = Math.max(dp[x], t);
    }

    return dp.reduce((r, c) => Math.max(r, c), 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由小写字母组成的字符串 <code>s</code> ，和一个整数 <code>k</code> 。如果满足下述条件，则可以将字符串 <code>t</code> 视作是 <strong>理想字符串</strong> ：</p>

<ul>
	<li><code>t</code> 是字符串 <code>s</code> 的一个子序列。</li>
	<li><code>t</code> 中每两个 <strong>相邻</strong> 字母在字母表中位次的绝对差值小于或等于 <code>k</code> 。</li>
</ul>

<p>返回 <strong>最长</strong> 理想字符串的长度。</p>

<p>字符串的子序列同样是一个字符串，并且子序列还满足：可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。</p>

<p><strong>注意：</strong>字母表顺序不会循环。例如，<code>'a'</code> 和 <code>'z'</code> 在字母表中位次的绝对差值是 <code>25</code> ，而不是 <code>1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "acfgbd", k = 2
<strong>输出：</strong>4
<strong>解释：</strong>最长理想字符串是 "acbd" 。该字符串长度为 4 ，所以返回 4 。
注意 "acfgbd" 不是理想字符串，因为 'c' 和 'f' 的字母表位次差值为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", k = 3
<strong>输出：</strong>4
<strong>解释：</strong>最长理想字符串是 "abcd" ，该字符串长度为 4 ，所以返回 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 25</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

设 $dp[i]$ 表示以字符 $s[i]$ 结尾的最长理想子序列的长度，利用哈希表 $d$ 记录每个字符最新出现的位置。初始时 $dp[0]=1$, $d[s[0]]=0$。

在 $[1,..n-1]$ 范围内的每个字符 $s[i]$，获取它所有前一个合法字符的位置 $j$，那么 $dp[i]=max(dp[i], dp[j]+1)$。

答案为 $dp$ 中的最大值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        ans = 1
        dp = [1] * n
        d = {s[0]: 0}
        for i in range(1, n):
            a = ord(s[i])
            for b in ascii_lowercase:
                if abs(a - ord(b)) > k:
                    continue
                if b in d:
                    dp[i] = max(dp[i], dp[d[b]] + 1)
            d[s[i]] = i
        return max(dp)
```

#### Java

```java
class Solution {
    public int longestIdealString(String s, int k) {
        int n = s.length();
        int ans = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        Map<Character, Integer> d = new HashMap<>(26);
        d.put(s.charAt(0), 0);
        for (int i = 1; i < n; ++i) {
            char a = s.charAt(i);
            for (char b = 'a'; b <= 'z'; ++b) {
                if (Math.abs(a - b) > k) {
                    continue;
                }
                if (d.containsKey(b)) {
                    dp[i] = Math.max(dp[i], dp[d.get(b)] + 1);
                }
            }
            d.put(a, i);
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int ans = 1;
        vector<int> dp(n, 1);
        unordered_map<char, int> d;
        d[s[0]] = 0;
        for (int i = 1; i < n; ++i) {
            char a = s[i];
            for (char b = 'a'; b <= 'z'; ++b) {
                if (abs(a - b) > k) continue;
                if (d.count(b)) dp[i] = max(dp[i], dp[d[b]] + 1);
            }
            d[a] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func longestIdealString(s string, k int) int {
	n := len(s)
	ans := 1
	dp := make([]int, n)
	for i := range dp {
		dp[i] = 1
	}
	d := map[byte]int{s[0]: 0}
	for i := 1; i < n; i++ {
		a := s[i]
		for b := byte('a'); b <= byte('z'); b++ {
			if int(a)-int(b) > k || int(b)-int(a) > k {
				continue
			}
			if v, ok := d[b]; ok {
				dp[i] = max(dp[i], dp[v]+1)
			}
		}
		d[a] = i
		ans = max(ans, dp[i])
	}
	return ans
}
```

#### TypeScript

```ts
function longestIdealString(s: string, k: number): number {
    const dp = new Array(26).fill(0);
    for (const c of s) {
        const x = c.charCodeAt(0) - 'a'.charCodeAt(0);
        let t = 0;
        for (let i = 0; i < 26; i++) {
            if (Math.abs(x - i) <= k) {
                t = Math.max(t, dp[i] + 1);
            }
        }
        dp[x] = Math.max(dp[x], t);
    }

    return dp.reduce((r, c) => Math.max(r, c), 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2371. 最小化网格中的最大值 🔒](https://leetcode.cn/problems/minimize-maximum-value-in-a-grid){#2371}

{{< tabs "2371" >}}

{{% tab "python" %}}
```python
class Solution:
    def minScore(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        nums = [(v, i, j) for i, row in enumerate(grid) for j, v in enumerate(row)]
        nums.sort()
        row_max = [0] * m
        col_max = [0] * n
        ans = [[0] * n for _ in range(m)]
        for _, i, j in nums:
            ans[i][j] = max(row_max[i], col_max[j]) + 1
            row_max[i] = col_max[j] = ans[i][j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] minScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        List<int[]> nums = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.add(new int[] {grid[i][j], i, j});
            }
        }
        Collections.sort(nums, (a, b) -> a[0] - b[0]);
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int[][] ans = new int[m][n];
        for (int[] num : nums) {
            int i = num[1], j = num[2];
            ans[i][j] = Math.max(rowMax[i], colMax[j]) + 1;
            rowMax[i] = ans[i][j];
            colMax[j] = ans[i][j];
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
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        vector<tuple<int, int, int>> nums;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back({grid[i][j], i, j});
            }
        }
        sort(nums.begin(), nums.end());
        vector<int> rowMax(m);
        vector<int> colMax(n);
        vector<vector<int>> ans(m, vector<int>(n));
        for (auto [_, i, j] : nums) {
            ans[i][j] = max(rowMax[i], colMax[j]) + 1;
            rowMax[i] = colMax[j] = ans[i][j];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minScore(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	nums := [][]int{}
	for i, row := range grid {
		for j, v := range row {
			nums = append(nums, []int{v, i, j})
		}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i][0] < nums[j][0] })
	rowMax := make([]int, m)
	colMax := make([]int, n)
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for _, num := range nums {
		i, j := num[1], num[2]
		ans[i][j] = max(rowMax[i], colMax[j]) + 1
		rowMax[i] = ans[i][j]
		colMax[j] = ans[i][j]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minScore(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const nums = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            nums.push([grid[i][j], i, j]);
        }
    }
    nums.sort((a, b) => a[0] - b[0]);
    const rowMax = new Array(m).fill(0);
    const colMax = new Array(n).fill(0);
    const ans = Array.from({ length: m }, _ => new Array(n));
    for (const [_, i, j] of nums) {
        ans[i][j] = Math.max(rowMax[i], colMax[j]) + 1;
        rowMax[i] = colMax[j] = ans[i][j];
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

<p>给定一个包含&nbsp;<strong>不同&nbsp;</strong>正整数的 <code>m × n</code> 整数矩阵 <code>grid</code>。</p>

<p>必须将矩阵中的每一个整数替换为正整数，且满足以下条件:</p>

<ul>
	<li>在替换之后，同行或同列中的每两个元素的&nbsp;<strong>相对&nbsp;</strong>顺序应该保持&nbsp;<strong>不变</strong>。</li>
	<li>替换后矩阵中的 <strong>最大</strong> 数目应尽可能 <strong>小</strong>。</li>
</ul>

<p>如果对于原始矩阵中的所有元素对，使&nbsp;<code>grid[r<sub>1</sub>][c<sub>1</sub>] &gt; grid[r<sub>2</sub>][c<sub>2</sub>]</code>，其中要么&nbsp;<code>r<sub>1</sub> == r<sub>2</sub></code> ，要么&nbsp;<code>c<sub>1</sub> == c<sub>2</sub></code>，则相对顺序保持不变。那么在替换之后一定满足&nbsp;<code>grid[r<sub>1</sub>][c<sub>1</sub>] &gt; grid[r<sub>2</sub>][c<sub>2</sub>]</code>。</p>

<p>例如，如果&nbsp;<code>grid = [[2, 4, 5], [7, 3, 9]]</code>，那么一个好的替换可以是 <code>grid = [[1, 2, 3], [2, 1, 4]]</code> 或 <code>grid = [[1, 2, 3], [3, 1, 4]]</code>。</p>

<p>返回&nbsp;<em><strong>结果&nbsp;</strong>矩阵</em>。如果有多个答案，则返回其中&nbsp;<strong>任何&nbsp;</strong>一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2371.Minimize%20Maximum%20Value%20in%20a%20Grid/images/grid2drawio.png" />
<pre>
<strong>输入:</strong> grid = [[3,1],[2,5]]
<strong>输出:</strong> [[2,1],[1,2]]
<strong>解释:</strong> 上面的图显示了一个有效的替换。
矩阵中的最大值是 2。可以证明，不能得到更小的值。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[10]]
<strong>输出:</strong> [[1]]
<strong>解释:</strong> 我们将矩阵中唯一的数字替换为 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
	<li><code>grid</code> 由不同的整数组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

由于可以将每一个数字重新填入并且使最终矩阵的最大值最小化，可考虑贪心。

矩阵中每一个数字不一样，可考虑哈希表或数组记录每个数字对应的位置。

将所有数字排序。然后从小到大填入新的数字，每次填入的数字为当前行和列的较大值再加一，同时用新填入的数字更新当前行和列的最大值。

时间复杂度 $O(mn\log mn)$，空间复杂度 $O(mn)$。其中 $m$ 和 $n$ 是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minScore(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        nums = [(v, i, j) for i, row in enumerate(grid) for j, v in enumerate(row)]
        nums.sort()
        row_max = [0] * m
        col_max = [0] * n
        ans = [[0] * n for _ in range(m)]
        for _, i, j in nums:
            ans[i][j] = max(row_max[i], col_max[j]) + 1
            row_max[i] = col_max[j] = ans[i][j]
        return ans
```

#### Java

```java
class Solution {
    public int[][] minScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        List<int[]> nums = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.add(new int[] {grid[i][j], i, j});
            }
        }
        Collections.sort(nums, (a, b) -> a[0] - b[0]);
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int[][] ans = new int[m][n];
        for (int[] num : nums) {
            int i = num[1], j = num[2];
            ans[i][j] = Math.max(rowMax[i], colMax[j]) + 1;
            rowMax[i] = ans[i][j];
            colMax[j] = ans[i][j];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        vector<tuple<int, int, int>> nums;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back({grid[i][j], i, j});
            }
        }
        sort(nums.begin(), nums.end());
        vector<int> rowMax(m);
        vector<int> colMax(n);
        vector<vector<int>> ans(m, vector<int>(n));
        for (auto [_, i, j] : nums) {
            ans[i][j] = max(rowMax[i], colMax[j]) + 1;
            rowMax[i] = colMax[j] = ans[i][j];
        }
        return ans;
    }
};
```

#### Go

```go
func minScore(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	nums := [][]int{}
	for i, row := range grid {
		for j, v := range row {
			nums = append(nums, []int{v, i, j})
		}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i][0] < nums[j][0] })
	rowMax := make([]int, m)
	colMax := make([]int, n)
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for _, num := range nums {
		i, j := num[1], num[2]
		ans[i][j] = max(rowMax[i], colMax[j]) + 1
		rowMax[i] = ans[i][j]
		colMax[j] = ans[i][j]
	}
	return ans
}
```

#### TypeScript

```ts
function minScore(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const nums = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            nums.push([grid[i][j], i, j]);
        }
    }
    nums.sort((a, b) => a[0] - b[0]);
    const rowMax = new Array(m).fill(0);
    const colMax = new Array(n).fill(0);
    const ans = Array.from({ length: m }, _ => new Array(n));
    for (const [_, i, j] of nums) {
        ans[i][j] = Math.max(rowMax[i], colMax[j]) + 1;
        rowMax[i] = colMax[j] = ans[i][j];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2372. 计算每个销售人员的影响力 🔒](https://leetcode.cn/problems/calculate-the-influence-of-each-salesperson){#2372}

{{< tabs "2372" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT sp.salesperson_id, name, IFNULL(SUM(price), 0) AS total
FROM
    Salesperson AS sp
    LEFT JOIN Customer AS c ON sp.salesperson_id = c.salesperson_id
    LEFT JOIN Sales AS s ON s.customer_id = c.customer_id
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Salesperson</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| salesperson_id | int     |
| name           | varchar |
+----------------+---------+
sales_person_id 包含唯一值。
这个表中的每一行都显示一个销售人员的 ID。
</pre>

<p>&nbsp;</p>

<p>表：<code>Customer</code></p>

<pre>
+----------------+------+
| Column Name    | Type |
+----------------+------+
| customer_id    | int  |
| salesperson_id | int  |
+----------------+------+
customer_id 包含唯一值。
salesperson_id 是一个来自于 <code>Salesperson 表的外键</code>
<code>Customer </code>表中的每一行都显示了一个客户的 ID 和销售人员的 ID。
</pre>

<p>&nbsp;</p>

<p>表：<code>Sales</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| sale_id     | int  |
| customer_id | int  |
| price       | int  |
+-------------+------+
sale_id 包含唯一值。
customer_id 是一个来自于 Customer 表的外键。
<code>Sales </code>表中的每一行都显示了一个客户的 ID 以及他们在 sale_id 指代的交易中所支付的金额。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告每个销售人员的客户所支付的价格总和。如果销售人员没有任何客户，则总值应该为 <code>0</code> 。<br />
以 <strong>任意顺序</strong> 返回结果表。<br />
结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Salesperson 表:
+----------------+-------+
| salesperson_id | name  |
+----------------+-------+
| 1              | Alice |
| 2              | Bob   |
| 3              | Jerry |
+----------------+-------+
Customer 表:
+-------------+----------------+
| customer_id | salesperson_id |
+-------------+----------------+
| 1           | 1              |
| 2           | 1              |
| 3           | 2              |
+-------------+----------------+
Sales 表:
+---------+-------------+-------+
| sale_id | customer_id | price |
+---------+-------------+-------+
| 1       | 2           | 892   |
| 2       | 1           | 354   |
| 3       | 3           | 988   |
| 4       | 3           | 856   |
+---------+-------------+-------+
<strong>输出:</strong> 
+----------------+-------+-------+
| salesperson_id | name  | total |
+----------------+-------+-------+
| 1              | Alice | 1246  |
| 2              | Bob   | 1844  |
| 3              | Jerry | 0     |
+----------------+-------+-------+
<strong>解释:</strong> 
Alice 是客户 1 和客户 2 的销售人员。
  - 客户 1 一次购买花费了 354。
  - 客户 2 一次购买花费了 892。
Alice 的总数是 354 + 892 = 1246。

Bob 是客户 3 的销售人员。
  - 客户 3 一次购买花费了 988，另一次购买花费了 856。
Bob 的总数是 988 + 856 = 1844。

Jerry 没有客户。
Jerry 的总数是 0。</pre>

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
SELECT sp.salesperson_id, name, IFNULL(SUM(price), 0) AS total
FROM
    Salesperson AS sp
    LEFT JOIN Customer AS c ON sp.salesperson_id = c.salesperson_id
    LEFT JOIN Sales AS s ON s.customer_id = c.customer_id
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2373. 矩阵中的局部最大值](https://leetcode.cn/problems/largest-local-values-in-a-matrix){#2373}

{{< tabs "2373" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                ans[i][j] = max(
                    grid[x][y] for x in range(i, i + 3) for y in range(j, j + 3)
                )
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] ans = new int[n - 2][n - 2];
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                for (int x = i; x <= i + 2; ++x) {
                    for (int y = j; y <= j + 2; ++y) {
                        ans[i][j] = Math.max(ans[i][j], grid[x][y]);
                    }
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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                for (int x = i; x <= i + 2; ++x) {
                    for (int y = j; y <= j + 2; ++y) {
                        ans[i][j] = max(ans[i][j], grid[x][y]);
                    }
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
func largestLocal(grid [][]int) [][]int {
	n := len(grid)
	ans := make([][]int, n-2)
	for i := range ans {
		ans[i] = make([]int, n-2)
		for j := 0; j < n-2; j++ {
			for x := i; x <= i+2; x++ {
				for y := j; y <= j+2; y++ {
					ans[i][j] = max(ans[i][j], grid[x][y])
				}
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestLocal(grid: number[][]): number[][] {
    const n = grid.length;
    const res = Array.from({ length: n - 2 }, () => new Array(n - 2).fill(0));
    for (let i = 0; i < n - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            let max = 0;
            for (let k = i; k < i + 3; k++) {
                for (let z = j; z < j + 3; z++) {
                    max = Math.max(max, grid[k][z]);
                }
            }
            res[i][j] = max;
        }
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>n x n</code> 的整数矩阵 <code>grid</code> 。</p>

<p>生成一个大小为&nbsp;<code>(n - 2) x (n - 2)</code> 的整数矩阵&nbsp; <code>maxLocal</code> ，并满足：</p>

<ul>
	<li><code>maxLocal[i][j]</code> 等于 <code>grid</code> 中以 <code>i + 1</code> 行和 <code>j + 1</code> 列为中心的 <code>3 x 3</code> 矩阵中的 <strong>最大值</strong> 。</li>
</ul>

<p>换句话说，我们希望找出 <code>grid</code> 中每个&nbsp;<code>3 x 3</code> 矩阵中的最大值。</p>

<p>返回生成的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2373.Largest%20Local%20Values%20in%20a%20Matrix/images/ex1.png" style="width: 371px; height: 210px;" /></p>

<pre>
<strong>输入：</strong>grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
<strong>输出：</strong>[[9,9],[8,6]]
<strong>解释：</strong>原矩阵和生成的矩阵如上图所示。
注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2373.Largest%20Local%20Values%20in%20a%20Matrix/images/ex2new2.png" style="width: 436px; height: 240px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
<strong>输出：</strong>[[2,2,2],[2,2,2],[2,2,2]]
<strong>解释：</strong>注意，2 包含在 grid 中每个 3 x 3 的矩阵中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>3 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举每个 $3 \times 3$ 的矩阵，求出每个 $3 \times 3$ 的矩阵中的最大值，然后将这些最大值放入答案矩阵中。

时间复杂度 $O(n^2)$，其中 $n$ 是矩阵的边长。忽略答案矩阵的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                ans[i][j] = max(
                    grid[x][y] for x in range(i, i + 3) for y in range(j, j + 3)
                )
        return ans
```

#### Java

```java
class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] ans = new int[n - 2][n - 2];
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                for (int x = i; x <= i + 2; ++x) {
                    for (int y = j; y <= j + 2; ++y) {
                        ans[i][j] = Math.max(ans[i][j], grid[x][y]);
                    }
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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                for (int x = i; x <= i + 2; ++x) {
                    for (int y = j; y <= j + 2; ++y) {
                        ans[i][j] = max(ans[i][j], grid[x][y]);
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestLocal(grid [][]int) [][]int {
	n := len(grid)
	ans := make([][]int, n-2)
	for i := range ans {
		ans[i] = make([]int, n-2)
		for j := 0; j < n-2; j++ {
			for x := i; x <= i+2; x++ {
				for y := j; y <= j+2; y++ {
					ans[i][j] = max(ans[i][j], grid[x][y])
				}
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function largestLocal(grid: number[][]): number[][] {
    const n = grid.length;
    const res = Array.from({ length: n - 2 }, () => new Array(n - 2).fill(0));
    for (let i = 0; i < n - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            let max = 0;
            for (let k = i; k < i + 3; k++) {
                for (let z = j; z < j + 3; z++) {
                    max = Math.max(max, grid[k][z]);
                }
            }
            res[i][j] = max;
        }
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2374. 边积分最高的节点](https://leetcode.cn/problems/node-with-highest-edge-score){#2374}

{{< tabs "2374" >}}

{{% tab "python" %}}
```python
class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        ans = 0
        cnt = [0] * len(edges)
        for i, j in enumerate(edges):
            cnt[j] += i
            if cnt[ans] < cnt[j] or (cnt[ans] == cnt[j] and j < ans):
                ans = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int edgeScore(int[] edges) {
        int n = edges.length;
        long[] cnt = new long[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = edges[i];
            cnt[j] += i;
            if (cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans)) {
                ans = j;
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
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> cnt(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = edges[i];
            cnt[j] += i;
            if (cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans)) {
                ans = j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func edgeScore(edges []int) (ans int) {
	cnt := make([]int, len(edges))
	for i, j := range edges {
		cnt[j] += i
		if cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans) {
			ans = j
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function edgeScore(edges: number[]): number {
    const n = edges.length;
    const cnt: number[] = Array(n).fill(0);
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        const j = edges[i];
        cnt[j] += i;
        if (cnt[ans] < cnt[j] || (cnt[ans] === cnt[j] && j < ans)) {
            ans = j;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn edge_score(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut cnt = vec![0_i64; n];
        let mut ans = 0;

        for (i, &j) in edges.iter().enumerate() {
            let j = j as usize;
            cnt[j] += i as i64;
            if cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans) {
                ans = j;
            }
        }

        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有向图，图中有 <code>n</code> 个节点，节点编号从 <code>0</code> 到 <code>n - 1</code> ，其中每个节点都 <strong>恰有一条</strong> 出边。</p>

<p>图由一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>edges</code> 表示，其中 <code>edges[i]</code> 表示存在一条从节点 <code>i</code> 到节点 <code>edges[i]</code> 的 <strong>有向</strong> 边。</p>

<p>节点 <code>i</code> 的 <strong>边积分</strong> 定义为：所有存在一条指向节点 <code>i</code> 的边的节点的 <strong>编号</strong> 总和。</p>

<p>返回 <strong>边积分</strong> 最高的节点。如果多个节点的 <strong>边积分</strong> 相同，返回编号 <strong>最小</strong> 的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2374.Node%20With%20Highest%20Edge%20Score/images/image-20220620195403-1.png" style="width: 450px; height: 260px;">
<pre><strong>输入：</strong>edges = [1,0,0,0,0,7,7,5]
<strong>输出：</strong>7
<strong>解释：</strong>
- 节点 1、2、3 和 4 都有指向节点 0 的边，节点 0 的边积分等于 1 + 2 + 3 + 4 = 10 。
- 节点 0 有一条指向节点 1 的边，节点 1 的边积分等于 0 。
- 节点 7 有一条指向节点 5 的边，节点 5 的边积分等于 7 。
- 节点 5 和 6 都有指向节点 7 的边，节点 7 的边积分等于 5 + 6 = 11 。
节点 7 的边积分最高，所以返回 7 。
</pre>

<p><strong>示例 2：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2374.Node%20With%20Highest%20Edge%20Score/images/image-20220620200212-3.png" style="width: 150px; height: 155px;">
<pre><strong>输入：</strong>edges = [2,0,0,2]
<strong>输出：</strong>0
<strong>解释：
</strong>- 节点 1 和 2 都有指向节点 0 的边，节点 0 的边积分等于 1 + 2 = 3 。
- 节点 0 和 3 都有指向节点 2 的边，节点 2 的边积分等于 0 + 3 = 3 。
节点 0 和 2 的边积分都是 3 。由于节点 0 的编号更小，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们定义一个长度为 $n$ 的数组 $\textit{cnt}$，其中 $\textit{cnt}[i]$ 表示节点 $i$ 的边积分，初始时所有元素均为 $0$。定义一个答案变量 $\textit{ans}$，初始时为 $0$。

接下来，我们遍历数组 $\textit{edges}$，对于每个节点 $i$，以及它的出边节点 $j$，我们更新 $\textit{cnt}[j]$ 为 $\textit{cnt}[j] + i$。如果 $\textit{cnt}[\textit{ans}] < \textit{cnt}[j]$ 或者 $\textit{cnt}[\textit{ans}] = \textit{cnt}[j]$ 且 $j < \textit{ans}$，我们更新 $\textit{ans}$ 为 $j$。

最后，返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{edges}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        ans = 0
        cnt = [0] * len(edges)
        for i, j in enumerate(edges):
            cnt[j] += i
            if cnt[ans] < cnt[j] or (cnt[ans] == cnt[j] and j < ans):
                ans = j
        return ans
```

#### Java

```java
class Solution {
    public int edgeScore(int[] edges) {
        int n = edges.length;
        long[] cnt = new long[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = edges[i];
            cnt[j] += i;
            if (cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans)) {
                ans = j;
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
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> cnt(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = edges[i];
            cnt[j] += i;
            if (cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans)) {
                ans = j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func edgeScore(edges []int) (ans int) {
	cnt := make([]int, len(edges))
	for i, j := range edges {
		cnt[j] += i
		if cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans) {
			ans = j
		}
	}
	return
}
```

#### TypeScript

```ts
function edgeScore(edges: number[]): number {
    const n = edges.length;
    const cnt: number[] = Array(n).fill(0);
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        const j = edges[i];
        cnt[j] += i;
        if (cnt[ans] < cnt[j] || (cnt[ans] === cnt[j] && j < ans)) {
            ans = j;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn edge_score(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut cnt = vec![0_i64; n];
        let mut ans = 0;

        for (i, &j) in edges.iter().enumerate() {
            let j = j as usize;
            cnt[j] += i as i64;
            if cnt[ans] < cnt[j] || (cnt[ans] == cnt[j] && j < ans) {
                ans = j;
            }
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2375. 根据模式串构造最小数字](https://leetcode.cn/problems/construct-smallest-number-from-di-string){#2375}

{{< tabs "2375" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        def dfs(u):
            nonlocal ans
            if ans:
                return
            if u == len(pattern) + 1:
                ans = ''.join(t)
                return
            for i in range(1, 10):
                if not vis[i]:
                    if u and pattern[u - 1] == 'I' and int(t[-1]) >= i:
                        continue
                    if u and pattern[u - 1] == 'D' and int(t[-1]) <= i:
                        continue
                    vis[i] = True
                    t.append(str(i))
                    dfs(u + 1)
                    vis[i] = False
                    t.pop()

        vis = [False] * 10
        t = []
        ans = None
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private boolean[] vis = new boolean[10];
    private StringBuilder t = new StringBuilder();
    private String p;
    private String ans;

    public String smallestNumber(String pattern) {
        p = pattern;
        dfs(0);
        return ans;
    }

    private void dfs(int u) {
        if (ans != null) {
            return;
        }
        if (u == p.length() + 1) {
            ans = t.toString();
            return;
        }
        for (int i = 1; i < 10; ++i) {
            if (!vis[i]) {
                if (u > 0 && p.charAt(u - 1) == 'I' && t.charAt(u - 1) - '0' >= i) {
                    continue;
                }
                if (u > 0 && p.charAt(u - 1) == 'D' && t.charAt(u - 1) - '0' <= i) {
                    continue;
                }
                vis[i] = true;
                t.append(i);
                dfs(u + 1);
                t.deleteCharAt(t.length() - 1);
                vis[i] = false;
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
    string ans = "";
    string pattern;
    vector<bool> vis;
    string t = "";

    string smallestNumber(string pattern) {
        this->pattern = pattern;
        vis.assign(10, false);
        dfs(0);
        return ans;
    }

    void dfs(int u) {
        if (ans != "") return;
        if (u == pattern.size() + 1) {
            ans = t;
            return;
        }
        for (int i = 1; i < 10; ++i) {
            if (!vis[i]) {
                if (u && pattern[u - 1] == 'I' && t.back() - '0' >= i) continue;
                if (u && pattern[u - 1] == 'D' && t.back() - '0' <= i) continue;
                vis[i] = true;
                t += to_string(i);
                dfs(u + 1);
                t.pop_back();
                vis[i] = false;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestNumber(pattern string) string {
	vis := make([]bool, 10)
	t := []byte{}
	ans := ""
	var dfs func(u int)
	dfs = func(u int) {
		if ans != "" {
			return
		}
		if u == len(pattern)+1 {
			ans = string(t)
			return
		}
		for i := 1; i < 10; i++ {
			if !vis[i] {
				if u > 0 && pattern[u-1] == 'I' && int(t[len(t)-1]-'0') >= i {
					continue
				}
				if u > 0 && pattern[u-1] == 'D' && int(t[len(t)-1]-'0') <= i {
					continue
				}
				vis[i] = true
				t = append(t, byte('0'+i))
				dfs(u + 1)
				vis[i] = false
				t = t[:len(t)-1]
			}
		}
	}
	dfs(0)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestNumber(pattern: string): string {
    const n = pattern.length;
    const res = new Array(n + 1).fill('');
    const vis = new Array(n + 1).fill(false);
    const dfs = (i: number, num: number) => {
        if (i === n) {
            return;
        }

        if (vis[num]) {
            vis[num] = false;
            if (pattern[i] === 'I') {
                dfs(i - 1, num - 1);
            } else {
                dfs(i - 1, num + 1);
            }
            return;
        }

        vis[num] = true;
        res[i] = num;

        if (pattern[i] === 'I') {
            for (let j = res[i] + 1; j <= n + 1; j++) {
                if (!vis[j]) {
                    dfs(i + 1, j);
                    return;
                }
            }
            vis[num] = false;
            dfs(i, num - 1);
        } else {
            for (let j = res[i] - 1; j > 0; j--) {
                if (!vis[j]) {
                    dfs(i + 1, j);
                    return;
                }
            }
            vis[num] = false;
            dfs(i, num + 1);
        }
    };
    dfs(0, 1);
    for (let i = 1; i <= n + 1; i++) {
        if (!vis[i]) {
            res[n] = i;
            break;
        }
    }

    return res.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你下标从 <strong>0</strong> 开始、长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>pattern</code>&nbsp;，它包含两种字符，<code>'I'</code>&nbsp;表示 <strong>上升</strong>&nbsp;，<code>'D'</code>&nbsp;表示 <strong>下降</strong>&nbsp;。</p>

<p>你需要构造一个下标从 <strong>0</strong>&nbsp;开始长度为&nbsp;<code>n + 1</code>&nbsp;的字符串，且它要满足以下条件：</p>

<ul>
	<li><code>num</code>&nbsp;包含数字&nbsp;<code>'1'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;，其中每个数字&nbsp;<strong>至多</strong>&nbsp;使用一次。</li>
	<li>如果&nbsp;<code>pattern[i] == 'I'</code>&nbsp;，那么&nbsp;<code>num[i] &lt; num[i + 1]</code>&nbsp;。</li>
	<li>如果&nbsp;<code>pattern[i] == 'D'</code>&nbsp;，那么&nbsp;<code>num[i] &gt; num[i + 1]</code>&nbsp;。</li>
</ul>

<p>请你返回满足上述条件字典序 <strong>最小</strong>&nbsp;的字符串<em>&nbsp;</em><code>num</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>pattern = "IIIDIDDD"
<b>输出：</b>"123549876"
<strong>解释：
</strong>下标 0 ，1 ，2 和 4 处，我们需要使 num[i] &lt; num[i+1] 。
下标 3 ，5 ，6 和 7 处，我们需要使 num[i] &gt; num[i+1] 。
一些可能的 num 的值为 "245639871" ，"135749862" 和 "123849765" 。
"123549876" 是满足条件最小的数字。
注意，"123414321" 不是可行解因为数字 '1' 使用次数超过 1 次。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>pattern = "DDD"
<b>输出：</b>"4321"
<strong>解释：</strong>
一些可能的 num 的值为 "9876" ，"7321" 和 "8742" 。
"4321" 是满足条件最小的数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 8</code></li>
	<li><code>pattern</code>&nbsp;只包含字符&nbsp;<code>'I'</code> 和&nbsp;<code>'D'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

定义 $dfs(u)$，其中 $u$ 表示当前答案字符串的长度。从 $u=0$ 开始搜索，直至找到第一个符合条件的字符串。

时间复杂度 $O(n!)$，空间复杂度 $O(n)$。其中 $n$ 表示字符串 $pattern$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        def dfs(u):
            nonlocal ans
            if ans:
                return
            if u == len(pattern) + 1:
                ans = ''.join(t)
                return
            for i in range(1, 10):
                if not vis[i]:
                    if u and pattern[u - 1] == 'I' and int(t[-1]) >= i:
                        continue
                    if u and pattern[u - 1] == 'D' and int(t[-1]) <= i:
                        continue
                    vis[i] = True
                    t.append(str(i))
                    dfs(u + 1)
                    vis[i] = False
                    t.pop()

        vis = [False] * 10
        t = []
        ans = None
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private boolean[] vis = new boolean[10];
    private StringBuilder t = new StringBuilder();
    private String p;
    private String ans;

    public String smallestNumber(String pattern) {
        p = pattern;
        dfs(0);
        return ans;
    }

    private void dfs(int u) {
        if (ans != null) {
            return;
        }
        if (u == p.length() + 1) {
            ans = t.toString();
            return;
        }
        for (int i = 1; i < 10; ++i) {
            if (!vis[i]) {
                if (u > 0 && p.charAt(u - 1) == 'I' && t.charAt(u - 1) - '0' >= i) {
                    continue;
                }
                if (u > 0 && p.charAt(u - 1) == 'D' && t.charAt(u - 1) - '0' <= i) {
                    continue;
                }
                vis[i] = true;
                t.append(i);
                dfs(u + 1);
                t.deleteCharAt(t.length() - 1);
                vis[i] = false;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string ans = "";
    string pattern;
    vector<bool> vis;
    string t = "";

    string smallestNumber(string pattern) {
        this->pattern = pattern;
        vis.assign(10, false);
        dfs(0);
        return ans;
    }

    void dfs(int u) {
        if (ans != "") return;
        if (u == pattern.size() + 1) {
            ans = t;
            return;
        }
        for (int i = 1; i < 10; ++i) {
            if (!vis[i]) {
                if (u && pattern[u - 1] == 'I' && t.back() - '0' >= i) continue;
                if (u && pattern[u - 1] == 'D' && t.back() - '0' <= i) continue;
                vis[i] = true;
                t += to_string(i);
                dfs(u + 1);
                t.pop_back();
                vis[i] = false;
            }
        }
    }
};
```

#### Go

```go
func smallestNumber(pattern string) string {
	vis := make([]bool, 10)
	t := []byte{}
	ans := ""
	var dfs func(u int)
	dfs = func(u int) {
		if ans != "" {
			return
		}
		if u == len(pattern)+1 {
			ans = string(t)
			return
		}
		for i := 1; i < 10; i++ {
			if !vis[i] {
				if u > 0 && pattern[u-1] == 'I' && int(t[len(t)-1]-'0') >= i {
					continue
				}
				if u > 0 && pattern[u-1] == 'D' && int(t[len(t)-1]-'0') <= i {
					continue
				}
				vis[i] = true
				t = append(t, byte('0'+i))
				dfs(u + 1)
				vis[i] = false
				t = t[:len(t)-1]
			}
		}
	}
	dfs(0)
	return ans
}
```

#### TypeScript

```ts
function smallestNumber(pattern: string): string {
    const n = pattern.length;
    const res = new Array(n + 1).fill('');
    const vis = new Array(n + 1).fill(false);
    const dfs = (i: number, num: number) => {
        if (i === n) {
            return;
        }

        if (vis[num]) {
            vis[num] = false;
            if (pattern[i] === 'I') {
                dfs(i - 1, num - 1);
            } else {
                dfs(i - 1, num + 1);
            }
            return;
        }

        vis[num] = true;
        res[i] = num;

        if (pattern[i] === 'I') {
            for (let j = res[i] + 1; j <= n + 1; j++) {
                if (!vis[j]) {
                    dfs(i + 1, j);
                    return;
                }
            }
            vis[num] = false;
            dfs(i, num - 1);
        } else {
            for (let j = res[i] - 1; j > 0; j--) {
                if (!vis[j]) {
                    dfs(i + 1, j);
                    return;
                }
            }
            vis[num] = false;
            dfs(i, num + 1);
        }
    };
    dfs(0, 1);
    for (let i = 1; i <= n + 1; i++) {
        if (!vis[i]) {
            res[n] = i;
            break;
        }
    }

    return res.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers){#2376}

{{< tabs "2376" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        @cache
        def dfs(i: int, mask: int, lead: bool, limit: bool) -> int:
            if i >= len(s):
                return int(lead ^ 1)
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if mask >> j & 1:
                    continue
                if lead and j == 0:
                    ans += dfs(i + 1, mask, True, limit and j == up)
                else:
                    ans += dfs(i + 1, mask | 1 << j, False, limit and j == up)
            return ans

        s = str(n)
        return dfs(0, 0, True, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;
    private Integer[][] f;

    public int countSpecialNumbers(int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length][1 << 10];
        return dfs(0, 0, true, true);
    }

    private int dfs(int i, int mask, boolean lead, boolean limit) {
        if (i >= s.length) {
            return lead ? 0 : 1;
        }
        if (!limit && !lead && f[i][mask] != null) {
            return f[i][mask];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if ((mask >> j & 1) == 1) {
                continue;
            }
            if (lead && j == 0) {
                ans += dfs(i + 1, mask, true, limit && j == up);
            } else {
                ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
            }
        }
        if (!limit && !lead) {
            f[i][mask] = ans;
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
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ^ 1;
            }
            if (!limit && !lead && f[i][mask] != -1) {
                return f[i][mask];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (mask >> j & 1) {
                    continue;
                }
                if (lead && j == 0) {
                    ans += dfs(i + 1, mask, true, limit && j == up);
                } else {
                    ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
                }
            }
            if (!limit && !lead) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSpecialNumbers(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][1 << 10]int, m+1)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int, bool, bool) int
	dfs = func(i, mask int, lead, limit bool) int {
		if i >= m {
			if lead {
				return 0
			}
			return 1
		}
		if !limit && !lead && f[i][mask] != -1 {
			return f[i][mask]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if mask>>j&1 == 1 {
				continue
			}
			if lead && j == 0 {
				ans += dfs(i+1, mask, true, limit && j == up)
			} else {
				ans += dfs(i+1, mask|1<<j, false, limit && j == up)
			}
		}
		if !limit && !lead {
			f[i][mask] = ans
		}
		return ans
	}
	return dfs(0, 0, true, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSpecialNumbers(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[][] = Array.from({ length: m }, () => Array(1 << 10).fill(-1));
    const dfs = (i: number, mask: number, lead: boolean, limit: boolean): number => {
        if (i >= m) {
            return lead ? 0 : 1;
        }
        if (!limit && !lead && f[i][mask] !== -1) {
            return f[i][mask];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if ((mask >> j) & 1) {
                continue;
            }
            if (lead && j === 0) {
                ans += dfs(i + 1, mask, true, limit && j === up);
            } else {
                ans += dfs(i + 1, mask | (1 << j), false, limit && j === up);
            }
        }
        if (!limit && !lead) {
            f[i][mask] = ans;
        }
        return ans;
    };
    return dfs(0, 0, true, true);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个正整数每一个数位都是 <strong>互不相同</strong>&nbsp;的，我们称它是 <strong>特殊整数</strong> 。</p>

<p>给你一个 <strong>正</strong>&nbsp;整数&nbsp;<code>n</code>&nbsp;，请你返回区间<em>&nbsp;</em><code>[1, n]</code>&nbsp;之间特殊整数的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 20
<b>输出：</b>19
<b>解释：</b>1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 5
<b>输出：</b>5
<b>解释：</b>1 到 5 所有整数都是特殊整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 135
<b>输出：</b>110
<b>解释：</b>从 1 到 135 总共有 110 个整数是特殊整数。
不特殊的部分数字为：22 ，114 和 131 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，满足条件的数的个数。条件与数的大小无关，而只与数的组成有关，因此可以使用数位 DP 的思想求解。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

不过对于本题而言，我们只需要求出区间 $[1,..n]$ 的值即可。

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

我们根据题目信息，设计一个函数 $\textit{dfs}(i, \textit{mask}, \textit{lead}, \textit{limit})$，其中：

-   数字 $i$ 表示当前搜索到的位置，我们从高位开始搜索，即 $i = 0$ 表示最高位。
-   数字 $\textit{mask}$ 表示当前数字的状态，即 $\textit{mask}$ 的第 $j$ 位为 $1$ 表示数字 $j$ 已经被使用过。
-   布尔值 $\textit{lead}$ 表示当前是否只包含前导 $0$。
-   布尔值 $\textit{limit}$ 表示当前是否受到上界的限制。

函数的执行过程如下：

如果 $i$ 超过了数字 $n$ 的长度，说明搜索结束，如果此时 $\textit{lead}$ 为真，说明当前数字只包含前导 $0$，直接返回 $0$，否则返回 $1$。

如果 $\textit{limit}$ 为假且 $\textit{lead}$ 为假且 $\textit{mask}$ 的状态已经被记忆化，直接返回记忆化的结果。

否则，我们计算当前数字的上界 $up$，如果 $\textit{limit}$ 为真，$up$ 为当前数字的第 $i$ 位，否则 $up = 9$。

然后我们遍历 $[0, up]$，对于每个数字 $j$，如果 $\textit{mask}$ 的第 $j$ 位为 $1$，说明数字 $j$ 已经被使用过，直接跳过。否则，如果 $\textit{lead}$ 为真且 $j = 0$，说明当前数字只包含前导 $0$，递归搜索下一位，否则递归搜索下一位并更新 $\textit{mask}$ 的状态。

最后，如果 $\textit{limit}$ 为假且 $\textit{lead}$ 为假，将当前状态记忆化。

最终返回答案。

时间复杂度 $O(m \times 2^D \times D)$，空间复杂度 $O(m \times 2^D)$。其中 $m$ 为数字 $n$ 的长度，而 $D = 10$。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)
-   [357. 统计各位数字都不同的数字个数](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0357.Count%20Numbers%20with%20Unique%20Digits/README.md)
-   [600. 不含连续 1 的非负整数](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0600.Non-negative%20Integers%20without%20Consecutive%20Ones/README.md)
-   [788. 旋转数字](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0788.Rotated%20Digits/README.md)
-   [902. 最大为 N 的数字组合](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0902.Numbers%20At%20Most%20N%20Given%20Digit%20Set/README.md)
-   [1012. 至少有 1 位重复的数字](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1012.Numbers%20With%20Repeated%20Digits/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        @cache
        def dfs(i: int, mask: int, lead: bool, limit: bool) -> int:
            if i >= len(s):
                return int(lead ^ 1)
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if mask >> j & 1:
                    continue
                if lead and j == 0:
                    ans += dfs(i + 1, mask, True, limit and j == up)
                else:
                    ans += dfs(i + 1, mask | 1 << j, False, limit and j == up)
            return ans

        s = str(n)
        return dfs(0, 0, True, True)
```

#### Java

```java
class Solution {
    private char[] s;
    private Integer[][] f;

    public int countSpecialNumbers(int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length][1 << 10];
        return dfs(0, 0, true, true);
    }

    private int dfs(int i, int mask, boolean lead, boolean limit) {
        if (i >= s.length) {
            return lead ? 0 : 1;
        }
        if (!limit && !lead && f[i][mask] != null) {
            return f[i][mask];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if ((mask >> j & 1) == 1) {
                continue;
            }
            if (lead && j == 0) {
                ans += dfs(i + 1, mask, true, limit && j == up);
            } else {
                ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
            }
        }
        if (!limit && !lead) {
            f[i][mask] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ^ 1;
            }
            if (!limit && !lead && f[i][mask] != -1) {
                return f[i][mask];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (mask >> j & 1) {
                    continue;
                }
                if (lead && j == 0) {
                    ans += dfs(i + 1, mask, true, limit && j == up);
                } else {
                    ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
                }
            }
            if (!limit && !lead) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true, true);
    }
};
```

#### Go

```go
func countSpecialNumbers(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][1 << 10]int, m+1)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int, bool, bool) int
	dfs = func(i, mask int, lead, limit bool) int {
		if i >= m {
			if lead {
				return 0
			}
			return 1
		}
		if !limit && !lead && f[i][mask] != -1 {
			return f[i][mask]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if mask>>j&1 == 1 {
				continue
			}
			if lead && j == 0 {
				ans += dfs(i+1, mask, true, limit && j == up)
			} else {
				ans += dfs(i+1, mask|1<<j, false, limit && j == up)
			}
		}
		if !limit && !lead {
			f[i][mask] = ans
		}
		return ans
	}
	return dfs(0, 0, true, true)
}
```

#### TypeScript

```ts
function countSpecialNumbers(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[][] = Array.from({ length: m }, () => Array(1 << 10).fill(-1));
    const dfs = (i: number, mask: number, lead: boolean, limit: boolean): number => {
        if (i >= m) {
            return lead ? 0 : 1;
        }
        if (!limit && !lead && f[i][mask] !== -1) {
            return f[i][mask];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if ((mask >> j) & 1) {
                continue;
            }
            if (lead && j === 0) {
                ans += dfs(i + 1, mask, true, limit && j === up);
            } else {
                ans += dfs(i + 1, mask | (1 << j), false, limit && j === up);
            }
        }
        if (!limit && !lead) {
            f[i][mask] = ans;
        }
        return ans;
    };
    return dfs(0, 0, true, true);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2377. 整理奥运表 🔒](https://leetcode.cn/problems/sort-the-olympic-table){#2377}

{{< tabs "2377" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT *
FROM Olympic
ORDER BY 2 DESC, 3 DESC, 4 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Olympic</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| country       | varchar |
| gold_medals   | int     |
| silver_medals | int     |
| bronze_medals | int     |
+---------------+---------+
在 SQL 中，country 是该表的主键。
该表中的每一行都显示了一个国家的名称以及它在奥运会上获得的金、银、铜牌的数量。
</pre>

<p>&nbsp;</p>

<p>奥运名次表的排序规则如下:</p>

<ul>
	<li>金牌越多的国家排名第一。</li>
	<li>如果金牌数持平，银牌多的国家排名第一。</li>
	<li>如果银牌数量持平，铜牌数量最多的国家排名第一。</li>
	<li>如果铜牌中出现并列，那么并列的国家将按照字典的升序进行排序。</li>
</ul>

<p>写一个解决方案对奥运表进行排序</p>

<p>返回结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Olympic 表:
+-------------+-------------+---------------+---------------+
| country     | gold_medals | silver_medals | bronze_medals |
+-------------+-------------+---------------+---------------+
| China       | 10          | 10            | 20            |
| South Sudan | 0           | 0             | 1             |
| USA         | 10          | 10            | 20            |
| Israel      | 2           | 2             | 3             |
| Egypt       | 2           | 2             | 2             |
+-------------+-------------+---------------+---------------+
<strong>输出:</strong> 
+-------------+-------------+---------------+---------------+
| country     | gold_medals | silver_medals | bronze_medals |
+-------------+-------------+---------------+---------------+
| China       | 10          | 10            | 20            |
| USA         | 10          | 10            | 20            |
| Israel      | 2           | 2             | 3             |
| Egypt       | 2           | 2             | 2             |
| South Sudan | 0           | 0             | 1             |
+-------------+-------------+---------------+---------------+
<strong>解释:</strong> 
中国和美国之间的联系被它们的字典名称打破了。因为 "China" 在字典上比 "USA" 小，所以它排在第一位。
以色列排在埃及之前，因为它的铜牌更多。</pre>

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
SELECT *
FROM Olympic
ORDER BY 2 DESC, 3 DESC, 4 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2378. 选择边来最大化树的得分 🔒](https://leetcode.cn/problems/choose-edges-to-maximize-score-in-a-tree){#2378}

{{< tabs "2378" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, edges: List[List[int]]) -> int:
        def dfs(i):
            a = b = t = 0
            for j, w in g[i]:
                x, y = dfs(j)
                a += y
                b += y
                t = max(t, x - y + w)
            b += t
            return a, b

        g = defaultdict(list)
        for i, (p, w) in enumerate(edges[1:], 1):
            g[p].append((i, w))
        return dfs(0)[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<int[]>[] g;

    public long maxScore(int[][] edges) {
        int n = edges.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            int p = edges[i][0], w = edges[i][1];
            g[p].add(new int[] {i, w});
        }
        return dfs(0)[1];
    }

    private long[] dfs(int i) {
        long a = 0, b = 0, t = 0;
        for (int[] nxt : g[i]) {
            int j = nxt[0], w = nxt[1];
            long[] s = dfs(j);
            a += s[1];
            b += s[1];
            t = Math.max(t, s[0] - s[1] + w);
        }
        b += t;
        return new long[] {a, b};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pair<int, int>>> g(n);
        for (int i = 1; i < n; ++i) {
            int p = edges[i][0], w = edges[i][1];
            g[p].emplace_back(i, w);
        }
        using ll = long long;
        using pll = pair<ll, ll>;
        function<pll(int)> dfs = [&](int i) -> pll {
            ll a = 0, b = 0, t = 0;
            for (auto& [j, w] : g[i]) {
                auto [x, y] = dfs(j);
                a += y;
                b += y;
                t = max(t, x - y + w);
            }
            b += t;
            return make_pair(a, b);
        };
        return dfs(0).second;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(edges [][]int) int64 {
	n := len(edges)
	g := make([][][2]int, n)
	for i := 1; i < n; i++ {
		p, w := edges[i][0], edges[i][1]
		g[p] = append(g[p], [2]int{i, w})
	}
	var dfs func(int) [2]int
	dfs = func(i int) [2]int {
		var a, b, t int
		for _, e := range g[i] {
			j, w := e[0], e[1]
			s := dfs(j)
			a += s[1]
			b += s[1]
			t = max(t, s[0]-s[1]+w)
		}
		b += t
		return [2]int{a, b}
	}
	return int64(dfs(0)[1])
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个&nbsp;<strong>加权&nbsp;</strong>树，由 <code>n</code> 个节点组成，从 <code>0</code> 到 <code>n - 1</code>。</p>

<p>该树以节点 0 为&nbsp;<strong>根</strong>，用大小为 <code>n</code> 的二维数组 <code>edges</code> 表示，其中 <code>edges[i] = [par<sub>i</sub>, weight<sub>i</sub>]</code> 表示节点 <code>par<sub>i</sub></code> 是节点 <code>i</code>&nbsp;的&nbsp;<strong>父&nbsp;</strong>节点，它们之间的边的权重等于 <code>weight<sub>i</sub></code>。因为根结点&nbsp;<strong>没有&nbsp;</strong>父结点，所以有 <code>edges[0] = [-1, -1]</code>。</p>

<p>从树中选择一些边，使所选的两条边都不&nbsp;<strong>相邻</strong>，所选边的权值之 <strong>和</strong> 最大。</p>

<p>&nbsp;</p>

<p>返回<em>所选边的&nbsp;<strong>最大&nbsp;</strong>和。</em></p>

<p><strong>注意</strong>:</p>

<ul>
	<li>你可以&nbsp;<strong>不选择&nbsp;</strong>树中的任何边，在这种情况下权值和将为 <code>0</code>。</li>
	<li>如果树中的两条边 <code>Edge<sub>1</sub></code> 和 <code>Edge<sub>2</sub></code> 有一个&nbsp;<strong>公共&nbsp;</strong>节点，它们就是&nbsp;<strong>相邻&nbsp;</strong>的。
	<ul>
		<li>换句话说，如果 <code>Edge<sub>1</sub></code>连接节点 <code>a</code> 和 <code>b</code>, <code>Edge<sub>2</sub></code> 连接节点 <code>b</code> 和 <code>c</code>，它们是相邻的。</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2378.Choose%20Edges%20to%20Maximize%20Score%20in%20a%20Tree/images/treedrawio.png" style="width: 271px; height: 221px;" />
<pre>
<strong>输入:</strong> edges = [[-1,-1],[0,5],[0,10],[2,6],[2,4]]
<strong>输出:</strong> 11
<strong>解释:</strong> 上面的图表显示了我们必须选择红色的边。
总分是 5 + 6 = 11.
可以看出，没有更好的分数可以获得。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2378.Choose%20Edges%20to%20Maximize%20Score%20in%20a%20Tree/images/treee1293712983719827.png" style="width: 221px; height: 181px;" />
<pre>
<strong>输入:</strong> edges = [[-1,-1],[0,5],[0,-6],[0,7]]
<strong>输出:</strong> 7
<strong>解释:</strong> 我们选择权值为 7 的边。
注意，我们不能选择一条以上的边，因为所有的边都是彼此相邻的。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>par<sub>0</sub> == weight<sub>0</sub> == -1</code></li>
	<li><code>i &gt;= 1</code>&nbsp;时&nbsp;<code>0 &lt;= par<sub>i</sub> &lt;= n - 1</code>&nbsp;。</li>
	<li><code>par<sub>i</sub> != i</code></li>
	<li><code>i &gt;= 1</code>&nbsp;时&nbsp;<code>-10<sup>6</sup> &lt;= weight<sub>i</sub> &lt;= 10<sup>6</sup></code> 。</li>
	<li><code>edges</code> 表示有效的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP

我们设计一个函数 $dfs(i)$，表示以节点 $i$ 为根的子树中，选择一些边，使得所选的两条边都不相邻，所选边的权值之和最大。该函数返回了两个值 $(a, b)$，第一个值 $a$ 表示当前节点 $i$ 与其父节点之间的边被选中时，所选边的权值之和；第二个值 $b$ 表示当前节点 $i$ 与其父节点之间的边不被选中时，所选边的权值之和。

我们可以发现，对于当前节点 $i$：

-   如果 $i$ 与父节点的边被选择，则它与子节点的所有边都不能被选择，那么当前节点的 $a$ 值就是其所有子节点的 $b$ 值之和；
-   如果 $i$ 与父节点的边没被选择，那么可以选择它与子节点的最多一条边，那么当前节点的 $b$ 值就是其选中的子节点的 $a$ 值与未选中的子节点的 $b$ 值之和，再加上 $i$ 与选中的子节点之间的边的权值。

我们调用 $dfs(0)$ 函数，返回的第二个值即为答案，即当前根节点不与父节点之间的边被选中时，所选边的权值之和。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, edges: List[List[int]]) -> int:
        def dfs(i):
            a = b = t = 0
            for j, w in g[i]:
                x, y = dfs(j)
                a += y
                b += y
                t = max(t, x - y + w)
            b += t
            return a, b

        g = defaultdict(list)
        for i, (p, w) in enumerate(edges[1:], 1):
            g[p].append((i, w))
        return dfs(0)[1]
```

#### Java

```java
class Solution {
    private List<int[]>[] g;

    public long maxScore(int[][] edges) {
        int n = edges.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            int p = edges[i][0], w = edges[i][1];
            g[p].add(new int[] {i, w});
        }
        return dfs(0)[1];
    }

    private long[] dfs(int i) {
        long a = 0, b = 0, t = 0;
        for (int[] nxt : g[i]) {
            int j = nxt[0], w = nxt[1];
            long[] s = dfs(j);
            a += s[1];
            b += s[1];
            t = Math.max(t, s[0] - s[1] + w);
        }
        b += t;
        return new long[] {a, b};
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pair<int, int>>> g(n);
        for (int i = 1; i < n; ++i) {
            int p = edges[i][0], w = edges[i][1];
            g[p].emplace_back(i, w);
        }
        using ll = long long;
        using pll = pair<ll, ll>;
        function<pll(int)> dfs = [&](int i) -> pll {
            ll a = 0, b = 0, t = 0;
            for (auto& [j, w] : g[i]) {
                auto [x, y] = dfs(j);
                a += y;
                b += y;
                t = max(t, x - y + w);
            }
            b += t;
            return make_pair(a, b);
        };
        return dfs(0).second;
    }
};
```

#### Go

```go
func maxScore(edges [][]int) int64 {
	n := len(edges)
	g := make([][][2]int, n)
	for i := 1; i < n; i++ {
		p, w := edges[i][0], edges[i][1]
		g[p] = append(g[p], [2]int{i, w})
	}
	var dfs func(int) [2]int
	dfs = func(i int) [2]int {
		var a, b, t int
		for _, e := range g[i] {
			j, w := e[0], e[1]
			s := dfs(j)
			a += s[1]
			b += s[1]
			t = max(t, s[0]-s[1]+w)
		}
		b += t
		return [2]int{a, b}
	}
	return int64(dfs(0)[1])
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2379. 得到 K 个黑块的最少涂色次数](https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks){#2379}

{{< tabs "2379" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = cnt = blocks[:k].count('W')
        for i in range(k, len(blocks)):
            cnt += blocks[i] == 'W'
            cnt -= blocks[i - k] == 'W'
            ans = min(ans, cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumRecolors(String blocks, int k) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += blocks.charAt(i) == 'W' ? 1 : 0;
        }
        int ans = cnt;
        for (int i = k; i < blocks.length(); ++i) {
            cnt += blocks.charAt(i) == 'W' ? 1 : 0;
            cnt -= blocks.charAt(i - k) == 'W' ? 1 : 0;
            ans = Math.min(ans, cnt);
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
    int minimumRecolors(string blocks, int k) {
        int cnt = count(blocks.begin(), blocks.begin() + k, 'W');
        int ans = cnt;
        for (int i = k; i < blocks.size(); ++i) {
            cnt += blocks[i] == 'W';
            cnt -= blocks[i - k] == 'W';
            ans = min(ans, cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRecolors(blocks string, k int) int {
	cnt := strings.Count(blocks[:k], "W")
	ans := cnt
	for i := k; i < len(blocks); i++ {
		if blocks[i] == 'W' {
			cnt++
		}
		if blocks[i-k] == 'W' {
			cnt--
		}
		if ans > cnt {
			ans = cnt
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRecolors(blocks: string, k: number): number {
    let cnt = 0;
    for (let i = 0; i < k; ++i) {
        cnt += blocks[i] === 'W' ? 1 : 0;
    }
    let ans = cnt;
    for (let i = k; i < blocks.length; ++i) {
        cnt += blocks[i] === 'W' ? 1 : 0;
        cnt -= blocks[i - k] === 'W' ? 1 : 0;
        ans = Math.min(ans, cnt);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let k = k as usize;
        let s = blocks.as_bytes();
        let n = s.len();
        let mut count = 0;
        for i in 0..k {
            if s[i] == b'B' {
                count += 1;
            }
        }
        let mut ans = k - count;
        for i in k..n {
            if s[i - k] == b'B' {
                count -= 1;
            }
            if s[i] == b'B' {
                count += 1;
            }
            ans = ans.min(k - count);
        }
        ans as i32
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $blocks
     * @param Integer $k
     * @return Integer
     */
    function minimumRecolors($blocks, $k) {
        $cnt = 0;
        for ($i = 0; $i < $k; $i++) {
            if ($blocks[$i] === 'W') {
                $cnt++;
            }
        }
        $min = $cnt;
        for ($i = $k; $i < strlen($blocks); $i++) {
            if ($blocks[$i] === 'W') {
                $cnt++;
            }
            if ($blocks[$i - $k] === 'W') {
                $cnt--;
            }
            $min = min($min, $cnt);
        }
        return $min;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minimumRecolors(char* blocks, int k) {
    int n = strlen(blocks);
    int count = 0;
    for (int i = 0; i < k; i++) {
        count += blocks[i] == 'B';
    }
    int ans = k - count;
    for (int i = k; i < n; i++) {
        count -= blocks[i - k] == 'B';
        count += blocks[i] == 'B';
        ans = min(ans, k - count);
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

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>blocks</code>&nbsp;，<code>blocks[i]</code>&nbsp;要么是&nbsp;<code>'W'</code>&nbsp;要么是&nbsp;<code>'B'</code>&nbsp;，表示第&nbsp;<code>i</code>&nbsp;块的颜色。字符&nbsp;<code>'W'</code> 和&nbsp;<code>'B'</code>&nbsp;分别表示白色和黑色。</p>

<p>给你一个整数&nbsp;<code>k</code>&nbsp;，表示想要&nbsp;<strong>连续</strong>&nbsp;黑色块的数目。</p>

<p>每一次操作中，你可以选择一个白色块将它 <strong>涂成</strong>&nbsp;黑色块。</p>

<p>请你返回至少出现 <strong>一次</strong>&nbsp;连续 <code>k</code>&nbsp;个黑色块的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>blocks = "WBBWWBBWBW", k = 7
<b>输出：</b>3
<strong>解释：</strong>
一种得到 7 个连续黑色块的方法是把第 0 ，3 和 4 个块涂成黑色。
得到 blocks = "BBBBBBBWBW" 。
可以证明无法用少于 3 次操作得到 7 个连续的黑块。
所以我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>blocks = "WBWBBBW", k = 2
<b>输出：</b>0
<strong>解释：</strong>
不需要任何操作，因为已经有 2 个连续的黑块。
所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>n == blocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>blocks[i]</code>&nbsp;要么是&nbsp;<code>'W'</code>&nbsp;，要么是&nbsp;<code>'B'</code> 。</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们观察发现，题目实际上求的是一个 $k$ 大小的滑动窗口中白色块的最小数量。

因此，我们只需要遍历字符串 $blocks$，用一个变量 $cnt$ 统计当前窗口中白色块的数量，然后用一个变量 $ans$ 维护最小值即可。

遍历结束后即可得到答案。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $blocks$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = cnt = blocks[:k].count('W')
        for i in range(k, len(blocks)):
            cnt += blocks[i] == 'W'
            cnt -= blocks[i - k] == 'W'
            ans = min(ans, cnt)
        return ans
```

#### Java

```java
class Solution {
    public int minimumRecolors(String blocks, int k) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += blocks.charAt(i) == 'W' ? 1 : 0;
        }
        int ans = cnt;
        for (int i = k; i < blocks.length(); ++i) {
            cnt += blocks.charAt(i) == 'W' ? 1 : 0;
            cnt -= blocks.charAt(i - k) == 'W' ? 1 : 0;
            ans = Math.min(ans, cnt);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = count(blocks.begin(), blocks.begin() + k, 'W');
        int ans = cnt;
        for (int i = k; i < blocks.size(); ++i) {
            cnt += blocks[i] == 'W';
            cnt -= blocks[i - k] == 'W';
            ans = min(ans, cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumRecolors(blocks string, k int) int {
	cnt := strings.Count(blocks[:k], "W")
	ans := cnt
	for i := k; i < len(blocks); i++ {
		if blocks[i] == 'W' {
			cnt++
		}
		if blocks[i-k] == 'W' {
			cnt--
		}
		if ans > cnt {
			ans = cnt
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumRecolors(blocks: string, k: number): number {
    let cnt = 0;
    for (let i = 0; i < k; ++i) {
        cnt += blocks[i] === 'W' ? 1 : 0;
    }
    let ans = cnt;
    for (let i = k; i < blocks.length; ++i) {
        cnt += blocks[i] === 'W' ? 1 : 0;
        cnt -= blocks[i - k] === 'W' ? 1 : 0;
        ans = Math.min(ans, cnt);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let k = k as usize;
        let s = blocks.as_bytes();
        let n = s.len();
        let mut count = 0;
        for i in 0..k {
            if s[i] == b'B' {
                count += 1;
            }
        }
        let mut ans = k - count;
        for i in k..n {
            if s[i - k] == b'B' {
                count -= 1;
            }
            if s[i] == b'B' {
                count += 1;
            }
            ans = ans.min(k - count);
        }
        ans as i32
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $blocks
     * @param Integer $k
     * @return Integer
     */
    function minimumRecolors($blocks, $k) {
        $cnt = 0;
        for ($i = 0; $i < $k; $i++) {
            if ($blocks[$i] === 'W') {
                $cnt++;
            }
        }
        $min = $cnt;
        for ($i = $k; $i < strlen($blocks); $i++) {
            if ($blocks[$i] === 'W') {
                $cnt++;
            }
            if ($blocks[$i - $k] === 'W') {
                $cnt--;
            }
            $min = min($min, $cnt);
        }
        return $min;
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minimumRecolors(char* blocks, int k) {
    int n = strlen(blocks);
    int count = 0;
    for (int i = 0; i < k; i++) {
        count += blocks[i] == 'B';
    }
    int ans = k - count;
    for (int i = k; i < n; i++) {
        count -= blocks[i - k] == 'B';
        count += blocks[i] == 'B';
        ans = min(ans, k - count);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
