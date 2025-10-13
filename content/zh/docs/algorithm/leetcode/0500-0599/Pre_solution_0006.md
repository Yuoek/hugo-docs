---
title: "0550_游戏玩法分析 IV"
date: 2025-10-08T18:36:17+08:00
weight: 6
tags: [分治, 动态规划, 双指针, 哈希表, 字符串, 广度优先搜索, 数学, 数据库, 数组, 树, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [0550_游戏玩法分析 IV](#550)
#### [数据库](#550)
### [0551_学生出勤记录 I](#551)
#### [字符串](#551)
### [0552_学生出勤记录 II](#552)
#### [动态规划](#552)
### [0553_最优除法](#553)
#### [数组](#553)
#### [数学](#553)
#### [动态规划](#553)
### [0554_砖墙](#554)
#### [数组](#554)
#### [哈希表](#554)
### [0555_分割连接字符串 🔒](#555)
#### [贪心](#555)
#### [数组](#555)
#### [字符串](#555)
### [0556_下一个更大元素 III](#556)
#### [数学](#556)
#### [双指针](#556)
#### [字符串](#556)
### [0557_反转字符串中的单词 III](#557)
#### [双指针](#557)
#### [字符串](#557)
### [0558_四叉树交集](#558)
#### [树](#558)
#### [分治](#558)
### [0559_N 叉树的最大深度](#559)
#### [树](#559)
#### [深度优先搜索](#559)
#### [广度优先搜索](#559)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0550_游戏玩法分析 IV
___
#### 数据库
---
### 0551_学生出勤记录 I
___
#### 字符串
---
### 0552_学生出勤记录 II
___
#### 动态规划
---
### 0553_最优除法
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 0554_砖墙
___
#### 数组
___
#### 哈希表
---
### 0555_分割连接字符串 🔒
___
#### 贪心
___
#### 数组
___
#### 字符串
---
### 0556_下一个更大元素 III
___
#### 数学
___
#### 双指针
___
#### 字符串
---
### 0557_反转字符串中的单词 III
___
#### 双指针
___
#### 字符串
---
### 0558_四叉树交集
___
#### 树
___
#### 分治
---
### 0559_N 叉树的最大深度
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 分治 | 动态规划 | 双指针 |
| 哈希表 | 字符串 | 广度优先搜索 |
| 数学 | 数据库 | 数组 |
| 树 | 深度优先搜索 | 贪心 |

# [550. 游戏玩法分析 IV](https://leetcode.cn/problems/game-play-analysis-iv){#550}

{{< tabs "550" >}}

{{% tab "python" %}}
```python
import pandas as pd


def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    activity["first"] = activity.groupby("player_id").event_date.transform(min)
    activity_2nd_day = activity[
        activity["first"] + pd.DateOffset(1) == activity["event_date"]
    ]

    return pd.DataFrame(
        {"fraction": [round(len(activity_2nd_day) / activity.player_id.nunique(), 2)]}
    )
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            player_id,
            DATEDIFF(
                LEAD(event_date) OVER (
                    PARTITION BY player_id
                    ORDER BY event_date
                ),
                event_date
            ) = 1 AS st,
            RANK() OVER (
                PARTITION BY player_id
                ORDER BY event_date
            ) AS rk
        FROM Activity
    )
SELECT ROUND(COUNT(IF(st = 1, player_id, NULL)) / COUNT(DISTINCT player_id), 2) AS fraction
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Table:&nbsp;<code>Activity</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
（player_id，event_date）是此表的主键（具有唯一值的列的组合）。
这张表显示了某些游戏的玩家的活动情况。
每一行是一个玩家的记录，他在某一天使用某个设备注销之前登录并玩了很多游戏（可能是 0）。
</pre>

<p>编写解决方案，报告在首次登录的第二天再次登录的玩家的 <strong>比率</strong>，<strong>四舍五入到小数点后两位</strong>。换句话说，你需要计算从首次登录后的第二天登录的玩家数量，并将其除以总玩家数。</p>

<p>结果格式如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
<strong>输出：</strong>
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+
<strong>解释：</strong>
只有 ID 为 1 的玩家在第一天登录后才重新登录，所以答案是 1/3 = 0.33
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组取最小值 + 左连接

我们可以先找到每个玩家的首次登录日期，然后与原表进行左连接，连接条件为玩家 ID 相同且日期差为 $-1$，即第二天登录。那么，我们只需要统计出第二天登录的玩家数量中，玩家不为空的比率即可。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    activity["first"] = activity.groupby("player_id").event_date.transform(min)
    activity_2nd_day = activity[
        activity["first"] + pd.DateOffset(1) == activity["event_date"]
    ]

    return pd.DataFrame(
        {"fraction": [round(len(activity_2nd_day) / activity.player_id.nunique(), 2)]}
    )
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT ROUND(AVG(b.event_date IS NOT NULL), 2) AS fraction
FROM
    (
        SELECT player_id, MIN(event_date) AS event_date
        FROM Activity
        GROUP BY 1
    ) AS a
    LEFT JOIN Activity AS b
        ON a.player_id = b.player_id AND DATEDIFF(a.event_date, b.event_date) = -1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们也可以使用窗口函数 `LEAD` 获取每个玩家的下一次登录日期，如果下一次登录日期与当前登录日期相差 $1$ 天，则说明该玩家在第二天登录，我们用一个字段 $st$ 记录该信息。然后，我们用窗口函数 `RANK` 对玩家 ID 按照日期升序排列，得到每个玩家的登录排名。最后，我们只需要统计出排名为 $1$ 的玩家中，字段 $st$ 不为空的比率即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            player_id,
            DATEDIFF(
                LEAD(event_date) OVER (
                    PARTITION BY player_id
                    ORDER BY event_date
                ),
                event_date
            ) = 1 AS st,
            RANK() OVER (
                PARTITION BY player_id
                ORDER BY event_date
            ) AS rk
        FROM Activity
    )
SELECT ROUND(COUNT(IF(st = 1, player_id, NULL)) / COUNT(DISTINCT player_id), 2) AS fraction
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [551. 学生出勤记录 I](https://leetcode.cn/problems/student-attendance-record-i){#551}

{{< tabs "551" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkRecord(self, s: str) -> bool:
        return s.count('A') < 2 and 'LLL' not in s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkRecord(String s) {
        return s.indexOf("A") == s.lastIndexOf("A") && !s.contains("LLL");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkRecord(string s) {
        return count(s.begin(), s.end(), 'A') < 2 && s.find("LLL") == string::npos;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkRecord(s string) bool {
	return strings.Count(s, "A") < 2 && !strings.Contains(s, "LLL")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkRecord(s: string): boolean {
    return s.indexOf('A') === s.lastIndexOf('A') && s.indexOf('LLL') === -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：</p>

<ul>
	<li><code>'A'</code>：Absent，缺勤</li>
	<li><code>'L'</code>：Late，迟到</li>
	<li><code>'P'</code>：Present，到场</li>
</ul>

<p>如果学生能够 <strong>同时</strong> 满足下面两个条件，则可以获得出勤奖励：</p>

<ul>
	<li>按 <strong>总出勤</strong> 计，学生缺勤（<code>'A'</code>）<strong>严格</strong> 少于两天。</li>
	<li>学生 <strong>不会</strong> 存在 <strong>连续</strong> 3 天或 <strong>连续</strong> 3 天以上的迟到（<code>'L'</code>）记录。</li>
</ul>

<p>如果学生可以获得出勤奖励，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "PPALLP"
<strong>输出：</strong>true
<strong>解释：</strong>学生缺勤次数少于 2 次，且不存在 3 天或以上的连续迟到记录。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "PPALLL"
<strong>输出：</strong>false
<strong>解释：</strong>学生最后三天连续迟到，所以不满足出勤奖励的条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 为 <code>'A'</code>、<code>'L'</code> 或 <code>'P'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串遍历

我们可以遍历字符串 $s$，记录字符 `'A'` 和字符串 `"LLL"` 的出现次数。如果字符 `'A'` 的出现次数小于 $2$，且字符串 `"LLL"` 没有出现过，则可以将该字符串视作记录合法，返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkRecord(self, s: str) -> bool:
        return s.count('A') < 2 and 'LLL' not in s
```

#### Java

```java
class Solution {
    public boolean checkRecord(String s) {
        return s.indexOf("A") == s.lastIndexOf("A") && !s.contains("LLL");
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        return count(s.begin(), s.end(), 'A') < 2 && s.find("LLL") == string::npos;
    }
};
```

#### Go

```go
func checkRecord(s string) bool {
	return strings.Count(s, "A") < 2 && !strings.Contains(s, "LLL")
}
```

#### TypeScript

```ts
function checkRecord(s: string): boolean {
    return s.indexOf('A') === s.lastIndexOf('A') && s.indexOf('LLL') === -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [552. 学生出勤记录 II](https://leetcode.cn/problems/student-attendance-record-ii){#552}

{{< tabs "552" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkRecord(self, n: int) -> int:
        mod = int(1e9 + 7)
        dp = [[[0, 0, 0], [0, 0, 0]] for _ in range(n)]

        # base case
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1

        for i in range(1, n):
            # A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod
            # L
            dp[i][0][1] = dp[i - 1][0][0]
            dp[i][0][2] = dp[i - 1][0][1]
            dp[i][1][1] = dp[i - 1][1][0]
            dp[i][1][2] = dp[i - 1][1][1]
            # P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod
            dp[i][1][0] = (
                dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]
            ) % mod

        ans = 0
        for j in range(2):
            for k in range(3):
                ans = (ans + dp[n - 1][j][k]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = 1000000007;

    public int checkRecord(int n) {
        long[][][] dp = new long[n][2][3];

        // base case
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;

        for (int i = 1; i < n; i++) {
            // A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            // L
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
            // P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        }

        long ans = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                ans = (ans + dp[n - 1][j][k]) % MOD;
            }
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        using ll = long long;
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(3)));

        // base case
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;

        for (int i = 1; i < n; ++i) {
            // A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            // L
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
            // P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        }

        ll ans = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans = (ans + dp[n - 1][j][k]) % MOD;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const _mod int = 1e9 + 7

func checkRecord(n int) int {
	dp := make([][][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int, 3)
		}
	}

	// base case
	dp[0][0][0] = 1
	dp[0][0][1] = 1
	dp[0][1][0] = 1

	for i := 1; i < n; i++ {
		// A
		dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % _mod
		// L
		dp[i][0][1] = dp[i-1][0][0]
		dp[i][0][2] = dp[i-1][0][1]
		dp[i][1][1] = dp[i-1][1][0]
		dp[i][1][2] = dp[i-1][1][1]
		// P
		dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % _mod
		dp[i][1][0] = (dp[i][1][0] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % _mod
	}

	var ans int
	for j := 0; j < 2; j++ {
		for k := 0; k < 3; k++ {
			ans = (ans + dp[n-1][j][k]) % _mod
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

可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：

<ul>
	<li><code>'A'</code>：Absent，缺勤</li>
	<li><code>'L'</code>：Late，迟到</li>
	<li><code>'P'</code>：Present，到场</li>
</ul>

<p>如果学生能够 <strong>同时</strong> 满足下面两个条件，则可以获得出勤奖励：</p>

<ul>
	<li>按 <strong>总出勤</strong> 计，学生缺勤（<code>'A'</code>）<strong>严格</strong> 少于两天。</li>
	<li>学生 <strong>不会</strong> 存在 <strong>连续</strong> 3 天或 <strong>连续</strong> 3 天以上的迟到（<code>'L'</code>）记录。</li>
</ul>

<p>给你一个整数 <code>n</code> ，表示出勤记录的长度（次数）。请你返回记录长度为 <code>n</code> 时，可能获得出勤奖励的记录情况 <strong>数量</strong> 。答案可能很大，所以返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>8
<strong>解释：
</strong>有 8 种长度为 2 的记录将被视为可奖励：
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL" 
只有"AA"不会被视为可奖励，因为缺勤次数为 2 次（需要少于 2 次）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 10101
<strong>输出：</strong>183236316
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, k)$，表示从第 $i$ 个出勤记录开始，当前缺勤次数为 $j$，目前最后连续迟到次数为 $k$ 时，可获得出勤奖励的情况数量。那么答案就是 $dfs(0, 0, 0)$。

函数 $dfs(i, j, k)$ 的执行过程如下：

-   如果 $i \ge n$，说明已经遍历完所有出勤记录，返回 $1$；
-   如果 $j = 0$，说明当前缺勤次数为 $0$，那么可以选择缺勤，即 $dfs(i + 1, j + 1, 0)$；
-   如果 $k \lt 2$，说明当前连续迟到次数小于 $2$，那么可以选择迟到，即 $dfs(i + 1, j, k + 1)$；
-   无论如何，都可以选择到场，即 $dfs(i + 1, j, 0)$。

我们将上述三种情况的结果相加，即为 $dfs(i, j, k)$ 的结果。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为出勤记录的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkRecord(self, n: int) -> int:
        @cache
        def dfs(i, j, k):
            if i >= n:
                return 1
            ans = 0
            if j == 0:
                ans += dfs(i + 1, j + 1, 0)
            if k < 2:
                ans += dfs(i + 1, j, k + 1)
            ans += dfs(i + 1, j, 0)
            return ans % mod

        mod = 10**9 + 7
        ans = dfs(0, 0, 0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;
    private int n;
    private Integer[][][] f;

    public int checkRecord(int n) {
        this.n = n;
        f = new Integer[n][2][3];
        return dfs(0, 0, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i >= n) {
            return 1;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, 0);
        if (j == 0) {
            ans = (ans + dfs(i + 1, j + 1, 0)) % mod;
        }
        if (k < 2) {
            ans = (ans + dfs(i + 1, j, k + 1)) % mod;
        }
        return f[i][j][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int checkRecord(int n) {
        int f[n][2][3];
        memset(f, -1, sizeof(f));
        const int mod = 1e9 + 7;
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i >= n) {
                return 1;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = dfs(i + 1, j, 0);
            if (j == 0) {
                ans = (ans + dfs(i + 1, j + 1, 0)) % mod;
            }
            if (k < 2) {
                ans = (ans + dfs(i + 1, j, k + 1)) % mod;
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, 0, 0);
    }
};
```

#### Go

```go
func checkRecord(n int) int {
	f := make([][][]int, n)
	for i := range f {
		f[i] = make([][]int, 2)
		for j := range f[i] {
			f[i][j] = make([]int, 3)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	const mod = 1e9 + 7
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i >= n {
			return 1
		}
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		ans := dfs(i+1, j, 0)
		if j == 0 {
			ans = (ans + dfs(i+1, j+1, 0)) % mod
		}
		if k < 2 {
			ans = (ans + dfs(i+1, j, k+1)) % mod
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, 0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

动态规划，定义 `dp[i][j][k]` 表示前 `i` 天，缺勤 `j` 次，连续迟到 `k` 次时，可获得出勤奖励的情况数量

状态转移需要对第 `i` 天的出勤情况分别讨论：

-   缺勤：之前不能有任何缺勤记录，即 `j == 0`
-   迟到：之前最多连续迟到 1 次，即 `k == 0 || k == 1`
-   到场：无限制

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkRecord(self, n: int) -> int:
        mod = int(1e9 + 7)
        dp = [[[0, 0, 0], [0, 0, 0]] for _ in range(n)]

        # base case
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1

        for i in range(1, n):
            # A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod
            # L
            dp[i][0][1] = dp[i - 1][0][0]
            dp[i][0][2] = dp[i - 1][0][1]
            dp[i][1][1] = dp[i - 1][1][0]
            dp[i][1][2] = dp[i - 1][1][1]
            # P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod
            dp[i][1][0] = (
                dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]
            ) % mod

        ans = 0
        for j in range(2):
            for k in range(3):
                ans = (ans + dp[n - 1][j][k]) % mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = 1000000007;

    public int checkRecord(int n) {
        long[][][] dp = new long[n][2][3];

        // base case
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;

        for (int i = 1; i < n; i++) {
            // A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            // L
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
            // P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        }

        long ans = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                ans = (ans + dp[n - 1][j][k]) % MOD;
            }
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        using ll = long long;
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(3)));

        // base case
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;

        for (int i = 1; i < n; ++i) {
            // A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            // L
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
            // P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        }

        ll ans = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans = (ans + dp[n - 1][j][k]) % MOD;
            }
        }
        return ans;
    }
};
```

#### Go

```go
const _mod int = 1e9 + 7

func checkRecord(n int) int {
	dp := make([][][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int, 3)
		}
	}

	// base case
	dp[0][0][0] = 1
	dp[0][0][1] = 1
	dp[0][1][0] = 1

	for i := 1; i < n; i++ {
		// A
		dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % _mod
		// L
		dp[i][0][1] = dp[i-1][0][0]
		dp[i][0][2] = dp[i-1][0][1]
		dp[i][1][1] = dp[i-1][1][0]
		dp[i][1][2] = dp[i-1][1][1]
		// P
		dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % _mod
		dp[i][1][0] = (dp[i][1][0] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % _mod
	}

	var ans int
	for j := 0; j < 2; j++ {
		for k := 0; k < 3; k++ {
			ans = (ans + dp[n-1][j][k]) % _mod
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

# [553. 最优除法](https://leetcode.cn/problems/optimal-division){#553}

{{< tabs "553" >}}

{{% tab "python" %}}
```python
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        n = len(nums)
        if n == 1:
            return str(nums[0])
        if n == 2:
            return f'{nums[0]}/{nums[1]}'
        return f'{nums[0]}/({"/".join(map(str, nums[1:]))})'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String optimalDivision(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0] + "";
        }
        if (n == 2) {
            return nums[0] + "/" + nums[1];
        }
        StringBuilder ans = new StringBuilder(nums[0] + "/(");
        for (int i = 1; i < n - 1; ++i) {
            ans.append(nums[i] + "/");
        }
        ans.append(nums[n - 1] + ")");
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ans = to_string(nums[0]) + "/(";
        for (int i = 1; i < n - 1; i++) ans.append(to_string(nums[i]) + "/");
        ans.append(to_string(nums[n - 1]) + ")");
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func optimalDivision(nums []int) string {
	n := len(nums)
	if n == 1 {
		return strconv.Itoa(nums[0])
	}
	if n == 2 {
		return fmt.Sprintf("%d/%d", nums[0], nums[1])
	}
	ans := &strings.Builder{}
	ans.WriteString(fmt.Sprintf("%d/(", nums[0]))
	for _, num := range nums[1 : n-1] {
		ans.WriteString(strconv.Itoa(num))
		ans.WriteByte('/')
	}
	ans.WriteString(fmt.Sprintf("%d)", nums[n-1]))
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function optimalDivision(nums: number[]): string {
    const n = nums.length;
    const res = nums.join('/');
    if (n > 2) {
        const index = res.indexOf('/') + 1;
        return `${res.slice(0, index)}(${res.slice(index)})`;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn optimal_division(nums: Vec<i32>) -> String {
        let n = nums.len();
        match n {
            1 => nums[0].to_string(),
            2 => nums[0].to_string() + "/" + &nums[1].to_string(),
            _ => {
                let mut res = nums[0].to_string();
                res.push_str("/(");
                for i in 1..n {
                    res.push_str(&nums[i].to_string());
                    res.push('/');
                }
                res.pop();
                res.push(')');
                res
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

<p>给定一正整数数组<strong> </strong><code>nums</code><strong>，</strong><code>nums</code> 中的相邻整数将进行浮点除法。</p>

<ul>
	<li>例如，<code>nums = [2,3,4]</code>，我们将求表达式的值&nbsp;<code>"2/3/4"</code>。</li>
</ul>

<p>但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，以便计算后的表达式的值为最大值。</p>

<p>以字符串格式返回具有最大值的对应表达式。</p>

<p><strong>注意：</strong>你的表达式不应该包含多余的括号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> [1000,100,10,2]
<strong>输出:</strong> "1000/(100/10/2)"
<strong>解释: </strong>1000/(100/10/2) = 1000/((100/10)/2) = 200
但是，以下加粗的括号 "1000/(<strong>(</strong>100/10<strong>)</strong>/2)" 是冗余的，
因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

其他用例:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
</pre>

<p>&nbsp;</p>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,3,4]
<strong>输出:</strong> "2/(3/4)"
<strong>解释:</strong> (2/(3/4)) = 8/3 = 2.667
可以看出，在尝试了所有的可能性之后，我们无法得到一个结果大于 2.667 的表达式。
</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>2 &lt;= nums[i] &lt;= 1000</code></li>
	<li>对于给定的输入只有一种最优除法。</li>
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
    def optimalDivision(self, nums: List[int]) -> str:
        n = len(nums)
        if n == 1:
            return str(nums[0])
        if n == 2:
            return f'{nums[0]}/{nums[1]}'
        return f'{nums[0]}/({"/".join(map(str, nums[1:]))})'
```

#### Java

```java
class Solution {
    public String optimalDivision(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0] + "";
        }
        if (n == 2) {
            return nums[0] + "/" + nums[1];
        }
        StringBuilder ans = new StringBuilder(nums[0] + "/(");
        for (int i = 1; i < n - 1; ++i) {
            ans.append(nums[i] + "/");
        }
        ans.append(nums[n - 1] + ")");
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ans = to_string(nums[0]) + "/(";
        for (int i = 1; i < n - 1; i++) ans.append(to_string(nums[i]) + "/");
        ans.append(to_string(nums[n - 1]) + ")");
        return ans;
    }
};
```

#### Go

```go
func optimalDivision(nums []int) string {
	n := len(nums)
	if n == 1 {
		return strconv.Itoa(nums[0])
	}
	if n == 2 {
		return fmt.Sprintf("%d/%d", nums[0], nums[1])
	}
	ans := &strings.Builder{}
	ans.WriteString(fmt.Sprintf("%d/(", nums[0]))
	for _, num := range nums[1 : n-1] {
		ans.WriteString(strconv.Itoa(num))
		ans.WriteByte('/')
	}
	ans.WriteString(fmt.Sprintf("%d)", nums[n-1]))
	return ans.String()
}
```

#### TypeScript

```ts
function optimalDivision(nums: number[]): string {
    const n = nums.length;
    const res = nums.join('/');
    if (n > 2) {
        const index = res.indexOf('/') + 1;
        return `${res.slice(0, index)}(${res.slice(index)})`;
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn optimal_division(nums: Vec<i32>) -> String {
        let n = nums.len();
        match n {
            1 => nums[0].to_string(),
            2 => nums[0].to_string() + "/" + &nums[1].to_string(),
            _ => {
                let mut res = nums[0].to_string();
                res.push_str("/(");
                for i in 1..n {
                    res.push_str(&nums[i].to_string());
                    res.push('/');
                }
                res.pop();
                res.push(')');
                res
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

# [554. 砖墙](https://leetcode.cn/problems/brick-wall){#554}

{{< tabs "554" >}}

{{% tab "python" %}}
```python
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        cnt = Counter()
        for row in wall:
            s = 0
            for x in row[:-1]:
                s += x
                cnt[s] += 1
        return len(wall) - max(cnt.values(), default=0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (var row : wall) {
            int s = 0;
            for (int i = 0; i + 1 < row.size(); ++i) {
                s += row.get(i);
                cnt.merge(s, 1, Integer::sum);
            }
        }
        int mx = 0;
        for (var x : cnt.values()) {
            mx = Math.max(mx, x);
        }
        return wall.size() - mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (const auto& row : wall) {
            int s = 0;
            for (int i = 0; i + 1 < row.size(); ++i) {
                s += row[i];
                cnt[s]++;
            }
        }
        int mx = 0;
        for (const auto& [_, x] : cnt) {
            mx = max(mx, x);
        }
        return wall.size() - mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func leastBricks(wall [][]int) int {
	cnt := map[int]int{}
	for _, row := range wall {
		s := 0
		for _, x := range row[:len(row)-1] {
			s += x
			cnt[s]++
		}
	}
	mx := 0
	for _, x := range cnt {
		mx = max(mx, x)
	}
	return len(wall) - mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function leastBricks(wall: number[][]): number {
    const cnt: Map<number, number> = new Map();
    for (const row of wall) {
        let s = 0;
        for (let i = 0; i + 1 < row.length; ++i) {
            s += row[i];
            cnt.set(s, (cnt.get(s) || 0) + 1);
        }
    }
    const mx = Math.max(...cnt.values(), 0);
    return wall.length - mx;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} wall
 * @return {number}
 */
var leastBricks = function (wall) {
    const cnt = new Map();
    for (const row of wall) {
        let s = 0;
        for (let i = 0; i + 1 < row.length; ++i) {
            s += row[i];
            cnt.set(s, (cnt.get(s) || 0) + 1);
        }
    }
    const mx = Math.max(...cnt.values(), 0);
    return wall.length - mx;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你的面前有一堵矩形的、由 <code>n</code> 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和相等。</p>

<p>你现在要画一条 <strong>自顶向下 </strong>的、穿过 <strong>最少 </strong>砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。<strong>你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。</strong></p>

<p>给你一个二维数组 <code>wall</code> ，该数组包含这堵墙的相关信息。其中，<code>wall[i]</code> 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 <strong>穿过的砖块数量最少</strong> ，并且返回 <strong>穿过的砖块数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0554.Brick%20Wall/images/a.png" style="width: 400px; height: 384px;" />
<pre>
<strong>输入：</strong>wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>wall = [[1],[1],[1]]
<strong>输出：</strong>3
</pre>

&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == wall.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= wall[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sum(wall[i].length) &lt;= 2 * 10<sup>4</sup></code></li>
	<li>对于每一行 <code>i</code> ，<code>sum(wall[i])</code> 是相同的</li>
	<li><code>1 &lt;= wall[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

我们可以用一个哈希表 $\textit{cnt}$ 记录每一行除了最后一个砖块以外的前缀和，其中键为前缀和的值，值为该前缀和出现的次数。

遍历每一行，对于当前行的每一个砖块，我们将其加到当前的前缀和上，然后更新 $\textit{cnt}$。

最后我们遍历 $\textit{cnt}$，找出出现次数最多的前缀和，这就是穿过的砖块数量最少的情况。最后答案即为砖墙的行数减去穿过的砖块数量。

时间复杂度 $O(m \times n)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别是砖墙的行数和砖墙的砖块数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        cnt = Counter()
        for row in wall:
            s = 0
            for x in row[:-1]:
                s += x
                cnt[s] += 1
        return len(wall) - max(cnt.values(), default=0)
```

#### Java

```java
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (var row : wall) {
            int s = 0;
            for (int i = 0; i + 1 < row.size(); ++i) {
                s += row.get(i);
                cnt.merge(s, 1, Integer::sum);
            }
        }
        int mx = 0;
        for (var x : cnt.values()) {
            mx = Math.max(mx, x);
        }
        return wall.size() - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (const auto& row : wall) {
            int s = 0;
            for (int i = 0; i + 1 < row.size(); ++i) {
                s += row[i];
                cnt[s]++;
            }
        }
        int mx = 0;
        for (const auto& [_, x] : cnt) {
            mx = max(mx, x);
        }
        return wall.size() - mx;
    }
};
```

#### Go

```go
func leastBricks(wall [][]int) int {
	cnt := map[int]int{}
	for _, row := range wall {
		s := 0
		for _, x := range row[:len(row)-1] {
			s += x
			cnt[s]++
		}
	}
	mx := 0
	for _, x := range cnt {
		mx = max(mx, x)
	}
	return len(wall) - mx
}
```

#### TypeScript

```ts
function leastBricks(wall: number[][]): number {
    const cnt: Map<number, number> = new Map();
    for (const row of wall) {
        let s = 0;
        for (let i = 0; i + 1 < row.length; ++i) {
            s += row[i];
            cnt.set(s, (cnt.get(s) || 0) + 1);
        }
    }
    const mx = Math.max(...cnt.values(), 0);
    return wall.length - mx;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} wall
 * @return {number}
 */
var leastBricks = function (wall) {
    const cnt = new Map();
    for (const row of wall) {
        let s = 0;
        for (let i = 0; i + 1 < row.length; ++i) {
            s += row[i];
            cnt.set(s, (cnt.get(s) || 0) + 1);
        }
    }
    const mx = Math.max(...cnt.values(), 0);
    return wall.length - mx;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [555. 分割连接字符串 🔒](https://leetcode.cn/problems/split-concatenated-strings){#555}

{{< tabs "555" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitLoopedString(self, strs: List[str]) -> str:
        strs = [s[::-1] if s[::-1] > s else s for s in strs]
        ans = ''.join(strs)
        for i, s in enumerate(strs):
            t = ''.join(strs[i + 1 :]) + ''.join(strs[:i])
            for j in range(len(s)):
                a = s[j:]
                b = s[:j]
                ans = max(ans, a + t + b)
                ans = max(ans, b[::-1] + t + a[::-1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String splitLoopedString(String[] strs) {
        int n = strs.length;
        for (int i = 0; i < n; ++i) {
            String s = strs[i];
            String t = new StringBuilder(s).reverse().toString();
            if (s.compareTo(t) < 0) {
                strs[i] = t;
            }
        }
        String ans = "";
        for (int i = 0; i < n; ++i) {
            String s = strs[i];
            StringBuilder sb = new StringBuilder();
            for (int j = i + 1; j < n; ++j) {
                sb.append(strs[j]);
            }
            for (int j = 0; j < i; ++j) {
                sb.append(strs[j]);
            }
            String t = sb.toString();
            for (int j = 0; j < s.length(); ++j) {
                String a = s.substring(j);
                String b = s.substring(0, j);
                String cur = a + t + b;
                if (ans.compareTo(cur) < 0) {
                    ans = cur;
                }
                cur = new StringBuilder(b)
                          .reverse()
                          .append(t)
                          .append(new StringBuilder(a).reverse().toString())
                          .toString();
                if (ans.compareTo(cur) < 0) {
                    ans = cur;
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
    string splitLoopedString(vector<string>& strs) {
        for (auto& s : strs) {
            string t{s.rbegin(), s.rend()};
            s = max(s, t);
        }
        int n = strs.size();
        string ans = "";
        for (int i = 0; i < strs.size(); ++i) {
            auto& s = strs[i];
            string t;
            for (int j = i + 1; j < n; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < i; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < s.size(); ++j) {
                auto a = s.substr(j);
                auto b = s.substr(0, j);
                auto cur = a + t + b;
                if (ans < cur) {
                    ans = cur;
                }
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());
                cur = b + t + a;
                if (ans < cur) {
                    ans = cur;
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
func splitLoopedString(strs []string) (ans string) {
	for i, s := range strs {
		t := reverse(s)
		if s < t {
			strs[i] = t
		}
	}
	for i, s := range strs {
		sb := &strings.Builder{}
		for _, w := range strs[i+1:] {
			sb.WriteString(w)
		}
		for _, w := range strs[:i] {
			sb.WriteString(w)
		}
		t := sb.String()
		for j := 0; j < len(s); j++ {
			a, b := s[j:], s[0:j]
			cur := a + t + b
			if ans < cur {
				ans = cur
			}
			cur = reverse(b) + t + reverse(a)
			if ans < cur {
				ans = cur
			}
		}
	}
	return ans
}

func reverse(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串列表&nbsp;<code>strs</code>，你可以将这些字符串连接成一个循环字符串，对于每个字符串，你可以选择是否翻转它。在所有可能的循环字符串中，你需要分割循环字符串（这将使循环字符串变成一个常规的字符串），然后找到字典序最大的字符串。</p>

<p>具体来说，要找到字典序最大的字符串，你需要经历两个阶段：</p>

<ol>
	<li>将所有字符串连接成一个循环字符串，你可以选择是否翻转某些字符串，并按照给定的顺序连接它们。</li>
	<li>在循环字符串的某个位置分割它，这将使循环字符串从分割点变成一个常规的字符串。</li>
</ol>

<p>你的工作是在所有可能的常规字符串中找到字典序最大的一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> strs = ["abc","xyz"]
<strong>输出:</strong> "zyxcba"
<strong>解释:</strong> 你可以得到循环字符串 "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-"，其中 '-' 代表循环状态。 
答案字符串来自第四个循环字符串， 你可以从中间字符 'a' 分割开然后得到 "zyxcba"。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> strs = ["abc"]
<strong>输出:</strong> "cba"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 1000</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(strs[i].length) &lt;= 1000</code></li>
	<li><code>strs[i]</code>&nbsp;只包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先遍历字符串数组 `strs`，对于每个字符串 $s$，如果 $s$ 的反转字符串 $t$ 比 $s$ 大，那么我们就将 $s$ 替换为 $t$。

然后我们再枚举字符串数组 `strs` 的每个位置 $i$ 作为分割点，将字符串数组 `strs` 拆成两部分，分别为 $strs[i + 1:]$ 和 $strs[:i]$，然后将这两部分拼接起来，得到一个新的字符串 $t$。接下来，我们枚举当前字符串 $strs[i]$ 的每个位置 $j$，其后缀部分为 $a=strs[i][j:]$，前缀部分为 $b=strs[i][:j]$，那么我们可以将 $a$, $t$ 和 $b$ 拼接起来，得到一个新的字符串 $cur$，如果 $cur$ 比当前答案大，那么我们就更新答案。这是将 $strs[i]$ 翻转后的情况，我们还需要考虑 $strs[i]$ 不翻转的情况，即将 $a$, $t$ 和 $b$ 的顺序反过来拼接，得到一个新的字符串 $cur$，如果 $cur$ 比当前答案大，那么我们就更新答案。

最后，我们返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为字符串数组 `strs` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitLoopedString(self, strs: List[str]) -> str:
        strs = [s[::-1] if s[::-1] > s else s for s in strs]
        ans = ''.join(strs)
        for i, s in enumerate(strs):
            t = ''.join(strs[i + 1 :]) + ''.join(strs[:i])
            for j in range(len(s)):
                a = s[j:]
                b = s[:j]
                ans = max(ans, a + t + b)
                ans = max(ans, b[::-1] + t + a[::-1])
        return ans
```

#### Java

```java
class Solution {
    public String splitLoopedString(String[] strs) {
        int n = strs.length;
        for (int i = 0; i < n; ++i) {
            String s = strs[i];
            String t = new StringBuilder(s).reverse().toString();
            if (s.compareTo(t) < 0) {
                strs[i] = t;
            }
        }
        String ans = "";
        for (int i = 0; i < n; ++i) {
            String s = strs[i];
            StringBuilder sb = new StringBuilder();
            for (int j = i + 1; j < n; ++j) {
                sb.append(strs[j]);
            }
            for (int j = 0; j < i; ++j) {
                sb.append(strs[j]);
            }
            String t = sb.toString();
            for (int j = 0; j < s.length(); ++j) {
                String a = s.substring(j);
                String b = s.substring(0, j);
                String cur = a + t + b;
                if (ans.compareTo(cur) < 0) {
                    ans = cur;
                }
                cur = new StringBuilder(b)
                          .reverse()
                          .append(t)
                          .append(new StringBuilder(a).reverse().toString())
                          .toString();
                if (ans.compareTo(cur) < 0) {
                    ans = cur;
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
    string splitLoopedString(vector<string>& strs) {
        for (auto& s : strs) {
            string t{s.rbegin(), s.rend()};
            s = max(s, t);
        }
        int n = strs.size();
        string ans = "";
        for (int i = 0; i < strs.size(); ++i) {
            auto& s = strs[i];
            string t;
            for (int j = i + 1; j < n; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < i; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < s.size(); ++j) {
                auto a = s.substr(j);
                auto b = s.substr(0, j);
                auto cur = a + t + b;
                if (ans < cur) {
                    ans = cur;
                }
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());
                cur = b + t + a;
                if (ans < cur) {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func splitLoopedString(strs []string) (ans string) {
	for i, s := range strs {
		t := reverse(s)
		if s < t {
			strs[i] = t
		}
	}
	for i, s := range strs {
		sb := &strings.Builder{}
		for _, w := range strs[i+1:] {
			sb.WriteString(w)
		}
		for _, w := range strs[:i] {
			sb.WriteString(w)
		}
		t := sb.String()
		for j := 0; j < len(s); j++ {
			a, b := s[j:], s[0:j]
			cur := a + t + b
			if ans < cur {
				ans = cur
			}
			cur = reverse(b) + t + reverse(a)
			if ans < cur {
				ans = cur
			}
		}
	}
	return ans
}

func reverse(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [556. 下一个更大元素 III](https://leetcode.cn/problems/next-greater-element-iii){#556}

{{< tabs "556" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        cs = list(str(n))
        n = len(cs)
        i, j = n - 2, n - 1
        while i >= 0 and cs[i] >= cs[i + 1]:
            i -= 1
        if i < 0:
            return -1
        while cs[i] >= cs[j]:
            j -= 1
        cs[i], cs[j] = cs[j], cs[i]
        cs[i + 1 :] = cs[i + 1 :][::-1]
        ans = int(''.join(cs))
        return -1 if ans > 2**31 - 1 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nextGreaterElement(int n) {
        char[] cs = String.valueOf(n).toCharArray();
        n = cs.length;
        int i = n - 2, j = n - 1;
        for (; i >= 0 && cs[i] >= cs[i + 1]; --i)
            ;
        if (i < 0) {
            return -1;
        }
        for (; cs[i] >= cs[j]; --j)
            ;
        swap(cs, i, j);
        reverse(cs, i + 1, n - 1);
        long ans = Long.parseLong(String.valueOf(cs));
        return ans > Integer.MAX_VALUE ? -1 : (int) ans;
    }

    private void swap(char[] cs, int i, int j) {
        char t = cs[i];
        cs[i] = cs[j];
        cs[j] = t;
    }

    private void reverse(char[] cs, int i, int j) {
        for (; i < j; ++i, --j) {
            swap(cs, i, j);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        n = s.size();
        int i = n - 2, j = n - 1;
        for (; i >= 0 && s[i] >= s[i + 1]; --i)
            ;
        if (i < 0) return -1;
        for (; s[i] >= s[j]; --j)
            ;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long ans = stol(s);
        return ans > INT_MAX ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextGreaterElement(n int) int {
	s := []byte(strconv.Itoa(n))
	n = len(s)
	i, j := n-2, n-1
	for ; i >= 0 && s[i] >= s[i+1]; i-- {
	}
	if i < 0 {
		return -1
	}
	for ; j >= 0 && s[i] >= s[j]; j-- {
	}
	s[i], s[j] = s[j], s[i]
	for i, j = i+1, n-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	ans, _ := strconv.Atoi(string(s))
	if ans > math.MaxInt32 {
		return -1
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

<p>给你一个正整数 <code>n</code> ，请你找出符合条件的最小整数，其由重新排列 <code>n</code><strong> </strong>中存在的每位数字组成，并且其值大于 <code>n</code> 。如果不存在这样的正整数，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong> ，返回的整数应当是一个 <strong>32 位整数</strong> ，如果存在满足题意的答案，但不是 <strong>32 位整数</strong> ，同样返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 12
<strong>输出：</strong>21
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 21
<strong>输出：</strong>-1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        cs = list(str(n))
        n = len(cs)
        i, j = n - 2, n - 1
        while i >= 0 and cs[i] >= cs[i + 1]:
            i -= 1
        if i < 0:
            return -1
        while cs[i] >= cs[j]:
            j -= 1
        cs[i], cs[j] = cs[j], cs[i]
        cs[i + 1 :] = cs[i + 1 :][::-1]
        ans = int(''.join(cs))
        return -1 if ans > 2**31 - 1 else ans
```

#### Java

```java
class Solution {
    public int nextGreaterElement(int n) {
        char[] cs = String.valueOf(n).toCharArray();
        n = cs.length;
        int i = n - 2, j = n - 1;
        for (; i >= 0 && cs[i] >= cs[i + 1]; --i)
            ;
        if (i < 0) {
            return -1;
        }
        for (; cs[i] >= cs[j]; --j)
            ;
        swap(cs, i, j);
        reverse(cs, i + 1, n - 1);
        long ans = Long.parseLong(String.valueOf(cs));
        return ans > Integer.MAX_VALUE ? -1 : (int) ans;
    }

    private void swap(char[] cs, int i, int j) {
        char t = cs[i];
        cs[i] = cs[j];
        cs[j] = t;
    }

    private void reverse(char[] cs, int i, int j) {
        for (; i < j; ++i, --j) {
            swap(cs, i, j);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        n = s.size();
        int i = n - 2, j = n - 1;
        for (; i >= 0 && s[i] >= s[i + 1]; --i)
            ;
        if (i < 0) return -1;
        for (; s[i] >= s[j]; --j)
            ;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long ans = stol(s);
        return ans > INT_MAX ? -1 : ans;
    }
};
```

#### Go

```go
func nextGreaterElement(n int) int {
	s := []byte(strconv.Itoa(n))
	n = len(s)
	i, j := n-2, n-1
	for ; i >= 0 && s[i] >= s[i+1]; i-- {
	}
	if i < 0 {
		return -1
	}
	for ; j >= 0 && s[i] >= s[j]; j-- {
	}
	s[i], s[j] = s[j], s[i]
	for i, j = i+1, n-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	ans, _ := strconv.Atoi(string(s))
	if ans > math.MaxInt32 {
		return -1
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [557. 反转字符串中的单词 III](https://leetcode.cn/problems/reverse-words-in-a-string-iii){#557}

{{< tabs "557" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(t[::-1] for t in s.split())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        for (int i = 0; i < words.length; ++i) {
            words[i] = new StringBuilder(words[i]).reverse().toString();
        }
        return String.join(" ", words);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string t;
        string ans;
        while (ss >> t) {
            reverse(t.begin(), t.end());
            ans += t;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseWords(s string) string {
	words := strings.Fields(s)
	for i, w := range words {
		t := []byte(w)
		slices.Reverse(t)
		words[i] = string(t)
	}
	return strings.Join(words, " ")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reverseWords(s: string): string {
    return s
        .split(' ')
        .map(t => t.split('').reverse().join(''))
        .join(' ');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.split(' ')
            .map(|s| s.chars().rev().collect::<String>())
            .collect::<Vec<_>>()
            .join(" ")
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    return s
        .split(' ')
        .map(t => t.split('').reverse().join(''))
        .join(' ');
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $words = explode(' ', $s);
        foreach ($words as $i => $word) {
            $words[$i] = strrev($word);
        }
        return implode(' ', $words);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "Let's take LeetCode contest"
<strong>输出：</strong>"s'teL ekat edoCteeL tsetnoc"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong> s = "Mr Ding"
<strong>输出：</strong>"rM gniD"
</pre>

<p>&nbsp;</p>

<p><strong><strong><strong><strong>提示：</strong></strong></strong></strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;包含可打印的 <strong>ASCII</strong> 字符。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;不包含任何开头或结尾空格。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;里 <strong>至少</strong> 有一个词。</li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;中的所有单词都用一个空格隔开。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以将字符串 $\textit{s}$ 按照空格分割成单词数组 $\textit{words}$，然后将每个单词反转后再拼接成字符串。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{s}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(t[::-1] for t in s.split())
```

#### Java

```java
class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        for (int i = 0; i < words.length; ++i) {
            words[i] = new StringBuilder(words[i]).reverse().toString();
        }
        return String.join(" ", words);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string t;
        string ans;
        while (ss >> t) {
            reverse(t.begin(), t.end());
            ans += t;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
```

#### Go

```go
func reverseWords(s string) string {
	words := strings.Fields(s)
	for i, w := range words {
		t := []byte(w)
		slices.Reverse(t)
		words[i] = string(t)
	}
	return strings.Join(words, " ")
}
```

#### TypeScript

```ts
function reverseWords(s: string): string {
    return s
        .split(' ')
        .map(t => t.split('').reverse().join(''))
        .join(' ');
}
```

#### Rust

```rust
impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.split(' ')
            .map(|s| s.chars().rev().collect::<String>())
            .collect::<Vec<_>>()
            .join(" ")
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    return s
        .split(' ')
        .map(t => t.split('').reverse().join(''))
        .join(' ');
};
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $words = explode(' ', $s);
        foreach ($words as $i => $word) {
            $words[$i] = strrev($word);
        }
        return implode(' ', $words);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [558. 四叉树交集](https://leetcode.cn/problems/logical-or-of-two-binary-grids-represented-as-quad-trees){#558}

{{< tabs "558" >}}

{{% tab "python" %}}
```python
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def intersect(self, quadTree1: "Node", quadTree2: "Node") -> "Node":
        def dfs(t1, t2):
            if t1.isLeaf and t2.isLeaf:
                return Node(t1.val or t2.val, True)
            if t1.isLeaf:
                return t1 if t1.val else t2
            if t2.isLeaf:
                return t2 if t2.val else t1
            res = Node()
            res.topLeft = dfs(t1.topLeft, t2.topLeft)
            res.topRight = dfs(t1.topRight, t2.topRight)
            res.bottomLeft = dfs(t1.bottomLeft, t2.bottomLeft)
            res.bottomRight = dfs(t1.bottomRight, t2.bottomRight)
            isLeaf = (
                res.topLeft.isLeaf
                and res.topRight.isLeaf
                and res.bottomLeft.isLeaf
                and res.bottomRight.isLeaf
            )
            sameVal = (
                res.topLeft.val
                == res.topRight.val
                == res.bottomLeft.val
                == res.bottomRight.val
            )
            if isLeaf and sameVal:
                res = res.topLeft
            return res

        return dfs(quadTree1, quadTree2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/

class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        return dfs(quadTree1, quadTree2);
    }

    private Node dfs(Node t1, Node t2) {
        if (t1.isLeaf && t2.isLeaf) {
            return new Node(t1.val || t2.val, true);
        }
        if (t1.isLeaf) {
            return t1.val ? t1 : t2;
        }
        if (t2.isLeaf) {
            return t2.val ? t2 : t1;
        }
        Node res = new Node();
        res.topLeft = dfs(t1.topLeft, t2.topLeft);
        res.topRight = dfs(t1.topRight, t2.topRight);
        res.bottomLeft = dfs(t1.bottomLeft, t2.bottomLeft);
        res.bottomRight = dfs(t1.bottomRight, t2.bottomRight);
        boolean isLeaf = res.topLeft.isLeaf && res.topRight.isLeaf && res.bottomLeft.isLeaf
            && res.bottomRight.isLeaf;
        boolean sameVal = res.topLeft.val == res.topRight.val
            && res.topRight.val == res.bottomLeft.val && res.bottomLeft.val == res.bottomRight.val;
        if (isLeaf && sameVal) {
            res = res.topLeft;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return dfs(quadTree1, quadTree2);
    }

    Node* dfs(Node* t1, Node* t2) {
        if (t1->isLeaf && t2->isLeaf) return new Node(t1->val || t2->val, true);
        if (t1->isLeaf) return t1->val ? t1 : t2;
        if (t2->isLeaf) return t2->val ? t2 : t1;
        Node* res = new Node();
        res->topLeft = dfs(t1->topLeft, t2->topLeft);
        res->topRight = dfs(t1->topRight, t2->topRight);
        res->bottomLeft = dfs(t1->bottomLeft, t2->bottomLeft);
        res->bottomRight = dfs(t1->bottomRight, t2->bottomRight);
        bool isLeaf = res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf;
        bool sameVal = res->topLeft->val == res->topRight->val && res->topRight->val == res->bottomLeft->val && res->bottomLeft->val == res->bottomRight->val;
        if (isLeaf && sameVal) res = res->topLeft;
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a QuadTree node.
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

func intersect(quadTree1 *Node, quadTree2 *Node) *Node {
	var dfs func(*Node, *Node) *Node
	dfs = func(t1, t2 *Node) *Node {
		if t1.IsLeaf && t2.IsLeaf {
			return &Node{Val: t1.Val || t2.Val, IsLeaf: true}
		}
		if t1.IsLeaf {
			if t1.Val {
				return t1
			}
			return t2
		}
		if t2.IsLeaf {
			if t2.Val {
				return t2
			}
			return t1
		}
		res := &Node{}
		res.TopLeft = dfs(t1.TopLeft, t2.TopLeft)
		res.TopRight = dfs(t1.TopRight, t2.TopRight)
		res.BottomLeft = dfs(t1.BottomLeft, t2.BottomLeft)
		res.BottomRight = dfs(t1.BottomRight, t2.BottomRight)
		isLeaf := res.TopLeft.IsLeaf && res.TopRight.IsLeaf && res.BottomLeft.IsLeaf && res.BottomRight.IsLeaf
		sameVal := res.TopLeft.Val == res.TopRight.Val && res.TopRight.Val == res.BottomLeft.Val && res.BottomLeft.Val == res.BottomRight.Val
		if isLeaf && sameVal {
			res = res.TopLeft
		}
		return res
	}

	return dfs(quadTree1, quadTree2)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>二进制矩阵中的所有元素不是 <strong>0</strong> 就是 <strong>1 </strong>。</p>

<p>给你两个四叉树，<code>quadTree1</code> 和 <code>quadTree2</code>。其中 <code>quadTree1</code> 表示一个 <code>n * n</code> 二进制矩阵，而 <code>quadTree2</code> 表示另一个 <code>n * n</code> 二进制矩阵。</p>

<p>请你返回一个表示 <code>n * n</code> 二进制矩阵的四叉树，它是 <code>quadTree1</code> 和 <code>quadTree2</code> 所表示的两个二进制矩阵进行 <strong>按位逻辑或运算</strong> 的结果。</p>

<p>注意，当 <code>isLeaf</code> 为 <strong>False </strong>时，你可以把 <strong>True</strong> 或者 <strong>False</strong> 赋值给节点，两种值都会被判题机制 <strong>接受</strong> 。</p>

<p>四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：</p>

<ul>
	<li><code>val</code>：储存叶子结点所代表的区域的值。1 对应 <strong>True</strong>，0 对应 <strong>False</strong>；</li>
	<li><code>isLeaf</code>: 当这个节点是一个叶子结点时为 <strong>True</strong>，如果它有 4 个子节点则为 <strong>False</strong> 。</li>
</ul>

<pre>
class Node {
    public boolean val;
&nbsp; &nbsp; public boolean isLeaf;
&nbsp; &nbsp; public Node topLeft;
&nbsp; &nbsp; public Node topRight;
&nbsp; &nbsp; public Node bottomLeft;
&nbsp; &nbsp; public Node bottomRight;
}</pre>

<p>我们可以按以下步骤为二维区域构建四叉树：</p>

<ol>
	<li>如果当前网格的值相同（即，全为 <code>0</code> 或者全为 <code>1</code>），将 <code>isLeaf</code> 设为 True ，将 <code>val</code> 设为网格相应的值，并将四个子节点都设为 Null 然后停止。</li>
	<li>如果当前网格的值不同，将 <code>isLeaf</code> 设为 False， 将 <code>val</code> 设为任意值，然后如下图所示，将当前网格划分为四个子网格。</li>
	<li>使用适当的子网格递归每个子节点。</li>
</ol>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0558.Logical%20OR%20of%20Two%20Binary%20Grids%20Represented%20as%20Quad-Trees/images/new_top.png" style="height: 181px; width: 777px;" /></p>

<p>如果你想了解更多关于四叉树的内容，可以参考 <a href="https://baike.baidu.com/item/%E5%9B%9B%E5%8F%89%E6%A0%91/8557650">百科</a>。</p>

<p><strong>四叉树格式：</strong></p>

<p>输出为使用层序遍历后四叉树的序列化形式，其中 <code>null</code> 表示路径终止符，其下面不存在节点。</p>

<p>它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 <code>[isLeaf, val]</code> 。</p>

<p>如果 <code>isLeaf</code> 或者 <code>val</code> 的值为 True ，则表示它在列表&nbsp;<code>[isLeaf, val]</code> 中的值为 <strong>1</strong> ；如果 <code>isLeaf</code> 或者 <code>val</code> 的值为 False ，则表示值为 <strong>0 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0558.Logical%20OR%20of%20Two%20Binary%20Grids%20Represented%20as%20Quad-Trees/images/qt1.png" style="height: 196px; width: 550px;" /> <img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0558.Logical%20OR%20of%20Two%20Binary%20Grids%20Represented%20as%20Quad-Trees/images/qt2.png" style="height: 278px; width: 550px;" /></p>

<pre>
<strong>输入：</strong>quadTree1 = [[0,1],[1,1],[1,1],[1,0],[1,0]]
, quadTree2 = [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong>输出：</strong>[[0,0],[1,1],[1,1],[1,1],[1,0]]
<strong>解释：</strong>quadTree1 和 quadTree2 如上所示。由四叉树所表示的二进制矩阵也已经给出。
如果我们对这两个矩阵进行按位逻辑或运算，则可以得到下面的二进制矩阵，由一个作为结果的四叉树表示。
注意，我们展示的二进制矩阵仅仅是为了更好地说明题意，你无需构造二进制矩阵来获得结果四叉树。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0558.Logical%20OR%20of%20Two%20Binary%20Grids%20Represented%20as%20Quad-Trees/images/qtr.png" style="height: 222px; width: 777px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>quadTree1 = [[1,0]]
, quadTree2 = [[1,0]]
<strong>输出：</strong>[[1,0]]
<strong>解释：</strong>两个数所表示的矩阵大小都为 1*1，值全为 0 
结果矩阵大小为 1*1，值全为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>quadTree1</code> 和 <code>quadTree2</code> 都是符合题目要求的四叉树，每个都代表一个 <code>n * n</code> 的矩阵。</li>
	<li><code>n == 2<sup>x</sup></code>&nbsp;，其中 <code>0 &lt;= x &lt;= 9</code>.</li>
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
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def intersect(self, quadTree1: "Node", quadTree2: "Node") -> "Node":
        def dfs(t1, t2):
            if t1.isLeaf and t2.isLeaf:
                return Node(t1.val or t2.val, True)
            if t1.isLeaf:
                return t1 if t1.val else t2
            if t2.isLeaf:
                return t2 if t2.val else t1
            res = Node()
            res.topLeft = dfs(t1.topLeft, t2.topLeft)
            res.topRight = dfs(t1.topRight, t2.topRight)
            res.bottomLeft = dfs(t1.bottomLeft, t2.bottomLeft)
            res.bottomRight = dfs(t1.bottomRight, t2.bottomRight)
            isLeaf = (
                res.topLeft.isLeaf
                and res.topRight.isLeaf
                and res.bottomLeft.isLeaf
                and res.bottomRight.isLeaf
            )
            sameVal = (
                res.topLeft.val
                == res.topRight.val
                == res.bottomLeft.val
                == res.bottomRight.val
            )
            if isLeaf and sameVal:
                res = res.topLeft
            return res

        return dfs(quadTree1, quadTree2)
```

#### Java

```java
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/

class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        return dfs(quadTree1, quadTree2);
    }

    private Node dfs(Node t1, Node t2) {
        if (t1.isLeaf && t2.isLeaf) {
            return new Node(t1.val || t2.val, true);
        }
        if (t1.isLeaf) {
            return t1.val ? t1 : t2;
        }
        if (t2.isLeaf) {
            return t2.val ? t2 : t1;
        }
        Node res = new Node();
        res.topLeft = dfs(t1.topLeft, t2.topLeft);
        res.topRight = dfs(t1.topRight, t2.topRight);
        res.bottomLeft = dfs(t1.bottomLeft, t2.bottomLeft);
        res.bottomRight = dfs(t1.bottomRight, t2.bottomRight);
        boolean isLeaf = res.topLeft.isLeaf && res.topRight.isLeaf && res.bottomLeft.isLeaf
            && res.bottomRight.isLeaf;
        boolean sameVal = res.topLeft.val == res.topRight.val
            && res.topRight.val == res.bottomLeft.val && res.bottomLeft.val == res.bottomRight.val;
        if (isLeaf && sameVal) {
            res = res.topLeft;
        }
        return res;
    }
}
```

#### C++

```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return dfs(quadTree1, quadTree2);
    }

    Node* dfs(Node* t1, Node* t2) {
        if (t1->isLeaf && t2->isLeaf) return new Node(t1->val || t2->val, true);
        if (t1->isLeaf) return t1->val ? t1 : t2;
        if (t2->isLeaf) return t2->val ? t2 : t1;
        Node* res = new Node();
        res->topLeft = dfs(t1->topLeft, t2->topLeft);
        res->topRight = dfs(t1->topRight, t2->topRight);
        res->bottomLeft = dfs(t1->bottomLeft, t2->bottomLeft);
        res->bottomRight = dfs(t1->bottomRight, t2->bottomRight);
        bool isLeaf = res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf;
        bool sameVal = res->topLeft->val == res->topRight->val && res->topRight->val == res->bottomLeft->val && res->bottomLeft->val == res->bottomRight->val;
        if (isLeaf && sameVal) res = res->topLeft;
        return res;
    }
};
```

#### Go

```go
/**
 * Definition for a QuadTree node.
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

func intersect(quadTree1 *Node, quadTree2 *Node) *Node {
	var dfs func(*Node, *Node) *Node
	dfs = func(t1, t2 *Node) *Node {
		if t1.IsLeaf && t2.IsLeaf {
			return &Node{Val: t1.Val || t2.Val, IsLeaf: true}
		}
		if t1.IsLeaf {
			if t1.Val {
				return t1
			}
			return t2
		}
		if t2.IsLeaf {
			if t2.Val {
				return t2
			}
			return t1
		}
		res := &Node{}
		res.TopLeft = dfs(t1.TopLeft, t2.TopLeft)
		res.TopRight = dfs(t1.TopRight, t2.TopRight)
		res.BottomLeft = dfs(t1.BottomLeft, t2.BottomLeft)
		res.BottomRight = dfs(t1.BottomRight, t2.BottomRight)
		isLeaf := res.TopLeft.IsLeaf && res.TopRight.IsLeaf && res.BottomLeft.IsLeaf && res.BottomRight.IsLeaf
		sameVal := res.TopLeft.Val == res.TopRight.Val && res.TopRight.Val == res.BottomLeft.Val && res.BottomLeft.Val == res.BottomRight.Val
		if isLeaf && sameVal {
			res = res.TopLeft
		}
		return res
	}

	return dfs(quadTree1, quadTree2)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [559. N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree){#559}

{{< tabs "559" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: "Node") -> int:
        if root is None:
            return 0
        mx = 0
        for child in root.children:
            mx = max(mx, self.maxDepth(child))
        return 1 + mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        int mx = 0;
        for (Node child : root.children) {
            mx = Math.max(mx, maxDepth(child));
        }
        return 1 + mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int mx = 0;
        for (Node* child : root->children) {
            mx = max(mx, maxDepth(child));
        }
        return mx + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	mx := 0
	for _, child := range root.Children {
		mx = max(mx, maxDepth(child))
	}
	return 1 + mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     children: _Node[]
 *
 *     constructor(val?: number, children?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = (children===undefined ? [] : children)
 *     }
 * }
 */

function maxDepth(root: _Node | null): number {
    if (!root) {
        return 0;
    }
    return 1 + Math.max(...root.children.map(child => maxDepth(child)), 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 N 叉树，找到其最大深度。</p>

<p class="MachineTrans-lang-zh-CN">最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。</p>

<p class="MachineTrans-lang-zh-CN">N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。</p>

<p class="MachineTrans-lang-zh-CN"> </p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0559.Maximum%20Depth%20of%20N-ary%20Tree/images/narytreeexample.png" style="width: 100%; max-width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0559.Maximum%20Depth%20of%20N-ary%20Tree/images/sample_4_964.png" style="width: 296px; height: 241px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树的深度不会超过 <code>1000</code> 。</li>
	<li>树的节点数目位于 <code>[0, 10<sup>4</sup>]</code> 之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们首先判断 $\textit{root}$ 是否为空，若为空则返回 0。否则我们初始化一个变量 $\textit{mx}$ 用来记录子节点的最大深度，然后遍历 $\textit{root}$ 的所有子节点，递归调用 $\text{maxDepth}$ 函数，更新 $\textit{mx}$ 的值。最后返回 $\textit{mx} + 1$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点的数量。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: "Node") -> int:
        if root is None:
            return 0
        mx = 0
        for child in root.children:
            mx = max(mx, self.maxDepth(child))
        return 1 + mx
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        int mx = 0;
        for (Node child : root.children) {
            mx = Math.max(mx, maxDepth(child));
        }
        return 1 + mx;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int mx = 0;
        for (Node* child : root->children) {
            mx = max(mx, maxDepth(child));
        }
        return mx + 1;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	mx := 0
	for _, child := range root.Children {
		mx = max(mx, maxDepth(child))
	}
	return 1 + mx
}
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     children: _Node[]
 *
 *     constructor(val?: number, children?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = (children===undefined ? [] : children)
 *     }
 * }
 */

function maxDepth(root: _Node | null): number {
    if (!root) {
        return 0;
    }
    return 1 + Math.max(...root.children.map(child => maxDepth(child)), 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
