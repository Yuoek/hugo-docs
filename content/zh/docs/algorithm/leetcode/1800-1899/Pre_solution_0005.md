---
title: "1840_最高建筑高度"
date: 2025-10-08T18:38:27+08:00
weight: 5
tags: [二分查找, 双指针, 回溯, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 有序集合, 枚举, 设计, 贪心]
---

{{< markmap >}}
### [1840_最高建筑高度](#1840)
#### [数组](#1840)
#### [数学](#1840)
#### [排序](#1840)
### [1841_联赛信息统计 🔒](#1841)
#### [数据库](#1841)
### [1842_下个由相同数字构成的回文串 🔒](#1842)
#### [双指针](#1842)
#### [字符串](#1842)
### [1843_可疑银行账户 🔒](#1843)
#### [数据库](#1843)
### [1844_将所有数字用字符替换](#1844)
#### [字符串](#1844)
### [1845_座位预约管理系统](#1845)
#### [设计](#1845)
#### [堆（优先队列）](#1845)
### [1846_减小和重新排列数组后的最大元素](#1846)
#### [贪心](#1846)
#### [数组](#1846)
#### [排序](#1846)
### [1847_最近的房间](#1847)
#### [数组](#1847)
#### [二分查找](#1847)
#### [有序集合](#1847)
#### [排序](#1847)
### [1848_到目标元素的最小距离](#1848)
#### [数组](#1848)
### [1849_将字符串拆分为递减的连续值](#1849)
#### [字符串](#1849)
#### [回溯](#1849)
#### [枚举](#1849)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1840_最高建筑高度
___
#### 数组
___
#### 数学
___
#### 排序
---
### 1841_联赛信息统计 🔒
___
#### 数据库
---
### 1842_下个由相同数字构成的回文串 🔒
___
#### 双指针
___
#### 字符串
---
### 1843_可疑银行账户 🔒
___
#### 数据库
---
### 1844_将所有数字用字符替换
___
#### 字符串
---
### 1845_座位预约管理系统
___
#### 设计
___
#### 堆（优先队列）
---
### 1846_减小和重新排列数组后的最大元素
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1847_最近的房间
___
#### 数组
___
#### 二分查找
___
#### 有序集合
___
#### 排序
---
### 1848_到目标元素的最小距离
___
#### 数组
---
### 1849_将字符串拆分为递减的连续值
___
#### 字符串
___
#### 回溯
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 双指针 | 回溯 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 枚举 | 设计 |
| 贪心 |  |  |

# [1840. 最高建筑高度](https://leetcode.cn/problems/maximum-building-height){#1840}

{{< tabs "1840" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        r = restrictions
        r.append([1, 0])
        r.sort()
        if r[-1][0] != n:
            r.append([n, n - 1])
        m = len(r)
        for i in range(1, m):
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0])
        for i in range(m - 2, 0, -1):
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0])
        ans = 0
        for i in range(m - 1):
            t = (r[i][1] + r[i + 1][1] + r[i + 1][0] - r[i][0]) // 2
            ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxBuilding(int n, int[][] restrictions) {
        List<int[]> r = new ArrayList<>();
        r.addAll(Arrays.asList(restrictions));
        r.add(new int[] {1, 0});
        Collections.sort(r, (a, b) -> a[0] - b[0]);
        if (r.get(r.size() - 1)[0] != n) {
            r.add(new int[] {n, n - 1});
        }
        int m = r.size();
        for (int i = 1; i < m; ++i) {
            int[] a = r.get(i - 1), b = r.get(i);
            b[1] = Math.min(b[1], a[1] + b[0] - a[0]);
        }
        for (int i = m - 2; i > 0; --i) {
            int[] a = r.get(i), b = r.get(i + 1);
            a[1] = Math.min(a[1], b[1] + b[0] - a[0]);
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int[] a = r.get(i), b = r.get(i + 1);
            int t = (a[1] + b[1] + b[0] - a[0]) / 2;
            ans = Math.max(ans, t);
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
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;
        r.push_back({1, 0});
        ranges::sort(r);
        if (r[r.size() - 1][0] != n) {
            r.push_back({n, n - 1});
        }
        int m = r.size();
        for (int i = 1; i < m; ++i) {
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        }
        for (int i = m - 2; i > 0; --i) {
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int t = (r[i][1] + r[i + 1][1] + r[i + 1][0] - r[i][0]) / 2;
            ans = max(ans, t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxBuilding(n int, restrictions [][]int) (ans int) {
	r := restrictions
	r = append(r, []int{1, 0})
	sort.Slice(r, func(i, j int) bool { return r[i][0] < r[j][0] })
	if r[len(r)-1][0] != n {
		r = append(r, []int{n, n - 1})
	}
	m := len(r)
	for i := 1; i < m; i++ {
		r[i][1] = min(r[i][1], r[i-1][1]+r[i][0]-r[i-1][0])
	}
	for i := m - 2; i > 0; i-- {
		r[i][1] = min(r[i][1], r[i+1][1]+r[i+1][0]-r[i][0])
	}
	for i := 0; i < m-1; i++ {
		t := (r[i][1] + r[i+1][1] + r[i+1][0] - r[i][0]) / 2
		ans = max(ans, t)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxBuilding(n: number, restrictions: number[][]): number {
    restrictions.push([1, 0]);
    restrictions.sort((a, b) => a[0] - b[0]);
    if (restrictions[restrictions.length - 1][0] !== n) {
        restrictions.push([n, n - 1]);
    }

    const m = restrictions.length;
    for (let i = 1; i < m; ++i) {
        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0],
        );
    }

    for (let i = m - 2; i >= 0; --i) {
        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0],
        );
    }

    let ans = 0;
    for (let i = 0; i < m - 1; ++i) {
        const t = Math.floor(
            (restrictions[i][1] +
                restrictions[i + 1][1] +
                restrictions[i + 1][0] -
                restrictions[i][0]) /
                2,
        );
        ans = Math.max(ans, t);
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

<p>在一座城市里，你需要建 <code>n</code> 栋新的建筑。这些新的建筑会从 <code>1</code> 到 <code>n</code> 编号排成一列。</p>

<p>这座城市对这些新建筑有一些规定：</p>

<ul>
	<li>每栋建筑的高度必须是一个非负整数。</li>
	<li>第一栋建筑的高度 <strong>必须</strong> 是 <code>0</code> 。</li>
	<li>任意两栋相邻建筑的高度差 <strong>不能超过</strong>  <code>1</code> 。</li>
</ul>

<p>除此以外，某些建筑还有额外的最高高度限制。这些限制会以二维整数数组 <code>restrictions</code> 的形式给出，其中 <code>restrictions[i] = [id<sub>i</sub>, maxHeight<sub>i</sub>]</code> ，表示建筑 <code>id<sub>i</sub></code> 的高度 <strong>不能超过</strong> <code>maxHeight<sub>i</sub></code> 。</p>

<p>题目保证每栋建筑在 <code>restrictions</code> 中<strong> 至多出现一次</strong> ，同时建筑 <code>1</code> <strong>不会</strong> 出现在 <code>restrictions</code> 中。</p>

<p>请你返回 <strong>最高</strong> 建筑能达到的 <strong>最高高度</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1840.Maximum%20Building%20Height/images/ic236-q4-ex1-1.png" style="width: 400px; height: 253px;" />
<pre>
<b>输入：</b>n = 5, restrictions = [[2,1],[4,1]]
<b>输出：</b>2
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,1,2] ，最高建筑的高度为 2 。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1840.Maximum%20Building%20Height/images/ic236-q4-ex2.png" style="width: 500px; height: 269px;" />
<pre>
<b>输入：</b>n = 6, restrictions = []
<b>输出：</b>5
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,4,5] ，最高建筑的高度为 5 。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1840.Maximum%20Building%20Height/images/ic236-q4-ex3.png" style="width: 500px; height: 187px;" />
<pre>
<b>输入：</b>n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
<b>输出：</b>5
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,3,4,4,5,4,3] ，最高建筑的高度为 5 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10<sup>9</sup></code></li>
	<li><code>0 <= restrictions.length <= min(n - 1, 10<sup>5</sup>)</code></li>
	<li><code>2 <= id<sub>i</sub> <= n</code></li>
	<li><code>id<sub>i</sub></code> 是 <strong>唯一的</strong> 。</li>
	<li><code>0 <= maxHeight<sub>i</sub> <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 数学

首先，我们将所有的限制条件按照建筑物的编号从小到大排序。

然后我们从左到右遍历所有的限制条件，对于每个限制条件，我们可以得到一个最高高度的上界，即 $r_i[1] = \min(r_i[1], r_{i-1}[1] + r_i[0] - r_{i-1}[0])$，其中 $r_i$ 表示第 $i$ 个限制条件，而 $r_i[0]$ 和 $r_i[1]$ 分别表示建筑物的编号以及建筑物的最高高度的上界。

然后我们从右到左遍历所有的限制条件，对于每个限制条件，我们可以得到一个最高高度的上界，即 $r_i[1] = \min(r_i[1], r_{i+1}[1] + r_{i+1}[0] - r_i[0])$。

这样，我们就得到了每个限制建筑物的最高高度的上界。

题目求的是最高建筑物的高度，我们可以枚举相邻两个限制条件之间的建筑物 $i$ 和 $i+1$，要使得高度最大，那么高度应该是先增大后减小，假设最大高度为 $t$，那么 $t - r_i[1] + t - r_{i+1}[1] \leq r_{i+1}[0] - r_i[0]$，即 $t \leq \frac{r_i[1] + r_{i+1}[1] + r_{i+1}[0] - r_{i}[0]}{2}$，我们取所有的 $t$ 中的最大值即可。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 为限制条件的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        r = restrictions
        r.append([1, 0])
        r.sort()
        if r[-1][0] != n:
            r.append([n, n - 1])
        m = len(r)
        for i in range(1, m):
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0])
        for i in range(m - 2, 0, -1):
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0])
        ans = 0
        for i in range(m - 1):
            t = (r[i][1] + r[i + 1][1] + r[i + 1][0] - r[i][0]) // 2
            ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public int maxBuilding(int n, int[][] restrictions) {
        List<int[]> r = new ArrayList<>();
        r.addAll(Arrays.asList(restrictions));
        r.add(new int[] {1, 0});
        Collections.sort(r, (a, b) -> a[0] - b[0]);
        if (r.get(r.size() - 1)[0] != n) {
            r.add(new int[] {n, n - 1});
        }
        int m = r.size();
        for (int i = 1; i < m; ++i) {
            int[] a = r.get(i - 1), b = r.get(i);
            b[1] = Math.min(b[1], a[1] + b[0] - a[0]);
        }
        for (int i = m - 2; i > 0; --i) {
            int[] a = r.get(i), b = r.get(i + 1);
            a[1] = Math.min(a[1], b[1] + b[0] - a[0]);
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int[] a = r.get(i), b = r.get(i + 1);
            int t = (a[1] + b[1] + b[0] - a[0]) / 2;
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;
        r.push_back({1, 0});
        ranges::sort(r);
        if (r[r.size() - 1][0] != n) {
            r.push_back({n, n - 1});
        }
        int m = r.size();
        for (int i = 1; i < m; ++i) {
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        }
        for (int i = m - 2; i > 0; --i) {
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int t = (r[i][1] + r[i + 1][1] + r[i + 1][0] - r[i][0]) / 2;
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maxBuilding(n int, restrictions [][]int) (ans int) {
	r := restrictions
	r = append(r, []int{1, 0})
	sort.Slice(r, func(i, j int) bool { return r[i][0] < r[j][0] })
	if r[len(r)-1][0] != n {
		r = append(r, []int{n, n - 1})
	}
	m := len(r)
	for i := 1; i < m; i++ {
		r[i][1] = min(r[i][1], r[i-1][1]+r[i][0]-r[i-1][0])
	}
	for i := m - 2; i > 0; i-- {
		r[i][1] = min(r[i][1], r[i+1][1]+r[i+1][0]-r[i][0])
	}
	for i := 0; i < m-1; i++ {
		t := (r[i][1] + r[i+1][1] + r[i+1][0] - r[i][0]) / 2
		ans = max(ans, t)
	}
	return ans
}
```

#### TypeScript

```ts
function maxBuilding(n: number, restrictions: number[][]): number {
    restrictions.push([1, 0]);
    restrictions.sort((a, b) => a[0] - b[0]);
    if (restrictions[restrictions.length - 1][0] !== n) {
        restrictions.push([n, n - 1]);
    }

    const m = restrictions.length;
    for (let i = 1; i < m; ++i) {
        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0],
        );
    }

    for (let i = m - 2; i >= 0; --i) {
        restrictions[i][1] = Math.min(
            restrictions[i][1],
            restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0],
        );
    }

    let ans = 0;
    for (let i = 0; i < m - 1; ++i) {
        const t = Math.floor(
            (restrictions[i][1] +
                restrictions[i + 1][1] +
                restrictions[i + 1][0] -
                restrictions[i][0]) /
                2,
        );
        ans = Math.max(ans, t);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1841. 联赛信息统计 🔒](https://leetcode.cn/problems/league-statistics){#1841}

{{< tabs "1841" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    Scores AS (
        SELECT
            home_team_id AS team_id,
            CASE
                WHEN home_team_goals > away_team_goals THEN 3
                WHEN home_team_goals < away_team_goals THEN 0
                ELSE 1
            END AS score,
            home_team_goals AS goals,
            away_team_goals AS away_goals
        FROM Matches
        UNION ALL
        SELECT
            away_team_id AS team_id,
            CASE
                WHEN home_team_goals > away_team_goals THEN 0
                WHEN home_team_goals < away_team_goals THEN 3
                ELSE 1
            END AS score,
            away_team_goals AS goals,
            home_team_goals AS away_goals
        FROM Matches
    )
SELECT
    team_name,
    COUNT(1) AS matches_played,
    SUM(score) AS points,
    SUM(goals) AS goal_for,
    SUM(away_goals) AS goal_against,
    (SUM(goals) - SUM(away_goals)) AS goal_diff
FROM
    Scores AS s
    JOIN Teams AS t ON s.team_id = t.team_id
GROUP BY s.team_id
ORDER BY points DESC, goal_diff DESC, team_name;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Teams</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| team_id        | int     |
| team_name      | varchar |
+----------------+---------+
team_id 是该表主键.
每一行都包含了一个参加联赛的队伍信息.
</pre>

<p>&nbsp;</p>

<p>表: <code>Matches</code></p>

<pre>
+-----------------+---------+
| Column Name     | Type    |
+-----------------+---------+
| home_team_id    | int     |
| away_team_id    | int     |
| home_team_goals | int     |
| away_team_goals | int     |
+-----------------+---------+
(home_team_id, away_team_id) 是该表主键.
每一行包含了一次比赛信息.
home_team_goals 代表主场队得球数.
away_team_goals 代表客场队得球数.
获得球数较多的队伍为胜者队伍.
</pre>

<p>&nbsp;</p>

<p>写一段SQL，用来报告联赛信息. 统计数据应使用已进行的比赛来构建，其中 <strong>获胜</strong> 球队获得 <strong>三分</strong> ，而失败球队获得<strong> 零分</strong>&nbsp;。如果 <strong>打平 </strong>，两支球队都得&nbsp;<strong>一分&nbsp;</strong>。</p>

<p>result 表的每行应包含以下信息:</p>

<ul>
	<li><code>team_name</code> - <code>Teams</code> 表中的队伍名字</li>
	<li><code>matches_played</code> - 主场与客场球队进行的比赛次数.</li>
	<li><code>points</code> - 球队获得的总分数.</li>
	<li><code>goal_for</code> - 球队在所有比赛中获取的总进球数</li>
	<li><code>goal_against</code> - 球队在所有比赛中，他的对手球队的所有进球数</li>
	<li><code>goal_diff</code> - <code>goal_for - goal_against</code>.</li>
</ul>

<p>按 <code>points</code> <strong>降序</strong> 返回结果表。 如果两队或多队得分相同，则按 <code>goal_diff</code> <strong>降序</strong> 排列。 如果仍然存在平局，则以&nbsp;<code>team_name</code> <strong>按字典顺序</strong> 排列它们。</p>

<p>查询的结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Teams 表:
+---------+-----------+
| team_id | team_name |
+---------+-----------+
| 1       | Ajax      |
| 4       | Dortmund  |
| 6       | Arsenal   |
+---------+-----------+
Matches 表:
+--------------+--------------+-----------------+-----------------+
| home_team_id | away_team_id | home_team_goals | away_team_goals |
+--------------+--------------+-----------------+-----------------+
| 1            | 4            | 0               | 1               |
| 1            | 6            | 3               | 3               |
| 4            | 1            | 5               | 2               |
| 6            | 1            | 0               | 0               |
+--------------+--------------+-----------------+-----------------+
<strong>输出：</strong>
+-----------+----------------+--------+----------+--------------+-----------+
| team_name | matches_played | points | goal_for | goal_against | goal_diff |
+-----------+----------------+--------+----------+--------------+-----------+
| Dortmund  | 2              | 6      | 6        | 2            | 4         |
| Arsenal   | 2              | 2      | 3        | 3            | 0         |
| Ajax      | 4              | 2      | 5        | 9            | -4        |
+-----------+----------------+--------+----------+--------------+-----------+
<strong>解释：</strong>
Ajax (team_id=1) 有4场比赛: 2败2平. 总分数 = 0 + 0 + 1 + 1 = 2.
Dortmund (team_id=4) 有2场比赛: 2胜. 总分数 = 3 + 3 = 6.
Arsenal (team_id=6) 有2场比赛: 2平. 总分数 = 1 + 1 = 2.
Dortmund 是积分榜上的第一支球队. Ajax和Arsenal 有同样的分数, 但Arsenal的goal_diff高于Ajax, 所以Arsenal在表中的顺序在Ajaxzhi'qian.</pre>

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
WITH
    Scores AS (
        SELECT
            home_team_id AS team_id,
            CASE
                WHEN home_team_goals > away_team_goals THEN 3
                WHEN home_team_goals < away_team_goals THEN 0
                ELSE 1
            END AS score,
            home_team_goals AS goals,
            away_team_goals AS away_goals
        FROM Matches
        UNION ALL
        SELECT
            away_team_id AS team_id,
            CASE
                WHEN home_team_goals > away_team_goals THEN 0
                WHEN home_team_goals < away_team_goals THEN 3
                ELSE 1
            END AS score,
            away_team_goals AS goals,
            home_team_goals AS away_goals
        FROM Matches
    )
SELECT
    team_name,
    COUNT(1) AS matches_played,
    SUM(score) AS points,
    SUM(goals) AS goal_for,
    SUM(away_goals) AS goal_against,
    (SUM(goals) - SUM(away_goals)) AS goal_diff
FROM
    Scores AS s
    JOIN Teams AS t ON s.team_id = t.team_id
GROUP BY s.team_id
ORDER BY points DESC, goal_diff DESC, team_name;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1842. 下个由相同数字构成的回文串 🔒](https://leetcode.cn/problems/next-palindrome-using-same-digits){#1842}

{{< tabs "1842" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextPalindrome(self, num: str) -> str:
        def next_permutation(nums: List[str]) -> bool:
            n = len(nums) // 2
            i = n - 2
            while i >= 0 and nums[i] >= nums[i + 1]:
                i -= 1
            if i < 0:
                return False
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1 : n] = nums[i + 1 : n][::-1]
            return True

        nums = list(num)
        if not next_permutation(nums):
            return ""
        n = len(nums)
        for i in range(n // 2):
            nums[n - i - 1] = nums[i]
        return "".join(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String nextPalindrome(String num) {
        char[] nums = num.toCharArray();
        if (!nextPermutation(nums)) {
            return "";
        }
        int n = nums.length;
        for (int i = 0; i < n / 2; ++i) {
            nums[n - 1 - i] = nums[i];
        }
        return String.valueOf(nums);
    }

    private boolean nextPermutation(char[] nums) {
        int n = nums.length / 2;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {
            return false;
        }
        int j = n - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            --j;
        }
        swap(nums, i++, j);
        for (j = n - 1; i < j; ++i, --j) {
            swap(nums, i, j);
        }
        return true;
    }

    private void swap(char[] nums, int i, int j) {
        char t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        string nums = num.substr(0, n / 2);
        if (!next_permutation(begin(nums), end(nums))) {
            return "";
        }
        for (int i = 0; i < n / 2; ++i) {
            num[i] = nums[i];
            num[n - i - 1] = nums[i];
        }
        return num;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextPalindrome(num string) string {
	nums := []byte(num)
	n := len(nums)
	if !nextPermutation(nums) {
		return ""
	}
	for i := 0; i < n/2; i++ {
		nums[n-1-i] = nums[i]
	}
	return string(nums)
}

func nextPermutation(nums []byte) bool {
	n := len(nums) / 2
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return false
	}
	j := n - 1
	for j >= 0 && nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	for i, j = i+1, n-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nextPalindrome(num: string): string {
    const nums = num.split('');
    const n = nums.length;
    if (!nextPermutation(nums)) {
        return '';
    }
    for (let i = 0; i < n >> 1; ++i) {
        nums[n - 1 - i] = nums[i];
    }
    return nums.join('');
}

function nextPermutation(nums: string[]): boolean {
    const n = nums.length >> 1;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    let j = n - 1;
    while (j >= 0 && nums[i] >= nums[j]) {
        j--;
    }
    [nums[i], nums[j]] = [nums[j], nums[i]];
    for (i = i + 1, j = n - 1; i < j; ++i, --j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个很长的数字回文串 <code>num</code> ，返回 <strong>大于</strong> <code>num</code>、<strong>由相同数字重新组合而成的最小</strong> 回文串。</p>

<p>如果不存在这样的回文串，则返回空串 <code>""</code>。</p>

<p><strong>回文串</strong> 是正读和反读都一样的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = "1221"
<b>输出：</b>"2112"
<b>解释：</b>下个比<b> </b>"1221" 大的回文串是 "2112"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = "32123"
<b>输出：</b>""
<b>解释：</b>不存在通过重组 "32123" 的数字可得、比 "32123" 还大的回文串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>num = "45544554"
<b>输出：</b>"54455445"
<b>解释：</b>下个比 "45544554" 还要大的回文串是 "54455445"。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num</code> 是回文串。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求前一半的下一个排列

根据题目描述，我们只需要求出前一半的下一个排列，然后遍历前一半，对称赋值后半部分即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextPalindrome(self, num: str) -> str:
        def next_permutation(nums: List[str]) -> bool:
            n = len(nums) // 2
            i = n - 2
            while i >= 0 and nums[i] >= nums[i + 1]:
                i -= 1
            if i < 0:
                return False
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1 : n] = nums[i + 1 : n][::-1]
            return True

        nums = list(num)
        if not next_permutation(nums):
            return ""
        n = len(nums)
        for i in range(n // 2):
            nums[n - i - 1] = nums[i]
        return "".join(nums)
```

#### Java

```java
class Solution {
    public String nextPalindrome(String num) {
        char[] nums = num.toCharArray();
        if (!nextPermutation(nums)) {
            return "";
        }
        int n = nums.length;
        for (int i = 0; i < n / 2; ++i) {
            nums[n - 1 - i] = nums[i];
        }
        return String.valueOf(nums);
    }

    private boolean nextPermutation(char[] nums) {
        int n = nums.length / 2;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {
            return false;
        }
        int j = n - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            --j;
        }
        swap(nums, i++, j);
        for (j = n - 1; i < j; ++i, --j) {
            swap(nums, i, j);
        }
        return true;
    }

    private void swap(char[] nums, int i, int j) {
        char t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        string nums = num.substr(0, n / 2);
        if (!next_permutation(begin(nums), end(nums))) {
            return "";
        }
        for (int i = 0; i < n / 2; ++i) {
            num[i] = nums[i];
            num[n - i - 1] = nums[i];
        }
        return num;
    }
};
```

#### Go

```go
func nextPalindrome(num string) string {
	nums := []byte(num)
	n := len(nums)
	if !nextPermutation(nums) {
		return ""
	}
	for i := 0; i < n/2; i++ {
		nums[n-1-i] = nums[i]
	}
	return string(nums)
}

func nextPermutation(nums []byte) bool {
	n := len(nums) / 2
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return false
	}
	j := n - 1
	for j >= 0 && nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	for i, j = i+1, n-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return true
}
```

#### TypeScript

```ts
function nextPalindrome(num: string): string {
    const nums = num.split('');
    const n = nums.length;
    if (!nextPermutation(nums)) {
        return '';
    }
    for (let i = 0; i < n >> 1; ++i) {
        nums[n - 1 - i] = nums[i];
    }
    return nums.join('');
}

function nextPermutation(nums: string[]): boolean {
    const n = nums.length >> 1;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    let j = n - 1;
    while (j >= 0 && nums[i] >= nums[j]) {
        j--;
    }
    [nums[i], nums[j]] = [nums[j], nums[i]];
    for (i = i + 1, j = n - 1; i < j; ++i, --j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1843. 可疑银行账户 🔒](https://leetcode.cn/problems/suspicious-bank-accounts){#1843}

{{< tabs "1843" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            account_id,
            DATE_FORMAT(day, '%Y%m') AS yearmonth,
            transaction_id AS tx
        FROM
            Transactions
            JOIN Accounts USING (account_id)
        WHERE type = 'Creditor'
        GROUP BY account_id, yearmonth
        HAVING SUM(amount) > AVG(max_income)
    )
SELECT DISTINCT account_id
FROM S
WHERE (account_id, PERIOD_ADD(yearmonth, 1)) IN (SELECT account_id, yearmonth FROM S)
ORDER BY tx;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Accounts</code></p>

<pre>
+----------------+------+
| Column Name    | Type |
+----------------+------+
| account_id     | int  |
| max_income     | int  |
+----------------+------+
account_id 是这张表具有唯一值的列。
每行包含一个银行账户每月最大收入的信息。
</pre>

<p>&nbsp;</p>

<p>表: <code>Transactions</code></p>

<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| transaction_id | int      |
| account_id     | int      |
| type           | ENUM     |
| amount         | int      |
| day            | datetime |
+----------------+----------+
transaction_id 是这张表具有唯一值的列。
每行包含一条转账信息。
type 是枚举类型（包含'Creditor','Debtor'），其中 'Creditor' 表示用户向其账户存入资金，'Debtor' 表示用户从其账户取出资金。
amount 是交易过程中的存入/取出的金额。
</pre>

<p>&nbsp;</p>

<p>如果一个账户在&nbsp;<strong>连续两个及以上&nbsp;</strong>月份的&nbsp;<strong>总收入&nbsp;</strong>超过最大收入（<code>max_income</code>），那么认为这个账户&nbsp;<strong>可疑</strong>。&nbsp; 账户当月&nbsp;<strong>总收入&nbsp;</strong>是当月存入资金总数（即 transactions 表中 type 字段的&nbsp;<code>'Creditor'</code>）。</p>

<p>编写一个解决方案，报告所有的&nbsp;<strong>可疑&nbsp;</strong>账户。</p>

<p>以 <strong>任意顺序</strong> 返回结果表</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Accounts 表:
+------------+------------+
| account_id | max_income |
+------------+------------+
| 3          | 21000      |
| 4          | 10400      |
+------------+------------+
Transactions 表:
+----------------+------------+----------+--------+---------------------+
| transaction_id | account_id | type     | amount | day                 |
+----------------+------------+----------+--------+---------------------+
| 2              | 3          | Creditor | 107100 | 2021-06-02 11:38:14 |
| 4              | 4          | Creditor | 10400  | 2021-06-20 12:39:18 |
| 11             | 4          | Debtor   | 58800  | 2021-07-23 12:41:55 |
| 1              | 4          | Creditor | 49300  | 2021-05-03 16:11:04 |
| 15             | 3          | Debtor   | 75500  | 2021-05-23 14:40:20 |
| 10             | 3          | Creditor | 102100 | 2021-06-15 10:37:16 |
| 14             | 4          | Creditor | 56300  | 2021-07-21 12:12:25 |
| 19             | 4          | Debtor   | 101100 | 2021-05-09 15:21:49 |
| 8              | 3          | Creditor | 64900  | 2021-07-26 15:09:56 |
| 7              | 3          | Creditor | 90900  | 2021-06-14 11:23:07 |
+----------------+------------+----------+--------+---------------------+
<strong>输出：</strong>
+------------+
| account_id |
+------------+
| 3          |
+------------+
<strong>解释：</strong>
对于账户 3：
- 在 2021年6月，用户收入为 107100 + 102100 + 90900 = 300100。
- 在 2021年7月，用户收入为 64900。
可见收入连续两月超过21000的最大收入，因此账户3列入结果表中。

对于账户 4：
- 在 2021年5月，用户收入为 49300。
- 在 2021年6月，用户收入为 10400。
- 在 2021年7月，用户收入为 56300。
可见收入在5月与7月超过了最大收入，但6月没有。因为账户没有没有连续两月超过最大收入，账户4不列入结果表中。</pre>

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
WITH
    S AS (
        SELECT DISTINCT
            t.account_id,
            DATE_FORMAT(day, '%Y-%m-01') AS day,
            transaction_id AS tx,
            SUM(amount) OVER (
                PARTITION BY account_id, DATE_FORMAT(day, '%Y-%m-01')
            ) > max_income AS marked
        FROM
            Transactions AS t
            LEFT JOIN Accounts AS a ON t.account_id = a.account_id
        WHERE type = 'Creditor'
    )
SELECT DISTINCT s1.account_id
FROM
    S AS s1
    LEFT JOIN S AS s2 ON s1.account_id = s2.account_id AND TIMESTAMPDIFF(Month, s1.day, s2.day) = 1
WHERE s1.marked = 1 AND s2.marked = 1
ORDER BY s1.tx;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            account_id,
            DATE_FORMAT(day, '%Y%m') AS yearmonth,
            transaction_id AS tx
        FROM
            Transactions
            JOIN Accounts USING (account_id)
        WHERE type = 'Creditor'
        GROUP BY account_id, yearmonth
        HAVING SUM(amount) > AVG(max_income)
    )
SELECT DISTINCT account_id
FROM S
WHERE (account_id, PERIOD_ADD(yearmonth, 1)) IN (SELECT account_id, yearmonth FROM S)
ORDER BY tx;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1844. 将所有数字用字符替换](https://leetcode.cn/problems/replace-all-digits-with-characters){#1844}

{{< tabs "1844" >}}

{{% tab "python" %}}
```python
class Solution:
    def replaceDigits(self, s: str) -> str:
        s = list(s)
        for i in range(1, len(s), 2):
            s[i] = chr(ord(s[i - 1]) + int(s[i]))
        return ''.join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String replaceDigits(String s) {
        char[] cs = s.toCharArray();
        for (int i = 1; i < cs.length; i += 2) {
            cs[i] = (char) (cs[i - 1] + (cs[i] - '0'));
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            s[i] = s[i - 1] + s[i] - '0';
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func replaceDigits(s string) string {
	cs := []byte(s)
	for i := 1; i < len(s); i += 2 {
		cs[i] = cs[i-1] + cs[i] - '0'
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function replaceDigits(s: string): string {
    const n = s.length;
    const ans = [...s];
    for (let i = 1; i < n; i += 2) {
        ans[i] = String.fromCharCode(ans[i - 1].charCodeAt(0) + Number(ans[i]));
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn replace_digits(s: String) -> String {
        let n = s.len();
        let mut ans = s.into_bytes();
        let mut i = 1;
        while i < n {
            ans[i] = ans[i - 1] + (ans[i] - b'0');
            i += 2;
        }
        ans.into_iter().map(char::from).collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* replaceDigits(char* s) {
    int n = strlen(s);
    for (int i = 1; i < n; i += 2) {
        s[i] = s[i - 1] + s[i] - '0';
    }
    return s;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，它的 <strong>偶数</strong> 下标处为小写英文字母，<strong>奇数</strong> 下标处为数字。</p>

<p>定义一个函数 <code>shift(c, x)</code> ，其中 <code>c</code> 是一个字符且 <code>x</code> 是一个数字，函数返回字母表中 <code>c</code> 后面第 <code>x</code> 个字符。</p>

<ul>
	<li>比方说，<code>shift('a', 5) = 'f'</code> 和 <code>shift('x', 0) = 'x'</code> 。</li>
</ul>

<p>对于每个 <strong>奇数</strong> 下标 <code>i</code> ，你需要将数字 <code>s[i]</code> 用 <code>shift(s[i-1], s[i])</code> 替换。</p>

<p>请你替换所有数字以后，将字符串 <code>s</code> 返回。题目 <strong>保证</strong><em> </em><code>shift(s[i-1], s[i])</code> 不会超过 <code>'z'</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "a1c1e1"
<b>输出：</b>"abcdef"
<strong>解释：</strong>数字被替换结果如下：
- s[1] -&gt; shift('a',1) = 'b'
- s[3] -&gt; shift('c',1) = 'd'
- s[5] -&gt; shift('e',1) = 'f'</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "a1b2c3d4e"
<b>输出：</b>"abbdcfdhe"
<strong>解释：</strong>数字被替换结果如下：
- s[1] -&gt; shift('a',1) = 'b'
- s[3] -&gt; shift('b',2) = 'd'
- s[5] -&gt; shift('c',3) = 'f'
- s[7] -&gt; shift('d',4) = 'h'</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 只包含小写英文字母和数字。</li>
	<li>对所有 <strong>奇数</strong> 下标处的 <code>i</code> ，满足 <code>shift(s[i-1], s[i]) &lt;= 'z'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

遍历字符串，对于奇数下标的字符，将其替换为前一个字符后移对应位数的字符。

最后返回替换后的字符串。

时间复杂度 $(n)$，其中 $n$ 为字符串 $s$ 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def replaceDigits(self, s: str) -> str:
        s = list(s)
        for i in range(1, len(s), 2):
            s[i] = chr(ord(s[i - 1]) + int(s[i]))
        return ''.join(s)
```

#### Java

```java
class Solution {
    public String replaceDigits(String s) {
        char[] cs = s.toCharArray();
        for (int i = 1; i < cs.length; i += 2) {
            cs[i] = (char) (cs[i - 1] + (cs[i] - '0'));
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            s[i] = s[i - 1] + s[i] - '0';
        }
        return s;
    }
};
```

#### Go

```go
func replaceDigits(s string) string {
	cs := []byte(s)
	for i := 1; i < len(s); i += 2 {
		cs[i] = cs[i-1] + cs[i] - '0'
	}
	return string(cs)
}
```

#### TypeScript

```ts
function replaceDigits(s: string): string {
    const n = s.length;
    const ans = [...s];
    for (let i = 1; i < n; i += 2) {
        ans[i] = String.fromCharCode(ans[i - 1].charCodeAt(0) + Number(ans[i]));
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn replace_digits(s: String) -> String {
        let n = s.len();
        let mut ans = s.into_bytes();
        let mut i = 1;
        while i < n {
            ans[i] = ans[i - 1] + (ans[i] - b'0');
            i += 2;
        }
        ans.into_iter().map(char::from).collect()
    }
}
```

#### C

```c
char* replaceDigits(char* s) {
    int n = strlen(s);
    for (int i = 1; i < n; i += 2) {
        s[i] = s[i - 1] + s[i] - '0';
    }
    return s;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1845. 座位预约管理系统](https://leetcode.cn/problems/seat-reservation-manager){#1845}

{{< tabs "1845" >}}

{{% tab "python" %}}
```python
class SeatManager:
    def __init__(self, n: int):
        self.q = list(range(1, n + 1))

    def reserve(self) -> int:
        return heappop(self.q)

    def unreserve(self, seatNumber: int) -> None:
        heappush(self.q, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SeatManager {
    private PriorityQueue<Integer> q = new PriorityQueue<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            q.offer(i);
        }
    }

    public int reserve() {
        return q.poll();
    }

    public void unreserve(int seatNumber) {
        q.offer(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
    }

    int reserve() {
        int seat = q.top();
        q.pop();
        return seat;
    }

    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SeatManager struct {
	q hp
}

func Constructor(n int) SeatManager {
	q := hp{}
	for i := 1; i <= n; i++ {
		heap.Push(&q, i)
	}
	return SeatManager{q}
}

func (this *SeatManager) Reserve() int {
	return heap.Pop(&this.q).(int)
}

func (this *SeatManager) Unreserve(seatNumber int) {
	heap.Push(&this.q, seatNumber)
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Reserve();
 * obj.Unreserve(seatNumber);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class SeatManager {
    private q: typeof MinPriorityQueue;
    constructor(n: number) {
        this.q = new MinPriorityQueue();
        for (let i = 1; i <= n; i++) {
            this.q.enqueue(i);
        }
    }

    reserve(): number {
        return this.q.dequeue().element;
    }

    unreserve(seatNumber: number): void {
        this.q.enqueue(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * var obj = new SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class SeatManager {
    private PriorityQueue<int, int> q = new PriorityQueue<int, int>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            q.Enqueue(i, i);
        }
    }

    public int Reserve() {
        return q.Dequeue();
    }

    public void Unreserve(int seatNumber) {
        q.Enqueue(seatNumber, seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.Reserve();
 * obj.Unreserve(seatNumber);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个管理 <code>n</code> 个座位预约的系统，座位编号从 <code>1</code> 到 <code>n</code> 。</p>

<p>请你实现 <code>SeatManager</code> 类：</p>

<ul>
	<li><code>SeatManager(int n)</code> 初始化一个 <code>SeatManager</code> 对象，它管理从 <code>1</code> 到 <code>n</code> 编号的 <code>n</code> 个座位。所有座位初始都是可预约的。</li>
	<li><code>int reserve()</code> 返回可以预约座位的 <strong>最小编号</strong> ，此座位变为不可预约。</li>
	<li><code>void unreserve(int seatNumber)</code> 将给定编号 <code>seatNumber</code> 对应的座位变成可以预约。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
<strong>输出：</strong>
[null, 1, 2, null, 2, 3, 4, 5, null]

<strong>解释：</strong>
SeatManager seatManager = new SeatManager(5); // 初始化 SeatManager ，有 5 个座位。
seatManager.reserve();    // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
seatManager.reserve();    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
seatManager.unreserve(2); // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
seatManager.reserve();    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
seatManager.reserve();    // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
seatManager.reserve();    // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
seatManager.reserve();    // 唯一可以预约的是座位 5 ，所以返回 5 。
seatManager.unreserve(5); // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= seatNumber &lt;= n</code></li>
	<li>每一次对 <code>reserve</code> 的调用，题目保证至少存在一个可以预约的座位。</li>
	<li>每一次对 <code>unreserve</code> 的调用，题目保证 <code>seatNumber</code> 在调用函数前都是被预约状态。</li>
	<li>对 <code>reserve</code> 和 <code>unreserve</code> 的调用 <strong>总共</strong> 不超过 <code>10<sup>5</sup></code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们定义一个优先队列（小根堆）$\textit{q}$，用于存储所有可预约的座位编号。初始时，我们将 $1$ 到 $n$ 的所有座位编号加入到 $\textit{q}$ 中。

调用 `reserve` 方法时，我们从 $\textit{q}$ 中弹出堆顶元素，即可预约的座位编号的最小值。

调用 `unreserve` 方法时，我们将座位编号加入到 $\textit{q}$ 中。

时间复杂度方面，初始化的时间复杂度为 $O(n)$ 或 $O(n \times \log n)$，`reserve` 和 `unreserve` 方法的时间复杂度均为 $O(\log n)$。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class SeatManager:
    def __init__(self, n: int):
        self.q = list(range(1, n + 1))

    def reserve(self) -> int:
        return heappop(self.q)

    def unreserve(self, seatNumber: int) -> None:
        heappush(self.q, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
```

#### Java

```java
class SeatManager {
    private PriorityQueue<Integer> q = new PriorityQueue<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            q.offer(i);
        }
    }

    public int reserve() {
        return q.poll();
    }

    public void unreserve(int seatNumber) {
        q.offer(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */
```

#### C++

```cpp
class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
    }

    int reserve() {
        int seat = q.top();
        q.pop();
        return seat;
    }

    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
```

#### Go

```go
type SeatManager struct {
	q hp
}

func Constructor(n int) SeatManager {
	q := hp{}
	for i := 1; i <= n; i++ {
		heap.Push(&q, i)
	}
	return SeatManager{q}
}

func (this *SeatManager) Reserve() int {
	return heap.Pop(&this.q).(int)
}

func (this *SeatManager) Unreserve(seatNumber int) {
	heap.Push(&this.q, seatNumber)
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Reserve();
 * obj.Unreserve(seatNumber);
 */
```

#### TypeScript

```ts
class SeatManager {
    private q: typeof MinPriorityQueue;
    constructor(n: number) {
        this.q = new MinPriorityQueue();
        for (let i = 1; i <= n; i++) {
            this.q.enqueue(i);
        }
    }

    reserve(): number {
        return this.q.dequeue().element;
    }

    unreserve(seatNumber: number): void {
        this.q.enqueue(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * var obj = new SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */
```

#### C#

```cs
public class SeatManager {
    private PriorityQueue<int, int> q = new PriorityQueue<int, int>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            q.Enqueue(i, i);
        }
    }

    public int Reserve() {
        return q.Dequeue();
    }

    public void Unreserve(int seatNumber) {
        q.Enqueue(seatNumber, seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.Reserve();
 * obj.Unreserve(seatNumber);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1846. 减小和重新排列数组后的最大元素](https://leetcode.cn/problems/maximum-element-after-decreasing-and-rearranging){#1846}

{{< tabs "1846" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        arr[0] = 1
        for i in range(1, len(arr)):
            d = max(0, arr[i] - arr[i - 1] - 1)
            arr[i] -= d
        return max(arr)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        int ans = 1;
        for (int i = 1; i < arr.length; ++i) {
            int d = Math.max(0, arr[i] - arr[i - 1] - 1);
            arr[i] -= d;
            ans = Math.max(ans, arr[i]);
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
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int ans = 1;
        for (int i = 1; i < arr.size(); ++i) {
            int d = max(0, arr[i] - arr[i - 1] - 1);
            arr[i] -= d;
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumElementAfterDecrementingAndRearranging(arr []int) int {
	sort.Ints(arr)
	ans := 1
	arr[0] = 1
	for i := 1; i < len(arr); i++ {
		d := max(0, arr[i]-arr[i-1]-1)
		arr[i] -= d
		ans = max(ans, arr[i])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumElementAfterDecrementingAndRearranging(arr: number[]): number {
    arr.sort((a, b) => a - b);
    arr[0] = 1;
    let ans = 1;
    for (let i = 1; i < arr.length; ++i) {
        const d = Math.max(0, arr[i] - arr[i - 1] - 1);
        arr[i] -= d;
        ans = Math.max(ans, arr[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaximumElementAfterDecrementingAndRearranging(int[] arr) {
        Array.Sort(arr);
        int n = arr.Length;
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            arr[i] = Math.Min(arr[i], arr[i - 1] + 1);
        }
        return arr[n - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>arr</code> 。请你对 <code>arr</code> 执行一些操作（也可以不进行任何操作），使得数组满足以下条件：</p>

<ul>
	<li><code>arr</code> 中 <strong>第一个</strong> 元素必须为 <code>1</code> 。</li>
	<li>任意相邻两个元素的差的绝对值 <strong>小于等于</strong> <code>1</code> ，也就是说，对于任意的 <code>1 <= i < arr.length</code> （<strong>数组下标从 0 开始</strong>），都满足 <code>abs(arr[i] - arr[i - 1]) <= 1</code> 。<code>abs(x)</code> 为 <code>x</code> 的绝对值。</li>
</ul>

<p>你可以执行以下 2 种操作任意次：</p>

<ul>
	<li><strong>减小</strong> <code>arr</code> 中任意元素的值，使其变为一个 <strong>更小的正整数</strong> 。</li>
	<li><strong>重新排列</strong> <code>arr</code> 中的元素，你可以以任意顺序重新排列。</li>
</ul>

<p>请你返回执行以上操作后，在满足前文所述的条件下，<code>arr</code> 中可能的 <strong>最大值</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [2,2,1,2,1]
<b>输出：</b>2
<b>解释：</b>
我们可以重新排列 arr 得到 <code>[1,2,2,2,1] ，该数组满足所有条件。</code>
arr 中最大元素为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [100,1,1000]
<b>输出：</b>3
<b>解释：</b>
一个可行的方案如下：
1. 重新排列 <code>arr</code> 得到 <code>[1,100,1000] 。</code>
2. 将第二个元素减小为 2 。
3. 将第三个元素减小为 3 。
现在 <code>arr = [1,2,3] ，满足所有条件。</code>
arr 中最大元素为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,3,4,5]
<b>输出：</b>5
<b>解释：</b>数组已经满足所有条件，最大元素为 5 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= arr[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们先对数组进行排序，然后将数组的第一个元素设置为 $1$。

接下来，我们从第二个元素开始遍历数组，如果当前元素与前一个元素的差值大于 $1$，我们就贪心地将当前元素减小为前一个元素加 $1$。

最后，我们返回数组中的最大元素。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        arr[0] = 1
        for i in range(1, len(arr)):
            d = max(0, arr[i] - arr[i - 1] - 1)
            arr[i] -= d
        return max(arr)
```

#### Java

```java
class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        int ans = 1;
        for (int i = 1; i < arr.length; ++i) {
            int d = Math.max(0, arr[i] - arr[i - 1] - 1);
            arr[i] -= d;
            ans = Math.max(ans, arr[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int ans = 1;
        for (int i = 1; i < arr.size(); ++i) {
            int d = max(0, arr[i] - arr[i - 1] - 1);
            arr[i] -= d;
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumElementAfterDecrementingAndRearranging(arr []int) int {
	sort.Ints(arr)
	ans := 1
	arr[0] = 1
	for i := 1; i < len(arr); i++ {
		d := max(0, arr[i]-arr[i-1]-1)
		arr[i] -= d
		ans = max(ans, arr[i])
	}
	return ans
}
```

#### TypeScript

```ts
function maximumElementAfterDecrementingAndRearranging(arr: number[]): number {
    arr.sort((a, b) => a - b);
    arr[0] = 1;
    let ans = 1;
    for (let i = 1; i < arr.length; ++i) {
        const d = Math.max(0, arr[i] - arr[i - 1] - 1);
        arr[i] -= d;
        ans = Math.max(ans, arr[i]);
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int MaximumElementAfterDecrementingAndRearranging(int[] arr) {
        Array.Sort(arr);
        int n = arr.Length;
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            arr[i] = Math.Min(arr[i], arr[i - 1] + 1);
        }
        return arr[n - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1847. 最近的房间](https://leetcode.cn/problems/closest-room){#1847}

{{< tabs "1847" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestRoom(
        self, rooms: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        rooms.sort(key=lambda x: x[1])
        k = len(queries)
        idx = sorted(range(k), key=lambda i: queries[i][1])
        ans = [-1] * k
        i, n = 0, len(rooms)
        sl = SortedList(x[0] for x in rooms)
        for j in idx:
            prefer, minSize = queries[j]
            while i < n and rooms[i][1] < minSize:
                sl.remove(rooms[i][0])
                i += 1
            if i == n:
                break
            p = sl.bisect_left(prefer)
            if p < len(sl):
                ans[j] = sl[p]
            if p and (ans[j] == -1 or ans[j] - prefer >= prefer - sl[p - 1]):
                ans[j] = sl[p - 1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int n = rooms.length;
        int k = queries.length;
        Arrays.sort(rooms, (a, b) -> a[1] - b[1]);
        Integer[] idx = new Integer[k];
        for (int i = 0; i < k; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[i][1] - queries[j][1]);
        int i = 0;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int[] room : rooms) {
            tm.merge(room[0], 1, Integer::sum);
        }
        int[] ans = new int[k];
        Arrays.fill(ans, -1);
        for (int j : idx) {
            int prefer = queries[j][0], minSize = queries[j][1];
            while (i < n && rooms[i][1] < minSize) {
                if (tm.merge(rooms[i][0], -1, Integer::sum) == 0) {
                    tm.remove(rooms[i][0]);
                }
                ++i;
            }
            if (i == n) {
                break;
            }
            Integer p = tm.ceilingKey(prefer);
            if (p != null) {
                ans[j] = p;
            }
            p = tm.floorKey(prefer);
            if (p != null && (ans[j] == -1 || ans[j] - prefer >= prefer - p)) {
                ans[j] = p;
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
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int k = queries.size();
        sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> idx(k);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i][1] < queries[j][1];
        });
        vector<int> ans(k, -1);
        int i = 0;
        multiset<int> s;
        for (auto& room : rooms) {
            s.insert(room[0]);
        }
        for (int j : idx) {
            int prefer = queries[j][0], minSize = queries[j][1];
            while (i < n && rooms[i][1] < minSize) {
                s.erase(s.find(rooms[i][0]));
                ++i;
            }
            if (i == n) {
                break;
            }
            auto it = s.lower_bound(prefer);
            if (it != s.end()) {
                ans[j] = *it;
            }
            if (it != s.begin()) {
                --it;
                if (ans[j] == -1 || abs(*it - prefer) <= abs(ans[j] - prefer)) {
                    ans[j] = *it;
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
func closestRoom(rooms [][]int, queries [][]int) []int {
	n, k := len(rooms), len(queries)
	sort.Slice(rooms, func(i, j int) bool { return rooms[i][1] < rooms[j][1] })
	idx := make([]int, k)
	ans := make([]int, k)
	for i := range idx {
		idx[i] = i
		ans[i] = -1
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[i]][1] < queries[idx[j]][1] })
	rbt := redblacktree.NewWithIntComparator()
	merge := func(rbt *redblacktree.Tree, key, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}
	for _, room := range rooms {
		merge(rbt, room[0], 1)
	}
	i := 0

	for _, j := range idx {
		prefer, minSize := queries[j][0], queries[j][1]
		for i < n && rooms[i][1] < minSize {
			merge(rbt, rooms[i][0], -1)
			i++
		}
		if i == n {
			break
		}
		c, _ := rbt.Ceiling(prefer)
		f, _ := rbt.Floor(prefer)
		if c != nil {
			ans[j] = c.Key.(int)
		}
		if f != nil && (ans[j] == -1 || ans[j]-prefer >= prefer-f.Key.(int)) {
			ans[j] = f.Key.(int)
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

<p>一个酒店里有 <code>n</code> 个房间，这些房间用二维整数数组 <code>rooms</code> 表示，其中 <code>rooms[i] = [roomId<sub>i</sub>, size<sub>i</sub>]</code> 表示有一个房间号为 <code>roomId<sub>i</sub></code> 的房间且它的面积为 <code>size<sub>i</sub></code> 。每一个房间号 <code>roomId<sub>i</sub></code> 保证是 <strong>独一无二</strong> 的。</p>

<p>同时给你 <code>k</code> 个查询，用二维数组 <code>queries</code> 表示，其中 <code>queries[j] = [preferred<sub>j</sub>, minSize<sub>j</sub>]</code> 。第 <code>j</code> 个查询的答案是满足如下条件的房间 <code>id</code> ：</p>

<ul>
	<li>房间的面积 <b>至少</b> 为 <code>minSize<sub>j</sub></code> ，且</li>
	<li><code>abs(id - preferred<sub>j</sub>)</code> 的值 <strong>最小</strong> ，其中 <code>abs(x)</code> 是 <code>x</code> 的绝对值。</li>
</ul>

<p>如果差的绝对值有 <strong>相等</strong> 的，选择 <strong>最小</strong> 的 <code>id</code> 。如果 <strong>没有满足条件的房间</strong> ，答案为 <code>-1</code> 。</p>

<p>请你返回长度为 <code>k</code> 的数组 <code>answer</code> ，其中<em> </em><code>answer[j]</code> 为第 <code>j</code> 个查询的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
<b>输出：</b>[3,-1,3]
<strong>解释：</strong>查询的答案如下：
查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
<b>输出：</b>[2,1,3]
<strong>解释：</strong>查询的答案如下：
查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rooms.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 <= k <= 10<sup>4</sup></code></li>
	<li><code>1 <= roomId<sub>i</sub>, preferred<sub>j</sub> <= 10<sup>7</sup></code></li>
	<li><code>1 <= size<sub>i</sub>, minSize<sub>j</sub> <= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离线查询 + 有序集合 + 二分查找

我们注意到，查询的顺序并不影响答案，而且题目中涉及到房间面积的大小关系，因此，我们可以将查询按照最小面积从小到大排序，这样我们就可以从小到大依次处理每个查询。另外，我们也将房间按照面积从小到大排序。

接下来，我们创建一个有序列表，将所有房间的编号加入有序列表中。

然后，我们从小到大依次处理每个查询。对于每个查询，我们首先将所有面积小于等于当前查询的最小面积的房间从有序列表中移除。然后，我们在剩余的房间中，使用二分查找找到最接近当前查询的房间编号。如果不存在这样的房间，那么我们就返回 $-1$。

时间复杂度 $O(n \times \log n + k \times \log k)$，空间复杂度 $O(n + k)$。其中 $n$ 和 $k$ 分别是房间数和查询数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestRoom(
        self, rooms: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        rooms.sort(key=lambda x: x[1])
        k = len(queries)
        idx = sorted(range(k), key=lambda i: queries[i][1])
        ans = [-1] * k
        i, n = 0, len(rooms)
        sl = SortedList(x[0] for x in rooms)
        for j in idx:
            prefer, minSize = queries[j]
            while i < n and rooms[i][1] < minSize:
                sl.remove(rooms[i][0])
                i += 1
            if i == n:
                break
            p = sl.bisect_left(prefer)
            if p < len(sl):
                ans[j] = sl[p]
            if p and (ans[j] == -1 or ans[j] - prefer >= prefer - sl[p - 1]):
                ans[j] = sl[p - 1]
        return ans
```

#### Java

```java
class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int n = rooms.length;
        int k = queries.length;
        Arrays.sort(rooms, (a, b) -> a[1] - b[1]);
        Integer[] idx = new Integer[k];
        for (int i = 0; i < k; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[i][1] - queries[j][1]);
        int i = 0;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int[] room : rooms) {
            tm.merge(room[0], 1, Integer::sum);
        }
        int[] ans = new int[k];
        Arrays.fill(ans, -1);
        for (int j : idx) {
            int prefer = queries[j][0], minSize = queries[j][1];
            while (i < n && rooms[i][1] < minSize) {
                if (tm.merge(rooms[i][0], -1, Integer::sum) == 0) {
                    tm.remove(rooms[i][0]);
                }
                ++i;
            }
            if (i == n) {
                break;
            }
            Integer p = tm.ceilingKey(prefer);
            if (p != null) {
                ans[j] = p;
            }
            p = tm.floorKey(prefer);
            if (p != null && (ans[j] == -1 || ans[j] - prefer >= prefer - p)) {
                ans[j] = p;
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
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int k = queries.size();
        sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> idx(k);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i][1] < queries[j][1];
        });
        vector<int> ans(k, -1);
        int i = 0;
        multiset<int> s;
        for (auto& room : rooms) {
            s.insert(room[0]);
        }
        for (int j : idx) {
            int prefer = queries[j][0], minSize = queries[j][1];
            while (i < n && rooms[i][1] < minSize) {
                s.erase(s.find(rooms[i][0]));
                ++i;
            }
            if (i == n) {
                break;
            }
            auto it = s.lower_bound(prefer);
            if (it != s.end()) {
                ans[j] = *it;
            }
            if (it != s.begin()) {
                --it;
                if (ans[j] == -1 || abs(*it - prefer) <= abs(ans[j] - prefer)) {
                    ans[j] = *it;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func closestRoom(rooms [][]int, queries [][]int) []int {
	n, k := len(rooms), len(queries)
	sort.Slice(rooms, func(i, j int) bool { return rooms[i][1] < rooms[j][1] })
	idx := make([]int, k)
	ans := make([]int, k)
	for i := range idx {
		idx[i] = i
		ans[i] = -1
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[i]][1] < queries[idx[j]][1] })
	rbt := redblacktree.NewWithIntComparator()
	merge := func(rbt *redblacktree.Tree, key, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}
	for _, room := range rooms {
		merge(rbt, room[0], 1)
	}
	i := 0

	for _, j := range idx {
		prefer, minSize := queries[j][0], queries[j][1]
		for i < n && rooms[i][1] < minSize {
			merge(rbt, rooms[i][0], -1)
			i++
		}
		if i == n {
			break
		}
		c, _ := rbt.Ceiling(prefer)
		f, _ := rbt.Floor(prefer)
		if c != nil {
			ans[j] = c.Key.(int)
		}
		if f != nil && (ans[j] == -1 || ans[j]-prefer >= prefer-f.Key.(int)) {
			ans[j] = f.Key.(int)
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

# [1848. 到目标元素的最小距离](https://leetcode.cn/problems/minimum-distance-to-the-target-element){#1848}

{{< tabs "1848" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i - start) for i, x in enumerate(nums) if x == target)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans = Math.min(ans, Math.abs(i - start));
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
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMinDistance(nums []int, target int, start int) int {
	ans := 1 << 30
	for i, x := range nums {
		if t := abs(i - start); x == target && t < ans {
			ans = t
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
function getMinDistance(nums: number[], target: number, start: number): number {
    let ans = Infinity;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === target) {
            ans = Math.min(ans, Math.abs(i - start));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        nums.iter()
            .enumerate()
            .filter(|&(_, &x)| x == target)
            .map(|(i, _)| ((i as i32) - start).abs())
            .min()
            .unwrap_or_default()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> （下标 <strong>从 0 开始</strong> 计数）以及两个整数 <code>target</code> 和 <code>start</code> ，请你找出一个下标 <code>i</code> ，满足 <code>nums[i] == target</code> 且 <code>abs(i - start)</code> <strong>最小化</strong> 。注意：<code>abs(x)</code> 表示 <code>x</code> 的绝对值。</p>

<p>返回 <code>abs(i - start)</code> 。</p>

<p>题目数据保证 <code>target</code> 存在于 <code>nums</code> 中。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5], target = 5, start = 3
<strong>输出：</strong>1
<strong>解释：</strong>nums[4] = 5 是唯一一个等于 target 的值，所以答案是 abs(4 - 3) = 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], target = 1, start = 0
<strong>输出：</strong>0
<strong>解释：</strong>nums[0] = 1 是唯一一个等于 target 的值，所以答案是 abs(0 - 0) = 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
<strong>输出：</strong>0
<strong>解释：</strong>nums 中的每个值都是 1 ，但 nums[0] 使 abs(i - start) 的结果得以最小化，所以答案是 abs(0 - 0) = 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
	<li><code>0 <= start < nums.length</code></li>
	<li><code>target</code> 存在于 <code>nums</code> 中</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

遍历数组，找到所有等于 $target$ 的下标，然后计算 $|i - start|$，取最小值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i - start) for i, x in enumerate(nums) if x == target)
```

#### Java

```java
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans = Math.min(ans, Math.abs(i - start));
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
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getMinDistance(nums []int, target int, start int) int {
	ans := 1 << 30
	for i, x := range nums {
		if t := abs(i - start); x == target && t < ans {
			ans = t
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
function getMinDistance(nums: number[], target: number, start: number): number {
    let ans = Infinity;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === target) {
            ans = Math.min(ans, Math.abs(i - start));
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        nums.iter()
            .enumerate()
            .filter(|&(_, &x)| x == target)
            .map(|(i, _)| ((i as i32) - start).abs())
            .min()
            .unwrap_or_default()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1849. 将字符串拆分为递减的连续值](https://leetcode.cn/problems/splitting-a-string-into-descending-consecutive-values){#1849}

{{< tabs "1849" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitString(self, s: str) -> bool:
        def dfs(i: int, x: int) -> bool:
            if i >= len(s):
                return True
            y = 0
            r = len(s) - 1 if x < 0 else len(s)
            for j in range(i, r):
                y = y * 10 + int(s[j])
                if (x < 0 or x - y == 1) and dfs(j + 1, y):
                    return True
            return False

        return dfs(0, -1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;

    public boolean splitString(String s) {
        this.s = s.toCharArray();
        return dfs(0, -1);
    }

    private boolean dfs(int i, long x) {
        if (i >= s.length) {
            return true;
        }
        long y = 0;
        int r = x < 0 ? s.length - 1 : s.length;
        for (int j = i; j < r; ++j) {
            y = y * 10 + s[j] - '0';
            if ((x < 0 || x - y == 1) && dfs(j + 1, y)) {
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
    bool splitString(string s) {
        auto dfs = [&](this auto&& dfs, int i, long long x) -> bool {
            if (i >= s.size()) {
                return true;
            }
            long long y = 0;
            int r = x < 0 ? s.size() - 1 : s.size();
            for (int j = i; j < r; ++j) {
                y = y * 10 + s[j] - '0';
                if (y > 1e10) {
                    break;
                }
                if ((x < 0 || x - y == 1) && dfs(j + 1, y)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0, -1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitString(s string) bool {
	var dfs func(i, x int) bool
	dfs = func(i, x int) bool {
		if i >= len(s) {
			return true
		}
		y := 0
		r := len(s)
		if x < 0 {
			r--
		}
		for j := i; j < r; j++ {
			y = y*10 + int(s[j]-'0')
			if (x < 0 || x-y == 1) && dfs(j+1, y) {
				return true
			}
		}
		return false
	}
	return dfs(0, -1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function splitString(s: string): boolean {
    const dfs = (i: number, x: number): boolean => {
        if (i >= s.length) {
            return true;
        }
        let y = 0;
        const r = x < 0 ? s.length - 1 : s.length;
        for (let j = i; j < r; ++j) {
            y = y * 10 + +s[j];
            if ((x < 0 || x - y === 1) && dfs(j + 1, y)) {
                return true;
            }
        }
        return false;
    };
    return dfs(0, -1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由数字组成的字符串 <code>s</code> 。</p>

<p>请你判断能否将 <code>s</code> 拆分成两个或者多个 <strong>非空子字符串</strong> ，使子字符串的 <strong>数值</strong> 按 <strong>降序</strong> 排列，且每两个 <strong>相邻子字符串</strong> 的数值之 <strong>差 </strong>等于 <code>1</code> 。</p>

<ul>
	<li>例如，字符串 <code>s = "0090089"</code> 可以拆分成 <code>["0090", "089"]</code> ，数值为 <code>[90,89]</code> 。这些数值满足按降序排列，且相邻值相差 <code>1</code> ，这种拆分方法可行。</li>
	<li>另一个例子中，字符串 <code>s = "001"</code> 可以拆分成 <code>["0", "01"]</code>、<code>["00", "1"]</code> 或 <code>["0", "0", "1"]</code> 。然而，所有这些拆分方法都不可行，因为对应数值分别是 <code>[0,1]</code>、<code>[0,1]</code> 和 <code>[0,0,1]</code> ，都不满足按降序排列的要求。</li>
</ul>

<p>如果可以按要求拆分 <code>s</code> ，返回 <code>true</code> ；否则，返回 <code>false</code><em> </em>。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1234"
<strong>输出：</strong>false
<strong>解释：</strong>不存在拆分 s 的可行方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "050043"
<strong>输出：</strong>true
<strong>解释：</strong>s 可以拆分为 ["05", "004", "3"] ，对应数值为 [5,4,3] 。
满足按降序排列，且相邻值相差 <code>1</code> 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "9080701"
<strong>输出：</strong>false
<strong>解释：</strong>不存在拆分 s 的可行方法。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "10009998"
<strong>输出：</strong>true
<strong>解释：</strong>s 可以拆分为 ["100", "099", "98"] ，对应数值为 [100,99,98] 。
满足按降序排列，且相邻值相差 <code>1</code> 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 20</code></li>
	<li><code>s</code> 仅由数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以从字符串的第一个字符开始，尝试将其拆分成一个或多个子字符串，然后递归处理剩余的部分。

具体地，我们设计一个函数 $\textit{dfs}(i, x)$，其中 $i$ 表示当前处理到的位置，而 $x$ 表示上一个拆分出的数值。初始时 $x = -1$，表示我们还没有拆分出任何数值。

在 $\textit{dfs}(i, x)$ 中，我们首先计算当前拆分出的数值 $y$，如果 $x = -1$，或者 $x - y = 1$，那么我们可以尝试将 $y$ 作为下一个数值，继续递归处理剩余的部分。如果递归的结果为 $\textit{true}$，我们就找到了一种拆分方法，返回 $\textit{true}$。

遍历完所有的拆分方法后，如果没有找到合适的拆分方法，我们返回 $\textit{false}$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$，其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitString(self, s: str) -> bool:
        def dfs(i: int, x: int) -> bool:
            if i >= len(s):
                return True
            y = 0
            r = len(s) - 1 if x < 0 else len(s)
            for j in range(i, r):
                y = y * 10 + int(s[j])
                if (x < 0 or x - y == 1) and dfs(j + 1, y):
                    return True
            return False

        return dfs(0, -1)
```

#### Java

```java
class Solution {
    private char[] s;

    public boolean splitString(String s) {
        this.s = s.toCharArray();
        return dfs(0, -1);
    }

    private boolean dfs(int i, long x) {
        if (i >= s.length) {
            return true;
        }
        long y = 0;
        int r = x < 0 ? s.length - 1 : s.length;
        for (int j = i; j < r; ++j) {
            y = y * 10 + s[j] - '0';
            if ((x < 0 || x - y == 1) && dfs(j + 1, y)) {
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
    bool splitString(string s) {
        auto dfs = [&](this auto&& dfs, int i, long long x) -> bool {
            if (i >= s.size()) {
                return true;
            }
            long long y = 0;
            int r = x < 0 ? s.size() - 1 : s.size();
            for (int j = i; j < r; ++j) {
                y = y * 10 + s[j] - '0';
                if (y > 1e10) {
                    break;
                }
                if ((x < 0 || x - y == 1) && dfs(j + 1, y)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0, -1);
    }
};
```

#### Go

```go
func splitString(s string) bool {
	var dfs func(i, x int) bool
	dfs = func(i, x int) bool {
		if i >= len(s) {
			return true
		}
		y := 0
		r := len(s)
		if x < 0 {
			r--
		}
		for j := i; j < r; j++ {
			y = y*10 + int(s[j]-'0')
			if (x < 0 || x-y == 1) && dfs(j+1, y) {
				return true
			}
		}
		return false
	}
	return dfs(0, -1)
}
```

#### TypeScript

```ts
function splitString(s: string): boolean {
    const dfs = (i: number, x: number): boolean => {
        if (i >= s.length) {
            return true;
        }
        let y = 0;
        const r = x < 0 ? s.length - 1 : s.length;
        for (let j = i; j < r; ++j) {
            y = y * 10 + +s[j];
            if ((x < 0 || x - y === 1) && dfs(j + 1, y)) {
                return true;
            }
        }
        return false;
    };
    return dfs(0, -1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
