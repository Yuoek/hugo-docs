---
title: "3160_所有球里面不同颜色的数目"
date: 2025-10-08T18:40:09+08:00
weight: 7
tags: [二分查找, 分治, 动态规划, 哈希表, 字符串, 排序, 数据库, 数组, 树状数组, 模拟, 线段树, 计数]
---

{{< markmap >}}
### [3160_所有球里面不同颜色的数目](#3160)
#### [数组](#3160)
#### [哈希表](#3160)
#### [模拟](#3160)
### [3161_物块放置查询](#3161)
#### [树状数组](#3161)
#### [线段树](#3161)
#### [数组](#3161)
#### [二分查找](#3161)
### [3162_优质数对的总数 I](#3162)
#### [数组](#3162)
#### [哈希表](#3162)
### [3163_压缩字符串 III](#3163)
#### [字符串](#3163)
### [3164_优质数对的总数 II](#3164)
#### [数组](#3164)
#### [哈希表](#3164)
### [3165_不包含相邻元素的子序列的最大和](#3165)
#### [线段树](#3165)
#### [数组](#3165)
#### [分治](#3165)
#### [动态规划](#3165)
### [3166_计算停车费与时长 🔒](#3166)
#### [数据库](#3166)
### [3167_字符串的更好压缩 🔒](#3167)
#### [哈希表](#3167)
#### [字符串](#3167)
#### [计数](#3167)
#### [排序](#3167)
### [3168_候诊室中的最少椅子数](#3168)
#### [字符串](#3168)
#### [模拟](#3168)
### [3169_无需开会的工作日](#3169)
#### [数组](#3169)
#### [排序](#3169)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3160_所有球里面不同颜色的数目
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 3161_物块放置查询
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
---
### 3162_优质数对的总数 I
___
#### 数组
___
#### 哈希表
---
### 3163_压缩字符串 III
___
#### 字符串
---
### 3164_优质数对的总数 II
___
#### 数组
___
#### 哈希表
---
### 3165_不包含相邻元素的子序列的最大和
___
#### 线段树
___
#### 数组
___
#### 分治
___
#### 动态规划
---
### 3166_计算停车费与时长 🔒
___
#### 数据库
---
### 3167_字符串的更好压缩 🔒
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
---
### 3168_候诊室中的最少椅子数
___
#### 字符串
___
#### 模拟
---
### 3169_无需开会的工作日
___
#### 数组
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 分治 | 动态规划 |
| 哈希表 | 字符串 | 排序 |
| 数据库 | 数组 | 树状数组 |
| 模拟 | 线段树 | 计数 |

# [3160. 所有球里面不同颜色的数目](https://leetcode.cn/problems/find-the-number-of-distinct-colors-among-the-balls){#3160}

{{< tabs "3160" >}}

{{% tab "python" %}}
```python
class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        g = {}
        cnt = Counter()
        ans = []
        for x, y in queries:
            cnt[y] += 1
            if x in g:
                cnt[g[x]] -= 1
                if cnt[g[x]] == 0:
                    cnt.pop(g[x])
            g[x] = y
            ans.append(len(cnt))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        Map<Integer, Integer> g = new HashMap<>();
        Map<Integer, Integer> cnt = new HashMap<>();
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int x = queries[i][0], y = queries[i][1];
            cnt.merge(y, 1, Integer::sum);
            if (g.containsKey(x) && cnt.merge(g.get(x), -1, Integer::sum) == 0) {
                cnt.remove(g.get(x));
            }
            g.put(x, y);
            ans[i] = cnt.size();
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
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> g;
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            cnt[y]++;
            if (g.contains(x) && --cnt[g[x]] == 0) {
                cnt.erase(g[x]);
            }
            g[x] = y;
            ans.push_back(cnt.size());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func queryResults(limit int, queries [][]int) (ans []int) {
	g := map[int]int{}
	cnt := map[int]int{}
	for _, q := range queries {
		x, y := q[0], q[1]
		cnt[y]++
		if v, ok := g[x]; ok {
			cnt[v]--
			if cnt[v] == 0 {
				delete(cnt, v)
			}
		}
		g[x] = y
		ans = append(ans, len(cnt))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function queryResults(limit: number, queries: number[][]): number[] {
    const g = new Map<number, number>();
    const cnt = new Map<number, number>();
    const ans: number[] = [];
    for (const [x, y] of queries) {
        cnt.set(y, (cnt.get(y) ?? 0) + 1);
        if (g.has(x)) {
            const v = g.get(x)!;
            cnt.set(v, cnt.get(v)! - 1);
            if (cnt.get(v) === 0) {
                cnt.delete(v);
            }
        }
        g.set(x, y);
        ans.push(cnt.size);
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

<p>给你一个整数&nbsp;<code>limit</code>&nbsp;和一个大小为 <code>n x 2</code>&nbsp;的二维数组&nbsp;<code>queries</code>&nbsp;。</p>

<p>总共有&nbsp;<code>limit + 1</code>&nbsp;个球，每个球的编号为&nbsp;<code>[0, limit]</code>&nbsp;中一个&nbsp;<strong>互不相同</strong>&nbsp;的数字。一开始，所有球都没有颜色。<code>queries</code>&nbsp;中每次操作的格式为&nbsp;<code>[x, y]</code>&nbsp;，你需要将球&nbsp;<code>x</code>&nbsp;染上颜色&nbsp;<code>y</code>&nbsp;。每次操作之后，你需要求出所有球颜色的数目。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的数组&nbsp;<code>result</code>&nbsp;，其中&nbsp;<code>result[i]</code>&nbsp;是第 <code>i</code>&nbsp;次操作以后颜色的数目。</p>

<p><strong>注意</strong>&nbsp;，没有染色的球不算作一种颜色。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]</span></p>

<p><span class="example-io"><b>输出：</b>[1,2,2,3]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3160.Find%20the%20Number%20of%20Distinct%20Colors%20Among%20the%20Balls/images/ezgifcom-crop.gif" style="width: 455px; height: 145px;" /></p>

<ul>
	<li>操作 0&nbsp;后，球 1 颜色为 4 。</li>
	<li>操作 1 后，球 1 颜色为&nbsp;4 ，球 2 颜色为 5 。</li>
	<li>操作 2 后，球 1 颜色为 3 ，球 2 颜色为 5 。</li>
	<li>操作 3 后，球 1 颜色为 3 ，球 2 颜色为 5 ，球 3 颜色为 4 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]</span></p>

<p><span class="example-io"><b>输出：</b>[1,2,2,3,4]</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3160.Find%20the%20Number%20of%20Distinct%20Colors%20Among%20the%20Balls/images/ezgifcom-crop2.gif" style="width: 457px; height: 144px;" /></strong></p>

<ul>
	<li>操作 0&nbsp;后，球 0&nbsp;颜色为 1&nbsp;。</li>
	<li>操作 1&nbsp;后，球 0&nbsp;颜色为 1 ，球 1 颜色为 2 。</li>
	<li>操作 2&nbsp;后，球 0&nbsp;颜色为 1 ，球 1 和 2&nbsp;颜色为 2 。</li>
	<li>操作 3 后，球 0&nbsp;颜色为 1 ，球 1 和 2&nbsp;颜色为 2 ，球 3 颜色为 4 。</li>
	<li>操作 4&nbsp;后，球 0&nbsp;颜色为 1 ，球 1 和 2&nbsp;颜色为 2 ，球 3 颜色为 4 ，球 4 颜色为 5 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= limit &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= n == queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= limit</code></li>
	<li><code>1 &lt;= queries[i][1] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双哈希表

我们使用一个哈希表 $\textit{g}$ 记录每个球的颜色，使用一个哈希表 $\textit{cnt}$ 记录每种颜色的球的个数。

接下来，遍历数组 $\textit{queries}$，对于每个查询 $(x, y)$，我们将颜色 $y$ 的球的个数加 $1$，然后判断球 $x$ 是否已经染色，如果已经染色，我们将球 $x$ 的颜色的球的个数减 $1$，如果减到 $0$，我们将其从哈希表 $\textit{cnt}$ 中移除。接下来，我们将球 $x$ 的颜色更新为 $y$，并将当前哈希表 $\textit{cnt}$ 的大小加入答案数组。

遍历结束后，返回答案数组即可。

时间复杂度 $O(m)$，空间复杂度 $O(m)$，其中 $m$ 为数组 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        g = {}
        cnt = Counter()
        ans = []
        for x, y in queries:
            cnt[y] += 1
            if x in g:
                cnt[g[x]] -= 1
                if cnt[g[x]] == 0:
                    cnt.pop(g[x])
            g[x] = y
            ans.append(len(cnt))
        return ans
```

#### Java

```java
class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        Map<Integer, Integer> g = new HashMap<>();
        Map<Integer, Integer> cnt = new HashMap<>();
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int x = queries[i][0], y = queries[i][1];
            cnt.merge(y, 1, Integer::sum);
            if (g.containsKey(x) && cnt.merge(g.get(x), -1, Integer::sum) == 0) {
                cnt.remove(g.get(x));
            }
            g.put(x, y);
            ans[i] = cnt.size();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> g;
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            cnt[y]++;
            if (g.contains(x) && --cnt[g[x]] == 0) {
                cnt.erase(g[x]);
            }
            g[x] = y;
            ans.push_back(cnt.size());
        }
        return ans;
    }
};
```

#### Go

```go
func queryResults(limit int, queries [][]int) (ans []int) {
	g := map[int]int{}
	cnt := map[int]int{}
	for _, q := range queries {
		x, y := q[0], q[1]
		cnt[y]++
		if v, ok := g[x]; ok {
			cnt[v]--
			if cnt[v] == 0 {
				delete(cnt, v)
			}
		}
		g[x] = y
		ans = append(ans, len(cnt))
	}
	return
}
```

#### TypeScript

```ts
function queryResults(limit: number, queries: number[][]): number[] {
    const g = new Map<number, number>();
    const cnt = new Map<number, number>();
    const ans: number[] = [];
    for (const [x, y] of queries) {
        cnt.set(y, (cnt.get(y) ?? 0) + 1);
        if (g.has(x)) {
            const v = g.get(x)!;
            cnt.set(v, cnt.get(v)! - 1);
            if (cnt.get(v) === 0) {
                cnt.delete(v);
            }
        }
        g.set(x, y);
        ans.push(cnt.size);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3161. 物块放置查询](https://leetcode.cn/problems/block-placement-queries){#3161}

{{< tabs "3161" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一条无限长的数轴，原点在 0 处，沿着 x 轴 <strong>正</strong>&nbsp;方向无限延伸。</p>

<p>给你一个二维数组&nbsp;<code>queries</code>&nbsp;，它包含两种操作：</p>

<ol>
	<li>操作类型 1 ：<code>queries[i] = [1, x]</code>&nbsp;。在距离原点 <code>x</code>&nbsp;处建一个障碍物。数据保证当操作执行的时候，位置 <code>x</code>&nbsp;处 <strong>没有</strong>&nbsp;任何障碍物。</li>
	<li>操作类型 2 ：<code>queries[i] = [2, x, sz]</code>&nbsp;。判断在数轴范围&nbsp;<code>[0, x]</code>&nbsp;内是否可以放置一个长度为&nbsp;<code>sz</code>&nbsp;的物块，这个物块需要&nbsp;<strong>完全</strong>&nbsp;放置在范围&nbsp;<code>[0, x]</code>&nbsp;内。如果物块与任何障碍物有重合，那么这个物块&nbsp;<strong>不能</strong>&nbsp;被放置，但物块可以与障碍物刚好接触。注意，你只是进行查询，并&nbsp;<strong>不是</strong>&nbsp;真的放置这个物块。每个查询都是相互独立的。</li>
</ol>

<p>请你返回一个 boolean 数组<code>results</code>&nbsp;，如果第&nbsp;<code>i</code> 个操作类型 2 的操作你可以放置物块，那么&nbsp;<code>results[i]</code>&nbsp;为&nbsp;<code>true</code>&nbsp;，否则为 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]</span></p>

<p><span class="example-io"><b>输出：</b>[false,true,true]</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3161.Block%20Placement%20Queries/images/example0block.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 309px; height: 129px;" /></strong></p>

<p>查询 0 ，在&nbsp;<code>x = 2</code>&nbsp;处放置一个障碍物。在&nbsp;<code>x = 3</code>&nbsp;之前任何大小不超过 2 的物块都可以被放置。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>queries = </span>[[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]<!-- notionvc: 4a471445-5af1-4d72-b11b-94d351a2c8e9 --></p>

<p><b>输出：</b>[true,true,false]</p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3161.Block%20Placement%20Queries/images/example1block.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 310px; height: 130px;" /></strong></p>

<ul>
	<li>查询 0 在&nbsp;<code>x = 7</code>&nbsp;处放置一个障碍物。在&nbsp;<code>x = 7</code>&nbsp;之前任何大小不超过 7 的物块都可以被放置。</li>
	<li>查询 2 在&nbsp;<code>x = 2</code>&nbsp;处放置一个障碍物。现在，在&nbsp;<code>x = 7</code>&nbsp;之前任何大小不超过 5 的物块可以被放置，<code>x = 2</code>&nbsp;之前任何大小不超过 2 的物块可以被放置。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 15 * 10<sup>4</sup></code></li>
	<li><code>2 &lt;= queries[i].length &lt;= 3</code></li>
	<li><code>1 &lt;= queries[i][0] &lt;= 2</code></li>
	<li><code>1 &lt;= x, sz &lt;= min(5 * 10<sup>4</sup>, 3 * queries.length)</code></li>
	<li>输入保证操作 1 中，<code>x</code>&nbsp;处不会有障碍物。</li>
	<li>输入保证至少有一个操作类型 2 。</li>
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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3162. 优质数对的总数 I](https://leetcode.cn/problems/find-the-number-of-good-pairs-i){#3162}

{{< tabs "3162" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cnt1 = Counter(x // k for x in nums1 if x % k == 0)
        if not cnt1:
            return 0
        cnt2 = Counter(nums2)
        ans = 0
        mx = max(cnt1)
        for x, v in cnt2.items():
            s = sum(cnt1[y] for y in range(x, mx + 1, x))
            ans += s * v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Integer, Integer> cnt1 = new HashMap<>();
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1.merge(x / k, 1, Integer::sum);
            }
        }
        if (cnt1.isEmpty()) {
            return 0;
        }
        Map<Integer, Integer> cnt2 = new HashMap<>();
        for (int x : nums2) {
            cnt2.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        int mx = Collections.max(cnt1.keySet());
        for (var e : cnt2.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            int s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1.getOrDefault(y, 0);
            }
            ans += s * v;
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
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> cnt1;
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1[x / k]++;
            }
        }
        if (cnt1.empty()) {
            return 0;
        }
        unordered_map<int, int> cnt2;
        for (int x : nums2) {
            ++cnt2[x];
        }
        int mx = 0;
        for (auto& [x, _] : cnt1) {
            mx = max(mx, x);
        }
        int ans = 0;
        for (auto& [x, v] : cnt2) {
            int s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1[y];
            }
            ans += s * v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPairs(nums1 []int, nums2 []int, k int) (ans int) {
	cnt1 := map[int]int{}
	for _, x := range nums1 {
		if x%k == 0 {
			cnt1[x/k]++
		}
	}
	if len(cnt1) == 0 {
		return 0
	}
	cnt2 := map[int]int{}
	for _, x := range nums2 {
		cnt2[x]++
	}
	mx := 0
	for x := range cnt1 {
		mx = max(mx, x)
	}
	for x, v := range cnt2 {
		s := 0
		for y := x; y <= mx; y += x {
			s += cnt1[y]
		}
		ans += s * v
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPairs(nums1: number[], nums2: number[], k: number): number {
    const cnt1: Map<number, number> = new Map();
    for (const x of nums1) {
        if (x % k === 0) {
            cnt1.set((x / k) | 0, (cnt1.get((x / k) | 0) || 0) + 1);
        }
    }
    if (cnt1.size === 0) {
        return 0;
    }
    const cnt2: Map<number, number> = new Map();
    for (const x of nums2) {
        cnt2.set(x, (cnt2.get(x) || 0) + 1);
    }
    const mx = Math.max(...cnt1.keys());
    let ans = 0;
    for (const [x, v] of cnt2) {
        let s = 0;
        for (let y = x; y <= mx; y += x) {
            s += cnt1.get(y) || 0;
        }
        ans += s * v;
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

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>，长度分别为 <code>n</code> 和 <code>m</code>。同时给你一个<strong>正整数</strong> <code>k</code>。</p>

<p>如果 <code>nums1[i]</code> 可以除尽&nbsp;<code>nums2[j] * k</code>，则称数对 <code>(i, j)</code> 为 <strong>优质数对</strong>（<code>0 &lt;= i &lt;= n - 1</code>, <code>0 &lt;= j &lt;= m - 1</code>）。</p>

<p>返回<strong> 优质数对 </strong>的总数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,3,4], nums2 = [1,3,4], k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>5个优质数对分别是 <code>(0, 0)</code>, <code>(1, 0)</code>, <code>(1, 1)</code>, <code>(2, 0)</code>, 和 <code>(2, 2)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,2,4,12], nums2 = [2,4], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>2个优质数对分别是 <code>(3, 0)</code> 和 <code>(3, 1)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 50</code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们直接枚举所有的数位 $(x, y)$，判断是否满足 $x \bmod (y \times k) = 0$，如果满足则答案加一。

枚举结束后，返回答案即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        return sum(x % (y * k) == 0 for x in nums1 for y in nums2)
```

#### Java

```java
class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        int ans = 0;
        for (int x : nums1) {
            for (int y : nums2) {
                if (x % (y * k) == 0) {
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
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int x : nums1) {
            for (int y : nums2) {
                if (x % (y * k) == 0) {
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
func numberOfPairs(nums1 []int, nums2 []int, k int) (ans int) {
	for _, x := range nums1 {
		for _, y := range nums2 {
			if x%(y*k) == 0 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfPairs(nums1: number[], nums2: number[], k: number): number {
    let ans = 0;
    for (const x of nums1) {
        for (const y of nums2) {
            if (x % (y * k) === 0) {
                ++ans;
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 枚举倍数

我们用一个哈希表 $\textit{cnt1}$ 记录数组 $\textit{nums1}$ 中每个数除以 $k$ 的商的出现次数，用一个哈希表 $\textit{cnt2}$ 记录数组 $\textit{nums2}$ 中每个数的出现次数。

接下来，我们枚举数组 $\textit{nums2}$ 中的每个数 $x$，对于每个数 $x$，我们枚举 $x$ 的倍数 $y$，其中 $y$ 的范围是 $[x, \textit{mx}]$，其中 $\textit{mx}$ 是 $\textit{cnt1}$ 中的最大键值，然后我们统计 $\textit{cnt1}[y]$ 的和，记为 $s$，最后我们将 $s \times v$ 累加到答案中，其中 $v$ 是 $\textit{cnt2}[x]$。

时间复杂度 $O(n + m + (M / k) \times \log m)$，空间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度，而 $M$ 是数组 $\textit{nums1}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cnt1 = Counter(x // k for x in nums1 if x % k == 0)
        if not cnt1:
            return 0
        cnt2 = Counter(nums2)
        ans = 0
        mx = max(cnt1)
        for x, v in cnt2.items():
            s = sum(cnt1[y] for y in range(x, mx + 1, x))
            ans += s * v
        return ans
```

#### Java

```java
class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Integer, Integer> cnt1 = new HashMap<>();
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1.merge(x / k, 1, Integer::sum);
            }
        }
        if (cnt1.isEmpty()) {
            return 0;
        }
        Map<Integer, Integer> cnt2 = new HashMap<>();
        for (int x : nums2) {
            cnt2.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        int mx = Collections.max(cnt1.keySet());
        for (var e : cnt2.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            int s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1.getOrDefault(y, 0);
            }
            ans += s * v;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> cnt1;
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1[x / k]++;
            }
        }
        if (cnt1.empty()) {
            return 0;
        }
        unordered_map<int, int> cnt2;
        for (int x : nums2) {
            ++cnt2[x];
        }
        int mx = 0;
        for (auto& [x, _] : cnt1) {
            mx = max(mx, x);
        }
        int ans = 0;
        for (auto& [x, v] : cnt2) {
            int s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1[y];
            }
            ans += s * v;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfPairs(nums1 []int, nums2 []int, k int) (ans int) {
	cnt1 := map[int]int{}
	for _, x := range nums1 {
		if x%k == 0 {
			cnt1[x/k]++
		}
	}
	if len(cnt1) == 0 {
		return 0
	}
	cnt2 := map[int]int{}
	for _, x := range nums2 {
		cnt2[x]++
	}
	mx := 0
	for x := range cnt1 {
		mx = max(mx, x)
	}
	for x, v := range cnt2 {
		s := 0
		for y := x; y <= mx; y += x {
			s += cnt1[y]
		}
		ans += s * v
	}
	return
}
```

#### TypeScript

```ts
function numberOfPairs(nums1: number[], nums2: number[], k: number): number {
    const cnt1: Map<number, number> = new Map();
    for (const x of nums1) {
        if (x % k === 0) {
            cnt1.set((x / k) | 0, (cnt1.get((x / k) | 0) || 0) + 1);
        }
    }
    if (cnt1.size === 0) {
        return 0;
    }
    const cnt2: Map<number, number> = new Map();
    for (const x of nums2) {
        cnt2.set(x, (cnt2.get(x) || 0) + 1);
    }
    const mx = Math.max(...cnt1.keys());
    let ans = 0;
    for (const [x, v] of cnt2) {
        let s = 0;
        for (let y = x; y <= mx; y += x) {
            s += cnt1.get(y) || 0;
        }
        ans += s * v;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3163. 压缩字符串 III](https://leetcode.cn/problems/string-compression-iii){#3163}

{{< tabs "3163" >}}

{{% tab "python" %}}
```python
class Solution:
    def compressedString(self, word: str) -> str:
        g = groupby(word)
        ans = []
        for c, v in g:
            k = len(list(v))
            while k:
                x = min(9, k)
                ans.append(str(x) + c)
                k -= x
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word.charAt(j) == word.charAt(i)) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = Math.min(9, k);
                ans.append(x).append(word.charAt(i));
                k -= x;
            }
            i = j;
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
    string compressedString(string word) {
        string ans;
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = min(9, k);
                ans.push_back('0' + x);
                ans.push_back(word[i]);
                k -= x;
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func compressedString(word string) string {
	ans := []byte{}
	n := len(word)
	for i := 0; i < n; {
		j := i + 1
		for j < n && word[j] == word[i] {
			j++
		}
		k := j - i
		for k > 0 {
			x := min(9, k)
			ans = append(ans, byte('0'+x))
			ans = append(ans, word[i])
			k -= x
		}
		i = j
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function compressedString(word: string): string {
    const regex = /(.)\1{0,8}/g;
    let m: RegExpMatchArray | null = null;
    let res = '';

    while ((m = regex.exec(word))) {
        res += m[0].length + m[1];
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function compressedString(word) {
    const regex = /(.)\1{0,8}/g;
    let m = null;
    let res = '';

    while ((m = regex.exec(word))) {
        res += m[0].length + m[1];
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

<p>给你一个字符串 <code>word</code>，请你使用以下算法进行压缩：</p>

<ul>
	<li>从空字符串 <code>comp</code> 开始。当 <code>word</code> <strong>不为空</strong> 时，执行以下操作：

    <ul>
    	<li>移除 <code>word</code> 的最长单字符前缀，该前缀由单一字符 <code>c</code> 重复多次组成，且该前缀长度 <strong>最多 </strong>为 9 。</li>
    	<li>将前缀的长度和字符 <code>c</code> 追加到 <code>comp</code> 。</li>
    </ul>
    </li>

</ul>

<p>返回字符串 <code>comp</code> 。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abcde"</span></p>

<p><strong>输出：</strong><span class="example-io">"1a1b1c1d1e"</span></p>

<p><strong>解释：</strong></p>

<p>初始时，<code>comp = ""</code> 。进行 5 次操作，每次操作分别选择 <code>"a"</code>、<code>"b"</code>、<code>"c"</code>、<code>"d"</code> 和 <code>"e"</code> 作为前缀。</p>

<p>对每个前缀，将 <code>"1"</code> 和对应的字符追加到 <code>comp</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aaaaaaaaaaaaaabb"</span></p>

<p><strong>输出：</strong><span class="example-io">"9a5a2b"</span></p>

<p><strong>解释：</strong></p>

<p>初始时，<code>comp = ""</code>。进行 3 次操作，每次操作分别选择 <code>"aaaaaaaaa"</code>、<code>"aaaaa"</code> 和 <code>"bb"</code> 作为前缀。</p>

<ul>
	<li>对于前缀 <code>"aaaaaaaaa"</code>，将 <code>"9"</code> 和 <code>"a"</code> 追加到 <code>comp</code>。</li>
	<li>对于前缀 <code>"aaaaa"</code>，将 <code>"5"</code> 和 <code>"a"</code> 追加到 <code>comp</code>。</li>
	<li>对于前缀 <code>"bb"</code>，将 <code>"2"</code> 和 <code>"b"</code> 追加到 <code>comp</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以利用双指针，统计每个字符的连续出现次数。假如当前字符 $c$ 连续出现了 $k$ 次，然后我们将 $k$ 划分成若干个 $x$，每个 $x$ 最大为 $9$，然后将 $x$ 和 $c$ 拼接起来，将每个 $x$ 和 $c$ 拼接起来到结果中。

最后返回结果即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def compressedString(self, word: str) -> str:
        g = groupby(word)
        ans = []
        for c, v in g:
            k = len(list(v))
            while k:
                x = min(9, k)
                ans.append(str(x) + c)
                k -= x
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word.charAt(j) == word.charAt(i)) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = Math.min(9, k);
                ans.append(x).append(word.charAt(i));
                k -= x;
            }
            i = j;
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = min(9, k);
                ans.push_back('0' + x);
                ans.push_back(word[i]);
                k -= x;
            }
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func compressedString(word string) string {
	ans := []byte{}
	n := len(word)
	for i := 0; i < n; {
		j := i + 1
		for j < n && word[j] == word[i] {
			j++
		}
		k := j - i
		for k > 0 {
			x := min(9, k)
			ans = append(ans, byte('0'+x))
			ans = append(ans, word[i])
			k -= x
		}
		i = j
	}
	return string(ans)
}
```

#### TypeScript

```ts
function compressedString(word: string): string {
    const ans: string[] = [];
    const n = word.length;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && word[j] === word[i]) {
            ++j;
        }
        let k = j - i;
        while (k) {
            const x = Math.min(k, 9);
            ans.push(x + word[i]);
            k -= x;
        }
        i = j;
    }
    return ans.join('');
}
```

#### JavaScript

```js
/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function (word) {
    const ans = [];
    const n = word.length;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && word[j] === word[i]) {
            ++j;
        }
        let k = j - i;
        while (k) {
            const x = Math.min(k, 9);
            ans.push(x + word[i]);
            k -= x;
        }
        i = j;
    }
    return ans.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

<!-- tabs:start -->

#### TypeScript

```ts
function compressedString(word: string): string {
    let res = '';

    for (let i = 1, j = 0; i <= word.length; i++) {
        if (word[i] !== word[j] || i - j === 9) {
            res += i - j + word[j];
            j = i;
        }
    }

    return res;
}
```

#### JavaScript

```js
function compressedString(word) {
    let res = '';

    for (let i = 1, j = 0; i <= word.length; i++) {
        if (word[i] !== word[j] || i - j === 9) {
            res += i - j + word[j];
            j = i;
        }
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：正则匹配

<!-- tabs:start -->

#### TypeScript

```ts
function compressedString(word: string): string {
    const regex = /(.)\1{0,8}/g;
    let m: RegExpMatchArray | null = null;
    let res = '';

    while ((m = regex.exec(word))) {
        res += m[0].length + m[1];
    }

    return res;
}
```

#### JavaScript

```js
function compressedString(word) {
    const regex = /(.)\1{0,8}/g;
    let m = null;
    let res = '';

    while ((m = regex.exec(word))) {
        res += m[0].length + m[1];
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3164. 优质数对的总数 II](https://leetcode.cn/problems/find-the-number-of-good-pairs-ii){#3164}

{{< tabs "3164" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cnt1 = Counter(x // k for x in nums1 if x % k == 0)
        if not cnt1:
            return 0
        cnt2 = Counter(nums2)
        ans = 0
        mx = max(cnt1)
        for x, v in cnt2.items():
            s = sum(cnt1[y] for y in range(x, mx + 1, x))
            ans += s * v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Integer, Integer> cnt1 = new HashMap<>();
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1.merge(x / k, 1, Integer::sum);
            }
        }
        if (cnt1.isEmpty()) {
            return 0;
        }
        Map<Integer, Integer> cnt2 = new HashMap<>();
        for (int x : nums2) {
            cnt2.merge(x, 1, Integer::sum);
        }
        long ans = 0;
        int mx = Collections.max(cnt1.keySet());
        for (var e : cnt2.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            int s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1.getOrDefault(y, 0);
            }
            ans += 1L * s * v;
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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> cnt1;
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1[x / k]++;
            }
        }
        if (cnt1.empty()) {
            return 0;
        }
        unordered_map<int, int> cnt2;
        for (int x : nums2) {
            ++cnt2[x];
        }
        int mx = 0;
        for (auto& [x, _] : cnt1) {
            mx = max(mx, x);
        }
        long long ans = 0;
        for (auto& [x, v] : cnt2) {
            long long s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1[y];
            }
            ans += s * v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPairs(nums1 []int, nums2 []int, k int) (ans int64) {
	cnt1 := map[int]int{}
	for _, x := range nums1 {
		if x%k == 0 {
			cnt1[x/k]++
		}
	}
	if len(cnt1) == 0 {
		return 0
	}
	cnt2 := map[int]int{}
	for _, x := range nums2 {
		cnt2[x]++
	}
	mx := 0
	for x := range cnt1 {
		mx = max(mx, x)
	}
	for x, v := range cnt2 {
		s := 0
		for y := x; y <= mx; y += x {
			s += cnt1[y]
		}
		ans += int64(s) * int64(v)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPairs(nums1: number[], nums2: number[], k: number): number {
    const cnt1: Map<number, number> = new Map();
    for (const x of nums1) {
        if (x % k === 0) {
            cnt1.set((x / k) | 0, (cnt1.get((x / k) | 0) || 0) + 1);
        }
    }
    if (cnt1.size === 0) {
        return 0;
    }
    const cnt2: Map<number, number> = new Map();
    for (const x of nums2) {
        cnt2.set(x, (cnt2.get(x) || 0) + 1);
    }
    const mx = Math.max(...cnt1.keys());
    let ans = 0;
    for (const [x, v] of cnt2) {
        let s = 0;
        for (let y = x; y <= mx; y += x) {
            s += cnt1.get(y) || 0;
        }
        ans += s * v;
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

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>，长度分别为 <code>n</code> 和 <code>m</code>。同时给你一个<strong>正整数</strong> <code>k</code>。</p>

<p>如果 <code>nums1[i]</code> 可以被 <code>nums2[j] * k</code> 整除，则称数对 <code>(i, j)</code> 为 <strong>优质数对</strong>（<code>0 &lt;= i &lt;= n - 1</code>, <code>0 &lt;= j &lt;= m - 1</code>）。</p>

<p>返回<strong> 优质数对 </strong>的总数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,3,4], nums2 = [1,3,4], k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>5个优质数对分别是 <code>(0, 0)</code>, <code>(1, 0)</code>, <code>(1, 1)</code>, <code>(2, 0)</code>, 和 <code>(2, 2)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,2,4,12], nums2 = [2,4], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>2个优质数对分别是 <code>(3, 0)</code> 和 <code>(3, 1)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举倍数

我们用一个哈希表 $\textit{cnt1}$ 记录数组 $\textit{nums1}$ 中每个数除以 $k$ 的商的出现次数，用一个哈希表 $\textit{cnt2}$ 记录数组 $\textit{nums2}$ 中每个数的出现次数。

接下来，我们枚举数组 $\textit{nums2}$ 中的每个数 $x$，对于每个数 $x$，我们枚举 $x$ 的倍数 $y$，其中 $y$ 的范围是 $[x, \textit{mx}]$，其中 $\textit{mx}$ 是 $\textit{cnt1}$ 中的最大键值，然后我们统计 $\textit{cnt1}[y]$ 的和，记为 $s$，最后我们将 $s \times v$ 累加到答案中，其中 $v$ 是 $\textit{cnt2}[x]$。

时间复杂度 $O(n + m + (M / k) \times \log m)$，空间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度，而 $M$ 是数组 $\textit{nums1}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        cnt1 = Counter(x // k for x in nums1 if x % k == 0)
        if not cnt1:
            return 0
        cnt2 = Counter(nums2)
        ans = 0
        mx = max(cnt1)
        for x, v in cnt2.items():
            s = sum(cnt1[y] for y in range(x, mx + 1, x))
            ans += s * v
        return ans
```

#### Java

```java
class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Integer, Integer> cnt1 = new HashMap<>();
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1.merge(x / k, 1, Integer::sum);
            }
        }
        if (cnt1.isEmpty()) {
            return 0;
        }
        Map<Integer, Integer> cnt2 = new HashMap<>();
        for (int x : nums2) {
            cnt2.merge(x, 1, Integer::sum);
        }
        long ans = 0;
        int mx = Collections.max(cnt1.keySet());
        for (var e : cnt2.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            int s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1.getOrDefault(y, 0);
            }
            ans += 1L * s * v;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> cnt1;
        for (int x : nums1) {
            if (x % k == 0) {
                cnt1[x / k]++;
            }
        }
        if (cnt1.empty()) {
            return 0;
        }
        unordered_map<int, int> cnt2;
        for (int x : nums2) {
            ++cnt2[x];
        }
        int mx = 0;
        for (auto& [x, _] : cnt1) {
            mx = max(mx, x);
        }
        long long ans = 0;
        for (auto& [x, v] : cnt2) {
            long long s = 0;
            for (int y = x; y <= mx; y += x) {
                s += cnt1[y];
            }
            ans += s * v;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfPairs(nums1 []int, nums2 []int, k int) (ans int64) {
	cnt1 := map[int]int{}
	for _, x := range nums1 {
		if x%k == 0 {
			cnt1[x/k]++
		}
	}
	if len(cnt1) == 0 {
		return 0
	}
	cnt2 := map[int]int{}
	for _, x := range nums2 {
		cnt2[x]++
	}
	mx := 0
	for x := range cnt1 {
		mx = max(mx, x)
	}
	for x, v := range cnt2 {
		s := 0
		for y := x; y <= mx; y += x {
			s += cnt1[y]
		}
		ans += int64(s) * int64(v)
	}
	return
}
```

#### TypeScript

```ts
function numberOfPairs(nums1: number[], nums2: number[], k: number): number {
    const cnt1: Map<number, number> = new Map();
    for (const x of nums1) {
        if (x % k === 0) {
            cnt1.set((x / k) | 0, (cnt1.get((x / k) | 0) || 0) + 1);
        }
    }
    if (cnt1.size === 0) {
        return 0;
    }
    const cnt2: Map<number, number> = new Map();
    for (const x of nums2) {
        cnt2.set(x, (cnt2.get(x) || 0) + 1);
    }
    const mx = Math.max(...cnt1.keys());
    let ans = 0;
    for (const [x, v] of cnt2) {
        let s = 0;
        for (let y = x; y <= mx; y += x) {
            s += cnt1.get(y) || 0;
        }
        ans += s * v;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3165. 不包含相邻元素的子序列的最大和](https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements){#3165}

{{< tabs "3165" >}}

{{% tab "python" %}}
```python
def max(a: int, b: int) -> int:
    return a if a > b else b


class Node:
    __slots__ = "l", "r", "s00", "s01", "s10", "s11"

    def __init__(self, l: int, r: int):
        self.l = l
        self.r = r
        self.s00 = self.s01 = self.s10 = self.s11 = 0


class SegmentTree:
    __slots__ = "tr"

    def __init__(self, n: int):
        self.tr: List[Node | None] = [None] * (n << 2)
        self.build(1, 1, n)

    def build(self, u: int, l: int, r: int):
        self.tr[u] = Node(l, r)
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def query(self, u: int, l: int, r: int) -> int:
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].s11
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        ans = 0
        if r <= mid:
            ans = self.query(u << 1, l, r)
        if l > mid:
            ans = max(ans, self.query(u << 1 | 1, l, r))
        return ans

    def pushup(self, u: int):
        left, right = self.tr[u << 1], self.tr[u << 1 | 1]
        self.tr[u].s00 = max(left.s00 + right.s10, left.s01 + right.s00)
        self.tr[u].s01 = max(left.s00 + right.s11, left.s01 + right.s01)
        self.tr[u].s10 = max(left.s10 + right.s10, left.s11 + right.s00)
        self.tr[u].s11 = max(left.s10 + right.s11, left.s11 + right.s01)

    def modify(self, u: int, x: int, v: int):
        if self.tr[u].l == self.tr[u].r:
            self.tr[u].s11 = max(0, v)
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)


class Solution:
    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        tree = SegmentTree(n)
        for i, x in enumerate(nums, 1):
            tree.modify(1, i, x)
        ans = 0
        mod = 10**9 + 7
        for i, x in queries:
            tree.modify(1, i + 1, x)
            ans = (ans + tree.query(1, 1, n)) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l, r;
    long s00, s01, s10, s11;

    Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.s00 = this.s01 = this.s10 = this.s11 = 0;
    }
}

class SegmentTree {
    Node[] tr;

    SegmentTree(int n) {
        tr = new Node[n * 4];
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    long query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s11;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        long ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = Math.max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    void pushup(int u) {
        Node left = tr[u << 1];
        Node right = tr[u << 1 | 1];
        tr[u].s00 = Math.max(left.s00 + right.s10, left.s01 + right.s00);
        tr[u].s01 = Math.max(left.s00 + right.s11, left.s01 + right.s01);
        tr[u].s10 = Math.max(left.s10 + right.s10, left.s11 + right.s00);
        tr[u].s11 = Math.max(left.s10 + right.s11, left.s11 + right.s01);
    }

    void modify(int u, int x, int v) {
        if (tr[u].l == tr[u].r) {
            tr[u].s11 = Math.max(0, v);
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }
}

class Solution {
    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        int n = nums.length;
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < n; ++i) {
            tree.modify(1, i + 1, nums[i]);
        }
        long ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int[] q : queries) {
            tree.modify(1, q[0] + 1, q[1]);
            ans = (ans + tree.query(1, 1, n)) % mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l, r;
    long long s00, s01, s10, s11;

    Node(int l, int r)
        : l(l)
        , r(r)
        , s00(0)
        , s01(0)
        , s10(0)
        , s11(0) {}
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n)
        : tr(n << 2) {
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    long long query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s11;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        long long ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    void pushup(int u) {
        Node* left = tr[u << 1];
        Node* right = tr[u << 1 | 1];
        tr[u]->s00 = max(left->s00 + right->s10, left->s01 + right->s00);
        tr[u]->s01 = max(left->s00 + right->s11, left->s01 + right->s01);
        tr[u]->s10 = max(left->s10 + right->s10, left->s11 + right->s00);
        tr[u]->s11 = max(left->s10 + right->s11, left->s11 + right->s01);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == tr[u]->r) {
            tr[u]->s11 = max(0LL, (long long) v);
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    ~SegmentTree() {
        for (auto node : tr) {
            delete node;
        }
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree tree(n);
        for (int i = 0; i < n; ++i) {
            tree.modify(1, i + 1, nums[i]);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            tree.modify(1, q[0] + 1, q[1]);
            ans = (ans + tree.query(1, 1, n)) % mod;
        }
        return (int) ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	l, r               int
	s00, s01, s10, s11 int
}

func NewNode(l, r int) *Node {
	return &Node{l: l, r: r, s00: 0, s01: 0, s10: 0, s11: 0}
}

type SegmentTree struct {
	tr []*Node
}

func NewSegmentTree(n int) *SegmentTree {
	tr := make([]*Node, n*4)
	tree := &SegmentTree{tr: tr}
	tree.build(1, 1, n)
	return tree
}

func (st *SegmentTree) build(u, l, r int) {
	st.tr[u] = NewNode(l, r)
	if l == r {
		return
	}
	mid := (l + r) >> 1
	st.build(u<<1, l, mid)
	st.build(u<<1|1, mid+1, r)
}

func (st *SegmentTree) query(u, l, r int) int {
	if st.tr[u].l >= l && st.tr[u].r <= r {
		return st.tr[u].s11
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	ans := 0
	if r <= mid {
		ans = st.query(u<<1, l, r)
	}
	if l > mid {
		ans = max(ans, st.query(u<<1|1, l, r))
	}
	return ans
}

func (st *SegmentTree) pushup(u int) {
	left := st.tr[u<<1]
	right := st.tr[u<<1|1]
	st.tr[u].s00 = max(left.s00+right.s10, left.s01+right.s00)
	st.tr[u].s01 = max(left.s00+right.s11, left.s01+right.s01)
	st.tr[u].s10 = max(left.s10+right.s10, left.s11+right.s00)
	st.tr[u].s11 = max(left.s10+right.s11, left.s11+right.s01)
}

func (st *SegmentTree) modify(u, x, v int) {
	if st.tr[u].l == st.tr[u].r {
		st.tr[u].s11 = max(0, v)
		return
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	if x <= mid {
		st.modify(u<<1, x, v)
	} else {
		st.modify(u<<1|1, x, v)
	}
	st.pushup(u)
}

func maximumSumSubsequence(nums []int, queries [][]int) (ans int) {
	n := len(nums)
	tree := NewSegmentTree(n)
	for i, x := range nums {
		tree.modify(1, i+1, x)
	}
	const mod int = 1e9 + 7
	for _, q := range queries {
		tree.modify(1, q[0]+1, q[1])
		ans = (ans + tree.query(1, 1, n)) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    s00 = 0;
    s01 = 0;
    s10 = 0;
    s11 = 0;

    constructor(
        public l: number,
        public r: number,
    ) {}
}

class SegmentTree {
    tr: Node[];

    constructor(n: number) {
        this.tr = Array(n * 4);
        this.build(1, 1, n);
    }

    build(u: number, l: number, r: number) {
        this.tr[u] = new Node(l, r);
        if (l === r) {
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
    }

    query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].s11;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let ans = 0;
        if (r <= mid) {
            ans = this.query(u << 1, l, r);
        }
        if (l > mid) {
            ans = Math.max(ans, this.query((u << 1) | 1, l, r));
        }
        return ans;
    }

    pushup(u: number) {
        const left = this.tr[u << 1];
        const right = this.tr[(u << 1) | 1];
        this.tr[u].s00 = Math.max(left.s00 + right.s10, left.s01 + right.s00);
        this.tr[u].s01 = Math.max(left.s00 + right.s11, left.s01 + right.s01);
        this.tr[u].s10 = Math.max(left.s10 + right.s10, left.s11 + right.s00);
        this.tr[u].s11 = Math.max(left.s10 + right.s11, left.s11 + right.s01);
    }

    modify(u: number, x: number, v: number) {
        if (this.tr[u].l === this.tr[u].r) {
            this.tr[u].s11 = Math.max(0, v);
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }
}

function maximumSumSubsequence(nums: number[], queries: number[][]): number {
    const n = nums.length;
    const tree = new SegmentTree(n);
    for (let i = 0; i < n; i++) {
        tree.modify(1, i + 1, nums[i]);
    }
    let ans = 0;
    const mod = 1e9 + 7;
    for (const [i, x] of queries) {
        tree.modify(1, i + 1, x);
        ans = (ans + tree.query(1, 1, n)) % mod;
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

<p>给你一个整数数组 <code>nums</code> 和一个二维数组 <code>queries</code>，其中 <code>queries[i] = [pos<sub>i</sub>, x<sub>i</sub>]</code>。</p>

<p>对于每个查询 <code>i</code>，首先将 <code>nums[pos<sub>i</sub>]</code> 设置为 <code>x<sub>i</sub></code>，然后计算查询 <code>i</code> 的答案，该答案为 <code>nums</code> 中 <strong>不包含相邻元素 </strong>的 <span data-keyword="subsequence-array">子序列</span> 的 <strong>最大 </strong>和。</p>

<p>返回所有查询的答案之和。</p>

<p>由于最终答案可能非常大，返回其对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p><strong>子序列</strong> 是指从另一个数组中删除一些或不删除元素而不改变剩余元素顺序得到的数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,5,9], queries = [[1,-2],[0,-3]]</span></p>

<p><strong>输出：</strong><span class="example-io">21</span></p>

<p><strong>解释：</strong><br />
执行第 1 个查询后，<code>nums = [3,-2,9]</code>，不包含相邻元素的子序列的最大和为 <code>3 + 9 = 12</code>。<br />
执行第 2 个查询后，<code>nums = [-3,-2,9]</code>，不包含相邻元素的子序列的最大和为 9 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [0,-1], queries = [[0,-5]]</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong><br />
执行第 1 个查询后，<code>nums = [-5,-1]</code>，不包含相邻元素的子序列的最大和为 0（选择空子序列）。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i] == [pos<sub>i</sub>, x<sub>i</sub>]</code></li>
	<li><code>0 &lt;= pos<sub>i</sub> &lt;= nums.length - 1</code></li>
	<li><code>-10<sup>5</sup> &lt;= x<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

根据题目描述，我们需要进行多次单点修改和区间查询，这种场景下，我们考虑使用线段树来解决。

首先，我们定义一个 $\textit{Node}$ 类，用于存储线段树的节点信息，包括左右端点 $l$ 和 $r$，以及四个状态值 $s_{00}$, $s_{01}$, $s_{10}$ 和 $s_{11}$。其中：

-   $s_{00}$ 表示不包含当前节点左右端点的子序列的最大和；
-   $s_{01}$ 表示不包含当前节点左端点的子序列的最大和；
-   $s_{10}$ 表示不包含当前节点右端点的子序列的最大和；
-   $s_{11}$ 表示包含当前节点左右端点的子序列的最大和。

接着，我们定义一个 $\textit{SegmentTree}$ 类，用于构建线段树。在构建线段树的过程中，我们需要递归地构建左右子树，并根据左右子树的状态值来更新当前节点的状态值。

在主函数中，我们首先根据给定的数组 $\textit{nums}$ 构建线段树，并对每个查询进行处理。对于每个查询，我们首先进行单点修改，然后查询整个区间的状态值，并将结果累加到答案中。

时间复杂度 $O((n + q) \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 表示数组 $\textit{nums}$ 的长度，而 $q$ 表示查询的次数。

<!-- tabs:start -->

#### Python3

```python
def max(a: int, b: int) -> int:
    return a if a > b else b


class Node:
    __slots__ = "l", "r", "s00", "s01", "s10", "s11"

    def __init__(self, l: int, r: int):
        self.l = l
        self.r = r
        self.s00 = self.s01 = self.s10 = self.s11 = 0


class SegmentTree:
    __slots__ = "tr"

    def __init__(self, n: int):
        self.tr: List[Node | None] = [None] * (n << 2)
        self.build(1, 1, n)

    def build(self, u: int, l: int, r: int):
        self.tr[u] = Node(l, r)
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def query(self, u: int, l: int, r: int) -> int:
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].s11
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        ans = 0
        if r <= mid:
            ans = self.query(u << 1, l, r)
        if l > mid:
            ans = max(ans, self.query(u << 1 | 1, l, r))
        return ans

    def pushup(self, u: int):
        left, right = self.tr[u << 1], self.tr[u << 1 | 1]
        self.tr[u].s00 = max(left.s00 + right.s10, left.s01 + right.s00)
        self.tr[u].s01 = max(left.s00 + right.s11, left.s01 + right.s01)
        self.tr[u].s10 = max(left.s10 + right.s10, left.s11 + right.s00)
        self.tr[u].s11 = max(left.s10 + right.s11, left.s11 + right.s01)

    def modify(self, u: int, x: int, v: int):
        if self.tr[u].l == self.tr[u].r:
            self.tr[u].s11 = max(0, v)
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)


class Solution:
    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        tree = SegmentTree(n)
        for i, x in enumerate(nums, 1):
            tree.modify(1, i, x)
        ans = 0
        mod = 10**9 + 7
        for i, x in queries:
            tree.modify(1, i + 1, x)
            ans = (ans + tree.query(1, 1, n)) % mod
        return ans
```

#### Java

```java
class Node {
    int l, r;
    long s00, s01, s10, s11;

    Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.s00 = this.s01 = this.s10 = this.s11 = 0;
    }
}

class SegmentTree {
    Node[] tr;

    SegmentTree(int n) {
        tr = new Node[n * 4];
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    long query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s11;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        long ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = Math.max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    void pushup(int u) {
        Node left = tr[u << 1];
        Node right = tr[u << 1 | 1];
        tr[u].s00 = Math.max(left.s00 + right.s10, left.s01 + right.s00);
        tr[u].s01 = Math.max(left.s00 + right.s11, left.s01 + right.s01);
        tr[u].s10 = Math.max(left.s10 + right.s10, left.s11 + right.s00);
        tr[u].s11 = Math.max(left.s10 + right.s11, left.s11 + right.s01);
    }

    void modify(int u, int x, int v) {
        if (tr[u].l == tr[u].r) {
            tr[u].s11 = Math.max(0, v);
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }
}

class Solution {
    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        int n = nums.length;
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < n; ++i) {
            tree.modify(1, i + 1, nums[i]);
        }
        long ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int[] q : queries) {
            tree.modify(1, q[0] + 1, q[1]);
            ans = (ans + tree.query(1, 1, n)) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    int l, r;
    long long s00, s01, s10, s11;

    Node(int l, int r)
        : l(l)
        , r(r)
        , s00(0)
        , s01(0)
        , s10(0)
        , s11(0) {}
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n)
        : tr(n << 2) {
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    long long query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s11;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        long long ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    void pushup(int u) {
        Node* left = tr[u << 1];
        Node* right = tr[u << 1 | 1];
        tr[u]->s00 = max(left->s00 + right->s10, left->s01 + right->s00);
        tr[u]->s01 = max(left->s00 + right->s11, left->s01 + right->s01);
        tr[u]->s10 = max(left->s10 + right->s10, left->s11 + right->s00);
        tr[u]->s11 = max(left->s10 + right->s11, left->s11 + right->s01);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == tr[u]->r) {
            tr[u]->s11 = max(0LL, (long long) v);
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    ~SegmentTree() {
        for (auto node : tr) {
            delete node;
        }
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree tree(n);
        for (int i = 0; i < n; ++i) {
            tree.modify(1, i + 1, nums[i]);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            tree.modify(1, q[0] + 1, q[1]);
            ans = (ans + tree.query(1, 1, n)) % mod;
        }
        return (int) ans;
    }
};
```

#### Go

```go
type Node struct {
	l, r               int
	s00, s01, s10, s11 int
}

func NewNode(l, r int) *Node {
	return &Node{l: l, r: r, s00: 0, s01: 0, s10: 0, s11: 0}
}

type SegmentTree struct {
	tr []*Node
}

func NewSegmentTree(n int) *SegmentTree {
	tr := make([]*Node, n*4)
	tree := &SegmentTree{tr: tr}
	tree.build(1, 1, n)
	return tree
}

func (st *SegmentTree) build(u, l, r int) {
	st.tr[u] = NewNode(l, r)
	if l == r {
		return
	}
	mid := (l + r) >> 1
	st.build(u<<1, l, mid)
	st.build(u<<1|1, mid+1, r)
}

func (st *SegmentTree) query(u, l, r int) int {
	if st.tr[u].l >= l && st.tr[u].r <= r {
		return st.tr[u].s11
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	ans := 0
	if r <= mid {
		ans = st.query(u<<1, l, r)
	}
	if l > mid {
		ans = max(ans, st.query(u<<1|1, l, r))
	}
	return ans
}

func (st *SegmentTree) pushup(u int) {
	left := st.tr[u<<1]
	right := st.tr[u<<1|1]
	st.tr[u].s00 = max(left.s00+right.s10, left.s01+right.s00)
	st.tr[u].s01 = max(left.s00+right.s11, left.s01+right.s01)
	st.tr[u].s10 = max(left.s10+right.s10, left.s11+right.s00)
	st.tr[u].s11 = max(left.s10+right.s11, left.s11+right.s01)
}

func (st *SegmentTree) modify(u, x, v int) {
	if st.tr[u].l == st.tr[u].r {
		st.tr[u].s11 = max(0, v)
		return
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	if x <= mid {
		st.modify(u<<1, x, v)
	} else {
		st.modify(u<<1|1, x, v)
	}
	st.pushup(u)
}

func maximumSumSubsequence(nums []int, queries [][]int) (ans int) {
	n := len(nums)
	tree := NewSegmentTree(n)
	for i, x := range nums {
		tree.modify(1, i+1, x)
	}
	const mod int = 1e9 + 7
	for _, q := range queries {
		tree.modify(1, q[0]+1, q[1])
		ans = (ans + tree.query(1, 1, n)) % mod
	}
	return
}
```

#### TypeScript

```ts
class Node {
    s00 = 0;
    s01 = 0;
    s10 = 0;
    s11 = 0;

    constructor(
        public l: number,
        public r: number,
    ) {}
}

class SegmentTree {
    tr: Node[];

    constructor(n: number) {
        this.tr = Array(n * 4);
        this.build(1, 1, n);
    }

    build(u: number, l: number, r: number) {
        this.tr[u] = new Node(l, r);
        if (l === r) {
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
    }

    query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].s11;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let ans = 0;
        if (r <= mid) {
            ans = this.query(u << 1, l, r);
        }
        if (l > mid) {
            ans = Math.max(ans, this.query((u << 1) | 1, l, r));
        }
        return ans;
    }

    pushup(u: number) {
        const left = this.tr[u << 1];
        const right = this.tr[(u << 1) | 1];
        this.tr[u].s00 = Math.max(left.s00 + right.s10, left.s01 + right.s00);
        this.tr[u].s01 = Math.max(left.s00 + right.s11, left.s01 + right.s01);
        this.tr[u].s10 = Math.max(left.s10 + right.s10, left.s11 + right.s00);
        this.tr[u].s11 = Math.max(left.s10 + right.s11, left.s11 + right.s01);
    }

    modify(u: number, x: number, v: number) {
        if (this.tr[u].l === this.tr[u].r) {
            this.tr[u].s11 = Math.max(0, v);
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }
}

function maximumSumSubsequence(nums: number[], queries: number[][]): number {
    const n = nums.length;
    const tree = new SegmentTree(n);
    for (let i = 0; i < n; i++) {
        tree.modify(1, i + 1, nums[i]);
    }
    let ans = 0;
    const mod = 1e9 + 7;
    for (const [i, x] of queries) {
        tree.modify(1, i + 1, x);
        ans = (ans + tree.query(1, 1, n)) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3166. 计算停车费与时长 🔒](https://leetcode.cn/problems/calculate-parking-fees-and-duration){#3166}

{{< tabs "3166" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            car_id,
            lot_id,
            SUM(TIMESTAMPDIFF(SECOND, entry_time, exit_time)) AS duration
        FROM ParkingTransactions
        GROUP BY 1, 2
    ),
    P AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY car_id
                ORDER BY duration DESC
            ) AS rk
        FROM T
    )
SELECT
    t1.car_id,
    SUM(fee_paid) AS total_fee_paid,
    ROUND(
        SUM(fee_paid) / (SUM(TIMESTAMPDIFF(SECOND, entry_time, exit_time)) / 3600),
        2
    ) AS avg_hourly_fee,
    t2.lot_id AS most_time_lot
FROM
    ParkingTransactions AS t1
    LEFT JOIN P AS t2 ON t1.car_id = t2.car_id AND t2.rk = 1
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>ParkingTransactions</code></p>

<pre>
+--------------+-----------+
| Column Name  | Type      |
+--------------+-----------+
| lot_id       | int       |
| car_id       | int       |
| entry_time   | datetime  |
| exit_time    | datetime  |
| fee_paid     | decimal   |
+--------------+-----------+
(lot_id, car_id, entry_time) 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含停车场的 ID，车的 ID，入场和出场时间，以及停车时长的支付费用。
</pre>

<p>编写一个解决方案来找到 <strong>所有停车场</strong>&nbsp;中每辆车支付的 <strong>总停车费</strong>，以及 <strong>每</strong> 辆车支付的&nbsp;<strong>每小时平均费用</strong>（舍入到&nbsp;<code>2</code> 位小数）。同时，找到每辆车 <strong>总花费时间</strong> 最多的 <strong>停车场</strong>。</p>

<p>返回结果表以<em>&nbsp;</em><code>car_id</code><em><b>&nbsp;升序 </b>排序。</em></p>

<p><strong>注意：</strong>测试用例的生成方式使得单辆汽车不能同时位于多个停车场。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>ParkingTransactions 表：</p>

<pre class="example-io">
+--------+--------+---------------------+---------------------+----------+
| lot_id | car_id | entry_time          | exit_time           | fee_paid |
+--------+--------+---------------------+---------------------+----------+
| 1      | 1001   | 2023-06-01 08:00:00 | 2023-06-01 10:30:00 | 5.00     |
| 1      | 1001   | 2023-06-02 11:00:00 | 2023-06-02 12:45:00 | 3.00     |
| 2      | 1001   | 2023-06-01 10:45:00 | 2023-06-01 12:00:00 | 6.00     |
| 2      | 1002   | 2023-06-01 09:00:00 | 2023-06-01 11:30:00 | 4.00     |
| 3      | 1001   | 2023-06-03 07:00:00 | 2023-06-03 09:00:00 | 4.00     |
| 3      | 1002   | 2023-06-02 12:00:00 | 2023-06-02 14:00:00 | 2.00     |
+--------+--------+---------------------+---------------------+----------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+--------+----------------+----------------+---------------+
| car_id | total_fee_paid | avg_hourly_fee | most_time_lot |
+--------+----------------+----------------+---------------+
| 1001   | 18.00          | 2.40           | 1             |
| 1002   | 6.00           | 1.33           | 2             |
+--------+----------------+----------------+---------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于汽车 ID 1001：
	<ul>
		<li>从 2023-06-01 08:00:00 到 2023-06-01 10:30:00 在停车场&nbsp;1：2.5 小时，费用&nbsp;5.00</li>
		<li>从 2023-06-02 11:00:00 到 2023-06-02 12:45:00 在停车场 1：1.75 小时，费用 3.00</li>
		<li>从 2023-06-01 10:45:00 到 2023-06-01 12:00:00 在停车场 2：1.25 小时，费用 6.00</li>
		<li>从 2023-06-03 07:00:00 到 2023-06-03 09:00:00 在停车场 3：2 小时，费用 4.00</li>
	</ul>
	总共支付费用：18.00，总小时：7.5，每小时平均费用：2.40，停车场 1 总花费时间最长：4.25&nbsp;小时。</li>
	<li>对于汽车 ID 1002：
	<ul>
		<li>从 2023-06-01 09:00:00 到 2023-06-01 11:30:00 在停车场 2：2.5 小时，费用 4.00</li>
		<li>从 2023-06-02 12:00:00 到 2023-06-02 14:00:00 在停车场 3：2 小时，费用 2.00</li>
	</ul>
	总共支付费用：6.00，总小时：4.5，每小时平均费用：1.33，停车场 2 总花费时间最长：2.5 小时。</li>
</ul>

<p><b>注意：</b>&nbsp;输出表以 car_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 连接

我们可以先按照 `car_id` 和 `lot_id` 进行分组，计算每辆车在每个停车场的停车时长，然后利用 `RANK()` 函数对每辆车在每个停车场的停车时长进行排名，找到每辆车在停车时长最长的停车场。

最后，我们可以根据 `car_id` 进行分组，计算每辆车的总停车费、每小时平均费用和停车时长最长的停车场。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            car_id,
            lot_id,
            SUM(TIMESTAMPDIFF(SECOND, entry_time, exit_time)) AS duration
        FROM ParkingTransactions
        GROUP BY 1, 2
    ),
    P AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY car_id
                ORDER BY duration DESC
            ) AS rk
        FROM T
    )
SELECT
    t1.car_id,
    SUM(fee_paid) AS total_fee_paid,
    ROUND(
        SUM(fee_paid) / (SUM(TIMESTAMPDIFF(SECOND, entry_time, exit_time)) / 3600),
        2
    ) AS avg_hourly_fee,
    t2.lot_id AS most_time_lot
FROM
    ParkingTransactions AS t1
    LEFT JOIN P AS t2 ON t1.car_id = t2.car_id AND t2.rk = 1
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3167. 字符串的更好压缩 🔒](https://leetcode.cn/problems/better-compression-of-string){#3167}

{{< tabs "3167" >}}

{{% tab "python" %}}
```python
class Solution:
    def betterCompression(self, compressed: str) -> str:
        cnt = Counter()
        i, n = 0, len(compressed)
        while i < n:
            j = i + 1
            x = 0
            while j < n and compressed[j].isdigit():
                x = x * 10 + int(compressed[j])
                j += 1
            cnt[compressed[i]] += x
            i = j
        return "".join(sorted(f"{k}{v}" for k, v in cnt.items()))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String betterCompression(String compressed) {
        Map<Character, Integer> cnt = new TreeMap<>();
        int i = 0;
        int n = compressed.length();
        while (i < n) {
            char c = compressed.charAt(i);
            int j = i + 1;
            int x = 0;
            while (j < n && Character.isDigit(compressed.charAt(j))) {
                x = x * 10 + (compressed.charAt(j) - '0');
                j++;
            }
            cnt.merge(c, x, Integer::sum);
            i = j;
        }
        StringBuilder ans = new StringBuilder();
        for (var e : cnt.entrySet()) {
            ans.append(e.getKey()).append(e.getValue());
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
    string betterCompression(string compressed) {
        map<char, int> cnt;
        int i = 0;
        int n = compressed.length();
        while (i < n) {
            char c = compressed[i];
            int j = i + 1;
            int x = 0;
            while (j < n && isdigit(compressed[j])) {
                x = x * 10 + (compressed[j] - '0');
                j++;
            }
            cnt[c] += x;
            i = j;
        }
        stringstream ans;
        for (const auto& entry : cnt) {
            ans << entry.first << entry.second;
        }
        return ans.str();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func betterCompression(compressed string) string {
	cnt := map[byte]int{}
	n := len(compressed)
	for i := 0; i < n; {
		c := compressed[i]
		j := i + 1
		x := 0
		for j < n && compressed[j] >= '0' && compressed[j] <= '9' {
			x = x*10 + int(compressed[j]-'0')
			j++
		}
		cnt[c] += x
		i = j
	}
	ans := strings.Builder{}
	for c := byte('a'); c <= byte('z'); c++ {
		if cnt[c] > 0 {
			ans.WriteByte(c)
			ans.WriteString(strconv.Itoa(cnt[c]))
		}
	}
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function betterCompression(compressed: string): string {
    const cnt = new Map<string, number>();
    const n = compressed.length;
    let i = 0;

    while (i < n) {
        const c = compressed[i];
        let j = i + 1;
        let x = 0;
        while (j < n && /\d/.test(compressed[j])) {
            x = x * 10 + +compressed[j];
            j++;
        }
        cnt.set(c, (cnt.get(c) || 0) + x);
        i = j;
    }
    const keys = Array.from(cnt.keys()).sort();
    const ans: string[] = [];
    for (const k of keys) {
        ans.push(`${k}${cnt.get(k)}`);
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>compressed</code>&nbsp;表示一个字符串的压缩版本。格式是一个字符后面加上其出现频率。例如&nbsp;<code>"a3b1a1c2"</code>&nbsp;是字符串&nbsp;<code>"aaabacc"</code>&nbsp;的一个压缩版本。</p>

<p>我们在以下条件下寻求 <strong>更好的压缩</strong>：</p>

<ol>
	<li>每个字符在压缩版本中只应出现 <strong>一次</strong>。</li>
	<li>字符应按 <strong>字母顺序</strong> 排列。</li>
</ol>

<p>返回&nbsp;<code>compressed</code>&nbsp;的更好压缩版本。</p>

<p><strong>注意：</strong>在更好的压缩版本中，字母的顺序可能会改变，这是可以接受的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">compressed = "a3c9b2c1"</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">"a3b2c10"</span></p>

<p><strong>解释：</strong></p>

<p>字符 "a" 和 "b" 在输入中只出现了一次，但 "c" 出现了两次，第一次长度为 9，另一次是长度为 1。</p>

<p>因此，在结果字符串中，它应当长度为 10。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">compressed = "c2b3a1"</span></p>

<p><span class="example-io"><b>输出：</b>"a1b3c2"</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">compressed = "a2b4c1"</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">"a2b4c1"</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= compressed.length &lt;= 6 * 10<sup>4</sup></code></li>
	<li><code>compressed</code> 仅由小写英文字母和数字组成。</li>
	<li><code>compressed</code> 是有效的压缩，即，每个字符后面都有其出现频率。</li>
	<li>出现频率在&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;之间并且没有前导 0。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双指针

我们可以使用哈希表来统计每个字符的频率，然后使用双指针来遍历 `compressed` 字符串，将每个字符的频率累加到哈希表中，最后按照字母顺序将字符和频率拼接成字符串。

时间复杂度 $O(n + |\Sigma| \log |\Sigma|)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 `compressed` 的长度，而 $|\Sigma|$ 是字符集的大小，这里字符集是小写字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def betterCompression(self, compressed: str) -> str:
        cnt = Counter()
        i, n = 0, len(compressed)
        while i < n:
            j = i + 1
            x = 0
            while j < n and compressed[j].isdigit():
                x = x * 10 + int(compressed[j])
                j += 1
            cnt[compressed[i]] += x
            i = j
        return "".join(sorted(f"{k}{v}" for k, v in cnt.items()))
```

#### Java

```java
class Solution {
    public String betterCompression(String compressed) {
        Map<Character, Integer> cnt = new TreeMap<>();
        int i = 0;
        int n = compressed.length();
        while (i < n) {
            char c = compressed.charAt(i);
            int j = i + 1;
            int x = 0;
            while (j < n && Character.isDigit(compressed.charAt(j))) {
                x = x * 10 + (compressed.charAt(j) - '0');
                j++;
            }
            cnt.merge(c, x, Integer::sum);
            i = j;
        }
        StringBuilder ans = new StringBuilder();
        for (var e : cnt.entrySet()) {
            ans.append(e.getKey()).append(e.getValue());
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string betterCompression(string compressed) {
        map<char, int> cnt;
        int i = 0;
        int n = compressed.length();
        while (i < n) {
            char c = compressed[i];
            int j = i + 1;
            int x = 0;
            while (j < n && isdigit(compressed[j])) {
                x = x * 10 + (compressed[j] - '0');
                j++;
            }
            cnt[c] += x;
            i = j;
        }
        stringstream ans;
        for (const auto& entry : cnt) {
            ans << entry.first << entry.second;
        }
        return ans.str();
    }
};
```

#### Go

```go
func betterCompression(compressed string) string {
	cnt := map[byte]int{}
	n := len(compressed)
	for i := 0; i < n; {
		c := compressed[i]
		j := i + 1
		x := 0
		for j < n && compressed[j] >= '0' && compressed[j] <= '9' {
			x = x*10 + int(compressed[j]-'0')
			j++
		}
		cnt[c] += x
		i = j
	}
	ans := strings.Builder{}
	for c := byte('a'); c <= byte('z'); c++ {
		if cnt[c] > 0 {
			ans.WriteByte(c)
			ans.WriteString(strconv.Itoa(cnt[c]))
		}
	}
	return ans.String()
}
```

#### TypeScript

```ts
function betterCompression(compressed: string): string {
    const cnt = new Map<string, number>();
    const n = compressed.length;
    let i = 0;

    while (i < n) {
        const c = compressed[i];
        let j = i + 1;
        let x = 0;
        while (j < n && /\d/.test(compressed[j])) {
            x = x * 10 + +compressed[j];
            j++;
        }
        cnt.set(c, (cnt.get(c) || 0) + x);
        i = j;
    }
    const keys = Array.from(cnt.keys()).sort();
    const ans: string[] = [];
    for (const k of keys) {
        ans.push(`${k}${cnt.get(k)}`);
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3168. 候诊室中的最少椅子数](https://leetcode.cn/problems/minimum-number-of-chairs-in-a-waiting-room){#3168}

{{< tabs "3168" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumChairs(self, s: str) -> int:
        cnt = left = 0
        for c in s:
            if c == "E":
                if left:
                    left -= 1
                else:
                    cnt += 1
            else:
                left += 1
        return cnt
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumChairs(String s) {
        int cnt = 0, left = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, left = 0;
        for (char& c : s) {
            if (c == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumChairs(s string) int {
	cnt, left := 0, 0
	for _, c := range s {
		if c == 'E' {
			if left > 0 {
				left--
			} else {
				cnt++
			}
		} else {
			left++
		}
	}
	return cnt
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumChairs(s: string): number {
    let [cnt, left] = [0, 0];
    for (const c of s) {
        if (c === 'E') {
            if (left > 0) {
                --left;
            } else {
                ++cnt;
            }
        } else {
            ++left;
        }
    }
    return cnt;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>，模拟每秒钟的事件 <code>i</code>：</p>

<ul>
	<li>如果 <code>s[i] == 'E'</code>，表示有一位顾客进入候诊室并占用一把椅子。</li>
	<li>如果 <code>s[i] == 'L'</code>，表示有一位顾客离开候诊室，从而释放一把椅子。</li>
</ul>

<p>返回保证每位进入候诊室的顾客都能有椅子坐的<strong> 最少 </strong>椅子数，假设候诊室最初是 <strong>空的 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "EEEEEEE"</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<p>每秒后都有一个顾客进入候诊室，没有人离开。因此，至少需要 7 把椅子。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "ELELEEL"</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>假设候诊室里有 2 把椅子。下表显示了每秒钟等候室的状态。</p>
</div>
<table>
	<tbody>
		<tr>
			<th>秒</th>
			<th>事件</th>
			<th>候诊室的人数</th>
			<th>可用的椅子数</th>
		</tr>
		<tr>
			<td>0</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Leave</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Leave</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>5</td>
			<td>Enter</td>
			<td>2</td>
			<td>0</td>
		</tr>
		<tr>
			<td>6</td>
			<td>Leave</td>
			<td>1</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "ELEELEELLL"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>假设候诊室里有 3 把椅子。下表显示了每秒钟等候室的状态。</p>
</div>
<table>
	<tbody>
		<tr>
			<th>秒</th>
			<th>事件</th>
			<th>候诊室的人数</th>
			<th>可用的椅子数</th>
		</tr>
		<tr>
			<td>0</td>
			<td>Enter</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Leave</td>
			<td>0</td>
			<td>3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Enter</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Enter</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Leave</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>5</td>
			<td>Enter</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>6</td>
			<td>Enter</td>
			<td>3</td>
			<td>0</td>
		</tr>
		<tr>
			<td>7</td>
			<td>Leave</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>8</td>
			<td>Leave</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>9</td>
			<td>Leave</td>
			<td>0</td>
			<td>3</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> 仅由字母 <code>'E'</code> 和 <code>'L'</code> 组成。</li>
	<li><code>s</code> 表示一个有效的进出序列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用变量 $\textit{cnt}$ 来记录当前需要的椅子数，用变量 $\textit{left}$ 来记录当前剩余的空椅子数。遍历字符串 $\textit{s}$，如果当前字符是 'E'，那么如果有剩余的空椅子，就直接使用一个空椅子，否则需要增加一个椅子；如果当前字符是 'L'，那么剩余的空椅子数加一。

遍历结束后，返回 $\textit{cnt}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumChairs(self, s: str) -> int:
        cnt = left = 0
        for c in s:
            if c == "E":
                if left:
                    left -= 1
                else:
                    cnt += 1
            else:
                left += 1
        return cnt
```

#### Java

```java
class Solution {
    public int minimumChairs(String s) {
        int cnt = 0, left = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, left = 0;
        for (char& c : s) {
            if (c == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
};
```

#### Go

```go
func minimumChairs(s string) int {
	cnt, left := 0, 0
	for _, c := range s {
		if c == 'E' {
			if left > 0 {
				left--
			} else {
				cnt++
			}
		} else {
			left++
		}
	}
	return cnt
}
```

#### TypeScript

```ts
function minimumChairs(s: string): number {
    let [cnt, left] = [0, 0];
    for (const c of s) {
        if (c === 'E') {
            if (left > 0) {
                --left;
            } else {
                ++cnt;
            }
        } else {
            ++left;
        }
    }
    return cnt;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3169. 无需开会的工作日](https://leetcode.cn/problems/count-days-without-meetings){#3169}

{{< tabs "3169" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        ans = last = 0
        for st, ed in meetings:
            if last < st:
                ans += st - last - 1
            last = max(last, ed)
        ans += days - last
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        int ans = 0, last = 0;
        for (var e : meetings) {
            int st = e[0], ed = e[1];
            if (last < st) {
                ans += st - last - 1;
            }
            last = Math.max(last, ed);
        }
        ans += days - last;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0, last = 0;
        for (auto& e : meetings) {
            int st = e[0], ed = e[1];
            if (last < st) {
                ans += st - last - 1;
            }
            last = max(last, ed);
        }
        ans += days - last;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDays(days int, meetings [][]int) (ans int) {
	sort.Slice(meetings, func(i, j int) bool { return meetings[i][0] < meetings[j][0] })
	last := 0
	for _, e := range meetings {
		st, ed := e[0], e[1]
		if last < st {
			ans += st - last - 1
		}
		last = max(last, ed)
	}
	ans += days - last
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countDays(days: number, meetings: number[][]): number {
    meetings.sort((a, b) => a[0] - b[0]);
    let [ans, last] = [0, 0];
    for (const [st, ed] of meetings) {
        if (last < st) {
            ans += st - last - 1;
        }
        last = Math.max(last, ed);
    }
    ans += days - last;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_days(days: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        meetings.sort_by_key(|m| m[0]);
        let mut ans = 0;
        let mut last = 0;

        for e in meetings {
            let st = e[0];
            let ed = e[1];
            if last < st {
                ans += st - last - 1;
            }
            last = last.max(ed);
        }

        ans + (days - last)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>days</code>，表示员工可工作的总天数（从第 1 天开始）。另给你一个二维数组 <code>meetings</code>，长度为 <code>n</code>，其中 <code>meetings[i] = [start_i, end_i]</code> 表示第 <code>i</code> 次会议的开始和结束天数（包含首尾）。</p>

<p>返回员工可工作且没有安排会议的天数。</p>

<p><strong>注意：</strong>会议时间可能会有重叠。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">days = 10, meetings = [[5,7],[1,3],[9,10]]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>第 4 天和第 8 天没有安排会议。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">days = 5, meetings = [[2,4],[1,3]]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>第 5 天没有安排会议。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">days = 6, meetings = [[1,6]]</span></p>

<p><strong>输出：</strong>0</p>

<p><strong>解释：</strong></p>

<p>所有工作日都安排了会议。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code>1 &lt;= meetings[i][0] &lt;= meetings[i][1] &lt;= days</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们不妨将所有会议按照开始时间排序，用一个变量 $\textit{last}$ 记录此前会议的最晚结束时间。

然后我们遍历所有会议，对于每一个会议 $(\textit{st}, \textit{ed})$，如果 $\textit{last} < \textit{st}$，说明 $\textit{last}$ 到 $\textit{st}$ 之间的时间段是员工可以工作且没有安排会议的时间，我们将这段时间加入答案。然后我们更新 $\textit{last} = \max(\textit{last}, \textit{ed})$。

最后，如果 $\textit{last} < \textit{days}$，说明最后一次会议结束后还有时间段是员工可以工作且没有安排会议的时间，我们将这段时间加入答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为会议的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        ans = last = 0
        for st, ed in meetings:
            if last < st:
                ans += st - last - 1
            last = max(last, ed)
        ans += days - last
        return ans
```

#### Java

```java
class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        int ans = 0, last = 0;
        for (var e : meetings) {
            int st = e[0], ed = e[1];
            if (last < st) {
                ans += st - last - 1;
            }
            last = Math.max(last, ed);
        }
        ans += days - last;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0, last = 0;
        for (auto& e : meetings) {
            int st = e[0], ed = e[1];
            if (last < st) {
                ans += st - last - 1;
            }
            last = max(last, ed);
        }
        ans += days - last;
        return ans;
    }
};
```

#### Go

```go
func countDays(days int, meetings [][]int) (ans int) {
	sort.Slice(meetings, func(i, j int) bool { return meetings[i][0] < meetings[j][0] })
	last := 0
	for _, e := range meetings {
		st, ed := e[0], e[1]
		if last < st {
			ans += st - last - 1
		}
		last = max(last, ed)
	}
	ans += days - last
	return
}
```

#### TypeScript

```ts
function countDays(days: number, meetings: number[][]): number {
    meetings.sort((a, b) => a[0] - b[0]);
    let [ans, last] = [0, 0];
    for (const [st, ed] of meetings) {
        if (last < st) {
            ans += st - last - 1;
        }
        last = Math.max(last, ed);
    }
    ans += days - last;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_days(days: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        meetings.sort_by_key(|m| m[0]);
        let mut ans = 0;
        let mut last = 0;

        for e in meetings {
            let st = e[0];
            let ed = e[1];
            if last < st {
                ans += st - last - 1;
            }
            last = last.max(ed);
        }

        ans + (days - last)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
