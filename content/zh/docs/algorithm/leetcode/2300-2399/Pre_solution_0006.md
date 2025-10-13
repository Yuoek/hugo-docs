---
title: "2350_不可能得到的最短骰子序列"
date: 2025-10-08T18:39:12+08:00
weight: 6
tags: [二分查找, 位运算, 动态规划, 单调栈, 哈希表, 图, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 有序集合, 栈, 模拟, 深度优先搜索, 矩阵, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2350_不可能得到的最短骰子序列](#2350)
#### [贪心](#2350)
#### [数组](#2350)
#### [哈希表](#2350)
### [2351_第一个出现两次的字母](#2351)
#### [位运算](#2351)
#### [哈希表](#2351)
#### [字符串](#2351)
#### [计数](#2351)
### [2352_相等行列对](#2352)
#### [数组](#2352)
#### [哈希表](#2352)
#### [矩阵](#2352)
#### [模拟](#2352)
### [2353_设计食物评分系统](#2353)
#### [设计](#2353)
#### [数组](#2353)
#### [哈希表](#2353)
#### [字符串](#2353)
#### [有序集合](#2353)
#### [堆（优先队列）](#2353)
### [2354_优质数对的数目](#2354)
#### [位运算](#2354)
#### [数组](#2354)
#### [哈希表](#2354)
#### [二分查找](#2354)
### [2355_你能拿走的最大图书数量 🔒](#2355)
#### [栈](#2355)
#### [数组](#2355)
#### [动态规划](#2355)
#### [单调栈](#2355)
### [2356_每位教师所教授的科目种类的数量](#2356)
#### [数据库](#2356)
### [2357_使数组中所有元素都等于零](#2357)
#### [贪心](#2357)
#### [数组](#2357)
#### [哈希表](#2357)
#### [排序](#2357)
#### [模拟](#2357)
#### [堆（优先队列）](#2357)
### [2358_分组的最大数量](#2358)
#### [贪心](#2358)
#### [数组](#2358)
#### [数学](#2358)
#### [二分查找](#2358)
### [2359_找到离给定两个节点最近的节点](#2359)
#### [深度优先搜索](#2359)
#### [图](#2359)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2350_不可能得到的最短骰子序列
___
#### 贪心
___
#### 数组
___
#### 哈希表
---
### 2351_第一个出现两次的字母
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2352_相等行列对
___
#### 数组
___
#### 哈希表
___
#### 矩阵
___
#### 模拟
---
### 2353_设计食物评分系统
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 有序集合
___
#### 堆（优先队列）
---
### 2354_优质数对的数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 二分查找
---
### 2355_你能拿走的最大图书数量 🔒
___
#### 栈
___
#### 数组
___
#### 动态规划
___
#### 单调栈
---
### 2356_每位教师所教授的科目种类的数量
___
#### 数据库
---
### 2357_使数组中所有元素都等于零
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 2358_分组的最大数量
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 二分查找
---
### 2359_找到离给定两个节点最近的节点
___
#### 深度优先搜索
___
#### 图
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 栈 | 模拟 |
| 深度优先搜索 | 矩阵 | 计数 |
| 设计 | 贪心 |  |

# [2350. 不可能得到的最短骰子序列](https://leetcode.cn/problems/shortest-impossible-sequence-of-rolls){#2350}

{{< tabs "2350" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        ans = 1
        s = set()
        for v in rolls:
            s.add(v)
            if len(s) == k:
                ans += 1
                s.clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestSequence(int[] rolls, int k) {
        Set<Integer> s = new HashSet<>();
        int ans = 1;
        for (int v : rolls) {
            s.add(v);
            if (s.size() == k) {
                s.clear();
                ++ans;
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
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> s;
        int ans = 1;
        for (int v : rolls) {
            s.insert(v);
            if (s.size() == k) {
                s.clear();
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestSequence(rolls []int, k int) int {
	s := map[int]bool{}
	ans := 1
	for _, v := range rolls {
		s[v] = true
		if len(s) == k {
			ans++
			s = map[int]bool{}
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>rolls</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。你扔一个&nbsp;<code>k</code>&nbsp;面的骰子 <code>n</code>&nbsp;次，骰子的每个面分别是&nbsp;<code>1</code>&nbsp;到&nbsp;<code>k</code>&nbsp;，其中第&nbsp;<code>i</code>&nbsp;次扔得到的数字是&nbsp;<code>rolls[i]</code>&nbsp;。</p>

<p>请你返回 <strong>无法</strong>&nbsp;从 <code>rolls</code>&nbsp;中得到的 <strong>最短</strong>&nbsp;骰子子序列的长度。</p>

<p>扔一个 <code>k</code>&nbsp;面的骰子 <code>len</code>&nbsp;次得到的是一个长度为 <code>len</code>&nbsp;的 <strong>骰子子序列</strong>&nbsp;。</p>

<p><strong>注意</strong>&nbsp;，子序列只需要保持在原数组中的顺序，不需要连续。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>rolls = [4,2,1,2,3,3,2,4,1], k = 4
<b>输出：</b>3
<b>解释：</b>所有长度为 1 的骰子子序列 [1] ，[2] ，[3] ，[4] 都可以从原数组中得到。
所有长度为 2 的骰子子序列 [1, 1] ，[1, 2] ，... ，[4, 4] 都可以从原数组中得到。
子序列 [1, 4, 2] 无法从原数组中得到，所以我们返回 3 。
还有别的子序列也无法从原数组中得到。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>rolls = [1,1,2,2], k = 2
<b>输出：</b>2
<b>解释：</b>所有长度为 1 的子序列 [1] ，[2] 都可以从原数组中得到。
子序列 [2, 1] 无法从原数组中得到，所以我们返回 2 。
还有别的子序列也无法从原数组中得到，但 [2, 1] 是最短的子序列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>rolls = [1,1,3,2,2,2,3,3], k = 4
<b>输出：</b>1
<b>解释：</b>子序列 [4] 无法从原数组中得到，所以我们返回 1 。
还有别的子序列也无法从原数组中得到，但 [4] 是最短的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rolls.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= rolls[i] &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

时间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        ans = 1
        s = set()
        for v in rolls:
            s.add(v)
            if len(s) == k:
                ans += 1
                s.clear()
        return ans
```

#### Java

```java
class Solution {
    public int shortestSequence(int[] rolls, int k) {
        Set<Integer> s = new HashSet<>();
        int ans = 1;
        for (int v : rolls) {
            s.add(v);
            if (s.size() == k) {
                s.clear();
                ++ans;
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
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> s;
        int ans = 1;
        for (int v : rolls) {
            s.insert(v);
            if (s.size() == k) {
                s.clear();
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shortestSequence(rolls []int, k int) int {
	s := map[int]bool{}
	ans := 1
	for _, v := range rolls {
		s[v] = true
		if len(s) == k {
			ans++
			s = map[int]bool{}
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

# [2351. 第一个出现两次的字母](https://leetcode.cn/problems/first-letter-to-appear-twice){#2351}

{{< tabs "2351" >}}

{{% tab "python" %}}
```python
class Solution:
    def repeatedCharacter(self, s: str) -> str:
        mask = 0
        for c in s:
            i = ord(c) - ord('a')
            if mask >> i & 1:
                return c
            mask |= 1 << i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char repeatedCharacter(String s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            char c = s.charAt(i);
            if ((mask >> (c - 'a') & 1) == 1) {
                return c;
            }
            mask |= 1 << (c - 'a');
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            if (mask >> (s[i] - 'a') & 1) {
                return s[i];
            }
            mask |= 1 << (s[i] - 'a');
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repeatedCharacter(s string) byte {
	mask := 0
	for i := 0; ; i++ {
		if mask>>(s[i]-'a')&1 == 1 {
			return s[i]
		}
		mask |= 1 << (s[i] - 'a')
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repeatedCharacter(s: string): string {
    let mask = 0;
    for (const c of s) {
        const i = c.charCodeAt(0) - 'a'.charCodeAt(0);
        if (mask & (1 << i)) {
            return c;
        }
        mask |= 1 << i;
    }
    return ' ';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut mask = 0;
        for &c in s.as_bytes() {
            if (mask & (1 << ((c - b'a') as i32))) != 0 {
                return c as char;
            }
            mask |= 1 << ((c - b'a') as i32);
        }
        ' '
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function repeatedCharacter($s) {
        for ($i = 0; ; $i++) {
            $hashtable[$s[$i]] += 1;
            if ($hashtable[$s[$i]] == 2) {
                return $s[$i];
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char repeatedCharacter(char* s) {
    int mask = 0;
    for (int i = 0; s[i]; i++) {
        if (mask & (1 << s[i] - 'a')) {
            return s[i];
        }
        mask |= 1 << s[i] - 'a';
    }
    return ' ';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由小写英文字母组成的字符串 <code>s</code> ，请你找出并返回第一个出现 <strong>两次</strong> 的字母。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果 <code>a</code> 的 <strong>第二次</strong> 出现比 <code>b</code> 的 <strong>第二次</strong> 出现在字符串中的位置更靠前，则认为字母 <code>a</code> 在字母 <code>b</code> 之前出现两次。</li>
	<li><code>s</code> 包含至少一个出现两次的字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abccbaacz"
<strong>输出：</strong>"c"
<strong>解释：</strong>
字母 'a' 在下标 0 、5 和 6 处出现。
字母 'b' 在下标 1 和 4 处出现。
字母 'c' 在下标 2 、3 和 7 处出现。
字母 'z' 在下标 8 处出现。
字母 'c' 是第一个出现两次的字母，因为在所有字母中，'c' 第二次出现的下标是最小的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcdd"
<strong>输出：</strong>"d"
<strong>解释：</strong>
只有字母 'd' 出现两次，所以返回 'd' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>s</code> 包含至少一个重复字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

遍历字符串 $s$，用数组或哈希表 `cnt` 记录每个字母出现的次数，当某个字母出现两次时，返回该字母。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 为字符集大小。本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def repeatedCharacter(self, s: str) -> str:
        cnt = Counter()
        for c in s:
            cnt[c] += 1
            if cnt[c] == 2:
                return c
```

#### Java

```java
class Solution {
    public char repeatedCharacter(String s) {
        int[] cnt = new int[26];
        for (int i = 0;; ++i) {
            char c = s.charAt(i);
            if (++cnt[c - 'a'] == 2) {
                return c;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    char repeatedCharacter(string s) {
        int cnt[26]{};
        for (int i = 0;; ++i) {
            if (++cnt[s[i] - 'a'] == 2) {
                return s[i];
            }
        }
    }
};
```

#### Go

```go
func repeatedCharacter(s string) byte {
	cnt := [26]int{}
	for i := 0; ; i++ {
		cnt[s[i]-'a']++
		if cnt[s[i]-'a'] == 2 {
			return s[i]
		}
	}
}
```

#### TypeScript

```ts
function repeatedCharacter(s: string): string {
    const vis = new Array(26).fill(false);
    for (const c of s) {
        const i = c.charCodeAt(0) - 'a'.charCodeAt(0);
        if (vis[i]) {
            return c;
        }
        vis[i] = true;
    }
    return ' ';
}
```

#### Rust

```rust
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut vis = [false; 26];
        for &c in s.as_bytes() {
            if vis[(c - b'a') as usize] {
                return c as char;
            }
            vis[(c - b'a') as usize] = true;
        }
        ' '
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function repeatedCharacter($s) {
        for ($i = 0; ; $i++) {
            $hashtable[$s[$i]] += 1;
            if ($hashtable[$s[$i]] == 2) {
                return $s[$i];
            }
        }
    }
}
```

#### C

```c
char repeatedCharacter(char* s) {
    int vis[26] = {0};
    for (int i = 0; s[i]; i++) {
        if (vis[s[i] - 'a']) {
            return s[i];
        }
        vis[s[i] - 'a']++;
    }
    return ' ';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

我们也可以用一个整数 `mask` 记录每个字母是否出现过，其中 `mask` 的第 $i$ 位表示第 $i$ 个字母是否出现过。当某个字母出现两次时，返回该字母。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def repeatedCharacter(self, s: str) -> str:
        mask = 0
        for c in s:
            i = ord(c) - ord('a')
            if mask >> i & 1:
                return c
            mask |= 1 << i
```

#### Java

```java
class Solution {
    public char repeatedCharacter(String s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            char c = s.charAt(i);
            if ((mask >> (c - 'a') & 1) == 1) {
                return c;
            }
            mask |= 1 << (c - 'a');
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            if (mask >> (s[i] - 'a') & 1) {
                return s[i];
            }
            mask |= 1 << (s[i] - 'a');
        }
    }
};
```

#### Go

```go
func repeatedCharacter(s string) byte {
	mask := 0
	for i := 0; ; i++ {
		if mask>>(s[i]-'a')&1 == 1 {
			return s[i]
		}
		mask |= 1 << (s[i] - 'a')
	}
}
```

#### TypeScript

```ts
function repeatedCharacter(s: string): string {
    let mask = 0;
    for (const c of s) {
        const i = c.charCodeAt(0) - 'a'.charCodeAt(0);
        if (mask & (1 << i)) {
            return c;
        }
        mask |= 1 << i;
    }
    return ' ';
}
```

#### Rust

```rust
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut mask = 0;
        for &c in s.as_bytes() {
            if (mask & (1 << ((c - b'a') as i32))) != 0 {
                return c as char;
            }
            mask |= 1 << ((c - b'a') as i32);
        }
        ' '
    }
}
```

#### C

```c
char repeatedCharacter(char* s) {
    int mask = 0;
    for (int i = 0; s[i]; i++) {
        if (mask & (1 << s[i] - 'a')) {
            return s[i];
        }
        mask |= 1 << s[i] - 'a';
    }
    return ' ';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2352. 相等行列对](https://leetcode.cn/problems/equal-row-and-column-pairs){#2352}

{{< tabs "2352" >}}

{{% tab "python" %}}
```python
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for i in range(n):
            for j in range(n):
                ans += all(grid[i][k] == grid[k][j] for k in range(n))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ok = 1;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
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
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ok = 1;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equalPairs(grid [][]int) (ans int) {
	for i := range grid {
		for j := range grid {
			ok := 1
			for k := range grid {
				if grid[i][k] != grid[k][j] {
					ok = 0
					break
				}
			}
			ans += ok
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function equalPairs(grid: number[][]): number {
    const n = grid.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            let ok = 1;
            for (let k = 0; k < n; ++k) {
                if (grid[i][k] !== grid[k][j]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
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

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n x n</code> 的整数矩阵 <code>grid</code> ，返回满足 <code>R<sub>i</sub></code><em> </em>行和<em> </em><code>C<sub>j</sub></code><em> </em>列相等的行列对<em> </em><code>(R<sub>i</sub>, C<sub>j</sub>)</code><em> </em>的数目<em>。</em></p>

<p>如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2352.Equal%20Row%20and%20Column%20Pairs/images/ex1.jpg" style="width: 150px; height: 153px;" /></p>

<pre>
<strong>输入：</strong>grid = [[3,2,1],[1,7,6],[2,7,7]]
<strong>输出：</strong>1
<strong>解释：</strong>存在一对相等行列对：
- (第 2 行，第 1 列)：[2,7,7]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2352.Equal%20Row%20and%20Column%20Pairs/images/ex2.jpg" style="width: 200px; height: 209px;" /></p>

<pre>
<strong>输入：</strong>grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
<strong>输出：</strong>3
<strong>解释：</strong>存在三对相等行列对：
- (第 0 行，第 0 列)：[3,1,2,2]
- (第 2 行, 第 2 列)：[2,4,2,2]
- (第 3 行, 第 2 列)：[2,4,2,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接将矩阵 $grid$ 的每一行和每一列进行比较，如果相等，那么就是一对相等行列对，答案加一。

时间复杂度 $O(n^3)$，其中 $n$ 为矩阵 $grid$ 的行数或列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for i in range(n):
            for j in range(n):
                ans += all(grid[i][k] == grid[k][j] for k in range(n))
        return ans
```

#### Java

```java
class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ok = 1;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
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
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ok = 1;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func equalPairs(grid [][]int) (ans int) {
	for i := range grid {
		for j := range grid {
			ok := 1
			for k := range grid {
				if grid[i][k] != grid[k][j] {
					ok = 0
					break
				}
			}
			ans += ok
		}
	}
	return
}
```

#### TypeScript

```ts
function equalPairs(grid: number[][]): number {
    const n = grid.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            let ok = 1;
            for (let k = 0; k < n; ++k) {
                if (grid[i][k] !== grid[k][j]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
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

# [2353. 设计食物评分系统](https://leetcode.cn/problems/design-a-food-rating-system){#2353}

{{< tabs "2353" >}}

{{% tab "python" %}}
```python
class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.d = defaultdict(SortedList)
        self.g = {}
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.d[cuisine].add((-rating, food))
            self.g[food] = (rating, cuisine)

    def changeRating(self, food: str, newRating: int) -> None:
        oldRating, cuisine = self.g[food]
        self.g[food] = (newRating, cuisine)
        self.d[cuisine].remove((-oldRating, food))
        self.d[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.d[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FoodRatings {
    private Map<String, TreeSet<Pair<Integer, String>>> d = new HashMap<>();
    private Map<String, Pair<Integer, String>> g = new HashMap<>();
    private final Comparator<Pair<Integer, String>> cmp = (a, b) -> {
        if (!a.getKey().equals(b.getKey())) {
            return b.getKey().compareTo(a.getKey());
        }
        return a.getValue().compareTo(b.getValue());
    };

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; ++i) {
            String food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            d.computeIfAbsent(cuisine, k -> new TreeSet<>(cmp)).add(new Pair<>(rating, food));
            g.put(food, new Pair<>(rating, cuisine));
        }
    }

    public void changeRating(String food, int newRating) {
        Pair<Integer, String> old = g.get(food);
        int oldRating = old.getKey();
        String cuisine = old.getValue();
        g.put(food, new Pair<>(newRating, cuisine));
        d.get(cuisine).remove(new Pair<>(oldRating, food));
        d.get(cuisine).add(new Pair<>(newRating, food));
    }

    public String highestRated(String cuisine) {
        return d.get(cuisine).first().getValue();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            d[cuisine].insert({-rating, food});
            g[food] = {rating, cuisine};
        }
    }

    void changeRating(string food, int newRating) {
        auto [oldRating, cuisine] = g[food];
        g[food] = {newRating, cuisine};
        d[cuisine].erase({-oldRating, food});
        d[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return d[cuisine].begin()->second;
    }

private:
    unordered_map<string, set<pair<int, string>>> d;
    unordered_map<string, pair<int, string>> g;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
import (
	"github.com/emirpasic/gods/v2/trees/redblacktree"
)

type pair struct {
	rating int
	food   string
}

type FoodRatings struct {
	d map[string]*redblacktree.Tree[pair, struct{}]
	g map[string]pair
}

func Constructor(foods []string, cuisines []string, ratings []int) FoodRatings {
	d := make(map[string]*redblacktree.Tree[pair, struct{}])
	g := make(map[string]pair)

	for i, food := range foods {
		rating, cuisine := ratings[i], cuisines[i]
		g[food] = pair{rating, cuisine}

		if d[cuisine] == nil {
			d[cuisine] = redblacktree.NewWith[pair, struct{}](func(a, b pair) int {
				return cmp.Or(b.rating-a.rating, strings.Compare(a.food, b.food))
			})
		}
		d[cuisine].Put(pair{rating, food}, struct{}{})
	}

	return FoodRatings{d, g}
}

func (this *FoodRatings) ChangeRating(food string, newRating int) {
	p := this.g[food]
	t := this.d[p.food]

	t.Remove(pair{p.rating, food})
	t.Put(pair{newRating, food}, struct{}{})

	p.rating = newRating
	this.g[food] = p
}

func (this *FoodRatings) HighestRated(cuisine string) string {
	return this.d[cuisine].Left().Key.food
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * obj := Constructor(foods, cuisines, ratings);
 * obj.ChangeRating(food,newRating);
 * param_2 := obj.HighestRated(cuisine);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个支持下述操作的食物评分系统：</p>

<ul>
	<li><strong>修改</strong> 系统中列出的某种食物的评分。</li>
	<li>返回系统中某一类烹饪方式下评分最高的食物。</li>
</ul>

<p>实现 <code>FoodRatings</code> 类：</p>

<ul>
	<li><code>FoodRatings(String[] foods, String[] cuisines, int[] ratings)</code> 初始化系统。食物由 <code>foods</code>、<code>cuisines</code> 和 <code>ratings</code> 描述，长度均为 <code>n</code> 。

    <ul>
    	<li><code>foods[i]</code> 是第 <code>i</code> 种食物的名字。</li>
    	<li><code>cuisines[i]</code> 是第 <code>i</code> 种食物的烹饪方式。</li>
    	<li><code>ratings[i]</code> 是第 <code>i</code> 种食物的最初评分。</li>
    </ul>
    </li>
    <li><code>void changeRating(String food, int newRating)</code> 修改名字为 <code>food</code> 的食物的评分。</li>
    <li><code>String highestRated(String cuisine)</code> 返回指定烹饪方式 <code>cuisine</code> 下评分最高的食物的名字。如果存在并列，返回 <strong>字典序较小</strong> 的名字。</li>

</ul>

<p>注意，字符串 <code>x</code> 的字典序比字符串 <code>y</code> 更小的前提是：<code>x</code> 在字典中出现的位置在 <code>y</code> 之前，也就是说，要么 <code>x</code> 是 <code>y</code> 的前缀，或者在满足&nbsp;<code>x[i] != y[i]</code> 的第一个位置 <code>i</code> 处，<code>x[i]</code> 在字母表中出现的位置在 <code>y[i]</code> 之前。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入</strong>
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
<strong>输出</strong>
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

<strong>解释</strong>
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // 返回 "kimchi"
                                    // "kimchi" 是分数最高的韩式料理，评分为 9 。
foodRatings.highestRated("japanese"); // 返回 "ramen"
                                      // "ramen" 是分数最高的日式料理，评分为 14 。
foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
foodRatings.highestRated("japanese"); // 返回 "sushi"
                                      // "sushi" 是分数最高的日式料理，评分为 16 。
foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
foodRatings.highestRated("japanese"); // 返回 "ramen"
                                      // "sushi" 和 "ramen" 的评分都是 16 。
                                      // 但是，"ramen" 的字典序比 "sushi" 更小。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>n == foods.length == cuisines.length == ratings.length</code></li>
	<li><code>1 &lt;= foods[i].length, cuisines[i].length &lt;= 10</code></li>
	<li><code>foods[i]</code>、<code>cuisines[i]</code> 由小写英文字母组成</li>
	<li><code>1 &lt;= ratings[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>foods</code> 中的所有字符串 <strong>互不相同</strong></li>
	<li>在对&nbsp;<code>changeRating</code> 的所有调用中，<code>food</code> 是系统中食物的名字。</li>
	<li>在对&nbsp;<code>highestRated</code> 的所有调用中，<code>cuisine</code> 是系统中 <strong>至少一种</strong> 食物的烹饪方式。</li>
	<li>最多调用 <code>changeRating</code> 和 <code>highestRated</code> <strong>总计</strong> <code>2 * 10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序集合

我们可以使用哈希表 $\textit{d}$ 来存储每种烹饪方式下的食物，其中键是烹饪方式，值是一个有序集合，有序集合的每个元素是一个二元组 $(\textit{rating}, \textit{food})$，按照评分从高到低排序，如果评分相同，则按照食物名字的字典序从小到大排序。

我们还可以使用哈希表 $\textit{g}$ 来存储每种食物的评分和烹饪方式。即 $\textit{g}[\textit{food}] = (\textit{rating}, \textit{cuisine})$。

在构造函数中，我们遍历 $\textit{foods}$、$\textit{cuisines}$ 和 $\textit{ratings}$，将每种食物的评分和烹饪方式存储到 $\textit{d}$ 和 $\textit{g}$ 中。

在 $\textit{changeRating}$ 函数中，我们首先获取食物 $\textit{food}$ 的原评分 $\textit{oldRating}$ 和烹饪方式 $\textit{cuisine}$，然后更新 $\textit{g}[\textit{food}]$ 的评分为 $\textit{newRating}$，并从 $\textit{d}[\textit{cuisine}]$ 中删除 $(\textit{oldRating}, \textit{food})$，并将 $(\textit{newRating}, \textit{food})$ 添加到 $\textit{d}[\textit{cuisine}]$ 中。

在 $\textit{highestRated}$ 函数中，我们直接返回 $\textit{d}[\textit{cuisine}]$ 的第一个元素的食物名字即可。

时间复杂度方面，构造函数的时间复杂度为 $O(n \log n)$，其中 $n$ 是食物的数量。其余操作的时间复杂度为 $O(\log n)$。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.d = defaultdict(SortedList)
        self.g = {}
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.d[cuisine].add((-rating, food))
            self.g[food] = (rating, cuisine)

    def changeRating(self, food: str, newRating: int) -> None:
        oldRating, cuisine = self.g[food]
        self.g[food] = (newRating, cuisine)
        self.d[cuisine].remove((-oldRating, food))
        self.d[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.d[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
```

#### Java

```java
class FoodRatings {
    private Map<String, TreeSet<Pair<Integer, String>>> d = new HashMap<>();
    private Map<String, Pair<Integer, String>> g = new HashMap<>();
    private final Comparator<Pair<Integer, String>> cmp = (a, b) -> {
        if (!a.getKey().equals(b.getKey())) {
            return b.getKey().compareTo(a.getKey());
        }
        return a.getValue().compareTo(b.getValue());
    };

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; ++i) {
            String food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            d.computeIfAbsent(cuisine, k -> new TreeSet<>(cmp)).add(new Pair<>(rating, food));
            g.put(food, new Pair<>(rating, cuisine));
        }
    }

    public void changeRating(String food, int newRating) {
        Pair<Integer, String> old = g.get(food);
        int oldRating = old.getKey();
        String cuisine = old.getValue();
        g.put(food, new Pair<>(newRating, cuisine));
        d.get(cuisine).remove(new Pair<>(oldRating, food));
        d.get(cuisine).add(new Pair<>(newRating, food));
    }

    public String highestRated(String cuisine) {
        return d.get(cuisine).first().getValue();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */
```

#### C++

```cpp
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            d[cuisine].insert({-rating, food});
            g[food] = {rating, cuisine};
        }
    }

    void changeRating(string food, int newRating) {
        auto [oldRating, cuisine] = g[food];
        g[food] = {newRating, cuisine};
        d[cuisine].erase({-oldRating, food});
        d[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return d[cuisine].begin()->second;
    }

private:
    unordered_map<string, set<pair<int, string>>> d;
    unordered_map<string, pair<int, string>> g;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
```

#### Go

```go
import (
	"github.com/emirpasic/gods/v2/trees/redblacktree"
)

type pair struct {
	rating int
	food   string
}

type FoodRatings struct {
	d map[string]*redblacktree.Tree[pair, struct{}]
	g map[string]pair
}

func Constructor(foods []string, cuisines []string, ratings []int) FoodRatings {
	d := make(map[string]*redblacktree.Tree[pair, struct{}])
	g := make(map[string]pair)

	for i, food := range foods {
		rating, cuisine := ratings[i], cuisines[i]
		g[food] = pair{rating, cuisine}

		if d[cuisine] == nil {
			d[cuisine] = redblacktree.NewWith[pair, struct{}](func(a, b pair) int {
				return cmp.Or(b.rating-a.rating, strings.Compare(a.food, b.food))
			})
		}
		d[cuisine].Put(pair{rating, food}, struct{}{})
	}

	return FoodRatings{d, g}
}

func (this *FoodRatings) ChangeRating(food string, newRating int) {
	p := this.g[food]
	t := this.d[p.food]

	t.Remove(pair{p.rating, food})
	t.Put(pair{newRating, food}, struct{}{})

	p.rating = newRating
	this.g[food] = p
}

func (this *FoodRatings) HighestRated(cuisine string) string {
	return this.d[cuisine].Left().Key.food
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * obj := Constructor(foods, cuisines, ratings);
 * obj.ChangeRating(food,newRating);
 * param_2 := obj.HighestRated(cuisine);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2354. 优质数对的数目](https://leetcode.cn/problems/number-of-excellent-pairs){#2354}

{{< tabs "2354" >}}

{{% tab "python" %}}
```python
class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        s = set(nums)
        ans = 0
        cnt = Counter()
        for v in s:
            cnt[v.bit_count()] += 1
        for v in s:
            t = v.bit_count()
            for i, x in cnt.items():
                if t + i >= k:
                    ans += x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countExcellentPairs(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        long ans = 0;
        int[] cnt = new int[32];
        for (int v : s) {
            int t = Integer.bitCount(v);
            ++cnt[t];
        }
        for (int v : s) {
            int t = Integer.bitCount(v);
            for (int i = 0; i < 32; ++i) {
                if (t + i >= k) {
                    ans += cnt[i];
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
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> cnt(32);
        for (int v : s) ++cnt[__builtin_popcount(v)];
        long long ans = 0;
        for (int v : s) {
            int t = __builtin_popcount(v);
            for (int i = 0; i < 32; ++i) {
                if (t + i >= k) {
                    ans += cnt[i];
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
func countExcellentPairs(nums []int, k int) int64 {
	s := map[int]bool{}
	for _, v := range nums {
		s[v] = true
	}
	cnt := make([]int, 32)
	for v := range s {
		t := bits.OnesCount(uint(v))
		cnt[t]++
	}
	ans := 0
	for v := range s {
		t := bits.OnesCount(uint(v))
		for i, x := range cnt {
			if t+i >= k {
				ans += x
			}
		}
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

<p>给你一个下标从 <strong>0</strong> 开始的正整数数组 <code>nums</code> 和一个正整数 <code>k</code> 。</p>

<p>如果满足下述条件，则数对 <code>(num1, num2)</code> 是 <strong>优质数对</strong> ：</p>

<ul>
	<li><code>num1</code> 和 <code>num2</code> <strong>都</strong> 在数组 <code>nums</code> 中存在。</li>
	<li><code>num1 OR num2</code> 和 <code>num1 AND num2</code> 的二进制表示中值为 <strong>1</strong> 的位数之和大于等于 <code>k</code> ，其中 <code>OR</code> 是按位 <strong>或</strong> 操作，而 <code>AND</code> 是按位 <strong>与</strong> 操作。</li>
</ul>

<p>返回 <strong>不同</strong> 优质数对的数目。</p>

<p>如果&nbsp;<code>a != c</code> 或者 <code>b != d</code> ，则认为 <code>(a, b)</code> 和 <code>(c, d)</code> 是不同的两个数对。例如，<code>(1, 2)</code> 和 <code>(2, 1)</code> 不同。</p>

<p><strong>注意：</strong>如果 <code>num1</code> 在数组中至少出现 <strong>一次</strong> ，则满足 <code>num1 == num2</code> 的数对 <code>(num1, num2)</code> 也可以是优质数对。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1], k = 3
<strong>输出：</strong>5
<strong>解释：</strong>有如下几个优质数对：
- (3, 3)：(3 AND 3) 和 (3 OR 3) 的二进制表示都等于 (11) 。值为 1 的位数和等于 2 + 2 = 4 ，大于等于 k = 3 。
- (2, 3) 和 (3, 2)： (2 AND 3) 的二进制表示等于 (10) ，(2 OR 3) 的二进制表示等于 (11) 。值为 1 的位数和等于 1 + 2 = 3 。
- (1, 3) 和 (3, 1)： (1 AND 3) 的二进制表示等于 (01) ，(1 OR 3) 的二进制表示等于 (11) 。值为 1 的位数和等于 1 + 2 = 3 。
所以优质数对的数目是 5 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,1], k = 10
<strong>输出：</strong>0
<strong>解释：</strong>该数组中不存在优质数对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 60</code></li>
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
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        s = set(nums)
        ans = 0
        cnt = Counter()
        for v in s:
            cnt[v.bit_count()] += 1
        for v in s:
            t = v.bit_count()
            for i, x in cnt.items():
                if t + i >= k:
                    ans += x
        return ans
```

#### Java

```java
class Solution {
    public long countExcellentPairs(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        long ans = 0;
        int[] cnt = new int[32];
        for (int v : s) {
            int t = Integer.bitCount(v);
            ++cnt[t];
        }
        for (int v : s) {
            int t = Integer.bitCount(v);
            for (int i = 0; i < 32; ++i) {
                if (t + i >= k) {
                    ans += cnt[i];
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
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> cnt(32);
        for (int v : s) ++cnt[__builtin_popcount(v)];
        long long ans = 0;
        for (int v : s) {
            int t = __builtin_popcount(v);
            for (int i = 0; i < 32; ++i) {
                if (t + i >= k) {
                    ans += cnt[i];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countExcellentPairs(nums []int, k int) int64 {
	s := map[int]bool{}
	for _, v := range nums {
		s[v] = true
	}
	cnt := make([]int, 32)
	for v := range s {
		t := bits.OnesCount(uint(v))
		cnt[t]++
	}
	ans := 0
	for v := range s {
		t := bits.OnesCount(uint(v))
		for i, x := range cnt {
			if t+i >= k {
				ans += x
			}
		}
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2355. 你能拿走的最大图书数量 🔒](https://leetcode.cn/problems/maximum-number-of-books-you-can-take){#2355}

{{< tabs "2355" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBooks(self, books: List[int]) -> int:
        nums = [v - i for i, v in enumerate(books)]
        n = len(nums)
        left = [-1] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        ans = 0
        dp = [0] * n
        dp[0] = books[0]
        for i, v in enumerate(books):
            j = left[i]
            cnt = min(v, i - j)
            u = v - cnt + 1
            s = (u + v) * cnt // 2
            dp[i] = s + (0 if j == -1 else dp[j])
            ans = max(ans, dp[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumBooks(int[] books) {
        int n = books.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = books[i] - i;
        }
        int[] left = new int[n];
        Arrays.fill(left, -1);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        long ans = 0;
        long[] dp = new long[n];
        dp[0] = books[0];
        for (int i = 0; i < n; ++i) {
            int j = left[i];
            int v = books[i];
            int cnt = Math.min(v, i - j);
            int u = v - cnt + 1;
            long s = (long) (u + v) * cnt / 2;
            dp[i] = s + (j == -1 ? 0 : dp[j]);
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = books[i] - i;
        vector<int> left(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        vector<ll> dp(n);
        dp[0] = books[0];
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = books[i];
            int j = left[i];
            int cnt = min(v, i - j);
            int u = v - cnt + 1;
            ll s = 1ll * (u + v) * cnt / 2;
            dp[i] = s + (j == -1 ? 0 : dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBooks(books []int) int64 {
	n := len(books)
	nums := make([]int, n)
	left := make([]int, n)
	for i, v := range books {
		nums[i] = v - i
		left[i] = -1
	}
	stk := []int{}
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	dp := make([]int, n)
	dp[0] = books[0]
	ans := 0
	for i, v := range books {
		j := left[i]
		cnt := min(v, i-j)
		u := v - cnt + 1
		s := (u + v) * cnt / 2
		dp[i] = s
		if j != -1 {
			dp[i] += dp[j]
		}
		ans = max(ans, dp[i])
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

<p>给定一个长度为 <code>n</code> 的<b>&nbsp;下标从 0 开始&nbsp;</b>的整数数组 <code>books</code>，其中 <code>books[i]</code> 表示书架的第 <code>i</code> 个书架上的书的数量。</p>

<p>你要从书架&nbsp;<code>l</code> 到 <code>r</code> 的一个&nbsp;<strong>连续&nbsp;</strong>的部分中取书，其中 <code>0 &lt;= l &lt;= r &lt; n</code>。对于 <code>l &lt;= i &lt; r</code> 范围内的每个索引 <code>i</code>，你从书架 <code>i</code>&nbsp;取书的数量必须&nbsp;<strong>严格小于 </strong>你从书架 <code>i + 1</code> 取书的数量。</p>

<p>返回<em>你能从书架上拿走的书的&nbsp;<strong>最大&nbsp;</strong>数量。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> books = [8,5,2,7,9]
<strong>输出:</strong> 19
<strong>解释:</strong>
- 从书架 1 上取 1 本书。
- 从书架 2 上取 2 本书。
- 从书架 3 上取 7 本书
- 从书架 4 上取 9 本书
你已经拿了19本书，所以返回 19。
可以证明 19 本是你所能拿走的书的最大数量。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> books = [7,0,3,4,5]
<strong>输出:</strong> 12
<strong>解释:</strong>
- 从书架 2 上取 3 本书。
- 从书架 3 上取 4 本书。
- 从书架 4 上取 5 本书。
你已经拿了 12 本书，所以返回 12。
可以证明 12 本是你所能拿走的书的最大数量。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> books = [8,2,3,7,3,4,0,1,4,3]
<strong>输出:</strong> 13
<strong>解释:</strong>
- 从书架 0 上取 1 本书。
- 从书架 1 上取 2 本书。
- 从书架 2 上取 3 本书。
- 从书架 3 上取 7 本书。
你已经拿了 13 本书，所以返回 13。
可以证明 13 本是你所能拿走的书的最大数量。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= books[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈 + 动态规划

我们定义 $dp[i]$ 表示以 $books[i]$ 结尾时能取走的书的最大数量。

若从 $i$ 到 $0$ 可以取成一个公差为 $1$ 的等差数列，那么 $dp[i]$ 可以直接通过等差数列求和算出。

若从 $i$ 到 $0$ 不能取成一个公差为 $-1$ 的等差数列，即这个规律在某个 $j$ 处断掉了（$0 \le j \lt i$），那么一定有 $books[j] \lt books[i] - (i-j)$，也即 $books[j] - j \lt books[i] - i$，利用单调栈在新数组 $books[i] - i$ 的每个位置，找到左边第一个比它严格小的数的位置，可以求出符合题意的 $j$，此时 $dp[i]=dp[j] + \sum_{k=j+1}^{i} (books[k]-k)$。

答案为 $\max_{i=0}^{n-1} dp[i]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBooks(self, books: List[int]) -> int:
        nums = [v - i for i, v in enumerate(books)]
        n = len(nums)
        left = [-1] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        ans = 0
        dp = [0] * n
        dp[0] = books[0]
        for i, v in enumerate(books):
            j = left[i]
            cnt = min(v, i - j)
            u = v - cnt + 1
            s = (u + v) * cnt // 2
            dp[i] = s + (0 if j == -1 else dp[j])
            ans = max(ans, dp[i])
        return ans
```

#### Java

```java
class Solution {
    public long maximumBooks(int[] books) {
        int n = books.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = books[i] - i;
        }
        int[] left = new int[n];
        Arrays.fill(left, -1);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        long ans = 0;
        long[] dp = new long[n];
        dp[0] = books[0];
        for (int i = 0; i < n; ++i) {
            int j = left[i];
            int v = books[i];
            int cnt = Math.min(v, i - j);
            int u = v - cnt + 1;
            long s = (long) (u + v) * cnt / 2;
            dp[i] = s + (j == -1 ? 0 : dp[j]);
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = books[i] - i;
        vector<int> left(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        vector<ll> dp(n);
        dp[0] = books[0];
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = books[i];
            int j = left[i];
            int cnt = min(v, i - j);
            int u = v - cnt + 1;
            ll s = 1ll * (u + v) * cnt / 2;
            dp[i] = s + (j == -1 ? 0 : dp[j]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumBooks(books []int) int64 {
	n := len(books)
	nums := make([]int, n)
	left := make([]int, n)
	for i, v := range books {
		nums[i] = v - i
		left[i] = -1
	}
	stk := []int{}
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	dp := make([]int, n)
	dp[0] = books[0]
	ans := 0
	for i, v := range books {
		j := left[i]
		cnt := min(v, i-j)
		u := v - cnt + 1
		s := (u + v) * cnt / 2
		dp[i] = s
		if j != -1 {
			dp[i] += dp[j]
		}
		ans = max(ans, dp[i])
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2356. 每位教师所教授的科目种类的数量](https://leetcode.cn/problems/number-of-unique-subjects-taught-by-each-teacher){#2356}

{{< tabs "2356" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Teacher</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| teacher_id  | int  |
| subject_id  | int  |
| dept_id     | int  |
+-------------+------+
在 SQL 中，(subject_id, dept_id) 是该表的主键。
该表中的每一行都表示带有 teacher_id 的教师在系 dept_id 中教授科目 subject_id。
</pre>

<p>&nbsp;</p>

<p>查询每位老师在大学里教授的科目种类的数量。</p>

<p data-group="1-1">以 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Teacher 表:
+------------+------------+---------+
| teacher_id | subject_id | dept_id |
+------------+------------+---------+
| 1          | 2          | 3       |
| 1          | 2          | 4       |
| 1          | 3          | 3       |
| 2          | 1          | 1       |
| 2          | 2          | 1       |
| 2          | 3          | 1       |
| 2          | 4          | 1       |
+------------+------------+---------+
<strong>输出:</strong>  
+------------+-----+
| teacher_id | cnt |
+------------+-----+
| 1          | 2   |
| 2          | 4   |
+------------+-----+
<strong>解释:</strong> 
教师 1:
  - 他在 3、4 系教科目 2。
  - 他在 3 系教科目 3。
教师 2:
  - 他在 1 系教科目 1。
  - 他在 1 系教科目 2。
  - 他在 1 系教科目 3。
  - 他在 1 系教科目 4。</pre>

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
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2357. 使数组中所有元素都等于零](https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts){#2357}

{{< tabs "2357" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        return len({x for x in nums if x})
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperations(int[] nums) {
        boolean[] s = new boolean[101];
        s[0] = true;
        int ans = 0;
        for (int x : nums) {
            if (!s[x]) {
                ++ans;
                s[x] = true;
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
    int minimumOperations(vector<int>& nums) {
        bool s[101]{};
        s[0] = true;
        int ans = 0;
        for (int& x : nums) {
            if (!s[x]) {
                ++ans;
                s[x] = true;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int) (ans int) {
	s := [101]bool{true}
	for _, x := range nums {
		if !s[x] {
			s[x] = true
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(nums: number[]): number {
    const s = new Set(nums);
    s.delete(0);
    return s.size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut s = nums.iter().collect::<HashSet<&i32>>();
        s.remove(&0);
        s.len() as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minimumOperations(int* nums, int numsSize) {
    int vis[101] = {0};
    vis[0] = 1;
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (vis[nums[i]]) {
            continue;
        }
        vis[nums[i]] = 1;
        ans++;
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

<p>给你一个非负整数数组 <code>nums</code> 。在一步操作中，你必须：</p>

<ul>
	<li>选出一个正整数 <code>x</code> ，<code>x</code> 需要小于或等于 <code>nums</code> 中 <strong>最小</strong> 的 <strong>非零</strong> 元素。</li>
	<li><code>nums</code> 中的每个正整数都减去 <code>x</code>。</li>
</ul>

<p>返回使 <code>nums</code> 中所有元素都等于<em> </em><code>0</code> 需要的 <strong>最少</strong> 操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,0,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>
第一步操作：选出 x = 1 ，之后 nums = [0,4,0,2,4] 。
第二步操作：选出 x = 2 ，之后 nums = [0,2,0,0,2] 。
第三步操作：选出 x = 2 ，之后 nums = [0,0,0,0,0] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>0
<strong>解释：</strong>nums 中的每个元素都已经是 0 ，所以不需要执行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们观察到，每一次操作，都可以把数组 $\textit{nums}$ 中相同且非零的元素减少到 $0$，因此，我们只需要统计数组 $\textit{nums}$ 中有多少个不同的非零元素，即为最少操作数。统计不同的非零元素，可以使用哈希表或数组来实现。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        return len({x for x in nums if x})
```

#### Java

```java
class Solution {
    public int minimumOperations(int[] nums) {
        boolean[] s = new boolean[101];
        s[0] = true;
        int ans = 0;
        for (int x : nums) {
            if (!s[x]) {
                ++ans;
                s[x] = true;
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
    int minimumOperations(vector<int>& nums) {
        bool s[101]{};
        s[0] = true;
        int ans = 0;
        for (int& x : nums) {
            if (!s[x]) {
                ++ans;
                s[x] = true;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumOperations(nums []int) (ans int) {
	s := [101]bool{true}
	for _, x := range nums {
		if !s[x] {
			s[x] = true
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumOperations(nums: number[]): number {
    const s = new Set(nums);
    s.delete(0);
    return s.size;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut s = nums.iter().collect::<HashSet<&i32>>();
        s.remove(&0);
        s.len() as i32
    }
}
```

#### C

```c
int minimumOperations(int* nums, int numsSize) {
    int vis[101] = {0};
    vis[0] = 1;
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (vis[nums[i]]) {
            continue;
        }
        vis[nums[i]] = 1;
        ans++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2358. 分组的最大数量](https://leetcode.cn/problems/maximum-number-of-groups-entering-a-competition){#2358}

{{< tabs "2358" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        n = len(grades)
        return bisect_right(range(n + 1), n * 2, key=lambda x: x * x + x) - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumGroups(int[] grades) {
        int n = grades.length;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (1L * mid * mid + mid > n * 2L) {
                r = mid - 1;
            } else {
                l = mid;
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
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (1LL * mid * mid + mid > n * 2LL) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumGroups(grades []int) int {
	n := len(grades)
	return sort.Search(n, func(k int) bool {
		k++
		return k*k+k > n*2
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumGroups(grades: number[]): number {
    const n = grades.length;
    let l = 1;
    let r = n;
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (mid * mid + mid > n * 2) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_groups(grades: Vec<i32>) -> i32 {
        let n = grades.len() as i64;
        let (mut l, mut r) = (0i64, n);
        while l < r {
            let mid = (l + r + 1) / 2;
            if mid * mid + mid > 2 * n {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        l as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>grades</code> ，表示大学中一些学生的成绩。你打算将 <strong>所有</strong> 学生分为一些 <strong>有序</strong> 的非空分组，其中分组间的顺序满足以下全部条件：</p>

<ul>
	<li>第 <code>i</code> 个分组中的学生总成绩 <strong>小于</strong> 第 <code>(i + 1)</code> 个分组中的学生总成绩，对所有组均成立（除了最后一组）。</li>
	<li>第 <code>i</code> 个分组中的学生总数 <strong>小于</strong> 第 <code>(i + 1)</code> 个分组中的学生总数，对所有组均成立（除了最后一组）。</li>
</ul>

<p>返回可以形成的 <strong>最大</strong> 组数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>grades = [10,6,12,7,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>下面是形成 3 个分组的一种可行方法：
- 第 1 个分组的学生成绩为 grades = [12] ，总成绩：12 ，学生数：1
- 第 2 个分组的学生成绩为 grades = [6,7] ，总成绩：6 + 7 = 13 ，学生数：2
- 第 3 个分组的学生成绩为 grades = [10,3,5] ，总成绩：10 + 3 + 5 = 18 ，学生数：3 
可以证明无法形成超过 3 个分组。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grades = [8,8]
<strong>输出：</strong>1
<strong>解释：</strong>只能形成 1 个分组，因为如果要形成 2 个分组的话，会导致每个分组中的学生数目相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grades.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grades[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

我们观察题目中的条件，第 $i$ 组的学生人数要小于第 $i+1$ 组的学生人数，且第 $i$ 组的学生总成绩要小于第 $i+1$ 组的学生总成绩，我们只需要将学生按照成绩从小到大排序，然后每一组依次分配 $1$, $2$, ..., $k$ 个学生即可。如果最后一组的学生人数不足 $k$ 个，那么我们可以将这些学生分配到前面的最后一组中。

因此，我们要找到最大的 $k$，使得 $\frac{(1 + k) \times k}{2} \leq n$，其中 $n$ 为学生的总人数。我们可以使用二分查找来求解。

我们定义二分查找的左边界为 $l = 1$，右边界为 $r = n$，每一次二分查找的中点为 $mid = \lfloor \frac{l + r + 1}{2} \rfloor$，如果 $(1 + mid) \times mid \gt 2 \times n$，则说明 $mid$ 太大，我们需要将右边界缩小至 $mid - 1$，否则我们需要将左边界增大至 $mid$。

最后，我们将 $l$ 作为答案返回即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为学生的总人数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        n = len(grades)
        return bisect_right(range(n + 1), n * 2, key=lambda x: x * x + x) - 1
```

#### Java

```java
class Solution {
    public int maximumGroups(int[] grades) {
        int n = grades.length;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (1L * mid * mid + mid > n * 2L) {
                r = mid - 1;
            } else {
                l = mid;
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
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (1LL * mid * mid + mid > n * 2LL) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maximumGroups(grades []int) int {
	n := len(grades)
	return sort.Search(n, func(k int) bool {
		k++
		return k*k+k > n*2
	})
}
```

#### TypeScript

```ts
function maximumGroups(grades: number[]): number {
    const n = grades.length;
    let l = 1;
    let r = n;
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (mid * mid + mid > n * 2) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_groups(grades: Vec<i32>) -> i32 {
        let n = grades.len() as i64;
        let (mut l, mut r) = (0i64, n);
        while l < r {
            let mid = (l + r + 1) / 2;
            if mid * mid + mid > 2 * n {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        l as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2359. 找到离给定两个节点最近的节点](https://leetcode.cn/problems/find-closest-node-to-given-two-nodes){#2359}

{{< tabs "2359" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def f(i):
            dist = [inf] * n
            dist[i] = 0
            q = deque([i])
            while q:
                i = q.popleft()
                for j in g[i]:
                    if dist[j] == inf:
                        dist[j] = dist[i] + 1
                        q.append(j)
            return dist

        g = defaultdict(list)
        for i, j in enumerate(edges):
            if j != -1:
                g[i].append(j)
        n = len(edges)
        d1 = f(node1)
        d2 = f(node2)
        ans, d = -1, inf
        for i, (a, b) in enumerate(zip(d1, d2)):
            if (t := max(a, b)) < d:
                d = t
                ans = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private List<Integer>[] g;

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        n = edges.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g[i].add(edges[i]);
            }
        }
        int[] d1 = f(node1);
        int[] d2 = f(node2);
        int d = 1 << 30;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int t = Math.max(d1[i], d2[i]);
            if (t < d) {
                d = t;
                ans = i;
            }
        }
        return ans;
    }

    private int[] f(int i) {
        int[] dist = new int[n];
        Arrays.fill(dist, 1 << 30);
        dist[i] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(i);
        while (!q.isEmpty()) {
            i = q.poll();
            for (int j : g[i]) {
                if (dist[j] == 1 << 30) {
                    dist[j] = dist[i] + 1;
                    q.offer(j);
                }
            }
        }
        return dist;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
            }
        }
        const int inf = 1 << 30;
        using pii = pair<int, int>;
        auto f = [&](int i) {
            vector<int> dist(n, inf);
            dist[i] = 0;
            queue<int> q{{i}};
            while (!q.empty()) {
                i = q.front();
                q.pop();
                for (int j : g[i]) {
                    if (dist[j] == inf) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
            }
            return dist;
        };
        vector<int> d1 = f(node1);
        vector<int> d2 = f(node2);
        int ans = -1, d = inf;
        for (int i = 0; i < n; ++i) {
            int t = max(d1[i], d2[i]);
            if (t < d) {
                d = t;
                ans = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closestMeetingNode(edges []int, node1 int, node2 int) int {
	n := len(edges)
	g := make([][]int, n)
	for i, j := range edges {
		if j != -1 {
			g[i] = append(g[i], j)
		}
	}
	const inf int = 1 << 30
	f := func(i int) []int {
		dist := make([]int, n)
		for j := range dist {
			dist[j] = inf
		}
		dist[i] = 0
		q := []int{i}
		for len(q) > 0 {
			i = q[0]
			q = q[1:]
			for _, j := range g[i] {
				if dist[j] == inf {
					dist[j] = dist[i] + 1
					q = append(q, j)
				}
			}
		}
		return dist
	}
	d1 := f(node1)
	d2 := f(node2)
	ans, d := -1, inf
	for i, a := range d1 {
		b := d2[i]
		t := max(a, b)
		if t < d {
			d = t
			ans = i
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function closestMeetingNode(edges: number[], node1: number, node2: number): number {
    const n = edges.length;
    const g = Array.from({ length: n }, () => []);
    for (let i = 0; i < n; ++i) {
        if (edges[i] != -1) {
            g[i].push(edges[i]);
        }
    }
    const inf = 1 << 30;
    const f = (i: number) => {
        const dist = new Array(n).fill(inf);
        dist[i] = 0;
        const q: number[] = [i];
        while (q.length) {
            i = q.shift();
            for (const j of g[i]) {
                if (dist[j] == inf) {
                    dist[j] = dist[i] + 1;
                    q.push(j);
                }
            }
        }
        return dist;
    };
    const d1 = f(node1);
    const d2 = f(node2);
    let ans = -1;
    let d = inf;
    for (let i = 0; i < n; ++i) {
        const t = Math.max(d1[i], d2[i]);
        if (t < d) {
            d = t;
            ans = i;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
        let n = edges.len();
        let mut g = vec![Vec::new(); n];
        for i in 0..n {
            if edges[i] != -1 {
                g[i].push(edges[i] as usize);
            }
        }
        let inf = 1 << 30;
        let f = |mut i: usize| -> Vec<i32> {
            let mut dist = vec![inf; n];
            dist[i] = 0;
            let mut q = VecDeque::new();
            q.push_back(i);
            while !q.is_empty() {
                i = q.pop_front().unwrap();
                for &j in &g[i] {
                    if dist[j] == inf {
                        dist[j] = dist[i] + 1;
                        q.push_back(j);
                    }
                }
            }
            dist
        };
        let d1 = f(node1 as usize);
        let d2 = f(node2 as usize);
        let mut ans = -1;
        let mut d = inf;
        for i in 0..n {
            let t = std::cmp::max(d1[i], d2[i]);
            if t < d {
                d = t;
                ans = i as i32;
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
    public int ClosestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.Length;
        List<int>[] g = new List<int>[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new List<int>();
            if (edges[i] != -1) {
                g[i].Add(edges[i]);
            }
        }
        int inf = 1 << 30;
        int[] f(int i) {
            int[] dist = new int[n];
            Array.Fill(dist, inf);
            dist[i] = 0;
            Queue<int> q = new Queue<int>();
            q.Enqueue(i);
            while (q.Count > 0) {
                i = q.Dequeue();
                foreach (int j in g[i]) {
                    if (dist[j] == inf) {
                        dist[j] = dist[i] + 1;
                        q.Enqueue(j);
                    }
                }
            }
            return dist;
        }
        int[] d1 = f(node1);
        int[] d2 = f(node2);
        int ans = -1, d = inf;
        for (int i = 0; i < n; ++i) {
            int t = Math.Max(d1[i], d2[i]);
            if (t < d) {
                d = t;
                ans = i;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func closestMeetingNode(_ edges: [Int], _ node1: Int, _ node2: Int) -> Int {
        let n = edges.count
        var g = [[Int]](repeating: [], count: n)
        for i in 0..<n {
            if edges[i] != -1 {
                g[i].append(edges[i])
            }
        }
        let inf = 1 << 30

        func f(_ i: Int) -> [Int] {
            var dist = [Int](repeating: inf, count: n)
            dist[i] = 0
            var q = [i]
            var idx = 0
            while idx < q.count {
                let i = q[idx]
                idx += 1
                for j in g[i] {
                    if dist[j] == inf {
                        dist[j] = dist[i] + 1
                        q.append(j)
                    }
                }
            }
            return dist
        }

        let d1 = f(node1)
        let d2 = f(node2)
        var ans = -1, d = inf
        for i in 0..<n {
            let t = max(d1[i], d2[i])
            if t < d {
                d = t
                ans = i
            }
        }
        return ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code>&nbsp;个节点的 <strong>有向图</strong>&nbsp;，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，每个节点 <strong>至多</strong>&nbsp;有一条出边。</p>

<p>有向图用大小为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>edges</code>&nbsp;表示，表示节点&nbsp;<code>i</code>&nbsp;有一条有向边指向&nbsp;<code>edges[i]</code>&nbsp;。如果节点&nbsp;<code>i</code>&nbsp;没有出边，那么&nbsp;<code>edges[i] == -1</code>&nbsp;。</p>

<p>同时给你两个节点&nbsp;<code>node1</code> 和&nbsp;<code>node2</code>&nbsp;。</p>

<p>请你返回一个从 <code>node1</code>&nbsp;和 <code>node2</code>&nbsp;都能到达节点的编号，使节点 <code>node1</code>&nbsp;和节点 <code>node2</code>&nbsp;到这个节点的距离 <b>较大值最小化</b>。如果有多个答案，请返回 <strong>最小</strong>&nbsp;的节点编号。如果答案不存在，返回 <code>-1</code>&nbsp;。</p>

<p>注意&nbsp;<code>edges</code>&nbsp;可能包含环。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2359.Find%20Closest%20Node%20to%20Given%20Two%20Nodes/images/graph4drawio-2.png" style="width: 321px; height: 161px;"></p>

<pre><b>输入：</b>edges = [2,2,3,-1], node1 = 0, node2 = 1
<b>输出：</b>2
<b>解释：</b>从节点 0 到节点 2 的距离为 1 ，从节点 1 到节点 2 的距离为 1 。
两个距离的较大值为 1 。我们无法得到一个比 1 更小的较大值，所以我们返回节点 2 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2359.Find%20Closest%20Node%20to%20Given%20Two%20Nodes/images/graph4drawio-4.png" style="width: 195px; height: 161px;"></p>

<pre><b>输入：</b>edges = [1,2,-1], node1 = 0, node2 = 2
<b>输出：</b>2
<b>解释：</b>节点 0 到节点 2 的距离为 2 ，节点 2 到它自己的距离为 0 。
两个距离的较大值为 2 。我们无法得到一个比 2 更小的较大值，所以我们返回节点 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
	<li><code>0 &lt;= node1, node2 &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 枚举公共点

我们可以先用 BFS 求出从 $node1$ 和 $node2$ 分别到达每个点的距离，分别记为 $d_1$ 和 $d_2$。然后枚举所有的公共点 $i$，然后求出 $\max(d_1[i], d_2[i])$，取其中的最小值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点个数。

相似题目：

-   [2203.得到要求路径的最小带权子图](https://github.com/doocs/leetcode/blob/main/solution/2200-2299/2203.Minimum%20Weighted%20Subgraph%20With%20the%20Required%20Paths/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def f(i):
            dist = [inf] * n
            dist[i] = 0
            q = deque([i])
            while q:
                i = q.popleft()
                for j in g[i]:
                    if dist[j] == inf:
                        dist[j] = dist[i] + 1
                        q.append(j)
            return dist

        g = defaultdict(list)
        for i, j in enumerate(edges):
            if j != -1:
                g[i].append(j)
        n = len(edges)
        d1 = f(node1)
        d2 = f(node2)
        ans, d = -1, inf
        for i, (a, b) in enumerate(zip(d1, d2)):
            if (t := max(a, b)) < d:
                d = t
                ans = i
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private List<Integer>[] g;

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        n = edges.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g[i].add(edges[i]);
            }
        }
        int[] d1 = f(node1);
        int[] d2 = f(node2);
        int d = 1 << 30;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int t = Math.max(d1[i], d2[i]);
            if (t < d) {
                d = t;
                ans = i;
            }
        }
        return ans;
    }

    private int[] f(int i) {
        int[] dist = new int[n];
        Arrays.fill(dist, 1 << 30);
        dist[i] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(i);
        while (!q.isEmpty()) {
            i = q.poll();
            for (int j : g[i]) {
                if (dist[j] == 1 << 30) {
                    dist[j] = dist[i] + 1;
                    q.offer(j);
                }
            }
        }
        return dist;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
            }
        }
        const int inf = 1 << 30;
        using pii = pair<int, int>;
        auto f = [&](int i) {
            vector<int> dist(n, inf);
            dist[i] = 0;
            queue<int> q{{i}};
            while (!q.empty()) {
                i = q.front();
                q.pop();
                for (int j : g[i]) {
                    if (dist[j] == inf) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
            }
            return dist;
        };
        vector<int> d1 = f(node1);
        vector<int> d2 = f(node2);
        int ans = -1, d = inf;
        for (int i = 0; i < n; ++i) {
            int t = max(d1[i], d2[i]);
            if (t < d) {
                d = t;
                ans = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func closestMeetingNode(edges []int, node1 int, node2 int) int {
	n := len(edges)
	g := make([][]int, n)
	for i, j := range edges {
		if j != -1 {
			g[i] = append(g[i], j)
		}
	}
	const inf int = 1 << 30
	f := func(i int) []int {
		dist := make([]int, n)
		for j := range dist {
			dist[j] = inf
		}
		dist[i] = 0
		q := []int{i}
		for len(q) > 0 {
			i = q[0]
			q = q[1:]
			for _, j := range g[i] {
				if dist[j] == inf {
					dist[j] = dist[i] + 1
					q = append(q, j)
				}
			}
		}
		return dist
	}
	d1 := f(node1)
	d2 := f(node2)
	ans, d := -1, inf
	for i, a := range d1 {
		b := d2[i]
		t := max(a, b)
		if t < d {
			d = t
			ans = i
		}
	}
	return ans
}
```

#### TypeScript

```ts
function closestMeetingNode(edges: number[], node1: number, node2: number): number {
    const n = edges.length;
    const g = Array.from({ length: n }, () => []);
    for (let i = 0; i < n; ++i) {
        if (edges[i] != -1) {
            g[i].push(edges[i]);
        }
    }
    const inf = 1 << 30;
    const f = (i: number) => {
        const dist = new Array(n).fill(inf);
        dist[i] = 0;
        const q: number[] = [i];
        while (q.length) {
            i = q.shift();
            for (const j of g[i]) {
                if (dist[j] == inf) {
                    dist[j] = dist[i] + 1;
                    q.push(j);
                }
            }
        }
        return dist;
    };
    const d1 = f(node1);
    const d2 = f(node2);
    let ans = -1;
    let d = inf;
    for (let i = 0; i < n; ++i) {
        const t = Math.max(d1[i], d2[i]);
        if (t < d) {
            d = t;
            ans = i;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
        let n = edges.len();
        let mut g = vec![Vec::new(); n];
        for i in 0..n {
            if edges[i] != -1 {
                g[i].push(edges[i] as usize);
            }
        }
        let inf = 1 << 30;
        let f = |mut i: usize| -> Vec<i32> {
            let mut dist = vec![inf; n];
            dist[i] = 0;
            let mut q = VecDeque::new();
            q.push_back(i);
            while !q.is_empty() {
                i = q.pop_front().unwrap();
                for &j in &g[i] {
                    if dist[j] == inf {
                        dist[j] = dist[i] + 1;
                        q.push_back(j);
                    }
                }
            }
            dist
        };
        let d1 = f(node1 as usize);
        let d2 = f(node2 as usize);
        let mut ans = -1;
        let mut d = inf;
        for i in 0..n {
            let t = std::cmp::max(d1[i], d2[i]);
            if t < d {
                d = t;
                ans = i as i32;
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int ClosestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.Length;
        List<int>[] g = new List<int>[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new List<int>();
            if (edges[i] != -1) {
                g[i].Add(edges[i]);
            }
        }
        int inf = 1 << 30;
        int[] f(int i) {
            int[] dist = new int[n];
            Array.Fill(dist, inf);
            dist[i] = 0;
            Queue<int> q = new Queue<int>();
            q.Enqueue(i);
            while (q.Count > 0) {
                i = q.Dequeue();
                foreach (int j in g[i]) {
                    if (dist[j] == inf) {
                        dist[j] = dist[i] + 1;
                        q.Enqueue(j);
                    }
                }
            }
            return dist;
        }
        int[] d1 = f(node1);
        int[] d2 = f(node2);
        int ans = -1, d = inf;
        for (int i = 0; i < n; ++i) {
            int t = Math.Max(d1[i], d2[i]);
            if (t < d) {
                d = t;
                ans = i;
            }
        }
        return ans;
    }
}
```

#### Swift

```swift
class Solution {
    func closestMeetingNode(_ edges: [Int], _ node1: Int, _ node2: Int) -> Int {
        let n = edges.count
        var g = [[Int]](repeating: [], count: n)
        for i in 0..<n {
            if edges[i] != -1 {
                g[i].append(edges[i])
            }
        }
        let inf = 1 << 30

        func f(_ i: Int) -> [Int] {
            var dist = [Int](repeating: inf, count: n)
            dist[i] = 0
            var q = [i]
            var idx = 0
            while idx < q.count {
                let i = q[idx]
                idx += 1
                for j in g[i] {
                    if dist[j] == inf {
                        dist[j] = dist[i] + 1
                        q.append(j)
                    }
                }
            }
            return dist
        }

        let d1 = f(node1)
        let d2 = f(node2)
        var ans = -1, d = inf
        for i in 0..<n {
            let t = max(d1[i], d2[i])
            if t < d {
                d = t
                ans = i
            }
        }
        return ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
