---
title: "1270_向公司 CEO 汇报工作的所有人 🔒"
date: 2025-10-08T18:37:06+08:00
weight: 8
tags: [交互, 分治, 动态规划, 哈希表, 多线程, 字符串, 广度优先搜索, 数学, 数据库, 数组, 树, 模拟, 深度优先搜索, 矩阵]
---

{{< markmap >}}
### [1270_向公司 CEO 汇报工作的所有人 🔒](#1270)
#### [数据库](#1270)
### [1271_十六进制魔术数字 🔒](#1271)
#### [数学](#1271)
#### [字符串](#1271)
### [1272_删除区间 🔒](#1272)
#### [数组](#1272)
### [1273_删除树节点 🔒](#1273)
#### [树](#1273)
#### [深度优先搜索](#1273)
#### [广度优先搜索](#1273)
#### [数组](#1273)
### [1274_矩形内船只的数目 🔒](#1274)
#### [数组](#1274)
#### [分治](#1274)
#### [交互](#1274)
### [1275_找出井字棋的获胜者](#1275)
#### [数组](#1275)
#### [哈希表](#1275)
#### [矩阵](#1275)
#### [模拟](#1275)
### [1276_不浪费原料的汉堡制作方案](#1276)
#### [数学](#1276)
### [1277_统计全为 1 的正方形子矩阵](#1277)
#### [数组](#1277)
#### [动态规划](#1277)
#### [矩阵](#1277)
### [1278_分割回文串 III](#1278)
#### [字符串](#1278)
#### [动态规划](#1278)
### [1279_红绿灯路口 🔒](#1279)
#### [多线程](#1279)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1270_向公司 CEO 汇报工作的所有人 🔒
___
#### 数据库
---
### 1271_十六进制魔术数字 🔒
___
#### 数学
___
#### 字符串
---
### 1272_删除区间 🔒
___
#### 数组
---
### 1273_删除树节点 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
---
### 1274_矩形内船只的数目 🔒
___
#### 数组
___
#### 分治
___
#### 交互
---
### 1275_找出井字棋的获胜者
___
#### 数组
___
#### 哈希表
___
#### 矩阵
___
#### 模拟
---
### 1276_不浪费原料的汉堡制作方案
___
#### 数学
---
### 1277_统计全为 1 的正方形子矩阵
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1278_分割回文串 III
___
#### 字符串
___
#### 动态规划
---
### 1279_红绿灯路口 🔒
___
#### 多线程
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 交互 | 分治 | 动态规划 |
| 哈希表 | 多线程 | 字符串 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 |  |

# [1270. 向公司 CEO 汇报工作的所有人 🔒](https://leetcode.cn/problems/all-people-report-to-the-given-manager){#1270}

{{< tabs "1270" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT e1.employee_id
FROM
    Employees AS e1
    JOIN Employees AS e2 ON e1.manager_id = e2.employee_id
    JOIN Employees AS e3 ON e2.manager_id = e3.employee_id
WHERE e1.employee_id != 1 AND e3.manager_id = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>员工表：<code>Employees</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| employee_id   | int     |
| employee_name | varchar |
| manager_id    | int     |
+---------------+---------+
employee_id 是这个表具有唯一值的列。
这个表中每一行中，employee_id 表示职工的 ID，employee_name 表示职工的名字，manager_id 表示该职工汇报工作的直线经理。
这个公司 CEO 是 employee_id = 1 的人。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出所有直接或间接向公司 CEO 汇报工作的职工的 <code>employee_id</code> 。</p>

<p>由于公司规模较小，经理之间的间接关系 <strong>不超过 3 个经理</strong> 。</p>

<p>可以以 <strong>任何顺序</strong> 返回无重复项的结果。</p>

<p>返回结果示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
<code>Employees </code>table:
+-------------+---------------+------------+
| employee_id | employee_name | manager_id |
+-------------+---------------+------------+
| 1           | Boss          | 1          |
| 3           | Alice         | 3          |
| 2           | Bob           | 1          |
| 4           | Daniel        | 2          |
| 7           | Luis          | 4          |
| 8           | Jhon          | 3          |
| 9           | Angela        | 8          |
| 77          | Robert        | 1          |
+-------------+---------------+------------+
<strong>输出：</strong>
+-------------+
| employee_id |
+-------------+
| 2           |
| 77          |
| 4           |
| 7           |
+-------------+
<strong>解释：</strong>
公司 CEO 的 employee_id 是 1.
employee_id 是 2 和 77 的职员直接汇报给公司 CEO。
employee_id 是 4 的职员间接汇报给公司 CEO 4 --&gt; 2 --&gt; 1 。
employee_id 是 7 的职员间接汇报给公司 CEO 7 --&gt; 4 --&gt; 2 --&gt; 1 。
employee_id 是 3, 8 ，9 的职员不会直接或间接的汇报给公司 CEO。 
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次连接

我们可以通过两次连接来找到所有直接或间接向公司 CEO 汇报工作的职工的 `employee_id`。

具体地，我们首先通过一次连接，找到每个 `manager_id` 对应的上级经理的 `manager_id`，然后再通过一次连接，找到更上一级经理的 `manager_id`，最后，如果更上一级的 `manager_id` 为 $1$，且员工的 `employee_id` 不为 $1$，则说明该员工直接或间接向公司 CEO 汇报工作。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT e1.employee_id
FROM
    Employees AS e1
    JOIN Employees AS e2 ON e1.manager_id = e2.employee_id
    JOIN Employees AS e3 ON e2.manager_id = e3.employee_id
WHERE e1.employee_id != 1 AND e3.manager_id = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1271. 十六进制魔术数字 🔒](https://leetcode.cn/problems/hexspeak){#1271}

{{< tabs "1271" >}}

{{% tab "python" %}}
```python
class Solution:
    def toHexspeak(self, num: str) -> str:
        s = set('ABCDEFIO')
        t = hex(int(num))[2:].upper().replace('0', 'O').replace('1', 'I')
        return t if all(c in s for c in t) else 'ERROR'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final Set<Character> S = Set.of('A', 'B', 'C', 'D', 'E', 'F', 'I', 'O');

    public String toHexspeak(String num) {
        String t
            = Long.toHexString(Long.valueOf(num)).toUpperCase().replace("0", "O").replace("1", "I");
        for (char c : t.toCharArray()) {
            if (!S.contains(c)) {
                return "ERROR";
            }
        }
        return t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string toHexspeak(string num) {
        stringstream ss;
        ss << hex << stol(num);
        string t = ss.str();
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] >= '2' && t[i] <= '9') return "ERROR";
            if (t[i] == '0')
                t[i] = 'O';
            else if (t[i] == '1')
                t[i] = 'I';
            else
                t[i] = t[i] - 32;
        }
        return t;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func toHexspeak(num string) string {
	x, _ := strconv.Atoi(num)
	t := strings.ToUpper(fmt.Sprintf("%x", x))
	t = strings.ReplaceAll(t, "0", "O")
	t = strings.ReplaceAll(t, "1", "I")
	for _, c := range t {
		if c >= '2' && c <= '9' {
			return "ERROR"
		}
	}
	return t
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个十进制数字，请按照此规则将它变成「十六进制魔术数字」：首先将它变成字母大写的十六进制字符串，然后将所有的数字&nbsp;<code>0</code> 变成字母&nbsp;<code>O</code> ，将数字&nbsp;<code>1</code> &nbsp;变成字母&nbsp;<code>I</code> 。</p>

<p>如果一个数字在转换后只包含&nbsp;<code>{&quot;A&quot;, &quot;B&quot;, &quot;C&quot;, &quot;D&quot;, &quot;E&quot;, &quot;F&quot;, &quot;I&quot;, &quot;O&quot;}</code>&nbsp;，那么我们就认为这个转换是有效的。</p>

<p>给你一个字符串&nbsp;<code>num</code> ，它表示一个十进制数 <code>N</code>，如果它的十六进制魔术数字转换是有效的，请返回转换后的结果，否则返回&nbsp;<code>&quot;ERROR&quot;</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = &quot;257&quot;
<strong>输出：</strong>&quot;IOI&quot;
<strong>解释：</strong>257 的十六进制表示是 101 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = &quot;3&quot;
<strong>输出：</strong>&quot;ERROR&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 10^12</code></li>
	<li>给定字符串不会有前导 0 。</li>
	<li>结果中的所有字母都应该是大写字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

将数字转换为十六进制字符串，然后遍历字符串，将数字 $0$ 转换为字母 $O$，将数字 $1$ 转换为字母 $I$，最后判断转换后的字符串是否合法。

时间复杂度 $O(\log n)$，其中 $n$ 为 $num$ 所表示的十进制数字的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def toHexspeak(self, num: str) -> str:
        s = set('ABCDEFIO')
        t = hex(int(num))[2:].upper().replace('0', 'O').replace('1', 'I')
        return t if all(c in s for c in t) else 'ERROR'
```

#### Java

```java
class Solution {
    private static final Set<Character> S = Set.of('A', 'B', 'C', 'D', 'E', 'F', 'I', 'O');

    public String toHexspeak(String num) {
        String t
            = Long.toHexString(Long.valueOf(num)).toUpperCase().replace("0", "O").replace("1", "I");
        for (char c : t.toCharArray()) {
            if (!S.contains(c)) {
                return "ERROR";
            }
        }
        return t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string toHexspeak(string num) {
        stringstream ss;
        ss << hex << stol(num);
        string t = ss.str();
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] >= '2' && t[i] <= '9') return "ERROR";
            if (t[i] == '0')
                t[i] = 'O';
            else if (t[i] == '1')
                t[i] = 'I';
            else
                t[i] = t[i] - 32;
        }
        return t;
    }
};
```

#### Go

```go
func toHexspeak(num string) string {
	x, _ := strconv.Atoi(num)
	t := strings.ToUpper(fmt.Sprintf("%x", x))
	t = strings.ReplaceAll(t, "0", "O")
	t = strings.ReplaceAll(t, "1", "I")
	for _, c := range t {
		if c >= '2' && c <= '9' {
			return "ERROR"
		}
	}
	return t
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1272. 删除区间 🔒](https://leetcode.cn/problems/remove-interval){#1272}

{{< tabs "1272" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeInterval(
        self, intervals: List[List[int]], toBeRemoved: List[int]
    ) -> List[List[int]]:
        x, y = toBeRemoved
        ans = []
        for a, b in intervals:
            if a >= y or b <= x:
                ans.append([a, b])
            else:
                if a < x:
                    ans.append([a, x])
                if b > y:
                    ans.append([y, b])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        int x = toBeRemoved[0], y = toBeRemoved[1];
        List<List<Integer>> ans = new ArrayList<>();
        for (var e : intervals) {
            int a = e[0], b = e[1];
            if (a >= y || b <= x) {
                ans.add(Arrays.asList(a, b));
            } else {
                if (a < x) {
                    ans.add(Arrays.asList(a, x));
                }
                if (b > y) {
                    ans.add(Arrays.asList(y, b));
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int x = toBeRemoved[0], y = toBeRemoved[1];
        vector<vector<int>> ans;
        for (auto& e : intervals) {
            int a = e[0], b = e[1];
            if (a >= y || b <= x) {
                ans.push_back(e);
            } else {
                if (a < x) {
                    ans.push_back({a, x});
                }
                if (b > y) {
                    ans.push_back({y, b});
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
func removeInterval(intervals [][]int, toBeRemoved []int) (ans [][]int) {
	x, y := toBeRemoved[0], toBeRemoved[1]
	for _, e := range intervals {
		a, b := e[0], e[1]
		if a >= y || b <= x {
			ans = append(ans, e)
		} else {
			if a < x {
				ans = append(ans, []int{a, x})
			}
			if b > y {
				ans = append(ans, []int{y, b})
			}
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实数集合可以表示为若干不相交区间的并集，其中每个区间的形式为 <code>[a, b)</code>（左闭右开），表示满足&nbsp;<code>a &lt;= x &lt; b</code> 的所有实数&nbsp; <code>x</code>&nbsp;的集合。如果某个区间&nbsp;<code>[a, b)</code> 中包含实数 <code>x</code> ，则称实数 <code>x</code> 在集合中。</p>

<p>给你一个 <strong>有序的</strong> 不相交区间列表 <code>intervals</code>&nbsp;。<code>intervals</code> 表示一个实数集合，其中每一项 <code>intervals[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 都表示一个区间 <code>[a<sub>i</sub>, b<sub>i</sub>)</code> 。再给你一个要删除的区间 <code>toBeRemoved</code> 。</p>

<p>返回 <em>一组实数，该实数表示<code>intervals</code> 中&nbsp;<strong>删除</strong>&nbsp;了 <code>toBeRemoved</code> 的部分</em>&nbsp;。<em>换句话说，返回实数集合，并满足集合中的每个实数 <code>x</code> 都在&nbsp;<code>intervals</code> 中，但不在 <code>toBeRemoved</code> 中。你的答案应该是一个如上所述的 <strong>有序的</strong> 不相连的间隔列表&nbsp;。</em></p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1272.Remove%20Interval/images/removeintervalex1.png" />
<pre>
<strong>输入：</strong>intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
<strong>输出：</strong>[[0,1],[6,7]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1272.Remove%20Interval/images/removeintervalex2.png" />
<pre>
<strong>输入：</strong>intervals = [[0,5]], toBeRemoved = [2,3]
<strong>输出：</strong>[[0,2],[3,5]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
<strong>输出：</strong>[[-5,-4],[-3,-2],[4,5],[8,9]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= a<sub>i</sub> &lt; b<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

我们记要删除的区间为 $[x, y)$，遍历区间列表，对于每个区间 $[a, b)$，有以下三种情况：

-   $a \geq y$ 或 $b \leq x$，表示该区间与要删除的区间没有交集，直接将该区间加入答案；
-   $a \lt x$, $b \gt y$，表示该区间与要删除的区间有交集，将该区间分成两个区间加入答案；
-   $a \geq x$, $b \leq y$，表示该区间被要删除的区间完全覆盖，不加入答案。

时间复杂度 $O(n)$，其中 $n$ 为区间列表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeInterval(
        self, intervals: List[List[int]], toBeRemoved: List[int]
    ) -> List[List[int]]:
        x, y = toBeRemoved
        ans = []
        for a, b in intervals:
            if a >= y or b <= x:
                ans.append([a, b])
            else:
                if a < x:
                    ans.append([a, x])
                if b > y:
                    ans.append([y, b])
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        int x = toBeRemoved[0], y = toBeRemoved[1];
        List<List<Integer>> ans = new ArrayList<>();
        for (var e : intervals) {
            int a = e[0], b = e[1];
            if (a >= y || b <= x) {
                ans.add(Arrays.asList(a, b));
            } else {
                if (a < x) {
                    ans.add(Arrays.asList(a, x));
                }
                if (b > y) {
                    ans.add(Arrays.asList(y, b));
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int x = toBeRemoved[0], y = toBeRemoved[1];
        vector<vector<int>> ans;
        for (auto& e : intervals) {
            int a = e[0], b = e[1];
            if (a >= y || b <= x) {
                ans.push_back(e);
            } else {
                if (a < x) {
                    ans.push_back({a, x});
                }
                if (b > y) {
                    ans.push_back({y, b});
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeInterval(intervals [][]int, toBeRemoved []int) (ans [][]int) {
	x, y := toBeRemoved[0], toBeRemoved[1]
	for _, e := range intervals {
		a, b := e[0], e[1]
		if a >= y || b <= x {
			ans = append(ans, e)
		} else {
			if a < x {
				ans = append(ans, []int{a, x})
			}
			if b > y {
				ans = append(ans, []int{y, b})
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1273. 删除树节点 🔒](https://leetcode.cn/problems/delete-tree-nodes){#1273}

{{< tabs "1273" >}}

{{% tab "python" %}}
```python
class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        def dfs(i):
            s, m = value[i], 1
            for j in g[i]:
                t, n = dfs(j)
                s += t
                m += n
            if s == 0:
                m = 0
            return (s, m)

        g = defaultdict(list)
        for i in range(1, nodes):
            g[parent[i]].append(i)
        return dfs(0)[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] value;

    public int deleteTreeNodes(int nodes, int[] parent, int[] value) {
        g = new List[nodes];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < nodes; ++i) {
            g[parent[i]].add(i);
        }
        this.value = value;
        return dfs(0)[1];
    }

    private int[] dfs(int i) {
        int[] res = new int[] {value[i], 1};
        for (int j : g[i]) {
            int[] t = dfs(j);
            res[0] += t[0];
            res[1] += t[1];
        }
        if (res[0] == 0) {
            res[1] = 0;
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
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> g(nodes);
        for (int i = 1; i < nodes; ++i) {
            g[parent[i]].emplace_back(i);
        }
        function<pair<int, int>(int)> dfs = [&](int i) -> pair<int, int> {
            int s = value[i], m = 1;
            for (int j : g[i]) {
                auto [t, n] = dfs(j);
                s += t;
                m += n;
            }
            if (s == 0) {
                m = 0;
            }
            return pair<int, int>{s, m};
        };
        return dfs(0).second;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func deleteTreeNodes(nodes int, parent []int, value []int) int {
	g := make([][]int, nodes)
	for i := 1; i < nodes; i++ {
		g[parent[i]] = append(g[parent[i]], i)
	}
	type pair struct{ s, n int }
	var dfs func(int) pair
	dfs = func(i int) pair {
		s, m := value[i], 1
		for _, j := range g[i] {
			t := dfs(j)
			s += t.s
			m += t.n
		}
		if s == 0 {
			m = 0
		}
		return pair{s, m}
	}
	return dfs(0).n
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵以节点 0 为根节点的树，定义如下：</p>

<ul>
	<li>节点的总数为&nbsp;<code>nodes</code>&nbsp;个；</li>
	<li>第&nbsp;<code>i</code> 个节点的值为&nbsp;<code>value[i]</code>&nbsp;；</li>
	<li>第&nbsp;<code>i</code> 个节点的父节点是&nbsp;<code>parent[i]</code>&nbsp;。</li>
</ul>

<p>请你删除节点值之和为 0 的每一棵子树。</p>

<p>在完成所有删除之后，返回树中剩余节点的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1273.Delete%20Tree%20Nodes/images/1421_sample_1.png" style="height: 347px; width: 403px;"></p>

<pre><strong>输入：</strong>nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-2]
<strong>输出：</strong>6
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nodes = 5, parent = [-1,0,1,0,0], value = [-672,441,18,728,378]
<strong>输出：</strong>5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nodes = 5, parent = [-1,0,0,1,1], value = [-686,-842,616,-739,-746]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nodes &lt;= 10^4</code></li>
	<li><code>parent.length == nodes</code></li>
	<li><code>0 &lt;= parent[i] &lt;= nodes - 1</code></li>
	<li><code>parent[0] == -1</code>&nbsp;表示节点 <code>0</code> 是树的根。</li>
	<li><code>value.length == nodes</code></li>
	<li><code>-10^5 &lt;= value[i] &lt;= 10^5</code></li>
	<li>题目输入数据 <strong>保证</strong> 是一棵 <strong>有效的树</strong> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先将树转换成图 $g$，其中 $g[i]$ 表示节点 $i$ 的所有子节点。

然后我们设计一个函数 $dfs(i)$，表示以节点 $i$ 为根的子树的节点数目和权值之和。那么答案就是 $dfs(0)[1]$。

在这个函数中，我们递归地计算出以每个子节点 $j$ 为根的子树的节点数目和权值之和，然后将这些值进行累加，如果累加后的值为零，那么我们就将这个子树的节点数目置为零。最后我们返回以节点 $i$ 为根的子树的节点数目和权值之和。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树的节点数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        def dfs(i):
            s, m = value[i], 1
            for j in g[i]:
                t, n = dfs(j)
                s += t
                m += n
            if s == 0:
                m = 0
            return (s, m)

        g = defaultdict(list)
        for i in range(1, nodes):
            g[parent[i]].append(i)
        return dfs(0)[1]
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] value;

    public int deleteTreeNodes(int nodes, int[] parent, int[] value) {
        g = new List[nodes];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < nodes; ++i) {
            g[parent[i]].add(i);
        }
        this.value = value;
        return dfs(0)[1];
    }

    private int[] dfs(int i) {
        int[] res = new int[] {value[i], 1};
        for (int j : g[i]) {
            int[] t = dfs(j);
            res[0] += t[0];
            res[1] += t[1];
        }
        if (res[0] == 0) {
            res[1] = 0;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> g(nodes);
        for (int i = 1; i < nodes; ++i) {
            g[parent[i]].emplace_back(i);
        }
        function<pair<int, int>(int)> dfs = [&](int i) -> pair<int, int> {
            int s = value[i], m = 1;
            for (int j : g[i]) {
                auto [t, n] = dfs(j);
                s += t;
                m += n;
            }
            if (s == 0) {
                m = 0;
            }
            return pair<int, int>{s, m};
        };
        return dfs(0).second;
    }
};
```

#### Go

```go
func deleteTreeNodes(nodes int, parent []int, value []int) int {
	g := make([][]int, nodes)
	for i := 1; i < nodes; i++ {
		g[parent[i]] = append(g[parent[i]], i)
	}
	type pair struct{ s, n int }
	var dfs func(int) pair
	dfs = func(i int) pair {
		s, m := value[i], 1
		for _, j := range g[i] {
			t := dfs(j)
			s += t.s
			m += t.n
		}
		if s == 0 {
			m = 0
		}
		return pair{s, m}
	}
	return dfs(0).n
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1274. 矩形内船只的数目 🔒](https://leetcode.cn/problems/number-of-ships-in-a-rectangle){#1274}

{{< tabs "1274" >}}

{{% tab "python" %}}
```python
# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Sea:
#    def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#
# class Point:
# 	def __init__(self, x: int, y: int):
# 		self.x = x
# 		self.y = y


class Solution:
    def countShips(self, sea: "Sea", topRight: "Point", bottomLeft: "Point") -> int:
        def dfs(topRight, bottomLeft):
            x1, y1 = bottomLeft.x, bottomLeft.y
            x2, y2 = topRight.x, topRight.y
            if x1 > x2 or y1 > y2:
                return 0
            if not sea.hasShips(topRight, bottomLeft):
                return 0
            if x1 == x2 and y1 == y2:
                return 1
            midx = (x1 + x2) >> 1
            midy = (y1 + y2) >> 1
            a = dfs(topRight, Point(midx + 1, midy + 1))
            b = dfs(Point(midx, y2), Point(x1, midy + 1))
            c = dfs(Point(midx, midy), bottomLeft)
            d = dfs(Point(x2, midy), Point(midx + 1, y1))
            return a + b + c + d

        return dfs(topRight, bottomLeft)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *     public boolean hasShips(int[] topRight, int[] bottomLeft);
 * }
 */

class Solution {
    public int countShips(Sea sea, int[] topRight, int[] bottomLeft) {
        int x1 = bottomLeft[0], y1 = bottomLeft[1];
        int x2 = topRight[0], y2 = topRight[1];
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return 1;
        }
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        int a = countShips(sea, topRight, new int[] {midx + 1, midy + 1});
        int b = countShips(sea, new int[] {midx, y2}, new int[] {x1, midy + 1});
        int c = countShips(sea, new int[] {midx, midy}, bottomLeft);
        int d = countShips(sea, new int[] {x2, midy}, new int[] {midx + 1, y1});
        return a + b + c + d;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = bottomLeft[0], y1 = bottomLeft[1];
        int x2 = topRight[0], y2 = topRight[1];
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return 1;
        }
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        int a = countShips(sea, topRight, {midx + 1, midy + 1});
        int b = countShips(sea, {midx, y2}, {x1, midy + 1});
        int c = countShips(sea, {midx, midy}, bottomLeft);
        int d = countShips(sea, {x2, midy}, {midx + 1, y1});
        return a + b + c + d;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * type Sea struct {
 *     func hasShips(topRight, bottomLeft []int) bool {}
 * }
 */

func countShips(sea Sea, topRight, bottomLeft []int) int {
	x1, y1 := bottomLeft[0], bottomLeft[1]
	x2, y2 := topRight[0], topRight[1]
	if x1 > x2 || y1 > y2 {
		return 0
	}
	if !sea.hasShips(topRight, bottomLeft) {
		return 0
	}
	if x1 == x2 && y1 == y2 {
		return 1
	}
	midx := (x1 + x2) >> 1
	midy := (y1 + y2) >> 1
	a := countShips(sea, topRight, []int{midx + 1, midy + 1})
	b := countShips(sea, []int{midx, y2}, []int{x1, midy + 1})
	c := countShips(sea, []int{midx, midy}, bottomLeft)
	d := countShips(sea, []int{x2, midy}, []int{midx + 1, y1})
	return a + b + c + d
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *      hasShips(topRight: number[], bottomLeft: number[]): boolean {}
 * }
 */

function countShips(sea: Sea, topRight: number[], bottomLeft: number[]): number {
    const [x1, y1] = bottomLeft;
    const [x2, y2] = topRight;
    if (x1 > x2 || y1 > y2 || !sea.hasShips(topRight, bottomLeft)) {
        return 0;
    }
    if (x1 === x2 && y1 === y2) {
        return 1;
    }
    const midx = (x1 + x2) >> 1;
    const midy = (y1 + y2) >> 1;
    const a = countShips(sea, topRight, [midx + 1, midy + 1]);
    const b = countShips(sea, [midx, y2], [x1, midy + 1]);
    const c = countShips(sea, [midx, midy], bottomLeft);
    const d = countShips(sea, [x2, midy], [midx + 1, y1]);
    return a + b + c + d;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><em>(此题是 <strong>交互式问题&nbsp;</strong>)</em></p>

<p>在用笛卡尔坐标系表示的二维海平面上，有一些船。每一艘船都在一个整数点上，且每一个整数点最多只有 1 艘船。</p>

<p>有一个函数&nbsp;<code>Sea.hasShips(topRight, bottomLeft)</code>&nbsp;，输入参数为右上角和左下角两个点的坐标，当且仅当这两个点所表示的矩形区域（包含边界）内至少有一艘船时，这个函数才返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code> 。</p>

<p>给你矩形的右上角&nbsp;<code>topRight</code> 和左下角&nbsp;<code>bottomLeft</code> 的坐标，请你返回此矩形内船只的数目。题目保证矩形内&nbsp;<strong>至多只有 10 艘船</strong>。</p>

<p>调用函数&nbsp;<code>hasShips</code>&nbsp;<strong>超过400次&nbsp;</strong>的提交将被判为&nbsp;<em>错误答案（Wrong Answer）</em>&nbsp;。同时，任何尝试绕过评测系统的行为都将被取消比赛资格。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1274.Number%20of%20Ships%20in%20a%20Rectangle/images/1445_example_1.png" style="height: 500px; width: 496px;" /></p>

<pre>
<strong>输入：</strong>
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
<strong>输出：</strong>3
<strong>解释：</strong>在 [0,0] 到 [4,4] 的范围内总共有 3 艘船。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>ans = [[1,1],[2,2],[3,3]], topRight = [1000,1000], bottomLeft = [0,0]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>ships</code>&nbsp;数组只用于评测系统内部初始化。你必须“蒙着眼睛”解决这个问题。你无法得知&nbsp;<code>ships</code>&nbsp;的信息，所以只能通过调用&nbsp;<code>hasShips</code>&nbsp;接口来求解。</li>
	<li><code>0 &lt;=&nbsp;bottomLeft[0]&nbsp;&lt;= topRight[0]&nbsp;&lt;= 1000</code></li>
	<li><code>0 &lt;=&nbsp;bottomLeft[1]&nbsp;&lt;= topRight[1]&nbsp;&lt;= 1000</code></li>
	<li><code>topRight != bottomLeft</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 + 分治

由于矩形内最多只有 $10$ 艘船，所以我们可以将矩形划分为四个子矩形，分别求出每个子矩形内船只的数目 🔒，然后将四个子矩形内船只的数目 🔒 相加即可。如果一个子矩形内没有船只，那么就不需要再继续划分了。

时间复杂度 $O(C \times \log \max(m, n))$，空间复杂度 $O(\log \max(m, n))$。其中 $C$ 为船只的数目，而 $m$ 和 $n$ 分别为矩形的长和宽。

<!-- tabs:start -->

#### Python3

```python
# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Sea:
#    def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#
# class Point:
# 	def __init__(self, x: int, y: int):
# 		self.x = x
# 		self.y = y


class Solution:
    def countShips(self, sea: "Sea", topRight: "Point", bottomLeft: "Point") -> int:
        def dfs(topRight, bottomLeft):
            x1, y1 = bottomLeft.x, bottomLeft.y
            x2, y2 = topRight.x, topRight.y
            if x1 > x2 or y1 > y2:
                return 0
            if not sea.hasShips(topRight, bottomLeft):
                return 0
            if x1 == x2 and y1 == y2:
                return 1
            midx = (x1 + x2) >> 1
            midy = (y1 + y2) >> 1
            a = dfs(topRight, Point(midx + 1, midy + 1))
            b = dfs(Point(midx, y2), Point(x1, midy + 1))
            c = dfs(Point(midx, midy), bottomLeft)
            d = dfs(Point(x2, midy), Point(midx + 1, y1))
            return a + b + c + d

        return dfs(topRight, bottomLeft)
```

#### Java

```java
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *     public boolean hasShips(int[] topRight, int[] bottomLeft);
 * }
 */

class Solution {
    public int countShips(Sea sea, int[] topRight, int[] bottomLeft) {
        int x1 = bottomLeft[0], y1 = bottomLeft[1];
        int x2 = topRight[0], y2 = topRight[1];
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return 1;
        }
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        int a = countShips(sea, topRight, new int[] {midx + 1, midy + 1});
        int b = countShips(sea, new int[] {midx, y2}, new int[] {x1, midy + 1});
        int c = countShips(sea, new int[] {midx, midy}, bottomLeft);
        int d = countShips(sea, new int[] {x2, midy}, new int[] {midx + 1, y1});
        return a + b + c + d;
    }
}
```

#### C++

```cpp
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = bottomLeft[0], y1 = bottomLeft[1];
        int x2 = topRight[0], y2 = topRight[1];
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (x1 == x2 && y1 == y2) {
            return 1;
        }
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        int a = countShips(sea, topRight, {midx + 1, midy + 1});
        int b = countShips(sea, {midx, y2}, {x1, midy + 1});
        int c = countShips(sea, {midx, midy}, bottomLeft);
        int d = countShips(sea, {x2, midy}, {midx + 1, y1});
        return a + b + c + d;
    }
};
```

#### Go

```go
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * type Sea struct {
 *     func hasShips(topRight, bottomLeft []int) bool {}
 * }
 */

func countShips(sea Sea, topRight, bottomLeft []int) int {
	x1, y1 := bottomLeft[0], bottomLeft[1]
	x2, y2 := topRight[0], topRight[1]
	if x1 > x2 || y1 > y2 {
		return 0
	}
	if !sea.hasShips(topRight, bottomLeft) {
		return 0
	}
	if x1 == x2 && y1 == y2 {
		return 1
	}
	midx := (x1 + x2) >> 1
	midy := (y1 + y2) >> 1
	a := countShips(sea, topRight, []int{midx + 1, midy + 1})
	b := countShips(sea, []int{midx, y2}, []int{x1, midy + 1})
	c := countShips(sea, []int{midx, midy}, bottomLeft)
	d := countShips(sea, []int{x2, midy}, []int{midx + 1, y1})
	return a + b + c + d
}
```

#### TypeScript

```ts
/**
 * // This is the Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *      hasShips(topRight: number[], bottomLeft: number[]): boolean {}
 * }
 */

function countShips(sea: Sea, topRight: number[], bottomLeft: number[]): number {
    const [x1, y1] = bottomLeft;
    const [x2, y2] = topRight;
    if (x1 > x2 || y1 > y2 || !sea.hasShips(topRight, bottomLeft)) {
        return 0;
    }
    if (x1 === x2 && y1 === y2) {
        return 1;
    }
    const midx = (x1 + x2) >> 1;
    const midy = (y1 + y2) >> 1;
    const a = countShips(sea, topRight, [midx + 1, midy + 1]);
    const b = countShips(sea, [midx, y2], [x1, midy + 1]);
    const c = countShips(sea, [midx, midy], bottomLeft);
    const d = countShips(sea, [x2, midy], [midx + 1, y1]);
    return a + b + c + d;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1275. 找出井字棋的获胜者](https://leetcode.cn/problems/find-winner-on-a-tic-tac-toe-game){#1275}

{{< tabs "1275" >}}

{{% tab "python" %}}
```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        n = len(moves)
        cnt = [0] * 8
        for k in range(n - 1, -1, -2):
            i, j = moves[k]
            cnt[i] += 1
            cnt[j + 3] += 1
            if i == j:
                cnt[6] += 1
            if i + j == 2:
                cnt[7] += 1
            if any(v == 3 for v in cnt):
                return "B" if k & 1 else "A"
        return "Draw" if n == 9 else "Pending"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String tictactoe(int[][] moves) {
        int n = moves.length;
        int[] cnt = new int[8];
        for (int k = n - 1; k >= 0; k -= 2) {
            int i = moves[k][0], j = moves[k][1];
            cnt[i]++;
            cnt[j + 3]++;
            if (i == j) {
                cnt[6]++;
            }
            if (i + j == 2) {
                cnt[7]++;
            }
            if (cnt[i] == 3 || cnt[j + 3] == 3 || cnt[6] == 3 || cnt[7] == 3) {
                return k % 2 == 0 ? "A" : "B";
            }
        }
        return n == 9 ? "Draw" : "Pending";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        int cnt[8]{};
        for (int k = n - 1; k >= 0; k -= 2) {
            int i = moves[k][0], j = moves[k][1];
            cnt[i]++;
            cnt[j + 3]++;
            if (i == j) {
                cnt[6]++;
            }
            if (i + j == 2) {
                cnt[7]++;
            }
            if (cnt[i] == 3 || cnt[j + 3] == 3 || cnt[6] == 3 || cnt[7] == 3) {
                return k % 2 == 0 ? "A" : "B";
            }
        }
        return n == 9 ? "Draw" : "Pending";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func tictactoe(moves [][]int) string {
	n := len(moves)
	cnt := [8]int{}
	for k := n - 1; k >= 0; k -= 2 {
		i, j := moves[k][0], moves[k][1]
		cnt[i]++
		cnt[j+3]++
		if i == j {
			cnt[6]++
		}
		if i+j == 2 {
			cnt[7]++
		}
		if cnt[i] == 3 || cnt[j+3] == 3 || cnt[6] == 3 || cnt[7] == 3 {
			if k%2 == 0 {
				return "A"
			}
			return "B"
		}
	}
	if n == 9 {
		return "Draw"
	}
	return "Pending"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function tictactoe(moves: number[][]): string {
    const n = moves.length;
    const cnt = new Array(8).fill(0);
    for (let k = n - 1; k >= 0; k -= 2) {
        const [i, j] = moves[k];
        cnt[i]++;
        cnt[j + 3]++;
        if (i == j) {
            cnt[6]++;
        }
        if (i + j == 2) {
            cnt[7]++;
        }
        if (cnt[i] == 3 || cnt[j + 3] == 3 || cnt[6] == 3 || cnt[7] == 3) {
            return k % 2 == 0 ? 'A' : 'B';
        }
    }
    return n == 9 ? 'Draw' : 'Pending';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>井字棋&nbsp;</strong>是由两个玩家<i>&nbsp;</i><code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;在&nbsp;<code>3 x 3</code>&nbsp;的棋盘上进行的游戏。井字棋游戏的规则如下：</p>

<ul>
	<li>玩家轮流将棋子放在空方格 (<code>' '</code>) 上。</li>
	<li>第一个玩家 <code>A</code> 总是用&nbsp;<code>'X'</code> 作为棋子，而第二个玩家 <code>B</code> 总是用 <code>'O'</code> 作为棋子。</li>
	<li><code>'X'</code> 和 <code>'O'</code> 只能放在空方格中，而不能放在已经被占用的方格上。</li>
	<li>只要有 <strong>3</strong> 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。</li>
	<li>如果所有方块都放满棋子（不为空），游戏也会结束。</li>
	<li>游戏结束后，棋子无法再进行任何移动。</li>
</ul>

<p>给你一个数组 <code>moves</code>，其中 <code>moves[i] = [row<sub>i</sub>, col<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;次移动在&nbsp;<code>grid[row<sub>i</sub>][col<sub>i</sub>]</code>。如果游戏存在获胜者（<code>A</code> 或 <code>B</code>），就返回该游戏的获胜者；如果游戏以平局结束，则返回 <code>"Draw"</code>；如果仍会有行动（游戏未结束），则返回 <code>"Pending"</code>。</p>

<p>你可以假设&nbsp;<code>moves</code>&nbsp;都 <strong>有效</strong>（遵循 <strong>井字棋</strong> 规则），网格最初是空的，<code>A</code> 将先行动。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1275.Find%20Winner%20on%20a%20Tic%20Tac%20Toe%20Game/images/xo1-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
<strong>输出：</strong>"A"
<strong>解释：</strong>"A" 获胜，他总是先走。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1275.Find%20Winner%20on%20a%20Tic%20Tac%20Toe%20Game/images/xo2-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
<strong>输出：</strong>"B"
<strong>解释：</strong>"B" 获胜。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1275.Find%20Winner%20on%20a%20Tic%20Tac%20Toe%20Game/images/xo3-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
<strong>输出：</strong>"Draw"
<strong>解释：</strong>由于没有办法再行动，游戏以平局结束。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= moves.length &lt;= 9</code></li>
	<li><code>moves[i].length == 2</code></li>
	<li><code>0 &lt;= moves[i][j] &lt;= 2</code></li>
	<li><code>moves</code>&nbsp;里没有重复的元素。</li>
	<li><code>moves</code> 遵循井字棋的规则。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：判断最后一个落棋的人能否获胜

由于 `moves` 都有效，也即是说，不存在某个人获胜后，其他人仍然落棋的情况。因此，只需判断最后一个落棋的人能否获胜即可。

我们用一个长度为 $8$ 的数组 `cnt` 记录行、列以及对角线的落棋次数。其中 $cnt[0, 1, 2]$ 分别表示第 $0, 1, 2$ 行的落棋次数，而 $cnt[3, 4, 5]$ 分别表示第 $0, 1, 2$ 列的落棋次数，另外 $cnt[6]$ 和 $cnt[7]$ 分别表示两条对角线的落棋次数。落棋过程中，如果某个人在某一行、列或对角线上落棋次数达到 $3$ 次，则该人获胜。

如果最后一个落棋的人没有获胜，那么我们判断棋盘是否已满，如果已满，则平局；否则，游戏尚未结束。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `moves` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        n = len(moves)
        cnt = [0] * 8
        for k in range(n - 1, -1, -2):
            i, j = moves[k]
            cnt[i] += 1
            cnt[j + 3] += 1
            if i == j:
                cnt[6] += 1
            if i + j == 2:
                cnt[7] += 1
            if any(v == 3 for v in cnt):
                return "B" if k & 1 else "A"
        return "Draw" if n == 9 else "Pending"
```

#### Java

```java
class Solution {
    public String tictactoe(int[][] moves) {
        int n = moves.length;
        int[] cnt = new int[8];
        for (int k = n - 1; k >= 0; k -= 2) {
            int i = moves[k][0], j = moves[k][1];
            cnt[i]++;
            cnt[j + 3]++;
            if (i == j) {
                cnt[6]++;
            }
            if (i + j == 2) {
                cnt[7]++;
            }
            if (cnt[i] == 3 || cnt[j + 3] == 3 || cnt[6] == 3 || cnt[7] == 3) {
                return k % 2 == 0 ? "A" : "B";
            }
        }
        return n == 9 ? "Draw" : "Pending";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        int cnt[8]{};
        for (int k = n - 1; k >= 0; k -= 2) {
            int i = moves[k][0], j = moves[k][1];
            cnt[i]++;
            cnt[j + 3]++;
            if (i == j) {
                cnt[6]++;
            }
            if (i + j == 2) {
                cnt[7]++;
            }
            if (cnt[i] == 3 || cnt[j + 3] == 3 || cnt[6] == 3 || cnt[7] == 3) {
                return k % 2 == 0 ? "A" : "B";
            }
        }
        return n == 9 ? "Draw" : "Pending";
    }
};
```

#### Go

```go
func tictactoe(moves [][]int) string {
	n := len(moves)
	cnt := [8]int{}
	for k := n - 1; k >= 0; k -= 2 {
		i, j := moves[k][0], moves[k][1]
		cnt[i]++
		cnt[j+3]++
		if i == j {
			cnt[6]++
		}
		if i+j == 2 {
			cnt[7]++
		}
		if cnt[i] == 3 || cnt[j+3] == 3 || cnt[6] == 3 || cnt[7] == 3 {
			if k%2 == 0 {
				return "A"
			}
			return "B"
		}
	}
	if n == 9 {
		return "Draw"
	}
	return "Pending"
}
```

#### TypeScript

```ts
function tictactoe(moves: number[][]): string {
    const n = moves.length;
    const cnt = new Array(8).fill(0);
    for (let k = n - 1; k >= 0; k -= 2) {
        const [i, j] = moves[k];
        cnt[i]++;
        cnt[j + 3]++;
        if (i == j) {
            cnt[6]++;
        }
        if (i + j == 2) {
            cnt[7]++;
        }
        if (cnt[i] == 3 || cnt[j + 3] == 3 || cnt[6] == 3 || cnt[7] == 3) {
            return k % 2 == 0 ? 'A' : 'B';
        }
    }
    return n == 9 ? 'Draw' : 'Pending';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1276. 不浪费原料的汉堡制作方案](https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients){#1276}

{{< tabs "1276" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        k = 4 * cheeseSlices - tomatoSlices
        y = k // 2
        x = cheeseSlices - y
        return [] if k % 2 or y < 0 or x < 0 else [x, y]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int k = 4 * cheeseSlices - tomatoSlices;
        int y = k / 2;
        int x = cheeseSlices - y;
        return k % 2 != 0 || y < 0 || x < 0 ? List.of() : List.of(x, y);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int k = 4 * cheeseSlices - tomatoSlices;
        int y = k / 2;
        int x = cheeseSlices - y;
        return k % 2 || x < 0 || y < 0 ? vector<int>{} : vector<int>{x, y};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfBurgers(tomatoSlices int, cheeseSlices int) []int {
	k := 4*cheeseSlices - tomatoSlices
	y := k / 2
	x := cheeseSlices - y
	if k%2 != 0 || x < 0 || y < 0 {
		return []int{}
	}
	return []int{x, y}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfBurgers(tomatoSlices: number, cheeseSlices: number): number[] {
    const k = 4 * cheeseSlices - tomatoSlices;
    const y = k >> 1;
    const x = cheeseSlices - y;
    return k % 2 || y < 0 || x < 0 ? [] : [x, y];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_of_burgers(tomato_slices: i32, cheese_slices: i32) -> Vec<i32> {
        let k = 4 * cheese_slices - tomato_slices;
        let y = k / 2;
        let x = cheese_slices - y;
        if k % 2 != 0 || y < 0 || x < 0 {
            Vec::new()
        } else {
            vec![x, y]
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

<p>圣诞活动预热开始啦，汉堡店推出了全新的汉堡套餐。为了避免浪费原料，请你帮他们制定合适的制作计划。</p>

<p>给你两个整数&nbsp;<code>tomatoSlices</code>&nbsp;和&nbsp;<code>cheeseSlices</code>，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：</p>

<ul>
	<li><strong>巨无霸汉堡：</strong>4 片番茄和 1 片奶酪</li>
	<li><strong>小皇堡：</strong>2 片番茄和&nbsp;1 片奶酪</li>
</ul>

<p>请你以&nbsp;<code>[total_jumbo, total_small]</code>（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片&nbsp;<code>tomatoSlices</code>&nbsp;和奶酪片&nbsp;<code>cheeseSlices</code>&nbsp;的数量都是&nbsp;<code>0</code>。</p>

<p>如果无法使剩下的番茄片&nbsp;<code>tomatoSlices</code>&nbsp;和奶酪片&nbsp;<code>cheeseSlices</code>&nbsp;的数量为&nbsp;<code>0</code>，就请返回&nbsp;<code>[]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 16, cheeseSlices = 7
<strong>输出：</strong>[1,6]
<strong>解释：</strong>制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 = 7 片奶酪。不会剩下原料。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 17, cheeseSlices = 4
<strong>输出：</strong>[]
<strong>解释：</strong>只制作小皇堡和巨无霸汉堡无法用光全部原料。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 4, cheeseSlices = 17
<strong>输出：</strong>[]
<strong>解释：</strong>制作 1 个巨无霸汉堡会剩下 16 片奶酪，制作 2 个小皇堡会剩下 15 片奶酪。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 0, cheeseSlices = 0
<strong>输出：</strong>[0,0]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>tomatoSlices = 2, cheeseSlices = 1
<strong>输出：</strong>[0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= tomatoSlices &lt;= 10^7</code></li>
	<li><code>0 &lt;= cheeseSlices &lt;= 10^7</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们设巨无霸汉堡数量为 $x$，小皇堡数量为 $y$，则有：

$$
\begin{aligned}
4x + 2y &= tomatoSlices \\
x + y &= cheeseSlices
\end{aligned}
$$

将上述两式转换，可以得到：

$$
\begin{aligned}
y = (4 \times cheeseSlices - tomatoSlices) / 2 \\
x = cheeseSlices - y
\end{aligned}
$$

其中 $x$ 和 $y$ 必须为非负整数。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        k = 4 * cheeseSlices - tomatoSlices
        y = k // 2
        x = cheeseSlices - y
        return [] if k % 2 or y < 0 or x < 0 else [x, y]
```

#### Java

```java
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int k = 4 * cheeseSlices - tomatoSlices;
        int y = k / 2;
        int x = cheeseSlices - y;
        return k % 2 != 0 || y < 0 || x < 0 ? List.of() : List.of(x, y);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int k = 4 * cheeseSlices - tomatoSlices;
        int y = k / 2;
        int x = cheeseSlices - y;
        return k % 2 || x < 0 || y < 0 ? vector<int>{} : vector<int>{x, y};
    }
};
```

#### Go

```go
func numOfBurgers(tomatoSlices int, cheeseSlices int) []int {
	k := 4*cheeseSlices - tomatoSlices
	y := k / 2
	x := cheeseSlices - y
	if k%2 != 0 || x < 0 || y < 0 {
		return []int{}
	}
	return []int{x, y}
}
```

#### TypeScript

```ts
function numOfBurgers(tomatoSlices: number, cheeseSlices: number): number[] {
    const k = 4 * cheeseSlices - tomatoSlices;
    const y = k >> 1;
    const x = cheeseSlices - y;
    return k % 2 || y < 0 || x < 0 ? [] : [x, y];
}
```

#### Rust

```rust
impl Solution {
    pub fn num_of_burgers(tomato_slices: i32, cheese_slices: i32) -> Vec<i32> {
        let k = 4 * cheese_slices - tomato_slices;
        let y = k / 2;
        let x = cheese_slices - y;
        if k % 2 != 0 || y < 0 || x < 0 {
            Vec::new()
        } else {
            vec![x, y]
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1277. 统计全为 1 的正方形子矩阵](https://leetcode.cn/problems/count-square-submatrices-with-all-ones){#1277}

{{< tabs "1277" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        f = [[0] * n for _ in range(m)]
        ans = 0
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                if v == 0:
                    continue
                if i == 0 or j == 0:
                    f[i][j] = 1
                else:
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]) + 1
                ans += f[i][j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] f = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])) + 1;
                }
                ans += f[i][j];
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
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                }
                ans += f[i][j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSquares(matrix [][]int) int {
	m, n, ans := len(matrix), len(matrix[0]), 0
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i, row := range matrix {
		for j, v := range row {
			if v == 0 {
				continue
			}
			if i == 0 || j == 0 {
				f[i][j] = 1
			} else {
				f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1
			}
			ans += f[i][j]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSquares(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 0) {
                continue;
            }
            if (i === 0 || j === 0) {
                f[i][j] = 1;
            } else {
                f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])) + 1;
            }
            ans += f[i][j];
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut f = vec![vec![0; n]; m];
        let mut ans = 0;

        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 0 {
                    continue;
                }
                if i == 0 || j == 0 {
                    f[i][j] = 1;
                } else {
                    f[i][j] = std::cmp::min(f[i - 1][j - 1], std::cmp::min(f[i - 1][j], f[i][j - 1])) + 1;
                }
                ans += f[i][j];
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(0));
    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 0) {
                continue;
            }
            if (i === 0 || j === 0) {
                f[i][j] = 1;
            } else {
                f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])) + 1;
            }
            ans += f[i][j];
        }
    }

    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountSquares(int[][] matrix) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        int[,] f = new int[m, n];
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    f[i, j] = 1;
                } else {
                    f[i, j] = Math.Min(f[i - 1, j - 1], Math.Min(f[i - 1, j], f[i, j - 1])) + 1;
                }
                ans += f[i, j];
            }
        }

        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m * n</code>&nbsp;的矩阵，矩阵中的元素不是 <code>0</code> 就是 <code>1</code>，请你统计并返回其中完全由 <code>1</code> 组成的 <strong>正方形</strong> 子矩阵的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>matrix =
[
&nbsp; [0,1,1,1],
&nbsp; [1,1,1,1],
&nbsp; [0,1,1,1]
]
<strong>输出：</strong>15
<strong>解释：</strong> 
边长为 1 的正方形有 <strong>10</strong> 个。
边长为 2 的正方形有 <strong>4</strong> 个。
边长为 3 的正方形有 <strong>1</strong> 个。
正方形的总数 = 10 + 4 + 1 = <strong>15</strong>.
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
<strong>输出：</strong>7
<strong>解释：</strong>
边长为 1 的正方形有 <strong>6</strong> 个。 
边长为 2 的正方形有 <strong>1</strong> 个。
正方形的总数 = 6 + 1 = <strong>7</strong>.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 300</code></li>
	<li><code>1 &lt;= arr[0].length&nbsp;&lt;= 300</code></li>
	<li><code>0 &lt;= arr[i][j] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 为以 $(i,j)$ 为右下角的正方形子矩阵的边长，初始时 $f[i][j] = 0$，答案为 $\sum_{i,j} f[i][j]$。

考虑 $f[i][j]$ 如何进行状态转移。

-   当 $\text{matrix}[i][j] = 0$ 时，有 $f[i][j] = 0$。
-   当 $\text{matrix}[i][j] = 1$ 时，状态 $f[i][j]$ 的值取决于其上、左、左上三个位置的值：
    -   如果 $i = 0$ 或 $j = 0$，则 $f[i][j] = 1$。
    -   否则 $f[i][j] = \min(f[i-1][j-1], f[i-1][j], f[i][j-1]) + 1$。

答案为 $\sum_{i,j} f[i][j]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        f = [[0] * n for _ in range(m)]
        ans = 0
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                if v == 0:
                    continue
                if i == 0 or j == 0:
                    f[i][j] = 1
                else:
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]) + 1
                ans += f[i][j]
        return ans
```

#### Java

```java
class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] f = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])) + 1;
                }
                ans += f[i][j];
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
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                }
                ans += f[i][j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSquares(matrix [][]int) int {
	m, n, ans := len(matrix), len(matrix[0]), 0
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i, row := range matrix {
		for j, v := range row {
			if v == 0 {
				continue
			}
			if i == 0 || j == 0 {
				f[i][j] = 1
			} else {
				f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1
			}
			ans += f[i][j]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countSquares(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 0) {
                continue;
            }
            if (i === 0 || j === 0) {
                f[i][j] = 1;
            } else {
                f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])) + 1;
            }
            ans += f[i][j];
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut f = vec![vec![0; n]; m];
        let mut ans = 0;

        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 0 {
                    continue;
                }
                if i == 0 || j == 0 {
                    f[i][j] = 1;
                } else {
                    f[i][j] = std::cmp::min(f[i - 1][j - 1], std::cmp::min(f[i - 1][j], f[i][j - 1])) + 1;
                }
                ans += f[i][j];
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(0));
    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 0) {
                continue;
            }
            if (i === 0 || j === 0) {
                f[i][j] = 1;
            } else {
                f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])) + 1;
            }
            ans += f[i][j];
        }
    }

    return ans;
};
```

#### C#

```cs
public class Solution {
    public int CountSquares(int[][] matrix) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        int[,] f = new int[m, n];
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    f[i, j] = 1;
                } else {
                    f[i, j] = Math.Min(f[i - 1, j - 1], Math.Min(f[i - 1, j], f[i, j - 1])) + 1;
                }
                ans += f[i, j];
            }
        }

        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1278. 分割回文串 III](https://leetcode.cn/problems/palindrome-partitioning-iii){#1278}

{{< tabs "1278" >}}

{{% tab "python" %}}
```python
class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = int(s[i] != s[j])
                if i + 1 < j:
                    g[i][j] += g[i + 1][j - 1]

        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, min(i, k) + 1):
                if j == 1:
                    f[i][j] = g[0][i - 1]
                else:
                    f[i][j] = inf
                    for h in range(j - 1, i):
                        f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1])
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                g[i][j] = s.charAt(i) != s.charAt(j) ? 1 : 0;
                if (i + 1 < j) {
                    g[i][j] += g[i + 1][j - 1];
                }
            }
        }
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(i, k); ++j) {
                if (j == 1) {
                    f[i][j] = g[0][i - 1];
                } else {
                    f[i][j] = 10000;
                    for (int h = j - 1; h < i; ++h) {
                        f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                    }
                }
            }
        }
        return f[n][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                g[i][j] = s[i] != s[j] ? 1 : 0;
                if (i + 1 < j) g[i][j] += g[i + 1][j - 1];
            }
        }
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                if (j == 1) {
                    f[i][j] = g[0][i - 1];
                } else {
                    f[i][j] = 10000;
                    for (int h = j - 1; h < i; ++h) {
                        f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                    }
                }
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func palindromePartition(s string, k int) int {
	n := len(s)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		for j := 1; j < n; j++ {
			if s[i] != s[j] {
				g[i][j] = 1
			}
			if i+1 < j {
				g[i][j] += g[i+1][j-1]
			}
		}
	}
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= min(i, k); j++ {
			if j == 1 {
				f[i][j] = g[0][i-1]
			} else {
				f[i][j] = 100000
				for h := j - 1; h < i; h++ {
					f[i][j] = min(f[i][j], f[h][j-1]+g[h][i-1])
				}
			}
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function palindromePartition(s: string, k: number): number {
    const n = s.length;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            g[i][j] = s[i] !== s[j] ? 1 : 0;
            if (i + 1 < j) {
                g[i][j] += g[i + 1][j - 1];
            }
        }
    }
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= Math.min(i, k); j++) {
            if (j === 1) {
                f[i][j] = g[0][i - 1];
            } else {
                f[i][j] = 1 << 30;
                for (let h = j - 1; h < i; h++) {
                    f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                }
            }
        }
    }
    return f[n][k];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn palindrome_partition(s: String, k: i32) -> i32 {
        let n = s.len();
        let s: Vec<char> = s.chars().collect();
        let mut g = vec![vec![0; n]; n];

        for i in (0..n).rev() {
            for j in i + 1..n {
                g[i][j] = if s[i] != s[j] { 1 } else { 0 };
                if i + 1 < j {
                    g[i][j] += g[i + 1][j - 1];
                }
            }
        }

        let mut f = vec![vec![0; (k + 1) as usize]; n + 1];
        let inf = i32::MAX;

        for i in 1..=n {
            for j in 1..=i.min(k as usize) {
                if j == 1 {
                    f[i][j] = g[0][i - 1];
                } else {
                    f[i][j] = inf;
                    for h in (j - 1)..i {
                        f[i][j] = f[i][j].min(f[h][j - 1] + g[h][i - 1]);
                    }
                }
            }
        }

        f[n][k as usize]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由小写字母组成的字符串&nbsp;<code>s</code>，和一个整数&nbsp;<code>k</code>。</p>

<p>请你按下面的要求分割字符串：</p>

<ul>
	<li>首先，你可以将&nbsp;<code>s</code>&nbsp;中的部分字符修改为其他的小写英文字母。</li>
	<li>接着，你需要把&nbsp;<code>s</code>&nbsp;分割成&nbsp;<code>k</code>&nbsp;个非空且不相交的子串，并且每个子串都是回文串。</li>
</ul>

<p>请返回以这种方式分割字符串所需修改的最少字符数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;abc&quot;, k = 2
<strong>输出：</strong>1
<strong>解释：</strong>你可以把字符串分割成 &quot;ab&quot; 和 &quot;c&quot;，并修改 &quot;ab&quot; 中的 1 个字符，将它变成回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aabbc&quot;, k = 3
<strong>输出：</strong>0
<strong>解释：</strong>你可以把字符串分割成 &quot;aa&quot;、&quot;bb&quot; 和 &quot;c&quot;，它们都是回文串。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;leetcode&quot;, k = 8
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示将字符串 $s$ 的前 $i$ 个字符分割成 $j$ 个回文串所需要的最少修改次数，我们假定 $i$ 下标从 $1$ 开始，答案为 $f[n][k]$。

对于 $f[i][j]$，我们可以枚举第 $j-1$ 个回文串的最后一个字符的位置 $h$，那么 $f[i][j]$ 就等于 $f[h][j-1] + g[h][i-1]$ 的较小值，其中 $g[h][i-1]$ 表示将字符串 $s[h..i-1]$ 变成回文串所需要的最少修改次数（这一部分我们可以通过预处理得到，时间复杂度 $O(n^2)$。

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n \times (n + k))$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = int(s[i] != s[j])
                if i + 1 < j:
                    g[i][j] += g[i + 1][j - 1]

        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, min(i, k) + 1):
                if j == 1:
                    f[i][j] = g[0][i - 1]
                else:
                    f[i][j] = inf
                    for h in range(j - 1, i):
                        f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1])
        return f[n][k]
```

#### Java

```java
class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                g[i][j] = s.charAt(i) != s.charAt(j) ? 1 : 0;
                if (i + 1 < j) {
                    g[i][j] += g[i + 1][j - 1];
                }
            }
        }
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(i, k); ++j) {
                if (j == 1) {
                    f[i][j] = g[0][i - 1];
                } else {
                    f[i][j] = 10000;
                    for (int h = j - 1; h < i; ++h) {
                        f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                    }
                }
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                g[i][j] = s[i] != s[j] ? 1 : 0;
                if (i + 1 < j) g[i][j] += g[i + 1][j - 1];
            }
        }
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                if (j == 1) {
                    f[i][j] = g[0][i - 1];
                } else {
                    f[i][j] = 10000;
                    for (int h = j - 1; h < i; ++h) {
                        f[i][j] = min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                    }
                }
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func palindromePartition(s string, k int) int {
	n := len(s)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		for j := 1; j < n; j++ {
			if s[i] != s[j] {
				g[i][j] = 1
			}
			if i+1 < j {
				g[i][j] += g[i+1][j-1]
			}
		}
	}
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= min(i, k); j++ {
			if j == 1 {
				f[i][j] = g[0][i-1]
			} else {
				f[i][j] = 100000
				for h := j - 1; h < i; h++ {
					f[i][j] = min(f[i][j], f[h][j-1]+g[h][i-1])
				}
			}
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function palindromePartition(s: string, k: number): number {
    const n = s.length;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            g[i][j] = s[i] !== s[j] ? 1 : 0;
            if (i + 1 < j) {
                g[i][j] += g[i + 1][j - 1];
            }
        }
    }
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= Math.min(i, k); j++) {
            if (j === 1) {
                f[i][j] = g[0][i - 1];
            } else {
                f[i][j] = 1 << 30;
                for (let h = j - 1; h < i; h++) {
                    f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h][i - 1]);
                }
            }
        }
    }
    return f[n][k];
}
```

#### Rust

```rust
impl Solution {
    pub fn palindrome_partition(s: String, k: i32) -> i32 {
        let n = s.len();
        let s: Vec<char> = s.chars().collect();
        let mut g = vec![vec![0; n]; n];

        for i in (0..n).rev() {
            for j in i + 1..n {
                g[i][j] = if s[i] != s[j] { 1 } else { 0 };
                if i + 1 < j {
                    g[i][j] += g[i + 1][j - 1];
                }
            }
        }

        let mut f = vec![vec![0; (k + 1) as usize]; n + 1];
        let inf = i32::MAX;

        for i in 1..=n {
            for j in 1..=i.min(k as usize) {
                if j == 1 {
                    f[i][j] = g[0][i - 1];
                } else {
                    f[i][j] = inf;
                    for h in (j - 1)..i {
                        f[i][j] = f[i][j].min(f[h][j - 1] + g[h][i - 1]);
                    }
                }
            }
        }

        f[n][k as usize]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1279. 红绿灯路口 🔒](https://leetcode.cn/problems/traffic-light-controlled-intersection){#1279}

{{< tabs "1279" >}}

{{% tab "python" %}}
```python
from threading import Lock


class TrafficLight:
    def __init__(self):
        self.lock = Lock()
        self.road = 1

    def carArrived(
        self,
        carId: int,  # ID of the car
        # ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        roadId: int,
        direction: int,  # Direction of the car
        # Use turnGreen() to turn light to green on current road
        turnGreen: 'Callable[[], None]',
        # Use crossCar() to make car cross the intersection
        crossCar: 'Callable[[], None]',
    ) -> None:
        self.lock.acquire()
        if self.road != roadId:
            self.road = roadId
            turnGreen()
        crossCar()
        self.lock.release()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TrafficLight {
    private int road = 1;

    public TrafficLight() {
    }

    public synchronized void carArrived(int carId, // ID of the car
        int roadId, // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction, // Direction of the car
        Runnable turnGreen, // Use turnGreen.run() to turn light to green on current road
        Runnable crossCar // Use crossCar.run() to make car cross the intersection
    ) {
        if (roadId != road) {
            turnGreen.run();
            road = roadId;
        }
        crossCar.run();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这是两条路的交叉路口。第一条路是 A 路，车辆可沿&nbsp;1 号方向由北向南行驶，也可沿&nbsp;2 号方向由南向北行驶。第二条路是 B 路，车辆可沿&nbsp;3 号方向由西向东行驶，也可沿 4 号方向由东向西行驶。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1279.Traffic%20Light%20Controlled%20Intersection/images/exp.png" style="height:417px; width:600px" /></p>

<p>每条路在路口前都有一个红绿灯。红绿灯可以亮起红灯或绿灯。</p>

<ol>
	<li><strong>绿灯</strong>表示两个方向的车辆都可通过路口。</li>
	<li><strong>红灯</strong>表示两个方向的车辆都不可以通过路口，必须等待绿灯亮起。</li>
</ol>

<p>两条路上的红绿灯不可以同时为绿灯。这意味着，当 A 路上的绿灯亮起时，B 路上的红灯会亮起；当 B&nbsp;路上的绿灯亮起时，A&nbsp;路上的红灯会亮起.</p>

<p>开始时，A 路上的<strong>绿灯</strong>亮起，B 路上的<strong>红灯</strong>亮起。当一条路上的绿灯亮起时，所有车辆都可以从任意两个方向通过路口，直到另一条路上的绿灯亮起。不同路上的车辆不可以同时通过路口。</p>

<p>给这个路口设计一个没有死锁的红绿灯控制系统。</p>

<p>实现函数&nbsp;<code>void carArrived(carId, roadId, direction, turnGreen, crossCar)</code>&nbsp;:</p>

<ul>
	<li><code>carId</code>&nbsp;为到达车辆的编号。</li>
	<li><code>roadId</code>&nbsp;为车辆所在道路的编号。</li>
	<li><code>direction</code>&nbsp;为车辆的行进方向。</li>
	<li><code>turnGreen</code>&nbsp;是一个函数，调用此函数会使当前道路上的绿灯亮起。</li>
	<li><code>crossCar</code>&nbsp;是一个函数，调用此函数会允许车辆通过路口。</li>
</ul>

<p>当你的答案避免了车辆在路口出现死锁，此答案会被认定为正确的。当路口已经亮起绿灯时仍打开绿灯，此答案会被认定为错误的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> cars = [1,3,5,2,4], directions = [2,1,2,4,3], arrivalTimes = [10,20,30,40,50]
<strong>输出:</strong> [
&quot;Car 1 Has Passed Road A In Direction 2&quot;,    // A 路上的红绿灯为绿色，1 号车可通过路口。
&quot;Car 3 Has Passed Road A In Direction 1&quot;,    // 红绿灯仍为绿色，3 号车通过路口。
&quot;Car 5 Has Passed Road A In Direction 2&quot;,    // 红绿灯仍为绿色，5 号车通过路口。
&quot;Traffic Light On Road B Is Green&quot;,          // 2 号车在 B 路请求绿灯。
&quot;Car 2 Has Passed Road B In Direction 4&quot;,    // B 路上的绿灯现已亮起，2 号车通过路口。
&quot;Car 4 Has Passed Road B In Direction 3&quot;     // 红绿灯仍为绿色，4 号车通过路口。
]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> cars = [1,2,3,4,5], directions = [2,4,3,3,1], arrivalTimes = [10,20,30,40,40]
<strong>输出:</strong> [
&quot;Car 1 Has Passed Road A In Direction 2&quot;,    // A 路上的红绿灯为绿色，1 号车可通过路口。
&quot;Traffic Light On Road B Is Green&quot;,          // 2 号车在 B 路请求绿灯。
&quot;Car 2 Has Passed Road B In Direction 4&quot;,    // B 路上的绿灯现已亮起，2 号车通过路口。
&quot;Car 3 Has Passed Road B In Direction 3&quot;,    // B 路上的绿灯现已亮起，3 号车通过路口。
&quot;Traffic Light On Road A Is Green&quot;,          // 5 号车在 A 路请求绿灯。
&quot;Car 5 Has Passed Road A In Direction 1&quot;,    // A 路上的绿灯现已亮起，5 号车通过路口。
&quot;Traffic Light On Road B Is Green&quot;,          // 4 号车在 B 路请求绿灯。4 号车在路口等灯，直到 5 号车通过路口，B 路的绿灯亮起。
&quot;Car 4 Has Passed Road B In Direction 3&quot;     // B 路上的绿灯现已亮起，4 号车通过路口。
]
<strong>解释:</strong> 这是一个无死锁的方案。注意，在 A 路上的绿灯亮起、5 号车通过前让 4 号车通过，也是一个<strong>正确</strong>且<strong>可</strong><strong>被接受</strong>的方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cars.length &lt;= 20</code></li>
	<li><code>cars.length = directions.length</code></li>
	<li><code>cars.length = arrivalTimes.length</code></li>
	<li><code>cars</code>&nbsp;中的所有值都是唯一的。</li>
	<li><code>1 &lt;= directions[i] &lt;= 4</code></li>
	<li><code>arrivalTimes</code> 是非递减的。</li>
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
from threading import Lock


class TrafficLight:
    def __init__(self):
        self.lock = Lock()
        self.road = 1

    def carArrived(
        self,
        carId: int,  # ID of the car
        # ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        roadId: int,
        direction: int,  # Direction of the car
        # Use turnGreen() to turn light to green on current road
        turnGreen: 'Callable[[], None]',
        # Use crossCar() to make car cross the intersection
        crossCar: 'Callable[[], None]',
    ) -> None:
        self.lock.acquire()
        if self.road != roadId:
            self.road = roadId
            turnGreen()
        crossCar()
        self.lock.release()
```

#### Java

```java
class TrafficLight {
    private int road = 1;

    public TrafficLight() {
    }

    public synchronized void carArrived(int carId, // ID of the car
        int roadId, // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction, // Direction of the car
        Runnable turnGreen, // Use turnGreen.run() to turn light to green on current road
        Runnable crossCar // Use crossCar.run() to make car cross the intersection
    ) {
        if (roadId != road) {
            turnGreen.run();
            road = roadId;
        }
        crossCar.run();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
