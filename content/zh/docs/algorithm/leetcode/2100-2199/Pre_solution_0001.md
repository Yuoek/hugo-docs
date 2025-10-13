---
title: "2100_适合野炊的日子"
date: 2025-10-08T18:39:03+08:00
weight: 1
tags: [二分查找, 几何, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 数学, 数据流, 数组, 有序集合, 栈, 模拟, 深度优先搜索, 滑动窗口, 设计]
---

{{< markmap >}}
### [2100_适合野炊的日子](#2100)
#### [数组](#2100)
#### [动态规划](#2100)
#### [前缀和](#2100)
### [2101_引爆最多的炸弹](#2101)
#### [深度优先搜索](#2101)
#### [广度优先搜索](#2101)
#### [图](#2101)
#### [几何](#2101)
#### [数组](#2101)
#### [数学](#2101)
### [2102_序列顺序查询](#2102)
#### [设计](#2102)
#### [数据流](#2102)
#### [有序集合](#2102)
#### [堆（优先队列）](#2102)
### [2103_环和杆](#2103)
#### [哈希表](#2103)
#### [字符串](#2103)
### [2104_子数组范围和](#2104)
#### [栈](#2104)
#### [数组](#2104)
#### [单调栈](#2104)
### [2105_给植物浇水 II](#2105)
#### [数组](#2105)
#### [双指针](#2105)
#### [模拟](#2105)
### [2106_摘水果](#2106)
#### [数组](#2106)
#### [二分查找](#2106)
#### [前缀和](#2106)
#### [滑动窗口](#2106)
### [2107_分享 K 个糖果后独特口味的数量 🔒](#2107)
#### [数组](#2107)
#### [哈希表](#2107)
#### [滑动窗口](#2107)
### [2108_找出数组中的第一个回文字符串](#2108)
#### [数组](#2108)
#### [双指针](#2108)
#### [字符串](#2108)
### [2109_向字符串添加空格](#2109)
#### [数组](#2109)
#### [双指针](#2109)
#### [字符串](#2109)
#### [模拟](#2109)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2100_适合野炊的日子
___
#### 数组
___
#### 动态规划
___
#### 前缀和
---
### 2101_引爆最多的炸弹
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 几何
___
#### 数组
___
#### 数学
---
### 2102_序列顺序查询
___
#### 设计
___
#### 数据流
___
#### 有序集合
___
#### 堆（优先队列）
---
### 2103_环和杆
___
#### 哈希表
___
#### 字符串
---
### 2104_子数组范围和
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 2105_给植物浇水 II
___
#### 数组
___
#### 双指针
___
#### 模拟
---
### 2106_摘水果
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 2107_分享 K 个糖果后独特口味的数量 🔒
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2108_找出数组中的第一个回文字符串
___
#### 数组
___
#### 双指针
___
#### 字符串
---
### 2109_向字符串添加空格
___
#### 数组
___
#### 双指针
___
#### 字符串
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 几何 | 前缀和 |
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 数学 |
| 数据流 | 数组 | 有序集合 |
| 栈 | 模拟 | 深度优先搜索 |
| 滑动窗口 | 设计 |  |

# [2100. 适合野炊的日子](https://leetcode.cn/problems/find-good-days-to-rob-the-bank){#2100}

{{< tabs "2100" >}}

{{% tab "python" %}}
```python
class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        if n <= time * 2:
            return []
        left, right = [0] * n, [0] * n
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]:
                right[i] = right[i + 1] + 1
        return [i for i in range(n) if time <= min(left[i], right[i])]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int n = security.length;
        if (n <= time * 2) {
            return Collections.emptyList();
        }
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = time; i < n - time; ++i) {
            if (time <= Math.min(left[i], right[i])) {
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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        if (n <= time * 2) return {};
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; ++i)
            if (security[i] <= security[i - 1])
                left[i] = left[i - 1] + 1;
        for (int i = n - 2; i >= 0; --i)
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
        vector<int> ans;
        for (int i = time; i < n - time; ++i)
            if (time <= min(left[i], right[i]))
                ans.push_back(i);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func goodDaysToRobBank(security []int, time int) []int {
	n := len(security)
	if n <= time*2 {
		return []int{}
	}
	left := make([]int, n)
	right := make([]int, n)
	for i := 1; i < n; i++ {
		if security[i] <= security[i-1] {
			left[i] = left[i-1] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if security[i] <= security[i+1] {
			right[i] = right[i+1] + 1
		}
	}
	var ans []int
	for i := time; i < n-time; i++ {
		if time <= left[i] && time <= right[i] {
			ans = append(ans, i)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function goodDaysToRobBank(security: number[], time: number): number[] {
    const n = security.length;
    if (n <= time * 2) {
        return [];
    }
    const l = new Array(n).fill(0);
    const r = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        if (security[i] <= security[i - 1]) {
            l[i] = l[i - 1] + 1;
        }
        if (security[n - i - 1] <= security[n - i]) {
            r[n - i - 1] = r[n - i] + 1;
        }
    }
    const res = [];
    for (let i = time; i < n - time; i++) {
        if (time <= Math.min(l[i], r[i])) {
            res.push(i);
        }
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Ordering;

impl Solution {
    pub fn good_days_to_rob_bank(security: Vec<i32>, time: i32) -> Vec<i32> {
        let time = time as usize;
        let n = security.len();
        if time * 2 >= n {
            return vec![];
        }
        let mut g = vec![0; n];
        for i in 1..n {
            g[i] = match security[i].cmp(&security[i - 1]) {
                Ordering::Less => -1,
                Ordering::Greater => 1,
                Ordering::Equal => 0,
            };
        }
        let (mut a, mut b) = (vec![0; n + 1], vec![0; n + 1]);
        for i in 1..=n {
            a[i] = a[i - 1] + (if g[i - 1] == 1 { 1 } else { 0 });
            b[i] = b[i - 1] + (if g[i - 1] == -1 { 1 } else { 0 });
        }
        let mut res = vec![];
        for i in time..n - time {
            if a[i + 1] - a[i + 1 - time] == 0 && b[i + 1 + time] - b[i + 1] == 0 {
                res.push(i as i32);
            }
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

<p>你和朋友们准备去野炊。给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>security</code>&nbsp;，其中&nbsp;<code>security[i]</code>&nbsp;是第 <code>i</code>&nbsp;天的建议出行指数。日子从 <code>0</code>&nbsp;开始编号。同时给你一个整数&nbsp;<code>time</code>&nbsp;。</p>

<p>如果第 <code>i</code>&nbsp;天满足以下所有条件，我们称它为一个适合野炊的日子：</p>

<ul>
	<li>第 <code>i</code>&nbsp;天前和后都分别至少有 <code>time</code>&nbsp;天。</li>
	<li>第 <code>i</code>&nbsp;天前连续 <code>time</code>&nbsp;天建议出行指数都是非递增的。</li>
	<li>第 <code>i</code>&nbsp;天后连续 <code>time</code>&nbsp;天建议出行指数都是非递减的。</li>
</ul>

<p>更正式的，第 <code>i</code> 天是一个适合野炊的日子当且仅当：<code>security[i - time] &gt;= security[i - time + 1] &gt;= ... &gt;= security[i] &lt;= ... &lt;= security[i + time - 1] &lt;= security[i + time]</code>.</p>

<p>请你返回一个数组，包含 <strong>所有</strong> 适合野炊的日子（下标从 <strong>0</strong>&nbsp;开始）。返回的日子可以 <strong>任意</strong>&nbsp;顺序排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>security = [5,3,3,3,5,6,2], time = 2
<b>输出：</b>[2,3]
<strong>解释：</strong>
第 2 天，我们有 security[0] &gt;= security[1] &gt;= security[2] &lt;= security[3] &lt;= security[4] 。
第 3 天，我们有 security[1] &gt;= security[2] &gt;= security[3] &lt;= security[4] &lt;= security[5] 。
没有其他日子符合这个条件，所以日子 2 和 3 是适合野炊的日子。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>security = [1,1,1,1,1], time = 0
<b>输出：</b>[0,1,2,3,4]
<strong>解释：</strong>
因为 time 等于 0 ，所以每一天都是适合野炊的日子，所以返回每一天。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>security = [1,2,3,4,5,6], time = 2
<b>输出：</b>[]
<strong>解释：</strong>
没有任何一天的前 2 天建议出行指数是非递增的。
所以没有适合野炊的日子，返回空数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= security.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= security[i], time &lt;= 10<sup>5</sup></code></li>
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
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        if n <= time * 2:
            return []
        left, right = [0] * n, [0] * n
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                left[i] = left[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]:
                right[i] = right[i + 1] + 1
        return [i for i in range(n) if time <= min(left[i], right[i])]
```

#### Java

```java
class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int n = security.length;
        if (n <= time * 2) {
            return Collections.emptyList();
        }
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = time; i < n - time; ++i) {
            if (time <= Math.min(left[i], right[i])) {
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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        if (n <= time * 2) return {};
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; ++i)
            if (security[i] <= security[i - 1])
                left[i] = left[i - 1] + 1;
        for (int i = n - 2; i >= 0; --i)
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
        vector<int> ans;
        for (int i = time; i < n - time; ++i)
            if (time <= min(left[i], right[i]))
                ans.push_back(i);
        return ans;
    }
};
```

#### Go

```go
func goodDaysToRobBank(security []int, time int) []int {
	n := len(security)
	if n <= time*2 {
		return []int{}
	}
	left := make([]int, n)
	right := make([]int, n)
	for i := 1; i < n; i++ {
		if security[i] <= security[i-1] {
			left[i] = left[i-1] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if security[i] <= security[i+1] {
			right[i] = right[i+1] + 1
		}
	}
	var ans []int
	for i := time; i < n-time; i++ {
		if time <= left[i] && time <= right[i] {
			ans = append(ans, i)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function goodDaysToRobBank(security: number[], time: number): number[] {
    const n = security.length;
    if (n <= time * 2) {
        return [];
    }
    const l = new Array(n).fill(0);
    const r = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        if (security[i] <= security[i - 1]) {
            l[i] = l[i - 1] + 1;
        }
        if (security[n - i - 1] <= security[n - i]) {
            r[n - i - 1] = r[n - i] + 1;
        }
    }
    const res = [];
    for (let i = time; i < n - time; i++) {
        if (time <= Math.min(l[i], r[i])) {
            res.push(i);
        }
    }
    return res;
}
```

#### Rust

```rust
use std::cmp::Ordering;

impl Solution {
    pub fn good_days_to_rob_bank(security: Vec<i32>, time: i32) -> Vec<i32> {
        let time = time as usize;
        let n = security.len();
        if time * 2 >= n {
            return vec![];
        }
        let mut g = vec![0; n];
        for i in 1..n {
            g[i] = match security[i].cmp(&security[i - 1]) {
                Ordering::Less => -1,
                Ordering::Greater => 1,
                Ordering::Equal => 0,
            };
        }
        let (mut a, mut b) = (vec![0; n + 1], vec![0; n + 1]);
        for i in 1..=n {
            a[i] = a[i - 1] + (if g[i - 1] == 1 { 1 } else { 0 });
            b[i] = b[i - 1] + (if g[i - 1] == -1 { 1 } else { 0 });
        }
        let mut res = vec![];
        for i in time..n - time {
            if a[i + 1] - a[i + 1 - time] == 0 && b[i + 1 + time] - b[i + 1] == 0 {
                res.push(i as i32);
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2101. 引爆最多的炸弹](https://leetcode.cn/problems/detonate-the-maximum-bombs){#2101}

{{< tabs "2101" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        g = [[] for _ in range(n)]
        for i in range(n - 1):
            x1, y1, r1 = bombs[i]
            for j in range(i + 1, n):
                x2, y2, r2 = bombs[j]
                dist = hypot(x1 - x2, y1 - y2)
                if dist <= r1:
                    g[i].append(j)
                if dist <= r2:
                    g[j].append(i)
        ans = 0
        for k in range(n):
            vis = {k}
            q = [k]
            for i in q:
                for j in g[i]:
                    if j not in vis:
                        vis.add(j)
                        q.append(j)
            if len(vis) == n:
                return n
            ans = max(ans, len(vis))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int[] p1 = bombs[i], p2 = bombs[j];
                double dist = Math.hypot(p1[0] - p2[0], p1[1] - p2[1]);
                if (dist <= p1[2]) {
                    g[i].add(j);
                }
                if (dist <= p2[2]) {
                    g[j].add(i);
                }
            }
        }
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int k = 0; k < n; ++k) {
            Arrays.fill(vis, false);
            vis[k] = true;
            int cnt = 0;
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(k);
            while (!q.isEmpty()) {
                int i = q.poll();
                ++cnt;
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
            }
            if (cnt == n) {
                return n;
            }
            ans = Math.max(ans, cnt);
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
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> g[n];
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto& p1 = bombs[i];
                auto& p2 = bombs[j];
                auto dist = hypot(p1[0] - p2[0], p1[1] - p2[1]);
                if (dist <= p1[2]) {
                    g[i].push_back(j);
                }
                if (dist <= p2[2]) {
                    g[j].push_back(i);
                }
            }
        }
        int ans = 0;
        bool vis[n];
        for (int k = 0; k < n; ++k) {
            memset(vis, false, sizeof(vis));
            queue<int> q;
            q.push(k);
            vis[k] = true;
            int cnt = 0;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                ++cnt;
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
            if (cnt == n) {
                return n;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumDetonation(bombs [][]int) (ans int) {
	n := len(bombs)
	g := make([][]int, n)
	for i, p1 := range bombs[:n-1] {
		for j := i + 1; j < n; j++ {
			p2 := bombs[j]
			dist := math.Hypot(float64(p1[0]-p2[0]), float64(p1[1]-p2[1]))
			if dist <= float64(p1[2]) {
				g[i] = append(g[i], j)
			}
			if dist <= float64(p2[2]) {
				g[j] = append(g[j], i)
			}
		}
	}
	for k := 0; k < n; k++ {
		q := []int{k}
		vis := make([]bool, n)
		vis[k] = true
		cnt := 0
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			cnt++
			for _, j := range g[i] {
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
		}
		if cnt == n {
			return n
		}
		ans = max(ans, cnt)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumDetonation(bombs: number[][]): number {
    const n = bombs.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 0; i < n - 1; ++i) {
        const [x1, y1, r1] = bombs[i];
        for (let j = i + 1; j < n; ++j) {
            const [x2, y2, r2] = bombs[j];
            const d = Math.hypot(x1 - x2, y1 - y2);
            if (d <= r1) {
                g[i].push(j);
            }
            if (d <= r2) {
                g[j].push(i);
            }
        }
    }
    let ans = 0;
    for (let k = 0; k < n; ++k) {
        const vis: Set<number> = new Set([k]);
        const q: number[] = [k];
        for (const i of q) {
            for (const j of g[i]) {
                if (!vis.has(j)) {
                    vis.add(j);
                    q.push(j);
                }
            }
        }
        if (vis.size === n) {
            return n;
        }
        ans = Math.max(ans, vis.size);
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

<p>给你一个炸弹列表。一个炸弹的 <strong>爆炸范围</strong>&nbsp;定义为以炸弹为圆心的一个圆。</p>

<p>炸弹用一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>bombs</code>&nbsp;表示，其中&nbsp;<code>bombs[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;。<code>x<sub>i</sub></code> 和&nbsp;<code>y<sub>i</sub></code>&nbsp;表示第 <code>i</code>&nbsp;个炸弹的 X 和 Y 坐标，<code>r<sub>i</sub></code>&nbsp;表示爆炸范围的 <strong>半径</strong>&nbsp;。</p>

<p>你需要选择引爆 <strong>一个&nbsp;</strong>炸弹。当这个炸弹被引爆时，<strong>所有</strong> 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。</p>

<p>给你数组&nbsp;<code>bombs</code>&nbsp;，请你返回在引爆&nbsp;<strong>一个</strong>&nbsp;炸弹的前提下，<strong>最多</strong>&nbsp;能引爆的炸弹数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2101.Detonate%20the%20Maximum%20Bombs/images/desmos-eg-3.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>bombs = [[2,1,3],[6,1,4]]
<b>输出：</b>2
<strong>解释：</strong>
上图展示了 2 个炸弹的位置和爆炸范围。
如果我们引爆左边的炸弹，右边的炸弹不会被影响。
但如果我们引爆右边的炸弹，两个炸弹都会爆炸。
所以最多能引爆的炸弹数目是 max(1, 2) = 2 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2101.Detonate%20the%20Maximum%20Bombs/images/desmos-eg-2.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>bombs = [[1,1,5],[10,10,5]]
<b>输出：</b>1
<strong>解释：
</strong>引爆任意一个炸弹都不会引爆另一个炸弹。所以最多能引爆的炸弹数目为 1 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2101.Detonate%20the%20Maximum%20Bombs/images/desmos-eg1.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
<b>输出：</b>5
<strong>解释：</strong>
最佳引爆炸弹为炸弹 0 ，因为：
- 炸弹 0 引爆炸弹 1 和 2 。红色圆表示炸弹 0 的爆炸范围。
- 炸弹 2 引爆炸弹 3 。蓝色圆表示炸弹 2 的爆炸范围。
- 炸弹 3 引爆炸弹 4 。绿色圆表示炸弹 3 的爆炸范围。
所以总共有 5 个炸弹被引爆。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= bombs.length&nbsp;&lt;= 100</code></li>
	<li><code>bombs[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个长度为 $n$ 的数组 $g$，其中 $g[i]$ 表示炸弹 $i$ 的爆炸范围内可以引爆的所有炸弹的下标。

然后，我们遍历所有炸弹，对于两个炸弹 $(x_1, y_1, r_1)$ 和 $(x_2, y_2, r_2)$，我们计算它们之间的距离 $\textit{dist} = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$。如果 $\textit{dist} \leq r_1$，那么炸弹 $i$ 的爆炸范围内可以引爆炸弹 $j$，我们就将 $j$ 添加到 $g[i]$ 中。如果 $\textit{dist} \leq r_2$，那么炸弹 $j$ 的爆炸范围内可以引爆炸弹 $i$，我们就将 $i$ 添加到 $g[j]$ 中。

接下来，我们遍历所有炸弹，对于每个炸弹 $k$，我们使用广度优先搜索计算炸弹 $k$ 的爆炸范围内可以引爆的所有炸弹的下标，并记录下来。如果这些炸弹的数量等于 $n$，那么我们就可以引爆所有炸弹，直接返回 $n$。否则，我们记录下来这些炸弹的数量，并返回最大值。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为炸弹的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        g = [[] for _ in range(n)]
        for i in range(n - 1):
            x1, y1, r1 = bombs[i]
            for j in range(i + 1, n):
                x2, y2, r2 = bombs[j]
                dist = hypot(x1 - x2, y1 - y2)
                if dist <= r1:
                    g[i].append(j)
                if dist <= r2:
                    g[j].append(i)
        ans = 0
        for k in range(n):
            vis = {k}
            q = [k]
            for i in q:
                for j in g[i]:
                    if j not in vis:
                        vis.add(j)
                        q.append(j)
            if len(vis) == n:
                return n
            ans = max(ans, len(vis))
        return ans
```

#### Java

```java
class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int[] p1 = bombs[i], p2 = bombs[j];
                double dist = Math.hypot(p1[0] - p2[0], p1[1] - p2[1]);
                if (dist <= p1[2]) {
                    g[i].add(j);
                }
                if (dist <= p2[2]) {
                    g[j].add(i);
                }
            }
        }
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int k = 0; k < n; ++k) {
            Arrays.fill(vis, false);
            vis[k] = true;
            int cnt = 0;
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(k);
            while (!q.isEmpty()) {
                int i = q.poll();
                ++cnt;
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
            }
            if (cnt == n) {
                return n;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> g[n];
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto& p1 = bombs[i];
                auto& p2 = bombs[j];
                auto dist = hypot(p1[0] - p2[0], p1[1] - p2[1]);
                if (dist <= p1[2]) {
                    g[i].push_back(j);
                }
                if (dist <= p2[2]) {
                    g[j].push_back(i);
                }
            }
        }
        int ans = 0;
        bool vis[n];
        for (int k = 0; k < n; ++k) {
            memset(vis, false, sizeof(vis));
            queue<int> q;
            q.push(k);
            vis[k] = true;
            int cnt = 0;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                ++cnt;
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
            if (cnt == n) {
                return n;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumDetonation(bombs [][]int) (ans int) {
	n := len(bombs)
	g := make([][]int, n)
	for i, p1 := range bombs[:n-1] {
		for j := i + 1; j < n; j++ {
			p2 := bombs[j]
			dist := math.Hypot(float64(p1[0]-p2[0]), float64(p1[1]-p2[1]))
			if dist <= float64(p1[2]) {
				g[i] = append(g[i], j)
			}
			if dist <= float64(p2[2]) {
				g[j] = append(g[j], i)
			}
		}
	}
	for k := 0; k < n; k++ {
		q := []int{k}
		vis := make([]bool, n)
		vis[k] = true
		cnt := 0
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			cnt++
			for _, j := range g[i] {
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
		}
		if cnt == n {
			return n
		}
		ans = max(ans, cnt)
	}
	return
}
```

#### TypeScript

```ts
function maximumDetonation(bombs: number[][]): number {
    const n = bombs.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 0; i < n - 1; ++i) {
        const [x1, y1, r1] = bombs[i];
        for (let j = i + 1; j < n; ++j) {
            const [x2, y2, r2] = bombs[j];
            const d = Math.hypot(x1 - x2, y1 - y2);
            if (d <= r1) {
                g[i].push(j);
            }
            if (d <= r2) {
                g[j].push(i);
            }
        }
    }
    let ans = 0;
    for (let k = 0; k < n; ++k) {
        const vis: Set<number> = new Set([k]);
        const q: number[] = [k];
        for (const i of q) {
            for (const j of g[i]) {
                if (!vis.has(j)) {
                    vis.add(j);
                    q.push(j);
                }
            }
        }
        if (vis.size === n) {
            return n;
        }
        ans = Math.max(ans, vis.size);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2102. 序列顺序查询](https://leetcode.cn/problems/sequentially-ordinal-rank-tracker){#2102}

{{< tabs "2102" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self, s: str):
        self.s = s

    def __lt__(self, other):
        return self.s > other.s


class SORTracker:

    def __init__(self):
        self.good = []
        self.bad = []

    def add(self, name: str, score: int) -> None:
        score, node = heappushpop(self.good, (score, Node(name)))
        heappush(self.bad, (-score, node.s))

    def get(self) -> str:
        score, name = heappop(self.bad)
        heappush(self.good, (-score, Node(name)))
        return self.good[0][1].s


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using pis = pair<int, string>;

class SORTracker {
public:
    SORTracker() {
    }

    void add(string name, int score) {
        good.push({-score, name});
        bad.push(good.top());
        good.pop();
    }

    string get() {
        good.push(bad.top());
        bad.pop();
        return good.top().second;
    }

private:
    priority_queue<pis, vector<pis>, less<pis>> good;
    priority_queue<pis, vector<pis>, greater<pis>> bad;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SORTracker {
    private PriorityQueue<Map.Entry<Integer, String>> good = new PriorityQueue<>(
        (a, b)
            -> a.getKey().equals(b.getKey()) ? b.getValue().compareTo(a.getValue())
                                             : a.getKey() - b.getKey());
    private PriorityQueue<Map.Entry<Integer, String>> bad = new PriorityQueue<>(
        (a, b)
            -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                             : b.getKey() - a.getKey());

    public SORTracker() {
    }

    public void add(String name, int score) {
        good.offer(Map.entry(score, name));
        bad.offer(good.poll());
    }

    public String get() {
        good.offer(bad.poll());
        return good.peek().getValue();
    }
}

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker obj = new SORTracker();
 * obj.add(name,score);
 * String param_2 = obj.get();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个观光景点由它的名字&nbsp;<code>name</code> 和景点评分&nbsp;<code>score</code>&nbsp;组成，其中&nbsp;<code>name</code>&nbsp;是所有观光景点中&nbsp;<strong>唯一</strong>&nbsp;的字符串，<code>score</code>&nbsp;是一个整数。景点按照最好到最坏排序。景点评分 <strong>越高</strong>&nbsp;，这个景点越好。如果有两个景点的评分一样，那么 <strong>字典序较小</strong>&nbsp;的景点更好。</p>

<p>你需要搭建一个系统，查询景点的排名。初始时系统里没有任何景点。这个系统支持：</p>

<ul>
	<li><strong>添加</strong> 景点，每次添加 <strong>一个</strong> 景点。</li>
	<li><strong>查询 </strong>已经添加景点中第&nbsp;<code>i</code>&nbsp;<strong>好</strong>&nbsp;的景点，其中&nbsp;<code>i</code>&nbsp;是系统目前位置查询的次数（包括当前这一次）。
	<ul>
		<li>比方说，如果系统正在进行第 <code>4</code>&nbsp;次查询，那么需要返回所有已经添加景点中第 <code>4</code>&nbsp;好的。</li>
	</ul>
	</li>
</ul>

<p>注意，测试数据保证&nbsp;<strong>任意查询时刻</strong>&nbsp;，查询次数都 <strong>不超过</strong>&nbsp;系统中景点的数目。</p>

<p>请你实现&nbsp;<code>SORTracker</code>&nbsp;类：</p>

<ul>
	<li><code>SORTracker()</code>&nbsp;初始化系统。</li>
	<li><code>void add(string name, int score)</code>&nbsp;向系统中添加一个名为&nbsp;<code>name</code> 评分为&nbsp;<code>score</code>&nbsp;的景点。</li>
	<li><code>string get()</code>&nbsp;查询第 <code>i</code>&nbsp;好的景点，其中 <code>i</code>&nbsp;是目前系统查询的次数（包括当前这次查询）。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["SORTracker", "add", "add", "get", "add", "get", "add", "get", "add", "get", "add", "get", "get"]
[[], ["bradford", 2], ["branford", 3], [], ["alps", 2], [], ["orland", 2], [], ["orlando", 3], [], ["alpine", 2], [], []]
<strong>输出：</strong>
[null, null, null, "branford", null, "alps", null, "bradford", null, "bradford", null, "bradford", "orland"]

<strong>解释：</strong>
SORTracker tracker = new SORTracker(); // 初始化系统
tracker.add("bradford", 2); // 添加 name="bradford" 且 score=2 的景点。
tracker.add("branford", 3); // 添加 name="branford" 且 score=3 的景点。
tracker.get();              // 从好到坏的景点为：branford ，bradford 。
                            // 注意到 branford 比 bradford 好，因为它的 <strong>评分更高</strong> (3 &gt; 2) 。
                            // 这是第 1 次调用 get() ，所以返回最好的景点："branford" 。
tracker.add("alps", 2);     // 添加 name="alps" 且 score=2 的景点。
tracker.get();              // 从好到坏的景点为：branford, alps, bradford 。
                            // 注意 alps 比 bradford 好，虽然它们评分相同，都为 2 。
                            // 这是因为 "alps" <strong>字典序</strong>&nbsp;比 "bradford" 小。
                            // 返回第 2 好的地点 "alps" ，因为当前为第 2 次调用 get() 。
tracker.add("orland", 2);   // 添加 name="orland" 且 score=2 的景点。
tracker.get();              // 从好到坏的景点为：branford, alps, bradford, orland 。
                            // 返回 "bradford" ，因为当前为第 3 次调用 get() 。
tracker.add("orlando", 3);  // 添加 name="orlando" 且 score=3 的景点。
tracker.get();              // 从好到坏的景点为：branford, orlando, alps, bradford, orland 。
                            // 返回 "bradford".
tracker.add("alpine", 2);   // 添加 name="alpine" 且 score=2 的景点。
tracker.get();              // 从好到坏的景点为：branford, orlando, alpine, alps, bradford, orland 。
                            // 返回 "bradford" 。
tracker.get();              // 从好到坏的景点为：branford, orlando, alpine, alps, bradford, orland 。
                            // 返回 "orland" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>name</code>&nbsp;只包含小写英文字母，且每个景点名字互不相同。</li>
	<li><code>1 &lt;= name.length &lt;= 10</code></li>
	<li><code>1 &lt;= score &lt;= 10<sup>5</sup></code></li>
	<li>任意时刻，调用&nbsp;<code>get</code>&nbsp;的次数都不超过调用&nbsp;<code>add</code>&nbsp;的次数。</li>
	<li><strong>总共</strong>&nbsp;调用&nbsp;<code>add</code> 和&nbsp;<code>get</code>&nbsp;不超过&nbsp;<code>4 * 10<sup>4</sup></code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合

我们可以使用有序集合来存储景点，用一个变量 $i$ 来记录当前查询的次数，初始时 $i = -1$。

调用 `add` 方法时，我们将景点的评分取负数，这样就可以使用有序集合按照评分从大到小排序，如果评分相同，按照景点名字的字典序从小到大排序。

调用 `get` 方法时，我们将 $i$ 加一，然后返回有序集合中第 $i$ 个景点的名字。

每次操作的时间复杂度为 $O(\log n)$，其中 $n$ 为已添加的景点数。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class SORTracker:

    def __init__(self):
        self.sl = SortedList()
        self.i = -1

    def add(self, name: str, score: int) -> None:
        self.sl.add((-score, name))

    def get(self) -> str:
        self.i += 1
        return self.sl[self.i][1]


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
```

#### C++

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class SORTracker {
public:
    SORTracker() {
    }

    void add(string name, int score) {
        st.insert({-score, name});
    }

    string get() {
        return st.find_by_order(++i)->second;
    }

private:
    ordered_set<pair<int, string>> st;
    int i = -1;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双优先队列（大小根堆）

我们注意到，由于本题中的查询操作是按照严格递增的顺序进行的，因此我们可以使用类似于数据流中的中位数的方法，定义两个优先队列 `good` 和 `bad`，其中 `good` 是一个小根堆，存储当前最好的景点，`bad` 是一个大根堆，存储当前第 $i$ 好的景点。

每次调用 `add` 方法时，我们将景点的评分和名字加入 `good` 中，然后将 `good` 中的最差的景点加入 `bad` 中。

每次调用 `get` 方法时，我们将 `bad` 中的最好的景点加入 `good` 中，然后返回 `good` 中的最差的景点。

每次操作的时间复杂度为 $O(\log n)$，其中 $n$ 为已添加的景点数。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self, s: str):
        self.s = s

    def __lt__(self, other):
        return self.s > other.s


class SORTracker:

    def __init__(self):
        self.good = []
        self.bad = []

    def add(self, name: str, score: int) -> None:
        score, node = heappushpop(self.good, (score, Node(name)))
        heappush(self.bad, (-score, node.s))

    def get(self) -> str:
        score, name = heappop(self.bad)
        heappush(self.good, (-score, Node(name)))
        return self.good[0][1].s


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
```

#### Java

```java
class SORTracker {
    private PriorityQueue<Map.Entry<Integer, String>> good = new PriorityQueue<>(
        (a, b)
            -> a.getKey().equals(b.getKey()) ? b.getValue().compareTo(a.getValue())
                                             : a.getKey() - b.getKey());
    private PriorityQueue<Map.Entry<Integer, String>> bad = new PriorityQueue<>(
        (a, b)
            -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                             : b.getKey() - a.getKey());

    public SORTracker() {
    }

    public void add(String name, int score) {
        good.offer(Map.entry(score, name));
        bad.offer(good.poll());
    }

    public String get() {
        good.offer(bad.poll());
        return good.peek().getValue();
    }
}

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker obj = new SORTracker();
 * obj.add(name,score);
 * String param_2 = obj.get();
 */
```

#### C++

```cpp
using pis = pair<int, string>;

class SORTracker {
public:
    SORTracker() {
    }

    void add(string name, int score) {
        good.push({-score, name});
        bad.push(good.top());
        good.pop();
    }

    string get() {
        good.push(bad.top());
        bad.pop();
        return good.top().second;
    }

private:
    priority_queue<pis, vector<pis>, less<pis>> good;
    priority_queue<pis, vector<pis>, greater<pis>> bad;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2103. 环和杆](https://leetcode.cn/problems/rings-and-rods){#2103}

{{< tabs "2103" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPoints(self, rings: str) -> int:
        mask = [0] * 10
        d = {"R": 1, "G": 2, "B": 4}
        for i in range(0, len(rings), 2):
            c = rings[i]
            j = int(rings[i + 1])
            mask[j] |= d[c]
        return mask.count(7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPoints(String rings) {
        int[] d = new int['Z'];
        d['R'] = 1;
        d['G'] = 2;
        d['B'] = 4;
        int[] mask = new int[10];
        for (int i = 0, n = rings.length(); i < n; i += 2) {
            int c = rings.charAt(i);
            int j = rings.charAt(i + 1) - '0';
            mask[j] |= d[c];
        }
        int ans = 0;
        for (int x : mask) {
            if (x == 7) {
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
    int countPoints(string rings) {
        int d['Z']{['R'] = 1, ['G'] = 2, ['B'] = 4};
        int mask[10]{};
        for (int i = 0, n = rings.size(); i < n; i += 2) {
            int c = rings[i];
            int j = rings[i + 1] - '0';
            mask[j] |= d[c];
        }
        return count(mask, mask + 10, 7);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPoints(rings string) (ans int) {
	d := ['Z']int{'R': 1, 'G': 2, 'B': 4}
	mask := [10]int{}
	for i, n := 0, len(rings); i < n; i += 2 {
		c := rings[i]
		j := int(rings[i+1] - '0')
		mask[j] |= d[c]
	}
	for _, x := range mask {
		if x == 7 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPoints(rings: string): number {
    let c = 0;
    for (let i = 0; i <= 9; i++) {
        if (rings.includes('B' + i) && rings.includes('R' + i) && rings.includes('G' + i)) c++;
    }
    return c;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_points(rings: String) -> i32 {
        let mut d: [i32; 90] = [0; 90];
        d['R' as usize] = 1;
        d['G' as usize] = 2;
        d['B' as usize] = 4;

        let mut mask: [i32; 10] = [0; 10];

        let cs: Vec<char> = rings.chars().collect();

        for i in (0..cs.len()).step_by(2) {
            let c = cs[i] as usize;
            let j = (cs[i + 1] as usize) - ('0' as usize);
            mask[j] |= d[c];
        }

        mask.iter().filter(|&&x| x == 7).count() as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countPoints(char* rings) {
    int d['Z'];
    memset(d, 0, sizeof(d));
    d['R'] = 1;
    d['G'] = 2;
    d['B'] = 4;

    int mask[10];
    memset(mask, 0, sizeof(mask));

    for (int i = 0, n = strlen(rings); i < n; i += 2) {
        int c = rings[i];
        int j = rings[i + 1] - '0';
        mask[j] |= d[c];
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (mask[i] == 7) {
            ans++;
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

<p>总计有 <code>n</code> 个环，环的颜色可以是红、绿、蓝中的一种。这些环分别穿在 10 根编号为 <code>0</code> 到 <code>9</code> 的杆上。</p>

<p>给你一个长度为 <code>2n</code> 的字符串 <code>rings</code> ，表示这 <code>n</code> 个环在杆上的分布。<code>rings</code> 中每两个字符形成一个 <strong>颜色位置对</strong> ，用于描述每个环：</p>

<ul>
	<li>第 <code>i</code> 对中的 <strong>第一个</strong> 字符表示第 <code>i</code> 个环的 <strong>颜色</strong>（<code>'R'</code>、<code>'G'</code>、<code>'B'</code>）。</li>
	<li>第 <code>i</code> 对中的 <strong>第二个</strong> 字符表示第 <code>i</code> 个环的 <strong>位置</strong>，也就是位于哪根杆上（<code>'0'</code> 到 <code>'9'</code>）。</li>
</ul>

<p>例如，<code>"R3G2B1"</code> 表示：共有 <code>n == 3</code> 个环，红色的环在编号为 3 的杆上，绿色的环在编号为 2 的杆上，蓝色的环在编号为 1 的杆上。</p>

<p>找出所有集齐 <strong>全部三种颜色</strong> 环的杆，并返回这种杆的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2103.Rings%20and%20Rods/images/ex1final.png" style="width: 258px; height: 130px;" />
<pre>
<strong>输入：</strong>rings = "B0B6G0R6R0R6G9"
<strong>输出：</strong>1
<strong>解释：</strong>
- 编号 0 的杆上有 3 个环，集齐全部颜色：红、绿、蓝。
- 编号 6 的杆上有 3 个环，但只有红、蓝两种颜色。
- 编号 9 的杆上只有 1 个绿色环。
因此，集齐全部三种颜色环的杆的数目为 1 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2103.Rings%20and%20Rods/images/ex2final.png" style="width: 266px; height: 130px;" />
<pre>
<strong>输入：</strong>rings = "B0R0G0R9R0B0G0"
<strong>输出：</strong>1
<strong>解释：</strong>
- 编号 0 的杆上有 6 个环，集齐全部颜色：红、绿、蓝。
- 编号 9 的杆上只有 1 个红色环。
因此，集齐全部三种颜色环的杆的数目为 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rings = "G4"
<strong>输出：</strong>0
<strong>解释：</strong>
只给了一个环，因此，不存在集齐全部三种颜色环的杆。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rings.length == 2 * n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li>如 <code>i</code> 是 <strong>偶数</strong> ，则&nbsp;<code>rings[i]</code> 的值可以取 <code>'R'</code>、<code>'G'</code> 或 <code>'B'</code>（下标从 <strong>0</strong> 开始计数）</li>
	<li>如 <code>i</code> 是 <strong>奇数</strong> ，则&nbsp;<code>rings[i]</code> 的值可以取 <code>'0'</code> 到 <code>'9'</code> 中的一个数字（下标从 <strong>0</strong> 开始计数）</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以用一个长度为 $10$ 的数组 $mask$ 来表示每根杆上的环的颜色情况，其中 $mask[i]$ 表示第 $i$ 根杆上的环的颜色情况，如果第 $i$ 根杆上有红色、绿色、蓝色的环，那么 $mask[i]$ 的二进制表示为 $111$，即 $mask[i] = 7$。

我们遍历字符串 $rings$，对于每个颜色位置对 $(c, j)$，其中 $c$ 表示环的颜色，$j$ 表示环所在的杆的编号，我们将 $mask[j]$ 对应的二进制位进行置位，即 $mask[j] |= d[c]$，其中 $d[c]$ 表示颜色 $c$ 对应的二进制位。

最后我们统计 $mask$ 中值为 $7$ 的元素的个数，即为集齐全部三种颜色环的杆的数目。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 表示字符串 $rings$ 的长度，而 $|\Sigma|$ 表示字符集的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPoints(self, rings: str) -> int:
        mask = [0] * 10
        d = {"R": 1, "G": 2, "B": 4}
        for i in range(0, len(rings), 2):
            c = rings[i]
            j = int(rings[i + 1])
            mask[j] |= d[c]
        return mask.count(7)
```

#### Java

```java
class Solution {
    public int countPoints(String rings) {
        int[] d = new int['Z'];
        d['R'] = 1;
        d['G'] = 2;
        d['B'] = 4;
        int[] mask = new int[10];
        for (int i = 0, n = rings.length(); i < n; i += 2) {
            int c = rings.charAt(i);
            int j = rings.charAt(i + 1) - '0';
            mask[j] |= d[c];
        }
        int ans = 0;
        for (int x : mask) {
            if (x == 7) {
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
    int countPoints(string rings) {
        int d['Z']{['R'] = 1, ['G'] = 2, ['B'] = 4};
        int mask[10]{};
        for (int i = 0, n = rings.size(); i < n; i += 2) {
            int c = rings[i];
            int j = rings[i + 1] - '0';
            mask[j] |= d[c];
        }
        return count(mask, mask + 10, 7);
    }
};
```

#### Go

```go
func countPoints(rings string) (ans int) {
	d := ['Z']int{'R': 1, 'G': 2, 'B': 4}
	mask := [10]int{}
	for i, n := 0, len(rings); i < n; i += 2 {
		c := rings[i]
		j := int(rings[i+1] - '0')
		mask[j] |= d[c]
	}
	for _, x := range mask {
		if x == 7 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countPoints(rings: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'A'.charCodeAt(0);
    const d: number[] = Array(26).fill(0);
    d[idx('R')] = 1;
    d[idx('G')] = 2;
    d[idx('B')] = 4;
    const mask: number[] = Array(10).fill(0);
    for (let i = 0; i < rings.length; i += 2) {
        const c = rings[i];
        const j = rings[i + 1].charCodeAt(0) - '0'.charCodeAt(0);
        mask[j] |= d[idx(c)];
    }
    return mask.filter(x => x === 7).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_points(rings: String) -> i32 {
        let mut d: [i32; 90] = [0; 90];
        d['R' as usize] = 1;
        d['G' as usize] = 2;
        d['B' as usize] = 4;

        let mut mask: [i32; 10] = [0; 10];

        let cs: Vec<char> = rings.chars().collect();

        for i in (0..cs.len()).step_by(2) {
            let c = cs[i] as usize;
            let j = (cs[i + 1] as usize) - ('0' as usize);
            mask[j] |= d[c];
        }

        mask.iter().filter(|&&x| x == 7).count() as i32
    }
}
```

#### C

```c
int countPoints(char* rings) {
    int d['Z'];
    memset(d, 0, sizeof(d));
    d['R'] = 1;
    d['G'] = 2;
    d['B'] = 4;

    int mask[10];
    memset(mask, 0, sizeof(mask));

    for (int i = 0, n = strlen(rings); i < n; i += 2) {
        int c = rings[i];
        int j = rings[i + 1] - '0';
        mask[j] |= d[c];
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (mask[i] == 7) {
            ans++;
        }
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function countPoints(rings: string): number {
    let c = 0;
    for (let i = 0; i <= 9; i++) {
        if (rings.includes('B' + i) && rings.includes('R' + i) && rings.includes('G' + i)) c++;
    }
    return c;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2104. 子数组范围和](https://leetcode.cn/problems/sum-of-subarray-ranges){#2104}

{{< tabs "2104" >}}

{{% tab "python" %}}
```python
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        def f(nums):
            stk = []
            n = len(nums)
            left = [-1] * n
            right = [n] * n
            for i, v in enumerate(nums):
                while stk and nums[stk[-1]] <= v:
                    stk.pop()
                if stk:
                    left[i] = stk[-1]
                stk.append(i)
            stk = []
            for i in range(n - 1, -1, -1):
                while stk and nums[stk[-1]] < nums[i]:
                    stk.pop()
                if stk:
                    right[i] = stk[-1]
                stk.append(i)
            return sum((i - left[i]) * (right[i] - i) * v for i, v in enumerate(nums))

        mx = f(nums)
        mi = f([-v for v in nums])
        return mx + mi
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long subArrayRanges(int[] nums) {
        long mx = f(nums);
        for (int i = 0; i < nums.length; ++i) {
            nums[i] *= -1;
        }
        long mi = f(nums);
        return mx + mi;
    }

    private long f(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] < nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long s = 0;
        for (int i = 0; i < n; ++i) {
            s += (long) (i - left[i]) * (right[i] - i) * nums[i];
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
    long long subArrayRanges(vector<int>& nums) {
        long long mx = f(nums);
        for (int i = 0; i < nums.size(); ++i) nums[i] *= -1;
        long long mi = f(nums);
        return mx + mi;
    }

    long long f(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long) (i - left[i]) * (right[i] - i) * nums[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subArrayRanges(nums []int) int64 {
	f := func(nums []int) int64 {
		stk := []int{}
		n := len(nums)
		left := make([]int, n)
		right := make([]int, n)
		for i := range left {
			left[i] = -1
			right[i] = n
		}
		for i, v := range nums {
			for len(stk) > 0 && nums[stk[len(stk)-1]] <= v {
				stk = stk[:len(stk)-1]
			}
			if len(stk) > 0 {
				left[i] = stk[len(stk)-1]
			}
			stk = append(stk, i)
		}
		stk = []int{}
		for i := n - 1; i >= 0; i-- {
			for len(stk) > 0 && nums[stk[len(stk)-1]] < nums[i] {
				stk = stk[:len(stk)-1]
			}
			if len(stk) > 0 {
				right[i] = stk[len(stk)-1]
			}
			stk = append(stk, i)
		}
		ans := 0
		for i, v := range nums {
			ans += (i - left[i]) * (right[i] - i) * v
		}
		return int64(ans)
	}
	mx := f(nums)
	for i := range nums {
		nums[i] *= -1
	}
	mi := f(nums)
	return mx + mi
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subArrayRanges(nums: number[]): number {
    const n = nums.length;
    let res = 0;
    for (let i = 0; i < n - 1; i++) {
        let min = nums[i];
        let max = nums[i];
        for (let j = i + 1; j < n; j++) {
            min = Math.min(min, nums[j]);
            max = Math.max(max, nums[j]);
            res += max - min;
        }
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sub_array_ranges(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut res: i64 = 0;
        for i in 1..n {
            let mut min = nums[i - 1];
            let mut max = nums[i - 1];
            for j in i..n {
                min = min.min(nums[j]);
                max = max.max(nums[j]);
                res += (max - min) as i64;
            }
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

<p>给你一个整数数组 <code>nums</code> 。<code>nums</code> 中，子数组的 <strong>范围</strong> 是子数组中最大元素和最小元素的差值。</p>

<p>返回 <code>nums</code> 中 <strong>所有</strong> 子数组范围的 <strong>和</strong> <em>。</em></p>

<p>子数组是数组中一个连续 <strong>非空</strong> 的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>4
<strong>解释：</strong>nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0 
[2]，范围 = 2 - 2 = 0
[3]，范围 = 3 - 3 = 0
[1,2]，范围 = 2 - 1 = 1
[2,3]，范围 = 3 - 2 = 1
[1,2,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,3]
<strong>输出：</strong>4
<strong>解释：</strong>nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0
[3]，范围 = 3 - 3 = 0
[3]，范围 = 3 - 3 = 0
[1,3]，范围 = 3 - 1 = 2
[3,3]，范围 = 3 - 3 = 0
[1,3,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,-2,-3,4,1]
<strong>输出：</strong>59
<strong>解释：</strong>nums 中所有子数组范围的和是 59
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一种时间复杂度为 <code>O(n)</code> 的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

循环遍历 $i$，作为子数组的起始位置。对于每个 $i$，遍历每个 $j$ 作为子数组的终止位置，此过程中不断求解子数组的最大值、最小值，然后累加差值到结果 `ans` 中。

最后返回 `ans` 即可。

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n - 1):
            mi = mx = nums[i]
            for j in range(i + 1, n):
                mi = min(mi, nums[j])
                mx = max(mx, nums[j])
                ans += mx - mi
        return ans
```

#### Java

```java
class Solution {
    public long subArrayRanges(int[] nums) {
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < n - 1; ++i) {
            int mi = nums[i], mx = nums[i];
            for (int j = i + 1; j < n; ++j) {
                mi = Math.min(mi, nums[j]);
                mx = Math.max(mx, nums[j]);
                ans += (mx - mi);
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
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int mi = nums[i], mx = nums[i];
            for (int j = i + 1; j < n; ++j) {
                mi = min(mi, nums[j]);
                mx = max(mx, nums[j]);
                ans += (mx - mi);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func subArrayRanges(nums []int) int64 {
	var ans int64
	n := len(nums)
	for i := 0; i < n-1; i++ {
		mi, mx := nums[i], nums[i]
		for j := i + 1; j < n; j++ {
			mi = min(mi, nums[j])
			mx = max(mx, nums[j])
			ans += (int64)(mx - mi)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function subArrayRanges(nums: number[]): number {
    const n = nums.length;
    let res = 0;
    for (let i = 0; i < n - 1; i++) {
        let min = nums[i];
        let max = nums[i];
        for (let j = i + 1; j < n; j++) {
            min = Math.min(min, nums[j]);
            max = Math.max(max, nums[j]);
            res += max - min;
        }
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn sub_array_ranges(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut res: i64 = 0;
        for i in 1..n {
            let mut min = nums[i - 1];
            let mut max = nums[i - 1];
            for j in i..n {
                min = min.min(nums[j]);
                max = max.max(nums[j]);
                res += (max - min) as i64;
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调栈

枚举每个元素 `nums[i]` 作为最大值出现在了多少个子数组中，以及作为最小值出现在多少个子数组中。

其中 `nums[i]` 作为最大值的贡献为正，作为最小值的贡献为负。

我们以 `nums[i]` 作为最大值为例。找出左侧第一个比 `nums[i]` 大的位置 `left[i]`，右侧第一个大于等于 `nums[i]` 的位置 `right[i]`。计算每个 `nums[i]` 的贡献 $(i - left[i])\times (right[i] - i)\times arr[i]$，累加得到结果。

时间复杂度 $O(n)$。

相似题目：

-   [907. 子数组的最小值之和](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0907.Sum%20of%20Subarray%20Minimums/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        def f(nums):
            stk = []
            n = len(nums)
            left = [-1] * n
            right = [n] * n
            for i, v in enumerate(nums):
                while stk and nums[stk[-1]] <= v:
                    stk.pop()
                if stk:
                    left[i] = stk[-1]
                stk.append(i)
            stk = []
            for i in range(n - 1, -1, -1):
                while stk and nums[stk[-1]] < nums[i]:
                    stk.pop()
                if stk:
                    right[i] = stk[-1]
                stk.append(i)
            return sum((i - left[i]) * (right[i] - i) * v for i, v in enumerate(nums))

        mx = f(nums)
        mi = f([-v for v in nums])
        return mx + mi
```

#### Java

```java
class Solution {
    public long subArrayRanges(int[] nums) {
        long mx = f(nums);
        for (int i = 0; i < nums.length; ++i) {
            nums[i] *= -1;
        }
        long mi = f(nums);
        return mx + mi;
    }

    private long f(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] < nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        long s = 0;
        for (int i = 0; i < n; ++i) {
            s += (long) (i - left[i]) * (right[i] - i) * nums[i];
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long mx = f(nums);
        for (int i = 0; i < nums.size(); ++i) nums[i] *= -1;
        long long mi = f(nums);
        return mx + mi;
    }

    long long f(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long) (i - left[i]) * (right[i] - i) * nums[i];
        }
        return ans;
    }
};
```

#### Go

```go
func subArrayRanges(nums []int) int64 {
	f := func(nums []int) int64 {
		stk := []int{}
		n := len(nums)
		left := make([]int, n)
		right := make([]int, n)
		for i := range left {
			left[i] = -1
			right[i] = n
		}
		for i, v := range nums {
			for len(stk) > 0 && nums[stk[len(stk)-1]] <= v {
				stk = stk[:len(stk)-1]
			}
			if len(stk) > 0 {
				left[i] = stk[len(stk)-1]
			}
			stk = append(stk, i)
		}
		stk = []int{}
		for i := n - 1; i >= 0; i-- {
			for len(stk) > 0 && nums[stk[len(stk)-1]] < nums[i] {
				stk = stk[:len(stk)-1]
			}
			if len(stk) > 0 {
				right[i] = stk[len(stk)-1]
			}
			stk = append(stk, i)
		}
		ans := 0
		for i, v := range nums {
			ans += (i - left[i]) * (right[i] - i) * v
		}
		return int64(ans)
	}
	mx := f(nums)
	for i := range nums {
		nums[i] *= -1
	}
	mi := f(nums)
	return mx + mi
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2105. 给植物浇水 II](https://leetcode.cn/problems/watering-plants-ii){#2105}

{{< tabs "2105" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        a, b = capacityA, capacityB
        ans = 0
        i, j = 0, len(plants) - 1
        while i < j:
            if a < plants[i]:
                ans += 1
                a = capacityA
            a -= plants[i]
            if b < plants[j]:
                ans += 1
                b = capacityB
            b -= plants[j]
            i, j = i + 1, j - 1
        ans += i == j and max(a, b) < plants[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int a = capacityA, b = capacityB;
        int ans = 0;
        int i = 0, j = plants.length - 1;
        for (; i < j; ++i, --j) {
            if (a < plants[i]) {
                ++ans;
                a = capacityA;
            }
            a -= plants[i];
            if (b < plants[j]) {
                ++ans;
                b = capacityB;
            }
            b -= plants[j];
        }
        ans += i == j && Math.max(a, b) < plants[i] ? 1 : 0;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a = capacityA, b = capacityB;
        int ans = 0;
        int i = 0, j = plants.size() - 1;
        for (; i < j; ++i, --j) {
            if (a < plants[i]) {
                ++ans;
                a = capacityA;
            }
            a -= plants[i];
            if (b < plants[j]) {
                ++ans;
                b = capacityB;
            }
            b -= plants[j];
        }
        ans += i == j && max(a, b) < plants[i];
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRefill(plants []int, capacityA int, capacityB int) (ans int) {
	a, b := capacityA, capacityB
	i, j := 0, len(plants)-1
	for ; i < j; i, j = i+1, j-1 {
		if a < plants[i] {
			ans++
			a = capacityA
		}
		a -= plants[i]
		if b < plants[j] {
			ans++
			b = capacityB
		}
		b -= plants[j]
	}
	if i == j && max(a, b) < plants[i] {
		ans++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRefill(plants: number[], capacityA: number, capacityB: number): number {
    let [a, b] = [capacityA, capacityB];
    let ans = 0;
    let [i, j] = [0, plants.length - 1];
    for (; i < j; ++i, --j) {
        if (a < plants[i]) {
            ++ans;
            a = capacityA;
        }
        a -= plants[i];
        if (b < plants[j]) {
            ++ans;
            b = capacityB;
        }
        b -= plants[j];
    }
    ans += i === j && Math.max(a, b) < plants[i] ? 1 : 0;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_refill(plants: Vec<i32>, capacity_a: i32, capacity_b: i32) -> i32 {
        let mut a = capacity_a;
        let mut b = capacity_b;
        let mut ans = 0;
        let mut i = 0;
        let mut j = plants.len() - 1;

        while i < j {
            if a < plants[i] {
                ans += 1;
                a = capacity_a;
            }
            a -= plants[i];

            if b < plants[j] {
                ans += 1;
                b = capacity_b;
            }
            b -= plants[j];

            i += 1;
            j -= 1;
        }

        if i == j && a.max(b) < plants[i] {
            ans += 1;
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

<p>Alice 和 Bob 打算给花园里的 <code>n</code> 株植物浇水。植物排成一行，从左到右进行标记，编号从 <code>0</code> 到 <code>n - 1</code> 。其中，第 <code>i</code> 株植物的位置是 <code>x = i</code> 。</p>

<p>每一株植物都需要浇特定量的水。Alice 和 Bob 每人有一个水罐，<strong>最初是满的 </strong>。他们按下面描述的方式完成浇水：</p>

<ul>
	<li>&nbsp;Alice 按 <strong>从左到右</strong> 的顺序给植物浇水，从植物 <code>0</code> 开始。Bob 按 <strong>从右到左</strong> 的顺序给植物浇水，从植物 <code>n - 1</code> 开始。他们 <strong>同时</strong> 给植物浇水。</li>
	<li>无论需要多少水，为每株植物浇水所需的时间都是相同的。</li>
	<li>如果 Alice/Bob 水罐中的水足以 <strong>完全</strong> 灌溉植物，他们 <strong>必须</strong> 给植物浇水。否则，他们 <strong>首先</strong>（立即）重新装满罐子，然后给植物浇水。</li>
	<li>如果 Alice 和 Bob 到达同一株植物，那么当前水罐中水 <strong>更多</strong> 的人会给这株植物浇水。如果他俩水量相同，那么 Alice 会给这株植物浇水。</li>
</ul>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>plants</code> ，数组由 <code>n</code> 个整数组成。其中，<code>plants[i]</code> 为第 <code>i</code> 株植物需要的水量。另有两个整数 <code>capacityA</code> 和&nbsp;<code>capacityB</code> 分别表示 Alice 和 Bob 水罐的容量。返回两人浇灌所有植物过程中重新灌满水罐的 <strong>次数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>plants = [2,2,3,3], capacityA = 5, capacityB = 5
<strong>输出：</strong>1
<strong>解释：</strong>
- 最初，Alice 和 Bob 的水罐中各有 5 单元水。
- Alice 给植物 0 浇水，Bob 给植物 3 浇水。
- Alice 和 Bob 现在分别剩下 3 单元和 2 单元水。
- Alice 有足够的水给植物 1 ，所以她直接浇水。Bob 的水不够给植物 2 ，所以他先重新装满水，再浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 0 + 1 + 0 = 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>plants = [2,2,3,3], capacityA = 3, capacityB = 4
<strong>输出：</strong>2
<strong>解释：</strong>
- 最初，Alice 的水罐中有 3 单元水，Bob 的水罐中有 4 单元水。
- Alice 给植物 0 浇水，Bob 给植物 3 浇水。
- Alice 和 Bob 现在都只有 1 单元水，并分别需要给植物 1 和植物 2 浇水。
- 由于他们的水量均不足以浇水，所以他们重新灌满水罐再进行浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 1 + 1 + 0 = 2 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>plants = [5], capacityA = 10, capacityB = 8
<strong>输出：</strong>0
<strong>解释：</strong>
- 只有一株植物
- Alice 的水罐有 10 单元水，Bob 的水罐有 8 单元水。因此 Alice 的水罐中水更多，她会给这株植物浇水。
所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == plants.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= plants[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>max(plants[i]) &lt;= capacityA, capacityB &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 模拟

我们用两个变量 $a$ 和 $b$ 分别表示 Alice 和 Bob 的水量，初始时 $a = \textit{capacityA}$, $b = \textit{capacityB}$。然后用两个指针 $i$ 和 $j$ 分别指向植物数组的头尾，然后模拟 Alice 和 Bob 从两端向中间浇水的过程。

当 $i < j$ 时，我们分别判断 Alice 和 Bob 的水量是否足够浇水，如果不够，我们就重新灌满水罐。然后更新 $a$ 和 $b$ 的水量，同时移动指针 $i$ 和 $j$。最后我们还需要判断 $i$ 和 $j$ 是否相等，如果相等，我们还需要判断 $\max(a, b)$ 是否小于植物的水量，如果小于，我们需要再次重新灌满水罐。

时间复杂度 $O(n)$，其中 $n$ 是植物数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        a, b = capacityA, capacityB
        ans = 0
        i, j = 0, len(plants) - 1
        while i < j:
            if a < plants[i]:
                ans += 1
                a = capacityA
            a -= plants[i]
            if b < plants[j]:
                ans += 1
                b = capacityB
            b -= plants[j]
            i, j = i + 1, j - 1
        ans += i == j and max(a, b) < plants[i]
        return ans
```

#### Java

```java
class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int a = capacityA, b = capacityB;
        int ans = 0;
        int i = 0, j = plants.length - 1;
        for (; i < j; ++i, --j) {
            if (a < plants[i]) {
                ++ans;
                a = capacityA;
            }
            a -= plants[i];
            if (b < plants[j]) {
                ++ans;
                b = capacityB;
            }
            b -= plants[j];
        }
        ans += i == j && Math.max(a, b) < plants[i] ? 1 : 0;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a = capacityA, b = capacityB;
        int ans = 0;
        int i = 0, j = plants.size() - 1;
        for (; i < j; ++i, --j) {
            if (a < plants[i]) {
                ++ans;
                a = capacityA;
            }
            a -= plants[i];
            if (b < plants[j]) {
                ++ans;
                b = capacityB;
            }
            b -= plants[j];
        }
        ans += i == j && max(a, b) < plants[i];
        return ans;
    }
};
```

#### Go

```go
func minimumRefill(plants []int, capacityA int, capacityB int) (ans int) {
	a, b := capacityA, capacityB
	i, j := 0, len(plants)-1
	for ; i < j; i, j = i+1, j-1 {
		if a < plants[i] {
			ans++
			a = capacityA
		}
		a -= plants[i]
		if b < plants[j] {
			ans++
			b = capacityB
		}
		b -= plants[j]
	}
	if i == j && max(a, b) < plants[i] {
		ans++
	}
	return
}
```

#### TypeScript

```ts
function minimumRefill(plants: number[], capacityA: number, capacityB: number): number {
    let [a, b] = [capacityA, capacityB];
    let ans = 0;
    let [i, j] = [0, plants.length - 1];
    for (; i < j; ++i, --j) {
        if (a < plants[i]) {
            ++ans;
            a = capacityA;
        }
        a -= plants[i];
        if (b < plants[j]) {
            ++ans;
            b = capacityB;
        }
        b -= plants[j];
    }
    ans += i === j && Math.max(a, b) < plants[i] ? 1 : 0;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_refill(plants: Vec<i32>, capacity_a: i32, capacity_b: i32) -> i32 {
        let mut a = capacity_a;
        let mut b = capacity_b;
        let mut ans = 0;
        let mut i = 0;
        let mut j = plants.len() - 1;

        while i < j {
            if a < plants[i] {
                ans += 1;
                a = capacity_a;
            }
            a -= plants[i];

            if b < plants[j] {
                ans += 1;
                b = capacity_b;
            }
            b -= plants[j];

            i += 1;
            j -= 1;
        }

        if i == j && a.max(b) < plants[i] {
            ans += 1;
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

# [2106. 摘水果](https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps){#2106}

{{< tabs "2106" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        ans = i = s = 0
        for j, (pj, fj) in enumerate(fruits):
            s += fj
            while (
                i <= j
                and pj
                - fruits[i][0]
                + min(abs(startPos - fruits[i][0]), abs(startPos - fruits[j][0]))
                > k
            ):
                s -= fruits[i][1]
                i += 1
            ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int ans = 0, s = 0;
        for (int i = 0, j = 0; j < fruits.length; ++j) {
            int pj = fruits[j][0], fj = fruits[j][1];
            s += fj;
            while (i <= j
                && pj - fruits[i][0]
                        + Math.min(Math.abs(startPos - fruits[i][0]), Math.abs(startPos - pj))
                    > k) {
                s -= fruits[i++][1];
            }
            ans = Math.max(ans, s);
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
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0, s = 0;
        for (int i = 0, j = 0; j < fruits.size(); ++j) {
            int pj = fruits[j][0], fj = fruits[j][1];
            s += fj;
            while (i <= j && pj - fruits[i][0] + min(abs(startPos - fruits[i][0]), abs(startPos - pj)) > k) {
                s -= fruits[i++][1];
            }
            ans = max(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTotalFruits(fruits [][]int, startPos int, k int) (ans int) {
	var s, i int
	for j, f := range fruits {
		s += f[1]
		for i <= j && f[0]-fruits[i][0]+min(abs(startPos-fruits[i][0]), abs(startPos-f[0])) > k {
			s -= fruits[i][1]
			i += 1
		}
		ans = max(ans, s)
	}
	return
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
function maxTotalFruits(fruits: number[][], startPos: number, k: number): number {
    let ans = 0;
    let s = 0;
    for (let i = 0, j = 0; j < fruits.length; ++j) {
        const [pj, fj] = fruits[j];
        s += fj;
        while (
            i <= j &&
            pj -
                fruits[i][0] +
                Math.min(Math.abs(startPos - fruits[i][0]), Math.abs(startPos - pj)) >
                k
        ) {
            s -= fruits[i++][1];
        }
        ans = Math.max(ans, s);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_total_fruits(fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        let mut ans = 0;
        let mut s = 0;
        let mut i = 0;
        for j in 0..fruits.len() {
            let pj = fruits[j][0];
            let fj = fruits[j][1];
            s += fj;
            while i <= j && pj - fruits[i][0] + std::cmp::min((start_pos - fruits[i][0]).abs(), (start_pos - pj).abs()) > k {
                s -= fruits[i][1];
                i += 1;
            }
            ans = ans.max(s)
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

<p>在一个无限的 x 坐标轴上，有许多水果分布在其中某些位置。给你一个二维整数数组 <code>fruits</code> ，其中 <code>fruits[i] = [position<sub>i</sub>, amount<sub>i</sub>]</code> 表示共有 <code>amount<sub>i</sub></code> 个水果放置在 <code>position<sub>i</sub></code> 上。<code>fruits</code> 已经按 <code>position<sub>i</sub></code> <strong>升序排列</strong> ，每个 <code>position<sub>i</sub></code> <strong>互不相同</strong> 。</p>

<p>另给你两个整数 <code>startPos</code> 和 <code>k</code> 。最初，你位于 <code>startPos</code> 。从任何位置，你可以选择 <strong>向左或者向右</strong> 走。在 x 轴上每移动 <strong>一个单位</strong> ，就记作 <strong>一步</strong> 。你总共可以走 <strong>最多</strong> <code>k</code> 步。你每达到一个位置，都会摘掉全部的水果，水果也将从该位置消失（不会再生）。</p>

<p>返回你可以摘到水果的 <strong>最大总数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2106.Maximum%20Fruits%20Harvested%20After%20at%20Most%20K%20Steps/images/1.png" style="width: 472px; height: 115px;">
<pre><strong>输入：</strong>fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
<strong>输出：</strong>9
<strong>解释：</strong>
最佳路线为：
- 向右移动到位置 6 ，摘到 3 个水果
- 向右移动到位置 8 ，摘到 6 个水果
移动 3 步，共摘到 3 + 6 = 9 个水果
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2106.Maximum%20Fruits%20Harvested%20After%20at%20Most%20K%20Steps/images/2.png" style="width: 512px; height: 129px;">
<pre><strong>输入：</strong>fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
<strong>输出：</strong>14
<strong>解释：</strong>
可以移动最多 k = 4 步，所以无法到达位置 0 和位置 10 。
最佳路线为：
- 在初始位置 5 ，摘到 7 个水果
- 向左移动到位置 4 ，摘到 1 个水果
- 向右移动到位置 6 ，摘到 2 个水果
- 向右移动到位置 7 ，摘到 4 个水果
移动 1 + 3 = 4 步，共摘到 7 + 1 + 2 + 4 = 14 个水果
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2106.Maximum%20Fruits%20Harvested%20After%20at%20Most%20K%20Steps/images/3.png" style="width: 476px; height: 100px;">
<pre><strong>输入：</strong>fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
<strong>输出：</strong>0
<strong>解释：</strong>
最多可以移动 k = 2 步，无法到达任一有水果的地方
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>fruits[i].length == 2</code></li>
	<li><code>0 &lt;= startPos, position<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
	<li>对于任意 <code>i &gt; 0</code> ，<code>position<sub>i-1</sub> &lt; position<sub>i</sub></code> 均成立（下标从 <strong>0</strong> 开始计数）</li>
	<li><code>1 &lt;= amount<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们不妨假设移动的位置区间为 $[l, r]$，开始位置为 $\textit{startPos}$，来看看如何算出移动的最小步数。根据 $\textit{startPos}$ 所处的位置，我们可以分为三种情况：

1. 如果 $\textit{startPos} \leq l$，那么就是从 $\textit{startPos}$ 一直向右移动到 $r$。移动的最小步数为 $r - \textit{startPos}$；
2. 如果 $\textit{startPos} \geq r$，那么就是从 $\textit{startPos}$ 一直向左移动到 $l$。移动的最小步数为 $\textit{startPos} - l$；
3. 如果 $l < \textit{startPos} < r$，那么可以从 $\textit{startPos}$ 向左移动到 $l$，再向右移动到 $r$；也可以从 $\textit{startPos}$ 向右移动到 $r$，再向左移动到 $l$。移动的最小步数为 $r - l + \min(\lvert \textit{startPos} - l \rvert, \lvert r - \textit{startPos} \rvert)$。

以上三种情况可以统一用式子 $r - l + \min(\lvert \textit{startPos} - l \rvert, \lvert r - \textit{startPos} \rvert)$ 表示。

假设我们固定区间右端点 $r$，向右移动左端点 $l$，我们来看看最小移动步数是怎么变化的。

1. 如果 $\textit{startPos} \leq l$，随着 $l$ 的增大，最小步数不会发生变化。
2. 如果 $\textit{startPos} > l$，随着 $l$ 的增大，最小步数会减小。

因此，随着 $l$ 的增大，最小移动步数一定是非严格单调递减的。基于此，我们可以使用双指针的方法，找出所有符合条件的最大区间，然后取所有符合条件的区间中水果总数最大的一个作为答案。

具体地，我们用两个指针 $i$ 和 $j$ 分别指向区间的左右下标，初始时 $i = j = 0$。另外用一个变量 $s$ 记录区间内的水果总数，初始时 $s = 0$。

每次我们将 $j$ 加入区间中，然后更新 $s = s + \textit{fruits}[j][1]$。如果此时区间内的最小步数 $\textit{fruits}[j][0] - \textit{fruits}[i][0] + \min(\lvert \textit{startPos} - \textit{fruits}[i][0] \rvert, \lvert \textit{startPos} - \textit{fruits}[j][0] \rvert)$ 大于 $k$，那么我们就将 $i$ 循环向右移动，直到 $i > j$ 或者区间内的最小步数小于等于 $k$。此时我们更新答案 $\textit{ans} = \max(\textit{ans}, s)$。继续移动 $j$，直到 $j$ 到达数组末尾。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        ans = i = s = 0
        for j, (pj, fj) in enumerate(fruits):
            s += fj
            while (
                i <= j
                and pj
                - fruits[i][0]
                + min(abs(startPos - fruits[i][0]), abs(startPos - fruits[j][0]))
                > k
            ):
                s -= fruits[i][1]
                i += 1
            ans = max(ans, s)
        return ans
```

#### Java

```java
class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int ans = 0, s = 0;
        for (int i = 0, j = 0; j < fruits.length; ++j) {
            int pj = fruits[j][0], fj = fruits[j][1];
            s += fj;
            while (i <= j
                && pj - fruits[i][0]
                        + Math.min(Math.abs(startPos - fruits[i][0]), Math.abs(startPos - pj))
                    > k) {
                s -= fruits[i++][1];
            }
            ans = Math.max(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0, s = 0;
        for (int i = 0, j = 0; j < fruits.size(); ++j) {
            int pj = fruits[j][0], fj = fruits[j][1];
            s += fj;
            while (i <= j && pj - fruits[i][0] + min(abs(startPos - fruits[i][0]), abs(startPos - pj)) > k) {
                s -= fruits[i++][1];
            }
            ans = max(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func maxTotalFruits(fruits [][]int, startPos int, k int) (ans int) {
	var s, i int
	for j, f := range fruits {
		s += f[1]
		for i <= j && f[0]-fruits[i][0]+min(abs(startPos-fruits[i][0]), abs(startPos-f[0])) > k {
			s -= fruits[i][1]
			i += 1
		}
		ans = max(ans, s)
	}
	return
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
function maxTotalFruits(fruits: number[][], startPos: number, k: number): number {
    let ans = 0;
    let s = 0;
    for (let i = 0, j = 0; j < fruits.length; ++j) {
        const [pj, fj] = fruits[j];
        s += fj;
        while (
            i <= j &&
            pj -
                fruits[i][0] +
                Math.min(Math.abs(startPos - fruits[i][0]), Math.abs(startPos - pj)) >
                k
        ) {
            s -= fruits[i++][1];
        }
        ans = Math.max(ans, s);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_total_fruits(fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        let mut ans = 0;
        let mut s = 0;
        let mut i = 0;
        for j in 0..fruits.len() {
            let pj = fruits[j][0];
            let fj = fruits[j][1];
            s += fj;
            while i <= j && pj - fruits[i][0] + std::cmp::min((start_pos - fruits[i][0]).abs(), (start_pos - pj).abs()) > k {
                s -= fruits[i][1];
                i += 1;
            }
            ans = ans.max(s)
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

# [2107. 分享 K 个糖果后独特口味的数量 🔒](https://leetcode.cn/problems/number-of-unique-flavors-after-sharing-k-candies){#2107}

{{< tabs "2107" >}}

{{% tab "python" %}}
```python
class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        cnt = Counter(candies[k:])
        ans = len(cnt)
        for i in range(k, len(candies)):
            cnt[candies[i - k]] += 1
            cnt[candies[i]] -= 1
            if cnt[candies[i]] == 0:
                cnt.pop(candies[i])
            ans = max(ans, len(cnt))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shareCandies(int[] candies, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int n = candies.length;
        for (int i = k; i < n; ++i) {
            cnt.merge(candies[i], 1, Integer::sum);
        }
        int ans = cnt.size();
        for (int i = k; i < n; ++i) {
            cnt.merge(candies[i - k], 1, Integer::sum);
            if (cnt.merge(candies[i], -1, Integer::sum) == 0) {
                cnt.remove(candies[i]);
            }
            ans = Math.max(ans, cnt.size());
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
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> cnt;
        int n = candies.size();
        for (int i = k; i < n; ++i) {
            ++cnt[candies[i]];
        }
        int ans = cnt.size();
        for (int i = k; i < n; ++i) {
            ++cnt[candies[i - k]];
            if (--cnt[candies[i]] == 0) {
                cnt.erase(candies[i]);
            }
            ans = max(ans, (int) cnt.size());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shareCandies(candies []int, k int) (ans int) {
	cnt := map[int]int{}
	for _, c := range candies[k:] {
		cnt[c]++
	}
	ans = len(cnt)
	for i := k; i < len(candies); i++ {
		cnt[candies[i-k]]++
		cnt[candies[i]]--
		if cnt[candies[i]] == 0 {
			delete(cnt, candies[i])
		}
		ans = max(ans, len(cnt))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shareCandies(candies: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    for (const x of candies.slice(k)) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    let ans = cnt.size;
    for (let i = k; i < candies.length; ++i) {
        cnt.set(candies[i - k], (cnt.get(candies[i - k]) || 0) + 1);
        cnt.set(candies[i], (cnt.get(candies[i]) || 0) - 1);
        if (cnt.get(candies[i]) === 0) {
            cnt.delete(candies[i]);
        }
        ans = Math.max(ans, cnt.size);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn share_candies(candies: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        let n = candies.len();

        for i in k as usize..n {
            *cnt.entry(candies[i]).or_insert(0) += 1;
        }

        let mut ans = cnt.len() as i32;

        for i in k as usize..n {
            *cnt.entry(candies[i - (k as usize)]).or_insert(0) += 1;
            if let Some(x) = cnt.get_mut(&candies[i]) {
                *x -= 1;
                if *x == 0 {
                    cnt.remove(&candies[i]);
                }
            }

            ans = ans.max(cnt.len() as i32);
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

<p>您将获得一个 <strong>从0开始的</strong> 整数数组 <code>candies</code> ，其中 <code>candies[i]</code>&nbsp;表示第 <code>i</code> 个糖果的味道。你妈妈想让你和你妹妹分享这些糖果，给她 <code>k</code> 个 <strong>连续 </strong>的糖果，但你想保留尽可能多的糖果口味。<br />
在与妹妹分享后，返回 <strong>最多</strong> 可保留的 <strong>独特</strong> 口味的糖果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> candies = [1,<u>2,2,3</u>,4,3], k = 3
<strong>输出:</strong> 3
<strong>解释:</strong>
将[1,3]（含[2,2,3]）范围内的糖果加入[2,2,3]口味。
你可以吃各种口味的糖果[1,4,3]。
有3种独特的口味，所以返回3。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> candies = [2,2,2,<u>2,3</u>,3], k = 2
<strong>输出:</strong> 2
<strong>解释:</strong>
在[3,4]范围内（含[2,3]）的糖果中加入[2,3]口味。
你可以吃各种口味的糖果[2,2,2,3]。
有两种独特的口味，所以返回2。
请注意，你也可以分享口味为[2,2]的糖果，吃口味为[2,2,3,3]的糖果。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> candies = [2,4,5], k = 0
<strong>输出:</strong> 3
<strong>解释:</strong>
你不必给任何糖果。
你可以吃各种口味的糖果[2,4,5]。
有3种独特的口味，所以返回3。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= candies.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candies[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= candies.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 哈希表

我们可以维护一个大小为 $k$ 的滑动窗口，窗口外的糖果为自己的，窗口内的 $k$ 个糖果分给妹妹和妈妈。我们可以用哈希表 $cnt$ 记录窗口外的糖果口味以及对应的数量。

初始时，哈希表 $cnt$ 中存储的是 $candies[k]$ 到 $candies[n-1]$ 的糖果口味以及对应的数量。此时糖果口味的种类数为哈希表 $cnt$ 的大小，即 $ans = cnt.size()$。

接下来，我们遍历 $[k,..n-1]$ 范围内的糖果，将当前糖果 $candies[i]$ 加入窗口内，同时将窗口左侧的糖果 $candies[i-k]$ 移出窗口外。然后我们更新哈希表 $cnt$，并且更新糖果口味的种类数 $ans$ 为 $max(ans, cnt.size())$。

遍历完所有糖果后，我们即可得到最多可保留的独特口味的糖果。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为糖果的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        cnt = Counter(candies[k:])
        ans = len(cnt)
        for i in range(k, len(candies)):
            cnt[candies[i - k]] += 1
            cnt[candies[i]] -= 1
            if cnt[candies[i]] == 0:
                cnt.pop(candies[i])
            ans = max(ans, len(cnt))
        return ans
```

#### Java

```java
class Solution {
    public int shareCandies(int[] candies, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int n = candies.length;
        for (int i = k; i < n; ++i) {
            cnt.merge(candies[i], 1, Integer::sum);
        }
        int ans = cnt.size();
        for (int i = k; i < n; ++i) {
            cnt.merge(candies[i - k], 1, Integer::sum);
            if (cnt.merge(candies[i], -1, Integer::sum) == 0) {
                cnt.remove(candies[i]);
            }
            ans = Math.max(ans, cnt.size());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> cnt;
        int n = candies.size();
        for (int i = k; i < n; ++i) {
            ++cnt[candies[i]];
        }
        int ans = cnt.size();
        for (int i = k; i < n; ++i) {
            ++cnt[candies[i - k]];
            if (--cnt[candies[i]] == 0) {
                cnt.erase(candies[i]);
            }
            ans = max(ans, (int) cnt.size());
        }
        return ans;
    }
};
```

#### Go

```go
func shareCandies(candies []int, k int) (ans int) {
	cnt := map[int]int{}
	for _, c := range candies[k:] {
		cnt[c]++
	}
	ans = len(cnt)
	for i := k; i < len(candies); i++ {
		cnt[candies[i-k]]++
		cnt[candies[i]]--
		if cnt[candies[i]] == 0 {
			delete(cnt, candies[i])
		}
		ans = max(ans, len(cnt))
	}
	return
}
```

#### TypeScript

```ts
function shareCandies(candies: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    for (const x of candies.slice(k)) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    let ans = cnt.size;
    for (let i = k; i < candies.length; ++i) {
        cnt.set(candies[i - k], (cnt.get(candies[i - k]) || 0) + 1);
        cnt.set(candies[i], (cnt.get(candies[i]) || 0) - 1);
        if (cnt.get(candies[i]) === 0) {
            cnt.delete(candies[i]);
        }
        ans = Math.max(ans, cnt.size);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn share_candies(candies: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        let n = candies.len();

        for i in k as usize..n {
            *cnt.entry(candies[i]).or_insert(0) += 1;
        }

        let mut ans = cnt.len() as i32;

        for i in k as usize..n {
            *cnt.entry(candies[i - (k as usize)]).or_insert(0) += 1;
            if let Some(x) = cnt.get_mut(&candies[i]) {
                *x -= 1;
                if *x == 0 {
                    cnt.remove(&candies[i]);
                }
            }

            ans = ans.max(cnt.len() as i32);
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

# [2108. 找出数组中的第一个回文字符串](https://leetcode.cn/problems/find-first-palindromic-string-in-the-array){#2108}

{{< tabs "2108" >}}

{{% tab "python" %}}
```python
class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        return next((w for w in words if w == w[::-1]), "")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String firstPalindrome(String[] words) {
        for (var w : words) {
            boolean ok = true;
            for (int i = 0, j = w.length() - 1; i < j && ok; ++i, --j) {
                if (w.charAt(i) != w.charAt(j)) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
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
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words) {
            bool ok = true;
            for (int i = 0, j = w.size() - 1; i < j; ++i, --j) {
                if (w[i] != w[j]) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func firstPalindrome(words []string) string {
	for _, w := range words {
		ok := true
		for i, j := 0, len(w)-1; i < j && ok; i, j = i+1, j-1 {
			if w[i] != w[j] {
				ok = false
			}
		}
		if ok {
			return w
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function firstPalindrome(words: string[]): string {
    return words.find(w => w === w.split('').reverse().join('')) || '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        for w in words {
            if w == w.chars().rev().collect::<String>() {
                return w;
            }
        }
        String::new()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i < wordsSize; ++i) {
        char* w = words[i];
        int len = strlen(w);
        bool ok = true;
        for (int j = 0, k = len - 1; j < k && ok; ++j, --k) {
            if (w[j] != w[k]) {
                ok = false;
            }
        }
        if (ok) {
            return w;
        }
    }
    return "";
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code> ，找出并返回数组中的 <strong>第一个回文字符串</strong> 。如果不存在满足要求的字符串，返回一个 <strong>空字符串</strong><em> </em><code>""</code> 。</p>

<p><strong>回文字符串</strong> 的定义为：如果一个字符串正着读和反着读一样，那么该字符串就是一个 <strong>回文字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["abc","car","ada","racecar","cool"]
<strong>输出：</strong>"ada"
<strong>解释：</strong>第一个回文字符串是 "ada" 。
注意，"racecar" 也是回文字符串，但它不是第一个。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["notapalindrome","racecar"]
<strong>输出：</strong>"racecar"
<strong>解释：</strong>第一个也是唯一一个回文字符串是 "racecar" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["def","ghi"]
<strong>输出：</strong>""
<strong>解释：</strong>不存在回文字符串，所以返回一个空字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历数组 `words`，对于每个字符串 `w`，判断其是否为回文字符串，如果是，则返回 `w`，否则继续遍历。

判断一个字符串是否为回文字符串，可以使用双指针，分别指向字符串的首尾，向中间移动，判断对应的字符是否相等。如果遍历完整个字符串，都没有发现不相等的字符，则该字符串为回文字符串。

时间复杂度 $O(L)$，其中 $L$ 为数组 `words` 中所有字符串的长度之和。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        return next((w for w in words if w == w[::-1]), "")
```

#### Java

```java
class Solution {
    public String firstPalindrome(String[] words) {
        for (var w : words) {
            boolean ok = true;
            for (int i = 0, j = w.length() - 1; i < j && ok; ++i, --j) {
                if (w.charAt(i) != w.charAt(j)) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
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
    string firstPalindrome(vector<string>& words) {
        for (auto& w : words) {
            bool ok = true;
            for (int i = 0, j = w.size() - 1; i < j; ++i, --j) {
                if (w[i] != w[j]) {
                    ok = false;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
};
```

#### Go

```go
func firstPalindrome(words []string) string {
	for _, w := range words {
		ok := true
		for i, j := 0, len(w)-1; i < j && ok; i, j = i+1, j-1 {
			if w[i] != w[j] {
				ok = false
			}
		}
		if ok {
			return w
		}
	}
	return ""
}
```

#### TypeScript

```ts
function firstPalindrome(words: string[]): string {
    return words.find(w => w === w.split('').reverse().join('')) || '';
}
```

#### Rust

```rust
impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        for w in words {
            if w == w.chars().rev().collect::<String>() {
                return w;
            }
        }
        String::new()
    }
}
```

#### C

```c
char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i < wordsSize; ++i) {
        char* w = words[i];
        int len = strlen(w);
        bool ok = true;
        for (int j = 0, k = len - 1; j < k && ok; ++j, --k) {
            if (w[j] != w[k]) {
                ok = false;
            }
        }
        if (ok) {
            return w;
        }
    }
    return "";
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2109. 向字符串添加空格](https://leetcode.cn/problems/adding-spaces-to-a-string){#2109}

{{< tabs "2109" >}}

{{% tab "python" %}}
```python
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        j = 0
        for i, c in enumerate(s):
            if j < len(spaces) and i == spaces[j]:
                ans.append(' ')
                j += 1
            ans.append(c)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (j < spaces.length && i == spaces[j]) {
                ans.append(' ');
                ++j;
            }
            ans.append(s.charAt(i));
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
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (j < spaces.size() && i == spaces[j]) {
                ans += ' ';
                ++j;
            }
            ans += s[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addSpaces(s string, spaces []int) string {
	var ans []byte
	for i, j := 0, 0; i < len(s); i++ {
		if j < len(spaces) && i == spaces[j] {
			ans = append(ans, ' ')
			j++
		}
		ans = append(ans, s[i])
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addSpaces(s: string, spaces: number[]): string {
    const ans: string[] = [];
    for (let i = 0, j = 0; i < s.length; i++) {
        if (i === spaces[j]) {
            ans.push(' ');
            j++;
        }
        ans.push(s[i]);
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，以及一个下标从 <strong>0</strong> 开始的整数数组 <code>spaces</code> 。</p>

<p>数组 <code>spaces</code> 描述原字符串中需要添加空格的下标。每个空格都应该插入到给定索引处的字符值 <strong>之前</strong> 。</p>

<ul>
	<li>例如，<code>s = "EnjoyYourCoffee"</code> 且 <code>spaces = [5, 9]</code> ，那么我们需要在 <code>'Y'</code> 和 <code>'C'</code> 之前添加空格，这两个字符分别位于下标 <code>5</code> 和下标 <code>9</code> 。因此，最终得到 <code>"Enjoy <em><strong>Y</strong></em>our <em><strong>C</strong></em>offee"</code> 。</li>
</ul>

<p>请你添加空格，并返回修改后的字符串<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
<strong>输出：</strong>"Leetcode Helps Me Learn"
<strong>解释：</strong>
下标 8、13 和 15 对应 "Leetcode<em><strong>H</strong></em>elps<em><strong>M</strong></em>e<em><strong>L</strong></em>earn" 中加粗斜体字符。
接着在这些字符前添加空格。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "icodeinpython", spaces = [1,5,7,9]
<strong>输出：</strong>"i code in py thon"
<strong>解释：</strong>
下标 1、5、7 和 9 对应 "i<em><strong>c</strong></em>ode<em><strong>i</strong></em>n<em><strong>p</strong></em>y<em><strong>t</strong></em>hon" 中加粗斜体字符。
接着在这些字符前添加空格。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "spacing", spaces = [0,1,2,3,4,5,6]
<strong>输出：</strong>" s p a c i n g"
<strong>解释：</strong>
字符串的第一个字符前可以添加空格。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由大小写英文字母组成</li>
	<li><code>1 &lt;= spaces.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= spaces[i] &lt;= s.length - 1</code></li>
	<li><code>spaces</code> 中的所有值 <strong>严格递增</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以用双指针 $i$ 和 $j$ 分别指向字符串 $s$ 和数组 $\textit{spaces}$ 的头部，然后从头到尾遍历字符串 $s$，当 $i$ 等于 $\textit{spaces}[j]$ 时，我们往结果字符串中添加一个空格，然后 $j$ 自增 $1$。接下来，我们将 $s[i]$ 添加到结果字符串中，然后 $i$ 自增 $1$。继续这个过程，直到遍历完字符串 $s$。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是字符串 $s$ 和数组 $spaces$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        j = 0
        for i, c in enumerate(s):
            if j < len(spaces) and i == spaces[j]:
                ans.append(' ')
                j += 1
            ans.append(c)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (j < spaces.length && i == spaces[j]) {
                ans.append(' ');
                ++j;
            }
            ans.append(s.charAt(i));
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (j < spaces.size() && i == spaces[j]) {
                ans += ' ';
                ++j;
            }
            ans += s[i];
        }
        return ans;
    }
};
```

#### Go

```go
func addSpaces(s string, spaces []int) string {
	var ans []byte
	for i, j := 0, 0; i < len(s); i++ {
		if j < len(spaces) && i == spaces[j] {
			ans = append(ans, ' ')
			j++
		}
		ans = append(ans, s[i])
	}
	return string(ans)
}
```

#### TypeScript

```ts
function addSpaces(s: string, spaces: number[]): string {
    const ans: string[] = [];
    for (let i = 0, j = 0; i < s.length; i++) {
        if (i === spaces[j]) {
            ans.push(' ');
            j++;
        }
        ans.push(s[i]);
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
