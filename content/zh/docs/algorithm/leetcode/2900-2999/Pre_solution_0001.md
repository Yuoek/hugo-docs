---
title: "2900_最长相邻不相等子序列 I"
date: 2025-10-08T18:39:48+08:00
weight: 1
tags: [前缀和, 动态规划, 双指针, 哈希表, 字符串, 数组, 树状数组, 滑动窗口, 矩阵, 线段树, 贪心]
---

{{< markmap >}}
### [2900_最长相邻不相等子序列 I](#2900)
#### [贪心](#2900)
#### [数组](#2900)
#### [字符串](#2900)
#### [动态规划](#2900)
### [2901_最长相邻不相等子序列 II](#2901)
#### [数组](#2901)
#### [字符串](#2901)
#### [动态规划](#2901)
### [2902_和带限制的子多重集合的数目](#2902)
#### [数组](#2902)
#### [哈希表](#2902)
#### [动态规划](#2902)
#### [滑动窗口](#2902)
### [2903_找出满足差值条件的下标 I](#2903)
#### [数组](#2903)
#### [双指针](#2903)
### [2904_最短且字典序最小的美丽子字符串](#2904)
#### [字符串](#2904)
#### [滑动窗口](#2904)
### [2905_找出满足差值条件的下标 II](#2905)
#### [数组](#2905)
#### [双指针](#2905)
### [2906_构造乘积矩阵](#2906)
#### [数组](#2906)
#### [矩阵](#2906)
#### [前缀和](#2906)
### [2907_价格递增的最大利润三元组 I 🔒](#2907)
#### [树状数组](#2907)
#### [线段树](#2907)
#### [数组](#2907)
### [2908_元素和最小的山形三元组 I](#2908)
#### [数组](#2908)
### [2909_元素和最小的山形三元组 II](#2909)
#### [数组](#2909)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2900_最长相邻不相等子序列 I
___
#### 贪心
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 2901_最长相邻不相等子序列 II
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 2902_和带限制的子多重集合的数目
___
#### 数组
___
#### 哈希表
___
#### 动态规划
___
#### 滑动窗口
---
### 2903_找出满足差值条件的下标 I
___
#### 数组
___
#### 双指针
---
### 2904_最短且字典序最小的美丽子字符串
___
#### 字符串
___
#### 滑动窗口
---
### 2905_找出满足差值条件的下标 II
___
#### 数组
___
#### 双指针
---
### 2906_构造乘积矩阵
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 2907_价格递增的最大利润三元组 I 🔒
___
#### 树状数组
___
#### 线段树
___
#### 数组
---
### 2908_元素和最小的山形三元组 I
___
#### 数组
---
### 2909_元素和最小的山形三元组 II
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 双指针 |
| 哈希表 | 字符串 | 数组 |
| 树状数组 | 滑动窗口 | 矩阵 |
| 线段树 | 贪心 |  |

# [2900. 最长相邻不相等子序列 I](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i){#2900}

{{< tabs "2900" >}}

{{% tab "python" %}}
```python
class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        return [words[i] for i, x in enumerate(groups) if i == 0 or x != groups[i - 1]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        int n = groups.length;
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.add(words[i]);
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
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getLongestSubsequence(words []string, groups []int) (ans []string) {
	for i, x := range groups {
		if i == 0 || x != groups[i-1] {
			ans = append(ans, words[i])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getLongestSubsequence(words: string[], groups: number[]): string[] {
    const ans: string[] = [];
    for (let i = 0; i < groups.length; ++i) {
        if (i === 0 || groups[i] !== groups[i - 1]) {
            ans.push(words[i]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let mut ans = Vec::new();
        for (i, &g) in groups.iter().enumerate() {
            if i == 0 || g != groups[i - 1] {
                ans.push(words[i].clone());
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

<p>给定一个字符串数组&nbsp;<code>words</code>&nbsp;，和一个&nbsp;<strong>二进制</strong>&nbsp;数组&nbsp;<code>groups</code>&nbsp;，两个数组长度都是&nbsp;<code>n</code>&nbsp;。</p>

<p>如果&nbsp;<code>words</code>&nbsp;的一个 <span data-keyword="subsequence-array">子序列</span> 是交替的，那么对于序列中的任意两个连续字符串，它们在&nbsp;<code>groups</code>&nbsp;中相同索引的对应元素是 <strong>不同</strong> 的（也就是说，不能有连续的 0 或 1），</p>

<p>你需要从&nbsp;<code>words</code>&nbsp;中选出&nbsp;<strong>最长交替<span data-keyword="subsequence-array">子序列</span></strong>。</p>

<p>返回选出的子序列。如果有多个答案，返回 <strong>任意</strong> 一个。</p>

<p><b>注意：</b><code>words</code>&nbsp;中的元素是不同的&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["e","a","b"], groups = [0,0,1]
<b>输出：</b>["e","b"]
<strong>解释：</strong>一个可行的子序列是 [0,2] ，因为 groups[0] != groups[2] 。
所以一个可行的答案是 [words[0],words[2]] = ["e","b"] 。
另一个可行的子序列是 [1,2] ，因为 groups[1] != groups[2] 。
得到答案为 [words[1],words[2]] = ["a","b"] 。
这也是一个可行的答案。
符合题意的最长子序列的长度为 2 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["a","b","c","d"], groups = [1,0,1,1]
<b>输出：</b>["a","b","c"]
<b>解释：</b>一个可行的子序列为 [0,1,2] 因为 groups[0] != groups[1] 且 groups[1] != groups[2] 。
所以一个可行的答案是 [words[0],words[1],words[2]] = ["a","b","c"] 。
另一个可行的子序列为 [0,1,3] 因为 groups[0] != groups[1] 且 groups[1] != groups[3] 。
得到答案为 [words[0],words[1],words[3]] = ["a","b","d"] 。
这也是一个可行的答案。
符合题意的最长子序列的长度为 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == words.length == groups.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>groups[i]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li><code>words</code>&nbsp;中的字符串 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 一次遍历

我们可以遍历数组 $groups$，对于当前遍历到的下标 $i$，如果 $i=0$ 或者 $groups[i] \neq groups[i - 1]$，我们就将 $words[i]$ 加入答案数组中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $groups$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        return [words[i] for i, x in enumerate(groups) if i == 0 or x != groups[i - 1]]
```

#### Java

```java
class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        int n = groups.length;
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.add(words[i]);
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
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getLongestSubsequence(words []string, groups []int) (ans []string) {
	for i, x := range groups {
		if i == 0 || x != groups[i-1] {
			ans = append(ans, words[i])
		}
	}
	return
}
```

#### TypeScript

```ts
function getLongestSubsequence(words: string[], groups: number[]): string[] {
    const ans: string[] = [];
    for (let i = 0; i < groups.length; ++i) {
        if (i === 0 || groups[i] !== groups[i - 1]) {
            ans.push(words[i]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let mut ans = Vec::new();
        for (i, &g) in groups.iter().enumerate() {
            if i == 0 || g != groups[i - 1] {
                ans.push(words[i].clone());
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

# [2901. 最长相邻不相等子序列 II](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii){#2901}

{{< tabs "2901" >}}

{{% tab "python" %}}
```python
class Solution:
    def getWordsInLongestSubsequence(
        self, words: List[str], groups: List[int]
    ) -> List[str]:
        def check(s: str, t: str) -> bool:
            return len(s) == len(t) and sum(a != b for a, b in zip(s, t)) == 1

        n = len(groups)
        f = [1] * n
        g = [-1] * n
        mx = 1
        for i, x in enumerate(groups):
            for j, y in enumerate(groups[:i]):
                if x != y and f[i] < f[j] + 1 and check(words[i], words[j]):
                    f[i] = f[j] + 1
                    g[i] = j
                    mx = max(mx, f[i])
        ans = []
        for i in range(n):
            if f[i] == mx:
                j = i
                while j >= 0:
                    ans.append(words[j])
                    j = g[j]
                break
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int n = groups.length;
        int[] f = new int[n];
        int[] g = new int[n];
        Arrays.fill(f, 1);
        Arrays.fill(g, -1);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                    mx = Math.max(mx, f[i]);
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (f[i] == mx) {
                for (int j = i; j >= 0; j = g[j]) {
                    ans.add(words[j]);
                }
                break;
            }
        }
        Collections.reverse(ans);
        return ans;
    }

    private boolean check(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != t.charAt(i)) {
                ++cnt;
            }
        }
        return cnt == 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto check = [](string& s, string& t) {
            if (s.size() != t.size()) {
                return false;
            }
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                cnt += s[i] != t[i];
            }
            return cnt == 1;
        };
        int n = groups.size();
        vector<int> f(n, 1);
        vector<int> g(n, -1);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                    mx = max(mx, f[i]);
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (f[i] == mx) {
                for (int j = i; ~j; j = g[j]) {
                    ans.emplace_back(words[j]);
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getWordsInLongestSubsequence(words []string, groups []int) []string {
	check := func(s, t string) bool {
		if len(s) != len(t) {
			return false
		}
		cnt := 0
		for i := range s {
			if s[i] != t[i] {
				cnt++
			}
		}
		return cnt == 1
	}
	n := len(groups)
	f := make([]int, n)
	g := make([]int, n)
	for i := range f {
		f[i] = 1
		g[i] = -1
	}
	mx := 1
	for i, x := range groups {
		for j, y := range groups[:i] {
			if x != y && f[i] < f[j]+1 && check(words[i], words[j]) {
				f[i] = f[j] + 1
				g[i] = j
				if mx < f[i] {
					mx = f[i]
				}
			}
		}
	}
	ans := make([]string, 0, mx)
	for i, x := range f {
		if x == mx {
			for j := i; j >= 0; j = g[j] {
				ans = append(ans, words[j])
			}
			break
		}
	}
	slices.Reverse(ans)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getWordsInLongestSubsequence(words: string[], groups: number[]): string[] {
    const n = groups.length;
    const f: number[] = Array(n).fill(1);
    const g: number[] = Array(n).fill(-1);
    let mx = 1;
    const check = (s: string, t: string) => {
        if (s.length !== t.length) {
            return false;
        }
        let cnt = 0;
        for (let i = 0; i < s.length; ++i) {
            if (s[i] !== t[i]) {
                ++cnt;
            }
        }
        return cnt === 1;
    };
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (groups[i] !== groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                f[i] = f[j] + 1;
                g[i] = j;
                mx = Math.max(mx, f[i]);
            }
        }
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ++i) {
        if (f[i] === mx) {
            for (let j = i; ~j; j = g[j]) {
                ans.push(words[j]);
            }
            break;
        }
    }
    return ans.reverse();
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_words_in_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        fn check(s: &str, t: &str) -> bool {
            s.len() == t.len() && s.chars().zip(t.chars()).filter(|(a, b)| a != b).count() == 1
        }

        let n = groups.len();

        let mut f = vec![1; n];
        let mut g = vec![-1; n];

        let mut mx = 1;

        for i in 0..n {
            let x = groups[i] as usize;
            for j in 0..i {
                let y = groups[j] as usize;
                if x != y && f[i] < f[j] + 1 && check(&words[i], &words[j]) {
                    f[i] = f[j] + 1;
                    g[i] = j as i32;
                    mx = mx.max(f[i]);
                }
            }
        }

        let mut ans = vec![];
        let mut i = n - 1;

        while f[i] != mx {
            i -= 1;
        }

        let mut j = i as i32;
        while j >= 0 {
            ans.push(words[j as usize].clone());
            j = g[j as usize];
        }

        ans.reverse();
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

<p>给定一个字符串数组&nbsp;<code>words</code>&nbsp;，和一个数组&nbsp;<code>groups</code>&nbsp;，两个数组长度都是&nbsp;<code>n</code>&nbsp;。</p>

<p>两个长度相等字符串的 <strong>汉明距离</strong>&nbsp;定义为对应位置字符&nbsp;<strong>不同</strong>&nbsp;的数目。</p>

<p>你需要从下标&nbsp;<code>[0, 1, ..., n - 1]</code>&nbsp;中选出一个&nbsp;<strong>最长<span data-keyword="subsequence-array">子序列</span></strong>&nbsp;，将这个子序列记作长度为 <code>k</code> 的&nbsp;<code>[i<sub>0</sub>, i<sub>1</sub>, ..., i<sub>k - 1</sub>]</code>&nbsp;，它需要满足以下条件：</p>

<ul>
	<li><strong>相邻</strong> 下标对应的 <code>groups</code> 值 <strong>不同</strong>。即，对于所有满足&nbsp;<code>0 &lt; j + 1 &lt; k</code>&nbsp;的&nbsp;<code>j</code>&nbsp;都有&nbsp;<code>groups[i<sub>j</sub>] != groups[i<sub>j + 1</sub>]</code>&nbsp;。</li>
	<li>对于所有&nbsp;<code>0 &lt; j + 1 &lt; k</code>&nbsp;的下标&nbsp;<code>j</code>&nbsp;，都满足&nbsp;<code>words[i<sub>j</sub>]</code> 和&nbsp;<code>words[i<sub>j + 1</sub>]</code>&nbsp;的长度 <strong>相等</strong>&nbsp;，且两个字符串之间的 <strong>汉明距离</strong>&nbsp;为 <code>1</code>&nbsp;。</li>
</ul>

<p>请你返回一个字符串数组，它是下标子序列&nbsp;<strong>依次</strong>&nbsp;对应&nbsp;<code>words</code>&nbsp;数组中的字符串连接形成的字符串数组。如果有多个答案，返回任意一个。</p>

<p><strong>子序列</strong>&nbsp;指的是从原数组中删掉一些（也可能一个也不删掉）元素，剩余元素不改变相对位置得到的新的数组。</p>

<p><b>注意：</b><code>words</code>&nbsp;中的字符串长度可能&nbsp;<strong>不相等</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["bab","dab","cab"], groups = [1,2,2]
<b>输出：</b>["bab","cab"]
<b>解释：</b>一个可行的子序列是 [0,2] 。
- groups[0] != groups[2]
- words[0].length == words[2].length 且它们之间的汉明距离为 1 。
所以一个可行的答案是 [words[0],words[2]] = ["bab","cab"] 。
另一个可行的子序列是 [0,1] 。
- groups[0] != groups[1]
- words[0].length = words[1].length 且它们之间的汉明距离为 1 。
所以另一个可行的答案是 [words[0],words[1]] = ["bab","dab"] 。
符合题意的最长子序列的长度为 2 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["a","b","c","d"], groups = [1,2,3,4]
<b>输出：</b>["a","b","c","d"]
<b>解释：</b>我们选择子序列 [0,1,2,3] 。
它同时满足两个条件。
所以答案为 [words[0],words[1],words[2],words[3]] = ["a","b","c","d"] 。
它是所有下标子序列里最长且满足所有条件的。
所以它是唯一的答案。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= n == words.length == groups.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= groups[i] &lt;= n</code></li>
	<li><code>words</code>&nbsp;中的字符串&nbsp;<strong>互不相同</strong>&nbsp;。</li>
	<li><code>words[i]</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以第 $i$ 个单词结尾的最长相邻不相等子序列的长度，定义 $g[i]$ 表示以第 $i$ 个单词结尾的最长相邻不相等子序列的前驱下标。初始时 $f[i] = 1$, $g[i] = -1$。

另外，我们定义一个变量 $mx$ 表示最长相邻不相等子序列的长度。

我们枚举 $i$，枚举 $j \in [0, i)$，如果 $groups[i] \neq groups[j]$ 且 $f[i] \lt f[j] + 1$ 且 $words[i]$ 和 $words[j]$ 之间的汉明距离为 $1$，则更新 $f[i] = f[j] + 1$，$g[i] = j$，并且更新 $mx = \max(mx, f[i])$。

最后，我们从 $f$ 数组中找到最大值对应的下标 $i$，然后从 $i$ 开始不断往前找，直到找到 $g[i] = -1$，这样就找到了最长相邻不相等子序列。

时间复杂度 $O(n^2 \times L)$，空间复杂度 $O(n)$。其中 $L$ 表示单词的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getWordsInLongestSubsequence(
        self, words: List[str], groups: List[int]
    ) -> List[str]:
        def check(s: str, t: str) -> bool:
            return len(s) == len(t) and sum(a != b for a, b in zip(s, t)) == 1

        n = len(groups)
        f = [1] * n
        g = [-1] * n
        mx = 1
        for i, x in enumerate(groups):
            for j, y in enumerate(groups[:i]):
                if x != y and f[i] < f[j] + 1 and check(words[i], words[j]):
                    f[i] = f[j] + 1
                    g[i] = j
                    mx = max(mx, f[i])
        ans = []
        for i in range(n):
            if f[i] == mx:
                j = i
                while j >= 0:
                    ans.append(words[j])
                    j = g[j]
                break
        return ans[::-1]
```

#### Java

```java
class Solution {
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int n = groups.length;
        int[] f = new int[n];
        int[] g = new int[n];
        Arrays.fill(f, 1);
        Arrays.fill(g, -1);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                    mx = Math.max(mx, f[i]);
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (f[i] == mx) {
                for (int j = i; j >= 0; j = g[j]) {
                    ans.add(words[j]);
                }
                break;
            }
        }
        Collections.reverse(ans);
        return ans;
    }

    private boolean check(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != t.charAt(i)) {
                ++cnt;
            }
        }
        return cnt == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto check = [](string& s, string& t) {
            if (s.size() != t.size()) {
                return false;
            }
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                cnt += s[i] != t[i];
            }
            return cnt == 1;
        };
        int n = groups.size();
        vector<int> f(n, 1);
        vector<int> g(n, -1);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                    mx = max(mx, f[i]);
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (f[i] == mx) {
                for (int j = i; ~j; j = g[j]) {
                    ans.emplace_back(words[j]);
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func getWordsInLongestSubsequence(words []string, groups []int) []string {
	check := func(s, t string) bool {
		if len(s) != len(t) {
			return false
		}
		cnt := 0
		for i := range s {
			if s[i] != t[i] {
				cnt++
			}
		}
		return cnt == 1
	}
	n := len(groups)
	f := make([]int, n)
	g := make([]int, n)
	for i := range f {
		f[i] = 1
		g[i] = -1
	}
	mx := 1
	for i, x := range groups {
		for j, y := range groups[:i] {
			if x != y && f[i] < f[j]+1 && check(words[i], words[j]) {
				f[i] = f[j] + 1
				g[i] = j
				if mx < f[i] {
					mx = f[i]
				}
			}
		}
	}
	ans := make([]string, 0, mx)
	for i, x := range f {
		if x == mx {
			for j := i; j >= 0; j = g[j] {
				ans = append(ans, words[j])
			}
			break
		}
	}
	slices.Reverse(ans)
	return ans
}
```

#### TypeScript

```ts
function getWordsInLongestSubsequence(words: string[], groups: number[]): string[] {
    const n = groups.length;
    const f: number[] = Array(n).fill(1);
    const g: number[] = Array(n).fill(-1);
    let mx = 1;
    const check = (s: string, t: string) => {
        if (s.length !== t.length) {
            return false;
        }
        let cnt = 0;
        for (let i = 0; i < s.length; ++i) {
            if (s[i] !== t[i]) {
                ++cnt;
            }
        }
        return cnt === 1;
    };
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (groups[i] !== groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                f[i] = f[j] + 1;
                g[i] = j;
                mx = Math.max(mx, f[i]);
            }
        }
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ++i) {
        if (f[i] === mx) {
            for (let j = i; ~j; j = g[j]) {
                ans.push(words[j]);
            }
            break;
        }
    }
    return ans.reverse();
}
```

#### Rust

```rust
impl Solution {
    pub fn get_words_in_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        fn check(s: &str, t: &str) -> bool {
            s.len() == t.len() && s.chars().zip(t.chars()).filter(|(a, b)| a != b).count() == 1
        }

        let n = groups.len();

        let mut f = vec![1; n];
        let mut g = vec![-1; n];

        let mut mx = 1;

        for i in 0..n {
            let x = groups[i] as usize;
            for j in 0..i {
                let y = groups[j] as usize;
                if x != y && f[i] < f[j] + 1 && check(&words[i], &words[j]) {
                    f[i] = f[j] + 1;
                    g[i] = j as i32;
                    mx = mx.max(f[i]);
                }
            }
        }

        let mut ans = vec![];
        let mut i = n - 1;

        while f[i] != mx {
            i -= 1;
        }

        let mut j = i as i32;
        while j >= 0 {
            ans.push(words[j as usize].clone());
            j = g[j as usize];
        }

        ans.reverse();
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2902. 和带限制的子多重集合的数目](https://leetcode.cn/problems/count-of-sub-multisets-with-bounded-sum){#2902}

{{< tabs "2902" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubMultisets(self, nums: List[int], l: int, r: int) -> int:
        kMod = 1_000_000_007
        # dp[i] := # of submultisets of nums with sum i
        dp = [1] + [0] * r
        count = collections.Counter(nums)
        zeros = count.pop(0, 0)

        for num, freq in count.items():
            # stride[i] := dp[i] + dp[i - num] + dp[i - 2 * num] + ...
            stride = dp.copy()
            for i in range(num, r + 1):
                stride[i] += stride[i - num]
            for i in range(r, 0, -1):
                if i >= num * (freq + 1):
                    # dp[i] + dp[i - num] + dp[i - freq * num]
                    dp[i] = stride[i] - stride[i - num * (freq + 1)]
                else:
                    dp[i] = stride[i]

        return (zeros + 1) * sum(dp[l : r + 1]) % kMod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    static final int MOD = 1_000_000_007;
    public int countSubMultisets(List<Integer> nums, int l, int r) {
        Map<Integer, Integer> count = new HashMap<>();
        int total = 0;
        for (int num : nums) {
            total += num;
            if (num <= r) {
                count.merge(num, 1, Integer::sum);
            }
        }
        if (total < l) {
            return 0;
        }
        r = Math.min(r, total);
        int[] dp = new int[r + 1];
        dp[0] = count.getOrDefault(0, 0) + 1;
        count.remove(Integer.valueOf(0));
        int sum = 0;
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            int num = e.getKey();
            int c = e.getValue();
            sum = Math.min(sum + c * num, r);
            // prefix part
            // dp[i] = dp[i] + dp[i - num] + ... + dp[i - c*num] + dp[i-(c+1)*num] + ... + dp[i %
            // num]
            for (int i = num; i <= sum; i++) {
                dp[i] = (dp[i] + dp[i - num]) % MOD;
            }
            int temp = (c + 1) * num;
            // correction part
            // subtract dp[i - (freq + 1) * num] to the end part.
            // leves dp[i] = dp[i] + dp[i-num] +...+ dp[i - c*num];
            for (int i = sum; i >= temp; i--) {
                dp[i] = (dp[i] - dp[i - temp] + MOD) % MOD;
            }
        }
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += dp[i];
            ans %= MOD;
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
    int countSubMultisets(const vector<int> &nums, int l, int r) {
        int cnt[20001] = {};
        int memo[20001] = {};
        const int mod = 1000000007;
        for (int n : nums) {
            ++cnt[n];
        }
        fill_n(memo, cnt[1] + 1, 1);
        for (int n = 2, total = cnt[1]; n <= r; ++n) {
            if (!cnt[n]) {
                continue;
            }
            int top = (cnt[n] + 1) * n;
            total += n * cnt[n];
            for (int i = n, ii = min(total, r); i <= ii; ++i) {
                memo[i] = (memo[i] + memo[i - n]) % mod;
            }
            for (int i = min(total, r); i >= top; --i) {
                memo[i] = (mod + memo[i] - memo[i - top]) % mod;
            }
        }
        return accumulate(memo + l, memo + r + 1, 0LL) * (cnt[0] + 1) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubMultisets(nums []int, l int, r int) int {
	multiset := make(map[int]int)
	for _, num := range nums {
		multiset[num]++
	}
	mem := make([]int, r+1)
	mem[0] = 1
	prefix := make([]int, len(mem))
	for num, occ := range multiset {
		copy(prefix, mem)
		for sum := num; sum <= r; sum++ {
			prefix[sum] = (prefix[sum] + prefix[sum-num]) % mod
		}
		for sum := r; sum >= 0; sum-- {
			if num > 0 {
				mem[sum] = prefix[sum]
				if sum >= num*(occ+1) {
					mem[sum] = (mem[sum] - prefix[sum-num*(occ+1)] + mod) % mod
				}
			} else {
				mem[sum] = (mem[sum] * (occ + 1)) % mod
			}
		}
	}
	var result int
	for sum := l; sum <= r; sum++ {
		result = (result + mem[sum]) % mod
	}
	return result
}
var mod int = 1e9 + 7
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubMultisets(nums: number[], l: number, r: number): number {
    const cnt: number[] = Array(20001).fill(0);
    const memo: number[] = Array(20001).fill(0);
    const mod: number = 1000000007;
    for (const n of nums) {
        cnt[n]++;
    }
    memo.fill(1, 0, cnt[1] + 1);
    let total: number = cnt[1];
    for (let n = 2; n <= r; ++n) {
        if (!cnt[n]) {
            continue;
        }
        const top: number = (cnt[n] + 1) * n;
        total += n * cnt[n];
        for (let i = n, ii = Math.min(total, r); i <= ii; ++i) {
            memo[i] = (memo[i] + memo[i - n]) % mod;
        }
        for (let i = Math.min(total, r); i >= top; --i) {
            memo[i] = (mod + memo[i] - memo[i - top]) % mod;
        }
    }
    let result: number = 0;
    for (let i = l; i <= r; i++) {
        result = (result + memo[i]) % mod;
    }
    return (result * (cnt[0] + 1)) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的非负整数数组&nbsp;<code>nums</code>&nbsp;和两个整数&nbsp;<code>l</code> 和&nbsp;<code>r</code>&nbsp;。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中子多重集合的和在闭区间&nbsp;<code>[l, r]</code>&nbsp;之间的 <strong>子多重集合的数目</strong> 。</p>

<p>由于答案可能很大，请你将答案对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;取余后返回。</p>

<p><strong>子多重集合</strong> 指的是从数组中选出一些元素构成的 <strong>无序</strong>&nbsp;集合，每个元素 <code>x</code>&nbsp;出现的次数可以是&nbsp;<code>0, 1, ..., occ[x]</code>&nbsp;次，其中&nbsp;<code>occ[x]</code>&nbsp;是元素&nbsp;<code>x</code>&nbsp;在数组中的出现次数。</p>

<p><b>注意：</b></p>

<ul>
	<li>如果两个子多重集合中的元素排序后一模一样，那么它们两个是相同的&nbsp;<strong>子多重集合</strong>&nbsp;。</li>
	<li><strong>空</strong>&nbsp;集合的和是 <code>0</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,2,3], l = 6, r = 6
<b>输出：</b>1
<b>解释：</b>唯一和为 6 的子集合是 {1, 2, 3} 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,4,2,7], l = 1, r = 5
<b>输出：</b>7
<b>解释：</b>和在闭区间 [1, 5] 之间的子多重集合为 {1} ，{2} ，{4} ，{2, 2} ，{1, 2} ，{1, 4} 和 {1, 2, 2} 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1,3,5,2], l = 3, r = 5
<b>输出：</b>9
<b>解释：</b>和在闭区间 [3, 5] 之间的子多重集合为 {3} ，{5} ，{1, 2} ，{1, 3} ，{2, 2} ，{2, 3} ，{1, 1, 2} ，{1, 1, 3} 和 {1, 2, 2} 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>nums</code> 的和不超过&nbsp;<code>2 * 10<sup>4</sup></code> 。</li>
	<li><code>0 &lt;= l &lt;= r &lt;= 2 * 10<sup>4</sup></code></li>
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
    def countSubMultisets(self, nums: List[int], l: int, r: int) -> int:
        kMod = 1_000_000_007
        # dp[i] := # of submultisets of nums with sum i
        dp = [1] + [0] * r
        count = collections.Counter(nums)
        zeros = count.pop(0, 0)

        for num, freq in count.items():
            # stride[i] := dp[i] + dp[i - num] + dp[i - 2 * num] + ...
            stride = dp.copy()
            for i in range(num, r + 1):
                stride[i] += stride[i - num]
            for i in range(r, 0, -1):
                if i >= num * (freq + 1):
                    # dp[i] + dp[i - num] + dp[i - freq * num]
                    dp[i] = stride[i] - stride[i - num * (freq + 1)]
                else:
                    dp[i] = stride[i]

        return (zeros + 1) * sum(dp[l : r + 1]) % kMod
```

#### Java

```java
class Solution {
    static final int MOD = 1_000_000_007;
    public int countSubMultisets(List<Integer> nums, int l, int r) {
        Map<Integer, Integer> count = new HashMap<>();
        int total = 0;
        for (int num : nums) {
            total += num;
            if (num <= r) {
                count.merge(num, 1, Integer::sum);
            }
        }
        if (total < l) {
            return 0;
        }
        r = Math.min(r, total);
        int[] dp = new int[r + 1];
        dp[0] = count.getOrDefault(0, 0) + 1;
        count.remove(Integer.valueOf(0));
        int sum = 0;
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            int num = e.getKey();
            int c = e.getValue();
            sum = Math.min(sum + c * num, r);
            // prefix part
            // dp[i] = dp[i] + dp[i - num] + ... + dp[i - c*num] + dp[i-(c+1)*num] + ... + dp[i %
            // num]
            for (int i = num; i <= sum; i++) {
                dp[i] = (dp[i] + dp[i - num]) % MOD;
            }
            int temp = (c + 1) * num;
            // correction part
            // subtract dp[i - (freq + 1) * num] to the end part.
            // leves dp[i] = dp[i] + dp[i-num] +...+ dp[i - c*num];
            for (int i = sum; i >= temp; i--) {
                dp[i] = (dp[i] - dp[i - temp] + MOD) % MOD;
            }
        }
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSubMultisets(const vector<int> &nums, int l, int r) {
        int cnt[20001] = {};
        int memo[20001] = {};
        const int mod = 1000000007;
        for (int n : nums) {
            ++cnt[n];
        }
        fill_n(memo, cnt[1] + 1, 1);
        for (int n = 2, total = cnt[1]; n <= r; ++n) {
            if (!cnt[n]) {
                continue;
            }
            int top = (cnt[n] + 1) * n;
            total += n * cnt[n];
            for (int i = n, ii = min(total, r); i <= ii; ++i) {
                memo[i] = (memo[i] + memo[i - n]) % mod;
            }
            for (int i = min(total, r); i >= top; --i) {
                memo[i] = (mod + memo[i] - memo[i - top]) % mod;
            }
        }
        return accumulate(memo + l, memo + r + 1, 0LL) * (cnt[0] + 1) % mod;
    }
};
```

#### Go

```go
func countSubMultisets(nums []int, l int, r int) int {
	multiset := make(map[int]int)
	for _, num := range nums {
		multiset[num]++
	}
	mem := make([]int, r+1)
	mem[0] = 1
	prefix := make([]int, len(mem))
	for num, occ := range multiset {
		copy(prefix, mem)
		for sum := num; sum <= r; sum++ {
			prefix[sum] = (prefix[sum] + prefix[sum-num]) % mod
		}
		for sum := r; sum >= 0; sum-- {
			if num > 0 {
				mem[sum] = prefix[sum]
				if sum >= num*(occ+1) {
					mem[sum] = (mem[sum] - prefix[sum-num*(occ+1)] + mod) % mod
				}
			} else {
				mem[sum] = (mem[sum] * (occ + 1)) % mod
			}
		}
	}
	var result int
	for sum := l; sum <= r; sum++ {
		result = (result + mem[sum]) % mod
	}
	return result
}
var mod int = 1e9 + 7
```

#### TypeScript

```ts
function countSubMultisets(nums: number[], l: number, r: number): number {
    const cnt: number[] = Array(20001).fill(0);
    const memo: number[] = Array(20001).fill(0);
    const mod: number = 1000000007;
    for (const n of nums) {
        cnt[n]++;
    }
    memo.fill(1, 0, cnt[1] + 1);
    let total: number = cnt[1];
    for (let n = 2; n <= r; ++n) {
        if (!cnt[n]) {
            continue;
        }
        const top: number = (cnt[n] + 1) * n;
        total += n * cnt[n];
        for (let i = n, ii = Math.min(total, r); i <= ii; ++i) {
            memo[i] = (memo[i] + memo[i - n]) % mod;
        }
        for (let i = Math.min(total, r); i >= top; --i) {
            memo[i] = (mod + memo[i] - memo[i - top]) % mod;
        }
    }
    let result: number = 0;
    for (let i = l; i <= r; i++) {
        result = (result + memo[i]) % mod;
    }
    return (result * (cnt[0] + 1)) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2903. 找出满足差值条件的下标 I](https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i){#2903}

{{< tabs "2903" >}}

{{% tab "python" %}}
```python
class Solution:
    def findIndices(
        self, nums: List[int], indexDifference: int, valueDifference: int
    ) -> List[int]:
        mi = mx = 0
        for i in range(indexDifference, len(nums)):
            j = i - indexDifference
            if nums[j] < nums[mi]:
                mi = j
            if nums[j] > nums[mx]:
                mx = j
            if nums[i] - nums[mi] >= valueDifference:
                return [mi, i]
            if nums[mx] - nums[i] >= valueDifference:
                return [mx, i]
        return [-1, -1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int mi = 0;
        int mx = 0;
        for (int i = indexDifference; i < nums.length; ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return new int[] {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return new int[] {mx, i};
            }
        }
        return new int[] {-1, -1};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mi = 0, mx = 0;
        for (int i = indexDifference; i < nums.size(); ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return {mx, i};
            }
        }
        return {-1, -1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findIndices(nums []int, indexDifference int, valueDifference int) []int {
	mi, mx := 0, 0
	for i := indexDifference; i < len(nums); i++ {
		j := i - indexDifference
		if nums[j] < nums[mi] {
			mi = j
		}
		if nums[j] > nums[mx] {
			mx = j
		}
		if nums[i]-nums[mi] >= valueDifference {
			return []int{mi, i}
		}
		if nums[mx]-nums[i] >= valueDifference {
			return []int{mx, i}
		}
	}
	return []int{-1, -1}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findIndices(nums: number[], indexDifference: number, valueDifference: number): number[] {
    let [mi, mx] = [0, 0];
    for (let i = indexDifference; i < nums.length; ++i) {
        const j = i - indexDifference;
        if (nums[j] < nums[mi]) {
            mi = j;
        }
        if (nums[j] > nums[mx]) {
            mx = j;
        }
        if (nums[i] - nums[mi] >= valueDifference) {
            return [mi, i];
        }
        if (nums[mx] - nums[i] >= valueDifference) {
            return [mx, i];
        }
    }
    return [-1, -1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_indices(nums: Vec<i32>, index_difference: i32, value_difference: i32) -> Vec<i32> {
        let index_difference = index_difference as usize;
        let mut mi = 0;
        let mut mx = 0;

        for i in index_difference..nums.len() {
            let j = i - index_difference;

            if nums[j] < nums[mi] {
                mi = j;
            }

            if nums[j] > nums[mx] {
                mx = j;
            }

            if nums[i] - nums[mi] >= value_difference {
                return vec![mi as i32, i as i32];
            }

            if nums[mx] - nums[i] >= value_difference {
                return vec![mx as i32, i as i32];
            }
        }

        vec![-1, -1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> ，以及整数 <code>indexDifference</code> 和整数 <code>valueDifference</code> 。</p>

<p>你的任务是从范围 <code>[0, n - 1]</code> 内找出&nbsp; <strong>2</strong> 个满足下述所有条件的下标 <code>i</code> 和 <code>j</code> ：</p>

<ul>
	<li><code>abs(i - j) &gt;= indexDifference</code> 且</li>
	<li><code>abs(nums[i] - nums[j]) &gt;= valueDifference</code></li>
</ul>

<p>返回整数数组 <code>answer</code>。如果存在满足题目要求的两个下标，则 <code>answer = [i, j]</code> ；否则，<code>answer = [-1, -1]</code> 。如果存在多组可供选择的下标对，只需要返回其中任意一组即可。</p>

<p><strong>注意：</strong><code>i</code> 和 <code>j</code> 可能 <strong>相等</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
<strong>输出：</strong>[0,3]
<strong>解释：</strong>在示例中，可以选择 i = 0 和 j = 3 。
abs(0 - 3) &gt;= 2 且 abs(nums[0] - nums[3]) &gt;= 4 。
因此，[0,3] 是一个符合题目要求的答案。
[3,0] 也是符合题目要求的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1], indexDifference = 0, valueDifference = 0
<strong>输出：</strong>[0,0]
<strong>解释：</strong>
在示例中，可以选择 i = 0 和 j = 0 。 
abs(0 - 0) &gt;= 0 且 abs(nums[0] - nums[0]) &gt;= 0 。 
因此，[0,0] 是一个符合题目要求的答案。 
[0,1]、[1,0] 和 [1,1] 也是符合题目要求的答案。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], indexDifference = 2, valueDifference = 4
<strong>输出：</strong>[-1,-1]
<strong>解释：</strong>在示例中，可以证明无法找出 2 个满足所有条件的下标。
因此，返回 [-1,-1] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= indexDifference &lt;= 100</code></li>
	<li><code>0 &lt;= valueDifference &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 维护最大最小值

我们用两个指针 $i$ 和 $j$ 来维护一个间隔为 $indexDifference$ 的滑动窗口，其中指针 $j$ 和 $i$ 分别指向窗口的左右边界。初始时 $i$ 指向 $indexDifference$，而 $j$ 指向 $0$。

我们用 $mi$ 和 $mx$ 来维护指针 $j$ 左侧区间的最小值下标和最大值下标。

当指针 $i$ 向右移动时，我们需要更新 $mi$ 和 $mx$。如果 $nums[j] < nums[mi]$，则 $mi$ 更新为 $j$；如果 $nums[j] > nums[mx]$，则 $mx$ 更新为 $j$。更新完 $mi$ 和 $mx$ 后，我们就可以判断是否找到了满足条件的下标对。如果 $nums[i] - nums[mi] \geq valueDifference$，则找到了满足条件的下标对 $[mi, i]$；如果 $nums[mx] - nums[i] \geq valueDifference$，则找到了满足条件的下标对 $[mx, i]$。

如果指针 $i$ 移动到了数组的末尾，说明没有找到满足条件的下标对，返回 $[-1, -1]$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findIndices(
        self, nums: List[int], indexDifference: int, valueDifference: int
    ) -> List[int]:
        mi = mx = 0
        for i in range(indexDifference, len(nums)):
            j = i - indexDifference
            if nums[j] < nums[mi]:
                mi = j
            if nums[j] > nums[mx]:
                mx = j
            if nums[i] - nums[mi] >= valueDifference:
                return [mi, i]
            if nums[mx] - nums[i] >= valueDifference:
                return [mx, i]
        return [-1, -1]
```

#### Java

```java
class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int mi = 0;
        int mx = 0;
        for (int i = indexDifference; i < nums.length; ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return new int[] {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return new int[] {mx, i};
            }
        }
        return new int[] {-1, -1};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mi = 0, mx = 0;
        for (int i = indexDifference; i < nums.size(); ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return {mx, i};
            }
        }
        return {-1, -1};
    }
};
```

#### Go

```go
func findIndices(nums []int, indexDifference int, valueDifference int) []int {
	mi, mx := 0, 0
	for i := indexDifference; i < len(nums); i++ {
		j := i - indexDifference
		if nums[j] < nums[mi] {
			mi = j
		}
		if nums[j] > nums[mx] {
			mx = j
		}
		if nums[i]-nums[mi] >= valueDifference {
			return []int{mi, i}
		}
		if nums[mx]-nums[i] >= valueDifference {
			return []int{mx, i}
		}
	}
	return []int{-1, -1}
}
```

#### TypeScript

```ts
function findIndices(nums: number[], indexDifference: number, valueDifference: number): number[] {
    let [mi, mx] = [0, 0];
    for (let i = indexDifference; i < nums.length; ++i) {
        const j = i - indexDifference;
        if (nums[j] < nums[mi]) {
            mi = j;
        }
        if (nums[j] > nums[mx]) {
            mx = j;
        }
        if (nums[i] - nums[mi] >= valueDifference) {
            return [mi, i];
        }
        if (nums[mx] - nums[i] >= valueDifference) {
            return [mx, i];
        }
    }
    return [-1, -1];
}
```

#### Rust

```rust
impl Solution {
    pub fn find_indices(nums: Vec<i32>, index_difference: i32, value_difference: i32) -> Vec<i32> {
        let index_difference = index_difference as usize;
        let mut mi = 0;
        let mut mx = 0;

        for i in index_difference..nums.len() {
            let j = i - index_difference;

            if nums[j] < nums[mi] {
                mi = j;
            }

            if nums[j] > nums[mx] {
                mx = j;
            }

            if nums[i] - nums[mi] >= value_difference {
                return vec![mi as i32, i as i32];
            }

            if nums[mx] - nums[i] >= value_difference {
                return vec![mx as i32, i as i32];
            }
        }

        vec![-1, -1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2904. 最短且字典序最小的美丽子字符串](https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string){#2904}

{{< tabs "2904" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        i = j = cnt = 0
        n = len(s)
        ans = ""
        while j < n:
            cnt += s[j] == "1"
            while cnt > k or (i < j and s[i] == "0"):
                cnt -= s[i] == "1"
                i += 1
            j += 1
            if cnt == k and (
                not ans or j - i < len(ans) or (j - i == len(ans) and s[i:j] < ans)
            ):
                ans = s[i:j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int i = 0, j = 0, cnt = 0;
        int n = s.length();
        String ans = "";
        while (j < n) {
            cnt += s.charAt(j) - '0';
            while (cnt > k || (i < j && s.charAt(i) == '0')) {
                cnt -= s.charAt(i) - '0';
                ++i;
            }
            ++j;
            String t = s.substring(i, j);
            if (cnt == k
                && ("".equals(ans) || j - i < ans.length()
                    || (j - i == ans.length() && t.compareTo(ans) < 0))) {
                ans = t;
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
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0, cnt = 0;
        int n = s.size();
        string ans = "";
        while (j < n) {
            cnt += s[j] == '1';
            while (cnt > k || (i < j && s[i] == '0')) {
                cnt -= s[i++] == '1';
            }
            ++j;
            string t = s.substr(i, j - i);
            if (cnt == k && (ans == "" || j - i < ans.size() || (j - i == ans.size() && t < ans))) {
                ans = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestBeautifulSubstring(s string, k int) (ans string) {
	i, j, cnt := 0, 0, 0
	n := len(s)
	for j < n {
		cnt += int(s[j] - '0')
		for cnt > k || (i < j && s[i] == '0') {
			cnt -= int(s[i] - '0')
			i++
		}
		j++
		t := s[i:j]
		if cnt == k && (ans == "" || j-i < len(ans) || (j-i == len(ans) && t < ans)) {
			ans = t
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestBeautifulSubstring(s: string, k: number): string {
    let [i, j, cnt] = [0, 0, 0];
    const n = s.length;
    let ans: string = '';
    while (j < n) {
        cnt += s[j] === '1' ? 1 : 0;
        while (cnt > k || (i < j && s[i] === '0')) {
            cnt -= s[i++] === '1' ? 1 : 0;
        }
        ++j;
        const t = s.slice(i, j);
        if (cnt === k && (ans === '' || j - i < ans.length || (j - i === ans.length && t < ans))) {
            ans = t;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        let s_chars: Vec<char> = s.chars().collect();
        let mut i = 0;
        let mut j = 0;
        let mut cnt = 0;
        let mut ans = String::new();
        let n = s.len();

        while j < n {
            if s_chars[j] == '1' {
                cnt += 1;
            }

            while cnt > k || (i < j && s_chars[i] == '0') {
                if s_chars[i] == '1' {
                    cnt -= 1;
                }
                i += 1;
            }

            j += 1;

            if cnt == k
                && (ans.is_empty() || j - i < ans.len() || (j - i == ans.len() && &s[i..j] < &ans))
            {
                ans = s_chars[i..j].iter().collect();
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

<p>给你一个二进制字符串 <code>s</code> 和一个正整数 <code>k</code> 。</p>

<p>如果 <code>s</code> 的某个子字符串中 <code>1</code> 的个数恰好等于 <code>k</code> ，则称这个子字符串是一个 <strong>美丽子字符串</strong> 。</p>

<p>令 <code>len</code> 等于 <strong>最短</strong> 美丽子字符串的长度。</p>

<p>返回长度等于 <code>len</code> 且字典序 <strong>最小</strong> 的美丽子字符串。如果 <code>s</code> 中不含美丽子字符串，则返回一个 <strong>空</strong> 字符串。</p>

<p>对于相同长度的两个字符串 <code>a</code> 和 <code>b</code> ，如果在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置上，<code>a</code> 中该位置上的字符严格大于 <code>b</code> 中的对应字符，则认为字符串 <code>a</code> 字典序 <strong>大于</strong> 字符串 <code>b</code> 。</p>

<ul>
	<li>例如，<code>"abcd"</code> 的字典序大于 <code>"abcc"</code> ，因为两个字符串出现不同的第一个位置对应第四个字符，而 <code>d</code> 大于 <code>c</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "100011001", k = 3
<strong>输出：</strong>"11001"
<strong>解释：</strong>示例中共有 7 个美丽子字符串：
1. 子字符串 "<u>100011</u>001" 。
2. 子字符串 "<u>1000110</u>01" 。
3. 子字符串 "<u>10001100</u>1" 。
4. 子字符串 "1<u>00011001</u>" 。
5. 子字符串 "10<u>0011001</u>" 。
6. 子字符串 "100<u>011001</u>" 。
7. 子字符串 "1000<u>11001</u>" 。
最短美丽子字符串的长度是 5 。
长度为 5 且字典序最小的美丽子字符串是子字符串 "11001" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "1011", k = 2
<strong>输出：</strong>"11"
<strong>解释：</strong>示例中共有 3 个美丽子字符串：
1. 子字符串 "<u>101</u>1" 。
2. 子字符串 "1<u>011</u>" 。
3. 子字符串 "10<u>11</u>" 。
最短美丽子字符串的长度是 2 。
长度为 2 且字典序最小的美丽子字符串是子字符串 "11" 。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "000", k = 1
<strong>输出：</strong>""
<strong>解释：</strong>示例中不存在美丽子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举所有子字符串 $s[i: j]$，其中 $i \lt j$，并检查它们是否是美丽子字符串。如果是，我们就更新答案。

时间复杂度 $O(n^3)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        ans = ""
        for i in range(n):
            for j in range(i + k, n + 1):
                t = s[i:j]
                if t.count("1") == k and (
                    not ans or j - i < len(ans) or (j - i == len(ans) and t < ans)
                ):
                    ans = t
        return ans
```

#### Java

```java
class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int n = s.length();
        String ans = "";
        for (int i = 0; i < n; ++i) {
            for (int j = i + k; j <= n; ++j) {
                String t = s.substring(i, j);
                int cnt = 0;
                for (char c : t.toCharArray()) {
                    cnt += c - '0';
                }
                if (cnt == k
                    && ("".equals(ans) || j - i < ans.length()
                        || (j - i == ans.length() && t.compareTo(ans) < 0))) {
                    ans = t;
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
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; ++i) {
            for (int j = i + k; j <= n; ++j) {
                string t = s.substr(i, j - i);
                int cnt = count(t.begin(), t.end(), '1');
                if (cnt == k && (ans == "" || j - i < ans.size() || (j - i == ans.size() && t < ans))) {
                    ans = t;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shortestBeautifulSubstring(s string, k int) (ans string) {
	n := len(s)
	for i := 0; i < n; i++ {
		for j := i + k; j <= n; j++ {
			t := s[i:j]
			cnt := 0
			for _, c := range t {
				if c == '1' {
					cnt++
				}
			}
			if cnt == k && (ans == "" || j-i < len(ans) || (j-i == len(ans) && t < ans)) {
				ans = t
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function shortestBeautifulSubstring(s: string, k: number): string {
    const n = s.length;
    let ans: string = '';
    for (let i = 0; i < n; ++i) {
        for (let j = i + k; j <= n; ++j) {
            const t = s.slice(i, j);
            const cnt = t.split('').filter(c => c === '1').length;
            if (
                cnt === k &&
                (ans === '' || j - i < ans.length || (j - i === ans.length && t < ans))
            ) {
                ans = t;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        let n = s.len();
        let mut ans = String::new();

        for i in 0..n {
            for j in i + (k as usize)..=n {
                let t = &s[i..j];
                if (t.matches('1').count() as i32) == k
                    && (ans.is_empty() || j - i < ans.len() || (j - i == ans.len() && t < &ans))
                {
                    ans = t.to_string();
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

### 方法二：双指针

我们也可以用两个指针维护一个滑动窗口，其中指针 $i$ 指向滑动窗口的左端点，指针 $j$ 指向滑动窗口的右端点。初始时 $i = j = 0$。另外，我们用变量 $cnt$ 记录滑动窗口中的 $1$ 的个数。

我们首先将指针 $j$ 向右移动，将 $s[j]$ 加入到滑动窗口中，并更新 $cnt$。如果 $cnt \gt k$，或者 $i \lt j$ 并且 $s[i]=0$，我们就循环将指针 $i$ 往右移动，并且更新 $cnt$。

当 $cnt = k$ 时，我们就找到了一个美丽子字符串。我们将它与当前的答案进行比较，并更新答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        i = j = cnt = 0
        n = len(s)
        ans = ""
        while j < n:
            cnt += s[j] == "1"
            while cnt > k or (i < j and s[i] == "0"):
                cnt -= s[i] == "1"
                i += 1
            j += 1
            if cnt == k and (
                not ans or j - i < len(ans) or (j - i == len(ans) and s[i:j] < ans)
            ):
                ans = s[i:j]
        return ans
```

#### Java

```java
class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int i = 0, j = 0, cnt = 0;
        int n = s.length();
        String ans = "";
        while (j < n) {
            cnt += s.charAt(j) - '0';
            while (cnt > k || (i < j && s.charAt(i) == '0')) {
                cnt -= s.charAt(i) - '0';
                ++i;
            }
            ++j;
            String t = s.substring(i, j);
            if (cnt == k
                && ("".equals(ans) || j - i < ans.length()
                    || (j - i == ans.length() && t.compareTo(ans) < 0))) {
                ans = t;
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
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0, cnt = 0;
        int n = s.size();
        string ans = "";
        while (j < n) {
            cnt += s[j] == '1';
            while (cnt > k || (i < j && s[i] == '0')) {
                cnt -= s[i++] == '1';
            }
            ++j;
            string t = s.substr(i, j - i);
            if (cnt == k && (ans == "" || j - i < ans.size() || (j - i == ans.size() && t < ans))) {
                ans = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shortestBeautifulSubstring(s string, k int) (ans string) {
	i, j, cnt := 0, 0, 0
	n := len(s)
	for j < n {
		cnt += int(s[j] - '0')
		for cnt > k || (i < j && s[i] == '0') {
			cnt -= int(s[i] - '0')
			i++
		}
		j++
		t := s[i:j]
		if cnt == k && (ans == "" || j-i < len(ans) || (j-i == len(ans) && t < ans)) {
			ans = t
		}
	}
	return
}
```

#### TypeScript

```ts
function shortestBeautifulSubstring(s: string, k: number): string {
    let [i, j, cnt] = [0, 0, 0];
    const n = s.length;
    let ans: string = '';
    while (j < n) {
        cnt += s[j] === '1' ? 1 : 0;
        while (cnt > k || (i < j && s[i] === '0')) {
            cnt -= s[i++] === '1' ? 1 : 0;
        }
        ++j;
        const t = s.slice(i, j);
        if (cnt === k && (ans === '' || j - i < ans.length || (j - i === ans.length && t < ans))) {
            ans = t;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        let s_chars: Vec<char> = s.chars().collect();
        let mut i = 0;
        let mut j = 0;
        let mut cnt = 0;
        let mut ans = String::new();
        let n = s.len();

        while j < n {
            if s_chars[j] == '1' {
                cnt += 1;
            }

            while cnt > k || (i < j && s_chars[i] == '0') {
                if s_chars[i] == '1' {
                    cnt -= 1;
                }
                i += 1;
            }

            j += 1;

            if cnt == k
                && (ans.is_empty() || j - i < ans.len() || (j - i == ans.len() && &s[i..j] < &ans))
            {
                ans = s_chars[i..j].iter().collect();
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

# [2905. 找出满足差值条件的下标 II](https://leetcode.cn/problems/find-indices-with-index-and-value-difference-ii){#2905}

{{< tabs "2905" >}}

{{% tab "python" %}}
```python
class Solution:
    def findIndices(
        self, nums: List[int], indexDifference: int, valueDifference: int
    ) -> List[int]:
        mi = mx = 0
        for i in range(indexDifference, len(nums)):
            j = i - indexDifference
            if nums[j] < nums[mi]:
                mi = j
            if nums[j] > nums[mx]:
                mx = j
            if nums[i] - nums[mi] >= valueDifference:
                return [mi, i]
            if nums[mx] - nums[i] >= valueDifference:
                return [mx, i]
        return [-1, -1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int mi = 0;
        int mx = 0;
        for (int i = indexDifference; i < nums.length; ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return new int[] {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return new int[] {mx, i};
            }
        }
        return new int[] {-1, -1};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mi = 0, mx = 0;
        for (int i = indexDifference; i < nums.size(); ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return {mx, i};
            }
        }
        return {-1, -1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findIndices(nums []int, indexDifference int, valueDifference int) []int {
	mi, mx := 0, 0
	for i := indexDifference; i < len(nums); i++ {
		j := i - indexDifference
		if nums[j] < nums[mi] {
			mi = j
		}
		if nums[j] > nums[mx] {
			mx = j
		}
		if nums[i]-nums[mi] >= valueDifference {
			return []int{mi, i}
		}
		if nums[mx]-nums[i] >= valueDifference {
			return []int{mx, i}
		}
	}
	return []int{-1, -1}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findIndices(nums: number[], indexDifference: number, valueDifference: number): number[] {
    let [mi, mx] = [0, 0];
    for (let i = indexDifference; i < nums.length; ++i) {
        const j = i - indexDifference;
        if (nums[j] < nums[mi]) {
            mi = j;
        }
        if (nums[j] > nums[mx]) {
            mx = j;
        }
        if (nums[i] - nums[mi] >= valueDifference) {
            return [mi, i];
        }
        if (nums[mx] - nums[i] >= valueDifference) {
            return [mx, i];
        }
    }
    return [-1, -1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_indices(nums: Vec<i32>, index_difference: i32, value_difference: i32) -> Vec<i32> {
        let index_difference = index_difference as usize;
        let mut mi = 0;
        let mut mx = 0;

        for i in index_difference..nums.len() {
            let j = i - index_difference;

            if nums[j] < nums[mi] {
                mi = j;
            }

            if nums[j] > nums[mx] {
                mx = j;
            }

            if nums[i] - nums[mi] >= value_difference {
                return vec![mi as i32, i as i32];
            }

            if nums[mx] - nums[i] >= value_difference {
                return vec![mx as i32, i as i32];
            }
        }

        vec![-1, -1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> ，以及整数 <code>indexDifference</code> 和整数 <code>valueDifference</code> 。</p>

<p>你的任务是从范围 <code>[0, n - 1]</code> 内找出&nbsp; <strong>2</strong> 个满足下述所有条件的下标 <code>i</code> 和 <code>j</code> ：</p>

<ul>
	<li><code>abs(i - j) &gt;= indexDifference</code> 且</li>
	<li><code>abs(nums[i] - nums[j]) &gt;= valueDifference</code></li>
</ul>

<p>返回整数数组 <code>answer</code>。如果存在满足题目要求的两个下标，则 <code>answer = [i, j]</code> ；否则，<code>answer = [-1, -1]</code> 。如果存在多组可供选择的下标对，只需要返回其中任意一组即可。</p>

<p><strong>注意：</strong><code>i</code> 和 <code>j</code> 可能 <strong>相等</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
<strong>输出：</strong>[0,3]
<strong>解释：</strong>在示例中，可以选择 i = 0 和 j = 3 。
abs(0 - 3) &gt;= 2 且 abs(nums[0] - nums[3]) &gt;= 4 。
因此，[0,3] 是一个符合题目要求的答案。
[3,0] 也是符合题目要求的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1], indexDifference = 0, valueDifference = 0
<strong>输出：</strong>[0,0]
<strong>解释：</strong>
在示例中，可以选择 i = 0 和 j = 0 。 
abs(0 - 0) &gt;= 0 且 abs(nums[0] - nums[0]) &gt;= 0 。 
因此，[0,0] 是一个符合题目要求的答案。 
[0,1]、[1,0] 和 [1,1] 也是符合题目要求的答案。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], indexDifference = 2, valueDifference = 4
<strong>输出：</strong>[-1,-1]
<strong>解释：</strong>在示例中，可以证明无法找出 2 个满足所有条件的下标。
因此，返回 [-1,-1] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= indexDifference &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= valueDifference &lt;= 10<sup>9</sup></code></li>
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
    def findIndices(
        self, nums: List[int], indexDifference: int, valueDifference: int
    ) -> List[int]:
        mi = mx = 0
        for i in range(indexDifference, len(nums)):
            j = i - indexDifference
            if nums[j] < nums[mi]:
                mi = j
            if nums[j] > nums[mx]:
                mx = j
            if nums[i] - nums[mi] >= valueDifference:
                return [mi, i]
            if nums[mx] - nums[i] >= valueDifference:
                return [mx, i]
        return [-1, -1]
```

#### Java

```java
class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int mi = 0;
        int mx = 0;
        for (int i = indexDifference; i < nums.length; ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return new int[] {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return new int[] {mx, i};
            }
        }
        return new int[] {-1, -1};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mi = 0, mx = 0;
        for (int i = indexDifference; i < nums.size(); ++i) {
            int j = i - indexDifference;
            if (nums[j] < nums[mi]) {
                mi = j;
            }
            if (nums[j] > nums[mx]) {
                mx = j;
            }
            if (nums[i] - nums[mi] >= valueDifference) {
                return {mi, i};
            }
            if (nums[mx] - nums[i] >= valueDifference) {
                return {mx, i};
            }
        }
        return {-1, -1};
    }
};
```

#### Go

```go
func findIndices(nums []int, indexDifference int, valueDifference int) []int {
	mi, mx := 0, 0
	for i := indexDifference; i < len(nums); i++ {
		j := i - indexDifference
		if nums[j] < nums[mi] {
			mi = j
		}
		if nums[j] > nums[mx] {
			mx = j
		}
		if nums[i]-nums[mi] >= valueDifference {
			return []int{mi, i}
		}
		if nums[mx]-nums[i] >= valueDifference {
			return []int{mx, i}
		}
	}
	return []int{-1, -1}
}
```

#### TypeScript

```ts
function findIndices(nums: number[], indexDifference: number, valueDifference: number): number[] {
    let [mi, mx] = [0, 0];
    for (let i = indexDifference; i < nums.length; ++i) {
        const j = i - indexDifference;
        if (nums[j] < nums[mi]) {
            mi = j;
        }
        if (nums[j] > nums[mx]) {
            mx = j;
        }
        if (nums[i] - nums[mi] >= valueDifference) {
            return [mi, i];
        }
        if (nums[mx] - nums[i] >= valueDifference) {
            return [mx, i];
        }
    }
    return [-1, -1];
}
```

#### Rust

```rust
impl Solution {
    pub fn find_indices(nums: Vec<i32>, index_difference: i32, value_difference: i32) -> Vec<i32> {
        let index_difference = index_difference as usize;
        let mut mi = 0;
        let mut mx = 0;

        for i in index_difference..nums.len() {
            let j = i - index_difference;

            if nums[j] < nums[mi] {
                mi = j;
            }

            if nums[j] > nums[mx] {
                mx = j;
            }

            if nums[i] - nums[mi] >= value_difference {
                return vec![mi as i32, i as i32];
            }

            if nums[mx] - nums[i] >= value_difference {
                return vec![mx as i32, i as i32];
            }
        }

        vec![-1, -1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2906. 构造乘积矩阵](https://leetcode.cn/problems/construct-product-matrix){#2906}

{{< tabs "2906" >}}

{{% tab "python" %}}
```python
class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        p = [[0] * m for _ in range(n)]
        mod = 12345
        suf = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                p[i][j] = suf
                suf = suf * grid[i][j] % mod
        pre = 1
        for i in range(n):
            for j in range(m):
                p[i][j] = p[i][j] * pre % mod
                pre = pre * grid[i][j] % mod
        return p
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        final int mod = 12345;
        int n = grid.length, m = grid[0].length;
        int[][] p = new int[n][m];
        long suf = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = (int) suf;
                suf = suf * grid[i][j] % mod;
            }
        }
        long pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = (int) (p[i][j] * pre % mod);
                pre = pre * grid[i][j] % mod;
            }
        }
        return p;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        long long suf = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = suf;
                suf = suf * grid[i][j] % mod;
            }
        }
        long long pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = p[i][j] * pre % mod;
                pre = pre * grid[i][j] % mod;
            }
        }
        return p;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func constructProductMatrix(grid [][]int) [][]int {
	const mod int = 12345
	n, m := len(grid), len(grid[0])
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, m)
	}
	suf := 1
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			p[i][j] = suf
			suf = suf * grid[i][j] % mod
		}
	}
	pre := 1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			p[i][j] = p[i][j] * pre % mod
			pre = pre * grid[i][j] % mod
		}
	}
	return p
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function constructProductMatrix(grid: number[][]): number[][] {
    const mod = 12345;
    const [n, m] = [grid.length, grid[0].length];
    const p: number[][] = Array.from({ length: n }, () => Array.from({ length: m }, () => 0));
    let suf = 1;
    for (let i = n - 1; ~i; --i) {
        for (let j = m - 1; ~j; --j) {
            p[i][j] = suf;
            suf = (suf * grid[i][j]) % mod;
        }
    }
    let pre = 1;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            p[i][j] = (p[i][j] * pre) % mod;
            pre = (pre * grid[i][j]) % mod;
        }
    }
    return p;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn construct_product_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let modulo: i32 = 12345;
        let n = grid.len();
        let m = grid[0].len();
        let mut p: Vec<Vec<i32>> = vec![vec![0; m]; n];
        let mut suf = 1;

        for i in (0..n).rev() {
            for j in (0..m).rev() {
                p[i][j] = suf;
                suf = (((suf as i64) * (grid[i][j] as i64)) % (modulo as i64)) as i32;
            }
        }

        let mut pre = 1;

        for i in 0..n {
            for j in 0..m {
                p[i][j] = (((p[i][j] as i64) * (pre as i64)) % (modulo as i64)) as i32;
                pre = (((pre as i64) * (grid[i][j] as i64)) % (modulo as i64)) as i32;
            }
        }

        p
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n * m</code> 的二维整数矩阵 <code><font face="monospace">grid</font></code><font face="monospace"> ，定义一个下标从 <strong>0</strong> 开始、大小为 <code>n * m</code> 的的二维矩阵</font> <code>p</code>。如果满足以下条件，则称 <code>p</code> 为 <code>grid</code> 的 <strong>乘积矩阵</strong> ：</p>

<ul>
	<li>对于每个元素 <code>p[i][j]</code> ，它的值等于除了 <code>grid[i][j]</code> 外所有元素的乘积。乘积对 <code>12345</code> 取余数。</li>
</ul>

<p>返回 <code>grid</code> 的乘积矩阵。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,2],[3,4]]
<strong>输出：</strong>[[24,12],[8,6]]
<strong>解释：</strong>p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
所以答案是 [[24,12],[8,6]] 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[12345],[2],[1]]
<strong>输出：</strong>[[2],[0],[0]]
<strong>解释：</strong>p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0 ，所以 p[0][1] = 0
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0 ，所以 p[0][2] = 0
所以答案是 [[2],[0],[0]] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == grid.length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m == grid[i].length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= n * m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前后缀分解

我们可以预处理出每个元素的后缀乘积（不包含自身），然后再遍历矩阵，计算得到每个元素的前缀乘积（不包含自身），将两者相乘即可得到每个位置的结果。

具体地，我们用 $p[i][j]$ 表示矩阵中第 $i$ 行第 $j$ 列元素的结果，定义一个变量 $suf$ 表示当前位置右下方的所有元素的乘积，初始时 $suf = 1$。我们从矩阵右下角开始遍历，对于每个位置 $(i, j)$，我们将 $suf$ 赋值给 $p[i][j]$，然后更新 $suf$ 为 $suf \times grid[i][j] \bmod 12345$，这样就可以得到每个位置的后缀乘积。

接下来我们从矩阵左上角开始遍历，对于每个位置 $(i, j)$，我们将 $p[i][j]$ 乘上 $pre$，再对 $12345$ 取模，然后更新 $pre$ 为 $pre \times grid[i][j] \bmod 12345$，这样就可以得到每个位置的前缀乘积。

遍历结束，返回结果矩阵 $p$ 即可。

时间复杂度 $O(n \times m)$，其中 $n$ 和 $m$ 分别是矩阵的行数和列数。忽略结果矩阵的空间占用，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        p = [[0] * m for _ in range(n)]
        mod = 12345
        suf = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                p[i][j] = suf
                suf = suf * grid[i][j] % mod
        pre = 1
        for i in range(n):
            for j in range(m):
                p[i][j] = p[i][j] * pre % mod
                pre = pre * grid[i][j] % mod
        return p
```

#### Java

```java
class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        final int mod = 12345;
        int n = grid.length, m = grid[0].length;
        int[][] p = new int[n][m];
        long suf = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = (int) suf;
                suf = suf * grid[i][j] % mod;
            }
        }
        long pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = (int) (p[i][j] * pre % mod);
                pre = pre * grid[i][j] % mod;
            }
        }
        return p;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        long long suf = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = suf;
                suf = suf * grid[i][j] % mod;
            }
        }
        long long pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = p[i][j] * pre % mod;
                pre = pre * grid[i][j] % mod;
            }
        }
        return p;
    }
};
```

#### Go

```go
func constructProductMatrix(grid [][]int) [][]int {
	const mod int = 12345
	n, m := len(grid), len(grid[0])
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, m)
	}
	suf := 1
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			p[i][j] = suf
			suf = suf * grid[i][j] % mod
		}
	}
	pre := 1
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			p[i][j] = p[i][j] * pre % mod
			pre = pre * grid[i][j] % mod
		}
	}
	return p
}
```

#### TypeScript

```ts
function constructProductMatrix(grid: number[][]): number[][] {
    const mod = 12345;
    const [n, m] = [grid.length, grid[0].length];
    const p: number[][] = Array.from({ length: n }, () => Array.from({ length: m }, () => 0));
    let suf = 1;
    for (let i = n - 1; ~i; --i) {
        for (let j = m - 1; ~j; --j) {
            p[i][j] = suf;
            suf = (suf * grid[i][j]) % mod;
        }
    }
    let pre = 1;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            p[i][j] = (p[i][j] * pre) % mod;
            pre = (pre * grid[i][j]) % mod;
        }
    }
    return p;
}
```

#### Rust

```rust
impl Solution {
    pub fn construct_product_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let modulo: i32 = 12345;
        let n = grid.len();
        let m = grid[0].len();
        let mut p: Vec<Vec<i32>> = vec![vec![0; m]; n];
        let mut suf = 1;

        for i in (0..n).rev() {
            for j in (0..m).rev() {
                p[i][j] = suf;
                suf = (((suf as i64) * (grid[i][j] as i64)) % (modulo as i64)) as i32;
            }
        }

        let mut pre = 1;

        for i in 0..n {
            for j in 0..m {
                p[i][j] = (((p[i][j] as i64) * (pre as i64)) % (modulo as i64)) as i32;
                pre = (((pre as i64) * (grid[i][j] as i64)) % (modulo as i64)) as i32;
            }
        }

        p
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2907. 价格递增的最大利润三元组 I 🔒](https://leetcode.cn/problems/maximum-profitable-triplets-with-increasing-prices-i){#2907}

{{< tabs "2907" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        n = len(prices)
        left = [0] * n
        right = [0] * n

        s = sorted(set(prices))
        m = len(s)
        tree1 = BinaryIndexedTree(m + 1)
        tree2 = BinaryIndexedTree(m + 1)

        for i, x in enumerate(prices):
            x = bisect_left(s, x) + 1
            left[i] = tree1.query(x - 1)
            tree1.update(x, profits[i])
        for i in range(n - 1, -1, -1):
            x = m + 1 - (bisect_left(s, prices[i]) + 1)
            right[i] = tree2.query(x - 1)
            tree2.update(x, profits[i])

        return max(
            (l + x + r for l, x, r in zip(left, profits, right) if l and r), default=-1
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] s = prices.clone();
        Arrays.sort(s);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                s[m++] = s[i];
            }
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = search(s, prices[i], m);
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - search(s, prices[i], m);
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = Math.max(ans, left[i] + profits[i] + right[i]);
            }
        }
        return ans;
    }

    private int search(int[] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, 0);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> s = prices;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        int m = s.size();
        BinaryIndexedTree tree1(m + 1);
        BinaryIndexedTree tree2(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(s.begin(), s.end(), prices[i]) - s.begin() + 1;
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - (lower_bound(s.begin(), s.end(), prices[i]) - s.begin() + 1);
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + profits[i] + right[i]);
            }
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

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxProfit(prices []int, profits []int) int {
	n := len(prices)
	left := make([]int, n)
	right := make([]int, n)
	s := make([]int, n)
	copy(s, prices)
	sort.Ints(s)
	m := 0
	for i, x := range s {
		if i == 0 || x != s[i-1] {
			s[m] = x
			m++
		}
	}

	tree1 := NewBinaryIndexedTree(m + 1)
	tree2 := NewBinaryIndexedTree(m + 1)

	for i, x := range prices {
		x = sort.SearchInts(s[:m], x) + 1
		left[i] = tree1.query(x - 1)
		tree1.update(x, profits[i])
	}

	for i := n - 1; i >= 0; i-- {
		x := m + 1 - (sort.SearchInts(s[:m], prices[i]) + 1)
		right[i] = tree2.query(x - 1)
		tree2.update(x, profits[i])
	}

	ans := -1

	for i := 0; i < n; i++ {
		if left[i] > 0 && right[i] > 0 {
			ans = max(ans, left[i]+profits[i]+right[i])
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxProfit(prices: number[], profits: number[]): number {
    const n: number = prices.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);

    const s = [...prices].sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < n; ++i) {
        if (i === 0 || s[i] !== s[i - 1]) {
            s[m++] = s[i];
        }
    }
    s.length = m;

    const tree1: BinaryIndexedTree = new BinaryIndexedTree(m + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(m + 1);

    const search = (nums: number[], x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    for (let i = 0; i < n; ++i) {
        const x = search(s, prices[i]) + 1;
        left[i] = tree1.query(x - 1);
        tree1.update(x, profits[i]);
    }

    for (let i = n - 1; i >= 0; i--) {
        const x: number = m + 1 - (search(s, prices[i]) + 1);
        right[i] = tree2.query(x - 1);
        tree2.update(x, profits[i]);
    }

    let ans: number = -1;

    for (let i = 0; i < n; i++) {
        if (left[i] > 0 && right[i] > 0) {
            ans = Math.max(ans, left[i] + profits[i] + right[i]);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct BinaryIndexedTree {
    n: usize,
    c: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> BinaryIndexedTree {
        BinaryIndexedTree {
            n,
            c: vec![0; n + 1],
        }
    }

    fn update(&mut self, x: usize, v: i32) {
        let mut x = x;
        while x <= self.n {
            self.c[x] = self.c[x].max(v);
            x += x & x.wrapping_neg();
        }
    }

    fn query(&self, x: usize) -> i32 {
        let mut x = x;
        let mut mx = 0;
        while x > 0 {
            mx = mx.max(self.c[x]);
            x -= x & x.wrapping_neg();
        }
        mx
    }
}

impl Solution {
    pub fn max_profit(prices: Vec<i32>, profits: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let m = prices.iter().cloned().max().unwrap_or(0);

        let mut tree1 = BinaryIndexedTree::new((m as usize) + 1);
        let mut tree2 = BinaryIndexedTree::new((m as usize) + 1);

        for i in 0..n {
            let x = prices[i] as usize;
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }

        for i in (0..n).rev() {
            let x = (m + 1 - prices[i]) as usize;
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }

        let mut ans = -1;
        for i in 0..n {
            if left[i] > 0 && right[i] > 0 {
                ans = ans.max(left[i] + profits[i] + right[i]);
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

<p>给定两个长度为 <code>n</code> 的 <b>下标从 0 开始</b>&nbsp;的数组 <code>prices</code> 和 <code>profits</code>。商店里有 <code>n</code> 件商品，其中第 <code>i</code> 件商品的价格为 <code>prices[i]</code>，利润为 <code>profits[i]</code>。</p>

<p>我们必须按照以下条件选择三件商品：</p>

<ul>
	<li><code>prices[i] &lt; prices[j] &lt; prices[k]</code>，其中 <code>i &lt; j &lt; k</code>。</li>
</ul>

<p>如果我们选择满足上述条件的索引 <code>i</code>，<code>j</code> 和 <code>k</code> 的商品，那么利润就是 <code>profits[i] + profits[j] + profits[k]</code>。</p>

<p>返回我们能得到的最大利润，如果无法选择三件满足条件的商品，则返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b> prices = [10,2,3,4], profits = [100,2,7,10]
<b>输出：</b> 19
<b>解释：</b> 我们不能选择索引为 i=0 的商品，因为不存在索引 j 和 k 满足条件。
所以我们能选择的唯一三元组是索引为 1，2 和 3 的商品，这是一个有效的选择，因为 prices[1] &lt; prices[2] &lt; prices[3]。
答案就是它们的利润之和，即 2 + 7 + 10 = 19。</pre>

<p><b>示例 2:</b></p>

<pre>
<b>输入：</b> prices = [1,2,3,4,5], profits = [1,5,3,4,6]
<b>输出：</b> 15
<b>解释：</b> 我们可以选择任意三件商品，因为对于每个索引三元组 i，j 和 k 满足 i &lt; j &lt; k，条件都成立。
因此我们能得到的最大利润就是三件最赚钱的商品，它们的索引分别是 1，3 和 4。
答案就是它们的利润之和，即 5 + 4 + 6 = 15。</pre>

<p><b>示例 3:</b></p>

<pre>
<b>输入：</b> prices = [4,3,2,1], profits = [33,20,19,87]
<b>输出：</b> -1
<b>解释：</b> 我们不能选择任何满足条件的索引三元组，所以我们返回 -1。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>3 &lt;= prices.length == profits.length &lt;= 2000</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= profits[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举中间元素

我们可以枚举中间元素 $profits[j]$，然后再枚举左边元素 $profits[i]$ 和右边元素 $profits[k]$。对于每个 $profits[j]$，我们需要找到最大的 $profits[i]$ 和最大的 $profits[k]$，使得 $prices[i] < prices[j] < prices[k]$。我们记 $left$ 为 $profits[j]$ 左边的最大值，而 $right$ 为 $profits[j]$ 右边的最大值。如果存在，那么我们更新答案为 $ans = \max(ans, left + profits[j] + right)$。

时间复杂度 $O(n^2)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        n = len(prices)
        ans = -1
        for j, x in enumerate(profits):
            left = right = 0
            for i in range(j):
                if prices[i] < prices[j] and left < profits[i]:
                    left = profits[i]
            for k in range(j + 1, n):
                if prices[j] < prices[k] and right < profits[k]:
                    right = profits[k]
            if left and right:
                ans = max(ans, left + x + right)
        return ans
```

#### Java

```java
class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int ans = -1;
        for (int j = 0; j < n; ++j) {
            int left = 0, right = 0;
            for (int i = 0; i < j; ++i) {
                if (prices[i] < prices[j]) {
                    left = Math.max(left, profits[i]);
                }
            }
            for (int k = j + 1; k < n; ++k) {
                if (prices[j] < prices[k]) {
                    right = Math.max(right, profits[k]);
                }
            }
            if (left > 0 && right > 0) {
                ans = Math.max(ans, left + profits[j] + right);
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
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        int ans = -1;
        for (int j = 0; j < n; ++j) {
            int left = 0, right = 0;
            for (int i = 0; i < j; ++i) {
                if (prices[i] < prices[j]) {
                    left = max(left, profits[i]);
                }
            }
            for (int k = j + 1; k < n; ++k) {
                if (prices[j] < prices[k]) {
                    right = max(right, profits[k]);
                }
            }
            if (left && right) {
                ans = max(ans, left + profits[j] + right);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxProfit(prices []int, profits []int) int {
	n := len(prices)
	ans := -1
	for j, x := range profits {
		left, right := 0, 0
		for i := 0; i < j; i++ {
			if prices[i] < prices[j] {
				left = max(left, profits[i])
			}
		}
		for k := j + 1; k < n; k++ {
			if prices[j] < prices[k] {
				right = max(right, profits[k])
			}
		}
		if left > 0 && right > 0 {
			ans = max(ans, left+x+right)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxProfit(prices: number[], profits: number[]): number {
    const n = prices.length;
    let ans = -1;
    for (let j = 0; j < n; ++j) {
        let [left, right] = [0, 0];
        for (let i = 0; i < j; ++i) {
            if (prices[i] < prices[j]) {
                left = Math.max(left, profits[i]);
            }
        }
        for (let k = j + 1; k < n; ++k) {
            if (prices[j] < prices[k]) {
                right = Math.max(right, profits[k]);
            }
        }
        if (left > 0 && right > 0) {
            ans = Math.max(ans, left + profits[j] + right);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_profit(prices: Vec<i32>, profits: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut ans = -1;

        for j in 0..n {
            let mut left = 0;
            let mut right = 0;

            for i in 0..j {
                if prices[i] < prices[j] {
                    left = left.max(profits[i]);
                }
            }

            for k in j + 1..n {
                if prices[j] < prices[k] {
                    right = right.max(profits[k]);
                }
            }

            if left > 0 && right > 0 {
                ans = ans.max(left + profits[j] + right);
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组

我们可以用两个树状数组分别维护每个价格左边以及右边的最大利润，然后枚举中间的价格，通过树状数组查询左右两边的最大利润，最后取最大值即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $prices$ 的长度，而 $M$ 是数组 $prices$ 中的最大值，本题中 $M \le 10^6$。

由于 $prices$ 的长度不超过 $2000$，而 $prices[i]$ 的取值达到 $10^6$，因此，我们可以对 $prices$ 进行离散化处理，这样可以将空间复杂度降低到 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        n = len(prices)
        left = [0] * n
        right = [0] * n

        m = max(prices)
        tree1 = BinaryIndexedTree(m + 1)
        tree2 = BinaryIndexedTree(m + 1)

        for i, x in enumerate(prices):
            left[i] = tree1.query(x - 1)
            tree1.update(x, profits[i])
        for i in range(n - 1, -1, -1):
            x = m + 1 - prices[i]
            right[i] = tree2.query(x - 1)
            tree2.update(x, profits[i])

        return max(
            (l + x + r for l, x, r in zip(left, profits, right) if l and r), default=-1
        )
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int m = 0;
        for (int x : prices) {
            m = Math.max(m, x);
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - prices[i];
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = Math.max(ans, left[i] + profits[i] + right[i]);
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, 0);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int m = *max_element(prices.begin(), prices.end());
        BinaryIndexedTree tree1(m + 1);
        BinaryIndexedTree tree2(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - prices[i];
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + profits[i] + right[i]);
            }
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

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxProfit(prices []int, profits []int) int {
	n := len(prices)
	left := make([]int, n)
	right := make([]int, n)
	m := slices.Max(prices)

	tree1 := NewBinaryIndexedTree(m + 1)
	tree2 := NewBinaryIndexedTree(m + 1)

	for i, x := range prices {
		left[i] = tree1.query(x - 1)
		tree1.update(x, profits[i])
	}

	for i := n - 1; i >= 0; i-- {
		x := m + 1 - prices[i]
		right[i] = tree2.query(x - 1)
		tree2.update(x, profits[i])
	}

	ans := -1

	for i := 0; i < n; i++ {
		if left[i] > 0 && right[i] > 0 {
			ans = max(ans, left[i]+profits[i]+right[i])
		}
	}

	return ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxProfit(prices: number[], profits: number[]): number {
    const n: number = prices.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);
    const m = Math.max(...prices);

    const tree1: BinaryIndexedTree = new BinaryIndexedTree(m + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(m + 1);

    for (let i = 0; i < n; i++) {
        const x: number = prices[i];
        left[i] = tree1.query(x - 1);
        tree1.update(x, profits[i]);
    }

    for (let i = n - 1; i >= 0; i--) {
        const x: number = m + 1 - prices[i];
        right[i] = tree2.query(x - 1);
        tree2.update(x, profits[i]);
    }

    let ans: number = -1;

    for (let i = 0; i < n; i++) {
        if (left[i] > 0 && right[i] > 0) {
            ans = Math.max(ans, left[i] + profits[i] + right[i]);
        }
    }

    return ans;
}
```

#### Rust

```rust
struct BinaryIndexedTree {
    n: usize,
    c: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> BinaryIndexedTree {
        BinaryIndexedTree {
            n,
            c: vec![0; n + 1],
        }
    }

    fn update(&mut self, x: usize, v: i32) {
        let mut x = x;
        while x <= self.n {
            self.c[x] = self.c[x].max(v);
            x += x & x.wrapping_neg();
        }
    }

    fn query(&self, x: usize) -> i32 {
        let mut x = x;
        let mut mx = 0;
        while x > 0 {
            mx = mx.max(self.c[x]);
            x -= x & x.wrapping_neg();
        }
        mx
    }
}

impl Solution {
    pub fn max_profit(prices: Vec<i32>, profits: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let m = prices.iter().cloned().max().unwrap_or(0);

        let mut tree1 = BinaryIndexedTree::new((m as usize) + 1);
        let mut tree2 = BinaryIndexedTree::new((m as usize) + 1);

        for i in 0..n {
            let x = prices[i] as usize;
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }

        for i in (0..n).rev() {
            let x = (m + 1 - prices[i]) as usize;
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }

        let mut ans = -1;
        for i in 0..n {
            if left[i] > 0 && right[i] > 0 {
                ans = ans.max(left[i] + profits[i] + right[i]);
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

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        n = len(prices)
        left = [0] * n
        right = [0] * n

        s = sorted(set(prices))
        m = len(s)
        tree1 = BinaryIndexedTree(m + 1)
        tree2 = BinaryIndexedTree(m + 1)

        for i, x in enumerate(prices):
            x = bisect_left(s, x) + 1
            left[i] = tree1.query(x - 1)
            tree1.update(x, profits[i])
        for i in range(n - 1, -1, -1):
            x = m + 1 - (bisect_left(s, prices[i]) + 1)
            right[i] = tree2.query(x - 1)
            tree2.update(x, profits[i])

        return max(
            (l + x + r for l, x, r in zip(left, profits, right) if l and r), default=-1
        )
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] s = prices.clone();
        Arrays.sort(s);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                s[m++] = s[i];
            }
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = search(s, prices[i], m);
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - search(s, prices[i], m);
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = Math.max(ans, left[i] + profits[i] + right[i]);
            }
        }
        return ans;
    }

    private int search(int[] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, 0);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> s = prices;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        int m = s.size();
        BinaryIndexedTree tree1(m + 1);
        BinaryIndexedTree tree2(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(s.begin(), s.end(), prices[i]) - s.begin() + 1;
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - (lower_bound(s.begin(), s.end(), prices[i]) - s.begin() + 1);
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + profits[i] + right[i]);
            }
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

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxProfit(prices []int, profits []int) int {
	n := len(prices)
	left := make([]int, n)
	right := make([]int, n)
	s := make([]int, n)
	copy(s, prices)
	sort.Ints(s)
	m := 0
	for i, x := range s {
		if i == 0 || x != s[i-1] {
			s[m] = x
			m++
		}
	}

	tree1 := NewBinaryIndexedTree(m + 1)
	tree2 := NewBinaryIndexedTree(m + 1)

	for i, x := range prices {
		x = sort.SearchInts(s[:m], x) + 1
		left[i] = tree1.query(x - 1)
		tree1.update(x, profits[i])
	}

	for i := n - 1; i >= 0; i-- {
		x := m + 1 - (sort.SearchInts(s[:m], prices[i]) + 1)
		right[i] = tree2.query(x - 1)
		tree2.update(x, profits[i])
	}

	ans := -1

	for i := 0; i < n; i++ {
		if left[i] > 0 && right[i] > 0 {
			ans = max(ans, left[i]+profits[i]+right[i])
		}
	}

	return ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxProfit(prices: number[], profits: number[]): number {
    const n: number = prices.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);

    const s = [...prices].sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < n; ++i) {
        if (i === 0 || s[i] !== s[i - 1]) {
            s[m++] = s[i];
        }
    }
    s.length = m;

    const tree1: BinaryIndexedTree = new BinaryIndexedTree(m + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(m + 1);

    const search = (nums: number[], x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    for (let i = 0; i < n; ++i) {
        const x = search(s, prices[i]) + 1;
        left[i] = tree1.query(x - 1);
        tree1.update(x, profits[i]);
    }

    for (let i = n - 1; i >= 0; i--) {
        const x: number = m + 1 - (search(s, prices[i]) + 1);
        right[i] = tree2.query(x - 1);
        tree2.update(x, profits[i]);
    }

    let ans: number = -1;

    for (let i = 0; i < n; i++) {
        if (left[i] > 0 && right[i] > 0) {
            ans = Math.max(ans, left[i] + profits[i] + right[i]);
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

# [2908. 元素和最小的山形三元组 I](https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-i){#2908}

{{< tabs "2908" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        right = [inf] * (n + 1)
        for i in range(n - 1, -1, -1):
            right[i] = min(right[i + 1], nums[i])
        ans = left = inf
        for i, x in enumerate(nums):
            if left < x and right[i + 1] < x:
                ans = min(ans, left + x + right[i + 1])
            left = min(left, x)
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] right = new int[n + 1];
        final int inf = 1 << 30;
        right[n] = inf;
        for (int i = n - 1; i >= 0; --i) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = Math.min(ans, left + nums[i] + right[i + 1]);
            }
            left = Math.min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1 << 30;
        int right[n + 1];
        right[n] = inf;
        for (int i = n - 1; ~i; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = min(ans, left + nums[i] + right[i + 1]);
            }
            left = min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSum(nums []int) int {
	n := len(nums)
	const inf = 1 << 30
	right := make([]int, n+1)
	right[n] = inf
	for i := n - 1; i >= 0; i-- {
		right[i] = min(right[i+1], nums[i])
	}
	ans, left := inf, inf
	for i, x := range nums {
		if left < x && right[i+1] < x {
			ans = min(ans, left+x+right[i+1])
		}
		left = min(left, x)
	}
	if ans == inf {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSum(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n + 1).fill(Infinity);
    for (let i = n - 1; ~i; --i) {
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    let [ans, left] = [Infinity, Infinity];
    for (let i = 0; i < n; ++i) {
        if (left < nums[i] && right[i + 1] < nums[i]) {
            ans = Math.min(ans, left + nums[i] + right[i + 1]);
        }
        left = Math.min(left, nums[i]);
    }
    return ans === Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。</p>

<p>如果下标三元组 <code>(i, j, k)</code> 满足下述全部条件，则认为它是一个 <strong>山形三元组</strong> ：</p>

<ul>
	<li><code>i &lt; j &lt; k</code></li>
	<li><code>nums[i] &lt; nums[j]</code> 且 <code>nums[k] &lt; nums[j]</code></li>
</ul>

<p>请你找出 <code>nums</code> 中 <strong>元素和最小</strong> 的山形三元组，并返回其 <strong>元素和</strong> 。如果不存在满足条件的三元组，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [8,6,1,5,3]
<strong>输出：</strong>9
<strong>解释：</strong>三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为： 
- 2 &lt; 3 &lt; 4
- nums[2] &lt; nums[3] 且 nums[4] &lt; nums[3]
这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,8,7,10,2]
<strong>输出：</strong>13
<strong>解释：</strong>三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为： 
- 1 &lt; 3 &lt; 5 
- nums[1] &lt; nums[3] 且 nums[5] &lt; nums[3]
这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,5,4,3,4,5]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明 nums 中不存在山形三元组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

我们可以预处理出每个位置右侧的最小值，记录在数组 $right[i]$ 中，即 $right[i]$ 表示 $nums[i+1..n-1]$ 中的最小值。

接下来，我们从左到右枚举山形三元组的中间元素 $nums[i]$，用一个变量 $left$ 表示 $nums[0..i-1]$ 中的最小值，用一个变量 $ans$ 表示当前找到的最小元素和。对于每个 $i$，我们需要找到满足 $left < nums[i]$ 且 $right[i+1] < nums[i]$ 的元素 $nums[i]$，并更新 $ans$。

最后，如果 $ans$ 仍然为初始值，则说明不存在山形三元组，返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        right = [inf] * (n + 1)
        for i in range(n - 1, -1, -1):
            right[i] = min(right[i + 1], nums[i])
        ans = left = inf
        for i, x in enumerate(nums):
            if left < x and right[i + 1] < x:
                ans = min(ans, left + x + right[i + 1])
            left = min(left, x)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] right = new int[n + 1];
        final int inf = 1 << 30;
        right[n] = inf;
        for (int i = n - 1; i >= 0; --i) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = Math.min(ans, left + nums[i] + right[i + 1]);
            }
            left = Math.min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1 << 30;
        int right[n + 1];
        right[n] = inf;
        for (int i = n - 1; ~i; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = min(ans, left + nums[i] + right[i + 1]);
            }
            left = min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
};
```

#### Go

```go
func minimumSum(nums []int) int {
	n := len(nums)
	const inf = 1 << 30
	right := make([]int, n+1)
	right[n] = inf
	for i := n - 1; i >= 0; i-- {
		right[i] = min(right[i+1], nums[i])
	}
	ans, left := inf, inf
	for i, x := range nums {
		if left < x && right[i+1] < x {
			ans = min(ans, left+x+right[i+1])
		}
		left = min(left, x)
	}
	if ans == inf {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumSum(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n + 1).fill(Infinity);
    for (let i = n - 1; ~i; --i) {
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    let [ans, left] = [Infinity, Infinity];
    for (let i = 0; i < n; ++i) {
        if (left < nums[i] && right[i + 1] < nums[i]) {
            ans = Math.min(ans, left + nums[i] + right[i + 1]);
        }
        left = Math.min(left, nums[i]);
    }
    return ans === Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2909. 元素和最小的山形三元组 II](https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-ii){#2909}

{{< tabs "2909" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        right = [inf] * (n + 1)
        for i in range(n - 1, -1, -1):
            right[i] = min(right[i + 1], nums[i])
        ans = left = inf
        for i, x in enumerate(nums):
            if left < x and right[i + 1] < x:
                ans = min(ans, left + x + right[i + 1])
            left = min(left, x)
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] right = new int[n + 1];
        final int inf = 1 << 30;
        right[n] = inf;
        for (int i = n - 1; i >= 0; --i) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = Math.min(ans, left + nums[i] + right[i + 1]);
            }
            left = Math.min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1 << 30;
        int right[n + 1];
        right[n] = inf;
        for (int i = n - 1; ~i; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = min(ans, left + nums[i] + right[i + 1]);
            }
            left = min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSum(nums []int) int {
	n := len(nums)
	const inf = 1 << 30
	right := make([]int, n+1)
	right[n] = inf
	for i := n - 1; i >= 0; i-- {
		right[i] = min(right[i+1], nums[i])
	}
	ans, left := inf, inf
	for i, x := range nums {
		if left < x && right[i+1] < x {
			ans = min(ans, left+x+right[i+1])
		}
		left = min(left, x)
	}
	if ans == inf {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSum(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n + 1).fill(Infinity);
    for (let i = n - 1; ~i; --i) {
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    let [ans, left] = [Infinity, Infinity];
    for (let i = 0; i < n; ++i) {
        if (left < nums[i] && right[i + 1] < nums[i]) {
            ans = Math.min(ans, left + nums[i] + right[i + 1]);
        }
        left = Math.min(left, nums[i]);
    }
    return ans === Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。</p>

<p>如果下标三元组 <code>(i, j, k)</code> 满足下述全部条件，则认为它是一个 <strong>山形三元组</strong> ：</p>

<ul>
	<li><code>i &lt; j &lt; k</code></li>
	<li><code>nums[i] &lt; nums[j]</code> 且 <code>nums[k] &lt; nums[j]</code></li>
</ul>

<p>请你找出 <code>nums</code> 中 <strong>元素和最小</strong> 的山形三元组，并返回其 <strong>元素和</strong> 。如果不存在满足条件的三元组，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [8,6,1,5,3]
<strong>输出：</strong>9
<strong>解释：</strong>三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为： 
- 2 &lt; 3 &lt; 4
- nums[2] &lt; nums[3] 且 nums[4] &lt; nums[3]
这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,8,7,10,2]
<strong>输出：</strong>13
<strong>解释：</strong>三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为： 
- 1 &lt; 3 &lt; 5 
- nums[1] &lt; nums[3] 且 nums[5] &lt; nums[3]
这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,5,4,3,4,5]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明 nums 中不存在山形三元组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

我们可以预处理出每个位置右侧的最小值，记录在数组 $right[i]$ 中，即 $right[i]$ 表示 $nums[i+1..n-1]$ 中的最小值。

接下来，我们从左到右枚举山形三元组的中间元素 $nums[i]$，用一个变量 $left$ 表示 $nums[0..i-1]$ 中的最小值，用一个变量 $ans$ 表示当前找到的最小元素和。对于每个 $i$，我们需要找到满足 $left < nums[i]$ 且 $right[i+1] < nums[i]$ 的元素 $nums[i]$，并更新 $ans$。

最后，如果 $ans$ 仍然为初始值，则说明不存在山形三元组，返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        right = [inf] * (n + 1)
        for i in range(n - 1, -1, -1):
            right[i] = min(right[i + 1], nums[i])
        ans = left = inf
        for i, x in enumerate(nums):
            if left < x and right[i + 1] < x:
                ans = min(ans, left + x + right[i + 1])
            left = min(left, x)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] right = new int[n + 1];
        final int inf = 1 << 30;
        right[n] = inf;
        for (int i = n - 1; i >= 0; --i) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = Math.min(ans, left + nums[i] + right[i + 1]);
            }
            left = Math.min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1 << 30;
        int right[n + 1];
        right[n] = inf;
        for (int i = n - 1; ~i; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int ans = inf, left = inf;
        for (int i = 0; i < n; ++i) {
            if (left < nums[i] && right[i + 1] < nums[i]) {
                ans = min(ans, left + nums[i] + right[i + 1]);
            }
            left = min(left, nums[i]);
        }
        return ans == inf ? -1 : ans;
    }
};
```

#### Go

```go
func minimumSum(nums []int) int {
	n := len(nums)
	const inf = 1 << 30
	right := make([]int, n+1)
	right[n] = inf
	for i := n - 1; i >= 0; i-- {
		right[i] = min(right[i+1], nums[i])
	}
	ans, left := inf, inf
	for i, x := range nums {
		if left < x && right[i+1] < x {
			ans = min(ans, left+x+right[i+1])
		}
		left = min(left, x)
	}
	if ans == inf {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumSum(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n + 1).fill(Infinity);
    for (let i = n - 1; ~i; --i) {
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    let [ans, left] = [Infinity, Infinity];
    for (let i = 0; i < n; ++i) {
        if (left < nums[i] && right[i + 1] < nums[i]) {
            ans = Math.min(ans, left + nums[i] + right[i + 1]);
        }
        left = Math.min(left, nums[i]);
    }
    return ans === Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
