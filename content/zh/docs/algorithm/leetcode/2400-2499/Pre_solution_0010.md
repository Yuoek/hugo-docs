---
title: "2490_回环句"
date: 2025-10-08T18:39:18+08:00
weight: 10
tags: [二分查找, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 深度优先搜索, 计数, 贪心]
---

{{< markmap >}}
### [2490_回环句](#2490)
#### [字符串](#2490)
### [2491_划分技能点相等的团队](#2491)
#### [数组](#2491)
#### [哈希表](#2491)
#### [双指针](#2491)
#### [排序](#2491)
### [2492_两个城市间路径的最小分数](#2492)
#### [深度优先搜索](#2492)
#### [广度优先搜索](#2492)
#### [并查集](#2492)
#### [图](#2492)
### [2493_将节点分成尽可能多的组](#2493)
#### [深度优先搜索](#2493)
#### [广度优先搜索](#2493)
#### [并查集](#2493)
#### [图](#2493)
### [2494_合并在同一个大厅重叠的活动 🔒](#2494)
#### [数据库](#2494)
### [2495_乘积为偶数的子数组数 🔒](#2495)
#### [数组](#2495)
#### [数学](#2495)
#### [动态规划](#2495)
### [2496_数组中字符串的最大值](#2496)
#### [数组](#2496)
#### [字符串](#2496)
### [2497_图中最大星和](#2497)
#### [贪心](#2497)
#### [图](#2497)
#### [数组](#2497)
#### [排序](#2497)
#### [堆（优先队列）](#2497)
### [2498_青蛙过河 II](#2498)
#### [贪心](#2498)
#### [数组](#2498)
#### [二分查找](#2498)
### [2499_让数组不相等的最小总代价](#2499)
#### [贪心](#2499)
#### [数组](#2499)
#### [哈希表](#2499)
#### [计数](#2499)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2490_回环句
___
#### 字符串
---
### 2491_划分技能点相等的团队
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 排序
---
### 2492_两个城市间路径的最小分数
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 2493_将节点分成尽可能多的组
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 2494_合并在同一个大厅重叠的活动 🔒
___
#### 数据库
---
### 2495_乘积为偶数的子数组数 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 2496_数组中字符串的最大值
___
#### 数组
___
#### 字符串
---
### 2497_图中最大星和
___
#### 贪心
___
#### 图
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2498_青蛙过河 II
___
#### 贪心
___
#### 数组
___
#### 二分查找
---
### 2499_让数组不相等的最小总代价
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 深度优先搜索 | 计数 |
| 贪心 |  |  |

# [2490. 回环句](https://leetcode.cn/problems/circular-sentence){#2490}

{{< tabs "2490" >}}

{{% tab "python" %}}
```python
class Solution:
    def isCircularSentence(self, s: str) -> bool:
        return s[0] == s[-1] and all(
            c != " " or s[i - 1] == s[i + 1] for i, c in enumerate(s)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isCircularSentence(String s) {
        int n = s.length();
        if (s.charAt(0) != s.charAt(n - 1)) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == ' ' && s.charAt(i - 1) != s.charAt(i + 1)) {
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
    bool isCircularSentence(string s) {
        int n = s.size();
        if (s[0] != s.back()) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == ' ' && s[i - 1] != s[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isCircularSentence(s string) bool {
	n := len(s)
	if s[0] != s[n-1] {
		return false
	}
	for i := 1; i < n; i++ {
		if s[i] == ' ' && s[i-1] != s[i+1] {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isCircularSentence(s: string): boolean {
    const n = s.length;
    if (s[0] !== s[n - 1]) {
        return false;
    }
    for (let i = 1; i < n; ++i) {
        if (s[i] === ' ' && s[i - 1] !== s[i + 1]) {
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
    pub fn is_circular_sentence(sentence: String) -> bool {
        let n = sentence.len();
        let chars: Vec<char> = sentence.chars().collect();

        if chars[0] != chars[n - 1] {
            return false;
        }

        for i in 1..n - 1 {
            if chars[i] == ' ' && chars[i - 1] != chars[i + 1] {
                return false;
            }
        }

        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isCircularSentence = function (s) {
    const n = s.length;
    if (s[0] !== s[n - 1]) {
        return false;
    }
    for (let i = 1; i < n; ++i) {
        if (s[i] === ' ' && s[i - 1] !== s[i + 1]) {
            return false;
        }
    }
    return true;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>句子</strong> 是由单个空格分隔的一组单词，且不含前导或尾随空格。</p>

<ul>
	<li>例如，<code>"Hello World"</code>、<code>"HELLO"</code>、<code>"hello world hello world"</code> 都是符合要求的句子。</li>
</ul>

<p>单词 <strong>仅</strong> 由大写和小写英文字母组成。且大写和小写字母会视作不同字符。</p>

<p>如果句子满足下述全部条件，则认为它是一个 <strong>回环句</strong> ：</p>

<ul>
	<li>句子中每个单词的最后一个字符等于下一个单词的第一个字符。</li>
	<li>最后一个单词的最后一个字符和第一个单词的第一个字符相等。</li>
</ul>

<p>例如，<code>"leetcode exercises sound delightful"</code>、<code>"eetcode"</code>、<code>"leetcode eats soul"</code> 都是回环句。然而，<code>"Leetcode is cool"</code>、<code>"happy Leetcode"</code>、<code>"Leetcode"</code> 和 <code>"I like Leetcode"</code> 都 <strong>不</strong> 是回环句。</p>

<p>给你一个字符串 <code>sentence</code> ，请你判断它是不是一个回环句。如果是，返回 <code>true</code><em> </em>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "leetcode exercises sound delightful"
<strong>输出：</strong>true
<strong>解释：</strong>句子中的单词是 ["leetcode", "exercises", "sound", "delightful"] 。
- leetcod<strong><em>e</em></strong> 的最后一个字符和 <strong><em>e</em></strong>xercises 的第一个字符相等。
- exercise<em><strong>s</strong></em> 的最后一个字符和 <em><strong>s</strong></em>ound 的第一个字符相等。
- <em><strong>s</strong></em>ound 的最后一个字符和 delightfu<em><strong>l</strong></em> 的第一个字符相等。
- delightfu<em><strong>l</strong></em> 的最后一个字符和 <em><strong>l</strong></em>eetcode 的第一个字符相等。
这个句子是回环句。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "eetcode"
<strong>输出：</strong>true
<strong>解释：</strong>句子中的单词是 ["eetcode"] 。
- eetcod<em><strong>e</strong></em> 的最后一个字符和 <em><strong>e</strong></em>etcod<em>e</em> 的第一个字符相等。
这个句子是回环句。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sentence = "Leetcode is cool"
<strong>输出：</strong>false
<strong>解释：</strong>句子中的单词是 ["Leetcode", "is", "cool"] 。
- Leetcod<em><strong>e</strong></em>&nbsp;的最后一个字符和 <em><strong>i</strong></em>s 的第一个字符 <strong>不</strong> 相等。 
这个句子 <strong>不</strong> 是回环句。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 500</code></li>
	<li><code>sentence</code> 仅由大小写英文字母和空格组成</li>
	<li><code>sentence</code> 中的单词由单个空格进行分隔</li>
	<li>不含任何前导或尾随空格</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们将字符串按照空格分割成单词，然后判断每个单词的最后一个字符和下一个单词的第一个字符是否相等，如果不相等则返回 `false`，否则遍历完所有单词后返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        ss = sentence.split()
        n = len(ss)
        return all(s[-1] == ss[(i + 1) % n][0] for i, s in enumerate(ss))
```

#### Java

```java
class Solution {
    public boolean isCircularSentence(String sentence) {
        var ss = sentence.split(" ");
        int n = ss.length;
        for (int i = 0; i < n; ++i) {
            if (ss[i].charAt(ss[i].length() - 1) != ss[(i + 1) % n].charAt(0)) {
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
    bool isCircularSentence(string sentence) {
        auto ss = split(sentence, ' ');
        int n = ss.size();
        for (int i = 0; i < n; ++i) {
            if (ss[i].back() != ss[(i + 1) % n][0]) {
                return false;
            }
        }
        return true;
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
func isCircularSentence(sentence string) bool {
	ss := strings.Split(sentence, " ")
	n := len(ss)
	for i, s := range ss {
		if s[len(s)-1] != ss[(i+1)%n][0] {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isCircularSentence(sentence: string): boolean {
    const ss = sentence.split(' ');
    const n = ss.length;
    for (let i = 0; i < n; ++i) {
        if (ss[i][ss[i].length - 1] !== ss[(i + 1) % n][0]) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        let ss: Vec<String> = sentence.split(' ').map(String::from).collect();
        let n = ss.len();
        for i in 0..n {
            if ss[i].as_bytes()[ss[i].len() - 1] != ss[(i + 1) % n].as_bytes()[0] {
                return false;
            }
        }
        return true;
    }
}
```

#### JavaScript

```js
/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function (sentence) {
    const ss = sentence.split(' ');
    const n = ss.length;
    for (let i = 0; i < n; ++i) {
        if (ss[i][ss[i].length - 1] !== ss[(i + 1) % n][0]) {
            return false;
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：模拟（空间优化）

我们可以先判断字符串的第一个字符和最后一个字符是否相等，如果不相等则返回 `false`，否则遍历字符串，如果当前字符是空格，则判断前一个字符和后一个字符是否相等，如果不相等则返回 `false`，否则遍历完所有字符后返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isCircularSentence(self, s: str) -> bool:
        return s[0] == s[-1] and all(
            c != " " or s[i - 1] == s[i + 1] for i, c in enumerate(s)
        )
```

#### Java

```java
class Solution {
    public boolean isCircularSentence(String s) {
        int n = s.length();
        if (s.charAt(0) != s.charAt(n - 1)) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == ' ' && s.charAt(i - 1) != s.charAt(i + 1)) {
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
    bool isCircularSentence(string s) {
        int n = s.size();
        if (s[0] != s.back()) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == ' ' && s[i - 1] != s[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isCircularSentence(s string) bool {
	n := len(s)
	if s[0] != s[n-1] {
		return false
	}
	for i := 1; i < n; i++ {
		if s[i] == ' ' && s[i-1] != s[i+1] {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isCircularSentence(s: string): boolean {
    const n = s.length;
    if (s[0] !== s[n - 1]) {
        return false;
    }
    for (let i = 1; i < n; ++i) {
        if (s[i] === ' ' && s[i - 1] !== s[i + 1]) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        let n = sentence.len();
        let chars: Vec<char> = sentence.chars().collect();

        if chars[0] != chars[n - 1] {
            return false;
        }

        for i in 1..n - 1 {
            if chars[i] == ' ' && chars[i - 1] != chars[i + 1] {
                return false;
            }
        }

        true
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isCircularSentence = function (s) {
    const n = s.length;
    if (s[0] !== s[n - 1]) {
        return false;
    }
    for (let i = 1; i < n; ++i) {
        if (s[i] === ' ' && s[i - 1] !== s[i + 1]) {
            return false;
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2491. 划分技能点相等的团队](https://leetcode.cn/problems/divide-players-into-teams-of-equal-skill){#2491}

{{< tabs "2491" >}}

{{% tab "python" %}}
```python
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        s = sum(skill)
        m = len(skill) >> 1
        if s % m:
            return -1
        t = s // m
        d = defaultdict(int)
        ans = 0
        for v in skill:
            if d[t - v]:
                ans += v * (t - v)
                m -= 1
                d[t - v] -= 1
            else:
                d[v] += 1
        return -1 if m else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long dividePlayers(int[] skill) {
        int s = Arrays.stream(skill).sum();
        int m = skill.length >> 1;
        if (s % m != 0) {
            return -1;
        }
        int t = s / m;
        int[] d = new int[1010];
        long ans = 0;
        for (int v : skill) {
            if (d[t - v] > 0) {
                ans += (long) v * (t - v);
                --d[t - v];
                --m;
            } else {
                ++d[v];
            }
        }
        return m == 0 ? ans : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int s = accumulate(skill.begin(), skill.end(), 0);
        int m = skill.size() / 2;
        if (s % m) return -1;
        int t = s / m;
        int d[1010] = {0};
        long long ans = 0;
        for (int& v : skill) {
            if (d[t - v]) {
                ans += 1ll * v * (t - v);
                --d[t - v];
                --m;
            } else {
                ++d[v];
            }
        }
        return m == 0 ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func dividePlayers(skill []int) int64 {
	s := 0
	for _, v := range skill {
		s += v
	}
	m := len(skill) >> 1
	if s%m != 0 {
		return -1
	}
	t := s / m
	d := [1010]int{}
	ans := 0
	for _, v := range skill {
		if d[t-v] > 0 {
			ans += v * (t - v)
			d[t-v]--
			m--
		} else {
			d[v]++
		}
	}
	if m == 0 {
		return int64(ans)
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function dividePlayers(skill: number[]): number {
    let [sum, res, map] = [0, 0, new Map<number, number>()];

    for (const x of skill) {
        sum += x;
        map.set(x, (map.get(x) || 0) + 1);
    }
    sum /= skill.length / 2;

    for (let [x, c] of map) {
        const complement = sum - x;
        if ((map.get(complement) ?? 0) !== c) return -1;
        if (x === complement) c /= 2;

        res += x * complement * c;
        map.delete(x);
        map.delete(complement);
    }

    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn divide_players(mut skill: Vec<i32>) -> i64 {
        let n = skill.len();
        skill.sort();
        let target = skill[0] + skill[n - 1];
        let mut ans = 0;
        for i in 0..n >> 1 {
            if skill[i] + skill[n - 1 - i] != target {
                return -1;
            }
            ans += (skill[i] * skill[n - 1 - i]) as i64;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function dividePlayers(skill) {
    let [sum, res, map] = [0, 0, new Map()];

    for (const x of skill) {
        sum += x;
        map.set(x, (map.get(x) || 0) + 1);
    }
    sum /= skill.length / 2;

    for (let [x, c] of map) {
        const complement = sum - x;
        if ((map.get(complement) ?? 0) !== c) return -1;
        if (x === complement) c /= 2;

        res += x * complement * c;
        map.delete(x);
        map.delete(complement);
    }

    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>skill</code> ，数组长度为 <strong>偶数</strong> <code>n</code> ，其中 <code>skill[i]</code> 表示第 <code>i</code> 个玩家的技能点。将所有玩家分成 <code>n / 2</code> 个 <code>2</code> 人团队，使每一个团队的技能点之和 <strong>相等</strong> 。</p>

<p>团队的 <strong>化学反应</strong> 等于团队中玩家的技能点 <strong>乘积</strong> 。</p>

<p>返回所有团队的 <strong>化学反应</strong> 之和，如果无法使每个团队的技能点之和相等，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>skill = [3,2,5,1,3,4]
<strong>输出：</strong>22
<strong>解释：</strong>
将玩家分成 3 个团队 (1, 5), (2, 4), (3, 3) ，每个团队的技能点之和都是 6 。
所有团队的化学反应之和是 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>skill = [3,4]
<strong>输出：</strong>12
<strong>解释：</strong>
两个玩家形成一个团队，技能点之和是 7 。
团队的化学反应是 3 * 4 = 12 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>skill = [1,1,2,3]
<strong>输出：</strong>-1
<strong>解释：</strong>
无法将玩家分成每个团队技能点都相等的若干个 2 人团队。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= skill.length &lt;= 10<sup>5</sup></code></li>
	<li><code>skill.length</code> 是偶数</li>
	<li><code>1 &lt;= skill[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

要使得所有 $2$ 人团队的技能点相等，最小值一定需要跟最大值匹配。因此，我们将数组 `skill` 排序，然后用双指针 $i$ 和 $j$ 分别指向数组的首位，两两匹配，判断其和是否均为同一个数。

若不是，说明技能点无法相等，直接返回 $-1$，否则，将化学反应累加到答案中。

遍历结束，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 `skill` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        t = skill[0] + skill[-1]
        i, j = 0, len(skill) - 1
        ans = 0
        while i < j:
            if skill[i] + skill[j] != t:
                return -1
            ans += skill[i] * skill[j]
            i, j = i + 1, j - 1
        return ans
```

#### Java

```java
class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        int n = skill.length;
        int t = skill[0] + skill[n - 1];
        long ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (skill[i] + skill[j] != t) {
                return -1;
            }
            ans += (long) skill[i] * skill[j];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int t = skill[0] + skill[n - 1];
        long long ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (skill[i] + skill[j] != t) return -1;
            ans += 1ll * skill[i] * skill[j];
        }
        return ans;
    }
};
```

#### Go

```go
func dividePlayers(skill []int) (ans int64) {
	sort.Ints(skill)
	n := len(skill)
	t := skill[0] + skill[n-1]
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		if skill[i]+skill[j] != t {
			return -1
		}
		ans += int64(skill[i] * skill[j])
	}
	return
}
```

#### TypeScript

```ts
function dividePlayers(skill: number[]): number {
    const n = skill.length;
    skill.sort((a, b) => a - b);
    const target = skill[0] + skill[n - 1];
    let ans = 0;
    for (let i = 0; i < n >> 1; i++) {
        if (target !== skill[i] + skill[n - 1 - i]) {
            return -1;
        }
        ans += skill[i] * skill[n - 1 - i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn divide_players(mut skill: Vec<i32>) -> i64 {
        let n = skill.len();
        skill.sort();
        let target = skill[0] + skill[n - 1];
        let mut ans = 0;
        for i in 0..n >> 1 {
            if skill[i] + skill[n - 1 - i] != target {
                return -1;
            }
            ans += (skill[i] * skill[n - 1 - i]) as i64;
        }
        ans
    }
}
```

#### JavaScript

```js
var dividePlayers = function (skill) {
    const n = skill.length,
        m = n / 2;
    skill.sort((a, b) => a - b);
    const sum = skill[0] + skill[n - 1];
    let ans = 0;
    for (let i = 0; i < m; i++) {
        const x = skill[i],
            y = skill[n - 1 - i];
        if (x + y != sum) return -1;
        ans += x * y;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `skill` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        s = sum(skill)
        m = len(skill) >> 1
        if s % m:
            return -1
        t = s // m
        d = defaultdict(int)
        ans = 0
        for v in skill:
            if d[t - v]:
                ans += v * (t - v)
                m -= 1
                d[t - v] -= 1
            else:
                d[v] += 1
        return -1 if m else ans
```

#### Java

```java
class Solution {
    public long dividePlayers(int[] skill) {
        int s = Arrays.stream(skill).sum();
        int m = skill.length >> 1;
        if (s % m != 0) {
            return -1;
        }
        int t = s / m;
        int[] d = new int[1010];
        long ans = 0;
        for (int v : skill) {
            if (d[t - v] > 0) {
                ans += (long) v * (t - v);
                --d[t - v];
                --m;
            } else {
                ++d[v];
            }
        }
        return m == 0 ? ans : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int s = accumulate(skill.begin(), skill.end(), 0);
        int m = skill.size() / 2;
        if (s % m) return -1;
        int t = s / m;
        int d[1010] = {0};
        long long ans = 0;
        for (int& v : skill) {
            if (d[t - v]) {
                ans += 1ll * v * (t - v);
                --d[t - v];
                --m;
            } else {
                ++d[v];
            }
        }
        return m == 0 ? ans : -1;
    }
};
```

#### Go

```go
func dividePlayers(skill []int) int64 {
	s := 0
	for _, v := range skill {
		s += v
	}
	m := len(skill) >> 1
	if s%m != 0 {
		return -1
	}
	t := s / m
	d := [1010]int{}
	ans := 0
	for _, v := range skill {
		if d[t-v] > 0 {
			ans += v * (t - v)
			d[t-v]--
			m--
		} else {
			d[v]++
		}
	}
	if m == 0 {
		return int64(ans)
	}
	return -1
}
```

#### TypeScript

```ts
function dividePlayers(skill: number[]): number {
    let [sum, res, map] = [0, 0, new Map<number, number>()];

    for (const x of skill) {
        sum += x;
        map.set(x, (map.get(x) || 0) + 1);
    }
    sum /= skill.length / 2;

    for (let [x, c] of map) {
        const complement = sum - x;
        if ((map.get(complement) ?? 0) !== c) return -1;
        if (x === complement) c /= 2;

        res += x * complement * c;
        map.delete(x);
        map.delete(complement);
    }

    return res;
}
```

#### JavaScript

```js
function dividePlayers(skill) {
    let [sum, res, map] = [0, 0, new Map()];

    for (const x of skill) {
        sum += x;
        map.set(x, (map.get(x) || 0) + 1);
    }
    sum /= skill.length / 2;

    for (let [x, c] of map) {
        const complement = sum - x;
        if ((map.get(complement) ?? 0) !== c) return -1;
        if (x === complement) c /= 2;

        res += x * complement * c;
        map.delete(x);
        map.delete(complement);
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2492. 两个城市间路径的最小分数](https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities){#2492}

{{< tabs "2492" >}}

{{% tab "python" %}}
```python
class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        g = defaultdict(list)
        for a, b, d in roads:
            g[a].append((b, d))
            g[b].append((a, d))
        vis = [False] * (n + 1)
        vis[1] = True
        ans = inf
        q = deque([1])
        while q:
            for _ in range(len(q)):
                i = q.popleft()
                for j, d in g[i]:
                    ans = min(ans, d)
                    if not vis[j]:
                        vis[j] = True
                        q.append(j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minScore(int n, int[][] roads) {
        List<int[]>[] g = new List[n];
        boolean[] vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : roads) {
            int a = e[0] - 1, b = e[1] - 1, d = e[2];
            g[a].add(new int[] {b, d});
            g[b].add(new int[] {a, d});
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        vis[0] = true;
        int ans = 1 << 30;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.pollFirst();
                for (var nxt : g[i]) {
                    int j = nxt[0], d = nxt[1];
                    ans = Math.min(ans, d);
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
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
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        bool vis[n];
        memset(vis, 0, sizeof vis);
        for (auto& e : roads) {
            int a = e[0] - 1, b = e[1] - 1, d = e[2];
            g[a].emplace_back(b, d);
            g[b].emplace_back(a, d);
        }
        int ans = INT_MAX;
        queue<int> q{{0}};
        vis[0] = true;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                for (auto [j, d] : g[i]) {
                    ans = min(ans, d);
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
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
func minScore(n int, roads [][]int) int {
	type pair struct{ i, v int }
	g := make([][]pair, n)
	for _, e := range roads {
		a, b, d := e[0]-1, e[1]-1, e[2]
		g[a] = append(g[a], pair{b, d})
		g[b] = append(g[b], pair{a, d})
	}
	vis := make([]bool, n)
	ans := 1 << 30
	q := []int{0}
	vis[0] = true
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			i := q[0]
			q = q[1:]
			for _, nxt := range g[i] {
				j, d := nxt.i, nxt.v
				ans = min(ans, d)
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minScore(n: number, roads: number[][]): number {
    const vis = new Array(n + 1).fill(false);
    const g = Array.from({ length: n + 1 }, () => []);
    for (const [a, b, v] of roads) {
        g[a].push([b, v]);
        g[b].push([a, v]);
    }
    let ans = Infinity;
    const dfs = (i: number) => {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        for (const [j, v] of g[i]) {
            ans = Math.min(ans, v);
            dfs(j);
        }
    };
    dfs(1);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(i: usize, mut ans: i32, g: &Vec<Vec<(usize, i32)>>, vis: &mut Vec<bool>) -> i32 {
        if vis[i] {
            return ans;
        }
        vis[i] = true;
        for (j, v) in g[i].iter() {
            ans = ans.min(*v.min(&Self::dfs(*j, ans, g, vis)));
        }
        ans
    }

    pub fn min_score(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut vis = vec![false; n + 1];
        let mut g = vec![Vec::new(); n + 1];
        for road in roads.iter() {
            let a = road[0] as usize;
            let b = road[1] as usize;
            let v = road[2];
            g[a].push((b, v));
            g[b].push((a, v));
        }
        Self::dfs(1, i32::MAX, &g, &mut vis)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var minScore = function (n, roads) {
    // 构建点到点的映射表
    const graph = Array.from({ length: n + 1 }, () => new Map());
    for (let [u, v, w] of roads) {
        graph[u].set(v, w);
        graph[v].set(u, w);
    }

    // DFS
    const vis = new Array(n).fill(false);
    let ans = Infinity;
    var dfs = function (u) {
        vis[u] = true;
        for (const [v, w] of graph[u]) {
            ans = Math.min(ans, w);
            if (!vis[v]) dfs(v);
        }
    };
    dfs(1);

    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，表示总共有&nbsp;<code>n</code>&nbsp;个城市，城市从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;编号。给你一个二维数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>, distance<sub>i</sub>]</code>&nbsp;表示城市&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条 <strong>双向</strong>&nbsp;道路，道路距离为&nbsp;<code>distance<sub>i</sub></code>&nbsp;。城市构成的图不一定是连通的。</p>

<p>两个城市之间一条路径的 <strong>分数</strong>&nbsp;定义为这条路径中道路的 <strong>最小</strong>&nbsp;距离。</p>

<p><span class="text-only" data-eleid="20" style="white-space: pre;">城市</span><span class="text-only text-font-italic" data-eleid="21" style="white-space: pre;"> </span><code><span class="text-only" data-eleid="22" style="white-space: pre;">1</span></code><span class="text-only text-font-italic" data-eleid="23" style="white-space: pre;"> </span><span class="text-only" data-eleid="24" style="white-space: pre;">和城市</span><span class="text-only text-font-italic" data-eleid="25" style="white-space: pre;"> </span><span class="text-only" data-eleid="26" style="white-space: pre;"><code>n</code> 之间的所有路径的 </span><strong><span class="text-only" data-eleid="27" style="white-space: pre;">最小</span></strong><span class="text-only" data-eleid="28" style="white-space: pre;"> 分数。</span></p>

<p><b>注意：</b></p>

<ul>
	<li>一条路径指的是两个城市之间的道路序列。</li>
	<li>一条路径可以 <strong>多次</strong> 包含同一条道路，你也可以沿着路径多次到达城市 <code>1</code>&nbsp;和城市 <code>n</code>&nbsp;。</li>
	<li>测试数据保证城市 <code>1</code>&nbsp;和城市<code>n</code>&nbsp;之间 <strong>至少</strong>&nbsp;有一条路径。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2492.Minimum%20Score%20of%20a%20Path%20Between%20Two%20Cities/images/graph11.png" style="width: 190px; height: 231px;" /></p>

<pre>
<b>输入：</b>n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
<b>输出：</b>5
<b>解释：</b>城市 1 到城市 4 的路径中，分数最小的一条为：1 -&gt; 2 -&gt; 4 。这条路径的分数是 min(9,5) = 5 。
不存在分数更小的路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2492.Minimum%20Score%20of%20a%20Path%20Between%20Two%20Cities/images/graph22.png" style="width: 190px; height: 231px;" /></p>

<pre>
<b>输入：</b>n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
<b>输出：</b>2
<b>解释：</b>城市 1 到城市 4 分数最小的路径是：1 -&gt; 2 -&gt; 1 -&gt; 3 -&gt; 4 。这条路径的分数是 min(2,2,4,7) = 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= roads.length &lt;= 10<sup>5</sup></code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= distance<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>不会有重复的边。</li>
	<li>城市 <code>1</code>&nbsp;和城市 <code>n</code>&nbsp;之间至少有一条路径。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

根据题目描述，每条边可以经过多次，并且保证节点 $1$ 和节点 $n$ 在同一个连通块中。因此，题目实际上求的是节点 $1$ 所在的连通块的最小边。我们可以用 DFS，从节点 $1$ 开始搜索所有的边，找到最小的边即可。

时间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        def dfs(i):
            nonlocal ans
            for j, d in g[i]:
                ans = min(ans, d)
                if not vis[j]:
                    vis[j] = True
                    dfs(j)

        g = defaultdict(list)
        for a, b, d in roads:
            g[a].append((b, d))
            g[b].append((a, d))
        vis = [False] * (n + 1)
        ans = inf
        dfs(1)
        return ans
```

#### Java

```java
class Solution {
    private List<int[]>[] g;
    private boolean[] vis;
    private int ans = 1 << 30;

    public int minScore(int n, int[][] roads) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : roads) {
            int a = e[0] - 1, b = e[1] - 1, d = e[2];
            g[a].add(new int[] {b, d});
            g[b].add(new int[] {a, d});
        }
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        for (var nxt : g[i]) {
            int j = nxt[0], d = nxt[1];
            ans = Math.min(ans, d);
            if (!vis[j]) {
                vis[j] = true;
                dfs(j);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        bool vis[n];
        memset(vis, 0, sizeof vis);
        for (auto& e : roads) {
            int a = e[0] - 1, b = e[1] - 1, d = e[2];
            g[a].emplace_back(b, d);
            g[b].emplace_back(a, d);
        }
        int ans = INT_MAX;
        function<void(int)> dfs = [&](int i) {
            for (auto [j, d] : g[i]) {
                ans = min(ans, d);
                if (!vis[j]) {
                    vis[j] = true;
                    dfs(j);
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func minScore(n int, roads [][]int) int {
	type pair struct{ i, v int }
	g := make([][]pair, n)
	for _, e := range roads {
		a, b, d := e[0]-1, e[1]-1, e[2]
		g[a] = append(g[a], pair{b, d})
		g[b] = append(g[b], pair{a, d})
	}
	vis := make([]bool, n)
	ans := 1 << 30
	var dfs func(int)
	dfs = func(i int) {
		for _, nxt := range g[i] {
			j, d := nxt.i, nxt.v
			ans = min(ans, d)
			if !vis[j] {
				vis[j] = true
				dfs(j)
			}
		}
	}
	dfs(0)
	return ans
}
```

#### TypeScript

```ts
function minScore(n: number, roads: number[][]): number {
    const vis = new Array(n + 1).fill(false);
    const g = Array.from({ length: n + 1 }, () => []);
    for (const [a, b, v] of roads) {
        g[a].push([b, v]);
        g[b].push([a, v]);
    }
    let ans = Infinity;
    const dfs = (i: number) => {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        for (const [j, v] of g[i]) {
            ans = Math.min(ans, v);
            dfs(j);
        }
    };
    dfs(1);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, mut ans: i32, g: &Vec<Vec<(usize, i32)>>, vis: &mut Vec<bool>) -> i32 {
        if vis[i] {
            return ans;
        }
        vis[i] = true;
        for (j, v) in g[i].iter() {
            ans = ans.min(*v.min(&Self::dfs(*j, ans, g, vis)));
        }
        ans
    }

    pub fn min_score(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut vis = vec![false; n + 1];
        let mut g = vec![Vec::new(); n + 1];
        for road in roads.iter() {
            let a = road[0] as usize;
            let b = road[1] as usize;
            let v = road[2];
            g[a].push((b, v));
            g[b].push((a, v));
        }
        Self::dfs(1, i32::MAX, &g, &mut vis)
    }
}
```

#### JavaScript

```js
var minScore = function (n, roads) {
    // 构建点到点的映射表
    const graph = Array.from({ length: n + 1 }, () => new Map());
    for (let [u, v, w] of roads) {
        graph[u].set(v, w);
        graph[v].set(u, w);
    }

    // DFS
    const vis = new Array(n).fill(false);
    let ans = Infinity;
    var dfs = function (u) {
        vis[u] = true;
        for (const [v, w] of graph[u]) {
            ans = Math.min(ans, w);
            if (!vis[v]) dfs(v);
        }
    };
    dfs(1);

    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

我们也可以用 BFS 来求解。

时间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        g = defaultdict(list)
        for a, b, d in roads:
            g[a].append((b, d))
            g[b].append((a, d))
        vis = [False] * (n + 1)
        vis[1] = True
        ans = inf
        q = deque([1])
        while q:
            for _ in range(len(q)):
                i = q.popleft()
                for j, d in g[i]:
                    ans = min(ans, d)
                    if not vis[j]:
                        vis[j] = True
                        q.append(j)
        return ans
```

#### Java

```java
class Solution {
    public int minScore(int n, int[][] roads) {
        List<int[]>[] g = new List[n];
        boolean[] vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : roads) {
            int a = e[0] - 1, b = e[1] - 1, d = e[2];
            g[a].add(new int[] {b, d});
            g[b].add(new int[] {a, d});
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        vis[0] = true;
        int ans = 1 << 30;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.pollFirst();
                for (var nxt : g[i]) {
                    int j = nxt[0], d = nxt[1];
                    ans = Math.min(ans, d);
                    if (!vis[j]) {
                        vis[j] = true;
                        q.offer(j);
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
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        bool vis[n];
        memset(vis, 0, sizeof vis);
        for (auto& e : roads) {
            int a = e[0] - 1, b = e[1] - 1, d = e[2];
            g[a].emplace_back(b, d);
            g[b].emplace_back(a, d);
        }
        int ans = INT_MAX;
        queue<int> q{{0}};
        vis[0] = true;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                for (auto [j, d] : g[i]) {
                    ans = min(ans, d);
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
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
func minScore(n int, roads [][]int) int {
	type pair struct{ i, v int }
	g := make([][]pair, n)
	for _, e := range roads {
		a, b, d := e[0]-1, e[1]-1, e[2]
		g[a] = append(g[a], pair{b, d})
		g[b] = append(g[b], pair{a, d})
	}
	vis := make([]bool, n)
	ans := 1 << 30
	q := []int{0}
	vis[0] = true
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			i := q[0]
			q = q[1:]
			for _, nxt := range g[i] {
				j, d := nxt.i, nxt.v
				ans = min(ans, d)
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
				}
			}
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

# [2493. 将节点分成尽可能多的组](https://leetcode.cn/problems/divide-nodes-into-the-maximum-number-of-groups){#2493}

{{< tabs "2493" >}}

{{% tab "python" %}}
```python
class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a - 1].append(b - 1)
            g[b - 1].append(a - 1)
        d = defaultdict(int)
        for i in range(n):
            q = deque([i])
            dist = [0] * n
            dist[i] = mx = 1
            root = i
            while q:
                a = q.popleft()
                root = min(root, a)
                for b in g[a]:
                    if dist[b] == 0:
                        dist[b] = dist[a] + 1
                        mx = max(mx, dist[b])
                        q.append(b)
                    elif abs(dist[b] - dist[a]) != 1:
                        return -1
            d[root] = max(d[root], mx)
        return sum(d.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int magnificentSets(int n, int[][] edges) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            g[b].add(a);
        }
        int[] d = new int[n];
        int[] dist = new int[n];
        for (int i = 0; i < n; ++i) {
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(i);
            Arrays.fill(dist, 0);
            dist[i] = 1;
            int mx = 1;
            int root = i;
            while (!q.isEmpty()) {
                int a = q.poll();
                root = Math.min(root, a);
                for (int b : g[a]) {
                    if (dist[b] == 0) {
                        dist[b] = dist[a] + 1;
                        mx = Math.max(mx, dist[b]);
                        q.offer(b);
                    } else if (Math.abs(dist[b] - dist[a]) != 1) {
                        return -1;
                    }
                }
            }
            d[root] = Math.max(d[root], mx);
        }
        return Arrays.stream(d).sum();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            queue<int> q{{i}};
            vector<int> dist(n);
            dist[i] = 1;
            int mx = 1;
            int root = i;
            while (q.size()) {
                int a = q.front();
                q.pop();
                root = min(root, a);
                for (int b : g[a]) {
                    if (dist[b] == 0) {
                        dist[b] = dist[a] + 1;
                        mx = max(mx, dist[b]);
                        q.push(b);
                    } else if (abs(dist[b] - dist[a]) != 1) {
                        return -1;
                    }
                }
            }
            d[root] = max(d[root], mx);
        }
        return accumulate(d.begin(), d.end(), 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func magnificentSets(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	d := make([]int, n)
	for i := range d {
		q := []int{i}
		dist := make([]int, n)
		dist[i] = 1
		mx := 1
		root := i
		for len(q) > 0 {
			a := q[0]
			q = q[1:]
			root = min(root, a)
			for _, b := range g[a] {
				if dist[b] == 0 {
					dist[b] = dist[a] + 1
					mx = max(mx, dist[b])
					q = append(q, b)
				} else if abs(dist[b]-dist[a]) != 1 {
					return -1
				}
			}
		}
		d[root] = max(d[root], mx)
	}
	for _, x := range d {
		ans += x
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var magnificentSets = function (n, edges) {
    const g = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a - 1].push(b - 1);
        g[b - 1].push(a - 1);
    }
    const d = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const q = [i];
        const dist = Array(n).fill(0);
        dist[i] = 1;
        let mx = 1;
        let root = i;
        while (q.length) {
            const a = q.shift();
            root = Math.min(root, a);
            for (const b of g[a]) {
                if (dist[b] === 0) {
                    dist[b] = dist[a] + 1;
                    mx = Math.max(mx, dist[b]);
                    q.push(b);
                } else if (Math.abs(dist[b] - dist[a]) !== 1) {
                    return -1;
                }
            }
        }
        d[root] = Math.max(d[root], mx);
    }
    return d.reduce((a, b) => a + b);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，表示一个 <strong>无向</strong>&nbsp;图中的节点数目，节点编号从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;。</p>

<p>同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i, </sub>b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code><sub>&nbsp;</sub>之间有一条&nbsp;<strong>双向</strong>&nbsp;边。注意给定的图可能是不连通的。</p>

<p>请你将图划分为&nbsp;<code>m</code>&nbsp;个组（编号从 <strong>1</strong>&nbsp;开始），满足以下要求：</p>

<ul>
	<li>图中每个节点都只属于一个组。</li>
	<li>图中每条边连接的两个点&nbsp;<code>[a<sub>i, </sub>b<sub>i</sub>]</code>&nbsp;，如果&nbsp;<code>a<sub>i</sub></code>&nbsp;属于编号为&nbsp;<code>x</code>&nbsp;的组，<code>b<sub>i</sub></code>&nbsp;属于编号为&nbsp;<code>y</code>&nbsp;的组，那么&nbsp;<code>|y - x| = 1</code>&nbsp;。</li>
</ul>

<p>请你返回最多可以将节点分为多少个组（也就是最大的<em>&nbsp;</em><code>m</code>&nbsp;）。如果没办法在给定条件下分组，请你返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2493.Divide%20Nodes%20Into%20the%20Maximum%20Number%20of%20Groups/images/example1.png" style="width: 352px; height: 201px;"></p>

<pre><b>输入：</b>n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
<b>输出：</b>4
<b>解释：</b>如上图所示，
- 节点 5 在第一个组。
- 节点 1 在第二个组。
- 节点 2 和节点 4 在第三个组。
- 节点 3 和节点 6 在第四个组。
所有边都满足题目要求。
如果我们创建第五个组，将第三个组或者第四个组中任何一个节点放到第五个组，至少有一条边连接的两个节点所属的组编号不符合题目要求。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 3, edges = [[1,2],[2,3],[3,1]]
<b>输出：</b>-1
<b>解释：</b>如果我们将节点 1 放入第一个组，节点 2 放入第二个组，节点 3 放入第三个组，前两条边满足题目要求，但第三条边不满足题目要求。
没有任何符合题目要求的分组方式。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= edges.length &lt;= 10<sup>4</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>两个点之间至多只有一条边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 枚举

由于题目给定的图可能是不连通的，所以我们需要对每个连通分量进行处理，找出每个连通分量的最大分组数，累加得到最终结果。

我们可以枚举每一个点作为第一组的节点，然后使用 BFS 遍历整个连通分量，用一个数组 $d$ 记录每个连通分量的最大分组数。在代码实现上，我们使用连通分量中的最小节点作为该连通分量的根节点。

在 BFS 的过程中，我们使用一个队列 $q$ 存储当前遍历到的节点，用一个数组 $dist$ 记录每个节点到起始节点的距离，用一个变量 $mx$ 记录当前连通分量的最大深度，用一个变量 $root$ 记录当前连通分量的根节点。

在遍历过程中，如果发现某个节点 $b$ 的 $dist[b]$ 为 $0$，说明 $b$ 还没有被遍历到，我们将 $b$ 的距离设为 $dist[a] + 1$，更新 $mx$，并将 $b$ 加入队列 $q$ 中。如果 $b$ 的距离已经被更新过，我们检查 $b$ 和 $a$ 之间的距离是否为 $1$，如果不是，说明无法满足题目要求，直接返回 $-1$。

时间复杂度 $O(n \times (n + m))$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a - 1].append(b - 1)
            g[b - 1].append(a - 1)
        d = defaultdict(int)
        for i in range(n):
            q = deque([i])
            dist = [0] * n
            dist[i] = mx = 1
            root = i
            while q:
                a = q.popleft()
                root = min(root, a)
                for b in g[a]:
                    if dist[b] == 0:
                        dist[b] = dist[a] + 1
                        mx = max(mx, dist[b])
                        q.append(b)
                    elif abs(dist[b] - dist[a]) != 1:
                        return -1
            d[root] = max(d[root], mx)
        return sum(d.values())
```

#### Java

```java
class Solution {
    public int magnificentSets(int n, int[][] edges) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].add(b);
            g[b].add(a);
        }
        int[] d = new int[n];
        int[] dist = new int[n];
        for (int i = 0; i < n; ++i) {
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(i);
            Arrays.fill(dist, 0);
            dist[i] = 1;
            int mx = 1;
            int root = i;
            while (!q.isEmpty()) {
                int a = q.poll();
                root = Math.min(root, a);
                for (int b : g[a]) {
                    if (dist[b] == 0) {
                        dist[b] = dist[a] + 1;
                        mx = Math.max(mx, dist[b]);
                        q.offer(b);
                    } else if (Math.abs(dist[b] - dist[a]) != 1) {
                        return -1;
                    }
                }
            }
            d[root] = Math.max(d[root], mx);
        }
        return Arrays.stream(d).sum();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            queue<int> q{{i}};
            vector<int> dist(n);
            dist[i] = 1;
            int mx = 1;
            int root = i;
            while (q.size()) {
                int a = q.front();
                q.pop();
                root = min(root, a);
                for (int b : g[a]) {
                    if (dist[b] == 0) {
                        dist[b] = dist[a] + 1;
                        mx = max(mx, dist[b]);
                        q.push(b);
                    } else if (abs(dist[b] - dist[a]) != 1) {
                        return -1;
                    }
                }
            }
            d[root] = max(d[root], mx);
        }
        return accumulate(d.begin(), d.end(), 0);
    }
};
```

#### Go

```go
func magnificentSets(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0]-1, e[1]-1
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	d := make([]int, n)
	for i := range d {
		q := []int{i}
		dist := make([]int, n)
		dist[i] = 1
		mx := 1
		root := i
		for len(q) > 0 {
			a := q[0]
			q = q[1:]
			root = min(root, a)
			for _, b := range g[a] {
				if dist[b] == 0 {
					dist[b] = dist[a] + 1
					mx = max(mx, dist[b])
					q = append(q, b)
				} else if abs(dist[b]-dist[a]) != 1 {
					return -1
				}
			}
		}
		d[root] = max(d[root], mx)
	}
	for _, x := range d {
		ans += x
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var magnificentSets = function (n, edges) {
    const g = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a - 1].push(b - 1);
        g[b - 1].push(a - 1);
    }
    const d = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const q = [i];
        const dist = Array(n).fill(0);
        dist[i] = 1;
        let mx = 1;
        let root = i;
        while (q.length) {
            const a = q.shift();
            root = Math.min(root, a);
            for (const b of g[a]) {
                if (dist[b] === 0) {
                    dist[b] = dist[a] + 1;
                    mx = Math.max(mx, dist[b]);
                    q.push(b);
                } else if (Math.abs(dist[b] - dist[a]) !== 1) {
                    return -1;
                }
            }
        }
        d[root] = Math.max(d[root], mx);
    }
    return d.reduce((a, b) => a + b);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2494. 合并在同一个大厅重叠的活动 🔒](https://leetcode.cn/problems/merge-overlapping-events-in-the-same-hall){#2494}

{{< tabs "2494" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            hall_id,
            start_day,
            end_day,
            MAX(end_day) OVER (
                PARTITION BY hall_id
                ORDER BY start_day
            ) AS cur_max_end_day
        FROM HallEvents
    ),
    T AS (
        SELECT
            *,
            IF(
                start_day <= LAG(cur_max_end_day) OVER (
                    PARTITION BY hall_id
                    ORDER BY start_day
                ),
                0,
                1
            ) AS start
        FROM S
    ),
    P AS (
        SELECT
            *,
            SUM(start) OVER (
                PARTITION BY hall_id
                ORDER BY start_day
            ) AS gid
        FROM T
    )
SELECT hall_id, MIN(start_day) AS start_day, MAX(end_day) AS end_day
FROM P
GROUP BY hall_id, gid;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>HallEvents</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| hall_id     | int  |
| start_day   | date |
| end_day     | date |
+-------------+------+
该表可能包含重复字段。
该表的每一行表示活动的开始日期和结束日期，以及活动举行的大厅。
</pre>

<p><br />
编写解决方案，合并在&nbsp;<strong>同一个大厅举行&nbsp;</strong>的所有重叠活动。如果两个活动&nbsp;<strong>至少有一天&nbsp;</strong>相同，那么它们就是重叠的。</p>

<p data-group="1-1">以<strong>任意顺序</strong>返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
HallEvents 表:
+---------+------------+------------+
| hall_id | start_day  | end_day    |
+---------+------------+------------+
| 1       | 2023-01-13 | 2023-01-14 |
| 1       | 2023-01-14 | 2023-01-17 |
| 1       | 2023-01-18 | 2023-01-25 |
| 2       | 2022-12-09 | 2022-12-23 |
| 2       | 2022-12-13 | 2022-12-17 |
| 3       | 2022-12-01 | 2023-01-30 |
+---------+------------+------------+
<strong>输出:</strong> 
+---------+------------+------------+
| hall_id | start_day  | end_day    |
+---------+------------+------------+
| 1       | 2023-01-13 | 2023-01-17 |
| 1       | 2023-01-18 | 2023-01-25 |
| 2       | 2022-12-09 | 2022-12-23 |
| 3       | 2022-12-01 | 2023-01-30 |
+---------+------------+------------+
<strong>解释:</strong> 有三个大厅。
大厅 1:
- 两个活动 ["2023-01-13", "2023-01-14"] 和 ["2023-01-14", "2023-01-17"] 重叠。我们将它们合并到一个活动中 ["2023-01-13", "2023-01-17"]。
- 活动 ["2023-01-18", "2023-01-25"] 不与任何其他活动重叠，所以我们保持原样。
大厅 2:
- 两个活动 ["2022-12-09", "2022-12-23"] 和 ["2022-12-13", "2022-12-17"] 重叠。我们将它们合并到一个活动中 ["2022-12-09", "2022-12-23"]。
大厅 3:
- 大厅只有一个活动，所以我们返回它。请注意，我们只分别考虑每个大厅的活动。</pre>

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
        SELECT
            hall_id,
            start_day,
            end_day,
            MAX(end_day) OVER (
                PARTITION BY hall_id
                ORDER BY start_day
            ) AS cur_max_end_day
        FROM HallEvents
    ),
    T AS (
        SELECT
            *,
            IF(
                start_day <= LAG(cur_max_end_day) OVER (
                    PARTITION BY hall_id
                    ORDER BY start_day
                ),
                0,
                1
            ) AS start
        FROM S
    ),
    P AS (
        SELECT
            *,
            SUM(start) OVER (
                PARTITION BY hall_id
                ORDER BY start_day
            ) AS gid
        FROM T
    )
SELECT hall_id, MIN(start_day) AS start_day, MAX(end_day) AS end_day
FROM P
GROUP BY hall_id, gid;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2495. 乘积为偶数的子数组数 🔒](https://leetcode.cn/problems/number-of-subarrays-having-even-product){#2495}

{{< tabs "2495" >}}

{{% tab "python" %}}
```python
class Solution:
    def evenProduct(self, nums: List[int]) -> int:
        ans, last = 0, -1
        for i, v in enumerate(nums):
            if v % 2 == 0:
                last = i
            ans += last + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long evenProduct(int[] nums) {
        long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] % 2 == 0) {
                last = i;
            }
            ans += last + 1;
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
    long long evenProduct(vector<int>& nums) {
        long long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                last = i;
            }
            ans += last + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func evenProduct(nums []int) int64 {
	ans, last := 0, -1
	for i, v := range nums {
		if v%2 == 0 {
			last = i
		}
		ans += last + 1
	}
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>nums</code>，返回<em>具有偶数乘积的 </em><code>nums</code><em> <span data-keyword="subarray">子数组</span>的数目</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [9,6,7,13]
<strong>输出:</strong> 6
<strong>解释:</strong> 有6个子数组的乘积是偶数:
- nums[0..1] = 9 * 6 = 54.
- nums[0..2] = 9 * 6 * 7 = 378.
- nums[0..3] = 9 * 6 * 7 * 13 = 4914.
- nums[1..1] = 6.
- nums[1..2] = 6 * 7 = 42.
- nums[1..3] = 6 * 7 * 13 = 546.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [7,3,5]
<strong>输出:</strong> 0
<strong>解释:</strong> 没有乘积是偶数的子数组
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们知道，一个子数组的乘积为偶数，当且仅当该子数组中至少有一个偶数。

因此，我们可以遍历数组，记录最近一个偶数的下标 `last`，则以当前元素结尾的子数组中，乘积为偶数的子数组个数为 `last + 1`，累加到结果中即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 `nums` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def evenProduct(self, nums: List[int]) -> int:
        ans, last = 0, -1
        for i, v in enumerate(nums):
            if v % 2 == 0:
                last = i
            ans += last + 1
        return ans
```

#### Java

```java
class Solution {
    public long evenProduct(int[] nums) {
        long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] % 2 == 0) {
                last = i;
            }
            ans += last + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                last = i;
            }
            ans += last + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func evenProduct(nums []int) int64 {
	ans, last := 0, -1
	for i, v := range nums {
		if v%2 == 0 {
			last = i
		}
		ans += last + 1
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2496. 数组中字符串的最大值](https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array){#2496}

{{< tabs "2496" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        def f(s: str) -> int:
            x = 0
            for c in s:
                if c.isalpha():
                    return len(s)
                x = x * 10 + ord(c) - ord("0")
            return x

        return max(f(s) for s in strs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumValue(String[] strs) {
        int ans = 0;
        for (var s : strs) {
            ans = Math.max(ans, f(s));
        }
        return ans;
    }

    private int f(String s) {
        int x = 0;
        for (int i = 0, n = s.length(); i < n; ++i) {
            char c = s.charAt(i);
            if (Character.isLetter(c)) {
                return n;
            }
            x = x * 10 + (c - '0');
        }
        return x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        auto f = [](string& s) {
            int x = 0;
            for (char& c : s) {
                if (!isdigit(c)) {
                    return (int) s.size();
                }
                x = x * 10 + c - '0';
            }
            return x;
        };
        int ans = 0;
        for (auto& s : strs) {
            ans = max(ans, f(s));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumValue(strs []string) (ans int) {
	f := func(s string) (x int) {
		for _, c := range s {
			if c >= 'a' && c <= 'z' {
				return len(s)
			}
			x = x*10 + int(c-'0')
		}
		return
	}
	for _, s := range strs {
		if x := f(s); ans < x {
			ans = x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumValue(strs: string[]): number {
    const f = (s: string) => (Number.isNaN(Number(s)) ? s.length : Number(s));
    return Math.max(...strs.map(f));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::max;

impl Solution {
    pub fn maximum_value(strs: Vec<String>) -> i32 {
        let mut ans = 0;

        for s in strs {
            match s.parse::<i32>() {
                Ok(v) => {
                    ans = max(ans, v);
                }
                Err(_) => {
                    ans = max(ans, s.len() as i32);
                }
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaximumValue(string[] strs) {
        return strs.Max(f);
    }

    private int f(string s) {
        int x = 0;
        foreach (var c in s) {
            if (c >= 'a') {
                return s.Length;
            }
            x = x * 10 + (c - '0');
        }
        return x;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int parseInt(char* s) {
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (!isdigit(s[i])) {
            return n;
        }
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int maximumValue(char** strs, int strsSize) {
    int ans = 0;
    for (int i = 0; i < strsSize; i++) {
        int num = parseInt(strs[i]);
        ans = max(ans, num);
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

<p>一个由字母和数字组成的字符串的 <strong>值</strong>&nbsp;定义如下：</p>

<ul>
	<li>如果字符串 <strong>只</strong> 包含数字，那么值为该字符串在 <code>10</code>&nbsp;进制下的所表示的数字。</li>
	<li>否则，值为字符串的 <strong>长度&nbsp;</strong>。</li>
</ul>

<p>给你一个字符串数组&nbsp;<code>strs</code>&nbsp;，每个字符串都只由字母和数字组成，请你返回 <code>strs</code>&nbsp;中字符串的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["alic3","bob","3","4","00000"]
<b>输出：</b>5
<b>解释：</b>
- "alic3" 包含字母和数字，所以值为长度 5 。
- "bob" 只包含字母，所以值为长度 3 。
- "3" 只包含数字，所以值为 3 。
- "4" 只包含数字，所以值为 4 。
- "00000" 只包含数字，所以值为 0 。
所以最大的值为 5 ，是字符串 "alic3" 的值。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>strs = ["1","01","001","0001"]
<b>输出：</b>1
<b>解释：</b>
数组中所有字符串的值都是 1 ，所以我们返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 9</code></li>
	<li><code>strs[i]</code>&nbsp;只包含小写英文字母和数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个函数 $f(s)$，用于计算字符串 $s$ 的值。如果 $s$ 只包含数字，那么 $f(s)$ 就是 $s$ 在十进制下的值；否则 $f(s)$ 就是 $s$ 的长度。

答案为 $\max\limits_{s \in \textit{strs}} f(s)$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $strs$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        def f(s: str) -> int:
            return int(s) if all(c.isdigit() for c in s) else len(s)

        return max(f(s) for s in strs)
```

#### Java

```java
class Solution {
    public int maximumValue(String[] strs) {
        int ans = 0;
        for (var s : strs) {
            ans = Math.max(ans, f(s));
        }
        return ans;
    }

    private int f(String s) {
        int x = 0;
        for (int i = 0, n = s.length(); i < n; ++i) {
            char c = s.charAt(i);
            if (Character.isLetter(c)) {
                return n;
            }
            x = x * 10 + (c - '0');
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        auto f = [](string& s) {
            int x = 0;
            for (char& c : s) {
                if (!isdigit(c)) {
                    return (int) s.size();
                }
                x = x * 10 + c - '0';
            }
            return x;
        };
        int ans = 0;
        for (auto& s : strs) {
            ans = max(ans, f(s));
        }
        return ans;
    }
};
```

#### Go

```go
func maximumValue(strs []string) (ans int) {
	f := func(s string) (x int) {
		for _, c := range s {
			if c >= 'a' && c <= 'z' {
				return len(s)
			}
			x = x*10 + int(c-'0')
		}
		return
	}
	for _, s := range strs {
		if x := f(s); ans < x {
			ans = x
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumValue(strs: string[]): number {
    const f = (s: string) => (Number.isNaN(Number(s)) ? s.length : Number(s));
    return Math.max(...strs.map(f));
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_value(strs: Vec<String>) -> i32 {
        let mut ans = 0;
        for s in strs.iter() {
            let num = s.parse().unwrap_or(s.len());
            ans = ans.max(num);
        }
        ans as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int MaximumValue(string[] strs) {
        return strs.Max(f);
    }

    private int f(string s) {
        int x = 0;
        foreach (var c in s) {
            if (c >= 'a') {
                return s.Length;
            }
            x = x * 10 + (c - '0');
        }
        return x;
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int parseInt(char* s) {
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (!isdigit(s[i])) {
            return n;
        }
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int maximumValue(char** strs, int strsSize) {
    int ans = 0;
    for (int i = 0; i < strsSize; i++) {
        int num = parseInt(strs[i]);
        ans = max(ans, num);
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
    def maximumValue(self, strs: List[str]) -> int:
        def f(s: str) -> int:
            x = 0
            for c in s:
                if c.isalpha():
                    return len(s)
                x = x * 10 + ord(c) - ord("0")
            return x

        return max(f(s) for s in strs)
```

#### Rust

```rust
impl Solution {
    pub fn maximum_value(strs: Vec<String>) -> i32 {
        let parse = |s: String| -> i32 {
            let mut x = 0;

            for c in s.chars() {
                if c >= 'a' && c <= 'z' {
                    x = s.len();
                    break;
                }

                x = x * 10 + (((c as u8) - b'0') as usize);
            }

            x as i32
        };

        let mut ans = 0;
        for s in strs {
            let v = parse(s);
            if v > ans {
                ans = v;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Rust

```rust
use std::cmp::max;

impl Solution {
    pub fn maximum_value(strs: Vec<String>) -> i32 {
        let mut ans = 0;

        for s in strs {
            match s.parse::<i32>() {
                Ok(v) => {
                    ans = max(ans, v);
                }
                Err(_) => {
                    ans = max(ans, s.len() as i32);
                }
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

# [2497. 图中最大星和](https://leetcode.cn/problems/maximum-star-sum-of-a-graph){#2497}

{{< tabs "2497" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        g = defaultdict(list)
        for a, b in edges:
            if vals[b] > 0:
                g[a].append(vals[b])
            if vals[a] > 0:
                g[b].append(vals[a])
        for bs in g.values():
            bs.sort(reverse=True)
        return max(v + sum(g[i][:k]) for i, v in enumerate(vals))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxStarSum(int[] vals, int[][] edges, int k) {
        int n = vals.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, key -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            if (vals[b] > 0) {
                g[a].add(vals[b]);
            }
            if (vals[a] > 0) {
                g[b].add(vals[a]);
            }
        }
        for (var e : g) {
            Collections.sort(e, (a, b) -> b - a);
        }
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int v = vals[i];
            for (int j = 0; j < Math.min(g[i].size(), k); ++j) {
                v += g[i].get(j);
            }
            ans = Math.max(ans, v);
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
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (vals[b] > 0) g[a].emplace_back(vals[b]);
            if (vals[a] > 0) g[b].emplace_back(vals[a]);
        }
        for (auto& e : g) sort(e.rbegin(), e.rend());
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int v = vals[i];
            for (int j = 0; j < min((int) g[i].size(), k); ++j) v += g[i][j];
            ans = max(ans, v);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxStarSum(vals []int, edges [][]int, k int) (ans int) {
	n := len(vals)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		if vals[b] > 0 {
			g[a] = append(g[a], vals[b])
		}
		if vals[a] > 0 {
			g[b] = append(g[b], vals[a])
		}
	}
	for _, e := range g {
		sort.Sort(sort.Reverse(sort.IntSlice(e)))
	}
	ans = math.MinInt32
	for i, v := range vals {
		for j := 0; j < min(len(g[i]), k); j++ {
			v += g[i][j]
		}
		ans = max(ans, v)
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

<p>给你一个&nbsp;<code>n</code>&nbsp;个点的无向图，节点从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;编号。给你一个长度为 <code>n</code>&nbsp;下标从&nbsp;<strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>vals</code>&nbsp;，其中&nbsp;<code>vals[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个节点的值。</p>

<p>同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条双向边。</p>

<p><strong>星图</strong>&nbsp;是给定图中的一个子图，它包含一个中心节点和&nbsp;<code>0</code>&nbsp;个或更多个邻居。换言之，星图是给定图中一个边的子集，且这些边都有一个公共节点。</p>

<p>下图分别展示了有 <code>3</code>&nbsp;个和 <code>4</code>&nbsp;个邻居的星图，蓝色节点为中心节点。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2497.Maximum%20Star%20Sum%20of%20a%20Graph/images/max-star-sum-descdrawio.png" style="width: 400px; height: 179px;"></p>

<p><strong>星和</strong> 定义为星图中所有节点值的和。</p>

<p>给你一个整数&nbsp;<code>k</code>&nbsp;，请你返回 <strong>至多</strong>&nbsp;包含 <code>k</code>&nbsp;条边的星图中的 <strong>最大星和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2497.Maximum%20Star%20Sum%20of%20a%20Graph/images/max-star-sum-example1drawio.png" style="width: 300px; height: 291px;"></p>

<pre><b>输入：</b>vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
<b>输出：</b>16
<b>解释：</b>上图展示了输入示例。
最大星和对应的星图在上图中用蓝色标出。中心节点是 3 ，星图中还包含邻居 1 和 4 。
无法得到一个和大于 16 且边数不超过 2 的星图。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>vals = [-5], edges = [], k = 0
<b>输出：</b>-5
<b>解释：</b>只有一个星图，就是节点 0 自己。
所以我们返回 -5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == vals.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= vals[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= min(n * (n - 1) / 2</code><code>, 10<sup>5</sup>)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 模拟

我们先将输入的边集合转换成邻接表，其中 $g[i]$ 表示节点 $i$ 的邻居节点的值列表，且按照值的降序排列。

然后我们遍历每个节点 $i$，计算以 $i$ 为中心节点的星图的最大星和，即 $vals[i] + \sum_{j=0}^{k-1} g[i][j]$，并且更新最大星和。

最后返回最大星和即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$，其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        g = defaultdict(list)
        for a, b in edges:
            if vals[b] > 0:
                g[a].append(vals[b])
            if vals[a] > 0:
                g[b].append(vals[a])
        for bs in g.values():
            bs.sort(reverse=True)
        return max(v + sum(g[i][:k]) for i, v in enumerate(vals))
```

#### Java

```java
class Solution {
    public int maxStarSum(int[] vals, int[][] edges, int k) {
        int n = vals.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, key -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            if (vals[b] > 0) {
                g[a].add(vals[b]);
            }
            if (vals[a] > 0) {
                g[b].add(vals[a]);
            }
        }
        for (var e : g) {
            Collections.sort(e, (a, b) -> b - a);
        }
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int v = vals[i];
            for (int j = 0; j < Math.min(g[i].size(), k); ++j) {
                v += g[i].get(j);
            }
            ans = Math.max(ans, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (vals[b] > 0) g[a].emplace_back(vals[b]);
            if (vals[a] > 0) g[b].emplace_back(vals[a]);
        }
        for (auto& e : g) sort(e.rbegin(), e.rend());
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int v = vals[i];
            for (int j = 0; j < min((int) g[i].size(), k); ++j) v += g[i][j];
            ans = max(ans, v);
        }
        return ans;
    }
};
```

#### Go

```go
func maxStarSum(vals []int, edges [][]int, k int) (ans int) {
	n := len(vals)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		if vals[b] > 0 {
			g[a] = append(g[a], vals[b])
		}
		if vals[a] > 0 {
			g[b] = append(g[b], vals[a])
		}
	}
	for _, e := range g {
		sort.Sort(sort.Reverse(sort.IntSlice(e)))
	}
	ans = math.MinInt32
	for i, v := range vals {
		for j := 0; j < min(len(g[i]), k); j++ {
			v += g[i][j]
		}
		ans = max(ans, v)
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2498. 青蛙过河 II](https://leetcode.cn/problems/frog-jump-ii){#2498}

{{< tabs "2498" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxJump(self, stones: List[int]) -> int:
        ans = stones[1] - stones[0]
        for i in range(2, len(stones)):
            ans = max(ans, stones[i] - stones[i - 2])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxJump(int[] stones) {
        int ans = stones[1] - stones[0];
        for (int i = 2; i < stones.length; ++i) {
            ans = Math.max(ans, stones[i] - stones[i - 2]);
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
    int maxJump(vector<int>& stones) {
        int ans = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); ++i) ans = max(ans, stones[i] - stones[i - 2]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxJump(stones []int) int {
	ans := stones[1] - stones[0]
	for i := 2; i < len(stones); i++ {
		ans = max(ans, stones[i]-stones[i-2])
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>stones</code>&nbsp;，数组中的元素&nbsp;<strong>严格递增</strong>&nbsp;，表示一条河中石头的位置。</p>

<p>一只青蛙一开始在第一块石头上，它想到达最后一块石头，然后回到第一块石头。同时每块石头 <strong>至多</strong> 到达 <strong>一次。</strong></p>

<p>一次跳跃的 <strong>长度</strong>&nbsp;是青蛙跳跃前和跳跃后所在两块石头之间的距离。</p>

<ul>
	<li>更正式的，如果青蛙从&nbsp;<code>stones[i]</code>&nbsp;跳到&nbsp;<code>stones[j]</code>&nbsp;，跳跃的长度为&nbsp;<code>|stones[i] - stones[j]|</code>&nbsp;。</li>
</ul>

<p>一条路径的 <b>代价</b>&nbsp;是这条路径里的&nbsp;<b>最大跳跃长度</b>&nbsp;。</p>

<p>请你返回这只青蛙的 <strong>最小代价</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2498.Frog%20Jump%20II/images/example-1.png" style="width: 600px; height: 219px;" /></p>

<pre>
<b>输入：</b>stones = [0,2,5,6,7]
<b>输出：</b>5
<b>解释：</b>上图展示了一条最优路径。
这条路径的代价是 5 ，是这条路径中的最大跳跃长度。
无法得到一条代价小于 5 的路径，我们返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2498.Frog%20Jump%20II/images/example-2.png" style="width: 500px; height: 171px;" /></p>

<pre>
<b>输入：</b>stones = [0,3,9]
<b>输出：</b>9
<b>解释：</b>
青蛙可以直接跳到最后一块石头，然后跳回第一块石头。
在这条路径中，每次跳跃长度都是 9 。所以路径代价是 max(9, 9) = 9 。
这是可行路径中的最小代价。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= stones.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= stones[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>stones[0] == 0</code></li>
	<li><code>stones</code>&nbsp;中的元素严格递增。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

要使得跳跃过程中的每一步的最大跳跃长度最小，我们应该将跳跃过程切分成尽可能多的连续的步骤。通过观察，间隔跳跃可以获取最优解。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `stones` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxJump(self, stones: List[int]) -> int:
        ans = stones[1] - stones[0]
        for i in range(2, len(stones)):
            ans = max(ans, stones[i] - stones[i - 2])
        return ans
```

#### Java

```java
class Solution {
    public int maxJump(int[] stones) {
        int ans = stones[1] - stones[0];
        for (int i = 2; i < stones.length; ++i) {
            ans = Math.max(ans, stones[i] - stones[i - 2]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); ++i) ans = max(ans, stones[i] - stones[i - 2]);
        return ans;
    }
};
```

#### Go

```go
func maxJump(stones []int) int {
	ans := stones[1] - stones[0]
	for i := 2; i < len(stones); i++ {
		ans = max(ans, stones[i]-stones[i-2])
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2499. 让数组不相等的最小总代价](https://leetcode.cn/problems/minimum-total-cost-to-make-arrays-unequal){#2499}

{{< tabs "2499" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTotalCost(self, nums1: List[int], nums2: List[int]) -> int:
        ans = same = 0
        cnt = Counter()
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            if a == b:
                same += 1
                ans += i
                cnt[a] += 1

        m = lead = 0
        for k, v in cnt.items():
            if v * 2 > same:
                m = v * 2 - same
                lead = k
                break
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            if m and a != b and a != lead and b != lead:
                ans += i
                m -= 1
        return -1 if m else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumTotalCost(int[] nums1, int[] nums2) {
        long ans = 0;
        int same = 0;
        int n = nums1.length;
        int[] cnt = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                ++same;
                ++cnt[nums1[i]];
            }
        }
        int m = 0, lead = 0;
        for (int i = 0; i < cnt.length; ++i) {
            int t = cnt[i] * 2 - same;
            if (t > 0) {
                m = t;
                lead = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (m > 0 && nums1[i] != nums2[i] && nums1[i] != lead && nums2[i] != lead) {
                ans += i;
                --m;
            }
        }
        return m > 0 ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int same = 0;
        int n = nums1.size();
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                ++same;
                ++cnt[nums1[i]];
            }
        }
        int m = 0, lead = 0;
        for (int i = 0; i < n + 1; ++i) {
            int t = cnt[i] * 2 - same;
            if (t > 0) {
                m = t;
                lead = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (m > 0 && nums1[i] != nums2[i] && nums1[i] != lead && nums2[i] != lead) {
                ans += i;
                --m;
            }
        }
        return m > 0 ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTotalCost(nums1 []int, nums2 []int) (ans int64) {
	same, n := 0, len(nums1)
	cnt := make([]int, n+1)
	for i, a := range nums1 {
		b := nums2[i]
		if a == b {
			same++
			ans += int64(i)
			cnt[a]++
		}
	}
	var m, lead int
	for i, v := range cnt {
		if t := v*2 - same; t > 0 {
			m = t
			lead = i
			break
		}
	}
	for i, a := range nums1 {
		b := nums2[i]
		if m > 0 && a != b && a != lead && b != lead {
			ans += int64(i)
			m--
		}
	}
	if m > 0 {
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

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;，两者长度都为&nbsp;<code>n</code>&nbsp;。</p>

<p>每次操作中，你可以选择交换 <code>nums1</code>&nbsp;中任意两个下标处的值。操作的 <strong>开销</strong>&nbsp;为两个下标的 <strong>和</strong>&nbsp;。</p>

<p>你的目标是对于所有的 <code>0 &lt;= i &lt;= n - 1</code>&nbsp;，都满足&nbsp;<code>nums1[i] != nums2[i]</code>&nbsp;，你可以进行 <strong>任意次</strong>&nbsp;操作，请你返回达到这个目标的 <strong>最小</strong>&nbsp;总代价。</p>

<p>请你返回让<em>&nbsp;</em><code>nums1</code> 和&nbsp;<code>nums2</code><em>&nbsp;</em>满足上述条件的 <strong>最小总代价</strong> ，如果无法达成目标，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,2,3,4,5], nums2 = [1,2,3,4,5]
<b>输出：</b>10
<b>解释：</b>
实现目标的其中一种方法为：
- 交换下标为 0 和 3 的两个值，代价为 0 + 3 = 3 。现在 nums1 = [4,2,3,1,5] 。
- 交换下标为 1 和 2 的两个值，代价为 1 + 2 = 3 。现在 nums1 = [4,3,2,1,5] 。
- 交换下标为 0 和 4 的两个值，代价为 0 + 4 = 4 。现在 nums1 = [5,3,2,1,4] 。
最后，对于每个下标 i ，都有 nums1[i] != nums2[i] 。总代价为 10 。
还有别的交换值的方法，但是无法得到代价和小于 10 的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums1 = [2,2,2,1,3], nums2 = [1,2,2,3,3]
<b>输出：</b>10
<b>解释：</b>
实现目标的一种方法为：
- 交换下标为 2 和 3 的两个值，代价为 2 + 3 = 5 。现在 nums1 = [2,2,1,2,3] 。
- 交换下标为 1 和 4 的两个值，代价为 1 + 4 = 5 。现在 nums1 = [2,3,1,2,2] 。
总代价为 10 ，是所有方案中的最小代价。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,2,2], nums2 = [1,2,2]
<b>输出：</b>-1
<b>解释：</b>
不管怎么操作，都无法满足题目要求。
所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先同时遍历数组 `nums1` 和 `nums2`，统计相同位置上的值相同的个数 `same`，这些位置上的值必须交换，因此，将这些位置下标累加到答案中。另外，用数组或哈希表 `cnt` 统计这些相同值的出现次数。

如果所有相同值的出现次数均不超过 `same` 的一半，那么意味着，我们可以在其内部，通过两两交换，使得对应位置上的值不同，而这些交换，已经在上面累加下标时计入了答案中了，无需额外的代价。否则，如果某个值的出现次数超过 `same` 的一半，那么对于这个值就是多出的个数，我们需要在数组的其他位置上找到合适的，进行交换。这里我们可以直接遍历一遍数组得出。

如果最终还有剩余位置未能交换，说明无法达成目标，返回 $-1$ 即可，否则返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `nums1` 或 `nums2` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTotalCost(self, nums1: List[int], nums2: List[int]) -> int:
        ans = same = 0
        cnt = Counter()
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            if a == b:
                same += 1
                ans += i
                cnt[a] += 1

        m = lead = 0
        for k, v in cnt.items():
            if v * 2 > same:
                m = v * 2 - same
                lead = k
                break
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            if m and a != b and a != lead and b != lead:
                ans += i
                m -= 1
        return -1 if m else ans
```

#### Java

```java
class Solution {
    public long minimumTotalCost(int[] nums1, int[] nums2) {
        long ans = 0;
        int same = 0;
        int n = nums1.length;
        int[] cnt = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                ++same;
                ++cnt[nums1[i]];
            }
        }
        int m = 0, lead = 0;
        for (int i = 0; i < cnt.length; ++i) {
            int t = cnt[i] * 2 - same;
            if (t > 0) {
                m = t;
                lead = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (m > 0 && nums1[i] != nums2[i] && nums1[i] != lead && nums2[i] != lead) {
                ans += i;
                --m;
            }
        }
        return m > 0 ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int same = 0;
        int n = nums1.size();
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                ++same;
                ++cnt[nums1[i]];
            }
        }
        int m = 0, lead = 0;
        for (int i = 0; i < n + 1; ++i) {
            int t = cnt[i] * 2 - same;
            if (t > 0) {
                m = t;
                lead = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (m > 0 && nums1[i] != nums2[i] && nums1[i] != lead && nums2[i] != lead) {
                ans += i;
                --m;
            }
        }
        return m > 0 ? -1 : ans;
    }
};
```

#### Go

```go
func minimumTotalCost(nums1 []int, nums2 []int) (ans int64) {
	same, n := 0, len(nums1)
	cnt := make([]int, n+1)
	for i, a := range nums1 {
		b := nums2[i]
		if a == b {
			same++
			ans += int64(i)
			cnt[a]++
		}
	}
	var m, lead int
	for i, v := range cnt {
		if t := v*2 - same; t > 0 {
			m = t
			lead = i
			break
		}
	}
	for i, a := range nums1 {
		b := nums2[i]
		if m > 0 && a != b && a != lead && b != lead {
			ans += int64(i)
			m--
		}
	}
	if m > 0 {
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
