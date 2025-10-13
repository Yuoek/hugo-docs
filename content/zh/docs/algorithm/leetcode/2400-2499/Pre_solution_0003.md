---
title: "2420_找到所有好下标"
date: 2025-10-08T18:39:18+08:00
weight: 3
tags: [二分查找, 位运算, 分治, 前缀和, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 归并排序, 排序, 数学, 数组, 数论, 有序集合, 枚举, 树, 树状数组, 矩阵, 线段树, 脑筋急转弯, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2420_找到所有好下标](#2420)
#### [数组](#2420)
#### [动态规划](#2420)
#### [前缀和](#2420)
### [2421_好路径的数目](#2421)
#### [树](#2421)
#### [并查集](#2421)
#### [图](#2421)
#### [数组](#2421)
#### [哈希表](#2421)
#### [排序](#2421)
### [2422_使用合并操作将数组转换为回文序列 🔒](#2422)
#### [贪心](#2422)
#### [数组](#2422)
#### [双指针](#2422)
### [2423_删除字符使频率相同](#2423)
#### [哈希表](#2423)
#### [字符串](#2423)
#### [计数](#2423)
### [2424_最长上传前缀](#2424)
#### [并查集](#2424)
#### [设计](#2424)
#### [树状数组](#2424)
#### [线段树](#2424)
#### [哈希表](#2424)
#### [二分查找](#2424)
#### [有序集合](#2424)
#### [堆（优先队列）](#2424)
### [2425_所有数对的异或和](#2425)
#### [位运算](#2425)
#### [脑筋急转弯](#2425)
#### [数组](#2425)
### [2426_满足不等式的数对数目](#2426)
#### [树状数组](#2426)
#### [线段树](#2426)
#### [数组](#2426)
#### [二分查找](#2426)
#### [分治](#2426)
#### [有序集合](#2426)
#### [归并排序](#2426)
### [2427_公因子的数目](#2427)
#### [数学](#2427)
#### [枚举](#2427)
#### [数论](#2427)
### [2428_沙漏的最大总和](#2428)
#### [数组](#2428)
#### [矩阵](#2428)
#### [前缀和](#2428)
### [2429_最小异或](#2429)
#### [贪心](#2429)
#### [位运算](#2429)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2420_找到所有好下标
___
#### 数组
___
#### 动态规划
___
#### 前缀和
---
### 2421_好路径的数目
___
#### 树
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 2422_使用合并操作将数组转换为回文序列 🔒
___
#### 贪心
___
#### 数组
___
#### 双指针
---
### 2423_删除字符使频率相同
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2424_最长上传前缀
___
#### 并查集
___
#### 设计
___
#### 树状数组
___
#### 线段树
___
#### 哈希表
___
#### 二分查找
___
#### 有序集合
___
#### 堆（优先队列）
---
### 2425_所有数对的异或和
___
#### 位运算
___
#### 脑筋急转弯
___
#### 数组
---
### 2426_满足不等式的数对数目
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
---
### 2427_公因子的数目
___
#### 数学
___
#### 枚举
___
#### 数论
---
### 2428_沙漏的最大总和
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 2429_最小异或
___
#### 贪心
___
#### 位运算
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 前缀和 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 并查集 | 归并排序 |
| 排序 | 数学 | 数组 |
| 数论 | 有序集合 | 枚举 |
| 树 | 树状数组 | 矩阵 |
| 线段树 | 脑筋急转弯 | 计数 |
| 设计 | 贪心 |  |

# [2420. 找到所有好下标](https://leetcode.cn/problems/find-all-good-indices){#2420}

{{< tabs "2420" >}}

{{% tab "python" %}}
```python
class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        decr = [1] * (n + 1)
        incr = [1] * (n + 1)
        for i in range(2, n - 1):
            if nums[i - 1] <= nums[i - 2]:
                decr[i] = decr[i - 1] + 1
        for i in range(n - 3, -1, -1):
            if nums[i + 1] <= nums[i + 2]:
                incr[i] = incr[i + 1] + 1
        return [i for i in range(k, n - k) if decr[i] >= k and incr[i] >= k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> goodIndices(int[] nums, int k) {
        int n = nums.length;
        int[] decr = new int[n];
        int[] incr = new int[n];
        Arrays.fill(decr, 1);
        Arrays.fill(incr, 1);
        for (int i = 2; i < n - 1; ++i) {
            if (nums[i - 1] <= nums[i - 2]) {
                decr[i] = decr[i - 1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i + 1] <= nums[i + 2]) {
                incr[i] = incr[i + 1] + 1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = k; i < n - k; ++i) {
            if (decr[i] >= k && incr[i] >= k) {
                ans.add(i);
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
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> decr(n, 1);
        vector<int> incr(n, 1);
        for (int i = 2; i < n; ++i) {
            if (nums[i - 1] <= nums[i - 2]) {
                decr[i] = decr[i - 1] + 1;
            }
        }
        for (int i = n - 3; ~i; --i) {
            if (nums[i + 1] <= nums[i + 2]) {
                incr[i] = incr[i + 1] + 1;
            }
        }
        vector<int> ans;
        for (int i = k; i < n - k; ++i) {
            if (decr[i] >= k && incr[i] >= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func goodIndices(nums []int, k int) []int {
	n := len(nums)
	decr := make([]int, n)
	incr := make([]int, n)
	for i := range decr {
		decr[i] = 1
		incr[i] = 1
	}
	for i := 2; i < n; i++ {
		if nums[i-1] <= nums[i-2] {
			decr[i] = decr[i-1] + 1
		}
	}
	for i := n - 3; i >= 0; i-- {
		if nums[i+1] <= nums[i+2] {
			incr[i] = incr[i+1] + 1
		}
	}
	ans := []int{}
	for i := k; i < n-k; i++ {
		if decr[i] >= k && incr[i] >= k {
			ans = append(ans, i)
		}
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

<p>给你一个大小为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>对于&nbsp;<code>k &lt;= i &lt; n - k</code>&nbsp;之间的一个下标&nbsp;<code>i</code>&nbsp;，如果它满足以下条件，我们就称它为一个&nbsp;<strong>好</strong>&nbsp;下标：</p>

<ul>
	<li>下标 <code>i</code> <strong>之前</strong> 的 <code>k</code>&nbsp;个元素是 <strong>非递增的</strong>&nbsp;。</li>
	<li>下标 <code>i</code> <strong>之后</strong>&nbsp;的 <code>k</code>&nbsp;个元素是 <strong>非递减的</strong>&nbsp;。</li>
</ul>

<p>按 <strong>升序</strong>&nbsp;返回所有好下标。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,1,1,3,4,1], k = 2
<b>输出：</b>[2,3]
<b>解释：</b>数组中有两个好下标：
- 下标 2 。子数组 [2,1] 是非递增的，子数组 [1,3] 是非递减的。
- 下标 3 。子数组 [1,1] 是非递增的，子数组 [3,4] 是非递减的。
注意，下标 4 不是好下标，因为 [4,1] 不是非递减的。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,1,2], k = 2
<b>输出：</b>[]
<b>解释：</b>数组中没有好下标。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n / 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

我们定义两个数组 `decr` 和 `incr`，分别表示从左到右和从右到左的非递增和非递减的最长子数组长度。

遍历数组，更新 `decr` 和 `incr` 数组。

然后顺序遍历下标 $i$（其中 $k\le i \lt n - k$），若 $decr[i] \geq k$ 并且 $incr[i] \geq k$，则 $i$ 为好下标。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        decr = [1] * (n + 1)
        incr = [1] * (n + 1)
        for i in range(2, n - 1):
            if nums[i - 1] <= nums[i - 2]:
                decr[i] = decr[i - 1] + 1
        for i in range(n - 3, -1, -1):
            if nums[i + 1] <= nums[i + 2]:
                incr[i] = incr[i + 1] + 1
        return [i for i in range(k, n - k) if decr[i] >= k and incr[i] >= k]
```

#### Java

```java
class Solution {
    public List<Integer> goodIndices(int[] nums, int k) {
        int n = nums.length;
        int[] decr = new int[n];
        int[] incr = new int[n];
        Arrays.fill(decr, 1);
        Arrays.fill(incr, 1);
        for (int i = 2; i < n - 1; ++i) {
            if (nums[i - 1] <= nums[i - 2]) {
                decr[i] = decr[i - 1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i + 1] <= nums[i + 2]) {
                incr[i] = incr[i + 1] + 1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = k; i < n - k; ++i) {
            if (decr[i] >= k && incr[i] >= k) {
                ans.add(i);
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
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> decr(n, 1);
        vector<int> incr(n, 1);
        for (int i = 2; i < n; ++i) {
            if (nums[i - 1] <= nums[i - 2]) {
                decr[i] = decr[i - 1] + 1;
            }
        }
        for (int i = n - 3; ~i; --i) {
            if (nums[i + 1] <= nums[i + 2]) {
                incr[i] = incr[i + 1] + 1;
            }
        }
        vector<int> ans;
        for (int i = k; i < n - k; ++i) {
            if (decr[i] >= k && incr[i] >= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func goodIndices(nums []int, k int) []int {
	n := len(nums)
	decr := make([]int, n)
	incr := make([]int, n)
	for i := range decr {
		decr[i] = 1
		incr[i] = 1
	}
	for i := 2; i < n; i++ {
		if nums[i-1] <= nums[i-2] {
			decr[i] = decr[i-1] + 1
		}
	}
	for i := n - 3; i >= 0; i-- {
		if nums[i+1] <= nums[i+2] {
			incr[i] = incr[i+1] + 1
		}
	}
	ans := []int{}
	for i := k; i < n-k; i++ {
		if decr[i] >= k && incr[i] >= k {
			ans = append(ans, i)
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2421. 好路径的数目](https://leetcode.cn/problems/number-of-good-paths){#2421}

{{< tabs "2421" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)

        n = len(vals)
        p = list(range(n))
        size = defaultdict(Counter)
        for i, v in enumerate(vals):
            size[i][v] = 1

        ans = n
        for v, a in sorted(zip(vals, range(n))):
            for b in g[a]:
                if vals[b] > v:
                    continue
                pa, pb = find(a), find(b)
                if pa != pb:
                    ans += size[pa][v] * size[pb][v]
                    p[pa] = pb
                    size[pb][v] += size[pa][v]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length;
        p = new int[n];
        int[][] arr = new int[n][2];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        Map<Integer, Map<Integer, Integer>> size = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            arr[i] = new int[] {vals[i], i};
            size.computeIfAbsent(i, k -> new HashMap<>()).put(vals[i], 1);
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        int ans = n;
        for (var e : arr) {
            int v = e[0], a = e[1];
            for (int b : g[a]) {
                if (vals[b] > v) {
                    continue;
                }
                int pa = find(a), pb = find(b);
                if (pa != pb) {
                    ans += size.get(pa).getOrDefault(v, 0) * size.get(pb).getOrDefault(v, 0);
                    p[pa] = pb;
                    size.get(pb).put(
                        v, size.get(pb).getOrDefault(v, 0) + size.get(pa).getOrDefault(v, 0));
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find;
        find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        unordered_map<int, unordered_map<int, int>> size;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {vals[i], i};
            size[i][vals[i]] = 1;
        }
        sort(arr.begin(), arr.end());
        int ans = n;
        for (auto [v, a] : arr) {
            for (int b : g[a]) {
                if (vals[b] > v) {
                    continue;
                }
                int pa = find(a), pb = find(b);
                if (pa != pb) {
                    ans += size[pa][v] * size[pb][v];
                    p[pa] = pb;
                    size[pb][v] += size[pa][v];
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
func numberOfGoodPaths(vals []int, edges [][]int) int {
	n := len(vals)
	p := make([]int, n)
	size := map[int]map[int]int{}
	type pair struct{ v, i int }
	arr := make([]pair, n)
	for i, v := range vals {
		p[i] = i
		if size[i] == nil {
			size[i] = map[int]int{}
		}
		size[i][v] = 1
		arr[i] = pair{v, i}
	}

	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}

	sort.Slice(arr, func(i, j int) bool { return arr[i].v < arr[j].v })
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := n
	for _, e := range arr {
		v, a := e.v, e.i
		for _, b := range g[a] {
			if vals[b] > v {
				continue
			}
			pa, pb := find(a), find(b)
			if pa != pb {
				ans += size[pb][v] * size[pa][v]
				p[pa] = pb
				size[pb][v] += size[pa][v]
			}
		}
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

<p>给你一棵 <code>n</code>&nbsp;个节点的树（连通无向无环的图），节点编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;且恰好有&nbsp;<code>n - 1</code>&nbsp;条边。</p>

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>vals</code>&nbsp;，分别表示每个节点的值。同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code><sub>&nbsp;</sub>之间有一条&nbsp;<strong>无向</strong>&nbsp;边。</p>

<p>一条 <strong>好路径</strong>&nbsp;需要满足以下条件：</p>

<ol>
	<li>开始节点和结束节点的值 <strong>相同</strong>&nbsp;。</li>
	<li>开始节点和结束节点中间的所有节点值都 <strong>小于等于</strong>&nbsp;开始节点的值（也就是说开始节点的值应该是路径上所有节点的最大值）。</li>
</ol>

<p>请你返回不同好路径的数目。</p>

<p>注意，一条路径和它反向的路径算作 <strong>同一</strong>&nbsp;路径。比方说，&nbsp;<code>0 -&gt; 1</code>&nbsp;与&nbsp;<code>1 -&gt; 0</code>&nbsp;视为同一条路径。单个节点也视为一条合法路径。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2421.Number%20of%20Good%20Paths/images/f9caaac15b383af9115c5586779dec5.png" style="width: 400px; height: 333px;"></p>

<pre><b>输入：</b>vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
<b>输出：</b>6
<b>解释：</b>总共有 5 条单个节点的好路径。
还有 1 条好路径：1 -&gt; 0 -&gt; 2 -&gt; 4 。
（反方向的路径 4 -&gt; 2 -&gt; 0 -&gt; 1 视为跟 1 -&gt; 0 -&gt; 2 -&gt; 4 一样的路径）
注意 0 -&gt; 2 -&gt; 3 不是一条好路径，因为 vals[2] &gt; vals[0] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2421.Number%20of%20Good%20Paths/images/149d3065ec165a71a1b9aec890776ff.png" style="width: 273px; height: 350px;"></p>

<pre><b>输入：</b>vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
<b>输出：</b>7
<strong>解释：</strong>总共有 5 条单个节点的好路径。
还有 2 条好路径：0 -&gt; 1 和 2 -&gt; 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2421.Number%20of%20Good%20Paths/images/31705e22af3d9c0a557459bc7d1b62d.png" style="width: 100px; height: 88px;"></p>

<pre><b>输入：</b>vals = [1], edges = []
<b>输出：</b>1
<b>解释：</b>这棵树只有一个节点，所以只有一条好路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == vals.length</code></li>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= vals[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code>&nbsp;表示一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 并查集

要保证路径起点（终点）大于等于路径上的所有点，因此我们可以考虑先把所有点按值从小到大排序，然后再进行遍历，添加到连通块中，具体如下：

当遍历到点 $a$ 时， 对于小于等于 $vals[a]$ 的邻接点 $b$ 来说，若二者不在同一个连通块，则可以合并，并且可以以点 $a$ 所在的连通块中所有值为 $vals[a]$ 的点为起点，以点 $b$ 所在的连通块中所有值为 $vals[a]$ 的点为终点，两种点的个数的乘积即为加入点 $a$ 时对答案的贡献。

时间复杂度 $O(n \times \log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)

        n = len(vals)
        p = list(range(n))
        size = defaultdict(Counter)
        for i, v in enumerate(vals):
            size[i][v] = 1

        ans = n
        for v, a in sorted(zip(vals, range(n))):
            for b in g[a]:
                if vals[b] > v:
                    continue
                pa, pb = find(a), find(b)
                if pa != pb:
                    ans += size[pa][v] * size[pb][v]
                    p[pa] = pb
                    size[pb][v] += size[pa][v]
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length;
        p = new int[n];
        int[][] arr = new int[n][2];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        Map<Integer, Map<Integer, Integer>> size = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            arr[i] = new int[] {vals[i], i};
            size.computeIfAbsent(i, k -> new HashMap<>()).put(vals[i], 1);
        }
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        int ans = n;
        for (var e : arr) {
            int v = e[0], a = e[1];
            for (int b : g[a]) {
                if (vals[b] > v) {
                    continue;
                }
                int pa = find(a), pb = find(b);
                if (pa != pb) {
                    ans += size.get(pa).getOrDefault(v, 0) * size.get(pb).getOrDefault(v, 0);
                    p[pa] = pb;
                    size.get(pb).put(
                        v, size.get(pb).getOrDefault(v, 0) + size.get(pa).getOrDefault(v, 0));
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find;
        find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        unordered_map<int, unordered_map<int, int>> size;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {vals[i], i};
            size[i][vals[i]] = 1;
        }
        sort(arr.begin(), arr.end());
        int ans = n;
        for (auto [v, a] : arr) {
            for (int b : g[a]) {
                if (vals[b] > v) {
                    continue;
                }
                int pa = find(a), pb = find(b);
                if (pa != pb) {
                    ans += size[pa][v] * size[pb][v];
                    p[pa] = pb;
                    size[pb][v] += size[pa][v];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfGoodPaths(vals []int, edges [][]int) int {
	n := len(vals)
	p := make([]int, n)
	size := map[int]map[int]int{}
	type pair struct{ v, i int }
	arr := make([]pair, n)
	for i, v := range vals {
		p[i] = i
		if size[i] == nil {
			size[i] = map[int]int{}
		}
		size[i][v] = 1
		arr[i] = pair{v, i}
	}

	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}

	sort.Slice(arr, func(i, j int) bool { return arr[i].v < arr[j].v })
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := n
	for _, e := range arr {
		v, a := e.v, e.i
		for _, b := range g[a] {
			if vals[b] > v {
				continue
			}
			pa, pb := find(a), find(b)
			if pa != pb {
				ans += size[pb][v] * size[pa][v]
				p[pa] = pb
				size[pb][v] += size[pa][v]
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2422. 使用合并操作将数组转换为回文序列 🔒](https://leetcode.cn/problems/merge-operations-to-turn-array-into-a-palindrome){#2422}

{{< tabs "2422" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        i, j = 0, len(nums) - 1
        a, b = nums[i], nums[j]
        ans = 0
        while i < j:
            if a < b:
                i += 1
                a += nums[i]
                ans += 1
            elif b < a:
                j -= 1
                b += nums[j]
                ans += 1
            else:
                i, j = i + 1, j - 1
                a, b = nums[i], nums[j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperations(int[] nums) {
        int i = 0, j = nums.length - 1;
        long a = nums[i], b = nums[j];
        int ans = 0;
        while (i < j) {
            if (a < b) {
                a += nums[++i];
                ++ans;
            } else if (b < a) {
                b += nums[--j];
                ++ans;
            } else {
                a = nums[++i];
                b = nums[--j];
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
    int minimumOperations(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        long a = nums[i], b = nums[j];
        int ans = 0;
        while (i < j) {
            if (a < b) {
                a += nums[++i];
                ++ans;
            } else if (b < a) {
                b += nums[--j];
                ++ans;
            } else {
                a = nums[++i];
                b = nums[--j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int) int {
	i, j := 0, len(nums)-1
	a, b := nums[i], nums[j]
	ans := 0
	for i < j {
		if a < b {
			i++
			a += nums[i]
			ans++
		} else if b < a {
			j--
			b += nums[j]
			ans++
		} else {
			i, j = i+1, j-1
			a, b = nums[i], nums[j]
		}
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

<p>给定一个由&nbsp;<strong>正整数&nbsp;</strong>组成的数组 <code>nums</code>。</p>

<p>可以对阵列执行如下操作，<strong>次数不限</strong>:</p>

<ul>
	<li>选择任意两个&nbsp;<strong>相邻&nbsp;</strong>的元素并用它们的&nbsp;<strong>和</strong>&nbsp;<strong>替换&nbsp;</strong>它们。

    <ul>
    	<li>例如，如果 <code>nums = [1,<u>2,3</u>,1]</code>，则可以应用一个操作使其变为 <code>[1,5,1]</code>。</li>
    </ul>
    </li>

</ul>

<p>返回<em>将数组转换为&nbsp;<strong>回文序列&nbsp;</strong>所需的&nbsp;<strong>最小&nbsp;</strong>操作数。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,3,2,1,2,3,1]
<strong>输出:</strong> 2
<strong>解释:</strong> 我们可以通过以下 2 个操作将数组转换为回文:
- 在数组的第 4 和第 5 个元素上应用该操作，nums 将等于 [4,3,2,<strong><u>3</u></strong>,3,1].
- 在数组的第 5 和第 6 个元素上应用该操作，nums 将等于 [4,3,2,3,<strong><u>4</u></strong>].
数组 [4,3,2,3,4] 是一个回文序列。
可以证明，2 是所需的最小操作数。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4]
<strong>输出:</strong> 3
<strong>解释:</strong> 我们在任意位置进行 3 次运算，最后得到数组 [10]，它是一个回文序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

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

### 方法一：贪心 + 双指针

定义两个指针 $i$ 和 $j$，分别指向数组的首尾，用变量 $a$ 和 $b$ 分别表示首尾两个元素的值，变量 $ans$ 表示操作次数。

如果 $a \lt b$，我们将指针 $i$ 向右移动一位，即 $i \leftarrow i + 1$，然后将 $a$ 加上指针 $i$ 指向的元素的值，即 $a \leftarrow a + nums[i]$，同时将操作次数加一，即 $ans \leftarrow ans + 1$。

如果 $a \gt b$，我们将指针 $j$ 向左移动一位，即 $j \leftarrow j - 1$，然后将 $b$ 加上指针 $j$ 指向的元素的值，即 $b \leftarrow b + nums[j]$，同时将操作次数加一，即 $ans \leftarrow ans + 1$。

否则，说明 $a = b$，此时我们将指针 $i$ 向右移动一位，即 $i \leftarrow i + 1$，将指针 $j$ 向左移动一位，即 $j \leftarrow j - 1$，并且更新 $a$ 和 $b$ 的值，即 $a \leftarrow nums[i]$ 以及 $b \leftarrow nums[j]$。

循环上述过程，直至指针 $i \ge j$，返回操作次数 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        i, j = 0, len(nums) - 1
        a, b = nums[i], nums[j]
        ans = 0
        while i < j:
            if a < b:
                i += 1
                a += nums[i]
                ans += 1
            elif b < a:
                j -= 1
                b += nums[j]
                ans += 1
            else:
                i, j = i + 1, j - 1
                a, b = nums[i], nums[j]
        return ans
```

#### Java

```java
class Solution {
    public int minimumOperations(int[] nums) {
        int i = 0, j = nums.length - 1;
        long a = nums[i], b = nums[j];
        int ans = 0;
        while (i < j) {
            if (a < b) {
                a += nums[++i];
                ++ans;
            } else if (b < a) {
                b += nums[--j];
                ++ans;
            } else {
                a = nums[++i];
                b = nums[--j];
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
    int minimumOperations(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        long a = nums[i], b = nums[j];
        int ans = 0;
        while (i < j) {
            if (a < b) {
                a += nums[++i];
                ++ans;
            } else if (b < a) {
                b += nums[--j];
                ++ans;
            } else {
                a = nums[++i];
                b = nums[--j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumOperations(nums []int) int {
	i, j := 0, len(nums)-1
	a, b := nums[i], nums[j]
	ans := 0
	for i < j {
		if a < b {
			i++
			a += nums[i]
			ans++
		} else if b < a {
			j--
			b += nums[j]
			ans++
		} else {
			i, j = i+1, j-1
			a, b = nums[i], nums[j]
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2423. 删除字符使频率相同](https://leetcode.cn/problems/remove-letter-to-equalize-frequency){#2423}

{{< tabs "2423" >}}

{{% tab "python" %}}
```python
class Solution:
    def equalFrequency(self, word: str) -> bool:
        cnt = Counter(word)
        for c in cnt.keys():
            cnt[c] -= 1
            if len(set(v for v in cnt.values() if v)) == 1:
                return True
            cnt[c] += 1
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean equalFrequency(String word) {
        int[] cnt = new int[26];
        for (int i = 0; i < word.length(); ++i) {
            ++cnt[word.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                --cnt[i];
                int x = 0;
                boolean ok = true;
                for (int v : cnt) {
                    if (v == 0) {
                        continue;
                    }
                    if (x > 0 && v != x) {
                        ok = false;
                        break;
                    }
                    x = v;
                }
                if (ok) {
                    return true;
                }
                ++cnt[i];
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
    bool equalFrequency(string word) {
        int cnt[26]{};
        for (char& c : word) {
            ++cnt[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                --cnt[i];
                int x = 0;
                bool ok = true;
                for (int v : cnt) {
                    if (v == 0) {
                        continue;
                    }
                    if (x && v != x) {
                        ok = false;
                        break;
                    }
                    x = v;
                }
                if (ok) {
                    return true;
                }
                ++cnt[i];
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equalFrequency(word string) bool {
	cnt := [26]int{}
	for _, c := range word {
		cnt[c-'a']++
	}
	for i := range cnt {
		if cnt[i] > 0 {
			cnt[i]--
			x := 0
			ok := true
			for _, v := range cnt {
				if v == 0 {
					continue
				}
				if x > 0 && v != x {
					ok = false
					break
				}
				x = v
			}
			if ok {
				return true
			}
			cnt[i]++
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function equalFrequency(word: string): boolean {
    const cnt: number[] = new Array(26).fill(0);
    for (const c of word) {
        cnt[c.charCodeAt(0) - 97]++;
    }
    for (let i = 0; i < 26; ++i) {
        if (cnt[i]) {
            cnt[i]--;
            let x = 0;
            let ok = true;
            for (const v of cnt) {
                if (v === 0) {
                    continue;
                }
                if (x && v !== x) {
                    ok = false;
                    break;
                }
                x = v;
            }
            if (ok) {
                return true;
            }
            cnt[i]++;
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>word</code>&nbsp;，字符串只包含小写英文字母。你需要选择 <strong>一个</strong>&nbsp;下标并 <strong>删除</strong>&nbsp;下标处的字符，使得 <code>word</code>&nbsp;中剩余每个字母出现 <strong>频率</strong>&nbsp;相同。</p>

<p>如果删除一个字母后，<code>word</code>&nbsp;中剩余所有字母的出现频率都相同，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>字母&nbsp;<code>x</code>&nbsp;的 <strong>频率</strong><strong>&nbsp;</strong>是这个字母在字符串中出现的次数。</li>
	<li>你 <strong>必须</strong>&nbsp;恰好删除一个字母，不能一个字母都不删除。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>word = "abcc"
<b>输出：</b>true
<b>解释：</b>选择下标 3 并删除该字母：word 变成 "abc" 且每个字母出现频率都为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>word = "aazz"
<b>输出：</b>false
<b>解释：</b>我们必须删除一个字母，所以要么 "a" 的频率变为 1 且 "z" 的频率为 2 ，要么两个字母频率反过来。所以不可能让剩余所有字母出现频率相同。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们先用哈希表或者一个长度为 $26$ 的数组 $cnt$ 统计字符串中每个字母出现的次数。

接下来，枚举 $26$ 个字母，如果字母 $c$ 在字符串中出现过，我们将其出现次数减一，然后判断剩余的字母出现次数是否相同。如果相同，返回 `true`，否则将 $c$ 的出现次数加一，继续枚举下一个字母。

枚举结束，说明无法通过删除一个字母使得剩余字母出现次数相同，返回 `false`。

时间复杂度 $O(n + C^2)$，空间复杂度 $O(C)$，其中 $n$ 为字符串 $word$ 的长度，而 $C$ 为字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalFrequency(self, word: str) -> bool:
        cnt = Counter(word)
        for c in cnt.keys():
            cnt[c] -= 1
            if len(set(v for v in cnt.values() if v)) == 1:
                return True
            cnt[c] += 1
        return False
```

#### Java

```java
class Solution {
    public boolean equalFrequency(String word) {
        int[] cnt = new int[26];
        for (int i = 0; i < word.length(); ++i) {
            ++cnt[word.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                --cnt[i];
                int x = 0;
                boolean ok = true;
                for (int v : cnt) {
                    if (v == 0) {
                        continue;
                    }
                    if (x > 0 && v != x) {
                        ok = false;
                        break;
                    }
                    x = v;
                }
                if (ok) {
                    return true;
                }
                ++cnt[i];
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
    bool equalFrequency(string word) {
        int cnt[26]{};
        for (char& c : word) {
            ++cnt[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                --cnt[i];
                int x = 0;
                bool ok = true;
                for (int v : cnt) {
                    if (v == 0) {
                        continue;
                    }
                    if (x && v != x) {
                        ok = false;
                        break;
                    }
                    x = v;
                }
                if (ok) {
                    return true;
                }
                ++cnt[i];
            }
        }
        return false;
    }
};
```

#### Go

```go
func equalFrequency(word string) bool {
	cnt := [26]int{}
	for _, c := range word {
		cnt[c-'a']++
	}
	for i := range cnt {
		if cnt[i] > 0 {
			cnt[i]--
			x := 0
			ok := true
			for _, v := range cnt {
				if v == 0 {
					continue
				}
				if x > 0 && v != x {
					ok = false
					break
				}
				x = v
			}
			if ok {
				return true
			}
			cnt[i]++
		}
	}
	return false
}
```

#### TypeScript

```ts
function equalFrequency(word: string): boolean {
    const cnt: number[] = new Array(26).fill(0);
    for (const c of word) {
        cnt[c.charCodeAt(0) - 97]++;
    }
    for (let i = 0; i < 26; ++i) {
        if (cnt[i]) {
            cnt[i]--;
            let x = 0;
            let ok = true;
            for (const v of cnt) {
                if (v === 0) {
                    continue;
                }
                if (x && v !== x) {
                    ok = false;
                    break;
                }
                x = v;
            }
            if (ok) {
                return true;
            }
            cnt[i]++;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2424. 最长上传前缀](https://leetcode.cn/problems/longest-uploaded-prefix){#2424}

{{< tabs "2424" >}}

{{% tab "python" %}}
```python
class LUPrefix:
    def __init__(self, n: int):
        self.r = 0
        self.s = set()

    def upload(self, video: int) -> None:
        self.s.add(video)
        while self.r + 1 in self.s:
            self.r += 1

    def longest(self) -> int:
        return self.r


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class LUPrefix {
    private int r;
    private Set<Integer> s = new HashSet<>();

    public LUPrefix(int n) {
    }

    public void upload(int video) {
        s.add(video);
        while (s.contains(r + 1)) {
            ++r;
        }
    }

    public int longest() {
        return r;
    }
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix obj = new LUPrefix(n);
 * obj.upload(video);
 * int param_2 = obj.longest();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class LUPrefix {
public:
    LUPrefix(int n) {
    }

    void upload(int video) {
        s.insert(video);
        while (s.count(r + 1)) {
            ++r;
        }
    }

    int longest() {
        return r;
    }

private:
    int r = 0;
    unordered_set<int> s;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type LUPrefix struct {
	r int
	s []bool
}

func Constructor(n int) LUPrefix {
	return LUPrefix{0, make([]bool, n+1)}
}

func (this *LUPrefix) Upload(video int) {
	this.s[video] = true
	for this.r+1 < len(this.s) && this.s[this.r+1] {
		this.r++
	}
}

func (this *LUPrefix) Longest() int {
	return this.r
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * obj := Constructor(n);
 * obj.Upload(video);
 * param_2 := obj.Longest();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>n</code>&nbsp;个视频的上传序列，每个视频编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;之间的 <strong>不同</strong>&nbsp;数字，你需要依次将这些视频上传到服务器。请你实现一个数据结构，在上传的过程中计算 <strong>最长上传前缀</strong>&nbsp;。</p>

<p>如果&nbsp;<strong>闭区间</strong>&nbsp;<code>1</code>&nbsp;到&nbsp;<code>i</code>&nbsp;之间的视频全部都已经被上传到服务器，那么我们称 <code>i</code>&nbsp;是上传前缀。最长上传前缀指的是符合定义的 <code>i</code>&nbsp;中的 <strong>最大值</strong>&nbsp;。<br>
<br>
请你实现&nbsp;<code>LUPrefix</code>&nbsp;类：</p>

<ul>
	<li><code>LUPrefix(int n)</code>&nbsp;初始化一个 <code>n</code>&nbsp;个视频的流对象。</li>
	<li><code>void upload(int video)</code>&nbsp;上传&nbsp;<code>video</code>&nbsp;到服务器。</li>
	<li><code>int longest()</code>&nbsp;返回上述定义的 <strong>最长上传前缀</strong>&nbsp;的长度。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["LUPrefix", "upload", "longest", "upload", "longest", "upload", "longest"]
[[4], [3], [], [1], [], [2], []]
<strong>输出：</strong>
[null, null, 0, null, 1, null, 3]

<strong>解释：</strong>
LUPrefix server = new LUPrefix(4);   // 初始化 4个视频的上传流
server.upload(3);                    // 上传视频 3 。
server.longest();                    // 由于视频 1 还没有被上传，最长上传前缀是 0 。
server.upload(1);                    // 上传视频 1 。
server.longest();                    // 前缀 [1] 是最长上传前缀，所以我们返回 1 。
server.upload(2);                    // 上传视频 2 。
server.longest();                    // 前缀 [1,2,3] 是最长上传前缀，所以我们返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= video &lt;= 10<sup>5</sup></code></li>
	<li><code>video</code>&nbsp;中所有值 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>upload</code> 和&nbsp;<code>longest</code>&nbsp;<strong>总调用</strong> 次数至多不超过&nbsp;<code>2 * 10<sup>5</sup></code>&nbsp;次。</li>
	<li>至少会调用&nbsp;<code>longest</code>&nbsp;一次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用变量 $r$ 记录当前的最长上传前缀，用数组或哈希表 $s$ 记录已经上传的视频。

每次上传视频 `video` 时，将 `s[video]` 置为 `true`，然后循环判断 `s[r + 1]` 是否为 `true`，如果是，则更新 $r$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为视频总数。

<!-- tabs:start -->

#### Python3

```python
class LUPrefix:
    def __init__(self, n: int):
        self.r = 0
        self.s = set()

    def upload(self, video: int) -> None:
        self.s.add(video)
        while self.r + 1 in self.s:
            self.r += 1

    def longest(self) -> int:
        return self.r


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
```

#### Java

```java
class LUPrefix {
    private int r;
    private Set<Integer> s = new HashSet<>();

    public LUPrefix(int n) {
    }

    public void upload(int video) {
        s.add(video);
        while (s.contains(r + 1)) {
            ++r;
        }
    }

    public int longest() {
        return r;
    }
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix obj = new LUPrefix(n);
 * obj.upload(video);
 * int param_2 = obj.longest();
 */
```

#### C++

```cpp
class LUPrefix {
public:
    LUPrefix(int n) {
    }

    void upload(int video) {
        s.insert(video);
        while (s.count(r + 1)) {
            ++r;
        }
    }

    int longest() {
        return r;
    }

private:
    int r = 0;
    unordered_set<int> s;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
```

#### Go

```go
type LUPrefix struct {
	r int
	s []bool
}

func Constructor(n int) LUPrefix {
	return LUPrefix{0, make([]bool, n+1)}
}

func (this *LUPrefix) Upload(video int) {
	this.s[video] = true
	for this.r+1 < len(this.s) && this.s[this.r+1] {
		this.r++
	}
}

func (this *LUPrefix) Longest() int {
	return this.r
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * obj := Constructor(n);
 * obj.Upload(video);
 * param_2 := obj.Longest();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2425. 所有数对的异或和](https://leetcode.cn/problems/bitwise-xor-of-all-pairings){#2425}

{{< tabs "2425" >}}

{{% tab "python" %}}
```python
class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        if len(nums2) & 1:
            for v in nums1:
                ans ^= v
        if len(nums1) & 1:
            for v in nums2:
                ans ^= v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int ans = 0;
        if (nums2.length % 2 == 1) {
            for (int v : nums1) {
                ans ^= v;
            }
        }
        if (nums1.length % 2 == 1) {
            for (int v : nums2) {
                ans ^= v;
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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums2.size() % 2 == 1) {
            for (int v : nums1) {
                ans ^= v;
            }
        }
        if (nums1.size() % 2 == 1) {
            for (int v : nums2) {
                ans ^= v;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func xorAllNums(nums1 []int, nums2 []int) int {
	ans := 0
	if len(nums2)%2 == 1 {
		for _, v := range nums1 {
			ans ^= v
		}
	}
	if len(nums1)%2 == 1 {
		for _, v := range nums2 {
			ans ^= v
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function xorAllNums(nums1: number[], nums2: number[]): number {
    let ans = 0;
    if (nums2.length % 2 != 0) {
        ans ^= nums1.reduce((a, c) => a ^ c, 0);
    }
    if (nums1.length % 2 != 0) {
        ans ^= nums2.reduce((a, c) => a ^ c, 0);
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

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，两个数组都只包含非负整数。请你求出另外一个数组&nbsp;<code>nums3</code>&nbsp;，包含 <code>nums1</code>&nbsp;和 <code>nums2</code>&nbsp;中 <strong>所有数对</strong>&nbsp;的异或和（<code>nums1</code>&nbsp;中每个整数都跟 <code>nums2</code>&nbsp;中每个整数 <strong>恰好</strong>&nbsp;匹配一次）。</p>

<p>请你返回 <code>nums3</code>&nbsp;中所有整数的 <strong>异或和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [2,1,3], nums2 = [10,2,5,0]
<b>输出：</b>13
<strong>解释：</strong>
一个可能的 nums3 数组是 [8,0,7,2,11,3,4,1,9,1,6,3] 。
所有这些数字的异或和是 13 ，所以我们返回 13 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,2], nums2 = [3,4]
<b>输出：</b>0
<strong>解释：</strong>
所有数对异或和的结果分别为 nums1[0] ^ nums2[0] ，nums1[0] ^ nums2[1] ，nums1[1] ^ nums2[0] 和 nums1[1] ^ nums2[1] 。
所以，一个可能的 nums3 数组是 [2,5,1,6] 。
2 ^ 5 ^ 1 ^ 6 = 0 ，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯 + 位运算

由于数组的每个元素都会与另一个数组的每个元素进行异或，我们知道，同一个数异或两次，结果不变，即 $a \oplus a = 0$。因此，我们只需要统计数组的长度，就能知道每个元素与另一个数组的每个元素进行异或的次数。

如果 `nums2` 数组长度为奇数，那么相当于 `nums1` 中每个元素都与 `nums2` 中的每个元素进行了奇数次异或，因此 `nums1` 数组的最终异或结果即为 `nums1` 数组的所有元素异或的结果。如果为偶数，那么相当于 `nums1` 中每个元素都与 `nums2` 中的每个元素进行了偶数次异或，因此 `nums1` 数组的最终异或结果为 0。

同理，我们可以得知 `nums2` 数组的最终异或结果。

最终把两个异或结果再异或一次，即可得到最终结果。

时间复杂度 $O(m+n)$。其中 $m$ 和 $n$ 分别为数组 `nums1` 和 `nums2` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        if len(nums2) & 1:
            for v in nums1:
                ans ^= v
        if len(nums1) & 1:
            for v in nums2:
                ans ^= v
        return ans
```

#### Java

```java
class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int ans = 0;
        if (nums2.length % 2 == 1) {
            for (int v : nums1) {
                ans ^= v;
            }
        }
        if (nums1.length % 2 == 1) {
            for (int v : nums2) {
                ans ^= v;
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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums2.size() % 2 == 1) {
            for (int v : nums1) {
                ans ^= v;
            }
        }
        if (nums1.size() % 2 == 1) {
            for (int v : nums2) {
                ans ^= v;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func xorAllNums(nums1 []int, nums2 []int) int {
	ans := 0
	if len(nums2)%2 == 1 {
		for _, v := range nums1 {
			ans ^= v
		}
	}
	if len(nums1)%2 == 1 {
		for _, v := range nums2 {
			ans ^= v
		}
	}
	return ans
}
```

#### TypeScript

```ts
function xorAllNums(nums1: number[], nums2: number[]): number {
    let ans = 0;
    if (nums2.length % 2 != 0) {
        ans ^= nums1.reduce((a, c) => a ^ c, 0);
    }
    if (nums1.length % 2 != 0) {
        ans ^= nums2.reduce((a, c) => a ^ c, 0);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2426. 满足不等式的数对数目](https://leetcode.cn/problems/number-of-pairs-satisfying-inequality){#2426}

{{< tabs "2426" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff: int) -> int:
        tree = BinaryIndexedTree(10**5)
        ans = 0
        for a, b in zip(nums1, nums2):
            v = a - b
            ans += tree.query(v + diff + 40000)
            tree.update(v + 40000, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public static final int lowbit(int x) {
        return x & -x;
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }
}

class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        BinaryIndexedTree tree = new BinaryIndexedTree(100000);
        long ans = 0;
        for (int i = 0; i < nums1.length; ++i) {
            int v = nums1[i] - nums2[i];
            ans += tree.query(v + diff + 40000);
            tree.update(v + 40000, 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        BinaryIndexedTree* tree = new BinaryIndexedTree(1e5);
        long long ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int v = nums1[i] - nums2[i];
            ans += tree->query(v + diff + 40000);
            tree->update(v + 40000, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func numberOfPairs(nums1 []int, nums2 []int, diff int) int64 {
	tree := newBinaryIndexedTree(100000)
	ans := 0
	for i := range nums1 {
		v := nums1[i] - nums2[i]
		ans += tree.query(v + diff + 40000)
		tree.update(v+40000, 1)
	}
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，两个数组的大小都为&nbsp;<code>n</code>&nbsp;，同时给你一个整数&nbsp;<code>diff</code>&nbsp;，统计满足以下条件的&nbsp;<strong>数对&nbsp;</strong><code>(i, j)</code>&nbsp;：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt;= n - 1</code>&nbsp;<b>且</b></li>
	<li><code>nums1[i] - nums1[j] &lt;= nums2[i] - nums2[j] + diff</code>.</li>
</ul>

<p>请你返回满足条件的 <strong>数对数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
<b>输出：</b>3
<strong>解释：</strong>
总共有 3 个满足条件的数对：
1. i = 0, j = 1：3 - 2 &lt;= 2 - 2 + 1 。因为 i &lt; j 且 1 &lt;= 1 ，这个数对满足条件。
2. i = 0, j = 2：3 - 5 &lt;= 2 - 1 + 1 。因为 i &lt; j 且 -2 &lt;= 2 ，这个数对满足条件。
3. i = 1, j = 2：2 - 5 &lt;= 2 - 1 + 1 。因为 i &lt; j 且 -3 &lt;= 2 ，这个数对满足条件。
所以，我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [3,-1], nums2 = [-2,2], diff = -1
<b>输出：</b>0
<strong>解释：</strong>
没有满足条件的任何数对，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= diff &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

我们将题目的不等式转换一下，得到 $nums1[i] - nums2[i] \leq nums1[j] - nums2[j] + diff$，因此，如果我们对两个数组对应位置的元素求差值，得到另一个数组 $nums$，那么题目就转换为求 $nums$ 中满足 $nums[i] \leq nums[j] + diff$ 的数对数目。

我们可以从小到大枚举 $j$，找出前面有多少个数满足 $nums[i] \leq nums[j] + diff$，这样就可以求出数对数目。我们可以使用树状数组来维护前缀和，这样就可以在 $O(\log n)$ 的时间内求出前面有多少个数满足 $nums[i] \leq nums[j] + diff$。

时间复杂度 $O(n \times \log n)$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff: int) -> int:
        tree = BinaryIndexedTree(10**5)
        ans = 0
        for a, b in zip(nums1, nums2):
            v = a - b
            ans += tree.query(v + diff + 40000)
            tree.update(v + 40000, 1)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public static final int lowbit(int x) {
        return x & -x;
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }
}

class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        BinaryIndexedTree tree = new BinaryIndexedTree(100000);
        long ans = 0;
        for (int i = 0; i < nums1.length; ++i) {
            int v = nums1[i] - nums2[i];
            ans += tree.query(v + diff + 40000);
            tree.update(v + 40000, 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        BinaryIndexedTree* tree = new BinaryIndexedTree(1e5);
        long long ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int v = nums1[i] - nums2[i];
            ans += tree->query(v + diff + 40000);
            tree->update(v + 40000, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func numberOfPairs(nums1 []int, nums2 []int, diff int) int64 {
	tree := newBinaryIndexedTree(100000)
	ans := 0
	for i := range nums1 {
		v := nums1[i] - nums2[i]
		ans += tree.query(v + diff + 40000)
		tree.update(v+40000, 1)
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2427. 公因子的数目](https://leetcode.cn/problems/number-of-common-factors){#2427}

{{< tabs "2427" >}}

{{% tab "python" %}}
```python
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        g = gcd(a, b)
        ans, x = 0, 1
        while x * x <= g:
            if g % x == 0:
                ans += 1
                ans += x * x < g
            x += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ++ans;
                if (x * x < g) {
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
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ans++;
                ans += x * x < g;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func commonFactors(a int, b int) (ans int) {
	g := gcd(a, b)
	for x := 1; x*x <= g; x++ {
		if g%x == 0 {
			ans++
			if x*x < g {
				ans++
			}
		}
	}
	return
}

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function commonFactors(a: number, b: number): number {
    const g = gcd(a, b);
    let ans = 0;
    for (let x = 1; x * x <= g; ++x) {
        if (g % x === 0) {
            ++ans;
            if (x * x < g) {
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

<p>给你两个正整数 <code>a</code> 和 <code>b</code> ，返回 <code>a</code> 和 <code>b</code> 的 <strong>公</strong> 因子的数目。</p>

<p>如果 <code>x</code> 可以同时整除 <code>a</code> 和 <code>b</code> ，则认为 <code>x</code> 是 <code>a</code> 和 <code>b</code> 的一个 <strong>公因子</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = 12, b = 6
<strong>输出：</strong>4
<strong>解释：</strong>12 和 6 的公因子是 1、2、3、6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = 25, b = 30
<strong>输出：</strong>2
<strong>解释：</strong>25 和 30 的公因子是 1、5 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a, b &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以先算出 $a$ 和 $b$ 的最大公约数 $g$，然后枚举 $[1,..g]$ 中的每个数，判断其是否是 $g$ 的因子，如果是，则答案加一。

时间复杂度 $O(\min(a, b))$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        g = gcd(a, b)
        return sum(g % x == 0 for x in range(1, g + 1))
```

#### Java

```java
class Solution {
    public int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x <= g; ++x) {
            if (g % x == 0) {
                ++ans;
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
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x <= g; ++x) {
            ans += g % x == 0;
        }
        return ans;
    }
};
```

#### Go

```go
func commonFactors(a int, b int) (ans int) {
	g := gcd(a, b)
	for x := 1; x <= g; x++ {
		if g%x == 0 {
			ans++
		}
	}
	return
}

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function commonFactors(a: number, b: number): number {
    const g = gcd(a, b);
    let ans = 0;
    for (let x = 1; x <= g; ++x) {
        if (g % x === 0) {
            ++ans;
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

<!-- solution:start -->

### 方法二：枚举优化

与方法一类似，我们可以先算出 $a$ 和 $b$ 的最大公约数 $g$，然后枚举最大公约数 $g$ 的所有因子，累加答案。

时间复杂度 $O(\sqrt{\min(a, b)})$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        g = gcd(a, b)
        ans, x = 0, 1
        while x * x <= g:
            if g % x == 0:
                ans += 1
                ans += x * x < g
            x += 1
        return ans
```

#### Java

```java
class Solution {
    public int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ++ans;
                if (x * x < g) {
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
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int ans = 0;
        for (int x = 1; x * x <= g; ++x) {
            if (g % x == 0) {
                ans++;
                ans += x * x < g;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func commonFactors(a int, b int) (ans int) {
	g := gcd(a, b)
	for x := 1; x*x <= g; x++ {
		if g%x == 0 {
			ans++
			if x*x < g {
				ans++
			}
		}
	}
	return
}

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function commonFactors(a: number, b: number): number {
    const g = gcd(a, b);
    let ans = 0;
    for (let x = 1; x * x <= g; ++x) {
        if (g % x === 0) {
            ++ans;
            if (x * x < g) {
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

# [2428. 沙漏的最大总和](https://leetcode.cn/problems/maximum-sum-of-an-hourglass){#2428}

{{< tabs "2428" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(1, m - 1):
            for j in range(1, n - 1):
                s = -grid[i][j - 1] - grid[i][j + 1]
                s += sum(
                    grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2)
                )
                ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int s = -grid[i][j - 1] - grid[i][j + 1];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        s += grid[x][y];
                    }
                }
                ans = Math.max(ans, s);
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
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int s = -grid[i][j - 1] - grid[i][j + 1];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        s += grid[x][y];
                    }
                }
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSum(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	for i := 1; i < m-1; i++ {
		for j := 1; j < n-1; j++ {
			s := -grid[i][j-1] - grid[i][j+1]
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					s += grid[x][y]
				}
			}
			ans = max(ans, s)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSum(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let ans = 0;
    for (let i = 1; i < m - 1; ++i) {
        for (let j = 1; j < n - 1; ++j) {
            let s = -grid[i][j - 1] - grid[i][j + 1];
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    s += grid[x][y];
                }
            }
            ans = Math.max(ans, s);
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

<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code> 。</p>

<p>按以下形式将矩阵的一部分定义为一个 <strong>沙漏</strong> ：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2428.Maximum%20Sum%20of%20an%20Hourglass/images/img.jpg" style="width: 243px; height: 243px;">
<p>返回沙漏中元素的 <strong>最大</strong> 总和。</p>

<p><strong>注意：</strong>沙漏无法旋转且必须整个包含在矩阵中。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2428.Maximum%20Sum%20of%20an%20Hourglass/images/1.jpg" style="width: 323px; height: 323px;">
<pre><strong>输入：</strong>grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
<strong>输出：</strong>30
<strong>解释：</strong>上图中的单元格表示元素总和最大的沙漏：6 + 2 + 1 + 2 + 9 + 2 + 8 = 30 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2428.Maximum%20Sum%20of%20an%20Hourglass/images/2.jpg" style="width: 243px; height: 243px;">
<pre><strong>输入：</strong>grid = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>35
<strong>解释：</strong>上图中的单元格表示元素总和最大的沙漏：1 + 2 + 3 + 5 + 7 + 8 + 9 = 35 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>3 &lt;= m, n &lt;= 150</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们观察题目发现，每个沙漏就是一个 $3 \times 3$ 的矩阵挖去中间行的首尾两个元素。因此，我们可以从左上角开始，枚举每个沙漏的中间坐标 $(i, j)$，然后计算沙漏的元素和，取其中的最大值即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(1, m - 1):
            for j in range(1, n - 1):
                s = -grid[i][j - 1] - grid[i][j + 1]
                s += sum(
                    grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2)
                )
                ans = max(ans, s)
        return ans
```

#### Java

```java
class Solution {
    public int maxSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int s = -grid[i][j - 1] - grid[i][j + 1];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        s += grid[x][y];
                    }
                }
                ans = Math.max(ans, s);
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
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int s = -grid[i][j - 1] - grid[i][j + 1];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        s += grid[x][y];
                    }
                }
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSum(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	for i := 1; i < m-1; i++ {
		for j := 1; j < n-1; j++ {
			s := -grid[i][j-1] - grid[i][j+1]
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					s += grid[x][y]
				}
			}
			ans = max(ans, s)
		}
	}
	return
}
```

#### TypeScript

```ts
function maxSum(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let ans = 0;
    for (let i = 1; i < m - 1; ++i) {
        for (let j = 1; j < n - 1; ++j) {
            let s = -grid[i][j - 1] - grid[i][j + 1];
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    s += grid[x][y];
                }
            }
            ans = Math.max(ans, s);
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

# [2429. 最小异或](https://leetcode.cn/problems/minimize-xor){#2429}

{{< tabs "2429" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt1 = num1.bit_count()
        cnt2 = num2.bit_count()
        while cnt1 > cnt2:
            num1 &= num1 - 1
            cnt1 -= 1
        while cnt1 < cnt2:
            num1 |= num1 + 1
            cnt1 += 1
        return num1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt1 = Integer.bitCount(num1);
        int cnt2 = Integer.bitCount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeXor(num1 int, num2 int) int {
	cnt1 := bits.OnesCount(uint(num1))
	cnt2 := bits.OnesCount(uint(num2))
	for ; cnt1 > cnt2; cnt1-- {
		num1 &= (num1 - 1)
	}
	for ; cnt1 < cnt2; cnt1++ {
		num1 |= (num1 + 1)
	}
	return num1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizeXor(num1: number, num2: number): number {
    let cnt1 = bitCount(num1);
    let cnt2 = bitCount(num2);
    for (; cnt1 > cnt2; --cnt1) {
        num1 &= num1 - 1;
    }
    for (; cnt1 < cnt2; ++cnt1) {
        num1 |= num1 + 1;
    }
    return num1;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数 <code>num1</code> 和 <code>num2</code> ，找出满足下述条件的正整数 <code>x</code> ：</p>

<ul>
	<li><code>x</code> 的置位数和 <code>num2</code> 相同，且</li>
	<li><code>x XOR num1</code> 的值 <strong>最小</strong></li>
</ul>

<p>注意 <code>XOR</code> 是按位异或运算。</p>

<p>返回整数<em> </em><code>x</code> 。题目保证，对于生成的测试用例， <code>x</code> 是 <strong>唯一确定</strong> 的。</p>

<p>整数的 <strong>置位数</strong> 是其二进制表示中 <code>1</code> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 3, num2 = 5
<strong>输出：</strong>3
<strong>解释：</strong>
num1 和 num2 的二进制表示分别是 0011 和 0101 。
整数 <strong>3</strong> 的置位数与 num2 相同，且 <code>3 XOR 3 = 0</code> 是最小的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = 1, num2 = 12
<strong>输出：</strong>3
<strong>解释：</strong>
num1 和 num2 的二进制表示分别是 0001 和 1100 。
整数 <strong>3</strong> 的置位数与 num2 相同，且 <code>3 XOR 1 = 2</code> 是最小的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1, num2 &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 位运算

根据题目描述，我们先求出 $num2$ 的置位数 $cnt$，然后从高位到低位枚举 $num1$ 的每一位，如果该位为 $1$，则将 $x$ 的对应位设为 $1$，并将 $cnt$ 减 $1$，直到 $cnt$ 为 $0$。如果此时 $cnt$ 仍不为 $0$，则从低位开始将 $num1$ 的每一位为 $0$ 的位置设为 $1$，并将 $cnt$ 减 $1$，直到 $cnt$ 为 $0$。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为 $num1$ 和 $num2$ 的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt = num2.bit_count()
        x = 0
        for i in range(30, -1, -1):
            if num1 >> i & 1 and cnt:
                x |= 1 << i
                cnt -= 1
        for i in range(30):
            if num1 >> i & 1 ^ 1 and cnt:
                x |= 1 << i
                cnt -= 1
        return x
```

#### Java

```java
class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt = Integer.bitCount(num2);
        int x = 0;
        for (int i = 30; i >= 0 && cnt > 0; --i) {
            if ((num1 >> i & 1) == 1) {
                x |= 1 << i;
                --cnt;
            }
        }
        for (int i = 0; cnt > 0; ++i) {
            if ((num1 >> i & 1) == 0) {
                x |= 1 << i;
                --cnt;
            }
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int x = 0;
        for (int i = 30; ~i && cnt; --i) {
            if (num1 >> i & 1) {
                x |= 1 << i;
                --cnt;
            }
        }
        for (int i = 0; cnt; ++i) {
            if (num1 >> i & 1 ^ 1) {
                x |= 1 << i;
                --cnt;
            }
        }
        return x;
    }
};
```

#### Go

```go
func minimizeXor(num1 int, num2 int) int {
	cnt := bits.OnesCount(uint(num2))
	x := 0
	for i := 30; i >= 0 && cnt > 0; i-- {
		if num1>>i&1 == 1 {
			x |= 1 << i
			cnt--
		}
	}
	for i := 0; cnt > 0; i++ {
		if num1>>i&1 == 0 {
			x |= 1 << i
			cnt--
		}
	}
	return x
}
```

#### TypeScript

```ts
function minimizeXor(num1: number, num2: number): number {
    let cnt = 0;
    while (num2) {
        num2 &= num2 - 1;
        ++cnt;
    }
    let x = 0;
    for (let i = 30; i >= 0 && cnt > 0; --i) {
        if ((num1 >> i) & 1) {
            x |= 1 << i;
            --cnt;
        }
    }
    for (let i = 0; cnt > 0; ++i) {
        if (!((num1 >> i) & 1)) {
            x |= 1 << i;
            --cnt;
        }
    }
    return x;
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
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt1 = num1.bit_count()
        cnt2 = num2.bit_count()
        while cnt1 > cnt2:
            num1 &= num1 - 1
            cnt1 -= 1
        while cnt1 < cnt2:
            num1 |= num1 + 1
            cnt1 += 1
        return num1
```

#### Java

```java
class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt1 = Integer.bitCount(num1);
        int cnt2 = Integer.bitCount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        for (; cnt1 > cnt2; --cnt1) {
            num1 &= (num1 - 1);
        }
        for (; cnt1 < cnt2; ++cnt1) {
            num1 |= (num1 + 1);
        }
        return num1;
    }
};
```

#### Go

```go
func minimizeXor(num1 int, num2 int) int {
	cnt1 := bits.OnesCount(uint(num1))
	cnt2 := bits.OnesCount(uint(num2))
	for ; cnt1 > cnt2; cnt1-- {
		num1 &= (num1 - 1)
	}
	for ; cnt1 < cnt2; cnt1++ {
		num1 |= (num1 + 1)
	}
	return num1
}
```

#### TypeScript

```ts
function minimizeXor(num1: number, num2: number): number {
    let cnt1 = bitCount(num1);
    let cnt2 = bitCount(num2);
    for (; cnt1 > cnt2; --cnt1) {
        num1 &= num1 - 1;
    }
    for (; cnt1 < cnt2; ++cnt1) {
        num1 |= num1 + 1;
    }
    return num1;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
