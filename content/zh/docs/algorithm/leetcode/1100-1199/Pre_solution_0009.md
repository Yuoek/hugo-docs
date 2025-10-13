---
title: "1180_统计只含单一字母的子串 🔒"
date: 2025-10-08T18:36:57+08:00
weight: 9
tags: [二分查找, 动态规划, 哈希表, 堆（优先队列）, 多线程, 字符串, 排序, 数学, 数组, 计数, 贪心]
---

{{< markmap >}}
### [1180_统计只含单一字母的子串 🔒](#1180)
#### [数学](#1180)
#### [字符串](#1180)
### [1181_前后拼接 🔒](#1181)
#### [数组](#1181)
#### [哈希表](#1181)
#### [字符串](#1181)
#### [排序](#1181)
### [1182_与目标颜色间的最短距离 🔒](#1182)
#### [数组](#1182)
#### [二分查找](#1182)
#### [动态规划](#1182)
### [1183_矩阵中 1 的最大数量 🔒](#1183)
#### [贪心](#1183)
#### [数学](#1183)
#### [排序](#1183)
#### [堆（优先队列）](#1183)
### [1184_公交站间的距离](#1184)
#### [数组](#1184)
### [1185_一周中的第几天](#1185)
#### [数学](#1185)
### [1186_删除一次得到子数组最大和](#1186)
#### [数组](#1186)
#### [动态规划](#1186)
### [1187_使数组严格递增](#1187)
#### [数组](#1187)
#### [二分查找](#1187)
#### [动态规划](#1187)
#### [排序](#1187)
### [1188_设计有限阻塞队列 🔒](#1188)
#### [多线程](#1188)
### [1189_“气球” 的最大数量](#1189)
#### [哈希表](#1189)
#### [字符串](#1189)
#### [计数](#1189)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1180_统计只含单一字母的子串 🔒
___
#### 数学
___
#### 字符串
---
### 1181_前后拼接 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 1182_与目标颜色间的最短距离 🔒
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 1183_矩阵中 1 的最大数量 🔒
___
#### 贪心
___
#### 数学
___
#### 排序
___
#### 堆（优先队列）
---
### 1184_公交站间的距离
___
#### 数组
---
### 1185_一周中的第几天
___
#### 数学
---
### 1186_删除一次得到子数组最大和
___
#### 数组
___
#### 动态规划
---
### 1187_使数组严格递增
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 1188_设计有限阻塞队列 🔒
___
#### 多线程
---
### 1189_“气球” 的最大数量
___
#### 哈希表
___
#### 字符串
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 哈希表 |
| 堆（优先队列） | 多线程 | 字符串 |
| 排序 | 数学 | 数组 |
| 计数 | 贪心 |  |

# [1180. 统计只含单一字母的子串 🔒](https://leetcode.cn/problems/count-substrings-with-only-one-distinct-letter){#1180}

{{< tabs "1180" >}}

{{% tab "python" %}}
```python
class Solution:
    def countLetters(self, s: str) -> int:
        ans = 0
        i, n = 0, len(s)
        while i < n:
            j = i
            cnt = 0
            while j < n and s[j] == s[i]:
                j += 1
                cnt += 1
                ans += cnt
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countLetters(String s) {
        int ans = 0;
        int i = 0, n = s.length();
        while (i < n) {
            int j = i;
            int cnt = 0;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
                ans += ++cnt;
            }
            i = j;
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
    int countLetters(string s) {
        int ans = 0;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            int cnt = 0;
            while (j < n && s[j] == s[i]) {
                ++j;
                ans += ++cnt;
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countLetters(s string) (ans int) {
	i, n := 0, len(s)
	for i < n {
		j := i
		cnt := 0
		for j < n && s[j] == s[i] {
			j++
			cnt++
			ans += cnt
		}
		i = j
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countLetters(s: string): number {
    let ans = 0;
    const n = s.length;
    for (let i = 0; i < n; ) {
        let j = i;
        let cnt = 0;
        while (j < n && s[j] === s[i]) {
            ++j;
            ans += ++cnt;
        }
        i = j;
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

<p>给你一个字符串 <code>s</code>，返回 <em>只含 <strong>单一字母</strong> 的子串个数</em> 。</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入： </strong>s = "aaaba"
<strong>输出： </strong>8
<strong>解释： </strong>只含单一字母的子串分别是 "aaa"， "aa"， "a"， "b"。
"aaa" 出现 1 次。
"aa" 出现 2 次。
"a" 出现 4 次。
"b" 出现 1 次。
所以答案是 1 + 2 + 4 + 1 = 8。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入： </strong>s = "aaaaaaaaaa"
<strong>输出： </strong>55
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以使用双指针，用指针 $i$ 指向当前子串的起始位置，指针 $j$ 向右移动到第一个与 $s[i]$ 不同的位置，那么 $[i,..j-1]$ 就是以 $s[i]$ 为唯一字母的子串，长度为 $j-i$，那么以 $s[i]$ 为唯一字母的子串的个数就是 $\frac{(j-i+1)(j-i)}{2}$，累加到答案中。然后令 $i=j$，继续遍历，直到 $i$ 超出字符串 $s$ 的范围。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countLetters(self, s: str) -> int:
        n = len(s)
        i = ans = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            ans += (1 + j - i) * (j - i) // 2
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int countLetters(String s) {
        int ans = 0;
        for (int i = 0, n = s.length(); i < n;) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            ans += (1 + j - i) * (j - i) / 2;
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countLetters(string s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            ans += (1 + j - i) * (j - i) / 2;
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func countLetters(s string) int {
	ans := 0
	for i, n := 0, len(s); i < n; {
		j := i
		for j < n && s[j] == s[i] {
			j++
		}
		ans += (1 + j - i) * (j - i) / 2
		i = j
	}
	return ans
}
```

#### TypeScript

```ts
function countLetters(s: string): number {
    let ans = 0;
    const n = s.length;
    for (let i = 0; i < n; ) {
        let j = i;
        let cnt = 0;
        while (j < n && s[j] === s[i]) {
            ++j;
            ans += ++cnt;
        }
        i = j;
    }
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
    def countLetters(self, s: str) -> int:
        ans = 0
        i, n = 0, len(s)
        while i < n:
            j = i
            cnt = 0
            while j < n and s[j] == s[i]:
                j += 1
                cnt += 1
                ans += cnt
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int countLetters(String s) {
        int ans = 0;
        int i = 0, n = s.length();
        while (i < n) {
            int j = i;
            int cnt = 0;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
                ans += ++cnt;
            }
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countLetters(string s) {
        int ans = 0;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            int cnt = 0;
            while (j < n && s[j] == s[i]) {
                ++j;
                ans += ++cnt;
            }
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func countLetters(s string) (ans int) {
	i, n := 0, len(s)
	for i < n {
		j := i
		cnt := 0
		for j < n && s[j] == s[i] {
			j++
			cnt++
			ans += cnt
		}
		i = j
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1181. 前后拼接 🔒](https://leetcode.cn/problems/before-and-after-puzzle){#1181}

{{< tabs "1181" >}}

{{% tab "python" %}}
```python
class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        ps = []
        for p in phrases:
            ws = p.split()
            ps.append((ws[0], ws[-1]))
        n = len(ps)
        ans = []
        for i in range(n):
            for j in range(n):
                if i != j and ps[i][1] == ps[j][0]:
                    ans.append(phrases[i] + phrases[j][len(ps[j][0]) :])
        return sorted(set(ans))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> beforeAndAfterPuzzles(String[] phrases) {
        int n = phrases.length;
        var ps = new String[n][];
        for (int i = 0; i < n; ++i) {
            var ws = phrases[i].split(" ");
            ps[i] = new String[] {ws[0], ws[ws.length - 1]};
        }
        Set<String> s = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && ps[i][1].equals(ps[j][0])) {
                    s.add(phrases[i] + phrases[j].substring(ps[j][0].length()));
                }
            }
        }
        var ans = new ArrayList<>(s);
        Collections.sort(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        pair<string, string> ps[n];
        for (int i = 0; i < n; ++i) {
            int j = phrases[i].find(' ');
            if (j == string::npos) {
                ps[i] = {phrases[i], phrases[i]};
            } else {
                int k = phrases[i].rfind(' ');
                ps[i] = {phrases[i].substr(0, j), phrases[i].substr(k + 1)};
            }
        }
        unordered_set<string> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && ps[i].second == ps[j].first) {
                    s.insert(phrases[i] + phrases[j].substr(ps[i].second.size()));
                }
            }
        }
        vector<string> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beforeAndAfterPuzzles(phrases []string) []string {
	n := len(phrases)
	ps := make([][2]string, n)
	for i, p := range phrases {
		ws := strings.Split(p, " ")
		ps[i] = [2]string{ws[0], ws[len(ws)-1]}
	}
	s := map[string]bool{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j && ps[i][1] == ps[j][0] {
				s[phrases[i]+phrases[j][len(ps[j][0]):]] = true
			}
		}
	}
	ans := make([]string, 0, len(s))
	for k := range s {
		ans = append(ans, k)
	}
	sort.Strings(ans)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function beforeAndAfterPuzzles(phrases: string[]): string[] {
    const ps: string[][] = [];
    for (const p of phrases) {
        const ws = p.split(' ');
        ps.push([ws[0], ws[ws.length - 1]]);
    }
    const n = ps.length;
    const s: Set<string> = new Set();
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i !== j && ps[i][1] === ps[j][0]) {
                s.add(`${phrases[i]}${phrases[j].substring(ps[j][0].length)}`);
            }
        }
    }
    return [...s].sort();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个「短语」列表&nbsp;<code>phrases</code>，请你帮忙按规则生成拼接后的「新短语」列表。</p>

<p>「短语」（phrase）是仅由小写英文字母和空格组成的字符串。「短语」的开头和结尾都不会出现空格，「短语」中的空格不会连续出现。</p>

<p>「前后拼接」（Before and After&nbsp;puzzles）是合并两个「短语」形成「新短语」的方法。我们规定拼接时，<strong>第一个短语的最后一个单词</strong> 和 <strong>第二个短语的第一个单词</strong> 必须相同。</p>

<p>返回每两个「短语」&nbsp;<code>phrases[i]</code>&nbsp;和&nbsp;<code>phrases[j]</code>（<code>i != j</code>）进行「前后拼接」得到的「新短语」。</p>

<p>注意，两个「短语」拼接时的顺序也很重要，我们需要同时考虑这两个「短语」。另外，同一个「短语」可以多次参与拼接，但「新短语」不能再参与拼接。</p>

<p>请你按字典序排列并返回「新短语」列表，列表中的字符串应该是 <strong>不重复的</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>phrases = ["writing code","code rocks"]</p>

<p><strong>输出：</strong>["writing code rocks"]</p>
</div>

<p><strong>示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>phrases = ["mission statement", "a quick bite to eat", &nbsp; "a chip off the old block", &nbsp; "chocolate bar", &nbsp; "mission impossible", &nbsp; "a man on a mission", &nbsp; "block party", &nbsp; "eat my words", &nbsp; "bar of soap"]</p>

<p><strong>输出：</strong>["a chip off the old block party", &nbsp; "a man on a mission impossible", &nbsp; "a man on a mission statement", &nbsp; "a quick bite to eat my words", "chocolate bar of soap"]</p>
</div>

<p><strong>示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>phrases = ["a","b","a"]</p>

<p><strong>输出：</strong>["a"]</p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>phrases = ["ab ba","ba ab","ab ba"]</span></p>

<p><span class="example-io"><b>输出：</b>["ab ba ab","ba ab ba"]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= phrases.length &lt;= 100</code></li>
	<li><code>1 &lt;= phrases[i].length &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们先遍历列表 `phrases`，将每个短语的首尾单词存储数组 $ps$ 中，其中 $ps[i][0]$ 和 $ps[i][1]$ 分别表示第 $i$ 个短语的首尾单词。

接下来，我们枚举所有 $(i, j)$，其中 $i, j \in [0, n)$ 且 $i \neq j$。如果 $ps[i][1] = ps[j][0]$，那么我们就可以将第 $i$ 个短语和第 $j$ 个短语进行拼接，得到的新短语为 $phrases[i] + phrases[j][len(ps[j][0]):]$，将新短语加入哈希表 $s$ 中。

最后，我们将哈希表 $s$ 转化为数组并排序，即可得到答案。

时间复杂度 $O(n^2 \times m \times (\log n + \log m))$，空间复杂度 $O(n^2 \times m)$。其中 $n$ 和 $m$ 分别表示数组 $phrases$ 的长度和每个短语的平均长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        ps = []
        for p in phrases:
            ws = p.split()
            ps.append((ws[0], ws[-1]))
        n = len(ps)
        ans = []
        for i in range(n):
            for j in range(n):
                if i != j and ps[i][1] == ps[j][0]:
                    ans.append(phrases[i] + phrases[j][len(ps[j][0]) :])
        return sorted(set(ans))
```

#### Java

```java
class Solution {
    public List<String> beforeAndAfterPuzzles(String[] phrases) {
        int n = phrases.length;
        var ps = new String[n][];
        for (int i = 0; i < n; ++i) {
            var ws = phrases[i].split(" ");
            ps[i] = new String[] {ws[0], ws[ws.length - 1]};
        }
        Set<String> s = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && ps[i][1].equals(ps[j][0])) {
                    s.add(phrases[i] + phrases[j].substring(ps[j][0].length()));
                }
            }
        }
        var ans = new ArrayList<>(s);
        Collections.sort(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        pair<string, string> ps[n];
        for (int i = 0; i < n; ++i) {
            int j = phrases[i].find(' ');
            if (j == string::npos) {
                ps[i] = {phrases[i], phrases[i]};
            } else {
                int k = phrases[i].rfind(' ');
                ps[i] = {phrases[i].substr(0, j), phrases[i].substr(k + 1)};
            }
        }
        unordered_set<string> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && ps[i].second == ps[j].first) {
                    s.insert(phrases[i] + phrases[j].substr(ps[i].second.size()));
                }
            }
        }
        vector<string> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func beforeAndAfterPuzzles(phrases []string) []string {
	n := len(phrases)
	ps := make([][2]string, n)
	for i, p := range phrases {
		ws := strings.Split(p, " ")
		ps[i] = [2]string{ws[0], ws[len(ws)-1]}
	}
	s := map[string]bool{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j && ps[i][1] == ps[j][0] {
				s[phrases[i]+phrases[j][len(ps[j][0]):]] = true
			}
		}
	}
	ans := make([]string, 0, len(s))
	for k := range s {
		ans = append(ans, k)
	}
	sort.Strings(ans)
	return ans
}
```

#### TypeScript

```ts
function beforeAndAfterPuzzles(phrases: string[]): string[] {
    const ps: string[][] = [];
    for (const p of phrases) {
        const ws = p.split(' ');
        ps.push([ws[0], ws[ws.length - 1]]);
    }
    const n = ps.length;
    const s: Set<string> = new Set();
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i !== j && ps[i][1] === ps[j][0]) {
                s.add(`${phrases[i]}${phrases[j].substring(ps[j][0].length)}`);
            }
        }
    }
    return [...s].sort();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1182. 与目标颜色间的最短距离 🔒](https://leetcode.cn/problems/shortest-distance-to-target-color){#1182}

{{< tabs "1182" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestDistanceColor(
        self, colors: List[int], queries: List[List[int]]
    ) -> List[int]:
        n = len(colors)
        right = [[inf] * 3 for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(3):
                right[i][j] = right[i + 1][j]
            right[i][colors[i] - 1] = i
        left = [[-inf] * 3 for _ in range(n + 1)]
        for i, c in enumerate(colors, 1):
            for j in range(3):
                left[i][j] = left[i - 1][j]
            left[i][c - 1] = i - 1
        ans = []
        for i, c in queries:
            d = min(i - left[i + 1][c - 1], right[i][c - 1] - i)
            ans.append(-1 if d > n else d)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        int n = colors.length;
        final int inf = 1 << 30;
        int[][] right = new int[n + 1][3];
        Arrays.fill(right[n], inf);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                right[i][j] = right[i + 1][j];
            }
            right[i][colors[i] - 1] = i;
        }
        int[][] left = new int[n + 1][3];
        Arrays.fill(left[0], -inf);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                left[i][j] = left[i - 1][j];
            }
            left[i][colors[i - 1] - 1] = i - 1;
        }
        List<Integer> ans = new ArrayList<>();
        for (int[] q : queries) {
            int i = q[0], c = q[1] - 1;
            int d = Math.min(i - left[i + 1][c], right[i][c] - i);
            ans.add(d > n ? -1 : d);
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
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int right[n + 1][3];
        const int inf = 1 << 30;
        fill(right[n], right[n] + 3, inf);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                right[i][j] = right[i + 1][j];
            }
            right[i][colors[i] - 1] = i;
        }
        int left[n + 1][3];
        fill(left[0], left[0] + 3, -inf);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                left[i][j] = left[i - 1][j];
            }
            left[i][colors[i - 1] - 1] = i - 1;
        }
        vector<int> ans;
        for (auto& q : queries) {
            int i = q[0], c = q[1] - 1;
            int d = min(i - left[i + 1][c], right[i][c] - i);
            ans.push_back(d > n ? -1 : d);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestDistanceColor(colors []int, queries [][]int) (ans []int) {
	n := len(colors)
	const inf = 1 << 30
	right := make([][3]int, n+1)
	left := make([][3]int, n+1)
	right[n] = [3]int{inf, inf, inf}
	left[0] = [3]int{-inf, -inf, -inf}
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < 3; j++ {
			right[i][j] = right[i+1][j]
		}
		right[i][colors[i]-1] = i
	}
	for i := 1; i <= n; i++ {
		for j := 0; j < 3; j++ {
			left[i][j] = left[i-1][j]
		}
		left[i][colors[i-1]-1] = i - 1
	}
	for _, q := range queries {
		i, c := q[0], q[1]-1
		d := min(i-left[i+1][c], right[i][c]-i)
		if d > n {
			d = -1
		}
		ans = append(ans, d)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestDistanceColor(colors: number[], queries: number[][]): number[] {
    const n = colors.length;
    const inf = 1 << 30;
    const right: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(3).fill(inf));
    const left: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(3).fill(-inf));
    for (let i = n - 1; i >= 0; --i) {
        for (let j = 0; j < 3; ++j) {
            right[i][j] = right[i + 1][j];
        }
        right[i][colors[i] - 1] = i;
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 3; ++j) {
            left[i][j] = left[i - 1][j];
        }
        left[i][colors[i - 1] - 1] = i - 1;
    }
    const ans: number[] = [];
    for (const [i, c] of queries) {
        const d = Math.min(i - left[i + 1][c - 1], right[i][c - 1] - i);
        ans.push(d > n ? -1 : d);
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

<p>给你一个数组&nbsp;<code>colors</code>，里面有&nbsp;&nbsp;<code>1</code>、<code>2</code>、&nbsp;<code>3</code> 三种颜色。</p>

<p>我们需要在&nbsp;<code>colors</code> 上进行一些查询操作 <code>queries</code>，其中每个待查项都由两个整数 <code>i</code> 和 <code>c</code> 组成。</p>

<p>现在请你帮忙设计一个算法，查找从索引&nbsp;<code>i</code>&nbsp;到具有目标颜色&nbsp;<code>c</code>&nbsp;的元素之间的最短距离。</p>

<p>如果不存在解决方案，请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
<strong>输出：</strong>[3,0,3]
<strong>解释： </strong>
距离索引 1 最近的颜色 3 位于索引 4（距离为 3）。
距离索引 2 最近的颜色 2 就是它自己（距离为 0）。
距离索引 6 最近的颜色 1 位于索引 3（距离为 3）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>colors = [1,2], queries = [[0,3]]
<strong>输出：</strong>[-1]
<strong>解释：</strong>colors 中没有颜色 3。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= colors.length &lt;= 5*10^4</code></li>
	<li><code>1 &lt;= colors[i] &lt;= 3</code></li>
	<li><code>1&nbsp;&lt;= queries.length &lt;= 5*10^4</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;&nbsp;colors.length</code></li>
	<li><code>1 &lt;= queries[i][1] &lt;= 3</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理

我们可以预处理出每个位置到左边最近的颜色 $1$,$2$,$3$ 的距离，以及每个位置到右边最近的颜色 $1$,$2$,$3$ 的距离，记录在数组 $left$ 和 $right$ 中。初始时 $left[0][0] = left[0][1] = left[0][2] = -\infty$，而 $right[n][0] = right[n][1] = right[n][2] = \infty$，其中 $n$ 是数组 $colors$ 的长度。

然后对于每个查询 $(i, c)$，最小距离就是 $d = \min(i - left[i + 1][c - 1], right[i][c - 1][i] - i)$，如果 $d \gt n$，则不存在解决方案，此次查询的答案为 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $colors$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestDistanceColor(
        self, colors: List[int], queries: List[List[int]]
    ) -> List[int]:
        n = len(colors)
        right = [[inf] * 3 for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(3):
                right[i][j] = right[i + 1][j]
            right[i][colors[i] - 1] = i
        left = [[-inf] * 3 for _ in range(n + 1)]
        for i, c in enumerate(colors, 1):
            for j in range(3):
                left[i][j] = left[i - 1][j]
            left[i][c - 1] = i - 1
        ans = []
        for i, c in queries:
            d = min(i - left[i + 1][c - 1], right[i][c - 1] - i)
            ans.append(-1 if d > n else d)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        int n = colors.length;
        final int inf = 1 << 30;
        int[][] right = new int[n + 1][3];
        Arrays.fill(right[n], inf);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                right[i][j] = right[i + 1][j];
            }
            right[i][colors[i] - 1] = i;
        }
        int[][] left = new int[n + 1][3];
        Arrays.fill(left[0], -inf);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                left[i][j] = left[i - 1][j];
            }
            left[i][colors[i - 1] - 1] = i - 1;
        }
        List<Integer> ans = new ArrayList<>();
        for (int[] q : queries) {
            int i = q[0], c = q[1] - 1;
            int d = Math.min(i - left[i + 1][c], right[i][c] - i);
            ans.add(d > n ? -1 : d);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int right[n + 1][3];
        const int inf = 1 << 30;
        fill(right[n], right[n] + 3, inf);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                right[i][j] = right[i + 1][j];
            }
            right[i][colors[i] - 1] = i;
        }
        int left[n + 1][3];
        fill(left[0], left[0] + 3, -inf);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                left[i][j] = left[i - 1][j];
            }
            left[i][colors[i - 1] - 1] = i - 1;
        }
        vector<int> ans;
        for (auto& q : queries) {
            int i = q[0], c = q[1] - 1;
            int d = min(i - left[i + 1][c], right[i][c] - i);
            ans.push_back(d > n ? -1 : d);
        }
        return ans;
    }
};
```

#### Go

```go
func shortestDistanceColor(colors []int, queries [][]int) (ans []int) {
	n := len(colors)
	const inf = 1 << 30
	right := make([][3]int, n+1)
	left := make([][3]int, n+1)
	right[n] = [3]int{inf, inf, inf}
	left[0] = [3]int{-inf, -inf, -inf}
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < 3; j++ {
			right[i][j] = right[i+1][j]
		}
		right[i][colors[i]-1] = i
	}
	for i := 1; i <= n; i++ {
		for j := 0; j < 3; j++ {
			left[i][j] = left[i-1][j]
		}
		left[i][colors[i-1]-1] = i - 1
	}
	for _, q := range queries {
		i, c := q[0], q[1]-1
		d := min(i-left[i+1][c], right[i][c]-i)
		if d > n {
			d = -1
		}
		ans = append(ans, d)
	}
	return
}
```

#### TypeScript

```ts
function shortestDistanceColor(colors: number[], queries: number[][]): number[] {
    const n = colors.length;
    const inf = 1 << 30;
    const right: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(3).fill(inf));
    const left: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(3).fill(-inf));
    for (let i = n - 1; i >= 0; --i) {
        for (let j = 0; j < 3; ++j) {
            right[i][j] = right[i + 1][j];
        }
        right[i][colors[i] - 1] = i;
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 3; ++j) {
            left[i][j] = left[i - 1][j];
        }
        left[i][colors[i - 1] - 1] = i - 1;
    }
    const ans: number[] = [];
    for (const [i, c] of queries) {
        const d = Math.min(i - left[i + 1][c - 1], right[i][c - 1] - i);
        ans.push(d > n ? -1 : d);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1183. 矩阵中 1 的最大数量 🔒](https://leetcode.cn/problems/maximum-number-of-ones){#1183}

{{< tabs "1183" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumNumberOfOnes(
        self, width: int, height: int, sideLength: int, maxOnes: int
    ) -> int:
        x = sideLength
        cnt = [0] * (x * x)
        for i in range(width):
            for j in range(height):
                k = (i % x) * x + (j % x)
                cnt[k] += 1
        cnt.sort(reverse=True)
        return sum(cnt[:maxOnes])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int x = sideLength;
        int[] cnt = new int[x * x];
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int k = (i % x) * x + (j % x);
                ++cnt[k];
            }
        }
        Arrays.sort(cnt);
        int ans = 0;
        for (int i = 0; i < maxOnes; ++i) {
            ans += cnt[cnt.length - i - 1];
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
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int x = sideLength;
        vector<int> cnt(x * x);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int k = (i % x) * x + (j % x);
                ++cnt[k];
            }
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < maxOnes; ++i) {
            ans += cnt[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumNumberOfOnes(width int, height int, sideLength int, maxOnes int) int {
	x := sideLength
	cnt := make([]int, x*x)
	for i := 0; i < width; i++ {
		for j := 0; j < height; j++ {
			k := (i%x)*x + (j % x)
			cnt[k]++
		}
	}
	sort.Ints(cnt)
	ans := 0
	for i := range cnt[:maxOnes] {
		ans += cnt[len(cnt)-i-1]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} width
 * @param {number} height
 * @param {number} sideLength
 * @param {number} maxOnes
 * @return {number}
 */
var maximumNumberOfOnes = function (width, height, sideLength, maxOnes) {
    const x = sideLength;
    const cnt = new Array(x * x).fill(0);
    for (let i = 0; i < width; ++i) {
        for (let j = 0; j < height; ++j) {
            const k = (i % x) * x + (j % x);
            ++cnt[k];
        }
    }
    cnt.sort((a, b) => b - a);
    return cnt.slice(0, maxOnes).reduce((a, b) => a + b, 0);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现在有一个尺寸为 <code>width * height</code>&nbsp;的矩阵&nbsp;<code>M</code>，矩阵中的每个单元格的值不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>。</p>

<p>而且矩阵 <code>M</code> 中每个大小为&nbsp;<code>sideLength * sideLength</code>&nbsp;的 <strong>正方形</strong> 子阵中，<code>1</code> 的数量不得超过&nbsp;<code>maxOnes</code>。</p>

<p>请你设计一个算法，计算矩阵中最多可以有多少个 <code>1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>width = 3, height = 3, sideLength = 2, maxOnes = 1
<strong>输出：</strong>4
<strong>解释：</strong>
题目要求：在一个 3*3 的矩阵中，每一个 2*2 的子阵中的 1 的数目不超过 1 个。
最好的解决方案中，矩阵 M 里最多可以有 4 个 1，如下所示：
[1,0,1]
[0,0,0]
[1,0,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>width = 3, height = 3, sideLength = 2, maxOnes = 2
<strong>输出：</strong>6
<strong>解释：</strong>
[1,0,1]
[1,0,1]
[1,0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= width, height &lt;= 100</code></li>
	<li><code>1 &lt;= sideLength &lt;= width, height</code></li>
	<li><code>0 &lt;= maxOnes &lt;= sideLength * sideLength</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计等效位置

为了方便说明，我们不妨令 $x = sideLength$。

考虑一个 $x\times x$ 的正方形，我们需要在正方形里面取最多 $maxOnes$ 个点，将其置为 1。注意到当坐标 $(i, j)$ 处的点被选取后，所有坐标为 $(i\pm k_1 \times x, j\pm k_2 \times x)$ 的点都可以等效地置为 1。因此，我们算出坐标 $(i, j)$ 在矩阵中的等效位置的数量，取数量最多的前 $maxOnes$ 个即可。

时间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumNumberOfOnes(
        self, width: int, height: int, sideLength: int, maxOnes: int
    ) -> int:
        x = sideLength
        cnt = [0] * (x * x)
        for i in range(width):
            for j in range(height):
                k = (i % x) * x + (j % x)
                cnt[k] += 1
        cnt.sort(reverse=True)
        return sum(cnt[:maxOnes])
```

#### Java

```java
class Solution {
    public int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int x = sideLength;
        int[] cnt = new int[x * x];
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int k = (i % x) * x + (j % x);
                ++cnt[k];
            }
        }
        Arrays.sort(cnt);
        int ans = 0;
        for (int i = 0; i < maxOnes; ++i) {
            ans += cnt[cnt.length - i - 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int x = sideLength;
        vector<int> cnt(x * x);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int k = (i % x) * x + (j % x);
                ++cnt[k];
            }
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < maxOnes; ++i) {
            ans += cnt[i];
        }
        return ans;
    }
};
```

#### Go

```go
func maximumNumberOfOnes(width int, height int, sideLength int, maxOnes int) int {
	x := sideLength
	cnt := make([]int, x*x)
	for i := 0; i < width; i++ {
		for j := 0; j < height; j++ {
			k := (i%x)*x + (j % x)
			cnt[k]++
		}
	}
	sort.Ints(cnt)
	ans := 0
	for i := range cnt[:maxOnes] {
		ans += cnt[len(cnt)-i-1]
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {number} width
 * @param {number} height
 * @param {number} sideLength
 * @param {number} maxOnes
 * @return {number}
 */
var maximumNumberOfOnes = function (width, height, sideLength, maxOnes) {
    const x = sideLength;
    const cnt = new Array(x * x).fill(0);
    for (let i = 0; i < width; ++i) {
        for (let j = 0; j < height; ++j) {
            const k = (i % x) * x + (j % x);
            ++cnt[k];
        }
    }
    cnt.sort((a, b) => b - a);
    return cnt.slice(0, maxOnes).reduce((a, b) => a + b, 0);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1184. 公交站间的距离](https://leetcode.cn/problems/distance-between-bus-stops){#1184}

{{< tabs "1184" >}}

{{% tab "python" %}}
```python
class Solution:
    def distanceBetweenBusStops(
        self, distance: List[int], start: int, destination: int
    ) -> int:
        s = sum(distance)
        t, n = 0, len(distance)
        while start != destination:
            t += distance[start]
            start = (start + 1) % n
        return min(t, s - t)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int s = Arrays.stream(distance).sum();
        int n = distance.length, t = 0;
        while (start != destination) {
            t += distance[start];
            start = (start + 1) % n;
        }
        return Math.min(t, s - t);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s = accumulate(distance.begin(), distance.end(), 0);
        int t = 0, n = distance.size();
        while (start != destination) {
            t += distance[start];
            start = (start + 1) % n;
        }
        return min(t, s - t);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distanceBetweenBusStops(distance []int, start int, destination int) int {
	s, t := 0, 0
	for _, x := range distance {
		s += x
	}
	for start != destination {
		t += distance[start]
		start = (start + 1) % len(distance)
	}
	return min(t, s-t)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distanceBetweenBusStops(distance: number[], start: number, destination: number): number {
    const s = distance.reduce((a, b) => a + b, 0);
    const n = distance.length;
    let t = 0;
    while (start !== destination) {
        t += distance[start];
        start = (start + 1) % n;
    }
    return Math.min(t, s - t);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
        let s: i32 = distance.iter().sum();
        let mut t = 0;
        let n = distance.len();
        let mut start = start as usize;
        let destination = destination as usize;

        while start != destination {
            t += distance[start];
            start = (start + 1) % n;
        }

        t.min(s - t)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
var distanceBetweenBusStops = function (distance, start, destination) {
    const s = distance.reduce((a, b) => a + b, 0);
    const n = distance.length;
    let t = 0;
    while (start !== destination) {
        t += distance[start];
        start = (start + 1) % n;
    }
    return Math.min(t, s - t);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>环形公交路线上有&nbsp;<code>n</code>&nbsp;个站，按次序从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;进行编号。我们已知每一对相邻公交站之间的距离，<code>distance[i]</code>&nbsp;表示编号为&nbsp;<code>i</code>&nbsp;的车站和编号为&nbsp;<code>(i + 1) % n</code>&nbsp;的车站之间的距离。</p>

<p>环线上的公交车都可以按顺时针和逆时针的方向行驶。</p>

<p>返回乘客从出发点&nbsp;<code>start</code>&nbsp;到目的地&nbsp;<code>destination</code>&nbsp;之间的最短距离。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1184.Distance%20Between%20Bus%20Stops/images/untitled-diagram-1.jpg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 1
<strong>输出：</strong>1
<strong>解释：</strong>公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1184.Distance%20Between%20Bus%20Stops/images/untitled-diagram-1-1.jpg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 2
<strong>输出：</strong>3
<strong>解释：</strong>公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
</pre>

<p>&nbsp;</p>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1184.Distance%20Between%20Bus%20Stops/images/untitled-diagram-1-2.jpg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 3
<strong>输出：</strong>4
<strong>解释：</strong>公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n&nbsp;&lt;= 10^4</code></li>
	<li><code>distance.length == n</code></li>
	<li><code>0 &lt;= start, destination &lt; n</code></li>
	<li><code>0 &lt;= distance[i] &lt;= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以先统计出公交车的总行驶距离 $s$，然后模拟公交车的行驶过程，从出发点开始，每次向右移动一站，直到到达目的地为止，记录下这个过程中的行驶距离 $t$，最后返回 $t$ 和 $s - t$ 中的最小值即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{distance}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distanceBetweenBusStops(
        self, distance: List[int], start: int, destination: int
    ) -> int:
        s = sum(distance)
        t, n = 0, len(distance)
        while start != destination:
            t += distance[start]
            start = (start + 1) % n
        return min(t, s - t)
```

#### Java

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int s = Arrays.stream(distance).sum();
        int n = distance.length, t = 0;
        while (start != destination) {
            t += distance[start];
            start = (start + 1) % n;
        }
        return Math.min(t, s - t);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s = accumulate(distance.begin(), distance.end(), 0);
        int t = 0, n = distance.size();
        while (start != destination) {
            t += distance[start];
            start = (start + 1) % n;
        }
        return min(t, s - t);
    }
};
```

#### Go

```go
func distanceBetweenBusStops(distance []int, start int, destination int) int {
	s, t := 0, 0
	for _, x := range distance {
		s += x
	}
	for start != destination {
		t += distance[start]
		start = (start + 1) % len(distance)
	}
	return min(t, s-t)
}
```

#### TypeScript

```ts
function distanceBetweenBusStops(distance: number[], start: number, destination: number): number {
    const s = distance.reduce((a, b) => a + b, 0);
    const n = distance.length;
    let t = 0;
    while (start !== destination) {
        t += distance[start];
        start = (start + 1) % n;
    }
    return Math.min(t, s - t);
}
```

#### Rust

```rust
impl Solution {
    pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
        let s: i32 = distance.iter().sum();
        let mut t = 0;
        let n = distance.len();
        let mut start = start as usize;
        let destination = destination as usize;

        while start != destination {
            t += distance[start];
            start = (start + 1) % n;
        }

        t.min(s - t)
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
var distanceBetweenBusStops = function (distance, start, destination) {
    const s = distance.reduce((a, b) => a + b, 0);
    const n = distance.length;
    let t = 0;
    while (start !== destination) {
        t += distance[start];
        start = (start + 1) % n;
    }
    return Math.min(t, s - t);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1185. 一周中的第几天](https://leetcode.cn/problems/day-of-the-week){#1185}

{{< tabs "1185" >}}

{{% tab "python" %}}
```python
class Solution:
    def dayOfTheWeek(self, d: int, m: int, y: int) -> str:
        if m < 3:
            m += 12
            y -= 1
        c = y // 100
        y = y % 100
        w = (c // 4 - 2 * c + y + y // 4 + 13 * (m + 1) // 5 + d - 1) % 7
        return [
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        ][w]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String dayOfTheWeek(int d, int m, int y) {
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int c = y / 100;
        y %= 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        return new String[] {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
            "Saturday"}[(w + 7) % 7];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int c = y / 100;
        y %= 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return weeks[(w + 7) % 7];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func dayOfTheWeek(d int, m int, y int) string {
	if m < 3 {
		m += 12
		y -= 1
	}
	c := y / 100
	y %= 100
	w := (c/4 - 2*c + y + y/4 + 13*(m+1)/5 + d - 1) % 7
	weeks := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
	return weeks[(w+7)%7]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function dayOfTheWeek(d: number, m: number, y: number): string {
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    const c: number = (y / 100) | 0;
    y %= 100;
    const w = (((c / 4) | 0) - 2 * c + y + ((y / 4) | 0) + (((13 * (m + 1)) / 5) | 0) + d - 1) % 7;
    const weeks: string[] = [
        'Sunday',
        'Monday',
        'Tuesday',
        'Wednesday',
        'Thursday',
        'Friday',
        'Saturday',
    ];
    return weeks[(w + 7) % 7];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。</p>

<p>输入为三个整数：<code>day</code>、<code>month</code> 和&nbsp;<code>year</code>，分别表示日、月、年。</p>

<p>您返回的结果必须是这几个值中的一个&nbsp;<code>{&quot;Sunday&quot;, &quot;Monday&quot;, &quot;Tuesday&quot;, &quot;Wednesday&quot;, &quot;Thursday&quot;, &quot;Friday&quot;, &quot;Saturday&quot;}</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>day = 31, month = 8, year = 2019
<strong>输出：</strong>&quot;Saturday&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>day = 18, month = 7, year = 1999
<strong>输出：</strong>&quot;Sunday&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>day = 15, month = 8, year = 1993
<strong>输出：</strong>&quot;Sunday&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给出的日期一定是在&nbsp;<code>1971</code> 到&nbsp;<code>2100</code>&nbsp;年之间的有效日期。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：蔡勒公式

我们可以使用蔡勒公式来计算星期几，蔡勒公式如下：

$$
w = (\left \lfloor \frac{c}{4} \right \rfloor - 2c + y + \left \lfloor \frac{y}{4} \right \rfloor + \left \lfloor \frac{13(m+1)}{5} \right \rfloor + d - 1) \bmod 7
$$

其中：

-   `w`: 星期（从 Sunday 开始）
-   `c`: 年份前两位
-   `y`: 年份后两位
-   `m`: 月（m 的取值范围是 3 至 14，即在蔡勒公式中，某年的 1、2 月要看作上一年的 13、14 月来计算，比如 2003 年 1 月 1 日要看作 2002 年的 13 月 1 日来计算）
-   `d`: 日
-   `⌊⌋`: 向下取整
-   `mod`: 取余

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        return datetime.date(year, month, day).strftime('%A')
```

#### Java

```java
import java.util.Calendar;

class Solution {
    private static final String[] WEEK
        = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    public static String dayOfTheWeek(int day, int month, int year) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month - 1, day);
        return WEEK[calendar.get(Calendar.DAY_OF_WEEK) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int c = y / 100;
        y %= 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return weeks[(w + 7) % 7];
    }
};
```

#### Go

```go
func dayOfTheWeek(d int, m int, y int) string {
	if m < 3 {
		m += 12
		y -= 1
	}
	c := y / 100
	y %= 100
	w := (c/4 - 2*c + y + y/4 + 13*(m+1)/5 + d - 1) % 7
	weeks := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
	return weeks[(w+7)%7]
}
```

#### TypeScript

```ts
function dayOfTheWeek(d: number, m: number, y: number): string {
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    const c: number = (y / 100) | 0;
    y %= 100;
    const w = (((c / 4) | 0) - 2 * c + y + ((y / 4) | 0) + (((13 * (m + 1)) / 5) | 0) + d - 1) % 7;
    const weeks: string[] = [
        'Sunday',
        'Monday',
        'Tuesday',
        'Wednesday',
        'Thursday',
        'Friday',
        'Saturday',
    ];
    return weeks[(w + 7) % 7];
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
    def dayOfTheWeek(self, d: int, m: int, y: int) -> str:
        if m < 3:
            m += 12
            y -= 1
        c = y // 100
        y = y % 100
        w = (c // 4 - 2 * c + y + y // 4 + 13 * (m + 1) // 5 + d - 1) % 7
        return [
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        ][w]
```

#### Java

```java
class Solution {
    public String dayOfTheWeek(int d, int m, int y) {
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int c = y / 100;
        y %= 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        return new String[] {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
            "Saturday"}[(w + 7) % 7];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1186. 删除一次得到子数组最大和](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion){#1186}

{{< tabs "1186" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        left = [0] * n
        right = [0] * n
        s = 0
        for i, x in enumerate(arr):
            s = max(s, 0) + x
            left[i] = s
        s = 0
        for i in range(n - 1, -1, -1):
            s = max(s, 0) + arr[i]
            right[i] = s
        ans = max(left)
        for i in range(1, n - 1):
            ans = max(ans, left[i - 1] + right[i + 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int ans = -(1 << 30);
        for (int i = 0, s = 0; i < n; ++i) {
            s = Math.max(s, 0) + arr[i];
            left[i] = s;
            ans = Math.max(ans, left[i]);
        }
        for (int i = n - 1, s = 0; i >= 0; --i) {
            s = Math.max(s, 0) + arr[i];
            right[i] = s;
        }
        for (int i = 1; i < n - 1; ++i) {
            ans = Math.max(ans, left[i - 1] + right[i + 1]);
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
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int left[n];
        int right[n];
        for (int i = 0, s = 0; i < n; ++i) {
            s = max(s, 0) + arr[i];
            left[i] = s;
        }
        for (int i = n - 1, s = 0; ~i; --i) {
            s = max(s, 0) + arr[i];
            right[i] = s;
        }
        int ans = *max_element(left, left + n);
        for (int i = 1; i < n - 1; ++i) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSum(arr []int) int {
	n := len(arr)
	left := make([]int, n)
	right := make([]int, n)
	for i, s := 0, 0; i < n; i++ {
		s = max(s, 0) + arr[i]
		left[i] = s
	}
	for i, s := n-1, 0; i >= 0; i-- {
		s = max(s, 0) + arr[i]
		right[i] = s
	}
	ans := slices.Max(left)
	for i := 1; i < n-1; i++ {
		ans = max(ans, left[i-1]+right[i+1])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSum(arr: number[]): number {
    const n = arr.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);
    for (let i = 0, s = 0; i < n; ++i) {
        s = Math.max(s, 0) + arr[i];
        left[i] = s;
    }
    for (let i = n - 1, s = 0; i >= 0; --i) {
        s = Math.max(s, 0) + arr[i];
        right[i] = s;
    }
    let ans = Math.max(...left);
    for (let i = 1; i < n - 1; ++i) {
        ans = Math.max(ans, left[i - 1] + right[i + 1]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_sum(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut s = 0;
        for i in 0..n {
            s = (s.max(0)) + arr[i];
            left[i] = s;
        }
        s = 0;
        for i in (0..n).rev() {
            s = (s.max(0)) + arr[i];
            right[i] = s;
        }
        let mut ans = *left.iter().max().unwrap();
        for i in 1..n - 1 {
            ans = ans.max(left[i - 1] + right[i + 1]);
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

<p>给你一个整数数组，返回它的某个&nbsp;<strong>非空</strong> 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。</p>

<p>注意，删除一个元素后，子数组 <strong>不能为空</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,-2,0,3]
<strong>输出：</strong>4
<strong>解释：</strong>我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,-2,-2,3]
<strong>输出：</strong>3
<strong>解释：</strong>我们直接选出 [3]，这就是最大和。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [-1,-1,-1,-1]
<strong>输出：</strong>-1
<strong>解释：</strong>最后得到的子数组不能为空，所以我们不能选择 [-1] 并从中删去 -1 来得到 0。
     我们应该直接选择 [-1]，或者选择 [-1, -1] 再从中删去一个 -1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

我们可以先预处理出数组 $\textit{arr}$ 以每个元素结尾和开头的最大子数组和，分别存入数组 $\textit{left}$ 和 $\textit{right}$ 中。

如果我们不删除任何元素，那么最大子数组和就是 $\textit{left}[i]$ 或 $\textit{right}[i]$ 中的最大值；如果我们删除一个元素，我们可以枚举 $[1..n-2]$ 中的每个位置 $i$，计算 $\textit{left}[i-1] + \textit{right}[i+1]$ 的值，取最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        left = [0] * n
        right = [0] * n
        s = 0
        for i, x in enumerate(arr):
            s = max(s, 0) + x
            left[i] = s
        s = 0
        for i in range(n - 1, -1, -1):
            s = max(s, 0) + arr[i]
            right[i] = s
        ans = max(left)
        for i in range(1, n - 1):
            ans = max(ans, left[i - 1] + right[i + 1])
        return ans
```

#### Java

```java
class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int ans = -(1 << 30);
        for (int i = 0, s = 0; i < n; ++i) {
            s = Math.max(s, 0) + arr[i];
            left[i] = s;
            ans = Math.max(ans, left[i]);
        }
        for (int i = n - 1, s = 0; i >= 0; --i) {
            s = Math.max(s, 0) + arr[i];
            right[i] = s;
        }
        for (int i = 1; i < n - 1; ++i) {
            ans = Math.max(ans, left[i - 1] + right[i + 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int left[n];
        int right[n];
        for (int i = 0, s = 0; i < n; ++i) {
            s = max(s, 0) + arr[i];
            left[i] = s;
        }
        for (int i = n - 1, s = 0; ~i; --i) {
            s = max(s, 0) + arr[i];
            right[i] = s;
        }
        int ans = *max_element(left, left + n);
        for (int i = 1; i < n - 1; ++i) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSum(arr []int) int {
	n := len(arr)
	left := make([]int, n)
	right := make([]int, n)
	for i, s := 0, 0; i < n; i++ {
		s = max(s, 0) + arr[i]
		left[i] = s
	}
	for i, s := n-1, 0; i >= 0; i-- {
		s = max(s, 0) + arr[i]
		right[i] = s
	}
	ans := slices.Max(left)
	for i := 1; i < n-1; i++ {
		ans = max(ans, left[i-1]+right[i+1])
	}
	return ans
}
```

#### TypeScript

```ts
function maximumSum(arr: number[]): number {
    const n = arr.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);
    for (let i = 0, s = 0; i < n; ++i) {
        s = Math.max(s, 0) + arr[i];
        left[i] = s;
    }
    for (let i = n - 1, s = 0; i >= 0; --i) {
        s = Math.max(s, 0) + arr[i];
        right[i] = s;
    }
    let ans = Math.max(...left);
    for (let i = 1; i < n - 1; ++i) {
        ans = Math.max(ans, left[i - 1] + right[i + 1]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_sum(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut s = 0;
        for i in 0..n {
            s = (s.max(0)) + arr[i];
            left[i] = s;
        }
        s = 0;
        for i in (0..n).rev() {
            s = (s.max(0)) + arr[i];
            right[i] = s;
        }
        let mut ans = *left.iter().max().unwrap();
        for i in 1..n - 1 {
            ans = ans.max(left[i - 1] + right[i + 1]);
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

# [1187. 使数组严格递增](https://leetcode.cn/problems/make-array-strictly-increasing){#1187}

{{< tabs "1187" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        m = 0
        for x in arr2:
            if m == 0 or x != arr2[m - 1]:
                arr2[m] = x
                m += 1
        arr2 = arr2[:m]
        arr = [-inf] + arr1 + [inf]
        n = len(arr)
        f = [inf] * n
        f[0] = 0
        for i in range(1, n):
            if arr[i - 1] < arr[i]:
                f[i] = f[i - 1]
            j = bisect_left(arr2, arr[i])
            for k in range(1, min(i - 1, j) + 1):
                if arr[i - k - 1] < arr2[j - k]:
                    f[i] = min(f[i], f[i - k - 1] + k)
        return -1 if f[n - 1] >= inf else f[n - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        Arrays.sort(arr2);
        int m = 0;
        for (int x : arr2) {
            if (m == 0 || x != arr2[m - 1]) {
                arr2[m++] = x;
            }
        }
        final int inf = 1 << 30;
        int[] arr = new int[arr1.length + 2];
        arr[0] = -inf;
        arr[arr.length - 1] = inf;
        System.arraycopy(arr1, 0, arr, 1, arr1.length);
        int[] f = new int[arr.length];
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 1; i < arr.length; ++i) {
            if (arr[i - 1] < arr[i]) {
                f[i] = f[i - 1];
            }
            int j = search(arr2, arr[i], m);
            for (int k = 1; k <= Math.min(i - 1, j); ++k) {
                if (arr[i - k - 1] < arr2[j - k]) {
                    f[i] = Math.min(f[i], f[i - k - 1] + k);
                }
            }
        }
        return f[arr.length - 1] >= inf ? -1 : f[arr.length - 1];
    }

    private int search(int[] nums, int x, int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        const int inf = 1 << 30;
        arr1.insert(arr1.begin(), -inf);
        arr1.push_back(inf);
        int n = arr1.size();
        vector<int> f(n, inf);
        f[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (arr1[i - 1] < arr1[i]) {
                f[i] = f[i - 1];
            }
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            for (int k = 1; k <= min(i - 1, j); ++k) {
                if (arr1[i - k - 1] < arr2[j - k]) {
                    f[i] = min(f[i], f[i - k - 1] + k);
                }
            }
        }
        return f[n - 1] >= inf ? -1 : f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeArrayIncreasing(arr1 []int, arr2 []int) int {
	sort.Ints(arr2)
	m := 0
	for _, x := range arr2 {
		if m == 0 || x != arr2[m-1] {
			arr2[m] = x
			m++
		}
	}
	arr2 = arr2[:m]
	const inf = 1 << 30
	arr1 = append([]int{-inf}, arr1...)
	arr1 = append(arr1, inf)
	n := len(arr1)
	f := make([]int, n)
	for i := range f {
		f[i] = inf
	}
	f[0] = 0
	for i := 1; i < n; i++ {
		if arr1[i-1] < arr1[i] {
			f[i] = f[i-1]
		}
		j := sort.SearchInts(arr2, arr1[i])
		for k := 1; k <= min(i-1, j); k++ {
			if arr1[i-k-1] < arr2[j-k] {
				f[i] = min(f[i], f[i-k-1]+k)
			}
		}
	}
	if f[n-1] >= inf {
		return -1
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeArrayIncreasing(arr1: number[], arr2: number[]): number {
    arr2.sort((a, b) => a - b);
    let m = 0;
    for (const x of arr2) {
        if (m === 0 || x !== arr2[m - 1]) {
            arr2[m++] = x;
        }
    }
    arr2 = arr2.slice(0, m);
    const inf = 1 << 30;
    arr1 = [-inf, ...arr1, inf];
    const n = arr1.length;
    const f: number[] = new Array(n).fill(inf);
    f[0] = 0;
    const search = (arr: number[], x: number): number => {
        let l = 0;
        let r = arr.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i < n; ++i) {
        if (arr1[i - 1] < arr1[i]) {
            f[i] = f[i - 1];
        }
        const j = search(arr2, arr1[i]);
        for (let k = 1; k <= Math.min(i - 1, j); ++k) {
            if (arr1[i - k - 1] < arr2[j - k]) {
                f[i] = Math.min(f[i], f[i - k - 1] + k);
            }
        }
    }
    return f[n - 1] >= inf ? -1 : f[n - 1];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MakeArrayIncreasing(int[] arr1, int[] arr2) {
        Array.Sort(arr2);
        int m = 0;
        foreach (int x in arr2) {
            if (m == 0 || x != arr2[m - 1]) {
                arr2[m++] = x;
            }
        }
        int inf = 1 << 30;
        int[] arr = new int[arr1.Length + 2];
        arr[0] = -inf;
        arr[arr.Length - 1] = inf;
        for (int i = 0; i < arr1.Length; ++i) {
            arr[i + 1] = arr1[i];
        }
        int[] f = new int[arr.Length];
        Array.Fill(f, inf);
        f[0] = 0;
        for (int i = 1; i < arr.Length; ++i) {
            if (arr[i - 1] < arr[i]) {
                f[i] = f[i - 1];
            }
            int j = search(arr2, arr[i], m);
            for (int k = 1; k <= Math.Min(i - 1, j); ++k) {
                if (arr[i - k - 1] < arr2[j - k]) {
                    f[i] = Math.Min(f[i], f[i - k - 1] + k);
                }
            }
        }
        return f[arr.Length - 1] >= inf ? -1 : f[arr.Length - 1];
    }

    private int search(int[] nums, int x, int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组&nbsp;<code>arr1</code> 和 <code>arr2</code>，返回使&nbsp;<code>arr1</code>&nbsp;严格递增所需要的最小「操作」数（可能为 0）。</p>

<p>每一步「操作」中，你可以分别从 <code>arr1</code> 和 <code>arr2</code> 中各选出一个索引，分别为&nbsp;<code>i</code> 和&nbsp;<code>j</code>，<code>0 &lt;=&nbsp;i &lt; arr1.length</code>&nbsp;和&nbsp;<code>0 &lt;= j &lt; arr2.length</code>，然后进行赋值运算&nbsp;<code>arr1[i] = arr2[j]</code>。</p>

<p>如果无法让&nbsp;<code>arr1</code>&nbsp;严格递增，请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
<strong>输出：</strong>1
<strong>解释：</strong>用 2 来替换 <code>5，之后</code> <code>arr1 = [1, 2, 3, 6, 7]</code>。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,5,3,6,7], arr2 = [4,3,1]
<strong>输出：</strong>2
<strong>解释：</strong>用 3 来替换 <code>5，然后</code>用 4 来替换 3<code>，得到</code> <code>arr1 = [1, 3, 4, 6, 7]</code>。
</pre>

<p><strong class="example">示例&nbsp;3：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
<strong>输出：</strong>-1
<strong>解释：</strong>无法使 <code>arr1 严格递增</code>。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 2000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 10^9</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示将 $arr1[0,..,i]$ 转换为严格递增数组，且 $arr1[i]$ 不替换的最小操作数。因此，我们在 $arr1$ 设置首尾两个哨兵 $-\infty$ 和 $\infty$。最后一个数一定是不替换，因此 $f[n-1]$ 即为答案。我们初始化 $f[0]=0$，其余 $f[i]=\infty$。

接下来我们对数组 $arr2$ 进行排序并去重，方便进行二分查找。

对于 $i=1,..,n-1$，我们考虑 $arr1[i-1]$ 是否替换。如果 $arr1[i-1] \lt arr1[i]$，那么 $f[i]$ 可以从 $f[i-1]$ 转移而来，即 $f[i] = f[i-1]$。然后，我们考虑 $arr[i-1]$ 替换的情况，显然 $arr[i-1]$ 应该替换成一个尽可能大的、且比 $arr[i]$ 小的数字，我们在数组 $arr2$ 中进行二分查找，找到第一个大于等于 $arr[i]$ 的下标 $j$。然后我们在 $k \in [1, \min(i-1, j)]$ 的范围内枚举替换的个数，如果满足 $arr[i-k-1] \lt arr2[j-k]$，那么 $f[i]$ 可以从 $f[i-k-1]$ 转移而来，即 $f[i] = \min(f[i], f[i-k-1] + k)$。

最后，如果 $f[n-1] \geq \infty$，说明无法转换为严格递增数组，返回 $-1$，否则返回 $f[n-1]$。

时间复杂度 $(n \times (\log m + \min(m, n)))$，空间复杂度 $O(n)$。其中 $n$ 为 $arr1$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        m = 0
        for x in arr2:
            if m == 0 or x != arr2[m - 1]:
                arr2[m] = x
                m += 1
        arr2 = arr2[:m]
        arr = [-inf] + arr1 + [inf]
        n = len(arr)
        f = [inf] * n
        f[0] = 0
        for i in range(1, n):
            if arr[i - 1] < arr[i]:
                f[i] = f[i - 1]
            j = bisect_left(arr2, arr[i])
            for k in range(1, min(i - 1, j) + 1):
                if arr[i - k - 1] < arr2[j - k]:
                    f[i] = min(f[i], f[i - k - 1] + k)
        return -1 if f[n - 1] >= inf else f[n - 1]
```

#### Java

```java
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        Arrays.sort(arr2);
        int m = 0;
        for (int x : arr2) {
            if (m == 0 || x != arr2[m - 1]) {
                arr2[m++] = x;
            }
        }
        final int inf = 1 << 30;
        int[] arr = new int[arr1.length + 2];
        arr[0] = -inf;
        arr[arr.length - 1] = inf;
        System.arraycopy(arr1, 0, arr, 1, arr1.length);
        int[] f = new int[arr.length];
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 1; i < arr.length; ++i) {
            if (arr[i - 1] < arr[i]) {
                f[i] = f[i - 1];
            }
            int j = search(arr2, arr[i], m);
            for (int k = 1; k <= Math.min(i - 1, j); ++k) {
                if (arr[i - k - 1] < arr2[j - k]) {
                    f[i] = Math.min(f[i], f[i - k - 1] + k);
                }
            }
        }
        return f[arr.length - 1] >= inf ? -1 : f[arr.length - 1];
    }

    private int search(int[] nums, int x, int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        const int inf = 1 << 30;
        arr1.insert(arr1.begin(), -inf);
        arr1.push_back(inf);
        int n = arr1.size();
        vector<int> f(n, inf);
        f[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (arr1[i - 1] < arr1[i]) {
                f[i] = f[i - 1];
            }
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            for (int k = 1; k <= min(i - 1, j); ++k) {
                if (arr1[i - k - 1] < arr2[j - k]) {
                    f[i] = min(f[i], f[i - k - 1] + k);
                }
            }
        }
        return f[n - 1] >= inf ? -1 : f[n - 1];
    }
};
```

#### Go

```go
func makeArrayIncreasing(arr1 []int, arr2 []int) int {
	sort.Ints(arr2)
	m := 0
	for _, x := range arr2 {
		if m == 0 || x != arr2[m-1] {
			arr2[m] = x
			m++
		}
	}
	arr2 = arr2[:m]
	const inf = 1 << 30
	arr1 = append([]int{-inf}, arr1...)
	arr1 = append(arr1, inf)
	n := len(arr1)
	f := make([]int, n)
	for i := range f {
		f[i] = inf
	}
	f[0] = 0
	for i := 1; i < n; i++ {
		if arr1[i-1] < arr1[i] {
			f[i] = f[i-1]
		}
		j := sort.SearchInts(arr2, arr1[i])
		for k := 1; k <= min(i-1, j); k++ {
			if arr1[i-k-1] < arr2[j-k] {
				f[i] = min(f[i], f[i-k-1]+k)
			}
		}
	}
	if f[n-1] >= inf {
		return -1
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function makeArrayIncreasing(arr1: number[], arr2: number[]): number {
    arr2.sort((a, b) => a - b);
    let m = 0;
    for (const x of arr2) {
        if (m === 0 || x !== arr2[m - 1]) {
            arr2[m++] = x;
        }
    }
    arr2 = arr2.slice(0, m);
    const inf = 1 << 30;
    arr1 = [-inf, ...arr1, inf];
    const n = arr1.length;
    const f: number[] = new Array(n).fill(inf);
    f[0] = 0;
    const search = (arr: number[], x: number): number => {
        let l = 0;
        let r = arr.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i < n; ++i) {
        if (arr1[i - 1] < arr1[i]) {
            f[i] = f[i - 1];
        }
        const j = search(arr2, arr1[i]);
        for (let k = 1; k <= Math.min(i - 1, j); ++k) {
            if (arr1[i - k - 1] < arr2[j - k]) {
                f[i] = Math.min(f[i], f[i - k - 1] + k);
            }
        }
    }
    return f[n - 1] >= inf ? -1 : f[n - 1];
}
```

#### C#

```cs
public class Solution {
    public int MakeArrayIncreasing(int[] arr1, int[] arr2) {
        Array.Sort(arr2);
        int m = 0;
        foreach (int x in arr2) {
            if (m == 0 || x != arr2[m - 1]) {
                arr2[m++] = x;
            }
        }
        int inf = 1 << 30;
        int[] arr = new int[arr1.Length + 2];
        arr[0] = -inf;
        arr[arr.Length - 1] = inf;
        for (int i = 0; i < arr1.Length; ++i) {
            arr[i + 1] = arr1[i];
        }
        int[] f = new int[arr.Length];
        Array.Fill(f, inf);
        f[0] = 0;
        for (int i = 1; i < arr.Length; ++i) {
            if (arr[i - 1] < arr[i]) {
                f[i] = f[i - 1];
            }
            int j = search(arr2, arr[i], m);
            for (int k = 1; k <= Math.Min(i - 1, j); ++k) {
                if (arr[i - k - 1] < arr2[j - k]) {
                    f[i] = Math.Min(f[i], f[i - k - 1] + k);
                }
            }
        }
        return f[arr.Length - 1] >= inf ? -1 : f[arr.Length - 1];
    }

    private int search(int[] nums, int x, int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1188. 设计有限阻塞队列 🔒](https://leetcode.cn/problems/design-bounded-blocking-queue){#1188}

{{< tabs "1188" >}}

{{% tab "python" %}}
```python
from threading import Semaphore


class BoundedBlockingQueue(object):
    def __init__(self, capacity: int):
        self.s1 = Semaphore(capacity)
        self.s2 = Semaphore(0)
        self.q = deque()

    def enqueue(self, element: int) -> None:
        self.s1.acquire()
        self.q.append(element)
        self.s2.release()

    def dequeue(self) -> int:
        self.s2.acquire()
        ans = self.q.popleft()
        self.s1.release()
        return ans

    def size(self) -> int:
        return len(self.q)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BoundedBlockingQueue {
    private Semaphore s1;
    private Semaphore s2;
    private Deque<Integer> q = new ArrayDeque<>();

    public BoundedBlockingQueue(int capacity) {
        s1 = new Semaphore(capacity);
        s2 = new Semaphore(0);
    }

    public void enqueue(int element) throws InterruptedException {
        s1.acquire();
        q.offer(element);
        s2.release();
    }

    public int dequeue() throws InterruptedException {
        s2.acquire();
        int ans = q.poll();
        s1.release();
        return ans;
    }

    public int size() {
        return q.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <semaphore.h>

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        sem_init(&s1, 0, capacity);
        sem_init(&s2, 0, 0);
    }

    void enqueue(int element) {
        sem_wait(&s1);
        q.push(element);
        sem_post(&s2);
    }

    int dequeue() {
        sem_wait(&s2);
        int ans = q.front();
        q.pop();
        sem_post(&s1);
        return ans;
    }

    int size() {
        return q.size();
    }

private:
    queue<int> q;
    sem_t s1, s2;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实现一个拥有如下方法的线程安全有限阻塞队列：</p>

<ul>
	<li><code>BoundedBlockingQueue(int capacity)</code>&nbsp;构造方法初始化队列，其中<code>capacity</code>代表队列长度上限。</li>
	<li><code>void enqueue(int element)</code>&nbsp;在队首增加一个<code>element</code>. 如果队列满，调用线程被阻塞直到队列非满。</li>
	<li><code>int dequeue()</code>&nbsp;返回队尾元素并从队列中将其删除. 如果队列为空，调用线程被阻塞直到队列非空。</li>
	<li><code>int size()</code>&nbsp;返回当前队列元素个数。</li>
</ul>

<p>你的实现将会被多线程同时访问进行测试。每一个线程要么是一个只调用<code>enqueue</code>方法的生产者线程，要么是一个只调用<code>dequeue</code>方法的消费者线程。<code>size</code>方法将会在每一个测试用例之后进行调用。</p>

<p>请不要使用内置的有限阻塞队列实现，否则面试将不会通过。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong>
1
1
["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
[[2],[1],[],[],[0],[2],[3],[4],[]]

<strong>输出:</strong>
[1,0,2,2]

<strong>解释:
</strong>生产者线程数目 = 1
消费者线程数目 = 1

BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // 使用capacity = 2初始化队列。

queue.enqueue(1);   // 生产者线程将 1 插入队列。
queue.dequeue();    // 消费者线程调用 dequeue 并返回 1 。
queue.dequeue();    // 由于队列为空，消费者线程被阻塞。
queue.enqueue(0);   // 生产者线程将 0 插入队列。消费者线程被解除阻塞同时将 0 弹出队列并返回。
queue.enqueue(2);   // 生产者线程将 2 插入队列。
queue.enqueue(3);   // 生产者线程将 3 插入队列。
queue.enqueue(4);   // 生产者线程由于队列长度已达到上限 2 而被阻塞。
queue.dequeue();    // 消费者线程将 2 从队列弹出并返回。生产者线程解除阻塞同时将4插入队列。
queue.size();       // 队列中还有 2 个元素。size()方法在每组测试用例最后调用。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>
3
4
["BoundedBlockingQueue","enqueue","enqueue","enqueue","dequeue","dequeue","dequeue","enqueue"]
[[3],[1],[0],[2],[],[],[],[3]]

<strong>输出:</strong>
[1,0,2,1]

<strong>解释:
</strong>生产者线程数目 = 3
消费者线程数目 = 4

BoundedBlockingQueue queue = new BoundedBlockingQueue(3);   // 使用capacity = 3初始化队列。

queue.enqueue(1);   // 生产者线程 P1 将 1 插入队列。
queue.enqueue(0);   // 生产者线程 P2 将 0 插入队列。
queue.enqueue(2);   // 生产者线程 P3 将2插入队列。
queue.dequeue();    // 消费者线程 C1 调用 dequeue。
queue.dequeue();    // 消费者线程 C2 调用 dequeue。
queue.dequeue();    // 消费者线程 C3 调用 dequeue。
queue.enqueue(3);   // 其中一个生产者线程将3插入队列。
queue.size();       // 队列中还有 1 个元素。

由于生产者/消费者线程的数目可能大于 1 ，我们并不知道线程如何被操作系统调度，即使输入看上去隐含了顺序。因此任意一种输出[1,0,2]或[1,2,0]或[0,1,2]或[0,2,1]或[2,0,1]或[2,1,0]都可被接受。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Prdoucers &lt;= 8</code></li>
	<li><code>1 &lt;= Number of Consumers &lt;= 8</code></li>
	<li><code>1 &lt;= size &lt;= 30</code></li>
	<li><code>0 &lt;= element &lt;= 20</code></li>
	<li>&nbsp;<code>enqueue</code>的调用次数&nbsp;<strong>大于等于</strong> &nbsp;<code>dequeue</code>&nbsp;的调用次数。</li>
	<li>&nbsp;<code>enque</code>,&nbsp;<code>deque</code> 和&nbsp;<code>size</code>&nbsp;最多被调用&nbsp;<code>40</code>&nbsp;次</li>
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
from threading import Semaphore


class BoundedBlockingQueue(object):
    def __init__(self, capacity: int):
        self.s1 = Semaphore(capacity)
        self.s2 = Semaphore(0)
        self.q = deque()

    def enqueue(self, element: int) -> None:
        self.s1.acquire()
        self.q.append(element)
        self.s2.release()

    def dequeue(self) -> int:
        self.s2.acquire()
        ans = self.q.popleft()
        self.s1.release()
        return ans

    def size(self) -> int:
        return len(self.q)
```

#### Java

```java
class BoundedBlockingQueue {
    private Semaphore s1;
    private Semaphore s2;
    private Deque<Integer> q = new ArrayDeque<>();

    public BoundedBlockingQueue(int capacity) {
        s1 = new Semaphore(capacity);
        s2 = new Semaphore(0);
    }

    public void enqueue(int element) throws InterruptedException {
        s1.acquire();
        q.offer(element);
        s2.release();
    }

    public int dequeue() throws InterruptedException {
        s2.acquire();
        int ans = q.poll();
        s1.release();
        return ans;
    }

    public int size() {
        return q.size();
    }
}
```

#### C++

```cpp
#include <semaphore.h>

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        sem_init(&s1, 0, capacity);
        sem_init(&s2, 0, 0);
    }

    void enqueue(int element) {
        sem_wait(&s1);
        q.push(element);
        sem_post(&s2);
    }

    int dequeue() {
        sem_wait(&s2);
        int ans = q.front();
        q.pop();
        sem_post(&s1);
        return ans;
    }

    int size() {
        return q.size();
    }

private:
    queue<int> q;
    sem_t s1, s2;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1189. “气球” 的最大数量](https://leetcode.cn/problems/maximum-number-of-balloons){#1189}

{{< tabs "1189" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = Counter(text)
        cnt['o'] >>= 1
        cnt['l'] >>= 1
        return min(cnt[c] for c in 'balon')
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] cnt = new int[26];
        for (int i = 0; i < text.length(); ++i) {
            ++cnt[text.charAt(i) - 'a'];
        }
        cnt['l' - 'a'] >>= 1;
        cnt['o' - 'a'] >>= 1;
        int ans = 1 << 30;
        for (char c : "balon".toCharArray()) {
            ans = Math.min(ans, cnt[c - 'a']);
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
    int maxNumberOfBalloons(string text) {
        int cnt[26]{};
        for (char c : text) {
            ++cnt[c - 'a'];
        }
        cnt['o' - 'a'] >>= 1;
        cnt['l' - 'a'] >>= 1;
        int ans = 1 << 30;
        string t = "balon";
        for (char c : t) {
            ans = min(ans, cnt[c - 'a']);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumberOfBalloons(text string) int {
	cnt := [26]int{}
	for _, c := range text {
		cnt[c-'a']++
	}
	cnt['l'-'a'] >>= 1
	cnt['o'-'a'] >>= 1
	ans := 1 << 30
	for _, c := range "balon" {
		if x := cnt[c-'a']; ans > x {
			ans = x
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNumberOfBalloons(text: string): number {
    const cnt = new Array(26).fill(0);
    for (const c of text) {
        cnt[c.charCodeAt(0) - 97]++;
    }
    return Math.min(cnt[0], cnt[1], cnt[11] >> 1, cnt[14] >> 1, cnt[13]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut arr = [0; 5];
        for c in text.chars() {
            match c {
                'b' => {
                    arr[0] += 1;
                }
                'a' => {
                    arr[1] += 1;
                }
                'l' => {
                    arr[2] += 1;
                }
                'o' => {
                    arr[3] += 1;
                }
                'n' => {
                    arr[4] += 1;
                }
                _ => {}
            }
        }
        arr[2] /= 2;
        arr[3] /= 2;
        let mut res = i32::MAX;
        for num in arr {
            res = res.min(num);
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $text
     * @return Integer
     */
    function maxNumberOfBalloons($text) {
        $cnt1 = $cnt2 = $cnt3 = $cnt4 = $cnt5 = 0;
        for ($i = 0; $i < strlen($text); $i++) {
            if ($text[$i] == 'b') {
                $cnt1 += 1;
            } elseif ($text[$i] == 'a') {
                $cnt2 += 1;
            } elseif ($text[$i] == 'l') {
                $cnt3 += 1;
            } elseif ($text[$i] == 'o') {
                $cnt4 += 1;
            } elseif ($text[$i] == 'n') {
                $cnt5 += 1;
            }
        }
        $cnt3 = floor($cnt3 / 2);
        $cnt4 = floor($cnt4 / 2);
        return min($cnt1, $cnt2, $cnt3, $cnt4, $cnt5);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>text</code>，你需要使用 <code>text</code> 中的字母来拼凑尽可能多的单词&nbsp;<strong>"balloon"（气球）</strong>。</p>

<p>字符串&nbsp;<code>text</code> 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词&nbsp;<strong>"balloon"</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1189.Maximum%20Number%20of%20Balloons/images/1536_ex1_upd.jpeg" style="height: 35px; width: 154px;" /></strong></p>

<pre>
<strong>输入：</strong>text = "nlaebolko"
<strong>输出：</strong>1
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1189.Maximum%20Number%20of%20Balloons/images/1536_ex2_upd.jpeg" style="height: 35px; width: 233px;" /></strong></p>

<pre>
<strong>输入：</strong>text = "loonbalxballpoon"
<strong>输出：</strong>2
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>text = "leetcode"
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>text</code>&nbsp;全部由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与&nbsp;<a href="https://leetcode.cn/problems/rearrange-characters-to-make-target-string/">2287. 重排字符形成目标字符串</a>&nbsp;相同。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们统计字符串 `text` 中每个字母出现的次数，然后将其中字母 `'o'` 和 `'l'` 的出现次数分别除以 2，这是因为单词 `balloon` 中字母 `'o'` 和 `'l'` 都出现了 2 次。

接着，我们遍历单词 `balon` 中的每个字母，统计每个字母在字符串 `text` 中出现的次数的最小值，这个最小值就是单词 `balloon` 在字符串 `text` 中出现的最大次数。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 `text` 的长度；而 $C$ 为字符集大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = Counter(text)
        cnt['o'] >>= 1
        cnt['l'] >>= 1
        return min(cnt[c] for c in 'balon')
```

#### Java

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] cnt = new int[26];
        for (int i = 0; i < text.length(); ++i) {
            ++cnt[text.charAt(i) - 'a'];
        }
        cnt['l' - 'a'] >>= 1;
        cnt['o' - 'a'] >>= 1;
        int ans = 1 << 30;
        for (char c : "balon".toCharArray()) {
            ans = Math.min(ans, cnt[c - 'a']);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26]{};
        for (char c : text) {
            ++cnt[c - 'a'];
        }
        cnt['o' - 'a'] >>= 1;
        cnt['l' - 'a'] >>= 1;
        int ans = 1 << 30;
        string t = "balon";
        for (char c : t) {
            ans = min(ans, cnt[c - 'a']);
        }
        return ans;
    }
};
```

#### Go

```go
func maxNumberOfBalloons(text string) int {
	cnt := [26]int{}
	for _, c := range text {
		cnt[c-'a']++
	}
	cnt['l'-'a'] >>= 1
	cnt['o'-'a'] >>= 1
	ans := 1 << 30
	for _, c := range "balon" {
		if x := cnt[c-'a']; ans > x {
			ans = x
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxNumberOfBalloons(text: string): number {
    const cnt = new Array(26).fill(0);
    for (const c of text) {
        cnt[c.charCodeAt(0) - 97]++;
    }
    return Math.min(cnt[0], cnt[1], cnt[11] >> 1, cnt[14] >> 1, cnt[13]);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut arr = [0; 5];
        for c in text.chars() {
            match c {
                'b' => {
                    arr[0] += 1;
                }
                'a' => {
                    arr[1] += 1;
                }
                'l' => {
                    arr[2] += 1;
                }
                'o' => {
                    arr[3] += 1;
                }
                'n' => {
                    arr[4] += 1;
                }
                _ => {}
            }
        }
        arr[2] /= 2;
        arr[3] /= 2;
        let mut res = i32::MAX;
        for num in arr {
            res = res.min(num);
        }
        res
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $text
     * @return Integer
     */
    function maxNumberOfBalloons($text) {
        $cnt1 = $cnt2 = $cnt3 = $cnt4 = $cnt5 = 0;
        for ($i = 0; $i < strlen($text); $i++) {
            if ($text[$i] == 'b') {
                $cnt1 += 1;
            } elseif ($text[$i] == 'a') {
                $cnt2 += 1;
            } elseif ($text[$i] == 'l') {
                $cnt3 += 1;
            } elseif ($text[$i] == 'o') {
                $cnt4 += 1;
            } elseif ($text[$i] == 'n') {
                $cnt5 += 1;
            }
        }
        $cnt3 = floor($cnt3 / 2);
        $cnt4 = floor($cnt4 / 2);
        return min($cnt1, $cnt2, $cnt3, $cnt4, $cnt5);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
