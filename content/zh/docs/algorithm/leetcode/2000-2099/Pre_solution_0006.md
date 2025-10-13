---
title: "2050_并行课程 III"
date: 2025-10-08T18:38:57+08:00
weight: 6
tags: [二分查找, 前缀和, 动态规划, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 广度优先搜索, 拓扑排序, 排序, 数据库, 数组, 模拟, 计数, 链表]
---

{{< markmap >}}
### [2050_并行课程 III](#2050)
#### [图](#2050)
#### [拓扑排序](#2050)
#### [数组](#2050)
#### [动态规划](#2050)
### [2051_商店中每个成员的级别 🔒](#2051)
#### [数据库](#2051)
### [2052_将句子分隔成行的最低成本 🔒](#2052)
#### [数组](#2052)
#### [动态规划](#2052)
### [2053_数组中第 K 个独一无二的字符串](#2053)
#### [数组](#2053)
#### [哈希表](#2053)
#### [字符串](#2053)
#### [计数](#2053)
### [2054_两个最好的不重叠活动](#2054)
#### [数组](#2054)
#### [二分查找](#2054)
#### [动态规划](#2054)
#### [排序](#2054)
#### [堆（优先队列）](#2054)
### [2055_蜡烛之间的盘子](#2055)
#### [数组](#2055)
#### [字符串](#2055)
#### [二分查找](#2055)
#### [前缀和](#2055)
### [2056_棋盘上有效移动组合的数目](#2056)
#### [数组](#2056)
#### [字符串](#2056)
#### [回溯](#2056)
#### [模拟](#2056)
### [2057_值相等的最小索引](#2057)
#### [数组](#2057)
### [2058_找出临界点之间的最小和最大距离](#2058)
#### [链表](#2058)
### [2059_转化数字的最小运算数](#2059)
#### [广度优先搜索](#2059)
#### [数组](#2059)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2050_并行课程 III
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 动态规划
---
### 2051_商店中每个成员的级别 🔒
___
#### 数据库
---
### 2052_将句子分隔成行的最低成本 🔒
___
#### 数组
___
#### 动态规划
---
### 2053_数组中第 K 个独一无二的字符串
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2054_两个最好的不重叠活动
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 排序
___
#### 堆（优先队列）
---
### 2055_蜡烛之间的盘子
___
#### 数组
___
#### 字符串
___
#### 二分查找
___
#### 前缀和
---
### 2056_棋盘上有效移动组合的数目
___
#### 数组
___
#### 字符串
___
#### 回溯
___
#### 模拟
---
### 2057_值相等的最小索引
___
#### 数组
---
### 2058_找出临界点之间的最小和最大距离
___
#### 链表
---
### 2059_转化数字的最小运算数
___
#### 广度优先搜索
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 拓扑排序 | 排序 | 数据库 |
| 数组 | 模拟 | 计数 |
| 链表 |  |  |

# [2050. 并行课程 III](https://leetcode.cn/problems/parallel-courses-iii){#2050}

{{< tabs "2050" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        g = defaultdict(list)
        indeg = [0] * n
        for a, b in relations:
            g[a - 1].append(b - 1)
            indeg[b - 1] += 1
        q = deque()
        f = [0] * n
        ans = 0
        for i, (v, t) in enumerate(zip(indeg, time)):
            if v == 0:
                q.append(i)
                f[i] = t
                ans = max(ans, t)
        while q:
            i = q.popleft()
            for j in g[i]:
                f[j] = max(f[j], f[i] + time[j])
                ans = max(ans, f[j])
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];
        for (int[] e : relations) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            ++indeg[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        int[] f = new int[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = indeg[i], t = time[i];
            if (v == 0) {
                q.offer(i);
                f[i] = t;
                ans = Math.max(ans, t);
            }
        }
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            for (int j : g[i]) {
                f[j] = Math.max(f[j], f[i] + time[j]);
                ans = Math.max(ans, f[j]);
                if (--indeg[j] == 0) {
                    q.offer(j);
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
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& e : relations) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            ++indeg[b];
        }
        queue<int> q;
        vector<int> f(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = indeg[i], t = time[i];
            if (v == 0) {
                q.push(i);
                f[i] = t;
                ans = max(ans, t);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
                f[j] = max(f[j], f[i] + time[j]);
                ans = max(ans, f[j]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(n int, relations [][]int, time []int) int {
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, e := range relations {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		indeg[b]++
	}
	f := make([]int, n)
	q := []int{}
	ans := 0
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
			f[i] = time[i]
			ans = max(ans, time[i])
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
			f[j] = max(f[j], f[i]+time[j])
			ans = max(ans, f[j])
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTime(n: number, relations: number[][], time: number[]): number {
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => []);
    const indeg: number[] = Array(n).fill(0);
    for (const [a, b] of relations) {
        g[a - 1].push(b - 1);
        ++indeg[b - 1];
    }
    const q: number[] = [];
    const f: number[] = Array(n).fill(0);
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
            f[i] = time[i];
            ans = Math.max(ans, f[i]);
        }
    }
    while (q.length > 0) {
        const i = q.shift()!;
        for (const j of g[i]) {
            f[j] = Math.max(f[j], f[i] + time[j]);
            ans = Math.max(ans, f[j]);
            if (--indeg[j] === 0) {
                q.push(j);
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

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示有&nbsp;<code>n</code>&nbsp;节课，课程编号从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;。同时给你一个二维整数数组&nbsp;<code>relations</code>&nbsp;，其中&nbsp;<code>relations[j] = [prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code>&nbsp;，表示课程&nbsp;<code>prevCourse<sub>j</sub></code>&nbsp;必须在课程&nbsp;<code>nextCourse<sub>j</sub></code>&nbsp;<strong>之前</strong>&nbsp;完成（先修课的关系）。同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>time</code>&nbsp;，其中&nbsp;<code>time[i]</code>&nbsp;表示完成第&nbsp;<code>(i+1)</code>&nbsp;门课程需要花费的 <strong>月份</strong>&nbsp;数。</p>

<p>请你根据以下规则算出完成所有课程所需要的 <strong>最少</strong>&nbsp;月份数：</p>

<ul>
	<li>如果一门课的所有先修课都已经完成，你可以在 <strong>任意</strong>&nbsp;时间开始这门课程。</li>
	<li>你可以&nbsp;<strong>同时</strong>&nbsp;上&nbsp;<strong>任意门课程</strong>&nbsp;。</li>
</ul>

<p>请你返回完成所有课程所需要的 <strong>最少</strong>&nbsp;月份数。</p>

<p><strong>注意：</strong>测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2050.Parallel%20Courses%20III/images/ex1.png" style="width: 392px; height: 232px;"></strong></p>

<pre><strong>输入：</strong>n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
<b>输出：</b>8
<b>解释：</b>上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
你可以在月份 0 同时开始课程 1 和 2 。
课程 1 花费 3 个月，课程 2 花费 2 个月。
所以，最早开始课程 3 的时间是月份 3 ，完成所有课程所需时间为 3 + 5 = 8 个月。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2050.Parallel%20Courses%20III/images/ex2.png" style="width: 500px; height: 365px;"></strong></p>

<pre><b>输入：</b>n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
<b>输出：</b>12
<b>解释：</b>上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
你可以在月份 0 同时开始课程 1 ，2 和 3 。
在月份 1，2 和 3 分别完成这三门课程。
课程 4 需在课程 3 之后开始，也就是 3 个月后。课程 4 在 3 + 4 = 7 月完成。
课程 5 需在课程 1，2，3 和 4 之后开始，也就是在 max(1,2,3,7) = 7 月开始。
所以完成所有课程所需的最少时间为 7 + 5 = 12 个月。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= relations.length &lt;= min(n * (n - 1) / 2, 5 * 10<sup>4</sup>)</code></li>
	<li><code>relations[j].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>j</sub>, nextCourse<sub>j</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>j</sub> != nextCourse<sub>j</sub></code></li>
	<li>所有的先修课程对&nbsp;<code>[prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code>&nbsp;都是 <strong>互不相同</strong>&nbsp;的。</li>
	<li><code>time.length == n</code></li>
	<li><code>1 &lt;= time[i] &lt;= 10<sup>4</sup></code></li>
	<li>先修课程图是一个有向无环图。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序 + 动态规划

我们首先根据给定的先修课程关系，构建出一个有向无环图，对该图进行拓扑排序，然后根据拓扑排序的结果，使用动态规划求出完成所有课程所需要的最少时间。

我们定义以下几个数据结构或变量：

-   邻接表 $g$ 存储有向无环图，同时使用一个数组 $indeg$ 存储每个节点的入度；
-   队列 $q$ 存储所有入度为 $0$ 的节点；
-   数组 $f$ 存储每个节点的最早完成时间，初始时 $f[i] = 0$；
-   变量 $ans$ 记录最终的答案，初始时 $ans = 0$；

当 $q$ 非空时，依次取出队首节点 $i$，遍历 $g[i]$ 中的每个节点 $j$，更新 $f[j] = \max(f[j], f[i] + time[j])$，同时更新 $ans = \max(ans, f[j])$，并将 $j$ 的入度减 $1$，如果此时 $j$ 的入度为 $0$，则将 $j$ 加入队列 $q$ 中；

最终返回 $ans$。

时间复杂度 $O(m + n)$，空间复杂度 $O(m + n)$。其中 $m$ 是数组 $relations$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        g = defaultdict(list)
        indeg = [0] * n
        for a, b in relations:
            g[a - 1].append(b - 1)
            indeg[b - 1] += 1
        q = deque()
        f = [0] * n
        ans = 0
        for i, (v, t) in enumerate(zip(indeg, time)):
            if v == 0:
                q.append(i)
                f[i] = t
                ans = max(ans, t)
        while q:
            i = q.popleft()
            for j in g[i]:
                f[j] = max(f[j], f[i] + time[j])
                ans = max(ans, f[j])
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return ans
```

#### Java

```java
class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];
        for (int[] e : relations) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            ++indeg[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        int[] f = new int[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = indeg[i], t = time[i];
            if (v == 0) {
                q.offer(i);
                f[i] = t;
                ans = Math.max(ans, t);
            }
        }
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            for (int j : g[i]) {
                f[j] = Math.max(f[j], f[i] + time[j]);
                ans = Math.max(ans, f[j]);
                if (--indeg[j] == 0) {
                    q.offer(j);
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
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& e : relations) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            ++indeg[b];
        }
        queue<int> q;
        vector<int> f(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = indeg[i], t = time[i];
            if (v == 0) {
                q.push(i);
                f[i] = t;
                ans = max(ans, t);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
                f[j] = max(f[j], f[i] + time[j]);
                ans = max(ans, f[j]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumTime(n int, relations [][]int, time []int) int {
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, e := range relations {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		indeg[b]++
	}
	f := make([]int, n)
	q := []int{}
	ans := 0
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
			f[i] = time[i]
			ans = max(ans, time[i])
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
			f[j] = max(f[j], f[i]+time[j])
			ans = max(ans, f[j])
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumTime(n: number, relations: number[][], time: number[]): number {
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => []);
    const indeg: number[] = Array(n).fill(0);
    for (const [a, b] of relations) {
        g[a - 1].push(b - 1);
        ++indeg[b - 1];
    }
    const q: number[] = [];
    const f: number[] = Array(n).fill(0);
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
            f[i] = time[i];
            ans = Math.max(ans, f[i]);
        }
    }
    while (q.length > 0) {
        const i = q.shift()!;
        for (const j of g[i]) {
            f[j] = Math.max(f[j], f[i] + time[j]);
            ans = Math.max(ans, f[j]);
            if (--indeg[j] === 0) {
                q.push(j);
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

# [2051. 商店中每个成员的级别 🔒](https://leetcode.cn/problems/the-category-of-each-member-in-the-store){#2051}

{{< tabs "2051" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    m.member_id,
    name,
    CASE
        WHEN COUNT(v.visit_id) = 0 THEN 'Bronze'
        WHEN 100 * COUNT(charged_amount) / COUNT(v.visit_id) >= 80 THEN 'Diamond'
        WHEN 100 * COUNT(charged_amount) / COUNT(v.visit_id) >= 50 THEN 'Gold'
        ELSE 'Silver'
    END AS category
FROM
    Members AS m
    LEFT JOIN Visits AS v ON m.member_id = v.member_id
    LEFT JOIN Purchases AS p ON v.visit_id = p.visit_id
GROUP BY member_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Members</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| member_id   | int     |
| name        | varchar |
+-------------+---------+
member_id 是该表的主键。
该表的每一行都表示成员的名称和 ID。
</pre>

<p>&nbsp;</p>

<p>表: <code>Visits</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| visit_id    | int  |
| member_id   | int  |
| visit_date  | date |
+-------------+------+
visit_id 是该表的主键。
member_id 是 Members 表中 member_id 的外键。
该表的每一行都包含关于访问商店的日期和访问该商店的成员的信息。
</pre>

<p>&nbsp;</p>

<p>表: <code>Purchases</code></p>

<pre>
+----------------+------+
| Column Name    | Type |
+----------------+------+
| visit_id       | int  |
| charged_amount | int  |
+----------------+------+
visit_id 是该表的主键。
visit_id 是访问表 visit_id 的外键。
该表的每一行都包含了关于在商店中消费的信息。
</pre>

<p>&nbsp;</p>

<p>一个商店想对其成员进行分类。有三个层次:</p>

<ul>
	<li><strong>"钻石"</strong>: 如果转换率&nbsp;<strong>大于或等于</strong> <code>80</code>.</li>
	<li><strong>"黄金"</strong>: 如果转换率&nbsp;<strong>大于或等于</strong> <code>50</code> 且小于 <code>80</code>.</li>
	<li><strong>"白银"</strong>: 如果转化率 <strong>小于</strong> <code>50</code>.</li>
	<li><strong>"青铜"</strong>: 如果该成员从未访问过该商店。</li>
</ul>

<p>成员的&nbsp;<strong>转化率&nbsp;</strong>为 <code>(100 * 该会员的购买总数) / 该成员的总访问次数</code>.</p>

<p>编写一个 SQL 来查询每个成员的 id、名称和类别。</p>

<p data-group="1-1">以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Members 表:
+-----------+---------+
| member_id | name    |
+-----------+---------+
| 9         | Alice   |
| 11        | Bob     |
| 3         | Winston |
| 8         | Hercy   |
| 1         | Narihan |
+-----------+---------+
Visits 表:
+----------+-----------+------------+
| visit_id | member_id | visit_date |
+----------+-----------+------------+
| 22       | 11        | 2021-10-28 |
| 16       | 11        | 2021-01-12 |
| 18       | 9         | 2021-12-10 |
| 19       | 3         | 2021-10-19 |
| 12       | 11        | 2021-03-01 |
| 17       | 8         | 2021-05-07 |
| 21       | 9         | 2021-05-12 |
+----------+-----------+------------+
Purchases 表:
+----------+----------------+
| visit_id | charged_amount |
+----------+----------------+
| 12       | 2000           |
| 18       | 9000           |
| 17       | 7000           |
+----------+----------------+
<strong>输出:</strong> 
+-----------+---------+----------+
| member_id | name    | category |
+-----------+---------+----------+
| 1         | Narihan | Bronze   |
| 3         | Winston | Silver   |
| 8         | Hercy   | Diamond  |
| 9         | Alice   | Gold     |
| 11        | Bob     | Silver   |
+-----------+---------+----------+
<strong>解释:</strong> 
- id = 1 的成员 Narihan 没有访问过该商店。她获得了铜奖。
- id = 3 的成员 Winston 访问了商店一次，但没有购买任何东西。转化率=(100 * 0)/ 1 = 0。他获得了银奖。
- id = 8 的成员 Hercy 访问商店一次，购买一次。转化率=(100 * 1)/ 1 = 1。他获得了钻石奖。
- id = 9 的成员 Alice 访问了商店两次，购买了一次。转化率=(100 * 1)/ 2 = 50。她获得了金奖。
- id = 11 的用户 Bob 访问了商店三次，购买了一次。转化率=(100 * 1)/ 3 = 33.33。他获得了银奖。</pre>

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
    m.member_id,
    name,
    CASE
        WHEN COUNT(v.visit_id) = 0 THEN 'Bronze'
        WHEN 100 * COUNT(charged_amount) / COUNT(v.visit_id) >= 80 THEN 'Diamond'
        WHEN 100 * COUNT(charged_amount) / COUNT(v.visit_id) >= 50 THEN 'Gold'
        ELSE 'Silver'
    END AS category
FROM
    Members AS m
    LEFT JOIN Visits AS v ON m.member_id = v.member_id
    LEFT JOIN Purchases AS p ON v.visit_id = p.visit_id
GROUP BY member_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2052. 将句子分隔成行的最低成本 🔒](https://leetcode.cn/problems/minimum-cost-to-separate-sentence-into-rows){#2052}

{{< tabs "2052" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, sentence: str, k: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if s[n] - s[i] + n - i - 1 <= k:
                return 0
            ans = inf
            j = i + 1
            while j < n and (m := s[j] - s[i] + j - i - 1) <= k:
                ans = min(ans, dfs(j) + (k - m) ** 2)
                j += 1
            return ans

        nums = [len(s) for s in sentence.split()]
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        return dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[] f;
    private int[] s;
    private int k;
    private int n;

    public int minimumCost(String sentence, int k) {
        this.k = k;
        String[] words = sentence.split(" ");
        n = words.length;
        f = new Integer[n];
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + words[i].length();
        }
        return dfs(0);
    }

    private int dfs(int i) {
        if (s[n] - s[i] + n - i - 1 <= k) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int j = i + 1; j < n && s[j] - s[i] + j - i - 1 <= k; ++j) {
            int m = s[j] - s[i] + j - i - 1;
            ans = Math.min(ans, dfs(j) + (k - m) * (k - m));
        }
        return f[i] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumCost(string sentence, int k) {
        istringstream iss(sentence);
        vector<int> s = {0};
        string w;
        while (iss >> w) {
            s.push_back(s.back() + w.size());
        }
        int n = s.size() - 1;
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (s[n] - s[i] + n - i - 1 <= k) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            int ans = INT_MAX;
            for (int j = i + 1; j < n && s[j] - s[i] + j - i - 1 <= k; ++j) {
                int m = s[j] - s[i] + j - i - 1;
                ans = min(ans, dfs(j) + (k - m) * (k - m));
            }
            return f[i] = ans;
        };
        return dfs(0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(sentence string, k int) int {
	s := []int{0}
	for _, w := range strings.Split(sentence, " ") {
		s = append(s, s[len(s)-1]+len(w))
	}
	n := len(s) - 1
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if s[n]-s[i]+n-i-1 <= k {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		ans := math.MaxInt32
		for j := i + 1; j < n && s[j]-s[i]+j-i-1 <= k; j++ {
			m := s[j] - s[i] + j - i - 1
			ans = min(ans, dfs(j)+(k-m)*(k-m))
		}
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(sentence: string, k: number): number {
    const s: number[] = [0];
    for (const w of sentence.split(' ')) {
        s.push(s.at(-1)! + w.length);
    }
    const n = s.length - 1;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (s[n] - s[i] + n - i - 1 <= k) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        let ans = Infinity;
        for (let j = i + 1; j < n && s[j] - s[i] + j - i - 1 <= k; ++j) {
            const m = s[j] - s[i] + j - i - 1;
            ans = Math.min(ans, dfs(j) + (k - m) ** 2);
        }
        return (f[i] = ans);
    };
    return dfs(0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由空格分隔的单词组成的字符串&nbsp;<code>sentence</code>&nbsp;和一个整数 <code>k</code>。你的任务是将&nbsp;<code>sentence</code> 分成<strong>多行</strong>，每行中的字符数<strong>最多</strong>为 <code>k</code>。你可以假设&nbsp;<code>sentence</code> 不以空格开头或结尾，并且&nbsp;<code>sentence</code> 中的单词由单个空格分隔。</p>

<p>你可以通过在&nbsp;<code>sentence</code>&nbsp;中的单词间插入换行来分隔&nbsp;<code>sentence</code> 。一个单词<strong>不能</strong>被分成两行。每个单词只能使用一次，并且单词顺序不能重排。同一行中的相邻单词应该由单个空格分隔，并且每行都不应该以空格开头或结尾。</p>

<p>一行长度为&nbsp;<code>n</code> 的字符串的<strong>分隔成本</strong>是&nbsp;<code>(k - n)<sup>2</sup></code> ，<strong>总成本</strong>就是<strong>除开</strong>最后一行以外的<strong>其它所有行的分隔成本</strong>之和。</p>

<ul>
	<li>以&nbsp;<code>sentence = "i love leetcode"</code> 和<code>k = 12</code>为例：

    <ul>
    	<li>将<code>sentence</code> 分成&nbsp;<code>"i"</code>, <code>"love"</code>, 和<code>"leetcode"</code> 的成本为&nbsp;<code>(12 - 1)<sup>2</sup> + (12 - 4)<sup>2</sup> = 185</code>。</li>
    	<li>将<code>sentence</code> 分成&nbsp;<code>"i love"</code>, 和<code>"leetcode"</code> 的成本为 <code>(12 - 6)<sup>2</sup> = 36</code>。</li>
    	<li>将<code>sentence</code> 分成&nbsp;<code>"i"</code>, 和<code>"love leetcode"</code>&nbsp;是不可能的，因为&nbsp;<code>"love leetcode"</code>&nbsp;的长度大于&nbsp;<code>k</code>。</li>
    </ul>
    </li>

</ul>

<p>返回<em>将</em><code>sentence</code><em>分隔成行的<strong>最低的</strong>可能总成本。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> sentence = "i love leetcode", k = 12
<strong>输出:</strong> 36
<strong>解释:</strong>
将 sentence 分成"i", "love", 和"leetcode" 的成本为 (12 - 1)<sup>2</sup> + (12 - 4)<sup>2</sup> = 185.
将 sentence 分成"i love", 和"leetcode" 的成本为 (12 - 6)<sup>2</sup> = 36.
将 sentence 分成"i", "love leetcode" 是不可能的，因为 "love leetcode" 的长度为 13.
36是最低的可能总成本，因此返回它
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> sentence = "apples and bananas taste great", k = 7
<strong>输出:</strong> 21
<strong>解释:</strong>
将 sentence 分成"apples", "and", "bananas", "taste", 和"great" 的成本为 (7 - 6)<sup>2</sup> + (7 - 3)<sup>2</sup> + (7 - 7)<sup>2</sup> + (7 - 5)<sup>2 </sup>= 21.
21是最低的可能总成本，因此返回它
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> sentence = "a", k = 5
<strong>输出:</strong> 0
<strong>解释:</strong>
最后一行的成本不包括在总成本中，而sentence只有一行，所以返回0</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 5000</code></li>
	<li><code>1 &lt;= k &lt;= 5000</code></li>
	<li><code>sentence</code>&nbsp;中每个单词长度最大为&nbsp;<code>k</code>.</li>
	<li><code>sentence</code> 只包含小写字母和空格.</li>
	<li><code>sentence</code> 不会以空格开头或结尾.</li>
	<li><code>sentence</code>&nbsp;中的单词以单个空格分隔.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 记忆化搜索

我们用一个数组 $\textit{nums}$ 记录每个单词的长度，数组的长度记为 $n$。然后我们定义一个长度为 $n + 1$ 的前缀和数组 $\textit{s}$，其中 $\textit{s}[i]$ 表示前 $i$ 个单词的长度之和。

接下来，我们设计一个函数 $\textit{dfs}(i)$，表示从第 $i$ 个单词开始分隔句子的最小成本。那么答案为 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的执行过程如下：

-   如果从第 $i$ 个单词开始到最后一个单词的长度之和加上单词之间的空格数小于等于 $k$，那么这些单词可以放在最后一行，成本为 $0$。
-   否则，我们枚举下一个开始分隔的单词的位置 $j$，使得从第 $i$ 个单词到第 $j-1$ 个单词的长度之和加上单词之间的空格数小于等于 $k$。那么 $\textit{dfs}(j)$ 表示从第 $j$ 个单词开始分隔句子的最小成本，而 $(k - m)^2$ 表示将第 $i$ 个单词到第 $j-1$ 个单词放在一行的成本，其中 $m$ 表示从第 $i$ 个单词到第 $j-1$ 个单词的长度之和加上单词之间的空格数。我们枚举所有的 $j$，取最小值即可。

答案即为 $\textit{dfs}(0)$。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为单词的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, sentence: str, k: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if s[n] - s[i] + n - i - 1 <= k:
                return 0
            ans = inf
            j = i + 1
            while j < n and (m := s[j] - s[i] + j - i - 1) <= k:
                ans = min(ans, dfs(j) + (k - m) ** 2)
                j += 1
            return ans

        nums = [len(s) for s in sentence.split()]
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        return dfs(0)
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] s;
    private int k;
    private int n;

    public int minimumCost(String sentence, int k) {
        this.k = k;
        String[] words = sentence.split(" ");
        n = words.length;
        f = new Integer[n];
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + words[i].length();
        }
        return dfs(0);
    }

    private int dfs(int i) {
        if (s[n] - s[i] + n - i - 1 <= k) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int j = i + 1; j < n && s[j] - s[i] + j - i - 1 <= k; ++j) {
            int m = s[j] - s[i] + j - i - 1;
            ans = Math.min(ans, dfs(j) + (k - m) * (k - m));
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCost(string sentence, int k) {
        istringstream iss(sentence);
        vector<int> s = {0};
        string w;
        while (iss >> w) {
            s.push_back(s.back() + w.size());
        }
        int n = s.size() - 1;
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (s[n] - s[i] + n - i - 1 <= k) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            int ans = INT_MAX;
            for (int j = i + 1; j < n && s[j] - s[i] + j - i - 1 <= k; ++j) {
                int m = s[j] - s[i] + j - i - 1;
                ans = min(ans, dfs(j) + (k - m) * (k - m));
            }
            return f[i] = ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func minimumCost(sentence string, k int) int {
	s := []int{0}
	for _, w := range strings.Split(sentence, " ") {
		s = append(s, s[len(s)-1]+len(w))
	}
	n := len(s) - 1
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if s[n]-s[i]+n-i-1 <= k {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		ans := math.MaxInt32
		for j := i + 1; j < n && s[j]-s[i]+j-i-1 <= k; j++ {
			m := s[j] - s[i] + j - i - 1
			ans = min(ans, dfs(j)+(k-m)*(k-m))
		}
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function minimumCost(sentence: string, k: number): number {
    const s: number[] = [0];
    for (const w of sentence.split(' ')) {
        s.push(s.at(-1)! + w.length);
    }
    const n = s.length - 1;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (s[n] - s[i] + n - i - 1 <= k) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        let ans = Infinity;
        for (let j = i + 1; j < n && s[j] - s[i] + j - i - 1 <= k; ++j) {
            const m = s[j] - s[i] + j - i - 1;
            ans = Math.min(ans, dfs(j) + (k - m) ** 2);
        }
        return (f[i] = ans);
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2053. 数组中第 K 个独一无二的字符串](https://leetcode.cn/problems/kth-distinct-string-in-an-array){#2053}

{{< tabs "2053" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        cnt = Counter(arr)
        for s in arr:
            if cnt[s] == 1:
                k -= 1
                if k == 0:
                    return s
        return ""
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : arr) {
            cnt.merge(s, 1, Integer::sum);
        }
        for (String s : arr) {
            if (cnt.get(s) == 1 && --k == 0) {
                return s;
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for (const auto& s : arr) {
            ++cnt[s];
        }
        for (const auto& s : arr) {
            if (cnt[s] == 1 && --k == 0) {
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
func kthDistinct(arr []string, k int) string {
	cnt := map[string]int{}
	for _, s := range arr {
		cnt[s]++
	}
	for _, s := range arr {
		if cnt[s] == 1 {
			k--
			if k == 0 {
				return s
			}
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthDistinct(arr: string[], k: number): string {
    const cnt = new Map<string, number>();
    for (const s of arr) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    for (const s of arr) {
        if (cnt.get(s) === 1 && --k === 0) {
            return s;
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn kth_distinct(arr: Vec<String>, mut k: i32) -> String {
        let mut cnt = HashMap::new();

        for s in &arr {
            *cnt.entry(s).or_insert(0) += 1;
        }

        for s in &arr {
            if *cnt.get(s).unwrap() == 1 {
                k -= 1;
                if k == 0 {
                    return s.clone();
                }
            }
        }

        "".to_string()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    const cnt = new Map();
    for (const s of arr) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    for (const s of arr) {
        if (cnt.get(s) === 1 && --k === 0) {
            return s;
        }
    }
    return '';
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>独一无二的字符串</strong>&nbsp;指的是在一个数组中只出现过 <strong>一次</strong>&nbsp;的字符串。</p>

<p>给你一个字符串数组&nbsp;<code>arr</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回&nbsp;<code>arr</code>&nbsp;中第&nbsp;<code>k</code>&nbsp;个&nbsp;<strong>独一无二的字符串</strong>&nbsp;。如果&nbsp;<strong>少于</strong>&nbsp;<code>k</code>&nbsp;个独一无二的字符串，那么返回&nbsp;<strong>空字符串</strong>&nbsp;<code>""</code>&nbsp;。</p>

<p>注意，按照字符串在原数组中的 <strong>顺序</strong>&nbsp;找到第 <code>k</code>&nbsp;个独一无二字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><b>输入：</b>arr = ["d","b","c","b","c","a"], k = 2
<b>输出：</b>"a"
<strong>解释：</strong>
arr 中独一无二字符串包括 "d" 和 "a"<code>&nbsp;。</code>
"d" 首先出现，所以它是第 1 个独一无二字符串。
"a" 第二个出现，所以它是 2 个独一无二字符串。
由于 k == 2 ，返回 "a" 。
</pre>

<p><strong>示例 2:</strong></p>

<pre><b>输入：</b>arr = ["aaa","aa","a"], k = 1
<b>输出：</b>"aaa"
<strong>解释：</strong>
arr 中所有字符串都是独一无二的，所以返回第 1 个字符串 "aaa" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>arr = ["a","b","a"], k = 3
<b>输出：</b>""
<strong>解释：</strong>
唯一一个独一无二字符串是 "b" 。由于少于 3 个独一无二字符串，我们返回空字符串 "" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 5</code></li>
	<li><code>arr[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 计数

我们可以用一个哈希表 $\textit{cnt}$ 记录每个字符串出现的次数，然后再遍历一次数组，对于每个字符串，如果它出现的次数为 $1$，那么就将 $k$ 减一，直到 $k$ 减为 $0$，返回当前字符串即可。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 为数组 $\textit{arr}$ 所有字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        cnt = Counter(arr)
        for s in arr:
            if cnt[s] == 1:
                k -= 1
                if k == 0:
                    return s
        return ""
```

#### Java

```java
class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : arr) {
            cnt.merge(s, 1, Integer::sum);
        }
        for (String s : arr) {
            if (cnt.get(s) == 1 && --k == 0) {
                return s;
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for (const auto& s : arr) {
            ++cnt[s];
        }
        for (const auto& s : arr) {
            if (cnt[s] == 1 && --k == 0) {
                return s;
            }
        }
        return "";
    }
};
```

#### Go

```go
func kthDistinct(arr []string, k int) string {
	cnt := map[string]int{}
	for _, s := range arr {
		cnt[s]++
	}
	for _, s := range arr {
		if cnt[s] == 1 {
			k--
			if k == 0 {
				return s
			}
		}
	}
	return ""
}
```

#### TypeScript

```ts
function kthDistinct(arr: string[], k: number): string {
    const cnt = new Map<string, number>();
    for (const s of arr) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    for (const s of arr) {
        if (cnt.get(s) === 1 && --k === 0) {
            return s;
        }
    }
    return '';
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn kth_distinct(arr: Vec<String>, mut k: i32) -> String {
        let mut cnt = HashMap::new();

        for s in &arr {
            *cnt.entry(s).or_insert(0) += 1;
        }

        for s in &arr {
            if *cnt.get(s).unwrap() == 1 {
                k -= 1;
                if k == 0 {
                    return s.clone();
                }
            }
        }

        "".to_string()
    }
}
```

#### JavaScript

```js
/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    const cnt = new Map();
    for (const s of arr) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    for (const s of arr) {
        if (cnt.get(s) === 1 && --k === 0) {
            return s;
        }
    }
    return '';
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2054. 两个最好的不重叠活动](https://leetcode.cn/problems/two-best-non-overlapping-events){#2054}

{{< tabs "2054" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n = len(events)
        f = [events[-1][2]] * n
        for i in range(n - 2, -1, -1):
            f[i] = max(f[i + 1], events[i][2])
        ans = 0
        for _, e, v in events:
            idx = bisect_right(events, e, key=lambda x: x[0])
            if idx < n:
                v += f[idx]
            ans = max(ans, v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        int[] f = new int[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            f[i] = Math.max(f[i + 1], events[i][2]);
        }
        int ans = 0;
        for (int[] e : events) {
            int v = e[2];
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (events[mid][0] > e[1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left < n) {
                v += f[left];
            }
            ans = Math.max(ans, v);
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
    int maxTwoEvents(vector<vector<int>>& events) {
        ranges::sort(events);
        int n = events.size();
        vector<int> f(n + 1);
        for (int i = n - 1; ~i; --i) {
            f[i] = max(f[i + 1], events[i][2]);
        }
        int ans = 0;
        for (const auto& e : events) {
            int v = e[2];
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (events[mid][0] > e[1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left < n) {
                v += f[left];
            }
            ans = max(ans, v);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTwoEvents(events [][]int) int {
	sort.Slice(events, func(i, j int) bool {
		return events[i][0] < events[j][0]
	})
	n := len(events)
	f := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		f[i] = max(f[i+1], events[i][2])
	}
	ans := 0
	for _, e := range events {
		v := e[2]
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if events[mid][0] > e[1] {
				right = mid
			} else {
				left = mid + 1
			}
		}
		if left < n {
			v += f[left]
		}
		ans = max(ans, v)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTwoEvents(events: number[][]): number {
    events.sort((a, b) => a[0] - b[0]);
    const n = events.length;
    const f: number[] = Array(n + 1).fill(0);
    for (let i = n - 1; ~i; --i) {
        f[i] = Math.max(f[i + 1], events[i][2]);
    }
    let ans = 0;
    for (const [_, end, v] of events) {
        let [left, right] = [0, n];
        while (left < right) {
            const mid = (left + right) >> 1;
            if (events[mid][0] > end) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const t = left < n ? f[left] : 0;
        ans = Math.max(ans, t + v);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>events</code>&nbsp;，其中&nbsp;<code>events[i] = [startTime<sub>i</sub>, endTime<sub>i</sub>, value<sub>i</sub>]</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个活动开始于&nbsp;<code>startTime<sub>i</sub></code>&nbsp;，结束于&nbsp;<code>endTime<sub>i</sub></code>&nbsp;，如果你参加这个活动，那么你可以得到价值&nbsp;<code>value<sub>i</sub></code>&nbsp;。你 <strong>最多</strong>&nbsp;可以参加&nbsp;<strong>两个时间不重叠</strong>&nbsp;活动，使得它们的价值之和 <strong>最大</strong>&nbsp;。</p>

<p>请你返回价值之和的 <strong>最大值</strong>&nbsp;。</p>

<p>注意，活动的开始时间和结束时间是 <strong>包括</strong>&nbsp;在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。更具体的，如果你参加一个活动，且结束时间为 <code>t</code>&nbsp;，那么下一个活动必须在&nbsp;<code>t + 1</code>&nbsp;或之后的时间开始。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2054.Two%20Best%20Non-Overlapping%20Events/images/picture5.png" style="width: 400px; height: 75px;"></p>

<pre><b>输入：</b>events = [[1,3,2],[4,5,2],[2,4,3]]
<b>输出：</b>4
<strong>解释：</strong>选择绿色的活动 0 和 1 ，价值之和为 2 + 2 = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="Example 1 Diagram" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2054.Two%20Best%20Non-Overlapping%20Events/images/picture1.png" style="width: 400px; height: 77px;"></p>

<pre><b>输入：</b>events = [[1,3,2],[4,5,2],[1,5,5]]
<b>输出：</b>5
<strong>解释：</strong>选择活动 2 ，价值和为 5 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2054.Two%20Best%20Non-Overlapping%20Events/images/picture3.png" style="width: 400px; height: 66px;"></p>

<pre><b>输入：</b>events = [[1,5,3],[1,5,1],[6,6,5]]
<b>输出：</b>8
<strong>解释：</strong>选择活动 0 和 2 ，价值之和为 3 + 5 = 8 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 3</code></li>
	<li><code>1 &lt;= startTime<sub>i</sub> &lt;= endTime<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们可以讲活动按照开始排序，然后预处理出以每个活动为作为开始的最大价值，即 $f[i]$ 表示从第 $i$ 个活动开始，到最后一个活动结束，选择其中一个活动的最大价值。

然后我们枚举每个活动，对于每个活动，我们使用二分查找找到第一个开始时间大于当前活动结束时间的活动，下标记为 $\textit{idx}$，那么以当前活动为开始的最大价值就是 $f[\textit{idx}]$，加上当前活动的价值，即为以当前活动为第一个活动，最终能获得的最大价值。求最大值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为活动的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n = len(events)
        f = [events[-1][2]] * n
        for i in range(n - 2, -1, -1):
            f[i] = max(f[i + 1], events[i][2])
        ans = 0
        for _, e, v in events:
            idx = bisect_right(events, e, key=lambda x: x[0])
            if idx < n:
                v += f[idx]
            ans = max(ans, v)
        return ans
```

#### Java

```java
class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        int[] f = new int[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            f[i] = Math.max(f[i + 1], events[i][2]);
        }
        int ans = 0;
        for (int[] e : events) {
            int v = e[2];
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (events[mid][0] > e[1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left < n) {
                v += f[left];
            }
            ans = Math.max(ans, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ranges::sort(events);
        int n = events.size();
        vector<int> f(n + 1);
        for (int i = n - 1; ~i; --i) {
            f[i] = max(f[i + 1], events[i][2]);
        }
        int ans = 0;
        for (const auto& e : events) {
            int v = e[2];
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (events[mid][0] > e[1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left < n) {
                v += f[left];
            }
            ans = max(ans, v);
        }
        return ans;
    }
};
```

#### Go

```go
func maxTwoEvents(events [][]int) int {
	sort.Slice(events, func(i, j int) bool {
		return events[i][0] < events[j][0]
	})
	n := len(events)
	f := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		f[i] = max(f[i+1], events[i][2])
	}
	ans := 0
	for _, e := range events {
		v := e[2]
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if events[mid][0] > e[1] {
				right = mid
			} else {
				left = mid + 1
			}
		}
		if left < n {
			v += f[left]
		}
		ans = max(ans, v)
	}
	return ans
}
```

#### TypeScript

```ts
function maxTwoEvents(events: number[][]): number {
    events.sort((a, b) => a[0] - b[0]);
    const n = events.length;
    const f: number[] = Array(n + 1).fill(0);
    for (let i = n - 1; ~i; --i) {
        f[i] = Math.max(f[i + 1], events[i][2]);
    }
    let ans = 0;
    for (const [_, end, v] of events) {
        let [left, right] = [0, n];
        while (left < right) {
            const mid = (left + right) >> 1;
            if (events[mid][0] > end) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const t = left < n ? f[left] : 0;
        ans = Math.max(ans, t + v);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2055. 蜡烛之间的盘子](https://leetcode.cn/problems/plates-between-candles){#2055}

{{< tabs "2055" >}}

{{% tab "python" %}}
```python
class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        presum = [0] * (n + 1)
        for i, c in enumerate(s):
            presum[i + 1] = presum[i] + (c == '*')

        left, right = [0] * n, [0] * n
        l = r = -1
        for i, c in enumerate(s):
            if c == '|':
                l = i
            left[i] = l
        for i in range(n - 1, -1, -1):
            if s[i] == '|':
                r = i
            right[i] = r

        ans = [0] * len(queries)
        for k, (l, r) in enumerate(queries):
            i, j = right[l], left[r]
            if i >= 0 and j >= 0 and i < j:
                ans[k] = presum[j] - presum[i + 1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length();
        int[] presum = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + (s.charAt(i) == '*' ? 1 : 0);
        }
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0, l = -1; i < n; ++i) {
            if (s.charAt(i) == '|') {
                l = i;
            }
            left[i] = l;
        }
        for (int i = n - 1, r = -1; i >= 0; --i) {
            if (s.charAt(i) == '|') {
                r = i;
            }
            right[i] = r;
        }
        int[] ans = new int[queries.length];
        for (int k = 0; k < queries.length; ++k) {
            int i = right[queries[k][0]];
            int j = left[queries[k][1]];
            if (i >= 0 && j >= 0 && i < j) {
                ans[k] = presum[j] - presum[i + 1];
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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> presum(n + 1);
        for (int i = 0; i < n; ++i) presum[i + 1] = presum[i] + (s[i] == '*');
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0, l = -1; i < n; ++i) {
            if (s[i] == '|') l = i;
            left[i] = l;
        }
        for (int i = n - 1, r = -1; i >= 0; --i) {
            if (s[i] == '|') r = i;
            right[i] = r;
        }
        vector<int> ans(queries.size());
        for (int k = 0; k < queries.size(); ++k) {
            int i = right[queries[k][0]];
            int j = left[queries[k][1]];
            if (i >= 0 && j >= 0 && i < j) ans[k] = presum[j] - presum[i + 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func platesBetweenCandles(s string, queries [][]int) []int {
	n := len(s)
	presum := make([]int, n+1)
	for i := range s {
		if s[i] == '*' {
			presum[i+1] = 1
		}
		presum[i+1] += presum[i]
	}
	left, right := make([]int, n), make([]int, n)
	for i, l := 0, -1; i < n; i++ {
		if s[i] == '|' {
			l = i
		}
		left[i] = l
	}
	for i, r := n-1, -1; i >= 0; i-- {
		if s[i] == '|' {
			r = i
		}
		right[i] = r
	}
	ans := make([]int, len(queries))
	for k, q := range queries {
		i, j := right[q[0]], left[q[1]]
		if i >= 0 && j >= 0 && i < j {
			ans[k] = presum[j] - presum[i+1]
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

<p>给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，它只包含字符&nbsp;<code>'*'</code> 和&nbsp;<code>'|'</code>&nbsp;，其中&nbsp;<code>'*'</code>&nbsp;表示一个 <strong>盘子</strong>&nbsp;，<code>'|'</code>&nbsp;表示一支&nbsp;<strong>蜡烛</strong>&nbsp;。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;表示 <strong>子字符串</strong>&nbsp;<code>s[left<sub>i</sub>...right<sub>i</sub>]</code>&nbsp;（<strong>包含左右端点的字符</strong>）。对于每个查询，你需要找到 <strong>子字符串中</strong>&nbsp;在 <strong>两支蜡烛之间</strong>&nbsp;的盘子的 <b>数目</b>&nbsp;。如果一个盘子在 <strong>子字符串中</strong>&nbsp;左边和右边 <strong>都</strong>&nbsp;至少有一支蜡烛，那么这个盘子满足在 <strong>两支蜡烛之间</strong>&nbsp;。</p>

<ul>
	<li>比方说，<code>s = "||**||**|*"</code>&nbsp;，查询&nbsp;<code>[3, 8]</code>&nbsp;，表示的是子字符串&nbsp;<code>"*||<strong><em>**</em></strong>|"</code>&nbsp;。子字符串中在两支蜡烛之间的盘子数目为&nbsp;<code>2</code>&nbsp;，子字符串中右边两个盘子在它们左边和右边 <strong>都 </strong>至少有一支蜡烛。</li>
</ul>

<p>请你返回一个整数数组&nbsp;<code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="ex-1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2055.Plates%20Between%20Candles/images/ex-1.png" style="width: 400px; height: 134px;"></p>

<pre><b>输入：</b>s = "**|**|***|", queries = [[2,5],[5,9]]
<b>输出：</b>[2,3]
<b>解释：</b>
- queries[0] 有两个盘子在蜡烛之间。
- queries[1] 有三个盘子在蜡烛之间。
</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="ex-2" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2055.Plates%20Between%20Candles/images/ex-2.png" style="width: 600px; height: 193px;"></p>

<pre><b>输入：</b>s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
<b>输出：</b>[9,0,0,0,0]
<strong>解释：</strong>
- queries[0] 有 9 个盘子在蜡烛之间。
- 另一个查询没有盘子在蜡烛之间。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含字符&nbsp;<code>'*'</code> 和&nbsp;<code>'|'</code>&nbsp;。</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt; s.length</code></li>
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
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        presum = [0] * (n + 1)
        for i, c in enumerate(s):
            presum[i + 1] = presum[i] + (c == '*')

        left, right = [0] * n, [0] * n
        l = r = -1
        for i, c in enumerate(s):
            if c == '|':
                l = i
            left[i] = l
        for i in range(n - 1, -1, -1):
            if s[i] == '|':
                r = i
            right[i] = r

        ans = [0] * len(queries)
        for k, (l, r) in enumerate(queries):
            i, j = right[l], left[r]
            if i >= 0 and j >= 0 and i < j:
                ans[k] = presum[j] - presum[i + 1]
        return ans
```

#### Java

```java
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int n = s.length();
        int[] presum = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + (s.charAt(i) == '*' ? 1 : 0);
        }
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0, l = -1; i < n; ++i) {
            if (s.charAt(i) == '|') {
                l = i;
            }
            left[i] = l;
        }
        for (int i = n - 1, r = -1; i >= 0; --i) {
            if (s.charAt(i) == '|') {
                r = i;
            }
            right[i] = r;
        }
        int[] ans = new int[queries.length];
        for (int k = 0; k < queries.length; ++k) {
            int i = right[queries[k][0]];
            int j = left[queries[k][1]];
            if (i >= 0 && j >= 0 && i < j) {
                ans[k] = presum[j] - presum[i + 1];
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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> presum(n + 1);
        for (int i = 0; i < n; ++i) presum[i + 1] = presum[i] + (s[i] == '*');
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0, l = -1; i < n; ++i) {
            if (s[i] == '|') l = i;
            left[i] = l;
        }
        for (int i = n - 1, r = -1; i >= 0; --i) {
            if (s[i] == '|') r = i;
            right[i] = r;
        }
        vector<int> ans(queries.size());
        for (int k = 0; k < queries.size(); ++k) {
            int i = right[queries[k][0]];
            int j = left[queries[k][1]];
            if (i >= 0 && j >= 0 && i < j) ans[k] = presum[j] - presum[i + 1];
        }
        return ans;
    }
};
```

#### Go

```go
func platesBetweenCandles(s string, queries [][]int) []int {
	n := len(s)
	presum := make([]int, n+1)
	for i := range s {
		if s[i] == '*' {
			presum[i+1] = 1
		}
		presum[i+1] += presum[i]
	}
	left, right := make([]int, n), make([]int, n)
	for i, l := 0, -1; i < n; i++ {
		if s[i] == '|' {
			l = i
		}
		left[i] = l
	}
	for i, r := n-1, -1; i >= 0; i-- {
		if s[i] == '|' {
			r = i
		}
		right[i] = r
	}
	ans := make([]int, len(queries))
	for k, q := range queries {
		i, j := right[q[0]], left[q[1]]
		if i >= 0 && j >= 0 && i < j {
			ans[k] = presum[j] - presum[i+1]
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

# [2056. 棋盘上有效移动组合的数目](https://leetcode.cn/problems/number-of-valid-move-combinations-on-chessboard){#2056}

{{< tabs "2056" >}}

{{% tab "python" %}}
```python
rook_dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
bishop_dirs = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
queue_dirs = rook_dirs + bishop_dirs


def get_dirs(piece: str) -> List[Tuple[int, int]]:
    match piece[0]:
        case "r":
            return rook_dirs
        case "b":
            return bishop_dirs
        case _:
            return queue_dirs


class Solution:
    def countCombinations(self, pieces: List[str], positions: List[List[int]]) -> int:
        def check_stop(i: int, x: int, y: int, t: int) -> bool:
            return all(dist[j][x][y] < t for j in range(i))

        def check_pass(i: int, x: int, y: int, t: int) -> bool:
            for j in range(i):
                if dist[j][x][y] == t:
                    return False
                if end[j][0] == x and end[j][1] == y and end[j][2] <= t:
                    return False
            return True

        def dfs(i: int) -> None:
            if i >= n:
                nonlocal ans
                ans += 1
                return
            x, y = positions[i]
            dist[i][:] = [[-1] * m for _ in range(m)]
            dist[i][x][y] = 0
            end[i] = (x, y, 0)
            if check_stop(i, x, y, 0):
                dfs(i + 1)
            dirs = get_dirs(pieces[i])
            for dx, dy in dirs:
                dist[i][:] = [[-1] * m for _ in range(m)]
                dist[i][x][y] = 0
                nx, ny, nt = x + dx, y + dy, 1
                while 1 <= nx < m and 1 <= ny < m and check_pass(i, nx, ny, nt):
                    dist[i][nx][ny] = nt
                    end[i] = (nx, ny, nt)
                    if check_stop(i, nx, ny, nt):
                        dfs(i + 1)
                    nx += dx
                    ny += dy
                    nt += 1

        n = len(pieces)
        m = 9
        dist = [[[-1] * m for _ in range(m)] for _ in range(n)]
        end = [(0, 0, 0) for _ in range(n)]
        ans = 0
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    int n, m = 9, ans;
    int[][][] dist;
    int[][] end;
    String[] pieces;
    int[][] positions;
    int[][] rookDirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int[][] bishopDirs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int[][] queenDirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    public int countCombinations(String[] pieces, int[][] positions) {
        n = pieces.length;
        dist = new int[n][m][m];
        end = new int[n][3];
        ans = 0;
        this.pieces = pieces;
        this.positions = positions;

        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= n) {
            ans++;
            return;
        }

        int x = positions[i][0], y = positions[i][1];
        resetDist(i);
        dist[i][x][y] = 0;
        end[i] = new int[] {x, y, 0};

        if (checkStop(i, x, y, 0)) {
            dfs(i + 1);
        }

        int[][] dirs = getDirs(pieces[i]);
        for (int[] dir : dirs) {
            resetDist(i);
            dist[i][x][y] = 0;
            int nx = x + dir[0], ny = y + dir[1], nt = 1;

            while (isValid(nx, ny) && checkPass(i, nx, ny, nt)) {
                dist[i][nx][ny] = nt;
                end[i] = new int[] {nx, ny, nt};
                if (checkStop(i, nx, ny, nt)) {
                    dfs(i + 1);
                }
                nx += dir[0];
                ny += dir[1];
                nt++;
            }
        }
    }

    private void resetDist(int i) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                dist[i][j][k] = -1;
            }
        }
    }

    private boolean checkStop(int i, int x, int y, int t) {
        for (int j = 0; j < i; j++) {
            if (dist[j][x][y] >= t) {
                return false;
            }
        }
        return true;
    }

    private boolean checkPass(int i, int x, int y, int t) {
        for (int j = 0; j < i; j++) {
            if (dist[j][x][y] == t) {
                return false;
            }
            if (end[j][0] == x && end[j][1] == y && end[j][2] <= t) {
                return false;
            }
        }
        return true;
    }

    private boolean isValid(int x, int y) {
        return x >= 1 && x < m && y >= 1 && y < m;
    }

    private int[][] getDirs(String piece) {
        char c = piece.charAt(0);
        return switch (c) {
            case 'r' -> rookDirs;
            case 'b' -> bishopDirs;
            default -> queenDirs;
        };
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        const int m = 9;
        int ans = 0;

        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(m, -1)));
        vector<vector<int>> end(n, vector<int>(3));

        const int rookDirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        const int bishopDirs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        const int queenDirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        auto resetDist = [&](int i) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    dist[i][j][k] = -1;
                }
            }
        };

        auto checkStop = [&](int i, int x, int y, int t) -> bool {
            for (int j = 0; j < i; j++) {
                if (dist[j][x][y] >= t) {
                    return false;
                }
            }
            return true;
        };

        auto checkPass = [&](int i, int x, int y, int t) -> bool {
            for (int j = 0; j < i; j++) {
                if (dist[j][x][y] == t) {
                    return false;
                }
                if (end[j][0] == x && end[j][1] == y && end[j][2] <= t) {
                    return false;
                }
            }
            return true;
        };

        auto isValid = [&](int x, int y) -> bool {
            return x >= 1 && x < m && y >= 1 && y < m;
        };

        auto getDirs = [&](const string& piece) -> const int(*)[2] {
            char c = piece[0];
            if (c == 'r') {
                return rookDirs;
            }
            if (c == 'b') {
                return bishopDirs;
            }
            return queenDirs;
        };

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i >= n) {
                ans++;
                return;
            }

            int x = positions[i][0], y = positions[i][1];
            resetDist(i);
            dist[i][x][y] = 0;
            end[i] = {x, y, 0};

            if (checkStop(i, x, y, 0)) {
                dfs(i + 1);
            }

            const int(*dirs)[2] = getDirs(pieces[i]);
            int dirsSize = (pieces[i][0] == 'q') ? 8 : 4;

            for (int d = 0; d < dirsSize; d++) {
                resetDist(i);
                dist[i][x][y] = 0;
                int nx = x + dirs[d][0], ny = y + dirs[d][1], nt = 1;

                while (isValid(nx, ny) && checkPass(i, nx, ny, nt)) {
                    dist[i][nx][ny] = nt;
                    end[i] = {nx, ny, nt};
                    if (checkStop(i, nx, ny, nt)) {
                        dfs(i + 1);
                    }
                    nx += dirs[d][0];
                    ny += dirs[d][1];
                    nt++;
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
func countCombinations(pieces []string, positions [][]int) (ans int) {
	n := len(pieces)
	m := 9
	dist := make([][][]int, n)
	for i := range dist {
		dist[i] = make([][]int, m)
		for j := range dist[i] {
			dist[i][j] = make([]int, m)
		}
	}

	end := make([][3]int, n)

	rookDirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	bishopDirs := [][2]int{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
	queenDirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}

	resetDist := func(i int) {
		for j := 0; j < m; j++ {
			for k := 0; k < m; k++ {
				dist[i][j][k] = -1
			}
		}
	}

	checkStop := func(i, x, y, t int) bool {
		for j := 0; j < i; j++ {
			if dist[j][x][y] >= t {
				return false
			}
		}
		return true
	}

	checkPass := func(i, x, y, t int) bool {
		for j := 0; j < i; j++ {
			if dist[j][x][y] == t {
				return false
			}
			if end[j][0] == x && end[j][1] == y && end[j][2] <= t {
				return false
			}
		}
		return true
	}

	isValid := func(x, y int) bool {
		return x >= 1 && x < m && y >= 1 && y < m
	}

	getDirs := func(piece string) [][2]int {
		switch piece[0] {
		case 'r':
			return rookDirs
		case 'b':
			return bishopDirs
		default:
			return queenDirs
		}
	}

	var dfs func(i int)
	dfs = func(i int) {
		if i >= n {
			ans++
			return
		}

		x, y := positions[i][0], positions[i][1]
		resetDist(i)
		dist[i][x][y] = 0
		end[i] = [3]int{x, y, 0}

		if checkStop(i, x, y, 0) {
			dfs(i + 1)
		}

		dirs := getDirs(pieces[i])
		for _, dir := range dirs {
			resetDist(i)
			dist[i][x][y] = 0
			nx, ny, nt := x+dir[0], y+dir[1], 1

			for isValid(nx, ny) && checkPass(i, nx, ny, nt) {
				dist[i][nx][ny] = nt
				end[i] = [3]int{nx, ny, nt}
				if checkStop(i, nx, ny, nt) {
					dfs(i + 1)
				}
				nx += dir[0]
				ny += dir[1]
				nt++
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
const rookDirs: [number, number][] = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
];
const bishopDirs: [number, number][] = [
    [1, 1],
    [1, -1],
    [-1, 1],
    [-1, -1],
];
const queenDirs = [...rookDirs, ...bishopDirs];

function countCombinations(pieces: string[], positions: number[][]): number {
    const n = pieces.length;
    const m = 9;
    let ans = 0;

    const dist = Array.from({ length: n }, () =>
        Array.from({ length: m }, () => Array(m).fill(-1)),
    );

    const end: [number, number, number][] = Array(n).fill([0, 0, 0]);

    const resetDist = (i: number) => {
        for (let j = 0; j < m; j++) {
            for (let k = 0; k < m; k++) {
                dist[i][j][k] = -1;
            }
        }
    };

    const checkStop = (i: number, x: number, y: number, t: number): boolean => {
        for (let j = 0; j < i; j++) {
            if (dist[j][x][y] >= t) {
                return false;
            }
        }
        return true;
    };

    const checkPass = (i: number, x: number, y: number, t: number): boolean => {
        for (let j = 0; j < i; j++) {
            if (dist[j][x][y] === t) {
                return false;
            }
            if (end[j][0] === x && end[j][1] === y && end[j][2] <= t) {
                return false;
            }
        }
        return true;
    };

    const isValid = (x: number, y: number): boolean => {
        return x >= 1 && x < m && y >= 1 && y < m;
    };

    const getDirs = (piece: string): [number, number][] => {
        switch (piece[0]) {
            case 'r':
                return rookDirs;
            case 'b':
                return bishopDirs;
            default:
                return queenDirs;
        }
    };

    const dfs = (i: number) => {
        if (i >= n) {
            ans++;
            return;
        }

        const [x, y] = positions[i];
        resetDist(i);
        dist[i][x][y] = 0;
        end[i] = [x, y, 0];

        if (checkStop(i, x, y, 0)) {
            dfs(i + 1);
        }

        const dirs = getDirs(pieces[i]);
        for (const [dx, dy] of dirs) {
            resetDist(i);
            dist[i][x][y] = 0;
            let nx = x + dx,
                ny = y + dy,
                nt = 1;

            while (isValid(nx, ny) && checkPass(i, nx, ny, nt)) {
                dist[i][nx][ny] = nt;
                end[i] = [nx, ny, nt];
                if (checkStop(i, nx, ny, nt)) {
                    dfs(i + 1);
                }
                nx += dx;
                ny += dy;
                nt++;
            }
        }
    };

    dfs(0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个&nbsp;<code>8 x 8</code>&nbsp;的棋盘，它包含&nbsp;<code>n</code>&nbsp;个棋子（棋子包括车，后和象三种）。给你一个长度为 <code>n</code>&nbsp;的字符串数组&nbsp;<code>pieces</code>&nbsp;，其中&nbsp;<code>pieces[i]</code>&nbsp;表示第 <code>i</code>&nbsp;个棋子的类型（车，后或象）。除此以外，还给你一个长度为 <code>n</code>&nbsp;的二维整数数组&nbsp;<code>positions</code>&nbsp;，其中 <code>positions[i] = [r<sub>i</sub>, c<sub>i</sub>]</code>&nbsp;表示第 <code>i</code>&nbsp;个棋子现在在棋盘上的位置为&nbsp;<code>(r<sub>i</sub>, c<sub>i</sub>)</code>&nbsp;，棋盘下标从 <strong>1</strong>&nbsp;开始。</p>

<p>每个棋子的移动中，首先选择移动的 <strong>方向</strong>&nbsp;，然后选择 <strong>移动的步数</strong>&nbsp;，同时你要确保移动过程中棋子不能移到棋盘以外的地方。棋子需按照以下规则移动：</p>

<ul>
	<li>车可以 <strong>水平或者竖直</strong>&nbsp;从&nbsp;<code>(r, c)</code>&nbsp;沿着方向&nbsp;<code>(r+1, c)</code>，<code>(r-1, c)</code>，<code>(r, c+1)</code>&nbsp;或者&nbsp;<code>(r, c-1)</code>&nbsp;移动。</li>
	<li>后可以 <strong>水平竖直或者斜对角</strong>&nbsp;从&nbsp;<code>(r, c)</code> 沿着方向&nbsp;<code>(r+1, c)</code>，<code>(r-1, c)</code>，<code>(r, c+1)</code>，<code>(r, c-1)</code>，<code>(r+1, c+1)</code>，<code>(r+1, c-1)</code>，<code>(r-1, c+1)</code>，<code>(r-1, c-1)</code>&nbsp;移动。</li>
	<li>象可以 <strong>斜对角</strong>&nbsp;从&nbsp;<code>(r, c)</code>&nbsp;沿着方向&nbsp;<code>(r+1, c+1)</code>，<code>(r+1, c-1)</code>，<code>(r-1, c+1)</code>，<code>(r-1, c-1)</code>&nbsp;移动。</li>
</ul>

<p>你必须同时 <strong>移动</strong> 棋盘上的每一个棋子。<strong>移动组合</strong>&nbsp;包含所有棋子的 <strong>移动</strong>&nbsp;。每一秒，每个棋子都沿着它们选择的方向往前移动 <strong>一步</strong>&nbsp;，直到它们到达目标位置。所有棋子从时刻 <code>0</code>&nbsp;开始移动。如果在某个时刻，两个或者更多棋子占据了同一个格子，那么这个移动组合 <strong>不有效</strong>&nbsp;。</p>

<p>请你返回 <strong>有效</strong>&nbsp;移动组合的数目。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>初始时，<strong>不会有两个棋子</strong>&nbsp;在 <strong>同一个位置 。</strong></li>
	<li>有可能在一个移动组合中，有棋子不移动。</li>
	<li>如果两个棋子 <strong>直接相邻</strong>&nbsp;且两个棋子下一秒要互相占据对方的位置，可以将它们在同一秒内 <strong>交换位置</strong>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2056.Number%20of%20Valid%20Move%20Combinations%20On%20Chessboard/images/a1.png" style="width: 215px; height: 215px;" /></p>

<pre>
<b>输入：</b>pieces = ["rook"], positions = [[1,1]]
<b>输出：</b>15
<b>解释：</b>上图展示了棋子所有可能的移动。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2056.Number%20of%20Valid%20Move%20Combinations%20On%20Chessboard/images/a2.png" style="width: 215px; height: 215px;" /></p>

<pre>
<b>输入：</b>pieces = ["queen"], positions = [[1,1]]
<b>输出：</b>22
<b>解释：</b>上图展示了棋子所有可能的移动。
</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2056.Number%20of%20Valid%20Move%20Combinations%20On%20Chessboard/images/a3.png" style="width: 214px; height: 215px;" /></p>

<pre>
<b>输入：</b>pieces = ["bishop"], positions = [[4,3]]
<b>输出：</b>12
<b>解释：</b>上图展示了棋子所有可能的移动。
</pre>

<p><strong>示例 4:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2056.Number%20of%20Valid%20Move%20Combinations%20On%20Chessboard/images/a4.png" style="width: 216px; height: 219px;" /></p>

<pre>
<b>输入：</b>pieces = ["rook","rook"], positions = [[1,1],[8,8]]
<b>输出：</b>223
<b>解释：</b>每个车有 15 种移动，所以总共有 15 * 15 = 225 种移动组合。
但是，有两个是不有效的移动组合：
- 将两个车都移动到 (8, 1) ，会导致它们在同一个格子相遇。
- 将两个车都移动到 (1, 8) ，会导致它们在同一个格子相遇。
所以，总共有 225 - 2 = 223 种有效移动组合。
注意，有两种有效的移动组合，分别是一个车在 (1, 8) ，另一个车在 (8, 1) 。
即使棋盘状态是相同的，这两个移动组合被视为不同的，因为每个棋子移动操作是不相同的。
</pre>

<p><strong>示例 5：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2056.Number%20of%20Valid%20Move%20Combinations%20On%20Chessboard/images/a5.png" style="width: 214px; height: 213px;" /></p>

<pre>
<b>输入：</b>pieces = ["queen","bishop"], positions = [[5,7],[3,4]]
<b>输出：</b>281
<b>解释：</b>总共有 12 * 24 = 288 种移动组合。
但是，有一些不有效的移动组合：
- 如果后停在 (6, 7) ，它会阻挡象到达 (6, 7) 或者 (7, 8) 。
- 如果后停在 (5, 6) ，它会阻挡象到达 (5, 6) ，(6, 7) 或者 (7, 8) 。
- 如果象停在 (5, 2) ，它会阻挡后到达 (5, 2) 或者 (5, 1) 。
在 288 个移动组合当中，281 个是有效的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == pieces.length </code></li>
	<li><code>n == positions.length</code></li>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>pieces</code>&nbsp;只包含字符串&nbsp;<code>"rook"</code>&nbsp;，<code>"queen"</code>&nbsp;和&nbsp;<code>"bishop"</code>&nbsp;。</li>
	<li>棋盘上最多只有一个后。</li>
	<li><code>1 &lt;= r<sub>i</sub>, c<sub>i</sub> &lt;= 8</code></li>
	<li>每一个&nbsp;<code>positions[i]</code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

题目最多只有 $4$ 个棋子，每个棋子的移动方向最多有 $8$ 种，我们可以考虑使用 DFS 搜索所有的移动组合。

我们按照顺序依次枚举每个棋子，对于每个棋子，我们可以选择不移动，或者按照规则移动，用数组 $\textit{dist}[i]$ 记录第 $i$ 个棋子的移动情况，其中 $\textit{dist}[i][x][y]$ 表示第 $i$ 个棋子经过坐标 $(x, y)$ 时的时间，用数组 $\textit{end}[i]$ 记录第 $i$ 个棋子的终点坐标和时间。在搜索时，我们需要分别判断当前棋子是否可以停止移动，以及当前棋子是否可以继续在当前方向移动。

我们定义方法 $\text{checkStop}(i, x, y, t)$ 判断第 $i$ 个棋子是否在时间 $t$ 时停在坐标 $(x, y)$，如果对于此前的所有棋子 $j$，都有 $\textit{dist}[j][x][y] < t$，那么第 $i$ 个棋子可以停止移动。

另外，我们定义方法 $\text{checkPass}(i, x, y, t)$ 判断第 $i$ 个棋子是否可以在时间 $t$ 时经过坐标 $(x, y)$。如果此前有其它棋子 $j$ 也在时间 $t$ 经过坐标 $(x, y)$，或者有其它棋子 $j$ 停在 $(x, y)$，且时间不超过 $t$，那么第 $i$ 个棋子不能在时间 $t$ 时经过坐标 $(x, y)$。

时间复杂度 $O((n \times M)^n)$，空间复杂度 $O(n \times M)$。其中 $n$ 是棋子的数量，而 $M$ 是每个棋子的移动范围。

<!-- tabs:start -->

#### Python3

```python
rook_dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
bishop_dirs = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
queue_dirs = rook_dirs + bishop_dirs


def get_dirs(piece: str) -> List[Tuple[int, int]]:
    match piece[0]:
        case "r":
            return rook_dirs
        case "b":
            return bishop_dirs
        case _:
            return queue_dirs


class Solution:
    def countCombinations(self, pieces: List[str], positions: List[List[int]]) -> int:
        def check_stop(i: int, x: int, y: int, t: int) -> bool:
            return all(dist[j][x][y] < t for j in range(i))

        def check_pass(i: int, x: int, y: int, t: int) -> bool:
            for j in range(i):
                if dist[j][x][y] == t:
                    return False
                if end[j][0] == x and end[j][1] == y and end[j][2] <= t:
                    return False
            return True

        def dfs(i: int) -> None:
            if i >= n:
                nonlocal ans
                ans += 1
                return
            x, y = positions[i]
            dist[i][:] = [[-1] * m for _ in range(m)]
            dist[i][x][y] = 0
            end[i] = (x, y, 0)
            if check_stop(i, x, y, 0):
                dfs(i + 1)
            dirs = get_dirs(pieces[i])
            for dx, dy in dirs:
                dist[i][:] = [[-1] * m for _ in range(m)]
                dist[i][x][y] = 0
                nx, ny, nt = x + dx, y + dy, 1
                while 1 <= nx < m and 1 <= ny < m and check_pass(i, nx, ny, nt):
                    dist[i][nx][ny] = nt
                    end[i] = (nx, ny, nt)
                    if check_stop(i, nx, ny, nt):
                        dfs(i + 1)
                    nx += dx
                    ny += dy
                    nt += 1

        n = len(pieces)
        m = 9
        dist = [[[-1] * m for _ in range(m)] for _ in range(n)]
        end = [(0, 0, 0) for _ in range(n)]
        ans = 0
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    int n, m = 9, ans;
    int[][][] dist;
    int[][] end;
    String[] pieces;
    int[][] positions;
    int[][] rookDirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int[][] bishopDirs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int[][] queenDirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    public int countCombinations(String[] pieces, int[][] positions) {
        n = pieces.length;
        dist = new int[n][m][m];
        end = new int[n][3];
        ans = 0;
        this.pieces = pieces;
        this.positions = positions;

        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= n) {
            ans++;
            return;
        }

        int x = positions[i][0], y = positions[i][1];
        resetDist(i);
        dist[i][x][y] = 0;
        end[i] = new int[] {x, y, 0};

        if (checkStop(i, x, y, 0)) {
            dfs(i + 1);
        }

        int[][] dirs = getDirs(pieces[i]);
        for (int[] dir : dirs) {
            resetDist(i);
            dist[i][x][y] = 0;
            int nx = x + dir[0], ny = y + dir[1], nt = 1;

            while (isValid(nx, ny) && checkPass(i, nx, ny, nt)) {
                dist[i][nx][ny] = nt;
                end[i] = new int[] {nx, ny, nt};
                if (checkStop(i, nx, ny, nt)) {
                    dfs(i + 1);
                }
                nx += dir[0];
                ny += dir[1];
                nt++;
            }
        }
    }

    private void resetDist(int i) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                dist[i][j][k] = -1;
            }
        }
    }

    private boolean checkStop(int i, int x, int y, int t) {
        for (int j = 0; j < i; j++) {
            if (dist[j][x][y] >= t) {
                return false;
            }
        }
        return true;
    }

    private boolean checkPass(int i, int x, int y, int t) {
        for (int j = 0; j < i; j++) {
            if (dist[j][x][y] == t) {
                return false;
            }
            if (end[j][0] == x && end[j][1] == y && end[j][2] <= t) {
                return false;
            }
        }
        return true;
    }

    private boolean isValid(int x, int y) {
        return x >= 1 && x < m && y >= 1 && y < m;
    }

    private int[][] getDirs(String piece) {
        char c = piece.charAt(0);
        return switch (c) {
            case 'r' -> rookDirs;
            case 'b' -> bishopDirs;
            default -> queenDirs;
        };
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        const int m = 9;
        int ans = 0;

        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(m, -1)));
        vector<vector<int>> end(n, vector<int>(3));

        const int rookDirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        const int bishopDirs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        const int queenDirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        auto resetDist = [&](int i) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    dist[i][j][k] = -1;
                }
            }
        };

        auto checkStop = [&](int i, int x, int y, int t) -> bool {
            for (int j = 0; j < i; j++) {
                if (dist[j][x][y] >= t) {
                    return false;
                }
            }
            return true;
        };

        auto checkPass = [&](int i, int x, int y, int t) -> bool {
            for (int j = 0; j < i; j++) {
                if (dist[j][x][y] == t) {
                    return false;
                }
                if (end[j][0] == x && end[j][1] == y && end[j][2] <= t) {
                    return false;
                }
            }
            return true;
        };

        auto isValid = [&](int x, int y) -> bool {
            return x >= 1 && x < m && y >= 1 && y < m;
        };

        auto getDirs = [&](const string& piece) -> const int(*)[2] {
            char c = piece[0];
            if (c == 'r') {
                return rookDirs;
            }
            if (c == 'b') {
                return bishopDirs;
            }
            return queenDirs;
        };

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i >= n) {
                ans++;
                return;
            }

            int x = positions[i][0], y = positions[i][1];
            resetDist(i);
            dist[i][x][y] = 0;
            end[i] = {x, y, 0};

            if (checkStop(i, x, y, 0)) {
                dfs(i + 1);
            }

            const int(*dirs)[2] = getDirs(pieces[i]);
            int dirsSize = (pieces[i][0] == 'q') ? 8 : 4;

            for (int d = 0; d < dirsSize; d++) {
                resetDist(i);
                dist[i][x][y] = 0;
                int nx = x + dirs[d][0], ny = y + dirs[d][1], nt = 1;

                while (isValid(nx, ny) && checkPass(i, nx, ny, nt)) {
                    dist[i][nx][ny] = nt;
                    end[i] = {nx, ny, nt};
                    if (checkStop(i, nx, ny, nt)) {
                        dfs(i + 1);
                    }
                    nx += dirs[d][0];
                    ny += dirs[d][1];
                    nt++;
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
func countCombinations(pieces []string, positions [][]int) (ans int) {
	n := len(pieces)
	m := 9
	dist := make([][][]int, n)
	for i := range dist {
		dist[i] = make([][]int, m)
		for j := range dist[i] {
			dist[i][j] = make([]int, m)
		}
	}

	end := make([][3]int, n)

	rookDirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	bishopDirs := [][2]int{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
	queenDirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}

	resetDist := func(i int) {
		for j := 0; j < m; j++ {
			for k := 0; k < m; k++ {
				dist[i][j][k] = -1
			}
		}
	}

	checkStop := func(i, x, y, t int) bool {
		for j := 0; j < i; j++ {
			if dist[j][x][y] >= t {
				return false
			}
		}
		return true
	}

	checkPass := func(i, x, y, t int) bool {
		for j := 0; j < i; j++ {
			if dist[j][x][y] == t {
				return false
			}
			if end[j][0] == x && end[j][1] == y && end[j][2] <= t {
				return false
			}
		}
		return true
	}

	isValid := func(x, y int) bool {
		return x >= 1 && x < m && y >= 1 && y < m
	}

	getDirs := func(piece string) [][2]int {
		switch piece[0] {
		case 'r':
			return rookDirs
		case 'b':
			return bishopDirs
		default:
			return queenDirs
		}
	}

	var dfs func(i int)
	dfs = func(i int) {
		if i >= n {
			ans++
			return
		}

		x, y := positions[i][0], positions[i][1]
		resetDist(i)
		dist[i][x][y] = 0
		end[i] = [3]int{x, y, 0}

		if checkStop(i, x, y, 0) {
			dfs(i + 1)
		}

		dirs := getDirs(pieces[i])
		for _, dir := range dirs {
			resetDist(i)
			dist[i][x][y] = 0
			nx, ny, nt := x+dir[0], y+dir[1], 1

			for isValid(nx, ny) && checkPass(i, nx, ny, nt) {
				dist[i][nx][ny] = nt
				end[i] = [3]int{nx, ny, nt}
				if checkStop(i, nx, ny, nt) {
					dfs(i + 1)
				}
				nx += dir[0]
				ny += dir[1]
				nt++
			}
		}
	}

	dfs(0)
	return
}
```

#### TypeScript

```ts
const rookDirs: [number, number][] = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
];
const bishopDirs: [number, number][] = [
    [1, 1],
    [1, -1],
    [-1, 1],
    [-1, -1],
];
const queenDirs = [...rookDirs, ...bishopDirs];

function countCombinations(pieces: string[], positions: number[][]): number {
    const n = pieces.length;
    const m = 9;
    let ans = 0;

    const dist = Array.from({ length: n }, () =>
        Array.from({ length: m }, () => Array(m).fill(-1)),
    );

    const end: [number, number, number][] = Array(n).fill([0, 0, 0]);

    const resetDist = (i: number) => {
        for (let j = 0; j < m; j++) {
            for (let k = 0; k < m; k++) {
                dist[i][j][k] = -1;
            }
        }
    };

    const checkStop = (i: number, x: number, y: number, t: number): boolean => {
        for (let j = 0; j < i; j++) {
            if (dist[j][x][y] >= t) {
                return false;
            }
        }
        return true;
    };

    const checkPass = (i: number, x: number, y: number, t: number): boolean => {
        for (let j = 0; j < i; j++) {
            if (dist[j][x][y] === t) {
                return false;
            }
            if (end[j][0] === x && end[j][1] === y && end[j][2] <= t) {
                return false;
            }
        }
        return true;
    };

    const isValid = (x: number, y: number): boolean => {
        return x >= 1 && x < m && y >= 1 && y < m;
    };

    const getDirs = (piece: string): [number, number][] => {
        switch (piece[0]) {
            case 'r':
                return rookDirs;
            case 'b':
                return bishopDirs;
            default:
                return queenDirs;
        }
    };

    const dfs = (i: number) => {
        if (i >= n) {
            ans++;
            return;
        }

        const [x, y] = positions[i];
        resetDist(i);
        dist[i][x][y] = 0;
        end[i] = [x, y, 0];

        if (checkStop(i, x, y, 0)) {
            dfs(i + 1);
        }

        const dirs = getDirs(pieces[i]);
        for (const [dx, dy] of dirs) {
            resetDist(i);
            dist[i][x][y] = 0;
            let nx = x + dx,
                ny = y + dy,
                nt = 1;

            while (isValid(nx, ny) && checkPass(i, nx, ny, nt)) {
                dist[i][nx][ny] = nt;
                end[i] = [nx, ny, nt];
                if (checkStop(i, nx, ny, nt)) {
                    dfs(i + 1);
                }
                nx += dx;
                ny += dy;
                nt++;
            }
        }
    };

    dfs(0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2057. 值相等的最小索引](https://leetcode.cn/problems/smallest-index-with-equal-value){#2057}

{{< tabs "2057" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestEqual(self, nums: List[int]) -> int:
        for i, x in enumerate(nums):
            if i % 10 == x:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestEqual(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestEqual(nums []int) int {
	for i, x := range nums {
		if i%10 == x {
			return i
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestEqual(nums: number[]): number {
    for (let i = 0; i < nums.length; ++i) {
        if (i % 10 === nums[i]) {
            return i;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_equal(nums: Vec<i32>) -> i32 {
        for (i, &x) in nums.iter().enumerate() {
            if i % 10 == x as usize {
                return i as i32;
            }
        }
        -1
    }
}
```
{{% /tab %}}
{{% tab "cj" %}}
```cj
class Solution {
    func smallestEqual(nums: Array<Int64>): Int64 {
        for (i in 0..nums.size) {
            if (i % 10 == nums[i]) {
                return i
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

<p>给你一个下标从 0 开始的整数数组 <code>nums</code> ，返回 <code>nums</code> 中满足<em> </em><code>i mod 10 == nums[i]</code><em> </em>的最小下标 <code>i</code> ；如果不存在这样的下标，返回<em> </em><code>-1</code><em> </em>。</p>

<p><code>x mod y</code> 表示 <code>x</code> 除以 <code>y</code> 的 <strong>余数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,2]
<strong>输出：</strong>0
<strong>解释：</strong>
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
所有下标都满足 i mod 10 == nums[i] ，所以返回最小下标 0
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,3,2,1]
<strong>输出：</strong>2
<strong>解释：</strong>
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 唯一一个满足 i mod 10 == nums[i] 的下标
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5,6,7,8,9,0]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在满足 i mod 10 == nums[i] 的下标
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [2,1,3,5,2]
<strong>输出：</strong>1
<strong>解释：</strong>1 是唯一一个满足 i mod 10 == nums[i] 的下标
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们直接遍历数组，对于每个下标 $i$，我们判断是否满足 $i \bmod 10 = \textit{nums}[i]$，如果满足则返回当前下标 $i$。

如果遍历完数组都没有找到满足条件的下标，则返回 $-1$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestEqual(self, nums: List[int]) -> int:
        for i, x in enumerate(nums):
            if i % 10 == x:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int smallestEqual(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func smallestEqual(nums []int) int {
	for i, x := range nums {
		if i%10 == x {
			return i
		}
	}
	return -1
}
```

#### TypeScript

```ts
function smallestEqual(nums: number[]): number {
    for (let i = 0; i < nums.length; ++i) {
        if (i % 10 === nums[i]) {
            return i;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_equal(nums: Vec<i32>) -> i32 {
        for (i, &x) in nums.iter().enumerate() {
            if i % 10 == x as usize {
                return i as i32;
            }
        }
        -1
    }
}
```

#### Cangjie

```cj
class Solution {
    func smallestEqual(nums: Array<Int64>): Int64 {
        for (i in 0..nums.size) {
            if (i % 10 == nums[i]) {
                return i
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

# [2058. 找出临界点之间的最小和最大距离](https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points){#2058}

{{< tabs "2058" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        ans = [inf, -inf]
        first = last = -1
        i = 0
        while head.next.next:
            a, b, c = head.val, head.next.val, head.next.next.val
            if a > b < c or a < b > c:
                if last == -1:
                    first = last = i
                else:
                    ans[0] = min(ans[0], i - last)
                    last = i
                    ans[1] = max(ans[1], last - first)
            i += 1
            head = head.next
        return [-1, -1] if first == last else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] ans = {1 << 30, 0};
        int first = -1, last = -1;
        for (int i = 0; head.next.next != null; head = head.next, ++i) {
            int a = head.val, b = head.next.val, c = head.next.next.val;
            if (b < Math.min(a, c) || b > Math.max(a, c)) {
                if (last == -1) {
                    first = i;
                    last = i;
                } else {
                    ans[0] = Math.min(ans[0], i - last);
                    last = i;
                    ans[1] = Math.max(ans[1], last - first);
                }
            }
        }
        return first == last ? new int[] {-1, -1} : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {1 << 30, 0};
        int first = -1, last = -1;
        for (int i = 0; head->next->next; head = head->next, ++i) {
            int a = head->val, b = head->next->val, c = head->next->next->val;
            if (b < min(a, c) || b > max(a, c)) {
                if (last == -1) {
                    first = i;
                    last = i;
                } else {
                    ans[0] = min(ans[0], i - last);
                    last = i;
                    ans[1] = max(ans[1], last - first);
                }
            }
        }
        return first == last ? vector<int>{-1, -1} : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
	ans := []int{1 << 30, 0}
	first, last := -1, -1
	for i := 0; head.Next.Next != nil; head, i = head.Next, i+1 {
		a, b, c := head.Val, head.Next.Val, head.Next.Next.Val
		if b < min(a, c) || b > max(a, c) {
			if last == -1 {
				first, last = i, i
			} else {
				ans[0] = min(ans[0], i-last)
				last = i
				ans[1] = max(ans[1], last-first)
			}
		}
	}
	if first == last {
		return []int{-1, -1}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
    const ans: number[] = [Infinity, 0];
    let [first, last] = [-1, -1];
    for (let i = 0; head.next.next; head = head.next, ++i) {
        const [a, b, c] = [head.val, head.next.val, head.next.next.val];
        if (b < Math.min(a, c) || b > Math.max(a, c)) {
            if (last < 0) {
                first = i;
                last = i;
            } else {
                ans[0] = Math.min(ans[0], i - last);
                last = i;
                ans[1] = Math.max(ans[1], last - first);
            }
        }
    }
    return first === last ? [-1, -1] : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>链表中的 <strong>临界点</strong> 定义为一个 <strong>局部极大值点</strong> <strong>或</strong> <strong>局部极小值点 。</strong></p>

<p>如果当前节点的值 <strong>严格大于</strong> 前一个节点和后一个节点，那么这个节点就是一个<strong>&nbsp; 局部极大值点</strong> 。</p>

<p>如果当前节点的值 <strong>严格小于</strong> 前一个节点和后一个节点，那么这个节点就是一个<strong>&nbsp; 局部极小值点</strong> 。</p>

<p>注意：节点只有在同时存在前一个节点和后一个节点的情况下，才能成为一个 <strong>局部极大值点 / 极小值点</strong> 。</p>

<p>给你一个链表 <code>head</code> ，返回一个长度为 2 的数组<em> </em><code>[minDistance, maxDistance]</code> ，其中<em> </em><code>minDistance</code><em> </em>是任意两个不同临界点之间的最小距离，<code>maxDistance</code> 是任意两个不同临界点之间的最大距离。如果临界点少于两个，则返回 <code>[-1，-1]</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2058.Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points/images/a1.png" style="width: 148px; height: 55px;" /></p>

<pre>
<strong>输入：</strong>head = [3,1]
<strong>输出：</strong>[-1,-1]
<strong>解释：</strong>链表 [3,1] 中不存在临界点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2058.Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points/images/a2.png" style="width: 624px; height: 46px;" /></p>

<pre>
<strong>输入：</strong>head = [5,3,1,2,5,1,2]
<strong>输出：</strong>[1,3]
<strong>解释：</strong>存在三个临界点：
- [5,3,<em><strong>1</strong></em>,2,5,1,2]：第三个节点是一个局部极小值点，因为 1 比 3 和 2 小。
- [5,3,1,2,<em><strong>5</strong></em>,1,2]：第五个节点是一个局部极大值点，因为 5 比 2 和 1 大。
- [5,3,1,2,5,<em><strong>1</strong></em>,2]：第六个节点是一个局部极小值点，因为 1 比 5 和 2 小。
第五个节点和第六个节点之间距离最小。minDistance = 6 - 5 = 1 。
第三个节点和第六个节点之间距离最大。maxDistance = 6 - 3 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2058.Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points/images/a5.png" style="width: 624px; height: 39px;" /></p>

<pre>
<strong>输入：</strong>head = [1,3,2,2,3,2,2,2,7]
<strong>输出：</strong>[3,3]
<strong>解释：</strong>存在两个临界点：
- [1,<em><strong>3</strong></em>,2,2,3,2,2,2,7]：第二个节点是一个局部极大值点，因为 3 比 1 和 2 大。
- [1,3,2,2,<em><strong>3</strong></em>,2,2,2,7]：第五个节点是一个局部极大值点，因为 3 比 2 和 2 大。
最小和最大距离都存在于第二个节点和第五个节点之间。
因此，minDistance 和 maxDistance 是 5 - 2 = 3 。
注意，最后一个节点不算一个局部极大值点，因为它之后就没有节点了。
</pre>

<p><strong>示例 4：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2058.Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points/images/a4.png" style="width: 345px; height: 52px;" /></p>

<pre>
<strong>输入：</strong>head = [2,3,3,2]
<strong>输出：</strong>[-1,-1]
<strong>解释：</strong>链表 [2,3,3,2] 中不存在临界点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数量在范围 <code>[2, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

根据题目描述，我们需要找出链表的第一个临界点和最后一个临界点位置 $\textit{first}$ 和 $\textit{last}$，这样可以计算出最大距离 $\textit{maxDistance} = \textit{last} - \textit{first}$。对于最小距离 $\textit{minDistance}$，我们需要遍历链表，计算相邻两个临界点之间的距离，取最小值即可。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        ans = [inf, -inf]
        first = last = -1
        i = 0
        while head.next.next:
            a, b, c = head.val, head.next.val, head.next.next.val
            if a > b < c or a < b > c:
                if last == -1:
                    first = last = i
                else:
                    ans[0] = min(ans[0], i - last)
                    last = i
                    ans[1] = max(ans[1], last - first)
            i += 1
            head = head.next
        return [-1, -1] if first == last else ans
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] ans = {1 << 30, 0};
        int first = -1, last = -1;
        for (int i = 0; head.next.next != null; head = head.next, ++i) {
            int a = head.val, b = head.next.val, c = head.next.next.val;
            if (b < Math.min(a, c) || b > Math.max(a, c)) {
                if (last == -1) {
                    first = i;
                    last = i;
                } else {
                    ans[0] = Math.min(ans[0], i - last);
                    last = i;
                    ans[1] = Math.max(ans[1], last - first);
                }
            }
        }
        return first == last ? new int[] {-1, -1} : ans;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {1 << 30, 0};
        int first = -1, last = -1;
        for (int i = 0; head->next->next; head = head->next, ++i) {
            int a = head->val, b = head->next->val, c = head->next->next->val;
            if (b < min(a, c) || b > max(a, c)) {
                if (last == -1) {
                    first = i;
                    last = i;
                } else {
                    ans[0] = min(ans[0], i - last);
                    last = i;
                    ans[1] = max(ans[1], last - first);
                }
            }
        }
        return first == last ? vector<int>{-1, -1} : ans;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
	ans := []int{1 << 30, 0}
	first, last := -1, -1
	for i := 0; head.Next.Next != nil; head, i = head.Next, i+1 {
		a, b, c := head.Val, head.Next.Val, head.Next.Next.Val
		if b < min(a, c) || b > max(a, c) {
			if last == -1 {
				first, last = i, i
			} else {
				ans[0] = min(ans[0], i-last)
				last = i
				ans[1] = max(ans[1], last-first)
			}
		}
	}
	if first == last {
		return []int{-1, -1}
	}
	return ans
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
    const ans: number[] = [Infinity, 0];
    let [first, last] = [-1, -1];
    for (let i = 0; head.next.next; head = head.next, ++i) {
        const [a, b, c] = [head.val, head.next.val, head.next.next.val];
        if (b < Math.min(a, c) || b > Math.max(a, c)) {
            if (last < 0) {
                first = i;
                last = i;
            } else {
                ans[0] = Math.min(ans[0], i - last);
                last = i;
                ans[1] = Math.max(ans[1], last - first);
            }
        }
    }
    return first === last ? [-1, -1] : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2059. 转化数字的最小运算数](https://leetcode.cn/problems/minimum-operations-to-convert-number){#2059}

{{< tabs "2059" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        def next(x):
            res = []
            for num in nums:
                res.append(x + num)
                res.append(x - num)
                res.append(x ^ num)
            return res

        def extend(m1, m2, q):
            for _ in range(len(q)):
                x = q.popleft()
                step = m1[x]
                for y in next(x):
                    if y in m1:
                        continue
                    if y in m2:
                        return step + 1 + m2[y]
                    if 0 <= y <= 1000:
                        m1[y] = step + 1
                        q.append(y)
            return -1

        m1, m2 = {start: 0}, {goal: 0}
        q1, q2 = deque([start]), deque([goal])
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;

    public int minimumOperations(int[] nums, int start, int goal) {
        this.nums = nums;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        Deque<Integer> q1 = new ArrayDeque<>();
        Deque<Integer> q2 = new ArrayDeque<>();
        m1.put(start, 0);
        m2.put(goal, 0);
        q1.offer(start);
        q2.offer(goal);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<Integer, Integer> m1, Map<Integer, Integer> m2, Deque<Integer> q) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.poll();
            int step = m1.get(x);
            for (int y : next(x)) {
                if (m1.containsKey(y)) {
                    continue;
                }
                if (m2.containsKey(y)) {
                    return step + 1 + m2.get(y);
                }
                if (y >= 0 && y <= 1000) {
                    m1.put(y, step + 1);
                    q.offer(y);
                }
            }
        }
        return -1;
    }

    private List<Integer> next(int x) {
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            res.add(x + num);
            res.add(x - num);
            res.add(x ^ num);
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        m1[start] = 0;
        m2[goal] = 0;
        queue<int> q1{{start}};
        queue<int> q2{{goal}};
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1, nums) : extend(m2, m1, q2, nums);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<int, int>& m1, unordered_map<int, int>& m2, queue<int>& q, vector<int>& nums) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.front();
            int step = m1[x];
            q.pop();
            for (int y : next(nums, x)) {
                if (m1.count(y)) continue;
                if (m2.count(y)) return step + 1 + m2[y];
                if (y >= 0 && y <= 1000) {
                    m1[y] = step + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }

    vector<int> next(vector<int>& nums, int x) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(x + num);
            res.push_back(x - num);
            res.push_back(x ^ num);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int, start int, goal int) int {
	next := func(x int) []int {
		var res []int
		for _, num := range nums {
			res = append(res, []int{x + num, x - num, x ^ num}...)
		}
		return res
	}
	m1, m2 := map[int]int{start: 0}, map[int]int{goal: 0}
	q1, q2 := []int{start}, []int{goal}
	extend := func() int {
		for i := len(q1); i > 0; i-- {
			x := q1[0]
			q1 = q1[1:]
			step, _ := m1[x]
			for _, y := range next(x) {
				if _, ok := m1[y]; ok {
					continue
				}
				if v, ok := m2[y]; ok {
					return step + 1 + v
				}
				if y >= 0 && y <= 1000 {
					m1[y] = step + 1
					q1 = append(q1, y)
				}
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) > len(q2) {
			m1, m2 = m2, m1
			q1, q2 = q2, q1
		}
		t := extend()
		if t != -1 {
			return t
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(nums: number[], start: number, goal: number): number {
    const n = nums.length;
    const op1 = function (x: number, y: number): number {
        return x + y;
    };
    const op2 = function (x: number, y: number): number {
        return x - y;
    };
    const op3 = function (x: number, y: number): number {
        return x ^ y;
    };
    const ops = [op1, op2, op3];
    let vis = new Array(1001).fill(false);
    let quenue: Array<Array<number>> = [[start, 0]];
    vis[start] = true;
    while (quenue.length) {
        let [x, step] = quenue.shift();
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < ops.length; j++) {
                const nx = ops[j](x, nums[i]);
                if (nx == goal) {
                    return step + 1;
                }
                if (nx >= 0 && nx <= 1000 && !vis[nx]) {
                    vis[nx] = true;
                    quenue.push([nx, step + 1]);
                }
            }
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，该数组由 <strong>互不相同</strong> 的数字组成。另给你两个整数 <code>start</code> 和 <code>goal</code> 。</p>

<p>整数 <code>x</code> 的值最开始设为 <code>start</code> ，你打算执行一些运算使 <code>x</code> 转化为 <code>goal</code> 。你可以对数字 <code>x</code> 重复执行下述运算：</p>

<p>如果 <code>0 &lt;= x &lt;= 1000</code> ，那么，对于数组中的任一下标 <code>i</code>（<code>0 &lt;= i &lt; nums.length</code>），可以将 <code>x</code> 设为下述任一值：</p>

<ul>
	<li><code>x + nums[i]</code></li>
	<li><code>x - nums[i]</code></li>
	<li><code>x ^ nums[i]</code>（按位异或 XOR）</li>
</ul>

<p>注意，你可以按任意顺序使用每个 <code>nums[i]</code> 任意次。使 <code>x</code> 越过 <code>0 &lt;= x &lt;= 1000</code> 范围的运算同样可以生效，但该该运算执行后将不能执行其他运算。</p>

<p>返回将 <code>x = start</code><em> </em>转化为<em> </em><code>goal</code><em> </em>的最小操作数；如果无法完成转化，则返回<em> </em><code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,12], start = 2, goal = 12
<strong>输出：</strong>2
<strong>解释：</strong>
可以按 2 → 14 → 12 的转化路径进行，只需执行下述 2 次运算：
- 2 + 12 = 14
- 14 - 2 = 12
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,5,7], start = 0, goal = -4
<strong>输出：</strong>2
<strong>解释：</strong>
可以按 0 → 3 → -4 的转化路径进行，只需执行下述 2 次运算：
- 0 + 3 = 3
- 3 - 7 = -4
注意，最后一步运算使 x 超过范围 0 &lt;= x &lt;= 1000 ，但该运算仍然可以生效。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,8,16], start = 0, goal = 1
<strong>输出：</strong>-1
<strong>解释：</strong>
无法将 0 转化为 1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i], goal &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= start &lt;= 1000</code></li>
	<li><code>start != goal</code></li>
	<li><code>nums</code> 中的所有整数互不相同</li>
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
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        op1 = lambda x, y: x + y
        op2 = lambda x, y: x - y
        op3 = lambda x, y: x ^ y
        ops = [op1, op2, op3]
        vis = [False] * 1001
        q = deque([(start, 0)])
        while q:
            x, step = q.popleft()
            for num in nums:
                for op in ops:
                    nx = op(x, num)
                    if nx == goal:
                        return step + 1
                    if 0 <= nx <= 1000 and not vis[nx]:
                        q.append((nx, step + 1))
                        vis[nx] = True
        return -1
```

#### Java

```java
class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        IntBinaryOperator op1 = (x, y) -> x + y;
        IntBinaryOperator op2 = (x, y) -> x - y;
        IntBinaryOperator op3 = (x, y) -> x ^ y;
        IntBinaryOperator[] ops = {op1, op2, op3};
        boolean[] vis = new boolean[1001];
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[] {start, 0});
        while (!queue.isEmpty()) {
            int[] p = queue.poll();
            int x = p[0], step = p[1];
            for (int num : nums) {
                for (IntBinaryOperator op : ops) {
                    int nx = op.applyAsInt(x, num);
                    if (nx == goal) {
                        return step + 1;
                    }
                    if (nx >= 0 && nx <= 1000 && !vis[nx]) {
                        queue.offer(new int[] {nx, step + 1});
                        vis[nx] = true;
                    }
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        using pii = pair<int, int>;
        vector<function<int(int, int)>> ops{
            [](int x, int y) { return x + y; },
            [](int x, int y) { return x - y; },
            [](int x, int y) { return x ^ y; },
        };
        vector<bool> vis(1001, false);
        queue<pii> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto [x, step] = q.front();
            q.pop();
            for (int num : nums) {
                for (auto op : ops) {
                    int nx = op(x, num);
                    if (nx == goal) {
                        return step + 1;
                    }
                    if (nx >= 0 && nx <= 1000 && !vis[nx]) {
                        q.push({nx, step + 1});
                        vis[nx] = true;
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumOperations(nums []int, start int, goal int) int {
	type pair struct {
		x    int
		step int
	}

	ops := []func(int, int) int{
		func(x, y int) int { return x + y },
		func(x, y int) int { return x - y },
		func(x, y int) int { return x ^ y },
	}
	vis := make([]bool, 1001)
	q := []pair{{start, 0}}

	for len(q) > 0 {
		x, step := q[0].x, q[0].step
		q = q[1:]
		for _, num := range nums {
			for _, op := range ops {
				nx := op(x, num)
				if nx == goal {
					return step + 1
				}
				if nx >= 0 && nx <= 1000 && !vis[nx] {
					q = append(q, pair{nx, step + 1})
					vis[nx] = true
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumOperations(nums: number[], start: number, goal: number): number {
    const n = nums.length;
    const op1 = function (x: number, y: number): number {
        return x + y;
    };
    const op2 = function (x: number, y: number): number {
        return x - y;
    };
    const op3 = function (x: number, y: number): number {
        return x ^ y;
    };
    const ops = [op1, op2, op3];
    let vis = new Array(1001).fill(false);
    let quenue: Array<Array<number>> = [[start, 0]];
    vis[start] = true;
    while (quenue.length) {
        let [x, step] = quenue.shift();
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < ops.length; j++) {
                const nx = ops[j](x, nums[i]);
                if (nx == goal) {
                    return step + 1;
                }
                if (nx >= 0 && nx <= 1000 && !vis[nx]) {
                    vis[nx] = true;
                    quenue.push([nx, step + 1]);
                }
            }
        }
    }
    return -1;
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
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        def next(x):
            res = []
            for num in nums:
                res.append(x + num)
                res.append(x - num)
                res.append(x ^ num)
            return res

        q = deque([start])
        vis = {start}
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                x = q.popleft()
                for y in next(x):
                    if y == goal:
                        return ans
                    if 0 <= y <= 1000 and y not in vis:
                        vis.add(y)
                        q.append(y)
        return -1
```

#### Java

```java
class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(start);
        boolean[] vis = new boolean[1001];
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int n = q.size(); n > 0; --n) {
                int x = q.poll();
                for (int y : next(nums, x)) {
                    if (y == goal) {
                        return ans;
                    }
                    if (y >= 0 && y <= 1000 && !vis[y]) {
                        vis[y] = true;
                        q.offer(y);
                    }
                }
            }
        }
        return -1;
    }

    private List<Integer> next(int[] nums, int x) {
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            res.add(x + num);
            res.add(x - num);
            res.add(x ^ num);
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q{{start}};
        vector<bool> vis(1001);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int n = q.size(); n > 0; --n) {
                int x = q.front();
                q.pop();
                for (int y : next(nums, x)) {
                    if (y == goal) return ans;
                    if (y >= 0 && y <= 1000 && !vis[y]) {
                        vis[y] = true;
                        q.push(y);
                    }
                }
            }
        }
        return -1;
    }

    vector<int> next(vector<int>& nums, int x) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(x + num);
            res.push_back(x - num);
            res.push_back(x ^ num);
        }
        return res;
    }
};
```

#### Go

```go
func minimumOperations(nums []int, start int, goal int) int {
	next := func(x int) []int {
		var res []int
		for _, num := range nums {
			res = append(res, []int{x + num, x - num, x ^ num}...)
		}
		return res
	}
	q := []int{start}
	vis := make([]bool, 1001)
	ans := 0
	for len(q) > 0 {
		ans++
		for n := len(q); n > 0; n-- {
			x := q[0]
			q = q[1:]
			for _, y := range next(x) {
				if y == goal {
					return ans
				}
				if y >= 0 && y <= 1000 && !vis[y] {
					vis[y] = true
					q = append(q, y)
				}
			}
		}
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        def next(x):
            res = []
            for num in nums:
                res.append(x + num)
                res.append(x - num)
                res.append(x ^ num)
            return res

        def extend(m1, m2, q):
            for _ in range(len(q)):
                x = q.popleft()
                step = m1[x]
                for y in next(x):
                    if y in m1:
                        continue
                    if y in m2:
                        return step + 1 + m2[y]
                    if 0 <= y <= 1000:
                        m1[y] = step + 1
                        q.append(y)
            return -1

        m1, m2 = {start: 0}, {goal: 0}
        q1, q2 = deque([start]), deque([goal])
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t
        return -1
```

#### Java

```java
class Solution {
    private int[] nums;

    public int minimumOperations(int[] nums, int start, int goal) {
        this.nums = nums;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        Deque<Integer> q1 = new ArrayDeque<>();
        Deque<Integer> q2 = new ArrayDeque<>();
        m1.put(start, 0);
        m2.put(goal, 0);
        q1.offer(start);
        q2.offer(goal);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<Integer, Integer> m1, Map<Integer, Integer> m2, Deque<Integer> q) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.poll();
            int step = m1.get(x);
            for (int y : next(x)) {
                if (m1.containsKey(y)) {
                    continue;
                }
                if (m2.containsKey(y)) {
                    return step + 1 + m2.get(y);
                }
                if (y >= 0 && y <= 1000) {
                    m1.put(y, step + 1);
                    q.offer(y);
                }
            }
        }
        return -1;
    }

    private List<Integer> next(int x) {
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            res.add(x + num);
            res.add(x - num);
            res.add(x ^ num);
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        m1[start] = 0;
        m2[goal] = 0;
        queue<int> q1{{start}};
        queue<int> q2{{goal}};
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1, nums) : extend(m2, m1, q2, nums);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<int, int>& m1, unordered_map<int, int>& m2, queue<int>& q, vector<int>& nums) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.front();
            int step = m1[x];
            q.pop();
            for (int y : next(nums, x)) {
                if (m1.count(y)) continue;
                if (m2.count(y)) return step + 1 + m2[y];
                if (y >= 0 && y <= 1000) {
                    m1[y] = step + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }

    vector<int> next(vector<int>& nums, int x) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(x + num);
            res.push_back(x - num);
            res.push_back(x ^ num);
        }
        return res;
    }
};
```

#### Go

```go
func minimumOperations(nums []int, start int, goal int) int {
	next := func(x int) []int {
		var res []int
		for _, num := range nums {
			res = append(res, []int{x + num, x - num, x ^ num}...)
		}
		return res
	}
	m1, m2 := map[int]int{start: 0}, map[int]int{goal: 0}
	q1, q2 := []int{start}, []int{goal}
	extend := func() int {
		for i := len(q1); i > 0; i-- {
			x := q1[0]
			q1 = q1[1:]
			step, _ := m1[x]
			for _, y := range next(x) {
				if _, ok := m1[y]; ok {
					continue
				}
				if v, ok := m2[y]; ok {
					return step + 1 + v
				}
				if y >= 0 && y <= 1000 {
					m1[y] = step + 1
					q1 = append(q1, y)
				}
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) > len(q2) {
			m1, m2 = m2, m1
			q1, q2 = q2, q1
		}
		t := extend()
		if t != -1 {
			return t
		}
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
