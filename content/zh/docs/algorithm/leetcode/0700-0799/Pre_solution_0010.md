---
title: "0790_多米诺和托米诺平铺"
date: 2025-10-08T18:36:29+08:00
weight: 10
tags: [二分查找, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 图, 字典树, 字符串, 字符串匹配, 广度优先搜索, 排序, 数学, 数组, 深度优先搜索, 矩阵]
---

{{< markmap >}}
### [0790_多米诺和托米诺平铺](#790)
#### [动态规划](#790)
### [0791_自定义字符串排序](#791)
#### [哈希表](#791)
#### [字符串](#791)
#### [排序](#791)
### [0792_匹配子序列的单词数](#792)
#### [字典树](#792)
#### [数组](#792)
#### [哈希表](#792)
#### [字符串](#792)
#### [二分查找](#792)
#### [动态规划](#792)
#### [排序](#792)
### [0793_阶乘函数后 K 个零](#793)
#### [数学](#793)
#### [二分查找](#793)
### [0794_有效的井字游戏](#794)
#### [数组](#794)
#### [矩阵](#794)
### [0795_区间子数组个数](#795)
#### [数组](#795)
#### [双指针](#795)
### [0796_旋转字符串](#796)
#### [字符串](#796)
#### [字符串匹配](#796)
### [0797_所有可能的路径](#797)
#### [深度优先搜索](#797)
#### [广度优先搜索](#797)
#### [图](#797)
#### [回溯](#797)
### [0798_得分最高的最小轮调](#798)
#### [数组](#798)
#### [前缀和](#798)
### [0799_香槟塔](#799)
#### [动态规划](#799)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0790_多米诺和托米诺平铺
___
#### 动态规划
---
### 0791_自定义字符串排序
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0792_匹配子序列的单词数
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 0793_阶乘函数后 K 个零
___
#### 数学
___
#### 二分查找
---
### 0794_有效的井字游戏
___
#### 数组
___
#### 矩阵
---
### 0795_区间子数组个数
___
#### 数组
___
#### 双指针
---
### 0796_旋转字符串
___
#### 字符串
___
#### 字符串匹配
---
### 0797_所有可能的路径
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 回溯
---
### 0798_得分最高的最小轮调
___
#### 数组
___
#### 前缀和
---
### 0799_香槟塔
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 回溯 |
| 图 | 字典树 | 字符串 |
| 字符串匹配 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 深度优先搜索 |
| 矩阵 |  |  |

# [790. 多米诺和托米诺平铺](https://leetcode.cn/problems/domino-and-tromino-tiling){#790}

{{< tabs "790" >}}

{{% tab "python" %}}
```python
class Solution:
    def numTilings(self, n: int) -> int:
        f = [1, 0, 0, 0]
        mod = 10**9 + 7
        for i in range(1, n + 1):
            g = [0] * 4
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod
            g[1] = (f[2] + f[3]) % mod
            g[2] = (f[1] + f[3]) % mod
            g[3] = f[0]
            f = g
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numTilings(int n) {
        long[] f = {1, 0, 0, 0};
        int mod = (int) 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            long[] g = new long[4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
            g[1] = (f[2] + f[3]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[0];
            f = g;
        }
        return (int) f[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        long long f[4] = {1, 0, 0, 0};
        for (int i = 1; i <= n; ++i) {
            long long g[4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
            g[1] = (f[2] + f[3]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[0];
            memcpy(f, g, sizeof(g));
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numTilings(n int) int {
	f := [4]int{}
	f[0] = 1
	const mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		g := [4]int{}
		g[0] = (f[0] + f[1] + f[2] + f[3]) % mod
		g[1] = (f[2] + f[3]) % mod
		g[2] = (f[1] + f[3]) % mod
		g[3] = f[0]
		f = g
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numTilings(n: number): number {
    const mod = 1_000_000_007;
    let f: number[] = [1, 0, 0, 0];

    for (let i = 1; i <= n; ++i) {
        const g: number[] = Array(4);
        g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
        g[1] = (f[2] + f[3]) % mod;
        g[2] = (f[1] + f[3]) % mod;
        g[3] = f[0] % mod;
        f = g;
    }

    return f[0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut f: [i64; 4] = [1, 0, 0, 0];
        for _ in 1..=n {
            let mut g = [0i64; 4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % MOD;
            g[1] = (f[2] + f[3]) % MOD;
            g[2] = (f[1] + f[3]) % MOD;
            g[3] = f[0] % MOD;
            f = g;
        }
        f[0] as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有两种形状的瓷砖：一种是&nbsp;<code>2 x 1</code> 的多米诺形，另一种是形如&nbsp;"L" 的托米诺形。两种形状都可以旋转。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0790.Domino%20and%20Tromino%20Tiling/images/lc-domino.jpg" style="height: 195px; width: 362px;" /></p>

<p>给定整数 n ，返回可以平铺&nbsp;<code>2 x n</code> 的面板的方法的数量。<strong>返回对</strong>&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取模&nbsp;</strong>的值。</p>

<p>平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0790.Domino%20and%20Tromino%20Tiling/images/lc-domino1.jpg" style="height: 226px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> n = 3
<strong>输出:</strong> 5
<strong>解释:</strong> 五种不同的方法如上所示。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 1
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们首先要读懂题意，题目实际上是让我们求铺满 $2\times n$ 的面板的方案数，其中面板上的每个正方形只能被一个瓷砖覆盖。

瓷砖的形状有两种，分别是 `2 x 1` 型 和 `L` 型，并且两种瓷砖都可以旋转。我们将旋转后的瓷砖分别记为 `1 x 2` 型 和 `L'` 型。

我们定义 $f[i][j]$ 表示平铺前 $2\times i$ 的面板，其中 $j$ 表示最后一列的状态。最后一列有 $4$ 种状态，分别是：

-   最后一列铺满，记为 $0$
-   最后一列只铺了上方一个瓷砖，记为 $1$
-   最后一列只铺了下方一个瓷砖，记为 $2$
-   最后一列没有铺瓷砖，记为 $3$

那么答案就是 $f[n][0]$。初始时 $f[0][0]=1$，其余 $f[0][j]=0$。

我们考虑铺到第 $i$ 列，来看看状态转移方程：

当 $j=0$ 时，最后一列铺满，可由前一列的 $0,1,2,3$ 四种状态铺上对应的瓷砖转移而来，即 $f[i-1][0]$ 铺上 `1 x 2` 型瓷砖，或者 $f[i-1][1]$ 铺上 `L'` 型瓷砖，或者 $f[i-1][2]$ 铺上 `L'` 型瓷砖，或者 $f[i-1][3]$ 铺上两块 `2 x 1` 型瓷砖。因此 $f[i][0]=\sum_{j=0}^3f[i-1][j]$。

当 $j=1$ 时，最后一列只铺了上方一个瓷砖，可由前一列的 $2,3$ 两种状态转移而来，即 $f[i-1][2]$ 铺上 `2 x 1` 型瓷砖，或者 $f[i-1][3]$ 铺上 `L` 型瓷砖。因此 $f[i][1]=f[i-1][2]+f[i-1][3]$。

当 $j=2$ 时，最后一列只铺了下方一个瓷砖，可由前一列的 $1,3$ 两种状态转移而来，即 $f[i-1][1]$ 铺上 `2 x 1` 型瓷砖，或者 $f[i-1][3]$ 铺上 `L'` 型瓷砖。因此 $f[i][2]=f[i-1][1]+f[i-1][3]$。

当 $j=3$ 时，最后一列没有铺瓷砖，可由前一列的 $0$ 一种状态转移而来。因此 $f[i][3]=f[i-1][0]$。

可以发现，状态转移方程中只涉及到前一列的状态，因此我们可以使用滚动数组优化空间复杂度。

注意，过程中的状态数值可能会很大，因此需要对 $10^9+7$ 取模。

时间复杂度 $O(n)$，其中 $n$ 为面板的列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numTilings(self, n: int) -> int:
        f = [1, 0, 0, 0]
        mod = 10**9 + 7
        for i in range(1, n + 1):
            g = [0] * 4
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod
            g[1] = (f[2] + f[3]) % mod
            g[2] = (f[1] + f[3]) % mod
            g[3] = f[0]
            f = g
        return f[0]
```

#### Java

```java
class Solution {
    public int numTilings(int n) {
        long[] f = {1, 0, 0, 0};
        int mod = (int) 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            long[] g = new long[4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
            g[1] = (f[2] + f[3]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[0];
            f = g;
        }
        return (int) f[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        long long f[4] = {1, 0, 0, 0};
        for (int i = 1; i <= n; ++i) {
            long long g[4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
            g[1] = (f[2] + f[3]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[0];
            memcpy(f, g, sizeof(g));
        }
        return f[0];
    }
};
```

#### Go

```go
func numTilings(n int) int {
	f := [4]int{}
	f[0] = 1
	const mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		g := [4]int{}
		g[0] = (f[0] + f[1] + f[2] + f[3]) % mod
		g[1] = (f[2] + f[3]) % mod
		g[2] = (f[1] + f[3]) % mod
		g[3] = f[0]
		f = g
	}
	return f[0]
}
```

#### TypeScript

```ts
function numTilings(n: number): number {
    const mod = 1_000_000_007;
    let f: number[] = [1, 0, 0, 0];

    for (let i = 1; i <= n; ++i) {
        const g: number[] = Array(4);
        g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
        g[1] = (f[2] + f[3]) % mod;
        g[2] = (f[1] + f[3]) % mod;
        g[3] = f[0] % mod;
        f = g;
    }

    return f[0];
}
```

#### Rust

```rust
impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut f: [i64; 4] = [1, 0, 0, 0];
        for _ in 1..=n {
            let mut g = [0i64; 4];
            g[0] = (f[0] + f[1] + f[2] + f[3]) % MOD;
            g[1] = (f[2] + f[3]) % MOD;
            g[2] = (f[1] + f[3]) % MOD;
            g[3] = f[0] % MOD;
            f = g;
        }
        f[0] as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [791. 自定义字符串排序](https://leetcode.cn/problems/custom-sort-string){#791}

{{< tabs "791" >}}

{{% tab "python" %}}
```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        cnt = Counter(s)
        ans = []
        for c in order:
            ans.append(c * cnt[c])
            cnt[c] = 0
        for c, v in cnt.items():
            ans.append(c * v)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String customSortString(String order, String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < order.length(); ++i) {
            char c = order.charAt(i);
            while (cnt[c - 'a']-- > 0) {
                ans.append(c);
            }
        }
        for (int i = 0; i < 26; ++i) {
            while (cnt[i]-- > 0) {
                ans.append((char) ('a' + i));
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        string ans;
        for (char& c : order)
            while (cnt[c - 'a']-- > 0) ans += c;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0) ans += string(cnt[i], i + 'a');
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func customSortString(order string, s string) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	ans := []rune{}
	for _, c := range order {
		for cnt[c-'a'] > 0 {
			ans = append(ans, c)
			cnt[c-'a']--
		}
	}
	for i, v := range cnt {
		for j := 0; j < v; j++ {
			ans = append(ans, rune('a'+i))
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function customSortString(order: string, s: string): string {
    const toIndex = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const count = new Array(26).fill(0);
    for (const c of s) {
        count[toIndex(c)]++;
    }
    const ans: string[] = [];
    for (const c of order) {
        const i = toIndex(c);
        ans.push(c.repeat(count[i]));
        count[i] = 0;
    }
    for (let i = 0; i < 26; i++) {
        if (!count[i]) continue;
        ans.push(String.fromCharCode('a'.charCodeAt(0) + i).repeat(count[i]));
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let mut count = [0; 26];
        for c in s.as_bytes() {
            count[(c - b'a') as usize] += 1;
        }
        let mut ans = String::new();
        for c in order.as_bytes() {
            for _ in 0..count[(c - b'a') as usize] {
                ans.push(char::from(*c));
            }
            count[(c - b'a') as usize] = 0;
        }
        for i in 0..count.len() {
            for _ in 0..count[i] {
                ans.push(char::from(b'a' + (i as u8)));
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

<p>给定两个字符串 <code>order</code> 和 <code>s</code> 。<code>order</code> 的所有字母都是 <strong>唯一</strong> 的，并且以前按照一些自定义的顺序排序。</p>

<p>对 <code>s</code> 的字符进行置换，使其与排序的&nbsp;<code>order</code>&nbsp;相匹配。更具体地说，如果在&nbsp;<code>order</code>&nbsp;中的字符 <code>x</code> 出现字符 <code>y</code> 之前，那么在排列后的字符串中， <code>x</code>&nbsp;也应该出现在 <code>y</code> 之前。</p>

<p>返回 <em>满足这个性质的 <code>s</code> 的任意一种排列&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> order = "cba", s = "abcd"
<strong>输出:</strong> "cbad"
<strong>解释:</strong> 
"a"、"b"、"c"是按顺序出现的，所以"a"、"b"、"c"的顺序应该是"c"、"b"、"a"。
因为"d"不是按顺序出现的，所以它可以在返回的字符串中的任何位置。"dcba"、"cdba"、"cbda"也是有效的输出。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> order = "cbafg", s = "abcd"
<strong>输出:</strong> "cbad"
解释：字符 "b"、"c" 和 "a" 规定了 s 中字符的顺序。s 中的字符 "d" 没有在 order 中出现，所以它的位置是弹性的。

按照出现的顺序，s 中的 "b"、"c"、"a" 应排列为"b"、"c"、"a"。"d" 可以放在任何位置，因为它没有按顺序排列。输出 "bcad" 遵循这一规则。其他排序如 "dbca" 或 "bcda" 也是有效的，只要维持 "b"、"c"、"a" 的顺序。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= order.length &lt;= 26</code></li>
	<li><code>1 &lt;= s.length &lt;= 200</code></li>
	<li><code>order</code>&nbsp;和&nbsp;<code>s</code>&nbsp;由小写英文字母组成</li>
	<li><code>order</code>&nbsp;中的所有字符都 <strong>不同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

一种比较直接的思路是，用哈希表或数组 $d$ 记录字符串 $order$ 中每个字符的位置，然后对字符串 $s$ 中每个字符按照其在 $d$ 中的位置进行排序。如果某个字符不在 $d$ 中，我们可以将其位置置为 $0$。

时间复杂度 $O(m + n\times \log n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是字符串 $order$ 和 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        d = {c: i for i, c in enumerate(order)}
        return ''.join(sorted(s, key=lambda x: d.get(x, 0)))
```

#### Java

```java
class Solution {
    public String customSortString(String order, String s) {
        int[] d = new int[26];
        for (int i = 0; i < order.length(); ++i) {
            d[order.charAt(i) - 'a'] = i;
        }
        List<Character> cs = new ArrayList<>();
        for (int i = 0; i < s.length(); ++i) {
            cs.add(s.charAt(i));
        }
        cs.sort((a, b) -> d[a - 'a'] - d[b - 'a']);
        return cs.stream().map(String::valueOf).collect(Collectors.joining());
    }
}
```

#### C++

```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        int d[26] = {0};
        for (int i = 0; i < order.size(); ++i) d[order[i] - 'a'] = i;
        sort(s.begin(), s.end(), [&](auto a, auto b) { return d[a - 'a'] < d[b - 'a']; });
        return s;
    }
};
```

#### Go

```go
func customSortString(order string, s string) string {
	d := [26]int{}
	for i := range order {
		d[order[i]-'a'] = i
	}
	cs := []byte(s)
	sort.Slice(cs, func(i, j int) bool { return d[cs[i]-'a'] < d[cs[j]-'a'] })
	return string(cs)
}
```

#### TypeScript

```ts
function customSortString(order: string, s: string): string {
    const toIndex = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const n = order.length;
    const d = new Array(26).fill(n);
    for (let i = 0; i < n; i++) {
        d[toIndex(order[i])] = i;
    }
    return [...s].sort((a, b) => d[toIndex(a)] - d[toIndex(b)]).join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let n = order.len();
        let mut d = [n; 26];
        for (i, c) in order.as_bytes().iter().enumerate() {
            d[(c - b'a') as usize] = i;
        }
        let mut ans = s.chars().collect::<Vec<_>>();
        ans.sort_by(|&a, &b| {
            d[((a as u8) - ('a' as u8)) as usize].cmp(&d[((b as u8) - ('a' as u8)) as usize])
        });
        ans.into_iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字符计数

我们还可以先统计 $s$ 中每个字符的出现次数，存储在 $cnt$ 数组中。

然后把字符串 $s$ 在 $order$ 中出现的字符按照 $order$ 中的顺序排序，添加到结果字符串中。最后把剩余的字符直接追加到结果字符串中。

时间复杂度 $O(m+n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是字符串 $order$ 和 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        cnt = Counter(s)
        ans = []
        for c in order:
            ans.append(c * cnt[c])
            cnt[c] = 0
        for c, v in cnt.items():
            ans.append(c * v)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String customSortString(String order, String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < order.length(); ++i) {
            char c = order.charAt(i);
            while (cnt[c - 'a']-- > 0) {
                ans.append(c);
            }
        }
        for (int i = 0; i < 26; ++i) {
            while (cnt[i]-- > 0) {
                ans.append((char) ('a' + i));
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        string ans;
        for (char& c : order)
            while (cnt[c - 'a']-- > 0) ans += c;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0) ans += string(cnt[i], i + 'a');
        return ans;
    }
};
```

#### Go

```go
func customSortString(order string, s string) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	ans := []rune{}
	for _, c := range order {
		for cnt[c-'a'] > 0 {
			ans = append(ans, c)
			cnt[c-'a']--
		}
	}
	for i, v := range cnt {
		for j := 0; j < v; j++ {
			ans = append(ans, rune('a'+i))
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function customSortString(order: string, s: string): string {
    const toIndex = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const count = new Array(26).fill(0);
    for (const c of s) {
        count[toIndex(c)]++;
    }
    const ans: string[] = [];
    for (const c of order) {
        const i = toIndex(c);
        ans.push(c.repeat(count[i]));
        count[i] = 0;
    }
    for (let i = 0; i < 26; i++) {
        if (!count[i]) continue;
        ans.push(String.fromCharCode('a'.charCodeAt(0) + i).repeat(count[i]));
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let mut count = [0; 26];
        for c in s.as_bytes() {
            count[(c - b'a') as usize] += 1;
        }
        let mut ans = String::new();
        for c in order.as_bytes() {
            for _ in 0..count[(c - b'a') as usize] {
                ans.push(char::from(*c));
            }
            count[(c - b'a') as usize] = 0;
        }
        for i in 0..count.len() {
            for _ in 0..count[i] {
                ans.push(char::from(b'a' + (i as u8)));
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [792. 匹配子序列的单词数](https://leetcode.cn/problems/number-of-matching-subsequences){#792}

{{< tabs "792" >}}

{{% tab "text" %}}
```text
c: ["cd", "ce"]
b: ["bb"]
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        def check(w):
            i = -1
            for c in w:
                j = bisect_right(d[c], i)
                if j == len(d[c]):
                    return False
                i = d[c][j]
            return True

        d = defaultdict(list)
        for i, c in enumerate(s):
            d[c].append(i)
        return sum(check(w) for w in words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] d = new List[26];

    public int numMatchingSubseq(String s, String[] words) {
        Arrays.setAll(d, k -> new ArrayList<>());
        for (int i = 0; i < s.length(); ++i) {
            d[s.charAt(i) - 'a'].add(i);
        }
        int ans = 0;
        for (String w : words) {
            if (check(w)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(String w) {
        int i = -1;
        for (int k = 0; k < w.length(); ++k) {
            int c = w.charAt(k) - 'a';
            int j = search(d[c], i);
            if (j == d[c].size()) {
                return false;
            }
            i = d[c].get(j);
        }
        return true;
    }

    private int search(List<Integer> t, int x) {
        int left = 0, right = t.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (t.get(mid) > x) {
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
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> d(26);
        for (int i = 0; i < s.size(); ++i) d[s[i] - 'a'].emplace_back(i);
        int ans = 0;
        auto check = [&](string& w) {
            int i = -1;
            for (char& c : w) {
                auto& t = d[c - 'a'];
                int j = upper_bound(t.begin(), t.end(), i) - t.begin();
                if (j == t.size()) return false;
                i = t[j];
            }
            return true;
        };
        for (auto& w : words) ans += check(w);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numMatchingSubseq(s string, words []string) (ans int) {
	d := [26][]int{}
	for i, c := range s {
		d[c-'a'] = append(d[c-'a'], i)
	}
	check := func(w string) bool {
		i := -1
		for _, c := range w {
			t := d[c-'a']
			j := sort.SearchInts(t, i+1)
			if j == len(t) {
				return false
			}
			i = t[j]
		}
		return true
	}
	for _, w := range words {
		if check(w) {
			ans++
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

<p>给定字符串 <code>s</code>&nbsp;和字符串数组&nbsp;<code>words</code>, 返回&nbsp;&nbsp;<em><code>words[i]</code>&nbsp;中是<code>s</code>的子序列的单词个数</em>&nbsp;。</p>

<p>字符串的 <strong>子序列</strong> 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。</p>

<ul>
	<li>例如， <code>“ace”</code> 是 <code>“abcde”</code> 的子序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", words = ["a","bb","acd","ace"]
<strong>输出:</strong> 3
<strong>解释:</strong> 有三个是&nbsp;s 的子序列的单词: "a", "acd", "ace"。
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>输入: </strong>s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
<strong>输出:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>words[i]</code>和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">s</span></font>&nbsp;都只由小写字母组成。</li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​​</span></span></span>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分桶

题目中字符串 $s$ 的数据规模最高达到 $5 \times 10^4$，如果暴力枚举 $words$ 中的每个字符串 $w$，判断其是否为 $s$ 的子序列，很有可能会超时。

我们不妨将 $words$ 中的所有单词根据首字母来分桶，即：把所有单词按照首字母分到 $26$ 个桶中，每个桶中存储的是所有以该字母开头的所有单词。

比如对于 `words = ["a", "bb", "acd", "ace"]`，我们得到以下的分桶结果：

```text
a: ["a", "acd", "ace"]
b: ["bb"]
```

然后我们从 $s$ 的第一个字符开始遍历，假设当前字符为 `'a'`，我们从 `'a'` 开头的桶中取出所有单词。对于取出的每个单词，如果此时单词长度为 $1$，说明该单词已经匹配完毕，我们将答案加 $1$；否则我们将单词的首字母去掉，然后放入下一个字母开头的桶中，比如对于单词 `"acd"`，去掉首字母 `'a'` 后，我们将其放入 `'c'` 开头的桶中。这一轮结束后，分桶结果变为：

```text
c: ["cd", "ce"]
b: ["bb"]
```

遍历完 $s$ 后，我们就得到了答案。

实际上，每个桶可以只存储单词的下标 $i$ 以及该单词当前匹配到的位置 $j$，这样可以节省空间。

时间复杂度 $O(n + \sum_{i=0}^{m-1} |w_i|)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为 $s$ 和 $words$ 的长度，而 $|w_i|$ 为 $words[i]$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        d = defaultdict(deque)
        for w in words:
            d[w[0]].append(w)
        ans = 0
        for c in s:
            for _ in range(len(d[c])):
                t = d[c].popleft()
                if len(t) == 1:
                    ans += 1
                else:
                    d[t[1]].append(t[1:])
        return ans
```

#### Java

```java
class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        Deque<String>[] d = new Deque[26];
        Arrays.setAll(d, k -> new ArrayDeque<>());
        for (String w : words) {
            d[w.charAt(0) - 'a'].add(w);
        }
        int ans = 0;
        for (char c : s.toCharArray()) {
            var q = d[c - 'a'];
            for (int k = q.size(); k > 0; --k) {
                String t = q.pollFirst();
                if (t.length() == 1) {
                    ++ans;
                } else {
                    d[t.charAt(1) - 'a'].offer(t.substring(1));
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
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<string>> d(26);
        for (auto& w : words) d[w[0] - 'a'].emplace(w);
        int ans = 0;
        for (char& c : s) {
            auto& q = d[c - 'a'];
            for (int k = q.size(); k; --k) {
                auto t = q.front();
                q.pop();
                if (t.size() == 1)
                    ++ans;
                else
                    d[t[1] - 'a'].emplace(t.substr(1));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numMatchingSubseq(s string, words []string) (ans int) {
	d := [26][]string{}
	for _, w := range words {
		d[w[0]-'a'] = append(d[w[0]-'a'], w)
	}
	for _, c := range s {
		q := d[c-'a']
		d[c-'a'] = nil
		for _, t := range q {
			if len(t) == 1 {
				ans++
			} else {
				d[t[1]-'a'] = append(d[t[1]-'a'], t[1:])
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

我们还可以先用数组或哈希表 $d$ 存放字符串 $s$ 每个字符的下标，即 $d[c]$ 为 $s$ 中所有字符 $c$ 的下标组成的数组。

然后我们遍历 $words$ 中的每个单词 $w$，我们通过二分查找的方法，判断 $w$ 是否为 $s$ 的子序列，是则答案加 $1$。判断逻辑如下：

1. 定义指针 $i$ 表示当前指向字符串 $s$ 的第 $i$ 个字符，初始化为 $-1$。
1. 遍历字符串 $w$ 中的每个字符 $c$，在 $d[c]$ 中二分查找第一个大于 $i$ 的位置 $j$，如果不存在，则说明 $w$ 不是 $s$ 的子序列，直接跳出循环；否则，将 $i$ 更新为 $d[c][j]$，继续遍历下一个字符。
1. 如果遍历完 $w$ 中的所有字符，说明 $w$ 是 $s$ 的子序列。

时间复杂度 $O(\sum_{i=0}^{m-1} |w_i| \times \log n)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为 $s$ 和 $words$ 的长度，而 $|w_i|$ 为 $words[i]$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        d = defaultdict(deque)
        for i, w in enumerate(words):
            d[w[0]].append((i, 0))
        ans = 0
        for c in s:
            for _ in range(len(d[c])):
                i, j = d[c].popleft()
                j += 1
                if j == len(words[i]):
                    ans += 1
                else:
                    d[words[i][j]].append((i, j))
        return ans
```

#### Java

```java
class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        Deque<int[]>[] d = new Deque[26];
        Arrays.setAll(d, k -> new ArrayDeque<>());
        for (int i = 0; i < words.length; ++i) {
            d[words[i].charAt(0) - 'a'].offer(new int[] {i, 0});
        }
        int ans = 0;
        for (char c : s.toCharArray()) {
            var q = d[c - 'a'];
            for (int t = q.size(); t > 0; --t) {
                var p = q.pollFirst();
                int i = p[0], j = p[1] + 1;
                if (j == words[i].length()) {
                    ++ans;
                } else {
                    d[words[i].charAt(j) - 'a'].offer(new int[] {i, j});
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
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<int, int>>> d(26);
        for (int i = 0; i < words.size(); ++i) d[words[i][0] - 'a'].emplace(i, 0);
        int ans = 0;
        for (char& c : s) {
            auto& q = d[c - 'a'];
            for (int t = q.size(); t; --t) {
                auto [i, j] = q.front();
                q.pop();
                if (++j == words[i].size())
                    ++ans;
                else
                    d[words[i][j] - 'a'].emplace(i, j);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numMatchingSubseq(s string, words []string) (ans int) {
	type pair struct{ i, j int }
	d := [26][]pair{}
	for i, w := range words {
		d[w[0]-'a'] = append(d[w[0]-'a'], pair{i, 0})
	}
	for _, c := range s {
		q := d[c-'a']
		d[c-'a'] = nil
		for _, p := range q {
			i, j := p.i, p.j+1
			if j == len(words[i]) {
				ans++
			} else {
				d[words[i][j]-'a'] = append(d[words[i][j]-'a'], pair{i, j})
			}
		}
	}
	return
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
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        def check(w):
            i = -1
            for c in w:
                j = bisect_right(d[c], i)
                if j == len(d[c]):
                    return False
                i = d[c][j]
            return True

        d = defaultdict(list)
        for i, c in enumerate(s):
            d[c].append(i)
        return sum(check(w) for w in words)
```

#### Java

```java
class Solution {
    private List<Integer>[] d = new List[26];

    public int numMatchingSubseq(String s, String[] words) {
        Arrays.setAll(d, k -> new ArrayList<>());
        for (int i = 0; i < s.length(); ++i) {
            d[s.charAt(i) - 'a'].add(i);
        }
        int ans = 0;
        for (String w : words) {
            if (check(w)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(String w) {
        int i = -1;
        for (int k = 0; k < w.length(); ++k) {
            int c = w.charAt(k) - 'a';
            int j = search(d[c], i);
            if (j == d[c].size()) {
                return false;
            }
            i = d[c].get(j);
        }
        return true;
    }

    private int search(List<Integer> t, int x) {
        int left = 0, right = t.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (t.get(mid) > x) {
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
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> d(26);
        for (int i = 0; i < s.size(); ++i) d[s[i] - 'a'].emplace_back(i);
        int ans = 0;
        auto check = [&](string& w) {
            int i = -1;
            for (char& c : w) {
                auto& t = d[c - 'a'];
                int j = upper_bound(t.begin(), t.end(), i) - t.begin();
                if (j == t.size()) return false;
                i = t[j];
            }
            return true;
        };
        for (auto& w : words) ans += check(w);
        return ans;
    }
};
```

#### Go

```go
func numMatchingSubseq(s string, words []string) (ans int) {
	d := [26][]int{}
	for i, c := range s {
		d[c-'a'] = append(d[c-'a'], i)
	}
	check := func(w string) bool {
		i := -1
		for _, c := range w {
			t := d[c-'a']
			j := sort.SearchInts(t, i+1)
			if j == len(t) {
				return false
			}
			i = t[j]
		}
		return true
	}
	for _, w := range words {
		if check(w) {
			ans++
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

# [793. 阶乘函数后 K 个零](https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function){#793}

{{< tabs "793" >}}

{{% tab "python" %}}
```python
class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        def f(x):
            if x == 0:
                return 0
            return x // 5 + f(x // 5)

        def g(k):
            return bisect_left(range(5 * k), k, key=f)

        return g(k + 1) - g(k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int preimageSizeFZF(int k) {
        return g(k + 1) - g(k);
    }

    private int g(int k) {
        long left = 0, right = 5 * k;
        while (left < right) {
            long mid = (left + right) >> 1;
            if (f(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (int) left;
    }

    private int f(long x) {
        if (x == 0) {
            return 0;
        }
        return (int) (x / 5) + f(x / 5);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int preimageSizeFZF(int k) {
        return g(k + 1) - g(k);
    }

    int g(int k) {
        long long left = 0, right = 1ll * 5 * k;
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (f(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (int) left;
    }

    int f(long x) {
        int res = 0;
        while (x) {
            x /= 5;
            res += x;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func preimageSizeFZF(k int) int {
	f := func(x int) int {
		res := 0
		for x != 0 {
			x /= 5
			res += x
		}
		return res
	}

	g := func(k int) int {
		left, right := 0, k*5
		for left < right {
			mid := (left + right) >> 1
			if f(mid) >= k {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}

	return g(k+1) - g(k)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>&nbsp;<code>f(x)</code>&nbsp;是&nbsp;<code>x!</code>&nbsp;末尾是 0 的数量。回想一下&nbsp;<code>x! = 1 * 2 * 3 * ... * x</code>，且 <code>0! = 1</code>&nbsp;。</p>

<ul>
	<li>例如，&nbsp;<code>f(3) = 0</code>&nbsp;，因为 <code>3! = 6</code> 的末尾没有 0 ；而 <code>f(11) = 2</code>&nbsp;，因为 <code>11!= 39916800</code> 末端有 2 个 0 。</li>
</ul>

<p>给定&nbsp;<code>k</code>，找出返回能满足 <code>f(x) = k</code>&nbsp;的非负整数 <code>x</code>&nbsp;的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong><strong> </strong></p>

<pre>
<strong>输入：</strong>k = 0<strong>
输出：</strong>5<strong>
解释：</strong>0!, 1!, 2!, 3!, 和 4!&nbsp;均符合 k = 0 的条件。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 5
<strong>输出：</strong>0
<strong>解释：</strong>没有匹配到这样的 x!，符合 k = 5 的条件。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> k = 3
<strong>输出:</strong> 5
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

定义 $f(x)$ 为 $x!$ 末尾零的个数，那么

$$
f(x)=
\begin{cases}
0, x=0\\
x/5+f(x/5), x>0
\end{cases}
$$

定义 $g(k)$ 表示 $x!$ 末尾为零的个数为 $k$ 的最小的 $x$ 值，那么题目等价于求解 $g(k+1)-g(k)$。

由于 $g(k)$ 是单调递增的，因此可以使用二分查找求解 $g(k)$。

同时，由于 $f(x)=x/5+f(x/5) \ge x/5$，因此 $f(5k)\ge k$。所以，求解 $g(k)$ 时，二分的右边界可以取 $5k$。

时间复杂度 $O(log^2k)$，其中 $k$ 为题目给定的整数。二分查找 $g(k)$ 的时间复杂度为 $O(logk)$，计算 $f(x)$ 的时间复杂度为 $O(logx)$，因此总时间复杂度为 $O(log^2k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        def f(x):
            if x == 0:
                return 0
            return x // 5 + f(x // 5)

        def g(k):
            return bisect_left(range(5 * k), k, key=f)

        return g(k + 1) - g(k)
```

#### Java

```java
class Solution {
    public int preimageSizeFZF(int k) {
        return g(k + 1) - g(k);
    }

    private int g(int k) {
        long left = 0, right = 5 * k;
        while (left < right) {
            long mid = (left + right) >> 1;
            if (f(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (int) left;
    }

    private int f(long x) {
        if (x == 0) {
            return 0;
        }
        return (int) (x / 5) + f(x / 5);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int preimageSizeFZF(int k) {
        return g(k + 1) - g(k);
    }

    int g(int k) {
        long long left = 0, right = 1ll * 5 * k;
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (f(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (int) left;
    }

    int f(long x) {
        int res = 0;
        while (x) {
            x /= 5;
            res += x;
        }
        return res;
    }
};
```

#### Go

```go
func preimageSizeFZF(k int) int {
	f := func(x int) int {
		res := 0
		for x != 0 {
			x /= 5
			res += x
		}
		return res
	}

	g := func(k int) int {
		left, right := 0, k*5
		for left < right {
			mid := (left + right) >> 1
			if f(mid) >= k {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}

	return g(k+1) - g(k)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [794. 有效的井字游戏](https://leetcode.cn/problems/valid-tic-tac-toe-state){#794}

{{< tabs "794" >}}

{{% tab "python" %}}
```python
class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        def win(x):
            for i in range(3):
                if all(board[i][j] == x for j in range(3)):
                    return True
                if all(board[j][i] == x for j in range(3)):
                    return True
            if all(board[i][i] == x for i in range(3)):
                return True
            return all(board[i][2 - i] == x for i in range(3))

        x = sum(board[i][j] == 'X' for i in range(3) for j in range(3))
        o = sum(board[i][j] == 'O' for i in range(3) for j in range(3))
        if x != o and x - 1 != o:
            return False
        if win('X') and x - 1 != o:
            return False
        return not (win('O') and x != o)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String[] board;

    public boolean validTicTacToe(String[] board) {
        this.board = board;
        int x = count('X'), o = count('O');
        if (x != o && x - 1 != o) {
            return false;
        }
        if (win('X') && x - 1 != o) {
            return false;
        }
        return !(win('O') && x != o);
    }

    private boolean win(char x) {
        for (int i = 0; i < 3; ++i) {
            if (board[i].charAt(0) == x && board[i].charAt(1) == x && board[i].charAt(2) == x) {
                return true;
            }
            if (board[0].charAt(i) == x && board[1].charAt(i) == x && board[2].charAt(i) == x) {
                return true;
            }
        }
        if (board[0].charAt(0) == x && board[1].charAt(1) == x && board[2].charAt(2) == x) {
            return true;
        }
        return board[0].charAt(2) == x && board[1].charAt(1) == x && board[2].charAt(0) == x;
    }

    private int count(char x) {
        int cnt = 0;
        for (var row : board) {
            for (var c : row.toCharArray()) {
                if (c == x) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        auto count = [&](char x) {
            int ans = 0;
            for (auto& row : board)
                for (auto& c : row) ans += c == x;
            return ans;
        };
        auto win = [&](char x) {
            for (int i = 0; i < 3; ++i) {
                if (board[i][0] == x && board[i][1] == x && board[i][2] == x) return true;
                if (board[0][i] == x && board[1][i] == x && board[2][i] == x) return true;
            }
            if (board[0][0] == x && board[1][1] == x && board[2][2] == x) return true;
            return board[0][2] == x && board[1][1] == x && board[2][0] == x;
        };
        int x = count('X'), o = count('O');
        if (x != o && x - 1 != o) return false;
        if (win('X') && x - 1 != o) return false;
        return !(win('O') && x != o);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validTicTacToe(board []string) bool {
	var x, o int
	for _, row := range board {
		for _, c := range row {
			if c == 'X' {
				x++
			} else if c == 'O' {
				o++
			}
		}
	}
	win := func(x byte) bool {
		for i := 0; i < 3; i++ {
			if board[i][0] == x && board[i][1] == x && board[i][2] == x {
				return true
			}
			if board[0][i] == x && board[1][i] == x && board[2][i] == x {
				return true
			}
		}
		if board[0][0] == x && board[1][1] == x && board[2][2] == x {
			return true
		}
		return board[0][2] == x && board[1][1] == x && board[2][0] == x
	}
	if x != o && x-1 != o {
		return false
	}
	if win('X') && x-1 != o {
		return false
	}
	return !(win('O') && x != o)
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[]} board
 * @return {boolean}
 */
var validTicTacToe = function (board) {
    function count(x) {
        let cnt = 0;
        for (const row of board) {
            for (const c of row) {
                cnt += c == x;
            }
        }
        return cnt;
    }
    function win(x) {
        for (let i = 0; i < 3; ++i) {
            if (board[i][0] == x && board[i][1] == x && board[i][2] == x) {
                return true;
            }
            if (board[0][i] == x && board[1][i] == x && board[2][i] == x) {
                return true;
            }
        }
        if (board[0][0] == x && board[1][1] == x && board[2][2] == x) {
            return true;
        }
        return board[0][2] == x && board[1][1] == x && board[2][0] == x;
    }
    const [x, o] = [count('X'), count('O')];
    if (x != o && x - 1 != o) {
        return false;
    }
    if (win('X') && x - 1 != o) {
        return false;
    }
    return !(win('O') && x != o);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>board</code> 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 <code>board</code> 所显示的状态时，才返回 <code>true</code> 。</p>

<p>井字游戏的棋盘是一个 <code>3 x 3</code> 数组，由字符 <code>' '</code>，<code>'X'</code> 和 <code>'O'</code> 组成。字符 <code>' '</code> 代表一个空位。</p>

<p>以下是井字游戏的规则：</p>

<ul>
	<li>玩家轮流将字符放入空位（<code>' '</code>）中。</li>
	<li>玩家 1 总是放字符 <code>'X'</code> ，而玩家 2 总是放字符 <code>'O'</code> 。</li>
	<li><code>'X'</code> 和 <code>'O'</code> 只允许放置在空位中，不允许对已放有字符的位置进行填充。</li>
	<li>当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。</li>
	<li>当所有位置非空时，也算为游戏结束。</li>
	<li>如果游戏结束，玩家不允许再放置字符。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0794.Valid%20Tic-Tac-Toe%20State/images/tictactoe1-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>board = ["O  ","   ","   "]
<strong>输出：</strong>false
<strong>解释：</strong>玩家 1 总是放字符 "X" 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0794.Valid%20Tic-Tac-Toe%20State/images/tictactoe2-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>board = ["XOX"," X ","   "]
<strong>输出：</strong>false
<strong>解释：</strong>玩家应该轮流放字符。
</pre>

<p><strong>示例 3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0794.Valid%20Tic-Tac-Toe%20State/images/tictactoe4-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>board = ["XOX","O O","XOX"]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board.length == 3</code></li>
	<li><code>board[i].length == 3</code></li>
	<li><code>board[i][j]</code> 为 <code>'X'</code>、<code>'O'</code> 或 <code>' '</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

我们先统计当前棋盘上 `'X'` 和 `'O'` 的数量，记为 $x$ 和 $o$。接下来，我们分情况讨论：

-   如果 $x \neq o$ 且 $x - 1 \neq o$，则当前棋盘不可能是有效棋盘，返回 `false`。
-   如果当前棋盘上玩家 1 获胜，但 $x-1 \neq o$，则当前棋盘不可能是有效棋盘，返回 `false`。
-   如果当前棋盘上玩家 2 获胜，但 $x \neq o$，则当前棋盘不可能是有效棋盘，返回 `false`。
-   其他情况下，当前棋盘是有效棋盘，返回 `true`。

时间复杂度 $O(C)$，空间复杂度 $O(1)$。其中 $C$ 是棋盘上的格子数。本题中 $C = 9$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        def win(x):
            for i in range(3):
                if all(board[i][j] == x for j in range(3)):
                    return True
                if all(board[j][i] == x for j in range(3)):
                    return True
            if all(board[i][i] == x for i in range(3)):
                return True
            return all(board[i][2 - i] == x for i in range(3))

        x = sum(board[i][j] == 'X' for i in range(3) for j in range(3))
        o = sum(board[i][j] == 'O' for i in range(3) for j in range(3))
        if x != o and x - 1 != o:
            return False
        if win('X') and x - 1 != o:
            return False
        return not (win('O') and x != o)
```

#### Java

```java
class Solution {
    private String[] board;

    public boolean validTicTacToe(String[] board) {
        this.board = board;
        int x = count('X'), o = count('O');
        if (x != o && x - 1 != o) {
            return false;
        }
        if (win('X') && x - 1 != o) {
            return false;
        }
        return !(win('O') && x != o);
    }

    private boolean win(char x) {
        for (int i = 0; i < 3; ++i) {
            if (board[i].charAt(0) == x && board[i].charAt(1) == x && board[i].charAt(2) == x) {
                return true;
            }
            if (board[0].charAt(i) == x && board[1].charAt(i) == x && board[2].charAt(i) == x) {
                return true;
            }
        }
        if (board[0].charAt(0) == x && board[1].charAt(1) == x && board[2].charAt(2) == x) {
            return true;
        }
        return board[0].charAt(2) == x && board[1].charAt(1) == x && board[2].charAt(0) == x;
    }

    private int count(char x) {
        int cnt = 0;
        for (var row : board) {
            for (var c : row.toCharArray()) {
                if (c == x) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        auto count = [&](char x) {
            int ans = 0;
            for (auto& row : board)
                for (auto& c : row) ans += c == x;
            return ans;
        };
        auto win = [&](char x) {
            for (int i = 0; i < 3; ++i) {
                if (board[i][0] == x && board[i][1] == x && board[i][2] == x) return true;
                if (board[0][i] == x && board[1][i] == x && board[2][i] == x) return true;
            }
            if (board[0][0] == x && board[1][1] == x && board[2][2] == x) return true;
            return board[0][2] == x && board[1][1] == x && board[2][0] == x;
        };
        int x = count('X'), o = count('O');
        if (x != o && x - 1 != o) return false;
        if (win('X') && x - 1 != o) return false;
        return !(win('O') && x != o);
    }
};
```

#### Go

```go
func validTicTacToe(board []string) bool {
	var x, o int
	for _, row := range board {
		for _, c := range row {
			if c == 'X' {
				x++
			} else if c == 'O' {
				o++
			}
		}
	}
	win := func(x byte) bool {
		for i := 0; i < 3; i++ {
			if board[i][0] == x && board[i][1] == x && board[i][2] == x {
				return true
			}
			if board[0][i] == x && board[1][i] == x && board[2][i] == x {
				return true
			}
		}
		if board[0][0] == x && board[1][1] == x && board[2][2] == x {
			return true
		}
		return board[0][2] == x && board[1][1] == x && board[2][0] == x
	}
	if x != o && x-1 != o {
		return false
	}
	if win('X') && x-1 != o {
		return false
	}
	return !(win('O') && x != o)
}
```

#### JavaScript

```js
/**
 * @param {string[]} board
 * @return {boolean}
 */
var validTicTacToe = function (board) {
    function count(x) {
        let cnt = 0;
        for (const row of board) {
            for (const c of row) {
                cnt += c == x;
            }
        }
        return cnt;
    }
    function win(x) {
        for (let i = 0; i < 3; ++i) {
            if (board[i][0] == x && board[i][1] == x && board[i][2] == x) {
                return true;
            }
            if (board[0][i] == x && board[1][i] == x && board[2][i] == x) {
                return true;
            }
        }
        if (board[0][0] == x && board[1][1] == x && board[2][2] == x) {
            return true;
        }
        return board[0][2] == x && board[1][1] == x && board[2][0] == x;
    }
    const [x, o] = [count('X'), count('O')];
    if (x != o && x - 1 != o) {
        return false;
    }
    if (win('X') && x - 1 != o) {
        return false;
    }
    return !(win('O') && x != o);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [795. 区间子数组个数](https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum){#795}

{{< tabs "795" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        n = len(nums)
        l, r = [-1] * n, [n] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] <= v:
                stk.pop()
            if stk:
                l[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] < nums[i]:
                stk.pop()
            if stk:
                r[i] = stk[-1]
            stk.append(i)
        return sum(
            (i - l[i]) * (r[i] - i) for i, v in enumerate(nums) if left <= v <= right
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int n = nums.length;
        int[] l = new int[n];
        int[] r = new int[n];
        Arrays.fill(l, -1);
        Arrays.fill(r, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] <= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                l[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] < v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                r[i] = stk.peek();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left <= nums[i] && nums[i] <= right) {
                ans += (i - l[i]) * (r[i] - i);
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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> l(n, -1);
        vector<int> r(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] <= v) stk.pop();
            if (!stk.empty()) l[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] < v) stk.pop();
            if (!stk.empty()) r[i] = stk.top();
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left <= nums[i] && nums[i] <= right) {
                ans += (i - l[i]) * (r[i] - i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSubarrayBoundedMax(nums []int, left int, right int) (ans int) {
	n := len(nums)
	l := make([]int, n)
	r := make([]int, n)
	for i := range l {
		l[i], r[i] = -1, n
	}
	stk := []int{}
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			l[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		v := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] < v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			r[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, v := range nums {
		if left <= v && v <= right {
			ans += (i - l[i]) * (r[i] - i)
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

<p>给你一个整数数组 <code>nums</code> 和两个整数：<code>left</code> 及 <code>right</code> 。找出 <code>nums</code> 中连续、非空且其中最大元素在范围&nbsp;<code>[left, right]</code> 内的子数组，并返回满足条件的子数组的个数。</p>

<p>生成的测试用例保证结果符合 <strong>32-bit</strong> 整数范围。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,4,3], left = 2, right = 3
<strong>输出：</strong>3
<strong>解释：</strong>满足条件的三个子数组：[2], [2, 1], [3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,9,2,5,6], left = 2, right = 8
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：区间计数

题目要我们统计数组 `nums` 中，最大值在区间 $[left, right]$ 范围内的子数组个数。

对于区间 $[left,..right]$ 问题，我们可以考虑将其转换为 $[0,..right]$ 然后再减去 $[0,..left-1]$ 的问题。也就是说，所有最大元素不超过 $right$ 的子数组个数，减去所有最大元素不超过 $left-1$ 的子数组个数，剩下的就是最大元素在区间 $[left,..right]$ 范围内的子数组个数，即题目要求的结果。

$$
ans = \sum_{i=0}^{right} ans_i -  \sum_{i=0}^{left-1} ans_i
$$

对于本题，我们设计一个函数 $f(x)$，表示数组 `nums` 中，最大值不超过 $x$ 的子数组个数。那么答案为 $f(right) - f(left-1)$。函数 $f(x)$ 的执行逻辑如下：

-   用变量 $cnt$ 记录最大值不超过 $x$ 的子数组的个数，用 $t$ 记录当前子数组的长度。
-   遍历数组 `nums`，对于每个元素 $nums[i]$，如果 $nums[i] \leq x$，则当前子数组的长度加一，即 $t=t+1$，否则当前子数组的长度重置为 0，即 $t=0$。然后将当前子数组的长度加到 $cnt$ 中，即 $cnt = cnt + t$。
-   遍历结束，将 $cnt$ 返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        def f(x):
            cnt = t = 0
            for v in nums:
                t = 0 if v > x else t + 1
                cnt += t
            return cnt

        return f(right) - f(left - 1)
```

#### Java

```java
class Solution {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        return f(nums, right) - f(nums, left - 1);
    }

    private int f(int[] nums, int x) {
        int cnt = 0, t = 0;
        for (int v : nums) {
            t = v > x ? 0 : t + 1;
            cnt += t;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        auto f = [&](int x) {
            int cnt = 0, t = 0;
            for (int& v : nums) {
                t = v > x ? 0 : t + 1;
                cnt += t;
            }
            return cnt;
        };
        return f(right) - f(left - 1);
    }
};
```

#### Go

```go
func numSubarrayBoundedMax(nums []int, left int, right int) int {
	f := func(x int) (cnt int) {
		t := 0
		for _, v := range nums {
			t++
			if v > x {
				t = 0
			}
			cnt += t
		}
		return
	}
	return f(right) - f(left-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调栈 + 枚举元素计算贡献

我们还可以枚举数组中每个元素 $nums[i]$ 作为子数组的最大值，然后统计以该元素为最大值的子数组的个数。问题转化为求出每个元素 $nums[i]$ 左侧第一个大于该元素的下标 $l[i]$，右侧第一个大于等于该元素的下标 $r[i]$，则以该元素为最大值的子数组的个数为 $(i - l[i]) \times (r[i] - i)$。

我们可以使用单调栈方便地求出 $l[i]$ 和 $r[i]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

相似题目：

-   [907. 子数组的最小值之和](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0907.Sum%20of%20Subarray%20Minimums/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        n = len(nums)
        l, r = [-1] * n, [n] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] <= v:
                stk.pop()
            if stk:
                l[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] < nums[i]:
                stk.pop()
            if stk:
                r[i] = stk[-1]
            stk.append(i)
        return sum(
            (i - l[i]) * (r[i] - i) for i, v in enumerate(nums) if left <= v <= right
        )
```

#### Java

```java
class Solution {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int n = nums.length;
        int[] l = new int[n];
        int[] r = new int[n];
        Arrays.fill(l, -1);
        Arrays.fill(r, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] <= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                l[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] < v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                r[i] = stk.peek();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left <= nums[i] && nums[i] <= right) {
                ans += (i - l[i]) * (r[i] - i);
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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> l(n, -1);
        vector<int> r(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] <= v) stk.pop();
            if (!stk.empty()) l[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] < v) stk.pop();
            if (!stk.empty()) r[i] = stk.top();
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left <= nums[i] && nums[i] <= right) {
                ans += (i - l[i]) * (r[i] - i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numSubarrayBoundedMax(nums []int, left int, right int) (ans int) {
	n := len(nums)
	l := make([]int, n)
	r := make([]int, n)
	for i := range l {
		l[i], r[i] = -1, n
	}
	stk := []int{}
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			l[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		v := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] < v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			r[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, v := range nums {
		if left <= v && v <= right {
			ans += (i - l[i]) * (r[i] - i)
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

# [796. 旋转字符串](https://leetcode.cn/problems/rotate-string){#796}

{{< tabs "796" >}}

{{% tab "python" %}}
```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in s + s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean rotateString(String s, String goal) {
        return s.length() == goal.length() && (s + s).contains(goal);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && strstr((s + s).data(), goal.data());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rotateString(s string, goal string) bool {
	return len(s) == len(goal) && strings.Contains(s+s, goal)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rotateString(s: string, goal: string): boolean {
    return s.length === goal.length && (goal + goal).includes(s);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        s.len() == goal.len() && (s.clone() + &s).contains(&goal)
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @param String $goal
     * @return Boolean
     */
    function rotateString($s, $goal) {
        return strlen($goal) === strlen($s) && strpos($s . $s, $goal) !== false;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串, <code>s</code>&nbsp;和&nbsp;<code>goal</code>。如果在若干次旋转操作之后，<code>s</code>&nbsp;能变成&nbsp;<code>goal</code>&nbsp;，那么返回&nbsp;<code>true</code>&nbsp;。</p>

<p><code>s</code>&nbsp;的 <strong>旋转操作</strong> 就是将&nbsp;<code>s</code> 最左边的字符移动到最右边。&nbsp;</p>

<ul>
	<li>例如, 若&nbsp;<code>s = 'abcde'</code>，在旋转一次之后结果就是<code>'bcdea'</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", goal = "cdeab"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", goal = "abced"
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, goal.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>goal</code>&nbsp;由小写英文字母组成</li>
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
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in s + s
```

#### Java

```java
class Solution {
    public boolean rotateString(String s, String goal) {
        return s.length() == goal.length() && (s + s).contains(goal);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && strstr((s + s).data(), goal.data());
    }
};
```

#### Go

```go
func rotateString(s string, goal string) bool {
	return len(s) == len(goal) && strings.Contains(s+s, goal)
}
```

#### TypeScript

```ts
function rotateString(s: string, goal: string): boolean {
    return s.length === goal.length && (goal + goal).includes(s);
}
```

#### Rust

```rust
impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        s.len() == goal.len() && (s.clone() + &s).contains(&goal)
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @param String $goal
     * @return Boolean
     */
    function rotateString($s, $goal) {
        return strlen($goal) === strlen($s) && strpos($s . $s, $goal) !== false;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [797. 所有可能的路径](https://leetcode.cn/problems/all-paths-from-source-to-target){#797}

{{< tabs "797" >}}

{{% tab "python" %}}
```python
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(t):
            if t[-1] == len(graph) - 1:
                ans.append(t[:])
                return
            for v in graph[t[-1]]:
                t.append(v)
                dfs(t)
                t.pop()

        ans = []
        dfs([0])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<Integer>> ans;
    private int[][] graph;

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        ans = new ArrayList<>();
        this.graph = graph;
        List<Integer> t = new ArrayList<>();
        t.add(0);
        dfs(t);
        return ans;
    }

    private void dfs(List<Integer> t) {
        int cur = t.get(t.size() - 1);
        if (cur == graph.length - 1) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int v : graph[cur]) {
            t.add(v);
            dfs(t);
            t.remove(t.size() - 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> ans;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        vector<int> path;
        path.push_back(0);
        dfs(0, path);
        return ans;
    }

    void dfs(int i, vector<int> path) {
        if (i == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        for (int j : graph[i]) {
            path.push_back(j);
            dfs(j, path);
            path.pop_back();
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func allPathsSourceTarget(graph [][]int) [][]int {
	var path []int
	path = append(path, 0)
	var ans [][]int

	var dfs func(i int)
	dfs = func(i int) {
		if i == len(graph)-1 {
			ans = append(ans, append([]int(nil), path...))
			return
		}
		for _, j := range graph[i] {
			path = append(path, j)
			dfs(j)
			path = path[:len(path)-1]
		}
	}

	dfs(0)
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(i: usize, path: &mut Vec<i32>, res: &mut Vec<Vec<i32>>, graph: &Vec<Vec<i32>>) {
        path.push(i as i32);
        if i == graph.len() - 1 {
            res.push(path.clone());
        }
        for j in graph[i].iter() {
            Self::dfs(*j as usize, path, res, graph);
        }
        path.pop();
    }

    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        Self::dfs(0, &mut vec![], &mut res, &graph);
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
var allPathsSourceTarget = function (graph) {
    const ans = [];
    const t = [0];

    const dfs = t => {
        const cur = t[t.length - 1];
        if (cur == graph.length - 1) {
            ans.push([...t]);
            return;
        }
        for (const v of graph[cur]) {
            t.push(v);
            dfs(t);
            t.pop();
        }
    };

    dfs(t);
    return ans;
};
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function allPathsSourceTarget(graph: number[][]): number[][] {
    const ans: number[][] = [];

    const dfs = (path: number[]) => {
        const curr = path.at(-1)!;
        if (curr === graph.length - 1) {
            ans.push([...path]);
            return;
        }

        for (const v of graph[curr]) {
            path.push(v);
            dfs(path);
            path.pop();
        }
    };

    dfs([0]);

    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个有&nbsp;<code>n</code>&nbsp;个节点的 <strong>有向无环图（DAG）</strong>，请你找出从节点 <code>0</code>&nbsp;到节点 <code>n-1</code>&nbsp;的所有路径并输出（<strong>不要求按特定顺序</strong>）</p>

<p><meta charset="UTF-8" />&nbsp;<code>graph[i]</code>&nbsp;是一个从节点 <code>i</code> 可以访问的所有节点的列表（即从节点 <code>i</code> 到节点&nbsp;<code>graph[i][j]</code>存在一条有向边）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0797.All%20Paths%20From%20Source%20to%20Target/images/all_1.jpg" /></p>

<pre>
<strong>输入：</strong>graph = [[1,2],[3],[3],[]]
<strong>输出：</strong>[[0,1,3],[0,2,3]]
<strong>解释：</strong>有两条路径 0 -&gt; 1 -&gt; 3 和 0 -&gt; 2 -&gt; 3
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0797.All%20Paths%20From%20Source%20to%20Target/images/all_2.jpg" /></p>

<pre>
<strong>输入：</strong>graph = [[4,3,1],[3,2,4],[3],[4],[]]
<strong>输出：</strong>[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>0 &lt;= graph[i][j] &lt; n</code></li>
	<li><code>graph[i][j] != i</code>（即不存在自环）</li>
	<li><code>graph[i]</code> 中的所有元素 <strong>互不相同</strong></li>
	<li>保证输入为 <strong>有向无环图（DAG）</strong></li>
</ul>

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
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        q = deque([[0]])
        ans = []
        while q:
            path = q.popleft()
            u = path[-1]
            if u == n - 1:
                ans.append(path)
                continue
            for v in graph[u]:
                q.append(path + [v])
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;
        Queue<List<Integer>> queue = new ArrayDeque<>();
        queue.offer(Arrays.asList(0));
        List<List<Integer>> ans = new ArrayList<>();
        while (!queue.isEmpty()) {
            List<Integer> path = queue.poll();
            int u = path.get(path.size() - 1);
            if (u == n - 1) {
                ans.add(path);
                continue;
            }
            for (int v : graph[u]) {
                List<Integer> next = new ArrayList<>(path);
                next.add(v);
                queue.offer(next);
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
    vector<vector<int>> graph;
    vector<vector<int>> ans;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        vector<int> path;
        path.push_back(0);
        dfs(0, path);
        return ans;
    }

    void dfs(int i, vector<int> path) {
        if (i == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        for (int j : graph[i]) {
            path.push_back(j);
            dfs(j, path);
            path.pop_back();
        }
    }
};
```

#### Go

```go
func allPathsSourceTarget(graph [][]int) [][]int {
	var path []int
	path = append(path, 0)
	var ans [][]int

	var dfs func(i int)
	dfs = func(i int) {
		if i == len(graph)-1 {
			ans = append(ans, append([]int(nil), path...))
			return
		}
		for _, j := range graph[i] {
			path = append(path, j)
			dfs(j)
			path = path[:len(path)-1]
		}
	}

	dfs(0)
	return ans
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, path: &mut Vec<i32>, res: &mut Vec<Vec<i32>>, graph: &Vec<Vec<i32>>) {
        path.push(i as i32);
        if i == graph.len() - 1 {
            res.push(path.clone());
        }
        for j in graph[i].iter() {
            Self::dfs(*j as usize, path, res, graph);
        }
        path.pop();
    }

    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        Self::dfs(0, &mut vec![], &mut res, &graph);
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
var allPathsSourceTarget = function (graph) {
    const ans = [];
    const t = [0];

    const dfs = t => {
        const cur = t[t.length - 1];
        if (cur == graph.length - 1) {
            ans.push([...t]);
            return;
        }
        for (const v of graph[cur]) {
            t.push(v);
            dfs(t);
            t.pop();
        }
    };

    dfs(t);
    return ans;
};
```

#### TypeScript

```ts
function allPathsSourceTarget(graph: number[][]): number[][] {
    const ans: number[][] = [];

    const dfs = (path: number[]) => {
        const curr = path.at(-1)!;
        if (curr === graph.length - 1) {
            ans.push([...path]);
            return;
        }

        for (const v of graph[curr]) {
            path.push(v);
            dfs(path);
            path.pop();
        }
    };

    dfs([0]);

    return ans;
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
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(t):
            if t[-1] == len(graph) - 1:
                ans.append(t[:])
                return
            for v in graph[t[-1]]:
                t.append(v)
                dfs(t)
                t.pop()

        ans = []
        dfs([0])
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans;
    private int[][] graph;

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        ans = new ArrayList<>();
        this.graph = graph;
        List<Integer> t = new ArrayList<>();
        t.add(0);
        dfs(t);
        return ans;
    }

    private void dfs(List<Integer> t) {
        int cur = t.get(t.size() - 1);
        if (cur == graph.length - 1) {
            ans.add(new ArrayList<>(t));
            return;
        }
        for (int v : graph[cur]) {
            t.add(v);
            dfs(t);
            t.remove(t.size() - 1);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [798. 得分最高的最小轮调](https://leetcode.cn/problems/smallest-rotation-with-highest-score){#798}

{{< tabs "798" >}}

{{% tab "python" %}}
```python
class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        mx, ans = -1, n
        d = [0] * n
        for i, v in enumerate(nums):
            l, r = (i + 1) % n, (n + i + 1 - v) % n
            d[l] += 1
            d[r] -= 1
        s = 0
        for k, t in enumerate(d):
            s += t
            if s > mx:
                mx = s
                ans = k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int bestRotation(int[] nums) {
        int n = nums.length;
        int[] d = new int[n];
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (n + i + 1 - nums[i]) % n;
            ++d[l];
            --d[r];
        }
        int mx = -1;
        int s = 0;
        int ans = n;
        for (int k = 0; k < n; ++k) {
            s += d[k];
            if (s > mx) {
                mx = s;
                ans = k;
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
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        int mx = -1, ans = n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (n + i + 1 - nums[i]) % n;
            ++d[l];
            --d[r];
        }
        int s = 0;
        for (int k = 0; k < n; ++k) {
            s += d[k];
            if (s > mx) {
                mx = s;
                ans = k;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func bestRotation(nums []int) int {
	n := len(nums)
	d := make([]int, n)
	for i, v := range nums {
		l, r := (i+1)%n, (n+i+1-v)%n
		d[l]++
		d[r]--
	}
	mx, ans, s := -1, n, 0
	for k, t := range d {
		s += t
		if s > mx {
			mx = s
			ans = k
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

<p>给你一个数组&nbsp;<code>nums</code>，我们可以将它按一个非负整数 <code>k</code> 进行轮调，这样可以使数组变为&nbsp;<code>[nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]]</code>&nbsp;的形式。此后，任何值小于或等于其索引的项都可以记作一分。</p>

<ul>
	<li>例如，数组为&nbsp;<code>nums = [2,4,1,3,0]</code>，我们按&nbsp;<code>k = 2</code>&nbsp;进行轮调后，它将变成&nbsp;<code>[1,3,0,2,4]</code>。这将记为 <code>3</code> 分，因为 <code>1 &gt; 0</code> [不计分]、<code>3 &gt; 1</code> [不计分]、<code>0 &lt;= 2</code> [计 1 分]、<code>2 &lt;= 3</code> [计 1 分]，<code>4 &lt;= 4</code> [计 1 分]。</li>
</ul>

<p>在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调下标 <code>k</code> 。如果有多个答案，返回满足条件的最小的下标 <code>k</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,1,4,0]
<strong>输出：</strong>3
<strong>解释：</strong>
下面列出了每个 k 的得分：
k = 0,  nums = [2,3,1,4,0],    score 2
k = 1,  nums = [3,1,4,0,2],    score 3
k = 2,  nums = [1,4,0,2,3],    score 3
k = 3,  nums = [4,0,2,3,1],    score 4
k = 4,  nums = [0,2,3,1,4],    score 3
所以我们应当选择&nbsp;k = 3，得分最高。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,0,2,4]
<strong>输出：</strong>0
<strong>解释：</strong>
nums 无论怎么变化总是有 3 分。
所以我们将选择最小的 k，即 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

对于每个数，都有一个固定的 k 生效区间。我们先利用差分，预处理每个数的 k 生效区间。有最多个数能覆盖到的 k 即是答案。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        mx, ans = -1, n
        d = [0] * n
        for i, v in enumerate(nums):
            l, r = (i + 1) % n, (n + i + 1 - v) % n
            d[l] += 1
            d[r] -= 1
        s = 0
        for k, t in enumerate(d):
            s += t
            if s > mx:
                mx = s
                ans = k
        return ans
```

#### Java

```java
class Solution {
    public int bestRotation(int[] nums) {
        int n = nums.length;
        int[] d = new int[n];
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (n + i + 1 - nums[i]) % n;
            ++d[l];
            --d[r];
        }
        int mx = -1;
        int s = 0;
        int ans = n;
        for (int k = 0; k < n; ++k) {
            s += d[k];
            if (s > mx) {
                mx = s;
                ans = k;
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
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        int mx = -1, ans = n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (n + i + 1 - nums[i]) % n;
            ++d[l];
            --d[r];
        }
        int s = 0;
        for (int k = 0; k < n; ++k) {
            s += d[k];
            if (s > mx) {
                mx = s;
                ans = k;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func bestRotation(nums []int) int {
	n := len(nums)
	d := make([]int, n)
	for i, v := range nums {
		l, r := (i+1)%n, (n+i+1-v)%n
		d[l]++
		d[r]--
	}
	mx, ans, s := -1, n, 0
	for k, t := range d {
		s += t
		if s > mx {
			mx = s
			ans = k
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

# [799. 香槟塔](https://leetcode.cn/problems/champagne-tower){#799}

{{< tabs "799" >}}

{{% tab "python" %}}
```python
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        f = [poured]
        for i in range(1, query_row + 1):
            g = [0] * (i + 1)
            for j, v in enumerate(f):
                if v > 1:
                    half = (v - 1) / 2
                    g[j] += half
                    g[j + 1] += half
            f = g
        return min(1, f[query_glass])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[] f = {poured};
        for (int i = 1; i <= query_row; ++i) {
            double[] g = new double[i + 1];
            for (int j = 0; j < i; ++j) {
                if (f[j] > 1) {
                    double half = (f[j] - 1) / 2.0;
                    g[j] += half;
                    g[j + 1] += half;
                }
            }
            f = g;
        }
        return Math.min(1, f[query_glass]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double f[101] = {(double) poured};
        double g[101];
        for (int i = 1; i <= query_row; ++i) {
            memset(g, 0, sizeof g);
            for (int j = 0; j < i; ++j) {
                if (f[j] > 1) {
                    double half = (f[j] - 1) / 2.0;
                    g[j] += half;
                    g[j + 1] += half;
                }
            }
            memcpy(f, g, sizeof g);
        }
        return min(1.0, f[query_glass]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func champagneTower(poured int, query_row int, query_glass int) float64 {
	f := []float64{float64(poured)}
	for i := 1; i <= query_row; i++ {
		g := make([]float64, i+1)
		for j, v := range f {
			if v > 1 {
				half := (v - 1) / 2.0
				g[j] += half
				g[j+1] += half
			}
		}
		f = g
	}
	return math.Min(1, f[query_glass])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function champagneTower(poured: number, query_row: number, query_glass: number): number {
    let row = [poured];
    for (let i = 1; i <= query_row; i++) {
        const nextRow = new Array(i + 1).fill(0);
        for (let j = 0; j < i; j++) {
            if (row[j] > 1) {
                nextRow[j] += (row[j] - 1) / 2;
                nextRow[j + 1] += (row[j] - 1) / 2;
            }
        }
        row = nextRow;
    }
    return Math.min(1, row[query_glass]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let query_row = query_row as usize;
        let query_glass = query_glass as usize;
        let mut row = vec![poured as f64];
        for i in 1..=query_row {
            let mut next_row = vec![0f64; i + 1];
            for j in 0..i {
                if row[j] > 1f64 {
                    next_row[j] += (row[j] - 1f64) / 2f64;
                    next_row[j + 1] += (row[j] - 1f64) / 2f64;
                }
            }
            row = next_row;
        }
        (1f64).min(row[query_glass])
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们把玻璃杯摆成金字塔的形状，其中&nbsp;<strong>第一层</strong>&nbsp;有 <code>1</code> 个玻璃杯， <strong>第二层</strong>&nbsp;有 <code>2</code> 个，依次类推到第 100 层，每个玻璃杯将盛有香槟。</p>

<p>从顶层的第一个玻璃杯开始倾倒一些香槟，当顶层的杯子满了，任何溢出的香槟都会立刻等流量的流向左右两侧的玻璃杯。当左右两边的杯子也满了，就会等流量的流向它们左右两边的杯子，依次类推。（当最底层的玻璃杯满了，香槟会流到地板上）</p>

<p>例如，在倾倒一杯香槟后，最顶层的玻璃杯满了。倾倒了两杯香槟后，第二层的两个玻璃杯各自盛放一半的香槟。在倒三杯香槟后，第二层的香槟满了 - 此时总共有三个满的玻璃杯。在倒第四杯后，第三层中间的玻璃杯盛放了一半的香槟，他两边的玻璃杯各自盛放了四分之一的香槟，如下图所示。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0799.Champagne%20Tower/images/tower.png" style="height: 241px; width: 350px;" /></p>

<p>现在当倾倒了非负整数杯香槟后，返回第 <code>i</code> 行 <code>j</code>&nbsp;个玻璃杯所盛放的香槟占玻璃杯容积的比例（ <code>i</code> 和 <code>j</code>&nbsp;都从0开始）。</p>

<p>&nbsp;</p>

<pre>
<strong>示例 1:</strong>
<strong>输入:</strong> poured(倾倒香槟总杯数) = 1, query_glass(杯子的位置数) = 1, query_row(行数) = 1
<strong>输出:</strong> 0.00000
<strong>解释:</strong> 我们在顶层（下标是（0，0））倒了一杯香槟后，没有溢出，因此所有在顶层以下的玻璃杯都是空的。

<strong>示例 2:</strong>
<strong>输入:</strong> poured(倾倒香槟总杯数) = 2, query_glass(杯子的位置数) = 1, query_row(行数) = 1
<strong>输出:</strong> 0.50000
<strong>解释:</strong> 我们在顶层（下标是（0，0）倒了两杯香槟后，有一杯量的香槟将从顶层溢出，位于（1，0）的玻璃杯和（1，1）的玻璃杯平分了这一杯香槟，所以每个玻璃杯有一半的香槟。
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> poured = 100000009, query_row = 33, query_glass = 17
<strong>输出:</strong> 1.00000
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;=&nbsp;poured &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= query_glass &lt;= query_row&nbsp;&lt; 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接模拟倒香槟的过程。

定义一个二维数组 $f$，其中 $f[i][j]$ 表示第 $i$ 层第 $j$ 个玻璃杯中的香槟量。初始时 $f[0][0] = poured$。

对于每一层，如果当前杯子的香槟量 $f[i][j]$ 大于 $1$，香槟会流向下一层的两个杯子，流入的量为 $\frac{f[i][j]-1}{2}$，即当前杯子的香槟量减去 $1$ 后除以 $2$，然后当前杯子的香槟量更新为 $1$。

模拟结束，返回 $f[query\_row][query\_glass]$ 即可。

由于每一层的香槟量只与上一层的香槟量有关，因此我们可以用滚动数组的方式优化空间复杂度，将二维数组优化为一维数组。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为层数，即 $query\_row$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        f = [[0] * 101 for _ in range(101)]
        f[0][0] = poured
        for i in range(query_row + 1):
            for j in range(i + 1):
                if f[i][j] > 1:
                    half = (f[i][j] - 1) / 2
                    f[i][j] = 1
                    f[i + 1][j] += half
                    f[i + 1][j + 1] += half
        return f[query_row][query_glass]
```

#### Java

```java
class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] f = new double[101][101];
        f[0][0] = poured;
        for (int i = 0; i <= query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (f[i][j] > 1) {
                    double half = (f[i][j] - 1) / 2.0;
                    f[i][j] = 1;
                    f[i + 1][j] += half;
                    f[i + 1][j + 1] += half;
                }
            }
        }
        return f[query_row][query_glass];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double f[101][101] = {0.0};
        f[0][0] = poured;
        for (int i = 0; i <= query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (f[i][j] > 1) {
                    double half = (f[i][j] - 1) / 2.0;
                    f[i][j] = 1;
                    f[i + 1][j] += half;
                    f[i + 1][j + 1] += half;
                }
            }
        }
        return f[query_row][query_glass];
    }
};
```

#### Go

```go
func champagneTower(poured int, query_row int, query_glass int) float64 {
	f := [101][101]float64{}
	f[0][0] = float64(poured)
	for i := 0; i <= query_row; i++ {
		for j := 0; j <= i; j++ {
			if f[i][j] > 1 {
				half := (f[i][j] - 1) / 2.0
				f[i][j] = 1
				f[i+1][j] += half
				f[i+1][j+1] += half
			}
		}
	}
	return f[query_row][query_glass]
}
```

#### TypeScript

```ts
function champagneTower(poured: number, query_row: number, query_glass: number): number {
    let row = [poured];
    for (let i = 1; i <= query_row; i++) {
        const nextRow = new Array(i + 1).fill(0);
        for (let j = 0; j < i; j++) {
            if (row[j] > 1) {
                nextRow[j] += (row[j] - 1) / 2;
                nextRow[j + 1] += (row[j] - 1) / 2;
            }
        }
        row = nextRow;
    }
    return Math.min(1, row[query_glass]);
}
```

#### Rust

```rust
impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let query_row = query_row as usize;
        let query_glass = query_glass as usize;
        let mut row = vec![poured as f64];
        for i in 1..=query_row {
            let mut next_row = vec![0f64; i + 1];
            for j in 0..i {
                if row[j] > 1f64 {
                    next_row[j] += (row[j] - 1f64) / 2f64;
                    next_row[j + 1] += (row[j] - 1f64) / 2f64;
                }
            }
            row = next_row;
        }
        (1f64).min(row[query_glass])
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
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        f = [poured]
        for i in range(1, query_row + 1):
            g = [0] * (i + 1)
            for j, v in enumerate(f):
                if v > 1:
                    half = (v - 1) / 2
                    g[j] += half
                    g[j + 1] += half
            f = g
        return min(1, f[query_glass])
```

#### Java

```java
class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[] f = {poured};
        for (int i = 1; i <= query_row; ++i) {
            double[] g = new double[i + 1];
            for (int j = 0; j < i; ++j) {
                if (f[j] > 1) {
                    double half = (f[j] - 1) / 2.0;
                    g[j] += half;
                    g[j + 1] += half;
                }
            }
            f = g;
        }
        return Math.min(1, f[query_glass]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double f[101] = {(double) poured};
        double g[101];
        for (int i = 1; i <= query_row; ++i) {
            memset(g, 0, sizeof g);
            for (int j = 0; j < i; ++j) {
                if (f[j] > 1) {
                    double half = (f[j] - 1) / 2.0;
                    g[j] += half;
                    g[j + 1] += half;
                }
            }
            memcpy(f, g, sizeof g);
        }
        return min(1.0, f[query_glass]);
    }
};
```

#### Go

```go
func champagneTower(poured int, query_row int, query_glass int) float64 {
	f := []float64{float64(poured)}
	for i := 1; i <= query_row; i++ {
		g := make([]float64, i+1)
		for j, v := range f {
			if v > 1 {
				half := (v - 1) / 2.0
				g[j] += half
				g[j+1] += half
			}
		}
		f = g
	}
	return math.Min(1, f[query_glass])
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
