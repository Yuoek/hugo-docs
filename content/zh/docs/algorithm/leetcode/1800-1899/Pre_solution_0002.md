---
title: "1810_隐藏网格下的最小消耗路径 🔒"
date: 2025-10-08T18:38:27+08:00
weight: 2
tags: [二分查找, 交互, 位运算, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 最短路, 有序集合, 深度优先搜索, 状态压缩, 矩阵, 计数, 记忆化搜索]
---

{{< markmap >}}
### [1810_隐藏网格下的最小消耗路径 🔒](#1810)
#### [深度优先搜索](#1810)
#### [广度优先搜索](#1810)
#### [图](#1810)
#### [数组](#1810)
#### [交互](#1810)
#### [矩阵](#1810)
#### [最短路](#1810)
#### [堆（优先队列）](#1810)
### [1811_寻找面试候选人 🔒](#1811)
#### [数据库](#1811)
### [1812_判断国际象棋棋盘中一个格子的颜色](#1812)
#### [数学](#1812)
#### [字符串](#1812)
### [1813_句子相似性 III](#1813)
#### [数组](#1813)
#### [双指针](#1813)
#### [字符串](#1813)
### [1814_统计一个数组中好对子的数目](#1814)
#### [数组](#1814)
#### [哈希表](#1814)
#### [数学](#1814)
#### [计数](#1814)
### [1815_得到新鲜甜甜圈的最多组数](#1815)
#### [位运算](#1815)
#### [记忆化搜索](#1815)
#### [数组](#1815)
#### [动态规划](#1815)
#### [状态压缩](#1815)
### [1816_截断句子](#1816)
#### [数组](#1816)
#### [字符串](#1816)
### [1817_查找用户活跃分钟数](#1817)
#### [数组](#1817)
#### [哈希表](#1817)
### [1818_绝对差值和](#1818)
#### [数组](#1818)
#### [二分查找](#1818)
#### [有序集合](#1818)
#### [排序](#1818)
### [1819_序列中不同最大公约数的数目](#1819)
#### [数组](#1819)
#### [数学](#1819)
#### [计数](#1819)
#### [数论](#1819)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1810_隐藏网格下的最小消耗路径 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 交互
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
---
### 1811_寻找面试候选人 🔒
___
#### 数据库
---
### 1812_判断国际象棋棋盘中一个格子的颜色
___
#### 数学
___
#### 字符串
---
### 1813_句子相似性 III
___
#### 数组
___
#### 双指针
___
#### 字符串
---
### 1814_统计一个数组中好对子的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
---
### 1815_得到新鲜甜甜圈的最多组数
___
#### 位运算
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 1816_截断句子
___
#### 数组
___
#### 字符串
---
### 1817_查找用户活跃分钟数
___
#### 数组
___
#### 哈希表
---
### 1818_绝对差值和
___
#### 数组
___
#### 二分查找
___
#### 有序集合
___
#### 排序
---
### 1819_序列中不同最大公约数的数目
___
#### 数组
___
#### 数学
___
#### 计数
___
#### 数论
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 位运算 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 最短路 | 有序集合 | 深度优先搜索 |
| 状态压缩 | 矩阵 | 计数 |
| 记忆化搜索 |  |  |

# [1810. 隐藏网格下的最小消耗路径 🔒](https://leetcode.cn/problems/minimum-path-cost-in-a-hidden-grid){#1810}

{{< tabs "1810" >}}

{{% tab "python" %}}
```python
# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
# class GridMaster(object):
#    def canMove(self, direction: str) -> bool:
#
#
#    def move(self, direction: str) -> int:
#
#
#    def isTarget(self) -> None:
#
#


class Solution(object):
    def findShortestPath(self, master: 'GridMaster') -> int:
        def dfs(i, j):
            nonlocal target
            if master.isTarget():
                target = (i, j)
            for dir, (a, b, ndir) in dirs.items():
                x, y = i + a, j + b
                if 0 <= x < N and 0 <= y < N and master.canMove(dir) and g[x][y] == -1:
                    g[x][y] = master.move(dir)
                    dfs(x, y)
                    master.move(ndir)

        target = (-1, -1)
        N = 200
        INF = 0x3F3F3F3F
        g = [[-1] * N for _ in range(N)]
        dirs = {
            'U': (-1, 0, 'D'),
            'D': (1, 0, 'U'),
            'L': (0, -1, 'R'),
            'R': (0, 1, 'L'),
        }
        dfs(100, 100)
        if target == (-1, -1):
            return -1
        q = [(0, 100, 100)]
        dist = [[INF] * N for _ in range(N)]
        dist[100][100] = 0
        while q:
            w, i, j = heappop(q)
            if (i, j) == target:
                return w
            for a, b, _ in dirs.values():
                x, y = i + a, j + b
                if (
                    0 <= x < N
                    and 0 <= y < N
                    and g[x][y] != -1
                    and dist[x][y] > w + g[x][y]
                ):
                    dist[x][y] = w + g[x][y]
                    heappush(q, (dist[x][y], x, y))
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *     boolean canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * }
 */

class Solution {
    private static final char[] dir = {'U', 'R', 'D', 'L'};
    private static final char[] ndir = {'D', 'L', 'U', 'R'};
    private static final int[] dirs = {-1, 0, 1, 0, -1};
    private static final int N = 200;
    private static final int INF = 0x3f3f3f3f;
    private static int[][] g = new int[N][N];
    private static int[][] dist = new int[N][N];
    private int[] target;

    public int findShortestPath(GridMaster master) {
        target = new int[] {-1, -1};
        for (int i = 0; i < N; ++i) {
            Arrays.fill(g[i], -1);
            Arrays.fill(dist[i], INF);
        }
        dfs(100, 100, master);
        if (target[0] == -1 && target[1] == -1) {
            return -1;
        }
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.offer(new int[] {0, 100, 100});
        dist[100][100] = 0;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int w = p[0], i = p[1], j = p[2];
            if (i == target[0] && j == target[1]) {
                return w;
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < N && y >= 0 && y < N && g[x][y] != -1
                    && dist[x][y] > w + g[x][y]) {
                    dist[x][y] = w + g[x][y];
                    q.offer(new int[] {dist[x][y], x, y});
                }
            }
        }
        return 0;
    }

    private void dfs(int i, int j, GridMaster master) {
        if (master.isTarget()) {
            target = new int[] {i, j};
        }
        for (int k = 0; k < 4; ++k) {
            char d = dir[k], nd = ndir[k];
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < N && y >= 0 && y < N && master.canMove(d) && g[x][y] == -1) {
                g[x][y] = master.move(d);
                dfs(x, y, master);
                master.move(nd);
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这是一个交互问题。</p>

<p>有一个机器人存在于网格中，你需要通过不断尝试使他从初始单元到达目标单元。网格的规格为m x n，并且每个单元的属性值要不为空，要不已被占用。题目<strong>保证</strong>初始网格和目标网格不同且均为空。</p>

<p>每个单元格都有<b>消耗</b>值，你需要在每次<strong>移动</strong>至此单元格后支付该费用。在机器人启动前，初始单元的费用不被计算在内。</p>

<p>你需要找到机器人移动至目标网格的最小总消耗。但可惜的是你并<strong>不知道</strong>网格的尺寸、初始单元和目标单元。你只允许通过询问<code>GridMaster</code>类获得信息。</p>

<p><code>GridMaster</code>类存在以下功能：</p>

<ul>
	<li><code>boolean canMove(char direction)</code> 当机器人可以向这个方向移动时，返回<code>true</code>；反之返回<code>false</code>。</li>
	<li><code>int move(char direction)</code> 沿该方向移动机器人，并返回移动到该单元的消耗值。如果此移动将机器人移动到被占有的单元格或离开网格，则移动将被<strong>忽略</strong>，机器人将保持在相同的位置，函数将返回<code>-1</code>。</li>
	<li><code>boolean isTarget()</code> ：如果机器人当前位于目标单元格上，则返回<code>true</code>；<span style="">反之返回</span> <code>false</code> 。</li>
</ul>

<p>请注意，上述函数中的方向应该是<code>{ 'U'、'D'、'L'、'R' }</code>中的字符，分别表示向上、向下、左和右方向。</p>

<p>返回使机器人从其初始起始单元到目标单元的<strong>最小总消耗</strong>。如果单元格之间不存在有效路径，则返回<code>-1</code>。</p>

<p><strong>测试实例:</strong></p>

<p>测试输入一个大小为<code>m x n</code>的二维数组 <code>grid</code> 和四个<code>int</code>型参数 <code>r1</code>, <code>c1</code>, <code>r2</code>, 和 <code><font face="monospace">c2</font></code> :</p>

<ul>
	<li><code>grid[i][j] == 0</code> 表示网格 <code>(i, j)</code> 已被占用。</li>
	<li><code>grid[i][j] >= 1</code> 表示网格单元 <code>(i, j)</code> 为空并且 <code>grid[i][j]</code> 的值为移动至此网格的成本值。</li>
	<li><code>(r1, c1)</code> 为初始单元。</li>
	<li><code>(r2, c2)</code> 为目标单元。</li>
</ul>

<p>请注意，你将无法在你的代码中获知这些信息。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> grid = [[2,3],[1,1]], r1 = 0, c1 = 1, r2 = 1, c2 = 0
<strong>输出:</strong> 2
<strong>解释:</strong> 其中一种可能路径描述如下：
机器人最开始站在单元格 (0, 1) ，用 3 表示
- master.canMove('U') 返回 false
- master.canMove('D') 返回 true
- master.canMove('L') 返回 true
- master.canMove('R') 返回 false
- master.move('L') 机器人移动到单元格 (0, 0) 并返回 2
- master.isTarget() 返回 false
- master.canMove('U') 返回 false
- master.canMove('D') 返回 true
- master.canMove('L') 返回 false
- master.canMove('R') 返回 true
- master.move('D') 机器人移动到单元格 (1, 0) 并返回 1
- master.isTarget() 返回 true
- master.move('L') 机器人不移动并返回 -1
- master.move('R') 机器人移动到单元格 (1, 1) 并返回 1
现在我们知道了机器人达到目标单元(1, 0)的最小消耗成本为2。 </pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[0,3,1],[3,4,2],[1,2,0]], r1 = 2, c1 = 0, r2 = 0, c2 = 2
<strong>输出:</strong> 9
<strong>解释:</strong> 最小消耗路径为 (2,0) -> (2,1) -> (1,1) -> (1,2) -> (0,2).
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,0],[0,1]], r1 = 0, c1 = 0, r2 = 1, c2 = 1
<strong>输出:</strong> -1
<strong>解释:</strong> 不存在可使机器人到达目标单元的路径。
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 <= n, m <= 100</code></li>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>0 <= grid[i][j] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS 建图 + 堆优化版 Dijkstra 算法

<!-- tabs:start -->

#### Python3

```python
# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
# class GridMaster(object):
#    def canMove(self, direction: str) -> bool:
#
#
#    def move(self, direction: str) -> int:
#
#
#    def isTarget(self) -> None:
#
#


class Solution(object):
    def findShortestPath(self, master: 'GridMaster') -> int:
        def dfs(i, j):
            nonlocal target
            if master.isTarget():
                target = (i, j)
            for dir, (a, b, ndir) in dirs.items():
                x, y = i + a, j + b
                if 0 <= x < N and 0 <= y < N and master.canMove(dir) and g[x][y] == -1:
                    g[x][y] = master.move(dir)
                    dfs(x, y)
                    master.move(ndir)

        target = (-1, -1)
        N = 200
        INF = 0x3F3F3F3F
        g = [[-1] * N for _ in range(N)]
        dirs = {
            'U': (-1, 0, 'D'),
            'D': (1, 0, 'U'),
            'L': (0, -1, 'R'),
            'R': (0, 1, 'L'),
        }
        dfs(100, 100)
        if target == (-1, -1):
            return -1
        q = [(0, 100, 100)]
        dist = [[INF] * N for _ in range(N)]
        dist[100][100] = 0
        while q:
            w, i, j = heappop(q)
            if (i, j) == target:
                return w
            for a, b, _ in dirs.values():
                x, y = i + a, j + b
                if (
                    0 <= x < N
                    and 0 <= y < N
                    and g[x][y] != -1
                    and dist[x][y] > w + g[x][y]
                ):
                    dist[x][y] = w + g[x][y]
                    heappush(q, (dist[x][y], x, y))
        return 0
```

#### Java

```java
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *     boolean canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * }
 */

class Solution {
    private static final char[] dir = {'U', 'R', 'D', 'L'};
    private static final char[] ndir = {'D', 'L', 'U', 'R'};
    private static final int[] dirs = {-1, 0, 1, 0, -1};
    private static final int N = 200;
    private static final int INF = 0x3f3f3f3f;
    private static int[][] g = new int[N][N];
    private static int[][] dist = new int[N][N];
    private int[] target;

    public int findShortestPath(GridMaster master) {
        target = new int[] {-1, -1};
        for (int i = 0; i < N; ++i) {
            Arrays.fill(g[i], -1);
            Arrays.fill(dist[i], INF);
        }
        dfs(100, 100, master);
        if (target[0] == -1 && target[1] == -1) {
            return -1;
        }
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.offer(new int[] {0, 100, 100});
        dist[100][100] = 0;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int w = p[0], i = p[1], j = p[2];
            if (i == target[0] && j == target[1]) {
                return w;
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < N && y >= 0 && y < N && g[x][y] != -1
                    && dist[x][y] > w + g[x][y]) {
                    dist[x][y] = w + g[x][y];
                    q.offer(new int[] {dist[x][y], x, y});
                }
            }
        }
        return 0;
    }

    private void dfs(int i, int j, GridMaster master) {
        if (master.isTarget()) {
            target = new int[] {i, j};
        }
        for (int k = 0; k < 4; ++k) {
            char d = dir[k], nd = ndir[k];
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < N && y >= 0 && y < N && master.canMove(d) && g[x][y] == -1) {
                g[x][y] = master.move(d);
                dfs(x, y, master);
                master.move(nd);
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1811. 寻找面试候选人 🔒](https://leetcode.cn/problems/find-interview-candidates){#1811}

{{< tabs "1811" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT contest_id, gold_medal AS user_id, 1 AS type
        FROM Contests
        UNION
        SELECT contest_id, silver_medal AS user_id, 2 AS type
        FROM Contests
        UNION
        SELECT contest_id, bronze_medal AS user_id, 3 AS type
        FROM Contests
    ),
    T AS (
        SELECT
            user_id,
            (
                contest_id - ROW_NUMBER() OVER (
                    PARTITION BY user_id
                    ORDER BY contest_id
                )
            ) AS diff
        FROM S
    ),
    P AS (
        SELECT user_id
        FROM S
        WHERE type = 1
        GROUP BY user_id
        HAVING COUNT(1) >= 3
        UNION
        SELECT DISTINCT user_id
        FROM T
        GROUP BY user_id, diff
        HAVING COUNT(1) >= 3
    )
SELECT name, mail
FROM
    P AS p
    LEFT JOIN Users AS u ON p.user_id = u.user_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Contests</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| contest_id   | int  |
| gold_medal   | int  |
| silver_medal | int  |
| bronze_medal | int  |
+--------------+------+
contest_id 是该表的主键.
该表包含LeetCode竞赛的ID和该场比赛中金牌、银牌、铜牌的用户id。
可以保证，所有连续的比赛都有连续的ID，没有ID被跳过。

</pre>

<p>Table: <code>Users</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| mail        | varchar |
| name        | varchar |
+-------------+---------+
user_id 是该表的主键.
该表包含用户信息。</pre>

<p>&nbsp;</p>

<p>编写 SQL 语句来返回 <strong>所有面试候选人</strong> 的姓名&nbsp;<code>name</code>&nbsp;和邮件&nbsp;<code>mail</code>&nbsp;。当用户满足以下两个要求中的 <strong>任意一条 </strong>，其成为 <strong>面试候选人 </strong>:</p>

<ul>
	<li>该用户在 <strong>连续三场及更多</strong> 比赛中赢得 <strong>任意</strong> 奖牌。</li>
	<li>该用户在 <strong>三场及更多不同的</strong> 比赛中赢得 <strong>金牌</strong>（这些比赛可以不是连续的）</li>
</ul>

<p>可以以 <strong>任何顺序</strong> 返回结果。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Contests表:
+------------+------------+--------------+--------------+
| contest_id | gold_medal | silver_medal | bronze_medal |
+------------+------------+--------------+--------------+
| 190        | 1          | 5            | 2            |
| 191        | 2          | 3            | 5            |
| 192        | 5          | 2            | 3            |
| 193        | 1          | 3            | 5            |
| 194        | 4          | 5            | 2            |
| 195        | 4          | 2            | 1            |
| 196        | 1          | 5            | 2            |
+------------+------------+--------------+--------------+
Users表:
+---------+--------------------+-------+
| user_id | mail               | name  |
+---------+--------------------+-------+
| 1       | sarah@leetcode.com | Sarah |
| 2       | bob@leetcode.com   | Bob   |
| 3       | alice@leetcode.com | Alice |
| 4       | hercy@leetcode.com | Hercy |
| 5       | quarz@leetcode.com | Quarz |
+---------+--------------------+-------+
<strong>输出：</strong>
+-------+--------------------+
| name  | mail               |
+-------+--------------------+
| Sarah | sarah@leetcode.com |
| Bob   | bob@leetcode.com   |
| Alice | alice@leetcode.com |
| Quarz | quarz@leetcode.com |
+-------+--------------------+
<strong>解释：</strong>
Sarah 赢得了3块金牌 (190, 193, and 196),所以我们将她列入结果表。
Bob在连续3场竞赛中赢得了奖牌(190, 191, and 192), 所以我们将他列入结果表。
    - 注意他在另外的连续3场竞赛中也赢得了奖牌(194, 195, and 196).
Alice在连续3场竞赛中赢得了奖牌 (191, 192, and 193), 所以我们将她列入结果表。
Quarz在连续5场竞赛中赢得了奖牌(190, 191, 192, 193, and 194), 所以我们将他列入结果表。
</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果第一个条件变成“该用户在连续 <code>n</code> 场及比赛中赢得任意奖牌。”呢？你如何更改你的解法，来选出面试候选人？可以把 <code>n</code> 想象成存储过程中的参数。</li>
	<li>有的用户可能没有参加每一场竞赛，但是在参加的每一场竞赛中都表现得不错。你如何更改你的解法，以达到只考虑那些&nbsp;<strong>用户参与了的&nbsp;</strong>比赛？可假设另一张表给出了每场比赛的注册用户信息。</li>
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

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT contest_id, gold_medal AS user_id, 1 AS type
        FROM Contests
        UNION
        SELECT contest_id, silver_medal AS user_id, 2 AS type
        FROM Contests
        UNION
        SELECT contest_id, bronze_medal AS user_id, 3 AS type
        FROM Contests
    ),
    T AS (
        SELECT
            user_id,
            (
                contest_id - ROW_NUMBER() OVER (
                    PARTITION BY user_id
                    ORDER BY contest_id
                )
            ) AS diff
        FROM S
    ),
    P AS (
        SELECT user_id
        FROM S
        WHERE type = 1
        GROUP BY user_id
        HAVING COUNT(1) >= 3
        UNION
        SELECT DISTINCT user_id
        FROM T
        GROUP BY user_id, diff
        HAVING COUNT(1) >= 3
    )
SELECT name, mail
FROM
    P AS p
    LEFT JOIN Users AS u ON p.user_id = u.user_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1812. 判断国际象棋棋盘中一个格子的颜色](https://leetcode.cn/problems/determine-color-of-a-chessboard-square){#1812}

{{< tabs "1812" >}}

{{% tab "python" %}}
```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return (ord(coordinates[0]) + ord(coordinates[1])) % 2 == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean squareIsWhite(String coordinates) {
        return (coordinates.charAt(0) + coordinates.charAt(1)) % 2 == 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] + coordinates[1]) % 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func squareIsWhite(coordinates string) bool {
	return (coordinates[0]+coordinates[1])%2 == 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function squareIsWhite(coordinates: string): boolean {
    return ((coordinates.charCodeAt(0) + coordinates.charCodeAt(1)) & 1) === 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn square_is_white(coordinates: String) -> bool {
        let s = coordinates.as_bytes();
        ((s[0] + s[1]) & 1) == 1
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} coordinates
 * @return {boolean}
 */
var squareIsWhite = function (coordinates) {
    return (coordinates[0].charCodeAt() + coordinates[1].charCodeAt()) % 2 == 1;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool squareIsWhite(char* coordinates) {
    return (coordinates[0] + coordinates[1]) & 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个坐标 <code>coordinates</code> ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1812.Determine%20Color%20of%20a%20Chessboard%20Square/images/chessboard.png" style="width: 400px; height: 396px;" /></p>

<p>如果所给格子的颜色是白色，请你返回 <code>true</code>，如果是黑色，请返回 <code>false</code> 。</p>

<p>给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>coordinates = "a1"
<b>输出：</b>false
<b>解释：</b>如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>coordinates = "h3"
<b>输出：</b>true
<b>解释：</b>如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>coordinates = "c7"
<b>输出：</b>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>coordinates.length == 2</code></li>
	<li><code>'a' <= coordinates[0] <= 'h'</code></li>
	<li><code>'1' <= coordinates[1] <= '8'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：找规律

观察棋盘我们发现，颜色相同的两个格子 $(x_1, y_1)$ 和 $(x_2, y_2)$ 满足 $x_1 + y_1$ 和 $x_2 + y_2$ 均为奇数或偶数。

因此，我们可以根据 $\textit{coordinates}$ 获取对应的坐标 $(x, y)$，如果 $x + y$ 为奇数，则格子为白色，返回 $\textit{true}$，否则返回 $\textit{false}$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return (ord(coordinates[0]) + ord(coordinates[1])) % 2 == 1
```

#### Java

```java
class Solution {
    public boolean squareIsWhite(String coordinates) {
        return (coordinates.charAt(0) + coordinates.charAt(1)) % 2 == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] + coordinates[1]) % 2;
    }
};
```

#### Go

```go
func squareIsWhite(coordinates string) bool {
	return (coordinates[0]+coordinates[1])%2 == 1
}
```

#### TypeScript

```ts
function squareIsWhite(coordinates: string): boolean {
    return ((coordinates.charCodeAt(0) + coordinates.charCodeAt(1)) & 1) === 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn square_is_white(coordinates: String) -> bool {
        let s = coordinates.as_bytes();
        ((s[0] + s[1]) & 1) == 1
    }
}
```

#### JavaScript

```js
/**
 * @param {string} coordinates
 * @return {boolean}
 */
var squareIsWhite = function (coordinates) {
    return (coordinates[0].charCodeAt() + coordinates[1].charCodeAt()) % 2 == 1;
};
```

#### C

```c
bool squareIsWhite(char* coordinates) {
    return (coordinates[0] + coordinates[1]) & 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1813. 句子相似性 III](https://leetcode.cn/problems/sentence-similarity-iii){#1813}

{{< tabs "1813" >}}

{{% tab "python" %}}
```python
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1, words2 = sentence1.split(), sentence2.split()
        m, n = len(words1), len(words2)
        if m < n:
            words1, words2 = words2, words1
            m, n = n, m
        i = j = 0
        while i < n and words1[i] == words2[i]:
            i += 1
        while j < n and words1[m - 1 - j] == words2[n - 1 - j]:
            j += 1
        return i + j >= n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        var words1 = sentence1.split(" ");
        var words2 = sentence2.split(" ");
        if (words1.length < words2.length) {
            var t = words1;
            words1 = words2;
            words2 = t;
        }
        int m = words1.length, n = words2.length;
        int i = 0, j = 0;
        while (i < n && words1[i].equals(words2[i])) {
            ++i;
        }
        while (j < n && words1[m - 1 - j].equals(words2[n - 1 - j])) {
            ++j;
        }
        return i + j >= n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto words1 = split(sentence1, ' ');
        auto words2 = split(sentence2, ' ');
        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }
        int m = words1.size(), n = words2.size();
        int i = 0, j = 0;
        while (i < n && words1[i] == words2[i]) {
            ++i;
        }
        while (j < n && words1[m - 1 - j] == words2[n - 1 - j]) {
            ++j;
        }
        return i + j >= n;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func areSentencesSimilar(sentence1 string, sentence2 string) bool {
	words1, words2 := strings.Fields(sentence1), strings.Fields(sentence2)
	if len(words1) < len(words2) {
		words1, words2 = words2, words1
	}
	m, n := len(words1), len(words2)
	i, j := 0, 0
	for i < n && words1[i] == words2[i] {
		i++
	}
	for j < n && words1[m-1-j] == words2[n-1-j] {
		j++
	}
	return i+j >= n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function areSentencesSimilar(sentence1: string, sentence2: string): boolean {
    const [words1, words2] = [sentence1.split(' '), sentence2.split(' ')];
    const [m, n] = [words1.length, words2.length];

    if (m > n) return areSentencesSimilar(sentence2, sentence1);

    let [l, r] = [0, 0];
    for (let i = 0; i < n; i++) {
        if (l === i && words1[i] === words2[i]) l++;
        if (r === i && words2[n - i - 1] === words1[m - r - 1]) r++;
    }

    return l + r >= m;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function areSentencesSimilar(sentence1, sentence2) {
    const [words1, words2] = [sentence1.split(' '), sentence2.split(' ')];
    const [m, n] = [words1.length, words2.length];

    if (m > n) return areSentencesSimilar(sentence2, sentence1);

    let [l, r] = [0, 0];
    for (let i = 0; i < n; i++) {
        if (l === i && words1[i] === words2[i]) l++;
        if (r === i && words2[n - i - 1] === words1[m - r - 1]) r++;
    }

    return l + r >= m;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串&nbsp;<code>sentence1</code>&nbsp;和&nbsp;<code>sentence2</code>，每个表示由一些单词组成的一个句子。句子是一系列由&nbsp;<strong>单个 </strong>空格分隔的&nbsp;<strong>单词</strong>，且开头和结尾没有多余空格。每个单词都只包含大写和小写英文字母。</p>

<p>如果两个句子&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;，可以通过往其中一个句子插入一个任意的句子（可以是空句子）而得到另一个句子，那么我们称这两个句子是 <strong>相似的</strong>&nbsp;。<strong>注意</strong>，插入的句子必须与现有单词用空白隔开。&nbsp;</p>

<p>比方说，</p>

<ul>
	<li><code>s1 = "Hello Jane"</code> 与&nbsp;<code>s2 = "Hello my name is Jane"</code>，我们可以往 <code>s1</code>&nbsp;中&nbsp;<code>"Hello"</code> 和&nbsp;<code>"Jane"</code>&nbsp;之间插入&nbsp;<code>"my name is"</code>&nbsp;得到 <code>s2</code>&nbsp;。</li>
	<li><code>s1 = "Frog cool"</code>&nbsp;与 <code>s2 = "Frogs are cool"</code>&nbsp;不是相似的，因为尽管往&nbsp;<code>s1</code>&nbsp;中插入&nbsp;<code>"s are"</code>，它没有与&nbsp;<code>"Frog"</code>&nbsp;用空格隔开。</li>
</ul>

<p>给你两个句子&nbsp;<code>sentence1</code> 和&nbsp;<code>sentence2</code>&nbsp;，如果<em>&nbsp;</em><code>sentence1</code> 和<em>&nbsp;</em><code>sentence2</code> 是 <strong>相似</strong> 的，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block"><b>输入：</b>sentence1 = "My name is Haley", sentence2 = "My Haley"</div>

<div class="example-block"><b>输出：</b>true</div>

<div class="example-block"><b>解释：</b>可以往 <code>sentence2</code> 中 "My" 和 "Haley" 之间插入 "name is" ，得到 <code>sentence1</code> 。</div>

<div class="example-block">&nbsp;</div>

<p><strong>示例 2：</strong></p>

<div class="example-block"><b>输入：</b>sentence1 = "of", sentence2 = "A lot of words"</div>

<div class="example-block"><b>输出：</b>false</div>

<div class="example-block"><strong>解释：</strong>没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。</div>

<div class="example-block">&nbsp;</div>

<p><strong>示例 3：</strong></p>

<div class="example-block"><b>输入：</b>sentence1 = "Eating right now", sentence2 = "Eating"</div>

<div class="example-block"><b>输出：</b>true</div>

<div class="example-block"><b>解释：</b>可以往 <code>sentence2</code> 的结尾插入 "right now" 得到 <code>sentence1</code> 。</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence1.length, sentence2.length &lt;= 100</code></li>
	<li><code>sentence1</code>&nbsp;和&nbsp;<code>sentence2</code>&nbsp;都只包含大小写英文字母和空格。</li>
	<li><code>sentence1</code>&nbsp;和&nbsp;<code>sentence2</code>&nbsp;中的单词都只由单个空格隔开。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们将两个句子按照空格分割成两个单词数组 `words1` 和 `words2`，假设 `words1` 和 `words2` 的长度分别为 $m$ 和 $n$，不妨设 $m \geq n$。

我们使用双指针 $i$ 和 $j$，初始时 $i = j = 0$。接下来，我们循环判断 `words1[i]` 是否等于 `words2[i]`，是则指针 $i$ 继续右移；然后我们循环判断 `words1[m - 1 - j]` 是否等于 `words2[n - 1 - j]`，是则指针 $j$ 继续右移。

循环结束后，如果 $i + j \geq n$，说明两个句子相似，返回 `true`，否则返回 `false`。

时间复杂度 $O(L)$，空间复杂度 $O(L)$。其中 $L$ 为两个句子的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1, words2 = sentence1.split(), sentence2.split()
        m, n = len(words1), len(words2)
        if m < n:
            words1, words2 = words2, words1
            m, n = n, m
        i = j = 0
        while i < n and words1[i] == words2[i]:
            i += 1
        while j < n and words1[m - 1 - j] == words2[n - 1 - j]:
            j += 1
        return i + j >= n
```

#### Java

```java
class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        var words1 = sentence1.split(" ");
        var words2 = sentence2.split(" ");
        if (words1.length < words2.length) {
            var t = words1;
            words1 = words2;
            words2 = t;
        }
        int m = words1.length, n = words2.length;
        int i = 0, j = 0;
        while (i < n && words1[i].equals(words2[i])) {
            ++i;
        }
        while (j < n && words1[m - 1 - j].equals(words2[n - 1 - j])) {
            ++j;
        }
        return i + j >= n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto words1 = split(sentence1, ' ');
        auto words2 = split(sentence2, ' ');
        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }
        int m = words1.size(), n = words2.size();
        int i = 0, j = 0;
        while (i < n && words1[i] == words2[i]) {
            ++i;
        }
        while (j < n && words1[m - 1 - j] == words2[n - 1 - j]) {
            ++j;
        }
        return i + j >= n;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
```

#### Go

```go
func areSentencesSimilar(sentence1 string, sentence2 string) bool {
	words1, words2 := strings.Fields(sentence1), strings.Fields(sentence2)
	if len(words1) < len(words2) {
		words1, words2 = words2, words1
	}
	m, n := len(words1), len(words2)
	i, j := 0, 0
	for i < n && words1[i] == words2[i] {
		i++
	}
	for j < n && words1[m-1-j] == words2[n-1-j] {
		j++
	}
	return i+j >= n
}
```

#### TypeScript

```ts
function areSentencesSimilar(sentence1: string, sentence2: string): boolean {
    const [words1, words2] = [sentence1.split(' '), sentence2.split(' ')];
    const [m, n] = [words1.length, words2.length];

    if (m > n) return areSentencesSimilar(sentence2, sentence1);

    let [l, r] = [0, 0];
    for (let i = 0; i < n; i++) {
        if (l === i && words1[i] === words2[i]) l++;
        if (r === i && words2[n - i - 1] === words1[m - r - 1]) r++;
    }

    return l + r >= m;
}
```

#### JavaScript

```js
function areSentencesSimilar(sentence1, sentence2) {
    const [words1, words2] = [sentence1.split(' '), sentence2.split(' ')];
    const [m, n] = [words1.length, words2.length];

    if (m > n) return areSentencesSimilar(sentence2, sentence1);

    let [l, r] = [0, 0];
    for (let i = 0; i < n; i++) {
        if (l === i && words1[i] === words2[i]) l++;
        if (r === i && words2[n - i - 1] === words1[m - r - 1]) r++;
    }

    return l + r >= m;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1814. 统计一个数组中好对子的数目](https://leetcode.cn/problems/count-nice-pairs-in-an-array){#1814}

{{< tabs "1814" >}}

{{% tab "python" %}}
```python
class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(x):
            y = 0
            while x:
                y = y * 10 + x % 10
                x //= 10
            return y

        ans = 0
        mod = 10**9 + 7
        cnt = Counter()
        for x in nums:
            y = x - rev(x)
            ans += cnt[y]
            cnt[y] += 1
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countNicePairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        final int mod = (int) 1e9 + 7;
        int ans = 0;
        for (int x : nums) {
            int y = x - rev(x);
            ans = (ans + cnt.getOrDefault(y, 0)) % mod;
            cnt.merge(y, 1, Integer::sum);
        }
        return ans;
    }

    private int rev(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y = y * 10 + x % 10;
        }
        return y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        auto rev = [](int x) {
            int y = 0;
            for (; x > 0; x /= 10) {
                y = y * 10 + x % 10;
            }
            return y;
        };
        unordered_map<int, int> cnt;
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int& x : nums) {
            int y = x - rev(x);
            ans = (ans + cnt[y]++) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countNicePairs(nums []int) (ans int) {
	rev := func(x int) (y int) {
		for ; x > 0; x /= 10 {
			y = y*10 + x%10
		}
		return
	}
	cnt := map[int]int{}
	const mod int = 1e9 + 7
	for _, x := range nums {
		y := x - rev(x)
		ans = (ans + cnt[y]) % mod
		cnt[y]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countNicePairs(nums: number[]): number {
    const rev = (x: number): number => {
        let y = 0;
        while (x) {
            y = y * 10 + (x % 10);
            x = Math.floor(x / 10);
        }
        return y;
    };
    const mod = 10 ** 9 + 7;
    const cnt = new Map<number, number>();
    let ans = 0;
    for (const x of nums) {
        const y = x - rev(x);
        ans = (ans + (cnt.get(y) ?? 0)) % mod;
        cnt.set(y, (cnt.get(y) ?? 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var countNicePairs = function (nums) {
    const rev = x => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y = y * 10 + (x % 10);
        }
        return y;
    };
    let ans = 0;
    const mod = 1e9 + 7;
    const cnt = new Map();
    for (const x of nums) {
        const y = x - rev(x);
        const v = cnt.get(y) | 0;
        ans = (ans + v) % mod;
        cnt.set(y, v + 1);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountNicePairs(int[] nums) {
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        foreach (int x in nums) {
            int y = x - Rev(x);
            cnt[y] = cnt.GetValueOrDefault(y, 0) + 1;
        }
        int mod = (int)1e9 + 7;
        long ans = 0;
        foreach (int v in cnt.Values) {
            ans = (ans + (long)v * (v - 1) / 2) % mod;
        }
        return (int)ans;
    }

    private int Rev(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> ，数组中只包含非负整数。定义 <code>rev(x)</code> 的值为将整数 <code>x</code> 各个数字位反转得到的结果。比方说 <code>rev(123) = 321</code> ， <code>rev(120) = 21</code> 。我们称满足下面条件的下标对 <code>(i, j)</code> 是 <strong>好的</strong> ：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; nums.length</code></li>
	<li><code>nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])</code></li>
</ul>

<p>请你返回好下标对的数目。由于结果可能会很大，请将结果对 <code>10<sup>9</sup> + 7</code> <b>取余</b> 后返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [42,11,1,97]
<b>输出：</b>2
<b>解释：</b>两个坐标对为：
 - (0,3)：42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 。
 - (1,2)：11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [13,10,35,24,76]
<b>输出：</b>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：式子变换 + 哈希表

对于下标对 $(i, j)$，如果满足条件，那么有 $nums[i] + rev(nums[j]) = nums[j] + rev(nums[i])$，即 $nums[i] - nums[j] = rev(nums[j]) - rev(nums[i])$。

因此，我们可以将 $nums[i] - rev(nums[i])$ 作为哈希表的键，统计每个键出现的次数。最后计算每个键对应的值的组合数，相加得到最终的答案。

注意答案的取模操作。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 `nums` 的长度和数组 `nums` 中的最大值。空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(x):
            y = 0
            while x:
                y = y * 10 + x % 10
                x //= 10
            return y

        cnt = Counter(x - rev(x) for x in nums)
        mod = 10**9 + 7
        return sum(v * (v - 1) // 2 for v in cnt.values()) % mod
```

#### Java

```java
class Solution {
    public int countNicePairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            int y = x - rev(x);
            cnt.merge(y, 1, Integer::sum);
        }
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        for (int v : cnt.values()) {
            ans = (ans + (long) v * (v - 1) / 2) % mod;
        }
        return (int) ans;
    }

    private int rev(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y = y * 10 + x % 10;
        }
        return y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        auto rev = [](int x) {
            int y = 0;
            for (; x > 0; x /= 10) {
                y = y * 10 + x % 10;
            }
            return y;
        };
        unordered_map<int, int> cnt;
        for (int& x : nums) {
            int y = x - rev(x);
            cnt[y]++;
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (auto& [_, v] : cnt) {
            ans = (ans + 1ll * v * (v - 1) / 2) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countNicePairs(nums []int) (ans int) {
	rev := func(x int) (y int) {
		for ; x > 0; x /= 10 {
			y = y*10 + x%10
		}
		return
	}
	cnt := map[int]int{}
	for _, x := range nums {
		y := x - rev(x)
		cnt[y]++
	}
	const mod int = 1e9 + 7
	for _, v := range cnt {
		ans = (ans + v*(v-1)/2) % mod
	}
	return
}
```

#### TypeScript

```ts
function countNicePairs(nums: number[]): number {
    const rev = (x: number): number => {
        let y = 0;
        while (x) {
            y = y * 10 + (x % 10);
            x = Math.floor(x / 10);
        }
        return y;
    };
    const mod = 10 ** 9 + 7;
    const cnt = new Map<number, number>();
    let ans = 0;
    for (const x of nums) {
        const y = x - rev(x);
        ans = (ans + (cnt.get(y) ?? 0)) % mod;
        cnt.set(y, (cnt.get(y) ?? 0) + 1);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var countNicePairs = function (nums) {
    const rev = x => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y = y * 10 + (x % 10);
        }
        return y;
    };
    const cnt = new Map();
    for (const x of nums) {
        const y = x - rev(x);
        cnt.set(y, (cnt.get(y) | 0) + 1);
    }
    let ans = 0;
    const mod = 1e9 + 7;
    for (const [_, v] of cnt) {
        ans = (ans + Math.floor((v * (v - 1)) / 2)) % mod;
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int CountNicePairs(int[] nums) {
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        foreach (int x in nums) {
            int y = x - Rev(x);
            cnt[y] = cnt.GetValueOrDefault(y, 0) + 1;
        }
        int mod = (int)1e9 + 7;
        long ans = 0;
        foreach (int v in cnt.Values) {
            ans = (ans + (long)v * (v - 1) / 2) % mod;
        }
        return (int)ans;
    }

    private int Rev(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
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
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(x):
            y = 0
            while x:
                y = y * 10 + x % 10
                x //= 10
            return y

        ans = 0
        mod = 10**9 + 7
        cnt = Counter()
        for x in nums:
            y = x - rev(x)
            ans += cnt[y]
            cnt[y] += 1
        return ans % mod
```

#### Java

```java
class Solution {
    public int countNicePairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        final int mod = (int) 1e9 + 7;
        int ans = 0;
        for (int x : nums) {
            int y = x - rev(x);
            ans = (ans + cnt.getOrDefault(y, 0)) % mod;
            cnt.merge(y, 1, Integer::sum);
        }
        return ans;
    }

    private int rev(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y = y * 10 + x % 10;
        }
        return y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        auto rev = [](int x) {
            int y = 0;
            for (; x > 0; x /= 10) {
                y = y * 10 + x % 10;
            }
            return y;
        };
        unordered_map<int, int> cnt;
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int& x : nums) {
            int y = x - rev(x);
            ans = (ans + cnt[y]++) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countNicePairs(nums []int) (ans int) {
	rev := func(x int) (y int) {
		for ; x > 0; x /= 10 {
			y = y*10 + x%10
		}
		return
	}
	cnt := map[int]int{}
	const mod int = 1e9 + 7
	for _, x := range nums {
		y := x - rev(x)
		ans = (ans + cnt[y]) % mod
		cnt[y]++
	}
	return
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var countNicePairs = function (nums) {
    const rev = x => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y = y * 10 + (x % 10);
        }
        return y;
    };
    let ans = 0;
    const mod = 1e9 + 7;
    const cnt = new Map();
    for (const x of nums) {
        const y = x - rev(x);
        const v = cnt.get(y) | 0;
        ans = (ans + v) % mod;
        cnt.set(y, v + 1);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1815. 得到新鲜甜甜圈的最多组数](https://leetcode.cn/problems/maximum-number-of-groups-getting-fresh-donuts){#1815}

{{< tabs "1815" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        @cache
        def dfs(state, x):
            if state == mask:
                return 0
            vis = [False] * batchSize
            res = 0
            for i, v in enumerate(g):
                if state >> i & 1 == 0 and not vis[v]:
                    vis[v] = True
                    y = (x + v) % batchSize
                    res = max(res, dfs(state | 1 << i, y))
            return res + (x == 0)

        g = [v % batchSize for v in groups if v % batchSize]
        mask = (1 << len(g)) - 1
        return len(groups) - len(g) + dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private int size;

    public int maxHappyGroups(int batchSize, int[] groups) {
        size = batchSize;
        int ans = 0;
        long state = 0;
        for (int g : groups) {
            int i = g % size;
            if (i == 0) {
                ++ans;
            } else {
                state += 1l << (i * 5);
            }
        }
        ans += dfs(state, 0);
        return ans;
    }

    private int dfs(long state, int mod) {
        if (f.containsKey(state)) {
            return f.get(state);
        }
        int res = 0;
        for (int i = 1; i < size; ++i) {
            if ((state >> (i * 5) & 31) != 0) {
                int t = dfs(state - (1l << (i * 5)), (mod + i) % size);
                res = Math.max(res, t + (mod == 0 ? 1 : 0));
            }
        }
        f.put(state, res);
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        using ll = long long;
        unordered_map<ll, int> f;
        ll state = 0;
        int ans = 0;
        for (auto& v : groups) {
            int i = v % batchSize;
            ans += i == 0;
            if (i) {
                state += 1ll << (i * 5);
            }
        }
        function<int(ll, int)> dfs = [&](ll state, int mod) {
            if (f.count(state)) {
                return f[state];
            }
            int res = 0;
            int x = mod == 0;
            for (int i = 1; i < batchSize; ++i) {
                if (state >> (i * 5) & 31) {
                    int t = dfs(state - (1ll << (i * 5)), (mod + i) % batchSize);
                    res = max(res, t + x);
                }
            }
            return f[state] = res;
        };
        ans += dfs(state, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxHappyGroups(batchSize int, groups []int) (ans int) {
	state := 0
	for _, v := range groups {
		i := v % batchSize
		if i == 0 {
			ans++
		} else {
			state += 1 << (i * 5)
		}
	}
	f := map[int]int{}
	var dfs func(int, int) int
	dfs = func(state, mod int) int {
		if v, ok := f[state]; ok {
			return v
		}
		res := 0
		x := 0
		if mod == 0 {
			x = 1
		}
		for i := 1; i < batchSize; i++ {
			if state>>(i*5)&31 != 0 {
				t := dfs(state-1<<(i*5), (mod+i)%batchSize)
				res = max(res, t+x)
			}
		}
		f[state] = res
		return res
	}
	ans += dfs(state, 0)
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个甜甜圈商店，每批次都烤 <code>batchSize</code> 个甜甜圈。这个店铺有个规则，就是在烤一批新的甜甜圈时，之前 <strong>所有</strong> 甜甜圈都必须已经全部销售完毕。给你一个整数 <code>batchSize</code> 和一个整数数组 <code>groups</code> ，数组中的每个整数都代表一批前来购买甜甜圈的顾客，其中 <code>groups[i]</code> 表示这一批顾客的人数。每一位顾客都恰好只要一个甜甜圈。</p>

<p>当有一批顾客来到商店时，他们所有人都必须在下一批顾客来之前购买完甜甜圈。如果一批顾客中第一位顾客得到的甜甜圈不是上一组剩下的，那么这一组人都会很开心。</p>

<p>你可以随意安排每批顾客到来的顺序。请你返回在此前提下，<strong>最多</strong> 有多少组人会感到开心。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>batchSize = 3, groups = [1,2,3,4,5,6]
<b>输出：</b>4
<b>解释：</b>你可以将这些批次的顾客顺序安排为 [6,2,4,5,1,3] 。那么第 1，2，4，6 组都会感到开心。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>batchSize = 4, groups = [1,3,2,5,2,2,1,6]
<b>输出：</b>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= batchSize <= 9</code></li>
	<li><code>1 <= groups.length <= 30</code></li>
	<li><code>1 <= groups[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 状态压缩 + 记忆化搜索

题目实际上要我们找到一种安排顺序，使得前缀和（这里指的是“人数”）与 $batchSize$ 取模后为 $0$ 的组数最多。因此，我们可以将所有顾客按组分成两类：

-   人数为 $batchSize$ 的整数倍的顾客，这些顾客不会对下一组顾客的甜甜圈产生影响，我们可以贪心地优先安排这些组的顾客，那么这些组的顾客都会感到开心，“初始答案”为这些组的数量；
-   人数不为 $batchSize$ 的整数倍的顾客，这些顾客的安排顺序会影响下一组顾客的甜甜圈。我们可以对这里每一组的人数 $v$ 模 $batchSize$，得到的这些余数构成一个集合，集合中的元素值范围是 $[1,2...,batchSize-1]$。数组 $groups$ 的长度最大为 $30$，因此，每个余数的数量最大不超过 $30$。我们可以用 $5$ 个二进制位来表示一个余数的数量，而 $batchSize$ 最大为 $9$，那么表示这些余数以及对应的数量总共需要的二进制位就是 $5\times (9-1)=40$。我们可以用一个 $64$ 位整数 $state$ 来表示。

接下来，我们设计一个函数 $dfs(state, mod)$，表示安排状态为 $state$，且当前前缀余数为 $mod$ 时，能使得多少组感到开心。那么我们在“初始答案”加上 $dfs(state, 0)$，即为最终答案。

函数 $dfs(state, mod)$ 的实现逻辑如下：

我们枚举 $1$ 到 $batchSize-1$ 的每一个余数 $i$，如果余数 $i$ 的数量不为 $0$，那么我们可以将余数 $i$ 的数量减去 $1$，将当前前缀余数加上 $i$ 并且对 $batchSize$ 取模，然后递归调用函数 $dfs$，求出子状态的最优解，取最大值即可。最后判断 $mod$ 是否为 $0$，如果为 $0$，我们在最大值上加 $1$ 后返回，否则直接返回最大值。

过程中，我们可以使用记忆化搜索来避免状态的重复计算。

时间复杂度不超过 $O(10^7)$，空间复杂度不超过 $O(10^6)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        @cache
        def dfs(state, mod):
            res = 0
            x = int(mod == 0)
            for i in range(1, batchSize):
                if state >> (i * 5) & 31:
                    t = dfs(state - (1 << (i * 5)), (mod + i) % batchSize)
                    res = max(res, t + x)
            return res

        state = ans = 0
        for v in groups:
            i = v % batchSize
            ans += i == 0
            if i:
                state += 1 << (i * 5)
        ans += dfs(state, 0)
        return ans
```

#### Java

```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private int size;

    public int maxHappyGroups(int batchSize, int[] groups) {
        size = batchSize;
        int ans = 0;
        long state = 0;
        for (int g : groups) {
            int i = g % size;
            if (i == 0) {
                ++ans;
            } else {
                state += 1l << (i * 5);
            }
        }
        ans += dfs(state, 0);
        return ans;
    }

    private int dfs(long state, int mod) {
        if (f.containsKey(state)) {
            return f.get(state);
        }
        int res = 0;
        for (int i = 1; i < size; ++i) {
            if ((state >> (i * 5) & 31) != 0) {
                int t = dfs(state - (1l << (i * 5)), (mod + i) % size);
                res = Math.max(res, t + (mod == 0 ? 1 : 0));
            }
        }
        f.put(state, res);
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        using ll = long long;
        unordered_map<ll, int> f;
        ll state = 0;
        int ans = 0;
        for (auto& v : groups) {
            int i = v % batchSize;
            ans += i == 0;
            if (i) {
                state += 1ll << (i * 5);
            }
        }
        function<int(ll, int)> dfs = [&](ll state, int mod) {
            if (f.count(state)) {
                return f[state];
            }
            int res = 0;
            int x = mod == 0;
            for (int i = 1; i < batchSize; ++i) {
                if (state >> (i * 5) & 31) {
                    int t = dfs(state - (1ll << (i * 5)), (mod + i) % batchSize);
                    res = max(res, t + x);
                }
            }
            return f[state] = res;
        };
        ans += dfs(state, 0);
        return ans;
    }
};
```

#### Go

```go
func maxHappyGroups(batchSize int, groups []int) (ans int) {
	state := 0
	for _, v := range groups {
		i := v % batchSize
		if i == 0 {
			ans++
		} else {
			state += 1 << (i * 5)
		}
	}
	f := map[int]int{}
	var dfs func(int, int) int
	dfs = func(state, mod int) int {
		if v, ok := f[state]; ok {
			return v
		}
		res := 0
		x := 0
		if mod == 0 {
			x = 1
		}
		for i := 1; i < batchSize; i++ {
			if state>>(i*5)&31 != 0 {
				t := dfs(state-1<<(i*5), (mod+i)%batchSize)
				res = max(res, t+x)
			}
		}
		f[state] = res
		return res
	}
	ans += dfs(state, 0)
	return
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
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        @cache
        def dfs(state, x):
            if state == mask:
                return 0
            vis = [False] * batchSize
            res = 0
            for i, v in enumerate(g):
                if state >> i & 1 == 0 and not vis[v]:
                    vis[v] = True
                    y = (x + v) % batchSize
                    res = max(res, dfs(state | 1 << i, y))
            return res + (x == 0)

        g = [v % batchSize for v in groups if v % batchSize]
        mask = (1 << len(g)) - 1
        return len(groups) - len(g) + dfs(0, 0)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1816. 截断句子](https://leetcode.cn/problems/truncate-sentence){#1816}

{{< tabs "1816" >}}

{{% tab "python" %}}
```python
class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        for i, c in enumerate(s):
            k -= c == ' '
            if k == 0:
                return s[:i]
        return s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String truncateSentence(String s, int k) {
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == ' ' && (--k) == 0) {
                return s.substring(0, i);
            }
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
    string truncateSentence(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && (--k) == 0) {
                return s.substr(0, i);
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func truncateSentence(s string, k int) string {
	for i, c := range s {
		if c == ' ' {
			k--
		}
		if k == 0 {
			return s[:i]
		}
	}
	return s
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function truncateSentence(s: string, k: number): string {
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === ' ' && --k === 0) {
            return s.slice(0, i);
        }
    }
    return s;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function (s, k) {
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === ' ' && --k === 0) {
            return s.slice(0, i);
        }
    }
    return s;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>句子</strong> 是一个单词列表，列表中的单词之间用单个空格隔开，且不存在前导或尾随空格。每个单词仅由大小写英文字母组成（不含标点符号）。</p>

<ul>
	<li>例如，<code>"Hello World"</code>、<code>"HELLO"</code> 和 <code>"hello world hello world"</code> 都是句子。</li>
</ul>

<p>给你一个句子 <code>s</code>​​​​​​ 和一个整数 <code>k</code>​​​​​​ ，请你将 <code>s</code>​​ <strong>截断</strong> ​，​​​使截断后的句子仅含 <strong>前</strong> <code>k</code>​​​​​​ 个单词。返回 <strong>截断</strong> <code>s</code>​​​​<em>​​ </em>后得到的句子<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "Hello how are you Contestant", k = 4
<strong>输出：</strong>"Hello how are you"
<strong>解释：</strong>
s 中的单词为 ["Hello", "how" "are", "you", "Contestant"]
前 4 个单词为 ["Hello", "how", "are", "you"]
因此，应当返回 "Hello how are you"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "What is the solution to this problem", k = 4
<strong>输出：</strong>"What is the solution"
<strong>解释：</strong>
s 中的单词为 ["What", "is" "the", "solution", "to", "this", "problem"]
前 4 个单词为 ["What", "is", "the", "solution"]
因此，应当返回 "What is the solution"</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "chopper is not a tanuki", k = 5
<strong>输出：</strong>"chopper is not a tanuki"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>k</code> 的取值范围是 <code>[1,  s 中单词的数目]</code></li>
	<li><code>s</code> 仅由大小写英文字母和空格组成</li>
	<li><code>s</code> 中的单词之间由单个空格隔开</li>
	<li>不存在前导或尾随空格</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们从前往后遍历字符串 $s$，对于当前遍历到的字符 $s[i]$，如果 $s[i]$ 是空格，那么 $k$ 自减 $1$，当 $k$ 为 $0$ 时，说明已经截取了 $k$ 个单词，截取字符串 $s[0..i)$ 返回即可。

遍历结束，返回 $s$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        return ' '.join(s.split()[:k])
```

#### Java

```java
class Solution {
    public String truncateSentence(String s, int k) {
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == ' ' && (--k) == 0) {
                return s.substring(0, i);
            }
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string truncateSentence(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && (--k) == 0) {
                return s.substr(0, i);
            }
        }
        return s;
    }
};
```

#### Go

```go
func truncateSentence(s string, k int) string {
	for i, c := range s {
		if c == ' ' {
			k--
		}
		if k == 0 {
			return s[:i]
		}
	}
	return s
}
```

#### TypeScript

```ts
function truncateSentence(s: string, k: number): string {
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === ' ' && --k === 0) {
            return s.slice(0, i);
        }
    }
    return s;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function (s, k) {
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === ' ' && --k === 0) {
            return s.slice(0, i);
        }
    }
    return s;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        for i, c in enumerate(s):
            k -= c == ' '
            if k == 0:
                return s[:i]
        return s
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1817. 查找用户活跃分钟数](https://leetcode.cn/problems/finding-the-users-active-minutes){#1817}

{{< tabs "1817" >}}

{{% tab "python" %}}
```python
class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        d = defaultdict(set)
        for i, t in logs:
            d[i].add(t)
        ans = [0] * k
        for ts in d.values():
            ans[len(ts) - 1] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> d = new HashMap<>();
        for (var log : logs) {
            int i = log[0], t = log[1];
            d.computeIfAbsent(i, key -> new HashSet<>()).add(t);
        }
        int[] ans = new int[k];
        for (var ts : d.values()) {
            ++ans[ts.size() - 1];
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
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> d;
        for (auto& log : logs) {
            int i = log[0], t = log[1];
            d[i].insert(t);
        }
        vector<int> ans(k);
        for (auto& [_, ts] : d) {
            ++ans[ts.size() - 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findingUsersActiveMinutes(logs [][]int, k int) []int {
	d := map[int]map[int]bool{}
	for _, log := range logs {
		i, t := log[0], log[1]
		if _, ok := d[i]; !ok {
			d[i] = make(map[int]bool)
		}
		d[i][t] = true
	}
	ans := make([]int, k)
	for _, ts := range d {
		ans[len(ts)-1]++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findingUsersActiveMinutes(logs: number[][], k: number): number[] {
    const d: Map<number, Set<number>> = new Map();
    for (const [i, t] of logs) {
        if (!d.has(i)) {
            d.set(i, new Set<number>());
        }
        d.get(i)!.add(t);
    }
    const ans: number[] = Array(k).fill(0);
    for (const [_, ts] of d) {
        ++ans[ts.size - 1];
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

<p>给你用户在 LeetCode 的操作日志，和一个整数 <code>k</code> 。日志用一个二维整数数组 <code>logs</code> 表示，其中每个 <code>logs[i] = [ID<sub>i</sub>, time<sub>i</sub>]</code> 表示 ID 为 <code>ID<sub>i</sub></code> 的用户在 <code>time<sub>i</sub></code> 分钟时执行了某个操作。</p>

<p><strong>多个用户 </strong>可以同时执行操作，单个用户可以在同一分钟内执行 <strong>多个操作</strong> 。</p>

<p>指定用户的<strong> 用户活跃分钟数（user active minutes，UAM）</strong> 定义为用户对 LeetCode 执行操作的 <strong>唯一分钟数</strong> 。 即使一分钟内执行多个操作，也只能按一分钟计数。</p>

<p>请你统计用户活跃分钟数的分布情况，统计结果是一个长度为 <code>k</code> 且 <strong>下标从 1 开始计数</strong> 的数组 <code>answer</code> ，对于每个 <code>j</code>（<code>1 <= j <= k</code>），<code>answer[j]</code> 表示 <strong>用户活跃分钟数</strong> 等于 <code>j</code> 的用户数。</p>

<p>返回上面描述的答案数组<i> </i><code>answer</code><i> </i>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
<strong>输出：</strong>[0,2,0,0,0]
<strong>解释：</strong>
ID=0 的用户执行操作的分钟分别是：5 、2 和 5 。因此，该用户的用户活跃分钟数为 2（分钟 5 只计数一次）
ID=1 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
2 个用户的用户活跃分钟数都是 2 ，answer[2] 为 2 ，其余 answer[j] 的值都是 0
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>logs = [[1,1],[2,2],[2,3]], k = 4
<strong>输出：</strong>[1,1,0,0]
<strong>解释：</strong>
ID=1 的用户仅在分钟 1 执行单个操作。因此，该用户的用户活跃分钟数为 1
ID=2 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
1 个用户的用户活跃分钟数是 1 ，1 个用户的用户活跃分钟数是 2 
因此，answer[1] = 1 ，answer[2] = 1 ，其余的值都是 0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= logs.length <= 10<sup>4</sup></code></li>
	<li><code>0 <= ID<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>1 <= time<sub>i</sub> <= 10<sup>5</sup></code></li>
	<li><code>k</code> 的取值范围是 <code>[用户的最大用户活跃分钟数, 10<sup>5</sup>]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 $d$ 记录每个用户的所有去重操作时间，然后遍历哈希表，统计每个用户的用户活跃分钟数，最后统计每个用户活跃分钟数的分布情况。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $logs$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        d = defaultdict(set)
        for i, t in logs:
            d[i].add(t)
        ans = [0] * k
        for ts in d.values():
            ans[len(ts) - 1] += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> d = new HashMap<>();
        for (var log : logs) {
            int i = log[0], t = log[1];
            d.computeIfAbsent(i, key -> new HashSet<>()).add(t);
        }
        int[] ans = new int[k];
        for (var ts : d.values()) {
            ++ans[ts.size() - 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> d;
        for (auto& log : logs) {
            int i = log[0], t = log[1];
            d[i].insert(t);
        }
        vector<int> ans(k);
        for (auto& [_, ts] : d) {
            ++ans[ts.size() - 1];
        }
        return ans;
    }
};
```

#### Go

```go
func findingUsersActiveMinutes(logs [][]int, k int) []int {
	d := map[int]map[int]bool{}
	for _, log := range logs {
		i, t := log[0], log[1]
		if _, ok := d[i]; !ok {
			d[i] = make(map[int]bool)
		}
		d[i][t] = true
	}
	ans := make([]int, k)
	for _, ts := range d {
		ans[len(ts)-1]++
	}
	return ans
}
```

#### TypeScript

```ts
function findingUsersActiveMinutes(logs: number[][], k: number): number[] {
    const d: Map<number, Set<number>> = new Map();
    for (const [i, t] of logs) {
        if (!d.has(i)) {
            d.set(i, new Set<number>());
        }
        d.get(i)!.add(t);
    }
    const ans: number[] = Array(k).fill(0);
    for (const [_, ts] of d) {
        ++ans[ts.size - 1];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1818. 绝对差值和](https://leetcode.cn/problems/minimum-absolute-sum-difference){#1818}

{{< tabs "1818" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        mod = 10**9 + 7
        nums = sorted(nums1)
        s = sum(abs(a - b) for a, b in zip(nums1, nums2)) % mod
        mx = 0
        for a, b in zip(nums1, nums2):
            d1, d2 = abs(a - b), inf
            i = bisect_left(nums, b)
            if i < len(nums):
                d2 = min(d2, abs(nums[i] - b))
            if i:
                d2 = min(d2, abs(nums[i - 1] - b))
            mx = max(mx, d1 - d2)
        return (s - mx + mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        final int mod = (int) 1e9 + 7;
        int[] nums = nums1.clone();
        Arrays.sort(nums);
        int s = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            s = (s + Math.abs(nums1[i] - nums2[i])) % mod;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int d1 = Math.abs(nums1[i] - nums2[i]);
            int d2 = 1 << 30;
            int j = search(nums, nums2[i]);
            if (j < n) {
                d2 = Math.min(d2, Math.abs(nums[j] - nums2[i]));
            }
            if (j > 0) {
                d2 = Math.min(d2, Math.abs(nums[j - 1] - nums2[i]));
            }
            mx = Math.max(mx, d1 - d2);
        }
        return (s - mx + mod) % mod;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        vector<int> nums(nums1);
        sort(nums.begin(), nums.end());
        int s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            s = (s + abs(nums1[i] - nums2[i])) % mod;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int d1 = abs(nums1[i] - nums2[i]);
            int d2 = 1 << 30;
            int j = lower_bound(nums.begin(), nums.end(), nums2[i]) - nums.begin();
            if (j < n) {
                d2 = min(d2, abs(nums[j] - nums2[i]));
            }
            if (j) {
                d2 = min(d2, abs(nums[j - 1] - nums2[i]));
            }
            mx = max(mx, d1 - d2);
        }
        return (s - mx + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAbsoluteSumDiff(nums1 []int, nums2 []int) int {
	n := len(nums1)
	nums := make([]int, n)
	copy(nums, nums1)
	sort.Ints(nums)
	s, mx := 0, 0
	const mod int = 1e9 + 7
	for i, a := range nums1 {
		b := nums2[i]
		s = (s + abs(a-b)) % mod
	}
	for i, a := range nums1 {
		b := nums2[i]
		d1, d2 := abs(a-b), 1<<30
		j := sort.SearchInts(nums, b)
		if j < n {
			d2 = min(d2, abs(nums[j]-b))
		}
		if j > 0 {
			d2 = min(d2, abs(nums[j-1]-b))
		}
		mx = max(mx, d1-d2)
	}
	return (s - mx + mod) % mod
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
function minAbsoluteSumDiff(nums1: number[], nums2: number[]): number {
    const mod = 10 ** 9 + 7;
    const nums = [...nums1];
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s = (s + Math.abs(nums1[i] - nums2[i])) % mod;
    }
    let mx = 0;
    for (let i = 0; i < n; ++i) {
        const d1 = Math.abs(nums1[i] - nums2[i]);
        let d2 = 1 << 30;
        let j = search(nums, nums2[i]);
        if (j < n) {
            d2 = Math.min(d2, Math.abs(nums[j] - nums2[i]));
        }
        if (j) {
            d2 = Math.min(d2, Math.abs(nums[j - 1] - nums2[i]));
        }
        mx = Math.max(mx, d1 - d2);
    }
    return (s - mx + mod) % mod;
}

function search(nums: number[], x: number): number {
    let left = 0;
    let right = nums.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minAbsoluteSumDiff = function (nums1, nums2) {
    const mod = 10 ** 9 + 7;
    const nums = [...nums1];
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s = (s + Math.abs(nums1[i] - nums2[i])) % mod;
    }
    let mx = 0;
    for (let i = 0; i < n; ++i) {
        const d1 = Math.abs(nums1[i] - nums2[i]);
        let d2 = 1 << 30;
        let j = search(nums, nums2[i]);
        if (j < n) {
            d2 = Math.min(d2, Math.abs(nums[j] - nums2[i]));
        }
        if (j) {
            d2 = Math.min(d2, Math.abs(nums[j - 1] - nums2[i]));
        }
        mx = Math.max(mx, d1 - d2);
    }
    return (s - mx + mod) % mod;
};

function search(nums, x) {
    let left = 0;
    let right = nums.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数数组 <code>nums1</code> 和 <code>nums2</code> ，数组的长度都是 <code>n</code> 。</p>

<p>数组 <code>nums1</code> 和 <code>nums2</code> 的 <strong>绝对差值和</strong> 定义为所有 <code>|nums1[i] - nums2[i]|</code>（<code>0 <= i < n</code>）的 <strong>总和</strong>（<strong>下标从 0 开始</strong>）。</p>

<p>你可以选用 <code>nums1</code> 中的 <strong>任意一个</strong> 元素来替换 <code>nums1</code> 中的 <strong>至多</strong> 一个元素，以 <strong>最小化</strong> 绝对差值和。</p>

<p>在替换数组 <code>nums1</code> 中最多一个元素 <strong>之后</strong> ，返回最小绝对差值和。因为答案可能很大，所以需要对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>后返回。</p>

<p><code>|x|</code> 定义为：</p>

<ul>
	<li>如果 <code>x >= 0</code> ，值为 <code>x</code> ，或者</li>
	<li>如果 <code>x <= 0</code> ，值为 <code>-x</code></li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,7,5], nums2 = [2,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>有两种可能的最优方案：
- 将第二个元素替换为第一个元素：[1,<strong>7</strong>,5] => [1,<strong>1</strong>,5] ，或者
- 将第二个元素替换为第三个元素：[1,<strong>7</strong>,5] => [1,<strong>5</strong>,5]
两种方案的绝对差值和都是 <code>|1-2| + (|1-3| 或者 |5-3|) + |5-5| = </code>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
<strong>输出：</strong>0
<strong>解释：</strong>nums1 和 nums2 相等，所以不用替换元素。绝对差值和为 0
</pre>

<p><strong>示例 3</strong><strong>：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
<strong>输出：</strong>20
<strong>解释：</strong>将第一个元素替换为第二个元素：[<strong>1</strong>,10,4,4,2,7] => [<strong>10</strong>,10,4,4,2,7]
绝对差值和为 <code>|10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20</code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums1[i], nums2[i] <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

根据题意，我们可以先计算出在不进行替换的情况下，`nums1` 和 `nums2` 的绝对差值和，记为 $s$。

接下来，我们枚举 `nums1` 中的每个元素 $nums1[i]$，将其替换为与 $nums2[i]$ 最接近的元素，并且这个最接近的元素在 `nums1` 中。因此，我们可以在枚举之前，先复制一份 `nums1`，得到数组 `nums`，并将 `nums` 排序。接下来，就在 `nums` 中二分查找与 $nums2[i]$ 最接近的元素，记为 $nums[j]$，并计算 $|nums1[i] - nums2[i]| - |nums[j] - nums2[i]|$，更新差值 $mx$ 的最大值。

最后，我们将 $s$ 减去 $mx$，即为答案。注意取模操作。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums1` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        mod = 10**9 + 7
        nums = sorted(nums1)
        s = sum(abs(a - b) for a, b in zip(nums1, nums2)) % mod
        mx = 0
        for a, b in zip(nums1, nums2):
            d1, d2 = abs(a - b), inf
            i = bisect_left(nums, b)
            if i < len(nums):
                d2 = min(d2, abs(nums[i] - b))
            if i:
                d2 = min(d2, abs(nums[i - 1] - b))
            mx = max(mx, d1 - d2)
        return (s - mx + mod) % mod
```

#### Java

```java
class Solution {
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        final int mod = (int) 1e9 + 7;
        int[] nums = nums1.clone();
        Arrays.sort(nums);
        int s = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            s = (s + Math.abs(nums1[i] - nums2[i])) % mod;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int d1 = Math.abs(nums1[i] - nums2[i]);
            int d2 = 1 << 30;
            int j = search(nums, nums2[i]);
            if (j < n) {
                d2 = Math.min(d2, Math.abs(nums[j] - nums2[i]));
            }
            if (j > 0) {
                d2 = Math.min(d2, Math.abs(nums[j - 1] - nums2[i]));
            }
            mx = Math.max(mx, d1 - d2);
        }
        return (s - mx + mod) % mod;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 + 7;
        vector<int> nums(nums1);
        sort(nums.begin(), nums.end());
        int s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            s = (s + abs(nums1[i] - nums2[i])) % mod;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int d1 = abs(nums1[i] - nums2[i]);
            int d2 = 1 << 30;
            int j = lower_bound(nums.begin(), nums.end(), nums2[i]) - nums.begin();
            if (j < n) {
                d2 = min(d2, abs(nums[j] - nums2[i]));
            }
            if (j) {
                d2 = min(d2, abs(nums[j - 1] - nums2[i]));
            }
            mx = max(mx, d1 - d2);
        }
        return (s - mx + mod) % mod;
    }
};
```

#### Go

```go
func minAbsoluteSumDiff(nums1 []int, nums2 []int) int {
	n := len(nums1)
	nums := make([]int, n)
	copy(nums, nums1)
	sort.Ints(nums)
	s, mx := 0, 0
	const mod int = 1e9 + 7
	for i, a := range nums1 {
		b := nums2[i]
		s = (s + abs(a-b)) % mod
	}
	for i, a := range nums1 {
		b := nums2[i]
		d1, d2 := abs(a-b), 1<<30
		j := sort.SearchInts(nums, b)
		if j < n {
			d2 = min(d2, abs(nums[j]-b))
		}
		if j > 0 {
			d2 = min(d2, abs(nums[j-1]-b))
		}
		mx = max(mx, d1-d2)
	}
	return (s - mx + mod) % mod
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
function minAbsoluteSumDiff(nums1: number[], nums2: number[]): number {
    const mod = 10 ** 9 + 7;
    const nums = [...nums1];
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s = (s + Math.abs(nums1[i] - nums2[i])) % mod;
    }
    let mx = 0;
    for (let i = 0; i < n; ++i) {
        const d1 = Math.abs(nums1[i] - nums2[i]);
        let d2 = 1 << 30;
        let j = search(nums, nums2[i]);
        if (j < n) {
            d2 = Math.min(d2, Math.abs(nums[j] - nums2[i]));
        }
        if (j) {
            d2 = Math.min(d2, Math.abs(nums[j - 1] - nums2[i]));
        }
        mx = Math.max(mx, d1 - d2);
    }
    return (s - mx + mod) % mod;
}

function search(nums: number[], x: number): number {
    let left = 0;
    let right = nums.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minAbsoluteSumDiff = function (nums1, nums2) {
    const mod = 10 ** 9 + 7;
    const nums = [...nums1];
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s = (s + Math.abs(nums1[i] - nums2[i])) % mod;
    }
    let mx = 0;
    for (let i = 0; i < n; ++i) {
        const d1 = Math.abs(nums1[i] - nums2[i]);
        let d2 = 1 << 30;
        let j = search(nums, nums2[i]);
        if (j < n) {
            d2 = Math.min(d2, Math.abs(nums[j] - nums2[i]));
        }
        if (j) {
            d2 = Math.min(d2, Math.abs(nums[j - 1] - nums2[i]));
        }
        mx = Math.max(mx, d1 - d2);
    }
    return (s - mx + mod) % mod;
};

function search(nums, x) {
    let left = 0;
    let right = nums.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1819. 序列中不同最大公约数的数目](https://leetcode.cn/problems/number-of-different-subsequences-gcds){#1819}

{{< tabs "1819" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        mx = max(nums)
        vis = set(nums)
        ans = 0
        for x in range(1, mx + 1):
            g = 0
            for y in range(x, mx + 1, x):
                if y in vis:
                    g = gcd(g, y)
                    if g == x:
                        ans += 1
                        break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDifferentSubsequenceGCDs(int[] nums) {
        int mx = Arrays.stream(nums).max().getAsInt();
        boolean[] vis = new boolean[mx + 1];
        for (int x : nums) {
            vis[x] = true;
        }
        int ans = 0;
        for (int x = 1; x <= mx; ++x) {
            int g = 0;
            for (int y = x; y <= mx; y += x) {
                if (vis[y]) {
                    g = gcd(g, y);
                    if (x == g) {
                        ++ans;
                        break;
                    }
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
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> vis(mx + 1);
        for (int& x : nums) {
            vis[x] = true;
        }
        int ans = 0;
        for (int x = 1; x <= mx; ++x) {
            int g = 0;
            for (int y = x; y <= mx; y += x) {
                if (vis[y]) {
                    g = gcd(g, y);
                    if (g == x) {
                        ++ans;
                        break;
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
func countDifferentSubsequenceGCDs(nums []int) (ans int) {
	mx := slices.Max(nums)
	vis := make([]bool, mx+1)
	for _, x := range nums {
		vis[x] = true
	}
	for x := 1; x <= mx; x++ {
		g := 0
		for y := x; y <= mx; y += x {
			if vis[y] {
				g = gcd(g, y)
				if g == x {
					ans++
					break
				}
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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由正整数组成的数组 <code>nums</code> 。</p>

<p>数字序列的 <strong>最大公约数</strong> 定义为序列中所有整数的共有约数中的最大整数。</p>

<ul>
	<li>例如，序列 <code>[4,6,16]</code> 的最大公约数是 <code>2</code> 。</li>
</ul>

<p>数组的一个 <strong>子序列</strong> 本质是一个序列，可以通过删除数组中的某些元素（或者不删除）得到。</p>

<ul>
	<li>例如，<code>[2,5,10]</code> 是 <code>[1,2,1,<strong>2</strong>,4,1,<strong>5</strong>,<strong>10</strong>]</code> 的一个子序列。</li>
</ul>

<p>计算并返回 <code>nums</code> 的所有 <strong>非空</strong> 子序列中 <strong>不同</strong> 最大公约数的 <strong>数目</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1819.Number%20of%20Different%20Subsequences%20GCDs/images/image-1.png" />
<pre>
<strong>输入：</strong>nums = [6,10,3]
<strong>输出：</strong>5
<strong>解释：</strong>上图显示了所有的非空子序列与各自的最大公约数。
不同的最大公约数为 6 、10 、3 、2 和 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,15,40,5,6]
<strong>输出：</strong>7
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 2 * 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 数学

对于数组 $nums$ 的所有子序列，其最大公约数一定不超过数组中的最大值 $mx$。

因此我们可以枚举 $[1,.. mx]$ 中的每个数 $x$，判断 $x$ 是否为数组 $nums$ 的子序列的最大公约数，如果是，则答案加一。

那么问题转换为：判断 $x$ 是否为数组 $nums$ 的子序列的最大公约数。我们可以通过枚举 $x$ 的倍数 $y$，判断 $y$ 是否在数组 $nums$ 中，如果 $y$ 在数组 $nums$ 中，则计算 $y$ 的最大公约数 $g$，如果出现 $g = x$，则 $x$ 是数组 $nums$ 的子序列的最大公约数。

时间复杂度 $O(n + M \times \log M)$，空间复杂度 $O(M)$。其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度和数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        mx = max(nums)
        vis = set(nums)
        ans = 0
        for x in range(1, mx + 1):
            g = 0
            for y in range(x, mx + 1, x):
                if y in vis:
                    g = gcd(g, y)
                    if g == x:
                        ans += 1
                        break
        return ans
```

#### Java

```java
class Solution {
    public int countDifferentSubsequenceGCDs(int[] nums) {
        int mx = Arrays.stream(nums).max().getAsInt();
        boolean[] vis = new boolean[mx + 1];
        for (int x : nums) {
            vis[x] = true;
        }
        int ans = 0;
        for (int x = 1; x <= mx; ++x) {
            int g = 0;
            for (int y = x; y <= mx; y += x) {
                if (vis[y]) {
                    g = gcd(g, y);
                    if (x == g) {
                        ++ans;
                        break;
                    }
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
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> vis(mx + 1);
        for (int& x : nums) {
            vis[x] = true;
        }
        int ans = 0;
        for (int x = 1; x <= mx; ++x) {
            int g = 0;
            for (int y = x; y <= mx; y += x) {
                if (vis[y]) {
                    g = gcd(g, y);
                    if (g == x) {
                        ++ans;
                        break;
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
func countDifferentSubsequenceGCDs(nums []int) (ans int) {
	mx := slices.Max(nums)
	vis := make([]bool, mx+1)
	for _, x := range nums {
		vis[x] = true
	}
	for x := 1; x <= mx; x++ {
		g := 0
		for y := x; y <= mx; y += x {
			if vis[y] {
				g = gcd(g, y)
				if g == x {
					ans++
					break
				}
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

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
