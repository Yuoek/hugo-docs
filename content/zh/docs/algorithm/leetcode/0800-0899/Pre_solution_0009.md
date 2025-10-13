---
title: "0880_索引处的解码字符串"
date: 2025-10-08T18:36:34+08:00
weight: 9
tags: [二分查找, 二叉树, 几何, 分治, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 最短路, 栈, 树, 模拟, 深度优先搜索, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [0880_索引处的解码字符串](#880)
#### [栈](#880)
#### [字符串](#880)
### [0881_救生艇](#881)
#### [贪心](#881)
#### [数组](#881)
#### [双指针](#881)
#### [排序](#881)
### [0882_细分图中的可到达节点](#882)
#### [图](#882)
#### [最短路](#882)
#### [堆（优先队列）](#882)
### [0883_三维形体投影面积](#883)
#### [几何](#883)
#### [数组](#883)
#### [数学](#883)
#### [矩阵](#883)
### [0884_两句话中的不常见单词](#884)
#### [哈希表](#884)
#### [字符串](#884)
#### [计数](#884)
### [0885_螺旋矩阵 III](#885)
#### [数组](#885)
#### [矩阵](#885)
#### [模拟](#885)
### [0886_可能的二分法](#886)
#### [深度优先搜索](#886)
#### [广度优先搜索](#886)
#### [并查集](#886)
#### [图](#886)
### [0887_鸡蛋掉落](#887)
#### [数学](#887)
#### [二分查找](#887)
#### [动态规划](#887)
### [0888_公平的糖果交换](#888)
#### [数组](#888)
#### [哈希表](#888)
#### [二分查找](#888)
#### [排序](#888)
### [0889_根据前序和后序遍历构造二叉树](#889)
#### [树](#889)
#### [数组](#889)
#### [哈希表](#889)
#### [分治](#889)
#### [二叉树](#889)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0880_索引处的解码字符串
___
#### 栈
___
#### 字符串
---
### 0881_救生艇
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0882_细分图中的可到达节点
___
#### 图
___
#### 最短路
___
#### 堆（优先队列）
---
### 0883_三维形体投影面积
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 矩阵
---
### 0884_两句话中的不常见单词
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 0885_螺旋矩阵 III
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 0886_可能的二分法
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0887_鸡蛋掉落
___
#### 数学
___
#### 二分查找
___
#### 动态规划
---
### 0888_公平的糖果交换
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 排序
---
### 0889_根据前序和后序遍历构造二叉树
___
#### 树
___
#### 数组
___
#### 哈希表
___
#### 分治
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 几何 |
| 分治 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 最短路 | 栈 | 树 |
| 模拟 | 深度优先搜索 | 矩阵 |
| 计数 | 贪心 |  |

# [880. 索引处的解码字符串](https://leetcode.cn/problems/decoded-string-at-index){#880}

{{< tabs "880" >}}

{{% tab "python" %}}
```python
class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        m = 0
        for c in s:
            if c.isdigit():
                m *= int(c)
            else:
                m += 1
        for c in s[::-1]:
            k %= m
            if k == 0 and c.isalpha():
                return c
            if c.isdigit():
                m //= int(c)
            else:
                m -= 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String decodeAtIndex(String s, int k) {
        long m = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                m *= (s.charAt(i) - '0');
            } else {
                ++m;
            }
        }
        for (int i = s.length() - 1;; --i) {
            k %= m;
            if (k == 0 && !Character.isDigit(s.charAt(i))) {
                return String.valueOf(s.charAt(i));
            }
            if (Character.isDigit(s.charAt(i))) {
                m /= (s.charAt(i) - '0');
            } else {
                --m;
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
    string decodeAtIndex(string s, int k) {
        long long m = 0;
        for (char& c : s) {
            if (isdigit(c)) {
                m *= (c - '0');
            } else {
                ++m;
            }
        }
        for (int i = s.size() - 1;; --i) {
            k %= m;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            if (isdigit(s[i])) {
                m /= (s[i] - '0');
            } else {
                --m;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decodeAtIndex(s string, k int) string {
	m := 0
	for _, c := range s {
		if c >= '0' && c <= '9' {
			m *= int(c - '0')
		} else {
			m++
		}
	}
	for i := len(s) - 1; ; i-- {
		k %= m
		if k == 0 && s[i] >= 'a' && s[i] <= 'z' {
			return string(s[i])
		}
		if s[i] >= '0' && s[i] <= '9' {
			m /= int(s[i] - '0')
		} else {
			m--
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decodeAtIndex(s: string, k: number): string {
    let m = 0n;
    for (const c of s) {
        if (c >= '1' && c <= '9') {
            m *= BigInt(c);
        } else {
            ++m;
        }
    }
    for (let i = s.length - 1; ; --i) {
        if (k >= m) {
            k %= Number(m);
        }
        if (k === 0 && s[i] >= 'a' && s[i] <= 'z') {
            return s[i];
        }
        if (s[i] >= '1' && s[i] <= '9') {
            m = (m / BigInt(s[i])) | 0n;
        } else {
            --m;
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

<p>给定一个编码字符串 <code>s</code> 。请你找出<em> </em><strong>解码字符串</strong> 并将其写入磁带。解码时，从编码字符串中<strong> 每次读取一个字符 </strong>，并采取以下步骤：</p>

<ul>
	<li>如果所读的字符是字母，则将该字母写在磁带上。</li>
	<li>如果所读的字符是数字（例如 <code>d</code>），则整个当前磁带总共会被重复写&nbsp;<code>d-1</code> 次。</li>
</ul>

<p>现在，对于给定的编码字符串 <code>s</code> 和索引 <code>k</code>，查找并返回解码字符串中的第 <code>k</code> 个字母。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "leet2code3", k = 10
<strong>输出：</strong>"o"
<strong>解释：</strong>
解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
字符串中的第 10 个字母是 "o"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ha22", k = 5
<strong>输出：</strong>"h"
<strong>解释：</strong>
解码后的字符串为 "hahahaha"。第 5 个字母是 "h"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "a2345678999999999999999", k = 1
<strong>输出：</strong>"a"
<strong>解释：</strong>
解码后的字符串为 "a" 重复 8301530446056247680 次。第 1 个字母是 "a"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 只包含小写字母与数字 <code>2</code> 到 <code>9</code> 。</li>
	<li><code>s</code> 以字母开头。</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>题目保证 <code>k</code> 小于或等于解码字符串的长度。</li>
	<li>解码后的字符串保证少于&nbsp;<code>2<sup>63</sup></code>&nbsp;个字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向思维

我们可以先计算出解码字符串的总长度 $m$，然后从后向前遍历字符串，每次更新 $k$ 为 $k \bmod m$，直到 $k$ 为 $0$ 且当前字符为字母，返回当前字符。否则，如果当前字符为数字，则将 $m$ 除以该数字。如果当前字符为字母，则将 $m$ 减 $1$。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        m = 0
        for c in s:
            if c.isdigit():
                m *= int(c)
            else:
                m += 1
        for c in s[::-1]:
            k %= m
            if k == 0 and c.isalpha():
                return c
            if c.isdigit():
                m //= int(c)
            else:
                m -= 1
```

#### Java

```java
class Solution {
    public String decodeAtIndex(String s, int k) {
        long m = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                m *= (s.charAt(i) - '0');
            } else {
                ++m;
            }
        }
        for (int i = s.length() - 1;; --i) {
            k %= m;
            if (k == 0 && !Character.isDigit(s.charAt(i))) {
                return String.valueOf(s.charAt(i));
            }
            if (Character.isDigit(s.charAt(i))) {
                m /= (s.charAt(i) - '0');
            } else {
                --m;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long m = 0;
        for (char& c : s) {
            if (isdigit(c)) {
                m *= (c - '0');
            } else {
                ++m;
            }
        }
        for (int i = s.size() - 1;; --i) {
            k %= m;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            if (isdigit(s[i])) {
                m /= (s[i] - '0');
            } else {
                --m;
            }
        }
    }
};
```

#### Go

```go
func decodeAtIndex(s string, k int) string {
	m := 0
	for _, c := range s {
		if c >= '0' && c <= '9' {
			m *= int(c - '0')
		} else {
			m++
		}
	}
	for i := len(s) - 1; ; i-- {
		k %= m
		if k == 0 && s[i] >= 'a' && s[i] <= 'z' {
			return string(s[i])
		}
		if s[i] >= '0' && s[i] <= '9' {
			m /= int(s[i] - '0')
		} else {
			m--
		}
	}
}
```

#### TypeScript

```ts
function decodeAtIndex(s: string, k: number): string {
    let m = 0n;
    for (const c of s) {
        if (c >= '1' && c <= '9') {
            m *= BigInt(c);
        } else {
            ++m;
        }
    }
    for (let i = s.length - 1; ; --i) {
        if (k >= m) {
            k %= Number(m);
        }
        if (k === 0 && s[i] >= 'a' && s[i] <= 'z') {
            return s[i];
        }
        if (s[i] >= '1' && s[i] <= '9') {
            m = (m / BigInt(s[i])) | 0n;
        } else {
            --m;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [881. 救生艇](https://leetcode.cn/problems/boats-to-save-people){#881}

{{< tabs "881" >}}

{{% tab "python" %}}
```python
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans = 0
        i, j = 0, len(people) - 1
        while i <= j:
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int ans = 0;
        for (int i = 0, j = people.length - 1; i <= j; --j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            ++ans;
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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        for (int i = 0, j = people.size() - 1; i <= j; --j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	ans := 0
	for i, j := 0, len(people)-1; i <= j; j-- {
		if people[i]+people[j] <= limit {
			i++
		}
		ans++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numRescueBoats(people: number[], limit: number): number {
    people.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0, j = people.length - 1; i <= j; --j) {
        if (people[i] + people[j] <= limit) {
            ++i;
        }
        ++ans;
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

<p>给定数组<meta charset="UTF-8" />&nbsp;<code>people</code>&nbsp;。<code>people[i]</code>表示第 <code>i</code><sup>&nbsp;</sup>个人的体重&nbsp;，<strong>船的数量不限</strong>，每艘船可以承载的最大重量为&nbsp;<code>limit</code>。</p>

<p>每艘船最多可同时载两人，但条件是这些人的重量之和最多为&nbsp;<code>limit</code>。</p>

<p>返回 <em>承载所有人所需的最小船数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>people = [1,2], limit = 3
<strong>输出：</strong>1
<strong>解释：</strong>1 艘船载 (1, 2)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>people = [3,2,2,1], limit = 3
<strong>输出：</strong>3
<strong>解释：</strong>3 艘船分别载 (1, 2), (2) 和 (3)
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>people = [3,5,3,4], limit = 5
<strong>输出：</strong>4
<strong>解释：</strong>4 艘船分别载 (3), (3), (4), (5)</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= limit &lt;= 3 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

排序后，使用双指针分别指向数组首尾，每次取两个指针指向的元素之和与 `limit` 比较，如果小于等于 `limit`，则两个指针同时向中间移动一位，否则只移动右指针。累加答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `people` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans = 0
        i, j = 0, len(people) - 1
        while i <= j:
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int ans = 0;
        for (int i = 0, j = people.length - 1; i <= j; --j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        for (int i = 0, j = people.size() - 1; i <= j; --j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	ans := 0
	for i, j := 0, len(people)-1; i <= j; j-- {
		if people[i]+people[j] <= limit {
			i++
		}
		ans++
	}
	return ans
}
```

#### TypeScript

```ts
function numRescueBoats(people: number[], limit: number): number {
    people.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0, j = people.length - 1; i <= j; --j) {
        if (people[i] + people[j] <= limit) {
            ++i;
        }
        ++ans;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [882. 细分图中的可到达节点](https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph){#882}

{{< tabs "882" >}}

{{% tab "python" %}}
```python
class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        g = defaultdict(list)
        for u, v, cnt in edges:
            g[u].append((v, cnt + 1))
            g[v].append((u, cnt + 1))
        q = [(0, 0)]
        dist = [0] + [inf] * n
        while q:
            d, u = heappop(q)
            for v, cnt in g[u]:
                if (t := d + cnt) < dist[v]:
                    dist[v] = t
                    q.append((t, v))
        ans = sum(d <= maxMoves for d in dist)
        for u, v, cnt in edges:
            a = min(cnt, max(0, maxMoves - dist[u]))
            b = min(cnt, max(0, maxMoves - dist[v]))
            ans += min(cnt, a + b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, e -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1], cnt = e[2] + 1;
            g[u].add(new int[] {v, cnt});
            g[v].add(new int[] {u, cnt});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, 1 << 30);
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, 0});
        dist[0] = 0;
        while (!q.isEmpty()) {
            var p = q.poll();
            int d = p[0], u = p[1];
            for (var nxt : g[u]) {
                int v = nxt[0], cnt = nxt[1];
                if (d + cnt < dist[v]) {
                    dist[v] = d + cnt;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int d : dist) {
            if (d <= maxMoves) {
                ++ans;
            }
        }
        for (var e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = Math.min(cnt, Math.max(0, maxMoves - dist[u]));
            int b = Math.min(cnt, Math.max(0, maxMoves - dist[v]));
            ans += Math.min(cnt, a + b);
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
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2] + 1;
            g[u].emplace_back(v, cnt);
            g[v].emplace_back(u, cnt);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, 0);
        int dist[n];
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            for (auto& [v, cnt] : g[u]) {
                if (d + cnt < dist[v]) {
                    dist[v] = d + cnt;
                    q.emplace(dist[v], v);
                }
            }
        }
        int ans = 0;
        for (int& d : dist) ans += d <= maxMoves;
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = min(cnt, max(0, maxMoves - dist[u]));
            int b = min(cnt, max(0, maxMoves - dist[v]));
            ans += min(cnt, a + b);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reachableNodes(edges [][]int, maxMoves int, n int) (ans int) {
	g := make([][]pair, n)
	for _, e := range edges {
		u, v, cnt := e[0], e[1], e[2]+1
		g[u] = append(g[u], pair{cnt, v})
		g[v] = append(g[v], pair{cnt, u})
	}
	dist := make([]int, n)
	for i := range dist {
		dist[i] = 1 << 30
	}
	dist[0] = 0
	q := hp{{0, 0}}
	for len(q) > 0 {
		p := heap.Pop(&q).(pair)
		d, u := p.v, p.i
		for _, nxt := range g[u] {
			v, cnt := nxt.i, nxt.v
			if t := d + cnt; t < dist[v] {
				dist[v] = t
				heap.Push(&q, pair{t, v})
			}
		}
	}
	for _, d := range dist {
		if d <= maxMoves {
			ans++
		}
	}
	for _, e := range edges {
		u, v, cnt := e[0], e[1], e[2]
		a := min(cnt, max(0, maxMoves-dist[u]))
		b := min(cnt, max(0, maxMoves-dist[v]))
		ans += min(cnt, a+b)
	}
	return
}

type pair struct{ v, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个无向图（<strong>原始图</strong>），图中有 <code>n</code> 个节点，编号从 <code>0</code> 到 <code>n - 1</code> 。你决定将图中的每条边 <strong>细分</strong> 为一条节点链，每条边之间的新节点数各不相同。</p>

<p>图用由边组成的二维数组 <code>edges</code> 表示，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, cnt<sub>i</sub>]</code> 表示原始图中节点&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code> 之间存在一条边，<code>cnt<sub>i</sub></code> 是将边 <strong>细分</strong> 后的新节点总数。注意，<code>cnt<sub>i</sub> == 0</code> 表示边不可细分。</p>

<p>要 <strong>细分</strong> 边 <code>[ui, vi]</code> ，需要将其替换为 <code>(cnt<sub>i</sub> + 1)</code> 条新边，和&nbsp;<code>cnt<sub>i</sub></code> 个新节点。新节点为 <code>x<sub>1</sub></code>, <code>x<sub>2</sub></code>, ..., <code>x<sub>cnt<sub>i</sub></sub></code> ，新边为 <code>[u<sub>i</sub>, x<sub>1</sub>]</code>, <code>[x<sub>1</sub>, x<sub>2</sub>]</code>, <code>[x<sub>2</sub>, x<sub>3</sub>]</code>, ..., <code>[x<sub>cnt<sub>i</sub>-1</sub>, x<sub>cnt<sub>i</sub></sub>]</code>, <code>[x<sub>cnt<sub>i</sub></sub>, v<sub>i</sub>]</code> 。</p>

<p>现在得到一个&nbsp;<strong>新的细分图</strong> ，请你计算从节点 <code>0</code> 出发，可以到达多少个节点？如果节点间距离是 <code>maxMoves</code> 或更少，则视为 <strong>可以到达</strong> 。</p>

<p>给你原始图和 <code>maxMoves</code> ，返回 <em>新的细分图中从节点 <code>0</code> 出发</em><strong><em> 可到达的节点数</em></strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0882.Reachable%20Nodes%20In%20Subdivided%20Graph/images/origfinal.png" style="height: 247px; width: 600px;" />
<pre>
<strong>输入：</strong>edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
<strong>输出：</strong>13
<strong>解释：</strong>边的细分情况如上图所示。
可以到达的节点已经用黄色标注出来。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
<strong>输出：</strong>23
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
<strong>输出：</strong>1
<strong>解释：</strong>节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= edges.length &lt;= min(n * (n - 1) / 2, 10<sup>4</sup>)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub> &lt; v<sub>i</sub> &lt; n</code></li>
	<li>图中 <strong>不存在平行边</strong></li>
	<li><code>0 &lt;= cnt<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= maxMoves &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= n &lt;= 3000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Dijkstra 算法

这道题本质是求从节点 $0$ 出发，最多经过 $maxMoves$ 步，可以到达多少个节点。单源最短路，且边权非负，我们可以考虑使用 Dijkstra 算法。

根据题目描述，节点 $u_i$ 到节点 $v_i$ 之间存在 $cnt_i$ 个新节点，那么节点 $u_i$ 到节点 $v_i$ 的距离为 $cnt_i + 1$。

我们举个简单的例子，以下节点 $1$ 和节点 $2$ 之间存在 $3$ 个新节点，那么节点 $1$ 到节点 $2$ 之间有 $4$ 条边，也即距离为 $4$。

```
1 -- o -- o -- o -- 2
```

因此，我们可以将原图中两点之间新节点的个数 $cnt_i$ 加 $1$，得到两点之间的距离。然后构建一个邻接表 $g$，用于存储每个节点的邻接节点以及到达邻接节点的距离。

接下来，我们使用 Dijkstra 算法求出从节点 $0$ 到原始图其余所有节点的最短距离，存储在数组 $dist$ 中。

然后，我们遍历数组 $dist$，统计其中小于等于 $maxMoves$ 的节点个数，也就是我们可以到达的节点数。不过，这并不是最终答案，我们还需要加上新节点中符合条件的节点个数。

我们可以发现，如果我们能在 $dist[u]$ 步到达节点 $u$（其中 $dist[u] \leq maxMoves$），并且节点 $u$ 到节点 $v$ 之间有 $cnt$ 个新节点，那么我们能通过节点 $u$ 到达的新节点个数 $a=\min(cnt, maxMoves - dist[u])$。同理，我们能通过节点 $v$ 到达的新节点个数 $b=\min(cnt, maxMoves - dist[v])$。那么，我们能到达节点 $u$ 和节点 $v$ 之间的新节点个数为 $\min(cnt, a + b)$。

因此，我们再遍历所有的边，统计其中能到达的新节点个数，累加到答案中即可。

时间复杂度 $O(n + m \times \log n)$，其中 $m$ 和 $n$ 分别为边数和节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        g = defaultdict(list)
        for u, v, cnt in edges:
            g[u].append((v, cnt + 1))
            g[v].append((u, cnt + 1))
        q = [(0, 0)]
        dist = [0] + [inf] * n
        while q:
            d, u = heappop(q)
            for v, cnt in g[u]:
                if (t := d + cnt) < dist[v]:
                    dist[v] = t
                    q.append((t, v))
        ans = sum(d <= maxMoves for d in dist)
        for u, v, cnt in edges:
            a = min(cnt, max(0, maxMoves - dist[u]))
            b = min(cnt, max(0, maxMoves - dist[v]))
            ans += min(cnt, a + b)
        return ans
```

#### Java

```java
class Solution {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, e -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1], cnt = e[2] + 1;
            g[u].add(new int[] {v, cnt});
            g[v].add(new int[] {u, cnt});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, 1 << 30);
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[] {0, 0});
        dist[0] = 0;
        while (!q.isEmpty()) {
            var p = q.poll();
            int d = p[0], u = p[1];
            for (var nxt : g[u]) {
                int v = nxt[0], cnt = nxt[1];
                if (d + cnt < dist[v]) {
                    dist[v] = d + cnt;
                    q.offer(new int[] {dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int d : dist) {
            if (d <= maxMoves) {
                ++ans;
            }
        }
        for (var e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = Math.min(cnt, Math.max(0, maxMoves - dist[u]));
            int b = Math.min(cnt, Math.max(0, maxMoves - dist[v]));
            ans += Math.min(cnt, a + b);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2] + 1;
            g[u].emplace_back(v, cnt);
            g[v].emplace_back(u, cnt);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, 0);
        int dist[n];
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            for (auto& [v, cnt] : g[u]) {
                if (d + cnt < dist[v]) {
                    dist[v] = d + cnt;
                    q.emplace(dist[v], v);
                }
            }
        }
        int ans = 0;
        for (int& d : dist) ans += d <= maxMoves;
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = min(cnt, max(0, maxMoves - dist[u]));
            int b = min(cnt, max(0, maxMoves - dist[v]));
            ans += min(cnt, a + b);
        }
        return ans;
    }
};
```

#### Go

```go
func reachableNodes(edges [][]int, maxMoves int, n int) (ans int) {
	g := make([][]pair, n)
	for _, e := range edges {
		u, v, cnt := e[0], e[1], e[2]+1
		g[u] = append(g[u], pair{cnt, v})
		g[v] = append(g[v], pair{cnt, u})
	}
	dist := make([]int, n)
	for i := range dist {
		dist[i] = 1 << 30
	}
	dist[0] = 0
	q := hp{{0, 0}}
	for len(q) > 0 {
		p := heap.Pop(&q).(pair)
		d, u := p.v, p.i
		for _, nxt := range g[u] {
			v, cnt := nxt.i, nxt.v
			if t := d + cnt; t < dist[v] {
				dist[v] = t
				heap.Push(&q, pair{t, v})
			}
		}
	}
	for _, d := range dist {
		if d <= maxMoves {
			ans++
		}
	}
	for _, e := range edges {
		u, v, cnt := e[0], e[1], e[2]
		a := min(cnt, max(0, maxMoves-dist[u]))
		b := min(cnt, max(0, maxMoves-dist[v]))
		ans += min(cnt, a+b)
	}
	return
}

type pair struct{ v, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [883. 三维形体投影面积](https://leetcode.cn/problems/projection-area-of-3d-shapes){#883}

{{< tabs "883" >}}

{{% tab "python" %}}
```python
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        xy = sum(v > 0 for row in grid for v in row)
        yz = sum(max(row) for row in grid)
        zx = sum(max(col) for col in zip(*grid))
        return xy + yz + zx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int projectionArea(int[][] grid) {
        int xy = 0, yz = 0, zx = 0;
        for (int i = 0, n = grid.length; i < n; ++i) {
            int maxYz = 0;
            int maxZx = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ++xy;
                }
                maxYz = Math.max(maxYz, grid[i][j]);
                maxZx = Math.max(maxZx, grid[j][i]);
            }
            yz += maxYz;
            zx += maxZx;
        }
        return xy + yz + zx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz = 0, zx = 0;
        for (int i = 0, n = grid.size(); i < n; ++i) {
            int maxYz = 0, maxZx = 0;
            for (int j = 0; j < n; ++j) {
                xy += grid[i][j] > 0;
                maxYz = max(maxYz, grid[i][j]);
                maxZx = max(maxZx, grid[j][i]);
            }
            yz += maxYz;
            zx += maxZx;
        }
        return xy + yz + zx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func projectionArea(grid [][]int) int {
	xy, yz, zx := 0, 0, 0
	for i, row := range grid {
		maxYz, maxZx := 0, 0
		for j, v := range row {
			if v > 0 {
				xy++
			}
			maxYz = max(maxYz, v)
			maxZx = max(maxZx, grid[j][i])
		}
		yz += maxYz
		zx += maxZx
	}
	return xy + yz + zx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function projectionArea(grid: number[][]): number {
    const xy: number = grid.flat().filter(v => v > 0).length;
    const yz: number = grid.reduce((acc, row) => acc + Math.max(...row), 0);
    const zx: number = grid[0]
        .map((_, i) => Math.max(...grid.map(row => row[i])))
        .reduce((acc, val) => acc + val, 0);
    return xy + yz + zx;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let xy: i32 = grid
            .iter()
            .map(|row| row.iter().filter(|&&v| v > 0).count() as i32)
            .sum();
        let yz: i32 = grid.iter().map(|row| *row.iter().max().unwrap_or(&0)).sum();
        let zx: i32 = (0..grid[0].len())
            .map(|i| grid.iter().map(|row| row[i]).max().unwrap_or(0))
            .sum();
        xy + yz + zx
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在<meta charset="UTF-8" />&nbsp;<code>n x n</code>&nbsp;的网格<meta charset="UTF-8" />&nbsp;<code>grid</code>&nbsp;中，我们放置了一些与 x，y，z 三轴对齐的<meta charset="UTF-8" />&nbsp;<code>1 x 1 x 1</code>&nbsp;立方体。</p>

<p>每个值&nbsp;<code>v = grid[i][j]</code>&nbsp;表示有一列&nbsp;<code>v</code>&nbsp;个正方体叠放在格子&nbsp;<code>(i, j)</code>&nbsp;上。</p>

<p>现在，我们查看这些立方体在 <code>xy</code>&nbsp;、<code>yz</code>&nbsp;和 <code>zx</code>&nbsp;平面上的<em>投影</em>。</p>

<p><strong>投影</strong>&nbsp;就像影子，将 <strong>三维</strong> 形体映射到一个 <strong>二维</strong> 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。</p>

<p>返回 <em>所有三个投影的总面积</em> 。</p>

<p>&nbsp;</p>

<ul>
</ul>

<ul>
</ul>

<ul>
</ul>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0883.Projection%20Area%20of%203D%20Shapes/images/shadow.png" style="height: 214px; width: 800px;" /></p>

<pre>
<strong>输入：</strong>[[1,2],[3,4]]
<strong>输出：</strong>17
<strong>解释：</strong>这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>grid = [[2]]
<strong>输出：</strong>5
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>[[1,0],[0,2]]
<strong>输出：</strong>8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们可以分别计算三个投影的面积。

-   xy 平面的投影面积：每个非零值都会投影到 xy 平面，所以 xy 的投影面积为非零值的个数。
-   yz 平面的投影面积：每一行的最大值。
-   zx 平面的投影面积：每一列的最大值。

最后将三个面积相加即可。

时间复杂度 $O(n^2)$，其中 $n$ 为网格 `grid` 的边长。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        xy = sum(v > 0 for row in grid for v in row)
        yz = sum(max(row) for row in grid)
        zx = sum(max(col) for col in zip(*grid))
        return xy + yz + zx
```

#### Java

```java
class Solution {
    public int projectionArea(int[][] grid) {
        int xy = 0, yz = 0, zx = 0;
        for (int i = 0, n = grid.length; i < n; ++i) {
            int maxYz = 0;
            int maxZx = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ++xy;
                }
                maxYz = Math.max(maxYz, grid[i][j]);
                maxZx = Math.max(maxZx, grid[j][i]);
            }
            yz += maxYz;
            zx += maxZx;
        }
        return xy + yz + zx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz = 0, zx = 0;
        for (int i = 0, n = grid.size(); i < n; ++i) {
            int maxYz = 0, maxZx = 0;
            for (int j = 0; j < n; ++j) {
                xy += grid[i][j] > 0;
                maxYz = max(maxYz, grid[i][j]);
                maxZx = max(maxZx, grid[j][i]);
            }
            yz += maxYz;
            zx += maxZx;
        }
        return xy + yz + zx;
    }
};
```

#### Go

```go
func projectionArea(grid [][]int) int {
	xy, yz, zx := 0, 0, 0
	for i, row := range grid {
		maxYz, maxZx := 0, 0
		for j, v := range row {
			if v > 0 {
				xy++
			}
			maxYz = max(maxYz, v)
			maxZx = max(maxZx, grid[j][i])
		}
		yz += maxYz
		zx += maxZx
	}
	return xy + yz + zx
}
```

#### TypeScript

```ts
function projectionArea(grid: number[][]): number {
    const xy: number = grid.flat().filter(v => v > 0).length;
    const yz: number = grid.reduce((acc, row) => acc + Math.max(...row), 0);
    const zx: number = grid[0]
        .map((_, i) => Math.max(...grid.map(row => row[i])))
        .reduce((acc, val) => acc + val, 0);
    return xy + yz + zx;
}
```

#### Rust

```rust
impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let xy: i32 = grid
            .iter()
            .map(|row| row.iter().filter(|&&v| v > 0).count() as i32)
            .sum();
        let yz: i32 = grid.iter().map(|row| *row.iter().max().unwrap_or(&0)).sum();
        let zx: i32 = (0..grid[0].len())
            .map(|i| grid.iter().map(|row| row[i]).max().unwrap_or(0))
            .sum();
        xy + yz + zx
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [884. 两句话中的不常见单词](https://leetcode.cn/problems/uncommon-words-from-two-sentences){#884}

{{< tabs "884" >}}

{{% tab "python" %}}
```python
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        cnt = Counter(s1.split()) + Counter(s2.split())
        return [s for s, v in cnt.items() if v == 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : s1.split(" ")) {
            cnt.merge(s, 1, Integer::sum);
        }
        for (String s : s2.split(" ")) {
            cnt.merge(s, 1, Integer::sum);
        }
        List<String> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            if (e.getValue() == 1) {
                ans.add(e.getKey());
            }
        }
        return ans.toArray(new String[0]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> cnt;
        auto add = [&](string& s) {
            stringstream ss(s);
            string w;
            while (ss >> w) ++cnt[move(w)];
        };
        add(s1);
        add(s2);
        vector<string> ans;
        for (auto& [s, v] : cnt)
            if (v == 1) ans.emplace_back(s);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func uncommonFromSentences(s1 string, s2 string) (ans []string) {
	cnt := map[string]int{}
	for _, s := range strings.Split(s1, " ") {
		cnt[s]++
	}
	for _, s := range strings.Split(s2, " ") {
		cnt[s]++
	}
	for s, v := range cnt {
		if v == 1 {
			ans = append(ans, s)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function uncommonFromSentences(s1: string, s2: string): string[] {
    const cnt: Map<string, number> = new Map();
    for (const s of [...s1.split(' '), ...s2.split(' ')]) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    const ans: Array<string> = [];
    for (const [s, v] of cnt.entries()) {
        if (v == 1) {
            ans.push(s);
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
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut map = HashMap::new();
        for s in s1.split(' ') {
            map.insert(s, !map.contains_key(s));
        }
        for s in s2.split(' ') {
            map.insert(s, !map.contains_key(s));
        }
        let mut res = Vec::new();
        for (k, v) in map {
            if v {
                res.push(String::from(k));
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function (s1, s2) {
    const cnt = new Map();
    for (const s of [...s1.split(' '), ...s2.split(' ')]) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    const ans = [];
    for (const [s, v] of cnt.entries()) {
        if (v == 1) {
            ans.push(s);
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

<p><strong>句子</strong> 是一串由空格分隔的单词。每个 <strong>单词</strong><em> </em>仅由小写字母组成。</p>

<p>如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 <strong>没有出现</strong> ，那么这个单词就是 <strong>不常见的</strong><em> </em>。</p>

<p>给你两个 <strong>句子</strong> <code>s1</code> 和 <code>s2</code> ，返回所有 <strong>不常用单词</strong> 的列表。返回列表中单词可以按 <strong>任意顺序</strong> 组织。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "this apple is sweet", s2 = "this apple is sour"
<strong>输出：</strong>["sweet","sour"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "apple apple", s2 = "banana"
<strong>输出：</strong>["banana"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 200</code></li>
	<li><code>s1</code> 和 <code>s2</code> 由小写英文字母和空格组成</li>
	<li><code>s1</code> 和 <code>s2</code> 都不含前导或尾随空格</li>
	<li><code>s1</code> 和 <code>s2</code> 中的所有单词间均由单个空格分隔</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

根据题目描述，只要单词出现一次，就符合题目要求。因此，我们用哈希表 $cnt$ 记录所有单词以及出现的次数。

然后遍历哈希表，取出所有出现次数为 $1$ 的字符串即可。

时间复杂度 $O(m + n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是字符串 $s1$ 和 $s2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        cnt = Counter(s1.split()) + Counter(s2.split())
        return [s for s, v in cnt.items() if v == 1]
```

#### Java

```java
class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String s : s1.split(" ")) {
            cnt.merge(s, 1, Integer::sum);
        }
        for (String s : s2.split(" ")) {
            cnt.merge(s, 1, Integer::sum);
        }
        List<String> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            if (e.getValue() == 1) {
                ans.add(e.getKey());
            }
        }
        return ans.toArray(new String[0]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> cnt;
        auto add = [&](string& s) {
            stringstream ss(s);
            string w;
            while (ss >> w) ++cnt[move(w)];
        };
        add(s1);
        add(s2);
        vector<string> ans;
        for (auto& [s, v] : cnt)
            if (v == 1) ans.emplace_back(s);
        return ans;
    }
};
```

#### Go

```go
func uncommonFromSentences(s1 string, s2 string) (ans []string) {
	cnt := map[string]int{}
	for _, s := range strings.Split(s1, " ") {
		cnt[s]++
	}
	for _, s := range strings.Split(s2, " ") {
		cnt[s]++
	}
	for s, v := range cnt {
		if v == 1 {
			ans = append(ans, s)
		}
	}
	return
}
```

#### TypeScript

```ts
function uncommonFromSentences(s1: string, s2: string): string[] {
    const cnt: Map<string, number> = new Map();
    for (const s of [...s1.split(' '), ...s2.split(' ')]) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    const ans: Array<string> = [];
    for (const [s, v] of cnt.entries()) {
        if (v == 1) {
            ans.push(s);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut map = HashMap::new();
        for s in s1.split(' ') {
            map.insert(s, !map.contains_key(s));
        }
        for s in s2.split(' ') {
            map.insert(s, !map.contains_key(s));
        }
        let mut res = Vec::new();
        for (k, v) in map {
            if v {
                res.push(String::from(k));
            }
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function (s1, s2) {
    const cnt = new Map();
    for (const s of [...s1.split(' '), ...s2.split(' ')]) {
        cnt.set(s, (cnt.get(s) || 0) + 1);
    }
    const ans = [];
    for (const [s, v] of cnt.entries()) {
        if (v == 1) {
            ans.push(s);
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

# [885. 螺旋矩阵 III](https://leetcode.cn/problems/spiral-matrix-iii){#885}

{{< tabs "885" >}}

{{% tab "python" %}}
```python
class Solution:
    def spiralMatrixIII(
        self, rows: int, cols: int, rStart: int, cStart: int
    ) -> List[List[int]]:
        ans = [[rStart, cStart]]
        if rows * cols == 1:
            return ans
        k = 1
        while True:
            for dr, dc, dk in [[0, 1, k], [1, 0, k], [0, -1, k + 1], [-1, 0, k + 1]]:
                for _ in range(dk):
                    rStart += dr
                    cStart += dc
                    if 0 <= rStart < rows and 0 <= cStart < cols:
                        ans.append([rStart, cStart])
                        if len(ans) == rows * cols:
                            return ans
            k += 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cnt = rows * cols;
        int[][] ans = new int[cnt][2];
        ans[0] = new int[] {rStart, cStart};
        if (cnt == 1) {
            return ans;
        }
        for (int k = 1, idx = 1;; k += 2) {
            int[][] dirs = new int[][] {{0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}};
            for (int[] dir : dirs) {
                int r = dir[0], c = dir[1], dk = dir[2];
                while (dk-- > 0) {
                    rStart += r;
                    cStart += c;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans[idx++] = new int[] {rStart, cStart};
                        if (idx == cnt) {
                            return ans;
                        }
                    }
                }
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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cnt = rows * cols;
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        if (cnt == 1) return ans;
        for (int k = 1;; k += 2) {
            vector<vector<int>> dirs = {{0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}};
            for (auto& dir : dirs) {
                int r = dir[0], c = dir[1], dk = dir[2];
                while (dk-- > 0) {
                    rStart += r;
                    cStart += c;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                        if (ans.size() == cnt) return ans;
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func spiralMatrixIII(rows int, cols int, rStart int, cStart int) [][]int {
	cnt := rows * cols
	ans := [][]int{[]int{rStart, cStart}}
	if cnt == 1 {
		return ans
	}
	for k := 1; ; k += 2 {
		dirs := [][]int{{0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}}
		for _, dir := range dirs {
			r, c, dk := dir[0], dir[1], dir[2]
			for dk > 0 {
				rStart += r
				cStart += c
				if rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols {
					ans = append(ans, []int{rStart, cStart})
					if len(ans) == cnt {
						return ans
					}
				}
				dk--
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function spiralMatrixIII(rows: number, cols: number, rStart: number, cStart: number): number[][] {
    // prettier-ignore
    const dir = [[1,0],[0,1],[-1,0],[0,-1]]
    let [x, y, i, size] = [cStart, rStart, 0, 0];
    const ans: number[][] = [[y, x]];
    const total = rows * cols;

    while (ans.length < total) {
        if (i % 2 === 0) size++;

        for (let j = 0; ans.length < total && j < size; j++) {
            x += dir[i][0];
            y += dir[i][1];

            if (0 <= x && x < cols && 0 <= y && y < rows) {
                ans.push([y, x]);
            }
        }

        i = (i + 1) % 4;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
var spiralMatrixIII = function (rows, cols, rStart, cStart) {
    // prettier-ignore
    const dir = [[1,0],[0,1],[-1,0],[0,-1]]
    let [x, y, i, size] = [cStart, rStart, 0, 0];
    const ans = [[y, x]];
    const total = rows * cols;

    while (ans.length < total) {
        if (i % 2 === 0) size++;

        for (let j = 0; ans.length < total && j < size; j++) {
            x += dir[i][0];
            y += dir[i][1];

            if (0 <= x && x < cols && 0 <= y && y < rows) {
                ans.push([y, x]);
            }
        }

        i = (i + 1) % 4;
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

<p>在 <code>rows x cols</code> 的网格上，你从单元格 <code>(rStart, cStart)</code> 面朝东面开始。网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。</p>

<p>你需要以顺时针按螺旋状行走，访问此网格中的每个位置。每当移动到网格的边界之外时，需要继续在网格之外行走（但稍后可能会返回到网格边界）。</p>

<p>最终，我们到过网格的所有&nbsp;<code>rows x cols</code>&nbsp;个空间。</p>

<p>按照访问顺序返回表示网格位置的坐标列表。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0885.Spiral%20Matrix%20III/images/example_1.png" style="width: 174px; height: 99px;" />
<pre>
<strong>输入：</strong>rows = 1, cols = 4, rStart = 0, cStart = 0
<strong>输出：</strong>[[0,0],[0,1],[0,2],[0,3]]
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0885.Spiral%20Matrix%20III/images/example_2.png" style="width: 202px; height: 142px;" />
<pre>
<strong>输入：</strong>rows = 5, cols = 6, rStart = 1, cStart = 4
<strong>输出：</strong>[[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rows, cols &lt;= 100</code></li>
	<li><code>0 &lt;= rStart &lt; rows</code></li>
	<li><code>0 &lt;= cStart &lt; cols</code></li>
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
    def spiralMatrixIII(
        self, rows: int, cols: int, rStart: int, cStart: int
    ) -> List[List[int]]:
        ans = [[rStart, cStart]]
        if rows * cols == 1:
            return ans
        k = 1
        while True:
            for dr, dc, dk in [[0, 1, k], [1, 0, k], [0, -1, k + 1], [-1, 0, k + 1]]:
                for _ in range(dk):
                    rStart += dr
                    cStart += dc
                    if 0 <= rStart < rows and 0 <= cStart < cols:
                        ans.append([rStart, cStart])
                        if len(ans) == rows * cols:
                            return ans
            k += 2
```

#### Java

```java
class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cnt = rows * cols;
        int[][] ans = new int[cnt][2];
        ans[0] = new int[] {rStart, cStart};
        if (cnt == 1) {
            return ans;
        }
        for (int k = 1, idx = 1;; k += 2) {
            int[][] dirs = new int[][] {{0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}};
            for (int[] dir : dirs) {
                int r = dir[0], c = dir[1], dk = dir[2];
                while (dk-- > 0) {
                    rStart += r;
                    cStart += c;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans[idx++] = new int[] {rStart, cStart};
                        if (idx == cnt) {
                            return ans;
                        }
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cnt = rows * cols;
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        if (cnt == 1) return ans;
        for (int k = 1;; k += 2) {
            vector<vector<int>> dirs = {{0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}};
            for (auto& dir : dirs) {
                int r = dir[0], c = dir[1], dk = dir[2];
                while (dk-- > 0) {
                    rStart += r;
                    cStart += c;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                        if (ans.size() == cnt) return ans;
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func spiralMatrixIII(rows int, cols int, rStart int, cStart int) [][]int {
	cnt := rows * cols
	ans := [][]int{[]int{rStart, cStart}}
	if cnt == 1 {
		return ans
	}
	for k := 1; ; k += 2 {
		dirs := [][]int{{0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}}
		for _, dir := range dirs {
			r, c, dk := dir[0], dir[1], dir[2]
			for dk > 0 {
				rStart += r
				cStart += c
				if rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols {
					ans = append(ans, []int{rStart, cStart})
					if len(ans) == cnt {
						return ans
					}
				}
				dk--
			}
		}
	}
}
```

#### TypeScript

```ts
function spiralMatrixIII(rows: number, cols: number, rStart: number, cStart: number): number[][] {
    // prettier-ignore
    const dir = [[1,0],[0,1],[-1,0],[0,-1]]
    let [x, y, i, size] = [cStart, rStart, 0, 0];
    const ans: number[][] = [[y, x]];
    const total = rows * cols;

    while (ans.length < total) {
        if (i % 2 === 0) size++;

        for (let j = 0; ans.length < total && j < size; j++) {
            x += dir[i][0];
            y += dir[i][1];

            if (0 <= x && x < cols && 0 <= y && y < rows) {
                ans.push([y, x]);
            }
        }

        i = (i + 1) % 4;
    }

    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
var spiralMatrixIII = function (rows, cols, rStart, cStart) {
    // prettier-ignore
    const dir = [[1,0],[0,1],[-1,0],[0,-1]]
    let [x, y, i, size] = [cStart, rStart, 0, 0];
    const ans = [[y, x]];
    const total = rows * cols;

    while (ans.length < total) {
        if (i % 2 === 0) size++;

        for (let j = 0; ans.length < total && j < size; j++) {
            x += dir[i][0];
            y += dir[i][1];

            if (0 <= x && x < cols && 0 <= y && y < rows) {
                ans.push([y, x]);
            }
        }

        i = (i + 1) % 4;
    }

    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [886. 可能的二分法](https://leetcode.cn/problems/possible-bipartition){#886}

{{< tabs "886" >}}

{{% tab "python" %}}
```python
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        g = defaultdict(list)
        for a, b in dislikes:
            a, b = a - 1, b - 1
            g[a].append(b)
            g[b].append(a)
        p = list(range(n))
        for i in range(n):
            for j in g[i]:
                if find(i) == find(j):
                    return False
                p[find(j)] = find(g[i][0])
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public boolean possibleBipartition(int n, int[][] dislikes) {
        p = new int[n];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (var e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (find(i) == find(j)) {
                    return false;
                }
                p[find(j)] = find(g[i].get(0));
            }
        }
        return true;
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        unordered_map<int, vector<int>> g;
        for (auto& e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (find(i) == find(j)) return false;
                p[find(j)] = find(g[i][0]);
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func possibleBipartition(n int, dislikes [][]int) bool {
	p := make([]int, n)
	g := make([][]int, n)
	for i := range p {
		p[i] = i
	}
	for _, e := range dislikes {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for i := 0; i < n; i++ {
		for _, j := range g[i] {
			if find(i) == find(j) {
				return false
			}
			p[find(j)] = find(g[i][0])
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function possibleBipartition(n: number, dislikes: number[][]): boolean {
    const color = new Array(n + 1).fill(0);
    const g = Array.from({ length: n + 1 }, () => []);
    const dfs = (i: number, v: number) => {
        color[i] = v;
        for (const j of g[i]) {
            if (color[j] === color[i] || (color[j] === 0 && dfs(j, 3 ^ v))) {
                return true;
            }
        }
        return false;
    };
    for (const [a, b] of dislikes) {
        g[a].push(b);
        g[b].push(a);
    }
    for (let i = 1; i <= n; i++) {
        if (color[i] === 0 && dfs(i, 1)) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(i: usize, v: usize, color: &mut Vec<usize>, g: &Vec<Vec<usize>>) -> bool {
        color[i] = v;
        for &j in (*g[i]).iter() {
            if color[j] == color[i] || (color[j] == 0 && Self::dfs(j, v ^ 3, color, g)) {
                return true;
            }
        }
        false
    }

    pub fn possible_bipartition(n: i32, dislikes: Vec<Vec<i32>>) -> bool {
        let n = n as usize;
        let mut color = vec![0; n + 1];
        let mut g = vec![Vec::new(); n + 1];
        for d in dislikes.iter() {
            let (i, j) = (d[0] as usize, d[1] as usize);
            g[i].push(j);
            g[j].push(i);
        }
        for i in 1..=n {
            if color[i] == 0 && Self::dfs(i, 1, &mut color, &g) {
                return false;
            }
        }
        true
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一组&nbsp;<code>n</code>&nbsp;人（编号为&nbsp;<code>1, 2, ..., n</code>），&nbsp;我们想把每个人分进<strong>任意</strong>大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。</p>

<p>给定整数 <code>n</code>&nbsp;和数组 <code>dislikes</code>&nbsp;，其中&nbsp;<code>dislikes[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;，表示不允许将编号为 <code>a<sub>i</sub></code>&nbsp;和&nbsp;&nbsp;<code>b<sub>i</sub></code>的人归入同一组。当可以用这种方法将所有人分进两组时，返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 4, dislikes = [[1,2],[1,3],[2,4]]
<strong>输出：</strong>true
<strong>解释：</strong>group1 [1,4], group2 [2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, dislikes = [[1,2],[1,3],[2,3]]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= dislikes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>dislikes[i].length == 2</code></li>
	<li><code>1 &lt;= dislikes[i][j] &lt;= n</code></li>
	<li><code>a<sub>i</sub>&nbsp;&lt; b<sub>i</sub></code></li>
	<li><code>dislikes</code>&nbsp;中每一组都 <strong>不同</strong></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：染色法

我们用两种颜色对图进行染色，如果可以完成染色，那么就说明可以将所有人分进两组。

具体的染色方法如下：

-   初始化所有人的颜色为 $0$，表示还没有染色。
-   遍历所有人，如果当前人没有染色，那么就用颜色 $1$ 对其进行染色，然后将其所有不喜欢的人用颜色 $2$ 进行染色。如果染色过程中出现了冲突，那么就说明无法将所有人分进两组，返回 `false`。
-   如果所有人都染色成功，那么就说明可以将所有人分进两组，返回 `true`。

时间复杂度 $O(n + m)$，其中 $n$, $m$ 分别是人数和不喜欢的关系数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(i, c):
            color[i] = c
            for j in g[i]:
                if color[j] == c:
                    return False
                if color[j] == 0 and not dfs(j, 3 - c):
                    return False
            return True

        g = defaultdict(list)
        color = [0] * n
        for a, b in dislikes:
            a, b = a - 1, b - 1
            g[a].append(b)
            g[b].append(a)
        return all(c or dfs(i, 1) for i, c in enumerate(color))
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] color;

    public boolean possibleBipartition(int n, int[][] dislikes) {
        g = new List[n];
        color = new int[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                if (!dfs(i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean dfs(int i, int c) {
        color[i] = c;
        for (int j : g[i]) {
            if (color[j] == c) {
                return false;
            }
            if (color[j] == 0 && !dfs(j, 3 - c)) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> g;
        for (auto& e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> color(n);
        function<bool(int, int)> dfs = [&](int i, int c) -> bool {
            color[i] = c;
            for (int j : g[i]) {
                if (!color[j] && !dfs(j, 3 - c)) return false;
                if (color[j] == c) return false;
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (!color[i] && !dfs(i, 1)) return false;
        }
        return true;
    }
};
```

#### Go

```go
func possibleBipartition(n int, dislikes [][]int) bool {
	g := make([][]int, n)
	for _, e := range dislikes {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	color := make([]int, n)
	var dfs func(int, int) bool
	dfs = func(i, c int) bool {
		color[i] = c
		for _, j := range g[i] {
			if color[j] == c {
				return false
			}
			if color[j] == 0 && !dfs(j, 3-c) {
				return false
			}
		}
		return true
	}
	for i, c := range color {
		if c == 0 && !dfs(i, 1) {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function possibleBipartition(n: number, dislikes: number[][]): boolean {
    const color = new Array(n + 1).fill(0);
    const g = Array.from({ length: n + 1 }, () => []);
    const dfs = (i: number, v: number) => {
        color[i] = v;
        for (const j of g[i]) {
            if (color[j] === color[i] || (color[j] === 0 && dfs(j, 3 ^ v))) {
                return true;
            }
        }
        return false;
    };
    for (const [a, b] of dislikes) {
        g[a].push(b);
        g[b].push(a);
    }
    for (let i = 1; i <= n; i++) {
        if (color[i] === 0 && dfs(i, 1)) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, v: usize, color: &mut Vec<usize>, g: &Vec<Vec<usize>>) -> bool {
        color[i] = v;
        for &j in (*g[i]).iter() {
            if color[j] == color[i] || (color[j] == 0 && Self::dfs(j, v ^ 3, color, g)) {
                return true;
            }
        }
        false
    }

    pub fn possible_bipartition(n: i32, dislikes: Vec<Vec<i32>>) -> bool {
        let n = n as usize;
        let mut color = vec![0; n + 1];
        let mut g = vec![Vec::new(); n + 1];
        for d in dislikes.iter() {
            let (i, j) = (d[0] as usize, d[1] as usize);
            g[i].push(j);
            g[j].push(i);
        }
        for i in 1..=n {
            if color[i] == 0 && Self::dfs(i, 1, &mut color, &g) {
                return false;
            }
        }
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

并查集是一种树形的数据结构，顾名思义，它用于处理一些不交集的**合并**及**查询**问题。 它支持两种操作：

1. 查找（Find）：确定某个元素处于哪个子集，单次操作时间复杂度 $O(\alpha(n))$
1. 合并（Union）：将两个子集合并成一个集合，单次操作时间复杂度 $O(\alpha(n))$

其中 $\alpha$ 为阿克曼函数的反函数，其增长极其缓慢，也就是说其单次操作的平均运行时间可以认为是一个很小的常数。

以下是并查集的常用模板，需要熟练掌握。其中：

-   `n` 表示节点数
-   `p` 存储每个点的父节点，初始时每个点的父节点都是自己
-   `size` 只有当节点是祖宗节点时才有意义，表示祖宗节点所在集合中，点的数量
-   `find(x)` 函数用于查找 $x$ 所在集合的祖宗节点
-   `union(a, b)` 函数用于合并 $a$ 和 $b$ 所在的集合

```python
p = list(range(n))
size = [1] * n


def find(x):
    if p[x] != x:
        # 路径压缩
        p[x] = find(p[x])
    return p[x]


def union(a, b):
    pa, pb = find(a), find(b)
    if pa == pb:
        return
    p[pa] = pb
    size[pb] += size[pa]
```

对于本题，我们遍历每一个人，他与他不喜欢的人不应该在同一个集合中，如果在同一个集合中，就产生了冲突，直接返回 `false`。如果没有冲突，那么就将他所有不喜欢的人合并到同一个集合中。

遍历结束，说明没有冲突，返回 `true`。

时间复杂度 $O(n + m\times \alpha(n))$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        g = defaultdict(list)
        for a, b in dislikes:
            a, b = a - 1, b - 1
            g[a].append(b)
            g[b].append(a)
        p = list(range(n))
        for i in range(n):
            for j in g[i]:
                if find(i) == find(j):
                    return False
                p[find(j)] = find(g[i][0])
        return True
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean possibleBipartition(int n, int[][] dislikes) {
        p = new int[n];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (var e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (find(i) == find(j)) {
                    return false;
                }
                p[find(j)] = find(g[i].get(0));
            }
        }
        return true;
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        unordered_map<int, vector<int>> g;
        for (auto& e : dislikes) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (find(i) == find(j)) return false;
                p[find(j)] = find(g[i][0]);
            }
        }
        return true;
    }
};
```

#### Go

```go
func possibleBipartition(n int, dislikes [][]int) bool {
	p := make([]int, n)
	g := make([][]int, n)
	for i := range p {
		p[i] = i
	}
	for _, e := range dislikes {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for i := 0; i < n; i++ {
		for _, j := range g[i] {
			if find(i) == find(j) {
				return false
			}
			p[find(j)] = find(g[i][0])
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [887. 鸡蛋掉落](https://leetcode.cn/problems/super-egg-drop){#887}

{{< tabs "887" >}}

{{% tab "python" %}}
```python
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            f[i][1] = i
        for i in range(1, n + 1):
            for j in range(2, k + 1):
                l, r = 1, i
                while l < r:
                    mid = (l + r + 1) >> 1
                    a, b = f[mid - 1][j - 1], f[i - mid][j]
                    if a <= b:
                        l = mid
                    else:
                        r = mid - 1
                f[i][j] = max(f[l - 1][j - 1], f[i - l][j]) + 1
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int superEggDrop(int k, int n) {
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            f[i][1] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                int l = 1, r = i;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    int a = f[mid - 1][j - 1];
                    int b = f[i - mid][j];
                    if (a <= b) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                f[i][j] = Math.max(f[l - 1][j - 1], f[i - l][j]) + 1;
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
    int superEggDrop(int k, int n) {
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            f[i][1] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                int l = 1, r = i;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    int a = f[mid - 1][j - 1];
                    int b = f[i - mid][j];
                    if (a <= b) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                f[i][j] = max(f[l - 1][j - 1], f[i - l][j]) + 1;
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func superEggDrop(k int, n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		f[i][1] = i
	}
	for i := 1; i <= n; i++ {
		for j := 2; j <= k; j++ {
			l, r := 1, i
			for l < r {
				mid := (l + r + 1) >> 1
				a, b := f[mid-1][j-1], f[i-mid][j]
				if a <= b {
					l = mid
				} else {
					r = mid - 1
				}
			}
			f[i][j] = max(f[l-1][j-1], f[i-l][j]) + 1
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function superEggDrop(k: number, n: number): number {
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    for (let i = 1; i <= n; ++i) {
        f[i][1] = i;
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 2; j <= k; ++j) {
            let l = 1;
            let r = i;
            while (l < r) {
                const mid = (l + r + 1) >> 1;
                const a = f[mid - 1][j - 1];
                const b = f[i - mid][j];
                if (a <= b) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            f[i][j] = Math.max(f[l - 1][j - 1], f[i - l][j]) + 1;
        }
    }
    return f[n][k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你 <code>k</code> 枚相同的鸡蛋，并可以使用一栋从第 <code>1</code> 层到第 <code>n</code> 层共有 <code>n</code> 层楼的建筑。</p>

<p>已知存在楼层 <code>f</code> ，满足 <code>0 <= f <= n</code> ，任何从<strong> 高于</strong> <code>f</code> 的楼层落下的鸡蛋都会碎，从 <code>f</code> 楼层或比它低的楼层落下的鸡蛋都不会破。</p>

<p>每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 <code>x</code> 扔下（满足 <code>1 <= x <= n</code>）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 <strong>重复使用</strong> 这枚鸡蛋。</p>

<p>请你计算并返回要确定 <code>f</code> <strong>确切的值</strong> 的 <strong>最小操作次数</strong> 是多少？</p>
 

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 1, n = 2
<strong>输出：</strong>2
<strong>解释：</strong>
鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。 
否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。 
如果它没碎，那么肯定能得出 f = 2 。 
因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 2, n = 6
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>k = 3, n = 14
<strong>输出：</strong>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= 100</code></li>
	<li><code>1 <= n <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 二分查找

我们设计一个函数 $dfs(i, j)$，表示有 $i$ 层楼以及 $j$ 个鸡蛋时，确定 $f$ 值的最小操作次数，那么答案就是 $dfs(n, k)$。

函数 $dfs(i, j)$ 的执行逻辑如下：

如果 $i \lt 1$，说明楼层已经小于等于 $0$，此时返回 $0$；

如果 $j = 1$，说明只有一个鸡蛋，那么只能从第一层开始一层一层试，最坏情况下需要试 $i$ 次，此时返回 $i$；

否则，我们考虑枚举第一个鸡蛋从第 $x$ 层扔下的情况，其中 $1 \le x \le i$。如果鸡蛋在第 $x$ 层扔下时碎了，说明 $f \lt x$，此时我们接下来需要在 $x - 1$ 层下方以及剩下的 $j - 1$ 个鸡蛋确定 $f$ 值，总共需要的最小操作次数为 $dfs(x - 1, j - 1) + 1$ 次；如果鸡蛋在第 $x$ 层扔下时没碎，说明 $f \gt x$，此时我们需要在第 $x + 1$ 层及以上以及剩下的 $j$ 个鸡蛋确定 $f$ 值，总共需要的最小操作次数为 $dfs(i - x, j) + 1$ 次。由于我们要保证最坏情况下操作次数最少，因此 $dfs(i, j) = \min_{1 \le x \le i} \max(dfs(x - 1, j - 1), dfs(i - x, j)) + 1$。

如果按照这样的方式枚举，由于状态数有 $n \times k$，每个状态需要枚举 $n$ 次，那么总时间复杂度达到 $O(n^2 \times k)$，这会超出时间限制，我们考虑如何进行优化。

我们注意到函数 $dfs(x - 1, j - 1)$ 随着 $x$ 的增大而单调递增，而函数 $dfs(i - x, j)$ 随着 $x$ 的增大而单调递减，因此存在一个最优的 $x$ 值使得 $\max(dfs(x - 1, j - 1), dfs(i - x, j))$ 达到最小值。我们可以对 $x$ 进行二分查找，找出这个最优的 $x$ 值。其中 $x$ 是满足 $dfs(x - 1, j - 1) \le dfs(i - x, j)$ 的最大整数。这样我们可以将时间复杂度降低到 $O(n \times k \log n)$。

时间复杂度 $O(n \times k \log n)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别是楼层数和鸡蛋数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i < 1:
                return 0
            if j == 1:
                return i
            l, r = 1, i
            while l < r:
                mid = (l + r + 1) >> 1
                a = dfs(mid - 1, j - 1)
                b = dfs(i - mid, j)
                if a <= b:
                    l = mid
                else:
                    r = mid - 1
            return max(dfs(l - 1, j - 1), dfs(i - l, j)) + 1

        return dfs(n, k)
```

#### Java

```java
class Solution {
    private int[][] f;

    public int superEggDrop(int k, int n) {
        f = new int[n + 1][k + 1];
        return dfs(n, k);
    }

    private int dfs(int i, int j) {
        if (i < 1) {
            return 0;
        }
        if (j == 1) {
            return i;
        }
        if (f[i][j] != 0) {
            return f[i][j];
        }
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int a = dfs(mid - 1, j - 1);
            int b = dfs(i - mid, j);
            if (a <= b) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return f[i][j] = Math.max(dfs(l - 1, j - 1), dfs(i - l, j)) + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int superEggDrop(int k, int n) {
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 1) {
                return 0;
            }
            if (j == 1) {
                return i;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            int l = 1, r = i;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                int a = dfs(mid - 1, j - 1);
                int b = dfs(i - mid, j);
                if (a <= b) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            return f[i][j] = max(dfs(l - 1, j - 1), dfs(i - l, j)) + 1;
        };
        return dfs(n, k);
    }
};
```

#### Go

```go
func superEggDrop(k int, n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i < 1 {
			return 0
		}
		if j == 1 {
			return i
		}
		if f[i][j] != 0 {
			return f[i][j]
		}
		l, r := 1, i
		for l < r {
			mid := (l + r + 1) >> 1
			a, b := dfs(mid-1, j-1), dfs(i-mid, j)
			if a <= b {
				l = mid
			} else {
				r = mid - 1
			}
		}
		f[i][j] = max(dfs(l-1, j-1), dfs(i-l, j)) + 1
		return f[i][j]
	}
	return dfs(n, k)
}
```

#### TypeScript

```ts
function superEggDrop(k: number, n: number): number {
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const dfs = (i: number, j: number): number => {
        if (i < 1) {
            return 0;
        }
        if (j === 1) {
            return i;
        }
        if (f[i][j]) {
            return f[i][j];
        }
        let l = 1;
        let r = i;
        while (l < r) {
            const mid = (l + r + 1) >> 1;
            const a = dfs(mid - 1, j - 1);
            const b = dfs(i - mid, j);
            if (a <= b) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return (f[i][j] = Math.max(dfs(l - 1, j - 1), dfs(i - l, j)) + 1);
    };
    return dfs(n, k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 二分查找

我们也可以使用动态规划的方法解决这个问题。

我们定义 $f[i][j]$ 表示有 $i$ 层楼以及 $j$ 个鸡蛋时，确定 $f$ 值的最小操作次数，那么答案就是 $f[n][k]$。

状态转移方程为 $f[i][j] = \min_{1 \le x \le i} \max(f[x - 1][j - 1], f[i - x][j]) + 1$。

与方法一类似，我们可以使用二分查找来优化 $x$ 的枚举过程。

时间复杂度 $O(n \times k \log n)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别是楼层数和鸡蛋数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            f[i][1] = i
        for i in range(1, n + 1):
            for j in range(2, k + 1):
                l, r = 1, i
                while l < r:
                    mid = (l + r + 1) >> 1
                    a, b = f[mid - 1][j - 1], f[i - mid][j]
                    if a <= b:
                        l = mid
                    else:
                        r = mid - 1
                f[i][j] = max(f[l - 1][j - 1], f[i - l][j]) + 1
        return f[n][k]
```

#### Java

```java
class Solution {
    public int superEggDrop(int k, int n) {
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            f[i][1] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                int l = 1, r = i;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    int a = f[mid - 1][j - 1];
                    int b = f[i - mid][j];
                    if (a <= b) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                f[i][j] = Math.max(f[l - 1][j - 1], f[i - l][j]) + 1;
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
    int superEggDrop(int k, int n) {
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            f[i][1] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                int l = 1, r = i;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    int a = f[mid - 1][j - 1];
                    int b = f[i - mid][j];
                    if (a <= b) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                f[i][j] = max(f[l - 1][j - 1], f[i - l][j]) + 1;
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func superEggDrop(k int, n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		f[i][1] = i
	}
	for i := 1; i <= n; i++ {
		for j := 2; j <= k; j++ {
			l, r := 1, i
			for l < r {
				mid := (l + r + 1) >> 1
				a, b := f[mid-1][j-1], f[i-mid][j]
				if a <= b {
					l = mid
				} else {
					r = mid - 1
				}
			}
			f[i][j] = max(f[l-1][j-1], f[i-l][j]) + 1
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function superEggDrop(k: number, n: number): number {
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    for (let i = 1; i <= n; ++i) {
        f[i][1] = i;
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 2; j <= k; ++j) {
            let l = 1;
            let r = i;
            while (l < r) {
                const mid = (l + r + 1) >> 1;
                const a = f[mid - 1][j - 1];
                const b = f[i - mid][j];
                if (a <= b) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            f[i][j] = Math.max(f[l - 1][j - 1], f[i - l][j]) + 1;
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [888. 公平的糖果交换](https://leetcode.cn/problems/fair-candy-swap){#888}

{{< tabs "888" >}}

{{% tab "python" %}}
```python
class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        diff = (sum(aliceSizes) - sum(bobSizes)) >> 1
        s = set(bobSizes)
        for a in aliceSizes:
            if (b := (a - diff)) in s:
                return [a, b]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int s1 = 0, s2 = 0;
        Set<Integer> s = new HashSet<>();
        for (int a : aliceSizes) {
            s1 += a;
        }
        for (int b : bobSizes) {
            s.add(b);
            s2 += b;
        }
        int diff = (s1 - s2) >> 1;
        for (int a : aliceSizes) {
            int b = a - diff;
            if (s.contains(b)) {
                return new int[] {a, b};
            }
        }
        return null;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int s1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int s2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (s1 - s2) >> 1;
        unordered_set<int> s(bobSizes.begin(), bobSizes.end());
        vector<int> ans;
        for (int& a : aliceSizes) {
            int b = a - diff;
            if (s.count(b)) {
                ans = vector<int>{a, b};
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fairCandySwap(aliceSizes []int, bobSizes []int) []int {
	s1, s2 := 0, 0
	s := map[int]bool{}
	for _, a := range aliceSizes {
		s1 += a
	}
	for _, b := range bobSizes {
		s2 += b
		s[b] = true
	}
	diff := (s1 - s2) / 2
	for _, a := range aliceSizes {
		if b := a - diff; s[b] {
			return []int{a, b}
		}
	}
	return nil
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fairCandySwap(aliceSizes: number[], bobSizes: number[]): number[] {
    const s1 = aliceSizes.reduce((acc, cur) => acc + cur, 0);
    const s2 = bobSizes.reduce((acc, cur) => acc + cur, 0);
    const diff = (s1 - s2) >> 1;
    const s = new Set(bobSizes);
    for (const a of aliceSizes) {
        const b = a - diff;
        if (s.has(b)) {
            return [a, b];
        }
    }
    return [];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>爱丽丝和鲍勃拥有不同总数量的糖果。给你两个数组 <code>aliceSizes</code> 和 <code>bobSizes</code> ，<code>aliceSizes[i]</code> 是爱丽丝拥有的第 <code>i</code> 盒糖果中的糖果数量，<code>bobSizes[j]</code> 是鲍勃拥有的第 <code>j</code> 盒糖果中的糖果数量。</p>

<p>两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。一个人拥有的糖果总数量是他们每盒糖果数量的总和。</p>

<p>返回一个整数数组 <code>answer</code>，其中 <code>answer[0]</code> 是爱丽丝必须交换的糖果盒中的糖果的数目，<code>answer[1]</code> 是鲍勃必须交换的糖果盒中的糖果的数目。如果存在多个答案，你可以返回其中 <strong>任何一个</strong> 。题目测试用例保证存在与输入对应的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>aliceSizes = [1,1], bobSizes = [2,2]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>aliceSizes = [1,2], bobSizes = [2,3]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>aliceSizes = [2], bobSizes = [1,3]
<strong>输出：</strong>[2,3]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>aliceSizes = [1,2,5], bobSizes = [2,4]
<strong>输出：</strong>[5,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= aliceSizes.length, bobSizes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= aliceSizes[i], bobSizes[j] &lt;= 10<sup>5</sup></code></li>
	<li>爱丽丝和鲍勃的糖果总数量不同。</li>
	<li>题目数据保证对于给定的输入至少存在一个有效答案。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以先计算出爱丽丝和鲍勃的糖果总数之差，除以二得到需要交换的糖果数之差 $\textit{diff}$，用一个哈希表 $\textit{s}$ 存储鲍勃的糖果盒中的糖果数，然后遍历爱丽丝的糖果盒，对于每个糖果数 $\textit{a}$，我们判断 $\textit{a} - \textit{diff}$ 是否在哈希表 $\textit{s}$ 中，如果存在，说明找到了一组答案，返回即可。

时间复杂度 $O(m + n)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别是爱丽丝和鲍勃的糖果盒的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        diff = (sum(aliceSizes) - sum(bobSizes)) >> 1
        s = set(bobSizes)
        for a in aliceSizes:
            if (b := (a - diff)) in s:
                return [a, b]
```

#### Java

```java
class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int s1 = 0, s2 = 0;
        Set<Integer> s = new HashSet<>();
        for (int a : aliceSizes) {
            s1 += a;
        }
        for (int b : bobSizes) {
            s.add(b);
            s2 += b;
        }
        int diff = (s1 - s2) >> 1;
        for (int a : aliceSizes) {
            int b = a - diff;
            if (s.contains(b)) {
                return new int[] {a, b};
            }
        }
        return null;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int s1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int s2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (s1 - s2) >> 1;
        unordered_set<int> s(bobSizes.begin(), bobSizes.end());
        vector<int> ans;
        for (int& a : aliceSizes) {
            int b = a - diff;
            if (s.count(b)) {
                ans = vector<int>{a, b};
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func fairCandySwap(aliceSizes []int, bobSizes []int) []int {
	s1, s2 := 0, 0
	s := map[int]bool{}
	for _, a := range aliceSizes {
		s1 += a
	}
	for _, b := range bobSizes {
		s2 += b
		s[b] = true
	}
	diff := (s1 - s2) / 2
	for _, a := range aliceSizes {
		if b := a - diff; s[b] {
			return []int{a, b}
		}
	}
	return nil
}
```

#### TypeScript

```ts
function fairCandySwap(aliceSizes: number[], bobSizes: number[]): number[] {
    const s1 = aliceSizes.reduce((acc, cur) => acc + cur, 0);
    const s2 = bobSizes.reduce((acc, cur) => acc + cur, 0);
    const diff = (s1 - s2) >> 1;
    const s = new Set(bobSizes);
    for (const a of aliceSizes) {
        const b = a - diff;
        if (s.has(b)) {
            return [a, b];
        }
    }
    return [];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [889. 根据前序和后序遍历构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal){#889}

{{< tabs "889" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:
                return None
            root = TreeNode(preorder[i])
            if n == 1:
                return root
            k = pos[preorder[i + 1]]
            m = k - j + 1
            root.left = dfs(i + 1, j, m)
            root.right = dfs(i + m + 1, k + 1, n - m - 1)
            return root

        pos = {x: i for i, x in enumerate(postorder)}
        return dfs(0, 0, len(preorder))
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
    private Map<Integer, Integer> pos = new HashMap<>();
    private int[] preorder;

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        this.preorder = preorder;
        for (int i = 0; i < postorder.length; ++i) {
            pos.put(postorder[i], i);
        }
        return dfs(0, 0, preorder.length);
    }

    private TreeNode dfs(int i, int j, int n) {
        if (n <= 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[i]);
        if (n == 1) {
            return root;
        }
        int k = pos.get(preorder[i + 1]);
        int m = k - j + 1;
        root.left = dfs(i + 1, j, m);
        root.right = dfs(i + m + 1, k + 1, n - m - 1);
        return root;
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> pos;
        int n = postorder.size();
        for (int i = 0; i < n; ++i) {
            pos[postorder[i]] = i;
        }
        function<TreeNode*(int, int, int)> dfs = [&](int i, int j, int n) -> TreeNode* {
            if (n <= 0) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[i]);
            if (n == 1) {
                return root;
            }
            int k = pos[preorder[i + 1]];
            int m = k - j + 1;
            root->left = dfs(i + 1, j, m);
            root->right = dfs(i + m + 1, k + 1, n - m - 1);
            return root;
        };
        return dfs(0, 0, n);
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
func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	pos := map[int]int{}
	for i, x := range postorder {
		pos[x] = i
	}
	var dfs func(int, int, int) *TreeNode
	dfs = func(i, j, n int) *TreeNode {
		if n <= 0 {
			return nil
		}
		root := &TreeNode{Val: preorder[i]}
		if n == 1 {
			return root
		}
		k := pos[preorder[i+1]]
		m := k - j + 1
		root.Left = dfs(i+1, j, m)
		root.Right = dfs(i+m+1, k+1, n-m-1)
		return root
	}
	return dfs(0, 0, len(preorder))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function constructFromPrePost(preorder: number[], postorder: number[]): TreeNode | null {
    const pos: Map<number, number> = new Map();
    const n = postorder.length;
    for (let i = 0; i < n; ++i) {
        pos.set(postorder[i], i);
    }
    const dfs = (i: number, j: number, n: number): TreeNode | null => {
        if (n <= 0) {
            return null;
        }
        const root = new TreeNode(preorder[i]);
        if (n === 1) {
            return root;
        }
        const k = pos.get(preorder[i + 1])!;
        const m = k - j + 1;
        root.left = dfs(i + 1, j, m);
        root.right = dfs(i + 1 + m, k + 1, n - 1 - m);
        return root;
    };
    return dfs(0, 0, n);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个整数数组，<code>preorder</code>&nbsp;和 <code>postorder</code> ，其中 <code>preorder</code> 是一个具有 <strong>无重复</strong> 值的二叉树的前序遍历，<code>postorder</code> 是同一棵树的后序遍历，重构并返回二叉树。</p>

<p>如果存在多个答案，您可以返回其中 <strong>任何</strong> 一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0889.Construct%20Binary%20Tree%20from%20Preorder%20and%20Postorder%20Traversal/images/lc-prepost.jpg" style="height: 265px; width: 304px;" /></p>

<pre>
<strong>输入：</strong>preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
<strong>输出：</strong>[1,2,3,4,5,6,7]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> preorder = [1], postorder = [1]
<strong>输出:</strong> [1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 30</code></li>
	<li><code>1 &lt;= preorder[i] &lt;= preorder.length</code></li>
	<li><code>preorder</code>&nbsp;中所有值都 <strong>不同</strong></li>
	<li><code>postorder.length == preorder.length</code></li>
	<li><code>1 &lt;= postorder[i] &lt;= postorder.length</code></li>
	<li><code>postorder</code>&nbsp;中所有值都 <strong>不同</strong></li>
	<li>保证 <code>preorder</code>&nbsp;和 <code>postorder</code>&nbsp;是同一棵二叉树的前序遍历和后序遍历</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

前序遍历的顺序是：根节点 -> 左子树 -> 右子树，后序遍历的顺序是：左子树 -> 右子树 -> 根节点。

因此，二叉树的根节点一定是前序遍历的第一个节点，也是后序遍历的最后一个节点。

接下来，我们需要确定二叉树的左子树范围和右子树范围。

如果二叉树有左子树，那么左子树的根节点一定是前序遍历的第二个节点；如果二叉树没有左子树，那么前序遍历的第二个节点一定是右子树的根节点。由于这两种情况下，后序遍历的结果是一样的，因此，我们可以把前序遍历的第二个节点作为左子树的根节点，然后找到它在后序遍历中的位置，这样就确定了左子树的范围。

具体地，我们设计一个递归函数 $dfs(a, b, c, d)$，其中 $[a, b]$ 表示前序遍历的范围，而 $[c, d]$ 表示后序遍历的范围。这个函数的功能是根据前序遍历 $[a, b]$ 和后序遍历 $[c, d]$ 构造出二叉树的根节点。那么答案就是 $dfs(0, n - 1, 0, n - 1)$，其中 $n$ 是前序遍历的长度。

函数 $dfs(a, b, c, d)$ 的执行步骤如下：

1. 如果 $a > b$，说明范围为空，直接返回空节点。
1. 否则，我们构造一个新的节点 $root$，它的值为前序遍历中的第一个节点的值，也就是 $preorder[a]$。
1. 如果 $a$ 等于 $b$，说明 $root$ 没有左子树也没有右子树，直接返回 $root$。
1. 否则，左子树的根节点的值为 $preorder[a + 1]$，我们在后序遍历中找到 $preorder[a + 1]$ 的位置，记为 $i$。那么左子树的节点个数 $m = i - c + 1$，由此可知左子树在前序遍历中的范围是 $[a + 1, a + m]$，后序遍历中的范围是 $[c, i]$，右子树在前序遍历中的范围是 $[a + m + 1, b]$，后序遍历中的范围是 $[i + 1, d - 1]$。
1. 知道了左右子树的范围，我们就可以递归地重建左右子树，然后将左右子树的根节点分别作为 $root$ 的左右子节点。最后返回 $root$。

在函数 $dfs(a, b, c, d)$ 中，我们需要用到一个哈希表 $pos$，它存储了后序遍历中每个节点的位置。在函数的开头，我们可以先计算出这个哈希表，这样就可以在 $O(1)$ 的时间内找到任意节点在后序遍历中的位置。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点数。

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
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        def dfs(a: int, b: int, c: int, d: int) -> Optional[TreeNode]:
            if a > b:
                return None
            root = TreeNode(preorder[a])
            if a == b:
                return root
            i = pos[preorder[a + 1]]
            m = i - c + 1
            root.left = dfs(a + 1, a + m, c, i)
            root.right = dfs(a + m + 1, b, i + 1, d - 1)
            return root

        pos = {x: i for i, x in enumerate(postorder)}
        return dfs(0, len(preorder) - 1, 0, len(postorder) - 1)
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
    private Map<Integer, Integer> pos = new HashMap<>();
    private int[] preorder;

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        this.preorder = preorder;
        for (int i = 0; i < postorder.length; ++i) {
            pos.put(postorder[i], i);
        }
        return dfs(0, preorder.length - 1, 0, postorder.length - 1);
    }

    private TreeNode dfs(int a, int b, int c, int d) {
        if (a > b) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[a]);
        if (a == b) {
            return root;
        }
        int i = pos.get(preorder[a + 1]);
        int m = i - c + 1;
        root.left = dfs(a + 1, a + m, c, i);
        root.right = dfs(a + m + 1, b, i + 1, d - 1);
        return root;
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> pos;
        int n = postorder.size();
        for (int i = 0; i < n; ++i) {
            pos[postorder[i]] = i;
        }
        function<TreeNode*(int, int, int, int)> dfs = [&](int a, int b, int c, int d) -> TreeNode* {
            if (a > b) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[a]);
            if (a == b) {
                return root;
            }
            int i = pos[preorder[a + 1]];
            int m = i - c + 1;
            root->left = dfs(a + 1, a + m, c, i);
            root->right = dfs(a + m + 1, b, i + 1, d - 1);
            return root;
        };
        return dfs(0, n - 1, 0, n - 1);
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
func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	pos := map[int]int{}
	for i, x := range postorder {
		pos[x] = i
	}
	var dfs func(int, int, int, int) *TreeNode
	dfs = func(a, b, c, d int) *TreeNode {
		if a > b {
			return nil
		}
		root := &TreeNode{Val: preorder[a]}
		if a == b {
			return root
		}
		i := pos[preorder[a+1]]
		m := i - c + 1
		root.Left = dfs(a+1, a+m, c, i)
		root.Right = dfs(a+m+1, b, i+1, d-1)
		return root
	}
	return dfs(0, len(preorder)-1, 0, len(postorder)-1)
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function constructFromPrePost(preorder: number[], postorder: number[]): TreeNode | null {
    const pos: Map<number, number> = new Map();
    const n = postorder.length;
    for (let i = 0; i < n; ++i) {
        pos.set(postorder[i], i);
    }
    const dfs = (a: number, b: number, c: number, d: number): TreeNode | null => {
        if (a > b) {
            return null;
        }
        const root = new TreeNode(preorder[a]);
        if (a === b) {
            return root;
        }
        const i = pos.get(preorder[a + 1])!;
        const m = i - c + 1;
        root.left = dfs(a + 1, a + m, c, i);
        root.right = dfs(a + m + 1, b, i + 1, d - 1);
        return root;
    };
    return dfs(0, n - 1, 0, n - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：递归的另一种写法

我们也可以设计一个递归函数 $dfs(i, j, n)$，其中 $i$ 和 $j$ 表示前序遍历和后序遍历的起点，而 $n$ 表示节点个数。这个函数的功能是根据前序遍历 $[i, i + n - 1]$ 和后序遍历 $[j, j + n - 1]$ 构造出二叉树的根节点。那么答案就是 $dfs(0, 0, n)$，其中 $n$ 是前序遍历的长度。

函数 $dfs(i, j, n)$ 的执行步骤如下：

1. 如果 $n = 0$，说明范围为空，直接返回空节点。
1. 否则，我们构造一个新的节点 $root$，它的值为前序遍历中的第一个节点的值，也就是 $preorder[i]$。
1. 如果 $n = 1$，说明 $root$ 没有左子树也没有右子树，直接返回 $root$。
1. 否则，左子树的根节点的值为 $preorder[i + 1]$，我们在后序遍历中找到 $preorder[i + 1]$ 的位置，记为 $k$。那么左子树的节点个数 $m = k - j + 1$，右子树的节点数为 $n - m - 1$。我们递归地重建左右子树，然后将左右子树的根节点分别作为 $root$ 的左右子节点。最后返回 $root$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点数。

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
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        def dfs(i: int, j: int, n: int) -> Optional[TreeNode]:
            if n <= 0:
                return None
            root = TreeNode(preorder[i])
            if n == 1:
                return root
            k = pos[preorder[i + 1]]
            m = k - j + 1
            root.left = dfs(i + 1, j, m)
            root.right = dfs(i + m + 1, k + 1, n - m - 1)
            return root

        pos = {x: i for i, x in enumerate(postorder)}
        return dfs(0, 0, len(preorder))
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
    private Map<Integer, Integer> pos = new HashMap<>();
    private int[] preorder;

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        this.preorder = preorder;
        for (int i = 0; i < postorder.length; ++i) {
            pos.put(postorder[i], i);
        }
        return dfs(0, 0, preorder.length);
    }

    private TreeNode dfs(int i, int j, int n) {
        if (n <= 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[i]);
        if (n == 1) {
            return root;
        }
        int k = pos.get(preorder[i + 1]);
        int m = k - j + 1;
        root.left = dfs(i + 1, j, m);
        root.right = dfs(i + m + 1, k + 1, n - m - 1);
        return root;
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> pos;
        int n = postorder.size();
        for (int i = 0; i < n; ++i) {
            pos[postorder[i]] = i;
        }
        function<TreeNode*(int, int, int)> dfs = [&](int i, int j, int n) -> TreeNode* {
            if (n <= 0) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[i]);
            if (n == 1) {
                return root;
            }
            int k = pos[preorder[i + 1]];
            int m = k - j + 1;
            root->left = dfs(i + 1, j, m);
            root->right = dfs(i + m + 1, k + 1, n - m - 1);
            return root;
        };
        return dfs(0, 0, n);
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
func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	pos := map[int]int{}
	for i, x := range postorder {
		pos[x] = i
	}
	var dfs func(int, int, int) *TreeNode
	dfs = func(i, j, n int) *TreeNode {
		if n <= 0 {
			return nil
		}
		root := &TreeNode{Val: preorder[i]}
		if n == 1 {
			return root
		}
		k := pos[preorder[i+1]]
		m := k - j + 1
		root.Left = dfs(i+1, j, m)
		root.Right = dfs(i+m+1, k+1, n-m-1)
		return root
	}
	return dfs(0, 0, len(preorder))
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function constructFromPrePost(preorder: number[], postorder: number[]): TreeNode | null {
    const pos: Map<number, number> = new Map();
    const n = postorder.length;
    for (let i = 0; i < n; ++i) {
        pos.set(postorder[i], i);
    }
    const dfs = (i: number, j: number, n: number): TreeNode | null => {
        if (n <= 0) {
            return null;
        }
        const root = new TreeNode(preorder[i]);
        if (n === 1) {
            return root;
        }
        const k = pos.get(preorder[i + 1])!;
        const m = k - j + 1;
        root.left = dfs(i + 1, j, m);
        root.right = dfs(i + 1 + m, k + 1, n - 1 - m);
        return root;
    };
    return dfs(0, 0, n);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
