---
title: "1100_长度为 K 的无重复字符子串 🔒"
date: 2025-10-08T18:36:57+08:00
weight: 1
tags: [二分查找, 二叉树, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 树, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 递归]
---

{{< markmap >}}
### [1100_长度为 K 的无重复字符子串 🔒](#1100)
#### [哈希表](#1100)
#### [字符串](#1100)
#### [滑动窗口](#1100)
### [1101_彼此熟识的最早时间 🔒](#1101)
#### [并查集](#1101)
#### [数组](#1101)
#### [排序](#1101)
### [1102_得分最高的路径 🔒](#1102)
#### [深度优先搜索](#1102)
#### [广度优先搜索](#1102)
#### [并查集](#1102)
#### [数组](#1102)
#### [二分查找](#1102)
#### [矩阵](#1102)
#### [堆（优先队列）](#1102)
### [1103_分糖果 II](#1103)
#### [数学](#1103)
#### [模拟](#1103)
### [1104_二叉树寻路](#1104)
#### [树](#1104)
#### [数学](#1104)
#### [二叉树](#1104)
### [1105_填充书架](#1105)
#### [数组](#1105)
#### [动态规划](#1105)
### [1106_解析布尔表达式](#1106)
#### [栈](#1106)
#### [递归](#1106)
#### [字符串](#1106)
### [1107_每日新用户统计 🔒](#1107)
#### [数据库](#1107)
### [1108_IP 地址无效化](#1108)
#### [字符串](#1108)
### [1109_航班预订统计](#1109)
#### [数组](#1109)
#### [前缀和](#1109)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1100_长度为 K 的无重复字符子串 🔒
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 1101_彼此熟识的最早时间 🔒
___
#### 并查集
___
#### 数组
___
#### 排序
---
### 1102_得分最高的路径 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 堆（优先队列）
---
### 1103_分糖果 II
___
#### 数学
___
#### 模拟
---
### 1104_二叉树寻路
___
#### 树
___
#### 数学
___
#### 二叉树
---
### 1105_填充书架
___
#### 数组
___
#### 动态规划
---
### 1106_解析布尔表达式
___
#### 栈
___
#### 递归
___
#### 字符串
---
### 1107_每日新用户统计 🔒
___
#### 数据库
---
### 1108_IP 地址无效化
___
#### 字符串
---
### 1109_航班预订统计
___
#### 数组
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 动态规划 | 哈希表 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 栈 | 树 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 矩阵 | 递归 |  |

# [1100. 长度为 K 的无重复字符子串 🔒](https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters){#1100}

{{< tabs "1100" >}}

{{% tab "python" %}}
```python
class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        cnt = Counter(s[:k])
        ans = int(len(cnt) == k)
        for i in range(k, len(s)):
            cnt[s[i]] += 1
            cnt[s[i - k]] -= 1
            if cnt[s[i - k]] == 0:
                cnt.pop(s[i - k])
            ans += int(len(cnt) == k)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numKLenSubstrNoRepeats(String s, int k) {
        int n = s.length();
        if (n < k) {
            return 0;
        }
        Map<Character, Integer> cnt = new HashMap<>(k);
        for (int i = 0; i < k; ++i) {
            cnt.merge(s.charAt(i), 1, Integer::sum);
        }
        int ans = cnt.size() == k ? 1 : 0;
        for (int i = k; i < n; ++i) {
            cnt.merge(s.charAt(i), 1, Integer::sum);
            if (cnt.merge(s.charAt(i - k), -1, Integer::sum) == 0) {
                cnt.remove(s.charAt(i - k));
            }
            ans += cnt.size() == k ? 1 : 0;
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
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if (n < k) {
            return 0;
        }
        unordered_map<char, int> cnt;
        for (int i = 0; i < k; ++i) {
            ++cnt[s[i]];
        }
        int ans = cnt.size() == k;
        for (int i = k; i < n; ++i) {
            ++cnt[s[i]];
            if (--cnt[s[i - k]] == 0) {
                cnt.erase(s[i - k]);
            }
            ans += cnt.size() == k;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numKLenSubstrNoRepeats(s string, k int) (ans int) {
	n := len(s)
	if n < k {
		return
	}
	cnt := map[byte]int{}
	for i := 0; i < k; i++ {
		cnt[s[i]]++
	}
	if len(cnt) == k {
		ans++
	}
	for i := k; i < n; i++ {
		cnt[s[i]]++
		cnt[s[i-k]]--
		if cnt[s[i-k]] == 0 {
			delete(cnt, s[i-k])
		}
		if len(cnt) == k {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numKLenSubstrNoRepeats(s: string, k: number): number {
    const n = s.length;
    if (n < k) {
        return 0;
    }
    const cnt: Map<string, number> = new Map();
    for (let i = 0; i < k; ++i) {
        cnt.set(s[i], (cnt.get(s[i]) ?? 0) + 1);
    }
    let ans = cnt.size === k ? 1 : 0;
    for (let i = k; i < n; ++i) {
        cnt.set(s[i], (cnt.get(s[i]) ?? 0) + 1);
        cnt.set(s[i - k], (cnt.get(s[i - k]) ?? 0) - 1);
        if (cnt.get(s[i - k]) === 0) {
            cnt.delete(s[i - k]);
        }
        ans += cnt.size === k ? 1 : 0;
    }
    return ans;
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
    function numKLenSubstrNoRepeats($s, $k) {
        $n = strlen($s);
        if ($n < $k) {
            return 0;
        }
        $cnt = [];
        for ($i = 0; $i < $k; ++$i) {
            if (!isset($cnt[$s[$i]])) {
                $cnt[$s[$i]] = 1;
            } else {
                $cnt[$s[$i]]++;
            }
        }
        $ans = count($cnt) == $k ? 1 : 0;
        for ($i = $k; $i < $n; ++$i) {
            if (!isset($cnt[$s[$i]])) {
                $cnt[$s[$i]] = 1;
            } else {
                $cnt[$s[$i]]++;
            }
            if ($cnt[$s[$i - $k]] - 1 == 0) {
                unset($cnt[$s[$i - $k]]);
            } else {
                $cnt[$s[$i - $k]]--;
            }
            $ans += count($cnt) == $k ? 1 : 0;
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>S</code>，找出所有长度为&nbsp;<code>K</code>&nbsp;且不含重复字符的子串，请你返回全部满足要求的子串的&nbsp;<strong>数目</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>S = &quot;havefunonleetcode&quot;, K = 5
<strong>输出：</strong>6
<strong>解释：</strong>
这里有 6 个满足题意的子串，分别是：&#39;havef&#39;,&#39;avefu&#39;,&#39;vefun&#39;,&#39;efuno&#39;,&#39;etcod&#39;,&#39;tcode&#39;。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>S = &quot;home&quot;, K = 5
<strong>输出：</strong>0
<strong>解释：</strong>
注意：K 可能会大于 S 的长度。在这种情况下，就无法找到任何长度为 K 的子串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= S.length &lt;= 10^4</code></li>
	<li><code>S</code> 中的所有字符均为小写英文字母</li>
	<li><code>1 &lt;= K &lt;= 10^4</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 哈希表

我们维护一个长度为 $k$ 的滑动窗口，用一个哈希表 $cnt$ 统计窗口中每个字符的出现次数。

首先，我们将字符串 $s$ 的前 $k$ 个字符加入哈希表 $cnt$ 中，并判断 $cnt$ 的大小是否等于 $k$，如果等于 $k$，则说明窗口中的字符都不相同，答案 $ans$ 加一。

接下来，我们从 $k$ 开始遍历字符串 $s$，每次将 $s[i]$ 加入哈希表 $cnt$ 中，同时将 $s[i-k]$ 从哈希表 $cnt$ 中减一，如果 $cnt[s[i-k]]$ 减一后等于 $0$，则将 $s[i-k]$ 从哈希表 $cnt$ 中删除。如果此时哈希表 $cnt$ 的大小等于 $k$，则说明窗口中的字符都不相同，答案 $ans$ 加一。

最后，返回答案 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(\min(k, |\Sigma|))$，其中 $n$ 为字符串 $s$ 的长度；而 $\Sigma$ 为字符集，本题中字符集为小写英文字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        cnt = Counter(s[:k])
        ans = int(len(cnt) == k)
        for i in range(k, len(s)):
            cnt[s[i]] += 1
            cnt[s[i - k]] -= 1
            if cnt[s[i - k]] == 0:
                cnt.pop(s[i - k])
            ans += int(len(cnt) == k)
        return ans
```

#### Java

```java
class Solution {
    public int numKLenSubstrNoRepeats(String s, int k) {
        int n = s.length();
        if (n < k) {
            return 0;
        }
        Map<Character, Integer> cnt = new HashMap<>(k);
        for (int i = 0; i < k; ++i) {
            cnt.merge(s.charAt(i), 1, Integer::sum);
        }
        int ans = cnt.size() == k ? 1 : 0;
        for (int i = k; i < n; ++i) {
            cnt.merge(s.charAt(i), 1, Integer::sum);
            if (cnt.merge(s.charAt(i - k), -1, Integer::sum) == 0) {
                cnt.remove(s.charAt(i - k));
            }
            ans += cnt.size() == k ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if (n < k) {
            return 0;
        }
        unordered_map<char, int> cnt;
        for (int i = 0; i < k; ++i) {
            ++cnt[s[i]];
        }
        int ans = cnt.size() == k;
        for (int i = k; i < n; ++i) {
            ++cnt[s[i]];
            if (--cnt[s[i - k]] == 0) {
                cnt.erase(s[i - k]);
            }
            ans += cnt.size() == k;
        }
        return ans;
    }
};
```

#### Go

```go
func numKLenSubstrNoRepeats(s string, k int) (ans int) {
	n := len(s)
	if n < k {
		return
	}
	cnt := map[byte]int{}
	for i := 0; i < k; i++ {
		cnt[s[i]]++
	}
	if len(cnt) == k {
		ans++
	}
	for i := k; i < n; i++ {
		cnt[s[i]]++
		cnt[s[i-k]]--
		if cnt[s[i-k]] == 0 {
			delete(cnt, s[i-k])
		}
		if len(cnt) == k {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numKLenSubstrNoRepeats(s: string, k: number): number {
    const n = s.length;
    if (n < k) {
        return 0;
    }
    const cnt: Map<string, number> = new Map();
    for (let i = 0; i < k; ++i) {
        cnt.set(s[i], (cnt.get(s[i]) ?? 0) + 1);
    }
    let ans = cnt.size === k ? 1 : 0;
    for (let i = k; i < n; ++i) {
        cnt.set(s[i], (cnt.get(s[i]) ?? 0) + 1);
        cnt.set(s[i - k], (cnt.get(s[i - k]) ?? 0) - 1);
        if (cnt.get(s[i - k]) === 0) {
            cnt.delete(s[i - k]);
        }
        ans += cnt.size === k ? 1 : 0;
    }
    return ans;
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
    function numKLenSubstrNoRepeats($s, $k) {
        $n = strlen($s);
        if ($n < $k) {
            return 0;
        }
        $cnt = [];
        for ($i = 0; $i < $k; ++$i) {
            if (!isset($cnt[$s[$i]])) {
                $cnt[$s[$i]] = 1;
            } else {
                $cnt[$s[$i]]++;
            }
        }
        $ans = count($cnt) == $k ? 1 : 0;
        for ($i = $k; $i < $n; ++$i) {
            if (!isset($cnt[$s[$i]])) {
                $cnt[$s[$i]] = 1;
            } else {
                $cnt[$s[$i]]++;
            }
            if ($cnt[$s[$i - $k]] - 1 == 0) {
                unset($cnt[$s[$i - $k]]);
            } else {
                $cnt[$s[$i - $k]]--;
            }
            $ans += count($cnt) == $k ? 1 : 0;
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1101. 彼此熟识的最早时间 🔒](https://leetcode.cn/problems/the-earliest-moment-when-everyone-become-friends){#1101}

{{< tabs "1101" >}}

{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = ('p', 'size')

    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        uf = UnionFind(n)
        for t, x, y in sorted(logs):
            if uf.union(x, y):
                n -= 1
                if n == 1:
                    return t
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int earliestAcq(int[][] logs, int n) {
        Arrays.sort(logs, (a, b) -> a[0] - b[0]);
        UnionFind uf = new UnionFind(n);
        for (int[] log : logs) {
            int t = log[0], x = log[1], y = log[2];
            if (uf.union(x, y) && --n == 1) {
                return t;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UnionFind uf(n);
        for (auto& log : logs) {
            int t = log[0], x = log[1], y = log[2];
            if (uf.unite(x, y) && --n == 1) {
                return t;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func earliestAcq(logs [][]int, n int) int {
	sort.Slice(logs, func(i, j int) bool { return logs[i][0] < logs[j][0] })
	uf := newUnionFind(n)
	for _, log := range logs {
		t, x, y := log[0], log[1], log[2]
		if uf.union(x, y) {
			n--
			if n == 1 {
				return t
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function earliestAcq(logs: number[][], n: number): number {
    logs.sort((a, b) => a[0] - b[0]);
    const uf = new UnionFind(n);
    for (const [t, x, y] of logs) {
        if (uf.union(x, y) && --n === 1) {
            return t;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) -> bool {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa == pb {
            false
        } else if self.size[pa] > self.size[pb] {
            self.p[pb] = pa;
            self.size[pa] += self.size[pb];
            true
        } else {
            self.p[pa] = pb;
            self.size[pb] += self.size[pa];
            true
        }
    }
}

impl Solution {
    pub fn earliest_acq(logs: Vec<Vec<i32>>, n: i32) -> i32 {
        let mut logs = logs;
        logs.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut uf = UnionFind::new(n as usize);
        let mut n = n;
        for log in logs {
            let t = log[0];
            let x = log[1] as usize;
            let y = log[2] as usize;
            if uf.union(x, y) {
                n -= 1;
                if n == 1 {
                    return t;
                }
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

<p>在一个社交圈子当中，有&nbsp;<code>n</code>&nbsp;个人。每个人都有一个从&nbsp;<code>0</code> 到&nbsp;<code>n - 1</code>&nbsp;的唯一编号。我们有一份日志列表&nbsp;<code>logs</code>，其中&nbsp;<code>logs[i] = [timestamp<sub>i</sub>, x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示 <code>x<sub>i</sub></code>&nbsp;和&nbsp;<code>y<sub>i</sub></code>&nbsp;将在同一时间&nbsp;<code>timestamp<sub>i</sub></code><sub>&nbsp;</sub>成为朋友。</p>

<p>友谊是 <strong>相互</strong> 的。也就是说，如果 <code>a</code> 和 <code>b</code> 是朋友，那么&nbsp;<code>b</code>&nbsp;和 <code>a</code> 也是朋友。同样，如果 <code>a</code> 和 <code>b</code> 是朋友，或者&nbsp;<code>a</code> 是 <code>b</code> 朋友的朋友 ，那么 <code>a</code> 和 <code>b</code>&nbsp;认识。</p>

<p>返回圈子里所有人之间都认识的最早时间。如果找不到最早时间，就返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], N = 6
<strong>输出：</strong>20190301
<strong>解释：</strong>
第一次结交发生在 timestamp = 20190101，0 和 1 成为好友，社交朋友圈如下 [0,1], [2], [3], [4], [5]。
第二次结交发生在 timestamp = 20190104，3 和 4 成为好友，社交朋友圈如下 [0,1], [2], [3,4], [5].
第三次结交发生在 timestamp = 20190107，2 和 3 成为好友，社交朋友圈如下 [0,1], [2,3,4], [5].
第四次结交发生在 timestamp = 20190211，1 和 5 成为好友，社交朋友圈如下 [0,1,5], [2,3,4].
第五次结交发生在 timestamp = 20190224，2 和 4 已经是好友了。
第六次结交发生在 timestamp = 20190301，0 和 3 成为好友，大家都互相熟识了。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
<strong>输出:</strong> 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= logs.length &lt;= 10<sup>4</sup></code></li>
	<li><code>logs[i].length == 3</code></li>
	<li><code>0 &lt;= timestamp<sub>i</sub>&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>x<sub>i</sub>&nbsp;!= y<sub>i</sub></code></li>
	<li><code>timestamp<sub>i</sub></code>&nbsp;中的所有时间戳&nbsp;<strong>均</strong><strong>不同</strong></li>
	<li>所有的对 <code>(xi, yi)</code> 在输入中最多出现一次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 并查集

我们将所有的日志按照时间戳从小到大排序，然后遍历排序后的日志，利用并查集判断当前日志中的两个人是否已经是朋友，如果不是朋友，则将两个人合并成一个朋友圈，直到所有人都在一个朋友圈中，返回当前日志的时间戳。

如果遍历完所有日志，还没有所有人都在一个朋友圈中，则返回 $-1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为日志的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        for t, x, y in sorted(logs):
            if find(x) == find(y):
                continue
            p[find(x)] = find(y)
            n -= 1
            if n == 1:
                return t
        return -1
```

#### Java

```java
class Solution {
    private int[] p;

    public int earliestAcq(int[][] logs, int n) {
        Arrays.sort(logs, (a, b) -> a[0] - b[0]);
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int[] log : logs) {
            int t = log[0], x = log[1], y = log[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            if (--n == 1) {
                return t;
            }
        }
        return -1;
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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        for (auto& log : logs) {
            int x = find(log[1]);
            int y = find(log[2]);
            if (x != y) {
                p[x] = y;
                --n;
            }
            if (n == 1) {
                return log[0];
            }
        }
        return -1;
    }
};
```

#### Go

```go
func earliestAcq(logs [][]int, n int) int {
	sort.Slice(logs, func(i, j int) bool { return logs[i][0] < logs[j][0] })
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, log := range logs {
		t, x, y := log[0], log[1], log[2]
		if find(x) == find(y) {
			continue
		}
		p[find(x)] = find(y)
		n--
		if n == 1 {
			return t
		}
	}
	return -1
}
```

#### TypeScript

```ts
function earliestAcq(logs: number[][], n: number): number {
    const p: number[] = Array(n)
        .fill(0)
        .map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    logs.sort((a, b) => a[0] - b[0]);
    for (const [t, x, y] of logs) {
        const rx = find(x);
        const ry = find(y);
        if (rx !== ry) {
            p[rx] = ry;
            if (--n === 1) {
                return t;
            }
        }
    }
    return -1;
}
```

#### Rust

```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) -> bool {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa == pb {
            false
        } else if self.size[pa] > self.size[pb] {
            self.p[pb] = pa;
            self.size[pa] += self.size[pb];
            true
        } else {
            self.p[pa] = pb;
            self.size[pb] += self.size[pa];
            true
        }
    }
}

impl Solution {
    pub fn earliest_acq(logs: Vec<Vec<i32>>, n: i32) -> i32 {
        let mut logs = logs;
        logs.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut uf = UnionFind::new(n as usize);
        let mut n = n;
        for log in logs {
            let t = log[0];
            let x = log[1] as usize;
            let y = log[2] as usize;
            if uf.union(x, y) {
                n -= 1;
                if n == 1 {
                    return t;
                }
            }
        }
        -1
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
class UnionFind:
    __slots__ = ('p', 'size')

    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        uf = UnionFind(n)
        for t, x, y in sorted(logs):
            if uf.union(x, y):
                n -= 1
                if n == 1:
                    return t
        return -1
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int earliestAcq(int[][] logs, int n) {
        Arrays.sort(logs, (a, b) -> a[0] - b[0]);
        UnionFind uf = new UnionFind(n);
        for (int[] log : logs) {
            int t = log[0], x = log[1], y = log[2];
            if (uf.union(x, y) && --n == 1) {
                return t;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UnionFind uf(n);
        for (auto& log : logs) {
            int t = log[0], x = log[1], y = log[2];
            if (uf.unite(x, y) && --n == 1) {
                return t;
            }
        }
        return -1;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func earliestAcq(logs [][]int, n int) int {
	sort.Slice(logs, func(i, j int) bool { return logs[i][0] < logs[j][0] })
	uf := newUnionFind(n)
	for _, log := range logs {
		t, x, y := log[0], log[1], log[2]
		if uf.union(x, y) {
			n--
			if n == 1 {
				return t
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function earliestAcq(logs: number[][], n: number): number {
    logs.sort((a, b) => a[0] - b[0]);
    const uf = new UnionFind(n);
    for (const [t, x, y] of logs) {
        if (uf.union(x, y) && --n === 1) {
            return t;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1102. 得分最高的路径 🔒](https://leetcode.cn/problems/path-with-maximum-minimum-value){#1102}

{{< tabs "1102" >}}

{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = ("p", "size")

    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        uf = UnionFind(m * n)
        q = [(v, i, j) for i, row in enumerate(grid) for j, v in enumerate(row)]
        q.sort()
        ans = 0
        vis = set()
        dirs = (-1, 0, 1, 0, -1)
        while uf.find(0) != uf.find(m * n - 1):
            v, i, j = q.pop()
            ans = v
            vis.add((i, j))
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (x, y) in vis:
                    uf.union(x * n + y, i * n + j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    public int maximumMinimumPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        UnionFind uf = new UnionFind(m * n);
        List<int[]> q = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.add(new int[] {grid[i][j], i, j});
            }
        }
        q.sort((a, b) -> b[0] - a[0]);
        boolean[][] vis = new boolean[m][n];
        int[] dirs = {-1, 0, 1, 0, -1};
        int ans = 0;
        for (int i = 0; uf.find(0) != uf.find(m * n - 1); ++i) {
            int[] t = q.get(i);
            vis[t[1]][t[2]] = true;
            ans = t[0];
            for (int k = 0; k < 4; ++k) {
                int x = t[1] + dirs[k], y = t[2] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    uf.union(x * n + y, t[1] * n + t[2]);
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
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> q;
        UnionFind uf(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace_back(grid[i][j], i, j);
            }
        }
        sort(q.begin(), q.end(), greater<tuple<int, int, int>>());
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (auto& [v, i, j] : q) {
            vis[i][j] = true;
            ans = v;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    uf.unite(x * n + y, i * n + j);
                }
            }
            if (uf.find(0) == uf.find(m * n - 1)) {
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
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func maximumMinimumPath(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	uf := newUnionFind(m * n)
	vis := make([][]bool, m)
	q := [][3]int{}
	for i, row := range grid {
		vis[i] = make([]bool, n)
		for j, v := range row {
			q = append(q, [3]int{v, i, j})
		}
	}
	sort.Slice(q, func(i, j int) bool { return q[i][0] > q[j][0] })
	dirs := [5]int{-1, 0, 1, 0, -1}
	for _, t := range q {
		v, i, j := t[0], t[1], t[2]
		ans = v
		vis[i][j] = true
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if 0 <= x && x < m && 0 <= y && y < n && vis[x][y] {
				uf.union(x*n+y, i*n+j)
			}
		}
		if uf.find(0) == uf.find(m*n-1) {
			break
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function maximumMinimumPath(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const q: number[][] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            q.push([grid[i][j], i, j]);
        }
    }
    q.sort((a, b) => b[0] - a[0]);
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const vis: boolean[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(false));
    let ans = 0;
    const uf = new UnionFind(m * n);
    for (let k = 0; uf.find(0) !== uf.find(m * n - 1); ++k) {
        const [t, i, j] = q[k];
        ans = t;
        vis[i][j] = true;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                uf.union(i * n + j, x * n + y);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa != pb {
            if self.size[pa] > self.size[pb] {
                self.p[pb] = pa;
                self.size[pa] += self.size[pb];
            } else {
                self.p[pa] = pb;
                self.size[pb] += self.size[pa];
            }
        }
    }
}

impl Solution {
    pub fn maximum_minimum_path(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut uf = UnionFind::new(m * n);
        let mut q: Vec<Vec<i32>> = Vec::new();

        for i in 0..m {
            for j in 0..n {
                q.push(vec![grid[i][j], i as i32, j as i32]);
            }
        }

        q.sort_by(|a, b| b[0].cmp(&a[0]));

        let mut vis: Vec<Vec<bool>> = vec![vec![false; n]; m];
        let dirs: [i32; 5] = [-1, 0, 1, 0, -1];
        let mut ans = 0;
        for k in 0..q.len() {
            if uf.find(0) == uf.find(m * n - 1) {
                break;
            }
            let t = &q[k];
            let (v, i, j) = (t[0], t[1] as usize, t[2] as usize);
            ans = v;
            vis[i][j] = true;
            for d in 0..4 {
                let x = (i as i32) + dirs[d];
                let y = (j as i32) + dirs[d + 1];
                if x >= 0
                    && x < (m as i32)
                    && y >= 0
                    && y < (n as i32)
                    && vis[x as usize][y as usize]
                {
                    uf.union((x as usize) * n + (y as usize), i * n + j);
                }
            }
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

<p>给定一个 <code>m x n</code> 的整数矩阵&nbsp;<code>grid</code>，返回从 <code>(0,0)</code> 开始到 <code>(m - 1, n - 1)</code> 在四个基本方向上移动的路径的最大 <strong>分数</strong> 。</p>

<p>一条路径的 <strong>分数</strong> 是该路径上的最小值。</p>

<ul>
	<li>例如，路径 <code>8 → 4 → 5 → 9</code> 的得分为 <code>4</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1102.Path%20With%20Maximum%20Minimum%20Value/images/maxgrid1.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[5,4,5],[1,2,6],[7,4,6]]
<strong>输出：</strong>4
<strong>解释：</strong>得分最高的路径用黄色突出显示。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1102.Path%20With%20Maximum%20Minimum%20Value/images/maxgrid2.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[2,2,1,2,2,2],[1,2,2,2,1,2]]
<strong>输出：</strong>2</pre>

<p><strong>示例 3：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1102.Path%20With%20Maximum%20Minimum%20Value/images/maxgrid3.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
<strong>输出：</strong>3</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 并查集

我们先将矩阵的每个元素构建一个三元组 $(v, i, j)$，其中 $v$ 表示元素值，而 $i$ 和 $j$ 分别表示元素在矩阵中的行和列。然后对这些三元组按照元素值从大到小进行排序，存放在列表 $q$ 中。

接下来，我们按顺序从 $q$ 中取出三元组，将其对应的元素值作为路径的分数，并且将该位置标记为已访问。然后我们检查该位置的上下左右四个相邻位置，如果某个相邻位置已经被访问过，那么我们就将该位置与当前位置进行合并。如果发现位置 $(0, 0)$ 和位置 $(m - 1, n - 1)$ 已经被合并，那么我们就可以直接返回当前路径的分数，即为答案。

时间复杂度 $O(m \times n \times (\log (m \times n) + \alpha(m \times n)))$，其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        m, n = len(grid), len(grid[0])
        p = list(range(m * n))
        q = [(v, i, j) for i, row in enumerate(grid) for j, v in enumerate(row)]
        q.sort()
        ans = 0
        dirs = (-1, 0, 1, 0, -1)
        vis = set()
        while find(0) != find(m * n - 1):
            v, i, j = q.pop()
            ans = v
            vis.add((i, j))
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (x, y) in vis:
                    p[find(i * n + j)] = find(x * n + y)
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public int maximumMinimumPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        p = new int[m * n];
        List<int[]> q = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.add(new int[] {grid[i][j], i, j});
                p[i * n + j] = i * n + j;
            }
        }
        q.sort((a, b) -> b[0] - a[0]);
        boolean[][] vis = new boolean[m][n];
        int[] dirs = {-1, 0, 1, 0, -1};
        int ans = 0;
        for (int i = 0; find(0) != find(m * n - 1); ++i) {
            int[] t = q.get(i);
            vis[t[1]][t[2]] = true;
            ans = t[0];
            for (int k = 0; k < 4; ++k) {
                int x = t[1] + dirs[k], y = t[2] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    p[find(x * n + y)] = find(t[1] * n + t[2]);
                }
            }
        }
        return ans;
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
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> q;
        vector<int> p(m * n);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace_back(grid[i][j], i, j);
            }
        }
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        sort(q.begin(), q.end(), greater<tuple<int, int, int>>());
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (auto& [v, i, j] : q) {
            vis[i][j] = true;
            ans = v;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    p[find(x * n + y)] = find(i * n + j);
                }
            }
            if (find(0) == find(m * n - 1)) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumMinimumPath(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	p := make([]int, m*n)
	vis := make([][]bool, m)
	q := [][3]int{}
	for i, row := range grid {
		vis[i] = make([]bool, n)
		for j, v := range row {
			p[i*n+j] = i*n + j
			q = append(q, [3]int{v, i, j})
		}
	}
	sort.Slice(q, func(i, j int) bool { return q[i][0] > q[j][0] })
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for _, t := range q {
		v, i, j := t[0], t[1], t[2]
		ans = v
		vis[i][j] = true
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if 0 <= x && x < m && 0 <= y && y < n && vis[x][y] {
				p[find(x*n+y)] = find(i*n + j)
			}
		}
		if find(0) == find(m*n-1) {
			break
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumMinimumPath(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const p: number[] = Array(m * n)
        .fill(0)
        .map((_, i) => i);
    const q: number[][] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            q.push([grid[i][j], i, j]);
        }
    }
    q.sort((a, b) => b[0] - a[0]);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const vis: boolean[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(false));
    let ans = 0;
    for (let k = 0; find(0) !== find(m * n - 1); ++k) {
        const [t, i, j] = q[k];
        ans = t;
        vis[i][j] = true;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                p[find(i * n + j)] = find(x * n + y);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa != pb {
            if self.size[pa] > self.size[pb] {
                self.p[pb] = pa;
                self.size[pa] += self.size[pb];
            } else {
                self.p[pa] = pb;
                self.size[pb] += self.size[pa];
            }
        }
    }
}

impl Solution {
    pub fn maximum_minimum_path(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut uf = UnionFind::new(m * n);
        let mut q: Vec<Vec<i32>> = Vec::new();

        for i in 0..m {
            for j in 0..n {
                q.push(vec![grid[i][j], i as i32, j as i32]);
            }
        }

        q.sort_by(|a, b| b[0].cmp(&a[0]));

        let mut vis: Vec<Vec<bool>> = vec![vec![false; n]; m];
        let dirs: [i32; 5] = [-1, 0, 1, 0, -1];
        let mut ans = 0;
        for k in 0..q.len() {
            if uf.find(0) == uf.find(m * n - 1) {
                break;
            }
            let t = &q[k];
            let (v, i, j) = (t[0], t[1] as usize, t[2] as usize);
            ans = v;
            vis[i][j] = true;
            for d in 0..4 {
                let x = (i as i32) + dirs[d];
                let y = (j as i32) + dirs[d + 1];
                if x >= 0
                    && x < (m as i32)
                    && y >= 0
                    && y < (n as i32)
                    && vis[x as usize][y as usize]
                {
                    uf.union((x as usize) * n + (y as usize), i * n + j);
                }
            }
        }
        ans
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
class UnionFind:
    __slots__ = ("p", "size")

    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        uf = UnionFind(m * n)
        q = [(v, i, j) for i, row in enumerate(grid) for j, v in enumerate(row)]
        q.sort()
        ans = 0
        vis = set()
        dirs = (-1, 0, 1, 0, -1)
        while uf.find(0) != uf.find(m * n - 1):
            v, i, j = q.pop()
            ans = v
            vis.add((i, j))
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (x, y) in vis:
                    uf.union(x * n + y, i * n + j)
        return ans
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    public int maximumMinimumPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        UnionFind uf = new UnionFind(m * n);
        List<int[]> q = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.add(new int[] {grid[i][j], i, j});
            }
        }
        q.sort((a, b) -> b[0] - a[0]);
        boolean[][] vis = new boolean[m][n];
        int[] dirs = {-1, 0, 1, 0, -1};
        int ans = 0;
        for (int i = 0; uf.find(0) != uf.find(m * n - 1); ++i) {
            int[] t = q.get(i);
            vis[t[1]][t[2]] = true;
            ans = t[0];
            for (int k = 0; k < 4; ++k) {
                int x = t[1] + dirs[k], y = t[2] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    uf.union(x * n + y, t[1] * n + t[2]);
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> q;
        UnionFind uf(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace_back(grid[i][j], i, j);
            }
        }
        sort(q.begin(), q.end(), greater<tuple<int, int, int>>());
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (auto& [v, i, j] : q) {
            vis[i][j] = true;
            ans = v;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    uf.unite(x * n + y, i * n + j);
                }
            }
            if (uf.find(0) == uf.find(m * n - 1)) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func maximumMinimumPath(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	uf := newUnionFind(m * n)
	vis := make([][]bool, m)
	q := [][3]int{}
	for i, row := range grid {
		vis[i] = make([]bool, n)
		for j, v := range row {
			q = append(q, [3]int{v, i, j})
		}
	}
	sort.Slice(q, func(i, j int) bool { return q[i][0] > q[j][0] })
	dirs := [5]int{-1, 0, 1, 0, -1}
	for _, t := range q {
		v, i, j := t[0], t[1], t[2]
		ans = v
		vis[i][j] = true
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if 0 <= x && x < m && 0 <= y && y < n && vis[x][y] {
				uf.union(x*n+y, i*n+j)
			}
		}
		if uf.find(0) == uf.find(m*n-1) {
			break
		}
	}
	return
}
```

#### TypeScript

```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function maximumMinimumPath(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const q: number[][] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            q.push([grid[i][j], i, j]);
        }
    }
    q.sort((a, b) => b[0] - a[0]);
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const vis: boolean[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(false));
    let ans = 0;
    const uf = new UnionFind(m * n);
    for (let k = 0; uf.find(0) !== uf.find(m * n - 1); ++k) {
        const [t, i, j] = q[k];
        ans = t;
        vis[i][j] = true;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                uf.union(i * n + j, x * n + y);
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

# [1103. 分糖果 II](https://leetcode.cn/problems/distribute-candies-to-people){#1103}

{{< tabs "1103" >}}

{{% tab "python" %}}
```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        i = 0
        while candies:
            ans[i % num_people] += min(candies, i + 1)
            candies -= min(candies, i + 1)
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        for (int i = 0; candies > 0; ++i) {
            ans[i % num_people] += Math.min(candies, i + 1);
            candies -= Math.min(candies, i + 1);
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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        for (int i = 0; candies > 0; ++i) {
            ans[i % num_people] += min(candies, i + 1);
            candies -= min(candies, i + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCandies(candies int, num_people int) []int {
	ans := make([]int, num_people)
	for i := 0; candies > 0; i++ {
		ans[i%num_people] += min(candies, i+1)
		candies -= min(candies, i+1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCandies(candies: number, num_people: number): number[] {
    const ans: number[] = Array(num_people).fill(0);
    for (let i = 0; candies > 0; ++i) {
        ans[i % num_people] += Math.min(candies, i + 1);
        candies -= Math.min(candies, i + 1);
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

<p>排排坐，分糖果。</p>

<p>我们买了一些糖果 <code>candies</code>，打算把它们分给排好队的 <strong><code>n = num_people</code></strong> 个小朋友。</p>

<p>给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 <code>n</code>&nbsp;颗糖果。</p>

<p>然后，我们再回到队伍的起点，给第一个小朋友 <code>n&nbsp;+ 1</code> 颗糖果，第二个小朋友 <code>n&nbsp;+ 2</code> 颗，依此类推，直到给最后一个小朋友 <code>2 * n</code>&nbsp;颗糖果。</p>

<p>重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。</p>

<p>返回一个长度为 <code>num_people</code>、元素之和为 <code>candies</code> 的数组，以表示糖果的最终分发情况（即 <code>ans[i]</code> 表示第 <code>i</code> 个小朋友分到的糖果数）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>candies = 7, num_people = 4
<strong>输出：</strong>[1,2,3,1]
<strong>解释：</strong>
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>candies = 10, num_people = 3
<strong>输出：</strong>[5,2,3]
<strong>解释：</strong>
第一次，ans[0] += 1，数组变为 [1,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0]。
第三次，ans[2] += 3，数组变为 [1,2,3]。
第四次，ans[0] += 4，最终数组变为 [5,2,3]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candies &lt;= 10^9</code></li>
	<li><code>1 &lt;= num_people &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟每一个人分到糖果的过程，按照题目描述的规则模拟即可。

时间复杂度 $O(\max(\sqrt{candies}, num\_people))$，空间复杂度 $O(num\_people)$。其中 $candies$ 为糖果数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        i = 0
        while candies:
            ans[i % num_people] += min(candies, i + 1)
            candies -= min(candies, i + 1)
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        for (int i = 0; candies > 0; ++i) {
            ans[i % num_people] += Math.min(candies, i + 1);
            candies -= Math.min(candies, i + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        for (int i = 0; candies > 0; ++i) {
            ans[i % num_people] += min(candies, i + 1);
            candies -= min(candies, i + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func distributeCandies(candies int, num_people int) []int {
	ans := make([]int, num_people)
	for i := 0; candies > 0; i++ {
		ans[i%num_people] += min(candies, i+1)
		candies -= min(candies, i+1)
	}
	return ans
}
```

#### TypeScript

```ts
function distributeCandies(candies: number, num_people: number): number[] {
    const ans: number[] = Array(num_people).fill(0);
    for (let i = 0; candies > 0; ++i) {
        ans[i % num_people] += Math.min(candies, i + 1);
        candies -= Math.min(candies, i + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1104. 二叉树寻路](https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree){#1104}

{{< tabs "1104" >}}

{{% tab "python" %}}
```python
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        x = i = 1
        while (x << 1) <= label:
            x <<= 1
            i += 1
        ans = [0] * i
        while i:
            ans[i - 1] = label
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1
            i -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int x = 1, i = 1;
        while ((x << 1) <= label) {
            x <<= 1;
            ++i;
        }
        List<Integer> ans = new ArrayList<>();
        for (; i > 0; --i) {
            ans.add(label);
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1;
        }
        Collections.reverse(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int x = 1, i = 1;
        while ((x << 1) <= label) {
            x <<= 1;
            ++i;
        }
        vector<int> ans;
        for (; i > 0; --i) {
            ans.push_back(label);
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pathInZigZagTree(label int) (ans []int) {
	x, i := 1, 1
	for x<<1 <= label {
		x <<= 1
		i++
	}
	for ; i > 0; i-- {
		ans = append(ans, label)
		label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
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

<p>在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 <strong>逐行</strong> 依次按&nbsp;&ldquo;之&rdquo; 字形进行标记。</p>

<p>如下图所示，在奇数行（即，第一行、第三行、第五行&hellip;&hellip;）中，按从左到右的顺序进行标记；</p>

<p>而偶数行（即，第二行、第四行、第六行&hellip;&hellip;）中，按从右到左的顺序进行标记。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1104.Path%20In%20Zigzag%20Labelled%20Binary%20Tree/images/tree.png" style="height: 138px; width: 300px;"></p>

<p>给你树上某一个节点的标号 <code>label</code>，请你返回从根节点到该标号为 <code>label</code> 节点的路径，该路径是由途经的节点标号所组成的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>label = 14
<strong>输出：</strong>[1,3,4,14]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>label = 26
<strong>输出：</strong>[1,2,6,10,26]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= label &lt;= 10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

对于一棵完全二叉树，第 $i$ 行的节点个数为 $2^{i-1}$，第 $i$ 行的节点编号范围为 $[2^{i-1}, 2^i - 1]$。而题目中对于奇数行，按从左到右的顺序进行标记，对于偶数行，按从右到左的顺序进行标记。所以对于第 $i$ 行的节点 $label$，它的互补节点编号为 $2^{i-1} + 2^i - 1 - label$。所以节点 $label$ 的实际父节点编号为 $(2^{i-1} + 2^i - 1 - label) / 2$。我们可以通过不断地求互补节点编号和父节点编号，直到到达根节点，即可得到从根节点到节点 $label$ 的路径。

最后，我们需要将路径反转，因为题目要求路径是从根节点到节点 $label$ 的路径。

时间复杂度 $O(\log n)$，其中 $n$ 为节点 $label$ 的编号。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        x = i = 1
        while (x << 1) <= label:
            x <<= 1
            i += 1
        ans = [0] * i
        while i:
            ans[i - 1] = label
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1
            i -= 1
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int x = 1, i = 1;
        while ((x << 1) <= label) {
            x <<= 1;
            ++i;
        }
        List<Integer> ans = new ArrayList<>();
        for (; i > 0; --i) {
            ans.add(label);
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1;
        }
        Collections.reverse(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int x = 1, i = 1;
        while ((x << 1) <= label) {
            x <<= 1;
            ++i;
        }
        vector<int> ans;
        for (; i > 0; --i) {
            ans.push_back(label);
            label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func pathInZigZagTree(label int) (ans []int) {
	x, i := 1, 1
	for x<<1 <= label {
		x <<= 1
		i++
	}
	for ; i > 0; i-- {
		ans = append(ans, label)
		label = ((1 << (i - 1)) + (1 << i) - 1 - label) >> 1
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1105. 填充书架](https://leetcode.cn/problems/filling-bookcase-shelves){#1105}

{{< tabs "1105" >}}

{{% tab "python" %}}
```python
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        f = [0] * (n + 1)
        for i, (w, h) in enumerate(books, 1):
            f[i] = f[i - 1] + h
            for j in range(i - 1, 0, -1):
                w += books[j - 1][0]
                if w > shelfWidth:
                    break
                h = max(h, books[j - 1][1])
                f[i] = min(f[i], f[j - 1] + h)
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = Math.max(h, books[j - 1][1]);
                f[i] = Math.min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = max(h, books[j - 1][1]);
                f[i] = min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minHeightShelves(books [][]int, shelfWidth int) int {
	n := len(books)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		w, h := books[i-1][0], books[i-1][1]
		f[i] = f[i-1] + h
		for j := i - 1; j > 0; j-- {
			w += books[j-1][0]
			if w > shelfWidth {
				break
			}
			h = max(h, books[j-1][1])
			f[i] = min(f[i], f[j-1]+h)
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minHeightShelves(books: number[][], shelfWidth: number): number {
    const n = books.length;
    const f = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        let [w, h] = books[i - 1];
        f[i] = f[i - 1] + h;
        for (let j = i - 1; j > 0; --j) {
            w += books[j - 1][0];
            if (w > shelfWidth) {
                break;
            }
            h = Math.max(h, books[j - 1][1]);
            f[i] = Math.min(f[i], f[j - 1] + h);
        }
    }
    return f[n];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinHeightShelves(int[][] books, int shelfWidth) {
        int n = books.Length;
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = Math.Max(h, books[j - 1][1]);
                f[i] = Math.Min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组 <code>books</code> ，其中&nbsp;<code>books[i] = [thickness<sub>i</sub>, height<sub>i</sub>]</code>&nbsp;表示第 <code>i</code> 本书的厚度和高度。你也会得到一个整数 <code>shelfWidth</code> 。</p>

<p><strong>按顺序</strong>&nbsp;将这些书摆放到总宽度为 <code>shelfWidth</code> 的书架上。</p>

<p>先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 <code>shelfWidth</code> ），然后再建一层书架。重复这个过程，直到把所有的书都放在书架上。</p>

<p>需要注意的是，在上述过程的每个步骤中，<strong>摆放书的顺序与给定图书数组 </strong><code>books</code><strong> 顺序相同</strong>。</p>

<ul>
	<li>例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二本书放在第一层书架上，第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。</li>
</ul>

<p>每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。</p>

<p>以这种方式布置书架，返回书架整体可能的最小高度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1105.Filling%20Bookcase%20Shelves/images/shelves.png" style="width: 337px; height: 500px;" /></p>

<pre>
<strong>输入：</strong>books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
<strong>输出：</strong>6
<strong>解释：</strong>
3 层书架的高度和为 1 + 3 + 2 = 6 。
第 2 本书不必放在第一层书架上。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> books = [[1,3],[2,4],[3,2]], shelfWidth = 6
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 1000</code></li>
	<li><code>1 &lt;= thickness<sub>i</sub>&nbsp;&lt;= shelfWidth &lt;= 1000</code></li>
	<li><code>1 &lt;= height<sub>i</sub>&nbsp;&lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示前 $i$ 本书摆放的最小高度，初始时 $f[0] = 0$，答案为 $f[n]$。

考虑 $f[i]$，最后一本书为 $books[i - 1]$，其厚度为 $w$，高度为 $h$。

-   如果这本书单独摆放在新的一层，那么有 $f[i] = f[i - 1] + h$；
-   如果这本书可以与前面的最后几本书摆放在同一层，我们从后往前枚举同一层的第一本书 $boos[j-1]$，其中 $j \in [1, i - 1]$，将书的厚度累积到 $w$，如果 $w \gt shelfWidth$，说明此时的 $books[j-1]$ 已经无法与 $books[i-1]$ 摆放在同一层，停止枚举；否则我们更新当前层的最大高度 $h = \max(h, books[j-1][1])$，那么此时有 $f[i] = \min(f[i], f[j - 1] + h)$。

最终的答案即为 $f[n]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $books$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        f = [0] * (n + 1)
        for i, (w, h) in enumerate(books, 1):
            f[i] = f[i - 1] + h
            for j in range(i - 1, 0, -1):
                w += books[j - 1][0]
                if w > shelfWidth:
                    break
                h = max(h, books[j - 1][1])
                f[i] = min(f[i], f[j - 1] + h)
        return f[n]
```

#### Java

```java
class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = Math.max(h, books[j - 1][1]);
                f[i] = Math.min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = max(h, books[j - 1][1]);
                f[i] = min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func minHeightShelves(books [][]int, shelfWidth int) int {
	n := len(books)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		w, h := books[i-1][0], books[i-1][1]
		f[i] = f[i-1] + h
		for j := i - 1; j > 0; j-- {
			w += books[j-1][0]
			if w > shelfWidth {
				break
			}
			h = max(h, books[j-1][1])
			f[i] = min(f[i], f[j-1]+h)
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function minHeightShelves(books: number[][], shelfWidth: number): number {
    const n = books.length;
    const f = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        let [w, h] = books[i - 1];
        f[i] = f[i - 1] + h;
        for (let j = i - 1; j > 0; --j) {
            w += books[j - 1][0];
            if (w > shelfWidth) {
                break;
            }
            h = Math.max(h, books[j - 1][1]);
            f[i] = Math.min(f[i], f[j - 1] + h);
        }
    }
    return f[n];
}
```

#### C#

```cs
public class Solution {
    public int MinHeightShelves(int[][] books, int shelfWidth) {
        int n = books.Length;
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = Math.Max(h, books[j - 1][1]);
                f[i] = Math.Min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1106. 解析布尔表达式](https://leetcode.cn/problems/parsing-a-boolean-expression){#1106}

{{< tabs "1106" >}}

{{% tab "python" %}}
```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stk = []
        for c in expression:
            if c in 'tf!&|':
                stk.append(c)
            elif c == ')':
                t = f = 0
                while stk[-1] in 'tf':
                    t += stk[-1] == 't'
                    f += stk[-1] == 'f'
                    stk.pop()
                match stk.pop():
                    case '!':
                        c = 't' if f else 'f'
                    case '&':
                        c = 'f' if f else 't'
                    case '|':
                        c = 't' if t else 'f'
                stk.append(c)
        return stk[0] == 't'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : expression.toCharArray()) {
            if (c != '(' && c != ')' && c != ',') {
                stk.push(c);
            } else if (c == ')') {
                int t = 0, f = 0;
                while (stk.peek() == 't' || stk.peek() == 'f') {
                    t += stk.peek() == 't' ? 1 : 0;
                    f += stk.peek() == 'f' ? 1 : 0;
                    stk.pop();
                }
                char op = stk.pop();
                c = 'f';
                if ((op == '!' && f > 0) || (op == '&' && f == 0) || (op == '|' && t > 0)) {
                    c = 't';
                }
                stk.push(c);
            }
        }
        return stk.peek() == 't';
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char c : expression) {
            if (c != '(' && c != ')' && c != ',')
                stk.push(c);
            else if (c == ')') {
                int t = 0, f = 0;
                while (stk.top() == 't' || stk.top() == 'f') {
                    t += stk.top() == 't';
                    f += stk.top() == 'f';
                    stk.pop();
                }
                char op = stk.top();
                stk.pop();
                if (op == '!') c = f ? 't' : 'f';
                if (op == '&') c = f ? 'f' : 't';
                if (op == '|') c = t ? 't' : 'f';
                stk.push(c);
            }
        }
        return stk.top() == 't';
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func parseBoolExpr(expression string) bool {
	stk := []rune{}
	for _, c := range expression {
		if c != '(' && c != ')' && c != ',' {
			stk = append(stk, c)
		} else if c == ')' {
			var t, f int
			for stk[len(stk)-1] == 't' || stk[len(stk)-1] == 'f' {
				if stk[len(stk)-1] == 't' {
					t++
				} else {
					f++
				}
				stk = stk[:len(stk)-1]
			}
			op := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			c = 'f'
			if (op == '!' && f > 0) || (op == '&' && f == 0) || (op == '|' && t > 0) {
				c = 't'
			}
			stk = append(stk, c)
		}
	}
	return stk[0] == 't'
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function parseBoolExpr(expression: string): boolean {
    const expr = expression;
    const n = expr.length;
    let i = 0;
    const dfs = () => {
        let res: boolean[] = [];
        while (i < n) {
            const c = expr[i++];
            if (c === ')') {
                break;
            }

            if (c === '!') {
                res.push(!dfs()[0]);
            } else if (c === '|') {
                res.push(dfs().some(v => v));
            } else if (c === '&') {
                res.push(dfs().every(v => v));
            } else if (c === 't') {
                res.push(true);
            } else if (c === 'f') {
                res.push(false);
            }
        }
        return res;
    };
    return dfs()[0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(i: &mut usize, expr: &[u8]) -> Vec<bool> {
        let n = expr.len();
        let mut res = Vec::new();
        while *i < n {
            let c = expr[*i];
            *i += 1;
            match c {
                b')' => {
                    break;
                }
                b't' => {
                    res.push(true);
                }
                b'f' => {
                    res.push(false);
                }
                b'!' => {
                    res.push(!Self::dfs(i, expr)[0]);
                }
                b'&' => {
                    res.push(Self::dfs(i, expr).iter().all(|v| *v));
                }
                b'|' => {
                    res.push(Self::dfs(i, expr).iter().any(|v| *v));
                }
                _ => {}
            }
        }
        res
    }

    pub fn parse_bool_expr(expression: String) -> bool {
        let expr = expression.as_bytes();
        let mut i = 0;
        Self::dfs(&mut i, expr)[0]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>布尔表达式</strong> 是计算结果不是 <code>true</code> 就是 <code>false</code> 的表达式。有效的表达式需遵循以下约定：</p>

<ul>
	<li><code>'t'</code>，运算结果为 <code>true</code></li>
	<li><code>'f'</code>，运算结果为 <code>false</code></li>
	<li><code>'!(subExpr)'</code>，运算过程为对内部表达式 <code>subExpr</code> 进行 <strong>逻辑非</strong>（NOT）运算</li>
	<li><code>'&amp;(subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub>)'</code>，运算过程为对 2 个或以上内部表达式 <code>subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub></code> 进行 <strong>逻辑与</strong>（AND）运算</li>
	<li><code>'|(subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub>)'</code>，运算过程为对 2 个或以上内部表达式 <code>subExpr<sub>1</sub>, subExpr<sub>2</sub>, ..., subExpr<sub>n</sub></code> 进行 <strong>逻辑或</strong>（OR）运算</li>
</ul>

<p>给你一个以字符串形式表述的&nbsp;<a href="https://baike.baidu.com/item/%E5%B8%83%E5%B0%94%E8%A1%A8%E8%BE%BE%E5%BC%8F/1574380?fr=aladdin" target="_blank">布尔表达式</a> <code>expression</code>，返回该式的运算结果。</p>

<p>题目测试用例所给出的表达式均为有效的布尔表达式，遵循上述约定。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>expression = "&amp;(|(f))"
<strong>输出：</strong>false
<strong>解释：</strong>
首先，计算 |(f) --&gt; f ，表达式变为 "&amp;(f)" 。
接着，计算 &amp;(f) --&gt; f ，表达式变为 "f" 。
最后，返回 false 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>expression = "|(f,f,f,t)"
<strong>输出：</strong>true
<strong>解释：</strong>计算 (false OR false OR false OR true) ，结果为 true 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>expression = "!(&amp;(f,t))"
<strong>输出：</strong>true
<strong>解释：</strong>
首先，计算 &amp;(f,t) --&gt; (false AND true) --&gt; false --&gt; f ，表达式变为 "!(f)" 。
接着，计算 !(f) --&gt; NOT false --&gt; true ，返回 true 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>expression[i]</code> 为 <code>'('</code>、<code>')'</code>、<code>'&amp;'</code>、<code>'|'</code>、<code>'!'</code>、<code>'t'</code>、<code>'f'</code> 和 <code>','</code> 之一</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

对于这种表达式解析问题，我们可以使用栈来辅助解决。

从左到右遍历表达式 `expression`，对于遍历到的每个字符 $c$：

-   如果 $c$ 是 `"tf!&|"` 中的一个，我们直接将其入栈；
-   如果 $c$ 是右括号 `')'`，我们将栈中元素依次出栈，直到遇到操作符 `'!'` 或 `'&'` 或 `'|'`。过程中我们用变量 $t$ 和 $f$ 记录出栈字符中 `'t'` 和 `'f'` 的个数。最后根据出栈字符的个数和操作符计算得到新的字符 `'t'` 或 `'f'`，并将其入栈。

遍历完表达式 `expression` 后，栈中只剩下一个字符，如果是 `'t'`，返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是表达式 `expression` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stk = []
        for c in expression:
            if c in 'tf!&|':
                stk.append(c)
            elif c == ')':
                t = f = 0
                while stk[-1] in 'tf':
                    t += stk[-1] == 't'
                    f += stk[-1] == 'f'
                    stk.pop()
                match stk.pop():
                    case '!':
                        c = 't' if f else 'f'
                    case '&':
                        c = 'f' if f else 't'
                    case '|':
                        c = 't' if t else 'f'
                stk.append(c)
        return stk[0] == 't'
```

#### Java

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : expression.toCharArray()) {
            if (c != '(' && c != ')' && c != ',') {
                stk.push(c);
            } else if (c == ')') {
                int t = 0, f = 0;
                while (stk.peek() == 't' || stk.peek() == 'f') {
                    t += stk.peek() == 't' ? 1 : 0;
                    f += stk.peek() == 'f' ? 1 : 0;
                    stk.pop();
                }
                char op = stk.pop();
                c = 'f';
                if ((op == '!' && f > 0) || (op == '&' && f == 0) || (op == '|' && t > 0)) {
                    c = 't';
                }
                stk.push(c);
            }
        }
        return stk.peek() == 't';
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char c : expression) {
            if (c != '(' && c != ')' && c != ',')
                stk.push(c);
            else if (c == ')') {
                int t = 0, f = 0;
                while (stk.top() == 't' || stk.top() == 'f') {
                    t += stk.top() == 't';
                    f += stk.top() == 'f';
                    stk.pop();
                }
                char op = stk.top();
                stk.pop();
                if (op == '!') c = f ? 't' : 'f';
                if (op == '&') c = f ? 'f' : 't';
                if (op == '|') c = t ? 't' : 'f';
                stk.push(c);
            }
        }
        return stk.top() == 't';
    }
};
```

#### Go

```go
func parseBoolExpr(expression string) bool {
	stk := []rune{}
	for _, c := range expression {
		if c != '(' && c != ')' && c != ',' {
			stk = append(stk, c)
		} else if c == ')' {
			var t, f int
			for stk[len(stk)-1] == 't' || stk[len(stk)-1] == 'f' {
				if stk[len(stk)-1] == 't' {
					t++
				} else {
					f++
				}
				stk = stk[:len(stk)-1]
			}
			op := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			c = 'f'
			if (op == '!' && f > 0) || (op == '&' && f == 0) || (op == '|' && t > 0) {
				c = 't'
			}
			stk = append(stk, c)
		}
	}
	return stk[0] == 't'
}
```

#### TypeScript

```ts
function parseBoolExpr(expression: string): boolean {
    const expr = expression;
    const n = expr.length;
    let i = 0;
    const dfs = () => {
        let res: boolean[] = [];
        while (i < n) {
            const c = expr[i++];
            if (c === ')') {
                break;
            }

            if (c === '!') {
                res.push(!dfs()[0]);
            } else if (c === '|') {
                res.push(dfs().some(v => v));
            } else if (c === '&') {
                res.push(dfs().every(v => v));
            } else if (c === 't') {
                res.push(true);
            } else if (c === 'f') {
                res.push(false);
            }
        }
        return res;
    };
    return dfs()[0];
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: &mut usize, expr: &[u8]) -> Vec<bool> {
        let n = expr.len();
        let mut res = Vec::new();
        while *i < n {
            let c = expr[*i];
            *i += 1;
            match c {
                b')' => {
                    break;
                }
                b't' => {
                    res.push(true);
                }
                b'f' => {
                    res.push(false);
                }
                b'!' => {
                    res.push(!Self::dfs(i, expr)[0]);
                }
                b'&' => {
                    res.push(Self::dfs(i, expr).iter().all(|v| *v));
                }
                b'|' => {
                    res.push(Self::dfs(i, expr).iter().any(|v| *v));
                }
                _ => {}
            }
        }
        res
    }

    pub fn parse_bool_expr(expression: String) -> bool {
        let expr = expression.as_bytes();
        let mut i = 0;
        Self::dfs(&mut i, expr)[0]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1107. 每日新用户统计 🔒](https://leetcode.cn/problems/new-users-daily-count){#1107}

{{< tabs "1107" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            MIN(activity_date) OVER (PARTITION BY user_id) AS login_date
        FROM Traffic
        WHERE activity = 'login'
    )
SELECT login_date, COUNT(DISTINCT user_id) AS user_count
FROM T
WHERE DATEDIFF('2019-06-30', login_date) <= 90
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Traffic</code>&nbsp;表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| activity      | enum    |
| activity_date | date    |
+---------------+---------+
该表可能有重复的行。
activity 列是 ENUM 类型，可能取 ('login', 'logout', 'jobs', 'groups', 'homepage') 几个值之一。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出从今天起最多 <code>90</code> 天内，每个日期首次登录的用户数。假设今天是&nbsp;<strong>2019-06-30 </strong>。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Traffic 表：
+---------+----------+---------------+
| user_id | activity | activity_date |
+---------+----------+---------------+
| 1       | login    | 2019-05-01    |
| 1       | homepage | 2019-05-01    |
| 1       | logout   | 2019-05-01    |
| 2       | login    | 2019-06-21    |
| 2       | logout   | 2019-06-21    |
| 3       | login    | 2019-01-01    |
| 3       | jobs     | 2019-01-01    |
| 3       | logout   | 2019-01-01    |
| 4       | login    | 2019-06-21    |
| 4       | groups   | 2019-06-21    |
| 4       | logout   | 2019-06-21    |
| 5       | login    | 2019-03-01    |
| 5       | logout   | 2019-03-01    |
| 5       | login    | 2019-06-21    |
| 5       | logout   | 2019-06-21    |
+---------+----------+---------------+
<strong>输出：</strong>
+------------+-------------+
| login_date | user_count  |
+------------+-------------+
| 2019-05-01 | 1           |
| 2019-06-21 | 2           |
+------------+-------------+
<strong>解释：</strong>
请注意，我们只关心用户数非零的日期.
ID 为 5 的用户第一次登陆于 2019-03-01，因此他不算在 2019-06-21 的的统计内。
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
    T AS (
        SELECT
            user_id,
            MIN(activity_date) OVER (PARTITION BY user_id) AS login_date
        FROM Traffic
        WHERE activity = 'login'
    )
SELECT login_date, COUNT(DISTINCT user_id) AS user_count
FROM T
WHERE DATEDIFF('2019-06-30', login_date) <= 90
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1108. IP 地址无效化](https://leetcode.cn/problems/defanging-an-ip-address){#1108}

{{< tabs "1108" >}}

{{% tab "python" %}}
```python
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = address.size(); i >= 0; --i) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
            }
        }
        return address;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func defangIPaddr(address string) string {
	return strings.Replace(address, ".", "[.]", -1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function defangIPaddr(address: string): string {
    return address.split('.').join('[.]');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有效的 <a href="https://baike.baidu.com/item/IPv4" target="_blank">IPv4</a> 地址&nbsp;<code>address</code>，返回这个 IP 地址的无效化版本。</p>

<p>所谓无效化&nbsp;IP 地址，其实就是用&nbsp;<code>&quot;[.]&quot;</code>&nbsp;代替了每个 <code>&quot;.&quot;</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>address = &quot;1.1.1.1&quot;
<strong>输出：</strong>&quot;1[.]1[.]1[.]1&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>address = &quot;255.100.50.0&quot;
<strong>输出：</strong>&quot;255[.]100[.]50[.]0&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给出的&nbsp;<code>address</code>&nbsp;是一个有效的 IPv4 地址</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接替换

我们直接将字符串中的 `'.'` 替换为 `'[.]'` 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
```

#### Java

```java
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}
```

#### C++

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = address.size(); i >= 0; --i) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
            }
        }
        return address;
    }
};
```

#### Go

```go
func defangIPaddr(address string) string {
	return strings.Replace(address, ".", "[.]", -1)
}
```

#### TypeScript

```ts
function defangIPaddr(address: string): string {
    return address.split('.').join('[.]');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1109. 航班预订统计](https://leetcode.cn/problems/corporate-flight-bookings){#1109}

{{< tabs "1109" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        tree = BinaryIndexedTree(n)
        for first, last, seats in bookings:
            tree.update(first, seats)
            tree.update(last + 1, -seats)
        return [tree.query(i + 1) for i in range(n)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (var e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            tree.update(first, seats);
            tree.update(last + 1, -seats);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = tree.query(i + 1);
        }
        return ans;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        for (auto& e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            tree->update(first, seats);
            tree->update(last + 1, -seats);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = tree->query(i + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func corpFlightBookings(bookings [][]int, n int) []int {
	tree := newBinaryIndexedTree(n)
	for _, e := range bookings {
		first, last, seats := e[0], e[1], e[2]
		tree.update(first, seats)
		tree.update(last+1, -seats)
	}
	ans := make([]int, n)
	for i := range ans {
		ans[i] = tree.query(i + 1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let mut ans = vec![0; n as usize];

        // Build the difference vector first
        for b in &bookings {
            let (l, r) = ((b[0] as usize) - 1, (b[1] as usize) - 1);
            ans[l] += b[2];
            if r < (n as usize) - 1 {
                ans[r + 1] -= b[2];
            }
        }

        // Build the prefix sum vector based on the difference vector
        for i in 1..n as usize {
            ans[i] += ans[i - 1];
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function (bookings, n) {
    const ans = new Array(n).fill(0);
    for (const [first, last, seats] of bookings) {
        ans[first - 1] += seats;
        if (last < n) {
            ans[last] -= seats;
        }
    }
    for (let i = 1; i < n; ++i) {
        ans[i] += ans[i - 1];
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

<p>这里有&nbsp;<code>n</code>&nbsp;个航班，它们分别从 <code>1</code> 到 <code>n</code> 进行编号。</p>

<p>有一份航班预订表&nbsp;<code>bookings</code> ，表中第&nbsp;<code>i</code>&nbsp;条预订记录&nbsp;<code>bookings[i] = [first<sub>i</sub>, last<sub>i</sub>, seats<sub>i</sub>]</code>&nbsp;意味着在从 <code>first<sub>i</sub></code>&nbsp;到 <code>last<sub>i</sub></code> （<strong>包含</strong> <code>first<sub>i</sub></code> 和 <code>last<sub>i</sub></code> ）的 <strong>每个航班</strong> 上预订了 <code>seats<sub>i</sub></code>&nbsp;个座位。</p>

<p>请你返回一个长度为 <code>n</code> 的数组&nbsp;<code>answer</code>，里面的元素是每个航班预定的座位总数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
<strong>输出：</strong>[10,55,45,25,25]
<strong>解释：</strong>
航班编号        1   2   3   4   5
预订记录 1 ：   10  10
预订记录 2 ：       20  20
预订记录 3 ：       25  25  25  25
总座位数：      10  55  45  25  25
因此，answer = [10,55,45,25,25]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>bookings = [[1,2,10],[2,2,15]], n = 2
<strong>输出：</strong>[10,25]
<strong>解释：</strong>
航班编号        1   2
预订记录 1 ：   10  10
预订记录 2 ：       15
总座位数：      10  25
因此，answer = [10,25]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= bookings.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>bookings[i].length == 3</code></li>
	<li><code>1 &lt;= first<sub>i</sub> &lt;= last<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= seats<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们注意到，每一次预订都是在某个区间 `[first, last]` 内的所有航班上预订了 `seats` 个座位。因此，我们可以利用差分数组的思想，对于每一次预订，将 `first` 位置的数加上 `seats`，将 `last + 1` 位置的数减去 `seats`。最后，对差分数组求前缀和，即可得到每个航班预定的座位总数。

时间复杂度 $O(n)$，其中 $n$ 为航班数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        for first, last, seats in bookings:
            ans[first - 1] += seats
            if last < n:
                ans[last] -= seats
        return list(accumulate(ans))
```

#### Java

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] ans = new int[n];
        for (var e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            ans[first - 1] += seats;
            if (last < n) {
                ans[last] -= seats;
            }
        }
        for (int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto& e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            ans[first - 1] += seats;
            if (last < n) {
                ans[last] -= seats;
            }
        }
        for (int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
```

#### Go

```go
func corpFlightBookings(bookings [][]int, n int) []int {
	ans := make([]int, n)
	for _, e := range bookings {
		first, last, seats := e[0], e[1], e[2]
		ans[first-1] += seats
		if last < n {
			ans[last] -= seats
		}
	}
	for i := 1; i < n; i++ {
		ans[i] += ans[i-1]
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let mut ans = vec![0; n as usize];

        // Build the difference vector first
        for b in &bookings {
            let (l, r) = ((b[0] as usize) - 1, (b[1] as usize) - 1);
            ans[l] += b[2];
            if r < (n as usize) - 1 {
                ans[r + 1] -= b[2];
            }
        }

        // Build the prefix sum vector based on the difference vector
        for i in 1..n as usize {
            ans[i] += ans[i - 1];
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function (bookings, n) {
    const ans = new Array(n).fill(0);
    for (const [first, last, seats] of bookings) {
        ans[first - 1] += seats;
        if (last < n) {
            ans[last] -= seats;
        }
    }
    for (let i = 1; i < n; ++i) {
        ans[i] += ans[i - 1];
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组 + 差分思想

我们也可以利用树状数组，结合差分的思想，来实现上述操作。我们可以将每一次预订看作是在某个区间 `[first, last]` 内的所有航班上预订了 `seats` 个座位。因此，我们可以对每一次预订，对树状数组的 `first` 位置加上 `seats`，对树状数组的 `last + 1` 位置减去 `seats`。最后，对树状数组每个位置求前缀和，即可得到每个航班预定的座位总数。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为航班数。

以下是树状数组的基本介绍：

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 x 位置的数加上一个值 delta；
1. **前缀和查询** `query(x)`：查询序列 `[1,...x]` 区间的区间和，即位置 x 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        tree = BinaryIndexedTree(n)
        for first, last, seats in bookings:
            tree.update(first, seats)
            tree.update(last + 1, -seats)
        return [tree.query(i + 1) for i in range(n)]
```

#### Java

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (var e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            tree.update(first, seats);
            tree.update(last + 1, -seats);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = tree.query(i + 1);
        }
        return ans;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        for (auto& e : bookings) {
            int first = e[0], last = e[1], seats = e[2];
            tree->update(first, seats);
            tree->update(last + 1, -seats);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = tree->query(i + 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func corpFlightBookings(bookings [][]int, n int) []int {
	tree := newBinaryIndexedTree(n)
	for _, e := range bookings {
		first, last, seats := e[0], e[1], e[2]
		tree.update(first, seats)
		tree.update(last+1, -seats)
	}
	ans := make([]int, n)
	for i := range ans {
		ans[i] = tree.query(i + 1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
