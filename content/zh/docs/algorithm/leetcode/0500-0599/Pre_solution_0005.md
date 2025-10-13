---
title: "0540_有序数组中的单一元素"
date: 2025-10-08T18:36:17+08:00
weight: 5
tags: [二分查找, 二叉树, 前缀和, 动态规划, 双指针, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 数组, 树, 模拟, 深度优先搜索, 矩阵, 记忆化搜索, 递归]
---

{{< markmap >}}
### [0540_有序数组中的单一元素](#540)
#### [数组](#540)
#### [二分查找](#540)
### [0541_反转字符串 II](#541)
#### [双指针](#541)
#### [字符串](#541)
### [0542_01 矩阵](#542)
#### [广度优先搜索](#542)
#### [数组](#542)
#### [动态规划](#542)
#### [矩阵](#542)
### [0543_二叉树的直径](#543)
#### [树](#543)
#### [深度优先搜索](#543)
#### [二叉树](#543)
### [0544_输出比赛匹配对 🔒](#544)
#### [递归](#544)
#### [字符串](#544)
#### [模拟](#544)
### [0545_二叉树的边界 🔒](#545)
#### [树](#545)
#### [深度优先搜索](#545)
#### [二叉树](#545)
### [0546_移除盒子](#546)
#### [记忆化搜索](#546)
#### [数组](#546)
#### [动态规划](#546)
### [0547_省份数量](#547)
#### [深度优先搜索](#547)
#### [广度优先搜索](#547)
#### [并查集](#547)
#### [图](#547)
### [0548_将数组分割成和相等的子数组 🔒](#548)
#### [数组](#548)
#### [哈希表](#548)
#### [前缀和](#548)
### [0549_二叉树最长连续序列 II 🔒](#549)
#### [树](#549)
#### [深度优先搜索](#549)
#### [二叉树](#549)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0540_有序数组中的单一元素
___
#### 数组
___
#### 二分查找
---
### 0541_反转字符串 II
___
#### 双指针
___
#### 字符串
---
### 0542_01 矩阵
___
#### 广度优先搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0543_二叉树的直径
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0544_输出比赛匹配对 🔒
___
#### 递归
___
#### 字符串
___
#### 模拟
---
### 0545_二叉树的边界 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0546_移除盒子
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
---
### 0547_省份数量
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0548_将数组分割成和相等的子数组 🔒
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 0549_二叉树最长连续序列 II 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 数组 | 树 |
| 模拟 | 深度优先搜索 | 矩阵 |
| 记忆化搜索 | 递归 |  |

# [540. 有序数组中的单一元素](https://leetcode.cn/problems/single-element-in-a-sorted-array){#540}

{{< tabs "540" >}}

{{% tab "python" %}}
```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] != nums[mid ^ 1]:
                r = mid
            else:
                l = mid + 1
        return nums[l]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func singleNonDuplicate(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] != nums[mid^1] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return nums[l]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function singleNonDuplicate(nums: number[]): number {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] !== nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] != nums[mid ^ 1] {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        nums[l]
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] != nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。</p>

<p>请你找出并返回只出现一次的那个数。</p>

<p>你设计的解决方案必须满足 <code>O(log n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>输出:</strong> 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums =  [3,3,7,7,10,11,11]
<strong>输出:</strong> 10
</pre>

<p>&nbsp;</p>

<p><meta charset="UTF-8" /></p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

题目给定的数组 $\textit{nums}$ 是有序的，且要求在 $\textit{O}(\log n)$ 时间找到只出现一次的元素，因此我们考虑使用二分查找解决。

我们定义二分查找的左边界 $\textit{l} = 0$，右边界 $\textit{r} = n - 1$，其中 $n$ 是数组的长度。

在每一步中，我们取中间位置 $\textit{mid} = (l + r) / 2$，如果下标 $\textit{mid}$ 为偶数，那么我们应该将 $\textit{nums}[\textit{mid}]$ 与 $\textit{nums}[\textit{mid} + 1]$ 进行比较；如果下标 $\textit{mid}$ 为奇数，那么我们应该将 $\textit{nums}[\textit{mid}]$ 与 $\textit{nums}[\textit{mid} - 1]$ 进行比较。因此，我们可以统一将 $\textit{nums}[\textit{mid}]$ 与 $\textit{nums}[\textit{mid} \oplus 1]$ 进行比较，其中 $\oplus$ 表示异或运算。

如果 $\textit{nums}[\textit{mid}] \neq \textit{nums}[\textit{mid} \oplus 1]$，那么答案在 $[\textit{l}, \textit{mid}]$ 中，我们令 $\textit{r} = \textit{mid}$；如果 $\textit{nums}[\textit{mid}] = \textit{nums}[\textit{mid} \oplus 1]$，那么答案在 $[\textit{mid} + 1, \textit{r}]$ 中，我们令 $\textit{l} = \textit{mid} + 1$。继续二分查找，直到 $\textit{l} = \textit{r}$，此时 $\textit{nums}[\textit{l}]$ 即为只出现一次的元素。

时间复杂度 $\textit{O}(\log n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $\textit{O}(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] != nums[mid ^ 1]:
                r = mid
            else:
                l = mid + 1
        return nums[l]
```

#### Java

```java
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
```

#### Go

```go
func singleNonDuplicate(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] != nums[mid^1] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return nums[l]
}
```

#### TypeScript

```ts
function singleNonDuplicate(nums: number[]): number {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] !== nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
```

#### Rust

```rust
impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l < r {
            let mid = (l + r) >> 1;
            if nums[mid] != nums[mid ^ 1] {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        nums[l]
    }
}
```

#### C

```c
int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] != nums[mid ^ 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [541. 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii){#541}

{{< tabs "541" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        cs = list(s)
        for i in range(0, len(cs), 2 * k):
            cs[i : i + k] = reversed(cs[i : i + k])
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reverseStr(String s, int k) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        for (int i = 0; i < n; i += k * 2) {
            for (int l = i, r = Math.min(i + k - 1, n - 1); l < r; ++l, --r) {
                char t = cs[l];
                cs[l] = cs[r];
                cs[r] = t;
            }
        }
        return new String(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseStr(s string, k int) string {
	cs := []byte(s)
	n := len(cs)
	for i := 0; i < n; i += 2 * k {
		for l, r := i, min(i+k-1, n-1); l < r; l, r = l+1, r-1 {
			cs[l], cs[r] = cs[r], cs[l]
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reverseStr(s: string, k: number): string {
    const n = s.length;
    const cs = s.split('');
    for (let i = 0; i < n; i += 2 * k) {
        for (let l = i, r = Math.min(i + k - 1, n - 1); l < r; l++, r--) {
            [cs[l], cs[r]] = [cs[r], cs[l]];
        }
    }
    return cs.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>s</code> 和一个整数 <code>k</code>，从字符串开头算起，每计数至 <code>2k</code> 个字符，就反转这 <code>2k</code> 字符中的前 <code>k</code> 个字符。</p>

<ul>
	<li>如果剩余字符少于 <code>k</code> 个，则将剩余字符全部反转。</li>
	<li>如果剩余字符小于 <code>2k</code> 但大于或等于 <code>k</code> 个，则反转前 <code>k</code> 个字符，其余字符保持原样。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdefg", k = 2
<strong>输出：</strong>"bacdfeg"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", k = 2
<strong>输出：</strong>"bacd"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文组成</li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以遍历字符串 $\textit{s}$，每次遍历 $\textit{2k}$ 个字符，然后利用双指针技巧，对这 $\textit{2k}$ 个字符中的前 $\textit{k}$ 个字符进行反转。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{s}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        cs = list(s)
        for i in range(0, len(cs), 2 * k):
            cs[i : i + k] = reversed(cs[i : i + k])
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String reverseStr(String s, int k) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        for (int i = 0; i < n; i += k * 2) {
            for (int l = i, r = Math.min(i + k - 1, n - 1); l < r; ++l, --r) {
                char t = cs[l];
                cs[l] = cs[r];
                cs[r] = t;
            }
        }
        return new String(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};
```

#### Go

```go
func reverseStr(s string, k int) string {
	cs := []byte(s)
	n := len(cs)
	for i := 0; i < n; i += 2 * k {
		for l, r := i, min(i+k-1, n-1); l < r; l, r = l+1, r-1 {
			cs[l], cs[r] = cs[r], cs[l]
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function reverseStr(s: string, k: number): string {
    const n = s.length;
    const cs = s.split('');
    for (let i = 0; i < n; i += 2 * k) {
        for (let l = i, r = Math.min(i + k - 1, n - 1); l < r; l++, r--) {
            [cs[l], cs[r]] = [cs[r], cs[l]];
        }
    }
    return cs.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [542. 01 矩阵](https://leetcode.cn/problems/01-matrix){#542}

{{< tabs "542" >}}

{{% tab "python" %}}
```python
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        ans = [[-1] * n for _ in range(m)]
        q = deque()
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                if x == 0:
                    ans[i][j] = 0
                    q.append((i, j))
        dirs = (-1, 0, 1, 0, -1)
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                    ans[x][y] = ans[i][j] + 1
                    q.append((x, y))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] ans = new int[m][n];
        for (int[] row : ans) {
            Arrays.fill(row, -1);
        }
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.offer(new int[] {i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[i][j] + 1;
                    q.offer(new int[] {x, y});
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dirs[i];
                int y = p.second + dirs[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
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
func updateMatrix(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
		for j := range ans[i] {
			ans[i][j] = -1
		}
	}
	type pair struct{ x, y int }
	var q []pair
	for i, row := range mat {
		for j, v := range row {
			if v == 0 {
				ans[i][j] = 0
				q = append(q, pair{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		for i := 0; i < 4; i++ {
			x, y := p.x+dirs[i], p.y+dirs[i+1]
			if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
				ans[x][y] = ans[p.x][p.y] + 1
				q = append(q, pair{x, y})
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function updateMatrix(mat: number[][]): number[][] {
    const [m, n] = [mat.length, mat[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => -1));
    const q: [number, number][] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (mat[i][j] === 0) {
                q.push([i, j]);
                ans[i][j] = 0;
            }
        }
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (const [i, j] of q) {
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] === -1) {
                ans[x][y] = ans[i][j] + 1;
                q.push([x, y]);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let mut ans = vec![vec![-1; n]; m];
        let mut q = VecDeque::new();

        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 0 {
                    q.push_back((i, j));
                    ans[i][j] = 0;
                }
            }
        }

        let dirs = [-1, 0, 1, 0, -1];
        while let Some((i, j)) = q.pop_front() {
            for k in 0..4 {
                let x = i as isize + dirs[k];
                let y = j as isize + dirs[k + 1];
                if x >= 0 && x < m as isize && y >= 0 && y < n as isize {
                    let x = x as usize;
                    let y = y as usize;
                    if ans[x][y] == -1 {
                        ans[x][y] = ans[i][j] + 1;
                        q.push_back((x, y));
                    }
                }
            }
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由 <code>0</code> 和 <code>1</code> 组成的矩阵 <code>mat</code> ，请输出一个大小相同的矩阵，其中每一个格子是 <code>mat</code> 中对应位置元素到最近的 <code>0</code> 的距离。</p>

<p>两个相邻元素间的距离为 <code>1</code> 。</p>

<p> </p>

<p><b>示例 1：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0542.01%20Matrix/images/1626667201-NCWmuP-image.png" style="width: 150px; " /></p>

<pre>
<strong>输入：</strong>mat =<strong> </strong>[[0,0,0],[0,1,0],[0,0,0]]
<strong>输出：</strong>[[0,0,0],[0,1,0],[0,0,0]]
</pre>

<p><b>示例 2：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0542.01%20Matrix/images/1626667205-xFxIeK-image.png" style="width: 150px; " /></p>

<pre>
<b>输入：</b>mat =<b> </b>[[0,0,0],[0,1,0],[1,1,1]]
<strong>输出：</strong>[[0,0,0],[0,1,0],[1,2,1]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 <= m, n <= 10<sup>4</sup></code></li>
	<li><code>1 <= m * n <= 10<sup>4</sup></code></li>
	<li><code>mat[i][j] is either 0 or 1.</code></li>
	<li><code>mat</code> 中至少有一个 <code>0 </code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们创建一个大小和 $\textit{mat}$ 一样的矩阵 $\textit{ans}$，并将所有的元素初始化为 $-1$。

然后我们遍历 $\textit{mat}$，将所有的 $0$ 元素的坐标 $(i, j)$ 加入队列 $\textit{q}$，并将 $\textit{ans}[i][j]$ 设为 $0$。

接下来，我们使用广度优先搜索，从队列中取出一个元素 $(i, j)$，并遍历其四个方向，如果该方向的元素 $(x, y)$ 满足 $0 \leq x < m$, $0 \leq y < n$ 且 $\textit{ans}[x][y] = -1$，则将 $\textit{ans}[x][y]$ 设为 $\textit{ans}[i][j] + 1$，并将 $(x, y)$ 加入队列 $\textit{q}$。

最后返回 $\textit{ans}$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵 $\textit{mat}$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        ans = [[-1] * n for _ in range(m)]
        q = deque()
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                if x == 0:
                    ans[i][j] = 0
                    q.append((i, j))
        dirs = (-1, 0, 1, 0, -1)
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                    ans[x][y] = ans[i][j] + 1
                    q.append((x, y))
        return ans
```

#### Java

```java
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] ans = new int[m][n];
        for (int[] row : ans) {
            Arrays.fill(row, -1);
        }
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.offer(new int[] {i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[i][j] + 1;
                    q.offer(new int[] {x, y});
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dirs[i];
                int y = p.second + dirs[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func updateMatrix(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
		for j := range ans[i] {
			ans[i][j] = -1
		}
	}
	type pair struct{ x, y int }
	var q []pair
	for i, row := range mat {
		for j, v := range row {
			if v == 0 {
				ans[i][j] = 0
				q = append(q, pair{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		for i := 0; i < 4; i++ {
			x, y := p.x+dirs[i], p.y+dirs[i+1]
			if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
				ans[x][y] = ans[p.x][p.y] + 1
				q = append(q, pair{x, y})
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function updateMatrix(mat: number[][]): number[][] {
    const [m, n] = [mat.length, mat[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => -1));
    const q: [number, number][] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (mat[i][j] === 0) {
                q.push([i, j]);
                ans[i][j] = 0;
            }
        }
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (const [i, j] of q) {
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] === -1) {
                ans[x][y] = ans[i][j] + 1;
                q.push([x, y]);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let mut ans = vec![vec![-1; n]; m];
        let mut q = VecDeque::new();

        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 0 {
                    q.push_back((i, j));
                    ans[i][j] = 0;
                }
            }
        }

        let dirs = [-1, 0, 1, 0, -1];
        while let Some((i, j)) = q.pop_front() {
            for k in 0..4 {
                let x = i as isize + dirs[k];
                let y = j as isize + dirs[k + 1];
                if x >= 0 && x < m as isize && y >= 0 && y < n as isize {
                    let x = x as usize;
                    let y = y as usize;
                    if ans[x][y] == -1 {
                        ans[x][y] = ans[i][j] + 1;
                        q.push_back((x, y));
                    }
                }
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree){#543}

{{< tabs "543" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def dfs(root):
            if root is None:
                return 0
            nonlocal ans
            left, right = dfs(root.left), dfs(root.right)
            ans = max(ans, left + right)
            return 1 + max(left, right)

        ans = 0
        dfs(root)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;

    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            ans = max(ans, l + r);
            return 1 + max(l, r);
        };
        dfs(root);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) (ans int) {
	var dfs func(root *TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ans = max(ans, l+r)
		return 1 + max(l, r)
	}
	dfs(root)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function diameterOfBinaryTree(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const [l, r] = [dfs(root.left), dfs(root.right)];
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> i32 {
            match root {
                Some(node) => {
                    let node = node.borrow();
                    let l = dfs(node.left.clone(), ans);
                    let r = dfs(node.right.clone(), ans);

                    *ans = (*ans).max(l + r);

                    1 + l.max(r)
                }
                None => 0,
            }
        }
        dfs(root, &mut ans);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
    let ans = 0;
    const dfs = root => {
        if (!root) {
            return 0;
        }
        const [l, r] = [dfs(root.left), dfs(root.right)];
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    };
    dfs(root);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int ans;

    public int DiameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        ans = Math.Max(ans, l + r);
        return 1 + Math.Max(l, r);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int* ans) {
    if (root == NULL) {
        return 0;
    }
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    if (l + r > *ans) {
        *ans = l + r;
    }
    return 1 + (l > r ? l : r);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点，返回该树的 <strong>直径</strong> 。</p>

<p>二叉树的 <strong>直径</strong> 是指树中任意两个节点之间最长路径的 <strong>长度</strong> 。这条路径可能经过也可能不经过根节点 <code>root</code> 。</p>

<p>两节点之间路径的 <strong>长度</strong> 由它们之间边数表示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0543.Diameter%20of%20Binary%20Tree/images/diamtree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,5]
<strong>输出：</strong>3
<strong>解释：</strong>3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + DFS

我们可以枚举二叉树的每个节点，以该节点为根节点，计算其左右子树的最大深度 $\textit{l}$ 和 $\textit{r}$，则该节点的直径为 $\textit{l} + \textit{r}$。取所有节点的直径的最大值即为二叉树的直径。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def dfs(root):
            if root is None:
                return 0
            nonlocal ans
            left, right = dfs(root.left), dfs(root.right)
            ans = max(ans, left + right)
            return 1 + max(left, right)

        ans = 0
        dfs(root)
        return ans
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;

    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> int {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            ans = max(ans, l + r);
            return 1 + max(l, r);
        };
        dfs(root);
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) (ans int) {
	var dfs func(root *TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ans = max(ans, l+r)
		return 1 + max(l, r)
	}
	dfs(root)
	return
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function diameterOfBinaryTree(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const [l, r] = [dfs(root.left), dfs(root.right)];
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    };
    dfs(root);
    return ans;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> i32 {
            match root {
                Some(node) => {
                    let node = node.borrow();
                    let l = dfs(node.left.clone(), ans);
                    let r = dfs(node.right.clone(), ans);

                    *ans = (*ans).max(l + r);

                    1 + l.max(r)
                }
                None => 0,
            }
        }
        dfs(root, &mut ans);
        ans
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
    let ans = 0;
    const dfs = root => {
        if (!root) {
            return 0;
        }
        const [l, r] = [dfs(root.left), dfs(root.right)];
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    };
    dfs(root);
    return ans;
};
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int ans;

    public int DiameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        ans = Math.Max(ans, l + r);
        return 1 + Math.Max(l, r);
    }
}
```

#### C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int* ans) {
    if (root == NULL) {
        return 0;
    }
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    if (l + r > *ans) {
        *ans = l + r;
    }
    return 1 + (l > r ? l : r);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [544. 输出比赛匹配对 🔒](https://leetcode.cn/problems/output-contest-matches){#544}

{{< tabs "544" >}}

{{% tab "python" %}}
```python
class Solution:
    def findContestMatch(self, n: int) -> str:
        s = [str(i + 1) for i in range(n)]
        while n > 1:
            for i in range(n >> 1):
                s[i] = f"({s[i]},{s[n - i - 1]})"
            n >>= 1
        return s[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findContestMatch(int n) {
        String[] s = new String[n];
        for (int i = 0; i < n; ++i) {
            s[i] = String.valueOf(i + 1);
        }
        for (; n > 1; n >>= 1) {
            for (int i = 0; i < n >> 1; ++i) {
                s[i] = String.format("(%s,%s)", s[i], s[n - i - 1]);
            }
        }
        return s[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            s[i] = to_string(i + 1);
        }
        for (; n > 1; n >>= 1) {
            for (int i = 0; i < n >> 1; ++i) {
                s[i] = "(" + s[i] + "," + s[n - i - 1] + ")";
            }
        }
        return s[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findContestMatch(n int) string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = strconv.Itoa(i + 1)
	}
	for ; n > 1; n >>= 1 {
		for i := 0; i < n>>1; i++ {
			s[i] = fmt.Sprintf("(%s,%s)", s[i], s[n-i-1])
		}
	}
	return s[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findContestMatch(n: number): string {
    const s: string[] = Array.from({ length: n }, (_, i) => (i + 1).toString());
    for (; n > 1; n >>= 1) {
        for (let i = 0; i < n >> 1; ++i) {
            s[i] = `(${s[i]},${s[n - i - 1]})`;
        }
    }
    return s[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>&nbsp;</p>

<p>在 NBA 季后赛期间，我们总是安排相对强大的球队与相对弱小的球队比赛，就像让排名第 <code>1</code> 的球队与排名第 <code>n</code> 的球队比赛一样，这是一种使比赛更加有趣的好策略。</p>

<p>现给定 <code>n</code> 支球队，请以字符串的形式返回它们的最终的比赛匹配方案。</p>

<p>这 <code>n</code> 支球队从 <code>1</code> 到 <code>n</code> 进行标记，代表它们的初始排名（即，排名 <code>1</code> 的是最强的球队，排名 <code>n</code> 的是最弱的球队）。</p>

<p>我们将使用括号 <code>'('</code> 和 <code>')'</code> 以及逗号 <code>','</code> 来表示比赛的匹配情况。我们使用括号来表示匹配，逗号来表示分组。在每一轮的匹配过程中，你总是需要遵循使相对强大的球队与相对弱小的球队配对的策略。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> n = 4
<strong>输出:</strong> "((1,4),(2,3))"
<strong>解释:</strong> 
在第一轮，我们将队伍 1 和 4 配对，2 和 3 配对，以满足将强队和弱队搭配的效果。得到(1,4),(2,3).
在第二轮，(1,4) 和 (2,3) 的赢家需要进行比赛以确定最终赢家，因此需要再在外面加一层括号。
于是最终答案是((1,4),(2,3))。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> n = 8
<strong>输出:</strong> "(((1,8),(4,5)),((2,7),(3,6)))"
<strong>解释:</strong> 
第一轮: (1,8),(2,7),(3,6),(4,5)
第二轮: ((1,8),(4,5)),((2,7),(3,6))
第三轮 (((1,8),(4,5)),((2,7),(3,6)))
由于第三轮会决出最终胜者，故输出答案为(((1,8),(4,5)),((2,7),(3,6)))。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == 2<sup>x</sup></code>，并且 <code>x</code> 在范围 <code>[1, 12]</code> 内。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以用一个长度为 $n$ 的数组 $s$ 来存储每个队伍的编号，然后模拟比赛的过程。

每一轮比赛，我们将数组 $s$ 中的前 $n$ 个元素两两配对，然后将胜者的编号存入数组 $s$ 的前 $n/2$ 个位置。然后，我们将 $n$ 减半，继续进行下一轮比赛，直到 $n$ 减半为 $1$，此时数组 $s$ 中的第一个元素即为最终的比赛匹配方案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n \times \log n)$。其中 $n$ 为队伍的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findContestMatch(self, n: int) -> str:
        s = [str(i + 1) for i in range(n)]
        while n > 1:
            for i in range(n >> 1):
                s[i] = f"({s[i]},{s[n - i - 1]})"
            n >>= 1
        return s[0]
```

#### Java

```java
class Solution {
    public String findContestMatch(int n) {
        String[] s = new String[n];
        for (int i = 0; i < n; ++i) {
            s[i] = String.valueOf(i + 1);
        }
        for (; n > 1; n >>= 1) {
            for (int i = 0; i < n >> 1; ++i) {
                s[i] = String.format("(%s,%s)", s[i], s[n - i - 1]);
            }
        }
        return s[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            s[i] = to_string(i + 1);
        }
        for (; n > 1; n >>= 1) {
            for (int i = 0; i < n >> 1; ++i) {
                s[i] = "(" + s[i] + "," + s[n - i - 1] + ")";
            }
        }
        return s[0];
    }
};
```

#### Go

```go
func findContestMatch(n int) string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = strconv.Itoa(i + 1)
	}
	for ; n > 1; n >>= 1 {
		for i := 0; i < n>>1; i++ {
			s[i] = fmt.Sprintf("(%s,%s)", s[i], s[n-i-1])
		}
	}
	return s[0]
}
```

#### TypeScript

```ts
function findContestMatch(n: number): string {
    const s: string[] = Array.from({ length: n }, (_, i) => (i + 1).toString());
    for (; n > 1; n >>= 1) {
        for (let i = 0; i < n >> 1; ++i) {
            s[i] = `(${s[i]},${s[n - i - 1]})`;
        }
    }
    return s[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [545. 二叉树的边界 🔒](https://leetcode.cn/problems/boundary-of-binary-tree){#545}

{{< tabs "545" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(nums: List[int], root: Optional[TreeNode], i: int):
            if root is None:
                return
            if i == 0:
                if root.left != root.right:
                    nums.append(root.val)
                    if root.left:
                        dfs(nums, root.left, i)
                    else:
                        dfs(nums, root.right, i)
            elif i == 1:
                if root.left == root.right:
                    nums.append(root.val)
                else:
                    dfs(nums, root.left, i)
                    dfs(nums, root.right, i)
            else:
                if root.left != root.right:
                    nums.append(root.val)
                    if root.right:
                        dfs(nums, root.right, i)
                    else:
                        dfs(nums, root.left, i)

        ans = [root.val]
        if root.left == root.right:
            return ans
        left, leaves, right = [], [], []
        dfs(left, root.left, 0)
        dfs(leaves, root, 1)
        dfs(right, root.right, 2)
        ans += left + leaves + right[::-1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        ans.add(root.val);
        if (root.left == root.right) {
            return ans;
        }
        List<Integer> left = new ArrayList<>();
        List<Integer> leaves = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        dfs(left, root.left, 0);
        dfs(leaves, root, 1);
        dfs(right, root.right, 2);

        ans.addAll(left);
        ans.addAll(leaves);
        Collections.reverse(right);
        ans.addAll(right);
        return ans;
    }

    private void dfs(List<Integer> nums, TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i == 0) {
            if (root.left != root.right) {
                nums.add(root.val);
                if (root.left != null) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i == 1) {
            if (root.left == root.right) {
                nums.add(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left != root.right) {
                nums.add(root.val);
                if (root.right != null) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, vector<int>& nums, TreeNode* root, int i) -> void {
            if (!root) {
                return;
            }
            if (i == 0) {
                if (root->left != root->right) {
                    nums.push_back(root->val);
                    if (root->left) {
                        dfs(nums, root->left, i);
                    } else {
                        dfs(nums, root->right, i);
                    }
                }
            } else if (i == 1) {
                if (root->left == root->right) {
                    nums.push_back(root->val);
                } else {
                    dfs(nums, root->left, i);
                    dfs(nums, root->right, i);
                }
            } else {
                if (root->left != root->right) {
                    nums.push_back(root->val);
                    if (root->right) {
                        dfs(nums, root->right, i);
                    } else {
                        dfs(nums, root->left, i);
                    }
                }
            }
        };
        vector<int> ans = {root->val};
        if (root->left == root->right) {
            return ans;
        }
        vector<int> left, right, leaves;
        dfs(left, root->left, 0);
        dfs(leaves, root, 1);
        dfs(right, root->right, 2);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leaves.begin(), leaves.end());
        ans.insert(ans.end(), right.rbegin(), right.rend());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func boundaryOfBinaryTree(root *TreeNode) []int {
	ans := []int{root.Val}
	if root.Left == root.Right {
		return ans
	}

	left, leaves, right := []int{}, []int{}, []int{}

	var dfs func(nums *[]int, root *TreeNode, i int)
	dfs = func(nums *[]int, root *TreeNode, i int) {
		if root == nil {
			return
		}
		if i == 0 {
			if root.Left != root.Right {
				*nums = append(*nums, root.Val)
				if root.Left != nil {
					dfs(nums, root.Left, i)
				} else {
					dfs(nums, root.Right, i)
				}
			}
		} else if i == 1 {
			if root.Left == root.Right {
				*nums = append(*nums, root.Val)
			} else {
				dfs(nums, root.Left, i)
				dfs(nums, root.Right, i)
			}
		} else {
			if root.Left != root.Right {
				*nums = append(*nums, root.Val)
				if root.Right != nil {
					dfs(nums, root.Right, i)
				} else {
					dfs(nums, root.Left, i)
				}
			}
		}
	}

	dfs(&left, root.Left, 0)
	dfs(&leaves, root, 1)
	dfs(&right, root.Right, 2)

	ans = append(ans, left...)
	ans = append(ans, leaves...)
	for i := len(right) - 1; i >= 0; i-- {
		ans = append(ans, right[i])
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function boundaryOfBinaryTree(root: TreeNode | null): number[] {
    const ans: number[] = [root.val];
    if (root.left === root.right) {
        return ans;
    }

    const left: number[] = [];
    const leaves: number[] = [];
    const right: number[] = [];

    const dfs = function (nums: number[], root: TreeNode | null, i: number) {
        if (!root) {
            return;
        }
        if (i === 0) {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.left) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i === 1) {
            if (root.left === root.right) {
                nums.push(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.right) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    };

    dfs(left, root.left, 0);
    dfs(leaves, root, 1);
    dfs(right, root.right, 2);

    return ans.concat(left).concat(leaves).concat(right.reverse());
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var boundaryOfBinaryTree = function (root) {
    const ans = [root.val];
    if (root.left === root.right) {
        return ans;
    }

    const left = [];
    const leaves = [];
    const right = [];

    const dfs = function (nums, root, i) {
        if (!root) {
            return;
        }
        if (i === 0) {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.left) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i === 1) {
            if (root.left === root.right) {
                nums.push(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.right) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    };

    dfs(left, root.left, 0);
    dfs(leaves, root, 1);
    dfs(right, root.right, 2);
    return ans.concat(left).concat(leaves).concat(right.reverse());
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>二叉树的 <strong>边界</strong> 是由 <strong>根节点 </strong>、<strong>左边界</strong> 、按从左到右顺序的<strong> 叶节点</strong> 和 <strong>逆序的右边界</strong> ，按顺序依次连接组成。</p>

<p><strong>左边界 </strong>是满足下述定义的节点集合：</p>

<ul>
	<li>根节点的左子节点在左边界中。如果根节点不含左子节点，那么左边界就为 <strong>空</strong> 。</li>
	<li>如果一个节点在左边界中，并且该节点有左子节点，那么它的左子节点也在左边界中。</li>
	<li>如果一个节点在左边界中，并且该节点 <strong>不含</strong> 左子节点，那么它的右子节点就在左边界中。</li>
	<li>最左侧的叶节点 <strong>不在</strong> 左边界中。</li>
</ul>

<p><strong>右边界</strong> 定义方式与 <strong>左边界</strong> 相同，只是将左替换成右。即，右边界是根节点右子树的右侧部分；叶节点 <strong>不是</strong> 右边界的组成部分；如果根节点不含右子节点，那么右边界为 <strong>空</strong> 。</p>

<p><strong>叶节点</strong> 是没有任何子节点的节点。对于此问题，根节点 <strong>不是</strong> 叶节点。</p>

<p>给你一棵二叉树的根节点 <code>root</code> ，按顺序返回组成二叉树 <strong>边界</strong> 的这些值。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0545.Boundary%20of%20Binary%20Tree/images/boundary1.jpg" style="width: 299px; height: 290px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3,4]
<strong>输出：</strong>[1,3,4,2]
<b>解释：</b>
- 左边界为空，因为二叉树不含左子节点。
- 右边界是 [2] 。从根节点的右子节点开始的路径为 2 -> 4 ，但 4 是叶节点，所以右边界只有 2 。
- 叶节点从左到右是 [3,4] 。
按题目要求依序连接得到结果 [1] + [] + [3,4] + [2] = [1,3,4,2] 。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0545.Boundary%20of%20Binary%20Tree/images/boundary2.jpg" style="width: 599px; height: 411px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
<strong>输出：</strong>[1,2,4,7,8,9,10,6,3]
<b>解释：</b>
- 左边界为 [2] 。从根节点的左子节点开始的路径为 2 -> 4 ，但 4 是叶节点，所以左边界只有 2 。
- 右边界是 [3,6] ，逆序为 [6,3] 。从根节点的右子节点开始的路径为 3 -> 6 -> 10 ，但 10 是叶节点。
- 叶节点从左到右是 [4,7,8,9,10]
按题目要求依序连接得到结果 [1] + [2] + [4,7,8,9,10] + [6,3] = [1,2,4,7,8,9,10,6,3] 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>-1000 <= Node.val <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

首先，如果树只有一个节点，那么直接返回这个节点的值的列表。

否则，我们可以通过深度优先搜索，找到二叉树的左边界、叶节点和右边界。

具体地，我们可以通过一个递归函数 $\textit{dfs}$ 来找到这三个部分。在 $\textit{dfs}$ 函数中，我们需要传入一个列表 $\textit{nums}$，一个节点 $\textit{root}$ 和一个整数 $\textit{i}$，其中 $\textit{nums}$ 用来存储当前部分的节点值，而 $\textit{root}$ 和 $\textit{i}$ 分别表示当前节点和当前部分的类型（左边界, 叶节点或右边界）。

函数的具体实现如下：

-   如果 $\textit{root}$ 为空，那么直接返回。
-   如果 $\textit{i} = 0$，那么我们需要找到左边界。如果 $\textit{root}$ 不是叶节点，那么我们将 $\textit{root}$ 的值加入到 $\textit{nums}$ 中。如果 $\textit{root}$ 有左子节点，那么我们递归地调用 $\textit{dfs}$ 函数，传入 $\textit{nums}$, $\textit{root}$ 的左子节点和 $\textit{i}$。否则，我们递归地调用 $\textit{dfs}$ 函数，传入 $\textit{nums}$, $\textit{root}$ 的右子节点和 $\textit{i}$。
-   如果 $\textit{i} = 1$，那么我们需要找到叶节点。如果 $\textit{root}$ 是叶节点，那么我们将 $\textit{root}$ 的值加入到 $\textit{nums}$ 中。否则，我们递归地调用 $\textit{dfs}$ 函数，传入 $\textit{nums}$, $\textit{root}$ 的左子节点和 $\textit{i}$，以及 $\textit{nums}$, $\textit{root}$ 的右子节点和 $\textit{i}$。
-   如果 $\textit{i} = 2$，那么我们需要找到右边界。如果 $\textit{root}$ 不是叶节点，那么我们将 $\textit{root}$ 的值加入到 $\textit{nums}$ 中，如果 $\textit{root}$ 有右子节点，那么我们递归地调用 $\textit{dfs}$ 函数，传入 $\textit{nums}$, $\textit{root}$ 的右子节点和 $\textit{i}$。否则，我们递归地调用 $\textit{dfs}$ 函数，传入 $\textit{nums}$, $\textit{root}$ 的左子节点和 $\textit{i}$。

我们分别调用 $\textit{dfs}$ 函数，找到左边界、叶节点和右边界，然后将这三个部分连接起来，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(nums: List[int], root: Optional[TreeNode], i: int):
            if root is None:
                return
            if i == 0:
                if root.left != root.right:
                    nums.append(root.val)
                    if root.left:
                        dfs(nums, root.left, i)
                    else:
                        dfs(nums, root.right, i)
            elif i == 1:
                if root.left == root.right:
                    nums.append(root.val)
                else:
                    dfs(nums, root.left, i)
                    dfs(nums, root.right, i)
            else:
                if root.left != root.right:
                    nums.append(root.val)
                    if root.right:
                        dfs(nums, root.right, i)
                    else:
                        dfs(nums, root.left, i)

        ans = [root.val]
        if root.left == root.right:
            return ans
        left, leaves, right = [], [], []
        dfs(left, root.left, 0)
        dfs(leaves, root, 1)
        dfs(right, root.right, 2)
        ans += left + leaves + right[::-1]
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        ans.add(root.val);
        if (root.left == root.right) {
            return ans;
        }
        List<Integer> left = new ArrayList<>();
        List<Integer> leaves = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        dfs(left, root.left, 0);
        dfs(leaves, root, 1);
        dfs(right, root.right, 2);

        ans.addAll(left);
        ans.addAll(leaves);
        Collections.reverse(right);
        ans.addAll(right);
        return ans;
    }

    private void dfs(List<Integer> nums, TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i == 0) {
            if (root.left != root.right) {
                nums.add(root.val);
                if (root.left != null) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i == 1) {
            if (root.left == root.right) {
                nums.add(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left != root.right) {
                nums.add(root.val);
                if (root.right != null) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, vector<int>& nums, TreeNode* root, int i) -> void {
            if (!root) {
                return;
            }
            if (i == 0) {
                if (root->left != root->right) {
                    nums.push_back(root->val);
                    if (root->left) {
                        dfs(nums, root->left, i);
                    } else {
                        dfs(nums, root->right, i);
                    }
                }
            } else if (i == 1) {
                if (root->left == root->right) {
                    nums.push_back(root->val);
                } else {
                    dfs(nums, root->left, i);
                    dfs(nums, root->right, i);
                }
            } else {
                if (root->left != root->right) {
                    nums.push_back(root->val);
                    if (root->right) {
                        dfs(nums, root->right, i);
                    } else {
                        dfs(nums, root->left, i);
                    }
                }
            }
        };
        vector<int> ans = {root->val};
        if (root->left == root->right) {
            return ans;
        }
        vector<int> left, right, leaves;
        dfs(left, root->left, 0);
        dfs(leaves, root, 1);
        dfs(right, root->right, 2);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leaves.begin(), leaves.end());
        ans.insert(ans.end(), right.rbegin(), right.rend());
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func boundaryOfBinaryTree(root *TreeNode) []int {
	ans := []int{root.Val}
	if root.Left == root.Right {
		return ans
	}

	left, leaves, right := []int{}, []int{}, []int{}

	var dfs func(nums *[]int, root *TreeNode, i int)
	dfs = func(nums *[]int, root *TreeNode, i int) {
		if root == nil {
			return
		}
		if i == 0 {
			if root.Left != root.Right {
				*nums = append(*nums, root.Val)
				if root.Left != nil {
					dfs(nums, root.Left, i)
				} else {
					dfs(nums, root.Right, i)
				}
			}
		} else if i == 1 {
			if root.Left == root.Right {
				*nums = append(*nums, root.Val)
			} else {
				dfs(nums, root.Left, i)
				dfs(nums, root.Right, i)
			}
		} else {
			if root.Left != root.Right {
				*nums = append(*nums, root.Val)
				if root.Right != nil {
					dfs(nums, root.Right, i)
				} else {
					dfs(nums, root.Left, i)
				}
			}
		}
	}

	dfs(&left, root.Left, 0)
	dfs(&leaves, root, 1)
	dfs(&right, root.Right, 2)

	ans = append(ans, left...)
	ans = append(ans, leaves...)
	for i := len(right) - 1; i >= 0; i-- {
		ans = append(ans, right[i])
	}

	return ans
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function boundaryOfBinaryTree(root: TreeNode | null): number[] {
    const ans: number[] = [root.val];
    if (root.left === root.right) {
        return ans;
    }

    const left: number[] = [];
    const leaves: number[] = [];
    const right: number[] = [];

    const dfs = function (nums: number[], root: TreeNode | null, i: number) {
        if (!root) {
            return;
        }
        if (i === 0) {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.left) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i === 1) {
            if (root.left === root.right) {
                nums.push(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.right) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    };

    dfs(left, root.left, 0);
    dfs(leaves, root, 1);
    dfs(right, root.right, 2);

    return ans.concat(left).concat(leaves).concat(right.reverse());
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var boundaryOfBinaryTree = function (root) {
    const ans = [root.val];
    if (root.left === root.right) {
        return ans;
    }

    const left = [];
    const leaves = [];
    const right = [];

    const dfs = function (nums, root, i) {
        if (!root) {
            return;
        }
        if (i === 0) {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.left) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i === 1) {
            if (root.left === root.right) {
                nums.push(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left !== root.right) {
                nums.push(root.val);
                if (root.right) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    };

    dfs(left, root.left, 0);
    dfs(leaves, root, 1);
    dfs(right, root.right, 2);
    return ans.concat(left).concat(leaves).concat(right.reverse());
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [546. 移除盒子](https://leetcode.cn/problems/remove-boxes){#546}

{{< tabs "546" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        @cache
        def dfs(i, j, k):
            if i > j:
                return 0
            while i < j and boxes[j] == boxes[j - 1]:
                j, k = j - 1, k + 1
            ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1)
            for h in range(i, j):
                if boxes[h] == boxes[j]:
                    ans = max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1))
            return ans

        n = len(boxes)
        ans = dfs(0, n - 1, 0)
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][][] f;
    private int[] b;

    public int removeBoxes(int[] boxes) {
        b = boxes;
        int n = b.length;
        f = new int[n][n][n];
        return dfs(0, n - 1, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i > j) {
            return 0;
        }
        while (i < j && b[j] == b[j - 1]) {
            --j;
            ++k;
        }
        if (f[i][j][k] > 0) {
            return f[i][j][k];
        }
        int ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1);
        for (int h = i; h < j; ++h) {
            if (b[h] == b[j]) {
                ans = Math.max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1));
            }
        }
        f[i][j][k] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n)));
        function<int(int, int, int)> dfs;
        dfs = [&](int i, int j, int k) {
            if (i > j) return 0;
            while (i < j && boxes[j] == boxes[j - 1]) {
                --j;
                ++k;
            }
            if (f[i][j][k]) return f[i][j][k];
            int ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1);
            for (int h = i; h < j; ++h) {
                if (boxes[h] == boxes[j]) {
                    ans = max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1));
                }
            }
            f[i][j][k] = ans;
            return ans;
        };
        return dfs(0, n - 1, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeBoxes(boxes []int) int {
	n := len(boxes)
	f := make([][][]int, n)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i > j {
			return 0
		}
		for i < j && boxes[j] == boxes[j-1] {
			j, k = j-1, k+1
		}
		if f[i][j][k] > 0 {
			return f[i][j][k]
		}
		ans := dfs(i, j-1, 0) + (k+1)*(k+1)
		for h := i; h < j; h++ {
			if boxes[h] == boxes[j] {
				ans = max(ans, dfs(h+1, j-1, 0)+dfs(i, h, k+1))
			}
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, n-1, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一些不同颜色的盒子<meta charset="UTF-8" />&nbsp;<code>boxes</code>&nbsp;，盒子的颜色由不同的正数表示。</p>

<p>你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 <code>k</code> 个盒子（<code>k&nbsp;&gt;= 1</code>），这样一轮之后你将得到 <code>k * k</code> 个积分。</p>

<p>返回 <em>你能获得的最大积分和</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>boxes = [1,3,2,2,2,3,4,3,1]
<strong>输出：</strong>23
<strong>解释：</strong>
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----&gt; [1, 3, 3, 4, 3, 1] (3*3=9 分) 
----&gt; [1, 3, 3, 3, 1] (1*1=1 分) 
----&gt; [1, 1] (3*3=9 分) 
----&gt; [] (2*2=4 分)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>boxes = [1,1,1]
<strong>输出：</strong>9
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>boxes = [1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= boxes.length &lt;= 100</code></li>
	<li><code>1 &lt;= boxes[i]&nbsp;&lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

设计递归函数 `dfs(i, j, k)` 表示当前处理的区间为 `[i, j]`，且该区间的右边有 `k` 个与 `boxes[j]` 相同的元素，返回该区间的最大积分。答案即为 `dfs(0, n - 1, 0)`。

对于 `dfs(i, j, k)`，我们可以直接删除 `boxes[j]` 和其右边的 `k` 个元素，所得积分为 `dfs(i, j - 1, 0) + (k + 1) * (k + 1)`。

我们还可以在区间 `[i, j-1]` 内枚举下标 `h`，找到满足 `boxes[h] == boxes[j]` 的下标，那么我们就将区间 `[i, j - 1]` 分成两部分，即 `[i, h]` 和 `[h + 1, j - 1]`。其中 `[i, h]` 的部分可以与 `boxes[j]` 合并，所以积分为 `dfs(i, h, k + 1) + dfs(h + 1, j - 1, 0)`。求不同 `h` 下的最大值即可。

我们使用记忆化搜索来优化递归函数的时间复杂度。

时间复杂度 $O(n^4)$，空间复杂度 $O(n^3)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        @cache
        def dfs(i, j, k):
            if i > j:
                return 0
            while i < j and boxes[j] == boxes[j - 1]:
                j, k = j - 1, k + 1
            ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1)
            for h in range(i, j):
                if boxes[h] == boxes[j]:
                    ans = max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1))
            return ans

        n = len(boxes)
        ans = dfs(0, n - 1, 0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int[][][] f;
    private int[] b;

    public int removeBoxes(int[] boxes) {
        b = boxes;
        int n = b.length;
        f = new int[n][n][n];
        return dfs(0, n - 1, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i > j) {
            return 0;
        }
        while (i < j && b[j] == b[j - 1]) {
            --j;
            ++k;
        }
        if (f[i][j][k] > 0) {
            return f[i][j][k];
        }
        int ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1);
        for (int h = i; h < j; ++h) {
            if (b[h] == b[j]) {
                ans = Math.max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1));
            }
        }
        f[i][j][k] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n)));
        function<int(int, int, int)> dfs;
        dfs = [&](int i, int j, int k) {
            if (i > j) return 0;
            while (i < j && boxes[j] == boxes[j - 1]) {
                --j;
                ++k;
            }
            if (f[i][j][k]) return f[i][j][k];
            int ans = dfs(i, j - 1, 0) + (k + 1) * (k + 1);
            for (int h = i; h < j; ++h) {
                if (boxes[h] == boxes[j]) {
                    ans = max(ans, dfs(h + 1, j - 1, 0) + dfs(i, h, k + 1));
                }
            }
            f[i][j][k] = ans;
            return ans;
        };
        return dfs(0, n - 1, 0);
    }
};
```

#### Go

```go
func removeBoxes(boxes []int) int {
	n := len(boxes)
	f := make([][][]int, n)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i > j {
			return 0
		}
		for i < j && boxes[j] == boxes[j-1] {
			j, k = j-1, k+1
		}
		if f[i][j][k] > 0 {
			return f[i][j][k]
		}
		ans := dfs(i, j-1, 0) + (k+1)*(k+1)
		for h := i; h < j; h++ {
			if boxes[h] == boxes[j] {
				ans = max(ans, dfs(h+1, j-1, 0)+dfs(i, h, k+1))
			}
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, n-1, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [547. 省份数量](https://leetcode.cn/problems/number-of-provinces){#547}

{{< tabs "547" >}}

{{% tab "python" %}}
```python
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(isConnected)
        p = list(range(n))
        ans = n
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j]:
                    pa, pb = find(i), find(j)
                    if pa != pb:
                        p[pa] = pb
                        ans -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    int pa = find(i), pb = find(j);
                    if (pa != pb) {
                        p[pa] = pb;
                        --ans;
                    }
                }
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int p[n];
        iota(p, p + n, 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    int pa = find(i), pb = find(j);
                    if (pa != pb) {
                        p[pa] = pb;
                        --ans;
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
func findCircleNum(isConnected [][]int) (ans int) {
	n := len(isConnected)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	ans = n
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if isConnected[i][j] == 1 {
				pa, pb := find(i), find(j)
				if pa != pb {
					p[pa] = pb
					ans--
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    let ans = n;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (isConnected[i][j]) {
                const pa = find(i);
                const pb = find(j);
                if (pa !== pb) {
                    p[pa] = pb;
                    --ans;
                }
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(is_connected: &mut Vec<Vec<i32>>, vis: &mut Vec<bool>, i: usize) {
        vis[i] = true;
        for j in 0..is_connected.len() {
            if vis[j] || is_connected[i][j] == 0 {
                continue;
            }
            Self::dfs(is_connected, vis, j);
        }
    }

    pub fn find_circle_num(mut is_connected: Vec<Vec<i32>>) -> i32 {
        let n = is_connected.len();
        let mut vis = vec![false; n];
        let mut res = 0;
        for i in 0..n {
            if vis[i] {
                continue;
            }
            res += 1;
            Self::dfs(&mut is_connected, &mut vis, i);
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<div class="original__bRMd">
<div>
<p>有 <code>n</code> 个城市，其中一些彼此相连，另一些没有相连。如果城市 <code>a</code> 与城市 <code>b</code> 直接相连，且城市 <code>b</code> 与城市 <code>c</code> 直接相连，那么城市 <code>a</code> 与城市 <code>c</code> 间接相连。</p>

<p><strong>省份</strong> 是一组直接或间接相连的城市，组内不含其他没有相连的城市。</p>

<p>给你一个 <code>n x n</code> 的矩阵 <code>isConnected</code> ，其中 <code>isConnected[i][j] = 1</code> 表示第 <code>i</code> 个城市和第 <code>j</code> 个城市直接相连，而 <code>isConnected[i][j] = 0</code> 表示二者不直接相连。</p>

<p>返回矩阵中 <strong>省份</strong> 的数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0547.Number%20of%20Provinces/images/graph1.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>输入：</strong>isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0547.Number%20of%20Provinces/images/graph2.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>输入：</strong>isConnected = [[1,0,0],[0,1,0],[0,0,1]]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 200</code></li>
	<li><code>n == isConnected.length</code></li>
	<li><code>n == isConnected[i].length</code></li>
	<li><code>isConnected[i][j]</code> 为 <code>1</code> 或 <code>0</code></li>
	<li><code>isConnected[i][i] == 1</code></li>
	<li><code>isConnected[i][j] == isConnected[j][i]</code></li>
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

### 方法一：DFS

我们创建一个数组 $\textit{vis}$，用于记录每个城市是否被访问过。

接下来，遍历每个城市 $i$，如果该城市未被访问过，则从该城市开始深度优先搜索，通过矩阵 $\textit{isConnected}$ 得到与该城市直接相连的城市有哪些，这些城市和该城市属于同一个省，然后对这些城市继续深度优先搜索，直到同一个省的所有城市都被访问到，即可得到一个省，将答案 $\textit{ans}$ 加 $1$，然后遍历下一个未被访问过的城市，直到遍历完所有的城市。

最后返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是城市的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(i: int):
            vis[i] = True
            for j, x in enumerate(isConnected[i]):
                if not vis[j] and x:
                    dfs(j)

        n = len(isConnected)
        vis = [False] * n
        ans = 0
        for i in range(n):
            if not vis[i]:
                dfs(i)
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    private int[][] g;
    private boolean[] vis;

    public int findCircleNum(int[][] isConnected) {
        g = isConnected;
        int n = g.length;
        vis = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i);
                ++ans;
            }
        }
        return ans;
    }

    private void dfs(int i) {
        vis[i] = true;
        for (int j = 0; j < g.length; ++j) {
            if (!vis[j] && g[i][j] == 1) {
                dfs(j);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = true;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && isConnected[i][j]) {
                    dfs(j);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i);
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findCircleNum(isConnected [][]int) (ans int) {
	n := len(isConnected)
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		vis[i] = true
		for j, x := range isConnected[i] {
			if !vis[j] && x == 1 {
				dfs(j)
			}
		}
	}
	for i, v := range vis {
		if !v {
			ans++
			dfs(i)
		}
	}
	return
}
```

#### TypeScript

```ts
function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    const vis: boolean[] = new Array(n).fill(false);
    const dfs = (i: number) => {
        vis[i] = true;
        for (let j = 0; j < n; ++j) {
            if (!vis[j] && isConnected[i][j]) {
                dfs(j);
            }
        }
    };
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(is_connected: &mut Vec<Vec<i32>>, vis: &mut Vec<bool>, i: usize) {
        vis[i] = true;
        for j in 0..is_connected.len() {
            if vis[j] || is_connected[i][j] == 0 {
                continue;
            }
            Self::dfs(is_connected, vis, j);
        }
    }

    pub fn find_circle_num(mut is_connected: Vec<Vec<i32>>) -> i32 {
        let n = is_connected.len();
        let mut vis = vec![false; n];
        let mut res = 0;
        for i in 0..n {
            if vis[i] {
                continue;
            }
            res += 1;
            Self::dfs(&mut is_connected, &mut vis, i);
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

我们也可以用并查集维护每个连通分量，初始时，每个城市都属于不同的连通分量，所以省份数量为 $n$。

接下来，遍历矩阵 $\textit{isConnected}$，如果两个城市 $(i, j)$ 之间有相连关系，并且处于两个不同的连通分量，则它们将被合并成为一个连通分量，然后将省份数量减去 $1$。

最后返回省份数量即可。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是城市的数量，而 $\log n$ 是并查集的路径压缩的时间复杂度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(isConnected)
        p = list(range(n))
        ans = n
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j]:
                    pa, pb = find(i), find(j)
                    if pa != pb:
                        p[pa] = pb
                        ans -= 1
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    int pa = find(i), pb = find(j);
                    if (pa != pb) {
                        p[pa] = pb;
                        --ans;
                    }
                }
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int p[n];
        iota(p, p + n, 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    int pa = find(i), pb = find(j);
                    if (pa != pb) {
                        p[pa] = pb;
                        --ans;
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
func findCircleNum(isConnected [][]int) (ans int) {
	n := len(isConnected)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	ans = n
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if isConnected[i][j] == 1 {
				pa, pb := find(i), find(j)
				if pa != pb {
					p[pa] = pb
					ans--
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    let ans = n;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (isConnected[i][j]) {
                const pa = find(i);
                const pb = find(j);
                if (pa !== pb) {
                    p[pa] = pb;
                    --ans;
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

# [548. 将数组分割成和相等的子数组 🔒](https://leetcode.cn/problems/split-array-with-equal-sum){#548}

{{< tabs "548" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitArray(self, nums: List[int]) -> bool:
        n = len(nums)
        s = [0] * (n + 1)
        for i, v in enumerate(nums):
            s[i + 1] = s[i] + v
        for j in range(3, n - 3):
            seen = set()
            for i in range(1, j - 1):
                if s[i] == s[j] - s[i + 1]:
                    seen.add(s[i])
            for k in range(j + 2, n - 1):
                if s[n] - s[k + 1] == s[k] - s[j + 1] and s[n] - s[k + 1] in seen:
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean splitArray(int[] nums) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int j = 3; j < n - 3; ++j) {
            Set<Integer> seen = new HashSet<>();
            for (int i = 1; i < j - 1; ++i) {
                if (s[i] == s[j] - s[i + 1]) {
                    seen.add(s[i]);
                }
            }
            for (int k = j + 2; k < n - 1; ++k) {
                if (s[n] - s[k + 1] == s[k] - s[j + 1] && seen.contains(s[n] - s[k + 1])) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + nums[i];
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> seen;
            for (int i = 1; i < j - 1; ++i)
                if (s[i] == s[j] - s[i + 1])
                    seen.insert(s[i]);
            for (int k = j + 2; k < n - 1; ++k)
                if (s[n] - s[k + 1] == s[k] - s[j + 1] && seen.count(s[n] - s[k + 1]))
                    return true;
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitArray(nums []int) bool {
	n := len(nums)
	s := make([]int, n+1)
	for i, v := range nums {
		s[i+1] = s[i] + v
	}
	for j := 3; j < n-3; j++ {
		seen := map[int]bool{}
		for i := 1; i < j-1; i++ {
			if s[i] == s[j]-s[i+1] {
				seen[s[i]] = true
			}
		}
		for k := j + 2; k < n-1; k++ {
			if s[n]-s[k+1] == s[k]-s[j+1] && seen[s[n]-s[k+1]] {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个有 <code>n</code> 个整数的数组 <code>nums</code>&nbsp;，如果能找到满足以下条件的三元组&nbsp; <code>(i, j, k)</code>&nbsp; 则返回 <code>true</code> ：</p>

<ol>
	<li><code>0 &lt; i, i + 1 &lt; j, j + 1 &lt; k &lt; n - 1</code></li>
	<li>子数组 <code>(0, i - 1)</code>&nbsp;， <code>(i + 1, j - 1)</code> ， <code>(j + 1, k - 1)</code> ， <code>(k + 1, n - 1)</code> 的和应该相等。</li>
</ol>

<p>这里我们定义子数组&nbsp;<code>(l, r)</code>&nbsp;表示原数组从索引为&nbsp;<code>l</code>&nbsp;的元素开始至索引为&nbsp;<code>r</code> 的元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1:&nbsp;</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,1,2,1,2,1]
<strong>输出:</strong> True
<strong>解释:</strong>
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,1,2,1,2,1,2]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n ==&nbsp;nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

先求出前缀和数组 s。

然后遍历 j 所有可能的位置，对于每个 j，找出 i，使得前两个子数组的和相等。同时将和添加到哈希表中。

接着对于每个 j，找出 k，使得后两个子数组的和相等，然后判断哈希表中是否存在该和，如果存在，则找到满足条件的三元组 `(i, j, k)`，返回 true。

否则遍历结束返回 false。

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitArray(self, nums: List[int]) -> bool:
        n = len(nums)
        s = [0] * (n + 1)
        for i, v in enumerate(nums):
            s[i + 1] = s[i] + v
        for j in range(3, n - 3):
            seen = set()
            for i in range(1, j - 1):
                if s[i] == s[j] - s[i + 1]:
                    seen.add(s[i])
            for k in range(j + 2, n - 1):
                if s[n] - s[k + 1] == s[k] - s[j + 1] and s[n] - s[k + 1] in seen:
                    return True
        return False
```

#### Java

```java
class Solution {
    public boolean splitArray(int[] nums) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int j = 3; j < n - 3; ++j) {
            Set<Integer> seen = new HashSet<>();
            for (int i = 1; i < j - 1; ++i) {
                if (s[i] == s[j] - s[i + 1]) {
                    seen.add(s[i]);
                }
            }
            for (int k = j + 2; k < n - 1; ++k) {
                if (s[n] - s[k + 1] == s[k] - s[j + 1] && seen.contains(s[n] - s[k + 1])) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + nums[i];
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> seen;
            for (int i = 1; i < j - 1; ++i)
                if (s[i] == s[j] - s[i + 1])
                    seen.insert(s[i]);
            for (int k = j + 2; k < n - 1; ++k)
                if (s[n] - s[k + 1] == s[k] - s[j + 1] && seen.count(s[n] - s[k + 1]))
                    return true;
        }
        return false;
    }
};
```

#### Go

```go
func splitArray(nums []int) bool {
	n := len(nums)
	s := make([]int, n+1)
	for i, v := range nums {
		s[i+1] = s[i] + v
	}
	for j := 3; j < n-3; j++ {
		seen := map[int]bool{}
		for i := 1; i < j-1; i++ {
			if s[i] == s[j]-s[i+1] {
				seen[s[i]] = true
			}
		}
		for k := j + 2; k < n-1; k++ {
			if s[n]-s[k+1] == s[k]-s[j+1] && seen[s[n]-s[k+1]] {
				return true
			}
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [549. 二叉树最长连续序列 II 🔒](https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence-ii){#549}

{{< tabs "549" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        def dfs(root):
            if root is None:
                return [0, 0]
            nonlocal ans
            incr = decr = 1
            i1, d1 = dfs(root.left)
            i2, d2 = dfs(root.right)
            if root.left:
                if root.left.val + 1 == root.val:
                    incr = i1 + 1
                if root.left.val - 1 == root.val:
                    decr = d1 + 1
            if root.right:
                if root.right.val + 1 == root.val:
                    incr = max(incr, i2 + 1)
                if root.right.val - 1 == root.val:
                    decr = max(decr, d2 + 1)
            ans = max(ans, incr + decr - 1)
            return [incr, decr]

        ans = 0
        dfs(root)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;

    public int longestConsecutive(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {0, 0};
        }
        int incr = 1, decr = 1;
        int[] left = dfs(root.left);
        int[] right = dfs(root.right);
        if (root.left != null) {
            if (root.left.val + 1 == root.val) {
                incr = left[0] + 1;
            }
            if (root.left.val - 1 == root.val) {
                decr = left[1] + 1;
            }
        }
        if (root.right != null) {
            if (root.right.val + 1 == root.val) {
                incr = Math.max(incr, right[0] + 1);
            }
            if (root.right.val - 1 == root.val) {
                decr = Math.max(decr, right[1] + 1);
            }
        }
        ans = Math.max(ans, incr + decr - 1);
        return new int[] {incr, decr};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;

    int longestConsecutive(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        int incr = 1, decr = 1;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (root->left) {
            if (root->left->val + 1 == root->val) incr = left[0] + 1;
            if (root->left->val - 1 == root->val) decr = left[1] + 1;
        }
        if (root->right) {
            if (root->right->val + 1 == root->val) incr = max(incr, right[0] + 1);
            if (root->right->val - 1 == root->val) decr = max(decr, right[1] + 1);
        }
        ans = max(ans, incr + decr - 1);
        return {incr, decr};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestConsecutive(root *TreeNode) int {
	ans := 0
	var dfs func(root *TreeNode) []int
	dfs = func(root *TreeNode) []int {
		if root == nil {
			return []int{0, 0}
		}
		incr, decr := 1, 1
		left := dfs(root.Left)
		right := dfs(root.Right)
		if root.Left != nil {
			if root.Left.Val+1 == root.Val {
				incr = left[0] + 1
			}
			if root.Left.Val-1 == root.Val {
				decr = left[1] + 1
			}
		}
		if root.Right != nil {
			if root.Right.Val+1 == root.Val {
				incr = max(incr, right[0]+1)
			}
			if root.Right.Val-1 == root.Val {
				decr = max(decr, right[1]+1)
			}
		}
		ans = max(ans, incr+decr-1)
		return []int{incr, decr}
	}
	dfs(root)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定二叉树的根&nbsp;<code>root</code>&nbsp;，返回树中<strong>最长连续路径</strong>的长度。<br />
<strong>连续路径</strong>是路径中相邻节点的值相差 <code>1</code> 的路径。此路径可以是增加或减少。</p>

<ul>
	<li>例如，&nbsp;<code>[1,2,3,4]</code> 和 <code>[4,3,2,1]</code> 都被认为有效，但路径 <code>[1,2,4,3]</code> 无效。</li>
</ul>

<p>另一方面，路径可以是子-父-子顺序，不一定是父子顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0549.Binary%20Tree%20Longest%20Consecutive%20Sequence%20II/images/consec2-1-tree.jpg" /></p>

<pre>
<strong>输入: </strong>root = [1,2,3]
<strong>输出:</strong> 2
<strong>解释:</strong> 最长的连续路径是 [1, 2] 或者 [2, 1]。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0549.Binary%20Tree%20Longest%20Consecutive%20Sequence%20II/images/consec2-2-tree.jpg" /></p>

<pre>
<strong>输入: </strong>root = [2,1,3]
<strong>输出:</strong> 3
<strong>解释:</strong> 最长的连续路径是 [1, 2, 3] 或者 [3, 2, 1]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树上所有节点的值都在&nbsp;<code>[1, 3 * 10<sup>4</sup>]</code>&nbsp;范围内。</li>
	<li><code>-3 * 10<sup>4</sup>&nbsp;&lt;= Node.val &lt;= 3 * 10<sup>4</sup></code></li>
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

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        def dfs(root):
            if root is None:
                return [0, 0]
            nonlocal ans
            incr = decr = 1
            i1, d1 = dfs(root.left)
            i2, d2 = dfs(root.right)
            if root.left:
                if root.left.val + 1 == root.val:
                    incr = i1 + 1
                if root.left.val - 1 == root.val:
                    decr = d1 + 1
            if root.right:
                if root.right.val + 1 == root.val:
                    incr = max(incr, i2 + 1)
                if root.right.val - 1 == root.val:
                    decr = max(decr, d2 + 1)
            ans = max(ans, incr + decr - 1)
            return [incr, decr]

        ans = 0
        dfs(root)
        return ans
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;

    public int longestConsecutive(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {0, 0};
        }
        int incr = 1, decr = 1;
        int[] left = dfs(root.left);
        int[] right = dfs(root.right);
        if (root.left != null) {
            if (root.left.val + 1 == root.val) {
                incr = left[0] + 1;
            }
            if (root.left.val - 1 == root.val) {
                decr = left[1] + 1;
            }
        }
        if (root.right != null) {
            if (root.right.val + 1 == root.val) {
                incr = Math.max(incr, right[0] + 1);
            }
            if (root.right.val - 1 == root.val) {
                decr = Math.max(decr, right[1] + 1);
            }
        }
        ans = Math.max(ans, incr + decr - 1);
        return new int[] {incr, decr};
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;

    int longestConsecutive(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        int incr = 1, decr = 1;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (root->left) {
            if (root->left->val + 1 == root->val) incr = left[0] + 1;
            if (root->left->val - 1 == root->val) decr = left[1] + 1;
        }
        if (root->right) {
            if (root->right->val + 1 == root->val) incr = max(incr, right[0] + 1);
            if (root->right->val - 1 == root->val) decr = max(decr, right[1] + 1);
        }
        ans = max(ans, incr + decr - 1);
        return {incr, decr};
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestConsecutive(root *TreeNode) int {
	ans := 0
	var dfs func(root *TreeNode) []int
	dfs = func(root *TreeNode) []int {
		if root == nil {
			return []int{0, 0}
		}
		incr, decr := 1, 1
		left := dfs(root.Left)
		right := dfs(root.Right)
		if root.Left != nil {
			if root.Left.Val+1 == root.Val {
				incr = left[0] + 1
			}
			if root.Left.Val-1 == root.Val {
				decr = left[1] + 1
			}
		}
		if root.Right != nil {
			if root.Right.Val+1 == root.Val {
				incr = max(incr, right[0]+1)
			}
			if root.Right.Val-1 == root.Val {
				decr = max(decr, right[1]+1)
			}
		}
		ans = max(ans, incr+decr-1)
		return []int{incr, decr}
	}
	dfs(root)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
