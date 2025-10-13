---
title: "2790_长度递增组的最大数目"
date: 2025-10-08T18:39:33+08:00
weight: 10
tags: [JavaScript, 二分查找, 二叉树, 位运算, 分治, 动态规划, 哈希表, 排序, 数学, 数据库, 数组, 树, 深度优先搜索, 滑动窗口, 状态压缩, 贪心]
---

{{< markmap >}}
### [2790_长度递增组的最大数目](#2790)
#### [贪心](#2790)
#### [数组](#2790)
#### [数学](#2790)
#### [二分查找](#2790)
#### [排序](#2790)
### [2791_树中可以形成回文的路径数](#2791)
#### [位运算](#2791)
#### [树](#2791)
#### [深度优先搜索](#2791)
#### [动态规划](#2791)
#### [状态压缩](#2791)
### [2792_计算足够大的节点数 🔒](#2792)
#### [树](#2792)
#### [深度优先搜索](#2792)
#### [分治](#2792)
#### [二叉树](#2792)
### [2793_航班机票状态 🔒](#2793)
#### [数据库](#2793)
### [2794_从两个数组中创建对象 🔒](#2794)
#### [JavaScript](#2794)
### [2795_并行执行 Promise 以获取独有的结果 🔒](#2795)
#### [JavaScript](#2795)
### [2796_重复字符串 🔒](#2796)
#### [JavaScript](#2796)
### [2797_带有占位符的部分函数 🔒](#2797)
#### [JavaScript](#2797)
### [2798_满足目标工作时长的员工数目](#2798)
#### [数组](#2798)
### [2799_统计完全子数组的数目](#2799)
#### [数组](#2799)
#### [哈希表](#2799)
#### [滑动窗口](#2799)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2790_长度递增组的最大数目
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 排序
---
### 2791_树中可以形成回文的路径数
___
#### 位运算
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
___
#### 状态压缩
---
### 2792_计算足够大的节点数 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 分治
___
#### 二叉树
---
### 2793_航班机票状态 🔒
___
#### 数据库
---
### 2794_从两个数组中创建对象 🔒
___
#### JavaScript
---
### 2795_并行执行 Promise 以获取独有的结果 🔒
___
#### JavaScript
---
### 2796_重复字符串 🔒
___
#### JavaScript
---
### 2797_带有占位符的部分函数 🔒
___
#### JavaScript
---
### 2798_满足目标工作时长的员工数目
___
#### 数组
---
### 2799_统计完全子数组的数目
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 二叉树 |
| 位运算 | 分治 | 动态规划 |
| 哈希表 | 排序 | 数学 |
| 数据库 | 数组 | 树 |
| 深度优先搜索 | 滑动窗口 | 状态压缩 |
| 贪心 |  |  |

# [2790. 长度递增组的最大数目](https://leetcode.cn/problems/maximum-number-of-groups-with-increasing-length){#2790}

{{< tabs "2790" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxIncreasingGroups(self, usageLimits: List[int]) -> int:
        usageLimits.sort()
        k = s = 0
        for x in usageLimits:
            s += x
            if s > k:
                k += 1
                s -= k
        return k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxIncreasingGroups(List<Integer> usageLimits) {
        Collections.sort(usageLimits);
        int k = 0;
        long s = 0;
        for (int x : usageLimits) {
            s += x;
            if (s > k) {
                ++k;
                s -= k;
            }
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int k = 0;
        long long s = 0;
        for (int x : usageLimits) {
            s += x;
            if (s > k) {
                ++k;
                s -= k;
            }
        }
        return k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxIncreasingGroups(usageLimits []int) int {
	sort.Ints(usageLimits)
	s, k := 0, 0
	for _, x := range usageLimits {
		s += x
		if s > k {
			k++
			s -= k
		}
	}
	return k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxIncreasingGroups(usageLimits: number[]): number {
    usageLimits.sort((a, b) => a - b);
    let k = 0;
    let s = 0;
    for (const x of usageLimits) {
        s += x;
        if (s > k) {
            ++k;
            s -= k;
        }
    }
    return k;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的数组 <code>usageLimits</code> 。</p>

<p>你的任务是使用从 <code>0</code> 到 <code>n - 1</code> 的数字创建若干组，并确保每个数字 <code>i</code> 在 <strong>所有组</strong> 中使用的次数总共不超过 <code>usageLimits[i]</code> 次。此外，还必须满足以下条件：</p>

<ul>
	<li>每个组必须由 <strong>不同</strong> 的数字组成，也就是说，单个组内不能存在重复的数字。</li>
	<li>每个组（除了第一个）的长度必须 <strong>严格大于</strong> 前一个组。</li>
</ul>

<p>在满足所有条件的情况下，以整数形式返回可以创建的最大组数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>usageLimits</code> = [1,2,5]
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，我们可以使用 0 至多一次，使用 1 至多 2 次，使用 2 至多 5 次。
一种既能满足所有条件，又能创建最多组的方式是： 
组 1 包含数字 [2] 。
组 2 包含数字 [1,2] 。
组 3 包含数字 [0,1,2] 。 
可以证明能够创建的最大组数是 3 。 
所以，输出是 3 。 </pre>

<p><strong>示例 2：</strong></p>

<pre>
<code><strong>输入：</strong></code><code>usageLimits</code> = [2,1,2]
<strong>输出：</strong>2
<strong>解释：</strong>在这个示例中，我们可以使用 0 至多 2 次，使用 1 至多 1 次，使用 2 至多 2 次。
一种既能满足所有条件，又能创建最多组的方式是： 
组 1 包含数字 [0] 。 
组 2 包含数字 [1,2] 。
可以证明能够创建的最大组数是 2 。 
所以，输出是 2 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<code><strong>输入：</strong></code><code>usageLimits</code> = [1,1]
<strong>输出：</strong>1
<strong>解释：</strong>在这个示例中，我们可以使用 0 和 1 至多 1 次。 
一种既能满足所有条件，又能创建最多组的方式是：
组 1 包含数字 [0] 。
可以证明能够创建的最大组数是 1 。 
所以，输出是 1 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= usageLimits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= usageLimits[i] &lt;= 10<sup>9</sup></code></li>
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
class Solution:
    def maxIncreasingGroups(self, usageLimits: List[int]) -> int:
        usageLimits.sort()
        k, n = 0, len(usageLimits)
        for i in range(n):
            if usageLimits[i] > k:
                k += 1
                usageLimits[i] -= k
            if i + 1 < n:
                usageLimits[i + 1] += usageLimits[i]
        return k
```

#### Java

```java
class Solution {
    public int maxIncreasingGroups(List<Integer> usageLimits) {
        Collections.sort(usageLimits);
        int k = 0;
        long s = 0;
        for (int x : usageLimits) {
            s += x;
            if (s > k) {
                ++k;
                s -= k;
            }
        }
        return k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int k = 0;
        long long s = 0;
        for (int x : usageLimits) {
            s += x;
            if (s > k) {
                ++k;
                s -= k;
            }
        }
        return k;
    }
};
```

#### Go

```go
func maxIncreasingGroups(usageLimits []int) int {
	sort.Ints(usageLimits)
	s, k := 0, 0
	for _, x := range usageLimits {
		s += x
		if s > k {
			k++
			s -= k
		}
	}
	return k
}
```

#### TypeScript

```ts
function maxIncreasingGroups(usageLimits: number[]): number {
    usageLimits.sort((a, b) => a - b);
    let k = 0;
    let s = 0;
    for (const x of usageLimits) {
        s += x;
        if (s > k) {
            ++k;
            s -= k;
        }
    }
    return k;
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
    def maxIncreasingGroups(self, usageLimits: List[int]) -> int:
        usageLimits.sort()
        k = s = 0
        for x in usageLimits:
            s += x
            if s > k:
                k += 1
                s -= k
        return k
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2791. 树中可以形成回文的路径数](https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree){#2791}

{{< tabs "2791" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPalindromePaths(self, parent: List[int], s: str) -> int:
        def dfs(i: int, xor: int):
            nonlocal ans
            for j, v in g[i]:
                x = xor ^ v
                ans += cnt[x]
                for k in range(26):
                    ans += cnt[x ^ (1 << k)]
                cnt[x] += 1
                dfs(j, x)

        n = len(parent)
        g = defaultdict(list)
        for i in range(1, n):
            p = parent[i]
            g[p].append((i, 1 << (ord(s[i]) - ord('a'))))
        ans = 0
        cnt = Counter({0: 1})
        dfs(0, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<int[]>[] g;
    private Map<Integer, Integer> cnt = new HashMap<>();
    private long ans;

    public long countPalindromePaths(List<Integer> parent, String s) {
        int n = parent.size();
        g = new List[n];
        cnt.put(0, 1);
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            int p = parent.get(i);
            g[p].add(new int[] {i, 1 << (s.charAt(i) - 'a')});
        }
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int xor) {
        for (int[] e : g[i]) {
            int j = e[0], v = e[1];
            int x = xor ^ v;
            ans += cnt.getOrDefault(x, 0);
            for (int k = 0; k < 26; ++k) {
                ans += cnt.getOrDefault(x ^ (1 << k), 0);
            }
            cnt.merge(x, 1, Integer::sum);
            dfs(j, x);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<pair<int, int>>> g(n);
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 1; i < n; ++i) {
            int p = parent[i];
            g[p].emplace_back(i, 1 << (s[i] - 'a'));
        }
        long long ans = 0;
        function<void(int, int)> dfs = [&](int i, int xo) {
            for (auto [j, v] : g[i]) {
                int x = xo ^ v;
                ans += cnt[x];
                for (int k = 0; k < 26; ++k) {
                    ans += cnt[x ^ (1 << k)];
                }
                ++cnt[x];
                dfs(j, x);
            }
        };
        dfs(0, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPalindromePaths(parent []int, s string) (ans int64) {
	type pair struct{ i, v int }
	n := len(parent)
	g := make([][]pair, n)
	for i := 1; i < n; i++ {
		p := parent[i]
		g[p] = append(g[p], pair{i, 1 << (s[i] - 'a')})
	}
	cnt := map[int]int{0: 1}
	var dfs func(i, xor int)
	dfs = func(i, xor int) {
		for _, e := range g[i] {
			x := xor ^ e.v
			ans += int64(cnt[x])
			for k := 0; k < 26; k++ {
				ans += int64(cnt[x^(1<<k)])
			}
			cnt[x]++
			dfs(e.i, x)
		}
	}
	dfs(0, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPalindromePaths(parent: number[], s: string): number {
    const n = parent.length;
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (let i = 1; i < n; ++i) {
        g[parent[i]].push([i, 1 << (s.charCodeAt(i) - 97)]);
    }
    const cnt: Map<number, number> = new Map();
    cnt.set(0, 1);
    let ans = 0;
    const dfs = (i: number, xor: number): void => {
        for (const [j, v] of g[i]) {
            const x = xor ^ v;
            ans += cnt.get(x) || 0;
            for (let k = 0; k < 26; ++k) {
                ans += cnt.get(x ^ (1 << k)) || 0;
            }
            cnt.set(x, (cnt.get(x) || 0) + 1);
            dfs(j, x);
        }
    };
    dfs(0, 0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <strong>树</strong>（即，一个连通、无向且无环的图），<strong>根</strong> 节点为 <code>0</code> ，由编号从 <code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个节点组成。这棵树用一个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的数组 <code>parent</code> 表示，其中 <code>parent[i]</code> 为节点 <code>i</code> 的父节点，由于节点 <code>0</code> 为根节点，所以 <code>parent[0] == -1</code> 。</p>

<p>另给你一个长度为 <code>n</code> 的字符串 <code>s</code> ，其中 <code>s[i]</code> 是分配给 <code>i</code> 和 <code>parent[i]</code> 之间的边的字符。<code>s[0]</code> 可以忽略。</p>

<p>找出满足 <code>u &lt; v</code> ，且从 <code>u</code> 到 <code>v</code> 的路径上分配的字符可以 <strong>重新排列</strong> 形成 <strong>回文</strong> 的所有节点对&nbsp;<code>(u, v)</code> ，并返回节点对的数目。</p>

<p>如果一个字符串正着读和反着读都相同，那么这个字符串就是一个 <strong>回文</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2791.Count%20Paths%20That%20Can%20Form%20a%20Palindrome%20in%20a%20Tree/images/treedrawio-8drawio.png" style="width: 281px; height: 181px;" /></p>

<pre>
<strong>输入：</strong>parent = [-1,0,0,1,1,2], s = "acaabc"
<strong>输出：</strong>8
<strong>解释：</strong>符合题目要求的节点对分别是：
- (0,1)、(0,2)、(1,3)、(1,4) 和 (2,5) ，路径上只有一个字符，满足回文定义。
- (2,3)，路径上字符形成的字符串是 "aca" ，满足回文定义。
- (1,5)，路径上字符形成的字符串是 "cac" ，满足回文定义。
- (3,5)，路径上字符形成的字符串是 "acac" ，可以重排形成回文 "acca" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>parent = [-1,0,0,0,0], s = "aaaaa"
<strong>输出：</strong>10
<strong>解释：</strong>任何满足 u &lt; v 的节点对 (u,v) 都符合题目要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == parent.length == s.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li>对于所有 <code>i &gt;= 1</code> ，<code>0 &lt;= parent[i] &lt;= n - 1</code> 均成立</li>
	<li><code>parent[0] == -1</code></li>
	<li><code>parent</code> 表示一棵有效的树</li>
	<li><code>s</code> 仅由小写英文字母组成</li>
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
class Solution:
    def countPalindromePaths(self, parent: List[int], s: str) -> int:
        def dfs(i: int, xor: int):
            nonlocal ans
            for j, v in g[i]:
                x = xor ^ v
                ans += cnt[x]
                for k in range(26):
                    ans += cnt[x ^ (1 << k)]
                cnt[x] += 1
                dfs(j, x)

        n = len(parent)
        g = defaultdict(list)
        for i in range(1, n):
            p = parent[i]
            g[p].append((i, 1 << (ord(s[i]) - ord('a'))))
        ans = 0
        cnt = Counter({0: 1})
        dfs(0, 0)
        return ans
```

#### Java

```java
class Solution {
    private List<int[]>[] g;
    private Map<Integer, Integer> cnt = new HashMap<>();
    private long ans;

    public long countPalindromePaths(List<Integer> parent, String s) {
        int n = parent.size();
        g = new List[n];
        cnt.put(0, 1);
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            int p = parent.get(i);
            g[p].add(new int[] {i, 1 << (s.charAt(i) - 'a')});
        }
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int xor) {
        for (int[] e : g[i]) {
            int j = e[0], v = e[1];
            int x = xor ^ v;
            ans += cnt.getOrDefault(x, 0);
            for (int k = 0; k < 26; ++k) {
                ans += cnt.getOrDefault(x ^ (1 << k), 0);
            }
            cnt.merge(x, 1, Integer::sum);
            dfs(j, x);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<pair<int, int>>> g(n);
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 1; i < n; ++i) {
            int p = parent[i];
            g[p].emplace_back(i, 1 << (s[i] - 'a'));
        }
        long long ans = 0;
        function<void(int, int)> dfs = [&](int i, int xo) {
            for (auto [j, v] : g[i]) {
                int x = xo ^ v;
                ans += cnt[x];
                for (int k = 0; k < 26; ++k) {
                    ans += cnt[x ^ (1 << k)];
                }
                ++cnt[x];
                dfs(j, x);
            }
        };
        dfs(0, 0);
        return ans;
    }
};
```

#### Go

```go
func countPalindromePaths(parent []int, s string) (ans int64) {
	type pair struct{ i, v int }
	n := len(parent)
	g := make([][]pair, n)
	for i := 1; i < n; i++ {
		p := parent[i]
		g[p] = append(g[p], pair{i, 1 << (s[i] - 'a')})
	}
	cnt := map[int]int{0: 1}
	var dfs func(i, xor int)
	dfs = func(i, xor int) {
		for _, e := range g[i] {
			x := xor ^ e.v
			ans += int64(cnt[x])
			for k := 0; k < 26; k++ {
				ans += int64(cnt[x^(1<<k)])
			}
			cnt[x]++
			dfs(e.i, x)
		}
	}
	dfs(0, 0)
	return
}
```

#### TypeScript

```ts
function countPalindromePaths(parent: number[], s: string): number {
    const n = parent.length;
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (let i = 1; i < n; ++i) {
        g[parent[i]].push([i, 1 << (s.charCodeAt(i) - 97)]);
    }
    const cnt: Map<number, number> = new Map();
    cnt.set(0, 1);
    let ans = 0;
    const dfs = (i: number, xor: number): void => {
        for (const [j, v] of g[i]) {
            const x = xor ^ v;
            ans += cnt.get(x) || 0;
            for (let k = 0; k < 26; ++k) {
                ans += cnt.get(x ^ (1 << k)) || 0;
            }
            cnt.set(x, (cnt.get(x) || 0) + 1);
            dfs(j, x);
        }
    };
    dfs(0, 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2792. 计算足够大的节点数 🔒](https://leetcode.cn/problems/count-nodes-that-are-great-enough){#2792}

{{< tabs "2792" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countGreatEnoughNodes(self, root: Optional[TreeNode], k: int) -> int:
        def push(pq, x):
            heappush(pq, x)
            if len(pq) > k:
                heappop(pq)

        def dfs(root):
            if root is None:
                return []
            l, r = dfs(root.left), dfs(root.right)
            for x in r:
                push(l, x)
            if len(l) == k and -l[0] < root.val:
                nonlocal ans
                ans += 1
            push(l, -root.val)
            return l

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
    private int k;

    public int countGreatEnoughNodes(TreeNode root, int k) {
        this.k = k;
        dfs(root);
        return ans;
    }

    private PriorityQueue<Integer> dfs(TreeNode root) {
        if (root == null) {
            return new PriorityQueue<>(Comparator.reverseOrder());
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        for (int x : r) {
            l.offer(x);
            if (l.size() > k) {
                l.poll();
            }
        }
        if (l.size() == k && l.peek() < root.val) {
            ++ans;
        }
        l.offer(root.val);
        if (l.size() > k) {
            l.poll();
        }
        return l;
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
    int countGreatEnoughNodes(TreeNode* root, int k) {
        int ans = 0;
        function<priority_queue<int>(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return priority_queue<int>();
            }
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            while (right.size()) {
                left.push(right.top());
                right.pop();
                if (left.size() > k) {
                    left.pop();
                }
            }
            if (left.size() == k && left.top() < root->val) {
                ++ans;
            }
            left.push(root->val);
            if (left.size() > k) {
                left.pop();
            }
            return left;
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
func countGreatEnoughNodes(root *TreeNode, k int) (ans int) {
	var dfs func(*TreeNode) hp
	dfs = func(root *TreeNode) hp {
		if root == nil {
			return hp{}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		for _, x := range r.IntSlice {
			l.push(x)
			if l.Len() > k {
				l.pop()
			}
		}
		if l.Len() == k && root.Val > l.IntSlice[0] {
			ans++
		}
		l.push(root.Val)
		if l.Len() > k {
			l.pop()
		}
		return l
	}
	dfs(root)
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点 <code>root</code> 和一个整数 <code>k</code> 。如果一个节点满足以下条件，则称其为 <strong>足够大</strong>&nbsp;：</p>

<ul>
	<li>它的子树中 <strong>至少</strong> 有 <code>k</code> 个节点。</li>
	<li>它的值 <strong>大于</strong> 其子树中 <strong>至少</strong> <code>k</code> 个节点的值。</li>
</ul>

<p>返回足够大的节点数。</p>

<p>如果 <code>u == v</code> 或者 <code>v</code> 是 <code>u</code> 的祖先，则节点 <code>u</code> 在节点 <code>v</code> 的 <strong>子树</strong> 中。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>root = [7,6,5,4,3,2,1], k = 2
<b>输出：</b>3
<b>解释：</b>节点编号从 1 到 7。 
节点 1 的子树中的值：{1,2,3,4,5,6,7}。由于节点的值等于 7，有 6 个节点的值小于它的值，因此它是“足够大”的。 
节点 2 的子树中的值：{3,4,6}。由于节点的值等于 6，有 2 个节点的值小于它的值，因此它是“足够大”的。 
节点 3 的子树中的值：{1,2,5}。由于节点的值等于 5，有 2 个节点的值小于它的值，因此它是“足够大”的。 
其他节点不满足条件。 
参考下面的图片可以帮助你得到更好的理解。</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2792.Count%20Nodes%20That%20Are%20Great%20Enough/images/1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 300px; height: 167px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>root = [1,2,3], k = 1
<b>输出：</b>0
<strong>解释：</strong>节点编号从 1 到 3。 
节点 1 的子树中的值：{1,2,3}。由于节点的值等于 1，没有节点的值小于它的值，因此它不是“足够大”的。 
节点 2 的子树中的值：{2}。由于节点的值等于 2，没有节点的值小于它的值，因此它不是“足够大”的。 
节点 3 的子树中的值：{3}。由于节点的值等于 3，没有节点的值小于它的值，因此它不是“足够大”的。 
参考下面的图片可以帮助你得到更好的理解。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2792.Count%20Nodes%20That%20Are%20Great%20Enough/images/2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 123px; height: 101px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>root = [3,2,2], k = 2
<b>输出：</b>1
<strong>解释：</strong>节点编号从 1 到 3。 
节点 1 的子树中的值：{2,2,3}。
由于节点的值等于 3，有 2 个节点的值小于它的值，因此它是“足够大”的。 
节点 2 的子树中的值：{2}。由于节点的值等于 2，没有节点的值小于它的值，因此它不是“足够大”的。 
节点 3 的子树中的值：{2}。由于节点的值等于 2，没有节点的值小于它的值，因此它不是“足够大”的。 
参考下面的图片可以帮助你得到更好的理解。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2792.Count%20Nodes%20That%20Are%20Great%20Enough/images/3.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 123px; height: 101px;" /></p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在范围&nbsp;<code>[1, 10<sup>4</sup>]</code> 内。<span style="display: none;">&nbsp;</span></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 大根堆

我们可以使用 DFS 后序遍历整棵树，对于每个节点，我们维护一个大根堆，堆中存储该节点的所有子树中最小的 k 个节点的值，如果当前节点的值大于堆顶元素，那么该节点就是一个「足够大」的节点，我们将答案加一。

时间复杂度 $O(n \times k \times \log k)$，空间复杂度 $(n \times k)$。其中 $n$ 是树中节点的个数。

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
    def countGreatEnoughNodes(self, root: Optional[TreeNode], k: int) -> int:
        def push(pq, x):
            heappush(pq, x)
            if len(pq) > k:
                heappop(pq)

        def dfs(root):
            if root is None:
                return []
            l, r = dfs(root.left), dfs(root.right)
            for x in r:
                push(l, x)
            if len(l) == k and -l[0] < root.val:
                nonlocal ans
                ans += 1
            push(l, -root.val)
            return l

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
    private int k;

    public int countGreatEnoughNodes(TreeNode root, int k) {
        this.k = k;
        dfs(root);
        return ans;
    }

    private PriorityQueue<Integer> dfs(TreeNode root) {
        if (root == null) {
            return new PriorityQueue<>(Comparator.reverseOrder());
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        for (int x : r) {
            l.offer(x);
            if (l.size() > k) {
                l.poll();
            }
        }
        if (l.size() == k && l.peek() < root.val) {
            ++ans;
        }
        l.offer(root.val);
        if (l.size() > k) {
            l.poll();
        }
        return l;
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
    int countGreatEnoughNodes(TreeNode* root, int k) {
        int ans = 0;
        function<priority_queue<int>(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return priority_queue<int>();
            }
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            while (right.size()) {
                left.push(right.top());
                right.pop();
                if (left.size() > k) {
                    left.pop();
                }
            }
            if (left.size() == k && left.top() < root->val) {
                ++ans;
            }
            left.push(root->val);
            if (left.size() > k) {
                left.pop();
            }
            return left;
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
func countGreatEnoughNodes(root *TreeNode, k int) (ans int) {
	var dfs func(*TreeNode) hp
	dfs = func(root *TreeNode) hp {
		if root == nil {
			return hp{}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		for _, x := range r.IntSlice {
			l.push(x)
			if l.Len() > k {
				l.pop()
			}
		}
		if l.Len() == k && root.Val > l.IntSlice[0] {
			ans++
		}
		l.push(root.Val)
		if l.Len() > k {
			l.pop()
		}
		return l
	}
	dfs(root)
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2793. 航班机票状态 🔒](https://leetcode.cn/problems/status-of-flight-tickets){#2793}

{{< tabs "2793" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    passenger_id,
    IF(
        (
            RANK() OVER (
                PARTITION BY flight_id
                ORDER BY booking_time
            )
        ) <= capacity,
        'Confirmed',
        'Waitlist'
    ) AS Status
FROM
    Passengers
    JOIN Flights USING (flight_id)
ORDER BY passenger_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code><font face="monospace">Flights</font></code></p>

<pre>
+-------------+------+
| 列名        | 类型 |
+-------------+------+
| flight_id   | int  |
| capacity    | int  |
+-------------+------+
flight_id 列包含不同的值。
每行包含航班 id 和座位容量。
</pre>

<p>表：<code>Passengers</code></p>

<pre>
+--------------+----------+
| 列名         | 类型 |
+--------------+----------+
| passenger_id | int      |
| flight_id    | int      |
| booking_time | datetime |
+--------------+----------+
passenger_id 包含不同的值。
booking_time 包含不同的值。
每行包含乘客 id、预订时间和所预订的航班 id。
</pre>

<p>乘客提前预订航班机票。如果乘客预订了一张航班机票，并且航班上还有空座位，则乘客的机票将 <strong>得到确认</strong> 。然而，如果航班已经满员，乘客将被列入 <strong>等候名单</strong> 。</p>

<p>编写解决方案来确定每个乘客航班机票的当前状态。</p>

<p>按 <code>passenger_id</code> <strong>升序排序&nbsp;</strong>返回结果表。</p>

<p>查询结果的格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Flights 表:
+-----------+----------+
| flight_id | capacity |
+-----------+----------+
| 1         | 2        |
| 2         | 2        |
| 3         | 1        |
+-----------+----------+
Passengers 表:
+--------------+-----------+---------------------+
| passenger_id | flight_id | booking_time        |
+--------------+-----------+---------------------+
| 101          | 1         | 2023-07-10 16:30:00 |
| 102          | 1         | 2023-07-10 17:45:00 |
| 103          | 1         | 2023-07-10 12:00:00 |
| 104          | 2         | 2023-07-05 13:23:00 |
| 105          | 2         | 2023-07-05 09:00:00 |
| 106          | 3         | 2023-07-08 11:10:00 |
| 107          | 3         | 2023-07-08 09:10:00 |
+--------------+-----------+---------------------+
<b>输出：</b>
+--------------+-----------+
| passenger_id | Status    |
+--------------+-----------+
| 101          | Confirmed | 
| 102          | Waitlist  | 
| 103          | Confirmed | 
| 104          | Confirmed | 
| 105          | Confirmed | 
| 106          | Waitlist  | 
| 107          | Confirmed | 
+--------------+-----------+
<b>解释：</b>
- 航班 1 的容量为 2 位乘客。乘客 101 和乘客 103 是最先预订机票的，已经确认他们的预订。然而，乘客 102 是第三位预订该航班的乘客，这意味着没有更多的可用座位。乘客 102 现在被列入等候名单。
- 航班 2 的容量为 2 位乘客，已经有两位乘客预订了机票，乘客 104 和乘客 105。由于预订机票的乘客数与可用座位数相符，这两个预订都得到了确认。
- 航班 3 的容量为 1 位乘客，乘客 107 先预订并获得了唯一的可用座位，确认了他们的预订。预订时间在乘客 107 之后的乘客 106 被列入等候名单。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Rank() 窗口函数

注意，如果多个人在同一时间预定了同一个航班，只要有空位，就都可以确认预定。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    passenger_id,
    IF(
        (
            RANK() OVER (
                PARTITION BY flight_id
                ORDER BY booking_time
            )
        ) <= capacity,
        'Confirmed',
        'Waitlist'
    ) AS Status
FROM
    Passengers
    JOIN Flights USING (flight_id)
ORDER BY passenger_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2794. 从两个数组中创建对象 🔒](https://leetcode.cn/problems/create-object-from-two-arrays){#2794}

{{< tabs "2794" >}}

{{% tab "ts" %}}
```ts
function createObject(keysArr: any[], valuesArr: any[]): Record<string, any> {
    const ans: Record<string, any> = {};
    for (let i = 0; i < keysArr.length; ++i) {
        const k = String(keysArr[i]);
        if (ans[k] === undefined) {
            ans[k] = valuesArr[i];
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function (keysArr, valuesArr) {
    const ans = {};
    for (let i = 0; i < keysArr.length; ++i) {
        const k = keysArr[i] + '';
        if (ans[k] === undefined) {
            ans[k] = valuesArr[i];
        }
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

<p>给定两个数组 <code>keysArr </code>和 <code>valuesArr</code>，返回一个新的对象 <code>obj</code>。<code>obj</code> 中的每个键值对都来自 <code>keysArr[i]</code> 和 <code>valuesArr[i]</code>。</p>

<p>如果前面的索引中存在重复的键，则应该跳过该键值对。换句话说，只有第一次出现的键会被添加到对象中。</p>

<p>如果键不是字符串，则应通过调用 <code>String()</code> 方法将其转换为字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>keysArr = ["a", "b", "c"], valuesArr = [1, 2, 3]
<b>输出：</b>{"a": 1, "b": 2, "c": 3}
<b>解释：</b>键 "a"、"b" 和 "c" 分别与值 1、2 和 3 配对。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>keysArr = ["1", 1, false], valuesArr = [4, 5, 6]
<b>输出：</b>{"1": 4, "false": 6}
<b>解释：</b>首先，将 arr1 中的所有元素转换为字符串。我们可以看到有两个 "1" 的出现。使用第一次出现 "1" 的关联值：4。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>keysArr = [], valuesArr = []
<b>输出：</b>{}
<b>解释：</b>没有键，因此返回一个空对象。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>keysArr</code> 和 <code>valuesArr</code> 都是有效的 JSON 数组</li>
	<li><code>2 &lt;= JSON.stringify(keysArr).length,&nbsp;JSON.stringify(valuesArr).length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>keysArr.length === valuesArr.length</code></li>
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
function createObject(keysArr: any[], valuesArr: any[]): Record<string, any> {
    const ans: Record<string, any> = {};
    for (let i = 0; i < keysArr.length; ++i) {
        const k = String(keysArr[i]);
        if (ans[k] === undefined) {
            ans[k] = valuesArr[i];
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function (keysArr, valuesArr) {
    const ans = {};
    for (let i = 0; i < keysArr.length; ++i) {
        const k = keysArr[i] + '';
        if (ans[k] === undefined) {
            ans[k] = valuesArr[i];
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2795. 并行执行 Promise 以获取独有的结果 🔒](https://leetcode.cn/problems/parallel-execution-of-promises-for-individual-results-retrieval){#2795}

{{< tabs "2795" >}}

{{% tab "ts" %}}
```ts
type FulfilledObj = {
    status: 'fulfilled';
    value: string;
};
type RejectedObj = {
    status: 'rejected';
    reason: string;
};
type Obj = FulfilledObj | RejectedObj;

function promiseAllSettled(functions: Function[]): Promise<Obj[]> {
    return new Promise(resolve => {
        const res: Obj[] = [];
        let count = 0;
        for (let i in functions) {
            functions[i]()
                .then(value => ({ status: 'fulfilled', value }))
                .catch(reason => ({ status: 'rejected', reason }))
                .then(obj => {
                    res[i] = obj;
                    if (++count === functions.length) {
                        resolve(res);
                    }
                });
        }
    });
}

/**
 * const functions = [
 *    () => new Promise(resolve => setTimeout(() => resolve(15), 100))
 * ]
 * const time = performance.now()
 *
 * const promise = promiseAllSettled(functions);
 *
 * promise.then(res => {
 *     const out = {t: Math.floor(performance.now() - time), values: res}
 *     console.log(out) // {"t":100,"values":[{"status":"fulfilled","value":15}]}
 * })
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Array<Function>} functions
 * @return {Promise}
 */
var promiseAllSettled = function (functions) {
    return new Promise(resolve => {
        const res = [];
        let count = 0;
        for (let i in functions) {
            functions[i]()
                .then(value => ({ status: 'fulfilled', value }))
                .catch(reason => ({ status: 'rejected', reason }))
                .then(obj => {
                    res[i] = obj;
                    if (++count === functions.length) {
                        resolve(res);
                    }
                });
        }
    });
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组 <code>functions</code>，返回一个 promise 对象 <code>promise</code>。<code>functions</code> 是一个返回多个 promise&nbsp;对象 <code>fnPromise</code> 的函数数组。每个 <code>fnPromise</code> 可以被解析（resolved）或拒绝（rejected）。</p>

<p>如果 <code>fnPromise</code> 被解析：</p>

<p>&nbsp; &nbsp; <code>obj = { status: "fulfilled", value:&nbsp;<em>resolved value</em>}</code></p>

<p>如果 <code>fnPromise</code> 被拒绝：</p>

<p>&nbsp; &nbsp;&nbsp;<code>obj = { status: "rejected", reason: 拒绝的原因（捕获的错误消息）}</code></p>

<p>该 <code>promise</code> 应该返回一个包含这些对象 <code>obj</code> 的数组。数组中的每个 <code>obj</code> 应该对应原始函数数组中的多个 promise 对象，并保持相同的顺序。</p>

<p>请在不使用内置方法 <code>Promise.allSettled()</code> 的情况下实现它。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>functions = [
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(15), 100))
]
<strong>输出：</strong>{"t":100,"values":[{"status":"fulfilled","value":15}]}
<b>解释：</b>
const time = performance.now()
const promise = promiseAllSettled(functions);
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
promise.then(res =&gt; {
    const out = {t: Math.floor(performance.now() - time), values: res}
    console.log(out) // {"t":100,"values":[{"status":"fulfilled","value":15}]}
})

返回的 promise 在 100 毫秒内解析。由于函数数组中的 promise 被解析，返回的 promise 的解析值设置为[{"status":"fulfilled","value":15}]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>functions = [
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(20), 100)), 
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(15), 100))
]
<strong>输出：
</strong>{
    "t":100,
    "values": [
&nbsp;       {"status":"fulfilled","value":20},
&nbsp;       {"status":"fulfilled","value":15}
    ]
}
<b>解释：</b>返回的 promise 在 100 毫秒内解析，因为解析时间取决于需要最长时间来解析的 promise。由于函数数组中的 promises 被解析，返回的 promise 的解析值设置为[{"status":"fulfilled","value":20},{"status":"fulfilled","value":15}]。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>functions = [
&nbsp;   () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(30), 200)), 
&nbsp;   () =&gt; new Promise((resolve, reject) =&gt; setTimeout(() =&gt; reject("Error"), 100))
]
<strong>输出：</strong>
{
    "t":200,
    "values": [
        {"status":"fulfilled","value":30},
        {"status":"rejected","reason":"Error"}
    ]
}
<b>解释：</b>返回的 promise 在 200 毫秒内解析，因为解析时间取决于需要最长时间来解析的 promise。由于函数数组中的一个 promise 被解析，另一个被拒绝，返回的 promise 的解析值设置为[{"status":"fulfilled","value":30},{"status":"rejected","reason":"Error"}]。数组中的每个对象对应原始函数数组中的 promise，并保持相同的顺序。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= functions.length &lt;= 10</code></li>
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
type FulfilledObj = {
    status: 'fulfilled';
    value: string;
};
type RejectedObj = {
    status: 'rejected';
    reason: string;
};
type Obj = FulfilledObj | RejectedObj;

function promiseAllSettled(functions: Function[]): Promise<Obj[]> {
    return new Promise(resolve => {
        const res: Obj[] = [];
        let count = 0;
        for (let i in functions) {
            functions[i]()
                .then(value => ({ status: 'fulfilled', value }))
                .catch(reason => ({ status: 'rejected', reason }))
                .then(obj => {
                    res[i] = obj;
                    if (++count === functions.length) {
                        resolve(res);
                    }
                });
        }
    });
}

/**
 * const functions = [
 *    () => new Promise(resolve => setTimeout(() => resolve(15), 100))
 * ]
 * const time = performance.now()
 *
 * const promise = promiseAllSettled(functions);
 *
 * promise.then(res => {
 *     const out = {t: Math.floor(performance.now() - time), values: res}
 *     console.log(out) // {"t":100,"values":[{"status":"fulfilled","value":15}]}
 * })
 */
```

#### JavaScript

```js
/**
 * @param {Array<Function>} functions
 * @return {Promise}
 */
var promiseAllSettled = function (functions) {
    return new Promise(resolve => {
        const res = [];
        let count = 0;
        for (let i in functions) {
            functions[i]()
                .then(value => ({ status: 'fulfilled', value }))
                .catch(reason => ({ status: 'rejected', reason }))
                .then(obj => {
                    res[i] = obj;
                    if (++count === functions.length) {
                        resolve(res);
                    }
                });
        }
    });
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2796. 重复字符串 🔒](https://leetcode.cn/problems/repeat-string){#2796}

{{< tabs "2796" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface String {
        replicate(times: number): string;
    }
}

String.prototype.replicate = function (times: number) {
    return new Array(times).fill(this).join('');
};
```
{{% /tab %}}
{{% tab "js" %}}
```js
String.prototype.replicate = function (times) {
    return Array(times).fill(this).join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写代码实现字符串方法 <code>string.replicate(x)</code> ，它将返回重复的字符串 <code>x</code> 次。</p>

<p>请尝试在不使用内置方法 <code>string.repeat</code> 的情况下实现它。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>str = "hello", times = 2
<b>输出：</b>"hellohello"
<b>解释：</b>"hello" 被重复了 2 次
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>str = "code", times = 3
<b>输出：</b>codecodecode"
<b>解释：</b> "code" 被重复了 3 次
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>str = "js", times = 1
<b>输出：</b>"js"
<b>解释：</b>"js" 被重复了 1 次
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= times &lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>1 &lt;= str.length &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong>：为了简化分析，让我们假设连接字符串是一个常数时间操作 <code>O(1)</code>。考虑到这个假设，您能编写时间复杂度为 <code>O(log n)</code>&nbsp;的算法吗？</p>

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
declare global {
    interface String {
        replicate(times: number): string;
    }
}

String.prototype.replicate = function (times: number) {
    return new Array(times).fill(this).join('');
};
```

#### JavaScript

```js
String.prototype.replicate = function (times) {
    return Array(times).fill(this).join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2797. 带有占位符的部分函数 🔒](https://leetcode.cn/problems/partial-function-with-placeholders){#2797}

{{< tabs "2797" >}}

{{% tab "ts" %}}
```ts
function partial(fn: Function, args: any[]): Function {
    return function (...restArgs) {
        let i = 0;
        for (let j = 0; j < args.length; ++j) {
            if (args[j] === '_') {
                args[j] = restArgs[i++];
            }
        }
        while (i < restArgs.length) {
            args.push(restArgs[i++]);
        }
        return fn(...args);
    };
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Function} fn
 * @param {Array} args
 * @return {Function}
 */
var partial = function (fn, args) {
    return function (...restArgs) {
        let i = 0;
        for (let j = 0; j < args.length; ++j) {
            if (args[j] === '_') {
                args[j] = restArgs[i++];
            }
        }
        while (i < restArgs.length) {
            args.push(restArgs[i++]);
        }
        return fn.apply(this, args);
    };
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定函数 <code>fn</code> 和数组 <code>args</code>，返回一个函数 <code>partialFn</code>。</p>

<p><code>args</code> 中的占位符 <code>"_"</code> 需要用&nbsp;<code>restArgs</code> 中索引从&nbsp;<code>0</code> 开始的值替换。 <code>restArgs</code> 中剩余的值则添加到 <code>args</code> 的末尾。</p>

<p><code>partialFn</code> 应该返回 <code>fn</code> 的结果。<code>fn</code> 应该使用修改后的 <code>args</code> 的元素作为单独的参数调用。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>fn = (...args) =&gt; args, args = [2,4,6], restArgs = [8,10]
<strong>输出：</strong>[2,4,6,8,10]
<strong>解释：</strong>
const partialFn = partial(fn, args)
const result = partialFn(...restArgs) 
console.log(result) //&nbsp;[2,4,6,8,10]

args 中没有占位符 "_"，因此 restArgs 只是添加到 args 的末尾。然后将 args 的元素作为单独的参数传递给 fn，fn 返回传递的参数作为数组。
</pre>

<strong class="example">示例 2：</strong>

<pre>
<strong>输入：</strong>fn = (...args) =&gt; args, args = [1,2,"_",4,"_",6], restArgs = [3,5]
<strong>输出：</strong>[1,2,3,4,5,6]
<strong>解释：</strong>
const partialFn = partial(fn, args) 
const result = partialFn(...restArgs) 
console.log(result) //&nbsp;[1,2,3,4,5,6] 

占位符 "_" 被 restArgs 中的值替换。然后将 args 的元素作为单独的参数传递给 fn，fn 返回传递的参数作为数组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>fn = (a, b, c) =&gt; b + a - c, args = ["_", 5], restArgs = [5, 20]
<strong>输出：</strong>-10
<strong>解释：
</strong>const partialFn = partial(fn, args)
const result = partialFn(...restArgs)
console.log(result) //&nbsp;-10

占位符 "_" 被替换为 5，并将 20 添加到 args 的末尾。然后将 args 的元素作为单独的参数传递给 fn，fn 返回 -10（5 + 5 - 20）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>fn</code> 是一个函数</li>
	<li><code>args</code> 和 <code>restArgs</code> 都是有效的 JSON 数组</li>
	<li><code>1 &lt;= args.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;=&nbsp;restArgs.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= number of placeholders &lt;= restArgs.length</code></li>
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
function partial(fn: Function, args: any[]): Function {
    return function (...restArgs) {
        let i = 0;
        for (let j = 0; j < args.length; ++j) {
            if (args[j] === '_') {
                args[j] = restArgs[i++];
            }
        }
        while (i < restArgs.length) {
            args.push(restArgs[i++]);
        }
        return fn(...args);
    };
}
```

#### JavaScript

```js
/**
 * @param {Function} fn
 * @param {Array} args
 * @return {Function}
 */
var partial = function (fn, args) {
    return function (...restArgs) {
        let i = 0;
        for (let j = 0; j < args.length; ++j) {
            if (args[j] === '_') {
                args[j] = restArgs[i++];
            }
        }
        while (i < restArgs.length) {
            args.push(restArgs[i++]);
        }
        return fn.apply(this, args);
    };
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2798. 满足目标工作时长的员工数目](https://leetcode.cn/problems/number-of-employees-who-met-the-target){#2798}

{{< tabs "2798" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
        return sum(x >= target for x in hours)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int ans = 0;
        for (int x : hours) {
            if (x >= target) {
                ++ans;
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
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return count_if(hours.begin(), hours.end(), [target](int h) { return h >= target; });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfEmployeesWhoMetTarget(hours []int, target int) (ans int) {
	for _, x := range hours {
		if x >= target {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfEmployeesWhoMetTarget(hours: number[], target: number): number {
    return hours.filter(x => x >= target).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_employees_who_met_target(hours: Vec<i32>, target: i32) -> i32 {
        hours.iter().filter(|&x| *x >= target).count() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>公司里共有 <code>n</code> 名员工，按从 <code>0</code> 到 <code>n - 1</code> 编号。每个员工 <code>i</code> 已经在公司工作了 <code>hours[i]</code> 小时。</p>

<p>公司要求每位员工工作&nbsp;<strong>至少</strong> <code>target</code> 小时。</p>

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的非负整数数组 <code>hours</code> 和一个非负整数 <code>target</code> 。</p>

<p>请你用整数表示并返回工作至少 <code>target</code> 小时的员工数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>hours = [0,1,2,3,4], target = 2
<strong>输出：</strong>3
<strong>解释：</strong>公司要求每位员工工作至少 2 小时。
- 员工 0 工作 0 小时，不满足要求。
- 员工 1 工作 1 小时，不满足要求。
- 员工 2 工作 2 小时，满足要求。
- 员工 3 工作 3 小时，满足要求。
- 员工 4 工作 4 小时，满足要求。
共有 3 位满足要求的员工。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>hours = [5,1,4,2,2], target = 6
<strong>输出：</strong>0
<strong>解释：</strong>公司要求每位员工工作至少 6 小时。
共有 0 位满足要求的员工。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == hours.length &lt;= 50</code></li>
	<li><code>0 &lt;=&nbsp;hours[i], target &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们可以遍历数组 $hours$，对于每个员工，如果其工作时长 $x$ 大于等于 $target$，则将计数器 $ans$ 加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $hours$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
        return sum(x >= target for x in hours)
```

#### Java

```java
class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int ans = 0;
        for (int x : hours) {
            if (x >= target) {
                ++ans;
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
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return count_if(hours.begin(), hours.end(), [target](int h) { return h >= target; });
    }
};
```

#### Go

```go
func numberOfEmployeesWhoMetTarget(hours []int, target int) (ans int) {
	for _, x := range hours {
		if x >= target {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfEmployeesWhoMetTarget(hours: number[], target: number): number {
    return hours.filter(x => x >= target).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_employees_who_met_target(hours: Vec<i32>, target: i32) -> i32 {
        hours.iter().filter(|&x| *x >= target).count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2799. 统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array){#2799}

{{< tabs "2799" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        cnt = len(set(nums))
        d = Counter()
        ans, n = 0, len(nums)
        i = 0
        for j, x in enumerate(nums):
            d[x] += 1
            while len(d) == cnt:
                ans += n - j
                d[nums[i]] -= 1
                if d[nums[i]] == 0:
                    d.pop(nums[i])
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int x : nums) {
            d.put(x, 1);
        }
        int cnt = d.size();
        int ans = 0, n = nums.length;
        d.clear();
        for (int i = 0, j = 0; j < n; ++j) {
            d.merge(nums[j], 1, Integer::sum);
            while (d.size() == cnt) {
                ans += n - j;
                if (d.merge(nums[i], -1, Integer::sum) == 0) {
                    d.remove(nums[i]);
                }
                ++i;
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
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> d;
        for (int x : nums) {
            d[x] = 1;
        }
        int cnt = d.size();
        d.clear();
        int ans = 0, n = nums.size();
        for (int i = 0, j = 0; j < n; ++j) {
            d[nums[j]]++;
            while (d.size() == cnt) {
                ans += n - j;
                if (--d[nums[i]] == 0) {
                    d.erase(nums[i]);
                }
                ++i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCompleteSubarrays(nums []int) (ans int) {
	d := map[int]int{}
	for _, x := range nums {
		d[x] = 1
	}
	cnt := len(d)
	i, n := 0, len(nums)
	d = map[int]int{}
	for j, x := range nums {
		d[x]++
		for len(d) == cnt {
			ans += n - j
			d[nums[i]]--
			if d[nums[i]] == 0 {
				delete(d, nums[i])
			}
			i++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countCompleteSubarrays(nums: number[]): number {
    const d: Map<number, number> = new Map();
    for (const x of nums) {
        d.set(x, (d.get(x) ?? 0) + 1);
    }
    const cnt = d.size;
    d.clear();
    const n = nums.length;
    let ans = 0;
    let i = 0;
    for (let j = 0; j < n; ++j) {
        d.set(nums[j], (d.get(nums[j]) ?? 0) + 1);
        while (d.size === cnt) {
            ans += n - j;
            d.set(nums[i], d.get(nums[i])! - 1);
            if (d.get(nums[i]) === 0) {
                d.delete(nums[i]);
            }
            ++i;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let mut d = HashMap::new();
        for &x in &nums {
            d.insert(x, 1);
        }
        let cnt = d.len();
        let mut ans = 0;
        let n = nums.len();
        d.clear();

        let (mut i, mut j) = (0, 0);
        while j < n {
            *d.entry(nums[j]).or_insert(0) += 1;
            while d.len() == cnt {
                ans += (n - j) as i32;
                let e = d.get_mut(&nums[i]).unwrap();
                *e -= 1;
                if *e == 0 {
                    d.remove(&nums[i]);
                }
                i += 1;
            }
            j += 1;
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

<p>给你一个由 <strong>正</strong> 整数组成的数组 <code>nums</code> 。</p>

<p>如果数组中的某个子数组满足下述条件，则称之为 <strong>完全子数组</strong> ：</p>

<ul>
	<li>子数组中 <strong>不同</strong> 元素的数目等于整个数组不同元素的数目。</li>
</ul>

<p>返回数组中 <strong>完全子数组</strong> 的数目。</p>

<p><strong>子数组</strong> 是数组中的一个连续非空序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,1,2,2]
<strong>输出：</strong>4
<strong>解释：</strong>完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,5,5,5]
<strong>输出：</strong>10
<strong>解释：</strong>数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们先用哈希表统计数组中不同元素的数目，记为 $cnt$。

接下来，我们枚举子数组的左端点下标 $i$，并维护一个集合 $s$，用于存储子数组中的元素。每次向右移动右端点下标 $j$ 时，我们将 $nums[j]$ 加入集合 $s$ 中，并判断集合 $s$ 的大小是否等于 $cnt$。如果等于 $cnt$，则说明当前子数组是完全子数组，我们将答案增加 $1$。

枚举结束后，返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        cnt = len(set(nums))
        ans, n = 0, len(nums)
        for i in range(n):
            s = set()
            for x in nums[i:]:
                s.add(x)
                if len(s) == cnt:
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            s.add(x);
        }
        int cnt = s.size();
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            s.clear();
            for (int j = i; j < n; ++j) {
                s.add(nums[j]);
                if (s.size() == cnt) {
                    ++ans;
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
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int cnt = s.size();
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            s.clear();
            for (int j = i; j < n; ++j) {
                s.insert(nums[j]);
                if (s.size() == cnt) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countCompleteSubarrays(nums []int) (ans int) {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	cnt := len(s)
	for i := range nums {
		s = map[int]bool{}
		for _, x := range nums[i:] {
			s[x] = true
			if len(s) == cnt {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countCompleteSubarrays(nums: number[]): number {
    const s: Set<number> = new Set(nums);
    const cnt = s.size;
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        s.clear();
        for (let j = i; j < n; ++j) {
            s.add(nums[j]);
            if (s.size === cnt) {
                ++ans;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let mut s = HashSet::new();
        for &x in &nums {
            s.insert(x);
        }
        let cnt = s.len();
        let n = nums.len();
        let mut ans = 0;

        for i in 0..n {
            s.clear();
            for j in i..n {
                s.insert(nums[j]);
                if s.len() == cnt {
                    ans += 1;
                }
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 双指针

与方法一类似，我们可以使用哈希表统计数组中不同元素的数目，记为 $cnt$。

接下来，我们使用双指针维护一个滑动窗口，滑动窗口的右端点下标为 $j$，左端点下标为 $i$。

每次固定左端点下标 $i$，然后向右移动右端点下标 $j$，当滑动窗口中的元素种类数等于 $cnt$ 时，这意味着从左端点下标 $i$ 到右端点下标 $j$ 以及右侧的所有子数组都是完全子数组，我们将答案增加 $n - j$，其中 $n$ 是数组的长度。然后我们将左端点下标 $i$ 右移一位，继续上述过程。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        cnt = len(set(nums))
        d = Counter()
        ans, n = 0, len(nums)
        i = 0
        for j, x in enumerate(nums):
            d[x] += 1
            while len(d) == cnt:
                ans += n - j
                d[nums[i]] -= 1
                if d[nums[i]] == 0:
                    d.pop(nums[i])
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int x : nums) {
            d.put(x, 1);
        }
        int cnt = d.size();
        int ans = 0, n = nums.length;
        d.clear();
        for (int i = 0, j = 0; j < n; ++j) {
            d.merge(nums[j], 1, Integer::sum);
            while (d.size() == cnt) {
                ans += n - j;
                if (d.merge(nums[i], -1, Integer::sum) == 0) {
                    d.remove(nums[i]);
                }
                ++i;
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
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> d;
        for (int x : nums) {
            d[x] = 1;
        }
        int cnt = d.size();
        d.clear();
        int ans = 0, n = nums.size();
        for (int i = 0, j = 0; j < n; ++j) {
            d[nums[j]]++;
            while (d.size() == cnt) {
                ans += n - j;
                if (--d[nums[i]] == 0) {
                    d.erase(nums[i]);
                }
                ++i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countCompleteSubarrays(nums []int) (ans int) {
	d := map[int]int{}
	for _, x := range nums {
		d[x] = 1
	}
	cnt := len(d)
	i, n := 0, len(nums)
	d = map[int]int{}
	for j, x := range nums {
		d[x]++
		for len(d) == cnt {
			ans += n - j
			d[nums[i]]--
			if d[nums[i]] == 0 {
				delete(d, nums[i])
			}
			i++
		}
	}
	return
}
```

#### TypeScript

```ts
function countCompleteSubarrays(nums: number[]): number {
    const d: Map<number, number> = new Map();
    for (const x of nums) {
        d.set(x, (d.get(x) ?? 0) + 1);
    }
    const cnt = d.size;
    d.clear();
    const n = nums.length;
    let ans = 0;
    let i = 0;
    for (let j = 0; j < n; ++j) {
        d.set(nums[j], (d.get(nums[j]) ?? 0) + 1);
        while (d.size === cnt) {
            ans += n - j;
            d.set(nums[i], d.get(nums[i])! - 1);
            if (d.get(nums[i]) === 0) {
                d.delete(nums[i]);
            }
            ++i;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let mut d = HashMap::new();
        for &x in &nums {
            d.insert(x, 1);
        }
        let cnt = d.len();
        let mut ans = 0;
        let n = nums.len();
        d.clear();

        let (mut i, mut j) = (0, 0);
        while j < n {
            *d.entry(nums[j]).or_insert(0) += 1;
            while d.len() == cnt {
                ans += (n - j) as i32;
                let e = d.get_mut(&nums[i]).unwrap();
                *e -= 1;
                if *e == 0 {
                    d.remove(&nums[i]);
                }
                i += 1;
            }
            j += 1;
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
