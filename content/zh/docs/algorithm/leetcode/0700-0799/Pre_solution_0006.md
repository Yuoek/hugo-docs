---
title: "0750_角矩形的数量 🔒"
date: 2025-10-08T18:36:29+08:00
weight: 6
tags: [二分查找, 位运算, 动态规划, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 字符串匹配, 广度优先搜索, 扫描线, 排序, 数学, 数组, 模拟, 欧拉回路, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [0750_角矩形的数量 🔒](#750)
#### [数组](#750)
#### [数学](#750)
#### [动态规划](#750)
#### [矩阵](#750)
### [0751_IP 到 CIDR 🔒](#751)
#### [位运算](#751)
#### [字符串](#751)
### [0752_打开转盘锁](#752)
#### [广度优先搜索](#752)
#### [数组](#752)
#### [哈希表](#752)
#### [字符串](#752)
### [0753_破解保险箱](#753)
#### [深度优先搜索](#753)
#### [图](#753)
#### [欧拉回路](#753)
### [0754_到达终点数字](#754)
#### [数学](#754)
#### [二分查找](#754)
### [0755_倒水 🔒](#755)
#### [数组](#755)
#### [模拟](#755)
### [0756_金字塔转换矩阵](#756)
#### [位运算](#756)
#### [深度优先搜索](#756)
#### [广度优先搜索](#756)
### [0757_设置交集大小至少为2](#757)
#### [贪心](#757)
#### [数组](#757)
#### [排序](#757)
### [0758_字符串中的加粗单词 🔒](#758)
#### [字典树](#758)
#### [数组](#758)
#### [哈希表](#758)
#### [字符串](#758)
#### [字符串匹配](#758)
### [0759_员工空闲时间 🔒](#759)
#### [数组](#759)
#### [排序](#759)
#### [扫描线](#759)
#### [堆（优先队列）](#759)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0750_角矩形的数量 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 矩阵
---
### 0751_IP 到 CIDR 🔒
___
#### 位运算
___
#### 字符串
---
### 0752_打开转盘锁
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0753_破解保险箱
___
#### 深度优先搜索
___
#### 图
___
#### 欧拉回路
---
### 0754_到达终点数字
___
#### 数学
___
#### 二分查找
---
### 0755_倒水 🔒
___
#### 数组
___
#### 模拟
---
### 0756_金字塔转换矩阵
___
#### 位运算
___
#### 深度优先搜索
___
#### 广度优先搜索
---
### 0757_设置交集大小至少为2
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 0758_字符串中的加粗单词 🔒
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 字符串匹配
---
### 0759_员工空闲时间 🔒
___
#### 数组
___
#### 排序
___
#### 扫描线
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 哈希表 | 图 | 堆（优先队列） |
| 字典树 | 字符串 | 字符串匹配 |
| 广度优先搜索 | 扫描线 | 排序 |
| 数学 | 数组 | 模拟 |
| 欧拉回路 | 深度优先搜索 | 矩阵 |
| 贪心 |  |  |

# [750. 角矩形的数量 🔒](https://leetcode.cn/problems/number-of-corner-rectangles){#750}

{{< tabs "750" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        ans = 0
        cnt = Counter()
        n = len(grid[0])
        for row in grid:
            for i, c1 in enumerate(row):
                if c1:
                    for j in range(i + 1, n):
                        if row[j]:
                            ans += cnt[(i, j)]
                            cnt[(i, j)] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countCornerRectangles(int[][] grid) {
        int n = grid[0].length;
        int ans = 0;
        Map<List<Integer>, Integer> cnt = new HashMap<>();
        for (var row : grid) {
            for (int i = 0; i < n; ++i) {
                if (row[i] == 1) {
                    for (int j = i + 1; j < n; ++j) {
                        if (row[j] == 1) {
                            List<Integer> t = List.of(i, j);
                            ans += cnt.getOrDefault(t, 0);
                            cnt.merge(t, 1, Integer::sum);
                        }
                    }
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
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ans = 0;
        map<pair<int, int>, int> cnt;
        for (auto& row : grid) {
            for (int i = 0; i < n; ++i) {
                if (row[i]) {
                    for (int j = i + 1; j < n; ++j) {
                        if (row[j]) {
                            ans += cnt[{i, j}];
                            ++cnt[{i, j}];
                        }
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
func countCornerRectangles(grid [][]int) (ans int) {
	n := len(grid[0])
	type pair struct{ x, y int }
	cnt := map[pair]int{}
	for _, row := range grid {
		for i, x := range row {
			if x == 1 {
				for j := i + 1; j < n; j++ {
					if row[j] == 1 {
						t := pair{i, j}
						ans += cnt[t]
						cnt[t]++
					}
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countCornerRectangles(grid: number[][]): number {
    const n = grid[0].length;
    let ans = 0;
    const cnt: Map<number, number> = new Map();
    for (const row of grid) {
        for (let i = 0; i < n; ++i) {
            if (row[i] === 1) {
                for (let j = i + 1; j < n; ++j) {
                    if (row[j] === 1) {
                        const t = i * 200 + j;
                        ans += cnt.get(t) ?? 0;
                        cnt.set(t, (cnt.get(t) ?? 0) + 1);
                    }
                }
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

<p>给定一个只包含 <code>0</code> 和 <code>1</code> 的&nbsp;<code>m x n</code>&nbsp;整数矩阵&nbsp;<code>grid</code>&nbsp;，返回 <em>其中 「<strong>角矩形 」</strong>的数量</em> 。</p>

<p>一个<strong>「角矩形」</strong>是由四个不同的在矩阵上的 <code>1</code> 形成的&nbsp;<strong>轴对齐&nbsp;</strong>的矩形。注意只有角的位置才需要为 <code>1</code>。</p>

<p><strong>注意：</strong>4 个 <code>1</code>&nbsp;的位置需要是不同的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0750.Number%20Of%20Corner%20Rectangles/images/cornerrec1-grid.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[1,0,0,1,0],[0,0,1,0,1],[0,0,0,1,0],[1,0,1,0,1]]
<strong>输出：</strong>1
<strong>解释：</strong>只有一个角矩形，角的位置为 grid[1][2], grid[1][4], grid[3][2], grid[3][4]。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0750.Number%20Of%20Corner%20Rectangles/images/cornerrec2-grid.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1],[1,1,1],[1,1,1]]
<strong>输出：</strong>9
<strong>解释：</strong>这里有 4 个 2x2 的矩形，4 个 2x3 和 3x2 的矩形和 1 个 3x3&nbsp;的矩形。
</pre>

<p><strong>示例 3：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0750.Number%20Of%20Corner%20Rectangles/images/cornerrec3-grid.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1]]
<strong>输出：</strong>0
<strong>解释：</strong>矩形必须有 4 个不同的角。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code></li>
	<li>网格中&nbsp;<code>1</code>&nbsp;的个数在&nbsp;<code>[1, 6000]</code> 范围内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们枚举每一行作为矩形的下边，对于当前行，如果列 $i$ 和列 $j$ 都是 $1$，那么我们用哈希表找出此前的所有行中，有多少行的 $i$ 和 $j$ 列都是 $1$，那么就有多少个以 $(i, j)$ 为右下角的矩形，我们将其数量加入答案。然后将 $(i, j)$ 加入哈希表，继续枚举下一对 $(i, j)$。

时间复杂度 $O(m \times n^2)$，空间复杂度 $O(n^2)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        ans = 0
        cnt = Counter()
        n = len(grid[0])
        for row in grid:
            for i, c1 in enumerate(row):
                if c1:
                    for j in range(i + 1, n):
                        if row[j]:
                            ans += cnt[(i, j)]
                            cnt[(i, j)] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countCornerRectangles(int[][] grid) {
        int n = grid[0].length;
        int ans = 0;
        Map<List<Integer>, Integer> cnt = new HashMap<>();
        for (var row : grid) {
            for (int i = 0; i < n; ++i) {
                if (row[i] == 1) {
                    for (int j = i + 1; j < n; ++j) {
                        if (row[j] == 1) {
                            List<Integer> t = List.of(i, j);
                            ans += cnt.getOrDefault(t, 0);
                            cnt.merge(t, 1, Integer::sum);
                        }
                    }
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
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ans = 0;
        map<pair<int, int>, int> cnt;
        for (auto& row : grid) {
            for (int i = 0; i < n; ++i) {
                if (row[i]) {
                    for (int j = i + 1; j < n; ++j) {
                        if (row[j]) {
                            ans += cnt[{i, j}];
                            ++cnt[{i, j}];
                        }
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
func countCornerRectangles(grid [][]int) (ans int) {
	n := len(grid[0])
	type pair struct{ x, y int }
	cnt := map[pair]int{}
	for _, row := range grid {
		for i, x := range row {
			if x == 1 {
				for j := i + 1; j < n; j++ {
					if row[j] == 1 {
						t := pair{i, j}
						ans += cnt[t]
						cnt[t]++
					}
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countCornerRectangles(grid: number[][]): number {
    const n = grid[0].length;
    let ans = 0;
    const cnt: Map<number, number> = new Map();
    for (const row of grid) {
        for (let i = 0; i < n; ++i) {
            if (row[i] === 1) {
                for (let j = i + 1; j < n; ++j) {
                    if (row[j] === 1) {
                        const t = i * 200 + j;
                        ans += cnt.get(t) ?? 0;
                        cnt.set(t, (cnt.get(t) ?? 0) + 1);
                    }
                }
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

# [751. IP 到 CIDR 🔒](https://leetcode.cn/problems/ip-to-cidr){#751}

{{< tabs "751" >}}

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

<p><strong>IP地址</strong> 是一个格式化的 32位 无符号整数，每组 8位 被打印为一个十进制数字和，点字符&nbsp;<code>'.'</code>&nbsp;起到了分组的作用。</p>

<ul>
	<li>例如，二进制数 <code>00001111 10001000 11111111 01101011</code>&nbsp;( 为清晰起见增加了空格)被格式化为IP地址将是 <code>“15.136.255.107”</code> 。</li>
</ul>

<p><strong>CIDR块</strong> 是一种用来表示一组特定IP地址的格式。字符串形式，由基础IP地址、斜杠和前缀长度 <code>k</code> 组成。它所覆盖的地址是所有IP地址的 <strong>前 <code>k</code> 位</strong> 与基础IP地址相同的IP地址。</p>

<ul>
	<li>例如， <code>“123.45.67.89/20”</code> 是一个前缀长度为 <code>20</code> 的&nbsp;<strong>CIDR块</strong>。任何二进制表示形式匹配 <code>01111011 00101101 0100xxxx xxxxxxxx</code> 的IP地址，其中 <code>x</code> 可以是 <code>0</code> 或 <code>1</code> ，都在CIDR块覆盖的集合中。</li>
</ul>

<p>给你一个起始IP地址&nbsp;<code>ip</code>&nbsp;和我们需要覆盖的IP地址数量 <code>n</code> 。你的目标是使用 <strong>尽可能少的CIDR块</strong> 来&nbsp;<strong>覆盖范围&nbsp;<code>[ip, ip + n - 1]</code>&nbsp;内的所有IP地址</strong>&nbsp;。不应该覆盖范围之外的其他IP地址。</p>

<p>返回 <em>包含IP地址范围的 <strong>CIDR块</strong> 的 <strong>最短</strong> 列表。如果有多个答案，返回其中 <strong>任何</strong> 一个&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ip = "255.0.0.7", n = 10
<strong>输出：</strong>["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
<strong>解释：
</strong>需要覆盖的IP地址有:
- 255.0.0.7 -&gt; 11111111 00000000 00000000 00000111
- 255.0.0.8 -&gt; 11111111 00000000 00000000 00001000
- 255.0.0.9 -&gt; 11111111 00000000 00000000 00001001
- 255.0.0.10 -&gt; 11111111 00000000 00000000 00001010
- 255.0.0.11 -&gt; 11111111 00000000 00000000 00001011
- 255.0.0.12 -&gt; 11111111 00000000 00000000 00001100
- 255.0.0.13 -&gt; 11111111 00000000 00000000 00001101
- 255.0.0.14 -&gt; 11111111 00000000 00000000 00001110
- 255.0.0.15 -&gt; 11111111 00000000 00000000 00001111
- 255.0.0.16 -&gt; 11111111 00000000 00000000 00010000
CIDR区块“255.0.0.7/32”包含第一个地址。
CIDR区块255.0.0.8/29包含中间的8个地址(二进制格式为11111111 00000000 00000000 00001xxx)。
CIDR区块“255.0.0.16/32”包含最后一个地址。
请注意，虽然CIDR区块“255.0.0.0/28”覆盖了所有的地址，但它也包括范围之外的地址，所以我们不能使用它。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>ip = "117.145.102.62", n = 8
<b>输出：</b>["117.145.102.62/31","117.145.102.64/30","117.145.102.68/31"]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>7 &lt;= ip.length &lt;= 15</code></li>
	<li><code>ip</code>&nbsp;是一个有效的&nbsp;<strong>IPv4</strong>&nbsp;，形式为&nbsp;<code>"a.b.c.d"</code>&nbsp;，其中&nbsp;<code>a</code>,&nbsp;<code>b</code>,&nbsp;<code>c</code>,&nbsp;&nbsp;<code>d</code>&nbsp;是&nbsp;<code>[0, 255]</code>&nbsp;范围内的整数</li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li>每个隐含地址&nbsp;<code>ip + x</code>&nbsp;(&nbsp;<code>x &lt; n</code>) 都是有效的 IPv4 地址</li>
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

# [752. 打开转盘锁](https://leetcode.cn/problems/open-the-lock){#752}

{{< tabs "752" >}}

{{% tab "python" %}}
```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next(s):
            res = []
            s = list(s)
            for i in range(4):
                c = s[i]
                s[i] = '9' if c == '0' else str(int(c) - 1)
                res.append(''.join(s))
                s[i] = '0' if c == '9' else str(int(c) + 1)
                res.append(''.join(s))
                s[i] = c
            return res

        def f(s):
            ans = 0
            for i in range(4):
                a = ord(s[i]) - ord('0')
                b = ord(target[i]) - ord('0')
                if a > b:
                    a, b = b, a
                ans += min(b - a, a + 10 - b)
            return ans

        if target == '0000':
            return 0
        s = set(deadends)
        if '0000' in s:
            return -1
        start = '0000'
        q = [(f(start), start)]
        dist = {start: 0}
        while q:
            _, state = heappop(q)
            if state == target:
                return dist[state]
            for t in next(state):
                if t in s:
                    continue
                if t not in dist or dist[t] > dist[state] + 1:
                    dist[t] = dist[state] + 1
                    heappush(q, (dist[t] + f(t), t))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String target;

    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target)) {
            return 0;
        }
        String start = "0000";
        this.target = target;
        Set<String> s = new HashSet<>();
        for (String d : deadends) {
            s.add(d);
        }
        if (s.contains(start)) {
            return -1;
        }
        PriorityQueue<Pair<Integer, String>> q
            = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
        q.offer(new Pair<>(f(start), start));
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        while (!q.isEmpty()) {
            String state = q.poll().getValue();
            int step = dist.get(state);
            if (target.equals(state)) {
                return step;
            }
            for (String t : next(state)) {
                if (s.contains(t)) {
                    continue;
                }
                if (!dist.containsKey(t) || dist.get(t) > step + 1) {
                    dist.put(t, step + 1);
                    q.offer(new Pair<>(step + 1 + f(t), t));
                }
            }
        }
        return -1;
    }

    private int f(String s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s.charAt(i) - '0';
            int b = target.charAt(i) - '0';
            if (a > b) {
                int t = a;
                a = b;
                b = a;
            }
            ans += Math.min(b - a, a + 10 - b);
        }
        return ans;
    }

    private List<String> next(String t) {
        List res = new ArrayList<>();
        char[] chars = t.toCharArray();
        for (int i = 0; i < 4; ++i) {
            char c = chars[i];
            chars[i] = c == '0' ? '9' : (char) (c - 1);
            res.add(String.valueOf(chars));
            chars[i] = c == '9' ? '0' : (char) (c + 1);
            res.add(String.valueOf(chars));
            chars[i] = c;
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
    string target;

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000")) return -1;
        string start = "0000";
        this->target = target;
        typedef pair<int, string> PIS;
        priority_queue<PIS, vector<PIS>, greater<PIS>> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.push({f(start), start});
        while (!q.empty()) {
            PIS t = q.top();
            q.pop();
            string state = t.second;
            int step = dist[state];
            if (state == target) return step;
            for (string& t : next(state)) {
                if (s.count(t)) continue;
                if (!dist.count(t) || dist[t] > step + 1) {
                    dist[t] = step + 1;
                    q.push({step + 1 + f(t), t});
                }
            }
        }
        return -1;
    }

    int f(string s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s[i] - '0';
            int b = target[i] - '0';
            if (a < b) {
                int t = a;
                a = b;
                b = t;
            }
            ans += min(b - a, a + 10 - b);
        }
        return ans;
    }

    vector<string> next(string& t) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            res.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            res.push_back(t);
            t[i] = c;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func openLock(deadends []string, target string) int {
	if target == "0000" {
		return 0
	}
	s := make(map[string]bool)
	for _, d := range deadends {
		s[d] = true
	}
	if s["0000"] {
		return -1
	}
	next := func(t string) []string {
		s := []byte(t)
		var res []string
		for i, b := range s {
			s[i] = b - 1
			if s[i] < '0' {
				s[i] = '9'
			}
			res = append(res, string(s))
			s[i] = b + 1
			if s[i] > '9' {
				s[i] = '0'
			}
			res = append(res, string(s))
			s[i] = b
		}
		return res
	}

	extend := func(m1, m2 map[string]int, q *[]string) int {
		for n := len(*q); n > 0; n-- {
			p := (*q)[0]
			*q = (*q)[1:]
			step, _ := m1[p]
			for _, t := range next(p) {
				if s[t] {
					continue
				}
				if _, ok := m1[t]; ok {
					continue
				}
				if v, ok := m2[t]; ok {
					return step + 1 + v
				}
				m1[t] = step + 1
				*q = append(*q, t)
			}
		}
		return -1
	}

	bfs := func() int {
		q1 := []string{"0000"}
		q2 := []string{target}
		m1 := map[string]int{"0000": 0}
		m2 := map[string]int{target: 0}
		for len(q1) > 0 && len(q2) > 0 {
			t := -1
			if len(q1) <= len(q2) {
				t = extend(m1, m2, &q1)
			} else {
				t = extend(m2, m1, &q2)
			}
			if t != -1 {
				return t
			}
		}
		return -1
	}

	return bfs()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function openLock(deadends: string[], target: string): number {
    const vis = Array<boolean>(10_000);
    const q = [[0, 0, 0, 0, 0]];
    const t = +target;
    deadends.forEach(s => (vis[+s] = true));

    for (const [a, b, c, d, ans] of q) {
        const key = a * 1000 + b * 100 + c * 10 + d;
        if (vis[key]) {
            continue;
        }

        vis[key] = true;
        if (key === t) {
            return ans;
        }

        for (let i = 0; i < 4; i++) {
            const next = [a, b, c, d, ans + 1];
            const prev = [a, b, c, d, ans + 1];
            next[i] = (next[i] + 11) % 10;
            prev[i] = (prev[i] + 9) % 10;
            q.push(prev, next);
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

<p>你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： <code>'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'</code> 。每个拨轮可以自由旋转：例如把 <code>'9'</code> 变为&nbsp;<code>'0'</code>，<code>'0'</code> 变为 <code>'9'</code> 。每次旋转都只能旋转一个拨轮的一位数字。</p>

<p>锁的初始数字为 <code>'0000'</code> ，一个代表四个拨轮的数字的字符串。</p>

<p>列表 <code>deadends</code> 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。</p>

<p>字符串 <code>target</code> 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>deadends = ["0201","0101","0102","1212","2002"], target = "0202"
<strong>输出：</strong>6
<strong>解释：</strong>
可能的移动序列为 "0000" -&gt; "1000" -&gt; "1100" -&gt; "1200" -&gt; "1201" -&gt; "1202" -&gt; "0202"。
注意 "0000" -&gt; "0001" -&gt; "0002" -&gt; "0102" -&gt; "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> deadends = ["8888"], target = "0009"
<strong>输出：</strong>1
<strong>解释：</strong>把最后一位反向旋转一次即可 "0000" -&gt; "0009"。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
<strong>输出：</strong>-1
<strong>解释：</strong>无法旋转到目标数字且不被锁定。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;deadends.length &lt;= 500</code></li>
	<li><code><font face="monospace">deadends[i].length == 4</font></code></li>
	<li><code><font face="monospace">target.length == 4</font></code></li>
	<li><code>target</code> <strong>不在</strong> <code>deadends</code> 之中</li>
	<li><code>target</code> 和 <code>deadends[i]</code> 仅由若干位数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：朴素 BFS

直接用朴素 BFS。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next(s):
            res = []
            s = list(s)
            for i in range(4):
                c = s[i]
                s[i] = '9' if c == '0' else str(int(c) - 1)
                res.append(''.join(s))
                s[i] = '0' if c == '9' else str(int(c) + 1)
                res.append(''.join(s))
                s[i] = c
            return res

        if target == '0000':
            return 0
        s = set(deadends)
        if '0000' in s:
            return -1
        q = deque([('0000')])
        s.add('0000')
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                p = q.popleft()
                for t in next(p):
                    if t == target:
                        return ans
                    if t not in s:
                        q.append(t)
                        s.add(t)
        return -1
```

#### Java

```java
class Solution {
    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target)) {
            return 0;
        }
        Set<String> s = new HashSet<>(Arrays.asList(deadends));
        if (s.contains("0000")) {
            return -1;
        }
        Deque<String> q = new ArrayDeque<>();
        q.offer("0000");
        s.add("0000");
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int n = q.size(); n > 0; --n) {
                String p = q.poll();
                for (String t : next(p)) {
                    if (target.equals(t)) {
                        return ans;
                    }
                    if (!s.contains(t)) {
                        q.offer(t);
                        s.add(t);
                    }
                }
            }
        }
        return -1;
    }

    private List<String> next(String t) {
        List res = new ArrayList<>();
        char[] chars = t.toCharArray();
        for (int i = 0; i < 4; ++i) {
            char c = chars[i];
            chars[i] = c == '0' ? '9' : (char) (c - 1);
            res.add(String.valueOf(chars));
            chars[i] = c == '9' ? '0' : (char) (c + 1);
            res.add(String.valueOf(chars));
            chars[i] = c;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000")) return -1;
        if (target == "0000") return 0;
        queue<string> q{{"0000"}};
        s.insert("0000");
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int n = q.size(); n > 0; --n) {
                string p = q.front();
                q.pop();
                for (string t : next(p)) {
                    if (target == t) return ans;
                    if (!s.count(t)) {
                        q.push(t);
                        s.insert(t);
                    }
                }
            }
        }
        return -1;
    }

    vector<string> next(string& t) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            res.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            res.push_back(t);
            t[i] = c;
        }
        return res;
    }
};
```

#### Go

```go
func openLock(deadends []string, target string) int {
	if target == "0000" {
		return 0
	}
	s := make(map[string]bool)
	for _, d := range deadends {
		s[d] = true
	}
	if s["0000"] {
		return -1
	}
	q := []string{"0000"}
	s["0000"] = true
	ans := 0
	next := func(t string) []string {
		s := []byte(t)
		var res []string
		for i, b := range s {
			s[i] = b - 1
			if s[i] < '0' {
				s[i] = '9'
			}
			res = append(res, string(s))
			s[i] = b + 1
			if s[i] > '9' {
				s[i] = '0'
			}
			res = append(res, string(s))
			s[i] = b
		}
		return res
	}
	for len(q) > 0 {
		ans++
		for n := len(q); n > 0; n-- {
			p := q[0]
			q = q[1:]
			for _, t := range next(p) {
				if target == t {
					return ans
				}
				if !s[t] {
					q = append(q, t)
					s[t] = true
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function openLock(deadends: string[], target: string): number {
    const vis = Array<boolean>(10_000);
    const q = [[0, 0, 0, 0, 0]];
    const t = +target;
    deadends.forEach(s => (vis[+s] = true));

    for (const [a, b, c, d, ans] of q) {
        const key = a * 1000 + b * 100 + c * 10 + d;
        if (vis[key]) {
            continue;
        }

        vis[key] = true;
        if (key === t) {
            return ans;
        }

        for (let i = 0; i < 4; i++) {
            const next = [a, b, c, d, ans + 1];
            const prev = [a, b, c, d, ans + 1];
            next[i] = (next[i] + 11) % 10;
            prev[i] = (prev[i] + 9) % 10;
            q.push(prev, next);
        }
    }

    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双向 BFS

本题也可以用双向 BFS 优化搜索空间，从而提升效率。

双向 BFS 是 BFS 常见的一个优化方法，主要实现思路如下：

1. 创建两个队列 q1, q2 分别用于“起点 -> 终点”、“终点 -> 起点”两个方向的搜索；
2. 创建两个哈希表 m1, m2 分别记录访问过的节点以及对应的扩展次数（步数）；
3. 每次搜索时，优先选择元素数量较少的队列进行搜索扩展，如果在扩展过程中，搜索到另一个方向已经访问过的节点，说明找到了最短路径；
4. 只要其中一个队列为空，说明当前方向的搜索已经进行不下去了，说明起点到终点不连通，无需继续搜索。

```python
while q1 and q2:
    if len(q1) <= len(q2):
        # 优先选择较少元素的队列进行扩展
        extend(m1, m2, q1)
    else:
        extend(m2, m1, q2)


def extend(m1, m2, q):
    # 新一轮扩展
    for _ in range(len(q)):
        p = q.popleft()
        step = m1[p]
        for t in next(p):
            if t in m1:
                # 此前已经访问过
                continue
            if t in m2:
                # 另一个方向已经搜索过，说明找到了一条最短的连通路径
                return step + 1 + m2[t]
            q.append(t)
            m1[t] = step + 1
```

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next(s):
            res = []
            s = list(s)
            for i in range(4):
                c = s[i]
                s[i] = '9' if c == '0' else str(int(c) - 1)
                res.append(''.join(s))
                s[i] = '0' if c == '9' else str(int(c) + 1)
                res.append(''.join(s))
                s[i] = c
            return res

        def extend(m1, m2, q):
            for _ in range(len(q)):
                p = q.popleft()
                step = m1[p]
                for t in next(p):
                    if t in s or t in m1:
                        continue
                    if t in m2:
                        return step + 1 + m2[t]
                    m1[t] = step + 1
                    q.append(t)
            return -1

        def bfs():
            m1, m2 = {"0000": 0}, {target: 0}
            q1, q2 = deque([('0000')]), deque([(target)])
            while q1 and q2:
                t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
                if t != -1:
                    return t
            return -1

        if target == '0000':
            return 0
        s = set(deadends)
        if '0000' in s:
            return -1
        return bfs()
```

#### Java

```java
class Solution {
    private String start;
    private String target;
    private Set<String> s = new HashSet<>();

    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target)) {
            return 0;
        }
        start = "0000";
        this.target = target;
        for (String d : deadends) {
            s.add(d);
        }
        if (s.contains(start)) {
            return -1;
        }
        return bfs();
    }

    private int bfs() {
        Map<String, Integer> m1 = new HashMap<>();
        Map<String, Integer> m2 = new HashMap<>();
        Deque<String> q1 = new ArrayDeque<>();
        Deque<String> q2 = new ArrayDeque<>();
        m1.put(start, 0);
        m2.put(target, 0);
        q1.offer(start);
        q2.offer(target);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<String, Integer> m1, Map<String, Integer> m2, Deque<String> q) {
        for (int n = q.size(); n > 0; --n) {
            String p = q.poll();
            int step = m1.get(p);
            for (String t : next(p)) {
                if (m1.containsKey(t) || s.contains(t)) {
                    continue;
                }
                if (m2.containsKey(t)) {
                    return step + 1 + m2.get(t);
                }
                m1.put(t, step + 1);
                q.offer(t);
            }
        }
        return -1;
    }

    private List<String> next(String t) {
        List res = new ArrayList<>();
        char[] chars = t.toCharArray();
        for (int i = 0; i < 4; ++i) {
            char c = chars[i];
            chars[i] = c == '0' ? '9' : (char) (c - 1);
            res.add(String.valueOf(chars));
            chars[i] = c == '9' ? '0' : (char) (c + 1);
            res.add(String.valueOf(chars));
            chars[i] = c;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    unordered_set<string> s;
    string start;
    string target;

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        for (auto d : deadends) s.insert(d);
        if (s.count("0000")) return -1;
        this->start = "0000";
        this->target = target;
        return bfs();
    }

    int bfs() {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        m1[start] = 0;
        m2[target] = 0;
        queue<string> q1{{start}};
        queue<string> q2{{target}};
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<string, int>& m1, unordered_map<string, int>& m2, queue<string>& q) {
        for (int n = q.size(); n > 0; --n) {
            string p = q.front();
            int step = m1[p];
            q.pop();
            for (string t : next(p)) {
                if (s.count(t) || m1.count(t)) continue;
                if (m2.count(t)) return step + 1 + m2[t];
                m1[t] = step + 1;
                q.push(t);
            }
        }
        return -1;
    }

    vector<string> next(string& t) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            res.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            res.push_back(t);
            t[i] = c;
        }
        return res;
    }
};
```

#### Go

```go
func openLock(deadends []string, target string) int {
	if target == "0000" {
		return 0
	}
	s := make(map[string]bool)
	for _, d := range deadends {
		s[d] = true
	}
	if s["0000"] {
		return -1
	}
	next := func(t string) []string {
		s := []byte(t)
		var res []string
		for i, b := range s {
			s[i] = b - 1
			if s[i] < '0' {
				s[i] = '9'
			}
			res = append(res, string(s))
			s[i] = b + 1
			if s[i] > '9' {
				s[i] = '0'
			}
			res = append(res, string(s))
			s[i] = b
		}
		return res
	}

	extend := func(m1, m2 map[string]int, q *[]string) int {
		for n := len(*q); n > 0; n-- {
			p := (*q)[0]
			*q = (*q)[1:]
			step, _ := m1[p]
			for _, t := range next(p) {
				if s[t] {
					continue
				}
				if _, ok := m1[t]; ok {
					continue
				}
				if v, ok := m2[t]; ok {
					return step + 1 + v
				}
				m1[t] = step + 1
				*q = append(*q, t)
			}
		}
		return -1
	}

	bfs := func() int {
		q1 := []string{"0000"}
		q2 := []string{target}
		m1 := map[string]int{"0000": 0}
		m2 := map[string]int{target: 0}
		for len(q1) > 0 && len(q2) > 0 {
			t := -1
			if len(q1) <= len(q2) {
				t = extend(m1, m2, &q1)
			} else {
				t = extend(m2, m1, &q2)
			}
			if t != -1 {
				return t
			}
		}
		return -1
	}

	return bfs()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：A\*算法

A\* 算法主要思想如下：

1. 将 BFS 队列转换为优先队列（小根堆）；
1. 队列中的每个元素为 `(dist[state] + f(state), state)`，`dist[state]` 表示从起点到当前 state 的距离，`f(state)` 表示从当前 state 到终点的估计距离，这两个距离之和作为堆排序的依据；
1. 当终点第一次出队时，说明找到了从起点到终点的最短路径，直接返回对应的 step；
1. `f(state)` 是估价函数，并且估价函数要满足 `f(state) <= g(state)`，其中 `g(state)` 表示 state 到终点的真实距离；
1. A\* 算法只能保证终点第一次出队时，即找到了一条从起点到终点的最小路径，不能保证其他点出队时也是从起点到当前点的最短路径。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next(s):
            res = []
            s = list(s)
            for i in range(4):
                c = s[i]
                s[i] = '9' if c == '0' else str(int(c) - 1)
                res.append(''.join(s))
                s[i] = '0' if c == '9' else str(int(c) + 1)
                res.append(''.join(s))
                s[i] = c
            return res

        def f(s):
            ans = 0
            for i in range(4):
                a = ord(s[i]) - ord('0')
                b = ord(target[i]) - ord('0')
                if a > b:
                    a, b = b, a
                ans += min(b - a, a + 10 - b)
            return ans

        if target == '0000':
            return 0
        s = set(deadends)
        if '0000' in s:
            return -1
        start = '0000'
        q = [(f(start), start)]
        dist = {start: 0}
        while q:
            _, state = heappop(q)
            if state == target:
                return dist[state]
            for t in next(state):
                if t in s:
                    continue
                if t not in dist or dist[t] > dist[state] + 1:
                    dist[t] = dist[state] + 1
                    heappush(q, (dist[t] + f(t), t))
        return -1
```

#### Java

```java
class Solution {
    private String target;

    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target)) {
            return 0;
        }
        String start = "0000";
        this.target = target;
        Set<String> s = new HashSet<>();
        for (String d : deadends) {
            s.add(d);
        }
        if (s.contains(start)) {
            return -1;
        }
        PriorityQueue<Pair<Integer, String>> q
            = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
        q.offer(new Pair<>(f(start), start));
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        while (!q.isEmpty()) {
            String state = q.poll().getValue();
            int step = dist.get(state);
            if (target.equals(state)) {
                return step;
            }
            for (String t : next(state)) {
                if (s.contains(t)) {
                    continue;
                }
                if (!dist.containsKey(t) || dist.get(t) > step + 1) {
                    dist.put(t, step + 1);
                    q.offer(new Pair<>(step + 1 + f(t), t));
                }
            }
        }
        return -1;
    }

    private int f(String s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s.charAt(i) - '0';
            int b = target.charAt(i) - '0';
            if (a > b) {
                int t = a;
                a = b;
                b = a;
            }
            ans += Math.min(b - a, a + 10 - b);
        }
        return ans;
    }

    private List<String> next(String t) {
        List res = new ArrayList<>();
        char[] chars = t.toCharArray();
        for (int i = 0; i < 4; ++i) {
            char c = chars[i];
            chars[i] = c == '0' ? '9' : (char) (c - 1);
            res.add(String.valueOf(chars));
            chars[i] = c == '9' ? '0' : (char) (c + 1);
            res.add(String.valueOf(chars));
            chars[i] = c;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string target;

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000")) return -1;
        string start = "0000";
        this->target = target;
        typedef pair<int, string> PIS;
        priority_queue<PIS, vector<PIS>, greater<PIS>> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.push({f(start), start});
        while (!q.empty()) {
            PIS t = q.top();
            q.pop();
            string state = t.second;
            int step = dist[state];
            if (state == target) return step;
            for (string& t : next(state)) {
                if (s.count(t)) continue;
                if (!dist.count(t) || dist[t] > step + 1) {
                    dist[t] = step + 1;
                    q.push({step + 1 + f(t), t});
                }
            }
        }
        return -1;
    }

    int f(string s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s[i] - '0';
            int b = target[i] - '0';
            if (a < b) {
                int t = a;
                a = b;
                b = t;
            }
            ans += min(b - a, a + 10 - b);
        }
        return ans;
    }

    vector<string> next(string& t) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            res.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            res.push_back(t);
            t[i] = c;
        }
        return res;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [753. 破解保险箱](https://leetcode.cn/problems/cracking-the-safe){#753}

{{< tabs "753" >}}

{{% tab "python" %}}
```python
class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        def dfs(u):
            for x in range(k):
                e = u * 10 + x
                if e not in vis:
                    vis.add(e)
                    v = e % mod
                    dfs(v)
                    ans.append(str(x))

        mod = 10 ** (n - 1)
        vis = set()
        ans = []
        dfs(0)
        ans.append("0" * (n - 1))
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<Integer> vis = new HashSet<>();
    private StringBuilder ans = new StringBuilder();
    private int mod;

    public String crackSafe(int n, int k) {
        mod = (int) Math.pow(10, n - 1);
        dfs(0, k);
        ans.append("0".repeat(n - 1));
        return ans.toString();
    }

    private void dfs(int u, int k) {
        for (int x = 0; x < k; ++x) {
            int e = u * 10 + x;
            if (vis.add(e)) {
                int v = e % mod;
                dfs(v, k);
                ans.append(x);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<int> vis;
        int mod = pow(10, n - 1);
        string ans;
        function<void(int)> dfs = [&](int u) {
            for (int x = 0; x < k; ++x) {
                int e = u * 10 + x;
                if (!vis.count(e)) {
                    vis.insert(e);
                    dfs(e % mod);
                    ans += (x + '0');
                }
            }
        };
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func crackSafe(n int, k int) string {
	mod := int(math.Pow(10, float64(n-1)))
	vis := map[int]bool{}
	ans := &strings.Builder{}
	var dfs func(int)
	dfs = func(u int) {
		for x := 0; x < k; x++ {
			e := u*10 + x
			if !vis[e] {
				vis[e] = true
				v := e % mod
				dfs(v)
				ans.WriteByte(byte('0' + x))
			}
		}
	}
	dfs(0)
	ans.WriteString(strings.Repeat("0", n-1))
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function crackSafe(n: number, k: number): string {
    function dfs(u: number): void {
        for (let x = 0; x < k; x++) {
            const e = u * 10 + x;
            if (!vis.has(e)) {
                vis.add(e);
                const v = e % mod;
                dfs(v);
                ans.push(x.toString());
            }
        }
    }

    const mod = Math.pow(10, n - 1);
    const vis = new Set<number>();
    const ans: string[] = [];

    dfs(0);
    ans.push('0'.repeat(n - 1));
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个需要密码才能打开的保险箱。密码是&nbsp;<code>n</code> 位数, 密码的每一位都是范围&nbsp;<code>[0, k - 1]</code>&nbsp;中的一个数字。</p>

<p>保险箱有一种特殊的密码校验方法，你可以随意输入密码序列，保险箱会自动记住 <strong>最后&nbsp;<code>n</code>&nbsp;位输入</strong> ，如果匹配，则能够打开保险箱。</p>

<ul>
	<li>例如，正确的密码是 <code>"345"</code> ，并且你输入的是 <code>"012345"</code> ：

    <ul>
    	<li>输入 <code>0</code> 之后，最后 <code>3</code> 位输入是 <code>"0"</code> ，不正确。</li>
    	<li>输入 <code>1</code> 之后，最后 <code>3</code> 位输入是 <code>"01"</code> ，不正确。</li>
    	<li>输入 <code>2</code> 之后，最后 <code>3</code> 位输入是 <code>"012"</code> ，不正确。</li>
    	<li>输入 <code>3</code> 之后，最后 <code>3</code> 位输入是 <code>"123"</code> ，不正确。</li>
    	<li>输入 <code>4</code> 之后，最后 <code>3</code> 位输入是 <code>"234"</code> ，不正确。</li>
    	<li>输入 <code>5</code> 之后，最后 <code>3</code> 位输入是 <code>"345"</code> ，正确，打开保险箱。</li>
    </ul>
    </li>

</ul>

<p>在只知道密码位数 <code>n</code> 和范围边界 <code>k</code> 的前提下，请你找出并返回确保在输入的 <strong>某个时刻</strong> 能够打开保险箱的任一 <strong>最短</strong> 密码序列 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 2
<strong>输出：</strong>"10"
<strong>解释：</strong>密码只有 1 位，所以输入每一位就可以。"01" 也能够确保打开保险箱。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 2
<strong>输出：</strong>"01100"
<strong>解释：</strong>对于每种可能的密码：
- "00" 从第 4 位开始输入。
- "01" 从第 1 位开始输入。
- "10" 从第 3 位开始输入。
- "11" 从第 2 位开始输入。
因此 "01100" 可以确保打开保险箱。"01100"、"10011" 和 "11001" 也可以确保打开保险箱。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>1 &lt;= k<sup>n</sup> &lt;= 4096</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：欧拉回路

我们可以对题目中所描述的内容构建有向图：将每个点看作一个长度为 $n-1$ 的 $k$ 字符串，每条边都带有一个从 $0$ 到 $k-1$ 的字符。如果点 $u$ 到点 $v$ 之间有一条有向边 $e$，假设 $e$ 携带的字符为 $c$，那么 $u+c$ 的末尾 $k-1$ 个字符形成的字符串等于 $v$，此时边 $u+c$ 就表示了一个长度为 $n$ 的密码。

在这个有向图中，一共有 $k^{n-1}$ 个点，每个点都有 $k$ 条出边，也有 $k$ 条入边，因此，该有向图存在欧拉回路，欧拉回路所经过的路径拼接起来就是题目中的答案。

时间复杂度 $O(k^n)$，空间复杂度 $O(k^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        def dfs(u):
            for x in range(k):
                e = u * 10 + x
                if e not in vis:
                    vis.add(e)
                    v = e % mod
                    dfs(v)
                    ans.append(str(x))

        mod = 10 ** (n - 1)
        vis = set()
        ans = []
        dfs(0)
        ans.append("0" * (n - 1))
        return "".join(ans)
```

#### Java

```java
class Solution {
    private Set<Integer> vis = new HashSet<>();
    private StringBuilder ans = new StringBuilder();
    private int mod;

    public String crackSafe(int n, int k) {
        mod = (int) Math.pow(10, n - 1);
        dfs(0, k);
        ans.append("0".repeat(n - 1));
        return ans.toString();
    }

    private void dfs(int u, int k) {
        for (int x = 0; x < k; ++x) {
            int e = u * 10 + x;
            if (vis.add(e)) {
                int v = e % mod;
                dfs(v, k);
                ans.append(x);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<int> vis;
        int mod = pow(10, n - 1);
        string ans;
        function<void(int)> dfs = [&](int u) {
            for (int x = 0; x < k; ++x) {
                int e = u * 10 + x;
                if (!vis.count(e)) {
                    vis.insert(e);
                    dfs(e % mod);
                    ans += (x + '0');
                }
            }
        };
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
```

#### Go

```go
func crackSafe(n int, k int) string {
	mod := int(math.Pow(10, float64(n-1)))
	vis := map[int]bool{}
	ans := &strings.Builder{}
	var dfs func(int)
	dfs = func(u int) {
		for x := 0; x < k; x++ {
			e := u*10 + x
			if !vis[e] {
				vis[e] = true
				v := e % mod
				dfs(v)
				ans.WriteByte(byte('0' + x))
			}
		}
	}
	dfs(0)
	ans.WriteString(strings.Repeat("0", n-1))
	return ans.String()
}
```

#### TypeScript

```ts
function crackSafe(n: number, k: number): string {
    function dfs(u: number): void {
        for (let x = 0; x < k; x++) {
            const e = u * 10 + x;
            if (!vis.has(e)) {
                vis.add(e);
                const v = e % mod;
                dfs(v);
                ans.push(x.toString());
            }
        }
    }

    const mod = Math.pow(10, n - 1);
    const vis = new Set<number>();
    const ans: string[] = [];

    dfs(0);
    ans.push('0'.repeat(n - 1));
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [754. 到达终点数字](https://leetcode.cn/problems/reach-a-number){#754}

{{< tabs "754" >}}

{{% tab "python" %}}
```python
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        s = k = 0
        while 1:
            if s >= target and (s - target) % 2 == 0:
                return k
            k += 1
            s += k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int s = 0, k = 0;
        while (true) {
            if (s >= target && (s - target) % 2 == 0) {
                return k;
            }
            ++k;
            s += k;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 0, k = 0;
        while (1) {
            if (s >= target && (s - target) % 2 == 0) return k;
            ++k;
            s += k;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reachNumber(target int) int {
	if target < 0 {
		target = -target
	}
	var s, k int
	for {
		if s >= target && (s-target)%2 == 0 {
			return k
		}
		k++
		s += k
	}
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} target
 * @return {number}
 */
var reachNumber = function (target) {
    target = Math.abs(target);
    let [s, k] = [0, 0];
    while (1) {
        if (s >= target && (s - target) % 2 == 0) {
            return k;
        }
        ++k;
        s += k;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一根无限长的数轴上，你站在<code>0</code>的位置。终点在<code>target</code>的位置。</p>

<p>你可以做一些数量的移动 <code>numMoves</code> :</p>

<ul>
	<li>每次你可以选择向左或向右移动。</li>
	<li>第 <code>i</code>&nbsp;次移动（从 &nbsp;<code>i == 1</code>&nbsp;开始，到&nbsp;<code>i == numMoves</code> ），在选择的方向上走 <code>i</code>&nbsp;步。</li>
</ul>

<p>给定整数&nbsp;<code>target</code> ，返回 <em>到达目标所需的 <strong>最小&nbsp;</strong>移动次数(即最小 <code>numMoves</code> )&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> target = 2
<strong>输出:</strong> 3
<strong>解释:</strong>
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> target = 3
<strong>输出:</strong> 2
<strong>解释:</strong>
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>target != 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学分析

由于对称性，每次可以选择向左或向右移动，因此，我们可以将 $\textit{target}$ 统一取绝对值。

定义 $s$ 表示当前所处的位置，用变量 $k$ 记录移动的次数。初始时 $s$ 和 $k$ 均为 $0$。

我们将 $s$ 一直循环累加，直到满足 $s\ge \textit{target}$ 并且 $(s-\textit{target}) \bmod 2 = 0$，此时的移动次数 $k$ 就是答案，直接返回。

为什么？因为如果 $s\ge \textit{target}$ 且 $(s-\textit{target})\mod 2 = 0$，我们只需要把前面 $\frac{s-\textit{target}}{2}$ 这个正整数变为负数，就能使得 $s$ 与 $\textit{target}$ 相等。正整数变负数的过程，实际上是将移动的方向改变，但实际移动次数仍然不变。

时间复杂度 $O(\sqrt{\left | \textit{target} \right | })$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        s = k = 0
        while 1:
            if s >= target and (s - target) % 2 == 0:
                return k
            k += 1
            s += k
```

#### Java

```java
class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int s = 0, k = 0;
        while (true) {
            if (s >= target && (s - target) % 2 == 0) {
                return k;
            }
            ++k;
            s += k;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 0, k = 0;
        while (1) {
            if (s >= target && (s - target) % 2 == 0) return k;
            ++k;
            s += k;
        }
    }
};
```

#### Go

```go
func reachNumber(target int) int {
	if target < 0 {
		target = -target
	}
	var s, k int
	for {
		if s >= target && (s-target)%2 == 0 {
			return k
		}
		k++
		s += k
	}
}
```

#### JavaScript

```js
/**
 * @param {number} target
 * @return {number}
 */
var reachNumber = function (target) {
    target = Math.abs(target);
    let [s, k] = [0, 0];
    while (1) {
        if (s >= target && (s - target) % 2 == 0) {
            return k;
        }
        ++k;
        s += k;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [755. 倒水 🔒](https://leetcode.cn/problems/pour-water){#755}

{{< tabs "755" >}}

{{% tab "python" %}}
```python
class Solution:
    def pourWater(self, heights: List[int], volume: int, k: int) -> List[int]:
        for _ in range(volume):
            for d in (-1, 1):
                i = j = k
                while 0 <= i + d < len(heights) and heights[i + d] <= heights[i]:
                    if heights[i + d] < heights[i]:
                        j = i + d
                    i += d
                if j != k:
                    heights[j] += 1
                    break
            else:
                heights[k] += 1
        return heights
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] pourWater(int[] heights, int volume, int k) {
        while (volume-- > 0) {
            boolean find = false;
            for (int d = -1; d < 2 && !find; d += 2) {
                int i = k, j = k;
                while (i + d >= 0 && i + d < heights.length && heights[i + d] <= heights[i]) {
                    if (heights[i + d] < heights[i]) {
                        j = i + d;
                    }
                    i += d;
                }
                if (j != k) {
                    find = true;
                    ++heights[j];
                }
            }
            if (!find) {
                ++heights[k];
            }
        }
        return heights;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        while (volume--) {
            bool find = false;
            for (int d = -1; d < 2 && !find; d += 2) {
                int i = k, j = k;
                while (i + d >= 0 && i + d < heights.size() && heights[i + d] <= heights[i]) {
                    if (heights[i + d] < heights[i]) {
                        j = i + d;
                    }
                    i += d;
                }
                if (j != k) {
                    find = true;
                    ++heights[j];
                }
            }
            if (!find) {
                ++heights[k];
            }
        }
        return heights;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pourWater(heights []int, volume int, k int) []int {
	for ; volume > 0; volume-- {
		find := false
		for _, d := range [2]int{-1, 1} {
			i, j := k, k
			for i+d >= 0 && i+d < len(heights) && heights[i+d] <= heights[i] {
				if heights[i+d] < heights[i] {
					j = i + d
				}
				i += d
			}
			if j != k {
				find = true
				heights[j]++
				break
			}
		}
		if !find {
			heights[k]++
		}
	}
	return heights
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个地形高度图， <code>heights[i]</code> 表示该索引处的高度。每个索引的宽度为 1。在 <code>V</code> 个单位的水落在索引 <code>K</code> 处以后，每个索引位置有多少水？</p>

<p>水最先会在索引 <code>K</code> 处下降并且落在该索引位置的最高地形或水面之上。然后按如下方式流动：</p>

<ul>
	<li>如果液滴最终可以通过向左流动而下降，则向左流动。</li>
	<li>否则，如果液滴最终可以通过向右流动而下降，则向右流动。</li>
	<li>否则，在当前的位置上升。</li>
	<li>这里，“最终下降” 的意思是液滴如果按此方向移动的话，最终可以下降到一个较低的水平。而且，“水平”的意思是当前列的地形的高度加上水的高度。</li>
</ul>

<p>我们可以假定在数组两侧的边界外有无限高的地形。而且，不能有部分水在多于 1 个的网格块上均匀分布 - 每个单位的水必须要位于一个块中。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>heights = [2,1,1,2,1,2,2], V = 4, K = 3
<strong>输出：</strong>[2,2,2,3,2,2,2]
<strong>解释：</strong>
#       #
#       #
##  # ###
#########
 0123456    <- 索引

第一个水滴降落在索引 K = 3 上：

#       #
#   w   #
##  # ###
#########
 0123456    

当向左或向右移动时，水可以移动到相同或更低的高度。When moving left or right, the water can only move to the same level or a lower level.
（从水平上看，意思是该列的地形高度加上水的高度）
由于向左移动可以最终下落，因此向左移动。
（一个水滴 “下落” 的意思是可以相比之前可以进入更低的高度）

#       #
#       #
## w# ###
#########
 0123456    

由于向左移动不会使其降落，所以停在该位置上。下一个水滴下落：

#       #
#   w   #
## w# ###
#########
 0123456  


由于新水滴向左移动可以最终下落，因此向左移动。
注意水滴仍然是优先选择向左移动，
尽管可以向右移动（而且向右移动可以下落更快）


#       #
#  w    #
## w# ###
#########
 0123456  

#       #
#       #
##ww# ###
#########
 0123456  

经过刚才的阶段后，第三个水滴下落。
由于向左移动不会最终下落，因此尝试向右移动。
由于向右移动可以最终下落，因此向右移动。


#       #
#   w   #
##ww# ###
#########
 0123456  

#       #
#       #
##ww#w###
#########
 0123456  

最终，第四个水滴下落。
由于向左移动不会最终下落，因此尝试向右移动。
由于向右移动不会最终下落，因此停在当前位置：

#       #
#   w   #
##ww#w###
#########
 0123456  

最终的答案为 [2,2,2,3,2,2,2]:

    #    
 ####### 
 ####### 
 0123456 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>heights = [1,2,3,4], V = 2, K = 2
<strong>输出：</strong>[2,3,3,4]
<strong>解释：</strong>
最后的水滴落在索引 1 位置，因为继续向左移动不会使其下降到更低的高度。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>heights = [3,1,3], V = 5, K = 1
<strong>输出：</strong>[4,4,4]
</pre>

<p> </p>

<p><strong>注：</strong></p>

<ol>
	<li><code>heights</code> 的长度为 <code>[1, 100]</code> ，并且每个数的范围为<code>[0, 99]</code>。</li>
	<li><code>V</code> 的范围 <code>[0, 2000]</code>。</li>
	<li><code>K</code> 的范围 <code>[0, heights.length - 1]</code>。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟每一单位的水滴下落的过程，每次下落时，我们首先尝试向左移动，如果可以移动到更低的高度，则移动到最低的高度处；如果不能移动到更低的高度，则尝试向右移动，如果可以移动到更低的高度，则移动到最低的高度处；如果不能移动到更低的高度，则在当前位置上升。

时间复杂度 $O(v \times n)，空间复杂度 O(1)$。其中 $v$ 和 $n$ 分别是水滴的数量和高度数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pourWater(self, heights: List[int], volume: int, k: int) -> List[int]:
        for _ in range(volume):
            for d in (-1, 1):
                i = j = k
                while 0 <= i + d < len(heights) and heights[i + d] <= heights[i]:
                    if heights[i + d] < heights[i]:
                        j = i + d
                    i += d
                if j != k:
                    heights[j] += 1
                    break
            else:
                heights[k] += 1
        return heights
```

#### Java

```java
class Solution {
    public int[] pourWater(int[] heights, int volume, int k) {
        while (volume-- > 0) {
            boolean find = false;
            for (int d = -1; d < 2 && !find; d += 2) {
                int i = k, j = k;
                while (i + d >= 0 && i + d < heights.length && heights[i + d] <= heights[i]) {
                    if (heights[i + d] < heights[i]) {
                        j = i + d;
                    }
                    i += d;
                }
                if (j != k) {
                    find = true;
                    ++heights[j];
                }
            }
            if (!find) {
                ++heights[k];
            }
        }
        return heights;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        while (volume--) {
            bool find = false;
            for (int d = -1; d < 2 && !find; d += 2) {
                int i = k, j = k;
                while (i + d >= 0 && i + d < heights.size() && heights[i + d] <= heights[i]) {
                    if (heights[i + d] < heights[i]) {
                        j = i + d;
                    }
                    i += d;
                }
                if (j != k) {
                    find = true;
                    ++heights[j];
                }
            }
            if (!find) {
                ++heights[k];
            }
        }
        return heights;
    }
};
```

#### Go

```go
func pourWater(heights []int, volume int, k int) []int {
	for ; volume > 0; volume-- {
		find := false
		for _, d := range [2]int{-1, 1} {
			i, j := k, k
			for i+d >= 0 && i+d < len(heights) && heights[i+d] <= heights[i] {
				if heights[i+d] < heights[i] {
					j = i + d
				}
				i += d
			}
			if j != k {
				find = true
				heights[j]++
				break
			}
		}
		if !find {
			heights[k]++
		}
	}
	return heights
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [756. 金字塔转换矩阵](https://leetcode.cn/problems/pyramid-transition-matrix){#756}

{{< tabs "756" >}}

{{% tab "python" %}}
```python
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        @cache
        def dfs(s):
            if len(s) == 1:
                return True
            t = []
            for a, b in pairwise(s):
                cs = d[a, b]
                if not cs:
                    return False
                t.append(cs)
            return any(dfs(''.join(nxt)) for nxt in product(*t))

        d = defaultdict(list)
        for a, b, c in allowed:
            d[a, b].append(c)
        return dfs(bottom)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] f = new int[7][7];
    private Map<String, Boolean> dp = new HashMap<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (String s : allowed) {
            int a = s.charAt(0) - 'A', b = s.charAt(1) - 'A';
            f[a][b] |= 1 << (s.charAt(2) - 'A');
        }
        return dfs(bottom, new StringBuilder());
    }

    boolean dfs(String s, StringBuilder t) {
        if (s.length() == 1) {
            return true;
        }
        if (t.length() + 1 == s.length()) {
            return dfs(t.toString(), new StringBuilder());
        }
        String k = s + "." + t.toString();
        if (dp.containsKey(k)) {
            return dp.get(k);
        }
        int a = s.charAt(t.length()) - 'A', b = s.charAt(t.length() + 1) - 'A';
        int cs = f[a][b];
        for (int i = 0; i < 7; ++i) {
            if (((cs >> i) & 1) == 1) {
                t.append((char) ('A' + i));
                if (dfs(s, t)) {
                    dp.put(k, true);
                    return true;
                }
                t.deleteCharAt(t.length() - 1);
            }
        }
        dp.put(k, false);
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int f[7][7];
    unordered_map<string, bool> dp;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(f, 0, sizeof f);
        for (auto& s : allowed) {
            int a = s[0] - 'A', b = s[1] - 'A';
            f[a][b] |= 1 << (s[2] - 'A');
        }
        return dfs(bottom, "");
    }

    bool dfs(string& s, string t) {
        if (s.size() == 1) {
            return true;
        }
        if (t.size() + 1 == s.size()) {
            return dfs(t, "");
        }
        string k = s + "." + t;
        if (dp.count(k)) {
            return dp[k];
        }
        int a = s[t.size()] - 'A', b = s[t.size() + 1] - 'A';
        int cs = f[a][b];
        for (int i = 0; i < 7; ++i) {
            if ((cs >> i) & 1) {
                if (dfs(s, t + (char) (i + 'A'))) {
                    dp[k] = true;
                    return true;
                }
            }
        }
        dp[k] = false;
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pyramidTransition(bottom string, allowed []string) bool {
	f := make([][]int, 7)
	for i := range f {
		f[i] = make([]int, 7)
	}
	for _, s := range allowed {
		a, b := s[0]-'A', s[1]-'A'
		f[a][b] |= 1 << (s[2] - 'A')
	}
	dp := map[string]bool{}
	var dfs func(s string, t []byte) bool
	dfs = func(s string, t []byte) bool {
		if len(s) == 1 {
			return true
		}
		if len(t)+1 == len(s) {
			return dfs(string(t), []byte{})
		}
		k := s + "." + string(t)
		if v, ok := dp[k]; ok {
			return v
		}
		a, b := s[len(t)]-'A', s[len(t)+1]-'A'
		cs := f[a][b]
		for i := 0; i < 7; i++ {
			if ((cs >> i) & 1) == 1 {
				t = append(t, byte('A'+i))
				if dfs(s, t) {
					dp[k] = true
					return true
				}
				t = t[:len(t)-1]
			}
		}
		dp[k] = false
		return false
	}
	return dfs(bottom, []byte{})
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在把积木堆成金字塔。每个块都有一个颜色，用一个字母表示。每一行的块比它下面的行 <strong>少一个块</strong> ，并且居中。</p>

<p>为了使金字塔美观，只有特定的 <strong>三角形图案</strong> 是允许的。一个三角形的图案由&nbsp;<strong>两个块</strong>&nbsp;和叠在上面的 <strong>单个块</strong> 组成。模式是以三个字母字符串的列表形式&nbsp;<code>allowed</code>&nbsp;给出的，其中模式的前两个字符分别表示左右底部块，第三个字符表示顶部块。</p>

<ul>
	<li>例如，<code>"ABC"</code>&nbsp;表示一个三角形图案，其中一个 <code>“C”</code> 块堆叠在一个&nbsp;<code>'A'</code>&nbsp;块(左)和一个&nbsp;<code>'B'</code>&nbsp;块(右)之上。请注意，这与 <code>"BAC"</code>&nbsp;不同，<code>"B"</code>&nbsp;在左下角，<code>"A"</code>&nbsp;在右下角。</li>
</ul>

<p>你从作为单个字符串给出的底部的一排积木&nbsp;<code>bottom</code>&nbsp;开始，<strong>必须</strong>&nbsp;将其作为金字塔的底部。</p>

<p>在给定&nbsp;<code>bottom</code>&nbsp;和&nbsp;<code>allowed</code>&nbsp;的情况下，如果你能一直构建到金字塔顶部，使金字塔中的 <strong>每个三角形图案</strong> 都是在&nbsp;<code>allowed</code>&nbsp;中的，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0756.Pyramid%20Transition%20Matrix/images/pyramid1-grid.jpg" style="height: 232px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
<strong>输出：</strong>true
<strong>解释：</strong>允许的三角形图案显示在右边。
从最底层(第 3 层)开始，我们可以在第 2 层构建“CE”，然后在第 1 层构建“E”。
金字塔中有三种三角形图案，分别是 “BCC”、“CDE” 和 “CEA”。都是允许的。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0756.Pyramid%20Transition%20Matrix/images/pyramid2-grid.jpg" style="height: 359px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
<strong>输出：</strong>false
<strong>解释：</strong>允许的三角形图案显示在右边。
从最底层(即第 4 层)开始，创造第 3 层有多种方法，但如果尝试所有可能性，你便会在创造第 1 层前陷入困境。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= bottom.length &lt;= 6</code></li>
	<li><code>0 &lt;= allowed.length &lt;= 216</code></li>
	<li><code>allowed[i].length == 3</code></li>
	<li>所有输入字符串中的字母来自集合&nbsp;<code>{'A', 'B', 'C', 'D', 'E', 'F'}</code>。</li>
	<li>&nbsp;<code>allowed</code>&nbsp;中所有值都是 <strong>唯一的</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

定义哈希表 $d$ 存放允许的三角形图案，其中键为两个字符，值为对应的字符列表，表示两个字符可以组成一个三角形图案，三角形图案的顶部为值列表的每一项。

从最底层开始，对于每一层的每两个相邻的字符，如果它们可以组成一个三角形图案，那么就将三角形图案的顶部字符加入到下一层的对应位置的字符列表中，然后对下一层进行递归处理。

时间复杂度 $O(C^N)$。其中 $C$ 是字符集的大小，而 $N$ 是 `bottom` 字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        @cache
        def dfs(s):
            if len(s) == 1:
                return True
            t = []
            for a, b in pairwise(s):
                cs = d[a, b]
                if not cs:
                    return False
                t.append(cs)
            return any(dfs(''.join(nxt)) for nxt in product(*t))

        d = defaultdict(list)
        for a, b, c in allowed:
            d[a, b].append(c)
        return dfs(bottom)
```

#### Java

```java
class Solution {
    private int[][] f = new int[7][7];
    private Map<String, Boolean> dp = new HashMap<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (String s : allowed) {
            int a = s.charAt(0) - 'A', b = s.charAt(1) - 'A';
            f[a][b] |= 1 << (s.charAt(2) - 'A');
        }
        return dfs(bottom, new StringBuilder());
    }

    boolean dfs(String s, StringBuilder t) {
        if (s.length() == 1) {
            return true;
        }
        if (t.length() + 1 == s.length()) {
            return dfs(t.toString(), new StringBuilder());
        }
        String k = s + "." + t.toString();
        if (dp.containsKey(k)) {
            return dp.get(k);
        }
        int a = s.charAt(t.length()) - 'A', b = s.charAt(t.length() + 1) - 'A';
        int cs = f[a][b];
        for (int i = 0; i < 7; ++i) {
            if (((cs >> i) & 1) == 1) {
                t.append((char) ('A' + i));
                if (dfs(s, t)) {
                    dp.put(k, true);
                    return true;
                }
                t.deleteCharAt(t.length() - 1);
            }
        }
        dp.put(k, false);
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int f[7][7];
    unordered_map<string, bool> dp;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(f, 0, sizeof f);
        for (auto& s : allowed) {
            int a = s[0] - 'A', b = s[1] - 'A';
            f[a][b] |= 1 << (s[2] - 'A');
        }
        return dfs(bottom, "");
    }

    bool dfs(string& s, string t) {
        if (s.size() == 1) {
            return true;
        }
        if (t.size() + 1 == s.size()) {
            return dfs(t, "");
        }
        string k = s + "." + t;
        if (dp.count(k)) {
            return dp[k];
        }
        int a = s[t.size()] - 'A', b = s[t.size() + 1] - 'A';
        int cs = f[a][b];
        for (int i = 0; i < 7; ++i) {
            if ((cs >> i) & 1) {
                if (dfs(s, t + (char) (i + 'A'))) {
                    dp[k] = true;
                    return true;
                }
            }
        }
        dp[k] = false;
        return false;
    }
};
```

#### Go

```go
func pyramidTransition(bottom string, allowed []string) bool {
	f := make([][]int, 7)
	for i := range f {
		f[i] = make([]int, 7)
	}
	for _, s := range allowed {
		a, b := s[0]-'A', s[1]-'A'
		f[a][b] |= 1 << (s[2] - 'A')
	}
	dp := map[string]bool{}
	var dfs func(s string, t []byte) bool
	dfs = func(s string, t []byte) bool {
		if len(s) == 1 {
			return true
		}
		if len(t)+1 == len(s) {
			return dfs(string(t), []byte{})
		}
		k := s + "." + string(t)
		if v, ok := dp[k]; ok {
			return v
		}
		a, b := s[len(t)]-'A', s[len(t)+1]-'A'
		cs := f[a][b]
		for i := 0; i < 7; i++ {
			if ((cs >> i) & 1) == 1 {
				t = append(t, byte('A'+i))
				if dfs(s, t) {
					dp[k] = true
					return true
				}
				t = t[:len(t)-1]
			}
		}
		dp[k] = false
		return false
	}
	return dfs(bottom, []byte{})
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [757. 设置交集大小至少为2](https://leetcode.cn/problems/set-intersection-size-at-least-two){#757}

{{< tabs "757" >}}

{{% tab "python" %}}
```python
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        s = e = -1
        ans = 0
        for a, b in intervals:
            if a <= s:
                continue
            if a > e:
                ans += 2
                s, e = b - 1, b
            else:
                ans += 1
                s, e = e, b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);
        int ans = 0;
        int s = -1, e = -1;
        for (int[] v : intervals) {
            int a = v[0], b = v[1];
            if (a <= s) {
                continue;
            }
            if (a > e) {
                ans += 2;
                s = b - 1;
                e = b;
            } else {
                ans += 1;
                s = e;
                e = b;
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
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        int ans = 0;
        int s = -1, e = -1;
        for (auto& v : intervals) {
            int a = v[0], b = v[1];
            if (a <= s) continue;
            if (a > e) {
                ans += 2;
                s = b - 1;
                e = b;
            } else {
                ans += 1;
                s = e;
                e = b;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func intersectionSizeTwo(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		a, b := intervals[i], intervals[j]
		if a[1] == b[1] {
			return a[0] > b[0]
		}
		return a[1] < b[1]
	})
	ans := 0
	s, e := -1, -1
	for _, v := range intervals {
		a, b := v[0], v[1]
		if a <= s {
			continue
		}
		if a > e {
			ans += 2
			s, e = b-1, b
		} else {
			ans += 1
			s, e = e, b
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

<p>给你一个二维整数数组 <code>intervals</code> ，其中 <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示从 <code>start<sub>i</sub></code> 到 <code>end<sub>i</sub></code> 的所有整数，包括 <code>start<sub>i</sub></code> 和 <code>end<sub>i</sub></code> 。</p>

<p><strong>包含集合</strong> 是一个名为 <code>nums</code> 的数组，并满足 <code>intervals</code> 中的每个区间都 <strong>至少</strong> 有 <strong>两个</strong> 整数在 <code>nums</code> 中。</p>

<ul>
	<li>例如，如果 <code>intervals = [[1,3], [3,7], [8,9]]</code> ，那么 <code>[1,2,4,7,8,9]</code> 和 <code>[2,3,4,8,9]</code> 都符合 <strong>包含集合</strong> 的定义。</li>
</ul>

<p>返回包含集合可能的最小大小。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,3],[3,7],[8,9]]
<strong>输出：</strong>5
<strong>解释：</strong>nums = [2, 3, 4, 8, 9].
可以证明不存在元素数量为 4 的包含集合。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,3],[1,4],[2,5],[3,5]]
<strong>输出：</strong>3
<strong>解释：</strong>nums = [2, 3, 4].
可以证明不存在元素数量为 2 的包含集合。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,2],[2,3],[2,4],[4,5]]
<strong>输出：</strong>5
<strong>解释：</strong>nums = [1, 2, 3, 4, 5].
可以证明不存在元素数量为 4 的包含集合。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 3000</code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

相似题目：

-   [452. 用最少数量的箭引爆气球](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0452.Minimum%20Number%20of%20Arrows%20to%20Burst%20Balloons/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        s = e = -1
        ans = 0
        for a, b in intervals:
            if a <= s:
                continue
            if a > e:
                ans += 2
                s, e = b - 1, b
            else:
                ans += 1
                s, e = e, b
        return ans
```

#### Java

```java
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);
        int ans = 0;
        int s = -1, e = -1;
        for (int[] v : intervals) {
            int a = v[0], b = v[1];
            if (a <= s) {
                continue;
            }
            if (a > e) {
                ans += 2;
                s = b - 1;
                e = b;
            } else {
                ans += 1;
                s = e;
                e = b;
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
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        int ans = 0;
        int s = -1, e = -1;
        for (auto& v : intervals) {
            int a = v[0], b = v[1];
            if (a <= s) continue;
            if (a > e) {
                ans += 2;
                s = b - 1;
                e = b;
            } else {
                ans += 1;
                s = e;
                e = b;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func intersectionSizeTwo(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		a, b := intervals[i], intervals[j]
		if a[1] == b[1] {
			return a[0] > b[0]
		}
		return a[1] < b[1]
	})
	ans := 0
	s, e := -1, -1
	for _, v := range intervals {
		a, b := v[0], v[1]
		if a <= s {
			continue
		}
		if a > e {
			ans += 2
			s, e = b-1, b
		} else {
			ans += 1
			s, e = e, b
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

# [758. 字符串中的加粗单词 🔒](https://leetcode.cn/problems/bold-words-in-string){#758}

{{< tabs "758" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 128
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c)
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def boldWords(self, words: List[str], s: str) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(s)
        pairs = []
        for i in range(n):
            node = trie
            for j in range(i, n):
                idx = ord(s[j])
                if node.children[idx] is None:
                    break
                node = node.children[idx]
                if node.is_end:
                    pairs.append([i, j])
        if not pairs:
            return s
        st, ed = pairs[0]
        t = []
        for a, b in pairs[1:]:
            if ed + 1 < a:
                t.append([st, ed])
                st, ed = a, b
            else:
                ed = max(ed, b)
        t.append([st, ed])

        ans = []
        i = j = 0
        while i < n:
            if j == len(t):
                ans.append(s[i:])
                break
            st, ed = t[j]
            if i < st:
                ans.append(s[i:st])
            ans.append('<b>')
            ans.append(s[st : ed + 1])
            ans.append('</b>')
            j += 1
            i = ed + 1

        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[128];
    boolean isEnd;

    public void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    public String boldWords(String[] words, String s) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        List<int[]> pairs = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s.charAt(j);
                if (node.children[idx] == null) {
                    break;
                }
                node = node.children[idx];
                if (node.isEnd) {
                    pairs.add(new int[] {i, j});
                }
            }
        }
        if (pairs.isEmpty()) {
            return s;
        }
        List<int[]> t = new ArrayList<>();
        int st = pairs.get(0)[0], ed = pairs.get(0)[1];
        for (int j = 1; j < pairs.size(); ++j) {
            int a = pairs.get(j)[0], b = pairs.get(j)[1];
            if (ed + 1 < a) {
                t.add(new int[] {st, ed});
                st = a;
                ed = b;
            } else {
                ed = Math.max(ed, b);
            }
        }
        t.add(new int[] {st, ed});
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < n) {
            if (j == t.size()) {
                ans.append(s.substring(i));
                break;
            }
            st = t.get(j)[0];
            ed = t.get(j)[1];
            if (i < st) {
                ans.append(s.substring(i, st));
            }
            ++j;
            ans.append("<b>");
            ans.append(s.substring(st, ed + 1));
            ans.append("</b>");
            i = ed + 1;
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie() {
        children.resize(128);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        Trie* trie = new Trie();
        for (string w : words) trie->insert(w);
        int n = s.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s[j];
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) pairs.push_back({i, j});
            }
        }
        if (pairs.empty()) return s;
        vector<pair<int, int>> t;
        int st = pairs[0].first, ed = pairs[0].second;
        for (int i = 1; i < pairs.size(); ++i) {
            int a = pairs[i].first, b = pairs[i].second;
            if (ed + 1 < a) {
                t.push_back({st, ed});
                st = a, ed = b;
            } else
                ed = max(ed, b);
        }
        t.push_back({st, ed});
        string ans = "";
        int i = 0, j = 0;
        while (i < n) {
            if (j == t.size()) {
                ans += s.substr(i);
                break;
            }
            st = t[j].first, ed = t[j].second;
            if (i < st) ans += s.substr(i, st - i);
            ans += "<b>";
            ans += s.substr(st, ed - st + 1);
            ans += "</b>";
            i = ed + 1;
            ++j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [128]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func boldWords(words []string, s string) string {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	n := len(s)
	var pairs [][]int
	for i := range s {
		node := trie
		for j := i; j < n; j++ {
			if node.children[s[j]] == nil {
				break
			}
			node = node.children[s[j]]
			if node.isEnd {
				pairs = append(pairs, []int{i, j})
			}
		}
	}
	if len(pairs) == 0 {
		return s
	}
	var t [][]int
	st, ed := pairs[0][0], pairs[0][1]
	for i := 1; i < len(pairs); i++ {
		a, b := pairs[i][0], pairs[i][1]
		if ed+1 < a {
			t = append(t, []int{st, ed})
			st, ed = a, b
		} else {
			ed = max(ed, b)
		}
	}
	t = append(t, []int{st, ed})
	var ans strings.Builder
	i, j := 0, 0
	for i < n {
		if j == len(t) {
			ans.WriteString(s[i:])
			break
		}
		st, ed = t[j][0], t[j][1]
		if i < st {
			ans.WriteString(s[i:st])
		}
		ans.WriteString("<b>")
		ans.WriteString(s[st : ed+1])
		ans.WriteString("</b>")
		i = ed + 1
		j++
	}
	return ans.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个关键词集合&nbsp;<code>words</code> 和一个字符串&nbsp;<code>s</code>，将所有 <code>s</code> 中出现的关键词&nbsp;<code>words[i]</code>&nbsp;加粗。所有在标签&nbsp;<code>&lt;b&gt;</code>&nbsp;和&nbsp;<code>&lt;b&gt;</code>&nbsp;中的字母都会加粗。</p>

<p>加粗后返回 <code>s</code> 。返回的字符串需要使用尽可能少的标签，当然标签应形成有效的组合。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> words = ["ab","bc"], s = "aabcd"
<strong>输出:</strong> "a&lt;b&gt;abc&lt;/b&gt;d"
<strong>解释: </strong>注意返回 <code>"a&lt;b&gt;a&lt;b&gt;b&lt;/b&gt;c&lt;/b&gt;d"</code> 会使用更多的标签，因此是错误的。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> words = ["ab","cb"], s = "aabcd"
<strong>输出:</strong> "a&lt;b&gt;ab&lt;/b&gt;cd"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>0 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>words[i]</code>&nbsp;由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注：</strong>此题与「616 - 给字符串添加加粗标签」相同 - <a href="https://leetcode.cn/problems/add-bold-tag-in-string/">https://leetcode.cn/problems/add-bold-tag-in-string/</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + 区间合并

相似题目：

-   [1065. 字符串的索引对](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1065.Index%20Pairs%20of%20a%20String/README.md)
-   [616. 给字符串添加加粗标签](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0616.Add%20Bold%20Tag%20in%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 128
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c)
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def boldWords(self, words: List[str], s: str) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(s)
        pairs = []
        for i in range(n):
            node = trie
            for j in range(i, n):
                idx = ord(s[j])
                if node.children[idx] is None:
                    break
                node = node.children[idx]
                if node.is_end:
                    pairs.append([i, j])
        if not pairs:
            return s
        st, ed = pairs[0]
        t = []
        for a, b in pairs[1:]:
            if ed + 1 < a:
                t.append([st, ed])
                st, ed = a, b
            else:
                ed = max(ed, b)
        t.append([st, ed])

        ans = []
        i = j = 0
        while i < n:
            if j == len(t):
                ans.append(s[i:])
                break
            st, ed = t[j]
            if i < st:
                ans.append(s[i:st])
            ans.append('<b>')
            ans.append(s[st : ed + 1])
            ans.append('</b>')
            j += 1
            i = ed + 1

        return ''.join(ans)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[128];
    boolean isEnd;

    public void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    public String boldWords(String[] words, String s) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        List<int[]> pairs = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s.charAt(j);
                if (node.children[idx] == null) {
                    break;
                }
                node = node.children[idx];
                if (node.isEnd) {
                    pairs.add(new int[] {i, j});
                }
            }
        }
        if (pairs.isEmpty()) {
            return s;
        }
        List<int[]> t = new ArrayList<>();
        int st = pairs.get(0)[0], ed = pairs.get(0)[1];
        for (int j = 1; j < pairs.size(); ++j) {
            int a = pairs.get(j)[0], b = pairs.get(j)[1];
            if (ed + 1 < a) {
                t.add(new int[] {st, ed});
                st = a;
                ed = b;
            } else {
                ed = Math.max(ed, b);
            }
        }
        t.add(new int[] {st, ed});
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < n) {
            if (j == t.size()) {
                ans.append(s.substring(i));
                break;
            }
            st = t.get(j)[0];
            ed = t.get(j)[1];
            if (i < st) {
                ans.append(s.substring(i, st));
            }
            ++j;
            ans.append("<b>");
            ans.append(s.substring(st, ed + 1));
            ans.append("</b>");
            i = ed + 1;
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie() {
        children.resize(128);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        Trie* trie = new Trie();
        for (string w : words) trie->insert(w);
        int n = s.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s[j];
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) pairs.push_back({i, j});
            }
        }
        if (pairs.empty()) return s;
        vector<pair<int, int>> t;
        int st = pairs[0].first, ed = pairs[0].second;
        for (int i = 1; i < pairs.size(); ++i) {
            int a = pairs[i].first, b = pairs[i].second;
            if (ed + 1 < a) {
                t.push_back({st, ed});
                st = a, ed = b;
            } else
                ed = max(ed, b);
        }
        t.push_back({st, ed});
        string ans = "";
        int i = 0, j = 0;
        while (i < n) {
            if (j == t.size()) {
                ans += s.substr(i);
                break;
            }
            st = t[j].first, ed = t[j].second;
            if (i < st) ans += s.substr(i, st - i);
            ans += "<b>";
            ans += s.substr(st, ed - st + 1);
            ans += "</b>";
            i = ed + 1;
            ++j;
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [128]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func boldWords(words []string, s string) string {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	n := len(s)
	var pairs [][]int
	for i := range s {
		node := trie
		for j := i; j < n; j++ {
			if node.children[s[j]] == nil {
				break
			}
			node = node.children[s[j]]
			if node.isEnd {
				pairs = append(pairs, []int{i, j})
			}
		}
	}
	if len(pairs) == 0 {
		return s
	}
	var t [][]int
	st, ed := pairs[0][0], pairs[0][1]
	for i := 1; i < len(pairs); i++ {
		a, b := pairs[i][0], pairs[i][1]
		if ed+1 < a {
			t = append(t, []int{st, ed})
			st, ed = a, b
		} else {
			ed = max(ed, b)
		}
	}
	t = append(t, []int{st, ed})
	var ans strings.Builder
	i, j := 0, 0
	for i < n {
		if j == len(t) {
			ans.WriteString(s[i:])
			break
		}
		st, ed = t[j][0], t[j][1]
		if i < st {
			ans.WriteString(s[i:st])
		}
		ans.WriteString("<b>")
		ans.WriteString(s[st : ed+1])
		ans.WriteString("</b>")
		i = ed + 1
		j++
	}
	return ans.String()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [759. 员工空闲时间 🔒](https://leetcode.cn/problems/employee-free-time){#759}

{{< tabs "759" >}}

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

<p>给定员工的 <code>schedule</code> 列表，表示每个员工的工作时间。</p>

<p>每个员工都有一个非重叠的时间段&nbsp; <code>Intervals</code> 列表，这些时间段已经排好序。</p>

<p>返回表示 <em>所有 </em>员工的 <strong>共同，正数长度的空闲时间 </strong>的有限时间段的列表，同样需要排好序。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
<strong>输出：</strong>[[3,4]]
<strong>解释：</strong>
共有 3 个员工，并且所有共同的
空间时间段是 [-inf, 1], [3, 4], [10, inf]。
我们去除所有包含 inf 的时间段，因为它们不是有限的时间段。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
<strong>输出：</strong>[[5,6],[7,9]]
</pre>

<p>&nbsp;</p>

<p>（尽管我们用 <code>[x, y]</code> 的形式表示 <code>Intervals</code> ，内部的对象是 <code>Intervals</code> 而不是列表或数组。例如，<code>schedule[0][0].start = 1, schedule[0][0].end = 2</code>，并且 <code>schedule[0][0][0]</code>&nbsp;是未定义的）</p>

<p>而且，答案中不包含 [5, 5] ，因为长度为 0。</p>

<p>&nbsp;</p>

<p><strong>注：</strong></p>

<ol>
	<li><code>schedule</code> 和&nbsp;<code>schedule[i]</code>&nbsp;为长度范围在&nbsp;<code>[1, 50]</code>的列表。</li>
	<li><code>0 &lt;= schedule[i].start &lt; schedule[i].end &lt;= 10^8</code>。</li>
</ol>

<p><strong>注：</strong>输入类型于&nbsp;2019 年&nbsp;4 月 15 日 改变。请重置为默认代码的定义以获取新方法。</p>

<p>&nbsp;</p>

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
