---
title: "1310_子数组异或查询"
date: 2025-10-08T18:37:12+08:00
weight: 2
tags: [二叉树, 位运算, 前缀和, 动态规划, 哈希函数, 哈希表, 图, 字典树, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 树, 深度优先搜索, 滚动哈希, 矩阵]
---

{{< markmap >}}
### [1310_子数组异或查询](#1310)
#### [位运算](#1310)
#### [数组](#1310)
#### [前缀和](#1310)
### [1311_获取你好友已观看的视频](#1311)
#### [广度优先搜索](#1311)
#### [图](#1311)
#### [数组](#1311)
#### [哈希表](#1311)
#### [排序](#1311)
### [1312_让字符串成为回文串的最少插入次数](#1312)
#### [字符串](#1312)
#### [动态规划](#1312)
### [1313_解压缩编码列表](#1313)
#### [数组](#1313)
### [1314_矩阵区域和](#1314)
#### [数组](#1314)
#### [矩阵](#1314)
#### [前缀和](#1314)
### [1315_祖父节点值为偶数的节点和](#1315)
#### [树](#1315)
#### [深度优先搜索](#1315)
#### [广度优先搜索](#1315)
#### [二叉树](#1315)
### [1316_不同的循环子字符串](#1316)
#### [字典树](#1316)
#### [字符串](#1316)
#### [哈希函数](#1316)
#### [滚动哈希](#1316)
### [1317_将整数转换为两个无零整数的和](#1317)
#### [数学](#1317)
### [1318_或运算的最小翻转次数](#1318)
#### [位运算](#1318)
### [1319_连通网络的操作次数](#1319)
#### [深度优先搜索](#1319)
#### [广度优先搜索](#1319)
#### [并查集](#1319)
#### [图](#1319)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1310_子数组异或查询
___
#### 位运算
___
#### 数组
___
#### 前缀和
---
### 1311_获取你好友已观看的视频
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1312_让字符串成为回文串的最少插入次数
___
#### 字符串
___
#### 动态规划
---
### 1313_解压缩编码列表
___
#### 数组
---
### 1314_矩阵区域和
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 1315_祖父节点值为偶数的节点和
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 1316_不同的循环子字符串
___
#### 字典树
___
#### 字符串
___
#### 哈希函数
___
#### 滚动哈希
---
### 1317_将整数转换为两个无零整数的和
___
#### 数学
---
### 1318_或运算的最小翻转次数
___
#### 位运算
---
### 1319_连通网络的操作次数
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 前缀和 |
| 动态规划 | 哈希函数 | 哈希表 |
| 图 | 字典树 | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 树 |
| 深度优先搜索 | 滚动哈希 | 矩阵 |

# [1310. 子数组异或查询](https://leetcode.cn/problems/xor-queries-of-a-subarray){#1310}

{{< tabs "1310" >}}

{{% tab "python" %}}
```python
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        s = list(accumulate(arr, xor, initial=0))
        return [s[r + 1] ^ s[l] for l, r in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] s = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = s[r + 1] ^ s[l];
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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int s[n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(s[r + 1] ^ s[l]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func xorQueries(arr []int, queries [][]int) (ans []int) {
	n := len(arr)
	s := make([]int, n+1)
	for i, x := range arr {
		s[i+1] = s[i] ^ x
	}
	for _, q := range queries {
		l, r := q[0], q[1]
		ans = append(ans, s[r+1]^s[l])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function xorQueries(arr: number[], queries: number[][]): number[] {
    const n = arr.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }
    return queries.map(([l, r]) => s[r + 1] ^ s[l]);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function (arr, queries) {
    const n = arr.length;
    const s = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }
    return queries.map(([l, r]) => s[r + 1] ^ s[l]);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个正整数数组 <code>arr</code>，现给你一个对应的查询数组 <code>queries</code>，其中 <code>queries[i] = [L<sub>i, </sub>R<sub>i</sub>]</code>。</p>

<p>对于每个查询 <code>i</code>，请你计算从 <code>L<sub>i</sub></code> 到 <code>R<sub>i</sub></code> 的 <strong>XOR</strong> 值（即 <code>arr[L<sub>i</sub>] <strong>xor</strong> arr[L<sub>i</sub>+1] <strong>xor</strong> ... <strong>xor</strong> arr[R<sub>i</sub>]</code>）作为本次查询的结果。</p>

<p>并返回一个包含给定查询 <code>queries</code> 所有结果的数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
<strong>输出：</strong>[2,7,14,8] 
<strong>解释：</strong>
数组中元素的二进制表示形式是：
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
<strong>输出：</strong>[8,0,4,4]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 3 * 10^4</code></li>
	<li><code>1 <= arr[i] <= 10^9</code></li>
	<li><code>1 <= queries.length <= 3 * 10^4</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 <= queries[i][0] <= queries[i][1] < arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀异或

我们可以用一个长度为 $n+1$ 的前缀异或数组 $s$ 来存储数组 $\textit{arr}$ 的前缀异或结果，其中 $s[i] = s[i-1] \oplus \textit{arr}[i-1]$，即 $s[i]$ 表示 $\textit{arr}$ 的前 $i$ 个元素的异或结果。

那么对于一个查询 $[l,r]$，我们可以得到：

$$
\begin{aligned}
\textit{arr}[l] \oplus \textit{arr}[l+1] \oplus \cdots \oplus \textit{arr}[r] &= (\textit{arr}[0] \oplus \textit{arr}[1] \oplus \cdots \oplus \textit{arr}[l-1]) \oplus (\textit{arr}[0] \oplus \textit{arr}[1] \oplus \cdots \oplus \textit{arr}[r]) \\
&= s[l] \oplus s[r+1]
\end{aligned}
$$

时间复杂度 $O(n+m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $\textit{arr}$ 的长度和查询数组 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        s = list(accumulate(arr, xor, initial=0))
        return [s[r + 1] ^ s[l] for l, r in queries]
```

#### Java

```java
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] s = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = s[r + 1] ^ s[l];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int s[n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(s[r + 1] ^ s[l]);
        }
        return ans;
    }
};
```

#### Go

```go
func xorQueries(arr []int, queries [][]int) (ans []int) {
	n := len(arr)
	s := make([]int, n+1)
	for i, x := range arr {
		s[i+1] = s[i] ^ x
	}
	for _, q := range queries {
		l, r := q[0], q[1]
		ans = append(ans, s[r+1]^s[l])
	}
	return
}
```

#### TypeScript

```ts
function xorQueries(arr: number[], queries: number[][]): number[] {
    const n = arr.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }
    return queries.map(([l, r]) => s[r + 1] ^ s[l]);
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function (arr, queries) {
    const n = arr.length;
    const s = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] ^ arr[i];
    }
    return queries.map(([l, r]) => s[r + 1] ^ s[l]);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1311. 获取你好友已观看的视频](https://leetcode.cn/problems/get-watched-videos-by-your-friends){#1311}

{{< tabs "1311" >}}

{{% tab "python" %}}
```python
class Solution:
    def watchedVideosByFriends(
        self,
        watchedVideos: List[List[str]],
        friends: List[List[int]],
        id: int,
        level: int,
    ) -> List[str]:
        q = deque([id])
        vis = {id}
        for _ in range(level):
            for _ in range(len(q)):
                i = q.popleft()
                for j in friends[i]:
                    if j not in vis:
                        vis.add(j)
                        q.append(j)
        cnt = Counter()
        for i in q:
            for v in watchedVideos[i]:
                cnt[v] += 1
        return sorted(cnt.keys(), key=lambda k: (cnt[k], k))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> watchedVideosByFriends(
        List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(id);
        int n = friends.length;
        boolean[] vis = new boolean[n];
        vis[id] = true;
        while (level-- > 0) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.poll();
                for (int j : friends[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
            }
        }
        Map<String, Integer> cnt = new HashMap<>();
        for (int i : q) {
            for (var v : watchedVideos.get(i)) {
                cnt.merge(v, 1, Integer::sum);
            }
        }
        List<String> ans = new ArrayList<>(cnt.keySet());
        ans.sort((a, b) -> {
            int x = cnt.get(a), y = cnt.get(b);
            return x == y ? a.compareTo(b) : Integer.compare(x, y);
        });
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q{{id}};
        int n = friends.size();
        vector<bool> vis(n);
        vis[id] = true;
        while (level--) {
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                for (int j : friends[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        unordered_map<string, int> cnt;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (const auto& v : watchedVideos[i]) {
                cnt[v]++;
            }
        }
        vector<string> ans;
        for (const auto& [key, _] : cnt) {
            ans.push_back(key);
        }
        sort(ans.begin(), ans.end(), [&cnt](const string& a, const string& b) {
            return cnt[a] == cnt[b] ? a < b : cnt[a] < cnt[b];
        });
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func watchedVideosByFriends(watchedVideos [][]string, friends [][]int, id int, level int) []string {
	q := []int{id}
	n := len(friends)
	vis := make([]bool, n)
	vis[id] = true
	for level > 0 {
		level--
		nextQ := []int{}
		for _, i := range q {
			for _, j := range friends[i] {
				if !vis[j] {
					vis[j] = true
					nextQ = append(nextQ, j)
				}
			}
		}
		q = nextQ
	}
	cnt := make(map[string]int)
	for _, i := range q {
		for _, v := range watchedVideos[i] {
			cnt[v]++
		}
	}
	ans := []string{}
	for key := range cnt {
		ans = append(ans, key)
	}
	sort.Slice(ans, func(i, j int) bool {
		if cnt[ans[i]] == cnt[ans[j]] {
			return ans[i] < ans[j]
		}
		return cnt[ans[i]] < cnt[ans[j]]
	})
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function watchedVideosByFriends(
    watchedVideos: string[][],
    friends: number[][],
    id: number,
    level: number,
): string[] {
    let q: number[] = [id];
    const n: number = friends.length;
    const vis: boolean[] = Array(n).fill(false);
    vis[id] = true;
    while (level-- > 0) {
        const nq: number[] = [];
        for (const i of q) {
            for (const j of friends[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    nq.push(j);
                }
            }
        }
        q = nq;
    }
    const cnt: { [key: string]: number } = {};
    for (const i of q) {
        for (const v of watchedVideos[i]) {
            cnt[v] = (cnt[v] || 0) + 1;
        }
    }
    const ans: string[] = Object.keys(cnt);
    ans.sort((a, b) => {
        if (cnt[a] === cnt[b]) {
            return a.localeCompare(b);
        }
        return cnt[a] - cnt[b];
    });
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有&nbsp;<code>n</code> 个人，每个人都有一个&nbsp; <code>0</code>&nbsp;到&nbsp;<code>n-1</code>&nbsp;的唯一&nbsp;<em>id</em>&nbsp;。</p>

<p>给你数组 <code>watchedVideos</code>&nbsp; 和&nbsp;<code>friends</code>&nbsp;，其中&nbsp;<code>watchedVideos[i]</code>&nbsp; 和&nbsp;<code>friends[i]</code>&nbsp;分别表示&nbsp;<code>id = i</code>&nbsp;的人观看过的视频列表和他的好友列表。</p>

<p>Level&nbsp;<strong>1</strong>&nbsp;的视频包含所有你好友观看过的视频，level&nbsp;<strong>2</strong>&nbsp;的视频包含所有你好友的好友观看过的视频，以此类推。一般的，Level 为 <strong>k</strong>&nbsp;的视频包含所有从你出发，最短距离为&nbsp;<strong>k</strong>&nbsp;的好友观看过的视频。</p>

<p>给定你的&nbsp;<code>id</code>&nbsp; 和一个&nbsp;<code>level</code>&nbsp;值，请你找出所有指定 <code>level</code> 的视频，并将它们按观看频率升序返回。如果有频率相同的视频，请将它们按字母顺序从小到大排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1311.Get%20Watched%20Videos%20by%20Your%20Friends/images/leetcode_friends_1.png" style="height: 179px; width: 129px;"></strong></p>

<pre><strong>输入：</strong>watchedVideos = [[&quot;A&quot;,&quot;B&quot;],[&quot;C&quot;],[&quot;B&quot;,&quot;C&quot;],[&quot;D&quot;]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
<strong>输出：</strong>[&quot;B&quot;,&quot;C&quot;] 
<strong>解释：</strong>
你的 id 为 0（绿色），你的朋友包括（黄色）：
id 为 1 -&gt; watchedVideos = [&quot;C&quot;]&nbsp;
id 为 2 -&gt; watchedVideos = [&quot;B&quot;,&quot;C&quot;]&nbsp;
你朋友观看过视频的频率为：
B -&gt; 1&nbsp;
C -&gt; 2
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1311.Get%20Watched%20Videos%20by%20Your%20Friends/images/leetcode_friends_2.png" style="height: 179px; width: 129px;"></strong></p>

<pre><strong>输入：</strong>watchedVideos = [[&quot;A&quot;,&quot;B&quot;],[&quot;C&quot;],[&quot;B&quot;,&quot;C&quot;],[&quot;D&quot;]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
<strong>输出：</strong>[&quot;D&quot;]
<strong>解释：</strong>
你的 id 为 0（绿色），你朋友的朋友只有一个人，他的 id 为 3（黄色）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == watchedVideos.length ==&nbsp;friends.length</code></li>
	<li><code>2 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;watchedVideos[i].length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;watchedVideos[i][j].length &lt;= 8</code></li>
	<li><code>0 &lt;= friends[i].length &lt; n</code></li>
	<li><code>0 &lt;= friends[i][j]&nbsp;&lt; n</code></li>
	<li><code>0 &lt;= id &lt; n</code></li>
	<li><code>1 &lt;= level &lt; n</code></li>
	<li>如果&nbsp;<code>friends[i]</code> 包含&nbsp;<code>j</code>&nbsp;，那么&nbsp;<code>friends[j]</code> 包含&nbsp;<code>i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索的方法，从 $\textit{id}$ 出发，找到所有距离为 $\textit{level}$ 的好友，然后统计这些好友观看的视频。

具体地，我们可以使用一个队列 $\textit{q}$ 来存储当前层的好友，初始时将 $\textit{id}$ 加入队列 $\textit{q}$ 中，用一个哈希表或者布尔数组 $\textit{vis}$ 来记录已经访问过的好友，然后进行 $\textit{level}$ 次循环，每次循环将队列中的所有好友出队，并将他们的好友加入队列，直到找到所有距禒为 $\textit{level}$ 的好友。

然后，我们使用一个哈希表 $\textit{cnt}$ 来统计这些好友观看的视频及其频率，最后将哈希表中的键值对按照频率升序排序，如果频率相同，则按照视频名称升序排序。最后返回排序后的视频名称列表。

时间复杂度 $O(n + m + v \times \log v)$，空间复杂度 $O(n + v)$。其中 $n$ 和 $m$ 分别是数组 $\textit{watchedVideos}$ 和 $\textit{friends}$ 的长度，而 $v$ 是所有好友观看的视频数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def watchedVideosByFriends(
        self,
        watchedVideos: List[List[str]],
        friends: List[List[int]],
        id: int,
        level: int,
    ) -> List[str]:
        q = deque([id])
        vis = {id}
        for _ in range(level):
            for _ in range(len(q)):
                i = q.popleft()
                for j in friends[i]:
                    if j not in vis:
                        vis.add(j)
                        q.append(j)
        cnt = Counter()
        for i in q:
            for v in watchedVideos[i]:
                cnt[v] += 1
        return sorted(cnt.keys(), key=lambda k: (cnt[k], k))
```

#### Java

```java
class Solution {
    public List<String> watchedVideosByFriends(
        List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(id);
        int n = friends.length;
        boolean[] vis = new boolean[n];
        vis[id] = true;
        while (level-- > 0) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.poll();
                for (int j : friends[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
                    }
                }
            }
        }
        Map<String, Integer> cnt = new HashMap<>();
        for (int i : q) {
            for (var v : watchedVideos.get(i)) {
                cnt.merge(v, 1, Integer::sum);
            }
        }
        List<String> ans = new ArrayList<>(cnt.keySet());
        ans.sort((a, b) -> {
            int x = cnt.get(a), y = cnt.get(b);
            return x == y ? a.compareTo(b) : Integer.compare(x, y);
        });
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q{{id}};
        int n = friends.size();
        vector<bool> vis(n);
        vis[id] = true;
        while (level--) {
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                for (int j : friends[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        unordered_map<string, int> cnt;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (const auto& v : watchedVideos[i]) {
                cnt[v]++;
            }
        }
        vector<string> ans;
        for (const auto& [key, _] : cnt) {
            ans.push_back(key);
        }
        sort(ans.begin(), ans.end(), [&cnt](const string& a, const string& b) {
            return cnt[a] == cnt[b] ? a < b : cnt[a] < cnt[b];
        });
        return ans;
    }
};
```

#### Go

```go
func watchedVideosByFriends(watchedVideos [][]string, friends [][]int, id int, level int) []string {
	q := []int{id}
	n := len(friends)
	vis := make([]bool, n)
	vis[id] = true
	for level > 0 {
		level--
		nextQ := []int{}
		for _, i := range q {
			for _, j := range friends[i] {
				if !vis[j] {
					vis[j] = true
					nextQ = append(nextQ, j)
				}
			}
		}
		q = nextQ
	}
	cnt := make(map[string]int)
	for _, i := range q {
		for _, v := range watchedVideos[i] {
			cnt[v]++
		}
	}
	ans := []string{}
	for key := range cnt {
		ans = append(ans, key)
	}
	sort.Slice(ans, func(i, j int) bool {
		if cnt[ans[i]] == cnt[ans[j]] {
			return ans[i] < ans[j]
		}
		return cnt[ans[i]] < cnt[ans[j]]
	})
	return ans
}
```

#### TypeScript

```ts
function watchedVideosByFriends(
    watchedVideos: string[][],
    friends: number[][],
    id: number,
    level: number,
): string[] {
    let q: number[] = [id];
    const n: number = friends.length;
    const vis: boolean[] = Array(n).fill(false);
    vis[id] = true;
    while (level-- > 0) {
        const nq: number[] = [];
        for (const i of q) {
            for (const j of friends[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    nq.push(j);
                }
            }
        }
        q = nq;
    }
    const cnt: { [key: string]: number } = {};
    for (const i of q) {
        for (const v of watchedVideos[i]) {
            cnt[v] = (cnt[v] || 0) + 1;
        }
    }
    const ans: string[] = Object.keys(cnt);
    ans.sort((a, b) => {
        if (cnt[a] === cnt[b]) {
            return a.localeCompare(b);
        }
        return cnt[a] - cnt[b];
    });
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1312. 让字符串成为回文串的最少插入次数](https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome){#1312}

{{< tabs "1312" >}}

{{% tab "python" %}}
```python
class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for k in range(2, n + 1):
            for i in range(n - k + 1):
                j = i + k - 1
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                else:
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1
        return f[0][n - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[0][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minInsertions(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for k := 2; k <= n; k++ {
		for i := 0; i+k-1 < n; i++ {
			j := i + k - 1
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1]
			} else {
				f[i][j] = min(f[i+1][j], f[i][j-1]) + 1
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，每一次操作你都可以在字符串的任意位置插入任意字符。</p>

<p>请你返回让&nbsp;<code>s</code>&nbsp;成为回文串的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>

<p>「回文串」是正读和反读都相同的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "zzazz"
<strong>输出：</strong>0
<strong>解释：</strong>字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "mbadm"
<strong>输出：</strong>2
<strong>解释：</strong>字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>5
<strong>解释：</strong>插入 5 个字符后字符串变为 "leetcodocteel" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code>&nbsp;中所有字符都是小写字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示将字符串 $s[i..j]$ 变成回文串所需要的最少操作次数。那么答案就是 $dfs(0, n - 1)$。

函数 $dfs(i, j)$ 的计算过程如下：

如果 $i \geq j$，此时无需插入任何字符，我们直接返回 $0$。

否则，我们判断 $s[i]$ 与 $s[j]$ 是否相等，如果 $s[i]=s[j]$，那么我们只需要将 $s[i+1..j-1]$ 变成回文串，那么我们返回 $dfs(i + 1, j - 1)$。否则，我们可以在 $s[i]$ 的左侧或者 $s[j]$ 的右侧插入一个与另一侧相同的字符，那么 $dfs(i, j) = \min(dfs(i + 1, j), dfs(i, j - 1)) + 1$。

为了避免重复计算，我们可以使用记忆化搜索，即使用哈希表或者数组来存储已经计算过的函数值。

最后，我们返回 $dfs(0, n - 1)$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minInsertions(self, s: str) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= j:
                return 0
            if s[i] == s[j]:
                return dfs(i + 1, j - 1)
            return 1 + min(dfs(i + 1, j), dfs(i, j - 1))

        return dfs(0, len(s) - 1)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private String s;

    public int minInsertions(String s) {
        this.s = s;
        int n = s.length();
        f = new Integer[n][n];
        return dfs(0, n - 1);
    }

    private int dfs(int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 1 << 30;
        if (s.charAt(i) == s.charAt(j)) {
            ans = dfs(i + 1, j - 1);
        } else {
            ans = Math.min(dfs(i + 1, j), dfs(i, j - 1)) + 1;
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= j) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = 1 << 30;
            if (s[i] == s[j]) {
                ans = dfs(i + 1, j - 1);
            } else {
                ans = min(dfs(i + 1, j), dfs(i, j - 1)) + 1;
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};
```

#### Go

```go
func minInsertions(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= j {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		ans := 1 << 30
		if s[i] == s[j] {
			ans = dfs(i+1, j-1)
		} else {
			ans = min(dfs(i+1, j), dfs(i, j-1)) + 1
		}
		f[i][j] = ans
		return ans
	}
	return dfs(0, n-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（区间 DP）

我们定义 $f[i][j]$ 表示将字符串 $s[i..j]$ 变成回文串所需要的最少操作次数。初始时 $f[i][j]=0$，答案即为 $f[0][n-1]$。

对于 $f[i][j]$，如果 $s[i]=s[j]$，那么我们只需要将 $s[i+1..j-1]$ 变成回文串，因此 $f[i][j]=f[i+1][j-1]$。否则，我们可以在 $s[i]$ 的左侧或者 $s[j]$ 的右侧插入一个与另一侧相同的字符，那么 $f[i][j]=\min(f[i+1][j],f[i][j-1])+1$。

综上，我们可以得到状态转移方程：

$$
f[i][j]=\left\{\begin{array}{ll}f[i+1][j-1], & s[i]=s[j]\\ \min(f[i+1][j],f[i][j-1])+1, & s[i]\neq s[j]\end{array}\right.
$$

在枚举时，我们可以有两种枚举的方式：

1. 从大到小枚举 $i$，从小到大枚举 $j$，这样可以保证在计算状态 $f[i][j]$ 时，状态 $f[i+1][j-1]$ 和 $f[i][j-1]$ 都已经计算过了；
1. 从小到大枚举区间长度 $k$，然后枚举区间的左端点 $i$，那么可以得到右端点 $j=i+k-1$，这样也可以保证在计算较大区间 $f[i][j]$ 时，较小区间 $f[i+1][j]$ 和 $f[i][j-1]$ 都已经计算过了。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

相似题目：

-   [1039. 多边形三角剖分的最低得分](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1039.Minimum%20Score%20Triangulation%20of%20Polygon/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                else:
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func minInsertions(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1]
			} else {
				f[i][j] = min(f[i+1][j], f[i][j-1]) + 1
			}
		}
	}
	return f[0][n-1]
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
    def minInsertions(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for k in range(2, n + 1):
            for i in range(n - k + 1):
                j = i + k - 1
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                else:
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1
        return f[0][n - 1]
```

#### Java

```java
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = Math.min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                int j = i + k - 1;
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1];
                } else {
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func minInsertions(s string) int {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for k := 2; k <= n; k++ {
		for i := 0; i+k-1 < n; i++ {
			j := i + k - 1
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1]
			} else {
				f[i][j] = min(f[i+1][j], f[i][j-1]) + 1
			}
		}
	}
	return f[0][n-1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1313. 解压缩编码列表](https://leetcode.cn/problems/decompress-run-length-encoded-list){#1313}

{{< tabs "1313" >}}

{{% tab "python" %}}
```python
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return [nums[i + 1] for i in range(0, len(nums), 2) for _ in range(nums[i])]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                ans.add(nums[i + 1]);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                ans.push_back(nums[i + 1]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decompressRLElist(nums []int) (ans []int) {
	for i := 1; i < len(nums); i += 2 {
		for j := 0; j < nums[i-1]; j++ {
			ans = append(ans, nums[i])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decompressRLElist(nums: number[]): number[] {
    const ans: number[] = [];
    for (let i = 0; i < nums.length; i += 2) {
        for (let j = 0; j < nums[i]; j++) {
            ans.push(nums[i + 1]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        let n = nums.len();
        let mut i = 0;
        while i < n {
            let freq = nums[i];
            let val = nums[i + 1];
            for _ in 0..freq {
                ans.push(val);
            }
            i += 2;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int n = 0;
    for (int i = 0; i < numsSize; i += 2) {
        n += nums[i];
    }
    int* ans = (int*) malloc(n * sizeof(int));
    *returnSize = n;
    int k = 0;
    for (int i = 0; i < numsSize; i += 2) {
        int freq = nums[i];
        int val = nums[i + 1];
        for (int j = 0; j < freq; j++) {
            ans[k++] = val;
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

<p>给你一个以行程长度编码压缩的整数列表 <code>nums</code> 。</p>

<p>考虑每对相邻的两个元素 <code>[freq, val] = [nums[2*i], nums[2*i+1]]</code> （其中 <code>i >= 0</code> ），每一对都表示解压后子列表中有 <code>freq</code> 个值为 <code>val</code> 的元素，你需要从左到右连接所有子列表以生成解压后的列表。</p>

<p>请你返回解压后的列表。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[2,4,4,4]
<strong>解释：</strong>第一对 [1,2] 代表着 2 的出现频次为 1，所以生成数组 [2]。
第二对 [3,4] 代表着 4 的出现频次为 3，所以生成数组 [4,4,4]。
最后将它们串联到一起 [2] + [4,4,4] = [2,4,4,4]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,3]
<strong>输出：</strong>[1,3,3]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
	<li><code>1 <= nums[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟题目描述的过程，从左到右遍历数组 $\textit{nums}$，每次取出两个数 $\textit{freq}$ 和 $\textit{val}$，然后将 $\textit{val}$ 重复 $\textit{freq}$ 次，将这 $\textit{freq}$ 个 $\textit{val}$ 加入答案数组即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。我们只需要遍历一次数组 $\textit{nums}$ 即可。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return [nums[i + 1] for i in range(0, len(nums), 2) for _ in range(nums[i])]
```

#### Java

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                ans.add(nums[i + 1]);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                ans.push_back(nums[i + 1]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func decompressRLElist(nums []int) (ans []int) {
	for i := 1; i < len(nums); i += 2 {
		for j := 0; j < nums[i-1]; j++ {
			ans = append(ans, nums[i])
		}
	}
	return
}
```

#### TypeScript

```ts
function decompressRLElist(nums: number[]): number[] {
    const ans: number[] = [];
    for (let i = 0; i < nums.length; i += 2) {
        for (let j = 0; j < nums[i]; j++) {
            ans.push(nums[i + 1]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        let n = nums.len();
        let mut i = 0;
        while i < n {
            let freq = nums[i];
            let val = nums[i + 1];
            for _ in 0..freq {
                ans.push(val);
            }
            i += 2;
        }
        ans
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int n = 0;
    for (int i = 0; i < numsSize; i += 2) {
        n += nums[i];
    }
    int* ans = (int*) malloc(n * sizeof(int));
    *returnSize = n;
    int k = 0;
    for (int i = 0; i < numsSize; i += 2) {
        int freq = nums[i];
        int val = nums[i + 1];
        for (int j = 0; j < freq; j++) {
            ans[k++] = val;
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

# [1314. 矩阵区域和](https://leetcode.cn/problems/matrix-block-sum){#1314}

{{< tabs "1314" >}}

{{% tab "python" %}}
```python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(mat, 1):
            for j, x in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x1, y1 = max(i - k, 0), max(j - k, 0)
                x2, y2 = min(m - 1, i + k), min(n - 1, j + k)
                ans[i][j] = (
                    s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1]
                )
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] s = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mat[i][j];
            }
        }

        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = Math.max(i - k, 0);
                int y1 = Math.max(j - k, 0);
                int x2 = Math.min(m - 1, i + k);
                int y2 = Math.min(n - 1, j + k);
                ans[i][j] = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mat[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = max(i - k, 0);
                int y1 = max(j - k, 0);
                int x2 = min(m - 1, i + k);
                int y2 = min(n - 1, j + k);
                ans[i][j] = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matrixBlockSum(mat [][]int, k int) [][]int {
	m, n := len(mat), len(mat[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i, row := range mat {
		for j, x := range row {
			s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + x
		}
	}

	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			x1 := max(i-k, 0)
			y1 := max(j-k, 0)
			x2 := min(m-1, i+k)
			y2 := min(n-1, j+k)
			ans[i][j] = s[x2+1][y2+1] - s[x1][y2+1] - s[x2+1][y1] + s[x1][y1]
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function matrixBlockSum(mat: number[][], k: number): number[][] {
    const m: number = mat.length;
    const n: number = mat[0].length;

    const s: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mat[i][j];
        }
    }

    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x1: number = Math.max(i - k, 0);
            const y1: number = Math.max(j - k, 0);
            const x2: number = Math.min(m - 1, i + k);
            const y2: number = Math.min(n - 1, j + k);
            ans[i][j] = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
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

<p>给你一个 <code>m x n</code> 的矩阵 <code>mat</code> 和一个整数 <code>k</code> ，请你返回一个矩阵 <code>answer</code> ，其中每个 <code>answer[i][j]</code> 是所有满足下述条件的元素 <code>mat[r][c]</code> 的和： </p>

<ul>
	<li><code>i - k <= r <= i + k, </code></li>
	<li><code>j - k <= c <= j + k</code> 且</li>
	<li><code>(r, c)</code> 在矩阵内。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
<strong>输出：</strong>[[12,21,16],[27,45,33],[24,39,28]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
<strong>输出：</strong>[[45,45,45],[45,45,45],[45,45,45]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 <= m, n, k <= 100</code></li>
	<li><code>1 <= mat[i][j] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀和

本题属于二维前缀和模板题。

我们定义 $s[i][j]$ 表示矩阵 $mat$ 前 $i$ 行，前 $j$ 列的元素和。那么 $s[i][j]$ 的计算公式为：

$$
s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + mat[i-1][j-1]
$$

这样我们就可以通过 $s$ 数组快速计算出任意矩形区域的元素和。

对于一个左上角坐标为 $(x_1, y_1)$，右下角坐标为 $(x_2, y_2)$ 的矩形区域的元素和，我们可以通过 $s$ 数组计算出来：

$$
s[x_2+1][y_2+1] - s[x_1][y_2+1] - s[x_2+1][y_1] + s[x_1][y_1]
$$

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(mat, 1):
            for j, x in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x1, y1 = max(i - k, 0), max(j - k, 0)
                x2, y2 = min(m - 1, i + k), min(n - 1, j + k)
                ans[i][j] = (
                    s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1]
                )
        return ans
```

#### Java

```java
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] s = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mat[i][j];
            }
        }

        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = Math.max(i - k, 0);
                int y1 = Math.max(j - k, 0);
                int x2 = Math.min(m - 1, i + k);
                int y2 = Math.min(n - 1, j + k);
                ans[i][j] = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mat[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = max(i - k, 0);
                int y1 = max(j - k, 0);
                int x2 = min(m - 1, i + k);
                int y2 = min(n - 1, j + k);
                ans[i][j] = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func matrixBlockSum(mat [][]int, k int) [][]int {
	m, n := len(mat), len(mat[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i, row := range mat {
		for j, x := range row {
			s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + x
		}
	}

	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			x1 := max(i-k, 0)
			y1 := max(j-k, 0)
			x2 := min(m-1, i+k)
			y2 := min(n-1, j+k)
			ans[i][j] = s[x2+1][y2+1] - s[x1][y2+1] - s[x2+1][y1] + s[x1][y1]
		}
	}

	return ans
}
```

#### TypeScript

```ts
function matrixBlockSum(mat: number[][], k: number): number[][] {
    const m: number = mat.length;
    const n: number = mat[0].length;

    const s: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + mat[i][j];
        }
    }

    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x1: number = Math.max(i - k, 0);
            const y1: number = Math.max(j - k, 0);
            const x2: number = Math.min(m - 1, i + k);
            const y2: number = Math.min(n - 1, j + k);
            ans[i][j] = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
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

# [1315. 祖父节点值为偶数的节点和](https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent){#1315}

{{< tabs "1315" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, x: int) -> int:
            if root is None:
                return 0
            ans = dfs(root.left, root.val) + dfs(root.right, root.val)
            if x % 2 == 0:
                if root.left:
                    ans += root.left.val
                if root.right:
                    ans += root.right.val
            return ans

        return dfs(root, 1)
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
    public int sumEvenGrandparent(TreeNode root) {
        return dfs(root, 1);
    }

    private int dfs(TreeNode root, int x) {
        if (root == null) {
            return 0;
        }
        int ans = dfs(root.left, root.val) + dfs(root.right, root.val);
        if (x % 2 == 0) {
            if (root.left != null) {
                ans += root.left.val;
            }
            if (root.right != null) {
                ans += root.right.val;
            }
        }
        return ans;
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
    int sumEvenGrandparent(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int x) {
            if (!root) {
                return 0;
            }
            int ans = dfs(root->left, root->val) + dfs(root->right, root->val);
            if (x % 2 == 0) {
                if (root->left) {
                    ans += root->left->val;
                }
                if (root->right) {
                    ans += root->right->val;
                }
            }
            return ans;
        };
        return dfs(root, 1);
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
func sumEvenGrandparent(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(root *TreeNode, x int) int {
		if root == nil {
			return 0
		}
		ans := dfs(root.Left, root.Val) + dfs(root.Right, root.Val)
		if x%2 == 0 {
			if root.Left != nil {
				ans += root.Left.Val
			}
			if root.Right != nil {
				ans += root.Right.Val
			}
		}
		return ans
	}
	return dfs(root, 1)
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

function sumEvenGrandparent(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, x: number): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        let ans = dfs(left, val) + dfs(right, val);
        if (x % 2 === 0) {
            ans += left?.val ?? 0;
            ans += right?.val ?? 0;
        }
        return ans;
    };
    return dfs(root, 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：</p>

<ul>
	<li>该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）</li>
</ul>

<p>如果不存在祖父节点值为偶数的节点，那么返回&nbsp;<code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1315.Sum%20of%20Nodes%20with%20Even-Valued%20Grandparent/images/1473_ex1.png" style="height: 214px; width: 350px;"></strong></p>

<pre><strong>输入：</strong>root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
<strong>输出：</strong>18
<strong>解释：</strong>图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在&nbsp;<code>1</code> 到&nbsp;<code>10^4</code>&nbsp;之间。</li>
	<li>每个节点的值在&nbsp;<code>1</code> 到&nbsp;<code>100</code> 之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root, x)$，表示以 $root$ 为根节点，并且 $root$ 的父节点的值为 $x$ 的子树中，满足条件的节点的值之和。那么答案就是 $dfs(root, 1)$。

函数 $dfs(root, x)$ 的执行过程如下：

-   如果 $root$ 为空，返回 $0$。
-   否则，我们递归计算 $root$ 的左子树和右子树的答案，即 $dfs(root.left, root.val)$ 和 $dfs(root.right, root.val)$，累加到答案中。如果 $x$ 为偶数，此时我们判断 $root$ 的左孩子和右孩子是否存在，如果存在，我们将它们的值累加到答案中。
-   最后返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点个数。

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
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, x: int) -> int:
            if root is None:
                return 0
            ans = dfs(root.left, root.val) + dfs(root.right, root.val)
            if x % 2 == 0:
                if root.left:
                    ans += root.left.val
                if root.right:
                    ans += root.right.val
            return ans

        return dfs(root, 1)
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
    public int sumEvenGrandparent(TreeNode root) {
        return dfs(root, 1);
    }

    private int dfs(TreeNode root, int x) {
        if (root == null) {
            return 0;
        }
        int ans = dfs(root.left, root.val) + dfs(root.right, root.val);
        if (x % 2 == 0) {
            if (root.left != null) {
                ans += root.left.val;
            }
            if (root.right != null) {
                ans += root.right.val;
            }
        }
        return ans;
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
    int sumEvenGrandparent(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int x) {
            if (!root) {
                return 0;
            }
            int ans = dfs(root->left, root->val) + dfs(root->right, root->val);
            if (x % 2 == 0) {
                if (root->left) {
                    ans += root->left->val;
                }
                if (root->right) {
                    ans += root->right->val;
                }
            }
            return ans;
        };
        return dfs(root, 1);
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
func sumEvenGrandparent(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(root *TreeNode, x int) int {
		if root == nil {
			return 0
		}
		ans := dfs(root.Left, root.Val) + dfs(root.Right, root.Val)
		if x%2 == 0 {
			if root.Left != nil {
				ans += root.Left.Val
			}
			if root.Right != nil {
				ans += root.Right.Val
			}
		}
		return ans
	}
	return dfs(root, 1)
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

function sumEvenGrandparent(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, x: number): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        let ans = dfs(left, val) + dfs(right, val);
        if (x % 2 === 0) {
            ans += left?.val ?? 0;
            ans += right?.val ?? 0;
        }
        return ans;
    };
    return dfs(root, 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1316. 不同的循环子字符串](https://leetcode.cn/problems/distinct-echo-substrings){#1316}

{{< tabs "1316" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        def get(l, r):
            return (h[r] - h[l - 1] * p[r - l + 1]) % mod

        n = len(text)
        base = 131
        mod = int(1e9) + 7
        h = [0] * (n + 10)
        p = [1] * (n + 10)
        for i, c in enumerate(text):
            t = ord(c) - ord('a') + 1
            h[i + 1] = (h[i] * base) % mod + t
            p[i + 1] = (p[i] * base) % mod
        vis = set()
        for i in range(n - 1):
            for j in range(i + 1, n, 2):
                k = (i + j) >> 1
                a = get(i + 1, k + 1)
                b = get(k + 2, j + 1)
                if a == b:
                    vis.add(a)
        return len(vis)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private long[] h;
    private long[] p;

    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        int base = 131;
        h = new long[n + 10];
        p = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            int t = text.charAt(i) - 'a' + 1;
            h[i + 1] = h[i] * base + t;
            p[i + 1] = p[i] * base;
        }
        Set<Long> vis = new HashSet<>();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; j += 2) {
                int k = (i + j) >> 1;
                long a = get(i + 1, k + 1);
                long b = get(k + 2, j + 1);
                if (a == b) {
                    vis.add(a);
                }
            }
        }
        return vis.size();
    }

    private long get(int i, int j) {
        return h[j] - h[i - 1] * p[j - i + 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
typedef unsigned long long ull;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        int base = 131;
        vector<ull> p(n + 10);
        vector<ull> h(n + 10);
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            int t = text[i] - 'a' + 1;
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + t;
        }
        unordered_set<ull> vis;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; j += 2) {
                int k = (i + j) >> 1;
                ull a = get(i + 1, k + 1, p, h);
                ull b = get(k + 2, j + 1, p, h);
                if (a == b) vis.insert(a);
            }
        }
        return vis.size();
    }

    ull get(int l, int r, vector<ull>& p, vector<ull>& h) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctEchoSubstrings(text string) int {
	n := len(text)
	base := 131
	h := make([]int, n+10)
	p := make([]int, n+10)
	p[0] = 1
	for i, c := range text {
		t := int(c-'a') + 1
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + t
	}
	get := func(l, r int) int {
		return h[r] - h[l-1]*p[r-l+1]
	}
	vis := map[int]bool{}
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j += 2 {
			k := (i + j) >> 1
			a, b := get(i+1, k+1), get(k+2, j+1)
			if a == b {
				vis[a] = true
			}
		}
	}
	return len(vis)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

const BASE: u64 = 131;

impl Solution {
    #[allow(dead_code)]
    pub fn distinct_echo_substrings(text: String) -> i32 {
        let n = text.len();
        let mut vis: HashSet<u64> = HashSet::new();
        let mut base_vec: Vec<u64> = vec![1; n + 1];
        let mut hash_vec: Vec<u64> = vec![0; n + 1];

        // Initialize the base vector & hash vector
        for i in 0..n {
            let cur_char = ((text.chars().nth(i).unwrap() as u8) - ('a' as u8) + 1) as u64;
            // Update base vector
            base_vec[i + 1] = base_vec[i] * BASE;
            // Update hash vector
            hash_vec[i + 1] = hash_vec[i] * BASE + cur_char;
        }

        // Traverse the text to find the result pair, using rolling hash
        for i in 0..n - 1 {
            for j in i + 1..n {
                // Prevent overflow
                let k = i + (j - i) / 2;
                let left = Self::get_hash(i + 1, k + 1, &base_vec, &hash_vec);
                let right = Self::get_hash(k + 2, j + 1, &base_vec, &hash_vec);
                if left == right {
                    vis.insert(left);
                }
            }
        }

        vis.len() as i32
    }

    #[allow(dead_code)]
    fn get_hash(start: usize, end: usize, base_vec: &Vec<u64>, hash_vec: &Vec<u64>) -> u64 {
        hash_vec[end] - hash_vec[start - 1] * base_vec[end - start + 1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>text</code> ，请你返回满足下述条件的&nbsp;<strong>不同</strong> 非空子字符串的数目：</p>

<ul>
	<li>可以写成某个字符串与其自身相连接的形式（即，可以写为 <code>a&nbsp;+ a</code>，其中 <code>a</code> 是某个字符串）。</li>
</ul>

<p>例如，<code>abcabc</code>&nbsp;就是&nbsp;<code>abc</code>&nbsp;和它自身连接形成的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = &quot;abcabcabc&quot;
<strong>输出：</strong>3
<strong>解释：</strong>3 个子字符串分别为 &quot;abcabc&quot;，&quot;bcabca&quot; 和 &quot;cabcab&quot; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = &quot;leetcodeleetcode&quot;
<strong>输出：</strong>2
<strong>解释：</strong>2 个子字符串为 &quot;ee&quot; 和 &quot;leetcodeleetcode&quot; 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 2000</code></li>
	<li><code>text</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串哈希

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 0。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

取一固定值 BASE，把字符串看作是 BASE 进制数，并分配一个大于 0 的数值，代表每种字符。一般来说，我们分配的数值都远小于 BASE。例如，对于小写字母构成的字符串，可以令 a=1, b=2, ..., z=26。取一固定值 MOD，求出该 BASE 进制对 M 的余数，作为该字符串的 hash 值。

一般来说，取 BASE=131 或者 BASE=13331，此时 hash 值产生的冲突概率极低。只要两个字符串 hash 值相同，我们就认为两个字符串是相等的。通常 MOD 取 2^64，C++ 里，可以直接使用 unsigned long long 类型存储这个 hash 值，在计算时不处理算术溢出问题，产生溢出时相当于自动对 2^64 取模，这样可以避免低效取模运算。

除了在极特殊构造的数据上，上述 hash 算法很难产生冲突，一般情况下上述 hash 算法完全可以出现在题目的标准答案中。我们还可以多取一些恰当的 BASE 和 MOD 的值（例如大质数），多进行几组 hash 运算，当结果都相同时才认为原字符串相等，就更加难以构造出使这个 hash 产生错误的数据。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        def get(l, r):
            return (h[r] - h[l - 1] * p[r - l + 1]) % mod

        n = len(text)
        base = 131
        mod = int(1e9) + 7
        h = [0] * (n + 10)
        p = [1] * (n + 10)
        for i, c in enumerate(text):
            t = ord(c) - ord('a') + 1
            h[i + 1] = (h[i] * base) % mod + t
            p[i + 1] = (p[i] * base) % mod
        vis = set()
        for i in range(n - 1):
            for j in range(i + 1, n, 2):
                k = (i + j) >> 1
                a = get(i + 1, k + 1)
                b = get(k + 2, j + 1)
                if a == b:
                    vis.add(a)
        return len(vis)
```

#### Java

```java
class Solution {
    private long[] h;
    private long[] p;

    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        int base = 131;
        h = new long[n + 10];
        p = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            int t = text.charAt(i) - 'a' + 1;
            h[i + 1] = h[i] * base + t;
            p[i + 1] = p[i] * base;
        }
        Set<Long> vis = new HashSet<>();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; j += 2) {
                int k = (i + j) >> 1;
                long a = get(i + 1, k + 1);
                long b = get(k + 2, j + 1);
                if (a == b) {
                    vis.add(a);
                }
            }
        }
        return vis.size();
    }

    private long get(int i, int j) {
        return h[j] - h[i - 1] * p[j - i + 1];
    }
}
```

#### C++

```cpp
typedef unsigned long long ull;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        int base = 131;
        vector<ull> p(n + 10);
        vector<ull> h(n + 10);
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            int t = text[i] - 'a' + 1;
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + t;
        }
        unordered_set<ull> vis;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; j += 2) {
                int k = (i + j) >> 1;
                ull a = get(i + 1, k + 1, p, h);
                ull b = get(k + 2, j + 1, p, h);
                if (a == b) vis.insert(a);
            }
        }
        return vis.size();
    }

    ull get(int l, int r, vector<ull>& p, vector<ull>& h) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};
```

#### Go

```go
func distinctEchoSubstrings(text string) int {
	n := len(text)
	base := 131
	h := make([]int, n+10)
	p := make([]int, n+10)
	p[0] = 1
	for i, c := range text {
		t := int(c-'a') + 1
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + t
	}
	get := func(l, r int) int {
		return h[r] - h[l-1]*p[r-l+1]
	}
	vis := map[int]bool{}
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j += 2 {
			k := (i + j) >> 1
			a, b := get(i+1, k+1), get(k+2, j+1)
			if a == b {
				vis[a] = true
			}
		}
	}
	return len(vis)
}
```

#### Rust

```rust
use std::collections::HashSet;

const BASE: u64 = 131;

impl Solution {
    #[allow(dead_code)]
    pub fn distinct_echo_substrings(text: String) -> i32 {
        let n = text.len();
        let mut vis: HashSet<u64> = HashSet::new();
        let mut base_vec: Vec<u64> = vec![1; n + 1];
        let mut hash_vec: Vec<u64> = vec![0; n + 1];

        // Initialize the base vector & hash vector
        for i in 0..n {
            let cur_char = ((text.chars().nth(i).unwrap() as u8) - ('a' as u8) + 1) as u64;
            // Update base vector
            base_vec[i + 1] = base_vec[i] * BASE;
            // Update hash vector
            hash_vec[i + 1] = hash_vec[i] * BASE + cur_char;
        }

        // Traverse the text to find the result pair, using rolling hash
        for i in 0..n - 1 {
            for j in i + 1..n {
                // Prevent overflow
                let k = i + (j - i) / 2;
                let left = Self::get_hash(i + 1, k + 1, &base_vec, &hash_vec);
                let right = Self::get_hash(k + 2, j + 1, &base_vec, &hash_vec);
                if left == right {
                    vis.insert(left);
                }
            }
        }

        vis.len() as i32
    }

    #[allow(dead_code)]
    fn get_hash(start: usize, end: usize, base_vec: &Vec<u64>, hash_vec: &Vec<u64>) -> u64 {
        hash_vec[end] - hash_vec[start - 1] * base_vec[end - start + 1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1317. 将整数转换为两个无零整数的和](https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers){#1317}

{{< tabs "1317" >}}

{{% tab "python" %}}
```python
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def f(x: int) -> bool:
            while x:
                if x % 10 == 0:
                    return False
                x //= 10
            return True

        for a in count(1):
            b = n - a
            if f(a) and f(b):
                return [a, b]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return new int[] {a, b};
            }
        }
    }

    private boolean f(int x) {
        for (; x > 0; x /= 10) {
            if (x % 10 == 0) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto f = [](int x) {
            for (; x; x /= 10) {
                if (x % 10 == 0) {
                    return false;
                }
            }
            return true;
        };
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return {a, b};
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getNoZeroIntegers(n int) []int {
	f := func(x int) bool {
		for ; x > 0; x /= 10 {
			if x%10 == 0 {
				return false
			}
		}
		return true
	}
	for a := 1; ; a++ {
		b := n - a
		if f(a) && f(b) {
			return []int{a, b}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getNoZeroIntegers(n: number): number[] {
    const f = (x: number): boolean => {
        for (; x; x = (x / 10) | 0) {
            if (x % 10 === 0) {
                return false;
            }
        }
        return true;
    };
    for (let a = 1; ; ++a) {
        const b = n - a;
        if (f(a) && f(b)) {
            return [a, b];
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        fn f(mut x: i32) -> bool {
            while x > 0 {
                if x % 10 == 0 {
                    return false;
                }
                x /= 10;
            }
            true
        }

        for a in 1..n {
            let b = n - a;
            if f(a) && f(b) {
                return vec![a, b];
            }
        }
        vec![]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>「无零整数」是十进制表示中 <strong>不含任何 0</strong>&nbsp;的正整数。</p>

<p>给你一个整数&nbsp;<code>n</code>，请你返回一个 <strong>由两个整数组成的列表</strong> <code>[a, b]</code>，满足：</p>

<ul>
	<li><code>a</code> 和 <code>b</code>&nbsp;都是无零整数</li>
	<li><code>a + b = n</code></li>
</ul>

<p>题目数据保证至少有一个有效的解决方案。</p>

<p>如果存在多个有效解决方案，你可以返回其中任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[1,1]
<strong>解释：</strong>a = 1, b = 1。a + b = n 并且 a 和 b 的十进制表示形式都不包含任何 0。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>[2,9]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 10000
<strong>输出：</strong>[1,9999]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 69
<strong>输出：</strong>[1,68]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>n = 1010
<strong>输出：</strong>[11,999]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接枚举

从 $1$ 开始枚举 $a$，那么 $b = n - a$。对于每个 $a$ 和 $b$，我们将它们转换为字符串并且连接起来，然后判断是否包含字符 `'0'`，如果不包含，那么就找到了答案，返回 $[a, b]$。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(\log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for a in count(1):
            b = n - a
            if "0" not in f"{a}{b}":
                return [a, b]
```

#### Java

```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if (!(a + "" + b).contains("0")) {
                return new int[] {a, b};
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if ((to_string(a) + to_string(b)).find('0') == -1) {
                return {a, b};
            }
        }
    }
};
```

#### Go

```go
func getNoZeroIntegers(n int) []int {
	for a := 1; ; a++ {
		b := n - a
		if !strings.Contains(strconv.Itoa(a)+strconv.Itoa(b), "0") {
			return []int{a, b}
		}
	}
}
```

#### TypeScript

```ts
function getNoZeroIntegers(n: number): number[] {
    for (let a = 1; ; ++a) {
        const b = n - a;
        if (!`${a}${b}`.includes('0')) {
            return [a, b];
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        for a in 1..n {
            let b = n - a;
            if !a.to_string().contains('0') && !b.to_string().contains('0') {
                return vec![a, b];
            }
        }
        vec![]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：直接枚举（另一种写法）

在方法一中，我们将 $a$ 和 $b$ 转换为字符串并且连接起来，然后判断是否包含字符 `'0'`。这里我们可以通过一个函数 $f(x)$ 来判断 $x$ 是否包含字符 `'0'`，然后直接枚举 $a$，判断 $a$ 和 $b = n - a$ 是否都不包含字符 `'0'`，如果是，则找到了答案，返回 $[a, b]$。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def f(x: int) -> bool:
            while x:
                if x % 10 == 0:
                    return False
                x //= 10
            return True

        for a in count(1):
            b = n - a
            if f(a) and f(b):
                return [a, b]
```

#### Java

```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return new int[] {a, b};
            }
        }
    }

    private boolean f(int x) {
        for (; x > 0; x /= 10) {
            if (x % 10 == 0) {
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
    vector<int> getNoZeroIntegers(int n) {
        auto f = [](int x) {
            for (; x; x /= 10) {
                if (x % 10 == 0) {
                    return false;
                }
            }
            return true;
        };
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return {a, b};
            }
        }
    }
};
```

#### Go

```go
func getNoZeroIntegers(n int) []int {
	f := func(x int) bool {
		for ; x > 0; x /= 10 {
			if x%10 == 0 {
				return false
			}
		}
		return true
	}
	for a := 1; ; a++ {
		b := n - a
		if f(a) && f(b) {
			return []int{a, b}
		}
	}
}
```

#### TypeScript

```ts
function getNoZeroIntegers(n: number): number[] {
    const f = (x: number): boolean => {
        for (; x; x = (x / 10) | 0) {
            if (x % 10 === 0) {
                return false;
            }
        }
        return true;
    };
    for (let a = 1; ; ++a) {
        const b = n - a;
        if (f(a) && f(b)) {
            return [a, b];
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        fn f(mut x: i32) -> bool {
            while x > 0 {
                if x % 10 == 0 {
                    return false;
                }
                x /= 10;
            }
            true
        }

        for a in 1..n {
            let b = n - a;
            if f(a) && f(b) {
                return vec![a, b];
            }
        }
        vec![]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1318. 或运算的最小翻转次数](https://leetcode.cn/problems/minimum-flips-to-make-a-or-b-equal-to-c){#1318}

{{< tabs "1318" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        for i in range(32):
            x, y, z = a >> i & 1, b >> i & 1, c >> i & 1
            ans += x + y if z == 0 else int(x == 0 and y == 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int x = a >> i & 1, y = b >> i & 1, z = c >> i & 1;
            ans += z == 0 ? x + y : (x == 0 && y == 0 ? 1 : 0);
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
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int x = a >> i & 1, y = b >> i & 1, z = c >> i & 1;
            ans += z == 0 ? x + y : (x == 0 && y == 0 ? 1 : 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlips(a int, b int, c int) (ans int) {
	for i := 0; i < 32; i++ {
		x, y, z := a>>i&1, b>>i&1, c>>i&1
		if z == 0 {
			ans += x + y
		} else if x == 0 && y == 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFlips(a: number, b: number, c: number): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        const [x, y, z] = [(a >> i) & 1, (b >> i) & 1, (c >> i) & 1];
        ans += z === 0 ? x + y : x + y === 0 ? 1 : 0;
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

<p>给你三个正整数&nbsp;<code>a</code>、<code>b</code> 和 <code>c</code>。</p>

<p>你可以对 <code>a</code> 和 <code>b</code>&nbsp;的二进制表示进行位翻转操作，返回能够使按位或运算&nbsp; &nbsp;<code>a</code> OR <code>b</code> == <code>c</code>&nbsp;&nbsp;成立的最小翻转次数。</p>

<p>「位翻转操作」是指将一个数的二进制表示任何单个位上的 1 变成 0 或者 0 变成 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1318.Minimum%20Flips%20to%20Make%20a%20OR%20b%20Equal%20to%20c/images/sample_3_1676.png" style="height: 87px; width: 260px;"></p>

<pre><strong>输入：</strong>a = 2, b = 6, c = 5
<strong>输出：</strong>3
<strong>解释：</strong>翻转后 a = 1 , b = 4 , c = 5 使得 <code>a</code> OR <code>b</code> == <code>c</code></pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = 4, b = 2, c = 7
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>a = 1, b = 2, c = 3
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a &lt;= 10^9</code></li>
	<li><code>1 &lt;= b&nbsp;&lt;= 10^9</code></li>
	<li><code>1 &lt;= c&nbsp;&lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以枚举 $a$, $b$, $c$ 的二进制表示的每一位，分别记为 $x$, $y$, $z$。如果 $x$ 和 $y$ 的按位或运算结果与 $z$ 不同，此时我们判断 $x$ 和 $y$ 是否都是 $1$，如果是，则需要翻转两次，否则只需要翻转一次。我们将所有需要翻转的次数累加即可。

时间复杂度 $O(\log M)$，其中 $M$ 是题目中数字的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        for i in range(32):
            x, y, z = a >> i & 1, b >> i & 1, c >> i & 1
            ans += x + y if z == 0 else int(x == 0 and y == 0)
        return ans
```

#### Java

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int x = a >> i & 1, y = b >> i & 1, z = c >> i & 1;
            ans += z == 0 ? x + y : (x == 0 && y == 0 ? 1 : 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int x = a >> i & 1, y = b >> i & 1, z = c >> i & 1;
            ans += z == 0 ? x + y : (x == 0 && y == 0 ? 1 : 0);
        }
        return ans;
    }
};
```

#### Go

```go
func minFlips(a int, b int, c int) (ans int) {
	for i := 0; i < 32; i++ {
		x, y, z := a>>i&1, b>>i&1, c>>i&1
		if z == 0 {
			ans += x + y
		} else if x == 0 && y == 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minFlips(a: number, b: number, c: number): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        const [x, y, z] = [(a >> i) & 1, (b >> i) & 1, (c >> i) & 1];
        ans += z === 0 ? x + y : x + y === 0 ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1319. 连通网络的操作次数](https://leetcode.cn/problems/number-of-operations-to-make-network-connected){#1319}

{{< tabs "1319" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        cnt = 0
        p = list(range(n))
        for a, b in connections:
            pa, pb = find(a), find(b)
            if pa == pb:
                cnt += 1
            else:
                p[pa] = pb
                n -= 1
        return -1 if n - 1 > cnt else n - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int makeConnected(int n, int[][] connections) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int cnt = 0;
        for (int[] e : connections) {
            int pa = find(e[0]), pb = find(e[1]);
            if (pa == pb) {
                ++cnt;
            } else {
                p[pa] = pb;
                --n;
            }
        }
        return n - 1 > cnt ? -1 : n - 1;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int cnt = 0;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (const auto& c : connections) {
            int pa = find(c[0]), pb = find(c[1]);
            if (pa == pb) {
                ++cnt;
            } else {
                p[pa] = pb;
                --n;
            }
        }
        return cnt >= n - 1 ? n - 1 : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeConnected(n int, connections [][]int) int {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	cnt := 0
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range connections {
		pa, pb := find(e[0]), find(e[1])
		if pa == pb {
			cnt++
		} else {
			p[pa] = pb
			n--
		}
	}
	if n-1 > cnt {
		return -1
	}
	return n - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeConnected(n: number, connections: number[][]): number {
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    let cnt = 0;
    for (const [a, b] of connections) {
        const [pa, pb] = [find(a), find(b)];
        if (pa === pb) {
            ++cnt;
        } else {
            p[pa] = pb;
            --n;
        }
    }
    return cnt >= n - 1 ? n - 1 : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>用以太网线缆将&nbsp;<code>n</code>&nbsp;台计算机连接成一个网络，计算机的编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n-1</code>。线缆用&nbsp;<code>connections</code>&nbsp;表示，其中&nbsp;<code>connections[i] = [a, b]</code>&nbsp;连接了计算机&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>。</p>

<p>网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。</p>

<p>给你这个计算机网络的初始布线&nbsp;<code>connections</code>，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回&nbsp;-1 。&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1319.Number%20of%20Operations%20to%20Make%20Network%20Connected/images/sample_1_1677.png" style="height: 167px; width: 570px;"></strong></p>

<pre><strong>输入：</strong>n = 4, connections = [[0,1],[0,2],[1,2]]
<strong>输出：</strong>1
<strong>解释：</strong>拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1319.Number%20of%20Operations%20to%20Make%20Network%20Connected/images/sample_2_1677.png" style="height: 175px; width: 660px;"></strong></p>

<pre><strong>输入：</strong>n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
<strong>输出：</strong>-1
<strong>解释：</strong>线缆数量不足。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= connections.length &lt;= min(n*(n-1)/2, 10^5)</code></li>
	<li><code>connections[i].length == 2</code></li>
	<li><code>0 &lt;= connections[i][0], connections[i][1]&nbsp;&lt; n</code></li>
	<li><code>connections[i][0] != connections[i][1]</code></li>
	<li>没有重复的连接。</li>
	<li>两台计算机不会通过多条线缆连接。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以用并查集维护计算机之间的联通关系。遍历所有的连接，对于每个连接 $(a, b)$，如果 $a$ 和 $b$ 已经联通，那么这个连接是多余的，我们将多余的连接数加一；否则，我们将 $a$ 和 $b$ 连通，然后将联通分量数减一。

最后，如果联通分量数减一大于多余的连接数，说明我们无法使所有计算机联通，返回 -1；否则，返回联通分量数减一。

时间复杂度 $O(m \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是计算机的数量和连接的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        cnt = 0
        p = list(range(n))
        for a, b in connections:
            pa, pb = find(a), find(b)
            if pa == pb:
                cnt += 1
            else:
                p[pa] = pb
                n -= 1
        return -1 if n - 1 > cnt else n - 1
```

#### Java

```java
class Solution {
    private int[] p;

    public int makeConnected(int n, int[][] connections) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int cnt = 0;
        for (int[] e : connections) {
            int pa = find(e[0]), pb = find(e[1]);
            if (pa == pb) {
                ++cnt;
            } else {
                p[pa] = pb;
                --n;
            }
        }
        return n - 1 > cnt ? -1 : n - 1;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int cnt = 0;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (const auto& c : connections) {
            int pa = find(c[0]), pb = find(c[1]);
            if (pa == pb) {
                ++cnt;
            } else {
                p[pa] = pb;
                --n;
            }
        }
        return cnt >= n - 1 ? n - 1 : -1;
    }
};
```

#### Go

```go
func makeConnected(n int, connections [][]int) int {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	cnt := 0
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range connections {
		pa, pb := find(e[0]), find(e[1])
		if pa == pb {
			cnt++
		} else {
			p[pa] = pb
			n--
		}
	}
	if n-1 > cnt {
		return -1
	}
	return n - 1
}
```

#### TypeScript

```ts
function makeConnected(n: number, connections: number[][]): number {
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    let cnt = 0;
    for (const [a, b] of connections) {
        const [pa, pb] = [find(a), find(b)];
        if (pa === pb) {
            ++cnt;
        } else {
            p[pa] = pb;
            --n;
        }
    }
    return cnt >= n - 1 ? n - 1 : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
