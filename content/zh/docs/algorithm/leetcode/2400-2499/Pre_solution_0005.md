---
title: "2440_创建价值相同的连通块"
date: 2025-10-08T18:39:18+08:00
weight: 5
tags: [二分查找, 二叉树, 前缀和, 单调队列, 双指针, 哈希表, 字符串, 广度优先搜索, 排序, 数学, 数组, 数论, 枚举, 树, 深度优先搜索, 滑动窗口, 计数, 贪心, 队列]
---

{{< markmap >}}
### [2440_创建价值相同的连通块](#2440)
#### [树](#2440)
#### [深度优先搜索](#2440)
#### [数组](#2440)
#### [数学](#2440)
#### [枚举](#2440)
### [2441_与对应负数同时存在的最大正整数](#2441)
#### [数组](#2441)
#### [哈希表](#2441)
#### [双指针](#2441)
#### [排序](#2441)
### [2442_反转之后不同整数的数目](#2442)
#### [数组](#2442)
#### [哈希表](#2442)
#### [数学](#2442)
#### [计数](#2442)
### [2443_反转之后的数字和](#2443)
#### [数学](#2443)
#### [枚举](#2443)
### [2444_统计定界子数组的数目](#2444)
#### [队列](#2444)
#### [数组](#2444)
#### [滑动窗口](#2444)
#### [单调队列](#2444)
### [2445_值为 1 的节点数 🔒](#2445)
#### [树](#2445)
#### [深度优先搜索](#2445)
#### [广度优先搜索](#2445)
#### [数组](#2445)
#### [二叉树](#2445)
### [2446_判断两个事件是否存在冲突](#2446)
#### [数组](#2446)
#### [字符串](#2446)
### [2447_最大公因数等于 K 的子数组数目](#2447)
#### [数组](#2447)
#### [数学](#2447)
#### [数论](#2447)
### [2448_使数组相等的最小开销](#2448)
#### [贪心](#2448)
#### [数组](#2448)
#### [二分查找](#2448)
#### [前缀和](#2448)
#### [排序](#2448)
### [2449_使数组相似的最少操作次数](#2449)
#### [贪心](#2449)
#### [数组](#2449)
#### [排序](#2449)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2440_创建价值相同的连通块
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 数学
___
#### 枚举
---
### 2441_与对应负数同时存在的最大正整数
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 排序
---
### 2442_反转之后不同整数的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
---
### 2443_反转之后的数字和
___
#### 数学
___
#### 枚举
---
### 2444_统计定界子数组的数目
___
#### 队列
___
#### 数组
___
#### 滑动窗口
___
#### 单调队列
---
### 2445_值为 1 的节点数 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 二叉树
---
### 2446_判断两个事件是否存在冲突
___
#### 数组
___
#### 字符串
---
### 2447_最大公因数等于 K 的子数组数目
___
#### 数组
___
#### 数学
___
#### 数论
---
### 2448_使数组相等的最小开销
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
---
### 2449_使数组相似的最少操作次数
___
#### 贪心
___
#### 数组
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 单调队列 | 双指针 | 哈希表 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 树 | 深度优先搜索 |
| 滑动窗口 | 计数 | 贪心 |
| 队列 |  |  |

# [2440. 创建价值相同的连通块](https://leetcode.cn/problems/create-components-with-same-value){#2440}

{{< tabs "2440" >}}

{{% tab "python" %}}
```python
class Solution:
    def componentValue(self, nums: List[int], edges: List[List[int]]) -> int:
        def dfs(i, fa):
            x = nums[i]
            for j in g[i]:
                if j != fa:
                    y = dfs(j, i)
                    if y == -1:
                        return -1
                    x += y
            if x > t:
                return -1
            return x if x < t else 0

        n = len(nums)
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        s = sum(nums)
        mx = max(nums)
        for k in range(min(n, s // mx), 1, -1):
            if s % k == 0:
                t = s // k
                if dfs(0, -1) == 0:
                    return k - 1
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] nums;
    private int t;

    public int componentValue(int[] nums, int[][] edges) {
        int n = nums.length;
        g = new List[n];
        this.nums = nums;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int s = sum(nums), mx = max(nums);
        for (int k = Math.min(n, s / mx); k > 1; --k) {
            if (s % k == 0) {
                t = s / k;
                if (dfs(0, -1) == 0) {
                    return k - 1;
                }
            }
        }
        return 0;
    }

    private int dfs(int i, int fa) {
        int x = nums[i];
        for (int j : g[i]) {
            if (j != fa) {
                int y = dfs(j, i);
                if (y == -1) {
                    return -1;
                }
                x += y;
            }
        }
        if (x > t) {
            return -1;
        }
        return x < t ? x : 0;
    }

    private int sum(int[] arr) {
        int x = 0;
        for (int v : arr) {
            x += v;
        }
        return x;
    }

    private int max(int[] arr) {
        int x = arr[0];
        for (int v : arr) {
            x = Math.max(x, v);
        }
        return x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int mx = *max_element(nums.begin(), nums.end());
        int t = 0;
        unordered_map<int, vector<int>> g;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<int(int, int)> dfs = [&](int i, int fa) -> int {
            int x = nums[i];
            for (int j : g[i]) {
                if (j != fa) {
                    int y = dfs(j, i);
                    if (y == -1) return -1;
                    x += y;
                }
            }
            if (x > t) return -1;
            return x < t ? x : 0;
        };
        for (int k = min(n, s / mx); k > 1; --k) {
            if (s % k == 0) {
                t = s / k;
                if (dfs(0, -1) == 0) {
                    return k - 1;
                }
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func componentValue(nums []int, edges [][]int) int {
	s, mx := 0, slices.Max(nums)
	for _, x := range nums {
		s += x
	}
	n := len(nums)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	t := 0
	var dfs func(int, int) int
	dfs = func(i, fa int) int {
		x := nums[i]
		for _, j := range g[i] {
			if j != fa {
				y := dfs(j, i)
				if y == -1 {
					return -1
				}
				x += y
			}
		}
		if x > t {
			return -1
		}
		if x < t {
			return x
		}
		return 0
	}
	for k := min(n, s/mx); k > 1; k-- {
		if s%k == 0 {
			t = s / k
			if dfs(0, -1) == 0 {
				return k - 1
			}
		}
	}
	return 0
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一棵&nbsp;<code>n</code>&nbsp;个节点的无向树，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个节点的值。同时给你一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code>&nbsp;与&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。</p>

<p>你可以 <strong>删除</strong>&nbsp;一些边，将这棵树分成几个连通块。一个连通块的 <strong>价值</strong>&nbsp;定义为这个连通块中 <strong>所有</strong> 节点 <code>i</code>&nbsp;对应的 <code>nums[i]</code>&nbsp;之和。</p>

<p>你需要删除一些边，删除后得到的各个连通块的价值都相等。请返回你可以删除的边数&nbsp;<strong>最多</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2440.Create%20Components%20With%20Same%20Value/images/diagramdrawio.png" style="width: 441px; height: 351px;"></p>

<pre><b>输入：</b>nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]] 
<b>输出：</b>2 
<b>解释：</b>上图展示了我们可以删除边 [0,1] 和 [3,4] 。得到的连通块为 [0] ，[1,2,3] 和 [4] 。每个连通块的价值都为 6 。可以证明没有别的更好的删除方案存在了，所以答案为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2], edges = []
<b>输出：</b>0
<b>解释：</b>没有任何边可以删除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li><code>edges</code>&nbsp;表示一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举连通块的个数

假设连通块的个数为 $k$，那么要删除的边数为 $k-1$，每个连通块的价值为 $\frac{s}{k}$，其中 $s$ 为 $nums$ 所有节点的值之和。

我们从大到小枚举 $k$，如果存在一个 $k$，使得 $\frac{s}{k}$ 是整数，并且得到的每个连通块的价值都相等，那么直接返回 $k-1$。其中 $k$ 的初始值为 $\min(n, \frac{s}{mx})$，记 $mx$ 为 $nums$ 中的最大值。

关键点在于判断对于给定的 $\frac{s}{k}$，是否能划分出若干子树，使得每棵子树的价值都为 $\frac{s}{k}$。

这里我们通过 `dfs` 函数来判断，从上到下递归遍历求出各个子树的价值，如果子树价值和恰好为 $\frac{s}{k}$，说明此时划分成功，我们将价值置为 $0$ 返回给上一层，表示此子树可以与父节点断开。如果子树价值之和大于 $\frac{s}{k}$，说明此时划分失败，我们返回 $-1$，表示无法划分。

时间复杂度 $O(n \times \sqrt{s})$，其中 $n$ 和 $s$ 分别为 $nums$ 的长度和 $nums$ 所有节点的值之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def componentValue(self, nums: List[int], edges: List[List[int]]) -> int:
        def dfs(i, fa):
            x = nums[i]
            for j in g[i]:
                if j != fa:
                    y = dfs(j, i)
                    if y == -1:
                        return -1
                    x += y
            if x > t:
                return -1
            return x if x < t else 0

        n = len(nums)
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        s = sum(nums)
        mx = max(nums)
        for k in range(min(n, s // mx), 1, -1):
            if s % k == 0:
                t = s // k
                if dfs(0, -1) == 0:
                    return k - 1
        return 0
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] nums;
    private int t;

    public int componentValue(int[] nums, int[][] edges) {
        int n = nums.length;
        g = new List[n];
        this.nums = nums;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int s = sum(nums), mx = max(nums);
        for (int k = Math.min(n, s / mx); k > 1; --k) {
            if (s % k == 0) {
                t = s / k;
                if (dfs(0, -1) == 0) {
                    return k - 1;
                }
            }
        }
        return 0;
    }

    private int dfs(int i, int fa) {
        int x = nums[i];
        for (int j : g[i]) {
            if (j != fa) {
                int y = dfs(j, i);
                if (y == -1) {
                    return -1;
                }
                x += y;
            }
        }
        if (x > t) {
            return -1;
        }
        return x < t ? x : 0;
    }

    private int sum(int[] arr) {
        int x = 0;
        for (int v : arr) {
            x += v;
        }
        return x;
    }

    private int max(int[] arr) {
        int x = arr[0];
        for (int v : arr) {
            x = Math.max(x, v);
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int mx = *max_element(nums.begin(), nums.end());
        int t = 0;
        unordered_map<int, vector<int>> g;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<int(int, int)> dfs = [&](int i, int fa) -> int {
            int x = nums[i];
            for (int j : g[i]) {
                if (j != fa) {
                    int y = dfs(j, i);
                    if (y == -1) return -1;
                    x += y;
                }
            }
            if (x > t) return -1;
            return x < t ? x : 0;
        };
        for (int k = min(n, s / mx); k > 1; --k) {
            if (s % k == 0) {
                t = s / k;
                if (dfs(0, -1) == 0) {
                    return k - 1;
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func componentValue(nums []int, edges [][]int) int {
	s, mx := 0, slices.Max(nums)
	for _, x := range nums {
		s += x
	}
	n := len(nums)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	t := 0
	var dfs func(int, int) int
	dfs = func(i, fa int) int {
		x := nums[i]
		for _, j := range g[i] {
			if j != fa {
				y := dfs(j, i)
				if y == -1 {
					return -1
				}
				x += y
			}
		}
		if x > t {
			return -1
		}
		if x < t {
			return x
		}
		return 0
	}
	for k := min(n, s/mx); k > 1; k-- {
		if s%k == 0 {
			t = s / k
			if dfs(0, -1) == 0 {
				return k - 1
			}
		}
	}
	return 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2441. 与对应负数同时存在的最大正整数](https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative){#2441}

{{< tabs "2441" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        return max((x for x in s if -x in s), default=-1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaxK(int[] nums) {
        int ans = -1;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        for (int x : s) {
            if (s.contains(-x)) {
                ans = Math.max(ans, x);
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
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = -1;
        for (int x : s) {
            if (s.count(-x)) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxK(nums []int) int {
	ans := -1
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for x := range s {
		if s[-x] && ans < x {
			ans = x
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxK(nums: number[]): number {
    let ans = -1;
    const s = new Set(nums);
    for (const x of s) {
        if (s.has(-x)) {
            ans = Math.max(ans, x);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let mut ans = -1;
        let mut h = HashSet::new();

        for &n in &nums {
            h.insert(n);
        }

        for &n in &nums {
            if h.contains(&-n) && n > ans {
                ans = n;
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

<p>给你一个 <strong>不包含</strong> 任何零的整数数组 <code>nums</code> ，找出自身与对应的负数都在数组中存在的最大正整数 <code>k</code> 。</p>

<p>返回正整数<em> </em><code>k</code> ，如果不存在这样的整数，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,2,-3,3]
<strong>输出：</strong>3
<strong>解释：</strong>3 是数组中唯一一个满足题目要求的 k 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,10,6,7,-7,1]
<strong>输出：</strong>7
<strong>解释：</strong>数组中存在 1 和 7 对应的负数，7 的值更大。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-10,8,6,7,-2,-3]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在满足题目要求的 k ，返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums[i] != 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用哈希表 $s$ 记录数组中出现的所有元素，用一个变量 $ans$ 记录满足题目要求的最大正整数，初始时 $ans = -1$。

接下来，我们遍历哈希表 $s$ 中的每个元素 $x$，如果 $s$ 中存在 $-x$，那么我们就更新 $ans = \max(ans, x)$。

遍历结束后，返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        return max((x for x in s if -x in s), default=-1)
```

#### Java

```java
class Solution {
    public int findMaxK(int[] nums) {
        int ans = -1;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        for (int x : s) {
            if (s.contains(-x)) {
                ans = Math.max(ans, x);
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
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = -1;
        for (int x : s) {
            if (s.count(-x)) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMaxK(nums []int) int {
	ans := -1
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for x := range s {
		if s[-x] && ans < x {
			ans = x
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findMaxK(nums: number[]): number {
    let ans = -1;
    const s = new Set(nums);
    for (const x of s) {
        if (s.has(-x)) {
            ans = Math.max(ans, x);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let s = nums.into_iter().collect::<HashSet<i32>>();
        let mut ans = -1;
        for &x in s.iter() {
            if s.contains(&-x) {
                ans = ans.max(x);
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let mut ans = -1;
        let mut h = HashSet::new();

        for &n in &nums {
            h.insert(n);
        }

        for &n in &nums {
            if h.contains(&-n) && n > ans {
                ans = n;
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

# [2442. 反转之后不同整数的数目](https://leetcode.cn/problems/count-number-of-distinct-integers-after-reverse-operations){#2442}

{{< tabs "2442" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        s = set(nums)
        for x in nums:
            y = int(str(x)[::-1])
            s.add(y)
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDistinctIntegers(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        for (int x : nums) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            s.add(y);
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x : nums) {
            int y = 0;
            while (x) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            s.insert(y);
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDistinctIntegers(nums []int) int {
	s := map[int]struct{}{}
	for _, x := range nums {
		s[x] = struct{}{}
	}
	for _, x := range nums {
		y := 0
		for x > 0 {
			y = y*10 + x%10
			x /= 10
		}
		s[y] = struct{}{}
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countDistinctIntegers(nums: number[]): number {
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        nums.push(Number([...(nums[i] + '')].reverse().join('')));
    }
    return new Set(nums).size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn count_distinct_integers(nums: Vec<i32>) -> i32 {
        let mut set = HashSet::new();
        for i in 0..nums.len() {
            let mut num = nums[i];
            set.insert(num);
            set.insert({
                let mut item = 0;
                while num > 0 {
                    item = item * 10 + (num % 10);
                    num /= 10;
                }
                item
            });
        }
        set.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>正</strong> 整数组成的数组 <code>nums</code> 。</p>

<p>你必须取出数组中的每个整数，<strong>反转其中每个数位</strong>，并将反转后得到的数字添加到数组的末尾。这一操作只针对 <code>nums</code> 中原有的整数执行。</p>

<p>返回结果数组中 <strong>不同</strong> 整数的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,13,10,12,31]
<strong>输出：</strong>6
<strong>解释：</strong>反转每个数字后，结果数组是 [1,13,10,12,31,<em><strong>1,31,1,21,13</strong></em>] 。
反转后得到的数字添加到数组的末尾并按斜体加粗表示。注意对于整数 10 ，反转之后会变成 01 ，即 1 。
数组中不同整数的数目为 6（数字 1、10、12、13、21 和 31）。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>反转每个数字后，结果数组是 [2,2,2,<em><strong>2,2,2</strong></em>] 。
数组中不同整数的数目为 1（数字 2）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们先用哈希表记录数组中的所有整数，然后遍历数组中的每个整数，对其进行反转，将反转后的整数添加到哈希表中，最后返回哈希表的大小即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        s = set(nums)
        for x in nums:
            y = int(str(x)[::-1])
            s.add(y)
        return len(s)
```

#### Java

```java
class Solution {
    public int countDistinctIntegers(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        for (int x : nums) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            s.add(y);
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x : nums) {
            int y = 0;
            while (x) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            s.insert(y);
        }
        return s.size();
    }
};
```

#### Go

```go
func countDistinctIntegers(nums []int) int {
	s := map[int]struct{}{}
	for _, x := range nums {
		s[x] = struct{}{}
	}
	for _, x := range nums {
		y := 0
		for x > 0 {
			y = y*10 + x%10
			x /= 10
		}
		s[y] = struct{}{}
	}
	return len(s)
}
```

#### TypeScript

```ts
function countDistinctIntegers(nums: number[]): number {
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        nums.push(Number([...(nums[i] + '')].reverse().join('')));
    }
    return new Set(nums).size;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn count_distinct_integers(nums: Vec<i32>) -> i32 {
        let mut set = HashSet::new();
        for i in 0..nums.len() {
            let mut num = nums[i];
            set.insert(num);
            set.insert({
                let mut item = 0;
                while num > 0 {
                    item = item * 10 + (num % 10);
                    num /= 10;
                }
                item
            });
        }
        set.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2443. 反转之后的数字和](https://leetcode.cn/problems/sum-of-number-and-its-reverse){#2443}

{{< tabs "2443" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        return any(k + int(str(k)[::-1]) == num for k in range(num + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; ++x) {
            int k = x;
            int y = 0;
            while (k > 0) {
                y = y * 10 + k % 10;
                k /= 10;
            }
            if (x + y == num) {
                return true;
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
    bool sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; ++x) {
            int k = x;
            int y = 0;
            while (k > 0) {
                y = y * 10 + k % 10;
                k /= 10;
            }
            if (x + y == num) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfNumberAndReverse(num int) bool {
	for x := 0; x <= num; x++ {
		k, y := x, 0
		for k > 0 {
			y = y*10 + k%10
			k /= 10
		}
		if x+y == num {
			return true
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfNumberAndReverse(num: number): boolean {
    for (let i = 0; i <= num; i++) {
        if (i + Number([...(i + '')].reverse().join('')) === num) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_number_and_reverse(num: i32) -> bool {
        for i in 0..=num {
            if i + ({
                let mut t = i;
                let mut j = 0;
                while t > 0 {
                    j = j * 10 + (t % 10);
                    t /= 10;
                }
                j
            }) == num
            {
                return true;
            }
        }
        false
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num; i++) {
        int t = i;
        int j = 0;
        while (t > 0) {
            j = j * 10 + t % 10;
            t /= 10;
        }
        if (i + j == num) {
            return 1;
        }
    }
    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非负</strong> 整数 <code>num</code> 。如果存在某个 <strong>非负</strong> 整数 <code>k</code> 满足 <code>k + reverse(k) = num</code>&nbsp; ，则返回 <code>true</code> ；否则，返回<em> </em><code>false</code> 。</p>

<p><code>reverse(k)</code> 表示 <code>k</code> 反转每个数位后得到的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 443
<strong>输出：</strong>true
<strong>解释：</strong>172 + 271 = 443 ，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 63
<strong>输出：</strong>false
<strong>解释：</strong>63 不能表示为非负整数及其反转后数字之和，返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = 181
<strong>输出：</strong>true
<strong>解释：</strong>140 + 041 = 181 ，所以返回 true 。注意，反转后的数字可能包含前导零。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

在 $[0,.., num]$ 范围内枚举 $k$，判断 $k + reverse(k)$ 是否等于 $num$ 即可。

时间复杂度 $O(n \times \log n)。其中 $n$ 为 $num$ 的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        return any(k + int(str(k)[::-1]) == num for k in range(num + 1))
```

#### Java

```java
class Solution {
    public boolean sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; ++x) {
            int k = x;
            int y = 0;
            while (k > 0) {
                y = y * 10 + k % 10;
                k /= 10;
            }
            if (x + y == num) {
                return true;
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
    bool sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; ++x) {
            int k = x;
            int y = 0;
            while (k > 0) {
                y = y * 10 + k % 10;
                k /= 10;
            }
            if (x + y == num) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func sumOfNumberAndReverse(num int) bool {
	for x := 0; x <= num; x++ {
		k, y := x, 0
		for k > 0 {
			y = y*10 + k%10
			k /= 10
		}
		if x+y == num {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function sumOfNumberAndReverse(num: number): boolean {
    for (let i = 0; i <= num; i++) {
        if (i + Number([...(i + '')].reverse().join('')) === num) {
            return true;
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_number_and_reverse(num: i32) -> bool {
        for i in 0..=num {
            if i + ({
                let mut t = i;
                let mut j = 0;
                while t > 0 {
                    j = j * 10 + (t % 10);
                    t /= 10;
                }
                j
            }) == num
            {
                return true;
            }
        }
        false
    }
}
```

#### C

```c
bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num; i++) {
        int t = i;
        int j = 0;
        while (t > 0) {
            j = j * 10 + t % 10;
            t /= 10;
        }
        if (i + j == num) {
            return 1;
        }
    }
    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2444. 统计定界子数组的数目](https://leetcode.cn/problems/count-subarrays-with-fixed-bounds){#2444}

{{< tabs "2444" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        j1 = j2 = k = -1
        ans = 0
        for i, v in enumerate(nums):
            if v < minK or v > maxK:
                k = i
            if v == minK:
                j1 = i
            if v == maxK:
                j2 = i
            ans += max(0, min(j1, j2) - k)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long ans = 0;
        int j1 = -1, j2 = -1, k = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += Math.max(0, Math.min(j1, j2) - k);
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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j1 = -1, j2 = -1, k = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += max(0, min(j1, j2) - k);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int, minK int, maxK int) int64 {
	ans := 0
	j1, j2, k := -1, -1, -1
	for i, v := range nums {
		if v < minK || v > maxK {
			k = i
		}
		if v == minK {
			j1 = i
		}
		if v == maxK {
			j2 = i
		}
		ans += max(0, min(j1, j2)-k)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[], minK: number, maxK: number): number {
    let ans = 0;
    let [j1, j2, k] = [-1, -1, -1];
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] < minK || nums[i] > maxK) k = i;
        if (nums[i] === minK) j1 = i;
        if (nums[i] === maxK) j2 = i;
        ans += Math.max(0, Math.min(j1, j2) - k);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
        let mut ans: i64 = 0;
        let mut j1: i64 = -1;
        let mut j2: i64 = -1;
        let mut k: i64 = -1;
        for (i, &v) in nums.iter().enumerate() {
            let i = i as i64;
            if v < min_k || v > max_k {
                k = i;
            }
            if v == min_k {
                j1 = i;
            }
            if v == max_k {
                j2 = i;
            }
            let m = j1.min(j2);
            if m > k {
                ans += m - k;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long ans = 0;
    int j1 = -1, j2 = -1, k = -1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < minK || nums[i] > maxK) k = i;
        if (nums[i] == minK) j1 = i;
        if (nums[i] == maxK) j2 = i;
        int m = j1 < j2 ? j1 : j2;
        if (m > k) ans += (long long) (m - k);
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

<p>给你一个整数数组 <code>nums</code> 和两个整数 <code>minK</code> 以及 <code>maxK</code> 。</p>

<p><code>nums</code> 的定界子数组是满足下述条件的一个子数组：</p>

<ul>
	<li>子数组中的 <strong>最小值</strong> 等于 <code>minK</code> 。</li>
	<li>子数组中的 <strong>最大值</strong> 等于 <code>maxK</code> 。</li>
</ul>

<p>返回定界子数组的数目。</p>

<p>子数组是数组中的一个连续部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,5,2,7,5], minK = 1, maxK = 5
<strong>输出：</strong>2
<strong>解释：</strong>定界子数组是 [1,3,5] 和 [1,3,5,2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1], minK = 1, maxK = 1
<strong>输出：</strong>10
<strong>解释：</strong>nums 的每个子数组都是一个定界子数组。共有 10 个子数组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], minK, maxK &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举右端点

由题意，我们可以知道，定界子数组的所有元素都在区间 $[\textit{minK}, \textit{maxK}]$ 中，且最小值一定为 $\textit{minK}$，最大值一定为 $\textit{maxK}$。

我们遍历数组 $\textit{nums}$，统计以 $\textit{nums}[i]$ 为右端点的定界子数组的个数，然后将所有的个数相加即可。

具体实现逻辑如下：

1. 维护最近一个不在区间 $[\textit{minK}, \textit{maxK}]$ 中的元素的下标 $k$，初始值为 $-1$。那么当前元素 $\textit{nums}[i]$ 的左端点一定大于 $k$。
2. 维护最近一个值为 $\textit{minK}$ 的下标 $j_1$，最近一个值为 $\textit{maxK}$ 的下标 $j_2$，初始值均为 $-1$。那么当前元素 $\textit{nums}[i]$ 的左端点一定小于等于 $\min(j_1, j_2)$。
3. 综上可知，以当前元素为右端点的定界子数组的个数为 $\max\bigl(0,\ \min(j_1, j_2) - k\bigr)$。累加所有的个数即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        j1 = j2 = k = -1
        ans = 0
        for i, v in enumerate(nums):
            if v < minK or v > maxK:
                k = i
            if v == minK:
                j1 = i
            if v == maxK:
                j2 = i
            ans += max(0, min(j1, j2) - k)
        return ans
```

#### Java

```java
class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long ans = 0;
        int j1 = -1, j2 = -1, k = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += Math.max(0, Math.min(j1, j2) - k);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j1 = -1, j2 = -1, k = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += max(0, min(j1, j2) - k);
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int, minK int, maxK int) int64 {
	ans := 0
	j1, j2, k := -1, -1, -1
	for i, v := range nums {
		if v < minK || v > maxK {
			k = i
		}
		if v == minK {
			j1 = i
		}
		if v == maxK {
			j2 = i
		}
		ans += max(0, min(j1, j2)-k)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[], minK: number, maxK: number): number {
    let ans = 0;
    let [j1, j2, k] = [-1, -1, -1];
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] < minK || nums[i] > maxK) k = i;
        if (nums[i] === minK) j1 = i;
        if (nums[i] === maxK) j2 = i;
        ans += Math.max(0, Math.min(j1, j2) - k);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
        let mut ans: i64 = 0;
        let mut j1: i64 = -1;
        let mut j2: i64 = -1;
        let mut k: i64 = -1;
        for (i, &v) in nums.iter().enumerate() {
            let i = i as i64;
            if v < min_k || v > max_k {
                k = i;
            }
            if v == min_k {
                j1 = i;
            }
            if v == max_k {
                j2 = i;
            }
            let m = j1.min(j2);
            if m > k {
                ans += m - k;
            }
        }
        ans
    }
}
```

#### C

```c
long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long ans = 0;
    int j1 = -1, j2 = -1, k = -1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < minK || nums[i] > maxK) k = i;
        if (nums[i] == minK) j1 = i;
        if (nums[i] == maxK) j2 = i;
        int m = j1 < j2 ? j1 : j2;
        if (m > k) ans += (long long) (m - k);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2445. 值为 1 的节点数 🔒](https://leetcode.cn/problems/number-of-nodes-with-value-one){#2445}

{{< tabs "2445" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfNodes(self, n: int, queries: List[int]) -> int:
        def dfs(i):
            if i > n:
                return
            tree[i] ^= 1
            dfs(i << 1)
            dfs(i << 1 | 1)

        tree = [0] * (n + 1)
        cnt = Counter(queries)
        for i, v in cnt.items():
            if v & 1:
                dfs(i)
        return sum(tree)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] tree;

    public int numberOfNodes(int n, int[] queries) {
        tree = new int[n + 1];
        int[] cnt = new int[n + 1];
        for (int v : queries) {
            ++cnt[v];
        }
        for (int i = 0; i < n + 1; ++i) {
            if (cnt[i] % 2 == 1) {
                dfs(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < n + 1; ++i) {
            ans += tree[i];
        }
        return ans;
    }

    private void dfs(int i) {
        if (i >= tree.length) {
            return;
        }
        tree[i] ^= 1;
        dfs(i << 1);
        dfs(i << 1 | 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> tree(n + 1);
        vector<int> cnt(n + 1);
        for (int v : queries) ++cnt[v];
        function<void(int)> dfs = [&](int i) {
            if (i > n) return;
            tree[i] ^= 1;
            dfs(i << 1);
            dfs(i << 1 | 1);
        };
        for (int i = 0; i < n + 1; ++i) {
            if (cnt[i] & 1) {
                dfs(i);
            }
        }
        return accumulate(tree.begin(), tree.end(), 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfNodes(n int, queries []int) int {
	tree := make([]int, n+1)
	cnt := make([]int, n+1)
	for _, v := range queries {
		cnt[v]++
	}
	var dfs func(int)
	dfs = func(i int) {
		if i > n {
			return
		}
		tree[i] ^= 1
		dfs(i << 1)
		dfs(i<<1 | 1)
	}
	for i, v := range cnt {
		if v%2 == 1 {
			dfs(i)
		}
	}
	ans := 0
	for _, v := range tree {
		ans += v
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个&nbsp;<strong>无向&nbsp;</strong>树，有 <code>n</code> 个节点，节点标记为从 <code>1</code> 到 <code>n</code>&nbsp;，还有&nbsp;<code>n - 1</code> 条边。给定整数 <code>n</code>。标记为 <code>v</code> 的节点的父节点是标记为&nbsp;<code>floor (v / 2)</code>&nbsp;的节点。树的根节点是标记为 <code>1</code> 的节点。</p>

<ul>
	<li>例如，如果 <code>n = 7</code>，那么标记为 <code>3</code> 的节点将标记&nbsp;<code>floor(3 / 2) = 1</code> 的节点作为其父节点，标记为 <code>7</code> 的节点将标记&nbsp;<code>floor(7 / 2) = 3</code> 的节点作为其父节点。</li>
</ul>

<p>你还得到一个整数数组 <code>queries</code>。最初，每个节点的值都是 <code>0</code>。对于每个查询 <code>queries[i]</code>，您应该翻转节点标记为&nbsp;<code>queries[i]</code> 的子树中的所有值。</p>

<p>在&nbsp;<strong>处理完所有查询后</strong>，返回<em>值为 <code>1</code> 的节点总数。</em></p>

<p><b>注意</b>:</p>

<ul>
	<li>翻转节点的值意味着值为 <code>0</code> 的节点变为 <code>1</code>，反之亦然。</li>
	<li><code>floor(x)</code>&nbsp;相当于将 <code>x</code> 舍入到最接近的整数。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2445.Number%20of%20Nodes%20With%20Value%20One/images/ex1.jpg" style="width: 600px; height: 297px;" />
<pre>
<strong>输入:</strong> n = 5 , queries = [1,2,5]
<strong>输出:</strong> 3
<strong>解释:</strong> 上图显示了执行查询后的树结构及其状态。蓝色节点表示值 0，红色节点表示值 1。
在处理查询之后，有三个红色节点 (值为 1 的节点): 1、3、5。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2445.Number%20of%20Nodes%20With%20Value%20One/images/ex2.jpg" style="width: 650px; height: 88px;" />
<pre>
<strong>输入:</strong> n = 3, queries = [2,3,3]
<strong>输出:</strong> 1
<strong>解释:</strong> 上图显示了执行查询后的树结构及其状态。蓝色节点表示值 0，红色节点表示值 1。
在处理查询之后，有一个红色节点 (值为 1 的节点): 2。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意，我们可以模拟每次查询的过程，即将查询节点及其子树的节点值反转。最后统计节点值为 1 的节点个数即可。

这里有一个优化点，每个节点及其对应的子树，如果经过了偶数次查询，那么节点值不会发生变化，因此我们可以记录每个节点的查询次数，对于奇数次查询的节点及其子树，才进行反转。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为节点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfNodes(self, n: int, queries: List[int]) -> int:
        def dfs(i):
            if i > n:
                return
            tree[i] ^= 1
            dfs(i << 1)
            dfs(i << 1 | 1)

        tree = [0] * (n + 1)
        cnt = Counter(queries)
        for i, v in cnt.items():
            if v & 1:
                dfs(i)
        return sum(tree)
```

#### Java

```java
class Solution {
    private int[] tree;

    public int numberOfNodes(int n, int[] queries) {
        tree = new int[n + 1];
        int[] cnt = new int[n + 1];
        for (int v : queries) {
            ++cnt[v];
        }
        for (int i = 0; i < n + 1; ++i) {
            if (cnt[i] % 2 == 1) {
                dfs(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < n + 1; ++i) {
            ans += tree[i];
        }
        return ans;
    }

    private void dfs(int i) {
        if (i >= tree.length) {
            return;
        }
        tree[i] ^= 1;
        dfs(i << 1);
        dfs(i << 1 | 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> tree(n + 1);
        vector<int> cnt(n + 1);
        for (int v : queries) ++cnt[v];
        function<void(int)> dfs = [&](int i) {
            if (i > n) return;
            tree[i] ^= 1;
            dfs(i << 1);
            dfs(i << 1 | 1);
        };
        for (int i = 0; i < n + 1; ++i) {
            if (cnt[i] & 1) {
                dfs(i);
            }
        }
        return accumulate(tree.begin(), tree.end(), 0);
    }
};
```

#### Go

```go
func numberOfNodes(n int, queries []int) int {
	tree := make([]int, n+1)
	cnt := make([]int, n+1)
	for _, v := range queries {
		cnt[v]++
	}
	var dfs func(int)
	dfs = func(i int) {
		if i > n {
			return
		}
		tree[i] ^= 1
		dfs(i << 1)
		dfs(i<<1 | 1)
	}
	for i, v := range cnt {
		if v%2 == 1 {
			dfs(i)
		}
	}
	ans := 0
	for _, v := range tree {
		ans += v
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2446. 判断两个事件是否存在冲突](https://leetcode.cn/problems/determine-if-two-events-have-conflict){#2446}

{{< tabs "2446" >}}

{{% tab "python" %}}
```python
class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        return not (event1[0] > event2[1] or event1[1] < event2[0])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        return !(event1[0].compareTo(event2[1]) > 0 || event1[1].compareTo(event2[0]) < 0);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[0] > event2[1] || event1[1] < event2[0]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func haveConflict(event1 []string, event2 []string) bool {
	return !(event1[0] > event2[1] || event1[1] < event2[0])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function haveConflict(event1: string[], event2: string[]): boolean {
    return !(event1[0] > event2[1] || event1[1] < event2[0]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn have_conflict(event1: Vec<String>, event2: Vec<String>) -> bool {
        !(event1[1] < event2[0] || event1[0] > event2[1])
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串数组 <code>event1</code> 和&nbsp;<code>event2</code>&nbsp;，表示发生在同一天的两个闭区间时间段事件，其中：</p>

<ul>
	<li><code>event1 = [startTime<sub>1</sub>, endTime<sub>1</sub>]</code> 且</li>
	<li><code>event2 = [startTime<sub>2</sub>, endTime<sub>2</sub>]</code></li>
</ul>

<p>事件的时间为有效的 24 小时制且按&nbsp;<code>HH:MM</code>&nbsp;格式给出。</p>

<p>当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），则认为出现 <strong>冲突</strong>&nbsp;。</p>

<p>如果两个事件之间存在冲突，返回&nbsp;<code>true</code><em>&nbsp;</em>；否则，返回<em>&nbsp;</em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
<b>输出：</b>true
<b>解释：</b>两个事件在 2:00 出现交集。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
<b>输出：</b>true
<b>解释：</b>两个事件的交集从 01:20 开始，到 02:00 结束。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
<b>输出：</b>false
<b>解释：</b>两个事件不存在交集。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>event1.length == event2.length == 2</code></li>
	<li><code>event1[i].length == event2[i].length == 5</code></li>
	<li><code>startTime<sub>1</sub> &lt;= endTime<sub>1</sub></code></li>
	<li><code>startTime<sub>2</sub> &lt;= endTime<sub>2</sub></code></li>
	<li>所有事件的时间都按照&nbsp;<code>HH:MM</code>&nbsp;格式给出</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串比较

如果 $event1$ 的开始时间大于 $event2$ 的结束时间，或者 $event1$ 的结束时间小于 $event2$ 的开始时间，那么两个事件不会有冲突。否则，两个事件存在冲突。

<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2446.Determine%20if%20Two%20Events%20Have%20Conflict/images/event.png" />

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        return not (event1[0] > event2[1] or event1[1] < event2[0])
```

#### Java

```java
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        return !(event1[0].compareTo(event2[1]) > 0 || event1[1].compareTo(event2[0]) < 0);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[0] > event2[1] || event1[1] < event2[0]);
    }
};
```

#### Go

```go
func haveConflict(event1 []string, event2 []string) bool {
	return !(event1[0] > event2[1] || event1[1] < event2[0])
}
```

#### TypeScript

```ts
function haveConflict(event1: string[], event2: string[]): boolean {
    return !(event1[0] > event2[1] || event1[1] < event2[0]);
}
```

#### Rust

```rust
impl Solution {
    pub fn have_conflict(event1: Vec<String>, event2: Vec<String>) -> bool {
        !(event1[1] < event2[0] || event1[0] > event2[1])
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2447. 最大公因数等于 K 的子数组数目](https://leetcode.cn/problems/number-of-subarrays-with-gcd-equal-to-k){#2447}

{{< tabs "2447" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(len(nums)):
            g = 0
            for x in nums[i:]:
                g = gcd(g, x)
                ans += g == k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subarrayGCD(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == k) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                ans += g == k;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subarrayGCD(nums []int, k int) (ans int) {
	for i := range nums {
		g := 0
		for _, x := range nums[i:] {
			g = gcd(g, x)
			if g == k {
				ans++
			}
		}
	}
	return
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subarrayGCD(nums: number[], k: number): number {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let g = 0;
        for (let j = i; j < n; ++j) {
            g = gcd(g, nums[j]);
            if (g === k) {
                ++ans;
            }
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code> ，请你统计并返回 <code>nums</code>&nbsp;的子数组中元素的最大公因数等于 <code>k</code>&nbsp;的子数组数目。</p>

<p><strong>子数组</strong> 是数组中一个连续的非空序列。</p>

<p><strong>数组的最大公因数</strong>&nbsp;是能整除数组中所有元素的最大整数。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>nums = [9,3,1,2,6,3], k = 3
<b>输出：</b>4
<b>解释：</b>nums 的子数组中，以 3 作为最大公因数的子数组如下：
- [9,<strong><em>3</em></strong>,1,2,6,3]
- [9,3,1,2,6,<em><strong>3</strong></em>]
- [<strong><em>9,3</em></strong>,1,2,6,3]
- [9,3,1,2,<em><strong>6,3</strong></em>]
</pre>

<p><b>示例 2：</b></p>

<pre><b>输入：</b>nums = [4], k = 7
<b>输出：</b>0
<b>解释：</b>不存在以 7 作为最大公因数的子数组。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接枚举

我们可以枚举 $nums[i]$ 作为子数组的左端点，然后枚举 $nums[j]$ 作为子数组的右端点，其中 $i \le j$。在枚举右端点的过程中，我们可以用一个变量 $g$ 来维护当前子数组的最大公因数，每次枚举到一个新的右端点时，我们更新最大公因数 $g = \gcd(g, nums[j])$。如果 $g=k$，那么当前子数组的最大公因数等于 $k$，我们就将答案增加 $1$。

枚举结束后，返回答案即可。

时间复杂度 $O(n \times (n + \log M))$，其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度和数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(len(nums)):
            g = 0
            for x in nums[i:]:
                g = gcd(g, x)
                ans += g == k
        return ans
```

#### Java

```java
class Solution {
    public int subarrayGCD(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == k) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                ans += g == k;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func subarrayGCD(nums []int, k int) (ans int) {
	for i := range nums {
		g := 0
		for _, x := range nums[i:] {
			g = gcd(g, x)
			if g == k {
				ans++
			}
		}
	}
	return
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function subarrayGCD(nums: number[], k: number): number {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let g = 0;
        for (let j = i; j < n; ++j) {
            g = gcd(g, nums[j]);
            if (g === k) {
                ++ans;
            }
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2448. 使数组相等的最小开销](https://leetcode.cn/problems/minimum-cost-to-make-array-equal){#2448}

{{< tabs "2448" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        arr = sorted(zip(nums, cost))
        mid = sum(cost) // 2
        s = 0
        for x, c in arr:
            s += c
            if s > mid:
                return sum(abs(v - x) * c for v, c in arr)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minCost(int[] nums, int[] cost) {
        int n = nums.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {nums[i], cost[i]};
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        long mid = sum(cost) / 2;
        long s = 0, ans = 0;
        for (var e : arr) {
            int x = e[0], c = e[1];
            s += c;
            if (s > mid) {
                for (var t : arr) {
                    ans += (long) Math.abs(t[0] - x) * t[1];
                }
                break;
            }
        }
        return ans;
    }

    private long sum(int[] arr) {
        long s = 0;
        for (int v : arr) {
            s += v;
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], cost[i]};
        sort(arr.begin(), arr.end());
        ll mid = accumulate(cost.begin(), cost.end(), 0ll) / 2;
        ll s = 0, ans = 0;
        for (auto [x, c] : arr) {
            s += c;
            if (s > mid) {
                for (auto [v, d] : arr) {
                    ans += 1ll * abs(v - x) * d;
                }
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(nums []int, cost []int) int64 {
	n := len(nums)
	type pair struct{ a, b int }
	arr := make([]pair, n)
	mid := 0
	for i, a := range nums {
		b := cost[i]
		mid += b
		arr[i] = pair{a, b}
	}
	mid /= 2
	sort.Slice(arr, func(i, j int) bool { return arr[i].a < arr[j].a })
	s, ans := 0, 0
	for _, e := range arr {
		x, c := e.a, e.b
		s += c
		if s > mid {
			for _, t := range arr {
				ans += abs(t.a-x) * t.b
			}
			break
		}
	}
	return int64(ans)

}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_cost(nums: Vec<i32>, cost: Vec<i32>) -> i64 {
        let mut zip_vec: Vec<_> = nums.into_iter().zip(cost.into_iter()).collect();

        // Sort the zip vector based on nums
        zip_vec.sort_by(|lhs, rhs| lhs.0.cmp(&rhs.0));

        let (nums, cost): (Vec<i32>, Vec<i32>) = zip_vec.into_iter().unzip();

        let mut sum: i64 = 0;
        for &c in &cost {
            sum += c as i64;
        }
        let middle_cost = (sum + 1) / 2;
        let mut cur_sum: i64 = 0;
        let mut i = 0;
        let n = nums.len();

        while i < n {
            if (cost[i] as i64) + cur_sum >= middle_cost {
                break;
            }
            cur_sum += cost[i] as i64;
            i += 1;
        }

        Self::compute_manhattan_dis(&nums, &cost, nums[i])
    }

    #[allow(dead_code)]
    fn compute_manhattan_dis(v: &Vec<i32>, c: &Vec<i32>, e: i32) -> i64 {
        let mut ret = 0;
        let n = v.len();

        for i in 0..n {
            if v[i] == e {
                continue;
            }
            ret += ((v[i] - e).abs() as i64) * (c[i] as i64);
        }

        ret
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code> 和&nbsp;<code>cost</code>&nbsp;，分别包含&nbsp;<code>n</code>&nbsp;个&nbsp;<strong>正</strong>&nbsp;整数。</p>

<p>你可以执行下面操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>将&nbsp;<code>nums</code>&nbsp;中 <strong>任意</strong>&nbsp;元素增加或者减小 <code>1</code>&nbsp;。</li>
</ul>

<p>对第 <code>i</code>&nbsp;个元素执行一次操作的开销是&nbsp;<code>cost[i]</code>&nbsp;。</p>

<p>请你返回使 <code>nums</code>&nbsp;中所有元素 <strong>相等</strong>&nbsp;的 <strong>最少</strong>&nbsp;总开销。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,5,2], cost = [2,3,1,14]
<b>输出：</b>8
<b>解释：</b>我们可以执行以下操作使所有元素变为 2 ：
- 增加第 0 个元素 1 次，开销为 2 。
- 减小第 1 个元素 1 次，开销为 3 。
- 减小第 2 个元素 3 次，开销为 1 + 1 + 1 = 3 。
总开销为 2 + 3 + 3 = 8 。
这是最小开销。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,2,2,2,2], cost = [4,2,8,1,3]
<b>输出：</b>0
<b>解释：</b>数组中所有元素已经全部相等，不需要执行额外的操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length == cost.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], cost[i] &lt;= 10<sup>6</sup></code></li>
	<li>测试用例确保输出不超过 2<sup>53</sup>-1。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 排序 + 枚举

我们记数组 `nums` 所有元素为 $a_1, a_2, \cdots, a_n$，数组 `cost` 所有元素为 $b_1, b_2, \cdots, b_n$。我们不妨令 $a_1 \leq a_2 \leq \cdots \leq a_n$，即数组 `nums` 升序排列。

假设我们将数组 `nums` 中的元素全部变为 $x$，那么我们需要的总开销为：

$$
\begin{aligned}
\sum_{i=1}^{n} \left | a_i-x \right | b_i  &= \sum_{i=1}^{k} (x-a_i)b_i + \sum_{i=k+1}^{n} (a_i-x)b_i \\
&= x\sum_{i=1}^{k} b_i - \sum_{i=1}^{k} a_ib_i + \sum_{i=k+1}^{n}a_ib_i - x\sum_{i=k+1}^{n}b_i
\end{aligned}
$$

其中 $k$ 为 $a_1, a_2, \cdots, a_n$ 中小于等于 $x$ 的元素个数。

我们可以使用前缀和的方法，计算 $\sum_{i=1}^{k} b_i$ 和 $\sum_{i=1}^{k} a_ib_i$，以及 $\sum_{i=k+1}^{n}a_ib_i$ 和 $\sum_{i=k+1}^{n}b_i$。

然后我们枚举 $x$，计算上述四个前缀和，得到上述的总开销，取其中的最小值即可。

时间复杂度 $O(n\times \log n)$。其中 $n$ 为数组 `nums` 的长度。主要是排序的时间复杂度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        arr = sorted(zip(nums, cost))
        n = len(arr)
        f = [0] * (n + 1)
        g = [0] * (n + 1)
        for i in range(1, n + 1):
            a, b = arr[i - 1]
            f[i] = f[i - 1] + a * b
            g[i] = g[i - 1] + b
        ans = inf
        for i in range(1, n + 1):
            a = arr[i - 1][0]
            l = a * g[i - 1] - f[i - 1]
            r = f[n] - f[i] - a * (g[n] - g[i])
            ans = min(ans, l + r)
        return ans
```

#### Java

```java
class Solution {
    public long minCost(int[] nums, int[] cost) {
        int n = nums.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {nums[i], cost[i]};
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        long[] f = new long[n + 1];
        long[] g = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            long a = arr[i - 1][0], b = arr[i - 1][1];
            f[i] = f[i - 1] + a * b;
            g[i] = g[i - 1] + b;
        }
        long ans = Long.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            long a = arr[i - 1][0];
            long l = a * g[i - 1] - f[i - 1];
            long r = f[n] - f[i] - a * (g[n] - g[i]);
            ans = Math.min(ans, l + r);
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], cost[i]};
        sort(arr.begin(), arr.end());
        vector<ll> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; ++i) {
            auto [a, b] = arr[i - 1];
            f[i] = f[i - 1] + 1ll * a * b;
            g[i] = g[i - 1] + b;
        }
        ll ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            auto [a, _] = arr[i - 1];
            ll l = 1ll * a * g[i - 1] - f[i - 1];
            ll r = f[n] - f[i] - 1ll * a * (g[n] - g[i]);
            ans = min(ans, l + r);
        }
        return ans;
    }
};
```

#### Go

```go
func minCost(nums []int, cost []int) int64 {
	n := len(nums)
	type pair struct{ a, b int }
	arr := make([]pair, n)
	for i, a := range nums {
		b := cost[i]
		arr[i] = pair{a, b}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].a < arr[j].a })
	f := make([]int, n+1)
	g := make([]int, n+1)
	for i := 1; i <= n; i++ {
		a, b := arr[i-1].a, arr[i-1].b
		f[i] = f[i-1] + a*b
		g[i] = g[i-1] + b
	}
	var ans int64 = 1e18
	for i := 1; i <= n; i++ {
		a := arr[i-1].a
		l := a*g[i-1] - f[i-1]
		r := f[n] - f[i] - a*(g[n]-g[i])
		ans = min(ans, int64(l+r))
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_cost(nums: Vec<i32>, cost: Vec<i32>) -> i64 {
        let mut zip_vec: Vec<_> = nums.into_iter().zip(cost.into_iter()).collect();

        // Sort the zip vector based on nums
        zip_vec.sort_by(|lhs, rhs| lhs.0.cmp(&rhs.0));

        let (nums, cost): (Vec<i32>, Vec<i32>) = zip_vec.into_iter().unzip();

        let mut sum: i64 = 0;
        for &c in &cost {
            sum += c as i64;
        }
        let middle_cost = (sum + 1) / 2;
        let mut cur_sum: i64 = 0;
        let mut i = 0;
        let n = nums.len();

        while i < n {
            if (cost[i] as i64) + cur_sum >= middle_cost {
                break;
            }
            cur_sum += cost[i] as i64;
            i += 1;
        }

        Self::compute_manhattan_dis(&nums, &cost, nums[i])
    }

    #[allow(dead_code)]
    fn compute_manhattan_dis(v: &Vec<i32>, c: &Vec<i32>, e: i32) -> i64 {
        let mut ret = 0;
        let n = v.len();

        for i in 0..n {
            if v[i] == e {
                continue;
            }
            ret += ((v[i] - e).abs() as i64) * (c[i] as i64);
        }

        ret
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 中位数

我们还可以把 $b_i$ 看作是 $a_i$ 的出现次数，那么中位数下标是 $\frac{\sum_{i=1}^{n} b_i}{2}$。把所有数变成中位数，一定是最优的。

时间复杂度 $O(n\times \log n)$。其中 $n$ 为数组 `nums` 的长度。主要是排序的时间复杂度。

相似题目：

-   [296. 最佳的碰头地点](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0296.Best%20Meeting%20Point/README.md)
-   [462. 最少移动次数使数组元素相等 II](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0462.Minimum%20Moves%20to%20Equal%20Array%20Elements%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        arr = sorted(zip(nums, cost))
        mid = sum(cost) // 2
        s = 0
        for x, c in arr:
            s += c
            if s > mid:
                return sum(abs(v - x) * c for v, c in arr)
```

#### Java

```java
class Solution {
    public long minCost(int[] nums, int[] cost) {
        int n = nums.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {nums[i], cost[i]};
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        long mid = sum(cost) / 2;
        long s = 0, ans = 0;
        for (var e : arr) {
            int x = e[0], c = e[1];
            s += c;
            if (s > mid) {
                for (var t : arr) {
                    ans += (long) Math.abs(t[0] - x) * t[1];
                }
                break;
            }
        }
        return ans;
    }

    private long sum(int[] arr) {
        long s = 0;
        for (int v : arr) {
            s += v;
        }
        return s;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], cost[i]};
        sort(arr.begin(), arr.end());
        ll mid = accumulate(cost.begin(), cost.end(), 0ll) / 2;
        ll s = 0, ans = 0;
        for (auto [x, c] : arr) {
            s += c;
            if (s > mid) {
                for (auto [v, d] : arr) {
                    ans += 1ll * abs(v - x) * d;
                }
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minCost(nums []int, cost []int) int64 {
	n := len(nums)
	type pair struct{ a, b int }
	arr := make([]pair, n)
	mid := 0
	for i, a := range nums {
		b := cost[i]
		mid += b
		arr[i] = pair{a, b}
	}
	mid /= 2
	sort.Slice(arr, func(i, j int) bool { return arr[i].a < arr[j].a })
	s, ans := 0, 0
	for _, e := range arr {
		x, c := e.a, e.b
		s += c
		if s > mid {
			for _, t := range arr {
				ans += abs(t.a-x) * t.b
			}
			break
		}
	}
	return int64(ans)

}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2449. 使数组相似的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar){#2449}

{{< tabs "2449" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeSimilar(self, nums: List[int], target: List[int]) -> int:
        nums.sort(key=lambda x: (x & 1, x))
        target.sort(key=lambda x: (x & 1, x))
        return sum(abs(a - b) for a, b in zip(nums, target)) // 4
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long makeSimilar(int[] nums, int[] target) {
        Arrays.sort(nums);
        Arrays.sort(target);
        List<Integer> a1 = new ArrayList<>();
        List<Integer> a2 = new ArrayList<>();
        List<Integer> b1 = new ArrayList<>();
        List<Integer> b2 = new ArrayList<>();
        for (int v : nums) {
            if (v % 2 == 0) {
                a1.add(v);
            } else {
                a2.add(v);
            }
        }
        for (int v : target) {
            if (v % 2 == 0) {
                b1.add(v);
            } else {
                b2.add(v);
            }
        }
        long ans = 0;
        for (int i = 0; i < a1.size(); ++i) {
            ans += Math.abs(a1.get(i) - b1.get(i));
        }
        for (int i = 0; i < a2.size(); ++i) {
            ans += Math.abs(a2.get(i) - b2.get(i));
        }
        return ans / 4;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> a1;
        vector<int> a2;
        vector<int> b1;
        vector<int> b2;
        for (int v : nums) {
            if (v & 1)
                a1.emplace_back(v);
            else
                a2.emplace_back(v);
        }
        for (int v : target) {
            if (v & 1)
                b1.emplace_back(v);
            else
                b2.emplace_back(v);
        }
        long long ans = 0;
        for (int i = 0; i < a1.size(); ++i) ans += abs(a1[i] - b1[i]);
        for (int i = 0; i < a2.size(); ++i) ans += abs(a2[i] - b2[i]);
        return ans / 4;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeSimilar(nums []int, target []int) int64 {
	sort.Ints(nums)
	sort.Ints(target)
	a1, a2, b1, b2 := []int{}, []int{}, []int{}, []int{}
	for _, v := range nums {
		if v%2 == 0 {
			a1 = append(a1, v)
		} else {
			a2 = append(a2, v)
		}
	}
	for _, v := range target {
		if v%2 == 0 {
			b1 = append(b1, v)
		} else {
			b2 = append(b2, v)
		}
	}
	ans := 0
	for i := 0; i < len(a1); i++ {
		ans += abs(a1[i] - b1[i])
	}
	for i := 0; i < len(a2); i++ {
		ans += abs(a2[i] - b2[i])
	}
	return int64(ans / 4)
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
function makeSimilar(nums: number[], target: number[]): number {
    nums.sort((a, b) => a - b);
    target.sort((a, b) => a - b);

    const a1: number[] = [];
    const a2: number[] = [];
    const b1: number[] = [];
    const b2: number[] = [];

    for (const v of nums) {
        if (v % 2 === 0) {
            a1.push(v);
        } else {
            a2.push(v);
        }
    }

    for (const v of target) {
        if (v % 2 === 0) {
            b1.push(v);
        } else {
            b2.push(v);
        }
    }

    let ans = 0;
    for (let i = 0; i < a1.length; ++i) {
        ans += Math.abs(a1[i] - b1[i]);
    }

    for (let i = 0; i < a2.length; ++i) {
        ans += Math.abs(a2[i] - b2[i]);
    }

    return ans / 4;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数数组&nbsp;<code>nums</code> 和&nbsp;<code>target</code>&nbsp;，两个数组长度相等。</p>

<p>在一次操作中，你可以选择两个 <strong>不同</strong>&nbsp;的下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，其中&nbsp;<code>0 &lt;= i, j &lt; nums.length</code>&nbsp;，并且：</p>

<ul>
	<li>令&nbsp;<code>nums[i] = nums[i] + 2</code>&nbsp;且</li>
	<li>令&nbsp;<code>nums[j] = nums[j] - 2</code>&nbsp;。</li>
</ul>

<p>如果两个数组中每个元素出现的频率相等，我们称两个数组是 <strong>相似</strong>&nbsp;的。</p>

<p>请你返回将 <code>nums</code>&nbsp;变得与 <code>target</code>&nbsp;相似的最少操作次数。测试数据保证 <code>nums</code>&nbsp;一定能变得与 <code>target</code>&nbsp;相似。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [8,12,6], target = [2,14,10]
<b>输出：</b>2
<b>解释：</b>可以用两步操作将 nums 变得与 target 相似：
- 选择 i = 0 和 j = 2 ，nums = [10,12,4] 。
- 选择 i = 1 和 j = 2 ，nums = [10,14,2] 。
2 次操作是最少需要的操作次数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,5], target = [4,1,3]
<b>输出：</b>1
<b>解释：</b>一步操作可以使 nums 变得与 target 相似：
- 选择 i = 1 和 j = 2 ，nums = [1,4,3] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1,1,1], target = [1,1,1,1,1]
<b>输出：</b>0
<b>解释：</b>数组 nums 已经与 target 相似。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], target[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>nums</code>&nbsp;一定可以变得与&nbsp;<code>target</code> 相似。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：奇偶分类 + 排序

注意到，由于每次操作，元素的值只会增加 $2$ 或减少 $2$，因此，元素的奇偶性不会改变。

因此，我们可以将数组 $nums$ 和 $target$ 分别按奇偶性分为两组，分别记为 $a_1$ 和 $a_2$，以及 $b_1$ 和 $b_2$。

那么，我们只需要将 $a_1$ 中的元素与 $b_1$ 中的元素配对，将 $a_2$ 中的元素与 $b_2$ 中的元素配对，然后进行操作。配对的过程中，我们可以使用贪心的策略，每次将 $a_i$ 中较小的元素与 $b_i$ 中较小的元素配对，这样可以保证操作的次数最少。这里可以直接通过排序来实现。

由于每次操作，都可以将对应位置的元素差值减少 $4$，因此，我们累计每个对应位置的差值，最后除以 $4$ 即可得到答案。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeSimilar(self, nums: List[int], target: List[int]) -> int:
        nums.sort(key=lambda x: (x & 1, x))
        target.sort(key=lambda x: (x & 1, x))
        return sum(abs(a - b) for a, b in zip(nums, target)) // 4
```

#### Java

```java
class Solution {
    public long makeSimilar(int[] nums, int[] target) {
        Arrays.sort(nums);
        Arrays.sort(target);
        List<Integer> a1 = new ArrayList<>();
        List<Integer> a2 = new ArrayList<>();
        List<Integer> b1 = new ArrayList<>();
        List<Integer> b2 = new ArrayList<>();
        for (int v : nums) {
            if (v % 2 == 0) {
                a1.add(v);
            } else {
                a2.add(v);
            }
        }
        for (int v : target) {
            if (v % 2 == 0) {
                b1.add(v);
            } else {
                b2.add(v);
            }
        }
        long ans = 0;
        for (int i = 0; i < a1.size(); ++i) {
            ans += Math.abs(a1.get(i) - b1.get(i));
        }
        for (int i = 0; i < a2.size(); ++i) {
            ans += Math.abs(a2.get(i) - b2.get(i));
        }
        return ans / 4;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> a1;
        vector<int> a2;
        vector<int> b1;
        vector<int> b2;
        for (int v : nums) {
            if (v & 1)
                a1.emplace_back(v);
            else
                a2.emplace_back(v);
        }
        for (int v : target) {
            if (v & 1)
                b1.emplace_back(v);
            else
                b2.emplace_back(v);
        }
        long long ans = 0;
        for (int i = 0; i < a1.size(); ++i) ans += abs(a1[i] - b1[i]);
        for (int i = 0; i < a2.size(); ++i) ans += abs(a2[i] - b2[i]);
        return ans / 4;
    }
};
```

#### Go

```go
func makeSimilar(nums []int, target []int) int64 {
	sort.Ints(nums)
	sort.Ints(target)
	a1, a2, b1, b2 := []int{}, []int{}, []int{}, []int{}
	for _, v := range nums {
		if v%2 == 0 {
			a1 = append(a1, v)
		} else {
			a2 = append(a2, v)
		}
	}
	for _, v := range target {
		if v%2 == 0 {
			b1 = append(b1, v)
		} else {
			b2 = append(b2, v)
		}
	}
	ans := 0
	for i := 0; i < len(a1); i++ {
		ans += abs(a1[i] - b1[i])
	}
	for i := 0; i < len(a2); i++ {
		ans += abs(a2[i] - b2[i])
	}
	return int64(ans / 4)
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
function makeSimilar(nums: number[], target: number[]): number {
    nums.sort((a, b) => a - b);
    target.sort((a, b) => a - b);

    const a1: number[] = [];
    const a2: number[] = [];
    const b1: number[] = [];
    const b2: number[] = [];

    for (const v of nums) {
        if (v % 2 === 0) {
            a1.push(v);
        } else {
            a2.push(v);
        }
    }

    for (const v of target) {
        if (v % 2 === 0) {
            b1.push(v);
        } else {
            b2.push(v);
        }
    }

    let ans = 0;
    for (let i = 0; i < a1.length; ++i) {
        ans += Math.abs(a1[i] - b1[i]);
    }

    for (let i = 0; i < a2.length; ++i) {
        ans += Math.abs(a2[i] - b2[i]);
    }

    return ans / 4;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
