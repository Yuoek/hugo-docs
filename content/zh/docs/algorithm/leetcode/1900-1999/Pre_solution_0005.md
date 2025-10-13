---
title: "1940_排序数组之间的最长公共子序列 🔒"
date: 2025-10-08T18:38:49+08:00
weight: 5
tags: [位运算, 前缀和, 动态规划, 单调栈, 哈希函数, 哈希表, 回溯, 堆（优先队列）, 字典树, 字符串, 排序, 数据库, 数组, 栈, 模拟, 状态压缩, 计数, 贪心]
---

{{< markmap >}}
### [1940_排序数组之间的最长公共子序列 🔒](#1940)
#### [数组](#1940)
#### [哈希表](#1940)
#### [计数](#1940)
### [1941_检查是否所有字符出现次数相同](#1941)
#### [哈希表](#1941)
#### [字符串](#1941)
#### [计数](#1941)
### [1942_最小未被占据椅子的编号](#1942)
#### [数组](#1942)
#### [哈希表](#1942)
#### [堆（优先队列）](#1942)
### [1943_描述绘画结果](#1943)
#### [数组](#1943)
#### [哈希表](#1943)
#### [前缀和](#1943)
#### [排序](#1943)
### [1944_队列中可以看到的人数](#1944)
#### [栈](#1944)
#### [数组](#1944)
#### [单调栈](#1944)
### [1945_字符串转化后的各位数字之和](#1945)
#### [字符串](#1945)
#### [模拟](#1945)
### [1946_子字符串突变后可能得到的最大整数](#1946)
#### [贪心](#1946)
#### [数组](#1946)
#### [字符串](#1946)
### [1947_最大兼容性评分和](#1947)
#### [位运算](#1947)
#### [数组](#1947)
#### [动态规划](#1947)
#### [回溯](#1947)
#### [状态压缩](#1947)
### [1948_删除系统中的重复文件夹](#1948)
#### [字典树](#1948)
#### [数组](#1948)
#### [哈希表](#1948)
#### [字符串](#1948)
#### [哈希函数](#1948)
### [1949_坚定的友谊 🔒](#1949)
#### [数据库](#1949)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1940_排序数组之间的最长公共子序列 🔒
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1941_检查是否所有字符出现次数相同
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1942_最小未被占据椅子的编号
___
#### 数组
___
#### 哈希表
___
#### 堆（优先队列）
---
### 1943_描述绘画结果
___
#### 数组
___
#### 哈希表
___
#### 前缀和
___
#### 排序
---
### 1944_队列中可以看到的人数
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 1945_字符串转化后的各位数字之和
___
#### 字符串
___
#### 模拟
---
### 1946_子字符串突变后可能得到的最大整数
___
#### 贪心
___
#### 数组
___
#### 字符串
---
### 1947_最大兼容性评分和
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 1948_删除系统中的重复文件夹
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 哈希函数
---
### 1949_坚定的友谊 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 单调栈 | 哈希函数 | 哈希表 |
| 回溯 | 堆（优先队列） | 字典树 |
| 字符串 | 排序 | 数据库 |
| 数组 | 栈 | 模拟 |
| 状态压缩 | 计数 | 贪心 |

# [1940. 排序数组之间的最长公共子序列 🔒](https://leetcode.cn/problems/longest-common-subsequence-between-sorted-arrays){#1940}

{{< tabs "1940" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        cnt = [0] * 101
        for row in arrays:
            for x in row:
                cnt[x] += 1
        return [x for x, v in enumerate(cnt) if v == len(arrays)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        int[] cnt = new int[101];
        for (var row : arrays) {
            for (int x : row) {
                ++cnt[x];
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] == arrays.length) {
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
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int cnt[101]{};
        for (const auto& row : arrays) {
            for (int x : row) {
                ++cnt[x];
            }
        }
        vector<int> ans;
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] == arrays.size()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestCommonSubsequence(arrays [][]int) (ans []int) {
	cnt := [101]int{}
	for _, row := range arrays {
		for _, x := range row {
			cnt[x]++
		}
	}
	for x, v := range cnt {
		if v == len(arrays) {
			ans = append(ans, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestCommonSubsequence(arrays: number[][]): number[] {
    const cnt: number[] = Array(101).fill(0);
    for (const row of arrays) {
        for (const x of row) {
            ++cnt[x];
        }
    }
    const ans: number[] = [];
    for (let i = 0; i < 101; ++i) {
        if (cnt[i] === arrays.length) {
            ans.push(i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} arrays
 * @return {number[]}
 */
var longestCommonSubsequence = function (arrays) {
    const cnt = Array(101).fill(0);
    for (const row of arrays) {
        for (const x of row) {
            ++cnt[x];
        }
    }
    const ans = [];
    for (let i = 0; i < 101; ++i) {
        if (cnt[i] === arrays.length) {
            ans.push(i);
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

<p>给定一个由整数数组组成的数组&nbsp;<code>arrays</code>，其中&nbsp;<code>arrays[i]</code>&nbsp;是 <strong>严格递增</strong> 排序的，返回一个 <strong>所有</strong> 数组均包含的 <strong>最长公共子序列</strong> 的整数数组。</p>

<p><strong>子序列</strong> 是从另一个序列派生出来的序列，删除一些元素或不删除任何元素，而不改变其余元素的顺序。</p>

<p><strong>示例1:</strong></p>

<pre>
<strong>输入:</strong> arrays = [[<u>1</u>,3,<u>4</u>],
&nbsp;              [<u>1</u>,<u>4</u>,7,9]]
<strong>输出:</strong> [1,4]
<strong>解释:</strong>&nbsp;这两个数组中的最长子序列是[1,4]。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> arrays = [[<u>2</u>,<u>3</u>,<u>6</u>,8],
&nbsp;              [1,<u>2</u>,<u>3</u>,5,<u>6</u>,7,10],
&nbsp;              [<u>2</u>,<u>3</u>,4,<u>6</u>,9]]
<strong>输出:</strong> [2,3,6]
<strong>解释:</strong>&nbsp;这三个数组中的最长子序列是 [2,3,6]。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> arrays = [[1,2,3,4,5],
&nbsp;              [6,7,8]]
<strong>输出:</strong> []
<strong>解释:</strong>&nbsp;这两个数组之间没有公共子序列。
</pre>

<p>&nbsp;</p>

<p><strong>限制条件:</strong></p>

<ul>
	<li><code>2 &lt;= arrays.length &lt;= 100</code></li>
	<li><code>1 &lt;= arrays[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= arrays[i][j] &lt;= 100</code></li>
	<li><code>arrays[i]</code> 是严格递增排序.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们注意到，元素的范围是 $[1, 100]$，我们可以用一个长度为 $101$ 的数组 $\textit{cnt}$ 来记录每个元素出现的次数。

由于数组 $\textit{arrays}$ 中的每个数组都是严格递增排序的，因此，公共子序列的元素必然是单调递增，并且这些元素的出现次数都等于 $\textit{arrays}$ 的长度。

因此，我们可以遍历 $\textit{arrays}$ 中的每个数组，统计每个元素的出现次数，最后，从小到大遍历 $\textit{cnt}$ 的每个元素，如果出现次数等于 $\textit{arrays}$ 的长度，那么这个元素就是公共子序列的元素之一，我们将其加入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(M + N)$，空间复杂度 $O(M)$。其中 $M$ 为元素的范围，本题中 $M = 101$，而 $N$ 为数组所有元素的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        cnt = [0] * 101
        for row in arrays:
            for x in row:
                cnt[x] += 1
        return [x for x, v in enumerate(cnt) if v == len(arrays)]
```

#### Java

```java
class Solution {
    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        int[] cnt = new int[101];
        for (var row : arrays) {
            for (int x : row) {
                ++cnt[x];
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] == arrays.length) {
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
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int cnt[101]{};
        for (const auto& row : arrays) {
            for (int x : row) {
                ++cnt[x];
            }
        }
        vector<int> ans;
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] == arrays.size()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestCommonSubsequence(arrays [][]int) (ans []int) {
	cnt := [101]int{}
	for _, row := range arrays {
		for _, x := range row {
			cnt[x]++
		}
	}
	for x, v := range cnt {
		if v == len(arrays) {
			ans = append(ans, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function longestCommonSubsequence(arrays: number[][]): number[] {
    const cnt: number[] = Array(101).fill(0);
    for (const row of arrays) {
        for (const x of row) {
            ++cnt[x];
        }
    }
    const ans: number[] = [];
    for (let i = 0; i < 101; ++i) {
        if (cnt[i] === arrays.length) {
            ans.push(i);
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} arrays
 * @return {number[]}
 */
var longestCommonSubsequence = function (arrays) {
    const cnt = Array(101).fill(0);
    for (const row of arrays) {
        for (const x of row) {
            ++cnt[x];
        }
    }
    const ans = [];
    for (let i = 0; i < 101; ++i) {
        if (cnt[i] === arrays.length) {
            ans.push(i);
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

# [1941. 检查是否所有字符出现次数相同](https://leetcode.cn/problems/check-if-all-characters-have-equal-number-of-occurrences){#1941}

{{< tabs "1941" >}}

{{% tab "python" %}}
```python
class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        return len(set(Counter(s).values())) == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean areOccurrencesEqual(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        int v = 0;
        for (int x : cnt) {
            if (x == 0) {
                continue;
            }
            if (v > 0 && v != x) {
                return false;
            }
            v = x;
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
    bool areOccurrencesEqual(string s) {
        vector<int> cnt(26);
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        int v = 0;
        for (int x : cnt) {
            if (x == 0) {
                continue;
            }
            if (v && v != x) {
                return false;
            }
            v = x;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func areOccurrencesEqual(s string) bool {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	v := 0
	for _, x := range cnt {
		if x == 0 {
			continue
		}
		if v > 0 && v != x {
			return false
		}
		v = x
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function areOccurrencesEqual(s: string): boolean {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    const v = cnt.find(v => v);
    return cnt.every(x => !x || v === x);
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function areOccurrencesEqual($s) {
        $cnt = array_fill(0, 26, 0);
        for ($i = 0; $i < strlen($s); $i++) {
            $cnt[ord($s[$i]) - ord('a')]++;
        }
        $v = 0;
        foreach ($cnt as $x) {
            if ($x == 0) {
                continue;
            }
            if ($v && $v != $x) {
                return false;
            }
            $v = $x;
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，如果 <code>s</code> 是一个 <strong>好</strong> 字符串，请你返回 <code>true</code> ，否则请返回 <code>false</code> 。</p>

<p>如果 <code>s</code> 中出现过的 <strong>所有</strong> 字符的出现次数 <strong>相同</strong> ，那么我们称字符串 <code>s</code> 是 <strong>好</strong> 字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "abacbc"
<b>输出：</b>true
<b>解释：</b>s 中出现过的字符为 'a'，'b' 和 'c' 。s 中所有字符均出现 2 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aaabb"
<b>输出：</b>false
<b>解释：</b>s 中出现过的字符为 'a' 和 'b' 。
'a' 出现了 3 次，'b' 出现了 2 次，两者出现次数不同。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用一个哈希表或者一个长度为 $26$ 的数组 $\textit{cnt}$ 记录字符串 $s$ 中每个字符出现的次数。

接下来遍历 $\textit{cnt}$ 中的每个值，判断所有非零值是否相等即可。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度；而 $\Sigma$ 是字符集大小，本题中字符集为小写英文字母，因此 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        return len(set(Counter(s).values())) == 1
```

#### Java

```java
class Solution {
    public boolean areOccurrencesEqual(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        int v = 0;
        for (int x : cnt) {
            if (x == 0) {
                continue;
            }
            if (v > 0 && v != x) {
                return false;
            }
            v = x;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> cnt(26);
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        int v = 0;
        for (int x : cnt) {
            if (x == 0) {
                continue;
            }
            if (v && v != x) {
                return false;
            }
            v = x;
        }
        return true;
    }
};
```

#### Go

```go
func areOccurrencesEqual(s string) bool {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	v := 0
	for _, x := range cnt {
		if x == 0 {
			continue
		}
		if v > 0 && v != x {
			return false
		}
		v = x
	}
	return true
}
```

#### TypeScript

```ts
function areOccurrencesEqual(s: string): boolean {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    const v = cnt.find(v => v);
    return cnt.every(x => !x || v === x);
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function areOccurrencesEqual($s) {
        $cnt = array_fill(0, 26, 0);
        for ($i = 0; $i < strlen($s); $i++) {
            $cnt[ord($s[$i]) - ord('a')]++;
        }
        $v = 0;
        foreach ($cnt as $x) {
            if ($x == 0) {
                continue;
            }
            if ($v && $v != $x) {
                return false;
            }
            $v = $x;
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1942. 最小未被占据椅子的编号](https://leetcode.cn/problems/the-number-of-the-smallest-unoccupied-chair){#1942}

{{< tabs "1942" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        for i in range(n):
            times[i].append(i)
        times.sort()
        idle = list(range(n))
        heapify(idle)
        busy = []
        for arrival, leaving, i in times:
            while busy and busy[0][0] <= arrival:
                heappush(idle, heappop(busy)[1])
            j = heappop(idle)
            if i == targetFriend:
                return j
            heappush(busy, (leaving, j))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int n = times.length;
        PriorityQueue<Integer> idle = new PriorityQueue<>();
        PriorityQueue<int[]> busy = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < n; ++i) {
            times[i] = new int[] {times[i][0], times[i][1], i};
            idle.offer(i);
        }
        Arrays.sort(times, Comparator.comparingInt(a -> a[0]));
        for (var e : times) {
            int arrival = e[0], leaving = e[1], i = e[2];
            while (!busy.isEmpty() && busy.peek()[0] <= arrival) {
                idle.offer(busy.poll()[1]);
            }
            int j = idle.poll();
            if (i == targetFriend) {
                return j;
            }
            busy.offer(new int[] {leaving, j});
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
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> busy;
        priority_queue<int, vector<int>, greater<int>> idle;
        int n = times.size();
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);
            idle.push(i);
        }
        ranges::sort(times);
        for (const auto& e : times) {
            int arrival = e[0], leaving = e[1], i = e[2];
            while (!busy.empty() && busy.top().first <= arrival) {
                idle.push(busy.top().second);
                busy.pop();
            }
            int j = idle.top();
            if (i == targetFriend) {
                return j;
            }
            idle.pop();
            busy.emplace(leaving, j);
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestChair(times [][]int, targetFriend int) int {
	idle := hp{}
	busy := hp2{}
	for i := range times {
		times[i] = append(times[i], i)
		heap.Push(&idle, i)
	}
	sort.Slice(times, func(i, j int) bool { return times[i][0] < times[j][0] })
	for _, e := range times {
		arrival, leaving, i := e[0], e[1], e[2]
		for len(busy) > 0 && busy[0].t <= arrival {
			heap.Push(&idle, heap.Pop(&busy).(pair).i)
		}
		j := heap.Pop(&idle).(int)
		if i == targetFriend {
			return j
		}
		heap.Push(&busy, pair{leaving, j})
	}
	return -1
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

type pair struct{ t, i int }
type hp2 []pair

func (h hp2) Len() int           { return len(h) }
func (h hp2) Less(i, j int) bool { return h[i].t < h[j].t || (h[i].t == h[j].t && h[i].i < h[j].i) }
func (h hp2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestChair(times: number[][], targetFriend: number): number {
    const n = times.length;
    const idle = new MinPriorityQueue();
    const busy = new MinPriorityQueue({ priority: v => v[0] });
    for (let i = 0; i < n; ++i) {
        times[i].push(i);
        idle.enqueue(i);
    }
    times.sort((a, b) => a[0] - b[0]);
    for (const [arrival, leaving, i] of times) {
        while (busy.size() > 0 && busy.front().element[0] <= arrival) {
            idle.enqueue(busy.dequeue().element[1]);
        }
        const j = idle.dequeue().element;
        if (i === targetFriend) {
            return j;
        }
        busy.enqueue([leaving, j]);
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} times
 * @param {number} targetFriend
 * @return {number}
 */
var smallestChair = function (times, targetFriend) {
    const n = times.length;
    const idle = new MinPriorityQueue();
    const busy = new MinPriorityQueue({ priority: v => v[0] });
    for (let i = 0; i < n; ++i) {
        times[i].push(i);
        idle.enqueue(i);
    }
    times.sort((a, b) => a[0] - b[0]);
    for (const [arrival, leaving, i] of times) {
        while (busy.size() > 0 && busy.front().element[0] <= arrival) {
            idle.enqueue(busy.dequeue().element[1]);
        }
        const j = idle.dequeue().element;
        if (i === targetFriend) {
            return j;
        }
        busy.enqueue([leaving, j]);
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 个朋友在举办一个派对，这些朋友从 <code>0</code> 到 <code>n - 1</code> 编号。派对里有 <strong>无数</strong> 张椅子，编号为 <code>0</code> 到 <code>infinity</code> 。当一个朋友到达派对时，他会占据 <strong>编号最小</strong> 且未被占据的椅子。</p>

<ul>
	<li>比方说，当一个朋友到达时，如果椅子 <code>0</code> ，<code>1</code> 和 <code>5</code> 被占据了，那么他会占据 <code>2</code> 号椅子。</li>
</ul>

<p>当一个朋友离开派对时，他的椅子会立刻变成未占据状态。如果同一时刻有另一个朋友到达，可以立即占据这张椅子。</p>

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>times</code> ，其中 <code>times[i] = [arrival<sub>i</sub>, leaving<sub>i</sub>]</code> 表示第 <code>i</code> 个朋友到达和离开的时刻，同时给你一个整数 <code>targetFriend</code> 。所有到达时间 <strong>互不相同</strong> 。</p>

<p>请你返回编号为 <code>targetFriend</code> 的朋友占据的 <strong>椅子编号</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>times = [[1,4],[2,3],[4,6]], targetFriend = 1
<b>输出：</b>1
<b>解释：</b>
- 朋友 0 时刻 1 到达，占据椅子 0 。
- 朋友 1 时刻 2 到达，占据椅子 1 。
- 朋友 1 时刻 3 离开，椅子 1 变成未占据。
- 朋友 0 时刻 4 离开，椅子 0 变成未占据。
- 朋友 2 时刻 4 到达，占据椅子 0 。
朋友 1 占据椅子 1 ，所以返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>times = [[3,10],[1,5],[2,6]], targetFriend = 0
<b>输出：</b>2
<b>解释：</b>
- 朋友 1 时刻 1 到达，占据椅子 0 。
- 朋友 2 时刻 2 到达，占据椅子 1 。
- 朋友 0 时刻 3 到达，占据椅子 2 。
- 朋友 1 时刻 5 离开，椅子 0 变成未占据。
- 朋友 2 时刻 6 离开，椅子 1 变成未占据。
- 朋友 0 时刻 10 离开，椅子 2 变成未占据。
朋友 0 占据椅子 2 ，所以返回 2 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == times.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>times[i].length == 2</code></li>
	<li><code>1 &lt;= arrival<sub>i</sub> &lt; leaving<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= targetFriend &lt;= n - 1</code></li>
	<li>每个 <code>arrival<sub>i</sub></code> 时刻 <strong>互不相同</strong> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们首先将每个朋友的到达时间、离开时间和编号组成一个三元组，然后按到达时间排序。

我们使用一个小根堆 $\textit{idle}$ 来存储当前空闲的椅子编号，初始时，我们将 $0, 1, \ldots, n-1$ 加入 $\textit{idle}$ 中。使用一个小根堆 $\textit{busy}$ 存储二元组 $(\textit{leaving}, \textit{chair})$，其中 $\textit{leaving}$ 表示离开时间，而 $\textit{chair}$ 表示椅子编号。

遍历每个朋友的到达时间、离开时间和编号，对于每个朋友，我们首先将所有离开时间小于等于当前朋友到达时间的朋友从 $\textit{busy}$ 中弹出，将他们占据的椅子编号加入 $\textit{idle}$ 中。然后我们从 $\textit{idle}$ 中弹出一个椅子编号，将其分配给当前朋友，将 $(\textit{leaving}, \textit{chair})$ 加入 $\textit{busy}$ 中。如果当前朋友的编号等于 $\textit{targetFriend}$，我们返回当前分配的椅子编号。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为朋友的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        for i in range(n):
            times[i].append(i)
        times.sort()
        idle = list(range(n))
        heapify(idle)
        busy = []
        for arrival, leaving, i in times:
            while busy and busy[0][0] <= arrival:
                heappush(idle, heappop(busy)[1])
            j = heappop(idle)
            if i == targetFriend:
                return j
            heappush(busy, (leaving, j))
```

#### Java

```java
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int n = times.length;
        PriorityQueue<Integer> idle = new PriorityQueue<>();
        PriorityQueue<int[]> busy = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < n; ++i) {
            times[i] = new int[] {times[i][0], times[i][1], i};
            idle.offer(i);
        }
        Arrays.sort(times, Comparator.comparingInt(a -> a[0]));
        for (var e : times) {
            int arrival = e[0], leaving = e[1], i = e[2];
            while (!busy.isEmpty() && busy.peek()[0] <= arrival) {
                idle.offer(busy.poll()[1]);
            }
            int j = idle.poll();
            if (i == targetFriend) {
                return j;
            }
            busy.offer(new int[] {leaving, j});
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> busy;
        priority_queue<int, vector<int>, greater<int>> idle;
        int n = times.size();
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);
            idle.push(i);
        }
        ranges::sort(times);
        for (const auto& e : times) {
            int arrival = e[0], leaving = e[1], i = e[2];
            while (!busy.empty() && busy.top().first <= arrival) {
                idle.push(busy.top().second);
                busy.pop();
            }
            int j = idle.top();
            if (i == targetFriend) {
                return j;
            }
            idle.pop();
            busy.emplace(leaving, j);
        }
        return -1;
    }
};
```

#### Go

```go
func smallestChair(times [][]int, targetFriend int) int {
	idle := hp{}
	busy := hp2{}
	for i := range times {
		times[i] = append(times[i], i)
		heap.Push(&idle, i)
	}
	sort.Slice(times, func(i, j int) bool { return times[i][0] < times[j][0] })
	for _, e := range times {
		arrival, leaving, i := e[0], e[1], e[2]
		for len(busy) > 0 && busy[0].t <= arrival {
			heap.Push(&idle, heap.Pop(&busy).(pair).i)
		}
		j := heap.Pop(&idle).(int)
		if i == targetFriend {
			return j
		}
		heap.Push(&busy, pair{leaving, j})
	}
	return -1
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

type pair struct{ t, i int }
type hp2 []pair

func (h hp2) Len() int           { return len(h) }
func (h hp2) Less(i, j int) bool { return h[i].t < h[j].t || (h[i].t == h[j].t && h[i].i < h[j].i) }
func (h hp2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function smallestChair(times: number[][], targetFriend: number): number {
    const n = times.length;
    const idle = new MinPriorityQueue();
    const busy = new MinPriorityQueue({ priority: v => v[0] });
    for (let i = 0; i < n; ++i) {
        times[i].push(i);
        idle.enqueue(i);
    }
    times.sort((a, b) => a[0] - b[0]);
    for (const [arrival, leaving, i] of times) {
        while (busy.size() > 0 && busy.front().element[0] <= arrival) {
            idle.enqueue(busy.dequeue().element[1]);
        }
        const j = idle.dequeue().element;
        if (i === targetFriend) {
            return j;
        }
        busy.enqueue([leaving, j]);
    }
    return -1;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} times
 * @param {number} targetFriend
 * @return {number}
 */
var smallestChair = function (times, targetFriend) {
    const n = times.length;
    const idle = new MinPriorityQueue();
    const busy = new MinPriorityQueue({ priority: v => v[0] });
    for (let i = 0; i < n; ++i) {
        times[i].push(i);
        idle.enqueue(i);
    }
    times.sort((a, b) => a[0] - b[0]);
    for (const [arrival, leaving, i] of times) {
        while (busy.size() > 0 && busy.front().element[0] <= arrival) {
            idle.enqueue(busy.dequeue().element[1]);
        }
        const j = idle.dequeue().element;
        if (i === targetFriend) {
            return j;
        }
        busy.enqueue([leaving, j]);
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1943. 描述绘画结果](https://leetcode.cn/problems/describe-the-painting){#1943}

{{< tabs "1943" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        d = defaultdict(int)
        for l, r, c in segments:
            d[l] += c
            d[r] -= c
        s = sorted([[k, v] for k, v in d.items()])
        n = len(s)
        for i in range(1, n):
            s[i][1] += s[i - 1][1]
        return [[s[i][0], s[i + 1][0], s[i][1]] for i in range(n - 1) if s[i][1]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Long>> splitPainting(int[][] segments) {
        TreeMap<Integer, Long> d = new TreeMap<>();
        for (int[] e : segments) {
            int l = e[0], r = e[1], c = e[2];
            d.put(l, d.getOrDefault(l, 0L) + c);
            d.put(r, d.getOrDefault(r, 0L) - c);
        }
        List<List<Long>> ans = new ArrayList<>();
        long i = 0, j = 0;
        long cur = 0;
        for (Map.Entry<Integer, Long> e : d.entrySet()) {
            if (Objects.equals(e.getKey(), d.firstKey())) {
                i = e.getKey();
            } else {
                j = e.getKey();
                if (cur > 0) {
                    ans.add(Arrays.asList(i, j, cur));
                }
                i = j;
            }
            cur += e.getValue();
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
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> d;
        for (auto& e : segments) {
            int l = e[0], r = e[1], c = e[2];
            d[l] += c;
            d[r] -= c;
        }
        vector<vector<long long>> ans;
        long long i, j, cur = 0;
        for (auto& it : d) {
            if (it == *d.begin())
                i = it.first;
            else {
                j = it.first;
                if (cur > 0) ans.push_back({i, j, cur});
                i = j;
            }
            cur += it.second;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitPainting(segments [][]int) [][]int64 {
	d := make(map[int]int64)
	for _, seg := range segments {
		d[seg[0]] += int64(seg[2])
		d[seg[1]] -= int64(seg[2])
	}
	dList := make([]int, 0, len(d))
	for k := range d {
		dList = append(dList, k)
	}
	sort.Ints(dList)

	var ans [][]int64

	i := dList[0]
	cur := d[i]
	for j := 1; j < len(dList); j++ {
		it := d[dList[j]]
		if cur > 0 {
			ans = append(ans, []int64{int64(i), int64(dList[j]), cur})
		}
		cur += it
		i = dList[j]
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

<p>给你一个细长的画，用数轴表示。这幅画由若干有重叠的线段表示，每个线段有 <strong>独一无二</strong>&nbsp;的颜色。给你二维整数数组&nbsp;<code>segments</code>&nbsp;，其中&nbsp;<code>segments[i] = [start<sub>i</sub>, end<sub>i</sub>, color<sub>i</sub>]</code>&nbsp;表示线段为&nbsp;<strong>半开区间</strong>&nbsp;<code>[start<sub>i</sub>, end<sub>i</sub>)</code> 且颜色为&nbsp;<code>color<sub>i</sub></code>&nbsp;。</p>

<p>线段间重叠部分的颜色会被 <strong>混合</strong>&nbsp;。如果有两种或者更多颜色混合时，它们会形成一种新的颜色，用一个 <strong>集合</strong>&nbsp;表示这个混合颜色。</p>

<ul>
	<li>比方说，如果颜色&nbsp;<code>2</code>&nbsp;，<code>4</code>&nbsp;和&nbsp;<code>6</code>&nbsp;被混合，那么结果颜色为&nbsp;<code>{2,4,6}</code>&nbsp;。</li>
</ul>

<p>为了简化题目，你不需要输出整个集合，只需要用集合中所有元素的 <strong>和</strong>&nbsp;来表示颜色集合。</p>

<p>你想要用 <strong>最少数目</strong>&nbsp;不重叠 <strong>半开区间</strong>&nbsp;来 <b>表示</b>&nbsp;这幅混合颜色的画。这些线段可以用二维数组&nbsp;<code>painting</code>&nbsp;表示，其中 <code>painting[j] = [left<sub>j</sub>, right<sub>j</sub>, mix<sub>j</sub>]</code>&nbsp;表示一个&nbsp;<strong>半开区间</strong><code>[left<sub>j</sub>, right<sub>j</sub>)</code>&nbsp;的颜色 <strong>和</strong>&nbsp;为&nbsp;<code>mix<sub>j</sub></code>&nbsp;。</p>

<ul>
	<li>比方说，这幅画由&nbsp;<code>segments = [[1,4,5],[1,7,7]]</code>&nbsp;组成，那么它可以表示为&nbsp;<code>painting = [[1,4,12],[4,7,7]]</code>&nbsp;，因为：

    <ul>
    	<li><code>[1,4)</code>&nbsp;由颜色&nbsp;<code>{5,7}</code>&nbsp;组成（和为&nbsp;<code>12</code>），分别来自第一个线段和第二个线段。</li>
    	<li><code>[4,7)</code>&nbsp;由颜色 <code>{7}</code>&nbsp;组成，来自第二个线段。</li>
    </ul>
    </li>

</ul>

<p>请你返回二维数组&nbsp;<code>painting</code>&nbsp;，它表示最终绘画的结果（<strong>没有</strong>&nbsp;被涂色的部分不出现在结果中）。你可以按 <strong>任意顺序</strong> 返回最终数组的结果。</p>

<p><strong>半开区间&nbsp;</strong><code>[a, b)</code>&nbsp;是数轴上点&nbsp;<code>a</code> 和点&nbsp;<code>b</code>&nbsp;之间的部分，<strong>包含 </strong>点&nbsp;<code>a</code>&nbsp;且 <strong>不包含</strong>&nbsp;点&nbsp;<code>b</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1943.Describe%20the%20Painting/images/1.png" style="width: 529px; height: 241px;" />
<pre>
<b>输入：</b>segments = [[1,4,5],[4,7,7],[1,7,9]]
<b>输出：</b>[[1,4,14],[4,7,16]]
<strong>解释：</strong>绘画结果可以表示为：
- [1,4) 颜色为 {5,9} （和为 14），分别来自第一和第二个线段。
- [4,7) 颜色为 {7,9} （和为 16），分别来自第二和第三个线段。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1943.Describe%20the%20Painting/images/2.png" style="width: 532px; height: 219px;" />
<pre>
<b>输入：</b>segments = [[1,7,9],[6,8,15],[8,10,7]]
<b>输出：</b>[[1,6,9],[6,7,24],[7,8,15],[8,10,7]]
<b>解释：</b>绘画结果可以以表示为：
- [1,6) 颜色为 9 ，来自第一个线段。
- [6,7) 颜色为 {9,15} （和为 24），来自第一和第二个线段。
- [7,8) 颜色为 15 ，来自第二个线段。
- [8,10) 颜色为 7 ，来自第三个线段。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1943.Describe%20the%20Painting/images/c1.png" style="width: 529px; height: 289px;" />
<pre>
<b>输入：</b>segments = [[1,4,5],[1,4,7],[4,7,1],[4,7,11]]
<b>输出：</b>[[1,4,12],[4,7,12]]
<strong>解释：</strong>绘画结果可以表示为：
- [1,4) 颜色为 {5,7} （和为 12），分别来自第一和第二个线段。
- [4,7) 颜色为 {1,11} （和为 12），分别来自第三和第四个线段。
注意，只返回一个单独的线段 [1,7) 是不正确的，因为混合颜色的集合不相同。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= segments.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>segments[i].length == 3</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= color<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li>每种颜色&nbsp;<code>color<sub>i</sub></code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        d = defaultdict(int)
        for l, r, c in segments:
            d[l] += c
            d[r] -= c
        s = sorted([[k, v] for k, v in d.items()])
        n = len(s)
        for i in range(1, n):
            s[i][1] += s[i - 1][1]
        return [[s[i][0], s[i + 1][0], s[i][1]] for i in range(n - 1) if s[i][1]]
```

#### Java

```java
class Solution {
    public List<List<Long>> splitPainting(int[][] segments) {
        TreeMap<Integer, Long> d = new TreeMap<>();
        for (int[] e : segments) {
            int l = e[0], r = e[1], c = e[2];
            d.put(l, d.getOrDefault(l, 0L) + c);
            d.put(r, d.getOrDefault(r, 0L) - c);
        }
        List<List<Long>> ans = new ArrayList<>();
        long i = 0, j = 0;
        long cur = 0;
        for (Map.Entry<Integer, Long> e : d.entrySet()) {
            if (Objects.equals(e.getKey(), d.firstKey())) {
                i = e.getKey();
            } else {
                j = e.getKey();
                if (cur > 0) {
                    ans.add(Arrays.asList(i, j, cur));
                }
                i = j;
            }
            cur += e.getValue();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> d;
        for (auto& e : segments) {
            int l = e[0], r = e[1], c = e[2];
            d[l] += c;
            d[r] -= c;
        }
        vector<vector<long long>> ans;
        long long i, j, cur = 0;
        for (auto& it : d) {
            if (it == *d.begin())
                i = it.first;
            else {
                j = it.first;
                if (cur > 0) ans.push_back({i, j, cur});
                i = j;
            }
            cur += it.second;
        }
        return ans;
    }
};
```

#### Go

```go
func splitPainting(segments [][]int) [][]int64 {
	d := make(map[int]int64)
	for _, seg := range segments {
		d[seg[0]] += int64(seg[2])
		d[seg[1]] -= int64(seg[2])
	}
	dList := make([]int, 0, len(d))
	for k := range d {
		dList = append(dList, k)
	}
	sort.Ints(dList)

	var ans [][]int64

	i := dList[0]
	cur := d[i]
	for j := 1; j < len(dList); j++ {
		it := d[dList[j]]
		if cur > 0 {
			ans = append(ans, []int64{int64(i), int64(dList[j]), cur})
		}
		cur += it
		i = dList[j]
	}

	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1944. 队列中可以看到的人数](https://leetcode.cn/problems/number-of-visible-people-in-a-queue){#1944}

{{< tabs "1944" >}}

{{% tab "python" %}}
```python
class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        ans = [0] * n
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and stk[-1] < heights[i]:
                ans[i] += 1
                stk.pop()
            if stk:
                ans[i] += 1
            stk.append(heights[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && stk.peek() < heights[i]) {
                stk.pop();
                ++ans[i];
            }
            if (!stk.isEmpty()) {
                ++ans[i];
            }
            stk.push(heights[i]);
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
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (stk.size() && stk.top() < heights[i]) {
                ++ans[i];
                stk.pop();
            }
            if (stk.size()) {
                ++ans[i];
            }
            stk.push(heights[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canSeePersonsCount(heights []int) []int {
	n := len(heights)
	ans := make([]int, n)
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && stk[len(stk)-1] < heights[i] {
			ans[i]++
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			ans[i]++
		}
		stk = append(stk, heights[i])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canSeePersonsCount(heights: number[]): number[] {
    const n = heights.length;
    const ans: number[] = new Array(n).fill(0);
    const stk: number[] = [];
    for (let i = n - 1; ~i; --i) {
        while (stk.length && stk.at(-1) < heights[i]) {
            ++ans[i];
            stk.pop();
        }
        if (stk.length) {
            ++ans[i];
        }
        stk.push(heights[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let n = heights.len();
        let mut ans = vec![0; n];
        let mut stack = Vec::new();
        for i in (0..n).rev() {
            while !stack.is_empty() {
                ans[i] += 1;
                if heights[i] <= heights[*stack.last().unwrap()] {
                    break;
                }
                stack.pop();
            }
            stack.push(i);
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
int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * heightsSize);
    memset(ans, 0, sizeof(int) * heightsSize);
    int stack[heightsSize];
    int i = 0;
    for (int j = heightsSize - 1; j >= 0; j--) {
        while (i) {
            ans[j]++;
            if (heights[j] <= heights[stack[i - 1]]) {
                break;
            }
            i--;
        }
        stack[i++] = j;
    }
    *returnSize = heightsSize;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有&nbsp;<code>n</code>&nbsp;个人排成一个队列，<strong>从左到右</strong>&nbsp;编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。给你以一个整数数组&nbsp;<code>heights</code>&nbsp;，每个整数 <strong>互不相同</strong>，<code>heights[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个人的高度。</p>

<p>一个人能 <strong>看到</strong> 他右边另一个人的条件是这两人之间的所有人都比他们两人 <strong>矮</strong>&nbsp;。更正式的，第&nbsp;<code>i</code>&nbsp;个人能看到第&nbsp;<code>j</code>&nbsp;个人的条件是&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>min(heights[i], heights[j]) &gt; max(heights[i+1], heights[i+2], ..., heights[j-1])</code>&nbsp;。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的数组<em>&nbsp;</em><code>answer</code><em>&nbsp;</em>，其中<em>&nbsp;</em><code>answer[i]</code><em>&nbsp;</em>是第&nbsp;<code>i</code>&nbsp;个人在他右侧队列中能&nbsp;<strong>看到</strong>&nbsp;的&nbsp;<strong>人数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1944.Number%20of%20Visible%20People%20in%20a%20Queue/images/queue-plane.jpg" style="width: 600px; height: 247px;" /></p>

<pre>
<b>输入：</b>heights = [10,6,8,5,11,9]
<b>输出：</b>[3,1,2,1,1,0]
<strong>解释：</strong>
第 0 个人能看到编号为 1 ，2 和 4 的人。
第 1 个人能看到编号为 2 的人。
第 2 个人能看到编号为 3 和 4 的人。
第 3 个人能看到编号为 4 的人。
第 4 个人能看到编号为 5 的人。
第 5 个人谁也看不到因为他右边没人。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>heights = [5,1,2,3,10]
<b>输出：</b>[4,1,1,1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == heights.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>heights</code>&nbsp;中所有数 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们观察发现，对于第 $i$ 个人来说，他能看到的人一定是按从左到右高度严格单调递增的。

因此，我们可以倒序遍历数组 $\textit{heights}$，用一个从栈顶到栈底单调递增的栈 $\textit{stk}$ 记录已经遍历过的人的高度。

对于第 $i$ 个人，如果栈不为空并且栈顶元素小于 $\textit{heights}[i]$，累加当前第 $i$ 个人能看到的人数，然后将栈顶元素出栈，直到栈为空或者栈顶元素大于等于 $\textit{heights}[i]$。如果此时栈不为空，说明栈顶元素大于等于 $\textit{heights}[i]$，那么第 $i$ 个人能看到的人数还要再加 $1$。

接下来，我们将 $\textit{heights}[i]$ 入栈，继续遍历下一个人。

遍历结束后，返回答案数组 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{heights}$ 的长度。

相似题目：

-   [2282. 在一个网格中可以看到的人数](https://github.com/doocs/leetcode/blob/main/solution/2200-2299/2282.Number%20of%20People%20That%20Can%20Be%20Seen%20in%20a%20Grid/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        ans = [0] * n
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and stk[-1] < heights[i]:
                ans[i] += 1
                stk.pop()
            if stk:
                ans[i] += 1
            stk.append(heights[i])
        return ans
```

#### Java

```java
class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && stk.peek() < heights[i]) {
                stk.pop();
                ++ans[i];
            }
            if (!stk.isEmpty()) {
                ++ans[i];
            }
            stk.push(heights[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (stk.size() && stk.top() < heights[i]) {
                ++ans[i];
                stk.pop();
            }
            if (stk.size()) {
                ++ans[i];
            }
            stk.push(heights[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func canSeePersonsCount(heights []int) []int {
	n := len(heights)
	ans := make([]int, n)
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && stk[len(stk)-1] < heights[i] {
			ans[i]++
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			ans[i]++
		}
		stk = append(stk, heights[i])
	}
	return ans
}
```

#### TypeScript

```ts
function canSeePersonsCount(heights: number[]): number[] {
    const n = heights.length;
    const ans: number[] = new Array(n).fill(0);
    const stk: number[] = [];
    for (let i = n - 1; ~i; --i) {
        while (stk.length && stk.at(-1) < heights[i]) {
            ++ans[i];
            stk.pop();
        }
        if (stk.length) {
            ++ans[i];
        }
        stk.push(heights[i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let n = heights.len();
        let mut ans = vec![0; n];
        let mut stack = Vec::new();
        for i in (0..n).rev() {
            while !stack.is_empty() {
                ans[i] += 1;
                if heights[i] <= heights[*stack.last().unwrap()] {
                    break;
                }
                stack.pop();
            }
            stack.push(i);
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
int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * heightsSize);
    memset(ans, 0, sizeof(int) * heightsSize);
    int stack[heightsSize];
    int i = 0;
    for (int j = heightsSize - 1; j >= 0; j--) {
        while (i) {
            ans[j]++;
            if (heights[j] <= heights[stack[i - 1]]) {
                break;
            }
            i--;
        }
        stack[i++] = j;
    }
    *returnSize = heightsSize;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1945. 字符串转化后的各位数字之和](https://leetcode.cn/problems/sum-of-digits-of-string-after-convert){#1945}

{{< tabs "1945" >}}

{{% tab "python" %}}
```python
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        s = ''.join(str(ord(c) - ord('a') + 1) for c in s)
        for _ in range(k):
            t = sum(int(c) for c in s)
            s = str(t)
        return int(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append(c - 'a' + 1);
        }
        s = sb.toString();
        while (k-- > 0) {
            int t = 0;
            for (char c : s.toCharArray()) {
                t += c - '0';
            }
            s = String.valueOf(t);
        }
        return Integer.parseInt(s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getLucky(string s, int k) {
        string t;
        for (char c : s) {
            t += to_string(c - 'a' + 1);
        }
        s = t;
        while (k--) {
            int t = 0;
            for (char c : s) {
                t += c - '0';
            }
            s = to_string(t);
        }
        return stoi(s);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getLucky(s string, k int) int {
	var t strings.Builder
	for _, c := range s {
		t.WriteString(strconv.Itoa(int(c - 'a' + 1)))
	}
	s = t.String()
	for k > 0 {
		k--
		t := 0
		for _, c := range s {
			t += int(c - '0')
		}
		s = strconv.Itoa(t)
	}
	ans, _ := strconv.Atoi(s)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getLucky(s: string, k: number): number {
    let ans = '';
    for (const c of s) {
        ans += c.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
    }
    for (let i = 0; i < k; i++) {
        let t = 0;
        for (const v of ans) {
            t += Number(v);
        }
        ans = `${t}`;
    }
    return Number(ans);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_lucky(s: String, k: i32) -> i32 {
        let mut ans = String::new();
        for c in s.as_bytes() {
            ans.push_str(&(c - b'a' + 1).to_string());
        }
        for _ in 0..k {
            let mut t = 0;
            for c in ans.as_bytes() {
                t += (c - b'0') as i32;
            }
            ans = t.to_string();
        }
        ans.parse().unwrap()
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @param Integer $k
     * @return Integer
     */
    function getLucky($s, $k) {
        $rs = '';
        for ($i = 0; $i < strlen($s); $i++) {
            $num = ord($s[$i]) - 96;
            $rs = $rs . strval($num);
        }
        while ($k != 0) {
            $sum = 0;
            for ($j = 0; $j < strlen($rs); $j++) {
                $sum += intval($rs[$j]);
            }
            $rs = strval($sum);
            $k--;
        }
        return intval($rs);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由小写字母组成的字符串 <code>s</code> ，以及一个整数 <code>k</code> 。你的任务是通过一种特殊处理将字符串转为整数，然后通过重复对它的数位求和&nbsp;<code>k</code> 次来进行转换。更具体地说，执行以下步骤：</p>

<ol>
	<li>用字母在字母表中的位置&nbsp;<strong>替换&nbsp;</strong>该字母，将 <code>s</code> <strong>转化</strong> 为一个整数（也就是，<code>'a'</code> 用 <code>1</code> 替换，<code>'b'</code> 用 <code>2</code> 替换，... <code>'z'</code> 用 <code>26</code> 替换）。</li>
	<li>接着，将整数 <strong>转换</strong> 为其 <strong>各位数字之和</strong> 。</li>
	<li>共重复 <strong>转换</strong> 操作（第 2 步）&nbsp;<code>k</code><strong> 次</strong> 。</li>
</ol>

<p>例如，如果 <code>s = "zbax"</code> 且 <code>k = 2</code> ，那么执行下述步骤后得到的结果是整数 <code>8</code> ：</p>

<ul>
	<li><strong>转化：</strong><code>"zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124</code></li>
	<li><strong>转换 #1</strong>：<code>262124&nbsp;➝ 2 + 6 + 2 + 1 + 2 + 4&nbsp;➝ 17</code></li>
	<li><strong>转换 #2</strong>：<code>17 ➝ 1 + 7 ➝ 8</code></li>
</ul>

<p>返回执行上述 <strong>操作</strong> 后得到的 <strong>结果整数</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block"><strong>输入：</strong>s = "iiii", k = 1</div>

<div class="example-block"><strong>输出：</strong>36</div>

<div class="example-block"><strong>解释：</strong></div>

<div class="example-block">操作如下：</div>

<ul>
	<li class="example-block">转化："iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999</li>
	<li class="example-block">转换 #1：9999 ➝ 9 + 9 + 9 + 9 ➝ 36</li>
</ul>

<div class="example-block">因此，结果整数为 36 。</div>

<div class="example-block">&nbsp;</div>

<p><strong>示例 2：</strong></p>

<div class="example-block"><strong>输入：</strong>s = "leetcode", k = 2</div>

<div class="example-block"><strong>输出：</strong>6</div>

<div class="example-block"><strong>解释：</strong></div>

<div class="example-block">操作如下：</div>

<ul>
	<li class="example-block">转化："leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545</li>
	<li class="example-block">转换 #1：12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33</li>
	<li class="example-block">转换 #2：33 ➝ 3 + 3 ➝ 6</li>
</ul>

<p class="example-block">因此，结果整数为 6 。</p>

<p class="example-block">&nbsp;</p>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "zbax", k = 2</span></p>

<p><span class="example-io"><b>输出：</b>8</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题目描述进行模拟即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        s = ''.join(str(ord(c) - ord('a') + 1) for c in s)
        for _ in range(k):
            t = sum(int(c) for c in s)
            s = str(t)
        return int(s)
```

#### Java

```java
class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append(c - 'a' + 1);
        }
        s = sb.toString();
        while (k-- > 0) {
            int t = 0;
            for (char c : s.toCharArray()) {
                t += c - '0';
            }
            s = String.valueOf(t);
        }
        return Integer.parseInt(s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getLucky(string s, int k) {
        string t;
        for (char c : s) {
            t += to_string(c - 'a' + 1);
        }
        s = t;
        while (k--) {
            int t = 0;
            for (char c : s) {
                t += c - '0';
            }
            s = to_string(t);
        }
        return stoi(s);
    }
};
```

#### Go

```go
func getLucky(s string, k int) int {
	var t strings.Builder
	for _, c := range s {
		t.WriteString(strconv.Itoa(int(c - 'a' + 1)))
	}
	s = t.String()
	for k > 0 {
		k--
		t := 0
		for _, c := range s {
			t += int(c - '0')
		}
		s = strconv.Itoa(t)
	}
	ans, _ := strconv.Atoi(s)
	return ans
}
```

#### TypeScript

```ts
function getLucky(s: string, k: number): number {
    let ans = '';
    for (const c of s) {
        ans += c.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
    }
    for (let i = 0; i < k; i++) {
        let t = 0;
        for (const v of ans) {
            t += Number(v);
        }
        ans = `${t}`;
    }
    return Number(ans);
}
```

#### Rust

```rust
impl Solution {
    pub fn get_lucky(s: String, k: i32) -> i32 {
        let mut ans = String::new();
        for c in s.as_bytes() {
            ans.push_str(&(c - b'a' + 1).to_string());
        }
        for _ in 0..k {
            let mut t = 0;
            for c in ans.as_bytes() {
                t += (c - b'0') as i32;
            }
            ans = t.to_string();
        }
        ans.parse().unwrap()
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @param Integer $k
     * @return Integer
     */
    function getLucky($s, $k) {
        $rs = '';
        for ($i = 0; $i < strlen($s); $i++) {
            $num = ord($s[$i]) - 96;
            $rs = $rs . strval($num);
        }
        while ($k != 0) {
            $sum = 0;
            for ($j = 0; $j < strlen($rs); $j++) {
                $sum += intval($rs[$j]);
            }
            $rs = strval($sum);
            $k--;
        }
        return intval($rs);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1946. 子字符串突变后可能得到的最大整数](https://leetcode.cn/problems/largest-number-after-mutating-substring){#1946}

{{< tabs "1946" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        s = list(num)
        changed = False
        for i, c in enumerate(s):
            d = str(change[int(c)])
            if changed and d < c:
                break
            if d > c:
                changed = True
                s[i] = d
        return "".join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String maximumNumber(String num, int[] change) {
        char[] s = num.toCharArray();
        boolean changed = false;
        for (int i = 0; i < s.length; ++i) {
            char d = (char) (change[s[i] - '0'] + '0');
            if (changed && d < s[i]) {
                break;
            }
            if (d > s[i]) {
                changed = true;
                s[i] = d;
            }
        }
        return new String(s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        bool changed = false;
        for (int i = 0; i < n; ++i) {
            char d = '0' + change[num[i] - '0'];
            if (changed && d < num[i]) {
                break;
            }
            if (d > num[i]) {
                changed = true;
                num[i] = d;
            }
        }
        return num;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumNumber(num string, change []int) string {
	s := []byte(num)
	changed := false
	for i, c := range num {
		d := byte('0' + change[c-'0'])
		if changed && d < s[i] {
			break
		}
		if d > s[i] {
			s[i] = d
			changed = true
		}
	}
	return string(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumNumber(num: string, change: number[]): string {
    const s = num.split('');
    let changed = false;
    for (let i = 0; i < s.length; ++i) {
        const d = change[+s[i]].toString();
        if (changed && d < s[i]) {
            break;
        }
        if (d > s[i]) {
            s[i] = d;
            changed = true;
        }
    }
    return s.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_number(num: String, change: Vec<i32>) -> String {
        let mut s: Vec<char> = num.chars().collect();
        let mut changed = false;
        for i in 0..s.len() {
            let d = (change[s[i] as usize - '0' as usize] + '0' as i32) as u8 as char;
            if changed && d < s[i] {
                break;
            }
            if d > s[i] {
                changed = true;
                s[i] = d;
            }
        }
        s.into_iter().collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} num
 * @param {number[]} change
 * @return {string}
 */
var maximumNumber = function (num, change) {
    const s = num.split('');
    let changed = false;
    for (let i = 0; i < s.length; ++i) {
        const d = change[+s[i]].toString();
        if (changed && d < s[i]) {
            break;
        }
        if (d > s[i]) {
            s[i] = d;
            changed = true;
        }
    }
    return s.join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>num</code> ，该字符串表示一个大整数。另给你一个长度为 <code>10</code> 且 <strong>下标从 0&nbsp; 开始</strong> 的整数数组 <code>change</code> ，该数组将 <code>0-9</code> 中的每个数字映射到另一个数字。更规范的说法是，数字 <code>d</code> 映射为数字 <code>change[d]</code> 。</p>

<p>你可以选择 <strong>突变</strong>&nbsp; <code>num</code> 的任一子字符串。<strong>突变</strong> 子字符串意味着将每位数字 <code>num[i]</code> 替换为该数字在 <code>change</code> 中的映射（也就是说，将 <code>num[i]</code> 替换为 <code>change[num[i]]</code>）。</p>

<p>请你找出在对 <code>num</code> 的任一子字符串执行突变操作（也可以不执行）后，可能得到的 <strong>最大整数</strong> ，并用字符串表示返回。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = "<strong><em>1</em></strong>32", change = [9,8,5,0,3,6,4,2,6,8]
<strong>输出：</strong>"<strong><em>8</em></strong>32"
<strong>解释：</strong>替换子字符串 "1"：
- 1 映射为 change[1] = 8 。
因此 "<strong><em>1</em></strong>32" 变为 "<strong><em>8</em></strong>32" 。
"832" 是可以构造的最大整数，所以返回它的字符串表示。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = "<strong><em>021</em></strong>", change = [9,4,3,5,7,2,1,9,0,6]
<strong>输出：</strong>"<strong><em>934</em></strong>"
<strong>解释：</strong>替换子字符串 "021"：
- 0 映射为 change[0] = 9 。
- 2 映射为 change[2] = 3 。
- 1 映射为 change[1] = 4 。
因此，"<strong><em>021</em></strong>" 变为 "<strong><em>934</em></strong>" 。
"934" 是可以构造的最大整数，所以返回它的字符串表示。 
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = "5", change = [1,4,7,5,3,2,5,6,9,4]
<strong>输出：</strong>"5"
<strong>解释：</strong>"5" 已经是可以构造的最大整数，所以返回它的字符串表示。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> 仅由数字 <code>0-9</code> 组成</li>
	<li><code>change.length == 10</code></li>
	<li><code>0 &lt;= change[d] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，我们可以从字符串的高位开始，贪心的进行连续的替换操作，直到遇到一个比当前位数字小的数字为止。

我们先将字符串 $\textit{num}$ 转换为字符数组 $\textit{s}$，用一个变量 $\textit{changed}$ 记录是否已经发生过变化，初始时 $\textit{changed} = \text{false}$。

然后我们遍历字符数组 $\textit{s}$，对于每个字符 $\textit{c}$，我们将其转换为数字 $\textit{d} = \text{change}[\text{int}(\textit{c})]$，如果已经发生过变化且 $\textit{d} < \textit{c}$，则说明我们不能再继续变化，直接退出循环；否则，如果 $\textit{d} > \textit{c}$，则说明我们可以将 $\textit{c}$ 替换为 $\textit{d}$，此时我们将 $\textit{changed} = \text{true}$，并将 $\textit{s}[i]$ 替换为 $\textit{d}$。

最后我们将字符数组 $\textit{s}$ 转换为字符串并返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{num}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        s = list(num)
        changed = False
        for i, c in enumerate(s):
            d = str(change[int(c)])
            if changed and d < c:
                break
            if d > c:
                changed = True
                s[i] = d
        return "".join(s)
```

#### Java

```java
class Solution {
    public String maximumNumber(String num, int[] change) {
        char[] s = num.toCharArray();
        boolean changed = false;
        for (int i = 0; i < s.length; ++i) {
            char d = (char) (change[s[i] - '0'] + '0');
            if (changed && d < s[i]) {
                break;
            }
            if (d > s[i]) {
                changed = true;
                s[i] = d;
            }
        }
        return new String(s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        bool changed = false;
        for (int i = 0; i < n; ++i) {
            char d = '0' + change[num[i] - '0'];
            if (changed && d < num[i]) {
                break;
            }
            if (d > num[i]) {
                changed = true;
                num[i] = d;
            }
        }
        return num;
    }
};
```

#### Go

```go
func maximumNumber(num string, change []int) string {
	s := []byte(num)
	changed := false
	for i, c := range num {
		d := byte('0' + change[c-'0'])
		if changed && d < s[i] {
			break
		}
		if d > s[i] {
			s[i] = d
			changed = true
		}
	}
	return string(s)
}
```

#### TypeScript

```ts
function maximumNumber(num: string, change: number[]): string {
    const s = num.split('');
    let changed = false;
    for (let i = 0; i < s.length; ++i) {
        const d = change[+s[i]].toString();
        if (changed && d < s[i]) {
            break;
        }
        if (d > s[i]) {
            s[i] = d;
            changed = true;
        }
    }
    return s.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_number(num: String, change: Vec<i32>) -> String {
        let mut s: Vec<char> = num.chars().collect();
        let mut changed = false;
        for i in 0..s.len() {
            let d = (change[s[i] as usize - '0' as usize] + '0' as i32) as u8 as char;
            if changed && d < s[i] {
                break;
            }
            if d > s[i] {
                changed = true;
                s[i] = d;
            }
        }
        s.into_iter().collect()
    }
}
```

#### JavaScript

```js
/**
 * @param {string} num
 * @param {number[]} change
 * @return {string}
 */
var maximumNumber = function (num, change) {
    const s = num.split('');
    let changed = false;
    for (let i = 0; i < s.length; ++i) {
        const d = change[+s[i]].toString();
        if (changed && d < s[i]) {
            break;
        }
        if (d > s[i]) {
            s[i] = d;
            changed = true;
        }
    }
    return s.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1947. 最大兼容性评分和](https://leetcode.cn/problems/maximum-compatibility-score-sum){#1947}

{{< tabs "1947" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCompatibilitySum(
        self, students: List[List[int]], mentors: List[List[int]]
    ) -> int:
        def dfs(i: int, s: int):
            if i >= m:
                nonlocal ans
                ans = max(ans, s)
                return
            for j in range(m):
                if not vis[j]:
                    vis[j] = True
                    dfs(i + 1, s + g[i][j])
                    vis[j] = False

        ans = 0
        m = len(students)
        vis = [False] * m
        g = [[0] * m for _ in range(m)]
        for i, x in enumerate(students):
            for j, y in enumerate(mentors):
                g[i][j] = sum(a == b for a, b in zip(x, y))
        dfs(0, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int ans;
    private int[][] g;
    private boolean[] vis;

    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        m = students.length;
        g = new int[m][m];
        vis = new boolean[m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < students[i].length; ++k) {
                    if (students[i][k] == mentors[j][k]) {
                        ++g[i][j];
                    }
                }
            }
        }
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int s) {
        if (i >= m) {
            ans = Math.max(ans, s);
            return;
        }
        for (int j = 0; j < m; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, s + g[i][j]);
                vis[j] = false;
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
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> g(m, vector<int>(m));
        vector<bool> vis(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[i][j] += students[i][k] == mentors[j][k];
                }
            }
        }
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i, int s) {
            if (i >= m) {
                ans = max(ans, s);
                return;
            }
            for (int j = 0; j < m; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    dfs(i + 1, s + g[i][j]);
                    vis[j] = false;
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxCompatibilitySum(students [][]int, mentors [][]int) (ans int) {
	m, n := len(students), len(students[0])
	g := make([][]int, m)
	vis := make([]bool, m)
	for i, x := range students {
		g[i] = make([]int, m)
		for j, y := range mentors {
			for k := 0; k < n; k++ {
				if x[k] == y[k] {
					g[i][j]++
				}
			}
		}
	}
	var dfs func(int, int)
	dfs = func(i, s int) {
		if i == m {
			ans = max(ans, s)
			return
		}
		for j := 0; j < m; j++ {
			if !vis[j] {
				vis[j] = true
				dfs(i+1, s+g[i][j])
				vis[j] = false
			}
		}
	}
	dfs(0, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxCompatibilitySum(students: number[][], mentors: number[][]): number {
    let ans = 0;
    const m = students.length;
    const vis: boolean[] = Array(m).fill(false);
    const g: number[][] = Array.from({ length: m }, () => Array(m).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < m; ++j) {
            for (let k = 0; k < students[i].length; ++k) {
                if (students[i][k] === mentors[j][k]) {
                    g[i][j]++;
                }
            }
        }
    }
    const dfs = (i: number, s: number): void => {
        if (i >= m) {
            ans = Math.max(ans, s);
            return;
        }
        for (let j = 0; j < m; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, s + g[i][j]);
                vis[j] = false;
            }
        }
    };
    dfs(0, 0);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_compatibility_sum(students: Vec<Vec<i32>>, mentors: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let m = students.len();
        let mut vis = vec![false; m];
        let mut g = vec![vec![0; m]; m];

        for i in 0..m {
            for j in 0..m {
                for k in 0..students[i].len() {
                    if students[i][k] == mentors[j][k] {
                        g[i][j] += 1;
                    }
                }
            }
        }

        fn dfs(i: usize, s: i32, m: usize, g: &Vec<Vec<i32>>, vis: &mut Vec<bool>, ans: &mut i32) {
            if i >= m {
                *ans = (*ans).max(s);
                return;
            }
            for j in 0..m {
                if !vis[j] {
                    vis[j] = true;
                    dfs(i + 1, s + g[i][j], m, g, vis, ans);
                    vis[j] = false;
                }
            }
        }

        dfs(0, 0, m, &g, &mut vis, &mut ans);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} students
 * @param {number[][]} mentors
 * @return {number}
 */
var maxCompatibilitySum = function (students, mentors) {
    let ans = 0;
    const m = students.length;
    const vis = Array(m).fill(false);
    const g = Array.from({ length: m }, () => Array(m).fill(0));

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < m; ++j) {
            for (let k = 0; k < students[i].length; ++k) {
                if (students[i][k] === mentors[j][k]) {
                    g[i][j]++;
                }
            }
        }
    }

    const dfs = function (i, s) {
        if (i >= m) {
            ans = Math.max(ans, s);
            return;
        }
        for (let j = 0; j < m; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, s + g[i][j]);
                vis[j] = false;
            }
        }
    };

    dfs(0, 0);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一份由 <code>n</code> 个问题组成的调查问卷，每个问题的答案要么是 <code>0</code>（no，否），要么是 <code>1</code>（yes，是）。</p>

<p>这份调查问卷被分发给 <code>m</code> 名学生和 <code>m</code> 名导师，学生和导师的编号都是从 <code>0</code> 到 <code>m - 1</code> 。学生的答案用一个二维整数数组 <code>students</code> 表示，其中 <code>students[i]</code> 是一个整数数组，包含第 <code>i</code> 名学生对调查问卷给出的答案（<strong>下标从 0 开始</strong>）。导师的答案用一个二维整数数组 <code>mentors</code> 表示，其中 <code>mentors[j]</code> 是一个整数数组，包含第 <code>j</code> 名导师对调查问卷给出的答案（<strong>下标从 0 开始</strong>）。</p>

<p>每个学生都会被分配给 <strong>一名</strong> 导师，而每位导师也会分配到 <strong>一名</strong> 学生。配对的学生与导师之间的兼容性评分等于学生和导师答案相同的次数。</p>

<ul>
	<li>例如，学生答案为<code>[1, <strong><em>0</em></strong>, <strong><em>1</em></strong>]</code> 而导师答案为 <code>[0, <strong><em>0</em></strong>, <strong><em>1</em></strong>]</code> ，那么他们的兼容性评分为 2 ，因为只有第二个和第三个答案相同。</li>
</ul>

<p>请你找出最优的学生与导师的配对方案，以 <strong>最大程度上</strong> 提高 <strong>兼容性评分和</strong> 。</p>

<p>给你 <code>students</code> 和 <code>mentors</code> ，返回可以得到的<em> </em><strong>最大兼容性评分和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
<strong>输出：</strong>8
<strong>解释：</strong>按下述方式分配学生和导师：
- 学生 0 分配给导师 2 ，兼容性评分为 3 。
- 学生 1 分配给导师 0 ，兼容性评分为 2 。
- 学生 2 分配给导师 1 ，兼容性评分为 3 。
最大兼容性评分和为 3 + 2 + 3 = 8 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
<strong>输出：</strong>0
<strong>解释：</strong>任意学生与导师配对的兼容性评分都是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == students.length == mentors.length</code></li>
	<li><code>n == students[i].length == mentors[j].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 8</code></li>
	<li><code>students[i][k]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>mentors[j][k]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 回溯

我们可以先预处理出每个学生 $i$ 和导师 $j$ 之间的兼容性评分 $g[i][j]$，然后使用回溯算法求解。

定义一个函数 $\textit{dfs}(i, s)$，其中 $i$ 表示当前处理到第 $i$ 个学生，$s$ 表示当前的兼容性评分和。

在 $\textit{dfs}(i, s)$ 中，如果 $i \geq m$，表示所有学生都已经分配完毕，此时更新答案为 $\max(\textit{ans}, s)$。否则，我们枚举第 $i$ 个学生可以分配给哪个导师，然后递归处理下一个学生。过程中，我们用一个数组 $\textit{vis}$ 记录哪些导师已经被分配过，以避免重复分配。

我们调用 $\textit{dfs}(0, 0)$ 即可得到最大的兼容性评分和。

时间复杂度 $O(m!)$，空间复杂度 $O(m^2)$。其中 $m$ 为学生和导师的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCompatibilitySum(
        self, students: List[List[int]], mentors: List[List[int]]
    ) -> int:
        def dfs(i: int, s: int):
            if i >= m:
                nonlocal ans
                ans = max(ans, s)
                return
            for j in range(m):
                if not vis[j]:
                    vis[j] = True
                    dfs(i + 1, s + g[i][j])
                    vis[j] = False

        ans = 0
        m = len(students)
        vis = [False] * m
        g = [[0] * m for _ in range(m)]
        for i, x in enumerate(students):
            for j, y in enumerate(mentors):
                g[i][j] = sum(a == b for a, b in zip(x, y))
        dfs(0, 0)
        return ans
```

#### Java

```java
class Solution {
    private int m;
    private int ans;
    private int[][] g;
    private boolean[] vis;

    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        m = students.length;
        g = new int[m][m];
        vis = new boolean[m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < students[i].length; ++k) {
                    if (students[i][k] == mentors[j][k]) {
                        ++g[i][j];
                    }
                }
            }
        }
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int s) {
        if (i >= m) {
            ans = Math.max(ans, s);
            return;
        }
        for (int j = 0; j < m; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, s + g[i][j]);
                vis[j] = false;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> g(m, vector<int>(m));
        vector<bool> vis(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[i][j] += students[i][k] == mentors[j][k];
                }
            }
        }
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i, int s) {
            if (i >= m) {
                ans = max(ans, s);
                return;
            }
            for (int j = 0; j < m; ++j) {
                if (!vis[j]) {
                    vis[j] = true;
                    dfs(i + 1, s + g[i][j]);
                    vis[j] = false;
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
};
```

#### Go

```go
func maxCompatibilitySum(students [][]int, mentors [][]int) (ans int) {
	m, n := len(students), len(students[0])
	g := make([][]int, m)
	vis := make([]bool, m)
	for i, x := range students {
		g[i] = make([]int, m)
		for j, y := range mentors {
			for k := 0; k < n; k++ {
				if x[k] == y[k] {
					g[i][j]++
				}
			}
		}
	}
	var dfs func(int, int)
	dfs = func(i, s int) {
		if i == m {
			ans = max(ans, s)
			return
		}
		for j := 0; j < m; j++ {
			if !vis[j] {
				vis[j] = true
				dfs(i+1, s+g[i][j])
				vis[j] = false
			}
		}
	}
	dfs(0, 0)
	return
}
```

#### TypeScript

```ts
function maxCompatibilitySum(students: number[][], mentors: number[][]): number {
    let ans = 0;
    const m = students.length;
    const vis: boolean[] = Array(m).fill(false);
    const g: number[][] = Array.from({ length: m }, () => Array(m).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < m; ++j) {
            for (let k = 0; k < students[i].length; ++k) {
                if (students[i][k] === mentors[j][k]) {
                    g[i][j]++;
                }
            }
        }
    }
    const dfs = (i: number, s: number): void => {
        if (i >= m) {
            ans = Math.max(ans, s);
            return;
        }
        for (let j = 0; j < m; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, s + g[i][j]);
                vis[j] = false;
            }
        }
    };
    dfs(0, 0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_compatibility_sum(students: Vec<Vec<i32>>, mentors: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let m = students.len();
        let mut vis = vec![false; m];
        let mut g = vec![vec![0; m]; m];

        for i in 0..m {
            for j in 0..m {
                for k in 0..students[i].len() {
                    if students[i][k] == mentors[j][k] {
                        g[i][j] += 1;
                    }
                }
            }
        }

        fn dfs(i: usize, s: i32, m: usize, g: &Vec<Vec<i32>>, vis: &mut Vec<bool>, ans: &mut i32) {
            if i >= m {
                *ans = (*ans).max(s);
                return;
            }
            for j in 0..m {
                if !vis[j] {
                    vis[j] = true;
                    dfs(i + 1, s + g[i][j], m, g, vis, ans);
                    vis[j] = false;
                }
            }
        }

        dfs(0, 0, m, &g, &mut vis, &mut ans);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} students
 * @param {number[][]} mentors
 * @return {number}
 */
var maxCompatibilitySum = function (students, mentors) {
    let ans = 0;
    const m = students.length;
    const vis = Array(m).fill(false);
    const g = Array.from({ length: m }, () => Array(m).fill(0));

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < m; ++j) {
            for (let k = 0; k < students[i].length; ++k) {
                if (students[i][k] === mentors[j][k]) {
                    g[i][j]++;
                }
            }
        }
    }

    const dfs = function (i, s) {
        if (i >= m) {
            ans = Math.max(ans, s);
            return;
        }
        for (let j = 0; j < m; ++j) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, s + g[i][j]);
                vis[j] = false;
            }
        }
    };

    dfs(0, 0);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1948. 删除系统中的重复文件夹](https://leetcode.cn/problems/delete-duplicate-folders-in-system){#1948}

{{< tabs "1948" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: Dict[str, "Trie"] = defaultdict(Trie)
        self.deleted: bool = False


class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Trie()
        for path in paths:
            cur = root
            for name in path:
                if cur.children[name] is None:
                    cur.children[name] = Trie()
                cur = cur.children[name]

        g: Dict[str, Trie] = {}

        def dfs(node: Trie) -> str:
            if not node.children:
                return ""
            subs: List[str] = []
            for name, child in node.children.items():
                subs.append(f"{name}({dfs(child)})")
            s = "".join(sorted(subs))
            if s in g:
                node.deleted = g[s].deleted = True
            else:
                g[s] = node
            return s

        def dfs2(node: Trie) -> None:
            if node.deleted:
                return
            if path:
                ans.append(path[:])
            for name, child in node.children.items():
                path.append(name)
                dfs2(child)
                path.pop()

        dfs(root)
        ans: List[List[str]] = []
        path: List[str] = []
        dfs2(root)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Map<String, Trie> children;
    boolean deleted;

    public Trie() {
        children = new HashMap<>();
        deleted = false;
    }
}

class Solution {
    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Trie root = new Trie();
        for (List<String> path : paths) {
            Trie cur = root;
            for (String name : path) {
                if (!cur.children.containsKey(name)) {
                    cur.children.put(name, new Trie());
                }
                cur = cur.children.get(name);
            }
        }

        Map<String, Trie> g = new HashMap<>();

        var dfs = new Function<Trie, String>() {
            @Override
            public String apply(Trie node) {
                if (node.children.isEmpty()) {
                    return "";
                }
                List<String> subs = new ArrayList<>();
                for (var entry : node.children.entrySet()) {
                    subs.add(entry.getKey() + "(" + apply(entry.getValue()) + ")");
                }
                Collections.sort(subs);
                String s = String.join("", subs);
                if (g.containsKey(s)) {
                    node.deleted = true;
                    g.get(s).deleted = true;
                } else {
                    g.put(s, node);
                }
                return s;
            }
        };

        dfs.apply(root);

        List<List<String>> ans = new ArrayList<>();
        List<String> path = new ArrayList<>();

        var dfs2 = new Function<Trie, Void>() {
            @Override
            public Void apply(Trie node) {
                if (node.deleted) {
                    return null;
                }
                if (!path.isEmpty()) {
                    ans.add(new ArrayList<>(path));
                }
                for (Map.Entry<String, Trie> entry : node.children.entrySet()) {
                    path.add(entry.getKey());
                    apply(entry.getValue());
                    path.remove(path.size() - 1);
                }
                return null;
            }
        };

        dfs2.apply(root);

        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    unordered_map<string, Trie*> children;
    bool deleted = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root = new Trie();

        for (auto& path : paths) {
            Trie* cur = root;
            for (auto& name : path) {
                if (cur->children.find(name) == cur->children.end()) {
                    cur->children[name] = new Trie();
                }
                cur = cur->children[name];
            }
        }

        unordered_map<string, Trie*> g;

        auto dfs = [&](this auto&& dfs, Trie* node) -> string {
            if (node->children.empty()) return "";

            vector<string> subs;
            for (auto& child : node->children) {
                subs.push_back(child.first + "(" + dfs(child.second) + ")");
            }
            sort(subs.begin(), subs.end());
            string s = "";
            for (auto& sub : subs) s += sub;

            if (g.contains(s)) {
                node->deleted = true;
                g[s]->deleted = true;
            } else {
                g[s] = node;
            }
            return s;
        };

        dfs(root);

        vector<vector<string>> ans;
        vector<string> path;

        auto dfs2 = [&](this auto&& dfs2, Trie* node) -> void {
            if (node->deleted) return;
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (auto& child : node->children) {
                path.push_back(child.first);
                dfs2(child.second);
                path.pop_back();
            }
        };

        dfs2(root);

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children map[string]*Trie
	deleted  bool
}

func NewTrie() *Trie {
	return &Trie{
		children: make(map[string]*Trie),
	}
}

func deleteDuplicateFolder(paths [][]string) (ans [][]string) {
	root := NewTrie()
	for _, path := range paths {
		cur := root
		for _, name := range path {
			if _, exists := cur.children[name]; !exists {
				cur.children[name] = NewTrie()
			}
			cur = cur.children[name]
		}
	}

	g := make(map[string]*Trie)

	var dfs func(*Trie) string
	dfs = func(node *Trie) string {
		if len(node.children) == 0 {
			return ""
		}
		var subs []string
		for name, child := range node.children {
			subs = append(subs, name+"("+dfs(child)+")")
		}
		sort.Strings(subs)
		s := strings.Join(subs, "")
		if existingNode, exists := g[s]; exists {
			node.deleted = true
			existingNode.deleted = true
		} else {
			g[s] = node
		}
		return s
	}

	var dfs2 func(*Trie, []string)
	dfs2 = func(node *Trie, path []string) {
		if node.deleted {
			return
		}
		if len(path) > 0 {
			ans = append(ans, append([]string{}, path...))
		}
		for name, child := range node.children {
			dfs2(child, append(path, name))
		}
	}

	dfs(root)
	dfs2(root, []string{})
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function deleteDuplicateFolder(paths: string[][]): string[][] {
    class Trie {
        children: { [key: string]: Trie } = {};
        deleted: boolean = false;
    }

    const root = new Trie();

    for (const path of paths) {
        let cur = root;
        for (const name of path) {
            if (!cur.children[name]) {
                cur.children[name] = new Trie();
            }
            cur = cur.children[name];
        }
    }

    const g: { [key: string]: Trie } = {};

    const dfs = (node: Trie): string => {
        if (Object.keys(node.children).length === 0) return '';

        const subs: string[] = [];
        for (const [name, child] of Object.entries(node.children)) {
            subs.push(`${name}(${dfs(child)})`);
        }
        subs.sort();
        const s = subs.join('');

        if (g[s]) {
            node.deleted = true;
            g[s].deleted = true;
        } else {
            g[s] = node;
        }
        return s;
    };

    dfs(root);

    const ans: string[][] = [];
    const path: string[] = [];

    const dfs2 = (node: Trie): void => {
        if (node.deleted) return;
        if (path.length > 0) {
            ans.push([...path]);
        }
        for (const [name, child] of Object.entries(node.children)) {
            path.push(name);
            dfs2(child);
            path.pop();
        }
    };

    dfs2(root);

    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>由于一个漏洞，文件系统中存在许多重复文件夹。给你一个二维数组 <code>paths</code>，其中 <code>paths[i]</code> 是一个表示文件系统中第 <code>i</code> 个文件夹的绝对路径的数组。</p>

<ul>
	<li>例如，<code>["one", "two", "three"]</code> 表示路径 <code>"/one/two/three"</code> 。</li>
</ul>

<p>如果两个文件夹（不需要在同一层级）包含 <strong>非空且</strong><b>相同的&nbsp;</b>子文件夹&nbsp;<strong>集合</strong> 并具有相同的子文件夹结构，则认为这两个文件夹是相同文件夹。相同文件夹的根层级 <strong>不</strong> 需要相同。如果存在两个（或两个以上）<strong>相同</strong> 文件夹，则需要将这些文件夹和所有它们的子文件夹 <strong>标记</strong> 为待删除。</p>

<ul>
	<li>例如，下面文件结构中的文件夹 <code>"/a"</code> 和 <code>"/b"</code> 相同。它们（以及它们的子文件夹）应该被 <strong>全部</strong> 标记为待删除：

    <ul>
    	<li><code>/a</code></li>
    	<li><code>/a/x</code></li>
    	<li><code>/a/x/y</code></li>
    	<li><code>/a/z</code></li>
    	<li><code>/b</code></li>
    	<li><code>/b/x</code></li>
    	<li><code>/b/x/y</code></li>
    	<li><code>/b/z</code></li>
    </ul>
    </li>
    <li>然而，如果文件结构中还包含路径 <code>"/b/w"</code> ，那么文件夹 <code>"/a"</code> 和 <code>"/b"</code> 就不相同。注意，即便添加了新的文件夹 <code>"/b/w"</code> ，仍然认为 <code>"/a/x"</code> 和 <code>"/b/x"</code> 相同。</li>

</ul>

<p>一旦所有的相同文件夹和它们的子文件夹都被标记为待删除，文件系统将会 <strong>删除</strong> 所有上述文件夹。文件系统只会执行一次删除操作。执行完这一次删除操作后，不会删除新出现的相同文件夹。</p>

<p>返回二维数组<em> </em><code>ans</code> ，该数组包含删除所有标记文件夹之后剩余文件夹的路径。路径可以按 <strong>任意顺序</strong> 返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1948.Delete%20Duplicate%20Folders%20in%20System/images/lc-dupfolder1.jpg" style="width: 200px; height: 218px;" />
<pre>
<strong>输入：</strong>paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
<strong>输出：</strong>[["d"],["d","a"]]
<strong>解释：</strong>文件结构如上所示。
文件夹 "/a" 和 "/c"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含名为 "b" 的空文件夹。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1948.Delete%20Duplicate%20Folders%20in%20System/images/lc-dupfolder2.jpg" style="width: 200px; height: 355px;" />
<pre>
<strong>输入：</strong>paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
<strong>输出：</strong>[["c"],["c","b"],["a"],["a","b"]]
<strong>解释：</strong>文件结构如上所示。
文件夹 "/a/b/x" 和 "/w"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含名为 "y" 的空文件夹。
注意，文件夹 "/a" 和 "/c" 在删除后变为相同文件夹，但这两个文件夹不会被删除，因为删除只会进行一次，且它们没有在删除前被标记。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1948.Delete%20Duplicate%20Folders%20in%20System/images/lc-dupfolder3.jpg" style="width: 200px; height: 201px;" />
<pre>
<strong>输入：</strong>paths = [["a","b"],["c","d"],["c"],["a"]]
<strong>输出：</strong>[["c"],["c","d"],["a"],["a","b"]]
<strong>解释：</strong>文件系统中所有文件夹互不相同。
注意，返回的数组可以按不同顺序返回文件夹路径，因为题目对顺序没有要求。
</pre>

<p><strong>示例 4：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1948.Delete%20Duplicate%20Folders%20in%20System/images/lc-dupfolder4_.jpg" style="width: 300px; height: 290px;" />
<pre>
<strong>输入：</strong>paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"]]
<strong>输出：</strong>[]
<strong>解释：</strong>文件结构如上所示。
文件夹 "/a/x" 和 "/b/x"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含名为 "y" 的空文件夹。
文件夹 "/a" 和 "/b"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含一个名为 "z" 的空文件夹以及上面提到的文件夹 "x" 。
</pre>

<p><strong>示例 5：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1948.Delete%20Duplicate%20Folders%20in%20System/images/lc-dupfolder5_.jpg" style="width: 300px; height: 282px;" />
<pre>
<strong>输入：</strong>paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"],["b","w"]]
<strong>输出：</strong>[["b"],["b","w"],["b","z"],["a"],["a","z"]]
<strong>解释：</strong>本例与上例的结构基本相同，除了新增 "/b/w" 文件夹。
文件夹 "/a/x" 和 "/b/x" 仍然会被标记，但 "/a" 和 "/b" 不再被标记，因为 "/b" 中有名为 "w" 的空文件夹而 "/a" 没有。
注意，"/a/z" 和 "/b/z" 不会被标记，因为相同子文件夹的集合必须是非空集合，但这两个文件夹都是空的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= paths.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= paths[i].length &lt;= 500</code></li>
	<li><code>1 &lt;= paths[i][j].length &lt;= 10</code></li>
	<li><code>1 &lt;= sum(paths[i][j].length) &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>path[i][j]</code> 由小写英文字母组成</li>
	<li>不会存在两个路径都指向同一个文件夹的情况</li>
	<li>对于不在根层级的任意文件夹，其父文件夹也会包含在输入中</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树 + DFS

我们可以使用字典树来存储文件夹的结构，字典树的每个节点数据如下：

-   `children`：一个字典，键为子文件夹的名称，值为对应的子节点。
-   `deleted`：一个布尔值，表示该节点是否被标记为待删除。

我们将所有路径插入到字典树中，然后使用 DFS 遍历字典树，构建每个子树的字符串表示。对于每个子树，如果它的字符串表示已经存在于一个全局字典中，则将该节点和全局字典中的对应节点都标记为待删除。最后，再次使用 DFS 遍历字典树，将未被标记的节点的路径添加到结果列表中。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: Dict[str, "Trie"] = defaultdict(Trie)
        self.deleted: bool = False


class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Trie()
        for path in paths:
            cur = root
            for name in path:
                if cur.children[name] is None:
                    cur.children[name] = Trie()
                cur = cur.children[name]

        g: Dict[str, Trie] = {}

        def dfs(node: Trie) -> str:
            if not node.children:
                return ""
            subs: List[str] = []
            for name, child in node.children.items():
                subs.append(f"{name}({dfs(child)})")
            s = "".join(sorted(subs))
            if s in g:
                node.deleted = g[s].deleted = True
            else:
                g[s] = node
            return s

        def dfs2(node: Trie) -> None:
            if node.deleted:
                return
            if path:
                ans.append(path[:])
            for name, child in node.children.items():
                path.append(name)
                dfs2(child)
                path.pop()

        dfs(root)
        ans: List[List[str]] = []
        path: List[str] = []
        dfs2(root)
        return ans
```

#### Java

```java
class Trie {
    Map<String, Trie> children;
    boolean deleted;

    public Trie() {
        children = new HashMap<>();
        deleted = false;
    }
}

class Solution {
    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Trie root = new Trie();
        for (List<String> path : paths) {
            Trie cur = root;
            for (String name : path) {
                if (!cur.children.containsKey(name)) {
                    cur.children.put(name, new Trie());
                }
                cur = cur.children.get(name);
            }
        }

        Map<String, Trie> g = new HashMap<>();

        var dfs = new Function<Trie, String>() {
            @Override
            public String apply(Trie node) {
                if (node.children.isEmpty()) {
                    return "";
                }
                List<String> subs = new ArrayList<>();
                for (var entry : node.children.entrySet()) {
                    subs.add(entry.getKey() + "(" + apply(entry.getValue()) + ")");
                }
                Collections.sort(subs);
                String s = String.join("", subs);
                if (g.containsKey(s)) {
                    node.deleted = true;
                    g.get(s).deleted = true;
                } else {
                    g.put(s, node);
                }
                return s;
            }
        };

        dfs.apply(root);

        List<List<String>> ans = new ArrayList<>();
        List<String> path = new ArrayList<>();

        var dfs2 = new Function<Trie, Void>() {
            @Override
            public Void apply(Trie node) {
                if (node.deleted) {
                    return null;
                }
                if (!path.isEmpty()) {
                    ans.add(new ArrayList<>(path));
                }
                for (Map.Entry<String, Trie> entry : node.children.entrySet()) {
                    path.add(entry.getKey());
                    apply(entry.getValue());
                    path.remove(path.size() - 1);
                }
                return null;
            }
        };

        dfs2.apply(root);

        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    unordered_map<string, Trie*> children;
    bool deleted = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root = new Trie();

        for (auto& path : paths) {
            Trie* cur = root;
            for (auto& name : path) {
                if (cur->children.find(name) == cur->children.end()) {
                    cur->children[name] = new Trie();
                }
                cur = cur->children[name];
            }
        }

        unordered_map<string, Trie*> g;

        auto dfs = [&](this auto&& dfs, Trie* node) -> string {
            if (node->children.empty()) return "";

            vector<string> subs;
            for (auto& child : node->children) {
                subs.push_back(child.first + "(" + dfs(child.second) + ")");
            }
            sort(subs.begin(), subs.end());
            string s = "";
            for (auto& sub : subs) s += sub;

            if (g.contains(s)) {
                node->deleted = true;
                g[s]->deleted = true;
            } else {
                g[s] = node;
            }
            return s;
        };

        dfs(root);

        vector<vector<string>> ans;
        vector<string> path;

        auto dfs2 = [&](this auto&& dfs2, Trie* node) -> void {
            if (node->deleted) return;
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (auto& child : node->children) {
                path.push_back(child.first);
                dfs2(child.second);
                path.pop_back();
            }
        };

        dfs2(root);

        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children map[string]*Trie
	deleted  bool
}

func NewTrie() *Trie {
	return &Trie{
		children: make(map[string]*Trie),
	}
}

func deleteDuplicateFolder(paths [][]string) (ans [][]string) {
	root := NewTrie()
	for _, path := range paths {
		cur := root
		for _, name := range path {
			if _, exists := cur.children[name]; !exists {
				cur.children[name] = NewTrie()
			}
			cur = cur.children[name]
		}
	}

	g := make(map[string]*Trie)

	var dfs func(*Trie) string
	dfs = func(node *Trie) string {
		if len(node.children) == 0 {
			return ""
		}
		var subs []string
		for name, child := range node.children {
			subs = append(subs, name+"("+dfs(child)+")")
		}
		sort.Strings(subs)
		s := strings.Join(subs, "")
		if existingNode, exists := g[s]; exists {
			node.deleted = true
			existingNode.deleted = true
		} else {
			g[s] = node
		}
		return s
	}

	var dfs2 func(*Trie, []string)
	dfs2 = func(node *Trie, path []string) {
		if node.deleted {
			return
		}
		if len(path) > 0 {
			ans = append(ans, append([]string{}, path...))
		}
		for name, child := range node.children {
			dfs2(child, append(path, name))
		}
	}

	dfs(root)
	dfs2(root, []string{})
	return ans
}
```

#### TypeScript

```ts
function deleteDuplicateFolder(paths: string[][]): string[][] {
    class Trie {
        children: { [key: string]: Trie } = {};
        deleted: boolean = false;
    }

    const root = new Trie();

    for (const path of paths) {
        let cur = root;
        for (const name of path) {
            if (!cur.children[name]) {
                cur.children[name] = new Trie();
            }
            cur = cur.children[name];
        }
    }

    const g: { [key: string]: Trie } = {};

    const dfs = (node: Trie): string => {
        if (Object.keys(node.children).length === 0) return '';

        const subs: string[] = [];
        for (const [name, child] of Object.entries(node.children)) {
            subs.push(`${name}(${dfs(child)})`);
        }
        subs.sort();
        const s = subs.join('');

        if (g[s]) {
            node.deleted = true;
            g[s].deleted = true;
        } else {
            g[s] = node;
        }
        return s;
    };

    dfs(root);

    const ans: string[][] = [];
    const path: string[] = [];

    const dfs2 = (node: Trie): void => {
        if (node.deleted) return;
        if (path.length > 0) {
            ans.push([...path]);
        }
        for (const [name, child] of Object.entries(node.children)) {
            path.push(name);
            dfs2(child);
            path.pop();
        }
    };

    dfs2(root);

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1949. 坚定的友谊 🔒](https://leetcode.cn/problems/strong-friendship){#1949}

{{< tabs "1949" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            *
        FROM Friendship
        UNION ALL
        SELECT
            user2_id,
            user1_id
        FROM Friendship
    )
SELECT
    t1.user1_id,
    t1.user2_id,
    COUNT(1) AS common_friend
FROM
    t AS t1
    JOIN t AS t2 ON t1.user2_id = t2.user1_id
    JOIN t AS t3 ON t1.user1_id = t3.user1_id
WHERE t3.user2_id = t2.user2_id AND t1.user1_id < t1.user2_id
GROUP BY t1.user1_id, t1.user2_id
HAVING COUNT(1) >= 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表名: <code>Friendship</code></p>

<pre>
+-------------+------+
| 列名         | 类型 |
+-------------+------+
| user1_id    | int  |
| user2_id    | int  |
+-------------+------+
(user1_id, user2_id) 是这个表的主键（具有唯一值的列的组合）。
这张表的每一行都表示用户 user1_id 和 user2_id 是朋友。
请注意，user1_id &lt; user2_id。
</pre>

<p>&nbsp;</p>

<p>如果 <code>x</code>&nbsp; 和&nbsp;<code>y</code>&nbsp;为&nbsp;<strong>朋友&nbsp;</strong>且他们&nbsp;<strong>至少&nbsp;</strong>有三个共同的朋友 ，那么&nbsp;<code>x</code> 和&nbsp;<code>y</code> 之间的友谊就是&nbsp;<strong>坚定的</strong>。</p>

<p>写一个解决方案来找到所有的&nbsp;<strong>坚定的友谊</strong>。</p>

<p>注意，结果表不应该包含重复的行，并且 <code>user1_id &lt; user2_id</code>。</p>

<p>以&nbsp;<strong>任何顺序&nbsp;</strong>返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> 
Friendship table:
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
| 1        | 3        |
| 2        | 3        |
| 1        | 4        |
| 2        | 4        |
| 1        | 5        |
| 2        | 5        |
| 1        | 7        |
| 3        | 7        |
| 1        | 6        |
| 3        | 6        |
| 2        | 6        |
+----------+----------+
<strong>输出:</strong> 
+----------+----------+---------------+
| user1_id | user2_id | common_friend |
+----------+----------+---------------+
| 1        | 2        | 4             |
| 1        | 3        | 3             |
+----------+----------+---------------+
<strong>解释:</strong> 
用户 1 和 2 有 4 个共同的朋友（3，4，5，和 6）。
用户 1 和 3 有 3 个共同的朋友（2，6，和 7）。
但这里不包括用户 2 和 3 的友谊，因为他们只有两个共同的朋友（1 和 6）。
</pre>

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
    t AS (
        SELECT
            *
        FROM Friendship
        UNION ALL
        SELECT
            user2_id,
            user1_id
        FROM Friendship
    )
SELECT
    t1.user1_id,
    t1.user2_id,
    COUNT(1) AS common_friend
FROM
    t AS t1
    JOIN t AS t2 ON t1.user2_id = t2.user1_id
    JOIN t AS t3 ON t1.user1_id = t3.user1_id
WHERE t3.user2_id = t2.user2_id AND t1.user1_id < t1.user2_id
GROUP BY t1.user1_id, t1.user2_id
HAVING COUNT(1) >= 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
