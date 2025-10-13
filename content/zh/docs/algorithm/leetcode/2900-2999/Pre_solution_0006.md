---
title: "2950_可整除子串的数量 🔒"
date: 2025-10-08T18:39:48+08:00
weight: 6
tags: [位运算, 前缀和, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 排序, 数学, 数组, 最短路, 枚举, 滑动窗口, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [2950_可整除子串的数量 🔒](#2950)
#### [哈希表](#2950)
#### [字符串](#2950)
#### [计数](#2950)
#### [前缀和](#2950)
### [2951_找出峰值](#2951)
#### [数组](#2951)
#### [枚举](#2951)
### [2952_需要添加的硬币的最小数量](#2952)
#### [贪心](#2952)
#### [数组](#2952)
#### [排序](#2952)
### [2953_统计完全子字符串](#2953)
#### [哈希表](#2953)
#### [字符串](#2953)
#### [滑动窗口](#2953)
### [2954_统计感冒序列的数目](#2954)
#### [数组](#2954)
#### [数学](#2954)
#### [组合数学](#2954)
### [2955_同端子串的数量 🔒](#2955)
#### [数组](#2955)
#### [哈希表](#2955)
#### [字符串](#2955)
#### [计数](#2955)
#### [前缀和](#2955)
### [2956_找到两个数组中的公共元素](#2956)
#### [数组](#2956)
#### [哈希表](#2956)
### [2957_消除相邻近似相等字符](#2957)
#### [贪心](#2957)
#### [字符串](#2957)
#### [动态规划](#2957)
### [2958_最多 K 个重复元素的最长子数组](#2958)
#### [数组](#2958)
#### [哈希表](#2958)
#### [滑动窗口](#2958)
### [2959_关闭分部的可行集合数目](#2959)
#### [位运算](#2959)
#### [图](#2959)
#### [枚举](#2959)
#### [最短路](#2959)
#### [堆（优先队列）](#2959)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2950_可整除子串的数量 🔒
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 前缀和
---
### 2951_找出峰值
___
#### 数组
___
#### 枚举
---
### 2952_需要添加的硬币的最小数量
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2953_统计完全子字符串
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 2954_统计感冒序列的数目
___
#### 数组
___
#### 数学
___
#### 组合数学
---
### 2955_同端子串的数量 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 前缀和
---
### 2956_找到两个数组中的公共元素
___
#### 数组
___
#### 哈希表
---
### 2957_消除相邻近似相等字符
___
#### 贪心
___
#### 字符串
___
#### 动态规划
---
### 2958_最多 K 个重复元素的最长子数组
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2959_关闭分部的可行集合数目
___
#### 位运算
___
#### 图
___
#### 枚举
___
#### 最短路
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数组 | 最短路 | 枚举 |
| 滑动窗口 | 组合数学 | 计数 |
| 贪心 |  |  |

# [2950. 可整除子串的数量 🔒](https://leetcode.cn/problems/number-of-divisible-substrings){#2950}

{{< tabs "2950" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDivisibleSubstrings(self, word: str) -> int:
        d = ["ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"]
        mp = {}
        for i, s in enumerate(d, 1):
            for c in s:
                mp[c] = i
        ans = 0
        for i in range(1, 10):
            cnt = defaultdict(int)
            cnt[0] = 1
            s = 0
            for c in word:
                s += mp[c] - i
                ans += cnt[s]
                cnt[s] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDivisibleSubstrings(String word) {
        String[] d = {"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"};
        int[] mp = new int[26];
        for (int i = 0; i < d.length; ++i) {
            for (char c : d[i].toCharArray()) {
                mp[c - 'a'] = i + 1;
            }
        }
        int ans = 0;
        char[] cs = word.toCharArray();
        for (int i = 1; i < 10; ++i) {
            Map<Integer, Integer> cnt = new HashMap<>();
            cnt.put(0, 1);
            int s = 0;
            for (char c : cs) {
                s += mp[c - 'a'] - i;
                ans += cnt.getOrDefault(s, 0);
                cnt.merge(s, 1, Integer::sum);
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
    int countDivisibleSubstrings(string word) {
        string d[9] = {"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"};
        int mp[26]{};
        for (int i = 0; i < 9; ++i) {
            for (char& c : d[i]) {
                mp[c - 'a'] = i + 1;
            }
        }
        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            unordered_map<int, int> cnt{{0, 1}};
            int s = 0;
            for (char& c : word) {
                s += mp[c - 'a'] - i;
                ans += cnt[s]++;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDivisibleSubstrings(word string) (ans int) {
	d := []string{"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"}
	mp := [26]int{}
	for i, s := range d {
		for _, c := range s {
			mp[c-'a'] = i + 1
		}
	}
	for i := 0; i < 10; i++ {
		cnt := map[int]int{0: 1}
		s := 0
		for _, c := range word {
			s += mp[c-'a'] - i
			ans += cnt[s]
			cnt[s]++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countDivisibleSubstrings(word: string): number {
    const d = ['ab', 'cde', 'fgh', 'ijk', 'lmn', 'opq', 'rst', 'uvw', 'xyz'];
    const mp: number[] = Array(26).fill(0);

    d.forEach((s, i) => {
        for (const c of s) {
            mp[c.charCodeAt(0) - 'a'.charCodeAt(0)] = i + 1;
        }
    });

    let ans = 0;
    for (let i = 0; i < 10; i++) {
        const cnt: { [key: number]: number } = { 0: 1 };
        let s = 0;
        for (const c of word) {
            s += mp[c.charCodeAt(0) - 'a'.charCodeAt(0)] - i;
            ans += cnt[s] || 0;
            cnt[s] = (cnt[s] || 0) + 1;
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
    pub fn count_divisible_substrings(word: String) -> i32 {
        let d = vec!["ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"];
        let mut mp: Vec<usize> = vec![0; 26];
        for (i, s) in d.iter().enumerate() {
            for c in s.chars() {
                mp[(c as usize) - ('a' as usize)] = i + 1;
            }
        }
        let mut ans = 0;
        for i in 0..10 {
            let mut cnt: HashMap<i32, i32> = HashMap::new();
            cnt.insert(0, 1);
            let mut s = 0;
            for c in word.chars() {
                s += (mp[(c as usize) - ('a' as usize)] - i) as i32;
                ans += cnt.get(&s).cloned().unwrap_or(0);
                *cnt.entry(s).or_insert(0) += 1;
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

<p>每个英文字母都被映射到一个数字，如下所示。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2950.Number%20of%20Divisible%20Substrings/images/old_phone_digits.png" style="padding: 10px; width: 200px; height: 200px;" /></p>

<p>如果字符串的字符的映射值的总和可以被字符串的长度整除，则该字符串是 <strong>可整除</strong> 的。</p>

<p>给定一个字符串 <code>s</code>，请返回 <code>s</code> 的<em> <strong>可整除子串</strong> 的数量</em>。</p>

<p><strong>子串</strong> 是字符串内的一个连续的非空字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<th style="padding: 5px; border: 1px solid black;">Substring</th>
			<th style="padding: 5px; border: 1px solid black;">Mapped</th>
			<th style="padding: 5px; border: 1px solid black;">Sum</th>
			<th style="padding: 5px; border: 1px solid black;">Length</th>
			<th style="padding: 5px; border: 1px solid black;">Divisible?</th>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">a</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">Yes</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">s</td>
			<td style="padding: 5px; border: 1px solid black;">7</td>
			<td style="padding: 5px; border: 1px solid black;">7</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">Yes</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">d</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">Yes</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">f</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">1</td>
			<td style="padding: 5px; border: 1px solid black;">Yes</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">as</td>
			<td style="padding: 5px; border: 1px solid black;">1, 7</td>
			<td style="padding: 5px; border: 1px solid black;">8</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">Yes</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">sd</td>
			<td style="padding: 5px; border: 1px solid black;">7, 2</td>
			<td style="padding: 5px; border: 1px solid black;">9</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">No</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">df</td>
			<td style="padding: 5px; border: 1px solid black;">2, 3</td>
			<td style="padding: 5px; border: 1px solid black;">5</td>
			<td style="padding: 5px; border: 1px solid black;">2</td>
			<td style="padding: 5px; border: 1px solid black;">No</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">asd</td>
			<td style="padding: 5px; border: 1px solid black;">1, 7, 2</td>
			<td style="padding: 5px; border: 1px solid black;">10</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">No</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">sdf</td>
			<td style="padding: 5px; border: 1px solid black;">7, 2, 3</td>
			<td style="padding: 5px; border: 1px solid black;">12</td>
			<td style="padding: 5px; border: 1px solid black;">3</td>
			<td style="padding: 5px; border: 1px solid black;">Yes</td>
		</tr>
		<tr>
			<td style="padding: 5px; border: 1px solid black;">asdf</td>
			<td style="padding: 5px; border: 1px solid black;">1, 7, 2, 3</td>
			<td style="padding: 5px; border: 1px solid black;">13</td>
			<td style="padding: 5px; border: 1px solid black;">4</td>
			<td style="padding: 5px; border: 1px solid black;">No</td>
		</tr>
	</tbody>
</table>

<pre>
<b>输入：</b>word = "asdf"
<b>输出：</b>6
<b>解释：</b>上表包含了有关 word 中每个子串的详细信息，我们可以看到其中有 6 个是可整除的。
</pre>

<p><b>示例 2:</b></p>

<pre>
<b>输入：</b>word = "bdh"
<b>输出：</b>4
<b>解释：</b>4 个可整除的子串是："b"，"d"，"h"，"bdh"。
可以证明 word 中没有其他可整除的子串。
</pre>

<p><b>示例 3:</b></p>

<pre>
<b>输入：</b>word = "abcd"
<b>输出：</b>6
<b>解释：</b>6 个可整除的子串是："a"，"b"，"c"，"d"，"ab"，"cd"。
可以证明 word 中没有其他可整除的子串。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2000</code></li>
	<li><code>word</code> 仅包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们先用一个哈希表或数组 $mp$ 记录每个字母对应的数字。

然后，我们枚举子串的起始位置 $i$，再枚举子串的结束位置 $j$，计算子串 $s[i..j]$ 的数字和 $s$，如果 $s$ 能被 $j-i+1$ 整除，那么就找到了一个可被整除的子串，将答案加一。

枚举结束后，返回答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(C)$。其中 $n$ 是字符串 $word$ 的长度，而 $C$ 是字符集的大小，本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDivisibleSubstrings(self, word: str) -> int:
        d = ["ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"]
        mp = {}
        for i, s in enumerate(d, 1):
            for c in s:
                mp[c] = i
        ans = 0
        n = len(word)
        for i in range(n):
            s = 0
            for j in range(i, n):
                s += mp[word[j]]
                ans += s % (j - i + 1) == 0
        return ans
```

#### Java

```java
class Solution {
    public int countDivisibleSubstrings(String word) {
        String[] d = {"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"};
        int[] mp = new int[26];
        for (int i = 0; i < d.length; ++i) {
            for (char c : d[i].toCharArray()) {
                mp[c - 'a'] = i + 1;
            }
        }
        int ans = 0;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += mp[word.charAt(j) - 'a'];
                ans += s % (j - i + 1) == 0 ? 1 : 0;
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
    int countDivisibleSubstrings(string word) {
        string d[9] = {"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"};
        int mp[26]{};
        for (int i = 0; i < 9; ++i) {
            for (char& c : d[i]) {
                mp[c - 'a'] = i + 1;
            }
        }
        int ans = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += mp[word[j] - 'a'];
                ans += s % (j - i + 1) == 0 ? 1 : 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countDivisibleSubstrings(word string) (ans int) {
	d := []string{"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"}
	mp := [26]int{}
	for i, s := range d {
		for _, c := range s {
			mp[c-'a'] = i + 1
		}
	}
	n := len(word)
	for i := 0; i < n; i++ {
		s := 0
		for j := i; j < n; j++ {
			s += mp[word[j]-'a']
			if s%(j-i+1) == 0 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countDivisibleSubstrings(word: string): number {
    const d: string[] = ['ab', 'cde', 'fgh', 'ijk', 'lmn', 'opq', 'rst', 'uvw', 'xyz'];
    const mp: number[] = Array(26).fill(0);
    for (let i = 0; i < d.length; ++i) {
        for (const c of d[i]) {
            mp[c.charCodeAt(0) - 'a'.charCodeAt(0)] = i + 1;
        }
    }
    const n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let s = 0;
        for (let j = i; j < n; ++j) {
            s += mp[word.charCodeAt(j) - 'a'.charCodeAt(0)];
            if (s % (j - i + 1) === 0) {
                ++ans;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_divisible_substrings(word: String) -> i32 {
        let d = vec!["ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"];
        let mut mp = vec![0; 26];

        for (i, s) in d.iter().enumerate() {
            s.chars().for_each(|c| {
                mp[(c as usize) - ('a' as usize)] = (i + 1) as i32;
            });
        }

        let mut ans = 0;
        let n = word.len();

        for i in 0..n {
            let mut s = 0;

            for j in i..n {
                s += mp[(word.as_bytes()[j] as usize) - ('a' as usize)];
                ans += (s % ((j - i + 1) as i32) == 0) as i32;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 前缀和 + 枚举

与方法一类似，我们先用一个哈希表或数组 $mp$ 记录每个字母对应的数字。

如果一个整数子数组的数字之和能被它的长度整除，那么这个子数组的平均值一定是一个整数。而由于子数组中每个元素的数字都在 $[1, 9]$ 范围内，因此子数组的平均值只能是 $1, 2, \cdots, 9$ 中的一个。

我们可以枚举子数组的平均值 $i$，如果一个子数组的元素和能被 $i$ 整除，假设子数组为 $a_1, a_2, \cdots, a_k$，那么 $a_1 + a_2 + \cdots + a_k = i \times k$，即 $(a_1 - i) + (a_2 - i) + \cdots + (a_k - i) = 0$。如果我们把 $a_k - i$ 视为一个新的元素 $b_k$，那么原来的子数组就变成了 $b_1, b_2, \cdots, b_k$，其中 $b_1 + b_2 + \cdots + b_k = 0$。我们只需要求出新的数组中，有多少个子数组的元素和为 $0$ 即可，这可以用“哈希表”结合“前缀和”来实现。

时间复杂度 $O(10 \times n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $word$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDivisibleSubstrings(self, word: str) -> int:
        d = ["ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"]
        mp = {}
        for i, s in enumerate(d, 1):
            for c in s:
                mp[c] = i
        ans = 0
        for i in range(1, 10):
            cnt = defaultdict(int)
            cnt[0] = 1
            s = 0
            for c in word:
                s += mp[c] - i
                ans += cnt[s]
                cnt[s] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countDivisibleSubstrings(String word) {
        String[] d = {"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"};
        int[] mp = new int[26];
        for (int i = 0; i < d.length; ++i) {
            for (char c : d[i].toCharArray()) {
                mp[c - 'a'] = i + 1;
            }
        }
        int ans = 0;
        char[] cs = word.toCharArray();
        for (int i = 1; i < 10; ++i) {
            Map<Integer, Integer> cnt = new HashMap<>();
            cnt.put(0, 1);
            int s = 0;
            for (char c : cs) {
                s += mp[c - 'a'] - i;
                ans += cnt.getOrDefault(s, 0);
                cnt.merge(s, 1, Integer::sum);
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
    int countDivisibleSubstrings(string word) {
        string d[9] = {"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"};
        int mp[26]{};
        for (int i = 0; i < 9; ++i) {
            for (char& c : d[i]) {
                mp[c - 'a'] = i + 1;
            }
        }
        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            unordered_map<int, int> cnt{{0, 1}};
            int s = 0;
            for (char& c : word) {
                s += mp[c - 'a'] - i;
                ans += cnt[s]++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countDivisibleSubstrings(word string) (ans int) {
	d := []string{"ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"}
	mp := [26]int{}
	for i, s := range d {
		for _, c := range s {
			mp[c-'a'] = i + 1
		}
	}
	for i := 0; i < 10; i++ {
		cnt := map[int]int{0: 1}
		s := 0
		for _, c := range word {
			s += mp[c-'a'] - i
			ans += cnt[s]
			cnt[s]++
		}
	}
	return
}
```

#### TypeScript

```ts
function countDivisibleSubstrings(word: string): number {
    const d = ['ab', 'cde', 'fgh', 'ijk', 'lmn', 'opq', 'rst', 'uvw', 'xyz'];
    const mp: number[] = Array(26).fill(0);

    d.forEach((s, i) => {
        for (const c of s) {
            mp[c.charCodeAt(0) - 'a'.charCodeAt(0)] = i + 1;
        }
    });

    let ans = 0;
    for (let i = 0; i < 10; i++) {
        const cnt: { [key: number]: number } = { 0: 1 };
        let s = 0;
        for (const c of word) {
            s += mp[c.charCodeAt(0) - 'a'.charCodeAt(0)] - i;
            ans += cnt[s] || 0;
            cnt[s] = (cnt[s] || 0) + 1;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_divisible_substrings(word: String) -> i32 {
        let d = vec!["ab", "cde", "fgh", "ijk", "lmn", "opq", "rst", "uvw", "xyz"];
        let mut mp: Vec<usize> = vec![0; 26];
        for (i, s) in d.iter().enumerate() {
            for c in s.chars() {
                mp[(c as usize) - ('a' as usize)] = i + 1;
            }
        }
        let mut ans = 0;
        for i in 0..10 {
            let mut cnt: HashMap<i32, i32> = HashMap::new();
            cnt.insert(0, 1);
            let mut s = 0;
            for c in word.chars() {
                s += (mp[(c as usize) - ('a' as usize)] - i) as i32;
                ans += cnt.get(&s).cloned().unwrap_or(0);
                *cnt.entry(s).or_insert(0) += 1;
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

# [2951. 找出峰值](https://leetcode.cn/problems/find-the-peaks){#2951}

{{< tabs "2951" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPeaks(self, mountain: List[int]) -> List[int]:
        return [
            i
            for i in range(1, len(mountain) - 1)
            if mountain[i - 1] < mountain[i] > mountain[i + 1]
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findPeaks(int[] mountain) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < mountain.length - 1; ++i) {
            if (mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]) {
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
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        for (int i = 1; i < mountain.size() - 1; ++i) {
            if (mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]) {
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
func findPeaks(mountain []int) (ans []int) {
	for i := 1; i < len(mountain)-1; i++ {
		if mountain[i-1] < mountain[i] && mountain[i+1] < mountain[i] {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPeaks(mountain: number[]): number[] {
    const ans: number[] = [];
    for (let i = 1; i < mountain.length - 1; ++i) {
        if (mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]) {
            ans.push(i);
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

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>mountain</code> 。你的任务是找出数组&nbsp;<code>mountain</code> 中的所有 <strong>峰值</strong>。</p>

<p>以数组形式返回给定数组中 <strong>峰值</strong> 的下标，<strong>顺序不限</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>峰值</strong> 是指一个严格大于其相邻元素的元素。</li>
	<li>数组的第一个和最后一个元素 <strong>不</strong> 是峰值。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>mountain = [2,4,4]
<strong>输出：</strong>[]
<strong>解释：</strong>mountain[0] 和 mountain[2] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
mountain[1] 也不可能是峰值，因为它不严格大于 mountain[2] 。
因此，答案为 [] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>mountain = [1,4,3,8,5]
<strong>输出：</strong>[1,3]
<strong>解释：</strong>mountain[0] 和 mountain[4] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
mountain[2] 也不可能是峰值，因为它不严格大于 mountain[3] 和 mountain[1] 。
但是 mountain[1] 和 mountain[3] 严格大于它们的相邻元素。
因此，答案是 [1,3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= mountain.length &lt;= 100</code></li>
	<li><code>1 &lt;= mountain[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们直接遍历下标 $i \in [1, n-2]$，对于每个下标 $i$，如果满足 $mountain[i-1] < mountain[i]$ 并且 $mountain[i + 1] < mountain[i]$，那么 $mountain[i]$ 就是一个峰值，我们将下标 $i$ 加入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPeaks(self, mountain: List[int]) -> List[int]:
        return [
            i
            for i in range(1, len(mountain) - 1)
            if mountain[i - 1] < mountain[i] > mountain[i + 1]
        ]
```

#### Java

```java
class Solution {
    public List<Integer> findPeaks(int[] mountain) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < mountain.length - 1; ++i) {
            if (mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]) {
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
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        for (int i = 1; i < mountain.size() - 1; ++i) {
            if (mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findPeaks(mountain []int) (ans []int) {
	for i := 1; i < len(mountain)-1; i++ {
		if mountain[i-1] < mountain[i] && mountain[i+1] < mountain[i] {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function findPeaks(mountain: number[]): number[] {
    const ans: number[] = [];
    for (let i = 1; i < mountain.length - 1; ++i) {
        if (mountain[i - 1] < mountain[i] && mountain[i + 1] < mountain[i]) {
            ans.push(i);
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

# [2952. 需要添加的硬币的最小数量](https://leetcode.cn/problems/minimum-number-of-coins-to-be-added){#2952}

{{< tabs "2952" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        s = 1
        ans = i = 0
        while s <= target:
            if i < len(coins) and coins[i] <= s:
                s += coins[i]
                i += 1
            else:
                s <<= 1
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumAddedCoins(int[] coins, int target) {
        Arrays.sort(coins);
        int ans = 0;
        for (int i = 0, s = 1; s <= target;) {
            if (i < coins.length && coins[i] <= s) {
                s += coins[i++];
            } else {
                s <<= 1;
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
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        for (int i = 0, s = 1; s <= target;) {
            if (i < coins.size() && coins[i] <= s) {
                s += coins[i++];
            } else {
                s <<= 1;
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
func minimumAddedCoins(coins []int, target int) (ans int) {
	slices.Sort(coins)
	for i, s := 0, 1; s <= target; {
		if i < len(coins) && coins[i] <= s {
			s += coins[i]
			i++
		} else {
			s <<= 1
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumAddedCoins(coins: number[], target: number): number {
    coins.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0, s = 1; s <= target; ) {
        if (i < coins.length && coins[i] <= s) {
            s += coins[i++];
        } else {
            s <<= 1;
            ++ans;
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

<p>给你一个下标从 <strong>0 </strong>开始的整数数组 <code>coins</code>，表示可用的硬币的面值，以及一个整数 <code>target</code> 。</p>

<p>如果存在某个 <code>coins</code> 的子序列总和为 <code>x</code>，那么整数 <code>x</code> 就是一个 <strong>可取得的金额 </strong>。</p>

<p>返回需要添加到数组中的<strong> 任意面值 </strong>硬币的 <strong>最小数量 </strong>，使范围 <code>[1, target]</code> 内的每个整数都属于 <strong>可取得的金额</strong> 。</p>

<p>数组的 <strong>子序列</strong> 是通过删除原始数组的一些（<strong>可能不删除</strong>）元素而形成的新的 <strong>非空</strong> 数组，删除过程不会改变剩余元素的相对位置。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>coins = [1,4,10], target = 19
<strong>输出：</strong>2
<strong>解释：</strong>需要添加面值为 2 和 8 的硬币各一枚，得到硬币数组 [1,2,4,8,10] 。
可以证明从 1 到 19 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>coins = [1,4,10,5,7,19], target = 19
<strong>输出：</strong>1
<strong>解释：</strong>只需要添加一枚面值为 2 的硬币，得到硬币数组 [1,2,4,5,7,10,19] 。
可以证明从 1 到 19 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 1 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>coins = [1,1,1], target = 20
<strong>输出：</strong>3
<strong>解释：</strong>
需要添加面值为 4 、8 和 16 的硬币各一枚，得到硬币数组 [1,1,1,4,8,16] 。 
可以证明从 1 到 20 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins[i] &lt;= target</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 构造

我们不妨假设当前需要构造的金额为 $s$，且我们已经构造出了 $[0,...,s-1]$ 内的所有金额。如果此时有一个新的硬币 $x$，我们把它加入到数组中，可以构造出 $[x, s+x-1]$ 内的所有金额。

接下来，分类讨论：

-   如果 $x \le s$，那么我们可以将上面两个区间合并，得到 $[0, s+x-1]$ 内的所有金额。
-   如果 $x \gt s$，那么我们就需要添加一个面值为 $s$ 的硬币，这样可以构造出 $[0, 2s-1]$ 内的所有金额。然后我们再考虑 $x$ 和 $s$ 的大小关系，继续分析。

因此，我们将数组 $coins$ 按照升序排序，然后从小到大遍历数组中的硬币。对于每个硬币 $x$，我们进行上述分类讨论，直到 $s > target$ 为止。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        s = 1
        ans = i = 0
        while s <= target:
            if i < len(coins) and coins[i] <= s:
                s += coins[i]
                i += 1
            else:
                s <<= 1
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minimumAddedCoins(int[] coins, int target) {
        Arrays.sort(coins);
        int ans = 0;
        for (int i = 0, s = 1; s <= target;) {
            if (i < coins.length && coins[i] <= s) {
                s += coins[i++];
            } else {
                s <<= 1;
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
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        for (int i = 0, s = 1; s <= target;) {
            if (i < coins.size() && coins[i] <= s) {
                s += coins[i++];
            } else {
                s <<= 1;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumAddedCoins(coins []int, target int) (ans int) {
	slices.Sort(coins)
	for i, s := 0, 1; s <= target; {
		if i < len(coins) && coins[i] <= s {
			s += coins[i]
			i++
		} else {
			s <<= 1
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumAddedCoins(coins: number[], target: number): number {
    coins.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0, s = 1; s <= target; ) {
        if (i < coins.length && coins[i] <= s) {
            s += coins[i++];
        } else {
            s <<= 1;
            ++ans;
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

# [2953. 统计完全子字符串](https://leetcode.cn/problems/count-complete-substrings){#2953}

{{< tabs "2953" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        def f(s: str) -> int:
            m = len(s)
            ans = 0
            for i in range(1, 27):
                l = i * k
                if l > m:
                    break
                cnt = Counter(s[:l])
                freq = Counter(cnt.values())
                ans += freq[k] == i
                for j in range(l, m):
                    freq[cnt[s[j]]] -= 1
                    cnt[s[j]] += 1
                    freq[cnt[s[j]]] += 1

                    freq[cnt[s[j - l]]] -= 1
                    cnt[s[j - l]] -= 1
                    freq[cnt[s[j - l]]] += 1

                    ans += freq[k] == i
            return ans

        n = len(word)
        ans = i = 0
        while i < n:
            j = i + 1
            while j < n and abs(ord(word[j]) - ord(word[j - 1])) <= 2:
                j += 1
            ans += f(word[i:j])
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countCompleteSubstrings(String word, int k) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && Math.abs(word.charAt(j) - word.charAt(j - 1)) <= 2) {
                ++j;
            }
            ans += f(word.substring(i, j), k);
            i = j;
        }
        return ans;
    }

    private int f(String s, int k) {
        int m = s.length();
        int ans = 0;
        for (int i = 1; i <= 26 && i * k <= m; ++i) {
            int l = i * k;
            int[] cnt = new int[26];
            for (int j = 0; j < l; ++j) {
                ++cnt[s.charAt(j) - 'a'];
            }
            Map<Integer, Integer> freq = new HashMap<>();
            for (int x : cnt) {
                if (x > 0) {
                    freq.merge(x, 1, Integer::sum);
                }
            }
            if (freq.getOrDefault(k, 0) == i) {
                ++ans;
            }
            for (int j = l; j < m; ++j) {
                int a = s.charAt(j) - 'a';
                int b = s.charAt(j - l) - 'a';
                freq.merge(cnt[a], -1, Integer::sum);
                ++cnt[a];
                freq.merge(cnt[a], 1, Integer::sum);

                freq.merge(cnt[b], -1, Integer::sum);
                --cnt[b];
                freq.merge(cnt[b], 1, Integer::sum);
                if (freq.getOrDefault(k, 0) == i) {
                    ++ans;
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
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        auto f = [&](string s) {
            int m = s.length();
            int ans = 0;
            for (int i = 1; i <= 26 && i * k <= m; ++i) {
                int l = i * k;
                int cnt[26]{};
                for (int j = 0; j < l; ++j) {
                    ++cnt[s[j] - 'a'];
                }
                unordered_map<int, int> freq;
                for (int x : cnt) {
                    if (x > 0) {
                        freq[x]++;
                    }
                }
                if (freq[k] == i) {
                    ++ans;
                }
                for (int j = l; j < m; ++j) {
                    int a = s[j] - 'a';
                    int b = s[j - l] - 'a';
                    freq[cnt[a]]--;
                    cnt[a]++;
                    freq[cnt[a]]++;

                    freq[cnt[b]]--;
                    cnt[b]--;
                    freq[cnt[b]]++;

                    if (freq[k] == i) {
                        ++ans;
                    }
                }
            }
            return ans;
        };
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && abs(word[j] - word[j - 1]) <= 2) {
                ++j;
            }
            ans += f(word.substr(i, j - i));
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCompleteSubstrings(word string, k int) (ans int) {
	n := len(word)
	f := func(s string) (ans int) {
		m := len(s)
		for i := 1; i <= 26 && i*k <= m; i++ {
			l := i * k
			cnt := [26]int{}
			for j := 0; j < l; j++ {
				cnt[int(s[j]-'a')]++
			}
			freq := map[int]int{}
			for _, x := range cnt {
				if x > 0 {
					freq[x]++
				}
			}
			if freq[k] == i {
				ans++
			}
			for j := l; j < m; j++ {
				a := int(s[j] - 'a')
				b := int(s[j-l] - 'a')
				freq[cnt[a]]--
				cnt[a]++
				freq[cnt[a]]++

				freq[cnt[b]]--
				cnt[b]--
				freq[cnt[b]]++

				if freq[k] == i {
					ans++
				}
			}
		}
		return
	}
	for i := 0; i < n; {
		j := i + 1
		for j < n && abs(int(word[j])-int(word[j-1])) <= 2 {
			j++
		}
		ans += f(word[i:j])
		i = j
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
{{% tab "ts" %}}
```ts
function countCompleteSubstrings(word: string, k: number): number {
    const f = (s: string): number => {
        const m = s.length;
        let ans = 0;
        for (let i = 1; i <= 26 && i * k <= m; i++) {
            const l = i * k;
            const cnt: number[] = new Array(26).fill(0);
            for (let j = 0; j < l; j++) {
                cnt[s.charCodeAt(j) - 'a'.charCodeAt(0)]++;
            }
            const freq: { [key: number]: number } = {};
            for (const x of cnt) {
                if (x > 0) {
                    freq[x] = (freq[x] || 0) + 1;
                }
            }
            if (freq[k] === i) {
                ans++;
            }

            for (let j = l; j < m; j++) {
                const a = s.charCodeAt(j) - 'a'.charCodeAt(0);
                const b = s.charCodeAt(j - l) - 'a'.charCodeAt(0);

                freq[cnt[a]]--;
                cnt[a]++;
                freq[cnt[a]] = (freq[cnt[a]] || 0) + 1;

                freq[cnt[b]]--;
                cnt[b]--;
                freq[cnt[b]] = (freq[cnt[b]] || 0) + 1;

                if (freq[k] === i) {
                    ans++;
                }
            }
        }

        return ans;
    };

    let n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && Math.abs(word.charCodeAt(j) - word.charCodeAt(j - 1)) <= 2) {
            j++;
        }
        ans += f(word.substring(i, j));
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

<p>给你一个字符串&nbsp;<code>word</code>&nbsp;和一个整数 <code>k</code>&nbsp;。</p>

<p>如果&nbsp;<code>word</code>&nbsp;的一个子字符串 <code>s</code>&nbsp;满足以下条件，我们称它是 <strong>完全字符串：</strong></p>

<ul>
	<li><code>s</code>&nbsp;中每个字符 <strong>恰好</strong>&nbsp;出现 <code>k</code>&nbsp;次。</li>
	<li>相邻字符在字母表中的顺序 <strong>至多</strong>&nbsp;相差&nbsp;<code>2</code>&nbsp;。也就是说，<code>s</code>&nbsp;中两个相邻字符&nbsp;<code>c1</code> 和&nbsp;<code>c2</code>&nbsp;，它们在字母表中的位置相差<strong>&nbsp;至多</strong>&nbsp;为 <code>2</code> 。</li>
</ul>

<p>请你返回 <code>word</code>&nbsp;中 <strong>完全</strong>&nbsp;子字符串的数目。</p>

<p><strong>子字符串</strong>&nbsp;指的是一个字符串中一段连续 <strong>非空</strong>&nbsp;的字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>word = "igigee", k = 2
<b>输出：</b>3
<b>解释：</b>完全子字符串需要满足每个字符恰好出现 2 次，且相邻字符相差至多为 2 ：<em><strong>igig</strong></em>ee, igig<strong style="font-style: italic;">ee</strong>, <em><strong>igigee</strong>&nbsp;。</em>
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>word = "aaabbbccc", k = 3
<b>输出：</b>6
<b>解释：</b>完全子字符串需要满足每个字符恰好出现 3 次，且相邻字符相差至多为 2 ：<em><strong>aaa</strong></em>bbbccc, aaa<em><strong>bbb</strong></em>ccc, aaabbb<em><strong>ccc</strong></em>, <em><strong>aaabbb</strong></em>ccc, aaa<em><strong>bbbccc</strong></em>, <em><strong>aaabbbccc </strong></em>。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
	<li><code>1 &lt;= k &lt;= word.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举字符种类数 + 滑动窗口

根据题目描述中的条件 $2$，我们可以发现，一个完全字符串中，相邻两个字符之差不超过 $2$。因此，我们遍历字符串 $word$，可以利用双指针把 $word$ 分割成若干个子字符串，这些子字符串中的字符种类数不超过 $26$，且相邻字符之差不超过 $2$。接下来，我们只需要在每个子字符串中，统计每个字符都出现 $k$ 次的子字符串的个数即可。

我们定义一个函数 $f(s)$，它的功能是统计字符串 $s$ 中每个字符都出现 $k$ 次的子字符串的个数。由于 $s$ 中的字符种类数不超过 $26$，因此我们可以枚举每个字符种类数 $i$，其中 $1 \le i \le 26$，那么每个字符种类数为 $i$ 的子字符串的长度为 $l = i \times k$。

我们可以用一个数组或哈希表 $cnt$ 维护一个长度为 $l$ 的滑动窗口中每个字符出现的次数，用另一个哈希表 $freq$ 维护每个次数出现的次数。如果 $freq[k] = i$，即有 $i$ 个字符都出现了 $k$ 次，那么我们就找到了一个满足条件的子字符串。我们可以用双指针维护这个滑动窗口，每次移动右指针时，我们将右指针指向的字符出现的次数加一，并更新 $freq$ 数组；每次移动左指针时，我们将左指针指向的字符出现的次数减一，并更新 $freq$ 数组。在每次移动指针后，我们都判断 $freq[k]$ 是否等于 $i$，如果等于则说明我们找到了一个满足条件的子字符串。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 $word$ 的长度；而 $\Sigma$ 是字符集的大小，本题中字符集为小写英文字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        def f(s: str) -> int:
            m = len(s)
            ans = 0
            for i in range(1, 27):
                l = i * k
                if l > m:
                    break
                cnt = Counter(s[:l])
                freq = Counter(cnt.values())
                ans += freq[k] == i
                for j in range(l, m):
                    freq[cnt[s[j]]] -= 1
                    cnt[s[j]] += 1
                    freq[cnt[s[j]]] += 1

                    freq[cnt[s[j - l]]] -= 1
                    cnt[s[j - l]] -= 1
                    freq[cnt[s[j - l]]] += 1

                    ans += freq[k] == i
            return ans

        n = len(word)
        ans = i = 0
        while i < n:
            j = i + 1
            while j < n and abs(ord(word[j]) - ord(word[j - 1])) <= 2:
                j += 1
            ans += f(word[i:j])
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int countCompleteSubstrings(String word, int k) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && Math.abs(word.charAt(j) - word.charAt(j - 1)) <= 2) {
                ++j;
            }
            ans += f(word.substring(i, j), k);
            i = j;
        }
        return ans;
    }

    private int f(String s, int k) {
        int m = s.length();
        int ans = 0;
        for (int i = 1; i <= 26 && i * k <= m; ++i) {
            int l = i * k;
            int[] cnt = new int[26];
            for (int j = 0; j < l; ++j) {
                ++cnt[s.charAt(j) - 'a'];
            }
            Map<Integer, Integer> freq = new HashMap<>();
            for (int x : cnt) {
                if (x > 0) {
                    freq.merge(x, 1, Integer::sum);
                }
            }
            if (freq.getOrDefault(k, 0) == i) {
                ++ans;
            }
            for (int j = l; j < m; ++j) {
                int a = s.charAt(j) - 'a';
                int b = s.charAt(j - l) - 'a';
                freq.merge(cnt[a], -1, Integer::sum);
                ++cnt[a];
                freq.merge(cnt[a], 1, Integer::sum);

                freq.merge(cnt[b], -1, Integer::sum);
                --cnt[b];
                freq.merge(cnt[b], 1, Integer::sum);
                if (freq.getOrDefault(k, 0) == i) {
                    ++ans;
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
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        auto f = [&](string s) {
            int m = s.length();
            int ans = 0;
            for (int i = 1; i <= 26 && i * k <= m; ++i) {
                int l = i * k;
                int cnt[26]{};
                for (int j = 0; j < l; ++j) {
                    ++cnt[s[j] - 'a'];
                }
                unordered_map<int, int> freq;
                for (int x : cnt) {
                    if (x > 0) {
                        freq[x]++;
                    }
                }
                if (freq[k] == i) {
                    ++ans;
                }
                for (int j = l; j < m; ++j) {
                    int a = s[j] - 'a';
                    int b = s[j - l] - 'a';
                    freq[cnt[a]]--;
                    cnt[a]++;
                    freq[cnt[a]]++;

                    freq[cnt[b]]--;
                    cnt[b]--;
                    freq[cnt[b]]++;

                    if (freq[k] == i) {
                        ++ans;
                    }
                }
            }
            return ans;
        };
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && abs(word[j] - word[j - 1]) <= 2) {
                ++j;
            }
            ans += f(word.substr(i, j - i));
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func countCompleteSubstrings(word string, k int) (ans int) {
	n := len(word)
	f := func(s string) (ans int) {
		m := len(s)
		for i := 1; i <= 26 && i*k <= m; i++ {
			l := i * k
			cnt := [26]int{}
			for j := 0; j < l; j++ {
				cnt[int(s[j]-'a')]++
			}
			freq := map[int]int{}
			for _, x := range cnt {
				if x > 0 {
					freq[x]++
				}
			}
			if freq[k] == i {
				ans++
			}
			for j := l; j < m; j++ {
				a := int(s[j] - 'a')
				b := int(s[j-l] - 'a')
				freq[cnt[a]]--
				cnt[a]++
				freq[cnt[a]]++

				freq[cnt[b]]--
				cnt[b]--
				freq[cnt[b]]++

				if freq[k] == i {
					ans++
				}
			}
		}
		return
	}
	for i := 0; i < n; {
		j := i + 1
		for j < n && abs(int(word[j])-int(word[j-1])) <= 2 {
			j++
		}
		ans += f(word[i:j])
		i = j
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

#### TypeScript

```ts
function countCompleteSubstrings(word: string, k: number): number {
    const f = (s: string): number => {
        const m = s.length;
        let ans = 0;
        for (let i = 1; i <= 26 && i * k <= m; i++) {
            const l = i * k;
            const cnt: number[] = new Array(26).fill(0);
            for (let j = 0; j < l; j++) {
                cnt[s.charCodeAt(j) - 'a'.charCodeAt(0)]++;
            }
            const freq: { [key: number]: number } = {};
            for (const x of cnt) {
                if (x > 0) {
                    freq[x] = (freq[x] || 0) + 1;
                }
            }
            if (freq[k] === i) {
                ans++;
            }

            for (let j = l; j < m; j++) {
                const a = s.charCodeAt(j) - 'a'.charCodeAt(0);
                const b = s.charCodeAt(j - l) - 'a'.charCodeAt(0);

                freq[cnt[a]]--;
                cnt[a]++;
                freq[cnt[a]] = (freq[cnt[a]] || 0) + 1;

                freq[cnt[b]]--;
                cnt[b]--;
                freq[cnt[b]] = (freq[cnt[b]] || 0) + 1;

                if (freq[k] === i) {
                    ans++;
                }
            }
        }

        return ans;
    };

    let n = word.length;
    let ans = 0;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && Math.abs(word.charCodeAt(j) - word.charCodeAt(j - 1)) <= 2) {
            j++;
        }
        ans += f(word.substring(i, j));
        i = j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2954. 统计感冒序列的数目](https://leetcode.cn/problems/count-the-number-of-infection-sequences){#2954}

{{< tabs "2954" >}}

{{% tab "python" %}}
```python
mod = 10**9 + 7
mx = 10**5
fac = [1] * (mx + 1)
for i in range(2, mx + 1):
    fac[i] = fac[i - 1] * i % mod


class Solution:
    def numberOfSequence(self, n: int, sick: List[int]) -> int:
        nums = [b - a - 1 for a, b in pairwise([-1] + sick + [n])]
        ans = 1
        s = sum(nums)
        ans = fac[s]
        for x in nums:
            if x:
                ans = ans * pow(fac[x], mod - 2, mod) % mod
        for x in nums[1:-1]:
            if x > 1:
                ans = ans * pow(2, x - 1, mod) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) (1e9 + 7);
    private static final int MX = 100000;
    private static final int[] FAC = new int[MX + 1];

    static {
        FAC[0] = 1;
        for (int i = 1; i <= MX; i++) {
            FAC[i] = (int) ((long) FAC[i - 1] * i % MOD);
        }
    }

    public int numberOfSequence(int n, int[] sick) {
        int m = sick.length;
        int[] nums = new int[m + 1];
        nums[0] = sick[0];
        nums[m] = n - sick[m - 1] - 1;
        for (int i = 1; i < m; i++) {
            nums[i] = sick[i] - sick[i - 1] - 1;
        }
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        int ans = FAC[s];
        for (int x : nums) {
            if (x > 0) {
                ans = (int) ((long) ans * qpow(FAC[x], MOD - 2) % MOD);
            }
        }
        for (int i = 1; i < nums.length - 1; ++i) {
            if (nums[i] > 1) {
                ans = (int) ((long) ans * qpow(2, nums[i] - 1) % MOD);
            }
        }
        return ans;
    }

    private int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int MX = 1e5;
const int MOD = 1e9 + 7;
int fac[MX + 1];

auto init = [] {
    fac[0] = 1;
    for (int i = 1; i <= MX; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    return 0;
}();

int qpow(long long a, long long n) {
    long long ans = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int m = sick.size();
        vector<int> nums(m + 1);

        nums[0] = sick[0];
        nums[m] = n - sick[m - 1] - 1;
        for (int i = 1; i < m; i++) {
            nums[i] = sick[i] - sick[i - 1] - 1;
        }

        int s = accumulate(nums.begin(), nums.end(), 0);
        long long ans = fac[s];
        for (int x : nums) {
            if (x > 0) {
                ans = ans * qpow(fac[x], MOD - 2) % MOD;
            }
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] > 1) {
                ans = ans * qpow(2, nums[i] - 1) % MOD;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const MX = 1e5
const MOD = 1e9 + 7

var fac [MX + 1]int

func init() {
	fac[0] = 1
	for i := 1; i <= MX; i++ {
		fac[i] = fac[i-1] * i % MOD
	}
}

func qpow(a, n int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % MOD
		}
		a = (a * a) % MOD
		n >>= 1
	}
	return ans
}

func numberOfSequence(n int, sick []int) int {
	m := len(sick)
	nums := make([]int, m+1)

	nums[0] = sick[0]
	nums[m] = n - sick[m-1] - 1
	for i := 1; i < m; i++ {
		nums[i] = sick[i] - sick[i-1] - 1
	}

	s := 0
	for _, x := range nums {
		s += x
	}
	ans := fac[s]
	for _, x := range nums {
		if x > 0 {
			ans = ans * qpow(fac[x], MOD-2) % MOD
		}
	}
	for i := 1; i < len(nums)-1; i++ {
		if nums[i] > 1 {
			ans = ans * qpow(2, nums[i]-1) % MOD
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const MX = 1e5;
const MOD: bigint = BigInt(1e9 + 7);
const fac: bigint[] = Array(MX + 1);

const init = (() => {
    fac[0] = 1n;
    for (let i = 1; i <= MX; ++i) {
        fac[i] = (fac[i - 1] * BigInt(i)) % MOD;
    }
    return 0;
})();

function qpow(a: bigint, n: number): bigint {
    let ans = 1n;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

function numberOfSequence(n: number, sick: number[]): number {
    const m = sick.length;
    const nums: number[] = Array(m + 1);
    nums[0] = sick[0];
    nums[m] = n - sick[m - 1] - 1;
    for (let i = 1; i < m; i++) {
        nums[i] = sick[i] - sick[i - 1] - 1;
    }

    const s = nums.reduce((acc, x) => acc + x, 0);
    let ans = fac[s];
    for (let x of nums) {
        if (x > 0) {
            ans = (ans * qpow(fac[x], Number(MOD) - 2)) % MOD;
        }
    }
    for (let i = 1; i < nums.length - 1; ++i) {
        if (nums[i] > 1) {
            ans = (ans * qpow(2n, nums[i] - 1)) % MOD;
        }
    }
    return Number(ans);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>sick</code>&nbsp;，数组按 <strong>升序</strong>&nbsp;排序。</p>

<p>有&nbsp;<code>n</code>&nbsp;位小朋友站成一排，按顺序编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。数组&nbsp;<code>sick</code>&nbsp;包含一开始得了感冒的小朋友的位置。如果位置为&nbsp;<code>i</code>&nbsp;的小朋友得了感冒，他会传染给下标为 <code>i - 1</code>&nbsp;或者 <code>i + 1</code>&nbsp;的小朋友，<strong>前提</strong> 是被传染的小朋友存在且还没有得感冒。每一秒中， <strong>至多一位</strong>&nbsp;还没感冒的小朋友会被传染。</p>

<p>经过有限的秒数后，队列中所有小朋友都会感冒。<strong>感冒序列</strong>&nbsp;指的是 <strong>所有</strong>&nbsp;一开始没有感冒的小朋友最后得感冒的顺序序列。请你返回所有感冒序列的数目。</p>

<p>由于答案可能很大，请你将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后返回。</p>

<p><b>注意</b>，感冒序列 <strong>不</strong> 包含一开始就得了感冒的小朋友的下标。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 5, sick = [0,4]
<b>输出：</b>4
<b>解释：</b>一开始，下标为 1 ，2 和 3 的小朋友没有感冒。总共有 4 个可能的感冒序列：
- 一开始，下标为 1 和 3 的小朋友可以被传染，因为他们分别挨着有感冒的小朋友 0 和 4 ，令下标为 1 的小朋友先被传染。
然后，下标为 2 的小朋友挨着感冒的小朋友 1 ，下标为 3 的小朋友挨着感冒的小朋友 4 ，两位小朋友都可以被传染，令下标为 2 的小朋友被传染。
最后，下标为 3 的小朋友被传染，因为他挨着感冒的小朋友 2 和 4 ，感冒序列为 [1,2,3] 。
- 一开始，下标为 1 和 3 的小朋友可以被传染，因为他们分别挨着感冒的小朋友 0 和 4 ，令下标为 1 的小朋友先被传染。
然后，下标为 2 的小朋友挨着感冒的小朋友 1 ，下标为 3 的小朋友挨着感冒的小朋友 4 ，两位小朋友都可以被传染，令下标为 3 的小朋友被传染。
最后，下标为 2 的小朋友被传染，因为他挨着感冒的小朋友 1 和 3 ，感冒序列为  [1,3,2] 。
- 感冒序列 [3,1,2] ，被传染的顺序：[<strong><em>0</em></strong>,1,2,3,<strong><em>4</em></strong>] =&gt; [<strong><em>0</em></strong>,1,2,<strong><em>3</em></strong>,<strong><em>4</em></strong>] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,2,<em><strong>3</strong></em>,<strong><em>4</em></strong>] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,<strong><em>3</em></strong>,<strong><em>4</em></strong>] 。
- 感冒序列 [3,2,1] ，被传染的顺序：[<strong><em>0</em></strong>,1,2,3,<strong><em>4</em></strong>] =&gt; [<strong><em>0</em></strong>,1,2,<strong><em>3</em></strong>,<strong><em>4</em></strong>] =&gt; [<strong><em>0</em></strong>,1,<strong><em>2</em></strong>,<strong><em>3</em></strong>,<strong><em>4</em></strong>] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,<strong><em>3</em></strong>,<strong><em>4</em></strong>] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 4, sick = [1]
<b>输出：</b>3
<b>解释：</b>一开始，下标为 0 ，2 和 3 的小朋友没有感冒。总共有 3 个可能的感冒序列：
- 感冒序列 [0,2,3] ，被传染的顺序：[0,<strong><em>1</em></strong>,2,3] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,2,3] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,3] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,<strong><em>3</em></strong>] 。
- 感冒序列 [2,0,3] ，被传染的顺序：[0,<strong><em>1</em></strong>,2,3] =&gt; [0,<strong><em>1</em></strong>,<strong><em>2</em></strong>,3] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,3] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,<strong><em>3</em></strong>] 。
- 感冒序列 [2,3,0] ，被传染的顺序：[0,<strong><em>1</em></strong>,2,3] =&gt; [0,<strong><em>1</em></strong>,<strong><em>2</em></strong>,3] =&gt; [0,<strong><em>1</em></strong>,<strong><em>2</em></strong>,<strong><em>3</em></strong>] =&gt; [<strong><em>0</em></strong>,<strong><em>1</em></strong>,<strong><em>2</em></strong>,<strong><em>3</em></strong>] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= sick.length &lt;= n - 1</code></li>
	<li><code>0 &lt;= sick[i] &lt;= n - 1</code></li>
	<li><code>sick</code>&nbsp;按升序排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合数学 + 乘法逆元 + 快速幂

根据题目描述，感冒的小朋友把还没有感冒的小朋友划分成了若干个连续段。我们可以用一个数组 $nums$ 记录每一段不感冒的小朋友的认识，不感冒人数一共有 $s = \sum_{i=0}^{k} nums[k]$ 人。我们可以发现，感冒序列的数目就是 $s$ 个不同元素的全排列数，即 $s!$。

假设每一段不感冒小朋友只有一种传播方案，那么一共有 $\frac{s!}{\prod_{i=0}^{k} nums[k]!}$ 种感冒序列。

接下来，我们再考虑每一段不感冒小朋友的传播方案。假设一段不感冒小朋友有 $x$ 个人，那么他们的传播方案有 $2^{x-1}$ 种，因为每一次可以从一段的左右两端选择其中一端传播，即：两种选择，一共有 $x-1$ 次传播。不过，如果是第一段或者最后一段，那么只有一种选择。

综上所述，总的感冒序列数目为：

$$
\frac{s!}{\prod_{i=0}^{k} nums[k]!} \prod_{i=1}^{k-1} 2^{nums[i]-1}
$$

最后，我们需要考虑到答案可能很大，需要对 $10^9 + 7$ 取模。因此，我们需要预处理阶乘和乘法逆元。

时间复杂度 $O(m)$，其中 $m$ 是数组 $sick$ 的长度。忽略预处理数组的空间消耗，空间复杂度 $O(m)$。

<!-- tabs:start -->

#### Python3

```python
mod = 10**9 + 7
mx = 10**5
fac = [1] * (mx + 1)
for i in range(2, mx + 1):
    fac[i] = fac[i - 1] * i % mod


class Solution:
    def numberOfSequence(self, n: int, sick: List[int]) -> int:
        nums = [b - a - 1 for a, b in pairwise([-1] + sick + [n])]
        ans = 1
        s = sum(nums)
        ans = fac[s]
        for x in nums:
            if x:
                ans = ans * pow(fac[x], mod - 2, mod) % mod
        for x in nums[1:-1]:
            if x > 1:
                ans = ans * pow(2, x - 1, mod) % mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) (1e9 + 7);
    private static final int MX = 100000;
    private static final int[] FAC = new int[MX + 1];

    static {
        FAC[0] = 1;
        for (int i = 1; i <= MX; i++) {
            FAC[i] = (int) ((long) FAC[i - 1] * i % MOD);
        }
    }

    public int numberOfSequence(int n, int[] sick) {
        int m = sick.length;
        int[] nums = new int[m + 1];
        nums[0] = sick[0];
        nums[m] = n - sick[m - 1] - 1;
        for (int i = 1; i < m; i++) {
            nums[i] = sick[i] - sick[i - 1] - 1;
        }
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        int ans = FAC[s];
        for (int x : nums) {
            if (x > 0) {
                ans = (int) ((long) ans * qpow(FAC[x], MOD - 2) % MOD);
            }
        }
        for (int i = 1; i < nums.length - 1; ++i) {
            if (nums[i] > 1) {
                ans = (int) ((long) ans * qpow(2, nums[i] - 1) % MOD);
            }
        }
        return ans;
    }

    private int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
const int MX = 1e5;
const int MOD = 1e9 + 7;
int fac[MX + 1];

auto init = [] {
    fac[0] = 1;
    for (int i = 1; i <= MX; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    return 0;
}();

int qpow(long long a, long long n) {
    long long ans = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int m = sick.size();
        vector<int> nums(m + 1);

        nums[0] = sick[0];
        nums[m] = n - sick[m - 1] - 1;
        for (int i = 1; i < m; i++) {
            nums[i] = sick[i] - sick[i - 1] - 1;
        }

        int s = accumulate(nums.begin(), nums.end(), 0);
        long long ans = fac[s];
        for (int x : nums) {
            if (x > 0) {
                ans = ans * qpow(fac[x], MOD - 2) % MOD;
            }
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] > 1) {
                ans = ans * qpow(2, nums[i] - 1) % MOD;
            }
        }
        return ans;
    }
};
```

#### Go

```go
const MX = 1e5
const MOD = 1e9 + 7

var fac [MX + 1]int

func init() {
	fac[0] = 1
	for i := 1; i <= MX; i++ {
		fac[i] = fac[i-1] * i % MOD
	}
}

func qpow(a, n int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % MOD
		}
		a = (a * a) % MOD
		n >>= 1
	}
	return ans
}

func numberOfSequence(n int, sick []int) int {
	m := len(sick)
	nums := make([]int, m+1)

	nums[0] = sick[0]
	nums[m] = n - sick[m-1] - 1
	for i := 1; i < m; i++ {
		nums[i] = sick[i] - sick[i-1] - 1
	}

	s := 0
	for _, x := range nums {
		s += x
	}
	ans := fac[s]
	for _, x := range nums {
		if x > 0 {
			ans = ans * qpow(fac[x], MOD-2) % MOD
		}
	}
	for i := 1; i < len(nums)-1; i++ {
		if nums[i] > 1 {
			ans = ans * qpow(2, nums[i]-1) % MOD
		}
	}
	return ans
}
```

#### TypeScript

```ts
const MX = 1e5;
const MOD: bigint = BigInt(1e9 + 7);
const fac: bigint[] = Array(MX + 1);

const init = (() => {
    fac[0] = 1n;
    for (let i = 1; i <= MX; ++i) {
        fac[i] = (fac[i - 1] * BigInt(i)) % MOD;
    }
    return 0;
})();

function qpow(a: bigint, n: number): bigint {
    let ans = 1n;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

function numberOfSequence(n: number, sick: number[]): number {
    const m = sick.length;
    const nums: number[] = Array(m + 1);
    nums[0] = sick[0];
    nums[m] = n - sick[m - 1] - 1;
    for (let i = 1; i < m; i++) {
        nums[i] = sick[i] - sick[i - 1] - 1;
    }

    const s = nums.reduce((acc, x) => acc + x, 0);
    let ans = fac[s];
    for (let x of nums) {
        if (x > 0) {
            ans = (ans * qpow(fac[x], Number(MOD) - 2)) % MOD;
        }
    }
    for (let i = 1; i < nums.length - 1; ++i) {
        if (nums[i] > 1) {
            ans = (ans * qpow(2n, nums[i] - 1)) % MOD;
        }
    }
    return Number(ans);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2955. 同端子串的数量 🔒](https://leetcode.cn/problems/number-of-same-end-substrings){#2955}

{{< tabs "2955" >}}

{{% tab "python" %}}
```python
class Solution:
    def sameEndSubstringCount(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        cs = set(s)
        cnt = {c: [0] * (n + 1) for c in cs}
        for i, a in enumerate(s, 1):
            for c in cs:
                cnt[c][i] = cnt[c][i - 1]
            cnt[a][i] += 1
        ans = []
        for l, r in queries:
            t = r - l + 1
            for c in cs:
                x = cnt[c][r + 1] - cnt[c][l]
                t += x * (x - 1) // 2
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sameEndSubstringCount(String s, int[][] queries) {
        int n = s.length();
        int[][] cnt = new int[26][n + 1];
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < 26; ++i) {
                cnt[i][j] = cnt[i][j - 1];
            }
            cnt[s.charAt(j - 1) - 'a'][j]++;
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int l = queries[k][0], r = queries[k][1];
            ans[k] = r - l + 1;
            for (int i = 0; i < 26; ++i) {
                int x = cnt[i][r + 1] - cnt[i][l];
                ans[k] += x * (x - 1) / 2;
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
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int cnt[26][n + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < 26; ++i) {
                cnt[i][j] = cnt[i][j - 1];
            }
            cnt[s[j - 1] - 'a'][j]++;
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(r - l + 1);
            for (int i = 0; i < 26; ++i) {
                int x = cnt[i][r + 1] - cnt[i][l];
                ans.back() += x * (x - 1) / 2;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sameEndSubstringCount(s string, queries [][]int) []int {
	n := len(s)
	cnt := make([][]int, 26)
	for i := 0; i < 26; i++ {
		cnt[i] = make([]int, n+1)
	}

	for j := 1; j <= n; j++ {
		for i := 0; i < 26; i++ {
			cnt[i][j] = cnt[i][j-1]
		}
		cnt[s[j-1]-'a'][j]++
	}

	var ans []int
	for _, q := range queries {
		l, r := q[0], q[1]
		ans = append(ans, r-l+1)
		for i := 0; i < 26; i++ {
			x := cnt[i][r+1] - cnt[i][l]
			ans[len(ans)-1] += x * (x - 1) / 2
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sameEndSubstringCount(s: string, queries: number[][]): number[] {
    const n: number = s.length;
    const cnt: number[][] = Array.from({ length: 26 }, () => Array(n + 1).fill(0));
    for (let j = 1; j <= n; j++) {
        for (let i = 0; i < 26; i++) {
            cnt[i][j] = cnt[i][j - 1];
        }
        cnt[s.charCodeAt(j - 1) - 'a'.charCodeAt(0)][j]++;
    }
    const ans: number[] = [];
    for (const [l, r] of queries) {
        ans.push(r - l + 1);
        for (let i = 0; i < 26; i++) {
            const x: number = cnt[i][r + 1] - cnt[i][l];
            ans[ans.length - 1] += (x * (x - 1)) / 2;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn same_end_substring_count(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = s.len();
        let mut cnt: Vec<Vec<i32>> = vec![vec![0; n + 1]; 26];
        for j in 1..=n {
            for i in 0..26 {
                cnt[i][j] = cnt[i][j - 1];
            }
            cnt[(s.as_bytes()[j - 1] as usize) - (b'a' as usize)][j] += 1;
        }
        let mut ans: Vec<i32> = Vec::new();
        for q in queries.iter() {
            let l = q[0] as usize;
            let r = q[1] as usize;
            let mut t = (r - l + 1) as i32;
            for i in 0..26 {
                let x = cnt[i][r + 1] - cnt[i][l];
                t += (x * (x - 1)) / 2;
            }
            ans.push(t);
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

<p>给定一个 <strong>下标从0开始</strong>&nbsp;的字符串 <code>s</code>，以及一个二维整数数组 <code>queries</code>，其中 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code> 表示 <code>s</code> 中从索引 <code>l<sub>i</sub></code> 开始到索引 <code>r<sub>i</sub></code> 结束的子串（<strong>包括两端</strong>），即 <code>s[l<sub>i</sub>..r<sub>i</sub>]</code>。</p>

<p>返回一个数组 <code>ans</code>，其中 <code>ans[i]</code> 是 <code>queries[i]</code> 的 <strong>同端</strong> 子串的数量。</p>

<p>如果一个&nbsp;<strong>下标从0开始 </strong>且长度为 <code>n</code> 的字符串 <code>t</code> 两端的字符相同，即 <code>t[0] == t[n - 1]</code>，则该字符串被称为 <strong>同端</strong>。</p>

<p><strong>子串</strong> 是一个字符串中连续的非空字符序列。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>s = "abcaab", queries = [[0,0],[1,4],[2,5],[0,5]]
<b>输出：</b>[1,5,5,10]
<b>解释：</b>每个查询的同端子串如下：
第一个查询：s[0..0] 是 "a"，有 1 个同端子串："<strong><u>a</u></strong>"。
第二个查询：s[1..4] 是 "bcaa"，有 5 个同端子串："<strong><u>b</u></strong>caa", "b<strong><u>c</u></strong>aa", "bc<strong><u>a</u></strong>a", "bca<strong><u>a</u></strong>", "bc<strong><u>aa</u></strong>"。
第三个查询：s[2..5] 是 "caab"，有 5 个同端子串："<strong><u>c</u></strong>aab", "c<strong><u>a</u></strong>ab", "ca<strong><u>a</u></strong>b", "caa<strong><u>b</u></strong>", "c<strong><u>aa</u></strong>b"。
第四个查询：s[0..5] 是 "abcaab"，有 10 个同端子串："<strong><u>a</u></strong>bcaab", "a<strong><u>b</u></strong>caab", "ab<strong><u>c</u></strong>aab", "abc<strong><u>a</u></strong>ab", "abca<strong><u>a</u></strong>b", "abcaa<strong><u>b</u></strong>", "abc<strong><u>aa</u></strong>b", "<strong><u>abca</u></strong>ab", "<strong><u>abcaa</u></strong>b", "a<strong><u>bcaab</u></strong>"。</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>s = "abcd", queries = [[0,3]]
<b>输出：</b>[4]
<b>解释：</b>唯一的查询是 s[0..3]，它有 4 个同端子串："<strong><u>a</u></strong>bcd", "a<strong><u>b</u></strong>cd", "ab<strong><u>c</u></strong>d", "abc<strong><u>d</u></strong>"。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> 仅包含小写英文字母。</li>
	<li><code>1 &lt;= queries.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 枚举

我们可以预处理出每个字母的前缀和，记录在数组 $cnt$ 中，其中 $cnt[i][j]$ 表示第 $i$ 个字母在前 $j$ 个字符中出现的次数。这样，对于每个区间 $[l, r]$，我们可以枚举区间中的每个字母 $c$，利用前缀和数组快速计算出 $c$ 在区间中出现的次数 $x$，我们任取其中两个，即可组成一个同尾子串，子串数为 $C_x^2=\frac{x(x-1)}{2}$，加上区间中每个字母可以单独组成同尾子串的情况，一共有 $r - l + 1$ 个字母。因此，对于每个查询 $[l, r]$，满足条件的同尾子串数为 $r - l + 1 + \sum_{c \in \Sigma} \frac{x_c(x_c-1)}{2}$，其中 $x_c$ 表示字母 $c$ 在区间 $[l, r]$ 中出现的次数。

时间复杂度 $O((n + m) \times |\Sigma|)$，空间复杂度 $O(n \times |\Sigma|)$。其中 $n$ 和 $m$ 分别为字符串 $s$ 的长度和查询数，而 $\Sigma$ 表示字符串 $s$ 中出现的字母集合，本题中 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sameEndSubstringCount(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        cs = set(s)
        cnt = {c: [0] * (n + 1) for c in cs}
        for i, a in enumerate(s, 1):
            for c in cs:
                cnt[c][i] = cnt[c][i - 1]
            cnt[a][i] += 1
        ans = []
        for l, r in queries:
            t = r - l + 1
            for c in cs:
                x = cnt[c][r + 1] - cnt[c][l]
                t += x * (x - 1) // 2
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public int[] sameEndSubstringCount(String s, int[][] queries) {
        int n = s.length();
        int[][] cnt = new int[26][n + 1];
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < 26; ++i) {
                cnt[i][j] = cnt[i][j - 1];
            }
            cnt[s.charAt(j - 1) - 'a'][j]++;
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int l = queries[k][0], r = queries[k][1];
            ans[k] = r - l + 1;
            for (int i = 0; i < 26; ++i) {
                int x = cnt[i][r + 1] - cnt[i][l];
                ans[k] += x * (x - 1) / 2;
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
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int cnt[26][n + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < 26; ++i) {
                cnt[i][j] = cnt[i][j - 1];
            }
            cnt[s[j - 1] - 'a'][j]++;
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(r - l + 1);
            for (int i = 0; i < 26; ++i) {
                int x = cnt[i][r + 1] - cnt[i][l];
                ans.back() += x * (x - 1) / 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sameEndSubstringCount(s string, queries [][]int) []int {
	n := len(s)
	cnt := make([][]int, 26)
	for i := 0; i < 26; i++ {
		cnt[i] = make([]int, n+1)
	}

	for j := 1; j <= n; j++ {
		for i := 0; i < 26; i++ {
			cnt[i][j] = cnt[i][j-1]
		}
		cnt[s[j-1]-'a'][j]++
	}

	var ans []int
	for _, q := range queries {
		l, r := q[0], q[1]
		ans = append(ans, r-l+1)
		for i := 0; i < 26; i++ {
			x := cnt[i][r+1] - cnt[i][l]
			ans[len(ans)-1] += x * (x - 1) / 2
		}
	}

	return ans
}
```

#### TypeScript

```ts
function sameEndSubstringCount(s: string, queries: number[][]): number[] {
    const n: number = s.length;
    const cnt: number[][] = Array.from({ length: 26 }, () => Array(n + 1).fill(0));
    for (let j = 1; j <= n; j++) {
        for (let i = 0; i < 26; i++) {
            cnt[i][j] = cnt[i][j - 1];
        }
        cnt[s.charCodeAt(j - 1) - 'a'.charCodeAt(0)][j]++;
    }
    const ans: number[] = [];
    for (const [l, r] of queries) {
        ans.push(r - l + 1);
        for (let i = 0; i < 26; i++) {
            const x: number = cnt[i][r + 1] - cnt[i][l];
            ans[ans.length - 1] += (x * (x - 1)) / 2;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn same_end_substring_count(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = s.len();
        let mut cnt: Vec<Vec<i32>> = vec![vec![0; n + 1]; 26];
        for j in 1..=n {
            for i in 0..26 {
                cnt[i][j] = cnt[i][j - 1];
            }
            cnt[(s.as_bytes()[j - 1] as usize) - (b'a' as usize)][j] += 1;
        }
        let mut ans: Vec<i32> = Vec::new();
        for q in queries.iter() {
            let l = q[0] as usize;
            let r = q[1] as usize;
            let mut t = (r - l + 1) as i32;
            for i in 0..26 {
                let x = cnt[i][r + 1] - cnt[i][l];
                t += (x * (x - 1)) / 2;
            }
            ans.push(t);
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

# [2956. 找到两个数组中的公共元素](https://leetcode.cn/problems/find-common-elements-between-two-arrays){#2956}

{{< tabs "2956" >}}

{{% tab "python" %}}
```python
class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1, s2 = set(nums1), set(nums2)
        return [sum(x in s2 for x in nums1), sum(x in s1 for x in nums2)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        int[] s1 = new int[101];
        int[] s2 = new int[101];
        for (int x : nums1) {
            s1[x] = 1;
        }
        for (int x : nums2) {
            s2[x] = 1;
        }
        int[] ans = new int[2];
        for (int x : nums1) {
            ans[0] += s2[x];
        }
        for (int x : nums2) {
            ans[1] += s1[x];
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
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int s1[101]{};
        int s2[101]{};
        for (int& x : nums1) {
            s1[x] = 1;
        }
        for (int& x : nums2) {
            s2[x] = 1;
        }
        vector<int> ans(2);
        for (int& x : nums1) {
            ans[0] += s2[x];
        }
        for (int& x : nums2) {
            ans[1] += s1[x];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findIntersectionValues(nums1 []int, nums2 []int) []int {
	s1 := [101]int{}
	s2 := [101]int{}
	for _, x := range nums1 {
		s1[x] = 1
	}
	for _, x := range nums2 {
		s2[x] = 1
	}
	ans := make([]int, 2)
	for _, x := range nums1 {
		ans[0] += s2[x]
	}
	for _, x := range nums2 {
		ans[1] += s1[x]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findIntersectionValues(nums1: number[], nums2: number[]): number[] {
    const s1: number[] = Array(101).fill(0);
    const s2: number[] = Array(101).fill(0);
    for (const x of nums1) {
        s1[x] = 1;
    }
    for (const x of nums2) {
        s2[x] = 1;
    }
    const ans: number[] = Array(2).fill(0);
    for (const x of nums1) {
        ans[0] += s2[x];
    }
    for (const x of nums2) {
        ans[1] += s1[x];
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

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;，它们分别含有 <code>n</code>&nbsp;和 <code>m</code>&nbsp;个元素。请你计算以下两个数值：</p>

<ul>
	<li><code>answer1</code>：使得&nbsp;<code>nums1[i]</code>&nbsp;在&nbsp;<code>nums2</code>&nbsp;中出现的下标&nbsp;<code>i</code>&nbsp;的数量。</li>
	<li><code>answer2</code>：使得&nbsp;<code>nums2[i]</code>&nbsp;在&nbsp;<code>nums1</code>&nbsp;中出现的下标&nbsp;<code>i</code>&nbsp;的数量。</li>
</ul>

<p>返回 <code>[answer1, answer2]</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [2,3,2], nums2 = [1,2]</span></p>

<p><strong>输出：</strong><span class="example-io">[2,1]</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2956.Find%20Common%20Elements%20Between%20Two%20Arrays/images/3488_find_common_elements_between_two_arrays-t1.gif" style="width: 225px; height: 150px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]</span></p>

<p><strong>输出：</strong><span class="example-io">[3,4]</span></p>

<p><strong>解释：</strong></p>

<p><code>nums1</code>&nbsp;中下标在 1，2，3 的元素在&nbsp;<code>nums2</code>&nbsp;中也存在。所以&nbsp;<code>answer1</code>&nbsp;为&nbsp;3。</p>

<p><code>nums2</code>&nbsp;中下标在 0，1，3，4 的元素在&nbsp;<code>nums1</code>&nbsp;中也存在。所以&nbsp;<code>answer2</code>&nbsp;为 4。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [3,4,2,3], nums2 = [1,5]</span></p>

<p><strong>输出：</strong><span class="example-io">[0,0]</span></p>

<p><strong>解释：</strong></p>

<p><code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;中没有相同的数字，所以答案是 [0,0]。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>m == nums2.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以用两个哈希表或数组 $s1$ 和 $s2$ 分别记录两个数组中出现的元素。

接下来，我们创建一个长度为 $2$ 的数组 $ans$，其中 $ans[0]$ 表示 $nums1$ 中出现在 $s2$ 中的元素个数，$ans[1]$ 表示 $nums2$ 中出现在 $s1$ 中的元素个数。

然后，我们遍历数组 $nums1$ 中的每个元素 $x$，如果 $x$ 在 $s2$ 中出现过，则将 $ans[0]$ 加一。接着，我们遍历数组 $nums2$ 中的每个元素 $x$，如果 $x$ 在 $s1$ 中出现过，则将 $ans[1]$ 加一。

最后，我们返回数组 $ans$ 即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1, s2 = set(nums1), set(nums2)
        return [sum(x in s2 for x in nums1), sum(x in s1 for x in nums2)]
```

#### Java

```java
class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        int[] s1 = new int[101];
        int[] s2 = new int[101];
        for (int x : nums1) {
            s1[x] = 1;
        }
        for (int x : nums2) {
            s2[x] = 1;
        }
        int[] ans = new int[2];
        for (int x : nums1) {
            ans[0] += s2[x];
        }
        for (int x : nums2) {
            ans[1] += s1[x];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int s1[101]{};
        int s2[101]{};
        for (int& x : nums1) {
            s1[x] = 1;
        }
        for (int& x : nums2) {
            s2[x] = 1;
        }
        vector<int> ans(2);
        for (int& x : nums1) {
            ans[0] += s2[x];
        }
        for (int& x : nums2) {
            ans[1] += s1[x];
        }
        return ans;
    }
};
```

#### Go

```go
func findIntersectionValues(nums1 []int, nums2 []int) []int {
	s1 := [101]int{}
	s2 := [101]int{}
	for _, x := range nums1 {
		s1[x] = 1
	}
	for _, x := range nums2 {
		s2[x] = 1
	}
	ans := make([]int, 2)
	for _, x := range nums1 {
		ans[0] += s2[x]
	}
	for _, x := range nums2 {
		ans[1] += s1[x]
	}
	return ans
}
```

#### TypeScript

```ts
function findIntersectionValues(nums1: number[], nums2: number[]): number[] {
    const s1: number[] = Array(101).fill(0);
    const s2: number[] = Array(101).fill(0);
    for (const x of nums1) {
        s1[x] = 1;
    }
    for (const x of nums2) {
        s2[x] = 1;
    }
    const ans: number[] = Array(2).fill(0);
    for (const x of nums1) {
        ans[0] += s2[x];
    }
    for (const x of nums2) {
        ans[1] += s1[x];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2957. 消除相邻近似相等字符](https://leetcode.cn/problems/remove-adjacent-almost-equal-characters){#2957}

{{< tabs "2957" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:
        ans = 0
        i, n = 1, len(word)
        while i < n:
            if abs(ord(word[i]) - ord(word[i - 1])) < 2:
                ans += 1
                i += 2
            else:
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int removeAlmostEqualCharacters(String word) {
        int ans = 0, n = word.length();
        for (int i = 1; i < n; ++i) {
            if (Math.abs(word.charAt(i) - word.charAt(i - 1)) < 2) {
                ++ans;
                ++i;
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
    int removeAlmostEqualCharacters(string word) {
        int ans = 0, n = word.size();
        for (int i = 1; i < n; ++i) {
            if (abs(word[i] - word[i - 1]) < 2) {
                ++ans;
                ++i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeAlmostEqualCharacters(word string) (ans int) {
	for i := 1; i < len(word); i++ {
		if abs(int(word[i])-int(word[i-1])) < 2 {
			ans++
			i++
		}
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
{{% tab "ts" %}}
```ts
function removeAlmostEqualCharacters(word: string): number {
    let ans = 0;
    for (let i = 1; i < word.length; ++i) {
        if (Math.abs(word.charCodeAt(i) - word.charCodeAt(i - 1)) < 2) {
            ++ans;
            ++i;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>word</code>&nbsp;。</p>

<p>一次操作中，你可以选择&nbsp;<code>word</code>&nbsp;中任意一个下标 <code>i</code>&nbsp;，将&nbsp;<code>word[i]</code> 修改成任意一个小写英文字母。</p>

<p>请你返回消除 <code>word</code>&nbsp;中所有相邻 <strong>近似相等</strong>&nbsp;字符的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>两个字符&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;如果满足&nbsp;<code>a == b</code>&nbsp;或者&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;在字母表中是相邻的，那么我们称它们是 <strong>近似相等</strong>&nbsp;字符。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>word = "aaaaa"
<b>输出：</b>2
<b>解释：</b>我们将 word 变为 "a<em><strong>c</strong></em>a<em><strong>c</strong></em>a" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 2 次操作。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>word = "abddez"
<b>输出：</b>2
<b>解释：</b>我们将 word 变为 "<em><strong>y</strong></em>bd<em><strong>o</strong></em>ez" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 2 次操作。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>word = "zyxyxyz"
<b>输出：</b>3
<b>解释：</b>我们将 word 变为 "z<em><strong>a</strong></em>x<em><strong>a</strong></em>x<em><strong>a</strong></em>z" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 3 次操作
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们从下标 $1$ 开始遍历字符串 $word$，如果 $word[i]$ 和 $word[i - 1]$ 相邻近似相等，那么我们就贪心地将 $word[i]$ 替换成一个与 $word[i - 1]$ 和 $word[i + 1]$ 都不相等的字符（可以不执行替换操作，记录操作次数即可）。然后，我们跳过 $word[i + 1]$，继续遍历字符串 $word$。

最后，我们返回记录的操作次数。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $word$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:
        ans = 0
        i, n = 1, len(word)
        while i < n:
            if abs(ord(word[i]) - ord(word[i - 1])) < 2:
                ans += 1
                i += 2
            else:
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int removeAlmostEqualCharacters(String word) {
        int ans = 0, n = word.length();
        for (int i = 1; i < n; ++i) {
            if (Math.abs(word.charAt(i) - word.charAt(i - 1)) < 2) {
                ++ans;
                ++i;
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
    int removeAlmostEqualCharacters(string word) {
        int ans = 0, n = word.size();
        for (int i = 1; i < n; ++i) {
            if (abs(word[i] - word[i - 1]) < 2) {
                ++ans;
                ++i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeAlmostEqualCharacters(word string) (ans int) {
	for i := 1; i < len(word); i++ {
		if abs(int(word[i])-int(word[i-1])) < 2 {
			ans++
			i++
		}
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

#### TypeScript

```ts
function removeAlmostEqualCharacters(word: string): number {
    let ans = 0;
    for (let i = 1; i < word.length; ++i) {
        if (Math.abs(word.charCodeAt(i) - word.charCodeAt(i - 1)) < 2) {
            ++ans;
            ++i;
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

# [2958. 最多 K 个重复元素的最长子数组](https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency){#2958}

{{< tabs "2958" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        ans = j = 0
        for i, x in enumerate(nums):
            cnt[x] += 1
            while cnt[x] > k:
                cnt[nums[j]] -= 1
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int i = 0, j = 0; i < nums.length; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            while (cnt.get(nums[i]) > k) {
                cnt.merge(nums[j++], -1, Integer::sum);
            }
            ans = Math.max(ans, i - j + 1);
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
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            while (cnt[nums[i]] > k) {
                --cnt[nums[j++]];
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubarrayLength(nums []int, k int) (ans int) {
	cnt := map[int]int{}
	for i, j, n := 0, 0, len(nums); i < n; i++ {
		cnt[nums[i]]++
		for ; cnt[nums[i]] > k; j++ {
			cnt[nums[j]]--
		}
		ans = max(ans, i-j+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubarrayLength(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0, j = 0; i < nums.length; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        for (; cnt.get(nums[i])! > k; ++j) {
            cnt.set(nums[j], cnt.get(nums[j])! - 1);
        }
        ans = Math.max(ans, i - j + 1);
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一个元素 <code>x</code>&nbsp;在数组中的 <strong>频率</strong>&nbsp;指的是它在数组中的出现次数。</p>

<p>如果一个数组中所有元素的频率都 <strong>小于等于&nbsp;</strong><code>k</code>&nbsp;，那么我们称这个数组是 <strong>好</strong>&nbsp;数组。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <strong>最长好</strong>&nbsp;子数组的长度。</p>

<p><strong>子数组</strong> 指的是一个数组中一段连续非空的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,1,2,3,1,2], k = 2
<b>输出：</b>6
<strong>解释：</strong>最长好子数组是 [1,2,3,1,2,3] ，值 1 ，2 和 3 在子数组中的频率都没有超过 k = 2 。[2,3,1,2,3,1] 和 [3,1,2,3,1,2] 也是好子数组。
最长好子数组的长度为 6 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,1,2,1,2], k = 1
<b>输出：</b>2
<b>解释：</b>最长好子数组是 [1,2] ，值 1 和 2 在子数组中的频率都没有超过 k = 1 。[2,1] 也是好子数组。
最长好子数组的长度为 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [5,5,5,5,5,5,5], k = 4
<b>输出：</b>4
<b>解释：</b>最长好子数组是 [5,5,5,5] ，值 5 在子数组中的频率没有超过 k = 4 。
最长好子数组的长度为 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以用两个指针 $j$ 和 $i$ 分别表示子数组的左右端点，初始时两个指针都指向数组的第一个元素。

接下来，我们遍历数组 $nums$ 中的每个元素 $x$，对于每个元素 $x$，我们将 $x$ 的出现次数加一，然后判断当前子数组是否满足要求。如果当前子数组不满足要求，我们就将指针 $j$ 右移一位，并将 $nums[j]$ 的出现次数减一，直到当前子数组满足要求为止。然后我们更新答案 $ans = \max(ans, i - j + 1)$。继续遍历，直到 $i$ 到达数组的末尾。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        ans = j = 0
        for i, x in enumerate(nums):
            cnt[x] += 1
            while cnt[x] > k:
                cnt[nums[j]] -= 1
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```

#### Java

```java
class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int i = 0, j = 0; i < nums.length; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
            while (cnt.get(nums[i]) > k) {
                cnt.merge(nums[j++], -1, Integer::sum);
            }
            ans = Math.max(ans, i - j + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            while (cnt[nums[i]] > k) {
                --cnt[nums[j++]];
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maxSubarrayLength(nums []int, k int) (ans int) {
	cnt := map[int]int{}
	for i, j, n := 0, 0, len(nums); i < n; i++ {
		cnt[nums[i]]++
		for ; cnt[nums[i]] > k; j++ {
			cnt[nums[j]]--
		}
		ans = max(ans, i-j+1)
	}
	return
}
```

#### TypeScript

```ts
function maxSubarrayLength(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0, j = 0; i < nums.length; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) ?? 0) + 1);
        for (; cnt.get(nums[i])! > k; ++j) {
            cnt.set(nums[j], cnt.get(nums[j])! - 1);
        }
        ans = Math.max(ans, i - j + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2959. 关闭分部的可行集合数目](https://leetcode.cn/problems/number-of-possible-sets-of-closing-branches){#2959}

{{< tabs "2959" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSets(self, n: int, maxDistance: int, roads: List[List[int]]) -> int:
        ans = 0
        for mask in range(1 << n):
            g = [[inf] * n for _ in range(n)]
            for u, v, w in roads:
                if mask >> u & 1 and mask >> v & 1:
                    g[u][v] = min(g[u][v], w)
                    g[v][u] = min(g[v][u], w)
            for k in range(n):
                if mask >> k & 1:
                    g[k][k] = 0
                    for i in range(n):
                        for j in range(n):
                            # g[i][j] = min(g[i][j], g[i][k] + g[k][j])
                            if g[i][k] + g[k][j] < g[i][j]:
                                g[i][j] = g[i][k] + g[k][j]
            if all(
                g[i][j] <= maxDistance
                for i in range(n)
                for j in range(n)
                if mask >> i & 1 and mask >> j & 1
            ):
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfSets(int n, int maxDistance, int[][] roads) {
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int[][] g = new int[n][n];
            for (var e : g) {
                Arrays.fill(e, 1 << 29);
            }
            for (var e : roads) {
                int u = e[0], v = e[1], w = e[2];
                if ((mask >> u & 1) == 1 && (mask >> v & 1) == 1) {
                    g[u][v] = Math.min(g[u][v], w);
                    g[v][u] = Math.min(g[v][u], w);
                }
            }
            for (int k = 0; k < n; ++k) {
                if ((mask >> k & 1) == 1) {
                    g[k][k] = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                            g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                        }
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < n && ok == 1; ++i) {
                for (int j = 0; j < n && ok == 1; ++j) {
                    if ((mask >> i & 1) == 1 && (mask >> j & 1) == 1) {
                        if (g[i][j] > maxDistance) {
                            ok = 0;
                        }
                    }
                }
            }
            ans += ok;
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
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int g[n][n];
            memset(g, 0x3f, sizeof(g));
            for (auto& e : roads) {
                int u = e[0], v = e[1], w = e[2];
                if ((mask >> u & 1) & (mask >> v & 1)) {
                    g[u][v] = min(g[u][v], w);
                    g[v][u] = min(g[v][u], w);
                }
            }
            for (int k = 0; k < n; ++k) {
                if (mask >> k & 1) {
                    g[k][k] = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                        }
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < n && ok == 1; ++i) {
                for (int j = 0; j < n && ok == 1; ++j) {
                    if ((mask >> i & 1) & (mask >> j & 1) && g[i][j] > maxDistance) {
                        ok = 0;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSets(n int, maxDistance int, roads [][]int) (ans int) {
	for mask := 0; mask < 1<<n; mask++ {
		g := make([][]int, n)
		for i := range g {
			g[i] = make([]int, n)
			for j := range g[i] {
				g[i][j] = 1 << 29
			}
		}
		for _, e := range roads {
			u, v, w := e[0], e[1], e[2]
			if mask>>u&1 == 1 && mask>>v&1 == 1 {
				g[u][v] = min(g[u][v], w)
				g[v][u] = min(g[v][u], w)
			}
		}
		for k := 0; k < n; k++ {
			if mask>>k&1 == 1 {
				g[k][k] = 0
				for i := 0; i < n; i++ {
					for j := 0; j < n; j++ {
						g[i][j] = min(g[i][j], g[i][k]+g[k][j])
					}
				}
			}
		}
		ok := 1
		for i := 0; i < n && ok == 1; i++ {
			for j := 0; j < n && ok == 1; j++ {
				if mask>>i&1 == 1 && mask>>j&1 == 1 && g[i][j] > maxDistance {
					ok = 0
				}
			}
		}
		ans += ok
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSets(n: number, maxDistance: number, roads: number[][]): number {
    let ans = 0;
    for (let mask = 0; mask < 1 << n; ++mask) {
        const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
        for (const [u, v, w] of roads) {
            if ((mask >> u) & 1 && (mask >> v) & 1) {
                g[u][v] = Math.min(g[u][v], w);
                g[v][u] = Math.min(g[v][u], w);
            }
        }
        for (let k = 0; k < n; ++k) {
            if ((mask >> k) & 1) {
                g[k][k] = 0;
                for (let i = 0; i < n; ++i) {
                    for (let j = 0; j < n; ++j) {
                        g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
        let ok = 1;
        for (let i = 0; i < n && ok; ++i) {
            for (let j = 0; j < n && ok; ++j) {
                if ((mask >> i) & 1 && (mask >> j) & 1 && g[i][j] > maxDistance) {
                    ok = 0;
                }
            }
        }
        ans += ok;
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

<p>一个公司在全国有 <code>n</code>&nbsp;个分部，它们之间有的有道路连接。一开始，所有分部通过这些道路两两之间互相可以到达。</p>

<p>公司意识到在分部之间旅行花费了太多时间，所以它们决定关闭一些分部（<b>也可能不关闭任何分部</b>），同时保证剩下的分部之间两两互相可以到达且最远距离不超过&nbsp;<code>maxDistance</code>&nbsp;。</p>

<p>两个分部之间的 <strong>距离</strong> 是通过道路长度之和的 <strong>最小值</strong>&nbsp;。</p>

<p>给你整数&nbsp;<code>n</code>&nbsp;，<code>maxDistance</code>&nbsp;和下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code>&nbsp;表示一条从&nbsp;<code>u<sub>i</sub></code>&nbsp;到&nbsp;<code>v<sub>i</sub></code>&nbsp;长度为&nbsp;<code>w<sub>i</sub></code>的&nbsp;<strong>无向</strong>&nbsp;道路。</p>

<p>请你返回关闭分部的可行方案数目，满足每个方案里剩余分部之间的最远距离不超过<em>&nbsp;</em><code>maxDistance</code>。</p>

<p><strong>注意</strong>，关闭一个分部后，与之相连的所有道路不可通行。</p>

<p><b>注意</b>，两个分部之间可能会有多条道路。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2959.Number%20of%20Possible%20Sets%20of%20Closing%20Branches/images/example11.png" style="width: 221px; height: 191px;" /></p>

<pre>
<b>输入：</b>n = 3, maxDistance = 5, roads = [[0,1,2],[1,2,10],[0,2,10]]
<b>输出：</b>5
<b>解释：</b>可行的关闭分部方案有：
- 关闭分部集合 [2] ，剩余分部为 [0,1] ，它们之间的距离为 2 。
- 关闭分部集合 [0,1] ，剩余分部为 [2] 。
- 关闭分部集合 [1,2] ，剩余分部为 [0] 。
- 关闭分部集合 [0,2] ，剩余分部为 [1] 。
- 关闭分部集合 [0,1,2] ，关闭后没有剩余分部。
总共有 5 种可行的关闭方案。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2959.Number%20of%20Possible%20Sets%20of%20Closing%20Branches/images/example22.png" style="width: 221px; height: 241px;" /></p>

<pre>
<b>输入：</b>n = 3, maxDistance = 5, roads = [[0,1,20],[0,1,10],[1,2,2],[0,2,2]]
<b>输出：</b>7
<b>解释：</b>可行的关闭分部方案有：
- 关闭分部集合 [] ，剩余分部为 [0,1,2] ，它们之间的最远距离为 4 。
- 关闭分部集合 [0] ，剩余分部为 [1,2] ，它们之间的距离为 2 。
- 关闭分部集合 [1] ，剩余分部为 [0,2] ，它们之间的距离为 2 。
- 关闭分部集合 [0,1] ，剩余分部为 [2] 。
- 关闭分部集合 [1,2] ，剩余分部为 [0] 。
- 关闭分部集合 [0,2] ，剩余分部为 [1] 。
- 关闭分部集合 [0,1,2] ，关闭后没有剩余分部。
总共有 7 种可行的关闭方案。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 1, maxDistance = 10, roads = []
<b>输出：</b>2
<b>解释：</b>可行的关闭分部方案有：
- 关闭分部集合 [] ，剩余分部为 [0] 。
- 关闭分部集合 [0] ，关闭后没有剩余分部。
总共有 2 种可行的关闭方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= maxDistance &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= roads.length &lt;= 1000</code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= 1000</code></li>
	<li>一开始所有分部之间通过道路互相可以到达。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举 + Floyd 算法

我们注意到 $n \leq 10$，所以我们不妨考虑使用二进制枚举的方法来枚举所有的分部集合。

对于每个分部集合，我们可以使用 Floyd 算法来计算出剩余分部之间的最短距离，然后判断是否满足题目要求即可。具体地，我们先枚举中间点 $k$，再枚举起点 $i$ 和终点 $j$，如果 $g[i][k] + g[k][j] \lt g[i][j]$，那么我们就用更短的距离 $g[i][k] + g[k][j]$ 更新 $g[i][j]$。

时间复杂度 $O(2^n \times (n^3 + m))$，空间复杂度 $O(n^2)$。其中 $n$ 和 $m$ 分别是分部数量和道路数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSets(self, n: int, maxDistance: int, roads: List[List[int]]) -> int:
        ans = 0
        for mask in range(1 << n):
            g = [[inf] * n for _ in range(n)]
            for u, v, w in roads:
                if mask >> u & 1 and mask >> v & 1:
                    g[u][v] = min(g[u][v], w)
                    g[v][u] = min(g[v][u], w)
            for k in range(n):
                if mask >> k & 1:
                    g[k][k] = 0
                    for i in range(n):
                        for j in range(n):
                            # g[i][j] = min(g[i][j], g[i][k] + g[k][j])
                            if g[i][k] + g[k][j] < g[i][j]:
                                g[i][j] = g[i][k] + g[k][j]
            if all(
                g[i][j] <= maxDistance
                for i in range(n)
                for j in range(n)
                if mask >> i & 1 and mask >> j & 1
            ):
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfSets(int n, int maxDistance, int[][] roads) {
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int[][] g = new int[n][n];
            for (var e : g) {
                Arrays.fill(e, 1 << 29);
            }
            for (var e : roads) {
                int u = e[0], v = e[1], w = e[2];
                if ((mask >> u & 1) == 1 && (mask >> v & 1) == 1) {
                    g[u][v] = Math.min(g[u][v], w);
                    g[v][u] = Math.min(g[v][u], w);
                }
            }
            for (int k = 0; k < n; ++k) {
                if ((mask >> k & 1) == 1) {
                    g[k][k] = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                            g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                        }
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < n && ok == 1; ++i) {
                for (int j = 0; j < n && ok == 1; ++j) {
                    if ((mask >> i & 1) == 1 && (mask >> j & 1) == 1) {
                        if (g[i][j] > maxDistance) {
                            ok = 0;
                        }
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            int g[n][n];
            memset(g, 0x3f, sizeof(g));
            for (auto& e : roads) {
                int u = e[0], v = e[1], w = e[2];
                if ((mask >> u & 1) & (mask >> v & 1)) {
                    g[u][v] = min(g[u][v], w);
                    g[v][u] = min(g[v][u], w);
                }
            }
            for (int k = 0; k < n; ++k) {
                if (mask >> k & 1) {
                    g[k][k] = 0;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                        }
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < n && ok == 1; ++i) {
                for (int j = 0; j < n && ok == 1; ++j) {
                    if ((mask >> i & 1) & (mask >> j & 1) && g[i][j] > maxDistance) {
                        ok = 0;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSets(n int, maxDistance int, roads [][]int) (ans int) {
	for mask := 0; mask < 1<<n; mask++ {
		g := make([][]int, n)
		for i := range g {
			g[i] = make([]int, n)
			for j := range g[i] {
				g[i][j] = 1 << 29
			}
		}
		for _, e := range roads {
			u, v, w := e[0], e[1], e[2]
			if mask>>u&1 == 1 && mask>>v&1 == 1 {
				g[u][v] = min(g[u][v], w)
				g[v][u] = min(g[v][u], w)
			}
		}
		for k := 0; k < n; k++ {
			if mask>>k&1 == 1 {
				g[k][k] = 0
				for i := 0; i < n; i++ {
					for j := 0; j < n; j++ {
						g[i][j] = min(g[i][j], g[i][k]+g[k][j])
					}
				}
			}
		}
		ok := 1
		for i := 0; i < n && ok == 1; i++ {
			for j := 0; j < n && ok == 1; j++ {
				if mask>>i&1 == 1 && mask>>j&1 == 1 && g[i][j] > maxDistance {
					ok = 0
				}
			}
		}
		ans += ok
	}
	return
}
```

#### TypeScript

```ts
function numberOfSets(n: number, maxDistance: number, roads: number[][]): number {
    let ans = 0;
    for (let mask = 0; mask < 1 << n; ++mask) {
        const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
        for (const [u, v, w] of roads) {
            if ((mask >> u) & 1 && (mask >> v) & 1) {
                g[u][v] = Math.min(g[u][v], w);
                g[v][u] = Math.min(g[v][u], w);
            }
        }
        for (let k = 0; k < n; ++k) {
            if ((mask >> k) & 1) {
                g[k][k] = 0;
                for (let i = 0; i < n; ++i) {
                    for (let j = 0; j < n; ++j) {
                        g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
        let ok = 1;
        for (let i = 0; i < n && ok; ++i) {
            for (let j = 0; j < n && ok; ++j) {
                if ((mask >> i) & 1 && (mask >> j) & 1 && g[i][j] > maxDistance) {
                    ok = 0;
                }
            }
        }
        ans += ok;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
